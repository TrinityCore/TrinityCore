/*
 * Copyright 2023 AzgathCore
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

#include "neltharions_lair.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    {GO_ROKMORA_DOOR,           DATA_ROKMORA,       DOOR_TYPE_PASSAGE},
    {GO_ULAROGG_DOOR,           DATA_ULAROGG,       DOOR_TYPE_PASSAGE},
    {GO_ULAROGG_DOOR_2,         DATA_ULAROGG,       DOOR_TYPE_ROOM},
    {GO_NARAXAS_DOOR,           DATA_NARAXAS,       DOOR_TYPE_ROOM},
    {GO_NARAXAS_EXIT_DOOR_1,    DATA_NARAXAS,       DOOR_TYPE_PASSAGE},
    {GO_NARAXAS_EXIT_DOOR_2,    DATA_NARAXAS,       DOOR_TYPE_PASSAGE},
};

class instance_neltharions_lair : public InstanceMapScript
{
public:
    instance_neltharions_lair() : InstanceMapScript("instance_neltharions_lair", 1458) {}

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_neltharions_lair_InstanceMapScript(map);
    }

    struct instance_neltharions_lair_InstanceMapScript : public InstanceScript
    {
        instance_neltharions_lair_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_ENCOUNTER);
        }

        WorldLocation loc_res_pla;

        ObjectGuid NaraxasChestGUID;
        ObjectGuid UlaroggGUID;

        void Initialize()
        {
            LoadDoorData(doorData);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_ULAROGG_CRAGSHAPER:
                UlaroggGUID = creature->GetGUID();
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_ROKMORA_DOOR:
            case GO_ULAROGG_DOOR:
            case GO_ULAROGG_DOOR_2:
            case GO_NARAXAS_DOOR:
            case GO_NARAXAS_EXIT_DOOR_1:
            case GO_NARAXAS_EXIT_DOOR_2:
                AddDoor(go, true);
                break;
            case GO_NARAXAS_CHEST:
                NaraxasChestGUID = go->GetGUID();
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
            case DATA_NARAXAS:
                if (state == DONE)
                    if (GameObject* chest = instance->GetGameObject(NaraxasChestGUID))
                        chest->SetRespawnTime(604800);
                break;
            default:
                break;
            }

            return true;
        }

        void SetData(uint32 /*type*/, uint32 /*data*/) override
        {
            /*switch (type)
            {
                default:
                    break;
            }*/
        }

        ObjectGuid GetGuidData(uint32 type) const
        {
            switch (type)
            {
            case NPC_ULAROGG_CRAGSHAPER:
                return UlaroggGUID;
            }
            return ObjectGuid::Empty;
        }

        uint32 GetData(uint32 /*type*/) const override
        {
            return 0;
        }
    };
};

void AddSC_instance_neltharions_lair()
{
    new instance_neltharions_lair();
}
