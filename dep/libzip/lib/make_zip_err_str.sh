#!/bin/sh

#  make_zip_err_str.sh: create zip_err_str.c from zip.h
#  Copyright (C) 1999-2007 Dieter Baron and Thomas Klausner
#
#  This file is part of libzip, a library to manipulate ZIP archives.
#  The authors can be contacted at <libzip@nih.at>
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions
#  are met:
#  1. Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in
#     the documentation and/or other materials provided with the
#     distribution.
#  3. The names of the authors may not be used to endorse or promote
#     products derived from this software without specific prior
#     written permission.
# 
#  THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS
#  OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
#  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
#  ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY
#  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
#  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
#  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
#  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
#  IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
#  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
#  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


if [ "$#" -ne 2 ]
then
    echo "Usage: $0 in_file out_file" >&2
    echo "       e.g. $0 zip.h zip_err_str.c" >&2
    exit 1
fi

if [ "$1" = "$2" ]
then
    echo "$0: error: output file = input file" >&2
    exit 1
fi

#rcsid=`echo '$NiH: make_zip_err_str.sh,v 1.7 2004/04/25 16:20:16 dillo Exp $' | tr -d '$'`
#inrcsid=`sed -n 's/^  \$\([^$]*[^ ]\) *\$$/\1/p' "$1"`

cat <<EOF >> "$2.$$" || exit 1
/*
   This file was generated automatically by $0
   from $1; make changes there.
 */

#include "zipint.h"



const char * const _zip_err_str[] = {
EOF

sed -n  '/^#define ZIP_ER_/ s/.*\/\* . \([^*]*\) \*\//    "\1",/p' "$1" \
    >> "$2.$$" || exit 1

cat <<EOF >> "$2.$$" || exit 1
};

const int _zip_nerr_str = sizeof(_zip_err_str)/sizeof(_zip_err_str[0]);

#define N ZIP_ET_NONE
#define S ZIP_ET_SYS
#define Z ZIP_ET_ZLIB

const int _zip_err_type[] = {
EOF

sed -n  '/^#define ZIP_ER_/ s/.*\/\* \(.\) \([^*]*\) \*\//    \1,/p' "$1" \
    >> "$2.$$" || exit 1

echo '};' >> "$2.$$" || exit 1

mv "$2.$$" "$2" || exit 1
