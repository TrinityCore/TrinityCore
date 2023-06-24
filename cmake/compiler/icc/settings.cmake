target_compile_definitions(Kitron-compile-option-interface
  INTERFACE
    -D_BUILD_DIRECTIVE="$<CONFIG>")

if(PLATFORM EQUAL 32)
  target_compile_options(Kitron-compile-option-interface
    INTERFACE
      -axSSE2)
else()
  target_compile_options(Kitron-compile-option-interface
    INTERFACE
      -xSSE2)
endif()

if(WITH_WARNINGS)
  target_compile_options(Kitron-warning-interface
    INTERFACE
      -w1)

  message(STATUS "ICC: All warnings enabled")
endif()

if(WITH_COREDEBUG)
  target_compile_options(Kitron-compile-option-interface
    INTERFACE
      -g)
  message(STATUS "ICC: Debug-flag set (-g)")
endif()
