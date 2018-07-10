/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "GridNotifiers.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "ScriptMgr.h"
#include "eye_of_azshara.h"

// 97171
struct npc_hatecoil_arcanist : public ScriptedAI
{
    npc_hatecoil_arcanist(Creature* creature) : ScriptedAI(creature) { }

    void JustDied(Unit* /*killer*/) override
    {
        me->GetInstanceScript()->SetData(DATA_ARCANIST_DIED, 0);
    }
};

// 196027
class spell_hatecoil_arcanist_aqua_spout : public SpellScript
{
    PrepareSpellScript(spell_hatecoil_arcanist_aqua_spout);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        Unit* caster = GetCaster();

        if (caster && target && target->ToPlayer())
            caster->CastSpell(target, SPELL_AQUA_SPOUT_MISSILE);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_hatecoil_arcanist_aqua_spout::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 196031
class aura_hatecoil_wavebinder_bubble_shield : public AuraScript
{
    PrepareAuraScript(aura_hatecoil_wavebinder_bubble_shield);

    void OnRemove(AuraEffect const* /*auraEff*/, AuraEffectHandleModes /*modes*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
        {
            Unit* target = GetTarget();
            target->CastSpell(target, SPELL_FEEDBACK, true);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_hatecoil_wavebinder_bubble_shield::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

// 195528
class spell_animated_storm_water_spout : public SpellScript
{
    PrepareSpellScript(spell_animated_storm_water_spout);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        if (caster && target)
        {
            float x, y, z;
            target->GetNearPoint(target, x, y, z, 1, 3.0f, frand(0.f, 2.f * float(M_PI)));
            if (Creature* waterSpout = caster->SummonCreature(NPC_WATER_SPOUT, x, y, z, 1.0f, TEMPSUMMON_MANUAL_DESPAWN))
            {
                waterSpout->setFaction(caster->getFaction());
                waterSpout->CastSpell(waterSpout, SPELL_WATER_SPOUT_AT, false);
                waterSpout->GetMotionMaster()->MoveRandom(25.0f);
            }
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_animated_storm_water_spout::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Spell: 195539
// AT: 100100
struct at_animated_storm_water_spout : AreaTriggerAI
{
    at_animated_storm_water_spout(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (caster && unit && caster->IsValidAttackTarget(unit))
            caster->CastSpell(unit, SPELL_WATER_SPOUT_DAMAGE, true);
    }
};

// 195827
class spell_skrog_tidestomper_massive_quake : public SpellScript
{
    PrepareSpellScript(spell_skrog_tidestomper_massive_quake);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* target = GetHitUnit();
        Unit* caster = GetCaster();

        if (caster && target)
            caster->CastSpell(target, SPELL_MASSIVE_QUAKE_AT, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_skrog_tidestomper_massive_quake::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// Spell: 195828
// AT: 10655
struct at_skrog_tidestomper_massive_quake : AreaTriggerAI
{
    at_skrog_tidestomper_massive_quake(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
        {
            for (ObjectGuid guid : at->GetInsideUnits())
            {
                if (Unit* unit = ObjectAccessor::GetUnit(*caster, guid))
                {
                    if (caster->IsValidAttackTarget(unit))
                        caster->CastSpell(unit, SPELL_MASSIVE_QUAKE_DAMAGE, true);
                }
            }
        }
    }
};

// 196175
class aura_makrana_hardshell_armorshell : public AuraScript
{
    PrepareAuraScript(aura_makrana_hardshell_armorshell);

    void OnRemove(AuraEffect const* /*auraEff*/, AuraEffectHandleModes /*modes*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_ENEMY_SPELL)
        {
            Unit* target = GetTarget();
            target->CastSpell(target, SPELL_ARMORSHELL_SHRAPNEL, true);
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(aura_makrana_hardshell_armorshell::OnRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
    }
};

// 191792, 191805, 192649
class aura_eoa_violent_winds_broadcast : public AuraScript
{
    PrepareAuraScript(aura_eoa_violent_winds_broadcast);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        Map::PlayerList const& playerList = GetTarget()->GetInstanceScript()->instance->GetPlayers();
        for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
        {
            Player* player = itr->GetSource();
            player->CastSpell(player, SPELL_VIOLENT_WINDS_DUMMY, true);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_eoa_violent_winds_broadcast::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 191797
class aura_eoa_violent_winds_force_move : public AuraScript
{
    PrepareAuraScript(aura_eoa_violent_winds_force_move);

    void ApplyForceMove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->ApplyMovementForce(target->GetGUID(), 2.0f, Position(-3486.264f, 4386.87f, -3.580416f));
    }

    void RemoveForceMove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->RemoveMovementForce(target->GetGUID());
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(aura_eoa_violent_winds_force_move::ApplyForceMove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(aura_eoa_violent_winds_force_move::RemoveForceMove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 192737
class aura_eoa_lightning_strikes : public AuraScript
{
    PrepareAuraScript(aura_eoa_lightning_strikes);

    void OnPeriodic(AuraEffect const* aurEff)
    {
        if (Unit* caster = GetCaster())
        {
            if (InstanceScript* instanceScript = caster->GetInstanceScript())
            {
                if (instanceScript->GetData(DATA_BOSS_DIED) >= 3)
                {
                    Map::PlayerList const& playerList = instanceScript->instance->GetPlayers();
                    std::vector<Player*> playerVec;
                    for (auto itr = playerList.begin(); itr != playerList.end(); ++itr)
                        playerVec.push_back(itr->GetSource());

                    if (playerVec.size() > 0)
                    {
                        Unit* target = Trinity::Containers::SelectRandomContainerElement(playerVec);
                        caster->CastSpell(target, GetSpellInfo()->GetEffect(aurEff->GetEffIndex())->TriggerSpell, false);
                    }
                }
            }
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_eoa_lightning_strikes ::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 192794
class spell_eoa_lightning_strikes_damage : public SpellScript
{
    PrepareSpellScript(spell_eoa_lightning_strikes_damage);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(Trinity::ObjectTypeIdCheck(TYPEID_PLAYER, false));
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eoa_lightning_strikes_damage::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eoa_lightning_strikes_damage::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENTRY);
    }
};

void AddSC_eye_of_azshara()
{
    RegisterCreatureAI(npc_hatecoil_arcanist);

    RegisterSpellScript(spell_hatecoil_arcanist_aqua_spout);
    RegisterSpellScript(spell_animated_storm_water_spout);
    RegisterSpellScript(spell_skrog_tidestomper_massive_quake);
    RegisterSpellScript(spell_eoa_lightning_strikes_damage);

    RegisterAuraScript(aura_hatecoil_wavebinder_bubble_shield);
    RegisterAuraScript(aura_makrana_hardshell_armorshell);
    RegisterAuraScript(aura_eoa_violent_winds_broadcast);
    RegisterAuraScript(aura_eoa_violent_winds_force_move);
    RegisterAuraScript(aura_eoa_lightning_strikes);

    RegisterAreaTriggerAI(at_animated_storm_water_spout);
    RegisterAreaTriggerAI(at_skrog_tidestomper_massive_quake);
}
