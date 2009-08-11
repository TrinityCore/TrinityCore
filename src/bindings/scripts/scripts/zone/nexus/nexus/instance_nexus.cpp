/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Instance_Nexus
SD%Complete:
SDComment:
SDCategory: The Nexus, The Nexus
EndScriptData */

#include "precompiled.h"
#include "def_nexus.h"

#define NUMBER_OF_ENCOUNTERS      4

struct TRINITY_DLL_DECL instance_nexus : public ScriptedInstance
{
    instance_nexus(Map *Map) : ScriptedInstance(Map) { Initialize(); }

    uint32 Encounters[NUMBER_OF_ENCOUNTERS];

    uint64 Anomalus;
    uint64 Keristrasza;

    uint64 AnomalusContainmentSphere;
    uint64 OrmoroksContainmentSphere;
    uint64 TelestrasContainmentSphere;

    std::string strInstData;

    void Initialize()
    {
        Anomalus = 0;
        for(uint8 i = 0; i < NUMBER_OF_ENCOUNTERS; i++)
            Encounters[i] = NOT_STARTED;
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        Map::PlayerList const& players = instance->GetPlayers();
        uint32 TeamInInstance = 0;

        if (!players.isEmpty())
        {
            if (Player* pPlayer = players.begin()->getSource())
            {
                TeamInInstance = pPlayer->GetTeam();
            }
        }
        switch(pCreature->GetEntry())
        {
            case 26763: Anomalus = pCreature->GetGUID(); break;
            case 26723: Keristrasza = pCreature->GetGUID(); break;
            case 26800:
                {
                    //26799
                    pCreature->setFaction(16);
                    if (TeamInInstance == ALLIANCE)
                        pCreature->SetDisplayId(24358);
                    break;
                }
            case 26802:
                {
                    //26801
                    pCreature->setFaction(16);
                    if (TeamInInstance == ALLIANCE)
                        pCreature->SetDisplayId(24354);
                    break;
                }
            case 26805:
                {
                    //26803
                    pCreature->setFaction(16);
                    if (TeamInInstance == ALLIANCE)
                        pCreature->SetDisplayId(24357);
                    break;
                }
            case 27949:
                {
                    //27947
                    pCreature->setFaction(16);
                    if (TeamInInstance == ALLIANCE)
                        pCreature->SetDisplayId(24352);
                    break;
                }
            case 26796: 
                {
                    //26798
                    pCreature->setFaction(16);
                    if (TeamInInstance == ALLIANCE)
                        pCreature->SetDisplayId(24352);
                    break;
                }
        }
    }

    void OnGameObjectCreate(GameObject *go, bool add)
    {
        switch(go->GetEntry())
        {
            case 188527:
            {
                AnomalusContainmentSphere = go->GetGUID();
                if(Encounters[1] == DONE)
                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            }
            case 188528:
            {
                OrmoroksContainmentSphere = go->GetGUID();
                if(Encounters[2] == DONE)
                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            }
            case 188526:
            {
                TelestrasContainmentSphere = go->GetGUID();
                if(Encounters[0] == DONE)
                    go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            }
        }
    }

    uint32 GetData(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_MAGUS_TELESTRA_EVENT: return Encounters[0];
            case DATA_ANOMALUS_EVENT:       return Encounters[1];
            case DATA_ORMOROK_EVENT:        return Encounters[2];
            case DATA_KERISTRASZA_EVENT:    return Encounters[3];
        }
        return 0;
    }

    void SetData(uint32 identifier, uint32 data)
    {
        switch(identifier)
        {
            case DATA_MAGUS_TELESTRA_EVENT:
            {
                if(data == DONE)
                {
                    GameObject *Sphere = instance->GetGameObject(TelestrasContainmentSphere);
                    if(Sphere)
                        Sphere->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                }
                Encounters[0] = data;
                break;
            }
            case DATA_ANOMALUS_EVENT:
            {
                if(data == DONE)
                {
                    GameObject *Sphere = instance->GetGameObject(AnomalusContainmentSphere);
                    if(Sphere)
                        Sphere->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                }
                Encounters[1] = data;
                break;
            }
            case DATA_ORMOROK_EVENT:
            {
                if(data == DONE)
                {
                    GameObject *Sphere = instance->GetGameObject(OrmoroksContainmentSphere);
                    if(Sphere)
                        Sphere->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                }
                Encounters[2] = data;
                break;
            }
            case DATA_KERISTRASZA_EVENT:    Encounters[3] = data; break;
        }

        if (data == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << Encounters[0] << " " << Encounters[1] << " " << Encounters[2] << " "
                << Encounters[3];

            strInstData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    uint64 GetData64(uint32 uiIdentifier)
    {
        switch(uiIdentifier)
        {
            case DATA_ANOMALUS:                 return Anomalus;
            case DATA_KERISTRASZA:              return Keristrasza;
            case ANOMALUS_CONTAINMET_SPHERE:    return AnomalusContainmentSphere;
            case ORMOROKS_CONTAINMET_SPHERE:    return OrmoroksContainmentSphere;
            case TELESTRAS_CONTAINMET_SPHERE:   return TelestrasContainmentSphere;
        }
        return 0;
    }

    std::string GetSaveData()
    {
        return strInstData;
    }

    void Load(const char* chrIn)
    {
        if (!chrIn)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(chrIn);

        std::istringstream loadStream(chrIn);
        loadStream >> Encounters[0] >> Encounters[1] >> Encounters[2] >> Encounters[3];

        for(uint8 i = 1; i < NUMBER_OF_ENCOUNTERS; ++i)
        {
            if (Encounters[i] == IN_PROGRESS)
                Encounters[i] = NOT_STARTED;
        }

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_nexus(Map* map)
{
    return new instance_nexus(map);
}

void AddSC_instance_nexus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_nexus";
    newscript->GetInstanceData = &GetInstanceData_instance_nexus;
    newscript->RegisterSelf();
}
