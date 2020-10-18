/*
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
 * This program is free software licensed under GPL version 3
 * Please see the included DOCS/LICENSE.md for more information
 */

#include "Hooks.h"
#include "HookHelpers.h"
#include "LuaEngine.h"
#include "BindingMap.h"
#include "ElunaTemplate.h"

using namespace Hooks;

#define START_HOOK(EVENT) \
    if (!IsEnabled())\
        return;\
    auto key = EventKey<BGEvents>(EVENT);\
    if (!BGEventBindings->HasBindingsFor(key))\
        return;\
    LOCK_ELUNA

void Eluna::OnBGStart(BattleGround* bg, BattleGroundTypeId bgId, uint32 instanceId)
{
    START_HOOK(BG_EVENT_ON_START);
    Push(bg);
    Push(bgId);
    Push(instanceId);
    CallAllFunctions(BGEventBindings, key);
}

#if AZEROTHCORE
void Eluna::OnBGEnd(BattleGround* bg, BattleGroundTypeId bgId, uint32 instanceId, TeamId winner)
#else
void Eluna::OnBGEnd(BattleGround* bg, BattleGroundTypeId bgId, uint32 instanceId, Team winner)
#endif
{
    START_HOOK(BG_EVENT_ON_END);
    Push(bg);
    Push(bgId);
    Push(instanceId);
    Push(winner);
    CallAllFunctions(BGEventBindings, key);
}

void Eluna::OnBGCreate(BattleGround* bg, BattleGroundTypeId bgId, uint32 instanceId)
{
    START_HOOK(BG_EVENT_ON_CREATE);
    Push(bg);
    Push(bgId);
    Push(instanceId);
    CallAllFunctions(BGEventBindings, key);
}

void Eluna::OnBGDestroy(BattleGround* bg, BattleGroundTypeId bgId, uint32 instanceId)
{
    START_HOOK(BG_EVENT_ON_PRE_DESTROY);
    Push(bg);
    Push(bgId);
    Push(instanceId);
    CallAllFunctions(BGEventBindings, key);
}
