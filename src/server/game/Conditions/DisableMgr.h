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

#ifndef TRINITY_DISABLEMGR_H
#define TRINITY_DISABLEMGR_H

#include "Define.h"

class WorldObject;

enum DisableType
{
    DISABLE_TYPE_SPELL                  = 0,
    DISABLE_TYPE_QUEST                  = 1,
    DISABLE_TYPE_MAP                    = 2,
    DISABLE_TYPE_BATTLEGROUND           = 3,
    DISABLE_TYPE_ACHIEVEMENT_CRITERIA   = 4,
    DISABLE_TYPE_OUTDOORPVP             = 5,
    DISABLE_TYPE_VMAP                   = 6,
    DISABLE_TYPE_MMAP                   = 7,
    DISABLE_TYPE_LFG_MAP                = 8
};

enum SpellDisableTypes
{
    SPELL_DISABLE_PLAYER            = 0x01,
    SPELL_DISABLE_CREATURE          = 0x02,
    SPELL_DISABLE_PET               = 0x04,
    SPELL_DISABLE_DEPRECATED_SPELL  = 0x08,
    SPELL_DISABLE_MAP               = 0x10,
    SPELL_DISABLE_AREA              = 0x20,
    SPELL_DISABLE_LOS               = 0x40,
    SPELL_DISABLE_GAMEOBJECT        = 0x80,
    MAX_SPELL_DISABLE_TYPE = (  SPELL_DISABLE_PLAYER | SPELL_DISABLE_CREATURE | SPELL_DISABLE_PET |
                                SPELL_DISABLE_DEPRECATED_SPELL | SPELL_DISABLE_MAP | SPELL_DISABLE_AREA |
                                SPELL_DISABLE_LOS | SPELL_DISABLE_GAMEOBJECT)
};

enum MMapDisableTypes
{
    MMAP_DISABLE_PATHFINDING    = 0x0
};

namespace DisableMgr
{
    TC_GAME_API void LoadDisables();
    TC_GAME_API bool IsDisabledFor(DisableType type, uint32 entry, WorldObject const* ref, uint8 flags = 0);
    TC_GAME_API void CheckQuestDisables();
    TC_GAME_API bool IsVMAPDisabledFor(uint32 entry, uint8 flags);
    TC_GAME_API bool IsPathfindingEnabled(uint32 mapId);
}

#endif //TRINITY_DISABLEMGR_H
