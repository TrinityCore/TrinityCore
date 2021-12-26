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

#include "Hyperlinks.h"
#include "DB2Stores.h"
#include "Item.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"

static constexpr char HYPERLINK_DATA_DELIMITER = ':';

class HyperlinkDataTokenizer
{
    public:
    HyperlinkDataTokenizer(char const* pos, size_t len, bool allowEmptyTokens = false) : _pos(pos), _len(len), _allowEmptyTokens(allowEmptyTokens), _empty(false) {}

    template <typename T>
    bool TryConsumeTo(T& val)
    {
        if (_empty)
            return false;

        char const* firstPos = _pos;
        size_t thisLen = 0;
        // find next delimiter
        for (; _len && *_pos != HYPERLINK_DATA_DELIMITER; --_len, ++_pos, ++thisLen);
        if (_len)
            --_len, ++_pos; // skip the delimiter
        else
            _empty = true;

        if (_allowEmptyTokens && !thisLen)
        {
            val = T();
            return true;
        }

        return Trinity::Hyperlinks::LinkTags::base_tag::StoreTo(val, firstPos, thisLen);
    }

    bool IsEmpty() { return _empty; }

    private:
    char const* _pos;
    size_t _len;
    bool _allowEmptyTokens;
    bool _empty;
};

bool Trinity::Hyperlinks::LinkTags::achievement::StoreTo(AchievementLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 achievementId;
    if (!t.TryConsumeTo(achievementId))
        return false;
    val.Achievement = sAchievementStore.LookupEntry(achievementId);
    return val.Achievement && t.TryConsumeTo(val.CharacterId) && t.TryConsumeTo(val.IsFinished) &&
        t.TryConsumeTo(val.Month) && t.TryConsumeTo(val.Day) && t.TryConsumeTo(val.Year) && t.TryConsumeTo(val.Criteria[0]) &&
        t.TryConsumeTo(val.Criteria[1]) && t.TryConsumeTo(val.Criteria[2]) && t.TryConsumeTo(val.Criteria[3]) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::apower::StoreTo(ArtifactPowerLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 artifactPowerId;
    if (!(t.TryConsumeTo(artifactPowerId) && t.TryConsumeTo(val.PurchasedRank) && t.TryConsumeTo(val.CurrentRankWithBonus) && t.IsEmpty()))
        return false;
    if (!sArtifactPowerStore.LookupEntry(artifactPowerId))
        return false;
    val.ArtifactPower = sDB2Manager.GetArtifactPowerRank(artifactPowerId, std::max<uint8>(val.CurrentRankWithBonus, 1));
    if (val.ArtifactPower)
        return false;
    return true;
}

bool Trinity::Hyperlinks::LinkTags::azessence::StoreTo(AzeriteEssenceLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 azeriteEssenceId;
    if (!t.TryConsumeTo(azeriteEssenceId))
        return false;
    return (val.Essence = sAzeriteEssenceStore.LookupEntry(azeriteEssenceId)) && t.TryConsumeTo(val.Rank)
        && sDB2Manager.GetAzeriteEssencePower(azeriteEssenceId, val.Rank) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::battlepet::StoreTo(BattlePetLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 battlePetSpeciesId;
    if (!t.TryConsumeTo(battlePetSpeciesId))
        return false;
    return (val.Species = sBattlePetSpeciesStore.LookupEntry(battlePetSpeciesId)) && t.TryConsumeTo(val.Level)
        && t.TryConsumeTo(val.Quality) && val.Quality < MAX_ITEM_QUALITY
        && t.TryConsumeTo(val.MaxHealth) && t.TryConsumeTo(val.Power) && t.TryConsumeTo(val.Speed)
        && t.TryConsumeTo(val.PetGuid) && val.PetGuid.GetHigh() == HighGuid::BattlePet && t.TryConsumeTo(val.DisplayId);
}

bool Trinity::Hyperlinks::LinkTags::conduit::StoreTo(SoulbindConduitRankEntry const*& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 soulbindConduitId, rank;
    if (!(t.TryConsumeTo(soulbindConduitId) && t.TryConsumeTo(rank) && t.IsEmpty()))
        return false;
    return !!(val = sDB2Manager.GetSoulbindConduitRank(soulbindConduitId, rank));
}

bool Trinity::Hyperlinks::LinkTags::currency::StoreTo(CurrencyLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 currencyId;
    if (!t.TryConsumeTo(currencyId))
        return false;
    val.Currency = sCurrencyTypesStore.LookupEntry(currencyId);
    if (!val.Currency || !t.TryConsumeTo(val.Quantity) || !t.IsEmpty())
        return false;
    val.Container = sDB2Manager.GetCurrencyContainerForCurrencyQuantity(currencyId, val.Quantity);
    return true;
}

bool Trinity::Hyperlinks::LinkTags::enchant::StoreTo(SpellInfo const*& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 spellId;
    if (!(t.TryConsumeTo(spellId) && t.IsEmpty()))
        return false;
    return !!(val = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE)) && val->HasAttribute(SPELL_ATTR0_TRADESPELL);
}

bool Trinity::Hyperlinks::LinkTags::garrfollower::StoreTo(GarrisonFollowerLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 garrFollowerId;
    if (!t.TryConsumeTo(garrFollowerId))
        return false;

    val.Follower = sGarrFollowerStore.LookupEntry(garrFollowerId);
    if (!val.Follower || !t.TryConsumeTo(val.Quality) || val.Quality >= MAX_ITEM_QUALITY || !t.TryConsumeTo(val.Level) || !t.TryConsumeTo(val.ItemLevel)
        || !t.TryConsumeTo(val.Abilities[0]) || !t.TryConsumeTo(val.Abilities[1]) || !t.TryConsumeTo(val.Abilities[2]) || !t.TryConsumeTo(val.Abilities[3])
        || !t.TryConsumeTo(val.Traits[0]) || !t.TryConsumeTo(val.Traits[1]) || !t.TryConsumeTo(val.Traits[2]) || !t.TryConsumeTo(val.Traits[3])
        || !t.TryConsumeTo(val.Specialization))
        return false;

    for (uint32 ability : val.Abilities)
        if (ability && !sGarrAbilityStore.LookupEntry(ability))
            return false;

    for (uint32 trait : val.Traits)
        if (trait && !sGarrAbilityStore.LookupEntry(trait))
            return false;

    if (val.Specialization && !sGarrAbilityStore.LookupEntry(val.Specialization))
        return false;

    return true;
}

bool Trinity::Hyperlinks::LinkTags::garrfollowerability::StoreTo(GarrAbilityEntry const*& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 garrAbilityId;
    if (!t.TryConsumeTo(garrAbilityId))
        return false;
    return !!(val = sGarrAbilityStore.LookupEntry(garrAbilityId)) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::garrmission::StoreTo(GarrisonMissionLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 garrMissionId;
    if (!t.TryConsumeTo(garrMissionId))
        return false;
    return !!(val.Mission = sGarrMissionStore.LookupEntry(garrMissionId)) && t.TryConsumeTo(val.DbID) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::instancelock::StoreTo(InstanceLockLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    if (!t.TryConsumeTo(val.Owner))
        return false;
    uint32 mapId;
    if (!t.TryConsumeTo(mapId))
        return false;
    return !!(val.Map = sMapStore.LookupEntry(mapId))
        && t.TryConsumeTo(val.Difficulty) && sDB2Manager.GetMapDifficultyData(mapId, Difficulty(val.Difficulty))
        && t.TryConsumeTo(val.CompletedEncountersMask) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::item::StoreTo(ItemLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len, true);
    uint32 itemId, dummy, numBonusListIDs;
    if (!t.TryConsumeTo(itemId))
        return false;
    val.Item = sObjectMgr->GetItemTemplate(itemId);
    if (!(val.Item && t.TryConsumeTo(val.EnchantId) && t.TryConsumeTo(val.GemItemId[0]) && t.TryConsumeTo(val.GemItemId[1]) &&
        t.TryConsumeTo(val.GemItemId[2]) && t.TryConsumeTo(dummy) && !dummy && t.TryConsumeTo(dummy) && !dummy && t.TryConsumeTo(dummy) && !dummy &&
        t.TryConsumeTo(val.RenderLevel) && t.TryConsumeTo(val.RenderSpecialization) && t.TryConsumeTo(dummy) && !dummy &&
        t.TryConsumeTo(val.Context) && t.TryConsumeTo(numBonusListIDs)))
        return false;

    constexpr uint32 maxBonusListIDs = 16;
    if (numBonusListIDs > maxBonusListIDs)
        return false;

    BonusData evaluatedBonus;
    evaluatedBonus.Initialize(val.Item);

    val.ItemBonusListIDs.resize(numBonusListIDs);
    for (int32& itemBonusListID : val.ItemBonusListIDs)
    {
        if (!t.TryConsumeTo(itemBonusListID) || !sDB2Manager.GetItemBonusList(itemBonusListID))
            return false;

        evaluatedBonus.AddBonusList(itemBonusListID);
    }

    val.Quality = evaluatedBonus.Quality;
    val.Suffix = sItemNameDescriptionStore.LookupEntry(evaluatedBonus.Suffix);
    if (evaluatedBonus.Suffix && !val.Suffix)
        return false;

    uint32 numModifiers;
    if (!t.TryConsumeTo(numModifiers))
        return false;

    if (numModifiers > MAX_ITEM_MODIFIERS)
        return false;

    val.Modifiers.resize(numModifiers);
    for (ItemLinkData::Modifier& modifier : val.Modifiers)
        if (!(t.TryConsumeTo(modifier.Type) && modifier.Type < MAX_ITEM_MODIFIERS && t.TryConsumeTo(modifier.Value)))
            return false;

    for (uint32 i = 0; i < MAX_ITEM_PROTO_SOCKETS; ++i)
    {
        if (!t.TryConsumeTo(numBonusListIDs) || numBonusListIDs > maxBonusListIDs)
            return false;

        val.GemItemBonusListIDs[i].resize(numBonusListIDs);
        for (int32& itemBonusListID : val.GemItemBonusListIDs[i])
            if (!t.TryConsumeTo(itemBonusListID) || !sDB2Manager.GetItemBonusList(itemBonusListID))
                return false;
    }

    return t.TryConsumeTo(val.Creator) && t.TryConsumeTo(val.UseEnchantId) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::journal::StoreTo(JournalLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 id;
    if (!t.TryConsumeTo(val.Type) || !t.TryConsumeTo(id) || !t.TryConsumeTo(val.Difficulty) || !t.IsEmpty())
        return false;
    switch (JournalLinkData::Types(val.Type))
    {
        case JournalLinkData::Types::Instance:
        {
            JournalInstanceEntry const* instance = sJournalInstanceStore.LookupEntry(id);
            if (!instance)
                return false;
            val.ExpectedText = &instance->Name;
            break;
        }
        case JournalLinkData::Types::Encounter:
        {
            JournalEncounterEntry const* encounter = sJournalEncounterStore.LookupEntry(id);
            if (!encounter)
                return false;
            val.ExpectedText = &encounter->Name;
            break;
        }
        case JournalLinkData::Types::EncounterSection:
        {
            JournalEncounterSectionEntry const* encounterSection = sJournalEncounterSectionStore.LookupEntry(id);
            if (!encounterSection)
                return false;
            val.ExpectedText = &encounterSection->Title;
            break;
        }
        case JournalLinkData::Types::Tier:
        {
            JournalTierEntry const* tier = sDB2Manager.GetJournalTier(id);
            if (!tier)
                return false;
            val.ExpectedText = &tier->Name;
            break;
        }
        default:
            return false;
    }
    return true;
}

bool Trinity::Hyperlinks::LinkTags::keystone::StoreTo(KeystoneLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 mapChallengeModeId;
    if (!t.TryConsumeTo(val.ItemId) || !t.TryConsumeTo(mapChallengeModeId) || !t.TryConsumeTo(val.Level)
        || !t.TryConsumeTo(val.Affix[0]) || !t.TryConsumeTo(val.Affix[1]) || !t.TryConsumeTo(val.Affix[2]) || !t.TryConsumeTo(val.Affix[3])
        || !t.IsEmpty())
        return false;
    val.Map = sMapChallengeModeStore.LookupEntry(mapChallengeModeId);
    if (!val.Map)
        return false;
    ItemTemplate const* item = sObjectMgr->GetItemTemplate(val.ItemId);
    if (!item || item->GetClass() != ITEM_CLASS_REAGENT || item->GetSubClass() != ITEM_SUBCLASS_KEYSTONE)
        return false;
    for (uint32 keystoneAffix : val.Affix)
        if (keystoneAffix && !sKeystoneAffixStore.LookupEntry(keystoneAffix))
            return false;
    return true;
}

bool Trinity::Hyperlinks::LinkTags::mawpower::StoreTo(MawPowerEntry const*& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 mawPowerId;
    if (!t.TryConsumeTo(mawPowerId))
        return false;
    return !!(val = sMawPowerStore.LookupEntry(mawPowerId)) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::pvptal::StoreTo(PvpTalentEntry const*& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 pvpTalentId;
    if (!(t.TryConsumeTo(pvpTalentId) && t.IsEmpty()))
        return false;
    if (!(val = sPvpTalentStore.LookupEntry(pvpTalentId)))
        return false;
    return true;
}

bool Trinity::Hyperlinks::LinkTags::quest::StoreTo(QuestLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 questId;
    if (!t.TryConsumeTo(questId))
        return false;
    return (val.Quest = sObjectMgr->GetQuestTemplate(questId)) && t.TryConsumeTo(val.ContentTuningId) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::spell::StoreTo(SpellLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 spellId, glyphPropertiesId;
    if (!(t.TryConsumeTo(spellId) && t.TryConsumeTo(glyphPropertiesId) && t.IsEmpty()))
        return false;
    return !!(val.Spell = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE))
        && (!glyphPropertiesId || !!(val.Glyph = sGlyphPropertiesStore.LookupEntry(glyphPropertiesId)));
}

bool Trinity::Hyperlinks::LinkTags::talent::StoreTo(TalentEntry const*& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 talentId;
    if (!(t.TryConsumeTo(talentId) && t.IsEmpty()))
        return false;
    if (!(val = sTalentStore.LookupEntry(talentId)))
        return false;
    return true;
}

bool Trinity::Hyperlinks::LinkTags::trade::StoreTo(TradeskillLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 spellId, skillId;
    if (!t.TryConsumeTo(val.Owner) || !t.TryConsumeTo(spellId) || !t.TryConsumeTo(skillId) || !t.IsEmpty())
        return false;
    val.Spell = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE);
    val.Skill = sSkillLineStore.LookupEntry(skillId);
    if (!val.Spell || !val.Spell->HasEffect(SPELL_EFFECT_TRADE_SKILL) || !val.Skill)
        return false;
    return true;
}

bool Trinity::Hyperlinks::LinkTags::transmogappearance::StoreTo(ItemModifiedAppearanceEntry const*& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 itemModifiedAppearanceId;
    if (!t.TryConsumeTo(itemModifiedAppearanceId))
        return false;
    return !!(val = sItemModifiedAppearanceStore.LookupEntry(itemModifiedAppearanceId)) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::transmogillusion::StoreTo(SpellItemEnchantmentEntry const*& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 spellItemEnchantmentId;
    if (!t.TryConsumeTo(spellItemEnchantmentId))
        return false;
    return !!(val = sSpellItemEnchantmentStore.LookupEntry(spellItemEnchantmentId))
        && sDB2Manager.GetTransmogIllusionForEnchantment(spellItemEnchantmentId) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::transmogset::StoreTo(TransmogSetEntry const*& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 transmogSetId;
    if (!t.TryConsumeTo(transmogSetId))
        return false;
    return !!(val = sTransmogSetStore.LookupEntry(transmogSetId)) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::worldmap::StoreTo(WorldMapLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 uiMapId;
    if (!t.TryConsumeTo(uiMapId))
        return false;
    val.UiMap = sUiMapStore.LookupEntry(uiMapId);
    if (!val.UiMap || !t.TryConsumeTo(val.X) || !t.TryConsumeTo(val.Y))
        return false;
    if (t.IsEmpty())
        return true;
    val.Z.emplace();
    if (!t.TryConsumeTo(*val.Z))
        return false;
    return t.IsEmpty();
}
