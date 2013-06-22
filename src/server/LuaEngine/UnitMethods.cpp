#include "LuaEngine.h"
#include "UnitMethods.h"

#define TO_PLAYER() Player* player; if (!unit || !unit->IsInWorld() || !(player = unit->ToPlayer())) { return 0; } else (void)0;
#define TO_CREATURE() Creature* creature; if (!unit || !unit->IsInWorld() || !(creature = unit->ToCreature())) { return 0; } else (void)0;
#define TO_UNIT() if (!unit || !unit->IsInWorld() || !unit->ToUnit()) { return 0; } else (void)0;

#define TO_PLAYER_BOOL() Player* player; if (!unit || !unit->IsInWorld() || !(player = unit->ToPlayer())) { sEluna->PushBoolean(L, false); return 1; } else (void)0;
#define TO_CREATURE_BOOL() Creature* creature; if (!unit || !unit->IsInWorld() || !(creature = unit->ToCreature())) { sEluna->PushBoolean(L, false); return 1; } else (void)0;
#define TO_UNIT_BOOL() if (!unit || !unit->IsInWorld() || !unit->ToUnit()) { sEluna->PushBoolean(L, false); return 1; } else (void)0;


int LuaUnit::Attack(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    Unit* who = sEluna->CHECK_UNIT(L, 1);
    bool meleeAttack = luaL_optbool(L, 2, false);

    if (!who)
        sEluna->PushBoolean(L, false);
    else
        sEluna->PushBoolean(L, unit->Attack(who, meleeAttack));
    return 1;
}

int LuaUnit::SetFlag(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    uint32 flag = luaL_checkunsigned(L, 2);

    unit->SetFlag(index, flag);
    return 0;
}

int LuaUnit::RemoveFlag(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    uint32 flag = luaL_checkunsigned(L, 2);

    unit->RemoveFlag(index, flag);
    return 0;
}

int LuaUnit::HasFlag(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    uint32 flag = luaL_checkunsigned(L, 2);

    unit->HasFlag(index, flag);
    return 0;
}

int LuaUnit::ClearThreatList(lua_State* L, Unit* unit)
{
    TO_UNIT();

    unit->getThreatManager().clearReferences();
    return 0;
}

int LuaUnit::SetOwnerGUID(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint64 guid = sEluna->CHECK_ULONG(L, 1);

    unit->SetOwnerGUID(guid);
    return 0;
}

int LuaUnit::GetOwner(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnit(L, unit->GetOwner());
    return 1;
}

int LuaUnit::GetOwnerGUID(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushULong(L, unit->GetOwnerGUID());
    return 1;
}

int LuaUnit::SummonPlayer(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    Player* target = sEluna->CHECK_PLAYER(L, 1);
    uint32 map = luaL_checkunsigned(L, 2);
    float x = luaL_checknumber(L, 3);
    float y = luaL_checknumber(L, 4);
    float z = luaL_checknumber(L, 5);
    float zoneId = luaL_checkunsigned(L, 6);
    uint32 delay = luaL_optunsigned(L, 7, 0);
    if (!target || !MapManager::IsValidMapCoord(map, x, y, z))
        return 0;

    target->SetSummonPoint(map, x, y, z);
    WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
    data << uint64(player->GetGUID());
    data << uint32(zoneId);
    data << uint32(delay ? delay*IN_MILLISECONDS : MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS);
    target->GetSession()->SendPacket(&data);
    return 0;
}

int LuaUnit::Mute(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 muteseconds = luaL_checkunsigned(L, 1);
    const char* reason = luaL_checkstring(L, 2);

    PreparedStatement* stmt = LoginDatabase.GetPreparedStatement(LOGIN_UPD_MUTE_TIME);
    int64 muteTime = time(NULL) + muteseconds;
    player->GetSession()->m_muteTime = muteTime;
    stmt->setInt64(0, muteTime);
    stmt->setString(1, reason ? reason : "");
    stmt->setString(2, "Eluna");
    stmt->setUInt32(3, player->GetSession()->GetAccountId());
    LoginDatabase.Execute(stmt);
    return 0;
}

int LuaUnit::GetHeight(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);

    float z = unit->GetMap()->GetHeight(unit->GetPhaseMask(), x, y, MAX_HEIGHT);
    if (z == INVALID_HEIGHT)
        z = unit->GetPositionZ();
    sEluna->PushFloat(L, z);
    return 1;
}

int LuaUnit::GetRelativePoint(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float dist = luaL_checknumber(L, 1);
    float rad = luaL_checknumber(L, 2);

    float o = Position::NormalizeOrientation(unit->GetOrientation() + rad);
    sEluna->PushFloat(L, unit->GetPositionX()+(dist*cosf(o)));
    sEluna->PushFloat(L, unit->GetPositionY()+(dist*sinf(o)));
    sEluna->PushFloat(L, o);
    return 3;
}

int LuaUnit::Mount(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 displayId = luaL_checkunsigned(L, 1);

    unit->Mount(displayId);
    return 0;
}

int LuaUnit::Dismount(lua_State* L, Unit* unit)
{
    TO_UNIT();

    if (unit->IsMounted())
    {
        unit->Dismount();
        unit->RemoveAurasByType(SPELL_AURA_MOUNTED);
    }

    return 0;
}

int LuaUnit::IsMounted(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsMounted());
    return 1;
}

int LuaUnit::IsWithinLoS(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);
    float z = luaL_checknumber(L, 3);

    sEluna->PushBoolean(L, unit->IsWithinLOS(x, y, z));
    return 1;
}

int LuaUnit::GetScale(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushFloat(L, unit->GetFloatValue(OBJECT_FIELD_SCALE_X));
    return 1;
}

int LuaUnit::SetScale(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float size = luaL_checknumber(L, 1);

    unit->SetObjectScale(size);
    return 0;
}

int LuaUnit::IsDamageEnoughForLootingAndReward(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->IsDamageEnoughForLootingAndReward());
    return 1;
}

int LuaUnit::IsReputationGainDisabled(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->IsReputationGainDisabled());
    return 1;
}

int LuaUnit::SetDisableReputationGain(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    bool disable = luaL_optbool(L, 1, true);

    creature->SetDisableReputationGain(disable);
    return 0;
}

int LuaUnit::SelectVictim(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushUnit(L, creature->SelectVictim());
    return 1;
}

int LuaUnit::GetCurrentWaypointId(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushUnsigned(L, creature->GetCurrentWaypointID());
    return 1;
}

int LuaUnit::GetWaypointPath(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushUnsigned(L, creature->GetWaypointPath());
    return 1;
}

int LuaUnit::GetTransportHomePosition(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    float x,y,z,o;
    creature->GetTransportHomePosition(x,y,z,o);

    sEluna->PushFloat(L, x);
    sEluna->PushFloat(L, y);
    sEluna->PushFloat(L, z);
    sEluna->PushFloat(L, o);
    return 4;
}

int LuaUnit::IsRegeneratingHealth(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->isRegeneratingHealth());
    return 1;
}

int LuaUnit::HasInvolvedQuest(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    uint32 quest_id = luaL_checkunsigned(L, 1);

    sEluna->PushBoolean(L, creature->hasInvolvedQuest(quest_id));
    return 1;
}

int LuaUnit::SetInCombatWithZone(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    creature->SetInCombatWithZone();
    return 0;
}

int LuaUnit::SetRespawnRadius(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    float dist = luaL_checknumber(L, 1);

    creature->SetRespawnRadius(dist);
    return 0;
}

int LuaUnit::GetRespawnRadius(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushFloat(L, creature->GetRespawnRadius());
    return 1;
}

int LuaUnit::Respawn(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    bool force = luaL_optbool(L, 1, false);

    creature->Respawn(force);
    return 0;
}

int LuaUnit::SetRespawnDelay(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    uint32 delay = luaL_checkunsigned(L, 1);

    creature->SetRespawnDelay(delay);
    return 0;
}

int LuaUnit::GetRespawnDelay(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushUnsigned(L, creature->GetRespawnDelay());
    return 1;
}

int LuaUnit::DespawnOrUnsummon(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    uint32 msTimeToDespawn = luaL_optunsigned(L, 1, 0);

    creature->DespawnOrUnsummon(msTimeToDespawn);
    return 0;
}

int LuaUnit::RemoveCorpse(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    bool setSpawnTime = luaL_optbool(L, 1, true);

    creature->RemoveCorpse(setSpawnTime);
    return 0;
}

int LuaUnit::SetDefaultMovementType(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    int32 type = luaL_checkinteger(L, 1);

    creature->SetDefaultMovementType((MovementGeneratorType)type);
    return 0;
}

int LuaUnit::GetDefaultMovementType(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushInteger(L, creature->GetDefaultMovementType());
    return 1;
}

int LuaUnit::IsTargetAcceptable(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    Unit* target = sEluna->CHECK_UNIT(L, 1);

    if (!target)
        sEluna->PushBoolean(L, false);
    else
        sEluna->PushBoolean(L, creature->_IsTargetAcceptable(unit));
    return 1;
}

int LuaUnit::CanAssistTo(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    Unit* u = sEluna->CHECK_UNIT(L, 1);
    Unit* enemy = sEluna->CHECK_UNIT(L, 2);
    bool checkfaction = luaL_optbool(L, 3, true);

    if (!u)
        sEluna->PushBoolean(L, false);
    if (!enemy)
        sEluna->PushBoolean(L, false);
    else
        sEluna->PushBoolean(L, creature->CanAssistTo(u, enemy, checkfaction));
    return 1;
}

int LuaUnit::HasSearchedAssistance(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->HasSearchedAssistance());
    return 1;
}

int LuaUnit::SetNoSearchAssistance(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    bool val = luaL_optbool(L, 1, true);

    creature->SetNoSearchAssistance(val);
    return 0;
}

int LuaUnit::SetNoCallAssistance(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    bool val = luaL_optbool(L, 1, true);

    creature->SetNoCallAssistance(val);
    return 0;
}

int LuaUnit::CallAssistance(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    creature->CallAssistance();
    return 0;
}

int LuaUnit::CallForHelp(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    float radius = luaL_checknumber(L, 1);

    creature->CallForHelp(radius);
    return 0;
}

int LuaUnit::FleeToGetAssistance(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    creature->DoFleeToGetAssistance();
    return 0;
}

int LuaUnit::GetAggroRange(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    Unit* target = sEluna->CHECK_UNIT(L, 1);

    if (!target)
        return 0;

    sEluna->PushFloat(L, creature->GetAggroRange(target));
    return 1;
}

int LuaUnit::GetAttackDistance(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    Unit* target = sEluna->CHECK_UNIT(L, 1);

    if (!target)
        return 0;

    sEluna->PushFloat(L, creature->GetAttackDistance(target));
    return 1;
}

int LuaUnit::CanStartAttack(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    Unit* target = sEluna->CHECK_UNIT(L, 1);
    bool force = luaL_optbool(L, 2, true);

    if (!target)
        return 0;

    sEluna->PushBoolean(L, creature->CanStartAttack(target, force));
    return 1;
}

int LuaUnit::ResetLootMode(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    creature->ResetLootMode();
    return 0;
}

int LuaUnit::RemoveLootMode(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    uint16 lootMode = luaL_checkunsigned(L, 1);

    creature->RemoveLootMode(lootMode);
    return 0;
}

int LuaUnit::AddLootMode(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    uint16 lootMode = luaL_checkunsigned(L, 1);

    creature->AddLootMode(lootMode);
    return 0;
}

int LuaUnit::SetLootMode(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    uint16 lootMode = luaL_checkunsigned(L, 1);

    creature->SetLootMode(lootMode);
    return 0;
}

int LuaUnit::HasLootMode(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    uint16 lootMode = luaL_checkunsigned(L, 1);

    sEluna->PushBoolean(L, creature->HasLootMode(lootMode));
    return 1;
}

int LuaUnit::GetLootMode(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushUnsigned(L, creature->GetLootMode());
    return 1;
}

int LuaUnit::IsTappedBy(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    Player* player = sEluna->CHECK_PLAYER(L, 1);

    if (player)
        sEluna->PushBoolean(L, creature->isTappedBy(player));
    else
        sEluna->PushBoolean(L, false);
    return 1;
}

int LuaUnit::HasLootRecipient(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->hasLootRecipient());
    return 1;
}

int LuaUnit::GetLootRecipientGroup(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushGroup(L, creature->GetLootRecipientGroup());
    return 1;
}

int LuaUnit::GetLootRecipient(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushUnit(L, creature->GetLootRecipient());
    return 1;
}

int LuaUnit::SetDeathState(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    int32 state = luaL_checkinteger(L, 1);

    creature->setDeathState((DeathState)state);
    return 0;
}

int LuaUnit::SetReactState(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    int32 state = luaL_checkinteger(L, 1);

    creature->SetReactState((ReactStates)state);
    return 0;
}

int LuaUnit::GetReactState(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushInteger(L, creature->GetReactState());
    return 1;
}

int LuaUnit::HasReactState(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    int32 state = luaL_checkinteger(L, 1);

    sEluna->PushBoolean(L, creature->HasReactState((ReactStates)state));
    return 1;
}

int LuaUnit::CanFly(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    if (Player* player = unit->ToPlayer())
        sEluna->PushBoolean(L, player->CanFly());
    else if (Creature* creature = unit->ToCreature())
        sEluna->PushBoolean(L, creature->CanFly());
    else
        sEluna->PushBoolean(L, unit->CanFly());
    return 1;
}

int LuaUnit::CanSwim(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->CanSwim());
    return 1;
}

int LuaUnit::CanWalk(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->CanWalk());
    return 1;
}

int LuaUnit::SetDisableGravity(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    bool disable = luaL_optbool(L, 1, true);
    bool packetOnly = luaL_optbool(L, 2, false);

    sEluna->PushBoolean(L, creature->SetDisableGravity(disable, packetOnly));
    return 1;
}

int LuaUnit::SetHover(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    bool enable = luaL_optbool(L, 1, true);

    sEluna->PushBoolean(L, creature->SetHover(enable));
    return 1;
}

int LuaUnit::IsInEvadeMode(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->IsInEvadeMode());
    return 1;
}

int LuaUnit::IsElite(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->isElite());
    return 1;
}

int LuaUnit::IsGuard(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->IsGuard());
    return 1;
}

int LuaUnit::IsTrigger(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->IsTrigger());
    return 1;
}

int LuaUnit::IsCivilian(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->IsCivilian());
    return 1;
}

int LuaUnit::IsRacialLeader(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->IsRacialLeader());
    return 1;
}

int LuaUnit::HasCategoryCooldown(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    uint32 spell = luaL_checkunsigned(L, 1);

    sEluna->PushBoolean(L, creature->HasCategoryCooldown(spell));
    return 1;
}

int LuaUnit::GetScriptName(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushString(L, creature->GetScriptName().c_str());
    return 1;
}

int LuaUnit::GetAIName(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushString(L, creature->GetAIName().c_str());
    return 1;
}

int LuaUnit::GetScriptId(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushUnsigned(L, creature->GetScriptId());
    return 1;
}

int LuaUnit::GetCreatureSpellCooldownDelay(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    uint32 spell = luaL_checkunsigned(L, 1);

    sEluna->PushUnsigned(L, creature->GetCreatureSpellCooldownDelay(spell));
    return 1;
}

int LuaUnit::GetShieldBlockValue(lua_State* L, Unit* unit)
{
    TO_UNIT();

    if (Player* player = unit->ToPlayer())
        sEluna->PushUnsigned(L, player->GetShieldBlockValue());
    if (Creature* creature = unit->ToCreature())
        sEluna->PushUnsigned(L, creature->GetShieldBlockValue());
    else
        sEluna->PushUnsigned(L, unit->GetShieldBlockValue());
    return 1;
}

int LuaUnit::GetMountId(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetMountID());
    return 1;
}

int LuaUnit::GetCorpseDelay(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushUnsigned(L, creature->GetCorpseDelay());
    return 1;
}

int LuaUnit::GetHomePosition(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    float x,y,z,o;
    creature->GetHomePosition(x,y,z,o);

    sEluna->PushFloat(L, x);
    sEluna->PushFloat(L, y);
    sEluna->PushFloat(L, z);
    sEluna->PushFloat(L, o);
    return 4;
}

int LuaUnit::RewardQuest(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 entry = luaL_checkunsigned(L, 1);

    Quest const* quest = sObjectMgr->GetQuestTemplate(entry);
    if (quest)
        player->RewardQuest(quest, 0, player);
    return 0;
}

int LuaUnit::HasAura(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 spell = luaL_checkunsigned(L, 1);
    WorldObject* caster = sEluna->CHECK_WORLDOBJECT(L, 2);

    sEluna->PushBoolean(L, player->HasAura(spell, caster ? caster->GetGUID() : 0));
    return 1;
}

int LuaUnit::IsARecruiter(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->GetSession()->IsARecruiter() || (player->GetSession()->GetRecruiterId() != 0));
    return 1;
}

int LuaUnit::GetRecruiterId(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetSession()->GetRecruiterId());
    return 1;
}

int LuaUnit::GetSelectedPlayer(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnit(L, player->GetSelectedPlayer());
    return 1;
}

int LuaUnit::GetSelectedUnit(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnit(L, player->GetSelectedUnit());
    return 1;
}

int LuaUnit::GetDistance(lua_State* L, Unit* unit)
{
    TO_UNIT();

    WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 1);
    if (obj && obj->IsInWorld())
        sEluna->PushFloat(L, unit->GetDistance(obj));
    else
    {
        float X = luaL_checknumber(L, 1);
        float Y = luaL_checknumber(L, 2);
        float Z = luaL_checknumber(L, 3);
        sEluna->PushFloat(L, unit->GetDistance(X, Y, Z));
    }
    return 1;
}

int LuaUnit::GetLatency(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetSession()->GetLatency());
    return 1;
}

int LuaUnit::SendAuctionMenu(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    Creature* creature = sEluna->CHECK_CREATURE(L, 1);
    uint32 faction = luaL_checkunsigned(L, 2);

    if (player->getLevel() < sWorld->getIntConfig(CONFIG_AUCTION_LEVEL_REQ))
    {
        player->GetSession()->SendNotification(player->GetSession()->GetTrinityString(LANG_AUCTION_REQ), sWorld->getIntConfig(CONFIG_AUCTION_LEVEL_REQ));
        return 0;
    }

    uint64 guid = creature ? creature->GetGUID() : player->GetGUID();
    if (!faction)
        faction = creature ? creature->getFaction() : player->getFaction();

    AuctionHouseEntry const* ahEntry = AuctionHouseMgr::GetAuctionHouseEntry(faction);
    if (!ahEntry)
        return 0;

    WorldPacket data(MSG_AUCTION_HELLO, 12);
    data << uint64(guid);
    data << uint32(ahEntry->houseId);
    data << uint8(1);
    player->GetSession()->SendPacket(&data);
    return 0;
}

int LuaUnit::SendMailMenu(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    GameObject* object = sEluna->CHECK_GAMEOBJECT(L, 1);
    if (!object)
        return 0;

    WorldPacket data(SMSG_SHOW_MAILBOX, 8);
    data << uint64(object->GetGUID());
    player->GetSession()->HandleGetMailList(data);
    return 0;
}

int LuaUnit::SendTaxiMenu(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    Creature* creature = sEluna->CHECK_CREATURE(L, 1);

    if (creature)
        player->GetSession()->SendTaxiMenu(creature);
    return 0;
}

int LuaUnit::SendSpiritResurrect(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->GetSession()->SendSpiritResurrect();
    return 0;
}

int LuaUnit::SendTabardVendorActivate(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 1);

    if (obj)
        player->GetSession()->SendTabardVendorActivate(obj->GetGUID());
    return 0;
}

int LuaUnit::SendShowBank(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 1);

    if (obj)
        player->GetSession()->SendShowBank(obj->GetGUID());
    return 0;
}

int LuaUnit::SendListInventory(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 1);

    if (obj)
        player->GetSession()->SendListInventory(obj->GetGUID());
    return 0;
}

int LuaUnit::SendTrainerList(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 1);

    if (obj)
        player->GetSession()->SendTrainerList(obj->GetGUID());
    return 0;
}

int LuaUnit::LogoutPlayer(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    bool save = luaL_optbool(L, 1, true);

    player->GetSession()->LogoutPlayer(save);
    return 0;
}

int LuaUnit::GetChampioningFaction(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetChampioningFaction());
    return 1;
}

int LuaUnit::ResetAchievements(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->ResetAchievements();
    return 0;
}

int LuaUnit::HasAchieved(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 achievementId = luaL_checkunsigned(L, 1);

    sEluna->PushBoolean(L, player->HasAchieved(achievementId));
    return 1;
}

int LuaUnit::GetOriginalSubGroup(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetOriginalSubGroup());
    return 1;
}

int LuaUnit::GetOriginalGroup(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushGroup(L, player->GetOriginalGroup());
    return 1;
}

int LuaUnit::RemoveFromBattlegroundOrBattlefieldRaid(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->RemoveFromBattlegroundOrBattlefieldRaid();
    return 0;
}

int LuaUnit::CanUninviteFromGroup(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->CanUninviteFromGroup() == ERR_PARTY_RESULT_OK);
    return 1;
}

int LuaUnit::GetNextRandomRaidMember(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    float radius = luaL_checknumber(L, 1);

    sEluna->PushUnit(L, player->GetNextRandomRaidMember(radius));
    return 1;
}

int LuaUnit::GetSubGroup(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetSubGroup());
    return 1;
}

int LuaUnit::GetGroupInvite(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushGroup(L, player->GetGroupInvite());
    return 1;
}

int LuaUnit::HasPendingBind(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->HasPendingBind());
    return 1;
}

int LuaUnit::UnbindInstance(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 map = luaL_checkunsigned(L, 1);
    uint32 difficulty = luaL_checkunsigned(L, 2);

    if (difficulty < MAX_DIFFICULTY)
        player->UnbindInstance(map, (Difficulty)difficulty);
    return 0;
}

int LuaUnit::BindToInstance(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->BindToInstance();
    return 0;
}

int LuaUnit::SetAtLoginFlag(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 flag = luaL_checkunsigned(L, 1);

    player->SetAtLoginFlag((AtLoginFlags)flag);
    return 0;
}

int LuaUnit::InRandomLfgDungeon(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->inRandomLfgDungeon());
    return 1;
}

int LuaUnit::IsUsingLfg(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->isUsingLfg());
    return 1;
}

int LuaUnit::HasAtLoginFlag(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 flag = luaL_checkunsigned(L, 1);

    sEluna->PushBoolean(L, player->HasAtLoginFlag((AtLoginFlags)flag));
    return 1;
}

int LuaUnit::IsVisibleForPlayer(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    Player* target = sEluna->CHECK_PLAYER(L, 1);

    if (target)
        sEluna->PushBoolean(L, player->IsVisibleGloballyFor(target));
    else
        sEluna->PushBoolean(L, false);
    return 1;
}

int LuaUnit::IsNeverVisible(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->IsNeverVisible());
    return 1;
}

int LuaUnit::CanFlyInZone(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 mapid = luaL_checkunsigned(L, 1);
    uint32 zone = luaL_checkunsigned(L, 1);

    sEluna->PushBoolean(L, player->IsKnowHowFlyIn(mapid, zone));
    return 1;
}

int LuaUnit::SetRestTime(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 value = luaL_checkunsigned(L, 1);

    player->SetRestTime(value);
    return 0;
}

int LuaUnit::GetRestTime(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetRestTime());
    return 1;
}

int LuaUnit::GetXPRestBonus(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 xp = luaL_checkunsigned(L, 1);

    sEluna->PushUnsigned(L, player->GetXPRestBonus(xp));
    return 1;
}

int LuaUnit::CanSpeak(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->CanSpeak());
    return 1;
}

int LuaUnit::IsImmuneToEnvironmentalDamage(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->IsImmuneToEnvironmentalDamage());
    return 1;
}

int LuaUnit::IsRested(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->isRested());
    return 1;
}

int LuaUnit::LeaveBattleground(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    bool teleToEntryPoint = luaL_optbool(L, 1, true);

    player->LeaveBattleground(teleToEntryPoint);
    return 0;
}

int LuaUnit::InBattlegroundQueue(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->InBattlegroundQueue());
    return 1;
}

int LuaUnit::GetBattlegroundTypeId(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetBattlegroundTypeId());
    return 1;
}

int LuaUnit::GetBattlegroundId(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetBattlegroundId());
    return 1;
}

int LuaUnit::IsOutdoorPvPActive(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->IsOutdoorPvPActive());
    return 1;
}

int LuaUnit::InArena(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->InArena());
    return 1;
}

int LuaUnit::InBattleground(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->InBattleground());
    return 1;
}

int LuaUnit::CanTameExoticPets(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->CanTameExoticPets());
    return 1;
}

int LuaUnit::CanTitanGrip(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->CanTitanGrip());
    return 1;
}

int LuaUnit::CanBlock(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->CanBlock());
    return 1;
}

int LuaUnit::CanParry(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->CanParry());
    return 1;
}

int LuaUnit::GetDrunkValue(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetDrunkValue());
    return 1;
}

int LuaUnit::SetDrunkValue(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint8 newDrunkValue = luaL_checkunsigned(L, 1);

    player->SetDrunkValue(newDrunkValue);
    return 0;
}

int LuaUnit::GetSpellCooldowns(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    lua_newtable(L);
    int tbl = lua_gettop(L);
    uint32 i = 0;

    for (SpellCooldowns::iterator it = player->GetSpellCooldowns().begin(); it != player->GetSpellCooldowns().end(); ++it)
    {
        ++i;
        sEluna->PushUnsigned(L, it->first);
        sEluna->PushUnsigned(L, it->second.end);
        lua_settable(L, tbl);
    }

    lua_settop(L, tbl);
    return 1;
}

int LuaUnit::ModifyArenaPoints(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    int32 amount = luaL_checkunsigned(L, 1);

    player->ModifyArenaPoints(amount);
    return 0;
}

int LuaUnit::ModifyHonorPoints(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    int32 amount = luaL_checkunsigned(L, 1);

    player->ModifyHonorPoints(amount);
    return 0;
}

int LuaUnit::GetReputationRank(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 faction = luaL_checkunsigned(L, 1);

    sEluna->PushInteger(L, player->GetReputationRank(faction));
    return 1;
}

int LuaUnit::IsHonorOrXPTarget(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    Unit* victim = sEluna->CHECK_UNIT(L, 1);

    if (victim)
        sEluna->PushBoolean(L, player->isHonorOrXPTarget(victim));
    else
        sEluna->PushBoolean(L, false);
    return 1;
}

int LuaUnit::SetFactionForRace(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint8 race = luaL_checkunsigned(L, 1);

    player->setFactionForRace(race);
    return 0;
}

int LuaUnit::SetSkill(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint16 id = luaL_checkunsigned(L, 1);
    uint16 step = luaL_checkunsigned(L, 2);
    uint16 currVal = luaL_checkunsigned(L, 3);
    uint16 maxVal = luaL_checkunsigned(L, 4);

    player->SetSkill(id, step, currVal, maxVal);
    return 0;
}

int LuaUnit::HasSkill(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 skill = luaL_checkunsigned(L, 1);

    sEluna->PushBoolean(L, player->HasSkill(skill));
    return 1;
}

int LuaUnit::GetSkillTempBonusValue(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 skill = luaL_checkunsigned(L, 1);

    sEluna->PushInteger(L, player->GetSkillTempBonusValue(skill));
    return 1;
}

int LuaUnit::GetSkillPermBonusValue(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 skill = luaL_checkunsigned(L, 1);

    sEluna->PushInteger(L, player->GetSkillPermBonusValue(skill));
    return 1;
}

int LuaUnit::GetSkillStep(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 skill = luaL_checkunsigned(L, 1);

    sEluna->PushUnsigned(L, player->GetSkillStep(skill));
    return 1;
}

int LuaUnit::GetPureSkillValue(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 skill = luaL_checkunsigned(L, 1);

    sEluna->PushUnsigned(L, player->GetPureSkillValue(skill));
    return 1;
}

int LuaUnit::GetBaseSkillValue(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 skill = luaL_checkunsigned(L, 1);

    sEluna->PushUnsigned(L, player->GetBaseSkillValue(skill));
    return 1;
}

int LuaUnit::GetSkillValue(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 skill = luaL_checkunsigned(L, 1);

    sEluna->PushUnsigned(L, player->GetSkillValue(skill));
    return 1;
}

int LuaUnit::GetPureMaxSkillValue(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 skill = luaL_checkunsigned(L, 1);

    sEluna->PushUnsigned(L, player->GetPureMaxSkillValue(skill));
    return 1;
}

int LuaUnit::GetMaxSkillValue(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 skill = luaL_checkunsigned(L, 1);

    sEluna->PushUnsigned(L, player->GetMaxSkillValue(skill));
    return 1;
}

int LuaUnit::SetMovement(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    int32 pType = luaL_checkinteger(L, 1);

    player->SetMovement((PlayerMovementType)pType);
    return 0;
}

int LuaUnit::DurabilityRepair(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint16 position = luaL_checkunsigned(L, 1);
    bool cost = luaL_optbool(L, 2, true);
    float discountMod = luaL_checkinteger(L, 3);
    bool guildBank = luaL_optbool(L, 4, false);

    sEluna->PushUnsigned(L, player->DurabilityRepair(position, cost, discountMod, guildBank));
    return 1;
}

int LuaUnit::DurabilityRepairAll(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    bool cost = luaL_optbool(L, 1, true);
    float discountMod = luaL_checkinteger(L, 2);
    bool guildBank = luaL_optbool(L, 3, false);

    sEluna->PushUnsigned(L, player->DurabilityRepairAll(cost, discountMod, guildBank));
    return 1;
}

int LuaUnit::DurabilityPointLossForEquipSlot(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    int32 slot = luaL_checkinteger(L, 1);

    if (slot >= EQUIPMENT_SLOT_START && slot < EQUIPMENT_SLOT_END)
        player->DurabilityPointLossForEquipSlot((EquipmentSlots)slot);
    return 0;
}

int LuaUnit::DurabilityPointsLossAll(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    int32 points = luaL_checkinteger(L, 1);
    bool inventory = luaL_optbool(L, 2, true);

    player->DurabilityPointsLossAll(points, inventory);
    return 0;
}

int LuaUnit::DurabilityPointsLoss(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    Item* item = sEluna->CHECK_ITEM(L, 1);
    int32 points = luaL_checkinteger(L, 2);

    if (item)
        player->DurabilityPointsLoss(item, points);
    return 0;
}

int LuaUnit::DurabilityLoss(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    Item* item = sEluna->CHECK_ITEM(L, 1);
    double percent = luaL_checknumber(L, 2);

    if (item)
        player->DurabilityLoss(item, percent);
    return 0;
}

int LuaUnit::DurabilityLossAll(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    double percent = luaL_checknumber(L, 1);
    bool inventory = luaL_optbool(L, 2, true);

    player->DurabilityLossAll(percent, inventory);
    return 0;
}

int LuaUnit::KillPlayer(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->KillPlayer();
    return 0;
}

int LuaUnit::GetManaBonusFromIntellect(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushFloat(L, player->GetManaBonusFromIntellect());
    return 1;
}

int LuaUnit::GetHealthBonusFromStamina(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushFloat(L, player->GetHealthBonusFromStamina());
    return 1;
}

int LuaUnit::GetDifficulty(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    bool isRaid = luaL_optbool(L, 1, true);

    sEluna->PushUnsigned(L, player->GetDifficulty(isRaid));
    return 1;
}

int LuaUnit::GetGuildRank(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetRank());
    return 1;
}

int LuaUnit::SetGuildRank(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint8 rank = luaL_checkunsigned(L, 1);

    if (!player->GetGuild())
        return 0;

    player->SetRank(rank);
    return 0;
}

int LuaUnit::RemoveFromGroup(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    if (!player->GetGroup())
        return 0;

    player->RemoveFromGroup();
    return 0;
}

int LuaUnit::IsGroupVisibleFor(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    Player* target = sEluna->CHECK_PLAYER(L, 1);
    if (!target)
        sEluna->PushBoolean(L, false);
    else
        sEluna->PushBoolean(L, player->IsGroupVisibleFor(target));
    return 1;
}

int LuaUnit::IsInSameRaidWith(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    Player* target = sEluna->CHECK_PLAYER(L, 1);
    if (!target)
        sEluna->PushBoolean(L, false);
    else
        sEluna->PushBoolean(L, player->IsInSameRaidWith(target));
    return 1;
}

int LuaUnit::IsInSameGroupWith(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    Player* target = sEluna->CHECK_PLAYER(L, 1);
    if (!target)
        sEluna->PushBoolean(L, false);
    else
        sEluna->PushBoolean(L, player->IsInSameGroupWith(target));
    return 1;
}

int LuaUnit::SetPvP(lua_State* L, Unit* unit)
{
    TO_UNIT();

    bool apply = luaL_optbool(L, 1, true);

    unit->SetPvP(apply);
    return 0;
}

int LuaUnit::SetFFA(lua_State* L, Unit* unit)
{
    TO_UNIT();

    bool apply = luaL_optbool(L, 1, true);

    if (apply)
        unit->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);
    else
        unit->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_FFA_PVP);

    return 0;
}

int LuaUnit::SetSanctuary(lua_State* L, Unit* unit)
{
    TO_UNIT();

    bool apply = luaL_optbool(L, 1, true);

    if (apply)
    {
        unit->SetByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);
        unit->CombatStop();
        unit->CombatStopWithPets();
    }
    else
        unit->RemoveByteFlag(UNIT_FIELD_BYTES_2, 1, UNIT_BYTE2_FLAG_SANCTUARY);

    return 0;
}

int LuaUnit::GetSpellCooldownDelay(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 spellId = luaL_checkunsigned(L, 1);

    sEluna->PushUnsigned(L, player->GetSpellCooldownDelay(spellId));
    return 1;
}

int LuaUnit::HasSpellCooldown(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    uint32 spellId = luaL_checkunsigned(L, 1);

    if (Player* player = unit->ToPlayer())
        sEluna->PushBoolean(L, player->HasSpellCooldown(spellId));
    else if (Creature* creature = unit->ToCreature())
        sEluna->PushBoolean(L, creature->HasSpellCooldown(spellId));
    else
        sEluna->PushBoolean(L, false);
    return 1;
}

int LuaUnit::IsAuctioneer(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsAuctioner());
    return 1;
}

int LuaUnit::HealthBelowPct(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->HealthBelowPct(luaL_checkint(L, 1)));
    return 1;
}

int LuaUnit::HealthAbovePct(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->HealthAbovePct(luaL_checkint(L, 1)));
    return 1;
}

int LuaUnit::GetSpecsCount(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetSpecsCount());
    return 1;
}

int LuaUnit::GetActiveSpec(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetActiveSpec());
    return 1;
}

int LuaUnit::HasTalent(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 spellId = luaL_checkunsigned(L, 1);
    uint8 spec = luaL_checkunsigned(L, 2);
    if (spec >= MAX_TALENT_SPECS)
        sEluna->PushBoolean(L, false);
    else
        sEluna->PushBoolean(L, player->HasTalent(spellId, spec));
    return 1;
}

int LuaUnit::AddTalent(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 spellId = luaL_checkunsigned(L, 1);
    uint8 spec = luaL_checkunsigned(L, 2);
    bool learning = luaL_optbool(L, 3, true);
    if (spec >= MAX_TALENT_SPECS)
        sEluna->PushBoolean(L, false);
    else
        sEluna->PushBoolean(L, player->AddTalent(spellId, spec, learning));
    return 1;
}

int LuaUnit::ResetTalentsCost(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->resetTalentsCost());
    return 1;
}

int LuaUnit::ResetTalents(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    bool no_cost = luaL_optbool(L, 1, false);

    player->resetTalents(no_cost);
    player->SendTalentsInfoData(false);
    return 0;
}

int LuaUnit::SetFreeTalentPoints(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 points = luaL_checkunsigned(L, 1);

    player->SetFreeTalentPoints(points);
    return 0;
}

int LuaUnit::GetFreeTalentPoints(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetFreeTalentPoints());
    return 1;
}

int LuaUnit::GetGuildName(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    if (!player->GetGuildId())
        return 0;
    sEluna->PushString(L, player->GetGuildName().c_str());
    return 1;
}

int LuaUnit::GetReputation(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 faction = luaL_checkunsigned(L, 1);

    sEluna->PushUnsigned(L, player->GetReputation(faction));
    return 1;
}

int LuaUnit::SetReputation(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 faction = luaL_checkunsigned(L, 1);
    uint32 value = luaL_checkunsigned(L, 2);

    player->SetReputation(faction, value);
    return 0;
}

int LuaUnit::RemoveSpell(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);
    bool disabled = luaL_optbool(L, 2, false);
    bool learn_low_rank = luaL_optbool(L, 3, true);

    player->removeSpell(entry, disabled, learn_low_rank);
    return 0;
}

int LuaUnit::ClearComboPoints(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->ClearComboPoints();
    return 0;
}

int LuaUnit::GainSpellComboPoints(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    int8 count = luaL_checkinteger(L, 1);

    player->GainSpellComboPoints(count);
    return 0;
}

int LuaUnit::AddComboPoints(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    Unit* target = sEluna->CHECK_UNIT(L, 1);
    int8 count = luaL_checkinteger(L, 2);
    Spell* spell = sEluna->CHECK_SPELL(L, 3);
    if (!target)
        return 0;

    player->AddComboPoints(target, count, spell);
    return 0;
}

int LuaUnit::GetComboTarget(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnit(L, sObjectAccessor->FindUnit(player->GetComboTarget()));
    return 1;
}

int LuaUnit::GetComboPoints(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetComboPoints());
    return 1;
}

int LuaUnit::HasReceivedQuestReward(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 entry = luaL_checkunsigned(L, 1);

    sEluna->PushBoolean(L, player->IsQuestRewarded(entry));
    return 1;
}

int LuaUnit::RegenerateHealth(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->RegenerateHealth();
    return 0;
}

int LuaUnit::Regenerate(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 power = luaL_checkunsigned(L, 1);
    if (power >= MAX_POWERS)
        return 0;

    player->Regenerate((Powers)power);
    return 0;
}

int LuaUnit::RegenerateAll(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->RegenerateAll();
    return 0;
}

int LuaUnit::ResetPetTalents(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->ResetPetTalents();
    return 0;
}

int LuaUnit::SaveToDB(lua_State* L, Unit* unit)
{
    TO_UNIT();

    if (Player* player = unit->ToPlayer())
        player->SaveToDB();
    if (Creature* creature = unit->ToCreature())
        creature->SaveToDB();
    return 0;
}

int LuaUnit::Emote(lua_State* L, Unit* unit)
{
    TO_UNIT();

    unit->HandleEmoteCommand(luaL_checkunsigned(L, 1));
    return 0;
}

int LuaUnit::CountPctFromCurHealth(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->CountPctFromCurHealth(luaL_checkint(L, 1)));
    return 1;
}

int LuaUnit::CountPctFromMaxHealth(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->CountPctFromMaxHealth(luaL_checkint(L, 1)));
    return 1;
}

int LuaUnit::GetInGameTime(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetInGameTime());
    return 1;
}

int LuaUnit::TalkedToCreature(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);
    Creature* creature = sEluna->CHECK_CREATURE(L, 2);
    if (!creature)
        return 0;

    player->TalkedToCreature(entry, creature->GetGUID());
    return 0;
}

int LuaUnit::CastedCreatureOrGO(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);
    Unit* creaOrGo = sEluna->CHECK_UNIT(L, 2);
    uint32 spellId = luaL_checkunsigned(L, 3);
    if (!creaOrGo || !creaOrGo->ToGameObject() || !creaOrGo->ToCreature())
        return 0;

    player->CastedCreatureOrGO(entry, creaOrGo->GetGUID(), spellId);
    return 0;
}

int LuaUnit::KilledPlayerCredit(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->KilledPlayerCredit();
    return 0;
}

int LuaUnit::KilledMonsterCredit(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);

    player->KilledMonsterCredit(entry, 0);
    return 0;
}

int LuaUnit::GroupEventHappens(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 questId = luaL_checkunsigned(L, 1);
    WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 1);
    if (!obj)
        return 0;

    player->GroupEventHappens(questId, obj);
    return 0;
}

int LuaUnit::AreaExploredOrEventHappens(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 questId = luaL_checkunsigned(L, 1);

    player->AreaExploredOrEventHappens(questId);
    return 0;
}

int LuaUnit::CanShareQuest(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 entry = luaL_checkunsigned(L, 1);

    sEluna->PushBoolean(L, player->CanShareQuest(entry));
    return 1;
}

int LuaUnit::HasQuestForGO(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    int32 entry = luaL_checkinteger(L, 1);

    sEluna->PushBoolean(L, player->HasQuestForGO(entry));
    return 1;
}

int LuaUnit::HasQuestForItem(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 entry = luaL_checkunsigned(L, 1);

    sEluna->PushBoolean(L, player->HasQuestForItem(entry));
    return 1;
}

int LuaUnit::GetReqKillOrCastCurrentCount(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 questId = luaL_checkunsigned(L, 1);
    int32 entry = luaL_checkinteger(L, 2);

    sEluna->PushUnsigned(L, player->GetReqKillOrCastCurrentCount(questId, entry));
    return 1;
}

int LuaUnit::RemoveRewardedQuest(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);

    player->RemoveRewardedQuest(entry);
    return 0;
}

int LuaUnit::RemoveActiveQuest(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);

    player->RemoveActiveQuest(entry);
    return 0;
}

int LuaUnit::SetQuestStatus(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);
    uint32 status = luaL_checkunsigned(L, 2);
    if (status >= MAX_QUEST_STATUS)
        return 0;

    player->SetQuestStatus(entry, (QuestStatus)status);
    return 0;
}

int LuaUnit::GetQuestStatus(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);

    sEluna->PushInteger(L, player->GetQuestStatus(entry));
    return 1;
}

int LuaUnit::FailQuest(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);

    player->FailQuest(entry);
    return 0;
}

int LuaUnit::IncompleteQuest(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);

    player->IncompleteQuest(entry);
    return 0;
}

int LuaUnit::CompleteQuest(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);

    player->CompleteQuest(entry);
    return 0;
}

int LuaUnit::IsActiveQuest(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 entry = luaL_checkunsigned(L, 1);

    sEluna->PushBoolean(L, player->IsActiveQuest(entry));
    return 1;
}

int LuaUnit::GetQuestLevel(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    Quest* quest = sEluna->CHECK_QUEST(L, 1);
    if (!quest)
        return 0;

    sEluna->PushInteger(L, player->GetQuestLevel(quest));
    return 1;
}

int LuaUnit::GetItemByEntry(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);

    sEluna->PushItem(L, player->GetItemByEntry(entry));
    return 1;
}

int LuaUnit::SetSheath(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 sheathed = luaL_checkunsigned(L, 1);
    if (sheathed >= MAX_SHEATH_STATE)
        return 0;

    if (Player* player = unit->ToPlayer())
        player->SetSheath((SheathState)sheathed);
    else
        unit->SetSheath((SheathState)sheathed);
    return 0;
}

int LuaUnit::Whisper(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    std::string text = luaL_checkstring(L, 1);
    uint32 lang = luaL_checkunsigned(L, 2);
    uint32 guid = sEluna->CHECK_ULONG(L, 3);

    player->Whisper(text, lang, guid);
    return 0;
}

int LuaUnit::TextEmote(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    std::string text = luaL_checkstring(L, 1);

    player->TextEmote(text);
    return 0;
}

int LuaUnit::Yell(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    std::string text = luaL_checkstring(L, 1);
    uint32 lang = luaL_checkunsigned(L, 2);

    player->Yell(text, lang);
    return 0;
}

int LuaUnit::Say(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    std::string text = luaL_checkstring(L, 1);
    uint32 lang = luaL_checkunsigned(L, 2);

    player->Say(text, lang);
    return 0;
}

int LuaUnit::GetPhaseMaskForSpawn(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetPhaseMaskForSpawn());
    return 1;
}

int LuaUnit::SummonPet(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 entry = luaL_checkunsigned(L, 1);
    float x = luaL_checknumber(L, 2);
    float y = luaL_checknumber(L, 3);
    float z = luaL_checknumber(L, 4);
    float o = luaL_checknumber(L, 5);
    uint32 petType = luaL_checkunsigned(L, 6);
    uint32 despwtime = luaL_checkunsigned(L, 7);

    if (petType >= MAX_PET_TYPE)
        return 0;

    player->SummonPet(entry, x, y, z, o, (PetType)petType, despwtime);
    return 0;
}

int LuaUnit::RemovePet(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    int mode = luaL_optint(L, 1, PET_SAVE_AS_DELETED);
    bool returnreagent = luaL_optbool(L, 1, false);

    if (!player->GetPet())
        return 0;

    player->RemovePet(player->GetPet(), (PetSaveMode)mode, returnreagent);
    return 0;
}

int LuaUnit::GetRestType(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushInteger(L, player->GetRestType());
    return 1;
}

int LuaUnit::SetRestType(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    int type = luaL_checkinteger(L, 1);

    player->SetRestType((RestType)type);
    return 0;
}

int LuaUnit::SetRestBonus(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    float bonus = luaL_checknumber(L, 1);

    player->SetRestBonus(bonus);
    return 0;
}

int LuaUnit::GetRestBonus(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushFloat(L, player->GetRestBonus());
    return 1;
}

int LuaUnit::GiveLevel(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint8 level = luaL_checkunsigned(L, 1);

    player->GiveLevel(level);
    return 0;
}

int LuaUnit::GiveXP(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 xp = luaL_checkunsigned(L, 1);
    Unit* victim = sEluna->CHECK_UNIT(L, 2);
    float group_rate = luaL_optnumber(L, 3, 1.0f);

    player->GiveXP(xp, victim, group_rate);
    return 0;
}

int LuaUnit::IsGMVisible(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->isGMVisible());
    return 1;
}

int LuaUnit::IsTaxiCheater(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->isTaxiCheater());
    return 1;
}

int LuaUnit::IsGMChat(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->isGMChat());
    return 1;
}

int LuaUnit::IsAcceptingWhispers(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->isAcceptWhispers());
    return 1;
}

int LuaUnit::SetAcceptWhispers(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    bool on = luaL_optbool(L, 1, true);

    player->SetAcceptWhispers(on);
    return 0;
}

int LuaUnit::SetPvPDeath(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    bool on = luaL_optbool(L, 1, true);

    player->SetPvPDeath(on);
    return 0;
}

int LuaUnit::SetGMVisible(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    bool on = luaL_optbool(L, 1, true);

    player->SetGMVisible(on);
    return 0;
}

int LuaUnit::SetTaxiCheat(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    bool on = luaL_optbool(L, 1, true);

    player->SetTaxiCheater(on);
    return 0;
}

int LuaUnit::SetGMChat(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    bool on = luaL_optbool(L, 1, true);

    player->SetGMChat(on);
    return 0;
}

int LuaUnit::SetGameMaster(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    bool on = luaL_optbool(L, 1, true);

    player->SetGameMaster(on);
    return 0;
}

int LuaUnit::GetChatTag(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetChatTag());
    return 1;
}

int LuaUnit::IsDND(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->isDND());
    return 1;
}

int LuaUnit::IsAFK(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->isAFK());
    return 1;
}

int LuaUnit::ToggleDND(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->ToggleDND();
    return 0;
}

int LuaUnit::ToggleAFK(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->ToggleAFK();
    return 0;
}

int LuaUnit::IsFalling(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->IsFalling());
    return 1;
}

int LuaUnit::IsUnderWater(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsUnderWater());
    return 1;
}

int LuaUnit::IsInWater(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    if (Player* player = unit->ToPlayer())
        sEluna->PushBoolean(L, player->IsInWater());
    else
        sEluna->PushBoolean(L, unit->IsInWater());
    return 1;
}

int LuaUnit::GetVictim(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushUnit(L, creature->SelectVictim());
    return 1;
}

int LuaUnit::GetNearestTargetInAttackDistance(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    float dist = luaL_optnumber(L, 1, 0.0f);
    sEluna->PushUnit(L, creature->SelectNearestTargetInAttackDistance(dist));
    return 1;
}

int LuaUnit::GetNearestTarget(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    float dist = luaL_optnumber(L, 1, 0.0f);
    sEluna->PushUnit(L, creature->SelectNearestTarget(dist));
    return 1;
}

int LuaUnit::GetNearestHostileTargetInAggroRange(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    bool checkLOS = luaL_optbool(L, 1, false);
    sEluna->PushUnit(L, creature->SelectNearestHostileUnitInAggroRange(checkLOS));
    return 1;
}

int LuaUnit::GetNearbyTarget(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float dist = luaL_optnumber(L, 1, 5.0f);
    Unit* exclude = sEluna->CHECK_UNIT(L, 2);

    sEluna->PushUnit(L, unit->SelectNearbyTarget(exclude, dist));
    return 1;
}

int LuaUnit::GetObjectGlobally(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 lowguid = luaL_checkunsigned(L, 1);
    uint32 entry = luaL_checkunsigned(L, 2);

    sEluna->PushGO(L, ChatHandler(player->GetSession()).GetObjectGlobalyWithGuidOrNearWithDbGuid(lowguid, entry));
    return 1;
}

int LuaUnit::GetNearbyGameObject(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushGO(L, ChatHandler(player->GetSession()).GetNearbyGameObject());
    return 1;
}

int LuaUnit::SendChatMessageToPlayer(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint8 type = luaL_checkunsigned(L, 1);
    uint32 lang = luaL_checkunsigned(L, 2);
    const char* msg = luaL_checkstring(L, 3);
    Player* target = sEluna->CHECK_PLAYER(L, 4);
    if (!target || type == CHAT_MSG_CHANNEL)
        return 0;

    WorldPacket* data = new WorldPacket();
    uint32 messageLength = (uint32)strlen(msg) + 1;
    data->Initialize(SMSG_MESSAGECHAT, 100);
    *data << (uint8)type;
    *data << lang;
    *data << unit->GetGUID();
    *data << uint32(0);
    *data << unit->GetGUID();
    *data << messageLength;
    *data << msg;
    if (unit->ToPlayer() && type != CHAT_MSG_WHISPER_INFORM && type != CHAT_MSG_DND && type != CHAT_MSG_AFK)
        *data << uint8(unit->ToPlayer()->GetChatTag());
    else
        *data << uint8(0);
    target->GetSession()->SendPacket(data);
    return 0;
}

int LuaUnit::GetCurrentSpell(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 type = luaL_checkunsigned(L, 1);
    if (type >= CURRENT_MAX_SPELL)
    {
        luaL_error(L, "Invalid spell type (%d)", type);
        return 0;
    }
    sEluna->PushSpell(L, unit->GetCurrentSpell(type));
    return 1;
}

int LuaUnit::EquipItem(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint16 dest = 0;
    Item* item = sEluna->CHECK_ITEM(L, 1);
    uint32 slot = luaL_checkunsigned(L, 2);

    if (slot >= EQUIPMENT_SLOT_END)
        return 0;

    if (!item)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        item = Item::CreateItem(entry, 1, player);
        if (!item)
            return 0;

        InventoryResult result = player->CanEquipItem(slot, dest, item, false);
        if (result != EQUIP_ERR_OK)
        {
            delete item;
            return 0;
        }
        player->ItemAddedQuestCheck(entry, 1);
        player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM, entry, 1);
    }
    else
    {
        InventoryResult result = player->CanEquipItem(slot, dest, item, false);
        if (result != EQUIP_ERR_OK)
            return 0;
        player->RemoveItem(item->GetBagSlot(), item->GetSlot(), true);
    }

    sEluna->PushItem(L, player->EquipItem(dest, item, true));
    return 1;
}

int LuaUnit::CanEquipItem(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    Item* item = sEluna->CHECK_ITEM(L, 1);
    uint32 slot = luaL_checkunsigned(L, 2);
    if (slot >= EQUIPMENT_SLOT_END)
    {
        sEluna->PushBoolean(L, false);
        return 1;
    }

    if (!item)
    {
        uint32 entry = luaL_checkunsigned(L, 1);
        uint16 dest;
        InventoryResult msg = player->CanEquipNewItem(slot, dest, entry, false);
        if (msg != EQUIP_ERR_OK)
        {
            sEluna->PushBoolean(L, false);
            return 1;
        }
    }
    else
    {
        uint16 dest;
        InventoryResult msg = player->CanEquipItem(slot, dest, item, false);
        if (msg != EQUIP_ERR_OK)
        {
            sEluna->PushBoolean(L, false);
            return 1;
        }
    }
    sEluna->PushBoolean(L, true);
    return 1;
}

int LuaUnit::GetInventoryItem(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint8 slot = luaL_checkunsigned(L, 1);
    if (slot >= INVENTORY_SLOT_ITEM_END)
        return 0;

    Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
    sEluna->PushItem(L, item);
    return 1;
}

int LuaUnit::GetBagItem(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint8 bagslot = luaL_checkunsigned(L, 1);
    uint8 slot = luaL_checkunsigned(L, 2);

    if (bagslot < INVENTORY_SLOT_BAG_START && bagslot >= INVENTORY_SLOT_BAG_END)
        return 0;

    Bag* bag = player->GetBagByPos(bagslot);
    if (!bag || slot >= bag->GetBagSize())
        return 0;

    Item* item = player->GetItemByPos(bagslot, slot);
    sEluna->PushItem(L, item);
    return 1;
}

int LuaUnit::SummonGameObject(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 entry = luaL_checkunsigned(L, 1);
    float x = luaL_checknumber(L, 2);
    float y = luaL_checknumber(L, 3);
    float z = luaL_checknumber(L, 4);
    float o = luaL_checknumber(L, 5);
    uint32 respawnDelay = luaL_optunsigned(L, 6, 30);
    sEluna->PushGO(L, unit->SummonGameObject(entry, x, y, z, o, 0, 0, 0, 0, respawnDelay));
    return 1;
}

int LuaUnit::SpawnCreature(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 entry = luaL_checkunsigned(L, 1);
    float x = luaL_checknumber(L, 2);
    float y = luaL_checknumber(L, 3);
    float z = luaL_checknumber(L, 4);
    float o = luaL_checknumber(L, 5);
    uint32 desp = luaL_optunsigned(L, 6, 0);
    sEluna->PushUnit(L, unit->SummonCreature(entry, x, y, z, o, desp ? TEMPSUMMON_TIMED_OR_DEAD_DESPAWN : TEMPSUMMON_MANUAL_DESPAWN, desp));
    return 1;
}

int LuaUnit::Despawn(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    uint32 time = luaL_optunsigned(L, 1, 0);
    creature->DespawnOrUnsummon(time);
    return 0;
}

int LuaUnit::GetArenaPoints(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetArenaPoints());
    return 1;
}

int LuaUnit::KnockbackFrom(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);
    float speedXY = luaL_checknumber(L, 3);
    float speedZ = luaL_checknumber(L, 4);
    unit->KnockbackFrom(x, y, speedXY, speedZ);
    return 0;
}

int LuaUnit::JumpTo(lua_State* L, Unit* unit)
{
    TO_UNIT();

    WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 1);
    float speedZ = luaL_checknumber(L, 2);
    if (!obj)
        return 0;

    unit->JumpTo(obj, speedZ);
    return 0;
}

int LuaUnit::Jump(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float speedXY = luaL_checknumber(L, 1);
    float speedZ = luaL_checknumber(L, 2);
    bool forward = luaL_optbool(L, 3, true);
    unit->JumpTo(speedXY, speedZ, forward);
    return 0;
}

int LuaUnit::JumpToCoords(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);
    float z = luaL_checknumber(L, 3);
    float speedXY = luaL_checknumber(L, 4);
    float speedZ = luaL_checknumber(L, 5);
    unit->GetMotionMaster()->MoveJump(x, y, z, speedXY, speedZ);
    return 0;
}

int LuaUnit::MoveCharge(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);
    float z = luaL_checknumber(L, 3);
    float speed = luaL_checknumber(L, 4);
    unit->GetMotionMaster()->MoveCharge(x, y, z, speed);
    return 0;
}

int LuaUnit::MoveChase(lua_State* L, Unit* unit)
{
    TO_UNIT();

    Unit* target = sEluna->CHECK_UNIT(L, 1);
    float dist = luaL_optnumber(L, 2, 0.0f);
    float angle = luaL_optnumber(L, 3, 0.0f);
    unit->GetMotionMaster()->MoveChase(target, dist, angle);
    return 0;
}

int LuaUnit::SetStunned(lua_State* L, Unit* unit)
{
    TO_UNIT();

    bool apply = luaL_optbool(L, 1, true);
    unit->SetControlled(apply, UNIT_STATE_STUNNED);
    return 0;
}

int LuaUnit::SetRooted(lua_State* L, Unit* unit)
{
    TO_UNIT();

    bool apply = luaL_optbool(L, 1, true);
    unit->SetControlled(apply, UNIT_STATE_ROOT);
    return 0;
}

int LuaUnit::SetConfused(lua_State* L, Unit* unit)
{
    TO_UNIT();

    bool apply = luaL_optbool(L, 1, true);
    unit->SetControlled(apply, UNIT_STATE_CONFUSED);
    return 0;
}

int LuaUnit::SetFeared(lua_State* L, Unit* unit)
{
    TO_UNIT();

    bool apply = luaL_optbool(L, 1, true);
    unit->SetControlled(apply, UNIT_STATE_FLEEING);
    return 0;
}

int LuaUnit::SetGender(lua_State * L, Unit * unit)
{
    TO_PLAYER();

    Gender gender;
    uint32 _gender = luaL_checkint(L, 1);

    switch (_gender)
    {
    case 0:
        gender = GENDER_MALE;
        break;
    case 1:
        gender = GENDER_FEMALE;
        break;
    default:
        luaL_error(L, "Invalid gender (%d)", _gender);
        return 0;
    }

    player->SetByteValue(UNIT_FIELD_BYTES_0, 2, gender);
    player->SetByteValue(PLAYER_BYTES_3, 0, gender);
    player->InitDisplayIds();
    return 0;
}

int LuaUnit::MoveTo(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float id = luaL_checknumber(L, 1);
    float x = luaL_checknumber(L, 2);
    float y = luaL_checknumber(L, 3);
    float z = luaL_checknumber(L, 4);
    bool generatePath = luaL_optbool(L, 5, true);
    unit->GetMotionMaster()->MovePoint(id, x, y, z, generatePath);
    return 0;
}

int LuaUnit::MoveFollow(lua_State* L, Unit* unit)
{
    TO_UNIT();

    Unit* target = sEluna->CHECK_UNIT(L, 1);
    float dist = luaL_checknumber(L, 2);
    float angle = luaL_checknumber(L, 3);
    unit->GetMotionMaster()->MoveFollow(target, dist, angle);
    return 0;
}

int LuaUnit::MoveClear(lua_State* L, Unit* unit)
{
    TO_UNIT();

    unit->GetMotionMaster()->Clear();
    return 0;
}

int LuaUnit::MoveRandom(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float radius = luaL_checknumber(L, 1);
    unit->GetMotionMaster()->MoveRandom(radius);
    return 0;
}

int LuaUnit::MoveRotate(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 time = luaL_checkunsigned(L, 1);
    bool left = luaL_optbool(L, 2, true);
    unit->GetMotionMaster()->MoveRotate(time, left ? ROTATE_DIRECTION_LEFT : ROTATE_DIRECTION_RIGHT);
    return 0;
}

int LuaUnit::SetWalk(lua_State* L, Unit* unit)
{
    TO_UNIT();

    bool enable = luaL_optbool(L, 1, true);
    if (Creature* creature = unit->ToCreature())
        sEluna->PushBoolean(L, creature->SetWalk(enable));
    else
        sEluna->PushBoolean(L, unit->SetWalk(enable));
    return 1;
}

int LuaUnit::SetSpeed(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 type = luaL_checkunsigned(L, 1);
    float rate = luaL_checknumber(L, 2);
    bool forced = luaL_optbool(L, 3, false);
    if (type >= MAX_MOVE_TYPE)
        luaL_error(L, "Invalid movement type (%d)", type);
    else
        unit->SetSpeed((UnitMoveType)type, rate, forced);
    return 0;
}

int LuaUnit::GetHonorPoints(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetHonorPoints());
    return 1;
}

int LuaUnit::GetSelection(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnit(L, player->GetSelectedUnit());
    return 1;
}

int LuaUnit::GetGMRank(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushInteger(L, player->GetSession()->GetSecurity());
    return 1;
}

int LuaUnit::GetCoinage(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetMoney());
    return 1;
}

int LuaUnit::GetDisplayId(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetDisplayId());
    return 1;
}

int LuaUnit::GetNativeDisplayId(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetNativeDisplayId());
    return 1;
}

int LuaUnit::GetName(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushString(L, unit->GetName().c_str());
    return 1;
}

int LuaUnit::GetLevel(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->getLevel());
    return 1;
}

int LuaUnit::GetHealth(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetHealth());
    return 1;
}

int LuaUnit::GetGuildId(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetGuildId());
    return 1;
}

int LuaUnit::GetX(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushFloat(L, unit->GetPositionX());
    return 1;
}

int LuaUnit::GetY(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushFloat(L, unit->GetPositionY());
    return 1;
}

int LuaUnit::GetZ(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushFloat(L, unit->GetPositionZ());
    return 1;
}

int LuaUnit::GetO(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushFloat(L, unit->GetOrientation());
    return 1;
}

int LuaUnit::GetLocation(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushFloat(L, unit->GetPositionX());
    sEluna->PushFloat(L, unit->GetPositionY());
    sEluna->PushFloat(L, unit->GetPositionZ());
    sEluna->PushFloat(L, unit->GetOrientation());
    return 4;
}

int LuaUnit::GetZoneId(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetZoneId());
    return 1;
}

int LuaUnit::GetInstanceId(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetInstanceId());
    return 1;
}

int LuaUnit::GetPhaseMask(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetPhaseMask());
    return 1;
}

int LuaUnit::GetAreaId(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetAreaId());
    return 1;
}

int LuaUnit::GetTeam(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushInteger(L, player->GetTeamId());
    return 1;
}

int LuaUnit::GetGUID(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushULong(L, unit->GetGUID());
    return 1;
}

int LuaUnit::GetGUIDLow(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetGUIDLow());
    return 1;
}

int LuaUnit::GetPower(lua_State* L, Unit* unit)
{
    TO_UNIT();

    int type = luaL_optint(L, 1, -1);
    if (type == -1)
    {

        switch (unit->getClass())
        {
        case 1:
            type = POWER_RAGE;
            break;
        case 4:
            type = POWER_ENERGY;
            break;
        case 6:
            type = POWER_RUNIC_POWER;
            break;
        case 2:
        case 3:
        case 5:
        case 7:
        case 8:
        case 9:
        case 11:
            type = POWER_MANA;
            break;
        default:
            type = POWER_MANA;
        }
    }
    else if (type >= POWER_ALL)
    {
        luaL_error(L, "Invalid power type (%d)", type);
        return 0;
    }

    sEluna->PushUnsigned(L, unit->GetPower((Powers) type));
    return 1;
}

int LuaUnit::GetMaxPower(lua_State* L, Unit* unit)
{
    TO_UNIT();

    int type = luaL_optint(L, 1, -1);
    if (type == -1)
    {

        switch (unit->getClass())
        {
        case 1:
            type = POWER_RAGE;
            break;
        case 4:
            type = POWER_ENERGY;
            break;
        case 6:
            type = POWER_RUNIC_POWER;
            break;
        case 2:
        case 3:
        case 5:
        case 7:
        case 8:
        case 9:
        case 11:
            type = POWER_MANA;
            break;
        default:
            type = POWER_MANA;
        }
    }
    else if (type < 0 || type >= POWER_ALL)
    {
        luaL_error(L, "Invalid index (%d)", type);
        return 0;
    }

    sEluna->PushUnsigned(L, unit->GetMaxPower((Powers) type));
    return 1;
}

int LuaUnit::GetPowerType(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushInteger(L, unit->getPowerType());
    return 1;
}

int LuaUnit::GetMaxHealth(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetMaxHealth());
    return 1;
}

int LuaUnit::GetHealthPct(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushFloat(L, unit->GetHealthPct());
    return 1;
}

int LuaUnit::GetPowerPct(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float percent = (unit->GetPower(unit->getPowerType()) / unit->GetMaxPower(unit->getPowerType())) * 100;
    sEluna->PushFloat(L, percent);
    return 1;
}

int LuaUnit::GetGender(lua_State* L, Unit* unit)
{
    TO_UNIT();
    sEluna->PushUnsigned(L, unit->getGender());
    return 1;
}

int LuaUnit::GetRace(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->getRace());
    return 1;
}

int LuaUnit::GetClass(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->getClass());
    return 1;
}

int LuaUnit::GetCreatureType(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetCreatureType());
    return 1;
}

int LuaUnit::GetClassAsString(lua_State* L, Unit* unit)
{
    TO_UNIT();

    const char* str = NULL;
    switch (unit->getClass())
    {
    case 1:
        str = "Warrior";
        break;
    case 2:
        str = "Paladin";
        break;
    case 3:
        str = "Hunter";
        break;
    case 4:
        str = "Rogue";
        break;
    case 5:
        str = "Priest";
        break;
    case 6:
        str = "Death Knight";
        break;
    case 7:
        str = "Shaman";
        break;
    case 8:
        str = "Mage";
        break;
    case 9:
        str = "Warlock";
        break;
    case 11:
        str = "Druid";
        break;
    default:
        str = "NULL";
        break;
    }

    sEluna->PushString(L, str);
    return 1;
}

int LuaUnit::GetItemCount(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    int id = luaL_checknumber(L, 1);
    bool checkinBank = luaL_optbool(L, 2, false);
    sEluna->PushUnsigned(L, player->GetItemCount(id, checkinBank));
    return 1;
}

int LuaUnit::GetLifetimeKills(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
    sEluna->PushUnsigned(L, currentKills);
    return 1;
}

int LuaUnit::GetPlayerIP(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushString(L, player->GetSession()->GetRemoteAddress().c_str());
    return 1;
}

int LuaUnit::GetLevelPlayedTime(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetLevelPlayedTime());
    return 1;
}

int LuaUnit::GetTotalPlayedTime(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetTotalPlayedTime());
    return 1;
}

int LuaUnit::GetUnitType(lua_State* L, Unit* unit)
{
    TO_UNIT();

    if (unit->ToPlayer())
        sEluna->PushString(L, "Player");
    else if (unit->ToCreature())
        sEluna->PushString(L, "Creature");
    else
        sEluna->PushString(L, "Unknown");
    return 1;
}

int LuaUnit::GetGuild(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushGuild(L, player->GetGuild());
    return 1;
}

int LuaUnit::GetGroup(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushGroup(L, player->GetGroup());
    return 1;
}

int LuaUnit::GetGearLevel(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushFloat(L, player->GetAverageItemLevel());
    return 1;
}

int LuaUnit::GetEntry(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetEntry());
    return 1;
}

int LuaUnit::GetFaction(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->getFaction());
    return 1;
}

int LuaUnit::SetFaction(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 factionId = luaL_checkunsigned(L, 1);
    unit->setFaction(factionId);
    return 0;
}

int LuaUnit::SetLevel(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 newLevel = luaL_checkunsigned(L, 1);
    unit->SetLevel(newLevel);
    return 0;
}

int LuaUnit::SetPhaseMask(lua_State* L, Unit* unit)
{
    TO_UNIT();
    uint32 phaseMask = luaL_checkunsigned(L, 1);
    bool Update = luaL_optbool(L, 2, true);
    unit->SetPhaseMask(phaseMask, Update);
    return 0;
}

int LuaUnit::SetArenaPoints(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 arenaP = luaL_checkunsigned(L, 1);
    player->SetArenaPoints(arenaP);
    return 0;
}

int LuaUnit::SetHonorPoints(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 honorP = luaL_checkunsigned(L, 1);
    player->SetHonorPoints(honorP);
    return 0;
}

int LuaUnit::SetLifetimeKills(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 val = luaL_checkunsigned(L, 1);
    player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, val);
    return 0;
}

int LuaUnit::SetHealth(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 amt = luaL_checkunsigned(L, 1);
    unit->SetHealth(amt);
    return 0;
}

int LuaUnit::SetMaxHealth(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 amt = luaL_checkunsigned(L, 1);
    unit->SetMaxHealth(amt);
    return 0;
}

int LuaUnit::SetPower(lua_State* L, Unit* unit)
{
    TO_UNIT();

    int type = luaL_checkinteger(L, 1);
    uint32 amt = luaL_checkunsigned(L, 2);

    switch (type)
    {
    case POWER_MANA:
        unit->SetPower(POWER_MANA, amt);
        break;
    case POWER_RAGE:
        unit->SetPower(POWER_RAGE, amt);
        break;
    case POWER_ENERGY:
        unit->SetPower(POWER_ENERGY, amt);
        break;
    case POWER_RUNIC_POWER:
        unit->SetPower(POWER_RUNIC_POWER, amt);
        break;
    default:
        luaL_error(L, "Invalid power type (%d)", type);
        break;
    }
    return 0;
}

int LuaUnit::SetMaxPower(lua_State* L, Unit* unit)
{
    TO_UNIT();

    int type = luaL_checkinteger(L, 1);
    int amt = luaL_checkunsigned(L, 2);

    switch (type)
    {
    case POWER_MANA:
        unit->SetMaxPower(POWER_MANA, amt);
        break;
    case POWER_RAGE:
        unit->SetMaxPower(POWER_RAGE, amt);
        break;
    case POWER_ENERGY:
        unit->SetMaxPower(POWER_ENERGY, amt);
        break;
    case POWER_RUNIC_POWER:
        unit->SetMaxPower(POWER_RUNIC_POWER, amt);
        break;
    default:
        luaL_error(L, "Invalid power type (%d)", type);
        break;
    }
    return 0;
}

int LuaUnit::SetDisplayId(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 model = luaL_checkunsigned(L, 1);
    unit->SetDisplayId(model);
    return 0;
}

int LuaUnit::SetNativeDisplayId(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 model = luaL_checkunsigned(L, 1);
    unit->SetNativeDisplayId(model);
    return 0;
}

int LuaUnit::SetFacing(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float o = luaL_checknumber(L, 1);
    unit->SetFacingTo(o);
    return 0;
}

int LuaUnit::SetCoinage(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 amt = luaL_checkunsigned(L, 1);
    player->SetMoney(amt);
    return 0;
}

int LuaUnit::SetBindPoint(lua_State * L, Unit* unit)
{
    TO_PLAYER();

    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);
    float z = luaL_checknumber(L, 3);
    uint32 mapId = luaL_checkunsigned(L, 4);
    uint32 areaId = luaL_checkunsigned(L, 5);

    WorldLocation loc(mapId, x, y, z);
    player->SetHomebind(loc, areaId);
    return 0;
}

int LuaUnit::SetBindPointAtPlayerLoc(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    WorldLocation loc;
    player->GetPosition(&loc);
    loc.m_mapId = player->GetMapId();
    player->SetHomebind(loc, player->GetAreaId());
    return 0;
}

int LuaUnit::SetKnownTitle(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 id = luaL_checkunsigned(L, 1);
    CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
    if (t)
        player->SetTitle(t, false);
    return 0;
}

int LuaUnit::UnsetKnownTitle(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 id = luaL_checkunsigned(L, 1);
    CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
    if (t)
        player->SetTitle(t, true);
    return 0;
}

int LuaUnit::AdvanceSkillsToMax(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->UpdateSkillsToMaxSkillsForLevel();
    return 0;
}

int LuaUnit::AdvanceAllSkills(lua_State* L, Unit * unit)
{
    TO_PLAYER();

    uint32 skillsArray[] = { SKILL_BOWS, SKILL_CROSSBOWS, SKILL_DAGGERS, SKILL_DEFENSE, SKILL_UNARMED, SKILL_GUNS, SKILL_AXES, SKILL_MACES, SKILL_SWORDS, SKILL_POLEARMS,
        SKILL_STAVES, SKILL_2H_AXES, SKILL_2H_MACES, SKILL_2H_SWORDS, SKILL_WANDS, SKILL_SHIELD, SKILL_FISHING, SKILL_MINING, SKILL_ENCHANTING, SKILL_BLACKSMITHING,
        SKILL_ALCHEMY, SKILL_HERBALISM, SKILL_ENGINEERING, SKILL_JEWELCRAFTING, SKILL_LEATHERWORKING, SKILL_LOCKPICKING, SKILL_INSCRIPTION, SKILL_SKINNING, SKILL_TAILORING };
    uint32 step = luaL_checkunsigned(L, 1);

    if (!step)
        return 0;

    for (int i = 0; i < sizeof(skillsArray); ++i)
    {
        if (player->HasSkill(skillsArray[i]))
            player->UpdateSkill(skillsArray[i], step);
    }
    return 0;
}

int LuaUnit::AdvanceSkill(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 _skillId = luaL_checkunsigned(L, 1);
    uint32 _step = luaL_checkunsigned(L, 2);
    if (_skillId && _step)
    {
        if (player->HasSkill(_skillId))
            player->UpdateSkill(_skillId, _step);
    }
    return 0;
}

int LuaUnit::IsInGroup(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, (player->GetGroup() != NULL));
    return 1;
}

int LuaUnit::IsInGuild(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, (player->GetGuildId() != 0));
    return 1;
}

int LuaUnit::IsGM(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, player->IsGameMaster());
    return 1;
}

int LuaUnit::IsAlive(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsAlive());
    return 1;
}

int LuaUnit::IsDead(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->isDead());
    return 1;
}

int LuaUnit::IsDying(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->isDying());
    return 1;
}

int LuaUnit::IsBanker(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsBanker());
    return 1;
}

int LuaUnit::IsBattleMaster(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsBattleMaster());
    return 1;
}

int LuaUnit::IsCharmed(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsCharmed());
    return 1;
}

int LuaUnit::IsArmorer(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsArmorer());
    return 1;
}

int LuaUnit::IsAttackingPlayer(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->isAttackingPlayer());
    return 1;
}

int LuaUnit::IsInArenaTeam(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 type = luaL_checkunsigned(L, 1);
    if (type < MAX_ARENA_SLOT && player->GetArenaTeamId(type))
        sEluna->PushBoolean(L, true);
    else
        sEluna->PushBoolean(L, false);
    return 1;
}

int LuaUnit::IsInWorld(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsInWorld());
    return 1;
}

int LuaUnit::IsPvPFlagged(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsPvP());
    return 1;
}

int LuaUnit::HasQuest(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    uint32 questId = luaL_checkunsigned(L, 1);

    if (Player* player = unit->ToPlayer())
        sEluna->PushBoolean(L, player->hasQuest(questId));
    else if (Creature* creature = unit->ToCreature())
        sEluna->PushBoolean(L, creature->hasQuest(questId));
    else
        sEluna->PushBoolean(L, unit->hasQuest(questId));
    return 1;
}

int LuaUnit::IsHorde(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, (player->GetTeam() == HORDE));
    return 1;
}

int LuaUnit::IsAlliance(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    sEluna->PushBoolean(L, (player->GetTeam() == ALLIANCE));
    return 1;
}

int LuaUnit::IsInCombat(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsInCombat());
    return 1;
}

int LuaUnit::HasTitle(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 id = luaL_checkunsigned(L, 1);
    CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(id);
    if (titleInfo)
        sEluna->PushBoolean(L, player->HasTitle(titleInfo));
    else
        sEluna->PushBoolean(L, false);
    return 1;
}

int LuaUnit::HasSpell(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    uint32 id = luaL_checkunsigned(L, 1);
    if (Player* player = unit->ToPlayer())
        sEluna->PushBoolean(L, player->HasSpell(id));
    else if (Creature* creature = unit->ToCreature())
        sEluna->PushBoolean(L, creature->HasSpell(id));
    else
        sEluna->PushBoolean(L, unit->HasSpell(id));
    return 1;
}

int LuaUnit::HasItem(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 itemId = luaL_checkunsigned(L, 1);
    uint32 count = luaL_optunsigned(L, 2, 1);
    bool check_bank = luaL_optbool(L, 3, false);
    sEluna->PushBoolean(L, player->HasItemCount(itemId, count, check_bank));
    return 1;
}

int LuaUnit::Teleport(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 mapId = luaL_checkunsigned(L, 1);
    float X = luaL_checknumber(L, 2);
    float Y = luaL_checknumber(L, 3);
    float Z = luaL_checknumber(L, 4);
    float O = luaL_checknumber(L, 5);
    if (player->IsInFlight())
    {
        player->GetMotionMaster()->MovementExpired();
        player->CleanupAfterTaxiFlight();
    }
    sEluna->PushBoolean(L, player->TeleportTo(mapId, X, Y, Z, O));
    return 1;
}

int LuaUnit::AddLifetimeKills(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 val = luaL_checkunsigned(L, 1);
    uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
    player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills + val);
    return 0;
}

int LuaUnit::AddItem(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    uint32 itemId = luaL_checkunsigned(L, 1);
    uint32 itemCount = luaL_checkunsigned(L, 2);
    sEluna->PushBoolean(L, player->AddItem(itemId, itemCount));
    return 0;
}

int LuaUnit::RemoveItem(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    Item* item = sEluna->CHECK_ITEM(L, 1);
    uint32 itemCount = luaL_checkunsigned(L, 2);
    if (!item)
    {
        uint32 itemId = luaL_checkunsigned(L, 1);
        player->DestroyItemCount(itemId, itemCount, true);
    }
    else
        player->DestroyItemCount(item, itemCount, true);
    return 0;
}

int LuaUnit::RemoveLifetimeKills(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 val = luaL_checkunsigned(L, 1);
    uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
    if (val > currentKills)
        val = currentKills;
    player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills - val);
    return 0;
}

int LuaUnit::ResetSpellCooldown(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 spellId = luaL_checkunsigned(L, 1);
    bool update = luaL_optbool(L, 2, true);
    player->RemoveSpellCooldown(spellId, update);
    return 0;
}

int LuaUnit::ResetTypeCooldowns(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 category = luaL_checkunsigned(L, 1);
    bool update = luaL_optbool(L, 2, true);
    player->RemoveSpellCategoryCooldown(category, update);
    return 0;
}

int LuaUnit::ResetAllCooldowns(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->RemoveAllSpellCooldown();
    return 0;
}

int LuaUnit::SendClearCooldowns(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 spellId = luaL_checkunsigned(L, 1);
    Unit* target = sEluna->CHECK_UNIT(L, 2);
    if (!target)
        return 0;

    player->SendClearCooldown(spellId, target);
    return 0;
}

int LuaUnit::SendBroadcastMessage(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    const char* message = luaL_checkstring(L, 1);
    if (std::string(message).length() > 0)
        ChatHandler(player->GetSession()).SendSysMessage(message);
    return 0;
}

int LuaUnit::SendAreaTriggerMessage(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    const char* msg = luaL_checkstring(L, 1);
    if (std::string(msg).length() > 0)
        player->GetSession()->SendAreaTriggerMessage(msg);
    return 0;
}

int LuaUnit::SendNotification(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    const char* msg = luaL_checkstring(L, 1);
    if (std::string(msg).length() > 0)
        player->GetSession()->SendNotification(msg);
    return 0;
}

int LuaUnit::SendUnitWhisper(lua_State* L, Unit* unit)
{
    TO_UNIT();

    const char* msg = luaL_checkstring(L, 1);
    Unit* receiver = sEluna->CHECK_UNIT(L, 2);
    bool bossWhisper = luaL_optbool(L, 3, false);
    if (receiver && std::string(msg).length() > 0)
        unit->MonsterWhisper(msg, receiver->GetGUID(), bossWhisper);
    return 0;
}

int LuaUnit::SendUnitEmote(lua_State* L, Unit* unit)
{
    TO_UNIT();

    const char* msg = luaL_checkstring(L, 1);
    Unit* receiver = sEluna->CHECK_UNIT(L, 2);
    bool bossEmote = luaL_optbool(L, 3, false);
    if (std::string(msg).length() > 0)
        unit->MonsterTextEmote(msg, receiver ? receiver->GetGUID() : 0, bossEmote);
    return 0;
}

int LuaUnit::SendUnitSay(lua_State* L, Unit* unit)
{
    TO_UNIT();

    const char* msg = luaL_checkstring(L, 1);
    uint32 language = luaL_checknumber(L, 2);
    if (std::string(msg).length() > 0)
        unit->MonsterSay(msg, language, unit->GetGUID());
    return 0;
}

int LuaUnit::SendUnitYell(lua_State* L, Unit* unit)
{
    TO_UNIT();

    const char* msg = luaL_checkstring(L, 1);
    uint32 language = luaL_checknumber(L, 2);
    if (std::string(msg).length() > 0)
        unit->MonsterYell(msg, language, unit->GetGUID());
    return 0;
}

int LuaUnit::SendPacketToPlayer(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
    if (data)
        player->GetSession()->SendPacket(data);
    return 0;
}

int LuaUnit::SendPacket(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
    if (data)
        player->SendMessageToSet(data, false);
    return 0;
}

int LuaUnit::SendPacketToGroup(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
    bool ignorePlayersInBg = luaL_optbool(L, 2, false);
    if (data && player->GetGroup())
        player->GetGroup()->BroadcastPacket(data, ignorePlayersInBg, -1, player->GetGUID());
    return 0;
}

int LuaUnit::SendPacketToGuild(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
    if (data && player->GetGuild())
        player->GetGuild()->BroadcastPacket(data);
    return 0;
}

int LuaUnit::SendPacketToRankedInGuild(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
    uint8 ranked = luaL_checkunsigned(L, 2);
    if (data && player->GetGuild())
        player->GetGuild()->BroadcastPacketToRank(data, ranked);
    return 0;
}

int LuaUnit::SendVendorWindow(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    Unit* sendTo = sEluna->CHECK_UNIT(L, 1);
    if (!sendTo)
        return 0;
    player->GetSession()->SendListInventory(sendTo->GetGUID());
    return 0;
}

int LuaUnit::KickPlayer(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->GetSession()->KickPlayer();
    return 0;
}

int LuaUnit::ModifyMoney(lua_State* L, Unit* unit)
{
    TO_PLAYER_BOOL();

    int32 amt = luaL_checkinteger(L, 1);
    bool sendError = luaL_optbool(L, 2, true);
    sEluna->PushBoolean(L, player->ModifyMoney(amt, sendError));
    return 1;
}

int LuaUnit::LearnSpell(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 id = luaL_checkunsigned(L, 1);
    player->learnSpell(id, false);
    return 0;
}

int LuaUnit::DeMorph(lua_State* L, Unit* unit)
{
    TO_UNIT();

    unit->DeMorph();
    return 0;
}

int LuaUnit::ResurrectPlayer(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    float percent = luaL_optnumber(L, 1, 100.0f);
    bool sickness = luaL_optbool(L, 2, false);
    player->ResurrectPlayer(percent, sickness);
    player->SpawnCorpseBones();
    return 0;
}

int LuaUnit::CastSpell(lua_State* L, Unit* unit)
{
    TO_UNIT();

    Object* obj = sEluna->CHECK_OBJECT(L, 1);
    if (!obj)
        return 0;
    uint32 spell = luaL_checkunsigned(L, 2);
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell);
    if (!spellInfo)
        return 0;
    bool triggered = luaL_optbool(L, 3, true);

    SpellCastTargets targets;
    if (Unit* unitTarget = obj->ToUnit())
        targets.SetUnitTarget(unitTarget);
    else if (GameObject* goTarget = obj->ToGameObject())
        targets.SetGOTarget(goTarget);
    else if (obj->GetTypeId() == TYPEID_ITEM)
    {
        if (Item* itemTarget = reinterpret_cast<Item*>(obj))
            targets.SetItemTarget(itemTarget);
    }
    else
        return 0;

    unit->CastSpell(targets, spellInfo, NULL, triggered ? TRIGGERED_FULL_MASK : TRIGGERED_NONE);
    return 0;
}

int LuaUnit::CastSpellAoF(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float _x = luaL_checknumber(L, 1);
    float _y = luaL_checknumber(L, 2);
    float _z = luaL_checknumber(L, 3);
    uint32 spell = luaL_checkunsigned(L, 4);
    bool triggered = luaL_optbool(L, 5, true);
    unit->CastSpell(_x, _y, _z, spell, triggered);
    return 0;
}

int LuaUnit::GetAccountId(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    sEluna->PushUnsigned(L, player->GetSession()->GetAccountId());
    return 1;
}

int LuaUnit::GetAccountName(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    std::string accName;
    if (sAccountMgr->GetName(player->GetSession()->GetAccountId(), accName))
        sEluna->PushString(L, accName.c_str());
    else
        return 0;
    return 1;
}

int LuaUnit::GetAITarget(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    SelectAggroTarget targetType = (SelectAggroTarget)luaL_checkunsigned(L, 1);
    bool playerOnly = luaL_optbool(L, 2, false);
    uint32 position = luaL_optunsigned(L, 3, 0);
    float dist = luaL_optnumber(L, 4, 0.0f);
    int32 aura = luaL_optint(L, 5, 0);

    ;
    ThreatContainer::StorageType const& threatlist = creature->getThreatManager().getThreatList();
    if (position >= threatlist.size())
    {
        sEluna->PushUnit(L, NULL);
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
        sEluna->PushUnit(L, NULL);
        return 1;
    }

    if (targetType == SELECT_TARGET_NEAREST || targetType == SELECT_TARGET_FARTHEST)
        targetList.sort(Trinity::ObjectDistanceOrderPred(creature));

    switch (targetType)
    {
    case SELECT_TARGET_NEAREST:
    case SELECT_TARGET_TOPAGGRO:
        {
            std::list<Unit*>::iterator itr = targetList.begin();
            std::advance(itr, position);
            sEluna->PushUnit(L, *itr);
            return 1;
        }
    case SELECT_TARGET_FARTHEST:
    case SELECT_TARGET_BOTTOMAGGRO:
        {
            std::list<Unit*>::reverse_iterator ritr = targetList.rbegin();
            std::advance(ritr, position);
            sEluna->PushUnit(L, *ritr);
            return 1;
        }
    case SELECT_TARGET_RANDOM:
        {
            std::list<Unit*>::iterator itr = targetList.begin();
            std::advance(itr, urand(position, targetList.size() - 1));
            sEluna->PushUnit(L, *itr);
            return 1;
        }
    default:
        break;
    }

    sEluna->PushUnit(L, NULL);
    return 1;
}

int LuaUnit::GetAITargets(lua_State* L, Unit* unit)
{
    TO_CREATURE();

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
        sEluna->PushUnsigned(L, i);
        sEluna->PushUnit(L, target);
        lua_settable(L, tbl);
    }

    lua_settop(L, tbl);
    return 1;
}

int LuaUnit::GetAITargetsCount(lua_State* L, Unit* unit)
{
    TO_CREATURE();

    sEluna->PushUnsigned(L, creature->getThreatManager().getThreatList().size());
    return 1;
}

int LuaUnit::IsDungeonBoss(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->IsDungeonBoss());
    return 1;
}

int LuaUnit::IsWorldBoss(lua_State* L, Unit* unit)
{
    TO_CREATURE_BOOL();

    sEluna->PushBoolean(L, creature->isWorldBoss());
    return 1;
}

int LuaUnit::GetAura(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 spellID = luaL_checkunsigned(L, 1);
    sEluna->PushAura(L, unit->GetAura(spellID));
    return 1;
}

int LuaUnit::GetMapId(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetMapId());
    return 1;
}

int LuaUnit::GetCombatTime(lua_State* L, Unit* unit)
{
    TO_UNIT();

    sEluna->PushUnsigned(L, unit->GetCombatTimer());
    return 1;
}

int LuaUnit::ClearInCombat(lua_State* L, Unit* unit)
{
    TO_UNIT();

    unit->ClearInCombat();
    return 0;
}

int LuaUnit::StopSpellCast(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 spellId = luaL_optunsigned(L, 1, 0);
    unit->CastStop(spellId);
    return 0;
}

int LuaUnit::InterruptSpell(lua_State* L, Unit* unit)
{
    TO_UNIT();

    int spellType = luaL_checkint(L, 1);
    bool delayed = luaL_optbool(L, 2, true);
    bool instant = luaL_optbool(L, 3, true);
    switch (spellType)
    {
    case 0:
        spellType = CURRENT_MELEE_SPELL;
        break;
    case 1:
        spellType = CURRENT_GENERIC_SPELL;
        break;
    case 2:
        spellType = CURRENT_CHANNELED_SPELL;
        break;
    case 3:
        spellType = CURRENT_AUTOREPEAT_SPELL;
        break;
    }
    unit->InterruptSpell((CurrentSpellTypes)spellType, delayed, instant);
    return 0;
}

int LuaUnit::AddAura(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 spellId = luaL_checkunsigned(L, 1);
    Unit* target = sEluna->CHECK_UNIT(L, 2);
    if (!target)
        return 0;
    unit->AddAura(spellId, target);
    return 0;
}

int LuaUnit::RemoveAura(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 spellId = luaL_checkunsigned(L, 1);
    uint64 casterGUID = sEluna->CHECK_ULONG(L, 2);
    unit->RemoveAurasDueToSpell(spellId, casterGUID);
    return 0;
}

int LuaUnit::RemoveAllAuras(lua_State* L, Unit* unit)
{
    TO_UNIT();

    unit->RemoveAllAuras();
    return 0;
}

int LuaUnit::GossipMenuAddItem(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 _icon = luaL_checkunsigned(L, 1);
    const char* msg = luaL_checkstring(L, 2);
    uint32 _sender = luaL_checkunsigned(L, 3);
    uint32 _intid = luaL_checkunsigned(L, 4);
    bool _code = luaL_optbool(L, 5, false);
    const char* _promptMsg = luaL_optstring(L, 6, "");
    uint32 _money = luaL_optunsigned(L, 7, 0);
    player->ADD_GOSSIP_ITEM_EXTENDED(_icon, msg, _sender, _intid, _promptMsg, _money, _code);
    return 0;
}

int LuaUnit::GossipComplete(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->CLOSE_GOSSIP_MENU();
    return 0;
}

int LuaUnit::GossipSendMenu(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 _npcText = luaL_checkunsigned(L, 1);
    WorldObject* sender = sEluna->CHECK_WORLDOBJECT(L, 2);
    if (sender)
    {
        if (sender->ToPlayer())
        {
            uint32 menu_id = luaL_checkunsigned(L, 3);
            player->PlayerTalkClass->GetGossipMenu().SetMenuId(menu_id);
        }
        player->SEND_GOSSIP_MENU(_npcText, sender->GetGUID());
    }
    return 0;
}

int LuaUnit::GossipClearMenu(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    player->PlayerTalkClass->ClearMenus();
    return 0;
}

int LuaUnit::PlaySoundToPlayer(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 soundId = luaL_checkunsigned(L, 1);
    SoundEntriesEntry const* soundEntry = sSoundEntriesStore.LookupEntry(soundId);
    if (!soundEntry)
        return 0;

    player->PlayDirectSound(soundId, player);
    return 0;
}

int LuaUnit::PlayDirectSound(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 soundId = luaL_checkunsigned(L, 1);
    Player* player = sEluna->CHECK_PLAYER(L, 2);
    if (!sSoundEntriesStore.LookupEntry(soundId))
        return 0;

    if (player)
        unit->PlayDirectSound(soundId, player);
    else
        unit->PlayDirectSound(soundId);
    return 0;
}

int LuaUnit::PlayDistanceSound(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 soundId = luaL_checkunsigned(L, 1);
    Player* player = sEluna->CHECK_PLAYER(L, 2);
    if (!sSoundEntriesStore.LookupEntry(soundId))
        return 0;

    if (player)
        unit->PlayDistanceSound(soundId, player);
    else
        unit->PlayDistanceSound(soundId);
    return 0;
}

int LuaUnit::Kill(lua_State* L, Unit* unit)
{
    TO_UNIT();

    Unit* target = sEluna->CHECK_UNIT(L, 1);
    bool durLoss = luaL_optbool(L, 2, true);
    unit->Kill((target ? target : unit), durLoss);
    return 0;
}

int LuaUnit::RegisterEvent(lua_State* L, Unit* unit)
{
    TO_UNIT();

    luaL_checktype(L, 1, LUA_TFUNCTION);
    uint32 delay = luaL_checkunsigned(L, 2);
    uint32 repeats = luaL_checkunsigned(L, 3);

    lua_settop(L, 1);
    int functionRef = lua_ref(L, true);
    unit->m_Events.AddEvent(new Eluna::LuaEventData(functionRef, delay, repeats, unit), unit->m_Events.CalculateTime(delay));
    sEluna->PushInteger(L, functionRef);
    return 1;
}

int LuaUnit::RemoveEventById(lua_State* L, Unit* unit)
{
    TO_UNIT();

    int eventID = luaL_checkinteger(L, 1);
    Eluna::LuaEventData::Remove(unit->GetGUID(), eventID);
    return 0;
}

int LuaUnit::RemoveEvents(lua_State* L, Unit* unit)
{
    TO_UNIT();

    Eluna::LuaEventData::RemoveAll(unit);
    return 0;
}

int LuaUnit::GetInt32Value(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    sEluna->PushInteger(L, unit->GetInt32Value(index));
    return 1;
}

int LuaUnit::GetUInt32Value(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    sEluna->PushUnsigned(L, unit->GetUInt32Value(index));
    return 1;
}

int LuaUnit::GetFloatValue(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    sEluna->PushFloat(L, unit->GetFloatValue(index));
    return 1;
}

int LuaUnit::GetByteValue(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    uint8 offset = luaL_checkunsigned(L, 2);
    sEluna->PushUnsigned(L, unit->GetByteValue(index, offset));
    return 1;
}

int LuaUnit::GetUInt16Value(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    uint8 offset = luaL_checkunsigned(L, 2);
    sEluna->PushUnsigned(L, unit->GetUInt16Value(index, offset));
    return 1;
}

int LuaUnit::SetInt32Value(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    int32 value = luaL_checkinteger(L, 2);
    unit->SetInt32Value(index, value);
    return 0;
}

int LuaUnit::SetUInt32Value(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    uint32 value = luaL_checkunsigned(L, 2);
    unit->SetUInt32Value(index, value);
    return 0;
}

int LuaUnit::UpdateUInt32Value(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    uint32 value = luaL_checkunsigned(L, 2);
    unit->UpdateUInt32Value(index, value);
    return 0;
}

int LuaUnit::SetFloatValue(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    float value = luaL_checknumber(L, 2);

    unit->SetFloatValue(index, value);
    return 0;
}

int LuaUnit::SetByteValue(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    uint8 offset = luaL_checkunsigned(L, 2);
    uint8 value = luaL_checkunsigned(L, 3);
    unit->SetByteValue(index, offset, value);
    return 0;
}

int LuaUnit::SetUInt16Value(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    uint8 offset = luaL_checkunsigned(L, 2);
    uint16 value = luaL_checkunsigned(L, 3);
    unit->SetUInt16Value(index, offset, value);
    return 0;
}

int LuaUnit::SetInt16Value(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint16 index = luaL_checkunsigned(L, 1);
    uint8 offset = luaL_checkunsigned(L, 2);
    int16 value = luaL_checkinteger(L, 3);
    unit->SetInt16Value(index, offset, value);
    return 0;
}

/* Vehicle */

int LuaUnit::IsOnVehicle(lua_State* L, Unit* unit)
{
    TO_UNIT();

    if (unit->GetVehicle() || (unit->ToPlayer() && unit->IsVehicle()))
        sEluna->PushBoolean(L, true);
    else
        sEluna->PushBoolean(L, false);
    return 1;
}

int LuaUnit::DismissVehicle(lua_State* L, Unit* unit)
{
    TO_UNIT();

    if (Creature* vehicle = unit->GetVehicleCreatureBase())
        vehicle->DespawnOrUnsummon();
    return 0;
}

int LuaUnit::AddVehiclePassenger(lua_State* L, Unit* unit)
{
    TO_UNIT();

    Unit* passenger = sEluna->CHECK_UNIT(L, 1);
    int8 seatId = luaL_checkunsigned(L, 2);
    Vehicle* _vehicle = unit->GetVehicle();
    if (!_vehicle)
        return 0;

    _vehicle->AddPassenger(passenger, seatId);
    return 0;
}

/* Not coded in core
int LuaUnit::EjectPassenger(lua_State* L, Unit* unit)
{
TO_UNIT();

Unit* passenger = sEluna->CHECK_UNIT(L, 1);
Vehicle* _vehicle = unit->GetVehicle();
if (!_vehicle)
return 0;

_vehicle->EjectPassenger(passenger, unit);
return 0;
}
*/

int LuaUnit::RemovePassenger(lua_State* L, Unit* unit)
{
    TO_UNIT();

    Unit* passenger = sEluna->CHECK_UNIT(L, 1);
    Vehicle* _vehicle = unit->GetVehicle();
    if (!_vehicle)
        return 0;

    _vehicle->RemovePassenger(passenger);
    return 0;
}

int LuaUnit::RemoveAllPassengers(lua_State* L, Unit* unit)
{
    TO_UNIT();

    Unit* _unit = unit->GetVehicleBase();
    if (!_unit)
        return 0;

    _unit->GetVehicle()->RemoveAllPassengers();
    return 0;
}

int LuaUnit::GetPassenger(lua_State* L, Unit* unit)
{
    TO_UNIT();

    int8 seatId = luaL_checkunsigned(L, 1);
    Unit* _unit = unit->GetVehicleBase();
    if (!_unit)
        return 0;

    sEluna->PushUnit(L, _unit->GetVehicle()->GetPassenger(seatId));
    return 1;
}

int LuaUnit::GetNextEmptySeat(lua_State* L, Unit* unit)
{
    TO_UNIT();

    int8 seatId = luaL_checkunsigned(L, 1);
    Unit* _unit = unit->GetVehicleBase();
    if (!_unit)
        return 0;

    return 0;
}

int LuaUnit::GetAvailableSeats(lua_State* L, Unit* unit)
{
    TO_UNIT();

    Unit* _unit = unit->GetVehicleBase();
    if (!_unit)
        return 0;

    sEluna->PushUnsigned(L, _unit->GetVehicle()->GetAvailableSeatCount());
    return 1;
}

int LuaUnit::GetVehicleBase(lua_State* L, Unit* unit)
{
    TO_UNIT();

    Unit* _unit = unit->GetVehicleBase();
    if (_unit)
        sEluna->PushUnit(L, _unit);
    else
        lua_pushnil(L);
    return 1;
}

int LuaUnit::HasEmptySeat(lua_State* L, Unit* unit)
{
    TO_UNIT();

    int8 seatId = luaL_checkunsigned(L, 1);
    Unit* _unit = unit->GetVehicleBase();
    if (!_unit)
        return 0;

    sEluna->PushBoolean(L, _unit->GetVehicle()->HasEmptySeat(seatId));
    return 1;
}

int LuaUnit::StartTaxi(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    uint32 pathId = luaL_checkunsigned(L, 1);

    LuaTaxiMgr::StartTaxi(player, pathId);
    return 0;
}

int LuaUnit::SetPlayerLock(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    bool apply = luaL_optbool(L, 1, true);

    if (apply)
    {
        player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_SILENCED);
        player->SetClientControl(player, 0);
    }
    else
    {
        player->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_SILENCED);
        player->SetClientControl(player, 1);
    }
    return 0;
}

int LuaUnit::GetNearestPlayer(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float distance = luaL_optnumber(L, 1, SIZE_OF_GRIDS);

    Player* target = NULL;
    Eluna::NearestTypeWithEntryInRangeCheck checker(unit, distance, TYPEID_PLAYER);
    Trinity::PlayerLastSearcher<Eluna::NearestTypeWithEntryInRangeCheck> searcher(unit, target, checker);
    unit->VisitNearbyObject(distance, searcher);

    sEluna->PushUnit(L, target);
    return 1;
}

int LuaUnit::GetNearestGameObject(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);
    uint32 entry = luaL_optunsigned(L, 2, 0);

    GameObject* target = NULL;
    Eluna::NearestTypeWithEntryInRangeCheck checker(unit, range, TYPEID_GAMEOBJECT, entry);
    Trinity::GameObjectLastSearcher<Eluna::NearestTypeWithEntryInRangeCheck> searcher(unit, target, checker);
    unit->VisitNearbyGridObject(range, searcher);

    sEluna->PushGO(L, target);
    return 1;
}

int LuaUnit::GetNearestCreature(lua_State* L, Unit* unit)
{
    TO_UNIT();

    float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);
    uint32 entry = luaL_optunsigned(L, 2, 0);

    Creature* target = NULL;
    Eluna::NearestTypeWithEntryInRangeCheck checker(unit, range, TYPEID_UNIT, entry);
    Trinity::CreatureLastSearcher<Eluna::NearestTypeWithEntryInRangeCheck> searcher(unit, target, checker);
    unit->VisitNearbyGridObject(range, searcher);

    sEluna->PushUnit(L, target);
    return 1;
}

int LuaUnit::GetFriendlyUnitsInRange(lua_State* L, Unit* unit)
{
    TO_UNIT();
    float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);

    UnitList list;
    Trinity::AnyFriendlyUnitInObjectRangeCheck checker(unit, unit, range);
    Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(unit, list, checker);
    unit->VisitNearbyGridObject(range, searcher);

    lua_newtable(L);
    int tbl = lua_gettop(L);
    uint32 i = 0;

    for (UnitList::iterator it = list.begin(); it != list.end(); ++it)
    {
        sEluna->PushUnsigned(L, ++i);
        sEluna->PushUnit(L, *it);
        lua_settable(L, tbl);
    }

    lua_settop(L, tbl);
    return 1;
}

int LuaUnit::GetUnfriendlyUnitsInRange(lua_State* L, Unit* unit)
{
    TO_UNIT();
    float range = luaL_optnumber(L, 1, SIZE_OF_GRIDS);

    UnitList list;
    Trinity::AnyUnfriendlyUnitInObjectRangeCheck checker(unit, unit, range);
    Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(unit, list, checker);
    unit->VisitNearbyGridObject(range, searcher);

    lua_newtable(L);
    int tbl = lua_gettop(L);
    uint32 i = 0;

    for (UnitList::iterator it = list.begin(); it != list.end(); ++it)
    {
        sEluna->PushUnsigned(L, ++i);
        sEluna->PushUnit(L, *it);
        lua_settable(L, tbl);
    }

    lua_settop(L, tbl);
    return 1;
}

int LuaUnit::GossipSendPOI(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    float x = luaL_checknumber(L, 1);
    float y = luaL_checknumber(L, 2);
    uint32 icon = luaL_checkunsigned(L, 3);
    uint32 flags = luaL_checkunsigned(L, 4);
    uint32 data = luaL_checkunsigned(L, 5);
    std::string iconText = luaL_checkstring(L, 6);

    WorldPacket packet(SMSG_GOSSIP_POI, 4 + 4 + 4 + 4 + 4 + 10);
    packet << flags;
    packet << x;
    packet << y;
    packet << icon;
    packet << data;
    packet << iconText;
    player->GetSession()->SendPacket(&packet);
    return 0;
}

int LuaUnit::GossipAddQuests(lua_State* L, Unit* unit)
{
    TO_PLAYER();

    WorldObject* source = sEluna->CHECK_WORLDOBJECT(L, 1);
    if (!source)
        return 0;

    if (source->GetTypeId() == TYPEID_UNIT)
    {
        if (source->GetUInt32Value(UNIT_NPC_FLAGS) & UNIT_NPC_FLAG_QUESTGIVER)
            player->PrepareQuestMenu(source->GetGUID());
    }
    else if (source->GetTypeId() == TYPEID_GAMEOBJECT)
    {
        if (source->ToGameObject()->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
            player->PrepareQuestMenu(source->GetGUID());
    }
    return 0;
}

int LuaUnit::AttackStop(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->AttackStop());
    return 1;
}

int LuaUnit::SetCanFly(lua_State* L, Unit* unit)
{
    TO_UNIT();

    bool apply = luaL_optbool(L, 1, true);
    unit->SetCanFly(apply);
    return 0;
}

int LuaUnit::SetVisible(lua_State* L, Unit* unit)
{
    TO_UNIT();

    bool x = luaL_optbool(L, 1, true);
    unit->SetVisible(x);
    return 0;
}

int LuaUnit::IsVisible(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsVisible());
    return 1;
}

int LuaUnit::IsMoving(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->isMoving());
    return 1;
}

int LuaUnit::IsFlying(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsFlying());
    return 1;
}

int LuaUnit::IsStopped(lua_State* L, Unit* unit)
{
    TO_UNIT_BOOL();

    sEluna->PushBoolean(L, unit->IsStopped());
    return 1;
}

int LuaUnit::RestoreDisplayId(lua_State* L, Unit* unit)
{
    TO_UNIT();

    unit->RestoreDisplayId();
    return 0;
}

int LuaUnit::RestoreFaction(lua_State* L, Unit* unit)
{
    TO_UNIT();

    unit->RestoreFaction();
    return 0;
}

int LuaUnit::RemoveBindSightAuras(lua_State* L, Unit* unit)
{
    TO_UNIT();

    unit->RemoveBindSightAuras();
    return 0;
}

int LuaUnit::RemoveCharmAuras(lua_State* L, Unit* unit)
{
    TO_UNIT();

    unit->RemoveCharmAuras();
    return 0;
}

int LuaUnit::StopMoving(lua_State* L, Unit* unit)
{
    TO_UNIT();

    unit->StopMoving();
    return 0;
}

int LuaUnit::AddUnitState(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 state = luaL_checkunsigned(L, 1);

    unit->AddUnitState(state);
    return 0;
}

int LuaUnit::ClearUnitState(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 state = luaL_checkunsigned(L, 1);

    unit->ClearUnitState(state);
    return 0;
}

int LuaUnit::HasUnitState(lua_State* L, Unit* unit)
{
    TO_UNIT();

    uint32 state = luaL_checkunsigned(L, 1);

    sEluna->PushBoolean(L, unit->HasUnitState(state));
    return 1;
}

int LuaUnit::DisableMelee(lua_State* L, Unit* unit)
{
    TO_UNIT();

    bool apply = luaL_optbool(L, 1, true);

    if (apply)
        unit->AddUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
    else
        unit->ClearUnitState(UNIT_STATE_CANNOT_AUTOATTACK);
    return 0;
}
