/*
 * Copyright (C) 2009-2010 Trinity <http://www.trinitycore.org/>
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

/*** SQL START ***
UPDATE `creature_template` SET `ScriptName`='boss_koralon' WHERE `entry`='35013';
UPDATE `creature_template` SET `ScriptName`='mob_flame_warder' WHERE `entry`='35143';
*** SQL END ***/

#include "ScriptPCH.h"
#include "vault_of_archavon.h"

enum Events
{
    EVENT_NONE,

    // Koralon
    EVENT_BURNING_BREATH,
    EVENT_BURNING_FURY,
    EVENT_FLAME_CINDER_A,
    EVENT_METEOR_FISTS_A,
    EVENT_METEOR_FISTS_B,

    // Flame Warder
    EVENT_FW_LAVA_BIRST,
    EVENT_FW_METEOR_FISTS_A,
    EVENT_FW_METEOR_FISTS_B,
};

enum Spells
{
    // Spells Koralon
    SPELL_BURNING_BREATH                        = 66665,
    SPELL_BURNING_BREATH_H                      = 67328,
    SPELL_BURNING_FURY                          = 66721,
    SPELL_FLAME_CINDER_A                        = 66684,
    SPELL_FLAME_CINDER_A_H                      = 67332,
    SPELL_FLAME_CINDER_B                        = 66681, // don't know the real relation to SPELL_FLAME_CINDER_A atm.
    SPELL_METEOR_FISTS_A                        = 66725,
    SPELL_METEOR_FISTS_A_H                      = 66765,
    SPELL_METEOR_FISTS_B                        = 67333,
    SPELL_METEOR_FISTS_B_H                      = 68161,

    // Spells Flame Warder
    SPELL_FW_LAVA_BIRST                         = 66813,
    SPELL_FW_LAVA_BIRST_H                       = 67330,
    SPELL_FW_METEOR_FISTS_A                     = 66808,
    SPELL_FW_METEOR_FISTS_A_H                   = 66809,
    SPELL_FW_METEOR_FISTS_B                     = 67331,
    SPELL_FW_METEOR_FISTS_B_H                   = 68160,
};

struct boss_koralonAI : public ScriptedAI
{
    boss_koralonAI(Creature *c) : ScriptedAI(c)
    {
        pInstance = c->GetInstanceData();
    }

    ScriptedInstance *pInstance;
    EventMap events;

    void Reset()
    {
        events.Reset();

        if (pInstance)
            pInstance->SetData(DATA_KORALON_EVENT, NOT_STARTED);
    }

    void KilledUnit(Unit* /*Victim*/) {}

    void JustDied(Unit* /*Killer*/)
    {
        if (pInstance)
            pInstance->SetData(DATA_KORALON_EVENT, DONE);
    }

    void EnterCombat(Unit * /*who*/)
    {
        DoZoneInCombat();

        DoCast(me, SPELL_BURNING_FURY);

        events.ScheduleEvent(EVENT_BURNING_FURY, 20000);    // TODO check timer
        events.ScheduleEvent(EVENT_BURNING_BREATH, 15000);  // 1st after 15sec, then every 45sec
        events.ScheduleEvent(EVENT_METEOR_FISTS_A, 75000);  // 1st after 75sec, then every 45sec
        events.ScheduleEvent(EVENT_FLAME_CINDER_A, 30000);  // TODO check timer

        if (pInstance)
            pInstance->SetData(DATA_KORALON_EVENT, IN_PROGRESS);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_BURNING_FURY:
                    DoCast(me, SPELL_BURNING_FURY);
                    events.ScheduleEvent(EVENT_BURNING_FURY, 20000);
                    return;
                case EVENT_BURNING_BREATH:
                    DoCast(me, RAID_MODE(SPELL_BURNING_BREATH,SPELL_BURNING_BREATH_H));
                    events.ScheduleEvent(EVENT_BURNING_BREATH, 45000);
                    return;
                case EVENT_METEOR_FISTS_A:
                    DoCast(me, RAID_MODE(SPELL_METEOR_FISTS_A,SPELL_METEOR_FISTS_A_H));
                    events.ScheduleEvent(EVENT_METEOR_FISTS_B, 1500);
                    return;
                case EVENT_METEOR_FISTS_B:
                    DoCast(me, RAID_MODE(SPELL_METEOR_FISTS_B,SPELL_METEOR_FISTS_B_H));
                    events.ScheduleEvent(EVENT_METEOR_FISTS_A, 45000);
                    return;
                case EVENT_FLAME_CINDER_A:
                    DoCast(me, RAID_MODE(SPELL_FLAME_CINDER_A,SPELL_FLAME_CINDER_A_H));
                    events.ScheduleEvent(EVENT_FLAME_CINDER_A, 30000);
                    return;
            }
        }
        DoMeleeAttackIfReady();
    }
};

/*######
##  Mob Flame Warder
######*/
struct mob_flame_warderAI : public ScriptedAI
{
    mob_flame_warderAI(Creature *c) : ScriptedAI(c) {}

    EventMap events;

    void Reset()
    {
        events.Reset();
    }

    void EnterCombat(Unit * /*who*/)
    {
        DoZoneInCombat();

        events.ScheduleEvent(EVENT_FW_LAVA_BIRST, 5000);
        events.ScheduleEvent(EVENT_FW_METEOR_FISTS_A, 10000);
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
                case EVENT_FW_LAVA_BIRST:
                    DoCast(me->getVictim(), RAID_MODE(SPELL_FW_LAVA_BIRST,SPELL_FW_LAVA_BIRST_H));
                    events.ScheduleEvent(EVENT_FW_LAVA_BIRST, 15000);
                    return;
                case EVENT_FW_METEOR_FISTS_A:
                    DoCast(me, RAID_MODE(SPELL_FW_METEOR_FISTS_A,SPELL_FW_METEOR_FISTS_A_H));
                    events.ScheduleEvent(EVENT_FW_METEOR_FISTS_B, 1500);
                    return;
                case EVENT_FW_METEOR_FISTS_B:
                    DoCast(me, RAID_MODE(SPELL_FW_METEOR_FISTS_B,SPELL_FW_METEOR_FISTS_B_H));
                    events.ScheduleEvent(EVENT_FW_METEOR_FISTS_A, 20000);
                    return;
            }
        }
        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_koralon(Creature* pCreature)
{
    return new boss_koralonAI (pCreature);
}

CreatureAI* GetAI_mob_flame_warder(Creature* pCreature)
{
    return new mob_flame_warderAI (pCreature);
}

void AddSC_boss_koralon()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "boss_koralon";
    newscript->GetAI = &GetAI_boss_koralon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_flame_warder";
    newscript->GetAI = &GetAI_mob_flame_warder;
    newscript->RegisterSelf();
}
