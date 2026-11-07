if(PLATFORM EQUAL 32)
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      -axSSE2)
else()
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      -xSSE2)
endif()

if(WITH_WARNINGS)
  target_compile_options(trinity-warning-interface
    INTERFACE
      -w1)

  message(STATUS "ICC: All warnings enabled")
endif()

if(WITH_COREDEBUG)
  target_compile_options(trinity-compile-option-interface
    INTERFACE
      -g)
  message(STATUS "ICC: Debug-flag set (-g)")
endif()
