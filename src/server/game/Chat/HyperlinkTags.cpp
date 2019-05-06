/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "AchievementMgr.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"

static constexpr char HYPERLINK_DATA_DELIMITER = ':';

class HyperlinkDataTokenizer
{
    public:
    HyperlinkDataTokenizer(char const* pos, size_t len) : _pos(pos), _len(len), _empty(false) {}

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

        return Trinity::Hyperlinks::LinkTags::base_tag::StoreTo(val, firstPos, thisLen);
    }

    bool IsEmpty() { return _empty; }

    private:
    char const* _pos;
    size_t _len;
    bool _empty;
};

bool Trinity::Hyperlinks::LinkTags::achievement::StoreTo(AchievementLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 achievementId;
    if (!t.TryConsumeTo(achievementId))
        return false;
    val.Achievement = sAchievementMgr->GetAchievement(achievementId);
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
    return (val = sSpellMgr->GetSpellInfo(spellId)) && val->HasAttribute(SPELL_ATTR0_TRADESPELL);
}

bool Trinity::Hyperlinks::LinkTags::glyph::StoreTo(GlyphLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 slot, prop;
    if (!(t.TryConsumeTo(slot) && t.TryConsumeTo(prop) && t.IsEmpty()))
        return false;
    if (!(val.Slot = sGlyphSlotStore.LookupEntry(slot)))
        return false;
    if (!(val.Glyph = sGlyphPropertiesStore.LookupEntry(prop)))
        return false;
    return true;
}

bool Trinity::Hyperlinks::LinkTags::item::StoreTo(ItemLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 itemId, dummy;
    if (!t.TryConsumeTo(itemId))
        return false;
    val.Item = sObjectMgr->GetItemTemplate(itemId);
    return val.Item && t.TryConsumeTo(val.EnchantId) && t.TryConsumeTo(val.GemEnchantId[0]) && t.TryConsumeTo(val.GemEnchantId[1]) &&
        t.TryConsumeTo(val.GemEnchantId[2]) && t.TryConsumeTo(dummy) && t.TryConsumeTo(val.RandomPropertyId) && t.TryConsumeTo(val.RandomPropertySeed) &&
        t.TryConsumeTo(val.RenderLevel) && t.IsEmpty() && !dummy;
}

bool Trinity::Hyperlinks::LinkTags::quest::StoreTo(QuestLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 questId;
    if (!t.TryConsumeTo(questId))
        return false;
    return (val.Quest = sObjectMgr->GetQuestTemplate(questId)) && t.TryConsumeTo(val.QuestLevel) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::spell::StoreTo(SpellInfo const*& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 spellId;
    if (!(t.TryConsumeTo(spellId) && t.IsEmpty()))
        return false;
    return !!(val = sSpellMgr->GetSpellInfo(spellId));
}

bool Trinity::Hyperlinks::LinkTags::talent::StoreTo(TalentLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 talentId;
    int8 rank; // talent links contain <learned rank>-1, we store <learned rank>
    if (!(t.TryConsumeTo(talentId) && t.TryConsumeTo(rank) && t.IsEmpty()))
        return false;
    if (rank < -1 || rank > 4)
        return false;
    val.Rank = rank+1;
    if (!(val.Talent = sTalentStore.LookupEntry(talentId)))
        return false;
    if (val.Rank > 0 && !val.Talent->RankID[val.Rank - 1])
        return false;
    return true;
}

bool Trinity::Hyperlinks::LinkTags::trade::StoreTo(TradeskillLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 spellId;
    if (!t.TryConsumeTo(spellId))
        return false;
    val.Spell = sSpellMgr->GetSpellInfo(spellId);
    return (val.Spell && val.Spell->Effects[0].Effect == SPELL_EFFECT_TRADE_SKILL && t.TryConsumeTo(val.CurValue) &&
        t.TryConsumeTo(val.MaxValue) && t.TryConsumeTo(val.Owner) && t.TryConsumeTo(val.KnownRecipes) && t.IsEmpty());
}
