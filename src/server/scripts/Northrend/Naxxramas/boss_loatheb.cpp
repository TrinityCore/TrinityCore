/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "naxxramas.h"

enum Spells
{
    SPELL_NECROTIC_AURA                                    = 55593,
    SPELL_SUMMON_SPORE                                     = 29234,
    SPELL_DEATHBLOOM                                       = 29865,
    H_SPELL_DEATHBLOOM                                     = 55053,
    SPELL_INEVITABLE_DOOM                                  = 29204,
    H_SPELL_INEVITABLE_DOOM                                = 55052,
    SPELL_BERSERK                                          = 27680
};

enum Events
{
    EVENT_NONE,
    EVENT_AURA,
    EVENT_BLOOM,
    EVENT_DOOM,
    EVENT_BERSERK
};

class boss_loatheb : public CreatureScript
{
public:
    boss_loatheb() : CreatureScript("boss_loatheb") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_loathebAI (pCreature);
    }

    struct boss_loathebAI : public BossAI
    {
        boss_loathebAI(Creature *c) : BossAI(c, BOSS_LOATHEB) {}

        void Reset()
        {
            _Reset();
            SetImmuneToDeathGrip();
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            events.ScheduleEvent(EVENT_AURA, 10000);
            events.ScheduleEvent(EVENT_BLOOM, 5000);
            events.ScheduleEvent(EVENT_DOOM, 120000);
            events.ScheduleEvent(EVENT_BERSERK, 12*60000);
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_AURA:
                        DoCastAOE(SPELL_NECROTIC_AURA);
                        events.ScheduleEvent(EVENT_AURA, 20000);
                        break;
                    case EVENT_BLOOM:
                        // TODO : Add missing text
                        DoCastAOE(SPELL_SUMMON_SPORE, true);
                        DoCastAOE(RAID_MODE(SPELL_DEATHBLOOM, H_SPELL_DEATHBLOOM));
                        events.ScheduleEvent(EVENT_BLOOM, 30000);
                        break;
                    case EVENT_DOOM:
                        DoCastAOE(RAID_MODE(SPELL_INEVITABLE_DOOM, H_SPELL_INEVITABLE_DOOM));
                        events.ScheduleEvent(EVENT_DOOM, events.GetTimer() < 5*60000 ? 30000 : 15000);
                        break;
                    case EVENT_BERSERK:
                        if(GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                        {
                            if(!me->HasAura(SPELL_BERSERK))
                                DoCast(me,SPELL_BERSERK,true);
                        }
                         events.ScheduleEvent(EVENT_BERSERK, 60000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

enum SporeSpells
{
    SPELL_FUNGAL_CREEP                                     = 29232
};

class mob_loatheb_spore : public CreatureScript
{
public:
    mob_loatheb_spore() : CreatureScript("mob_loatheb_spore") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new mob_loatheb_sporeAI (pCreature);
    }

    struct mob_loatheb_sporeAI : public ScriptedAI
    {
        mob_loatheb_sporeAI(Creature *c) : ScriptedAI(c) {}

        void JustDied(Unit* killer)
        {
            DoCastAOE(SPELL_FUNGAL_CREEP, true); //A Little bit hacky ... but it works now (without triggered no cast on death)
        }
    };

};

void AddSC_boss_loatheb()
{
    new boss_loatheb();
    new mob_loatheb_spore();
}
