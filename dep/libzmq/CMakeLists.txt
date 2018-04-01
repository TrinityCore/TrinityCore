# Use the bundled source on windows
set (libzmq_STAT_SRCS
  src/address.cpp
  src/client.cpp
  src/clock.cpp
  src/ctx.cpp
  src/dealer.cpp
  src/devpoll.cpp
  src/dgram.cpp
  src/dist.cpp
  src/epoll.cpp
  src/err.cpp
  src/fq.cpp
  src/io_object.cpp
  src/io_thread.cpp
  src/ip.cpp
  src/ipc_address.cpp
  src/ipc_connecter.cpp
  src/ipc_listener.cpp
  src/lb.cpp
  src/kqueue.cpp
  src/mailbox.cpp
  src/mailbox_safe.cpp
  src/mechanism.cpp
  src/mechanism_base.cpp
  src/metadata.cpp
  src/msg.cpp
  src/mtrie.cpp
  src/object.cpp
  src/options.cpp
  src/own.cpp
  src/null_mechanism.cpp
  src/pair.cpp
  src/pipe.cpp
  src/plain_client.cpp
  src/plain_server.cpp
  src/poll.cpp
  src/poller_base.cpp
  src/pollset.cpp
  src/proxy.cpp
  src/pub.cpp
  src/pull.cpp
  src/push.cpp
  src/random.cpp
  src/raw_encoder.cpp
  src/raw_decoder.cpp
  src/reaper.cpp
  src/rep.cpp
  src/req.cpp
  src/router.cpp
  src/select.cpp
  src/server.cpp
  src/session_base.cpp
  src/signaler.cpp
  src/socket_base.cpp
  src/socks.cpp
  src/socks_connecter.cpp
  src/stream.cpp
  src/stream_engine.cpp
  src/sub.cpp
  src/tcp.cpp
  src/tcp_address.cpp
  src/tcp_connecter.cpp
  src/tcp_listener.cpp
  src/thread.cpp
  src/trie.cpp
  src/v1_decoder.cpp
  src/v1_encoder.cpp
  src/v2_decoder.cpp
  src/v2_encoder.cpp
  src/xpub.cpp
  src/xsub.cpp
  src/zmq.cpp
  src/zmq_utils.cpp
  src/decoder_allocators.cpp
  src/socket_poller.cpp
  src/timers.cpp
  src/config.hpp
  src/radio.cpp
  src/dish.cpp
  src/udp_engine.cpp
  src/udp_address.cpp
  src/scatter.cpp
  src/gather.cpp
  src/zap_client.cpp
)

if (WIN32)
  set(ZMQ_PLATFORM -DZMQ_HAVE_WINDOWS)
elseif (APPLE)
  set(ZMQ_PLATFORM -DZMQ_HAVE_OSX)
elseif (UNIX)
  set(ZMQ_PLATFORM -DZMQ_HAVE_LINUX)
endif()

set (POLLER "")

include (CheckFunctionExists)
include (CheckTypeSize)


if (POLLER STREQUAL "")
    set (CMAKE_REQUIRED_INCLUDES sys/event.h)
    check_function_exists (kqueue HAVE_KQUEUE)
    set (CMAKE_REQUIRED_INCLUDES)
    if (HAVE_KQUEUE)
        set (POLLER "kqueue")
    endif()
endif ()

if (POLLER STREQUAL "")
    set (CMAKE_REQUIRED_INCLUDES sys/epoll.h)
    check_function_exists (epoll_create HAVE_EPOLL)
    set (CMAKE_REQUIRED_INCLUDES)
    if (HAVE_EPOLL)
        set (POLLER "epoll")
    endif ()
endif ()

if (POLLER STREQUAL "")
    set (CMAKE_REQUIRED_INCLUDES sys/devpoll.h)
    check_type_size ("struct pollfd" DEVPOLL)
    set (CMAKE_REQUIRED_INCLUDES)
    if (HAVE_DEVPOLL)
        set (POLLER "devpoll")
    endif ()
endif ()

if (POLLER STREQUAL "")
    set (CMAKE_REQUIRED_INCLUDES sys/pollset.h)
    check_function_exists (pollset_create HAVE_POLLSET)
    set (CMAKE_REQUIRED_INCLUDES)
    if (HAVE_POLLSET)
        set (POLLER "pollset")
    endif()
endif ()

if (POLLER STREQUAL "")
    set (CMAKE_REQUIRED_INCLUDES poll.h)
    check_function_exists (poll HAVE_POLL)
    set (CMAKE_REQUIRED_INCLUDES)
    if (HAVE_POLL)
        set (POLLER "poll")
    endif ()
endif ()

if (POLLER STREQUAL "")
    if (WIN32)
        set (CMAKE_REQUIRED_INCLUDES winsock2.h)
        set (HAVE_SELECT 1)
    else ()
        set (CMAKE_REQUIRED_INCLUDES sys/select.h)
        check_function_exists (select HAVE_SELECT)
        set (CMAKE_REQUIRED_INCLUDES)
    endif ()
    if (HAVE_SELECT)
        set (POLLER "select")
    else ()
        message (FATAL_ERROR
            "Could not autodetect polling method")
    endif ()
endif ()

if (POLLER STREQUAL "kqueue"
 OR POLLER STREQUAL "epoll"
 OR POLLER STREQUAL "devpoll"
 OR POLLER STREQUAL "pollset"
 OR POLLER STREQUAL "poll"
 OR POLLER STREQUAL "select")
    message (STATUS "Detected ${POLLER} polling method")
    string (TOUPPER ${POLLER} UPPER_POLLER)
else ()
    message (FATAL_ERROR "Invalid polling method")
endif ()

include (CheckIncludeFiles)

set(ADDITIONAL_DEFINES "")
check_include_files (ifaddrs.h HAVE_IFADDRS)
if (HAVE_IFADDRS)
  list(APPEND ADDITIONAL_DEFINES -DZMQ_HAVE_IFADDRS)
endif()

check_include_files (sys/uio.h HAVE_UIO)
if (HAVE_UIO)
  list(APPEND ADDITIONAL_DEFINES -DZMQ_HAVE_UIO)
endif()

check_include_files (sys/eventfd.h HAVE_EVENTFD)
if (HAVE_EVENTFD)
  list(APPEND ADDITIONAL_DEFINES -DZMQ_HAVE_EVENTFD)
endif()

add_library(libzmq STATIC ${libzmq_STAT_SRCS})

target_include_directories(libzmq
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src)
    
target_link_libraries(libzmq
  PRIVATE
    trinity-dependency-interface
  PUBLIC
    bzip2
    zlib)

set_target_properties(libzmq
    PROPERTIES
      FOLDER
        "dep")

target_compile_definitions(libzmq
  PUBLIC
    -DZMQ_USE_${UPPER_POLLER}
    -DZMQ_STATIC
    ${ZMQ_PLATFORM}
    ${ADDITIONAL_DEFINES})
