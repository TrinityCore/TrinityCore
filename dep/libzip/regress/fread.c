/*
  $NiH: fread.c,v 1.6 2006/02/21 10:21:25 dillo Exp $

  fread.c -- test cases for reading from zip archives
  Copyright (C) 2004, 2005, 2006 Dieter Baron and Thomas Klausner

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

#include "zip.h"

enum when {
    WHEN_NEVER, WHEN_OPEN, WHEN_READ, WHEN_CLOSE
};

const char *when_name[] = {
    "no", "zip_fopen", "zip_fread", "zip_fclose"
};

int do_read(struct zip *, const char *, int, enum when, int, int);



const char *prg;

int
main(int argc, char *argv[])
{
    int fail, ze;
    struct zip *z;
    struct zip_source *zs;
    char *archive;
    char errstr[1024];

    fail = 0;

    prg = argv[0];

    if (argc != 2) {
        fprintf(stderr, "usage: %s archive\n", prg);
        return 1;
    }

    archive = argv[1];

    if ((z=zip_open(archive, 0, &ze)) == NULL) {
	zip_error_to_str(errstr, sizeof(errstr), ze, errno);
	printf("%s: opening zip archive ``%s'' failed: %s\n",
	       prg, archive, errstr);
	return 1;
    }

    fail += do_read(z, "storedok", 0, WHEN_NEVER, 0, 0);
    fail += do_read(z, "deflateok", 0, WHEN_NEVER, 0, 0);
    fail += do_read(z, "storedcrcerror", 0, WHEN_READ, ZIP_ER_CRC, 0);
    fail += do_read(z, "deflatecrcerror", 0, WHEN_READ, ZIP_ER_CRC, 0);
    fail += do_read(z, "deflatezliberror", 0, WHEN_READ, ZIP_ER_ZLIB, -3);
    fail += do_read(z, NULL, 0, WHEN_OPEN, ZIP_ER_INVAL, 0);
    fail += do_read(z, "nosuchfile", 0, WHEN_OPEN, ZIP_ER_NOENT, 0);
    fail += do_read(z, "deflatezliberror", ZIP_FL_COMPRESSED, WHEN_NEVER, 0,0);
    fail += do_read(z, "deflatecrcerror", ZIP_FL_COMPRESSED, WHEN_NEVER, 0, 0);
    fail += do_read(z, "storedcrcerror", ZIP_FL_COMPRESSED,
		    WHEN_READ, ZIP_ER_CRC, 0);
    fail += do_read(z, "storedok", ZIP_FL_COMPRESSED, WHEN_NEVER, 0, 0);

    zs = zip_source_buffer(z, "asdf", 4, 0);
    zip_replace(z, zip_name_locate(z, "storedok", 0), zs);
    fail += do_read(z, "storedok", 0, WHEN_OPEN, ZIP_ER_CHANGED, 0);
    fail += do_read(z, "storedok", ZIP_FL_UNCHANGED, WHEN_NEVER, 0, 0);
    zip_delete(z, zip_name_locate(z, "storedok", 0));
    fail += do_read(z, "storedok", 0, WHEN_OPEN, ZIP_ER_NOENT, 0);
    fail += do_read(z, "storedok", ZIP_FL_UNCHANGED, WHEN_NEVER, 0, 0);
    zs = zip_source_buffer(z, "asdf", 4, 0);
    zip_add(z, "new_file", zs);
    fail += do_read(z, "new_file", 0, WHEN_OPEN, ZIP_ER_CHANGED, 0);
    zip_unchange_all(z);

    if (zip_close(z) == -1) {
        fprintf(stderr, "%s: can't close zip archive `%s'\n", prg, archive);
        return 1;
    }

    exit(fail ? 1 : 0);
}



int
do_read(struct zip *z, const char *name, int flags,
	enum when when_ex, int ze_ex, int se_ex)
{
    struct zip_file *zf;
    enum when when_got;
    int ze_got, se_got;
    char b[8192];
    int n;
    char expected[80];
    char got[80];

    when_got = WHEN_NEVER;
    ze_got = se_got = 0;
    
    if ((zf=zip_fopen(z, name, flags)) == NULL) {
	when_got = WHEN_OPEN;
	zip_error_get(z, &ze_got, &se_got);
    }
    else {
	while ((n=zip_fread(zf, b, sizeof(b))) > 0)
	    ;
	if (n < 0) {
	    when_got = WHEN_READ;
	    zip_file_error_get(zf, &ze_got, &se_got);
	}
	n = zip_fclose(zf);
	if (when_got == WHEN_NEVER && n != 0) {
	    when_got = WHEN_CLOSE;
	    ze_got = n;
	    se_got = 0;
	}
    }

    if (when_got != when_ex || ze_got != ze_ex || se_got != se_ex) {
	zip_error_to_str(expected, sizeof(expected), ze_ex, se_ex);
	zip_error_to_str(got, sizeof(got), ze_got, se_got);
	printf("%s: got %s error (%s), expected %s error (%s)\n", prg,
	       when_name[when_got], got, 
	       when_name[when_ex], expected);
	return 1;
    }

    return 0;
}
