#pragma once

#include "Define.h"

#include <unordered_map>

struct TeleporterStoneTable
{
    std::string     Text;
    std::string     ConfirmText;
    uint32          GossipMenuIcon;
    int32           RefID;
    uint32          HardCodedID;
    uint32          RequiredVIPLevel;
    uint32          RequiredMG;
    uint32          MapID;
    float           X;
    float           Y;
    float           Z;
    float           O;
    std::vector<uint32>     IncludeIds;
};

class TeleporterStoneMgr
{
public:
    static TeleporterStoneMgr* instance()
    {
        static TeleporterStoneMgr l_Instance;
        return &l_Instance;
    }

    void LoadFromDatabase(bool p_Reload = false);

    TeleporterStoneTable const* GetDataForId(uint32 p_ID);

    std::unordered_map<int32, TeleporterStoneTable>& GetAllData()
    {
        return m_TeleporterStoneData;
    }

private:
    std::unordered_map<int32, TeleporterStoneTable> m_TeleporterStoneData;
};

#define sTeleporterStoneMgr TeleporterStoneMgr::instance()
