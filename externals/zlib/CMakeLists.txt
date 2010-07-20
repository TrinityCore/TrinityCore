# Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.


SET(zlib_STAT_SRCS
  adler32.c                                                                                                                                           
  compress.c                                                                                                                                          
  crc32.c                                                                                                                                             
  deflate.c                                                                                                                                           
  example.c                                                                                                                                           
  infback.c                                                                                                                                           
  inffast.c                                                                                                                                           
  inflate.c                                                                                                                                           
  inftrees.c                                                                                                                                          
  trees.c                                                                                                                                             
  uncompr.c                                                                                                                                           
  zutil.c   
)

include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}
)

add_library(zlib STATIC ${zlib_STAT_SRCS})
