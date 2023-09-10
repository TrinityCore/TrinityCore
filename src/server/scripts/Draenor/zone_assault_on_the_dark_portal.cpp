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

#include "PhasingHandler.h"
#include "Player.h"
#include "QuestDef.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"

enum AssaultOnTheDarkPortalSpells
{
    SPELL_DARK_PORTAL_RUN_AWAY = 158985
};

// 621 - Dark Portal: Run away
class scene_dark_portal_run_away : public SceneScript
{
public:
    scene_dark_portal_run_away() : SceneScript("scene_dark_portal_run_away") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->RemoveAurasDueToSpell(SPELL_DARK_PORTAL_RUN_AWAY);
        PhasingHandler::OnConditionChange(player);
    }
};

// 34420 - The Cost of War
class quest_the_cost_of_war : public QuestScript
{
public:
    quest_the_cost_of_war() : QuestScript("quest_the_cost_of_war") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_NONE)
        {
            player->RemoveAurasDueToSpell(SPELL_DARK_PORTAL_RUN_AWAY);
            PhasingHandler::OnConditionChange(player);
        }
        else if (newStatus == QUEST_STATUS_INCOMPLETE)
        {
            player->CastSpell(player, SPELL_DARK_PORTAL_RUN_AWAY, TRIGGERED_FULL_MASK);
            PhasingHandler::OnConditionChange(player);
        }
    }
};

void AddSC_assault_on_the_dark_portal()
{
    new scene_dark_portal_run_away();
    new quest_the_cost_of_war();
};
