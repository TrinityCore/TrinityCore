 /*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "zulaman.h"

#define MAX_ENCOUNTER       6
#define RAND_VENDOR         2
#define CHESTS              4

//187021 //Harkor's Satchel
//186648 //Tanzar's Trunk
//186672 //Ashli's Bag
//186667 //Kraz's Package
// Chests spawn at bear/eagle/dragonhawk/lynx bosses
// The loots depend on how many bosses have been killed, but not the entries of the chests
// But we cannot add loots to gameobject, so we have to use the fixed loot_template
struct SHostageInfo
{
    uint32 npc, pGo;
    float x, y, z, o;
};

static SHostageInfo HostageInfo[] =
{
    {23790, 186648, -57, 1343, 40.77f, 3.2f}, // bear
    {23999, 187021, 400, 1414, 74.36f, 3.3f}, // eagle
    {24001, 186672, -35, 1134, 18.71f, 1.9f}, // dragonhawk
    {24024, 186667, 413, 1117,  6.32f, 3.1f}  // lynx
    
};

enum ChestLootType
{
    NOTHING = 0,
    ARMANI_ARMOR = 1,
    ARMANI_WEAPON = 2,
    ARMANI_RING = 3,
    ARMANI_MOUNT = 4,
};

class instance_zulaman : public InstanceMapScript
{
public:
    instance_zulaman() : InstanceMapScript("instance_zulaman", 568) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_zulaman_InstanceMapScript(pMap);
    }

    struct instance_zulaman_InstanceMapScript : public InstanceScript
    {
        instance_zulaman_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {};

        uint64 HarkorsSatchelGUID;
        uint64 TanzarsTrunkGUID;
        uint64 AshlisBagGUID;
        uint64 KrazsPackageGUID;

        uint64 HexLordGateGUID;
        uint64 AkilzonDoorGUID;
        uint64 ZulJinDoorGUID;
        uint64 HalazziEntranceDoorGUID;
        uint64 HalazziExitDoorGUID;
        uint64 ZulAmanMainGateGUID;

        uint32 QuestTimer;
        uint16 QuestMinute;
        uint16 ChestLooted;

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        uint32 RandVendor[RAND_VENDOR];

        uint32 ChestLootTyp[CHESTS];

        uint32 SacreficeEventStarted;
        uint32 GauntletEventStatus;

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            HarkorsSatchelGUID = 0;
            TanzarsTrunkGUID = 0;
            AshlisBagGUID = 0;
            KrazsPackageGUID = 0;

            HexLordGateGUID = 0;
            AkilzonDoorGUID = 0;
            HalazziEntranceDoorGUID = 0;
            HalazziExitDoorGUID = 0;
            ZulJinDoorGUID = 0;
            ZulAmanMainGateGUID = 0;

            QuestTimer = 0;
            QuestMinute = 21;
            ChestLooted = 0;

            SacreficeEventStarted = NOT_STARTED;
            GauntletEventStatus = NOT_STARTED;

            for (uint8 i = 0; i < RAND_VENDOR; ++i)
                RandVendor[i] = NOT_STARTED;

            for(uint8 i = 0; i < 4; i++)
                ChestLootTyp[i] = NOTHING;

        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS) return true;

            return false;
        }

        void OnCreatureCreate(Creature* pCreature)
        {
            switch(pCreature->GetEntry())
            {
            case 23578://janalai
            case 23863://zuljin
            case 24239://hexlord
            case 23577://halazzi
            case 23576://nalorakk
            default: break;
            }
        }

        void OnGameObjectCreate(GameObject* pGo)
        {
            switch(pGo->GetEntry())
            {
            case 186303: HalazziExitDoorGUID = pGo->GetGUID(); break;
            case 186304: HalazziEntranceDoorGUID  = pGo->GetGUID(); break;
            case 186305: HexLordGateGUID = pGo->GetGUID(); break;
            case 186858: AkilzonDoorGUID = pGo->GetGUID(); break;
            case 186859: ZulJinDoorGUID  = pGo->GetGUID(); break;

            case 187021: HarkorsSatchelGUID  = pGo->GetGUID(); break;
            case 186648: TanzarsTrunkGUID = pGo->GetGUID(); break;
            case 186672: AshlisBagGUID = pGo->GetGUID(); break;
            case 186667: KrazsPackageGUID  = pGo->GetGUID(); break;

            case 186728:
                ZulAmanMainGateGUID = pGo->GetGUID();
                if(SacreficeEventStarted == IN_PROGRESS)
                    HandleGameObject(ZulAmanMainGateGUID,true,pGo);
                break;
            default: break;

            }
            CheckInstanceStatus();
        }

        void SummonHostage(uint8 num)
        {
            if(!QuestMinute)
                return;

            if(!SacreficeEventStarted)
                return;

            Map::PlayerList const &PlayerList = instance->GetPlayers();
            if (PlayerList.isEmpty())
                return;

            Map::PlayerList::const_iterator i = PlayerList.begin();
            if (Player* i_pl = i->getSource())
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
            if(SacreficeEventStarted == 1)
                HandleGameObject(ZulAmanMainGateGUID, true);

            if (PriestsDead())
                HandleGameObject(HexLordGateGUID, true);
        }

        std::string GetSaveData()
        {
            std::ostringstream ss;
            ss << "Z A " 
                << m_auiEncounter[0] << " " 
                << m_auiEncounter[1] << " " 
                << m_auiEncounter[2] << " " 
                << m_auiEncounter[3] << " " 
                << m_auiEncounter[4] << " " 
                << m_auiEncounter[5] << " " 
                << ChestLooted << " " 
                << QuestMinute << " " 
                << SacreficeEventStarted << " " 
                << ChestLootTyp[0] << " " 
                << ChestLootTyp[1] << " " 
                << ChestLootTyp[2] << " " 
                << ChestLootTyp[3];
            char* data = new char[ss.str().length()+1];
            strcpy(data, ss.str().c_str());
            return data;
        }

        void Load(const char* load)
        {
            if (!load) return;
            std::istringstream ss(load);
            char dataHead1, dataHead2; // Z A
            uint16 datab1, datab2, datab3, datab4, datab5, datab6, data2, data3, data4, data5, data6, data7, data8;
            ss >> dataHead1 >> dataHead2 >> datab1 >> datab2 >> datab3 >> datab4 >> datab5 >> datab6 >> data2 >> data3 >> data4 >> data5 >> data6 >> data7 >> data8;
            if (dataHead1 == 'Z' && dataHead2 == 'A')
            {
                m_auiEncounter[0] = datab1;
                m_auiEncounter[1] = datab2;
                m_auiEncounter[2] = datab3;
                m_auiEncounter[3] = datab4;
                m_auiEncounter[4] = datab5;
                m_auiEncounter[5] = datab6;
                //BossKilled = data1;
                ChestLooted = data2;
                QuestMinute = data3;
                SacreficeEventStarted = data4;

                ChestLootTyp[0] = data5;
                ChestLootTyp[1] = data6;
                ChestLootTyp[2] = data7;
                ChestLootTyp[3] = data8;
            } else sLog->outError("TSCR: Zul'aman: corrupted save data.");
        }

        bool PriestsDead()
        {
            return m_auiEncounter[0] == DONE && m_auiEncounter[1] == DONE && m_auiEncounter[2] == DONE && m_auiEncounter[3] == DONE;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
            case DATA_NALORAKKEVENT:
                if(m_auiEncounter[0] != DONE)
                    m_auiEncounter[0] = data;
                if (data == DONE)
                {
                    if (QuestMinute)
                    {
                        QuestMinute += 15;
                        DoUpdateWorldState(3106, QuestMinute);
                    }
                    SummonHostage(0);
                }
                break;
            case DATA_AKILZONEVENT:
                if(m_auiEncounter[1] != DONE)
                    m_auiEncounter[1] = data;
                HandleGameObject(AkilzonDoorGUID, data != IN_PROGRESS);
                if (data == DONE)
                {
                    if (QuestMinute)
                    {
                        QuestMinute += 10;
                        DoUpdateWorldState(3106, QuestMinute);
                    }
                    SummonHostage(1);
                }
                break;
            case DATA_JANALAIEVENT:
                if(m_auiEncounter[2] != DONE)
                    m_auiEncounter[2] = data;
                if (data == DONE) SummonHostage(2);
                break;
            case DATA_HALAZZIEVENT:
                if(m_auiEncounter[3] != DONE)
                    m_auiEncounter[3] = data;
                switch(data)
                {
                case IN_PROGRESS:
                    HandleGameObject(HalazziEntranceDoorGUID, false);
                    break;
                case NOT_STARTED: 
                    HandleGameObject(HalazziEntranceDoorGUID, true);
                    HandleGameObject(HalazziExitDoorGUID, false);
                    break;
                case DONE:
                    HandleGameObject(HalazziEntranceDoorGUID, true);
                    HandleGameObject(HalazziExitDoorGUID, true);
                    SummonHostage(3);
                    break;
                }
                break;
            case DATA_HEXLORDEVENT:
                if(m_auiEncounter[4] != DONE)
                    m_auiEncounter[4] = data;
                if (data == IN_PROGRESS)
                    HandleGameObject(HexLordGateGUID, false);
                else if (data == NOT_STARTED)
                    CheckInstanceStatus();
                break;
            case DATA_ZULJINEVENT:
                m_auiEncounter[5] = data;
                HandleGameObject(ZulJinDoorGUID, data != IN_PROGRESS);
                break;
            case DATA_CHESTLOOTED:
                ++ChestLooted;
                switch(data)
                {
                case 23790: ChestLootTyp[0] = ChestLooted; break;
                case 23999: ChestLootTyp[1] = ChestLooted; break;
                case 24024: ChestLootTyp[2] = ChestLooted; break;
                case 24001: ChestLootTyp[3] = ChestLooted; break;
                }
                SaveToDB();
                break;
            case TYPE_RAND_VENDOR_1:
                RandVendor[0] = data;
                break;
            case TYPE_RAND_VENDOR_2:
                RandVendor[1] = data;
                break;
            case DATA_TIMERSTART:
                if(QuestMinute > 0)
                {
                    SacreficeEventStarted = 1;
                    SaveToDB();
                    DoUpdateWorldState(3104, 1);
                    DoUpdateWorldState(3106, QuestMinute);
                    CheckInstanceStatus();
                }
                break;
            case DATA_GAUNTLET:
                GauntletEventStatus = data;
                break;
            case DATA_TIMERDELETE:
                QuestMinute = 0;
                SacreficeEventStarted = 1;
                DoUpdateWorldState(3104, 0);
                SaveToDB();
                CheckInstanceStatus();
                break;
            }

            if (data == DONE)
            {
                if (QuestMinute && PriestsDead())
                {
                    QuestMinute = 0;
                    DoUpdateWorldState(3104, 0);
                }
                CheckInstanceStatus();
                SaveToDB();
            }
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
            case DATA_NALORAKKEVENT:  return m_auiEncounter[0];
            case DATA_AKILZONEVENT:   return m_auiEncounter[1];
            case DATA_JANALAIEVENT:   return m_auiEncounter[2];
            case DATA_HALAZZIEVENT:   return m_auiEncounter[3];
            case DATA_HEXLORDEVENT:   return m_auiEncounter[4];
            case DATA_ZULJINEVENT:    return m_auiEncounter[5];
            case DATA_CHESTLOOTED:    return ChestLooted;
            case TYPE_RAND_VENDOR_1:  return RandVendor[0];
            case TYPE_RAND_VENDOR_2:  return RandVendor[1];
            case DATA_GAUNTLET:       return GauntletEventStatus;
            case DATA_TIMERSTART:     return SacreficeEventStarted;
            case DATA_CHEST_NAL_LOOT: return ChestLootTyp[0];
            case DATA_CHEST_AKI_LOOT: return ChestLootTyp[1];
            case DATA_CHEST_JAN_LOOT: return ChestLootTyp[2];
            case DATA_CHEST_HAL_LOOT: return ChestLootTyp[3];
            default:                  return 0;
            }
        }

        void Update(uint32 diff)
        {
            if( SacreficeEventStarted == 1)
            {
                if(QuestMinute)
                {
                    if(QuestTimer < diff)
                    {
                        QuestMinute--;
                        if(QuestMinute)
                        {
                            DoUpdateWorldState(3104, 1);
                            DoUpdateWorldState(3106, QuestMinute);
                        }else
                        {
                            DoUpdateWorldState(3104, 0);
                        }
                        SaveToDB();
                        QuestTimer += 60000;
                    }
                    QuestTimer -= diff;
                }
            }
        }
    };
};

void AddSC_instance_zulaman()
{
    new instance_zulaman();
}
