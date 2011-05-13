/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "SkillDiscovery.h"

// Generic script for handling item dummy effects which trigger another spell.
class spell_item_trigger_spell : public SpellScriptLoader
{
private:
    uint32 _triggeredSpellId;

public:
    spell_item_trigger_spell(const char* name, uint32 triggeredSpellId) : SpellScriptLoader(name), _triggeredSpellId(triggeredSpellId) { }

    class spell_item_trigger_spell_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_item_trigger_spell_SpellScript)
    private:
        uint32 _triggeredSpellId;

    public:
        spell_item_trigger_spell_SpellScript(uint32 triggeredSpellId) : SpellScript(), _triggeredSpellId(triggeredSpellId) { }

        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(_triggeredSpellId))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Item* pItem = GetCastItem())
                GetCaster()->CastSpell(GetCaster(), _triggeredSpellId, true, pItem);
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_item_trigger_spell_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_item_trigger_spell_SpellScript(_triggeredSpellId);
    }
};

// http://www.wowhead.com/item=6522 Deviate Fish
// 8063 Deviate Fish
enum eDeviateFishSpells
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
        PrepareSpellScript(spell_item_deviate_fish_SpellScript)
    public:
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            for (uint32 spellId = SPELL_SLEEPY; spellId <= SPELL_HEALTHY_SPIRIT; ++spellId)
                if (!sSpellStore.LookupEntry(spellId))
                    return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* pCaster = GetCaster();
            if (pCaster->GetTypeId() != TYPEID_PLAYER)
                return;

            uint32 spellId = urand(SPELL_SLEEPY, SPELL_HEALTHY_SPIRIT);
            pCaster->CastSpell(pCaster, spellId, true, NULL);
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_item_deviate_fish_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_item_deviate_fish_SpellScript();
    }
};

// http://www.wowhead.com/item=47499 Flask of the North
// 67019 Flask of the North
enum eFlaskOfTheNorthSpells
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
    public:
        PrepareSpellScript(spell_item_flask_of_the_north_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_FLASK_OF_THE_NORTH_SP))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_FLASK_OF_THE_NORTH_AP))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_FLASK_OF_THE_NORTH_STR))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* pCaster = GetCaster();
            if (pCaster->GetTypeId() != TYPEID_PLAYER)
                return;

            std::vector<uint32> possibleSpells;
            switch (pCaster->getClass())
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

            pCaster->CastSpell(pCaster, possibleSpells[irand(0, (possibleSpells.size() - 1))], true, NULL);
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_item_flask_of_the_north_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_item_flask_of_the_north_SpellScript();
    }
};

// http://www.wowhead.com/item=10645 Gnomish Death Ray
// 13280 Gnomish Death Ray
enum eGnomishDeathRay
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
    public:
        PrepareSpellScript(spell_item_gnomish_death_ray_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_GNOMISH_DEATH_RAY_SELF))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_GNOMISH_DEATH_RAY_TARGET))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* pTarget = GetHitUnit())
            {
                Unit* pCaster = GetCaster();
                if (urand(0, 99) < 15)
                    pCaster->CastSpell(pCaster, SPELL_GNOMISH_DEATH_RAY_SELF, true, NULL);    // failure
                else
                    pCaster->CastSpell(pTarget, SPELL_GNOMISH_DEATH_RAY_TARGET, true, NULL);
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_item_gnomish_death_ray_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_item_gnomish_death_ray_SpellScript();
    }
};

// http://www.wowhead.com/item=27388 Mr. Pinchy
// 33060 Make a Wish
enum eMakeAWish
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
    public:
        PrepareSpellScript(spell_item_make_a_wish_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_MR_PINCHYS_BLESSING))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SUMMON_MIGHTY_MR_PINCHY))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SUMMON_FURIOUS_MR_PINCHY))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_TINY_MAGICAL_CRAWDAD))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_MR_PINCHYS_GIFT))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* pCaster = GetCaster();
            if (pCaster->GetTypeId() != TYPEID_PLAYER)
                return;

            uint32 spellId = SPELL_MR_PINCHYS_GIFT;
            switch (urand(1, 5))
            {
                case 1: spellId = SPELL_MR_PINCHYS_BLESSING; break;
                case 2: spellId = SPELL_SUMMON_MIGHTY_MR_PINCHY; break;
                case 3: spellId = SPELL_SUMMON_FURIOUS_MR_PINCHY; break;
                case 4: spellId = SPELL_TINY_MAGICAL_CRAWDAD; break;
            }
            pCaster->CastSpell(pCaster, spellId, true, NULL);
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_item_make_a_wish_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
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
        PrepareSpellScript(spell_item_mingos_fortune_generator_SpellScript)
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

        void Register()
        {
            OnEffect += SpellEffectFn(spell_item_mingos_fortune_generator_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_item_mingos_fortune_generator_SpellScript();
    }
};

// http://www.wowhead.com/item=10720 Gnomish Net-o-Matic Projector
// 13120 Net-o-Matic
enum eNetOMaticSpells
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
    public:
        PrepareSpellScript(spell_item_net_o_matic_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_NET_O_MATIC_TRIGGERED1))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_NET_O_MATIC_TRIGGERED2))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_NET_O_MATIC_TRIGGERED3))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* pTarget = GetHitUnit())
            {
                uint32 spellId = SPELL_NET_O_MATIC_TRIGGERED3;
                uint32 roll = urand(0, 99);
                if (roll < 2)                            // 2% for 30 sec self root (off-like chance unknown)
                    spellId = SPELL_NET_O_MATIC_TRIGGERED1;
                else if (roll < 4)                       // 2% for 20 sec root, charge to target (off-like chance unknown)
                    spellId = SPELL_NET_O_MATIC_TRIGGERED2;

                GetCaster()->CastSpell(pTarget, spellId, true, NULL);
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_item_net_o_matic_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_item_net_o_matic_SpellScript();
    }
};

// http://www.wowhead.com/item=8529 Noggenfogger Elixir
// 16589 Noggenfogger Elixir
enum eNoggenfoggerElixirSpells
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
    public:
        PrepareSpellScript(spell_item_noggenfogger_elixir_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED1))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED2))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED3))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* pCaster = GetCaster();
            if (pCaster->GetTypeId() != TYPEID_PLAYER)
                return;

            uint32 spellId = SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED3;
            switch (urand(1, 3))
            {
                case 1: spellId = SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED1; break;
                case 2: spellId = SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED2; break;
            }

            pCaster->CastSpell(pCaster, spellId, true, NULL);
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_item_noggenfogger_elixir_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_item_noggenfogger_elixir_SpellScript();
    }
};

// http://www.wowhead.com/item=6657 Savory Deviate Delight
// 8213 Savory Deviate Delight
enum eSavoryDeviateDelight
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
    public:
        PrepareSpellScript(spell_item_savory_deviate_delight_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            for (uint32 spellId = SPELL_FLIP_OUT_MALE; spellId <= SPELL_YAAARRRR_FEMALE; ++spellId)
                if (!sSpellStore.LookupEntry(spellId))
                    return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* pCaster = GetCaster();
            if (pCaster->GetTypeId() != TYPEID_PLAYER)
                return;

            uint32 spellId = 0;
            switch (urand(1, 2))
            {
                // Flip Out - ninja
                case 1: spellId = (pCaster->getGender() == GENDER_MALE ? SPELL_FLIP_OUT_MALE : SPELL_FLIP_OUT_FEMALE); break;
                // Yaaarrrr - pirate
                case 2: spellId = (pCaster->getGender() == GENDER_MALE ? SPELL_YAAARRRR_MALE : SPELL_YAAARRRR_FEMALE); break;
            }
            pCaster->CastSpell(pCaster, spellId, true, NULL);
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_item_savory_deviate_delight_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_item_savory_deviate_delight_SpellScript();
    }
};

// http://www.wowhead.com/item=7734 Six Demon Bag
// 14537 Six Demon Bag
enum eSixDemonBagSpells
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
    public:
        PrepareSpellScript(spell_item_six_demon_bag_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_FROSTBOLT))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_POLYMORPH))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SUMMON_FELHOUND_MINION))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_FIREBALL))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_CHAIN_LIGHTNING))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_ENVELOPING_WINDS))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Unit* pTarget = GetHitUnit())
            {
                Unit* pCaster = GetCaster();

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
                        pTarget = pCaster;
                }
                else if (rand < 95)                 // Enveloping Winds (15% chance)
                    spellId = SPELL_ENVELOPING_WINDS;
                else                                // Summon Felhund minion (5% chance)
                {
                    spellId = SPELL_SUMMON_FELHOUND_MINION;
                    pTarget = pCaster;
                }

                pCaster->CastSpell(pTarget, spellId, true, GetCastItem());
            }
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_item_six_demon_bag_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_item_six_demon_bag_SpellScript();
    }
};

// http://www.wowhead.com/item=44012 Underbelly Elixir
// 59640 Underbelly Elixir
enum eUnderbellyElixirSpells
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
    public:
        PrepareSpellScript(spell_item_underbelly_elixir_SpellScript)
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_UNDERBELLY_ELIXIR_TRIGGERED1))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_UNDERBELLY_ELIXIR_TRIGGERED2))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_UNDERBELLY_ELIXIR_TRIGGERED3))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* pCaster = GetCaster();
            if (pCaster->GetTypeId() != TYPEID_PLAYER)
                return;

            uint32 spellId = SPELL_UNDERBELLY_ELIXIR_TRIGGERED3;
            switch (urand(1, 3))
            {
                case 1: spellId = SPELL_UNDERBELLY_ELIXIR_TRIGGERED1; break;
                case 2: spellId = SPELL_UNDERBELLY_ELIXIR_TRIGGERED2; break;
            }
            pCaster->CastSpell(pCaster, spellId, true, NULL);
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_item_underbelly_elixir_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_item_underbelly_elixir_SpellScript();
    }
};

enum eShadowmourneVisuals
{
    SPELL_SHADOWMOURNE_VISUAL_LOW       = 72521,
    SPELL_SHADOWMOURNE_VISUAL_HIGH      = 72523,
    SPELL_SHADOWMOURNE_CHAOS_BANE_BUFF  = 73422,
};

class spell_item_shadowmourne : public SpellScriptLoader
{
public:
    spell_item_shadowmourne() : SpellScriptLoader("spell_item_shadowmourne") { }

    class spell_item_shadowmourne_AuraScript : public AuraScript
    {
    public:
        PrepareAuraScript(spell_item_shadowmourne_AuraScript)
        spell_item_shadowmourne_AuraScript() : AuraScript() { }

        bool Validate(SpellEntry const* /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_SHADOWMOURNE_VISUAL_LOW))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SHADOWMOURNE_VISUAL_HIGH))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_SHADOWMOURNE_CHAOS_BANE_BUFF))
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
            }
        }

        void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();

            if (GetTargetApplication()->GetRemoveMode() == AURA_REMOVE_BY_STACK)
                return;
            target->RemoveAurasDueToSpell(SPELL_SHADOWMOURNE_VISUAL_LOW);
            target->RemoveAurasDueToSpell(SPELL_SHADOWMOURNE_VISUAL_HIGH);
        }

        void Register()
        {
            OnEffectApply += AuraEffectApplyFn(spell_item_shadowmourne_AuraScript::OnStackChange, EFFECT_0, SPELL_AURA_MOD_STAT, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_item_shadowmourne_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_STAT, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const
    {
        return new spell_item_shadowmourne_AuraScript();
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

            bool Validate(SpellEntry const* /*spell*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_AIR_RIFLE_HOLD_VISUAL))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_AIR_RIFLE_SHOOT))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_AIR_RIFLE_SHOOT_SELF))
                    return false;
                return true;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (!GetHitUnit())
                    return;

                GetCaster()->CastSpell(GetCaster(), SPELL_AIR_RIFLE_HOLD_VISUAL, true);
                // needed because this spell shares GCD with its triggered spells (which must not be cast with triggered flag)
                if (Player* player = GetCaster()->ToPlayer())
                    player->RemoveGlobalCooldown(GetSpellInfo());
                if (urand(0, 4))
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_AIR_RIFLE_SHOOT, false);
                else
                    GetCaster()->CastSpell(GetCaster(), SPELL_AIR_RIFLE_SHOOT_SELF, false);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_item_red_rider_air_rifle_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_item_red_rider_air_rifle_SpellScript();
        }
};

enum eGenericData
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
                if (!GetHitUnit() || !GetHitUnit()->ToPlayer())
                    return;

                Player* target = GetHitUnit()->ToPlayer();

                static const uint32 items[] = {ITEM_HEART_CANDY_1, ITEM_HEART_CANDY_2, ITEM_HEART_CANDY_3, ITEM_HEART_CANDY_4, ITEM_HEART_CANDY_5, ITEM_HEART_CANDY_6, ITEM_HEART_CANDY_7, ITEM_HEART_CANDY_8};

                target->AddItem(items[urand(0, 7)], 1);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_item_create_heart_candy_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_item_create_heart_candy_SpellScript();
        }
};

class spell_item_book_of_glyph_mastery : public SpellScriptLoader
{
    public:
        spell_item_book_of_glyph_mastery() : SpellScriptLoader("spell_item_book_of_glyph_mastery") {}

        class spell_item_book_of_glyph_mastery_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_book_of_glyph_mastery_SpellScript);

            SpellCastResult CheckRequirement()
            {
                if (GetCaster()->GetTypeId() == TYPEID_PLAYER && HasDiscoveredAllSpells(GetSpellInfo()->Id, GetCaster()->ToPlayer()))
                {
                    SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_LEARNED_EVERYTHING);
                    return SPELL_FAILED_CUSTOM_ERROR;
                }

                return SPELL_CAST_OK;
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_item_book_of_glyph_mastery_SpellScript::CheckRequirement);
            }
        };

        SpellScript* GetSpellScript() const
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
        spell_item_gift_of_the_harvester() : SpellScriptLoader("spell_item_gift_of_the_harvester") {}

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

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_item_gift_of_the_harvester_SpellScript::CheckRequirement);
            }
        };

        SpellScript* GetSpellScript() const
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
        spell_item_map_of_the_geyser_fields() : SpellScriptLoader("spell_item_map_of_the_geyser_fields") {}

        class spell_item_map_of_the_geyser_fields_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_map_of_the_geyser_fields_SpellScript);

            SpellCastResult CheckSinkholes()
            {
                Unit* caster = GetCaster();
                if (caster->FindNearestCreature(NPC_SOUTH_SINKHOLE, 30.0f, true)     ||
                    caster->FindNearestCreature(NPC_NORTHEAST_SINKHOLE, 30.0f, true) ||
                    caster->FindNearestCreature(NPC_NORTHWEST_SINKHOLE, 30.0f, true))
                    return SPELL_CAST_OK;

                SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_MUST_BE_CLOSE_TO_SINKHOLE);
                return SPELL_FAILED_CUSTOM_ERROR;
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_item_map_of_the_geyser_fields_SpellScript::CheckSinkholes);
            }
        };

        SpellScript* GetSpellScript() const
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

            bool Validate(SpellEntry const* /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_CRUSHER))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_CONSTRICTOR))
                    return false;
                if (!sSpellStore.LookupEntry(SPELL_CORRUPTOR))
                    return false;
                return true;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                uint32 spellId = RAND(SPELL_CRUSHER, SPELL_CONSTRICTOR, SPELL_CORRUPTOR);
                GetCaster()->CastSpell(GetCaster(), spellId, true);
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_item_vanquished_clutches_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
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

    SPELL_ASHBRINGER    = 28282,                            // Ashbringer - Inflicts the will of the Ashbringer upon the wielder
    SPELL_ASHBRINGER_TR = 28441                             // AB Effect 000
};

class spell_item_ashbringer : public SpellScriptLoader
{
    public:
        spell_item_ashbringer() : SpellScriptLoader("spell_item_ashbringer") {}

        class spell_item_ashbringer_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_item_ashbringer_SpellScript)
            bool Validate(SpellEntry const* /*spellEntry*/)
            {
                if (!sSpellStore.LookupEntry(SPELL_ASHBRINGER))
                    return false;
                return true;
            }

            void OnDummyEffect(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);

                Unit* caster = GetCaster())
                if (caster->GetTypeId() != TYPEID_PLAYER)
                    return;
                if (Player* player = caster->ToPlayer())
                {
                    uint32 sound_id = RAND( SOUND_ASHBRINGER_1, SOUND_ASHBRINGER_2, SOUND_ASHBRINGER_3, SOUND_ASHBRINGER_4, SOUND_ASHBRINGER_5, SOUND_ASHBRINGER_6,
                                    SOUND_ASHBRINGER_7, SOUND_ASHBRINGER_8, SOUND_ASHBRINGER_9, SOUND_ASHBRINGER_10, SOUND_ASHBRINGER_11, SOUND_ASHBRINGER_12 );

                    // Ashbringers effect (spellID 28441) retriggers every 5 seconds, with a chance of making it say one of the above 12 sounds
                    if (urand(0, 60) < 1)
                        player->PlayDirectSound(sound_id, player);
                }
            }

            void Register()
            {
                OnEffect += SpellEffectFn(spell_item_ashbringer_SpellScript::OnDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_item_ashbringer_SpellScript();
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

    new spell_item_deviate_fish();
    new spell_item_flask_of_the_north();
    new spell_item_gnomish_death_ray();
    new spell_item_make_a_wish();
    new spell_item_mingos_fortune_generator();
    new spell_item_net_o_matic();
    new spell_item_noggenfogger_elixir();
    new spell_item_savory_deviate_delight();
    new spell_item_six_demon_bag();
    new spell_item_underbelly_elixir();
    new spell_item_shadowmourne();
    new spell_item_red_rider_air_rifle();

    new spell_item_create_heart_candy();
    new spell_item_book_of_glyph_mastery();
    new spell_item_gift_of_the_harvester();
    new spell_item_map_of_the_geyser_fields();
    new spell_item_vanquished_clutches();

    new spell_item_ashbringer();
}
