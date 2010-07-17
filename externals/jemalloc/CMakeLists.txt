SET(jmalloc_STAT_SRC
  arena.c  
  chunk.c      
  chunk_mmap.c  
  ckh.c  
  extent.c  
  huge.c      
  mb.c     
  prof.c   
  tcache.c
  base.c   
  chunk_dss.c  
  chunk_swap.c 
  ctl.c  
  hash.c    
  jemalloc.c  
  mutex.c  
  stats.c
  )

include_directories(
  ${CMAKE_SOURCE_DIR}/dep/include
  )

add_definitions(-D_GNU_SOURCE -D_REENTRANT)

add_library(jmalloc STATIC ${jmalloc_STAT_SRC})