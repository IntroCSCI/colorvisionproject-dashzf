#include <iostream>
#include <cmath>
#include "libraries/bitmap.h" //library that adds pixels/bitmaps

using namespace std;

int main()
{
  Pixel pixIn, pixOut;
  int type;
  int errCnt = 0;

  do{
  cout << "Enter red value (0-255): ";
  cin >> pixIn.red;
  }
  while( pixIn.red > 255 || pixIn.red < 0 ); //check to make sure it's within range

  do{
  cout << "Enter green value (0-255): ";
  cin >> pixIn.green;
  }
  while( pixIn.green > 255 || pixIn.green < 0 ); //check to make sure it's within range

  do{
  cout << "Enter blue value (0-255): ";
  cin >> pixIn.blue;
  }
  while( pixIn.blue > 255 || pixIn.blue < 0 ); //check to make sure it's within range

  do{
    if( errCnt >= 1 ){ //check to see if this loop has been repeated
      cout << "Please enter a number between 1 and 4." << endl;
    }
    else {
      cout << "\nWhat kind of color blindness do you want? (enter number)" << endl;
      cout << "1. Monochromaticity - total color blindness." << endl;
      cout << "2. Deuteranomaly - lack of ability to see green" << endl;
      cout << "3. Protanopia - complete lack of ability to see red." << endl;
      cout << "4. Tritanopia - lack of ability to see blue." << endl;
    }
    cin >> type;
    cout << endl;

    errCnt++;
  }
  while( type > 4 || type < 1);


Pixel 
  if( type == 1 ){
    //Do monochromaticity
    pixOut.red = (pixIn.red + pixIn.blue + pixIn.green)/3; //get average of all 3 numbers
    pixOut.green = pixOut.red;
    pixOut.blue = pixOut.red;

  }
  else if( type == 2 ){
    //do Deuteranomaly - green
    pixOut.red = pixIn.red;
    pixOut.green = sqrt(pixIn.green);
    pixOut.blue = pixIn.blue;
  }
  else if( type == 3 ) {
    //do Protanopia - red
    pixOut.red = sqrt(pixIn.red);
    pixOut.green = pixIn.green;
    pixOut.blue = pixIn.blue;
  }
  else if( type == 4) {
    //do tritanopia
    pixOut.red = pixIn.red;
    pixOut.green = pixIn.blue;
    pixOut.blue = sqrt(pixIn.blue);
  }
  cout << pixOut.red << ", " << pixOut.green << ", " << pixOut.blue << endl;


  return 0;
}


