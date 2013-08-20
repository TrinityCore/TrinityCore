/**
 * \file
 *
 * \date   9 Aug 2011
 * \author Ben Gray (\@benjamg)
 */

#ifndef ZMQPP_MESSAGE_HPP_
#define ZMQPP_MESSAGE_HPP_

#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <zmq.h>

#include "compatibility.hpp"

namespace zmqpp
{
struct zmq_msg_wrapper;

/*!
 * \brief a zmq message with optional multipart support
 *
 * A zmq message is made up of one or more parts which are sent together to
 * the target endpoints. zmq guarantees either the whole message or none
 * of the message will be delivered.
 */
class message
{
public:
	/*!
	 * \brief callback to release user allocated data.
	 *
	 * The release function will be called on any void* moved part.
	 * It must be thread safe to the extent that the callback may occur on
	 * one of the context threads.
	 *
	 * The function called will be passed a single variable which is the
	 * pointer to the memory allocated.
	 */
	typedef std::function<void (void*)> release_function;

	message();
	~message();

	size_t parts() const;
	size_t size(size_t const& part) const;
	std::string get(size_t const& part) const;

	void get(int8_t& integer, size_t const& part) const;
	void get(int16_t& integer, size_t const& part) const;
	void get(int32_t& integer, size_t const& part) const;
	void get(int64_t& integer, size_t const& part) const;

	void get(uint8_t& unsigned_integer, size_t const& part) const;
	void get(uint16_t& unsigned_integer, size_t const& part) const;
	void get(uint32_t& unsigned_integer, size_t const& part) const;
	void get(uint64_t& unsigned_integer, size_t const& part) const;

	void get(float& floating_point, size_t const& part) const;
	void get(double& double_precision, size_t const& part) const;
	void get(bool& boolean, size_t const& part) const;

	void get(std::string& string, size_t const& part) const;

	// Warn: If a pointer type is requested the message (well zmq) still 'owns'
	// the data and will release it when the message object is freed.
	template<typename Type>
	Type get(size_t const& part)
	{
		Type value;
		get(value, part);
		return value;
	}

	// Raw get data operations, useful with data structures more than anything else
	// Warn: The message (well zmq) still 'owns' the data and will release it
	// when the message object is freed.
	template<typename Type>
	void get(Type*& value, size_t const& part) const
	{
		value = static_cast<Type*>(raw_data(part));
	}

	// Warn: The message (well zmq) still 'owns' the data and will release it
	// when the message object is freed.
	template<typename Type>
	void get(Type** value, size_t const& part) const
	{
		*value = static_cast<Type*>(raw_data(part));
	}

	// Move operators will take ownership of message parts without copying
	void move(void* part, size_t& size, release_function const& release);

	// Raw move data operation, useful with data structures more than anything else
	template<typename Object>
	void move(Object *part)
	{
		move(part, sizeof(Object), &deleter_callback<Object>);
	}

	// Copy operators will take copies of any data
	void add(void const* part, size_t const& size);

	template<typename Type>
	void add(Type const& part)
	{
		*this << part;
	}

	// Stream reader style
	void reset_read_cursor();

	template<typename Type>
	message& operator>>(Type& value)
	{
		get(value, _read_cursor++);
		return *this;
	}

	// Stream writer style - these all use copy styles
	message& operator<<(int8_t const& integer);
	message& operator<<(int16_t const& integer);
	message& operator<<(int32_t const& integer);
	message& operator<<(int64_t const& integer);

	message& operator<<(uint8_t const& unsigned_integer);
	message& operator<<(uint16_t const& unsigned_integer);
	message& operator<<(uint32_t const& unsigned_integer);
	message& operator<<(uint64_t const& unsigned_integer);

	message& operator<<(float const& floating_point);
	message& operator<<(double const& double_precision);
	message& operator<<(bool const& boolean);

	message& operator<<(char const* c_string);
	message& operator<<(std::string const& string);

	// Move supporting
	message(message&& source) noexcept;
	message& operator=(message&& source) noexcept;

	// Copy support
	message copy();
	void copy(message& source);

	// Used for internal tracking
	void sent(size_t const& part);

	// Access to raw zmq details
	void const* raw_data(size_t const& part = 0) const;
	zmq_msg_t& raw_msg(size_t const& part = 0);
	zmq_msg_t& raw_new_msg();

private:
	typedef std::vector<zmq_msg_wrapper> parts_type;
	parts_type _parts;
	size_t _read_cursor;

	// Disable implicit copy support, code must request a copy to clone
	message(message const&) noexcept ZMQPP_EXPLICITLY_DELETED;
	message& operator=(message const&) noexcept ZMQPP_EXPLICITLY_DELETED;

	static void release_callback(void* data, void* hint);

	template<typename Object>
	static void deleter_callback(void* data)
	{
		delete static_cast<Object*>(data);
	}
};

}

#endif /* ZMQPP_MESSAGE_HPP_ */
