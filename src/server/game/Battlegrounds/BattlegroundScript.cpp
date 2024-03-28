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

#include "BattlegroundScript.h"
#include "BattlegroundMgr.h"
#include "Creature.h"
#include "GameEventSender.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "WorldStateMgr.h"

BattlegroundScript::BattlegroundScript(BattlegroundMap* map) : battlegroundMap(map), battleground(map->GetBG())
{
#ifdef TRINITY_API_USE_DYNAMIC_LINKING
    BattlegroundScriptTemplate const* scriptTemplate = sBattlegroundMgr->FindBattlegroundScriptTemplate(battlegroundMap->GetId(), battlegroundMap->GetBG()->GetTypeID());
    if (!scriptTemplate)
        return;

    auto const scriptname = sObjectMgr->GetScriptName(scriptTemplate->ScriptId);
    ASSERT(!scriptname.empty());
    // Acquire a strong reference from the script module
    // to keep it loaded until this object is destroyed.
    module_reference = sScriptMgr->AcquireModuleReferenceOfScriptName(scriptname);
#endif // #ifndef TRINITY_API_USE_DYNAMIC_LINKING
}

Team BattlegroundScript::GetPrematureWinner()
{
    Team winner = TEAM_OTHER;
    if (battleground->GetPlayersCountByTeam(ALLIANCE) >= battleground->GetMinPlayersPerTeam())
        winner = ALLIANCE;
    else if (battleground->GetPlayersCountByTeam(HORDE) >= battleground->GetMinPlayersPerTeam())
        winner = HORDE;

    return winner;
}

void BattlegroundScript::TriggerGameEvent(uint32 gameEventId, WorldObject* source, WorldObject* target)
{
    ProcessEvent(target, gameEventId, source);
    GameEvents::TriggerForMap(gameEventId, battlegroundMap, source, target);
    for (auto const& [playerGuid, _] : battleground->GetPlayers())
        if (Player* player = ObjectAccessor::FindPlayer(playerGuid))
            GameEvents::TriggerForPlayer(gameEventId, player);
}

void BattlegroundScript::UpdateWorldState(int32 worldStateId, int32 value, bool hidden) const
{
    sWorldStateMgr->SetValue(worldStateId, value, hidden, battlegroundMap);
}

ArenaScript::ArenaScript(BattlegroundMap* map) : BattlegroundScript(map)
{

}

GameObject* ArenaScript::CreateObject(uint32 entry, float x, float y, float z, float o, float rotation0, float rotation1, float rotation2, float rotation3, GOState goState) const
{
    QuaternionData rot(rotation0, rotation1, rotation2, rotation3);
    // Temporally add safety check for bad spawns and send log (object rotations need to be rechecked in sniff)
    if (!rotation0 && !rotation1 && !rotation2 && !rotation3)
    {
        TC_LOG_DEBUG("bg.battleground", "Battleground::AddObject: gameoobject [entry: {}] for BG (map: {}) has zeroed rotation fields, "
            "orientation used temporally, but please fix the spawn", entry, battlegroundMap->GetId());

        rot = QuaternionData::fromEulerAnglesZYX(o, 0.f, 0.f);
    }

    // Must be created this way, adding to godatamap would add it to the base map of the instance
    // and when loading it (in go::LoadFromDB()), a new guid would be assigned to the object, and a new object would be created
    // So we must create it specific for this instance
    GameObject* go = GameObject::CreateGameObject(entry, battlegroundMap, Position(x, y, z, o), rot, 255, goState);
    if (!go)
    {
        TC_LOG_ERROR("bg.battleground", "Battleground::AddObject: cannot create gameobject (entry: {}) for BG (map: {}, instance id: {})!",
            entry, battlegroundMap->GetId(), battleground->GetInstanceID());
        return nullptr;
    }

    if (!battlegroundMap->AddToMap(go))
    {
        delete go;
        return nullptr;
    }

    return go;
}

Creature* ArenaScript::CreateCreature(uint32 entry, float x, float y, float z, float o) const
{
    if (!sObjectMgr->GetCreatureTemplate(entry))
    {
        TC_LOG_ERROR("bg.battleground", "Battleground::AddCreature: creature template (entry: {}) does not exist for BG (map: {}, instance id: {})!",
            entry, battlegroundMap->GetId(), battleground->GetInstanceID());
        return nullptr;
    }

    Position pos = { x, y, z, o };

    Creature* creature = Creature::CreateCreature(entry, battlegroundMap, pos);
    if (!creature)
    {
        TC_LOG_ERROR("bg.battleground", "Battleground::AddCreature: cannot create creature (entry: {}) for BG (map: {}, instance id: {})!",
            entry, battlegroundMap->GetId(), battleground->GetInstanceID());
        return nullptr;
    }

    creature->SetHomePosition(pos);

    if (!battlegroundMap->AddToMap(creature))
    {
        delete creature;
        return nullptr;
    }

    return creature;
}
