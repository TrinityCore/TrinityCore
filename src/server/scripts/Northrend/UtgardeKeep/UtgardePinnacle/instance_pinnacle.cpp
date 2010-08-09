/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "utgarde_pinnacle.h"

#define MAX_ENCOUNTER     4

/* Utgarde Pinnacle encounters:
0 - Svala Sorrowgrave
1 - Gortok Palehoof
2 - Skadi the Ruthless
3 - King Ymiron
*/

enum GameObjects
{
    ENTRY_SKADI_THE_RUTHLESS_DOOR                 = 192173,
    ENTRY_KING_YMIRON_DOOR                        = 192174,
    ENTRY_GORK_PALEHOOF_SPHERE                    = 188593
};

struct instance_pinnacle : public InstanceScript
{
    instance_pinnacle(Map* pMap) : InstanceScript(pMap) {Initialize();};

    uint64 uiSvalaSorrowgrave;
    uint64 uiGortokPalehoof;
    uint64 uiSkadiTheRuthless;
    uint64 uiKingYmiron;

    uint64 uiSkadiTheRuthlessDoor;
    uint64 uiKingYmironDoor;
    uint64 uiGortokPalehoofSphere;

    uint64 uiFrenziedWorgen;
    uint64 uiRavenousFurbolg;
    uint64 uiFerociousRhino;
    uint64 uiMassiveJormungar;
    uint64 uiPalehoofOrb;

    uint64 uiSvala;
    uint64 uiSacrificedPlayer;

    uint32 m_auiEncounter[MAX_ENCOUNTER];

    std::string str_data;

    void Initialize()
    {
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
           m_auiEncounter[i] = NOT_STARTED;

        uiSvalaSorrowgrave = 0;
        uiGortokPalehoof = 0;
        uiSkadiTheRuthless = 0;
        uiKingYmiron = 0;

        uiSkadiTheRuthlessDoor = 0;
        uiKingYmironDoor = 0;
        uiGortokPalehoofSphere = 0;

        uiFrenziedWorgen = 0;
        uiRavenousFurbolg = 0;
        uiFerociousRhino = 0;
        uiMassiveJormungar = 0;
        uiPalehoofOrb = 0;

        uiSvala = 0;
        uiSacrificedPlayer = 0;
    }

    bool IsEncounterInProgress() const
    {
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS) return true;

        return false;
    }

    void OnCreatureCreate(Creature* pCreature, bool /*add*/)
    {
        switch(pCreature->GetEntry())
        {
            case BOSS_SVALA_SORROWGRAVE:  uiSvalaSorrowgrave = pCreature->GetGUID();  break;
            case BOSS_GORTOK_PALEHOOF:    uiGortokPalehoof = pCreature->GetGUID();    break;
            case BOSS_SKADI_RUTHLESS:     uiSkadiTheRuthless = pCreature->GetGUID();  break;
            case BOSS_KING_YMIRON:        uiKingYmiron = pCreature->GetGUID();        break;
            case MOB_FRENZIED_WORGEN:     uiFrenziedWorgen = pCreature->GetGUID();    break;
            case MOB_RAVENOUS_FURBOLG:    uiRavenousFurbolg = pCreature->GetGUID();   break;
            case MOB_MASSIVE_JORMUNGAR:   uiMassiveJormungar = pCreature->GetGUID();  break;
            case MOB_FEROCIOUS_RHINO:     uiFerociousRhino = pCreature->GetGUID();    break;
            case MOB_SVALA:               uiSvala = pCreature->GetGUID();             break;
            case MOB_PALEHOOF_ORB:        uiPalehoofOrb = pCreature->GetGUID();       break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool /*add*/)
    {
        switch(pGo->GetEntry())
        {
            case ENTRY_SKADI_THE_RUTHLESS_DOOR:
                uiSkadiTheRuthlessDoor = pGo->GetGUID();
                if (m_auiEncounter[2] == DONE) HandleGameObject(NULL,true,pGo);
                break;
            case ENTRY_KING_YMIRON_DOOR:
                uiKingYmironDoor = pGo->GetGUID();
                if (m_auiEncounter[3] == DONE) HandleGameObject(NULL,true,pGo);
                break;
            case ENTRY_GORK_PALEHOOF_SPHERE:
                uiGortokPalehoofSphere = pGo->GetGUID();
                if (m_auiEncounter[1] == DONE)
                {
                    HandleGameObject(NULL,true,pGo);
                    pGo->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                }
                break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_SVALA_SORROWGRAVE_EVENT:
                m_auiEncounter[0] = data;
                break;
            case DATA_GORTOK_PALEHOOF_EVENT:
                m_auiEncounter[1] = data;
                break;
            case DATA_SKADI_THE_RUTHLESS_EVENT:
                if (data == DONE)
                    HandleGameObject(uiSkadiTheRuthlessDoor,true);
                m_auiEncounter[2] = data;
                break;
            case DATA_KING_YMIRON_EVENT:
                if (data == DONE)
                    HandleGameObject(uiKingYmironDoor,true);
                m_auiEncounter[3] = data;
                break;
        }

        if (data == DONE)
            SaveToDB();
    }

    void SetData64(uint32 type, uint64 data)
    {
        if (type == DATA_SACRIFICED_PLAYER)
            uiSacrificedPlayer = data;
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_SVALA_SORROWGRAVE_EVENT:        return m_auiEncounter[0];
            case DATA_GORTOK_PALEHOOF_EVENT:          return m_auiEncounter[1];
            case DATA_SKADI_THE_RUTHLESS_EVENT:       return m_auiEncounter[2];
            case DATA_KING_YMIRON_EVENT:              return m_auiEncounter[3];
        }
        return 0;
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_SVALA_SORROWGRAVE:      return uiSvalaSorrowgrave;
            case DATA_GORTOK_PALEHOOF:        return uiGortokPalehoof;
            case DATA_SKADI_THE_RUTHLESS:     return uiSkadiTheRuthless;
            case DATA_KING_YMIRON:            return uiKingYmiron;
            case DATA_MOB_FRENZIED_WORGEN:    return uiFrenziedWorgen;
            case DATA_MOB_RAVENOUS_FURBOLG:   return uiRavenousFurbolg;
            case DATA_MOB_MASSIVE_JORMUNGAR:  return uiMassiveJormungar;
            case DATA_MOB_FEROCIOUS_RHINO:    return uiFerociousRhino;
            case DATA_MOB_ORB:                return uiPalehoofOrb;
            case DATA_SVALA:                  return uiSvala;
            case DATA_GORTOK_PALEHOOF_SPHERE: return uiGortokPalehoofSphere;
        }

        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << "U P " << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
            << m_auiEncounter[2] << " " << m_auiEncounter[3];

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
        uint16 data0, data1, data2, data3;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3;

        if (dataHead1 == 'U' && dataHead2 == 'P')
        {
            m_auiEncounter[0] = data0;
            m_auiEncounter[1] = data1;
            m_auiEncounter[2] = data2;
            m_auiEncounter[3] = data3;

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;

        } else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

class instance_utgarde_pinnacle : public InstanceMapScript
{
public:
    instance_utgarde_pinnacle() : InstanceMapScript("instance_utgarde_pinnacle", 575) { }

    InstanceScript* GetInstanceData_InstanceMapScript(Map* pMap)
    {
        return new instance_pinnacle(pMap);
    }


};

void AddSC_instance_utgarde_pinnacle()
{
    new instance_utgarde_pinnacle();
}
