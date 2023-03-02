/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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

#ifndef SIEGE_NIUZAO_TEMPLE_H_
#define SIEGE_NIUZAO_TEMPLE_H_

#include "SpellScript.h"
#include "Map.h"
#include "Creature.h"
#include "CreatureAIImpl.h"

enum DataTypes
{
    DATA_JINBAK     = 1,
    DATA_VOJAK      = 2,
    DATA_PAVALAK    = 3,
    DATA_NERONOK    = 4
};

enum CreaturesIds
{
    NPC_JINBAK      = 61567,
    NPC_VOJAK       = 61634,
    NPC_PAVALAK     = 61485,
    NPC_NERONOK     = 62205,

    NPC_SAP_PUDDLE  = 61613
};

#endif // SIEGE_NIUZAO_TEMPLE_H_
