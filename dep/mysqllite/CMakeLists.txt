# Copyright (C) 2006 MySQL AB
# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(COMPILATION_COMMENT "Source distribution lite for Trinity Core")
set(PROTOCOL_VERSION "10")
set(DOT_FRM_VERSION "6")
set(MYSQL_TCP_PORT_DEFAULT "0")
set(MYSQL_TCP_PORT "3306")
set(MYSQL_UNIX_ADDR "/tmp/mysql.sock")
set(VERSION "5.1.50")
set(MYSQL_BASE_VERSION "5.1")
set(MYSQL_VERSION_ID "50150")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/mysql_version.h.in
               ${CMAKE_BINARY_DIR}/mysql_version.h @ONLY)

include_directories(
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/dep/zlib
  ${CMAKE_CURRENT_SOURCE_DIR}/include 
  ${CMAKE_CURRENT_SOURCE_DIR}/libmysql
  ${CMAKE_CURRENT_SOURCE_DIR}/sql
  ${CMAKE_CURRENT_SOURCE_DIR}/strings
  ${CMAKE_CURRENT_SOURCE_DIR}/dbug
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/mySTL
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/include
)

# FIXME only needed if build type is "Debug", but CMAKE_BUILD_TYPE is not set during configure time.
set(DBUG_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/dbug/dbug.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/dbug/factorial.c
  ${CMAKE_CURRENT_SOURCE_DIR}/dbug/sanity.c
)
                 
set(TAOCRYPT_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/aes.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/aestables.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/algebra.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/arc4.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/asn.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/coding.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/des.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/dh.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/dsa.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/file.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/hash.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/integer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/md2.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/md4.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/md5.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/misc.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/random.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/ripemd.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/rsa.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/src/sha.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/aes.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/algebra.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/arc4.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/asn.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/block.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/coding.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/des.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/dh.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/dsa.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/dsa.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/error.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/file.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/hash.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/hmac.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/integer.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/md2.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/md5.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/misc.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/modarith.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/modes.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/random.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/ripemd.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/rsa.hpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/taocrypt/include/sha.hpp
)

set(YASSL_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/src/buffer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/src/cert_wrapper.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/src/crypto_wrapper.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/src/handshake.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/src/lock.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/src/log.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/src/socket_wrapper.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/src/ssl.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/src/timer.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/src/yassl_error.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/src/yassl_imp.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/extra/yassl/src/yassl_int.cpp
) 

set(LIB_SOURCES
  ${DBUG_SOURCES}
  ${TAOCRYPT_SOURCES}
  ${YASSL_SOURCES}
)

set(CLIENT_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/libmysql/errmsg.c
  ${CMAKE_CURRENT_SOURCE_DIR}/libmysql/get_password.c
  ${CMAKE_CURRENT_SOURCE_DIR}/libmysql/libmysql.c
  ${CMAKE_CURRENT_SOURCE_DIR}/libmysql/manager.c
  ${CMAKE_CURRENT_SOURCE_DIR}/libmysql/dll.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/array.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/default.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/errors.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/hash.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_sleep.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/default_modify.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/charset-def.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/charset.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/list.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_arr_appstr.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_cache.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_dirname.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_fn_ext.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_format.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_iocache.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_iocache2.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_loadpath.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_pack.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_path.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_tempfile.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_unixpath.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_wcomp.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mulalloc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_access.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_alloc.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_chsize.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_compress.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_create.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_delete.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_div.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_error.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_file.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_fopen.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_fstream.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_gethostbyname.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_getopt.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_getwd.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_init.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_lib.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_malloc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_messnc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_net.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_once.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_open.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_pread.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_pthread.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_read.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_realloc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_rename.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_seek.c  
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_static.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_symlink.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_symlink2.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_thr_init.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_wincond.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_winthread.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_write.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/safemalloc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/sha1.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/string.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/thr_mutex.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/typelib.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/mf_qsort.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_getsystime.c
  ${CMAKE_CURRENT_SOURCE_DIR}/mysys/my_sync.c
  ${CMAKE_CURRENT_SOURCE_DIR}/sql-common/client.c
  ${CMAKE_CURRENT_SOURCE_DIR}/sql-common/my_time.c
  ${CMAKE_CURRENT_SOURCE_DIR}/sql-common/pack.c
  ${CMAKE_CURRENT_SOURCE_DIR}/sql/net_serv.cc
  ${CMAKE_CURRENT_SOURCE_DIR}/sql/password.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/bchange.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/bmove.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/bmove_upp.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-big5.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-bin.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-cp932.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-czech.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-euc_kr.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-eucjpms.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-extra.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-gb2312.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-gbk.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-latin1.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-mb.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-simple.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-sjis.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-tis620.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-uca.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-ucs2.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-ujis.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-utf8.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype-win1250ch.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/ctype.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/int2str.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/is_prefix.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/llstr.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/longlong2str.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strinstr.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strmake.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strmov.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strnlen.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strnmov.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strtod.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strtoll.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strtoull.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strxmov.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strxnmov.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/my_strtoll10.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/my_vsnprintf.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/str2int.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/str_alloc.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strcend.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strcont.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strend.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/strfill.c
  ${CMAKE_CURRENT_SOURCE_DIR}/strings/xml.c
  ${CMAKE_CURRENT_SOURCE_DIR}/vio/vio.c
  ${CMAKE_CURRENT_SOURCE_DIR}/vio/viosocket.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/vio/viossl.c
  ${CMAKE_CURRENT_SOURCE_DIR}/vio/viosslfactories.c
  ${LIB_SOURCES}
)

add_library(libmysql SHARED ${CLIENT_SOURCES} libmysql/libmysql.def)

# Need to set USE_TLS for building the DLL, since __declspec(thread)
# approach to thread local storage does not work properly in DLLs.
set(mysql_COMPILE_DEFINITIONS 
  USE_TLS
  HAVE_YASSL
  YASSL_THREAD_SAFE
  YASSL_PREFIX
  CMAKE_CONFIGD
  DEFAULT_BASEDIR="c:/Program Files/MySQL/"
  DEFAULT_CHARSET_HOME="c:/Program Files/MySQL/MySQL Server ${MYSQL_BASE_VERSION}/"
  PACKAGE="mysql"
  SHAREDIR="share"
  __NT__
)

if(ENABLED_DEBUG_SYNC)
  set(mysql_COMPILE_DEFINITIONS ${mysql_COMPILE_DEFINITIONS} ENABLED_DEBUG_SYNC)
endif(ENABLED_DEBUG_SYNC)

if(EXTRA_DEBUG)
  set(mysql_COMPILE_DEFINITIONS ${mysql_COMPILE_DEFINITIONS} EXTRA_DEBUG)
endif(EXTRA_DEBUG)

set(mysql_COMPILE_DEFINITIONS_DEBUG
  FORCE_INIT_OF_VARS
  SAFEMALLOC
  SAFE_MUTEX
  ENABLED_DEBUG_SYNC
)

set_target_properties(libmysql PROPERTIES COMPILE_DEFINITIONS "${mysql_COMPILE_DEFINITIONS}")
set_target_properties(libmysql PROPERTIES COMPILE_DEFINITIONS_DEBUG "${mysql_COMPILE_DEFINITIONS_DEBUG}")
set_target_properties(libmysql PROPERTIES COMPILE_DEFINITIONS_RELEASE DBUG_OFF)
set_target_properties(libmysql PROPERTIES COMPILE_DEFINITIONS_RELWITHDEBINFO DBUG_OFF)
set_target_properties(libmysql PROPERTIES COMPILE_DEFINITIONS_MINSIZEREL DBUG_OFF)

target_link_libraries(libmysql ${ZLIB_LIBRARIES} wsock32)

install(TARGETS libmysql RUNTIME DESTINATION "${CMAKE_INSTALL_PREFIX}")