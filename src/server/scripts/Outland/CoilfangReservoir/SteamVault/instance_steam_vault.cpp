/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Instance_Steam_Vault
SD%Complete: 80
SDComment:  Instance script and access panel GO
SDCategory: Coilfang Resevoir, The Steamvault
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
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

class go_main_chambers_access_panel : public GameObjectScript
{
public:
    go_main_chambers_access_panel() : GameObjectScript("go_main_chambers_access_panel") { }

    bool OnGossipHello(Player* /*player*/, GameObject* go)
    {
        InstanceScript* instance = go->GetInstanceScript();

        if (!instance)
            return false;

        if (go->GetEntry() == ACCESS_PANEL_HYDRO && (instance->GetData(TYPE_HYDROMANCER_THESPIA) == DONE || instance->GetData(TYPE_HYDROMANCER_THESPIA) == SPECIAL))
            instance->SetData(TYPE_HYDROMANCER_THESPIA, SPECIAL);

        if (go->GetEntry() == ACCESS_PANEL_MEK && (instance->GetData(TYPE_MEKGINEER_STEAMRIGGER) == DONE || instance->GetData(TYPE_MEKGINEER_STEAMRIGGER) == SPECIAL))
            instance->SetData(TYPE_MEKGINEER_STEAMRIGGER, SPECIAL);

        return true;
    }

};

class instance_steam_vault : public InstanceMapScript
{
public:
    instance_steam_vault() : InstanceMapScript("instance_steam_vault", 545) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_steam_vault_InstanceMapScript(map);
    }

    struct instance_steam_vault_InstanceMapScript : public InstanceScript
    {
        instance_steam_vault_InstanceMapScript(Map* map) : InstanceScript(map) {}

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

        void OnCreatureCreate(Creature* creature)
        {
              switch (creature->GetEntry())
            {
              case 17797: ThespiaGUID = creature->GetGUID(); break;
              case 17796: MekgineerGUID = creature->GetGUID(); break;
              case 17798: KalithreshGUID = creature->GetGUID(); break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
            case MAIN_CHAMBERS_DOOR: MainChambersDoor = go->GetGUID(); break;
            case ACCESS_PANEL_HYDRO: AccessPanelHydro = go->GetGUID(); break;
            case ACCESS_PANEL_MEK:   AccessPanelMek = go->GetGUID(); break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case TYPE_HYDROMANCER_THESPIA:
                    if (data == SPECIAL)
                    {
                        HandleGameObject(AccessPanelHydro, true);

                        if (GetData(TYPE_MEKGINEER_STEAMRIGGER) == SPECIAL)
                            HandleGameObject(MainChambersDoor, true);

                        TC_LOG_DEBUG(LOG_FILTER_TSCR, "Instance Steamvault: Access panel used.");
                    }
                    m_auiEncounter[0] = data;
                    break;
                case TYPE_MEKGINEER_STEAMRIGGER:
                    if (data == SPECIAL)
                    {
                        HandleGameObject(AccessPanelMek, true);

                        if (GetData(TYPE_HYDROMANCER_THESPIA) == SPECIAL)
                            HandleGameObject(MainChambersDoor, true);

                        TC_LOG_DEBUG(LOG_FILTER_TSCR, "Instance Steamvault: Access panel used.");
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

        uint32 GetData(uint32 type) const
        {
            switch (type)
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

        uint64 GetData64(uint32 data) const
        {
            switch (data)
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
            stream << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' ' << m_auiEncounter[2] << ' ' << m_auiEncounter[3];

            OUT_SAVE_INST_DATA_COMPLETE;
            return stream.str();
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

};

void AddSC_instance_steam_vault()
{
    new go_main_chambers_access_panel();
    new instance_steam_vault();
}
