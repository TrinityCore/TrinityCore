/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "ClassHall.h"
#include "Creature.h"
#include "DatabaseEnv.h"
#include "GameObject.h"
#include "GarrisonMgr.h"
#include "Log.h"
#include "MapManager.h"
#include "ObjectMgr.h"

ClassHall::ClassHall(Player* owner) : Garrison(owner)
{
    _garrisonType = GARRISON_TYPE_CLASS_HALL;
}

bool ClassHall::LoadFromDB()
{
    if (!Garrison::LoadFromDB())
        return false;

    return true;
}

void ClassHall::SaveToDB(SQLTransaction& trans)
{
    Garrison::SaveToDB(trans);
}

bool ClassHall::Create(uint32 garrSiteId)
{
    if (!Garrison::Create(garrSiteId))
        return false;

    return true;
}

void ClassHall::Delete()
{
    SQLTransaction trans = CharacterDatabase.BeginTransaction();
    DeleteFromDB(trans);
    CharacterDatabase.CommitTransaction(trans);

    Garrison::Delete();
}

bool ClassHall::IsAllowedArea(AreaTableEntry const* area) const
{
    if (!area)
        return false;

    // TODO : Find a better way to handle this
    return area->Flags[1] & AREA_FLAG_GARRISON && (area->ID >= 7638 && area->ID <= 8023);
}
