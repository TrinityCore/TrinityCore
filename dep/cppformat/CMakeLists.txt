include(CheckCXXCompilerFlag)
include(CheckSymbolExists)

set(FMT_SOURCES cppformat/format.cc cppformat/format.h)

# Use variadic templates
add_definitions(-DFMT_VARIADIC_TEMPLATES=1)

# Use deleted functions
add_definitions(-DFMT_USE_DELETED_FUNCTIONS=1)

# Use static assert
add_definitions(-DFMT_USE_STATIC_ASSERT=1)

if (WIN32)
  check_symbol_exists(open io.h HAVE_OPEN)
else ()
  check_symbol_exists(open fcntl.h HAVE_OPEN)
endif ()

if (HAVE_OPEN)
  add_definitions(-DFMT_USE_FILE_DESCRIPTORS=1)
  set(FMT_SOURCES ${FMT_SOURCES} cppformat/posix.cc cppformat/posix.h)
endif ()

add_library(cppformat STATIC ${FMT_SOURCES})

if (CMAKE_COMPILER_IS_GNUCXX)
  set_target_properties(cppformat PROPERTIES COMPILE_FLAGS
    "-Wall -Wextra -Wshadow -pedantic")
endif ()
