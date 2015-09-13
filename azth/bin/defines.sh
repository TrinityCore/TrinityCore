#!/bin/bash

source ./config.sh

BUILDPATH=$BINPATH

echo "TYPE: $TYPE"
DEBUG=0 && [[ "$TYPE" == "debug" ]] && DEBUG=1
BUILDPATH="$BUILDPATH/release/build/" && [[ "$TYPE" == "debug" ]] && BUILD_PATH="$BUILDPATH/debug/build/"
BINPATH="$BINPATH/release" && [[ "$TYPE" == "debug" ]] && BUILD_PATH="$BINPATH/debug"

mkdir -p $BUILDPATH
mkdir -p $BINPATH
