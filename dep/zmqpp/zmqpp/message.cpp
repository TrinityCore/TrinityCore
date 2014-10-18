/*
 *  Created on: 9 Aug 2011
 *      Author: Ben Gray (@benjamg)
 */

#include <cassert>
#include <cstring>

#include "exception.hpp"
#include "inet.hpp"
#include "message.hpp"

namespace zmqpp
{

/*!
 * \brief internal construct
 * \internal handles bubbling callback from zmq c style to the c++ functor provided
 */
struct callback_releaser
{
	message::release_function func;
};

message::message()
	: _parts()
	, _read_cursor(0)
{
}

message::~message()
{
	_parts.clear();
}

size_t message::parts() const
{
	return _parts.size();
}

/*
 * The two const_casts in size and raw_data are a little bit hacky
 * but neither of these methods called this way actually modify data
 * so accurately represent the intent of these calls.
 */

size_t message::size(size_t const part /* = 0 */) const
{
	if(part >= _parts.size())
	{
		throw exception("attempting to request a message part outside the valid range");
	}

	return _parts[part].size();
}

void const* message::raw_data(size_t const part /* = 0 */) const
{
	if(part >= _parts.size())
	{
		throw exception("attempting to request a message part outside the valid range");
	}

	return _parts[part].data();
}

zmq_msg_t& message::raw_msg(size_t const part /* = 0 */)
{
	if(part >= _parts.size())
	{
		throw exception("attempting to request a message part outside the valid range");
	}

	return _parts[part].msg();
}

zmq_msg_t& message::raw_new_msg()
{
	_parts.push_back( frame() );

	return _parts.back().msg();
}

zmq_msg_t& message::raw_new_msg(size_t const reserve_data_size)
{
	_parts.push_back( frame(reserve_data_size) );

	return _parts.back().msg();
}

std::string message::get(size_t const part /* = 0 */) const
{
	return std::string(static_cast<char const*>(raw_data(part)), size(part));
}


// Move operators will take ownership of message parts without copying
void message::move(void* part, size_t const size, release_function const& release)
{
	callback_releaser* hint = new callback_releaser();
	hint->func = release;

	_parts.push_back( frame( part, size, &message::release_callback, hint ) );
}

// Stream reader style
void message::reset_read_cursor()
{
	_read_cursor = 0;
}

void message::get(int8_t& integer, size_t const part) const
{
	assert(sizeof(int8_t) == size(part));

	int8_t const* byte = static_cast<int8_t const*>(raw_data(part));
	integer = *byte;
}

void message::get(int16_t& integer, size_t const part) const
{
	assert(sizeof(int16_t) == size(part));

	uint16_t const* network_order = static_cast<uint16_t const*>(raw_data(part));
	integer = static_cast<int16_t>(ntohs(*network_order));
}

void message::get(int32_t& integer, size_t const part) const
{
	assert(sizeof(int32_t) == size(part));

	uint32_t const* network_order = static_cast<uint32_t const*>(raw_data(part));
	integer = static_cast<int32_t>(htonl(*network_order));
}

void message::get(int64_t& integer, size_t const part) const
{
	assert(sizeof(int64_t) == size(part));

	uint64_t const* network_order = static_cast<uint64_t const*>(raw_data(part));
	integer = static_cast<int64_t>(zmqpp::htonll(*network_order));
}

void message::get(uint8_t& unsigned_integer, size_t const part) const
{
	assert(sizeof(uint8_t) == size(part));

	uint8_t const* byte = static_cast<uint8_t const*>(raw_data(part));
	unsigned_integer = *byte;
}

void message::get(uint16_t& unsigned_integer, size_t const part) const
{
	assert(sizeof(uint16_t) == size(part));

	uint16_t const* network_order = static_cast<uint16_t const*>(raw_data(part));
	unsigned_integer = ntohs(*network_order);
}

void message::get(uint32_t& unsigned_integer, size_t const part) const
{
	assert(sizeof(uint32_t) == size(part));

	uint32_t const* network_order = static_cast<uint32_t const*>(raw_data(part));
	unsigned_integer = ntohl(*network_order);
}

void message::get(uint64_t& unsigned_integer, size_t const part) const
{
	assert(sizeof(uint64_t) == size(part));

	uint64_t const* network_order = static_cast<uint64_t const*>(raw_data(part));
	unsigned_integer = zmqpp::ntohll(*network_order);
}

void message::get(float& floating_point, size_t const part) const
{
	assert(sizeof(float) == size(part));

	float const* network_order = static_cast<float const*>(raw_data(part));
	floating_point = zmqpp::ntohf(*network_order);
}

void message::get(double& double_precision, size_t const part) const
{
	assert(sizeof(double) == size(part));

	double const* network_order = static_cast<double const*>(raw_data(part));
	double_precision = zmqpp::ntohd(*network_order);
}

void message::get(bool& boolean, size_t const part) const
{
	assert(sizeof(uint8_t) == size(part));

	uint8_t const* byte = static_cast<uint8_t const*>(raw_data(part));
	boolean = (*byte != 0);
}

void message::get(std::string& string, size_t const part) const
{
	string.assign( get(part) );
}


// Stream writer style - these all use copy styles
message& message::operator<<(int8_t const integer)
{
        add(reinterpret_cast<void const*>(&integer), sizeof(int8_t));
	return *this;
}

message& message::operator<<(int16_t const integer)
{
	uint16_t network_order = htons(static_cast<uint16_t>(integer));
	add(reinterpret_cast<void const*>(&network_order), sizeof(uint16_t));

	return *this;
}

message& message::operator<<(int32_t const integer)
{
	uint32_t network_order = htonl(static_cast<uint32_t>(integer));
	add(reinterpret_cast<void const*>(&network_order), sizeof(uint32_t));

	return *this;
}

message& message::operator<<(int64_t const integer)
{
	uint64_t network_order = zmqpp::htonll(static_cast<uint64_t>(integer));
	add(reinterpret_cast<void const*>(&network_order), sizeof(uint64_t));

	return *this;
}


message& message::operator<<(uint8_t const unsigned_integer)
{
        add(reinterpret_cast<void const*>(&unsigned_integer), sizeof(uint8_t));
	return *this;
}

message& message::operator<<(uint16_t const unsigned_integer)
{
	uint16_t network_order = htons(unsigned_integer);
	add(reinterpret_cast<void const*>(&network_order), sizeof(uint16_t));

	return *this;
}

message& message::operator<<(uint32_t const unsigned_integer)
{
	uint32_t network_order = htonl(unsigned_integer);
	add(reinterpret_cast<void const*>(&network_order), sizeof(uint32_t));

	return *this;
}

message& message::operator<<(uint64_t const unsigned_integer)
{
	uint64_t network_order = zmqpp::htonll(unsigned_integer);
	add(reinterpret_cast<void const*>(&network_order), sizeof(uint64_t));

	return *this;
}

message& message::operator<<(float const floating_point)
{
	assert(sizeof(float) == 4);

	float network_order = zmqpp::htonf(floating_point);
	add(&network_order, sizeof(float));

	return *this;
}

message& message::operator<<(double const double_precision)
{
	assert(sizeof(double) == 8);

	double network_order = zmqpp::htond(double_precision);
	add(&network_order, sizeof(double));

	return *this;
}

message& message::operator<<(bool const boolean)
{
	uint8_t byte = (boolean) ? 1 : 0;
	add(reinterpret_cast<void const*>(&byte), sizeof(uint8_t));

	return *this;
}

message& message::operator<<(char const* c_string)
{
        add(reinterpret_cast<void const*>(c_string), strlen(c_string));
	return *this;
}

message& message::operator<<(std::string const& string)
{
        add(reinterpret_cast<void const*>(string.data()), string.size());
	return *this;
}

void message::push_front(void const* part, size_t const size)
{
	_parts.emplace( _parts.begin(), part, size );
}

void message::push_front(int8_t const integer)
{
	push_front(&integer, sizeof(int8_t));
}

void message::push_front(int16_t const integer)
{
	uint16_t network_order = htons(static_cast<uint16_t>(integer));
	push_front(&network_order, sizeof(uint16_t));
}

void message::push_front(int32_t const integer)
{
	uint32_t network_order = htonl(static_cast<uint32_t>(integer));
	push_front(&network_order, sizeof(uint32_t));
}

void message::push_front(int64_t const integer)
{
	uint64_t network_order = zmqpp::htonll(static_cast<uint64_t>(integer));
	push_front(&network_order, sizeof(uint64_t));
}


void message::push_front(uint8_t const unsigned_integer)
{
	push_front(&unsigned_integer, sizeof(uint8_t));
}

void message::push_front(uint16_t const unsigned_integer)
{
	uint16_t network_order = htons(unsigned_integer);
	push_front(&network_order, sizeof(uint16_t));
}

void message::push_front(uint32_t const unsigned_integer)
{
	uint32_t network_order = htonl(unsigned_integer);
	push_front(&network_order, sizeof(uint32_t));
}

void message::push_front(uint64_t const unsigned_integer)
{
	uint64_t network_order = zmqpp::htonll(unsigned_integer);
	push_front(&network_order, sizeof(uint64_t));
}

void message::push_front(float const floating_point)
{
	assert(sizeof(float) == 4);

	float network_order = zmqpp::htonf(floating_point);
	push_front(&network_order, sizeof(float));
}

void message::push_front(double const double_precision)
{
	assert(sizeof(double) == 8);

	double network_order = zmqpp::htond(double_precision);
	push_front(&network_order, sizeof(double));
}

void message::push_front(bool const boolean)
{
	uint8_t byte = (boolean) ? 1 : 0;
	push_front(&byte, sizeof(uint8_t));
}

void message::push_front(char const* c_string)
{
	push_front(c_string, strlen(c_string));
}

void message::push_front(std::string const& string)
{
	push_front(string.data(), string.size());
}

void message::pop_front()
{
	_parts.erase( _parts.begin() );
}

void message::pop_back()
{
	_parts.pop_back();
}

message::message(message&& source) NOEXCEPT
	: _parts()
	, _read_cursor(0)
{
	std::swap(_parts, source._parts);
}

message& message::operator=(message&& source) NOEXCEPT
{
	std::swap(_parts, source._parts);
	return *this;
}

message message::copy() const
{
	message msg;
	msg.copy(*this);
	return msg;
}

void message::copy(message const& source)
{
	_parts.resize( source._parts.size() );
	for(size_t i = 0; i < source._parts.size(); ++i)
	{
		_parts[i] = source._parts[i].copy();
	}

	// we don't need a copy of the releasers as we did data copies of the internal data,
	//_releasers = source._releasers;
	//_strings = source._strings
}

// Used for internal tracking
void message::sent(size_t const part)
{
	// sanity check
	assert(!_parts[part].is_sent());
	_parts[part].mark_sent();
}

// Note that these releasers are not thread safe, the only safety is provided by
// the socket class taking ownership so no updates can happen while zmq does it's thing
// If used in a custom class this has to be dealt with.
void message::release_callback(void* data, void* hint)
{
	callback_releaser* releaser = static_cast<callback_releaser*>(hint);
	releaser->func(data);

	delete releaser;
}

}
