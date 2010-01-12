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

#define SPELL_MORTAL_WOUND      25646
#define SPELL_ENRAGE            RAID_MODE(28371,54427)
#define SPELL_DECIMATE          RAID_MODE(28374,54426)
#define SPELL_BERSERK           26662
#define SPELL_INFECTED_WOUND    29306

#define MOB_ZOMBIE  16360

const Position PosSummon[3] =
{
    {3267.9, -3172.1, 297.42, 0.94},
    {3253.2, -3132.3, 297.42, 0},
    {3308.3, -3185.8, 297.42, 1.58},
};

enum Events
{
    EVENT_NONE,
    EVENT_WOUND,
    EVENT_ENRAGE,
    EVENT_DECIMATE,
    EVENT_BERSERK,
    EVENT_SUMMON,
};

#define EMOTE_NEARBY    " spots a nearby zombie to devour!"

struct TRINITY_DLL_DECL boss_gluthAI : public BossAI
{
    boss_gluthAI(Creature *c) : BossAI(c, BOSS_GLUTH)
    {
        // Do not let Gluth be affected by zombies' debuff
        me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_INFECTED_WOUND, true);
    }

    std::vector<Creature*> triggers;

    void Reset()
    {
        triggers.clear();
        _Reset();
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (who->GetEntry() == MOB_ZOMBIE && me->IsWithinDistInMap(who, 7))
        {
            SetGazeOn(who);
            // TODO: use a script text
            me->MonsterTextEmote(EMOTE_NEARBY, 0, true);
        }
        else
            BossAI::MoveInLineOfSight(who);
    }

    void EnterCombat(Unit *who)
    {
        for (uint32 i = 0; i < 3; ++i)
            if (Creature *trigger = DoSummon(WORLD_TRIGGER, PosSummon[i]))
                triggers.push_back(trigger);
        if (triggers.size() < 3)
        {
            error_log("Script Gluth: cannot summon triggers!");
            EnterEvadeMode();
            return;
        }

        _EnterCombat();
        events.ScheduleEvent(EVENT_WOUND, 10000);
        events.ScheduleEvent(EVENT_ENRAGE, 15000);
        events.ScheduleEvent(EVENT_DECIMATE, 105000);
        events.ScheduleEvent(EVENT_BERSERK, 8*60000);
        events.ScheduleEvent(EVENT_SUMMON, 15000);
    }

    void JustSummoned(Creature *summon)
    {
        if (summon->GetEntry() == WORLD_TRIGGER)
            summon->setActive(true);
        else if (summon->GetEntry() == MOB_ZOMBIE)
            summon->AI()->AttackStart(me);
        summons.Summon(summon);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictimWithGaze() || !CheckInRoom())
            return;

        events.Update(diff);

        while(uint32 eventId = events.ExecuteEvent())
        {
            switch(eventId)
            {
                case EVENT_WOUND:
                    DoCast(me->getVictim(), SPELL_MORTAL_WOUND);
                    events.ScheduleEvent(EVENT_WOUND, 10000);
                    break;
                case EVENT_ENRAGE:
                    // TODO : Add missing text
                    DoCast(me, SPELL_ENRAGE);
                    events.ScheduleEvent(EVENT_ENRAGE, 15000);
                    break;
                case EVENT_DECIMATE:
                    // TODO : Add missing text
                    DoCastAOE(SPELL_DECIMATE);
                    events.ScheduleEvent(EVENT_DECIMATE, 105000);
                    break;
                case EVENT_BERSERK:
                    DoCast(me, SPELL_BERSERK);
                    events.ScheduleEvent(EVENT_BERSERK, 5*60000);
                    break;
                case EVENT_SUMMON:
                    for (uint32 i = 0; i < RAID_MODE(1,2); ++i)
                        DoSummon(MOB_ZOMBIE, triggers[rand()%3]);
                    events.ScheduleEvent(EVENT_SUMMON, 10000);
                    break;
            }
        }

        if (me->getVictim()->GetEntry() == MOB_ZOMBIE)
        {
            if (me->IsWithinMeleeRange(me->getVictim()))
            {
                me->Kill(me->getVictim());
                me->ModifyHealth(me->GetMaxHealth() * 0.05f);
            }
        }
        else
            DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_gluth(Creature* pCreature)
{
    return new boss_gluthAI (pCreature);
}

void AddSC_boss_gluth()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_gluth";
    newscript->GetAI = &GetAI_boss_gluth;
    newscript->RegisterSelf();
}

