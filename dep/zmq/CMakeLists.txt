# Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

find_package(ZMQ REQUIRED)

add_library(zmq INTERFACE)

target_link_libraries(zmq
  INTERFACE
    ${ZMQ_LIBRARY})

target_include_directories(zmq
  INTERFACE
    ${ZMQ_INCLUDE_DIR})
