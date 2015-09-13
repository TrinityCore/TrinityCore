#!/bin/bash

. "defines.sh"

CWD=$(pwd)

cd $BUILDPATH

echo "Build path: $BUILDPATH"
echo "DEBUG: $CDEBUG"
# -DCMAKE_BUILD_TYPE=$DEBUG disable optimization "slow and huge amount of ram"
# -DWITH_COREDEBUG=$DEBUG compiled with debug information

make clean
find -iname '*cmake*' -not -name CMakeLists.txt -exec rm -rf {} \+
cmake $SRCPATH -DCMAKE_INSTALL_PREFIX=$BINPATH -DCONF_DIR=$CONFDIR -DSERVERS=$CSERVERS -DSCRIPTS=$CSCRIPTS \
-DTOOLS=$CTOOLS -DUSE_SCRIPTPCH=$CSCRIPTPCH -DUSE_COREPCH=$CCOREPCH -DWITH_COREDEBUG=$CDEBUG -DWITH_WARNINGS=$CWARNINGS

cd $CWD
