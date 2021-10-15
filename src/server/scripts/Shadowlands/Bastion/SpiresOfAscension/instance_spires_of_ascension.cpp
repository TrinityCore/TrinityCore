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
#include "spires_of_ascension.h"
#include "instance_spires_of_ascension.h"

class instance_spires_of_ascension : public InstanceMapScript
{
public:
    instance_spires_of_ascension() : InstanceMapScript(ABTScriptName, 2285) { }

    struct instance_spires_of_ascension_InstanceMapScript : public InstanceScript
    {
        instance_spires_of_ascension_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_spires_of_ascension_InstanceMapScript(map);
        }
    };
};

void AddSC_instance_spires_of_ascension()
{
    new instance_spires_of_ascension();
}
