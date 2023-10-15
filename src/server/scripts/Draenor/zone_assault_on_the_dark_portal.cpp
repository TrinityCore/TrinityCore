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
    SPELL_BLEEDING_HOLLOW_HOLDOUT        = 164609,
    SPELL_BLEEDING_HOLLOW_TRAIL_OF_FLAME = 164611,
    SPELL_CANCEL_TRAIL_OF_FLAME_VISUAL   = 165993,
    SPELL_DARK_PORTAL_RUN_AWAY           = 158985,
    SPELL_HUT_CREDIT                     = 164613, // Serverside Spell
    SPELL_PUSH_ARMY                      = 165072,
    SPELL_TRAIL_OF_FLAME_LARGE           = 165991
};

enum AssaultOnTheDarkPortalQuests
{
    QUEST_FLAG_ARMY_PUSHED        = 35297
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

// 34422 - Blaze of Glory
class quest_blaze_of_glory : public QuestScript
{
public:
    quest_blaze_of_glory() : QuestScript("quest_blaze_of_glory") { }

    void OnQuestStatusChange(Player* player, Quest const* /*quest*/, QuestStatus /*oldStatus*/, QuestStatus newStatus) override
    {
        if (newStatus == QUEST_STATUS_NONE)
        {
            player->RemoveAurasDueToSpell(SPELL_BLEEDING_HOLLOW_HOLDOUT);
            player->RemoveAurasDueToSpell(SPELL_BLEEDING_HOLLOW_TRAIL_OF_FLAME);
            player->RemoveAurasDueToSpell(SPELL_PUSH_ARMY);
            player->RemoveRewardedQuest(QUEST_FLAG_ARMY_PUSHED);
            PhasingHandler::OnConditionChange(player);
        }
        else if (newStatus == QUEST_STATUS_INCOMPLETE)
            PhasingHandler::OnConditionChange(player);
        else if (newStatus == QUEST_STATUS_COMPLETE)
            player->RemoveAurasDueToSpell(SPELL_BLEEDING_HOLLOW_TRAIL_OF_FLAME);
    }
};

// 770 - Bleeding Hollow: Holdout
class scene_bleeding_hollow_holdout : public SceneScript
{
public:
    scene_bleeding_hollow_holdout() : SceneScript("scene_bleeding_hollow_holdout") { }

    void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->RemoveAurasDueToSpell(SPELL_BLEEDING_HOLLOW_HOLDOUT);
        PhasingHandler::OnConditionChange(player);
    }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "Push")
            player->CastSpell(player, SPELL_PUSH_ARMY, false);
    }
};

// 771 - Bleeding Hollow: Trail of Flame
class scene_bleeding_hollow_trail_of_flame : public SceneScript
{
    public:
        scene_bleeding_hollow_trail_of_flame() : SceneScript("scene_bleeding_hollow_trail_of_flame") { }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "Visual")
            player->CastSpell(player, SPELL_TRAIL_OF_FLAME_LARGE, true);
        else if (triggerName == "Clear")
            player->CastSpell(player, SPELL_CANCEL_TRAIL_OF_FLAME_VISUAL, true);
        else if (triggerName == "Credit")
            player->CastSpell(player, SPELL_HUT_CREDIT, true);
    }
};

void AddSC_assault_on_the_dark_portal()
{
    new scene_dark_portal_run_away();
    new quest_the_cost_of_war();
    new quest_blaze_of_glory();
    new scene_bleeding_hollow_holdout();
    new scene_bleeding_hollow_trail_of_flame();
};
