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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"

class at_legion_instance_portal : public AreaTriggerEntityScript
{
public:
    at_legion_instance_portal(const char* name, uint32 mapId, float x, float y, float z, float o) : AreaTriggerEntityScript(name), _tpLocation(mapId, x, y, z, o) {}
    at_legion_instance_portal(const char* name, uint32 worldSafeLocs) : AreaTriggerEntityScript(name)
    {
        WorldSafeLocsEntry const* safeLoc = sObjectMgr->GetWorldSafeLoc(worldSafeLocs);
        ASSERT(safeLoc);
        _tpLocation = WorldLocation(safeLoc->Loc);
    }

    WorldLocation _tpLocation;

    struct at_legion_instance_portalAI : AreaTriggerAI
    {
        at_legion_instance_portalAI(AreaTrigger* areatrigger, WorldLocation tpLocation) : AreaTriggerAI(areatrigger), _tpLocation(tpLocation) { }

        WorldLocation _tpLocation;

        void OnUnitEnter(Unit* unit) override
        {
            if (Player* player = unit->ToPlayer())
                player->TeleportTo(_tpLocation);
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new at_legion_instance_portalAI(areatrigger, _tpLocation);
    }
};

void AddSC_legion_portal_at_scripts()
{
    new at_legion_instance_portal("at_legion_portal_dal_chamber_entrance", 1220,-784.447f, 4418.802f, 602.47973f, 2.443143f);
    new at_legion_instance_portal("at_legion_portal_dal_chamber_exit", 1220, -849.907959f, 4461.175f, 735.66101f, 4.045355f);
    new at_legion_instance_portal("at_legion_portal_helheim_exit",     1220, 3641.396973f, 774.1938f, -3.139639f, 2.321205f);
    new at_legion_instance_portal("at_legion_portal_warl_oh_exit",     1220, -796.369568f, 4577.488f, 700.57702f, 4.626544f);
    new at_legion_instance_portal("at_legion_portal_archerus_to_upper",1220, -1469.25f,     1116.78f, 313.74f,    4.165537f);
    new at_legion_instance_portal("at_legion_portal_archerus_to_lower",1220, -1473.09f,     1109.74f, 270.07f,    4.177318f);
}
