# 8-Bit Adder with Overflow Detection

## Giới Thiệu (Introduction)

A C++ implementation that demonstrates 8-bit unsigned integer addition, binary representation, overflow detection, and wraparound behavior.

## Mục Đích (Purpose)

This project was built to understand binary arithmetic, integer overflow, and basic concepts related to digital computer arithmetic while practicing C++ software design and testing.

## Tính Năng (Features)

✓ Performs 8-bit unsigned integer addition with values from 0 to 255
✓ Automatic overflow detection
✓ Detects and indicates overflow conditions
✓ 5 test cases covering normal, boundary, zero, and overflow scenarios
✓ Interactive mode for custom input testing
✓ Basic input validation for values outside the 0–255 range
✓ Uses formatted terminal output with ANSI colors and Unicode symbols
✓ Clean, well-documented C++ code

## Cách Sử Dụng (How to Use)

### Compile

```bash
g++ -o adder_8bit adder_8bit.cpp
```

### Run


```bash
./adder_8bit
```

Press **N** when asked to skip interactive mode.

## Kết Quả Test (Test Results)

| Test # | Input A | Input B | Expected | Actual | Overflow | Status |
|--------|---------|---------|----------|--------|----------|--------|
| 1 | 100 | 50 | 150 | 150 | NO | ✓ |
| 2 | 200 | 100 | 300 | 44 | YES | ✓ |
| 3 | 255 | 1 | 256 | 0 | YES | ✓ |
| 4 | 0 | 0 | 0 | 0 | NO | ✓ |
| 5 | 200 | 200 | 400 | 144 | YES | ✓ |

**Result:** ✓ All tests passed successfully

## Thông Tin Kỹ Thuật (Technical Details)

**Language:** C++
**File Size:** ~7.5 KB
**Compiler:** g++ (C++11 standard)
**Libraries Used:** 
- iostream (input/output)
- vector — stores the 8-bit binary representation
- iomanip (formatting)
- string — stores ANSI color codes and text values

**Compile Time:** < 1 second
**Runtime:** Negligible for the tested workload
**Memory Usage:** Minimal

## Tôi Học Được Gì (What I Learned)

1. **Binary Arithmetic** - Understanding how addition works at the bit level

2. **Overflow Detection** - How to detect when a result exceeds the maximum representable value and handle wraparound behavior.

3. **Object-Oriented Design** - Using classes to encapsulate logic and separate concerns for better code organization.

4. **Software Testing** - Designing comprehensive test cases that cover normal cases, boundary cases, and edge cases.

5. **Professional Code Quality** - Writing clean, well-commented code with proper error handling and user-friendly output.

6. **Version Control** - Using Git to track changes and maintain a clean development history.

## Chi Tiết Triển Khai (Implementation Details)

- **Class Design:** Created `Adder8Bit` class to encapsulate state (inputA, inputB, result, overflowFlag)
- **Overflow Detection:** Check if (inputA + inputB) > 255 to set overflow flag
- **Wraparound:** Use modulo 256 operator (%) to wrap result back to valid range
- **Input Validation:** Check inputs are in range [0, 255] before computation
- **Output Formatting:** Used ANSI escape codes for colors and Unicode characters for graphics

## Repository GitHub

https://github.com/LeTrungNguyen-07/8bit-adder-overflow-detection.git

---
