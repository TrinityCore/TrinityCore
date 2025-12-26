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

#include "Creature.h"
#include "InstanceScript.h"
#include "ScriptMgr.h"
#include "ecodome_aldani.h"

ObjectData const creatureData[] =
{
    { BOSS_AZHICCAR,    DATA_AZHICCAR    },
    { BOSS_TAAHBAT,     DATA_TAAHBAT     },
    { BOSS_AWAZJ,       DATA_AWAZJ       },
    { BOSS_SOUL_SCRIBE, DATA_SOUL_SCRIBE },
    { 0,                0                }  // END
};

DungeonEncounterData const encounters[] =
{
    { DATA_AZHICCAR,          {{ 3107 }} },
    { DATA_TAAHBAT_AND_AWAZJ, {{ 3108 }} },
    { DATA_SOUL_SCRIBE,       {{ 3109 }} }
};

class instance_ecodome_aldani : public InstanceMapScript
{
public:
    instance_ecodome_aldani() : InstanceMapScript(EAScriptName, 2830) { }

    struct instance_ecodome_aldani_InstanceMapScript: public InstanceScript
    {
        instance_ecodome_aldani_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
            LoadDungeonEncounterData(encounters);

            _azhiccarIntroState = NOT_STARTED;
        }

        uint32 GetData(uint32 dataId) const override
        {
            switch (dataId)
            {
                case DATA_AZHICCAR_INTRO:
                    return _azhiccarIntroState;
                default:
                    break;
            }
            return 0;
        }

        void SetData(uint32 dataId, uint32 value) override
        {
            switch (dataId)
            {
                case DATA_AZHICCAR_INTRO:
                    _azhiccarIntroState = value;
                    break;
                default:
                    break;
            }
        }

    private:
        uint8 _azhiccarIntroState;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_ecodome_aldani_InstanceMapScript(map);
    }
};

void AddSC_instance_ecodome_aldani()
{
    new instance_ecodome_aldani();
}
