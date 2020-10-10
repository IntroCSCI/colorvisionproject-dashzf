# Colorblindness Filter
## Description

This program attemts to simulate four different types of colorblindness:
  1. Monochromaticity - total color blindness.
  2. Deuteranomaly - lack of ability to see green
  3. Protanopia - complete lack of ability to see red.
  4. Tritanopia - lack of ability to see blue.

## Developer

Dash Ferrero

## Example

To run the program, give the following commands:

```
g++ --std=c++11 main.cpp -o cvp
./cvp
```

Here is an example of the program running:

```
Enter red value: 82 
Enter green value: 96
Enter blue value: 246

What kind of color blindness do you want? (enter number)
1. Monochromaticity - total color blindness.
2. Deuteranomaly - lack of ability to see green
3. Protanopia - complete lack of ability to see red.
4. Tritanopia - lack of ability to see blue.
3

9, 96, 246
```

## C++ Guide

### Variables and Data Types

This program uses integers and the bitmap library's `pixel` datatype to process the supplied values.

### Input and Output

This program accepts 3 `int`s representing the valuse of 3 colors: red, green, and blue. The inputs must be between 0 and 255. The program also accepts an addition `int` specifying which filter to apply.

### Decisions

This program uses `if` and `else if` statements to ensure the correct filter gets applied to the input values.

### Iteration

This program uses multiple `do while` loops to validate inputs are within acceptable parameters. 

### File Input and Output

This program does not input or output any files due to ~~layoffs~~ ~~budget cuts~~ me being a lazy ass.