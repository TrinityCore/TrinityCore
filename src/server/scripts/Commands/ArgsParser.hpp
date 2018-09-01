/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Define.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include <boost/variant.hpp>
#include <cstring>
#include <string>
#include <type_traits>
#include <utility>

static const char COMMAND_DELIMITER = ' ';

inline size_t tokenize(char const*& end)
{
    size_t len = 0;
    for (; *end && *end != COMMAND_DELIMITER; ++end, ++len);
    for (; *end && *end == COMMAND_DELIMITER; ++end);
    return len;
}

// a base 10 integer
struct PlainInteger
{
    typedef int64 type;

    static char const* tryConsume(char const* args, type& val)
    {
        char const* next = args;
        std::string token(args, tokenize(next));
        try { val = std::stoll(token); }
        catch (...) { return nullptr; }
        return next;
    }
};

// a string
struct PlainString
{
    typedef std::string type;
    static char const* tryConsume(char const* args, type& val)
    {
        char const* next = args;
        if (size_t len = tokenize(next))
        {
            val.assign(args, len);
            return next;
        }
        else
            return nullptr;
    }
};

// links always have the following format:
// |cxxxxxxxx   8 digit argb hex color
// |H           link data start tag
// link tag (e.g. item, itemset, quest, player etc.)
// :            separator
// link data (arbitrary string, must not contain |)
// |h           link data end tag
// actual visible link text (usually wrapped in braces)
// |h           link end tag
// |r           color return instruction
#define makelinktag(s) struct s { static constexpr char const* tag() { return #s; }}
makelinktag(creature);
makelinktag(creature_entry);
template <typename linktag, typename T = PlainInteger::type>
struct Hyperlink
{
    typedef T type;
    static char const* tryConsume(char const* pos, type& val)
    {
        //color tag
        if (*(pos++) != '|' || *(pos++) != 'c')
            return nullptr;
        for (uint8 i = 0; i < 8; ++i)
            if (!*(pos++)) // make sure we don't overrun a terminator
                return nullptr;
        // link data start tag
        if (*(pos++) != '|' || *(pos++) != 'H')
            return nullptr;
        // link tag, should match argument
        char const* tag = linktag::tag();
        while (*tag)
            if (*(pos++) != *(tag++))
                return nullptr;
        // separator
        if (*(pos++) != ':')
            return nullptr;
        // ok, link data, let's figure out how long it is
        char const* datastart = pos;
        size_t datalength = 0;
        while (*pos && *(pos++) != '|')
            ++datalength;
        // ok, next should be link data end tag...
        if (*(pos++) != 'h')
            return nullptr;
        // then visible link text, skip to next '|', should be '|h|r' terminator
        while (*pos && *(pos++) != '|');
        if (*(pos++) != 'h' || *(pos++) != '|' || *(pos++) != 'r')
            return nullptr;
        // finally, skip to end of token
        tokenize(pos);
        // store value
        if (!store(val, datastart, datalength))
            return nullptr;

        // return final pos
        return pos;
    }

    static std::enable_if_t<std::is_integral<T>::value, bool> store(T& val, char const* pos, size_t len)
    {
        try { val = std::stoi({ pos, len }); }
        catch (...) { return false; }
        return true;
    }

    static bool store(std::string& val, char const* pos, size_t len)
    {
        val.assign(pos, len);
        return true;
    }
};

template <char c1, char... chars>
struct ExactSequence
{
    typedef ExactSequence<c1> type; // zero size type
    static char const* tryConsume(char const* pos, type& = type())
    {
        if ((*pos++) == c1)
            return ExactSequence<chars...>::tryConsume(pos);
        else
            return nullptr;
    }
};

template <char c1>
struct ExactSequence<c1>
{
    typedef ExactSequence<c1> type;
    static char const* tryConsume(char const* pos, type& = type())
    {
        if ((*pos++) != c1)
            return nullptr;
        // if tokenize size > 0, then we didn't reach delimiter yet
        return *pos && tokenize(pos) ? nullptr : pos;
    }
};

// returns Optional<Arg::type>, handled entirely within the ArgsTuple partial spec
template <typename Arg>
struct OptionalArg {};

// internal type to differentiate between different tags with the same value type within boost::variant
template <typename ArgTag>
struct TaggedStorage
{
    typedef typename ArgTag::type inner_type;
    typename ArgTag::type value;
};

// either one or the other - lowest level only! no nesting below this (would be a clusterfuck to code)
template <typename Arg1, typename Arg2>
struct OneOf {
    typedef TaggedStorage<Arg1> first_storage;
    typedef typename Arg1::type first_type;
    typedef TaggedStorage<Arg2> second_storage;
    typedef typename Arg2::type second_type;
    static char const* tryConsume(char const* args, boost::variant<first_storage, second_storage>& val)
    {
        first_storage v1;
        if (char const* next = Arg1::tryConsume(args, v1.value))
        {
            val = v1;
            return next;
        }
        second_storage v2;
        if (char const* next = Arg2::tryConsume(args, v2.value))
        {
            val = v2;
            return next;
        }
        return nullptr;
    }
};

// recursion helper struct, because we can't partially specialize member functions for some reason
template <int i, typename Tag>
struct ArgsTupleForwarder
{
    template <typename T1, typename T2>
    static auto get_tagged(T1, T2 v2) { return v2.get<i - 1, Tag>(); }
    template <typename T1, typename T2>
    static auto get_untagged(T1, T2 v2) { return v2.get<i - 1>(); }
    template <typename T1, typename T2>
    static bool is_tagged(T1, T2 v2) { return v2.is<i - 1, Tag>(); }
    template <typename T1, typename T2>
    static bool is_untagged(T1, T2 v2) { return v2.is<i - 1>(); }
};

template <typename Tag>
struct ArgsTupleForwarder<0, Tag>
{
    template <typename T1, typename T2>
    static auto get_tagged(T1 v1, T2) { return v1.get<0, Tag>(); }
    template <typename T1, typename T2>
    static auto get_untagged(T1 v1, T2) { return v1.get<0>(); }
    template <typename T1, typename T2>
    static bool is_tagged(T1 v1, T2) { return v1.is<0, Tag>(); }
    template <typename T1, typename T2>
    static bool is_untagged(T1 v1, T2) { return v1.is<0>(); }
};

// helper struct, i don't want everything as public but otherwise friend declarations become messy
struct FillForwarder
{
    template <typename T1>
    static bool fillMe(T1& v1, char const*& arg)
    {
        return v1.fill(arg);
    }

    template <typename T1, typename T2>
    static bool fillBoth(T1& v1, T2& v2, char const*& arg)
    {
        char const* next = arg;
        if (v1.fill(next) && v2.fill(next))
        {
            arg = next;
            return true;
        }
        else
            return false;
    }
};

template <typename Arg1, typename... Args>
class ArgsTuple
{
    private:
        bool fill(char const*& arg)
        {
            return FillForwarder::fillBoth(first, rest, arg);
        }

    public:
        template <int i, typename ArgTag>
        auto get() const
        {
            return ArgsTupleForwarder<i, ArgTag>::get_tagged(first, rest);
        }

        template <int i>
        auto get() const
        {
            return ArgsTupleForwarder<i, nullptr_t>::get_untagged(first, rest);
        }

        template <int i, typename ArgTag>
        bool is() const
        {
            return ArgsTupleForwarder<i, ArgTag>::is_tagged(first, rest);
        }

        template <int i>
        bool is() const
        {
            return ArgsTupleForwarder<i, nullptr_t>::is_untagged(first, rest);
        }

    private:
        ArgsTuple<Arg1> first;
        ArgsTuple<Args...> rest;

    friend struct FillForwarder;
};

template <typename Arg1, typename Arg2>
class ArgsTuple<OneOf<Arg1, Arg2>>
{
    private:
        bool fill(char const*& arg)
        {
            char const* next = OneOf<Arg1, Arg2>::tryConsume(arg, vals);
            if (next)
            {
                arg = next;
                return true;
            }
            else
                return false;
        }

    public:
        template <int i, typename ArgTag>
        typename ArgTag::type get() const
        {
            static_assert(!i, "Invalid parameter extraction");
            return boost::get<TaggedStorage<ArgTag>>(vals).value;
        }

        template <int i>
        auto get() const
        {
            static_assert(!i && std::is_same<typename Arg1::type, typename Arg2::type>::value, "Invalid parameter extraction");
            if (vals.which())
                return boost::get<TaggedStorage<Arg2>>(vals).value;
            else
                return boost::get<TaggedStorage<Arg1>>(vals).value;
        }

        operator typename Arg1::type() const
        {
            return get<0>();
        }

        template <int i, typename ArgTag>
        bool is() const
        {
            static_assert(!i, "Invalid parameter extraction");
            if (vals.which()) // second type
                return std::is_same<Arg2, ArgTag>::value;
            else // first type
                return std::is_same<Arg1, ArgTag>::value;
        }

        template <int i>
        bool is() const { return true; }

    private:
        boost::variant<TaggedStorage<Arg1>, TaggedStorage<Arg2>> vals;

    friend struct FillForwarder;
};

template <typename Arg>
class ArgsTuple<OptionalArg<Arg>>
{
    private:
        bool fill(char const*& arg)
        {
            ArgsTuple<Arg> v;
            if (FillForwarder::fillMe(v, arg))
                val = v;
            else
                val = boost::none;
            return true;
        }

    public:
        template <int i, typename ArgTag>
        auto get() const
        {
            return val->get<i, ArgTag>();
        }

        template <int i>
        auto get() const
        {
            return val->get<i>();
        }

        template <typename U = Arg, typename = std::enable_if_t<std::is_convertible<ArgsTuple<Arg>, typename Arg::type>::value>>
        operator typename Arg::type() const
        {
            return *val;
        }

        template <int i, typename ArgTag>
        bool is() const
        {
            return val && val->is<i, ArgTag>();
        }

        template <int i>
        bool is() const { return !!val; }

    private:
        Optional<ArgsTuple<Arg>> val;

    friend struct FillForwarder;
};

template <typename Arg>
class ArgsTuple<Arg>
{
    private:
        bool fill(char const*& arg)
        {
            char const* next = Arg::tryConsume(arg, val);
            if (next)
            {
                arg = next;
                return true;
            }
            else
                return false;
        }

    public:
        ArgsTuple() : val() {}
        template <int i, typename ArgTag>
        auto get() const
        {
            static_assert(!i && std::is_same<Arg, ArgTag>::value, "Invalid parameter extraction");
            return val;
        }

        template<int i>
        auto get() const
        {
            static_assert(!i, "Invalid parameter extraction");
            return val;
        }

        // for convenience on single args
        operator typename Arg::type() const
        {
            return val;
        }

        template <int i, typename ArgTag>
        bool is() const
        {
            static_assert(!i, "Invalid parameter extraction");
            return std::is_same<Arg, ArgTag>::value;
        }

    private:
        typename Arg::type val;

    friend struct FillForwarder;
};

class ArgsParser
{
    public:
        ArgsParser(char const* args) : _original(args), _args(args) {}

        template<typename... Args>
        Optional<ArgsTuple<Args...>> tryConsume()
        {
            ArgsTuple<Args...> tuple;
            if (FillForwarder::fillMe(tuple, _args))
                return tuple;
            else
                return boost::none;
        }

        void reset() { _args = _original; }

    private:
        char const* const _original;
        char const* _args;
};
