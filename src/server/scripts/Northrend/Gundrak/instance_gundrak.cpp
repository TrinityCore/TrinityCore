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
#include "Creature.h"
#include "EventMap.h"
#include "GameObject.h"
#include "gundrak.h"
#include "InstanceScript.h"
#include "Map.h"

DoorData const doorData[] =
{
    { GO_GAL_DARAH_DOOR_1,              DATA_GAL_DARAH,         DOOR_TYPE_PASSAGE },
    { GO_GAL_DARAH_DOOR_2,              DATA_GAL_DARAH,         DOOR_TYPE_PASSAGE },
    { GO_GAL_DARAH_DOOR_3,              DATA_GAL_DARAH,         DOOR_TYPE_ROOM },
    { GO_ECK_THE_FEROCIOUS_DOOR,        DATA_MOORABI,           DOOR_TYPE_PASSAGE },
    { GO_ECK_THE_FEROCIOUS_DOOR_BEHIND, DATA_ECK_THE_FEROCIOUS, DOOR_TYPE_PASSAGE },
    { 0,                                0,                      DOOR_TYPE_ROOM } // END
};

ObjectData const creatureData[] =
{
    { NPC_DRAKKARI_COLOSSUS, DATA_DRAKKARI_COLOSSUS },
    { 0,                     0                      } // END
};

ObjectData const gameObjectData[] =
{
    { GO_SLAD_RAN_ALTAR,           DATA_SLAD_RAN_ALTAR           },
    { GO_MOORABI_ALTAR,            DATA_MOORABI_ALTAR            },
    { GO_DRAKKARI_COLOSSUS_ALTAR,  DATA_DRAKKARI_COLOSSUS_ALTAR  },
    { GO_SLAD_RAN_STATUE,          DATA_SLAD_RAN_STATUE          },
    { GO_MOORABI_STATUE,           DATA_MOORABI_STATUE           },
    { GO_DRAKKARI_COLOSSUS_STATUE, DATA_DRAKKARI_COLOSSUS_STATUE },
    { GO_GAL_DARAH_STATUE,         DATA_GAL_DARAH_STATUE         },
    { GO_TRAPDOOR,                 DATA_TRAPDOOR                 },
    { GO_COLLISION,                DATA_COLLISION                },
    { 0,                           0                             } // END
};

Position const EckSpawnPoint = { 1643.877930f, 936.278015f, 107.204948f, 0.668432f };

class instance_gundrak : public InstanceMapScript
{
    public:
        instance_gundrak() : InstanceMapScript(GundrakScriptName, 604) { }

        struct instance_gundrak_InstanceMapScript : public InstanceScript
        {
            instance_gundrak_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);

                SladRanStatueState = GO_STATE_ACTIVE;
                DrakkariColossusStatueState = GO_STATE_ACTIVE;
                MoorabiStatueState = GO_STATE_ACTIVE;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_RUIN_DWELLER:
                        if (creature->IsAlive())
                            DwellerGUIDs.insert(creature->GetGUID());
                        break;
                    default:
                        break;
                }

                InstanceScript::OnCreatureCreate(creature);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_SLAD_RAN_ALTAR:
                        if (GetBossState(DATA_SLAD_RAN) == DONE)
                        {
                            if (SladRanStatueState == GO_STATE_ACTIVE)
                                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            else
                                go->SetGoState(GO_STATE_ACTIVE);
                        }
                        break;
                    case GO_MOORABI_ALTAR:
                        if (GetBossState(DATA_MOORABI) == DONE)
                        {
                            if (MoorabiStatueState == GO_STATE_ACTIVE)
                                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            else
                                go->SetGoState(GO_STATE_ACTIVE);
                        }
                        break;
                    case GO_DRAKKARI_COLOSSUS_ALTAR:
                        if (GetBossState(DATA_DRAKKARI_COLOSSUS) == DONE)
                        {
                            if (DrakkariColossusStatueState == GO_STATE_ACTIVE)
                                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            else
                                go->SetGoState(GO_STATE_ACTIVE);
                        }
                        break;
                    case GO_SLAD_RAN_STATUE:
                        go->SetGoState(SladRanStatueState);
                        break;
                    case GO_MOORABI_STATUE:
                        go->SetGoState(MoorabiStatueState);
                        break;
                    case GO_GAL_DARAH_STATUE:
                        go->SetGoState(CheckRequiredBosses(DATA_GAL_DARAH) ? GO_STATE_ACTIVE_ALTERNATIVE : GO_STATE_READY);
                        break;
                    case GO_DRAKKARI_COLOSSUS_STATUE:
                        go->SetGoState(DrakkariColossusStatueState);
                        break;
                    case GO_ECK_THE_FEROCIOUS_DOOR:
                        // Don't store door on non-heroic
                        if (!instance->IsHeroic())
                            return;
                        break;
                    case GO_TRAPDOOR:
                        go->SetGoState(CheckRequiredBosses(DATA_GAL_DARAH) ? GO_STATE_READY : GO_STATE_ACTIVE);
                        break;
                    case GO_COLLISION:
                        go->SetGoState(CheckRequiredBosses(DATA_GAL_DARAH) ? GO_STATE_ACTIVE : GO_STATE_READY);
                        break;
                    default:
                        break;
                }

                InstanceScript::OnGameObjectCreate(go);
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (unit->GetEntry() == NPC_RUIN_DWELLER)
                {
                    DwellerGUIDs.erase(unit->GetGUID());

                    if (DwellerGUIDs.empty())
                        unit->SummonCreature(NPC_ECK_THE_FEROCIOUS, EckSpawnPoint, TEMPSUMMON_CORPSE_TIMED_DESPAWN, 300 * IN_MILLISECONDS);
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_SLAD_RAN:
                        if (state == DONE)
                            if (GameObject* go = GetGameObject(DATA_SLAD_RAN_ALTAR))
                                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case DATA_DRAKKARI_COLOSSUS:
                        if (state == DONE)
                            if (GameObject* go = GetGameObject(DATA_DRAKKARI_COLOSSUS_ALTAR))
                                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    case DATA_MOORABI:
                        if (state == DONE)
                            if (GameObject* go = GetGameObject(DATA_MOORABI_ALTAR))
                                go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                        break;
                    default:
                        break;
                }

                return true;
            }

            bool CheckRequiredBosses(uint32 bossId, Player const* player = nullptr) const override
            {
                if (_SkipCheckRequiredBosses(player))
                    return true;

                switch (bossId)
                {
                    case DATA_ECK_THE_FEROCIOUS:
                        if (!instance->IsHeroic() || GetBossState(DATA_MOORABI) != DONE)
                            return false;
                        break;
                    case DATA_GAL_DARAH:
                        if (SladRanStatueState != GO_STATE_ACTIVE_ALTERNATIVE
                            || DrakkariColossusStatueState != GO_STATE_ACTIVE_ALTERNATIVE
                            || MoorabiStatueState != GO_STATE_ACTIVE_ALTERNATIVE)
                            return false;
                        break;
                    default:
                        break;
                }

                return true;
            }

            bool IsBridgeReady() const
            {
                return SladRanStatueState == GO_STATE_READY && DrakkariColossusStatueState == GO_STATE_READY && MoorabiStatueState == GO_STATE_READY;
            }

            void SetData(uint32 type, uint32 data) override
            {
                if (type == DATA_STATUE_ACTIVATE)
                {
                    switch (data)
                    {
                        case GO_SLAD_RAN_ALTAR:
                            Events.ScheduleEvent(DATA_SLAD_RAN_STATUE, TIMER_STATUE_ACTIVATION);
                            break;
                        case GO_DRAKKARI_COLOSSUS_ALTAR:
                            Events.ScheduleEvent(DATA_DRAKKARI_COLOSSUS_STATUE, TIMER_STATUE_ACTIVATION);
                            break;
                        case GO_MOORABI_ALTAR:
                            Events.ScheduleEvent(DATA_MOORABI_STATUE, TIMER_STATUE_ACTIVATION);
                            break;
                        default:
                            break;
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << uint32(SladRanStatueState) << ' ';
                data << uint32(DrakkariColossusStatueState) << ' ';
                data << uint32(MoorabiStatueState) << ' ';
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                uint32 temp;

                data >> temp;
                SladRanStatueState = GOState(temp);

                data >> temp;
                DrakkariColossusStatueState = GOState(temp);

                data >> temp;
                MoorabiStatueState = GOState(temp);

                if (IsBridgeReady())
                    Events.ScheduleEvent(DATA_BRIDGE, TIMER_STATUE_ACTIVATION);
            }

            void ToggleGameObject(uint32 type, GOState state)
            {
                if (GameObject* go = GetGameObject(type))
                    go->SetGoState(state);

                switch (type)
                {
                    case DATA_SLAD_RAN_STATUE:
                        SladRanStatueState = state;
                        break;
                    case DATA_DRAKKARI_COLOSSUS_STATUE:
                        DrakkariColossusStatueState = state;
                        break;
                    case DATA_MOORABI_STATUE:
                        MoorabiStatueState = state;
                        break;
                    default:
                        break;
                }
            }

            void Update(uint32 diff) override
            {
                Events.Update(diff);

                while (uint32 eventId = Events.ExecuteEvent())
                {
                    uint32 spellId = 0;
                    uint32 altarId = 0;
                    switch (eventId)
                    {
                        case DATA_SLAD_RAN_STATUE:
                            spellId = SPELL_FIRE_BEAM_SNAKE;
                            altarId = DATA_SLAD_RAN_ALTAR;
                            break;
                        case DATA_DRAKKARI_COLOSSUS_STATUE:
                            spellId = SPELL_FIRE_BEAM_ELEMENTAL;
                            altarId = DATA_DRAKKARI_COLOSSUS_ALTAR;
                            break;
                        case DATA_MOORABI_STATUE:
                            spellId = SPELL_FIRE_BEAM_MAMMOTH;
                            altarId = DATA_MOORABI_ALTAR;
                            break;
                        case DATA_BRIDGE:
                            for (uint32 type = DATA_SLAD_RAN_STATUE; type <= DATA_GAL_DARAH_STATUE; ++type)
                                ToggleGameObject(type, GO_STATE_ACTIVE_ALTERNATIVE);
                            ToggleGameObject(DATA_TRAPDOOR, GO_STATE_READY);
                            ToggleGameObject(DATA_COLLISION, GO_STATE_ACTIVE);
                            SaveToDB();
                            return;
                        default:
                            return;
                    }

                    if (GameObject* altar = GetGameObject(altarId))
                        if (Creature* trigger = altar->FindNearestCreature(NPC_ALTAR_TRIGGER, 10.0f))
                            trigger->CastSpell(nullptr, spellId, true);

                    // eventId equals statueId
                    ToggleGameObject(eventId, GO_STATE_READY);

                    if (IsBridgeReady())
                        Events.ScheduleEvent(DATA_BRIDGE, TIMER_STATUE_ACTIVATION);

                    SaveToDB();
                }
            }

        protected:
            EventMap Events;
            GuidSet DwellerGUIDs;

            GOState SladRanStatueState;
            GOState DrakkariColossusStatueState;
            GOState MoorabiStatueState;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_gundrak_InstanceMapScript(map);
        }
};

class go_gundrak_altar : public GameObjectScript
{
    public:
        go_gundrak_altar() : GameObjectScript("go_gundrak_altar") { }

        bool OnGossipHello(Player* /*player*/, GameObject* go) override
        {
            go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
            go->SetGoState(GO_STATE_ACTIVE);

            if (InstanceScript* instance = go->GetInstanceScript())
            {
                instance->SetData(DATA_STATUE_ACTIVATE, go->GetEntry());
                return true;
            }

            return false;
        }
};

void AddSC_instance_gundrak()
{
    new instance_gundrak();
    new go_gundrak_altar();
}
