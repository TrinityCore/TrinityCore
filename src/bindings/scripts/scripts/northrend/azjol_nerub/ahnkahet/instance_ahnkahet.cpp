/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

/* ScriptData
SDName: Instance_Azjol_Nerub
SD%Complete: 0
SDComment:
SDCategory: Azjol Nerub
EndScriptData */

#include "precompiled.h"
#include "def_ahnkahet.h"

#define MAX_ENCOUNTER     5

/* Ahn'kahet encounters:
0 - Elder Nadox
1 - Prince Taldaram
2 - Jedoga Shadowseeker
3 - Herald Volazj
4 - Amanitar (Heroic only)
*/

struct TRINITY_DLL_DECL instance_ahnkahet : public ScriptedInstance
{
    instance_ahnkahet(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint64 Elder_Nadox;
    uint64 Prince_Taldaram;
    uint64 Jedoga_Shadowseeker;
    uint64 Herald_Volazj;
    uint64 Amanitar;
   
    uint64 Prince_TaldaramSpheres[2];
    uint64 Prince_TaldaramPlatform;
    uint64 Prince_TaldaramGate;

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    uint32 spheres[2];

    void Initialize()
    {
         Elder_Nadox =0;
         Prince_Taldaram =0;
         Jedoga_Shadowseeker =0;
         Herald_Volazj =0;
         Amanitar =0;
         
         for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
             m_auiEncounter[i] = NOT_STARTED;
        spheres[0] = NOT_STARTED;
        spheres[1] = NOT_STARTED;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS) return true;

        return false;
    }


    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case 29309:    Elder_Nadox = pCreature->GetGUID();                   break;
            case 29308:    Prince_Taldaram = pCreature->GetGUID();               break;
            case 29310:    Jedoga_Shadowseeker = pCreature->GetGUID();           break;
            case 29311:    Herald_Volazj = pCreature->GetGUID();                 break;
            case 30258:    Amanitar = pCreature->GetGUID();                      break;
        }
    }
    
    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
            case 193564:     Prince_TaldaramPlatform = pGo->GetGUID();
                if (m_auiEncounter[1] == DONE) HandleGameObject(NULL,true,pGo); break;
            case 193093:     Prince_TaldaramSpheres[0] = pGo->GetGUID();
                if (spheres[0] == IN_PROGRESS)
                {
                    pGo->SetGoState(GO_STATE_ACTIVE);
                    pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                }
                else pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            case 193094:     Prince_TaldaramSpheres[1] = pGo->GetGUID();
                if (spheres[1] == IN_PROGRESS)
                {
                    pGo->SetGoState(GO_STATE_ACTIVE);
                    pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                }
                else pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            case 192236:    Prince_TaldaramGate = pGo->GetGUID(); // Web gate past Prince Taldaram
                if (m_auiEncounter[1] == DONE)HandleGameObject(NULL,true,pGo);break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_ELDER_NADOX:                return Elder_Nadox;
            case DATA_PRINCE_TALDARAM:            return Prince_Taldaram;
            case DATA_JEDOGA_SHADOWSEEKER:        return Jedoga_Shadowseeker;
            case DATA_HERALD_VOLAZJ:              return Herald_Volazj;
            case DATA_AMANITAR:                   return Amanitar;
            case DATA_SPHERE1:                    return Prince_TaldaramSpheres[0];
            case DATA_SPHERE2:                    return Prince_TaldaramSpheres[1];
            case DATA_PRINCE_TALDARAM_PLATFORM:   return Prince_TaldaramPlatform;
        }
        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
        case DATA_ELDER_NADOX_EVENT:
            m_auiEncounter[0] = data;break;
        case DATA_PRINCE_TALDARAM_EVENT:
	    if (data == DONE)
	    {
	        HandleGameObject(Prince_TaldaramGate,true);
	    }
            m_auiEncounter[1] = data; break;
        case DATA_JEDOGA_SHADOWSEEKER_EVENT:
            m_auiEncounter[2] = data; break;
        case DATA_HERALD_VOLAZJ:
            m_auiEncounter[3] = data; break;
        case DATA_AMANITAR:
            m_auiEncounter[4] = data; break;
        case DATA_SPHERE1_EVENT:
            spheres[0] = data; break;
        case DATA_SPHERE2_EVENT:
            spheres[1] = data; break;
	}

        if (data == DONE)
        {
            SaveToDB();
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_ELDER_NADOX_EVENT:            return m_auiEncounter[0];
            case DATA_PRINCE_TALDARAM_EVENT:        return m_auiEncounter[1];
            case DATA_JEDOGA_SHADOWSEEKER_EVENT:    return m_auiEncounter[2];
            case DATA_HERALD_VOLAZJ:                return m_auiEncounter[3];
            case DATA_AMANITAR:                     return m_auiEncounter[4];
            case DATA_SPHERE1_EVENT:                return spheres[0];
            case DATA_SPHERE2_EVENT:                return spheres[1];
        }
        return 0;
    }

   std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::string str_data;

        std::ostringstream saveStream;
        saveStream << "A K " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
            << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << m_auiEncounter[4] << " "
            << spheres[0] << " " << spheres[1];

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
        uint16 data0,data1,data2,data3,data4, data5, data6;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4 >> data5 >> data6;

        if (dataHead1 == 'A' && dataHead2 == 'K')
        {
            m_auiEncounter[0] = data0;
            m_auiEncounter[1] = data1;
            m_auiEncounter[2] = data2;
            m_auiEncounter[3] = data3;
            m_auiEncounter[4] = data4;

            for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;

            spheres[0] = data5;
            spheres[1] = data6;

        }else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_ahnkahet(Map* pMap)
{
   return new instance_ahnkahet(pMap);
}

void AddSC_instance_ahnkahet()
{
   Script *newscript;
   newscript = new Script;
   newscript->Name = "instance_ahnkahet";
   newscript->GetInstanceData = &GetInstanceData_instance_ahnkahet;
   newscript->RegisterSelf();
}
