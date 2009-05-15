########### next target ###############

SET(ZThread_LIB_SRCS
   Condition.cxx
   ConcurrentExecutor.cxx
   CountingSemaphore.cxx
   FastMutex.cxx
   FastRecursiveMutex.cxx
   Mutex.cxx
   RecursiveMutexImpl.cxx
   RecursiveMutex.cxx
   Monitor.cxx
   PoolExecutor.cxx
   PriorityCondition.cxx
   PriorityInheritanceMutex.cxx
   PriorityMutex.cxx
   PrioritySemaphore.cxx
   Semaphore.cxx
   SynchronousExecutor.cxx
   Thread.cxx
   ThreadedExecutor.cxx
   ThreadImpl.cxx
   ThreadLocalImpl.cxx
   ThreadQueue.cxx
   Time.cxx
   ThreadOps.cxx
   )

ADD_LIBRARY(ZThread STATIC ${ZThread_LIB_SRCS})

TARGET_LINK_LIBRARIES(ZThread  )

SET_TARGET_PROPERTIES(ZThread PROPERTIES VERSION 4.2.0 SOVERSION 4 )
INSTALL(TARGETS ZThread DESTINATION lib )


########### install files ###############
