/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "BattlePetPackets.h"

#ifndef BattlePet_h__
#define BattlePet_h__

enum BattlePetSaveInfo
{
    BATTLE_PET_UNCHANGED = 0,
    BATTLE_PET_CHANGED   = 1,
    BATTLE_PET_NEW       = 2,
    BATTLE_PET_REMOVED   = 3
};

struct BattlePetOwnerInfo
{
    ObjectGuid Guid;
    uint32 PlayerVirtualRealm = 0;
    uint32 PlayerNativeRealm = 0;
};

class BattlePet
{
public:
    void CalculateStats();
    BattlePetSpeciesEntry const* GetSpecies();

    BattlePetSaveInfo SaveInfo;

    ObjectGuid Guid;
    uint32 Species = 0;
    uint32 CreatureID = 0;
    uint32 CollarID = 0;
    uint16 Breed = 0;
    uint16 Level = 0;
    uint16 Exp = 0;
    uint16 Flags = 0;
    uint32 Power = 0;
    uint32 Health = 0;
    uint32 MaxHealth = 0;
    uint32 Speed = 0;
    uint8 Quality = 0;
    Optional<BattlePetOwnerInfo> OwnerInfo;
    std::string Name;
};

#endif // BattlePet_h__
