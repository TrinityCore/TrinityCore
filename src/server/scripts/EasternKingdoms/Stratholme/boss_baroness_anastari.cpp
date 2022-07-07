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
    SPELL_POSSESS               = 17244,    // the charm on player
    SPELL_POSSESSED             = 17246,    // the damage debuff on player
    SPELL_POSSESS_INV           = 17250     // baroness becomes invisible while possessing a target
};

enum BaronessAnastariEvents
{
    EVENT_SPELL_BANSHEEWAIL     = 1,
    EVENT_SPELL_BANSHEECURSE    = 2,
    EVENT_SPELL_SILENCE         = 3,
    EVENT_SPELL_POSSESS         = 4,
    EVENT_CHECK_POSSESSED       = 5
};

struct boss_baroness_anastari : public BossAI
{
    boss_baroness_anastari(Creature* creature) : BossAI(creature, TYPE_BARONESS) { }

    ObjectGuid _possessedTargetGuid;

    void Reset() override
    {
        _possessedTargetGuid.Clear();

        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_POSSESS);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_POSSESSED);
        me->RemoveAurasDueToSpell(SPELL_POSSESS_INV);

        events.Reset();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        events.ScheduleEvent(EVENT_SPELL_BANSHEEWAIL, 1s);
        events.ScheduleEvent(EVENT_SPELL_BANSHEECURSE, 11s);
        events.ScheduleEvent(EVENT_SPELL_SILENCE, 13s);
        events.ScheduleEvent(EVENT_SPELL_POSSESS, 20s, 30s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        // needed until crystals implemented,
        // see line 305 instance_stratholme.cpp
        instance->SetData(TYPE_BARONESS, IN_PROGRESS);
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
                case EVENT_SPELL_BANSHEEWAIL:
                    DoCastVictim(SPELL_BANSHEEWAIL);
                    events.Repeat(4s);
                    break;
                case EVENT_SPELL_BANSHEECURSE:
                    DoCastVictim(SPELL_BANSHEECURSE);
                    events.Repeat(18s);
                    break;
                case EVENT_SPELL_SILENCE:
                    DoCastVictim(SPELL_SILENCE);
                    events.Repeat(13s);
                    break;
                case EVENT_SPELL_POSSESS:
                    if (Unit* possessTarget = SelectTarget(SelectTargetMethod::Random, 1, 0, true, false))
                    {
                        DoCast(possessTarget, SPELL_POSSESS, true);
                        DoCast(possessTarget, SPELL_POSSESSED, true);
                        DoCastSelf(SPELL_POSSESS_INV, true);
                        _possessedTargetGuid = possessTarget->GetGUID();
                        events.ScheduleEvent(EVENT_CHECK_POSSESSED, 0s);
                    }
                    else
                        events.Repeat(20s, 30s);
                    break;
                case EVENT_CHECK_POSSESSED:
                    if (Player* possessedTarget = ObjectAccessor::GetPlayer(*me, _possessedTargetGuid))
                    {
                        if (!possessedTarget->HasAura(SPELL_POSSESSED) || possessedTarget->HealthBelowPct(50))
                        {
                            possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESS);
                            possessedTarget->RemoveAurasDueToSpell(SPELL_POSSESSED);
                            me->RemoveAurasDueToSpell(SPELL_POSSESS_INV);
                            _possessedTargetGuid.Clear();
                            events.ScheduleEvent(EVENT_SPELL_POSSESS, 20s, 30s);
                            events.CancelEvent(EVENT_CHECK_POSSESSED);
                        }
                        else
                            events.Repeat(1s);
                    }
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_baroness_anastari()
{
    RegisterStratholmeCreatureAI(boss_baroness_anastari);
}
