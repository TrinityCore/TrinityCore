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

#include "darkheart_thicket.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    {GO_GLAIDALIS_FIRE_DOOR,     DATA_GLAIDALIS,     DOOR_TYPE_ROOM},
    {GO_DRESARON_FIRE_DOOR,      DATA_DRESARON,      DOOR_TYPE_ROOM},
    {GO_OAKHEART_DOOR,           DATA_OAKHEART,      DOOR_TYPE_ROOM},
};

class instance_darkheart_thicket : public InstanceMapScript
{
public:
    instance_darkheart_thicket() : InstanceMapScript("instance_darkheart_thicket", 1466) {}

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_darkheart_thicket_InstanceMapScript(map);
    }

    struct instance_darkheart_thicket_InstanceMapScript : public InstanceScript
    {
        instance_darkheart_thicket_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_ENCOUNTER);
        }

        WorldLocation loc_res_pla;

        ObjectGuid MalfurionGUID;
        ObjectGuid MalfurionCageGUID;
        ObjectGuid InvisDoorGUID;
        ObjectGuid DresaronGUID;

        void Initialize()
        {
            LoadDoorData(doorData);
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            return true;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_MALFURION_STORMRAGE:
                MalfurionGUID = creature->GetGUID();
                break;
            case NPC_DRESARON:
                DresaronGUID = creature->GetGUID();
                break;
            case NPC_NIGHTMARE_BINDINGS:
                MalfurionCageGUID = creature->GetGUID();
                break;
            default:
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_GLAIDALIS_FIRE_DOOR:
            case GO_DRESARON_FIRE_DOOR:
            case GO_OAKHEART_DOOR:
                AddDoor(go, true);
                break;
            case GO_GLAIDALIS_INVIS_DOOR:
                InvisDoorGUID = go->GetGUID();
                break;
            default:
                break;
            }
        }

        void SetData(uint32 /*type*/, uint32 /*data*/) override
        {
            /*switch (type)
            {
                default:
                    break;
            }*/
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case NPC_MALFURION_STORMRAGE:
                return MalfurionGUID;
            case NPC_DRESARON:
                return DresaronGUID;
            case NPC_NIGHTMARE_BINDINGS:
                return MalfurionCageGUID;
            case GO_GLAIDALIS_INVIS_DOOR:
                return InvisDoorGUID;
            }
            return ObjectGuid::Empty;
        }

        uint32 GetData(uint32 /*type*/) const override
        {
            return 0;
        }
    };
};

void AddSC_instance_darkheart_thicket()
{
    new instance_darkheart_thicket();
}
