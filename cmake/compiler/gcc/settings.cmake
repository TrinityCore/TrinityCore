add_definitions(-fno-delete-null-pointer-checks)

if( USE_SFMT)
  add_definitions(-msse2)
  message(STATUS "- GCC: SFMT enabled, SSE2 flag forced")
endif()

if( WITH_WARNINGS )
  add_definitions(-Wall -Wfatal-errors -Wextra)
  message(STATUS "- GCC: All warnings enabled")
else()
  add_definitions(--no-warnings)
  message(STATUS "- GCC: All warnings disabled")
endif()

if( WITH_COREDEBUG )
  add_definitions(-ggdb3)
  message(STATUS "- GCC: Debug-flags set (-ggdb3)")
endif()
