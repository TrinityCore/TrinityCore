/*
    Copyright (c) 2007-2015 Contributors as noted in the AUTHORS file

    This file is part of 0MQ.

    0MQ is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    0MQ is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

    *************************************************************************
    NOTE to contributors. This file comprises the principal public contract
    for ZeroMQ API users (along with zmq_utils.h). Any change to this file
    supplied in a stable release SHOULD not break existing applications.
    In practice this means that the value of constants must not change, and
    that old values may not be reused for new constants.
    *************************************************************************
*/

#ifndef __ZMQ_H_INCLUDED__
#define __ZMQ_H_INCLUDED__

/*  Version macros for compile-time API version detection                     */
#define ZMQ_VERSION_MAJOR 4
#define ZMQ_VERSION_MINOR 1
#define ZMQ_VERSION_PATCH 2

#define ZMQ_MAKE_VERSION(major, minor, patch) \
    ((major) * 10000 + (minor) * 100 + (patch))
#define ZMQ_VERSION \
    ZMQ_MAKE_VERSION(ZMQ_VERSION_MAJOR, ZMQ_VERSION_MINOR, ZMQ_VERSION_PATCH)

#ifdef __cplusplus
extern "C" {
#endif

#if !defined _WIN32_WCE
#include <errno.h>
#endif
#include <stddef.h>
#include <stdio.h>
#if defined _WIN32
#include <winsock2.h>
#endif

/*  Handle DSO symbol visibility                                             */
#if defined _WIN32
#   if defined ZMQ_STATIC
#       define ZMQ_EXPORT
#   elif defined DLL_EXPORT
#       define ZMQ_EXPORT __declspec(dllexport)
#   else
#       define ZMQ_EXPORT __declspec(dllimport)
#   endif
#else
#   if defined __SUNPRO_C  || defined __SUNPRO_CC
#       define ZMQ_EXPORT __global
#   elif (defined __GNUC__ && __GNUC__ >= 4) || defined __INTEL_COMPILER
#       define ZMQ_EXPORT __attribute__ ((visibility("default")))
#   else
#       define ZMQ_EXPORT
#   endif
#endif

/*  Define integer types needed for event interface                          */
#define ZMQ_DEFINED_STDINT 1
#if defined ZMQ_HAVE_SOLARIS || defined ZMQ_HAVE_OPENVMS
#   include <inttypes.h>
#else
#   include <stdint.h>
#endif


/******************************************************************************/
/*  0MQ errors.                                                               */
/******************************************************************************/

/*  A number random enough not to collide with different errno ranges on      */
/*  different OSes. The assumption is that error_t is at least 32-bit type.   */
#define ZMQ_HAUSNUMERO 156384712

/*  On Windows platform some of the standard POSIX errnos are not defined.    */
#ifndef ENOTSUP
#define ENOTSUP (ZMQ_HAUSNUMERO + 1)
#endif
#ifndef EPROTONOSUPPORT
#define EPROTONOSUPPORT (ZMQ_HAUSNUMERO + 2)
#endif
#ifndef ENOBUFS
#define ENOBUFS (ZMQ_HAUSNUMERO + 3)
#endif
#ifndef ENETDOWN
#define ENETDOWN (ZMQ_HAUSNUMERO + 4)
#endif
#ifndef EADDRINUSE
#define EADDRINUSE (ZMQ_HAUSNUMERO + 5)
#endif
#ifndef EADDRNOTAVAIL
#define EADDRNOTAVAIL (ZMQ_HAUSNUMERO + 6)
#endif
#ifndef ECONNREFUSED
#define ECONNREFUSED (ZMQ_HAUSNUMERO + 7)
#endif
#ifndef EINPROGRESS
#define EINPROGRESS (ZMQ_HAUSNUMERO + 8)
#endif
#ifndef ENOTSOCK
#define ENOTSOCK (ZMQ_HAUSNUMERO + 9)
#endif
#ifndef EMSGSIZE
#define EMSGSIZE (ZMQ_HAUSNUMERO + 10)
#endif
#ifndef EAFNOSUPPORT
#define EAFNOSUPPORT (ZMQ_HAUSNUMERO + 11)
#endif
#ifndef ENETUNREACH
#define ENETUNREACH (ZMQ_HAUSNUMERO + 12)
#endif
#ifndef ECONNABORTED
#define ECONNABORTED (ZMQ_HAUSNUMERO + 13)
#endif
#ifndef ECONNRESET
#define ECONNRESET (ZMQ_HAUSNUMERO + 14)
#endif
#ifndef ENOTCONN
#define ENOTCONN (ZMQ_HAUSNUMERO + 15)
#endif
#ifndef ETIMEDOUT
#define ETIMEDOUT (ZMQ_HAUSNUMERO + 16)
#endif
#ifndef EHOSTUNREACH
#define EHOSTUNREACH (ZMQ_HAUSNUMERO + 17)
#endif
#ifndef ENETRESET
#define ENETRESET (ZMQ_HAUSNUMERO + 18)
#endif

/*  Native 0MQ error codes.                                                   */
#define EFSM (ZMQ_HAUSNUMERO + 51)
#define ENOCOMPATPROTO (ZMQ_HAUSNUMERO + 52)
#define ETERM (ZMQ_HAUSNUMERO + 53)
#define EMTHREAD (ZMQ_HAUSNUMERO + 54)

/*  This function retrieves the errno as it is known to 0MQ library. The goal */
/*  of this function is to make the code 100% portable, including where 0MQ   */
/*  compiled with certain CRT library (on Windows) is linked to an            */
/*  application that uses different CRT library.                              */
ZMQ_EXPORT int zmq_errno (void);

/*  Resolves system errors and 0MQ errors to human-readable string.           */
ZMQ_EXPORT const char *zmq_strerror (int errnum);

/*  Run-time API version detection                                            */
ZMQ_EXPORT void zmq_version (int *major, int *minor, int *patch);

/******************************************************************************/
/*  0MQ infrastructure (a.k.a. context) initialisation & termination.         */
/******************************************************************************/

/*  New API                                                                   */
/*  Context options                                                           */
#define ZMQ_IO_THREADS  1
#define ZMQ_MAX_SOCKETS 2
#define ZMQ_SOCKET_LIMIT 3
#define ZMQ_THREAD_PRIORITY 3
#define ZMQ_THREAD_SCHED_POLICY 4

/*  Default for new contexts                                                  */
#define ZMQ_IO_THREADS_DFLT  1
#define ZMQ_MAX_SOCKETS_DFLT 1023
#define ZMQ_THREAD_PRIORITY_DFLT -1
#define ZMQ_THREAD_SCHED_POLICY_DFLT -1

ZMQ_EXPORT void *zmq_ctx_new (void);
ZMQ_EXPORT int zmq_ctx_term (void *context);
ZMQ_EXPORT int zmq_ctx_shutdown (void *ctx_);
ZMQ_EXPORT int zmq_ctx_set (void *context, int option, int optval);
ZMQ_EXPORT int zmq_ctx_get (void *context, int option);

/*  Old (legacy) API                                                          */
ZMQ_EXPORT void *zmq_init (int io_threads);
ZMQ_EXPORT int zmq_term (void *context);
ZMQ_EXPORT int zmq_ctx_destroy (void *context);


/******************************************************************************/
/*  0MQ message definition.                                                   */
/******************************************************************************/

typedef struct zmq_msg_t {unsigned char _ [64];} zmq_msg_t;

typedef void (zmq_free_fn) (void *data, void *hint);

ZMQ_EXPORT int zmq_msg_init (zmq_msg_t *msg);
ZMQ_EXPORT int zmq_msg_init_size (zmq_msg_t *msg, size_t size);
ZMQ_EXPORT int zmq_msg_init_data (zmq_msg_t *msg, void *data,
    size_t size, zmq_free_fn *ffn, void *hint);
ZMQ_EXPORT int zmq_msg_send (zmq_msg_t *msg, void *s, int flags);
ZMQ_EXPORT int zmq_msg_recv (zmq_msg_t *msg, void *s, int flags);
ZMQ_EXPORT int zmq_msg_close (zmq_msg_t *msg);
ZMQ_EXPORT int zmq_msg_move (zmq_msg_t *dest, zmq_msg_t *src);
ZMQ_EXPORT int zmq_msg_copy (zmq_msg_t *dest, zmq_msg_t *src);
ZMQ_EXPORT void *zmq_msg_data (zmq_msg_t *msg);
ZMQ_EXPORT size_t zmq_msg_size (zmq_msg_t *msg);
ZMQ_EXPORT int zmq_msg_more (zmq_msg_t *msg);
ZMQ_EXPORT int zmq_msg_get (zmq_msg_t *msg, int property);
ZMQ_EXPORT int zmq_msg_set (zmq_msg_t *msg, int property, int optval);
ZMQ_EXPORT const char *zmq_msg_gets (zmq_msg_t *msg, const char *property);


/******************************************************************************/
/*  0MQ socket definition.                                                    */
/******************************************************************************/

/*  Socket types.                                                             */
#define ZMQ_PAIR 0
#define ZMQ_PUB 1
#define ZMQ_SUB 2
#define ZMQ_REQ 3
#define ZMQ_REP 4
#define ZMQ_DEALER 5
#define ZMQ_ROUTER 6
#define ZMQ_PULL 7
#define ZMQ_PUSH 8
#define ZMQ_XPUB 9
#define ZMQ_XSUB 10
#define ZMQ_STREAM 11

/*  Deprecated aliases                                                        */
#define ZMQ_XREQ ZMQ_DEALER
#define ZMQ_XREP ZMQ_ROUTER

/*  Socket options.                                                           */
#define ZMQ_AFFINITY 4
#define ZMQ_IDENTITY 5
#define ZMQ_SUBSCRIBE 6
#define ZMQ_UNSUBSCRIBE 7
#define ZMQ_RATE 8
#define ZMQ_RECOVERY_IVL 9
#define ZMQ_SNDBUF 11
#define ZMQ_RCVBUF 12
#define ZMQ_RCVMORE 13
#define ZMQ_FD 14
#define ZMQ_EVENTS 15
#define ZMQ_TYPE 16
#define ZMQ_LINGER 17
#define ZMQ_RECONNECT_IVL 18
#define ZMQ_BACKLOG 19
#define ZMQ_RECONNECT_IVL_MAX 21
#define ZMQ_MAXMSGSIZE 22
#define ZMQ_SNDHWM 23
#define ZMQ_RCVHWM 24
#define ZMQ_MULTICAST_HOPS 25
#define ZMQ_RCVTIMEO 27
#define ZMQ_SNDTIMEO 28
#define ZMQ_LAST_ENDPOINT 32
#define ZMQ_ROUTER_MANDATORY 33
#define ZMQ_TCP_KEEPALIVE 34
#define ZMQ_TCP_KEEPALIVE_CNT 35
#define ZMQ_TCP_KEEPALIVE_IDLE 36
#define ZMQ_TCP_KEEPALIVE_INTVL 37
#define ZMQ_IMMEDIATE 39
#define ZMQ_XPUB_VERBOSE 40
#define ZMQ_ROUTER_RAW 41
#define ZMQ_IPV6 42
#define ZMQ_MECHANISM 43
#define ZMQ_PLAIN_SERVER 44
#define ZMQ_PLAIN_USERNAME 45
#define ZMQ_PLAIN_PASSWORD 46
#define ZMQ_CURVE_SERVER 47
#define ZMQ_CURVE_PUBLICKEY 48
#define ZMQ_CURVE_SECRETKEY 49
#define ZMQ_CURVE_SERVERKEY 50
#define ZMQ_PROBE_ROUTER 51
#define ZMQ_REQ_CORRELATE 52
#define ZMQ_REQ_RELAXED 53
#define ZMQ_CONFLATE 54
#define ZMQ_ZAP_DOMAIN 55
#define ZMQ_ROUTER_HANDOVER 56
#define ZMQ_TOS 57
#define ZMQ_CONNECT_RID 61
#define ZMQ_GSSAPI_SERVER 62
#define ZMQ_GSSAPI_PRINCIPAL 63
#define ZMQ_GSSAPI_SERVICE_PRINCIPAL 64
#define ZMQ_GSSAPI_PLAINTEXT 65
#define ZMQ_HANDSHAKE_IVL 66
#define ZMQ_SOCKS_PROXY 68
#define ZMQ_XPUB_NODROP 69

/*  Message options                                                           */
#define ZMQ_MORE 1
#define ZMQ_SRCFD 2
#define ZMQ_SHARED 3

/*  Send/recv options.                                                        */
#define ZMQ_DONTWAIT 1
#define ZMQ_SNDMORE 2

/*  Security mechanisms                                                       */
#define ZMQ_NULL 0
#define ZMQ_PLAIN 1
#define ZMQ_CURVE 2
#define ZMQ_GSSAPI 3

/*  Deprecated options and aliases                                            */
#define ZMQ_TCP_ACCEPT_FILTER       38
#define ZMQ_IPC_FILTER_PID          58
#define ZMQ_IPC_FILTER_UID          59
#define ZMQ_IPC_FILTER_GID          60
#define ZMQ_IPV4ONLY                31
#define ZMQ_DELAY_ATTACH_ON_CONNECT ZMQ_IMMEDIATE
#define ZMQ_NOBLOCK                 ZMQ_DONTWAIT
#define ZMQ_FAIL_UNROUTABLE         ZMQ_ROUTER_MANDATORY
#define ZMQ_ROUTER_BEHAVIOR         ZMQ_ROUTER_MANDATORY

/******************************************************************************/
/*  0MQ socket events and monitoring                                          */
/******************************************************************************/

/*  Socket transport events (TCP and IPC only)                                */

#define ZMQ_EVENT_CONNECTED         0x0001
#define ZMQ_EVENT_CONNECT_DELAYED   0x0002
#define ZMQ_EVENT_CONNECT_RETRIED   0x0004
#define ZMQ_EVENT_LISTENING         0x0008
#define ZMQ_EVENT_BIND_FAILED       0x0010
#define ZMQ_EVENT_ACCEPTED          0x0020
#define ZMQ_EVENT_ACCEPT_FAILED     0x0040
#define ZMQ_EVENT_CLOSED            0x0080
#define ZMQ_EVENT_CLOSE_FAILED      0x0100
#define ZMQ_EVENT_DISCONNECTED      0x0200
#define ZMQ_EVENT_MONITOR_STOPPED   0x0400
#define ZMQ_EVENT_ALL               0xFFFF

ZMQ_EXPORT void *zmq_socket (void *, int type);
ZMQ_EXPORT int zmq_close (void *s);
ZMQ_EXPORT int zmq_setsockopt (void *s, int option, const void *optval,
    size_t optvallen);
ZMQ_EXPORT int zmq_getsockopt (void *s, int option, void *optval,
    size_t *optvallen);
ZMQ_EXPORT int zmq_bind (void *s, const char *addr);
ZMQ_EXPORT int zmq_connect (void *s, const char *addr);
ZMQ_EXPORT int zmq_unbind (void *s, const char *addr);
ZMQ_EXPORT int zmq_disconnect (void *s, const char *addr);
ZMQ_EXPORT int zmq_send (void *s, const void *buf, size_t len, int flags);
ZMQ_EXPORT int zmq_send_const (void *s, const void *buf, size_t len, int flags);
ZMQ_EXPORT int zmq_recv (void *s, void *buf, size_t len, int flags);
ZMQ_EXPORT int zmq_socket_monitor (void *s, const char *addr, int events);


/******************************************************************************/
/*  I/O multiplexing.                                                         */
/******************************************************************************/

#define ZMQ_POLLIN 1
#define ZMQ_POLLOUT 2
#define ZMQ_POLLERR 4

typedef struct zmq_pollitem_t
{
    void *socket;
#if defined _WIN32
    SOCKET fd;
#else
    int fd;
#endif
    short events;
    short revents;
} zmq_pollitem_t;

#define ZMQ_POLLITEMS_DFLT 16

ZMQ_EXPORT int zmq_poll (zmq_pollitem_t *items, int nitems, long timeout);

/******************************************************************************/
/*  Message proxying                                                          */
/******************************************************************************/

ZMQ_EXPORT int zmq_proxy (void *frontend, void *backend, void *capture);
ZMQ_EXPORT int zmq_proxy_steerable (void *frontend, void *backend, void *capture, void *control);

/******************************************************************************/
/*  Probe library capabilities                                                */
/******************************************************************************/

#define ZMQ_HAS_CAPABILITIES 1
ZMQ_EXPORT int zmq_has (const char *capability);

/*  Deprecated aliases */
#define ZMQ_STREAMER 1
#define ZMQ_FORWARDER 2
#define ZMQ_QUEUE 3

/*  Deprecated methods */
ZMQ_EXPORT int zmq_device (int type, void *frontend, void *backend);
ZMQ_EXPORT int zmq_sendmsg (void *s, zmq_msg_t *msg, int flags);
ZMQ_EXPORT int zmq_recvmsg (void *s, zmq_msg_t *msg, int flags);


/******************************************************************************/
/*  Encryption functions                                                      */
/******************************************************************************/

/*  Encode data with Z85 encoding. Returns encoded data                       */
ZMQ_EXPORT char *zmq_z85_encode (char *dest, const uint8_t *data, size_t size);

/*  Decode data with Z85 encoding. Returns decoded data                       */
ZMQ_EXPORT uint8_t *zmq_z85_decode (uint8_t *dest, const char *string);

/*  Generate z85-encoded public and private keypair with libsodium.           */
/*  Returns 0 on success.                                                     */
ZMQ_EXPORT int zmq_curve_keypair (char *z85_public_key, char *z85_secret_key);


/******************************************************************************/
/*  These functions are not documented by man pages -- use at your own risk.  */
/*  If you need these to be part of the formal ZMQ API, then (a) write a man  */
/*  page, and (b) write a test case in tests.                                 */
/******************************************************************************/

struct iovec;

ZMQ_EXPORT int zmq_sendiov (void *s, struct iovec *iov, size_t count, int flags);
ZMQ_EXPORT int zmq_recviov (void *s, struct iovec *iov, size_t *count, int flags);

/*  Helper functions are used by perf tests so that they don't have to care   */
/*  about minutiae of time-related functions on different OS platforms.       */

/*  Starts the stopwatch. Returns the handle to the watch.                    */
ZMQ_EXPORT void *zmq_stopwatch_start (void);

/*  Stops the stopwatch. Returns the number of microseconds elapsed since     */
/*  the stopwatch was started.                                                */
ZMQ_EXPORT unsigned long zmq_stopwatch_stop (void *watch_);

/*  Sleeps for specified number of seconds.                                   */
ZMQ_EXPORT void zmq_sleep (int seconds_);

typedef void (zmq_thread_fn) (void*);

/* Start a thread. Returns a handle to the thread.                            */
ZMQ_EXPORT void *zmq_threadstart (zmq_thread_fn* func, void* arg);

/* Wait for thread to complete then free up resources.                        */
ZMQ_EXPORT void zmq_threadclose (void* thread);


#undef ZMQ_EXPORT

#ifdef __cplusplus
}
#endif

#endif

