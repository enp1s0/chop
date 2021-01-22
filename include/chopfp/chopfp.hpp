#ifndef __MTK_CHOP_HPP__
#define __MTK_CHOP_HPP__
#include <cstdint>
#include <random>
#include "detail/macro.hpp"
#include "detail/utils.hpp"
#include "detail/rn.hpp"
#include "detail/rn_01.hpp"
#include "detail/rz.hpp"
#include "detail/ru.hpp"
#include "detail/rd.hpp"
#include "detail/sr_1.hpp"

namespace mtk {
namespace chopfp {
enum rounding_type {
	RN,
	RN_01,
	RZ,
	RU,
	RD,
	SR_1
};

template <rounding_type rounding, class T>
FUNC_MACRO T chop(const T v, const unsigned leaving_length) {
	// Nothing to do
	if (leaving_length >= detail::get_mantissa_size<T>() || leaving_length == 0) {
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
		result = detail::chop_rd(v, leaving_length);
	} else if constexpr (rounding == rounding_type::SR_1) {
		result = detail::chop_sr_1(v, leaving_length, [](const typename mtk::chopfp::detail::same_size_uint<T>::type a) {
					std::mt19937_64 mt(std::random_device{}());
					return static_cast<typename mtk::chopfp::detail::same_size_uint<T>::type>(mt());
				});
	}
	return result;
}

template <rounding_type rounding, class T, class RandFunc>
FUNC_MACRO T chop(const T v, const unsigned leaving_length, RandFunc rand_func) {
	// Nothing to do
	if (leaving_length >= detail::get_mantissa_size<T>() || leaving_length == 0) {
		return v;
	}
	// If Nan then Nan
	if (v != v) {
		return v;
	}

	T result = static_cast<T>(0);
	if constexpr (rounding == rounding_type::SR_1) {
		result = detail::chop_sr_1(v, leaving_length, rand_func);
	}
	return result;
}
} // namesapce chop
} // namespace mtk
#endif
