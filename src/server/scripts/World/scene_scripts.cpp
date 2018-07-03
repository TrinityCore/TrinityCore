/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

void AddSC_scene_scripts()
{
    new scene_deathwing_simulator();
}
