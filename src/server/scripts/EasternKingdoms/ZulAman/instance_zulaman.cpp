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
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "TemporarySummon.h"
#include "zulaman.h"
#include <algorithm>

struct NalorakkWaveDefinition
{
    std::string_view StringId;
    uint8 CreatureCount;
    ZAActionIds ActionId;
} static constexpr NalorakkEventWaves[] =
{
    { .StringId = "NalorakkWave1", .CreatureCount = 3, .ActionId = ACTION_WAVE_DONE_1 },
    { .StringId = "NalorakkWave2", .CreatureCount = 4, .ActionId = ACTION_WAVE_DONE_2 },
    { .StringId = "NalorakkWave3", .CreatureCount = 2, .ActionId = ACTION_WAVE_DONE_3 },
    { .StringId = "NalorakkWave4", .CreatureCount = 4, .ActionId = ACTION_WAVE_DONE_4 },
};

// Chests spawn at bear/eagle/dragonhawk/lynx bosses
// The loots depend on how many bosses have been killed, but not the entries of the chests
// But we cannot add loots to gameobject, so we have to use the fixed loot_template
struct SHostageInfo
{
    uint32 npc, go; // FIXME go Not used
    Position pos;
};

static SHostageInfo const HostageInfo[] =
{
    { 23790, 186648, { -57.f, 1343.f, 40.77f, 3.2f } }, // bear
    { 23999, 187021, { 400.f, 1414.f, 74.36f, 3.3f } }, // eagle
    { 24001, 186672, { -35.f, 1134.f, 18.71f, 1.9f } }, // dragonhawk
    { 24024, 186667, { 413.f, 1117.f,  6.32f, 3.1f } }  // lynx
};

static constexpr DoorData doorData[] =
{
    { GO_HEXLORD_ENTRANCE,     BOSS_NALORAKK, EncounterDoorBehavior::OpenWhenDone          },
    { GO_HEXLORD_ENTRANCE,     BOSS_AKILZON,  EncounterDoorBehavior::OpenWhenDone          },
    { GO_HEXLORD_ENTRANCE,     BOSS_JANALAI,  EncounterDoorBehavior::OpenWhenDone          },
    { GO_HEXLORD_ENTRANCE,     BOSS_HALAZZI,  EncounterDoorBehavior::OpenWhenDone          },
    { GO_DOOR_AKILZON,         BOSS_AKILZON,  EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_LYNX_TEMPLE_ENTRANCE, BOSS_HALAZZI,  EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_LYNX_TEMPLE_EXIT,     BOSS_HALAZZI,  EncounterDoorBehavior::OpenWhenDone          },
    { GO_HEXLORD_ENTRANCE,     BOSS_HEXLORD,  EncounterDoorBehavior::OpenWhenNotInProgress },
    { GO_WOODEN_DOOR,          BOSS_HEXLORD,  EncounterDoorBehavior::OpenWhenDone          },
    { GO_DOOR_DAAKARA,         BOSS_DAAKARA,  EncounterDoorBehavior::OpenWhenNotInProgress }
};

static constexpr ObjectData creatureData[] =
{
    { NPC_NALORAKK,           BOSS_NALORAKK          },
    { NPC_AKILZON,            BOSS_AKILZON           },
    { NPC_JANALAI,            BOSS_JANALAI           },
    { NPC_HALAZZI,            BOSS_HALAZZI           },
    { NPC_HEXLORD,            BOSS_HEXLORD           },
    { NPC_HEXLORD_TRIGGER,    DATA_HEXLORD_TRIGGER   },
    { NPC_DAAKARA,            BOSS_DAAKARA           },
    { NPC_BEAR_SPIRIT,        DATA_BEAR_SPIRIT       },
    { NPC_EAGLE_SPIRIT,       DATA_EAGLE_SPIRIT      },
    { NPC_LYNX_SPIRIT,        DATA_LYNX_SPIRIT       },
    { NPC_DRAGONHAWK_SPIRIT,  DATA_DRAGONHAWK_SPIRIT }
};

static constexpr ObjectData gameObjectData[] =
{
    { GO_MASSIVE_GATE,      GO_MASSIVE_GATE      },
    { GO_BAKKALZUS_SATCHEL, GO_BAKKALZUS_SATCHEL },
    { GO_HAZLEKS_TRUNK,     GO_HAZLEKS_TRUNK     },
    { GO_KASHAS_BAG,        GO_KASHAS_BAG        },
    { GO_NORKANIS_PACKAGE,  GO_NORKANIS_PACKAGE  },
    { GO_STRANGE_GONG,      GO_STRANGE_GONG      }
};

static constexpr DungeonEncounterData encounters[] =
{
    { BOSS_AKILZON, {{ 1189 }} },
    { BOSS_NALORAKK, {{ 1190 }} },
    { BOSS_JANALAI, {{ 1191 }} },
    { BOSS_HALAZZI, {{ 1192 }} },
    { BOSS_HEXLORD, {{ 1193 }} },
    { BOSS_DAAKARA, {{ 1194 }} }
};

class instance_zulaman : public InstanceMapScript
{
    public:
        instance_zulaman() : InstanceMapScript(ZulamanScriptName, 568) { }

        struct instance_zulaman_InstanceScript : public InstanceScript
        {
            instance_zulaman_InstanceScript(InstanceMap* map) : InstanceScript(map),
                ZulAmanState(*this, "TimedRunState", NOT_STARTED)
            {
                SetHeaders(DataHeader);
                SetBossNumber(MAX_ENCOUNTER);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);
                LoadDungeonEncounterData(encounters);

                SpeedRunTimer           = 15;
                ZulAmanBossCount        = 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_VOLJIN:
                        VoljinGUID = creature->GetGUID();
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
                    case GO_MASSIVE_GATE:
                        if (ZulAmanState != NOT_STARTED)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                InstanceScript::OnUnitDeath(unit);

                Creature* creature = unit->ToCreature();
                if (!creature)
                    return;

                auto nalorakkEventWave = std::ranges::find_if(NalorakkEventWaves,
                    [creature](std::string_view stringId) { return creature->HasStringId(stringId); }, &NalorakkWaveDefinition::StringId);
                if (nalorakkEventWave != std::ranges::end(NalorakkEventWaves))
                {
                    std::ptrdiff_t waveIndex = std::ranges::distance(std::ranges::begin(NalorakkEventWaves), nalorakkEventWave);
                    ++killedUnitInWaveCounter[waveIndex];

                    if (killedUnitInWaveCounter[waveIndex] == nalorakkEventWave->CreatureCount)
                        if (Creature* nalorakk = GetCreature(BOSS_NALORAKK))
                            nalorakk->AI()->DoAction(nalorakkEventWave->ActionId);
                }
            }

            void SummonHostage(uint8 num)
            {
                if (ZulAmanState != IN_PROGRESS)
                    return;

                Map::PlayerList const& playerList = instance->GetPlayers();
                if (playerList.empty())
                    return;

                if (Player* player = playerList.front()->GetSource())
                {
                    if (Unit* hostage = player->SummonCreature(HostageInfo[num].npc, HostageInfo[num].pos, TEMPSUMMON_DEAD_DESPAWN))
                    {
                        hostage->SetUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
                        hostage->SetNpcFlag(UNIT_NPC_FLAG_GOSSIP);
                    }
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_ZULAMAN_STATE:
                    {
                        if (data == IN_PROGRESS)
                        {
                            DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER_ENABLED, 1);
                            DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER, 15);
                            events.ScheduleEvent(EVENT_UPDATE_ZULAMAN_TIMER, 1min);
                            SpeedRunTimer = 15;
                            ZulAmanState = data;
                        }
                        break;
                    }
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ZULAMAN_STATE:
                        return ZulAmanState;
                    default:
                        break;
                }

                return 0;
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (state == DONE)
                {
                    if (ZulAmanState == IN_PROGRESS && SpeedRunTimer)
                    {
                        ++ZulAmanBossCount;

                        if (ZulAmanBossCount < 2)
                        {
                            SpeedRunTimer = SpeedRunTimer + 5;
                            DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER, SpeedRunTimer);
                        }
                        else if (ZulAmanBossCount == 4)
                        {
                            DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER_ENABLED, 0);
                            events.CancelEvent(EVENT_UPDATE_ZULAMAN_TIMER);
                            ZulAmanState = DONE;
                        }
                    }
                }

                switch (type)
                {
                    case BOSS_NALORAKK:
                        if (state == DONE)
                            SummonHostage(0);
                        break;
                    case BOSS_AKILZON:
                        if (state == DONE)
                            SummonHostage(1);
                        break;
                    case BOSS_JANALAI:
                        if (state == DONE)
                            SummonHostage(2);
                        break;
                    case BOSS_HALAZZI:
                        if (state == DONE)
                            SummonHostage(3);
                        break;
                    case BOSS_HEXLORD:
                    case BOSS_DAAKARA:
                    default:
                        break;
                }

                return true;
            }

            void ProcessEvent(WorldObject* /*obj*/, uint32 eventId, WorldObject* /*invoker*/) override
            {
                switch (eventId)
                {
                    case EVENT_START_ZULAMAN:
                        if (Creature* voljin = instance->GetCreature(VoljinGUID))
                        {
                            if (voljin->IsAIEnabled())
                                voljin->AI()->DoAction(ACTION_START_ZULAMAN);
                        }
                        break;
                    default:
                        break;
                }
            }

            void Update(uint32 diff) override
            {
                if (events.Empty())
                    return;

                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_UPDATE_ZULAMAN_TIMER:
                            DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER, --SpeedRunTimer);
                            if (SpeedRunTimer)
                                events.ScheduleEvent(EVENT_UPDATE_ZULAMAN_TIMER, 1min);
                            else
                            {
                                DoUpdateWorldState(WORLD_STATE_ZULAMAN_TIMER_ENABLED, 0);
                                events.CancelEvent(EVENT_UPDATE_ZULAMAN_TIMER);
                                ZulAmanState = FAIL;
                            }
                            break;
                        default:
                            break;
                    }
                }
            }

            void AfterDataLoad() override
            {
                // Speed run cannot be resumed after reset/crash
                if (ZulAmanState != NOT_STARTED)
                {
                    SpeedRunTimer = 0;
                    ZulAmanState.LoadValue(FAIL);
                }
            }

        protected:
            EventMap events;
            ObjectGuid VoljinGUID;
            uint32 SpeedRunTimer;
            PersistentInstanceScriptValue<uint32> ZulAmanState;
            uint32 ZulAmanBossCount;
            std::array<uint8, 4> killedUnitInWaveCounter = { };
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_zulaman_InstanceScript(map);
        }
};

void AddSC_instance_zulaman()
{
    new instance_zulaman();
}
