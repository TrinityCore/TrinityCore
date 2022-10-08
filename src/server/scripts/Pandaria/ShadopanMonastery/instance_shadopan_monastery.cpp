/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "GameObject.h"
#include "PhasingHandler.h"
#include "shadopan_monastery.h"
#include "InstanceScript.h"

Position snowdriftCenterPos = {3659.08f, 3015.38f, 804.74f};

class instance_shadopan_monastery : public InstanceMapScript
{
public:
    instance_shadopan_monastery() : InstanceMapScript("instance_shadopan_monastery", 959) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_shadopan_monastery_InstanceMapScript(map);
    }

    struct instance_shadopan_monastery_InstanceMapScript : public InstanceScript
    {
        uint8 aliveNoviceCount;
        uint8 aliveMinibossCount;

        ObjectGuid guCloudstikeGUID;
        ObjectGuid masterSnowdriftGUID;
        ObjectGuid shaViolenceGUID;
        ObjectGuid taranZhuGUID;

        ObjectGuid azureSerpentGUID;

        ObjectGuid cloudstikeEntranceGUID;
        ObjectGuid cloudstikeExitGUID;
        ObjectGuid snowdriftEntranceGUID;
        ObjectGuid snowdriftPossessionsGUID;
        ObjectGuid snowdriftFirewallGUID;
        ObjectGuid snowdriftDojoDoorGUID;
        ObjectGuid snowdriftExitGUID;

        ObjectGuid shaEntranceGUID;
        ObjectGuid shaExitGUID;

        std::list<ObjectGuid> minibossPositionsGUID;
        std::list<ObjectGuid> minibossPositionsGUIDSave;

        std::list<ObjectGuid> firstDefeatedNovicePositionsGUID;
        std::list<ObjectGuid> firstDefeatedNovicePositionsGUIDSave;

        std::list<ObjectGuid> secondDefeatedNovicePositionsGUID;
        std::list<ObjectGuid> secondDefeatedNovicePositionsGUIDSave;

        std::list<ObjectGuid> firstArcherySet;
        std::list<ObjectGuid> secondArcherySet;
        std::list<ObjectGuid> archeryTargetGUIDs;

        uint32 dataStorage[MAX_DATA];

        instance_shadopan_monastery_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

        void Initialize() override
        {
            SetBossNumber(EncounterCount);

            aliveNoviceCount            = MAX_NOVICE;
            aliveMinibossCount          = 2;

            guCloudstikeGUID            = ObjectGuid::Empty;
            masterSnowdriftGUID         = ObjectGuid::Empty;
            shaViolenceGUID             = ObjectGuid::Empty;
            taranZhuGUID                = ObjectGuid::Empty;

            azureSerpentGUID            = ObjectGuid::Empty;

            cloudstikeEntranceGUID      = ObjectGuid::Empty;
            cloudstikeExitGUID          = ObjectGuid::Empty;
            snowdriftEntranceGUID       = ObjectGuid::Empty;
            snowdriftEntranceGUID       = ObjectGuid::Empty;
            snowdriftPossessionsGUID    = ObjectGuid::Empty;
            snowdriftFirewallGUID       = ObjectGuid::Empty;
            snowdriftDojoDoorGUID       = ObjectGuid::Empty;
            snowdriftExitGUID           = ObjectGuid::Empty;

            shaEntranceGUID             = ObjectGuid::Empty;
            shaExitGUID                 = ObjectGuid::Empty;

            firstArcherySet.clear();
            secondArcherySet.clear();

            memset(dataStorage, 0, MAX_DATA * sizeof(uint32));
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_GU_CLOUDSTRIKE:    guCloudstikeGUID    = creature->GetGUID();          return;
                case NPC_MASTER_SNOWDRIFT:  masterSnowdriftGUID = creature->GetGUID();          return;
                case NPC_SHA_VIOLENCE:      shaViolenceGUID     = creature->GetGUID();          return;
                case NPC_TARAN_ZHU:         taranZhuGUID        = creature->GetGUID();          return;
                case NPC_AZURE_SERPENT:     azureSerpentGUID    = creature->GetGUID();          return;
                case NPC_ARCHERY_TARGET:    archeryTargetGUIDs.push_back(creature->GetGUID());  return;
                case NPC_SNOWDRIFT_POSITION:
                {
                    if (creature->GetDistance(snowdriftCenterPos) > 5.0f && creature->GetDistance(snowdriftCenterPos) < 15.0f)
                    {
                        minibossPositionsGUID.push_back(creature->GetGUID());
                        minibossPositionsGUIDSave.push_back(creature->GetGUID());
                    }
                    else if (creature->GetDistance(snowdriftCenterPos) > 15.0f  && creature->GetDistance(snowdriftCenterPos) < 17.5f)
                    {
                        firstDefeatedNovicePositionsGUID.push_back(creature->GetGUID());
                        firstDefeatedNovicePositionsGUIDSave.push_back(creature->GetGUID());
                    }
                    else if (creature->GetDistance(snowdriftCenterPos) > 17.5f && creature->GetDistance(snowdriftCenterPos) < 25.0f)
                    {
                        secondDefeatedNovicePositionsGUID.push_back(creature->GetGUID());
                        secondDefeatedNovicePositionsGUIDSave.push_back(creature->GetGUID());
                    }
                    break;
                }
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_CLOUDSTRIKE_ENTRANCE:
                    cloudstikeEntranceGUID = go->GetGUID();
                    HandleGameObject(ObjectGuid::Empty, true, go);
                    break;
                case GO_CLOUDSTRIKE_EXIT:
                    cloudstikeExitGUID = go->GetGUID();
                    break;
                case GO_SNOWDRIFT_ENTRANCE:
                    snowdriftEntranceGUID = go->GetGUID();
                    HandleGameObject(ObjectGuid::Empty, true, go);
                    break;
                case GO_SNOWDRIFT_POSSESSIONS:
                    PhasingHandler::AddPhase(go, 50);
                    snowdriftPossessionsGUID = go->GetGUID();
                    break;
                case GO_SNOWDRIFT_FIRE_WALL:
                    snowdriftFirewallGUID = go->GetGUID();
                    break;
                case GO_SNOWDRIFT_DOJO_DOOR:
                    snowdriftDojoDoorGUID = go->GetGUID();
                    break;
                case GO_SNOWDRIFT_EXIT:
                    snowdriftExitGUID = go->GetGUID();
                    break;
                case GO_SHA_ENTRANCE:
                    shaEntranceGUID = go->GetGUID();
                    HandleGameObject(ObjectGuid::Empty, true, go);
                    break;
                case GO_SHA_EXIT:
                    shaExitGUID = go->GetGUID();
                    break;
                default:
                    return;
            }
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_GU_CLOUDSTRIKE:
                {
                    switch (state)
                    {
                        case NOT_STARTED:
                        case FAIL:
                        {
                            HandleGameObject(cloudstikeEntranceGUID, true);
                            HandleGameObject(cloudstikeExitGUID,     false);
                            break;
                        }
                        case IN_PROGRESS:
                        {
                            HandleGameObject(cloudstikeEntranceGUID, false);
                            HandleGameObject(cloudstikeExitGUID,     false);
                            break;
                        }
                        case DONE:
                        {
                            HandleGameObject(cloudstikeEntranceGUID, true);
                            HandleGameObject(cloudstikeExitGUID,     true);
                            HandleGameObject(snowdriftEntranceGUID,  true);
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case DATA_MASTER_SNOWDRIFT:
                {
                    switch (state)
                    {
                        case NOT_STARTED:
                        case FAIL:
                            aliveNoviceCount                    = MAX_NOVICE;
                            aliveMinibossCount                  = 2;
                            minibossPositionsGUID               = minibossPositionsGUIDSave;
                            firstDefeatedNovicePositionsGUID    = firstDefeatedNovicePositionsGUIDSave;
                            secondDefeatedNovicePositionsGUID   = secondDefeatedNovicePositionsGUIDSave;

                            HandleGameObject(snowdriftEntranceGUID, true);
                            HandleGameObject(snowdriftFirewallGUID, false);
                            HandleGameObject(snowdriftDojoDoorGUID, false);
                            HandleGameObject(snowdriftExitGUID,     false);
                            break;
                        case IN_PROGRESS:
                            HandleGameObject(snowdriftEntranceGUID, false);
                            HandleGameObject(snowdriftDojoDoorGUID, false);
                            break;
                        case DONE:
                            if (GameObject* possessions = instance->GetGameObject(snowdriftPossessionsGUID))
                                PhasingHandler::ResetPhaseShift(possessions);

                            HandleGameObject(snowdriftEntranceGUID, true);
                            HandleGameObject(snowdriftFirewallGUID, true);
                            HandleGameObject(snowdriftDojoDoorGUID, true);
                            HandleGameObject(snowdriftExitGUID,     true);
                            HandleGameObject(shaEntranceGUID,       true);
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case DATA_SHA_VIOLENCE:
                {
                    switch (state)
                    {
                        case NOT_STARTED:
                        case FAIL:
                            HandleGameObject(shaEntranceGUID,   true);
                            HandleGameObject(shaExitGUID,       false);
                            break;
                        case IN_PROGRESS:
                            HandleGameObject(shaEntranceGUID,   false);
                        case DONE:
                            HandleGameObject(shaEntranceGUID,   true);
                            HandleGameObject(shaExitGUID,       true);
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case DATA_TARAN_ZHU:
                {
                    if (state == IN_PROGRESS)
                        DoAddAuraOnPlayers(SPELL_HATE);
                    else
                    {
                        Map::PlayerList const &PlayerList = instance->GetPlayers();

                        if (!PlayerList.isEmpty())
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                if (Player* player = i->GetSource())
                                {
                                    player->RemoveAurasDueToSpell(SPELL_HATE);
                                    player->RemoveAurasDueToSpell(SPELL_HAZE_OF_HATE);
                                    player->RemoveAurasDueToSpell(SPELL_HAZE_OF_HATE_VISUAL);
                                }
                    }
                    break;
                }
                default:
                    break;
            }

            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_DEFEATED_NOVICE:
                    if (!--aliveNoviceCount)
                        if (Creature* snowdrift = instance->GetCreature(masterSnowdriftGUID))
                            if (snowdrift->IsAIEnabled)
                                snowdrift->AI()->DoAction(ACTION_NOVICE_DONE);
                    break;
                case DATA_DEFEATED_MINIBOSS:
                    if (!--aliveMinibossCount)
                    {
                        if (Creature* snowdrift = instance->GetCreature(masterSnowdriftGUID))
                            if (snowdrift->IsAIEnabled)
                                snowdrift->AI()->DoAction(ACTION_MINIBOSS_DONE);

                        HandleGameObject(snowdriftFirewallGUID, true);
                        HandleGameObject(snowdriftDojoDoorGUID, true);
                    }
                    break;
                default:
                    if (type < MAX_DATA)
                        dataStorage[type] = data;
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            if (type < MAX_DATA)
                return dataStorage[type];

            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case NPC_GU_CLOUDSTRIKE:
                    return guCloudstikeGUID;
                case NPC_MASTER_SNOWDRIFT:
                    return masterSnowdriftGUID;
                case NPC_SHA_VIOLENCE:
                    return shaViolenceGUID;
                case NPC_TARAN_ZHU:
                    return taranZhuGUID;
                case NPC_AZURE_SERPENT:
                    return azureSerpentGUID;
                case NPC_ARCHERY_TARGET:
                    return Trinity::Containers::SelectRandomContainerElement(archeryTargetGUIDs);
                case DATA_RANDOM_FIRST_POS:
                {
                    if (firstDefeatedNovicePositionsGUID.empty())
                        return ObjectGuid::Empty;

                    ObjectGuid GUID = Trinity::Containers::SelectRandomContainerElement(firstDefeatedNovicePositionsGUID);
                    //firstDefeatedNovicePositionsGUID.remove(GUID);
                    return GUID;
                }
                case DATA_RANDOM_SECOND_POS:
                {
                    if (secondDefeatedNovicePositionsGUID.empty())
                        return ObjectGuid::Empty;

                    ObjectGuid GUID = Trinity::Containers::SelectRandomContainerElement(secondDefeatedNovicePositionsGUID);
                    //secondDefeatedNovicePositionsGUID.remove(GUID);
                    return GUID;
                }
                case DATA_RANDOM_MINIBOSS_POS:
                {
                    if (minibossPositionsGUID.empty())
                        return ObjectGuid::Empty;

                    ObjectGuid GUID = Trinity::Containers::SelectRandomContainerElement(minibossPositionsGUID);
                    //minibossPositionsGUID.remove(GUID);
                    return GUID;
                }
            }

            return ObjectGuid::Empty;
        }
    };

};

void AddSC_instance_shadopan_monastery()
{
    new instance_shadopan_monastery();
}
