/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "stormstout_brewery.h"

class instance_stormstout_brewery : public InstanceMapScript
{
public:
    instance_stormstout_brewery() : InstanceMapScript("instance_stormstout_brewery", 961) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_stormstout_brewery_InstanceMapScript(map);
    }

    struct instance_stormstout_brewery_InstanceMapScript : public InstanceScript
    {
        ObjectGuid ookookGUID;
        ObjectGuid hoptallusGUID;
        ObjectGuid yanzhuGUID;

        instance_stormstout_brewery_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

        void Initialize() override
        {
            ookookGUID      = ObjectGuid::Empty;
            hoptallusGUID   = ObjectGuid::Empty;
            yanzhuGUID      = ObjectGuid::Empty;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_OOK_OOK:
                    ookookGUID = creature->GetGUID();
                    break;
                case NPC_HOPTALLUS:
                    hoptallusGUID = creature->GetGUID();
                    break;
                case NPC_YAN_ZHU:
                    yanzhuGUID = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* /*go*/) override
        {}

        void SetData(uint32 /*type*/, uint32 /*data*/) override
        {}

        uint32 GetData(uint32 /*type*/) const override
        {
            return 0;
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case NPC_OOK_OOK:
                    return ookookGUID;
                case NPC_HOPTALLUS:
                    return hoptallusGUID;
                case NPC_YAN_ZHU:
                    return yanzhuGUID;
            }

            return ObjectGuid::Empty;
        }
    };

};

void AddSC_instance_stormstout_brewery()
{
    new instance_stormstout_brewery();
}
