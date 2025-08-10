if (BUILD_SHARED_LIBS)
  set(EFSW_CPP_SOURCE
    src/efsw/Atomic.hpp
    src/efsw/base.hpp
    src/efsw/Debug.cpp
    src/efsw/Debug.hpp
    src/efsw/DirectorySnapshot.cpp
    src/efsw/DirectorySnapshot.hpp
    src/efsw/DirectorySnapshotDiff.cpp
    src/efsw/DirectorySnapshotDiff.hpp
    src/efsw/DirWatcherGeneric.cpp
    src/efsw/DirWatcherGeneric.hpp
    src/efsw/FileInfo.cpp
    src/efsw/FileInfo.hpp
    src/efsw/FileSystem.cpp
    src/efsw/FileSystem.hpp
    src/efsw/FileWatcher.cpp
    src/efsw/FileWatcherCWrapper.cpp
    src/efsw/FileWatcherGeneric.cpp
    src/efsw/FileWatcherGeneric.hpp
    src/efsw/FileWatcherImpl.cpp
    src/efsw/FileWatcherImpl.hpp
    src/efsw/Lock.hpp
    src/efsw/Log.cpp
    src/efsw/Mutex.cpp
    src/efsw/Mutex.hpp
    src/efsw/sophist.h
    src/efsw/String.cpp
    src/efsw/String.hpp
    src/efsw/System.cpp
    src/efsw/System.hpp
    src/efsw/Thread.cpp
    src/efsw/Thread.hpp
    src/efsw/Utf.hpp
    src/efsw/Watcher.cpp
    src/efsw/Watcher.hpp
    src/efsw/WatcherGeneric.cpp
    src/efsw/WatcherGeneric.hpp
    src/efsw/platform/platformimpl.hpp
  )

  if (WIN32)
    list (APPEND EFSW_CPP_SOURCE
      src/efsw/platform/win/FileSystemImpl.cpp
      src/efsw/platform/win/FileSystemImpl.hpp
      src/efsw/platform/win/MutexImpl.cpp
      src/efsw/platform/win/MutexImpl.hpp
      src/efsw/platform/win/SystemImpl.cpp
      src/efsw/platform/win/SystemImpl.hpp
      src/efsw/platform/win/ThreadImpl.cpp
      src/efsw/platform/win/ThreadImpl.hpp)
  else ()
    list (APPEND EFSW_CPP_SOURCE
      src/efsw/platform/posix/FileSystemImpl.cpp
      src/efsw/platform/posix/FileSystemImpl.hpp
      src/efsw/platform/posix/MutexImpl.cpp
      src/efsw/platform/posix/MutexImpl.hpp
      src/efsw/platform/posix/SystemImpl.cpp
      src/efsw/platform/posix/SystemImpl.hpp
      src/efsw/platform/posix/ThreadImpl.cpp
      src/efsw/platform/posix/ThreadImpl.hpp)
  endif()

  if (APPLE)
    list (APPEND EFSW_CPP_SOURCE
      src/efsw/FileWatcherFSEvents.cpp
      src/efsw/FileWatcherFSEvents.hpp
      src/efsw/FileWatcherKqueue.cpp
      src/efsw/FileWatcherKqueue.hpp
      src/efsw/WatcherFSEvents.cpp
      src/efsw/WatcherFSEvents.hpp
      src/efsw/WatcherKqueue.cpp
      src/efsw/WatcherKqueue.hpp)
    set(OPTIONAL_LINK_LIBRARIES "-framework CoreFoundation" "-framework CoreServices")
  elseif (WIN32)
    list (APPEND EFSW_CPP_SOURCE
      src/efsw/FileWatcherWin32.cpp
      src/efsw/FileWatcherWin32.hpp
      src/efsw/WatcherWin32.cpp
      src/efsw/WatcherWin32.hpp)
  elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")
    list (APPEND EFSW_CPP_SOURCE
      src/efsw/FileWatcherInotify.cpp
      src/efsw/FileWatcherInotify.hpp
      src/efsw/WatcherInotify.cpp
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
      set(OPTIONAL_COMPILE_DEFINITIONS "-DEFSW_INOTIFY_NOSYS")
    endif()
  elseif (${CMAKE_SYSTEM_NAME} MATCHES "FreeBSD")
    list (APPEND EFSW_CPP_SOURCE
      src/efsw/FileWatcherKqueue.cpp
      src/efsw/FileWatcherKqueue.hpp
      src/efsw/WatcherKqueue.cpp
      src/efsw/WatcherKqueue.hpp)
  endif()

  add_library(efsw STATIC ${EFSW_CPP_SOURCE})

  target_include_directories(efsw
    PUBLIC
      ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
      ${CMAKE_CURRENT_SOURCE_DIR}/src)

  target_compile_definitions(efsw
    PRIVATE
      ${OPTIONAL_COMPILE_DEFINITIONS})

  target_link_libraries(efsw
    PRIVATE
      trinity-dependency-interface
    PUBLIC
      threads
      ${OPTIONAL_LINK_LIBRARIES})

  set_target_properties(efsw
    PROPERTIES
      FOLDER
        "dep")
else ()
  add_library(efsw INTERFACE IMPORTED GLOBAL)
endif ()
