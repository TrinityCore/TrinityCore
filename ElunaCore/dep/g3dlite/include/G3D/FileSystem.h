/**
 @file FileSystem.h
 
 @author Morgan McGuire, http://graphics.cs.williams.edu
 
 @author  2002-06-06
 @edited  2010-02-05
 */
#ifndef G3D_FileSystem_h
#define G3D_FileSystem_h

#include "G3D/platform.h"
#include "G3D/Array.h"
#include "G3D/Table.h"

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

 The extension requirement allows G3D to quickly identify whether a path could enter a
 zipfile without forcing it to open all parent directories for reading.

 \sa FilePath
 TODO: make threadsafe!
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
#           ifdef G3D_WIN32
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
    Array<std::string>          m_winDrive;

    float                       m_cacheLifetime;

    enum Type {
        /** Not yet checked */
        UNKNOWN, 
        FILE_TYPE, 
        DIR_TYPE
    };

    class Entry {
    public: 
        /** Name, not including parent path */
        std::string             name;
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

        /** Case-independent comparison on Windows */
        bool contains(const std::string& child) const;

        /** Compute the contents of nodeArray from this zipfile. */
        void computeZipListing(const std::string& zipfile, const std::string& pathInsideZipfile);

        Dir() : exists(false), isZipfile(false), inZipfile(false), lastChecked(0) {}
    };

    /** Maps path names (without trailing slashes, except for the file system root) to contents.
        On Windows, all paths are lowercase */
    Table<std::string, Dir>     m_cache;

    /** Update the cache entry for path if it is not already present.
     \param forceUpdate If true, always override the current cache value.*/
    Dir& getContents(const std::string& path, bool forceUpdate);

    /** Don't allow public construction. */
    FileSystem();

    static FileSystem& instance();

#   ifdef G3D_WIN32
    /** On Windows, the drive letters that form the file system roots.*/
    const Array<std::string>& _drives();
#   endif 

    /** Returns true if some sub-path of \a path is a zipfile. 
        
       If the path itself is a zipfile, returns false.
       
       \param zipfile The part of \a path that was the zipfile */
    bool _inZipfile(const std::string& path, std::string& zipfile);

    /** Clears old cache entries so that exists() and list() will reflect recent changes to the file system.
       \param path Clear only \a path and its subdirectories ("" means clear the entire cache) */
    void _clearCache(const std::string& path);

    bool _inZipfile(const std::string& path) {
        std::string ignore;
        return inZipfile(path, ignore);
    }

    /** Set the cacheLifetime().
       \param t in seconds */
    void _setCacheLifetime(float t);


    /** A cache is used to optimize repeated calls.  A cache entry is considered
        valid for this many seconds after it has been checked. */
    float _cacheLifetime() const {
        return m_cacheLifetime;
    }

    /** Creates the directory named, including any subdirectories 
        that do not already exist.

        The directory must not be inside a zipfile.

        Flushes the cache.
     */
    void _createDirectory(const std::string& path);

    /** Returns true if a node named \a f exists.

        \param f If \a f contains wildcards, the function returns true if any file 
        matches those wildcards.  Wildcards may only appear in the base or ext, not the
        path.

        \param trustCache If true, uses the cache for optimizing repeated calls 
        in the same parent directory. 
     */
    bool _exists(const std::string& f, bool trustCache = true);

    /** Known bug: does not work inside zipfiles */
    bool _isDirectory(const std::string& path);
    
    /** Known bug: does not work inside zipfiles */
    bool _isFile(const std::string& path) {
        return ! isDirectory(path);
    }
    
    /**
    \param srcPath Must name a file.
    \param dstPath Must not contain a zipfile.

    Flushes the cache.
    */
    void _copyFile(const std::string& srcPath, const std::string& dstPath);

    /** Fully qualifies a filename.

        The filename may contain wildcards, in which case the wildcards will be preserved in the returned value.

        \param cwd The directory to treat as the "current" directory when resolving a relative path.  The default 
        value is the actual current directory.  (G3D::Any::sourceDirectory is a common alternative) 
    */
    std::string _resolve(const std::string& path, const std::string& cwd = currentDirectory());

    /** Returns true if \param dst does not exist or \param src is newer than \param dst,
       according to their time stamps.
       
       Known bug: does not work inside zipfiles.
       */
    bool _isNewer(const std::string& src, const std::string& dst);

    /** The current working directory (cwd).  Only ends in a slash if this is the root of the file system. */
    std::string _currentDirectory();

    /** Returns the length of the file in bytes, or -1 if the file could not be opened. */
    int64 _size(const std::string& path);

    /** Called from list() */
    void listHelper(const std::string& shortSpec, const std::string& parentPath, Array<std::string>& result, const ListSettings& settings);

    /** Appends all nodes matching \a spec to the \a result array.

      Wildcards can only appear to the right of the last slash in \a spec.

      The names will not contain parent paths unless \a includePath == true. 
      These may be relative to the current directory unless \a spec 
      is fully qualified (can be done with resolveFilename). 
      
     */
    void _list(const std::string& spec, Array<std::string>& result, const ListSettings& listSettings = ListSettings());

    /** Returns true if \a path is a file that is a zipfile. Note that G3D requires zipfiles to have
        some extension, although it is not required to be "zip" */
    bool _isZipfile(const std::string& path);

    /** list() files */
    void _getFiles(const std::string& spec, Array<std::string>& result, bool includeParentPath = false) {
        ListSettings set;
        set.includeParentPath = includeParentPath;
        set.directories = false;
        set.files = true;
        return list(spec, result, set);
    }

    /** list() directories */
    void _getDirectories(const std::string& spec, Array<std::string>& result, bool includeParentPath = false) {
        ListSettings set;
        set.includeParentPath = includeParentPath;
        set.directories = true;
        set.files = false;
        return list(spec, result, set);
    }

    /** Same as the C standard library fopen, but updates the file cache
    to acknowledge the new file on a write operation. */
    FILE* _fopen(const char* filename, const char* mode);

public:


    /** Create the common instance. */
    static void init();

    /** Destroy the common instance. */
    static void cleanup();

#   ifdef G3D_WIN32
    /** \copydoc _drives */
    static const Array<std::string>& drives() {
        return instance()._drives();
    }
#   endif

    /** \copydoc _inZipfile */
    static bool inZipfile(const std::string& path, std::string& zipfile) {
        return instance()._inZipfile(path, zipfile);
    }

    /** \copydoc _clearCache */
    static void clearCache(const std::string& path = "") {
        instance()._clearCache(path);
    }

    /** \copydoc _fopen */
    static FILE* fopen(const char* filename, const char* mode) {
        return instance()._fopen(filename, mode);
    }

    static void fclose(FILE* f) {
        ::fclose(f);
    }

    static bool inZipfile(const std::string& path) {
        return instance()._inZipfile(path);
    }

    /** \copydoc isZipfile */
    static bool isZipfile(const std::string& path) {
        return instance()._isZipfile(path);
    }

    /** \copydoc _setCacheLifetime */
    void setCacheLifetime(float t) {
        instance()._setCacheLifetime(t);
    }

    /** \copydoc _cacheLifetime */
    static float cacheLifetime() {
        return instance()._cacheLifetime();
    }

    /** \copydoc _createDirectory */
    static void createDirectory(const std::string& path) {
        instance()._createDirectory(path);
    }

    /** \copydoc _currentDirectory */
    static std::string currentDirectory() {
        return instance()._currentDirectory();
    }

    /** \copydoc _copyFile */
    static void copyFile(const std::string& srcPath, const std::string& dstPath) {
        instance()._copyFile(srcPath, dstPath);
    }

    /** \copydoc _exists */
    static bool exists(const std::string& f, bool trustCache = true) {
        return instance()._exists(f, trustCache);
    }

    /** \copydoc _isDirectory */
    static bool isDirectory(const std::string& path) {
        return instance()._isDirectory(path);
    }

    /** \copydoc _isFile */
    static bool isFile(const std::string& path) {
        return instance()._isFile(path);
    }

    /** \copydoc _resolve */
    static std::string resolve(const std::string& path, const std::string& cwd = currentDirectory()) {
        return instance()._resolve(path, cwd);
    }

    /** \copydoc _isNewer */
    static bool isNewer(const std::string& src, const std::string& dst) {
        return instance()._isNewer(src, dst);
    }

    /** \copydoc _size */
    static int64 size(const std::string& path) {
        return instance()._size(path);
    }

    /** \copydoc _list */
    static void list(const std::string& spec, Array<std::string>& result,
        const ListSettings& listSettings = ListSettings()) {
        return instance()._list(spec, result, listSettings);
    }

    /** \copydoc _getFiles */
    static void getFiles(const std::string& spec, Array<std::string>& result, bool includeParentPath = false) {
        return instance()._getFiles(spec, result, includeParentPath);
    }

    /** \copydoc getDirectories */
    static void getDirectories(const std::string& spec, Array<std::string>& result, bool includeParentPath = false) {
        return instance()._getDirectories(spec, result, includeParentPath);
    }
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
    static std::string concat(const std::string& a, const std::string& b);

    static bool isRoot(const std::string& f);

    /** Removes the trailing slash unless \a f is a filesystem root */
    static std::string removeTrailingSlash(const std::string& f);

    /** Returns everything to the right of the last '.' */
    static std::string ext(const std::string& path);

    /** Returns everything to the right of the last slash (or, on Windows, the last ':') */
    static std::string baseExt(const std::string& path);

    /** Returns everything between the right-most slash and the following '.' */
    static std::string base(const std::string& path);

    /** Returns everything to the left of the right-most slash */
    static std::string parent(const std::string& path);

    /** Returns true if '*' or '?' appear in the filename */
    static bool containsWildcards(const std::string& p);

    /** Convert all slashes to '/' */
    static std::string canonicalize(std::string x);

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
    (const std::string&  filename,
     std::string&        drive,    
     Array<std::string>& path,
     std::string&        base,
     std::string&        ext);


    /**
      Returns true if \a path matches \a pattern, with standard filesystem wildcards.
     */
    static bool matches(const std::string& path, const std::string& pattern, bool caseSensitive = true);
};

} // namespace G3D
#endif

