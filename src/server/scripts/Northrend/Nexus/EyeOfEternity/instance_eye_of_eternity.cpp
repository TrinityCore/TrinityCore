/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "eye_of_eternity.h"

class instance_eye_of_eternity : public InstanceMapScript
{
public:
    instance_eye_of_eternity() : InstanceMapScript("instance_eye_of_eternity", 616) {}

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_eye_of_eternity_InstanceMapScript(map);
    }

    struct instance_eye_of_eternity_InstanceMapScript : public InstanceScript
    {
        instance_eye_of_eternity_InstanceMapScript(Map* map) : InstanceScript(map) 
        {
            SetBossNumber(MAX_ENCOUNTER);

            vortexTriggers.clear();
            portalTriggers.clear();

            malygosGUID = 0;
            lastPortalGUID = 0;
            platformGUID = 0;
            exitPortalGUID = 0;
        };

        bool SetBossState(uint32 type, EncounterState state)
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            if (type == DATA_MALYGOS_EVENT)
            {
                if (state == FAIL)
                {
                    for (std::list<uint64>::const_iterator itr_trigger = portalTriggers.begin(); itr_trigger != portalTriggers.end(); ++itr_trigger)
                    {
                        if (Creature* trigger = instance->GetCreature(*itr_trigger))
                        {
                            // just in case
                            trigger->RemoveAllAuras();
                            trigger->AI()->Reset();
                        }
                    }

                    SpawnGameObject(GO_FOCUSING_IRIS,focusingIrisPosition);
                    SpawnGameObject(GO_EXIT_PORTAL,exitPortalPosition);

                    if (GameObject* platform = instance->GetGameObject(platformGUID))
                        platform->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                } else if (state == DONE)
                {
                    if (Creature* malygos = instance->GetCreature(malygosGUID))
                        malygos->SummonCreature(NPC_ALEXSTRASZA,829.0679f,1244.77f,279.7453f,2.32f);

                    SpawnGameObject(GO_EXIT_PORTAL,exitPortalPosition);

                    // we make the platform appear again because at the moment we don't support looting using a vehicle
                    if (GameObject* platform = instance->GetGameObject(platformGUID))
                        platform->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);

                    if (GameObject* chest = instance->GetGameObject(chestGUID))
                        chest->SetRespawnTime(chest->GetRespawnDelay());
                }
            }
            return true;
        }

        // There is no other way afaik...
        void SpawnGameObject(uint32 entry, Position& pos)
        {
            GameObject* go = new GameObject;
            if (!go->Create(sObjectMgr->GenerateLowGuid(HIGHGUID_GAMEOBJECT),entry, instance,
                PHASEMASK_NORMAL, pos.GetPositionX(),pos.GetPositionY(),pos.GetPositionZ(),pos.GetOrientation(),
                0,0,0,0,120,GO_STATE_READY))
            {
                delete go;
                return;
            }

            instance->Add(go);
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_NEXUS_RAID_PLATFORM:
                    platformGUID = go->GetGUID();
                    break;
                case GO_FOCUSING_IRIS:
                    go->GetPosition(&focusingIrisPosition);
                    break;
                case GO_EXIT_PORTAL:
                    exitPortalGUID = go->GetGUID();
                    go->GetPosition(&exitPortalPosition);
                    break;
                case GO_ALEXSTRASZA_S_GIFT:
                case GO_ALEXSTRASZA_S_GIFT_2:
                    chestGUID = go->GetGUID();
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_VORTEX_TRIGGER:
                    vortexTriggers.push_back(creature->GetGUID());
                    break;
                case NPC_MALYGOS:
                    malygosGUID = creature->GetGUID();
                    break;
                case NPC_PORTAL_TRIGGER:
                    portalTriggers.push_back(creature->GetGUID());
                    break;
            }
        }

        void ProcessEvent(GameObject* go, uint32 eventId)
        {
            if (eventId == EVENT_FOCUSING_IRIS)
            {
                go->Delete(); // this is not the best way.
                if (Creature* malygos = instance->GetCreature(malygosGUID))
                    malygos->GetMotionMaster()->MovePoint(4,770.10f, 1275.33f, 267.23f); // MOVE_INIT_PHASE_ONE

                if (GameObject* exitPortal = instance->GetGameObject(exitPortalGUID))
                    exitPortal->Delete();
            }
        }

        void VortexHandling()
        {
            if (Creature* malygos = instance->GetCreature(malygosGUID))
            {
                std::list<HostileReference*> m_threatlist = malygos->getThreatManager().getThreatList();
                for (std::list<uint64>::const_iterator itr_vortex = vortexTriggers.begin(); itr_vortex != vortexTriggers.end(); ++itr_vortex)
                {
                    if (m_threatlist.empty())
                        return;

                    uint8 counter = 0;
                    if (Creature* trigger = instance->GetCreature(*itr_vortex))
                    {
                        // each trigger have to cast the spell to 5 players.
                        for (std::list<HostileReference*>::const_iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
                        {
                            if (counter >= 5)
                                break;

                            if (Unit* target = (*itr)->getTarget())
                            {
                                Player* player = target->ToPlayer();

                                if (!player || player->isGameMaster() || player->HasAura(SPELL_VORTEX_4))
                                    continue;

                                player->CastSpell(trigger,SPELL_VORTEX_4,true);
                                counter++;
                            }
                        }
                    }
                }
            }
        }

        void PowerSparksHandling()
        {
            bool next =  (lastPortalGUID == portalTriggers.back() || !lastPortalGUID ? true : false);

            for (std::list<uint64>::const_iterator itr_trigger = portalTriggers.begin(); itr_trigger != portalTriggers.end(); ++itr_trigger)
            {
                if (next)
                {
                    if (Creature* trigger = instance->GetCreature(*itr_trigger))
                    {
                        lastPortalGUID = trigger->GetGUID();
                        trigger->CastSpell(trigger,SPELL_PORTAL_OPENED,true);
                        return;
                    }
                }

                if (*itr_trigger == lastPortalGUID)
                    next = true;
            }
        }

        void SetData(uint32 data,uint32 /*value*/)
        {
            switch (data)
            {
                case DATA_VORTEX_HANDLING:
                    VortexHandling();
                    break;
                case DATA_POWER_SPARKS_HANDLING:
                    PowerSparksHandling();
                    break;
            }
        }

        uint64 GetData64(uint32 data)
        {
            switch (data)
            {
                case DATA_TRIGGER:
                    return vortexTriggers.front();
                case DATA_MALYGOS:
                    return malygosGUID;
                case DATA_PLATFORM:
                    return platformGUID;
            }

            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "E E " << GetBossSaveData();

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

            if (dataHead1 == 'E' && dataHead2 == 'E')
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
            std::list<uint64> vortexTriggers;
            std::list<uint64> portalTriggers;
            uint64 malygosGUID;
            uint64 lastPortalGUID;
            uint64 platformGUID;
            uint64 exitPortalGUID;
            uint64 chestGUID;
            Position focusingIrisPosition;
            Position exitPortalPosition;
    };
};

void AddSC_instance_eye_of_eternity()
{
   new instance_eye_of_eternity();
}
