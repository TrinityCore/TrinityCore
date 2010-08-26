/*
  $NiH: open.c,v 1.6 2005/07/16 17:14:32 wiz Exp $

  open.c -- test cases for opening zip archives
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

#include "zip.h"

int open_fail(const char *, int, const char *, int, int);
int open_success(const char *, int, const char *, int);

const char *prg;


int
main(int argc, char *argv[])
{
    int fail;
    const char *archive;
    const char *nonarchive;

    fail = 0;
    prg = argv[0];

    if (argc != 3) {
        fprintf(stderr, "usage: %s archive non-archive\n", prg);
        return 1;
    }

    archive = argv[1];
    nonarchive = argv[2];

    remove("nosuchfile");
    fail += open_fail("nosuchfile", 0, "non-existing", ZIP_ER_OPEN, ENOENT);
    fail += open_fail(nonarchive, 0, "non-zip", ZIP_ER_NOZIP, 0);
    fail += open_fail(archive, ZIP_EXCL, "existing-excl", ZIP_ER_EXISTS, 0);
    /* ZIP_ER_OPEN */
    /* ZIP_ER_READ */
    /* ZIP_ER_SEEK */
    /* ZIP_ER_INCONS */

    fail += open_success(archive, 0, "existing", 3);
    fail += open_success("nosuchfile", ZIP_CREATE, "new", 0);

    exit(fail ? 1 : 0);
}



int
open_fail(const char *fname, int flags, const char *desc, int zerr, int serr)
{
    struct zip *z;
    int ze;

    errno = 0;

    if ((z=zip_open(fname, flags, &ze)) != NULL) {
	printf("%s: opening `%s' succeeded, though it shouldn't\n", prg, desc);
	zip_close(z);
	return 1;
    }
    else if (ze != zerr
	     || (zip_error_get_sys_type(ze) == ZIP_ET_SYS && errno != serr)) {
	printf("%s: opening `%s' returned wrong error %d/%d, expected %d/%d\n",
		prg, desc, ze, errno, zerr, serr);
	return 1;
    }

    return 0;
}



int
open_success(const char *fname, int flags, const char *desc, int nent)
{
    struct zip *z;
    int ze, num;

    if ((z=zip_open(fname, flags, &ze)) == NULL) {
	printf("%s: opening `%s' failed (%d)\n", prg, desc, ze);
	return 1;
    }

    num = zip_get_num_files(z);
    if (zip_close(z) == -1) {
	printf("%s: closing `%s' failed\n", prg, desc);
	return 1;
    }
    
    if (num != nent) {
	printf("%s: opening `%s' got wrong number of files %d, expected %d\n",
		prg, desc, num, nent);
	return 1;
    }

    return 0;
}
