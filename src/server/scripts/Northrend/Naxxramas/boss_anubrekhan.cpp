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

const Position GuardSummonPos = {3333.72f, -3476.30f, 287.1f, 6.2801f};

enum Texts
{
    SAY_AGGRO           = 0,
    SAY_GREET           = 1,
    SAY_SLAY            = 2,
    EMOTE_LOCUST        = 3,
    EMOTE_CRYPT         = 4,
    EMOTE_CORPSE_SCARAB = 5,
};

enum Events
{
    EVENT_IMPALE            = 1,
    EVENT_LOCUST            = 2,
    EVENT_SUMMON_GUARDIAN   = 3,
    EVENT_BERSERK           = 4,
};

enum Spells
{
    SPELL_IMPALE                    = 28783,
    SPELL_LOCUST_SWARM              = 28785,
    SPELL_SUMMON_CORPSE_SCARABS_PLR = 29105,
    SPELL_SUMMON_CORPSE_SCARABS_MOB = 28864,
    SPELL_BERSERK                   = 27680,
};

enum Achievement
{
    ACHIEV_TIMED_START_EVENT        = 9891,
};

enum Actions
{
    ACTION_INTRO    = 1,
};

class boss_anubrekhan : public CreatureScript
{
    public:
        boss_anubrekhan() : CreatureScript("boss_anubrekhan") { }

        struct boss_anubrekhanAI : public BossAI
        {
            boss_anubrekhanAI(Creature* creature) : BossAI(creature, DATA_ANUBREKHAN)
            {
                _introDone=false;
            }

            void Reset()
            {
                _Reset();

                if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
                {
                    Position pos;
                    pos = me->GetHomePosition();
                    pos.m_positionY -= 10.0f;
                    me->SummonCreature(NPC_CRYPT_GUARD, pos, TEMPSUMMON_CORPSE_DESPAWN, 5000);

                    pos = me->GetHomePosition();
                    pos.m_positionY += 10.0f;
                    me->SummonCreature(NPC_CRYPT_GUARD, pos, TEMPSUMMON_CORPSE_DESPAWN, 5000);
                }
            }

            void DoAction(int32 action)
            {
                switch (action)
                {
                    case ACTION_INTRO:
                        if (!_introDone)
                        {
                            TalkToMap(SAY_GREET);
                           _introDone = true;
                        }
                        break;
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                TalkToMap(SAY_AGGRO);
                events.ScheduleEvent(EVENT_IMPALE, urand(10000, 20000));
                events.ScheduleEvent(EVENT_LOCUST, 90000);
                events.ScheduleEvent(EVENT_BERSERK, 600000);

                if (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
                    events.ScheduleEvent(EVENT_SUMMON_GUARDIAN, urand(15000, 20000));
            }

            void KilledUnit(Unit* victim)
            {
                if (!(rand()%5))
                    if (victim->GetTypeId() == TYPEID_PLAYER)
                        victim->CastSpell(victim, SPELL_SUMMON_CORPSE_SCARABS_PLR, true, 0, 0, me->GetGUID());
                TalkToMap(EMOTE_CORPSE_SCARAB);
                TalkToMap(SAY_SLAY);
            }

            void SummonedCreatureDies(Creature* summon, Unit* /*killer*/)
            {
                switch (summon->GetEntry())
                {
                    case NPC_CRYPT_GUARD:
                        summon->CastSpell(summon, SPELL_SUMMON_CORPSE_SCARABS_MOB, true, 0, 0, me->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                if (instance)
                    instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
            }

            void UpdateAI(uint32 diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_IMPALE:
                            if (!me->HasAura(SPELL_LOCUST_SWARM))
                                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                    DoCast(target, SPELL_IMPALE);
                            events.ScheduleEvent(EVENT_IMPALE, urand(10000, 20000));
                            break;
                        case EVENT_LOCUST:
                            TalkToMap(EMOTE_LOCUST);
                            DoCast(me, SPELL_LOCUST_SWARM);
                            me->SummonCreature(NPC_CRYPT_GUARD, GuardSummonPos, TEMPSUMMON_CORPSE_DESPAWN, 5000);
                            events.ScheduleEvent(EVENT_LOCUST, 90000);
                            events.RescheduleEvent(EVENT_IMPALE, 20000);
                            break;
                        case EVENT_SUMMON_GUARDIAN:
                            TalkToMap(EMOTE_CRYPT);
                            me->SummonCreature(NPC_CRYPT_GUARD, GuardSummonPos, TEMPSUMMON_CORPSE_DESPAWN, 5000);
                            break;
                        case EVENT_BERSERK:
                            DoCastAOE(SPELL_BERSERK);
                            events.ScheduleEvent(EVENT_BERSERK, 600000);
                            break;
                    }
                }
                DoMeleeAttackIfReady();
            }

        private:
            bool _introDone;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetNaxxramasAI<boss_anubrekhanAI>(creature);
        }
};

class at_anubrekhan_intro : public AreaTriggerScript
{
    public:
        at_anubrekhan_intro() : AreaTriggerScript("at_anubrekhan_intro") { }

        bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/)
        {
            player->GetMap()->LoadGrid(GuardSummonPos.GetPositionX(), GuardSummonPos.GetPositionY());
            if (InstanceScript* instance = player->GetInstanceScript())
                if (instance->GetBossState(DATA_ANUBREKHAN) != DONE)
                    if (Creature* Anub = Unit::GetCreature(*player, instance->GetData64(DATA_ANUBREKHAN)))
                        Anub->AI()->DoAction(ACTION_INTRO);
            return true;
        }
};

void AddSC_boss_anubrekhan()
{
    new boss_anubrekhan();
    new at_anubrekhan_intro();
}
