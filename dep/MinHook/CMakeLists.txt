# This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(SOURCES_MINHOOK 
  "src/buffer.c"
  "src/hook.c"
  "src/trampoline.c"
)

if(PLATFORM EQUAL 64)
  set(SOURCES_HDE "src/hde/hde64.c")
else()
  set(SOURCES_HDE "src/hde/hde32.c")
endif()

add_library(minhook STATIC ${SOURCES_MINHOOK} ${SOURCES_HDE})

target_include_directories(minhook
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${CMAKE_CURRENT_SOURCE_DIR}/src/hde
    ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(minhook
  PRIVATE
    trinity-dependency-interface)

set_target_properties(minhook
  PROPERTIES
    FOLDER
      "dep")

if(WIN32)
  set_target_properties(minhook PROPERTIES PREFIX "")
  if(PLATFORM EQUAL 64)  
    set_target_properties(minhook PROPERTIES DEBUG_POSTFIX ".x64d")
    set_target_properties(minhook PROPERTIES RELEASE_POSTFIX ".x64")
    set_target_properties(minhook PROPERTIES RELWITHDEBINFO_POSTFIX ".x64")
    set_target_properties(minhook PROPERTIES MINSIZEREL_POSTFIX ".x64")
  else()
    set_target_properties(minhook PROPERTIES DEBUG_POSTFIX ".x32d")
    set_target_properties(minhook PROPERTIES RELEASE_POSTFIX ".x32")
    set_target_properties(minhook PROPERTIES RELWITHDEBINFO_POSTFIX ".x32")
    set_target_properties(minhook PROPERTIES MINSIZEREL_POSTFIX ".x32")
  endif()
else()
  set_target_properties(minhook PROPERTIES PREFIX "lib")
  set_target_properties(minhook PROPERTIES POSTFIX "")
  set_target_properties(minhook PROPERTIES DEBUG_POSTFIX "d")
endif()
