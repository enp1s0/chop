#ifndef __MTK_CHOP_DEBUG_HPP__
#define __MTK_CHOP_DEBUG_HPP__
#include <stdio.h>
#include "detail/macro.hpp"
#include "detail/utils.hpp"
namespace mtk {
namespace chop {
namespace debug {
template <class T>
FUNC_MACRO inline void print_hex(const T v, const bool line_break = true);
template <> FUNC_MACRO inline void print_hex<uint64_t>(const uint64_t v, const bool line_break) {printf("0x%016lx", v);if(line_break)printf("\n");}
template <> FUNC_MACRO inline void print_hex<uint32_t>(const uint32_t v, const bool line_break) {printf("0x%08x", v);if(line_break)printf("\n");}
template <> FUNC_MACRO inline void print_hex<uint16_t>(const uint16_t v, const bool line_break) {printf("0x%04x", v);if(line_break)printf("\n");}
template <> FUNC_MACRO inline void print_hex<uint8_t >(const uint8_t  v, const bool line_break) {printf("0x%02x", v);if(line_break)printf("\n");}
template <> FUNC_MACRO inline void print_hex<double  >(const double   v, const bool line_break) {print_hex(detail::reinterpret_as_uint(v), line_break);}
template <> FUNC_MACRO inline void print_hex<float   >(const float    v, const bool line_break) {print_hex(detail::reinterpret_as_uint(v), line_break);}

template <class T>
FUNC_MACRO inline void print_bin(const T v, const bool line_break = true) {
	for (int i = sizeof(T) * 8 - 1; i >= 0; i--) {
		printf("%d", static_cast<int>(v >> i) & 0x1);
	}
	if (line_break) {
		printf("\n");
	}
}
template <> FUNC_MACRO inline void print_bin<float >(const float  v, const bool line_break) {print_bin(detail::reinterpret_as_uint(v), line_break);}
template <> FUNC_MACRO inline void print_bin<double>(const double v, const bool line_break) {print_bin(detail::reinterpret_as_uint(v), line_break);}

} // namespace debug
} // namesapce chop
} // namespace mtk
#endif
