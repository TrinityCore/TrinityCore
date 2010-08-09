/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Instance_Molten_Core
SD%Complete: 0
SDComment: Place Holder
SDCategory: Molten Core
EndScriptData */

#include "ScriptPCH.h"
#include "molten_core.h"

#define MAX_ENCOUNTER      9

#define ID_LUCIFRON     12118
#define ID_MAGMADAR     11982
#define ID_GEHENNAS     12259
#define ID_GARR         12057
#define ID_GEDDON       12056
#define ID_SHAZZRAH     12264
#define ID_GOLEMAGG     11988
#define ID_SULFURON     12098
#define ID_DOMO         12018
#define ID_RAGNAROS     11502
#define ID_FLAMEWAKERPRIEST     11662

class instance_molten_core : public InstanceMapScript
{
public:
    instance_molten_core() : InstanceMapScript("instance_molten_core", 409) { }

    InstanceScript* GetInstance_InstanceMapScript(Map* pMap)
    {
        return new instance_molten_core_InstanceMapScript (pMap);
    }

    struct instance_molten_core_InstanceMapScript : public InstanceScript
    {
        instance_molten_core_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {Initialize();};

        uint64 Lucifron, Magmadar, Gehennas, Garr, Geddon, Shazzrah, Sulfuron, Golemagg, Domo, Ragnaros, FlamewakerPriest;
        uint64 RuneKoro, RuneZeth, RuneMazj, RuneTheri, RuneBlaz, RuneKress, RuneMohn, m_uiFirelordCacheGUID;

        //If all Bosses are dead.
        bool IsBossDied[9];

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            Lucifron = 0;
            Magmadar = 0;
            Gehennas = 0;
            Garr = 0;
            Geddon = 0;
            Shazzrah = 0;
            Sulfuron = 0;
            Golemagg = 0;
            Domo = 0;
            Ragnaros = 0;
            FlamewakerPriest = 0;

            RuneKoro = 0;
            RuneZeth = 0;
            RuneMazj = 0;
            RuneTheri = 0;
            RuneBlaz = 0;
            RuneKress = 0;
            RuneMohn = 0;

            m_uiFirelordCacheGUID = 0;

            IsBossDied[0] = false;
            IsBossDied[1] = false;
            IsBossDied[2] = false;
            IsBossDied[3] = false;
            IsBossDied[4] = false;
            IsBossDied[5] = false;
            IsBossDied[6] = false;

            IsBossDied[7] = false;
            IsBossDied[8] = false;
        }

        bool IsEncounterInProgress() const
        {
            return false;
        };

        void OnGameObjectCreate(GameObject* pGo, bool /*add*/)
        {
            switch(pGo->GetEntry())
            {
            case 176951:                                    //Sulfuron
                RuneKoro = pGo->GetGUID();
                break;
            case 176952:                                    //Geddon
                RuneZeth = pGo->GetGUID();
                break;
            case 176953:                                    //Shazzrah
                RuneMazj = pGo->GetGUID();
                break;
            case 176954:                                    //Golemagg
                RuneTheri = pGo->GetGUID();
                break;
            case 176955:                                    //Garr
                RuneBlaz = pGo->GetGUID();
                break;
            case 176956:                                    //Magmadar
                RuneKress = pGo->GetGUID();
                break;
            case 176957:                                    //Gehennas
                RuneMohn = pGo->GetGUID();
                break;
            case 179703:
                m_uiFirelordCacheGUID = pGo->GetGUID();      //when majordomo event == DONE DoRespawnGameObject(m_uiFirelordCacheGUID,);
                break;
            }
        }

        void OnCreatureCreate(Creature* pCreature, bool /*add*/)
        {
            switch (pCreature->GetEntry())
            {
                case ID_LUCIFRON:
                    Lucifron = pCreature->GetGUID();
                    break;

                case ID_MAGMADAR:
                    Magmadar = pCreature->GetGUID();
                    break;

                case ID_GEHENNAS:
                    Gehennas = pCreature->GetGUID();
                    break;

                case ID_GARR:
                    Garr = pCreature->GetGUID();
                    break;

                case ID_GEDDON:
                    Geddon = pCreature->GetGUID();
                    break;

                case ID_SHAZZRAH:
                    Shazzrah = pCreature->GetGUID();
                    break;

                case ID_SULFURON:
                    Sulfuron = pCreature->GetGUID();
                    break;

                case ID_GOLEMAGG:
                    Golemagg = pCreature->GetGUID();
                    break;

                case ID_DOMO:
                    Domo = pCreature->GetGUID();
                    break;

                case ID_RAGNAROS:
                    Ragnaros = pCreature->GetGUID();
                    break;

                case ID_FLAMEWAKERPRIEST:
                    FlamewakerPriest = pCreature->GetGUID();
                    break;
            }
        }

        uint64 GetData64 (uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_SULFURON:
                    return Sulfuron;
                case DATA_GOLEMAGG:
                    return Golemagg;

                case DATA_FLAMEWAKERPRIEST:
                    return FlamewakerPriest;
            }

            return 0;
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_LUCIFRONISDEAD:
                    if (IsBossDied[0])
                        return 1;
                    break;

                case DATA_MAGMADARISDEAD:
                    if (IsBossDied[1])
                        return 1;
                    break;

                case DATA_GEHENNASISDEAD:
                    if (IsBossDied[2])
                        return 1;
                    break;

                case DATA_GARRISDEAD:
                    if (IsBossDied[3])
                        return 1;
                    break;

                case DATA_GEDDONISDEAD:
                    if (IsBossDied[4])
                        return 1;
                    break;

                case DATA_SHAZZRAHISDEAD:
                    if (IsBossDied[5])
                        return 1;
                    break;

                case DATA_SULFURONISDEAD:
                    if (IsBossDied[6])
                        return 1;
                    break;

                case DATA_GOLEMAGGISDEAD:
                    if (IsBossDied[7])
                        return 1;
                    break;

                case DATA_MAJORDOMOISDEAD:
                    if (IsBossDied[8])
                        return 1;
                    break;
            }

            return 0;
        }

        void SetData(uint32 type, uint32 /*data*/)
        {
            if (type == DATA_GOLEMAGG_DEATH)
                IsBossDied[7] = true;
        }
    };

};


void AddSC_instance_molten_core()
{
    new instance_molten_core();
}
