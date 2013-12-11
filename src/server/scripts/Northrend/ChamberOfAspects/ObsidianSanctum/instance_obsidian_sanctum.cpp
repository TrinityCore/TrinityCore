/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "obsidian_sanctum.h"

/* Obsidian Sanctum encounters:
0 - Sartharion
*/

class instance_obsidian_sanctum : public InstanceMapScript
{
public:
    instance_obsidian_sanctum() : InstanceMapScript(OSScriptName, 615) { }

    struct instance_obsidian_sanctum_InstanceMapScript : public InstanceScript
    {
        instance_obsidian_sanctum_InstanceMapScript(Map* map) : InstanceScript(map) { }

        void Initialize() OVERRIDE
        {
            sartharionGUID = 0;
            tenebronGUID   = 0;
            shadronGUID    = 0;
            vesperonGUID   = 0;
        }

        void OnCreatureCreate(Creature* creature) OVERRIDE
        {
            switch (creature->GetEntry())
            {
                case NPC_SARTHARION:
                    sartharionGUID = creature->GetGUID();
                    break;
                // Three dragons below set to active state once created.
                // We must expect bigger raid to encounter main boss, and then three dragons must be active due to grid differences
                case NPC_TENEBRON:
                    tenebronGUID = creature->GetGUID();
                    creature->setActive(true);
                    break;
                case NPC_SHADRON:
                    shadronGUID = creature->GetGUID();
                    creature->setActive(true);
                    break;
                case NPC_VESPERON:
                    vesperonGUID = creature->GetGUID();
                    creature->setActive(true);
                    break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) OVERRIDE
        {
            if (!InstanceScript::SetBossState(type, state))
                 return false;

            switch (type)
            {
                case DATA_SARTHARION:
                case DATA_TENEBRON:
                case DATA_SHADRON:
                case DATA_VESPERON:
                    break;
                default:
                    break;
            }
            return true;
        }

        uint64 GetData64(uint32 Data) const OVERRIDE
        {
            switch (Data)
            {
                case DATA_SARTHARION:
                    return sartharionGUID;
                case DATA_TENEBRON:
                    return tenebronGUID;
                case DATA_SHADRON:
                    return shadronGUID;
                case DATA_VESPERON:
                    return vesperonGUID;
            }
            return 0;
        }

        std::string GetSaveData() OVERRIDE
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "O S " << GetBossSaveData();

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char* str) OVERRIDE
        {
            if (!str)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(str);

            char dataHead1, dataHead2;

            std::istringstream loadStream(str);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'O' && dataHead2 == 'S')
            {
                for (uint32 i = 0; i < EncounterCount; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    SetBossState(i, EncounterState(tmpState));
                }
            }
            else
                OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

    protected:
        uint64 sartharionGUID;
        uint64 tenebronGUID;
        uint64 shadronGUID;
        uint64 vesperonGUID;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
    {
        return new instance_obsidian_sanctum_InstanceMapScript(map);
    }
};

void AddSC_instance_obsidian_sanctum()
{
    new instance_obsidian_sanctum();
}
