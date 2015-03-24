include(CheckCXXCompilerFlag)
include(CheckSymbolExists)

set(FMT_SOURCES format.cc format.h)

# Use variadic templates
add_definitions(-DFMT_VARIADIC_TEMPLATES=1)

# Check if initializer lists are supported.
check_cxx_source_compiles("
  #include <initializer_list>
  int main() {}" FMT_INITIALIZER_LIST)

# Use delete
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
  set(FMT_SOURCES ${FMT_SOURCES} posix.cc posix.h)
endif ()

add_library(format STATIC ${FMT_SOURCES})

if (CMAKE_COMPILER_IS_GNUCXX)
  set_target_properties(format PROPERTIES COMPILE_FLAGS
    "-Wall -Wextra -Wshadow -pedantic")
endif ()
