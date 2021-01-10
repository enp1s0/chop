# chop-mantissa

A header only library for chopping a mantissa of a given floating point

This library supports these roungings:
- [x] `RN` (IEEE 754, Nearest even)
- [ ] `RN_01` (IEEE 754, Away from zero)
- [ ] `RZ` (IEEE 754, Toward 0)
- [ ] `RU` (IEEE 754, Toward +Inf)
- [ ] `RD` (IEEE 754, Toward -Inf)

## Requirements
- C++ >= 17 (This library uses `if constexpr`)

## Supported device
- CPUs (tested on x86_64)
- GPUs (tested on NVIDIA GPU)

## Sample code
```cpp
// sample.cpp
// g++ -I./path/to/chop/include sample.cpp -std=c++17
#include <chop/chop.hpp>

int main() {
	const float a = 1.f / 3;
	const auto chopped = mtk::chop::chop<mtk::chop::RN>(a, 10);
}
```

## License
Released under the MIT license
