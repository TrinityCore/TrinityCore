# Copyright (C) 2006 MySQL AB
# Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# Include the platform-specific file.
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/os/Windows.cmake)

# Add macros
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/character_sets.cmake)
include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/mysql_version.cmake)

# Advanced options (mostly useless, but usually still in config.h, so they need to be set...)
set(CYBOZU OFF)
set(BACKUP_TEST OFF)
set(ENABLED_LOCAL_INFILE ON)
set(WITH_FAST_MUTEXES OFF)

# Handle useful options - hardcode to ON/OFF
set(ENABLED_PROFILING OFF)
set_directory_properties(PROPERTIES COMPILE_DEFINITIONS_DEBUG ENABLED_DEBUG_SYNC)
 
# Set DBUG_OFF and other optional release-only flags for non-debug project types
foreach(BUILD_TYPE RELEASE RELWITHDEBINFO MINSIZEREL)
  set_directory_properties(PROPERTIES COMPILE_DEFINITIONS_${BUILD_TYPE} DBUG_OFF)
  if(WITH_FAST_MUTEXES)
    set_directory_properties(PROPERTIES COMPILE_DEFINITIONS_${BUILD_TYPE} "MY_PTHREAD_FASTMUTEX=1")
  endif()
endforeach()

# Set commonly used variables
set(DEFAULT_MYSQL_HOME "C:/Program Files/MySQL/MySQL Server ${MYSQL_BASE_VERSION}" )
set(SHAREDIR share)
set(DEFAULT_BASEDIR "${DEFAULT_MYSQL_HOME}")
set(MYSQL_DATADIR "${DEFAULT_MYSQL_HOME}/data")
set(DEFAULT_CHARSET_HOME "${DEFAULT_MYSQL_HOME}")
set(PLUGINDIR "${DEFAULT_MYSQL_HOME}/lib/plugin")

set(COMPILATION_COMMENT "Source distribution lite for TrinityCore")

# Run platform tests
include(${CMAKE_CURRENT_SOURCE_DIR}/configure.cmake)

# Use system openssl.
add_definitions(-DHAVE_OPENSSL)

include_directories(
  ${CMAKE_CURRENT_BINARY_DIR}
  ${CMAKE_BINARY_DIR}
  ${OPENSSL_INCLUDE_DIR}
  ${CMAKE_SOURCE_DIR}/dep/zlib
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/internal
  ${CMAKE_CURRENT_SOURCE_DIR}/dbug
  ${CMAKE_CURRENT_SOURCE_DIR}/strings
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys
  ${CMAKE_CURRENT_SOURCE_DIR}/libmysql
)

set(DBUG_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/dbug/dbug.c
)

set(STRINGS_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/bchange.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/bmove_upp.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-big5.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-bin.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-cp932.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-czech.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-euc_kr.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-extra.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-gb2312.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-gbk.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-latin1.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-mb.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-simple.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-tis620.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-uca.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-ucs2.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-utf8.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-win1250ch.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/decimal.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/dtoa.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/int2str.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/is_prefix.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/llstr.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/longlong2str.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/my_strtoll10.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/my_vsnprintf.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/str2int.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/str_alloc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strcend.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strend.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strfill.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strmake.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strmov.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strnmov.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strxmov.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strxnmov.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/xml.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/my_strchr.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strcont.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strappend.c
)
if(NOT HAVE_STRNLEN)
  # OSX does not have strnlen
  set(STRINGS_SOURCES ${STRINGS_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/strings/strnlen.c)
endif()

set(VIO_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/vio/vio.c
  ${CMAKE_CURRENT_SOURCE_DIR}/vio/viosocket.c
  ${CMAKE_CURRENT_SOURCE_DIR}/vio/viossl.c
  ${CMAKE_CURRENT_SOURCE_DIR}/vio/viosslfactories.c
)

set(MYSYS_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/array.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/charset-def.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/charset.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/checksum.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/default.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/errors.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/hash.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/list.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/md5.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_cache.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_dirname.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_fn_ext.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_format.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_getdate.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_iocache.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_iocache2.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_keycache.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_keycaches.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_loadpath.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_pack.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_path.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_qsort.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_qsort2.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_radix.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_same.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_sort.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_soundex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_arr_appstr.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_tempdir.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_tempfile.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_unixpath.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_wcomp.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mulalloc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_access.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_aes.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_alloc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_bit.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_bitmap.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_chsize.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_compress.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_copy.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_create.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_delete.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_div.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_error.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_file.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_fopen.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_fstream.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_gethostbyname.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_gethwaddr.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_getopt.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_getsystime.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_getwd.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_handler.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_init.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_lib.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_lock.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_malloc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_mess.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_mkdir.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_mmap.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_once.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_open.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_pread.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_pthread.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_quick.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_read.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_redel.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_rename.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_seek.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_sleep.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_static.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_symlink.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_symlink2.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_sync.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_thr_init.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_write.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/ptr_cmp.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/queues.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/stacktrace.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/rijndael.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/sha1.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/string.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/thr_alarm.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/thr_lock.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/thr_mutex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/thr_rwlock.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/tree.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/typelib.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/base64.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_memmem.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_getpagesize.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/lf_alloc-pin.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/lf_dynarray.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/lf_hash.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_atomic.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_getncpus.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_rdtsc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_winthread.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_wincond.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_winerr.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_winfile.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_windac.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_conio.c
)
if(HAVE_ALARM)
 set(MYSYS_SOURCES ${MYSYS_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_alarm.c)
endif()
if(HAVE_LARGE_PAGES)
 set(MYSYS_SOURCES ${MYSYS_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_largepage.c)
endif()
if(HAVE_MLOCK)
 set(MYSYS_SOURCES ${MYSYS_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_lockmem.c)
endif()

set(CLIENT_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/libmysql/get_password.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/libmysql/libmysql.c
  ${CMAKE_CURRENT_SOURCE_DIR}/libmysql/errmsg.c
  ${CMAKE_CURRENT_SOURCE_DIR}/sql-common/client.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/sql-common/my_time.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/sql-common/client_plugin.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/sql/net_serv.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/sql-common/pack.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/sql/password.c
)

configure_file(config.h.cmake ${CMAKE_BINARY_DIR}/my_config.h)
configure_file(config.h.cmake ${CMAKE_CURRENT_BINARY_DIR}/config.h)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/internal/mysql_version.h.in ${CMAKE_BINARY_DIR}/mysql_version.h)

add_version_info(libmysql CLIENT_SOURCES)
add_library(libmysql SHARED ${CLIENT_SOURCES} ${DBUG_SOURCES} ${MYSYS_SOURCES} ${STRINGS_SOURCES} ${VIO_SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/libmysql/libmysql_exports.def)
target_link_libraries(libmysql zlib ${OPENSSL_LIBRARIES} ${OPENSSL_EXTRA_LIBRARIES} ws2_32)

install(TARGETS libmysql RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}")
