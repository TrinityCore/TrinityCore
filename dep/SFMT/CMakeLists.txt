# Copyright 2019 Josua Mayer <josua.mayer97@gmail.com>

# add library
set(sfmt_SOURCES
SFMT.c
SFMT-alti.h
SFMT-common.h
SFMT-neon.h
SFMT-params607.h
SFMT-params1279.h
SFMT-params2281.h
SFMT-params4253.h
SFMT-params11213.h
SFMT-params19937.h
SFMT-params44497.h
SFMT-params86243.h
SFMT-params132049.h
SFMT-params216091.h
SFMT-params.h
SFMT-sse2-msc.h
SFMT-sse2.h
SFMT.h
)
add_library(sfmt STATIC ${sfmt_SOURCES})

# add self to header search path
target_include_directories(sfmt INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

# choose Mersenne exponent
target_compile_definitions(sfmt PUBLIC -DSFMT_MEXP=11213)

# enable SIMD instructions if available
include(CheckCCompilerFlag)
if(CMAKE_SYSTEM_PROCESSOR MATCHES "(powerpc|ppc)64|(powerpc|ppc)64le")
    check_c_compiler_flag("-maltivec" HAVE_ALTIVEC)
    if(HAVE_ALTIVEC)
        target_compile_options(sfmt PRIVATE -mabi=altivec -maltivec)
        target_compile_definitions(sfmt PUBLIC -DHAVE_ALTIVEC)
    else()
        message(WARNING "Altivec not available - performance will be poor!")
    endif()
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "arm|ARM")
    check_c_compiler_flag(-mfpu=neon HAVE_NEON)
    if(HAVE_NEON)
        target_compile_options(sfmt PRIVATE -mfpu=neon -ftree-vectorize)
        target_compile_definitions(sfmt PUBLIC -DHAVE_NEON)
    else()
        message(WARNING "Neon not available - performance will be poor!")
    endif()
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "aarch64|AARCH64")
    check_c_compiler_flag(-march=armv8-a+simd HAVE_NEON)
    if(HAVE_NEON)
        target_compile_options(sfmt PRIVATE -ftree-vectorize)
        target_compile_definitions(sfmt PUBLIC -DHAVE_NEON)
    else()
        message(WARNING "Neon not available - performance will be poor!")
    endif()
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "i686|amd64|x86_64|AMD64" AND CMAKE_C_COMPILER_ID MATCHES "MSVC")
    check_c_compiler_flag(/arch:SSE2 HAVE_SSE2)
    if(HAVE_SSE2)
        target_compile_options(sfmt PRIVATE /arch:SSE2)
        target_compile_definitions(sfmt PUBLIC -DHAVE_SSE2)
    else()
        message(WARNING "SSE2 not available - performance will be poor!")
    endif()
elseif(CMAKE_SYSTEM_PROCESSOR MATCHES "i686|amd64|x86_64|AMD64")
    check_c_compiler_flag(-msse2 HAVE_SSE2)
    if(HAVE_SSE2)
        target_compile_options(sfmt PRIVATE -msse2)
        target_compile_definitions(sfmt PUBLIC -DHAVE_SSE2)
    else()
        message(WARNING "SSE2 not available - performance will be poor!")
    endif()
endif()

# inherit trinitycore generic build options (e.g. fPIC)
target_link_libraries(sfmt PRIVATE trinity-dependency-interface)
