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
#include "Creature.h"
#include "InstanceScript.h"
#include "temple_of_ahnqiraj.h"

#include <array>

ObjectData const creatureData[] =
{
    { BOSS_VEM,         DATA_VEM            },
    { BOSS_KRI,         DATA_KRI            },
    { BOSS_VEKLOR,      DATA_VEKLOR         },
    { BOSS_VEKNILASH,   DATA_VEKNILASH      },
    { BOSS_VISCIDUS,    DATA_VISCIDUS       },
    { BOSS_SARTURA,     DATA_SARTURA        },
    { BOSS_OURO,        DATA_OURO           },
    { 0,                0                   } // END
};

DoorData const doorData[] =
{
    { AQ40_DOOR_1, DATA_SARTURA,       DOOR_TYPE_PASSAGE },
    { AQ40_DOOR_1, DATA_HUHURAN,       DOOR_TYPE_PASSAGE },
    { AQ40_DOOR_2, DATA_TWIN_EMPERORS, DOOR_TYPE_PASSAGE },
    { AQ40_DOOR_3, DATA_SKERAM,        DOOR_TYPE_PASSAGE },
    { 0,           0,                  DOOR_TYPE_ROOM    } // END
};

constexpr uint8 const BUG_TRIO_COUNT = 3;

class instance_temple_of_ahnqiraj : public InstanceMapScript
{
    public:
        instance_temple_of_ahnqiraj() : InstanceMapScript(AQ40ScriptName, 531) { }

        struct instance_temple_of_ahnqiraj_InstanceMapScript : public InstanceScript
        {
            instance_temple_of_ahnqiraj_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                LoadObjectData(creatureData, nullptr);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);

                _bugTrioMemberDead.fill(false);
                _bugTrioDeathCount = 0;
                _cthunPhase = 0;
            }

            bool IsEncounterInProgress() const override
            {
                //not active in AQ40
                return false;
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_VEMISDEAD:
                        return uint8(_bugTrioMemberDead[0]);
                    case DATA_VEKLORISDEAD:
                        return uint8(_bugTrioMemberDead[1]);
                    case DATA_VEKNILASHISDEAD:
                        return uint8(_bugTrioMemberDead[2]);
                    case DATA_BUG_TRIO_DEATH:
                        return _bugTrioDeathCount;
                    case DATA_CTHUN_PHASE:
                        return _cthunPhase;
                    default:
                        return 0;
                }
                return 0;
            }


            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                     case DATA_VEM_DEATH:
                         _bugTrioMemberDead[0] = true;
                         break;
                     case DATA_BUG_TRIO_DEATH:
                         ++_bugTrioDeathCount;
                         break;
                     case DATA_VEKLOR_DEATH:
                         _bugTrioMemberDead[1] = true;
                         break;
                     case DATA_VEKNILASH_DEATH:
                         _bugTrioMemberDead[2] = true;
                         break;
                     case DATA_CTHUN_PHASE:
                         _cthunPhase = data;
                         break;
                     default:
                         break;
                }
            }
            private:
                //If Vem is dead...
                std::array<bool, BUG_TRIO_COUNT> _bugTrioMemberDead;
                uint8 _bugTrioDeathCount;
                uint8 _cthunPhase;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_temple_of_ahnqiraj_InstanceMapScript(map);
        }
};

void AddSC_instance_temple_of_ahnqiraj()
{
    new instance_temple_of_ahnqiraj();
}
