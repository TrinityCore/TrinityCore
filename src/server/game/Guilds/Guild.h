/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITYCORE_GUILD_H
#define TRINITYCORE_GUILD_H

#define WITHDRAW_MONEY_UNLIMITED    0xFFFFFFFF
#define WITHDRAW_SLOT_UNLIMITED     0xFFFFFFFF

#include "Item.h"

class Item;

#define GUILD_RANKS_MIN_COUNT   5
#define GUILD_RANKS_MAX_COUNT   10

enum GuildDefaultRanks
{
    //these ranks can be modified, but they cannot be deleted
    GR_GUILDMASTER  = 0,
    GR_OFFICER      = 1,
    GR_VETERAN      = 2,
    GR_MEMBER       = 3,
    GR_INITIATE     = 4,
    //When promoting member server does: rank--;!
    //When demoting member server does: rank++;!
};

enum GuildRankRights
{
    GR_RIGHT_EMPTY              = 0x00000040,
    GR_RIGHT_GCHATLISTEN        = 0x00000041,
    GR_RIGHT_GCHATSPEAK         = 0x00000042,
    GR_RIGHT_OFFCHATLISTEN      = 0x00000044,
    GR_RIGHT_OFFCHATSPEAK       = 0x00000048,
    GR_RIGHT_PROMOTE            = 0x000000C0,
    GR_RIGHT_DEMOTE             = 0x00000140,
    GR_RIGHT_INVITE             = 0x00000050,
    GR_RIGHT_REMOVE             = 0x00000060,
    GR_RIGHT_SETMOTD            = 0x00001040,
    GR_RIGHT_EPNOTE             = 0x00002040,
    GR_RIGHT_VIEWOFFNOTE        = 0x00004040,
    GR_RIGHT_EOFFNOTE           = 0x00008040,
    GR_RIGHT_MODIFY_GUILD_INFO  = 0x00010040,
    GR_RIGHT_WITHDRAW_GOLD_LOCK = 0x00020000,               // remove money withdraw capacity
    GR_RIGHT_WITHDRAW_REPAIR    = 0x00040000,               // withdraw for repair
    GR_RIGHT_WITHDRAW_GOLD      = 0x00080000,               // withdraw gold
    GR_RIGHT_CREATE_GUILD_EVENT = 0x00100000,               // wotlk
    GR_RIGHT_ALL                = 0x001DF1FF
};

enum Typecommand
{
    GUILD_CREATE_S  = 0x00,
    GUILD_INVITE_S  = 0x01,
    GUILD_QUIT_S    = 0x03,
    GUILD_FOUNDER_S = 0x0E,
    GUILD_UNK1      = 0x13,
    GUILD_UNK2      = 0x14
};

enum CommandErrors
{
    ERR_PLAYER_NO_MORE_IN_GUILD     = 0x00,
    ERR_GUILD_INTERNAL              = 0x01,
    ERR_ALREADY_IN_GUILD            = 0x02,
    ERR_ALREADY_IN_GUILD_S          = 0x03,
    ERR_INVITED_TO_GUILD            = 0x04,
    ERR_ALREADY_INVITED_TO_GUILD_S  = 0x05,
    ERR_GUILD_NAME_INVALID          = 0x06,
    ERR_GUILD_NAME_EXISTS_S         = 0x07,
    ERR_GUILD_LEADER_LEAVE          = 0x08,
    ERR_GUILD_PERMISSIONS           = 0x08,
    ERR_GUILD_PLAYER_NOT_IN_GUILD   = 0x09,
    ERR_GUILD_PLAYER_NOT_IN_GUILD_S = 0x0A,
    ERR_GUILD_PLAYER_NOT_FOUND_S    = 0x0B,
    ERR_GUILD_NOT_ALLIED            = 0x0C,
    ERR_GUILD_RANK_TOO_HIGH_S       = 0x0D,
    ERR_GUILD_RANK_TOO_LOW_S        = 0x0E,
    ERR_GUILD_RANKS_LOCKED          = 0x11,
    ERR_GUILD_RANK_IN_USE           = 0x12,
    ERR_GUILD_IGNORING_YOU_S        = 0x13,
    ERR_GUILD_UNK1                  = 0x14,
    ERR_GUILD_WITHDRAW_LIMIT        = 0x19,
    ERR_GUILD_NOT_ENOUGH_MONEY      = 0x1A,
    ERR_GUILD_BANK_FULL             = 0x1C,
    ERR_GUILD_ITEM_NOT_FOUND        = 0x1D
};

enum GuildEvents
{
    GE_PROMOTION                    = 0x00,
    GE_DEMOTION                     = 0x01,
    GE_MOTD                         = 0x02,
    GE_JOINED                       = 0x03,
    GE_LEFT                         = 0x04,
    GE_REMOVED                      = 0x05,
    GE_LEADER_IS                    = 0x06,
    GE_LEADER_CHANGED               = 0x07,
    GE_DISBANDED                    = 0x08,
    GE_TABARDCHANGE                 = 0x09,
    GE_UNK1                         = 0x0A,                 // string, string EVENT_GUILD_ROSTER_UPDATE tab content change?
    GE_UNK2                         = 0x0B,                 // EVENT_GUILD_ROSTER_UPDATE
    GE_SIGNED_ON                    = 0x0C,                 // ERR_FRIEND_ONLINE_SS
    GE_SIGNED_OFF                   = 0x0D,                 // ERR_FRIEND_OFFLINE_S
    GE_GUILDBANKBAGSLOTS_CHANGED    = 0x0E,                 // EVENT_GUILDBANKBAGSLOTS_CHANGED
    GE_BANKTAB_PURCHASED            = 0x0F,                 // EVENT_GUILDBANK_UPDATE_TABS
    GE_UNK5                         = 0x10,                 // EVENT_GUILDBANK_UPDATE_TABS
    GE_GUILDBANK_UPDATE_MONEY       = 0x11,                 // EVENT_GUILDBANK_UPDATE_MONEY, string 0000000000002710 is 1 gold
    GE_GUILD_BANK_MONEY_WITHDRAWN   = 0x12,                 // MSG_GUILD_BANK_MONEY_WITHDRAWN
    GE_GUILDBANK_TEXT_CHANGED       = 0x13                  // EVENT_GUILDBANK_TEXT_CHANGED
};

enum PetitionTurns
{
    PETITION_TURN_OK                    = 0,
    PETITION_TURN_ALREADY_IN_GUILD      = 2,
    PETITION_TURN_NEED_MORE_SIGNATURES  = 4,
};

enum PetitionSigns
{
    PETITION_SIGN_OK                = 0,
    PETITION_SIGN_ALREADY_SIGNED    = 1,
    PETITION_SIGN_ALREADY_IN_GUILD  = 2,
    PETITION_SIGN_CANT_SIGN_OWN     = 3,
    PETITION_SIGN_NOT_SERVER        = 4,
};

enum GuildBankRights
{
    GUILD_BANK_RIGHT_VIEW_TAB       = 0x01,
    GUILD_BANK_RIGHT_PUT_ITEM       = 0x02,
    GUILD_BANK_RIGHT_UPDATE_TEXT    = 0x04,

    GUILD_BANK_RIGHT_DEPOSIT_ITEM   = GUILD_BANK_RIGHT_VIEW_TAB | GUILD_BANK_RIGHT_PUT_ITEM,
    GUILD_BANK_RIGHT_FULL           = 0xFF,
};

enum GuildBankEventLogTypes
{
    GUILD_BANK_LOG_DEPOSIT_ITEM     = 1,
    GUILD_BANK_LOG_WITHDRAW_ITEM    = 2,
    GUILD_BANK_LOG_MOVE_ITEM        = 3,
    GUILD_BANK_LOG_DEPOSIT_MONEY    = 4,
    GUILD_BANK_LOG_WITHDRAW_MONEY   = 5,
    GUILD_BANK_LOG_REPAIR_MONEY     = 6,
    GUILD_BANK_LOG_MOVE_ITEM2       = 7,
    GUILD_BANK_LOG_UNK1             = 8,
    GUILD_BANK_LOG_UNK2             = 9,
};

enum GuildEventLogTypes
{
    GUILD_EVENT_LOG_INVITE_PLAYER     = 1,
    GUILD_EVENT_LOG_JOIN_GUILD        = 2,
    GUILD_EVENT_LOG_PROMOTE_PLAYER    = 3,
    GUILD_EVENT_LOG_DEMOTE_PLAYER     = 4,
    GUILD_EVENT_LOG_UNINVITE_PLAYER   = 5,
    GUILD_EVENT_LOG_LEAVE_GUILD       = 6,
};

enum GuildEmblem
{
    ERR_GUILDEMBLEM_SUCCESS               = 0,
    ERR_GUILDEMBLEM_INVALID_TABARD_COLORS = 1,
    ERR_GUILDEMBLEM_NOGUILD               = 2,
    ERR_GUILDEMBLEM_NOTGUILDMASTER        = 3,
    ERR_GUILDEMBLEM_NOTENOUGHMONEY        = 4,
    ERR_GUILDEMBLEM_INVALIDVENDOR         = 5
};

inline uint32 GetGuildBankTabPrice(uint8 Index)
{
    switch(Index)
    {
        case 0: return 100;
        case 1: return 250;
        case 2: return 500;
        case 3: return 1000;
        case 4: return 2500;
        case 5: return 5000;
        default:
            return 0;
    }
}

struct GuildEventLogEntry
{
    uint8  EventType;
    uint32 PlayerGuid1;
    uint32 PlayerGuid2;
    uint8  NewRank;
    uint64 TimeStamp;
};

struct GuildBankEventLogEntry
{
    uint8  EventType;
    uint32 PlayerGuid;
    uint32 ItemOrMoney;
    uint16  ItemStackCount;
    uint8  DestTabId;
    uint64 TimeStamp;

    bool isMoneyEvent()
    {
        return EventType == GUILD_BANK_LOG_DEPOSIT_MONEY ||
            EventType == GUILD_BANK_LOG_WITHDRAW_MONEY ||
            EventType == GUILD_BANK_LOG_REPAIR_MONEY;
    }
};

struct GuildBankTab
{
    GuildBankTab() { memset(Slots, 0, GUILD_BANK_MAX_SLOTS * sizeof(Item*)); }

    Item* Slots[GUILD_BANK_MAX_SLOTS];
    std::string Name;
    std::string Icon;
    std::string Text;
};

struct GuildItemPosCount
{
    GuildItemPosCount(uint8 _slot, uint32 _count) : Slot(_slot), Count(_count) {}

    bool isContainedIn(std::vector<GuildItemPosCount> const& vec) const;

    uint8 Slot;
    uint32 Count;
};
typedef std::vector<GuildItemPosCount> GuildItemPosCountVec;

struct MemberSlot
{
    uint64 LogoutTime;
    uint32 accountId;
    std::string Name;
    std::string Pnote;
    std::string OFFnote;
    uint32 RankId;
    uint32 ZoneId;
    uint8 Level;
    uint8 Class;
    uint32 BankResetTimeMoney;
    uint32 BankRemMoney;
    uint32 BankResetTimeTab[GUILD_BANK_MAX_TABS];
    uint32 BankRemSlotsTab[GUILD_BANK_MAX_TABS];
};

struct RankInfo
{
    RankInfo(const std::string& _name, uint32 _rights, uint32 _money) : Name(_name), Rights(_rights), BankMoneyPerDay(_money)
    {
        for (uint8 i = 0; i < GUILD_BANK_MAX_TABS; ++i)
        {
            TabRight[i] = 0;
            TabSlotPerDay[i] = 0;
        }
    }

    std::string Name;
    uint32 Rights;
    uint32 BankMoneyPerDay;
    uint32 TabRight[GUILD_BANK_MAX_TABS];
    uint32 TabSlotPerDay[GUILD_BANK_MAX_TABS];
};

class Guild
{
    friend class ObjectMgr;
    public:
        Guild();
        ~Guild();

        bool Create(Player* leader, std::string gname);
        void CreateDefaultGuildRanks(LocaleConstant locale_idx);
        void Disband();

        void DeleteGuildBankItems(SQLTransaction& trans, bool alsoInDB = false);
        typedef std::map<uint32, MemberSlot> MemberList;
        typedef std::vector<RankInfo> RankList;

        uint32 GetId(){ return m_Id; }
        const uint64& GetLeader(){ return m_LeaderGuid; }
        std::string const& GetName() const { return m_Name; }
        std::string const& GetMOTD() const { return MOTD; }
        std::string const& GetGINFO() const { return GINFO; }

        time_t GetCreatedDate() const { return m_CreatedDate; }

        uint32 GetEmblemStyle() const { return m_EmblemStyle; }
        uint32 GetEmblemColor() const { return m_EmblemColor; }
        uint32 GetBorderStyle() const { return m_BorderStyle; }
        uint32 GetBorderColor() const { return m_BorderColor; }
        uint32 GetBackgroundColor() const { return m_BackgroundColor; }

        void SetLeader(uint64 guid);
        bool AddMember(uint64 plGuid, uint32 plRank);
        void ChangeRank(uint64 guid, uint32 newRank);
        void DelMember(uint64 guid, bool isDisbanding = false, bool isKicked = false);
        //lowest rank is the count of ranks - 1 (the highest rank_id in table)
        uint32 GetLowestRank() const { return m_Ranks.size() - 1; }

        void SetMOTD(std::string motd);
        void SetGINFO(std::string ginfo);
        void SetPNOTE(uint64 guid, std::string pnote);
        void SetOFFNOTE(uint64 guid, std::string offnote);
        void SetEmblem(uint32 emblemStyle, uint32 emblemColor, uint32 borderStyle, uint32 borderColor, uint32 backgroundColor);

        uint32 GetMemberSize() const { return members.size(); }
        uint32 GetAccountsNumber() const { return m_accountsNumber; }

        bool LoadGuildFromDB(QueryResult guildDataResult);
        bool CheckGuildStructure();
        bool LoadRanksFromDB(QueryResult guildRanksResult);
        bool LoadMembersFromDB(QueryResult guildMembersResult);

        void SetMemberStats(uint64 guid);

        void BroadcastToGuild(WorldSession *session, const std::string& msg, uint32 language = LANG_UNIVERSAL);
        void BroadcastToOfficers(WorldSession *session, const std::string& msg, uint32 language = LANG_UNIVERSAL);
        void BroadcastPacketToRank(WorldPacket *packet, uint32 rankId);
        void BroadcastPacket(WorldPacket *packet);
        void BroadcastEvent(GuildEvents event, uint64 guid, uint8 strCount, std::string str1, std::string str2, std::string str3);

        template<class Do>
        void BroadcastWorker(Do& _do, Player* except = NULL)
        {
            for (MemberList::iterator itr = members.begin(); itr != members.end(); ++itr)
                if (Player *player = ObjectAccessor::FindPlayer(MAKE_NEW_GUID(itr->first, 0, HIGHGUID_PLAYER)))
                    if (player != except)
                        _do(player);
        }

        void CreateRank(std::string name,uint32 rights);
        void DelRank();
        std::string GetRankName(uint32 rankId);
        uint32 GetRankRights(uint32 rankId);
        uint32 GetRanksSize() const { return m_Ranks.size(); }

        void SetRankName(uint32 rankId, std::string name);
        void SetRankRights(uint32 rankId, uint32 rights);
        bool HasRankRight(uint32 rankId, uint32 right)
        {
            return ((GetRankRights(rankId) & right) != GR_RIGHT_EMPTY) ? true : false;
        }
        int32 GetRank(uint32 LowGuid);
        bool IsMember(uint32 LowGuid)
        {
            return (members.find(LowGuid) != members.end());
        }
        MemberSlot* GetMemberSlot(const std::string& name, uint64& guid)
        {
            for (MemberList::iterator itr = members.begin(); itr != members.end(); ++itr)
            {
                if (itr->second.Name == name)
                {
                    guid = itr->first;
                    return &itr->second;
                }
            }
            return NULL;
        }

        void Roster(WorldSession *session = NULL);          // NULL = broadcast
        void Query(WorldSession *session);

        void   UpdateLogoutTime(uint64 guid);
        // Guild EventLog
        void   DisplayGuildEventLog(WorldSession *session);
        void   LogGuildEvent(uint8 EventType, uint32 PlayerGuid1, uint32 PlayerGuid2, uint8 NewRank);

        // ** Guild bank **
        // Content & item deposit/withdraw
        void   DisplayGuildBankContent(WorldSession *session, uint8 TabId);
        void   DisplayGuildBankMoneyUpdate(WorldSession *session);

        void   SwapItems(Player * pl, uint8 BankTab, uint8 BankTabSlot, uint8 BankTabDst, uint8 BankTabSlotDst, uint32 SplitedAmount);
        void   MoveFromBankToChar(Player * pl, uint8 BankTab, uint8 BankTabSlot, uint8 PlayerBag, uint8 PlayerSlot, uint32 SplitedAmount);
        void   MoveFromCharToBank(Player * pl, uint8 PlayerBag, uint8 PlayerSlot, uint8 BankTab, uint8 BankTabSlot, uint32 SplitedAmount);

        // Tabs
        void   DisplayGuildBankTabsInfo(WorldSession *session);
        void   CreateNewBankTab();
        void   SetGuildBankTabText(uint8 TabId, std::string text);
        void   SendGuildBankTabText(WorldSession *session, uint8 TabId);
        void   SetGuildBankTabInfo(uint8 TabId, std::string name, std::string icon);
        uint8  GetPurchasedTabs() const { return m_TabListMap.size(); }
        uint32 GetBankRights(uint32 rankId, uint8 TabId) const;
        bool   IsMemberHaveRights(uint32 LowGuid, uint8 TabId,uint32 rights) const;
        bool   CanMemberViewTab(uint32 LowGuid, uint8 TabId) const;
        // Money deposit/withdraw
        void   SendMoneyInfo(WorldSession *session, uint32 LowGuid);
        bool   MemberMoneyWithdraw(uint32 amount, uint32 LowGuid, SQLTransaction& trans);
        uint64 GetGuildBankMoney() { return m_GuildBankMoney; }
        void   SetBankMoney(int64 money, SQLTransaction& trans);
        // per days
        bool   MemberItemWithdraw(uint8 TabId, uint32 LowGuid, SQLTransaction& trans);
        uint32 GetMemberSlotWithdrawRem(uint32 LowGuid, uint8 TabId);
        uint32 GetMemberMoneyWithdrawRem(uint32 LowGuid);
        void   SetBankMoneyPerDay(uint32 rankId, uint32 money);
        void   SetBankRightsAndSlots(uint32 rankId, uint8 TabId, uint32 right, uint32 SlotPerDay, bool db);
        uint32 GetBankMoneyPerDay(uint32 rankId);
        uint32 GetBankSlotPerDay(uint32 rankId, uint8 TabId);
        // rights per day
        bool   LoadBankRightsFromDB(QueryResult guildBankTabRightsResult);
        // Guild Bank Event Logs
        void   DisplayGuildBankLogs(WorldSession *session, uint8 TabId);
        void   LogBankEvent(SQLTransaction& trans, uint8 EventType, uint8 TabId, uint32 PlayerGuidLow, uint32 ItemOrMoney, uint16 ItemStackCount=0, uint8 DestTabId=0);
        bool   AddGBankItemToDB(uint32 GuildId, uint32 BankTab , uint32 BankTabSlot , uint32 GUIDLow, uint32 Entry, SQLTransaction& trans);

    protected:
        void AddRank(const std::string& name,uint32 rights,uint32 money);

        uint32 m_Id;
        std::string m_Name;
        uint64 m_LeaderGuid;
        std::string MOTD;
        std::string GINFO;
        time_t m_CreatedDate;

        uint32 m_EmblemStyle;
        uint32 m_EmblemColor;
        uint32 m_BorderStyle;
        uint32 m_BorderColor;
        uint32 m_BackgroundColor;
        uint32 m_accountsNumber;

        RankList m_Ranks;

        MemberList members;

        typedef std::vector<GuildBankTab*> TabListMap;
        TabListMap m_TabListMap;

        /** These are actually ordered lists. The first element is the oldest entry.*/
        typedef std::list<GuildEventLogEntry> GuildEventLog;
        typedef std::list<GuildBankEventLogEntry> GuildBankEventLog;
        GuildEventLog m_GuildEventLog;
        GuildBankEventLog m_GuildBankEventLog_Money;
        GuildBankEventLog m_GuildBankEventLog_Item[GUILD_BANK_MAX_TABS];

        uint32 m_GuildEventLogNextGuid;
        uint32 m_GuildBankEventLogNextGuid_Money;
        uint32 m_GuildBankEventLogNextGuid_Item[GUILD_BANK_MAX_TABS];

        uint64 m_GuildBankMoney;

    private:
        void UpdateAccountsNumber();
        // used only from high level Swap/Move functions
        Item*  GetItem(uint8 TabId, uint8 SlotId);
        uint8  CanStoreItem(uint8 tab, uint8 slot, GuildItemPosCountVec& dest, uint32 count, Item *pItem, bool swap = false) const;
        Item*  StoreItem(uint8 tab, GuildItemPosCountVec const& pos, Item *pItem, SQLTransaction& trans);
        void   RemoveItem(uint8 tab, uint8 slot, SQLTransaction& trans);
        void   DisplayGuildBankContentUpdate(uint8 TabId, int32 slot1, int32 slot2 = -1);
        void   DisplayGuildBankContentUpdate(uint8 TabId, GuildItemPosCountVec const& slots);

        // internal common parts for CanStore/StoreItem functions
        void AppendDisplayGuildBankSlot(WorldPacket& data, GuildBankTab const *tab, int32 slot);
        uint8 _CanStoreItem_InSpecificSlot(uint8 tab, uint8 slot, GuildItemPosCountVec& dest, uint32& count, bool swap, Item *pSrcItem) const;
        uint8 _CanStoreItem_InTab(uint8 tab, GuildItemPosCountVec& dest, uint32& count, bool merge, Item *pSrcItem, uint8 skip_slot) const;
        Item* _StoreItem(uint8 tab, uint8 slot, Item *pItem, uint32 count, bool clone, SQLTransaction& trans);
};
#endif
