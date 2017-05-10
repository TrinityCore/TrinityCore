/**
 @file fileutils.cpp
 
 @author Morgan McGuire, graphics3d.com
 
 @author  2002-06-06
 @edited  2010-02-05
 */

#include <cstring>
#include <cstdio>
#include "G3D/platform.h"
#include "G3D/fileutils.h"
#include "G3D/BinaryInput.h"
#include "G3D/BinaryOutput.h"
#include "G3D/g3dmath.h"
#include "G3D/stringutils.h"
#include "G3D/Set.h"
#include "G3D/g3dfnmatch.h"
#include "G3D/FileSystem.h"

#include <sys/stat.h>
#include <sys/types.h>
#if _HAVE_ZIP /* G3DFIX: Use ZIP-library only if defined */
    #include "zip.h"
#endif

#ifdef G3D_WINDOWS
   // Needed for _getcwd
   #include <direct.h>
   #include <io.h>
#else
    #include <dirent.h>
    #include <fnmatch.h>
    #include <unistd.h>
    #define _getcwd getcwd
    #define _stat stat
#endif


namespace G3D {
    
namespace _internal {
    Set<std::string> currentFilesUsed;
}

std::string pathConcat(const std::string& dirname, const std::string& file) {
    // Ensure that the directory ends in a slash
    if ((dirname.size() != 0) && 
        (dirname[dirname.size() - 1] != '/') &&
        (dirname[dirname.size() - 1] != '\\') &&
        (dirname[dirname.size() - 1] != ':')) {
        return dirname + '/' + file;
    } else {
        return dirname + file;
    }
}

std::string resolveFilename(const std::string& filename) {
    if (filename.size() >= 1) {
        if ((filename[0] == '/') || (filename[0] == '\\')) {
            // Already resolved
            return filename;
        } else {

            #ifdef G3D_WINDOWS
                if ((filename.size() >= 2) && (filename[1] == ':')) {
                    // There is a drive spec on the front.
                    if ((filename.size() >= 3) && ((filename[2] == '\\') || 
                                                   (filename[2] == '/'))) {
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

    char buffer[1024];

    // Prepend the working directory.
    (void)_getcwd(buffer, 1024);

    return format("%s/%s", buffer, filename.c_str());
}

bool zipfileExists(const std::string& filename) {
    std::string    outZipfile;
    std::string    outInternalFile;
    return zipfileExists(filename, outZipfile, outInternalFile);
}


std::string readWholeFile(const std::string& filename) {

    std::string s;

    debugAssert(filename != "");
    if (!  FileSystem::exists(filename)) {
        throw (filename + " not found");
    }
    FileSystem::markFileUsed(filename);
    std::string zipfile;

    if (! FileSystem::inZipfile(filename, zipfile)) {
        // Not in zipfile
        if (! FileSystem::exists(filename)) {
            throw FileNotFound(filename, std::string("File not found in readWholeFile: ") + filename);
        }

        int64 length = FileSystem::size(filename);

        char* buffer = (char*)System::alignedMalloc(length + 1, 16);
        debugAssert(buffer);
        FILE* f = FileSystem::fopen(filename.c_str(), "rb");
        debugAssert(f);
        int64 ret = fread(buffer, 1, length, f);
        debugAssert(ret == length);(void)ret;
        FileSystem::fclose(f);

        buffer[length] = '\0';    
        s = std::string(buffer);

        System::alignedFree(buffer);

    } else {

        // In zipfile
        FileSystem::markFileUsed(zipfile);

#if _HAVE_ZIP /* G3DFIX: Use ZIP-library only if defined */    
        // Zipfiles require Unix-style slashes
        std::string internalFile = FilePath::canonicalize(filename.substr(zipfile.length() + 1));
        struct zip* z = zip_open(zipfile.c_str(), ZIP_CHECKCONS, NULL);
        {
            struct zip_stat info;
            zip_stat_init( &info );    // TODO: Docs unclear if zip_stat_init is required.
            zip_stat(z, internalFile.c_str(), ZIP_FL_NOCASE, &info);

            // Add NULL termination
            char* buffer = reinterpret_cast<char*>(System::alignedMalloc(info.size + 1, 16));
            buffer[info.size] = '\0';

            struct zip_file* zf = zip_fopen( z, internalFile.c_str(), ZIP_FL_NOCASE );
            if (zf == NULL) {
                throw std::string("\"") + internalFile + "\" inside \"" + zipfile + "\" could not be opened.";
            } else {
                const int64 bytesRead = zip_fread( zf, buffer, (info.size));
                debugAssertM((int64)bytesRead == (int64)info.size,
                             internalFile + " was corrupt because it unzipped to the wrong size.");
                (void)bytesRead;
                zip_fclose( zf );
            }
            // Copy the string
            s = buffer;
            System::alignedFree(buffer);
        }
        zip_close( z );
#endif
    }

    return s;
}


int64 fileLength(const std::string& filename) {
    struct _stat st;
    int result = _stat(filename.c_str(), &st);
    
    if (result == -1) {
#if _HAVE_ZIP /* G3DFIX: Use ZIP-library only if defined */
        std::string zip, contents;
        if(zipfileExists(filename, zip, contents)){
            int64 requiredMem;

                        struct zip *z = zip_open( zip.c_str(), ZIP_CHECKCONS, NULL );
                        debugAssertM(z != NULL, zip + ": zip open failed.");
            {
                                struct zip_stat info;
                                zip_stat_init( &info );    // TODO: Docs unclear if zip_stat_init is required.
                                int success = zip_stat( z, contents.c_str(), ZIP_FL_NOCASE, &info );
                (void)success;
                                debugAssertM(success == 0, zip + ": " + contents + ": zip stat failed.");
                                requiredMem = info.size;
            }
                        zip_close( z );
            return requiredMem;
        } else {
        return -1;
        }
#else
        return -1;
#endif
    }

    return st.st_size;
}

///////////////////////////////////////////////////////////////////////////////
void writeWholeFile(
    const std::string&          filename,
    const std::string&          str,
    bool                        flush) {

    // Make sure the directory exists.
    std::string root, base, ext, path;
    Array<std::string> pathArray;
    parseFilename(filename, root, pathArray, base, ext); 

    path = root + stringJoin(pathArray, '/');
    if (! FileSystem::exists(path, false)) {
        FileSystem::createDirectory(path);
    }

    FILE* file = FileSystem::fopen(filename.c_str(), "wb");

    debugAssert(file);

    fwrite(str.c_str(), str.size(), 1, file);

    if (flush) {
        fflush(file);
    }

    FileSystem::fclose(file);
}

///////////////////////////////////////////////////////////////////////////////

/**
 Creates the directory (which may optionally end in a /)
 and any parents needed to reach it.
 */
void createDirectory(
    const std::string&  dir) {
    
    if (dir == "") {
        return;
    }

    std::string d;

    // Add a trailing / if there isn't one.
    switch (dir[dir.size() - 1]) {
    case '/':
    case '\\':
        d = dir;
        break;

    default:
        d = dir + "/";
    }

    // If it already exists, do nothing
    if (FileSystem::exists(d.substr(0, d.size() - 1))) {
        return;
    }

    // Parse the name apart
    std::string root, base, ext;
    Array<std::string> path;

    std::string lead;
    parseFilename(d, root, path, base, ext);
    debugAssert(base == "");
    debugAssert(ext == "");

    // Begin with an extra period so "c:\" becomes "c:\.\" after
    // appending a path and "c:" becomes "c:.\", not root: "c:\"
    std::string p = root + ".";

    // Create any intermediate that doesn't exist
    for (int i = 0; i < path.size(); ++i) {
        p += "/" + path[i];
        if (! FileSystem::exists(p)) {
            // Windows only requires one argument to mkdir,
            // where as unix also requires the permissions.
#           ifndef G3D_WINDOWS
                mkdir(p.c_str(), 0777);
#            else
                _mkdir(p.c_str());
#            endif
        }
    }
}


///////////////////////////////////////////////////////////////////////////////

#if _HAVE_ZIP /* G3DFIX: Use ZIP-library only if defined */
/* Helper methods for zipfileExists()*/
// Given a string (the drive) and an array (the path), computes the directory
static void _zip_resolveDirectory(std::string& completeDir, const std::string& drive, const Array<std::string>& path, const int length){
    completeDir = drive;
    int tempLength;
    // if the given length is longer than the array, we correct it
    if(length > path.length()){
        tempLength = path.length();
    } else{
        tempLength = length;
    }

    for(int t = 0; t < tempLength; ++t){
        if(t > 0){
            completeDir += "/";
        }
        completeDir += path[t];
    }
}


/** assumes that zipDir references a .zip file */
static bool _zip_zipContains(const std::string& zipDir, const std::string& desiredFile){
        struct zip *z = zip_open( zipDir.c_str(), ZIP_CHECKCONS, NULL );
    //the last parameter, an int, determines case sensitivity:
    //1 is sensitive, 2 is not, 0 is default
        int test = zip_name_locate( z, desiredFile.c_str(), ZIP_FL_NOCASE );
        zip_close( z );
    if(test == -1){
        return false;
    }
    return true;
}
#endif


/** If no zipfile exists, outZipfile and outInternalFile are unchanged */
bool zipfileExists(const std::string& filename, std::string& outZipfile,
                   std::string& outInternalFile){
#if _HAVE_ZIP /* G3DFIX: Use ZIP-library only if defined */
    Array<std::string> path;
    std::string drive, base, ext, zipfile, infile;
    parseFilename(filename, drive, path, base, ext);
    
    // Put the filename back together
    if ((base != "") && (ext != "")) {
        infile = base + "." + ext;
    } else {
        infile = base + ext;
    }
    
    // Remove all standalone single dots (".") from path
    for (int i = 0; i < path.length(); ++i) {
        if (path[i] == ".") {
            path.remove(i);
            --i;
        }
    }
    
    // Remove non-leading ".." from path
    for (int i = 1; i < path.length(); ++i) {
        if ((path[i] == "..") && (i > 0) && (path[i - 1] != "..")) {
            // Remove both i and i - 1
            path.remove(i - 1, 2);
            i -= 2;
        }
    }
    
    // Walk the path backwards, accumulating pieces onto the infile until
    // we find a zipfile that contains it
    for (int t = 0; t < path.length(); ++t){
        _zip_resolveDirectory(zipfile, drive, path,  path.length() - t);
        if (t > 0) {
            infile = path[path.length() - t] + "/" + infile;
        }

        if (endsWith(zipfile, "..")) {
            return false;
        }
        
        if (FileSystem::exists(zipfile)) {
            // test if it actually is a zipfile
            // if not, return false, a bad
            // directory structure has been given,
            // not a .zip
            if (FileSystem::isZipfile(zipfile)){
                
                if (_zip_zipContains(zipfile, infile)){
                    outZipfile = zipfile;
                    outInternalFile = infile;
                    return true;
                } else {
                    return false;
                }
            } else {
                // the directory structure was valid but did not point to a .zip
                return false;
            }
        }
        
    }
#else
    (void)filename;
    (void)outZipfile;
    (void)outInternalFile;
#endif
    // not a valid directory structure ever, 
    // obviously no .zip was found within the path 
    return false;
}    

///////////////////////////////////////////////////////////////////////////////

std::string generateFilenameBase(const std::string& prefix, const std::string& suffix) {
    Array<std::string> exist;

    // Note "template" is a reserved word in C++
    std::string templat = prefix + System::currentDateString() + "_";
    FileSystem::getFiles(templat + "*", exist, true);
    
    // Remove extensions
    for (int i = 0; i < exist.size(); ++i) {
        const std::string ext = FilePath::ext(exist[i]);
        if (ext.length() > 0) {
            exist[i] = exist[i].substr(0, exist[i].length() - ext.length() - 1);
        }
    }

    int num = 0;
    std::string result;
    templat += "%03d" + suffix;
    do {
        result = format(templat.c_str(), num);
        ++num;
    } while (exist.contains(result));

    return result;
}

///////////////////////////////////////////////////////////////////////////////

void copyFile(
    const std::string&          source,
    const std::string&          dest) {

    #ifdef G3D_WINDOWS
        CopyFileA(source.c_str(), dest.c_str(), FALSE);
    #else
        // TODO: don't use BinaryInput and BinaryOutput
        // Read it all in, then dump it out
        BinaryInput  in(source, G3D_LITTLE_ENDIAN);
        BinaryOutput out(dest, G3D_LITTLE_ENDIAN);
        out.writeBytes(in.getCArray(), in.size());
        out.commit(false);
    #endif
}

//////////////////////////////////////////////////////////////////////////////

void parseFilename(
    const std::string&  filename,
    std::string&        root,
    Array<std::string>& path,
    std::string&        base,
    std::string&        ext) {

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

    } else if ((f.size() >= 2) & isSlash(f[0]) && isSlash(f[1])) {
        
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
            size_t j = maxNotNPOS(f.rfind('/'), f.rfind('\\'));
            if ((j == std::string::npos) || (i > j)) {
                ext = f.substr(i + 1, f.size() - i - 1);
                f = f.substr(0, i);
            }
        }
    }

    // Pull the basename off
    {
        // Find the last slash
        size_t i = maxNotNPOS(f.rfind('/'), f.rfind('\\'));
        
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


/**
 Helper for getFileList and getDirectoryList.

 @param wantFiles       If false, returns the directories, otherwise
                        returns the files.
 @param includePath     If true, the names include paths
 */
static void getFileOrDirListNormal
(const std::string&    filespec,
 Array<std::string>&    files,
 bool            wantFiles,
 bool                   includePath) {
    
    bool test = wantFiles ? true : false;
    
    std::string path = "";

    // Find the place where the path ends and the file-spec begins
    size_t i = filespec.rfind('/');
    size_t j = filespec.rfind('\\');
    
    // Drive letters on Windows can separate a path
    size_t k = filespec.rfind(':');
    
    if (((j != std::string::npos) && (j > i)) ||
        (i == std::string::npos)) {
        i = j;
    }
    
    if (((k != std::string::npos) && (k > i)) ||
        (i == std::string::npos)) {
        i = k;
    }
    
    // If there is a path, pull it off
    if (i != std::string::npos) {
        path = filespec.substr(0, i + 1);
    }
   
    std::string prefix = path;

    if (path.size() > 0) {
        // Strip the trailing character
        path = path.substr(0, path.size() - 1);
    }

#   ifdef G3D_WINDOWS
    {
       struct _finddata_t fileinfo;

        long handle = (long)_findfirst(filespec.c_str(), &fileinfo);
        int result = handle;

        while (result != -1) {
            if ((((fileinfo.attrib & _A_SUBDIR) == 0) == test) && 
                strcmp(fileinfo.name, ".") &&
                strcmp(fileinfo.name, "..")) {
                
                if (includePath) {
                    files.append(prefix + fileinfo.name);
                } else {
                    files.append(fileinfo.name);
                }
            }
            
            result = _findnext(handle, &fileinfo);
        }
    }
#   else
    {
        if (path == "") {
            // Empty paths don't work on Unix
            path = ".";
        }

        // Unix implementation
        DIR* dir = opendir(path.c_str());

        if (dir != NULL) {
            struct dirent* entry = readdir(dir);

            while (entry != NULL) {

                // Exclude '.' and '..'
                if ((strcmp(entry->d_name, ".") != 0) &&
                    (strcmp(entry->d_name, "..") != 0)) {
                    
                    // Form a name with a path
                    std::string filename = prefix + entry->d_name;
                    // See if this is a file or a directory
                    struct _stat st;
                    bool exists = _stat(filename.c_str(), &st) != -1;

                    if (exists &&

                        // Make sure it has the correct type
                        (((st.st_mode & S_IFDIR) == 0) == test) &&

                        // Make sure it matches the wildcard
                        (fnmatch(filespec.c_str(),
                                 filename.c_str(),
                                 FNM_PATHNAME) == 0)) {
                        
                        if (includePath) {
                            files.append(filename);
                        } else {
                            files.append(entry->d_name);
                        }
                    }
                }

                entry = readdir(dir);
            }
            closedir(dir);
        }
    }
#   endif
}

#if _HAVE_ZIP /* G3DFIX: Use ZIP-library only if defined */
/**
 @param path   The zipfile name (no trailing slash)
 @param prefix Directory inside the zipfile. No leading slash, must have trailing slash if non-empty.
 @param file   Name inside the zipfile that we are testing to see if it matches prefix + "*"
 */
static void _zip_addEntry(const std::string& path,
                          const std::string& prefix,
                          const std::string& file,
                          Set<std::string>& files,
                          bool wantFiles,
                          bool includePath) {

    // Make certain we are within the desired parent folder (prefix)
    if (beginsWith(file, prefix)) {
        // validityTest was prefix/file
        
        // Extract everything to the right of the prefix
        std::string s = file.substr(prefix.length());
        
        if (s == "") {
            // This was the name of the prefix
            return;
        }
        
        // See if there are any slashes
        size_t slashPos = s.find('/');
        
        bool add = false;
        
        if (slashPos == std::string::npos) {
            // No slashes, so s must be a file
            add = wantFiles;
        } else if (! wantFiles) {
            // Not all zipfiles list directories as explicit entries.
            // Because of this, if we're looking for directories and see
            // any path longer than prefix, we must add the subdirectory. 
            // The Set will fix duplicates for us.
            s = s.substr(0, slashPos);
            add = true;
        }
        
        if (add) {
            if (includePath) {
                files.insert(path + "/" + prefix + s);
            } else {
                files.insert(s);
            }
        }
    }
}
#endif


static void getFileOrDirListZip(const std::string& path,
                                const std::string& prefix,
                                Array<std::string>& files,
                                bool wantFiles,
                                bool includePath){
#if _HAVE_ZIP /* G3DFIX: Use ZIP-library only if defined */
    struct zip *z = zip_open( path.c_str(), ZIP_CHECKCONS, NULL );

    Set<std::string> fileSet;

    int count = zip_get_num_files( z );
    for( int i = 0; i < count; ++i ) {
        struct zip_stat info;
        zip_stat_init( &info );    // TODO: Docs unclear if zip_stat_init is required.
        zip_stat_index( z, i, ZIP_FL_NOCASE, &info );
        _zip_addEntry(path, prefix, info.name, fileSet, wantFiles, includePath);
    }
    
    zip_close( z );
    
    fileSet.getMembers(files);
#else
    (void)path;
    (void)prefix;
    (void)files;
    (void)wantFiles;
    (void)includePath;
#endif
}


static void determineFileOrDirList(
    const std::string&            filespec,
    Array<std::string>&            files,
    bool                        wantFiles,
    bool                        includePath) {

    // if it is a .zip, prefix will specify the folder within
    // whose contents we want to see
    std::string prefix = "";
    std::string path = filenamePath(filespec);

    if ((path.size() > 0) && isSlash(path[path.size() - 1])) {
        // Strip the trailing slash
        path = path.substr(0, path.length() -1);
    }
    
    if ((path == "") || FileSystem::exists(path)) {
        if ((path != "") && FileSystem::isZipfile(path)) {
            // .zip should only work if * is specified as the Base + Ext
            // Here, we have been asked for the root's contents
            debugAssertM(filenameBaseExt(filespec) == "*", "Can only call getFiles/getDirs on zipfiles using '*' wildcard");
            getFileOrDirListZip(path, prefix, files, wantFiles, includePath);
        } else {
            // It is a normal directory
            getFileOrDirListNormal(filespec, files, wantFiles, includePath);
        }
    } else if (zipfileExists(filenamePath(filespec), path, prefix)) {
        // .zip should only work if * is specified as the Base + Ext
        // Here, we have been asked for the contents of a folder within the .zip
        debugAssertM(filenameBaseExt(filespec) == "*", "Can only call getFiles/getDirs on zipfiles using '*' wildcard");
        getFileOrDirListZip(path, prefix, files, wantFiles, includePath);
    }
}


void getFiles(const std::string&            filespec,
              Array<std::string>&            files,
              bool                    includePath) {
    
    determineFileOrDirList(filespec, files, true, includePath);
}


void getDirs(
    const std::string&            filespec,
    Array<std::string>&            files,
    bool                        includePath) {

    determineFileOrDirList(filespec, files, false, includePath);
}


std::string filenameBaseExt(const std::string& filename) {
    size_t i = filename.rfind("/");
    size_t j = filename.rfind("\\");

    if ((j > i) && (j != std::string::npos)) {
        i = j;
    }

#   ifdef G3D_WINDOWS
        j = filename.rfind(":");
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


std::string filenameBase(const std::string& s) {
    std::string drive;
    std::string base;
    std::string ext;
    Array<std::string> path;

    parseFilename(s, drive, path, base, ext);
    return base;
}


std::string filenameExt(const std::string& filename) {
    size_t i = filename.rfind(".");
    if (i != std::string::npos) {
        return filename.substr(i + 1, filename.length() - i);
    } else {
        return "";
    }
}


std::string filenamePath(const std::string& filename) {
    size_t i = filename.rfind("/");
    size_t j = filename.rfind("\\");

    if ((j > i) && (j != std::string::npos)) {
        i = j;
    }

#   ifdef G3D_WINDOWS
        j = filename.rfind(":");
        if ((i == std::string::npos) && (j != std::string::npos)) {
            i = j;
        }
#   endif

    if (i == std::string::npos) {
        return "";
    } else {
        return filename.substr(0, i+1);
    }
}


bool isZipfile(const std::string& filename) {

    FILE* f = fopen(filename.c_str(), "r");
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


bool isDirectory(const std::string& filename) {
    struct _stat st;
    bool exists = _stat(filename.c_str(), &st) != -1;
    return exists && ((st.st_mode & S_IFDIR) != 0);
}


bool filenameContainsWildcards(const std::string& filename) {
    return (filename.find('*') != std::string::npos) || (filename.find('?') != std::string::npos);
}


bool fileIsNewer(const std::string& src, const std::string& dst) {
    struct _stat sts;
    bool sexists = _stat(src.c_str(), &sts) != -1;

    struct _stat dts;
    bool dexists = _stat(dst.c_str(), &dts) != -1;

    return sexists && ((! dexists) || (sts.st_mtime > dts.st_mtime));
}

}

#ifndef G3D_WINDOWS
  #undef _stat
#endif
