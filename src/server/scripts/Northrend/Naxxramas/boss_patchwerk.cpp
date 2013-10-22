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

enum Spells
{
    SPELL_HATEFUL_STRIKE                        = 41926,
    H_SPELL_HATEFUL_STRIKE                      = 59192,
    SPELL_FRENZY                                = 28131,
    SPELL_BERSERK                               = 26662,
    SPELL_SLIME_BOLT                            = 32309
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_SLAY                                    = 1,
    SAY_DEATH                                   = 2,
    EMOTE_BERSERK                               = 3,
    EMOTE_ENRAGE                                = 4
};

enum Events
{
    EVENT_NONE,
    EVENT_BERSERK,
    EVENT_HATEFUL,
    EVENT_SLIME
};

enum Misc
{
    ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT  = 10286
};

class boss_patchwerk : public CreatureScript
{
public:
    boss_patchwerk() : CreatureScript("boss_patchwerk") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return new boss_patchwerkAI(creature);
    }

    struct boss_patchwerkAI : public BossAI
    {
        boss_patchwerkAI(Creature* creature) : BossAI(creature, BOSS_PATCHWERK) { }

        bool Enraged;

        void Reset() OVERRIDE
        {
            _Reset();

            if (instance)
                instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT);
        }

        void KilledUnit(Unit* /*Victim*/) OVERRIDE
        {
            if (!(rand()%5))
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _EnterCombat();
            Enraged = false;
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_HATEFUL, 1000);
            events.ScheduleEvent(EVENT_BERSERK, 360000);

            if (instance)
                instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT);
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_HATEFUL:
                    {
                        //Cast Hateful strike on the player with the highest
                        //amount of HP within melee distance
                        uint32 MostHP = 0;
                        Unit* pMostHPTarget = NULL;
                        std::list<HostileReference*>::const_iterator i = me->getThreatManager().getThreatList().begin();
                        for (; i != me->getThreatManager().getThreatList().end(); ++i)
                        {
                            Unit* target = (*i)->getTarget();
                            if (target->IsAlive() && target != me->GetVictim() && target->GetHealth() > MostHP && me->IsWithinMeleeRange(target))
                            {
                                MostHP = target->GetHealth();
                                pMostHPTarget = target;
                            }
                        }

                        if (!pMostHPTarget)
                            pMostHPTarget = me->GetVictim();

                        DoCast(pMostHPTarget, RAID_MODE(SPELL_HATEFUL_STRIKE, H_SPELL_HATEFUL_STRIKE), true);

                        events.ScheduleEvent(EVENT_HATEFUL, 1000);
                        break;
                    }
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK, true);
                        Talk(EMOTE_BERSERK);
                        events.ScheduleEvent(EVENT_SLIME, 2000);
                        break;
                    case EVENT_SLIME:
                        DoCastVictim(SPELL_SLIME_BOLT, true);
                        events.ScheduleEvent(EVENT_SLIME, 2000);
                        break;
                }
            }

            if (!Enraged && HealthBelowPct(5))
            {
                DoCast(me, SPELL_FRENZY, true);
                Talk(EMOTE_ENRAGE);
                Enraged = true;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_patchwerk()
{
    new boss_patchwerk();
}
