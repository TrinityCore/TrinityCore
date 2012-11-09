/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 
#include"ScriptPCH.h"
#include"halls_of_origination.h"

#define ENCOUNTERS 7

/* Boss Encounters
   Temple Guardian Anhuur
   Earthrager Ptah
   Anraphet
   Isiset
   Ammunae
   Setesh
   Rajh
*/

class instance_halls_of_origination : public InstanceMapScript
{
public:
    instance_halls_of_origination() : InstanceMapScript("instance_halls_of_origination", 644) { }

    InstanceScript* GetInstanceScript(InstanceMap *map) const
    {
        return new instance_halls_of_origination_InstanceMapScript(map);
    }

    struct instance_halls_of_origination_InstanceMapScript: public InstanceScript
    {
        instance_halls_of_origination_InstanceMapScript(InstanceMap *map) : InstanceScript(map) { }

        uint32 Encounter[ENCOUNTERS];

        uint64 TempleGuardianAnhuur;
        uint64 EarthragerPtah;
        uint64 Anraphet;
        uint64 Isiset;
        uint64 Ammunae;
        uint64 Setesh;
        uint64 Rajh;
        uint64 OriginationElevatorGUID;
        uint64 TeamInInstance;
        uint64 AnhuurBridgeGUID;

        void Initialize()
        {
            TempleGuardianAnhuur = 0;
            EarthragerPtah = 0;
            Anraphet = 0;
            Isiset = 0;
            Ammunae = 0;
            Setesh = 0;
            Rajh = 0;
            AnhuurBridgeGUID = 0;
            uint64 OriginationElevatorGUID = 0;

            for (uint8 i=0; i<ENCOUNTERS; ++i)
                Encounter[i] = NOT_STARTED;
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i=0; i<ENCOUNTERS; ++i)
            {
                if (Encounter[i] == IN_PROGRESS)
                    return true;
            }

            return false;
        }

        void OnCreatureCreate(Creature* creature, bool)
        {
            switch (creature->GetEntry())
            {
                case BOSS_TEMPLE_GUARDIAN_ANHUUR:
                    TempleGuardianAnhuur = creature->GetGUID();
                    break;
                case BOSS_EARTHRAGER_PTAH:
                    EarthragerPtah = creature->GetGUID();
                    break;
                case BOSS_ANRAPHET:
                    Anraphet = creature->GetGUID();
                    break;
                case BOSS_ISISET:
                    Isiset = creature->GetGUID();
                    break;
                case BOSS_AMMUNAE:
                    Ammunae = creature->GetGUID();
                    break;
                case BOSS_SETESH:
                    Setesh = creature->GetGUID();
                case BOSS_RAJH:
                    Rajh = creature->GetGUID();
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry()) /* Elevator active switch to second level. Need more info on Id */
            {
                case GO_ORIGINATION_ELEVATOR:
                    OriginationElevatorGUID = go->GetGUID();
                    if (GetData(DATA_TEMPLE_GUARDIAN_ANHUUR) == DONE && GetData(DATA_ANRAPHET) == DONE && GetData(DATA_EARTHRAGER_PTAH) == DONE)
                        {
                            go->SetUInt32Value(GAMEOBJECT_LEVEL, 0);
                            go->SetGoState(GO_STATE_READY);
                        }
                    break;
                case GO_ANHUUR_BRIDGE:
                    AnhuurBridgeGUID = go->GetGUID();
                    if (GetData(DATA_TEMPLE_GUARDIAN_ANHUUR) == DONE)
                            HandleGameObject(AnhuurBridgeGUID, true, go);
                    break;
            }
        }

        uint64 GetData64(uint32 identifier)
        {
            switch (identifier)
            {
                case DATA_TEMPLE_GUARDIAN_ANHUUR:
                    return TempleGuardianAnhuur;
                case DATA_EARTHRAGER_PTAH:
                    return EarthragerPtah;
                case DATA_ANRAPHET:
                    return Anraphet;
                case DATA_ISISET:
                    return Isiset;
                case DATA_AMMUNAE:
                    return Ammunae;
                case DATA_SETESH:
                    return Setesh;
                case DATA_RAJH:
                    return Rajh;
            }
            return 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case DATA_TEMPLE_GUARDIAN_ANHUUR:
                    Encounter[0] = data;
                    break;
                case DATA_EARTHRAGER_PTAH:
                    Encounter[1] = data;
                    break;
                case DATA_ANRAPHET:
                    Encounter[2] = data;
                    break;
                case DATA_ISISET:
                    Encounter[3] = data;
                    break;
                case DATA_AMMUNAE:
                    Encounter[4] = data;
                    break;
                case DATA_SETESH:
                    Encounter[5] = data;
                    break;
                case DATA_RAJH:
                    Encounter[6] = data;
                    break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch (type)
            {
                case DATA_TEMPLE_GUARDIAN_ANHUUR:
                    return Encounter[0];
                case DATA_EARTHRAGER_PTAH:
                    return Encounter[1];
                case DATA_ANRAPHET:
                    return Encounter[2];
                case DATA_ISISET:
                    return Encounter[3];
                case DATA_AMMUNAE:
                    return Encounter[4];
                case DATA_SETESH:
                    return Encounter[5];
                case DATA_RAJH:
                    return Encounter[6];
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::string str_data;
            std::ostringstream saveStream;
            saveStream << "H O" << Encounter[0] << " " << Encounter[1]  << " " << Encounter[2]  << " " << Encounter[3] << " " << Encounter[4] << " " << Encounter[5] << " " << Encounter[6];
            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint16 data0, data1, data2, data3, data4, data5, data6;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4 >> data5 >> data6;

            if (dataHead1 == 'H' && dataHead2 == 'O')
            {
                Encounter[0] = data0;
                Encounter[1] = data1;
                Encounter[2] = data2;
                Encounter[3] = data3;
                Encounter[4] = data4;
                Encounter[5] = data5;
                Encounter[6] = data6;

                for (uint8 i=0; i<ENCOUNTERS; ++i)
                    if (Encounter[i] == IN_PROGRESS)
                        Encounter[i] = NOT_STARTED;
            }
            else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };
};

void AddSC_instance_halls_of_origination()
{
    new instance_halls_of_origination();
}