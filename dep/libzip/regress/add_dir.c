/*
  add_dir.c -- test case for adding file from buffer to archive
  Copyright (C) 1999-2008 Dieter Baron and Thomas Klausner

  This file is part of libzip, a library to manipulate ZIP archives.
  The authors can be contacted at <libzip@nih.at>

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions
  are met:
  1. Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
  2. Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in
     the documentation and/or other materials provided with the
     distribution.
  3. The names of the authors may not be used to endorse or promote
     products derived from this software without specific prior
     written permission.
 
  THIS SOFTWARE IS PROVIDED BY THE AUTHORS ``AS IS'' AND ANY EXPRESS
  OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
  ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY
  DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE
  GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER
  IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
  OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
  IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/



#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "zip.h"

const char *dir[2] = {
    "testdir/",
    "testdir-noslash"
};

const char *prg;

int
main(int argc, char *argv[])
{
    const char *archive;
    struct zip *za;
    char buf[100];
    size_t i;
    int err;

    prg = argv[0];

    if (argc != 2) {
	fprintf(stderr, "usage: %s archive\n", prg);
	return 1;
    }

    archive = argv[1];
    
    if ((za=zip_open(archive, ZIP_CREATE, &err)) == NULL) {
	zip_error_to_str(buf, sizeof(buf), err, errno);
	fprintf(stderr, "%s: can't open zip archive %s: %s\n", prg,
		archive, buf);
	return 1;
    }

    for (i=0; i<sizeof(dir)/sizeof(dir[0]); i++) {
	if (zip_add_dir(za, dir[i]) == -1) {
	    fprintf(stderr, "%s: can't add file `%s': %s\n", prg,
		    dir[i], zip_strerror(za));
	    return 1;
	}
    }

    if (zip_close(za) == -1) {
	fprintf(stderr, "%s: can't close zip archive %s\n", prg,
		archive);
	return 1;
    }

    return 0;
}
