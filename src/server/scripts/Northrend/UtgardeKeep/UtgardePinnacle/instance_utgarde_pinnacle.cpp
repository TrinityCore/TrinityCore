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
#include "AreaBoundary.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "utgarde_pinnacle.h"

BossBoundaryData const boundaries =
{
    { DATA_KING_YMIRON, new RectangleBoundary(340.0f, 443.0f, -412.0f, -275.0f) }
};

DoorData const doorData[] =
{
    { GO_SKADI_THE_RUTHLESS_DOOR,   DATA_SKADI_THE_RUTHLESS,    DOOR_TYPE_PASSAGE },
    { GO_KING_YMIRON_DOOR,          DATA_KING_YMIRON,           DOOR_TYPE_PASSAGE },
    { 0,                            0,                          DOOR_TYPE_ROOM    } // END
};

ObjectData const creatureData[] =
{
    { NPC_SVALA_SORROWGRAVE,        DATA_SVALA_SORROWGRAVE      },
    { NPC_GORTOK_PALEHOOF,          DATA_GORTOK_PALEHOOF        },
    { NPC_SKADI_THE_RUTHLESS,       DATA_SKADI_THE_RUTHLESS     },
    { NPC_KING_YMIRON,              DATA_KING_YMIRON            },
    { NPC_FRENZIED_WORGEN,          DATA_FRENZIED_WORGEN        },
    { NPC_RAVENOUS_FURBOLG,         DATA_RAVENOUS_FURBOLG       },
    { NPC_MASSIVE_JORMUNGAR,        DATA_MASSIVE_JORMUNGAR      },
    { NPC_FEROCIOUS_RHINO,          DATA_FEROCIOUS_RHINO        },
    { NPC_PALEHOOF_ORB,             DATA_GORTOK_ORB             },
    { NPC_SVALA,                    DATA_SVALA                  },
    { NPC_GRAUF,                    DATA_GRAUF                  },
    { 0,                            0                           } // END
};

ObjectData const gameObjectData[] =
{
    { GO_UTGARDE_MIRROR,            DATA_UTGARDE_MIRROR         },
    { GO_GORTOK_PALEHOOF_SPHERE,    DATA_GORTOK_PALEHOOF_SPHERE },
    { 0,                            0                           } //END
};

class instance_utgarde_pinnacle : public InstanceMapScript
{
    public:
        instance_utgarde_pinnacle() : InstanceMapScript(UPScriptName, 575) { }

        struct instance_utgarde_pinnacle_InstanceMapScript : public InstanceScript
        {
            instance_utgarde_pinnacle_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadBossBoundaries(boundaries);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                if (go->GetEntry() == GO_GORTOK_PALEHOOF_SPHERE)
                    if (GetBossState(DATA_GORTOK_PALEHOOF) == DONE)
                        go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            }

            void SetGuidData(uint32 type, ObjectGuid data) override
            {
                if (type == DATA_SACRIFICED_PLAYER)
                    SacrificedPlayerGUID = data;

                InstanceScript::SetGuidData(type, data);
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                if (type == DATA_SACRIFICED_PLAYER)
                    return SacrificedPlayerGUID;

                return InstanceScript::GetGuidData(type);
            }

        protected:
            ObjectGuid SacrificedPlayerGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_utgarde_pinnacle_InstanceMapScript(map);
        }
};

void AddSC_instance_utgarde_pinnacle()
{
    new instance_utgarde_pinnacle();
}
