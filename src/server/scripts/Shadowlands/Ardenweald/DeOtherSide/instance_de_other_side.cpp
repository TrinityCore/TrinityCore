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
#include "de_other_side.h"

class instance_de_other_side : public InstanceMapScript
{
public:
    instance_de_other_side() : InstanceMapScript(ABTScriptName, 2291) { }

    struct instance_de_other_side_InstanceMapScript : public InstanceScript
    {
        instance_de_other_side_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_de_other_side_InstanceMapScript(map);
        }
    };
};

void AddSC_instance_de_other_side()
{
    new instance_de_other_side();
}
