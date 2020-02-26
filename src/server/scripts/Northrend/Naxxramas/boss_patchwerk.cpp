/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "InstanceScript.h"
#include "naxxramas.h"
#include "ScriptedCreature.h"

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
        return GetNaxxramasAI<boss_patchwerkAI>(creature);
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

        void JustEngagedWith(Unit* who) override
        {
            BossAI::JustEngagedWith(who);
            Enraged = false;
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_HATEFUL, 1s);
            events.ScheduleEvent(EVENT_BERSERK, 6min);

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
                        ThreatReference* secondThreat = nullptr;
                        ThreatReference* thirdThreat = nullptr;

                        ThreatManager& mgr = me->GetThreatManager();
                        Unit* currentVictim = mgr.GetCurrentVictim();
                        auto list = mgr.GetModifiableThreatList();
                        auto it = list.begin(), end = list.end();
                        if (it == end)
                        {
                            EnterEvadeMode(EVADE_REASON_NO_HOSTILES);
                            return;
                        }

                        if ((*it)->GetVictim() != currentVictim)
                            secondThreat = *it;
                        if ((!secondThreat || Is25ManRaid()) && (++it != end && (*it)->IsAvailable()))
                        {
                            if ((*it)->GetVictim() != currentVictim)
                                (secondThreat ? thirdThreat : secondThreat) = *it;
                            if (!thirdThreat && Is25ManRaid() && (++it != end && (*it)->IsAvailable()))
                                thirdThreat = *it;
                        }

                        Unit* pHatefulTarget = nullptr;
                        if (!secondThreat)
                            pHatefulTarget = currentVictim;
                        else if (!thirdThreat)
                            pHatefulTarget = secondThreat->GetVictim();
                        else
                            pHatefulTarget = (secondThreat->GetVictim()->GetHealth() < thirdThreat->GetVictim()->GetHealth()) ? thirdThreat->GetVictim() : secondThreat->GetVictim();

                        // add threat to highest threat targets
                        AddThreat(currentVictim, HATEFUL_THREAT_AMT);
                        if (secondThreat)
                            secondThreat->AddThreat(HATEFUL_THREAT_AMT);
                        if (thirdThreat)
                            thirdThreat->AddThreat(HATEFUL_THREAT_AMT);

                        DoCast(pHatefulTarget, SPELL_HATEFUL_STRIKE, true);

                        events.Repeat(Seconds(1));
                        break;
                    }
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK, true);
                        Talk(EMOTE_BERSERK);
                        events.ScheduleEvent(EVENT_SLIME, 2s);
                        break;
                    case EVENT_SLIME:
                        DoCastAOE(SPELL_SLIME_BOLT, true);
                        events.Repeat(Seconds(2));
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
