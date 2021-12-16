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
#include "nexus.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_BATTLE_SHOUT           = 31403,
    SPELL_CHARGE                 = 60067,
    SPELL_FRIGHTENING_SHOUT      = 19134,
    SPELL_WHIRLWIND              = 38618,
    SPELL_FROZEN_PRISON          = 47543
};

enum Yells
{
    SAY_AGGRO                    = 0,
    SAY_KILL                     = 1,
    SAY_DEATH                    = 2
};

enum Events
{
    EVENT_CHARGE_COMMANDER      = 1,
    EVENT_WHIRLWIND,
    EVENT_FRIGHTENING_SHOUT
};

struct boss_nexus_commanders : public BossAI
{
    boss_nexus_commanders(Creature* creature) : BossAI(creature, DATA_COMMANDER) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        me->RemoveAurasDueToSpell(SPELL_FROZEN_PRISON);
        DoCast(me, SPELL_BATTLE_SHOUT);

        events.ScheduleEvent(EVENT_CHARGE_COMMANDER, 3s, 4s);
        events.ScheduleEvent(EVENT_WHIRLWIND, 6s, 8s);
        events.ScheduleEvent(EVENT_FRIGHTENING_SHOUT, 13s, 15s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_CHARGE_COMMANDER:
                if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0, 100.0f, true))
                    DoCast(target, SPELL_CHARGE);
                events.ScheduleEvent(EVENT_CHARGE_COMMANDER, 11s, 15s);
                break;
            case EVENT_WHIRLWIND:
                DoCast(me, SPELL_WHIRLWIND);
                events.ScheduleEvent(EVENT_WHIRLWIND, 19500ms, 25s);
                break;
            case EVENT_FRIGHTENING_SHOUT:
                DoCastAOE(SPELL_FRIGHTENING_SHOUT);
                events.ScheduleEvent(EVENT_FRIGHTENING_SHOUT, 45s, 55s);
                break;
            default:
                break;
        }
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_KILL);
    }
};

void AddSC_boss_nexus_commanders()
{
    RegisterNexusCreatureAI(boss_nexus_commanders);
}
