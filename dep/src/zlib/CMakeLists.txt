
########### next target ###############

SET(zlib_STAT_SRCS
   adler32.c
   compress.c
   crc32.c
   deflate.c
   example.c
   gzio.c
   infback.c
   inffast.c
   inflate.c
   inftrees.c
   trees.c
   uncompr.c
   zutil.c
)

add_library(zlib STATIC ${zlib_STAT_SRCS})
