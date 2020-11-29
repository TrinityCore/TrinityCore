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

template <typename T>
struct TSArray {
    std::vector<T> vec;

public:
    TSArray() {

    }

    TSArray(size_t size) {
        this->vec = std::vector<T>(size);
    }

    TSArray(std::initializer_list<T> list) {
        this->vec = list;
    }

    TSArray(std::vector<T> vec) {
        this->vec = vec;
    }

    auto pop() {
        return vec.pop_back();
    }

    constexpr TSArray* operator->()
    {
        return this;
    }

    std::ostream& operator<<(std::ostream& os)
    {
        os << "[";
        for (auto& g : this) {
            os << g << ",";
        }
        os << "]";
        return os;
    }

    template <typename... Args>
    void splice(size_t position, size_t size, Args... args)
    {
        vec.erase(vec.cbegin() + position, vec.cbegin() + position + size);
        vec.insert(vec.cbegin() + position, { args... });
    }

    TSArray slice(size_t first, size_t last)
    {
        return TSArray(std::vector<T>(vec.cbegin() + first, vec.cbegin() + last + 1));
    }

    int indexOf(const T& e)
    {
        return vec.cend() - std::find(vec.cbegin(), vec.cend(), e) - 1;
    }

    bool removeElement(const T& e)
    {
        return vec.erase(std::find(vec.cbegin(), vec.cend(), e)) != vec.cend();
    }


    auto keys() {
        return TSArrayKeys<size_t>(vec.size());
    }

    auto begin() {
        return vec.begin();
    }

    auto end() {
        return vec.end();
    }

    auto get_length() {
        return vec.size();
    }

    auto operator[](int index) {
        return vec[index];
    }

    auto operator[](int index) const {
        return vec[index];
    }

    TSArray filter(std::function<bool(T)> p)
    {
        std::vector<T> result;
        std::copy_if(vec.begin(), vec.end(), std::back_inserter(result), p);
        return TSArray(result);
    }

    TSArray filter(std::function<bool(T, size_t)> p)
    {
        std::vector<T> result;
        auto first = &(vec)[0];
        std::copy_if(vec.begin(), vec.end(), std::back_inserter(result), [=](auto& v) {
            auto index = &v - first;
            return p(v, index);
        });
        return TSArray(result);
    }

    template <typename F, class = decltype(F()(T()))>
    auto map(F p)->TSArray< decltype(p(T())) >
    {
        std::vector< decltype(p(T())) > result;
        std::transform(vec.begin(), vec.end(), std::back_inserter(result), [=](auto& v) {
            return mutable_(p)(v);
        });
        return TSArray< decltype(p(T())) >(result);
    }

    template <typename F, class = decltype(F()(T(), 0))>
    auto map(F p)->TSArray< decltype(p(T(), 0)) >
    {
        std::vector< decltype(p(T(), 0)) > result;
        auto first = &(vec)[0];
        std::transform(vec.begin(), vec.end(), std::back_inserter(result), [=](auto& v) {
            auto index = &v - first;
            return mutable_(p)(v, index);
        });
        return TSArray< decltype(p(T(), 0)) >(result);
    }

    template <typename P>
    auto reduce(P p)
    {
        // TODO enable (clang++ doesn't like reduce even in c++17)
        return this[0];
        //return std::reduce(vec.begin(), vec.end(), 0, p);
    }

    template <typename P, typename I>
    auto reduce(P p, I initial)
    {
        // TODO enable (clang++ doesn't like reduce even in c++17)
        return initial;
        //return std::reduce(vec.begin(), vec.end(), initial, p);
    }

    void forEach(std::function<void(T)> p)
    {
        std::for_each(vec.begin(), vec.end(), p);
    }

    void forEach(std::function<void(T, size_t)> p)
    {
        for (int i = 0; i < vec.size(); ++i) {
            p(vec[i], i);
        }
    }

    template <typename... Args>
    void push(Args...args) {
        for (const auto& item : { args... })
        {
            vec.push_back(item);
        }
    }
};