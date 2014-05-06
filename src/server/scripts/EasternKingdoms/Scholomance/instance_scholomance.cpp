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
#include "Player.h"
#include "scholomance.h"

Position const GandlingLoc = { 180.7712f, -5.428603f, 75.57024f, 1.291544f };

class instance_scholomance : public InstanceMapScript
{
    public:
        instance_scholomance() : InstanceMapScript("instance_scholomance", 289) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_scholomance_InstanceMapScript(map);
        }

        struct instance_scholomance_InstanceMapScript : public InstanceScript
        {
            instance_scholomance_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetBossNumber(EncounterCount);
                GateKirtonosGUID        = 0;
                GateGandlingGUID        = 0;
                GateMiliciaGUID         = 0;
                GateTheolenGUID         = 0;
                GatePolkeltGUID         = 0;
                GateRavenianGUID        = 0;
                GateBarovGUID           = 0;
                GateIlluciaGUID         = 0;
                BrazierOfTheHeraldGUID  = 0;
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_GATE_KIRTONOS:
                        GateKirtonosGUID = go->GetGUID();
                        break;
                    case GO_GATE_GANDLING:
                        GateGandlingGUID = go->GetGUID();
                        break;
                    case GO_GATE_MALICIA:
                        GateMiliciaGUID = go->GetGUID();
                        break;
                    case GO_GATE_THEOLEN:
                        GateTheolenGUID = go->GetGUID();
                        break;
                    case GO_GATE_POLKELT:
                        GatePolkeltGUID = go->GetGUID();
                        break;
                    case GO_GATE_RAVENIAN:
                        GateRavenianGUID = go->GetGUID();
                        break;
                    case GO_GATE_BAROV:
                        GateBarovGUID = go->GetGUID();
                        break;
                    case GO_GATE_ILLUCIA:
                        GateIlluciaGUID = go->GetGUID();
                        break;
                    case GO_BRAZIER_OF_THE_HERALD:
                        BrazierOfTheHeraldGUID = go->GetGUID();
                        break;
                    default:
                        break;
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_LORDALEXEIBAROV:
                    case DATA_DOCTORTHEOLENKRASTINOV:
                    case DATA_THERAVENIAN:
                    case DATA_LOREKEEPERPOLKELT:
                    case DATA_INSTRUCTORMALICIA:
                    case DATA_LADYILLUCIABAROV:
                        CheckToSpawnGandling();
                        break;
                    default:
                        break;
                }

                return true;
            }

            uint64 GetData64(uint32 type) const override
            {
                switch (type)
                {
                    case GO_GATE_KIRTONOS:
                        return GateKirtonosGUID;
                    case GO_GATE_GANDLING:
                        return GateGandlingGUID;
                    case GO_GATE_MALICIA:
                        return GateMiliciaGUID;
                    case GO_GATE_THEOLEN:
                        return GateTheolenGUID;
                    case GO_GATE_POLKELT:
                        return GatePolkeltGUID;
                    case GO_GATE_RAVENIAN:
                        return GateRavenianGUID;
                    case GO_GATE_BAROV:
                        return GateBarovGUID;
                    case GO_GATE_ILLUCIA:
                        return GateIlluciaGUID;
                    case GO_BRAZIER_OF_THE_HERALD:
                        return BrazierOfTheHeraldGUID;
                    default:
                        break;
                }

                return 0;
            }

            bool CheckPreBosses(uint32 bossId) const
            {
                switch (bossId)
                {
                    case DATA_DARKMASTERGANDLING:
                        if (GetBossState(DATA_LORDALEXEIBAROV) != DONE)
                            return false;
                        if (GetBossState(DATA_DOCTORTHEOLENKRASTINOV) != DONE)
                            return false;
                        if (GetBossState(DATA_THERAVENIAN) != DONE)
                            return false;
                        if (GetBossState(DATA_LOREKEEPERPOLKELT) != DONE)
                            return false;
                        if (GetBossState(DATA_INSTRUCTORMALICIA) != DONE)
                            return false;
                        if (GetBossState(DATA_LADYILLUCIABAROV) != DONE)
                            return false;
                        if (GetBossState(DATA_DARKMASTERGANDLING) == DONE)
                            return false;
                        break;
                    default:
                        break;
                }

                return true;
            }

            void CheckToSpawnGandling()
            {
                if (CheckPreBosses(DATA_DARKMASTERGANDLING))
                    instance->SummonCreature(NPC_DARKMASTER_GANDLING, GandlingLoc);
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << "S O " << GetBossSaveData();

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* str) override
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

                if (dataHead1 == 'S' && dataHead2 == 'O')
                {
                    for (uint32 i = 0; i < EncounterCount; ++i)
                    {
                        uint32 tmpState;
                        loadStream >> tmpState;
                        if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                            tmpState = NOT_STARTED;
                        SetBossState(i, EncounterState(tmpState));
                    }

                    CheckToSpawnGandling();
                }
                else
                    OUT_LOAD_INST_DATA_FAIL;

                OUT_LOAD_INST_DATA_COMPLETE;
            }

        protected:
            uint64 GateKirtonosGUID;
            uint64 GateGandlingGUID;
            uint64 GateMiliciaGUID;
            uint64 GateTheolenGUID;
            uint64 GatePolkeltGUID;
            uint64 GateRavenianGUID;
            uint64 GateBarovGUID;
            uint64 GateIlluciaGUID;
            uint64 BrazierOfTheHeraldGUID;
        };
};

void AddSC_instance_scholomance()
{
    new instance_scholomance();
}
