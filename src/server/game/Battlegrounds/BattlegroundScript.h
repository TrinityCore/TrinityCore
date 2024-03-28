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

#ifndef TRINITY_BATTLEGROUND_SCRIPT_H
#define TRINITY_BATTLEGROUND_SCRIPT_H

#include "SharedDefines.h"
#include "ZoneScript.h"

#ifdef TRINITY_API_USE_DYNAMIC_LINKING
#include <memory>
#endif

class Battleground;
class BattlegroundMap;
class ModuleReference;

class TC_GAME_API BattlegroundScript : public ZoneScript
{
public:
    explicit BattlegroundScript(BattlegroundMap* map);
    ~BattlegroundScript() override = default;

    virtual void OnInit() { }
    virtual void OnUpdate([[maybe_unused]] uint32 diff) { }
    virtual void OnPrepareStage1() { }
    virtual void OnPrepareStage2() { }
    virtual void OnPrepareStage3() { }
    virtual void OnStart() { }
    virtual void OnEnd([[maybe_unused]] Team winner) { }
    virtual void OnPlayerJoined([[maybe_unused]] Player* player, [[maybe_unused]] bool inBattleground) { }
    virtual void OnPlayerLeft([[maybe_unused]] Player* player) { }
    virtual void OnPlayerKilled([[maybe_unused]] Player* victim, [[maybe_unused]] Player* killer) { }
    virtual void OnUnitKilled([[maybe_unused]] Creature* victim, [[maybe_unused]] Unit* killer) { }
    virtual Team GetPrematureWinner();

    void TriggerGameEvent(uint32 gameEventId, WorldObject* source = nullptr, WorldObject* target = nullptr) override;

protected:
    void UpdateWorldState(int32 worldStateId, int32 value, bool hidden = false) const;

    BattlegroundMap* battlegroundMap;
    Battleground* battleground;

private:
#ifdef TRINITY_API_USE_DYNAMIC_LINKING
    // Strong reference to the associated script module
    std::shared_ptr<ModuleReference> module_reference;
#endif // #ifndef TRINITY_API_USE_DYNAMIC_LINKING
};

class TC_GAME_API ArenaScript : public BattlegroundScript
{
public:
    explicit ArenaScript(BattlegroundMap* map);
    ~ArenaScript() override = default;

protected:
    GameObject* CreateObject(uint32 entry, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3, GOState goState = GO_STATE_READY) const;
    Creature* CreateCreature(uint32 entry, float x, float y, float z, float o) const;
};

#endif // TRINITY_BATTLEGROUND_SCRIPT_H
