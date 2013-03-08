#include "ScriptPCH.h"
#include "ScriptMgr.h"
#include "LuaEngine.h"
#include "LuaHooks.h"

/* Item & player Gossip */
void HandleGossipSelectOption(Player* player, uint64 guid, uint32 sender, uint32 action, std::string code, uint32 menuId)
{
    if (!player || !player->IsInWorld() || !player->isAlive() || player->GetCharmerGUID())
        return;

    if (player->HasUnitState(UNIT_STATE_DIED))
        player->RemoveAurasByType(SPELL_AURA_FEIGN_DEATH);
    player->PlayerTalkClass->ClearMenus();

    if (IS_ITEM_GUID(guid))
    {
        Item* item = player->GetItemByGuid(guid);
        if (!item)
            return;

        int bind = sEluna->ItemGossipBindings->GetBind(item->GetEntry(), GOSSIP_EVENT_ON_SELECT);
        if (bind)
        {
            sEluna->BeginCall(bind);
            sEluna->PushUnsigned(sEluna->LuaState, GOSSIP_EVENT_ON_SELECT);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushItem(sEluna->LuaState, item);
            sEluna->PushUnsigned(sEluna->LuaState, sender);
            sEluna->PushUnsigned(sEluna->LuaState, action);
            if (code.empty())
                lua_pushnil(sEluna->LuaState);
            else
                sEluna->PushString(sEluna->LuaState, code.c_str());
            sEluna->ExecuteCall(6, 0);
        }
    }
    else if (IS_PLAYER_GUID(guid))
    {
        if (player->GetGUID() != guid)
            return;

        int bind = sEluna->playerGossipBindings->GetBind(menuId, GOSSIP_EVENT_ON_SELECT);
        if (bind)
        {
            sEluna->BeginCall(bind);
            sEluna->PushUnsigned(sEluna->LuaState, GOSSIP_EVENT_ON_SELECT);
            sEluna->PushUnit(sEluna->LuaState, player); // receiver
            sEluna->PushUnit(sEluna->LuaState, player); // sender, just not to mess up the amount of args.
            sEluna->PushUnsigned(sEluna->LuaState, sender);
            sEluna->PushUnsigned(sEluna->LuaState, action);
            if (code.empty())
                lua_pushnil(sEluna->LuaState);
            else
                sEluna->PushString(sEluna->LuaState, code.c_str());
            sEluna->PushUnsigned(sEluna->LuaState, menuId);
            sEluna->ExecuteCall(7, 0);
        }
    }
}

bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg)
{
    bool Result = true;
    for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(eventId).begin();
        itr != sEluna->ServerEventBindings.at(eventId).end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->PushUnsigned(sEluna->LuaState, eventId);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushString(sEluna->LuaState, msg.c_str());
        sEluna->PushUnsigned(sEluna->LuaState, type);
        sEluna->PushUnsigned(sEluna->LuaState, lang);
        if (sEluna->ExecuteCall(5, 1))
        {
            lua_State* L = sEluna->LuaState;
            if (!lua_isnoneornil(L, 1) && !lua_toboolean(L, 1))
                Result = false;
            sEluna->EndCall(1);
        }
    }
    return Result;
}

bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg, Group* group)
{
    bool Result = true;
    for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(eventId).begin();
        itr != sEluna->ServerEventBindings.at(eventId).end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->PushUnsigned(sEluna->LuaState, eventId);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushString(sEluna->LuaState, msg.c_str());
        sEluna->PushUnsigned(sEluna->LuaState, type);
        sEluna->PushUnsigned(sEluna->LuaState, lang);
        sEluna->PushGroup(sEluna->LuaState, group);
        if (sEluna->ExecuteCall(6, 1))
        {
            lua_State* L = sEluna->LuaState;
            if (!lua_isnoneornil(L, 1) && !lua_toboolean(L, 1))
                Result = false;
            sEluna->EndCall(1);
        }
    }
    return Result;
}

bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild)
{
    bool Result = true;
    for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(eventId).begin();
        itr != sEluna->ServerEventBindings.at(eventId).end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->PushUnsigned(sEluna->LuaState, eventId);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushString(sEluna->LuaState, msg.c_str());
        sEluna->PushUnsigned(sEluna->LuaState, type);
        sEluna->PushUnsigned(sEluna->LuaState, lang);
        sEluna->PushGuild(sEluna->LuaState, guild);
        if (sEluna->ExecuteCall(6, 1))
        {
            lua_State* L = sEluna->LuaState;
            if (!lua_isnoneornil(L, 1) && !lua_toboolean(L, 1))
                Result = false;
            sEluna->EndCall(1);
        }
    }
    return Result;
}

bool OnChat(uint32 eventId, Player* player, uint32 type, uint32 lang, std::string& msg, Channel* channel)
{
    bool Result = true;
    for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(eventId).begin();
        itr != sEluna->ServerEventBindings.at(eventId).end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->PushUnsigned(sEluna->LuaState, eventId);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushString(sEluna->LuaState, msg.c_str());
        sEluna->PushUnsigned(sEluna->LuaState, type);
        sEluna->PushUnsigned(sEluna->LuaState, lang);
        sEluna->PushUnsigned(sEluna->LuaState, channel->GetChannelId());
        if (sEluna->ExecuteCall(6, 1))
        {
            lua_State* L = sEluna->LuaState;
            if (!lua_isnoneornil(L, 1) && !lua_toboolean(L, 1))
                Result = false;
            sEluna->EndCall(1);
        }
    }
    return Result;
}

void OnElunaRestart(uint32 eventId)
{
    for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(eventId).begin();
        itr != sEluna->ServerEventBindings.at(eventId).end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->PushUnsigned(sEluna->LuaState, eventId);
        sEluna->ExecuteCall(1, 0);
    }
}

class Eluna_ServerScript : public ServerScript
{
public:
    Eluna_ServerScript() : ServerScript("Eluna_ServerScript") { }
    void OnNetworkStart()
    {
    }
    void OnNetworkStop()
    {
    }
    void OnSocketOpen(WorldSocket* socket)
    {
    }
    void OnSocketClose(WorldSocket* socket, bool wasNew)
    {
    }
    void OnPacketReceive(WorldSocket* socket, WorldPacket& packet)
    {
    }
    void OnPacketSend(WorldSocket* socket, WorldPacket& packet)
    {
    }
    void OnUnknownPacketReceive(WorldSocket* socket, WorldPacket& packet)
    {
    }
};
class Eluna_FormulaScript : public FormulaScript
{
public:
    Eluna_FormulaScript() : FormulaScript("Eluna_FormulaScript") { }
    void OnHonorCalculation(float& honor, uint8 level, float multiplier)
    {
    }
    void OnGrayLevelCalculation(uint8& grayLevel, uint8 playerLevel)
    {
    }
    void OnColorCodeCalculation(XPColorChar& color, uint8 playerLevel, uint8 mobLevel)
    {
    }
    void OnZeroDifferenceCalculation(uint8& diff, uint8 playerLevel)
    {
    }
    void OnBaseGainCalculation(uint32& gain, uint8 playerLevel, uint8 mobLevel, ContentLevels content)
    {
    }
    void OnGainCalculation(uint32& gain, Player* player, Unit* unit)
    {
    }
    void OnGroupRateCalculation(float& rate, uint32 count, bool isRaid)
    {
    }
};
/*
class Eluna_MapScript : public WorldMapScript
{
public:
    Eluna_MapScript() : WorldMapScript("Eluna_MapScript", 123) { }
    void OnCreateMap(Map* map)
    {
    }
    void OnDestroyMap(Map* map)
    {
    }
    void OnLoadGridMap(Map* map, GridMap* gmap, uint32 gx, uint32 gy)
    {
    }
    void OnUnloadGridMap(Map* map, GridMap* gmap, uint32 gx, uint32 gy)
    {
    }
    void OnPlayerEnterMap(Map* map, Player* player)
    {
    }
    void OnPlayerLeaveMap(Map* map, Player* player)
    {
    }
    void OnMapUpdate(Map* map, uint32 diff)
    {
    }
};
*/
/*
class Eluna_InstanceMapScript : public InstanceMapScript
{
public:
    Eluna_InstanceMapScript() : InstanceMapScript("Eluna_InstanceMapScript") { }
    InstanceScript* CreateInstanceData(InstanceMap* map)
    {
    }
};
*/
class Eluna_ItemScript : public ItemScript
{
public:
    Eluna_ItemScript() : ItemScript("Eluna_ItemScript") { }
    bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Item* target)
    {
        int bind = sEluna->ItemEventBindings->GetBind(target->GetEntry(), ITEM_EVENT_ON_DUMMY_EFFECT);
        if (!bind)
            return false;
        sEluna->BeginCall(bind);
        sEluna->PushUnsigned(sEluna->LuaState, ITEM_EVENT_ON_DUMMY_EFFECT);
        sEluna->PushUnit(sEluna->LuaState, caster);
        sEluna->PushUnsigned(sEluna->LuaState, spellId);
        sEluna->PushInteger(sEluna->LuaState, effIndex);
        sEluna->PushItem(sEluna->LuaState, target);
        sEluna->ExecuteCall(5, 0);
        return true;
    }
    bool OnQuestAccept(Player* player, Item* item, Quest const* quest)
    {
        int bind = sEluna->ItemEventBindings->GetBind(item->GetEntry(), ITEM_EVENT_ON_QUEST_ACCEPT);
        if (!bind)
            return false;
        sEluna->BeginCall(bind);
        sEluna->PushUnsigned(sEluna->LuaState, ITEM_EVENT_ON_QUEST_ACCEPT);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushItem(sEluna->LuaState, item);
        sEluna->PushQuest(sEluna->LuaState, quest);
        sEluna->ExecuteCall(4, 0);
        return true;
    }
    bool OnItemUse(Player* player, Item* item, SpellCastTargets const& targets)
    {
        int bind1 = sEluna->ItemGossipBindings->GetBind(item->GetEntry(), GOSSIP_EVENT_ON_HELLO);
        int bind2 = sEluna->ItemEventBindings->GetBind(item->GetEntry(), ITEM_EVENT_ON_USE);
        if (!bind1 && !bind2)
            return false;
        if (bind1)
        {
            player->PlayerTalkClass->ClearMenus();
            sEluna->BeginCall(bind1);
            sEluna->PushUnsigned(sEluna->LuaState, GOSSIP_EVENT_ON_HELLO);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushItem(sEluna->LuaState, item);
            sEluna->ExecuteCall(3, 0);
        }
        if (bind2)
        {
            sEluna->BeginCall(bind2);
            sEluna->PushUnsigned(sEluna->LuaState, ITEM_EVENT_ON_USE);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushItem(sEluna->LuaState, item);
            if (GameObject* target = targets.GetGOTarget())
                sEluna->PushGO(sEluna->LuaState, target);
            else if (Item* target = targets.GetItemTarget())
                sEluna->PushItem(sEluna->LuaState, target);
            else if (Unit* target = targets.GetUnitTarget())
                sEluna->PushUnit(sEluna->LuaState, target);
            else
                lua_pushnil(sEluna->LuaState);
            sEluna->ExecuteCall(4, 0);
        }
        return true;
    }
    bool OnItemExpire(Player* player, ItemTemplate const* proto)
    {
        int bind = sEluna->ItemEventBindings->GetBind(proto->ItemId, ITEM_EVENT_ON_EXPIRE);
        if (!bind)
            return false;
        sEluna->BeginCall(bind);
        sEluna->PushUnsigned(sEluna->LuaState, ITEM_EVENT_ON_EXPIRE);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushUnsigned(sEluna->LuaState, proto->ItemId);
        sEluna->ExecuteCall(3, 0);
        return true;
    }
};
class Eluna_CreatureScript : public CreatureScript
{
public:
    Eluna_CreatureScript() : CreatureScript("Eluna_CreatureScript") { }
    bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, Creature* target)
    {
        int bind = sEluna->CreatureEventBindings->GetBind(target->GetEntry(), CREATURE_EVENT_ON_DUMMY_EFFECT);
        if (!bind)
            return false;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_DUMMY_EFFECT);
        sEluna->PushUnit(sEluna->LuaState, caster);
        sEluna->PushUnsigned(sEluna->LuaState, spellId);
        sEluna->PushInteger(sEluna->LuaState, effIndex);
        sEluna->PushUnit(sEluna->LuaState, target);
        sEluna->ExecuteCall(5, 0);
        return true;
    }
    bool OnGossipHello(Player* player, Creature* creature)
    {
        int bind = sEluna->CreatureGossipBindings->GetBind(creature->GetEntry(), GOSSIP_EVENT_ON_HELLO);
        if (!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        sEluna->BeginCall(bind);
        sEluna->PushUnsigned(sEluna->LuaState, GOSSIP_EVENT_ON_HELLO);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushUnit(sEluna->LuaState, creature);
        sEluna->ExecuteCall(3, 0);
        return true;
    }
    bool OnGossipSelect(Player* player, Creature* creature, uint32 sender, uint32 action)
    {
        int bind = sEluna->CreatureGossipBindings->GetBind(creature->GetEntry(), GOSSIP_EVENT_ON_SELECT);
        if (!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        sEluna->BeginCall(bind);
        sEluna->PushUnsigned(sEluna->LuaState, GOSSIP_EVENT_ON_SELECT);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushUnit(sEluna->LuaState, creature);
        sEluna->PushUnsigned(sEluna->LuaState, sender);
        sEluna->PushUnsigned(sEluna->LuaState, action);
        sEluna->ExecuteCall(5, 0);
        return true;
    }
    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, const char* code)
    {
        int bind = sEluna->CreatureGossipBindings->GetBind(creature->GetEntry(), GOSSIP_EVENT_ON_SELECT);
        if (!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        sEluna->BeginCall(bind);
        sEluna->PushUnsigned(sEluna->LuaState, GOSSIP_EVENT_ON_SELECT);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushUnit(sEluna->LuaState, creature);
        sEluna->PushUnsigned(sEluna->LuaState, sender);
        sEluna->PushUnsigned(sEluna->LuaState, action);
        sEluna->PushString(sEluna->LuaState, code);
        sEluna->ExecuteCall(6, 0);
        return true;
    }
    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        int bind = sEluna->CreatureEventBindings->GetBind(creature->GetEntry(), CREATURE_EVENT_ON_QUEST_ACCEPT);
        if (!bind)
            return false;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_QUEST_ACCEPT);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushUnit(sEluna->LuaState, creature);
        sEluna->PushQuest(sEluna->LuaState, quest);
        sEluna->ExecuteCall(4, 0);
        return true;
    }
    bool OnQuestSelect(Player* player, Creature* creature, Quest const* quest)
    {
        int bind = sEluna->CreatureEventBindings->GetBind(creature->GetEntry(), CREATURE_EVENT_ON_QUEST_SELECT);
        if (!bind)
            return false;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_QUEST_SELECT);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushUnit(sEluna->LuaState, creature);
        sEluna->PushQuest(sEluna->LuaState, quest);
        sEluna->ExecuteCall(4, 0);
        return true;
    }
    bool OnQuestComplete(Player* player, Creature* creature, Quest const* quest)
    {
        int bind = sEluna->CreatureEventBindings->GetBind(creature->GetEntry(), CREATURE_EVENT_ON_QUEST_COMPLETE);
        if (!bind)
            return false;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_QUEST_COMPLETE);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushUnit(sEluna->LuaState, creature);
        sEluna->PushQuest(sEluna->LuaState, quest);
        sEluna->ExecuteCall(4, 0);
        return true;
    }
    bool OnQuestReward(Player* player, Creature* creature, Quest const* quest, uint32 opt)
    {
        int bind = sEluna->CreatureEventBindings->GetBind(creature->GetEntry(), CREATURE_EVENT_ON_QUEST_REWARD);
        if (!bind)
            return false;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_QUEST_REWARD);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushUnit(sEluna->LuaState, creature);
        sEluna->PushQuest(sEluna->LuaState, quest);
        sEluna->PushUnsigned(sEluna->LuaState, opt);
        sEluna->ExecuteCall(5, 0);
        return true;
    }
    uint32 GetDialogStatus(Player* player, Creature* creature)
    {
        int bind = sEluna->CreatureEventBindings->GetBind(creature->GetEntry(), CREATURE_EVENT_ON_DIALOG_STATUS);
        if (!bind)
            return 100;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, CREATURE_EVENT_ON_DIALOG_STATUS);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushUnit(sEluna->LuaState, creature);
        sEluna->ExecuteCall(3, 0);
        return 100;
    }
};
class Eluna_GameObjectScript : public GameObjectScript
{
public:
    Eluna_GameObjectScript() : GameObjectScript("Eluna_GameObjectScript") { }
    bool IsDatabaseBound() const { return false; }

    bool OnDummyEffect(Unit* caster, uint32 spellId, SpellEffIndex effIndex, GameObject* target)
    {
        int bind = sEluna->GameObjectEventBindings->GetBind(target->GetEntry(), GAMEOBJECT_EVENT_ON_DUMMY_EFFECT);
        if (!bind)
            return false;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_DUMMY_EFFECT);
        sEluna->PushUnit(sEluna->LuaState, caster);
        sEluna->PushUnsigned(sEluna->LuaState, spellId);
        sEluna->PushInteger(sEluna->LuaState, effIndex);
        sEluna->PushGO(sEluna->LuaState, target);
        sEluna->ExecuteCall(5, 0);
        return true;
    }
    bool OnGossipHello(Player* player, GameObject* go)
    {
        int bind = sEluna->GameObjectGossipBindings->GetBind(go->GetEntry(), GOSSIP_EVENT_ON_HELLO);
        if (!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        sEluna->BeginCall(bind);
        sEluna->PushUnsigned(sEluna->LuaState, GOSSIP_EVENT_ON_HELLO);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushGO(sEluna->LuaState, go);
        sEluna->ExecuteCall(3, 0);
        return true;
    }
    bool OnGossipSelect(Player* player, GameObject* go, uint32 sender, uint32 action)
    {
        int bind = sEluna->GameObjectGossipBindings->GetBind(go->GetEntry(), GOSSIP_EVENT_ON_SELECT);
        if (!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        sEluna->BeginCall(bind);
        sEluna->PushUnsigned(sEluna->LuaState, GOSSIP_EVENT_ON_SELECT);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushGO(sEluna->LuaState, go);
        sEluna->PushUnsigned(sEluna->LuaState, sender);
        sEluna->PushUnsigned(sEluna->LuaState, action);
        sEluna->ExecuteCall(5, 0);
        return true;
    }
    bool OnGossipSelectCode(Player* player, GameObject* go, uint32 sender, uint32 action, const char* code)
    {
        int bind = sEluna->GameObjectGossipBindings->GetBind(go->GetEntry(), GOSSIP_EVENT_ON_SELECT);
        if (!bind)
            return false;
        player->PlayerTalkClass->ClearMenus();
        sEluna->BeginCall(bind);
        sEluna->PushUnsigned(sEluna->LuaState, GOSSIP_EVENT_ON_SELECT);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushGO(sEluna->LuaState, go);
        sEluna->PushUnsigned(sEluna->LuaState, sender);
        sEluna->PushUnsigned(sEluna->LuaState, action);
        sEluna->PushString(sEluna->LuaState, code);
        sEluna->ExecuteCall(6, 0);
        return true;
    }
    bool OnQuestAccept(Player* player, GameObject* go, Quest const* quest)
    {
        int bind = sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_QUEST_ACCEPT);
        if (!bind)
            return false;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_QUEST_ACCEPT);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushGO(sEluna->LuaState, go);
        sEluna->PushQuest(sEluna->LuaState, quest);
        sEluna->ExecuteCall(4, 0);
        return true;
    }
    bool OnQuestReward(Player* player, GameObject* go, Quest const* quest, uint32 opt)
    {
        int bind = sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_QUEST_REWARD);
        if (!bind)
            return false;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_QUEST_REWARD);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushGO(sEluna->LuaState, go);
        sEluna->PushQuest(sEluna->LuaState, quest);
        sEluna->PushUnsigned(sEluna->LuaState, opt);
        sEluna->ExecuteCall(5, 0);
        return true;
    }
    uint32 GetDialogStatus(Player* player, GameObject* go)
    {
        int bind = sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_DIALOG_STATUS);
        if (!bind)
            return 100;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_DIALOG_STATUS);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->PushGO(sEluna->LuaState, go);
        sEluna->ExecuteCall(3, 0);
        return 100;
    }
    void OnGameObjectDestroyed(GameObject* go, Player* player)
    {
        int bind = sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_DESTROYED);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_DESTROYED);
        sEluna->PushGO(sEluna->LuaState, go);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->ExecuteCall(3, 0);
    }
    void OnGameObjectDamaged(GameObject* go, Player* player)
    {
        int bind = sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_DAMAGED);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_DAMAGED);
        sEluna->PushGO(sEluna->LuaState, go);
        sEluna->PushUnit(sEluna->LuaState, player);
        sEluna->ExecuteCall(3, 0);
    }
    void OnGameObjectLootStateChanged(GameObject* go, uint32 state, Unit* unit)
    {
        int bind = sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE);
        sEluna->PushGO(sEluna->LuaState, go);
        sEluna->PushUnsigned(sEluna->LuaState, state);
        sEluna->PushUnit(sEluna->LuaState, unit);
        sEluna->ExecuteCall(4, 0);
    }
    void OnGameObjectStateChanged(GameObject* go, uint32 state)
    {
        int bind = sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->PushInteger(sEluna->LuaState, GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED);
        sEluna->PushGO(sEluna->LuaState, go);
        sEluna->PushUnsigned(sEluna->LuaState, state);
        sEluna->ExecuteCall(3, 0);
    }
};
class Eluna_AreaTriggerScript : public AreaTriggerScript
{
public:
    Eluna_AreaTriggerScript() : AreaTriggerScript("Eluna_AreaTriggerScript") { }
    bool OnAreaTrigger(Player* player, AreaTriggerEntry const* trigger)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(TRIGGER_EVENT_ON_TRIGGER).begin();
            itr != sEluna->ServerEventBindings.at(TRIGGER_EVENT_ON_TRIGGER).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, TRIGGER_EVENT_ON_TRIGGER);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, trigger->id);
            sEluna->ExecuteCall(3, 0);
        }
        return false;
    }
};
class Eluna_WeatherScript : public WeatherScript
{
public:
    Eluna_WeatherScript() : WeatherScript("Eluna_WeatherScript") { }
    void OnWeatherChange(Weather* weather, WeatherState state, float grade)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(WEATHER_EVENT_ON_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(WEATHER_EVENT_ON_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, WEATHER_EVENT_ON_CHANGE);
            sEluna->PushUnsigned(sEluna->LuaState, (weather->GetZone()));
            sEluna->PushInteger(sEluna->LuaState, state);
            sEluna->PushFloat(sEluna->LuaState, grade);
            sEluna->ExecuteCall(4, 0);
        }
    }
    void OnWeatherUpdate(Weather* weather, uint32 diff)
    {
    }
};
class Eluna_AuctionHouseScript : public AuctionHouseScript
{
public:
    Eluna_AuctionHouseScript() : AuctionHouseScript("Eluna_AuctionHouseScript") { }
    void OnAuctionAdd(AuctionHouseObject* ah, AuctionEntry* entry)
    {
    }
    void OnAuctionRemove(AuctionHouseObject* ah, AuctionEntry* entry)
    {
    }
    void OnAuctionSuccessful(AuctionHouseObject* ah, AuctionEntry* entry)
    {
    }
    void OnAuctionExpire(AuctionHouseObject* ah, AuctionEntry* entry)
    {
    }
};
class Eluna_ConditionScript : public ConditionScript
{
public:
    Eluna_ConditionScript() : ConditionScript("Eluna_ConditionScript") { }
    bool OnConditionCheck(Condition* condition, ConditionSourceInfo& sourceInfo)
    {
        return false;
    }
};
class Eluna_VehicleScript : public VehicleScript
{
public:
    Eluna_VehicleScript() : VehicleScript("Eluna_VehicleScript") { }
    void OnInstall(Vehicle* veh)
    {
    }
    void OnUninstall(Vehicle* veh)
    {
    }
    void OnReset(Vehicle* veh)
    {
    }
    void OnInstallAccessory(Vehicle* veh, Creature* accessory)
    {
    }
    void OnAddPassenger(Vehicle* veh, Unit* passenger, int8 seatId)
    {
    }
    void OnRemovePassenger(Vehicle* veh, Unit* passenger)
    {
    }
};
class Eluna_DynamicObjectScript : public DynamicObjectScript
{
public:
    Eluna_DynamicObjectScript() : DynamicObjectScript("Eluna_DynamicObjectScript") { }
    void OnDynamicObjectUpdate(DynamicObject* dynobj, uint32 diff)
    {
    }
};
class Eluna_TransportScript : public TransportScript
{
public:
    Eluna_TransportScript() : TransportScript("Eluna_TransportScript") { }
    void OnAddPassenger(Transport* transport, Player* player)
    {
    }
    void OnAddCreaturePassenger(Transport* transport, Creature* creature)
    {
    }
    void OnRemovePassenger(Transport* transport, Player* player)
    {
    }
    void OnTransportUpdate(Transport* transport, uint32 diff)
    {
    }
    void OnRelocate(Transport* transport, uint32 waypointId, uint32 mapId, float x, float y, float z)
    {
    }
};
class Eluna_PlayerScript : public PlayerScript
{
public:
    Eluna_PlayerScript() : PlayerScript("Eluna_PlayerScript") { }
    void OnPVPKill(Player* killer, Player* killed)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_KILL_PLAYER).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_KILL_PLAYER).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_KILL_PLAYER);
            sEluna->PushUnit(sEluna->LuaState, killer);
            sEluna->PushUnit(sEluna->LuaState, killed);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnCreatureKill(Player* killer, Creature* killed)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_KILL_CREATURE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_KILL_CREATURE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_KILL_CREATURE);
            sEluna->PushUnit(sEluna->LuaState, killer);
            sEluna->PushUnit(sEluna->LuaState, killed);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnPlayerKilledByCreature(Creature* killer, Player* killed)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_KILLED_BY_CREATURE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_KILLED_BY_CREATURE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_KILLED_BY_CREATURE);
            sEluna->PushUnit(sEluna->LuaState, killer);
            sEluna->PushUnit(sEluna->LuaState, killed);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnPlayerLevelChanged(Player* player, uint8 oldLevel)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_LEVEL_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_LEVEL_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_LEVEL_CHANGE);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, oldLevel);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnPlayerFreeTalentPointsChanged(Player* player, uint32 newPoints)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_TALENTS_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_TALENTS_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_TALENTS_CHANGE);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, newPoints);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnPlayerTalentsReset(Player* player, bool noCost)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_TALENTS_RESET).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_TALENTS_RESET).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_TALENTS_RESET);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushBoolean(sEluna->LuaState, noCost);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnPlayerMoneyChanged(Player* player, int32& amount)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_MONEY_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_MONEY_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_MONEY_CHANGE);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushInteger(sEluna->LuaState, amount);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnGivePlayerXP(Player* player, uint32& amount, Unit* victim)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_GIVE_XP).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_GIVE_XP).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_GIVE_XP);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, amount);
            sEluna->PushUnit(sEluna->LuaState, victim);
            sEluna->ExecuteCall(4, 0);
        }
    }
    void OnPlayerReputationChange(Player* player, uint32 factionID, int32& standing, bool incremental)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_REPUTATION_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_REPUTATION_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_REPUTATION_CHANGE);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, factionID);
            sEluna->PushInteger(sEluna->LuaState, standing);
            sEluna->PushBoolean(sEluna->LuaState, incremental);
            sEluna->ExecuteCall(5, 0);
        }
    }
    void OnPlayerDuelRequest(Player* target, Player* challenger)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_DUEL_REQUEST).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_DUEL_REQUEST).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_DUEL_REQUEST);
            sEluna->PushUnit(sEluna->LuaState, target);
            sEluna->PushUnit(sEluna->LuaState, challenger);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnPlayerDuelStart(Player* player1, Player* player2)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_DUEL_START).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_DUEL_START).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_DUEL_START);
            sEluna->PushUnit(sEluna->LuaState, player1);
            sEluna->PushUnit(sEluna->LuaState, player2);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnPlayerDuelEnd(Player* winner, Player* loser, DuelCompleteType type)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_DUEL_END).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_DUEL_END).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_DUEL_END);
            sEluna->PushUnit(sEluna->LuaState, winner);
            sEluna->PushUnit(sEluna->LuaState, loser);
            sEluna->PushInteger(sEluna->LuaState, type);
            sEluna->ExecuteCall(4, 0);
        }
    }
    void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg)
    {
    }
    void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg, Player* receiver)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_WHISPER).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_WHISPER).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_WHISPER);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushString(sEluna->LuaState, msg.c_str());
            sEluna->PushUnsigned(sEluna->LuaState, type);
            sEluna->PushUnsigned(sEluna->LuaState, lang);
            sEluna->PushUnit(sEluna->LuaState, receiver);
            sEluna->ExecuteCall(6, 0);
        }
    }
    void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg, Group* group)
    {
    }
    void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg, Guild* guild)
    {
    }
    void OnPlayerChat(Player* player, uint32 type, uint32 lang, std::string& msg, Channel* channel)
    {
    }
    void OnPlayerEmote(Player* player, uint32 emote)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_EMOTE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_EMOTE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_EMOTE);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, emote);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnPlayerTextEmote(Player* player, uint32 textEmote, uint32 emoteNum, uint64 guid)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_TEXT_EMOTE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_TEXT_EMOTE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_TEXT_EMOTE);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, textEmote);
            sEluna->PushUnsigned(sEluna->LuaState, emoteNum);
            sEluna->PushGUID(sEluna->LuaState, guid);
            sEluna->ExecuteCall(5, 0);
        }
    }
    void OnPlayerSpellCast(Player* player, Spell* spell, bool skipCheck)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_SPELL_CAST).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_SPELL_CAST).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_SPELL_CAST);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushSpell(sEluna->LuaState, spell);
            sEluna->PushBoolean(sEluna->LuaState, skipCheck);
            sEluna->ExecuteCall(4, 0);
        }
    }
    void OnPlayerLogin(Player* player)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_LOGIN).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_LOGIN).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_LOGIN);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->ExecuteCall(2, 0);
        }
    }
    void OnPlayerLogout(Player* player)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_LOGOUT).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_LOGOUT).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_LOGOUT);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->ExecuteCall(2, 0);
        }
    }
    void OnPlayerCreate(Player* player)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_CHARACTER_CREATE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_CHARACTER_CREATE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_CHARACTER_CREATE);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->ExecuteCall(2, 0);
        }
    }
    void OnPlayerDelete(uint64 guid)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_CHARACTER_DELETE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_CHARACTER_DELETE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_CHARACTER_DELETE);
            sEluna->PushGUID(sEluna->LuaState, guid);
            sEluna->ExecuteCall(2, 0);
        }
    }
    void OnPlayerSave(Player* player)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_SAVE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_SAVE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_SAVE);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->ExecuteCall(2, 0);
        }
    }
    void OnPlayerBindToInstance(Player* player, Difficulty difficulty, uint32 mapid, bool permanent)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_BIND_TO_INSTANCE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_BIND_TO_INSTANCE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_BIND_TO_INSTANCE);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushInteger(sEluna->LuaState, difficulty);
            sEluna->PushUnsigned(sEluna->LuaState, mapid);
            sEluna->PushBoolean(sEluna->LuaState, permanent);
            sEluna->ExecuteCall(5, 0);
        }
    }
    void OnPlayerUpdateZone(Player* player, uint32 newZone, uint32 newArea)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_UPDATE_ZONE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_UPDATE_ZONE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_UPDATE_ZONE);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, newZone);
            sEluna->PushUnsigned(sEluna->LuaState, newArea);
            sEluna->ExecuteCall(4, 0);
        }
    }
    void OnMapChanged(Player* player)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_MAP_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(PLAYER_EVENT_ON_MAP_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, PLAYER_EVENT_ON_MAP_CHANGE);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->ExecuteCall(2, 0);
        }
    }
};
class Eluna_GuildScript : public GuildScript
{
public:
    Eluna_GuildScript() : GuildScript("Eluna_GuildScript") { }
    void OnGuildAddMember(Guild* guild, Player* player, uint8& plRank)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GUILD_EVENT_ON_ADD_MEMBER).begin();
            itr != sEluna->ServerEventBindings.at(GUILD_EVENT_ON_ADD_MEMBER).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GUILD_EVENT_ON_ADD_MEMBER);
            sEluna->PushGuild(sEluna->LuaState, guild);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, plRank);
            sEluna->ExecuteCall(4, 0);
        }
    }
    void OnGuildRemoveMember(Guild* guild, Player* player, bool isDisbanding, bool isKicked)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GUILD_EVENT_ON_REMOVE_MEMBER).begin();
            itr != sEluna->ServerEventBindings.at(GUILD_EVENT_ON_REMOVE_MEMBER).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GUILD_EVENT_ON_REMOVE_MEMBER);
            sEluna->PushGuild(sEluna->LuaState, guild);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushBoolean(sEluna->LuaState, isDisbanding);
            sEluna->PushBoolean(sEluna->LuaState, isKicked);
            sEluna->ExecuteCall(5, 0);
        }
    }
    void OnGuildMOTDChanged(Guild* guild, const std::string& newMotd)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GUILD_EVENT_ON_MOTD_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(GUILD_EVENT_ON_MOTD_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GUILD_EVENT_ON_MOTD_CHANGE);
            sEluna->PushGuild(sEluna->LuaState, guild);
            sEluna->PushString(sEluna->LuaState, newMotd.c_str());
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnGuildInfoChanged(Guild* guild, const std::string& newInfo)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GUILD_EVENT_ON_INFO_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(GUILD_EVENT_ON_INFO_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GUILD_EVENT_ON_INFO_CHANGE);
            sEluna->PushGuild(sEluna->LuaState, guild);
            sEluna->PushString(sEluna->LuaState, newInfo.c_str());
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnGuildCreate(Guild* guild, Player* leader, const std::string& name)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GUILD_EVENT_ON_CREATE).begin();
            itr != sEluna->ServerEventBindings.at(GUILD_EVENT_ON_CREATE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GUILD_EVENT_ON_CREATE);
            sEluna->PushGuild(sEluna->LuaState, guild);
            sEluna->PushUnit(sEluna->LuaState, leader);
            sEluna->PushString(sEluna->LuaState, name.c_str());
            sEluna->ExecuteCall(4, 0);
        }
    }
    void OnGuildDisband(Guild* guild)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GUILD_EVENT_ON_DISBAND).begin();
            itr != sEluna->ServerEventBindings.at(GUILD_EVENT_ON_DISBAND).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GUILD_EVENT_ON_DISBAND);
            sEluna->PushGuild(sEluna->LuaState, guild);
            sEluna->ExecuteCall(2, 0);
        }
    }
    void OnGuildMemberWitdrawMoney(Guild* guild, Player* player, uint32 &amount, bool isRepair)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GUILD_EVENT_ON_MONEY_WITHDRAW).begin();
            itr != sEluna->ServerEventBindings.at(GUILD_EVENT_ON_MONEY_WITHDRAW).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GUILD_EVENT_ON_MONEY_WITHDRAW);
            sEluna->PushGuild(sEluna->LuaState, guild);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, amount);
            sEluna->PushBoolean(sEluna->LuaState, isRepair);
            sEluna->ExecuteCall(5, 0);
        }
    }
    void OnGuildMemberDepositMoney(Guild* guild, Player* player, uint32 &amount)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GUILD_EVENT_ON_MONEY_DEPOSIT).begin();
            itr != sEluna->ServerEventBindings.at(GUILD_EVENT_ON_MONEY_DEPOSIT).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GUILD_EVENT_ON_MONEY_DEPOSIT);
            sEluna->PushGuild(sEluna->LuaState, guild);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushUnsigned(sEluna->LuaState, amount);
            sEluna->ExecuteCall(4, 0);
        }
    }
    void OnGuildItemMove(Guild* guild, Player* player, Item* pItem, bool isSrcBank, uint8 srcContainer, uint8 srcSlotId,
        bool isDestBank, uint8 destContainer, uint8 destSlotId)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GUILD_EVENT_ON_ITEM_MOVE).begin();
            itr != sEluna->ServerEventBindings.at(GUILD_EVENT_ON_ITEM_MOVE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GUILD_EVENT_ON_ITEM_MOVE);
            sEluna->PushGuild(sEluna->LuaState, guild);
            sEluna->PushUnit(sEluna->LuaState, player);
            sEluna->PushItem(sEluna->LuaState, pItem);
            sEluna->PushBoolean(sEluna->LuaState, isSrcBank);
            sEluna->PushUnsigned(sEluna->LuaState, srcContainer);
            sEluna->PushUnsigned(sEluna->LuaState, srcSlotId);
            sEluna->PushBoolean(sEluna->LuaState, isDestBank);
            sEluna->PushUnsigned(sEluna->LuaState, destContainer);
            sEluna->PushUnsigned(sEluna->LuaState, destSlotId);
            sEluna->ExecuteCall(10, 0);
        }
    }
    void OnGuildEvent(Guild* guild, uint8 eventType, uint32 playerGuid1, uint32 playerGuid2, uint8 newRank)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GUILD_EVENT_ON_EVENT).begin();
            itr != sEluna->ServerEventBindings.at(GUILD_EVENT_ON_EVENT).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GUILD_EVENT_ON_EVENT);
            sEluna->PushGuild(sEluna->LuaState, guild);
            sEluna->PushUnsigned(sEluna->LuaState, eventType);
            sEluna->PushUnsigned(sEluna->LuaState, playerGuid1);
            sEluna->PushUnsigned(sEluna->LuaState, playerGuid2);
            sEluna->PushUnsigned(sEluna->LuaState, newRank);
            sEluna->ExecuteCall(6, 0);
        }
    }
    void OnGuildBankEvent(Guild* guild, uint8 eventType, uint8 tabId, uint32 playerGuid, uint32 itemOrMoney, uint16 itemStackCount, uint8 destTabId)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GUILD_EVENT_ON_BANK_EVENT).begin();
            itr != sEluna->ServerEventBindings.at(GUILD_EVENT_ON_BANK_EVENT).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GUILD_EVENT_ON_BANK_EVENT);
            sEluna->PushGuild(sEluna->LuaState, guild);
            sEluna->PushUnsigned(sEluna->LuaState, eventType);
            sEluna->PushUnsigned(sEluna->LuaState, tabId);
            sEluna->PushUnsigned(sEluna->LuaState, playerGuid);
            sEluna->PushUnsigned(sEluna->LuaState, itemOrMoney);
            sEluna->PushUnsigned(sEluna->LuaState, itemStackCount);
            sEluna->PushUnsigned(sEluna->LuaState, destTabId);
            sEluna->ExecuteCall(8, 0);
        }
    }
};
class Eluna_GroupScript : public GroupScript
{
public:
    Eluna_GroupScript() : GroupScript("Eluna_GroupScript") { }
    void OnGroupAddMember(Group* group, uint64 guid)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GROUP_EVENT_ON_MEMBER_ADD).begin();
            itr != sEluna->ServerEventBindings.at(GROUP_EVENT_ON_MEMBER_ADD).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GROUP_EVENT_ON_MEMBER_ADD);
            sEluna->PushGroup(sEluna->LuaState, group);
            sEluna->PushGUID(sEluna->LuaState, guid);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnGroupInviteMember(Group* group, uint64 guid)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GROUP_EVENT_ON_MEMBER_INVITE).begin();
            itr != sEluna->ServerEventBindings.at(GROUP_EVENT_ON_MEMBER_INVITE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GROUP_EVENT_ON_MEMBER_INVITE);
            sEluna->PushGroup(sEluna->LuaState, group);
            sEluna->PushGUID(sEluna->LuaState, guid);
            sEluna->ExecuteCall(3, 0);
        }
    }
    void OnGroupRemoveMember(Group* group, uint64 guid, RemoveMethod method, uint64 kicker, const char* reason)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GROUP_EVENT_ON_MEMBER_REMOVE).begin();
            itr != sEluna->ServerEventBindings.at(GROUP_EVENT_ON_MEMBER_REMOVE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GROUP_EVENT_ON_MEMBER_REMOVE);
            sEluna->PushGroup(sEluna->LuaState, group);
            sEluna->PushGUID(sEluna->LuaState, guid);
            sEluna->PushInteger(sEluna->LuaState, method);
            sEluna->PushGUID(sEluna->LuaState, kicker);
            sEluna->PushString(sEluna->LuaState, reason);
            sEluna->ExecuteCall(6, 0);
        }
    }
    void OnGroupChangeLeader(Group* group, uint64 newLeaderGuid, uint64 oldLeaderGuid)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GROUP_EVENT_ON_LEADER_CHANGE).begin();
            itr != sEluna->ServerEventBindings.at(GROUP_EVENT_ON_LEADER_CHANGE).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GROUP_EVENT_ON_LEADER_CHANGE);
            sEluna->PushGroup(sEluna->LuaState, group);
            sEluna->PushGUID(sEluna->LuaState, newLeaderGuid);
            sEluna->PushGUID(sEluna->LuaState, oldLeaderGuid);
            sEluna->ExecuteCall(4, 0);
        }
    }
    void OnGroupDisband(Group* group)
    {
        for (vector<int>::iterator itr = sEluna->ServerEventBindings.at(GROUP_EVENT_ON_DISBAND).begin();
            itr != sEluna->ServerEventBindings.at(GROUP_EVENT_ON_DISBAND).end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->PushUnsigned(sEluna->LuaState, GROUP_EVENT_ON_DISBAND);
            sEluna->PushGroup(sEluna->LuaState, group);
            sEluna->ExecuteCall(2, 0);
        }
    }
};

void Eluna_AddScriptHooks()
{
    new Eluna_ServerScript;
    new Eluna_FormulaScript;
    //new Eluna_MapScript;
    //new Eluna_InstanceMapScript;
    new Eluna_ItemScript;
    new Eluna_CreatureScript;
    new Eluna_GameObjectScript;
    new Eluna_AreaTriggerScript;
    new Eluna_WeatherScript;
    new Eluna_AuctionHouseScript;
    new Eluna_ConditionScript;
    new Eluna_VehicleScript;
    new Eluna_DynamicObjectScript;
    new Eluna_TransportScript;
    new Eluna_PlayerScript;
    new Eluna_GuildScript;
    new Eluna_GroupScript;
}