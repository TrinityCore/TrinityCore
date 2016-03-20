/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

/*
 * Scripts for spells with SPELLFAMILY_DEATHKNIGHT and SPELLFAMILY_GENERIC spells used by deathknight players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dk_".
 */

#include "Player.h"
#include "PlayerAI.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "Containers.h"

enum DeathKnightSpells
{
    SPELL_DK_ANTI_MAGIC_SHELL_TALENT            = 51052,
    SPELL_DK_BLACK_ICE_R1                       = 49140,
    SPELL_DK_BLOOD_BOIL_TRIGGERED               = 65658,
    SPELL_DK_BLOOD_GORGED_HEAL                  = 50454,
    SPELL_DK_BLOOD_PRESENCE                     = 48266,
    SPELL_DK_CORPSE_EXPLOSION_TRIGGERED         = 43999,
    SPELL_DK_CORPSE_EXPLOSION_VISUAL            = 51270,
    SPELL_DK_DEATH_AND_DECAY_DAMAGE             = 52212,
    SPELL_DK_DEATH_COIL_DAMAGE                  = 47632,
    SPELL_DK_DEATH_COIL_HEAL                    = 47633,
    SPELL_DK_DEATH_GRIP                         = 49560,
    SPELL_DK_DEATH_STRIKE_HEAL                  = 45470,
    SPELL_DK_FROST_FEVER                        = 55095,
    SPELL_DK_FROST_PRESENCE                     = 48263,
    SPELL_DK_FROST_PRESENCE_TRIGGERED           = 61261,
    SPELL_DK_GHOUL_EXPLODE                      = 47496,
    SPELL_DK_GLYPH_OF_DISEASE                   = 63334,
    SPELL_DK_GLYPH_OF_ICEBOUND_FORTITUDE        = 58625,
    SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1         = 50365,
    SPELL_DK_IMPROVED_FROST_PRESENCE_R1         = 50384,
    SPELL_DK_IMPROVED_UNHOLY_PRESENCE_R1        = 50391,
    SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED  = 63611,
    SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED = 63622,
    SPELL_DK_ITEM_SIGIL_VENGEFUL_HEART          = 64962,
    SPELL_DK_ITEM_T8_MELEE_4P_BONUS             = 64736,
    SPELL_DK_MASTER_OF_GHOULS                   = 52143,
    SPELL_DK_BLOOD_PLAGUE                       = 55078,
    SPELL_DK_RAISE_DEAD_USE_REAGENT             = 48289,
    SPELL_DK_RUNIC_POWER_ENERGIZE               = 49088,
    SPELL_DK_SCENT_OF_BLOOD                     = 50422,
    SPELL_DK_SCOURGE_STRIKE_TRIGGERED           = 70890,
    SPELL_DK_UNHOLY_PRESENCE                    = 48265,
    SPELL_DK_UNHOLY_PRESENCE_TRIGGERED          = 49772,
    SPELL_DK_WILL_OF_THE_NECROPOLIS_TALENT_R1   = 49189,
    SPELL_DK_WILL_OF_THE_NECROPOLIS_AURA_R1     = 52284,
    SPELL_DK_GHOUL_THRASH                       = 47480
};

enum DeathKnightSpellIcons
{
    DK_ICON_ID_IMPROVED_DEATH_STRIKE            = 2751
};

enum Misc
{
    NPC_DK_GHOUL                                = 26125
};

// 50462 - Anti-Magic Shell (on raid member)
class spell_dk_anti_magic_shell_raid : public SpellScriptLoader
{
    public:
        spell_dk_anti_magic_shell_raid() : SpellScriptLoader("spell_dk_anti_magic_shell_raid") { }

        class spell_dk_anti_magic_shell_raid_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_anti_magic_shell_raid_AuraScript);

        public:
            spell_dk_anti_magic_shell_raid_AuraScript()
            {
                absorbPct = 0;
            }

        private:
            uint32 absorbPct;

            bool Load() override
            {
                absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                /// @todo this should absorb limited amount of damage, but no info on calculation formula
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_shell_raid_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_raid_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_anti_magic_shell_raid_AuraScript();
        }
};

// 48707 - Anti-Magic Shell (on self)
class spell_dk_anti_magic_shell_self : public SpellScriptLoader
{
    public:
        spell_dk_anti_magic_shell_self() : SpellScriptLoader("spell_dk_anti_magic_shell_self") { }

        class spell_dk_anti_magic_shell_self_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_anti_magic_shell_self_AuraScript);

        public:
            spell_dk_anti_magic_shell_self_AuraScript()
            {
                absorbPct = 0;
                hpPct = 0;
            }

        private:
            uint32 absorbPct, hpPct;
            bool Load() override
            {
                absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
                hpPct = GetSpellInfo()->Effects[EFFECT_1].CalcValue(GetCaster());
                return true;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_RUNIC_POWER_ENERGIZE))
                    return false;
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                amount = GetCaster()->CountPctFromMaxHealth(hpPct);
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                absorbAmount = std::min(CalculatePct(dmgInfo.GetDamage(), absorbPct), GetTarget()->CountPctFromMaxHealth(hpPct));
            }

            void Trigger(AuraEffect* aurEff, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
            {
                // damage absorbed by Anti-Magic Shell energizes the DK with additional runic power.
                // This, if I'm not mistaken, shows that we get back ~20% of the absorbed damage as runic power.
                int32 bp = CalculatePct(absorbAmount, 20);
                GetTarget()->CastCustomSpell(SPELL_DK_RUNIC_POWER_ENERGIZE, SPELLVALUE_BASE_POINT0, bp, GetTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_shell_self_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_self_AuraScript::Absorb, EFFECT_0);
                AfterEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_self_AuraScript::Trigger, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_anti_magic_shell_self_AuraScript();
        }
};

// 50461 - Anti-Magic Zone
class spell_dk_anti_magic_zone : public SpellScriptLoader
{
    public:
        spell_dk_anti_magic_zone() : SpellScriptLoader("spell_dk_anti_magic_zone") { }

        class spell_dk_anti_magic_zone_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_anti_magic_zone_AuraScript);

        public:
            spell_dk_anti_magic_zone_AuraScript()
            {
                absorbPct = 0;
            }

        private:
            uint32 absorbPct;

            bool Load() override
            {
                absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
                return true;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_ANTI_MAGIC_SHELL_TALENT))
                    return false;
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                SpellInfo const* talentSpell = sSpellMgr->EnsureSpellInfo(SPELL_DK_ANTI_MAGIC_SHELL_TALENT);
                amount = talentSpell->Effects[EFFECT_0].CalcValue(GetCaster());
                if (Player* player = GetCaster()->ToPlayer())
                     amount += int32(2 * player->GetTotalAttackPowerValue(BASE_ATTACK));
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                 absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
            }

            void Register() override
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_zone_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                 OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_zone_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_anti_magic_zone_AuraScript();
        }
};

// 48721 - Blood Boil
class spell_dk_blood_boil : public SpellScriptLoader
{
    public:
        spell_dk_blood_boil() : SpellScriptLoader("spell_dk_blood_boil") { }

        class spell_dk_blood_boil_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_blood_boil_SpellScript);

        public:
            spell_dk_blood_boil_SpellScript()
            {
                _executed = false;
            }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_BOIL_TRIGGERED))
                    return false;
                return true;
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER && GetCaster()->getClass() == CLASS_DEATH_KNIGHT;
            }

            void HandleAfterHit()
            {
                if (_executed || !GetHitUnit())
                    return;

                _executed = true;
                GetCaster()->CastSpell(GetCaster(), SPELL_DK_BLOOD_BOIL_TRIGGERED, true);
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_dk_blood_boil_SpellScript::HandleAfterHit);
            }

            bool _executed;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_blood_boil_SpellScript();
        }
};

// 50453 - Bloodworms Health Leech
class spell_dk_blood_gorged : public SpellScriptLoader
{
    public:
        spell_dk_blood_gorged() : SpellScriptLoader("spell_dk_blood_gorged") { }

        class spell_dk_blood_gorged_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_blood_gorged_AuraScript);

        public:
            spell_dk_blood_gorged_AuraScript()
            {
                _procTarget = nullptr;
            }

        private:
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_GORGED_HEAL))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                _procTarget = GetTarget()->GetOwner();
                return _procTarget != nullptr;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 bp = int32(eventInfo.GetDamageInfo()->GetDamage() * 1.5f);
                GetTarget()->CastCustomSpell(SPELL_DK_BLOOD_GORGED_HEAL, SPELLVALUE_BASE_POINT0, bp, _procTarget, true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dk_blood_gorged_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_dk_blood_gorged_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }

        private:
            Unit* _procTarget;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_blood_gorged_AuraScript();
        }
};

// -49027 - Bloodworms
class spell_dk_bloodworms : public SpellScriptLoader
{
    public:
        spell_dk_bloodworms() : SpellScriptLoader("spell_dk_bloodworms") { }

        class spell_dk_bloodworms_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_bloodworms_AuraScript);

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                aurEff->GetBase()->RecalculateAmountOfEffects();
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dk_bloodworms_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_bloodworms_AuraScript();
        }
};

class CorpseExplosionCheck
{
public:
    explicit CorpseExplosionCheck(ObjectGuid casterGUID, bool allowGhoul) : _casterGUID(casterGUID),
        _allowGhoul(allowGhoul) { }

    bool operator()(WorldObject* obj) const
    {
        if (Unit* target = obj->ToUnit())
        {
            if ((target->isDead() || (_allowGhoul && target->GetEntry() == NPC_DK_GHOUL && target->GetOwnerGUID() == _casterGUID))
                && !(target->GetCreatureTypeMask() & CREATURE_TYPEMASK_MECHANICAL_OR_ELEMENTAL)
                && target->GetDisplayId() == target->GetNativeDisplayId())
                return false;
        }

        return true;
    }

private:
    ObjectGuid _casterGUID;
    bool _allowGhoul;
};

// 49158 - Corpse Explosion (51325, 51326, 51327, 51328)
class spell_dk_corpse_explosion : public SpellScriptLoader
{
    public:
        spell_dk_corpse_explosion() : SpellScriptLoader("spell_dk_corpse_explosion") { }

        class spell_dk_corpse_explosion_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_corpse_explosion_SpellScript);

        public:
            spell_dk_corpse_explosion_SpellScript()
            {
                _target = nullptr;
            }

        private:
            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_CORPSE_EXPLOSION_TRIGGERED)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_GHOUL_EXPLODE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_CORPSE_EXPLOSION_VISUAL)
                    || !sSpellMgr->GetSpellInfo(spellInfo->Effects[EFFECT_1].CalcValue()))
                    return false;
                return true;
            }

            void CheckTarget(WorldObject*& target)
            {
                if (CorpseExplosionCheck(GetCaster()->GetGUID(), true)(target))
                    target = NULL;

                _target = target;
            }

            void CheckTargets(std::list<WorldObject*>& targets)
            {
                WorldObject* target = _target;
                if (!target)
                {
                    targets.remove_if(CorpseExplosionCheck(GetCaster()->GetGUID(), false));
                    if (targets.empty())
                    {
                        FinishCast(SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW);
                        return;
                    }
                    target = Trinity::Containers::SelectRandomContainerElement(targets);
                    targets.clear();
                    targets.push_back(target);
                }
                else
                    targets.clear();
            }

            void HandleDamage(SpellEffIndex effIndex, Unit* target)
            {
                if (effIndex == EFFECT_0)
                    GetCaster()->CastCustomSpell(GetSpellInfo()->Effects[EFFECT_1].CalcValue(), SPELLVALUE_BASE_POINT0, GetEffectValue(), target, true);
                else if (effIndex == EFFECT_1)
                    GetCaster()->CastCustomSpell(GetEffectValue(), SPELLVALUE_BASE_POINT0, GetSpell()->CalculateDamage(EFFECT_0, NULL), target, true);
            }

            void HandleCorpseExplosion(SpellEffIndex effIndex)
            {
                if (Unit* unitTarget = GetHitUnit())
                {
                    if (unitTarget->IsAlive())  // Living ghoul as a target
                    {
                        unitTarget->CastSpell(unitTarget, SPELL_DK_GHOUL_EXPLODE, false);
                        // Corpse Explosion (Suicide) and Set corpse look handled in SpellScript of SPELL_DK_GHOUL_EXPLODE
                    }
                    else                        // Some corpse
                    {
                        HandleDamage(effIndex, unitTarget);
                        // Corpse Explosion (Suicide)
                        unitTarget->CastSpell(unitTarget, SPELL_DK_CORPSE_EXPLOSION_TRIGGERED, true);
                        // Set corpse look
                        GetCaster()->CastSpell(unitTarget, SPELL_DK_CORPSE_EXPLOSION_VISUAL, true);
                    }
                }
            }

            void Register() override
            {
                OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_dk_corpse_explosion_SpellScript::CheckTarget, EFFECT_0, TARGET_UNIT_TARGET_ANY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dk_corpse_explosion_SpellScript::CheckTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENTRY);
                OnEffectHitTarget += SpellEffectFn(spell_dk_corpse_explosion_SpellScript::HandleCorpseExplosion, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnEffectHitTarget += SpellEffectFn(spell_dk_corpse_explosion_SpellScript::HandleCorpseExplosion, EFFECT_1, SPELL_EFFECT_DUMMY);
            }

        private:
            WorldObject* _target;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_corpse_explosion_SpellScript();
        }
};

class spell_dk_death_and_decay : public SpellScriptLoader
{
    public:
        spell_dk_death_and_decay() : SpellScriptLoader("spell_dk_death_and_decay") { }

        class spell_dk_death_and_decay_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_death_and_decay_AuraScript);

            void HandleDummyTick(AuraEffect const* aurEff)
            {
                if (Unit* caster = GetCaster())
                    caster->CastCustomSpell(SPELL_DK_DEATH_AND_DECAY_DAMAGE, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_dk_death_and_decay_AuraScript::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_death_and_decay_AuraScript();
        }
};

// -47541, 52375, 59134, -62900 - Death Coil
class spell_dk_death_coil : public SpellScriptLoader
{
    public:
        spell_dk_death_coil() : SpellScriptLoader("spell_dk_death_coil") { }

        class spell_dk_death_coil_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_coil_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_DEATH_COIL_DAMAGE) || !sSpellMgr->GetSpellInfo(SPELL_DK_DEATH_COIL_HEAL))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                int32 damage = GetEffectValue();
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    if (caster->IsFriendlyTo(target))
                    {
                        int32 bp = int32(damage * 1.5f);
                        caster->CastCustomSpell(target, SPELL_DK_DEATH_COIL_HEAL, &bp, NULL, NULL, true);
                    }
                    else
                    {
                        if (AuraEffect const* auraEffect = caster->GetAuraEffect(SPELL_DK_ITEM_SIGIL_VENGEFUL_HEART, EFFECT_1))
                            damage += auraEffect->GetBaseAmount();
                        caster->CastCustomSpell(target, SPELL_DK_DEATH_COIL_DAMAGE, &damage, NULL, NULL, true);
                    }
                }
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetExplTargetUnit())
                {
                    if (!caster->IsFriendlyTo(target) && !caster->isInFront(target))
                        return SPELL_FAILED_UNIT_NOT_INFRONT;

                    if (target->IsFriendlyTo(caster) && target->GetCreatureType() != CREATURE_TYPE_UNDEAD)
                        return SPELL_FAILED_BAD_TARGETS;
                }
                else
                    return SPELL_FAILED_BAD_TARGETS;

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_death_coil_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_coil_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_coil_SpellScript();
        }
};

// 52751 - Death Gate
class spell_dk_death_gate : public SpellScriptLoader
{
    public:
        spell_dk_death_gate() : SpellScriptLoader("spell_dk_death_gate") { }

        class spell_dk_death_gate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_gate_SpellScript);

            SpellCastResult CheckClass()
            {
                if (GetCaster()->getClass() != CLASS_DEATH_KNIGHT)
                {
                    SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_MUST_BE_DEATH_KNIGHT);
                    return SPELL_FAILED_CUSTOM_ERROR;
                }

                return SPELL_CAST_OK;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, GetEffectValue(), false);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_death_gate_SpellScript::CheckClass);
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_gate_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_gate_SpellScript();
        }
};

// 49560 - Death Grip
class spell_dk_death_grip : public SpellScriptLoader
{
    public:
        spell_dk_death_grip() : SpellScriptLoader("spell_dk_death_grip") { }

        class spell_dk_death_grip_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_grip_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                int32 damage = GetEffectValue();
                Position const* pos = GetExplTargetDest();
                if (Unit* target = GetHitUnit())
                {
                    if (!target->HasAuraType(SPELL_AURA_DEFLECT_SPELLS)) // Deterrence
                        target->CastSpell(pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), damage, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_grip_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_grip_SpellScript();
        }
};

// 48743 - Death Pact
class spell_dk_death_pact : public SpellScriptLoader
{
    public:
        spell_dk_death_pact() : SpellScriptLoader("spell_dk_death_pact") { }

        class spell_dk_death_pact_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_pact_SpellScript);

            SpellCastResult CheckCast()
            {
                // Check if we have valid targets, otherwise skip spell casting here
                if (Player* player = GetCaster()->ToPlayer())
                    for (Unit::ControlList::const_iterator itr = player->m_Controlled.begin(); itr != player->m_Controlled.end(); ++itr)
                        if (Creature* undeadPet = (*itr)->ToCreature())
                            if (undeadPet->IsAlive() &&
                                undeadPet->GetOwnerGUID() == player->GetGUID() &&
                                undeadPet->GetCreatureType() == CREATURE_TYPE_UNDEAD &&
                                undeadPet->IsWithinDist(player, 100.0f, false))
                                return SPELL_CAST_OK;

                return SPELL_FAILED_NO_PET;
            }

            void FilterTargets(std::list<WorldObject*>& targetList)
            {
                Unit* target = NULL;
                for (std::list<WorldObject*>::iterator itr = targetList.begin(); itr != targetList.end(); ++itr)
                {
                    if (Unit* unit = (*itr)->ToUnit())
                        if (unit->GetOwnerGUID() == GetCaster()->GetGUID() && unit->GetCreatureType() == CREATURE_TYPE_UNDEAD)
                        {
                            target = unit;
                            break;
                        }
                }

                targetList.clear();
                if (target)
                    targetList.push_back(target);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_death_pact_SpellScript::CheckCast);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dk_death_pact_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_pact_SpellScript();
        }
};

// -49998 - Death Strike
class spell_dk_death_strike : public SpellScriptLoader
{
    public:
        spell_dk_death_strike() : SpellScriptLoader("spell_dk_death_strike") { }

        class spell_dk_death_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_strike_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_DEATH_STRIKE_HEAL))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    uint32 count = target->GetDiseasesByCaster(caster->GetGUID());
                    int32 bp = int32(count * caster->CountPctFromMaxHealth(int32(GetSpellInfo()->Effects[EFFECT_0].DamageMultiplier)));
                    // Improved Death Strike
                    if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_DEATHKNIGHT, DK_ICON_ID_IMPROVED_DEATH_STRIKE, 0))
                        AddPct(bp, caster->CalculateSpellDamage(caster, aurEff->GetSpellInfo(), 2));
                    caster->CastCustomSpell(caster, SPELL_DK_DEATH_STRIKE_HEAL, &bp, NULL, NULL, false);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_strike_SpellScript::HandleDummy, EFFECT_2, SPELL_EFFECT_DUMMY);
            }

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_strike_SpellScript();
        }
};

// 47496 - Explode, Ghoul spell for Corpse Explosion
class spell_dk_ghoul_explode : public SpellScriptLoader
{
    public:
        spell_dk_ghoul_explode() : SpellScriptLoader("spell_dk_ghoul_explode") { }

        class spell_dk_ghoul_explode_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_ghoul_explode_SpellScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_CORPSE_EXPLOSION_TRIGGERED)
                    || spellInfo->Effects[EFFECT_2].CalcValue() <= 0)
                    return false;
                return true;
            }

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                int32 value = int32(GetCaster()->CountPctFromMaxHealth(GetSpellInfo()->Effects[EFFECT_2].CalcValue(GetCaster())));
                SetEffectValue(value);
            }

            void Suicide(SpellEffIndex /*effIndex*/)
            {
                if (Unit* unitTarget = GetHitUnit())
                {
                    // Corpse Explosion (Suicide)
                    unitTarget->CastSpell(unitTarget, SPELL_DK_CORPSE_EXPLOSION_TRIGGERED, true);
                    // Set corpse look
                    GetCaster()->CastSpell(unitTarget, SPELL_DK_CORPSE_EXPLOSION_VISUAL, true);
                }
            }

            void Register() override
            {
                OnEffectLaunchTarget += SpellEffectFn(spell_dk_ghoul_explode_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_dk_ghoul_explode_SpellScript::Suicide, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_ghoul_explode_SpellScript();
        }
};

// 48792 - Icebound Fortitude
class spell_dk_icebound_fortitude : public SpellScriptLoader
{
    public:
        spell_dk_icebound_fortitude() : SpellScriptLoader("spell_dk_icebound_fortitude") { }

        class spell_dk_icebound_fortitude_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_icebound_fortitude_AuraScript);

            bool Load() override
            {
                Unit* caster = GetCaster();
                return caster && caster->GetTypeId() == TYPEID_PLAYER;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                {
                    int32 value = amount;
                    uint32 defValue = uint32(caster->ToPlayer()->GetSkillValue(SKILL_DEFENSE) + caster->ToPlayer()->GetRatingBonusValue(CR_DEFENSE_SKILL));

                    if (defValue > 400)
                        value -= int32((defValue - 400) * 0.15);

                    // Glyph of Icebound Fortitude
                    if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_DK_GLYPH_OF_ICEBOUND_FORTITUDE, EFFECT_0))
                    {
                        int32 valMax = -aurEff->GetAmount();
                        if (value > valMax)
                            value = valMax;
                    }
                    amount = value;
                }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_icebound_fortitude_AuraScript::CalculateAmount, EFFECT_2, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_icebound_fortitude_AuraScript();
        }
};

// -50365 - Improved Blood Presence
class spell_dk_improved_blood_presence : public SpellScriptLoader
{
    public:
        spell_dk_improved_blood_presence() : SpellScriptLoader("spell_dk_improved_blood_presence") { }

        class spell_dk_improved_blood_presence_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_improved_blood_presence_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_PRESENCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_FROST_PRESENCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_UNHOLY_PRESENCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED))
                    return false;
                return true;
            }

            void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if ((target->HasAura(SPELL_DK_FROST_PRESENCE) || target->HasAura(SPELL_DK_UNHOLY_PRESENCE)) && !target->HasAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED))
                    target->CastCustomSpell(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED, SPELLVALUE_BASE_POINT1, aurEff->GetAmount(), target, true, NULL, aurEff);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (!target->HasAura(SPELL_DK_BLOOD_PRESENCE))
                    target->RemoveAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dk_improved_blood_presence_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dk_improved_blood_presence_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_improved_blood_presence_AuraScript();
        }
};

// -50384 - Improved Frost Presence
class spell_dk_improved_frost_presence : public SpellScriptLoader
{
    public:
        spell_dk_improved_frost_presence() : SpellScriptLoader("spell_dk_improved_frost_presence") { }

        class spell_dk_improved_frost_presence_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_improved_frost_presence_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_PRESENCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_FROST_PRESENCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_UNHOLY_PRESENCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_FROST_PRESENCE_TRIGGERED))
                    return false;
                return true;
            }

            void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if ((target->HasAura(SPELL_DK_BLOOD_PRESENCE) || target->HasAura(SPELL_DK_UNHOLY_PRESENCE)) && !target->HasAura(SPELL_DK_FROST_PRESENCE_TRIGGERED))
                    target->CastCustomSpell(SPELL_DK_FROST_PRESENCE_TRIGGERED, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), target, true, NULL, aurEff);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (!target->HasAura(SPELL_DK_FROST_PRESENCE))
                    target->RemoveAura(SPELL_DK_FROST_PRESENCE_TRIGGERED);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dk_improved_frost_presence_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dk_improved_frost_presence_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_improved_frost_presence_AuraScript();
        }
};

// -50391 - Improved Unholy Presence
class spell_dk_improved_unholy_presence : public SpellScriptLoader
{
    public:
        spell_dk_improved_unholy_presence() : SpellScriptLoader("spell_dk_improved_unholy_presence") { }

        class spell_dk_improved_unholy_presence_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_improved_unholy_presence_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_PRESENCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_FROST_PRESENCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_UNHOLY_PRESENCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_UNHOLY_PRESENCE_TRIGGERED))
                    return false;
                return true;
            }

            void HandleEffectApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (target->HasAura(SPELL_DK_UNHOLY_PRESENCE) && !target->HasAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED))
                {
                    // Not listed as any effect, only base points set in dbc
                    int32 basePoints = GetSpellInfo()->Effects[EFFECT_1].CalcValue();
                    target->CastCustomSpell(target, SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED, &basePoints, &basePoints, &basePoints, true, NULL, aurEff);
                }

                if ((target->HasAura(SPELL_DK_BLOOD_PRESENCE) || target->HasAura(SPELL_DK_FROST_PRESENCE)) && !target->HasAura(SPELL_DK_UNHOLY_PRESENCE_TRIGGERED))
                    target->CastCustomSpell(SPELL_DK_UNHOLY_PRESENCE_TRIGGERED, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), target, true, NULL, aurEff);
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                target->RemoveAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED);

                if (!target->HasAura(SPELL_DK_UNHOLY_PRESENCE))
                    target->RemoveAura(SPELL_DK_UNHOLY_PRESENCE_TRIGGERED);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dk_improved_unholy_presence_AuraScript::HandleEffectApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dk_improved_unholy_presence_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_improved_unholy_presence_AuraScript();
        }
};

// ID - 50842 Pestilence
class spell_dk_pestilence : public SpellScriptLoader
{
    public:
        spell_dk_pestilence() : SpellScriptLoader("spell_dk_pestilence") { }

        class spell_dk_pestilence_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_pestilence_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_GLYPH_OF_DISEASE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_PLAGUE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_FROST_FEVER))
                    return false;
                return true;
            }

            void OnHit(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Unit* hitUnit = GetHitUnit();
                Unit* victim = GetExplTargetUnit();

                if (!victim)
                    return;

                if (victim != hitUnit || caster->HasAura(SPELL_DK_GLYPH_OF_DISEASE))
                {
                    if (Aura* aurOld = victim->GetAura(SPELL_DK_BLOOD_PLAGUE, caster->GetGUID())) // Check Blood Plague application on victim.
                    {
                        if (AuraEffect* aurEffOld = aurOld->GetEffect(EFFECT_0))
                        {
                            float donePct = aurEffOld->GetDonePct();
                            float critChance = aurEffOld->GetCritChance();

                            caster->CastSpell(hitUnit, SPELL_DK_BLOOD_PLAGUE, true); // Spread the disease to hitUnit.

                            if (Aura* aurNew = hitUnit->GetAura(SPELL_DK_BLOOD_PLAGUE, caster->GetGUID())) // Check Blood Plague application on hitUnit.
                            {
                                if (AuraEffect* aurEffNew = aurNew->GetEffect(EFFECT_0))
                                {
                                    aurEffNew->SetCritChance(critChance); // Blood Plague can crit if caster has T9.
                                    aurEffNew->SetDonePct(donePct);
                                    aurEffNew->SetBonusAmount(caster->SpellDamageBonusDone(hitUnit, aurEffNew->GetSpellInfo(), 0, DOT));
                                }
                            }
                        }
                    }

                    if (Aura* aurOld = victim->GetAura(SPELL_DK_FROST_FEVER, caster->GetGUID())) // Check Frost Fever application on victim.
                    {
                        if (AuraEffect* aurEffOld = aurOld->GetEffect(EFFECT_0))
                        {
                            float donePct = aurEffOld->GetDonePct();

                            caster->CastSpell(hitUnit, SPELL_DK_FROST_FEVER, true); // Spread the disease to hitUnit.

                            if (Aura* aurNew = hitUnit->GetAura(SPELL_DK_FROST_FEVER, caster->GetGUID())) // Check Frost Fever application on hitUnit.
                            {
                                if (AuraEffect* aurEffNew = aurNew->GetEffect(EFFECT_0))
                                {
                                    aurEffNew->SetDonePct(donePct);
                                    aurEffNew->SetBonusAmount(caster->SpellDamageBonusDone(hitUnit, aurEffNew->GetSpellInfo(), 0, DOT));
                                }
                            }
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_pestilence_SpellScript::OnHit, EFFECT_2, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_pestilence_SpellScript();
        }
};


// 48266 - Blood Presence
// 48263 - Frost Presence
// 48265 - Unholy Presence
class spell_dk_presence : public SpellScriptLoader
{
    public:
        spell_dk_presence() : SpellScriptLoader("spell_dk_presence") { }

        class spell_dk_presence_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_presence_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_BLOOD_PRESENCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_FROST_PRESENCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_UNHOLY_PRESENCE)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_IMPROVED_FROST_PRESENCE_R1)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_R1)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_FROST_PRESENCE_TRIGGERED)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_UNHOLY_PRESENCE_TRIGGERED))
                    return false;

                return true;
            }

            void HandleImprovedBloodPresence(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (GetId() == SPELL_DK_BLOOD_PRESENCE)
                    target->CastSpell(target, SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED, true);
                else if (AuraEffect const* impAurEff = target->GetAuraEffectOfRankedSpell(SPELL_DK_IMPROVED_BLOOD_PRESENCE_R1, EFFECT_0))
                    if (!target->HasAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED))
                        target->CastCustomSpell(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED, SPELLVALUE_BASE_POINT1, impAurEff->GetAmount(), target, true, NULL, aurEff);
            }

            void HandleImprovedFrostPresence(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (GetId() == SPELL_DK_FROST_PRESENCE)
                    target->CastSpell(target, SPELL_DK_FROST_PRESENCE_TRIGGERED, true);
                else if (AuraEffect const* impAurEff = target->GetAuraEffectOfRankedSpell(SPELL_DK_IMPROVED_FROST_PRESENCE_R1, EFFECT_0))
                    if (!target->HasAura(SPELL_DK_FROST_PRESENCE_TRIGGERED))
                        target->CastCustomSpell(SPELL_DK_FROST_PRESENCE_TRIGGERED, SPELLVALUE_BASE_POINT0, impAurEff->GetAmount(), target, true, NULL, aurEff);
            }

            void HandleImprovedUnholyPresence(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (GetId() == SPELL_DK_UNHOLY_PRESENCE)
                    target->CastSpell(target, SPELL_DK_UNHOLY_PRESENCE_TRIGGERED, true);

                if (AuraEffect const* impAurEff = target->GetAuraEffectOfRankedSpell(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_R1, EFFECT_0))
                {
                    if (GetId() == SPELL_DK_UNHOLY_PRESENCE)
                    {
                        // Not listed as any effect, only base points set
                        int32 bp = impAurEff->GetSpellInfo()->Effects[EFFECT_1].CalcValue();
                        target->CastCustomSpell(target, SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED, &bp, &bp, &bp, true, NULL, aurEff);
                    }
                    else if (!target->HasAura(SPELL_DK_UNHOLY_PRESENCE_TRIGGERED))
                        target->CastCustomSpell(SPELL_DK_UNHOLY_PRESENCE_TRIGGERED, SPELLVALUE_BASE_POINT0, impAurEff->GetAmount(), target, true, NULL, aurEff);
                }
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->RemoveAura(SPELL_DK_IMPROVED_BLOOD_PRESENCE_TRIGGERED);
                target->RemoveAura(SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED);
                target->RemoveAura(SPELL_DK_FROST_PRESENCE_TRIGGERED);
                target->RemoveAura(SPELL_DK_UNHOLY_PRESENCE_TRIGGERED);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_dk_presence_AuraScript::HandleImprovedBloodPresence, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectApply += AuraEffectApplyFn(spell_dk_presence_AuraScript::HandleImprovedFrostPresence, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectApply += AuraEffectApplyFn(spell_dk_presence_AuraScript::HandleImprovedUnholyPresence, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dk_presence_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_ANY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_presence_AuraScript();
        }
};

class RaiseDeadCheck
{
    public:
        explicit RaiseDeadCheck(Player const* caster) : _caster(caster) { }

        bool operator()(WorldObject* obj) const
        {
            if (Unit* target = obj->ToUnit())
            {
                if (!target->IsAlive()
                    && _caster->isHonorOrXPTarget(target)
                    && target->GetCreatureType() == CREATURE_TYPE_HUMANOID
                    && target->GetDisplayId() == target->GetNativeDisplayId())
                    return false;
            }

            return true;
        }

    private:
        Player const* _caster;
};

// 46584 - Raise Dead
class spell_dk_raise_dead : public SpellScriptLoader
{
    public:
        spell_dk_raise_dead() : SpellScriptLoader("spell_dk_raise_dead") { }

        class spell_dk_raise_dead_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_raise_dead_SpellScript);

        public:
            spell_dk_raise_dead_SpellScript()
            {
                _result = SPELL_CAST_OK;
                _corpse = false;
            }

        private:
            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!sSpellMgr->GetSpellInfo(spellInfo->Effects[EFFECT_1].CalcValue())
                    || !sSpellMgr->GetSpellInfo(spellInfo->Effects[EFFECT_2].CalcValue())
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_RAISE_DEAD_USE_REAGENT)
                    || !sSpellMgr->GetSpellInfo(SPELL_DK_MASTER_OF_GHOULS))
                    return false;
                return true;
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            SpellCastResult CheckCast()
            {
                /// process spell target selection before cast starts
                /// targets of effect_1 are used to check cast
                GetSpell()->SelectSpellTargets();
                /// cleanup spell target map, and fill it again on normal way
                GetSpell()->CleanupTargetList();
                /// _result is set in spell target selection
                return _result;
            }

            SpellCastResult CheckReagents()
            {
                /// @workaround: there is no access to castresult of other spells, check it manually
                SpellInfo const* reagentSpell = sSpellMgr->GetSpellInfo(SPELL_DK_RAISE_DEAD_USE_REAGENT);
                Player* player = GetCaster()->ToPlayer();
                if (!player->CanNoReagentCast(reagentSpell))
                {
                    for (uint32 i = 0; i < MAX_SPELL_REAGENTS; i++)
                    {
                        if (reagentSpell->Reagent[i] <= 0)
                            continue;

                        if (!player->HasItemCount(reagentSpell->Reagent[i], reagentSpell->ReagentCount[i]))
                        {
                            Spell::SendCastResult(player, reagentSpell, 0, SPELL_FAILED_REAGENTS);
                            return SPELL_FAILED_DONT_REPORT;
                        }
                    }
                }
                return SPELL_CAST_OK;
            }

            void CheckTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(RaiseDeadCheck(GetCaster()->ToPlayer()));

                if (targets.empty())
                {
                    if (GetSpell()->getState() == SPELL_STATE_PREPARING)
                        _result = CheckReagents();

                    return;
                }

                WorldObject* target = Trinity::Containers::SelectRandomContainerElement(targets);
                targets.clear();
                targets.push_back(target);
                _corpse = true;
            }

            void CheckTarget(WorldObject*& target)
            {
                // Don't add caster to target map, if we found a corpse to raise dead
                if (_corpse)
                    target = NULL;
            }

            void ConsumeReagents()
            {
                // No corpse found, take reagents
                if (!_corpse)
                    GetCaster()->CastSpell(GetCaster(), SPELL_DK_RAISE_DEAD_USE_REAGENT, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
            }

            uint32 GetGhoulSpellId()
            {
                // Do we have talent Master of Ghouls?
                if (GetCaster()->HasAura(SPELL_DK_MASTER_OF_GHOULS))
                    // summon as pet
                    return GetSpellInfo()->Effects[EFFECT_2].CalcValue();

                // or guardian
                return GetSpellInfo()->Effects[EFFECT_1].CalcValue();
            }

            void HandleRaiseDead(SpellEffIndex /*effIndex*/)
            {
                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(GetGhoulSpellId());
                SpellCastTargets targets;
                targets.SetDst(*GetHitUnit());

                GetCaster()->CastSpell(targets, spellInfo, NULL, TRIGGERED_FULL_MASK);
            }

            void OverrideCooldown()
            {
                // Because the ghoul is summoned by one of triggered spells SendCooldownEvent is not sent for this spell
                // but the client has locked it by itself so we need some link between this spell and the real spell summoning.
                // Luckily such link already exists - spell category
                // This starts infinite category cooldown which can later be used by SendCooldownEvent to send packet for this spell
                GetCaster()->GetSpellHistory()->StartCooldown(GetSpellInfo(), 0, nullptr, true);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_raise_dead_SpellScript::CheckCast);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dk_raise_dead_SpellScript::CheckTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENTRY);
                OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_dk_raise_dead_SpellScript::CheckTarget, EFFECT_2, TARGET_UNIT_CASTER);
                OnCast += SpellCastFn(spell_dk_raise_dead_SpellScript::ConsumeReagents);
                OnEffectHitTarget += SpellEffectFn(spell_dk_raise_dead_SpellScript::HandleRaiseDead, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
                OnEffectHitTarget += SpellEffectFn(spell_dk_raise_dead_SpellScript::HandleRaiseDead, EFFECT_2, SPELL_EFFECT_DUMMY);
                AfterCast += SpellCastFn(spell_dk_raise_dead_SpellScript::OverrideCooldown);
            }

        private:
            SpellCastResult _result;
            bool _corpse;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_raise_dead_SpellScript();
        }
};

// 59754 Rune Tap - Party
class spell_dk_rune_tap_party : public SpellScriptLoader
{
    public:
        spell_dk_rune_tap_party() : SpellScriptLoader("spell_dk_rune_tap_party") { }

        class spell_dk_rune_tap_party_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_rune_tap_party_SpellScript);

            void CheckTargets(std::list<WorldObject*>& targets)
            {
                targets.remove(GetCaster());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_dk_rune_tap_party_SpellScript::CheckTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_PARTY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_rune_tap_party_SpellScript();
        }
};

// 50421 - Scent of Blood
class spell_dk_scent_of_blood : public SpellScriptLoader
{
    public:
        spell_dk_scent_of_blood() : SpellScriptLoader("spell_dk_scent_of_blood") { }

        class spell_dk_scent_of_blood_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_scent_of_blood_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_SCENT_OF_BLOOD))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_DK_SCENT_OF_BLOOD, true, NULL, aurEff);
                GetTarget()->RemoveAuraFromStack(GetSpellInfo()->Id);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dk_scent_of_blood_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_scent_of_blood_AuraScript();
        }
};

// 55090 - Scourge Strike (55265, 55270, 55271)
class spell_dk_scourge_strike : public SpellScriptLoader
{
    public:
        spell_dk_scourge_strike() : SpellScriptLoader("spell_dk_scourge_strike") { }

        class spell_dk_scourge_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_scourge_strike_SpellScript);

        public:
            spell_dk_scourge_strike_SpellScript()
            {
                multiplier = 1.0f;
            }

        private:
            float multiplier;

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DK_SCOURGE_STRIKE_TRIGGERED))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* unitTarget = GetHitUnit())
                {
                    multiplier = (GetEffectValue() * unitTarget->GetDiseasesByCaster(caster->GetGUID()) / 100.f);
                    // Death Knight T8 Melee 4P Bonus
                    if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_DK_ITEM_T8_MELEE_4P_BONUS, EFFECT_0))
                        AddPct(multiplier, aurEff->GetAmount());
                }
            }

            void HandleAfterHit()
            {
                Unit* caster = GetCaster();
                if (Unit* unitTarget = GetHitUnit())
                {
                    int32 bp = GetHitDamage() * multiplier;

                    if (AuraEffect* aurEff = caster->GetAuraEffectOfRankedSpell(SPELL_DK_BLACK_ICE_R1, EFFECT_0))
                        AddPct(bp, aurEff->GetAmount());

                    caster->CastCustomSpell(unitTarget, SPELL_DK_SCOURGE_STRIKE_TRIGGERED, &bp, NULL, NULL, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_scourge_strike_SpellScript::HandleDummy, EFFECT_2, SPELL_EFFECT_DUMMY);
                AfterHit += SpellHitFn(spell_dk_scourge_strike_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_scourge_strike_SpellScript();
        }
};

// 49145 - Spell Deflection
class spell_dk_spell_deflection : public SpellScriptLoader
{
    public:
        spell_dk_spell_deflection() : SpellScriptLoader("spell_dk_spell_deflection") { }

        class spell_dk_spell_deflection_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_spell_deflection_AuraScript);

        public:
            spell_dk_spell_deflection_AuraScript()
            {
                absorbPct = 0;
            }

        private:
            uint32 absorbPct;

            bool Load() override
            {
                absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                // You have a chance equal to your Parry chance
                if ((dmgInfo.GetDamageType() == SPELL_DIRECT_DAMAGE) && roll_chance_f(GetTarget()->GetUnitParryChance()))
                    absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_spell_deflection_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_spell_deflection_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_spell_deflection_AuraScript();
        }
};

// 55233 - Vampiric Blood
class spell_dk_vampiric_blood : public SpellScriptLoader
{
    public:
        spell_dk_vampiric_blood() : SpellScriptLoader("spell_dk_vampiric_blood") { }

        class spell_dk_vampiric_blood_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_vampiric_blood_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                amount = GetUnitOwner()->CountPctFromMaxHealth(amount);
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_vampiric_blood_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_HEALTH);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_vampiric_blood_AuraScript();
        }
};

// 52284 - Will of the Necropolis
class spell_dk_will_of_the_necropolis : public SpellScriptLoader
{
    public:
        spell_dk_will_of_the_necropolis() : SpellScriptLoader("spell_dk_will_of_the_necropolis") { }

        class spell_dk_will_of_the_necropolis_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_will_of_the_necropolis_AuraScript);

        public:
            spell_dk_will_of_the_necropolis_AuraScript()
            {
                absorbPct = 0;
            }

        private:
            bool Validate(SpellInfo const* spellInfo) override
            {
                SpellInfo const* firstRankSpellInfo = sSpellMgr->GetSpellInfo(SPELL_DK_WILL_OF_THE_NECROPOLIS_AURA_R1);
                if (!firstRankSpellInfo)
                    return false;

                // can't use other spell than will of the necropolis due to spell_ranks dependency
                if (!spellInfo->IsRankOf(firstRankSpellInfo))
                    return false;

                uint8 rank = spellInfo->GetRank();
                if (!sSpellMgr->GetSpellWithRank(SPELL_DK_WILL_OF_THE_NECROPOLIS_TALENT_R1, rank, true))
                    return false;

                return true;
            }

            uint32 absorbPct;

            bool Load() override
            {
                absorbPct = GetSpellInfo()->Effects[EFFECT_0].CalcValue(GetCaster());
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32 & amount, bool & /*canBeRecalculated*/)
            {
                // Set absorbtion amount to unlimited
                amount = -1;
            }

            void Absorb(AuraEffect* /*aurEff*/, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                // min pct of hp is stored in effect 0 of talent spell
                uint8 rank = GetSpellInfo()->GetRank();
                SpellInfo const* talentProto = sSpellMgr->EnsureSpellInfo(sSpellMgr->GetSpellWithRank(SPELL_DK_WILL_OF_THE_NECROPOLIS_TALENT_R1, rank));

                int32 remainingHp = int32(GetTarget()->GetHealth() - dmgInfo.GetDamage());
                int32 minHp = int32(GetTarget()->CountPctFromMaxHealth(talentProto->Effects[EFFECT_0].CalcValue(GetCaster())));

                // Damage that would take you below [effect0] health or taken while you are at [effect0]
                if (remainingHp < minHp)
                    absorbAmount = CalculatePct(dmgInfo.GetDamage(), absorbPct);
            }

            void Register() override
            {
                 DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_will_of_the_necropolis_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                 OnEffectAbsorb += AuraEffectAbsorbFn(spell_dk_will_of_the_necropolis_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_will_of_the_necropolis_AuraScript();
        }
};

// 49576 - Death Grip Initial
class spell_dk_death_grip_initial : public SpellScriptLoader
{
public:
    spell_dk_death_grip_initial() : SpellScriptLoader("spell_dk_death_grip_initial") { }

    class spell_dk_death_grip_initial_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_death_grip_initial_SpellScript);

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            // Death Grip should not be castable while jumping/falling
            if (caster->HasUnitState(UNIT_STATE_JUMPING) || caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING))
                return SPELL_FAILED_MOVING;

            // Patch 3.3.3 (2010-03-23): Minimum range has been changed to 8 yards in PvP.
            Unit* target = GetExplTargetUnit();
            if (target && target->GetTypeId() == TYPEID_PLAYER)
                if (caster->GetDistance(target) < 8.f)
                    return SPELL_FAILED_TOO_CLOSE;

            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_DEATH_GRIP, true);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dk_death_grip_initial_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_dk_death_grip_initial_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_death_grip_initial_SpellScript();
    }
};

enum RaiseAllyMisc
{
    TEXT_RISE_ALLY = 33055,

    SPELL_DK_RISEN_GHOUL_SELF_STUN = 47466,
    SPELL_DK_RISEN_GHOUL_SPAWN__IN = 47448,
    SPELL_DK_SUMMON_HEAL = 36492,
    SPELL_DK_DEATH_KNIGHT_RUNE_WEAPON_SCALING_02 = 51906,
    SPELL_DK_DEATH_KNIGHT_PET_SCALING_01 = 54566,
    SPELL_DK_DEATH_KNIGHT_PET_SCALING_03 = 61697,
    SPELL_DK_MIRROR_NAME = 62224,
    SPELL_DK_MIRROR_NAME_TRIGGERED = 62214,
    SPELL_DK_PET_SCALING___MASTER_SPELL_03___INTELLECT_SPIRIT_RESILIENCE = 67557,
    SPELL_DK_PET_SCALING___MASTER_SPELL_06___SPELL_HIT_EXPERTISE_SPELL_PENETRATION = 67561,

    SPELL_GHOUL_FRENZY = 62218,

    NPC_RISEN_ALLY = 30230
};

// 61999 - Raise Ally Initial
class spell_dk_raise_ally_initial : public SpellScriptLoader
{
public:
    spell_dk_raise_ally_initial() : SpellScriptLoader("spell_dk_raise_ally_initial") { }

    class spell_dk_raise_ally_initial_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_raise_ally_initial_SpellScript);

        bool Validate(SpellInfo const* spellInfo) override
        {
            if (!sSpellMgr->GetSpellInfo(uint32(spellInfo->Effects[EFFECT_0].CalcValue())))
                return false;
            return true;
        }

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        SpellCastResult CheckCast()
        {
            Unit* target = GetExplTargetUnit();
            if (!target)
                return SPELL_FAILED_NO_VALID_TARGETS;
            if (target->IsAlive())
                return SPELL_FAILED_TARGET_NOT_DEAD;
            if (target->IsGhouled())
                return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;
            return SPELL_CAST_OK;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Player* target = GetHitPlayer())
            {
                if (target->IsResurrectRequested()) // already have one active request
                    return;
                target->SetResurrectRequestData(GetCaster(), 0, 0, uint32(GetEffectValue()));
                GetSpell()->SendResurrectRequest(target);
            }
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_dk_raise_ally_initial_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_dk_raise_ally_initial_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_raise_ally_initial_SpellScript();
    }
};

class player_ghoulAI : public PlayerAI
{
    public:
        player_ghoulAI(Player* player, ObjectGuid ghoulGUID) : PlayerAI(player), _ghoulGUID(ghoulGUID) { }

        void UpdateAI(uint32 /*diff*/) override
        {
            Creature* ghoul = ObjectAccessor::GetCreature(*me, _ghoulGUID);
            if (!ghoul || !ghoul->IsAlive())
                me->RemoveAura(SPELL_DK_RAISE_ALLY);
        }

    private:
        ObjectGuid _ghoulGUID;
};

// 46619 - Raise Ally
#define DkRaiseAllyScriptName "spell_dk_raise_ally"
class spell_dk_raise_ally : public SpellScriptLoader
{
public:
    spell_dk_raise_ally() : SpellScriptLoader(DkRaiseAllyScriptName) { }

    class spell_dk_raise_ally_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_raise_ally_SpellScript);

        bool Load() override
        {
            return GetCaster()->GetTypeId() == TYPEID_PLAYER;
        }

        void SendText()
        {
            if (Unit* original = GetOriginalCaster())
                original->Whisper(TEXT_RISE_ALLY, GetCaster()->ToPlayer(), true);
        }

        void HandleSummon(SpellEffIndex effIndex)
        {
            PreventHitDefaultEffect(effIndex);

            Unit* caster = GetCaster();
            Unit* originalCaster = GetOriginalCaster();
            if (!originalCaster)
                return;

            uint32 entry = uint32(GetSpellInfo()->Effects[effIndex].MiscValue);

            //! HACK - StatSystem needs further develop to enable update on Puppet stats
            // Using same summon properties as Raise Dead 46585 (Guardian) - EffectMiscValueB = 829
            SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(829);

            uint32 duration = uint32(GetSpellInfo()->GetDuration());

            TempSummon* summon = originalCaster->GetMap()->SummonCreature(entry, *GetHitDest(), properties, duration, originalCaster, GetSpellInfo()->Id);
            if (!summon)
                return;

            //! Leaving this here as it's necessary if statsystem problem is solved
            /*
                Default SUMMON_CATEGORY_PUPPET behaviour sets possesor as originalCaster,
                in this case we need caster as possesor and originalCaster as owner
            */
            //summon->RemoveCharmedBy(NULL);

            summon->SetCharmedBy(caster, CHARM_TYPE_POSSESS);

            summon->CastSpell(summon, SPELL_DK_RISEN_GHOUL_SELF_STUN, true);
            summon->CastSpell(summon, SPELL_DK_RISEN_GHOUL_SPAWN__IN, true);
            summon->CastSpell(summon, SPELL_DK_SUMMON_HEAL, true);
            summon->CastSpell(caster, SPELL_DK_MIRROR_NAME, true);
            caster->CastSpell(summon, SPELL_DK_MIRROR_NAME_TRIGGERED, true);
            summon->CastSpell(summon, SPELL_DK_DEATH_KNIGHT_RUNE_WEAPON_SCALING_02, true);
            summon->CastSpell(summon, SPELL_DK_DEATH_KNIGHT_PET_SCALING_01, true);
            summon->CastSpell(summon, SPELL_DK_DEATH_KNIGHT_PET_SCALING_03, true);
            summon->CastSpell(summon, SPELL_DK_PET_SCALING___MASTER_SPELL_03___INTELLECT_SPIRIT_RESILIENCE, true);
            summon->CastSpell(summon, SPELL_DK_PET_SCALING___MASTER_SPELL_06___SPELL_HIT_EXPERTISE_SPELL_PENETRATION, true);

            // SMSG_POWER_UPDATE is sent
            summon->SetMaxPower(POWER_ENERGY, 100);

            _ghoulGuid = summon->GetGUID();
        }

        void SetGhoul(SpellEffIndex /*effIndex*/)
        {
            if (Aura* aura = GetHitAura())
                if (spell_dk_raise_ally_AuraScript* script = dynamic_cast<spell_dk_raise_ally_AuraScript*>(aura->GetScriptByName(DkRaiseAllyScriptName)))
                    script->SetGhoulGuid(_ghoulGuid);
        }

        void Register() override
        {
            AfterHit += SpellHitFn(spell_dk_raise_ally_SpellScript::SendText);
            OnEffectHit += SpellEffectFn(spell_dk_raise_ally_SpellScript::HandleSummon, EFFECT_0, SPELL_EFFECT_SUMMON);
            OnEffectHitTarget += SpellEffectFn(spell_dk_raise_ally_SpellScript::SetGhoul, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
        }

    private:
        ObjectGuid _ghoulGuid;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_raise_ally_SpellScript();
    }

    class spell_dk_raise_ally_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_raise_ally_AuraScript);

    public:
        spell_dk_raise_ally_AuraScript()
        {
            oldAI = nullptr;
            oldAIState = false;
        }

        void SetGhoulGuid(ObjectGuid guid)
        {
            ghoulGuid = guid;
        }

    private:
        bool Load() override
        {
            return GetUnitOwner()->GetTypeId() == TYPEID_PLAYER;
        }

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetTarget()->ToPlayer();
            if (ghoulGuid.IsEmpty())
                return;

            oldAI = player->AI();
            oldAIState = player->IsAIEnabled;
            player->SetAI(new player_ghoulAI(player, ghoulGuid));
            player->IsAIEnabled = true;
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Player* player = GetTarget()->ToPlayer();

            player->IsAIEnabled = oldAIState;
            PlayerAI* thisAI = player->AI();
            player->SetAI(oldAI);
            delete thisAI;

            // Dismiss ghoul if necessary
            if (Creature* ghoul = ObjectAccessor::GetCreature(*player, ghoulGuid))
            {
                ghoul->RemoveCharmedBy(player);
                ghoul->DespawnOrUnsummon(1000);
            }

            player->RemoveAura(SPELL_GHOUL_FRENZY);
        }

        void Register() override
        {
            AfterEffectApply += AuraEffectApplyFn(spell_dk_raise_ally_AuraScript::OnApply, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            AfterEffectRemove += AuraEffectRemoveFn(spell_dk_raise_ally_AuraScript::OnRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }

        ObjectGuid ghoulGuid;
        PlayerAI* oldAI;
        bool oldAIState;
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_raise_ally_AuraScript();
    }
};

// 47480 - Thrash
class spell_dk_ghoul_thrash : public SpellScriptLoader
{
public:
    spell_dk_ghoul_thrash() : SpellScriptLoader("spell_dk_ghoul_thrash") { }

    class spell_dk_ghoul_thrash_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_dk_ghoul_thrash_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_GHOUL_FRENZY))
                return false;
            return true;
        }

        void CalcDamage()
        {
            if (Aura* aur = GetCaster()->GetAura(SPELL_GHOUL_FRENZY))
            {
                int32 damage = GetHitDamage();
                damage += int32(GetCaster()->GetTotalAttackPowerValue(BASE_ATTACK) * 0.05f * aur->GetStackAmount());
                aur->Remove();
                SetHitDamage(damage);
            }

            /*
                Also remove aura from charmer
                SPELL_GHOUL_FRENZY (62218) - Targets (1, 27) (TARGET_UNIT_CASTER, TARGET_UNIT_MASTER)
            */
            if (Unit* charmer = GetCaster()->GetCharmer())
                charmer->RemoveAura(SPELL_GHOUL_FRENZY);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_dk_ghoul_thrash_SpellScript::CalcDamage);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_dk_ghoul_thrash_SpellScript();
    }
};

void AddSC_deathknight_spell_scripts()
{
    new spell_dk_anti_magic_shell_raid();
    new spell_dk_anti_magic_shell_self();
    new spell_dk_anti_magic_zone();
    new spell_dk_blood_boil();
    new spell_dk_blood_gorged();
    new spell_dk_bloodworms();
    new spell_dk_corpse_explosion();
    new spell_dk_death_and_decay();
    new spell_dk_death_coil();
    new spell_dk_death_gate();
    new spell_dk_death_grip();
    new spell_dk_death_pact();
    new spell_dk_death_strike();
    new spell_dk_ghoul_explode();
    new spell_dk_icebound_fortitude();
    new spell_dk_improved_blood_presence();
    new spell_dk_improved_frost_presence();
    new spell_dk_improved_unholy_presence();
    new spell_dk_pestilence();
    new spell_dk_presence();
    new spell_dk_raise_dead();
    new spell_dk_rune_tap_party();
    new spell_dk_scent_of_blood();
    new spell_dk_scourge_strike();
    new spell_dk_spell_deflection();
    new spell_dk_vampiric_blood();
    new spell_dk_will_of_the_necropolis();
    new spell_dk_death_grip_initial();
    new spell_dk_raise_ally_initial();
    new spell_dk_raise_ally();
    new spell_dk_ghoul_thrash();
}
