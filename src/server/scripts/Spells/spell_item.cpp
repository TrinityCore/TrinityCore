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
 * Scripts for spells with SPELLFAMILY_GENERIC spells used by items.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_item_".
 */

#include "ScriptPCH.h"

enum eDeviateFishSpells
{
    SPELL_SLEEPY            = 8064,
    SPELL_INVIGORATE        = 8065,
    SPELL_SHRINK            = 8066,
    SPELL_PARTY_TIME        = 8067,
    SPELL_HEALTHY_SPIRIT    = 8068,
};

// 8063 Deviate Fish
class spell_item_deviate_fish : public SpellScriptLoader
{
public:
    spell_item_deviate_fish() : SpellScriptLoader("spell_item_deviate_fish") { }

    class spell_item_deviate_fish_SpellScript : public SpellScript
    {
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

enum eFlaskOfTheNorthSpells
{
    SPELL_FLASK_OF_THE_NORTH_TRIGGERED1 = 67016,
    SPELL_FLASK_OF_THE_NORTH_TRIGGERED2 = 67017,
    SPELL_FLASK_OF_THE_NORTH_TRIGGERED3 = 67018,
};

// 67019 Flask of the North
class spell_item_flask_of_the_north : public SpellScriptLoader
{
public:
    spell_item_flask_of_the_north() : SpellScriptLoader("spell_item_flask_of_the_north") { }

    class spell_item_flask_of_the_north_SpellScript : public SpellScript
    {
    public:
        bool Validate(SpellEntry const * /*spellEntry*/)
        {
            if (!sSpellStore.LookupEntry(SPELL_FLASK_OF_THE_NORTH_TRIGGERED1))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_FLASK_OF_THE_NORTH_TRIGGERED2))
                return false;
            if (!sSpellStore.LookupEntry(SPELL_FLASK_OF_THE_NORTH_TRIGGERED3))
                return false;
            return true;
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            Unit* pCaster = GetCaster();
            if (pCaster->GetTypeId() != TYPEID_PLAYER)
                return;

            uint32 spellId = urand(SPELL_FLASK_OF_THE_NORTH_TRIGGERED1, SPELL_FLASK_OF_THE_NORTH_TRIGGERED3);
            pCaster->CastSpell(pCaster, spellId, true, NULL);
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

enum eGnomishDeathRay
{
    SPELL_GNOMISH_DEATH_RAY_SELF = 13493,
    SPELL_GNOMISH_DEATH_RAY_TARGET = 13279,
};

// 13280 Gnomish Death Ray
class spell_item_gnomish_death_ray : public SpellScriptLoader
{
public:
    spell_item_gnomish_death_ray() : SpellScriptLoader("spell_item_gnomish_death_ray") { }

    class spell_item_gnomish_death_ray_SpellScript : public SpellScript
    {
    public:
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

enum eMakeAWish
{
    SPELL_MR_PINCHYS_BLESSING       = 33053,
    SPELL_SUMMON_MIGHTY_MR_PINCHY   = 33057,
    SPELL_SUMMON_FURIOUS_MR_PINCHY  = 33059,
    SPELL_TINY_MAGICAL_CRAWDAD      = 33062,
    SPELL_MR_PINCHYS_GIFT           = 33064,
};

// 33060 Make a Wish
class spell_item_make_a_wish : public SpellScriptLoader
{
public:
    spell_item_make_a_wish() : SpellScriptLoader("spell_item_make_a_wish") { }

    class spell_item_make_a_wish_SpellScript : public SpellScript
    {
    public:
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

enum eNetOMaticSpells
{
    SPELL_NET_O_MATIC_TRIGGERED1 = 16566,
    SPELL_NET_O_MATIC_TRIGGERED2 = 13119,
    SPELL_NET_O_MATIC_TRIGGERED3 = 13099,
};

// 13120 Net-o-Matic
class spell_item_net_o_matic : public SpellScriptLoader
{
public:
    spell_item_net_o_matic() : SpellScriptLoader("spell_item_net_o_matic") { }

    class spell_item_net_o_matic_SpellScript : public SpellScript
    {
    public:
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

enum eNoggenfoggerElixirSpells
{
    SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED1 = 16595,
    SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED2 = 16593,
    SPELL_NOGGENFOGGER_ELIXIR_TRIGGERED3 = 16591,
};

// 16589 Noggenfogger Elixir
class spell_item_noggenfogger_elixir : public SpellScriptLoader
{
public:
    spell_item_noggenfogger_elixir() : SpellScriptLoader("spell_item_noggenfogger_elixir") { }

    class spell_item_noggenfogger_elixir_SpellScript : public SpellScript
    {
    public:
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

enum eSavoryDeviateDelight
{
    SPELL_FLIP_OUT_MALE     = 8219,
    SPELL_FLIP_OUT_FEMALE   = 8220,
    SPELL_YAAARRRR_MALE     = 8221,
    SPELL_YAAARRRR_FEMALE   = 8222,
};

// 8213 Savory Deviate Delight
class spell_item_savory_deviate_delight : public SpellScriptLoader
{
public:
    spell_item_savory_deviate_delight() : SpellScriptLoader("spell_item_savory_deviate_delight") { }

    class spell_item_savory_deviate_delight_SpellScript : public SpellScript
    {
    public:
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

enum eUnderbellyElixirSpells
{
    SPELL_UNDERBELLY_ELIXIR_TRIGGERED1 = 59645,
    SPELL_UNDERBELLY_ELIXIR_TRIGGERED2 = 59831,
    SPELL_UNDERBELLY_ELIXIR_TRIGGERED3 = 59843,
};

// 59640 Underbelly Elixir
class spell_item_underbelly_elixir : public SpellScriptLoader
{
public:
    spell_item_underbelly_elixir() : SpellScriptLoader("spell_item_underbelly_elixir") { }

    class spell_item_underbelly_elixir_SpellScript : public SpellScript
    {
    public:
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

void AddSC_item_spell_scripts()
{
    new spell_item_deviate_fish();
    new spell_item_flask_of_the_north();
    new spell_item_gnomish_death_ray();
    new spell_item_make_a_wish();
    new spell_item_net_o_matic();
    new spell_item_noggenfogger_elixir();
    new spell_item_savory_deviate_delight();
    new spell_item_underbelly_elixir();
}
