/*
* Copyright (C) 2016-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_PLAYERAI_H
#define TRINITY_PLAYERAI_H

#include "UnitAI.h"
#include "Player.h"
#include "Creature.h"

class TC_GAME_API PlayerAI : public UnitAI
{
    public:
        explicit PlayerAI(Player* player);

        void OnCharmed(bool /*apply*/) override { } // charm AI application for players is handled by Unit::SetCharmedBy / Unit::RemoveCharmedBy

    protected:
        Player* const me;
        void SetIsRangedAttacker(bool state) { _isRangedAttacker = state; }
        bool IsRangedAttacker() const { return _isRangedAttacker; }

        void DoRangedAttackIfReady();
        void DoAutoAttackIfReady();

    private:
        bool _isRangedAttacker;
};

class TC_GAME_API SimpleCharmedPlayerAI : public PlayerAI
{
    public:
        SimpleCharmedPlayerAI(Player* player) : PlayerAI(player) { }
        void UpdateAI(uint32 diff) override;
        void OnCharmed(bool apply) override;
};

#endif
