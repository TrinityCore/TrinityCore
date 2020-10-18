/*
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
 * This program is free software licensed under GPL version 3
 * Please see the included DOCS/LICENSE.md for more information
 */

#include "Hooks.h"
#include "HookHelpers.h"
#include "LuaEngine.h"
#include "BindingMap.h"
#include "ElunaIncludes.h"
#include "ElunaTemplate.h"

using namespace Hooks;

#define START_HOOK(EVENT, ENTRY) \
    if (!IsEnabled())\
        return;\
    auto key = EntryKey<ItemEvents>(EVENT, ENTRY);\
    if (!ItemEventBindings->HasBindingsFor(key))\
        return;\
    LOCK_ELUNA

#define START_HOOK_WITH_RETVAL(EVENT, ENTRY, RETVAL) \
    if (!IsEnabled())\
        return RETVAL;\
    auto key = EntryKey<ItemEvents>(EVENT, ENTRY);\
    if (!ItemEventBindings->HasBindingsFor(key))\
        return RETVAL;\
    LOCK_ELUNA

void Eluna::OnDummyEffect(WorldObject* pCaster, uint32 spellId, SpellEffIndex effIndex, Item* pTarget)
{
    START_HOOK(ITEM_EVENT_ON_DUMMY_EFFECT, pTarget->GetEntry());
    Push(pCaster);
    Push(spellId);
    Push(effIndex);
    Push(pTarget);
    CallAllFunctions(ItemEventBindings, key);
}

bool Eluna::OnQuestAccept(Player* pPlayer, Item* pItem, Quest const* pQuest)
{
    START_HOOK_WITH_RETVAL(ITEM_EVENT_ON_QUEST_ACCEPT, pItem->GetEntry(), false);
    Push(pPlayer);
    Push(pItem);
    Push(pQuest);
    return CallAllFunctionsBool(ItemEventBindings, key);
}

bool Eluna::OnUse(Player* pPlayer, Item* pItem, SpellCastTargets const& targets)
{
    ObjectGuid guid = pItem->GET_GUID();
    bool castSpell = true;

    if (!OnItemUse(pPlayer, pItem, targets))
        castSpell = false;

    pItem = pPlayer->GetItemByGuid(guid);
    if (pItem)
    {
        if (!OnItemGossip(pPlayer, pItem, targets))
            castSpell = false;
        pItem = pPlayer->GetItemByGuid(guid);
    }

    if (pItem && castSpell)
        return true;

    // Send equip error that shows no message
    // This is a hack fix to stop spell casting visual bug when a spell is not cast on use
    WorldPacket data(SMSG_INVENTORY_CHANGE_FAILURE, 18);
    data << uint8(59); // EQUIP_ERR_NONE / EQUIP_ERR_CANT_BE_DISENCHANTED
    data << ObjectGuid(guid);
    data << ObjectGuid(uint64(0));
    data << uint8(0);
#ifdef CMANGOS
    pPlayer->GetSession()->SendPacket(data);
#else
    pPlayer->GetSession()->SendPacket(&data);
#endif
    return false;
}

bool Eluna::OnItemUse(Player* pPlayer, Item* pItem, SpellCastTargets const& targets)
{
    START_HOOK_WITH_RETVAL(ITEM_EVENT_ON_USE, pItem->GetEntry(), true);
    Push(pPlayer);
    Push(pItem);
#if defined TRINITY || AZEROTHCORE
    if (GameObject* target = targets.GetGOTarget())
        Push(target);
    else if (Item* target = targets.GetItemTarget())
        Push(target);
    else if (Corpse* target = targets.GetCorpseTarget())
        Push(target);
    else if (Unit* target = targets.GetUnitTarget())
        Push(target);
    else if (WorldObject* target = targets.GetObjectTarget())
        Push(target);
    else
        Push();
#else
    if (GameObject* target = targets.getGOTarget())
        Push(target);
    else if (Item* target = targets.getItemTarget())
        Push(target);
    else if (Corpse* target = pPlayer->GetMap()->GetCorpse(targets.getCorpseTargetGuid()))
        Push(target);
    else if (Unit* target = targets.getUnitTarget())
        Push(target);
    else
        Push();
#endif

    return CallAllFunctionsBool(ItemEventBindings, key, true);
}

bool Eluna::OnExpire(Player* pPlayer, ItemTemplate const* pProto)
{
    START_HOOK_WITH_RETVAL(ITEM_EVENT_ON_EXPIRE, pProto->ItemId, false);
    Push(pPlayer);
    Push(pProto->ItemId);
    return CallAllFunctionsBool(ItemEventBindings, key);
}

bool Eluna::OnRemove(Player* pPlayer, Item* pItem)
{
    START_HOOK_WITH_RETVAL(ITEM_EVENT_ON_REMOVE, pItem->GetEntry(), false);
    Push(pPlayer);
    Push(pItem);
    return CallAllFunctionsBool(ItemEventBindings, key);
}
