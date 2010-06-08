#!/bin/sh
#
echo "Generating build information using aclocal, autoheader, automake and autoconf"
echo "This may take a while ..."

# Touch the timestamps on all the files since CVS messes them up
directory=`dirname $0`
touch $directory/configure.ac

# Regenerate configuration files
libtoolize --copy
aclocal
autoheader
automake --foreign --add-missing --copy
autoconf

# Run configure for this platform
#./configure $*
echo "Now you are ready to run ./configure"
