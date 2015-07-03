set(HEADER_FILES
    src/CascCommon.h
    src/CascLib.h
    src/CascMndxRoot.h
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
    src/common/FileStream.cpp
    src/common/ListFile.cpp
    src/common/Map.cpp
    src/jenkins/lookup3.c
    src/CascBuildCfg.cpp
    src/CascCommon.cpp
    src/CascDecompress.cpp
    src/CascDumpData.cpp
    src/CascFindFile.cpp
    src/CascMndxRoot.cpp
    src/CascOpenFile.cpp
    src/CascOpenStorage.cpp
    src/CascReadFile.cpp
)

set(TOMCRYPT_FILES
    src/libtomcrypt/src/hashes/hash_memory.c
    src/libtomcrypt/src/hashes/md5.c
    src/libtomcrypt/src/misc/crypt_argchk.c
    src/libtomcrypt/src/misc/crypt_hash_descriptor.c
    src/libtomcrypt/src/misc/crypt_hash_is_valid.c
    src/libtomcrypt/src/misc/crypt_libc.c
)

include_directories(${CMAKE_SOURCE_DIR}/dep)

# Turn off warnings for casclib till the sources are updated
IF ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang" OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU")
	set_source_files_properties(Common.cpp PROPERTIES COMPILE_FLAGS -Wno-char-subscripts)
endif()

add_library(casc STATIC ${SRC_FILES} ${TOMCRYPT_FILES})
