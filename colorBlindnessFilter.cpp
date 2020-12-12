#include <iostream>
#include "colorBlindnessFilter.h"

pixelFilter::pixelFilter(){};

void pixelFilter::setPixelRed(int r){
  pixelMatrixRGB[0] = r;
  return;
}

void pixelFilter::setPixelGreen(int g){
  pixelMatrixRGB[1] = g;
  return;
}

void pixelFilter::setPixelBlue(int b){
  pixelMatrixRGB[2] = b;
  return;
}

void pixelFilter::setPixel(int r, int g, int b){
  setPixelRed(r);
  setPixelGreen(g);
  setPixelBlue(b);
  return;
}

void pixelFilter::setPixelL(double l){
  pixelMatrixLMS[0] = l;
  return;
}

void pixelFilter::setPixelM(double m){
  pixelMatrixLMS[1] = m;
  return;
}

void pixelFilter::setPixelS(double s){
  pixelMatrixLMS[2] = s;
  return;
}

void pixelFilter::setPixelLMS(double l, double m, double s){
  setPixelL(l);
  setPixelM(m);
  setPixelS(s);
  return;
}



int pixelFilter::getPixelRed(){
  return pixelMatrixRGB[0];
}
int pixelFilter::getPixelGreen(){
  return pixelMatrixRGB[1];
}
int pixelFilter::getPixelBlue(){
  return pixelMatrixRGB[2];
}

double pixelFilter::getPixelL(){
  return pixelMatrixLMS[0];
}
double pixelFilter::getPixelM(){
  return pixelMatrixLMS[1];
}
double pixelFilter::getPixelS(){
  return pixelMatrixLMS[2];
}



void pixelFilter::convertPixelToLMS(){ //converts the RGB values to LMS (Longwave, middlewave, shortwave) values

  setPixelLMS(0, 0, 0); //resets all values  to 0

  for( int i = 0; i < 3; i++ ){ //count up collums
    for( int j = 0; j < 3; j++ ){ // multiplies R by each value is the first matrix conversion row, adds them all together. Repeat for G with 2nd conversion row and B with 3rd.
      pixelMatrixLMS[j] += (double)pixelMatrixRGB[i] * toLMSMultiplierMatrix[j][i];
    }
  }

}

void pixelFilter::convertPixelToRGB(){ //converts LMS values to RGB

  setPixel(0, 0, 0);

  for( int i = 0; i < 3; i++ ){
    for( int j = 0; j < 3; j++ ){ // multiplies L by each value is the first matrix conversion row, adds them all together. Repeat for M with 2nd conversion row and S with 3rd.
      pixelMatrixRGB[j] += pixelMatrixLMS[i] * toRGBMultiplierMatrix[j][i];
    }
  }

}

void pixelFilter::filterProtan(){

  double L;
  convertPixelToLMS(); //converts RGB to LMS

  L = getPixelL();
  
  setPixelL( ( L * protanMultiplierMatrix[1] ) + ( L * protanMultiplierMatrix[2] ) ); //applies filter. We only need to affect the L channel and we only use the last 2 values in the matrix

  convertPixelToRGB();

  clampRGB(); //clamps all values 0-255

  return;

}

void pixelFilter::filterDeuteran(){

  double L;
  convertPixelToLMS(); //converts RGB to LMS

  L = getPixelL();
  
  setPixelL( ( L * deuteranMultiplierMatrix[0] ) + ( L * deuteranMultiplierMatrix[2] ) ); //applies filter. We only need to affect the L channel and we only use the last 2 values in the matrix

  convertPixelToRGB();

  clampRGB(); //clamps all values 0-255

  return;

}

void pixelFilter::filterMonochrome(){
  
  setPixelRed( ( getPixelRed() + getPixelGreen() + getPixelBlue() ) / 3 ); //get average of all values, put it in red channel
  setPixel( getPixelRed(), getPixelRed(), getPixelRed() ); //copy value from red channel into all channels

  return;
}



void pixelFilter::clampRGB(){ //clamps all values to make sure they're between 0-255
  for( int i = 0; i < 3; i++ ) //go thru R, G, and B channels 
  {
    if( pixelMatrixRGB[i] > 255 ){ //clamp if above 255
      pixelMatrixRGB[i] = 255;
    }
    else if( pixelMatrixRGB[i] < 0 ){ //clamp if below 0
      pixelMatrixRGB[i] = 0;
    }
  }

  return;
}
