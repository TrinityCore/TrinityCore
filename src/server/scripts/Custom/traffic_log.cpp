//#include "ScriptMgr.h"
//#include "ObjectMgr.h"
//#include "Chat.h"
//#include "World.h"
//
//class Value
//{
//public:
//    uint32 pos;
//    uint64 value;
//    Value(uint32 p, uint64 v) : pos(p), value(v) {}
//};
//
//struct member_less : public std::binary_function<Value, Value, bool>
//{
//    bool operator()(const Value& m1, const Value& m2) const
//    {
//        return m1.value > m2.value;
//    }
//};
//
//class traffic_commandscript : public CommandScript
//{
//public:
//    traffic_commandscript() : CommandScript("traffic_commandscript") { }
//
//    ChatCommand* GetCommands() const override
//    {
//        static ChatCommand byCommandTable[] =
//        {
//            { "avg",                          SEC_ADMINISTRATOR, false, &HandleTrafficByAvgCommand,    "", NULL },
//            { "size",                         SEC_ADMINISTRATOR, false, &HandleTrafficBySizeCommand,   "", NULL },
//            { "count",                        SEC_ADMINISTRATOR, false, &HandleTrafficByCountCommand,  "", NULL },
//            { NULL,                           0,                 false, NULL,                          "", NULL }
//        };
//
//        static ChatCommand trafficCommandTable[] =
//        {
//            { "by",                           SEC_ADMINISTRATOR, false, NULL,                   "", byCommandTable },
//            { NULL,                           0,                 false, NULL,                   "", NULL }
//        };
//
//        static ChatCommand commandTable[] =
//        {
//            { "traffic",        SEC_ADMINISTRATOR,  false, NULL,                               "", trafficCommandTable },
//            { NULL,             0,                  false, NULL,                               "", NULL }
//        };
//        return commandTable;
//    }
//
//    static bool HandleTrafficByAvgCommand(ChatHandler* handler, const char* args)
//    {
//        if (!*args)
//            return false;
//
//        handler->PSendSysMessage("Sended data order by average value:");
//
//        uint32 size = atoi((char*)args);
//
//        std::vector<Value> v;
//        {
//            static std::mutex lock;
//            std::lock_guard<std::mutex> guard(lock);
//
//            for (uint32 i = 0; i < OPCODE_COUNT; ++i)
//                v.push_back(Value(i, World::SendCount[i] ? float(World::SendSize[i]) / World::SendCount[i] : 0));
//        }
//
//        std::sort(v.begin(), v.end(), member_less());
//
//        uint32 i = 0;
//        std::vector<Value>::iterator itr = v.begin();
//        while (itr != v.end() && i < size)
//        {
//            handler->PSendSysMessage("%i: 0x%x(%s); Value: %u;", i + 1, (*itr).pos, GetOpcodeNameForLogging(static_cast<OpcodeServer>((*itr).pos)).c_str(), (*itr).value);
//            itr++;
//            i++;
//        }
//
//        return true;
//    }
//
//    static bool HandleTrafficBySizeCommand(ChatHandler* handler, const char* args)
//    {
//        if (!*args)
//            return false;
//
//        handler->PSendSysMessage("Sended data order by size value:");
//
//        uint32 size = atoi((char*)args);
//
//        std::vector<Value> v;
//        {
//            static std::mutex lock;
//            std::lock_guard<std::mutex> guard(lock);
//
//            for (uint32 i = 0; i < OPCODE_COUNT; ++i)
//                v.push_back(Value(i, World::SendSize[i]));
//        }
//
//        std::sort(v.begin(), v.end(), member_less());
//
//        uint32 i = 0;
//        std::vector<Value>::iterator itr = v.begin();
//        while (itr != v.end() && i < size)
//        {
//            handler->PSendSysMessage("%i: 0x%x(%s); Value: %f(mb);", i + 1, (*itr).pos, GetOpcodeNameForLogging(static_cast<OpcodeServer>((*itr).pos)).c_str(), float((*itr).value) / 1024.f / 1024.f);
//            itr++;
//            i++;
//        }
//
//        return true;
//    }
//
//    static bool HandleTrafficByCountCommand(ChatHandler* handler, const char* args)
//    {
//        if (!*args)
//            return false;
//
//        handler->PSendSysMessage("Sended data order by count value:");
//
//        uint32 size = atoi((char*)args);
//
//        std::vector<Value> v;
//        {
//            static std::mutex lock;
//            std::lock_guard<std::mutex> guard(lock);
//
//            for (uint32 i = 0; i < OPCODE_COUNT; ++i)
//                v.push_back(Value(i, World::SendCount[i]));
//        }
//
//        std::sort(v.begin(), v.end(), member_less());
//
//        uint32 i = 0;
//        std::vector<Value>::iterator itr = v.begin();
//        while (itr != v.end() && i < size)
//        {
//            handler->PSendSysMessage("%i: 0x%x(%s); Value: %u;", i + 1, (*itr).pos, GetOpcodeNameForLogging(static_cast<OpcodeServer>((*itr).pos)).c_str(), (*itr).value);
//            itr++;
//            i++;
//        }
//
//        return true;
//    }
//
//};
//
//void AddSC_traffic_commandscript()
//{
//    new traffic_commandscript();
//}
