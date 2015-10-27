#!/bin/bash

. "defines.sh"

CWD=$(pwd)

cd $BUILDPATH

echo "Build path: $BUILDPATH"
echo "DEBUG info: $CDEBUG"
echo "Compilation type: $CCTYPE"
# -DCMAKE_BUILD_TYPE=$CCTYPE disable optimization "slow and huge amount of ram"
# -DWITH_COREDEBUG=$CDEBUG compiled with debug information

make clean
find -iname '*cmake*' -not -name CMakeLists.txt -exec rm -rf {} \+
cmake $SRCPATH -DCMAKE_INSTALL_PREFIX=$BINPATH -DCONF_DIR=$CONFDIR -DSERVERS=$CSERVERS -DSCRIPTS=$CSCRIPTS \
-DTOOLS=$CTOOLS -DUSE_SCRIPTPCH=$CSCRIPTPCH -DUSE_COREPCH=$CCOREPCH -DWITH_COREDEBUG=$CDEBUG  -DCMAKE_BUILD_TYPE=$CCTYPE -DWITH_WARNINGS=$CWARNINGS

cd $CWD
