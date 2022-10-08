/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "GameObject.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "the_underrot.h"

BossBoundaryData const boundaries =
{
    { DATA_ELDER_LEAXA,             new ZRangeBoundary(44.181206f, 63.479584f)                                  },
    { DATA_CRAGMAW_THE_INFESTED,    new CircleBoundary(Position(862.497009f, 982.315979f, 39.231701f), 90.f)    },
    { DATA_SPORECALLER_ZANCHA,      new ZRangeBoundary(20.f, 40.f)                                              },
    { DATA_UNBOUND_ABOMINATION,     new ZRangeBoundary(-200.f, -150.f)                                          },
};

struct instance_the_underrot : public InstanceScript
{
    instance_the_underrot(InstanceMap* map) : InstanceScript(map)
    {
        SetHeaders(DataHeader);
        SetBossNumber(EncounterCount);
        LoadBossBoundaries(boundaries);

        instance->SummonCreatureGroup(SUMMON_GROUP_BLOODSWORN_DEFILER);
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);

        switch (creature->GetEntry())
        {
            case NPC_TITAN_KEEPER_HEZREL:
            {
                if (creature->GetPositionZ() < -100.f)
                    AddObject(creature, DATA_BOSS_HERZEL, true);
                else
                    AddObject(creature, DATA_EVENT_HERZEL, true);

                break;
            }
            default:
                break;
        }
    }

    void SetData(uint32 type, uint32 data) override
    {
        switch (type)
        {
            case DATA_EVENT_HERZEL:
            {
                if (data == DONE)
                {
                    if (GameObject* web = GetGameObject(GOB_PYRAMID_WEB))
                        web->RemoveFromWorld();
                    HandleGameObject(ObjectGuid::Empty, true, GetGameObject(GOB_PYRAMID_DOOR));
                }
                break;
            }
            case DATA_FACELESS_CORRUPTOR_1:
            {
                if (Creature* hezrel = GetCreature(DATA_EVENT_HERZEL))
                    hezrel->AI()->SetData(DATA_EVENT_HERZEL, 1);

                break;
            }
            case DATA_FACELESS_CORRUPTOR_2:
            {
                if (GetData(DATA_FACELESS_CORRUPTOR_2) > 0)
                    if (Creature* hezrel = GetCreature(DATA_EVENT_HERZEL))
                        hezrel->AI()->SetData(DATA_EVENT_HERZEL, 2);

                break;
            }
        }

        InstanceScript::SetData(type, data);
    }
};

void AddSC_instance_underrot()
{
    RegisterInstanceScript(instance_the_underrot, 1841);
}
