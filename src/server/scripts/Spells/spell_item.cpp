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
 * Scripts for spells with SPELLFAMILY_GENERIC spells used by items.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_item_".
 */

#include "Player.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "SkillDiscovery.h"
#include "Battleground.h"

// Generic script for handling item dummy effects which trigger another spell.
class spell_item_trigger_spell : public SpellScriptLoader
{
    private:
        uint32 _triggeredSpellId;

    public:
        spell_item_trigger_spell(const char* name, uint32 triggeredSpellId) : SpellScriptLoader(name), _triggeredSpellId(triggeredSpellId) { }

        class spell_item_trigger_spell_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_trigger_spell_SpellScript);
        private:
            uint32 _triggeredSpellId;

        public:
            spell_item_trigger_spell_SpellScript(uint32 triggeredSpellId) : SpellScript(), _triggeredSpellId(triggeredSpellId) { }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(_triggeredSpellId))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Item* item = GetCastItem())
                    caster->CastSpell(caster, _triggeredSpellId, true, item);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_item_trigger_spell_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_trigger_spell_SpellScript(_triggeredSpellId);
        }
};

enum AegisOfPreservation
{
    SPELL_AEGIS_HEAL   = 23781
};

// 23780 - Aegis of Preservation
class spell_item_aegis_of_preservation : public SpellScriptLoader
{
    public:
        spell_item_aegis_of_preservation() : SpellScriptLoader("spell_item_aegis_of_preservation") { }

        class spell_item_aegis_of_preservation_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_item_aegis_of_preservation_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_AEGIS_HEAL))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_AEGIS_HEAL, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_item_aegis_of_preservation_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_item_aegis_of_preservation_AuraScript();
        }
};

// 26400 - Arcane Shroud
class spell_item_arcane_shroud : public SpellScriptLoader
{
    public:
        spell_item_arcane_shroud() : SpellScriptLoader("spell_item_arcane_shroud") { }

        class spell_item_arcane_shroud_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_item_arcane_shroud_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                int32 diff = GetUnitOwner()->getLevel() - 60;
                if (diff > 0)
                    amount += 2 * diff;
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_item_arcane_shroud_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_THREAT);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_item_arcane_shroud_AuraScript();
        }
};

// 64411 - Blessing of Ancient Kings (Val'anyr, Hammer of Ancient Kings)
enum BlessingOfAncientKings
{
    SPELL_PROTECTION_OF_ANCIENT_KINGS   = 64413
};

class spell_item_blessing_of_ancient_kings : public SpellScriptLoader
{
    public:
        spell_item_blessing_of_ancient_kings() : SpellScriptLoader("spell_item_blessing_of_ancient_kings") { }

        class spell_item_blessing_of_ancient_kings_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_item_blessing_of_ancient_kings_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PROTECTION_OF_ANCIENT_KINGS))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcTarget() != nullptr;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();

                int32 absorb = int32(CalculatePct(eventInfo.GetHealInfo()->GetHeal(), 15.0f));
                if (AuraEffect* protEff = eventInfo.GetProcTarget()->GetAuraEffect(SPELL_PROTECTION_OF_ANCIENT_KINGS, 0, eventInfo.GetActor()->GetGUID()))
                {
                    // The shield can grow to a maximum size of 20,000 damage absorbtion
                    protEff->SetAmount(std::min<int32>(protEff->GetAmount() + absorb, 20000));

                    // Refresh and return to prevent replacing the aura
                    protEff->GetBase()->RefreshDuration();
                }
                else
                    GetTarget()->CastCustomSpell(SPELL_PROTECTION_OF_ANCIENT_KINGS, SPELLVALUE_BASE_POINT0, absorb, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_item_blessing_of_ancient_kings_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_item_blessing_of_ancient_kings_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_item_blessing_of_ancient_kings_AuraScript();
        }
};

// 8342  - Defibrillate (Goblin Jumper Cables) have 33% chance on success
// 22999 - Defibrillate (Goblin Jumper Cables XL) have 50% chance on success
// 54732 - Defibrillate (Gnomish Army Knife) have 67% chance on success
enum Defibrillate
{
    SPELL_GOBLIN_JUMPER_CABLES_FAIL     = 8338,
    SPELL_GOBLIN_JUMPER_CABLES_XL_FAIL  = 23055
};

class spell_item_defibrillate : public SpellScriptLoader
{
    public:
        spell_item_defibrillate(char const* name, uint8 chance, uint32 failSpell = 0) : SpellScriptLoader(name), _chance(chance), _failSpell(failSpell) { }

        class spell_item_defibrillate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_defibrillate_SpellScript);

        public:
            spell_item_defibrillate_SpellScript(uint8 chance, uint32 failSpell) : SpellScript(), _chance(chance), _failSpell(failSpell) { }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (_failSpell && !sSpellMgr->GetSpellInfo(_failSpell))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                if (roll_chance_i(_chance))
                {
                    PreventHitDefaultEffect(effIndex);
                    if (_failSpell)
                        GetCaster()->CastSpell(GetCaster(), _failSpell, true, GetCastItem());
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_defibrillate_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_RESURRECT);
            }

        private:
            uint8 _chance;
            uint32 _failSpell;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_defibrillate_SpellScript(_chance, _failSpell);
        }

    private:
        uint8 _chance;
        uint32 _failSpell;
};

enum DesperateDefense
{
    SPELL_DESPERATE_RAGE    = 33898
};

// 33896 - Desperate Defense
class spell_item_desperate_defense : public SpellScriptLoader
{
    public:
        spell_item_desperate_defense() : SpellScriptLoader("spell_item_desperate_defense") { }

        class spell_item_desperate_defense_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_item_desperate_defense_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_DESPERATE_RAGE))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& /*eventInfo*/)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_DESPERATE_RAGE, true, NULL, aurEff);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_item_desperate_defense_AuraScript::HandleProc, EFFECT_2, SPELL_AURA_PROC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_item_desperate_defense_AuraScript();
        }
};

// http://www.wowhead.com/item=6522 Deviate Fish
// 8063 Deviate Fish
enum DeviateFishSpells
{
    SPELL_SLEEPY            = 8064,
    SPELL_INVIGORATE        = 8065,
    SPELL_SHRINK            = 8066,
    SPELL_PARTY_TIME        = 8067,
    SPELL_HEALTHY_SPIRIT    = 8068,
};

class spell_item_deviate_fish : public SpellScriptLoader
{
    public:
        spell_item_deviate_fish() : SpellScriptLoader("spell_item_deviate_fish") { }

        class spell_item_deviate_fish_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_deviate_fish_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                for (uint32 spellId = SPELL_SLEEPY; spellId <= SPELL_HEALTHY_SPIRIT; ++spellId)
                    if (!sSpellMgr->GetSpellInfo(spellId))
                        return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                uint32 spellId = urand(SPELL_SLEEPY, SPELL_HEALTHY_SPIRIT);
                caster->CastSpell(caster, spellId, true, NULL);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_item_deviate_fish_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_deviate_fish_SpellScript();
        }
};

// 71610, 71641 - Echoes of Light (Althor's Abacus)
class spell_item_echoes_of_light : public SpellScriptLoader
{
    public:
        spell_item_echoes_of_light() : SpellScriptLoader("spell_item_echoes_of_light") { }

        class spell_item_echoes_of_light_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_echoes_of_light_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                if (targets.size() < 2)
                    return;

                targets.sort(Trinity::HealthPctOrderPred());

                WorldObject* target = targets.front();
                targets.clear();
                targets.push_back(target);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_item_echoes_of_light_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ALLY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_echoes_of_light_SpellScript();
        }
};

// 7434 - Fate Rune of Unsurpassed Vigor
enum FateRuneOfUnsurpassedVigor
{
    SPELL_UNSURPASSED_VIGOR = 25733
};

class spell_item_fate_rune_of_unsurpassed_vigor : public SpellScriptLoader
{
    public:
        spell_item_fate_rune_of_unsurpassed_vigor() : SpellScriptLoader("spell_item_fate_rune_of_unsurpassed_vigor") { }

        class spell_item_fate_rune_of_unsurpassed_vigor_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_item_fate_rune_of_unsurpassed_vigor_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_UNSURPASSED_VIGOR))
                    return false;
                return true;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& /*eventInfo*/)
            {
                GetTarget()->CastSpell(GetTarget(), SPELL_UNSURPASSED_VIGOR, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_item_fate_rune_of_unsurpassed_vigor_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_item_fate_rune_of_unsurpassed_vigor_AuraScript();
        }
};

// http://www.wowhead.com/item=47499 Flask of the North
// 67019 Flask of the North
enum FlaskOfTheNorthSpells
{
    SPELL_FLASK_OF_THE_NORTH_SP = 67016,
    SPELL_FLASK_OF_THE_NORTH_AP = 67017,
    SPELL_FLASK_OF_THE_NORTH_STR = 67018,
};

class spell_item_flask_of_the_north : public SpellScriptLoader
{
    public:
        spell_item_flask_of_the_north() : SpellScriptLoader("spell_item_flask_of_the_north") { }

        class spell_item_flask_of_the_north_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_flask_of_the_north_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_FLASK_OF_THE_NORTH_SP) || !sSpellMgr->GetSpellInfo(SPELL_FLASK_OF_THE_NORTH_AP) || !sSpellMgr->GetSpellInfo(SPELL_FLASK_OF_THE_NORTH_STR))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                std::vector<uint32> possibleSpells;
                switch (caster->getClass())
                {
                    case CLASS_WARLOCK:
                    case CLASS_MAGE:
                    case CLASS_PRIEST:
                        possibleSpells.push_back(SPELL_FLASK_OF_THE_NORTH_SP);
                        break;
                    case CLASS_DEATH_KNIGHT:
                    case CLASS_WARRIOR:
                        possibleSpells.push_back(SPELL_FLASK_OF_THE_NORTH_STR);
                        break;
                    case CLASS_ROGUE:
                    case CLASS_HUNTER:
                        possibleSpells.push_back(SPELL_FLASK_OF_THE_NORTH_AP);
                        break;
                    case CLASS_DRUID:
                    case CLASS_PALADIN:
                        possibleSpells.push_back(SPELL_FLASK_OF_THE_NORTH_SP);
                        possibleSpells.push_back(SPELL_FLASK_OF_THE_NORTH_STR);
                        break;
                    case CLASS_SHAMAN:
                        possibleSpells.push_back(SPELL_FLASK_OF_THE_NORTH_SP);
                        possibleSpells.push_back(SPELL_FLASK_OF_THE_NORTH_AP);
                        break;
                }

                caster->CastSpell(caster, possibleSpells[irand(0, (possibleSpells.size() - 1))], true, NULL);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_item_flask_of_the_north_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_flask_of_the_north_SpellScript();
        }
};

// http://www.wowhead.com/item=10645 Gnomish Death Ray
// 13280 Gnomish Death Ray
enum GnomishDeathRay
{
    SPELL_GNOMISH_DEATH_RAY_SELF = 13493,
    SPELL_GNOMISH_DEATH_RAY_TARGET = 13279,
};

class spell_item_gnomish_death_ray : public SpellScriptLoader
{
    public:
        spell_item_gnomish_death_ray() : SpellScriptLoader("spell_item_gnomish_death_ray") { }

        class spell_item_gnomish_death_ray_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_gnomish_death_ray_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_GNOMISH_DEATH_RAY_SELF) || !sSpellMgr->GetSpellInfo(SPELL_GNOMISH_DEATH_RAY_TARGET))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    if (urand(0, 99) < 15)
                        caster->CastSpell(caster, SPELL_GNOMISH_DEATH_RAY_SELF, true, NULL);    // failure
                    else
                        caster->CastSpell(target, SPELL_GNOMISH_DEATH_RAY_TARGET, true, NULL);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_gnomish_death_ray_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_gnomish_death_ray_SpellScript();
        }
};

// http://www.wowhead.com/item=27388 Mr. Pinchy
// 33060 Make a Wish
enum MakeAWish
{
    SPELL_MR_PINCHYS_BLESSING       = 33053,
    SPELL_SUMMON_MIGHTY_MR_PINCHY   = 33057,
    SPELL_SUMMON_FURIOUS_MR_PINCHY  = 33059,
    SPELL_TINY_MAGICAL_CRAWDAD      = 33062,
    SPELL_MR_PINCHYS_GIFT           = 33064,
};

class spell_item_make_a_wish : public SpellScriptLoader
{
    public:
        spell_item_make_a_wish() : SpellScriptLoader("spell_item_make_a_wish") { }

        class spell_item_make_a_wish_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_make_a_wish_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MR_PINCHYS_BLESSING) || !sSpellMgr->GetSpellInfo(SPELL_SUMMON_MIGHTY_MR_PINCHY) || !sSpellMgr->GetSpellInfo(SPELL_SUMMON_FURIOUS_MR_PINCHY) || !sSpellMgr->GetSpellInfo(SPELL_TINY_MAGICAL_CRAWDAD) || !sSpellMgr->GetSpellInfo(SPELL_MR_PINCHYS_GIFT))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                uint32 spellId = SPELL_MR_PINCHYS_GIFT;
                switch (urand(1, 5))
                {
                    case 1: spellId = SPELL_MR_PINCHYS_BLESSING; break;
                    case 2: spellId = SPELL_SUMMON_MIGHTY_MR_PINCHY; break;
                    case 3: spellId = SPELL_SUMMON_FURIOUS_MR_PINCHY; break;
                    case 4: spellId = SPELL_TINY_MAGICAL_CRAWDAD; break;
                }
                caster->CastSpell(caster, spellId, true, NULL);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_item_make_a_wish_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_make_a_wish_SpellScript();
        }
};

// http://www.wowhead.com/item=32686 Mingo's Fortune Giblets
// 40802 Mingo's Fortune Generator
class spell_item_mingos_fortune_generator : public SpellScriptLoader
{
    public:
        spell_item_mingos_fortune_generator() : SpellScriptLoader("spell_item_mingos_fortune_generator") { }

        class spell_item_mingos_fortune_generator_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_mingos_fortune_generator_SpellScript);

            void HandleDummy(SpellEffIndex effIndex)
            {
                // Selecting one from Bloodstained Fortune item
                uint32 newitemid;
                switch (urand(1, 20))
                {
                    case 1:  newitemid = 32688; break;
                    case 2:  newitemid = 32689; break;
                    case 3:  newitemid = 32690; break;
                    case 4:  newitemid = 32691; break;
                    case 5:  newitemid = 32692; break;
                    case 6:  newitemid = 32693; break;
                    case 7:  newitemid = 32700; break;
                    case 8:  newitemid = 32701; break;
                    case 9:  newitemid = 32702; break;
                    case 10: newitemid = 32703; break;
                    case 11: newitemid = 32704; break;
                    case 12: newitemid = 32705; break;
                    case 13: newitemid = 32706; break;
                    case 14: newitemid = 32707; break;
                    case 15: newitemid = 32708; break;
                    case 16: newitemid = 32709; break;
                    case 17: newitemid = 32710; break;
                    case 18: newitemid = 32711; break;
                    case 19: newitemid = 32712; break;
                    case 20: newitemid = 32713; break;
                    default:
                        return;
                }

                CreateItem(effIndex, newitemid);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_item_mingos_fortune_generator_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_mingos_fortune_generator_SpellScript();
        }
};

// 71875, 71877 - Item - Black Bruise: Necrotic Touch Proc
enum NecroticTouch
{
    SPELL_ITEM_NECROTIC_TOUCH_PROC  = 71879
};

class spell_item_necrotic_touch : public SpellScriptLoader
{
    public:
        spell_item_necrotic_touch() : SpellScriptLoader("spell_item_necrotic_touch") { }

        class spell_item_necrotic_touch_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_item_necrotic_touch_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_ITEM_NECROTIC_TOUCH_PROC))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                return eventInfo.GetProcTarget() && eventInfo.GetProcTarget()->IsAlive();
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                int32 bp = CalculatePct(int32(eventInfo.GetDamageInfo()->GetDamage()), aurEff->GetAmount());
                GetTarget()->CastCustomSpell(SPELL_ITEM_NECROTIC_TOUCH_PROC, SPELLVALUE_BASE_POINT0, bp, eventInfo.GetProcTarget(), true, NULL, aurEff);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_item_necrotic_touch_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_item_necrotic_touch_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_item_necrotic_touch_AuraScript();
        }
};

// http://www.wowhead.com/item=10720 Gnomish Net-o-Matic Projector
// 13120 Net-o-Matic
enum NetOMaticSpells
{
    SPELL_NET_O_MATIC_TRIGGERED1 = 16566,
    SPELL_NET_O_MATIC_TRIGGERED2 = 13119,
    SPELL_NET_O_MATIC_TRIGGERED3 = 13099,
};

class spell_item_net_o_matic : public SpellScriptLoader
{
    public:
        spell_item_net_o_matic() : SpellScriptLoader("spell_item_net_o_matic") { }

        class spell_item_net_o_matic_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_net_o_matic_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_NET_O_MATIC_TRIGGERED1) || !sSpellMgr->GetSpellInfo(SPELL_NET_O_MATIC_TRIGGERED2) || !sSpellMgr->GetSpellInfo(SPELL_NET_O_MATIC_TRIGGERED3))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                {
                    uint32 spellId = SPELL_NET_O_MATIC_TRIGGERED3;
                    uint32 roll = urand(0, 99);
                    if (roll < 2)                            // 2% for 30 sec self root (off-like chance unknown)
                        spellId = SPELL_NET_O_MATIC_TRIGGERED1;
                    else if (roll < 4)                       // 2% for 20 sec root, charge to target (off-like chance unknown)
                        spellId = SPELL_NET_O_MATIC_TRIGGERED2;

                    GetCaster()->CastSpell(target, spellId, true, NULL);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_net_o_matic_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_net_o_matic_SpellScript();
        }
};

// http://www.wowhead.com/item=8529 Noggenfogger Elixir
// 16589 Noggenfogger Elixir
enum NoggenfoggerElixirSpells
{
    SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED1 = 16595,
    SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED2 = 16593,
    SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED3 = 16591,
};

class spell_item_noggenfogger_elixir : public SpellScriptLoader
{
    public:
        spell_item_noggenfogger_elixir() : SpellScriptLoader("spell_item_noggenfogger_elixir") { }

        class spell_item_noggenfogger_elixir_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_noggenfogger_elixir_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED1) || !sSpellMgr->GetSpellInfo(SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED2) || !sSpellMgr->GetSpellInfo(SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED3))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                uint32 spellId = SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED3;
                switch (urand(1, 3))
                {
                    case 1: spellId = SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED1; break;
                    case 2: spellId = SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED2; break;
                }

                caster->CastSpell(caster, spellId, true, NULL);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_item_noggenfogger_elixir_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_noggenfogger_elixir_SpellScript();
        }
};

// 17512 - Piccolo of the Flaming Fire
class spell_item_piccolo_of_the_flaming_fire : public SpellScriptLoader
{
    public:
        spell_item_piccolo_of_the_flaming_fire() : SpellScriptLoader("spell_item_piccolo_of_the_flaming_fire") { }

        class spell_item_piccolo_of_the_flaming_fire_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_piccolo_of_the_flaming_fire_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Player* target = GetHitPlayer())
                    target->HandleEmoteCommand(EMOTE_STATE_DANCE);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_piccolo_of_the_flaming_fire_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_piccolo_of_the_flaming_fire_SpellScript();
        }
};

// http://www.wowhead.com/item=6657 Savory Deviate Delight
// 8213 Savory Deviate Delight
enum SavoryDeviateDelight
{
    SPELL_FLIP_OUT_MALE     = 8219,
    SPELL_FLIP_OUT_FEMALE   = 8220,
    SPELL_YAAARRRR_MALE     = 8221,
    SPELL_YAAARRRR_FEMALE   = 8222,
};

class spell_item_savory_deviate_delight : public SpellScriptLoader
{
    public:
        spell_item_savory_deviate_delight() : SpellScriptLoader("spell_item_savory_deviate_delight") { }

        class spell_item_savory_deviate_delight_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_savory_deviate_delight_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                for (uint32 spellId = SPELL_FLIP_OUT_MALE; spellId <= SPELL_YAAARRRR_FEMALE; ++spellId)
                    if (!sSpellMgr->GetSpellInfo(spellId))
                        return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                uint32 spellId = 0;
                switch (urand(1, 2))
                {
                    // Flip Out - ninja
                    case 1: spellId = (caster->getGender() == GENDER_MALE ? SPELL_FLIP_OUT_MALE : SPELL_FLIP_OUT_FEMALE); break;
                    // Yaaarrrr - pirate
                    case 2: spellId = (caster->getGender() == GENDER_MALE ? SPELL_YAAARRRR_MALE : SPELL_YAAARRRR_FEMALE); break;
                }
                caster->CastSpell(caster, spellId, true, NULL);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_item_savory_deviate_delight_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_savory_deviate_delight_SpellScript();
        }
};

// 48129 - Scroll of Recall
// 60320 - Scroll of Recall II
// 60321 - Scroll of Recall III
enum ScrollOfRecall
{
    SPELL_SCROLL_OF_RECALL_I                = 48129,
    SPELL_SCROLL_OF_RECALL_II               = 60320,
    SPELL_SCROLL_OF_RECALL_III              = 60321,
    SPELL_LOST                              = 60444,
    SPELL_SCROLL_OF_RECALL_FAIL_ALLIANCE_1  = 60323,
    SPELL_SCROLL_OF_RECALL_FAIL_HORDE_1     = 60328,
};

class spell_item_scroll_of_recall : public SpellScriptLoader
{
    public:
        spell_item_scroll_of_recall() : SpellScriptLoader("spell_item_scroll_of_recall") { }

        class spell_item_scroll_of_recall_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_scroll_of_recall_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                Unit* caster = GetCaster();
                uint8 maxSafeLevel = 0;
                switch (GetSpellInfo()->Id)
                {
                    case SPELL_SCROLL_OF_RECALL_I:  // Scroll of Recall
                        maxSafeLevel = 40;
                        break;
                    case SPELL_SCROLL_OF_RECALL_II:  // Scroll of Recall II
                        maxSafeLevel = 70;
                        break;
                    case SPELL_SCROLL_OF_RECALL_III:  // Scroll of Recal III
                        maxSafeLevel = 80;
                        break;
                    default:
                        break;
                }

                if (caster->getLevel() > maxSafeLevel)
                {
                    caster->CastSpell(caster, SPELL_LOST, true);

                    // ALLIANCE from 60323 to 60330 - HORDE from 60328 to 60335
                    uint32 spellId = SPELL_SCROLL_OF_RECALL_FAIL_ALLIANCE_1;
                    if (GetCaster()->ToPlayer()->GetTeam() == HORDE)
                        spellId = SPELL_SCROLL_OF_RECALL_FAIL_HORDE_1;

                    GetCaster()->CastSpell(GetCaster(), spellId + urand(0, 7), true);

                    PreventHitDefaultEffect(effIndex);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_scroll_of_recall_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_TELEPORT_UNITS);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_scroll_of_recall_SpellScript();
        }
};

// 71169 - Shadow's Fate (Shadowmourne questline)
enum ShadowsFate
{
    SPELL_SOUL_FEAST        = 71203,
    NPC_SINDRAGOSA          = 36853
};

class spell_item_unsated_craving : public SpellScriptLoader
{
    public:
        spell_item_unsated_craving() : SpellScriptLoader("spell_item_unsated_craving") { }

        class spell_item_unsated_craving_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_item_unsated_craving_AuraScript);

            bool CheckProc(ProcEventInfo& procInfo)
            {
                Unit* caster = procInfo.GetActor();
                if (!caster || caster->GetTypeId() != TYPEID_PLAYER)
                    return false;

                Unit* target = procInfo.GetActionTarget();
                if (!target || target->GetTypeId() != TYPEID_UNIT || target->IsCritter() || (target->GetEntry() != NPC_SINDRAGOSA && target->IsSummon()))
                    return false;

                return true;
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_item_unsated_craving_AuraScript::CheckProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_item_unsated_craving_AuraScript();
        }
};

class spell_item_shadows_fate : public SpellScriptLoader
{
    public:
        spell_item_shadows_fate() : SpellScriptLoader("spell_item_shadows_fate") { }

        class spell_item_shadows_fate_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_item_shadows_fate_AuraScript);

            void HandleProc(ProcEventInfo& procInfo)
            {
                Unit* caster = procInfo.GetActor();
                Unit* target = GetCaster();
                if (!caster || !target)
                    return;

                caster->CastSpell(target, SPELL_SOUL_FEAST, TRIGGERED_FULL_MASK);
            }

            void Register() override
            {
                OnProc += AuraProcFn(spell_item_shadows_fate_AuraScript::HandleProc);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_item_shadows_fate_AuraScript();
        }
};

enum Shadowmourne
{
    SPELL_SHADOWMOURNE_CHAOS_BANE_DAMAGE    = 71904,
    SPELL_SHADOWMOURNE_SOUL_FRAGMENT        = 71905,
    SPELL_SHADOWMOURNE_VISUAL_LOW           = 72521,
    SPELL_SHADOWMOURNE_VISUAL_HIGH          = 72523,
    SPELL_SHADOWMOURNE_CHAOS_BANE_BUFF      = 73422,
};

// 71903 - Item - Shadowmourne Legendary
class spell_item_shadowmourne : public SpellScriptLoader
{
    public:
        spell_item_shadowmourne() : SpellScriptLoader("spell_item_shadowmourne") { }

        class spell_item_shadowmourne_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_item_shadowmourne_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHADOWMOURNE_CHAOS_BANE_DAMAGE))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHADOWMOURNE_SOUL_FRAGMENT))
                    return false;
                if (!sSpellMgr->GetSpellInfo(SPELL_SHADOWMOURNE_CHAOS_BANE_BUFF))
                    return false;
                return true;
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                if (GetTarget()->HasAura(SPELL_SHADOWMOURNE_CHAOS_BANE_BUFF)) // cant collect shards while under effect of Chaos Bane buff
                    return false;
                return eventInfo.GetProcTarget() && eventInfo.GetProcTarget()->IsAlive();
            }

            void HandleProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(GetTarget(), SPELL_SHADOWMOURNE_SOUL_FRAGMENT, true, NULL, aurEff);

                // this can't be handled in AuraScript of SoulFragments because we need to know victim
                if (Aura* soulFragments = GetTarget()->GetAura(SPELL_SHADOWMOURNE_SOUL_FRAGMENT))
                {
                    if (soulFragments->GetStackAmount() >= 10)
                    {
                        GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_SHADOWMOURNE_CHAOS_BANE_DAMAGE, true, NULL, aurEff);
                        soulFragments->Remove();
                    }
                }
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_item_shadowmourne_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_item_shadowmourne_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_item_shadowmourne_AuraScript();
        }
};

// 71905 - Soul Fragment
class spell_item_shadowmourne_soul_fragment : public SpellScriptLoader
{
    public:
        spell_item_shadowmourne_soul_fragment() : SpellScriptLoader("spell_item_shadowmourne_soul_fragment") { }

        class spell_item_shadowmourne_soul_fragment_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_item_shadowmourne_soul_fragment_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SHADOWMOURNE_VISUAL_LOW) || !sSpellMgr->GetSpellInfo(SPELL_SHADOWMOURNE_VISUAL_HIGH) || !sSpellMgr->GetSpellInfo(SPELL_SHADOWMOURNE_CHAOS_BANE_BUFF))
                    return false;
                return true;
            }

            void OnStackChange(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                switch (GetStackAmount())
                {
                    case 1:
                        target->CastSpell(target, SPELL_SHADOWMOURNE_VISUAL_LOW, true);
                        break;
                    case 6:
                        target->RemoveAurasDueToSpell(SPELL_SHADOWMOURNE_VISUAL_LOW);
                        target->CastSpell(target, SPELL_SHADOWMOURNE_VISUAL_HIGH, true);
                        break;
                    case 10:
                        target->RemoveAurasDueToSpell(SPELL_SHADOWMOURNE_VISUAL_HIGH);
                        target->CastSpell(target, SPELL_SHADOWMOURNE_CHAOS_BANE_BUFF, true);
                        break;
                    default:
                        break;
                }
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                target->RemoveAurasDueToSpell(SPELL_SHADOWMOURNE_VISUAL_LOW);
                target->RemoveAurasDueToSpell(SPELL_SHADOWMOURNE_VISUAL_HIGH);
            }

            void Register() override
            {
                AfterEffectApply += AuraEffectApplyFn(spell_item_shadowmourne_soul_fragment_AuraScript::OnStackChange, EFFECT_0, SPELL_AURA_MOD_STAT, AuraEffectHandleModes(AURA_EFFECT_HANDLE_REAL | AURA_EFFECT_HANDLE_REAPPLY));
                AfterEffectRemove += AuraEffectRemoveFn(spell_item_shadowmourne_soul_fragment_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_STAT, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_item_shadowmourne_soul_fragment_AuraScript();
        }
};

// http://www.wowhead.com/item=7734 Six Demon Bag
// 14537 Six Demon Bag
enum SixDemonBagSpells
{
    SPELL_FROSTBOLT                 = 11538,
    SPELL_POLYMORPH                 = 14621,
    SPELL_SUMMON_FELHOUND_MINION    = 14642,
    SPELL_FIREBALL                  = 15662,
    SPELL_CHAIN_LIGHTNING           = 21179,
    SPELL_ENVELOPING_WINDS          = 25189,
};

class spell_item_six_demon_bag : public SpellScriptLoader
{
    public:
        spell_item_six_demon_bag() : SpellScriptLoader("spell_item_six_demon_bag") { }

        class spell_item_six_demon_bag_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_six_demon_bag_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_FROSTBOLT) || !sSpellMgr->GetSpellInfo(SPELL_POLYMORPH) || !sSpellMgr->GetSpellInfo(SPELL_SUMMON_FELHOUND_MINION) || !sSpellMgr->GetSpellInfo(SPELL_FIREBALL) || !sSpellMgr->GetSpellInfo(SPELL_CHAIN_LIGHTNING) || !sSpellMgr->GetSpellInfo(SPELL_ENVELOPING_WINDS))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    uint32 spellId = 0;
                    uint32 rand = urand(0, 99);
                    if (rand < 25)                      // Fireball (25% chance)
                        spellId = SPELL_FIREBALL;
                    else if (rand < 50)                 // Frostball (25% chance)
                        spellId = SPELL_FROSTBOLT;
                    else if (rand < 70)                 // Chain Lighting (20% chance)
                        spellId = SPELL_CHAIN_LIGHTNING;
                    else if (rand < 80)                 // Polymorph (10% chance)
                    {
                        spellId = SPELL_POLYMORPH;
                        if (urand(0, 100) <= 30)        // 30% chance to self-cast
                            target = caster;
                    }
                    else if (rand < 95)                 // Enveloping Winds (15% chance)
                        spellId = SPELL_ENVELOPING_WINDS;
                    else                                // Summon Felhund minion (5% chance)
                    {
                        spellId = SPELL_SUMMON_FELHOUND_MINION;
                        target = caster;
                    }

                    caster->CastSpell(target, spellId, true, GetCastItem());
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_six_demon_bag_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_six_demon_bag_SpellScript();
        }
};

// 28862 - The Eye of Diminution
class spell_item_the_eye_of_diminution : public SpellScriptLoader
{
    public:
        spell_item_the_eye_of_diminution() : SpellScriptLoader("spell_item_the_eye_of_diminution") { }

        class spell_item_the_eye_of_diminution_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_item_the_eye_of_diminution_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                int32 diff = GetUnitOwner()->getLevel() - 60;
                if (diff > 0)
                    amount += diff;
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_item_the_eye_of_diminution_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_MOD_THREAT);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_item_the_eye_of_diminution_AuraScript();
        }
};

// http://www.wowhead.com/item=44012 Underbelly Elixir
// 59640 Underbelly Elixir
enum UnderbellyElixirSpells
{
    SPELL_UNDERBELLY_ELIXIR_TRIGGERED1 = 59645,
    SPELL_UNDERBELLY_ELIXIR_TRIGGERED2 = 59831,
    SPELL_UNDERBELLY_ELIXIR_TRIGGERED3 = 59843,
};

class spell_item_underbelly_elixir : public SpellScriptLoader
{
    public:
        spell_item_underbelly_elixir() : SpellScriptLoader("spell_item_underbelly_elixir") { }

        class spell_item_underbelly_elixir_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_underbelly_elixir_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }
            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_UNDERBELLY_ELIXIR_TRIGGERED1) || !sSpellMgr->GetSpellInfo(SPELL_UNDERBELLY_ELIXIR_TRIGGERED2) || !sSpellMgr->GetSpellInfo(SPELL_UNDERBELLY_ELIXIR_TRIGGERED3))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                uint32 spellId = SPELL_UNDERBELLY_ELIXIR_TRIGGERED3;
                switch (urand(1, 3))
                {
                    case 1: spellId = SPELL_UNDERBELLY_ELIXIR_TRIGGERED1; break;
                    case 2: spellId = SPELL_UNDERBELLY_ELIXIR_TRIGGERED2; break;
                }
                caster->CastSpell(caster, spellId, true, NULL);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_item_underbelly_elixir_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_underbelly_elixir_SpellScript();
        }
};

enum AirRifleSpells
{
    SPELL_AIR_RIFLE_HOLD_VISUAL = 65582,
    SPELL_AIR_RIFLE_SHOOT       = 67532,
    SPELL_AIR_RIFLE_SHOOT_SELF  = 65577,
};

class spell_item_red_rider_air_rifle : public SpellScriptLoader
{
    public:
        spell_item_red_rider_air_rifle() : SpellScriptLoader("spell_item_red_rider_air_rifle") { }

        class spell_item_red_rider_air_rifle_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_red_rider_air_rifle_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_AIR_RIFLE_HOLD_VISUAL) || !sSpellMgr->GetSpellInfo(SPELL_AIR_RIFLE_SHOOT) || !sSpellMgr->GetSpellInfo(SPELL_AIR_RIFLE_SHOOT_SELF))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                Unit* caster = GetCaster();
                if (Unit* target = GetHitUnit())
                {
                    caster->CastSpell(caster, SPELL_AIR_RIFLE_HOLD_VISUAL, true);
                    // needed because this spell shares GCD with its triggered spells (which must not be cast with triggered flag)
                    if (Player* player = caster->ToPlayer())
                        player->GetGlobalCooldownMgr().CancelGlobalCooldown(GetSpellInfo());
                    if (urand(0, 4))
                        caster->CastSpell(target, SPELL_AIR_RIFLE_SHOOT, false);
                    else
                        caster->CastSpell(caster, SPELL_AIR_RIFLE_SHOOT_SELF, false);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_red_rider_air_rifle_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_red_rider_air_rifle_SpellScript();
        }
};

enum GenericData
{
    SPELL_ARCANITE_DRAGONLING           = 19804,
    SPELL_BATTLE_CHICKEN                = 13166,
    SPELL_MECHANICAL_DRAGONLING         = 4073,
    SPELL_MITHRIL_MECHANICAL_DRAGONLING = 12749,
};

enum CreateHeartCandy
{
    ITEM_HEART_CANDY_1 = 21818,
    ITEM_HEART_CANDY_2 = 21817,
    ITEM_HEART_CANDY_3 = 21821,
    ITEM_HEART_CANDY_4 = 21819,
    ITEM_HEART_CANDY_5 = 21816,
    ITEM_HEART_CANDY_6 = 21823,
    ITEM_HEART_CANDY_7 = 21822,
    ITEM_HEART_CANDY_8 = 21820,
};

class spell_item_create_heart_candy : public SpellScriptLoader
{
    public:
        spell_item_create_heart_candy() : SpellScriptLoader("spell_item_create_heart_candy") { }

        class spell_item_create_heart_candy_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_create_heart_candy_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Player* target = GetHitPlayer())
                {
                    static const uint32 items[] = {ITEM_HEART_CANDY_1, ITEM_HEART_CANDY_2, ITEM_HEART_CANDY_3, ITEM_HEART_CANDY_4, ITEM_HEART_CANDY_5, ITEM_HEART_CANDY_6, ITEM_HEART_CANDY_7, ITEM_HEART_CANDY_8};
                    target->AddItem(items[urand(0, 7)], 1);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_create_heart_candy_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_create_heart_candy_SpellScript();
        }
};

class spell_item_book_of_glyph_mastery : public SpellScriptLoader
{
    public:
        spell_item_book_of_glyph_mastery() : SpellScriptLoader("spell_item_book_of_glyph_mastery") { }

        class spell_item_book_of_glyph_mastery_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_book_of_glyph_mastery_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            SpellCastResult CheckRequirement()
            {
                if (HasDiscoveredAllSpells(GetSpellInfo()->Id, GetCaster()->ToPlayer()))
                {
                    SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_LEARNED_EVERYTHING);
                    return SPELL_FAILED_CUSTOM_ERROR;
                }

                return SPELL_CAST_OK;
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Player* caster = GetCaster()->ToPlayer();
                uint32 spellId = GetSpellInfo()->Id;

                // learn random explicit discovery recipe (if any)
                if (uint32 discoveredSpellId = GetExplicitDiscoverySpell(spellId, caster))
                    caster->LearnSpell(discoveredSpellId, false);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_item_book_of_glyph_mastery_SpellScript::CheckRequirement);
                OnEffectHitTarget += SpellEffectFn(spell_item_book_of_glyph_mastery_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_book_of_glyph_mastery_SpellScript();
        }
};

enum GiftOfTheHarvester
{
    NPC_GHOUL   = 28845,
    MAX_GHOULS  = 5,
};

class spell_item_gift_of_the_harvester : public SpellScriptLoader
{
    public:
        spell_item_gift_of_the_harvester() : SpellScriptLoader("spell_item_gift_of_the_harvester") { }

        class spell_item_gift_of_the_harvester_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_gift_of_the_harvester_SpellScript);

            SpellCastResult CheckRequirement()
            {
                std::list<Creature*> ghouls;
                GetCaster()->GetAllMinionsByEntry(ghouls, NPC_GHOUL);
                if (ghouls.size() >= MAX_GHOULS)
                {
                    SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_TOO_MANY_GHOULS);
                    return SPELL_FAILED_CUSTOM_ERROR;
                }

                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_item_gift_of_the_harvester_SpellScript::CheckRequirement);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_gift_of_the_harvester_SpellScript();
        }
};

enum Sinkholes
{
    NPC_SOUTH_SINKHOLE      = 25664,
    NPC_NORTHEAST_SINKHOLE  = 25665,
    NPC_NORTHWEST_SINKHOLE  = 25666,
};

class spell_item_map_of_the_geyser_fields : public SpellScriptLoader
{
    public:
        spell_item_map_of_the_geyser_fields() : SpellScriptLoader("spell_item_map_of_the_geyser_fields") { }

        class spell_item_map_of_the_geyser_fields_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_map_of_the_geyser_fields_SpellScript);

            SpellCastResult CheckSinkholes()
            {
                Unit* caster = GetCaster();
                if (caster->FindNearestCreature(NPC_SOUTH_SINKHOLE, 30.0f, true) ||
                    caster->FindNearestCreature(NPC_NORTHEAST_SINKHOLE, 30.0f, true) ||
                    caster->FindNearestCreature(NPC_NORTHWEST_SINKHOLE, 30.0f, true))
                    return SPELL_CAST_OK;

                SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_SINKHOLE);
                return SPELL_FAILED_CUSTOM_ERROR;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_item_map_of_the_geyser_fields_SpellScript::CheckSinkholes);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_map_of_the_geyser_fields_SpellScript();
        }
};

enum VanquishedClutchesSpells
{
    SPELL_CRUSHER       = 64982,
    SPELL_CONSTRICTOR   = 64983,
    SPELL_CORRUPTOR     = 64984,
};

class spell_item_vanquished_clutches : public SpellScriptLoader
{
    public:
        spell_item_vanquished_clutches() : SpellScriptLoader("spell_item_vanquished_clutches") { }

        class spell_item_vanquished_clutches_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_vanquished_clutches_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_CRUSHER) || !sSpellMgr->GetSpellInfo(SPELL_CONSTRICTOR) || !sSpellMgr->GetSpellInfo(SPELL_CORRUPTOR))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                uint32 spellId = RAND(SPELL_CRUSHER, SPELL_CONSTRICTOR, SPELL_CORRUPTOR);
                Unit* caster = GetCaster();
                caster->CastSpell(caster, spellId, true);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_item_vanquished_clutches_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_vanquished_clutches_SpellScript();
        }
};

enum AshbringerSounds
{
    SOUND_ASHBRINGER_1  = 8906,                             // "I was pure once"
    SOUND_ASHBRINGER_2  = 8907,                             // "Fought for righteousness"
    SOUND_ASHBRINGER_3  = 8908,                             // "I was once called Ashbringer"
    SOUND_ASHBRINGER_4  = 8920,                             // "Betrayed by my order"
    SOUND_ASHBRINGER_5  = 8921,                             // "Destroyed by Kel'Thuzad"
    SOUND_ASHBRINGER_6  = 8922,                             // "Made to serve"
    SOUND_ASHBRINGER_7  = 8923,                             // "My son watched me die"
    SOUND_ASHBRINGER_8  = 8924,                             // "Crusades fed his rage"
    SOUND_ASHBRINGER_9  = 8925,                             // "Truth is unknown to him"
    SOUND_ASHBRINGER_10 = 8926,                             // "Scarlet Crusade  is pure no longer"
    SOUND_ASHBRINGER_11 = 8927,                             // "Balnazzar's crusade corrupted my son"
    SOUND_ASHBRINGER_12 = 8928,                             // "Kill them all!"
};

class spell_item_ashbringer : public SpellScriptLoader
{
    public:
        spell_item_ashbringer() : SpellScriptLoader("spell_item_ashbringer") { }

        class spell_item_ashbringer_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_ashbringer_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void OnDummyEffect(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                Player* player = GetCaster()->ToPlayer();
                uint32 sound_id = RAND( SOUND_ASHBRINGER_1, SOUND_ASHBRINGER_2, SOUND_ASHBRINGER_3, SOUND_ASHBRINGER_4, SOUND_ASHBRINGER_5, SOUND_ASHBRINGER_6,
                                SOUND_ASHBRINGER_7, SOUND_ASHBRINGER_8, SOUND_ASHBRINGER_9, SOUND_ASHBRINGER_10, SOUND_ASHBRINGER_11, SOUND_ASHBRINGER_12 );

                // Ashbringers effect (spellID 28441) retriggers every 5 seconds, with a chance of making it say one of the above 12 sounds
                if (urand(0, 60) < 1)
                    player->PlayDirectSound(sound_id, player);
            }

            void Register() override
            {
                OnEffectHit += SpellEffectFn(spell_item_ashbringer_SpellScript::OnDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_ashbringer_SpellScript();
        }
};

enum MagicEater
{
    SPELL_WILD_MAGIC                             = 58891,
    SPELL_WELL_FED_1                             = 57288,
    SPELL_WELL_FED_2                             = 57139,
    SPELL_WELL_FED_3                             = 57111,
    SPELL_WELL_FED_4                             = 57286,
    SPELL_WELL_FED_5                             = 57291,
};

class spell_magic_eater_food : public SpellScriptLoader
{
    public:
        spell_magic_eater_food() : SpellScriptLoader("spell_magic_eater_food") { }

        class spell_magic_eater_food_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_magic_eater_food_AuraScript);

            void HandleTriggerSpell(AuraEffect const* /*aurEff*/)
            {
                PreventDefaultAction();
                Unit* target = GetTarget();
                switch (urand(0, 5))
                {
                    case 0:
                        target->CastSpell(target, SPELL_WILD_MAGIC, true);
                        break;
                    case 1:
                        target->CastSpell(target, SPELL_WELL_FED_1, true);
                        break;
                    case 2:
                        target->CastSpell(target, SPELL_WELL_FED_2, true);
                        break;
                    case 3:
                        target->CastSpell(target, SPELL_WELL_FED_3, true);
                        break;
                    case 4:
                        target->CastSpell(target, SPELL_WELL_FED_4, true);
                        break;
                    case 5:
                        target->CastSpell(target, SPELL_WELL_FED_5, true);
                        break;
                }
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_magic_eater_food_AuraScript::HandleTriggerSpell, EFFECT_1, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_magic_eater_food_AuraScript();
        }
};

class spell_item_shimmering_vessel : public SpellScriptLoader
{
    public:
        spell_item_shimmering_vessel() : SpellScriptLoader("spell_item_shimmering_vessel") { }

        class spell_item_shimmering_vessel_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_shimmering_vessel_SpellScript);

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                if (Creature* target = GetHitCreature())
                    target->setDeathState(JUST_RESPAWNED);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_shimmering_vessel_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_shimmering_vessel_SpellScript();
        }
};

enum PurifyHelboarMeat
{
    SPELL_SUMMON_PURIFIED_HELBOAR_MEAT      = 29277,
    SPELL_SUMMON_TOXIC_HELBOAR_MEAT         = 29278,
};

class spell_item_purify_helboar_meat : public SpellScriptLoader
{
    public:
        spell_item_purify_helboar_meat() : SpellScriptLoader("spell_item_purify_helboar_meat") { }

        class spell_item_purify_helboar_meat_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_purify_helboar_meat_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SUMMON_PURIFIED_HELBOAR_MEAT) ||  !sSpellMgr->GetSpellInfo(SPELL_SUMMON_TOXIC_HELBOAR_MEAT))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Unit* caster = GetCaster();
                caster->CastSpell(caster, roll_chance_i(50) ? SPELL_SUMMON_PURIFIED_HELBOAR_MEAT : SPELL_SUMMON_TOXIC_HELBOAR_MEAT, true, NULL);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_purify_helboar_meat_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_purify_helboar_meat_SpellScript();
        }
};

enum CrystalPrison
{
    OBJECT_IMPRISONED_DOOMGUARD     = 179644,
};

class spell_item_crystal_prison_dummy_dnd : public SpellScriptLoader
{
    public:
        spell_item_crystal_prison_dummy_dnd() : SpellScriptLoader("spell_item_crystal_prison_dummy_dnd") { }

        class spell_item_crystal_prison_dummy_dnd_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_crystal_prison_dummy_dnd_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sObjectMgr->GetGameObjectTemplate(OBJECT_IMPRISONED_DOOMGUARD))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                if (Creature* target = GetHitCreature())
                    if (target->isDead() && !target->IsPet())
                    {
                        GetCaster()->SummonGameObject(OBJECT_IMPRISONED_DOOMGUARD, target->GetPositionX(), target->GetPositionY(), target->GetPositionZ(), target->GetOrientation(), 0, 0, 0, 0, uint32(target->GetRespawnTime()-time(NULL)));
                        target->DespawnOrUnsummon();
                    }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_crystal_prison_dummy_dnd_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_crystal_prison_dummy_dnd_SpellScript();
        }
};

enum ReindeerTransformation
{
    SPELL_FLYING_REINDEER_310                   = 44827,
    SPELL_FLYING_REINDEER_280                   = 44825,
    SPELL_FLYING_REINDEER_60                    = 44824,
    SPELL_REINDEER_100                          = 25859,
    SPELL_REINDEER_60                           = 25858,
};

class spell_item_reindeer_transformation : public SpellScriptLoader
{
    public:
        spell_item_reindeer_transformation() : SpellScriptLoader("spell_item_reindeer_transformation") { }

        class spell_item_reindeer_transformation_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_reindeer_transformation_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_FLYING_REINDEER_310) || !sSpellMgr->GetSpellInfo(SPELL_FLYING_REINDEER_280)
                    || !sSpellMgr->GetSpellInfo(SPELL_FLYING_REINDEER_60) || !sSpellMgr->GetSpellInfo(SPELL_REINDEER_100)
                    || !sSpellMgr->GetSpellInfo(SPELL_REINDEER_60))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Unit* caster = GetCaster();
                if (caster->HasAuraType(SPELL_AURA_MOUNTED))
                {
                    float flyspeed = caster->GetSpeedRate(MOVE_FLIGHT);
                    float speed = caster->GetSpeedRate(MOVE_RUN);

                    caster->RemoveAurasByType(SPELL_AURA_MOUNTED);
                    //5 different spells used depending on mounted speed and if mount can fly or not

                    if (flyspeed >= 4.1f)
                        // Flying Reindeer
                        caster->CastSpell(caster, SPELL_FLYING_REINDEER_310, true); //310% flying Reindeer
                    else if (flyspeed >= 3.8f)
                        // Flying Reindeer
                        caster->CastSpell(caster, SPELL_FLYING_REINDEER_280, true); //280% flying Reindeer
                    else if (flyspeed >= 1.6f)
                        // Flying Reindeer
                        caster->CastSpell(caster, SPELL_FLYING_REINDEER_60, true); //60% flying Reindeer
                    else if (speed >= 2.0f)
                        // Reindeer
                        caster->CastSpell(caster, SPELL_REINDEER_100, true); //100% ground Reindeer
                    else
                        // Reindeer
                        caster->CastSpell(caster, SPELL_REINDEER_60, true); //60% ground Reindeer
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_reindeer_transformation_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_item_reindeer_transformation_SpellScript();
    }
};

enum NighInvulnerability
{
    SPELL_NIGH_INVULNERABILITY                  = 30456,
    SPELL_COMPLETE_VULNERABILITY                = 30457,
};

class spell_item_nigh_invulnerability : public SpellScriptLoader
{
    public:
        spell_item_nigh_invulnerability() : SpellScriptLoader("spell_item_nigh_invulnerability") { }

        class spell_item_nigh_invulnerability_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_nigh_invulnerability_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_NIGH_INVULNERABILITY) || !sSpellMgr->GetSpellInfo(SPELL_COMPLETE_VULNERABILITY))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Unit* caster = GetCaster();
                if (Item* castItem = GetCastItem())
                {
                    if (roll_chance_i(86))                  // Nigh-Invulnerability   - success
                        caster->CastSpell(caster, SPELL_NIGH_INVULNERABILITY, true, castItem);
                    else                                    // Complete Vulnerability - backfire in 14% casts
                        caster->CastSpell(caster, SPELL_COMPLETE_VULNERABILITY, true, castItem);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_nigh_invulnerability_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_nigh_invulnerability_SpellScript();
        }
};

enum Poultryzer
{
    SPELL_POULTRYIZER_SUCCESS    = 30501,
    SPELL_POULTRYIZER_BACKFIRE   = 30504,
};

class spell_item_poultryizer : public SpellScriptLoader
{
    public:
        spell_item_poultryizer() : SpellScriptLoader("spell_item_poultryizer") { }

        class spell_item_poultryizer_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_poultryizer_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_POULTRYIZER_SUCCESS) || !sSpellMgr->GetSpellInfo(SPELL_POULTRYIZER_BACKFIRE))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                if (GetCastItem() && GetHitUnit())
                    GetCaster()->CastSpell(GetHitUnit(), roll_chance_i(80) ? SPELL_POULTRYIZER_SUCCESS : SPELL_POULTRYIZER_BACKFIRE, true, GetCastItem());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_poultryizer_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_poultryizer_SpellScript();
        }
};

enum SocretharsStone
{
    SPELL_SOCRETHAR_TO_SEAT     = 35743,
    SPELL_SOCRETHAR_FROM_SEAT   = 35744,
};

class spell_item_socrethars_stone : public SpellScriptLoader
{
    public:
        spell_item_socrethars_stone() : SpellScriptLoader("spell_item_socrethars_stone") { }

        class spell_item_socrethars_stone_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_socrethars_stone_SpellScript);

            bool Load() override
            {
                return (GetCaster()->GetAreaId() == 3900 || GetCaster()->GetAreaId() == 3742);
            }
            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_SOCRETHAR_TO_SEAT) || !sSpellMgr->GetSpellInfo(SPELL_SOCRETHAR_FROM_SEAT))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Unit* caster = GetCaster();
                switch (caster->GetAreaId())
                {
                    case 3900:
                        caster->CastSpell(caster, SPELL_SOCRETHAR_TO_SEAT, true);
                        break;
                    case 3742:
                        caster->CastSpell(caster, SPELL_SOCRETHAR_FROM_SEAT, true);
                        break;
                    default:
                        return;
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_socrethars_stone_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_socrethars_stone_SpellScript();
        }
};

enum DemonBroiledSurprise
{
    QUEST_SUPER_HOT_STEW                    = 11379,
    SPELL_CREATE_DEMON_BROILED_SURPRISE     = 43753,
    NPC_ABYSSAL_FLAMEBRINGER                = 19973,
};

class spell_item_demon_broiled_surprise : public SpellScriptLoader
{
    public:
        spell_item_demon_broiled_surprise() : SpellScriptLoader("spell_item_demon_broiled_surprise") { }

        class spell_item_demon_broiled_surprise_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_demon_broiled_surprise_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_CREATE_DEMON_BROILED_SURPRISE) || !sObjectMgr->GetCreatureTemplate(NPC_ABYSSAL_FLAMEBRINGER) || !sObjectMgr->GetQuestTemplate(QUEST_SUPER_HOT_STEW))
                    return false;
                return true;
            }

            bool Load() override
            {
               return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Unit* player = GetCaster();
                player->CastSpell(player, SPELL_CREATE_DEMON_BROILED_SURPRISE, false);
            }

            SpellCastResult CheckRequirement()
            {
                Player* player = GetCaster()->ToPlayer();
                if (player->GetQuestStatus(QUEST_SUPER_HOT_STEW) != QUEST_STATUS_INCOMPLETE)
                    return SPELL_FAILED_CANT_DO_THAT_RIGHT_NOW;

                if (Creature* creature = player->FindNearestCreature(NPC_ABYSSAL_FLAMEBRINGER, 10, false))
                    if (creature->isDead())
                        return SPELL_CAST_OK;
                return SPELL_FAILED_NOT_HERE;
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_demon_broiled_surprise_SpellScript::HandleDummy, EFFECT_1, SPELL_EFFECT_DUMMY);
                OnCheckCast += SpellCheckCastFn(spell_item_demon_broiled_surprise_SpellScript::CheckRequirement);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_demon_broiled_surprise_SpellScript();
        }
};

enum CompleteRaptorCapture
{
    SPELL_RAPTOR_CAPTURE_CREDIT     = 42337,
};

class spell_item_complete_raptor_capture : public SpellScriptLoader
{
    public:
        spell_item_complete_raptor_capture() : SpellScriptLoader("spell_item_complete_raptor_capture") { }

        class spell_item_complete_raptor_capture_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_complete_raptor_capture_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_RAPTOR_CAPTURE_CREDIT))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Unit* caster = GetCaster();
                if (GetHitCreature())
                {
                    GetHitCreature()->DespawnOrUnsummon();

                    //cast spell Raptor Capture Credit
                    caster->CastSpell(caster, SPELL_RAPTOR_CAPTURE_CREDIT, true, NULL);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_complete_raptor_capture_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_complete_raptor_capture_SpellScript();
        }
};

enum ImpaleLeviroth
{
    NPC_LEVIROTH                = 26452,
    SPELL_LEVIROTH_SELF_IMPALE  = 49882
};

class spell_item_impale_leviroth : public SpellScriptLoader
{
    public:
        spell_item_impale_leviroth() : SpellScriptLoader("spell_item_impale_leviroth") { }

        class spell_item_impale_leviroth_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_impale_leviroth_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sObjectMgr->GetCreatureTemplate(NPC_LEVIROTH))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Creature* target = GetHitCreature())
                    if (target->GetEntry() == NPC_LEVIROTH && !target->HealthBelowPct(95))
                    {
                        target->CastSpell(target, SPELL_LEVIROTH_SELF_IMPALE, true);
                        target->ResetPlayerDamageReq();
                    }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_impale_leviroth_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_impale_leviroth_SpellScript();
        }
};

enum BrewfestMountTransformation
{
    SPELL_MOUNT_RAM_100                         = 43900,
    SPELL_MOUNT_RAM_60                          = 43899,
    SPELL_MOUNT_KODO_100                        = 49379,
    SPELL_MOUNT_KODO_60                         = 49378,
    SPELL_BREWFEST_MOUNT_TRANSFORM              = 49357,
    SPELL_BREWFEST_MOUNT_TRANSFORM_REVERSE      = 52845,
};

class spell_item_brewfest_mount_transformation : public SpellScriptLoader
{
    public:
        spell_item_brewfest_mount_transformation() : SpellScriptLoader("spell_item_brewfest_mount_transformation") { }

        class spell_item_brewfest_mount_transformation_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_brewfest_mount_transformation_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_MOUNT_RAM_100) || !sSpellMgr->GetSpellInfo(SPELL_MOUNT_RAM_60) || !sSpellMgr->GetSpellInfo(SPELL_MOUNT_KODO_100) || !sSpellMgr->GetSpellInfo(SPELL_MOUNT_KODO_60))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Player* caster = GetCaster()->ToPlayer();
                if (caster->HasAuraType(SPELL_AURA_MOUNTED))
                {
                    caster->RemoveAurasByType(SPELL_AURA_MOUNTED);
                    uint32 spell_id;

                    switch (GetSpellInfo()->Id)
                    {
                        case SPELL_BREWFEST_MOUNT_TRANSFORM:
                            if (caster->GetSpeedRate(MOVE_RUN) >= 2.0f)
                                spell_id = caster->GetTeam() == ALLIANCE ? SPELL_MOUNT_RAM_100 : SPELL_MOUNT_KODO_100;
                            else
                                spell_id = caster->GetTeam() == ALLIANCE ? SPELL_MOUNT_RAM_60 : SPELL_MOUNT_KODO_60;
                            break;
                        case SPELL_BREWFEST_MOUNT_TRANSFORM_REVERSE:
                            if (caster->GetSpeedRate(MOVE_RUN) >= 2.0f)
                                spell_id = caster->GetTeam() == HORDE ? SPELL_MOUNT_RAM_100 : SPELL_MOUNT_KODO_100;
                            else
                                spell_id = caster->GetTeam() == HORDE ? SPELL_MOUNT_RAM_60 : SPELL_MOUNT_KODO_60;
                            break;
                        default:
                            return;
                    }
                    caster->CastSpell(caster, spell_id, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_brewfest_mount_transformation_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_brewfest_mount_transformation_SpellScript();
        }
};

enum NitroBoots
{
    SPELL_NITRO_BOOTS_SUCCESS       = 54861,
    SPELL_NITRO_BOOTS_BACKFIRE      = 46014,
};

class spell_item_nitro_boots : public SpellScriptLoader
{
    public:
        spell_item_nitro_boots() : SpellScriptLoader("spell_item_nitro_boots") { }

        class spell_item_nitro_boots_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_nitro_boots_SpellScript);

            bool Load() override
            {
                if (!GetCastItem())
                    return false;
                return true;
            }

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_NITRO_BOOTS_SUCCESS) || !sSpellMgr->GetSpellInfo(SPELL_NITRO_BOOTS_BACKFIRE))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Unit* caster = GetCaster();
                bool success = caster->GetMap()->IsDungeon() || roll_chance_i(95);
                caster->CastSpell(caster, success ? SPELL_NITRO_BOOTS_SUCCESS : SPELL_NITRO_BOOTS_BACKFIRE, true, GetCastItem());
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_nitro_boots_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_nitro_boots_SpellScript();
        }
};

enum TeachLanguage
{
    SPELL_LEARN_GNOMISH_BINARY      = 50242,
    SPELL_LEARN_GOBLIN_BINARY       = 50246,
};

class spell_item_teach_language : public SpellScriptLoader
{
    public:
        spell_item_teach_language() : SpellScriptLoader("spell_item_teach_language") { }

        class spell_item_teach_language_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_teach_language_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_LEARN_GNOMISH_BINARY) || !sSpellMgr->GetSpellInfo(SPELL_LEARN_GOBLIN_BINARY))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Player* caster = GetCaster()->ToPlayer();

                if (roll_chance_i(34))
                    caster->CastSpell(caster, caster->GetTeam() == ALLIANCE ? SPELL_LEARN_GNOMISH_BINARY : SPELL_LEARN_GOBLIN_BINARY, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_teach_language_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_teach_language_SpellScript();
        }
};

enum RocketBoots
{
    SPELL_ROCKET_BOOTS_PROC      = 30452,
};

class spell_item_rocket_boots : public SpellScriptLoader
{
    public:
        spell_item_rocket_boots() : SpellScriptLoader("spell_item_rocket_boots") { }

        class spell_item_rocket_boots_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_rocket_boots_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_ROCKET_BOOTS_PROC))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Player* caster = GetCaster()->ToPlayer();
                if (Battleground* bg = caster->GetBattleground())
                    bg->EventPlayerDroppedFlag(caster);

                caster->RemoveSpellCooldown(SPELL_ROCKET_BOOTS_PROC);
                caster->CastSpell(caster, SPELL_ROCKET_BOOTS_PROC, true, NULL);
            }

            SpellCastResult CheckCast()
            {
                if (GetCaster()->IsInWater())
                    return SPELL_FAILED_ONLY_ABOVEWATER;
                return SPELL_CAST_OK;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_item_rocket_boots_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_item_rocket_boots_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_rocket_boots_SpellScript();
        }
};

enum PygmyOil
{
    SPELL_PYGMY_OIL_PYGMY_AURA      = 53806,
    SPELL_PYGMY_OIL_SMALLER_AURA    = 53805,
};

class spell_item_pygmy_oil : public SpellScriptLoader
{
    public:
        spell_item_pygmy_oil() : SpellScriptLoader("spell_item_pygmy_oil") { }

        class spell_item_pygmy_oil_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_pygmy_oil_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_PYGMY_OIL_PYGMY_AURA) || !sSpellMgr->GetSpellInfo(SPELL_PYGMY_OIL_SMALLER_AURA))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Unit* caster = GetCaster();
                if (Aura* aura = caster->GetAura(SPELL_PYGMY_OIL_PYGMY_AURA))
                    aura->RefreshDuration();
                else
                {
                    aura = caster->GetAura(SPELL_PYGMY_OIL_SMALLER_AURA);
                    if (!aura || aura->GetStackAmount() < 5 || !roll_chance_i(50))
                         caster->CastSpell(caster, SPELL_PYGMY_OIL_SMALLER_AURA, true);
                    else
                    {
                        aura->Remove();
                        caster->CastSpell(caster, SPELL_PYGMY_OIL_PYGMY_AURA, true);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_pygmy_oil_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_pygmy_oil_SpellScript();
        }
};

class spell_item_unusual_compass : public SpellScriptLoader
{
    public:
        spell_item_unusual_compass() : SpellScriptLoader("spell_item_unusual_compass") { }

        class spell_item_unusual_compass_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_unusual_compass_SpellScript);

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Unit* caster = GetCaster();
                caster->SetFacingTo(frand(0.0f, 2.0f * float(M_PI)));
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_unusual_compass_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_unusual_compass_SpellScript();
        }
};

enum ChickenCover
{
    SPELL_CHICKEN_NET               = 51959,
    SPELL_CAPTURE_CHICKEN_ESCAPE    = 51037,
    QUEST_CHICKEN_PARTY             = 12702,
    QUEST_FLOWN_THE_COOP            = 12532,
};

class spell_item_chicken_cover : public SpellScriptLoader
{
    public:
        spell_item_chicken_cover() : SpellScriptLoader("spell_item_chicken_cover") { }

        class spell_item_chicken_cover_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_chicken_cover_SpellScript);

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_PLAYER;
            }

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_CHICKEN_NET) || !sSpellMgr->GetSpellInfo(SPELL_CAPTURE_CHICKEN_ESCAPE) || !sObjectMgr->GetQuestTemplate(QUEST_CHICKEN_PARTY) || !sObjectMgr->GetQuestTemplate(QUEST_FLOWN_THE_COOP))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /* effIndex */)
            {
                Player* caster = GetCaster()->ToPlayer();
                if (Unit* target = GetHitUnit())
                {
                    if (!target->HasAura(SPELL_CHICKEN_NET) && (caster->GetQuestStatus(QUEST_CHICKEN_PARTY) == QUEST_STATUS_INCOMPLETE || caster->GetQuestStatus(QUEST_FLOWN_THE_COOP) == QUEST_STATUS_INCOMPLETE))
                    {
                        caster->CastSpell(caster, SPELL_CAPTURE_CHICKEN_ESCAPE, true);
                        target->Kill(target);
                    }
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_chicken_cover_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_chicken_cover_SpellScript();
        }
};

enum Refocus
{
    SPELL_AIMED_SHOT    = 19434,
    SPELL_MULTISHOT     = 2643,
    SPELL_VOLLEY        = 42243,
};

class spell_item_refocus : public SpellScriptLoader
{
    public:
        spell_item_refocus() : SpellScriptLoader("spell_item_refocus") { }

        class spell_item_refocus_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_refocus_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Player* caster = GetCaster()->ToPlayer();

                if (!caster || caster->getClass() != CLASS_HUNTER)
                    return;

                if (caster->HasSpellCooldown(SPELL_AIMED_SHOT))
                    caster->RemoveSpellCooldown(SPELL_AIMED_SHOT, true);

                if (caster->HasSpellCooldown(SPELL_MULTISHOT))
                    caster->RemoveSpellCooldown(SPELL_MULTISHOT, true);

                if (caster->HasSpellCooldown(SPELL_VOLLEY))
                    caster->RemoveSpellCooldown(SPELL_VOLLEY, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_refocus_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_refocus_SpellScript();
        }
};

class spell_item_muisek_vessel : public SpellScriptLoader
{
    public:
        spell_item_muisek_vessel() : SpellScriptLoader("spell_item_muisek_vessel") { }

        class spell_item_muisek_vessel_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_muisek_vessel_SpellScript);

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                if (Creature* target = GetHitCreature())
                    if (target->isDead())
                        target->DespawnOrUnsummon();
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_item_muisek_vessel_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_item_muisek_vessel_SpellScript();
        }
};

enum GreatmothersSoulcather
{
    SPELL_FORCE_CAST_SUMMON_GNOME_SOUL = 46486,
};
class spell_item_greatmothers_soulcatcher : public SpellScriptLoader
{
public:
    spell_item_greatmothers_soulcatcher() : SpellScriptLoader("spell_item_greatmothers_soulcatcher") { }

    class spell_item_greatmothers_soulcatcher_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_item_greatmothers_soulcatcher_SpellScript);

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (GetHitUnit())
                GetCaster()->CastSpell(GetCaster(), SPELL_FORCE_CAST_SUMMON_GNOME_SOUL);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_item_greatmothers_soulcatcher_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_item_greatmothers_soulcatcher_SpellScript();
    }
};

void AddSC_item_spell_scripts()
{
    // 23074 Arcanite Dragonling
    new spell_item_trigger_spell("spell_item_arcanite_dragonling", SPELL_ARCANITE_DRAGONLING);
    // 23133 Gnomish Battle Chicken
    new spell_item_trigger_spell("spell_item_gnomish_battle_chicken", SPELL_BATTLE_CHICKEN);
    // 23076 Mechanical Dragonling
    new spell_item_trigger_spell("spell_item_mechanical_dragonling", SPELL_MECHANICAL_DRAGONLING);
    // 23075 Mithril Mechanical Dragonling
    new spell_item_trigger_spell("spell_item_mithril_mechanical_dragonling", SPELL_MITHRIL_MECHANICAL_DRAGONLING);

    new spell_item_aegis_of_preservation();
    new spell_item_arcane_shroud();
    new spell_item_blessing_of_ancient_kings();
    new spell_item_defibrillate("spell_item_goblin_jumper_cables", 67, SPELL_GOBLIN_JUMPER_CABLES_FAIL);
    new spell_item_defibrillate("spell_item_goblin_jumper_cables_xl", 50, SPELL_GOBLIN_JUMPER_CABLES_XL_FAIL);
    new spell_item_defibrillate("spell_item_gnomish_army_knife", 33);
    new spell_item_desperate_defense();
    new spell_item_deviate_fish();
    new spell_item_echoes_of_light();
    new spell_item_fate_rune_of_unsurpassed_vigor();
    new spell_item_flask_of_the_north();
    new spell_item_gnomish_death_ray();
    new spell_item_make_a_wish();
    new spell_item_mingos_fortune_generator();
    new spell_item_necrotic_touch();
    new spell_item_net_o_matic();
    new spell_item_noggenfogger_elixir();
    new spell_item_piccolo_of_the_flaming_fire();
    new spell_item_savory_deviate_delight();
    new spell_item_scroll_of_recall();
    new spell_item_unsated_craving();
    new spell_item_shadows_fate();
    new spell_item_shadowmourne();
    new spell_item_shadowmourne_soul_fragment();
    new spell_item_six_demon_bag();
    new spell_item_the_eye_of_diminution();
    new spell_item_underbelly_elixir();
    new spell_item_red_rider_air_rifle();

    new spell_item_create_heart_candy();
    new spell_item_book_of_glyph_mastery();
    new spell_item_gift_of_the_harvester();
    new spell_item_map_of_the_geyser_fields();
    new spell_item_vanquished_clutches();

    new spell_item_ashbringer();
    new spell_magic_eater_food();
    new spell_item_refocus();
    new spell_item_shimmering_vessel();
    new spell_item_purify_helboar_meat();
    new spell_item_crystal_prison_dummy_dnd();
    new spell_item_reindeer_transformation();
    new spell_item_nigh_invulnerability();
    new spell_item_poultryizer();
    new spell_item_socrethars_stone();
    new spell_item_demon_broiled_surprise();
    new spell_item_complete_raptor_capture();
    new spell_item_impale_leviroth();
    new spell_item_brewfest_mount_transformation();
    new spell_item_nitro_boots();
    new spell_item_teach_language();
    new spell_item_rocket_boots();
    new spell_item_pygmy_oil();
    new spell_item_unusual_compass();
    new spell_item_chicken_cover();
    new spell_item_muisek_vessel();
    new spell_item_greatmothers_soulcatcher();
}
