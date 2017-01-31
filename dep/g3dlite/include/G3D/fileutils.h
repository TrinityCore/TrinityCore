/**
 @file fileutils.h
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @author  2002-06-06
 @edited  2011-03-06

 Copyright 2000-2012, Morgan McGuire.
 All rights reserved.
 */

#ifndef G3D_fileutils_h
#define G3D_fileutils_h

#include "G3D/platform.h"
#include <string>
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
std::string readWholeFile
(const std::string&          filename);


/**
 @param flush If true (default), the file is ready for reading as soon
 as the function returns.  If false, the function returns immediately and
 writes the file in the background.
 */
void writeWholeFile(
    const std::string& filename, 
    const std::string& str, 
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
(const std::string&          filename,
 std::string&             outZipfile,
 std::string&             outInternalFile);

bool zipfileExists(const std::string& filename);

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
    const std::string&  filename,
    std::string&        drive,    
    Array<std::string>& path,
    std::string&        base,
    std::string&        ext);


/**
 Returns the part of the filename that includes the base and ext from
 parseFilename (i.e. everything to the right of the path).
 */
std::string filenameBaseExt(const std::string& filename);

/**
 Returns the extension on a filename.
 */
std::string filenameExt(const std::string& filename);


/** Returns the portion of a filename to the left of the last period
    and to the right of the last slash or colon.
 */
std::string filenameBase(const std::string& filename);

/** Creates a unique filename base in the current directory using the
    specified prefix and suffix.*/
std::string generateFilenameBase(const std::string& prefix = "", const std::string& suffix = "");

/** 
 Returns the drive (if Win32) and path from a filename, including 
 a slash if there was one.
 <CODE>filenamePath(f) + filenameBaseExt(f) == f</CODE>
 */
std::string filenamePath(const std::string& filename);

/** Returns true if '*' or '?' appears in the string */
bool filenameContainsWildcards(const std::string& filename);

/** Appends file onto dirname, ensuring a / if needed. \deprecated Use FilePath::concat */
std::string pathConcat(const std::string& dirname, const std::string& file);

} // namespace

#endif

