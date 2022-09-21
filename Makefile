#
# Makefile for port2land utility
#
#

OBJS = port2land.o

# WXCONFIG = /usr/src/wxWidgets-3.0.1/wx-config
# WXCONFIG = /usr/bin/wx-config
MAGICKCONFIG = /usr/lib/x86_64-linux-gnu/ImageMagick-6.9.11/bin-q16/Magick++-config

#LIBPATH = libs
LIBS = -lexiv2 -lfmt `${MAGICKCONFIG} --ldflags --libs`
# LIBS = -Llibs -ls3 
CPP = g++
# COPTS = -I/usr/include/lua5.1
LD = ld
CC = gcc
CCOPTS = `${MAGICKCONFIG} --cppflags --cxxflags` 

.cpp.o :
	$(CPP) $(CCOPTS) -c $< 

.c.o :
	$(CPP) $(CCOPTS) -c $< 


port2land:  port2land.o 
	$(CPP) $(CCOPTS) $(OBJS) -o $@ $(LIBS)
    
.PHONY: clean doc

clean:
	rm *.o

doc:
	doxygen
