
#ifndef _CUSTOM_TALK_MENU_H_
#define _CUSTOM_TALK_MENU_H_

#include "Common.h"
#include "Log.h"
#include "DatabaseEnv.h"
#include "Player.h"

enum MenuFunction
{
    MENUF_POP = 0,
    MENUF_TELEPORT,
    MENUF_NPC,
    MENUF_SPELL,
    MENUF_AURA,
    MENUF_ITEM,
    MENUF_INTERFACE,
    MENUF_POLYMORPH,
    MENUF_ARENALIST
};

struct CustomItem
{
    uint32 entry;
    uint32 menu;
    uint32 func;
    uint32 mask;
    uint32 level;
    std::string name;
    float param1;
    float param2;
    float param3;
    float param4;
    float param5;
    uint32 price;

    CustomItem(uint32 id, uint32 m, uint32 f, uint32 ma, uint32 lv, std::string& na, float p1, float p2, float p3, float p4, float p5, uint32 pri)
    {
        entry = id;
        menu = m;
        func = f;
        mask = ma;
        level = lv;
        name = na;
        param1 = p1;
        param2 = p2;
        param3 = p3;
        param4 = p4;
        param5 = p5;
        price = pri;
    }
};

typedef std::vector<CustomItem*> DisplayItems;

struct PlayerMenuState
{
    ObjectGuid playerGUID;
    DisplayItems items;

    PlayerMenuState(ObjectGuid& guid) : playerGUID(guid) {}
};

class CustomTalkMenu
{
    typedef std::map<uint32, CustomItem*> CustomTalkMenuItems;
    typedef std::map<ObjectGuid, PlayerMenuState*> PlayerMenuStates;

private:
    CustomTalkMenu() {}
    ~CustomTalkMenu();

public:
    CustomTalkMenu(CustomTalkMenu const&) = delete;
    CustomTalkMenu(CustomTalkMenu&&) = delete;

    CustomTalkMenu& operator= (CustomTalkMenu const&) = delete;
    CustomTalkMenu& operator= (CustomTalkMenu&&) = delete;

    static CustomTalkMenu* instance();

    void Initialize();
    void DisplayMainMenu(Player* player);
    void OnSelectMenuItem(Player* player, uint32 index);
    void UpdateArenaItems(std::list<CustomItem*>& arenaItems);

private:
    void ClearMenu();
    void DisplayMenuToPlayer(Player* player, PlayerMenuState* pState);
    PlayerMenuState* GetPlayerMenu(Player* player, bool reset = false);
    uint32 SearchMenuItemByType(PlayerMenuState* pState, Player* player, uint32 type);
    CustomItem* FindMenuItem(uint32 entry);

    bool ProcessTeleport(CustomItem* pMenuItem, Player* player);
    bool ProcessSummon(CustomItem* pMenuItem, Player* player);
    bool ProcessSpell(CustomItem* pMenuItem, Player* player);
    bool ProcessAura(CustomItem* pMenuItem, Player* player);
    bool ProcessItem(CustomItem* pMenuItem, Player* player);
    bool ProcessInterface(CustomItem* pMenuItem, Player* player);
    bool ProcessPolymorph(CustomItem* pMenuItem, Player* player);
    bool ProcessArenaList(CustomItem* pMenuItem, Player* player);

private:
    CustomTalkMenuItems m_MenuItems;
    CustomTalkMenuItems m_ArenaItems;
    PlayerMenuStates m_PlayerDisplayItems;
};

#define sCustomTalkMenu CustomTalkMenu::instance()

#endif // !_CUSTOM_TALK_MENU_H_
