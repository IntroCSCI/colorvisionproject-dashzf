# Colorblindness Image Filter-atron 2000

## Description

Takes RGB values and a filter type (Monochromaticity, Protanopia, Deuteranomaly, Tritanopia), outputs an adjusted value.
RGB values should be 0-255, filter # should be 1-4.

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
Enter red value: 239
Enter green value: 74
Enter blue value: 127

What kind of color blindness do you want? (enter number)
1. Monochromaticity - total color blindness.
2. Deuteranomaly - lack of ability to see green
3. Protanopia - complete lack of ability to see red.
4. Tritanopia - lack of ability to see blue.
1

146, 146, 146
```

## C++ Guide

### Variables and Data Types

The program accepts 3 `int`s between 0-255 to represent the input color values. `Int` was chosen because GRB values are whole numbers. The program also accepts an additional `int` between 1 and 4 (inclusive) to choose which "filter" to use. Filters:
```
1. Monochromaticity - total color blindness.
2. Deuteranomaly - lack of ability to see green
3. Protanopia - complete lack of ability to see red.
4. Tritanopia - lack of ability to see blue.
```
The program outputs 3 `ints` for the adjusted color values.

### Input and Output

!!!Replace with a summary and examples of how input and output have been used effectively and appropriately!!!

### Decisions

This program uses `if` statements to do different behaviors based on what filter the user chooses.

### Iteration

This program makes use of `do while` loops to verify inputs and ensure they are inside the expected range.

### File Input and Output

!!!Replace with a summary and examples of how input and/or output of files have been used effectively and appropriately!!!
