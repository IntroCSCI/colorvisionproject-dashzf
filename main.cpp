#include <iostream>
#include <cmath>
#include "libraries/bitmap.h" //library that adds pixels/bitmaps

using namespace std;

void filterPixel(Pixel &, int);
void printFilterMenu();

int main()
{
  Pixel currentPixel; //var to store RGB values of current pixels
  Bitmap imageInput;
  string imagePath;
  vector < vector <Pixel> > rawPixelValues; //holds raw pixel values
  int filterType;
  int errCnt = 0;

  do{
    if( errCnt >= 1 ){ //check to see if this loop has been repeated
      cout << "Please input a valid .bmp file." << endl;
    }
    else {
      cout << "Please input an image (must be a square .bmp with 24 bit color depth, case sensitive): ";
    }
    getline(cin, imagePath);
    cout << endl;
    imageInput.open(imagePath);

    errCnt++;
  }
  while( ! imageInput.isImage() ); //checks to see if it's a valid image

  errCnt = 0;

  do{
    if( errCnt >= 1 ){ //check to see if this loop has been repeated
      cout << "Please enter a number between 1 and 4." << endl;
    }
    else {
      printFilterMenu();
    }
    cin >> filterType;
    cout << endl;

    errCnt++;
  }
  while( filterType > 4 || filterType < 1);
  
  rawPixelValues = imageInput.toPixelMatrix(); //copies all pixel values from the image into this vector
  cout << "Processing...\n";

  for(int y = 0; y < rawPixelValues.size(); y++ ) { //Y counter
    for(int x = 0; x < rawPixelValues.size(); x++ ) { //X counter
      currentPixel = rawPixelValues[x][y];  //copy pixel value at current X and Y into currentPixel
      filterPixel(currentPixel, filterType); //filter currentPixel
      rawPixelValues[x][y] = currentPixel; //replace values in the vector with the adjusted ones
    }
  }

  imageInput.fromPixelMatrix(rawPixelValues); //copy values from vector into the bmp
  imageInput.save("out.bmp"); //save bmp

  cout << "Done! Saved as out.bmp\n";

  return 0;
}


void filterPixel(Pixel & pixIn, int filterNum){
  if( filterNum == 1 ){
    //Do monochromaticity
    pixIn.red = (pixIn.red + pixIn.blue + pixIn.green)/3; //get average of all 3 numbers
    pixIn.green = pixIn.red;
    pixIn.blue = pixIn.red;

  }
  else if( filterNum == 2 ){
    //do Deuteranomaly - green
    pixIn.red = pixIn.red;
    pixIn.green = 0;
    pixIn.blue = pixIn.blue;
  }
  else if( filterNum == 3 ) {
    //do Protanopia - red
    pixIn.red = 0;
    pixIn.green = pixIn.green;
    pixIn.blue = pixIn.blue;
  }
  else if( filterNum == 4) {
    //do tritanopia
    pixIn.red = pixIn.red;
    pixIn.green = pixIn.blue;
    pixIn.blue = 0;
  }
 // cout << pixIn.red << ", " << pixIn.green << ", " << pixIn.blue << endl;

  return;
}

void printFilterMenu(){
  cout << "\nWhat kind of color blindness do you want? (enter number)" << endl;
  cout << "1. Monochromaticity - total color blindness." << endl;
  cout << "2. Deuteranomaly - lack of ability to see green" << endl;
  cout << "3. Protanopia - complete lack of ability to see red." << endl;
  cout << "4. Tritanopia - lack of ability to see blue." << endl;

  return;
}