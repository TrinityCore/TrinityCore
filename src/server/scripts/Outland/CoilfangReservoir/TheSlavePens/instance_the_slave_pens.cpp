/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

/*
This placeholder for the instance is needed for dungeon finding to be able
to give credit after the boss defined in lastEncounterDungeon is killed.
Without it, the party doing random dungeon won't get satchel of spoils and
gets instead the deserter debuff.
*/

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "the_slave_pens.h"

class instance_the_slave_pens : public InstanceMapScript
{
public:
    instance_the_slave_pens() : InstanceMapScript(SPScriptName, 547) { }

    struct instance_the_slave_pens_InstanceMapScript : public InstanceScript
    {
        instance_the_slave_pens_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            counter = DATA_FLAMECALLER_000;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
                case NPC_AHUNE:
                    AhuneGUID = creature->GetGUID();
                    break;
                case NPC_FROZEN_CORE:
                    FrozenCoreGUID = creature->GetGUID();
                    break;
                case NPC_AHUNE_LOC_BUNNY:
                    AhuneBunnyGUID = creature->GetGUID();
                    break;
                case NPC_SHAMAN_BONFIRE_BUNNY_000:
                    BonfireBunnyGUIDs[0] = creature->GetGUID();
                    break;
                case NPC_SHAMAN_BONFIRE_BUNNY_001:
                    BonfireBunnyGUIDs[1] = creature->GetGUID();
                    break;
                case NPC_SHAMAN_BONFIRE_BUNNY_002:
                    BonfireBunnyGUIDs[2] = creature->GetGUID();
                    break;
                case NPC_SHAMAN_BEAM_BUNNY_000:
                    BeamBunnyGUIDs[0] = creature->GetGUID();
                    break;
                case NPC_SHAMAN_BEAM_BUNNY_001:
                    BeamBunnyGUIDs[1] = creature->GetGUID();
                    break;
                case NPC_SHAMAN_BEAM_BUNNY_002:
                    BeamBunnyGUIDs[2] = creature->GetGUID();
                    break;
                case NPC_LUMA_SKYMOTHER:
                    LumaGUID = creature->GetGUID();
                    break;
                case NPC_EARTHEN_RING_FLAMECALLER:
                    SetGuidData(counter, creature->GetGUID());
                    ++counter;
                    break;
                default:
                    break;
            }
        }

        void SetGuidData(uint32 data, ObjectGuid guid) override
        {
            switch (data)
            {
                case DATA_FLAMECALLER_000:
                    FlameCallerGUIDs[0] = guid;
                    break;
                case DATA_FLAMECALLER_001:
                    FlameCallerGUIDs[1] = guid;
                    break;
                case DATA_FLAMECALLER_002:
                    FlameCallerGUIDs[2] = guid;
                    break;
                default:
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_AHUNE:
                    return AhuneGUID;
                case DATA_AHUNE_BUNNY:
                    return AhuneBunnyGUID;
                case DATA_FROZEN_CORE:
                    return FrozenCoreGUID;
                case DATA_FLAMECALLER_000:
                    return FlameCallerGUIDs[0];
                case DATA_FLAMECALLER_001:
                    return FlameCallerGUIDs[1];
                case DATA_FLAMECALLER_002:
                    return FlameCallerGUIDs[2];
                case DATA_BONFIRE_BUNNY_000:
                    return BonfireBunnyGUIDs[0];
                case DATA_BONFIRE_BUNNY_001:
                    return BonfireBunnyGUIDs[1];
                case DATA_BONFIRE_BUNNY_002:
                    return BonfireBunnyGUIDs[2];
                case DATA_BEAM_BUNNY_000:
                    return BeamBunnyGUIDs[0];
                case DATA_BEAM_BUNNY_001:
                    return BeamBunnyGUIDs[1];
                case DATA_BEAM_BUNNY_002:
                    return BeamBunnyGUIDs[2];
                case DATA_LUMA_SKYMOTHER:
                    return LumaGUID;
                default:
                    break;
            }
            return ObjectGuid::Empty;
        }

    protected:
        ObjectGuid AhuneGUID;
        ObjectGuid AhuneBunnyGUID;
        ObjectGuid FrozenCoreGUID;
        ObjectGuid LumaGUID;
        ObjectGuid FlameCallerGUIDs[3];
        ObjectGuid BonfireBunnyGUIDs[3];
        ObjectGuid BeamBunnyGUIDs[3];
        uint8 counter;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_the_slave_pens_InstanceMapScript(map);
    }
};

void AddSC_instance_the_slave_pens()
{
    new instance_the_slave_pens();
}
