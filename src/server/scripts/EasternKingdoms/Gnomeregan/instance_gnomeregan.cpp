/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "gnomeregan.h"
#include "Player.h"

#define    MAX_ENCOUNTER  1

class instance_gnomeregan : public InstanceMapScript
{
public:
    instance_gnomeregan() : InstanceMapScript("instance_gnomeregan", 90) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_gnomeregan_InstanceMapScript(map);
    }

    struct instance_gnomeregan_InstanceMapScript : public InstanceScript
    {
        instance_gnomeregan_InstanceMapScript(Map* map) : InstanceScript(map)
        {
        }

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        uint64 uiCaveInLeftGUID;
        uint64 uiCaveInRightGUID;

        uint64 uiBastmasterEmiShortfuseGUID;

        void Initialize() override
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            uiCaveInLeftGUID                = 0;
            uiCaveInRightGUID               = 0;

            uiBastmasterEmiShortfuseGUID    = 0;
        }

        void Load(const char* in) override
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            std::istringstream loadStream(in);
            loadStream >> m_auiEncounter[0];

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
            {
                if (m_auiEncounter[i] == IN_PROGRESS)
                    m_auiEncounter[i] = NOT_STARTED;
            }

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_BLASTMASTER_EMI_SHORTFUSE: uiBastmasterEmiShortfuseGUID = creature->GetGUID(); break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_CAVE_IN_LEFT:
                    uiCaveInLeftGUID = go->GetGUID();
                    if (m_auiEncounter[0] == DONE || m_auiEncounter[0] == NOT_STARTED)
                        HandleGameObject(0, false, go);
                    break;
                case GO_CAVE_IN_RIGHT:
                    uiCaveInRightGUID = go->GetGUID();
                    if (m_auiEncounter[0] == DONE || m_auiEncounter[0] == NOT_STARTED)
                        HandleGameObject(0, false, go);
                    break;
            }
        }

        void SetData(uint32 uiType, uint32 uiData) override
        {
            switch (uiType)
            {
                case TYPE_EVENT:
                    m_auiEncounter[0] = uiData;
                    if (uiData == DONE)
                        SaveToDB();
                    break;
            }
        }

        uint32 GetData(uint32 uiType) const override
        {
            switch (uiType)
            {
                case TYPE_EVENT:    return m_auiEncounter[0];
            }
            return 0;
        }

        uint64 GetData64(uint32 uiType) const override
        {
            switch (uiType)
            {
                case DATA_GO_CAVE_IN_LEFT:              return uiCaveInLeftGUID;
                case DATA_GO_CAVE_IN_RIGHT:             return uiCaveInRightGUID;
                case DATA_NPC_BASTMASTER_EMI_SHORTFUSE: return uiBastmasterEmiShortfuseGUID;
            }

            return 0;
        }
    };

};

void AddSC_instance_gnomeregan()
{
    new instance_gnomeregan();
}
