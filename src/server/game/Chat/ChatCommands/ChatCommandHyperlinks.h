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

#ifndef TRINITY_CHATCOMMANDHYPERLINKS_H
#define TRINITY_CHATCOMMANDHYPERLINKS_H

#include "ChatCommandHelpers.h"
#include "ChatCommandTags.h"
#include "ObjectGuid.h"

namespace Trinity {
namespace ChatCommands {

// for details on what ContainerTag has to expose, see ChatCommandTags.h
template <typename linktag>
struct Hyperlink : public ContainerTag
{
    typedef typename linktag::value_type value_type;
    typedef advstd::remove_cvref_t<value_type> storage_type;

    public:
        operator value_type() const { return val; }

        char const* TryConsume(char const* pos)
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
            if (!linktag::StoreTo(val, datastart, datalength))
                return nullptr;

            // return final pos
            return pos;
        }

    private:
        storage_type val;
};

/************************** LINK TAGS ***************************************************\
|* Link tags must abide by the following:                                               *|
|* - MUST expose ::value_type typedef                                                   *|
|*   - storage type is remove_cvref_t<value_type>                                       *|
|* - MUST expose static ::tag method, void -> const char*                               *|
|*   - this method SHOULD be constexpr                                                  *|
|*   - returns identifier string for the link ("creature", "creature_entry", "item")    *|
|* - MUST expose static ::StoreTo method, (storage&, char const*, size_t)               *|
|*   - assign value_type& based on content of std::string(char const*, size_t)          *|
|*   - return value indicates success/failure                                           *|
|*   - for integral/string types this can be achieved by extending base_tag             *|
\****************************************************************************************/
struct base_tag
{
    static bool StoreTo(std::string& val, char const* pos, size_t len)
    {
        val.assign(pos, len);
        return true;
    }

    template <typename T>
    static std::enable_if_t<advstd::is_integral_v<T> && advstd::is_unsigned_v<T>, bool> StoreTo(T& val, char const* pos, size_t len)
    {
        try { val = std::stoull(std::string(pos, len)); }
        catch (...) { return false; }
        return true;
    }

    template <typename T>
    static std::enable_if_t<advstd::is_integral_v<T> && advstd::is_signed_v<T>, bool> StoreTo(T& val, char const* pos, size_t len)
    {
        try { val = std::stoll(std::string(pos, len)); }
        catch (...) { return false; }
        return true;
    }
};

#define make_base_tag(ltag, type) struct ltag : public base_tag { typedef type value_type; static constexpr char const* tag() { return #ltag; } }
make_base_tag(areatrigger, uint32);
make_base_tag(creature, ObjectGuid::LowType);
make_base_tag(creature_entry, uint32);
make_base_tag(gameobject, ObjectGuid::LowType);
make_base_tag(taxinode, uint32);
make_base_tag(tele, uint32);
#undef make_base_tag

}}

#endif

