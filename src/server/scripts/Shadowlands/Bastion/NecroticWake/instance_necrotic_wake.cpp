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

#include "necrotic_wake.h"
#include "ScriptMgr.h"
#include "Player.h"
#include "InstanceScript.h"
#include "Transport.h"
#include "TransportMgr.h"
#include "instance_necrotic_wake.h"

class instance_necrotic_wake : public InstanceMapScript
{
public:
    instance_necrotic_wake() : InstanceMapScript(ABTScriptName, 2286) { }

    struct instance_necrotic_wake_InstanceMapScript : public InstanceScript
    {
        instance_necrotic_wake_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { }

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_necrotic_wake_InstanceMapScript(map);
        }
    };
};

void AddSC_instance_necrotic_wake()
{
    new instance_necrotic_wake();
}
