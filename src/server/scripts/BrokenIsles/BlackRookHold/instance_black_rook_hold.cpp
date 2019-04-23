/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 *  ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "ObjectAccessor.h"
#include "black_rook_hold.h"

DoorData const doorData[] =
{
    { GOB_DOOR_AMALGAME_ENTER_1,        DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_ROOM      },
    { GOB_DOOR_AMALGAME_ENTER_2,        DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_ROOM      },
    { GOB_DOOR_AMALGAME_ROOM_1,         DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_ROOM      },
    { GOB_DOOR_AMALGAME_ROOM_2,         DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_ROOM      },
    { GOB_DOOR_AMALGAME_ROOM_3,         DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_ROOM      },
    { GOB_DOOR_AMALGAME_ROOM_4,         DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_ROOM      },
    { GOB_DOOR_AMALGAME_EXIT,           DATA_AMALGAM_OF_SOULS,      DOOR_TYPE_PASSAGE   },
    { GOB_DOOR_ILLYSANNA_PORTCULLIS_1,  DATA_ILLYSANNA_RAVENCREST,  DOOR_TYPE_PASSAGE   },
    { GOB_DOOR_ILLYSANNA_PORTCULLIS_2,  DATA_ILLYSANNA_RAVENCREST,  DOOR_TYPE_PASSAGE   },
    { GOB_DOOR_ILLYSANNA_ENTER,         DATA_ILLYSANNA_RAVENCREST,  DOOR_TYPE_ROOM      },
    { GOB_DOOR_ILLYSANNA_EXIT_1,        DATA_ILLYSANNA_RAVENCREST,  DOOR_TYPE_PASSAGE   },
    { GOB_DOOR_ILLYSANNA_EXIT_2,        DATA_ILLYSANNA_RAVENCREST,  DOOR_TYPE_PASSAGE   },
    { GOB_DOOR_SMASHSPITE_ROOM,         DATA_SMASHSPITE,            DOOR_TYPE_ROOM      },
    { GOB_DOOR_RAVENCREST_PASSAGE,      DATA_SMASHSPITE,            DOOR_TYPE_PASSAGE   },
    { GOB_DOOR_RAVENCREST_ROOM,         DATA_LORD_RAVENCREST,       DOOR_TYPE_ROOM      },
};

struct instance_black_rook_hold : public InstanceScript
{
    instance_black_rook_hold(InstanceMap* map) : InstanceScript(map) { }

    void Initialize() override
    {
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        LoadDoorData(doorData);

        events.ScheduleEvent(DATA_STAIRS_BOULDER_1, 3s);

        SetData(DATA_ILLYSANNA_PREEVENT_LOWER, NOT_STARTED);
        SetData(DATA_ILLYSANNA_PREEVENT_UPPER, NOT_STARTED);

        SetChallengeDoorPos({ 3468.448242f, 7631.900391f, -9.821134f, 4.351523f });
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);

        if (instance->IsHeroic())
            creature->SetBaseHealth(creature->GetMaxHealth() * 2.f);
        if (instance->IsMythic())
            creature->SetBaseHealth(creature->GetMaxHealth() * 1.33f);

        if (creature->isDead())
            return;

        switch (creature->GetEntry())
        {
            case NPC_SOUL_TORN_CHAMPION:
            case NPC_RISEN_SCOUT:
            case NPC_RISEN_ARCHER:
            case NPC_RISEN_ARCANIST_PREEVENT:
            {
                if (creature->GetPositionZ() < 90.f)
                    m_illysannaPreEventLowerMobs.push_back(creature->GetGUID());
                else if (creature->GetPositionZ() > 100.f)
                {
                    creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
                    m_illysannaPreEventUpperMobs.push_back(creature->GetGUID());
                }

                break;
            }
            case NPC_COMMANDER_SHEMDAHSOHN:
            {
                m_illysannaPreEventUpperMobs.push_back(creature->GetGUID());
                break;
            }
        }
    }

    void OnUnitDeath(Unit* unit) override
    {
        if (!unit->IsCreature())
            return;

        if (GetData(DATA_ILLYSANNA_PREEVENT_LOWER) == NOT_STARTED)
        {
            m_illysannaPreEventLowerMobs.remove(unit->GetGUID());

            if (m_illysannaPreEventLowerMobs.size() == 0)
            {
                SetData(DATA_ILLYSANNA_PREEVENT_LOWER, DONE);

                for (ObjectGuid guid : m_illysannaPreEventUpperMobs)
                {
                    if (Creature* creature = ObjectAccessor::GetCreature(*unit, guid))
                    {
                        Position jumpPos = creature->GetPosition();
                        GetPositionWithDistInFront(creature, 15.f, jumpPos);
                        jumpPos.m_positionZ = 86.412155f;

                        creature->GetMotionMaster()->MoveJump(jumpPos, 10.f, 10.f);

                        creature->GetScheduler().Schedule(3s, [](TaskContext context)
                        {
                            if (Player* player = GetContextCreature()->SelectNearestPlayer())
                            {
                                GetContextCreature()->GetMotionMaster()->MoveChase(player);
                                GetContextCreature()->Attack(player, true);
                            }

                            GetContextCreature()->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_IMMUNE_TO_NPC | UNIT_FLAG_IMMUNE_TO_PC);
                        });
                    }
                }
            }
        }

        if (unit->GetEntry() == NPC_COMMANDER_SHEMDAHSOHN)
        {
            HandleGameObject(GetObjectGuid(GOB_DOOR_ILLYSANNA_PORTCULLIS_1), true);
            HandleGameObject(GetObjectGuid(GOB_DOOR_ILLYSANNA_PORTCULLIS_2), true);
            SetData(DATA_ILLYSANNA_PREEVENT_UPPER, DONE);
        }
    }

    void Update(uint32 diff) override
    {
        events.Update(diff);

        switch (events.ExecuteEvent())
        {
            case DATA_STAIRS_BOULDER_1:
            {
                if (HasPlayerUpperThan(125.f))
                {
                    events.CancelEvent(DATA_STAIRS_BOULDER_1);
                    events.ScheduleEvent(DATA_STAIRS_BOULDER_2, 3s);
                    break;
                }

                uint8 boulderSide = urand(0, 1);
                if (Creature* boulder = instance->SummonCreature(NPC_BOULDER, firstBoulderPositions[boulderSide][0]))
                    boulder->GetMotionMaster()->MoveSmoothPath(1, firstBoulderPositions[boulderSide], FIRST_BOULDER_PATH_SIZE);
                events.Repeat(4s);
                break;
            }
            case DATA_STAIRS_BOULDER_2:
            {
                if (HasPlayerUpperThan(190.f))
                {
                    events.CancelEvent(DATA_STAIRS_BOULDER_2);
                    break;
                }

                uint8 boulderSide = urand(0, 1);
                if (Creature* boulder = instance->SummonCreature(NPC_BOULDER, secondBoulderPositions[boulderSide][0]))
                    boulder->GetMotionMaster()->MoveSmoothPath(2, secondBoulderPositions[boulderSide], SECOND_BOULDER_PATH_SIZE);
                events.Repeat(5s);
                break;
            }
        }
    }

private:
    bool HasPlayerUpperThan(float minZ)
    {
        Map::PlayerList const& players = instance->GetPlayers();
        for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
            if (itr->GetSource() && itr->GetSource()->GetPositionZ() >= minZ)
                return true;

        return false;
    }

    EventMap events;
    std::list<ObjectGuid> m_illysannaPreEventLowerMobs;
    std::list<ObjectGuid> m_illysannaPreEventUpperMobs;
};

void AddSC_instance_black_rook_hold()
{
    RegisterInstanceScript(instance_black_rook_hold, 1501);
}
