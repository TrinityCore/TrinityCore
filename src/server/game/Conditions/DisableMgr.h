/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#include "VMapManager2.h"
#include "Define.h"

class Unit;

enum DisableType
{
    DISABLE_TYPE_SPELL                  = 0,
    DISABLE_TYPE_QUEST                  = 1,
    DISABLE_TYPE_MAP                    = 2,
    DISABLE_TYPE_BATTLEGROUND           = 3,
    DISABLE_TYPE_ACHIEVEMENT_CRITERIA   = 4,
    DISABLE_TYPE_OUTDOORPVP             = 5,
    DISABLE_TYPE_VMAP                   = 6,
    DISABLE_TYPE_MMAP                   = 7
};

enum SpellDisableTypes
{
    SPELL_DISABLE_PLAYER            = 0x1,
    SPELL_DISABLE_CREATURE          = 0x2,
    SPELL_DISABLE_PET               = 0x4,
    SPELL_DISABLE_DEPRECATED_SPELL  = 0x8,
    SPELL_DISABLE_MAP               = 0x10,
    SPELL_DISABLE_AREA              = 0x20,
    SPELL_DISABLE_LOS               = 0x40,
    MAX_SPELL_DISABLE_TYPE = (  SPELL_DISABLE_PLAYER | SPELL_DISABLE_CREATURE | SPELL_DISABLE_PET |
                                SPELL_DISABLE_DEPRECATED_SPELL | SPELL_DISABLE_MAP | SPELL_DISABLE_AREA |
                                SPELL_DISABLE_LOS)
};

enum MMapDisableTypes
{
    MMAP_DISABLE_PATHFINDING    = 0x0
};

namespace DisableMgr
{
    void LoadDisables();
    bool IsDisabledFor(DisableType type, uint32 entry, Unit const* unit, uint8 flags = 0);
    void CheckQuestDisables();
    bool IsVMAPDisabledFor(uint32 entry, uint8 flags);
    bool IsPathfindingEnabled(uint32 mapId);
}

#endif //TRINITY_DISABLEMGR_H
