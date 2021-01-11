#ifndef __MTK_CHOP_BINARY16_HPP__
#define __MTK_CHOP_BINARY16_HPP__
#include "detail/utils.hpp"

#ifndef CHOPTF_BINARY16_TYPENAME
#define CHOPTF_BINARY16_TYPENAME half
#endif

namespace mtk {
namespace chopfp {
namespace detail {
template <> struct same_size_uint<CHOPTF_BINARY16_TYPENAME> {using type = uint16_t;};

// This function should not be defined because bfloat16 is also same size with uint16_t.
//template <> struct same_size_fp<uint16_t> {using type = COPTF_BINARY16_TYPENAME;};

template <> FUNC_MACRO inline unsigned get_exponent_size<CHOPTF_BINARY16_TYPENAME>() {return 5;}
template <> FUNC_MACRO inline unsigned get_mantissa_size<CHOPTF_BINARY16_TYPENAME>() {return 10;}
template <> FUNC_MACRO inline unsigned get_bias<CHOPTF_BINARY16_TYPENAME>() {return 0xf;}

template <> FUNC_MACRO inline typename same_size_fp<uint16_t, CHOPTF_BINARY16_TYPENAME>::type reinterpret_as_fp(const uint16_t bs) {
	return detail::reinterpret_medium<CHOPTF_BINARY16_TYPENAME, uint16_t>{.bs = bs}.fp;
}

} // namespace detail
} // namesapce chop
} // namespace mtk
#endif
