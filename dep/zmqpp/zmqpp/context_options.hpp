/**
 * \file
 *
 * \date   3 Jul 2013
 * \author Ben Gray (\@benjamg)
 */

#ifndef ZMQPP_CONTEXT_OPTIONS_HPP_
#define ZMQPP_CONTEXT_OPTIONS_HPP_

namespace zmqpp
{

/** \todo Expand the information on the options to make it actually useful. */
/*!
 * \brief possible Context options in zmq
 */

enum class context_option {
	io_threads  = ZMQ_IO_THREADS,          /*!< I/O thread count */
	max_sockets = ZMQ_MAX_SOCKETS,         /*!< Maximum supported sockets */
};

}

#endif /* ZMQPP_CONTEXT_OPTIONS_HPP_ */
