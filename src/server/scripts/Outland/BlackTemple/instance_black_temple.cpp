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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "black_temple.h"

DoorData const doorData[] =
{
    { GO_NAJENTUS_GATE,         DATA_HIGH_WARLORD_NAJENTUS, DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { GO_NAJENTUS_GATE,         DATA_SUPREMUS,              DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { GO_SUPREMUS_GATE,         DATA_SUPREMUS,              DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { GO_SHADE_OF_AKAMA_DOOR,   DATA_SHADE_OF_AKAMA,        DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { GO_TERON_DOOR_1,          DATA_TERON_GOREFIEND,       DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { GO_TERON_DOOR_2,          DATA_TERON_GOREFIEND,       DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { GO_GURTOGG_DOOR,          DATA_GURTOGG_BLOODBOIL,     DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { GO_TEMPLE_DOOR,           DATA_RELIQUARY_OF_SOULS,    DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { GO_MOTHER_SHAHRAZ_DOOR,   DATA_MOTHER_SHAHRAZ,        DOOR_TYPE_PASSAGE,  BOUNDARY_NONE },
    { GO_COUNCIL_DOOR_1,        DATA_ILLIDARI_COUNCIL,      DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { GO_COUNCIL_DOOR_2,        DATA_ILLIDARI_COUNCIL,      DOOR_TYPE_ROOM,     BOUNDARY_NONE },
    { 0,                        0,                          DOOR_TYPE_ROOM,     BOUNDARY_NONE } // END
};

class instance_black_temple : public InstanceMapScript
{
    public:
        instance_black_temple() : InstanceMapScript(BTScriptName, 564) { }

        struct instance_black_temple_InstanceMapScript : public InstanceScript
        {
            instance_black_temple_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                NajentusGUID                = 0;
                SupremusGUID                = 0;
                ShadeOfAkamaGUID            = 0;
                AkamaShadeGUID              = 0;
                AkamaGUID                   = 0;
                GathiosTheShattererGUID     = 0;
                HighNethermancerZerevorGUID = 0;
                LadyMalandeGUID             = 0;
                VerasDarkshadowGUID         = 0;
                IllidariCouncilGUID         = 0;
                BloodElfCouncilVoiceGUID    = 0;
                IllidanStormrageGUID        = 0;

                IllidanGateGUID             = 0;

                memset(IllidanDoorGUIDs, 0, 2 * sizeof(uint64));
            }

            void OnCreatureCreate(Creature* creature) OVERRIDE
            {
                switch (creature->GetEntry())
                {
                    case NPC_HIGH_WARLORD_NAJENTUS:
                        NajentusGUID = creature->GetGUID();
                        break;
                    case NPC_SUPREMUS:
                        SupremusGUID = creature->GetGUID();
                        break;
                    case NPC_SHADE_OF_AKAMA:
                        ShadeOfAkamaGUID = creature->GetGUID();
                        break;
                    case NPC_AKAMA_SHADE:
                        AkamaShadeGUID = creature->GetGUID();
                        break;
                    case NPC_AKAMA:
                        AkamaGUID = creature->GetGUID();
                        break;
                    case NPC_GATHIOS_THE_SHATTERER:
                        GathiosTheShattererGUID = creature->GetGUID();
                        break;
                    case NPC_HIGH_NETHERMANCER_ZEREVOR:
                        HighNethermancerZerevorGUID = creature->GetGUID();
                        break;
                    case NPC_LADY_MALANDE:
                        LadyMalandeGUID = creature->GetGUID();
                        break;
                    case NPC_VERAS_DARKSHADOW:
                        VerasDarkshadowGUID = creature->GetGUID();
                        break;
                    case NPC_ILLIDARI_COUNCIL:
                        IllidariCouncilGUID = creature->GetGUID();
                        break;
                    case NPC_BLOOD_ELF_COUNCIL_VOICE:
                        BloodElfCouncilVoiceGUID = creature->GetGUID();
                        break;
                    case NPC_ILLIDAN_STORMRAGE:
                        IllidanStormrageGUID = creature->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_NAJENTUS_GATE:
                    case GO_SUPREMUS_GATE:
                    case GO_SHADE_OF_AKAMA_DOOR:
                    case GO_TERON_DOOR_1:
                    case GO_TERON_DOOR_2:
                    case GO_GURTOGG_DOOR:
                    case GO_TEMPLE_DOOR:
                    case GO_MOTHER_SHAHRAZ_DOOR:
                    case GO_COUNCIL_DOOR_1:
                    case GO_COUNCIL_DOOR_2:
                        AddDoor(go, true);
                        break;
                    case GO_ILLIDAN_GATE:
                        IllidanGateGUID = go->GetGUID();
                        break;
                    case GO_ILLIDAN_DOOR_R:
                        IllidanDoorGUIDs[0] = go->GetGUID();
                        break;
                    case GO_ILLIDAN_DOOR_L:
                        IllidanDoorGUIDs[1] = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectRemove(GameObject* go) OVERRIDE
            {
                switch (go->GetEntry())
                {
                    case GO_NAJENTUS_GATE:
                    case GO_SUPREMUS_GATE:
                    case GO_SHADE_OF_AKAMA_DOOR:
                    case GO_TERON_DOOR_1:
                    case GO_TERON_DOOR_2:
                    case GO_GURTOGG_DOOR:
                    case GO_TEMPLE_DOOR:
                    case GO_MOTHER_SHAHRAZ_DOOR:
                    case GO_COUNCIL_DOOR_1:
                    case GO_COUNCIL_DOOR_2:
                        AddDoor(go, false);
                        break;
                    default:
                        break;
                }
            }

            uint64 GetData64(uint32 type) const OVERRIDE
            {
                switch (type)
                {
                    case DATA_HIGH_WARLORD_NAJENTUS:
                        return NajentusGUID;
                    case DATA_SUPREMUS:
                        return SupremusGUID;
                    case DATA_SHADE_OF_AKAMA:
                        return ShadeOfAkamaGUID;
                    case DATA_AKAMA_SHADE:
                        return AkamaShadeGUID;
                    case DATA_AKAMA:
                        return AkamaGUID;
                    case DATA_GATHIOS_THE_SHATTERER:
                        return GathiosTheShattererGUID;
                    case DATA_HIGH_NETHERMANCER_ZEREVOR:
                        return HighNethermancerZerevorGUID;
                    case DATA_LADY_MALANDE:
                        return LadyMalandeGUID;
                    case DATA_VERAS_DARKSHADOW:
                        return VerasDarkshadowGUID;
                    case DATA_ILLIDARI_COUNCIL:
                        return IllidariCouncilGUID;
                    case DATA_BLOOD_ELF_COUNCIL_VOICE:
                        return BloodElfCouncilVoiceGUID;
                    case DATA_ILLIDAN_STORMRAGE:
                        return IllidanStormrageGUID;
                    case DATA_GO_ILLIDAN_GATE:
                        return IllidanGateGUID;
                    case DATA_GO_ILLIDAN_DOOR_R:
                        return IllidanDoorGUIDs[0];
                    case DATA_GO_ILLIDAN_DOOR_L:
                        return IllidanDoorGUIDs[1];
                    default:
                        break;
                }

                return 0;
            }

            std::string GetSaveData() OVERRIDE
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "B T " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* str) OVERRIDE
            {
                if (!str)
                {
                    OUT_LOAD_INST_DATA_FAIL;
                    return;
                }

                OUT_LOAD_INST_DATA(str);

                char dataHead1, dataHead2;

                std::istringstream loadStream(str);
                loadStream >> dataHead1 >> dataHead2;

                if (dataHead1 == 'B' && dataHead2 == 'T')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            uint64 NajentusGUID;
            uint64 SupremusGUID;
            uint64 ShadeOfAkamaGUID;
            uint64 AkamaShadeGUID;
            uint64 AkamaGUID;

            uint64 GathiosTheShattererGUID;
            uint64 HighNethermancerZerevorGUID;
            uint64 LadyMalandeGUID;
            uint64 VerasDarkshadowGUID;

            uint64 IllidariCouncilGUID;
            uint64 BloodElfCouncilVoiceGUID;

            uint64 IllidanStormrageGUID;

            uint64 IllidanGateGUID;
            uint64 IllidanDoorGUIDs[2];
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_black_temple_InstanceMapScript(map);
        }
};

void AddSC_instance_black_temple()
{
    new instance_black_temple();
}
