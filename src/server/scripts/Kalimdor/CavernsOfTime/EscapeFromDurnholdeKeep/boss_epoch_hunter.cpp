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

/* Missing spawns pre-event, missing speech to be coordinated with rest of escort event  */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "old_hillsbrad.h"
#include "ScriptedCreature.h"

enum EpochHunterTexts
{
    SAY_ENTER                   = 0,
    SAY_AGGRO                   = 1,
    SAY_SLAY                    = 2,
    SAY_BREATH                  = 3,
    SAY_DEATH                   = 4
};

enum EpochHunterSpells
{
    SPELL_SAND_BREATH           = 31914,
    SPELL_IMPENDING_DEATH       = 31916,
    SPELL_MAGIC_DISRUPTION_AURA = 33834,
    SPELL_WING_BUFFET           = 31475
};

enum EpochHunterEvents
{
    EVENT_SAND_BREATH           = 1,
    EVENT_IMPENDING_DEATH,
    EVENT_MAGIC_DISRUPTION_AURA,
    EVENT_WING_BUFFET
};

// 18096 - Epoch Hunter
struct boss_epoch_hunter : public BossAI
{
    boss_epoch_hunter(Creature* creature) : BossAI(creature, DATA_EPOCH_HUNTER) { }

    void Reset() override
    {
        BossAI::Reset();
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        events.ScheduleEvent(EVENT_SAND_BREATH, 8s, 16s);
        events.ScheduleEvent(EVENT_IMPENDING_DEATH, 25s, 30s);
        events.ScheduleEvent(EVENT_MAGIC_DISRUPTION_AURA, 40s);
        events.ScheduleEvent(EVENT_WING_BUFFET, 35s);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);
        Talk(SAY_DEATH);

        instance->SetData(TYPE_THRALL_EVENT, OH_ESCORT_FINISHED);
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
                case EVENT_SAND_BREATH:
                    DoCastVictim(SPELL_SAND_BREATH);
                    Talk(SAY_BREATH);
                    events.Repeat(10s, 20s);
                    break;
                case EVENT_IMPENDING_DEATH:
                    DoCastVictim(SPELL_IMPENDING_DEATH);
                    events.Repeat(25s, 30s);
                    break;
                case EVENT_MAGIC_DISRUPTION_AURA:
                    DoCastSelf(SPELL_MAGIC_DISRUPTION_AURA);
                    events.Repeat(15s);
                    break;
                case EVENT_WING_BUFFET:
                    DoCastSelf(SPELL_WING_BUFFET);
                    events.Repeat(25s, 35s);
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

void AddSC_boss_epoch_hunter()
{
    RegisterOldHillsbradCreatureAI(boss_epoch_hunter);
}
