/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
    { GO_NAJENTUS_GATE,         DATA_HIGH_WARLORD_NAJENTUS, DOOR_TYPE_PASSAGE },
    { GO_NAJENTUS_GATE,         DATA_SUPREMUS,              DOOR_TYPE_ROOM },
    { GO_SUPREMUS_GATE,         DATA_SUPREMUS,              DOOR_TYPE_PASSAGE },
    { GO_SHADE_OF_AKAMA_DOOR,   DATA_SHADE_OF_AKAMA,        DOOR_TYPE_ROOM },
    { GO_TERON_DOOR_1,          DATA_TERON_GOREFIEND,       DOOR_TYPE_ROOM },
    { GO_TERON_DOOR_2,          DATA_TERON_GOREFIEND,       DOOR_TYPE_ROOM },
    { GO_GURTOGG_DOOR,          DATA_GURTOGG_BLOODBOIL,     DOOR_TYPE_PASSAGE },
    { GO_TEMPLE_DOOR,           DATA_RELIQUARY_OF_SOULS,    DOOR_TYPE_PASSAGE },
    { GO_MOTHER_SHAHRAZ_DOOR,   DATA_MOTHER_SHAHRAZ,        DOOR_TYPE_PASSAGE },
    { GO_COUNCIL_DOOR_1,        DATA_ILLIDARI_COUNCIL,      DOOR_TYPE_ROOM },
    { GO_COUNCIL_DOOR_2,        DATA_ILLIDARI_COUNCIL,      DOOR_TYPE_ROOM },
    { 0,                        0,                          DOOR_TYPE_ROOM } // END
};

class instance_black_temple : public InstanceMapScript
{
    public:
        instance_black_temple() : InstanceMapScript(BTScriptName, 564) { }

        struct instance_black_temple_InstanceMapScript : public InstanceScript
        {
            instance_black_temple_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
            }

            void OnCreatureCreate(Creature* creature) override
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

            void OnGameObjectCreate(GameObject* go) override
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

            void OnGameObjectRemove(GameObject* go) override
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

            ObjectGuid GetGuidData(uint32 type) const override
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

                return ObjectGuid::Empty;
            }

        protected:
            ObjectGuid NajentusGUID;
            ObjectGuid SupremusGUID;
            ObjectGuid ShadeOfAkamaGUID;
            ObjectGuid AkamaShadeGUID;
            ObjectGuid AkamaGUID;

            ObjectGuid GathiosTheShattererGUID;
            ObjectGuid HighNethermancerZerevorGUID;
            ObjectGuid LadyMalandeGUID;
            ObjectGuid VerasDarkshadowGUID;

            ObjectGuid IllidariCouncilGUID;
            ObjectGuid BloodElfCouncilVoiceGUID;

            ObjectGuid IllidanStormrageGUID;

            ObjectGuid IllidanGateGUID;
            ObjectGuid IllidanDoorGUIDs[2];
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_black_temple_InstanceMapScript(map);
        }
};

void AddSC_instance_black_temple()
{
    new instance_black_temple();
}
