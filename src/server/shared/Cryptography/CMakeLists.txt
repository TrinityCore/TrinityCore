
########### next target ###############

SET(trinityauth_STAT_SRCS
   Authentication/AuthCrypt.cpp
   Authentication/AuthCrypt.h
   BigNumber.cpp
   BigNumber.h
   HMACSHA1.cpp
   HMACSHA1.h
   SHA1.cpp
   SHA1.h
   MD5.c
   MD5.h
   ARC4.cpp
   ARC4.h
)

include_directories(
  ${ACE_INCLUDE_DIR}
  ${CMAKE_BINARY_DIR}
  ${CMAKE_SOURCE_DIR}/src/server/shared
  ${MYSQL_INCLUDE_DIR}
)

add_library(trinityauth STATIC ${trinityauth_STAT_SRCS})
