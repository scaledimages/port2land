#include <Magick++.h>
#include <string>
#include <iostream>

#include <fmt/core.h>

using namespace std;
using namespace Magick;

int main (int argc , char **argv ) {
    InitializeMagick(*argv);

    string inputFileName = "";
    string outputFileName = "";

    int outHeight = 1024;
    int outWidth = 1280;

    int origHeight = 0;
    int origWidth = 0;

    int leftOffset = 0;
    int rightOffset = 0; 

    Image origImage;

    Image outputImage;

    if ( argc != 2 ) {
        cerr << "Usage: " << argv[0] << " inputfile " << endl;
        exit(-1);
    } else {
        inputFileName = argv[1];
        origHeight = origImage.rows();
        origWidth = origImage.columns();
    } 

    cout << "Input: " << inputFileName << endl;

    origImage.read(inputFileName);
    if ( origImage.columns() > origImage.rows() ) { 
        origImage.rotate(-90);
    } 

    // create destination image
    outputImage = origImage;

    outputImage.resize("1280x1024!");
    
    outputImage.blur(0.0,6.0);
    // outputImage.opacity(100);
    outputImage.modulate(55.0,100.0,100.0);


    // set the new image to the same height as the output image
    origImage.resize("x1020");
    origImage.borderColor("grey");
    origImage.border("2x2-2-2");
    
    // figure out x offset
    leftOffset = ( outputImage.columns() - origImage.columns() ) / 2;
      
    string compositeGeometry = fmt::format("+{}+0",leftOffset); //"+" + leftOffset + "+0";

    outputImage.composite( origImage , compositeGeometry , OverCompositeOp );

    // set orientation exif tag appropriately

    outputImage.write("testme.jpg");

    return 0;
}
