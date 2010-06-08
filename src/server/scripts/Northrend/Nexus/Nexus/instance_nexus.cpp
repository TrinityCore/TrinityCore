/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * Copyright (C) 2008 - 2010 TrinityCore <http://www.trinitycore.org>
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

#include "ScriptPCH.h"
#include "nexus.h"

#define NUMBER_OF_ENCOUNTERS      4

enum Factions
{
    FACTION_HOSTILE_FOR_ALL                       = 16
};

struct instance_nexus : public ScriptedInstance
{
    instance_nexus(Map *pMap) : ScriptedInstance(pMap) { Initialize(); }

    uint32 m_auiEncounter[NUMBER_OF_ENCOUNTERS];

    uint64 Anomalus;
    uint64 Keristrasza;

    uint64 AnomalusContainmentSphere;
    uint64 OrmoroksContainmentSphere;
    uint64 TelestrasContainmentSphere;

    std::string strInstData;

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        Anomalus = 0;
        Keristrasza = 0;
    }

    void OnCreatureCreate(Creature *pCreature, bool /*bAdd*/)
    {
        Map::PlayerList const &players = instance->GetPlayers();
        uint32 TeamInInstance = 0;

        if (!players.isEmpty())
        {
            if (Player* pPlayer = players.begin()->getSource())
                TeamInInstance = pPlayer->GetTeam();
        }
        switch (pCreature->GetEntry())
        {
            case 26763:
                Anomalus = pCreature->GetGUID();
                break;
            case 26723:
                Keristrasza = pCreature->GetGUID();
                break;
            // Alliance npcs are spawned by default, if you are alliance, you will fight against horde npcs.
            case 26800:
            {
                if (ServerAllowsTwoSideGroups())
                    pCreature->setFaction(FACTION_HOSTILE_FOR_ALL);
                if (TeamInInstance == ALLIANCE)
                    pCreature->UpdateEntry(26799, HORDE);
                break;
            }
            case 26802:
            {
                if (ServerAllowsTwoSideGroups())
                    pCreature->setFaction(FACTION_HOSTILE_FOR_ALL);
                if (TeamInInstance == ALLIANCE)
                    pCreature->UpdateEntry(26801, HORDE);
                break;
            }
            case 26805:
            {
                if (ServerAllowsTwoSideGroups())
                    pCreature->setFaction(FACTION_HOSTILE_FOR_ALL);
                if (TeamInInstance == ALLIANCE)
                    pCreature->UpdateEntry(26803, HORDE);
                break;
            }
            case 27949:
            {
                if (ServerAllowsTwoSideGroups())
                    pCreature->setFaction(FACTION_HOSTILE_FOR_ALL);
                if (TeamInInstance == ALLIANCE)
                    pCreature->UpdateEntry(27947, HORDE);
                break;
            }
            case 26796:
            {
                if (ServerAllowsTwoSideGroups())
                    pCreature->setFaction(FACTION_HOSTILE_FOR_ALL);
                if (TeamInInstance == ALLIANCE)
                    pCreature->UpdateEntry(26798, HORDE);
                break;
            }
        }
    }

    void OnGameObjectCreate(GameObject *pGo, bool /*bAdd*/)
    {
        switch (pGo->GetEntry())
        {
            case 188527:
            {
                AnomalusContainmentSphere = pGo->GetGUID();
                if (m_auiEncounter[1] == DONE)
                    pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            }
            case 188528:
            {
                OrmoroksContainmentSphere = pGo->GetGUID();
                if (m_auiEncounter[2] == DONE)
                    pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            }
            case 188526:
            {
                TelestrasContainmentSphere = pGo->GetGUID();
                if (m_auiEncounter[0] == DONE)
                    pGo->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                break;
            }
        }
    }

    uint32 GetData(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_MAGUS_TELESTRA_EVENT: return m_auiEncounter[0];
            case DATA_ANOMALUS_EVENT:       return m_auiEncounter[1];
            case DATA_ORMOROK_EVENT:        return m_auiEncounter[2];
            case DATA_KERISTRASZA_EVENT:    return m_auiEncounter[3];
        }
        return 0;
    }

    void SetData(uint32 identifier, uint32 data)
    {
        switch (identifier)
        {
            case DATA_MAGUS_TELESTRA_EVENT:
            {
                if (data == DONE)
                {
                    GameObject *Sphere = instance->GetGameObject(TelestrasContainmentSphere);
                    if (Sphere)
                        Sphere->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                }
                m_auiEncounter[0] = data;
                break;
            }
            case DATA_ANOMALUS_EVENT:
            {
                if (data == DONE)
                {
                    if (GameObject *Sphere = instance->GetGameObject(AnomalusContainmentSphere))
                        Sphere->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                }
                m_auiEncounter[1] = data;
                break;
            }
            case DATA_ORMOROK_EVENT:
            {
                if (data == DONE)
                {
                    if (GameObject *Sphere = instance->GetGameObject(OrmoroksContainmentSphere))
                        Sphere->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                }
                m_auiEncounter[2] = data;
                break;
            }
            case DATA_KERISTRASZA_EVENT:
                m_auiEncounter[3] = data;
                break;
        }

        if (data == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " "
                << m_auiEncounter[3];

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

    void Load(const char *chrIn)
    {
        if (!chrIn)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }

        OUT_LOAD_INST_DATA(chrIn);

        std::istringstream loadStream(chrIn);
        loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3];

        for (uint8 i = 0; i < NUMBER_OF_ENCOUNTERS; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS)
                m_auiEncounter[i] = NOT_STARTED;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData *GetInstanceData_instance_nexus(Map *pMap)
{
    return new instance_nexus(pMap);
}

void AddSC_instance_nexus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_nexus";
    newscript->GetInstanceData = &GetInstanceData_instance_nexus;
    newscript->RegisterSelf();
}
