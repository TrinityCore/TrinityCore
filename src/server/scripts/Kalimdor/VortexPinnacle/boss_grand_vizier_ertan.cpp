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
#include "MotionMaster.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "InstanceScript.h"
#include "SpellScript.h"
#include "Unit.h"
#include "SpellInfo.h"
#include "vortex_pinnacle.h"

enum Spells
{
    // Grandvizier Ertan
    SPELL_STORMS_EDGE_PERIODIC              = 86295,
    SPELL_LIGHTNING_BOLT                    = 86331,
    SPELL_SUMMON_TEMPEST                    = 86340,
    SPELL_STORMS_EDGE_VISUAL                = 86329,
    SPELL_STORMS_EDGE_PERIODIC_2            = 86310,
    SPELL_STORMS_EDGE_TRIGGERED_1           = 86284,
    SPELL_STORMS_EDGE_SCRIPT                = 86299
};

enum Texts
{
    // Grand Vizier Ertan
    SAY_AGGRO                   = 0,
    SAY_ANNOUNCE_STORMS_EDGE    = 1
};

enum Events
{
    // Grandvizier Ertan
    EVENT_SUMMON_TEMPEST = 1,
    EVENT_STORMS_EDGE,
    EVENT_STORMS_EDGE_AURA,
    EVENT_END_STORMS_EDGE,
    EVENT_LIGHTNING_BOLT,

    // Ertan's Vortex
    EVENT_MOVE_POINT
};

enum Actions
{
    // Ertan's Vortex
    ACTION_STORMS_EDGE = 1
};

enum Points
{
    // Ertan's Vortex
    POINT_NONE      = 0,
    POINT_ROTATE    = 1
};

static constexpr uint8 MaxVortexPoints = 8;

Position const ErtansVortexPoints[MaxVortexPoints] =
{
    { -744.889f,  3.98611f, 635.6728f }, // South
    { -737.552f,  21.592f,  635.6728f }, // South-West
    { -719.802f,  28.8351f, 635.6728f }, // West
    { -702.144f,  21.9878f, 635.6728f }, // North-West
    { -694.911f,  4.16493f, 635.6728f }, // North
    { -702.212f, -13.6806f, 635.6728f }, // North-East
    { -719.934f, -20.9497f, 635.6728f }, // East
    { -737.649f, -13.5347f, 635.6728f } // South-East
};

Position const ErtansVortexMiddlePoints[MaxVortexPoints] =
{
    { -724.3819f,  2.915083f,   635.6728f }, // South
    { -724.0161f,  6.648534f,   635.6728f }, // South-West
    { -721.1381f,  9.082433f,   635.6728f }, // West
    { -716.7177f,  8.423817f,   635.6728f }, // North-West
    { -714.6548f,  5.146466f,   635.6728f }, // North
    { -715.2417f,  1.857746f,   635.6728f }, // North-East
    { -718.2345f, -0.4830246f,  635.6728f }, // East
    { -721.9816f, -0.05864143f, 635.6728f } // South-East
};

struct boss_grand_vizier_ertan : public BossAI
{
    boss_grand_vizier_ertan(Creature* creature) : BossAI(creature, DATA_GRAND_VIZIER_ERTAN) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        DoCastSelf(SPELL_STORMS_EDGE_PERIODIC);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        Talk(SAY_AGGRO);

        for (uint8 i = 0; i < MaxVortexPoints; i++)
            if (Creature * ertansVortex = DoSummon(NPC_ERTANS_VORTEX, ErtansVortexPoints[i], 0, TEMPSUMMON_MANUAL_DESPAWN))
                ertansVortex->GetMotionMaster()->MovePoint(POINT_ROTATE + i, ErtansVortexPoints[i + 1  < MaxVortexPoints ? i + 1 : 0]);

        events.ScheduleEvent(EVENT_STORMS_EDGE, 24s);
        events.ScheduleEvent(EVENT_LIGHTNING_BOLT, 1ms);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_SUMMON_TEMPEST, 16s, 17s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _DespawnAtEvade();
    }

    void JustDied(Unit* /*killer*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
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
                case EVENT_SUMMON_TEMPEST:
                    DoCast(me, SPELL_SUMMON_TEMPEST);
                    events.Repeat(17s);
                    break;
                case EVENT_STORMS_EDGE:
                {
                    Talk(SAY_ANNOUNCE_STORMS_EDGE);
                    DoCastSelf(SPELL_STORMS_EDGE_VISUAL);
                    EntryCheckPredicate pred(NPC_ERTANS_VORTEX);
                    summons.DoAction(ACTION_STORMS_EDGE, pred, 8);
                    events.ScheduleEvent(EVENT_STORMS_EDGE_AURA, 3s);
                    events.Repeat(31s);
                    break;
                }
                case EVENT_STORMS_EDGE_AURA:
                    me->RemoveAurasDueToSpell(SPELL_STORMS_EDGE_PERIODIC);
                    DoCastSelf(SPELL_STORMS_EDGE_PERIODIC_2);
                    events.ScheduleEvent(EVENT_END_STORMS_EDGE, 6s);
                    break;
                case EVENT_END_STORMS_EDGE:
                    me->RemoveAurasDueToSpell(SPELL_STORMS_EDGE_PERIODIC_2);
                    DoCastSelf(SPELL_STORMS_EDGE_PERIODIC);
                    break;
                case EVENT_LIGHTNING_BOLT:
                    DoCastVictim(SPELL_LIGHTNING_BOLT);
                    events.Repeat(2s + 400ms);
                    break;
                default:
                    break;
            }
        }
    }
};

struct npc_ertan_ertans_vortex : public NullCreatureAI
{
    npc_ertan_ertans_vortex(Creature* creature) : NullCreatureAI(creature), _nextPointId(0) { }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_STORMS_EDGE:
                me->GetMotionMaster()->MovePoint(POINT_NONE, ErtansVortexMiddlePoints[_nextPointId]);
                _events.ScheduleEvent(EVENT_MOVE_POINT, 9s);
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 movementType, uint32 pointId) override
    {
        if (movementType != POINT_MOTION_TYPE || pointId == POINT_NONE)
            return;

        _nextPointId = pointId < MaxVortexPoints ? pointId : 0;
        _events.ScheduleEvent(EVENT_MOVE_POINT, 1ms);
    };

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_POINT:
                    me->GetMotionMaster()->MovePoint(_nextPointId + 1, ErtansVortexPoints[_nextPointId]);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    uint32 _nextPointId;
};

class spell_ertan_storms_edge : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_STORMS_EDGE_TRIGGERED_1,
                SPELL_STORMS_EDGE_SCRIPT
            });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (GetSpellInfo()->Id == SPELL_STORMS_EDGE_TRIGGERED_1)
        {
            if (caster->GetExactDist2d(target) > GetEffectValue())
                target->CastSpell(target, SPELL_STORMS_EDGE_SCRIPT, true);
        }
        else
            target->CastSpell(target, SPELL_STORMS_EDGE_SCRIPT, true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ertan_storms_edge::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

class spell_ertan_storms_edge_script : public SpellScript
{
    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        if (Unit* caster = GetCaster())
            GetHitUnit()->CastSpell(caster, uint32(GetEffectValue()), true);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_ertan_storms_edge_script::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_boss_grand_vizier_ertan()
{
    RegisterVortexPinnacleCreatureAI(boss_grand_vizier_ertan);
    RegisterVortexPinnacleCreatureAI(npc_ertan_ertans_vortex);
    RegisterSpellScript(spell_ertan_storms_edge);
    RegisterSpellScript(spell_ertan_storms_edge_script);
}
