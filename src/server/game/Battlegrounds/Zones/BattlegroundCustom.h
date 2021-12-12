/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2021 tswow <https://github.com/tswow/>
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
#pragma once

#include "Battleground.h"
#include "Arena.h"
#include "BattlegroundScore.h"

struct CustomScore final : public BattlegroundScore
{
    CustomScore(ObjectGuid playerGuid) : BattlegroundScore(playerGuid) {}
    void BuildObjectivesBlock(WorldPacket& data) final override
    {
        data << uint32(0);
    }
    void UpdateScore(uint32 type, uint32 value) override
    {
        BattlegroundScore::UpdateScore(type, value);
    }
};

class BattlegroundCustom : public Battleground
{
public:
    BattlegroundCustom();
    ~BattlegroundCustom();
    void AddPlayer(Player* player) override;
};

class ArenaCustom : public Arena
{
public:
    ArenaCustom() : Arena() {};
};
