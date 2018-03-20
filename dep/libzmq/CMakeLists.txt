# Use the bundled source on windows
set (libzmq_STAT_SRCS
  src/address.cpp
  src/client.cpp
  src/clock.cpp
  src/ctx.cpp
  src/dealer.cpp
  src/dgram.cpp
  src/dist.cpp
  src/err.cpp
  src/fq.cpp
  src/io_object.cpp
  src/io_thread.cpp
  src/ip.cpp
  src/lb.cpp
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
  src/poller_base.cpp
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

add_definitions(-DZMQ_USE_SELECT)
add_definitions(-DZMQ_STATIC)

if (WIN32)
  add_definitions(-DZMQ_HAVE_WINDOWS)
elseif (APPLE)
  add_definitions(-DZMQ_HAVE_OSX)
elseif (UNIX)
  add_definitions(-DZMQ_HAVE_LINUX)
endif()

add_library(libzmq STATIC ${libzmq_STAT_SRCS})

target_include_directories(libzmq
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src)

set_target_properties(libzmq
    PROPERTIES
      FOLDER
        "dep")
