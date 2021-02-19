# Set build-directive (used in core to tell which buildtype we used)
target_compile_definitions(trinity-compile-option-interface
  INTERFACE
    -D_BUILD_DIRECTIVE="$<CONFIG>")

set(CLANG_EXPECTED_VERSION 7.0.0)

if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS CLANG_EXPECTED_VERSION)
  message(FATAL_ERROR "Clang: TrinityCore requires version ${CLANG_EXPECTED_VERSION} to build but found ${CMAKE_CXX_COMPILER_VERSION}")
else()
  message(STATUS "Clang: Minimum version required is ${CLANG_EXPECTED_VERSION}, found ${CMAKE_CXX_COMPILER_VERSION} - ok!")
endif()

# This tests for a bug in clang-7 that causes linkage to fail for 64-bit from_chars (in some configurations)
# If the clang requirement is bumped to >= clang-8, you can remove this check, as well as
# the associated ifdef block in src/common/Utilities/StringConvert.h
include(CheckCXXSourceCompiles)

check_cxx_source_compiles("
#include <charconv>
#include <cstdint>

int main()
{
    uint64_t n;
    char const c[] = \"0\";
    std::from_chars(c, c+1, n);
    return static_cast<int>(n);
}
" CLANG_HAVE_PROPER_CHARCONV)

if (NOT CLANG_HAVE_PROPER_CHARCONV)
  message(STATUS "Clang: Detected from_chars bug for 64-bit integers, workaround enabled")
  target_compile_definitions(trinity-compile-option-interface
  INTERFACE
    -DTRINITY_NEED_CHARCONV_WORKAROUND)
endif()

if(WITH_WARNINGS)
  target_compile_options(trinity-warning-interface
    INTERFACE
      -W
      -Wall
      -Wextra
      -Wimplicit-fallthrough
      -Winit-self
      -Wfatal-errors
      -Wno-mismatched-tags
      -Woverloaded-virtual)

  message(STATUS "Clang: All warnings enabled")
endif()

if(WITH_COREDEBUG)
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      -g3)

  message(STATUS "Clang: Debug-flags set (-g3)")
endif()

if(ASAN)
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      -fno-omit-frame-pointer
      -fsanitize=address
      -fsanitize-recover=address
      -fsanitize-address-use-after-scope)

  target_link_options(trinity-compile-option-interface
    INTERFACE
      -fno-omit-frame-pointer
      -fsanitize=address
      -fsanitize-recover=address
      -fsanitize-address-use-after-scope)

  message(STATUS "Clang: Enabled Address Sanitizer ASan")
endif()

if(MSAN)
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      -fno-omit-frame-pointer
      -fsanitize=memory
      -fsanitize-memory-track-origins
      -mllvm
      -msan-keep-going=1)

  target_link_options(trinity-compile-option-interface
    INTERFACE
      -fno-omit-frame-pointer
      -fsanitize=memory
      -fsanitize-memory-track-origins)

  message(STATUS "Clang: Enabled Memory Sanitizer MSan")
endif()

if(UBSAN)
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      -fno-omit-frame-pointer
      -fsanitize=undefined)

  target_link_options(trinity-compile-option-interface
    INTERFACE
      -fno-omit-frame-pointer
      -fsanitize=undefined)

  message(STATUS "Clang: Enabled Undefined Behavior Sanitizer UBSan")
endif()

if(TSAN)
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      -fno-omit-frame-pointer
      -fsanitize=thread)

  target_link_options(trinity-compile-option-interface
    INTERFACE
      -fno-omit-frame-pointer
      -fsanitize=thread)

  message(STATUS "Clang: Enabled Thread Sanitizer TSan")
endif()

# -Wno-narrowing needed to suppress a warning in g3d
# -Wno-deprecated-register is needed to suppress 185 gsoap warnings on Unix systems.
# -Wno-deprecated-copy needed to suppress a warning in g3d
target_compile_options(trinity-compile-option-interface
  INTERFACE
    -Wno-narrowing
    -Wno-deprecated-register)

if(BUILD_SHARED_LIBS)
  # -fPIC is needed to allow static linking in shared libs.
  # -fvisibility=hidden sets the default visibility to hidden to prevent exporting of all symbols.
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      -fPIC)

  target_compile_options(trinity-hidden-symbols-interface
    INTERFACE
      -fvisibility=hidden)

  # --no-undefined to throw errors when there are undefined symbols
  # (caused through missing TRINITY_*_API macros).
  set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} --no-undefined")

  message(STATUS "Clang: Disallow undefined symbols")
endif()
