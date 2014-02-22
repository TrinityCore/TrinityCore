/*
* Copyright (C) 2010 - 2014 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.TXT for more information
*/

#ifndef CREATUREMETHODS_H
#define CREATUREMETHODS_H

namespace LuaCreature
{
    /*int IsDamageEnoughForLootingAndReward(lua_State* L, Creature* creature)
    {
    sEluna->Push(L, creature->IsDamageEnoughForLootingAndReward());
    return 1;
    }*/

    int IsReputationGainDisabled(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->IsReputationGainDisabled());
        return 1;
    }

    int SetDisableReputationGain(lua_State* L, Creature* creature)
    {
        bool disable = sEluna->CHECKVAL<bool>(L, 2, true);

        creature->SetDisableReputationGain(disable);
        return 0;
    }

    int IsRegeneratingHealth(lua_State* L, Creature* creature)
    {
#ifdef MANGOS
        sEluna->Push(L, creature->IsRegeneratingHealth());
#else
        sEluna->Push(L, creature->isRegeneratingHealth());
#endif
        return 1;
    }

    int HasInvolvedQuest(lua_State* L, Creature* creature)
    {
        uint32 quest_id = sEluna->CHECKVAL<uint32>(L, 2);

#ifdef MANGOS
        sEluna->Push(L, creature->HasInvolvedQuest(quest_id));
#else
        sEluna->Push(L, creature->hasInvolvedQuest(quest_id));
#endif
        return 1;
    }

    int SetInCombatWithZone(lua_State* L, Creature* creature)
    {
        creature->SetInCombatWithZone();
        return 0;
    }

    int SetRespawnRadius(lua_State* L, Creature* creature)
    {
        float dist = sEluna->CHECKVAL<float>(L, 2);

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
        uint32 delay = sEluna->CHECKVAL<uint32>(L, 2);

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
        uint32 msTimeToDespawn = sEluna->CHECKVAL<uint32>(L, 2, 0);

#ifdef MANGOS
        creature->ForcedDespawn(msTimeToDespawn);
#else
        creature->DespawnOrUnsummon(msTimeToDespawn);
#endif
        return 0;
    }

    int RemoveCorpse(lua_State* L, Creature* creature)
    {
        creature->RemoveCorpse();
        return 0;
    }

    int MoveWaypoint(lua_State* L, Creature* creature)
    {
        // LuaUnit::PrepareMove(creature);
#ifdef MANGOS
        creature->GetMotionMaster()->MoveWaypoint();
#else
        creature->GetMotionMaster()->MovePath(creature->GetWaypointPath(), true);
#endif
        return 0;
    }

    int SetDefaultMovementType(lua_State* L, Creature* creature)
    {
        int32 type = sEluna->CHECKVAL<int32>(L, 2);

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
        Unit* target = sEluna->CHECKOBJ<Unit>(L, 2);

        sEluna->Push(L, creature->isTargetableForAttack(target));
        return 1;
    }

    int CanAssistTo(lua_State* L, Creature* creature)
    {
        Unit* u = sEluna->CHECKOBJ<Unit>(L, 2);
        Unit* enemy = sEluna->CHECKOBJ<Unit>(L, 3);
        bool checkfaction = sEluna->CHECKVAL<bool>(L, 4, true);

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
        bool val = sEluna->CHECKVAL<bool>(L, 2, true);

        creature->SetNoSearchAssistance(val);
        return 0;
    }

    int SetNoCallAssistance(lua_State* L, Creature* creature)
    {
        bool val = sEluna->CHECKVAL<bool>(L, 2, true);

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
        float radius = sEluna->CHECKVAL<float>(L, 2);

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
        Unit* target = sEluna->CHECKOBJ<Unit>(L, 2);

        sEluna->Push(L, creature->GetAttackDistance(target));
        return 1;
    }

    int GetAttackDistance(lua_State* L, Creature* creature)
    {
        Unit* target = sEluna->CHECKOBJ<Unit>(L, 2);

        sEluna->Push(L, creature->GetAttackDistance(target));
        return 1;
    }

    /*int CanStartAttack(lua_State* L, Creature* creature) // TODO: Implement core side
    {
    Unit* target = sEluna->CHECKOBJ<Unit>(L, 2);
    bool force = sEluna->CHECKVAL<bool>(L, 3, true);

    sEluna->Push(L, creature->CanStartAttack(target, force));
    return 1;
    }*/

    /*int ResetLootMode(lua_State* L, Creature* creature) // TODO: Implement LootMode features
    {
    creature->ResetLootMode();
    return 0;
    }*/

    /*int RemoveLootMode(lua_State* L, Creature* creature) // TODO: Implement LootMode features
    {
    uint16 lootMode = sEluna->CHECKVAL<uint16>(L, 2);

    creature->RemoveLootMode(lootMode);
    return 0;
    }*/

    /*int AddLootMode(lua_State* L, Creature* creature) // TODO: Implement LootMode features
    {
    uint16 lootMode = sEluna->CHECKVAL<uint16>(L, 2);

    creature->AddLootMode(lootMode);
    return 0;
    }*/

    /*int SetLootMode(lua_State* L, Creature* creature) // TODO: Implement LootMode features
    {
    uint16 lootMode = sEluna->CHECKVAL<uint16>(L, 2);

    creature->SetLootMode(lootMode);
    return 0;
    }*/

    /*int HasLootMode(lua_State* L, Creature* creature) // TODO: Implement LootMode features
    {
    uint16 lootMode = sEluna->CHECKVAL<uint16>(L, 2);

    sEluna->Push(L, creature->HasLootMode(lootMode));
    return 1;
    }*/

    /*int GetLootMode(lua_State* L, Creature* creature) // TODO: Implement LootMode features
    {
    sEluna->Push(L, creature->GetLootMode());
    return 1;
    }*/

    int IsTappedBy(lua_State* L, Creature* creature)
    {
        Player* player = sEluna->CHECKOBJ<Player>(L, 2);

        sEluna->Push(L, creature->isTappedBy(player));
        return 1;
    }

    int HasLootRecipient(lua_State* L, Creature* creature)
    {
#ifdef MANGOS
        sEluna->Push(L, creature->HasLootRecipient());
#else
        sEluna->Push(L, creature->hasLootRecipient());
#endif
        return 1;
    }

    int GetLootRecipientGroup(lua_State* L, Creature* creature)
    {
#ifdef MANGOS
        sEluna->Push(L, creature->GetGroupLootRecipient());
#else
        sEluna->Push(L, creature->GetLootRecipientGroup());
#endif
        return 1;
    }

    int GetLootRecipient(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetLootRecipient());
        return 1;
    }

    int SetDeathState(lua_State* L, Creature* creature)
    {
        int32 state = sEluna->CHECKVAL<int32>(L, 2);

#ifdef MANGOS
        creature->SetDeathState((DeathState)state);
#else
        creature->setDeathState((DeathState)state);
#endif
        return 0;
    }

    int SetWalk(lua_State* L, Creature* creature)           // TODO: Move same to Player ?
    {
        bool enable = sEluna->CHECKVAL<bool>(L, 2, true);

        creature->SetWalk(enable);
        return 0;
    }

    int SetReactState(lua_State* L, Creature* creature)
    {
        int32 state = sEluna->CHECKVAL<int32>(L, 2);

#ifdef MANGOS
        creature->GetCharmInfo()->SetReactState((ReactStates)state);
#else
        creature->SetReactState((ReactStates)state);
#endif
        return 0;
    }

    int GetReactState(lua_State* L, Creature* creature)
    {
#ifdef MANGOS
        sEluna->Push(L, creature->GetCharmInfo()->GetReactState());
#else
        sEluna->Push(L, creature->GetReactState());
#endif
        return 1;
    }

    int HasReactState(lua_State* L, Creature* creature)
    {
        int32 state = sEluna->CHECKVAL<int32>(L, 2);

#ifdef MANGOS
        sEluna->Push(L, creature->GetCharmInfo()->HasReactState((ReactStates)state));
#else
        sEluna->Push(L, creature->HasReactState((ReactStates)state));
#endif
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

    /*int SetDisableGravity(lua_State* L, Creature* creature)
    {
    bool disable = sEluna->CHECKVAL<bool>(L, 2, true);
    bool packetOnly = sEluna->CHECKVAL<bool>(L, 3, false);

    sEluna->Push(L, creature->SetDisableGravity(disable, packetOnly));
    return 1;
    }*/

    int SetHover(lua_State* L, Creature* creature)
    {
        bool enable = sEluna->CHECKVAL<bool>(L, 2, true);

#ifdef MANGOS
        creature->SetLevitate(enable);
#else
        creature->SetHover(enable);
#endif
        return 0;
    }

    int IsInEvadeMode(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->IsInEvadeMode());
        return 1;
    }

    int IsElite(lua_State* L, Creature* creature)
    {
#ifdef MANGOS
        sEluna->Push(L, creature->IsElite());
#else
        sEluna->Push(L, creature->isElite());
#endif
        return 1;
    }

    int IsGuard(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->IsGuard());
        return 1;
    }

    /*int IsTrigger(lua_State* L, Creature* creature)
    {
    sEluna->Push(L, creature->IsTrigger());
    return 1;
    }*/

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
        uint32 spell = sEluna->CHECKVAL<uint32>(L, 2);

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
        uint32 spell = sEluna->CHECKVAL<uint32>(L, 2);

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
#ifdef MANGOS
        creature->GetRespawnCoord(x, y, z, &o);
#else
        creature->GetHomePosition(x, y, z, o);
#endif

        sEluna->Push(L, x);
        sEluna->Push(L, y);
        sEluna->Push(L, z);
        sEluna->Push(L, o);
        return 4;
    }

    int AttackStart(lua_State* L, Creature* creature)
    {
        Unit* target = sEluna->CHECKOBJ<Unit>(L, 2);

        creature->AI()->AttackStart(target);
        return 0;
    }

    int GetAITarget(lua_State* L, Creature* creature)
    {
        uint32 targetType = sEluna->CHECKVAL<uint32>(L, 2);
        bool playerOnly = sEluna->CHECKVAL<bool>(L, 3, false);
        uint32 position = sEluna->CHECKVAL<uint32>(L, 4, 0);
        float dist = sEluna->CHECKVAL<float>(L, 5, 0.0f);
        int32 aura = sEluna->CHECKVAL<int32>(L, 6, 0);

        ThreatList const&  threatlist = creature->getThreatManager().getThreatList();
        if (position >= threatlist.size())
        {
            sEluna->Push(L);
            return 1;
        }

        std::list<Unit*> targetList;
        for (ThreatList::const_iterator itr = threatlist.begin(); itr != threatlist.end(); ++itr)
        {
            Unit* target = (*itr)->getTarget();
            if (!target)
                continue;
            if (playerOnly && target->GetTypeId() != TYPEID_PLAYER)
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
            targetList.sort(Eluna::ObjectDistanceOrderPred(creature));

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
            luaL_argerror(L, 2, "SelectAggroTarget expected");
        }

        sEluna->Push(L);
        return 1;
    }

    int GetAITargets(lua_State* L, Creature* creature)
    {
        lua_newtable(L);
        int tbl = lua_gettop(L);
        uint32 i = 0;

        ThreatList const& threatList = creature->getThreatManager().getThreatList();
        ThreatList::const_iterator itr;
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

    int IsWorldBoss(lua_State* L, Creature* creature)
    {
#ifdef MANGOS
        sEluna->Push(L, creature->IsWorldBoss());
#else
        sEluna->Push(L, creature->isWorldBoss());
#endif
        return 1;
    }

    int GetNPCFlags(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetUInt32Value(UNIT_NPC_FLAGS));
        return 1;
    }

    int SetNPCFlags(lua_State* L, Creature* creature)
    {
        uint32 flags = sEluna->CHECKVAL<uint32>(L, 2);

        creature->SetUInt32Value(UNIT_NPC_FLAGS, flags);
        return 0;
    }

    int HasSpell(lua_State* L, Creature* creature)
    {
        uint32 id = sEluna->CHECKVAL<uint32>(L, 2);

        sEluna->Push(L, creature->HasSpell(id));
        return 1;
    }

    int HasQuest(lua_State* L, Creature* creature)
    {
        uint32 questId = sEluna->CHECKVAL<uint32>(L, 2);

#ifdef MANGOS
        sEluna->Push(L, creature->HasQuest(questId));
#else
        sEluna->Push(L, creature->hasQuest(questId));
#endif
        return 1;
    }

    int SaveToDB(lua_State* L, Creature* creature)
    {
        creature->SaveToDB();
        return 0;
    }

    int HasSpellCooldown(lua_State* L, Creature* creature)
    {
        uint32 spellId = sEluna->CHECKVAL<uint32>(L, 2);

        sEluna->Push(L, creature->HasSpellCooldown(spellId));
        return 1;
    }

#ifndef CATA
    int GetShieldBlockValue(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->GetShieldBlockValue());
        return 1;
    }
#endif

    int CanFly(lua_State* L, Creature* creature)
    {
        sEluna->Push(L, creature->CanFly());
        return 1;
    }

    int SelectVictim(lua_State* L, Creature* creature)
    {
#ifdef MANGOS
        sEluna->Push(L, creature->SelectHostileTarget());
#else
        sEluna->Push(L, creature->SelectVictim());
#endif
        return 1;
    }
};
#endif
