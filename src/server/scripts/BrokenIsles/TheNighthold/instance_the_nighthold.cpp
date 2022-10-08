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

#include "InstanceScript.h"
#include "Group.h"
#include "LFGMgr.h"
#include "Vehicle.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellScript.h"
#include "WorldPacket.h"
#include "MiscPackets.h"
#include "QueryPackets.h"
#include "WeatherMgr.h"
#include "GameObject.h"
#include "thenighthold.h"
#include "AreaBoundary.h"

static BossBoundaryData const boundaries =
{
    { BOSS_SKORPYRON,               new CircleBoundary(Position(97.86111f, 3439.28f, -250.1467f), 50.0f)   },
    { BOSS_CHRONOMATIC_ANOMALY,     new CircleBoundary(Position(276.3507f, 3136.081f, -236.9497f), 120.0f) }
};

static DoorData const doorData[] =
{
    { GO_SKORPYRON_DOOR_01,                    BOSS_SKORPYRON,                    DOOR_TYPE_ROOM    },
    { GO_SKORPYRON_DOOR_02,                    BOSS_SKORPYRON,                    DOOR_TYPE_PASSAGE },
    { GO_CHRONOMATIC_ANOMALY_01,               BOSS_CHRONOMATIC_ANOMALY,          DOOR_TYPE_ROOM    },
    { GO_CHRONOMATIC_ANOMALY_02,               BOSS_CHRONOMATIC_ANOMALY,          DOOR_TYPE_PASSAGE },
    { GO_TRILLIAX_DOOR_01,                     BOSS_TRILLIAX,                     DOOR_TYPE_ROOM },
    { GO_TRILLIAX_DOOR_02,                     BOSS_TRILLIAX,                     DOOR_TYPE_PASSAGE },
    { 0,                                       0,                                 DOOR_TYPE_ROOM    }
};

class instance_the_nighthold : public InstanceMapScript
{
public:
    instance_the_nighthold() : InstanceMapScript(TNScriptName, 1530) { }

    struct instance_the_nighthold_InstanceMapScript : public InstanceScript
    {
        instance_the_nighthold_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(MAX_ENCOUNTER);
            LoadBossBoundaries(boundaries);
            LoadDoorData(doorData);
            CageRematch = DONE;
            TormTheBrute = NOT_STARTED;
            slimepool = 0;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_THE_NIGHTWELL:
                TheNightwellGUID = creature->GetGUID();
                break;
            case NPC_TRILLAX:
                Trillax = creature->GetGUID();
            default:
                break;
            }
        }

        void OnGameObjectCreate(GameObject* gameObject) override
        {
            switch (gameObject->GetEntry())
            {
            case GO_SKORPYRON_DOOR_01:
            case GO_SKORPYRON_DOOR_02:
            case GO_CHRONOMATIC_ANOMALY_01:
            case GO_CHRONOMATIC_ANOMALY_02:
            case GO_TRILLIAX_DOOR_01:
            case GO_TRILLIAX_DOOR_02:
                AddDoor(gameObject, true);
                break;
            case GO_TORM_THE_BRUTE_DOOR:
                TormTheBruteDoorGUID = gameObject->GetGUID();
                if (GetData(DATA_TORM_THE_BRUTE) == DONE)
                    HandleGameObject(TormTheBruteDoorGUID, true, gameObject);
                break;
            default:
                break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
            case DATA_CAGE_REMATCH:
                CageRematch |= data;
                break;
            case DATA_TORM_THE_BRUTE:
                TormTheBrute |= data;
                if (GetData(DATA_TORM_THE_BRUTE) == DONE)
                    HandleGameObject(TormTheBruteDoorGUID, true);
                SaveToDB();
                break;
            case DATA_SLIME_POOL:
                slimepool = data;
                break;
            default:
                break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_CAGE_REMATCH:
                return CageRematch;
            case DATA_TORM_THE_BRUTE:
                return TormTheBrute;
            case DATA_SLIME_POOL:
                return slimepool;
            default:
                return 0;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case DATAGUID_THE_NIGHTWELL:
                return TheNightwellGUID;
            case DATAGUID_TRILLAX:
                return Trillax;
            default:
                return ObjectGuid::Empty;
            }
        }

        void WriteSaveDataMore(std::ostringstream& data) override
        {
            data << TormTheBrute;
        }

        void ReadSaveDataMore(std::istringstream& data) override
        {
            uint32 temp = 0;
            data >> temp;
            SetData(DATA_TORM_THE_BRUTE, temp);
        }

    protected:
        // Creatures
        ObjectGuid TheNightwellGUID;
        ObjectGuid Trillax;
        //Gameobjects
        ObjectGuid TormTheBruteDoorGUID;
        // Miscellaneous
        uint32 CageRematch;
        uint32 TormTheBrute;
        uint32 slimepool;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_the_nighthold_InstanceMapScript(map);
    }
};

void AddSC_instance_the_nighthold()
{
    new instance_the_nighthold();
}
