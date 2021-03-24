/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "TSEvents.h"
#include "TSEventLoader.h"
#include "TSMutable.h"
#include "Player.h"
#include "TSPlayer.h"
#include "TSVehicle.h"
#include "TSUnit.h"
#include "TSSpell.h"
#include "TSCreature.h"
#include "TSQuest.h"
#include "TSItem.h"
#include "QuestDef.h"
#include "TSMutableString.h"
#include "ItemTemplate.h"
#include "TSItemTemplate.h"
#include "TSSpellInfo.h"
#include "Group.h"
#include "TSGroup.h"
#include "Guild.h"
#include "TSGuild.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "TSIDs.h"
#include "TSChannel.h"
#include "TSTask.h"
#include "DBCStores.h"
#include "MapManager.h"
#include "base64.h"
#include "Config.h"

#include <fstream>
#include <map>

TSTasks<void*> globalTasks;
TSTasks<void*> GetTasks()
{
    return globalTasks;
}

class TSWorldUpdater : public WorldScript {
public:
    TSWorldUpdater() : WorldScript("TSWorldUpdater"){}
    void OnUpdate(uint32 diff)
    {
        globalTasks.Tick(nullptr);
    }
};

TSEvents tsEvents;
std::map<std::string,TSEventHandlers> eventHandlers;

std::map<std::string,uint32_t> modIds;
std::vector<uint32_t> reloads;

/** Network Message maps */
std::vector<MessageHandle<void>> messageMap;
std::map<uint32_t, std::vector<uint16_t>> messageModMap;

std::vector<MessageHandle<void>> & getMessageMap()
{
    return messageMap;
}

TSEvents* GetTSEvents()
{
    return &tsEvents;
}

uint32_t GetReloads(uint32_t modid)
{
    return reloads[modid];
}

bool TSShouldLoadEventHandler(boost::filesystem::path const& name)
{
    std::string name_str = name.filename().string();
    if(name_str.size() <= 4)
    {
        return false;
    }
    auto name_offset = name_str.find("scripts_tswow_")+strlen("scripts_tswow_");
    name_str = name_str.substr(name_offset,name_str.find(".")-name_offset);
    std::string data_dir =
        sConfigMgr->GetStringDefault("DataDir","../../datasets/default");
    auto modulesfile =
        boost::filesystem::path(data_dir) / boost::filesystem::path("modules.txt");
    std::ifstream f(modulesfile.string().c_str());
    if(!f)
    {
        return true;
    }
    std::string line;
    while (std::getline(f, line))
    {
        if(line == name_str)
        {
            return true;
        }
    }
    return false;
}

TSEventHandlers* TSLoadEventHandler(boost::filesystem::path const& name)
{
    std::string sname = name.string();
    uint32_t modid = 0;
    if(modIds.find(sname) != modIds.end())
    {
        modid = modIds[sname];
    }
    else
    {
        modid = reloads.size();
        reloads.push_back(0);
    }

    auto handler = &(eventHandlers[sname] = TSEventHandlers());
    handler->modid = modid;
    handler->LoadEvents(&tsEvents);
    return handler;
}

static void RemoveData(WorldObject* obj)
{
    obj->storage.map.clear();
    obj->tasks.timers.vec->clear();
    obj->collisions.callbacks.clear();
}

struct RemoveWorker {
    void Visit(std::unordered_map<ObjectGuid, Creature*>& creatureMap)
    {
        for(auto const& p : creatureMap)
            RemoveData(p.second);
    }

    void Visit(std::unordered_map<ObjectGuid, GameObject*>& gameObjectMap)
    {
        for(auto const& p : gameObjectMap)
            RemoveData(p.second);
    }

    template<class T>
    void Visit(std::unordered_map<ObjectGuid, T*>&) { }
};

void TSUnloadEventHandler(boost::filesystem::path const& name)
{
    std::string sname = name.string();
    // Unload network message classes and handlers
    auto modid = modIds[sname];
    if(messageModMap.find(modid) != messageModMap.end())
    {
        auto vec = messageModMap[modid];
        for(auto g : vec)
        {
            if(g>messageMap.size()) {
                continue;
            }
            messageMap[g] = MessageHandle<void>();
        }
        messageModMap.erase(modid);
    }

    // Unload events
    std::map<std::string,TSEventHandlers>::iterator iter 
        = eventHandlers.find(sname);
    if(iter!=eventHandlers.end())
    {
        iter->second.Unload();
        reloads[iter->second.modid]++;
        eventHandlers.erase(sname);
    }

    // Clean up timers and storage for creatures and gameobjects
    sMapMgr->DoForAllMaps([](auto map){
        map->tasks.timers.vec->clear();
        map->storage.map.clear();
        RemoveWorker worker;
        TypeContainerVisitor<RemoveWorker, MapStoredObjectTypesContainer> visitor(worker);
        visitor.Visit(map->GetObjectsStore());
    });

    // Clean up timers and storage for players
    for(auto &p : ObjectAccessor::GetPlayers())
    {
        RemoveData(p.second);
    }
}

static std::map<uint32_t, TSMapDataExtra*> mapData;
TSMapDataExtra* GetMapDataExtra(uint32_t id)
{
    if(mapData.find(id) == mapData.end())
    {
        return (mapData[id] = new TSMapDataExtra());
    }
    else
    {
        return mapData[id];
    }
}

/** Network events */

void RegisterMessage(uint32_t modid, uint16_t opcode, uint8_t size, std::function<std::shared_ptr<void>(uint8_t*)> constructor)
{
    if(messageModMap.find(modid)==messageModMap.end())
    {
        messageModMap[modid] = std::vector<uint16_t>();
    }
    (&messageModMap[modid])->push_back(opcode);


    if(opcode>=messageMap.size())
    {
        messageMap.resize(opcode+1);
    }

    messageMap[opcode] = MessageHandle<void>(size,constructor);
}

MessageHandle<void>* GetMessage(uint16_t opcode)
{
    return &messageMap[opcode];
}

bool handleAddonNetworkMessage(Player* player,uint32 type,uint32 lang,std::string& msg,Player* receiver)
{
    if(player!=receiver) { return false; }

    char * carr = const_cast<char*>(msg.c_str());
    if(msg.size()<=5) { return false; }

    if(((uint32_t*)(carr+1))[0] != 1346455379)
    {
        return false;
    }

    uint8_t outarr[250];

    int outlen = decodeBase64((uint8_t*)(carr+1),msg.size()-1,outarr);

    BinReader<uint8_t> reader(outarr,outlen);
    FIRE(AddonOnMessage,reader);

    if(outlen<=6) { return false; }

    if(reader.Read<uint32_t>(0)!=1007688) { return false; }

    uint16_t opcode = reader.Read<uint16_t>(4);
    if(opcode>=getMessageMap().size()) { return true; }

    auto handler = &getMessageMap()[opcode];
    if(handler->size!=(outlen-6) || !handler->enabled) { return true; }

    handler->fire(TSPlayer(player),outarr+6);
    return true;
}

void AddMessageListener(uint16_t opcode, void(*func)(TSPlayer,std::shared_ptr<void>))
{
    if(opcode>=messageMap.size()) { return; }
    (&messageMap[opcode])->listeners.push_back(func);
}

static std::map<TSString, IDRange> tables;
IDRange GetIDRange(TSString table, TSString mod, TSString name)
{
    auto fn = table+JSTR(":")+mod+JSTR(":")+name;
    std::map<TSString, IDRange>::iterator it = tables.find(fn);
    if(it != tables.end())
    {
        return it->second;
    }
    return IDRange(0,0);
}

uint32 GetID(TSString table, TSString mod, TSString name)
{
    return GetIDRange(table,mod,name).low;
}

void LoadIDs()
{
    tables.clear();

    int stage = 0;
    char curstr[128];
    int strlen = 0;
    int namepos = 0;
    int lowpos = 0;
    int hipos = 0;

    auto data_str = sConfigMgr
        ->GetStringDefault("DataDir","../../datasets/default");
    auto data_dir =
          boost::filesystem::path(data_str)
        / boost::filesystem::path("ids.txt");

    std::ifstream t(data_dir.string().c_str());
    if (!t.good()) return;

    std::stringstream buffer;
    buffer << t.rdbuf();
    std::string str = buffer.str();
    t.close();
    buffer.clear();

    for (int i = 0; i < str.size(); ++i) {
        char& chr = str[i];
        if (chr != '|') {
            curstr[strlen++] = chr;
            continue;
        }

        switch (stage) {
        case 0:
            curstr[strlen++] = NULL;
            namepos = strlen;
            break;
        case 1:
            curstr[strlen++] = NULL;
            lowpos = strlen;
            break;
        case 2:
            curstr[strlen++] = NULL;
            hipos = strlen;
            break;
        case 3:
            ++i;
            curstr[strlen] = NULL;
            TSString table = TSString(std::string(curstr));
            TSString name = TSString(table + JSTR(":") + JSTR(curstr + namepos));
            strlen = 0;
            int low = atoi(curstr + lowpos);
            int high = atoi(curstr + hipos);
            stage = -1;
            tables[name] = IDRange(low, high);
            stage = -1;
            break;
        }
        ++stage;
    }
}

void TSInitializeEvents()
{
    new TSWorldUpdater();
    TSLoadEvents();
    LoadIDs();
};
