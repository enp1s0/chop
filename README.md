# chopfp

A header-only library for chopping a mantissa of a given floating point

This library supports these roungings:
- [x] `RN` (IEEE 754, Nearest even)
- [x] `RN_01` (IEEE 754, Away from zero)
- [x] `RZ` (IEEE 754, Toward 0)
- [x] `RU` (IEEE 754, Toward +Inf)
- [x] `RD` (IEEE 754, Toward -Inf)

## Requirements
- C++ >= 17 (This library uses `if constexpr`)

## Supported device
- CPUs (tested on x86_64)
- GPUs (tested on NVIDIA GPU)

## Supported floating point format
- `half` (IEEE 754 Binary16, availbale if compiler supports it)
- `float` (IEEE 754 Binary32)
- `double` (IEEE 754 Binary64)

## Sample code
```cpp
// sample.cpp
// g++ -I./path/to/chopfp/include sample.cpp -std=c++17
#include <chopfp/chopfp.hpp>

int main() {
	const float a = 1.f / 3;
	const auto chopped = mtk::chopfp::chop<mtk::chop::RN>(a, 10);
}
```

The function `chop<r>(const T v, const unsigned l)` chops a given floating point number `b` leaving `l` bits of mantissa bitstrings with rounding `r`.

## License
Released under the MIT license
