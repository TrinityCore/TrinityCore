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
#include "Containers.h"
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
        case 21: return 573;
        case 22: return 640;
        case 23: return 714;
        case 24: return 795;
        case 25: return 885;
        case 26: return 983;
        case 27: return 1092;
        case 28: return 1211;
        case 29: return 1342;
        case 30: return 1486;
        case 31: return 1645;
        case 32: return 1819;
        case 33: return 2011;
        case 34: return 2223;
        case 35: return 2455;
        case 36: return 2710;
        case 37: return 2991;
        case 38: return 3300;
        case 39: return 3640;
        case 40: return 4014;
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
        case 21: return 573;
        case 22: return 640;
        case 23: return 714;
        case 24: return 795;
        case 25: return 885;
        case 26: return 983;
        case 27: return 1092;
        case 28: return 1211;
        case 29: return 1342;
        case 30: return 1486;
        case 31: return 1645;
        case 32: return 1819;
        case 33: return 2011;
        case 34: return 2223;
        case 35: return 2455;
        case 36: return 2710;
        case 37: return 2991;
        case 38: return 3300;
        case 39: return 3640;
        case 40: return 4014;
        default:
            break;
    }

    return 1;
}

uint32 ChallengeModeMgr::GetRandomChallengeId(uint32 flags/* = 4*/)
{
    std::vector<uint32> challenges;

    for (uint32 i = 0; i < sMapChallengeModeStore.GetNumRows(); ++i)
        if (MapChallengeModeEntry const* challengeModeEntry = sMapChallengeModeStore.LookupEntry(i))
            if (challengeModeEntry->Flags & flags &&
                (challengeModeEntry->ID == 197 || challengeModeEntry->ID == 198 || challengeModeEntry->ID == 199)) // Temp fix, only doable dungeons here
                challenges.push_back(challengeModeEntry->ID);

    if (challenges.empty())
        return 0;

    return Trinity::Containers::SelectRandomContainerElement(challenges);
}
