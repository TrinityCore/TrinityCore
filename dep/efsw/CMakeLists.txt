if (BUILD_SHARED_LIBS)
  add_library(efsw STATIC)

  if(WIN32)
    set(efsw_platform_dir "win")
  else()
    set(efsw_platform_dir "posix")
  endif()

  target_sources(efsw
    PRIVATE
      src/efsw/Debug.cpp
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
      src/efsw/String.cpp
      src/efsw/System.cpp
      src/efsw/Watcher.cpp
      src/efsw/WatcherGeneric.cpp
      src/efsw/platform/${efsw_platform_dir}/FileSystemImpl.cpp
      src/efsw/platform/${efsw_platform_dir}/SystemImpl.cpp)

  target_sources(efsw
    PUBLIC
      FILE_SET HEADERS
      BASE_DIRS include
      FILES
        include/efsw/efsw.h
        include/efsw/efsw.hpp)

  target_sources(efsw
    PRIVATE
      FILE_SET efsw_private_headers
      TYPE HEADERS
      BASE_DIRS src
      FILES
        src/efsw/Atomic.hpp
        src/efsw/base.hpp
        src/efsw/Debug.hpp
        src/efsw/DirectorySnapshot.hpp
        src/efsw/DirectorySnapshotDiff.hpp
        src/efsw/DirWatcherGeneric.hpp
        src/efsw/FileInfo.hpp
        src/efsw/FileSystem.hpp
        src/efsw/FileWatcherGeneric.hpp
        src/efsw/FileWatcherImpl.hpp
        src/efsw/Lock.hpp
        src/efsw/Mutex.hpp
        src/efsw/sophist.h
        src/efsw/String.hpp
        src/efsw/System.hpp
        src/efsw/Thread.hpp
        src/efsw/Utf.hpp
        src/efsw/Watcher.hpp
        src/efsw/WatcherGeneric.hpp
        src/efsw/platform/platformimpl.hpp
        src/efsw/platform/${efsw_platform_dir}/FileSystemImpl.hpp
        src/efsw/platform/${efsw_platform_dir}/SystemImpl.hpp)

  if (APPLE)
    target_sources(efsw
      PRIVATE
        src/efsw/FileWatcherFSEvents.cpp
        src/efsw/FileWatcherKqueue.cpp
        src/efsw/WatcherFSEvents.cpp
        src/efsw/WatcherKqueue.cpp)
    target_sources(efsw
      PRIVATE
        FILE_SET efsw_private_headers
        TYPE HEADERS
        BASE_DIRS src
        FILES
          src/efsw/FileWatcherFSEvents.hpp
          src/efsw/FileWatcherKqueue.hpp
          src/efsw/WatcherFSEvents.hpp
          src/efsw/WatcherKqueue.hpp)
    target_link_libraries(efsw
      PRIVATE
        $<LINK_LIBRARY:FRAMEWORK,CoreFoundation>
        $<LINK_LIBRARY:FRAMEWORK,CoreServices>)
  elseif (WIN32)
    target_sources(efsw
      PRIVATE
        src/efsw/FileWatcherWin32.cpp
        src/efsw/WatcherWin32.cpp)
    target_sources(efsw
      PRIVATE
        FILE_SET efsw_private_headers
        TYPE HEADERS
        BASE_DIRS src
        FILES
          src/efsw/FileWatcherWin32.hpp
          src/efsw/WatcherWin32.hpp)
  elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    target_sources(efsw
      PRIVATE
        src/efsw/FileWatcherInotify.cpp
        src/efsw/WatcherInotify.cpp)
    target_sources(efsw
      PRIVATE
        FILE_SET efsw_private_headers
        TYPE HEADERS
        BASE_DIRS src
        FILES
          src/efsw/FileWatcherInotify.hpp
          src/efsw/WatcherInotify.hpp)
    find_path(EFSW_INOTIFY_H
      NAMES
        sys/inotify.h
      NO_CACHE
    )
    if (EFSW_INOTIFY_H STREQUAL "EFSW_INOTIFY_H-NOTFOUND")
      list (APPEND EFSW_CPP_SOURCE
        src/efsw/inotify-nosys.h
      )
      target_compile_definitions(efsw
        PRIVATE
          EFSW_INOTIFY_NOSYS)
    endif()
  elseif (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
    target_sources(efsw
      PRIVATE
        src/efsw/FileWatcherKqueue.cpp
        src/efsw/WatcherKqueue.cpp)
    target_sources(efsw
      PRIVATE
        FILE_SET efsw_private_headers
        TYPE HEADERS
        BASE_DIRS src
        FILES
          src/efsw/FileWatcherKqueue.hpp
          src/efsw/WatcherKqueue.hpp)
  endif()

  target_link_libraries(efsw
    PRIVATE
      trinity-dependency-interface
    PUBLIC
      threads)

  set_target_properties(efsw
    PROPERTIES
      FOLDER
        "dep")
else ()
  add_library(efsw INTERFACE IMPORTED GLOBAL)
endif ()
