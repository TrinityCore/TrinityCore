# $NiH: CMakeLists.txt,v 1.1 2007/03/04 10:35:17 wiz Exp $

# XXX: TODO
# 1. pkgconfig file not yet built.
# 2. installation not tested.
# 3. Problems generating html pages.
# 4. distribution tarball not checked for unwanted/missing content.
# 5. create usable libtool .la file

PROJECT(libzip C)

INCLUDE(CheckFunctionExists)
INCLUDE(CheckIncludeFiles)
INCLUDE(CheckSymbolExists)

SET(PACKAGE "libzip")
SET(PACKAGE_NAME ${PACKAGE})
SET(PACKAGE_VERSION_MAJOR "0")
SET(PACKAGE_VERSION_MINOR "9")
SET(PACKAGE_VERSION_PATCH "3")
SET(VERSION "${PACKAGE_VERSION_MAJOR}.${PACKAGE_VERSION_MINOR}.${PACKAGE_VERSION_PATCH}")
SET(PACKAGE_VERSION ${VERSION})
SET(PACKAGE_STRING "${PACKAGE_NAME} ${PACKAGE_VERSION}")

ADD_SUBDIRECTORY(lib)
ADD_SUBDIRECTORY(man)
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(regress)

# Checks

CHECK_FUNCTION_EXISTS(fseeko HAVE_FSEEKO)
CHECK_FUNCTION_EXISTS(MoveFileEx HAVE_MOVEFILEEX)
CHECK_FUNCTION_EXISTS(mkstemp HAVE_MKSTEMP)
CHECK_INCLUDE_FILES(unistd.h HAVE_UNISTD_H)

INCLUDE(FindZLIB)
CHECK_SYMBOL_EXISTS(ZEXPORT zlib.h HAVE_ZEXPORT)
IF(NOT HAVE_ZEXPORT)
  MESSAGE(FATAL_ERROR "-- ZLIB version too old, please install at least v1.1.2")
ENDIF(NOT HAVE_ZEXPORT)

# Targets

# XXX: pkgconfig file

# installation

# XXX: pkgconfig file

# packaging

SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "library for manipulating zip archives")
SET(CPACK_PACKAGE_VENDOR "Dieter Baron <dillo@giga.or.at> and Thomas Klausner <tk@giga.or.at>")
SET(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README")
# XXX: provide a license file
#SET(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/COPYING")
SET(CPACK_PACKAGE_VERSION_MAJOR ${PACKAGE_VERSION_MAJOR})
SET(CPACK_PACKAGE_VERSION_MINOR ${PACKAGE_VERSION_MINOR})
SET(CPACK_PACKAGE_VERSION_PATCH ${PACKAGE_VERSION_PATCH})
SET(CPACK_SOURCE_PACKAGE_FILE_NAME ${PACKAGE_NAME}-${PACKAGE_VERSION})
SET(CPACK_GENERATOR "TGZ")
SET(CPACK_SOURCE_GENERATOR "TGZ")
SET(CPACK_SOURCE_IGNORE_FILES
  ".a$"
  ".cmake$"
  ".o$"
  ".so$"
  "/.deps/"
  "/.libs/"
  "/CMakeFiles/"
  "/CVS/"
  "/autom4te.cache/"
  "/build"
  "/broken"
  "/docs/"
  "AdditionalInfo.txt$"
  "CMakeCache.txt$"
  "Makefile$"
  "\\\\.sh$"
  "_CPack_"
  "config.h$"
  "config.log$"
  "config.status$"
  "dccsend$"
  "dccserver$"
  "html$"
  "install_manifest.txt$"
  "stamp-h1$"
  "tar.bz2"
  "tar.gz"
  "~$"
)
SET(CPACK_SOURCE_STRIP_FILES "")
INCLUDE(CPack)

# write out config file
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/cmake-config.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/config.h)
