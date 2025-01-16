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

#ifndef _SummonInfo_h__
#define _SummonInfo_h__

#include "Define.h"

class Creature;

class TC_GAME_API SummonInfo
{
public:
    SummonInfo(SummonInfo const& right) = delete;
    SummonInfo(SummonInfo&& right) = delete;
    SummonInfo& operator=(SummonInfo const& right) = delete;
    SummonInfo& operator=(SummonInfo&& right) = delete;

    SummonInfo(Creature* summonedCreature);

    // Returns the creature that is tied to this SummonInfo instance
    Creature* GetSummonedCreature() const;

private:
    Creature* _summonedCreature;
};

#endif
