/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "blackrock_spire.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"

enum Spells
{
    SPELL_BLASTWAVE                 = 11130,
    SPELL_SHOUT                     = 23511,
    SPELL_CLEAVE                    = 20691,
    SPELL_KNOCKAWAY                 = 20686
};

enum Events
{
    EVENT_BLAST_WAVE                = 1,
    EVENT_SHOUT                     = 2,
    EVENT_CLEAVE                    = 3,
    EVENT_KNOCK_AWAY                = 4
};

enum Adds
{
    NPC_SPIRESTONE_WARLORD          = 9216,
    NPC_SMOLDERTHORN_BERSERKER      = 9268
};

const Position SummonLocation1 = { -39.355f, -513.456f, 88.472f, 4.679f };
const Position SummonLocation2 = { -49.875f, -511.896f, 88.195f, 4.613f };

class boss_overlord_wyrmthalak : public CreatureScript
{
public:
    boss_overlord_wyrmthalak() : CreatureScript("boss_overlord_wyrmthalak") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackrockSpireAI<boss_overlordwyrmthalakAI>(creature);
    }

    struct boss_overlordwyrmthalakAI : public BossAI
    {
        boss_overlordwyrmthalakAI(Creature* creature) : BossAI(creature, DATA_OVERLORD_WYRMTHALAK)
        {
            Initialize();
        }

        void Initialize()
        {
            Summoned = false;
        }

        bool Summoned;

        void Reset() override
        {
            _Reset();
            Initialize();
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            _JustEngagedWith();
            events.ScheduleEvent(EVENT_BLAST_WAVE, 20s);
            events.ScheduleEvent(EVENT_SHOUT, 2s);
            events.ScheduleEvent(EVENT_CLEAVE, 6s);
            events.ScheduleEvent(EVENT_KNOCK_AWAY, 12s);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _JustDied();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (!Summoned && HealthBelowPct(51))
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                {
                    if (Creature* warlord = me->SummonCreature(NPC_SPIRESTONE_WARLORD, SummonLocation1, TEMPSUMMON_TIMED_DESPAWN, 300 * IN_MILLISECONDS))
                        warlord->AI()->AttackStart(target);
                    if (Creature* berserker = me->SummonCreature(NPC_SMOLDERTHORN_BERSERKER, SummonLocation2, TEMPSUMMON_TIMED_DESPAWN, 300 * IN_MILLISECONDS))
                        berserker->AI()->AttackStart(target);
                    Summoned = true;
                }
            }

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_BLAST_WAVE:
                        DoCastVictim(SPELL_BLASTWAVE);
                        events.ScheduleEvent(EVENT_BLAST_WAVE, 20s);
                        break;
                    case EVENT_SHOUT:
                        DoCastVictim(SPELL_SHOUT);
                        events.ScheduleEvent(EVENT_SHOUT, 10s);
                        break;
                    case EVENT_CLEAVE:
                        DoCastVictim(SPELL_CLEAVE);
                        events.ScheduleEvent(EVENT_CLEAVE, 7s);
                        break;
                    case EVENT_KNOCK_AWAY:
                        DoCastVictim(SPELL_KNOCKAWAY);
                        events.ScheduleEvent(EVENT_KNOCK_AWAY, 14s);
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
            DoMeleeAttackIfReady();
        }
    };
};

void AddSC_boss_overlordwyrmthalak()
{
    new boss_overlord_wyrmthalak();
}
