/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "PassiveAI.h"
#include "BattlegroundIC.h"
#include "Player.h"

// TO-DO: This should be done with SmartAI, but yet it does not correctly support vehicles's AIs.
//        Even adding ReactState Passive we still have issues using SmartAI.

class npc_four_car_garage : public CreatureScript
{
    public:
        npc_four_car_garage() : CreatureScript("npc_four_car_garage") {}

        struct npc_four_car_garageAI : public NullCreatureAI
        {
            npc_four_car_garageAI(Creature* creature) : NullCreatureAI(creature) { }

            void PassengerBoarded(Unit* who, int8 /*seatId*/, bool apply) OVERRIDE
            {
                if (apply)
                {
                    uint32 spellId = 0;

                    switch (me->GetEntry())
                    {
                        case NPC_DEMOLISHER:
                            spellId = SPELL_DRIVING_CREDIT_DEMOLISHER;
                            break;
                        case NPC_GLAIVE_THROWER_A:
                        case NPC_GLAIVE_THROWER_H:
                            spellId = SPELL_DRIVING_CREDIT_GLAIVE;
                            break;
                        case NPC_SIEGE_ENGINE_H:
                        case NPC_SIEGE_ENGINE_A:
                            spellId = SPELL_DRIVING_CREDIT_SIEGE;
                            break;
                        case NPC_CATAPULT:
                            spellId = SPELL_DRIVING_CREDIT_CATAPULT;
                            break;
                        default:
                            return;
                    }

                    me->CastSpell(who, spellId, true);
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return new npc_four_car_garageAI(creature);
        }
};

void AddSC_isle_of_conquest()
{
    new npc_four_car_garage();
}
