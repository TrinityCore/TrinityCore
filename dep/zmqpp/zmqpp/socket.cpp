/*
 *  Created on: 9 Aug 2011
 *      Author: Ben Gray (@benjamg)
 */

#include <array>
#include <cassert>
#include <cstring>
#include <functional>

#include "context.hpp"
#include "exception.hpp"
#include "message.hpp"
#include "socket.hpp"

namespace zmqpp
{

const int socket::normal = 0;
#if (ZMQ_VERSION_MAJOR == 2)
const int socket::dont_wait = ZMQ_NOBLOCK;
#else
const int socket::dont_wait = ZMQ_DONTWAIT;
#endif
const int socket::send_more = ZMQ_SNDMORE;
#ifdef ZMQ_EXPERIMENTAL_LABELS
const int socket::send_label = ZMQ_SNDLABEL;
#endif

const int max_socket_option_buffer_size = 256;
const int max_stream_buffer_size = 4096;

socket::socket(const context& context, socket_type const type)
	: _socket(nullptr)
	, _type(type)
	, _recv_buffer()
{
	_socket = zmq_socket(context, static_cast<int>(type));
	if(nullptr == _socket)
	{
		throw zmq_internal_exception();
	}

	zmq_msg_init(&_recv_buffer);
}

socket::~socket()
{
	zmq_msg_close(&_recv_buffer);

	if (nullptr != _socket)
	{

#ifndef NDEBUG // unused assert variable in release
		int result = zmq_close(_socket);
		assert(0 == result);
#else
		zmq_close(_socket);
#endif // NDEBUG

		_socket = nullptr;
	}
}

void socket::bind(endpoint_t const& endpoint)
{
	int result = zmq_bind(_socket, endpoint.c_str());

	if (0 != result)
	{
		throw zmq_internal_exception();
	}
}

void socket::unbind(endpoint_t const& endpoint)
{
	int result = zmq_unbind(_socket, endpoint.c_str());

	if (0 != result)
	{
		throw zmq_internal_exception();
	}
}

void socket::connect(endpoint_t const& endpoint)
{
	int result = zmq_connect(_socket, endpoint.c_str());

	if (0 != result)
	{
		throw zmq_internal_exception();
	}
}

void socket::disconnect(endpoint_t const& endpoint)
{
	int result = zmq_disconnect(_socket, endpoint.c_str());

	if (0 != result)
	{
		throw zmq_internal_exception();
	}
}

void socket::close()
{
	int result = zmq_close(_socket);

	if (0 != result)
	{
		throw zmq_internal_exception();
	}

	_socket = nullptr;
}

bool socket::send(message& message, bool const dont_block /* = false */)
{
	size_t parts = message.parts();
	if (parts == 0)
	{
		throw std::invalid_argument("sending requires messages have at least one part");
	}

	bool dont_wait = dont_block;
	for(size_t i = 0; i < parts; ++i)
	{
		int flag = socket::normal;
		if(dont_wait) { flag |= socket::dont_wait; }
		if(i < (parts - 1)) { flag |= socket::send_more; }

#if (ZMQ_VERSION_MAJOR == 2)
		int result = zmq_send( _socket, &message.raw_msg(i), flag );
#elif (ZMQ_VERSION_MAJOR < 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR < 2))
		int result = zmq_sendmsg( _socket, &message.raw_msg(i), flag );
#else
		int result = zmq_msg_send( &message.raw_msg(i), _socket, flag );
#endif

		if (result < 0)
		{
			// the zmq framework should not block if the first part is accepted
			// so we should only ever get this error on the first part
			if((0 == i) && (EAGAIN == zmq_errno()))
			{
				return false;
			}

			if(EINTR == zmq_errno())
			{
				if (0 == message.parts())
				{
					return false;
				}

				// If we have an interrupt but it's not on the first part then we
				// know we can safely send out the rest of the message as we can
				// enforce that it won't wait on a blocking action
				dont_wait = true;
				continue;
			}

			// sanity checking
			assert(EAGAIN != zmq_errno());

			throw zmq_internal_exception();
		}

		message.sent(i);
	}

	// Leave message reference in a stable state
	zmqpp::message local;
	std::swap(local, message);
	return true;
}

bool socket::receive(message& message, bool const dont_block /* = false */)
{
	if (message.parts() > 0)
	{
		// swap and discard old message
		zmqpp::message local;
		std::swap(local, message);
	}

	int flags = (dont_block) ? socket::dont_wait : socket::normal;
	bool more = true;

	while(more)
	{
#if (ZMQ_VERSION_MAJOR == 2)
		int result = zmq_recv( _socket, &_recv_buffer, flags );
#elif (ZMQ_VERSION_MAJOR < 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR < 2))
		int result = zmq_recvmsg( _socket, &_recv_buffer, flags );
#else
		int result = zmq_msg_recv( &_recv_buffer, _socket, flags );
#endif

		if(result < 0)
		{
			if ((0 == message.parts()) && (EAGAIN == zmq_errno()))
			{
				return false;
			}

			if(EINTR == zmq_errno())
			{
				if (0 == message.parts())
				{
					return false;
				}

				// If we have an interrupt but it's not on the first part then we
				// know we can safely pull out the rest of the message as it will
				// not be blocking
				continue;
			}

			assert(EAGAIN != zmq_errno());

			throw zmq_internal_exception();
		}

		zmq_msg_t& dest = message.raw_new_msg();
		zmq_msg_move(&dest, &_recv_buffer);

		get(socket_option::receive_more, more);
	}

	return true;
}


bool socket::send(std::string const& string, int const flags /* = NORMAL */)
{
	return send_raw(string.data(), string.size(), flags);
}

bool socket::receive(std::string& string, int const flags /* = NORMAL */)
{
#if (ZMQ_VERSION_MAJOR == 2)
		int result = zmq_recv( _socket, &_recv_buffer, flags );
#elif (ZMQ_VERSION_MAJOR < 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR < 2))
		int result = zmq_recvmsg( _socket, &_recv_buffer, flags );
#else
		int result = zmq_msg_recv( &_recv_buffer, _socket, flags );
#endif

	if(result >= 0)
	{
		string.reserve(zmq_msg_size(&_recv_buffer));
		string.assign(static_cast<char*>(zmq_msg_data(&_recv_buffer)), zmq_msg_size(&_recv_buffer));

		return true;
	}

	if (EAGAIN == zmq_errno() || EINTR == zmq_errno())
	{
		return false;
	}

	throw zmq_internal_exception();
}


bool socket::send_raw(char const* buffer, int const length, int const flags /* = NORMAL */)
{
#if (ZMQ_VERSION_MAJOR == 2)
    zmq_msg_t msg;
    int result = zmq_msg_init_size(&msg, length);
    if (result != 0)
    {
    	zmq_internal_exception();
    }

    memcpy(zmq_msg_data(&msg), buffer, length);
    result = zmq_send(_socket, &msg, flags);
#else
	int result = zmq_send(_socket, buffer, length, flags);
#endif
	if(result >= 0)
	{
		return true;
	}

#if (ZMQ_VERSION_MAJOR == 2)
	// only actually need to close this on error
    zmq_msg_close(&msg);
#endif

	if (EAGAIN == zmq_errno() || EINTR == zmq_errno())
	{
		return false;
	}

	throw zmq_internal_exception();
}

bool socket::receive_raw(char* buffer, int& length, int const flags /* = NORMAL */)
{
#if (ZMQ_VERSION_MAJOR == 2)
		int result = zmq_recv( _socket, &_recv_buffer, flags );
#elif (ZMQ_VERSION_MAJOR < 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR < 2))
		int result = zmq_recvmsg( _socket, &_recv_buffer, flags );
#else
		int result = zmq_msg_recv( &_recv_buffer, _socket, flags );
#endif

	if(result >= 0)
	{
		length = zmq_msg_size(&_recv_buffer);
		memcpy(buffer, zmq_msg_data(&_recv_buffer), length);

		return true;
	}

	if (EAGAIN == zmq_errno() || EINTR == zmq_errno())
	{
		return false;
	}

	throw zmq_internal_exception();
}


// Helper
void socket::subscribe(std::string const& topic)
{
	set(socket_option::subscribe, topic);
}

void socket::unsubscribe(std::string const& topic)
{
	set(socket_option::unsubscribe, topic);
}

bool socket::has_more_parts() const
{
	return get<bool>(socket_option::receive_more);
}


// Set socket options for different types of option
void socket::set(socket_option const option, int const value)
{
	switch(option)
	{
	// unsigned 64bit Integers
#if (ZMQ_VERSION_MAJOR == 2)
	case socket_option::high_water_mark:
	case socket_option::send_buffer_size:
	case socket_option::receive_buffer_size:
#endif
	case socket_option::affinity:
		if (value < 0) { throw exception("attempting to set an unsigned 64 bit integer option with a negative integer"); }
		set(option, static_cast<uint64_t>(value));
		break;

	// 64bit Integers
#if (ZMQ_VERSION_MAJOR == 2)
	case socket_option::rate:
	case socket_option::recovery_interval:
	case socket_option::recovery_interval_seconds:
	case socket_option::swap_size:
#else
	case socket_option::max_messsage_size:
#endif
		set(option, static_cast<int64_t>(value));
		break;

	// Boolean
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 1))
	case socket_option::ipv4_only:
#endif
#if (ZMQ_VERSION_MAJOR == 2)
	case socket_option::multicast_loopback:
#endif
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 2))
#if (ZMQ_VERSION_MINOR == 2)
	case socket_option::delay_attach_on_connect:
#else
	case socket_option::immediate:
#endif
	case socket_option::router_mandatory:
	case socket_option::xpub_verbose:
#endif
		if (value == 0) { set(option, false); }
		else if (value == 1) { set(option, true); }
		else { throw exception("attempting to set a boolean option with a non 0 or 1 integer"); }
		break;

	// Default or Boolean
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 2))
	case socket_option::tcp_keepalive:
		if (value < -1 || value > 1) { throw exception("attempting to set a default or boolean option with a non -1, 0 or 1 integer"); }
		if (0 != zmq_setsockopt(_socket, static_cast<int>(option), &value, sizeof(value)))
		{
			throw zmq_internal_exception();
		}
		break;
#endif

	// Integers that require +ve numbers
#if (ZMQ_VERSION_MAJOR == 2)
	case socket_option::reconnect_interval_max:
#else
	case socket_option::reconnect_interval_max:
	case socket_option::send_buffer_size:
	case socket_option::recovery_interval:
	case socket_option::receive_buffer_size:
	case socket_option::send_high_water_mark:
	case socket_option::receive_high_water_mark:
	case socket_option::multicast_hops:
	case socket_option::rate:
#endif
	case socket_option::backlog:
		if (value < 0) { throw exception("attempting to set a positive only integer option with a negative integer"); }
		// Integers
	case socket_option::reconnect_interval:
	case socket_option::linger:
	case socket_option::receive_timeout:
	case socket_option::send_timeout:
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 2))
	case socket_option::tcp_keepalive_idle:
	case socket_option::tcp_keepalive_count:
	case socket_option::tcp_keepalive_interval:
#endif
		if (0 != zmq_setsockopt(_socket, static_cast<int>(option), &value, sizeof(value)))
		{
			throw zmq_internal_exception();
		}
		break;
	default:
		throw exception("attempting to set a non signed integer option with a signed integer value");
	}
}

void socket::set(socket_option const option, bool const value)
{
	switch(option)
	{
#if (ZMQ_VERSION_MAJOR == 2)
	case socket_option::multicast_loopback:
#endif
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 1))
	case socket_option::ipv4_only:
#endif
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 2))
#if (ZMQ_VERSION_MINOR == 2)
	case socket_option::delay_attach_on_connect:
#else
	case socket_option::immediate:
#endif
	case socket_option::router_mandatory:
	case socket_option::xpub_verbose:
#endif
	{
		int ivalue = value ? 1 : 0;
		if (0 != zmq_setsockopt(_socket, static_cast<int>(option), &ivalue, sizeof(ivalue)))
		{
			throw zmq_internal_exception();
		}
		break;
	}
	default:
		throw exception("attempting to set a non boolean option with a boolean value");
	}
}

void socket::set(socket_option const option, uint64_t const value)
{
	switch(option)
	{
#if (ZMQ_VERSION_MAJOR == 2)
	// unsigned 64bit Integers
	case socket_option::high_water_mark:
	case socket_option::send_buffer_size:
	case socket_option::receive_buffer_size:
#endif
	case socket_option::affinity:
		if (0 != zmq_setsockopt(_socket, static_cast<int>(option), &value, sizeof(value)))
		{
			throw zmq_internal_exception();
		}
		break;
	default:
		throw exception("attempting to set a non unsigned 64 bit integer option with a unsigned 64 bit integer value");
	}
}

void socket::set(socket_option const option, int64_t const value)
{
	switch(option)
	{
#if (ZMQ_VERSION_MAJOR == 2)
	case socket_option::rate:
	case socket_option::recovery_interval:
	case socket_option::recovery_interval_seconds:
	case socket_option::swap_size:
#else
	case socket_option::max_messsage_size:
#endif
		// zmq only allowed +ve int64_t options
		if (value < 0) { throw exception("attempting to set a positive only 64 bit integer option with a negative 64bit integer"); }
		if (0 != zmq_setsockopt(_socket, static_cast<int>(option), &value, sizeof(value)))
		{
			throw zmq_internal_exception();
		}
		break;
	default:
		throw exception("attempting to set a non 64 bit integer option with a 64 bit integer value");
	}
}

void socket::set(socket_option const option, char const* value, size_t const length)
{
	switch(option)
	{
	case socket_option::identity:
	case socket_option::subscribe:
	case socket_option::unsubscribe:
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 2))
	case socket_option::tcp_accept_filter:
#endif
		if (0 != zmq_setsockopt(_socket, static_cast<int>(option), value, length))
		{
			throw zmq_internal_exception();
		}
		break;
	default:
		throw exception("attempting to set a non string option with a string value");
	}
}

// Get socket options, multiple versions for easy of use
void socket::get(socket_option const option, int& value) const
{
	size_t value_size = sizeof(int);

	switch(option)
	{
#if (ZMQ_VERSION_MAJOR == 2)
	case socket_option::receive_more:
	case socket_option::multicast_loopback:
		value = static_cast<int>(get<int64_t>(option));
		break;
#endif
	case socket_option::type:
	case socket_option::linger:
	case socket_option::backlog:
	case socket_option::reconnect_interval:
	case socket_option::reconnect_interval_max:
	case socket_option::receive_timeout:
	case socket_option::send_timeout:
	case socket_option::file_descriptor:
	case socket_option::events:
#if (ZMQ_VERSION_MAJOR > 2)
	case socket_option::receive_more:
	case socket_option::send_buffer_size:
	case socket_option::receive_buffer_size:
	case socket_option::rate:
	case socket_option::recovery_interval:
	case socket_option::send_high_water_mark:
	case socket_option::receive_high_water_mark:
	case socket_option::multicast_hops:
#endif
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 1))
	case socket_option::ipv4_only:
#endif
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 2))
#if (ZMQ_VERSION_MINOR == 2)
	case socket_option::delay_attach_on_connect:
#else
	case socket_option::immediate:
#endif
	case socket_option::tcp_keepalive:
	case socket_option::tcp_keepalive_idle:
	case socket_option::tcp_keepalive_count:
	case socket_option::tcp_keepalive_interval:
#endif
#ifdef ZMQ_EXPERIMENTAL_LABELS
	case socket_option::receive_label:
#endif
		if (0 != zmq_getsockopt(_socket, static_cast<int>(option), &value, &value_size))
		{
			throw zmq_internal_exception();
		}

		// sanity check
		assert(value_size <= sizeof(int));
		break;
	default:
		throw exception("attempting to get a non integer option with an integer value");
	}
}

void socket::get(socket_option const option, bool& value) const
{
#if (ZMQ_VERSION_MAJOR == 2)
	int64_t int_value = 0;
	size_t value_size = sizeof(int64_t);
#else
	int int_value = 0;
	size_t value_size = sizeof(int);
#endif

	switch(option)
	{
	case socket_option::receive_more:
#if (ZMQ_VERSION_MAJOR == 2)
	case socket_option::multicast_loopback:
#endif
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 1))
	case socket_option::ipv4_only:
#endif
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 2))
#if (ZMQ_VERSION_MINOR == 2)
	case socket_option::delay_attach_on_connect:
#else
	case socket_option::immediate:
#endif
#endif
#ifdef ZMQ_EXPERIMENTAL_LABELS
	case socket_option::receive_label:
#endif
		if (0 != zmq_getsockopt(_socket, static_cast<int>(option), &int_value, &value_size))
		{
			throw zmq_internal_exception();
		}

		value = (int_value == 1) ? true : false;
		break;
	default:
		throw exception("attempting to get a non boolean option with a boolean value");
	}
}

void socket::get(socket_option const option, uint64_t& value) const
{
	size_t value_size = sizeof(uint64_t);

	switch(option)
	{
#if (ZMQ_VERSION_MAJOR == 2)
	case socket_option::high_water_mark:
	case socket_option::send_buffer_size:
	case socket_option::receive_buffer_size:
#endif
	case socket_option::affinity:
		if(0 != zmq_getsockopt(_socket, static_cast<int>(option), &value, &value_size))
		{
			throw zmq_internal_exception();
		}
		break;
	default:
		throw exception("attempting to get a non unsigned 64 bit integer option with an unsigned 64 bit integer value");
	}
}

void socket::get(socket_option const option, int64_t& value) const
{
	size_t value_size = sizeof(int64_t);

	switch(option)
	{
#if (ZMQ_VERSION_MAJOR == 2)
	case socket_option::rate:
	case socket_option::recovery_interval:
	case socket_option::recovery_interval_seconds:
	case socket_option::swap_size:
	case socket_option::receive_more:
	case socket_option::multicast_loopback:
#else
	case socket_option::max_messsage_size:
#endif
		if(0 != zmq_getsockopt(_socket, static_cast<int>(option), &value, &value_size))
		{
			throw zmq_internal_exception();
		}
		break;
	default:
		throw exception("attempting to get a non 64 bit integer option with an 64 bit integer value");
	}
}

void socket::get(socket_option const option, std::string& value) const
{
	static std::array<char, max_socket_option_buffer_size> buffer;
	size_t size = max_socket_option_buffer_size;

	switch(option)
	{
	case socket_option::identity:
#if (ZMQ_VERSION_MAJOR > 3) || ((ZMQ_VERSION_MAJOR == 3) && (ZMQ_VERSION_MINOR >= 2))
	case socket_option::last_endpoint:
#endif
		if(0 != zmq_getsockopt(_socket, static_cast<int>(option), buffer.data(), &size))
		{
			throw zmq_internal_exception();
		}

		value.assign(buffer.data(), size);
		break;
	default:
		throw exception("attempting to get a non string option with a string value");
	}
}

socket::socket(socket&& source) NOEXCEPT
	: _socket(source._socket)
	, _type(source._type)
	, _recv_buffer()
{
	// we steal the zmq_msg_t from the valid socket, we only init our own because it's cheap
	// and zmq_msg_move does a valid check
	zmq_msg_init(&_recv_buffer);
	zmq_msg_move(&_recv_buffer, &source._recv_buffer);

	// Clean up source a little, we will handle the deinit, it doesn't need to
	source._socket = nullptr;
}

socket& socket::operator=(socket&& source) NOEXCEPT
{
	std::swap(_socket, source._socket);

	_type = source._type; // just clone?

	// we steal the zmq_msg_t from the valid socket, we only init our own because it's cheap
	// and zmq_msg_move does a valid check
	zmq_msg_init(&_recv_buffer);
	zmq_msg_move(&_recv_buffer, &source._recv_buffer);

	return *this;
}


socket::operator bool() const
{
	return nullptr != _socket;
}


socket::operator void*() const
{
	return _socket;
}

void socket::track_message(message const& /* message */, uint32_t const parts, bool& should_delete)
{
	if (parts == 0)
	{
		should_delete = true;
	}
}

}
