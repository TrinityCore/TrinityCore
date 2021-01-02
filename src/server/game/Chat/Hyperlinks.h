/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "ObjectGuid.h"
#include "StringConvert.h"
#include <array>
#include <string>
#include <string_view>
#include <type_traits>
#include <utility>

struct AchievementEntry;
struct GlyphPropertiesEntry;
struct GlyphSlotEntry;
struct ItemRandomPropertiesEntry;
struct ItemRandomSuffixEntry;
struct ItemTemplate;
class SpellInfo;
class Quest;
struct TalentEntry;

namespace Trinity::Hyperlinks
{

    struct AchievementLinkData
    {
        AchievementEntry const* Achievement;
        ObjectGuid CharacterId;
        bool IsFinished;
        uint8 Year;
        uint8 Month;
        uint8 Day;
        std::array<uint32, 4> Criteria;
    };

    struct GlyphLinkData
    {
        GlyphPropertiesEntry const* Glyph;
        GlyphSlotEntry const* Slot;
    };

    struct ItemLinkData
    {
        ItemTemplate const* Item;
        uint32 EnchantId;
        std::array<uint32, 3> GemEnchantId;
        ItemRandomPropertiesEntry const* RandomProperty;
        ItemRandomSuffixEntry const* RandomSuffix;
        uint32 RandomSuffixBaseAmount; /* ITEM_FIELD_PROPERTY_SEED - only nonzero for RandomSuffix items, AllocationPct from DBC are multiplied with this, then floored, to get stat value */
        uint8 RenderLevel;
        bool IsBuggedInspectLink;
    };

    struct QuestLinkData
    {
        ::Quest const* Quest;
        int16 QuestLevel;
    };

    struct TalentLinkData
    {
        TalentEntry const* Talent;
        uint8 Rank;
        SpellInfo const* Spell;
    };

    struct TradeskillLinkData
    {
        SpellInfo const* Spell;
        uint16 CurValue;
        uint16 MaxValue;
        ObjectGuid Owner;
        std::string KnownRecipes;
    };

    namespace LinkTags {

        /************************** LINK TAGS ***************************************************\
        |* Link tags must abide by the following:                                               *|
        |* - MUST expose ::value_type typedef                                                   *|
        |*   - storage type is remove_cvref_t<value_type>                                       *|
        |* - MUST expose static ::tag method, void -> std::string_view                          *|
        |*   - this method SHOULD be constexpr                                                  *|
        |*   - returns identifier string for the link ("creature", "creature_entry", "item")    *|
        |* - MUST expose static ::StoreTo method, (storage&, std::string_view)                  *|
        |*   - assign storage& based on content of std::string_view                             *|
        |*   - return value indicates success/failure                                           *|
        |*   - for integral/string types this can be achieved by extending base_tag             *|
        \****************************************************************************************/
        struct base_tag
        {
            static bool StoreTo(std::string_view& val, std::string_view data)
            {
                val = data;
                return true;
            }

            static bool StoreTo(std::string& val, std::string_view data)
            {
                val.assign(data);
                return true;
            }

            template <typename T>
            static std::enable_if_t<std::is_integral_v<T>, bool> StoreTo(T& val, std::string_view data)
            {
                if (Optional<T> res = Trinity::StringTo<T>(data))
                {
                    val = *res;
                    return true;
                }
                else
                    return false;
            }

            static bool StoreTo(ObjectGuid& val, std::string_view data)
            {
                if (Optional<uint64> res = Trinity::StringTo<uint64>(data, 16))
                {
                    val.Set(*res);
                    return true;
                }
                else
                    return false;
            }
        };

    #define make_base_tag(ltag, type) struct ltag : public base_tag { using value_type = type; static constexpr std::string_view tag() { return #ltag; } }
        make_base_tag(area, uint32);
        make_base_tag(areatrigger, uint32);
        make_base_tag(creature, ObjectGuid::LowType);
        make_base_tag(creature_entry, uint32);
        make_base_tag(gameevent, uint16);
        make_base_tag(gameobject, ObjectGuid::LowType);
        make_base_tag(gameobject_entry, uint32);
        make_base_tag(itemset, uint32);
        make_base_tag(player, std::string_view);
        make_base_tag(skill, uint32);
        make_base_tag(taxinode, uint32);
        make_base_tag(tele, uint32);
        make_base_tag(title, uint32);
    #undef make_base_tag

        struct TC_GAME_API achievement
        {
            using value_type = AchievementLinkData const&;
            static constexpr std::string_view tag() { return "achievement"; }
            static bool StoreTo(AchievementLinkData& val, std::string_view data);
        };

        struct TC_GAME_API enchant
        {
            using value_type = SpellInfo const*;
            static constexpr std::string_view tag() { return "enchant"; }
            static bool StoreTo(SpellInfo const*& val, std::string_view data);
        };

        struct TC_GAME_API glyph
        {
            using value_type = GlyphLinkData const&;
            static constexpr std::string_view tag() { return "glyph"; };
            static bool StoreTo(GlyphLinkData& val, std::string_view data);
        };

        struct TC_GAME_API item
        {
            using value_type = ItemLinkData const&;
            static constexpr std::string_view tag() { return "item"; }
            static bool StoreTo(ItemLinkData& val, std::string_view data);
        };

        struct TC_GAME_API quest
        {
            using value_type = QuestLinkData const&;
            static constexpr std::string_view tag() { return "quest"; }
            static bool StoreTo(QuestLinkData& val, std::string_view data);
        };

        struct TC_GAME_API spell
        {
            using value_type = SpellInfo const*;
            static constexpr std::string_view tag() { return "spell"; }
            static bool StoreTo(SpellInfo const*& val, std::string_view data);
        };

        struct TC_GAME_API talent
        {
            using value_type = TalentLinkData const&;
            static constexpr std::string_view tag() { return "talent"; }
            static bool StoreTo(TalentLinkData& val, std::string_view data);
        };

        struct TC_GAME_API trade
        {
            using value_type = TradeskillLinkData const&;
            static constexpr std::string_view tag() { return "trade"; }
            static bool StoreTo(TradeskillLinkData& val, std::string_view data);
        };
    }

    struct HyperlinkColor
    {
        HyperlinkColor(uint32 c) : r(c >> 16), g(c >> 8), b(c), a(c >> 24) {}
        uint8 const r, g, b, a;
        bool operator==(uint32 c) const
        {
            if ((c & 0xff) ^ b)
                return false;
            if (((c >>= 8) & 0xff) ^ g)
                return false;
            if (((c >>= 8) & 0xff) ^ r)
                return false;
            if ((c >>= 8) ^ a)
                return false;
            return true;
        }
    };

    struct HyperlinkInfo
    {
        HyperlinkInfo() : ok(false), color(0) {}
        HyperlinkInfo(std::string_view t, uint32 c, std::string_view ta, std::string_view d, std::string_view te) :
            ok(true), tail(t), color(c), tag(ta), data(d), text(te) {}

        explicit operator bool() { return ok; }
        bool const ok;
        std::string_view const tail;
        HyperlinkColor const color;
        std::string_view const tag;
        std::string_view const data;
        std::string_view const text;
    };
    HyperlinkInfo TC_GAME_API ParseSingleHyperlink(std::string_view str);
    bool TC_GAME_API CheckAllLinks(std::string_view str);

}

#endif
