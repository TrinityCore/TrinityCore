 /* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/* ScriptData
SDName: instance_zulaman
SD%Complete: 80
SDComment:
SDCategory: Zul'Aman
EndScriptData */

#include "precompiled.h"
#include "def_zulaman.h"

#define ENCOUNTERS     6
#define RAND_VENDOR    2

//187021 //Harkor's Satchel
//186648 //Tanzar's Trunk
//186672 //Ashli's Bag
//186667 //Kraz's Package
// Chests spawn at bear/eagle/dragonhawk/lynx bosses
// The loots depend on how many bosses have been killed, but not the entries of the chests
// But we cannot add loots to gameobject, so we have to use the fixed loot_template
struct SHostageInfo
{
    uint32 npc, go;
    float x, y, z, o;
};

static SHostageInfo HostageInfo[] =
{
    {23790, 186648, -57, 1343, 40.77, 3.2}, // bear
    {23999, 187021, 400, 1414, 74.36, 3.3}, // eagle
    {24001, 186672, -35, 1134, 18.71, 1.9}, // dragonhawk
    {24024, 186667, 413, 1117,  6.32, 3.1}  // lynx

};

struct TRINITY_DLL_DECL instance_zulaman : public ScriptedInstance
{
    instance_zulaman(Map *map) : ScriptedInstance(map) {Initialize();};

    uint64 HarkorsSatchelGUID;
    uint64 TanzarsTrunkGUID;
    uint64 AshlisBagGUID;
    uint64 KrazsPackageGUID;

    uint64 HexLordGateGUID;
    uint64 ZulJinGateGUID;
    uint64 AkilzonDoorGUID;
    uint64 ZulJinDoorGUID;
    uint64 HalazziDoorGUID;

    uint32 QuestTimer;
    uint16 BossKilled;
    uint16 QuestMinute;
    uint16 ChestLooted;

    uint32 Encounters[ENCOUNTERS];
    uint32 RandVendor[RAND_VENDOR];

    void Initialize()
    {
        HarkorsSatchelGUID = 0;
        TanzarsTrunkGUID = 0;
        AshlisBagGUID = 0;
        KrazsPackageGUID = 0;

        uint64 HexLordGateGUID = 0;
        uint64 ZulJinGateGUID = 0;
        uint64 AkilzonDoorGUID = 0;
        uint64 HalazziDoorGUID = 0;
        uint64 ZulJinDoorGUID = 0;

        QuestTimer = 0;
        QuestMinute = 21;
        BossKilled = 0;
        ChestLooted = 0;

        for(uint8 i = 0; i < ENCOUNTERS; i++)
            Encounters[i] = NOT_STARTED;
        for(uint8 i = 0; i < RAND_VENDOR; i++)
            RandVendor[i] = NOT_STARTED;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < ENCOUNTERS; i++)
            if(Encounters[i] == IN_PROGRESS) return true;

        return false;
    }

    void OnCreatureCreate(Creature *creature, bool add)
    {
        switch(creature->GetEntry())
        {
        case 23578://janalai
        case 23863://zuljin
        case 24239://hexlord
        case 23577://halazzi
        case 23576://nalorakk
        default: break;
        }
    }

    void OnGameObjectCreate(GameObject *go, bool add)
    {
        switch(go->GetEntry())
        {
        case 186303: HalazziDoorGUID = go->GetGUID(); break;
        case 186304: ZulJinGateGUID  = go->GetGUID(); break;
        case 186305: HexLordGateGUID = go->GetGUID(); break;
        case 186858: AkilzonDoorGUID = go->GetGUID(); break;
        case 186859: ZulJinDoorGUID  = go->GetGUID(); break;

        case 187021: HarkorsSatchelGUID  = go->GetGUID(); break;
        case 186648: TanzarsTrunkGUID = go->GetGUID(); break;
        case 186672: AshlisBagGUID = go->GetGUID(); break;
        case 186667: KrazsPackageGUID  = go->GetGUID(); break;
        default: break;

        }
        CheckInstanceStatus();
    }

    void OpenDoor(uint64 DoorGUID, bool open)
    {
        if(GameObject *Door = instance->GetGameObject(DoorGUID))
            Door->SetGoState(open ? GO_STATE_ACTIVE : GO_STATE_READY);
    }

    void SummonHostage(uint8 num)
    {
        if(!QuestMinute)
            return;

        Map::PlayerList const &PlayerList = instance->GetPlayers();
        if (PlayerList.isEmpty())
            return;

        Map::PlayerList::const_iterator i = PlayerList.begin();
        if(Player* i_pl = i->getSource())
        {
            if(Unit* Hostage = i_pl->SummonCreature(HostageInfo[num].npc, HostageInfo[num].x, HostageInfo[num].y, HostageInfo[num].z, HostageInfo[num].o, TEMPSUMMON_DEAD_DESPAWN, 0))
            {
                Hostage->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                Hostage->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
            }
        }
    }

    void CheckInstanceStatus()
    {
        if(BossKilled >= 4)
            OpenDoor(HexLordGateGUID, true);

        if(BossKilled >= 5)
            OpenDoor(ZulJinGateGUID, true);
    }

    void UpdateWorldState(uint32 field, uint32 value)
    {
        WorldPacket data(SMSG_UPDATE_WORLD_STATE, 8);
        data << field << value;
        instance->SendToPlayers(&data);
    }

    std::string GetSaveData()
    {
        std::ostringstream ss;
        ss << "S " << BossKilled << " " << ChestLooted << " " << QuestMinute;
        char* data = new char[ss.str().length()+1];
        strcpy(data, ss.str().c_str());
        //error_log("TSCR: Zul'aman saved, %s.", data);
        return data;
    }

    void Load(const char* load)
    {
        if(!load) return;
        std::istringstream ss(load);
        //error_log("TSCR: Zul'aman loaded, %s.", ss.str().c_str());
        char dataHead; // S
        uint16 data1, data2, data3;
        ss >> dataHead >> data1 >> data2 >> data3;
        //error_log("TSCR: Zul'aman loaded, %d %d %d.", data1, data2, data3);
        if(dataHead == 'S')
        {
            BossKilled = data1;
            ChestLooted = data2;
            QuestMinute = data3;
        }else error_log("TSCR: Zul'aman: corrupted save data.");
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
        case DATA_NALORAKKEVENT:
            Encounters[0] = data;
            if(data == DONE)
            {
                if(QuestMinute)
                {
                    QuestMinute += 15;
                    UpdateWorldState(3106, QuestMinute);
                }
                SummonHostage(0);
            }
            break;
        case DATA_AKILZONEVENT:
            Encounters[1] = data;
            OpenDoor(AkilzonDoorGUID, data != IN_PROGRESS);
            if(data == DONE)
            {
                if(QuestMinute)
                {
                    QuestMinute += 10;
                    UpdateWorldState(3106, QuestMinute);
                }
                SummonHostage(1);
            }
            break;
        case DATA_JANALAIEVENT:
            Encounters[2] = data;
            if(data == DONE) SummonHostage(2);
            break;
        case DATA_HALAZZIEVENT:
            Encounters[3] = data;
            OpenDoor(HalazziDoorGUID, data != IN_PROGRESS);
            if(data == DONE) SummonHostage(3);
            break;
        case DATA_HEXLORDEVENT:
            Encounters[4] = data;
            if(data == IN_PROGRESS)
                OpenDoor(HexLordGateGUID, false);
            else if(data == NOT_STARTED)
                CheckInstanceStatus();
            break;
        case DATA_ZULJINEVENT:
            Encounters[5] = data;
            OpenDoor(ZulJinDoorGUID, data != IN_PROGRESS);
            break;
        case DATA_CHESTLOOTED:
            ChestLooted++;
            SaveToDB();
            break;
        case TYPE_RAND_VENDOR_1:
            RandVendor[0] = data;
            break;
        case TYPE_RAND_VENDOR_2:
            RandVendor[1] = data;
            break;
        }

        if(data == DONE)
        {
            BossKilled++;
            if(QuestMinute && BossKilled >= 4)
            {
                QuestMinute = 0;
                UpdateWorldState(3104, 0);
            }
            CheckInstanceStatus();
            SaveToDB();
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
        case DATA_NALORAKKEVENT: return Encounters[0];
        case DATA_AKILZONEVENT:  return Encounters[1];
        case DATA_JANALAIEVENT:  return Encounters[2];
        case DATA_HALAZZIEVENT:  return Encounters[3];
        case DATA_HEXLORDEVENT:  return Encounters[4];
        case DATA_ZULJINEVENT:   return Encounters[5];
        case DATA_CHESTLOOTED:   return ChestLooted;
        case TYPE_RAND_VENDOR_1: return RandVendor[0];
        case TYPE_RAND_VENDOR_2: return RandVendor[1];
        default:                 return 0;
        }
    }

    void Update(uint32 diff)
    {
        if(QuestMinute)
        {
            if(QuestTimer < diff)
            {
                QuestMinute--;
                SaveToDB();
                QuestTimer += 60000;
                if(QuestMinute)
                {
                    UpdateWorldState(3104, 1);
                    UpdateWorldState(3106, QuestMinute);
                }else UpdateWorldState(3104, 0);
            }
            QuestTimer -= diff;
        }
    }
};

InstanceData* GetInstanceData_instance_zulaman(Map* map)
{
    return new instance_zulaman(map);
}

void AddSC_instance_zulaman()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_zulaman";
    newscript->GetInstanceData = &GetInstanceData_instance_zulaman;
    newscript->RegisterSelf();
}

