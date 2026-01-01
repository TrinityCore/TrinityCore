add_library(casc STATIC)

target_sources(casc
  PRIVATE
    src/common/Common.cpp
    src/common/Directory.cpp
    src/common/Csv.cpp
    src/common/FileStream.cpp
    src/common/FileTree.cpp
    src/common/ListFile.cpp
    src/common/Mime.cpp
    src/common/RootHandler.cpp
    src/common/Sockets.cpp
    src/hashes/md5.cpp
    src/hashes/sha1.cpp
    src/jenkins/lookup3.c
    src/overwatch/apm.cpp
    src/overwatch/cmf.cpp
    src/overwatch/aes.cpp
    src/CascDecompress.cpp
    src/CascDecrypt.cpp
    src/CascDumpData.cpp
    src/CascFiles.cpp
    src/CascFindFile.cpp
    src/CascIndexFiles.cpp
    src/CascOpenFile.cpp
    src/CascOpenStorage.cpp
    src/CascReadFile.cpp
    src/CascRootFile_Diablo3.cpp
    src/CascRootFile_Install.cpp
    src/CascRootFile_MNDX.cpp
    src/CascRootFile_Text.cpp
    src/CascRootFile_TVFS.cpp
    src/CascRootFile_OW.cpp
    src/CascRootFile_WoW.cpp)

target_sources(casc
  PUBLIC
    FILE_SET HEADERS
    BASE_DIRS src
    FILES
      src/CascLib.h
  PRIVATE
    FILE_SET casc_private_headers
    TYPE HEADERS
    BASE_DIRS src
    FILES
      src/CascCommon.h
      src/CascPort.h
      src/common/Array.h
      src/common/Common.h
      src/common/Csv.h
      src/common/Directory.h
      src/common/FileStream.h
      src/common/FileTree.h
      src/common/ListFile.h
      src/common/Map.h
      src/common/Mime.h
      src/common/Path.h
      src/common/RootHandler.h
      src/common/Sockets.h
      src/jenkins/lookup.h)

target_compile_definitions(casc PUBLIC CASC_USE_SYSTEM_ZLIB CASCLIB_NO_AUTO_LINK_LIBRARY CASCLIB_NODEBUG)

target_link_libraries(casc
  PRIVATE
    trinity-dependency-interface
  PUBLIC
    zlib)

set_target_properties(casc
  PROPERTIES
    FOLDER
      "dep")
