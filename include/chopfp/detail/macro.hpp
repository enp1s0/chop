#ifndef __MTK_CHOP_DETAIL_MACRO_HPP__
#define __MTK_CHOP_DETAIL_MACRO_HPP__
#ifdef __CUDA_ARCH__
  #define FUNC_MACRO __device__ __host__
#endif
#ifndef FUNC_MACRO
  #define FUNC_MACRO
#endif
#endif
