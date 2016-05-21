# Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

set(HEADER_FILES
  Helper.hpp
  Patcher.hpp
  Constants/BinaryTypes.hpp
  Patches/Common.hpp
  Patches/Mac.hpp
  Patches/Windows.hpp
  Patterns/Common.hpp
  Patterns/Mac.hpp
  Patterns/Windows.hpp
)

set(SRC_FILES
  Helper.cpp
  Patcher.cpp
  Program.cpp
)

add_executable(connection_patcher ${HEADER_FILES} ${SRC_FILES})

if (MSVC)
  set_target_properties(connection_patcher PROPERTIES LINK_FLAGS "/level='requireAdministrator' /uiAccess='false'")
endif ()

target_link_libraries(connection_patcher
  PUBLIC
    common
)

if (UNIX)
  install(TARGETS connection_patcher DESTINATION bin)
elseif (WIN32)
  install(TARGETS connection_patcher DESTINATION "${CMAKE_INSTALL_PREFIX}")
endif ()
