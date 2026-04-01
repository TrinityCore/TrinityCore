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
#include "maisara_caverns.h"

BossBoundaryData const boundaries =
{
    { DATA_MUROJIN_AND_NEKRAXX, new ZRangeBoundary(99.50f, 103.0f) }
};

static constexpr ObjectData creatureData[] =
{
    { BOSS_MUROJIN,                DATA_MUROJIN                },
    { BOSS_NEKRAXX,                DATA_NEKRAXX                },
    { BOSS_VORDAZA,                DATA_VORDAZA                },
    { BOSS_RAKTUL_VESSEL_OF_SOULS, DATA_RAKTUL_VESSEL_OF_SOULS }
};

static constexpr DungeonEncounterData const encounters[] =
{
    { DATA_MUROJIN_AND_NEKRAXX,    {{ 3212 }} },
    { DATA_VORDAZA,                {{ 3213 }} },
    { DATA_RAKTUL_VESSEL_OF_SOULS, {{ 3214 }} }
};

static constexpr DoorData doorData[] =
{
    { GO_MAISARA_BOSS_1_GATE, DATA_MUROJIN_AND_NEKRAXX, EncounterDoorBehavior::OpenWhenDone }
};

class instance_maisara_caverns : public InstanceMapScript
{
public:
    instance_maisara_caverns() : InstanceMapScript(MCScriptName, 2874) { }

    struct instance_maisara_caverns_InstanceMapScript: public InstanceScript
    {
        instance_maisara_caverns_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, {});
            LoadBossBoundaries(boundaries);
            LoadDoorData(doorData);
            LoadDungeonEncounterData(encounters);

            _murojinAndNekraxxIntroState = NOT_STARTED;
        }

        uint32 GetData(uint32 dataId) const override
        {
            switch (dataId)
            {
                case DATA_MUROJIN_AND_NEKRAXX_INTRO_STATE:
                    return _murojinAndNekraxxIntroState;
                default:
                    break;
            }
            return 0;
        }

        void SetData(uint32 dataId, uint32 value) override
        {
            switch (dataId)
            {
                case DATA_MUROJIN_AND_NEKRAXX_INTRO_STATE:
                    _murojinAndNekraxxIntroState = value;
                    break;
                default:
                    break;
            }
        }

    private:
        uint8 _murojinAndNekraxxIntroState;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_maisara_caverns_InstanceMapScript(map);
    }
};

void AddSC_instance_maisara_caverns()
{
    new instance_maisara_caverns();
}
