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

#include "AreaBoundary.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "black_rook_hold.h"

BossBoundaryData const boundaries =
{
    { DATA_AMALGAM_OF_SOULS, new CircleBoundary(Position(3251.350098f, 7582.790039f), 40.0f) }
};

ObjectData const creatureData[] =
{
    { BOSS_AMALGAM_OF_SOULS,         DATA_AMALGAM_OF_SOULS         },
    { BOSS_ILLYSANNA_RAVENCREST,     DATA_ILLYSANNA_RAVENCREST     },
    { BOSS_SMASHPITE_THE_HATEFUL,    DATA_SMASHPITE_THE_HATEFUL    },
    { BOSS_LORD_KURTALOS_RAVENCREST, DATA_LORD_KURTALOS_RAVENCREST },
    { 0,                             0                             }  // END
};

ObjectData const gameobjectData[] =
{
    { GO_BOSS_1_POST_BOSS_DOOR, DATA_BOSS_1_POST_BOSS_DOOR   },
    { 0,                        0                            } // END
};

DoorData const doorData[] =
{
    { GO_BOSS_1_DOOR_1, DATA_AMALGAM_OF_SOULS, EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_BOSS_1_DOOR_2, DATA_AMALGAM_OF_SOULS, EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_BOSS_1_DOOR_3, DATA_AMALGAM_OF_SOULS, EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_BOSS_1_DOOR_4, DATA_AMALGAM_OF_SOULS, EncounterDoorBehavior::OpenWhenNotInProgress },
    { 0,                0,                     EncounterDoorBehavior::OpenWhenNotInProgress }
};

DungeonEncounterData const encounters[] =
{
    { DATA_AMALGAM_OF_SOULS,         {{ 1832 }} },
    { DATA_ILLYSANNA_RAVENCREST,     {{ 1833 }} },
    { DATA_SMASHPITE_THE_HATEFUL,    {{ 1834 }} },
    { DATA_LORD_KURTALOS_RAVENCREST, {{ 1835 }} },
};

class instance_black_rook_hold : public InstanceMapScript
{
    public:
        instance_black_rook_hold() : InstanceMapScript(BRHScriptName, 1501) { }

        struct instance_black_rook_hold_InstanceMapScript: public InstanceScript
        {
            instance_black_rook_hold_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameobjectData);
                LoadDoorData(doorData);
                LoadBossBoundaries(boundaries);
                LoadDungeonEncounterData(encounters);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_black_rook_hold_InstanceMapScript(map);
        }
};

void AddSC_instance_black_rook_hold()
{
    new instance_black_rook_hold();
}
