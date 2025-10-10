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

#ifndef TRINITY_COMMONHELPERS_H
#define TRINITY_COMMONHELPERS_H

#include "EventProcessor.h"
#include "Define.h"
#include "ObjectGuid.h"

class Creature;
class Player;

struct TC_GAME_API StartCombatArgs
{
    StartCombatArgs() {}
    StartCombatArgs& SetAvoidTargetVictim(bool value) { AvoidTargetVictim = value; return *this; }
    StartCombatArgs& SetTargetPlayers(bool value) { TargetPlayers = value; return *this; }
    StartCombatArgs& SetDistance(float value) { Distance = value; return *this; }

    bool AvoidTargetVictim = false;
    bool TargetPlayers = true;
    float Distance = 0.f;
};

namespace Trinity
{
    namespace Helpers
    {
        namespace Entity
        {
            // Return values range from 0 (left-most spec) to 2 (right-most spec). If two specs have the same number of talent points, the left-most of those specs is returned.
            TC_GAME_API uint8 GetPlayerSpecialization(Player const* who);
            TC_GAME_API bool IsPlayerHealer(Player const* who);
            bool IsPlayerRangedAttacker(Player const* who);
        }
        namespace Events
        {
            class TC_GAME_API SetAggresiveStateEvent : public BasicEvent
            {
                public:
                    SetAggresiveStateEvent(Creature* owner, bool startCombat = true, ObjectGuid summonerGUID = ObjectGuid::Empty, StartCombatArgs const& combatArgs = { });

                    bool Execute(uint64 /*time*/, uint32 /*diff*/) override;

                private:
                    Creature* _owner;
                    bool const _startCombat;
                    ObjectGuid const _summonerGUID;
                    StartCombatArgs const _combatArgs;
            };
        }
    }
}

#endif //TRINITY_COMMONHELPERS_H
