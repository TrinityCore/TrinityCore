#!/bin/bash

source ./config.sh

BUILDPATH=$BINPATH

echo "TYPE: $TYPE"
DEBUG=0 && [[ "$TYPE" == "debug" ]] && DEBUG=1
BUILDPATH="$BUILDPATH/build-release" && [[ "$TYPE" == "debug" ]] && BUILD_PATH="$BUILDPATH/build-debug"
BINPATH="$BINPATH/bin-release" && [[ "$TYPE" == "debug" ]] && BUILD_PATH="$BINPATH/bin-debug"

mkdir -p $BUILDPATH
mkdir -p $BINPATH
