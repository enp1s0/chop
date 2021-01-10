#include <iostream>
#include <vector>
#include <utility>
#include <chop/chop.hpp>
#include <chop/debug.hpp>

namespace {
std::string get_rounding_name_string(const mtk::chop::rounding_type rounding) {
	switch (rounding) {
	case mtk::chop::RN:
		return "RN";
	case mtk::chop::RN_01:
		return "RN_01";
	case mtk::chop::RZ:
		return "RZ";
	case mtk::chop::RU:
		return "RU";
	case mtk::chop::RD:
		return "RD";
	default:
		return "Unknown";
	}
}

template <class T> std::string get_type_name_string();
template <> std::string get_type_name_string<float >() {return "float" ;}
template <> std::string get_type_name_string<double>() {return "double";}

template <class T>
struct test_case {
	using bs_t = typename mtk::chop::detail::same_size_uint<T>::type;
	const bs_t input;
	const bs_t output;
	const unsigned leaving_length;

	test_case(const bs_t input, const bs_t output, const unsigned leaving_length):
		input(input), output(output), leaving_length(leaving_length){}
};

template <mtk::chop::rounding_type rounding, class T>
unsigned check(const std::vector<test_case<T>>& test_cases) {
	unsigned num_correct = 0;
	for (const auto& test_case : test_cases) {
		const auto result = (mtk::chop::detail::reinterpret_as_uint(mtk::chop::chop<rounding>(mtk::chop::detail::reinterpret_as_fp(test_case.input), test_case.leaving_length)) == test_case.output);
		if (result) {
			num_correct++;
		}
	}
	return num_correct;
}

template <mtk::chop::rounding_type rounding, class T>
std::vector<test_case<T>> make_test_cases();

template <>
std::vector<test_case<float>> make_test_cases<mtk::chop::RN, float>() {
	std::vector<test_case<float>> test_cases;
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000,
		0b0'01111111'00000000000000000000000,
		0
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'1000000000000,
		0b0'01111111'0000000010'0000000000000,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'0000000000000,
		0b0'01111111'0000000001'0000000000000,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000000'1000000000000,
		0b0'01111111'0000000000'0000000000000,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<double>> make_test_cases<mtk::chop::RN, double>() {
	std::vector<test_case<double>> test_cases;
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000001'100000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000010'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000'100000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000'000000000000000000000000000000000000000000lu,
		10
	});

	return test_cases;
}

template <mtk::chop::rounding_type rounding, class T>
void test() {
	std::printf("test for (%6s, %5s)... ", get_type_name_string<T>().c_str(), get_rounding_name_string(rounding).c_str());
	const auto test_cases = make_test_cases<rounding, T>();
	const auto num_correct = check<rounding>(test_cases);
	std::printf(" %u / %lu ", num_correct, test_cases.size());
	if (num_correct == test_cases.size()) {
		std::printf("ok.\n");
	} else {
		std::printf("failed.\n");
	}
}
} // namespace

int main() {
	test<mtk::chop::RN, float >();
	test<mtk::chop::RN, double>();
}
