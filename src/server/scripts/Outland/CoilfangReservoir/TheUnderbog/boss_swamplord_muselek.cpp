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

#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "MotionMaster.h"
#include "Player.h"
#include "the_underbog.h"

enum MuselekTexts
{
    SAY_COMMAND                 = 0,
    SAY_AGGRO                   = 1,
    SAY_SLAY                    = 2,
    SAY_DEATH                   = 3
};

enum MuselekSpells
{
    SPELL_SHOOT                 = 22907,
    SPELL_MULTI_SHOT            = 34974,
    SPELL_AIMED_SHOT            = 31623,

    SPELL_KNOCK_AWAY            = 18813,
    SPELL_BEAR_COMMAND          = 34662,
    SPELL_DETERRENCE            = 31567,

    SPELL_HUNTERS_MARK          = 31615,
    SPELL_FREEZING_TRAP         = 31946,
    SPELL_PACIFY_SELF           = 19951,
    SPELL_MOVE_AWAY_PRIMER      = 31564,
    SPELL_FACE_HIGHEST_THREAT   = 32425,

    // Claw
    SPELL_ECHOING_ROAR          = 31429,
    SPELL_MAUL                  = 34298,
    SPELL_FRENZY                = 34971,
    SPELL_FERAL_CHARGE          = 39435
};

enum MuselekEvents
{
    EVENT_SHOOT                 = 1,
    EVENT_MULTI_SHOT,

    EVENT_KNOCK_AWAY,
    EVENT_BEAR_COMMAND,

    EVENT_COMBAT_SEQUENCE_1,
    EVENT_COMBAT_SEQUENCE_2,
    EVENT_COMBAT_SEQUENCE_3,
    EVENT_COMBAT_SEQUENCE_4,

    // Claw
    EVENT_ECHOING_ROAR,
    EVENT_MAUL,
    EVENT_COMMAND_RESPONSE,
    EVENT_FERAL_CHARGE,

    EVENT_OUTRO_1,
    EVENT_OUTRO_2,
    EVENT_OUTRO_3
};

enum MuselekMisc
{
    FACTION_CENARION_EXP        = 1660,
    NPC_WINDCALLER_CLAW         = 17894,
    POINT_OUTRO_1               = 1,
    POINT_OUTRO_2               = 2,
    POINT_MOVE_AWAY             = 1
};

Position const OutroPos[2] =
{
    { 290.53226f, -125.35236f, 29.697079f, 0.0f },
    { 295.05692f, -123.32802f, 29.659490f, 0.0f }
};

// 17826 - Swamplord Musel'ek
struct boss_swamplord_muselek : public BossAI
{
    boss_swamplord_muselek(Creature* creature) : BossAI(creature, DATA_SWAMPLORD_MUSELEK) { }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO);
        BossAI::JustEngagedWith(who);
        me->SetReactState(REACT_AGGRESSIVE);

        events.ScheduleEvent(EVENT_SHOOT, 0s);
        events.ScheduleEvent(EVENT_MULTI_SHOT, 20s, 30s);

        events.ScheduleEvent(EVENT_KNOCK_AWAY, 35s, 40s);
        events.ScheduleEvent(EVENT_BEAR_COMMAND, 10s);

        events.ScheduleEvent(EVENT_COMBAT_SEQUENCE_1, 15s, 20s);
    }

    void AttackStart(Unit* who) override
    {
        ScriptedAI::AttackStartCaster(who, 30.0f);
    }

    void OnSpellCast(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_BEAR_COMMAND)
            Talk(SAY_COMMAND);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (pointId == POINT_MOVE_AWAY)
            events.ScheduleEvent(EVENT_COMBAT_SEQUENCE_3, 1s);
    }

    void KilledUnit(Unit* /*victim*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
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
                case EVENT_SHOOT:
                    DoCastVictim(SPELL_SHOOT);
                    events.Repeat(2s, 4s);
                    break;
                case EVENT_MULTI_SHOT:
                    DoCastVictim(SPELL_MULTI_SHOT);
                    events.Repeat(25s, 35s);
                    break;
                case EVENT_KNOCK_AWAY:
                    DoCastVictim(SPELL_KNOCK_AWAY);
                    events.Repeat(30s, 40s);
                    break;
                case EVENT_BEAR_COMMAND:
                    DoCastSelf(SPELL_BEAR_COMMAND);
                    events.Repeat(25s);
                    break;

                // This part requires additional research
                case EVENT_COMBAT_SEQUENCE_1:
                    DoCastSelf(SPELL_HUNTERS_MARK);

                    if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                        DoCast(target, SPELL_FREEZING_TRAP);

                    me->SetReactState(REACT_PASSIVE);
                    events.ScheduleEvent(EVENT_COMBAT_SEQUENCE_2, 2s);
                    events.Repeat(25s, 50s);
                    break;
                case EVENT_COMBAT_SEQUENCE_2:
                    DoCastSelf(SPELL_PACIFY_SELF);
                    DoCastSelf(SPELL_MOVE_AWAY_PRIMER);

                    // This is based only on one cast in sniff, need more info
                    if (roll_chance_i(50))
                        DoCastSelf(SPELL_DETERRENCE);
                    break;
                case EVENT_COMBAT_SEQUENCE_3:
                    // NYI
                    DoCastSelf(SPELL_FACE_HIGHEST_THREAT);
                    me->RemoveAurasDueToSpell(SPELL_PACIFY_SELF);
                    me->SetReactState(REACT_AGGRESSIVE);

                    // On next update, otherwise it will not work
                    events.ScheduleEvent(EVENT_COMBAT_SEQUENCE_4, 1ms);
                    break;
                case EVENT_COMBAT_SEQUENCE_4:
                    DoCastVictim(SPELL_AIMED_SHOT);
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

// 17827 - Claw
struct npc_claw : public ScriptedAI
{
    npc_claw(Creature* creature) : ScriptedAI(creature), _canPerformOutro(false), _chargeCounter(0), _currentChargeCount(0) { }

    void Reset() override
    {
        _events.Reset();
        _chargeCounter = 0;
        _currentChargeCount = 0;
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_ECHOING_ROAR, 20s, 25s);
        _events.ScheduleEvent(EVENT_MAUL, 5s, 10s);
    }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id == SPELL_BEAR_COMMAND)
            _events.ScheduleEvent(EVENT_COMMAND_RESPONSE, 0s);
    }

    bool OnGossipHello(Player* player) override
    {
        player->KilledMonsterCredit(NPC_WINDCALLER_CLAW);
        return false;
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage, DamageEffectType /*damageType*/, SpellInfo const* /*spellInfo = nullptr*/) override
    {
        // This CAN occur even if Musel'ek is NOT yet dead
        if (!_canPerformOutro && me->HealthBelowPctDamaged(20, damage))
        {
            _canPerformOutro = true;
            me->SetFaction(FACTION_CENARION_EXP);
            me->SetImmuneToAll(true);
            EnterEvadeMode();
        }
    }

    void JustReachedHome() override
    {
        if (_canPerformOutro)
            _events.ScheduleEvent(EVENT_OUTRO_1, 0s);
        ScriptedAI::JustReachedHome();
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_OUTRO_1:
                _events.ScheduleEvent(EVENT_OUTRO_2, 0s);
                break;
            case POINT_OUTRO_2:
                _events.ScheduleEvent(EVENT_OUTRO_3, 1s);
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            if (_canPerformOutro)
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_OUTRO_1:
                            me->SetWalk(true);
                            me->GetMotionMaster()->MovePoint(POINT_OUTRO_1, OutroPos[0]);
                            me->UpdateEntry(NPC_WINDCALLER_CLAW);
                            /// !HACK: UpdateEntry here should be done without changing faction. Changing faction back
                            me->SetFaction(FACTION_CENARION_EXP);
                            /// !HACK: Removed after entry is updated. Changing back
                            me->SetImmuneToAll(true);
                            break;
                        case EVENT_OUTRO_2:
                            me->GetMotionMaster()->MovePoint(POINT_OUTRO_2, OutroPos[1]);
                            break;
                        case EVENT_OUTRO_3:
                            me->SetFacingTo(3.420845270156860351f);
                            me->SetStandState(UNIT_STAND_STATE_SIT);
                            break;
                        default:
                            break;
                    }
                }
            }

            return;
        }

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_ECHOING_ROAR:
                    DoCastSelf(SPELL_ECHOING_ROAR);
                    _events.Repeat(10s, 20s);
                    break;
                case EVENT_MAUL:
                    DoCastVictim(SPELL_MAUL);
                    _events.Repeat(10s, 15s);
                    break;
                case EVENT_COMMAND_RESPONSE:
                    DoCastSelf(SPELL_FRENZY);
                    // 0 seems to be valid value. He doesn't obey always, perhaps. Or something is more tricky than it seems
                    _chargeCounter = RAND(0, 1, 2, 3, 4);
                    _currentChargeCount = 0;
                    _events.ScheduleEvent(EVENT_FERAL_CHARGE, 2s, 5s);
                    break;
                case EVENT_FERAL_CHARGE:
                    if (_currentChargeCount < _chargeCounter)
                    {
                        if (Unit* target = SelectTarget(SelectTargetMethod::Random, 0))
                            DoCast(target, SPELL_FERAL_CHARGE);

                        ++_currentChargeCount;
                        _events.Repeat(2s, 5s);
                    }
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
    bool _canPerformOutro;
    uint8 _chargeCounter;
    uint8 _currentChargeCount;
};

// 31564 - Move Away Primer
class spell_swamplord_muselek_move_away_primer : public SpellScript
{
    PrepareSpellScript(spell_swamplord_muselek_move_away_primer);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        // This should be more tricky. More like random position but with min and max distance, not just random
        Position pos = GetCaster()->GetRandomNearPosition(30.0f);
        GetCaster()->GetMotionMaster()->MovePoint(POINT_MOVE_AWAY, pos);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_swamplord_muselek_move_away_primer::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

void AddSC_boss_swamplord_muselek()
{
    RegisterTheUnderbogCreatureAI(boss_swamplord_muselek);
    RegisterTheUnderbogCreatureAI(npc_claw);
    RegisterSpellScript(spell_swamplord_muselek_move_away_primer);
}
