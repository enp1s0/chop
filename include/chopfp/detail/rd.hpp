#ifndef __MTK_CHOP_DETAIL_RD_HPP__
#define __MTK_CHOP_DETAIL_RD_HPP__
#include <cmath>
#include "macro.hpp"
#include "utils.hpp"

#include "../debug.hpp"

namespace mtk {
namespace chopfp {
namespace detail {
template <class T>
FUNC_MACRO T chop_rd(const T v, const unsigned leaving_length) {
	const unsigned shift = detail::get_mantissa_size<T>() - leaving_length;
	const auto bs_mantissa_0 = detail::mask_mantissa(v);
	const auto bs_mantissa = bs_mantissa_0 | (decltype(bs_mantissa_0)(1) << detail::get_mantissa_size<T>());

	// Decide roungind up
	const auto move_up = detail::mask_sign(v) >> (detail::get_exponent_size<T>() + detail::get_mantissa_size<T>());

	// Move up if necessary
	const auto result_bs_mantissa_0 = ((bs_mantissa >> shift) + move_up) << shift;
	const auto correct_mantissa_shift = (result_bs_mantissa_0 >> detail::get_mantissa_size<T>()) >> 1;
	const auto result_bs_mantissa = result_bs_mantissa_0 >> correct_mantissa_shift;

	const auto bs_exponent = detail::mask_exponent(v) >> detail::get_mantissa_size<T>();
	const auto result_bs_exponent = bs_exponent + correct_mantissa_shift;
	if ((result_bs_exponent >> detail::get_exponent_size<T>()) > 0) {
		return static_cast<T>(v * INFINITY);
	}

	const auto bs_result = detail::mask_sign(v)
		| (result_bs_exponent << detail::get_mantissa_size<T>())
		| (result_bs_mantissa & ((decltype(bs_mantissa_0)(1) << detail::get_mantissa_size<T>()) - 1));
	return detail::reinterpret_as_fp(bs_result);
}
} // namespace detail
} // namesapce chop
} // namespace mtk
#endif
