/*
 * Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
 *
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

#define SPELL_NECROTIC_AURA         55593
#define SPELL_SUMMON_SPORE          29234
#define SPELL_DEATHBLOOM            HEROIC(29865,55053)
#define SPELL_INEVITABLE_DOOM       HEROIC(29204,55052)

enum Events
{
    EVENT_AURA = 1,
    EVENT_BLOOM,
    EVENT_DOOM,
};

struct TRINITY_DLL_DECL boss_loathebAI : public BossAI
{
    boss_loathebAI(Creature *c) : BossAI(c, BOSS_LOATHEB) {}

    void EnterCombat(Unit *who)
    {
        _EnterCombat();
        events.ScheduleEvent(EVENT_AURA, 0);
        events.ScheduleEvent(EVENT_BLOOM, 30000);
        events.ScheduleEvent(EVENT_DOOM, 120000);
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
                case EVENT_AURA:
                    DoCastAOE(SPELL_NECROTIC_AURA);
                    events.ScheduleEvent(EVENT_AURA, 20000);
                    return;
                case EVENT_BLOOM:
                    DoCastAOE(SPELL_SUMMON_SPORE, true);
                    DoCastAOE(SPELL_DEATHBLOOM);
                    events.ScheduleEvent(EVENT_BLOOM, 30000);
                    return;
                case EVENT_DOOM:
                    DoCastAOE(SPELL_INEVITABLE_DOOM);
                    events.ScheduleEvent(EVENT_DOOM, events.GetTimer() < 5*60000 ? 30000 : 15000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_loatheb(Creature *_Creature)
{
    return new boss_loathebAI (_Creature);
}

void AddSC_boss_loatheb()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_loatheb";
    newscript->GetAI = &GetAI_boss_loatheb;
    newscript->RegisterSelf();

    // Fungal Creep
    GetAISpellInfo(29232)->condition = AICOND_DIE;
}

