/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#include "Creature.h"
#include "WildBattlePet.h"

WildBattlePet::WildBattlePet(Creature* creature) : m_creature(creature)
{
}

void WildBattlePet::Initialize()
{
    GetCreature()->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_WILD_BATTLE_PET | UNIT_FLAG_IMMUNE_TO_NPC);

    if (AreaTableEntry const* zone = sAreaTableStore.LookupEntry(GetCreature()->GetZoneId()))
    {
        uint8 level = urand(zone->WildBattlePetLevelMin, zone->WildBattlePetLevelMax);
        GetCreature()->SetUInt32Value(UNIT_FIELD_WILD_BATTLEPET_LEVEL, level);
    }
}
