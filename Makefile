#
# Makefile for port2land utility
#
# trying to keep it simple
#

#

# WXCONFIG = /usr/src/wxWidgets-3.0.1/wx-config
# WXCONFIG = /usr/bin/wx-config
MAGICKCONFIG = /usr/lib/x86_64-linux-gnu/ImageMagick-6.9.11/bin-q16/Magick++-config

# -----------------------------------------------------------------
# you shouldn't have to modify anything below this line to compile
# -----------------------------------------------------------------

OBJS = port2land.o
LIBS = -lexiv2 -lfmt `${MAGICKCONFIG} --ldflags --libs`
CPP = g++
LD = ld
CC = gcc

CCOPTS = `${MAGICKCONFIG} --cppflags --cxxflags` 

.cpp.o :
	$(CPP) $(CCOPTS) -c $< 

.c.o :
	$(CPP) $(CCOPTS) -c $< 

port2land:  port2land.o 
	$(CPP) $(CCOPTS) $(OBJS) -o $@ $(LIBS)
    
.PHONY: clean

clean:
	rm *.o

