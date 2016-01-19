#!/bin/bash

. "defines.sh"

echo "Cleaning build files"

CWD=$(pwd)

cd $BUILDPATH

make -f Makefile clean

cd $CWD

