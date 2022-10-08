/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "thunder_forge.h"

class instance_thunder_forge : public InstanceMapScript
{
public:
    instance_thunder_forge() : InstanceMapScript("instance_thunder_forge", 1126) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_thunder_forge_InstanceMapScript(map);
    }

    struct instance_thunder_forge_InstanceMapScript : public InstanceScript
    {
        instance_thunder_forge_InstanceMapScript(Map* map) : InstanceScript(map)
        { }

        void Initialize() override
        {
            playerRole = ROLES_DEFAULT;

            crucibleGUID.Clear();
            doorGUID.Clear();
            wrathionGUID.Clear();
            forgemasterGUID.Clear();
            celectialBlacksmithGUID.Clear();
            celectialDefenderGUID.Clear();
            portal.Clear();
            warriorGUIDs[0].Clear();
            warriorGUIDs[1].Clear();

            stageData = STAGE_1;
            waveCounter = 0;
            s1p2 = 0;
            s2p1 = 0;
            s2p2 = 0;
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GO_MOGU_CRICUBLE:
                    crucibleGUID = go->GetGUID();
                    break;
                case GO_THUNDER_FORGE_DOOR:
                    doorGUID = go->GetGUID();
                    break;
                case GO_INVISIBLE_WALL:
                    invisibleWallGUID = go->GetGUID();
                    break;
                case GO_PORTAL_TO_THUNDER_ISLAND:
                    go->SetVisible(false);
                    portal = go->GetGUID();
                    break;
                default:
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_WRATHION:
                    creature->RemoveFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    wrathionGUID = creature->GetGUID();
                    break;
                case NPC_SHADO_PAN_WARRIOR:
                    creature->SetFloatValue(UNIT_FIELD_COMBAT_REACH, 60.f);
                    if(!warriorGUIDs[0])
                        warriorGUIDs[0] = creature->GetGUID();
                    else if(!warriorGUIDs[1])
                        warriorGUIDs[1] = creature->GetGUID();
                    break;
                case NPC_SHADO_PAN_DEFENDER:
                    creature->SetFloatValue(UNIT_FIELD_COMBAT_REACH, 60.f);
                    defenderGUID = creature->GetGUID();
                    break;
                case NPC_FORGEMASTER_VULKON:
                    creature->SetFloatValue(UNIT_FIELD_COMBAT_REACH, 60.f);
                    forgemasterGUID = creature->GetGUID();
                    break;
                case NPC_CELESTIAL_BLACKSMITH:
                    celectialBlacksmithGUID = creature->GetGUID();
                    break;
                case NPC_CELESTIAL_DEFENDER:
                    creature->SetFloatValue(UNIT_FIELD_COMBAT_REACH, 60.f);
                    celectialDefenderGUID = creature->GetGUID();
                    break;
                default:
                    break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_PLAYER_ROLE:
                    playerRole = data;
                    break;
                case DATA_ALLOWED_STAGE:
                    stageData = data;
                    switch (data)
                    {
                        case STAGE_3:
                            if (Creature* cre = instance->GetCreature(wrathionGUID))
                                cre->AI()->DoAction(ACTION_1);
                            break;
                        default:
                            break;
                    }
                    break;
                case DATA_WAVE_COUNTER:
                    waveCounter = data;
                    switch (data)
                    {
                        case 0:
                            if (Creature* cre = instance->GetCreature(defenderGUID))
                                cre->AI()->DoAction(ACTION_1);
                            break;
                        default:
                            break;
                    }
                    break;
                case DATA_STAGE1_P2:
                    s1p2 = data;
                    switch (data)
                    {
                        case IN_PROGRESS:
                            if (Creature* cre = instance->GetCreature(forgemasterGUID))
                            {
                                cre->SetReactState(REACT_AGGRESSIVE);
                                cre->SetPhaseMask(1, true);
                                cre->AI()->DoAction(ACTION_1);
                            }
                            break;
                        case DONE:
                        {
                            // HandleGameObject(GetGuidData(doorGUID), true); EVIL
                            Map::PlayerList const& players = instance->GetPlayers();
                            if (Player* plr = players.begin()->getSource())
                            {
                                if (GameObject* obj = GameObject::GetGameObject(*plr, invisibleWallGUID))
                                    obj->DestroyForPlayer(plr);

                                if (GameObject* obj = GameObject::GetGameObject(*plr, doorGUID))
                                    obj->DestroyForPlayer(plr);
                            }

                            if (Creature* cre = instance->GetCreature(wrathionGUID))
                                cre->AI()->DoAction(ACTION_3);
                            break;
                        }
                    }
                case DATA_SECOND_STAGE_FIRST_STEP:
                {
                    s2p1 = data;
                    switch (data)
                    {
                        case FAIL:
                            if (Creature* cre = instance->GetCreature(wrathionGUID))
                                cre->AI()->DoAction(ACTION_1);
                            break;
                        default:
                            break;
                    }
                    break;
                }
                case DATA_COMPLETE_SECOND_STAGE_SECOND_STEP:
                    s2p2 = data;
                    if (data == DONE)
                    {
                        Map::PlayerList const& players = instance->GetPlayers();
                        if (Player* plr = players.begin()->getSource())
                        {
                            plr->UpdateAchievementCriteria(CRITERIA_TYPE_SCRIPT_EVENT_2, 35754, 1);
                            plr->KilledMonsterCredit(70094, ObjectGuid::Empty); //< set quest 32593 completed
                        }

                        if (Creature* cre = instance->GetCreature(wrathionGUID))
                        {
                            cre->AI()->DoAction(ACTION_9);
                            cre->SetFlag(UNIT_FIELD_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                        }

                        if (GameObject* obj = instance->GetGameObject(portal))
                            obj->SetVisible(true);
                    }
                    break;
                default:
                    break;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_PLAYER_ROLE:
                    return playerRole;
                case DATA_ALLOWED_STAGE:
                    return stageData;
                case DATA_WAVE_COUNTER:
                    return waveCounter;
                case DATA_STAGE1_P2:
                    return s1p2;
                default:
                    break;
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_MOGU_CRUCIBLE:
                    return crucibleGUID;
                case DATA_WARRIOR_1:
                    return warriorGUIDs[0];
                case DATA_WARRIOR_2:
                    return warriorGUIDs[1];
                case DATA_DEFENDER:
                    return defenderGUID;
                case DATA_TRUNDER_FORGE_DOOR:
                    return doorGUID;
                case DATA_WRATHION:
                    return wrathionGUID;
                case DATA_CELESTIAL_BLACKSMITH:
                    return celectialBlacksmithGUID;
                case DATA_CELESTIAL_DEFENDER:
                    return celectialDefenderGUID;
                default:
                    break;
            }
            return ObjectGuid::Empty;
        }

    private:
        uint32 playerRole;

        ObjectGuid doorGUID;
        ObjectGuid invisibleWallGUID;
        ObjectGuid crucibleGUID;
        ObjectGuid wrathionGUID;
        ObjectGuid defenderGUID;
        ObjectGuid forgemasterGUID;
        ObjectGuid celectialBlacksmithGUID;
        ObjectGuid celectialDefenderGUID;
        ObjectGuid portal;

        ObjectGuid warriorGUIDs[2];

        uint32 stageData;
        uint32 waveCounter;
        uint32 s1p2;
        uint32 s2p1;
        uint32 s2p2;
    };
};

bool Helper::IsNextStageAllowed(InstanceScript* instance, uint8 stage)
{
    switch (stage)
    {
        case STAGE_2:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_1)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_2);
                return true;
            }
            return false;
        case STAGE_3:
            if (instance->GetData(DATA_ALLOWED_STAGE) == STAGE_2)
            {
                instance->SetData(DATA_ALLOWED_STAGE, STAGE_3);
                return true;
            }
            return false;
        default:
            return false;
    }
    return false;
}

void AddSC_instance_thunder_forge()
{
    new instance_thunder_forge();
}
