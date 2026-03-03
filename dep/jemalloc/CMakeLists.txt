# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

include(CheckCSourceCompiles)
include(CheckFunctionExists)
include(CheckSymbolExists)

if(CMAKE_CXX_BYTE_ORDER STREQUAL "BIG_ENDIAN")
  set(JEMALLOC_BIG_ENDIAN)
endif()

try_run(JEMALLOC_SYSTEM_INFO_DETECTED JEMALLOC_SYSTEM_INFO_COMPILED ${CMAKE_BINARY_DIR}
  SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/Configure.c"
  RUN_OUTPUT_VARIABLE JEMALLOC_SYSTEM_INFO_RUN_OUTPUT
)

string(JSON LG_SIZEOF_PTR GET "${JEMALLOC_SYSTEM_INFO_RUN_OUTPUT}" "LG_SIZEOF_PTR")
string(JSON LG_SIZEOF_INT GET "${JEMALLOC_SYSTEM_INFO_RUN_OUTPUT}" "LG_SIZEOF_INT")
string(JSON LG_SIZEOF_LONG GET "${JEMALLOC_SYSTEM_INFO_RUN_OUTPUT}" "LG_SIZEOF_LONG")
string(JSON LG_SIZEOF_LONG_LONG GET "${JEMALLOC_SYSTEM_INFO_RUN_OUTPUT}" "LG_SIZEOF_LONG_LONG")
string(JSON LG_SIZEOF_INTMAX_T GET "${JEMALLOC_SYSTEM_INFO_RUN_OUTPUT}" "LG_SIZEOF_INTMAX_T")
string(JSON LG_VADDR GET "${JEMALLOC_SYSTEM_INFO_RUN_OUTPUT}" "LG_VADDR")
string(JSON LG_PAGE GET "${JEMALLOC_SYSTEM_INFO_RUN_OUTPUT}" "LG_PAGE")
set(LG_HUGEPAGE 21)

set(HAVE_CPU_SPINWAIT 1)
if(TRINITY_SYSTEM_PROCESSOR MATCHES "arm")
  if(MSVC)
    set(CPU_SPINWAIT "__isb(_ARM64_BARRIER_SY)")
  else()
    set(CPU_SPINWAIT "__asm__ volatile\(\"isb\"\)")
  endif()
else()
  if(MSVC)
    set(CPU_SPINWAIT "_mm_pause()")
  else()
    set(CPU_SPINWAIT "__asm__ volatile\(\"pause\"\)")
  endif()
endif()

# git describe --long --abbrev=40
set(JEMALLOC_VERSION "5.3.0-0-g54eaed1d8b56b1aa528be3bdd1877e59c56fa90c")
set(JEMALLOC_VERSION_MAJOR 5)
set(JEMALLOC_VERSION_MINOR 3)
set(JEMALLOC_VERSION_BUGFIX 0)
set(JEMALLOC_VERSION_NREV 0)
set(JEMALLOC_VERSION_GID "54eaed1d8b56b1aa528be3bdd1877e59c56fa90c")
set(JEMALLOC_VERSION_GID_IDENT 54eaed1d8b56b1aa528be3bdd1877e59c56fa90c)

set(JEMALLOC_MAPS_COALESCE 1)
set(JEMALLOC_TLS 1)
set(SYM_PREFIX "")
set(JEMALLOC_EXTRA_DEFINES "-D_REENTRANT")
set(JEMALLOC_INTERNAL_UNREACHABLE "__builtin_unreachable()")
if(APPLE)
  set(SYM_PREFIX "_")
  set(JEMALLOC_HAVE_VM_MAKE_TAG 1)
  set(JEMALLOC_OS_UNFAIR_LOCK 1)
  set(JEMALLOC_PREFIX "je_")
  set(JEMALLOC_ZONE 1)
  unset(JEMALLOC_TLS)
  check_symbol_exists(mach_absolute_time "mach/mach_time.h" JEMALLOC_HAVE_MACH_ABSOLUTE_TIME)
elseif(CMAKE_SYSTEM_NAME STREQUAL "OpenBSD")
  set(JEMALLOC_DSS 1)
  unset(JEMALLOC_TLS)
elseif(CMAKE_SYSTEM_NAME STREQUAL "FreeBSD")
  set(JEMALLOC_DSS 1)
  set(JEMALLOC_SYSCTL_VM_OVERCOMMIT)
  set(JEMALLOC_EXTRA_DEFINES "${JEMALLOC_EXTRA_DEFINES} -D_BSD_SOURCE")
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
  set(JEMALLOC_DSS 1)
  set(JEMALLOC_HAS_ALLOCA_H 1)
  set(JEMALLOC_PROC_SYS_VM_OVERCOMMIT_MEMORY 1)
  set(JEMALLOC_PURGE_MADVISE_DONTNEED_ZEROS 1)
  set(JEMALLOC_THREADED_INIT 1)
  set(JEMALLOC_USE_CXX_THROW 1)
  set(JEMALLOC_ZERO_REALLOC_DEFAULT_FREE 1)
  set(JEMALLOC_EXTRA_DEFINES "${JEMALLOC_EXTRA_DEFINES} -D_GNU_SOURCE")
  if(LG_SIZEOF_PTR STREQUAL "3")
    set(JEMALLOC_RETAIN 1)
  endif()
elseif(CMAKE_SYSTEM_NAME MATCHES "^Windows")
  unset(JEMALLOC_MAPS_COALESCE)
  unset(JEMALLOC_TLS)
  set(JEMALLOC_INTERNAL_UNREACHABLE "__assume(false)")
  set(JEMALLOC_PREFIX "je_")
  set(JEMALLOC_ZERO_REALLOC_DEFAULT_FREE 1)
  if(LG_SIZEOF_PTR STREQUAL "3")
    set(JEMALLOC_RETAIN 1)
  endif()
endif()

check_c_source_compiles("
#include <malloc.h>
#include <stddef.h>
size_t malloc_usable_size(const void *ptr);
" JEMALLOC_USABLE_SIZE_CONST)

if(JEMALLOC_USABLE_SIZE_CONST)
  set(JEMALLOC_USABLE_SIZE_CONST "const")
else()
  set(JEMALLOC_USABLE_SIZE_CONST "")
endif()

if(NOT MSVC)
  set(JEMALLOC_GCC_ATOMIC_ATOMICS 1)
  set(JEMALLOC_GCC_U8_ATOMIC_ATOMICS 1) # don't bother detecting atomic support, all TC-supported compilers (excluding msvc) have gcc-like atomics
  set(JEMALLOC_HAVE_ATTR 1)
  set(JEMALLOC_TLS_MODEL "__attribute__\(\(tls_model\(\"initial-exec\"\)\)\)")
  set(JEMALLOC_HAVE_ATTR_FORMAT_GNU_PRINTF 1)
  set(JEMALLOC_HAVE_ATTR_FORMAT_PRINTF 1)
  set(JEMALLOC_HAVE_ATTR_FORMAT_ARG 1)
  set(JEMALLOC_HAVE_ATTR_FALLTHROUGH 1)
  set(JEMALLOC_HAVE_ATTR_COLD 1)
  set(JEMALLOC_HAVE_BUILTIN_CLZ 1)
  set(JEMALLOC_INTERNAL_FFS "__builtin_ffs")
  set(JEMALLOC_INTERNAL_FFSL "__builtin_ffsl")
  set(JEMALLOC_INTERNAL_FFSLL "__builtin_ffsll")
  set(JEMALLOC_INTERNAL_POPCOUNT "__builtin_popcount")
  set(JEMALLOC_INTERNAL_POPCOUNTL "__builtin_popcountl")
  set(JEMALLOC_INTERNAL_POPCOUNTLL "__builtin_popcountll")
else()
  set(JEMALLOC_INTERNAL_FFS "ffs")
  set(JEMALLOC_INTERNAL_FFSL "ffsl")
  set(JEMALLOC_INTERNAL_FFSLL "ffsll")
  set(JEMALLOC_INTERNAL_POPCOUNT "__popcnt")
  set(JEMALLOC_INTERNAL_POPCOUNTL "__popcnt")
  set(JEMALLOC_INTERNAL_POPCOUNTLL "__popcnt64")
endif()

if(NOT JEMALLOC_PREFIX)
  set(JEMALLOC_IS_MALLOC 1)
else()
  string(TOUPPER "${JEMALLOC_PREFIX}" JEMALLOC_CPREFIX)
endif()

set(JEMALLOC_CACHE_OBLIVIOUS 1)
set(JEMALLOC_CONFIG_MALLOC_CONF "")
set(JEMALLOC_C11_ATOMICS 1)
set(JEMALLOC_ENABLE_CXX 1)
set(JEMALLOC_FILL 1)
set(JEMALLOC_PRIVATE_NAMESPACE "je_")
set(JEMALLOC_STATS 1)
unset(JEMALLOC_LOG)
unset(JEMALLOC_OPT_SAFETY_CHECKS)
unset(JEMALLOC_OPT_SIZE_CHECKS)
unset(JEMALLOC_READLINKAT)
unset(JEMALLOC_UAF_DETECTION)
unset(JEMALLOC_UTRACE)
unset(JEMALLOC_UTRACE_LABEL)
unset(JEMALLOC_XMALLOC)

set(CMAKE_REQUIRED_DEFINITIONS ${JEMALLOC_EXTRA_DEFINES})

check_symbol_exists(memalign "malloc.h" JEMALLOC_OVERRIDE_MEMALIGN)
check_symbol_exists(valloc "stdlib.h" JEMALLOC_OVERRIDE_VALLOC)
check_symbol_exists(malloc_size "malloc/malloc.h" JEMALLOC_HAVE_MALLOC_SIZE)

set(wrap_syms "")
if(NOT JEMALLOC_PREFIX)
  check_function_exists(__libc_calloc JEMALLOC_OVERRIDE___LIBC_CALLOC)
  if(JEMALLOC_OVERRIDE___LIBC_CALLOC)
    list(APPEND wrap_syms "__libc_calloc")
  endif()
  check_function_exists(__libc_free JEMALLOC_OVERRIDE___LIBC_FREE)
  if(JEMALLOC_OVERRIDE___LIBC_FREE)
    list(APPEND wrap_syms "__libc_free")
  endif()
  check_function_exists(__libc_malloc JEMALLOC_OVERRIDE___LIBC_MALLOC)
  if(JEMALLOC_OVERRIDE___LIBC_MALLOC)
    list(APPEND wrap_syms "__libc_malloc")
  endif()
  check_function_exists(__libc_memalign JEMALLOC_OVERRIDE___LIBC_MEMALIGN)
  if(JEMALLOC_OVERRIDE___LIBC_MEMALIGN)
    list(APPEND wrap_syms "__libc_memalign")
  endif()
  check_function_exists(__libc_realloc JEMALLOC_OVERRIDE___LIBC_REALLOC)
  if(JEMALLOC_OVERRIDE___LIBC_REALLOC)
    list(APPEND wrap_syms "__libc_realloc")
  endif()
  check_function_exists(__libc_valloc JEMALLOC_OVERRIDE___LIBC_VALLOC)
  if(JEMALLOC_OVERRIDE___LIBC_VALLOC)
    list(APPEND wrap_syms "__libc_valloc")
  endif()
  check_function_exists(__posix_memalign JEMALLOC_OVERRIDE___POSIX_MEMALIGN)
  if(JEMALLOC_OVERRIDE___POSIX_MEMALIGN)
    list(APPEND wrap_syms "__posix_memalign")
  endif()
endif()

if(NOT WIN32)
  set(JEMALLOC_HAVE_DLSYM 1)
  set(JEMALLOC_HAVE_PTHREAD 1)
  list(APPEND wrap_syms "pthread_create")

  check_symbol_exists(pthread_atfork "pthread.h" JEMALLOC_HAVE_PTHREAD_ATFORK)
  check_symbol_exists(pthread_setname_np "pthread.h" JEMALLOC_HAVE_PTHREAD_SETNAME_NP)
  check_symbol_exists(pthread_getname_np "pthread.h" JEMALLOC_HAVE_PTHREAD_GETNAME_NP)
  check_symbol_exists(pthread_get_name_np "pthread.h" JEMALLOC_HAVE_PTHREAD_GET_NAME_NP)
  check_c_source_compiles("
  #include <pthread.h>
  int main()
  {
    pthread_mutexattr_t attr;
    pthread_mutexattr_init(&attr);
    pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_ADAPTIVE_NP);
    pthread_mutexattr_destroy(&attr);
  }
  " JEMALLOC_HAVE_PTHREAD_MUTEX_ADAPTIVE_NP)
  check_symbol_exists(CLOCK_MONOTONIC_COARSE "time.h" JEMALLOC_HAVE_CLOCK_MONOTONIC_COARSE)
  check_symbol_exists(CLOCK_MONOTONIC "time.h" JEMALLOC_HAVE_CLOCK_MONOTONIC)
  check_symbol_exists(CLOCK_REALTIME "time.h" JEMALLOC_HAVE_CLOCK_REALTIME)

  set(CMAKE_REQUIRED_FLAGS "-Werror")
  check_c_source_compiles("
  #include <sys/syscall.h>
  #include <unistd.h>
  int main() { syscall(SYS_write, 2, \"hello\", 5); }
  " JEMALLOC_USE_SYSCALL)
  unset(CMAKE_REQUIRED_FLAGS)

  check_symbol_exists(secure_getenv "stdlib.h" JEMALLOC_HAVE_SECURE_GETENV)
  check_symbol_exists(sched_getcpu "sched.h" JEMALLOC_HAVE_SCHED_GETCPU)
  check_symbol_exists(sched_setaffinity "sched.h" JEMALLOC_HAVE_SCHED_SETAFFINITY)
  check_symbol_exists(issetugid "unistd.h" JEMALLOC_HAVE_ISSETUGID)
  check_symbol_exists(_malloc_thread_cleanup "pthread.h" JEMALLOC_MALLOC_THREAD_CLEANUP)
  if(JEMALLOC_MALLOC_THREAD_CLEANUP)
    list(APPEND wrap_syms "_malloc_thread_cleanup")
    list(APPEND wrap_syms "_malloc_tsd_cleanup_register")
    set(JEMALLOC_TLS 1)
  endif()

  check_symbol_exists(_pthread_mutex_init_calloc_cb "pthread.h" JEMALLOC_MUTEX_INIT_CB)
  if(JEMALLOC_MUTEX_INIT_CB)
    list(APPEND wrap_syms "_malloc_prefork")
    list(APPEND wrap_syms "_malloc_postfork")
  endif()

  check_symbol_exists(memcntl "sys/types.h;sys/mman.h" JEMALLOC_HAVE_MEMCNTL)
  check_symbol_exists(madvise "sys/mman.h" JEMALLOC_HAVE_MADVISE)
  if(JEMALLOC_HAVE_MADVISE)
    check_symbol_exists(MADV_FREE "sys/mman.h" JEMALLOC_PURGE_MADVISE_FREE)
    if(NOT JEMALLOC_PURGE_MADVISE_FREE AND CMAKE_SYSTEM_NAME STREQUAL "Linux" AND TRINITY_SYSTEM_PROCESSOR MATCHES "x86|amd64")
      set(JEMALLOC_PURGE_MADVISE_FREE 1)
      set(JEMALLOC_DEFINE_MADVISE_FREE 1)
    endif()
    check_symbol_exists(MADV_DONTNEED "sys/mman.h" JEMALLOC_PURGE_MADVISE_DONTNEED)
    check_symbol_exists(MADV_DONTDUMP "sys/mman.h" JEMALLOC_MADVISE_DONTDUMP)
    check_symbol_exists(MADV_NOCORE "sys/mman.h" JEMALLOC_MADVISE_NOCORE)
    if(TRINITY_SYSTEM_PROCESSOR MATCHES "x86|amd64")
      check_symbol_exists(MADV_HUGEPAGE "sys/mman.h" JEMALLOC_HAVE_MADVISE_HUGE)
    endif()
  else()
    check_symbol_exists(posix_madvise "sys/mman.h" JEMALLOC_HAVE_POSIX_MADVISE)
    if(JEMALLOC_HAVE_POSIX_MADVISE)
      check_symbol_exists(POSIX_MADV_DONTNEED "sys/mman.h" JEMALLOC_PURGE_POSIX_MADVISE_DONTNEED)
    endif()
  endif()

  check_symbol_exists(mprotect "sys/mman.h" JEMALLOC_HAVE_MPROTECT)
  if(NOT APPLE)
    set(JEMALLOC_BACKGROUND_THREAD 1)
  endif()

  set(CMAKE_REQUIRED_FLAGS "-Werror")
  check_c_source_compiles("
  #include <errno.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  int main()
  {
    char *buffer = (char *) malloc(100);
    char *error = strerror_r(EINVAL, buffer, 100);
    printf(\"%s\", error);
  }
  " JEMALLOC_STRERROR_R_RETURNS_CHAR_WITH_GNU_SOURCE)
  unset(CMAKE_REQUIRED_FLAGS)
endif()

unset(CMAKE_REQUIRED_DEFINITIONS)

set(je_ "je_")

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/include/jemalloc/jemalloc.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/jemalloc/jemalloc.h
  @ONLY
)

configure_file(
  ${CMAKE_CURRENT_SOURCE_DIR}/include/jemalloc/internal/jemalloc_internal_defs.h.in
  ${CMAKE_CURRENT_BINARY_DIR}/include/jemalloc/internal/jemalloc_internal_defs.h
  @ONLY
)

add_library(jemalloc STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/src/jemalloc.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/arena.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/background_thread.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/base.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/bin.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/bin_info.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/bitmap.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/buf_writer.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/cache_bin.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ckh.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/counter.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ctl.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/decay.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/div.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ecache.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/edata.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/edata_cache.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ehooks.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/emap.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/eset.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/exp_grow.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/extent.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/extent_dss.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/extent_mmap.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/fxp.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/san.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/san_bump.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/hook.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/hpa.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/hpa_hooks.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/hpdata.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/inspect.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/large.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/log.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/malloc_io.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/mutex.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/nstime.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pa.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pa_extra.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pai.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pac.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/pages.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/peak_event.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/prof.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/prof_data.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/prof_log.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/prof_recent.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/prof_stats.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/prof_sys.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/psset.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/rtree.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/safety_check.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sc.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sec.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/stats.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/sz.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/tcache.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/test_hooks.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/thread_event.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/ticker.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/tsd.c 
  ${CMAKE_CURRENT_SOURCE_DIR}/src/witness.c)

if(APPLE)
  target_sources(jemalloc
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/src/zone.c)
endif()

target_include_directories(jemalloc
  PUBLIC
    ${CMAKE_CURRENT_BINARY_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}/include/jemalloc/internal
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

if(MSVC)
  target_include_directories(jemalloc
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/include/msvc_compat)

  target_compile_definitions(jemalloc
    PRIVATE
      DLLEXPORT)
else()
  target_sources(jemalloc
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/src/jemalloc_cpp.cpp)
endif()

target_compile_definitions(jemalloc
  PRIVATE
    ${JEMALLOC_EXTRA_DEFINES})

target_link_libraries(jemalloc
  PRIVATE
    trinity-dependency-interface
  PUBLIC
    threads
    valgrind
    ${CMAKE_DL_LIBS})

set_target_properties(jemalloc
  PROPERTIES
    FOLDER
      "dep")
