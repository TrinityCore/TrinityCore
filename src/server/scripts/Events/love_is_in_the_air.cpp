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
#include "CellImpl.h"
#include "CreatureAIImpl.h"
#include "GridNotifiersImpl.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum SpellsPicnic
{
    SPELL_BASKET_CHECK              = 45119, // Holiday - Valentine - Romantic Picnic Near Basket Check
    SPELL_MEAL_PERIODIC             = 45103, // Holiday - Valentine - Romantic Picnic Meal Periodic - effect dummy
    SPELL_MEAL_EAT_VISUAL           = 45120, // Holiday - Valentine - Romantic Picnic Meal Eat Visual
    // SPELL_MEAL_PARTICLE          = 45114, // Holiday - Valentine - Romantic Picnic Meal Particle - unused
    SPELL_DRINK_VISUAL              = 45121, // Holiday - Valentine - Romantic Picnic Drink Visual
    SPELL_ROMANTIC_PICNIC_ACHIEV    = 45123, // Romantic Picnic periodic = 5000
};

// 45102 - Romantic Picnic
class spell_love_is_in_the_air_romantic_picnic : public AuraScript
{
    PrepareAuraScript(spell_love_is_in_the_air_romantic_picnic);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_BASKET_CHECK,
            SPELL_MEAL_PERIODIC,
            SPELL_MEAL_EAT_VISUAL,
            SPELL_DRINK_VISUAL,
            SPELL_ROMANTIC_PICNIC_ACHIEV
        });
    }

    void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->SetStandState(UNIT_STAND_STATE_SIT);
        target->CastSpell(target, SPELL_MEAL_PERIODIC);
    }

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        // Every 5 seconds
        Unit* target = GetTarget();

        // If our player is no longer sit, remove all auras
        if (target->GetStandState() != UNIT_STAND_STATE_SIT)
        {
            target->RemoveAurasDueToSpell(SPELL_ROMANTIC_PICNIC_ACHIEV);
            target->RemoveAura(GetAura());
            return;
        }

        target->CastSpell(target, SPELL_BASKET_CHECK); // unknown use, it targets Romantic Basket
        target->CastSpell(target, RAND(SPELL_MEAL_EAT_VISUAL, SPELL_DRINK_VISUAL));

        bool foundSomeone = false;
        // For nearby players, check if they have the same aura. If so, cast Romantic Picnic (45123)
        // required by achievement and "hearts" visual
        std::list<Player*> playerList;
        Trinity::AnyPlayerInObjectRangeCheck checker(target, INTERACTION_DISTANCE*2);
        Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(target, playerList, checker);
        Cell::VisitWorldObjects(target, searcher, INTERACTION_DISTANCE * 2);
        for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
        {
            if (Player* playerFound = (*itr))
            {
                if (target != playerFound && playerFound->HasAura(GetId()))
                {
                    playerFound->CastSpell(playerFound, SPELL_ROMANTIC_PICNIC_ACHIEV, true);
                    target->CastSpell(target, SPELL_ROMANTIC_PICNIC_ACHIEV, true);
                    foundSomeone = true;
                    break;
                }
            }
        }

        if (!foundSomeone && target->HasAura(SPELL_ROMANTIC_PICNIC_ACHIEV))
            target->RemoveAurasDueToSpell(SPELL_ROMANTIC_PICNIC_ACHIEV);
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectApplyFn(spell_love_is_in_the_air_romantic_picnic::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_love_is_in_the_air_romantic_picnic::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

enum CreateHeartCandy
{
    SPELL_CREATE_HEART_CANDY_1     = 26668,
    SPELL_CREATE_HEART_CANDY_2     = 26670,
    SPELL_CREATE_HEART_CANDY_3     = 26671,
    SPELL_CREATE_HEART_CANDY_4     = 26672,
    SPELL_CREATE_HEART_CANDY_5     = 26673,
    SPELL_CREATE_HEART_CANDY_6     = 26674,
    SPELL_CREATE_HEART_CANDY_7     = 26675,
    SPELL_CREATE_HEART_CANDY_8     = 26676
};

std::array<uint32, 8> const CreateHeartCandySpells =
{
    SPELL_CREATE_HEART_CANDY_1, SPELL_CREATE_HEART_CANDY_2, SPELL_CREATE_HEART_CANDY_3, SPELL_CREATE_HEART_CANDY_4,
    SPELL_CREATE_HEART_CANDY_5, SPELL_CREATE_HEART_CANDY_6, SPELL_CREATE_HEART_CANDY_7, SPELL_CREATE_HEART_CANDY_8
};

// 26678 - Create Heart Candy
class spell_love_is_in_the_air_create_heart_candy : public SpellScript
{
    PrepareSpellScript(spell_love_is_in_the_air_create_heart_candy);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(CreateHeartCandySpells);
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->CastSpell(GetCaster(), Trinity::Containers::SelectRandomContainerElement(CreateHeartCandySpells), true);
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_love_is_in_the_air_create_heart_candy::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_event_love_is_in_the_air()
{
    RegisterSpellScript(spell_love_is_in_the_air_romantic_picnic);
    RegisterSpellScript(spell_love_is_in_the_air_create_heart_candy);
}
