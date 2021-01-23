#include <iostream>
#include <vector>
#include <utility>
#include <chopfp/chopfp.hpp>
#include <chopfp/debug.hpp>
#ifdef TEST_BINARY16
#include <chopfp/binary16.hpp>
#endif

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
	case mtk::chopfp::SR_1:
		return "SR_1";
	default:
		return "Unknown";
	}
}

template <class T> std::string get_type_name_string();
template <> std::string get_type_name_string<float >() {return "binary32";}
template <> std::string get_type_name_string<double>() {return "binary64";}

#ifdef TEST_BINARY16
template <> std::string get_type_name_string<CHOPFP_BINARY16_TYPENAME>() {return "binary16";}
#endif

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
		const auto chopped = mtk::chopfp::detail::reinterpret_as_uint(mtk::chopfp::chop<rounding>(mtk::chopfp::detail::reinterpret_as_fp<typename mtk::chopfp::detail::same_size_uint<T>::type, T>(test_case.input), test_case.leaving_length));
		const auto expected = test_case.output;
		bool result;
		if (rounding == mtk::chopfp::rounding_type::SR_1) {
			result = std::abs(mtk::chopfp::detail::reinterpret_as_fp<T>(chopped)) <= std::abs(mtk::chopfp::detail::reinterpret_as_fp<T>(expected) * (1. + mtk::chopfp::detail::get_machine_epsilon<T>() * (1lu << (mtk::chopfp::detail::get_mantissa_size<T>() - test_case.leaving_length))));
		} else {
			result = (expected == chopped);
		}
		if (result) {
			num_correct++;
		} else {
			std::printf("! - FAILED -\n");
			std::printf("INPUT    : ");mtk::chopfp::debug::print_bin(test_case.input);
			if (rounding == mtk::chopfp::rounding_type::SR_1) {
				std::printf("BOUND    : ");
			} else {
				std::printf("EXPECTED : ");
			}
			mtk::chopfp::debug::print_bin(expected);
			std::printf("CHOPPED  : ");mtk::chopfp::debug::print_bin(chopped);
		}
	}
	return num_correct;
}

template <mtk::chopfp::rounding_type rounding, class T>
std::vector<test_case<T>> make_test_cases();

#ifdef TEST_BINARY16
#include "binary16_testcases.hpp"
#endif
#include "binary32_testcases.hpp"
#include "binary64_testcases.hpp"

template <mtk::chopfp::rounding_type rounding, class T>
void test() {
	std::printf("test for (%9s, %5s)... ", get_type_name_string<T>().c_str(), get_rounding_name_string(rounding).c_str());
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
	test<mtk::chopfp::RN_01, float >();
	test<mtk::chopfp::RZ   , float >();
	test<mtk::chopfp::RU   , float >();
	test<mtk::chopfp::RD   , float >();
	test<mtk::chopfp::SR_1 , float >();

	test<mtk::chopfp::RN   , double>();
	test<mtk::chopfp::RN_01, double>();
	test<mtk::chopfp::RZ   , double>();
	test<mtk::chopfp::RU   , double>();
	test<mtk::chopfp::RD   , double>();
	test<mtk::chopfp::SR_1 , double>();
#ifdef TEST_BINARY16
	test<mtk::chopfp::RN   , CHOPFP_BINARY16_TYPENAME>();
	test<mtk::chopfp::RN_01, CHOPFP_BINARY16_TYPENAME>();
	test<mtk::chopfp::RZ   , CHOPFP_BINARY16_TYPENAME>();
	test<mtk::chopfp::RU   , CHOPFP_BINARY16_TYPENAME>();
	test<mtk::chopfp::RD   , CHOPFP_BINARY16_TYPENAME>();
	test<mtk::chopfp::SR_1 , CHOPFP_BINARY16_TYPENAME>();
#endif
}
