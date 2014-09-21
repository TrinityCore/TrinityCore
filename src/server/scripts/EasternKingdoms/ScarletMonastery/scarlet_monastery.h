/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef SCARLET_M_
#define SCARLET_M_

#define SMScriptName "instance_scarlet_monastery"
#define DataHeader "SM"

uint32 const EncounterCount = 10;

enum DataTypes
{
    DATA_MOGRAINE_AND_WHITE_EVENT   = 1,
    DATA_MOGRAINE                   = 2,
    DATA_WHITEMANE                  = 3,

    DATA_HORSEMAN_EVENT             = 4,
    DATA_PUMPKIN_SHRINE             = 5,

    DATA_VORREL                     = 6,
    DATA_ARCANIST_DOAN              = 7,
    DATA_AZSHIR                     = 8,
    DATA_BLOODMAGE_THALNOS          = 9,
    DATA_HEROD                      = 10,
    DATA_HIGH_INQUISITOR_FAIRBANKS  = 11,
    DATA_HOUNDMASTER_LOKSEY         = 12,
    DATA_INTERROGATOR_VISHAS        = 13,
    DATA_SCORN                      = 14
};

enum CreatureIds
{
    NPC_MOGRAINE                    = 3976,
    NPC_WHITEMANE                   = 3977,
    NPC_VORREL                      = 3981,

    NPC_HORSEMAN                    = 23682,
    NPC_HEAD                        = 23775,
    NPC_PUMPKIN                     = 23694
};

enum GameObjectIds
{
    GO_HIGH_INQUISITORS_DOOR        = 104600,
    GO_PUMPKIN_SHRINE               = 186267
};

template<class AI>
inline AI* GetScarletMonasteryAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, SMScriptName);
}

#endif // SCARLET_M_
