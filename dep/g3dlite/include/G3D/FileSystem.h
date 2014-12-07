/**
 \file FileSystem.h
 
 \author Morgan McGuire, http://graphics.cs.williams.edu
 
 \author  2002-06-06
 \edited  2014-07-09
 */
#ifndef G3D_FileSystem_h
#define G3D_FileSystem_h

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/Table.h"
#include "G3D/Set.h"
#include "G3D/GMutex.h"

namespace G3D {

/** 
 OS-independent file system layer that optimizes the performance
 of queries by caching and prefetching.

 This class uses the following definitions:
 <ul>
   <li> "file" = document that can be opened for reading or writing
   <li> "directory" = folder containing files and other directories
   <li> "node" = file or directory
   <li> "path" = string identifying a (see the FSPath class)
   <li> "zipfile" = a compressed file storing an archive of files and directories in the zip format
 </ul>

 In G3D, Zipfiles are transparently treated as if they were directories, provided:
 <ul>
   <li> The zipfile name contains an extension (e.g., map.pk3, files.zip)
   <li> There are no nested zipfiles
 </ul>

 All FileSystem routines invoke FilePath::expandEnvironmentVariables if the input contains a '$'.

 The extension requirement allows G3D to quickly identify whether a path could enter a
 zipfile without forcing it to open all parent directories for reading.

 \sa FilePath
*/
class FileSystem {
public:

    class ListSettings {
    public:
        /** Defaults to true */
        bool    files;

        /** Defaults to true */
        bool    directories;

        /** Defaults to true on Windows, false on other platforms.*/
        bool    caseSensitive;

        /** Can get recurse into subdirectories? Defaults to true. */
        bool    recursive;

        /** Prefix the full path onto names that are returned. Defaults to true */
        bool    includeParentPath;

        ListSettings() :
            files(true),
            directories(true),
#           ifdef G3D_WINDOWS
                caseSensitive(true),
#           else
              caseSensitive(false),
#           endif
            recursive(false),
            includeParentPath(true) {}
    };

private:

    /** Drive letters.  Only used on windows, but defined on all platforms to help
       avoid breaking the Windows build when compiling on another platform. */
    Array<String>          m_winDrive;

    float                  m_cacheLifetime;

    enum Type {
        /** Not yet checked */
        UNKNOWN, 
        FILE_TYPE, 
        DIR_TYPE
    };

    class Entry {
    public: 
        /** Name, not including parent path */
        String             name;
        Type                    type;
        Entry() : type(UNKNOWN) {}
        Entry(const char* n) : name(n), type(UNKNOWN) {}
    };

    class Dir {
    public:
        
        /** If false, this path did not exist (even inside a zipfile) when last checked, or it is not a directory. */
        bool                    exists;

        bool                    isZipfile;
        bool                    inZipfile;

        /** Files and directories */
        Array<Entry>            nodeArray;
        
        /** When this entry was last updated */
        double                  lastChecked;

        bool contains(const String& child, bool caseSensitive =
#ifdef G3D_WINDOWS
            false
#else
            true
#endif
) const;

        /** Compute the contents of nodeArray from this zipfile. */
        void computeZipListing(const String& zipfile, const String& pathInsideZipfile);

        Dir() : exists(false), isZipfile(false), inZipfile(false), lastChecked(0) {}
    };

    /** Maps path names (without trailing slashes, except for the file system root) to contents.
        On Windows, all paths are lowercase */
    Table<String, Dir>     m_cache;

    /** Update the cache entry for path if it is not already present.
     \param forceUpdate If true, always override the current cache value.*/
    Dir& getContents(const String& path, bool forceUpdate);

    /** Don't allow public construction. */
    FileSystem();

    static FileSystem& instance();
    static GMutex      mutex;


#   ifdef G3D_WINDOWS
    /** \copydoc drives */
    const Array<String>& _drives();
#   endif 

    /** \copydoc inZipfile */
    bool _inZipfile(const String& path, String& zipfile);

    /** \copydoc clearCache */
    void _clearCache(const String& path);

	/** \copydoc inZipfile */
    bool _inZipfile(const String& path) {
        String ignore;
        return inZipfile(path, ignore);
    }

    /** \copydoc setCacheLifetime */
    void _setCacheLifetime(float t);


    /** \copydoc cacheLifetime */
    float _cacheLifetime() const {
        return m_cacheLifetime;
    }

    /** \copydoc createDirectory */
    void _createDirectory(const String& path);

    /** \copydoc exists */
    bool _exists(const String& f, bool trustCache = true, bool caseSensitive = 
#       ifdef G3D_WINDOWS
                 false
#       else
                 true
#       endif
       );

    /** \copydoc isDirectory */
    bool _isDirectory(const String& path, bool expandEnvironmentVariables);
    
    /** \copydoc isFile */
    bool _isFile(const String& path) {
        return ! isDirectory(path);
    }
    
	/** \copydoc copyFile */
    void _copyFile(const String& srcPath, const String& dstPath);

    /** \copydoc resolve */
    String _resolve(const String& path, const String& cwd = currentDirectory());

    /** \copydoc isNewer */
    bool _isNewer(const String& src, const String& dst);

    /** \copydoc currentDirectory */
    String _currentDirectory();

    /** \copydoc size */
    int64 _size(const String& path);

    /** Called from list() */
    void listHelper(const String& shortSpec, const String& parentPath, Array<String>& result, const ListSettings& settings);

    /** \copydoc list */
    void _list(const String& spec, Array<String>& result, const ListSettings& listSettings = ListSettings());

    /** \copydoc isZipfile */
    bool _isZipfile(const String& path);

    /** \copydoc getFiles */
    void _getFiles(const String& spec, Array<String>& result, bool includeParentPath = false) {
        ListSettings set;
        set.includeParentPath = includeParentPath;
        set.directories = false;
        set.files = true;
        return list(spec, result, set);
    }

    /** \copydoc getDirectories */
    void _getDirectories(const String& spec, Array<String>& result, bool includeParentPath = false) {
        ListSettings set;
        set.includeParentPath = includeParentPath;
        set.directories = true;
        set.files = false;
        return list(spec, result, set);
    }

    /** \copydoc fopen */
    FILE* _fopen(const char* filename, const char* mode);

    /** \copydoc removeFile */
    void _removeFile(const String& path);

    int _rename(const String& src, const String& dst);

public:

    /** Create the common instance. */
    static void init();

    /** Destroy the common instance. */
    static void cleanup();

#   ifdef G3D_WINDOWS
    /** On Windows, the drive letters that form the file system roots.*/
    static const Array<String>& drives() {
        mutex.lock();
        const Array<String>& s = instance()._drives();
        mutex.unlock();
        return s;
    }
#   endif

    /** Returns true if some sub-path of \a path is a zipfile. 
        
       If the path itself is a zipfile, returns false.
       
       \param zipfile The part of \a path that was the zipfile
	   */
    static bool inZipfile(const String& path, String& zipfile) {
        mutex.lock();
        bool b = instance()._inZipfile(path, zipfile);
        mutex.unlock();
        return b;
    }

	/** Clears old cache entries so that exists() and list() will reflect recent changes to the file system.
       \param path Clear only \a path and its subdirectories ("" means clear the entire cache) */
    static void clearCache(const String& path = "") {
        mutex.lock();
        instance()._clearCache(path);
        mutex.unlock();
    }

    
	/** Same as the C standard library fopen, but updates the file cache
    to acknowledge the new file on a write operation. */
    static FILE* fopen(const char* filename, const char* mode) {
        mutex.lock();
        FILE* f = instance()._fopen(filename, mode);
        mutex.unlock();
        return f;
    }


    static void fclose(FILE* f) {
        mutex.lock();
        ::fclose(f);
        mutex.unlock();
    }

    /** Returns true if some sub-path of \a path is a zipfile. 
        
       If the path itself is a zipfile, returns false.
      */
    static bool inZipfile(const String& path) {
        mutex.lock();
        bool b = instance()._inZipfile(path);
        mutex.unlock();
        return b;
    }

    
	/**
       \brief Delete this file. 
        No effect if \a path does not exist.

        \param path May contain wildcards.  May not be inside a zipfile.
     */
    static void removeFile(const String& path) {
        mutex.lock();
        instance()._removeFile(path);
        mutex.unlock();
    }

    
	/** Returns true if \a path is a file that is a zipfile. Note that G3D requires zipfiles to have
        some extension, although it is not required to be "zip" */
    static bool isZipfile(const String& path) {
        mutex.lock();
        bool b = instance()._isZipfile(path);
        mutex.unlock();
        return b;
    }

   
	/** Set the cacheLifetime().
       \param t in seconds */
    void setCacheLifetime(float t) {
        mutex.lock();
        instance()._setCacheLifetime(t);
        mutex.unlock();
    }

	/** A cache is used to optimize repeated calls.  A cache entry is considered
        valid for this many seconds after it has been checked. */
    static float cacheLifetime() {
        mutex.lock();
        float f = instance()._cacheLifetime();
        mutex.unlock();
        return f;
    }

    
	/** Creates the directory named, including any subdirectories 
        that do not already exist.

        The directory must not be inside a zipfile.

        Flushes the cache.
     */
    static void createDirectory(const String& path) {
        mutex.lock();
        instance()._createDirectory(path);
        mutex.unlock();
    }

    
	/** The current working directory (cwd).  Only ends in a slash if this is the root of the file system. */
    static String currentDirectory() {
        mutex.lock();
        const String& s = instance()._currentDirectory();
        mutex.unlock();
        return s;
    }


    static int rename(const String& src, const String& dst) {
        mutex.lock();
        const int i = instance()._rename(src, dst);
        mutex.unlock();
        return i;
    }
    
	/**
    \param srcPath Must name a file.
    \param dstPath Must not contain a zipfile.

    Flushes the cache.
    */
    static void copyFile(const String& srcPath, const String& dstPath) {
        mutex.lock();
        instance()._copyFile(srcPath, dstPath);
        mutex.unlock();
    }

    

	/** Returns true if a node named \a f exists.

        \param f If \a f contains wildcards, the function returns true if any file 
        matches those wildcards.  Wildcards may only appear in the base or ext, not the
        path.  Environment variables beginning with dollar signs (e.g., in "$G3DDATA/cubemap"),
         with optional parens ("$(G3DDATA)") are
        automatically expanded in \a f. Default share names on Windows (e.g., "\\mycomputer\c$")
        are correctly distinguished from empty environment variables.

        \param trustCache If true, uses the cache for optimizing repeated calls 
        in the same parent directory. 

        \param caseSensitive If true, the match must have exactly the same case for the base and extension.  If false,
        case is ignored.  The default on Windows is false and the default on other operating systems is true.
     */
    static bool exists(const String& f, bool trustCache = true, bool caseSensitive = 
#ifdef G3D_WINDOWS
        false
#else
        true
#endif
        ) {
        mutex.lock();
        bool e = instance()._exists(f, trustCache, caseSensitive);
        mutex.unlock();
        return e;
    }

    
    /** Known bug: does not work inside zipfiles */
    static bool isDirectory(const String& path, bool expandEnvironmentVariablesInPath = true) {
        mutex.lock();
        bool b = instance()._isDirectory(path, expandEnvironmentVariablesInPath);
        mutex.unlock();
        return b;
    }

    
	/** Known bug: does not work inside zipfiles */
    static bool isFile(const String& path) {
        mutex.lock();
        bool b = instance()._isFile(path);
        mutex.unlock();
        return b;
    }

    
	/** Fully qualifies a filename.

        The filename may contain wildcards, in which case the wildcards will be preserved in the returned value.

        \param cwd The directory to treat as the "current" directory when resolving a relative path.  The default 
        value is the actual current directory.  (G3D::Any::sourceDirectory is a common alternative) 
    */
    static String resolve(const String& path, const String& cwd = currentDirectory()) {
        mutex.lock();
        const String& s = instance()._resolve(path, cwd);
        mutex.unlock();
        return s;
    }

    
	/** Returns true if \a dst does not exist or \a src is newer than \a dst,
        according to their time stamps.
       
        Known bug: does not work inside zipfiles.
    */
    static bool isNewer(const String& src, const String& dst) {
        mutex.lock();
        bool b = instance()._isNewer(src, dst);
        mutex.unlock();
        return b;
    }

    
	/** Returns the length of the file in bytes, or -1 if the file could not be opened. */
    static int64 size(const String& path) {
        mutex.lock();
        int64 i = instance()._size(path);
        mutex.unlock();
        return i;
    }

    
	/** Appends all nodes matching \a spec to the \a result array.

      Wildcards can only appear to the right of the last slash in \a spec.

      The names will not contain parent paths unless \a includePath == true. 
      These may be relative to the current directory unless \a spec 
      is fully qualified (can be done with resolveFilename). 
      
     */
    static void list(const String& spec, Array<String>& result,
        const ListSettings& listSettings = ListSettings()) {
        mutex.lock();
        instance()._list(spec, result, listSettings);
        mutex.unlock();
    }

    
	/** list() files */
    static void getFiles(const String& spec, Array<String>& result, bool includeParentPath = false) {
        mutex.lock();
        instance()._getFiles(spec, result, includeParentPath);
        mutex.unlock();
    }

    
	/** list() directories */
    static void getDirectories(const String& spec, Array<String>& result, bool includeParentPath = false) {
        mutex.lock();
        instance()._getDirectories(spec, result, includeParentPath);
        mutex.unlock();
    }

    /** Adds \a filename to usedFiles().  This is called automatically by open() and all 
      G3D routines that open files. */
    static void markFileUsed(const String& filename);

    /** All files that have been marked by markFileUsed().  GApp automatically prints this list to log.txt.  It is useful
        for finding the dependencies of your program automatically.*/
    static const Set<String>& usedFiles();
};


/** \brief Parsing of file system paths.  

    None of these routines touch the disk--they are purely string manipulation.

    In "/a/b/base.ext",

    <ul>
      <li> base = "base"
      <li> ext = "ext"
      <li> parentPath = "/a/b"
      <li> baseExt = "base.ext"
    </ul>

*/
class FilePath {
public:

    /** Appends file onto dirname, ensuring a / if needed. */
    static String concat(const String& a, const String& b);

    /** Returns true if \a f specifies a path that parses as root of the filesystem.
        On OS X and other Unix-based operating systems, "/" is the only root.
        On Windows, drive letters and shares are roots, e.g., "c:\", "\\foo\".
        Does not check on Windows to see if the root is actually mounted or a legal
        drive letter--this is a purely string based test. */
    static bool isRoot(const String& f);

    /** Removes the trailing slash unless \a f is a filesystem root */
    static String removeTrailingSlash(const String& f);

    /** Returns everything to the right of the last '.' */
    static String ext(const String& path);

    /** Returns everything to the right of the last slash (or, on Windows, the last ':') */
    static String baseExt(const String& path);

    /** Returns everything between the right-most slash and the following '.' */
    static String base(const String& path);

    /** Returns everything to the left of the right-most slash */
    static String parent(const String& path);

    /** Returns true if '*' or '?' appear in the filename */
    static bool containsWildcards(const String& p);

    /** Convert all slashes to '/' */
    static String canonicalize(String x);

    /** \brief Replaces <code>$VAR</code> and <code>$(VAR)</code> patterns with the corresponding environment variable.
        Throws String if the environment variable is not defined.
     */
    static String expandEnvironmentVariables(const String& path);

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
    static void parse
    (const String&  filename,
     String&        drive,    
     Array<String>& path,
     String&        base,
     String&        ext);

    /**
      Returns true if \a path matches \a pattern, with standard filesystem wildcards.
     */
    static bool matches(const String& path, const String& pattern, bool caseSensitive = true);

    /** Replaces characters that are illegal in a filename with legal equivalents.*/
    static String makeLegalFilename(const String& f, size_t maxLength = 100000);
};

} // namespace G3D
#endif

