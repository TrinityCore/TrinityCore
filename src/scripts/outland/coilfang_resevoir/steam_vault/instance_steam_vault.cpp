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
SDName: Instance_Steam_Vault
SD%Complete: 80
SDComment:  Instance script and access panel GO
SDCategory: Coilfang Resevoir, The Steamvault
EndScriptData */

#include "ScriptedPch.h"
#include "steam_vault.h"

#define MAX_ENCOUNTER 4

#define MAIN_CHAMBERS_DOOR      183049
#define ACCESS_PANEL_HYDRO      184125
#define ACCESS_PANEL_MEK        184126

/* Steam Vaults encounters:
1 - Hydromancer Thespia Event
2 - Mekgineer Steamrigger Event
3 - Warlord Kalithresh Event
*/

bool GOHello_go_main_chambers_access_panel(Player* pPlayer, GameObject* pGo)
{
    ScriptedInstance* pInstance = pGo->GetInstanceData();

    if (!pInstance)
        return false;

    if (pGo->GetEntry() == ACCESS_PANEL_HYDRO && (pInstance->GetData(TYPE_HYDROMANCER_THESPIA) == DONE || pInstance->GetData(TYPE_HYDROMANCER_THESPIA) == SPECIAL))
        pInstance->SetData(TYPE_HYDROMANCER_THESPIA,SPECIAL);

    if (pGo->GetEntry() == ACCESS_PANEL_MEK && (pInstance->GetData(TYPE_MEKGINEER_STEAMRIGGER) == DONE || pInstance->GetData(TYPE_MEKGINEER_STEAMRIGGER) == SPECIAL))
        pInstance->SetData(TYPE_MEKGINEER_STEAMRIGGER,SPECIAL);

    return true;
}

struct TRINITY_DLL_DECL instance_steam_vault : public ScriptedInstance
{
    instance_steam_vault(Map* pMap) : ScriptedInstance(pMap) {Initialize();};

    uint32 m_auiEncounter[MAX_ENCOUNTER];

    uint64 ThespiaGUID;
    uint64 MekgineerGUID;
    uint64 KalithreshGUID;

    uint64 MainChambersDoor;
    uint64 AccessPanelHydro;
    uint64 AccessPanelMek;

    void Initialize()
    {
        memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

        ThespiaGUID = 0;
        MekgineerGUID = 0;
        KalithreshGUID = 0;
        MainChambersDoor = 0;
        AccessPanelHydro = 0;
        AccessPanelMek = 0;
    }

    bool IsEncounterInProgress() const
    {
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
             if (m_auiEncounter[i] == IN_PROGRESS)
                 return true;

        return false;
    }

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
          switch(pCreature->GetEntry())
        {
          case 17797: ThespiaGUID = pCreature->GetGUID(); break;
          case 17796: MekgineerGUID = pCreature->GetGUID(); break;
          case 17798: KalithreshGUID = pCreature->GetGUID(); break;
        }
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        switch(pGo->GetEntry())
        {
        case MAIN_CHAMBERS_DOOR: MainChambersDoor = pGo->GetGUID(); break;
        case ACCESS_PANEL_HYDRO: AccessPanelHydro = pGo->GetGUID(); break;
        case ACCESS_PANEL_MEK:   AccessPanelMek = pGo->GetGUID(); break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case TYPE_HYDROMANCER_THESPIA:
                if (data == SPECIAL)
                {
                    HandleGameObject(AccessPanelHydro, true);

                    if (GetData(TYPE_MEKGINEER_STEAMRIGGER) == SPECIAL)
                        HandleGameObject(MainChambersDoor, true);

                    debug_log("TSCR: Instance Steamvault: Access panel used.");
                }
                m_auiEncounter[0] = data;
                break;
            case TYPE_MEKGINEER_STEAMRIGGER:
                if (data == SPECIAL)
                {
                    HandleGameObject(AccessPanelMek, true);

                    if (GetData(TYPE_HYDROMANCER_THESPIA) == SPECIAL)
                        HandleGameObject(MainChambersDoor, true);

                    debug_log("TSCR: Instance Steamvault: Access panel used.");
                }
                m_auiEncounter[1] = data;
                break;
            case TYPE_WARLORD_KALITHRESH:
                m_auiEncounter[2] = data;
                break;
            case TYPE_DISTILLER:
                m_auiEncounter[3] = data;
                break;
        }

        if (data == DONE || data == SPECIAL)
            SaveToDB();
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case TYPE_HYDROMANCER_THESPIA:
                return m_auiEncounter[0];
            case TYPE_MEKGINEER_STEAMRIGGER:
                return m_auiEncounter[1];
            case TYPE_WARLORD_KALITHRESH:
                return m_auiEncounter[2];
            case TYPE_DISTILLER:
                return m_auiEncounter[3];
        }
        return 0;
    }

    uint64 GetData64(uint32 data)
    {
        switch(data)
        {
            case DATA_THESPIA:
                return ThespiaGUID;
            case DATA_MEKGINEERSTEAMRIGGER:
                return MekgineerGUID;
            case DATA_KALITRESH:
                return KalithreshGUID;
        }
        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;
        std::ostringstream stream;
        stream << m_auiEncounter[0] << " " << m_auiEncounter[1] << " " << m_auiEncounter[2] << " " << m_auiEncounter[3];
        char* out = new char[stream.str().length() + 1];
        strcpy(out, stream.str().c_str());
        if (out)
        {
            OUT_SAVE_INST_DATA_COMPLETE;
            return out;
        }
        return NULL;
    }

    void Load(const char* in)
    {
        if (!in)
        {
            OUT_LOAD_INST_DATA_FAIL;
            return;
        }
        OUT_LOAD_INST_DATA(in);
        std::istringstream stream(in);
        stream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3];
        for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            if (m_auiEncounter[i] == IN_PROGRESS)
                m_auiEncounter[i] = NOT_STARTED;
        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_steam_vault(Map* pMap)
{
    return new instance_steam_vault(pMap);
}

void AddSC_instance_steam_vault()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "go_main_chambers_access_panel";
    newscript->pGOHello = &GOHello_go_main_chambers_access_panel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "instance_steam_vault";
    newscript->GetInstanceData = &GetInstanceData_instance_steam_vault;
    newscript->RegisterSelf();
}

