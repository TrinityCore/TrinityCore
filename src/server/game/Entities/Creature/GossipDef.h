/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#ifndef TRINITYCORE_GOSSIP_H
#define TRINITYCORE_GOSSIP_H

#include "Common.h"
#include "QuestDef.h"
#include "NPCHandler.h"

class WorldSession;

#define GOSSIP_MAX_MENU_ITEMS 64                            // client supported items unknown, but provided number must be enough
#define DEFAULT_GOSSIP_MESSAGE              0xffffff

enum Gossip_Option
{
    GOSSIP_OPTION_NONE              = 0,                    //UNIT_NPC_FLAG_NONE                (0)
    GOSSIP_OPTION_GOSSIP            = 1,                    //UNIT_NPC_FLAG_GOSSIP              (1)
    GOSSIP_OPTION_QUESTGIVER        = 2,                    //UNIT_NPC_FLAG_QUESTGIVER          (2)
    GOSSIP_OPTION_VENDOR            = 3,                    //UNIT_NPC_FLAG_VENDOR              (128)
    GOSSIP_OPTION_TAXIVENDOR        = 4,                    //UNIT_NPC_FLAG_TAXIVENDOR          (8192)
    GOSSIP_OPTION_TRAINER           = 5,                    //UNIT_NPC_FLAG_TRAINER             (16)
    GOSSIP_OPTION_SPIRITHEALER      = 6,                    //UNIT_NPC_FLAG_SPIRITHEALER        (16384)
    GOSSIP_OPTION_SPIRITGUIDE       = 7,                    //UNIT_NPC_FLAG_SPIRITGUIDE         (32768)
    GOSSIP_OPTION_INNKEEPER         = 8,                    //UNIT_NPC_FLAG_INNKEEPER           (65536)
    GOSSIP_OPTION_BANKER            = 9,                    //UNIT_NPC_FLAG_BANKER              (131072)
    GOSSIP_OPTION_PETITIONER        = 10,                   //UNIT_NPC_FLAG_PETITIONER          (262144)
    GOSSIP_OPTION_TABARDDESIGNER    = 11,                   //UNIT_NPC_FLAG_TABARDDESIGNER      (524288)
    GOSSIP_OPTION_BATTLEFIELD       = 12,                   //UNIT_NPC_FLAG_BATTLEFIELDPERSON   (1048576)
    GOSSIP_OPTION_AUCTIONEER        = 13,                   //UNIT_NPC_FLAG_AUCTIONEER          (2097152)
    GOSSIP_OPTION_STABLEPET         = 14,                   //UNIT_NPC_FLAG_STABLE              (4194304)
    GOSSIP_OPTION_ARMORER           = 15,                   //UNIT_NPC_FLAG_ARMORER             (4096)
    GOSSIP_OPTION_UNLEARNTALENTS    = 16,                   //UNIT_NPC_FLAG_TRAINER             (16) (bonus option for GOSSIP_OPTION_TRAINER)
    GOSSIP_OPTION_UNLEARNPETTALENTS = 17,                   //UNIT_NPC_FLAG_TRAINER             (16) (bonus option for GOSSIP_OPTION_TRAINER)
    GOSSIP_OPTION_LEARNDUALSPEC     = 18,                   //UNIT_NPC_FLAG_TRAINER             (16) (bonus option for GOSSIP_OPTION_TRAINER)
    GOSSIP_OPTION_OUTDOORPVP        = 19,                   //added by code (option for outdoor pvp creatures)
    GOSSIP_OPTION_MAX
};

enum GossipOptionIcon
{
    GOSSIP_ICON_CHAT                = 0,                    // white chat bubble
    GOSSIP_ICON_VENDOR              = 1,                    // brown bag
    GOSSIP_ICON_TAXI                = 2,                    // flightmarker (paperplane)
    GOSSIP_ICON_TRAINER             = 3,                    // brown book (trainer)
    GOSSIP_ICON_INTERACT_1          = 4,                    // golden interaction wheel
    GOSSIP_ICON_INTERACT_2          = 5,                    // golden interaction wheel
    GOSSIP_ICON_MONEY_BAG           = 6,                    // brown bag (with gold coin in lower corner)
    GOSSIP_ICON_TALK                = 7,                    // white chat bubble (with "..." inside)
    GOSSIP_ICON_TABARD              = 8,                    // white tabard
    GOSSIP_ICON_BATTLE              = 9,                    // two crossed swords
    GOSSIP_ICON_DOT                 = 10,                   // yellow dot/point
    GOSSIP_ICON_CHAT_11             = 11,                   // white chat bubble
    GOSSIP_ICON_CHAT_12             = 12,                   // white chat bubble
    GOSSIP_ICON_CHAT_13             = 13,                   // white chat bubble
    GOSSIP_ICON_UNK_14              = 14,                   // INVALID - DO NOT USE
    GOSSIP_ICON_UNK_15              = 15,                   // INVALID - DO NOT USE
    GOSSIP_ICON_CHAT_16             = 16,                   // white chat bubble
    GOSSIP_ICON_CHAT_17             = 17,                   // white chat bubble
    GOSSIP_ICON_CHAT_18             = 18,                   // white chat bubble
    GOSSIP_ICON_CHAT_19             = 19,                   // white chat bubble
    GOSSIP_ICON_CHAT_20             = 20,                   // white chat bubble
    GOSSIP_ICON_MAX
};

//POI icons. Many more exist, list not complete.
enum Poi_Icon
{
    ICON_POI_BLANK              =   0,                      // Blank (not visible)
    ICON_POI_GREY_AV_MINE       =   1,                      // Grey mine lorry
    ICON_POI_RED_AV_MINE        =   2,                      // Red mine lorry
    ICON_POI_BLUE_AV_MINE       =   3,                      // Blue mine lorry
    ICON_POI_BWTOMB             =   4,                      // Blue and White Tomb Stone
    ICON_POI_SMALL_HOUSE        =   5,                      // Small house
    ICON_POI_GREYTOWER          =   6,                      // Grey Tower
    ICON_POI_REDFLAG            =   7,                      // Red Flag w/Yellow !
    ICON_POI_TOMBSTONE          =   8,                      // Normal tomb stone (brown)
    ICON_POI_BWTOWER            =   9,                      // Blue and White Tower
    ICON_POI_REDTOWER           =   10,                     // Red Tower
    ICON_POI_BLUETOWER          =   11,                     // Blue Tower
    ICON_POI_RWTOWER            =   12,                     // Red and White Tower
    ICON_POI_REDTOMB            =   13,                     // Red Tomb Stone
    ICON_POI_RWTOMB             =   14,                     // Red and White Tomb Stone
    ICON_POI_BLUETOMB           =   15,                     // Blue Tomb Stone
    ICON_POI_16                 =   16,                     // Grey ?
    ICON_POI_17                 =   17,                     // Blue/White ?
    ICON_POI_18                 =   18,                     // Blue ?
    ICON_POI_19                 =   19,                     // Red and White ?
    ICON_POI_20                 =   20,                     // Red ?
    ICON_POI_GREYLOGS           =   21,                     // Grey Wood Logs
    ICON_POI_BWLOGS             =   22,                     // Blue and White Wood Logs
    ICON_POI_BLUELOGS           =   23,                     // Blue Wood Logs
    ICON_POI_RWLOGS             =   24,                     // Red and White Wood Logs
    ICON_POI_REDLOGS            =   25,                     // Red Wood Logs
    ICON_POI_26                 =   26,                     // Grey ?
    ICON_POI_27                 =   27,                     // Blue and White ?
    ICON_POI_28                 =   28,                     // Blue ?
    ICON_POI_29                 =   29,                     // Red and White ?
    ICON_POI_30                 =   30,                     // Red ?
    ICON_POI_GREYHOUSE          =   31,                     // Grey House
    ICON_POI_BWHOUSE            =   32,                     // Blue and White House
    ICON_POI_BLUEHOUSE          =   33,                     // Blue House
    ICON_POI_RWHOUSE            =   34,                     // Red and White House
    ICON_POI_REDHOUSE           =   35,                     // Red House
    ICON_POI_GREYHORSE          =   36,                     // Grey Horse
    ICON_POI_BWHORSE            =   37,                     // Blue and White Horse
    ICON_POI_BLUEHORSE          =   38,                     // Blue Horse
    ICON_POI_RWHORSE            =   39,                     // Red and White Horse
    ICON_POI_REDHORSE           =   40                      // Red Horse
};

struct GossipMenuItem
{
    uint8       m_gIcon;
    bool        m_gCoded;
    std::string m_gMessage;
    uint32      m_gSender;
    uint32      m_gOptionId;
    std::string m_gBoxMessage;
    uint32      m_gBoxMoney;
};

typedef std::vector<GossipMenuItem> GossipMenuItemList;

struct GossipMenuItemData
{
    uint32 m_gAction_menu;
    uint32 m_gAction_poi;
    uint32 m_gAction_script;
};

typedef std::vector<GossipMenuItemData> GossipMenuItemDataList;

struct QuestMenuItem
{
    uint32      m_qId;
    uint8       m_qIcon;
};

typedef std::vector<QuestMenuItem> QuestMenuItemList;

class GossipMenu
{
    public:
        GossipMenu();
        ~GossipMenu();

        void AddMenuItem(uint8 Icon, const std::string& Message, bool Coded = false);
        void AddMenuItem(uint8 Icon, const std::string& Message, uint32 dtSender, uint32 dtAction, const std::string& BoxMessage, uint32 BoxMoney, bool Coded = false);

        // for using from scripts, don't must be inlined
        void AddMenuItem(uint8 Icon, char const* Message, bool Coded = false);
        void AddMenuItem(uint8 Icon, char const* Message, uint32 dtSender, uint32 dtAction, char const* BoxMessage, uint32 BoxMoney, bool Coded = false);

        void SetMenuId(uint32 menu_id) { m_gMenuId = menu_id; }
        uint32 GetMenuId() const { return m_gMenuId; }

        void AddGossipMenuItemData(uint32 action_menu, uint32 action_poi, uint32 action_script);

        unsigned int MenuItemCount() const
        {
            return m_gItems.size();
        }

        bool Empty() const
        {
            return m_gItems.empty();
        }

        GossipMenuItem const& GetItem(unsigned int Id) const
        {
            return m_gItems[ Id ];
        }

        GossipMenuItemData const& GetItemData(unsigned int indexId) const
        {
            return m_gItemsData[indexId];
        }

        uint32 MenuItemSender(unsigned int ItemId);
        uint32 MenuItemAction(unsigned int ItemId);
        bool MenuItemCoded(unsigned int ItemId);

        void ClearMenu();

    protected:
        GossipMenuItemList      m_gItems;
        GossipMenuItemDataList  m_gItemsData;

        uint32 m_gMenuId;
};

class QuestMenu
{
    public:
        QuestMenu();
        ~QuestMenu();

        void AddMenuItem(uint32 QuestId, uint8 Icon);
        void ClearMenu();

        uint8 MenuItemCount() const
        {
            return m_qItems.size();
        }

        bool Empty() const
        {
            return m_qItems.empty();
        }

        bool HasItem(uint32 questid);

        QuestMenuItem const& GetItem(uint16 Id) const
        {
            return m_qItems[ Id ];
        }

    protected:
        QuestMenuItemList m_qItems;
};

class PlayerMenu
{
    private:
        GossipMenu mGossipMenu;
        QuestMenu  mQuestMenu;
        WorldSession* pSession;

    public:
        PlayerMenu(WorldSession *Session);
        ~PlayerMenu();

        GossipMenu& GetGossipMenu() { return mGossipMenu; }
        QuestMenu& GetQuestMenu() { return mQuestMenu; }

        bool Empty() const { return mGossipMenu.Empty() && mQuestMenu.Empty(); }

        void ClearMenus();
        uint32 GossipOptionSender(unsigned int Selection);
        uint32 GossipOptionAction(unsigned int Selection);
        bool GossipOptionCoded(unsigned int Selection);

        void SendGossipMenu(uint32 TitleTextId, uint64 npcGUID);
        void CloseGossip();
        void SendPointOfInterest(float X, float Y, uint32 Icon, uint32 Flags, uint32 Data, const char * locName);
        void SendPointOfInterest(uint32 poi_id);
        void SendTalking(uint32 textID);
        void SendTalking(char const * title, char const * text);

        /*********************************************************/
        /***                    QUEST SYSTEM                   ***/
        /*********************************************************/
        void SendQuestGiverStatus(uint8 questStatus, uint64 npcGUID);

        void SendQuestGiverQuestList(QEmote eEmote, const std::string& Title, uint64 npcGUID);

        void SendQuestQueryResponse (Quest const *pQuest);
        void SendQuestGiverQuestDetails(Quest const *pQuest, uint64 npcGUID, bool ActivateAccept);

        void SendQuestGiverOfferReward(Quest const* pQuest, uint64 npcGUID, bool EnableNext);
        void SendQuestGiverRequestItems(Quest const *pQuest, uint64 npcGUID, bool Completable, bool CloseOnCancel);
};
#endif
