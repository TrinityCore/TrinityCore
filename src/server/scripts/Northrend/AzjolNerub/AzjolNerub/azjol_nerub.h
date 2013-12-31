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

#ifndef AZJOL_NERUB_H_
#define AZJOL_NERUB_H_

#define AzjolNerubScriptName "instance_azjol_nerub"

uint32 const EncounterCount = 3;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_KRIKTHIR_THE_GATEWATCHER   = 0,
    DATA_HADRONOX                   = 1,
    DATA_ANUBARAK                   = 2,

    // Additional Data
    DATA_WATCHER_GASHRA             = 3,
    DATA_WATCHER_SILTHIK            = 4,
    DATA_WATCHER_NARJIL             = 5
};

enum CreatureIds
{
    NPC_KRIKTHIR                    = 28684,
    NPC_HADRONOX                    = 28921,
    NPC_ANUBARAK                    = 29120,

    NPC_WATCHER_NARJIL              = 28729,
    NPC_WATCHER_GASHRA              = 28730,
    NPC_WATCHER_SILTHIK             = 28731
};

enum GameObjectIds
{
    GO_KRIKTHIR_DOOR                = 192395,
    GO_ANUBARAK_DOOR_1              = 192396,
    GO_ANUBARAK_DOOR_2              = 192397,
    GO_ANUBARAK_DOOR_3              = 192398
};

template<class AI>
AI* GetAzjolNerubAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, AzjolNerubScriptName);
}

#endif // AZJOL_NERUB_H_
