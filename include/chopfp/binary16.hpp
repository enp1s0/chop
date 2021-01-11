#ifndef __MTK_CHOP_BINARY16_HPP__
#define __MTK_CHOP_BINARY16_HPP__
#include "detail/utils.hpp"

#ifndef CHOPFP_BINARY16_TYPENAME
#define CHOPFP_BINARY16_TYPENAME half
#endif

namespace mtk {
namespace chopfp {
namespace detail {
template <> struct same_size_uint<CHOPFP_BINARY16_TYPENAME> {using type = uint16_t;};

// This function should not be defined because bfloat16 is also same size with uint16_t.
//template <> struct same_size_fp<uint16_t> {using type = COPTF_BINARY16_TYPENAME;};

template <> FUNC_MACRO inline unsigned get_exponent_size<CHOPFP_BINARY16_TYPENAME>() {return 5;}
template <> FUNC_MACRO inline unsigned get_mantissa_size<CHOPFP_BINARY16_TYPENAME>() {return 10;}
template <> FUNC_MACRO inline unsigned get_bias<CHOPFP_BINARY16_TYPENAME>() {return 0xf;}

template <> FUNC_MACRO inline CHOPFP_BINARY16_TYPENAME reinterpret_as_fp<uint16_t, CHOPFP_BINARY16_TYPENAME>(const uint16_t bs) {
	return detail::reinterpret_medium<CHOPFP_BINARY16_TYPENAME, uint16_t>{.bs = bs}.fp;
}

} // namespace detail
} // namesapce chop
} // namespace mtk
#endif
