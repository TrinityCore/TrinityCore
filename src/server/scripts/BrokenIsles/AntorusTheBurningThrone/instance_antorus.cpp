/*
 * Copyright 2023 AzgathCore
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

#include "antorus.h"
#include "GameObject.h"

#define MIN_X -4356.93f
#define MAX_X -3638.09f
#define MIN_Y -11006.65f
#define MAX_Y -10354.48f

DoorData const doorData[] =
{
    {GO_STONE,                     DATA_WORLDBREAKER,      DOOR_TYPE_PASSAGE},
    {GO_INVISIBLE_WALL,            DATA_WORLDBREAKER,      DOOR_TYPE_PASSAGE},
    {GO_ARCANE_BARRIER,            DATA_IMONAR,            DOOR_TYPE_PASSAGE},
    {GO_COMMAND_DOOR,              DATA_ANTORAN,           DOOR_TYPE_ROOM},
    {GO_KINGAROTH_DOOR,            DATA_KINGAROTH,         DOOR_TYPE_ROOM},
    {GO_HASABEL_DOOR,              DATA_HASABEL,           DOOR_TYPE_ROOM},
    {GO_EONAR_DOOR,                DATA_EONAR,             DOOR_TYPE_ROOM},
    {GO_VARIMATHRAS_DOOR_1,        DATA_VARIMATHRAS,       DOOR_TYPE_ROOM},
    {GO_VARIMATHRAS_DOOR_2,        DATA_VARIMATHRAS,       DOOR_TYPE_PASSAGE},
    {GO_COVEN_DOOR_1,              DATA_VARIMATHRAS,       DOOR_TYPE_PASSAGE},
    {GO_COVEN_DOOR_2,              DATA_VARIMATHRAS,       DOOR_TYPE_PASSAGE},
    {GO_COVEN_DOOR_1,              DATA_COVEN,             DOOR_TYPE_ROOM},
    {GO_COVEN_DOOR_2,              DATA_COVEN,             DOOR_TYPE_ROOM},
    {GO_AGGRAMAR_DOOR,             DATA_AGGRAMAR,          DOOR_TYPE_PASSAGE},
    {GO_AGGRAMAR_BRIDGE,           DATA_AGGRAMAR,          DOOR_TYPE_PASSAGE},
    {0,                            0,                      DOOR_TYPE_ROOM} // END
};

ObjectData const creatureData[] =
{
    {NPC_WORLDBREAKER,              NPC_WORLDBREAKER},
    {NPC_HASABEL,                   NPC_HASABEL},
    {NPC_IMONAR,                    NPC_IMONAR},
    {NPC_AZARA,                     NPC_AZARA},
    {NPC_KINGAROTH,                 NPC_KINGAROTH},
    {NPC_SHATUG,                    NPC_SHATUG},
    {NPC_FHARG,                     NPC_FHARG},
    {NPC_MOLTEN_TOUCH,              NPC_MOLTEN_TOUCH},
    {NPC_ADMIRAL_SVIRAX,            NPC_ADMIRAL_SVIRAX},
    {NPC_VARIMATHRAS,               NPC_VARIMATHRAS},
    {NPC_EONAR_EVENT,               NPC_EONAR_EVENT},
    {0,                             0} // END
};

ObjectData const gobjectData[] =
{
    {GO_ELEVATOR,                   GO_ELEVATOR},
    {GO_PORTAL_TO_ELUNARIES,        GO_PORTAL_TO_ELUNARIES},
    {GO_ARCANE_BARRIER_VISUAL,      GO_ARCANE_BARRIER_VISUAL},
    {GO_KINGAROTH_TRAP_LEFT_1,      GO_KINGAROTH_TRAP_LEFT_1},
    {GO_KINGAROTH_TRAP_LEFT_2,      GO_KINGAROTH_TRAP_LEFT_2},
    {GO_KINGAROTH_TRAP_RIGHT_1,     GO_KINGAROTH_TRAP_RIGHT_1},
    {GO_KINGAROTH_TRAP_RIGHT_2,     GO_KINGAROTH_TRAP_RIGHT_2},
    {GO_KINGAROTH_TRAP_BACK_1,      GO_KINGAROTH_TRAP_BACK_1},
    {GO_KINGAROTH_TRAP_BACK_2,      GO_KINGAROTH_TRAP_BACK_2},
    {GO_EONAR_PARAXIS_SHIP,         GO_EONAR_PARAXIS_SHIP},
    {GO_EONAR_PARAXIS_DOOR_1,       GO_EONAR_PARAXIS_DOOR_1},
    {GO_EONAR_PARAXIS_DOOR_2,       GO_EONAR_PARAXIS_DOOR_2},
    {GO_EONAR_PARAXIS_DOOR_3,       GO_EONAR_PARAXIS_DOOR_3},
    {GO_EONAR_CACHE,                GO_EONAR_CACHE},
    {0,                             0 } // END
};


Position const dreadWingsPos[2]
{
    { -3290.76f,	9519.75f,	22.1289f },
    { -3301.51f,	9595.35f,	36.3317f }
};

void AddSC_instance_antorus()
{
   
}
