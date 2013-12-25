/*
* Copyright (C) 2010 - 2013 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef CREATUREMETHODS_H
#define CREATUREMETHODS_H

namespace LuaCreature
{
    int IsDamageEnoughForLootingAndReward(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->IsDamageEnoughForLootingAndReward());
        return 1;
    }

    int IsReputationGainDisabled(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->IsReputationGainDisabled());
        return 1;
    }

    int SetDisableReputationGain(lua_State* L, Creature* creature)
    {
        bool disable = luaL_optbool(L, 1, true);

        creature->SetDisableReputationGain(disable);
        return 0;
    }

    int GetCurrentWaypointId(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetCurrentWaypointID());
        return 1;
    }

    int GetWaypointPath(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetWaypointPath());
        return 1;
    }

    int GetTransportHomePosition(lua_State* L, Creature* creature)
    {
        float x,y,z,o;
        creature->GetTransportHomePosition(x,y,z,o);

        sEluna->Push(L, x);
        sEluna->Push(L, y);
        sEluna->Push(L, z);
        sEluna->Push(L, o);
        return 4;
    }

    int IsRegeneratingHealth(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->isRegeneratingHealth());
        return 1;
    }

    int HasInvolvedQuest(lua_State* L, Creature* creature)
    {
        uint32 quest_id = luaL_checkunsigned(L, 1);

        sEluna->Push(L, creature->hasInvolvedQuest(quest_id));
        return 1;
    }

    int SetInCombatWithZone(lua_State* L, Creature* creature)
    {
        creature->SetInCombatWithZone();
        return 0;
    }

    int SetRespawnRadius(lua_State* L, Creature* creature)
    {
        float dist = luaL_checknumber(L, 1);

        creature->SetRespawnRadius(dist);
        return 0;
    }

    int GetRespawnRadius(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetRespawnRadius());
        return 1;
    }

    int Respawn(lua_State* L, Creature* creature)
    {
        creature->Respawn();
        return 0;
    }

    int SetRespawnDelay(lua_State* L, Creature* creature)
    {
        uint32 delay = luaL_checkunsigned(L, 1);

        creature->SetRespawnDelay(delay);
        return 0;
    }

    int GetRespawnDelay(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetRespawnDelay());
        return 1;
    }

    int DespawnOrUnsummon(lua_State* L, Creature* creature)
    {
        uint32 msTimeToDespawn = luaL_optunsigned(L, 1, 0);

        creature->DespawnOrUnsummon(msTimeToDespawn);
        return 0;
    }

    int RemoveCorpse(lua_State* L, Creature* creature)
    {
        creature->RemoveCorpse();
        return 0;
    }

    int SetDefaultMovementType(lua_State* L, Creature* creature)
    {
        int32 type = luaL_checkinteger(L, 1);

        creature->SetDefaultMovementType((MovementGeneratorType)type);
        return 0;
    }

    int GetDefaultMovementType(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetDefaultMovementType());
        return 1;
    }

    int IsTargetAcceptable(lua_State* L, Creature* creature)
    {
        Unit* target = sEluna->CHECK_UNIT(L, 1);

        if (!target)
            sEluna->Push(L, false);
        else
            sEluna->Push(L, creature->isTargetableForAttack(target));
        return 1;
    }

    int CanAssistTo(lua_State* L, Creature* creature)
    {
        Unit* u = sEluna->CHECK_UNIT(L, 1);
        Unit* enemy = sEluna->CHECK_UNIT(L, 2);
        bool checkfaction = luaL_optbool(L, 3, true);

        if (!u)
            sEluna->Push(L, false);
        if (!enemy)
            sEluna->Push(L, false);
        else
            sEluna->Push(L, creature->CanAssistTo(u, enemy, checkfaction));
        return 1;
    }

    int HasSearchedAssistance(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->HasSearchedAssistance());
        return 1;
    }

    int SetNoSearchAssistance(lua_State* L, Creature* creature)
    {
        bool val = luaL_optbool(L, 1, true);

        creature->SetNoSearchAssistance(val);
        return 0;
    }

    int SetNoCallAssistance(lua_State* L, Creature* creature)
    {
        bool val = luaL_optbool(L, 1, true);

        creature->SetNoCallAssistance(val);
        return 0;
    }

    int CallAssistance(lua_State* L, Creature* creature)
    {
        creature->CallAssistance();
        return 0;
    }

    int CallForHelp(lua_State* L, Creature* creature)
    {
        float radius = luaL_checknumber(L, 1);

        creature->CallForHelp(radius);
        return 0;
    }

    int FleeToGetAssistance(lua_State* L, Creature* creature)
    {
        creature->DoFleeToGetAssistance();
        return 0;
    }

    int GetAggroRange(lua_State* L, Creature* creature)
    {
        Unit* target = sEluna->CHECK_UNIT(L, 1);

        if (!target)
            return 0;
        sEluna->Push(L, creature->GetAttackDistance(target));
        return 1;
    }

    int GetAttackDistance(lua_State* L, Creature* creature)
    {
        Unit* target = sEluna->CHECK_UNIT(L, 1);

        if (!target)
            return 0;

        sEluna->Push(L, creature->GetAttackDistance(target));
        return 1;
    }

    int CanStartAttack(lua_State* L, Creature* creature) // TODO: Implement core side
    {
        Unit* target = sEluna->CHECK_UNIT(L, 1);
        bool force = luaL_optbool(L, 2, true);

        if (!target)
            return 0;

        sEluna->Push(L, creature->CanStartAttack(target, force));
        return 1;
    }

    int ResetLootMode(lua_State* L, Creature* creature) // TODO: Implement LootMode features
    {
        creature->ResetLootMode();
        return 0;
    }

    int RemoveLootMode(lua_State* L, Creature* creature) // TODO: Implement LootMode features
    {
        uint16 lootMode = luaL_checkunsigned(L, 1);

        creature->RemoveLootMode(lootMode);
        return 0;
    }

    int AddLootMode(lua_State* L, Creature* creature) // TODO: Implement LootMode features
    {
        uint16 lootMode = luaL_checkunsigned(L, 1);

        creature->AddLootMode(lootMode);
        return 0;
    }

    int SetLootMode(lua_State* L, Creature* creature) // TODO: Implement LootMode features
    {
        uint16 lootMode = luaL_checkunsigned(L, 1);

        creature->SetLootMode(lootMode);
        return 0;
    }

    int HasLootMode(lua_State* L, Creature* creature) // TODO: Implement LootMode features
    {
        uint16 lootMode = luaL_checkunsigned(L, 1);

        sEluna->Push(L, creature->HasLootMode(lootMode));
        return 1;
    }

    int GetLootMode(lua_State* L, Creature* creature) // TODO: Implement LootMode features
    {
        sEluna->Push(L, creature->GetLootMode());
        return 1;
    }

    int IsTappedBy(lua_State* L, Creature* creature)
    {
        Player* player = sEluna->CHECK_PLAYER(L, 1);

        if (!player)
            sEluna->Push(L, creature->isTappedBy(player));
        else
            sEluna->Push(L, false);
        return 1;
    }

    int HasLootRecipient(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->hasLootRecipient());
        return 1;
    }

    int GetLootRecipientGroup(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetLootRecipientGroup());
        return 1;
    }

    int GetLootRecipient(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetLootRecipient());
        return 1;
    }

    int SetDeathState(lua_State* L, Creature* creature)
    {
        int32 state = luaL_checkinteger(L, 1);

        creature->setDeathState((DeathState)state);
        return 0;
    }

    int SetWalk(lua_State* L, Creature* creature) // TODO: Move same to Player ?
    {
        bool enable = luaL_optbool(L, 1, true);

        creature->SetWalk(enable);
        return 0;
    }

    int SetReactState(lua_State* L, Creature* creature)
    {
        int32 state = luaL_checkinteger(L, 1);

        creature->SetReactState((ReactStates)state);
        return 0;
    }

    int GetReactState(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetReactState());
        return 1;
    }

    int HasReactState(lua_State* L, Creature* creature)
    {
        int32 state = luaL_checkinteger(L, 1);

        sEluna->Push(L, creature->HasReactState((ReactStates)state));
        return 1;
    }

    int CanSwim(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->CanSwim());
        return 1;
    }

    int CanWalk(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->CanWalk());
        return 1;
    }

    int SetDisableGravity(lua_State* L, Creature* creature)
    {
        bool disable = luaL_optbool(L, 1, true);
        bool packetOnly = luaL_optbool(L, 2, false);

        sEluna->Push(L, creature->SetDisableGravity(disable, packetOnly));
        return 1;
    }

    int SetHover(lua_State* L, Creature* creature)
    {
        bool enable = luaL_optbool(L, 1, true);

        sEluna->Push(L, creature->SetHover(enable));
        return 1;
    }

    int IsInEvadeMode(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->IsInEvadeMode());
        return 1;
    }

    int IsElite(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->isElite());
        return 1;
    }

    int IsGuard(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->IsGuard());
        return 1;
    }

    int IsTrigger(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->IsTrigger());
        return 1;
    }

    int IsCivilian(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->IsCivilian());
        return 1;
    }

    int IsRacialLeader(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->IsRacialLeader());
        return 1;
    }

    int HasCategoryCooldown(lua_State* L, Creature* creature)
    {
        uint32 spell = luaL_checkunsigned(L, 1);

        sEluna->Push(L, creature->HasCategoryCooldown(spell));
        return 1;
    }

    int GetScriptName(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetScriptName());
        return 1;
    }

    int GetAIName(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetAIName());
        return 1;
    }

    int GetScriptId(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetScriptId());
        return 1;
    }

    int GetCreatureSpellCooldownDelay(lua_State* L, Creature* creature)
    {
        uint32 spell = luaL_checkunsigned(L, 1);

        sEluna->Push(L, creature->GetCreatureSpellCooldownDelay(spell));
        return 1;
    }

    int GetCorpseDelay(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetCorpseDelay());
        return 1;
    }

    int GetHomePosition(lua_State* L, Creature* creature)
    {
        float x, y, z, o;
        creature->GetHomePosition(x, y, z, o);

        sEluna->Push(L, x);
        sEluna->Push(L, y);
        sEluna->Push(L, z);
        sEluna->Push(L, o);
        return 4;
    }

    int AttackStart(lua_State* L, Creature* creature)
    {
        Unit* target = sEluna->CHECK_UNIT(L, 1);
        if (!target)
            return 0;

        creature->AI()->AttackStart(target);
        return 0;
    }

    int GetNearestTargetInAttackDistance(lua_State* L, Creature* creature)
    {
        float dist = luaL_optnumber(L, 1, 0.0f);
        sEluna->Push(L, creature->SelectNearestTargetInAttackDistance(dist));
        return 1;
    }

    int GetNearestTarget(lua_State* L, Creature* creature)
    {
        float dist = luaL_optnumber(L, 1, 0.0f);
        sEluna->Push(L, creature->SelectNearestTarget(dist));
        return 1;
    }

    int GetNearestHostileTargetInAggroRange(lua_State* L, Creature* creature)
    {
        bool checkLOS = luaL_optbool(L, 1, false);
        sEluna->Push(L, creature->SelectNearestHostileUnitInAggroRange(checkLOS));
        return 1;
    }

    int Despawn(lua_State* L, Creature* creature)
    {
        uint32 time = luaL_optunsigned(L, 1, 0);
        creature->DespawnOrUnsummon(time);
        return 0;
    }

    int SendCreatureTalk(lua_State* L, Creature* creature)
    {
        uint8 id = luaL_checknumber(L, 1);
        WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 2);
        if (!obj)
            return 0;

        creature->AI()->Talk(id, obj);
        return 0;
    }

    int GetAITarget(lua_State* L, Creature* creature)
    {
        SelectAggroTarget targetType = (SelectAggroTarget)luaL_checkunsigned(L, 1);
        bool playerOnly = luaL_optbool(L, 2, false);
        uint32 position = luaL_optunsigned(L, 3, 0);
        float dist = luaL_optnumber(L, 4, 0.0f);
        int32 aura = luaL_optint(L, 5, 0);

        ;
        ThreatContainer::StorageType const& threatlist = creature->getThreatManager().getThreatList();
        if (position >= threatlist.size())
        {
            sEluna->Push(L);
            return 1;
        }

        std::list<Unit*> targetList;
        for (ThreatContainer::StorageType::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
        {
            Unit* target = (*itr)->getTarget();
            if (!target)
                continue;
            if (playerOnly && !target->ToPlayer())
                continue;
            if (aura > 0 && !target->HasAura(aura))
                continue;
            else if (aura < 0 && target->HasAura(-aura))
                continue;
            if (dist > 0.0f && !creature->IsWithinDist(target, dist))
                continue;
            targetList.push_back(target);
        }

        if (position >= targetList.size())
        {
            sEluna->Push(L);
            return 1;
        }

        if (targetType == SELECT_TARGET_NEAREST || targetType == SELECT_TARGET_FARTHEST)
            targetList.sort(Trinity::ObjectDistanceOrderPred(creature));

        switch (targetType)
        {
        case SELECT_TARGET_NEAREST:
        case SELECT_TARGET_TOPAGGRO:
            {
                std::list<Unit*>::const_iterator itr = targetList.begin();
                std::advance(itr, position);
                sEluna->Push(L, *itr);
                return 1;
            }
        case SELECT_TARGET_FARTHEST:
        case SELECT_TARGET_BOTTOMAGGRO:
            {
                std::list<Unit*>::reverse_iterator ritr = targetList.rbegin();
                std::advance(ritr, position);
                sEluna->Push(L, *ritr);
                return 1;
            }
        case SELECT_TARGET_RANDOM:
            {
                std::list<Unit*>::const_iterator itr = targetList.begin();
                std::advance(itr, urand(position, targetList.size() - 1));
                sEluna->Push(L, *itr);
                return 1;
            }
        default:
            break;
        }

        sEluna->Push(L);
        return 1;
    }

    int GetAITargets(lua_State* L, Creature* creature)
    {
        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        ThreatContainer::StorageType const &threatList = creature->getThreatManager().getThreatList();
        ThreatContainer::StorageType::const_iterator itr;
        for (itr = threatList.begin(); itr != threatList.end(); ++itr)
        {
            Unit* target = (*itr)->getTarget();
            if (!target)
                continue;
            ++i;
            sEluna->Push(L, i);
            sEluna->Push(L, target);
            lua_settable(L, tbl);
        }

        lua_settop(L, tbl);
        return 1;
    }

    int GetAITargetsCount(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->getThreatManager().getThreatList().size());
        return 1;
    }

    int IsDungeonBoss(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->IsDungeonBoss());
        return 1;
    }

    int IsWorldBoss(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->isWorldBoss());
        return 1;
    }

    int GetNPCFlags(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetUInt32Value(UNIT_NPC_FLAGS));
        return 1;
    }

    int SetNPCFlags(lua_State* L, Creature* creature)
    {
        uint32 flags = luaL_checkunsigned(L, 1);

        creature->SetUInt32Value(UNIT_NPC_FLAGS, flags);
        return 0;
    }

    int HasSpell(lua_State* L, Creature* creature)
    {
        uint32 id = luaL_checkunsigned(L, 1);

        sEluna->Push(L, creature->HasSpell(id));
        return 1;
    }

    int HasQuest(lua_State* L, Creature* creature)
    {
        uint32 questId = luaL_checkunsigned(L, 1);

        sEluna->Push(L, creature->hasQuest(questId));
        return 1;
    }

    int SaveToDB(lua_State* L, Creature* creature)
    {
        creature->SaveToDB();
        return 0;
    }

    int HasSpellCooldown(lua_State* L, Creature* creature)
    {
        uint32 spellId = luaL_checkunsigned(L, 1);

        sEluna->Push(L, creature->HasSpellCooldown(spellId));
        return 1;
    }

    int GetShieldBlockValue(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetShieldBlockValue());
        return 1;
    }

    int CanFly(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->CanFly());
        return 1;
    }

    int SelectVictim(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->SelectVictim());
        return 1;
    }
};
#endif