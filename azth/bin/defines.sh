#!/bin/bash

source ./config.sh.dist # "hack" to avoid missing conf variables

source ./config.sh # should overwrite previous

# you can choose build type from cmd argument
if [ ! -z $1 ] 
then 
    CCTYPE=$1
    CCTYPE=${CCTYPE^} # capitalize first letter if it's not yet
fi

BUILDPATH=$BINPATH

[ $CCTYPE == "Debug" ] && BUILDPATH="$BUILDPATH/debug/build/" ||  BUILDPATH="$BUILDPATH/release/build/" 

[ $CCTYPE == "Debug" ] && BINPATH="$BINPATH/debug" || BINPATH="$BINPATH/release" 

mkdir -p $BUILDPATH
mkdir -p $BINPATH
