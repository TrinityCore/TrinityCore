/*
 * Copyright (C) 2022 BfaCore Reforged
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
    NPC_JINBAK         = 61567,
    NPC_VOJAK          = 61634,
    NPC_PAVALAK        = 61485,
    NPC_NERONOK        = 62205,
    NPC_LI_CHU         = 61812,
    NPC_LO_CHU         = 62794,
    NPC_SIKTHIK_WARDEN = 62795,
    NPC_MANTID_TAR_KEG = 61817, // Vehicle. Interaction for throwing keg.
    NPC_SAP_PUDDLE     = 61613,
    DATA_VOJAK_DOOR
};

enum GameObjects
{
    GO_HARDENED_RESIN = 213174, // after jinbak
    GO_DOOR = 212921, // after vojak

    GO_TEMPLE_INVIS_DOOR = 213251, // before neronok bridge
    GO_WIND_WALL = 214548, // before neronok bridge
    GO_FIRE_WALL = 210097,
};

#endif // SIEGE_NIUZAO_TEMPLE_H_
