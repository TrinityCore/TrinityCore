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
#include "def_naxxramas.h"

#define SPELL_BOMBARD_SLIME         28280

#define SPELL_POISON_CLOUD          28240
#define SPELL_MUTATING_INJECTION    28169
#define SPELL_SLIME_SPRAY           HEROIC(28157,54364)
#define SPELL_BERSERK               26662

#define EVENT_BERSERK   1
#define EVENT_CLOUD     2
#define EVENT_INJECT    3
#define EVENT_SPRAY     4

#define MOB_FALLOUT_SLIME   16290

struct TRINITY_DLL_DECL boss_grobbulusAI : public BossAI
{
    boss_grobbulusAI(Creature *c) : BossAI(c, BOSS_GROBBULUS) {}

    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        events.ScheduleEvent(EVENT_CLOUD, 15000);
        events.ScheduleEvent(EVENT_INJECT, 20000);
        events.ScheduleEvent(EVENT_SPRAY, 15000+rand()%15000); //not sure
        events.ScheduleEvent(EVENT_BERSERK, 12*60000);
    }

    void SpellHitTarget(Unit *target, const SpellEntry *spell)
    {
        if (spell->Id == SPELL_SLIME_SPRAY)
        {
            if (TempSummon *slime = me->SummonCreature(MOB_FALLOUT_SLIME, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 0))
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
                    if (Unit *target = SelectUnit(SELECT_TARGET_RANDOM, 0))
                        if (!target->HasAura(SPELL_MUTATING_INJECTION))
                            DoCast(target, SPELL_MUTATING_INJECTION);
                    events.ScheduleEvent(EVENT_INJECT, 8000 + 12000 * ((float)me->GetHealth() / me->GetMaxHealth()));
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_grobbulus(Creature *_Creature)
{
    return new boss_grobbulusAI (_Creature);
}

void AddSC_boss_grobbulus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_grobbulus";
    newscript->GetAI = &GetAI_boss_grobbulus;
    newscript->RegisterSelf();
}
