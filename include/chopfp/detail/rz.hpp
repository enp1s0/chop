#ifndef __MTK_CHOP_DETAIL_RZ_HPP__
#define __MTK_CHOP_DETAIL_RZ_HPP__
#include <cmath>
#include "macro.hpp"
#include "utils.hpp"

namespace mtk {
namespace chopfp {
namespace detail {
template <class T>
FUNC_MACRO T chop_rz(const T v, const unsigned leaving_length) {
	const unsigned shift = detail::get_mantissa_size<T>() - leaving_length;
	const auto bs_mantissa = detail::reinterpret_as_uint(v);
	const auto bs_result = bs_mantissa & ((~decltype(bs_mantissa)(0)) - ((decltype(bs_mantissa)(1) << shift) - 1));
	return detail::reinterpret_as_fp(bs_result);
}
} // namespace detail
} // namesapce chop
} // namespace mtk
#endif
