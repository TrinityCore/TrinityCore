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

struct AchievementEntry;
struct ArtifactPowerRankEntry;
struct AzeriteEssenceEntry;
struct BattlePetAbilityEntry;
struct BattlePetSpeciesEntry;
struct ChrSpecializationEntry;
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
struct PvpTalentEntry;
class Quest;
struct SkillLineEntry;
class SpellInfo;
struct SpellItemEnchantmentEntry;
struct TalentEntry;
struct TransmogSetEntry;
struct UiMapEntry;

namespace Trinity::Hyperlinks
{

    struct AchievementLinkData
    {
        AchievementEntry const* Achievement = nullptr;
        ObjectGuid CharacterId;
        bool IsFinished = false;
        int32 Year = 0;
        int32 Month = 0;
        int32 Day = 0;
        std::array<uint32, 4> Criteria = { };
    };

    struct ApiLinkData
    {
        std::string_view Type;
        std::string_view Name;
        std::string_view Parent;
    };

    struct ArtifactPowerLinkData
    {
        ArtifactPowerRankEntry const* ArtifactPower = nullptr;
        uint8 PurchasedRank = 0;
        uint8 CurrentRankWithBonus = 0;
    };

    struct AzeriteEssenceLinkData
    {
        AzeriteEssenceEntry const* Essence = nullptr;
        uint8 Rank = 0;
    };

    struct BattlePetLinkData
    {
        BattlePetSpeciesEntry const* Species = nullptr;
        uint8 Level = 0;
        uint8 Quality = 0;
        uint32 MaxHealth = 0;
        uint32 Power = 0;
        uint32 Speed = 0;
        ObjectGuid PetGuid;
        uint32 DisplayId = 0;
    };

    struct BattlePetAbilLinkData
    {
        BattlePetAbilityEntry const* Ability = nullptr;
        uint32 MaxHealth = 0;
        uint32 Power = 0;
        uint32 Speed = 0;
    };

    struct CurrencyLinkData
    {
        CurrencyTypesEntry const* Currency = nullptr;
        int32 Quantity = 0;

        CurrencyContainerEntry const* Container = nullptr;
    };

    struct DungeonScoreLinkData
    {
        uint32 Score = 0;
        ObjectGuid Player;
        std::string_view PlayerName;
        uint8 PlayerClass = 0;
        uint32 AvgItemLevel = 0;
        uint8 PlayerLevel = 0;
        uint32 RunsThisSeason = 0;
        uint32 BestSeasonScore = 0;
        uint32 BestSeasonNumber = 0;

        struct Dungeon
        {
            uint32 MapChallengeModeID = 0;
            bool CompletedInTime = false;
            uint32 KeystoneLevel = 0;
        };

        std::vector<Dungeon> Dungeons;
    };

    struct GarrisonFollowerLinkData
    {
        GarrFollowerEntry const* Follower = nullptr;
        uint32 Quality = 0;
        uint32 Level = 0;
        uint32 ItemLevel = 0;
        std::array<uint32, 4> Abilities = { };
        uint32 Traits[4] = { };
        uint32 Specialization = 0;
    };

    struct GarrisonMissionLinkData
    {
        GarrMissionEntry const* Mission = nullptr;
        uint64 DbID = 0;
    };

    struct InstanceLockLinkData
    {
        ObjectGuid Owner;
        MapEntry const* Map = nullptr;
        uint32 Difficulty = 0;
        uint32 CompletedEncountersMask = 0;
    };

    struct ItemLinkData
    {
        ItemTemplate const* Item = nullptr;
        uint32 EnchantId = 0;
        std::array<uint32, 3> GemItemId = { };
        uint8 RenderLevel = 0;
        uint32 RenderSpecialization = 0;
        uint8 Context = 0;
        std::vector<int32> ItemBonusListIDs;

        struct Modifier
        {
            uint32 Type = 0;
            int32 Value = 0;
        };

        std::vector<Modifier> Modifiers;
        std::vector<int32> GemItemBonusListIDs[3];
        ObjectGuid Creator;
        uint32 UseEnchantId = 0;

        uint32 Quality = 0;
        ItemNameDescriptionEntry const* Suffix = nullptr;
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

        uint8 Type = 0;
        LocalizedString const* ExpectedText = nullptr;
        uint32 Difficulty = 0;
    };

    struct KeystoneLinkData
    {
        uint32 ItemId = 0;
        MapChallengeModeEntry const* Map = nullptr;
        uint32 Level = 0;
        std::array<uint32, 4> Affix = { };
    };

    struct MountLinkData
    {
        SpellInfo const* Spell = nullptr;
        uint32 DisplayId = 0;
        std::string_view Customizations;
    };

    struct QuestLinkData
    {
        ::Quest const* Quest = nullptr;
        uint32 ContentTuningId = 0;
    };

    struct SpellLinkData
    {
        SpellInfo const* Spell = nullptr;
        GlyphPropertiesEntry const* Glyph = nullptr;
    };

    struct TalentBuildLinkData
    {
        ChrSpecializationEntry const* Spec = nullptr;
        uint32 Level = 0;
        std::string_view ImportString;
    };

    struct TradeskillLinkData
    {
        ObjectGuid Owner;
        SpellInfo const* Spell = nullptr;
        SkillLineEntry const* Skill = nullptr;
    };

    struct WorldMapLinkData
    {
        UiMapEntry const* UiMap = nullptr;
        uint32 X = 0;
        uint32 Y = 0;
        Optional<uint32> Z;
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
                ObjectGuid parsed = ObjectGuid::FromString(std::string(data));
                if (parsed != ObjectGuid::FromStringFailed)
                {
                    val = parsed;
                    return true;
                }
                else
                    return false;
            }
        };

    #define make_base_tag(ltag, type) struct ltag : public base_tag { using value_type = type; static constexpr std::string_view tag() { return #ltag; } }
        // custom formats
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

        // client format
        make_base_tag(clubFinder, ObjectGuid);
        make_base_tag(clubTicket, std::string_view);
        make_base_tag(outfit, std::string_view); // some sort of weird base91 derived encoding
    #undef make_base_tag

        struct TC_GAME_API achievement
        {
            using value_type = AchievementLinkData const&;
            static constexpr std::string_view tag() { return "achievement"; }
            static bool StoreTo(AchievementLinkData& val, std::string_view text);
        };

        struct TC_GAME_API api
        {
            using value_type = ApiLinkData const&;
            static constexpr std::string_view tag() { return "api"; }
            static bool StoreTo(ApiLinkData& val, std::string_view text);
        };

        struct TC_GAME_API apower
        {
            using value_type = ArtifactPowerLinkData const&;
            static constexpr std::string_view tag() { return "apower"; }
            static bool StoreTo(ArtifactPowerLinkData& val, std::string_view text);
        };

        struct TC_GAME_API azessence
        {
            using value_type = AzeriteEssenceLinkData const&;
            static constexpr std::string_view tag() { return "azessence"; }
            static bool StoreTo(AzeriteEssenceLinkData& val, std::string_view text);
        };

        struct TC_GAME_API battlepet
        {
            using value_type = BattlePetLinkData const&;
            static constexpr std::string_view tag() { return "battlepet"; }
            static bool StoreTo(BattlePetLinkData& val, std::string_view text);
        };

        struct TC_GAME_API battlePetAbil
        {
            using value_type = BattlePetAbilLinkData const&;
            static constexpr std::string_view tag() { return "battlePetAbil"; }
            static bool StoreTo(BattlePetAbilLinkData& val, std::string_view text);
        };

        struct TC_GAME_API currency
        {
            using value_type = CurrencyLinkData const&;
            static constexpr std::string_view tag() { return "currency"; }
            static bool StoreTo(CurrencyLinkData& val, std::string_view text);
        };

        struct TC_GAME_API dungeonScore
        {
            using value_type = DungeonScoreLinkData const&;
            static constexpr std::string_view tag() { return "dungeonScore"; }
            static bool StoreTo(DungeonScoreLinkData& val, std::string_view text);
        };

        struct TC_GAME_API enchant
        {
            using value_type = SpellInfo const*;
            static constexpr std::string_view tag() { return "enchant"; }
            static bool StoreTo(SpellInfo const*& val, std::string_view text);
        };

        struct TC_GAME_API garrfollower
        {
            using value_type = GarrisonFollowerLinkData const&;
            static constexpr std::string_view tag() { return "garrfollower"; }
            static bool StoreTo(GarrisonFollowerLinkData& val, std::string_view text);
        };

        struct TC_GAME_API garrfollowerability
        {
            using value_type = GarrAbilityEntry const*;
            static constexpr std::string_view tag() { return "garrfollowerability"; }
            static bool StoreTo(GarrAbilityEntry const*& val, std::string_view text);
        };

        struct TC_GAME_API garrmission
        {
            using value_type = GarrisonMissionLinkData const&;
            static constexpr std::string_view tag() { return "garrmission"; }
            static bool StoreTo(GarrisonMissionLinkData& val, std::string_view text);
        };

        struct TC_GAME_API instancelock
        {
            using value_type = InstanceLockLinkData const&;
            static constexpr std::string_view tag() { return "instancelock"; }
            static bool StoreTo(InstanceLockLinkData& val, std::string_view text);
        };

        struct TC_GAME_API item
        {
            using value_type = ItemLinkData const&;
            static constexpr std::string_view tag() { return "item"; }
            static bool StoreTo(ItemLinkData& val, std::string_view text);
        };

        struct TC_GAME_API journal
        {
            using value_type = JournalLinkData const&;
            static constexpr std::string_view tag() { return "journal"; }
            static bool StoreTo(JournalLinkData& val, std::string_view text);
        };

        struct TC_GAME_API keystone
        {
            using value_type = KeystoneLinkData const&;
            static constexpr std::string_view tag() { return "keystone"; }
            static bool StoreTo(KeystoneLinkData& val, std::string_view text);
        };

        struct TC_GAME_API mount
        {
            using value_type = MountLinkData const&;
            static constexpr std::string_view tag() { return "mount"; }
            static bool StoreTo(MountLinkData& val, std::string_view text);
        };

        struct TC_GAME_API pvptal
        {
            using value_type = PvpTalentEntry const*;
            static constexpr std::string_view tag() { return "pvptal"; }
            static bool StoreTo(PvpTalentEntry const*& val, std::string_view text);
        };

        struct TC_GAME_API quest
        {
            using value_type = QuestLinkData const&;
            static constexpr std::string_view tag() { return "quest"; }
            static bool StoreTo(QuestLinkData& val, std::string_view text);
        };

        struct TC_GAME_API spell
        {
            using value_type = SpellLinkData const&;
            static constexpr std::string_view tag() { return "spell"; }
            static bool StoreTo(SpellLinkData& val, std::string_view text);
        };

        struct TC_GAME_API talent
        {
            using value_type = TalentEntry const*;
            static constexpr std::string_view tag() { return "talent"; }
            static bool StoreTo(TalentEntry const*& val, std::string_view text);
        };

        struct TC_GAME_API talentbuild
        {
            using value_type = TalentBuildLinkData const&;
            static constexpr std::string_view tag() { return "talentbuild"; }
            static bool StoreTo(TalentBuildLinkData& val, std::string_view text);
        };

        struct TC_GAME_API trade
        {
            using value_type = TradeskillLinkData const&;
            static constexpr std::string_view tag() { return "trade"; }
            static bool StoreTo(TradeskillLinkData& val, std::string_view text);
        };

        struct TC_GAME_API transmogappearance
        {
            using value_type = ItemModifiedAppearanceEntry const*;
            static constexpr std::string_view tag() { return "transmogappearance"; }
            static bool StoreTo(ItemModifiedAppearanceEntry const*& val, std::string_view text);
        };

        struct TC_GAME_API transmogset
        {
            using value_type = TransmogSetEntry const*;
            static constexpr std::string_view tag() { return "transmogset"; }
            static bool StoreTo(TransmogSetEntry const*& val, std::string_view text);
        };

        struct TC_GAME_API worldmap
        {
            using value_type = WorldMapLinkData const&;
            static constexpr std::string_view tag() { return "worldmap"; }
            static bool StoreTo(WorldMapLinkData& val, std::string_view text);
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
