# set up output paths for executable binaries (.exe-files, and .dll-files on DLL-capable platforms)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Set build-directive (used in core to tell which buildtype we used)
target_compile_definitions(trinity-compile-option-interface
  INTERFACE
    -D_BUILD_DIRECTIVE="$<CONFIG>")

if(PLATFORM EQUAL 32)
  # Required on 32-bit systems to enable SSE2 (standard on x64)
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      -msse2
      -mfpmath=sse)
endif()
target_compile_definitions(trinity-compile-option-interface
  INTERFACE
    -DHAVE_SSE2
    -D__SSE2__)
message(STATUS "GCC: SFMT enabled, SSE2 flags forced")

if( WITH_WARNINGS )
  target_compile_options(trinity-warning-interface
    INTERFACE
      -W
      -Wall
      -Wextra
      -Winit-self
      -Winvalid-pch
      -Wfatal-errors
      -Woverloaded-virtual)

  message(STATUS "GCC: All warnings enabled")
endif()

if( WITH_COREDEBUG )
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      -g3)

  message(STATUS "GCC: Debug-flags set (-g3)")
endif()
