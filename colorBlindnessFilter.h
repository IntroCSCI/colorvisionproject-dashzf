#ifndef COLORBLINDNESSFILTER_H
#define COLORBLINDNESSFILTER_H
#include <iostream>
#include <cmath>
#include "bitmap/bitmap.h" //library that adds pixels/bitmaps


using namespace std;


class pixelFilter 
{
  private:

    //multiplier constants for conversion
    const double toLMSMultiplierMatrix[3][3] = {{17.8824, 43.5161, 4.1194}, {3.4557, 27.1554, 3.8671}, {0.0300, 0.1843, 1.4671}};
    const double toRGBMultiplierMatrix[3][3] = {{0.0809, -0.1305, 0.1167}, {-0.0102, 0.0540, -0.1136}, {-0.0004, -0.0041, 0.6935}};  
    const double protanMultiplierMatrix[3] = {0, 2.0234, -2.5258} ;
    const double deuteranMultiplierMatrix[3] = {0.4942, 0, 1.2483};

    //holding pixels
    int pixelMatrixRGB[3]; //matrix holding the R, G, and B values of the current pixel
    double pixelMatrixLMS[3]; //matrix holding the pixel in LMS format (longwave, middlewave, shortwave)

    //conversion functions
    void convertPixelToLMS(); //converts contents of pixelMatrixRGB to LMS and puts in pixelMatrixLMS
    void convertPixelToRGB(); //converts contents of pixelMatrixLMS to LMS and puts in pixelMatrixRGB

    void clampRGB(); 

    //set LMS pixel data
    void setPixelL(double);
    void setPixelM(double);
    void setPixelS(double);
    void setPixelLMS(double, double, double);

    //get LMS pixel data
    double getPixelL();
    double getPixelM();
    double getPixelS();

  public:

    //set pixel data
    void setPixel(int, int, int);
    void setPixelRed(int);
    void setPixelGreen(int);
    void setPixelBlue(int);
    
    //get pixel data
    int getPixelRed();
    int getPixelGreen();
    int getPixelBlue();
    

    //filter functions
    void filterProtan();
    void filterDeuteran();
    void filterMonochrome();

    pixelFilter();

};

#endif