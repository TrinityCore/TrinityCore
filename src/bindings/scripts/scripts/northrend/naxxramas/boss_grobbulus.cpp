/* Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "precompiled.h"
#include "naxxramas.h"

#define SPELL_BOMBARD_SLIME         28280

#define SPELL_POISON_CLOUD          28240
#define SPELL_MUTATING_INJECTION    28169
#define SPELL_SLIME_SPRAY           RAID_MODE(28157,54364)
#define SPELL_BERSERK               26662
#define SPELL_POISON_CLOUD_ADD      59116

#define EVENT_BERSERK   1
#define EVENT_CLOUD     2
#define EVENT_INJECT    3
#define EVENT_SPRAY     4

#define MOB_FALLOUT_SLIME   16290

struct TRINITY_DLL_DECL boss_grobbulusAI : public BossAI
{
    boss_grobbulusAI(Creature *c) : BossAI(c, BOSS_GROBBULUS)
    {
        me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_POISON_CLOUD_ADD, true);
    }

    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        events.ScheduleEvent(EVENT_CLOUD, 15000);
        events.ScheduleEvent(EVENT_INJECT, 20000);
        events.ScheduleEvent(EVENT_SPRAY, 15000+rand()%15000); //not sure
        events.ScheduleEvent(EVENT_BERSERK, 12*60000);
    }

    void SpellHitTarget(Unit *pTarget, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_SLIME_SPRAY)
        {
            if (TempSummon *slime = me->SummonCreature(MOB_FALLOUT_SLIME, pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0))
                DoZoneInCombat(slime);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
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
                    if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM, 1))
                        if (!pTarget->HasAura(SPELL_MUTATING_INJECTION))
                            DoCast(pTarget, SPELL_MUTATING_INJECTION);
                    events.ScheduleEvent(EVENT_INJECT, 8000 + 12000 * ((float)me->GetHealth() / me->GetMaxHealth()));
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

struct TRINITY_DLL_DECL npc_grobbulus_poison_cloudAI : public Scripted_NoMovementAI
{
    npc_grobbulus_poison_cloudAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature)
    {
        Reset();
    }

    uint32 Cloud_Timer;

    void Reset()
    {
        Cloud_Timer = 1000;
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
    }

    void UpdateAI(const uint32 diff)
    {
        if (Cloud_Timer <= diff)
        {
            DoCast(m_creature, SPELL_POISON_CLOUD_ADD);
            Cloud_Timer = 10000;
        } else Cloud_Timer -= diff;
    }
};

CreatureAI* GetAI_boss_grobbulus(Creature* pCreature)
{
    return new boss_grobbulusAI (pCreature);
}

CreatureAI* GetAI_npc_grobbulus_poison_cloud(Creature* pCreature)
{
    return new npc_grobbulus_poison_cloudAI(pCreature);
}

void AddSC_boss_grobbulus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_grobbulus";
    newscript->GetAI = &GetAI_boss_grobbulus;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_grobbulus_poison_cloud";
    newscript->GetAI = &GetAI_npc_grobbulus_poison_cloud;
    newscript->RegisterSelf();
}
