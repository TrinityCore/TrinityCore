target_compile_definitions(trinity-compile-option-interface
  INTERFACE
    _WIN32_WINNT=0x0A00                     # Windows 10
    NTDDI_VERSION=0x0A000007                # 19H1 (1903)
    WIN32_LEAN_AND_MEAN
    NOMINMAX
    TRINITY_REQUIRED_WINDOWS_BUILD=18362)

# set up output paths for executable binaries (.exe-files, and .dll-files on DLL-capable platforms)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/$<CONFIG>")
