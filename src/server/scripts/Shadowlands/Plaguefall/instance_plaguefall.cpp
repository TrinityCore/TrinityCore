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
#include "plaguefall.h"

BossBoundaryData const boundaries =
{
    { DATA_GLOBGROG, new CircleBoundary(Position(2021.948120f, -3556.348848), 83.0f) }
};

ObjectData const creatureData[] =
{
    { BOSS_GLOBGROG,          DATA_GLOBGROG          },
    { BOSS_DOCTOR_ICKUS,      DATA_DOCTOR_ICKUS      },
    { BOSS_DOMINA_VENOMBLADE, DATA_DOMINA_VENOMBLADE },
    { BOSS_MARGRAVE_STRADAMA, DATA_MARGRAVE_STRADAMA },
    { 0,                      0                      }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_GLOBGROG,          {{ 2382 }} },
    { DATA_DOCTOR_ICKUS,      {{ 2384 }} },
    { DATA_DOMINA_VENOMBLADE, {{ 2385 }} },
    { DATA_MARGRAVE_STRADAMA, {{ 2386 }} }
};

class instance_plaguefall : public InstanceMapScript
{
    public:
        instance_plaguefall() : InstanceMapScript(PFScriptName, 2289) { }

        struct instance_plaguefall_InstanceMapScript: public InstanceScript
        {
            instance_plaguefall_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, nullptr);
                LoadDungeonEncounterData(encounters);
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_plaguefall_InstanceMapScript(map);
        }
};

void AddSC_instance_plaguefall()
{
    new instance_plaguefall();
}
