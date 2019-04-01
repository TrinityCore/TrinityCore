/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "Creature.h"
#include "GameObject.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "Random.h"
#include "Spell.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum WarlockSpells
{
    SPELL_WARLOCK_AFTERMATH_STUN                    = 85387,
    SPELL_WARLOCK_BANE_OF_DOOM_EFFECT               = 18662,
    SPELL_WARLOCK_CREATE_HEALTHSTONE                = 34130,
    SPELL_WARLOCK_CORRUPTION_TRIGGERED              = 87389,
    SPELL_WARLOCK_CURSE_OF_DOOM_EFFECT              = 18662,
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
    SPELL_WARLOCK_DRAIN_LIFE                        = 689,
    SPELL_WARLOCK_DRAIN_LIFE_HEAL                   = 89653,
    SPELL_WARLOCK_DRAIN_LIFE_SOULBURN               = 89420,
    SPELL_WARLOCK_FEL_ARMOR_HEAL                    = 96379,
    SPELL_WARLOCK_FEL_SYNERGY_HEAL                  = 54181,
    SPELL_WARLOCK_GLYPH_OF_SHADOWFLAME              = 63311,
    SPELL_WARLOCK_GLYPH_OF_SIPHON_LIFE              = 63106,
    SPELL_WARLOCK_GLYPH_OF_SOUL_SWAP                = 56226,
    SPELL_WARLOCK_GLYPH_OF_SUCCUBUS                 = 56250,
    SPELL_WARLOCK_HAUNT                             = 48181,
    SPELL_WARLOCK_HAUNT_HEAL                        = 48210,
    SPELL_WARLOCK_HEALTHSTONE                       = 6262,
    SPELL_WARLOCK_IMMOLATE                          = 348,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R1    = 60955,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R2    = 60956,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_R1         = 18703,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_R2         = 18704,
    SPELL_WARLOCK_IMPROVED_SOUL_FIRE_PCT            = 85383,
    SPELL_WARLOCK_IMPROVED_SOUL_FIRE_STATE          = 85385,
    SPELL_WARLOCK_LIFE_TAP_ENERGIZE                 = 31818,
    SPELL_WARLOCK_LIFE_TAP_ENERGIZE_2               = 32553,
    SPELL_WARLOCK_NETHER_WARD                       = 91711,
    SPELL_WARLOCK_NETHER_TALENT                     = 91713,
    SPELL_WARLOCK_RAIN_OF_FIRE                      = 42223,
    SPELL_WARLOCK_SHADOW_TRANCE                     = 17941,
    SPELL_WARLOCK_SEARING_PAIN                      = 5676,
    SPELL_WARLOCK_SEED_OF_CORRUPTION                = 27243,
    SPELL_WARLOCK_SEED_OF_CORRUPTION_TRIGGERED      = 87385,
    SPELL_WARLOCK_SEED_OF_CORRUPTION_VISUAL         = 37826,
    SPELL_WARLOCK_SIPHON_LIFE_HEAL                  = 63106,
    SPELL_WARLOCK_SHADOW_WARD                       = 6229,
    SPELL_WARLOCK_SOULBURN_HEALTHSTONE              = 79437,
    SPELL_WARLOCK_SOULBURN_DEMONIC_CIRCLE           = 79438,
    SPELL_WARLOCK_SOULBURN_SEARING_PAIN             = 79440,
    SPELL_WARLOCK_SOULBURN_DUMMY_SEED_OF_CORRUPTION = 93313,
    SPELL_WARLOCK_SOUL_HARVEST_ENERGIZE             = 101977,
    SPELL_WARLOCK_SOUL_SHARD                        = 87388,
    SPELL_WARLOCK_SOUL_SHARD_ENERGIZE               = 95810,
    SPELL_WARLOCK_SOULSHATTER                       = 32835,
    SPELL_WARLOCK_SOUL_SWAP_CD_MARKER               = 94229,
    SPELL_WARLOCK_SOUL_SWAP_OVERRIDE                = 86211,
    SPELL_WARLOCK_SOUL_SWAP_MOD_COST                = 92794,
    SPELL_WARLOCK_SOUL_SWAP_DOT_MARKER              = 92795,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION               = 30108,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION_DISPEL        = 31117
};

enum WarlockSpellIcons
{
    WARLOCK_ICON_ID_IMPROVED_LIFE_TAP               = 208,
    WARLOCK_ICON_ID_MANA_FEED                       = 1982,
	WARLOCK_ICON_ID_DEATHS_EMBRACE                  = 3223,
	WARLOCK_ICON_ID_SOUL_SIPHON                     = 5001,
    WARLOCK_ICON_ID_SOULBURN_SEED_OF_CORRUPTION     = 1932
};

enum WarlockSkillIds
{
    WARLOCK_SKILL_ID_AFFLICTION                     = 355
};

enum MiscSpells
{
    SPELL_GEN_REPLENISHMENT                         = 57669,
    SPELL_PRIEST_SHADOW_WORD_DEATH                  = 32409
};

// -85113 - Aftermath
class spell_warl_aftermath : public SpellScriptLoader
{
    public:
        spell_warl_aftermath() : SpellScriptLoader("spell_warl_aftermath") { }

        class spell_warl_aftermath_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_aftermath_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_AFTERMATH_STUN });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                if (eventInfo.GetDamageInfo()->GetSpellInfo()->Id == SPELL_WARLOCK_RAIN_OF_FIRE)
                {
                    PreventDefaultAction();

                    if (eventInfo.GetProcTarget() && roll_chance_i(aurEff->GetAmount()))
                        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_WARLOCK_AFTERMATH_STUN, true, nullptr, aurEff);
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_aftermath_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_aftermath_AuraScript();
        }
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
            spell_warl_banish_SpellScript()
            {
                _removed = false;
            }

        private:
            void HandleBanish()
            {
                /// Casting Banish on a banished target will cancel the effect
                /// Check if the target already has Banish, if so, do nothing.
                if (Unit* target = GetHitUnit())
                {
                    if (target->GetAuraEffect(SPELL_AURA_SCHOOL_IMMUNITY, SPELLFAMILY_WARLOCK, 0, 0x08000000, 0))
                    {
                        // No need to remove old aura since its removed due to not stack by current Banish aura
                        PreventHitDefaultEffect(EFFECT_0);
                        PreventHitDefaultEffect(EFFECT_1);
                        PreventHitDefaultEffect(EFFECT_2);
                        _removed = true;
                    }
                }
            }

            void RemoveAura()
            {
                if (_removed)
                    PreventHitAura();
            }

            void Register() override
            {
                BeforeHit += SpellHitFn(spell_warl_banish_SpellScript::HandleBanish);
                AfterHit += SpellHitFn(spell_warl_banish_SpellScript::RemoveAura);
            }

            bool _removed;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_banish_SpellScript();
        }
};

// 17962 - Conflagrate
class spell_warl_conflagrate : public SpellScript
{
    PrepareSpellScript(spell_warl_conflagrate);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_IMMOLATE });
    }

    void HandleHit(SpellEffIndex /*effIndex*/)
    {
        if (AuraEffect const* aurEff = GetHitUnit()->GetAuraEffect(SPELL_WARLOCK_IMMOLATE, EFFECT_2, GetCaster()->GetGUID()))
        {
            int32 damage = aurEff->GetAmount();
            damage += GetCaster()->SpellDamageBonusDone(GetHitUnit(), aurEff->GetSpellInfo(), damage, DOT, EFFECT_2);
            damage *= aurEff->GetTotalTicks();
            SetHitDamage(CalculatePct(damage, GetSpellInfo()->Effects[EFFECT_1].CalcValue(GetCaster())));
        }
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_warl_conflagrate::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
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

                    SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_WARLOCK_DEMONIC_CIRCLE_TELEPORT);

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
                        player->RemoveMovementImpairingAuras();
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
                        CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(targetCreature->GetEntry());
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
                        CreatureTemplate const* ci = sObjectMgr->GetCreatureTemplate(targetCreature->GetEntry());
                        ASSERT(ci);
                        switch (ci->family)
                        {
                            case CREATURE_FAMILY_SUCCUBUS:
                                targetCreature->CastSpell(targetCreature, SPELL_WARLOCK_DEMONIC_EMPOWERMENT_SUCCUBUS, true);
                                break;
                            case CREATURE_FAMILY_VOIDWALKER:
                            {
                                SpellInfo const* spellInfo = sSpellMgr->AssertSpellInfo(SPELL_WARLOCK_DEMONIC_EMPOWERMENT_VOIDWALKER);
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

// 47422 - Everlasting Affliction
/// Updated 4.3.4
class spell_warl_everlasting_affliction : public SpellScriptLoader
{
    public:
        spell_warl_everlasting_affliction() : SpellScriptLoader("spell_warl_everlasting_affliction") { }

        class spell_warl_everlasting_affliction_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_everlasting_affliction_SpellScript);

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    // Refresh corruption on target
                    if (AuraEffect* aurEff = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x2, 0, 0, caster->GetGUID()))
                    {
                        aurEff->SetBonusAmount(caster->SpellDamageBonusDone(target, aurEff->GetSpellInfo(), 0, DOT, aurEff->GetEffIndex()));
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

// 77799 - Fel Flame - Updated to 4.3.4
class spell_warl_fel_flame : public SpellScriptLoader
{
    public:
        spell_warl_fel_flame() : SpellScriptLoader("spell_warl_fel_flame") { }

        class spell_warl_fel_flame_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_fel_flame_SpellScript);

            void OnHitTarget(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();
                Aura* aura = target->GetAura(SPELL_WARLOCK_UNSTABLE_AFFLICTION, caster->GetGUID());
                if (!aura)
                    aura = target->GetAura(SPELL_WARLOCK_IMMOLATE, caster->GetGUID());

                if (!aura)
                    return;

                int32 newDuration = aura->GetDuration() + GetSpellInfo()->Effects[EFFECT_1].CalcValue() * 1000;
                aura->SetDuration(std::min(newDuration, aura->GetMaxDuration()));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warl_fel_flame_SpellScript::OnHitTarget, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_fel_flame_SpellScript;
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
                return GetTarget()->GetGuardianPet() && eventInfo.GetDamageInfo()->GetDamage();
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 heal = CalculatePct(int32(eventInfo.GetDamageInfo()->GetDamage()), aurEff->GetAmount());
                GetTarget()->CastCustomSpell(SPELL_WARLOCK_FEL_SYNERGY_HEAL, SPELLVALUE_BASE_POINT0, heal, (Unit*)nullptr, true, nullptr, aurEff); // TARGET_UNIT_PET
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

                SpellNonMeleeDamage damageInfo(caster, caster, GetSpellInfo()->Id, GetSpellInfo()->SchoolMask);
                damageInfo.damage = damage;
                caster->SendSpellNonMeleeDamageLog(&damageInfo);
                caster->DealSpellDamage(&damageInfo, false);
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

// 1454 - Life Tap
/// Updated 4.3.4
class spell_warl_life_tap : public SpellScriptLoader
{
    public:
        spell_warl_life_tap() : SpellScriptLoader("spell_warl_life_tap") { }

        class spell_warl_life_tap_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_life_tap_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_LIFE_TAP_ENERGIZE, SPELL_WARLOCK_LIFE_TAP_ENERGIZE_2 });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Player* caster = GetCaster()->ToPlayer();
                if (Unit* target = GetHitUnit())
                {
                    int32 damage = caster->CountPctFromMaxHealth(GetSpellInfo()->Effects[EFFECT_2].CalcValue());
                    int32 mana = CalculatePct(damage, GetSpellInfo()->Effects[EFFECT_1].CalcValue());

                    // Shouldn't Appear in Combat Log
                    target->ModifyHealth(-damage);

                    // Improved Life Tap mod
                    if (AuraEffect const* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_WARLOCK, WARLOCK_ICON_ID_IMPROVED_LIFE_TAP, 0))
                        AddPct(mana, aurEff->GetAmount());

                    caster->CastCustomSpell(target, SPELL_WARLOCK_LIFE_TAP_ENERGIZE, &mana, nullptr, nullptr, false);

                    // Mana Feed
                    if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_WARLOCK, WARLOCK_ICON_ID_MANA_FEED, 0))
                    {
                        int32 manaFeedVal = aurEff->GetAmount();
                        ApplyPct(manaFeedVal, mana);
                        caster->CastCustomSpell(caster, SPELL_WARLOCK_LIFE_TAP_ENERGIZE_2, &manaFeedVal, nullptr, nullptr, true, nullptr);
                    }
                }
            }

            SpellCastResult CheckCast()
            {
                if (int32(GetCaster()->GetHealth()) > int32(GetCaster()->CountPctFromMaxHealth(GetSpellInfo()->Effects[EFFECT_2].CalcValue())))
                    return SPELL_CAST_OK;
                return SPELL_FAILED_FIZZLE;
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warl_life_tap_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                OnCheckCast += SpellCheckCastFn(spell_warl_life_tap_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_life_tap_SpellScript();
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

// 27243 - Seed of Corruption
class spell_warl_seed_of_corruption : public AuraScript
{
    PrepareAuraScript(spell_warl_seed_of_corruption);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_WARLOCK_SEED_OF_CORRUPTION_TRIGGERED,
                SPELL_WARLOCK_SEED_OF_CORRUPTION_VISUAL,
                SPELL_WARLOCK_SOUL_SHARD
            });
    }

    void OnAuraRemoveHandler(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
        {
            caster->CastSpell(GetTarget(), SPELL_WARLOCK_SEED_OF_CORRUPTION_TRIGGERED, true, nullptr, aurEff);
            caster->CastSpell(GetTarget(), SPELL_WARLOCK_SEED_OF_CORRUPTION_VISUAL, true, nullptr, aurEff);

            //if (AuraEffect* dummy = caster->GetDummyAuraEffect(SPELLFAMILY_WARLOCK, WARLOCK_ICON_ID_SOULBURN_SEED_OF_CORRUPTION, EFFECT_0))
            //    caster->CastSpell(caster, SPELL_WARLOCK_SOUL_SHARD, true, nullptr, aurEff);
        }
        // else if (AuraEffect* dummy = caster->GetDummyAuraEffect(SPELLFAMILY_WARLOCK, WARLOCK_ICON_ID_SOULBURN_SEED_OF_CORRUPTION, EFFECT_0))
        //caster->CastSpell(target, SPELL_WARLOCK_CORRUPTION_TRIGGERED, true, nullptr, aurEff);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_warl_seed_of_corruption::OnAuraRemoveHandler, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// -18094 - Nightfall
// 56218 - Glyph of Corruption
class spell_warl_shadow_trance_proc : public SpellScriptLoader
{
    public:
        spell_warl_shadow_trance_proc() : SpellScriptLoader("spell_warl_shadow_trance_proc") { }

        class spell_warl_shadow_trance_proc_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_shadow_trance_proc_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_SHADOW_TRANCE });
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_WARLOCK_SHADOW_TRANCE, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_shadow_trance_proc_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_shadow_trance_proc_AuraScript();
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
                GetTarget()->CastSpell((Unit*)nullptr, SPELL_GEN_REPLENISHMENT, true, nullptr, aurEff);
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

            bool Load() override
            {
                _swapCaster = nullptr;
                return true;
            }

            //! Forced to, pure virtual functions must have a body when linking
            void Register() override { }

        public:
            void AddDot(uint32 id)                          { _dotList.push_back(id); }
            std::list<uint32> const GetDotList() const      { return _dotList; }
            Unit* GetOriginalSwapSource() const             { return _swapCaster; }
            void SetOriginalSwapSource(Unit* victim)        { _swapCaster = victim; }

        private:
            std::list<uint32> _dotList;
            Unit* _swapCaster;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_soul_swap_override_AuraScript();
        }
};
char constexpr const spell_warl_soul_swap_override::ScriptName[];

//! Soul Swap Copy Spells - 92795 - Simply copies spell IDs.
class spell_warl_soul_swap_dot_marker : public SpellScriptLoader
{
    public:
        spell_warl_soul_swap_dot_marker() : SpellScriptLoader("spell_warl_soul_swap_dot_marker") { }

        class spell_warl_soul_swap_dot_marker_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_soul_swap_dot_marker_SpellScript);

            typedef spell_warl_soul_swap_override::spell_warl_soul_swap_override_AuraScript SoulSwapOverrideAuraScript;

            void HandleHit(SpellEffIndex effIndex)
            {
                Unit* swapVictim = GetCaster();
                Unit* warlock    = GetHitUnit();
                if (!warlock || !swapVictim)
                    return;

                flag96 classMask = GetSpellInfo()->Effects[effIndex].SpellClassMask;

                Unit::AuraApplicationMap const& appliedAuras = swapVictim->GetAppliedAuras();
                SoulSwapOverrideAuraScript* swapSpellScript = nullptr;
                if (Aura* swapOverrideAura = warlock->GetAura(SPELL_WARLOCK_SOUL_SWAP_OVERRIDE))
                    swapSpellScript = swapOverrideAura->GetScript<SoulSwapOverrideAuraScript>(spell_warl_soul_swap_override::ScriptName);

                if (swapSpellScript == nullptr)
                    return;

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

        typedef spell_warl_soul_swap_override::spell_warl_soul_swap_override_AuraScript SoulSwapOverrideAuraScript;

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo(
            {
                SPELL_WARLOCK_SOUL_SWAP_MOD_COST,
                SPELL_WARLOCK_SOUL_SWAP_OVERRIDE
            });
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
                    if (target->CanHaveThreatList() && target->getThreatManager().getThreat(caster) > 0.0f)
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

// 689 / 89420 - Drain Life
class spell_warl_drain_life : public SpellScriptLoader
{
    public:
        spell_warl_drain_life() : SpellScriptLoader("spell_warl_drain_life") { }

        class spell_warl_drain_life_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_drain_life_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) 
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_DRAIN_LIFE_HEAL });
            }

            void HandlePeriodic(AuraEffect const* aurEff)
            {
                if (Unit* caster = GetCaster())
                {
                    int32 baseAmount = 0;
                    if (SpellInfo const* healspell = sSpellMgr->GetSpellInfo(SPELL_WARLOCK_DRAIN_LIFE_HEAL))
                        baseAmount = caster->CalculateSpellDamage(caster, healspell, aurEff->GetEffIndex());

                    // Death's Embrace
                    if (AuraEffect const* deathsEmbraceAurEff = caster->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_WARLOCK, WARLOCK_ICON_ID_DEATHS_EMBRACE, 0))
                        if (caster->HealthBelowPct(25))
                            baseAmount += int32(deathsEmbraceAurEff->GetAmount());

                    caster->CastCustomSpell(caster, SPELL_WARLOCK_DRAIN_LIFE_HEAL, &baseAmount, 0, 0, true);
                }
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_drain_life_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_warl_drain_life_AuraScript();
        }
};

// 89653 - Drain Life (Health Energize)
class spell_warl_drain_life_heal : public SpellScriptLoader
{
    public:
        spell_warl_drain_life_heal() : SpellScriptLoader("spell_warl_drain_life_heal") { }

        class spell_warl_drain_life_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_drain_life_heal_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                    {
                        SPELL_WARLOCK_DRAIN_LIFE,
                        SPELL_WARLOCK_DRAIN_LIFE_SOULBURN,
                    });
            }

            void HandleSoulSiphon(SpellEffIndex effIndex)
            {
                // Soul Siphon
                int32 baseHeal = 0;
                int32 bonusHeal = 0;
                if (Unit* caster = GetCaster())
                {
                    if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_WARLOCK, WARLOCK_ICON_ID_SOUL_SIPHON, 0))
                    {
                        baseHeal = CalculatePct(caster->GetHealth(), GetSpellInfo()->Effects[effIndex].BasePoints);
                        Unit* target = nullptr;
                        if (Spell* spell = caster->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                            target = spell->m_targets.GetUnitTarget();

                        if (target)
                        {
                            uint8 afflictionAurasCount = 0;
                            if (!target->GetOwnedAuras().empty())
                                for (auto itr = target->GetOwnedAuras().begin(); itr != target->GetOwnedAuras().end(); itr++)
                                    if (Aura* auraToCheck = itr->second)
                                        if (auraToCheck->GetCasterGUID() == caster->GetGUID())
                                            if (auraToCheck->GetSpellInfo()->Id != SPELL_WARLOCK_DRAIN_LIFE && auraToCheck->GetSpellInfo()->Id != SPELL_WARLOCK_DRAIN_LIFE_SOULBURN)
                                                if (auraToCheck->GetSpellInfo()->IsAbilityOfSkillType(WARLOCK_SKILL_ID_AFFLICTION) && afflictionAurasCount < 3)
                                                {
                                                    bonusHeal += CalculatePct(baseHeal, aurEff->GetAmount());
                                                    afflictionAurasCount++;
                                                }

                            SetHitHeal(bonusHeal);
                        }
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warl_drain_life_heal_SpellScript::HandleSoulSiphon, EFFECT_0, SPELL_EFFECT_HEAL_PCT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_drain_life_heal_SpellScript();
        }
};

// 1120 - Drain Soul
class spell_warl_drain_soul : public SpellScriptLoader
{
    public:
		spell_warl_drain_soul() : SpellScriptLoader("spell_warl_drain_soul") { }

        class spell_warl_drain_soul_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_drain_soul_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/)
            {
                return ValidateSpellInfo({  SPELL_WARLOCK_SOUL_SHARD_ENERGIZE });
            }

            void OnAuraRemoveHandler(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEATH)
                    if (Unit* caster = GetCaster())
                        if (GetOwner() && caster->ToPlayer() && caster->ToPlayer()->isHonorOrXPTarget(GetOwner()->ToUnit()))
                            caster->CastSpell(caster, SPELL_WARLOCK_SOUL_SHARD_ENERGIZE, true);
            }

            void Register()
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_warl_drain_soul_AuraScript::OnAuraRemoveHandler, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_warl_drain_soul_AuraScript();
        }
};

// 28176 - Fel Armor
class spell_warl_fel_armor : public SpellScriptLoader
{
    public:
        spell_warl_fel_armor() : SpellScriptLoader("spell_warl_fel_armor") { }

        class spell_warl_fel_armor_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_fel_armor_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_WARLOCK_FEL_ARMOR_HEAL });
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 bp = CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount());
                if (Unit* caster = GetCaster())
                    caster->CastCustomSpell(caster, SPELL_WARLOCK_FEL_ARMOR_HEAL, &bp, 0, 0, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_fel_armor_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_fel_armor_AuraScript();
        }
};

class spell_warl_soul_harvest : public AuraScript
{
    PrepareAuraScript(spell_warl_soul_harvest);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_WARLOCK_SOUL_HARVEST_ENERGIZE });
    }

    void HandleDummy(AuraEffect const* aurEff)
    {
        if (!(aurEff->GetTickNumber() % 3))
            GetTarget()->CastSpell(GetTarget(), SPELL_WARLOCK_SOUL_HARVEST_ENERGIZE, true, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_warl_soul_harvest::HandleDummy, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 74434 - Soulburn
class spell_warl_soulburn : public AuraScript
{
    PrepareAuraScript(spell_warl_soulburn);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
            {
                SPELL_WARLOCK_SOULBURN_HEALTHSTONE,
                SPELL_WARLOCK_SOULBURN_SEARING_PAIN,
                SPELL_WARLOCK_SOULBURN_DEMONIC_CIRCLE,
                SPELL_WARLOCK_SOULBURN_DUMMY_SEED_OF_CORRUPTION,
                SPELL_WARLOCK_HEALTHSTONE,
                SPELL_WARLOCK_DEMONIC_CIRCLE_TELEPORT,
                SPELL_WARLOCK_SEARING_PAIN,
                SPELL_WARLOCK_SEED_OF_CORRUPTION
            });
    }

    void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* target = GetTarget();
        target->RemoveAurasDueToSpell(SPELL_WARLOCK_SOULBURN_DUMMY_SEED_OF_CORRUPTION);

        SpellInfo const* spell = eventInfo.GetSpellInfo();
        if (!spell)
            return;

        switch (spell->Id)
        {
            case SPELL_WARLOCK_HEALTHSTONE:
                target->CastSpell(target, SPELL_WARLOCK_SOULBURN_HEALTHSTONE, true, nullptr, aurEff);
                break;
            case SPELL_WARLOCK_DEMONIC_CIRCLE_TELEPORT:
                target->CastSpell(target, SPELL_WARLOCK_SOULBURN_DEMONIC_CIRCLE, true, nullptr, aurEff);
                break;
            case SPELL_WARLOCK_SEARING_PAIN:
                target->CastSpell(target, SPELL_WARLOCK_SOULBURN_SEARING_PAIN, true, nullptr, aurEff);
                break;
            case SPELL_WARLOCK_SEED_OF_CORRUPTION:
                // todo: handle me
                break;
            default:
                break;
        }
    }

    void HandleSeedOfCorruptionDummyApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (AuraEffect* dummy = GetTarget()->GetDummyAuraEffect(SPELLFAMILY_WARLOCK, WARLOCK_ICON_ID_SOULBURN_SEED_OF_CORRUPTION, EFFECT_0))
            GetTarget()->CastSpell(GetTarget(), SPELL_WARLOCK_SOULBURN_DUMMY_SEED_OF_CORRUPTION);
    }

    void HandleSeedOfCorruptionDummyRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(SPELL_WARLOCK_SOULBURN_DUMMY_SEED_OF_CORRUPTION);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_warl_soulburn::HandleProc, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER);
        AfterEffectApply += AuraEffectApplyFn(spell_warl_soulburn::HandleSeedOfCorruptionDummyApply, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_warl_soulburn::HandleSeedOfCorruptionDummyRemove, EFFECT_0, SPELL_AURA_ADD_PCT_MODIFIER, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_warlock_spell_scripts()
{
    new spell_warl_aftermath();
    new spell_warl_bane_of_doom();
    new spell_warl_banish();
    RegisterSpellScript(spell_warl_conflagrate);
    new spell_warl_create_healthstone();
    new spell_warl_demonic_circle_summon();
    new spell_warl_demonic_circle_teleport();
    new spell_warl_demonic_empowerment();
    new spell_warl_demon_soul();
    new spell_warl_drain_life();
    new spell_warl_drain_life_heal();
	new spell_warl_drain_soul();
    new spell_warl_everlasting_affliction();
    new spell_warl_fel_flame();
    new spell_warl_fel_synergy();
    new spell_warl_fel_armor();
    new spell_warl_glyph_of_shadowflame();
    new spell_warl_haunt();
    new spell_warl_health_funnel();
    new spell_warl_healthstone_heal();
    new spell_warl_improved_soul_fire();
    new spell_warl_life_tap();
    new spell_warl_nether_ward_overrride();
    new spell_warl_seduction();
    RegisterAuraScript(spell_warl_seed_of_corruption);
    new spell_warl_shadow_trance_proc();
    new spell_warl_shadow_ward();
    RegisterAuraScript(spell_warl_soulburn);
    RegisterAuraScript(spell_warl_soul_harvest);
    new spell_warl_soul_leech();
    new spell_warl_soul_swap();
    new spell_warl_soul_swap_dot_marker();
    new spell_warl_soul_swap_exhale();
    new spell_warl_soul_swap_override();
    new spell_warl_soulshatter();
    new spell_warl_unstable_affliction();
}
