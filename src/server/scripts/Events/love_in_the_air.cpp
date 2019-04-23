/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

#include "AchievementMgr.h"
#include "ScriptMgr.h"
#include "ScriptedEscortAI.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "Unit.h"
#include "Player.h"
#include "World.h"
#include "GameEventMgr.h"

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
                if (target->GetStandState() != UNIT_STAND_STATE_SIT)
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
                target->GetPlayerListInGrid(playerList, INTERACTION_DISTANCE * 2);

                for (std::list<Player*>::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                {
                    if ((*itr) != target && (*itr)->HasAura(GetId())) // && (*itr)->getStandState() == UNIT_STAND_STATE_SIT)
                    {
                        if (caster)
                        {
                            if (!caster->HasAura(SPELL_ROMANTIC_PICNIC_ACHIEV))
                            {
                                caster->CastSpell(*itr, SPELL_ROMANTIC_PICNIC_ACHIEV, true);

                                if (caster->ToPlayer() && caster->GetZoneId() == 4395) // Dalaran
                                    caster->ToPlayer()->GetAchievementMgr()->CompletedAchievement(sAchievementStore.LookupEntry(1291), nullptr); // Lonely?
                            }

                            if (!target->HasAura(SPELL_ROMANTIC_PICNIC_ACHIEV))
                            {
                                caster->CastSpell(target, SPELL_ROMANTIC_PICNIC_ACHIEV, true);

                                if (target->ToPlayer() && target->GetZoneId() == 4395) // Dalaran
                                    target->ToPlayer()->GetAchievementMgr()->CompletedAchievement(sAchievementStore.LookupEntry(1291), nullptr); // Lonely?
                            }
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

class PlayerScript_event_love_int_the_air_lovely_charm : public PlayerScript
{
public:
    PlayerScript_event_love_int_the_air_lovely_charm() :PlayerScript("PlayerScript_event_love_int_the_air_lovely_charm") {}

    enum Values
    {
        EVENT_LOVE_IN_THE_AIR           = 8,
        ITEM_LOVELY_CHARM_COLLECTOR_KIT = 49661,
        SPELL_CREATE_LOVELY_CHARM       = 69511
    };

    void OnCreatureKill(Player* p_Killer, Creature* p_Killed) override
    {
        if (!sGameEventMgr->IsActiveEvent(EVENT_LOVE_IN_THE_AIR))
            return;

        if (!p_Killer->HasItemCount(ITEM_LOVELY_CHARM_COLLECTOR_KIT, 1))
            return;

        uint32 chance = 0;

        switch (p_Killed->GetCreatureTemplate()->RequiredExpansion)
        {
            case EXPANSION_WARLORDS_OF_DRAENOR:
                chance = 75;
                break;
            case EXPANSION_MISTS_OF_PANDARIA:
                chance = 25;
                break;
            default:
                return;
        }

        if (urand(1, 100) > chance)
            return;

        p_Killer->CastSpell(p_Killer, SPELL_CREATE_LOVELY_CHARM, true);
    }
};

void AddSC_event_love_in_the_air()
{
    new spell_love_is_in_the_air_romantic_picnic();
    new PlayerScript_event_love_int_the_air_lovely_charm();
}
