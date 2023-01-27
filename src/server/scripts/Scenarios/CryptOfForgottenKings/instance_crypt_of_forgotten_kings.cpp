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
#include "crypt_of_forgotten_kings.h"

class instance_crypt_of_forgotten_kings : public InstanceMapScript
{
public:
    instance_crypt_of_forgotten_kings() : InstanceMapScript("instance_crypt_of_forgotten_kings", 1030) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_crypt_of_forgotten_kings_InstanceMapScript(map);
    }

    struct instance_crypt_of_forgotten_kings_InstanceMapScript : public InstanceScript
    {
        instance_crypt_of_forgotten_kings_InstanceMapScript(Map* map) : InstanceScript(map)
        { }

        void Initialize() override
        {
        }

        void OnPlayerEnter(Player* player) override
        {
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case 0:
                default:
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case 0:
                default:
                    return ObjectGuid::Empty;
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case 0:
                default:
                    return 0;
            }
        }
    };
};

void AddSC_instance_crypt_of_forgotten_kings()
{
    new instance_crypt_of_forgotten_kings();
}
