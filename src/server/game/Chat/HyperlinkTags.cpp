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
#include "AchievementMgr.h"

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
    val.achievement = sAchievementMgr->GetAchievement(achievementId);
    return val.achievement && t.TryConsumeTo(val.characterId) && t.TryConsumeTo(val.isFinished) &&
        t.TryConsumeTo(val.month) && t.TryConsumeTo(val.day) && t.TryConsumeTo(val.year) && t.TryConsumeTo(val.criteria[0]) &&
        t.TryConsumeTo(val.criteria[1]) && t.TryConsumeTo(val.criteria[2]) && t.TryConsumeTo(val.criteria[3]) && t.IsEmpty();
}

bool Trinity::Hyperlinks::LinkTags::item::StoreTo(ItemLinkData& val, char const* pos, size_t len)
{
    HyperlinkDataTokenizer t(pos, len);
    uint32 itemId, dummy;
    if (!t.TryConsumeTo(itemId))
        return false;
    val.item = sObjectMgr->GetItemTemplate(itemId);
    return val.item && t.TryConsumeTo(val.enchantId) && t.TryConsumeTo(val.gemEnchantId[0]) && t.TryConsumeTo(val.gemEnchantId[1]) &&
        t.TryConsumeTo(val.gemEnchantId[2]) && t.TryConsumeTo(dummy) && t.TryConsumeTo(val.randomPropertyId) && t.TryConsumeTo(val.randomPropertySeed) &&
        t.TryConsumeTo(val.renderLevel) && t.IsEmpty() && !dummy;
}
