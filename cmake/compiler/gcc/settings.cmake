add_definitions(-fno-delete-null-pointer-checks)

if( USE_SFMT)
  add_definitions(-msse2)
endif()

if( WITH_WARNINGS )
  add_definitions(-Wall -Wfatal-errors -Wextra)
else()
  add_definitions(--no-warnings)
endif()

if( WITH_COREDEBUG )
  add_definitions(-ggdb3)
endif()
