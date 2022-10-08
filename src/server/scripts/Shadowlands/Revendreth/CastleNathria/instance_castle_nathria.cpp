/*
 * Copyright 2021 ShadowCore
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
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "castle_nathria.h"

DoorData const doorData[] =
{
    //Shriekwing
    { GO_DOOR_SHRIEKWING_LEFT, DATA_SHRIEKWING, DOOR_TYPE_PASSAGE },
    { GO_DOOR_SHRIEKWING_LEFT2, DATA_SHRIEKWING, DOOR_TYPE_PASSAGE },
    //Altimor
    { GO_DOOR_ALTIMOR_EXIT_LEFT, DATA_HUNTSMAN_ALTIMOR, DOOR_TYPE_PASSAGE },
    { GO_DOOR_ALTIMOR_EXIT_RIGHT, DATA_HUNTSMAN_ALTIMOR, DOOR_TYPE_PASSAGE },
    //Hungering
    { GO_DOOR_HUNGERING_LEFT, DATA_HUNGERING_DESTROYER, DOOR_TYPE_PASSAGE },
    { GO_DOOR_HUNGERING_RIGHT, DATA_HUNGERING_DESTROYER, DOOR_TYPE_PASSAGE },
    //Lady Inerva Darkevein
    { GO_DOOR_LADY_ONE, DATA_LADY_INERVA_DARKVEIN, DOOR_TYPE_PASSAGE },
    { GO_DOOR_LADY_TWO, DATA_LADY_INERVA_DARKVEIN, DOOR_TYPE_PASSAGE },
    //Unlock CoB after Inerva defeat
    { GO_DOOR_COUNCIL_OF_BLOOD_LEFT, DATA_LADY_INERVA_DARKVEIN, DOOR_TYPE_PASSAGE },
    { GO_DOOR_COUNCIL_OF_BLOOD_RIGHT, DATA_LADY_INERVA_DARKVEIN, DOOR_TYPE_PASSAGE },
    //Concil of Blood, unlock door to Sludgefist
    { GO_DOOR_SLUDGEFIST_LEFT, DATA_COUNCIL_OF_BLOOD, DOOR_TYPE_PASSAGE },
    { GO_DOOR_SLUDGEFIST_RIGHT, DATA_COUNCIL_OF_BLOOD, DOOR_TYPE_PASSAGE },
    //Stone Legion Generals, unlock door to Sire Denathrius
    { GO_DOOR_SIRE_DENATHRIUS, DATA_COUNCIL_OF_BLOOD, DOOR_TYPE_PASSAGE },
};

//2296
struct instance_castle_nathria : public InstanceScript
{
    instance_castle_nathria(InstanceMap* map) : InstanceScript(map) { }

    void Initialize() override
    {
        LoadDoorData(doorData);
        SetBossNumber(EncounterCount);
    }  

    ObjectGuid shriekwingDoorLeft;
    ObjectGuid shriekwingDoorLeftSecond;
    ObjectGuid shriekwingDoorRight;
    ObjectGuid shriekwingDoorRightSecond;
    ObjectGuid altimorDoorLeft;
    ObjectGuid altimorDoorRight;
    ObjectGuid altimorTunnel;
    ObjectGuid hungeringDoorLeft;
    ObjectGuid hungeringDoorRight;
    ObjectGuid ladyInervaDarkveinDoor;
    ObjectGuid ladyInervaDarkveinDoorTwo;
    ObjectGuid councilOfBloodTopDoorLeft;
    ObjectGuid councilOfBloodTopDoorRight;
    ObjectGuid sludgefistDoorLeft;
    ObjectGuid sludgefistDoorRight;
    ObjectGuid sireDenathriusDoor;
    ObjectGuid sludgefist;
    ObjectGuid brickDoorLeft;

    void OnCreatureCreate(Creature* creature) override
    {
        switch (creature->GetEntry())
        {
        case NPC_SLUDGEFIST:
            sludgefist = creature->GetGUID();
            break;
        }
    }

    void OnGameObjectCreate(GameObject* go) override
    {
        switch (go->GetEntry())
        {
        case GO_BRICKDOOR_LEFT:
            brickDoorLeft = go->GetGUID();
            break;
        case GO_DOOR_SHRIEKWING_LEFT:
            shriekwingDoorLeft = go->GetGUID();
            break;
        case GO_DOOR_SHRIEKWING_LEFT2:
            shriekwingDoorLeftSecond = go->GetGUID();
            break;
        case GO_DOOR_SHRIEKWING_RIGHT:
            shriekwingDoorRight = go->GetGUID();
            break;
        case GO_DOOR_SHRIEKWING_RIGHT2:
            shriekwingDoorRightSecond = go->GetGUID();
            break;
        case GO_DOOR_ALTIMOR_EXIT_LEFT:
            altimorDoorLeft = go->GetGUID();
            break;
        case GO_DOOR_ALTIMOR_EXIT_RIGHT:
            altimorDoorRight = go->GetGUID();
            break;
        case GO_DOOR_ALTIMOR_TUNNEL:
            altimorTunnel = go->GetGUID();
            break;
        case GO_DOOR_HUNGERING_LEFT:
            hungeringDoorLeft = go->GetGUID();
            break;
        case GO_DOOR_HUNGERING_RIGHT:
            hungeringDoorRight = go->GetGUID();
            break;
        case GO_DOOR_LADY_ONE:
            ladyInervaDarkveinDoor = go->GetGUID();
            break;
        case GO_DOOR_LADY_TWO:
            ladyInervaDarkveinDoorTwo = go->GetGUID();
            break;
        case GO_DOOR_COUNCIL_OF_BLOOD_LEFT:
            councilOfBloodTopDoorLeft = go->GetGUID();
            break;
        case GO_DOOR_COUNCIL_OF_BLOOD_RIGHT:
            councilOfBloodTopDoorRight = go->GetGUID();
            break;
        case GO_DOOR_SLUDGEFIST_LEFT:
            sludgefistDoorLeft = go->GetGUID();
            break;
        case GO_DOOR_SLUDGEFIST_RIGHT:
            sludgefistDoorRight = go->GetGUID();
            break;
        case GO_DOOR_SIRE_DENATHRIUS:
            sireDenathriusDoor = go->GetGUID();
            break;
        }
    }

    bool SetBossState(uint32 type, EncounterState state) override
    {
        if (!InstanceScript::SetBossState(type, state))
            return false;

        switch(type)
        {
        case DATA_SHRIEKWING:
            if (state == DONE)
            {
                HandleGameObject(shriekwingDoorLeft, true);
                HandleGameObject(shriekwingDoorLeftSecond, true);
                HandleGameObject(shriekwingDoorRight, true);
                HandleGameObject(shriekwingDoorRightSecond, true);
            }
            break;
        case DATA_HUNTSMAN_ALTIMOR:
            if (state == DONE)
            {
                HandleGameObject(altimorDoorLeft, true);
                HandleGameObject(altimorDoorRight, true);
                HandleGameObject(altimorTunnel, true);
            }
            break;
        case DATA_HUNGERING_DESTROYER:
            if (state == DONE)
            {
                HandleGameObject(hungeringDoorLeft, true);
                HandleGameObject(hungeringDoorRight, true);
                HandleGameObject(brickDoorLeft, true);
            }
            break;
        case DATA_LADY_INERVA_DARKVEIN:
            if (state == DONE)
            {
                HandleGameObject(ladyInervaDarkveinDoor, true);
                HandleGameObject(ladyInervaDarkveinDoorTwo, true);
                HandleGameObject(councilOfBloodTopDoorLeft, true);
                HandleGameObject(councilOfBloodTopDoorRight, true);
            }
            break;
        case DATA_COUNCIL_OF_BLOOD:
            if (state == DONE)
            {
                HandleGameObject(sludgefistDoorLeft, true);
                HandleGameObject(sludgefistDoorRight, true);
                if (Creature* Sludgefist = instance->GetCreature(sludgefist))
                {
                    Sludgefist->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                    Sludgefist->UpdatePosition(-1865.940f, 6721.381f, 4319.212f, 1.600f, true);
                }
            }
            break;
        case DATA_STONE_LEGION_GENERALS:
            if (state == DONE)
            {
                HandleGameObject(sireDenathriusDoor, true);
            }
            break;
        }
        return true;
    }
};

//100007
struct at_nathria_nightcloak : public AreaTriggerAI
{
    at_nathria_nightcloak(AreaTrigger* at) : AreaTriggerAI(at) { }

    void OnUnitEnter(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (InstanceScript* instance = target->GetInstanceScript())
            if (instance->GetBossState(DATA_SLUDGEFIST) == DONE)
                target->NearTeleportTo(-1840.733f, -9408.963f, 4644.256f, 0.948f, false);
    }
};

void AddSC_instance_castle_nathria()
{
    RegisterInstanceScript(instance_castle_nathria, 2296);
    RegisterAreaTriggerAI(at_nathria_nightcloak);
}
