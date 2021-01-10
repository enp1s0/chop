#ifndef __MTK_CHOP_HPP__
#define __MTK_CHOP_HPP__
#include <cstdint>
#include "detail/macro.hpp"
#include "detail/utils.hpp"

namespace mtk {
namespace chop {
enum rounding_type {
	RN,
	RN_01,
	RZ,
	RU,
	RD
};

template <class T, rounding_type rounding>
FUNC_MACRO T chop(const T v) {
	T result;
	if constexpr (rounding == rounding_type::RN) {
	} else if constexpr (rounding == rounding_type::RN_01) {
	} else if constexpr (rounding == rounding_type::RZ) {
	} else if constexpr (rounding == rounding_type::RU) {
	} else if constexpr (rounding == rounding_type::RD) {
	}
	return result;
}
} // namesapce chop
} // namespace mtk
#endif
