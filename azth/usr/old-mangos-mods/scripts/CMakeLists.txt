if (USE_SCRIPTPCH)
  set(hw2scripts_STAT_PCH_HDR precompiledheaders/Hw2ScriptsPCH.h)
  set(hw2scripts_STAT_PCH_SRC precompiledheaders/Hw2ScriptsPCH.cpp)
endif ()


set(hw2scripts_STAT_SRCS
  ${hw2scripts_STAT_SRCS}
  commands/cs_hw2commands.cpp
)

include(../cmake/CMakeIncludeFull.txt)

add_library(hw2scripts STATIC
  ${hw2scripts_STAT_SRCS}
  ${hw2scripts_STAT_PCH_SRC}
)

target_link_libraries(hw2scripts
  hw2shared
)

add_dependencies(hw2scripts revision_data.h)

# Generate precompiled header
if (USE_SCRIPTPCH)
  add_cxx_pch(hw2scripts ${hw2scripts_STAT_PCH_HDR} ${hw2scripts_STAT_PCH_SRC})
endif()

message("  -> Prepared: Hw2Scripts")
