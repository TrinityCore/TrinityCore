#!/bin/bash

source ./config.sh

BUILDPATH=$BINPATH

(( $CDEBUG == 1 )) && BUILDPATH="$BUILDPATH/debug/build/" ||  BUILDPATH="$BUILDPATH/release/build/" 

(( $CDEBUG == 1  )) && BINPATH="$BINPATH/debug" || BINPATH="$BINPATH/release" 

mkdir -p $BUILDPATH
mkdir -p $BINPATH
