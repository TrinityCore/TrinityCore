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

/* Script Data Start
SDName: Redridge Mountains
SD%Complete: 100%
SDComment: Support for quest 219.
Script Data End */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Player.h"

enum eCorporalKeeshan
{
    QUEST_MISSING_IN_ACTION = 219,

    SAY_CORPORAL_1  = 0,
    SAY_CORPORAL_2  = 1,
    SAY_CORPORAL_3  = 2,
    SAY_CORPORAL_4  = 3,
    SAY_CORPORAL_5  = 4,

    SPELL_MOCKING_BLOW  = 21008,
    SPELL_SHIELD_BASH   = 11972,
};

class npc_corporal_keeshan : public CreatureScript
{
public:
    npc_corporal_keeshan() : CreatureScript("npc_corporal_keeshan") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == QUEST_MISSING_IN_ACTION)
        {
            CAST_AI(npc_corporal_keeshan::npc_corporal_keeshanAI, creature->AI())->Start(true, false, player->GetGUID(), quest);
            creature->AI()->Talk(SAY_CORPORAL_1);
        }

        return false;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_corporal_keeshanAI(creature);
    }

    struct npc_corporal_keeshanAI : public npc_escortAI
    {
        npc_corporal_keeshanAI(Creature* creature) : npc_escortAI(creature) {}

        uint32 uiPhase;
        uint32 uiTimer;
        uint32 uiMockingBlowTimer;
        uint32 uiShieldBashTimer;

        void Reset()
        {
            uiTimer = 0;
            uiPhase = 0;
            uiMockingBlowTimer = 5000;
            uiShieldBashTimer  = 8000;
        }

        void WaypointReached(uint32 waypointId)
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            if (waypointId >= 65 && me->GetUnitMovementFlags() == MOVEMENTFLAG_WALKING)
                me->SetWalk(false);

            switch (waypointId)
            {
                case 39:
                    SetEscortPaused(true);
                    uiTimer = 2000;
                    uiPhase = 1;
                    break;
                case 65:
                    me->SetWalk(false);
                    break;
                case 115:
                    player->AreaExploredOrEventHappens(QUEST_MISSING_IN_ACTION);
                    uiTimer = 2000;
                    uiPhase = 4;
                    break;
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (HasEscortState(STATE_ESCORT_NONE))
                return;

            npc_escortAI::UpdateAI(uiDiff);

            if (uiPhase)
            {
                if (uiTimer <= uiDiff)
                {
                    switch (uiPhase)
                    {
                        case 1:
                            me->SetStandState(UNIT_STAND_STATE_SIT);
                            uiTimer = 1000;
                            uiPhase = 2;
                            break;
                        case 2:
                            Talk(SAY_CORPORAL_2);
                            uiTimer = 15000;
                            uiPhase = 3;
                            break;
                        case 3:
                            Talk(SAY_CORPORAL_3);
                            me->SetStandState(UNIT_STAND_STATE_STAND);
                            SetEscortPaused(false);
                            uiTimer = 0;
                            uiPhase = 0;
                            break;
                        case 4:
                            Talk(SAY_CORPORAL_4);
                            uiTimer = 2500;
                            uiPhase = 5;
                        case 5:
                            Talk(SAY_CORPORAL_5);
                            uiTimer = 0;
                            uiPhase = 0;
                    }
                } else uiTimer -= uiDiff;
            }

            if (!UpdateVictim())
                return;

            if (uiMockingBlowTimer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_MOCKING_BLOW);
                uiMockingBlowTimer = 5000;
            } else uiMockingBlowTimer -= uiDiff;

            if (uiShieldBashTimer <= uiDiff)
            {
                DoCast(me->getVictim(), SPELL_MOCKING_BLOW);
                uiShieldBashTimer = 8000;
            } else uiShieldBashTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_redridge_mountains()
{
    new npc_corporal_keeshan();
}
