/**
 \file FileSystem.cpp
 
 \author Morgan McGuire, http://graphics.cs.williams.edu
 
 \author  2002-06-06
 \edited  2010-10-10
 */
#include "G3D/FileSystem.h"
#include "G3D/System.h"
#include "G3D/stringutils.h"
#include "G3D/fileutils.h"
#include <sys/stat.h>
#include <sys/types.h>
#if _HAVE_ZIP /* G3DFIX: Use ZIP-library only if defined */
    #include "zip.h"
#endif
#include "G3D/g3dfnmatch.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"

#ifdef G3D_WINDOWS
    // Needed for _getcwd
#   include <direct.h>

    // Needed for _findfirst
#   include <io.h>
#  ifdef __MINGW32__
#    define stat64 stat
#  else
#    define stat64 _stat64
#  endif
#else
#   include <dirent.h>
#   include <fnmatch.h>
#   include <unistd.h>
#   define _getcwd getcwd
#   if defined(__DragonFly__) || defined(__FreeBSD__) || defined(__NetBSD__) || defined(__OpenBSD__)
#     define stat64 stat
#   endif
#   define _stat stat
#   define stricmp strcasecmp 
#   define strnicmp strncasecmp 
#endif

namespace G3D {

static FileSystem* common = NULL;

GMutex FileSystem::mutex;

FileSystem& FileSystem::instance() {
    init();
    return *common;
}


void FileSystem::init() {
    if (common == NULL) {
        common = new FileSystem();
    }
}


void FileSystem::cleanup() {
    if (common != NULL) {
        delete common;
        common = NULL;
    }
}

FileSystem::FileSystem() : m_cacheLifetime(10) {}

/////////////////////////////////////////////////////////////

bool FileSystem::Dir::contains(const std::string& f, bool caseSensitive) const {
    
    for (int i = 0; i < nodeArray.size(); ++i) {
        if (caseSensitive) {
            if (f == nodeArray[i].name) {
                return true;
            }
        } else if (stricmp(f.c_str(), nodeArray[i].name.c_str()) == 0) {
            return true;
        }
    }
    return false;
}

    
void FileSystem::Dir::computeZipListing(const std::string& zipfile, const std::string& _pathInsideZipfile) {
#if _HAVE_ZIP /* G3DFIX: Use ZIP-library only if defined */
    const std::string& pathInsideZipfile = FilePath::canonicalize(_pathInsideZipfile);
    struct zip* z = zip_open( FilePath::removeTrailingSlash(zipfile).c_str(), ZIP_CHECKCONS, NULL );
    debugAssert(z);

    int count = zip_get_num_files( z );
    Set<std::string> alreadyAdded;
    for (int i = 0; i < count; ++i) {
        struct zip_stat info;
        zip_stat_init( &info );    // TODO: Docs unclear if zip_stat_init is required.
        zip_stat_index( z, i, ZIP_FL_NOCASE, &info );
        
        // Fully-qualified name of a file inside zipfile
        std::string name = FilePath::canonicalize(info.name);

        if (beginsWith(name, pathInsideZipfile)) {
            // We found something inside the directory we were looking for,
            // so the directory itself must exist
            exists = true;

            // For building the cached directory listing, extract only elements that do not contain 
            // additional subdirectories.

            size_t start = pathInsideZipfile.size();
            if ((name.length() > start) && isSlash(name[start])) {
                ++start;
            }

            size_t end = findSlash(name, start);
            if (end == std::string::npos) {
                // There are no more slashes; add this name
                name = name.substr(start);
                if (alreadyAdded.insert(name)) {
                    Entry& e = nodeArray.next();
                    e.name = name;
                    e.type = FILE_TYPE;
                }
            } else {
                // There are more slashes, indicating that this is a directory
                name = name.substr(start, end);
                if (alreadyAdded.insert(name)) {
                    Entry& e = nodeArray.next();                    
                    e.name = FilePath::removeTrailingSlash(name);
                    e.type = DIR_TYPE;
                }
            }
        }
    }
    
    zip_close(z);
    z = NULL;
#else
    (void)zipfile;
    (void)_pathInsideZipfile;
#endif
}


FileSystem::Dir& FileSystem::getContents(const std::string& path, bool forceUpdate) {
    const std::string& key = 
#   if defined(G3D_WINDOWS)
        FilePath::canonicalize(FilePath::removeTrailingSlash(toLower(FilePath::canonicalize(resolve(path)))));
#   else
        FilePath::canonicalize(FilePath::removeTrailingSlash(FilePath::canonicalize(resolve(path))));
#   endif
    
    RealTime now = System::time();
    Dir& dir = m_cache.getCreate(key);

    if ((now > dir.lastChecked + cacheLifetime()) || forceUpdate) {
        dir = Dir();

        // Out of date: update
        dir.lastChecked = now;
#       ifdef G3D_WINDOWS
            // On windows, we have to use GetFileAttributes (http://msdn.microsoft.com/en-us/library/aa364944(v=vs.85).aspx) instead of 
            // stat in order to work with network shares
            const DWORD st = GetFileAttributesA(key.c_str());
            const bool exists = (st != INVALID_FILE_ATTRIBUTES);
            const bool isDirectory = (st & FILE_ATTRIBUTE_DIRECTORY) != 0;
#       else
            struct _stat st;
            const bool exists = _stat(key.c_str(), &st) != -1;
            const bool isDirectory = (st.st_mode & S_IFDIR) != 0;
#       endif

        // Does this path exist on the real filesystem?
        if (exists && isDirectory) {

            // Is this path actually a directory?
            if (isDirectory) {
                dir.exists = true;
                // Update contents
#               ifdef G3D_WINDOWS
                    const std::string& filespec = FilePath::concat(key, "*");
                    struct _finddata_t fileinfo;
                    intptr_t handle = _findfirst(filespec.c_str(), &fileinfo);
                    debugAssert(handle != -1);
                    int result = 0;
                    do {
                        if ((strcmp(fileinfo.name, ".") != 0) && (strcmp(fileinfo.name, "..") != 0)) {
                            Entry& e = dir.nodeArray.next();
                            e.name = fileinfo.name;
                            if ((fileinfo.attrib & _A_SUBDIR) != 0) {
                                e.type = DIR_TYPE;
                            } else {
                                e.type = FILE_TYPE;
                            }
                        }

                        result = _findnext(handle, &fileinfo);
                    } while (result == 0);
                    _findclose(handle);

#               else
                    DIR* listing = opendir(key.c_str());
                    debugAssertM(listing, "opendir failed on '" + key + "'");
                    struct dirent* entry = readdir(listing);
                    while (entry != NULL) {
                        if ((strcmp(entry->d_name, "..") != 0) && (strcmp(entry->d_name, ".") != 0)) {
                            Entry& e = dir.nodeArray.next();
                            e.name = entry->d_name;

#                           ifdef _DIRENT_HAVE_D_TYPE
                                // Not all POSIX systems support this field
                                // http://www.delorie.com/gnu/docs/glibc/libc_270.html
                                switch (entry->d_type) {
                                case DT_DIR:
                                    e.type = DIR_TYPE;
                                    break;
                                    
                                case DT_REG:
                                    e.type = FILE_TYPE;
                                    break;
                                    
                                case DT_UNKNOWN:
                                default:
                                    e.type = UNKNOWN;
                                    break;
                                }
#                           endif
                        }
                        entry = readdir(listing);
                    }
                    closedir(listing);
                    listing = NULL;
                    entry = NULL;
#               endif
            }

        } else {
            std::string zip;

            if (exists && isZipfile(path)) {
                // This is a zipfile; get its root
                dir.isZipfile = true;                
                dir.computeZipListing(path, "");

            } else if (inZipfile(path, zip)) {

                // There is a zipfile somewhere in the path.  Does
                // the rest of the path exist inside the zipfile?
                dir.inZipfile = true;
                dir.computeZipListing(zip, path.substr(zip.length() + 1));
            }
        }        
    }

    return dir;
}


bool FileSystem::_inZipfile(const std::string& _path, std::string& z) {
    const std::string& path = FilePath::expandEnvironmentVariables(_path);

    // Reject trivial cases before parsing

    // Look at all sub-paths containing periods.
    // For each, ask if it is a zipfile.
    size_t current = 0;
    current = path.find('.', current);

    while (current != std::string::npos) {
        // xxxxx/foo.zip/yyyyy
        current = path.find('.', current);

        // Look forward for the next slash
        size_t s = findSlash(path, current);

        if (s == std::string::npos) {
            // No more slashes
            return false;
        }

        z = path.substr(0, s); 
        if (_isZipfile(z)) {
            return true;
        }
        
        current = s + 1;
    }

    z = "";
    return false;
}


bool FileSystem::_isZipfile(const std::string& _filename) {
    const std::string& filename = FilePath::canonicalize(FilePath::expandEnvironmentVariables(_filename));


    
    FILE* f = fopen(FilePath::removeTrailingSlash(filename).c_str(), "r");
    if (f == NULL) {
        return false;
    }
    uint8 header[4];
    (void)fread(header, 4, 1, f);
    
    const uint8 zipHeader[4] = {0x50, 0x4b, 0x03, 0x04};
    for (int i = 0; i < 4; ++i) {
        if (header[i] != zipHeader[i]) {
            fclose(f);
            return false;
        }
    }
    
    fclose(f);
    return true;
}


FILE* FileSystem::_fopen(const char* _filename, const char* mode) {
    const std::string& filename = FilePath::canonicalize(FilePath::expandEnvironmentVariables(_filename));

    for (const char* m = mode; *m != '\0'; ++m) {
        if (*m == 'w') {
            // Purge the cache entry for the parent of this directory
            _clearCache(FilePath::parent(_resolve(filename)));
            break;
        }
    }

    markFileUsed(filename);
    return ::fopen(filename.c_str(), mode);
}


void FileSystem::_clearCache(const std::string& _path) {
    const std::string& path = FilePath::expandEnvironmentVariables(_path);

    if ((path == "") || FilePath::isRoot(path)) {
        m_cache.clear();
    } else {
        Array<std::string> keys;
        m_cache.getKeys(keys);

        const std::string& prefix = 
#           ifdef G3D_WINDOWS
                toLower(FilePath::canonicalize(FilePath::removeTrailingSlash(_resolve(path))));
#           else
                FilePath::canonicalize(FilePath::removeTrailingSlash(_resolve(path)));
#           endif
        const std::string& prefixSlash = prefix + "/";

        for (int k = 0; k < keys.size(); ++k) {
            const std::string& key = keys[k];
            if ((key == prefix) || beginsWith(key, prefixSlash)) {
                m_cache.remove(keys[k]);
            }
        }
    }
}


void FileSystem::_setCacheLifetime(float t) {
    m_cacheLifetime = t;
}


void FileSystem::_createDirectory(const std::string& _dir) {
    const std::string& dir = FilePath::expandEnvironmentVariables(_dir);

    if (dir == "") {
        return;
    }
    
    std::string d = _resolve(dir);
    
    // Add a trailing / if there isn't one.
    switch (d[d.size() - 1]) {
    case '/':
    case '\\':
        break;

    default:
        d += "/";
    }

    // If it already exists, do nothing
    if (_exists(FilePath::removeTrailingSlash(d))) {
        return;
    }

    // Parse the name apart
    std::string root, base, ext;
    Array<std::string> path;

    std::string lead;
    FilePath::parse(d, root, path, base, ext);
    debugAssert(base == "");
    debugAssert(ext == "");

    // Begin with an extra period so "c:\" becomes "c:\.\" after
    // appending a path and "c:" becomes "c:.\", not root: "c:\"
    std::string p = root + ".";

    // Create any intermediate that doesn't exist
    for (int i = 0; i < path.size(); ++i) {
        p += "/" + path[i];
        if (! _exists(p)) {
            // Windows only requires one argument to mkdir,
            // where as unix also requires the permissions.
#           ifndef G3D_WINDOWS
                mkdir(p.c_str(), 0777);
#           else
                _mkdir(p.c_str());
#           endif
        }
    }

    _clearCache(FilePath::parent(FilePath::removeTrailingSlash(d)));
}


void FileSystem::_copyFile(const std::string& _source, const std::string& _dest) {
    const std::string& source = FilePath::expandEnvironmentVariables(_source);
    const std::string& dest = FilePath::expandEnvironmentVariables(_dest);
#   ifdef G3D_WINDOWS
        // TODO: handle case where srcPath is in a zipfile
        CopyFileA(source.c_str(), dest.c_str(), FALSE);
        _clearCache(FilePath::parent(_resolve(dest)));
#   else
        // Read it all in, then dump it out
        BinaryInput  in(source, G3D_LITTLE_ENDIAN);
        BinaryOutput out(dest, G3D_LITTLE_ENDIAN);
        out.writeBytes(in.getCArray(), in.size());
        out.commit(false);
#   endif        
}


bool FileSystem::_exists(const std::string& _f, bool trustCache, bool caseSensitive) {
    const std::string& f = FilePath::expandEnvironmentVariables(_f);

    if (FilePath::isRoot(f)) {
#       ifdef G3D_WINDOWS
            const std::string& winname = toLower(f.substr(0, 1)) + ":\\";
            return _drives().contains(winname);
#       else
            return true;
#       endif
    }

    const std::string& path = FilePath::removeTrailingSlash(f);
    const std::string& parentPath = FilePath::parent(path);

    const bool forceUpdate = ! trustCache;
    const Dir& entry = getContents(parentPath, forceUpdate);

    if (FilePath::containsWildcards(f)) {
        if (! entry.exists) {
            // The directory didn't exist, so neither do its contents
            return false;
        } 

        const std::string& pattern = FilePath::baseExt(path);

        // See if any element of entry matches the wild card
        for (int i = 0; i < entry.nodeArray.size(); ++i) {
            if (FilePath::matches(entry.nodeArray[i].name, pattern, caseSensitive)) {
                return true;
            }
        }

        // Could not find a match
        return false;

    } else {
        return entry.exists && entry.contains(FilePath::baseExt(path), caseSensitive);
    }
}


bool FileSystem::_isDirectory(const std::string& _filename) {
    const std::string& filename = FilePath::expandEnvironmentVariables(_filename);
    // TODO: work with zipfiles and cache
    struct _stat st;
    const bool exists = _stat(FilePath::removeTrailingSlash(filename).c_str(), &st) != -1;
    return exists && ((st.st_mode & S_IFDIR) != 0);
}


void FileSystem::_removeFile(const std::string& path) {
    alwaysAssertM(! inZipfile(path), "Cannot invoke removeFile() on files inside zipfiles.");
    Array<std::string> files;
    getFiles(path, files, true);

    for (int i = 0; i < files.size(); ++i) {
        const std::string& filename = files[i];
        int retval = ::remove(filename.c_str());
        (void)retval;
    }
    
    // Remove from cache
    _clearCache(FilePath::parent(path));
}


std::string FileSystem::_resolve(const std::string& _filename, const std::string& _cwd) {
    const std::string& filename = FilePath::expandEnvironmentVariables(_filename);
    const std::string& cwd = FilePath::expandEnvironmentVariables(_cwd);

    if (filename.size() >= 1) {
        if (isSlash(filename[0])) {
            // Already resolved
            return filename;
        } else {

            #ifdef G3D_WINDOWS
                if ((filename.size() >= 2) && (filename[1] == ':')) {
                    // There is a drive spec on the front.
                    if ((filename.size() >= 3) && isSlash(filename[2])) {
                        // Already fully qualified
                        return filename;
                    } else {
                        // The drive spec is relative to the
                        // working directory on that drive.
                        debugAssertM(false, "Files of the form d:path are"
                                     " not supported (use a fully qualified"
                                     " name).");
                        return filename;
                    }
                }
            #endif
        }
    }

    // Prepend the working directory.
    return FilePath::concat(cwd, filename);
}


std::string FileSystem::_currentDirectory() {
    static const int N = 2048;
    char buffer[N];

    (void)_getcwd(buffer, N);
    return std::string(buffer);
}


static Set<std::string> _filesUsed;

void FileSystem::markFileUsed(const std::string& filename) {
    mutex.lock();
    _filesUsed.insert(filename);
    mutex.unlock();
}


const Set<std::string>& FileSystem::usedFiles() {
    return _filesUsed;
}


bool FileSystem::_isNewer(const std::string& _src, const std::string& _dst) {
    const std::string& src = FilePath::expandEnvironmentVariables(_src);
    const std::string& dst = FilePath::expandEnvironmentVariables(_dst);

    // TODO: work with cache and zipfiles
    struct _stat sts;
    bool sexists = _stat(src.c_str(), &sts) != -1;

    struct _stat dts;
    bool dexists = _stat(dst.c_str(), &dts) != -1;

    return sexists && ((! dexists) || (sts.st_mtime > dts.st_mtime));
}


int64 FileSystem::_size(const std::string& _filename) {
    const std::string& filename = FilePath::canonicalize(FilePath::expandEnvironmentVariables(_filename));

    struct stat64 st;
    int result = stat64(filename.c_str(), &st);
    
    if (result == -1) {
#if _HAVE_ZIP /* G3DFIX: Use ZIP-library only if defined */
        std::string zip, contents;
        if (zipfileExists(filename, zip, contents)) {
            int64 requiredMem;
            
            struct zip *z = zip_open( zip.c_str(), ZIP_CHECKCONS, NULL );
            debugAssertM(z != NULL, zip + ": zip open failed.");
            {
                struct zip_stat info;
                zip_stat_init( &info );    // Docs unclear if zip_stat_init is required.
                int success = zip_stat( z, contents.c_str(), ZIP_FL_NOCASE, &info );
                (void) success;
                debugAssertM(success == 0, zip + ": " + contents + ": zip stat failed.");
                requiredMem = info.size;
            }
            zip_close(z);
            return requiredMem;
        } else {
#endif
            return -1;
#if _HAVE_ZIP /* G3DFIX: Use ZIP-library only if defined */
         }
#endif
    }
    
    return st.st_size;
}


void FileSystem::listHelper
(const std::string&  shortSpec,
 const std::string&  parentPath, 
 Array<std::string>& result, 
 const ListSettings& settings) {

    Dir& dir = getContents(parentPath, false);

    if (! dir.exists) {
        return;
    }

    for (int i = 0; i < dir.nodeArray.size(); ++i) {
        Entry& entry = dir.nodeArray[i];
        // See if it matches the spec
        if (FilePath::matches(entry.name, shortSpec, settings.caseSensitive)) {

            if ((entry.type == UNKNOWN) && 
                (! (settings.files && settings.directories) ||
                 settings.recursive)) {
                // Update the type: it is unknown and we'll need to branch onit below
                entry.type = isDirectory(FilePath::concat(parentPath, entry.name)) ? DIR_TYPE : FILE_TYPE;
            }
            
            if ((settings.files && settings.directories) ||
                (settings.files && (entry.type == FILE_TYPE)) ||
                (settings.directories && (entry.type == DIR_TYPE))) {
                
                if (settings.includeParentPath) {
                    result.append(FilePath::concat(parentPath, entry.name));
                } else {
                    result.append(entry.name);
                }
            }
        } // match
  
        if (settings.recursive) {
            if (entry.type == UNKNOWN) {
                entry.type = isDirectory(FilePath::concat(parentPath, entry.name)) ? DIR_TYPE : FILE_TYPE;
            }

            if (entry.type == DIR_TYPE) {
                listHelper(shortSpec, FilePath::concat(parentPath, entry.name), result, settings);
            }
        }
    } // for
}


void FileSystem::_list(const std::string& _spec, Array<std::string>& result, const ListSettings& settings) {
    const std::string& spec = FilePath::expandEnvironmentVariables(_spec);

    const std::string& shortSpec = FilePath::baseExt(spec);
    const std::string& parentPath = FilePath::parent(spec);

    listHelper(shortSpec, parentPath, result, settings);
}



#ifdef G3D_WINDOWS
const Array<std::string>& FileSystem::_drives() {
    if (m_winDrive.length() == 0) {
        // See http://msdn.microsoft.com/en-us/library/aa364975(VS.85).aspx
        static const size_t bufSize = 5000;
        char bufData[bufSize];
        GetLogicalDriveStringsA(bufSize, bufData);

        // Drive list is a series of NULL-terminated strings, itself terminated with a NULL.
        for (size_t i = 0; bufData[i] != '\0'; ++i) {
            const char* thisString = bufData + i;
            m_winDrive.append(toLower(thisString));
            i += strlen(thisString);
        }
    }

    return m_winDrive;
}
#endif

/////////////////////////////////////////////////////////////////////

bool FilePath::isRoot(const std::string& f) {
#   ifdef G3D_WINDOWS
        if (f.length() < 2) {
            return false;
        }

        if (f[1] == ':') {
            if (f.length() == 2) {
                // e.g.,   "x:"
                return true;
            } else if ((f.length() == 3) && isSlash(f[2])) {
                // e.g.,   "x:\"
                return true;
            }
        }

        // Windows shares are considered roots, but only if this does not include a path inside the share
        if (isSlash(f[0]) && isSlash(f[1])) {
            size_t i = f.find("/", 3);
            size_t j = f.find("\\", 3);

            if (i == std::string::npos) {
                i = j;
            }

            // e.g., "\\foo\", "\\foo"
            return ((i == std::string::npos) || (i == f.length() - 1));
        }
#   else
        if (f == "/") {
            return true;
        }
#   endif

    return false;
}


std::string FilePath::removeTrailingSlash(const std::string& f) {
    bool removeSlash = ((endsWith(f, "/") || endsWith(f, "\\"))) && ! isRoot(f);

    return removeSlash ? f.substr(0, f.length() - 1) : f;
}


std::string FilePath::concat(const std::string& dirname, const std::string& file) {
    // Ensure that the directory ends in a slash
    if (! dirname.empty() && 
        ! isSlash(dirname[dirname.size() - 1]) &&
        (dirname[dirname.size() - 1] != ':')) {
        return dirname + '/' + file;
    } else {
        return dirname + file;
    }
}


std::string FilePath::ext(const std::string& filename) {
    size_t i = filename.rfind(".");
    if (i != std::string::npos) {
        return filename.substr(i + 1, filename.length() - i);
    } else {
        return "";
    }
}


std::string FilePath::baseExt(const std::string& filename) {
    size_t i = findLastSlash(filename);

#   ifdef G3D_WINDOWS
        size_t j = filename.rfind(":");
        if ((i == std::string::npos) && (j != std::string::npos)) {
            i = j;
        }
#   endif

    if (i == std::string::npos) {
        return filename;
    } else {
        return filename.substr(i + 1, filename.length() - i);
    }
}


std::string FilePath::base(const std::string& path) {
    std::string filename = baseExt(path);
    size_t i = filename.rfind(".");
    if (i == std::string::npos) {
        // No extension
        return filename;
    } else {
        return filename.substr(0, i);
    }
}


std::string FilePath::parent(const std::string& path) {    
    size_t i = findLastSlash(removeTrailingSlash(path));

#   ifdef G3D_WINDOWS
        size_t j = path.rfind(":");
        if ((i == std::string::npos) && (j != std::string::npos)) {
            i = j;
        }
#   endif

    if (i == std::string::npos) {
        return "";
    } else {
        return path.substr(0, i + 1);
    }
}


bool FilePath::containsWildcards(const std::string& filename) {
    return (filename.find('*') != std::string::npos) || (filename.find('?') != std::string::npos);
}


bool FilePath::matches(const std::string& path, const std::string& pattern, bool caseSensitive) {
    int flags = FNM_PERIOD | FNM_NOESCAPE | FNM_PATHNAME;
    if (!  caseSensitive) {
        flags |= FNM_CASEFOLD;
    }
    return g3dfnmatch(pattern.c_str(), path.c_str(), flags) == 0;
}


static int fixslash(int c) {
    return (c == '\\') ? '/' : c;
}


std::string FilePath::canonicalize(std::string x) {
    std::transform(x.begin(), x.end(), x.begin(), fixslash);
    return x;
}

void FilePath::parse
(const std::string&     filename,
 std::string&           root,
 Array<std::string>&    path,
 std::string&           base,
 std::string&           ext) {

    std::string f = filename;

    root = "";
    path.clear();
    base = "";
    ext = "";

    if (f == "") {
        // Empty filename
        return;
    }

    // See if there is a root/drive spec.
    if ((f.size() >= 2) && (f[1] == ':')) {
        
        if ((f.size() > 2) && isSlash(f[2])) {
        
            // e.g.  c:\foo
            root = f.substr(0, 3);
            f = f.substr(3, f.size() - 3);
        
        } else {
        
            // e.g.  c:foo
            root = f.substr(2);
            f = f.substr(2, f.size() - 2);

        }

    } else if ((f.size() >= 2) && isSlash(f[0]) && isSlash(f[1])) {
        
        // e.g. //foo
        root = f.substr(0, 2);
        f = f.substr(2, f.size() - 2);

    } else if (isSlash(f[0])) {
        
        root = f.substr(0, 1);
        f = f.substr(1, f.size() - 1);

    }

    // Pull the extension off
    {
        // Find the period
        size_t i = f.rfind('.');

        if (i != std::string::npos) {
            // Make sure it is after the last slash!
	    size_t j = findLastSlash(f);
            if ((j == std::string::npos) || (i > j)) {
                ext = f.substr(i + 1, f.size() - i - 1);
                f = f.substr(0, i);
            }
        }
    }

    // Pull the basename off
    {
        // Find the last slash
        size_t i = findLastSlash(f);
        
        if (i == std::string::npos) {
            
            // There is no slash; the basename is the whole thing
            base = f;
            f    = "";

        } else if ((i != std::string::npos) && (i < f.size() - 1)) {
            
            base = f.substr(i + 1, f.size() - i - 1);
            f    = f.substr(0, i);

        }
    }

    // Parse what remains into path.
    size_t prev, cur = 0;

    while (cur < f.size()) {
        prev = cur;
        
        // Allow either slash
        size_t i = f.find('/', prev + 1);
        size_t j = f.find('\\', prev + 1);
        if (i == std::string::npos) {
            i = f.size();
        }

        if (j == std::string::npos) {
            j = f.size();
        }

        cur = min(i, j);

        if (cur == std::string::npos) {
            cur = f.size();
        }

        path.append(f.substr(prev, cur - prev));
        ++cur;
    }
}


std::string FilePath::expandEnvironmentVariables(const std::string& path) {
    // Search for pattern
    size_t end = path.find_first_of('$', 0);
    if (end == std::string::npos) {
        // Pattern does not exist
        return path;
    }

    size_t start = 0;
    std::string result;
    while (end != std::string::npos) {
        const std::string& before = path.substr(start, end - start);
        result += before;
        start = end + 1;
        std::string var;
        if (path[start] == '(') {
            // Search for close paren
            end = path.find_first_of(')', start + 1);
            if (end == std::string::npos) {
                throw std::string("Missing close paren in environment variable in \"") + path + "\"";
            }
            var = path.substr(start + 1, end - start - 1);
        } else {
            // Search for slash or end of string
            end = path.find_first_of('/', start);
            size_t i = path.find_first_of('\\', start);
            if ((size_t(i) != std::string::npos) && ((end == std::string::npos) || (size_t(i) < end))) {
                end = i;
            }
            if (end == std::string::npos) {
                // If the varible goes to the end of the string, it is the rest of the string
                end = path.size();
            } else {
                --end;
            }
            var = path.substr(start, end - start + 1);
        }

        if (! var.empty()) {
            const char* value = getenv(var.c_str());

            if (value == NULL) {
                throw (std::string("LocalLightingEnvironment variable \"") + var + "\" not defined for path \"" + path + "\"");
            } else {
                result += value;
            }
        } else {
            // We just parsed an "empty" variable, which was probably a default share on Windows, e.g.,
            // "\\mycomputer\c$", and not a variable name.
            result += "$";            
        }

        start = end + 1;
        end = path.find_first_of('$', start);
    }

    // Paste on the remainder of the source path
    if (start < path.size()) {
        result += path.substr(start);
    }

    return result;
}


/** Generate a unique filename based on the provided hint */
std::string FilePath::makeLegalFilename(const std::string& f, size_t maxLength) {
    std::string tentative;
    
    for (size_t i = 0; i < G3D::min(maxLength, f.size()); ++i) {
        const char c = f[i];
        if (isLetter(c) || isDigit(c) || (c == '-') || (c == '+') || (c == '=') || (c == '(') || (c == ')')) {
            tentative += c;
        } else {
            tentative += "_";
        }
    }

    return tentative;
}

}
