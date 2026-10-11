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
#include "Player.h"
#include "PlayerChoice.h"

enum ALegendYouCanHoldPriest
{
    // Spells
    SPELL_FORCE_HOLY_SPEC                               = 199701,
    SPELL_FORCE_SHADOW_SPEC                             = 199703,
    SPELL_FORCE_DISCIPLINE_SPEC                         = 199704,
    SPELL_PLAYERCHOICE_REMOVE_TRACKING_QUESTS_PRIEST    = 199699,

    // Playerchoices
    PLAYERCHOICE_RESPONSE_CHOOSE_HOLY_WEAPON            = 532,
    PLAYERCHOICE_RESPONSE_CHOOSE_SHADOW_WEAPON          = 533,
    PLAYERCHOICE_RESPONSE_CHOOSE_DISCIPLINE             = 534
};

// 248 - Playerchoice
class playerchoice_a_weapon_you_can_hold_priest : public PlayerChoiceScript
{
public:
    playerchoice_a_weapon_you_can_hold_priest() : PlayerChoiceScript("playerchoice_a_weapon_you_can_hold_priest") {}

    void OnResponse(WorldObject* /*object*/, Player* player, PlayerChoice const* /*choice*/, PlayerChoiceResponse const* response, uint16 /*clientIdentifier*/)
    {
        if (response->ResponseId == PLAYERCHOICE_RESPONSE_CHOOSE_HOLY_WEAPON)
            player->CastSpell(player, SPELL_FORCE_HOLY_SPEC, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
        else if (response->ResponseId == PLAYERCHOICE_RESPONSE_CHOOSE_SHADOW_WEAPON)
            player->CastSpell(player, SPELL_FORCE_SHADOW_SPEC, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
        else if (response->ResponseId == PLAYERCHOICE_RESPONSE_CHOOSE_DISCIPLINE)
            player->CastSpell(player, SPELL_FORCE_DISCIPLINE_SPEC, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
    }
};

// 40706 - A Legend You Can Hold
class quest_a_legend_you_can_hold : public QuestScript
{
public:
    quest_a_legend_you_can_hold() : QuestScript("quest_a_legend_you_can_hold") {}

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_NONE)
            player->CastSpell(player, SPELL_PLAYERCHOICE_REMOVE_TRACKING_QUESTS_PRIEST, CastSpellExtraArgsInit{ .TriggerFlags = TRIGGERED_FULL_MASK });
    }
};

void AddSC_tirisfal_glades()
{
    // Playerchoice
    new playerchoice_a_weapon_you_can_hold_priest();

    // Quest
    new quest_a_legend_you_can_hold();
}
