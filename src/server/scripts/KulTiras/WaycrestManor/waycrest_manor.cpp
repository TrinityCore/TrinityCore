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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Conversation.h"
#include "Creature.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "TaskScheduler.h"
#include "waycrest_manor.h"

enum WaycrestManorSpells
{
    // Matron Bryndle
    SPELL_GOLIATH_DRAIN_FLAVOR_PERIODIC = 265777,
    SPELL_GOLIATH_DRAIN_FLAVOR          = 265779,
    SPELL_DRAIN_GOLIATH_ESSENCE         = 265741,
    SPELL_DRAIN_GOLIATH_ESSENCE_AREA    = 265743,
    SPELL_SPLINTER_SPIKE_MISSILE        = 265758,
    SPELL_SPLINTER_SPIKE_SELECTOR       = 265759,
    SPELL_THORNED_BARRAGE               = 265760,
    SPELL_WILDFIRE_MISSILE              = 260566,
    SPELL_WILDFIRE_DAMAGE               = 260569,
    SPELL_WILDFIRE_DAMAGE_NPC           = 273294,

    // Lord and Lady Waycrest outro
    SPELL_ORGAN_MISSILES              = 267646,
    SPELL_DEATH_REALM_PHASE           = 263332,
    SPELL_WAYCRESTS_DEFEATED_ALLIANCE = 267597,
    SPELL_WAYCRESTS_DEFEATED_HORDE    = 267595,
    SPELL_COSMETIC_MISSILE_TRANSFORM  = 267669
};

enum WaycrestManorMisc
{
    // Conversations after Waycrests are defeated
    CONVERSATION_LINE_LUCILLE_WAYCREST = 16957,
    CONVERSATION_LINE_GORAK_TUL_HORDE  = 16850,
    CONVO_ACTOR_IDX_GORAK_TUL          = 0,

    PATH_GORAK_TUL                     = 13616100
};

enum WaycrestManorEvents
{
    // Matron Bryndle
    EVENT_SPLINTER_SPIKE    = 1,
    EVENT_THORNED_BARRAGE,
    EVENT_GORAK_TUL_TRANSFORM,
    EVENT_GORAK_TUL_MOVE
};

// 135329 - Matron Bryndle
struct npc_matron_bryndle : public ScriptedAI
{
    npc_matron_bryndle(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        DoCast(SPELL_GOLIATH_DRAIN_FLAVOR_PERIODIC);
    }

    void JustReachedHome() override
    {
        DoCast(SPELL_GOLIATH_DRAIN_FLAVOR_PERIODIC);
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        InstanceScript* instance = me->GetInstanceScript();
        if (instance->GetData(DATA_SOULBOUND_GOLIATH_INTRO) != DONE)
        {
            me->RemoveAurasDueToSpell(SPELL_GOLIATH_DRAIN_FLAVOR_PERIODIC);
            DoCast(SPELL_DRAIN_GOLIATH_ESSENCE);

            if (Creature* soulboundGoliath = instance->GetCreature(DATA_SOULBOUND_GOLIATH))
                soulboundGoliath->AI()->DoAction(ACTION_SOULBOUND_GOLIATH_INTRO);

            instance->SetData(DATA_SOULBOUND_GOLIATH_INTRO, DONE);
        }

        _events.ScheduleEvent(EVENT_SPLINTER_SPIKE, 4500ms);
        _events.ScheduleEvent(EVENT_THORNED_BARRAGE, 8200ms);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (_events.ExecuteEvent())
        {
            case EVENT_SPLINTER_SPIKE:
            {
                DoCast(SPELL_SPLINTER_SPIKE_SELECTOR);
                _events.Repeat(24300ms);
                break;
            }
            case EVENT_THORNED_BARRAGE:
            {
                DoCast(SPELL_THORNED_BARRAGE);
                _events.Repeat(12100ms);
                break;
            }
            default:
                break;
        }
    }

private:
    EventMap _events;
};

// 265778 - Goliath Drain Flavor
class spell_waycrest_manor_goliath_drain_flavor_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_GOLIATH_DRAIN_FLAVOR });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_GOLIATH_DRAIN_FLAVOR, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_waycrest_manor_goliath_drain_flavor_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 265741 - Drain Goliath Essence
class spell_waycrest_manor_drain_goliath_essence : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_DRAIN_GOLIATH_ESSENCE_AREA });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_DRAIN_GOLIATH_ESSENCE_AREA, true);

        if (Creature* hitCreature = GetHitCreature())
            hitCreature->DespawnOrUnsummon();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_waycrest_manor_drain_goliath_essence::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 265759 - Splinter Spike
class spell_waycrest_manor_splinter_spike_selector : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SPLINTER_SPIKE_MISSILE });
    }

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SPLINTER_SPIKE_MISSILE, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_waycrest_manor_splinter_spike_selector::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 260564 - Wildfire
class spell_waycrest_manor_wildfire : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WILDFIRE_MISSILE });
    }

    Position GetRandomPositionInCircle()
    {
        static constexpr Position CircleCenterPos = { -422.13f, -258.28f, 233.8286f, 0.0f };

        Position randomPos = CircleCenterPos;
        GetTarget()->MovePosition(randomPos, 30.0f * rand_norm(), rand_norm() * static_cast<float>(2 * M_PI));

        return randomPos;
    }

    Position GetRandomPositionInRectangle()
    {
        static constexpr Position RectTopRight = { -452.514f, -244.098f };
        static constexpr Position RectBottomLeft = { -529.758f, -277.167f };

        float x = frand(RectBottomLeft.GetPositionX(), RectTopRight.GetPositionX());
        float y = frand(RectBottomLeft.GetPositionY(), RectTopRight.GetPositionY());
        float z = GetTarget()->GetPositionZ();

        GetTarget()->UpdateGroundPositionZ(x, y, z);

        return Position(x, y, z);
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() % 6 == 0)
            GetTarget()->CastSpell(roll_chance_i(50) ? GetRandomPositionInCircle() : GetRandomPositionInRectangle(), SPELL_WILDFIRE_MISSILE, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_waycrest_manor_wildfire::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 17041 - Wildfire (260570)
struct at_waycrest_manor_wildfire : AreaTriggerAI
{
    at_waycrest_manor_wildfire(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
        {
            if (!player->IsGameMaster())
                unit->CastSpell(unit, SPELL_WILDFIRE_DAMAGE, true);
        }
        else
        {
            if (!unit->IsInCombat())
                return;

            if (unit->GetEntry() == BOSS_SOULBOUND_GOLIATH)
            {
                if (unit->HasAura(SPELL_BURNING_BRUSH))
                    return;

                unit->CastSpell(unit, SPELL_BURNING_BRUSH, true);
            }
            else
                unit->CastSpell(unit, SPELL_WILDFIRE_DAMAGE_NPC, true);
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_WILDFIRE_DAMAGE);
        unit->RemoveAurasDueToSpell(SPELL_WILDFIRE_DAMAGE_NPC);
    }

    void OnRemove() override
    {
        for (ObjectGuid const& guid : at->GetInsideUnits())
        {
            Unit* unit = ObjectAccessor::GetUnit(*at, guid);
            if (!unit)
                continue;

            OnUnitExit(unit);
        }
    }
};

// 267643 - Organ Missiles
struct at_waycrest_manor_organ_missiles : AreaTriggerAI
{
    at_waycrest_manor_organ_missiles(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnCreate(Spell const* /*creatingSpell*/) override
    {
        _scheduler.Schedule(100ms, 300ms, [this](TaskContext task)
        {
            if (Unit* caster = at->GetCaster())
                caster->CastSpell(at->GetPosition(), SPELL_ORGAN_MISSILES, TRIGGERED_IGNORE_CAST_IN_PROGRESS);

            task.Repeat(100ms, 300ms);
        });
    }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
        {
            Creature* casterCreature = caster->ToCreature();
            if (!casterCreature)
                return;

            InstanceScript* instance = casterCreature->GetInstanceScript();
            if (!instance)
                return;

            casterCreature->RemoveAurasDueToSpell(SPELL_DEATH_REALM_PHASE);
            casterCreature->SetUninteractible(false);
            casterCreature->CastSpell(casterCreature, instance->instance->GetTeamInInstance() == HORDE ? SPELL_WAYCRESTS_DEFEATED_HORDE : SPELL_WAYCRESTS_DEFEATED_ALLIANCE);
        }
    }

    void OnUpdate(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

// 267646 - Organ Missiles
class spell_waycrest_manor_organ_missiles : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ frand(-26.0f, -15.0f), frand(-26.0f, 21.0f), 0.0f, 0.0f });
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_waycrest_manor_organ_missiles::SetDest, EFFECT_0, TARGET_DEST_DEST);
    }
};

// 267595 - Waycrest Manor - Waycrests Defeated (Horde)
// 267597 - Waycrest Manor - Waycrests Defeated (Alliance)
// 7351 - Conversation
// 7352 - Conversation
class conversation_waycrest_manor_waycrests_defeated : public ConversationScript
{
public:
    conversation_waycrest_manor_waycrests_defeated() : ConversationScript("conversation_waycrest_manor_waycrests_defeated") { }

    void OnConversationStart(Conversation* conversation) override
    {
        if (Milliseconds const* gorakTulMoveStartTimeAlliance = conversation->GetLineStartTime(DEFAULT_LOCALE, CONVERSATION_LINE_LUCILLE_WAYCREST))
            _events.ScheduleEvent(EVENT_GORAK_TUL_TRANSFORM, *gorakTulMoveStartTimeAlliance);
        else if (Milliseconds const* gorakTulMoveStartTimeHorde = conversation->GetLineStartTime(DEFAULT_LOCALE, CONVERSATION_LINE_GORAK_TUL_HORDE))
            _events.ScheduleEvent(EVENT_GORAK_TUL_TRANSFORM, *gorakTulMoveStartTimeHorde + 3s);
    }

    void OnConversationUpdate(Conversation* conversation, uint32 diff) override
    {
        _events.Update(diff);

        switch (_events.ExecuteEvent())
        {
            case EVENT_GORAK_TUL_TRANSFORM:
            {
                Creature* gorakTul = conversation->GetActorCreature(CONVO_ACTOR_IDX_GORAK_TUL);
                if (!gorakTul)
                    break;

                gorakTul->CastSpell(gorakTul, SPELL_COSMETIC_MISSILE_TRANSFORM);
                _events.ScheduleEvent(EVENT_GORAK_TUL_MOVE, 1s);
                break;
            }
            case EVENT_GORAK_TUL_MOVE:
            {
                Creature* gorakTul = conversation->GetActorCreature(CONVO_ACTOR_IDX_GORAK_TUL);
                if (!gorakTul)
                    break;

                // @TODO: SplineFilter nyi
                /*
                ServerToClient: SMSG_ON_MONSTER_MOVE (0x2DD4) Length: 191 ConnIdx: 1 Time: 07/19/2024 09:17:19.888 Number: 8254
                MoverGUID: Full: 0x204128E8C084F840001FF700001A1123 Creature/0 R4170/S8183 Map: 1862 (Waycrest Manor) Entry: 136161 (Gorak Tul) Low: 1708323
                Position: X: -524.88715 Y: -260.56772 Z: 182.55463
                (MovementMonsterSpline) (MovementSpline) Flags: 2438990336 (Flying, Catmullrom, CanSwim, UncompressedPath, Unknown5, Steering, Unknown10)
                (MovementMonsterSpline) (MovementSpline) HasSplineFilter: True
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) MonsterSplineFilterKey: 2
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) BaseSpeed: 5
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) StartOffset: 0
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) DistToPrevFilterKey: 0
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) AddedToStart: 1
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) [0] IDx: 0
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) [0] Speed: 500
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) [1] IDx: 1
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) [1] Speed: 1500
                (MovementMonsterSpline) (MovementSpline) (MonsterSplineFilter) FilterFlags: 2
                (MovementMonsterSpline) (MovementSpline) [0] Points: X: -525.816 Y: -261.41666 Z: 188.96046
                (MovementMonsterSpline) (MovementSpline) [1] Points: X: -532.49304 Y: -279.55383 Z: 186.57698
                (MovementMonsterSpline) (MovementSpline) [2] Points: X: -526.13367 Y: -292.1389 Z: 185.22873
                (MovementMonsterSpline) (MovementSpline) [3] Points: X: -501.00696 Y: -316.64932 Z: 171.55269
                (MovementMonsterSpline) (MovementSpline) [4] Points: X: -488.12326 Y: -329.7795 Z: 161.65425
                (MovementMonsterSpline) (MovementSpline) [5] Points: X: -470.80383 Y: -326.80557 Z: 159.51692
                (MovementMonsterSpline) (MovementSpline) [6] Points: X: -460.06772 Y: -335.67188 Z: 158.33897
                (MovementMonsterSpline) (MovementSpline) [7] Points: X: -446.75 Y: -343.94272 Z: 155.77182
                (MovementMonsterSpline) (MovementSpline) [8] Points: X: -441.15625 Y: -344.0955 Z: 157.48708
                (MovementMonsterSpline) (MovementSpline) CalculatedSpeedXY: 46.351273
                */

                gorakTul->SetFloating(true);
                gorakTul->GetMotionMaster()->MovePath(PATH_GORAK_TUL, false);
                break;
            }
            default:
                break;
        }
    }

private:
    EventMap _events;
};

void AddSC_waycrest_manor()
{
    // Matron Bryndle
    RegisterWaycrestManorCreatureAI(npc_matron_bryndle);

    RegisterSpellScript(spell_waycrest_manor_goliath_drain_flavor_selector);
    RegisterSpellScript(spell_waycrest_manor_drain_goliath_essence);
    RegisterSpellScript(spell_waycrest_manor_splinter_spike_selector);
    RegisterSpellScript(spell_waycrest_manor_wildfire);
    RegisterAreaTriggerAI(at_waycrest_manor_wildfire);

    // Lord and Lady Waycrest outro
    RegisterAreaTriggerAI(at_waycrest_manor_organ_missiles);
    RegisterSpellScript(spell_waycrest_manor_organ_missiles);
    new conversation_waycrest_manor_waycrests_defeated();
}
