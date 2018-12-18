/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "grim_batol.h"

enum TwilightBeguiler
{
    // Events
    EVENT_BEGUILE = 1,
    EVENT_MOVE_TO_HOME_POSITION,
    EVENT_ENSLAVE_GRONN_COSMETIC,
    EVENT_DECEITFUL_BLAST,
    EVENT_CHAINED_MIND,

    // Phases
    PHASE_COSMETIC                      = 1,
    PHASE_COMBAT                        = 2,

    // Spells
    SPELL_GRONN_KNOCKBACK_COSMETIC      = 76138,
    SPELL_BEGUILE                       = 76151,
    SPELL_ENSLAVE_GRONN_COSMETIC_RIGHT  = 74867,
    SPELL_ENSLAVE_GRONN_COSMETIC_LEFT   = 74884,
    SPELL_DECEITFUL_BLAST               = 76715,
    SPELL_CHAINED_MIND                  = 76711
};

struct npc_grim_batol_twilight_beguiler : public ScriptedAI
{
    npc_grim_batol_twilight_beguiler(Creature* creature) : ScriptedAI(creature) { }

    void Reset()
    {
        _events.Reset();
        _events.SetPhase(PHASE_COSMETIC);
        _events.ScheduleEvent(EVENT_ENSLAVE_GRONN_COSMETIC, 1s, 0, PHASE_COSMETIC);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.SetPhase(PHASE_COMBAT);
        _events.ScheduleEvent(EVENT_DECEITFUL_BLAST, 7s, 0, PHASE_COMBAT);
        _events.ScheduleEvent(EVENT_CHAINED_MIND, 7s, 15s, 0, PHASE_COMBAT);
        me->InterruptNonMeleeSpells(true);
    }

    void SpellHit(Unit* caster, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_GRONN_KNOCKBACK_COSMETIC)
        {
            _events.ScheduleEvent(EVENT_BEGUILE, 4s, 0, PHASE_COSMETIC);
            _events.ScheduleEvent(EVENT_MOVE_TO_HOME_POSITION, 7s + 600ms, 0, PHASE_COSMETIC);
            _events.ScheduleEvent(EVENT_ENSLAVE_GRONN_COSMETIC, 7s + 600ms, 0, PHASE_COSMETIC);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !_events.IsInPhase(PHASE_COSMETIC))
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) && !_events.IsInPhase(PHASE_COSMETIC))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_BEGUILE:
                    DoCastSelf(SPELL_BEGUILE);
                    break;
                case EVENT_MOVE_TO_HOME_POSITION:
                    me->GetMotionMaster()->MoveTargetedHome();
                    break;
                case EVENT_ENSLAVE_GRONN_COSMETIC:
                    if (Creature* gronn = me->FindNearestCreature(NPC_ENSLAVED_GRONN_BRUTE, 30.0f, true))
                    {
                        Position pos = gronn->GetHomePosition();
                        pos.SetOrientation(pos.GetOrientation() + (float)M_PI / 1.5f);

                        if (pos.HasInLine(&me->GetHomePosition(), 15.0f))
                            DoCastSelf(SPELL_ENSLAVE_GRONN_COSMETIC_LEFT);
                        else
                        {
                            pos = gronn->GetHomePosition();
                            pos.SetOrientation(pos.GetOrientation() - (float)M_PI / 1.5f);
                            if (pos.HasInLine(&me->GetHomePosition(), 15.0f))
                                DoCastSelf(SPELL_ENSLAVE_GRONN_COSMETIC_RIGHT);
                        }
                    }
                    break;
                case EVENT_DECEITFUL_BLAST:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 25.0f, true, 0))
                        DoCast(target, SPELL_DECEITFUL_BLAST);

                    if (_events.GetTimeUntilEvent(EVENT_CHAINED_MIND) > 4 * IN_MILLISECONDS)
                        _events.Repeat(1s, 3s);
                    else
                        _events.Repeat(11s, 12s);
                    break;
                case EVENT_CHAINED_MIND:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 25.0f, true, 0))
                        DoCast(target, SPELL_CHAINED_MIND);
                    _events.Repeat(18s, 27s);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

void AddSC_grim_batol()
{
    RegisterGrimBatolCreatureAI(npc_grim_batol_twilight_beguiler);
}