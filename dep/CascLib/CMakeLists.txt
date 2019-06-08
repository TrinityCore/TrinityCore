set(HEADER_FILES
    src/CascCommon.h
    src/CascLib.h
    src/CascPort.h
    src/common/Array.h
    src/common/Common.h
    src/common/Csv.h
    src/common/FileStream.h
    src/common/FileTree.h
    src/common/ListFile.h
    src/common/Map.h
    src/jenkins/lookup.h
)

set(SRC_FILES
    src/common/Common.cpp
    src/common/Directory.cpp
    src/common/Csv.cpp
    src/common/FileStream.cpp
    src/common/FileTree.cpp
    src/common/ListFile.cpp
    src/common/RootHandler.cpp
    src/jenkins/lookup3.c
    src/CascCommon.cpp
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
    src/CascRootFile_Mndx.cpp
    src/CascRootFile_Text.cpp
    src/CascRootFile_TVFS.cpp
    src/CascRootFile_OW.cpp
    src/CascRootFile_WoW.cpp
)

set(MD5_FILES
    src/md5/md5.cpp
)

add_library(casc STATIC ${SRC_FILES} ${HEADER_FILES} ${MD5_FILES})

target_include_directories(casc
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/src
    PRIVATE
      ${CMAKE_SOURCE_DIR}/dep)

target_compile_definitions(casc PUBLIC -D__SYS_ZLIB)

target_link_libraries(casc
  PRIVATE
    trinity-dependency-interface
  PUBLIC
    zlib)

set_target_properties(casc
  PROPERTIES
    FOLDER
      "dep")
