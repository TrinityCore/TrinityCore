########################################################################
#
# Makefile for compiling StormLib under linux
#
# Author: Marko Friedemann <marko.friedemann@bmx-chemnitz.de>
# Created at: Mon Jan 29 18:26:01 CEST 2001
# Computer: whiplash.flachland-chemnitz.de 
# System: Linux 2.4.0 on i686
#    
# Copyright (c) 2001 BMX-Chemnitz.DE All rights reserved.
#
########################################################################

FILES.cpp = SCommon.cpp SCompression.cpp SFileCompactArchive.cpp \
	SFileCreateArchiveEx.cpp SFileExtractFile.cpp SFileFindFile.cpp \
	SListFile.cpp SFileOpenArchive.cpp SFileOpenFileEx.cpp SFileReadFile.cpp \
	StormPortLinux.cpp wave/wave.cpp huffman/huff.cpp \
	pklib/crc32.cpp pklib/explode.cpp pklib/implode.cpp 
FILES.o = $(FILES.cpp:.cpp=.o)

LIB = libStorm.so

CXX = g++
CFLAGS = -Wall -s -D__SYS_ZLIB
I_FLAGS = 
LDFLAGS = -lz -lbz2

all: $(LIB)

$(LIB): $(FILES.o)
	$(LD) -shared $(LDFLAGS) -o $(LIB) $(FILES.o)

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(FILES.o) $(LIB)

new: clean all

mrproper: clean
	$(RM) Makefile.deps

mrnew: mrproper new

install: $(LIB)
	install $(I_FLAGS) $(LIB) /usr/local/lib
	mkdir -p /usr/local/include/StormLib
	cp Storm.h /usr/local/include/StormLib
	cp StormPort.h /usr/local/include/StormLib
	ldconfig

deps:
	$(CXX) -MM $(CFLAGS) $(FILES.cpp) > Makefile.deps
	
-include Makefile.deps

.PHONY: all clean new mrpoper mrnew install deps
