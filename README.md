# chop-mantissa

A tiny library to chop mantissa of a gven floating point

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

## License
Released under the MIT license
