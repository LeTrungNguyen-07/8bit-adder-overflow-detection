# 8-Bit Adder with Overflow Detection

## Giới Thiệu (Introduction)

A C++ implementation demonstrating how CPUs perform 8-bit arithmetic and handle overflow conditions.

## Mục Đích (Purpose)

I built this project to understand binary arithmetic at the hardware level and practice software design principles.

## Tính Năng (Features)

✓ Performs 8-bit unsigned integer addition with 0-255 range
✓ Automatic overflow detection
✓ Detects and indicates overflow conditions
✓ 5 comprehensive test cases covering all scenarios
✓ Interactive mode for custom input testing
✓ Input validation with error messages
✓ Professional formatted output with colors and graphics
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
- vector (8-bit array)
- iomanip (formatting)
- string (ANSI colors)

**Compile Time:** < 1 second
**Runtime:** Instant
**Memory Usage:** Minimal (~1 KB)

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
