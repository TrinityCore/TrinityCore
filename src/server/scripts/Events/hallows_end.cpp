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

#include "ScriptMgr.h"
#include "CreatureAIImpl.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum HallowEndCandysSpells
{
    SPELL_HALLOWS_END_CANDY_ORANGE_GIANT          = 24924, // Effect 1: Apply Aura: Mod Size, Value: 30%
    SPELL_HALLOWS_END_CANDY_SKELETON              = 24925, // Effect 1: Apply Aura: Change Model (Skeleton). Effect 2: Apply Aura: Underwater Breathing
    SPELL_HALLOWS_END_CANDY_PIRATE                = 24926, // Effect 1: Apply Aura: Increase Swim Speed, Value: 50%
    SPELL_HALLOWS_END_CANDY_GHOST                 = 24927, // Effect 1: Apply Aura: Levitate / Hover. Effect 2: Apply Aura: Slow Fall, Effect 3: Apply Aura: Water Walking
    SPELL_HALLOWS_END_CANDY_FEMALE_DEFIAS_PIRATE  = 44742, // Effect 1: Apply Aura: Change Model (Defias Pirate, Female). Effect 2: Increase Swim Speed, Value: 50%
    SPELL_HALLOWS_END_CANDY_MALE_DEFIAS_PIRATE    = 44743  // Effect 1: Apply Aura: Change Model (Defias Pirate, Male).   Effect 2: Increase Swim Speed, Value: 50%
};

std::array<uint32, 4> const CandysSpells =
{
    SPELL_HALLOWS_END_CANDY_ORANGE_GIANT,
    SPELL_HALLOWS_END_CANDY_SKELETON,
    SPELL_HALLOWS_END_CANDY_PIRATE,
    SPELL_HALLOWS_END_CANDY_GHOST
};

// 24930 - Hallow's End Candy
class spell_hallow_end_candy : public SpellScript
{
    PrepareSpellScript(spell_hallow_end_candy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(CandysSpells);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), Trinity::Containers::SelectRandomContainerElement(CandysSpells), true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_hallow_end_candy::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 24926 - Hallow's End Candy
class spell_hallow_end_candy_pirate : public AuraScript
{
    PrepareAuraScript(spell_hallow_end_candy_pirate);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_HALLOWS_END_CANDY_FEMALE_DEFIAS_PIRATE,
            SPELL_HALLOWS_END_CANDY_MALE_DEFIAS_PIRATE
        });
    }

    void HandleApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        uint32 spell = GetTarget()->GetNativeGender() == GENDER_FEMALE ? SPELL_HALLOWS_END_CANDY_FEMALE_DEFIAS_PIRATE : SPELL_HALLOWS_END_CANDY_MALE_DEFIAS_PIRATE;
        GetTarget()->CastSpell(GetTarget(), spell, true);
    }

    void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        uint32 spell = GetTarget()->GetNativeGender() == GENDER_FEMALE ? SPELL_HALLOWS_END_CANDY_FEMALE_DEFIAS_PIRATE : SPELL_HALLOWS_END_CANDY_MALE_DEFIAS_PIRATE;
        GetTarget()->RemoveAurasDueToSpell(spell);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_hallow_end_candy_pirate::HandleApply, EFFECT_0, SPELL_AURA_MOD_INCREASE_SWIM_SPEED, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_hallow_end_candy_pirate::HandleRemove, EFFECT_0, SPELL_AURA_MOD_INCREASE_SWIM_SPEED, AURA_EFFECT_HANDLE_REAL);
    }
};

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

// 24750 - Trick
class spell_hallow_end_trick : public SpellScript
{
    PrepareSpellScript(spell_hallow_end_trick);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PIRATE_COSTUME_MALE,
            SPELL_PIRATE_COSTUME_FEMALE,
            SPELL_NINJA_COSTUME_MALE,
            SPELL_NINJA_COSTUME_FEMALE,
            SPELL_LEPER_GNOME_COSTUME_MALE,
            SPELL_LEPER_GNOME_COSTUME_FEMALE,
            SPELL_SKELETON_COSTUME,
            SPELL_GHOST_COSTUME_MALE,
            SPELL_GHOST_COSTUME_FEMALE,
            SPELL_TRICK_BUFF
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (Player* target = GetHitPlayer())
        {
            uint8 gender = target->GetNativeGender();
            uint32 spellId = SPELL_TRICK_BUFF;
            switch (urand(0, 5))
            {
                case 1:
                    spellId = gender == GENDER_FEMALE ? SPELL_LEPER_GNOME_COSTUME_FEMALE : SPELL_LEPER_GNOME_COSTUME_MALE;
                    break;
                case 2:
                    spellId = gender == GENDER_FEMALE ? SPELL_PIRATE_COSTUME_FEMALE : SPELL_PIRATE_COSTUME_MALE;
                    break;
                case 3:
                    spellId = gender == GENDER_FEMALE ? SPELL_GHOST_COSTUME_FEMALE : SPELL_GHOST_COSTUME_MALE;
                    break;
                case 4:
                    spellId = gender == GENDER_FEMALE ? SPELL_NINJA_COSTUME_FEMALE : SPELL_NINJA_COSTUME_MALE;
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
        OnEffectHitTarget += SpellEffectFn(spell_hallow_end_trick::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum TrickOrTreatSpells
{
    SPELL_TRICK                 = 24714,
    SPELL_TREAT                 = 24715,
    SPELL_TRICKED_OR_TREATED    = 24755,
    SPELL_TRICKY_TREAT_SPEED    = 42919,
    SPELL_TRICKY_TREAT_TRIGGER  = 42965,
    SPELL_UPSET_TUMMY           = 42966
};

// 24751 - Trick or Treat
class spell_hallow_end_trick_or_treat : public SpellScript
{
    PrepareSpellScript(spell_hallow_end_trick_or_treat);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo({ SPELL_TRICK, SPELL_TREAT, SPELL_TRICKED_OR_TREATED });
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
        OnEffectHitTarget += SpellEffectFn(spell_hallow_end_trick_or_treat::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 44436 - Tricky Treat
class spell_hallow_end_tricky_treat : public SpellScript
{
    PrepareSpellScript(spell_hallow_end_tricky_treat);

    bool Validate(SpellInfo const* /*spell*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_TRICKY_TREAT_SPEED,
            SPELL_TRICKY_TREAT_TRIGGER,
            SPELL_UPSET_TUMMY
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (caster->HasAura(SPELL_TRICKY_TREAT_TRIGGER) && caster->GetAuraCount(SPELL_TRICKY_TREAT_SPEED) > 3 && roll_chance_i(33))
            caster->CastSpell(caster, SPELL_UPSET_TUMMY, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_hallow_end_tricky_treat::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

enum HallowendData
{
    SPELL_HALLOWED_WAND_PIRATE             = 24717,
    SPELL_HALLOWED_WAND_NINJA              = 24718,
    SPELL_HALLOWED_WAND_LEPER_GNOME        = 24719,
    SPELL_HALLOWED_WAND_RANDOM             = 24720,
    SPELL_HALLOWED_WAND_SKELETON           = 24724,
    SPELL_HALLOWED_WAND_WISP               = 24733,
    SPELL_HALLOWED_WAND_GHOST              = 24737,
    SPELL_HALLOWED_WAND_BAT                = 24741
};

// 24717, 24718, 24719, 24720, 24724, 24733, 24737, 24741
class spell_hallow_end_wand : public SpellScript
{
    PrepareSpellScript(spell_hallow_end_wand);

    bool Validate(SpellInfo const* /*spellEntry*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_PIRATE_COSTUME_MALE,
            SPELL_PIRATE_COSTUME_FEMALE,
            SPELL_NINJA_COSTUME_MALE,
            SPELL_NINJA_COSTUME_FEMALE,
            SPELL_LEPER_GNOME_COSTUME_MALE,
            SPELL_LEPER_GNOME_COSTUME_FEMALE,
            SPELL_GHOST_COSTUME_MALE,
            SPELL_GHOST_COSTUME_FEMALE
        });
    }

    void HandleScriptEffect()
    {
        Unit* caster = GetCaster();
        Unit* target = GetHitUnit();

        uint32 spellId = 0;
        uint8 gender = target->GetNativeGender();

        switch (GetSpellInfo()->Id)
        {
            case SPELL_HALLOWED_WAND_LEPER_GNOME:
                spellId = gender ? SPELL_LEPER_GNOME_COSTUME_FEMALE : SPELL_LEPER_GNOME_COSTUME_MALE;
                break;
            case SPELL_HALLOWED_WAND_PIRATE:
                spellId = gender ? SPELL_PIRATE_COSTUME_FEMALE : SPELL_PIRATE_COSTUME_MALE;
                break;
            case SPELL_HALLOWED_WAND_GHOST:
                spellId = gender ? SPELL_GHOST_COSTUME_FEMALE : SPELL_GHOST_COSTUME_MALE;
                break;
            case SPELL_HALLOWED_WAND_NINJA:
                spellId = gender ? SPELL_NINJA_COSTUME_FEMALE : SPELL_NINJA_COSTUME_MALE;
                break;
            case SPELL_HALLOWED_WAND_RANDOM:
                spellId = RAND(SPELL_HALLOWED_WAND_PIRATE, SPELL_HALLOWED_WAND_NINJA, SPELL_HALLOWED_WAND_LEPER_GNOME, SPELL_HALLOWED_WAND_SKELETON, SPELL_HALLOWED_WAND_WISP, SPELL_HALLOWED_WAND_GHOST, SPELL_HALLOWED_WAND_BAT);
                break;
            default:
                return;
        }
        caster->CastSpell(target, spellId, true);
    }

    void Register() override
    {
        AfterHit += SpellHitFn(spell_hallow_end_wand::HandleScriptEffect);
    }
};

void AddSC_event_hallows_end()
{
    RegisterSpellScript(spell_hallow_end_candy);
    RegisterSpellScript(spell_hallow_end_candy_pirate);
    RegisterSpellScript(spell_hallow_end_trick);
    RegisterSpellScript(spell_hallow_end_trick_or_treat);
    RegisterSpellScript(spell_hallow_end_tricky_treat);
    RegisterSpellScript(spell_hallow_end_wand);
}
