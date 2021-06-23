/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
 * Copyright (C) 2016 Firestorm Servers <https://firestorm-servers.com>
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
#include "siege_of_the_niuzao_temple.h"

class instance_siege_of_the_niuzao_temple : public InstanceMapScript
{
public:
    instance_siege_of_the_niuzao_temple() : InstanceMapScript("instance_siege_of_the_niuzao_temple", 1011) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_siege_of_the_niuzao_temple_InstanceMapScript(map);
    }

    struct instance_siege_of_the_niuzao_temple_InstanceMapScript : public InstanceScript
    {
        ObjectGuid jinbakGUID;
        ObjectGuid vojakGUID;
        ObjectGuid pavalakGUID;
        ObjectGuid neronokGUID;

        instance_siege_of_the_niuzao_temple_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

        void Initialize() override
        {
            jinbakGUID  = ObjectGuid::Empty;
            vojakGUID   = ObjectGuid::Empty;
            pavalakGUID = ObjectGuid::Empty;
            neronokGUID = ObjectGuid::Empty;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_JINBAK:
                    jinbakGUID = creature->GetGUID();
                    break;
                case NPC_VOJAK:
                    vojakGUID = creature->GetGUID();
                    break;
                case NPC_PAVALAK:
                    pavalakGUID = creature->GetGUID();
                    break;
                case NPC_NERONOK:
                    neronokGUID = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* /*go*/) override {}

        void SetData(uint32 /*type*/, uint32 /*p_Data*/) override {}

        uint32 GetData(uint32 /*type*/) const override
        {
            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case NPC_JINBAK:
                    return jinbakGUID;
                case NPC_VOJAK:
                    return vojakGUID;
                case NPC_PAVALAK:
                    return pavalakGUID;
                case NPC_NERONOK:
                    return neronokGUID;
            }

            return ObjectGuid::Empty;
        }
    };

};

void AddSC_instance_siege_of_the_niuzao_temple()
{
    new instance_siege_of_the_niuzao_temple();
}
