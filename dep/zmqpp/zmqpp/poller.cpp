/*
 *  Created on: 16 Aug 2011
 *      Author: Ben Gray (@benjamg)
 */

#include "exception.hpp"
#include "socket.hpp"
#include "poller.hpp"

#include <zmq.h>

namespace zmqpp
{

const long poller::wait_forever = -1;
const short poller::poll_none   = 0;
const short poller::poll_in     = ZMQ_POLLIN;
const short poller::poll_out    = ZMQ_POLLOUT;
const short poller::poll_error  = ZMQ_POLLERR;

poller::poller()
	: _items()
	, _index()
	, _fdindex()
{

}

poller::~poller()
{
	_items.clear();
	_index.clear();
	_fdindex.clear();
}

void poller::add(socket& socket, short const event /* = POLL_IN */)
{
	zmq_pollitem_t item { socket, 0, event, 0 };

	size_t index = _items.size();
	_items.push_back(item);
	_index[socket] = index;
}

void poller::add(int const descriptor, short const event /* = POLL_IN */)
{
	zmq_pollitem_t item { nullptr, descriptor, event, 0 };

	size_t index = _items.size();
	_items.push_back(item);
	_fdindex[descriptor] = index;
}

bool poller::has(socket_t const& socket)
{
	return _index.find(socket) != _index.end();
}

bool poller::has(int const descriptor)
{
	return _fdindex.find(descriptor) != _fdindex.end();
}

void poller::reindex(size_t const index)
{
	if ( nullptr != _items[index].socket )
	{
		auto found = _index.find( _items[index].socket );
		if (_index.end() == found) { throw exception("unable to reindex socket in poller"); }
		found->second = index;
	}
	else
	{
		auto found = _fdindex.find( _items[index].fd );
		if (_fdindex.end() == found) { throw exception("unable to reindex file descriptor in poller"); }
		found->second = index;
	}
}

void poller::remove(socket_t const& socket)
{
	auto found = _index.find(socket);
	if (_index.end() == found) { return; }

	if ( _items.size() - 1 == found->second )
	{
		_items.pop_back();
		_index.erase(found);
		return;
	}

	std::swap(_items[found->second], _items.back());
	_items.pop_back();

	auto index = found->second;
	_index.erase(found);

	reindex( index );
}

void poller::remove(int const descriptor)
{
	auto found = _fdindex.find(descriptor);
	if (_fdindex.end() == found) { return; }

	if ( _items.size() - 1 == found->second )
	{
		_items.pop_back();
		_fdindex.erase(found);
		return;
	}

	std::swap(_items[found->second], _items.back());
	_items.pop_back();

	auto index = found->second;
	_fdindex.erase(found);

	reindex( index );
}

void poller::check_for(socket const& socket, short const event)
{
	auto found = _index.find(socket);
	if (_index.end() == found)
	{
		throw exception("this socket is not represented within this poller");
	}

	_items[found->second].events = event;
}

void poller::check_for(int const descriptor, short const event)
{
	auto found = _fdindex.find(descriptor);
	if (_fdindex.end() == found)
	{
		throw exception("this socket is not represented within this poller");
	}

	_items[found->second].events = event;
}

bool poller::poll(long timeout /* = WAIT_FOREVER */)
{
	int result = zmq_poll(_items.data(), _items.size(), timeout);
	if (result < 0)
	{
		if(EINTR == zmq_errno())
		{
			return false;
		}

		throw zmq_internal_exception();
	}

	return (result > 0);
}

short poller::events(socket const& socket) const
{
	auto found = _index.find(socket);
	if (_index.end() == found)
	{
		throw exception("this socket is not represented within this poller");
	}

	return _items[found->second].revents;
}

short poller::events(int const descriptor) const
{
	auto found = _fdindex.find(descriptor);
	if (_fdindex.end() == found)
	{
		throw exception("this file descriptor is not represented within this poller");
	}

	return _items[found->second].revents;
}

}
