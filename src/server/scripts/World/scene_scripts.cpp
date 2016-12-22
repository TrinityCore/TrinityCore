/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

enum SceneSpells
{
    SPELL_DEATHWING_SIMULATOR = 201184
};

enum SceneQuests
{
    START_DEMON_HUNTER_TRACKING_EVENT = 40076
};

enum SceneCreatures
{
    SEE_FELSABER_QUEST_KILL_CREDIT = 101534
};

class scene_deathwing_simulator : public SceneScript
{
    public:
        scene_deathwing_simulator() : SceneScript("scene_deathwing_simulator") { }

    // Called when a player receive trigger from scene
    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "BURN PLAYER")
            player->CastSpell(player, SPELL_DEATHWING_SIMULATOR, true); // Deathwing Simulator Burn player
    }
};

class scene_demon_hunter_start : public SceneScript
{
public:
    scene_demon_hunter_start() : SceneScript("scene_demon_hunter_start") { }

    void OnSceneStart(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        Quest const* quest = sObjectMgr->GetQuestTemplate(START_DEMON_HUNTER_TRACKING_EVENT);
        if (!quest)
            return;
        
        if (!player->GetQuestRewardStatus(START_DEMON_HUNTER_TRACKING_EVENT))
            player->AddQuestAndCheckCompletion(quest, NULL);
        else
            return;
    }
    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "CUEILLIDANTH")
            // Illidan Conversation
            return;
    }
};

class scene_the_invasion_begins_banner : public SceneScript
{
public:
    scene_the_invasion_begins_banner() : SceneScript("scene_the_invasion_begins_banner") { }

    void OnSceneComplete(Player* player, uint32 sceneInstanceID, SceneTemplate const* sceneTemplate)
    {
        // Cinematic Scenes will cause Black Screen if not canceled
        OnSceneCancel(player, sceneInstanceID, sceneTemplate);
        player->UpdateAreaAndZonePhase();
    }
};

class scene_enter_the_illidari_ashtongue : public SceneScript
{
public:
    scene_enter_the_illidari_ashtongue() : SceneScript("scene_enter_the_illidari_ashtongue") { }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "SEEFELSABERCREDIT")
            player->KilledMonsterCredit(SEE_FELSABER_QUEST_KILL_CREDIT);
        if (triggerName == "UPDATEPHASE")
            player->UpdateAreaAndZonePhase();
    }
};

class scene_meeting_with_the_queen : public SceneScript
{
public:
    scene_meeting_with_the_queen() : SceneScript("scene_meeting_with_the_queen") { }

    void OnSceneComplete(Player* player, uint32 sceneInstanceID, SceneTemplate const* sceneTemplate)
    {
        // Cinematic Scenes will cause Black Screen if not canceled
        OnSceneCancel(player, sceneInstanceID, sceneTemplate);
    }
};

void AddSC_scene_scripts()
{
    new scene_deathwing_simulator();
    new scene_demon_hunter_start();
    new scene_the_invasion_begins_banner();
    new scene_enter_the_illidari_ashtongue();
    new scene_meeting_with_the_queen();
}
