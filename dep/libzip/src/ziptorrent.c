/*
  zipcmp.c -- compare zip files
  Copyright (C) 2008 Dieter Baron and Thomas Klausner

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
#include <unistd.h>
#include <zlib.h>

#include "config.h"
#include "zip.h"



#define FLAG_DRYRUN	1
#define FLAG_VERBOSE	2

const char *prg;

#define PROGRAM	"ziptorrent"

char *usage = "usage: %s [-hnVv] zip [...]\n";

char help_head[] =
    PROGRAM " (" PACKAGE ") by Dieter Baron and Thomas Klausner\n\n";

char help[] = "\n\
  -h       display this help message\n\
  -n       don't actually change archives, just print what would be done\n\
  -V       display version number\n\
  -v       verbose\n\
\n\
Report bugs to <libzip@nih.at>.\n";

char version_string[] = PROGRAM " (" PACKAGE " " VERSION ")\n\
Copyright (C) 2008 Dieter Baron and Thomas Klausner\n\
" PACKAGE " comes with ABSOLUTELY NO WARRANTY, to the extent permitted by law.\n";

#define OPTIONS "hnVv"

static int torrentzip(const char *, int);



int
main(int argc, char * const argv[])
{
    int err;
    int c;
    int flags;

    prg = argv[0];
    flags = 0;

    while ((c=getopt(argc, argv, OPTIONS)) != -1) {
	switch (c) {
	case 'h':
	    fputs(help_head, stdout);
	    printf(usage, prg);
	    fputs(help, stdout);
	    exit(0);
	case 'n':
	    flags |= FLAG_DRYRUN|FLAG_VERBOSE;
	    break;
	case 'V':
	    fputs(version_string, stdout);
	    exit(0);
	case 'v':
	    flags |= FLAG_VERBOSE;
	    break;

	default:
	    fprintf(stderr, usage, prg);
	    exit(2);
	}
    }

    if (argc == optind) {
	fprintf(stderr, usage, prg);
	exit(2);
    }

    err = 0;
    while (optind < argc) {
	err |= torrentzip(argv[optind++], flags);
    }

    return (err ? 1 : 0);
}



static int
torrentzip(const char *fname, int flags)
{
    struct zip *za;
    int err;
    char errstr[1024];

    if ((za=zip_open(fname, 0, &err)) == NULL) {
	zip_error_to_str(errstr, sizeof(errstr), err, errno);
	fprintf(stderr, "%s: cannot open zip archive `%s': %s\n",
		prg, fname, errstr);
	return -1;
    }

    if (flags & FLAG_VERBOSE) {
	if (zip_get_archive_flag(za, ZIP_AFL_TORRENT, 0))
	    printf("%s: already torrentzipped\n", fname);
	else
	    printf("%s: torrentzipping\n", fname);
    }

    if ((flags & FLAG_DRYRUN) == 0) {
        if (zip_set_archive_flag(za, ZIP_AFL_TORRENT, 1) < 0) {
	    fprintf(stderr,	"%s: cannot set torrentzip flag in `%s': %s\n",
		    prg, fname, zip_strerror(za));
	    zip_close(za);
	    return -1;
        }
    }

    if (zip_close(za) < 0) {
	fprintf(stderr,	"%s: cannot torrentzip `%s': %s\n",
		prg, fname, zip_strerror(za));
	zip_unchange_all(za);
	zip_close(za);
	return -1;
    }

    return 0;
}
