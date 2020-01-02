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

#include "scarlet_monastery.h"
#include "Creature.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "ScriptMgr.h"

ObjectData const creatureData[] =
{
    { NPC_HEAD,      DATA_HEAD      },
    { NPC_HORSEMAN,  DATA_HORSEMAN  },
    { NPC_MOGRAINE,  DATA_MOGRAINE  },
    { NPC_VORREL,    DATA_VORREL    },
    { NPC_WHITEMANE, DATA_WHITEMANE },
    { 0,             0              } // END
};

ObjectData const gameObjectData[] =
{
    { GO_PUMPKIN_SHRINE,        DATA_PUMPKIN_SHRINE        },
    { GO_HIGH_INQUISITORS_DOOR, DATA_HIGH_INQUISITORS_DOOR },
    { 0,                        0                          } // END
};

class instance_scarlet_monastery : public InstanceMapScript
{
    public:
        instance_scarlet_monastery() : InstanceMapScript(SMScriptName, 189) { }

        struct instance_scarlet_monastery_InstanceMapScript : public InstanceScript
        {
            instance_scarlet_monastery_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_PUMPKIN:
                        HorsemanAdds.insert(creature->GetGUID());
                        break;
                    default:
                        break;
                }

                InstanceScript::OnCreatureCreate(creature);
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_HORSEMAN_EVENT:
                        if (state == DONE || state == FAIL || state == NOT_STARTED)
                        {
                            for (ObjectGuid const& guid : HorsemanAdds)
                            {
                                Creature* add = instance->GetCreature(guid);
                                if (add)
                                    add->DespawnOrUnsummon();
                            }
                            HorsemanAdds.clear();

                            if (state == DONE)
                                HandleGameObject(ObjectGuid::Empty, false, GetGameObject(DATA_PUMPKIN_SHRINE));
                        }
                        break;
                    default:
                        break;
                }
                return true;
            }

        protected:
            GuidUnorderedSet HorsemanAdds;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_scarlet_monastery_InstanceMapScript(map);
        }
};

void AddSC_instance_scarlet_monastery()
{
    new instance_scarlet_monastery();
}
