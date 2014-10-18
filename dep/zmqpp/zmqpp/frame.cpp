/**
 * \file
 *
 * \date   8 Jan 2014
 * \author Ben Gray (\@benjamg)
 */

#include <cassert>
#include <cstring>

#include "exception.hpp"
#include "frame.hpp"

namespace zmqpp {

frame::frame()
	: _sent( false )
{
	if( 0 != zmq_msg_init( &_msg ) )
	{
		throw zmq_internal_exception();
	}
}

frame::frame(size_t const size)
	: _sent( false )
{
	if( 0 != zmq_msg_init_size( &_msg, size ) )
	{
		throw zmq_internal_exception();
	}
}

frame::frame(void const* part, size_t const size)
	: _sent( false )
{
	if( 0 != zmq_msg_init_size( &_msg, size ) )
	{
		throw zmq_internal_exception();
	}

	void* msg_data = zmq_msg_data( &_msg );
	memcpy( msg_data, part, size );
}

frame::frame(void* part, size_t const size, zmq_free_fn *ffn, void *hint)
	: _sent( false )
{
	if( 0 != zmq_msg_init_data( &_msg, part, size, ffn, hint ) )
	{
		throw zmq_internal_exception();
	}
}

frame::~frame()
{
#ifndef NDEBUG // unused assert variable in release
	int result = zmq_msg_close( &_msg );
	assert(0 == result);
#else
	zmq_msg_close( &_msg );
#endif // NDEBUG
}

frame::frame(frame&& other)
	: _sent( other._sent )
{
	zmq_msg_init( &_msg );
	zmq_msg_move( &_msg, &other._msg );
	other._sent = false;
}

frame& frame::operator=(frame&& other)
{
	zmq_msg_init( &_msg );
	zmq_msg_move( &_msg, &other._msg );
	std::swap( _sent, other._sent );

	return *this;
}

frame frame::copy() const
{
	frame other( size() );
	other._sent = _sent;

	if( 0 != zmq_msg_copy( &other._msg, const_cast<zmq_msg_t*>(&_msg) ) )
	{
		throw zmq_internal_exception();
	}

	return other;
}

} // namespace zmqpp
