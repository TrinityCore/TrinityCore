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
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "drak_tharon_keep.h"

class instance_drak_tharon_keep : public InstanceMapScript
{
    public:
        instance_drak_tharon_keep() : InstanceMapScript(DrakTharonKeepScriptName, 600) { }

        struct instance_drak_tharon_keep_InstanceScript : public InstanceScript
        {
            instance_drak_tharon_keep_InstanceScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);

                TrollgoreGUID       = 0;
                NovosGUID           = 0;
                KingDredGUID        = 0;
                TharonJaGUID        = 0;

                memset(NovosCrystalGUIDs, 0, 4 * sizeof(uint64));
                memset(NovosSummonerGUIDs, 0, 4 * sizeof(uint64));
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                    case NPC_TROLLGORE:
                        TrollgoreGUID = creature->GetGUID();
                        break;
                    case NPC_NOVOS:
                        NovosGUID = creature->GetGUID();
                        break;
                    case NPC_KING_DRED:
                        KingDredGUID = creature->GetGUID();
                        break;
                    case NPC_THARON_JA:
                        TharonJaGUID = creature->GetGUID();
                        break;
                    case NPC_CRYSTAL_CHANNEL_TARGET:
                        InitializeNovosSummoner(creature);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go)
            {
                switch (go->GetEntry())
                {
                    case GO_NOVOS_CRYSTAL_1:
                        NovosCrystalGUIDs[0] = go->GetGUID();
                        go->SetGoState(GO_STATE_READY);
                        break;
                    case GO_NOVOS_CRYSTAL_2:
                        NovosCrystalGUIDs[1] = go->GetGUID();
                        go->SetGoState(GO_STATE_READY);
                        break;
                    case GO_NOVOS_CRYSTAL_3:
                        NovosCrystalGUIDs[2] = go->GetGUID();
                        go->SetGoState(GO_STATE_READY);
                        break;
                    case GO_NOVOS_CRYSTAL_4:
                        NovosCrystalGUIDs[3] = go->GetGUID();
                        go->SetGoState(GO_STATE_READY);
                        break;
                    default:
                        break;
                }
            }

            void InitializeNovosSummoner(Creature* creature)
            {
                float x = creature->GetPositionX();
                float y = creature->GetPositionY();
                float z = creature->GetPositionZ();

                if (x < -374.0f && x > -379.0f && y > -820.0f && y < -815.0f && z < 60.0f && z > 58.0f)
                    NovosCrystalGUIDs[0] = creature->GetGUID();
                else if (x < -379.0f && x > -385.0f && y > -820.0f && y < -815.0f && z < 60.0f && z > 58.0f)
                    NovosCrystalGUIDs[1] = creature->GetGUID();
                else if (x < -374.0f && x > -385.0f && y > -827.0f && y < -820.0f && z < 60.0f && z > 58.0f)
                    NovosCrystalGUIDs[2] = creature->GetGUID();
                else if (x < -338.0f && x > -344.0f && y > -727.0f && y < 721.0f && z < 30.0f && z > 26.0f)
                    NovosCrystalGUIDs[3] = creature->GetGUID();
            }

            uint64 GetData64(uint32 type) const OVERRIDE
            {
                switch (type)
                {
                    case DATA_TROLLGORE:
                        return TrollgoreGUID;
                    case DATA_NOVOS:
                        return NovosGUID;
                    case DATA_KING_DRED:
                        return KingDredGUID;
                    case DATA_THARON_JA:
                        return TharonJaGUID;
                    case DATA_NOVOS_CRYSTAL_1:
                    case DATA_NOVOS_CRYSTAL_2:
                    case DATA_NOVOS_CRYSTAL_3:
                    case DATA_NOVOS_CRYSTAL_4:
                        return NovosCrystalGUIDs[type - DATA_NOVOS_CRYSTAL_1];
                    case DATA_NOVOS_SUMMONER_1:
                    case DATA_NOVOS_SUMMONER_2:
                    case DATA_NOVOS_SUMMONER_3:
                    case DATA_NOVOS_SUMMONER_4:
                        return NovosSummonerGUIDs[type - DATA_NOVOS_SUMMONER_1];
                }

                return 0;
            }

            void OnUnitDeath(Unit* unit)
            {
                if (unit->GetEntry() == NPC_CRYSTAL_HANDLER)
                    if (Creature* novos = instance->GetCreature(NovosGUID))
                        novos->AI()->DoAction(ACTION_CRYSTAL_HANDLER_DIED);
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "D K " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(char const* str)
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

                if (dataHead1 == 'D' && dataHead2 == 'K')
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
            uint64 TrollgoreGUID;
            uint64 NovosGUID;
            uint64 KingDredGUID;
            uint64 TharonJaGUID;

            uint64 NovosCrystalGUIDs[4];
            uint64 NovosSummonerGUIDs[4];
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_drak_tharon_keep_InstanceScript(map);
        }
};

void AddSC_instance_drak_tharon_keep()
{
    new instance_drak_tharon_keep();
}
