/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Instance_ZulGurub
SD%Complete: 80
SDComment: Missing reset function after killing a boss for Ohgan, Thekal.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptPCH.h"
#include "zulgurub.h"

class instance_zulgurub : public InstanceMapScript
{
    public:
        instance_zulgurub()
            : InstanceMapScript("instance_zulgurub", 309)
        {
        }

        struct instance_zulgurub_InstanceMapScript : public InstanceScript
        {
            instance_zulgurub_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {}

            //If all High Priest bosses were killed. Lorkhan, Zath and Ohgan are added too.
            uint32 m_auiEncounter[MAX_ENCOUNTERS];

            //Storing Lorkhan, Zath and Thekal because we need to cast on them later. Jindo is needed for healfunction too.
            uint64 m_uiLorKhanGUID;
            uint64 m_uiZathGUID;
            uint64 m_uiThekalGUID;
            uint64 m_uiJindoGUID;

            void Initialize()
            {
                memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

                m_uiLorKhanGUID = 0;
                m_uiZathGUID = 0;
                m_uiThekalGUID = 0;
                m_uiJindoGUID = 0;
            }

            bool IsEncounterInProgress() const
            {
                //not active in Zul'Gurub
                return false;
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch(creature->GetEntry())
                {
                    case 11347: m_uiLorKhanGUID = creature->GetGUID(); break;
                    case 11348: m_uiZathGUID = creature->GetGUID(); break;
                    case 14509: m_uiThekalGUID = creature->GetGUID(); break;
                    case 11380: m_uiJindoGUID = creature->GetGUID(); break;
                }
            }

            void SetData(uint32 uiType, uint32 uiData)
            {
                switch(uiType)
                {
                    case DATA_ARLOKK:
                        m_auiEncounter[0] = uiData;
                        break;

                    case DATA_JEKLIK:
                        m_auiEncounter[1] = uiData;
                        break;

                    case DATA_VENOXIS:
                        m_auiEncounter[2] = uiData;
                        break;

                    case DATA_MARLI:
                        m_auiEncounter[3] = uiData;
                        break;

                    case DATA_THEKAL:
                        m_auiEncounter[4] = uiData;
                        break;

                    case DATA_LORKHAN:
                        m_auiEncounter[5] = uiData;
                        break;

                    case DATA_ZATH:
                        m_auiEncounter[6] = uiData;
                        break;

                    case DATA_OHGAN:
                        m_auiEncounter[7] = uiData;
                        break;
                }
            }

            uint32 GetData(uint32 uiType)
            {
                switch(uiType)
                {
                    case DATA_ARLOKK:
                        return m_auiEncounter[0];
                    case DATA_JEKLIK:
                        return m_auiEncounter[1];
                    case DATA_VENOXIS:
                        return m_auiEncounter[2];
                    case DATA_MARLI:
                        return m_auiEncounter[3];
                    case DATA_THEKAL:
                        return m_auiEncounter[4];
                    case DATA_LORKHAN:
                        return m_auiEncounter[5];
                    case DATA_ZATH:
                        return m_auiEncounter[6];
                    case DATA_OHGAN:
                        return m_auiEncounter[7];
                }
                return 0;
            }

            uint64 GetData64(uint32 uiData)
            {
                switch(uiData)
                {
                    case DATA_LORKHAN:
                        return m_uiLorKhanGUID;
                    case DATA_ZATH:
                        return m_uiZathGUID;
                    case DATA_THEKAL:
                        return m_uiThekalGUID;
                    case DATA_JINDO:
                        return m_uiJindoGUID;
                }
                return 0;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* pMap) const
        {
            return new instance_zulgurub_InstanceMapScript(pMap);
        }
};

void AddSC_instance_zulgurub()
{
    new instance_zulgurub();
}