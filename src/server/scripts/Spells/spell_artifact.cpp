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
#include "Containers.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "Spell.h"
#include "SpellScript.h"
#include "SpellMgr.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "TemporarySummon.h"

enum SpellIds
{
    SPELL_DRUID_NEW_MOON                            = 202767,
    SPELL_DRUID_NEW_MOON_OVERRIDE                   = 202787,
    SPELL_DRUID_HALF_MOON                           = 202768,
    SPELL_DRUID_HALF_MOON_OVERRIDE                  = 202788,
    SPELL_DRUID_FULL_MOON                           = 202771,
    SPELL_MAGE_IMMOLATION                           = 211918,
    SPELL_MAGE_PHOENIX_FLAMES                       = 194466,
    SPELL_MAGE_PHOENIX_FLAMES_TRIGGER               = 224637,
    SPELL_DH_FURY_OF_THE_ILLIDARI_MH                = 201628,
    SPELL_DH_FURY_OF_THE_ILLIDARI_OH                = 201789,
    SPELL_SHAMAN_CARESS_OF_THE_TIDEMOTHER           = 207354,
    SPELL_SHAMAN_HEALING_STREAM_TOTEM               = 5394,
    SPELL_SHAMAN_REINCARNATION                      = 20608,
    SPELL_SHAMAN_SERVANT_OF_THE_QUEEN               = 207357,
    SPELL_DH_FURY_OF_THE_ILLIDARI_AT                = 202796,
    SPELL_WARLOCK_DEADWIND_HARVERST                 = 216708,
    SPELL_WARLOCK_TORMENTED_SOULS                   = 216695,
    SPELL_WARLOCK_THALKIELS_CONSUMPTION_DAMAGE      = 211715,
    SPELL_WARLOCK_TEAR_CHAOS_BARRAGE                = 187394,
    SPELL_WARLOCK_TEAR_CHAOS_BOLT                   = 215279,
    SPELL_WARLOCK_TEAR_SHADOW_BOLT                  = 196657,
    SPELL_MAGE_BRAIN_FREEZE_AURA                    = 190446
};

// Ebonbolt - 214634
class spell_arti_mage_ebonbolt : public SpellScript
{
    PrepareSpellScript(spell_arti_mage_ebonbolt);

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_MAGE_BRAIN_FREEZE_AURA, true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_arti_mage_ebonbolt::HandleDummy, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
    }
};

// Reap Souls - 216698
class spell_arti_warl_reap_souls : public SpellScriptLoader
{
public:
    spell_arti_warl_reap_souls() : SpellScriptLoader("spell_arti_warl_reap_souls") {}

    class spell_arti_warl_reap_souls_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_arti_warl_reap_souls_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_WARLOCK_DEADWIND_HARVERST, true);
        }

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return SPELL_FAILED_DONT_REPORT;

            if (!caster->HasAura(SPELL_WARLOCK_TORMENTED_SOULS))
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

            return SPELL_CAST_OK;
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_arti_warl_reap_souls_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_arti_warl_reap_souls_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_arti_warl_reap_souls_SpellScript();
    }
};

// Deadwind harvest - 216708
class spell_arti_warl_deadwind_harvest : public SpellScriptLoader
{
public:
    spell_arti_warl_deadwind_harvest() : SpellScriptLoader("spell_arti_warl_deadwind_harvest") {}

    class spell_arti_warl_deadwind_harvest_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_arti_warl_deadwind_harvest_AuraScript);

        void CalcAmount(AuraEffect const* /*aurEff*/, int32& /*amount*/, bool& /*canBeRecalculated*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            int32 stackAmount = 0;
            if (Aura* aur = caster->GetAura(SPELL_WARLOCK_TORMENTED_SOULS))
                stackAmount = aur->GetStackAmount();

            int32 duration = GetAura()->GetDuration() * stackAmount;
            GetAura()->SetMaxDuration(duration);
            GetAura()->SetDuration(duration);

            caster->RemoveAurasDueToSpell(SPELL_WARLOCK_TORMENTED_SOULS);
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_arti_warl_deadwind_harvest_AuraScript::CalcAmount, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_arti_warl_deadwind_harvest_AuraScript();
    }
};

// Phoenix Flames - 194466
class spell_arti_mage_phoenix_flames : public SpellScriptLoader
{
public:
    spell_arti_mage_phoenix_flames() : SpellScriptLoader("spell_arti_mage_phoenix_flames") { }

    class spell_arti_mage_phoenix_flames_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_arti_mage_phoenix_flames_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_MAGE_PHOENIX_FLAMES_TRIGGER, SPELL_MAGE_PHOENIX_FLAMES });
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_MAGE_PHOENIX_FLAMES_TRIGGER, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_arti_mage_phoenix_flames_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_arti_mage_phoenix_flames_SpellScript();
    }
};

// Phoenix Flames Trigger - 224637
class spell_arti_mage_phoenix_flames_trigger : public SpellScriptLoader
{
public:
    spell_arti_mage_phoenix_flames_trigger() : SpellScriptLoader("spell_arti_mage_phoenix_flames_trigger") { }

    class spell_arti_mage_phoenix_flames_trigger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_arti_mage_phoenix_flames_trigger_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_MAGE_PHOENIX_FLAMES_TRIGGER, SPELL_MAGE_PHOENIX_FLAMES });
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* target = GetHitUnit();
            Unit* originalTarget = GetExplTargetUnit();
            if (!target || !originalTarget)
                return;

            if (originalTarget == target)
                SetHitDamage(0);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_arti_mage_phoenix_flames_trigger_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_arti_mage_phoenix_flames_trigger_SpellScript();
    }
};

// Immolation (artifact passive) - 211918
class spell_arti_mage_immolation : public SpellScriptLoader
{
public:
    spell_arti_mage_immolation() : SpellScriptLoader("spell_arti_mage_immolation") {}

    class spell_arti_mage_immolation_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_arti_mage_immolation_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_MAGE_IMMOLATION, SPELL_MAGE_PHOENIX_FLAMES });
        }

    public:

        spell_arti_mage_immolation_AuraScript()
        {
            mod = new SpellModifier(GetAura());
            mod->op = SPELLMOD_CRITICAL_CHANCE;
            mod->type = SPELLMOD_FLAT;
            mod->spellId = SPELL_MAGE_IMMOLATION;
            mod->value = 200;
            mod->mask[3] = 0x20000000;
        }

    private:

        SpellModifier* mod = nullptr;

        void HandleApply(AuraEffect const* /*aurEffect*/, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetCaster()->ToPlayer();
            if (!player)
                return;

            player->AddSpellMod(mod, true);
        }

        void HandleRemove(AuraEffect const* /*aurEffect*/, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetCaster()->ToPlayer();
            if (!player)
                return;

            player->AddSpellMod(mod, false);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_arti_mage_immolation_AuraScript::HandleApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_arti_mage_immolation_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_arti_mage_immolation_AuraScript();
    }
};

// Half Moon - 202768
class spell_arti_dru_half_moon : public SpellScriptLoader
{
public:
    spell_arti_dru_half_moon() : SpellScriptLoader("spell_arti_dru_half_moon") { }

    class spell_arti_dru_half_moon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_arti_dru_half_moon_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_DRUID_HALF_MOON, SPELL_DRUID_HALF_MOON_OVERRIDE });
        }

        void RemoveOverride()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->RemoveAurasDueToSpell(SPELL_DRUID_NEW_MOON_OVERRIDE);
        }

        void Register() override
        {
            AfterCast += SpellCastFn(spell_arti_dru_half_moon_SpellScript::RemoveOverride);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_arti_dru_half_moon_SpellScript();
    }
};

// Fury of the Illidari - 201467
// AreaTriggerID - 5758
class at_dh_fury_of_the_illidari : public AreaTriggerEntityScript
{
public:
    at_dh_fury_of_the_illidari() : AreaTriggerEntityScript("at_dh_fury_of_the_illidari") { }

    struct at_dh_fury_of_the_illidariAI : AreaTriggerAI
    {
        int32 timeInterval;

        at_dh_fury_of_the_illidariAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            // How often should the action be executed
            timeInterval = 420; // Blaze it (blizzard wtf, 7 times under 3 seconds)
        }

        void OnCreate() override
        {
            at->SetDuration(3000);
        }

        void OnUpdate(uint32 p_Time) override
        {
            Unit* caster = at->GetCaster();
            if (!caster)
                return;

            if (caster->GetTypeId() != TYPEID_PLAYER)
                return;

            // Check if we can handle actions
            timeInterval += p_Time;
            if (timeInterval < 420)
                return;

            if (TempSummon* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPositionX(), at->GetPositionY(), at->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 1 * IN_MILLISECONDS))
            {
                tempSumm->setFaction(caster->getFaction());
                tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                tempSumm->CopyPhaseFrom(caster);
                caster->CastSpell(tempSumm, SPELL_DH_FURY_OF_THE_ILLIDARI_MH, true);
                caster->CastSpell(tempSumm, SPELL_DH_FURY_OF_THE_ILLIDARI_OH, true);
            }

            timeInterval -= 420;
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_dh_fury_of_the_illidariAI(areatrigger);
    }
};

//207357 - Servant of the queen
class spell_arti_sha_servant_of_the_queen : public SpellScriptLoader
{
public:
    spell_arti_sha_servant_of_the_queen() : SpellScriptLoader("spell_arti_sha_servant_of_the_queen") { }

    class spell_arti_sha_servant_of_the_queen_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_arti_sha_servant_of_the_queen_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (!eventInfo.GetSpellInfo())
                return false;

            if(eventInfo.GetSpellInfo()->Id == SPELL_SHAMAN_REINCARNATION)
                return true;
            else
                return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_arti_sha_servant_of_the_queen_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_arti_sha_servant_of_the_queen_AuraScript();
    }
};

//207354 - Caress of the tidemother
class spell_arti_sha_caress_of_the_tidemother : public SpellScriptLoader
{
public:
    spell_arti_sha_caress_of_the_tidemother() : SpellScriptLoader("spell_arti_sha_caress_of_the_tidemother") { }

    class spell_arti_sha_caress_of_the_tidemother_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_arti_sha_caress_of_the_tidemother_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if(!eventInfo.GetSpellInfo())
                return false;

            if(eventInfo.GetSpellInfo()->Id == SPELL_SHAMAN_HEALING_STREAM_TOTEM)
                return true;
            else
                return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_arti_sha_caress_of_the_tidemother_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_arti_sha_caress_of_the_tidemother_AuraScript();
    }
};

// Dimensional Rift - 196586
class spell_arti_warl_dimensional_rift : public SpellScriptLoader
{
public:
    spell_arti_warl_dimensional_rift() : SpellScriptLoader("spell_arti_warl_dimensional_rift") {}

    class spell_arti_warl_dimensional_rift_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_arti_warl_dimensional_rift_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

                                                  //green //green //purple
            std::vector<uint32> spellVisualIds = { 219117, 219117, 219107 };
                                          // Chaos Tear  //Chaos Portal  //Shadowy Tear
            std::vector<uint32> summonIds = { 108493,        108493,          99887 };
            // Durations must be longer, because if the npc gets destroyed before the last projectile hits
            // it won't deal any damage.
            std::vector<uint32> durations = { 7000, 4500, 16000 };
            uint32 id = std::rand() % 3;
            Position pos = caster->GetPosition();
            caster->MovePosition(pos, (float)(std::rand() % 5) + 4.f, (float)rand_norm() * static_cast<float>(2 * M_PI));
            if (TempSummon* rift = caster->SummonCreature(summonIds[id], pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, durations[id]))
            {
                rift->CastSpell(rift, spellVisualIds[id], true);
                rift->SetOwnerGUID(caster->GetGUID());
                rift->SetTarget(target->GetGUID());
                // We use same ID and script for Chaos Portal and Chaos Tear as there are no more NPCs for this spell
                rift->SetArmor(id);
            }
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_arti_warl_dimensional_rift_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_arti_warl_dimensional_rift_SpellScript();
    }
};

// Thal'kiel's Consumption - 211714
class spell_arti_warl_thalkiels_consumption : public SpellScriptLoader
{
public:
    spell_arti_warl_thalkiels_consumption() : SpellScriptLoader("spell_arti_warl_thalkiels_consumption") {}

    class spell_arti_warl_thalkiels_consumption_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_arti_warl_thalkiels_consumption_SpellScript);

        int32 damage = 0;

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!target || !caster)
                return;

            caster->CastCustomSpell(SPELL_WARLOCK_THALKIELS_CONSUMPTION_DAMAGE, SPELLVALUE_BASE_POINT0, damage, target, TRIGGERED_FULL_MASK);
        }

        void SaveDamage(std::list<WorldObject*>& targets)
        {
            targets.remove_if([](WorldObject* target)
            {
                if (!target->ToUnit())
                    return true;
                // Remove Gateways
                if (target->ToCreature()->GetCreatureType() != CREATURE_TYPE_DEMON)
                    return true;

                return false;
            });

            int32 basePoints = GetSpellInfo()->GetEffect(EFFECT_1)->BasePoints;
            for (WorldObject* pet : targets)
                damage += pet->ToUnit()->CountPctFromMaxHealth(basePoints);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_arti_warl_thalkiels_consumption_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_arti_warl_thalkiels_consumption_SpellScript::SaveDamage, EFFECT_1, 0/*TARGET_UNIT_CASTER_PET*/);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_arti_warl_thalkiels_consumption_SpellScript();
    }
};


// Chaos Tear - 108493
class npc_warl_chaos_tear : public CreatureScript
{
public:
    npc_warl_chaos_tear() : CreatureScript("npc_warl_chaos_tear") { }

    struct npc_warl_chaos_tearAI : public ScriptedAI
    {
        npc_warl_chaos_tearAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        int32 timer = 0;
        int32 counter = 0;

        void UpdateAI(uint32 diff) override

        {
            timer += diff;
            switch (me->GetArmor())
            {
            case 0:
                if (counter >= 22)
                    return;
                if (timer >= 250)
                {
                    timer -= 250;
                    ObjectGuid targetGuid = me->GetTarget();
                    ObjectGuid casterGuid = me->GetOwnerGUID();
                    if (targetGuid.IsEmpty() || casterGuid.IsEmpty())
                        return;
                    Unit* caster = ObjectAccessor::GetUnit(*me, casterGuid);
                    Unit* target = ObjectAccessor::GetUnit(*me, targetGuid);
                    if (!caster || !target)
                        return;

                    me->CastSpell(target, SPELL_WARLOCK_TEAR_CHAOS_BARRAGE, true, nullptr, nullptr, caster->GetGUID());
                    counter++;
                }
                break;
            case 1:
                if (timer >= 1500)
                {
                    timer -= 9000;
                    ObjectGuid targetGuid = me->GetTarget();
                    ObjectGuid casterGuid = me->GetOwnerGUID();
                    if (targetGuid.IsEmpty() || casterGuid.IsEmpty())
                        return;
                    Unit* caster = ObjectAccessor::GetUnit(*me, casterGuid);
                    Unit* target = ObjectAccessor::GetUnit(*me, targetGuid);
                    if (!caster || !target)
                        return;

                    me->CastSpell(target, SPELL_WARLOCK_TEAR_CHAOS_BOLT, true, nullptr, nullptr, caster->GetGUID());
                }
                break;
            default:
                break;
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new npc_warl_chaos_tearAI(p_Creature);
    }
};

// Shadowy Tear - 99887
class npc_warl_shadowy_tear : public CreatureScript
{
public:
    npc_warl_shadowy_tear() : CreatureScript("npc_warl_shadowy_tear") { }

    struct npc_warl_shadowy_tearAI : public ScriptedAI
    {
        npc_warl_shadowy_tearAI(Creature* p_Creature) : ScriptedAI(p_Creature) { }

        int32 timer = 0;
        int32 counter = 0;

        void UpdateAI(uint32 diff) override

        {
            if (counter >= 7)
                return;

            timer += diff;
            if (timer >= 2000)
            {
                timer -= 2000;
                ObjectGuid targetGuid = me->GetTarget();
                ObjectGuid casterGuid = me->GetOwnerGUID();
                if (targetGuid.IsEmpty() || casterGuid.IsEmpty())
                    return;
                Unit* caster = ObjectAccessor::GetUnit(*me, casterGuid);
                Unit* target = ObjectAccessor::GetUnit(*me, targetGuid);
                if (!caster || !target)
                    return;

                me->CastSpell(target, SPELL_WARLOCK_TEAR_SHADOW_BOLT, true, nullptr, nullptr, caster->GetGUID());
                counter++;
            }
        }
    };

    CreatureAI* GetAI(Creature* p_Creature) const override
    {
        return new npc_warl_shadowy_tearAI(p_Creature);
    }
};

void AddSC_artifact_spell_scripts()
{
    new spell_arti_dru_half_moon();

    new spell_arti_mage_immolation();
    new spell_arti_mage_phoenix_flames();
    new spell_arti_mage_phoenix_flames_trigger();

    new spell_arti_sha_servant_of_the_queen();
    new spell_arti_sha_caress_of_the_tidemother();

    new spell_arti_warl_deadwind_harvest();
    new spell_arti_warl_reap_souls();
    new spell_arti_warl_dimensional_rift();
    new npc_warl_chaos_tear();
    new npc_warl_shadowy_tear();
    new spell_arti_warl_thalkiels_consumption();

    /// AreaTrigger scripts
    new at_dh_fury_of_the_illidari();

    RegisterSpellScript(spell_arti_mage_ebonbolt);
}
