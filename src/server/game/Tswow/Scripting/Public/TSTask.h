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
#pragma once

#include <functional>
#include <chrono>
#include "TSString.h"
#include "TSArray.h"
#include "TSMutable.h"

static uint64_t now()
{
	return std::chrono::duration_cast<std::chrono::milliseconds>
		(std::chrono::high_resolution_clock::now().time_since_epoch()).count();
}

#define TimerCallback std::function<void(TSTimer<T>*,T,uint32_t, TSMutable<bool>)>

template <typename T>
struct TSTimer {
	TSTimer() {}

	uint32_t delay;
	uint32_t lastTick;
	uint32_t repeats;
	uint32_t modid;

	TimerCallback callback;
	TSString name;
	TSTimer(uint32_t modid, TSString name, uint32_t delay, uint32_t repeats, TimerCallback callback)
	{
		this->modid = modid;
		this->delay = delay;
		this->callback = callback;
		this->name = name;
		this->repeats = repeats;
		this->lastTick = now();
	}

	bool Tick(T context)
	{
		uint64_t n = now();

		uint64_t diff = n - lastTick;

		uint64_t loops = delay == 0 ? 1 : diff / delay;

		if (repeats != 0)
		{
			loops = loops < repeats ? loops : repeats;
		}

		bool stop = false;
		for (uint64_t loop = 0; loop < loops; ++loop)
		{
			callback(this,context, diff, TSMutable<bool>(&stop));
			this->lastTick = n;
			if(stop)
			{
				return true;
			}
		}

		if (repeats != 0)
		{
			repeats -= loops;
			if (repeats == 0)
			{
				return true;
			}
		}

		return false;
	}
};

template <typename T>
struct TSTasks {
	TSArray<TSTimer<T>> timers;

	TSTasks* operator->() { return this; }

	void AddTimer(uint32_t modid, TSString name, uint32_t time, uint32_t repeats, TimerCallback callback)
	{
		for (int i = 0; i < timers.get_length(); ++i)
		{
			if (timers[i].name == name)
			{
				timers.set(i,TSTimer<T>(modid, name, time, repeats, callback));
				return;
			}
		}
		timers.push(TSTimer<T>(modid, name, time, repeats, callback));
	}

	void RemoveTimer(TSString name)
	{
		timers = timers.filter([=](TSTimer<T> &timer, size_t index) mutable {
			return timer.name != name;
		});
	}

	void Tick(T context)
	{
		auto it = timers.vec->begin();
		while (it != timers.vec->end())
		{
			if (it->Tick(context))
			{
				it = timers.vec->erase(it);
			}
			else
			{
				++it;
			}
		}
	}
};