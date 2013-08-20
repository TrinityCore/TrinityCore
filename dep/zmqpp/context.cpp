/**
 * \file
 *
 * \date   9 Aug 2011
 * \author Ben Gray (\@benjamg)
 */

#include "context.hpp"

namespace zmqpp
{

void context::terminate()
{
#if (ZMQ_VERSION_MAJOR < 3) or ((ZMQ_VERSION_MAJOR == 3) and (ZMQ_VERSION_MINOR < 2))
	int result = zmq_term(_context);
#else
	int result = zmq_ctx_destroy(_context);
#endif
	if (result != 0) { throw zmq_internal_exception(); }
	_context = nullptr;
}

#if (ZMQ_VERSION_MAJOR > 3) or ((ZMQ_VERSION_MAJOR == 3) and (ZMQ_VERSION_MINOR >= 2))
void context::set(context_option const& option, int const& value)
{
	if (nullptr == _context) { throw invalid_instance("context is invalid"); }

	if (0 != zmq_ctx_set(_context, static_cast<int>(option), value))
	{
		throw zmq_internal_exception();
	}
}

int context::get(context_option const& option)
{
	if (nullptr == _context) { throw invalid_instance("context is invalid"); }

	int result = zmq_ctx_get(_context, static_cast<int>(option));

	if (result < 0)
	{
		throw zmq_internal_exception();
	}

	return result;
}
#endif

}
