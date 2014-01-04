/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

enum Says
{
    SAY_AGGRO           = 0,
    SAY_GREET           = 1,
    SAY_SLAY            = 2
};

Position const GuardSummonPos = {3333.72f, -3476.30f, 287.1f, 6.2801f};

enum Events
{
    EVENT_IMPALE                    = 1,
    EVENT_LOCUST,
    EVENT_SPAWN_GUARDIAN_NORMAL,
    EVENT_BERSERK
};

enum Spells
{
    SPELL_IMPALE_10                 = 28783,
    SPELL_IMPALE_25                 = 56090,
    SPELL_LOCUST_SWARM_10           = 28785,
    SPELL_LOCUST_SWARM_25           = 54021,
    SPELL_SUMMON_CORPSE_SCARABS_PLR = 29105,    // This spawns 5 corpse scarabs on top of player
    SPELL_SUMMON_CORPSE_SCARABS_MOB = 28864,   // This spawns 10 corpse scarabs on top of dead guards
    SPELL_BERSERK                   = 27680
};

enum Misc
{
    ACHIEV_TIMED_START_EVENT                      = 9891
};

class boss_anubrekhan : public CreatureScript
{
public:
    boss_anubrekhan() : CreatureScript("boss_anubrekhan") { }

    CreatureAI* GetAI(Creature* creature) const OVERRIDE
    {
        return GetInstanceAI<boss_anubrekhanAI>(creature);
    }

    struct boss_anubrekhanAI : public BossAI
    {
        boss_anubrekhanAI(Creature* creature) : BossAI(creature, BOSS_ANUBREKHAN) { }

        bool hasTaunted;

        void Reset() OVERRIDE
        {
            _Reset();

            hasTaunted = false;

            if (GetDifficulty() == RAID_DIFFICULTY_25MAN_NORMAL)
            {
                Position pos;

                // respawn guard using home position,
                // otherwise, after a wipe, they respawn where boss was at wipe moment.
                pos = me->GetHomePosition();
                pos.m_positionY -= 10.0f;
                me->SummonCreature(NPC_CRYPT_GUARD, pos, TEMPSUMMON_CORPSE_DESPAWN);

                pos = me->GetHomePosition();
                pos.m_positionY += 10.0f;
                me->SummonCreature(NPC_CRYPT_GUARD, pos, TEMPSUMMON_CORPSE_DESPAWN);
            }
        }

        void KilledUnit(Unit* victim) OVERRIDE
        {
            /// Force the player to spawn corpse scarabs via spell, @todo Check percent chance for scarabs, 20% at the moment
            if (!(rand()%5))
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    victim->CastSpell(victim, SPELL_SUMMON_CORPSE_SCARABS_PLR, true, NULL, NULL, me->GetGUID());

            Talk(SAY_SLAY);
        }

        void JustDied(Unit* /*killer*/) OVERRIDE
        {
            _JustDied();

            // start achievement timer (kill Maexna within 20 min)
            instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
        }
        void EnterCombat(Unit* /*who*/) OVERRIDE
        {
            _EnterCombat();
            Talk(SAY_AGGRO);
            events.ScheduleEvent(EVENT_IMPALE, urand(10000, 20000));
            events.ScheduleEvent(EVENT_LOCUST, 90000);
            events.ScheduleEvent(EVENT_BERSERK, 600000);

            if (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
                events.ScheduleEvent(EVENT_SPAWN_GUARDIAN_NORMAL, urand(15000, 20000));
        }

        void MoveInLineOfSight(Unit* who) OVERRIDE

        {
            if (!hasTaunted && me->IsWithinDistInMap(who, 60.0f) && who->GetTypeId() == TYPEID_PLAYER)
            {
                Talk(SAY_GREET);
                hasTaunted = true;
            }
            ScriptedAI::MoveInLineOfSight(who);
        }

        void SummonedCreatureDespawn(Creature* summon) OVERRIDE
        {
            BossAI::SummonedCreatureDespawn(summon);

            // check if it is an actual killed guard
            if (!me->IsAlive() || summon->IsAlive() || summon->GetEntry() != NPC_CRYPT_GUARD)
                return;

            summon->CastSpell(summon, SPELL_SUMMON_CORPSE_SCARABS_MOB, true, NULL, NULL, me->GetGUID());
        }

        void UpdateAI(uint32 diff) OVERRIDE
        {
            if (!UpdateVictim() || !CheckInRoom())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_IMPALE:
                        //Cast Impale on a random target
                        //Do NOT cast it when we are afflicted by locust swarm
                        if (!me->HasAura(RAID_MODE(SPELL_LOCUST_SWARM_10, SPELL_LOCUST_SWARM_25)))
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                                DoCast(target, RAID_MODE(SPELL_IMPALE_10, SPELL_IMPALE_25));
                        events.ScheduleEvent(EVENT_IMPALE, urand(10000, 20000));
                        break;
                    case EVENT_LOCUST:
                        /// @todo Add Text
                        DoCast(me, RAID_MODE(SPELL_LOCUST_SWARM_10, SPELL_LOCUST_SWARM_25));
                        DoSummon(NPC_CRYPT_GUARD, GuardSummonPos, 0, TEMPSUMMON_CORPSE_DESPAWN);
                        events.ScheduleEvent(EVENT_LOCUST, 90000);
                        break;
                    case EVENT_SPAWN_GUARDIAN_NORMAL:
                        /// @todo Add Text
                        DoSummon(NPC_CRYPT_GUARD, GuardSummonPos, 0, TEMPSUMMON_CORPSE_DESPAWN);
                        break;
                    case EVENT_BERSERK:
                        DoCast(me, SPELL_BERSERK, true);
                        events.ScheduleEvent(EVENT_BERSERK, 600000);
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_anubrekhan()
{
    new boss_anubrekhan();
}
