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
#include "ElunaEventMgr.h"
#include "ElunaTemplate.h"

using namespace Hooks;

#define START_HOOK(EVENT, ENTRY) \
    if (!IsEnabled())\
        return;\
    auto key = EntryKey<GameObjectEvents>(EVENT, ENTRY);\
    if (!GameObjectEventBindings->HasBindingsFor(key))\
        return;\
    LOCK_ELUNA

#define START_HOOK_WITH_RETVAL(EVENT, ENTRY, RETVAL) \
    if (!IsEnabled())\
        return RETVAL;\
    auto key = EntryKey<GameObjectEvents>(EVENT, ENTRY);\
    if (!GameObjectEventBindings->HasBindingsFor(key))\
        return RETVAL;\
    LOCK_ELUNA

void Eluna::OnDummyEffect(WorldObject* pCaster, uint32 spellId, SpellEffIndex effIndex, GameObject* pTarget)
{
    START_HOOK(GAMEOBJECT_EVENT_ON_DUMMY_EFFECT, pTarget->GetEntry());
    Push(pCaster);
    Push(spellId);
    Push(effIndex);
    Push(pTarget);
    CallAllFunctions(GameObjectEventBindings, key);
}

void Eluna::UpdateAI(GameObject* pGameObject, uint32 diff)
{
    pGameObject->elunaEvents->Update(diff);
    START_HOOK(GAMEOBJECT_EVENT_ON_AIUPDATE, pGameObject->GetEntry());
    Push(pGameObject);
    Push(diff);
    CallAllFunctions(GameObjectEventBindings, key);
}

bool Eluna::OnQuestAccept(Player* pPlayer, GameObject* pGameObject, Quest const* pQuest)
{
    START_HOOK_WITH_RETVAL(GAMEOBJECT_EVENT_ON_QUEST_ACCEPT, pGameObject->GetEntry(), false);
    Push(pPlayer);
    Push(pGameObject);
    Push(pQuest);
    return CallAllFunctionsBool(GameObjectEventBindings, key);
}

bool Eluna::OnQuestReward(Player* pPlayer, GameObject* pGameObject, Quest const* pQuest, uint32 opt)
{
    START_HOOK_WITH_RETVAL(GAMEOBJECT_EVENT_ON_QUEST_REWARD, pGameObject->GetEntry(), false);
    Push(pPlayer);
    Push(pGameObject);
    Push(pQuest);
    Push(opt);
    return CallAllFunctionsBool(GameObjectEventBindings, key);
}

void Eluna::GetDialogStatus(const Player* pPlayer, const GameObject* pGameObject)
{
    START_HOOK(GAMEOBJECT_EVENT_ON_DIALOG_STATUS, pGameObject->GetEntry());
    Push(pPlayer);
    Push(pGameObject);
    CallAllFunctions(GameObjectEventBindings, key);
}

#ifndef CLASSIC
#ifndef TBC
void Eluna::OnDestroyed(GameObject* pGameObject, WorldObject* attacker)
{
    START_HOOK(GAMEOBJECT_EVENT_ON_DESTROYED, pGameObject->GetEntry());
    Push(pGameObject);
    Push(attacker);
    CallAllFunctions(GameObjectEventBindings, key);
}

void Eluna::OnDamaged(GameObject* pGameObject, WorldObject* attacker)
{
    START_HOOK(GAMEOBJECT_EVENT_ON_DAMAGED, pGameObject->GetEntry());
    Push(pGameObject);
    Push(attacker);
    CallAllFunctions(GameObjectEventBindings, key);
}
#endif
#endif

void Eluna::OnLootStateChanged(GameObject* pGameObject, uint32 state)
{
    START_HOOK(GAMEOBJECT_EVENT_ON_LOOT_STATE_CHANGE, pGameObject->GetEntry());
    Push(pGameObject);
    Push(state);
    CallAllFunctions(GameObjectEventBindings, key);
}

void Eluna::OnGameObjectStateChanged(GameObject* pGameObject, uint32 state)
{
    START_HOOK(GAMEOBJECT_EVENT_ON_GO_STATE_CHANGED, pGameObject->GetEntry());
    Push(pGameObject);
    Push(state);
    CallAllFunctions(GameObjectEventBindings, key);
}

void Eluna::OnSpawn(GameObject* pGameObject)
{
    START_HOOK(GAMEOBJECT_EVENT_ON_SPAWN, pGameObject->GetEntry());
    Push(pGameObject);
    CallAllFunctions(GameObjectEventBindings, key);
}

void Eluna::OnAddToWorld(GameObject* pGameObject)
{
    START_HOOK(GAMEOBJECT_EVENT_ON_ADD, pGameObject->GetEntry());
    Push(pGameObject);
    CallAllFunctions(GameObjectEventBindings, key);
}

void Eluna::OnRemoveFromWorld(GameObject* pGameObject)
{
    START_HOOK(GAMEOBJECT_EVENT_ON_REMOVE, pGameObject->GetEntry());
    Push(pGameObject);
    CallAllFunctions(GameObjectEventBindings, key);
}

bool Eluna::OnGameObjectUse(Player* pPlayer, GameObject* pGameObject)
{
    START_HOOK_WITH_RETVAL(GAMEOBJECT_EVENT_ON_USE, pGameObject->GetEntry(), false);
    Push(pGameObject);
    Push(pPlayer);
    return CallAllFunctionsBool(GameObjectEventBindings, key);
}
