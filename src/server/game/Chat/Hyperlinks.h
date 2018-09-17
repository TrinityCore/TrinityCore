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
#include "Optional.h"
#include <string>
#include <utility>

struct AchievementEntry;
struct ArtifactPowerRankEntry;
struct AzeriteEssenceEntry;
struct BattlePetSpeciesEntry;
struct CurrencyContainerEntry;
struct CurrencyTypesEntry;
struct GarrAbilityEntry;
struct GarrFollowerEntry;
struct GarrMissionEntry;
struct GlyphPropertiesEntry;
struct ItemModifiedAppearanceEntry;
struct ItemNameDescriptionEntry;
struct ItemTemplate;
struct LocalizedString;
struct MapEntry;
struct MapChallengeModeEntry;
struct MawPowerEntry;
struct PvpTalentEntry;
class Quest;
struct SkillLineEntry;
struct SoulbindConduitRankEntry;
class SpellInfo;
struct SpellItemEnchantmentEntry;
struct TalentEntry;
struct TransmogSetEntry;
struct UiMapEntry;

namespace Trinity
{
namespace Hyperlinks
{

struct AchievementLinkData
{
    AchievementEntry const* Achievement;
    ObjectGuid CharacterId;
    bool IsFinished;
    uint16 Year;
    uint8 Month;
    uint8 Day;
    uint32 Criteria[4];
};

struct ArtifactPowerLinkData
{
    ArtifactPowerRankEntry const* ArtifactPower;
    uint8 PurchasedRank;
    uint8 CurrentRankWithBonus;
};

struct AzeriteEssenceLinkData
{
    AzeriteEssenceEntry const* Essence;
    uint8 Rank;
};

struct BattlePetLinkData
{
    BattlePetSpeciesEntry const* Species;
    uint8 Level;
    uint8 Quality;
    uint32 MaxHealth;
    uint32 Power;
    uint32 Speed;
    ObjectGuid PetGuid;
    uint32 DisplayId;
};

struct CurrencyLinkData
{
    CurrencyTypesEntry const* Currency;
    int32 Quantity;

    CurrencyContainerEntry const* Container;
};

struct GarrisonFollowerLinkData
{
    GarrFollowerEntry const* Follower;
    uint32 Quality;
    uint32 Level;
    uint32 ItemLevel;
    uint32 Abilities[4];
    uint32 Traits[4];
    uint32 Specialization;
};

struct GarrisonMissionLinkData
{
    GarrMissionEntry const* Mission;
    uint64 DbID;
};

struct InstanceLockLinkData
{
    ObjectGuid Owner;
    MapEntry const* Map;
    uint32 Difficulty;
    uint32 CompletedEncountersMask;
};

struct ItemLinkData
{
    ItemTemplate const* Item;
    uint32 EnchantId;
    uint32 GemItemId[3];
    uint8 RenderLevel;
    uint32 RenderSpecialization;
    uint8 Context;
    std::vector<int32> ItemBonusListIDs;

    struct Modifier
    {
        uint32 Type;
        int32 Value;
    };

    std::vector<Modifier> Modifiers;
    std::vector<int32> GemItemBonusListIDs[3];
    ObjectGuid Creator;
    uint32 UseEnchantId;

    uint32 Quality;
    ItemNameDescriptionEntry const* Suffix;
};

struct JournalLinkData
{
    enum class Types : uint8
    {
        Instance            = 0,
        Encounter           = 1,
        EncounterSection    = 2,
        Tier                = 3
    };

    uint8 Type;
    LocalizedString const* ExpectedText;
    uint32 Difficulty;
};

struct KeystoneLinkData
{
    uint32 ItemId;
    MapChallengeModeEntry const* Map;
    uint32 Level;
    uint32 Affix[4];
};

struct QuestLinkData
{
    ::Quest const* Quest;
    uint32 ContentTuningId;
};

struct SpellLinkData
{
    SpellInfo const* Spell;
    GlyphPropertiesEntry const* Glyph;
};

struct TradeskillLinkData
{
    ObjectGuid Owner;
    SpellInfo const* Spell;
    SkillLineEntry const* Skill;
};

struct WorldMapLinkData
{
    UiMapEntry const* UiMap;
    uint32 X;
    uint32 Y;
    Optional<uint32> Z;
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

        static bool StoreTo(ObjectGuid& val, char const* pos, size_t len)
        {
            val = ObjectGuid::FromString(std::string(pos, len));
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
    // custom formats
    make_base_tag(area, uint32);
    make_base_tag(areatrigger, uint32);
    make_base_tag(creature, ObjectGuid::LowType);
    make_base_tag(creature_entry, uint32);
    make_base_tag(gameevent, uint32);
    make_base_tag(gameobject, ObjectGuid::LowType);
    make_base_tag(gameobject_entry, uint32);
    make_base_tag(itemset, uint32);
    make_base_tag(player, std::string const&);
    make_base_tag(skill, uint32);
    make_base_tag(taxinode, uint32);
    make_base_tag(tele, uint32);
    make_base_tag(title, uint32);

    // client format
    make_base_tag(outfit, std::string const&); // some sort of weird base91 derived encoding
#undef make_base_tag

    struct TC_GAME_API achievement
    {
        using value_type = AchievementLinkData const&;
        static constexpr char const* tag() { return "achievement"; }
        static bool StoreTo(AchievementLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API apower
    {
        using value_type = ArtifactPowerLinkData const&;
        static constexpr char const* tag() { return "apower"; }
        static bool StoreTo(ArtifactPowerLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API azessence
    {
        using value_type = AzeriteEssenceLinkData const&;
        static constexpr char const* tag() { return "azessence"; }
        static bool StoreTo(AzeriteEssenceLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API battlepet
    {
        using value_type = BattlePetLinkData const&;
        static constexpr char const* tag() { return "battlepet"; }
        static bool StoreTo(BattlePetLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API conduit
    {
        using value_type = SoulbindConduitRankEntry const*&;
        static constexpr char const* tag() { return "conduit"; }
        static bool StoreTo(SoulbindConduitRankEntry const*& val, char const* pos, size_t len);
    };

    struct TC_GAME_API currency
    {
        using value_type = CurrencyLinkData const&;
        static constexpr char const* tag() { return "currency"; }
        static bool StoreTo(CurrencyLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API enchant
    {
        using value_type = SpellInfo const*;
        static constexpr char const* tag() { return "enchant"; }
        static bool StoreTo(SpellInfo const*& val, char const* pos, size_t len);
    };

    struct TC_GAME_API garrfollower
    {
        using value_type = GarrisonFollowerLinkData const&;
        static constexpr char const* tag() { return "garrfollower"; }
        static bool StoreTo(GarrisonFollowerLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API garrfollowerability
    {
        using value_type = GarrAbilityEntry const*&;
        static constexpr char const* tag() { return "garrfollowerability"; }
        static bool StoreTo(GarrAbilityEntry const*& val, char const* pos, size_t len);
    };

    struct TC_GAME_API garrmission
    {
        using value_type = GarrisonMissionLinkData const&;
        static constexpr char const* tag() { return "garrmission"; }
        static bool StoreTo(GarrisonMissionLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API instancelock
    {
        using value_type = InstanceLockLinkData const&;
        static constexpr char const* tag() { return "instancelock"; }
        static bool StoreTo(InstanceLockLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API item
    {
        using value_type = ItemLinkData const&;
        static constexpr char const* tag() { return "item"; }
        static bool StoreTo(ItemLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API journal
    {
        using value_type = JournalLinkData const&;
        static constexpr char const* tag() { return "journal"; }
        static bool StoreTo(JournalLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API keystone
    {
        using value_type = KeystoneLinkData const&;
        static constexpr char const* tag() { return "keystone"; }
        static bool StoreTo(KeystoneLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API mawpower
    {
        using value_type = MawPowerEntry const*&;
        static constexpr char const* tag() { return "mawpower"; }
        static bool StoreTo(MawPowerEntry const*& val, char const* pos, size_t len);
    };

    struct TC_GAME_API pvptal
    {
        using value_type = PvpTalentEntry const*&;
        static constexpr char const* tag() { return "pvptal"; }
        static bool StoreTo(PvpTalentEntry const*& val, char const* pos, size_t len);
    };

    struct TC_GAME_API quest
    {
        using value_type = QuestLinkData const&;
        static constexpr char const* tag() { return "quest"; }
        static bool StoreTo(QuestLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API spell
    {
        using value_type = SpellLinkData const&;
        static constexpr char const* tag() { return "spell"; }
        static bool StoreTo(SpellLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API talent
    {
        using value_type = TalentEntry const*&;
        static constexpr char const* tag() { return "talent"; }
        static bool StoreTo(TalentEntry const*& val, char const* pos, size_t len);
    };

    struct TC_GAME_API trade
    {
        using value_type = TradeskillLinkData const&;
        static constexpr char const* tag() { return "trade"; }
        static bool StoreTo(TradeskillLinkData& val, char const* pos, size_t len);
    };

    struct TC_GAME_API transmogappearance
    {
        using value_type = ItemModifiedAppearanceEntry const*&;
        static constexpr char const* tag() { return "transmogappearance"; }
        static bool StoreTo(ItemModifiedAppearanceEntry const*& val, char const* pos, size_t len);
    };

    struct TC_GAME_API transmogillusion
    {
        using value_type = SpellItemEnchantmentEntry const*&;
        static constexpr char const* tag() { return "transmogillusion"; }
        static bool StoreTo(SpellItemEnchantmentEntry const*& val, char const* pos, size_t len);
    };

    struct TC_GAME_API transmogset
    {
        using value_type = TransmogSetEntry const*&;
        static constexpr char const* tag() { return "transmogset"; }
        static bool StoreTo(TransmogSetEntry const*& val, char const* pos, size_t len);
    };

    struct TC_GAME_API worldmap
    {
        using value_type = WorldMapLinkData const&;
        static constexpr char const* tag() { return "worldmap"; }
        static bool StoreTo(WorldMapLinkData& val, char const* pos, size_t len);
    };
}

struct HyperlinkColor
{
    HyperlinkColor(uint32 c) : r(c >> 16), g(c >> 8), b(c), a(c >> 24) {}
    uint8 r, g, b, a;
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
    HyperlinkInfo(char const* n = nullptr, uint32 c = 0, char const* tS = nullptr, size_t tL = 0, char const* dS = nullptr, size_t dL = 0, char const* cS = nullptr, size_t cL = 0) :
        next(n), color(c), tag(tS, tL), data(dS, dL), text(cS, cL) {}

    explicit operator bool() { return next; }
    char const* const next;
    HyperlinkColor const color;
    std::pair<char const*, size_t> const tag;
    std::pair<char const*, size_t> const data;
    std::pair<char const*, size_t> const text;
};
HyperlinkInfo TC_GAME_API ParseHyperlink(char const* pos);
bool TC_GAME_API CheckAllLinks(std::string const&);

}
}

#endif
