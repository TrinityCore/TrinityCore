/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
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


#include "Player.h"
#include "ScriptMgr.h"
#include "SpellScript.h"

enum MasterySpells
{
    MASTERY_WARRIOR_ARMS                = 76838,
    MASTERY_WARRIOR_FURY                = 76856,
    MASTERY_WARRIOR_PROTECTION          = 76857,

    MASTERY_PALADIN_HOLY                = 76669,
    MASTERY_PALADIN_PROTECTION          = 76671,
    MASTERY_PALADIN_RETRIBUTION         = 76672,
    
    MASTERY_HUNTER_BEASTMASTER          = 76657,
    MASTERY_HUNTER_MARKSMAN             = 76659,
    MASTERY_HUNTER_SURVIVAL             = 76658,

    MASTERY_ROGUE_ASSASSINATION         = 76803,
    MASTERY_ROGUE_COMBAT                = 76806,
    MASTERY_ROGUE_SUBTLETY              = 76808,

    MASTERY_PRIEST_DISCIPLINE           = 77484,
    MASTERY_PRIEST_HOLY                 = 77485,
    MASTERY_PRIEST_SHADOW               = 77486,

    MASTERY_DEATHKNIGHT_BLOOD           = 77513,
    MASTERY_DEATHKNIGHT_FROST           = 77514,
    MASTERY_DEATHKNIGHT_UNHOLY          = 77515,

    MASTERY_SHAMAN_ELEMENTAL            = 77222,
    MASTERY_SHAMAN_ENHANCEMENT          = 77223,
    MASTERY_SHAMAN_RESTORATION          = 77226,

    MASTERY_MAGE_ARCANE                 = 76547,
    MASTERY_MAGE_FIRE                   = 12846,
    MASTERY_MAGE_FROST                  = 76613,

    MASTERY_WARLOCK_AFFLICTION          = 77215,
    MASTERY_WARLOCK_DEMONOLOGY          = 77219,
    MASTERY_WARLOCK_DESTRUCTION         = 77220,

    MASTERY_MONK_BREWMASTER             = 117906,
    MASTERY_MONK_MISTWEAVER             = 117907,
    MASTERY_MONK_WINDWALKER             = 115636,

    MASTERY_DRUID_BALANCE               = 77492,
    MASTERY_DRUID_FERAL                 = 77493,
    MASTERY_DRUID_GUARDIAN              = 77494,
    MASTERY_DRUID_RESTORATION           = 77495
};

enum WarriorSpells
{
	SPELL_WARR_ENRAGE		= 12880,
};

// Warrior spell : Enrage 12880
class spell_mastery_unshackled_fury : public SpellScriptLoader
{
    public:
        spell_mastery_unshackled_fury() : SpellScriptLoader("spell_mastery_unshackled_fury") { }

        class spell_mastery_unshackled_fury_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_mastery_unshackled_fury_AuraScript);

            void CalculateAmount(AuraEffect const* aurEff, int32 & amount, bool & /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster()->ToPlayer())
                {
                    if (caster->HasAura(MASTERY_WARRIOR_FURY) && caster->getLevel() >= 80)
                        amount = caster->GetFloatValue(PLAYER_MASTERY) + caster->ToPlayer()->GetRatingBonusValue(CR_MASTERY);
                }
            }

            void Register()
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_mastery_unshackled_fury_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_mastery_unshackled_fury_AuraScript();
        }
};

void AddSC_masteries_spell_scripts()
{
	new spell_mastery_unshackled_fury();
}
