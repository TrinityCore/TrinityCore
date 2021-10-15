/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "halls_of_attonement.h"

class instance_halls_of_attonement : public InstanceMapScript
{
public:
    instance_halls_of_attonement() : InstanceMapScript(ABTScriptName, 2287) { }

    struct instance_halls_of_attonement_InstanceMapScript : public InstanceScript
    {
        instance_halls_of_attonement_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_halls_of_attonement_InstanceMapScript(map);
        }
    };
};

void AddSC_instance_halls_of_attonement()
{
    new instance_halls_of_attonement();
}
