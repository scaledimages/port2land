# port2land

## Portrait to Landscape

### Currently A Work In Progress

Utility to format portrait photos onto a landscape background using the ImageMagick library
using the the original photo as a stretched/dimmed background image to fill the
landscape frame.

Currently a command line application with some fixed options.  Eventually it
will also include command line options to teak some settings along with a GUI 
to select and view the files.

### Design Notes

 * Makefile based builds (may switch to xmake)
 * imagemagick library for all image manipulation
 * uses fmt c++ formatting library to help format imagemagick options
 * since this is more than likely going to be used to post images
   online or publicly, all exif data is stripped out

### Background

This utility was the result of me going down a rabbit hole.

I went to put together a collection of photos spanning 20 years for some friends
on a digital photo frame that was on sale at Walmart.  There were a number of shots
that were done in portrait mode, and on some of them the frame would not rotate them
unless it was on a landscape background.  There were too many to justify doing them
one by one in Gimp, and while I was at it I thought I'd code it so that it created the
stretched blurry background like you see on TV/TicTok.

Here is an example of the original image:

![port2land before image](https://assets.scaledimages.com/img/port2land-before.jpg "Original Image")


Here is what it looks like after running through port2land

![port2land aftert image](https://assets.scaledimages.com/img/port2land-after.jpg "Output Image")

### Current Status

Rough proof of concept command line utility that has resolutions and
output file name hard coded.

### To Do

 * Override Exif.Image.Orientation tag
 * Move the heavy lifting to a parameterized function or class.
 * Add command line options to adjust all the parameters
   - resulting image size
   - rotation direction
   - output file name
 * Create GUI front end using wxWidgets
   - file selection dialog
   - save default options
   - preview result 
   - choose output filename
 * Port to OSX and Windows
 * Create Binary Installation Packages

### Support This Project

If you wind up using this or otherwise find it helpful feel free to:

[![buy me a coffee](https://assets.scaledimages.com/img/buy-me-a-coffee.png "Buy Me A Coffee")](https://www.buymeacoffee.com/scaledimages)
