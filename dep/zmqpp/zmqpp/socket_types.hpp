/**
 * \file
 *
 * \date   23 Sep 2011
 * \author Ben Gray (\@benjamg)
 */

#ifndef ZMQPP_SOCKET_TYPES_HPP_
#define ZMQPP_SOCKET_TYPES_HPP_

namespace zmqpp
{

/*!
 * \brief Socket types allowed by zmq
 *
 * The socket type choose at creation must be one of these types.
 *
 * Each is designed for a different use and has different limitations.
 */
enum class socket_type {
	/*!
	 * One to one - two way connection.\n
	 * Connect to ::pair.\n
	 * A \c pair socket has to be connected only one other pair socket and allows
	 * two way communication between them.
	 */
	pair       = ZMQ_PAIR,

	/*!
	 * One to many - fan out.\n
	 * Connect to ::subscribe or ::xsubscribe.\n
	 * Socket is send only.\n
	 * Socket will drop messages and not block.\n
	 * \c publish sockets allow sending of the same message to many subscribers
	 * each subscriber can limit what is sent through the socket_option::subscribe
	 * settings.
	 */
	publish    = ZMQ_PUB,

	/*!
	 * \note It seems doxygen can't work out which data is for the socket type and
	 * which is for the socket option so both get listed for both.
	 *
	 * One to many - fair-queued.\n
	 * Connect to ::publish or ::xpublish.\n
	 * Socket is receive only.\n
	 * The \c subscribe socket can connection to any number of publishers and will
	 * fairly pull messages from each. The socket_option::subscribe settings can
	 * be use to limit which messages are received and by default none are.
	 */
	subscribe  = ZMQ_SUB,

	/*!
	 * One to many - fair-queued.\n
	 * Connect to ::push.\n
	 * Socket is receive only.\n
	 * The \c pull socket fairly pulls messages from all pushers it is connected
	 * to.
	 */
	pull       = ZMQ_PULL,

	/*!
	 * One to many - load-balanced.\n
	 * Connect to ::pull.\n
	 * Socket is send only.\n
	 * Socket will block if unable to send.\n
	 * The \c push socket fairly distributes messages between any connected
	 * puller sockets.
	 */
	push       = ZMQ_PUSH,

	/*!
	 * One to many - fair-queued outgoing, last peer incoming.\n
	 * Connect to ::reply or ::xreply.\n
	 * Socket flips between send and receive only.\n
	 * Socket will block if unable to send.\n
	 * The \c request socket will fairly balance requests sent out to a
	 * replier and then can only be used to receive until that replier
	 * sends a reply.
	 */
	request    = ZMQ_REQ,

	/*!
	 * One to many - load-balanced incoming, last peer outgoing.\n
	 * Connect to ::request or ::xrequest.\n
	 * Socket flips between send and receive only.\n
	 * Socket will drop messages and not block.\n
	 * The \c reply socket can only receive until it pulls a message from a
	 * requester at which point it can only send until the reply is sent.
	 */
	reply      = ZMQ_REP,

	/*!
	 * One to many - fan out.\n
	 * Connect to ::subscribe or ::xsubscribe.\n
	 * Socket is send only with the exception of special subscription messages.\n
	 * Socket will drop messages and not block.\n
	 * \c xpublish act the same as ::publish sockets however also allow special
	 * subscription messages to be received from subscribers.
	 */
	xpublish   = ZMQ_XPUB,

	/*!
	 * One to many - fair-queued.\n
	 * Connect to ::publish or ::xpublish.\n
	 * Socket is receive only with the exception of special subscription messages\n
	 * \c xsubscribe act the same as ::subscribe sockets however also allow special
	 * subscription messages to be send to connected publishers.
	 */
	xsubscribe = ZMQ_XSUB,

	/*!
	 * One to many - fair-queued incoming, load-balanced outgoing.\n
	 * Connect to ::reply or ::xreply.\n
	 * Socket will block if unable to send.\n
	 * An \c xrequest socket balances requests between repliers and pulls replies
	 * back in a fair manner. Each request is expected to have exactly one reply.
	 */
	xrequest   = ZMQ_XREQ,

	/*!
	 * One to many - fair-queued incoming, targeted outgoing.\n
	 * Connect to ::request or ::xrequest.\n
	 * Socket will drop messages and not block.\n
	 * An \c xreply socket fairly pulls in requests from requesters and will
	 * label requests so it can return replies back to the correct target.
	 */
	xreply     = ZMQ_XREP,

	// To match for people who prefer the shorter versions
	pub        = ZMQ_PUB,    /*!< version of ::publish to match zmq name convention */
	sub        = ZMQ_SUB,    /*!< version of ::subscribe to match zmq name convention */
	req        = ZMQ_REQ,    /*!< version of ::request to match zmq name convention */
	rep        = ZMQ_REP,    /*!< version of ::reply to match zmq name convention */
	xpub       = ZMQ_XPUB,   /*!< version of ::xpublish to match zmq name convention */
	xsub       = ZMQ_XSUB,   /*!< version of ::xsubscribe to match zmq name convention */
	xreq       = ZMQ_XREQ,   /*!< version of ::xrequest to match zmq name convention */
	xrep       = ZMQ_XREP,   /*!< version of ::xreply to match zmq name convention */

	// For completion
	router     = ZMQ_ROUTER, /*!< \deprecated Matches zmq 2.x xrep functionality. */
	dealer     = ZMQ_DEALER  /*!< \deprecated Matches zmq 2.x xreq functionality. */
};

}

#endif /* ZMQPP_SOCKET_TYPES_HPP_ */
