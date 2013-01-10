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
SDName: Instance_Scholomance
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "scholomance.h"

enum CreatureId
{
    NPC_DARKMASTER_GANDLING    = 1853
};

Position const GandlingLoc = {180.7712f, -5.428603f, 75.57024f, 1.291544f};

class instance_scholomance : public InstanceMapScript
{
public:
    instance_scholomance() : InstanceMapScript("instance_scholomance", 289) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_scholomance_InstanceMapScript(map);
    }

    struct instance_scholomance_InstanceMapScript : public InstanceScript
    {
        instance_scholomance_InstanceMapScript(Map* map) : InstanceScript(map) {}

        //Lord Alexei Barov, Doctor Theolen Krastinov, The Ravenian, Lorekeeper Polkelt, Instructor Malicia and the Lady Illucia Barov.
        uint32 m_auiEncounter[MAX_ENCOUNTER];
        uint64 GateKirtonosGUID;
        uint64 GateGandlingGUID;
        uint64 GateMiliciaGUID;
        uint64 GateTheolenGUID;
        uint64 GatePolkeltGUID;
        uint64 GateRavenianGUID;
        uint64 GateBarovGUID;
        uint64 GateIlluciaGUID;
        uint64 BrazierOfTheHeraldGUID;

        void Initialize()
        {
            GateKirtonosGUID = 0;
            GateGandlingGUID = 0;
            GateMiliciaGUID = 0;
            GateTheolenGUID = 0;
            GatePolkeltGUID = 0;
            GateRavenianGUID = 0;
            GateBarovGUID = 0;
            GateIlluciaGUID = 0;
            BrazierOfTheHeraldGUID = 0;

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                m_auiEncounter[i] = NOT_STARTED;
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_GATE_KIRTONOS:           GateKirtonosGUID = go->GetGUID(); break;
                case GO_GATE_GANDLING:           GateGandlingGUID = go->GetGUID(); break;
                case GO_GATE_MALICIA:            GateMiliciaGUID = go->GetGUID(); break;
                case GO_GATE_THEOLEN:            GateTheolenGUID = go->GetGUID(); break;
                case GO_GATE_POLKELT:            GatePolkeltGUID = go->GetGUID(); break;
                case GO_GATE_RAVENIAN:           GateRavenianGUID = go->GetGUID(); break;
                case GO_GATE_BAROV:              GateBarovGUID = go->GetGUID(); break;
                case GO_GATE_ILLUCIA:            GateIlluciaGUID = go->GetGUID(); break;
                case GO_BRAZIER_OF_THE_HERALD:   BrazierOfTheHeraldGUID = go->GetGUID(); break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case DATA_LORDALEXEIBAROV:
                    m_auiEncounter[DATA_LORDALEXEIBAROV] = data;
                    CheckToSpawnGandling();
                    break;
                case DATA_DOCTORTHEOLENKRASTINOV:
                    m_auiEncounter[DATA_DOCTORTHEOLENKRASTINOV] = data;
                    CheckToSpawnGandling();
                    break;
                case DATA_THERAVENIAN:
                    m_auiEncounter[DATA_THERAVENIAN] = data;
                    CheckToSpawnGandling();
                    break;
                case DATA_LOREKEEPERPOLKELT:
                    m_auiEncounter[DATA_LOREKEEPERPOLKELT] = data;
                    CheckToSpawnGandling();
                    break;
                case DATA_INSTRUCTORMALICIA:
                    m_auiEncounter[DATA_INSTRUCTORMALICIA] = data;
                    CheckToSpawnGandling();
                    break;
                case DATA_LADYILLUCIABAROV:
                    m_auiEncounter[DATA_LADYILLUCIABAROV] = data;
                    CheckToSpawnGandling();
                    break;
                case DATA_DARKMASTERGANDLING:
                    m_auiEncounter[DATA_DARKMASTERGANDLING] = data;
                    break;
                case DATA_KIRTONOS:
                    m_auiEncounter[DATA_KIRTONOS] = data;
                    break;
            }
        }

        uint32 GetData(uint32 type) const
        {
            return type == (m_auiEncounter[DATA_LORDALEXEIBAROV] == DONE) && (m_auiEncounter[DATA_DOCTORTHEOLENKRASTINOV] == DONE) &&
                (m_auiEncounter[DATA_THERAVENIAN] == DONE) && (m_auiEncounter[DATA_LOREKEEPERPOLKELT] == DONE) &&
                (m_auiEncounter[DATA_INSTRUCTORMALICIA] == DONE) && (m_auiEncounter[DATA_LADYILLUCIABAROV] == DONE)
                ? IN_PROGRESS : 0;
        }

        uint64 GetData64(uint32 type) const
        {
            switch (type)
            {
                case GO_GATE_KIRTONOS:           return GateKirtonosGUID; break;
                case GO_GATE_GANDLING:           return GateGandlingGUID; break;
                case GO_GATE_MALICIA:            return GateMiliciaGUID; break;
                case GO_GATE_THEOLEN:            return GateTheolenGUID; break;
                case GO_GATE_POLKELT:            return GatePolkeltGUID; break;
                case GO_GATE_RAVENIAN:           return GateRavenianGUID; break;
                case GO_GATE_BAROV:              return GateBarovGUID; break;
                case GO_GATE_ILLUCIA:            return GateIlluciaGUID; break;
                case GO_BRAZIER_OF_THE_HERALD:   return BrazierOfTheHeraldGUID; break;
            }

            return 0;
        }

        void CheckToSpawnGandling()
        {
            if (GetData(DATA_DARKMASTERGANDLING) == IN_PROGRESS)
            {
                Map::PlayerList const &PlayerList = instance->GetPlayers();
                if (PlayerList.isEmpty())
                    return;

                Map::PlayerList::const_iterator i = PlayerList.begin();
                if (Player* i_pl = i->getSource())
                    i_pl->SummonCreature(NPC_DARKMASTER_GANDLING, GandlingLoc);
            }
        }
    };
};

void AddSC_instance_scholomance()
{
    new instance_scholomance();
}
