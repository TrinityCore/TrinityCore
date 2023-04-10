/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef EVENTOBJECTOBJECT_H
#define EVENTOBJECTOBJECT_H

#include "Object.h"
#include "GridObject.h"

struct EventObjectData
{
    explicit EventObjectData() { }

    std::set<uint32> PhaseID;
    ObjectGuid::LowType guid = 0;
    Position Pos;
    uint32 id = 0;                                              // entry in eventobject_template
    uint32 phaseMask = 1;
    uint16 mapid = 0;
    uint16 zoneId = 0;
    uint16 areaId = 0;
    uint64 spawnMask = 1;
    bool dbData = true;
};

struct EventObjectTemplate
{
    uint32 Entry;
    uint32 SpellID = 0;
    uint32 WorldSafeLocID = 0;
    uint32 ScriptID = 0;
    uint32 Flags = 0;
    float radius = 0.0f;
    std::string Name;
    bool RemoveSpell = false;
};

enum EventObjectFlags
{
    EO_FLAG_ONE_ACTION = 0x00000001,
};

typedef std::unordered_map<uint32, EventObjectTemplate> EventObjectTemplateContainer;

class EventObject : public WorldObject, public GridObject<EventObject>
{
public:
    EventObject();
    ~EventObject();

    bool Create(ObjectGuid::LowType guidlow, Map* map, uint32 phaseMask, uint32 entry, float x, float y, float z, float ang, float radius, uint32 spell, uint32 worldsafe);

    void AddToWorld() override;
    void RemoveFromWorld() override;

    bool LoadFromDB(ObjectGuid::LowType guid, Map* map) { return LoadEventObjectFromDB(guid, map); }
    bool LoadEventObjectFromDB(ObjectGuid::LowType guid, Map* map);
    void SaveToDB(uint32 mapid, uint64 spawnMask, uint32 phaseMask);

    void Update(uint32 p_time) override;
    void Remove();

    void MoveInLineOfSight(Unit* who);

    uint64 GetDBTableGUIDLow() const { return m_DBTableGuid; }

    uint32 GetScriptId() const;

    bool ActivatedForPlayer(Player* player) const;

    EventObjectTemplate const* eventTemplate = nullptr;
    uint64 m_DBTableGuid;
    GuidSet affectedPlayers;
    GuidSet affectedPermamentPlayers;
};
#endif
