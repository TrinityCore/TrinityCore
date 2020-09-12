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
#include "AchievementMgr.h"
#include "ObjectMgr.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include <limits>

static constexpr char HYPERLINK_DATA_DELIMITER = ':';

class HyperlinkDataTokenizer
{
    public:
        HyperlinkDataTokenizer(std::string_view str) : _str(str) {}

        template <typename T>
        bool TryConsumeTo(T& val)
        {
            if (IsEmpty())
                return false;

            if (size_t off = _str.find(HYPERLINK_DATA_DELIMITER); off != std::string_view::npos)
            {
                if (!Trinity::Hyperlinks::LinkTags::base_tag::StoreTo(val, _str.substr(0, off)))
                    return false;
                _str = _str.substr(off+1);
            }
            else
            {
                if (!Trinity::Hyperlinks::LinkTags::base_tag::StoreTo(val, _str))
                    return false;
                _str = std::string_view();
            }
            return true;
        }

        bool IsEmpty() { return _str.empty(); }

    private:
        std::string_view _str;
};

bool Trinity::Hyperlinks::LinkTags::achievement::StoreTo(AchievementLinkData& val, std::string_view text)
{
    HyperlinkDataTokenizer t(text);

    uint32 achievementId;
    if (!t.TryConsumeTo(achievementId))
        return false;
    val.Achievement = sAchievementMgr->GetAchievement(achievementId);

    if (!(val.Achievement && t.TryConsumeTo(val.CharacterId) && t.TryConsumeTo(val.IsFinished) && t.TryConsumeTo(val.Month) && t.TryConsumeTo(val.Day)))
        return false;
    if ((12 < val.Month) || (31 < val.Day))
        return false;

    int8 year;
    if (!t.TryConsumeTo(year))
        return false;
    if (val.IsFinished) // if finished, year must be >= 0
    {
        if (year < 0)
            return false;
        val.Year = static_cast<uint8>(year);
    }
    else
        val.Year = 0;

    return (t.TryConsumeTo(val.Criteria[0]) && t.TryConsumeTo(val.Criteria[1]) && t.TryConsumeTo(val.Criteria[2]) && t.TryConsumeTo(val.Criteria[3]) && t.IsEmpty());
}

bool Trinity::Hyperlinks::LinkTags::enchant::StoreTo(SpellInfo const*& val, std::string_view text)
{
    HyperlinkDataTokenizer t(text);
    uint32 spellId;
    if (!(t.TryConsumeTo(spellId) && t.IsEmpty()))
        return false;
    return (val = sSpellMgr->GetSpellInfo(spellId)) && val->HasAttribute(SPELL_ATTR0_TRADESPELL);
}

bool Trinity::Hyperlinks::LinkTags::glyph::StoreTo(GlyphLinkData& val, std::string_view text)
{
    HyperlinkDataTokenizer t(text);
    uint32 slot, prop;
    if (!(t.TryConsumeTo(slot) && t.TryConsumeTo(prop) && t.IsEmpty()))
        return false;
    if (!(val.Slot = sGlyphSlotStore.LookupEntry(slot)))
        return false;
    if (!(val.Glyph = sGlyphPropertiesStore.LookupEntry(prop)))
        return false;
    return true;
}

bool Trinity::Hyperlinks::LinkTags::item::StoreTo(ItemLinkData& val, std::string_view text)
{
    HyperlinkDataTokenizer t(text);
    uint32 itemId, dummy;
    if (!t.TryConsumeTo(itemId))
        return false;
    val.Item = sObjectMgr->GetItemTemplate(itemId);
    val.IsBuggedInspectLink = false;

    // randomPropertyId is actually a int16 in the client
    // positive values index ItemRandomSuffix.dbc, while negative values index ItemRandomProperties.dbc
    // however, there is also a client bug in inspect packet handling that causes a int16 to be cast to uint16, then int32 (dropping sign extension along the way)
    // this results in the wrong value being sent in the link; DBC lookup clientside fails, so it sends the link without suffix
    // to detect and allow these invalid links, we first read randomPropertyId as a full int32
    int32 randomPropertyId;
    if (!(val.Item && t.TryConsumeTo(val.EnchantId) && t.TryConsumeTo(val.GemEnchantId[0]) && t.TryConsumeTo(val.GemEnchantId[1]) &&
        t.TryConsumeTo(val.GemEnchantId[2]) && t.TryConsumeTo(dummy) && t.TryConsumeTo(randomPropertyId) && t.TryConsumeTo(val.RandomSuffixBaseAmount) &&
        t.TryConsumeTo(val.RenderLevel) && t.IsEmpty() && !dummy))
        return false;

    if ((static_cast<int32>(std::numeric_limits<int16>::max()) < randomPropertyId) && (randomPropertyId <= std::numeric_limits<uint16>::max()))
    { // this is the bug case, the id we received is actually static_cast<uint16>(i16RandomPropertyId)
        randomPropertyId = static_cast<int16>(randomPropertyId);
        val.IsBuggedInspectLink = true;
    }

    if (randomPropertyId < 0)
    {
        if (!val.Item->RandomSuffix)
            return false;
        if (randomPropertyId < -static_cast<int32>(sItemRandomSuffixStore.GetNumRows()))
            return false;
        if (ItemRandomSuffixEntry const* suffixEntry = sItemRandomSuffixStore.LookupEntry(-randomPropertyId))
        {
            val.RandomSuffix = suffixEntry;
            val.RandomProperty = nullptr;
        }
        else
            return false;
    }
    else if (randomPropertyId > 0)
    {
        if (!val.Item->RandomProperty)
            return false;
        if (ItemRandomPropertiesEntry const* propEntry = sItemRandomPropertiesStore.LookupEntry(randomPropertyId))
        {
            val.RandomSuffix = nullptr;
            val.RandomProperty = propEntry;
        }
        else
            return false;
    }
    else
    {
        val.RandomSuffix = nullptr;
        val.RandomProperty = nullptr;
    }

    if ((val.RandomSuffix && !val.RandomSuffixBaseAmount) || (val.RandomSuffixBaseAmount && !val.RandomSuffix))
        return false;

    return true;
}

bool Trinity::Hyperlinks::LinkTags::quest::StoreTo(QuestLinkData& val, std::string_view text)
{
    HyperlinkDataTokenizer t(text);
    uint32 questId;
    if (!t.TryConsumeTo(questId))
        return false;
    return (val.Quest = sObjectMgr->GetQuestTemplate(questId)) && t.TryConsumeTo(val.QuestLevel) && (val.QuestLevel >= -1) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::spell::StoreTo(SpellInfo const*& val, std::string_view text)
{
    HyperlinkDataTokenizer t(text);
    uint32 spellId;
    if (!(t.TryConsumeTo(spellId) && t.IsEmpty()))
        return false;
    return !!(val = sSpellMgr->GetSpellInfo(spellId));
}

bool Trinity::Hyperlinks::LinkTags::talent::StoreTo(TalentLinkData& val, std::string_view text)
{
    HyperlinkDataTokenizer t(text);
    uint32 talentId;
    int8 rank; // talent links contain <learned rank>-1, we store <learned rank>
    if (!(t.TryConsumeTo(talentId) && t.TryConsumeTo(rank) && t.IsEmpty()))
        return false;
    if (rank < -1 || rank >= MAX_TALENT_RANK)
        return false;
    val.Talent = sTalentStore.LookupEntry(talentId);
    val.Rank = rank+1;
    if (!val.Talent)
        return false;
    if (val.Rank > 0)
    {
        uint32 const spellId = val.Talent->SpellRank[val.Rank - 1];
        if (!spellId)
            return false;
        val.Spell = sSpellMgr->GetSpellInfo(spellId);
        if (!val.Spell)
            return false;
    }
    else
    {
        val.Spell = nullptr;
    }
    return true;
}

bool Trinity::Hyperlinks::LinkTags::trade::StoreTo(TradeskillLinkData& val, std::string_view text)
{
    HyperlinkDataTokenizer t(text);
    uint32 spellId;
    if (!t.TryConsumeTo(spellId))
        return false;
    val.Spell = sSpellMgr->GetSpellInfo(spellId);
    return (val.Spell && val.Spell->Effects[0].Effect == SPELL_EFFECT_TRADE_SKILL && t.TryConsumeTo(val.CurValue) &&
        t.TryConsumeTo(val.MaxValue) && t.TryConsumeTo(val.Owner) && t.TryConsumeTo(val.KnownRecipes) && t.IsEmpty());
}
