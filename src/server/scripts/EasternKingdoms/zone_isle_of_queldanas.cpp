/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Isle_of_Queldanas
SD%Complete: 100
SDComment: Quest support: 11524, 11525, 11532, 11533, 11542, 11543, 11541
SDCategory: Isle Of Quel'Danas
EndScriptData */

/* ContentData
npc_converted_sentry
npc_greengill_slave
EndContentData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"
#include "Pet.h"
#include "SpellInfo.h"

/*######
## npc_converted_sentry
######*/
enum ConvertedSentry
{
    SAY_CONVERTED           = 0,

    SPELL_CONVERT_CREDIT    = 45009
};

class npc_converted_sentry : public CreatureScript
{
public:
    npc_converted_sentry() : CreatureScript("npc_converted_sentry") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_converted_sentryAI(creature);
    }

    struct npc_converted_sentryAI : public ScriptedAI
    {
        npc_converted_sentryAI(Creature* creature) : ScriptedAI(creature) { }

        bool Credit;
        uint32 Timer;

        void Reset() OVERRIDE
        {
            Credit = false;
            Timer = 2500;
        }

        void MoveInLineOfSight(Unit* /*who*/) OVERRIDE { }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!Credit)
            {
                if (Timer <= diff)
                {
                    Talk(SAY_CONVERTED);

                    DoCast(me, SPELL_CONVERT_CREDIT);
                    if (me->IsPet())
                        me->ToPet()->SetDuration(7500);
                    Credit = true;
                } else Timer -= diff;
            }
        }
    };
};

/*######
## npc_greengill_slave
######*/

#define ENRAGE  45111
#define ORB     45109
#define QUESTG  11541
#define DM      25060

class npc_greengill_slave : public CreatureScript
{
public:
    npc_greengill_slave() : CreatureScript("npc_greengill_slave") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new npc_greengill_slaveAI(creature);
    }

    struct npc_greengill_slaveAI : public ScriptedAI
    {
        npc_greengill_slaveAI(Creature* creature) : ScriptedAI(creature) { }

        void EnterCombat(Unit* /*who*/) OVERRIDE { }

        void SpellHit(Unit* caster, SpellInfo const* spellInfo) OVERRIDE
        {
            Player* player = caster->ToPlayer();
            if (!player)
                return;

            if (spellInfo->Id == ORB && !me->HasAura(ENRAGE))
            {
                if (player->GetQuestStatus(QUESTG) == QUEST_STATUS_INCOMPLETE)
                    DoCast(player, 45110, true);

                DoCast(me, ENRAGE);

                if (Creature* Myrmidon = me->FindNearestCreature(DM, 70))
                {
                    me->AddThreat(Myrmidon, 100000.0f);
                    AttackStart(Myrmidon);
                }
            }
        }

        void UpdateAI(uint32 /*diff*/) OVERRIDE
        {
            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_isle_of_queldanas()
{
    new npc_converted_sentry();
    new npc_greengill_slave();
}
