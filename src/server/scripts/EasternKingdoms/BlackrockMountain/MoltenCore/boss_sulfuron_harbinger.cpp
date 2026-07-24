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
#include "Containers.h"
#include "molten_core.h"
#include "ScriptedCreature.h"

enum SulfuronSpells
{
    // Sulfuron Harbringer
    SPELL_DEMORALIZING_SHOUT    = 19778,
    SPELL_INSPIRE               = 19779,
    SPELL_HAND_OF_RAGNAROS      = 19780,
    SPELL_FLAME_SPEAR           = 19781,
    SPELL_THROW                 = 19785,

    // Flamewaker Priest
    SPELL_DARK_MENDING          = 19775,
    SPELL_SHADOW_WORD_PAIN      = 19776,
    SPELL_DARK_STRIKE           = 19777,
    SPELL_IMMOLATE              = 20294
};

enum SulfuronEvents
{
    // Sulfuron Harbringer
    EVENT_DEMORALIZING_SHOUT    = 1,
    EVENT_INSPIRE,
    EVENT_HAND_OF_RAGNAROS,
    EVENT_FLAME_SPEAR,
    EVENT_THROW,

    // Flamewaker Priest
    EVENT_DARK_MENDING,
    EVENT_SHADOW_WORD_PAIN,
    EVENT_DARK_STRIKE,
    EVENT_IMMOLATE
};

// 12098 - Sulfuron Harbinger
struct boss_sulfuron : public BossAI
{
    boss_sulfuron(Creature* creature) : BossAI(creature, BOSS_SULFURON_HARBINGER) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        events.ScheduleEvent(EVENT_DEMORALIZING_SHOUT, 10s, 15s);
        events.ScheduleEvent(EVENT_INSPIRE, 5s, 10s);
        events.ScheduleEvent(EVENT_HAND_OF_RAGNAROS, 5s, 10s);
        events.ScheduleEvent(EVENT_FLAME_SPEAR, 5s, 15s);
        events.ScheduleEvent(EVENT_THROW, 0s);
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
                case EVENT_DEMORALIZING_SHOUT:
                    DoCastSelf(SPELL_DEMORALIZING_SHOUT);
                    events.Repeat(25s, 35s);
                    break;
                case EVENT_INSPIRE:
                {
                    std::list<Creature*> healers = DoFindFriendlyMissingBuff(45.0f, SPELL_INSPIRE);
                    if (!healers.empty())
                        DoCast(Trinity::Containers::SelectRandomContainerElement(healers), SPELL_INSPIRE);

                    events.Repeat(15s, 20s);
                    break;
                }
                case EVENT_HAND_OF_RAGNAROS:
                    DoCastSelf(SPELL_HAND_OF_RAGNAROS);
                    events.Repeat(10s, 25s);
                    break;
                case EVENT_FLAME_SPEAR:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_FLAME_SPEAR);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_THROW:
                    DoCastVictim(SPELL_THROW);
                    events.Repeat(2s);
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

// 11662 - Flamewaker Priest
struct npc_flamewaker_priest : public ScriptedAI
{
    npc_flamewaker_priest(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_DARK_MENDING, 15s, 20s);
        _events.ScheduleEvent(EVENT_SHADOW_WORD_PAIN, 4s, 6s);
        _events.ScheduleEvent(EVENT_DARK_STRIKE, 3s, 6s);
        _events.ScheduleEvent(EVENT_IMMOLATE, 3s, 6s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_DARK_MENDING:
                    if (Unit* target = DoSelectLowestHpFriendly(60.0f))
                        DoCast(target, SPELL_DARK_MENDING);
                    _events.Repeat(15s, 20s);
                    break;
                case EVENT_SHADOW_WORD_PAIN:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true, true, -SPELL_SHADOW_WORD_PAIN))
                        DoCast(target, SPELL_SHADOW_WORD_PAIN);
                    _events.Repeat(3s, 10s);
                    break;
                case EVENT_DARK_STRIKE:
                    DoCastVictim(SPELL_DARK_STRIKE);
                    _events.Repeat(5s, 7s);
                    break;
                case EVENT_IMMOLATE:
                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 0.0f, true, true, -SPELL_IMMOLATE))
                        DoCast(target, SPELL_IMMOLATE);
                    _events.Repeat(4s, 8s);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

void AddSC_boss_sulfuron()
{
    RegisterMoltenCoreCreatureAI(boss_sulfuron);
    RegisterMoltenCoreCreatureAI(npc_flamewaker_priest);
}
