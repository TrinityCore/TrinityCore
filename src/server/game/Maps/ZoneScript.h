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

#ifndef ZONE_SCRIPT_H_
#define ZONE_SCRIPT_H_

#include "Define.h"
#include "ObjectGuid.h"

class AreaTrigger;
class Creature;
class GameObject;
class Player;
class Unit;
class WorldObject;
struct CreatureData;

enum class FlagState : uint8;

enum class EncounterType : uint8
{
    DungeonEncounter,
    Battleground,
    MythicPlusRun
};

class TC_GAME_API ControlZoneHandler
{
public:
    explicit ControlZoneHandler() = default;
    virtual ~ControlZoneHandler() = default;

    virtual void HandleCaptureEventHorde([[maybe_unused]] GameObject* controlZone) { }
    virtual void HandleCaptureEventAlliance([[maybe_unused]] GameObject* controlZone) { }
    virtual void HandleContestedEventHorde([[maybe_unused]] GameObject* controlZone) { }
    virtual void HandleContestedEventAlliance([[maybe_unused]] GameObject* controlZone) { }
    virtual void HandleProgressEventHorde([[maybe_unused]] GameObject* controlZone) { }
    virtual void HandleProgressEventAlliance([[maybe_unused]] GameObject* controlZone) { }
    virtual void HandleNeutralEventHorde([[maybe_unused]] GameObject* controlZone) { HandleNeutralEvent(controlZone); }
    virtual void HandleNeutralEventAlliance([[maybe_unused]] GameObject* controlZone) { HandleNeutralEvent(controlZone); }
    virtual void HandleNeutralEvent([[maybe_unused]] GameObject* controlZone) { }
};

class TC_GAME_API ZoneScript
{
    public:
        ZoneScript();
        ZoneScript(ZoneScript const& right);
        ZoneScript(ZoneScript&& right) noexcept;
        ZoneScript& operator=(ZoneScript const& right);
        ZoneScript& operator=(ZoneScript&& right) noexcept;
        virtual ~ZoneScript();

        virtual uint32 GetCreatureEntry(ObjectGuid::LowType /*spawnId*/, CreatureData const* data);
        virtual uint32 GetGameObjectEntry(ObjectGuid::LowType /*spawnId*/, uint32 entry) { return entry; }

        virtual void OnCreatureCreate(Creature* ) { }
        virtual void OnCreatureRemove(Creature* ) { }

        virtual void OnGameObjectCreate(GameObject* ) { }
        virtual void OnGameObjectRemove(GameObject* ) { }

        virtual void OnAreaTriggerCreate([[maybe_unused]] AreaTrigger* areaTrigger) { }
        virtual void OnAreaTriggerRemove([[maybe_unused]] AreaTrigger* areaTrigger) { }

        virtual void OnUnitDeath([[maybe_unused]] Unit* unit) { }

        //All-purpose data storage ObjectGuid
        virtual ObjectGuid GetGuidData(uint32 /*DataId*/) const { return ObjectGuid::Empty; }
        virtual void SetGuidData(uint32 /*DataId*/, ObjectGuid /*Value*/) { }

        //All-purpose data storage 64 bit
        virtual uint64 GetData64(uint32 /*DataId*/) const { return 0; }
        virtual void SetData64(uint32 /*DataId*/, uint64 /*Value*/) { }

        //All-purpose data storage 32 bit
        virtual uint32 GetData(uint32 /*DataId*/) const { return 0; }
        virtual void SetData(uint32 /*DataId*/, uint32 /*Value*/) { }

        virtual void TriggerGameEvent(uint32 gameEventId, WorldObject* source = nullptr, WorldObject* target = nullptr);
        virtual void ProcessEvent(WorldObject* /*obj*/, uint32 /*eventId*/, WorldObject* /*invoker*/) { }
        virtual void DoAction([[maybe_unused]] uint32 actionId, [[maybe_unused]] WorldObject* source = nullptr, [[maybe_unused]] WorldObject* target = nullptr) { }

        virtual void OnFlagStateChange([[maybe_unused]] GameObject* flagInBase, [[maybe_unused]] FlagState oldValue, [[maybe_unused]] FlagState newValue, [[maybe_unused]] Player* player) { }

        virtual bool CanCaptureFlag([[maybe_unused]] AreaTrigger* areaTrigger, [[maybe_unused]] Player* player) { return false; }
        virtual void OnCaptureFlag([[maybe_unused]] AreaTrigger* areaTrigger, [[maybe_unused]] Player* player) { }
};

#endif
