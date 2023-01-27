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

#include "ScriptMgr.h"
#include "Player.h"
#include "InstanceScript.h"
#include "ScriptedCreature.h"
#include "Creature.h"
#include "World.h"
#include "Group.h"
#include "GameObject.h"
#include "atal_dazar.h"
#include "Conversation.h"

enum conversationyasma
{
    CONVERSATION_YAZMA_INTRO = 6320,
};

struct instance_atal_dazar : public InstanceScript
{
    instance_atal_dazar(InstanceMap* map) : InstanceScript(map)
    {
        SetHeaders(DataHeader);
        SetBossNumber(DATA_MAX_ENCOUNTERS);
    }
    void Initialize() override
    {
        cont = 0;
    }

    void OnCreatureCreate(Creature* cre) override
    {
        switch (cre->GetEntry())
        {
        case NPC_PRIESTESS_ALUNZA:
            PriestressGUID = cre->GetGUID();
            break;
        default:
            break;
        }

        InstanceScript::OnCreatureCreate(cre);

        if (instance->GetDifficultyID() == 1)
        {
            cre->SetLevel(110);
        }
        if (instance->GetDifficultyID() == 2)
        {
            cre->SetLevel(121);
        }
        if (instance->GetDifficultyID() == 23)
        {
            cre->SetLevel(122);
        }
        if (instance->GetDifficultyID() == 8)
        {
            cre->SetLevel(122);
        }
    };

    void OnPlayerEnter(Player* player) override
    {
        SetCheckPointPos({ -839.0337f, -2092.268f, 725.8119f, 0.41233432f });
        Conversation::CreateConversation(CONVERSATION_YAZMA_INTRO, player, player->GetPosition(), { player->GetGUID() });
    };

    ObjectGuid GetGuidData(uint32 type) const override
    {
        switch (type)
        {
        case DATA_PRIESTESS_ALUNZA:
            return PriestressGUID;
        case GO_GATE_001:
            return Gate01GUID;
        case GO_GATE_002:
            return Gate02GUID;
        case GO_GATE_003:
            return Gate03GUID;
        case GO_GATE_004:
            return Gate04GUID;
        case GO_GATE_005:
            return Gate05GUID;
        case GO_GATE_006:
            return Gate06GUID;
        case GO_GATE_007:
            return Gate07GUID;
        case GO_GATE_008:
            return Gate08GUID;
        case GO_GATE_009:
            return Gate09GUID;
        case GO_GATE_010:
            return Gate10GUID;
        case GO_ANCIENT_SWITCH01:
            return ancientSwitchGUID;
        case GO_ANCIENT_SWITCH02:
            return ancientSwitch02GUID;
        case GO_COLLISION_WALL:
            return collisionWallGUID;
        default:
            break;
        }
        return ObjectGuid::Empty;
    }

    void OnGameObjectCreate(GameObject* go) override
    {
        switch (go->GetEntry())
        {
        case GO_ANCIENT_SWITCH01:
            ancientSwitchGUID = go->GetGUID();
            break;
        case GO_ANCIENT_SWITCH02:
            ancientSwitch02GUID = go->GetGUID();
            break;
        case GO_GATE_001:
            Gate01GUID = go->GetGUID();
            if (GameObject* ancientSwitch = instance->GetGameObject(ancientSwitchGUID))
                go->SetGoState(ancientSwitch->GetGoState() != GO_STATE_ACTIVE ? GO_STATE_READY : GO_STATE_ACTIVE);
            go->AddFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GO_GATE_002:
            Gate02GUID = go->GetGUID();
            if (GameObject* ancientSwitch = instance->GetGameObject(ancientSwitchGUID))
                go->SetGoState(ancientSwitch->GetGoState() != GO_STATE_ACTIVE ? GO_STATE_READY : GO_STATE_ACTIVE);
            go->AddFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GO_GATE_003:
            Gate03GUID = go->GetGUID();
            if (GameObject* ancientSwitch = instance->GetGameObject(ancientSwitchGUID))
                go->SetGoState(ancientSwitch->GetGoState() != GO_STATE_ACTIVE ? GO_STATE_READY : GO_STATE_ACTIVE);
            go->AddFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GO_GATE_004:
            Gate04GUID = go->GetGUID();
            if (GameObject* ancientSwitch = instance->GetGameObject(ancientSwitchGUID))
                go->SetGoState(ancientSwitch->GetGoState() != GO_STATE_ACTIVE ? GO_STATE_READY : GO_STATE_ACTIVE);
            go->AddFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GO_GATE_005:
            Gate05GUID = go->GetGUID();
            if (GameObject* ancientSwitch = instance->GetGameObject(ancientSwitchGUID))
                go->SetGoState(GetBossState(NPC_VOLKAAL) == IN_PROGRESS ? GO_STATE_READY : GO_STATE_ACTIVE);
            go->AddFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GO_GATE_006:
            Gate06GUID = go->GetGUID();
            if (GameObject* ancientSwitch = instance->GetGameObject(ancientSwitchGUID))
                go->SetGoState(GetBossState(NPC_VOLKAAL) == IN_PROGRESS ? GO_STATE_READY : GO_STATE_ACTIVE);
            go->AddFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GO_GATE_007:
            Gate07GUID = go->GetGUID();
            if (GameObject* ancientSwitch = instance->GetGameObject(ancientSwitchGUID))
                go->SetGoState(GetBossState(NPC_VOLKAAL) == IN_PROGRESS ? GO_STATE_READY : GO_STATE_ACTIVE);
            go->AddFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GO_GATE_008:
            Gate08GUID = go->GetGUID();
            if (GameObject* ancientSwitch = instance->GetGameObject(ancientSwitchGUID))
                go->SetGoState(GetBossState(NPC_VOLKAAL) == IN_PROGRESS ? GO_STATE_READY : GO_STATE_ACTIVE);
            go->AddFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GO_GATE_009:
            Gate09GUID = go->GetGUID();
            go->SetGoState((GetBossState(DATA_PRIESTESS_ALUNZA) == DONE && GetBossState(DATA_VOLKAAL) == DONE && GetBossState(DATA_REZAN) == DONE) ? GO_STATE_ACTIVE : GO_STATE_READY);
            go->AddFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GO_GATE_010:
            Gate10GUID = go->GetGUID();
            go->SetGoState((GetBossState(DATA_PRIESTESS_ALUNZA) == DONE && GetBossState(DATA_VOLKAAL) == DONE && GetBossState(DATA_REZAN) == DONE) ? GO_STATE_ACTIVE : GO_STATE_READY);
            go->AddFlag(GO_FLAG_NOT_SELECTABLE);
            break;
        case GO_COLLISION_WALL:
            collisionWallGUID = go->GetGUID();
            break;
        case GO_WATERFALL_STAIRS:
            waterfallstairsGUID = go->GetGUID();
            break;
        default:
            break;
        }
    }

    void OnUnitDeath(Unit* unit) override
    {
        if (!unit->IsCreature())
            return;
        if (unit->GetEntry() == NPC_PRIESTESS_ALUNZA)
        {
            cont++;
        }
        if (unit->GetEntry() == NPC_VOLKAAL)
        {
            cont++;
        }
        if (unit->GetEntry() == NPC_REZAN)
        {
            cont++;
        }
        if (cont == 3)
        {
            if (GameObject* yazmagate01 = instance->GetGameObject(Gate09GUID))
                yazmagate01->SetGoState(GO_STATE_ACTIVE);
            if (GameObject* yazmagate02 = instance->GetGameObject(Gate10GUID))
                yazmagate02->SetGoState(GO_STATE_ACTIVE);
            if (GameObject* colision = instance->GetGameObject(collisionWallGUID))
                colision->SetGoState(GO_STATE_ACTIVE);
            if (GameObject* water = instance->GetGameObject(waterfallstairsGUID))
                water->SetGoState(GO_STATE_ACTIVE);
        }
    }

protected:
    ObjectGuid PriestressGUID;
    ObjectGuid ancientSwitchGUID;
    ObjectGuid ancientSwitch02GUID;
    ObjectGuid waterfallstairsGUID;
    ObjectGuid collisionWallGUID;
    ObjectGuid Gate01GUID;
    ObjectGuid Gate02GUID;
    ObjectGuid Gate03GUID;
    ObjectGuid Gate04GUID;
    ObjectGuid Gate05GUID;
    ObjectGuid Gate06GUID;
    ObjectGuid Gate07GUID;
    ObjectGuid Gate08GUID;
    ObjectGuid Gate09GUID;
    ObjectGuid Gate10GUID;
    int8 cont;
};

void AddSC_instance_atal_dazar()
{
    RegisterInstanceScript(instance_atal_dazar, 1763);
}
