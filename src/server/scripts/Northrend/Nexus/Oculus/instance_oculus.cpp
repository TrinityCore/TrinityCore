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
#include "oculus.h"
#include "Player.h"

#define MAX_ENCOUNTER 4

/* The Occulus encounters:
0 - Drakos the Interrogator
1 - Varos Cloudstrider
2 - Mage-Lord Urom
3 - Ley-Guardian Eregos */

class instance_oculus : public InstanceMapScript
{
public:
    instance_oculus() : InstanceMapScript("instance_oculus", 578) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_oculus_InstanceMapScript(map);
    }

    struct instance_oculus_InstanceMapScript : public InstanceScript
    {
        instance_oculus_InstanceMapScript(Map* map) : InstanceScript(map) {}

        void Initialize()
        {
            SetBossNumber(MAX_ENCOUNTER);

            drakosGUID = 0;
            varosGUID = 0;
            uromGUID = 0;
            eregosGUID = 0;

            platformUrom = 0;
            centrifugueConstructCounter = 0;

            eregosCacheGUID = 0;

            gwhelpList.clear();
            gameObjectList.clear();

            belgaristraszGUID = 0;
            eternosGUID = 0;
            verdisaGUID = 0;
}

        void OnUnitDeath(Unit* unit)
        {
            Creature* creature = unit->ToCreature();
            if (!creature)
                return;

            if (creature->GetEntry() != NPC_CENTRIFUGE_CONSTRUCT)
                return;

             DoUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, --centrifugueConstructCounter);

             if (!centrifugueConstructCounter)
                if (Creature* varos = instance->GetCreature(varosGUID))
                    varos->RemoveAllAuras();
        }

        void OnPlayerEnter(Player* player)
        {
            if (GetBossState(DATA_DRAKOS_EVENT) == DONE && GetBossState(DATA_VAROS_EVENT) != DONE)
            {
                player->SendUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW, 1);
                player->SendUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, centrifugueConstructCounter);
            } else
            {
                player->SendUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW, 0);
                player->SendUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, 0);
            }
        }

        void ProcessEvent(WorldObject* /*unit*/, uint32 eventId)
        {
            if (eventId != EVENT_CALL_DRAGON)
                return;

            Creature* varos = instance->GetCreature(varosGUID);

            if (!varos)
                return;

            if (Creature* drake = varos->SummonCreature(NPC_AZURE_RING_GUARDIAN, varos->GetPositionX(), varos->GetPositionY(), varos->GetPositionZ()+40))
                drake->AI()->DoAction(ACTION_CALL_DRAGON_EVENT);
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_DRAKOS:
                    drakosGUID = creature->GetGUID();
                    break;
                case NPC_VAROS:
                    varosGUID = creature->GetGUID();
                    if (GetBossState(DATA_DRAKOS_EVENT) == DONE)
                       creature->SetPhaseMask(1, true);
                    break;
                case NPC_UROM:
                    uromGUID = creature->GetGUID();
                    if (GetBossState(DATA_VAROS_EVENT) == DONE)
                        creature->SetPhaseMask(1, true);
                    break;
                case NPC_EREGOS:
                    eregosGUID = creature->GetGUID();
                    if (GetBossState(DATA_UROM_EVENT) == DONE)
                        creature->SetPhaseMask(1, true);
                    break;
                case NPC_CENTRIFUGE_CONSTRUCT:
                    if (creature->IsAlive())
                        DoUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, ++centrifugueConstructCounter);
                    break;
                case NPC_BELGARISTRASZ:
                    belgaristraszGUID = creature->GetGUID();
                    if (GetBossState(DATA_DRAKOS_EVENT) == DONE)
                        creature->SetWalk(true),
                        creature->GetMotionMaster()->MovePoint(0, 941.453f, 1044.1f, 359.967f),
                        creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    break;
                case NPC_ETERNOS:
                    eternosGUID = creature->GetGUID();
                    if (GetBossState(DATA_DRAKOS_EVENT) == DONE)
                        creature->SetWalk(true),
                        creature->GetMotionMaster()->MovePoint(0, 943.202f, 1059.35f, 359.967f),
                        creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    break;
                case NPC_VERDISA:
                    verdisaGUID = creature->GetGUID();
                    if (GetBossState(DATA_DRAKOS_EVENT) == DONE)
                        creature->SetWalk(true),
                        creature->GetMotionMaster()->MovePoint(0, 949.188f, 1032.91f, 359.967f),
                        creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    break;
                case NPC_GREATER_WHELP:
                    if (GetBossState(DATA_UROM_EVENT) == DONE)
                        creature->SetPhaseMask(1, true);
                        gwhelpList.push_back(creature->GetGUID());
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_DRAGON_CAGE_DOOR:
                    if (GetBossState(DATA_DRAKOS_EVENT) == DONE)
                        go->SetGoState(GO_STATE_ACTIVE);
                    else
                        go->SetGoState(GO_STATE_READY);
                    gameObjectList.push_back(go->GetGUID());
                    break;
                case GO_EREGOS_CACHE_N:
                case GO_EREGOS_CACHE_H:
                    eregosCacheGUID = go->GetGUID();
                    break;
                default:
                    break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state)
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
                case DATA_DRAKOS_EVENT:
                    if (state == DONE)
                    {
                        DoUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW, 1);
                        DoUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_AMOUNT, centrifugueConstructCounter);
                        OpenCageDoors();
                        FreeDragons();
                        if (Creature* varos = instance->GetCreature(varosGUID))
                            varos->SetPhaseMask(1, true);
                    }
                    break;
                case DATA_VAROS_EVENT:
                    if (state == DONE)
                        DoUpdateWorldState(WORLD_STATE_CENTRIFUGE_CONSTRUCT_SHOW, 0);
                        if (Creature* urom = instance->GetCreature(uromGUID))
                            urom->SetPhaseMask(1, true);
                    break;
                case DATA_UROM_EVENT:
                    if (state == DONE)
                        if (Creature* eregos = instance->GetCreature(eregosGUID))
                            eregos->SetPhaseMask(1, true);
                            GreaterWhelps();
                    break;
                case DATA_EREGOS_EVENT:
                    if (state == DONE)
                        DoRespawnGameObject(eregosCacheGUID, 7*DAY);
                    break;
            }

            return true;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case DATA_UROM_PLATAFORM:
                    platformUrom = data;
                    break;
            }
        }

        uint32 GetData(uint32 type) const
        {
            switch (type)
            {
                case DATA_UROM_PLATAFORM:              return platformUrom;
                // used by condition system
                case DATA_UROM_EVENT:                  return GetBossState(DATA_UROM_EVENT);
            }

            return 0;
        }

        uint64 GetData64(uint32 identifier) const
        {
            switch (identifier)
            {
                case DATA_DRAKOS:                 return drakosGUID;
                case DATA_VAROS:                  return varosGUID;
                case DATA_UROM:                   return uromGUID;
                case DATA_EREGOS:                 return eregosGUID;
            }

            return 0;
        }

        void OpenCageDoors()
        {
            if (gameObjectList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = gameObjectList.begin(); itr != gameObjectList.end(); ++itr)
            {
                if (GameObject* go = instance->GetGameObject(*itr))
                    go->SetGoState(GO_STATE_ACTIVE);
            }
        }

        void FreeDragons()
        {
            if (Creature* belgaristrasz = instance->GetCreature(belgaristraszGUID))
                belgaristrasz->SetWalk(true),
                belgaristrasz->GetMotionMaster()->MovePoint(0, 941.453f, 1044.1f, 359.967f);
            if (Creature* eternos = instance->GetCreature(eternosGUID))
                eternos->SetWalk(true),
                eternos->GetMotionMaster()->MovePoint(0, 943.202f, 1059.35f, 359.967f);
            if (Creature* verdisa = instance->GetCreature(verdisaGUID))
                verdisa->SetWalk(true),
                verdisa->GetMotionMaster()->MovePoint(0, 949.188f, 1032.91f, 359.967f);
        }

        void GreaterWhelps()
        {
            if (gwhelpList.empty())
                return;

            for (std::list<uint64>::const_iterator itr = gwhelpList.begin(); itr != gwhelpList.end(); ++itr)
            {
                if (Creature* gwhelp = instance->GetCreature(*itr))
                    gwhelp->SetPhaseMask(1, true);
            }
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "T O " << GetBossSaveData();

            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'T' && dataHead2 == 'O')
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    SetBossState(i, EncounterState(tmpState));
                }
            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
        private:
            uint64 drakosGUID;
            uint64 varosGUID;
            uint64 uromGUID;
            uint64 eregosGUID;

            uint64 belgaristraszGUID;
            uint64 eternosGUID;
            uint64 verdisaGUID;

            uint8 platformUrom;
            uint8 centrifugueConstructCounter;

            uint64 eregosCacheGUID;

            std::string str_data;

            std::list<uint64> gameObjectList;
            std::list<uint64> gwhelpList;
    };
};

void AddSC_instance_oculus()
{
    new instance_oculus();
}
