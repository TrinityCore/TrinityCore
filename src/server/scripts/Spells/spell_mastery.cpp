/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with MASTERY.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_mastery_".
 */

#include "ScriptMgr.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"

enum MasterySpells
{
    MASTERY_SPELL_LIGHTNING_BOLT        = 45284,
    MASTERY_SPELL_CHAIN_LIGHTNING       = 45297,
    MASTERY_SPELL_LAVA_BURST            = 77451,
    MASTERY_SPELL_ELEMENTAL_BLAST       = 120588,
    MASTERY_SPELL_HAND_OF_LIGHT         = 96172,
    MASTERY_SPELL_IGNITE                = 12654,
    MASTERY_SPELL_BLOOD_SHIELD          = 77535,
    MASTERY_SPELL_COMBO_BREAKER         = 115636,
    MASTERY_SPELL_COMBO_BREAKER_1       = 118864,
    MASTERY_SPELL_COMBO_BREAKER_2       = 116768,
    MASTERY_SPELL_DISCIPLINE_SHIELD     = 77484,
    SPELL_DK_SCENT_OF_BLOOD             = 50421,
};

// Called by Power Word : Shield - 17, Power Word : Shield (Divine Insight) - 123258, Spirit Shell - 114908, Angelic Bulwark - 114214 and Divine Aegis - 47753
// Mastery : Shield Discipline - 77484
class spell_mastery_shield_discipline : public SpellScriptLoader
{
    public:
        spell_mastery_shield_discipline() : SpellScriptLoader("spell_mastery_shield_discipline") { }

        class spell_mastery_shield_discipline_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mastery_shield_discipline_AuraScript);

            void CalculateAmount(constAuraEffectPtr , int32 & amount, bool & )
            {
                if (Unit* caster = GetCaster())
                {
                    if (caster->HasAura(MASTERY_SPELL_DISCIPLINE_SHIELD) && caster->getLevel() >= 80)
                    {
                        float Mastery = 1 + (caster->GetFloatValue(PLAYER_MASTERY) * 2.5f / 100.0f);
                        amount = int32(amount * Mastery);
                    }
                }
            }

            void Register()
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mastery_shield_discipline_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_mastery_shield_discipline_AuraScript();
        }
};

// Called by 100780 / 108557 / 115698 / 115687 / 115693 / 115695 - Jab (and overrides)
// 115636 - Mastery : Combo Breaker
class spell_mastery_combo_breaker : public SpellScriptLoader
{
    public:
        spell_mastery_combo_breaker() : SpellScriptLoader("spell_mastery_combo_breaker") { }

        class spell_mastery_combo_breaker_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mastery_combo_breaker_SpellScript);

            void HandleOnHit()
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        if (caster->GetTypeId() == TYPEID_PLAYER && caster->HasAura(MASTERY_SPELL_COMBO_BREAKER))
                        {
                            float Mastery = caster->GetFloatValue(PLAYER_MASTERY) * 1.4f;

                            if (roll_chance_f(Mastery))
                            {
                                if (roll_chance_i(50))
                                    caster->CastSpell(caster, MASTERY_SPELL_COMBO_BREAKER_1, true);
                                else
                                    caster->CastSpell(caster, MASTERY_SPELL_COMBO_BREAKER_2, true);
                            }
                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_mastery_combo_breaker_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_mastery_combo_breaker_SpellScript();
        }
};

// Called by 45470 - Death Strike (Heal)
// 77513 - Mastery : Blood Shield
class spell_mastery_blood_shield : public SpellScriptLoader
{
    public:
        spell_mastery_blood_shield() : SpellScriptLoader("spell_mastery_blood_shield") { }

        class spell_mastery_blood_shield_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mastery_blood_shield_SpellScript);

            void HandleAfterHit()
            {
                if (Player* _plr = GetCaster()->ToPlayer())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        if (_plr->GetTypeId() == TYPEID_PLAYER && _plr->HasAura(77513) && _plr->getLevel() >= 80)
                        {
                            // Check the Mastery aura while in Blood presence
                            if (_plr->HasAura(77513) && _plr->HasAura(48263))
                            {
                                float Mastery = _plr->GetFloatValue(PLAYER_MASTERY) * 6.25f / 100.0f;

                                int32 bp = -int32(GetHitDamage() * Mastery);

                                if (AuraPtr scentOfBlood = _plr->GetAura(SPELL_DK_SCENT_OF_BLOOD))
                                    AddPct(bp, (scentOfBlood->GetStackAmount() * 20));

                                if (AuraEffectPtr bloodShield = target->GetAuraEffect(MASTERY_SPELL_BLOOD_SHIELD, EFFECT_0))
                                    bp += bloodShield->GetAmount();

                                bp = std::min(uint32(bp), target->GetMaxHealth());

                                _plr->CastCustomSpell(target, MASTERY_SPELL_BLOOD_SHIELD, &bp, NULL, NULL, true);
                            }
                        }
                    }
                }
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_mastery_blood_shield_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_mastery_blood_shield_SpellScript();
        }
};

// Called by 133 - Fireball, 44614 - Frostfire Bolt, 108853 - Inferno Blast, 2948 - Scorch and 11366 - Pyroblast
// 12846 - Mastery : Ignite
class spell_mastery_ignite : public SpellScriptLoader
{
    public:
        spell_mastery_ignite() : SpellScriptLoader("spell_mastery_ignite") { }

        class spell_mastery_ignite_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mastery_ignite_SpellScript);

            void HandleAfterHit()
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        if (caster->GetTypeId() == TYPEID_PLAYER && caster->HasAura(12846) && caster->getLevel() >= 80)
                        {
                            uint32 procSpellId = GetSpellInfo()->Id ? GetSpellInfo()->Id : 0;
                            if (procSpellId != MASTERY_SPELL_IGNITE)
                            {
                                float value = caster->GetFloatValue(PLAYER_MASTERY) * 1.5f / 100.0f;

                                int32 bp = GetHitDamage();
                                bp = int32(bp * value / 2);

                                if (target->HasAura(MASTERY_SPELL_IGNITE, caster->GetGUID()))
                                {
                                    bp += target->GetRemainingPeriodicAmount(caster->GetGUID(), MASTERY_SPELL_IGNITE, SPELL_AURA_PERIODIC_DAMAGE);
                                    bp = int32(bp * 0.66f);
                                }

                                caster->CastCustomSpell(target, MASTERY_SPELL_IGNITE, &bp, NULL, NULL, true);
                            }
                        }
                    }
                }
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_mastery_ignite_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_mastery_ignite_SpellScript();
        }
};

// Called by 35395 - Crusader Strike, 53595 - Hammer of the Righteous, 24275 - Hammer of Wrath, 85256 - Templar's Verdict and 53385 - Divine Storm
// 76672 - Mastery : Hand of Light
class spell_mastery_hand_of_light : public SpellScriptLoader
{
    public:
        spell_mastery_hand_of_light() : SpellScriptLoader("spell_mastery_hand_of_light") { }

        class spell_mastery_hand_of_light_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mastery_hand_of_light_SpellScript);

            void HandleAfterHit()
            {
                if (Unit* caster = GetCaster())
                {
                    if (Unit* target = GetHitUnit())
                    {
                        if (caster->GetTypeId() == TYPEID_PLAYER && caster->HasAura(76672) && caster->getLevel() >= 80)
                        {
                            uint32 procSpellId = GetSpellInfo()->Id ? GetSpellInfo()->Id : 0;
                            if (procSpellId != MASTERY_SPELL_HAND_OF_LIGHT)
                            {
                                float value = caster->GetFloatValue(PLAYER_MASTERY) * 1.85f;

                                int32 bp = int32(GetHitDamage() * value / 100);

                                caster->CastCustomSpell(target, MASTERY_SPELL_HAND_OF_LIGHT, &bp, NULL, NULL, true);
                            }
                        }
                    }
                }
            }

            void Register()
            {
                AfterHit += SpellHitFn(spell_mastery_hand_of_light_SpellScript::HandleAfterHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_mastery_hand_of_light_SpellScript();
        }
};

// Called by 403 - Lightning Bolt, 421 - Chain Lightning, 51505 - Lava Burst and 117014 - Elemental Blast
// 77222 - Mastery : Elemental Overload
class spell_mastery_elemental_overload : public SpellScriptLoader
{
    public:
        spell_mastery_elemental_overload() : SpellScriptLoader("spell_mastery_elemental_overload") { }

        class spell_mastery_elemental_overload_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_mastery_elemental_overload_SpellScript);

            bool Validate(SpellInfo const* /*spellEntry*/)
            {
                if (!sSpellMgr->GetSpellInfo(403) || !sSpellMgr->GetSpellInfo(421) || !sSpellMgr->GetSpellInfo(51505) || !sSpellMgr->GetSpellInfo(117014))
                    return false;
                return true;
            }

            void HandleOnHit()
            {
                SpellInfo const* procSpell = GetSpellInfo();

                if (procSpell)
                {
                    if (Unit* caster = GetCaster())
                    {
                        if (Unit* unitTarget = GetHitUnit())
                        {
                            if (caster->GetTypeId() == TYPEID_PLAYER && caster->HasAura(77222))
                            {
                                // Every Lightning Bolt, Chain Lightning and Lava Burst spells have duplicate vs 75% damage and no cost
                                switch (procSpell->Id)
                                {
                                    // Lava Burst
                                    case 51505:
                                    {
                                        float Mastery = caster->GetFloatValue(PLAYER_MASTERY) * 2.0f;

                                        if (roll_chance_f(Mastery))
                                            caster->CastSpell(unitTarget, MASTERY_SPELL_LAVA_BURST, true);

                                        break;
                                    }
                                    // Lightning Bolt
                                    case 403:
                                    {
                                        float Mastery = caster->GetFloatValue(PLAYER_MASTERY) * 2.0f;

                                        if (roll_chance_f(Mastery))
                                            caster->CastSpell(unitTarget, MASTERY_SPELL_LIGHTNING_BOLT, true);

                                        break;
                                    }
                                    // Chain Lightning
                                    case 421:
                                    {
                                        float Mastery = caster->GetFloatValue(PLAYER_MASTERY) * 2.0f;

                                        if (roll_chance_f(Mastery))
                                            caster->CastSpell(unitTarget, MASTERY_SPELL_CHAIN_LIGHTNING, true);

                                        break;
                                    }
                                    // Elemental Blast
                                    case 117014:
                                    {
                                        float Mastery = caster->GetFloatValue(PLAYER_MASTERY) * 2.0f;

                                        if (roll_chance_f(Mastery))
                                        {
                                            caster->CastSpell(unitTarget, MASTERY_SPELL_ELEMENTAL_BLAST, true);
                                            caster->CastSpell(unitTarget, 118517, true); // Nature visual
                                            caster->CastSpell(unitTarget, 118515, true); // Frost visual
                                        }

                                        break;
                                    }
                                    default: break;
                                }
                            }
                        }
                    }
                }
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_mastery_elemental_overload_SpellScript::HandleOnHit);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_mastery_elemental_overload_SpellScript();
        }
};

void AddSC_mastery_spell_scripts()
{
    new spell_mastery_shield_discipline();
    new spell_mastery_combo_breaker();
    new spell_mastery_blood_shield();
    new spell_mastery_ignite();
    new spell_mastery_hand_of_light();
    new spell_mastery_elemental_overload();
}