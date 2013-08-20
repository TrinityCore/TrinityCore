/**
 * \file
 *
 * \date   9 Aug 2011
 * \author Ben Gray (\@benjamg)
 */

#ifndef ZMQPP_CONTEXT_HPP_
#define ZMQPP_CONTEXT_HPP_

#include <cassert>

#include <zmq.h>

#include "compatibility.hpp"
#include "exception.hpp"
#if (ZMQ_VERSION_MAJOR > 3) or ((ZMQ_VERSION_MAJOR == 3) and (ZMQ_VERSION_MINOR >= 2))
#include "context_options.hpp"
#endif

namespace zmqpp
{

/*!
 * The context class represents internal zmq context and io threads.
 *
 * By default the context class will create one thread, however this can be
 * overridden in the constructor.
 *
 * The context class is the only object that can be considered thread safe.
 *
 * All sockets using endpoints other than inproc require the context to have
 * at least one thread.
 *
 * This class is c++0x move supporting and cannot be copied.
 */
class context
{
public:

#if (ZMQ_VERSION_MAJOR < 3) or ((ZMQ_VERSION_MAJOR == 3) and (ZMQ_VERSION_MINOR < 2))
	/*!
	 * Initialise the 0mq context.
	 *
	 * If only inproc is used then the context may be created with zero threads.
	 * Any inproc endpoint using sockets must be created using the same context.
	 *
	 * The context is thread safe an may be used anywhere in your application,
	 * however there is no requirement (other than inproc restrictions) for you
	 * to do this.
	 *
	 * \param threads an integer argument for the number of required threads. Defaults to 1.
	 */
	context(int const& threads = 1)
#else
	/*!
	 * Initialise the 0mq context.
	 *
	 * The context is thread safe an may be used anywhere in your application,
	 * however there is no requirement (other than inproc restrictions) for you
	 * to do this.
	 */
	context()
#endif
		: _context(nullptr)
	{
#if (ZMQ_VERSION_MAJOR < 3) or ((ZMQ_VERSION_MAJOR == 3) and (ZMQ_VERSION_MINOR < 2))
		_context = zmq_init(threads);
#else
		_context = zmq_ctx_new();
#endif

		if (nullptr == _context)
		{
			throw zmq_internal_exception();
		}
	}

	/*!
	 * Closes the 0mq context.
	 *
	 * Any blocking calls other than a socket close will return with an error.
	 *
	 * If there are open sockets will block while zmq internal buffers are
	 * processed up to a limit specified by that sockets linger option.
	 */
	~context() noexcept
	{
		if (nullptr != _context)
		{

#ifndef NDEBUG // unused assert variable in release
#if (ZMQ_VERSION_MAJOR < 3) or ((ZMQ_VERSION_MAJOR == 3) and (ZMQ_VERSION_MINOR < 2))
			int result = zmq_term(_context);
#else
			int result = zmq_ctx_destroy(_context);
#endif
			assert(0 == result);
#else
#if (ZMQ_VERSION_MAJOR < 3) or ((ZMQ_VERSION_MAJOR == 3) and (ZMQ_VERSION_MINOR < 2))
			zmq_term(_context);
#else
			zmq_ctx_destroy(_context);
#endif
#endif // NDEBUG

			_context = nullptr;
		}
	}

	/*!
	 * Move supporting constructor.
	 *
	 * Allows zero-copy move semantics to be used with this class.
	 *
	 * \param source a rvalue instance of the object who's internals we wish to steal.
	 */
	context(context&& source) noexcept
	{
		_context = source._context;
		source._context = nullptr;
	}

	/*!
	 * Move supporting operator.
	 *
	 * Allows zero-copy move semantics to be used with this class.
	 *
	 * \param source an rvalue instance of the context who's internals we wish to steal.
	 */
	context& operator=(context&& source) noexcept
	{
		_context = source._context;
		source._context = nullptr;
		return *this;
	}

	/*!
	 * Terminate the current context.
	 *
	 * Any blocking calls other than a socket close will return with an error.
	 *
	 * If there are open sockets will block while zmq internal buffers are
	 * processed up to a limit specified by that sockets linger option.
	 */
	void terminate();

#if (ZMQ_VERSION_MAJOR > 3) or ((ZMQ_VERSION_MAJOR == 3) and (ZMQ_VERSION_MINOR >= 2))
	/*!
	 * Set the value of an option in the underlaying zmq context.
	 *
	 * \param option a valid ::context_option
	 * \param value to set the option to
	 */
	void set(context_option const& option, int const& value);

	/*!
	 * Get a context option from the underlaying zmq context.
	 *
	 * \param option a valid ::context_option
	 * \return context option value
	 */
	int get(context_option const& option);
#endif

	/*!
	 * Validity checking of the context
	 *
	 * Checks if the underlying 0mq context for this instance is valid.
	 *
	 * Contexts should always be valid unless people are doing 'fun' things with
	 * std::move.
	 *
	 * \return boolean true if the object is valid.
	 */
	operator bool() const noexcept
	{
		return nullptr != _context;
	}

	/*!
	 * Access to the raw 0mq context
	 *
	 * \return void pointer to the underlying 0mq context.
	 */
	operator void*() const noexcept
	{
		return _context;
	}

private:
	void* _context;

	// No copy - private and not implemented
	context(context const&) ZMQPP_EXPLICITLY_DELETED;
	context& operator=(context const&) noexcept ZMQPP_EXPLICITLY_DELETED;
};

}

#endif /* ZMQPP_CONTEXT_HPP_ */
