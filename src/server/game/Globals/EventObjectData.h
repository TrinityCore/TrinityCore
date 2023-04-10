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

#ifndef _EventObjectDataStoreh_
#define _EventObjectDataStoreh_

#include "EventObject.h"

typedef std::unordered_map<ObjectGuid::LowType, EventObjectData> EventObjectDataContainer;

class EventObjectDataStoreMgr
{
    EventObjectDataStoreMgr();
    ~EventObjectDataStoreMgr();

public:
    static EventObjectDataStoreMgr* instance();

    void LoadEventObjectTemplates();
    void LoadEventObjects();

    EventObjectTemplate const* GetEventObjectTemplate(uint32 entry);
    EventObjectTemplate const* AddEventObjectTemplate(uint32 entry, float radius, uint32 spell, uint32 worldsafe);
    EventObjectData const* GetEventObjectData(ObjectGuid::LowType const& guid) const;
    EventObjectData& NewOrExistEventObjectData(ObjectGuid::LowType const& guid);
private:
    EventObjectTemplateContainer _eventObjectTemplateMap;
    EventObjectDataContainer _eventObjectData;
};

#define sEventObjectDataStore EventObjectDataStoreMgr::instance()

#endif
