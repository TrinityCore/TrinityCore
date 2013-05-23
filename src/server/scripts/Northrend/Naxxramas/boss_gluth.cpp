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

enum Gluth
{
    SPELL_MORTAL_WOUND      = 54378,
    SPELL_ENRAGE            = 28371,
    SPELL_DECIMATE          = 28374,
    SPELL_BERSERK           = 26662,
    SPELL_INFECTED_WOUND    = 29306,

    MOB_ZOMBIE              = 16360,
};

enum Events
{
    EVENT_NONE         = 1,
    EVENT_WOUND        = 2,
    EVENT_ENRAGE       = 3,
    EVENT_DECIMATE     = 4,
    EVENT_BERSERK      = 5,
    EVENT_SUMMON       = 6,
};

enum ScriptTexts
{
    EMOTE_ENRAGE     = 0,
    EMOTE_DECIMATE   = 1,
    EMOTE_NEARBY     = 2,
};

const Position PosSummon[3] =
{
    {3267.9f, -3172.1f, 297.42f, 0.94f},
    {3253.2f, -3132.3f, 297.42f, 0},
    {3308.3f, -3185.8f, 297.42f, 1.58f},
};

class boss_gluth : public CreatureScript
{
    public:
        boss_gluth() : CreatureScript("boss_gluth") { }

        struct boss_gluthAI : public BossAI
        {
            boss_gluthAI(Creature* creature) : BossAI(creature, DATA_GLUTH)
            {
                me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_INFECTED_WOUND, true);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->GetEntry() == MOB_ZOMBIE && me->IsWithinDistInMap(who, 7))
                {
                    SetGazeOn(who);
                    TalkToMap(EMOTE_NEARBY);
                }
                else
                    BossAI::MoveInLineOfSight(who);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                events.ScheduleEvent(EVENT_WOUND, 10000);
                events.ScheduleEvent(EVENT_ENRAGE, 15000);
                events.ScheduleEvent(EVENT_DECIMATE, 105000);
                events.ScheduleEvent(EVENT_BERSERK, 480000);
                events.ScheduleEvent(EVENT_SUMMON, 15000);
            }

            void JustSummoned(Creature* summon)
            {
                if (summon->GetEntry() == MOB_ZOMBIE)
                    summon->AI()->AttackStart(me);
                summons.Summon(summon);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictimWithGaze() || !CheckInRoom())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_WOUND:
                            DoCast(me->getVictim(), SPELL_MORTAL_WOUND);
                            events.ScheduleEvent(EVENT_WOUND, 10000);
                            break;
                        case EVENT_ENRAGE:
                            TalkToMap(EMOTE_ENRAGE);
                            DoCast(me, SPELL_ENRAGE);
                            events.ScheduleEvent(EVENT_ENRAGE, 15000);
                            break;
                        case EVENT_DECIMATE:
                            TalkToMap(EMOTE_DECIMATE);
                            DoCastAOE(SPELL_DECIMATE);
                            events.ScheduleEvent(EVENT_DECIMATE, 105000);
                            break;
                        case EVENT_BERSERK:
                            DoCast(me, SPELL_BERSERK);
                            events.ScheduleEvent(EVENT_BERSERK, 300000);
                            break;
                        case EVENT_SUMMON:
                            for (int32 i = 0; i < RAID_MODE(1, 2); ++i)
                               DoSummon(MOB_ZOMBIE, PosSummon[rand() % RAID_MODE(1, 3)]);
                            events.ScheduleEvent(EVENT_SUMMON, 10000);
                            break;
                    }
                }

                if (me->getVictim() && me->getVictim()->GetEntry() == MOB_ZOMBIE)
                {
                    if (me->IsWithinMeleeRange(me->getVictim()))
                    {
                        me->Kill(me->getVictim());
                        me->ModifyHealth(int32(me->CountPctFromMaxHealth(5)));
                    }
                }
                else
                    DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetNaxxramasAI<boss_gluthAI>(creature);
        }
};

void AddSC_boss_gluth()
{
    new boss_gluth();
}
