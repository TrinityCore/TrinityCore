# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

if(DO_WORLDSERVER)
  add_subdirectory(shared)
  add_subdirectory(game)
  add_subdirectory(collision)
  if(DO_SCRIPTS)
    add_subdirectory(scripts)
  endif()
  add_subdirectory(worldserver)
else()
  if(DO_TOOLS)
    add_subdirectory(collision)
  endif()
endif()

if (DO_AUTHSERVER)
  if(NOT DO_WORLDSERVER)
    add_subdirectory(shared)
  endif()
  add_subdirectory(authserver)
endif()
