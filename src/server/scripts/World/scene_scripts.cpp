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

enum SceneSpells
{
    SPELL_DEATHWING_SIMULATOR = 201184
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

enum AllianceHordeShipSceneSpells
{
    SPELL_BEGIN_TUTORIAL = 295600,
    SPELL_KNOCKED_DOWN   = 305445,
    SPELL_CRASHED_LANDED = 325136
};

class scene_alliance_and_horde_ship : public SceneScript
{
public:
    scene_alliance_and_horde_ship() : SceneScript("scene_alliance_and_horde_ship") { }

    virtual void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_BEGIN_TUTORIAL, true);
    }
};

class scene_alliance_and_horde_crash : public SceneScript
{
public:
    scene_alliance_and_horde_crash() : SceneScript("scene_alliance_and_horde_crash") { }

    void OnSceneTriggerEvent(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/, std::string const& triggerName) override
    {
        if (triggerName == "Begin Knockdown Aura")
            player->CastSpell(player, SPELL_KNOCKED_DOWN, true);
    }

    virtual void OnSceneComplete(Player* player, uint32 /*sceneInstanceID*/, SceneTemplate const* /*sceneTemplate*/) override
    {
        player->CastSpell(player, SPELL_CRASHED_LANDED, true);
    }
};

void AddSC_scene_scripts()
{
    new scene_deathwing_simulator();
    new scene_alliance_and_horde_ship();
    new scene_alliance_and_horde_crash();
}
