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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "CombatAI.h"
#include "MotionMaster.h"
#include "InstanceScript.h"
#include "Player.h"
#include "ObjectAccessor.h"
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

    void Reset() override
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

    void SpellHit(Unit* /*caster*/, SpellInfo const* spell) override
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
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 25.0f, true))
                        DoCast(target, SPELL_DECEITFUL_BLAST);

                    if (_events.GetTimeUntilEvent(EVENT_CHAINED_MIND) > 4 * IN_MILLISECONDS)
                        _events.Repeat(1s, 3s);
                    else
                        _events.Repeat(11s, 12s);
                    break;
                case EVENT_CHAINED_MIND:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 25.0f, true))
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

enum BatteredRedDrake
{
    SPELL_NET                               = 79377,
    SPELL_NET_SCRIPT                        = 79374,
    SPELL_BOMBING_RUN_PROTECTION_TRIGGER    = 80364,
    SPELL_GEAR_SCALING_TRIGGER              = 73917,
    SPELL_EJECT_ALL_PASSENGERS              = 68576,

    ANIM_KIT_ID_LIFTOFF                     = 1009,

    EVENT_SET_HOVERING                      = 1,
    EVENT_PREPARE_BOMBARDMENT,
    EVENT_FLY_BOMBARDMENT,
    EVENT_FLY_AWAY,

    SAY_WHISPER_BOMBARDMENT                 = 0,
    SAY_ANNOUNCE_BOMBARDMENT                = 1,

    SPLINE_CHAIN_BOMBARDMENT                = 1,
    SPLINE_CHAIN_ESCAPE_BOMBARDMENT         = 2,

    POINT_EJECT_PLAYER                      = 1
};

struct npc_grim_batol_battered_red_drake: public VehicleAI
{
    npc_grim_batol_battered_red_drake(Creature* creature) : VehicleAI(creature), _instance(me->GetInstanceScript()) { }

    void JustAppeared() override
    {
        if (_instance->GetData(DATA_BATTERED_RED_DRAKE_STATE) != DONE)
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            DoCastSelf(SPELL_NET);
        }
    }

    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
    {
        if (summon->GetEntry() == NPC_NET)
        {
            me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->RemoveAurasDueToSpell(SPELL_NET);
            DoCastSelf(SPELL_BOMBING_RUN_PROTECTION_TRIGGER);

            // Yes, this is stupid. Don't argue. Confirmed by 2012 sniffs.
            me->SetDisableGravity(true, false, false);
            summon->CastSpell(summon, SPELL_NET_SCRIPT);
            summon->DespawnOrUnsummon(3s);
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != SPLINE_CHAIN_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_EJECT_PLAYER:
                DoCastSelf(SPELL_EJECT_ALL_PASSENGERS);
                _events.ScheduleEvent(EVENT_FLY_AWAY, 2s + 500ms);
                break;
            default:
                break;
        }
    }

    void PassengerBoarded(Unit* passenger, int8 /*seat*/, bool apply) override
    {
        Player* player = passenger->ToPlayer();
        if (!player)
            return;

        if (apply)
        {
            _instance->SetData(DATA_START_BATTERED_RED_DRAKE_DESPAWN_EVENT, IN_PROGRESS);
            me->SetControlled(true, UNIT_STATE_ROOT);
            me->PlayOneShotAnimKitId(ANIM_KIT_ID_LIFTOFF);
            me->SetAnimationTier(AnimationTier::Fly);

            player->SetMover(me);
            _playerGuid = player->GetGUID();

            _events.ScheduleEvent(EVENT_SET_HOVERING, 2s);
            _events.ScheduleEvent(EVENT_PREPARE_BOMBARDMENT, 1s);
        }
        else
        {
            player->SetMover(player);
            me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SET_HOVERING:
                    if (Player* player = ObjectAccessor::FindConnectedPlayer(_playerGuid))
                        DoCast(player, SPELL_GEAR_SCALING_TRIGGER, true);

                    break;
                case EVENT_PREPARE_BOMBARDMENT:
                    if (Player* player = ObjectAccessor::FindConnectedPlayer(_playerGuid))
                    {
                        Talk(SAY_WHISPER_BOMBARDMENT, player);
                        Talk(SAY_ANNOUNCE_BOMBARDMENT, player);
                        _events.ScheduleEvent(EVENT_FLY_BOMBARDMENT, 2s);
                    }
                    break;
                case EVENT_FLY_BOMBARDMENT:
                    me->GetMotionMaster()->MoveAlongSplineChain(POINT_EJECT_PLAYER, SPLINE_CHAIN_BOMBARDMENT, false);
                    break;
                case EVENT_FLY_AWAY:
                    me->GetMotionMaster()->MoveAlongSplineChain(0, SPLINE_CHAIN_ESCAPE_BOMBARDMENT, false);
                    me->DespawnOrUnsummon(6s + 700ms);
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
    ObjectGuid _playerGuid;
};

class spell_grim_batol_engulfing_flames : public SpellScript
{
    void HandleEffect(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature())
            creature->setRegeneratingHealth(false);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_grim_batol_engulfing_flames::HandleEffect, EFFECT_1, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_grim_batol()
{
    RegisterGrimBatolCreatureAI(npc_grim_batol_twilight_beguiler);
    RegisterGrimBatolCreatureAI(npc_grim_batol_battered_red_drake);
    RegisterSpellScript(spell_grim_batol_engulfing_flames);
}
