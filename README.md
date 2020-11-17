# Colorblindness Image Filter-atron 2000 v2
## Description

This program attemts to simulate four different types of colorblindness:
  1. Monochromaticity - total color blindness.
  2. Deuteranomaly - lack of ability to see green
  3. Protanopia - complete lack of ability to see red.
  4. Tritanopia - lack of ability to see blue.

It takes a square .bmp image with 24 bit color depth eand a filter type (Monochromaticity, Protanopia, Deuteranomaly, Tritanopia), and outputs the adjusted image as `out.bmp`.

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
Please input an image (must be a square .bmp with 24 bit color depth, case sensitive): pixTest4.bmp


What kind of color blindness do you want? (enter number)
1. Monochromaticity - total color blindness.
2. Deuteranomaly - lack of ability to see green
3. Protanopia - complete lack of ability to see red.
4. Tritanopia - lack of ability to see blue.
4

Processing...
Done! Saved as out.bmp
```

## C++ Guide

### Variables and Data Types

This program primarily uses the bitmap library's `Pixel` and `Bitmap` datatypes to process the image. It also uses integers and strings to hold user input.

The program accepts a string specifying the path to the image and an integer representing the desired filter. Filters:
```
1. Monochromaticity - total color blindness.
2. Deuteranomaly - lack of ability to see green
3. Protanopia - complete lack of ability to see red.
4. Tritanopia - lack of ability to see blue.
```
The program outputs a `.bmp` file called `out.bmp`

### Input and Output

The program accepts a string specifying the path to the image and an integer representing the desired filter. it outputs text displaying options and the current status of the program.

### Decisions

This program uses `if` and `else if` statements to ensure the correct filter gets applied to the input values and check for errors.

### Iteration

This program uses multiple `do while` loops to validate inputs are within acceptable parameters. It also uses `for` loops to proccess every pixel.

### File Input and Output

This program accepts a square `.bmp` image with 24 bit color depth. It outputs a bmp of the same size with the name `out.bmp`.

### Arrays/Vectors
This program uses a vector to store data of all of the pixels in the image for easy editing.

### Functions
This program uses functions to simplify the main program and avoid having to duplicate text. For example, the `filterPixel` function, which accepts a `Pixel` and an `int`, applies the filter specified by the `int` to the `Pixel`.

## Disclaimer
This colorblindness simulator has no basis in reality. I have no idea if this is what colorblind people actually see.

## Changelog
### V0.2
* Added support for full images
* Adjusted filtering method