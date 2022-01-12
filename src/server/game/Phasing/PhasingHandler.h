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

#ifndef PhasingHandler_h__
#define PhasingHandler_h__

#include "Define.h"
#include <string>
#include <vector>

class ChatHandler;
class Map;
class ObjectGuid;
class PhaseShift;
class Player;
class WorldObject;
namespace WorldPackets
{
    namespace Party
    {
        struct PartyMemberPhaseStates;
    }
}

class TC_GAME_API PhasingHandler
{
public:
    static void AddPhase(WorldObject* object, uint32 phaseId, bool updateVisibility);
    static void RemovePhase(WorldObject* object, uint32 phaseId, bool updateVisibility);
    static void AddPhaseGroup(WorldObject* object, uint32 phaseGroupId, bool updateVisibility);
    static void RemovePhaseGroup(WorldObject* object, uint32 phaseGroupId, bool updateVisibility);

    static void AddVisibleMapId(WorldObject* object, uint32 visibleMapId);
    static void RemoveVisibleMapId(WorldObject* object, uint32 visibleMapId);

    static void ResetPhaseShift(WorldObject* object);
    static void InheritPhaseShift(WorldObject* target, WorldObject const* source);

    static void OnMapChange(WorldObject* object);
    static void OnAreaChange(WorldObject* object);
    static void OnConditionChange(WorldObject* object);

    static void SendToPlayer(Player const* player, PhaseShift const& phaseShift);
    static void SendToPlayer(Player const* player);
    static void FillPartyMemberPhase(WorldPackets::Party::PartyMemberPhaseStates* partyMemberPhases, PhaseShift const& phaseShift);

    static PhaseShift const& GetEmptyPhaseShift();
    static void InitDbPhaseShift(PhaseShift& phaseShift, uint8 phaseUseFlags, uint16 phaseId, uint32 phaseGroupId);
    static void InitDbPersonalOwnership(PhaseShift& phaseShift, ObjectGuid const& personalGuid);
    static void InitDbVisibleMapId(PhaseShift& phaseShift, int32 visibleMapId);
    static bool InDbPhaseShift(WorldObject const* object, uint8 phaseUseFlags, uint16 phaseId, uint32 phaseGroupId);

    static uint32 GetTerrainMapId(PhaseShift const& phaseShift, Map const* map, float x, float y);

    static void SetAlwaysVisible(WorldObject* object, bool apply, bool updateVisibility);
    static void SetInversed(WorldObject* object, bool apply, bool updateVisibility);

    static void PrintToChat(ChatHandler* chat, WorldObject const* target);
    static std::string FormatPhases(PhaseShift const& phaseShift);

    static bool IsPersonalPhase(uint32 phaseId);

private:
    class ControlledUnitVisitor;
    friend ControlledUnitVisitor;

    static void AddPhase(WorldObject* object, uint32 phaseId, ObjectGuid const& personalGuid, bool updateVisibility, ControlledUnitVisitor& visitor);
    static void RemovePhase(WorldObject* object, uint32 phaseId, bool updateVisibility, ControlledUnitVisitor& visitor);
    static void AddPhaseGroup(WorldObject* object, std::vector<uint32> const* phasesInGroup, ObjectGuid const& personalGuid, bool updateVisibility, ControlledUnitVisitor& visitor);
    static void RemovePhaseGroup(WorldObject* object, std::vector<uint32> const* phasesInGroup, bool updateVisibility, ControlledUnitVisitor& visitor);
    static void AddVisibleMapId(WorldObject* object, uint32 visibleMapId, ControlledUnitVisitor& visitor);
    static void RemoveVisibleMapId(WorldObject* object, uint32 visibleMapId, ControlledUnitVisitor& visitor);
    static void UpdateVisibilityIfNeeded(WorldObject* object, bool updateVisibility, bool changed);
};

#endif // PhasingHandler_h__
