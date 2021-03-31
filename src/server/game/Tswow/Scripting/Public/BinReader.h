/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2021 tswow <https://github.com/tswow/>
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

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <cstring>
#include <cmath>
#include <cstdint>
#include <algorithm>
#include <memory>
#include "TSArray.h"
#include "TSString.h"

template <typename L>
class BinReader {
	uint8_t* arr;
	L length;
public:
	BinReader(uint8_t* arr, L length)
	{
		this->arr = arr;
		this->length = length;
	}

	BinReader* operator->(){return this;}

	template <typename T>
	T Read(L offset) { return *((T*)(arr + offset)); }
	template <typename T>
	void Write(L offset, T value) { *((T*)(arr + offset)) = value; }

	template <typename T>
	void ReadArray(L offset, TSArray<T> arr, L max)
	{
		L len = std::min(max,Read<L>(offset));
		arr.vec->resize(len);
		for (L i = 0; i < len; ++i)
		{
			arr.set(i, Read<T>(offset+sizeof(L)+sizeof(T)*i));
		}
	}
	
	template <typename T>
	void WriteArray(L offset, TSArray<T> arr, L max)
	{
		L len = std::min(max, L(arr.get_length()));
		Write<L>(offset,len);
		for (L i = 0; i < len; ++i)
		{
			Write(offset+sizeof(L)+sizeof(T)*i,arr.get(i));
		}
	}

	TSString ReadString(L offset, L max)
	{
		auto len = std::min(Read<L>(offset), max);
		return TSString(std::string((char*)(arr + offset + sizeof(L)), len));
	}

	void WriteString(L offset, TSString string, L max)
	{
		auto len = std::min(L(string.get_length()),max);
		Write<L>(offset,len);
		strncpy((char*)((arr + offset + sizeof(L))), string.std_str().c_str(), len);
	}

	void WriteStringArray(L offset, TSArray<TSString> arr, L arrMax, L strMax)
	{
		auto len = std::min(L(arr.get_length()), arrMax);
		Write<L>(offset, len);
		for (L i = 0; i < len; ++i)
		{
			WriteString(offset + sizeof(L) + (strMax+sizeof(L)) * i, arr.get(i), strMax);
		}
	}

	void ReadStringArray(L offset, TSArray<TSString> arr, L arrMax, L strMax)
	{
		auto len = std::min(Read<L>(offset), arrMax);
		arr.vec->resize(len);
		for (L i = 0; i < len; ++i)
		{
			arr.set(i, ReadString(offset + sizeof(L) + (strMax+sizeof(L)) * i,strMax));
		}
	}

	void WriteDouble(L offset, double value)
	{
		auto disc = std::floor(value);
		auto frac = std::round((value-disc)*100000);
		Write<int32_t>(offset,disc);
		Write<int32_t>(offset+4,frac);
	}

	double ReadDouble(L offset)
	{
		double disc = (double) Read<int32_t>(offset);
		double frac = ((double)Read<int32_t>(offset+4))/100000;
		return disc+frac;
	}

	void WriteArrayDouble(L offset, TSArray<double> arr, L max)
	{
		L len = std::min(max,L(arr.get_length()));
		Write<L>(offset,len);
		for(L i = 0; i < len; ++i)
		{
			WriteDouble(offset+sizeof(L)+2*sizeof(uint32_t)*i,arr.get(i));
		}
	}

	void ReadArrayDouble(L offset, TSArray<double> arr, L max)
	{
		L len = std::min(max,Read<L>(offset));
		arr.vec->resize(len);
		for(L i = 0; i < len; ++i)
		{
			arr.set(i,ReadDouble(offset+sizeof(L)+2*sizeof(uint32_t)*i));
		}
	}

	template <typename T>
	void WriteClass(L offset, std::shared_ptr<T> value)
	{
		value->Write(arr+offset);
	}

	template <typename T> 
	void ReadClass(L offset, std::shared_ptr<T> value)
	{
		value->Read(arr+offset);
	}

	template <typename T>
	void ReadClassArray(L offset, TSArray<std::shared_ptr<T>> arr, L max, L ind_size, std::function<std::shared_ptr<T>()> constructor)
	{
		auto len = std::min(max, Read<L>(offset));
		arr.vec->resize(len);
		for (L i = 0; i < len; ++i)
		{
			auto cls = constructor();
			ReadClass<T>(offset+sizeof(L)+ind_size*i,cls);
			arr.set(i,cls);
		}
	}

	template <typename T>
	void WriteClassArray(L offset, TSArray<std::shared_ptr<T>> arr, L max, L ind_size)
	{
		auto len = std::min(L(arr.get_length()), max);
		Write<L>(offset,len);
		for (L i = 0; i < len; ++i)
		{
			WriteClass<T>(offset + sizeof(L) + ind_size * i,arr.get(i));
		}
	}
};