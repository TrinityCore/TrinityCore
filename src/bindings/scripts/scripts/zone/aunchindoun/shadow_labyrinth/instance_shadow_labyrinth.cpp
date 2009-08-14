/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Instance_Shadow_Labyrinth
SD%Complete: 85
SDComment: Some cleanup left along with save
SDCategory: Auchindoun, Shadow Labyrinth
EndScriptData */

#include "precompiled.h"
#include "def_shadow_labyrinth.h"

#define MAX_ENCOUNTER 5

#define REFECTORY_DOOR          183296                      //door opened when blackheart the inciter dies
#define SCREAMING_HALL_DOOR     183295                      //door opened when grandmaster vorpil dies

/* Shadow Labyrinth encounters:
1 - Ambassador Hellmaw event
2 - Blackheart the Inciter event
3 - Grandmaster Vorpil event
4 - Murmur event
*/

struct TRINITY_DLL_DECL instance_shadow_labyrinth : public ScriptedInstance
{
    instance_shadow_labyrinth(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint32 m_auiEncounter[MAX_ENCOUNTER];
    std::string str_data;

    uint64 m_uiRefectoryDoorGUID;
    uint64 m_uiScreamingHallDoorGUID;

    uint64 m_uiGrandmasterVorpil;
    uint32 m_uiFelOverseerCount;

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        m_uiRefectoryDoorGUID = 0;
        m_uiScreamingHallDoorGUID = 0;

        m_uiGrandmasterVorpil = 0;
        m_uiFelOverseerCount = 0;
    }

    bool Ism_auiEncounterInProgress() const
    {
        for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS) return true;

        return false;
    }

    void OnGameObjectCreate(GameObject *go, bool add)
    {
        switch(go->GetEntry())
        {
            case REFECTORY_DOOR:
                m_uiRefectoryDoorGUID = go->GetGUID();
                if (m_auiEncounter[2] == DONE)
                    DoUseDoorOrButton(m_uiRefectoryDoorGUID);
                break;
            case SCREAMING_HALL_DOOR:
                m_uiScreamingHallDoorGUID = go->GetGUID();
                if (m_auiEncounter[3] == DONE)
                    DoUseDoorOrButton(m_uiScreamingHallDoorGUID);
                break;
        }
    }

    void OnCreatureCreate(Creature *creature, bool add)
    {
        switch(creature->GetEntry())
        {
            case 18732:
                m_uiGrandmasterVorpil = creature->GetGUID();
                break;
            case 18796:
                ++m_uiFelOverseerCount;
                debug_log("TSCR: Shadow Labyrinth: counting %u Fel Overseers.",m_uiFelOverseerCount);
                break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case TYPE_HELLMAW:
                m_auiEncounter[0] = data;
                break;

            case TYPE_OVERSEER:
                if (data != DONE)
                    error_log("TSCR: Shadow Labyrinth: TYPE_OVERSEER did not expect other data than DONE");
                if (m_uiFelOverseerCount)
                {
                    --m_uiFelOverseerCount;
                    debug_log("TSCR: Shadow Labyrinth: %u Fel Overseers left to kill.",m_uiFelOverseerCount);
                }
                if (m_uiFelOverseerCount == 0)
                {
                    m_auiEncounter[1] = DONE;
                    debug_log("TSCR: Shadow Labyrinth: TYPE_OVERSEER == DONE");
                }
                break;

            case DATA_BLACKHEARTTHEINCITEREVENT:
                if (data == DONE)
                    DoUseDoorOrButton(m_uiRefectoryDoorGUID);
                m_auiEncounter[2] = data;
                break;

            case DATA_GRANDMASTERVORPILEVENT:
                if (data == DONE)
                    DoUseDoorOrButton(m_uiScreamingHallDoorGUID);
                m_auiEncounter[3] = data;
                break;

            case DATA_MURMUREVENT:
                m_auiEncounter[4] = data;
                break;
        }

        if (data == DONE)
        {
            if (type == TYPE_OVERSEER && m_uiFelOverseerCount != 0)
                return;

            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " "
                << m_auiEncounter[2] << " " << m_auiEncounter[3] << " " << m_auiEncounter[4];

            str_data = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case TYPE_HELLMAW: return m_auiEncounter[0];
            case TYPE_OVERSEER: return m_auiEncounter[1];
            case DATA_GRANDMASTERVORPILEVENT: return m_auiEncounter[3];
            case DATA_MURMUREVENT: return m_auiEncounter[4];
        }
        return false;
    }

    uint64 GetData64(uint32 identifier)
    {
        if (identifier == DATA_GRANDMASTERVORPIL)
            return m_uiGrandmasterVorpil;

        return 0;
    }

    std::string GetSaveData()
    {
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

        std::istringstream loadStream(in);
        loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3] >> m_auiEncounter[4];

        for(uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS)
                m_auiEncounter[i] = NOT_STARTED;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_shadow_labyrinth(Map* pMap)
{
    return new instance_shadow_labyrinth(pMap);
}

void AddSC_instance_shadow_labyrinth()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_shadow_labyrinth";
    newscript->GetInstanceData = &GetInstanceData_instance_shadow_labyrinth;
    newscript->RegisterSelf();
}

