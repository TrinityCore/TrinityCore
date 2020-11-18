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

/* ScriptData
SDName: instance_zulaman
SD%Complete: 80
SDComment:
SDCategory: Zul'Aman
EndScriptData */

#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "Player.h"
#include "TemporarySummon.h"
#include "zulaman.h"

enum Misc
{
    RAND_VENDOR                    = 2,
    WORLDSTATE_SHOW_TIMER          = 3104,
    WORLDSTATE_TIME_TO_SACRIFICE   = 3106
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

Position const HarrisonJonesLoc = { 120.687f, 1674.0f, 42.0217f, 1.59044f };

static DoorData const doorData[] =
{
    { GO_HEXLORD_ENTRANCE,     BOSS_NALORAKK, DOOR_TYPE_PASSAGE },
    { GO_HEXLORD_ENTRANCE,     BOSS_AKILZON,  DOOR_TYPE_PASSAGE },
    { GO_HEXLORD_ENTRANCE,     BOSS_JANALAI,  DOOR_TYPE_PASSAGE },
    { GO_HEXLORD_ENTRANCE,     BOSS_HALAZZI,  DOOR_TYPE_PASSAGE },
    { GO_DOOR_AKILZON,         BOSS_AKILZON,  DOOR_TYPE_ROOM    },
    { GO_LYNX_TEMPLE_ENTRANCE, BOSS_HALAZZI,  DOOR_TYPE_ROOM    },
    { GO_LYNX_TEMPLE_EXIT,     BOSS_HALAZZI,  DOOR_TYPE_ROOM    },
    { GO_HEXLORD_ENTRANCE,     BOSS_HEXLORD,  DOOR_TYPE_ROOM    },
    { GO_WOODEN_DOOR,          BOSS_HEXLORD,  DOOR_TYPE_PASSAGE },
    { GO_DOOR_ZULJIN,          BOSS_ZULJIN,   DOOR_TYPE_ROOM    },
    { 0,                       0,             DOOR_TYPE_ROOM    } // END
};

static ObjectData const creatureData[] =
{
    { NPC_HARRISON_JONES, NPC_HARRISON_JONES },
    { NPC_NALORAKK,       BOSS_NALORAKK      },
    { NPC_AKILZON,        BOSS_AKILZON       },
    { NPC_JANALAI,        BOSS_JANALAI       },
    { NPC_HALAZZI,        BOSS_HALAZZI       },
    { NPC_HEXLORD,        BOSS_HEXLORD       },
    { NPC_ZULJIN,         BOSS_ZULJIN        },
    { 0,                  0                  } // END

};

static ObjectData const gameObjectData[] =
{
    { GO_MASSIVE_GATE,    GO_MASSIVE_GATE    },
    { GO_HARKORS_SATCHEL, GO_HARKORS_SATCHEL },
    { GO_TANZARS_TRUNK,   GO_TANZARS_TRUNK   },
    { GO_ASHLIS_BAG,      GO_ASHLIS_BAG      },
    { GO_KRAZS_PACKAGE,   GO_KRAZS_PACKAGE   },
    { GO_STRANGE_GONG,    GO_STRANGE_GONG    },
    { 0,                  0                  } // END
};

class instance_zulaman : public InstanceMapScript
{
    public:
        instance_zulaman() : InstanceMapScript(ZulamanScriptName, 568) { }

        struct instance_zulaman_InstanceMapScript : public InstanceScript
        {
            instance_zulaman_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(MAX_ENCOUNTER);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameObjectData);

                QuestTimer = 0;
                QuestMinute = 0;
                ChestLooted = 0;

                for (uint8 i = 0; i < RAND_VENDOR; ++i)
                    RandVendor[i] = NOT_STARTED;

                GongEvent = NOT_STARTED;
            }

            uint32 QuestTimer;
            uint32 QuestMinute;
            uint32 ChestLooted;

            EncounterState RandVendor[RAND_VENDOR];
            EncounterState GongEvent;

            void OnPlayerEnter(Player* /*player*/) override
            {
                if (!GetGuidData(NPC_HARRISON_JONES))
                    instance->SummonCreature(NPC_HARRISON_JONES, HarrisonJonesLoc);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                switch (go->GetEntry())
                {
                    case GO_MASSIVE_GATE:
                        if (GongEvent == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    default:
                        break;
                }
            }

            void SummonHostage(uint8 num)
            {
                if (!QuestMinute)
                    return;

                Map::PlayerList const& playerList = instance->GetPlayers();
                if (playerList.isEmpty())
                    return;

                if (Player* player = playerList.getFirst()->GetSource())
                {
                    if (Unit* hostage = player->SummonCreature(HostageInfo[num].npc, HostageInfo[num].pos, TEMPSUMMON_DEAD_DESPAWN))
                    {
                        hostage->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        hostage->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& oss) override
            {
                oss << "S " << uint32(GongEvent) << ' '
                    << uint32(ChestLooted) << ' '
                    << uint32(QuestMinute) << ' ';
            }

            void ReadSaveDataMore(std::istringstream& iss) override
            {
                char dataHead; // S
                uint32 data1, data2, data3;
                iss >> dataHead >> data1 >> data2 >> data3;

                if (dataHead == 'S')
                {
                    GongEvent = EncounterState(data1);
                    ChestLooted = data2;
                    QuestMinute = data3;
                }
                else
                {
                    TC_LOG_ERROR("scripts", "Zul'aman: corrupted save data.");
                    return;
                }

                if (GongEvent == IN_PROGRESS)
                    GongEvent = NOT_STARTED;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_GONGEVENT:
                        GongEvent = EncounterState(data);
                        if (GongEvent == IN_PROGRESS)
                            SaveToDB();
                        else if (GongEvent == DONE)
                            QuestMinute = 21;
                        break;
                    case DATA_CHESTLOOTED:
                        ++ChestLooted;
                        SaveToDB();
                        break;
                    case TYPE_RAND_VENDOR_1:
                    case TYPE_RAND_VENDOR_2:
                        RandVendor[type - TYPE_RAND_VENDOR_1] = EncounterState(data);
                        break;
                }
            }

            bool SetBossState(uint32 id, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(id, state))
                    return false;

                switch (id)
                {
                    case BOSS_NALORAKK:
                        if (state == DONE)
                        {
                            if (QuestMinute)
                            {
                                QuestMinute += 15;
                                DoUpdateWorldState(WORLDSTATE_TIME_TO_SACRIFICE, QuestMinute);
                            }
                            SummonHostage(0);
                        }
                        break;
                    case BOSS_AKILZON:
                        if (state == DONE)
                        {
                            if (QuestMinute)
                            {
                                QuestMinute += 10;
                                DoUpdateWorldState(WORLDSTATE_TIME_TO_SACRIFICE, QuestMinute);
                            }
                            SummonHostage(1);
                        }
                        break;
                    case BOSS_JANALAI:
                        if (state == DONE)
                            SummonHostage(2);
                        break;
                    case BOSS_HALAZZI:
                        if (state == DONE)
                            SummonHostage(3);
                        break;
                }

                if (state == DONE)
                {
                    if (QuestMinute && id == BOSS_HALAZZI)
                    {
                        QuestMinute = 0;
                        DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 0);
                    }
                    SaveToDB();
                }

                return true;
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_GONGEVENT:
                        return uint32(GongEvent);
                    case DATA_CHESTLOOTED:
                        return ChestLooted;
                    case TYPE_RAND_VENDOR_1:
                    case TYPE_RAND_VENDOR_2:
                        return RandVendor[type - TYPE_RAND_VENDOR_1];
                }

                return 0;
            }

            void Update(uint32 diff) override
            {
                if (QuestMinute)
                {
                    if (QuestTimer <= diff)
                    {
                        QuestMinute--;
                        SaveToDB();
                        QuestTimer += 1 * MINUTE * IN_MILLISECONDS;
                        if (QuestMinute)
                        {
                            DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 1);
                            DoUpdateWorldState(WORLDSTATE_TIME_TO_SACRIFICE, QuestMinute);
                        }
                        else
                            DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 0);
                    }
                    QuestTimer -= diff;
                }
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_zulaman_InstanceMapScript(map);
        }
};

void AddSC_instance_zulaman()
{
    new instance_zulaman();
}
