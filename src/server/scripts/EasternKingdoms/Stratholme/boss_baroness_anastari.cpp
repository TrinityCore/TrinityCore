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

#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "stratholme.h"

enum Spells
{
    SPELL_BANSHEEWAIL           = 16565,
    SPELL_BANSHEECURSE          = 16867,
    SPELL_SILENCE               = 18327,
    SPELL_POSSESS               = 17244,    // The charm
    SPELL_POSSESSED             = 17246     // The damage buff
};

enum BaronessAnastariEvents
{
    EVENT_SPELL_BANSHEEWAIL     = 1,
    EVENT_SPELL_BANSHEECURSE    = 2,
    EVENT_SPELL_SILENCE         = 3,
    EVENT_SPELL_POSSESS         = 4,
    EVENT_INVISIBLE             = 5,
    EVENT_CHECK_POSSESSED       = 6
};


struct boss_baroness_anastari : public BossAI
{
    boss_baroness_anastari(Creature* creature) : BossAI(creature, TYPE_BARONESS) { }

    EventMap _events;
    ObjectGuid _possessedTargetGuid;

    void Reset() override
    {
        if (!me->IsVisible())
        {
            if (Player* possessedTarget = ObjectAccessor::FindConnectedPlayer(_possessedTargetGuid))
            {
                if (possessedTarget->IsAlive())
                {
                    possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESSED);
                    possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESS);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetVisible(true);
                }
            }
        }
        _events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SPELL_BANSHEEWAIL, 1s);
        _events.ScheduleEvent(EVENT_SPELL_BANSHEECURSE, 11s);
        _events.ScheduleEvent(EVENT_SPELL_SILENCE, 13s);
        _events.ScheduleEvent(EVENT_SPELL_POSSESS, 20s, 30s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SetData(TYPE_BARONESS, DONE);
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
            case EVENT_SPELL_BANSHEEWAIL:
                DoCastVictim(SPELL_BANSHEEWAIL);
                _events.ScheduleEvent(EVENT_SPELL_BANSHEEWAIL, 4s);
                break;
            case EVENT_SPELL_BANSHEECURSE:
                DoCastVictim(SPELL_BANSHEECURSE);
                _events.Repeat(18s);
                break;
            case EVENT_SPELL_SILENCE:
                DoCastVictim(SPELL_SILENCE);
                _events.ScheduleEvent(EVENT_SPELL_SILENCE, 13s);
                break;
            case EVENT_SPELL_POSSESS:
                if (Unit* possessTarget = SelectTarget(SELECT_TARGET_RANDOM, 1, 0, true, false))    // Random target to be possessed
                {
                    if (possessTarget->IsAlive())
                    {
                        me->CastStop();
                        DoCast(possessTarget, SPELL_POSSESS);
                        DoCast(possessTarget, SPELL_POSSESSED);
                        me->SetReactState(REACT_PASSIVE);
                        me->SetVisible(false);
                        _possessedTargetGuid = possessTarget->GetGUID();
                        _events.ScheduleEvent(EVENT_CHECK_POSSESSED, 0s);
                    }
                    else
                        _events.ScheduleEvent(EVENT_SPELL_POSSESS, 20s, 30s);
                }
                break;
            case EVENT_INVISIBLE:
                if (Player* possessedTarget = ObjectAccessor::FindConnectedPlayer(_possessedTargetGuid))    // When there's a possessed target
                {
                    possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESS);
                    possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESSED);
                    me->SetVisible(true);
                    possessedTarget->SetFullHealth();
                    me->SetReactState(REACT_AGGRESSIVE);
                    _events.ScheduleEvent(EVENT_SPELL_POSSESS, 20s, 30s);
                }
                break;
            case EVENT_CHECK_POSSESSED:
                if (!me->IsVisible())
                {
                    if (Player* possessedTarget = ObjectAccessor::FindConnectedPlayer(_possessedTargetGuid))
                    {
                        if (!possessedTarget->HasAura(SPELL_POSSESSED) || possessedTarget->GetHealthPct() <= 50)
                            _events.ScheduleEvent(EVENT_INVISIBLE, 0s);
                        else
                            _events.ScheduleEvent(EVENT_CHECK_POSSESSED, 1s);
                    }
                }
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_baroness_anastari()
{
    RegisterStratholmeCreatureAI(boss_baroness_anastari);
}
