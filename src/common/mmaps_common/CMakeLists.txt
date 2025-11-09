# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

CollectSourceFiles(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PRIVATE_SOURCES)

GroupSources(${CMAKE_CURRENT_SOURCE_DIR})

CollectIncludeDirectories(
  ${CMAKE_CURRENT_SOURCE_DIR}
  PUBLIC_INCLUDES
)

add_library(mmaps_common ${PRIVATE_SOURCES})

target_link_libraries(mmaps_common
  PRIVATE
    trinity-core-interface
  PUBLIC
    common
    Recast
    Detour)

target_include_directories(mmaps_common
  PUBLIC
    ${PUBLIC_INCLUDES})

set_target_properties(mmaps_common
  PROPERTIES
    COMPILE_WARNING_AS_ERROR ${WITH_WARNINGS_AS_ERRORS}
    DEFINE_SYMBOL TRINITY_API_EXPORT_MMAPS_COMMON
    FOLDER "tools")

if(BUILD_SHARED_LIBS)
  if(UNIX)
    install(TARGETS mmaps_common
      LIBRARY
        DESTINATION lib)
  elseif(WIN32)
    install(TARGETS mmaps_common
      RUNTIME
        DESTINATION "${CMAKE_INSTALL_PREFIX}")
  endif()
endif()
