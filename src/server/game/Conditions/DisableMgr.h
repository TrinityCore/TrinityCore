/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_DISABLEMGR_H
#define TRINITY_DISABLEMGR_H

#include <ace/Singleton.h>
class Unit;

enum DisableType
{
    DISABLE_TYPE_SPELL                  = 0,
    DISABLE_TYPE_QUEST                  = 1,
    DISABLE_TYPE_MAP                    = 2,
    DISABLE_TYPE_BATTLEGROUND           = 3,
    DISABLE_TYPE_ACHIEVEMENT_CRITERIA   = 4,
    DISABLE_TYPE_OUTDOORPVP             = 5,
};

#define MAX_DISABLE_TYPES 6

typedef std::map<uint32, uint8> DisableTypeMap;             // single disables here with optional data
typedef std::map<DisableType, DisableTypeMap> DisableMap;   // global disable map by source

class DisableMgr
{
    friend class ACE_Singleton<DisableMgr, ACE_Null_Mutex>;
    DisableMgr();
    ~DisableMgr();

    public:

        void LoadDisables();
        bool IsDisabledFor(DisableType type, uint32 entry, Unit const* pUnit);
        void CheckQuestDisables();

    protected:

        DisableMap m_DisableMap;
};

#define sDisableMgr (*ACE_Singleton<DisableMgr, ACE_Null_Mutex>::instance())

#endif //TRINITY_DISABLEMGR_H
