#include <iostream>
#include <vector>
#include <utility>
#include <chop/chop.hpp>
#include <chop/debug.hpp>

namespace {
std::string get_rounding_name_string(const mtk::chopfp::rounding_type rounding) {
	switch (rounding) {
	case mtk::chopfp::RN:
		return "RN";
	case mtk::chopfp::RN_01:
		return "RN_01";
	case mtk::chopfp::RZ:
		return "RZ";
	case mtk::chopfp::RU:
		return "RU";
	case mtk::chopfp::RD:
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
	using bs_t = typename mtk::chopfp::detail::same_size_uint<T>::type;
	const bs_t input;
	const bs_t output;
	const unsigned leaving_length;

	test_case(const bs_t input, const bs_t output, const unsigned leaving_length):
		input(input), output(output), leaving_length(leaving_length){}
};

template <mtk::chopfp::rounding_type rounding, class T>
unsigned check(const std::vector<test_case<T>>& test_cases) {
	unsigned num_correct = 0;
	for (const auto& test_case : test_cases) {
		const auto chopped = mtk::chopfp::detail::reinterpret_as_uint(mtk::chopfp::chop<rounding>(mtk::chopfp::detail::reinterpret_as_fp(test_case.input), test_case.leaving_length));
		const auto expected = test_case.output;
		const auto result = (expected == chopped);
		if (result) {
			num_correct++;
		} else {
			std::printf("! - FAILED -\n");
			std::printf("INPUT    : ");mtk::chopfp::debug::print_bin(test_case.input);
			std::printf("EXPECTED : ");mtk::chopfp::debug::print_bin(expected);
			std::printf("CHOPPED  : ");mtk::chopfp::debug::print_bin(chopped);
		}
	}
	return num_correct;
}

template <mtk::chopfp::rounding_type rounding, class T>
std::vector<test_case<T>> make_test_cases();

template <>
std::vector<test_case<float>> make_test_cases<mtk::chopfp::RN, float>() {
	std::vector<test_case<float>> test_cases;
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		0
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		100
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'1000000000000u,
		0b0'01111111'0000000010'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'0000000000000u,
		0b0'01111111'0000000001'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000000'1000000000000u,
		0b0'01111111'0000000000'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'1111111111'1000000000000u,
		0b0'10000000'0000000000'0000000000000u,
		10
	});

	return test_cases;
}


template <>
std::vector<test_case<float>> make_test_cases<mtk::chopfp::RN_01, float>() {
	std::vector<test_case<float>> test_cases;
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		0
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'00000000000000000000000u,
		0b0'01111111'00000000000000000000000u,
		100
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'1000000000000u,
		0b0'01111111'0000000010'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000001'0000000000000u,
		0b0'01111111'0000000001'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'0000000000'1000000000000u,
		0b0'01111111'0000000001'0000000000000u,
		10
	});
	test_cases.push_back(test_case<float>{
		0b0'01111111'1111111111'1000000000000u,
		0b0'10000000'0000000000'0000000000000u,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<double>> make_test_cases<mtk::chopfp::RN, double>() {
	std::vector<test_case<double>> test_cases;
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		100
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
	test_cases.push_back(test_case<double>{
		0b0'01111111111'1111111111'100000000000000000000000000000000000000000lu,
		0b0'10000000000'0000000000'000000000000000000000000000000000000000000lu,
		10
	});

	return test_cases;
}

template <>
std::vector<test_case<double>> make_test_cases<mtk::chopfp::RN_01, double>() {
	std::vector<test_case<double>> test_cases;
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		0b0'01111111111'0000000000000000000000000000000000000000000000000000lu,
		100
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
		0b0'01111111111'0000000001'000000000000000000000000000000000000000000lu,
		10
	});
	test_cases.push_back(test_case<double>{
		0b0'01111111111'1111111111'100000000000000000000000000000000000000000lu,
		0b0'10000000000'0000000000'000000000000000000000000000000000000000000lu,
		10
	});

	return test_cases;
}

template <mtk::chopfp::rounding_type rounding, class T>
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
	test<mtk::chopfp::RN   , float >();
	test<mtk::chopfp::RN   , double>();
	test<mtk::chopfp::RN_01, float >();
	test<mtk::chopfp::RN_01, double>();
}
