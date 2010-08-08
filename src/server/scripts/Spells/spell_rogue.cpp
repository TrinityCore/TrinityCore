/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
 * Scripts for spells with SPELLFAMILY_ROGUE and SPELLFAMILY_GENERIC spells used by rogue players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_rog_".
 */

#include "ScriptPCH.h"

enum RogueSpells
{
    ROGUE_SPELL_HUNGER_FOR_BLOOD_BUFF            = 63848,
    ROGUE_SPELL_SHIV_TRIGGERED                   = 5940,
    ROGUE_SPELL_CHEATING_DEATH                   = 45182,
    ROGUE_SPELL_GLYPH_OF_PREPARATION             = 56819,
};

class spell_rog_cheat_death : public SpellHandlerScript
{
    public:
        spell_rog_cheat_death() : SpellHandlerScript("spell_rog_cheat_death") { }

        class spell_rog_cheat_death_SpellScript : public SpellScript
        {
            bool Validate(SpellEntry const * spellEntry)
            {
                if (!sSpellStore.LookupEntry(ROGUE_SPELL_CHEATING_DEATH))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                Unit *caster = GetCaster();
                caster->CastSpell(caster, ROGUE_SPELL_CHEATING_DEATH, true);
            }

            void Register()
            {
                // add dummy effect spell handler to Cheat Death
                EffectHandlers += EffectHandlerFn(spell_rog_cheat_death_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_rog_cheat_death_SpellScript;
        }
};

class spell_rog_hunger_for_blood : public SpellHandlerScript
{
    public:
        spell_rog_hunger_for_blood() : SpellHandlerScript("spell_rog_hunger_for_blood") { }

        class spell_rog_hunger_for_blood_SpellScript : public SpellScript
        {
            bool Validate(SpellEntry const * spellEntry)
            {
                if (!sSpellStore.LookupEntry(ROGUE_SPELL_HUNGER_FOR_BLOOD_BUFF))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                Unit *caster = GetCaster();
                caster->CastSpell(caster, ROGUE_SPELL_HUNGER_FOR_BLOOD_BUFF, true);
            }

            void Register()
            {
                // add dummy effect spell handler to Hunger for Blood
                EffectHandlers += EffectHandlerFn(spell_rog_hunger_for_blood_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_rog_hunger_for_blood_SpellScript();
        }
};

class spell_rog_preparation : public SpellHandlerScript
{
    public:
        spell_rog_preparation() : SpellHandlerScript("spell_rog_preparation") { }

        class spell_rog_preparation_SpellScript : public SpellScript
        {
            bool Validate(SpellEntry const * spellEntry)
            {
                if (!sSpellStore.LookupEntry(ROGUE_SPELL_GLYPH_OF_PREPARATION))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                Unit *caster = GetCaster();
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return;

                //immediately finishes the cooldown on certain Rogue abilities
                const SpellCooldowns& cm = caster->ToPlayer()->GetSpellCooldownMap();
                for (SpellCooldowns::const_iterator itr = cm.begin(); itr != cm.end();)
                {
                    SpellEntry const *spellInfo = sSpellStore.LookupEntry(itr->first);

                    if (spellInfo->SpellFamilyName == SPELLFAMILY_ROGUE)
                    {
                        if (spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_ROGUE_COLDB_SHADOWSTEP ||      // Cold Blood, Shadowstep
                            spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_ROGUE_VAN_EVAS_SPRINT)           // Vanish, Evasion, Sprint
                            caster->ToPlayer()->RemoveSpellCooldown((itr++)->first, true);
                        else if (caster->HasAura(ROGUE_SPELL_GLYPH_OF_PREPARATION))
                        {
                            if (spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_ROGUE_DISMANTLE ||         // Dismantle
                                spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_ROGUE_KICK ||               // Kick
                                (spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_ROGUE_BLADE_FLURRY &&     // Blade Flurry
                                spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_ROGUE_BLADE_FLURRY))
                                caster->ToPlayer()->RemoveSpellCooldown((itr++)->first, true);
                            else
                                ++itr;
                        }
                        else
                            ++itr;
                    }
                    else
                        ++itr;
                }
            }

            void Register()
            {
                // add dummy effect spell handler to Preparation
                EffectHandlers += EffectHandlerFn(spell_rog_preparation_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_rog_preparation_SpellScript();
        }
};

class spell_rog_shiv : public SpellHandlerScript
{
    public:
        spell_rog_shiv() : SpellHandlerScript("spell_rog_shiv") { }

        class spell_rog_shiv_SpellScript : public SpellScript
        {
            bool Validate(SpellEntry const * spellEntry)
            {
                if (!sSpellStore.LookupEntry(ROGUE_SPELL_SHIV_TRIGGERED))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                Unit *caster = GetCaster();
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (Unit *unitTarget = GetHitUnit())
                    caster->CastSpell(unitTarget, ROGUE_SPELL_SHIV_TRIGGERED, true);
            }

            void Register()
            {
                // add dummy effect spell handler to Shiv
                EffectHandlers += EffectHandlerFn(spell_rog_shiv_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript *GetSpellScript() const
        {
            return new spell_rog_shiv_SpellScript();
        }
};

void AddSC_rogue_spell_scripts()
{
    new spell_rog_cheat_death;
    new spell_rog_hunger_for_blood;
    new spell_rog_preparation;
    new spell_rog_shiv;
}
