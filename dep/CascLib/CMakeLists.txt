set(HEADER_FILES
    src/CascCommon.h
    src/CascLib.h
    src/CascMndx.h
    src/CascPort.h
    src/common/Common.h
    src/common/FileStream.h
    src/common/ListFile.h
    src/common/Map.h
    src/jenkins/lookup.h
)

set(SRC_FILES
    src/common/Common.cpp
    src/common/Directory.cpp
    src/common/DumpContext.cpp
    src/common/DynamicArray.cpp
    src/common/FileStream.cpp
    src/common/ListFile.cpp
    src/common/Map.cpp
    src/common/RootHandler.cpp
    src/jenkins/lookup3.c
    src/CascCommon.cpp
    src/CascDecompress.cpp
    src/CascDecrypt.cpp
    src/CascDumpData.cpp
    src/CascFiles.cpp
    src/CascFindFile.cpp
    src/CascOpenFile.cpp
    src/CascOpenStorage.cpp
    src/CascReadFile.cpp
    src/CascRootFile_Diablo3.cpp
    src/CascRootFile_Mndx.cpp
    src/CascRootFile_Ovr.cpp
    src/CascRootFile_SC1.cpp
    src/CascRootFile_WoW6.cpp
)

set(TOMCRYPT_FILES
    src/libtomcrypt/src/hashes/hash_memory.c
    src/libtomcrypt/src/hashes/md5.c
    src/libtomcrypt/src/misc/crypt_argchk.c
    src/libtomcrypt/src/misc/crypt_hash_descriptor.c
    src/libtomcrypt/src/misc/crypt_hash_is_valid.c
    src/libtomcrypt/src/misc/crypt_libc.c
)

add_library(casc STATIC ${SRC_FILES} ${TOMCRYPT_FILES})

target_include_directories(casc
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/src
    PRIVATE
      ${CMAKE_SOURCE_DIR}/dep)

target_link_libraries(casc
  PRIVATE
    trinity-dependency-interface
  PUBLIC
    zlib)

set_target_properties(casc
  PROPERTIES
    FOLDER
      "dep")
