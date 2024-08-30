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
#include "Creature.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
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
    SPELL_WILDFIRE_DAMAGE_NPC           = 273294
};

enum WaycrestManorEvents
{
    // Matron Bryndle
    EVENT_SPLINTER_SPIKE    = 1,
    EVENT_THORNED_BARRAGE
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

void AddSC_waycrest_manor()
{
    // Matron Bryndle
    RegisterWaycrestManorCreatureAI(npc_matron_bryndle);

    RegisterSpellScript(spell_waycrest_manor_goliath_drain_flavor_selector);
    RegisterSpellScript(spell_waycrest_manor_drain_goliath_essence);
    RegisterSpellScript(spell_waycrest_manor_splinter_spike_selector);
    RegisterSpellScript(spell_waycrest_manor_wildfire);

    RegisterAreaTriggerAI(at_waycrest_manor_wildfire);
}
