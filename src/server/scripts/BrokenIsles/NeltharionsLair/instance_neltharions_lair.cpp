/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "VMapFactory.h"
#include "ObjectAccessor.h"
#include "neltharions_lair.h"
#include "GameObject.h"
#include "Log.h"
#include "Map.h"
#include "Object.h"
#include "Containers.h"

#include <numeric>

struct instance_neltharions_lair : public InstanceScript
{
    instance_neltharions_lair(InstanceMap* map) : InstanceScript(map)
    {
        SetHeaders(DataHeader);
        SetBossNumber(EncounterCount);
    }

    int32 round(float v)
    { 
        return floor( v + 0.5f); 
    }

    ObjectGuid spiritWalkerGUID;
    ObjectGuid navarroggRokmoraStarterGUID;
    ObjectGuid ularoggRokmoraStarterGUID;
    ObjectGuid rokmoraGUID;
    ObjectGuid barrierGUID;
    ObjectGuid goObstructionGUID;
    ObjectGuid rightIdolGuid;
    ObjectGuid leftIdolGuid;
    ObjectGuid centerIdolGuid;
    ObjectGuid backIdolGuid;
    ObjectGuid frontIdolGuid;
    ObjectGuid ularoggBarrierGUID;
    ObjectGuid naraxasBarrierGUID;
    ObjectGuid naraxasLootGUID;
    uint32 startDialogState = 0;
    uint32 rokmoraDialogState = 0;
    uint32 barrelsEventState = 0;
    uint32 rokmoraData = 0;
    uint32 ularoggCragshaperData = 0;
    uint32 naraxasData = 0;
    uint32 centerIdolKilled = 0;
    uint32 dargrulData = 0;

    void Initialize() override
    {
        SetBossNumber(EncounterCount);
        spiritWalkerGUID.Clear();
        navarroggRokmoraStarterGUID.Clear();
        ularoggRokmoraStarterGUID.Clear();
        rokmoraGUID.Clear();
        barrierGUID.Clear();
        goObstructionGUID.Clear();
        ularoggBarrierGUID.Clear();
        naraxasBarrierGUID.Clear();
        naraxasLootGUID.Clear();
    }

    void OnGameObjectCreate(GameObject* go) override
    {
        switch(go->GetEntry())
        {
            case GO_MYSTIC_BARRIER:
                barrierGUID = go->GetGUID();
                break;
            case GO_NAVARROGG_OBSTRUCTION:
                goObstructionGUID = go->GetGUID();
                break;
            case GO_BARRIER_ULAROGG:
                ularoggBarrierGUID = go->GetGUID();
                break;
            case GO_BARRIER_NARAXAS:
                naraxasBarrierGUID = go->GetGUID();
                break;
            case GO_NARAXAS_LOOT:
                naraxasLootGUID = go->GetGUID();
                go->AddFlag(GameObjectFlags(GO_FLAG_LOCKED | GO_FLAG_NOT_SELECTABLE | GO_FLAG_NODESPAWN));
                break;
        }
    }

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
            case NPC_SPIRITWALKER:
                spiritWalkerGUID = creature->GetGUID();
                break;
            case NPC_NAVARROGG_ROKMORA_STARTER:
                navarroggRokmoraStarterGUID = creature->GetGUID();
                break;
            case NPC_ULAROGG_ROKMORA_STARTER:
                ularoggRokmoraStarterGUID = creature->GetGUID();
                break;
            case NPC_ROKMORA:
                rokmoraGUID = creature->GetGUID();
        }

        if (creature->GetEntry() == NPC_BELLOWING_IDOL_M_STANCE)
        {
            if (round(creature->GetPositionX()) == round(ularoggRightIdolStartPos.GetPositionX()) &&
                round(creature->GetPositionY()) == round(ularoggRightIdolStartPos.GetPositionY()) &&
                round(creature->GetPositionZ()) == round(ularoggRightIdolStartPos.GetPositionZ()))
                rightIdolGuid = creature->GetGUID();

            if (round(creature->GetPositionX()) == round(ularoggLeftIdolStartPos.GetPositionX()) &&
                round(creature->GetPositionY()) == round(ularoggLeftIdolStartPos.GetPositionY()) &&
                round(creature->GetPositionZ()) == round(ularoggLeftIdolStartPos.GetPositionZ()))
                leftIdolGuid = creature->GetGUID();

            if (round(creature->GetPositionX()) == round(ularoggJumpPos.GetPositionX()) &&
                round(creature->GetPositionY()) == round(ularoggJumpPos.GetPositionY()) &&
                round(creature->GetPositionZ()) == round(ularoggJumpPos.GetPositionZ()))
                centerIdolGuid = creature->GetGUID();

            if (instance->GetDifficultyID() >= 2)
            {
                if (round(creature->GetPositionX()) == round(ularoggBackIdolStartPos.GetPositionX()) &&
                round(creature->GetPositionY()) == round(ularoggBackIdolStartPos.GetPositionY()) &&
                round(creature->GetPositionZ()) == round(ularoggBackIdolStartPos.GetPositionZ()))
                backIdolGuid = creature->GetGUID();

                if (round(creature->GetPositionX()) == round(ularoggFrontIdolStartPos.GetPositionX()) &&
                round(creature->GetPositionY()) == round(ularoggFrontIdolStartPos.GetPositionY()) &&
                round(creature->GetPositionZ()) == round(ularoggFrontIdolStartPos.GetPositionZ()))
                frontIdolGuid = creature->GetGUID();
            }
        }
    }

    uint32 GetData(uint32 type) const override
    {
        switch (type)
        {
            case DATA_ENTRANCE_START_DIALOG:
                return startDialogState;
            case DATA_ROKMORA_START_DIALOG:
                return rokmoraDialogState;
            case DATA_BARRELS_EVENT:
                return barrelsEventState;
            case DATA_ROKMORA:
                return rokmoraData;
            case DATA_ULAROGG_CRAGSHAPER:
                return ularoggCragshaperData;
            case DATA_NARAXAS:
                return naraxasData;
            case DATA_CENTER_IDOL_KILLED:
                return centerIdolKilled;
            case DATA_DARGRUL:
                return dargrulData;
            default:
                break;
        }

        return 0;
    }

    void SetData(uint32 type, uint32 data) override
    {
        switch (type)
        {
            case DATA_ENTRANCE_START_DIALOG:
                startDialogState = data;
                break;
            case DATA_ROKMORA_START_DIALOG:
                rokmoraDialogState = data;
                break;
            case DATA_BARRELS_EVENT:
                barrelsEventState = data;
                break;
            case DATA_ROKMORA:
                rokmoraData = data;
                break;
            case DATA_ULAROGG_CRAGSHAPER:
                ularoggCragshaperData = data;
                break;
            case DATA_NARAXAS:
                naraxasData = data;
                break;
            case DATA_CENTER_IDOL_KILLED:
                centerIdolKilled = data;
                break;
            case DATA_DARGRUL:
                dargrulData = data;
                break;
        }
    }

    void WriteSaveDataMore(std::ostringstream& data) override
    {
        data << startDialogState << ' '
        << rokmoraDialogState << ' '
        << barrelsEventState << ' '
        << rokmoraData << ' '
        << ularoggCragshaperData << ' '
        << naraxasData << ' '
        << centerIdolKilled << ' '
        << dargrulData;
    }

    void ReadSaveDataMore(std::istringstream& data) override
    {
        uint32 temp = 0;
        data >> temp;
        startDialogState = temp ? DONE : NOT_STARTED;
            
        data >> temp;
        rokmoraDialogState = temp ? DONE : NOT_STARTED;
        data >> temp;
        barrelsEventState = temp ? DONE : NOT_STARTED;
        data >> temp;
        rokmoraData = temp ? DONE : NOT_STARTED;
        data >> temp;
        ularoggCragshaperData = temp ? DONE : NOT_STARTED;
        data >> temp;
        naraxasData = temp ? DONE : NOT_STARTED;
        data >> temp;
        centerIdolKilled = temp ? DONE : NOT_STARTED;
        data >> temp;
        dargrulData = temp ? DONE : NOT_STARTED;
    }

    ObjectGuid GetGuidData(uint32 uiType) const override
    {
        switch(uiType)
        {
            case DATA_SPIRITWALKER:
                return spiritWalkerGUID;
                break;
            case DATA_NAVARROGG_ROKMORA_STARTER:
                return navarroggRokmoraStarterGUID;
                break;
            case DATA_ULAROGG_ROKMORA_STARTER:
                return ularoggRokmoraStarterGUID;
                break;
            case DATA_ROKMORA:
                return rokmoraGUID;
                break;
            case DATA_MYSTIC_BARRIER:
                return barrierGUID;
                break;
            case DATA_BARRIER_ULAROGG:
                return ularoggBarrierGUID;
                break;
            case DATA_BARRIER_NARAXAS:
                return naraxasBarrierGUID;
                break;
            case DATA_NARAXAS_LOOT:
                return naraxasLootGUID;
                break;
            case DATA_GO_NAVARROGG_OBSTRUCTION:
                return goObstructionGUID;
                break;
            case DATA_RIGHT_IDOL:
                return rightIdolGuid;
                break;
            case DATA_LEFT_IDOL:
                return leftIdolGuid;
                break;
            case DATA_CENTER_IDOL:
                return centerIdolGuid;
                break;
            case DATA_BACK_IDOL:
                return backIdolGuid;
                break;
            case DATA_FRONT_IDOL:
                return frontIdolGuid;
                break;
        }

        return ObjectGuid::Empty;
    }
};

void AddSC_instance_neltharions_lair()
{
    RegisterInstanceScript(instance_neltharions_lair, 1458);
}
