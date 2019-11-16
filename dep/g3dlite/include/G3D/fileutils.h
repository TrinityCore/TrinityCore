/**
 @file fileutils.h
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @author  2002-06-06
 @edited  2011-03-06

 Copyright 2000-2015, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_fileutils_h
#define G3D_fileutils_h

#include "G3D/platform.h"
#include "G3D/G3DString.h"
#include <stdio.h>
#include "G3D/Array.h"
#include "G3D/Set.h"
#include "G3D/g3dmath.h"

#ifdef G3D_WINDOWS
// For chdir, mkdir, etc.
#   include <direct.h>
#endif

namespace G3D {
 
/** Returns the contents of a text file as a single string */
String readWholeFile
(const String&          filename);


/**
 @param flush If true (default), the file is ready for reading as soon
 as the function returns.  If false, the function returns immediately and
 writes the file in the background.
 */
void writeWholeFile(
    const String& filename, 
    const String& str, 
    bool    flush = true);


/** Returns a temporary file that is open for read/write access.  This
    tries harder than the ANSI tmpfile, so it may succeed when that fails. */
FILE* createTempFile();


/**
 Returns true if the given file (or directory) exists
 within a zipfile.  Called if fileExists initially
 returns false and the lookInZipfiles flag has been set.
 Must not end in a trailing slash.  Does not work for recursive
 zipfiles (.zips within another .zip)

 @param filename the path to test
 @param outZipfile the path to the .zip file
 @param outInternalFile the path (within the .zip) where the desired file is located, if valid

 */
bool zipfileExists
(const String&          filename,
 String&             outZipfile,
 String&             outInternalFile);

bool zipfileExists(const String& filename);

/**
  Parses a filename into four useful pieces.

  Examples:

  c:\\a\\b\\d.e   
    root  = "c:\\"
    path  = "a" "b"
    base  = "d"
    ext   = "e"
 
  /a/b/d.e
    root = "/"
    path  = "a" "b"
    base  = "d"
    ext   = "e"

  /a/b
    root  = "/"
    path  = "a"
    base  = "b"
    ext   = "e"

 */
void parseFilename(
    const String&  filename,
    String&        drive,    
    Array<String>& path,
    String&        base,
    String&        ext);


/**
 Returns the part of the filename that includes the base and ext from
 parseFilename (i.e. everything to the right of the path).
 */
String filenameBaseExt(const String& filename);

/**
 Returns the extension on a filename.
 */
String filenameExt(const String& filename);


/** Returns the portion of a filename to the left of the last period
    and to the right of the last slash or colon.
 */
String filenameBase(const String& filename);

/** Creates a unique filename base in the current directory using the
    specified prefix and suffix.*/
String generateFilenameBase(const String& prefix = "", const String& suffix = "");

/** Creates a unique filename base in the current directory using the specified prefix, though
    any suffix is possible */
String generateFileNameBaseAnySuffix(const String& prefix);

/** 
 Returns the drive (if Win32) and path from a filename, including 
 a slash if there was one.
 <CODE>filenamePath(f) + filenameBaseExt(f) == f</CODE>
 */
String filenamePath(const String& filename);

/** Returns true if '*' or '?' appears in the string */
bool filenameContainsWildcards(const String& filename);

/** Appends file onto dirname, ensuring a / if needed. \deprecated Use FilePath::concat */
String pathConcat(const String& dirname, const String& file);

} // namespace

#endif

