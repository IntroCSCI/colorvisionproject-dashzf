# Colorblindness Image Filter-atron 2000 v3
## Description

This program attemts to simulate three different types of colorblindness:
  1. Monochromaticity - total color blindness.
  2. Deuteranopia - lack of ability to see green
  3. Protanopia - complete lack of ability to see red.

It takes a square .bmp image with 24 bit color depth eand a filter type (Monochromaticity, Protanopia, Deuteranomaly), and outputs the adjusted image as `out.bmp`.

## Developer

Dash Ferrero

## Example

To run the program, give the following commands:

```
g++ -std=c++11 bitmap/bitmap.cpp *.cpp -o cvp; ./cvp
```

Here is an example of the program running:

```
Please input an image (must be a square .bmp with 24 bit color depth, case sensitive): pixTest4.bmp


What kind of color blindness do you want? (enter number)
1. Monochromaticity - total color blindness.
2. Protanopia - complete lack of ability to see red.
3. Deuteranopia - lack of ability to see green
2

Processing...
Done! Saved as out.bmp
```

## C++ Guide

### Variables and Data Types

This program primarily uses the bitmap library's `Pixel` and `Bitmap` datatypes to process the image. It also uses integers and strings to hold user input.

The program accepts a string specifying the path to the image and an integer representing the desired filter. Filters:
```
1. Monochromaticity - total color blindness.
2. Deuteranopia - lack of ability to see green
3. Protanopia -  lack of ability to see red.
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
This program uses functions to simplify the main program and avoid having to duplicate text. For example, the `printFilterMenu` function, which prints the menu displaying the different filter options to the console.



## Classes
V1 of this program implements a lot of new functionality through the use of classes. The `pixelFilter` class features a handful of functions for filtering images and interacting with the class:

### Creating a variable 

`pixelFilter <variable name>`
*`pixelFilter` can be used as a datatype when declaring a variable.*

### Setting and getting
`void setPixel( int, int, int)`
*The `setPixel` function is used to set the red, green, and blue values in your variable. It accepts 3 `int`s between 0 and 255. *

`void setPixelRed( int )`
`void setPixelGreen( int )`
`void setPixelBlue( int )`
*These functions can be used to set each channel of the pixel individually. They all accept an `int` between 0 and 255.*

`int getPixelRed()`
`int getPixelGreen()`
`int getPixelBlue()`
*These functions can be used to retrive the values from your variable. They return an `int` between 0 and 255*

### Filters

`void filterProtan()`
`void filterDeuteran()`
`void filterMonochrome()`
*These functions are used to apply filters to the pixel. Their names correspond to their functionality. Fhe `filterProtan` function applies a filter for simulating Protanopia. The `filterDeuteran` function applies a filter for simulating Deuteranopia. The `filterMonochrome` function applies a function for simulating Monochromaticity. *


### Example Code 
```
#include <iostream>
#include "colorBlindnessFilter.h"

using namespace std;

int main {
  pixelFilter myPixel;

  myPixel.setPixel(255, 128, 0);
  mypixel.filterProtan();

  cout << "With a Protanopia filter, your values of 255, 128, and 0 become " << myPixel.getPixelRed << myPixel.getPixelGreen << myPixel.getPixelBlue << endl;

  return 0;

}
```



## Notes
This program uses the algorithm by Lee and Pinheiro dos Santos for simulating colorblindness from their paper [An Adaptive Fuzzy-Based System to Simulate, Quantify and Compensate Color Blindness](https://arxiv.org/pdf/1711.10662.pdf). It seems that the algorithm sometimes returns RGB values beyond the normal range (0-255). To combat this, the program will automatically clamp any output values to 0 and 255. Unfortunatley, this often results in images that are heavily tinted red or green because the respective color channels are fully white. I have not been able to find a better solution.

The monochormacity filter simply finds the average of all 3 RGB values and sets all 3 channels to that number.

## Changelog
### V0.2
* Added support for full images
* Adjusted filtering method

###V1
* New filtering method based on the algorithm by Lee and Pinheiro dos Santos for simulating colorblindness from their paper [An Adaptive Fuzzy-Based System to Simulate, Quantify and Compensate Color Blindness](https://arxiv.org/pdf/1711.10662.pdf). The new filter does not support Tritanopia.
