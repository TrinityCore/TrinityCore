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
 
#ifndef TRINITY_CHATCOMMANDARGS_HPP
#define TRINITY_CHATCOMMANDARGS_HPP

#include "Optional.h"
#include <boost/variant.hpp>
#include <cstring>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

class CommandArgs;

namespace Trinity {
namespace ChatCommandArgs {

static const char COMMAND_DELIMITER = ' ';

/***************** HELPERS *************************\
|* These really aren't for outside use...          *|
\***************************************************/
inline size_t tokenize(char const*& end)
{
    size_t len = 0;
    for (; *end && *end != COMMAND_DELIMITER; ++end, ++len);
    for (; *end && *end == COMMAND_DELIMITER; ++end);
    return len;
}

/************************** TAGS ********************************************************\
|* Tags must implement the following methods:                                           *|
|* - tryConsume: char const* -> char const*                                             *|
|*   returns nullptr if no match, otherwise pointer to first character of next token    *|
|* - get<T = value_type>: void -> value_type                                            *|
|*   returns value                                                                      *|
|* - is<T>: void -> bool                                                                *|
|*   returns true iff value is present and of specified type                            *|
|*                                                                                      *|
\****************************************************************************************/
class PlainInteger
{
    public:
        template<typename T = int64>
        T get() const
        {
            static_assert(std::is_integral_v<T>, "Attempt to extract PlainInteger using non-integral type");
            return val;
        }

        template<typename T = PlainInteger>
        static constexpr bool is()
        {
            return std::is_same_v<T, PlainInteger>;
        }

        char const* tryConsume(char const* args)
        {
            char const* next = args;
            std::string token(args, tokenize(next));
            try { val = std::stoll(token); }
            catch (...) { return nullptr; }
            return next;
        }

    private:
        int64 val;

};

class PlainString
{
    public:
        template<typename T = std::string>
        std::string const& get() const
        {
            static_assert(std::is_same_v<std::string, std::remove_const_t<std::remove_reference_t<T>>>, "Attempt to extract PlainString as non-string type");
            return val;
        }

        template<typename T = PlainString>
        static constexpr bool is()
        {
            return std::is_same_v<PlainString, T>;
        }

        char const* tryConsume(char const* args)
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

    private:
        std::string val;
};

template <typename linktag>
class Hyperlink
{
    typedef typename linktag::value_type value_type;

    public:
        template <typename T = value_type>
        T get() const
        {
            static_assert(std::is_trivially_assignable_v<T&, value_type>, "Attempt to extract Hyperlink data using invalid type");
            return val;
        }

        template <typename T = Hyperlink>
        static constexpr bool is()
        {
            return std::is_same_v<Hyperlink, T>;
        }

        char const* tryConsume(char const* pos)
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
            if (!linktag::store(val, datastart, datalength))
                return nullptr;

            // return final pos
            return pos;
        }

    private:
        value_type val;
};

/************************** LINK TAGS ***************************************************\
|* Link tags must abide by the following:                                               *|
|* - MUST expose ::value_type typedef                                                   *|
|* - MUST expose static ::tag method, void -> const char*                               *|
|*   - this method SHOULD be constexpr                                                  *|
|*   - returns identifier string for the link ("creature", "creature_entry", "item")    *|
|* - MUST expose static ::store method, (value_type&, char const*, size_t)              *|
|*   - assign value_type& based on content of std::string(char const*, size_t)          *|
|*   - return value indicates success/failure                                           *|
|*   - for integral/string types this can be achieved by extending base_tag             *|
\****************************************************************************************/
struct base_tag
{
    static bool store(std::string& val, char const* pos, size_t len)
    {
        val.assign(pos, len);
        return true;
    }

    template <typename T>
    static std::enable_if_t<std::is_integral_v<T> && std::is_unsigned_v<T>, bool> store(T& val, char const* pos, size_t len)
    {
        try { val = std::stoull(std::string(val, len)); }
        catch (...) { return false; }
        return true;
    }

    template <typename T>
    static std::enable_if_t<std::is_integral_v<T> && std::is_signed_v<T>, bool> store(T& val, char const* pos, size_t len)
    {
        try { val = std::stoll(std::string(val, len)); }
        catch (...) { return false; }
        return true;
    }
};

template <char c1, char... chars>
struct ExactSequence
{
    template <typename T = void> static constexpr void get() {}
    template <typename T = ExactSequence> static constexpr bool is() { return std::is_same_v<ExactSequence, T>; }

    template <size_t U = sizeof...(chars)>
    static typename std::enable_if_t<U, char const*> tryConsume(char const* pos)
    {
        if (*(pos++) == c1)
            return ExactSequence<chars...>::tryConsume(pos);
        else
            return nullptr;
    }

    template <size_t U = sizeof...(chars)>
    static typename std::enable_if_t<!U, char const*> tryConsume(char const* pos)
    {
        if (*(pos++) != c1)
            return nullptr;
        // if more of string is left, tokenize should return 0 (otherwise we didn't reach end of token yet)
        return *pos && tokenize(pos) ? nullptr : pos;
    }
};

/// specialty tags that enable nesting
/// === OneOf ===
template <typename Tag1, typename... Tags>
class OneOf
{
    using first_type = decltype(std::declval<Tag1>().get());
    public:
        template <typename Type = first_type>
        auto get() const
        {
            return OneOfExtractor<Type>::get<decltype(storage), Tag1, Tags...>(storage, storage.which());
        }

        template <typename Tag>
        bool is() const
        {
            return OneOfExtractor<Type>::is<Tag, Tag1, Tags...>(storage.which());
        }

        bool is() const { return true; }

        char const* tryConsume(char const* args)
        {
            return OneOfConsumer<Tag1, Tags...>::tryConsume(storage, args);
        }

    private:
        boost::variant<Tag1, Tags...> storage;
};

template <typename WantedType>
struct OneOfExtractor
{
    template <typename OtherTag>
    static constexpr bool can_assign_from = std::is_assignable_v<WantedType&, decltype(std::declval<OtherTag>().get<WantedType>()) const&>;

    template <typename StorageType, typename CurrentTag, typename... OtherTags>
    static std::enable_if_t<can_assign_from<CurrentTag> && sizeof...(OtherTags), WantedType> get(StorageType const& storage, size_t index)
    {
        if (index)
            return OneOfExtractor<WantedType>::get<StorageType, OtherTags...>(storage, index - 1);
        else
            return boost::get<CurrentTag>(storage).get<WantedType>();
    }

    template <typename StorageType, typename CurrentTag, typename... OtherTags>
    static std::enable_if_t<can_assign_from<CurrentTag> && !sizeof...(OtherTags), WantedType> get(StorageType const& storage, size_t index)
    {
        ASSERT(!index, "OneOf extraction index out of bounds - data corruption?");
        return boost::get<CurrentTag>(storage).get<WantedType>();
    }

    template <typename StorageType, typename CurrentTag, typename... OtherTags>
    static std::enable_if_t<!can_assign_from<CurrentTag> && sizeof...(OtherTags), WantedType> get(StorageType const& storage, size_t index)
    {
        ASSERT(index, "Invalid OneOf extraction - make sure you check ->is first!");
        return OneOfExtractor<WantedType>::get<StorageType, OtherTags...>(storage, index - 1);
    }

    template <typename StorageType, typename CurrentTag, typename... OtherTags>
    static std::enable_if_t<!can_assign_from<CurrentTag> && !sizeof...(OtherTags), WantedType> get(StorageType const& storage, size_t index)
    {
        if (index)
            ASSERT(false, "OneOf extraction index out of bounds - data corruption?");
        else
            ASSERT(false, "Invalid OneOf extraction - make sure you check ->is first!");
        return WantedType();
    }

    template <typename WantedTag, typename CurrentTag, typename... OtherTags>
    static std::enable_if_t<sizeof...(OtherTags), bool> is(size_t index)
    {
        if (!index)
            return std::is_same_v<WantedTag, CurrentTag>;
        else
            return OneOfExtractor<WantedType>::is<WantedTag, OtherTags...>(index - 1);
    }

    template <typename WantedTag, typename CurrentTag, typename... OtherTags>
    static std::enable_if_t<!sizeof...(OtherTags), bool> is(size_t index)
    {
        ASSERT(!index, "OneOf extraction index out of bounds - data corruption?");
        return std::is_same_v<WantedTag, CurrentTag>;
    }
};

template <typename Tag1, typename... Tags>
struct OneOfConsumer
{
    template <typename T>
    static char const* tryConsume(T& storage, char const* args)
    {
        Tag1 t;
        if (char const* next = t.tryConsume(args))
        {
            storage = t;
            return next;
        }
        else
            return OneOfConsumerNext<Tag1, Tags...>::tryConsume(storage, args);
    }
};

// extra level of indirection to avoid if constexpr :(
template <typename Tag1, typename... Tags>
struct OneOfConsumerNext
{
    template <typename T>
    static char const* tryConsume(T& storage, char const* args)
    {
        return OneOfConsumer<Tags...>::tryConsume(storage, args);
    }
};
template <typename Tag1>
struct OneOfConsumerNext<Tag1>
{
    template <typename T>
    static char const* tryConsume(T&, char const*)
    {
        return nullptr;
    }
};

/// === OptionalArg ===
template <typename Tag>
class OptionalArg
{
    public:
        template <typename T>
        auto get() const
        {
            return val->get<T>();
        }

        auto get() const
        {
            return val->get<>();
        }

        template <typename T>
        bool is() const
        {
            return val && val->is<T>();
        }

        template <int = 0>
        bool is() const
        {
            return val && val->is<>();
        }

        char const* tryConsume(char const* args)
        {
            val.emplace();
            if (char const* next = val->tryConsume(args))
                return next;
            val = boost::none;
            return args;
        }

    private:
        Optional<Tag> val;
};

#define make_base_tag(ltag, type) struct ltag : public base_tag { typedef type value_type; static constexpr char const* tag() { return #ltag; } }
make_base_tag(creature, uint32);
make_base_tag(creature_entry, uint32);
#undef make_base_tag

template <typename... Tags>
class Tuple
{
    private:
        std::tuple<Tags...> values;
    public:
        template <size_t i>
        auto get() const { return std::get<i>(values).get(); }

        template <size_t i, typename T>
        auto get() const { return std::get<i>(values).get<T>(); }

        template <size_t i>
        auto is() const { return std::get<i>(values).is(); }

        template <size_t i, typename T>
        auto is() const { return std::get<i>(values).is<T>(); }

        operator auto() const -> decltype(get<0>()) { return get<0>(); }

    private:
        template <size_t i = 0>
        std::enable_if_t <(i < sizeof...(Tags)), char const*> fill(char const* arg)
        {
            if (char const* next = std::get<i>(values).tryConsume(arg))
                return fill<i + 1>(next);
            else
                return nullptr;
        }

        template <size_t i>
        std::enable_if_t <(i == sizeof...(Tags)), char const*> fill(char const* arg)
        {
            return arg;
        }

    friend class ::CommandArgs;
};

/// === ARGINFO STUFF (used for assigning handler arguments directly) ===
template <typename T, typename = void>
struct ArgInfo { static_assert(!std::is_same_v<T,T>, "Invalid command parameter type - see ChatCommandArgs.hpp for possible types"); };

// catch-all for integral types
template <typename T>
struct ArgInfo<T, std::enable_if_t<std::is_integral_v<T>>>
{
    typedef PlainInteger tag;
    static bool assign(T& ret, tag val) { ret = val.get<T>(); return true; }
};

// string
template <>
struct ArgInfo<std::string, void>
{
    typedef PlainString tag;
    static bool assign(std::string& ret, tag const& val) { ret = val.get(); return true; }
};

// optional
template <typename T>
struct ArgInfo<boost::optional<T>, void>
{
    typedef ArgInfo<T> nested_info;
    typedef OptionalArg<typename nested_info::tag> tag;
    static bool assign(boost::optional<T>& ret, tag const& val)
    {
        if (val)
        {
            T v;
            nested_info::assign(v, *val);
            ret = v;
        }
        else
            ret = boost::none;
        return true;
    }
};

}}

#endif
