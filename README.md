# 8-Bit Adder with Overflow Detection

## Introduction

A C++ implementation that demonstrates 8-bit unsigned integer addition, binary representation, overflow detection, and wraparound behavior.

## Purpose

This project was built to understand binary arithmetic, integer overflow, and basic concepts related to digital computer arithmetic while practicing C++ software design and testing.

## Features

✓ Performs 8-bit unsigned integer addition with values from 0 to 255

✓ Automatic overflow detection

✓ Displays the result in both decimal and binary

✓ Indicates when the result exceeds the 8-bit range

✓ 5 test cases covering normal, boundary, zero, and overflow scenarios

✓ Interactive mode for custom input testing

✓ Basic input validation for values outside the 0–255 range

✓ Uses formatted terminal output with ANSI colors and Unicode symbols

✓ Clean, well-documented C++ code

## How to Use

### Compile

```bash
clang++ -std=c++14 -o adder_8bit adder_8bit.cpp
```

### Run


```bash
./adder_8bit
```

The program automatically runs the test suite and binary conversion demonstrations before entering interactive mode.

## Test Results

| Test # | Input A | Input B | Raw Sum | 8-bit Result | Overflow | Status |
|--------|---------|---------|----------|--------|----------|--------|
| 1 | 100 | 50 | 150 | 150 | NO | ✓ |
| 2 | 200 | 100 | 300 | 44 | YES | ✓ |
| 3 | 255 | 1 | 256 | 0 | YES | ✓ |
| 4 | 0 | 0 | 0 | 0 | NO | ✓ |
| 5 | 200 | 200 | 400 | 144 | YES | ✓ |

**Result:** ✓ All tests passed successfully

## Technical Details

**Language:** C++

**Standard:** C++14

**Compiler:** Apple Clang 17.0.0

**Libraries Used:** 
- iostream — input and output
- vector — storing binary bits
- iomanip — formatted terminal output
- string — text and ANSI color codes

## What I Learned

1. **Binary Arithmetic**

I learned how decimal numbers from 0 to 255 can be represented using exactly 8 bits and practiced working with bitwise operations.

2. **Integer Overflow**

I learned why an 8-bit unsigned integer has a maximum value of 255 and how arithmetic behaves when that limit is exceeded.

3. **Wraparound Behavior**

I learned that an overflowing 8-bit result can be viewed as arithmetic modulo 256.

4. **Object-Oriented Programming**

I practiced using a C++ class to encapsulate data and related operations, separating the calculation logic from the rest of the program.

5. **Software Testing**

I learned to test both ordinary and boundary conditions rather than relying only on simple examples.

The test cases include normal addition, zero values, the maximum 8-bit value, and multiple overflow scenarios.

6. **Problem Solving**

Building this project helped me break a simple arithmetic problem into smaller components: binary conversion, calculation, overflow detection, result handling, testing, and user interaction.

## Limitations and Future Improvements

This project focuses on demonstrating the concepts of 8-bit arithmetic rather than reproducing the complete hardware implementation of an adder.

A future version could implement the addition at the individual bit level using Full Adder logic and carry propagation instead of relying on C++ integer addition.

This would allow the project to explore concepts such as: 
- XOR, AND, and OR logic
- Carry propagation
- Half Adders and Full Adders
- Ripple-Carry Adders
- Digital logic design
## Implementation Details

- **Class Design:** Created `Adder8Bit` class to encapsulate state (inputA, inputB, result, overflowFlag)
- **Overflow Detection:** Check if (inputA + inputB) > 255 to set overflow flag
- **Wraparound:** Use modulo 256 operator (%) to wrap result back to valid range
- **Input Validation:** Check inputs are in range [0, 255] before computation
- **Output Formatting:** Used ANSI escape codes for terminal colors and Unicode symbols for visual feedback

## Project Motivation 

This project is a small step toward understanding how higher-level programming relates to the lower-level principles behind computer systems.

By starting with a simple 8-bit arithmetic problem, I explored concepts that connect programming with computer architecture and digital logic, which I hope to study in greater depth in the future.

## Repository GitHub

https://github.com/LeTrungNguyen-07/8bit-adder-overflow-detection.git

---
