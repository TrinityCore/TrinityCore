/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
 * Scripts for spells with SPELLFAMILY_SHAMAN and SPELLFAMILY_GENERIC spells used by shaman players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_sha_".
 */

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "CellImpl.h"
#include "CreatureAIImpl.h"
#include "GridNotifiersImpl.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"

enum ShamanSpells
{
    SPELL_PET_NETHERWINDS_FATIGUED                          = 160455,
    SPELL_SHAMAN_ANCESTRAL_AWAKENING                        = 52759,
    SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC                   = 52752,
    SPELL_SHAMAN_ANCESTRAL_GUIDANCE                         = 108281,
    SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL                    = 114911,
    SPELL_SHAMAN_ASCENDANCE                                 = 114049,
    SPELL_SHAMAN_ASCENDANCE_ELEMENTAL                       = 114050,
    SPELL_SHAMAN_ASCENDANCE_ENHANCED                        = 114051,
    SPELL_SHAMAN_ASCENDANCE_RESTORATION                     = 114052,
    SPELL_SHAMAN_AT_EARTHEN_SHIELD_TOTEM                    = 198839,
    SPELL_SHAMAN_BIND_SIGHT                                 = 6277,
    SPELL_SHAMAN_CONDUCTIVITY_HEAL                          = 118800,
    SPELL_SHAMAN_CONDUCTIVITY_TALENT                        = 108282,
    SPELL_SHAMAN_CRASH_LIGHTNING_PROC                       = 195592,
    SPELL_SHAMAN_CRASH_LIGTHNING                            = 187874,
    SPELL_SHAMAN_CRASH_LIGTHNING_AURA                       = 187878,
    SPELL_SHAMAN_CRASHING_STORM_DUMMY                       = 192246,
    SPELL_SHAMAN_CRASHING_STORM_AT                          = 210797,
    SPELL_SHAMAN_CRASHING_STORM_DAMAGE                      = 210801,
    SPELL_SHAMAN_DOOM_WINDS                                 = 204945,
    SPELL_SHAMAN_EARTHBIND_FOR_EARTHGRAB_TOTEM              = 116947,
    SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE                        = 170379,
    SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE                       = 170374,
    SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC                      = 170377,
    SPELL_SHAMAN_EARTHGRAB_IMMUNITY                         = 116946,
    SPELL_SHAMAN_EARTHQUAKE                                 = 61882,
    SPELL_SHAMAN_EARTHQUAKE_KNOCKING_DOWN                   = 77505,
    SPELL_SHAMAN_EARTHQUAKE_TICK                            = 77478,
    SPELL_SHAMAN_EARTH_ELEMENTAL_AGGRO                      = 235429,
    SPELL_SHAMAN_EARTH_ELEMENTAL_DUMMY                      = 198103,
    SPELL_SHAMAN_EARTH_ELEMENTAL_SUMMON                     = 188616,
    SPELL_SHAMAN_EARTH_SHIELD_HEAL                          = 379,
    SPELL_SHAMAN_EARTH_SHOCK                                = 8042,
    SPELL_SHAMAN_ECHO_OF_THE_ELEMENTS                       = 108283,
    SPELL_SHAMAN_ELEMENTAL_BLAST                            = 117014,
    SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT                       = 118522,
    SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE                      = 173183,
    SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY                    = 173184,
    SPELL_SHAMAN_ELEMENTAL_MASTERY                          = 16166,
    SPELL_SHAMAN_EXHAUSTION                                 = 57723,
    SPELL_SHAMAN_FERAL_LUNGE                                = 196884,
    SPELL_SHAMAN_FERAL_LUNGE_DAMAGE                         = 215802,
    SPELL_SHAMAN_FERAL_SPIRIT                               = 51533,
    SPELL_SHAMAN_FERAL_SPIRIT_SUMMON                        = 228562,
    SPELL_SHAMAN_FERAL_SPIRIT_ENERGIZE                      = 190185,
    SPELL_SHAMAN_FERAL_SPIRIT_ENERGIZE_DUMMY                = 231723,
    SPELL_SHAMAN_FIRE_ELEMENTAL_DUMMY                       = 198067,
    SPELL_SHAMAN_FIRE_ELEMENTAL_SUMMON                      = 188592,
    SPELL_SHAMAN_FIRE_NOVA                                  = 1535,
    SPELL_SHAMAN_FIRE_NOVA_TRIGGERED                        = 131786,
    SPELL_SHAMAN_FLAMETONGUE_ATTACK                         = 10444,
    SPELL_SHAMAN_FLAMETONGUE_WEAPON_PASSIVE                 = 10400,
    SPELL_SHAMAN_FLAME_SHOCK                                = 8050,
    SPELL_SHAMAN_FLAME_SHOCK_ELEM                           = 188389,
    SPELL_SHAMAN_FLAME_SHOCK_MAELSTROM                      = 188389,
    SPELL_SHAMAN_FROST_SHOCK_FREEZE                         = 63685,
    SPELL_SHAMAN_FROZEN_POWER                               = 63374,
    SPELL_SHAMAN_FULMINATION                                = 88766,
    SPELL_SHAMAN_FULMINATION_INFO                           = 95774,
    SPELL_SHAMAN_FULMINATION_TRIGGERED                      = 88767,
    SPELL_SHAMAN_FURY_OF_AIR                                = 197211,
    SPELL_SHAMAN_FURY_OF_AIR_EFFECT                         = 197385,
    SPELL_SHAMAN_GHOST_WOLF                                 = 2645,
    SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM                    = 119523,
    SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM              = 55456,
    SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM_TRIGGERED    = 119523,
    SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE                      = 55533,
    SPELL_SHAMAN_GLYPH_OF_LAKESTRIDER                       = 55448,
    SPELL_SHAMAN_GLYPH_OF_LAVA_LASH                         = 55444,
    SPELL_SHAMAN_GLYPH_OF_SHAMANISTIC_RAGE                  = 63280,
    SPELL_SHAMAN_GLYPH_OF_THUNDERSTORM                      = 62132,
    SPELL_SHAMAN_HEALING_RAIN                               = 73920,
    SPELL_SHAMAN_HEALING_RAIN_TICK                          = 73921,
    SPELL_SHAMAN_HEALING_STREAM                             = 52042,
    SPELL_SHAMAN_HEALING_STREAM_DUMMY                       = 98856,
    SPELL_SHAMAN_HIGH_TIDE                                  = 157154,
    SPELL_SHAMAN_HOT_HAND                                   = 215785,
    SPELL_SHAMAN_IMPROVED_LIGHTNING_SHIELD                  = 157774,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD                      = 23552,
    SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE               = 27635,
    SPELL_SHAMAN_ITEM_MANA_SURGE                            = 23571,
    SPELL_SHAMAN_ITEM_T14_4P                                = 123124,
    SPELL_SHAMAN_ITEM_T18_ELEMENTAL_2P_BONUS                = 185880,
    SPELL_SHAMAN_ITEM_T18_ELEMENTAL_4P_BONUS                = 185881,
    SPELL_SHAMAN_ITEM_T18_GATHERING_VORTEX                  = 189078,
    SPELL_SHAMAN_ITEM_T18_LIGHTNING_VORTEX                  = 189063,
    SPELL_SHAMAN_LAVA_BURST                                 = 51505,
    SPELL_SHAMAN_LAVA_LASH                                  = 60103,
    SPELL_SHAMAN_LAVA_LASH_SPREAD_FLAME_SHOCK               = 105792,
    SPELL_SHAMAN_LAVA_SURGE                                 = 77756,
    SPELL_SHAMAN_LAVA_SURGE_CAST_TIME                       = 77762,
    SPELL_SHAMAN_LIGHTNING_BOLT_ELEM                        = 188196,
    SPELL_SHAMAN_LIGHTNING_BOLT_ELEM_POWER                  = 214815,
    SPELL_SHAMAN_LIGHTNING_SHIELD                           = 324,
    SPELL_SHAMAN_LIGHTNING_SHIELD_AURA                      = 324,
    SPELL_SHAMAN_LIGHTNING_SHIELD_ORB_DAMAGE                = 26364,
    SPELL_SHAMAN_LIGHTNING_SHIELD_TRIGGER                   = 26364,
    SPELL_SHAMAN_LIQUID_MAGMA_DAMAGE                        = 192231,
    SPELL_SHAMAN_MAELSTROM_WEAPON                           = 187880,
    SPELL_SHAMAN_MAELSTROM_WEAPON_POWER                     = 187890,
    SPELL_SHAMAN_MAIL_SPECIALISATION_INT                    = 86100,
    SPELL_SHAMAN_MAIL_SPECIALIZATION_AGI                    = 86099,
    SPELL_SHAMAN_MANA_TIDE                                  = 16191,
    SPELL_SHAMAN_NATURE_GUARDIAN                            = 31616,
    SPELL_SHAMAN_OVERCHARGE                                 = 210727,
    SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD                      = 210621,
    SPELL_SHAMAN_PATH_OF_FLAMES_TALENT                      = 201909,
    SPELL_SHAMAN_RAINFALL                                   = 215864,
    SPELL_SHAMAN_RAINFALL_HEAL                              = 215871,
    SPELL_SHAMAN_RESTORATIVE_MISTS                          = 114083,
    SPELL_SHAMAN_RIPTIDE                                    = 61295,
    SPELL_SHAMAN_ROLLING_THUNDER_AURA                       = 88764,
    SPELL_SHAMAN_ROLLING_THUNDER_ENERGIZE                   = 88765,
    SPELL_SHAMAN_RUSHING_STREAMS                            = 147074,
    SPELL_SHAMAN_SATED                                      = 57724,
    SPELL_SHAMAN_SEARING_FLAMES_DAMAGE_DONE                 = 77661,
    SPELL_SHAMAN_SOLAR_BEAM                                 = 113286,
    SPELL_SHAMAN_SOLAR_BEAM_SILENCE                         = 113288,
    SPELL_SHAMAN_STONE_BULWARK_ABSORB                       = 114893,
    SPELL_SHAMAN_STORMBRINGER                               = 201845,
    SPELL_SHAMAN_STORMBRINGER_PROC                          = 201846,
    SPELL_SHAMAN_STORMLASH                                  = 195255,
    SPELL_SHAMAN_STORMLASH_BUFF                             = 195222,
    SPELL_SHAMAN_STORMLASH_DAMAGE                           = 213307,
    SPELL_SHAMAN_STORMSTRIKE                                = 17364,
    SPELL_SHAMAN_STORMSTRIKE_MAIN                           = 32175,
    SPELL_SHAMAN_TIDAL_WAVES                                = 53390,
    SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL                  = 52042,
    SPELL_SHAMAN_UNDULATION_PROC                            = 216251,
    SPELL_SHAMAN_UNLEASHED_FURY_EARTHLIVING                 = 118473,
    SPELL_SHAMAN_UNLEASHED_FURY_FLAMETONGUE                 = 118470,
    SPELL_SHAMAN_UNLEASHED_FURY_FROSTBRAND                  = 118474,
    SPELL_SHAMAN_UNLEASHED_FURY_ROCKBITER                   = 118475,
    SPELL_SHAMAN_UNLEASHED_FURY_TALENT                      = 117012,
    SPELL_SHAMAN_UNLEASHED_FURY_WINDFURY                    = 118472,
    SPELL_SHAMAN_UNLEASH_ELEMENTS                           = 73680,
    SPELL_SHAMAN_WATER_WALKING                              = 546,
    SPELL_SHAMAN_WELLSPRING_MISSILE                         = 198117,
    SPELL_SHAMAN_WINDFURY_ATTACK                            = 25504,
    SPELL_SHAMAN_WINDFURY_ATTACK_MAIN_HAND                  = 25504,
    SPELL_SHAMAN_WINDFURY_ATTACK_OFF_HAND                   = 33750,
    SPELL_SHAMAN_WINDFURY_WEAPON_PASSIVE                    = 33757,
    SPELL_SHAMAN_WIND_RUSH_TOTEM                            = 192077,
};

enum TotemSpells
{
    SPELL_TOTEM_WIND_RUSH_EFFECT                            = 192082,
    SPELL_TOTEM_VOODOO_AT                                   = 196935,
    SPELL_TOTEM_VOODOO_EFFECT                               = 196942,
    SPELL_TOTEM_VOODOO_COOLDOWN                             = 202318,
    SPELL_TOTEM_LIGHTNING_SURGE_EFFECT                      = 118905,
    SPELL_TOTEM_RESONANCE_EFFECT                            = 202192,
    SPELL_TOTEM_LIQUID_MAGMA_EFFECT                         = 192226,
    SPELL_TOTEM_EARTH_GRAB_ROOT_EFFECT                      = 64695,
    SPELL_TOTEM_EARTH_GRAB_SLOW_EFFECT                      = 116947,
    SPELL_TOTEM_HEALING_TIDE_EFFECT                         = 114942,
    SPELL_TOTEM_TAIL_WIND_EFFECT                            = 210659,
    SPELL_TOTEM_EMBER_EFFECT                                = 210658,
    SPELL_TOTEM_STORM_EFFECT                                = 210652,
    SPELL_TOTEM_CLOUDBURST_EFFECT                           = 157504,
    SPELL_TOTEM_CLOUDBURST                                  = 157503,
    SPELL_TOTEM_ANCESTRAL_PROTECTION_AT                     = 207495,
    SPELL_TOTEM_TOTEMIC_REVIVAL                             = 207553,
    SPELL_TOTEM_SKYFURY_EFFECT                              = 208963,
    SPELL_TOTEM_GROUDING_TOTEM_EFFECT                       = 8178
};

enum ShamanSpellIcons
{
    SHAMAN_ICON_ID_SOOTHING_RAIN                            = 2011,
    SHAMAN_ICON_ID_SHAMAN_LAVA_FLOW                         = 3087
};

enum MiscSpells
{
    SPELL_HUNTER_INSANITY                                   = 95809,
    SPELL_MAGE_TEMPORAL_DISPLACEMENT                        = 80354
};

enum AncestralAwakeningProc
{
    SPELL_ANCESTRAL_AWAKENING_PROC                          = 52752,
};

enum ShamanNpcs
{
    NPC_RAINFALL                                            = 73400,
    NPC_HEALING_RAIN                                        = 73400, // Same as Rainfall at 7.3.5
};

// Feral Lunge - 196884
class spell_sha_feral_lunge : public SpellScriptLoader
{
public:
    spell_sha_feral_lunge() : SpellScriptLoader("spell_sha_feral_lunge") {}

    class spell_sha_feral_lunge_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_feral_lunge_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FERAL_LUNGE_DAMAGE))
                return false;
            return true;
        }

        void HandleDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_SHAMAN_FERAL_LUNGE_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_sha_feral_lunge_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_feral_lunge_SpellScript();
    }
};

// Stormbringer - 201845
class spell_sha_stormbringer : public SpellScriptLoader
{
public:
    spell_sha_stormbringer() : SpellScriptLoader("spell_sha_stormbringer") {}

    class spell_sha_stormbringer_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_stormbringer_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            return eventInfo.GetDamageInfo()->GetAttackType() == BASE_ATTACK;
        }

        void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
        {
            if (Unit* caster = GetCaster())
            {
                caster->CastSpell(caster, SPELL_SHAMAN_STORMBRINGER_PROC, true);
                caster->GetSpellHistory()->ResetCooldown(SPELL_SHAMAN_STORMSTRIKE, true);
            }
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_sha_stormbringer_AuraScript::CheckProc);
            OnEffectProc += AuraEffectProcFn(spell_sha_stormbringer_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_stormbringer_AuraScript();
    }
};

// Crash Lightning aura - 187878
class spell_sha_crash_lightning_aura : public SpellScriptLoader
{
public:
    spell_sha_crash_lightning_aura() : SpellScriptLoader("spell_sha_crash_lightning_aura") {}

    class spell_sha_crash_lightning_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_crash_lightning_aura_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (eventInfo.GetSpellInfo()->Id == SPELL_SHAMAN_STORMSTRIKE_MAIN ||
                eventInfo.GetSpellInfo()->Id == SPELL_SHAMAN_LAVA_LASH)
                return true;
            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_sha_crash_lightning_aura_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_crash_lightning_aura_AuraScript();
    }
};

// Crash Lightning - 187874
class spell_sha_crash_lightning : public SpellScriptLoader
{
public:
    spell_sha_crash_lightning() : SpellScriptLoader("spell_sha_crash_lightning") {}

    class spell_sha_crash_lightning_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_crash_lightning_SpellScript);

        int8 targetsHit;

        bool Load() override
        {
            targetsHit = 0;
            return true;
        }

        SpellCastResult CheckCast()
        {
            Unit* caster = GetCaster();
            Unit* target = ObjectAccessor::GetUnit(*caster, caster->GetTarget());
            if (!caster || !target)
                return SPELL_FAILED_DONT_REPORT;

            if (!caster->IsWithinMeleeRange(target))
                return SPELL_FAILED_OUT_OF_RANGE;

            return SPELL_CAST_OK;
        }

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            targetsHit++;
            if (targetsHit == 2)
                caster->CastSpell(caster, SPELL_SHAMAN_CRASH_LIGTHNING_AURA, true);

            if (caster->HasAura(SPELL_SHAMAN_CRASHING_STORM_DUMMY))
                caster->CastSpell(nullptr, SPELL_SHAMAN_CRASHING_STORM_AT, true);
        }

        void Register() override
        {
            OnCheckCast += SpellCheckCastFn(spell_sha_crash_lightning_SpellScript::CheckCast);
            OnEffectHitTarget += SpellEffectFn(spell_sha_crash_lightning_SpellScript::HandleHit, EFFECT_1, SPELL_EFFECT_NORMALIZED_WEAPON_DMG);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_crash_lightning_SpellScript();
    }
};

// 51533 - Feral Spirit
class spell_sha_feral_spirit : public SpellScriptLoader
{
public:
    spell_sha_feral_spirit() : SpellScriptLoader("spell_sha_feral_spirit") {}

    class spell_sha_feral_spirit_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_feral_spirit_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            caster->CastSpell(GetHitUnit(), SPELL_SHAMAN_FERAL_SPIRIT_SUMMON, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_sha_feral_spirit_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_feral_spirit_SpellScript();
    }
};

// -51556 - Ancestral Awakening
class spell_sha_ancestral_awakening : public SpellScriptLoader
{
    public:
        spell_sha_ancestral_awakening() : SpellScriptLoader("spell_sha_ancestral_awakening") { }

        class spell_sha_ancestral_awakening_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_ancestral_awakening_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TIDAL_WAVES))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 heal = int32(CalculatePct(eventInfo.GetHealInfo()->GetHeal(), aurEff->GetAmount()));

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_ANCESTRAL_AWAKENING, SPELLVALUE_BASE_POINT0, heal, (Unit*)NULL, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_ancestral_awakening_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_ancestral_awakening_AuraScript();
        }
};

// 52759 - Ancestral Awakening
/// Updated 4.3.4
class spell_sha_ancestral_awakening_proc : public SpellScriptLoader
{
    public:
        spell_sha_ancestral_awakening_proc() : SpellScriptLoader("spell_sha_ancestral_awakening_proc") { }

        class spell_sha_ancestral_awakening_proc_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_ancestral_awakening_proc_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC))
                    return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.size() < 2)
                    return;

                targets.sort(Trinity::HealthPctOrderPred());

                WorldObject* target = targets.front();
                targets.clear();
                targets.push_back(target);
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastCustomSpell(SPELL_SHAMAN_ANCESTRAL_AWAKENING_PROC, SPELLVALUE_BASE_POINT0, GetEffectValue(), GetHitUnit(), true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_ancestral_awakening_proc_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnEffectHitTarget += SpellEffectFn(spell_sha_ancestral_awakening_proc_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_ancestral_awakening_proc_SpellScript();
        }
};

// 2825 - Bloodlust
class spell_sha_bloodlust : public SpellScriptLoader
{
    public:
        spell_sha_bloodlust() : SpellScriptLoader("spell_sha_bloodlust") { }

        class spell_sha_bloodlust_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_bloodlust_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_SATED)
                    || !sSpellMgr->GetSpellInfo(SPELL_HUNTER_INSANITY)
                    || !sSpellMgr->GetSpellInfo(SPELL_MAGE_TEMPORAL_DISPLACEMENT)
                    || !sSpellMgr->GetSpellInfo(SPELL_PET_NETHERWINDS_FATIGUED))
                    return false;
                return true;
            }

            void RemoveInvalidTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_SATED));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_HUNTER_INSANITY));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_MAGE_TEMPORAL_DISPLACEMENT));
            }

            void ApplyDebuff()
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, SPELL_SHAMAN_SATED, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_bloodlust_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit += SpellHitFn(spell_sha_bloodlust_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_bloodlust_SpellScript();
        }
};

// 1064 - Chain Heal
class spell_sha_chain_heal : public SpellScriptLoader
{
    public:
        spell_sha_chain_heal() : SpellScriptLoader("spell_sha_chain_heal") { }

        class spell_sha_chain_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_chain_heal_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_HIGH_TIDE))
                    return false;
                return true;
            }

            void CatchInitialTarget(WorldObject*& target)
            {
                _primaryTarget = target;
            }

            void SelectAdditionalTargets(std::list<WorldObject*>& targets)
            {
                Unit* caster = GetCaster();
                AuraEffect const* highTide = caster->GetAuraEffect(SPELL_SHAMAN_HIGH_TIDE, EFFECT_1);
                if (!highTide)
                    return;

                static float const range = 25.0f;
                SpellImplicitTargetInfo targetInfo(TARGET_UNIT_TARGET_CHAINHEAL_ALLY);
                ConditionContainer* conditions = GetSpellInfo()->GetEffect(EFFECT_0)->ImplicitTargetConditions;

                uint32 containerTypeMask = GetSpell()->GetSearcherTypeMask(targetInfo.GetObjectType(), conditions);
                if (!containerTypeMask)
                    return;

                std::list<WorldObject*> chainTargets;
                Trinity::WorldObjectSpellAreaTargetCheck check(range, _primaryTarget, caster, caster, GetSpellInfo(), targetInfo.GetCheckType(), conditions);
                Trinity::WorldObjectListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> searcher(caster, chainTargets, check, containerTypeMask);
                Cell::VisitAllObjects(_primaryTarget, searcher, range);

                chainTargets.remove_if(Trinity::UnitAuraCheck(false, SPELL_SHAMAN_RIPTIDE, caster->GetGUID()));
                if (chainTargets.empty())
                    return;

                chainTargets.sort();
                targets.sort();

                std::list<WorldObject*> extraTargets;
                std::set_difference(chainTargets.begin(), chainTargets.end(), targets.begin(), targets.end(), std::back_inserter(extraTargets));
                Trinity::Containers::RandomResize(extraTargets, uint32(highTide->GetAmount()));
                targets.splice(targets.end(), extraTargets);
            }

            WorldObject* _primaryTarget = nullptr;

            void Register() override
            {
                OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_sha_chain_heal_SpellScript::CatchInitialTarget, EFFECT_0, TARGET_UNIT_TARGET_CHAINHEAL_ALLY);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_chain_heal_SpellScript::SelectAdditionalTargets, EFFECT_0, TARGET_UNIT_TARGET_CHAINHEAL_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_chain_heal_SpellScript();
        }
};

// 974 - Earth Shield
class spell_sha_earth_shield : public SpellScriptLoader
{
    public:
        spell_sha_earth_shield() : SpellScriptLoader("spell_sha_earth_shield") { }

        class spell_sha_earth_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_earth_shield_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EARTH_SHIELD_HEAL))
                    return false;
                return true;
            }

            void CalculateAmount(AuraEffect const* aurEff, int32& amount, bool & /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                {
                    amount = caster->SpellHealingBonusDone(GetUnitOwner(), GetSpellInfo(), amount, HEAL, aurEff->GetSpellEffectInfo());
                    amount = GetUnitOwner()->SpellHealingBonusTaken(caster, GetSpellInfo(), amount, HEAL, aurEff->GetSpellEffectInfo());

                    //! WORKAROUND
                    // If target is affected by healing reduction, modifier is guaranteed to be negative
                    // value (e.g. -50). To revert the effect, multiply amount with reciprocal of relative value:
                    // (100 / ((-1) * modifier)) * 100 = (-1) * 100 * 100 / modifier = -10000 / modifier
                    if (int32 modifier = GetUnitOwner()->GetMaxNegativeAuraModifier(SPELL_AURA_MOD_HEALING_PCT))
                        ApplyPct(amount, -10000.0f / float(modifier));
                }
            }

            bool CheckProc(ProcEventInfo& /*eventInfo*/)
            {
                //! HACK due to currenct proc system implementation
                if (Player* player = GetTarget()->ToPlayer())
                    if (player->GetSpellHistory()->HasCooldown(SPELL_SHAMAN_EARTH_SHIELD_HEAL))
                        return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_EARTH_SHIELD_HEAL, SPELLVALUE_BASE_POINT0, aurEff->GetAmount(), GetTarget(), true, NULL, aurEff, GetCasterGUID());

                /// @hack: due to currenct proc system implementation
                if (Player* player = GetTarget()->ToPlayer())
                    player->GetSpellHistory()->AddCooldown(SPELL_SHAMAN_EARTH_SHIELD_HEAL, 0, std::chrono::seconds(3));
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sha_earth_shield_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_DUMMY);
                DoCheckProc += AuraCheckProcFn(spell_sha_earth_shield_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_earth_shield_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_earth_shield_AuraScript();
        }
};

// 117014 - Elemental Blast
class spell_sha_elemental_blast : public SpellScript
{
    PrepareSpellScript(spell_sha_elemental_blast);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT, SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE, SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY });
    }

    void TriggerBuff()
    {
        uint32 spellId = RAND(SPELL_SHAMAN_ELEMENTAL_BLAST_CRIT, SPELL_SHAMAN_ELEMENTAL_BLAST_HASTE, SPELL_SHAMAN_ELEMENTAL_BLAST_MASTERY);
        GetCaster()->CastSpell(GetCaster(), spellId, TRIGGERED_FULL_MASK);
    }

    void Register() override
    {
        AfterCast += SpellCastFn(spell_sha_elemental_blast::TriggerBuff);
    }
};

// 1535 Fire Nova
class spell_sha_fire_nova : public SpellScriptLoader
{
    public:
        spell_sha_fire_nova() : SpellScriptLoader("spell_sha_fire_nova") { }

        class spell_sha_fire_nova_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_fire_nova_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                    if (target->HasAura(SPELL_SHAMAN_FLAME_SHOCK))
                        GetCaster()->CastSpell(target, SPELL_SHAMAN_FIRE_NOVA_TRIGGERED, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_fire_nova_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_fire_nova_SpellScript();
        }
};

// 10400 - Flametongue
// 194084 - Flametongue
class spell_sha_flametongue : public AuraScript
{
    PrepareAuraScript(spell_sha_flametongue);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_FLAMETONGUE_ATTACK });
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        Unit* attacker = eventInfo.GetActor();
        int32 damage = int32(attacker->GetTotalAttackPowerValue(BASE_ATTACK) * 0.2f / 2600 * attacker->getAttackTimer(BASE_ATTACK));
        attacker->CastCustomSpell(SPELL_SHAMAN_FLAMETONGUE_ATTACK, SPELLVALUE_BASE_POINT0, damage, eventInfo.GetActionTarget(), TRIGGERED_FULL_MASK, nullptr, aurEff);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_flametongue::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 88766 - Fulmination
class spell_sha_fulmination : public SpellScriptLoader
{
    public:
        spell_sha_fulmination() : SpellScriptLoader("spell_sha_fulmination") { }

        class spell_sha_fulmination_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_fulmination_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FULMINATION))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FULMINATION_INFO))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_IMPROVED_LIGHTNING_SHIELD))
                    return false;
                SpellInfo const* lightningShield = sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LIGHTNING_SHIELD);
                if (!lightningShield || !lightningShield->GetEffect(EFFECT_0) || !sSpellMgr->GetSpellInfo(lightningShield->GetEffect(EFFECT_0)->TriggerSpell))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_T18_ELEMENTAL_2P_BONUS))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_T18_ELEMENTAL_4P_BONUS))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_T18_LIGHTNING_VORTEX))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // Lava Burst cannot add lightning shield stacks without Improved Lightning Shield
                if ((eventInfo.GetSpellInfo()->SpellFamilyFlags[1] & 0x00001000) && !eventInfo.GetActor()->HasAura(SPELL_SHAMAN_IMPROVED_LIGHTNING_SHIELD))
                    return false;

                return eventInfo.GetActor()->HasAura(SPELL_SHAMAN_LIGHTNING_SHIELD);
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                Unit* caster = eventInfo.GetActor();
                Unit* target = eventInfo.GetActionTarget();
                if (Aura* aura = caster->GetAura(SPELL_SHAMAN_LIGHTNING_SHIELD))
                {
                    // Earth Shock releases the charges
                    if (eventInfo.GetSpellInfo()->SpellFamilyFlags[0] & 0x00100000)
                    {
                        uint32 stacks = aura->GetCharges();
                        if (stacks > 1)
                        {
                            SpellInfo const* triggerSpell = sSpellMgr->AssertSpellInfo(aura->GetSpellEffectInfo(EFFECT_0)->TriggerSpell);
                            SpellEffectInfo const* triggerEffect = triggerSpell->GetEffect(EFFECT_0);

                            uint32 damage;
                            damage = caster->SpellDamageBonusDone(target, triggerSpell, uint32(triggerEffect->CalcValue(caster)), SPELL_DIRECT_DAMAGE, triggerEffect, stacks - 1);
                            damage = target->SpellDamageBonusTaken(caster, triggerSpell, damage, SPELL_DIRECT_DAMAGE, triggerEffect, stacks - 1);

                            caster->CastCustomSpell(SPELL_SHAMAN_FULMINATION, SPELLVALUE_BASE_POINT0, int32(damage), target, TRIGGERED_FULL_MASK);
                            caster->RemoveAurasDueToSpell(SPELL_SHAMAN_FULMINATION_INFO);

                            if (AuraEffect const* t18_4p = caster->GetAuraEffect(SPELL_SHAMAN_ITEM_T18_ELEMENTAL_4P_BONUS, EFFECT_0))
                            {
                                if (Aura* gatheringVortex = caster->GetAura(SPELL_SHAMAN_ITEM_T18_GATHERING_VORTEX))
                                {
                                    if (gatheringVortex->GetStackAmount() + stacks >= uint32(t18_4p->GetAmount()))
                                        caster->CastSpell(caster, SPELL_SHAMAN_ITEM_T18_LIGHTNING_VORTEX, TRIGGERED_FULL_MASK);

                                    if (uint8 newStacks = uint8((gatheringVortex->GetStackAmount() + stacks) % t18_4p->GetAmount()))
                                        gatheringVortex->SetStackAmount(newStacks);
                                    else
                                        gatheringVortex->Remove();
                                }
                                else
                                    caster->CastCustomSpell(SPELL_SHAMAN_ITEM_T18_GATHERING_VORTEX, SPELLVALUE_AURA_STACK, stacks, caster, TRIGGERED_FULL_MASK);
                            }

                            if (AuraEffect const* t18_2p = caster->GetAuraEffect(SPELL_SHAMAN_ITEM_T18_ELEMENTAL_2P_BONUS, EFFECT_0))
                            {
                                if (roll_chance_i(t18_2p->GetAmount()))
                                {
                                    caster->GetSpellHistory()->ResetCooldown(SPELL_SHAMAN_EARTH_SHOCK, true);
                                    return;
                                }
                            }

                            aura->SetCharges(1);
                            aura->SetUsingCharges(false);
                        }
                    }
                    else
                    {
                        aura->SetCharges(std::min<uint8>(aura->GetCharges() + 1, uint8(aurEff->GetAmount())));
                        aura->SetUsingCharges(false);
                        aura->RefreshDuration();

                        if (aura->GetCharges() == aurEff->GetAmount())
                            caster->CastSpell(caster, SPELL_SHAMAN_FULMINATION_INFO, TRIGGERED_FULL_MASK);
                    }
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_fulmination_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_fulmination_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_fulmination_AuraScript();
        }
};

// 55440 - Glyph of Healing Wave
class spell_sha_glyph_of_healing_wave : public SpellScriptLoader
{
    public:
        spell_sha_glyph_of_healing_wave() : SpellScriptLoader("spell_sha_glyph_of_healing_wave") { }

        class spell_sha_glyph_of_healing_wave_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_glyph_of_healing_wave_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                // Not proc from self heals
                return GetTarget() != eventInfo.GetProcTarget();
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 heal = CalculatePct(int32(eventInfo.GetHealInfo()->GetHeal()), aurEff->GetAmount());

                GetTarget()->CastCustomSpell(SPELL_SHAMAN_GLYPH_OF_HEALING_WAVE, SPELLVALUE_BASE_POINT0, heal, (Unit*)NULL, true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_glyph_of_healing_wave_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_glyph_of_healing_wave_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_glyph_of_healing_wave_AuraScript();
        }
};

// 5394 - Healing Stream Totem
class spell_sha_healing_stream_totem : public SpellScriptLoader
{
    public:
        spell_sha_healing_stream_totem() : SpellScriptLoader("spell_sha_healing_stream_totem") { }

        class spell_sha_healing_stream_totem_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_healing_stream_totem_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return sSpellMgr->GetSpellInfo(SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL) != nullptr;
            }

            void HandleDummy(AuraEffect const* aurEff)
            {
                if (Creature* waterTotem = GetTarget()->GetMap()->GetCreature(GetTarget()->m_SummonSlot[3]))
                    waterTotem->CastSpell((Unit*)nullptr, SPELL_SHAMAN_TOTEM_HEALING_STREAM_HEAL, TRIGGERED_FULL_MASK, nullptr, aurEff, GetTarget()->GetGUID());
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_healing_stream_totem_AuraScript::HandleDummy, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_healing_stream_totem_AuraScript();
        }
};

//192077 - Wind Rush Totem
class spell_sha_wind_rush_totem : public SpellScriptLoader
{
public:
    spell_sha_wind_rush_totem() : SpellScriptLoader("spell_sha_wind_rush_totem") { }

    class spell_sha_wind_rush_totem_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_wind_rush_totem_AuraScript);

        void Register() override
        {

        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_wind_rush_totem_AuraScript();
    }
};

// 52042 - Healing Stream Totem
class spell_sha_healing_stream_totem_heal : public SpellScriptLoader
{
    public:
        spell_sha_healing_stream_totem_heal() : SpellScriptLoader("spell_sha_healing_stream_totem_heal") { }

        class spell_sha_healing_stream_totem_heal_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_healing_stream_totem_heal_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_RUSHING_STREAMS) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM_TRIGGERED) ||
                    !sSpellMgr->GetSpellInfo(SPELL_SHAMAN_HEALING_STREAM_DUMMY))
                    return false;

                return true;
            }

            void SelectTargets(std::list<WorldObject*>& targets)
            {
                uint32 targetLimit = 1;
                if (GetOriginalCaster()->HasAura(SPELL_SHAMAN_RUSHING_STREAMS))
                    targetLimit = 2;

                targets.remove_if([](WorldObject* target)
                {
                    return !target->ToUnit() || target->ToUnit()->IsFullHealth();
                });

                Trinity::Containers::RandomResize(targets, targetLimit);

                if (targets.empty())
                    targets.push_back(GetOriginalCaster());
            }

            void HandleEffect(SpellEffIndex /*effIndex*/)
            {
                if (GetOriginalCaster()->HasAura(SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM))
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM_TRIGGERED, TRIGGERED_FULL_MASK);

                GetCaster()->CastSpell(GetHitUnit(), SPELL_SHAMAN_HEALING_STREAM_DUMMY, TRIGGERED_FULL_MASK);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_healing_stream_totem_heal_SpellScript::SelectTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
                OnEffectHitTarget += SpellEffectFn(spell_sha_healing_stream_totem_heal_SpellScript::HandleEffect, EFFECT_0, SPELL_EFFECT_HEAL);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_healing_stream_totem_heal_SpellScript();
        }
};

// 32182 - Heroism
class spell_sha_heroism : public SpellScriptLoader
{
    public:
        spell_sha_heroism() : SpellScriptLoader("spell_sha_heroism") { }

        class spell_sha_heroism_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_heroism_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_EXHAUSTION)
                    || !sSpellMgr->GetSpellInfo(SPELL_HUNTER_INSANITY)
                    || !sSpellMgr->GetSpellInfo(SPELL_MAGE_TEMPORAL_DISPLACEMENT)
                    || !sSpellMgr->GetSpellInfo(SPELL_PET_NETHERWINDS_FATIGUED))
                    return false;
                return true;
            }

            void RemoveInvalidTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_EXHAUSTION));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_HUNTER_INSANITY));
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_MAGE_TEMPORAL_DISPLACEMENT));
            }

            void ApplyDebuff()
            {
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, SPELL_SHAMAN_EXHAUSTION, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_heroism_SpellScript::RemoveInvalidTargets, EFFECT_1, TARGET_UNIT_CASTER_AREA_RAID);
                AfterHit += SpellHitFn(spell_sha_heroism_SpellScript::ApplyDebuff);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_heroism_SpellScript();
        }
};

// 23551 - Lightning Shield
class spell_sha_item_lightning_shield : public SpellScriptLoader
{
    public:
        spell_sha_item_lightning_shield() : SpellScriptLoader("spell_sha_item_lightning_shield") { }

        class spell_sha_item_lightning_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_lightning_shield_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_lightning_shield_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_lightning_shield_AuraScript();
        }
};

// 23552 - Lightning Shield
class spell_sha_item_lightning_shield_trigger : public SpellScriptLoader
{
    public:
        spell_sha_item_lightning_shield_trigger() : SpellScriptLoader("spell_sha_item_lightning_shield_trigger") { }

        class spell_sha_item_lightning_shield_trigger_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_lightning_shield_trigger_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_lightning_shield_trigger_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_lightning_shield_trigger_AuraScript();
        }
};

// 23572 - Mana Surge
class spell_sha_item_mana_surge : public SpellScriptLoader
{
    public:
        spell_sha_item_mana_surge() : SpellScriptLoader("spell_sha_item_mana_surge") { }

        class spell_sha_item_mana_surge_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_mana_surge_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ITEM_LIGHTNING_SHIELD_DAMAGE))
                    return false;
                return true;
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                std::vector<SpellPowerCost> costs = eventInfo.GetDamageInfo()->GetSpellInfo()->CalcPowerCost(GetTarget(), eventInfo.GetDamageInfo()->GetSchoolMask());
                auto m = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA; });
                if (m != costs.end())
                {
                    int32 mana = CalculatePct(m->Amount, 35);
                    if (mana > 0)
                        GetTarget()->CastCustomSpell(SPELL_SHAMAN_ITEM_MANA_SURGE, SPELLVALUE_BASE_POINT0, mana, GetTarget(), true, NULL, aurEff);
                }
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_mana_surge_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_mana_surge_AuraScript();
        }
};

// 70811 - Item - Shaman T10 Elemental 2P Bonus
class spell_sha_item_t10_elemental_2p_bonus : public SpellScriptLoader
{
    public:
        spell_sha_item_t10_elemental_2p_bonus() : SpellScriptLoader("spell_sha_item_t10_elemental_2p_bonus") { }

        class spell_sha_item_t10_elemental_2p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_item_t10_elemental_2p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ELEMENTAL_MASTERY))
                    return false;
                return true;
            }

            void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                if (Player* target = GetTarget()->ToPlayer())
                    target->GetSpellHistory()->ModifyCooldown(SPELL_SHAMAN_ELEMENTAL_MASTERY, -aurEff->GetAmount());
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_sha_item_t10_elemental_2p_bonus_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_item_t10_elemental_2p_bonus_AuraScript();
        }
};

// 189063 - Lightning Vortex (proc 185881 Item - Shaman T18 Elemental 4P Bonus)
class spell_sha_item_t18_elemental_4p_bonus : public SpellScriptLoader
{
public:
    spell_sha_item_t18_elemental_4p_bonus() : SpellScriptLoader("spell_sha_item_t18_elemental_4p_bonus") { }

    class spell_sha_item_t18_elemental_4p_bonus_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_item_t18_elemental_4p_bonus_AuraScript);

        void DiminishHaste(AuraEffect const* aurEff)
        {
            PreventDefaultAction();
            if (AuraEffect* hasteBuff = GetEffect(EFFECT_0))
                hasteBuff->ChangeAmount(hasteBuff->GetAmount() - aurEff->GetAmount());
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_item_t18_elemental_4p_bonus_AuraScript::DiminishHaste, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_item_t18_elemental_4p_bonus_AuraScript();
    }
};

// 60103 - Lava Lash
class spell_sha_lava_lash : public SpellScriptLoader
{
    public:
        spell_sha_lava_lash() : SpellScriptLoader("spell_sha_lava_lash") { }

        class spell_sha_lava_lash_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_lava_lash_SpellScript);

            bool Load() override
            {
                return GetCaster()->IsPlayer();
            }

            void HandleWeaponPercentDamage(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastCustomSpell(SPELL_SHAMAN_LAVA_LASH_SPREAD_FLAME_SHOCK, SPELLVALUE_MAX_TARGETS, GetEffectValue(), GetHitUnit(), TRIGGERED_FULL_MASK);

                GetCaster()->RemoveAurasDueToSpell(SPELL_SHAMAN_HOT_HAND);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_lava_lash_SpellScript::HandleWeaponPercentDamage, EFFECT_0, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_lava_lash_SpellScript();
        }
};

// 105792 - Lava Lash
class spell_sha_lava_lash_spread_flame_shock : public SpellScriptLoader
{
    public:
        spell_sha_lava_lash_spread_flame_shock() : SpellScriptLoader("spell_sha_lava_lash_spread_flame_shock") { }

        class spell_sha_lava_lash_spread_flame_shock_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_lava_lash_spread_flame_shock_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(Trinity::UnitAuraCheck(true, SPELL_SHAMAN_FLAME_SHOCK, GetCaster()->GetGUID()));
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* mainTarget = GetExplTargetUnit())
                {
                    if (Aura* flameShock = mainTarget->GetAura(SPELL_SHAMAN_FLAME_SHOCK, GetCaster()->GetGUID()))
                    {
                        if (Aura* newAura = GetCaster()->AddAura(SPELL_SHAMAN_FLAME_SHOCK, GetHitUnit()))
                        {
                            newAura->SetDuration(flameShock->GetDuration());
                            newAura->SetMaxDuration(flameShock->GetDuration());
                        }
                    }
                }
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_lava_lash_spread_flame_shock_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_sha_lava_lash_spread_flame_shock_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_lava_lash_spread_flame_shock_SpellScript();
        }
};

// 77756 - Lava Surge
class spell_sha_lava_surge : public AuraScript
{
    PrepareAuraScript(spell_sha_lava_surge);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_SURGE });
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_LAVA_SURGE_CAST_TIME, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_lava_surge::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 77762 - Lava Surge
class spell_sha_lava_surge_proc : public SpellScript
{
    PrepareSpellScript(spell_sha_lava_surge_proc);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_LAVA_BURST });
    }

    bool Load() override
    {
        return GetCaster()->IsPlayer();
    }

    void ResetCooldown()
    {
        GetCaster()->GetSpellHistory()->RestoreCharge(sSpellMgr->AssertSpellInfo(SPELL_SHAMAN_LAVA_BURST)->ChargeCategoryId);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_sha_lava_surge_proc::ResetCooldown);
    }
};

// 324 - Lightning Shield
class spell_sha_lightning_shield : public SpellScriptLoader
{
public:
    spell_sha_lightning_shield() : SpellScriptLoader("spell_sha_lightning_shield") { }

    class spell_sha_lightning_shield_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_lightning_shield_AuraScript);

        void UnsetUsingCharges(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            GetAura()->SetUsingCharges(false);
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_sha_lightning_shield_AuraScript::UnsetUsingCharges, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_lightning_shield_AuraScript();
    }
};

// 30884 - Nature's Guardian
class spell_sha_nature_guardian : public SpellScriptLoader
{
    public:
        spell_sha_nature_guardian() : SpellScriptLoader("spell_sha_nature_guardian") { }

        class spell_sha_nature_guardian_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_sha_nature_guardian_AuraScript);

            bool Validate(SpellInfo const* spellInfo) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_NATURE_GUARDIAN))
                    return false;
                if (!spellInfo->GetEffect(EFFECT_1))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                //! HACK due to currenct proc system implementation
                if (GetTarget()->GetSpellHistory()->HasCooldown(GetSpellInfo()->Id))
                    return false;

                return GetTarget()->HealthBelowPctDamaged(30, eventInfo.GetDamageInfo()->GetDamage());
            }

            void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 basePoints0 = GetTarget()->CountPctFromMaxHealth(aurEff->GetAmount());

                GetTarget()->CastCustomSpell(GetTarget(), SPELL_SHAMAN_NATURE_GUARDIAN, &basePoints0, NULL, NULL, true);

                if (eventInfo.GetProcTarget() && eventInfo.GetProcTarget()->IsAlive())
                    eventInfo.GetProcTarget()->getThreatManager().modifyThreatPercent(GetTarget(), -10);

                GetTarget()->GetSpellHistory()->AddCooldown(GetSpellInfo()->Id, 0, std::chrono::seconds(aurEff->GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue()));
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_sha_nature_guardian_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_sha_nature_guardian_AuraScript::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_sha_nature_guardian_AuraScript();
        }
};

// 51490 - Thunderstorm
class spell_sha_thunderstorm : public SpellScriptLoader
{
    public:
        spell_sha_thunderstorm() : SpellScriptLoader("spell_sha_thunderstorm") { }

        class spell_sha_thunderstorm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_sha_thunderstorm_SpellScript);

            void HandleKnockBack(SpellEffIndex effIndex)
            {
                // Glyph of Thunderstorm
                if (GetCaster()->HasAura(SPELL_SHAMAN_GLYPH_OF_THUNDERSTORM))
                    PreventHitDefaultEffect(effIndex);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_sha_thunderstorm_SpellScript::HandleKnockBack, EFFECT_1, SPELL_EFFECT_KNOCK_BACK);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_sha_thunderstorm_SpellScript();
        }
};

// 51564 - Tidal Waves
class spell_sha_tidal_waves : public AuraScript
{
    PrepareAuraScript(spell_sha_tidal_waves);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_TIDAL_WAVES });
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        PreventDefaultAction();
        GetTarget()->CastSpell(GetTarget(), SPELL_SHAMAN_TIDAL_WAVES, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sha_tidal_waves::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 8232 - Windfury Weapon
class spell_shaman_windfury_weapon : public SpellScriptLoader
{
public:
    spell_shaman_windfury_weapon() : SpellScriptLoader("spell_shaman_windfury_weapon") {}

    class spell_shaman_windfury_weapon_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_shaman_windfury_weapon_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return sSpellMgr->GetSpellInfo(SPELL_SHAMAN_WINDFURY_WEAPON_PASSIVE) != nullptr;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (AuraEffect* auraEffect = caster->GetAuraEffect(SPELL_SHAMAN_WINDFURY_WEAPON_PASSIVE, EFFECT_0))
                    auraEffect->SetAmount(GetEffectValue());
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_shaman_windfury_weapon_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_shaman_windfury_weapon_SpellScript();
    }
};

class spell_sha_earthgrab : public SpellScriptLoader
{
public:
    spell_sha_earthgrab() : SpellScriptLoader("spell_sha_earthgrab") { }

    class spell_sha_earthgrab_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_earthgrab_SpellScript);

        void HandleOnHit()
        {
            if (Unit* caster = GetCaster())
            {
                if (Unit* target = GetHitUnit())
                {
                    if (target->HasAura(SPELL_SHAMAN_EARTHGRAB_IMMUNITY, caster->GetGUID()))
                        caster->CastSpell(target, SPELL_SHAMAN_EARTHBIND_FOR_EARTHGRAB_TOTEM, true);
                    else
                        caster->CastSpell(target, SPELL_SHAMAN_EARTHGRAB_IMMUNITY, true);
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_sha_earthgrab_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_earthgrab_SpellScript();
    }
};

// 61882
class aura_sha_earthquake : public AuraScript
{
    PrepareAuraScript(aura_sha_earthquake);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_EARTHQUAKE });
    }

    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        if (AreaTrigger* at = GetTarget()->GetAreaTrigger(SPELL_SHAMAN_EARTHQUAKE))
            GetTarget()->CastSpell(at->GetPosition(), SPELL_SHAMAN_EARTHQUAKE_TICK, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_sha_earthquake::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 77478
class spell_sha_earthquake_tick : public SpellScript
{
    PrepareSpellScript(spell_sha_earthquake_tick);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_EARTHQUAKE_TICK });
    }

    void CalcDamage(SpellEffIndex /*effIndex*/)
    {
        uint32 dmg = GetCaster()->GetTotalSpellPowerValue(SPELL_SCHOOL_MASK_NATURE, false) * 0.92f;
        SetHitDamage(dmg);
    }

    void HandleOnHit()
    {
        if (Unit* target = GetHitUnit())
            if (roll_chance_i(GetEffectInfo(EFFECT_1)->BasePoints))
                GetCaster()->CastSpell(target, SPELL_SHAMAN_EARTHQUAKE_KNOCKING_DOWN, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_earthquake_tick::CalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        OnHit += SpellHitFn(spell_sha_earthquake_tick::HandleOnHit);
    }
};

class spell_sha_glyph_of_lakestrider : public SpellScriptLoader
{
public:
    spell_sha_glyph_of_lakestrider() : SpellScriptLoader("spell_sha_glyph_of_lakestrider") { }

    class spell_sha_glyph_of_lakestrider_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_glyph_of_lakestrider_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
                if (_player->HasAura(SPELL_SHAMAN_GLYPH_OF_LAKESTRIDER))
                    _player->CastSpell(_player, SPELL_SHAMAN_WATER_WALKING, true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_sha_glyph_of_lakestrider_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_glyph_of_lakestrider_SpellScript();
    }
};

class spell_sha_glyph_of_shamanistic_rage : public SpellScriptLoader
{
public:
    spell_sha_glyph_of_shamanistic_rage() : SpellScriptLoader("spell_sha_glyph_of_shamanistic_rage") { }

    class spell_sha_glyph_of_shamanistic_rage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_glyph_of_shamanistic_rage_SpellScript);

        void HandleOnHit()
        {
            if (Player* _player = GetCaster()->ToPlayer())
            {
                if (_player->HasAura(SPELL_SHAMAN_GLYPH_OF_SHAMANISTIC_RAGE))
                {
                    DispelChargesList dispelList;
                    _player->GetDispellableAuraList(_player, DISPEL_ALL_MASK, dispelList);
                    if (!dispelList.empty())
                    {
                        for (DispelChargesList::iterator itr = dispelList.begin(); itr != dispelList.end(); itr++)
                            if (_player->HasAura(itr->GetAura()->GetId()))
                                _player->RemoveAura(itr->GetAura());
                    }
                }
            }
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_sha_glyph_of_shamanistic_rage_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_glyph_of_shamanistic_rage_SpellScript();
    }
};

class spell_sha_healing_stream : public SpellScriptLoader
{
public:
    spell_sha_healing_stream() : SpellScriptLoader("spell_sha_healing_stream") { }

    class spell_sha_healing_stream_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_healing_stream_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_HEALING_STREAM))
                return false;
            return true;
        }

        void HandleOnHit()
        {
            if (!GetCaster()->GetOwner())
                return;

            if (Player* _player = GetCaster()->GetOwner()->ToPlayer())
                if (Unit* target = GetHitUnit())
                    // Glyph of Healing Stream Totem
                    if (target->GetGUID() != _player->GetGUID() && _player->HasAura(SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM_TOTEM))
                        _player->CastSpell(target, SPELL_SHAMAN_GLYPH_OF_HEALING_STREAM, true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_sha_healing_stream_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_healing_stream_SpellScript();
    }
};

// Spirit link
class spell_sha_spirit_link : public SpellScriptLoader
{
public:
    spell_sha_spirit_link() : SpellScriptLoader("spell_sha_spirit_link") { }

    class spell_sha_spirit_link_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_spirit_link_SpellScript);

        bool Load() override
        {
            averagePercentage = 0.0f;
            return true;
        }

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            uint32 targetCount = 0;
            for (std::list<WorldObject*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                if (Unit* target = (*itr)->ToUnit())
                {
                    targets[target->GetGUID()] = target->GetHealthPct();
                    averagePercentage += target->GetHealthPct();
                    ++targetCount;
                }

            averagePercentage /= targetCount;
        }

        void HandleOnHit()
        {
            if (Unit* target = GetHitUnit())
            {
                if (targets.find(target->GetGUID()) == targets.end())
                    return;

                int32 bp0 = 0;
                int32 bp1 = 0;
                float percentage = targets[target->GetGUID()];
                int64 currentHp = target->CountPctFromMaxHealth(percentage);
                int64 desiredHp = target->CountPctFromMaxHealth(averagePercentage);
                if (desiredHp > currentHp)
                    bp1 = desiredHp - currentHp;
                else
                    bp0 = currentHp - desiredHp;
                GetCaster()->CastCustomSpell(target, 98021, &bp0, &bp1, NULL, false);
            }

        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_spirit_link_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_CASTER_AREA_RAID);
            OnHit += SpellHitFn(spell_sha_spirit_link_SpellScript::HandleOnHit);
        }

    private:
        std::map<ObjectGuid, float> targets;
        float averagePercentage;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_spirit_link_SpellScript();
    }
};

class spell_sha_spiritwalkers_grace : public SpellScriptLoader
{
public:
    spell_sha_spiritwalkers_grace() : SpellScriptLoader("spell_sha_spiritwalkers_grace") { }

    class spell_sha_spiritwalkers_grace_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_spiritwalkers_grace_SpellScript);

        void HandleOnHit()
        {
            Unit* caster = GetCaster();
            if (caster->HasAura(159651))
                caster->CastSpell(caster, 159652, true);
        }

        void Register() override
        {
            OnHit += SpellHitFn(spell_sha_spiritwalkers_grace_SpellScript::HandleOnHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_spiritwalkers_grace_SpellScript();
    }
};

enum Resurgence
{
    SPELL_WATER_SHIELD = 52127,  // Player must have this aura to let the spell proc
    SPELL_RESURGENCE = 16196,  // Dummy aura applied on the player (spec spell)
    SPELL_RESURGENCE_PROC = 101033, // Regenerate life according to the spell that triggered the proc

    /* Spells that can cause the proc  */
    SPELL_HEALING_WAVE = 331,
    SPELL_GREATER_HEALING_WAVE = 77472,
    SPELL_RIPTIDE = 61295,
    SPELL_HEALING_SURGE = 8004,
    SPELL_UNLEASH_LIFE = 73685, // Triggered when Unleashed Elements is used on Earthliving Weapon
    SPELL_CHAIN_HEAL = 1064,
};

// Script to handle the dummy proc of 16196
class spell_sha_resurgence : public SpellScriptLoader
{
public:
    spell_sha_resurgence() : SpellScriptLoader("spell_sha_resurgence"){ }

    class spell_sha_resurgence_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_resurgence_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_WATER_SHIELD, SPELL_RESURGENCE, SPELL_RESURGENCE_PROC });
        }

        // Spell cannot proc if caster doesn't have aura 52127
        bool CheckDummyProc(ProcEventInfo& procInfo)
        {
            if (Unit* target = procInfo.GetActor())
                return target->HasAura(SPELL_WATER_SHIELD);

            return false;
        }

        void HandleDummyProc(ProcEventInfo& procInfo)
        {
            int32 healAmount = 0;
            if (Unit *target = procInfo.GetActor())
            {
                healAmount = target->CalculateSpellDamage(target, sSpellMgr->GetSpellInfo(SPELL_RESURGENCE_PROC), 0);
                if (healAmount)
                {
                    // Change heal amount accoring to the spell that triggered this one */
                    if (DamageInfo *damageInfo = procInfo.GetDamageInfo())
                    {
                        switch (damageInfo->GetSpellInfo()->Id)
                        {
                            // 100% on Healing Wave and Greater Healing Wave
                        case SPELL_HEALING_WAVE:
                        case SPELL_GREATER_HEALING_WAVE:
                            break;

                            // 60% on Riptide, Healing Surge and Unleash Life
                        case SPELL_RIPTIDE:
                        case SPELL_HEALING_SURGE:
                        case SPELL_UNLEASH_LIFE:
                            healAmount *= 0.6f;
                            break;

                            // 33% on Chain Heal
                        case SPELL_CHAIN_HEAL:
                            healAmount *= 0.33f;
                            break;

                            /*
                            * If we have something else here, we should assert, because it would not be
                            * logic (if spell_proc_event entry in DB is correct). But, since I cannot be
                            * sure that proc system is 100% correct, just return for now.
                            */
                        default:
                            return;
                        } // switch damageInfo->GetSpellInfo()->Id

                        target->CastCustomSpell(target, SPELL_RESURGENCE_PROC, &healAmount, NULL, NULL, true);
                    }   // if procInfo.GetDamageInfo()
                }   // if target->CalculateSpellDamage()
            }   // if procInfo.GetActor()
        }   // void HandleDummyProc

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_sha_resurgence_AuraScript::CheckDummyProc);
            OnProc += AuraProcFn(spell_sha_resurgence_AuraScript::HandleDummyProc);
        }
    };

    AuraScript *GetAuraScript() const override
    {
        return new spell_sha_resurgence_AuraScript();
    }
};


// Spells used by the Earthgrab Totem of the Shaman
enum EarthgrabTotem
{
    // Applied on the totem, ticks every two seconds and roots all targets within 10 yards (64695)
    SPELL_EARTHGRAB = 116943,
    SPELL_EARTHGRAB_PERIODIC = 64695,

    // When Earthgrab already hit a target, this target cannot be rooted a second time, and is instead
    // slowed with this one. (Same as the one used by Earthbind Totem)
    SPELL_EARTHBIND = 3600,
};

typedef std::list<WorldObject*> WorldObjectList;
typedef WorldObjectList::const_iterator WorldObjectListCIter;

enum ShamanTotems
{
    /* Entries */
    NPC_TOTEM_MAGMA = 5929,
    NPC_TOTEM_HEALING_STREAM = 3527,
    NPC_TOTEM_HEALING_TIDE = 59764,

    /* Spells */
    SPELL_MAGMA_TOTEM = 8188,     // Ticks every two seconds, inflicting damages to all the creatures in a 8 yards radius
    SPELL_HEALING_STREAM = 5672,     // Ticks every two seconds, targeting the group member with lowest hp in a 40 yards radius
    SPELL_HEALING_TIDE = 114941,   // Ticks every two seconds, targeting 5 / 12 group / raid members with lowest hp in a 40 yards radius
};

// 33757 - Windfury
class spell_sha_windfury : public AuraScript
{
    PrepareAuraScript(spell_sha_windfury);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_WINDFURY_ATTACK });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetDamageInfo()->GetAttackType() == BASE_ATTACK;
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();

        //Proc Chance is increased by 6.24% of Mastery (ceiled)
        float masteryBonus = 0.0f;
        if (Player* player = eventInfo.GetActor()->ToPlayer())
            masteryBonus += (player->GetFloatValue(ACTIVE_PLAYER_FIELD_MASTERY)*6.24f) / 100.0f;

        float rollChance = 5.0f + masteryBonus;
        if (roll_chance_f(rollChance) || eventInfo.GetActor()->HasAura(SPELL_SHAMAN_DOOM_WINDS))
            for (uint32 i = 0; i < 2; ++i)
                eventInfo.GetActor()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHAMAN_WINDFURY_ATTACK, true, nullptr, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_windfury::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_windfury::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

//188196 - Lightning bolt (Elemental)
class spell_sha_lightning_bolt_elem : public SpellScriptLoader
{
public:
    spell_sha_lightning_bolt_elem() : SpellScriptLoader("spell_sha_lightning_bolt_elem") {}

    class spell_sha_lightning_bolt_elem_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_lightning_bolt_elem_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_LIGHTNING_BOLT_ELEM_POWER))
                return false;
            return true;
        }

        void HandleHitTarget(SpellEffIndex /*eff*/)
        {
            if (Unit* caster = GetCaster())
                caster->CastSpell(caster, SPELL_SHAMAN_LIGHTNING_BOLT_ELEM_POWER, true);
        }


        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_sha_lightning_bolt_elem_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_lightning_bolt_elem_SpellScript();
    }
};

//187880 - Maelstrom Weapon
class spell_sha_maelstrom_weapon : public AuraScript
{
    PrepareAuraScript(spell_sha_maelstrom_weapon);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_MAELSTROM_WEAPON_POWER });
    }

    bool CheckEffectProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetDamageInfo()->GetAttackType() == BASE_ATTACK ||
               eventInfo.GetDamageInfo()->GetAttackType() == OFF_ATTACK ||
               eventInfo.GetSpellInfo()->Id == SPELL_SHAMAN_WINDFURY_ATTACK;
    }

    void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_SHAMAN_MAELSTROM_WEAPON_POWER, true);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_maelstrom_weapon::CheckEffectProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_maelstrom_weapon::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

class spell_sha_flame_shock_elem : public SpellScriptLoader
{
public:
    spell_sha_flame_shock_elem() : SpellScriptLoader("spell_sha_flame_shock_elem") {}

    class spell_sha_flame_shock_elem_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_flame_shock_elem_AuraScript);

        int32 m_ExtraSpellCost;

        bool Load() override
        {
            Unit* caster = GetCaster();
            if (!caster)
                return false;

            m_ExtraSpellCost = std::min(caster->GetPower(POWER_MAELSTROM), 20);
            return true;
        }

        void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            int32 m_newDuration = GetDuration() + (GetDuration() * (m_ExtraSpellCost / 20));
            SetDuration(m_newDuration);

            if (Unit* caster = GetCaster())
            {
                int32 m_newMael = caster->GetPower(POWER_MAELSTROM) - m_ExtraSpellCost;
                if (m_newMael < 0)
                    m_newMael = 0;
                caster->SetPower(POWER_MAELSTROM, m_newMael);
                if (Player* player = caster->ToPlayer())
                    player->SendPowerUpdate(POWER_MAELSTROM, m_newMael);
            }
        }

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;
            if(caster->HasAura(SPELL_SHAMAN_LAVA_SURGE))
                if (roll_chance_i(10))
                {
                    caster->CastSpell(caster, SPELL_SHAMAN_LAVA_SURGE_CAST_TIME);
                    caster->GetSpellHistory()->ResetCooldown(SPELL_SHAMAN_LAVA_BURST, true);
                }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_sha_flame_shock_elem_AuraScript::HandleApply, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_flame_shock_elem_AuraScript::HandlePeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_flame_shock_elem_AuraScript();
    }
};

//197211 - Fury of Air
class spell_sha_fury_of_air : public SpellScriptLoader
{
public:
    spell_sha_fury_of_air() : SpellScriptLoader("spell_sha_fury_of_air") {}

    class spell_sha_fury_of_air_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_fury_of_air_AuraScript);

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->GetPower(POWER_MAELSTROM) >= 5)
                caster->SetPower(POWER_MAELSTROM, caster->GetPower(POWER_MAELSTROM) - 5);
            else
                caster->RemoveAura(SPELL_SHAMAN_FURY_OF_AIR);

        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_fury_of_air_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_fury_of_air_AuraScript();
    }
};

//192223 - Liquid Magma Totem
class spell_sha_liquid_magma_effect : public SpellScriptLoader
{
public:
    spell_sha_liquid_magma_effect() : SpellScriptLoader("spell_sha_liquid_magma_effect") { }

    class spell_sha_liquid_magma_effect_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_liquid_magma_effect_SpellScript);

        void HandleCast()
        {
            if (Unit* caster = GetCaster())
            {
                caster->CastSpell(caster, SPELL_SHAMAN_LIQUID_MAGMA_DAMAGE, true);
            }
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_sha_liquid_magma_effect_SpellScript::HandleCast);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_liquid_magma_effect_SpellScript();
    }
};

//202192 - Resonance totem
class spell_sha_resonance_effect : public SpellScriptLoader
{
public:
    spell_sha_resonance_effect() : SpellScriptLoader("spell_sha_resonance_effect") {}

    class spell_sha_resonance_effect_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_resonance_effect_AuraScript);

        void HandlePeriodic(AuraEffect const* /*aurEff*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            if (caster->GetOwner())
                caster->GetOwner()->ModifyPower(POWER_MAELSTROM, +1);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_resonance_effect_AuraScript::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_ENERGIZE);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_resonance_effect_AuraScript();
    }
};

//157504 - Cloudburst Totem
class spell_sha_cloudburst_effect : public SpellScriptLoader
{
public:
    spell_sha_cloudburst_effect() : SpellScriptLoader("spell_sha_cloudburst_effect") { }

    class spell_sha_cloudburst_effect_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_cloudburst_effect_AuraScript);

        void OnProc(AuraEffect const* p_AurEff, ProcEventInfo& p_EventInfo)
        {
            PreventDefaultAction();

            HealInfo* l_HealInfo = p_EventInfo.GetHealInfo();

            if (!l_HealInfo)
                return;

            if (sSpellMgr->GetSpellInfo(SPELL_TOTEM_CLOUDBURST))
            {
                SpellInfo const* l_SpellInfo = sSpellMgr->GetSpellInfo(SPELL_TOTEM_CLOUDBURST);
                GetEffect(p_AurEff->GetEffIndex())->SetAmount(p_AurEff->GetAmount() + CalculatePct(l_HealInfo->GetHeal(), l_SpellInfo->GetEffect(EFFECT_0)->BasePoints));
            }
        }

        void OnRemove(AuraEffect const* p_AurEff, AuraEffectHandleModes /* p_Mode */)
        {
            if (Unit* l_Owner = GetOwner()->ToUnit())
            {
                if (int32 l_Amount = p_AurEff->GetAmount())
                {
                    l_Owner->CastCustomSpell(l_Owner, SPELL_TOTEM_CLOUDBURST, &l_Amount, nullptr, nullptr, true);
                    GetEffect(p_AurEff->GetEffIndex())->SetAmount(0);
                }
            }
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_sha_cloudburst_effect_AuraScript::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
            OnEffectRemove += AuraEffectRemoveFn(spell_sha_cloudburst_effect_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_cloudburst_effect_AuraScript();
    }
};

//Cloudburst - 157503
class spell_sha_cloudburst : public SpellScriptLoader
{
public:
    spell_sha_cloudburst() : SpellScriptLoader("spell_sha_cloudburst") { }

    class spell_sha_cloudburst_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_cloudburst_SpellScript);

        bool Load() override
        {
            l_TargetCount = 0;
            return true;
        }

        void HandleHeal(SpellEffIndex /*p_EffIndex*/)
        {
            if (l_TargetCount)
                SetHitHeal(GetHitHeal() / l_TargetCount);
        }

        void CountTargets(std::list<WorldObject*>& p_Targets)
        {
            l_TargetCount = p_Targets.size();
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_cloudburst_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            OnEffectHitTarget += SpellEffectFn(spell_sha_cloudburst_SpellScript::HandleHeal, EFFECT_0, SPELL_EFFECT_HEAL);
        }

        uint8 l_TargetCount;
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_cloudburst_SpellScript;
    }
};

// 108281 - Ancestral Guidance
class spell_sha_ancestral_guidance : public AuraScript
{
    PrepareAuraScript(spell_sha_ancestral_guidance);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL });
    }

    bool CheckProc(ProcEventInfo& eventInfo)
    {
        return eventInfo.GetHealInfo() && eventInfo.GetHealInfo()->GetSpellInfo()->Id == SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL;
    }

    void HandleEffectProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        PreventDefaultAction();
        int32 bp0 = CalculatePct(int32(eventInfo.GetDamageInfo()->GetDamage()), aurEff->GetAmount());
        if (bp0)
            eventInfo.GetActor()->CastCustomSpell(SPELL_SHAMAN_ANCESTRAL_GUIDANCE_HEAL, SPELLVALUE_BASE_POINT0, bp0, eventInfo.GetActor(), true, NULL, aurEff);
    }

    void Register() override
    {
        DoCheckProc += AuraCheckProcFn(spell_sha_ancestral_guidance::CheckProc);
        OnEffectProc += AuraEffectProcFn(spell_sha_ancestral_guidance::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 114911 - Ancestral Guidance Heal
class spell_sha_ancestral_guidance_heal : public SpellScriptLoader
{
public:
    spell_sha_ancestral_guidance_heal() : SpellScriptLoader("spell_sha_ancestral_guidance_heal") { }

    class spell_sha_ancestral_guidance_heal_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_ancestral_guidance_heal_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_ANCESTRAL_GUIDANCE))
                return false;
            return true;
        }

        void ResizeTargets(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResize(targets, 3);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_ancestral_guidance_heal_SpellScript::ResizeTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_ancestral_guidance_heal_SpellScript();
    }
};

// Ascendance (Water) - 114052
class spell_sha_ascendance_water : public SpellScriptLoader
{
public:
    spell_sha_ascendance_water() : SpellScriptLoader("spell_sha_ascendance_water") { }

    class spell_sha_ascendance_water_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_ascendance_water_AuraScript);

        enum eSpells
        {
            RestorativeMists = 114083
        };

        void OnProc(AuraEffect const* /*p_AurEff*/, ProcEventInfo& p_EventInfo)
        {
            PreventDefaultAction();

            if (!GetCaster())
                return;

            Player* l_Player = GetCaster()->ToPlayer();
            if (!l_Player)
                return;

            if (p_EventInfo.GetActor()->GetGUID() != l_Player->GetGUID())
                return;

            if (!p_EventInfo.GetDamageInfo()->GetSpellInfo())
                return;

            if (p_EventInfo.GetDamageInfo()->GetSpellInfo()->Id == eSpells::RestorativeMists)
                return;

            if (!(p_EventInfo.GetHealInfo()->GetHeal()))
                return;

            if (!(p_EventInfo.GetDamageInfo()->GetSpellInfo()->IsPositive()))
                return;

            if (Unit* l_Target = p_EventInfo.GetActionTarget())
            {
                int32 l_Bp = p_EventInfo.GetHealInfo()->GetHeal();

                if (l_Bp > 0)
                    l_Player->CastCustomSpell(l_Target, eSpells::RestorativeMists, &l_Bp, NULL, NULL, true); //< Restorative Mists
            }
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_sha_ascendance_water_AuraScript::OnProc, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_ascendance_water_AuraScript();
    }
};

// Ascendance (Water)(heal) - 114083
class spell_sha_ascendance_water_heal : public SpellScriptLoader
{
public:
    spell_sha_ascendance_water_heal() : SpellScriptLoader("spell_sha_ascendance_water_heal") { }

    class spell_sha_ascendance_water_heal_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_ascendance_water_heal_SpellScript);

        uint32 m_TargetSize = 0;

        void OnEffectHeal(SpellEffIndex /*effIndex*/)
        {
            SetHitHeal(GetHitHeal() / m_TargetSize);
        }

        void FilterTargets(std::list<WorldObject*>& p_Targets)
        {
            m_TargetSize = p_Targets.size();
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_sha_ascendance_water_heal_SpellScript::OnEffectHeal, EFFECT_0, SPELL_EFFECT_HEAL);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_ascendance_water_heal_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ALLY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_ascendance_water_heal_SpellScript();
    }
};

// 170374 - Earthen Rage (Passive)
class spell_sha_earthen_rage_passive : public SpellScriptLoader
{
public:
    spell_sha_earthen_rage_passive() : SpellScriptLoader("spell_sha_earthen_rage_passive") { }

    class spell_sha_earthen_rage_passive_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_earthen_rage_passive_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE, SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC, SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE });
        }

        void HandleEffectProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
        {
            PreventDefaultAction();
            GetAura()->Variables.Set("procTargetGUID", eventInfo.GetProcTarget()->GetGUID());
            eventInfo.GetActor()->CastSpell(eventInfo.GetActor(), SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC, true);
        }

        void Register() override
        {
            OnEffectProc += AuraEffectProcFn(spell_sha_earthen_rage_passive_AuraScript::HandleEffectProc, EFFECT_0, SPELL_AURA_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new  spell_sha_earthen_rage_passive_AuraScript();
    }
};

// 170377 - Earthen Rage (Proc Aura)
class spell_sha_earthen_rage_proc_aura : public SpellScriptLoader
{
public:
    spell_sha_earthen_rage_proc_aura() : SpellScriptLoader("spell_sha_earthen_rage_proc_aura") { }

    class spell_sha_earthen_rage_proc_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_earthen_rage_proc_aura_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE, SPELL_SHAMAN_EARTHEN_RAGE_PERIODIC, SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE });
        }

        void HandleEffectPeriodic(AuraEffect const* /*aurEff*/)
        {
            PreventDefaultAction();
            if (Aura* aura = GetCaster()->GetAura(SPELL_SHAMAN_EARTHEN_RAGE_PASSIVE))
            {
                ObjectGuid const procTargetGUID = aura->Variables.GetValue<ObjectGuid>("procTargetGUID");
                if (Unit* procTarget = ObjectAccessor::GetUnit(*GetCaster(), procTargetGUID))
                    GetTarget()->CastSpell(procTarget, SPELL_SHAMAN_EARTHEN_RAGE_DAMAGE, true);
            }
        }

        void CalcPeriodic(AuraEffect const* /*aurEff*/, bool& /*isPeriodic*/, int32& amplitude)
        {
            // On retail there have been 1-6 procs randomly distributed over the duration
            amplitude = urand(1000, 4000);
        }

        void Register() override
        {
            DoEffectCalcPeriodic += AuraEffectCalcPeriodicFn(spell_sha_earthen_rage_proc_aura_AuraScript::CalcPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_sha_earthen_rage_proc_aura_AuraScript::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new  spell_sha_earthen_rage_proc_aura_AuraScript();
    }
};

//210643 Totem Mastery
class spell_sha_totem_mastery : public SpellScriptLoader
{
public:
    spell_sha_totem_mastery() : SpellScriptLoader("spell_sha_totem_mastery") { }

    class spell_sha_totem_mastery_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_totem_mastery_SpellScript);

        void HandleSummon()
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            Player* player = caster->ToPlayer();
            if (!player)
                return;

            //Unsummon any Resonance Totem that the player already has. ID : 102392
            std::list<Creature*> totemResoList;
            player->GetCreatureListWithEntryInGrid(totemResoList, 102392, 500.0f);

            for (std::list<Creature*>::iterator i = totemResoList.begin(); i != totemResoList.end(); ++i)
            {
                Unit* owner = (*i)->GetOwner();

                if (owner && owner == player && (*i)->IsSummon())
                    continue;

                i = totemResoList.erase(i);
            }

            if ((int32)totemResoList.size() >= 1)
                totemResoList.back()->ToTempSummon()->UnSummon();

            //Unsummon any Storm Totem that the player already has. ID : 106317
            std::list<Creature*> totemStormList;
            player->GetCreatureListWithEntryInGrid(totemStormList, 106317, 500.0f);

            for (std::list<Creature*>::iterator i = totemStormList.begin(); i != totemStormList.end(); ++i)
            {
                Unit* owner = (*i)->GetOwner();

                if (owner && owner == player && (*i)->IsSummon())
                    continue;

                i = totemStormList.erase(i);
            }

            if ((int32)totemStormList.size() >= 1)
                totemStormList.back()->ToTempSummon()->UnSummon();

            //Unsummon any Ember Totem that the player already has. ID : 106319
            std::list<Creature*> totemEmberList;
            player->GetCreatureListWithEntryInGrid(totemEmberList, 106319, 500.0f);

            for (std::list<Creature*>::iterator i = totemEmberList.begin(); i != totemEmberList.end(); ++i)
            {
                Unit* owner = (*i)->GetOwner();

                if (owner && owner == player && (*i)->IsSummon())
                    continue;

                i = totemEmberList.erase(i);
            }

            if ((int32)totemEmberList.size() >= 1)
                totemEmberList.back()->ToTempSummon()->UnSummon();

            //Unsummon any Tailwind Totem that the player already has. ID : 106321
            std::list<Creature*> totemTailwindList;
            player->GetCreatureListWithEntryInGrid(totemTailwindList, 106321, 500.0f);

            for (std::list<Creature*>::iterator i = totemTailwindList.begin(); i != totemTailwindList.end(); ++i)
            {
                Unit* owner = (*i)->GetOwner();

                if (owner && owner == player && (*i)->IsSummon())
                    continue;

                i = totemTailwindList.erase(i);
            }

            if ((int32)totemTailwindList.size() >= 1)
                totemTailwindList.back()->ToTempSummon()->UnSummon();
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_sha_totem_mastery_SpellScript::HandleSummon);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_totem_mastery_SpellScript();
    }
};


//NPC ID : 97285
//NPC NAME : Wind Rush Totem
struct npc_wind_rush_totem : public ScriptedAI
{
    npc_wind_rush_totem(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->GetScheduler().Schedule(500ms, [this](TaskContext context)
        {
            std::list<Unit*> unitList;
            me->GetFriendlyUnitListInRange(unitList, 10.0f, true);

            for (Unit* target : unitList)
                me->CastSpell(target, SPELL_TOTEM_WIND_RUSH_EFFECT, true);

            context.Repeat();
        });
    }
};

//NPC ID : 100099
//NPC NAME : Voodoo Totem
struct npc_voodoo_totem : public ScriptedAI
{
    npc_voodoo_totem(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->CastSpell(nullptr, SPELL_TOTEM_VOODOO_AT, true);
    }
};

//NPC ID : 61245
//NPC NAME : Lightning Surge Totem
struct npc_lightning_surge_totem : public ScriptedAI
{
    npc_lightning_surge_totem(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->GetScheduler().Schedule(2s, [this](TaskContext /*context*/)
        {
            me->CastSpell(me, SPELL_TOTEM_LIGHTNING_SURGE_EFFECT, true);
        });
    }
};

//NPC ID : 102392
struct npc_resonance_totem : public ScriptedAI
{
    npc_resonance_totem(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->GetScheduler().Schedule(1s, [this](TaskContext context)
        {
            me->CastSpell(me, SPELL_TOTEM_RESONANCE_EFFECT, true);
            context.Repeat();
        });
    }
};

//NPC ID : 97369
struct npc_liquid_magma_totem : public ScriptedAI
{
    npc_liquid_magma_totem(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->GetScheduler().Schedule(15s, [this](TaskContext context)
        {
            me->CastSpell(me, SPELL_TOTEM_LIQUID_MAGMA_EFFECT, true);
            context.Repeat();
        });
    }
};

//NPC ID : 60561
struct npc_earth_grab_totem : public ScriptedAI
{
    npc_earth_grab_totem(Creature* creature) : ScriptedAI(creature) {}

    std::vector<ObjectGuid> alreadyRooted;

    void Reset() override
    {
        me->GetScheduler().Schedule(2s, [this](TaskContext context)
        {
            std::list<Unit*> unitList;
            me->GetAttackableUnitListInRange(unitList, 10.0f);

            for (auto target : unitList)
            {
                if (target->HasAura(SPELL_TOTEM_EARTH_GRAB_ROOT_EFFECT))
                    continue;

                if (std::find(alreadyRooted.begin(), alreadyRooted.end(), target->GetGUID()) == alreadyRooted.end())
                {
                    alreadyRooted.push_back(target->GetGUID());
                    me->CastSpell(target, SPELL_TOTEM_EARTH_GRAB_ROOT_EFFECT, true);
                }
                else
                    me->CastSpell(target, SPELL_TOTEM_EARTH_GRAB_SLOW_EFFECT, true);
            }

            context.Repeat();
        });
    }
};

//NPC ID : 59764
struct npc_healing_tide_totem : public ScriptedAI
{
    npc_healing_tide_totem(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->GetScheduler().Schedule(1900ms, [this](TaskContext context)
        {
            me->CastSpell(me, SPELL_TOTEM_HEALING_TIDE_EFFECT, true);
            context.Repeat();
        });
    }
};

//NPC ID : 106321
struct npc_tailwind_totem : public ScriptedAI
{
    npc_tailwind_totem(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->GetScheduler().Schedule(1s, [this](TaskContext context)
        {
            me->CastSpell(me, SPELL_TOTEM_TAIL_WIND_EFFECT, true);
            context.Repeat();
        });
    }
};

//NPC ID : 106319
struct npc_ember_totem : public ScriptedAI
{
    npc_ember_totem(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->GetScheduler().Schedule(1s, [this](TaskContext context)
        {
            me->CastSpell(me, SPELL_TOTEM_EMBER_EFFECT, true);
            context.Repeat();
        });
    }
};

//NPC ID : 78001
struct npc_cloudburst_totem : public ScriptedAI
{
    npc_cloudburst_totem(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        if (me->GetOwner())
            me->CastSpell(me->GetOwner(), SPELL_TOTEM_CLOUDBURST_EFFECT, true);
    }
};

//100943
struct npc_earthen_shield_totem : public ScriptedAI
{
    npc_earthen_shield_totem(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->CastSpell(me, SPELL_SHAMAN_AT_EARTHEN_SHIELD_TOTEM, true);
    }
};

//AT ID : 5760
//Spell ID : 198839
class at_earthen_shield_totem : public AreaTriggerEntityScript
{
public:
    at_earthen_shield_totem() : AreaTriggerEntityScript("at_earthen_shield_totem") { }

    struct at_earthen_shield_totemAI : AreaTriggerAI
    {
        int32 timeInterval;

        at_earthen_shield_totemAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            timeInterval = 200;
        }

        enum SpellsUsed
        {
            SPELL_SHAMAN_EARTHEN_SHIELD_ABSORB = 201633
        };

        void OnCreate() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            for (auto itr : at->GetInsideUnits())
            {
                Unit* target = ObjectAccessor::GetUnit(*caster, itr);
                if (caster->IsFriendlyTo(target) || target == caster->GetOwner())
                {
                    if (!target->IsTotem())
                        caster->CastSpell(target, SPELL_SHAMAN_EARTHEN_SHIELD_ABSORB, true);
                }
            }
        }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if(unit->IsTotem())
                return;

            if (caster->IsFriendlyTo(unit) || unit == caster->GetOwner())
            {
                caster->CastSpell(unit, SPELL_SHAMAN_EARTHEN_SHIELD_ABSORB, true);
            }
        }

        void OnUnitExit(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (unit->IsTotem())
                return;

            if (unit->HasAura(SPELL_SHAMAN_EARTHEN_SHIELD_ABSORB) && unit->GetAura(SPELL_SHAMAN_EARTHEN_SHIELD_ABSORB)->GetCaster() == caster)
                unit->RemoveAura(SPELL_SHAMAN_EARTHEN_SHIELD_ABSORB);
        }

        void OnRemove() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            for (auto itr : at->GetInsideUnits())
            {
                if (Unit* target = ObjectAccessor::GetUnit(*caster, itr))
                    if (!target->IsTotem())
                        if (target->HasAura(SPELL_SHAMAN_EARTHEN_SHIELD_ABSORB) && target->GetAura(SPELL_SHAMAN_EARTHEN_SHIELD_ABSORB)->GetCaster() == caster)
                            target->RemoveAura(SPELL_SHAMAN_EARTHEN_SHIELD_ABSORB);
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_earthen_shield_totemAI(areatrigger);
    }
};

//201633 - Earthen Shield
class spell_sha_earthen_shield_absorb : public SpellScriptLoader
{
public:
    spell_sha_earthen_shield_absorb() : SpellScriptLoader("spell_sha_earthen_shield_absorb") { }

    class spell_sha_earthen_shield_absorb_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_earthen_shield_absorb_AuraScript);

        void CalcAbsorb(AuraEffect const* /*aurEff*/, int32& amount, bool & /*canBeRecalculated*/)
        {
            if(!GetCaster())
                return;

            amount = GetCaster()->GetHealth();
        }

        void HandleAbsorb(AuraEffect* /*aurEff*/, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            Unit* caster = GetCaster();
            if(!caster || !caster->IsTotem())
                return;

            Unit* owner = caster->GetOwner();
            if(!owner)
                return;

            if(dmgInfo.GetDamage() - owner->GetTotalSpellPowerValue(SPELL_SCHOOL_MASK_ALL, true) > 0)
                absorbAmount = owner->GetTotalSpellPowerValue(SPELL_SCHOOL_MASK_ALL, true);
            else
                absorbAmount = dmgInfo.GetDamage();

            //201657 - The damager
            caster->CastCustomSpell(201657, SPELLVALUE_BASE_POINT0, absorbAmount, caster, TRIGGERED_FULL_MASK);
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sha_earthen_shield_absorb_AuraScript::CalcAbsorb, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_sha_earthen_shield_absorb_AuraScript::HandleAbsorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_earthen_shield_absorb_AuraScript();
    }
};

//104818 - Ancestral Protection Totem
struct npc_ancestral_protection_totem : public ScriptedAI
{
    npc_ancestral_protection_totem(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->CastSpell(me, SPELL_TOTEM_ANCESTRAL_PROTECTION_AT, true);
    }
};


//AT ID : 6336
//Spell ID : 207495
class at_sha_ancestral_protection_totem : public AreaTriggerEntityScript
{
public:
    at_sha_ancestral_protection_totem() : AreaTriggerEntityScript("at_sha_ancestral_protection_totem") { }

    struct at_sha_ancestral_protection_totemAI : AreaTriggerAI
    {
        int32 timeInterval;

        at_sha_ancestral_protection_totemAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        enum SpellsUsed
        {
            SPELL_SHAMAN_ANCESTRAL_PROTECTION_TOTEM_AURA = 207498
        };

        void OnCreate() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;


            for (auto itr : at->GetInsideUnits())
            {
                Unit* target = ObjectAccessor::GetUnit(*caster, itr);
                if (caster->IsFriendlyTo(target) || target == caster->GetOwner())
                {
                    if (!target->IsTotem())
                        caster->CastSpell(target, SPELL_SHAMAN_ANCESTRAL_PROTECTION_TOTEM_AURA, true);
                }
            }
        }

        void OnUnitEnter(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if(caster->IsFriendlyTo(unit) || unit == caster->GetOwner())
            {
                if(unit->IsTotem())
                    return;
                else
                    caster->CastSpell(unit, SPELL_SHAMAN_ANCESTRAL_PROTECTION_TOTEM_AURA, true);
            }
        }

        void OnUnitExit(Unit* unit) override
        {
            Unit* caster = at->GetCaster();

            if (!caster || !unit)
                return;

            if (unit->HasAura(SPELL_SHAMAN_ANCESTRAL_PROTECTION_TOTEM_AURA) && unit->GetAura(SPELL_SHAMAN_ANCESTRAL_PROTECTION_TOTEM_AURA)->GetCaster() == caster)
                unit->RemoveAura(SPELL_SHAMAN_ANCESTRAL_PROTECTION_TOTEM_AURA);
        }

        void OnRemove() override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            for (auto itr : at->GetInsideUnits())
            {
                Unit* target = ObjectAccessor::GetUnit(*caster, itr);
                if (!target->IsTotem())
                    if (target->HasAura(SPELL_SHAMAN_ANCESTRAL_PROTECTION_TOTEM_AURA))
                        target->RemoveAura(SPELL_SHAMAN_ANCESTRAL_PROTECTION_TOTEM_AURA);
            }
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_sha_ancestral_protection_totemAI(areatrigger);
    }
};

//207498 ancestral protection
class spell_sha_ancestral_protection_totem_aura : public SpellScriptLoader
{
public:
    spell_sha_ancestral_protection_totem_aura() : SpellScriptLoader("spell_sha_ancestral_protection_totem_aura") { }

    class spell_sha_ancestral_protection_totem_aura_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_sha_ancestral_protection_totem_aura_AuraScript);

        void CalculateAmount(AuraEffect const* /*auraEffect*/, int32& amount, bool& /*canBeRecalculated*/)
        {
            amount = -1;
        }


        void HandleAfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_DEATH)
                return;

            Unit* totem = GetCaster();
            if(!totem)
                return;

            totem->CastSpell(GetTargetApplication()->GetTarget(), SPELL_TOTEM_TOTEMIC_REVIVAL, true);
            totem->KillSelf();
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_sha_ancestral_protection_totem_aura_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectRemove += AuraEffectRemoveFn(spell_sha_ancestral_protection_totem_aura_AuraScript::HandleAfterRemove, EFFECT_1, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_sha_ancestral_protection_totem_aura_AuraScript();
    }
};

//AT id : 3691
//Spell ID : 61882
class at_sha_earthquake_totem : public AreaTriggerEntityScript
{
public:
    at_sha_earthquake_totem() : AreaTriggerEntityScript("at_sha_earthquake_totem") { }

    struct at_sha_earthquake_totemAI : AreaTriggerAI
    {
        int32 timeInterval;

        enum UsedSpells
        {
            SPELL_SHAMAN_EARTHQUAKE_DAMAGE = 77478,
            SPELL_SHAMAN_EARTHQUAKE_STUN = 77505
        };

        at_sha_earthquake_totemAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger)
        {
            timeInterval = 200;
        }

        void OnUpdate(uint32 p_Time) override
        {
            Unit* caster = at->GetCaster();

            if (!caster)
                return;

            if (!caster->ToPlayer())
                return;

            // Check if we can handle actions
            timeInterval += p_Time;
            if (timeInterval < 1000)
                return;

            if (Creature* tempSumm = caster->SummonCreature(WORLD_TRIGGER, at->GetPosition(), TEMPSUMMON_TIMED_DESPAWN, 200))
            {
                tempSumm->setFaction(caster->getFaction());
                tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                PhasingHandler::InheritPhaseShift(tempSumm, caster);
                tempSumm->CastCustomSpell(SPELL_SHAMAN_EARTHQUAKE_DAMAGE, SPELLVALUE_BASE_POINT0, caster->GetTotalSpellPowerValue(SPELL_SCHOOL_MASK_NORMAL, false) * 0.3, caster, TRIGGERED_FULL_MASK);
            }

            timeInterval -= 1000;
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_sha_earthquake_totemAI(areatrigger);
    }
};

//105427 Skyfury Totem
struct npc_skyfury_totem : public ScriptedAI
{
    npc_skyfury_totem(Creature* creature) : ScriptedAI(creature) {}

    uint32 m_uiBuffTimer;
    int32 m_buffDuration = 15000;
    enum TotemData
    {
        SPELL_TO_CAST = SPELL_TOTEM_SKYFURY_EFFECT,
        RANGE = 40,
        DELAY = 500
    };
    void Reset() override
    {
        m_uiBuffTimer = DELAY;
        ApplyBuff();
    }

    void UpdateAI(uint32 uiDiff) override
    {
        m_buffDuration -= uiDiff;

        if (m_uiBuffTimer <= uiDiff)
            ApplyBuff();
        else
            m_uiBuffTimer -= uiDiff;
    }

    void ApplyBuff()
    {
        m_uiBuffTimer = DELAY;

        if (!me)
            return;

        std::list<Unit*> targets;
        Trinity::AnyFriendlyUnitInObjectRangeCheck check(me, me, RANGE);
        Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(me, targets, check);
        Cell::VisitAllObjects(me, searcher, RANGE);
        for (auto itr : targets)
        {
            if(!itr)
                continue;

            if(!itr->HasAura(SPELL_TOTEM_SKYFURY_EFFECT))
            {
                me->CastSpell(itr, SPELL_TOTEM_SKYFURY_EFFECT, true);
                if (Aura* aura = itr->GetAura(SPELL_TOTEM_SKYFURY_EFFECT))
                    aura->SetDuration(m_buffDuration);
            }
        }
    }
};

//5925
struct npc_grounding_totem : public ScriptedAI
{
    npc_grounding_totem(Creature* creature) : ScriptedAI(creature) {}

    void Reset() override
    {
        me->CastSpell(me, SPELL_TOTEM_GROUDING_TOTEM_EFFECT, true);
    }
};

// 51505 - Lava burst
class spell_sha_lava_burst : public SpellScriptLoader
{
public:
    spell_sha_lava_burst() : SpellScriptLoader("spell_sha_lava_burst") { }

    class spell_sha_lava_burst_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_lava_burst_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_PATH_OF_FLAMES_TALENT))
                return false;
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD))
                return false;
            return true;
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Unit* caster = GetCaster())
                if (Unit* target = GetExplTargetUnit())
                    if (caster->HasAura(SPELL_SHAMAN_PATH_OF_FLAMES_TALENT))
                        caster->CastSpell(target, SPELL_SHAMAN_PATH_OF_FLAMES_SPREAD, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_sha_lava_burst_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_lava_burst_SpellScript();
    }
};

// 210621 - Path of Flames Spread
class spell_sha_path_of_flames_spread : public SpellScriptLoader
{
public:
    spell_sha_path_of_flames_spread() : SpellScriptLoader("spell_sha_path_of_flames_spread") { }

    class spell_sha_path_of_flames_spread_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_path_of_flames_spread_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_SHAMAN_FLAME_SHOCK_MAELSTROM))
                return false;
            return true;
        }

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            targets.remove(GetExplTargetUnit());
            Trinity::Containers::RandomResize(targets, 1);
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            if (Unit* mainTarget = GetExplTargetUnit())
            {
                if (Aura* flameShock = mainTarget->GetAura(SPELL_SHAMAN_FLAME_SHOCK_MAELSTROM, GetCaster()->GetGUID()))
                {
                    if (Aura* newAura = GetCaster()->AddAura(SPELL_SHAMAN_FLAME_SHOCK_MAELSTROM, GetHitUnit()))
                    {
                        newAura->SetDuration(flameShock->GetDuration());
                        newAura->SetMaxDuration(flameShock->GetDuration());
                    }
                }
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sha_path_of_flames_spread_SpellScript::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_sha_path_of_flames_spread_SpellScript::HandleScript, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_path_of_flames_spread_SpellScript();
    }
};

//197995
class spell_sha_wellspring : public SpellScriptLoader
{
public:
    spell_sha_wellspring() : SpellScriptLoader("spell_sha_wellspring") { }

    class spell_sha_wellspring_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sha_wellspring_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();

            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_SHAMAN_WELLSPRING_MISSILE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_sha_wellspring_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sha_wellspring_SpellScript();
    }
};

// Undulation
// 8004 Healing Surge
// 77472 Healing Wave
class spell_sha_undulation: public SpellScript
{
    PrepareSpellScript(spell_sha_undulation);

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (GetCaster()->Variables.IncrementOrProcCounter("spell_sha_undulation", 3))
            GetCaster()->CastSpell(nullptr, SPELL_SHAMAN_UNDULATION_PROC, true);
        else
            GetCaster()->RemoveAurasDueToSpell(SPELL_SHAMAN_UNDULATION_PROC);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_undulation::HandleHitTarget, EFFECT_0, SPELL_EFFECT_HEAL);
    }
};

// 188443 Chain Lightning
class spell_sha_chain_lightning: public SpellScript
{
    PrepareSpellScript(spell_sha_chain_lightning);

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (SpellEffectInfo const* effect = GetSpellInfo()->GetEffect(EFFECT_1))
            GetCaster()->ModifyPower(POWER_MAELSTROM, effect->BasePoints);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_chain_lightning::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

// 215864 Rainfall
class spell_sha_rainfall: public SpellScript
{
    PrepareSpellScript(spell_sha_rainfall);

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (WorldLocation* pos = GetHitDest())
            GetCaster()->SummonCreature(NPC_RAINFALL, *pos);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_sha_rainfall::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 215864 Rainfall
class aura_sha_rainfall : public AuraScript
{
    PrepareAuraScript(aura_sha_rainfall);

    void HandleHealPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* rainfallTrigger = caster->GetSummonedCreatureByEntry(NPC_RAINFALL))
                caster->CastSpell(rainfallTrigger->GetPosition(), SPELL_SHAMAN_RAINFALL_HEAL, true);
    }

    void HandleAfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->UnsummonCreatureByEntry(NPC_RAINFALL);
    }

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        ModDuration(GetEffect(EFFECT_2)->GetBaseAmount() * IN_MILLISECONDS, GetEffect(EFFECT_3)->GetBaseAmount() * IN_MILLISECONDS);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_sha_rainfall::HandleHealPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectRemove += AuraEffectRemoveFn(aura_sha_rainfall::HandleAfterRemove, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectProc += AuraEffectProcFn(aura_sha_rainfall::HandleProc, EFFECT_2, SPELL_AURA_DUMMY);
    }
};

// 73920 Healing Rain
class spell_sha_healing_rain: public SpellScript
{
    PrepareSpellScript(spell_sha_healing_rain);

    void HandleHitTarget(SpellEffIndex /*effIndex*/)
    {
        if (WorldLocation* pos = GetHitDest())
            GetCaster()->SummonCreature(NPC_HEALING_RAIN, *pos);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_sha_healing_rain::HandleHitTarget, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 73920 Healing Rain
class aura_sha_healing_rain : public AuraScript
{
    PrepareAuraScript(aura_sha_healing_rain);

    void HandleHealPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (Unit* caster = GetCaster())
            if (Creature* healingRainTrigger = caster->GetSummonedCreatureByEntry(NPC_HEALING_RAIN))
                caster->CastSpell(healingRainTrigger->GetPosition(), SPELL_SHAMAN_HEALING_RAIN_TICK, true);
    }

    void HandleAfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Unit* caster = GetCaster())
            caster->UnsummonCreatureByEntry(NPC_HEALING_RAIN);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(aura_sha_healing_rain::HandleHealPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
        OnEffectRemove += AuraEffectRemoveFn(aura_sha_healing_rain::HandleAfterRemove, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 188070 Healing Surge
class spell_sha_healing_surge: public SpellScript
{
    PrepareSpellScript(spell_sha_healing_surge);

    void HandleCalcCastTime(int32& castTime)
    {
        int32 requiredMaelstrom = GetEffectInfo(EFFECT_2)->BasePoints;
        if (GetCaster()->GetPower(POWER_MAELSTROM) >= requiredMaelstrom)
        {
            castTime = 0;
            _takenPower = requiredMaelstrom;
        }
    }

    void HandleEnergize(SpellEffIndex /*effIndex*/)
    {
        SetEffectValue(-_takenPower);
    }

    void Register() override
    {
        OnCalcCastTime += SpellOnCalcCastTimeFn(spell_sha_healing_surge::HandleCalcCastTime);
        OnEffectHitTarget += SpellEffectFn(spell_sha_healing_surge::HandleEnergize, EFFECT_1, SPELL_EFFECT_ENERGIZE);
    }
private:
    int32 _takenPower = 0;
};

// 8042 Earth Shock
class spell_sha_earth_shock: public SpellScript
{
    PrepareSpellScript(spell_sha_earth_shock);

    void HandleTakePower(SpellPowerCost& powerCost)
    {
        _takenPower = powerCost.Amount;
    }

    void HandleCalcDamage(SpellEffIndex /*effIndex*/)
    {
        SetHitDamage(CalculatePct(GetHitDamage(), _takenPower));
    }

    void Register() override
    {
        OnTakePower += SpellOnTakePowerFn(spell_sha_earth_shock::HandleTakePower);
        OnEffectHitTarget += SpellEffectFn(spell_sha_earth_shock::HandleCalcDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
private:
    int32 _takenPower = 0;
};

// 198103
class spell_sha_earth_elemental : public SpellScript
{
    PrepareSpellScript(spell_sha_earth_elemental);

    void HandleSummon(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SHAMAN_EARTH_ELEMENTAL_SUMMON, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_earth_elemental::HandleSummon, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 198067
class spell_sha_fire_elemental : public SpellScript
{
    PrepareSpellScript(spell_sha_fire_elemental);

    void HandleSummon(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetHitUnit(), SPELL_SHAMAN_FIRE_ELEMENTAL_SUMMON, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_sha_fire_elemental::HandleSummon, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 187837 - Lightning Bolt
class spell_sha_enhancement_lightning_bolt : public SpellScript
{
    PrepareSpellScript(spell_sha_enhancement_lightning_bolt);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SHAMAN_OVERCHARGE });
    }

    void HandleTakePower(SpellPowerCost& powerCost)
    {
        _maxTakenPower      = 0;
        _maxDamagePercent   = 0;

        if (Aura* overcharge = GetCaster()->GetAura(SPELL_SHAMAN_OVERCHARGE))
        {
            _maxTakenPower      = overcharge->GetSpellEffectInfo(EFFECT_0)->BasePoints;
            _maxDamagePercent   = overcharge->GetSpellEffectInfo(EFFECT_1)->BasePoints;
        }

        _takenPower = powerCost.Amount = std::min(GetCaster()->GetPower(POWER_MAELSTROM), _maxTakenPower);
    }

    void HandleDamage(SpellEffIndex /*effIndex*/)
    {
        if (_maxTakenPower > 0)
        {
            int32 increasedDamagePercent = CalculatePct(_maxDamagePercent, float(_takenPower) / float(_maxTakenPower) * 100.f);
            int32 hitDamage = CalculatePct(GetHitDamage(), 100 + increasedDamagePercent);
            SetHitDamage(hitDamage);
        }
    }

    void Register() override
    {
        OnTakePower += SpellOnTakePowerFn(spell_sha_enhancement_lightning_bolt::HandleTakePower);
        OnEffectHitTarget += SpellEffectFn(spell_sha_enhancement_lightning_bolt::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
    }

private:
    int32 _takenPower;
    int32 _maxTakenPower;
    int32 _maxDamagePercent;
};

// 195255 - Stormlash
class aura_sha_stormlash : public AuraScript
{
    PrepareAuraScript(aura_sha_stormlash);

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_SHAMAN_STORMLASH_BUFF, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(aura_sha_stormlash::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

// 195222 - Stormlash Buff
class aura_sha_stormlash_buff : public AuraScript
{
    PrepareAuraScript(aura_sha_stormlash_buff);

    void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
    {
        eventInfo.GetActor()->CastSpell(eventInfo.GetActionTarget(), SPELL_SHAMAN_STORMLASH_DAMAGE, true);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(aura_sha_stormlash_buff::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
    }
};

// Spell 210797 - Crashing Storm
// AT - 11353
class at_sha_crashing_storm : public AreaTriggerAI
{
public:
    at_sha_crashing_storm(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    void OnCreate() override
    {
        if (Unit* caster = at->GetCaster())
        {
            caster->GetScheduler().Schedule(0ms, SPELL_SHAMAN_CRASHING_STORM_AT, [this](TaskContext context)
            {
                GetContextUnit()->CastSpell(at->GetPosition(), SPELL_SHAMAN_CRASHING_STORM_DAMAGE, true);

                if (context.GetRepeatCounter() < 7)
                    context.Repeat(1s);
            });
        }
    }

    void OnRemove() override
    {
        if (Unit* caster = at->GetCaster())
            caster->GetScheduler().CancelGroup(SPELL_SHAMAN_CRASHING_STORM_AT);
    }
};

// 29264
struct npc_feral_spirit : public ScriptedAI
{
    npc_feral_spirit(Creature* p_Creature) : ScriptedAI(p_Creature) { }

    void DamageDealt(Unit* /*victim*/, uint32& /*damage*/, DamageEffectType /*damageType*/) override
    {
        if (TempSummon* tempSum = me->ToTempSummon())
            if (Unit* owner = tempSum->GetOwner())
                if (owner->HasAura(SPELL_SHAMAN_FERAL_SPIRIT_ENERGIZE_DUMMY))
                    owner->CastSpell(owner, SPELL_SHAMAN_FERAL_SPIRIT_ENERGIZE, true);
    }
};

// Spell 196935 - Voodoo Totem
// AT - 11577
class at_sha_voodoo_totem : public AreaTriggerAI
{
public:
    at_sha_voodoo_totem(AreaTrigger* areaTrigger) : AreaTriggerAI(areaTrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        Unit* caster = at->GetCaster();
        if (!caster || !unit)
            return;

        if (caster->IsValidAttackTarget(unit))
        {
            caster->CastSpell(unit, SPELL_TOTEM_VOODOO_EFFECT, true);
            caster->CastSpell(unit, SPELL_TOTEM_VOODOO_COOLDOWN, true);
        }
    }

    void OnUnitExit(Unit* unit) override
    {
        unit->RemoveAurasDueToSpell(SPELL_TOTEM_VOODOO_EFFECT, at->GetCasterGuid());
    }
};

void AddSC_shaman_spell_scripts()
{
    new at_sha_earthquake_totem();
    new at_sha_ancestral_protection_totem();
    new at_earthen_shield_totem();
    RegisterAuraScript(spell_sha_ancestral_guidance);
    new spell_sha_ancestral_guidance_heal();
    new spell_sha_ancestral_protection_totem_aura();
    new spell_sha_ascendance_water();
    new spell_sha_ascendance_water_heal();
    new spell_sha_bloodlust();
    new spell_sha_chain_heal();
    new spell_sha_cloudburst();
    new spell_sha_cloudburst_effect();
    new spell_sha_crash_lightning();
    new spell_sha_crash_lightning_aura();
    new spell_sha_earth_shield();
    new spell_sha_earthen_shield_absorb();
    new spell_sha_earthen_rage_passive();
    new spell_sha_earthen_rage_proc_aura();
    new spell_sha_earthgrab();
    RegisterAuraScript(aura_sha_earthquake);
    RegisterSpellScript(spell_sha_earthquake_tick);
    RegisterSpellScript(spell_sha_elemental_blast);
    new spell_sha_feral_lunge();
    new spell_sha_feral_spirit();
    new spell_sha_fire_nova();
    new spell_sha_flame_shock_elem();
    RegisterAuraScript(spell_sha_flametongue);
    new spell_sha_fulmination();
    new spell_sha_fury_of_air();
    new spell_sha_glyph_of_healing_wave();
    new spell_sha_glyph_of_lakestrider();
    new spell_sha_glyph_of_shamanistic_rage();
    new spell_sha_healing_stream();
    new spell_sha_healing_stream_totem();
    new spell_sha_healing_stream_totem_heal();
    new spell_sha_heroism();
    new spell_sha_item_lightning_shield();
    new spell_sha_item_lightning_shield_trigger();
    new spell_sha_item_mana_surge();
    new spell_sha_item_t10_elemental_2p_bonus();
    new spell_sha_item_t18_elemental_4p_bonus();
    new spell_sha_lava_burst();
    new spell_sha_lava_lash();
    new spell_sha_lava_lash_spread_flame_shock();
    RegisterAuraScript(spell_sha_lava_surge);
    RegisterSpellScript(spell_sha_lava_surge_proc);
    new spell_sha_lightning_bolt_elem();
    new spell_sha_lightning_shield();
    new spell_sha_liquid_magma_effect();
    RegisterAuraScript(spell_sha_maelstrom_weapon);
    new spell_sha_nature_guardian();
    new spell_sha_path_of_flames_spread();
    new spell_sha_resonance_effect();
    new spell_sha_resurgence();
    new spell_sha_spirit_link();
    new spell_sha_spiritwalkers_grace();
    new spell_sha_stormbringer();
    new spell_sha_thunderstorm();
    RegisterAuraScript(spell_sha_tidal_waves);
    new spell_sha_totem_mastery();
    new spell_sha_wellspring();
    RegisterAuraScript(spell_sha_windfury);
    new spell_shaman_windfury_weapon();
    RegisterSpellScript(spell_sha_undulation);
    RegisterSpellScript(spell_sha_chain_lightning);
    RegisterSpellAndAuraScriptPair(spell_sha_rainfall, aura_sha_rainfall);
    RegisterSpellAndAuraScriptPair(spell_sha_healing_rain, aura_sha_healing_rain);
    RegisterSpellScript(spell_sha_healing_surge);
    RegisterSpellScript(spell_sha_earth_shock);
    RegisterSpellScript(spell_sha_earth_elemental);
    RegisterSpellScript(spell_sha_fire_elemental);
    RegisterSpellScript(spell_sha_enhancement_lightning_bolt);
    RegisterAuraScript(aura_sha_stormlash);
    RegisterAuraScript(aura_sha_stormlash_buff);
    RegisterAreaTriggerAI(at_sha_crashing_storm);
    RegisterCreatureAI(npc_feral_spirit);
    RegisterAreaTriggerAI(at_sha_voodoo_totem);
}

void AddSC_npc_totem_scripts()
{
    RegisterCreatureAI(npc_ancestral_protection_totem);
    RegisterCreatureAI(npc_cloudburst_totem);
    RegisterCreatureAI(npc_earth_grab_totem);
    RegisterCreatureAI(npc_earthen_shield_totem);
    RegisterCreatureAI(npc_ember_totem);
    RegisterCreatureAI(npc_grounding_totem);
    RegisterCreatureAI(npc_healing_tide_totem);
    RegisterCreatureAI(npc_lightning_surge_totem);
    RegisterCreatureAI(npc_liquid_magma_totem);
    RegisterCreatureAI(npc_resonance_totem);
    RegisterCreatureAI(npc_skyfury_totem);
    RegisterCreatureAI(npc_tailwind_totem);
    RegisterCreatureAI(npc_voodoo_totem);
    RegisterCreatureAI(npc_wind_rush_totem);
}
