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

/*
 * Timers requires to be revisited
 * Devour is NYI
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "temple_of_ahnqiraj.h"

enum BugTrioSpells
{
    // Kri
    SPELL_THRASH                   = 3391,
    SPELL_CLEAVE                   = 40504,
    SPELL_TOXIC_VOLLEY             = 25812,
    SPELL_SUMMON_POISON_CLOUD      = 26590,

    // Vem
    SPELL_CHARGE                   = 26561,
    SPELL_KNOCK_AWAY               = 18670,
    SPELL_KNOCKDOWN                = 19128,
    SPELL_VENGEANCE                = 25790,

    // Yauj
    SPELL_GREAT_HEAL               = 25807,
    SPELL_FEAR                     = 26580,
    SPELL_RAVAGE                   = 3242,
    SPELL_DISPEL                   = 25808,
    SPELL_SUMMON_YAUJ_BROOD        = 25789,

    // Shared
    SPELL_DESPAWN_BROOD            = 25792,
    SPELL_BLOODY_DEATH             = 25770      // NYI
};

enum BugTrioEvents
{
    // Kri
    EVENT_THRASH                   = 1,
    EVENT_CLEAVE,
    EVENT_TOXIC_VOLLEY,

    // Vem
    EVENT_VEM_CHARGE,
    EVENT_KNOCK_AWAY,
    EVENT_KNOCKDOWN,

    // Yauj
    EVENT_GREAT_HEAL,
    EVENT_FEAR,
    EVENT_RAVAGE,
    EVENT_DISPEL
};

static void RespawnDeadBugs(InstanceScript* instance)
{
    for (uint32 type : { DATA_KRI, DATA_VEM, DATA_YAUJ })
        if (Creature* bug = instance->GetCreature(type))
            if (bug->isDead())
                bug->DespawnOrUnsummon(1ms, 1s);
}

// 15511 - Lord Kri
struct boss_kri : public BossAI
{
    boss_kri(Creature* creature) : BossAI(creature, DATA_BUG_TRIO) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_THRASH, 5s, 10s);
        events.ScheduleEvent(EVENT_CLEAVE, 5s, 15s);
        events.ScheduleEvent(EVENT_TOXIC_VOLLEY, 15s, 25s);
    }

    /// @todo: This should be in BaseAI (needs to be created to implement Devour)
    void JustReachedHome() override
    {
        _JustReachedHome();
        DoCastSelf(SPELL_DESPAWN_BROOD, true);
        RespawnDeadBugs(instance);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (instance->GetData(DATA_BUG_TRIO_DEATH) < 2)
            me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);

        instance->SetData(DATA_BUG_TRIO_DEATH, 1);

        DoCastSelf(SPELL_SUMMON_POISON_CLOUD, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_THRASH:
                    DoCastSelf(SPELL_THRASH);
                    events.Repeat(5s, 15s);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.Repeat(5s, 15s);
                    break;
                case EVENT_TOXIC_VOLLEY:
                    DoCastSelf(SPELL_TOXIC_VOLLEY);
                    events.Repeat(5s, 20s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

// 15544 - Vem
struct boss_vem : public BossAI
{
    boss_vem(Creature* creature) : BossAI(creature, DATA_BUG_TRIO) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_VEM_CHARGE, 15s, 25s);
        events.ScheduleEvent(EVENT_KNOCK_AWAY, 20s, 30s);
        events.ScheduleEvent(EVENT_KNOCKDOWN, 20s, 30s);
    }

    /// @todo: This should be in BaseAI (needs to be created to implement Devour)
    void JustReachedHome() override
    {
        _JustReachedHome();
        DoCastSelf(SPELL_DESPAWN_BROOD, true);
        RespawnDeadBugs(instance);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (instance->GetData(DATA_BUG_TRIO_DEATH) < 2)
            me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);

        instance->SetData(DATA_BUG_TRIO_DEATH, 1);

        DoCastSelf(SPELL_VENGEANCE, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_VEM_CHARGE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_CHARGE);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_KNOCK_AWAY:
                    DoCastVictim(SPELL_KNOCK_AWAY);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_KNOCKDOWN:
                    DoCastVictim(SPELL_KNOCKDOWN);
                    events.Repeat(10s, 20s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

// 15543 - Princess Yauj
struct boss_yauj : public BossAI
{
    boss_yauj(Creature* creature) : BossAI(creature, DATA_BUG_TRIO) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_GREAT_HEAL, 5s, 10s);
        events.ScheduleEvent(EVENT_FEAR, 10s, 15s);
        events.ScheduleEvent(EVENT_RAVAGE, 10s, 20s);
        events.ScheduleEvent(EVENT_DISPEL, 10s, 30s);
    }

    void JustReachedHome() override
    {
        _JustReachedHome();
        RespawnDeadBugs(instance);
    }

    void JustDied(Unit* /*killer*/) override
    {
        if (instance->GetData(DATA_BUG_TRIO_DEATH) < 2)
            me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
        instance->SetData(DATA_BUG_TRIO_DEATH, 1);

        DoCastSelf(SPELL_SUMMON_YAUJ_BROOD, true);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GREAT_HEAL:
                    if (Unit* target = DoSelectLowestHpFriendly(250.0f))
                        DoCast(target, SPELL_GREAT_HEAL);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_FEAR:
                    DoCastSelf(SPELL_FEAR);
                    events.Repeat(20s, 30s);
                    break;
                case EVENT_RAVAGE:
                    DoCastVictim(SPELL_RAVAGE);
                    events.Repeat(10s, 15s);
                    break;
                case EVENT_DISPEL:
                    DoCastSelf(SPELL_DISPEL);
                    events.Repeat(10s, 15s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_bug_trio()
{
    RegisterAQ40CreatureAI(boss_kri);
    RegisterAQ40CreatureAI(boss_vem);
    RegisterAQ40CreatureAI(boss_yauj);
}
