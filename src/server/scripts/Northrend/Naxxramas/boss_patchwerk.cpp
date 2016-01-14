/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
    SPELL_HATEFUL_STRIKE                        = 28308,
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
    EMOTE_FRENZY                                = 4
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

enum HatefulThreatAmounts
{
    HATEFUL_THREAT_AMT  = 1000,
};

class boss_patchwerk : public CreatureScript
{
public:
    boss_patchwerk() : CreatureScript("boss_patchwerk") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<boss_patchwerkAI>(creature);
    }

    struct boss_patchwerkAI : public BossAI
    {
        boss_patchwerkAI(Creature* creature) : BossAI(creature, BOSS_PATCHWERK)
        {
            Enraged = false;
        }

        bool Enraged;

        void Reset() override
        {
            _Reset();

            instance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT);
        }

        void KilledUnit(Unit* /*Victim*/) override
        {
            if (!(rand32() % 5))
                Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
            Talk(SAY_DEATH);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            _EnterCombat();
            Enraged = false;
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_HATEFUL, 1 * IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_BERSERK, 6 * MINUTE * IN_MILLISECONDS);

            instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_MAKE_QUICK_WERK_OF_HIM_STARTING_EVENT);
        }

        void UpdateAI(uint32 diff) override
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
                        // Hateful Strike targets the highest non-MT threat in melee range on 10man
                        // and the higher HP target out of the two highest non-MT threats in melee range on 25man
                        float MostThreat = 0.0f;
                        Unit* secondThreatTarget = NULL;
                        Unit* thirdThreatTarget = NULL;

                        std::list<HostileReference*>::const_iterator i = me->getThreatManager().getThreatList().begin();
                        for (; i != me->getThreatManager().getThreatList().end(); ++i)
                        { // find second highest
                            Unit* target = (*i)->getTarget();
                            if (target->IsAlive() && target != me->GetVictim() && (*i)->getThreat() >= MostThreat && me->IsWithinMeleeRange(target))
                            {
                                MostThreat = (*i)->getThreat();
                                secondThreatTarget = target;
                            }
                        }

                        if (secondThreatTarget && Is25ManRaid())
                        { // find third highest
                            MostThreat = 0.0f;
                            i = me->getThreatManager().getThreatList().begin();
                            for (; i != me->getThreatManager().getThreatList().end(); ++i)
                            {
                                Unit* target = (*i)->getTarget();
                                if (target->IsAlive() && target != me->GetVictim() && target != secondThreatTarget && (*i)->getThreat() >= MostThreat && me->IsWithinMeleeRange(target))
                                {
                                    MostThreat = (*i)->getThreat();
                                    thirdThreatTarget = target;
                                }
                            }
                        }

                        Unit* pHatefulTarget = NULL;
                        if (!thirdThreatTarget)
                            pHatefulTarget = secondThreatTarget;
                        else if (secondThreatTarget)
                            pHatefulTarget = (secondThreatTarget->GetHealth() < thirdThreatTarget->GetHealth()) ? thirdThreatTarget : secondThreatTarget;

                        if (!pHatefulTarget)
                            pHatefulTarget = me->GetVictim();

                        DoCast(pHatefulTarget, SPELL_HATEFUL_STRIKE, true);

                        // add threat to highest threat targets
                        if (me->GetVictim() && me->IsWithinMeleeRange(me->GetVictim()))
                            me->getThreatManager().addThreat(me->GetVictim(), HATEFUL_THREAT_AMT);
                        if (secondThreatTarget)
                            me->getThreatManager().addThreat(secondThreatTarget, HATEFUL_THREAT_AMT);
                        if (thirdThreatTarget)
                            me->getThreatManager().addThreat(thirdThreatTarget, HATEFUL_THREAT_AMT); // this will only ever be used in 25m

                        events.ScheduleEvent(EVENT_HATEFUL, 1 * IN_MILLISECONDS);
                        break;
                    }
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK, true);
                        Talk(EMOTE_BERSERK);
                        events.ScheduleEvent(EVENT_SLIME, 2 * IN_MILLISECONDS);
                        break;
                    case EVENT_SLIME:
                        DoCastVictim(SPELL_SLIME_BOLT, true);
                        events.ScheduleEvent(EVENT_SLIME, 2 * IN_MILLISECONDS);
                        break;
                }
            }

            if (!Enraged && HealthBelowPct(5))
            {
                DoCast(me, SPELL_FRENZY, true);
                Talk(EMOTE_FRENZY);
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
