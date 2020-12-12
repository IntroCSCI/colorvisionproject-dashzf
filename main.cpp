#include <iostream>
#include <cmath>
#include <vector>
#include "bitmap/bitmap.h" //library that adds pixels/bitmaps
#include "colorBlindnessFilter.h" // colorblindnessfilter library

using namespace std;

void filterPixel(Pixel &, int);
void printFilterMenu();

int main()
{

  pixelFilter currentPixel; //var to store RGB values of current pixels
  Bitmap imageInput; //stores the image
  string imagePath; //stores the path to the image
  vector < vector <Pixel> > rawPixelValues; //holds raw pixel values
  int filterType; //stores the filter we're using. 1=monochrome, 2=protan, 3=deuteran
  int errCnt = 0;



  do{ // image input, check to see if it's valid
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

  do{ //get filter type, make sure it's 1-3
    if( errCnt >= 1 ){ //check to see if this loop has been repeated
      cout << "Please enter a number between 1 and 3." << endl;
    }
    else {
      printFilterMenu();
    }
    cin >> filterType;
    cout << endl;

    errCnt++;
  }
  while( filterType > 3 || filterType < 1);
  


  rawPixelValues = imageInput.toPixelMatrix(); //copies all pixel values from the image into this vector
  cout << "Processing...\n";


//go through every pixel
  for(int y = 0; y < rawPixelValues.size(); y++ ) { //Y counter
    for(int x = 0; x < rawPixelValues.size(); x++ ) { //X counter

      currentPixel.setPixel(rawPixelValues[x][y].red,  rawPixelValues[x][y].green, rawPixelValues[x][y].blue); // copy values from the pixel vector into the pixelFilter


      // different operations based on the filter
      if(filterType == 1){ //monochromacity
        currentPixel.filterMonochrome();
      }
      else if(filterType == 2) { //protanomalty
        currentPixel.filterProtan();
      }
      else if(filterType == 3) { //Deuteranomaly
        currentPixel.filterDeuteran();
      }

      //copy values back into pixel vector
      rawPixelValues[x][y].red = currentPixel.getPixelRed();
      rawPixelValues[x][y].green = currentPixel.getPixelGreen();
      rawPixelValues[x][y].blue = currentPixel.getPixelBlue();


    }
  }

  imageInput.fromPixelMatrix(rawPixelValues); //copy values from vector into the bmp
  imageInput.save("out.bmp"); //save bmp

  cout << "Done! Saved as out.bmp\n";



  return 0;
} //end main






//functions


void printFilterMenu(){
  cout << "\nWhat kind of color blindness do you want? (enter number)" << endl;
  cout << "1. Monochromaticity - total color blindness." << endl;
  cout << "2. Protanopia - complete lack of ability to see red." << endl;
  cout << "3. Deuteranopia - lack of ability to see green" << endl;

  return;
}