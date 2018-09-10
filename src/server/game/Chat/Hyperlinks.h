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

#ifndef TRINITY_HYPERLINKS_H
#define TRINITY_HYPERLINKS_H

#include "advstd.h"
#include "ObjectGuid.h"
#include <string>
#include <utility>

struct AchievementEntry;
struct ItemRandomPropertiesEntry;
struct ItemRandomSuffixEntry;
struct ItemTemplate;

namespace Trinity {
namespace Hyperlinks {

struct AchievementLinkData
{
    AchievementEntry const* achievement;
    ObjectGuid::LowType characterId;
    bool isFinished;
    uint16 year;
    uint8 month;
    uint8 day;
    uint32 criteria[4];
};

struct ItemLinkData
{
    ItemTemplate const* item;
    uint32 enchantId;
    uint32 gemEnchantId[3];
    int32 randomPropertyId;
    int32 randomPropertySeed;
    uint8 renderLevel;
};

namespace LinkTags {

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

#define make_base_tag(ltag, type) struct ltag : public base_tag { using value_type = type; static constexpr char const* tag() { return #ltag; } }
    make_base_tag(areatrigger, uint32);
    make_base_tag(creature, ObjectGuid::LowType);
    make_base_tag(creature_entry, uint32);
    make_base_tag(gameobject, ObjectGuid::LowType);
    make_base_tag(taxinode, uint32);
    make_base_tag(tele, uint32);
#undef make_base_tag

    struct TC_GAME_API achievement
    {
        using value_type = AchievementLinkData const&;
        static constexpr char const* tag() { return "achievement"; }
        static bool StoreTo(AchievementLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API item
    {
        using value_type = ItemLinkData const&;
        static constexpr char const* tag() { return "item"; }
        static bool StoreTo(ItemLinkData& val, char const* pos, size_t len);
    };
}

struct HyperlinkInfo
{
    HyperlinkInfo(char const* n = nullptr, char const* tS = nullptr, size_t tL = 0, char const* dS = nullptr, size_t dL = 0, char const* cS = nullptr, size_t cL = 0) :
        next(n), tag(tS, tL), data(dS, dL), text(cS, cL) {}

    explicit operator bool() { return next; }
    char const* const next;
    std::pair<char const*, size_t> const tag;
    std::pair<char const*, size_t> const data;
    std::pair<char const*, size_t> const text;
};
HyperlinkInfo TC_GAME_API ParseHyperlink(char const* pos);
bool TC_GAME_API ValidateLinks(std::string&);

}}

#endif
