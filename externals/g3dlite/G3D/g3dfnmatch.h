/*-
 * Copyright (c) 1992, 1993
 *The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *This product includes software developed by the University of
 *California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *@(#)fnmatch.h8.1 (Berkeley) 6/2/93
 *
 * From FreeBSD fnmatch.h 1.7
 * $Id: g3dfnmatch.h,v 1.1 2010/02/06 06:51:28 morgan3d Exp $
 */
#ifndef G3D_g3dfnmatch_h
#define G3D_g3dfnmatch_h

#include "G3D/platform.h"

namespace G3D {

#if defined(G3D_WIN32) 

#   if ! defined(FNM_NOMATCH)
#       define FNM_NOMATCH        1      /* Match failed. */
#       define FNM_NOESCAPE    0x01      /* Disable backslash escaping. */
#       define FNM_PATHNAME    0x02      /* Slash must be matched by slash. */
#       define FNM_PERIOD      0x04      /* Period must be matched by period. */
#       define FNM_LEADING_DIR 0x08      /* Ignore /<tail> after Imatch. */
#       define FNM_CASEFOLD    0x10      /* Case insensitive search. */
#       define FNM_PREFIX_DIRS 0x20      /* Directory prefixes of pattern match too. */
#    endif

#else 

    // On non-windows systems, include fnmatch directly
#   include <fnmatch.h>
#endif


/**
  Function fnmatch() as specified in POSIX 1003.2-1992, section B.6.
  Compares a filename or pathname to a pattern.

The fnmatch() function checks whether the string argument matches the pattern argument, which is a shell wildcard pattern.
The flags argument modifies the behaviour; it is the bitwise OR of zero or more of the following flags:

- FNM_NOESCAPE If this flag is set, treat backslash as an ordinary character, instead of an escape character.
- FNM_PATHNAME If this flag is set, match a slash in string only with a slash in pattern and not by an asterisk (*) or a question mark (?) metacharacter, nor by a bracket expression ([]) containing a slash.
- FNM_PERIOD If this flag is set, a leading period in string has to be matched exactly by a period in pattern. A period is considered to be leading if it is the first character in string, or if both FNM_PATHNAME is set and the period immediately follows a slash.
- FNM_FILE_NAME This is a GNU synonym for FNM_PATHNAME.
- FNM_LEADING_DIR If this flag (a GNU extension) is set, the pattern is considered to be matched if it matches an initial segment of string which is followed by a slash. This flag is mainly for the internal use of glibc and is only implemented in certain cases.
- FNM_CASEFOLD If this flag (a GNU extension) is set, the pattern is matched case-insensitively.

\return Zero if \a string matches \a pattern, FNM_NOMATCH if there is no match or another non-zero value if there is an error

 */
int g3dfnmatch(const char *pattern, const char *string, int flags);
}
#endif
