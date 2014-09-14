 /*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "InstanceScript.h"
#include "zulaman.h"
#include "Player.h"
#include "TemporarySummon.h"

enum Misc
{
    MAX_ENCOUNTER                  = 7,
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
    float x, y, z, o;
};

static SHostageInfo HostageInfo[] =
{
    {23790, 186648, -57, 1343, 40.77f, 3.2f}, // bear
    {23999, 187021, 400, 1414, 74.36f, 3.3f}, // eagle
    {24001, 186672, -35, 1134, 18.71f, 1.9f}, // dragonhawk
    {24024, 186667, 413, 1117,  6.32f, 3.1f}  // lynx
};

Position const HarrisonJonesLoc = {120.687f, 1674.0f, 42.0217f, 1.59044f};

class instance_zulaman : public InstanceMapScript
{
    public:
        instance_zulaman()
            : InstanceMapScript("instance_zulaman", 568)
        {
        }

        struct instance_zulaman_InstanceMapScript : public InstanceScript
        {
            instance_zulaman_InstanceMapScript(Map* map) : InstanceScript(map) { }

            ObjectGuid HarkorsSatchelGUID;
            ObjectGuid TanzarsTrunkGUID;
            ObjectGuid AshlisBagGUID;
            ObjectGuid KrazsPackageGUID;
            ObjectGuid StrangeGongGUID;
            ObjectGuid HarrisonJonesGUID;

            ObjectGuid HexLordGateGUID;
            ObjectGuid ZulJinGateGUID;
            ObjectGuid MassiveGateGUID;
            ObjectGuid AkilzonDoorGUID;
            ObjectGuid ZulJinDoorGUID;
            ObjectGuid HalazziDoorGUID;

            uint32 QuestTimer;
            uint16 BossKilled;
            uint16 QuestMinute;
            uint16 ChestLooted;

            uint32 m_auiEncounter[MAX_ENCOUNTER];
            uint32 RandVendor[RAND_VENDOR];

            void Initialize() override
            {
                SetHeaders(DataHeader);
                memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

                QuestTimer = 0;
                QuestMinute = 0;
                BossKilled = 0;
                ChestLooted = 0;

                for (uint8 i = 0; i < RAND_VENDOR; ++i)
                    RandVendor[i] = NOT_STARTED;

                m_auiEncounter[DATA_GONGEVENT] = NOT_STARTED;
            }

            bool IsEncounterInProgress() const override
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        return true;

                return false;
            }

            void OnPlayerEnter(Player* /*player*/)
            {
                if (!HarrisonJonesGUID)
                    instance->SummonCreature(NPC_HARRISON_JONES, HarrisonJonesLoc);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_HARRISON_JONES:
                        HarrisonJonesGUID = creature->GetGUID();
                        break;
                    case NPC_JANALAI:
                    case NPC_ZULJIN:
                    case NPC_HEXLORD:
                    case NPC_HALAZZI:
                    case NPC_NALORAKK:
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GO_DOOR_HALAZZI: HalazziDoorGUID = go->GetGUID(); break;
                    case GO_GATE_ZULJIN: ZulJinGateGUID = go->GetGUID(); break;
                    case GO_GATE_HEXLORD: HexLordGateGUID = go->GetGUID(); break;
                    case GO_MASSIVE_GATE: MassiveGateGUID = go->GetGUID(); break;
                    case GO_DOOR_AKILZON: AkilzonDoorGUID = go->GetGUID(); break;
                    case GO_DOOR_ZULJIN: ZulJinDoorGUID = go->GetGUID(); break;

                    case GO_HARKORS_SATCHEL: HarkorsSatchelGUID = go->GetGUID(); break;
                    case GO_TANZARS_TRUNK: TanzarsTrunkGUID = go->GetGUID(); break;
                    case GO_ASHLIS_BAG: AshlisBagGUID = go->GetGUID(); break;
                    case GO_KRAZS_PACKAGE: KrazsPackageGUID = go->GetGUID(); break;
                    case GO_STRANGE_GONG: StrangeGongGUID = go->GetGUID(); break;
                    default: break;
                }
                CheckInstanceStatus();
            }

            void SummonHostage(uint8 num)
            {
                if (!QuestMinute)
                    return;

                Map::PlayerList const &PlayerList = instance->GetPlayers();
                if (PlayerList.isEmpty())
                    return;

                Map::PlayerList::const_iterator i = PlayerList.begin();
                if (Player* i_pl = i->GetSource())
                {
                    if (Unit* Hostage = i_pl->SummonCreature(HostageInfo[num].npc, HostageInfo[num].x, HostageInfo[num].y, HostageInfo[num].z, HostageInfo[num].o, TEMPSUMMON_DEAD_DESPAWN, 0))
                    {
                        Hostage->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                        Hostage->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                    }
                }
            }

            void CheckInstanceStatus()
            {
                if (BossKilled >= DATA_HALAZZIEVENT)
                    HandleGameObject(HexLordGateGUID, true);

                if (BossKilled >= DATA_HEXLORDEVENT)
                    HandleGameObject(ZulJinGateGUID, true);
            }

            std::string GetSaveData() override
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream ss;
                ss << "S " << BossKilled << ' ' << ChestLooted << ' ' << QuestMinute;

                OUT_SAVE_INST_DATA_COMPLETE;
                return ss.str();
            }

            void Load(const char* load)
            {
                if (!load)
                    return;

                std::istringstream ss(load);
                //TC_LOG_ERROR("scripts", "Zul'aman loaded, %s.", ss.str().c_str());
                char dataHead; // S
                uint16 data1, data2, data3;
                ss >> dataHead >> data1 >> data2 >> data3;
                //TC_LOG_ERROR("scripts", "Zul'aman loaded, %d %d %d.", data1, data2, data3);
                if (dataHead == 'S')
                {
                    BossKilled = data1;
                    ChestLooted = data2;
                    QuestMinute = data3;
                } else TC_LOG_ERROR("scripts", "Zul'aman: corrupted save data.");
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                case DATA_GONGEVENT:
                    m_auiEncounter[DATA_GONGEVENT] = data;
                    if (data == IN_PROGRESS)
                        SaveToDB();
                    else if (data == DONE)
                        QuestMinute = 21;
                    break;
                case DATA_NALORAKKEVENT:
                    m_auiEncounter[DATA_NALORAKKEVENT] = data;
                    if (data == DONE)
                    {
                        if (QuestMinute)
                        {
                            QuestMinute += 15;
                            DoUpdateWorldState(WORLDSTATE_TIME_TO_SACRIFICE, QuestMinute);
                        }
                        SummonHostage(0);
                    }
                    break;
                case DATA_AKILZONEVENT:
                    m_auiEncounter[DATA_AKILZONEVENT] = data;
                    HandleGameObject(AkilzonDoorGUID, data != IN_PROGRESS);
                    if (data == DONE)
                    {
                        if (QuestMinute)
                        {
                            QuestMinute += 10;
                            DoUpdateWorldState(WORLDSTATE_TIME_TO_SACRIFICE, QuestMinute);
                        }
                        SummonHostage(1);
                    }
                    break;
                case DATA_JANALAIEVENT:
                    m_auiEncounter[DATA_JANALAIEVENT] = data;
                    if (data == DONE)
                        SummonHostage(2);
                    break;
                case DATA_HALAZZIEVENT:
                    m_auiEncounter[DATA_HALAZZIEVENT] = data;
                    HandleGameObject(HalazziDoorGUID, data != IN_PROGRESS);
                    if (data == DONE) SummonHostage(3);
                    break;
                case DATA_HEXLORDEVENT:
                    m_auiEncounter[DATA_HEXLORDEVENT] = data;
                    if (data == IN_PROGRESS)
                        HandleGameObject(HexLordGateGUID, false);
                    else if (data == NOT_STARTED)
                        CheckInstanceStatus();
                    break;
                case DATA_ZULJINEVENT:
                    m_auiEncounter[DATA_ZULJINEVENT] = data;
                    HandleGameObject(ZulJinDoorGUID, data != IN_PROGRESS);
                    break;
                case DATA_CHESTLOOTED:
                    ++ChestLooted;
                    SaveToDB();
                    break;
                case TYPE_RAND_VENDOR_1:
                    RandVendor[0] = data;
                    break;
                case TYPE_RAND_VENDOR_2:
                    RandVendor[1] = data;
                    break;
                }

                if (data == DONE)
                {
                    ++BossKilled;
                    if (QuestMinute && BossKilled >= DATA_HALAZZIEVENT)
                    {
                        QuestMinute = 0;
                        DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 0);
                    }
                    CheckInstanceStatus();
                    SaveToDB();
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                case DATA_GONGEVENT:     return m_auiEncounter[DATA_GONGEVENT];
                case DATA_NALORAKKEVENT: return m_auiEncounter[DATA_NALORAKKEVENT];
                case DATA_AKILZONEVENT:  return m_auiEncounter[DATA_AKILZONEVENT];
                case DATA_JANALAIEVENT:  return m_auiEncounter[DATA_JANALAIEVENT];
                case DATA_HALAZZIEVENT:  return m_auiEncounter[DATA_HALAZZIEVENT];
                case DATA_HEXLORDEVENT:  return m_auiEncounter[DATA_HEXLORDEVENT];
                case DATA_ZULJINEVENT:   return m_auiEncounter[DATA_ZULJINEVENT];
                case DATA_CHESTLOOTED:   return ChestLooted;
                case TYPE_RAND_VENDOR_1: return RandVendor[0];
                case TYPE_RAND_VENDOR_2: return RandVendor[1];
                default:                 return 0;
                }
            }

            void Update(uint32 diff) override
            {
                if (QuestMinute)
                {
                    if (QuestTimer <= diff)
                    {
                        QuestMinute--;
                        SaveToDB();
                        QuestTimer += 60000;
                        if (QuestMinute)
                        {
                            DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 1);
                            DoUpdateWorldState(WORLDSTATE_TIME_TO_SACRIFICE, QuestMinute);
                        } else DoUpdateWorldState(WORLDSTATE_SHOW_TIMER, 0);
                    }
                    QuestTimer -= diff;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case GO_STRANGE_GONG:
                        return StrangeGongGUID;
                    case GO_MASSIVE_GATE:
                        return MassiveGateGUID;
                }

                return 0;
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

