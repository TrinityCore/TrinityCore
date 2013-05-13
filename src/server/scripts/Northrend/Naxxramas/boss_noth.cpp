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

#define SPELL_BLINK                     RAND(29208, 29209, 29210, 29211)

enum Noth
{
    SAY_AGGRO                       = 0,
    SAY_SUMMON                      = 1,
    SAY_SLAY                        = 2,
    SAY_DEATH                       = 3,
    EMOTE_SUMMON                    = 4,
    EMOTE_BALCONY                   = 5,
    EMOTE_SKELETON                  = 6,
    EMOTE_TELEPORT                  = 7,  
    EMOTE_BLINK                     = 8,

    SPELL_CURSE_PLAGUEBRINGER       = 29213,
    SPELL_CRIPPLE                   = 29212,
    SPELL_TELEPORT_BALCONY          = 29216,
    SPELL_TELEPORT_BACK             = 29231,
    SPELL_SUMMON_WARRIOR_1          = 29247,
    SPELL_SUMMON_WARRIOR_2          = 29248,
    SPELL_SUMMON_WARRIOR_3          = 29249,
    SPELL_SUMMON_CHAMPION_1         = 29255,
    SPELL_SUMMON_CHAMPION_2         = 29257,
    SPELL_SUMMON_CHAMPION_3         = 29224,
    SPELL_SUMMON_CHAMPION_4         = 29262,
    SPELL_SUMMON_GUARDIAN_1         = 29226,
    SPELL_SUMMON_GUARDIAN_2         = 29268,
    SPELL_SUMMON_GUARDIAN_3         = 29256,
    SPELL_SUMMON_CONSTRUCT_1        = 54862,
    SPELL_SUMMON_CONST_CHAMP        = 29240,

    MOB_WARRIOR                     = 16984,
    MOB_CHAMPION                    = 16983,
    MOB_GUARDIAN                    = 16981,
};

enum Events
{
    EVENT_NONE,
    EVENT_BERSERK,
    EVENT_CURSE,
    EVENT_BLINK,
    EVENT_WARRIOR,
    EVENT_BALCONY,
    EVENT_WAVE,
    EVENT_GROUND,
    EVENT_SUMMON,
    EVENT_BALCONY_TELEPORT,
};

class StartMovementEvent : public BasicEvent
{
    public:
        StartMovementEvent(Creature* summoner, Creature* owner)
            : _summoner(summoner), _owner(owner)
        {
        }

        bool Execute(uint64 /*time*/, uint32 /*diff*/)
        {
            _owner->SetReactState(REACT_AGGRESSIVE);
            if (Unit* target = _summoner->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(_summoner)))
                _owner->AI()->AttackStart(target);
            return true;
        }

    private:
        Creature* _summoner;
        Creature* _owner;
};

class boss_noth : public CreatureScript
{
    public:
        boss_noth() : CreatureScript("boss_noth") { }

        struct boss_nothAI : public BossAI
        {
            boss_nothAI(Creature* creature) : BossAI(creature, DATA_NOTH) {}

            void Reset()
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                _Reset();
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                TalkToMap(SAY_AGGRO);
                balconyCount = 0;
                EnterPhaseGround();
            }

            void EnterPhaseGround()
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                DoZoneInCombat();
                if (me->getThreatManager().isThreatListEmpty())
                    EnterEvadeMode();
                else
                {
                    events.ScheduleEvent(EVENT_BALCONY, 110000);
                    events.ScheduleEvent(EVENT_CURSE, 10000+rand()%15000);
                    events.ScheduleEvent(EVENT_WARRIOR, 30000);
                    if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                        events.ScheduleEvent(EVENT_BLINK, urand(20000, 40000));
                }
            }

            void KilledUnit(Unit* /*victim*/)
            {
                TalkToMap(SAY_SLAY);
            }

            void JustSummoned(Creature* summon)
            {
                switch (summon->GetEntry())
                {
                    case MOB_WARRIOR:
                    case MOB_CHAMPION:
                        summon->SetReactState(REACT_PASSIVE);
                        summon->HandleEmoteCommand(EMOTE_ONESHOT_EMERGE);
                        summon->m_Events.AddEvent(new StartMovementEvent(me, summon), summon->m_Events.CalculateTime(5000));
                        break;
                    default:
                        break;
                }
                BossAI::JustSummoned(summon);
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
            {
                switch (summon->GetEntry())
                {
                    case MOB_WARRIOR:
                    case MOB_CHAMPION:
                    case MOB_GUARDIAN:
                        summon->ToTempSummon()->DespawnOrUnsummon(4000);
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                TalkToMap(SAY_DEATH);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CURSE:
                            DoCastAOE(SPELL_CURSE_PLAGUEBRINGER);
                            events.ScheduleEvent(EVENT_CURSE, urand(50000, 60000));
                            break;
                        case EVENT_WARRIOR:
                            TalkToMap(SAY_SUMMON);
                            TalkToMap(EMOTE_SUMMON);
                            events.ScheduleEvent(EVENT_SUMMON, 4000);
                            break;
                        case EVENT_SUMMON:
                            DoCast(me, SPELL_SUMMON_WARRIOR_1);
                            DoCast(me, SPELL_SUMMON_WARRIOR_2);
                            if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                                DoCast(me, SPELL_SUMMON_WARRIOR_3);
                            events.ScheduleEvent(EVENT_WARRIOR, 26000);
                            break;
                        case EVENT_BLINK:
                            TalkToMap(EMOTE_BLINK);
                            DoCastAOE(SPELL_CRIPPLE);
                            DoCastAOE(SPELL_BLINK);
                            DoResetThreat();
                            events.ScheduleEvent(EVENT_BLINK, 40000);
                            break;
                        case EVENT_BALCONY:
                            TalkToMap(EMOTE_BALCONY);
                            me->SetReactState(REACT_PASSIVE);
                            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            me->AttackStop();
                            me->RemoveAllAuras();
                            events.ScheduleEvent(EVENT_BALCONY_TELEPORT, 2000);
                            break;
                        case EVENT_BALCONY_TELEPORT:
                            DoCast(SPELL_TELEPORT_BALCONY);
                            events.Reset();
                            events.ScheduleEvent(EVENT_WAVE, urand(2000, 5000));
                            waveCount = 0;
                            break;
                        case EVENT_WAVE:
                            TalkToMap(EMOTE_SKELETON);
                            switch (balconyCount)
                            {
                                case 0:
                                    DoCast(me, SPELL_SUMMON_CHAMPION_1);
                                    DoCast(me, SPELL_SUMMON_CHAMPION_2);
                                    if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                                    {
                                        DoCast(me, SPELL_SUMMON_CHAMPION_3);
                                        DoCast(me, SPELL_SUMMON_CHAMPION_4);
                                    }
                                    break;
                                case 1:
                                    DoCast(me, SPELL_SUMMON_CHAMPION_1);
                                    DoCast(me, SPELL_SUMMON_CHAMPION_2);
                                    if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                                    {
                                        DoCast(me, SPELL_SUMMON_CHAMPION_3);
                                        DoCast(me, SPELL_SUMMON_CHAMPION_4);
                                    }
                                    break;
                                case 2:
                                    if (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
                                    {
                                        DoCast(me, SPELL_SUMMON_CHAMPION_1);
                                        DoCast(me, SPELL_SUMMON_GUARDIAN_2);
                                        DoCast(me, SPELL_SUMMON_GUARDIAN_1);
                                    }
                                    else if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                                    {
                                        DoCast(me, SPELL_SUMMON_CHAMPION_1);
                                        DoCast(me, SPELL_SUMMON_CHAMPION_2);
                                        DoCast(me, SPELL_SUMMON_CHAMPION_3);
                                        DoCast(me, SPELL_SUMMON_CHAMPION_4);
                                        DoCast(me, SPELL_SUMMON_GUARDIAN_1);
                                        DoCast(me, SPELL_SUMMON_GUARDIAN_3);
                                    }
                                    break;
                                default:
                                    if (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
                                    {
                                        DoCast(me, SPELL_SUMMON_CHAMPION_2);
                                        DoCast(me, SPELL_SUMMON_CONSTRUCT_1);
                                        DoCast(me, SPELL_SUMMON_GUARDIAN_1);
                                    }
                                    else if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                                    {
                                        DoCast(me, SPELL_SUMMON_CONST_CHAMP);
                                        DoCast(me, SPELL_SUMMON_CHAMPION_2);
                                        DoCast(me, SPELL_SUMMON_CHAMPION_3);
                                        DoCast(me, SPELL_SUMMON_CHAMPION_4);
                                        DoCast(me, SPELL_SUMMON_GUARDIAN_1);
                                        DoCast(me, SPELL_SUMMON_GUARDIAN_3);
                                        DoCast(me, SPELL_SUMMON_CONSTRUCT_1);
                                        DoCast(me, SPELL_SUMMON_CONST_CHAMP);
                                    }
                                    break;
                            }
                            ++waveCount;
                            events.ScheduleEvent(waveCount < 2 ? EVENT_WAVE : EVENT_GROUND, urand(30000, 45000));
                            break;
                        case EVENT_GROUND:
                            TalkToMap(EMOTE_TELEPORT);
                            ++balconyCount;
                            DoCast(SPELL_TELEPORT_BACK);
                            events.ScheduleEvent(EVENT_BALCONY, 110000);
                            EnterPhaseGround();
                            break;
                    }
                }

                if (me->HasReactState(REACT_AGGRESSIVE))
                    DoMeleeAttackIfReady();
            }
        private:
            uint32 waveCount;
            uint32 balconyCount;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetNaxxramasAI<boss_nothAI>(creature);
        }
};

void AddSC_boss_noth()
{
    new boss_noth();
}
