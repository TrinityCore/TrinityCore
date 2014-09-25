/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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
 * Spells used in holidays/game events that do not fit any other category.
 * Ordered alphabetically using scriptname.
 * Scriptnames in this file should be prefixed with "spell_#holidayname_".
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"

// 45102 Romantic Picnic
enum SpellsPicnic
{
    SPELL_BASKET_CHECK              = 45119, // Holiday - Valentine - Romantic Picnic Near Basket Check
    SPELL_MEAL_PERIODIC             = 45103, // Holiday - Valentine - Romantic Picnic Meal Periodic - effect dummy
    SPELL_MEAL_EAT_VISUAL           = 45120, // Holiday - Valentine - Romantic Picnic Meal Eat Visual
    //SPELL_MEAL_PARTICLE             = 45114, // Holiday - Valentine - Romantic Picnic Meal Particle - unused
    SPELL_DRINK_VISUAL              = 45121, // Holiday - Valentine - Romantic Picnic Drink Visual
    SPELL_ROMANTIC_PICNIC_ACHIEV    = 45123, // Romantic Picnic periodic = 5000
};

class spell_love_is_in_the_air_romantic_picnic : public SpellScriptLoader
{
    public:
        spell_love_is_in_the_air_romantic_picnic() : SpellScriptLoader("spell_love_is_in_the_air_romantic_picnic") { }

        class spell_love_is_in_the_air_romantic_picnic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_love_is_in_the_air_romantic_picnic_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->SetStandState(UNIT_STAND_STATE_SIT);
                target->CastSpell(target, SPELL_MEAL_PERIODIC, false);
            }

            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                // Every 5 seconds
                Unit* target = GetTarget();
                Unit* caster = GetCaster();

                // If our player is no longer sit, remove all auras
                if (target->getStandState() != UNIT_STAND_STATE_SIT)
                {
                    target->RemoveAura(SPELL_ROMANTIC_PICNIC_ACHIEV);
                    target->RemoveAura(GetAura());
                    return;
                }

                target->CastSpell(target, SPELL_BASKET_CHECK, false); // unknown use, it targets Romantic Basket
                target->CastSpell(target, RAND(SPELL_MEAL_EAT_VISUAL, SPELL_DRINK_VISUAL), false);

                bool foundSomeone = false;
                // For nearby players, check if they have the same aura. If so, cast Romantic Picnic (45123)
                // required by achievement and "hearts" visual
                std::list<Player*> playerList;
                Trinity::AnyPlayerInObjectRangeCheck checker(target, INTERACTION_DISTANCE*2);
                Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(target, playerList, checker);
                target->VisitNearbyWorldObject(INTERACTION_DISTANCE*2, searcher);
                for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                {
                    if ((*itr) != target && (*itr)->HasAura(GetId())) // && (*itr)->getStandState() == UNIT_STAND_STATE_SIT)
                    {
                        if (caster)
                        {
                            caster->CastSpell(*itr, SPELL_ROMANTIC_PICNIC_ACHIEV, true);
                            caster->CastSpell(target, SPELL_ROMANTIC_PICNIC_ACHIEV, true);
                        }
                        foundSomeone = true;
                        // break;
                    }
                }

                if (!foundSomeone && target->HasAura(SPELL_ROMANTIC_PICNIC_ACHIEV))
                    target->RemoveAura(SPELL_ROMANTIC_PICNIC_ACHIEV);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_love_is_in_the_air_romantic_picnic_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_love_is_in_the_air_romantic_picnic_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_love_is_in_the_air_romantic_picnic_AuraScript();
        }
};

// 24750 Trick
enum TrickSpells
{
    SPELL_PIRATE_COSTUME_MALE           = 24708,
    SPELL_PIRATE_COSTUME_FEMALE         = 24709,
    SPELL_NINJA_COSTUME_MALE            = 24710,
    SPELL_NINJA_COSTUME_FEMALE          = 24711,
    SPELL_LEPER_GNOME_COSTUME_MALE      = 24712,
    SPELL_LEPER_GNOME_COSTUME_FEMALE    = 24713,
    SPELL_SKELETON_COSTUME              = 24723,
    SPELL_GHOST_COSTUME_MALE            = 24735,
    SPELL_GHOST_COSTUME_FEMALE          = 24736,
    SPELL_TRICK_BUFF                    = 24753,
};

class spell_hallow_end_trick : public SpellScriptLoader
{
    public:
        spell_hallow_end_trick() : SpellScriptLoader("spell_hallow_end_trick") { }

        class spell_hallow_end_trick_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hallow_end_trick_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PIRATE_COSTUME_MALE) || !sSpellMgr->GetSpellInfo(SPELL_PIRATE_COSTUME_FEMALE) || !sSpellMgr->GetSpellInfo(SPELL_NINJA_COSTUME_MALE)
                    || !sSpellMgr->GetSpellInfo(SPELL_NINJA_COSTUME_FEMALE) || !sSpellMgr->GetSpellInfo(SPELL_LEPER_GNOME_COSTUME_MALE) || !sSpellMgr->GetSpellInfo(SPELL_LEPER_GNOME_COSTUME_FEMALE)
                    || !sSpellMgr->GetSpellInfo(SPELL_SKELETON_COSTUME) || !sSpellMgr->GetSpellInfo(SPELL_GHOST_COSTUME_MALE) || !sSpellMgr->GetSpellInfo(SPELL_GHOST_COSTUME_FEMALE) || !sSpellMgr->GetSpellInfo(SPELL_TRICK_BUFF))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Player* target = GetHitPlayer())
                {
                    uint8 gender = target->getGender();
                    uint32 spellId = SPELL_TRICK_BUFF;
                    switch (urand(0, 5))
                    {
                        case 1:
                            spellId = gender ? SPELL_LEPER_GNOME_COSTUME_FEMALE : SPELL_LEPER_GNOME_COSTUME_MALE;
                            break;
                        case 2:
                            spellId = gender ? SPELL_PIRATE_COSTUME_FEMALE : SPELL_PIRATE_COSTUME_MALE;
                            break;
                        case 3:
                            spellId = gender ? SPELL_GHOST_COSTUME_FEMALE : SPELL_GHOST_COSTUME_MALE;
                            break;
                        case 4:
                            spellId = gender ? SPELL_NINJA_COSTUME_FEMALE : SPELL_NINJA_COSTUME_MALE;
                            break;
                        case 5:
                            spellId = SPELL_SKELETON_COSTUME;
                            break;
                        default:
                            break;
                    }

                    caster->CastSpell(target, spellId, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hallow_end_trick_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hallow_end_trick_SpellScript();
        }
};

// 24751 Trick or Treat
enum TrickOrTreatSpells
{
    SPELL_TRICK                 = 24714,
    SPELL_TREAT                 = 24715,
    SPELL_TRICKED_OR_TREATED    = 24755,
    SPELL_TRICKY_TREAT_SPEED    = 42919,
    SPELL_TRICKY_TREAT_TRIGGER  = 42965,
    SPELL_UPSET_TUMMY           = 42966
};

class spell_hallow_end_trick_or_treat : public SpellScriptLoader
{
    public:
        spell_hallow_end_trick_or_treat() : SpellScriptLoader("spell_hallow_end_trick_or_treat") { }

        class spell_hallow_end_trick_or_treat_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hallow_end_trick_or_treat_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_TRICK) || !sSpellMgr->GetSpellInfo(SPELL_TREAT) || !sSpellMgr->GetSpellInfo(SPELL_TRICKED_OR_TREATED))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Player* target = GetHitPlayer())
                {
                    caster->CastSpell(target, roll_chance_i(50) ? SPELL_TRICK : SPELL_TREAT, true);
                    caster->CastSpell(target, SPELL_TRICKED_OR_TREATED, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hallow_end_trick_or_treat_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hallow_end_trick_or_treat_SpellScript();
        }
};

class spell_hallow_end_tricky_treat : public SpellScriptLoader
{
    public:
        spell_hallow_end_tricky_treat() : SpellScriptLoader("spell_hallow_end_tricky_treat") { }

        class spell_hallow_end_tricky_treat_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_hallow_end_tricky_treat_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_TRICKY_TREAT_SPEED))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_TRICKY_TREAT_TRIGGER))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_UPSET_TUMMY))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (caster->HasAura(SPELL_TRICKY_TREAT_TRIGGER) && caster->GetAuraCount(SPELL_TRICKY_TREAT_SPEED) > 3 && roll_chance_i(33))
                    caster->CastSpell(caster, SPELL_UPSET_TUMMY, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_hallow_end_tricky_treat_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_hallow_end_tricky_treat_SpellScript();
        }
};

enum PilgrimsBountyBuffFood
{
    // Pilgrims Bounty Buff Food
    SPELL_WELL_FED_AP_TRIGGER       = 65414,
    SPELL_WELL_FED_ZM_TRIGGER       = 65412,
    SPELL_WELL_FED_HIT_TRIGGER      = 65416,
    SPELL_WELL_FED_HASTE_TRIGGER    = 65410,
    SPELL_WELL_FED_SPIRIT_TRIGGER   = 65415
};

class spell_pilgrims_bounty_buff_food : public SpellScriptLoader
{
    private:
        uint32 const _triggeredSpellId;
    public:
        spell_pilgrims_bounty_buff_food(const char* name, uint32 triggeredSpellId) : SpellScriptLoader(name), _triggeredSpellId(triggeredSpellId) { }

        class spell_pilgrims_bounty_buff_food_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_pilgrims_bounty_buff_food_AuraScript);
        private:
            uint32 const _triggeredSpellId;

        public:
            spell_pilgrims_bounty_buff_food_AuraScript(uint32 triggeredSpellId) : AuraScript(), _triggeredSpellId(triggeredSpellId)
            {
                _handled = false;
            }

            void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                if (_handled)
                    return;

                _handled = true;
                GetTarget()->CastSpell(GetTarget(), _triggeredSpellId, true);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_pilgrims_bounty_buff_food_AuraScript::HandleTriggerSpell, EFFECT_2, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }

            bool _handled;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_pilgrims_bounty_buff_food_AuraScript(_triggeredSpellId);
        }
};

enum Mistletoe
{
    SPELL_CREATE_MISTLETOE          = 26206,
    SPELL_CREATE_HOLLY              = 26207,
    SPELL_CREATE_SNOWFLAKES         = 45036
};

class spell_winter_veil_mistletoe : public SpellScriptLoader
{
    public:
        spell_winter_veil_mistletoe() : SpellScriptLoader("spell_winter_veil_mistletoe") { }

        class spell_winter_veil_mistletoe_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_winter_veil_mistletoe_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_CREATE_MISTLETOE) ||
                    !sSpellMgr->GetSpellInfo(SPELL_CREATE_HOLLY) ||
                    !sSpellMgr->GetSpellInfo(SPELL_CREATE_SNOWFLAKES))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Player* target = GetHitPlayer())
                {
                    uint32 spellId = RAND(SPELL_CREATE_HOLLY, SPELL_CREATE_MISTLETOE, SPELL_CREATE_SNOWFLAKES);
                    GetCaster()->CastSpell(target, spellId, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_winter_veil_mistletoe_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_winter_veil_mistletoe_SpellScript();
        }
};

// 26275 - PX-238 Winter Wondervolt TRAP
enum PX238WinterWondervolt
{
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_1  = 26157,
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_2  = 26272,
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_3  = 26273,
    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_4  = 26274
};

class spell_winter_veil_px_238_winter_wondervolt : public SpellScriptLoader
{
    public:
        spell_winter_veil_px_238_winter_wondervolt() : SpellScriptLoader("spell_winter_veil_px_238_winter_wondervolt") { }

        class spell_winter_veil_px_238_winter_wondervolt_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_winter_veil_px_238_winter_wondervolt_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_1) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_2) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_3) ||
                    !sSpellMgr->GetSpellInfo(SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_4))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                uint32 const spells[4] =
                {
                    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_1,
                    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_2,
                    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_3,
                    SPELL_PX_238_WINTER_WONDERVOLT_TRANSFORM_4
                };

                if (Unit* target = GetHitUnit())
                {
                    for (uint8 i = 0; i < 4; ++i)
                        if (target->HasAura(spells[i]))
                            return;

                    target->CastSpell(target, spells[urand(0, 3)], true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_winter_veil_px_238_winter_wondervolt_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }

        private:

        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_winter_veil_px_238_winter_wondervolt_SpellScript();
        }
};

enum RamBlaBla
{
    SPELL_GIDDYUP                           = 42924,
    SPELL_RENTAL_RACING_RAM                 = 43883,
    SPELL_RENTAL_RACING_RAM_AURA            = 42146,
    SPELL_RAM_LEVEL_NEUTRAL                 = 43310,
    SPELL_RAM_TROT                          = 42992,
    SPELL_RAM_CANTER                        = 42993,
    SPELL_RAM_GALLOP                        = 42994,
    SPELL_RAM_FATIGUE                       = 43052,
    SPELL_EXHAUSTED_RAM                     = 43332,

    // Quest
    SPELL_BREWFEST_QUEST_SPEED_BUNNY_GREEN  = 43345,
    SPELL_BREWFEST_QUEST_SPEED_BUNNY_YELLOW = 43346,
    SPELL_BREWFEST_QUEST_SPEED_BUNNY_RED    = 43347
};

// 42924 - Giddyup!
class spell_brewfest_giddyup : public SpellScriptLoader
{
    public:
        spell_brewfest_giddyup() : SpellScriptLoader("spell_brewfest_giddyup") { }

        class spell_brewfest_giddyup_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_brewfest_giddyup_AuraScript);

            void OnChange(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (!target->HasAura(SPELL_RENTAL_RACING_RAM))
                {
                    target->RemoveAura(GetId());
                    return;
                }

                if (target->HasAura(SPELL_EXHAUSTED_RAM))
                    return;

                switch (GetStackAmount())
                {
                    case 1: // green
                        target->RemoveAura(SPELL_RAM_LEVEL_NEUTRAL);
                        target->RemoveAura(SPELL_RAM_CANTER);
                        target->CastSpell(target, SPELL_RAM_TROT, true);
                        break;
                    case 6: // yellow
                        target->RemoveAura(SPELL_RAM_TROT);
                        target->RemoveAura(SPELL_RAM_GALLOP);
                        target->CastSpell(target, SPELL_RAM_CANTER, true);
                        break;
                    case 11: // red
                        target->RemoveAura(SPELL_RAM_CANTER);
                        target->CastSpell(target, SPELL_RAM_GALLOP, true);
                        break;
                    default:
                        break;
                }

                if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_DEFAULT)
                {
                    target->RemoveAura(SPELL_RAM_TROT);
                    target->CastSpell(target, SPELL_RAM_LEVEL_NEUTRAL, true);
                }
            }

            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                GetTarget()->RemoveAuraFromStack(GetId());
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_brewfest_giddyup_AuraScript::OnChange, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
                OnEffectRemove += AuraEffectRemoveFn(spell_brewfest_giddyup_AuraScript::OnChange, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_CHANGE_AMOUNT_MASK);
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_brewfest_giddyup_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_brewfest_giddyup_AuraScript();
        }
};

// 43310 - Ram Level - Neutral
// 42992 - Ram - Trot
// 42993 - Ram - Canter
// 42994 - Ram - Gallop
class spell_brewfest_ram : public SpellScriptLoader
{
    public:
        spell_brewfest_ram() : SpellScriptLoader("spell_brewfest_ram") { }

        class spell_brewfest_ram_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_brewfest_ram_AuraScript);

            void OnPeriodic(AuraEffect const* aurEff)
            {
                Unit* target = GetTarget();
                if (target->HasAura(SPELL_EXHAUSTED_RAM))
                    return;

                switch (GetId())
                {
                    case SPELL_RAM_LEVEL_NEUTRAL:
                        if (Aura* aura = target->GetAura(SPELL_RAM_FATIGUE))
                            aura->ModStackAmount(-4);
                        break;
                    case SPELL_RAM_TROT: // green
                        if (Aura* aura = target->GetAura(SPELL_RAM_FATIGUE))
                            aura->ModStackAmount(-2);
                        if (aurEff->GetTickNumber() == 4)
                            target->CastSpell(target, SPELL_BREWFEST_QUEST_SPEED_BUNNY_GREEN, true);
                        break;
                    case SPELL_RAM_CANTER:
                        target->CastCustomSpell(SPELL_RAM_FATIGUE, SPELLVALUE_AURA_STACK, 1, target, TRIGGERED_FULL_MASK);
                        if (aurEff->GetTickNumber() == 4)
                            target->CastSpell(target, SPELL_BREWFEST_QUEST_SPEED_BUNNY_YELLOW, true);
                        break;
                    case SPELL_RAM_GALLOP:
                        target->CastCustomSpell(SPELL_RAM_FATIGUE, SPELLVALUE_AURA_STACK, target->HasAura(SPELL_RAM_FATIGUE) ? 4 : 5 /*Hack*/, target, TRIGGERED_FULL_MASK);
                        if (aurEff->GetTickNumber() == 4)
                            target->CastSpell(target, SPELL_BREWFEST_QUEST_SPEED_BUNNY_RED, true);
                        break;
                    default:
                        break;
                }

            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_brewfest_ram_AuraScript::OnPeriodic, EFFECT_1, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_brewfest_ram_AuraScript();
        }
};

// 43052 - Ram Fatigue
class spell_brewfest_ram_fatigue : public SpellScriptLoader
{
    public:
        spell_brewfest_ram_fatigue() : SpellScriptLoader("spell_brewfest_ram_fatigue") { }

        class spell_brewfest_ram_fatigue_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_brewfest_ram_fatigue_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();

                if (GetStackAmount() == 101)
                {
                    target->RemoveAura(SPELL_RAM_LEVEL_NEUTRAL);
                    target->RemoveAura(SPELL_RAM_TROT);
                    target->RemoveAura(SPELL_RAM_CANTER);
                    target->RemoveAura(SPELL_RAM_GALLOP);
                    target->RemoveAura(SPELL_GIDDYUP);

                    target->CastSpell(target, SPELL_EXHAUSTED_RAM, true);
                }
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_brewfest_ram_fatigue_AuraScript::OnApply, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_brewfest_ram_fatigue_AuraScript();
        }
};

// 43450 - Brewfest - apple trap - friendly DND
class spell_brewfest_apple_trap : public SpellScriptLoader
{
    public:
        spell_brewfest_apple_trap() : SpellScriptLoader("spell_brewfest_apple_trap") { }

        class spell_brewfest_apple_trap_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_brewfest_apple_trap_AuraScript);

            void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                GetTarget()->RemoveAura(SPELL_RAM_FATIGUE);
            }

            void Register() override
            {
                OnEffectApply += AuraEffectApplyFn(spell_brewfest_apple_trap_AuraScript::OnApply, EFFECT_0, SPELL_AURA_FORCE_REACTION, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_brewfest_apple_trap_AuraScript();
        }
};

// 43332 - Exhausted Ram
class spell_brewfest_exhausted_ram : public SpellScriptLoader
{
    public:
        spell_brewfest_exhausted_ram() : SpellScriptLoader("spell_brewfest_exhausted_ram") { }

        class spell_brewfest_exhausted_ram_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_brewfest_exhausted_ram_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->CastSpell(target, SPELL_RAM_LEVEL_NEUTRAL, true);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectApplyFn(spell_brewfest_exhausted_ram_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_DECREASE_SPEED, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_brewfest_exhausted_ram_AuraScript();
        }
};

// 43714 - Brewfest - Relay Race - Intro - Force - Player to throw- DND
class spell_brewfest_relay_race_intro_force_player_to_throw : public SpellScriptLoader
{
    public:
        spell_brewfest_relay_race_intro_force_player_to_throw() : SpellScriptLoader("spell_brewfest_relay_race_intro_force_player_to_throw") { }

        class spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript);

            void HandleForceCast(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                // All this spells trigger a spell that requires reagents; if the
                // triggered spell is cast as "triggered", reagents are not consumed
                GetHitUnit()->CastSpell((Unit*)NULL, GetSpellInfo()->Effects[effIndex].TriggerSpell, TriggerCastFlags(TRIGGERED_FULL_MASK & ~TRIGGERED_IGNORE_POWER_AND_REAGENT_COST));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript::HandleForceCast, EFFECT_0, SPELL_EFFECT_FORCE_CAST);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript();
        }
};

// 43876 - Dismount Ram
class spell_brewfest_dismount_ram : public SpellScriptLoader
{
    public:
        spell_brewfest_dismount_ram() : SpellScriptLoader("spell_brewfest_dismount_ram") { }

        class spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->RemoveAura(SPELL_RENTAL_RACING_RAM);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_brewfest_relay_race_intro_force_player_to_throw_SpellScript();
        }
};

void AddSC_holiday_spell_scripts()
{
    // Love is in the Air
    new spell_love_is_in_the_air_romantic_picnic();
    // Hallow's End
    new spell_hallow_end_trick();
    new spell_hallow_end_trick_or_treat();
    new spell_hallow_end_tricky_treat();
    // Pilgrims Bounty
    new spell_pilgrims_bounty_buff_food("spell_gen_slow_roasted_turkey", SPELL_WELL_FED_AP_TRIGGER);
    new spell_pilgrims_bounty_buff_food("spell_gen_cranberry_chutney", SPELL_WELL_FED_ZM_TRIGGER);
    new spell_pilgrims_bounty_buff_food("spell_gen_spice_bread_stuffing", SPELL_WELL_FED_HIT_TRIGGER);
    new spell_pilgrims_bounty_buff_food("spell_gen_pumpkin_pie", SPELL_WELL_FED_SPIRIT_TRIGGER);
    new spell_pilgrims_bounty_buff_food("spell_gen_candied_sweet_potato", SPELL_WELL_FED_HASTE_TRIGGER);
    // Winter Veil
    new spell_winter_veil_mistletoe();
    new spell_winter_veil_px_238_winter_wondervolt();
    // Brewfest
    new spell_brewfest_giddyup();
    new spell_brewfest_ram();
    new spell_brewfest_ram_fatigue();
    new spell_brewfest_apple_trap();
    new spell_brewfest_exhausted_ram();
    new spell_brewfest_relay_race_intro_force_player_to_throw();
    new spell_brewfest_dismount_ram();
}
