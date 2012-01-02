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

#include "ScriptPCH.h"
#include "ahnkahet.h"

/* Ahn'kahet encounters:
0 - Elder Nadox
1 - Prince Taldaram
2 - Jedoga Shadowseeker
3 - Herald Volazj
4 - Amanitar (Heroic only)
*/

#define MAX_ENCOUNTER           5

enum Achievements
{
    ACHIEV_VOLUNTEER_WORK                         = 2056
};

class instance_ahnkahet : public InstanceMapScript
{
public:
    instance_ahnkahet() : InstanceMapScript("instance_ahnkahet", 619) { }

    struct instance_ahnkahet_InstanceScript : public InstanceScript
    {
        instance_ahnkahet_InstanceScript(Map* map) : InstanceScript(map) {}

        uint64 Elder_Nadox;
        uint64 Prince_Taldaram;
        uint64 Jedoga_Shadowseeker;
        uint64 Herald_Volazj;
        uint64 Amanitar;

        uint64 Prince_TaldaramSpheres[2];
        uint64 Prince_TaldaramPlatform;
        uint64 Prince_TaldaramGate;

        std::set<uint64> InitiandGUIDs;
        uint64 JedogaSacrifices;
        uint64 JedogaTarget;

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        uint32 spheres[2];

        uint8 InitiandCnt;
        uint8 switchtrigger;

        std::string str_data;

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
            InitiandGUIDs.clear();

            Elder_Nadox =0;
            Prince_Taldaram =0;
            Jedoga_Shadowseeker =0;
            Herald_Volazj =0;
            Amanitar =0;

            spheres[0] = NOT_STARTED;
            spheres[1] = NOT_STARTED;

            InitiandCnt = 0;
            switchtrigger = 0;
            JedogaSacrifices = 0;
            JedogaTarget = 0;
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS) return true;

            return false;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case 29309: Elder_Nadox = creature->GetGUID();                     break;
                case 29308: Prince_Taldaram = creature->GetGUID();                 break;
                case 29310: Jedoga_Shadowseeker = creature->GetGUID();             break;
                case 29311: Herald_Volazj = creature->GetGUID();                   break;
                case 30258: Amanitar = creature->GetGUID();                        break;
                case 30114: InitiandGUIDs.insert(creature->GetGUID());             break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case 193564:     Prince_TaldaramPlatform = go->GetGUID();
                    if (m_auiEncounter[1] == DONE) HandleGameObject(0, true, go); break;
                case 193093:     Prince_TaldaramSpheres[0] = go->GetGUID();
                    if (spheres[0] == IN_PROGRESS)
                    {
                        go->SetGoState(GO_STATE_ACTIVE);
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    }
                    else go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    break;
                case 193094:     Prince_TaldaramSpheres[1] = go->GetGUID();
                    if (spheres[1] == IN_PROGRESS)
                    {
                        go->SetGoState(GO_STATE_ACTIVE);
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    }
                    else go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                    break;
                case 192236:    Prince_TaldaramGate = go->GetGUID(); // Web gate past Prince Taldaram
                    if (m_auiEncounter[1] == DONE)HandleGameObject(0, true, go);break;
            }
        }

        void SetData64(uint32 idx, uint64 guid)
        {
            switch (idx)
            {
                case DATA_ADD_JEDOGA_OPFER: JedogaSacrifices = guid; break;
                case DATA_PL_JEDOGA_TARGET: JedogaTarget = guid; break;
            }
        }

        uint64 GetData64(uint32 identifier)
        {
            switch (identifier)
            {
                case DATA_ELDER_NADOX:                return Elder_Nadox;
                case DATA_PRINCE_TALDARAM:            return Prince_Taldaram;
                case DATA_JEDOGA_SHADOWSEEKER:        return Jedoga_Shadowseeker;
                case DATA_HERALD_VOLAZJ:              return Herald_Volazj;
                case DATA_AMANITAR:                   return Amanitar;
                case DATA_SPHERE1:                    return Prince_TaldaramSpheres[0];
                case DATA_SPHERE2:                    return Prince_TaldaramSpheres[1];
                case DATA_PRINCE_TALDARAM_PLATFORM:   return Prince_TaldaramPlatform;
                case DATA_ADD_JEDOGA_INITIAND:
                {
                    std::vector<uint64> vInitiands;
                    vInitiands.clear();
                    for (std::set<uint64>::const_iterator itr = InitiandGUIDs.begin(); itr != InitiandGUIDs.end(); ++itr)
                    {
                        Creature* cr = instance->GetCreature(*itr);
                        if (cr && cr->isAlive())
                            vInitiands.push_back(*itr);
                    }
                    if (vInitiands.empty())
                        return 0;
                    uint8 j = urand(0, vInitiands.size() -1);
                    return vInitiands[j];
                }
                case DATA_ADD_JEDOGA_OPFER: return JedogaSacrifices;
                case DATA_PL_JEDOGA_TARGET: return JedogaTarget;
            }
            return 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case DATA_ELDER_NADOX_EVENT: m_auiEncounter[0] = data; break;
                case DATA_PRINCE_TALDARAM_EVENT:
                    if (data == DONE)
                        HandleGameObject(Prince_TaldaramGate, true);
                    m_auiEncounter[1] = data;
                    break;
                case DATA_JEDOGA_SHADOWSEEKER_EVENT:
                    m_auiEncounter[2] = data;
                    if (data == DONE)
                    {
                        for (std::set<uint64>::const_iterator itr = InitiandGUIDs.begin(); itr != InitiandGUIDs.end(); ++itr)
                        {
                            Creature* cr = instance->GetCreature(*itr);
                            if (cr && cr->isAlive())
                            {
                                cr->SetVisible(false);
                                cr->setDeathState(JUST_DIED);
                                cr->RemoveCorpse();
                            }
                        }
                    }
                    break;
                case DATA_HERALD_VOLAZJ_EVENT: m_auiEncounter[3] = data; break;
                case DATA_AMANITAR_EVENT: m_auiEncounter[4] = data; break;
                case DATA_SPHERE1_EVENT: spheres[0] = data; break;
                case DATA_SPHERE2_EVENT: spheres[1] = data; break;
                case DATA_JEDOGA_TRIGGER_SWITCH: switchtrigger = data; break;
                case DATA_JEDOGA_RESET_INITIANDS:
                    for (std::set<uint64>::const_iterator itr = InitiandGUIDs.begin(); itr != InitiandGUIDs.end(); ++itr)
                    {
                        Creature* cr = instance->GetCreature(*itr);
                        if (cr)
                        {
                            cr->Respawn();
                            if (!cr->IsInEvadeMode()) cr->AI()->EnterEvadeMode();
                        }
                    }
                    break;
            }
            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch (type)
            {
                case DATA_ELDER_NADOX_EVENT:            return m_auiEncounter[0];
                case DATA_PRINCE_TALDARAM_EVENT:        return m_auiEncounter[1];
                case DATA_JEDOGA_SHADOWSEEKER_EVENT:    return m_auiEncounter[2];
                case DATA_HERALD_VOLAZJ:                return m_auiEncounter[3];
                case DATA_AMANITAR_EVENT:                     return m_auiEncounter[4];
                case DATA_SPHERE1_EVENT:                return spheres[0];
                case DATA_SPHERE2_EVENT:                return spheres[1];
                case DATA_ALL_INITIAND_DEAD:
                    for (std::set<uint64>::const_iterator itr = InitiandGUIDs.begin(); itr != InitiandGUIDs.end(); ++itr)
                    {
                        Creature* cr = instance->GetCreature(*itr);
                        if (!cr || (cr && cr->isAlive())) return 0;
                    }
                    return 1;
                case DATA_JEDOGA_TRIGGER_SWITCH: return switchtrigger;
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "A K " << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' '
                << m_auiEncounter[2] << ' ' << m_auiEncounter[3] << ' ' << m_auiEncounter[4] << ' '
                << spheres[0] << ' ' << spheres[1];

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

            if (dataHead1 == 'A' && dataHead2 == 'K')
            {
                m_auiEncounter[0] = data0;
                m_auiEncounter[1] = data1;
                m_auiEncounter[2] = data2;
                m_auiEncounter[3] = data3;
                m_auiEncounter[4] = data4;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;

                spheres[0] = data5;
                spheres[1] = data6;

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
       return new instance_ahnkahet_InstanceScript(map);
    }
};

void AddSC_instance_ahnkahet()
{
   new instance_ahnkahet;
}
