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
SDName: Instance_Trial_Of_the_Champion
SD%Complete: 100
SDComment: 
SDCategory: Trial Of the Champion
EndScriptData */

#include "precompiled.h"
#include "trial_of_the_champion.h"

struct TRINITY_DLL_DECL instance_trial_of_the_champion : public ScriptedInstance
{
    instance_trial_of_the_champion(Map* pMap) : ScriptedInstance(pMap), m_uiChampionsLootGUID(NULL), m_uiPaletressLootGUID(NULL), m_uiEadricLootGUID(NULL) { Initialize(); }

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string strInstData;

    uint64 m_uiEadricGUID;
    uint64 m_uiPaletressGUID;
    uint64 m_uiBlackKnightGUID;
    uint64 m_uiJaerenGUID;
    uint64 m_uiArelasGUID;
    uint64 m_uiAnnouncerGUID;
    uint64 m_uiBlackKnightMinionGUID;
    uint64 m_uiArgentChallenger;
    uint64 m_uiMemoryGUID;

    GameObject* m_uiChampionsLootGUID;
    GameObject* m_uiPaletressLootGUID;
    GameObject* m_uiEadricLootGUID;

    void Initialize()
    {
		m_uiChampionsLootGUID	= 0;
		m_uiEadricGUID			= 0;
		m_uiEadricLootGUID		= 0;
		m_uiPaletressGUID		= 0;
		m_uiPaletressLootGUID	= 0;
		m_uiBlackKnightGUID		= 0;
		m_uiJaerenGUID			= 0;
		m_uiArelasGUID			= 0;
		m_uiAnnouncerGUID		= 0;
		m_uiBlackKnightMinionGUID = 0;
		m_uiArgentChallenger	= 0;
		m_uiMemoryGUID			= 0;

        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
        {
            if (m_auiEncounter[i] == IN_PROGRESS)
                return true;
        }

        return false;
    }

    void OnCreatureCreate(Creature* pCreature, bool bAdd)
    {
        Map::PlayerList const &players = instance->GetPlayers();
        uint32 TeamInInstance = 0;

        if (!players.isEmpty())
        {
            if (Player* pPlayer = players.begin()->getSource())
                TeamInInstance = pPlayer->GetTeam();
        }
        switch(pCreature->GetEntry())
        {

            // Champions
            case NPC_MOKRA:
                if (TeamInInstance == HORDE)
                    pCreature->UpdateEntry(NPC_JACOB, ALLIANCE);
                break;
            case NPC_ERESSEA:
                if (TeamInInstance == HORDE)
                    pCreature->UpdateEntry(NPC_AMBROSE, ALLIANCE);
                break;
            case NPC_RUNOK:
                if (TeamInInstance == HORDE)
                    pCreature->UpdateEntry(NPC_COLOSOS, ALLIANCE);
                break;
            case NPC_ZULTORE:
                if (TeamInInstance == HORDE)
                    pCreature->UpdateEntry(NPC_JAELYNE, ALLIANCE);
                break;
	    case NPC_VISCERI:
                if (TeamInInstance == HORDE)
                    pCreature->UpdateEntry(NPC_LANA, ALLIANCE);
                break;

            // Argent Challenge
	    case NPC_EADRIC:
                m_uiEadricGUID = pCreature->GetGUID();
		    m_uiArgentChallenger = pCreature->GetGUID();
                break;
            case NPC_PALETRESS:
                m_uiPaletressGUID = pCreature->GetGUID();
		    m_uiArgentChallenger = pCreature->GetGUID();
                break;

	    // Black Knight
            case NPC_BLACK_KNIGHT:
                m_uiBlackKnightGUID = pCreature->GetGUID();
                break;
	    case NPC_RISEN_JAEREN:
                m_uiBlackKnightMinionGUID = pCreature->GetGUID();
                break;
            case NPC_RISEN_ARELAS:
                m_uiBlackKnightMinionGUID = pCreature->GetGUID();
                break;

	    // Coliseum Announcers
            case NPC_JAEREN:
                m_uiJaerenGUID = pCreature->GetGUID();
                break;
            case NPC_ARELAS:
                m_uiArelasGUID = pCreature->GetGUID();
                break;

	    // memories
	    case MEMORY_ALGALON:
		m_uiMemoryGUID = pCreature->GetGUID();
		break;
	    case MEMORY_ARCHIMONDE:
		m_uiMemoryGUID = pCreature->GetGUID();
		break;
	    case MEMORY_CHROMAGGUS:
		m_uiMemoryGUID = pCreature->GetGUID();
		break;
			case MEMORY_CYANIGOSA:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_DELRISSA:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_ECK:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_ENTROPIUS:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_GRUUL:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_HAKKAR:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_HEIGAN:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_HEROD:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_HOGGER:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_IGNIS:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_ILLIDAN:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_INGVAR:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_KALITHRESH:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_LUCIFRON:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_MALCHEZAAR:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_MUTANUS:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_ONYXIA:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_THUNDERAAN:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_VANCLEEF:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_VASHJ:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_VEKNILASH:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
			case MEMORY_VEZAX:
				m_uiMemoryGUID = pCreature->GetGUID();
				break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
	switch(pGo->GetEntry())
        {
	    case GO_CHAMPIONS_LOOT: m_uiChampionsLootGUID = add ? pGo : NULL; break;
	    case GO_EADRIC_LOOT: m_uiEadricLootGUID = add ? pGo : NULL; break;
	    case GO_PALETRESS_LOOT: m_uiPaletressLootGUID = add ? pGo : NULL; break;
	    case GO_CHAMPIONS_LOOT_H: m_uiChampionsLootGUID = add ? pGo : NULL; break;
	    case GO_EADRIC_LOOT_H: m_uiEadricLootGUID = add ? pGo : NULL; break;
	    case GO_PALETRESS_LOOT_H: m_uiPaletressLootGUID = add ? pGo : NULL; break;
	}
    }

    void SetData(uint32 Type, uint32 Data)
    {
        switch(Type)
        {
	    case DATA_TOC5_ANNOUNCER:
		m_uiAnnouncerGUID = Data;
		break;
	    case DATA_BLACK_KNIGHT_MINION:
		m_uiBlackKnightMinionGUID = Data;
		break;
            case TYPE_GRAND_CHAMPIONS:
                if (Data == DONE)
                    m_uiChampionsLootGUID->SetRespawnTime(m_uiChampionsLootGUID->GetRespawnDelay());
                m_auiEncounter[0] = Data;
                break;
            case TYPE_ARGENT_CHALLENGE:
                if (Data == DONE)
                {
                    if(m_uiEadricGUID == m_uiArgentChallenger)
                        m_uiEadricLootGUID->SetRespawnTime(m_uiEadricLootGUID->GetRespawnDelay());
                    if(m_uiPaletressGUID == m_uiArgentChallenger)
                        m_uiPaletressLootGUID->SetRespawnTime(m_uiPaletressLootGUID->GetRespawnDelay());
                }
                m_auiEncounter[1] = Data;
                break;
            case TYPE_BLACK_KNIGHT:
		m_auiEncounter[2] = Data;
                break;
        }

        if (Data == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2];

            strInstData = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    uint64 GetData64(uint32 uiData)
    {
        switch(uiData)
        {
	    case DATA_MEMORY:
		return m_uiMemoryGUID;
	    case DATA_BLACK_KNIGHT:
                return m_uiBlackKnightGUID;
        }

        return 0;
    }

    std::string GetSaveData()
    {
        return strInstData;
    }

    uint32 GetData(uint32 uiType)
    {
        switch(uiType)
        {
			case DATA_BLACK_KNIGHT_MINION:
				return m_uiBlackKnightMinionGUID;
			case DATA_TOC5_ANNOUNCER:
				return m_uiAnnouncerGUID;
			case DATA_JAEREN:
				return m_uiJaerenGUID;
			case DATA_ARELAS:
				return m_uiArelasGUID;
            case TYPE_GRAND_CHAMPIONS:
            case TYPE_ARGENT_CHALLENGE:
            case TYPE_BLACK_KNIGHT:
		return m_auiEncounter[uiType];
        }

        return 0;
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
        loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2];

        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS)
                m_auiEncounter[i] = NOT_STARTED;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_trial_of_the_champion(Map* pMap)
{
    return new instance_trial_of_the_champion(pMap);
}

void AddSC_instance_trial_of_the_champion()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_trial_of_the_champion";
    newscript->GetInstanceData = &GetInstanceData_instance_trial_of_the_champion;
    newscript->RegisterSelf();
}
