/**
 @file fileutils.h
 
 @maintainer Morgan McGuire, http://graphics.cs.williams.edu
 
 @author  2002-06-06
 @edited  2010-03-06

 Copyright 2000-2010, Morgan McGuire.
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

#ifdef G3D_WIN32
// For chdir, mkdir, etc.
#   include <direct.h>
#endif

namespace G3D {

    namespace _internal {
        extern Set<std::string> currentFilesUsed;
    }

/** Returns all the files used by G3D and GLG3D during the current execution. */
Array<std::string> filesUsed();
    
std::string readWholeFile(
    const std::string&          filename);


/** Reads from a zip file and decompresses the desired contents
	into memory.  Does not support recursive zip calls (i.e. a .zip
	stored within another .zip)

	@param file the path, of the format C:\\...\\something.zip\\...\\desiredfile.ext
	@param data a pointer to the memory where the file will be stored
	@param length the size of the file decompressed to memory */
void zipRead(const std::string& file,
			 void*& data,
			 size_t& length);


/** Closes the contents of a zip file that had been decompressed to
	memory.  Must be called in tandem with zipRead() to avoid memory
	leaks.

	@param data the pointer to the decompressed file in memory */
void zipClose(void* data);


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
 std::string&		     outZipfile,
 std::string&		     outInternalFile);

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

