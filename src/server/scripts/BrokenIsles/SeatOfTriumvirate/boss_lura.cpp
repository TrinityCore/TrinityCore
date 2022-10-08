/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "seat_of_triumvirate.h"

enum Spells
{
    SPELL_DEEP_ROOTS = 165950,

    //Nightmare Breath
    SPELL_NIGHTMARE_BREATH_DAMAGE = 204667,

    //Shattered Earth
    SPELL_SHATTERED_EARTH_DAMAGE = 204666,

    //Strangling Roots
    SPELL_STRANGLING_ROOTS_TARGET = 204574,
    SPELL_STRANGLING_ROOTS_MISSILE = 199051,
    SPELL_STRANGLING_ROOTS_SUMMON = 199060,
    SPELL_STRANGLING_ROOTS_AURA = 199063,
    SPELL_STRANGLING_ROOTS_AT = 199067,
    SPELL_STRANGLING_ROOTS_VISUAL = 100991,

    //Crushing Grip
    SPELL_CRUSHING_GRIP_CAST = 204611,
    SPELL_CRUSHING_GRIP_VEHICLE = 204613,
    SPELL_CRUSHING_GRIP_THROW = 204658
};

enum Talks
{
    SAY_PULL = 0,
    SAY_ROOT = 1,
    SAY_BREATH = 2,
    SAY_DIE = 3,
};


// 122314
struct boss_lura : public BossAI
{
    boss_lura(Creature* creature) : BossAI(creature, DATA_LURA) { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (me->GetDistance(who) < 20.0f)
        {
            me->RemoveUnitFlag(UnitFlags(UNIT_FLAG_UNK_6 | UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_UNK_15 | UNIT_FLAG_STUNNED));
            me->RemoveAurasDueToSpell(SPELL_DEEP_ROOTS);
        }
    }

    void ScheduleTasks() override
    {
        events.ScheduleEvent(SPELL_STRANGLING_ROOTS_TARGET, 15s);
        events.ScheduleEvent(SPELL_SHATTERED_EARTH_DAMAGE, 5s);
        events.ScheduleEvent(SPELL_NIGHTMARE_BREATH_DAMAGE, 10s);
        events.ScheduleEvent(SPELL_CRUSHING_GRIP_CAST, 20s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_SHATTERED_EARTH_DAMAGE:
        {
            DoCastSelf(SPELL_SHATTERED_EARTH_DAMAGE);
            events.Repeat(40s);
            break;
        }
        case SPELL_CRUSHING_GRIP_CAST:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
                DoCast(target, SPELL_CRUSHING_GRIP_CAST);
            events.Repeat(30s);
            break;
        }
        case SPELL_STRANGLING_ROOTS_TARGET:
        {
            DoCastSelf(SPELL_STRANGLING_ROOTS_TARGET);
            Talk(SAY_ROOT);
            events.Repeat(25s);
            break;
        }
        case SPELL_NIGHTMARE_BREATH_DAMAGE:
        {
            if (Unit* target = SelectTarget(SELECT_TARGET_TOPAGGRO))
            {
                DoCast(target, SPELL_NIGHTMARE_BREATH_DAMAGE);
                Talk(SAY_BREATH);
            }
            events.Repeat(30s);
            break;
        }
        }
    }
};

void AddSC_boss_lura()
{
    RegisterCreatureAI(boss_lura);
}
