/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#include "HookMgr.h"
#include "LuaEngine.h"

void HookMgr::OnWorldUpdate(uint32 diff)
{
    sEluna->m_EventMgr.Update(diff);
    for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_UPDATE].begin();
        itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_UPDATE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, WORLD_EVENT_ON_UPDATE);
        sEluna->Push(sEluna->L, diff);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnLootItem(Player* pPlayer, Item* pItem, uint32 count, uint64 guid)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_LOOT_ITEM].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_LOOT_ITEM].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_LOOT_ITEM);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, pItem);
        sEluna->Push(sEluna->L, count);
        sEluna->Push(sEluna->L, guid);
        sEluna->ExecuteCall(5, 0);
    }
}

void HookMgr::OnFirstLogin(Player* pPlayer)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_FIRST_LOGIN].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_FIRST_LOGIN].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_FIRST_LOGIN);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnRepop(Player* pPlayer)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_REPOP].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_REPOP].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_REPOP);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnResurrect(Player* pPlayer)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_RESURRECT].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_RESURRECT].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_RESURRECT);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnEquip(Player* pPlayer, Item* pItem, uint8 bag, uint8 slot)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_EQUIP].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_EQUIP].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_EQUIP);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, pItem);
        sEluna->Push(sEluna->L, bag);
        sEluna->Push(sEluna->L, slot);
        sEluna->ExecuteCall(5, 0);
    }
}

InventoryResult HookMgr::OnCanUseItem(const Player* pPlayer, uint32 itemEntry)
{
    InventoryResult result = EQUIP_ERR_OK;
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_CAN_USE_ITEM].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_CAN_USE_ITEM].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_CAN_USE_ITEM);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, itemEntry);
        if (sEluna->ExecuteCall(3, 1))
        {
            lua_State* L = sEluna->L;
            if (!lua_isnoneornil(L, 1))
                result = (InventoryResult)lua_tounsigned(L, 1);
            sEluna->EndCall(1);
        }
    }
    return result;
}

void HookMgr::HandleGossipSelectOption(Player* pPlayer, Item* item, uint32 sender, uint32 action, std::string code)
{
    int bind = sEluna->ItemGossipBindings->GetBind(item->GetEntry(), GOSSIP_EVENT_ON_SELECT);
    if (bind)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, GOSSIP_EVENT_ON_SELECT);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, item);
        sEluna->Push(sEluna->L, sender);
        sEluna->Push(sEluna->L, action);
        if (code.empty())
            lua_pushnil(sEluna->L);
        else
            sEluna->Push(sEluna->L, code);
        sEluna->ExecuteCall(6, 0);
    }
}

void HookMgr::HandleGossipSelectOption(Player* pPlayer, uint32 menuId, uint32 sender, uint32 action, std::string code)
{
    int bind = sEluna->playerGossipBindings->GetBind(menuId, GOSSIP_EVENT_ON_SELECT);
    if (bind)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, GOSSIP_EVENT_ON_SELECT);
        sEluna->Push(sEluna->L, pPlayer); // receiver
        sEluna->Push(sEluna->L, pPlayer); // sender, just not to mess up the amount of args.
        sEluna->Push(sEluna->L, sender);
        sEluna->Push(sEluna->L, action);
        if (code.empty())
            lua_pushnil(sEluna->L);
        else
            sEluna->Push(sEluna->L, code);
        sEluna->Push(sEluna->L, menuId);
        sEluna->ExecuteCall(7, 0);
    }
}

void HookMgr::OnEngineRestart()
{
    for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[ELUNA_EVENT_ON_RESTART].begin();
        itr != sEluna->ServerEventBindings[ELUNA_EVENT_ON_RESTART].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, ELUNA_EVENT_ON_RESTART);
        sEluna->ExecuteCall(1, 0);
    }
}

// item
bool HookMgr::OnDummyEffect(Unit* pCaster, uint32 spellId, SpellEffIndex effIndex, Item* pTarget)
{
    int bind = sEluna->ItemEventBindings->GetBind(pTarget->GetEntry(), ITEM_EVENT_ON_DUMMY_EFFECT);
    if (!bind)
        return false;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, ITEM_EVENT_ON_DUMMY_EFFECT);
    sEluna->Push(sEluna->L, pCaster);
    sEluna->Push(sEluna->L, spellId);
    sEluna->Push(sEluna->L, effIndex);
    sEluna->Push(sEluna->L, pTarget);
    sEluna->ExecuteCall(5, 0);
    return true;
}

bool HookMgr::OnQuestAccept(Player* pPlayer, Item* pItem, Quest const* pQuest)
{
    int bind = sEluna->ItemEventBindings->GetBind(pItem->GetEntry(), ITEM_EVENT_ON_QUEST_ACCEPT);
    if (!bind)
        return false;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, ITEM_EVENT_ON_QUEST_ACCEPT);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pItem);
    sEluna->Push(sEluna->L, pQuest);
    sEluna->ExecuteCall(4, 0);
    return true;
}

bool HookMgr::OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& targets)
{
    int bind1 = sEluna->ItemGossipBindings->GetBind(pItem->GetEntry(), GOSSIP_EVENT_ON_HELLO);
    int bind2 = sEluna->ItemEventBindings->GetBind(pItem->GetEntry(), ITEM_EVENT_ON_USE);
    if (!bind1 && !bind2)
        return false;
    if (bind1)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        sEluna->BeginCall(bind1);
        sEluna->Push(sEluna->L, GOSSIP_EVENT_ON_HELLO);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, pItem);
        sEluna->ExecuteCall(3, 0);
    }
    if (bind2)
    {
        sEluna->BeginCall(bind2);
        sEluna->Push(sEluna->L, ITEM_EVENT_ON_USE);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, pItem);
        if (GameObject* target = targets.GetGOTarget())
            sEluna->Push(sEluna->L, target);
        else if (Item* target = targets.GetItemTarget())
            sEluna->Push(sEluna->L, target);
        else if (Unit* target = targets.GetUnitTarget())
            sEluna->Push(sEluna->L, target);
        else
            sEluna->Push(sEluna->L);
        sEluna->ExecuteCall(4, 0);
    }
    // pPlayer->SendEquipError((InventoryResult)83, pItem, NULL);
    return false;
}

bool HookMgr::OnExpire(Player* pPlayer, ItemTemplate const* pProto)
{
    int bind = sEluna->ItemEventBindings->GetBind(pProto->ItemId, ITEM_EVENT_ON_EXPIRE);
    if (!bind)
        return false;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, ITEM_EVENT_ON_EXPIRE);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pProto->ItemId);
    sEluna->ExecuteCall(3, 0);
    return true;
}
// creature
bool HookMgr::OnDummyEffect(Unit* pCaster, uint32 spellId, SpellEffIndex effIndex, Creature* pTarget)
{
    int bind = sEluna->CreatureEventBindings->GetBind(pTarget->GetEntry(), CREATURE_EVENT_ON_DUMMY_EFFECT);
    if (!bind)
        return false;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, CREATURE_EVENT_ON_DUMMY_EFFECT);
    sEluna->Push(sEluna->L, pCaster);
    sEluna->Push(sEluna->L, spellId);
    sEluna->Push(sEluna->L, effIndex);
    sEluna->Push(sEluna->L, pTarget);
    sEluna->ExecuteCall(5, 0);
    return true;
}

bool HookMgr::OnGossipHello(Player* pPlayer, Creature* pCreature)
{
    int bind = sEluna->CreatureGossipBindings->GetBind(pCreature->GetEntry(), GOSSIP_EVENT_ON_HELLO);
    if (!bind)
        return false;
    pPlayer->PlayerTalkClass->ClearMenus();
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GOSSIP_EVENT_ON_HELLO);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pCreature);
    sEluna->ExecuteCall(3, 0);
    return true;
}

bool HookMgr::OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action)
{
    int bind = sEluna->CreatureGossipBindings->GetBind(pCreature->GetEntry(), GOSSIP_EVENT_ON_SELECT);
    if (!bind)
        return false;
    pPlayer->PlayerTalkClass->ClearMenus();
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GOSSIP_EVENT_ON_SELECT);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pCreature);
    sEluna->Push(sEluna->L, sender);
    sEluna->Push(sEluna->L, action);
    sEluna->ExecuteCall(5, 0);
    return true;
}

bool HookMgr::OnGossipSelectCode(Player* pPlayer, Creature* pCreature, uint32 sender, uint32 action, const char* code)
{
    int bind = sEluna->CreatureGossipBindings->GetBind(pCreature->GetEntry(), GOSSIP_EVENT_ON_SELECT);
    if (!bind)
        return false;
    pPlayer->PlayerTalkClass->ClearMenus();
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GOSSIP_EVENT_ON_SELECT);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pCreature);
    sEluna->Push(sEluna->L, sender);
    sEluna->Push(sEluna->L, action);
    sEluna->Push(sEluna->L, code);
    sEluna->ExecuteCall(6, 0);
    return true;
}

bool HookMgr::OnQuestAccept(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    int bind = sEluna->CreatureEventBindings->GetBind(pCreature->GetEntry(), CREATURE_EVENT_ON_QUEST_ACCEPT);
    if (!bind)
        return false;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, CREATURE_EVENT_ON_QUEST_ACCEPT);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pCreature);
    sEluna->Push(sEluna->L, pQuest);
    sEluna->ExecuteCall(4, 0);
    return true;
}

bool HookMgr::OnQuestSelect(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    int bind = sEluna->CreatureEventBindings->GetBind(pCreature->GetEntry(), CREATURE_EVENT_ON_QUEST_SELECT);
    if (!bind)
        return false;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, CREATURE_EVENT_ON_QUEST_SELECT);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pCreature);
    sEluna->Push(sEluna->L, pQuest);
    sEluna->ExecuteCall(4, 0);
    return true;
}

bool HookMgr::OnQuestComplete(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    int bind = sEluna->CreatureEventBindings->GetBind(pCreature->GetEntry(), CREATURE_EVENT_ON_QUEST_COMPLETE);
    if (!bind)
        return false;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, CREATURE_EVENT_ON_QUEST_COMPLETE);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pCreature);
    sEluna->Push(sEluna->L, pQuest);
    sEluna->ExecuteCall(4, 0);
    return true;
}

bool HookMgr::OnQuestReward(Player* pPlayer, Creature* pCreature, Quest const* pQuest)
{
    int bind = sEluna->CreatureEventBindings->GetBind(pCreature->GetEntry(), CREATURE_EVENT_ON_QUEST_REWARD);
    if (!bind)
        return false;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, CREATURE_EVENT_ON_QUEST_REWARD);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pCreature);
    sEluna->Push(sEluna->L, pQuest);
    sEluna->ExecuteCall(4, 0);
    return true;
}

uint32 HookMgr::GetDialogStatus(Player* pPlayer, Creature* pCreature)
{
    int bind = sEluna->CreatureEventBindings->GetBind(pCreature->GetEntry(), CREATURE_EVENT_ON_DIALOG_STATUS);
    if (!bind)
        return 0;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, CREATURE_EVENT_ON_DIALOG_STATUS);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pCreature);
    sEluna->ExecuteCall(3, 0);
    return DIALOG_STATUS_SCRIPTED_NO_STATUS;
}
// gameobject
bool HookMgr::OnDummyEffect(Unit* pCaster, uint32 spellId, SpellEffIndex effIndex, GameObject* pTarget)
{
    int bind = sEluna->GameObjectEventBindings->GetBind(pTarget->GetEntry(), GAMEOBJECT_EVENT_ON_DUMMY_EFFECT);
    if (!bind)
        return false;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GAMEOBJECT_EVENT_ON_DUMMY_EFFECT);
    sEluna->Push(sEluna->L, pCaster);
    sEluna->Push(sEluna->L, spellId);
    sEluna->Push(sEluna->L, effIndex);
    sEluna->Push(sEluna->L, pTarget);
    sEluna->ExecuteCall(5, 0);
    return true;
}

bool HookMgr::OnGossipHello(Player* pPlayer, GameObject* pGameObject)
{
    int bind = sEluna->GameObjectGossipBindings->GetBind(pGameObject->GetEntry(), GOSSIP_EVENT_ON_HELLO);
    if (!bind)
        return false;
    pPlayer->PlayerTalkClass->ClearMenus();
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GOSSIP_EVENT_ON_HELLO);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pGameObject);
    sEluna->ExecuteCall(3, 0);
    return true;
}

bool HookMgr::OnGossipSelect(Player* pPlayer, GameObject* pGameObject, uint32 sender, uint32 action)
{
    int bind = sEluna->GameObjectGossipBindings->GetBind(pGameObject->GetEntry(), GOSSIP_EVENT_ON_SELECT);
    if (!bind)
        return false;
    pPlayer->PlayerTalkClass->ClearMenus();
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GOSSIP_EVENT_ON_SELECT);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pGameObject);
    sEluna->Push(sEluna->L, sender);
    sEluna->Push(sEluna->L, action);
    sEluna->ExecuteCall(5, 0);
    return true;
}

bool HookMgr::OnGossipSelectCode(Player* pPlayer, GameObject* pGameObject, uint32 sender, uint32 action, const char* code)
{
    int bind = sEluna->GameObjectGossipBindings->GetBind(pGameObject->GetEntry(), GOSSIP_EVENT_ON_SELECT);
    if (!bind)
        return false;
    pPlayer->PlayerTalkClass->ClearMenus();
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GOSSIP_EVENT_ON_SELECT);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pGameObject);
    sEluna->Push(sEluna->L, sender);
    sEluna->Push(sEluna->L, action);
    sEluna->Push(sEluna->L, code);
    sEluna->ExecuteCall(6, 0);
    return true;
}

bool HookMgr::OnQuestAccept(Player* pPlayer, GameObject* pGameObject, Quest const* pQuest)
{
    int bind = sEluna->GameObjectEventBindings->GetBind(pGameObject->GetEntry(), GAMEOBJECT_EVENT_ON_QUEST_ACCEPT);
    if (!bind)
        return false;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GAMEOBJECT_EVENT_ON_QUEST_ACCEPT);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pGameObject);
    sEluna->Push(sEluna->L, pQuest);
    sEluna->ExecuteCall(4, 0);
    return true;
}

bool HookMgr::OnQuestComplete(Player* pPlayer, GameObject* pGameObject, Quest const* pQuest)
{
    int bind = sEluna->CreatureEventBindings->GetBind(pGameObject->GetEntry(), GAMEOBJECT_EVENT_ON_QUEST_COMPLETE);
    if (!bind)
        return false;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GAMEOBJECT_EVENT_ON_QUEST_COMPLETE);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pGameObject);
    sEluna->Push(sEluna->L, pQuest);
    sEluna->ExecuteCall(4, 0);
    return true;
}

bool HookMgr::OnQuestReward(Player* pPlayer, GameObject* pGameObject, Quest const* pQuest)
{
    int bind = sEluna->GameObjectEventBindings->GetBind(pGameObject->GetEntry(), GAMEOBJECT_EVENT_ON_QUEST_REWARD);
    if (!bind)
        return false;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GAMEOBJECT_EVENT_ON_QUEST_REWARD);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pGameObject);
    sEluna->Push(sEluna->L, pQuest);
    sEluna->ExecuteCall(4, 0);
    return true;
}

uint32 HookMgr::GetDialogStatus(Player* pPlayer, GameObject* pGameObject)
{
    int bind = sEluna->GameObjectEventBindings->GetBind(pGameObject->GetEntry(), GAMEOBJECT_EVENT_ON_DIALOG_STATUS);
    if (!bind)
        return 0;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GAMEOBJECT_EVENT_ON_DIALOG_STATUS);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->Push(sEluna->L, pGameObject);
    sEluna->ExecuteCall(3, 0);
    return DIALOG_STATUS_SCRIPTED_NO_STATUS; // DIALOG_STATUS_UNDEFINED
}

void HookMgr::OnDestroyed(GameObject* pGameObject, Player* pPlayer)
{
    int bind = sEluna->GameObjectEventBindings->GetBind(pGameObject->GetEntry(), GAMEOBJECT_EVENT_ON_DESTROYED);
    if (!bind)
        return;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GAMEOBJECT_EVENT_ON_DESTROYED);
    sEluna->Push(sEluna->L, pGameObject);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->ExecuteCall(3, 0);
}

void HookMgr::OnDamaged(GameObject* pGameObject, Player* pPlayer)
{
    int bind = sEluna->GameObjectEventBindings->GetBind(pGameObject->GetEntry(), GAMEOBJECT_EVENT_ON_DAMAGED);
    if (!bind)
        return;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GAMEOBJECT_EVENT_ON_DAMAGED);
    sEluna->Push(sEluna->L, pGameObject);
    sEluna->Push(sEluna->L, pPlayer);
    sEluna->ExecuteCall(3, 0);
}

void HookMgr::OnLootStateChanged(GameObject* pGameObject, uint32 state, Unit* pUnit)
{
    int bind = sEluna->GameObjectEventBindings->GetBind(pGameObject->GetEntry(), GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE);
    if (!bind)
        return;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE);
    sEluna->Push(sEluna->L, pGameObject);
    sEluna->Push(sEluna->L, state);
    sEluna->Push(sEluna->L, pUnit);
    sEluna->ExecuteCall(4, 0);
}

void HookMgr::OnGameObjectStateChanged(GameObject* pGameObject, uint32 state)
{
    int bind = sEluna->GameObjectEventBindings->GetBind(pGameObject->GetEntry(), GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED);
    if (!bind)
        return;
    sEluna->BeginCall(bind);
    sEluna->Push(sEluna->L, GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED);
    sEluna->Push(sEluna->L, pGameObject);
    sEluna->Push(sEluna->L, state);
    sEluna->ExecuteCall(3, 0);
}
// Player
void HookMgr::OnPlayerEnterCombat(Player* pPlayer, Unit* pEnemy)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_ENTER_COMBAT].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_ENTER_COMBAT].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_ENTER_COMBAT);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, pEnemy);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnPlayerLeaveCombat(Player* pPlayer)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_LEAVE_COMBAT].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_LEAVE_COMBAT].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_LEAVE_COMBAT);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnPVPKill(Player* pKiller, Player* pKilled)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_KILL_PLAYER].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_KILL_PLAYER].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_KILL_PLAYER);
        sEluna->Push(sEluna->L, pKiller);
        sEluna->Push(sEluna->L, pKilled);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnCreatureKill(Player* pKiller, Creature* pKilled)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_KILL_CREATURE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_KILL_CREATURE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_KILL_CREATURE);
        sEluna->Push(sEluna->L, pKiller);
        sEluna->Push(sEluna->L, pKilled);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnPlayerKilledByCreature(Creature* pKiller, Player* pKilled)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_KILLED_BY_CREATURE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_KILLED_BY_CREATURE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_KILLED_BY_CREATURE);
        sEluna->Push(sEluna->L, pKiller);
        sEluna->Push(sEluna->L, pKilled);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnLevelChanged(Player* pPlayer, uint8 oldLevel)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_LEVEL_CHANGE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_LEVEL_CHANGE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_LEVEL_CHANGE);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, oldLevel);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnFreeTalentPointsChanged(Player* pPlayer, uint32 newPoints)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_TALENTS_CHANGE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_TALENTS_CHANGE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_TALENTS_CHANGE);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, newPoints);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnTalentsReset(Player* pPlayer, bool noCost)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_TALENTS_RESET].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_TALENTS_RESET].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_TALENTS_RESET);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, noCost);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnMoneyChanged(Player* pPlayer, int32& amount)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_MONEY_CHANGE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_MONEY_CHANGE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_MONEY_CHANGE);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, amount);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnGiveXP(Player* pPlayer, uint32& amount, Unit* pVictim)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_GIVE_XP].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_GIVE_XP].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_GIVE_XP);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, amount);
        sEluna->Push(sEluna->L, pVictim);
        sEluna->ExecuteCall(4, 0);
    }
}

void HookMgr::OnReputationChange(Player* pPlayer, uint32 factionID, int32& standing, bool incremental)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_REPUTATION_CHANGE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_REPUTATION_CHANGE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_REPUTATION_CHANGE);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, factionID);
        sEluna->Push(sEluna->L, standing);
        sEluna->Push(sEluna->L, incremental);
        sEluna->ExecuteCall(5, 0);
    }
}

void HookMgr::OnDuelRequest(Player* pTarget, Player* pChallenger)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_DUEL_REQUEST].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_DUEL_REQUEST].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_DUEL_REQUEST);
        sEluna->Push(sEluna->L, pTarget);
        sEluna->Push(sEluna->L, pChallenger);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnDuelStart(Player* pStarter, Player* pChallenger)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_DUEL_START].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_DUEL_START].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_DUEL_START);
        sEluna->Push(sEluna->L, pStarter);
        sEluna->Push(sEluna->L, pChallenger);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnDuelEnd(Player* pWinner, Player* pLoser, DuelCompleteType type)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_DUEL_END].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_DUEL_END].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_DUEL_END);
        sEluna->Push(sEluna->L, pWinner);
        sEluna->Push(sEluna->L, pLoser);
        sEluna->Push(sEluna->L, type);
        sEluna->ExecuteCall(4, 0);
    }
}

void HookMgr::OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Player* pReceiver)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_WHISPER].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_WHISPER].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_WHISPER);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, msg);
        sEluna->Push(sEluna->L, type);
        sEluna->Push(sEluna->L, lang);
        sEluna->Push(sEluna->L, pReceiver);
        sEluna->ExecuteCall(6, 0);
    }
}

void HookMgr::OnEmote(Player* pPlayer, uint32 emote)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_EMOTE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_EMOTE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_EMOTE);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, emote);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnTextEmote(Player* pPlayer, uint32 textEmote, uint32 emoteNum, uint64 guid)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_TEXT_EMOTE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_TEXT_EMOTE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_TEXT_EMOTE);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, textEmote);
        sEluna->Push(sEluna->L, emoteNum);
        sEluna->Push(sEluna->L, guid);
        sEluna->ExecuteCall(5, 0);
    }
}

void HookMgr::OnSpellCast(Player* pPlayer, Spell* pSpell, bool skipCheck)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_SPELL_CAST].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_SPELL_CAST].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_SPELL_CAST);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, pSpell);
        sEluna->Push(sEluna->L, skipCheck);
        sEluna->ExecuteCall(4, 0);
    }
}

void HookMgr::OnLogin(Player* pPlayer)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_LOGIN].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_LOGIN].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_LOGIN);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnLogout(Player* pPlayer)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_LOGOUT].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_LOGOUT].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_LOGOUT);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnCreate(Player* pPlayer)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_CHARACTER_CREATE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_CHARACTER_CREATE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_CHARACTER_CREATE);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnDelete(uint32 guidlow)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_CHARACTER_DELETE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_CHARACTER_DELETE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_CHARACTER_DELETE);
        sEluna->Push(sEluna->L, guidlow);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnSave(Player* pPlayer)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_SAVE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_SAVE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_SAVE);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnBindToInstance(Player* pPlayer, Difficulty difficulty, uint32 mapid, bool permanent)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_BIND_TO_INSTANCE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_BIND_TO_INSTANCE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_BIND_TO_INSTANCE);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, difficulty);
        sEluna->Push(sEluna->L, mapid);
        sEluna->Push(sEluna->L, permanent);
        sEluna->ExecuteCall(5, 0);
    }
}

void HookMgr::OnUpdateZone(Player* pPlayer, uint32 newZone, uint32 newArea)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_UPDATE_ZONE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_UPDATE_ZONE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_UPDATE_ZONE);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, newZone);
        sEluna->Push(sEluna->L, newArea);
        sEluna->ExecuteCall(4, 0);
    }
}

void HookMgr::OnMapChanged(Player* player)
{
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_MAP_CHANGE].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_MAP_CHANGE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_MAP_CHANGE);
        sEluna->Push(sEluna->L, player);
        sEluna->ExecuteCall(2, 0);
    }
}

bool HookMgr::OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg)
{
    bool Result = true;
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_CHAT].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_CHAT].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_CHAT);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, msg);
        sEluna->Push(sEluna->L, type);
        sEluna->Push(sEluna->L, lang);
        if (sEluna->ExecuteCall(5, 1))
        {
            lua_State* L = sEluna->L;
            if (!lua_isnoneornil(L, 1) && !lua_toboolean(L, 1))
                Result = false;
            sEluna->EndCall(1);
        }
    }
    return Result;
}

bool HookMgr::OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Group* pGroup)
{
    bool Result = true;
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_GROUP_CHAT].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_GROUP_CHAT].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_GROUP_CHAT);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, msg);
        sEluna->Push(sEluna->L, type);
        sEluna->Push(sEluna->L, lang);
        sEluna->Push(sEluna->L, pGroup);
        if (sEluna->ExecuteCall(6, 1))
        {
            lua_State* L = sEluna->L;
            if (!lua_isnoneornil(L, 1) && !lua_toboolean(L, 1))
                Result = false;
            sEluna->EndCall(1);
        }
    }
    return Result;
}

bool HookMgr::OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Guild* pGuild)
{
    bool Result = true;
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_GUILD_CHAT].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_GUILD_CHAT].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_GUILD_CHAT);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, msg);
        sEluna->Push(sEluna->L, type);
        sEluna->Push(sEluna->L, lang);
        sEluna->Push(sEluna->L, pGuild);
        if (sEluna->ExecuteCall(6, 1))
        {
            lua_State* L = sEluna->L;
            if (!lua_isnoneornil(L, 1) && !lua_toboolean(L, 1))
                Result = false;
            sEluna->EndCall(1);
        }
    }
    return Result;
}

bool HookMgr::OnChat(Player* pPlayer, uint32 type, uint32 lang, std::string& msg, Channel* pChannel)
{
    bool Result = true;
    for (std::vector<int>::const_iterator itr = sEluna->PlayerEventBindings[PLAYER_EVENT_ON_CHANNEL_CHAT].begin();
        itr != sEluna->PlayerEventBindings[PLAYER_EVENT_ON_CHANNEL_CHAT].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, PLAYER_EVENT_ON_CHANNEL_CHAT);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, msg);
        sEluna->Push(sEluna->L, type);
        sEluna->Push(sEluna->L, lang);
        sEluna->Push(sEluna->L, pChannel->GetChannelId());
        if (sEluna->ExecuteCall(6, 1))
        {
            lua_State* L = sEluna->L;
            if (!lua_isnoneornil(L, 1) && !lua_toboolean(L, 1))
                Result = false;
            sEluna->EndCall(1);
        }
    }
    return Result;
}
// Vehicle
void HookMgr::OnInstall(Vehicle* vehicle)
{
    for (std::vector<int>::const_iterator itr = sEluna->VehicleEventBindings[VEHICLE_EVENT_ON_INSTALL].begin();
        itr != sEluna->VehicleEventBindings[VEHICLE_EVENT_ON_INSTALL].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, VEHICLE_EVENT_ON_INSTALL);
        sEluna->Push(sEluna->L, vehicle);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnUninstall(Vehicle* vehicle)
{
    for (std::vector<int>::const_iterator itr = sEluna->VehicleEventBindings[VEHICLE_EVENT_ON_UNINSTALL].begin();
        itr != sEluna->VehicleEventBindings[VEHICLE_EVENT_ON_UNINSTALL].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, VEHICLE_EVENT_ON_UNINSTALL);
        sEluna->Push(sEluna->L, vehicle);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnReset(Vehicle* vehicle)
{
    for (std::vector<int>::const_iterator itr = sEluna->VehicleEventBindings[VEHICLE_EVENT_ON_RESET].begin();
        itr != sEluna->VehicleEventBindings[VEHICLE_EVENT_ON_RESET].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, VEHICLE_EVENT_ON_RESET);
        sEluna->Push(sEluna->L, vehicle);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnInstallAccessory(Vehicle* vehicle, Creature* accessory)
{
    for (std::vector<int>::const_iterator itr = sEluna->VehicleEventBindings[VEHICLE_EVENT_ON_INSTALL_ACCESSORY].begin();
        itr != sEluna->VehicleEventBindings[VEHICLE_EVENT_ON_INSTALL_ACCESSORY].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, VEHICLE_EVENT_ON_INSTALL_ACCESSORY);
        sEluna->Push(sEluna->L, vehicle);
        sEluna->Push(sEluna->L, accessory);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnAddPassenger(Vehicle* vehicle, Unit* passenger, int8 seatId)
{
    for (std::vector<int>::const_iterator itr = sEluna->VehicleEventBindings[VEHICLE_EVENT_ON_ADD_PASSENGER].begin();
        itr != sEluna->VehicleEventBindings[VEHICLE_EVENT_ON_ADD_PASSENGER].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, VEHICLE_EVENT_ON_ADD_PASSENGER);
        sEluna->Push(sEluna->L, vehicle);
        sEluna->Push(sEluna->L, passenger);
        sEluna->Push(sEluna->L, seatId);
        sEluna->ExecuteCall(4, 0);
    }
}

void HookMgr::OnRemovePassenger(Vehicle* vehicle, Unit* passenger)
{
    for (std::vector<int>::const_iterator itr = sEluna->VehicleEventBindings[VEHICLE_EVENT_ON_REMOVE_PASSENGER].begin();
        itr != sEluna->VehicleEventBindings[VEHICLE_EVENT_ON_REMOVE_PASSENGER].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, VEHICLE_EVENT_ON_REMOVE_PASSENGER);
        sEluna->Push(sEluna->L, vehicle);
        sEluna->Push(sEluna->L, passenger);
        sEluna->ExecuteCall(3, 0);
    }
}

// areatrigger
bool HookMgr::OnAreaTrigger(Player* pPlayer, AreaTriggerEntry const* pTrigger)
{
    for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[TRIGGER_EVENT_ON_TRIGGER].begin();
        itr != sEluna->ServerEventBindings[TRIGGER_EVENT_ON_TRIGGER].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, TRIGGER_EVENT_ON_TRIGGER);
        sEluna->Push(sEluna->L, pPlayer);
        sEluna->Push(sEluna->L, pTrigger->id);
        sEluna->ExecuteCall(3, 0);
    }
    return false;
}
// weather
void HookMgr::OnChange(Weather* weather, WeatherState state, float grade)
{
    for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WEATHER_EVENT_ON_CHANGE].begin();
        itr != sEluna->ServerEventBindings[WEATHER_EVENT_ON_CHANGE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, WEATHER_EVENT_ON_CHANGE);
        sEluna->Push(sEluna->L, (weather->GetZone()));
        sEluna->Push(sEluna->L, state);
        sEluna->Push(sEluna->L, grade);
        sEluna->ExecuteCall(4, 0);
    }
}
// transport
void HookMgr::OnAddPassenger(Transport* transport, Player* player)
{
}
void HookMgr::OnAddCreaturePassenger(Transport* transport, Creature* creature)
{
}
void HookMgr::OnRemovePassenger(Transport* transport, Player* player)
{
}
void HookMgr::OnRelocate(Transport* transport, uint32 waypointId, uint32 mapId, float x, float y, float z)
{
}
// Auction House
void HookMgr::OnAdd(AuctionHouseObject* ah)
{
    for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[AUCTION_EVENT_ON_ADD].begin();
        itr != sEluna->ServerEventBindings[AUCTION_EVENT_ON_ADD].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, AUCTION_EVENT_ON_ADD);
        sEluna->Push(sEluna->L, (ah));
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnRemove(AuctionHouseObject* ah)
{
    for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[AUCTION_EVENT_ON_REMOVE].begin();
        itr != sEluna->ServerEventBindings[AUCTION_EVENT_ON_REMOVE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, AUCTION_EVENT_ON_REMOVE);
        sEluna->Push(sEluna->L, (ah));
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnSuccessful(AuctionHouseObject* ah)
{
    for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[AUCTION_EVENT_ON_SUCCESSFUL].begin();
        itr != sEluna->ServerEventBindings[AUCTION_EVENT_ON_SUCCESSFUL].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, AUCTION_EVENT_ON_SUCCESSFUL);
        sEluna->Push(sEluna->L, (ah));
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnExpire(AuctionHouseObject* ah)
{
    for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[AUCTION_EVENT_ON_EXPIRE].begin();
        itr != sEluna->ServerEventBindings[AUCTION_EVENT_ON_EXPIRE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, AUCTION_EVENT_ON_EXPIRE);
        sEluna->Push(sEluna->L, (ah));
        sEluna->ExecuteCall(2, 0);
    }
}

struct HookMgr::ElunaWorldAI : public WorldScript
{
public:
    ElunaWorldAI() : WorldScript("ElunaWorldAI") { }
    ~ElunaWorldAI() { }

    void OnOpenStateChange(bool open) OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_OPEN_STATE_CHANGE].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_OPEN_STATE_CHANGE].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->Push(sEluna->L, WORLD_EVENT_ON_OPEN_STATE_CHANGE);
            sEluna->Push(sEluna->L, open);
            sEluna->ExecuteCall(2, 0);
        }
    }

    void OnConfigLoad(bool reload) OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_CONFIG_LOAD].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_CONFIG_LOAD].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->Push(sEluna->L, WORLD_EVENT_ON_CONFIG_LOAD);
            sEluna->Push(sEluna->L, reload);
            sEluna->ExecuteCall(2, 0);
        }
    }

    void OnMotdChange(std::string& newMotd) OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_MOTD_CHANGE].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_MOTD_CHANGE].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->Push(sEluna->L, WORLD_EVENT_ON_MOTD_CHANGE);
            sEluna->Push(sEluna->L, newMotd);
            sEluna->ExecuteCall(2, 0);
        }
    }

    void OnShutdownInitiate(ShutdownExitCode code, ShutdownMask mask) OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN_INIT].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN_INIT].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->Push(sEluna->L, WORLD_EVENT_ON_SHUTDOWN_INIT);
            sEluna->Push(sEluna->L, code);
            sEluna->Push(sEluna->L, mask);
            sEluna->ExecuteCall(3, 0);
        }
    }

    void OnShutdownCancel() OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN_CANCEL].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN_CANCEL].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->Push(sEluna->L, WORLD_EVENT_ON_SHUTDOWN_CANCEL);
            sEluna->ExecuteCall(1, 0);
        }
    }

    void OnUpdate(uint32 diff) OVERRIDE
    {
        sEluna->m_EventMgr.Update(diff);
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_UPDATE].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_UPDATE].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->Push(sEluna->L, WORLD_EVENT_ON_UPDATE);
            sEluna->Push(sEluna->L, diff);
            sEluna->ExecuteCall(2, 0);
        }
    }
    // executed when a  timed event fires
    void OnScriptEvent(int funcRef, uint32 delay, uint32 calls) OVERRIDE
    {
        sEluna->BeginCall(funcRef);
        sEluna->Push(sEluna->L, funcRef);
        sEluna->Push(sEluna->L, delay);
        sEluna->Push(sEluna->L, calls);
        sEluna->ExecuteCall(3, 0);
    }

    void OnStartup() OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_STARTUP].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_STARTUP].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->Push(sEluna->L, WORLD_EVENT_ON_STARTUP);
            sEluna->ExecuteCall(1, 0);
        }
    }

    void OnShutdown() OVERRIDE
    {
        for (std::vector<int>::const_iterator itr = sEluna->ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN].begin();
            itr != sEluna->ServerEventBindings[WORLD_EVENT_ON_SHUTDOWN].end(); ++itr)
        {
            sEluna->BeginCall((*itr));
            sEluna->Push(sEluna->L, WORLD_EVENT_ON_SHUTDOWN);
            sEluna->ExecuteCall(1, 0);
        }
    }
};

struct HookMgr::ElunaCreatureAI : ScriptedAI
{
    ElunaCreatureAI(Creature* creature) : ScriptedAI(creature) { }
    ~ElunaCreatureAI() { }

    //Called at World update tick
    void UpdateAI(uint32 diff) OVERRIDE
    {
        ScriptedAI::UpdateAI(diff);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_AIUPDATE);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_AIUPDATE);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, diff);
        sEluna->ExecuteCall(3, 0);
    }

    //Called for reaction at enter to combat if not in combat yet (enemy can be NULL)
    //Called at creature aggro either by MoveInLOS or Attack Start
    void EnterCombat(Unit* target) OVERRIDE
    {
        ScriptedAI::EnterCombat(target);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_ENTER_COMBAT);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_ENTER_COMBAT);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, target);
        sEluna->ExecuteCall(3, 0);
    }

    // Called at any Damage from any attacker (before damage apply)
    void DamageTaken(Unit* attacker, uint32& damage) OVERRIDE
    {
        ScriptedAI::DamageTaken(attacker, damage);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_DAMAGE_TAKEN);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_DAMAGE_TAKEN);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, attacker);
        sEluna->Push(sEluna->L, damage);
        sEluna->ExecuteCall(4, 0);
    }

    //Called at creature death
    void JustDied(Unit* killer) OVERRIDE
    {
        ScriptedAI::JustDied(killer);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_DIED);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_DIED);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, killer);
        sEluna->ExecuteCall(3, 0);
    }

    //Called at creature killing another unit
    void KilledUnit(Unit* victim) OVERRIDE
    {
        ScriptedAI::KilledUnit(victim);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_TARGET_DIED);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_TARGET_DIED);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, victim);
        sEluna->ExecuteCall(3, 0);
    }

    // Called when the creature summon successfully other creature
    void JustSummoned(Creature* summon) OVERRIDE
    {
        ScriptedAI::JustSummoned(summon);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_JUST_SUMMONED_CREATURE);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, summon);
        sEluna->ExecuteCall(3, 0);
    }

    // Called when a summoned creature is despawned
    void SummonedCreatureDespawn(Creature* summon) OVERRIDE
    {
        ScriptedAI::SummonedCreatureDespawn(summon);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_SUMMONED_CREATURE_DESPAWN);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, summon);
        sEluna->ExecuteCall(3, 0);
    }

    // Called when hit by a spell
    void SpellHit(Unit* caster, SpellInfo const* spell) OVERRIDE
    {
        ScriptedAI::SpellHit(caster, spell);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_HIT_BY_SPELL);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_HIT_BY_SPELL);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, caster);
        sEluna->Push(sEluna->L, spell->Id); // Pass spell object?
        sEluna->ExecuteCall(4, 0);
    }

    // Called when spell hits a target
    void SpellHitTarget(Unit* target, SpellInfo const* spell) OVERRIDE
    {
        ScriptedAI::SpellHitTarget(target, spell);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPELL_HIT_TARGET);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_SPELL_HIT_TARGET);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, target);
        sEluna->Push(sEluna->L, spell->Id); // Pass spell object?
        sEluna->ExecuteCall(4, 0);
    }

    //Called at waypoint reached or PointMovement end
    void MovementInform(uint32 type, uint32 id) OVERRIDE
    {
        ScriptedAI::MovementInform(type, id);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_REACH_WP);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_REACH_WP);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, type);
        sEluna->Push(sEluna->L, id);
        sEluna->ExecuteCall(4, 0);
    }

    // Called when AI is temporarily replaced or put back when possess is applied or removed
    void OnPossess(bool apply) OVERRIDE
    {
        ScriptedAI::OnPossess(apply);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_POSSESS);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_POSSESS);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, apply);
        sEluna->ExecuteCall(3, 0);
    }

    //Called at creature reset either by death or evade
    void Reset() OVERRIDE
    {
        ScriptedAI::Reset();
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_RESET);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_RESET);
        sEluna->Push(sEluna->L, me);
        sEluna->ExecuteCall(2, 0);
    }

    // Called before EnterCombat even before the creature is in combat.
    void AttackStart(Unit* target) OVERRIDE
    {
        ScriptedAI::AttackStart(target);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_PRE_COMBAT);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_PRE_COMBAT);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, target);
        sEluna->ExecuteCall(3, 0);
    }

    // Called in Creature::Update when deathstate = DEAD. Inherited classes may maniuplate the ability to respawn based on scripted events.
    bool CanRespawn() OVERRIDE
    {
        ScriptedAI::CanRespawn();
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CAN_RESPAWN);
        if (!bind)
            return true;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_CAN_RESPAWN);
        sEluna->Push(sEluna->L, me);
        sEluna->ExecuteCall(2, 0);
        return true;
    }

    // Called for reaction at stopping attack at no attackers or targets
    void EnterEvadeMode() OVERRIDE
    {
        ScriptedAI::EnterEvadeMode();
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_LEAVE_COMBAT);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_LEAVE_COMBAT);
        sEluna->Push(sEluna->L, me);
        sEluna->ExecuteCall(2, 0);
    }

    // Called when the creature is summoned successfully by other creature
    void IsSummonedBy(Unit* summoner) OVERRIDE
    {
        ScriptedAI::IsSummonedBy(summoner);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_SUMMONED);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, summoner);
        sEluna->ExecuteCall(3, 0);
    }

    void SummonedCreatureDies(Creature* summon, Unit* killer) OVERRIDE
    {
        ScriptedAI::SummonedCreatureDies(summon, killer);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_SUMMONED_CREATURE_DIED);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, summon);
        sEluna->Push(sEluna->L, killer);
        sEluna->ExecuteCall(4, 0);
    }

    // Called when the creature is target of hostile action: swing, hostile spell landed, fear/etc)
    void AttackedBy(Unit* attacker) OVERRIDE
    {
        ScriptedAI::AttackedBy(attacker);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_ATTACKED_AT);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_ATTACKED_AT);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, attacker);
        sEluna->ExecuteCall(3, 0);
    }

    // Called when creature is spawned or respawned (for reseting variables)
    void JustRespawned() OVERRIDE
    {
        ScriptedAI::JustRespawned();
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPAWN);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_SPAWN);
        sEluna->Push(sEluna->L, me);
        sEluna->ExecuteCall(2, 0);
    }

    void OnCharmed(bool apply) OVERRIDE
    {
        ScriptedAI::OnCharmed(apply);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CHARMED);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_CHARMED);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, apply);
        sEluna->ExecuteCall(3, 0);
    }

    // Called at reaching home after evade
    void JustReachedHome() OVERRIDE
    {
        ScriptedAI::JustReachedHome();
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_REACH_HOME);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_REACH_HOME);
        sEluna->Push(sEluna->L, me);
        sEluna->ExecuteCall(2, 0);
    }

    // Called at text emote receive from player
    void ReceiveEmote(Player* player, uint32 emoteId) OVERRIDE
    {
        ScriptedAI::ReceiveEmote(player, emoteId);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_RECEIVE_EMOTE);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_RECEIVE_EMOTE);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, player);
        sEluna->Push(sEluna->L, emoteId);
        sEluna->ExecuteCall(4, 0);
    }

    // Called when owner takes damage
    void OwnerAttackedBy(Unit* attacker) OVERRIDE
    {
        ScriptedAI::OwnerAttackedBy(attacker);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_OWNER_ATTACKED_AT);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, attacker);
        sEluna->ExecuteCall(3, 0);
    }

    // Called when owner attacks something
    void OwnerAttacked(Unit* target) OVERRIDE
    {
        ScriptedAI::OwnerAttacked(target);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_OWNER_ATTACKED);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_OWNER_ATTACKED);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, target);
        sEluna->ExecuteCall(3, 0);
    }

    // called when the corpse of this creature gets removed
    void CorpseRemoved(uint32& respawnDelay) OVERRIDE
    {
        ScriptedAI::CorpseRemoved(respawnDelay);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_CORPSE_REMOVED);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_CORPSE_REMOVED);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, respawnDelay);
        sEluna->ExecuteCall(3, 0);
    }

    void PassengerBoarded(Unit* passenger, int8 seatId, bool apply) OVERRIDE
    {
        ScriptedAI::PassengerBoarded(passenger, seatId, apply);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_PASSANGER_BOARDED);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_PASSANGER_BOARDED);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, passenger);
        sEluna->Push(sEluna->L, seatId);
        sEluna->Push(sEluna->L, apply);
        sEluna->ExecuteCall(5, 0);
    }

    void OnSpellClick(Unit* clicker, bool& result) OVERRIDE
    {
        ScriptedAI::OnSpellClick(clicker, result);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_SPELL_CLICK);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_SPELL_CLICK);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, clicker);
        sEluna->Push(sEluna->L, result);
        sEluna->ExecuteCall(4, 0);
    }

    void MoveInLineOfSight(Unit* who) OVERRIDE
    {
        ScriptedAI::MoveInLineOfSight(who);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_MOVE_IN_LOS);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_MOVE_IN_LOS);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, who);
        sEluna->ExecuteCall(3, 0);
    }

    // Called if IsVisible(Unit* who) is true at each who move, reaction at visibility zone enter
    void MoveInLineOfSight_Safe(Unit* who)
    {
        ScriptedAI::MoveInLineOfSight_Safe(who);
        int bind = sEluna->CreatureEventBindings->GetBind(me->GetEntry(), CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, CREATURE_EVENT_ON_VISIBLE_MOVE_IN_LOS);
        sEluna->Push(sEluna->L, me);
        sEluna->Push(sEluna->L, who);
        sEluna->ExecuteCall(3, 0);
    }
};

struct HookMgr::ElunaGameObjectAI : public GameObjectAI
{
    ElunaGameObjectAI(GameObject* _go) : GameObjectAI(_go) { }
    ~ElunaGameObjectAI()
    {
    }

    void UpdateAI(uint32 diff) OVERRIDE
    {
        int bind = sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_AIUPDATE);
        if (!bind)
            return;
        sEluna->BeginCall(bind);
        sEluna->Push(sEluna->L, GAMEOBJECT_EVENT_ON_AIUPDATE);
        sEluna->Push(sEluna->L, go);
        sEluna->Push(sEluna->L, diff);
        sEluna->ExecuteCall(3, 0);
    }

    // executed when a timed event fires
    void OnScriptEvent(int funcRef, uint32 delay, uint32 calls) OVERRIDE
    {
        sEluna->BeginCall(funcRef);
        sEluna->Push(sEluna->L, funcRef);
        sEluna->Push(sEluna->L, delay);
        sEluna->Push(sEluna->L, calls);
        sEluna->Push(sEluna->L, go);
        sEluna->ExecuteCall(4, 0);
    }

    void Reset() OVERRIDE
    {
        sEluna->BeginCall(sEluna->GameObjectEventBindings->GetBind(go->GetEntry(), GAMEOBJECT_EVENT_ON_RESET));
        sEluna->Push(sEluna->L, GAMEOBJECT_EVENT_ON_RESET);
        sEluna->Push(sEluna->L, go);
        sEluna->ExecuteCall(2, 0);
    }
};

void HookMgr::OnAddMember(Guild* guild, Player* player, uint32 plRank)
{
    for (std::vector<int>::const_iterator itr = sEluna->GuildEventBindings[GUILD_EVENT_ON_ADD_MEMBER].begin();
        itr != sEluna->GuildEventBindings[GUILD_EVENT_ON_ADD_MEMBER].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GUILD_EVENT_ON_ADD_MEMBER);
        sEluna->Push(sEluna->L, guild);
        sEluna->Push(sEluna->L, player);
        sEluna->Push(sEluna->L, plRank);
        sEluna->ExecuteCall(4, 0);
    }
}

void HookMgr::OnRemoveMember(Guild* guild, Player* player, bool isDisbanding, bool isKicked) // IsKicked not a part of Mangos, implement?
{
    for (std::vector<int>::const_iterator itr = sEluna->GuildEventBindings[GUILD_EVENT_ON_REMOVE_MEMBER].begin();
        itr != sEluna->GuildEventBindings[GUILD_EVENT_ON_REMOVE_MEMBER].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GUILD_EVENT_ON_REMOVE_MEMBER);
        sEluna->Push(sEluna->L, guild);
        sEluna->Push(sEluna->L, player);
        sEluna->Push(sEluna->L, isDisbanding);
        sEluna->Push(sEluna->L, isKicked); // IsKicked not a part of Mangos, implement?
        sEluna->ExecuteCall(5, 0);
    }
}

void HookMgr::OnMOTDChanged(Guild* guild, const std::string& newMotd)
{
    for (std::vector<int>::const_iterator itr = sEluna->GuildEventBindings[GUILD_EVENT_ON_MOTD_CHANGE].begin();
        itr != sEluna->GuildEventBindings[GUILD_EVENT_ON_MOTD_CHANGE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GUILD_EVENT_ON_MOTD_CHANGE);
        sEluna->Push(sEluna->L, guild);
        sEluna->Push(sEluna->L, newMotd);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnInfoChanged(Guild* guild, const std::string& newInfo)
{
    for (std::vector<int>::const_iterator itr = sEluna->GuildEventBindings[GUILD_EVENT_ON_INFO_CHANGE].begin();
        itr != sEluna->GuildEventBindings[GUILD_EVENT_ON_INFO_CHANGE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GUILD_EVENT_ON_INFO_CHANGE);
        sEluna->Push(sEluna->L, guild);
        sEluna->Push(sEluna->L, newInfo);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnCreate(Guild* guild, Player* leader, const std::string& name)
{
    for (std::vector<int>::const_iterator itr = sEluna->GuildEventBindings[GUILD_EVENT_ON_CREATE].begin();
        itr != sEluna->GuildEventBindings[GUILD_EVENT_ON_CREATE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GUILD_EVENT_ON_CREATE);
        sEluna->Push(sEluna->L, guild);
        sEluna->Push(sEluna->L, leader);
        sEluna->Push(sEluna->L, name);
        sEluna->ExecuteCall(4, 0);
    }
}

void HookMgr::OnDisband(Guild* guild)
{
    for (std::vector<int>::const_iterator itr = sEluna->GuildEventBindings[GUILD_EVENT_ON_DISBAND].begin();
        itr != sEluna->GuildEventBindings[GUILD_EVENT_ON_DISBAND].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GUILD_EVENT_ON_DISBAND);
        sEluna->Push(sEluna->L, guild);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnMemberWitdrawMoney(Guild* guild, Player* player, uint32 &amount, bool isRepair) // isRepair not a part of Mangos, implement?
{
    for (std::vector<int>::const_iterator itr = sEluna->GuildEventBindings[GUILD_EVENT_ON_MONEY_WITHDRAW].begin();
        itr != sEluna->GuildEventBindings[GUILD_EVENT_ON_MONEY_WITHDRAW].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GUILD_EVENT_ON_MONEY_WITHDRAW);
        sEluna->Push(sEluna->L, guild);
        sEluna->Push(sEluna->L, player);
        sEluna->Push(sEluna->L, amount);
        sEluna->Push(sEluna->L, isRepair); // isRepair not a part of Mangos, implement?
        sEluna->ExecuteCall(5, 0);
    }
}

void HookMgr::OnMemberDepositMoney(Guild* guild, Player* player, uint32 &amount)
{
    for (std::vector<int>::const_iterator itr = sEluna->GuildEventBindings[GUILD_EVENT_ON_MONEY_DEPOSIT].begin();
        itr != sEluna->GuildEventBindings[GUILD_EVENT_ON_MONEY_DEPOSIT].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GUILD_EVENT_ON_MONEY_DEPOSIT);
        sEluna->Push(sEluna->L, guild);
        sEluna->Push(sEluna->L, player);
        sEluna->Push(sEluna->L, amount);
        sEluna->ExecuteCall(4, 0);
    }
}

void HookMgr::OnItemMove(Guild* guild, Player* player, Item* pItem, bool isSrcBank, uint8 srcContainer, uint8 srcSlotId,
                bool isDestBank, uint8 destContainer, uint8 destSlotId)
{
    for (std::vector<int>::const_iterator itr = sEluna->GuildEventBindings[GUILD_EVENT_ON_ITEM_MOVE].begin();
        itr != sEluna->GuildEventBindings[GUILD_EVENT_ON_ITEM_MOVE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GUILD_EVENT_ON_ITEM_MOVE);
        sEluna->Push(sEluna->L, guild);
        sEluna->Push(sEluna->L, player);
        sEluna->Push(sEluna->L, pItem);
        sEluna->Push(sEluna->L, isSrcBank);
        sEluna->Push(sEluna->L, srcContainer);
        sEluna->Push(sEluna->L, srcSlotId);
        sEluna->Push(sEluna->L, isDestBank);
        sEluna->Push(sEluna->L, destContainer);
        sEluna->Push(sEluna->L, destSlotId);
        sEluna->ExecuteCall(10, 0);
    }
}

void HookMgr::OnEvent(Guild* guild, uint8 eventType, uint32 playerGuid1, uint32 playerGuid2, uint8 newRank)
{
    for (std::vector<int>::const_iterator itr = sEluna->GuildEventBindings[GUILD_EVENT_ON_EVENT].begin();
        itr != sEluna->GuildEventBindings[GUILD_EVENT_ON_EVENT].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GUILD_EVENT_ON_EVENT);
        sEluna->Push(sEluna->L, guild);
        sEluna->Push(sEluna->L, eventType);
        sEluna->Push(sEluna->L, playerGuid1);
        sEluna->Push(sEluna->L, playerGuid2);
        sEluna->Push(sEluna->L, newRank);
        sEluna->ExecuteCall(6, 0);
    }
}

void HookMgr::OnBankEvent(Guild* guild, uint8 eventType, uint8 tabId, uint32 playerGuid, uint32 itemOrMoney, uint16 itemStackCount, uint8 destTabId)
{
    for (std::vector<int>::const_iterator itr = sEluna->GuildEventBindings[GUILD_EVENT_ON_BANK_EVENT].begin();
        itr != sEluna->GuildEventBindings[GUILD_EVENT_ON_BANK_EVENT].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GUILD_EVENT_ON_BANK_EVENT);
        sEluna->Push(sEluna->L, guild);
        sEluna->Push(sEluna->L, eventType);
        sEluna->Push(sEluna->L, tabId);
        sEluna->Push(sEluna->L, playerGuid);
        sEluna->Push(sEluna->L, itemOrMoney);
        sEluna->Push(sEluna->L, itemStackCount);
        sEluna->Push(sEluna->L, destTabId);
        sEluna->ExecuteCall(8, 0);
    }
}
// Group
void HookMgr::OnAddMember(Group* group, uint64 guid)
{
    for (std::vector<int>::const_iterator itr = sEluna->GroupEventBindings[GROUP_EVENT_ON_MEMBER_ADD].begin();
        itr != sEluna->GroupEventBindings[GROUP_EVENT_ON_MEMBER_ADD].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GROUP_EVENT_ON_MEMBER_ADD);
        sEluna->Push(sEluna->L, group);
        sEluna->Push(sEluna->L, guid);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnInviteMember(Group* group, uint64 guid)
{
    for (std::vector<int>::const_iterator itr = sEluna->GroupEventBindings[GROUP_EVENT_ON_MEMBER_INVITE].begin();
        itr != sEluna->GroupEventBindings[GROUP_EVENT_ON_MEMBER_INVITE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GROUP_EVENT_ON_MEMBER_INVITE);
        sEluna->Push(sEluna->L, group);
        sEluna->Push(sEluna->L, guid);
        sEluna->ExecuteCall(3, 0);
    }
}

void HookMgr::OnRemoveMember(Group* group, uint64 guid, uint8 method, uint64 kicker, const char* reason) // Kicker and Reason not a part of Mangos, implement?
{
    for (std::vector<int>::const_iterator itr = sEluna->GroupEventBindings[GROUP_EVENT_ON_MEMBER_REMOVE].begin();
        itr != sEluna->GroupEventBindings[GROUP_EVENT_ON_MEMBER_REMOVE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GROUP_EVENT_ON_MEMBER_REMOVE);
        sEluna->Push(sEluna->L, group);
        sEluna->Push(sEluna->L, guid);
        sEluna->Push(sEluna->L, method);
        sEluna->Push(sEluna->L, kicker); // Kicker and Reason not a part of Mangos, implement?
        sEluna->Push(sEluna->L, reason);
        sEluna->ExecuteCall(6, 0);
    }
}

void HookMgr::OnChangeLeader(Group* group, uint64 newLeaderGuid, uint64 oldLeaderGuid)
{
    for (std::vector<int>::const_iterator itr = sEluna->GroupEventBindings[GROUP_EVENT_ON_LEADER_CHANGE].begin();
        itr != sEluna->GroupEventBindings[GROUP_EVENT_ON_LEADER_CHANGE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GROUP_EVENT_ON_LEADER_CHANGE);
        sEluna->Push(sEluna->L, group);
        sEluna->Push(sEluna->L, newLeaderGuid);
        sEluna->Push(sEluna->L, oldLeaderGuid);
        sEluna->ExecuteCall(4, 0);
    }
}

void HookMgr::OnDisband(Group* group)
{
    for (std::vector<int>::const_iterator itr = sEluna->GroupEventBindings[GROUP_EVENT_ON_DISBAND].begin();
        itr != sEluna->GroupEventBindings[GROUP_EVENT_ON_DISBAND].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GROUP_EVENT_ON_DISBAND);
        sEluna->Push(sEluna->L, group);
        sEluna->ExecuteCall(2, 0);
    }
}

void HookMgr::OnCreate(Group* group, uint64 leaderGuid, GroupType groupType)
{
    for (std::vector<int>::const_iterator itr = sEluna->GroupEventBindings[GROUP_EVENT_ON_CREATE].begin();
        itr != sEluna->GroupEventBindings[GROUP_EVENT_ON_CREATE].end(); ++itr)
    {
        sEluna->BeginCall((*itr));
        sEluna->Push(sEluna->L, GROUP_EVENT_ON_CREATE);
        sEluna->Push(sEluna->L, group);
        sEluna->Push(sEluna->L, leaderGuid);
        sEluna->Push(sEluna->L, groupType);
        sEluna->ExecuteCall(4, 0);
    }
}

CreatureAI* HookMgr::GetAI(Creature* creature)
{
    if (!sEluna->CreatureEventBindings->GetBindMap(creature->GetEntry()))
        return NULL;
    return new ElunaCreatureAI(creature);
}

GameObjectAI* HookMgr::GetAI(GameObject* gameObject)
{
    if (!sEluna->GameObjectEventBindings->GetBindMap(gameObject->GetEntry()))
        return NULL;
    return new ElunaGameObjectAI(gameObject);
}

void AddElunaScripts()
{
    new HookMgr::ElunaWorldAI();
}
