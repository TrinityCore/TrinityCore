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
SDName: Instance_ZulGurub
SD%Complete: 80
SDComment: Missing reset function after killing a boss for Ohgan, Thekal.
SDCategory: Zul'Gurub
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "zulgurub.h"

class instance_zulgurub : public InstanceMapScript
{
    public: instance_zulgurub(): InstanceMapScript("instance_zulgurub", 309) {}

        struct instance_zulgurub_InstanceMapScript : public InstanceScript
        {
            instance_zulgurub_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
            }

            //If all High Priest bosses were killed. Lorkhan, Zath and Ohgan are added too.
            //Storing Lorkhan, Zath and Thekal because we need to cast on them later. Jindo is needed for healfunction too.
            uint64 LorKhanGUID;
            uint64 ZathGUID;
            uint64 ThekalGUID;
            uint64 JindoGUID;

            void Initialize()
            {
                LorKhanGUID = 0;
                ZathGUID = 0;
                ThekalGUID = 0;
                JindoGUID = 0;
            }

            bool IsEncounterInProgress() const
            {
                //not active in Zul'Gurub
                return false;
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_ZEALOT_LORKHAN: LorKhanGUID = creature->GetGUID(); break;
                    case NPC_ZEALOT_ZATH: ZathGUID = creature->GetGUID(); break;
                    case NPC_HIGH_PRIEST_THEKAL: ThekalGUID = creature->GetGUID(); break;
                    case NPC_JINDO_THE_HEXXER: JindoGUID = creature->GetGUID(); break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state)
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_JEKLIK:
                    case DATA_VENOXIS:
                    case DATA_MARLI:
                    case DATA_ARLOKK:
                    case DATA_HAKKAR:
                    case DATA_MANDOKIR:
                    case DATA_JINDO:
                    case DATA_GAHZRANKA:
                    case DATA_EDGE_OF_MADNESS:
                    case DATA_THEKAL:
                    case DATA_LORKHAN:
                    case DATA_ZATH:
                    case DATA_OHGAN:
                        break;
                    default:
                        break;
                }

                return true;
            }

            uint64 GetData64(uint32 uiData) const
            {
                switch (uiData)
                {
                    case DATA_LORKHAN:
                        return LorKhanGUID;
                    case DATA_ZATH:
                        return ZathGUID;
                    case DATA_THEKAL:
                        return ThekalGUID;
                    case DATA_JINDO:
                        return JindoGUID;
                }
                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "M C " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* str)
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

                if (dataHead1 == 'M' && dataHead2 == 'C')
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
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_zulgurub_InstanceMapScript(map);
        }
};

void AddSC_instance_zulgurub()
{
    new instance_zulgurub();
}
