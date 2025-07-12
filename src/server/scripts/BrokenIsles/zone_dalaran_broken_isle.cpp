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
#include "Conversation.h"
#include "ConversationAI.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "PlayerChoice.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"

enum OrderCampaignDalaranIntro
{
    // Quest
    QUEST_AN_IMPORTANT_MISSION              = 42814,
    QUEST_A_DESPERATE_PLEA                  = 41052,
    QUEST_FELSTORMS_PLEA                    = 41035,
    QUEST_NEEDS_OF_THE_HUNTER               = 40384,
    QUEST_CALL_OF_THE_UNCROWNED             = 40832,
    QUEST_PRIESTLY_MATTERS                  = 40705,
    QUEST_THE_SIXTH                         = 40716,
    QUEST_AN_URGENT_GATHERING               = 38710,
    QUEST_A_SUMMONS_FROM_MOONGLADE          = 40643,
    QUEST_BEFORE_THE_STORM                  = 12103,
    QUEST_CALL_OF_THE_ILLIDARI_ALTRUIS      = 39047,
    QUEST_CALL_OF_THE_ILLIDARI_JAYCE        = 39261,
    QUEST_THE_CALL_TO_WAR                   = 40714,

    // Tracking Quests DH
    QUEST_A_NEW_DIRECTION_ALTRUIS           = 40375,
    QUEST_A_NEW_DIRECTION_JAYCE             = 40374,

    // Mage
    SPELL_MAGE_ORDER_FORMATION              = 195356,

    // Death Knight
    SPELL_AN_AUDIENCE_WITH_THE_KING         = 200023,

    // Summon Spells
    SPELL_SUMMON_DALTON_WARRIOR             = 216497,
    SPELL_SUMMON_EITRIGG_WARRIOR            = 216443,
    SPELL_SUMMON_SNOWFEATHER_HUNTER         = 196908,
    SPELL_SUMMON_RAVENHOLDT_COURIER_ROGUE   = 201208,
    SPELL_A_SUMMON_MESSENGER_PRIEST         = 202051,
    SPELL_H_SUMMON_MESSENGER_PRIEST         = 226409,
    SPELL_SUMMON_RYSSTINS_PORTAL_WARLOCK    = 204858,
    SPELL_SUMMON_RYSSTINS_WARLOCK           = 204860,
    SPELL_SUMMON_MAXWELL_TYROSUS_PALADIN    = 190886,
    SPELL_SUMMON_DA_NEL_MONK                = 193978,
    SPELL_SUMMON_KORVAS_DH                  = 195286,
    SPELL_SUMMON_RUNETOTEM_DRUID            = 199277
};

// 224240 - 7.0 Order Campaign - Dalaran Aura
class spell_dalaran_order_campaign_intro_aura : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/) const
    {
        Player* player = Object::ToPlayer(GetCaster());
        if (!player)
            return;

        switch (player->GetClass())
        {
            case CLASS_WARRIOR:
            {
                if (player->GetTeamId() == TEAM_ALLIANCE && player->GetQuestStatus(QUEST_AN_IMPORTANT_MISSION) == QUEST_STATUS_NONE)
                    player->CastSpell(nullptr, SPELL_SUMMON_DALTON_WARRIOR, true);
                else if (player->GetTeamId() == TEAM_HORDE && player->GetQuestStatus(QUEST_A_DESPERATE_PLEA) == QUEST_STATUS_NONE)
                    player->CastSpell(nullptr, SPELL_SUMMON_EITRIGG_WARRIOR, true);
                break;
            }
            case CLASS_HUNTER:
            {
                if (player->GetQuestStatus(QUEST_NEEDS_OF_THE_HUNTER) == QUEST_STATUS_NONE)
                    player->CastSpell(nullptr, SPELL_SUMMON_SNOWFEATHER_HUNTER, true);
                break;
            }
            case CLASS_MAGE:
            {
                if (player->GetQuestStatus(QUEST_FELSTORMS_PLEA) == QUEST_STATUS_NONE)
                    player->CastSpell(nullptr, SPELL_MAGE_ORDER_FORMATION, true);
                break;
            }
            case CLASS_ROGUE:
            {
                if (player->GetQuestStatus(QUEST_CALL_OF_THE_UNCROWNED) == QUEST_STATUS_NONE)
                    player->CastSpell(nullptr, SPELL_SUMMON_RAVENHOLDT_COURIER_ROGUE, true);
                break;
            }
            case CLASS_PRIEST:
            {
                if (player->GetTeamId() == TEAM_ALLIANCE && player->GetQuestStatus(QUEST_PRIESTLY_MATTERS) == QUEST_STATUS_NONE)
                    player->CastSpell(nullptr, SPELL_A_SUMMON_MESSENGER_PRIEST, true);
                else if (player->GetTeamId() == TEAM_HORDE && player->GetQuestStatus(QUEST_PRIESTLY_MATTERS) == QUEST_STATUS_NONE)
                    player->CastSpell(nullptr, SPELL_H_SUMMON_MESSENGER_PRIEST, true);
                break;
            }
            case CLASS_WARLOCK:
            {
                if (player->GetQuestStatus(QUEST_THE_SIXTH) == QUEST_STATUS_NONE)
                    player->CastSpell(nullptr, SPELL_SUMMON_RYSSTINS_PORTAL_WARLOCK, true);
                break;
            }
            case CLASS_PALADIN:
            {
                if (player->GetQuestStatus(QUEST_AN_URGENT_GATHERING) == QUEST_STATUS_NONE)
                    player->CastSpell(nullptr, SPELL_SUMMON_MAXWELL_TYROSUS_PALADIN, true);
                break;
            }
            case CLASS_DRUID:
            {
                if (player->GetQuestStatus(QUEST_A_SUMMONS_FROM_MOONGLADE) == QUEST_STATUS_NONE)
                    player->CastSpell(nullptr, SPELL_SUMMON_RUNETOTEM_DRUID, true);
                break;
            }
            case CLASS_MONK:
            {
                if (player->GetQuestStatus(QUEST_BEFORE_THE_STORM) == QUEST_STATUS_NONE)
                    player->CastSpell(nullptr, SPELL_SUMMON_DA_NEL_MONK, true);
                break;
            }
            case CLASS_DEMON_HUNTER:
            {
                if (player->GetQuestStatus(QUEST_CALL_OF_THE_ILLIDARI_ALTRUIS) == QUEST_STATUS_NONE && player->GetQuestStatus(QUEST_A_NEW_DIRECTION_ALTRUIS) == QUEST_STATUS_REWARDED)
                    player->CastSpell(nullptr, SPELL_SUMMON_KORVAS_DH, true);
                else if (player->GetQuestStatus(QUEST_CALL_OF_THE_ILLIDARI_JAYCE) == QUEST_STATUS_NONE && player->GetQuestStatus(QUEST_A_NEW_DIRECTION_JAYCE) == QUEST_STATUS_REWARDED)
                    player->CastSpell(nullptr, SPELL_SUMMON_KORVAS_DH, true);
                break;
            }
            case CLASS_DEATH_KNIGHT:
            {
                if (player->GetQuestStatus(QUEST_THE_CALL_TO_WAR) == QUEST_STATUS_NONE)
                    player->CastSpell(nullptr, SPELL_AN_AUDIENCE_WITH_THE_KING, true);
                break;
            }
            default:
                break;
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_dalaran_order_campaign_intro_aura::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

enum WeaponsOfLegendHunter
{
    // Spells
    SPELL_FORCE_BEAST_MASTERY_SPEC                      = 198433,
    SPELL_FORCE_SURVIVAL_SPEC                           = 198435,
    SPELL_FORCE_MARKSMANSHIP_SPEC                       = 198436,

    // Playerchoice
    PLAYERCHOICE_RESPONSE_CHOOSE_BEAST_MASTERY_WEAPON   = 504,
    PLAYERCHOICE_RESPONSE_CHOOSE_SURVIVAL_WEAPON        = 505,
    PLAYERCHOICE_RESPONSE_CHOOSE_MARKSMANSHIP_WEAPON    = 506,
};

// 240 - Playerchoice
class playerchoice_weapons_of_legend_hunter : public PlayerChoiceScript
{
public:
    playerchoice_weapons_of_legend_hunter() : PlayerChoiceScript("playerchoice_weapons_of_legend_hunter") {}

    void OnResponse(WorldObject* /*object*/, Player* player, PlayerChoice const* /*choice*/, PlayerChoiceResponse const* response, uint16 /*clientIdentifier*/) override
    {
        if (response->ResponseId == PLAYERCHOICE_RESPONSE_CHOOSE_BEAST_MASTERY_WEAPON)
            player->CastSpell(player, SPELL_FORCE_BEAST_MASTERY_SPEC, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
        else if (response->ResponseId == PLAYERCHOICE_RESPONSE_CHOOSE_SURVIVAL_WEAPON)
            player->CastSpell(player, SPELL_FORCE_SURVIVAL_SPEC, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
        else if (response->ResponseId == PLAYERCHOICE_RESPONSE_CHOOSE_MARKSMANSHIP_WEAPON)
            player->CastSpell(player, SPELL_FORCE_MARKSMANSHIP_SPEC, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
    }
};

enum CallOfTheUncrownedData
{
    NPC_SUMMON_RAVENHOLD_COURIER    = 102018,

    CONVO_ACTOR_SUMMON_COURIER      = 51066,

    SPELL_SEALED_LETTER_CREDIT      = 201264
};

// 1100 - Conversation
class conversation_on_summon_call_of_the_uncrowned : public ConversationAI
{
public:
    using ConversationAI::ConversationAI;

    void OnCreate(Unit* creator) override
    {
        Creature* ravenholdCurier = creator->FindNearestCreatureWithOptions(20.0f, { .CreatureId = NPC_SUMMON_RAVENHOLD_COURIER, .IgnorePhases = true, .OwnerGuid = creator->GetGUID() });
        if (!ravenholdCurier)
            return;

        conversation->AddActor(CONVO_ACTOR_SUMMON_COURIER, 0, ravenholdCurier->GetGUID());
        conversation->Start();
    }
};

// 201253 - Sealed Letter
class spell_dalaran_sealed_letter : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/) const
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        GetCaster()->CastSpell(GetCaster(), SPELL_SEALED_LETTER_CREDIT, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_dalaran_sealed_letter::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_zone_dalaran_broken_isle()
{
    // Conversation
    RegisterConversationAI(conversation_on_summon_call_of_the_uncrowned);

    // Playerchoice
    new playerchoice_weapons_of_legend_hunter();

    // Spellscripts
    RegisterSpellScript(spell_dalaran_order_campaign_intro_aura);
    RegisterSpellScript(spell_dalaran_sealed_letter);
}
