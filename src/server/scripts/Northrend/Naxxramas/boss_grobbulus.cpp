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
#include "naxxramas.h"
#include "SpellInfo.h"

enum Spells
{
    SPELL_BOMBARD_SLIME         = 28280,
    SPELL_POISON_CLOUD          = 28240,
    SPELL_MUTATING_INJECTION    = 28169,
    SPELL_SLIME_SPRAY           = 28157,
    H_SPELL_SLIME_SPRAY         = 54364,
    SPELL_BERSERK               = 26662,
    SPELL_POISON_CLOUD_ADD      = 59116
};

enum Events
{
    EVENT_BERSERK               = 1,
    EVENT_CLOUD                 = 2,
    EVENT_INJECT                = 3,
    EVENT_SPRAY                 = 4
};

enum CreatureId
{
    NPC_FALLOUT_SLIME           = 16290
};

class boss_grobbulus : public CreatureScript
{
public:
    boss_grobbulus() : CreatureScript("boss_grobbulus") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_grobbulusAI (creature);
    }

    struct boss_grobbulusAI : public BossAI
    {
        boss_grobbulusAI(Creature* creature) : BossAI(creature, BOSS_GROBBULUS)
        {
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_POISON_CLOUD_ADD, true);
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_CLOUD, 15000);
            events.ScheduleEvent(EVENT_INJECT, 20000);
            events.ScheduleEvent(EVENT_SPRAY, 15000+rand()%15000); //not sure
            events.ScheduleEvent(EVENT_BERSERK, 12*60000);
        }

        void SpellHitTarget(Unit* target, const SpellInfo* spell)
        {
            if (spell->Id == uint32(SPELL_SLIME_SPRAY))
            {
                if (TempSummon* slime = me->SummonCreature(NPC_FALLOUT_SLIME, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0))
                    DoZoneInCombat(slime);
            }
        }

        void UpdateAI(uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_CLOUD:
                        DoCastAOE(SPELL_POISON_CLOUD);
                        events.ScheduleEvent(EVENT_CLOUD, 15000);
                        return;
                    case EVENT_BERSERK:
                        DoCastAOE(SPELL_BERSERK);
                        return;
                    case EVENT_SPRAY:
                        DoCastAOE(SPELL_SLIME_SPRAY);
                        events.ScheduleEvent(EVENT_SPRAY, 15000+rand()%15000);
                        return;
                    case EVENT_INJECT:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                            if (!target->HasAura(SPELL_MUTATING_INJECTION))
                                DoCast(target, SPELL_MUTATING_INJECTION);
                        events.ScheduleEvent(EVENT_INJECT, 8000 + uint32(120 * me->GetHealthPct()));
                        return;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

class npc_grobbulus_poison_cloud : public CreatureScript
{
public:
    npc_grobbulus_poison_cloud() : CreatureScript("npc_grobbulus_poison_cloud") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_grobbulus_poison_cloudAI(creature);
    }

    struct npc_grobbulus_poison_cloudAI : public ScriptedAI
    {
        npc_grobbulus_poison_cloudAI(Creature* creature) : ScriptedAI(creature)
        {
            SetCombatMovement(false);
        }

        uint32 Cloud_Timer;

        void Reset()
        {
            Cloud_Timer = 1000;
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
        }

        void UpdateAI(uint32 diff)
        {
            if (Cloud_Timer <= diff)
            {
                DoCast(me, SPELL_POISON_CLOUD_ADD);
                Cloud_Timer = 10000;
            } else Cloud_Timer -= diff;
        }
    };

};

void AddSC_boss_grobbulus()
{
    new boss_grobbulus();
    new npc_grobbulus_poison_cloud();
}
