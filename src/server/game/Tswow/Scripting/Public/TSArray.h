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

#include <algorithm>
#include <functional>
#include <vector>
#include <iostream>

template <typename T>
struct TSArrayKeys
{
    typedef TSArrayKeys<T> iterator;

    T _index;
    T _end;

    TSArrayKeys(T end_) : _index(0), _end(end_)
    {
    }

    iterator& begin()
    {
        return *this;
    }

    iterator& end()
    {
        return *this;
    }

    const T& operator*()
    {
        return _index;
    }

    bool operator!=(const iterator& rhs)
    {
        return _index != rhs._end;
    }

    iterator& operator++()
    {
        _index++;
        return *this;
    }
};

template <class T>
struct TSArray {
    std::shared_ptr<std::vector<T>> vec;

public:
    TSArray() {
        this->vec = std::make_shared<std::vector<T>>(0);
    }

    TSArray(size_t size) {
        this->vec = std::make_shared<std::vector<T>>(size);
    }

    TSArray(std::initializer_list<T> list) {
        this->vec = std::make_shared<std::vector<T>>(list);
    }

    TSArray(std::vector<T> vec) {
        // copies the vector
        this->vec = std::make_shared<std::vector<T>>(vec);
    }

    template <typename G>
    G join(G delim)
    {
        G str;
        for (int i = 0; i < this->get_length(); ++i)
        {
            str = str + (*vec)[i];
            if (i < this->get_length() - 1)
            {
                str = str + delim;
            }
        }
        return str;
    }

    auto pop() {
        auto value = (*vec)[vec->size() - 1];
        vec->pop_back();
        return value;
    }

    constexpr TSArray* operator->()
    {
        return this;
    }

    template <typename... Args>
    void splice(size_t position, size_t size, Args... args)
    {
        vec->erase(vec->cbegin() + position, vec->cbegin() + position + size);
        vec->insert(vec->cbegin() + position, { args... });
    }

    template <typename... Args>
    void unshift(Args... args)
    {
        vec->insert(vec->cbegin(), { args... });
    }


    TSArray slice(size_t first, size_t last)
    {
        return TSArray(std::vector<T>(vec->cbegin() + first, vec->cbegin() + last));
    }

    bool includes(const T& e)
    {
        return indexOf(e) != -1;
    }

    int indexOf(const T& e)
    {
        for (int i = 0; i < get_length(); ++i)
        {
            if ((*vec)[i] == e)
            {
                return i;
            }
        }
        return -1;
    }

    int lastIndexOf(const T& e)
    {
        for (int i = get_length() - 1; i >= 0; --i)
        {
            if ((*vec)[i] == e)
            {
                return i;
            }
        }
        return -1;
    }


    bool removeElement(const T& e)
    {
        auto res = vec->erase(std::find(vec->cbegin(), vec->cend(), e)) != vec->cend();
        return res;
    }

    auto keys() {
        return TSArrayKeys<size_t>(vec->size());
    }

    auto begin() {
        return vec->begin();
    }

    auto end() {
        return vec->end();
    }

    auto get_length() {
        return vec->size();
    }

    auto &operator[](int index) {
        return (*vec)[index];
    }

    auto &operator[](int index) const {
        return (*vec)[index];
    }

    auto get(int index) {
        return (*vec)[index];
    }

    auto set(int index, T value) {
        (*vec)[index] = value;
    }

    TSArray<T> filter(std::function<bool(T, size_t)> p)
    {
        std::vector<T> result;
        for (int i = 0; i < get_length(); ++i)
        {
            if (p((*vec)[i], i))
            {
                result.push_back((*vec)[i]);
            }
        }
        return TSArray(result);
    }

    template <typename P>
    auto reduce(P p)
    {
        auto cur = this[0];
        for (int i = 0; i < get_length(); ++i) {
            cur = p(cur, get(i), i);
        }
        return cur;
    }

    template <typename P, typename I>
    auto reduce(P p, I initial)
    {
        I cur = initial;
        for (int i = 0; i < this->vec->size(); ++i)
        {
            cur = p(cur, get(i), i);
        }
        return cur;
    }

    void forEach(std::function<void(T, size_t)> p)
    {
        for (int i = 0; i < vec->size(); ++i) {
            p((*vec)[i], i);
        }
    }

    template <typename... Args>
    void push(Args...args) {
        for (const auto& item : { args... })
        {
            vec->push_back(item);
        }
    }

    T shift()
    {
        T value = (*vec)[0];
        vec->erase(vec->begin());
        return value;
    }

    void insert(uint32_t position, T value)
    {
        vec->insert(vec->begin() + position, value);
    }

    TSArray<T> concat(TSArray<T> addition)
    {
        TSArray<T> clone;
        clone.vec->insert(clone.end(), this->begin(), this->end());
        clone.vec->insert(clone.end(), addition->begin(), addition->end());
        return clone;
    }

    friend std::ostream& operator<<(std::ostream& os, TSArray<T> arr)
    {
        os << "[";
        for (int i = 0; i < arr.get_length(); ++i)
        {
            if (i < arr.get_length() - 1)
            {
                os << arr.get(i) << ",";
            }
            else
            {
                os << arr(i);
            }
        }
        os << "]";
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, TSArray<T>* arr)
    {
        os << (*arr);
        return os;
    }
};