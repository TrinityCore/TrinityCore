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

#include "TSString.h"
#include "TSClass.h"
#include <memory>

inline TSString spaces(int indention) {
	TSString str = JSTR("");
	for (int i = 0; i < indention * 4; ++i) {
		str += " ";
	}
	return str;
}

template <typename A>
inline TSString stringify(A v, int indention = 0)
{
	return spaces(indention) + JSTR("[Unknown Type]");
}

inline TSString stringify(TSString str, int indention = 0)
{
	return TSString(str);
}

#define STRINGIFY_NUM(type) inline TSString stringify(type value, int indention = 0){ \
	return TSString(std::to_string(value)); \
}

STRINGIFY_NUM(int8_t)
STRINGIFY_NUM(int16_t)
STRINGIFY_NUM(int32_t)
STRINGIFY_NUM(int64_t)
STRINGIFY_NUM(uint8_t)
STRINGIFY_NUM(uint16_t)
STRINGIFY_NUM(uint32_t)
STRINGIFY_NUM(uint64_t)
STRINGIFY_NUM(float)
STRINGIFY_NUM(double)

inline TSString stringify(const char * value, int indention = 0) {
	return TSString(value);
}

inline TSString stringify(std::string value, int indention = 0)
{
	return TSString(value);
}

inline TSString stringify(std::shared_ptr<TSClass> ptr, int indention = 0)
{
	return ptr->stringify(indention);
}

template <typename T>
inline TSString stringify(TSArray<T> arr, int indention = 0)
{
	TSString str = JSTR("[");
	for (int i = 0; i < arr.get_length(); ++i) 
	{
		str+=stringify(arr.get(i), indention+1);
		if (i < arr.get_length() - 1)
		{
			str += JSTR(",");
		}
	}
	return str + JSTR("]");
}

template <typename K, typename V>
inline TSString stringify(TSDictionary<K, V> dict, int indention = 0)
{
	TSString str = JSTR("{\n");
	auto keys = dict.keys();
	
	for (int i = 0; i < keys.get_length(); ++i)
	{
		auto key = keys.get(i);
		str += spaces(indention + 1);
		str += stringify(key,indention+1) + JSTR(":") + stringify(dict.get(key), indention+1);
		if (i < keys.get_length() - 1)
		{
			str += JSTR(",");
		}
		str += "\n";
	}
	return str + spaces(indention) + JSTR("}");
}

template <typename K, typename V>
inline TSString stringify(TSDictionary<K, V> * dict, int indention = 0) {
	if (dict == nullptr) return JSTR("null");
	return stringify(*dict);
}

template <typename K, typename V>
inline TSString stringify(std::shared_ptr<TSDictionary<K, V>> dict, int indention = 0) {
	if (dict == nullptr) return JSTR("null");
	return stringify(*dict);
}

template <typename T>
inline TSString stringify(TSArray<T>* arr, int indention = 0) {
	if (arr == nullptr) return JSTR("null");
	return stringify(*arr);
}

template <typename T>
inline TSString stringify(std::shared_ptr<TSArray<T>> arr, int indention = 0) {
	if (arr == nullptr) return JSTR("null");
	return stringify(*arr);
}