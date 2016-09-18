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
 * Scripts for spells with SPELLFAMILY_WARLOCK and SPELLFAMILY_GENERIC spells used by warlock players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_warl_".
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum WarlockSpells
{
    SPELL_WARLOCK_CURSE_OF_DOOM_EFFECT              = 18662,
    SPELL_WARLOCK_DEMONIC_CIRCLE_SUMMON             = 48018,
    SPELL_WARLOCK_DEMONIC_CIRCLE_TELEPORT           = 48020,
    SPELL_WARLOCK_DEMONIC_CIRCLE_ALLOW_CAST         = 62388,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_SUCCUBUS      = 54435,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_VOIDWALKER    = 54443,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_FELGUARD      = 54508,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_FELHUNTER     = 54509,
    SPELL_WARLOCK_DEMONIC_EMPOWERMENT_IMP           = 54444,
    SPELL_WARLOCK_DEMONIC_PACT_PROC                 = 48090,
    SPELL_WARLOCK_FEL_SYNERGY_HEAL                  = 54181,
    SPELL_WARLOCK_GLYPH_OF_SHADOWFLAME              = 63311,
    SPELL_WARLOCK_GLYPH_OF_SIPHON_LIFE              = 63106,
    SPELL_WARLOCK_HAUNT                             = 48181,
    SPELL_WARLOCK_HAUNT_HEAL                        = 48210,
    SPELL_WARLOCK_IMPROVED_HEALTHSTONE_R1           = 18692,
    SPELL_WARLOCK_IMPROVED_HEALTHSTONE_R2           = 18693,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_R1         = 18703,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_R2         = 18704,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R1    = 60955,
    SPELL_WARLOCK_IMPROVED_HEALTH_FUNNEL_BUFF_R2    = 60956,
    SPELL_WARLOCK_LIFE_TAP_ENERGIZE                 = 31818,
    SPELL_WARLOCK_LIFE_TAP_ENERGIZE_2               = 32553,
    SPELL_WARLOCK_NETHER_PROTECTION_HOLY            = 54370,
    SPELL_WARLOCK_NETHER_PROTECTION_FIRE            = 54371,
    SPELL_WARLOCK_NETHER_PROTECTION_FROST           = 54372,
    SPELL_WARLOCK_NETHER_PROTECTION_ARCANE          = 54373,
    SPELL_WARLOCK_NETHER_PROTECTION_SHADOW          = 54374,
    SPELL_WARLOCK_NETHER_PROTECTION_NATURE          = 54375,
    SPELL_WARLOCK_SOULSHATTER                       = 32835,
    SPELL_WARLOCK_SIPHON_LIFE_HEAL                  = 63106,
    SPELL_WARLOCK_UNSTABLE_AFFLICTION_DISPEL        = 31117,
    SPELL_WARLOCK_GLYPH_OF_LIFE_TAP_TRIGGERED       = 63321,
    SPELL_WARLOCK_SEED_OF_CORRUPTION_DAMAGE_R1      = 27285,
    SPELL_WARLOCK_SEED_OF_CORRUPTION_GENERIC        = 32865,
    SPELL_WARLOCK_SHADOW_TRANCE                     = 17941,
    SPELL_WARLOCK_SOUL_LEECH_HEAL                   = 30294,
    SPELL_WARLOCK_IMP_SOUL_LEECH_R1                 = 54117,
    SPELL_WARLOCK_SOUL_LEECH_PET_MANA_1             = 54607,
    SPELL_WARLOCK_SOUL_LEECH_PET_MANA_2             = 59118,
    SPELL_WARLOCK_SOUL_LEECH_CASTER_MANA_1          = 54300,
    SPELL_WARLOCK_SOUL_LEECH_CASTER_MANA_2          = 59117,
    SPELL_REPLENISHMENT                             = 57669,
    SPELL_WARLOCK_SHADOWFLAME                       = 37378,
    SPELL_WARLOCK_FLAMESHADOW                       = 37379,
    SPELL_WARLOCK_GLYPH_OF_SUCCUBUS                 = 56250,
    SPELL_WARLOCK_IMPROVED_DRAIN_SOUL_PROC          = 18371
};

enum WarlockSpellIcons
{
    WARLOCK_ICON_ID_IMPROVED_LIFE_TAP               = 208,
    WARLOCK_ICON_ID_MANA_FEED                       = 1982,
    WARLOCK_ICON_ID_DEMONIC_PACT                    = 3220
};

// -710 - Banish
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

// 6201 - Create Healthstone (and ranks)
class spell_warl_create_healthstone : public SpellScriptLoader
{
    public:
        spell_warl_create_healthstone() : SpellScriptLoader("spell_warl_create_healthstone") { }

        class spell_warl_create_healthstone_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_create_healthstone_SpellScript);

            static uint32 const iTypes[8][3];

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_IMPROVED_HEALTHSTONE_R1) || !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_IMPROVED_HEALTHSTONE_R2))
                    return false;
                return true;
            }

            SpellCastResult CheckCast()
            {
                if (Player* caster = GetCaster()->ToPlayer())
                {
                    uint8 spellRank = GetSpellInfo()->GetRank();
                    ItemPosCountVec dest;
                    InventoryResult msg = caster->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, iTypes[spellRank - 1][0], 1, NULL);
                    if (msg != EQUIP_ERR_OK)
                        return SPELL_FAILED_TOO_MANY_OF_ITEM;
                }
                return SPELL_CAST_OK;
            }

            void HandleScriptEffect(SpellEffIndex effIndex)
            {
                if (Unit* unitTarget = GetHitUnit())
                {
                    uint32 rank = 0;
                    // Improved Healthstone
                    if (AuraEffect const* aurEff = unitTarget->GetDummyAuraEffect(SPELLFAMILY_WARLOCK, 284, 0))
                    {
                        switch (aurEff->GetId())
                        {
                            case SPELL_WARLOCK_IMPROVED_HEALTHSTONE_R1:
                                rank = 1;
                                break;
                            case SPELL_WARLOCK_IMPROVED_HEALTHSTONE_R2:
                                rank = 2;
                                break;
                            default:
                                TC_LOG_ERROR("spells", "Unknown rank of Improved Healthstone id: %d", aurEff->GetId());
                                break;
                        }
                    }
                    uint8 spellRank = GetSpellInfo()->GetRank();
                    if (spellRank > 0 && spellRank <= 8)
                        CreateItem(effIndex, iTypes[spellRank - 1][rank]);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_warl_create_healthstone_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                OnCheckCast += SpellCheckCastFn(spell_warl_create_healthstone_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_create_healthstone_SpellScript();
        }
};

uint32 const spell_warl_create_healthstone::spell_warl_create_healthstone_SpellScript::iTypes[8][3] = {
    { 5512, 19004, 19005},              // Minor Healthstone
    { 5511, 19006, 19007},              // Lesser Healthstone
    { 5509, 19008, 19009},              // Healthstone
    { 5510, 19010, 19011},              // Greater Healthstone
    { 9421, 19012, 19013},              // Major Healthstone
    {22103, 22104, 22105},              // Master Healthstone
    {36889, 36890, 36891},              // Demonic Healthstone
    {36892, 36893, 36894}               // Fel Healthstone
};

// -603 - Curse of Doom
class spell_warl_curse_of_doom : public SpellScriptLoader
{
    public:
        spell_warl_curse_of_doom() : SpellScriptLoader("spell_warl_curse_of_doom") { }

        class spell_warl_curse_of_doom_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_curse_of_doom_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_CURSE_OF_DOOM_EFFECT))
                    return false;
                return true;
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
                    GetCaster()->CastSpell(GetTarget(), SPELL_WARLOCK_CURSE_OF_DOOM_EFFECT, true, NULL, aurEff);
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

class spell_warl_decimation : public SpellScriptLoader
{
    public:
        spell_warl_decimation() : SpellScriptLoader("spell_warl_decimation") { }

        class spell_warl_decimation_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_decimation_AuraScript);

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (SpellInfo const* spellInfo = eventInfo.GetSpellInfo())
                    if (eventInfo.GetActionTarget()->HasAuraState(AURA_STATE_HEALTHLESS_35_PERCENT, spellInfo, eventInfo.GetActor()))
                        return true;

                return false;
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_warl_decimation_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_decimation_AuraScript();
        }
};

// 48018 - Demonic Circle: Summon
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

// 47193 - Demonic Empowerment
class spell_warl_demonic_empowerment : public SpellScriptLoader
{
    public:
        spell_warl_demonic_empowerment() : SpellScriptLoader("spell_warl_demonic_empowerment") { }

        class spell_warl_demonic_empowerment_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_demonic_empowerment_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_DEMONIC_EMPOWERMENT_SUCCUBUS) || !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_DEMONIC_EMPOWERMENT_VOIDWALKER) || !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_DEMONIC_EMPOWERMENT_FELGUARD) || !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_DEMONIC_EMPOWERMENT_FELHUNTER) || !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_DEMONIC_EMPOWERMENT_IMP))
                    return false;
                return true;
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
                                targetCreature->CastCustomSpell(targetCreature, SPELL_WARLOCK_DEMONIC_EMPOWERMENT_VOIDWALKER, &hp, NULL, NULL, true);
                                //unitTarget->CastSpell(unitTarget, 54441, true);
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
                    // Refresh corruption on target
                    if (AuraEffect* aur = target->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x2, 0, 0, caster->GetGUID()))
                    {
                        aur->SetBonusAmount(caster->SpellDamageBonusDone(target, aur->GetSpellInfo(), 0, DOT));
                        aur->CalculatePeriodic(caster, false, false);
                        aur->GetBase()->RefreshDuration(true);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_FEL_SYNERGY_HEAL))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return GetTarget()->GetGuardianPet() && eventInfo.GetDamageInfo()->GetDamage();
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 heal = CalculatePct(int32(eventInfo.GetDamageInfo()->GetDamage()), aurEff->GetAmount());
                GetTarget()->CastCustomSpell(SPELL_WARLOCK_FEL_SYNERGY_HEAL, SPELLVALUE_BASE_POINT0, heal, (Unit*)NULL, true, NULL, aurEff); // TARGET_UNIT_PET
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

// -18094 - Nightfall
//  56218 - Glyph of Corruption
class spell_warl_glyph_of_corruption_nightfall : public SpellScriptLoader
{
    public:
        spell_warl_glyph_of_corruption_nightfall() : SpellScriptLoader("spell_warl_glyph_of_corruption_nightfall") { }

        class spell_warl_glyph_of_corruption_nightfall_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_glyph_of_corruption_nightfall_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_SHADOW_TRANCE))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                caster->CastSpell(caster, SPELL_WARLOCK_SHADOW_TRANCE, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_glyph_of_corruption_nightfall_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_glyph_of_corruption_nightfall_AuraScript();
        }
};

// 63320 - Glyph of Life Tap
class spell_warl_glyph_of_life_tap : public SpellScriptLoader
{
public:
    spell_warl_glyph_of_life_tap() : SpellScriptLoader("spell_warl_glyph_of_life_tap") { }

    class spell_warl_glyph_of_life_tap_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_glyph_of_life_tap_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_GLYPH_OF_LIFE_TAP_TRIGGERED))
                return false;
            return true;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            Unit* caster = eventInfo.GetActor();
            caster->CastSpell(caster, SPELL_WARLOCK_GLYPH_OF_LIFE_TAP_TRIGGERED, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_warl_glyph_of_life_tap_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_glyph_of_life_tap_AuraScript();
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
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_GLYPH_OF_SHADOWFLAME))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_WARLOCK_GLYPH_OF_SHADOWFLAME, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_glyph_of_shadowflame_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_glyph_of_shadowflame_AuraScript();
        }
};

// -48181 - Haunt
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
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_HAUNT_HEAL))
                    return false;
                return true;
            }

            void HandleRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                {
                    int32 amount = aurEff->GetAmount();
                    GetTarget()->CastCustomSpell(caster, SPELL_WARLOCK_HAUNT_HEAL, &amount, NULL, NULL, true, NULL, aurEff, GetCasterGUID());
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

// -755 - Health Funnel
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

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_warl_health_funnel_AuraScript::RemoveEffect, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
                OnEffectApply += AuraEffectApplyFn(spell_warl_health_funnel_AuraScript::ApplyEffect, EFFECT_0, SPELL_AURA_PERIODIC_HEAL, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_health_funnel_AuraScript();
        }
};

// -18213 - Improved Drain Soul
class spell_warl_improved_drain_soul : public SpellScriptLoader
{
    public:
        spell_warl_improved_drain_soul() : SpellScriptLoader("spell_warl_improved_drain_soul") { }

        class spell_warl_improved_drain_soul_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_improved_drain_soul_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_IMPROVED_DRAIN_SOUL_PROC))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                
                Unit* target = GetTarget();
                int32 bp0 = CalculatePct(target->GetMaxPower(POWER_MANA), GetSpellInfo()->Effects[EFFECT_2].BasePoints);
                target->CastCustomSpell(SPELL_WARLOCK_IMPROVED_DRAIN_SOUL_PROC, SPELLVALUE_BASE_POINT0, bp0, target, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_improved_drain_soul_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_improved_drain_soul_AuraScript();
        }
};

// -1454 - Life Tap
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

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_LIFE_TAP_ENERGIZE) || !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_LIFE_TAP_ENERGIZE_2))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Player* caster = GetCaster()->ToPlayer();
                if (Unit* target = GetHitUnit())
                {
                    int32 damage = GetEffectValue();
                    int32 mana = int32(damage + (caster->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS+SPELL_SCHOOL_SHADOW) * 0.5f));

                    // Shouldn't Appear in Combat Log
                    target->ModifyHealth(-damage);

                    // Improved Life Tap mod
                    if (AuraEffect const* aurEff = caster->GetDummyAuraEffect(SPELLFAMILY_WARLOCK, WARLOCK_ICON_ID_IMPROVED_LIFE_TAP, 0))
                        AddPct(mana, aurEff->GetAmount());

                    caster->CastCustomSpell(target, SPELL_WARLOCK_LIFE_TAP_ENERGIZE, &mana, NULL, NULL, false);

                    // Mana Feed
                    int32 manaFeedVal = 0;
                    if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_WARLOCK, WARLOCK_ICON_ID_MANA_FEED, 0))
                        manaFeedVal = aurEff->GetAmount();

                    if (manaFeedVal > 0)
                    {
                        ApplyPct(manaFeedVal, mana);
                        caster->CastCustomSpell(caster, SPELL_WARLOCK_LIFE_TAP_ENERGIZE_2, &manaFeedVal, NULL, NULL, true, NULL);
                    }
                }
            }

            SpellCastResult CheckCast()
            {
                if ((int32(GetCaster()->GetHealth()) > int32(GetSpellInfo()->Effects[EFFECT_0].CalcValue() + (6.3875 * GetSpellInfo()->BaseLevel))))
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

// -30299 - Nether Protection
class spell_warl_nether_protection : public SpellScriptLoader
{
public:
    spell_warl_nether_protection() : SpellScriptLoader("spell_warl_nether_protection") { }

    class spell_warl_nether_protection_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_warl_nether_protection_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_NETHER_PROTECTION_HOLY) ||
                !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_NETHER_PROTECTION_FIRE) ||
                !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_NETHER_PROTECTION_FROST) ||
                !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_NETHER_PROTECTION_ARCANE) ||
                !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_NETHER_PROTECTION_SHADOW) ||
                !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_NETHER_PROTECTION_NATURE))
                return false;
            return true;
        }

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetDamageInfo())
            {
                switch (GetFirstSchoolInMask(eventInfo.GetDamageInfo()->GetSchoolMask()))
                {
                    case SPELL_SCHOOL_HOLY:
                    case SPELL_SCHOOL_FIRE:
                    case SPELL_SCHOOL_NATURE:
                    case SPELL_SCHOOL_FROST:
                    case SPELL_SCHOOL_SHADOW:
                    case SPELL_SCHOOL_ARCANE:
                        return true;
                    default:
                        break;
                }
            }

            return false;
        }

        void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            uint32 triggerspell = 0;

            switch (GetFirstSchoolInMask(eventInfo.GetDamageInfo()->GetSchoolMask()))
            {
                case SPELL_SCHOOL_HOLY:
                    triggerspell = SPELL_WARLOCK_NETHER_PROTECTION_HOLY;
                    break;
                case SPELL_SCHOOL_FIRE:
                    triggerspell = SPELL_WARLOCK_NETHER_PROTECTION_FIRE;
                    break;
                case SPELL_SCHOOL_NATURE:
                    triggerspell = SPELL_WARLOCK_NETHER_PROTECTION_NATURE;
                    break;
                case SPELL_SCHOOL_FROST:
                    triggerspell = SPELL_WARLOCK_NETHER_PROTECTION_FROST;
                    break;
                case SPELL_SCHOOL_SHADOW:
                    triggerspell = SPELL_WARLOCK_NETHER_PROTECTION_SHADOW;
                    break;
                case SPELL_SCHOOL_ARCANE:
                    triggerspell = SPELL_WARLOCK_NETHER_PROTECTION_ARCANE;
                    break;
                default:
                    return;
            }

            if (Unit* target = eventInfo.GetActionTarget())
                target->CastSpell(target, triggerspell, true, nullptr, aurEff);
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_warl_nether_protection_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_warl_nether_protection_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_warl_nether_protection_AuraScript();
    }
};

// 54909, 53646 - Demonic Pact
class spell_warl_demonic_pact : public SpellScriptLoader
{
    public:
        spell_warl_demonic_pact() : SpellScriptLoader("spell_warl_demonic_pact") { }

        class spell_warl_demonic_pact_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_demonic_pact_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_DEMONIC_PACT_PROC))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetActor() && eventInfo.GetActor()->IsPet();
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                if (Unit* owner = eventInfo.GetActor()->GetOwner())
                {
                    if (AuraEffect* aurEff = owner->GetDummyAuraEffect(SPELLFAMILY_WARLOCK, WARLOCK_ICON_ID_DEMONIC_PACT, EFFECT_0))
                    {
                        int32 bp0 = static_cast<int32>((aurEff->GetAmount() * owner->SpellBaseDamageBonusDone(SPELL_SCHOOL_MASK_MAGIC) + 100.0f) / 100.0f);
                        owner->CastCustomSpell(SPELL_WARLOCK_DEMONIC_PACT_PROC, SPELLVALUE_BASE_POINT0, bp0, (Unit*)nullptr, true, nullptr, aurEff);
                    }
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_warl_demonic_pact_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_warl_demonic_pact_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_demonic_pact_AuraScript();
        }
};

// 18541 - Ritual of Doom Effect
class spell_warl_ritual_of_doom_effect : public SpellScriptLoader
{
    public:
        spell_warl_ritual_of_doom_effect() : SpellScriptLoader("spell_warl_ritual_of_doom_effect") { }

        class spell_warl_ritual_of_doom_effect_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_ritual_of_doom_effect_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                caster->CastSpell(caster, GetEffectValue(), true);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_warl_ritual_of_doom_effect_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_ritual_of_doom_effect_SpellScript();
        }
};

// 6358 - Seduction
class spell_warl_seduction : public SpellScriptLoader
{
    public:
        spell_warl_seduction() : SpellScriptLoader("spell_warl_seduction") { }

        class spell_warl_seduction_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_seduction_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_GLYPH_OF_SUCCUBUS))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* owner = GetCaster()->GetOwner();
                if (!owner || !owner->HasAura(SPELL_WARLOCK_GLYPH_OF_SUCCUBUS))
                    return;

                Unit* target = GetHitUnit();
                target->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE, ObjectGuid::Empty, target->GetAura(32409)); // SW:D shall not be removed.
                target->RemoveAurasByType(SPELL_AURA_PERIODIC_DAMAGE_PERCENT);
                target->RemoveAurasByType(SPELL_AURA_PERIODIC_LEECH);
            }

            void Register() override
            {
                OnEffectLaunchTarget += SpellEffectFn(spell_warl_seduction_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_warl_seduction_SpellScript();
        }
};

// -27285 - Seed of Corruption
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

// -27243 - Seed of Corruption
class spell_warl_seed_of_corruption_dummy : public SpellScriptLoader
{
    public:
        spell_warl_seed_of_corruption_dummy() : SpellScriptLoader("spell_warl_seed_of_corruption_dummy") { }

        class spell_warl_seed_of_corruption_dummy_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_seed_of_corruption_dummy_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_SEED_OF_CORRUPTION_DAMAGE_R1))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo)
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

                uint32 spellId = sSpellMgr->GetSpellWithRank(SPELL_WARLOCK_SEED_OF_CORRUPTION_DAMAGE_R1, GetSpellInfo()->GetRank());
                caster->CastSpell(eventInfo.GetActionTarget(), spellId, true);
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
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_SEED_OF_CORRUPTION_GENERIC))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo)
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

                caster->CastSpell(eventInfo.GetActionTarget(), SPELL_WARLOCK_SEED_OF_CORRUPTION_GENERIC, true);
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
                    bonus *= caster->CalculateLevelPenalty(GetSpellInfo());

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

// 63108 - Siphon Life
class spell_warl_siphon_life : public SpellScriptLoader
{
    public:
        spell_warl_siphon_life() : SpellScriptLoader("spell_warl_siphon_life") { }

        class spell_warl_siphon_life_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_siphon_life_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_SIPHON_LIFE_HEAL))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_GLYPH_OF_SIPHON_LIFE))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetDamageInfo()->GetDamage() && GetTarget()->IsAlive();
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 amount = int32(CalculatePct(eventInfo.GetDamageInfo()->GetDamage(), aurEff->GetAmount()));
                // Glyph of Siphon Life
                if (AuraEffect const* glyph = GetTarget()->GetAuraEffect(SPELL_WARLOCK_GLYPH_OF_SIPHON_LIFE, EFFECT_0))
                    AddPct(amount, glyph->GetAmount());

                GetTarget()->CastCustomSpell(SPELL_WARLOCK_SIPHON_LIFE_HEAL, SPELLVALUE_BASE_POINT0, amount, GetTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_warl_siphon_life_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_warl_siphon_life_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_siphon_life_AuraScript();
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
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_SOUL_LEECH_HEAL) ||
                    !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_IMP_SOUL_LEECH_R1) ||
                    !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_SOUL_LEECH_PET_MANA_1) ||
                    !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_SOUL_LEECH_PET_MANA_2) ||
                    !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_SOUL_LEECH_CASTER_MANA_1) ||
                    !sSpellMgr->GetSpellInfo(SPELL_WARLOCK_SOUL_LEECH_CASTER_MANA_2) ||
                    !sSpellMgr->GetSpellInfo(SPELL_REPLENISHMENT))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                static uint32 const casterMana[2] = { SPELL_WARLOCK_SOUL_LEECH_CASTER_MANA_1, SPELL_WARLOCK_SOUL_LEECH_CASTER_MANA_2 };
                static uint32 const petMana[2]    = { SPELL_WARLOCK_SOUL_LEECH_PET_MANA_1,    SPELL_WARLOCK_SOUL_LEECH_PET_MANA_2    };

                PreventDefaultAction();
                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                Unit* caster = eventInfo.GetActor();
                int32 bp = CalculatePct(static_cast<int32>(damageInfo->GetDamage()), aurEff->GetAmount());
                caster->CastCustomSpell(SPELL_WARLOCK_SOUL_LEECH_HEAL, SPELLVALUE_BASE_POINT0, bp, caster, true);

                // Improved Soul Leech code below
                AuraEffect const* impSoulLeech = GetTarget()->GetAuraEffectOfRankedSpell(SPELL_WARLOCK_IMP_SOUL_LEECH_R1, EFFECT_1, aurEff->GetCasterGUID());
                if (!impSoulLeech)
                    return;

                uint8 impSoulLeechRank = impSoulLeech->GetSpellInfo()->GetRank();
                uint32 selfSpellId = casterMana[impSoulLeechRank - 1];
                uint32 petSpellId = petMana[impSoulLeechRank - 1];

                caster->CastSpell((Unit*)nullptr, selfSpellId, true);
                caster->CastSpell((Unit*)nullptr, petSpellId, true);

                if (roll_chance_i(impSoulLeech->GetAmount()))
                    caster->CastSpell((Unit*)nullptr, SPELL_REPLENISHMENT, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_warl_soul_leech_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_warl_soul_leech_AuraScript();
        }
};

// 29858 - Soulshatter
class spell_warl_soulshatter : public SpellScriptLoader
{
    public:
        spell_warl_soulshatter() : SpellScriptLoader("spell_warl_soulshatter") { }

        class spell_warl_soulshatter_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_warl_soulshatter_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_SOULSHATTER))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    if (target->CanHaveThreatList() && target->getThreatManager().getThreat(caster) > 0.0f)
                        caster->CastSpell(target, SPELL_WARLOCK_SOULSHATTER, true);
                }
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
                if (!sSpellMgr->GetSpellInfo(Trigger))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = eventInfo.GetActor();
                caster->CastSpell(caster, Trigger, true);
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

// -30108 - Unstable Affliction
class spell_warl_unstable_affliction : public SpellScriptLoader
{
    public:
        spell_warl_unstable_affliction() : SpellScriptLoader("spell_warl_unstable_affliction") { }

        class spell_warl_unstable_affliction_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_warl_unstable_affliction_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_WARLOCK_UNSTABLE_AFFLICTION_DISPEL))
                    return false;
                return true;
            }

            void HandleDispel(DispelInfo* dispelInfo)
            {
                if (Unit* caster = GetCaster())
                    if (AuraEffect const* aurEff = GetEffect(EFFECT_0))
                    {
                        int32 damage = aurEff->GetAmount() * 9;
                        // backfire damage and silence
                        caster->CastCustomSpell(dispelInfo->GetDispeller(), SPELL_WARLOCK_UNSTABLE_AFFLICTION_DISPEL, &damage, NULL, NULL, true, NULL, aurEff);
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

void AddSC_warlock_spell_scripts()
{
    new spell_warl_banish();
    new spell_warl_create_healthstone();
    new spell_warl_curse_of_doom();
    new spell_warl_decimation();
    new spell_warl_demonic_circle_summon();
    new spell_warl_demonic_circle_teleport();
    new spell_warl_demonic_empowerment();
    new spell_warl_demonic_pact();
    new spell_warl_everlasting_affliction();
    new spell_warl_fel_synergy();
    new spell_warl_glyph_of_life_tap();
    new spell_warl_glyph_of_shadowflame();
    new spell_warl_haunt();
    new spell_warl_health_funnel();
    new spell_warl_glyph_of_corruption_nightfall();
    new spell_warl_improved_drain_soul();
    new spell_warl_life_tap();
    new spell_warl_nether_protection();
    new spell_warl_ritual_of_doom_effect();
    new spell_warl_seduction();
    new spell_warl_seed_of_corruption();
    new spell_warl_seed_of_corruption_dummy();
    new spell_warl_seed_of_corruption_generic();
    new spell_warl_shadow_ward();
    new spell_warl_siphon_life();
    new spell_warl_soul_leech();
    new spell_warl_soulshatter();
    new spell_warl_t4_2p_bonus<SPELL_WARLOCK_FLAMESHADOW>("spell_warl_t4_2p_bonus_shadow");
    new spell_warl_t4_2p_bonus<SPELL_WARLOCK_SHADOWFLAME>("spell_warl_t4_2p_bonus_fire");
    new spell_warl_unstable_affliction();
}
