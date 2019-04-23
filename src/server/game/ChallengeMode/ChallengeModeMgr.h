/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef _CHALLENGEMODEMGR_H
#define _CHALLENGEMODEMGR_H

struct MapChallengeModeEntry;

class TC_GAME_API ChallengeModeMgr
{
public:
    static ChallengeModeMgr* instance();

    MapChallengeModeEntry const* GetMapChallengeModeEntry(uint32 mapId);

    uint32 GetDamageMultiplier(uint8 challengeLevel);
    uint32 GetHealthMultiplier(uint8 challengeLevel);

    uint32 GetRandomChallengeId(uint32 flags = 4);

    std::vector<int32> GetBonusListIdsForRewards(uint32 baseItemIlevel, uint8 challengeLevel);
    void Reward(Player* player, uint8 challengeLevel);
};

#define sChallengeModeMgr ChallengeModeMgr::instance()

#endif
