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

    // imagemagick Images
    Image origImage;
    Image outputImage;

    // check command line arguments
    if ( argc != 2 ) {
        cerr << "Usage: " << argv[0] << " inputfile " << endl;
        exit(-1);
    } else {
        inputFileName = argv[1];
        origHeight = origImage.rows();
        origWidth = origImage.columns();
    } 

    // rotate image if wider than taller
    origImage.read(inputFileName);
    if ( origImage.columns() > origImage.rows() ) { 
        origImage.rotate(-90);
    } 

    // create destination image
    outputImage = origImage;
    string resizeStr = fmt::format("{}x{}!",outWidth,outHeight);
    outputImage.resize(resizeStr);

    // blur and dim the background
    outputImage.blur(0.0,6.0);
    outputImage.modulate(55.0,100.0,100.0);

    // resize the new image to the same height as the output image,
    // and add a grey 2 pixel border
    resizeStr = fmt::format("x{}",outHeight);
    origImage.resize(resizeStr);
    origImage.borderColor("grey");
    origImage.border("2x2-2-2");
    
    // figure out x offset to center horizontally on background
    leftOffset = ( outputImage.columns() - origImage.columns() ) / 2;
    string compositeGeometry = fmt::format("+{}+0",leftOffset); //"+" + leftOffset + "+0";
    outputImage.composite( origImage , compositeGeometry , OverCompositeOp );

    // strip all exif data
    outputImage.strip();

    // set image orientation
    //  - maybe later link to exiv2 library and set some
    //    exif tags
    outputImage.orientation(TopLeftOrientation);

    // save the image
    outputImage.quality(90);
    outputImage.write("output.jpg");

    return 0;
}
