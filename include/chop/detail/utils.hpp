#ifndef __MTK_CHOP_DETAIL_UTILS_HPP__
#define __MTK_CHOP_DETAIL_UTILS_HPP__
#include <cstdint>
#include "macro.hpp"

namespace mtk {
namespace chop {
namespace detail {
template <class FP_T, class BS_T>
union reinterpret_medium {
	FP_T fp;
	BS_T bs;
};

template <class T>
struct same_size_uint {using type = uint32_t;};
template <> struct same_size_uint<float > {using type = uint32_t;};
template <> struct same_size_uint<double> {using type = uint64_t;};

template <class T>
struct same_size_fp {using type = float;};
template <> struct same_size_fp<uint32_t> {using type = float ;};
template <> struct same_size_fp<uint64_t> {using type = double;};

template <class T>
FUNC_MACRO inline unsigned get_exponent_size();
template <> FUNC_MACRO inline unsigned get_exponent_size<float >() {return 8;}
template <> FUNC_MACRO inline unsigned get_exponent_size<double>() {return 11;}

template <class T>
FUNC_MACRO inline unsigned get_mantissa_size();
template <> FUNC_MACRO inline unsigned get_mantissa_size<float >() {return 23;}
template <> FUNC_MACRO inline unsigned get_mantissa_size<double>() {return 52;}

template <class T>
FUNC_MACRO inline unsigned get_bias();
template <> FUNC_MACRO inline unsigned get_bias<float >() {return 0x7f;}
template <> FUNC_MACRO inline unsigned get_bias<double>() {return 0x3ff;}

template <class T>
FUNC_MACRO inline typename same_size_uint<T>::type reinterpret_as_uint(const T fp) {
	return detail::reinterpret_medium<T, typename same_size_uint<T>::type>{.fp = fp}.bs;
}

template <class T>
FUNC_MACRO inline typename same_size_fp<T>::type reinterpret_as_fp(const T bs) {
	return detail::reinterpret_medium<typename same_size_fp<T>::type, T>{.bs = bs}.fp;
}

template <class T>
FUNC_MACRO inline typename same_size_uint<T>::type mask_mantissa(const T fp) {
	const auto uint = reinterpret_as_uint(fp);
	const auto mask = (decltype(uint)(1) << get_mantissa_size<T>()) - 1;
	return uint & mask;
}

template <class T>
FUNC_MACRO inline typename same_size_uint<T>::type mask_exponent(const T fp) {
	const auto uint = reinterpret_as_uint(fp);
	const auto mask = ((decltype(uint)(1) << get_exponent_size<T>()) - 1) << get_mantissa_size<T>();
	return uint & mask;
}

template <class T>
FUNC_MACRO inline typename same_size_uint<T>::type mask_sign(const T fp) {
	const auto uint = reinterpret_as_uint(fp);
	const auto mask = decltype(uint)(1) << (sizeof(decltype(uint)) * 8 - 1);
	return uint & mask;
}
} // namespace detail
} // namesapce chop
} // namespace mtk
#endif
