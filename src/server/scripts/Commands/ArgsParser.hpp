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

#ifndef TRINITY_ARGSPARSER_HPP
#define TRINITY_ARGSPARSER_HPP

#include "Define.h"
#include "Errors.h"
#include "ObjectGuid.h"
#include "Optional.h"
#include <boost/variant.hpp>
#include <cstring>
#include <string>
#include <tuple>
#include <type_traits>
#include <utility>

namespace Trinity {
namespace CommandArgs {

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

/****** INTERFACING CLASSES *****************************************\
|* These are what the caller code gets to see                       *|
|* - Construct your Parser with char const* to first token          *|
|* - Call tryConsume<Tag1, Tag2, ...>()                             *|
|* - Get Optional<Tuple<Tag1, Tag2, ...>>() back                    *|
|* - If the Optional contains a value, the Parser consumed input    *|
\********************************************************************/
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

    friend class Parser;
};

class Parser
{
    public:
        Parser(char const* args) : _original(args), _args(args) {}

        template <typename... Args>
        Optional<Tuple<Args...>> tryConsume()
        {
            Optional<Tuple<Args...>> ret;
            ret.emplace();
            if (char const* next = ret->fill(_args))
                _args = next;
            else
                ret = boost::none;
            return ret;
        }

        void reset() { _args = _original; }

    private:
        char const* const _original;
        char const* _args;
};

}
}

#endif
