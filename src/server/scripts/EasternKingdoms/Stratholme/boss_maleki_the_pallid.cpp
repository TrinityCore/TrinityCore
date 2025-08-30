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
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum MalekiSpells
{
    SPELL_FROST_ARMOR   = 12556,
    SPELL_FROSTBOLT     = 17503,
    SPELL_DRAIN_LIFE    = 17238,
    SPELL_DRAIN_MANA    = 17243,
    SPELL_ICE_TOMB      = 16869
};

enum MalekiEvents
{
    EVENT_FROSTBOLT     = 1,
    EVENT_DRAIN_LIFE,
    EVENT_DRAIN_MANA,
    EVENT_ICE_TOMB
};

// 10438 - Maleki the Pallid
struct boss_maleki_the_pallid : public ScriptedAI
{
    boss_maleki_the_pallid(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void Reset() override
    {
        _events.Reset();
        DoCastSelf(SPELL_FROST_ARMOR);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_FROSTBOLT, 0s, 8s);
        _events.ScheduleEvent(EVENT_DRAIN_LIFE, 20s, 25s);
        _events.ScheduleEvent(EVENT_DRAIN_MANA, 15s, 25s);
        _events.ScheduleEvent(EVENT_ICE_TOMB, 10s, 20s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _instance->SetData(TYPE_PALLID, IN_PROGRESS);
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
                case EVENT_FROSTBOLT:
                    DoCastVictim(SPELL_FROSTBOLT);
                    _events.Repeat(2s, 8s);
                    break;
                case EVENT_DRAIN_LIFE:
                    DoCastVictim(SPELL_DRAIN_LIFE);
                    _events.Repeat(20s, 30s);
                    break;
                case EVENT_DRAIN_MANA:
                {
                    Unit* target = me->GetVictim();
                    if (target && target->GetPowerType() == POWER_MANA)
                        DoCast(target, SPELL_DRAIN_MANA);
                    _events.Repeat(15s, 20s);
                    break;
                }
                case EVENT_ICE_TOMB:
                    DoCastVictim(SPELL_ICE_TOMB);
                    _events.Repeat(15s, 25s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

void AddSC_boss_maleki_the_pallid()
{
    RegisterStratholmeCreatureAI(boss_maleki_the_pallid);
}
