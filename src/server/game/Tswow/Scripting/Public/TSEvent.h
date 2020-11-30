/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef TSWOW_EVENT_H
#define TSWOW_EVENT_H

#include <vector>
#include <string>
#include <functional>
#include <exception>

class TSEventHandle;

template <class TSCallback>
class TSEventEntry {
public:
	TSEventHandle* handle;
	TSCallback callback;
	TSEventEntry(TSEventHandle* handle, TSCallback callback)
	{
		this->handle = handle;
		this->callback = callback;
	}
};

template <class TSCallback>
class TSEvent
{
	TSEventEntry<TSCallback>* eventStart;
	size_t size;
public:
	TSEventHandle* Add(TSCallback callback);
	void Remove(size_t index);
	size_t GetSize() { return this->size; }
	TSCallback Get(size_t index) { return this->eventStart[index].callback; }
};

class TSEventHandle
{
public:
	size_t index;
	TSEvent<void*>* evt;
	TSEventHandle(TSEvent<void*>* evt, size_t index)
	{
		this->evt = evt;
		this->index = index;
	}

	void Remove()
	{
		this->evt->Remove(this->index);
	}
};

template <class TSCallback>
TSEventHandle* TSEvent<TSCallback>::Add(TSCallback callback)
{
	size_t entry_size = sizeof(TSEventEntry<TSCallback>);
	TSEventEntry<TSCallback>* ptr = (TSEventEntry<TSCallback>*) malloc(entry_size * (size + 1));
	if (!ptr)
	{
		// TODO Check TC way
		throw std::bad_alloc();
	}

	if (this->size == 0)
	{
		this->eventStart = ptr;
	}
	else
	{
		memcpy(ptr, this->eventStart, this->size * entry_size);
		free(this->eventStart);
		this->eventStart = ptr;
	}

	TSEvent<void*>* vd = (TSEvent<void*>*) this;
	TSEventHandle* handle = new TSEventHandle(vd, this->size);
	this->eventStart[this->size] = TSEventEntry<TSCallback>(handle, callback);
	++this->size;
	return handle;
}

template <class TSCallback>
void TSEvent<TSCallback>::Remove(size_t index)
{
	--this->size;
	size_t entry_size = sizeof(TSEventEntry<TSCallback>);
	if (this->size == 0)
	{
		free(this->eventStart);
		this->eventStart = 0;
		return;
	}
	else {
		TSEventEntry<TSCallback>* ptr = (TSEventEntry<TSCallback>*) malloc(entry_size * this->size);
		if (!ptr)
		{
			// TODO Check TC way
			throw std::bad_alloc();
		}

		if (index > 0)
		{
			memcpy(ptr, this->eventStart, entry_size * index);
		}
		if (index < this->size)
		{
			memcpy(ptr + index, this->eventStart + index + 1, sizeof(TSEventEntry<TSCallback>) * (this->size - index));
		}
		this->eventStart = ptr;

		for (size_t i = index; i < this->size; ++i)
		{
			ptr[i].handle->index--;
		}
	}
}

#define EVENT_TYPE(name,...) typedef void (*name##Type)(__VA_ARGS__);
#define EVENT(name,...) TSEvent<name##Type> name;
#define EVENT_HANDLE(category,name) void name(category##name##Type cb) { Add(this->events->category##name.Add(cb)); }
#define FIRE(name,...) {for(size_t i=0;i< tsEvents.name.GetSize(); ++i) tsEvents.name.Get(i)(__VA_ARGS__);}
#define FIRE_RETURN(name,retType,retVal,...) {retType rv = retVal; for(size_t i=0;i< tsEvents.name.GetSize(); ++i) tsEvents.name.Get(i)(__VA_ARGS__,TSMutable<retType>(&rv)); return retVal;}

class TSEvents;
class EventHandler {
protected:
	std::vector<TSEventHandle*> handles;
	void Add(TSEventHandle* listener) { handles.push_back(listener); }
	TSEvents* events = nullptr;
public:
	void LoadEvents(TSEvents* events)
	{
		this->events = events;
	}

	void Unload() {
		for (TSEventHandle* g : handles)
		{
			g->Remove();
			free(g);
		}
		handles.clear();
	}
};

#endif
