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

/*
 * Scripts for spells with SPELLFAMILY_WARLOCK and SPELLFAMILY_GENERIC spells used by warlock players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_warl_".
 */

#include "ScriptMgr.h"
#include "AreaTrigger.h"
#include "Creature.h"
#include "GameObject.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "Random.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum WarlockSpells
{
    SPELL_WARLOCK_BANE_OF_DOOM_EFFECT               = 18662,
    SPELL_WARLOCK_CREATE_HEALTHSTONE                = 23517,
    SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST         = 62388,
    SPELL_WARLOCK_DEMONIC_CIRCLE_SUMMON             = 48018,
    SPELL_WARLOCK_DEMONIC_CIRCLE_TELEPORT           = 48020,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_FELGUARD      = 54508,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_FELHUNTER     = 54509,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_IMP           = 54444,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_SUCCUBUS      = 54435,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_VOIDWALKER    = 54443,
    SPELL_WARLOCK_DEMON_SOUL_IMP                    = 79459,
    SPELL_WARLOCK_DEMON_SOUL_FELHUNTER              = 79460,
    SPELL_WARLOCK_DEMON_SOUL_FELGUARD               = 79452,
    SPELL_WARLOCK_DEMON_SOUL_SUCCUBUS               = 79453,
    SPELL_WARLOCK_DEMON_SOUL_VOIDWALKER             = 79454,
    SPELL_WARLOCK_DEVOUR_MAGIC_HEAL                 = 19658,
    SPELL_WARLOCK_FEL_SYNERGY_HEAL                  = 54181,
    SPELL_WARLOCK_GLYPH_OF_DEMON_TRAINING           = 56249,
    SPELL_WARLOCK_GLYPH_OF_SHADOWFLAME              = 63311,
    SPELL_WARLOCK_GLYPH_OF_SOUL_SWAP                = 56226,
    SPELL_WARLOCK_GLYPH_OF_SUCCUBUS                 = 56250,
    SPELL_WARLOCK_HAUNT_HEAL                        = 48210,
    SPELL_WARLOCK_IMMOLATE                          = 348,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R1    = 60955,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R2    = 60956,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_R1         = 18703,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_R2         = 18704,
    SPELL_WARLOCK_IMPROVED_SOUL_FIRE_PCT            = 85383,
    SPELL_WARLOCK_IMPROVED_SOUL_FIRE_STATE          = 85385,
    SPELL_WARLOCK_NETHER_WARD                       = 91711,
    SPELL_WARLOCK_NETHER_TALENT                     = 91713,
    SPELL_WARLOCK_RAIN_OF_FIRE                      = 5740,
    SPELL_WARLOCK_RAIN_OF_FIRE_DAMAGE               = 42223,
    SPELL_WARLOCK_SEED_OF_CORRUPTION_DAMAGE         = 27285,
    SPELL_WARLOCK_SEED_OF_CORRUPTION_GENERIC        = 32865,
    SPELL_WARLOCK_SHADOW_TRANCE                     = 17941,
    SPELL_WARLOCK_SHADOW_WARD                       = 6229,
    SPELL_WARLOCK_SOULSHATTER                       = 32835,
    SPELL_WARLOCK_SOUL_SWAP_CD_MARKER               = 94229,
    SPELL_WARLOCK_SOUL_SWAP_OVERRIDE                = 86211,
    SPELL_WARLOCK_SOUL_SWAP_MOD_COST                = 92794,
    SPELL_WARLOCK_SOUL_SWAP_DOT_MARKER              = 92795,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION               = 30108,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION_DISPEL        = 31117,
    SPELL_WARLOCK_SHADOWFLAME                       = 37378,
    SPELL_WARLOCK_FLAMESHADOW                       = 37379,
};

enum MiscSpells
{
    SPELL_GEN_REPLENISHMENT                         = 57669,
    SPELL_PRIEST_SHADOW_WORD_DEATH                  = 32409
};

// 710 - Banish
class spell_warl_banish : public SpellScriptLoader
{
    public:
        spell_warl_banish() : SpellScriptLoader("spell_warl_banish") { }

        class spell_warl_banish_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_banish_SpellScript);

        public:
            spell_warl_banish_SpellScript() {}

        private:
            void HandleBanish(SpellMissInfo missInfo)
            {
                if (missInfo != SPELL_MISS_IMMUNE)
                    return;

                if (Unit* target = GetHitUnit())
                {
                    // Casting Banish on a banished target will remove applied aura
                    if (Aura * banishAura = target->GetAura(GetSpellInfo()->Id, GetCaster()->GetGUID()))
                        banishAura->Remove();
                }
            }

            void Register() override
            {
                BeforeHit += BeforeSpellHitFn(spell_warl_banish_SpellScript::HandleBanish);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_banish_SpellScript();
        }
};

// 17962 - Conflagrate - Updated to 4.3.4
class spell_warl_conflagrate : public SpellScriptLoader
{
    public:
        spell_warl_conflagrate() : SpellScriptLoader("spell_warl_conflagrate") { }

        class spell_warl_conflagrate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_conflagrate_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_IMMOLATE });
            }

            // 6.x dmg formula in tooltip
            // void HandleHit(SpellEffIndex /*effIndex*/)
            // {
            //     if (AuraEffect const* aurEff = GetHitUnit()->GetAuraEffect(SPELL_WARLOCK_IMMOLATE, EFFECT_2, GetCaster()->GetGUID()))
            //         SetHitDamage(CalculatePct(aurEff->GetAmount(), GetSpellInfo()->Effects[EFFECT_1].CalcValue(GetCaster())));
            // }

            void Register() override
            {
                //OnEffectHitTarget += SpellEffectFn(spell_warl_conflagrate_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_conflagrate_SpellScript();
        }
};

// 77220 - Mastery: Chaotic Energies
class spell_warl_chaotic_energies : public AuraScript
{
    PrepareAuraScript(spell_warl_chaotic_energies);

    void HandleAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
    {
        AuraEffect const* effect1 = GetEffect(EFFECT_1);
        if (!effect1 || !GetTargetApplication()->HasEffect(EFFECT_1))
        {
            PreventDefaultAction();
            return;
        }

        // You take ${$s2/3}% reduced damage
        float damageReductionPct = float(effect1->GetAmount()) / 3;
        // plus a random amount of up to ${$s2/3}% additional reduced damage
        damageReductionPct += frand(0.0f, damageReductionPct);

        absorbAmount = CalculatePct(dmgInfo.GetDamage(), damageReductionPct);
    }

    void Register() override
    {
        OnEffectAbsorb += AuraEffectAbsorbFn(spell_warl_chaotic_energies::HandleAbsorb, EFFECT_2);
    }
};

// 6201 - Create Healthstone
class spell_warl_create_healthstone : public SpellScriptLoader
{
    public:
        spell_warl_create_healthstone() : SpellScriptLoader("spell_warl_create_healthstone") { }

        class spell_warl_create_healthstone_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_create_healthstone_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_CREATE_HEALTHSTONE });
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_CREATE_HEALTHSTONE, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warl_create_healthstone_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_create_healthstone_SpellScript();
        }
};

// 603 - Bane of Doom
/// Updated 4.3.4
class spell_warl_bane_of_doom : public SpellScriptLoader
{
    public:
        spell_warl_bane_of_doom() : SpellScriptLoader("spell_warl_bane_of_doom") { }

        class spell_warl_curse_of_doom_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_curse_of_doom_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_BANE_OF_DOOM_EFFECT });
            }

            bool Load() override
            {
                return GetCaster() && GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (!GetCaster())
                    return;

                AuraRemoveMode removeMode = GetTargetApplication()->GetRemoveMode();
                if (removeMode != AURA_REMOVE_BY_DEATH || !IsExpired())
                    return;

                if (GetCaster()->ToPlayer()->isHonorOrXPTarget(GetTarget()))
                    GetCaster()->CastSpell(GetTarget(), SPELL_WARLOCK_BANE_OF_DOOM_EFFECT, true, nullptr, aurEff);
            }

            void Register() override
            {
                 AfterEffectRemove += AuraEffectRemoveFn(spell_warl_curse_of_doom_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_curse_of_doom_AuraScript();
        }
};

// 48018 - Demonic Circle: Summon
/// Updated 4.3.4
class spell_warl_demonic_circle_summon : public SpellScriptLoader
{
    public:
        spell_warl_demonic_circle_summon() : SpellScriptLoader("spell_warl_demonic_circle_summon") { }

        class spell_warl_demonic_circle_summon_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_demonic_circle_summon_AuraScript);

            void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes mode)
            {
                // If effect is removed by expire remove the summoned demonic circle too.
                if (!(mode & AURA_EFFECT_HANDLE_REAPPLY))
                    GetTarget()->RemoveGameObject(GetId(), true);

                GetTarget()->RemoveAura(SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST);
            }

            void HandleDummyTick(AuraEffect const* /*aurEff*/)
            {
                if (GameObject* circle = GetTarget()->GetGameObject(GetId()))
                {
                    // Here we check if player is in demonic circle teleport range, if so add
                    // WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST; allowing him to cast the WARLOCK_DEMONIC_CIRCLE_TELEPORT.
                    // If not in range remove the WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST.

                    SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_WARLOCK_DEMONIC_CIRCLE_TELEPORT, GetCastDifficulty());

                    if (GetTarget()->IsWithinDist(circle, spellInfo->GetMaxRange(true)))
                    {
                        if (!GetTarget()->HasAura(SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST))
                            GetTarget()->CastSpell(GetTarget(), SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST, true);
                    }
                    else
                        GetTarget()->RemoveAura(SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST);
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectApplyFn(spell_warl_demonic_circle_summon_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_demonic_circle_summon_AuraScript::HandleDummyTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_demonic_circle_summon_AuraScript();
        }
};

// 48020 - Demonic Circle: Teleport
/// Updated 4.3.4
class spell_warl_demonic_circle_teleport : public SpellScriptLoader
{
    public:
        spell_warl_demonic_circle_teleport() : SpellScriptLoader("spell_warl_demonic_circle_teleport") { }

        class spell_warl_demonic_circle_teleport_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_demonic_circle_teleport_AuraScript);

            void HandleTeleport(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Player* player = GetTarget()->ToPlayer())
                {
                    if (GameObject* circle = player->GetGameObject(SPELL_WARLOCK_DEMONIC_CIRCLE_SUMMON))
                    {
                        player->NearTeleportTo(circle->GetPositionX(), circle->GetPositionY(), circle->GetPositionZ(), circle->GetOrientation());
                        player->RemoveMovementImpairingAuras(false);
                    }
                }
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_warl_demonic_circle_teleport_AuraScript::HandleTeleport, EFFECT_0, SPELL_AURA_MECHANIC_IMMUNITY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_demonic_circle_teleport_AuraScript();
        }
};

// 77801 - Demon Soul - Updated to 4.3.4
class spell_warl_demon_soul : public SpellScriptLoader
{
    public:
        spell_warl_demon_soul() : SpellScriptLoader("spell_warl_demon_soul") { }

        class spell_warl_demon_soul_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_demon_soul_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_WARLOCK_DEMON_SOUL_IMP,
                    SPELL_WARLOCK_DEMON_SOUL_FELHUNTER,
                    SPELL_WARLOCK_DEMON_SOUL_FELGUARD,
                    SPELL_WARLOCK_DEMON_SOUL_SUCCUBUS,
                    SPELL_WARLOCK_DEMON_SOUL_VOIDWALKER
                });
            }

            void OnHitTarget(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Creature* targetCreature = GetHitCreature())
                {
                    if (targetCreature->IsPet())
                    {
                        CreatureTemplate const* ci = targetCreature->GetCreatureTemplate();
                        switch (ci->family)
                        {
                            case CREATURE_FAMILY_SUCCUBUS:
                                caster->CastSpell(caster, SPELL_WARLOCK_DEMON_SOUL_SUCCUBUS);
                                break;
                            case CREATURE_FAMILY_VOIDWALKER:
                                caster->CastSpell(caster, SPELL_WARLOCK_DEMON_SOUL_VOIDWALKER);
                                break;
                            case CREATURE_FAMILY_FELGUARD:
                                caster->CastSpell(caster, SPELL_WARLOCK_DEMON_SOUL_FELGUARD);
                                break;
                            case CREATURE_FAMILY_FELHUNTER:
                                caster->CastSpell(caster, SPELL_WARLOCK_DEMON_SOUL_FELHUNTER);
                                break;
                            case CREATURE_FAMILY_IMP:
                                caster->CastSpell(caster, SPELL_WARLOCK_DEMON_SOUL_IMP);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warl_demon_soul_SpellScript::OnHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_demon_soul_SpellScript;
        }
};

// 47193 - Demonic Empowerment
/// Updated 4.3.4
class spell_warl_demonic_empowerment : public SpellScriptLoader
{
    public:
        spell_warl_demonic_empowerment() : SpellScriptLoader("spell_warl_demonic_empowerment") { }

        class spell_warl_demonic_empowerment_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_demonic_empowerment_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_SUCCUBUS,
                    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_VOIDWALKER,
                    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_FELGUARD,
                    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_FELHUNTER,
                    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_IMP
                });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                if (Creature* targetCreature = GetHitCreature())
                {
                    if (targetCreature->IsPet())
                    {
                        CreatureTemplate const* ci = targetCreature->GetCreatureTemplate();
                        switch (ci->family)
                        {
                            case CREATURE_FAMILY_SUCCUBUS:
                                targetCreature->CastSpell(targetCreature, SPELL_WARLOCK_DEMONIC_EMPOWERMENT_SUCCUBUS, true);
                                break;
                            case CREATURE_FAMILY_VOIDWALKER:
                            {
                                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_WARLOCK_DEMONIC_EMPOWERMENT_VOIDWALKER, GetCastDifficulty());
                                int32 hp = int32(targetCreature->CountPctFromMaxHealth(GetCaster()->CalculateSpellDamage(targetCreature, spellInfo, 0)));
                                targetCreature->CastCustomSpell(targetCreature, SPELL_WARLOCK_DEMONIC_EMPOWERMENT_VOIDWALKER, &hp, nullptr, nullptr, true);
                                break;
                            }
                            case CREATURE_FAMILY_FELGUARD:
                                targetCreature->CastSpell(targetCreature, SPELL_WARLOCK_DEMONIC_EMPOWERMENT_FELGUARD, true);
                                break;
                            case CREATURE_FAMILY_FELHUNTER:
                                targetCreature->CastSpell(targetCreature, SPELL_WARLOCK_DEMONIC_EMPOWERMENT_FELHUNTER, true);
                                break;
                            case CREATURE_FAMILY_IMP:
                                targetCreature->CastSpell(targetCreature, SPELL_WARLOCK_DEMONIC_EMPOWERMENT_IMP, true);
                                break;
                            default:
                                break;
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warl_demonic_empowerment_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_demonic_empowerment_SpellScript();
        }
};

// 67518, 19505 - Devour Magic
class spell_warl_devour_magic : public SpellScriptLoader
{
    public:
        spell_warl_devour_magic() : SpellScriptLoader("spell_warl_devour_magic") { }

        class spell_warl_devour_magic_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_devour_magic_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_GLYPH_OF_DEMON_TRAINING, SPELL_WARLOCK_DEVOUR_MAGIC_HEAL });
            }

            void OnSuccessfulDispel(SpellEffIndex /*effIndex*/)
            {
                if (SpellEffectInfo const* effect = GetSpellInfo()->GetEffect(EFFECT_1))
                {
                    Unit* caster = GetCaster();
                    int32 heal_amount = effect->CalcValue(caster);

                    caster->CastCustomSpell(caster, SPELL_WARLOCK_DEVOUR_MAGIC_HEAL, &heal_amount, nullptr, nullptr, true);

                    // Glyph of Felhunter
                    if (Unit* owner = caster->GetOwner())
                        if (owner->GetAura(SPELL_WARLOCK_GLYPH_OF_DEMON_TRAINING))
                            owner->CastCustomSpell(owner, SPELL_WARLOCK_DEVOUR_MAGIC_HEAL, &heal_amount, nullptr, nullptr, true);
                }
            }

            void Register() override
            {
                OnEffectSuccessfulDispel += SpellEffectFn(spell_warl_devour_magic_SpellScript::OnSuccessfulDispel, EFFECT_0, SPELL_EFFECT_DISPEL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_devour_magic_SpellScript();
        }
};

// 47422 - Everlasting Affliction
/// Updated 4.3.4
class spell_warl_everlasting_affliction : public SpellScriptLoader
{
    public:
        spell_warl_everlasting_affliction() : SpellScriptLoader("spell_warl_everlasting_affliction") { }

        class spell_warl_everlasting_affliction_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_everlasting_affliction_SpellScript);

            void HandleScriptEffect(SpellEffIndex effIndex)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    // Refresh corruption on target
                    if (AuraEffect* aurEff = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, flag128(0x2, 0, 0), caster->GetGUID()))
                    {
                        uint32 damage = std::max(aurEff->GetAmount(), 0);
                        sScriptMgr->ModifyPeriodicDamageAurasTick(target, caster, damage);
                        aurEff->SetDamage(caster->SpellDamageBonusDone(target, aurEff->GetSpellInfo(), damage, DOT, GetEffectInfo(effIndex)) * aurEff->GetDonePct());
                        aurEff->CalculatePeriodic(caster, false, false);
                        aurEff->GetBase()->RefreshDuration(true);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warl_everlasting_affliction_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_everlasting_affliction_SpellScript();
        }
};

// -47230 - Fel Synergy
class spell_warl_fel_synergy : public SpellScriptLoader
{
    public:
        spell_warl_fel_synergy() : SpellScriptLoader("spell_warl_fel_synergy") { }

        class spell_warl_fel_synergy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_fel_synergy_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_FEL_SYNERGY_HEAL });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return false;

                return GetTarget()->GetGuardianPet() != nullptr;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 heal = CalculatePct(static_cast<int32>(eventInfo.GetDamageInfo()->GetDamage()), aurEff->GetAmount());
                GetTarget()->CastCustomSpell(SPELL_WARLOCK_FEL_SYNERGY_HEAL, SPELLVALUE_BASE_POINT0, heal, nullptr, true, nullptr, aurEff); // TARGET_UNIT_PET
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_warl_fel_synergy_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_warl_fel_synergy_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_fel_synergy_AuraScript();
        }
};

// 63310 - Glyph of Shadowflame
class spell_warl_glyph_of_shadowflame : public SpellScriptLoader
{
    public:
        spell_warl_glyph_of_shadowflame() : SpellScriptLoader("spell_warl_glyph_of_shadowflame") { }

        class spell_warl_glyph_of_shadowflame_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_glyph_of_shadowflame_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_GLYPH_OF_SHADOWFLAME });
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_WARLOCK_GLYPH_OF_SHADOWFLAME, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_glyph_of_shadowflame_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_glyph_of_shadowflame_AuraScript();
        }
};

// 48181 - Haunt
/// Updated 4.3.4
class spell_warl_haunt : public SpellScriptLoader
{
    public:
        spell_warl_haunt() : SpellScriptLoader("spell_warl_haunt") { }

        class spell_warl_haunt_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_haunt_SpellScript);

            void HandleAfterHit()
            {
                if (Aura* aura = GetHitAura())
                    if (AuraEffect* aurEff = aura->GetEffect(EFFECT_1))
                        aurEff->SetAmount(CalculatePct(aurEff->GetAmount(), GetHitDamage()));
            }

            void Register() override
            {
                AfterHit += SpellHitFn(spell_warl_haunt_SpellScript::HandleAfterHit);
            }
        };

        class spell_warl_haunt_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_haunt_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_HAUNT_HEAL });
            }

            void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    int32 amount = aurEff->GetAmount();
                    GetTarget()->CastCustomSpell(caster, SPELL_WARLOCK_HAUNT_HEAL, &amount, nullptr, nullptr, true, nullptr, aurEff, GetCasterGUID());
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectApplyFn(spell_warl_haunt_AuraScript::HandleRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_haunt_SpellScript();
        }

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_haunt_AuraScript();
        }
};

// 755 - Health Funnel
/// Updated 4.3.4
class spell_warl_health_funnel : public SpellScriptLoader
{
    public:
        spell_warl_health_funnel() : SpellScriptLoader("spell_warl_health_funnel") { }

        class spell_warl_health_funnel_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_health_funnel_AuraScript);

            void ApplyEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                Unit* target = GetTarget();
                if (caster->HasAura(SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_R2))
                    target->CastSpell(target, SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R2, true);
                else if (caster->HasAura(SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_R1))
                    target->CastSpell(target, SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R1, true);
            }

            void RemoveEffect(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->RemoveAurasDueToSpell(SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R1);
                target->RemoveAurasDueToSpell(SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R2);
            }

            void OnPeriodic(AuraEffect const* aurEff)
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;
                //! HACK for self damage, is not blizz :/
                uint32 damage = caster->CountPctFromMaxHealth(aurEff->GetBaseAmount());

                if (Player* modOwner = caster->GetSpellModOwner())
                    modOwner->ApplySpellMod(GetId(), SPELLMOD_COST, damage);

                SpellNonMeleeDamage damageInfo(caster, caster, GetSpellInfo(), GetAura()->GetSpellXSpellVisualId(), GetSpellInfo()->SchoolMask, GetAura()->GetCastGUID());
                damageInfo.periodicLog = true;
                damageInfo.damage = damage;
                caster->DealSpellDamage(&damageInfo, false);
                caster->SendSpellNonMeleeDamageLog(&damageInfo);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_warl_health_funnel_AuraScript::ApplyEffect, EFFECT_0, SPELL_AURA_OBS_MOD_HEALTH, AURA_EFFECT_HANDLE_REAL);
                OnEffectRemove += AuraEffectRemoveFn(spell_warl_health_funnel_AuraScript::RemoveEffect, EFFECT_0, SPELL_AURA_OBS_MOD_HEALTH, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_health_funnel_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_OBS_MOD_HEALTH);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_health_funnel_AuraScript();
        }
};

// 6262 - Healthstone
class spell_warl_healthstone_heal : public SpellScriptLoader
{
    public:
        spell_warl_healthstone_heal() : SpellScriptLoader("spell_warl_healthstone_heal") { }

        class spell_warl_healthstone_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_healthstone_heal_SpellScript);

            void HandleOnHit()
            {
                int32 heal = int32(CalculatePct(GetCaster()->GetCreateHealth(), GetHitHeal()));
                SetHitHeal(heal);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_warl_healthstone_heal_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_healthstone_heal_SpellScript();
        }
};

// -18119 - Improved Soul Fire
class spell_warl_improved_soul_fire : public SpellScriptLoader
{
    public:
        spell_warl_improved_soul_fire() : SpellScriptLoader("spell_warl_improved_soul_fire") { }

        class spell_warl_improved_soul_fire_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_improved_soul_fire_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_IMPROVED_SOUL_FIRE_PCT, SPELL_WARLOCK_IMPROVED_SOUL_FIRE_STATE });
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastCustomSpell(SPELL_WARLOCK_IMPROVED_SOUL_FIRE_PCT, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, nullptr, aurEff);
                GetTarget()->CastSpell(GetTarget(), SPELL_WARLOCK_IMPROVED_SOUL_FIRE_STATE, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_improved_soul_fire_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_improved_soul_fire_AuraScript();
        }
};

// 687 - Demon Armor
// 28176 - Fel Armor
class spell_warl_nether_ward_overrride : public SpellScriptLoader
{
    public:
        spell_warl_nether_ward_overrride() : SpellScriptLoader("spell_warl_nether_ward_overrride") { }

        class spell_warl_nether_ward_overrride_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_nether_ward_overrride_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_WARLOCK_NETHER_TALENT,
                    SPELL_WARLOCK_NETHER_WARD,
                    SPELL_WARLOCK_SHADOW_WARD
                });
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (GetUnitOwner()->HasAura(SPELL_WARLOCK_NETHER_TALENT))
                    amount = SPELL_WARLOCK_NETHER_WARD;
                else
                    amount = SPELL_WARLOCK_SHADOW_WARD;
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_nether_ward_overrride_AuraScript::CalculateAmount, EFFECT_2, SPELL_AURA_OVERRIDE_ACTIONBAR_SPELLS);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_nether_ward_overrride_AuraScript();
        }
};

// 6358 - Seduction (Special Ability)
class spell_warl_seduction : public SpellScriptLoader
{
    public:
        spell_warl_seduction() : SpellScriptLoader("spell_warl_seduction") { }

        class spell_warl_seduction_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_seduction_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_GLYPH_OF_SUCCUBUS, SPELL_PRIEST_SHADOW_WORD_DEATH });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    if (caster->GetOwner() && caster->GetOwner()->HasAura(SPELL_WARLOCK_GLYPH_OF_SUCCUBUS))
                    {
                        target->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE, ObjectGuid::Empty, target->GetAura(SPELL_PRIEST_SHADOW_WORD_DEATH)); // SW:D shall not be removed.
                        target->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                        target->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warl_seduction_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_seduction_SpellScript();
        }
};

// 27285 - Seed of Corruption
/// Updated 4.3.4
class spell_warl_seed_of_corruption : public SpellScriptLoader
{
    public:
        spell_warl_seed_of_corruption() : SpellScriptLoader("spell_warl_seed_of_corruption") { }

        class spell_warl_seed_of_corruption_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_seed_of_corruption_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (GetExplTargetUnit())
                    targets.remove(GetExplTargetUnit());
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_warl_seed_of_corruption_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_seed_of_corruption_SpellScript();
        }
};

// 27243 - Seed of Corruption
class spell_warl_seed_of_corruption_dummy : public SpellScriptLoader
{
    public:
        spell_warl_seed_of_corruption_dummy() : SpellScriptLoader("spell_warl_seed_of_corruption_dummy") { }

        class spell_warl_seed_of_corruption_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_seed_of_corruption_dummy_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_SEED_OF_CORRUPTION_DAMAGE });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                int32 amount = aurEff->GetAmount() - damageInfo->GetDamage();
                if (amount > 0)
                {
                    const_cast<AuraEffect*>(aurEff)->SetAmount(amount);
                    if (!GetTarget()->HealthBelowPctDamaged(1, damageInfo->GetDamage()))
                        return;
                }

                Remove();

                Unit* caster = GetCaster();
                if (!caster)
                    return;

                caster->CastSpell(eventInfo.GetActionTarget(), SPELL_WARLOCK_SEED_OF_CORRUPTION_DAMAGE, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_seed_of_corruption_dummy_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_seed_of_corruption_dummy_AuraScript();
        }
};

// 32863 - Seed of Corruption
// 36123 - Seed of Corruption
// 38252 - Seed of Corruption
// 39367 - Seed of Corruption
// 44141 - Seed of Corruption
// 70388 - Seed of Corruption
// Monster spells, triggered only on amount drop (not on death)
class spell_warl_seed_of_corruption_generic : public SpellScriptLoader
{
    public:
        spell_warl_seed_of_corruption_generic() : SpellScriptLoader("spell_warl_seed_of_corruption_generic") { }

        class spell_warl_seed_of_corruption_generic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_seed_of_corruption_generic_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_SEED_OF_CORRUPTION_GENERIC });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                int32 amount = aurEff->GetAmount() - damageInfo->GetDamage();
                if (amount > 0)
                {
                    const_cast<AuraEffect*>(aurEff)->SetAmount(amount);
                    return;
                }

                Remove();

                Unit* caster = GetCaster();
                if (!caster)
                    return;

                caster->CastSpell(eventInfo.GetActionTarget(), SPELL_WARLOCK_SEED_OF_CORRUPTION_GENERIC, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_seed_of_corruption_generic_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_seed_of_corruption_generic_AuraScript();
        }
};

// -7235 - Shadow Ward
class spell_warl_shadow_ward : public SpellScriptLoader
{
    public:
        spell_warl_shadow_ward() : SpellScriptLoader("spell_warl_shadow_ward") { }

        class spell_warl_shadow_ward_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_shadow_ward_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& canBeRecalculated)
            {
                canBeRecalculated = false;
                if (Unit* caster = GetCaster())
                {
                    // +80.68% from sp bonus
                    float bonus = 0.8068f;

                    bonus *= caster->SpellBaseHealingBonusDone(GetSpellInfo()->GetSchoolMask());

                    amount += int32(bonus);
                }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_warl_shadow_ward_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_shadow_ward_AuraScript();
        }
};

// -30293 - Soul Leech
class spell_warl_soul_leech : public SpellScriptLoader
{
    public:
        spell_warl_soul_leech() : SpellScriptLoader("spell_warl_soul_leech") { }

        class spell_warl_soul_leech_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_soul_leech_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_GEN_REPLENISHMENT });
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                GetTarget()->CastSpell(nullptr, SPELL_GEN_REPLENISHMENT, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_soul_leech_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL_WITH_VALUE);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_soul_leech_AuraScript();
        }
};

// 86121 - Soul Swap
class spell_warl_soul_swap : public SpellScriptLoader
{
    public:
        spell_warl_soul_swap() : SpellScriptLoader("spell_warl_soul_swap") { }

        class spell_warl_soul_swap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_soul_swap_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_WARLOCK_GLYPH_OF_SOUL_SWAP,
                    SPELL_WARLOCK_SOUL_SWAP_CD_MARKER,
                    SPELL_WARLOCK_SOUL_SWAP_OVERRIDE
                });
            }

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_SOUL_SWAP_OVERRIDE, true);
                GetHitUnit()->CastSpell(GetCaster(), SPELL_WARLOCK_SOUL_SWAP_DOT_MARKER, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warl_soul_swap_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_soul_swap_SpellScript();
        }
};

// 86211 - Soul Swap Override - Also acts as a dot container
class spell_warl_soul_swap_override : public SpellScriptLoader
{
    public:
        static char constexpr const ScriptName[] = "spell_warl_soul_swap_override";

        spell_warl_soul_swap_override() : SpellScriptLoader(ScriptName) { }

        class spell_warl_soul_swap_override_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_soul_swap_override_AuraScript);

            //! Forced to, pure virtual functions must have a body when linking
            void Register() override { }

        public:
            void AddDot(uint32 id)                          { _dotList.push_back(id); }
            std::list<uint32> const GetDotList() const      { return _dotList; }
            Unit* GetOriginalSwapSource() const             { return _swapCaster; }
            void SetOriginalSwapSource(Unit* victim)        { _swapCaster = victim; }

        private:
            std::list<uint32> _dotList;
            Unit* _swapCaster = nullptr;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_soul_swap_override_AuraScript();
        }
};
char constexpr const spell_warl_soul_swap_override::ScriptName[];

typedef spell_warl_soul_swap_override::spell_warl_soul_swap_override_AuraScript SoulSwapOverrideAuraScript;

//! Soul Swap Copy Spells - 92795 - Simply copies spell IDs.
class spell_warl_soul_swap_dot_marker : public SpellScriptLoader
{
    public:
        spell_warl_soul_swap_dot_marker() : SpellScriptLoader("spell_warl_soul_swap_dot_marker") { }

        class spell_warl_soul_swap_dot_marker_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_soul_swap_dot_marker_SpellScript);

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                Unit* swapVictim = GetCaster();
                Unit* warlock    = GetHitUnit();
                if (!warlock || !swapVictim)
                    return;

                Unit::AuraApplicationMap const& appliedAuras = swapVictim->GetAppliedAuras();
                SoulSwapOverrideAuraScript* swapSpellScript = nullptr;
                if (Aura* swapOverrideAura = warlock->GetAura(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE))
                    swapSpellScript = swapOverrideAura->GetScript<SoulSwapOverrideAuraScript>(spell_warl_soul_swap_override::ScriptName);

                if (!swapSpellScript)
                    return;

                flag128 classMask = GetEffectInfo()->SpellClassMask;

                for (Unit::AuraApplicationMap::const_iterator itr = appliedAuras.begin(); itr != appliedAuras.end(); ++itr)
                {
                    SpellInfo const* spellProto = itr->second->GetBase()->GetSpellInfo();
                    if (itr->second->GetBase()->GetCaster() == warlock)
                        if (spellProto->SpellFamilyName == SPELLFAMILY_WARLOCK && (spellProto->SpellFamilyFlags & classMask))
                            swapSpellScript->AddDot(itr->first);
                }

                swapSpellScript->SetOriginalSwapSource(swapVictim);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warl_soul_swap_dot_marker_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_soul_swap_dot_marker_SpellScript();
        }
};

// 86213 - Soul Swap Exhale
class spell_warl_soul_swap_exhale : public SpellScriptLoader
{
public:
    spell_warl_soul_swap_exhale() : SpellScriptLoader("spell_warl_soul_swap_exhale") { }

    class spell_warl_soul_swap_exhale_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_warl_soul_swap_exhale_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_WARLOCK_SOUL_SWAP_MOD_COST, SPELL_WARLOCK_SOUL_SWAP_OVERRIDE });
        }

        SpellCastResult CheckCast()
        {
            Unit* currentTarget = GetExplTargetUnit();
            Unit* swapTarget = nullptr;
            if (Aura const* swapOverride = GetCaster()->GetAura(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE))
                if (SoulSwapOverrideAuraScript* swapScript = swapOverride->GetScript<SoulSwapOverrideAuraScript>(spell_warl_soul_swap_override::ScriptName))
                    swapTarget = swapScript->GetOriginalSwapSource();

            // Soul Swap Exhale can't be cast on the same target than Soul Swap
            if (swapTarget && currentTarget && swapTarget == currentTarget)
                return SPELL_FAILED_BAD_TARGETS;

            return SPELL_CAST_OK;
        }

        void OnEffectHit(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_SOUL_SWAP_MOD_COST, true);
            bool hasGlyph = GetCaster()->HasAura(SPELL_WARLOCK_GLYPH_OF_SOUL_SWAP);

            std::list<uint32> dotList;
            Unit* swapSource = nullptr;
            if (Aura const* swapOverride = GetCaster()->GetAura(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE))
            {
                SoulSwapOverrideAuraScript* swapScript = swapOverride->GetScript<SoulSwapOverrideAuraScript>(spell_warl_soul_swap_override::ScriptName);
                if (!swapScript)
                    return;
                dotList = swapScript->GetDotList();
                swapSource = swapScript->GetOriginalSwapSource();
            }

            if (dotList.empty())
                return;

            for (std::list<uint32>::const_iterator itr = dotList.begin(); itr != dotList.end(); ++itr)
            {
                GetCaster()->AddAura(*itr, GetHitUnit());
                if (!hasGlyph && swapSource)
                    swapSource->RemoveAurasDueToSpell(*itr);
            }

            // Remove Soul Swap Exhale buff
            GetCaster()->RemoveAurasDueToSpell(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE);

            if (hasGlyph) // Add a cooldown on Soul Swap if caster has the glyph
                GetCaster()->CastSpell(GetCaster(), SPELL_WARLOCK_SOUL_SWAP_CD_MARKER, false);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_warl_soul_swap_exhale_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_warl_soul_swap_exhale_SpellScript::OnEffectHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_warl_soul_swap_exhale_SpellScript();
    }
};

// 29858 - Soulshatter
/// Updated 4.3.4
class spell_warl_soulshatter : public SpellScriptLoader
{
    public:
        spell_warl_soulshatter() : SpellScriptLoader("spell_warl_soulshatter") { }

        class spell_warl_soulshatter_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_soulshatter_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_SOULSHATTER });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                    if (target->CanHaveThreatList() && target->GetThreatManager().IsThreatenedBy(caster, true))
                        caster->CastSpell(target, SPELL_WARLOCK_SOULSHATTER, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warl_soulshatter_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_soulshatter_SpellScript();
        }
};

// 37377 - Shadowflame
// 39437 - Shadowflame Hellfire and RoF
template <uint32 TriggerSpellId>
class spell_warl_t4_2p_bonus : public SpellScriptLoader
{
    public:
        spell_warl_t4_2p_bonus(char const* ScriptName) : SpellScriptLoader(ScriptName) { }

        template <uint32 Trigger>
        class spell_warl_t4_2p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_t4_2p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ Trigger });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                caster->CastSpell(caster, Trigger, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_t4_2p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_t4_2p_bonus_AuraScript<TriggerSpellId>();
        }
};

// 30108, 34438, 34439, 35183 - Unstable Affliction
/// Updated 4.3.4
class spell_warl_unstable_affliction : public SpellScriptLoader
{
    public:
        spell_warl_unstable_affliction() : SpellScriptLoader("spell_warl_unstable_affliction") { }

        class spell_warl_unstable_affliction_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_unstable_affliction_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_UNSTABLE_AFFLICTION_DISPEL });
            }

            void HandleDispel(DispelInfo* dispelInfo)
            {
                if (Unit* caster = GetCaster())
                    if (AuraEffect const* aurEff = GetEffect(EFFECT_1))
                    {
                        int32 damage = aurEff->GetAmount() * 9;
                        // backfire damage and silence
                        caster->CastCustomSpell(dispelInfo->GetDispeller(), SPELL_WARLOCK_UNSTABLE_AFFLICTION_DISPEL, &damage, nullptr, nullptr, true, nullptr, aurEff);
                    }
            }

            void Register() override
            {
                AfterDispel += AuraDispelFn(spell_warl_unstable_affliction_AuraScript::HandleDispel);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_unstable_affliction_AuraScript();
        }
};

// 5740 - Rain of Fire
/// Updated 7.1.5
class spell_warl_rain_of_fire : public SpellScriptLoader
{
public:
    spell_warl_rain_of_fire() : SpellScriptLoader("spell_warl_rain_of_fire") { }

    class spell_warl_rain_of_fire_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_rain_of_fire_AuraScript);

        void HandleDummyTick(AuraEffect const* /*aurEff*/)
        {
            std::vector<AreaTrigger*> rainOfFireAreaTriggers = GetTarget()->GetAreaTriggers(SPELL_WARLOCK_RAIN_OF_FIRE);
            GuidUnorderedSet targetsInRainOfFire;

            for (AreaTrigger* rainOfFireAreaTrigger : rainOfFireAreaTriggers)
            {
                GuidUnorderedSet const& insideTargets = rainOfFireAreaTrigger->GetInsideUnits();
                targetsInRainOfFire.insert(insideTargets.begin(), insideTargets.end());
            }

            for (ObjectGuid insideTargetGuid : targetsInRainOfFire)
                if (Unit* insideTarget = ObjectAccessor::GetUnit(*GetTarget(), insideTargetGuid))
                    if (!GetTarget()->IsFriendlyTo(insideTarget))
                        GetTarget()->CastSpell(insideTarget, SPELL_WARLOCK_RAIN_OF_FIRE_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_rain_of_fire_AuraScript::HandleDummyTick, EFFECT_3, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_rain_of_fire_AuraScript();
    }
};

void AddSC_warlock_spell_scripts()
{
    new spell_warl_bane_of_doom();
    new spell_warl_banish();
    RegisterAuraScript(spell_warl_chaotic_energies);
    new spell_warl_conflagrate();
    new spell_warl_create_healthstone();
    new spell_warl_demonic_circle_summon();
    new spell_warl_demonic_circle_teleport();
    new spell_warl_demonic_empowerment();
    new spell_warl_demon_soul();
    new spell_warl_devour_magic();
    new spell_warl_everlasting_affliction();
    new spell_warl_fel_synergy();
    new spell_warl_glyph_of_shadowflame();
    new spell_warl_haunt();
    new spell_warl_health_funnel();
    new spell_warl_healthstone_heal();
    new spell_warl_improved_soul_fire();
    new spell_warl_nether_ward_overrride();
    new spell_warl_seduction();
    new spell_warl_seed_of_corruption();
    new spell_warl_seed_of_corruption_dummy();
    new spell_warl_seed_of_corruption_generic();
    new spell_warl_shadow_ward();
    new spell_warl_soul_leech();
    new spell_warl_soul_swap();
    new spell_warl_soul_swap_dot_marker();
    new spell_warl_soul_swap_exhale();
    new spell_warl_soul_swap_override();
    new spell_warl_soulshatter();
    new spell_warl_t4_2p_bonus<SPELL_WARLOCK_FLAMESHADOW>("spell_warl_t4_2p_bonus_shadow");
    new spell_warl_t4_2p_bonus<SPELL_WARLOCK_SHADOWFLAME>("spell_warl_t4_2p_bonus_fire");
    new spell_warl_unstable_affliction();
    new spell_warl_rain_of_fire();
}
