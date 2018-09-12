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

bool Trinity::Hyperlinks::LinkTags::enchant::StoreTo(SpellInfo const*& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 spellId;
    if (!(t.TryConsumeTo(spellId) && t.IsEmpty()))
        return false;
    return (val = sSpellMgr->GetSpellInfo(spellId, DIFFICULTY_NONE)) && val->HasAttribute(SPELL_ATTR0_TRADESPELL);
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
