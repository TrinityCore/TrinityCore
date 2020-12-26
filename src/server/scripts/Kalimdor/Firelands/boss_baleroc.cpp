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
#include "InstanceScript.h"
#include "SpellScript.h"
#include "ObjectAccessor.h"
#include "Containers.h"
#include "firelands.h"
#include "Map.h"
#include "GridNotifiers.h"
#include "PassiveAI.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "SpellMgr.h"

enum Spells
{
    // Baleroc
    //SPELL_LEASH                   = 101514, // Server-side, used to keep him in his encounter area? TrinityCore does not need a spell to handle this
    SPELL_BLADES_OF_BALEROC         = 99342,
    SPELL_INFERNO_BLADE             = 99350,
    SPELL_INFERNO_STRIKE            = 99351,
    SPELL_DECIMATION_BLADE          = 99352,
    SPELL_DECIMATION_BLADE_2        = 99405,
    SPELL_DECIMATING_STRIKE         = 99353,
    SPELL_BLAZE_OF_GLORY            = 99252,
    SPELL_INCENDIARY_SOUL           = 99369,
    SPELL_SHARDS_OF_TORMENT         = 99259,
    SPELL_SHARDS_OF_TORMENT_SUMMON  = 99260,
    SPELL_TORMENT_PRE_VISUAL        = 99258,
    SPELL_TORMENT_ACTIVE            = 99254,
    SPELL_TORMENT_PERIODIC          = 99255,
    SPELL_WAVE_OF_TORMENT           = 99261,
    SPELL_TORMENTED                 = 99257,
    SPELL_TORMENT                   = 99256,
    SPELL_COUNTDOWN                 = 99515,
    SPELL_COUNTDOWN_AURA            = 99516,
    SPELL_COUNTDOWN_3               = 99517,
    SPELL_COUNTDOWN_AOE_EXPLOSION   = 99518,
    SPELL_COUNTDOWN_VISUAL_LINK     = 99519,
    SPELL_VITAL_SPARK               = 99262,
    SPELL_VITAL_FLAME               = 99263,
    SPELL_BERSERK                   = 26662,
};

enum Emotes
{
    SAY_AGGRO                       = 0,
    SAY_SHARDS_OF_TORMENT           = 1,
    SAY_INFERNO_BLADE               = 2,
    SAY_DECIMATION_BLADE            = 3,
    SAY_KILL                        = 4,
    SAY_DEATH                       = 5,
    SAY_ENRAGE                      = 6,
    EMOTE_ENRAGE                    = 7,
    EMOTE_DECIMATION_BLADE          = 8,
    EMOTE_INFERNO_BLADE             = 9,
};

enum Guids
{
    GUID_TORMENTED                  = 1,
};

enum Actions
{
    ACTION_EQUIP_DEFAULT            = 1,
    ACTION_EQUIP_INFERNO_BLADE      = 2,
    ACTION_EQUIP_DECIMATION_BLADE   = 3,
};


enum Misc
{
    EQUIP_DEFAULT                   = 1,
    EQUIP_INFERNO_BLADE             = 2,
    EQUIP_DECIMATION_BLADE          = 3,
};

enum Phases
{
    PHASE_NONE                      = 0,
    PHASE_ONE                       = 1
};

// http://www.wowhead.com/npc=53494/baleroc
struct boss_baleroc : public firelands_bossAI
{
    boss_baleroc(Creature* creature) : firelands_bossAI(creature, DATA_BALEROC), _canYellKilledPlayer(true)
    {
        scheduler.SetValidator([this]
        {
            return !me->HasUnitState(UNIT_STATE_CASTING);
        });
    }

    void Reset() override
    {
        firelands_bossAI::Reset();
        _canYellKilledPlayer = true;
        EquipWeapon(EQUIP_DEFAULT);
    }

    void EnterCombat(Unit* target) override
    {
        firelands_bossAI::EnterCombat(target);

        Talk(SAY_AGGRO);
        PreparePhase(PHASE_ONE);

        _sharedThePain.clear();
    }

    void PreparePhase(Phases phase)
    {
        //events.SetPhase(phase);

        switch (phase)
        {
            case PHASE_ONE:
                scheduler.Schedule(Milliseconds(8500), [this](TaskContext context)
                {
                    me->AddAura(SPELL_INCENDIARY_SOUL, me); // No cast
                    DoCastVictim(SPELL_BLAZE_OF_GLORY);
                    context.Repeat(Milliseconds(11500));
                });
                scheduler.Schedule(Seconds(5), [this](TaskContext context)
                {
                    DoCastAOE(SPELL_SHARDS_OF_TORMENT);
                    context.Repeat(Seconds(34));
                });
                if (me->GetMap()->IsHeroic())
                {
                    scheduler.Schedule(Seconds(26), [this](TaskContext context)
                    {
                        DoCastAOE(SPELL_COUNTDOWN);
                        context.Repeat(Seconds(48));
                    });
                }
                scheduler.Schedule(Milliseconds(30500), [this](TaskContext context)
                {
                    DoCastSelf(SPELL_BLADES_OF_BALEROC);
                    context.Repeat(Seconds(47));
                });
                scheduler.Schedule(Minutes(6), [this](TaskContext)
                {
                    Talk(SAY_ENRAGE);
                    Talk(EMOTE_ENRAGE);
                    DoCastSelf(SPELL_BERSERK);
                });
                break;
            default:
                break;
        }
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_EQUIP_DEFAULT:
            case ACTION_EQUIP_INFERNO_BLADE:
            case ACTION_EQUIP_DECIMATION_BLADE:
                EquipWeapon(action);
                break;
            default:
                break;
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER && _canYellKilledPlayer)
        {
            _canYellKilledPlayer = false;
            Talk(SAY_KILL);

            separateScheduler.Schedule(Seconds(8), [this](TaskContext)
            {
                _canYellKilledPlayer = true;
            });
        }
    }

    void JustDied(Unit* killer) override
    {
        Talk(SAY_DEATH);
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLAZE_OF_GLORY);
        firelands_bossAI::JustDied(killer);
    }

    void EnterEvadeMode(EvadeReason reason) override
    {
        summons.DespawnAll();
        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_BLAZE_OF_GLORY);
        firelands_bossAI::EnterEvadeMode(reason);
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
        separateScheduler.Update(diff);
        firelands_bossAI::UpdateAI(diff);
    }

    void SetGUID(ObjectGuid guid, int32 type = 0) override
    {
        switch (type)
        {
            case GUID_TORMENTED:
                ++_sharedThePain[guid];
                break;
            default:
                break;
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case GUID_TORMENTED:
                for (auto const& entry : _sharedThePain)
                    if (entry.second > 3)
                        return 1;
                break;
            default:
                break;
        }

        return 0;
    }

private:
    void EquipWeapon(uint8 equipment) const
    {
        switch (equipment)
        {
            case EQUIP_DEFAULT:
                me->LoadEquipment(equipment);
                me->SetCanDualWield(true);
                break;
            case EQUIP_INFERNO_BLADE:
            case EQUIP_DECIMATION_BLADE:
                me->LoadEquipment(equipment);
                me->SetCanDualWield(false);
                break;
            default:
                break;
        }
    }
    // Our default TaskScheduler has a UNIT_STATE_CASTING validator that would get in the way of certain tasks, run them on a separate track.
    TaskScheduler separateScheduler;
    bool _canYellKilledPlayer;
    std::unordered_map<ObjectGuid, uint32> _sharedThePain;
};

// http://www.wowhead.com/npc=53495/shard-of-torment
struct npc_shard_of_torment : public NullCreatureAI
{
    npc_shard_of_torment(Creature* creature) : NullCreatureAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoCastAOE(SPELL_TORMENT_PRE_VISUAL);
        scheduler.Schedule(Milliseconds(4400), [this](TaskContext)
        {
            me->RemoveAurasDueToSpell(SPELL_TORMENT_PRE_VISUAL);
            DoCastAOE(SPELL_TORMENT_ACTIVE);
            scheduler.Schedule(Milliseconds(1100), [this](TaskContext context)
            {
                DoCastAOE(SPELL_WAVE_OF_TORMENT);
                context.Repeat(Seconds(1));
            });
        });
    }

    void SpellHitTarget(Unit* /*target*/, const SpellInfo* spell) override
    {
        if (spell->Id != SPELL_TORMENT)
            return;

        scheduler.CancelAll();
        scheduler.Schedule(Milliseconds(1100), [this](TaskContext context)
        {
            DoCastAOE(SPELL_WAVE_OF_TORMENT);
            context.Repeat(Seconds(1));
        });
    }

    void UpdateAI(uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

// http://www.wowhead.com/spell=99342/blades-of-baloroc
class spell_baleroc_blades_of_baleroc : public SpellScript
{
    PrepareSpellScript(spell_baleroc_blades_of_baleroc);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_INFERNO_BLADE, SPELL_DECIMATION_BLADE });
    }

    void ChooseBlade(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster || !caster->IsAIEnabled)
            return;

        switch (urand(1, 2))
        {
            case 1:
                caster->AI()->DoCast(SPELL_INFERNO_BLADE);
                caster->AI()->Talk(SAY_INFERNO_BLADE);
                caster->AI()->Talk(EMOTE_INFERNO_BLADE);
                break;
            case 2:
                caster->AI()->DoCast(SPELL_DECIMATION_BLADE);
                caster->AI()->Talk(SAY_DECIMATION_BLADE);
                caster->AI()->Talk(EMOTE_DECIMATION_BLADE);
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_baleroc_blades_of_baleroc::ChooseBlade, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// http://www.wowhead.com/spell=99350/inferno-blade
class spell_baleroc_inferno_blade : public AuraScript
{
    PrepareAuraScript(spell_baleroc_inferno_blade);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget()->IsAIEnabled)
            GetTarget()->GetAI()->DoAction(ACTION_EQUIP_INFERNO_BLADE);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget()->IsAIEnabled)
            GetTarget()->GetAI()->DoAction(ACTION_EQUIP_DEFAULT);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_baleroc_inferno_blade::OnApply, EFFECT_0, SPELL_AURA_OVERRIDE_AUTOATTACK_WITH_MELEE_SPELL, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_baleroc_inferno_blade::OnRemove, EFFECT_0, SPELL_AURA_OVERRIDE_AUTOATTACK_WITH_MELEE_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// http://www.wowhead.com/spell=99352/decimation-blade
class spell_baleroc_decimation_blade : public AuraScript
{
    PrepareAuraScript(spell_baleroc_decimation_blade);

    bool Load() override
    {
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget()->IsAIEnabled)
            GetTarget()->GetAI()->DoAction(ACTION_EQUIP_DECIMATION_BLADE);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTarget()->IsAIEnabled)
            GetTarget()->GetAI()->DoAction(ACTION_EQUIP_DEFAULT);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_baleroc_decimation_blade::OnApply, EFFECT_1, SPELL_AURA_OVERRIDE_AUTOATTACK_WITH_MELEE_SPELL, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_baleroc_decimation_blade::OnRemove, EFFECT_1, SPELL_AURA_OVERRIDE_AUTOATTACK_WITH_MELEE_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// http://www.wowhead.com/spell=99353/decimating-strike
class spell_baleroc_decimating_strike : public SpellScript
{
    PrepareSpellScript(spell_baleroc_decimating_strike);

    bool Validate(SpellInfo const* spellInfo) override
    {
        if (!spellInfo->GetEffect(EFFECT_0))
            return false;
        SpellEffectInfo const* spellEffectInfo = spellInfo->GetEffect(EFFECT_2);
        return spellEffectInfo && ValidateSpellInfo({ uint32(spellEffectInfo->BasePoints) });
    }

    void ChangeDamage()
    {
        int32 healthPctDmg = GetHitUnit()->CountPctFromMaxHealth(GetSpellInfo()->GetEffect(EFFECT_0)->BasePoints);
        int32 flatDmg = GetSpellInfo()->GetEffect(EFFECT_2)->BasePoints;

        SetHitDamage(healthPctDmg < flatDmg ? flatDmg : healthPctDmg);
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_baleroc_decimating_strike::ChangeDamage);
    }
};

// http://www.wowhead.com/spell=99515/countdown
class spell_baleroc_countdown_aoe_dummy : public SpellScript
{
    PrepareSpellScript(spell_baleroc_countdown_aoe_dummy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_COUNTDOWN_VISUAL_LINK, SPELL_COUNTDOWN_AURA });
    }

    void CastSpellLink()
    {
        Unit* firstTarget = ObjectAccessor::GetUnit(*GetCaster(), _targets.front());
        Unit* secondTarget = ObjectAccessor::GetUnit(*GetCaster(), _targets.back());
        if (!firstTarget || !secondTarget)
            return;

        firstTarget->CastSpell(secondTarget, SPELL_COUNTDOWN_VISUAL_LINK, true);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_COUNTDOWN_AURA);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (WorldObject* tank = GetCaster()->GetVictim())
            targets.remove(tank);

        if (targets.size() < 2)
        {
            FinishCast(SPELL_FAILED_NO_VALID_TARGETS);
            return;
        }

        Trinity::Containers::RandomResize(targets, 2);

        _targets.push_back(targets.front()->GetGUID());
        _targets.push_back(targets.back()->GetGUID());
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_baleroc_countdown_aoe_dummy::CastSpellLink);
        OnEffectHitTarget += SpellEffectFn(spell_baleroc_countdown_aoe_dummy::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_baleroc_countdown_aoe_dummy::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }

    GuidList _targets;
};

// http://www.wowhead.com/spell=99516/countdown
class spell_baleroc_countdown : public AuraScript
{
    PrepareAuraScript(spell_baleroc_countdown);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_COUNTDOWN_VISUAL_LINK, SPELL_COUNTDOWN_AOE_EXPLOSION });
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_COUNTDOWN_VISUAL_LINK);
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            GetTarget()->CastSpell(static_cast<Unit*>(nullptr), SPELL_COUNTDOWN_AOE_EXPLOSION, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_baleroc_countdown::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
    }
};

// http://www.wowhead.com/spell=99517/countdown
class spell_baleroc_countdown_proximity_check : public SpellScript
{
    PrepareSpellScript(spell_baleroc_countdown_proximity_check);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_COUNTDOWN_AURA });
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetCaster()->RemoveAurasDueToSpell(SPELL_COUNTDOWN_AURA);
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_COUNTDOWN_AURA);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove(GetCaster());
        targets.remove_if(Trinity::UnitAuraCheck(false, SPELL_COUNTDOWN_AURA));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_baleroc_countdown_proximity_check::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_baleroc_countdown_proximity_check::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
    }
};

// http://www.wowhead.com/spell=99259/shards-of-torment
class spell_baleroc_shards_of_torment_target_search : public SpellScript
{
    PrepareSpellScript(spell_baleroc_shards_of_torment_target_search);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHARDS_OF_TORMENT_SUMMON });
    }

    bool Load() override
    {
        _hasTarget = false;
        return GetCaster()->GetTypeId() == TYPEID_UNIT;
    }

    void OnSpellCast()
    {
        if (_hasTarget)
            ENSURE_AI(boss_baleroc, GetCaster()->GetAI())->Talk(SAY_SHARDS_OF_TORMENT);
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SHARDS_OF_TORMENT_SUMMON, true);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        // Shards of torment seems to target tanks if no other targets are available as of Warlords of Draenor
        if (targets.size() <= 1)
        {
            _hasTarget = !targets.empty();
            return;
        }

        Unit* caster = GetCaster();
        if (WorldObject* tank = caster->GetVictim())
            targets.remove(tank);

        std::list<WorldObject*> melee, ranged;
        for (WorldObject* target : targets)
        {
            if (caster->IsWithinMeleeRange(target->ToUnit()))
                melee.push_back(target);
            else
                ranged.push_back(target);
        }

        targets.clear();

        if (caster->GetMap()->Is25ManRaid())
            if (WorldObject* target = GetRandomContainerElement(ranged, melee))
                targets.push_back(target);

        if (WorldObject* target = GetRandomContainerElement(melee, ranged))
            targets.push_back(target);

        _hasTarget = !targets.empty();
    }

    WorldObject* GetRandomContainerElement(std::list<WorldObject*>& priority1, std::list<WorldObject*>& priority2) const
    {
        WorldObject* target = nullptr;
        target = GetRandomContainerElement(&priority1);
        if (target)
            priority1.remove(target);
        else
        {
            target = GetRandomContainerElement(&priority2);
            priority2.remove(target);
        }

        return target;
    }

    static WorldObject* GetRandomContainerElement(std::list<WorldObject*> const* list)
    {
        if (!list->empty())
            return Trinity::Containers::SelectRandomContainerElement(*list);

        return nullptr;
    }

    void Register() override
    {
        OnCast += SpellCastFn(spell_baleroc_shards_of_torment_target_search::OnSpellCast);
        OnEffectHitTarget += SpellEffectFn(spell_baleroc_shards_of_torment_target_search::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_baleroc_shards_of_torment_target_search::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }

    bool _hasTarget = false;
};

// http://www.wowhead.com/spell=99253/torment
class spell_baleroc_torment_target_search : public SpellScript
{
    PrepareSpellScript(spell_baleroc_torment_target_search);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TORMENT_PERIODIC });
    }

    void OnHit(SpellEffIndex /*effIndex*/)
    {
        Spell* spell = GetCaster()->GetCurrentSpell(CURRENT_CHANNELED_SPELL);
        if (spell && spell->m_targets.GetUnitTargetGUID() == _target)
            return;

        if (GetHitUnit()->GetGUID() == _target)
            GetCaster()->CastSpell(GetHitUnit(), SPELL_TORMENT_PERIODIC);
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(PlayerCheck());
        if (targets.empty())
            return;

        targets.sort(Trinity::ObjectDistanceOrderPred(GetCaster()));
        _target = targets.front()->GetGUID();
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_baleroc_torment_target_search::OnHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_baleroc_torment_target_search::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }

    ObjectGuid _target;
};

// http://www.wowhead.com/spell=99256/torment
class spell_baleroc_torment : public SpellScript
{
    PrepareSpellScript(spell_baleroc_torment);

    void ModifyDamage()
    {
        SetHitDamage(GetHitDamage() * GetHitUnit()->GetAuraCount(GetSpellInfo()->Id));
    }

    void Register() override
    {
        OnHit += SpellHitFn(spell_baleroc_torment::ModifyDamage);
    }
};

class spell_baleroc_torment_AuraScript : public AuraScript
{
    PrepareAuraScript(spell_baleroc_torment_AuraScript);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VITAL_FLAME, SPELL_VITAL_SPARK, SPELL_TORMENTED });
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        Unit* healer = eventInfo.GetProcTarget();
        if (healer->HasAura(SPELL_VITAL_FLAME))
            return;

        bool is25ManHeroic = healer->GetMap()->IsHeroic() && healer->GetMap()->Is25ManRaid();
        uint32 stacks = healer->GetAuraCount(SPELL_VITAL_SPARK) + std::min(uint8(ceil(GetStackAmount() / (is25ManHeroic ? 5.0 : 3.0))), uint8(255));

        healer->SetAuraStack(SPELL_VITAL_SPARK, healer, stacks);
        if (Aura* aura = healer->GetAura(SPELL_VITAL_SPARK))
            aura->RefreshDuration();
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
            GetTarget()->CastSpell(GetTarget(), SPELL_TORMENTED, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_baleroc_torment_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
        OnEffectRemove += AuraEffectRemoveFn(spell_baleroc_torment_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// http://www.wowhead.com/spell=99257/tormented
class spell_baleroc_tormented : public AuraScript
{
    PrepareAuraScript(spell_baleroc_tormented);

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (InstanceScript* instance = GetTarget()->GetInstanceScript())
            if (Creature* baleroc = ObjectAccessor::GetCreature(*GetTarget(), instance->GetGuidData(DATA_BALEROC)))
                baleroc->AI()->SetGUID(GetTarget()->GetGUID(), GUID_TORMENTED);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_baleroc_tormented::OnApply, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

// http://www.wowhead.com/spell=99489/tormented
class spell_baleroc_tormented_spread : public SpellScript
{
    PrepareSpellScript(spell_baleroc_tormented_spread);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_TORMENTED });
    }

    void HandleScript(SpellEffIndex effIndex)
    {
        PreventHitDefaultEffect(effIndex);
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_TORMENTED, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_baleroc_tormented_spread::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// http://www.wowhead.com/spell=99262/vital-spark
class spell_baleroc_vital_spark : public AuraScript
{
    PrepareAuraScript(spell_baleroc_vital_spark);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_BLAZE_OF_GLORY, SPELL_VITAL_FLAME });
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        if (Unit* target = eventInfo.GetProcTarget())
            if (target->HasAura(SPELL_BLAZE_OF_GLORY))
                GetCaster()->CastSpell(GetCaster(), SPELL_VITAL_FLAME, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_baleroc_vital_spark::HandleProc, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// http://www.wowhead.com/spell=99263/vital-flame
class spell_baleroc_vital_flame : public AuraScript
{
    PrepareAuraScript(spell_baleroc_vital_flame);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_VITAL_SPARK });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster()->HasAura(SPELL_VITAL_SPARK))
        {
            stacks = 0;
            return;
        }

        stacks = GetCaster()->GetAuraCount(SPELL_VITAL_SPARK);
        int32 healingPct = sSpellMgr->AssertSpellInfo(SPELL_VITAL_SPARK, GetCastDifficulty())->GetEffect(EFFECT_0)->BasePoints * stacks;

        if (GetAura()->GetEffect(EFFECT_0)->GetAmount() < healingPct)
            GetAura()->GetEffect(EFFECT_0)->SetAmount(healingPct);

        GetCaster()->RemoveAura(SPELL_VITAL_SPARK);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_EXPIRE)
            GetCaster()->SetAuraStack(SPELL_VITAL_SPARK, GetCaster(), stacks);
    }

    void Register() override
    {
        OnEffectApply += AuraEffectApplyFn(spell_baleroc_vital_flame::OnApply, EFFECT_0, SPELL_AURA_359, AURA_EFFECT_HANDLE_REAL);
        OnEffectRemove += AuraEffectRemoveFn(spell_baleroc_vital_flame::OnRemove, EFFECT_0, SPELL_AURA_359, AURA_EFFECT_HANDLE_REAL);
    }

    uint32 stacks = 0u;
};

// http://www.wowhead.com/achievement=5830/share-the-pain //17577
class achievement_share_the_pain : public AchievementCriteriaScript
{
    public:
        achievement_share_the_pain() : AchievementCriteriaScript("achievement_share_the_pain") { }

        bool OnCheck(Player* /*source*/, Unit* target) override
        {
            if (!target)
                return false;

            return target->GetAI()->GetData(GUID_TORMENTED) == 0;
        }
};

void AddSC_boss_baleroc()
{
    RegisterFirelandsAI(boss_baleroc);
    RegisterFirelandsAI(npc_shard_of_torment);
    RegisterSpellScript(spell_baleroc_blades_of_baleroc);
    RegisterAuraScript(spell_baleroc_inferno_blade);
    RegisterAuraScript(spell_baleroc_decimation_blade);
    RegisterSpellScript(spell_baleroc_decimating_strike);
    RegisterSpellScript(spell_baleroc_countdown_aoe_dummy);
    RegisterAuraScript(spell_baleroc_countdown);
    RegisterSpellScript(spell_baleroc_countdown_proximity_check);
    RegisterSpellScript(spell_baleroc_shards_of_torment_target_search);
    RegisterSpellScript(spell_baleroc_torment_target_search);
    RegisterSpellAndAuraScriptPair(spell_baleroc_torment, spell_baleroc_torment_AuraScript);
    RegisterAuraScript(spell_baleroc_tormented);
    RegisterSpellScript(spell_baleroc_tormented_spread);
    RegisterAuraScript(spell_baleroc_vital_spark);
    RegisterAuraScript(spell_baleroc_vital_flame);
    new achievement_share_the_pain();
};
