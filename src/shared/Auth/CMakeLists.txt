
########### next target ###############

SET(trinityauth_STAT_SRCS
   AuthCrypt.cpp
   AuthCrypt.h
   BigNumber.cpp
   BigNumber.h
   Hmac.cpp
   Hmac.h
   Sha1.cpp
   Sha1.h
   md5.c
   md5.h
   SARC4.cpp
   SARC4.h
)

add_library(trinityauth STATIC ${trinityauth_STAT_SRCS})
