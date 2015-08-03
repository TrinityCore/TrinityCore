/**
 * \file
 *
 * \date   23 Sep 2011
 * \author Ben Gray (\@benjamg)
 */

#ifndef ZMQPP_SOCKET_OPTIONS_HPP_
#define ZMQPP_SOCKET_OPTIONS_HPP_

namespace zmqpp
{

/** \todo Expand the information on the options to make it actually useful. */
/*!
 * \brief possible Socket options in zmq
 */

enum class socket_option {
	affinity                  = ZMQ_AFFINITY,          /*!< I/O thread affinity */
	identity                  = ZMQ_IDENTITY,          /*!< Socket identity */
	subscribe                 = ZMQ_SUBSCRIBE,         /*!< Add topic subscription - set only */
	unsubscribe               = ZMQ_UNSUBSCRIBE,       /*!< Remove topic subscription - set only */
	rate                      = ZMQ_RATE,              /*!< Multicast data rate */
	send_buffer_size          = ZMQ_SNDBUF,            /*!< Kernel transmission buffer size */
	receive_buffer_size       = ZMQ_RCVBUF,            /*!< Kernel receive buffer size */
	receive_more              = ZMQ_RCVMORE,           /*!< Can receive more parts - get only */
	file_descriptor           = ZMQ_FD,                /*!< Socket file descriptor - get only */
	events                    = ZMQ_EVENTS,            /*!< Socket event flags - get only */
	type                      = ZMQ_TYPE,              /*!< Socket type - get only */
	linger                    = ZMQ_LINGER,            /*!< Socket linger timeout */
	backlog                   = ZMQ_BACKLOG,           /*!< Maximum length of outstanding connections - get only */
#if (ZMQ_VERSION_MAJOR == 2)
    // Note that this is inverse of the zmq names for version 2.x
	recovery_interval_seconds = ZMQ_RECOVERY_IVL,      /*!< Multicast recovery interval in seconds */
	recovery_interval         = ZMQ_RECOVERY_IVL_MSEC, /*!< Multicast recovery interval in milliseconds */
#else
	recovery_interval         = ZMQ_RECOVERY_IVL,      /*!< Multicast recovery interval in milliseconds */
#endif
	reconnect_interval        = ZMQ_RECONNECT_IVL,     /*!< Reconnection interval */
	reconnect_interval_max    = ZMQ_RECONNECT_IVL_MAX, /*!< Maximum reconnection interval */
	receive_timeout           = ZMQ_RCVTIMEO,          /*!< Maximum inbound block timeout */
	send_timeout              = ZMQ_SNDTIMEO,          /*!< Maximum outbound block timeout */
#if (ZMQ_VERSION_MAJOR == 2)
	high_water_mark           = ZMQ_HWM,               /*!< High-water mark for all messages */
	swap_size                 = ZMQ_SWAP,              /*!< Maximum socket swap size in bytes */
	multicast_loopback        = ZMQ_MCAST_LOOP,        /*!< Allow multicast packet loopback */
#else
	max_messsage_size         = ZMQ_MAXMSGSIZE,        /*!< Maximum inbound message size */
	send_high_water_mark      = ZMQ_SNDHWM,            /*!< High-water mark for outbound messages */
	receive_high_water_mark   = ZMQ_RCVHWM,            /*!< High-water mark for inbound messages */
	multicast_hops            = ZMQ_MULTICAST_HOPS,    /*!< Maximum number of multicast hops */
#endif
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 1))
	ipv4_only                 = ZMQ_IPV4ONLY,
#endif
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 2))
#if (ZMQ_VERSION_MINOR == 2)
	delay_attach_on_connect   = ZMQ_DELAY_ATTACH_ON_CONNECT, /*!< Delay buffer attachment until connect complete */
#else
	//  ZMQ_DELAY_ATTACH_ON_CONNECT is renamed in ZeroMQ starting 3.3.x
	immediate                 = ZMQ_IMMEDIATE,               /*!< Block message sending until connect complete */
#endif
	last_endpoint             = ZMQ_LAST_ENDPOINT,           /*!< Last bound endpoint - get only */
	router_mandatory          = ZMQ_ROUTER_MANDATORY,        /*!< Require routable messages - set only */
	xpub_verbose              = ZMQ_XPUB_VERBOSE,            /*!< Pass on existing subscriptions - set only */
	tcp_keepalive             = ZMQ_TCP_KEEPALIVE,           /*!< Enable TCP keepalives */
	tcp_keepalive_idle        = ZMQ_TCP_KEEPALIVE_IDLE,      /*!< TCP keepalive idle count (generally retry count) */
	tcp_keepalive_count       = ZMQ_TCP_KEEPALIVE_CNT,       /*!< TCP keepalive retry count */
	tcp_keepalive_interval    = ZMQ_TCP_KEEPALIVE_INTVL,     /*!< TCP keepalive interval */
	tcp_accept_filter         = ZMQ_TCP_ACCEPT_FILTER,       /*!< Filter inbound connections - set only */
#endif
#ifdef ZMQ_EXPERIMENTAL_LABELS
	receive_label             = ZMQ_RCVLABEL,          /*!< Received label part - get only */
#endif
};

}

#endif /* ZMQPP_SOCKET_OPTIONS_HPP_ */
