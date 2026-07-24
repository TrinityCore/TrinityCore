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
#include "molten_core.h"
#include "ScriptedCreature.h"

enum GehennasSpells
{
    SPELL_GEHENNAS_CURSE       = 19716,
    SPELL_RAIN_OF_FIRE         = 19717,
    SPELL_SHADOW_BOLT_VICTIM   = 19728,
    SPELL_SHADOW_BOLT_RANDOM   = 19729
};

enum GehennasEvents
{
    EVENT_GEHENNAS_CURSE       = 1,
    EVENT_RAIN_OF_FIRE,
    EVENT_SHADOW_BOLT_VICTIM,
    EVENT_SHADOW_BOLT_RANDOM
};

// 12259 - Gehennas
struct boss_gehennas : public BossAI
{
    boss_gehennas(Creature* creature) : BossAI(creature, BOSS_GEHENNAS) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_GEHENNAS_CURSE, 5s, 10s);
        events.ScheduleEvent(EVENT_RAIN_OF_FIRE, 5s, 10s);
        events.ScheduleEvent(EVENT_SHADOW_BOLT_VICTIM, 3s, 6s);
        events.ScheduleEvent(EVENT_SHADOW_BOLT_RANDOM, 3s, 6s);
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
                case EVENT_GEHENNAS_CURSE:
                    DoCastSelf(SPELL_GEHENNAS_CURSE);
                    events.Repeat(25s, 30s);
                    break;
                case EVENT_RAIN_OF_FIRE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_RAIN_OF_FIRE);
                    events.Repeat(6s, 12s);
                    break;
                case EVENT_SHADOW_BOLT_VICTIM:
                    DoCastVictim(SPELL_SHADOW_BOLT_VICTIM);
                    events.Repeat(3s, 6s);
                    break;
                case EVENT_SHADOW_BOLT_RANDOM:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_SHADOW_BOLT_RANDOM);
                    events.Repeat(3s, 6s);
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

void AddSC_boss_gehennas()
{
    RegisterMoltenCoreCreatureAI(boss_gehennas);
}
