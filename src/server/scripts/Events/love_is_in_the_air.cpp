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

/*######
## Item 21813: Bag of Heart Candies
######*/

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
        GetCaster()->CastSpell(GetCaster(), Trinity::Containers::SelectRandomContainerElement(CreateHeartCandySpells));
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_love_is_in_the_air_create_heart_candy::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Quest 24536, 24655: Something Stinks
######*/

enum SomethingStinks
{
    SPELL_HEAVILY_PERFUMED     = 71507
};

// 70192 - Fragrant Air Analysis
class spell_love_is_in_the_air_fragrant_air_analysis : public SpellScript
{
    PrepareSpellScript(spell_love_is_in_the_air_fragrant_air_analysis);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(uint32(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_love_is_in_the_air_fragrant_air_analysis::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 71507 - Heavily Perfumed
class spell_love_is_in_the_air_heavily_perfumed : public AuraScript
{
    PrepareAuraScript(spell_love_is_in_the_air_heavily_perfumed);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), uint32(GetEffectInfo(EFFECT_0).CalcValue()));
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_love_is_in_the_air_heavily_perfumed::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 71508 - Recently Analyzed
class spell_love_is_in_the_air_recently_analyzed : public AuraScript
{
    PrepareAuraScript(spell_love_is_in_the_air_recently_analyzed);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_HEAVILY_PERFUMED });
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->CastSpell(GetTarget(), SPELL_HEAVILY_PERFUMED);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_love_is_in_the_air_recently_analyzed::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

/*######
## Quest 24629, 24635, 24636: A Perfect Puff of Perfume & A Cloudlet of Classy Cologne & Bonbon Blitz
######*/

// 69438 - Sample Satisfaction
class spell_love_is_in_the_air_sample_satisfaction : public AuraScript
{
    PrepareAuraScript(spell_love_is_in_the_air_sample_satisfaction);

    void OnPeriodic(AuraEffect const* /*aurEff*/)
    {
        if (roll_chance_i(30))
            Remove();
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_love_is_in_the_air_sample_satisfaction::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

/*######
## Quest 24541, 24656: Pilfering Perfume
######*/

enum PilferingPerfume
{
    SPELL_SERVICE_UNIFORM       = 71450,

    MODEL_GOBLIN_MALE           = 31002,
    MODEL_GOBLIN_FEMALE         = 31003
};

// 71450 - Crown Parcel Service Uniform
class spell_love_is_in_the_air_service_uniform : public AuraScript
{
    PrepareAuraScript(spell_love_is_in_the_air_service_uniform);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo({ uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()) });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        if (target->GetTypeId() == TYPEID_PLAYER)
        {
            if (target->GetNativeGender() == GENDER_MALE)
                target->SetDisplayId(MODEL_GOBLIN_MALE);
            else
                target->SetDisplayId(MODEL_GOBLIN_FEMALE);
        }
    }

    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->RemoveAurasDueToSpell(uint32(GetEffectInfo(EFFECT_0).CalcValue()));
    }

    void Register() override
    {
        AfterEffectApply += AuraEffectRemoveFn(spell_love_is_in_the_air_service_uniform::AfterApply, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove += AuraEffectRemoveFn(spell_love_is_in_the_air_service_uniform::AfterRemove, EFFECT_0, SPELL_AURA_TRANSFORM, AURA_EFFECT_HANDLE_REAL);
    }
};

// 71522 - Crown Chemical Co. Supplies
// 71539 - Crown Chemical Co. Supplies
class spell_love_is_in_the_air_cancel_service_uniform : public SpellScript
{
    PrepareSpellScript(spell_love_is_in_the_air_cancel_service_uniform);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SERVICE_UNIFORM });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->RemoveAurasDueToSpell(SPELL_SERVICE_UNIFORM);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_love_is_in_the_air_cancel_service_uniform::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

/*######
## Item 49351, 49352: Perfume Neutralizer & Cologne Neutralizer
######*/

// 68529 - Perfume Immune
// 68530 - Cologne Immune
class spell_love_is_in_the_air_perfume_cologne_immune : public SpellScript
{
    PrepareSpellScript(spell_love_is_in_the_air_perfume_cologne_immune);

    bool Validate(SpellInfo const* spellInfo) override
    {
        return ValidateSpellInfo(
        {
            uint32(spellInfo->GetEffect(EFFECT_0).CalcValue()),
            uint32(spellInfo->GetEffect(EFFECT_1).CalcValue())
        });
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        GetCaster()->RemoveAurasDueToSpell(uint32(GetEffectValue()));
    }

    void Register() override
    {
        OnEffectHit += SpellEffectFn(spell_love_is_in_the_air_perfume_cologne_immune::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        OnEffectHit += SpellEffectFn(spell_love_is_in_the_air_perfume_cologne_immune::HandleScript, EFFECT_1, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

void AddSC_event_love_is_in_the_air()
{
    RegisterSpellScript(spell_love_is_in_the_air_romantic_picnic);
    RegisterSpellScript(spell_love_is_in_the_air_create_heart_candy);
    RegisterSpellScript(spell_love_is_in_the_air_fragrant_air_analysis);
    RegisterSpellScript(spell_love_is_in_the_air_heavily_perfumed);
    RegisterSpellScript(spell_love_is_in_the_air_recently_analyzed);
    RegisterSpellScript(spell_love_is_in_the_air_sample_satisfaction);
    RegisterSpellScript(spell_love_is_in_the_air_service_uniform);
    RegisterSpellScript(spell_love_is_in_the_air_cancel_service_uniform);
    RegisterSpellScript(spell_love_is_in_the_air_perfume_cologne_immune);
}
