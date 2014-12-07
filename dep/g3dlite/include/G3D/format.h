/**
 @file format.h
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @author  2000-09-09
 @edited  2005-11-03

 Copyright 2000-2005, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_format_h
#define G3D_format_h

#include "G3D/platform.h"
#include "G3D/G3DString.h"
#include <stdio.h>
#include <cstdarg>

namespace G3D {

/**
  Produces a string from arguments of the style of printf.  This avoids
  problems with buffer overflows when using sprintf and makes it easy
  to use the result functionally.  This function is fast when the resulting
  string is under 160 characters (not including terminator) and slower
  when the string is longer.
 */
String   __cdecl format(
    const char*                 fmt
    ...) G3D_CHECK_PRINTF_ARGS;

/**
  Like format, but can be called with the argument list from a ... function.
 */
String vformat(
    const char*                 fmt,
    va_list                     argPtr) G3D_CHECK_VPRINTF_ARGS;


} // namespace

#endif
