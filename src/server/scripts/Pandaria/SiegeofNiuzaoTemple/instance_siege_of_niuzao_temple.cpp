/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
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
#include "siege_of_niuzao_temple.h"


class instance_siege_of_niuzao_temple : public InstanceMapScript
{
    public:
        instance_siege_of_niuzao_temple() : InstanceMapScript("instance_siege_of_niuzao_temple", 1011) { }

        struct instance_siege_of_niuzao_temple_InstanceMapScript : public InstanceScript
        {
            instance_siege_of_niuzao_temple_InstanceMapScript(Map* map) : InstanceScript(map)
			{}
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_siege_of_niuzao_temple_InstanceMapScript(map);
        }
};

void AddSC_instance_siege_of_niuzao_temple()
{
    new instance_siege_of_niuzao_temple();
}
