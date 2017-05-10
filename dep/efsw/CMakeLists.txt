if (BUILD_SHARED_LIBS)
  set(SRCS
    src/efsw/DirectorySnapshot.cpp
    src/efsw/DirectorySnapshotDiff.cpp
    src/efsw/DirWatcherGeneric.cpp
    src/efsw/FileInfo.cpp
    src/efsw/FileSystem.cpp
    src/efsw/FileWatcher.cpp
    src/efsw/FileWatcherCWrapper.cpp
    src/efsw/FileWatcherGeneric.cpp
    src/efsw/FileWatcherImpl.cpp
    src/efsw/Log.cpp
    src/efsw/Mutex.cpp
    src/efsw/String.cpp
    src/efsw/System.cpp
    src/efsw/Thread.cpp
    src/efsw/Watcher.cpp
    src/efsw/WatcherGeneric.cpp)

  if(WIN32)
    list(APPEND SRCS
      src/efsw/platform/win/FileSystemImpl.cpp
      src/efsw/platform/win/MutexImpl.cpp
      src/efsw/platform/win/SystemImpl.cpp
      src/efsw/platform/win/ThreadImpl.cpp)
  else()
    list(APPEND SRCS
      src/efsw/platform/posix/FileSystemImpl.cpp
      src/efsw/platform/posix/MutexImpl.cpp
      src/efsw/platform/posix/SystemImpl.cpp
      src/efsw/platform/posix/ThreadImpl.cpp)
  endif()

  if (WIN32)
    list(APPEND SRCS
      src/efsw/WatcherWin32.cpp
      src/efsw/FileWatcherWin32.cpp)
  elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    list(APPEND SRCS
      src/efsw/FileWatcherInotify.cpp
      src/efsw/WatcherInotify.cpp)

    if (NOT EXISTS "/usr/include/sys/inotify.h" AND NOT EXISTS "/usr/local/include/sys/inotify.h")
      add_definitions(-DEFSW_INOTIFY_NOSYS)
    endif()
  elseif (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD" OR APPLE)
    list(APPEND SRCS
      src/efsw/FileWatcherKqueue.cpp
      src/efsw/WatcherKqueue.cpp)

    if (APPLE)
      list(APPEND SRCS
        src/efsw/FileWatcherFSEvents.cpp
        src/efsw/WatcherFSEvents.cpp)

      exec_program(uname ARGS -v  OUTPUT_VARIABLE OSX_VERSION)
      string(REGEX MATCH "[0-9]+" OSX_VERSION ${OSX_VERSION})
      if (NOT OSX_VERSION GREATER 9)
        add_definitions(-DEFSW_FSEVENTS_NOT_SUPPORTED)
      endif()

      set(OPTIONAL_MAC_LINK_LIBRARIES "-framework CoreFoundation" "-framework CoreServices")
    endif()
  endif()

  add_library(efsw STATIC ${SRCS})

  target_include_directories(efsw
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/src)

  target_link_libraries(efsw
    PUBLIC
      threads
      ${OPTIONAL_MAC_LINK_LIBRARIES})

  set_target_properties(efsw
    PROPERTIES
      FOLDER
        "dep")
else()
  add_library(efsw INTERFACE IMPORTED GLOBAL)
endif()
