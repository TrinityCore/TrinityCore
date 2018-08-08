/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "throne_of_the_tides.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Vehicle.h"
#include "MoveSpline.h"

ObjectData const creatureData[] =
{
    { BOSS_LADY_NAZJAR,         DATA_LADY_NAZJAR            },
    { BOSS_COMMANDER_ULTHOK,    DATA_COMMANDER_ULTHOK       },
    { BOSS_MINDBENDER_GURSHA,   DATA_MINDBENDER_GURSHA      },
    { BOSS_OZUMAT,              DATA_OZUMAT                 },
    { NPC_LADY_NAZJAR,          DATA_LADY_NAZJAR_GAUNTLET   },
    { 0,                        0                           } // END
};

ObjectData const gameobjectData[] =
{
    { GO_DOODAD_ABYSSAL_MAW_DOOR_1,     DATA_ABYSSAL_MAW_DOOR_1 },
    { 0,                                0                       } // END
};

DoorData const doorData[] =
{
    { GO_DOODAD_ABYSSAL_MAW_DOOR_1,     DATA_COMMANDER_ULTHOK,   DOOR_TYPE_PASSAGE   },
    { GO_DOODAD_ABYSSAL_MAW_DOOR_2,     DATA_LADY_NAZJAR,        DOOR_TYPE_ROOM      },
    { GO_DOODAD_ABYSSAL_MAW_DOOR_2,     DATA_COMMANDER_ULTHOK,   DOOR_TYPE_ROOM      },
    { 0,                                0,                       DOOR_TYPE_ROOM      } // END
};

enum Events
{
    EVENT_FALLING_ROCKS = 1
};

Position const fallingRocksDummyPos = { -144.283f, 983.316f, 230.4773f };

Position const ladyNazjarGauntletPos = { -20.19097f, 802.0608f, 807.5371f, 3.141593f };

class FaceDirectionEvent : public BasicEvent
{
    public:
        FaceDirectionEvent(Creature* owner, float facingAngle) :  _owner(owner), _facingAngle(facingAngle) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->RemoveAurasDueToSpell(SPELL_WATER_JUMP_THROUGH_WINDOW_VISUAL);
            _owner->SetDisableGravity(false);
            _owner->SendSetPlayHoverAnim(false);
            _owner->SetMovementAnimKitId(0);
            _owner->SetFacingTo(_facingAngle);
            _owner->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
            _owner->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_READY2HL);
            _owner->SetReactState(REACT_AGGRESSIVE);
            return true;
        }

    private:
        Creature* _owner;
        float _facingAngle;
};


class JumpThroughWindowEvent : public BasicEvent
{
    public:
        JumpThroughWindowEvent(Creature* owner, Position const jumpPos) :  _owner(owner), _jumpPos(jumpPos) { }

        bool Execute(uint64 /*time*/, uint32 /*diff*/) override
        {
            _owner->CastSpell(_owner, SPELL_WATER_JUMP_THROUGH_WINDOW_VISUAL, true);
            _owner->GetMotionMaster()->MoveJump(_jumpPos, 16.0f, 10.0f);
            _owner->SetHomePosition(_jumpPos);
            if (int32 travelTime = _owner->movespline->Duration())
                _owner->m_Events.AddEvent(new FaceDirectionEvent(_owner, _jumpPos.GetOrientation()), _owner->m_Events.CalculateTime(travelTime));
            return true;
        }

    private:
        Creature* _owner;
        Position const _jumpPos;
};

class instance_throne_of_the_tides : public InstanceMapScript
{
    public:
        instance_throne_of_the_tides(): InstanceMapScript(TotTScriptName, 643) {  }

        struct instance_throne_of_the_tides_InstanceMapScript : public InstanceScript
        {
            instance_throne_of_the_tides_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                Initialize();
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameobjectData);
                LoadDoorData(doorData);
            }

            void Initialize()
            {
                _eventIndex = EVENT_INDEX_NONE;
                _fallingRocksDummyGUID = ObjectGuid::Empty;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                return true;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case BOSS_OZUMAT:
                    case NPC_OZUMAT:
                    case NPC_OZUMAT_VEHICLE:
                    case NPC_OZUMAT_VEHICLE_BIG:
                    case NPC_LADY_NAZJAR:
                        creature->setActive(true);
                        creature->SetFarVisible(true);
                        break;
                    case NPC_WORLD_TRIGGER_INFINITE_AOI:
                        creature->setActive(true);
                        creature->SetFarVisible(true);

                        if (creature->GetExactDist2d(fallingRocksDummyPos) < 1.0f)
                        {
                            _fallingRocksDummyGUID = creature->GetGUID();
                            if (_eventIndex < EVENT_INDEX_DEFENSE_SYSTEM_ACTIVATED)
                                events.ScheduleEvent(EVENT_FALLING_ROCKS, 1min + 15s);
                        }
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_TEMP_FALLING_ROCKS:
                        go->SendCustomAnim(0);
                        break;
                    case GO_DOODAD_ABYSSAL_MAW_DOOR_1:
                        if (_eventIndex == EVENT_INDEX_LADY_NAZJAR_GAUNTLET)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_CURRENT_EVENT_PROGRESS:
                        return _eventIndex;
                }
                return 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_CURRENT_EVENT_PROGRESS:
                        _eventIndex = data;

                        switch (data)
                        {
                            case EVENT_INDEX_FIRST_INVADERS:
                                for (uint8 i = 0; i < 4; i++)
                                {
                                    if (Creature* invader = instance->SummonCreature(i < 2 ? NPC_NAZJAR_SPIRITMENDER_1 : NPC_NAZJAR_INVADER_1, TotTFirstInvaderPositions[i]))
                                    {
                                        invader->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                                        invader->SetDisableGravity(true);
                                        invader->SendSetPlayHoverAnim(true);
                                        invader->SetMovementAnimKitId(3);
                                        invader->SetReactState(REACT_PASSIVE);
                                        invader->GetMotionMaster()->MovePoint(0, TotTFirstInvaderInitialMovePositions[i], false);
                                        if (int32 travelTime = invader->movespline->Duration() + 200)
                                            invader->m_Events.AddEvent(new JumpThroughWindowEvent(invader, TotTFirstInvaderJumpPositions[i]), invader->m_Events.CalculateTime(travelTime));
                                    }
                                }
                                break;
                            case EVENT_INDEX_LADY_NAZJAR_GAUNTLET:
                                instance->SummonCreature(NPC_LADY_NAZJAR, ladyNazjarGauntletPos);
                                for (uint8 i = 0; i < 6; i++)
                                {
                                    if (Creature* invader = instance->SummonCreature(i < 3 ? NPC_NAZJAR_SPIRITMENDER_2 : NPC_NAZJAR_INVADER_2, TotTLadyNazjarInvaderPositions[i]))
                                    {
                                        invader->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC);
                                        invader->SetDisableGravity(true);
                                        invader->SendSetPlayHoverAnim(true);
                                        invader->SetMovementAnimKitId(3);
                                        invader->SetReactState(REACT_PASSIVE);
                                        invader->GetMotionMaster()->MovePoint(0, TotTLadyNazjarInvaderInitialMovePositions[i], false);
                                        if (int32 travelTime = invader->movespline->Duration() + 200)
                                            invader->m_Events.AddEvent(new JumpThroughWindowEvent(invader, TotTLadyNazjarInvaderJumpPositions[i]), invader->m_Events.CalculateTime(travelTime));
                                    }
                                }
                                break;
                            case EVENT_INDEX_DEFENSE_SYSTEM_ACTIVATED:
                                events.CancelEvent(EVENT_FALLING_ROCKS);
                                break;
                            default:
                                break;
                        }

                        SaveToDB();
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* who) override
            {
                if (who->GetTypeId() != TYPEID_UNIT)
                    return;

                if (who->GetEntry() == NPC_NAZJAR_INVADER_2 || who->GetEntry() == NPC_NAZJAR_SPIRITMENDER_2)
                    if (Creature* nazjar = GetCreature(DATA_LADY_NAZJAR_GAUNTLET))
                        nazjar->AI()->SummonedCreatureDies(who->ToCreature(), nullptr);
            }

            void Update(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_FALLING_ROCKS:
                            if (Creature* fallingRocksDummy = instance->GetCreature(_fallingRocksDummyGUID))
                                fallingRocksDummy->CastSpell(fallingRocksDummy, SPELL_SUMMON_FALLING_ROCKS, true);
                            events.Repeat(1min + 25s, 2min);
                            break;
                        default:
                            break;
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _eventIndex;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _eventIndex;
            }

        private:
            EventMap events;
            uint8 _eventIndex;
            ObjectGuid _fallingRocksDummyGUID;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_throne_of_the_tides_InstanceMapScript(map);
        }
};

void AddSC_instance_throne_of_the_tides()
{
    new instance_throne_of_the_tides();
}
