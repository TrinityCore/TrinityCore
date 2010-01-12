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
#include "naxxramas.h"

enum Spells
{
    SPELL_NECROTIC_AURA                                    = 55593,
    SPELL_SUMMON_SPORE                                     = 29234,
    SPELL_DEATHBLOOM                                       = 29865,
    H_SPELL_DEATHBLOOM                                     = 55053,
    SPELL_INEVITABLE_DOOM                                  = 29204,
    H_SPELL_INEVITABLE_DOOM                                = 55052
};

enum Events
{
    EVENT_NONE,
    EVENT_AURA,
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
                    DoCastAOE(RAID_MODE(SPELL_DEATHBLOOM,H_SPELL_DEATHBLOOM));
                    events.ScheduleEvent(EVENT_BLOOM, 30000);
                    return;
                case EVENT_DOOM:
                    DoCastAOE(RAID_MODE(SPELL_INEVITABLE_DOOM,H_SPELL_INEVITABLE_DOOM));
                    events.ScheduleEvent(EVENT_DOOM, events.GetTimer() < 5*60000 ? 30000 : 15000);
                    return;
            }
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_loatheb(Creature* pCreature)
{
    return new boss_loathebAI (pCreature);
}

enum SporeSpells
{
    SPELL_FUNGAL_CREEP                                     = 29232
};

struct TRINITY_DLL_DECL mob_loatheb_sporeAI : public ScriptedAI
{
    mob_loatheb_sporeAI(Creature *c) : ScriptedAI(c) {}

    void JustDied(Unit* killer)
    {
        DoCast(killer, SPELL_FUNGAL_CREEP);
    }
};

CreatureAI* GetAI_mob_loatheb_spore(Creature* pCreature)
{
    return new mob_loatheb_sporeAI (pCreature);
}

void AddSC_boss_loatheb()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_loatheb";
    newscript->GetAI = &GetAI_boss_loatheb;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_loatheb_spore";
    newscript->GetAI = &GetAI_mob_loatheb_spore;
    newscript->RegisterSelf();

    // Fungal Creep
    //GetAISpellInfo(29232)->condition = AICOND_DIE;
}

