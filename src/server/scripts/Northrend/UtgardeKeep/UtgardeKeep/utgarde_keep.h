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

#ifndef UTGARDE_KEEP_H_
#define UTGARDE_KEEP_H_

#define UKScriptName "instance_utgarde_keep"
#define DataHeader "UK"

uint32 const EncounterCount = 3;

enum DataTypes
{
    // Encounter States/Boss GUIDs
    DATA_PRINCE_KELESETH    = 0,
    DATA_SKARVALD_DALRONN   = 1,
    DATA_INGVAR             = 2,

    // Additional Data
    DATA_SKARVALD           = 3,
    DATA_DALRONN            = 4,

    DATA_FORGE_1            = 5,
    DATA_FORGE_2            = 6,
    DATA_FORGE_3            = 7
};

enum CreatureIds
{
    NPC_PRINCE_KELESETH     = 23953,
    NPC_SKARVALD            = 24200,
    NPC_DALRONN             = 24201,
    NPC_INGVAR              = 23954,

    // Skarvald - Dalronn
    NPC_DALRONN_GHOST       = 27389,
    NPC_SKARVALD_GHOST      = 27390,

    // Ingvar the Plunderer
    NPC_INGVAR_UNDEAD       = 23980,
    NPC_THROW_TARGET        = 23996,
    NPC_ANNHYLDE_THE_CALLER = 24068
};

enum GameObjectIds
{
    GO_BELLOW_1             = 186688,
    GO_BELLOW_2             = 186689,
    GO_BELLOW_3             = 186690,

    GO_FORGEFIRE_1          = 186692,
    GO_FORGEFIRE_2          = 186693,
    GO_FORGEFIRE_3          = 186691,

    GO_GLOWING_ANVIL_1      = 186609,
    GO_GLOWING_ANVIL_2      = 186610,
    GO_GLOWING_ANVIL_3      = 186611,

    GO_GIANT_PORTCULLIS_1   = 186756,
    GO_GIANT_PORTCULLIS_2   = 186694
};

struct ForgeInfo
{
    ForgeInfo() : AnvilGUID(0), BellowGUID(0), FireGUID(0), Event(NOT_STARTED) { };

    uint64 AnvilGUID;
    uint64 BellowGUID;
    uint64 FireGUID;

    uint32 Event;
};

template<class AI>
AI* GetUtgardeKeepAI(Creature* creature)
{
    return GetInstanceAI<AI>(creature, UKScriptName);
}

#endif // UTGARDE_KEEP_H_
