#ifndef __MTK_CHOP_HPP__
#define __MTK_CHOP_HPP__
#include <cstdint>
#include "detail/macro.hpp"
#include "detail/utils.hpp"
#include "detail/rn.hpp"
#include "detail/rn_01.hpp"
#include "detail/rz.hpp"
#include "detail/ru.hpp"

namespace mtk {
namespace chopfp {
enum rounding_type {
	RN,
	RN_01,
	RZ,
	RU,
	RD
};

template <rounding_type rounding, class T>
FUNC_MACRO T chop(const T v, const unsigned leaving_length) {
	// Nothing to do
	if (leaving_length >= detail::get_mantissa_size<T>()) {
		return v;
	}
	// If Nan then Nan
	if (v != v) {
		return v;
	}

	T result = static_cast<T>(0);
	if constexpr (rounding == rounding_type::RN) {
		result = detail::chop_rn(v, leaving_length);
	} else if constexpr (rounding == rounding_type::RN_01) {
		result = detail::chop_rn_01(v, leaving_length);
	} else if constexpr (rounding == rounding_type::RZ) {
		result = detail::chop_rz(v, leaving_length);
	} else if constexpr (rounding == rounding_type::RU) {
		result = detail::chop_ru(v, leaving_length);
	} else if constexpr (rounding == rounding_type::RD) {
	}
	return result;
}
} // namesapce chop
} // namespace mtk
#endif
