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

#include "ChatCommandHyperlinks.h"
#include "AchievementMgr.h"

static constexpr char HYPERLINK_DELIMITER = ':';

class AchievementLinkTokenizer
{
    public:
        AchievementLinkTokenizer(char const* pos, size_t len) : _pos(pos), _len(len), _empty(false) {}

        template <typename T>
        bool TryConsumeTo(T& val)
        {
            if (_empty)
                return false;

            char const* firstPos = _pos;
            size_t thisLen = 0;
            // find next delimiter
            for (; _len && *_pos != HYPERLINK_DELIMITER; --_len, ++_pos, ++thisLen);
            if (_len)
                --_len, ++_pos; // skip the delimiter
            else
                _empty = true;

            return Trinity::ChatCommands::base_tag::StoreTo(val, firstPos, thisLen);
        }

        bool IsEmpty() { return _empty; }

    private:
        char const* _pos;
        size_t _len;
        bool _empty;
};

bool Trinity::ChatCommands::achievement::StoreTo(AchievementLinkData& val, char const* pos, size_t len)
{
    AchievementLinkTokenizer t(pos, len);
    uint32 achievementId;
    if (!t.TryConsumeTo(achievementId))
        return false;
    val.achievement = sAchievementMgr->GetAchievement(achievementId);
    return val.achievement && t.TryConsumeTo(val.characterId) && t.TryConsumeTo(val.isFinished) &&
        t.TryConsumeTo(val.month) && t.TryConsumeTo(val.day) && t.TryConsumeTo(val.year) && t.TryConsumeTo(val.criteria[0]) &&
        t.TryConsumeTo(val.criteria[1]) && t.TryConsumeTo(val.criteria[2]) && t.TryConsumeTo(val.criteria[3]) && t.IsEmpty();
}
