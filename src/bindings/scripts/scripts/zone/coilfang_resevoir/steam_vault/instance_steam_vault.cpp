/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SD%Complete: 60
SDComment: Workaround for opening of Main Chamber door. Trinity does not support scripting of Gameobject as this instance require.
SDCategory: Coilfang Resevoir, The Steamvault
EndScriptData */

#include "precompiled.h"
#include "def_steam_vault.h"

#define ENCOUNTERS 4

#define MAIN_CHAMBERS_DOOR      183049                      //door opened when hydromancer and mekgineer are died
#define ACCESS_PANEL_HYDRO      184125
#define ACCESS_PANEL_MEK        184126

/* Steam Vaults encounters:
1 - Hydromancer Thespia Event
2 - Mekgineer Steamrigger Event
3 - Warlord Kalithresh Event
*/

struct TRINITY_DLL_DECL instance_steam_vault : public ScriptedInstance
{
    instance_steam_vault(Map *Map) : ScriptedInstance(Map) {Initialize();};

    uint64 ThespiaGUID;
    uint64 MekgineerGUID;
    uint64 KalithreshGUID;
    uint32 Encounter[ENCOUNTERS];

    bool IsHydromancerDead, IsMekgineerDead;
    GameObject *MainChambersDoor;
    GameObject *AccessPanelHydro;
    GameObject *AccessPanelMek;

    void Initialize()
    {
        ThespiaGUID = 0;
        MekgineerGUID = 0;
        KalithreshGUID = 0;
        IsHydromancerDead = false;
        IsMekgineerDead = false;
        MainChambersDoor = NULL;
        AccessPanelHydro = NULL;
        AccessPanelMek = NULL;

        for(uint8 i = 0; i < ENCOUNTERS; i++)
            Encounter[i] = false;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < ENCOUNTERS; i++)
            if( Encounter[i] ) return true;

        return false;
    }

    void OnCreatureCreate(Creature *creature, uint32 creature_entry)
    {
        switch(creature_entry)
        {
            case 17797: ThespiaGUID = creature->GetGUID(); break;
            case 17796: MekgineerGUID = creature->GetGUID(); break;
            case 17798: KalithreshGUID = creature->GetGUID(); break;
        }
    }

    void OnObjectCreate(GameObject *go)
    {
        switch(go->GetEntry())
        {
            case MAIN_CHAMBERS_DOOR: MainChambersDoor = go; break;
            case ACCESS_PANEL_HYDRO: AccessPanelHydro = go; break;
            case ACCESS_PANEL_MEK:   AccessPanelMek = go; break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case TYPE_HYDROMANCER_THESPIA:
                if(data == DONE)
                {
                    IsHydromancerDead = true;
                    if( IsMekgineerDead && MainChambersDoor )
                        MainChambersDoor->SetGoState(0);
                }
                Encounter[0] = data;
                break;
            case TYPE_MEKGINEER_STEAMRIGGER:
                if(data == DONE)
                {
                    IsMekgineerDead = true;
                    if( IsHydromancerDead && MainChambersDoor )
                        MainChambersDoor->SetGoState(0);
                }
                Encounter[1] = data;
                break;
            case TYPE_WARLORD_KALITHRESH:
                Encounter[2] = data;
                break;
            case TYPE_DISTILLER:
                Encounter[3] = data;
                break;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case TYPE_HYDROMANCER_THESPIA:
                return Encounter[0];
            case TYPE_MEKGINEER_STEAMRIGGER:
                return Encounter[1];
            case TYPE_WARLORD_KALITHRESH:
                return Encounter[2];
            case TYPE_DISTILLER:
                return Encounter[3];
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
};

InstanceData* GetInstanceData_instance_steam_vault(Map* map)
{
    return new instance_steam_vault(map);
}

void AddSC_instance_steam_vault()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_steam_vault";
    newscript->GetInstanceData = GetInstanceData_instance_steam_vault;
    m_scripts[nrscripts++] = newscript;
}
