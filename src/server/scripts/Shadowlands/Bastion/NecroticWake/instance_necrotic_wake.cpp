/*
 * Copyright 2021 ShadowCore
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

struct instance_necrotic_wake : public InstanceScript
{
    instance_necrotic_wake(InstanceMap* map) : InstanceScript(map)
    {
        if (Transport* transport = sTransportMgr->CreateTransport(GO_NECROPOLIS_TRANSPORT, UI64LIT(0), instance))
        {
            transport->SetDynamicFlags(GO_DYNFLAG_LO_STOPPED);
            transport->SetFlags(GameObjectFlags(GO_FLAG_MAP_OBJECT | GO_FLAG_NODESPAWN | GO_FLAG_TRANSPORT));
        }
    }
};

void AddSC_instance_necrotic_wake()
{
    RegisterInstanceScript(instance_necrotic_wake, 2286);
}
