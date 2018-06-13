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

#include "ChallengeModeMgr.h"
#include "DB2Stores.h"

ChallengeModeMgr* ChallengeModeMgr::instance()
{
    static ChallengeModeMgr instance;
    return &instance;
}

MapChallengeModeEntry const* ChallengeModeMgr::GetMapChallengeModeEntry(uint32 mapId)
{
    for (uint32 i = 0; i < sMapChallengeModeStore.GetNumRows(); ++i)
        if (MapChallengeModeEntry const* challengeModeEntry = sMapChallengeModeStore.LookupEntry(i))
            if (challengeModeEntry->MapID == mapId)
                return challengeModeEntry;

    return nullptr;
}

uint32 ChallengeModeMgr::GetDamageMultiplier(uint8 challengeLevel)
{
    switch (challengeLevel)
    {
        case 2: return 10;
        case 3: return 21;
        case 4: return 33;
        case 5: return 46;
        case 6: return 61;
        case 7: return 77;
        case 8: return 95;
        case 9: return 114;
        case 10: return 136;
        case 11: return 159;
        case 12: return 185;
        case 13: return 214;
        case 14: return 245;
        case 15: return 280;
        case 16: return 318;
        case 17: return 359;
        case 18: return 405;
        case 19: return 456;
        case 20: return 512;
        default:
            break;
    }

    return 1;
}

uint32 ChallengeModeMgr::GetHealthMultiplier(uint8 challengeLevel)
{
    switch (challengeLevel)
    {
        case 2: return 10;
        case 3: return 21;
        case 4: return 33;
        case 5: return 46;
        case 6: return 61;
        case 7: return 77;
        case 8: return 95;
        case 9: return 114;
        case 10: return 136;
        case 11: return 159;
        case 12: return 185;
        case 13: return 214;
        case 14: return 245;
        case 15: return 280;
        case 16: return 318;
        case 17: return 359;
        case 18: return 405;
        case 19: return 456;
        case 20: return 512;
        default:
            break;
    }

    return 1;
}
