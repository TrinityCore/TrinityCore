#ifndef UNITMETHODS_H
#define UNITMETHODS_H

#define TO_PLAYER()  Player* player; if (!unit || !unit->IsInWorld() || !(player = unit->ToPlayer()))     { return 0; } else (void)0;
#define TO_CREATURE()  Creature* creature; if (!unit || !unit->IsInWorld() || !(creature = unit->ToCreature())) { return 0; } else (void)0;
#define TO_UNIT()  if (!unit || !unit->IsInWorld() || !unit->ToUnit())  { return 0; } else (void)0;

#define TO_PLAYER_BOOL()  Player* player;  if (!unit || !unit->IsInWorld() || !(player = unit->ToPlayer()))     { sEluna->PushBoolean(L, false); return 1; } else (void)0;
#define TO_CREATURE_BOOL()  Creature* creature; if (!unit || !unit->IsInWorld() || !(creature = unit->ToCreature())) { sEluna->PushBoolean(L, false); return 1; } else (void)0;
#define TO_UNIT_BOOL() if (!unit || !unit->IsInWorld() || !unit->ToUnit()) { sEluna->PushBoolean(L, false); return 1; } else (void)0;

class LuaUnit
{
public:

    // GetManaBonusFromIntellect()
    static int GetManaBonusFromIntellect(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushFloat(L, player->GetManaBonusFromIntellect());
        return 1;
    }

    // GetHealthBonusFromStamina()
    static int GetHealthBonusFromStamina(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushFloat(L, player->GetHealthBonusFromStamina());
        return 1;
    }

    // GetDifficulty(isRaid)
    static int GetDifficulty(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        bool isRaid = luaL_checkbool(L, 1);

        sEluna->PushUnsigned(L, player->GetDifficulty(isRaid));
        return 1;
    }

    // GetGuildRank()
    static int GetRank(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetRank());
        return 1;
    }

    // SetGuildRank(rank)
    static int SetRank(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint8 rank = luaL_checkunsigned(L, 1);
        
        if(!player->GetGuild())
            return 0;

        player->SetRank(rank);
        return 0;
    }

    // RemoveFromGroup()
    static int RemoveFromGroup(lua_State* L, Unit* unit)
    {
        TO_PLAYER();
        
        if(!player->GetGroup())
            return 0;

        player->RemoveFromGroup();
        return 0;
    }

    // IsGroupVisibleFor(player)
    static int IsGroupVisibleFor(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();
        
        Player* target = sEluna->CHECK_PLAYER(L, 1);
        if(!target)
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, player->IsGroupVisibleFor(target));
        return 1;
    }

    // IsInSameRaidWith(player)
    static int IsInSameRaidWith(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();
        
        Player* target = sEluna->CHECK_PLAYER(L, 1);
        if(!target)
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, player->IsInSameRaidWith(target));
        return 1;
    }

    // IsInSameGroupWith(player)
    static int IsInSameGroupWith(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();
        
        Player* target = sEluna->CHECK_PLAYER(L, 1);
        if(!target)
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, player->IsInSameGroupWith(target));
        return 1;
    }

    // SetPvP(apply)
    static int SetPvP(lua_State* L, Unit* unit)
    {
        TO_PLAYER();
        
        bool apply = luaL_optbool(L, 1, true);

        player->SetPvP(apply);
        return 0;
    }

    // GetSpellCooldownDelay(spellid)
    static int GetSpellCooldownDelay(lua_State* L, Unit* unit)
    {
        TO_PLAYER();
        
        uint32 spellId = luaL_checkunsigned(L, 1);

        sEluna->PushUnsigned(L, player->GetSpellCooldownDelay(spellId));
        return 1;
    }

    // HasSpellCooldown(spellid)
    static int HasSpellCooldown(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();
        
        uint32 spellId = luaL_checkunsigned(L, 1);

        sEluna->PushBoolean(L, player->HasSpellCooldown(spellId));
        return 1;
    }

    // GetSpecsCount()
    static int GetSpecsCount(lua_State* L, Unit* unit)
    {
        TO_PLAYER();
        
        sEluna->PushUnsigned(L, player->GetSpecsCount());
        return 1;
    }

    // GetActiveSpec()
    static int GetActiveSpec(lua_State* L, Unit* unit)
    {
        TO_PLAYER();
        
        sEluna->PushUnsigned(L, player->GetActiveSpec());
        return 1;
    }

    // HasTalent(spellid, spec)
    static int HasTalent(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();
        
        uint32 spellId = luaL_checkunsigned(L, 1);
        uint8 spec = luaL_checkunsigned(L, 2);
        if(spec >= MAX_TALENT_SPECS)
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, player->HasTalent(spellId, spec));
        return 1;
    }

    // AddTalent(spellid, spec, learning)
    static int AddTalent(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();
        
        uint32 spellId = luaL_checkunsigned(L, 1);
        uint8 spec = luaL_checkunsigned(L, 2);
        bool learning = luaL_checkbool(L, 3);
        if(spec >= MAX_TALENT_SPECS)
            sEluna->PushBoolean(L, false);
        else
            sEluna->PushBoolean(L, player->AddTalent(spellId, spec, learning));
        return 1;
    }

    // resetTalentsCost()
    static int resetTalentsCost(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->resetTalentsCost());
        return 1;
    }

    // resetTalents([no_cost])
    static int resetTalents(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        bool no_cost = luaL_optbool(L, 1, false);

        player->resetTalents(no_cost);
        return 0;
    }

    // SetFreeTalentPoints(points)
    static int SetFreeTalentPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 points = luaL_checkunsigned(L, 1);

        player->SetFreeTalentPoints(points);
        return 0;
    }

    // GetFreeTalentPoints()
    static int GetFreeTalentPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetFreeTalentPoints());
        return 1;
    }

    // GetGuildName()
    static int GetGuildName(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        if(!player->GetGuildId())
            return 0;
        sEluna->PushString(L, player->GetGuildName().c_str());
        return 1;
    }

    // GetReputation(entry)
    static int GetReputation(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);

        sEluna->PushUnsigned(L, player->GetReputation(entry));
        return 1;
    }

    // SetReputation(faction, value)
    static int SetReputation(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 faction = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);

        player->SetReputation(faction, value);
        return 0;
    }

    // removeSpell(entry[, disabled, learn_low_rank])
    static int removeSpell(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);
        bool disabled = luaL_optbool(L, 2, false);
        bool learn_low_rank = luaL_optbool(L, 3, true);

        player->removeSpell(entry, disabled, learn_low_rank);
        return 0;
    }

    // ClearComboPoints()
    static int ClearComboPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->ClearComboPoints();
        return 0;
    }

    // GainSpellComboPoints(count)
    static int GainSpellComboPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        int8 count = luaL_checkinteger(L, 1);

        player->GainSpellComboPoints(count);
        return 0;
    }

    // AddComboPoints(target, count[, spell])
    static int AddComboPoints(lua_State* L, Unit* unit)
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

    // GetComboTarget()
    static int GetComboTarget(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnit(L, sObjectAccessor->FindUnit(player->GetComboTarget()));
        return 1;
    }

    // GetComboPoints()
    static int GetComboPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetComboPoints());
        return 1;
    }

    // IsQuestRewarded()
    static int IsQuestRewarded(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 entry = luaL_checkunsigned(L, 1);

        sEluna->PushBoolean(L, player->IsQuestRewarded(entry));
        return 1;
    }

    // RegenerateHealth()
    static int RegenerateHealth(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->RegenerateHealth();
        return 0;
    }

    // Regenerate(powerType)
    static int Regenerate(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 power = luaL_checkunsigned(L, 1);
        if(power >= MAX_POWERS)
            return 0;

        player->Regenerate((Powers)power);
        return 0;
    }

    // RegenerateAll()
    static int RegenerateAll(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->RegenerateAll();
        return 0;
    }

    // ResetPetTalents()
    static int ResetPetTalents(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->ResetPetTalents();
        return 0;
    }

    // SaveToDB()
    static int SaveToDB(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->SaveToDB();
        return 0;
    }

    // GetInGameTime()
    static int GetInGameTime(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetInGameTime());
        return 1;
    }

    // SendQuestTimerFailed(entry)
    static int SendQuestTimerFailed(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);

        player->SendQuestTimerFailed(entry);
        return 0;
    }

    // SendQuestFailed(entry)
    static int SendQuestFailed(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);

        player->SendQuestFailed(entry);
        return 0;
    }

    // SendQuestReward(quest, xp)
    static int SendQuestReward(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Quest* quest = sEluna->CHECK_QUEST(L, 1);
        uint32 xp = luaL_checkunsigned(L, 2);

        player->SendQuestReward(quest, xp);
        return 0;
    }

    // SendQuestComplete(entry)
    static int SendQuestComplete(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);

        player->SendQuestComplete(entry);
        return 0;
    }

    // TalkedToCreature(npcEntry, creature)
    static int TalkedToCreature(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);
        Creature* creature = sEluna->CHECK_CREATURE(L, 2);
        if(!creature)
            return 0;

        player->TalkedToCreature(entry, creature->GetGUID());
        return 0;
    }

    // CastedCreatureOrGO(creatureOrGOEntry, creatureOrGO, spellId)
    static int CastedCreatureOrGO(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);
        Unit* creaOrGo = sEluna->CHECK_UNIT(L, 2);
        uint32 spellId = luaL_checkunsigned(L, 3);
        if(!creaOrGo || !creaOrGo->ToGameObject() || !creaOrGo->ToCreature())
            return 0;

        player->CastedCreatureOrGO(entry, creaOrGo->GetGUID(), spellId);
        return 0;
    }

    // KilledPlayerCredit()
    static int KilledPlayerCredit(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->KilledPlayerCredit();
        return 0;
    }

    // KilledMonsterCredit(entry)
    static int KilledMonsterCredit(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);

        player->KilledMonsterCredit(entry, 0);
        return 0;
    }

    // ItemRemovedQuestCheck(questId, count)
    static int ItemRemovedQuestCheck(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 questId = luaL_checkunsigned(L, 1);
        uint32 count = luaL_checkunsigned(L, 2);

        player->ItemRemovedQuestCheck(questId, count);
        return 0;
    }

    // ItemAddedQuestCheck(questId, count)
    static int ItemAddedQuestCheck(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 questId = luaL_checkunsigned(L, 1);
        uint32 count = luaL_checkunsigned(L, 2);

        player->ItemAddedQuestCheck(questId, count);
        return 0;
    }

    // GroupEventHappens(questId, WorldObject)
    static int GroupEventHappens(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 questId = luaL_checkunsigned(L, 1);
        WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 1);
        if(!obj)
            return 0;

        player->GroupEventHappens(questId, obj);
        return 0;
    }

    // AreaExploredOrEventHappens(questId)
    static int AreaExploredOrEventHappens(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 questId = luaL_checkunsigned(L, 1);

        player->AreaExploredOrEventHappens(questId);
        return 0;
    }

    // CanShareQuest(entry)
    static int CanShareQuest(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 entry = luaL_checkunsigned(L, 1);

        sEluna->PushBoolean(L, player->CanShareQuest(entry));
        return 1;
    }

    // HasQuestForGO(entry)
    static int HasQuestForGO(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        int32 entry = luaL_checkinteger(L, 1);

        sEluna->PushBoolean(L, player->HasQuestForGO(entry));
        return 1;
    }

    // HasQuestForItem(entry)
    static int HasQuestForItem(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 entry = luaL_checkunsigned(L, 1);

        sEluna->PushBoolean(L, player->HasQuestForItem(entry));
        return 1;
    }

    // GetReqKillOrCastCurrentCount(questId, entry)
    static int GetReqKillOrCastCurrentCount(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 questId = luaL_checkunsigned(L, 1);
        int32 entry = luaL_checkinteger(L, 2);

        sEluna->PushUnsigned(L, player->GetReqKillOrCastCurrentCount(questId, entry));
        return 1;
    }

    // RemoveRewardedQuest(entry)
    static int RemoveRewardedQuest(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);

        player->RemoveRewardedQuest(entry);
        return 0;
    }

    // RemoveActiveQuest(entry)
    static int RemoveActiveQuest(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);

        player->RemoveActiveQuest(entry);
        return 0;
    }

    // SetQuestStatus(entry, queststatus)
    static int SetQuestStatus(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);
        uint32 status = luaL_checkunsigned(L, 2);
        if(status >= MAX_QUEST_STATUS)
            return 0;

        player->SetQuestStatus(entry, (QuestStatus)status);
        return 0;
    }

    // GetQuestStatus(entry)
    static int GetQuestStatus(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);

        sEluna->PushInteger(L, player->GetQuestStatus(entry));
        return 1;
    }

    // FailQuest(entry)
    static int RewardQuest(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);

        player->FailQuest(entry);
        return 0;
    }

    // IncompleteQuest(entry)
    static int IncompleteQuest(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);

        player->IncompleteQuest(entry);
        return 0;
    }

    // CompleteQuest(entry)
    static int CompleteQuest(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);

        player->CompleteQuest(entry);
        return 0;
    }

    // IsActiveQuest(entry)
    static int IsActiveQuest(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 entry = luaL_checkunsigned(L, 1);

        sEluna->PushBoolean(L, player->IsActiveQuest(entry));
        return 1;
    }

    // GetQuestLevel(quest)
    static int GetQuestLevel(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Quest* quest = sEluna->CHECK_QUEST(L, 1);
        if(!quest)
            return 0;

        sEluna->PushInteger(L, player->GetQuestLevel(quest));
        return 1;
    }

    // GetItemByEntry(entry)
    static int GetItemByEntry(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 entry = luaL_checkunsigned(L, 1);

        sEluna->PushItem(L, player->GetItemByEntry(entry));
        return 1;
    }

    // SetSheath(SheathState)
    static int SetSheath(lua_State* L, Unit* unit)
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

    // Whisper(text, lang, receiverGuid)
    static int Whisper(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        std::string text = luaL_checkstring(L, 1);
        uint32 lang = luaL_checkunsigned(L, 2);
        uint32 guidLow = luaL_checkunsigned(L, 3);

        player->Whisper(text, lang, MAKE_NEW_GUID(guidLow, 0, HIGHGUID_PLAYER));
        return 0;
    }

    // TextEmote(text)
    static int TextEmote(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        std::string text = luaL_checkstring(L, 1);

        player->TextEmote(text);
        return 0;
    }

    // Yell(text, lang)
    static int Yell(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        std::string text = luaL_checkstring(L, 1);
        uint32 lang = luaL_checkunsigned(L, 2);

        player->Yell(text, lang);
        return 0;
    }

    // Say(text, lang)
    static int Say(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        std::string text = luaL_checkstring(L, 1);
        uint32 lang = luaL_checkunsigned(L, 2);

        player->Say(text, lang);
        return 0;
    }

    // GetPhaseMaskForSpawn([mode, returnreagent])
    static int GetPhaseMaskForSpawn(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetPhaseMaskForSpawn());
        return 1;
    }

    // SummonPet(entry, x, y, z, o, petType, despwtime)
    static int SummonPet(lua_State* L, Unit* unit)
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

    // RemovePet([mode, returnreagent])
    static int RemovePet(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        int mode = luaL_optint(L, 1, PET_SAVE_AS_DELETED);
        bool returnreagent = luaL_optbool(L, 1, false);

        if (!player->GetPet())
            return 0;

        player->RemovePet(player->GetPet(), (PetSaveMode)mode, returnreagent);
        return 0;
    }

    // GetRestType()
    static int GetRestType(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushInteger(L, player->GetRestType());
        return 1;
    }

    // SetRestType(type)
    static int SetRestType(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        int type = luaL_checkinteger(L, 1);

        player->SetRestType((RestType)type);
        return 0;
    }

    // SetRestBonus(bonusrate)
    static int SetRestBonus(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        float bonus = luaL_checknumber(L, 1);

        player->SetRestBonus(bonus);
        return 0;
    }

    // GetRestBonus()
    static int GetRestBonus(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushFloat(L, player->GetRestBonus());
        return 1;
    }

    // GiveLevel(level)
    static int GiveLevel(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint8 level = luaL_checkunsigned(L, 1);

        player->GiveLevel(level);
        return 0;
    }

    // GiveXP(xp[, victim[, group_rate]])
    static int GiveXP(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 xp = luaL_checkunsigned(L, 1);
        Unit* victim = sEluna->CHECK_UNIT(L, 2);
        float group_rate = luaL_optnumber(L, 3, 1.0f);

        player->GiveXP(xp, victim, group_rate);
        return 0;
    }

    // isGMVisible()
    static int isGMVisible(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        sEluna->PushBoolean(L, player->isGMVisible());
        return 1;
    }

    // isTaxiCheater()
    static int isTaxiCheater(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        sEluna->PushBoolean(L, player->isTaxiCheater());
        return 1;
    }

    // isGMChat()
    static int isGMChat(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        sEluna->PushBoolean(L, player->isGMChat());
        return 1;
    }

    // isAcceptWhispers()
    static int isAcceptWhispers(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        sEluna->PushBoolean(L, player->isAcceptWhispers());
        return 1;
    }

    // SetAcceptWhispers(on)
    static int SetAcceptWhispers(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        bool on = luaL_checkbool(L, 1);

        player->SetAcceptWhispers(on);
        return 0;
    }

    // SetPvPDeath(on)
    static int SetPvPDeath(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        bool on = luaL_checkbool(L, 1);

        player->SetPvPDeath(on);
        return 0;
    }

    // SetGMVisible(on)
    static int SetGMVisible(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        bool on = luaL_checkbool(L, 1);

        player->SetGMVisible(on);
        return 0;
    }

    // SetTaxiCheater(on)
    static int SetTaxiCheater(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        bool on = luaL_checkbool(L, 1);

        player->SetTaxiCheater(on);
        return 0;
    }

    // SetGMChat(on)
    static int SetGMChat(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        bool on = luaL_checkbool(L, 1);

        player->SetGMChat(on);
        return 0;
    }

    // SetGameMaster(on)
    static int SetGameMaster(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        bool on = luaL_checkbool(L, 1);

        player->SetGameMaster(on);
        return 0;
    }

    // GetChatTag()
    static int GetChatTag(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetChatTag());
        return 1;
    }

    // isDND()
    static int isDND(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        sEluna->PushBoolean(L, player->isDND());
        return 1;
    }

    // isAFK()
    static int isAFK(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        sEluna->PushBoolean(L, player->isAFK());
        return 1;
    }

    // ToggleDND()
    static int ToggleDND(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->ToggleDND();
        return 0;
    }

    // ToggleAFK()
    static int ToggleAFK(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->ToggleAFK();
        return 0;
    }

    // IsFalling()
    static int IsFalling(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        sEluna->PushBoolean(L, player->IsFalling());
        return 1;
    }

    // IsUnderWater()
    static int IsUnderWater(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        sEluna->PushBoolean(L, unit->IsUnderWater());
        return 1;
    }

    // IsInWater()
    static int IsInWater(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        sEluna->PushBoolean(L, unit->IsInWater());
        return 1;
    }

    // GetVictim()
    static int GetVictim(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        sEluna->PushUnit(L, creature->SelectVictim());
        return 1;
    }

    // GetNearestTargetInAttackDistance([radius])
    static int GetNearestTargetInAttackDistance(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        float dist = luaL_optnumber(L, 1, 0.0f);
        sEluna->PushUnit(L, creature->SelectNearestTargetInAttackDistance(dist));
        return 1;
    }

    // GetNearestTarget([radius])
    static int GetNearestTarget(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        float dist = luaL_optnumber(L, 1, 0.0f);
        sEluna->PushUnit(L, creature->SelectNearestTarget(dist));
        return 1;
    }

    // GetNearestPlayer([radius])
    static int GetNearestPlayer(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        float dist = luaL_optnumber(L, 1, 0.0f);
        sEluna->PushUnit(L, creature->SelectNearestPlayer(dist));
        return 1;
    }

    // GetNearestHostileTargetInAggroRange([checkLOS])
    static int GetNearestHostileUnitInAggroRange(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        bool checkLOS = luaL_optbool(L, 1, false);
        sEluna->PushUnit(L, creature->SelectNearestHostileUnitInAggroRange(checkLOS));
        return 1;
    }

    // GetNearbyTarget([radius[, exclude]])
    static int GetNearbyTarget(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float dist = luaL_optnumber(L, 1, 5.0f);
        Unit* exclude = sEluna->CHECK_UNIT(L, 2);

        sEluna->PushUnit(L, unit->SelectNearbyTarget(exclude, dist));
        return 1;
    }

    // GetObjectGlobally(guid, entry)
    static int GetObjectGlobally(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 guidLow = luaL_checkunsigned(L, 1);
        uint32 entry = luaL_checkunsigned(L, 2);

        sEluna->PushGO(L, ChatHandler(player->GetSession()).GetObjectGlobalyWithGuidOrNearWithDbGuid(guidLow, entry));
        return 1;
    }

    // GetNearestGameObject()
    static int GetNearbyGameObject(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushGO(L, ChatHandler(player->GetSession()).GetNearbyGameObject());
        return 1;
    }

    // SendChatMessageToPlayer(type, lang, msg, target)
    static int SendChatMessageToPlayer(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint8 type = luaL_checkunsigned(L, 1);
        uint32 lang = luaL_checkunsigned(L, 2);
        const char* msg = luaL_checkstring(L, 3);
        Player* target = sEluna->CHECK_PLAYER(L, 4);
        if (!target || type == CHAT_MSG_CHANNEL)
            return 0;

        WorldPacket* data =  new WorldPacket(); // Needs a custom built packet since TC doesnt set guids in some cases
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

    //GetCurrentSpell(type)
    static int GetCurrentSpell(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 type = luaL_checkunsigned(L, 1);
        if (type >= CURRENT_MAX_SPELL)
        {
            sLog->outError(LOG_FILTER_GENERAL, "Eluna::Invalid spell type (%u) for GetCurrentSpell", type);
            return 0;
        }
        sEluna->PushSpell(L, unit->GetCurrentSpell(type));
        return 1;
    }

    //EquipItem(entry/item, slot)
    static int EquipItem(lua_State* L, Unit* unit)
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

    //CanEquipItem(entry/item, slot)
    static int CanEquipItem(lua_State* L, Unit* unit)
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

    //GetInventoryItem(slot)
    static int GetInventoryItem(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint8 slot = luaL_checkunsigned(L, 1);
        if (slot >= INVENTORY_SLOT_ITEM_END)
            return 0;

        Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
        sEluna->PushItem(L, item);
        return 1;
    }

    //GetBagItem(bagslot, slot)
    static int GetBagItem(lua_State* L, Unit* unit)
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

    //SpawnGameObject(entry, x, y, z, o[, respawnDelay])
    static int SummonGameObject(lua_State* L, Unit* unit)
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

    //SpawnCreature(entry, x, y, z, o[, despawnDelay])
    static int SpawnCreature(lua_State* L, Unit* unit)
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

    //Despawn([despawnDelay])
    static int Despawn(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        uint32 time = luaL_optunsigned(L, 1, 0);
        creature->DespawnOrUnsummon(time);
        return 0;
    }

    //GetArenaPoints()
    static int GetArenaPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetArenaPoints());
        return 1;
    }

    //KnockbackFrom()
    static int KnockbackFrom(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        float speedXY = luaL_checknumber(L, 3);
        float speedZ = luaL_checknumber(L, 4);
        unit->KnockbackFrom(x, y, speedXY, speedZ);
        return 0;
    }

    //JumpTo(WorldObj, speedZ)
    static int JumpTo(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        WorldObject* obj = sEluna->CHECK_WORLDOBJECT(L, 1);
        float speedZ = luaL_checknumber(L, 2);
        if (!obj)
            return 0;

        unit->JumpTo(obj, speedZ);
        return 0;
    }

    //Jump(speedXY, speedZ[, forward])
    static int Jump(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float speedXY = luaL_checknumber(L, 1);
        float speedZ = luaL_checknumber(L, 2);
        bool forward = luaL_optbool(L, 3, true);
        unit->JumpTo(speedXY, speedZ, forward);
        return 0;
    }

    //JumpToCoords(x, y, z, speedXY, speedZ)
    static int JumpToCoords(lua_State* L, Unit* unit)
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

    //MoveCharge(x, y, z, speed)
    static int MoveCharge(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float x = luaL_checknumber(L, 1);
        float y = luaL_checknumber(L, 2);
        float z = luaL_checknumber(L, 3);
        float speed = luaL_checknumber(L, 4);
        unit->GetMotionMaster()->MoveCharge(x, y, z, speed);
        return 0;
    }

    //MoveChase(target[, dist, angle])
    static int MoveChase(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* target = sEluna->CHECK_UNIT(L, 1);
        float dist = luaL_optnumber(L, 2, 0.0f);
        float angle = luaL_optnumber(L, 3, 0.0f);
        unit->GetMotionMaster()->MoveChase(target, dist, angle);
        return 0;
    }

    //SetStunned(apply)
    static int SetStunned(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        bool apply = luaL_optbool(L, 1, true);
        unit->SetControlled(apply, UNIT_STATE_STUNNED);
        return 0;
    }

    //SetRooted(apply)
    static int SetRooted(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        bool apply = luaL_optbool(L, 1, true);
        unit->SetControlled(apply, UNIT_STATE_ROOT);
        return 0;
    }

    //SetConfused(apply)
    static int SetConfused(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        bool apply = luaL_optbool(L, 1, true);
        unit->SetControlled(apply, UNIT_STATE_CONFUSED);
        return 0;
    }

    //SetFeared(apply)
    static int SetFeared(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        bool apply = luaL_optbool(L, 1, true);
        unit->SetControlled(apply, UNIT_STATE_FLEEING);
        return 0;
    }

    //MoveTo(id, x, y, z[, generatePath])
    static int MovePoint(lua_State* L, Unit* unit)
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

    //MoveFollow(target, dist, angle)
    static int MoveFollow(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* target = sEluna->CHECK_UNIT(L, 1);
        float dist = luaL_checknumber(L, 2);
        float angle = luaL_checknumber(L, 3);
        unit->GetMotionMaster()->MoveFollow(target, dist, angle);
        return 0;
    }

    //MoveClear()
    static int MoveClear(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        unit->GetMotionMaster()->Clear();
        return 0;
    }

    //MoveRandom(radius)
    static int MoveRandom(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float radius = luaL_checknumber(L, 1);
        unit->GetMotionMaster()->MoveRandom(radius);
        return 0;
    }

    //MoveRotate(time, left)
    static int MoveRotate(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 time = luaL_checkunsigned(L, 1);
        bool left = luaL_optbool(L, 2, true);
        unit->GetMotionMaster()->MoveRotate(time, left ? ROTATE_DIRECTION_LEFT : ROTATE_DIRECTION_RIGHT);
        return 0;
    }

    //SetWalk(enable)
    static int SetWalk(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        bool enable = luaL_optbool(L, 1, true);
        unit->SetWalk(enable);
        return 0;
    }

    //SetSpeed(type, speed[, forced])
    static int SetSpeed(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 type = luaL_checkunsigned(L, 1);
        float rate = luaL_checknumber(L, 2);
        bool forced = luaL_optbool(L, 3, false);
        if (type >= MAX_MOVE_TYPE)
            sLog->outError(LOG_FILTER_GENERAL, "Eluna::Invalid movement type (%u)  for SetSpeed", type);
        else
            unit->SetSpeed((UnitMoveType)type, rate, forced);
        return 0;
    }

    //GetHonorPoints()
    static int GetHonorPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetHonorPoints());
        return 1;
    }
    //GetSelection()
    static int GetSelection(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnit(L, player->GetSelectedUnit());
        return 1;
    }

    //GetSecurity
    static int GetSecurity(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushInteger(L, player->GetSession()->GetSecurity());
        return 1;
    }

    //GetCoinage()
    static int GetCoinage(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetMoney());
        return 1;
    }

    // GetDisplayID()
    static int GetDisplayID(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->GetDisplayId());
        return 1;
    }

    // GetName()
    static int GetName(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        sEluna->PushString(L, unit->GetName().c_str());
        return 1;
    }

    // GetLevel()
    static int GetLevel(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->getLevel());
        return 1;
    }

    // GetHealth()
    static int GetHealth(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->GetHealth());
        return 1;
    }

    // GetGuildId()
    static int GetGuildID(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetGuildId());
        return 1;
    }

    // GetX()
    static int GetX(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushFloat(L, unit->GetPositionX());
        return 1;
    }

    // GetY()
    static int GetY(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushFloat(L, unit->GetPositionY());
        return 1;
    }

    // GetZ()
    static int GetZ(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushFloat(L, unit->GetPositionZ());
        return 1;
    }

    // GetO()
    static int GetO(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushFloat(L, unit->GetOrientation());
        return 1;
    }

    // GetLocation()
    static int GetLocation(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushFloat(L, unit->GetPositionX());
        sEluna->PushFloat(L, unit->GetPositionY());
        sEluna->PushFloat(L, unit->GetPositionZ());
        sEluna->PushFloat(L, unit->GetOrientation());
        return 4;
    }

    // GetZoneId()
    static int GetZoneId(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->GetZoneId());
        return 1;
    }

    //GetInstanceId()
    static int GetInstanceId(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->GetInstanceId());
        return 1;
    }

    //GetPhaseMask()
    static int GetPhaseMask(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->GetPhaseMask());
        return 1;
    }

    // GetAreaId()
    static int GetAreaId(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->GetAreaId());
        return 1;
    }

    // GetTeam()
    static int GetTeam(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushInteger(L, player->GetTeamId());
        return 1;
    }

    // GetGUID()
    static int GetGUID(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushGUID(L, unit->GetGUID());
        return 1;
    }

    // GetPower([powertype])
    static int GetPower(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int type = luaL_optint(L, 1, -1);
        if (type == -1)
        {
            // We didn't specify a type, so get the default type for our class
            switch(unit->getClass())
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
            luaL_error(L, "Bad argument #1 to :GetPower(index) - specified out of range index (%i)", type);
            return 0;
        }

        sEluna->PushUnsigned(L, unit->GetPower((Powers) type));
        return 1;
    }

    // GetMaxPower([index])
    static int GetMaxPower(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int type = luaL_optint(L, 1, -1);
        if (type == -1)
        {
            // We didn't specify a type, so get the default type for our class
            switch(unit->getClass())
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
            luaL_error(L, "Bad argument #1 to :GetMaxPower(index) - specified out of range index.");
            return 0;
        }

        sEluna->PushUnsigned(L, unit->GetMaxPower((Powers) type));
        return 1;
    }

    //GetPowerType()
    static int GetPowerType(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushInteger(L, unit->getPowerType());
        return 1;
    }

    // GetMaxHealth()
    static int GetMaxHealth(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->GetMaxHealth());
        return 1;
    }

    // GetHealthPct()
    static int GetHealthPct(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushFloat(L, unit->GetHealthPct());
        return 1;
    }

    // GetPowerPct()
    static int GetPowerPct(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float percent = (unit->GetPower(unit->getPowerType()) / unit->GetMaxPower(unit->getPowerType())) * 100;
        sEluna->PushFloat(L, percent);
        return 1;
    }

    // GetGender()
    static int GetGender(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        sEluna->PushUnsigned(L, unit->getGender());
        return 1;
    }

    // GetRace()
    static int GetRace(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->getRace());
        return 1;
    }

    // GetClass() - returns numerical index of class
    static int GetClass(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->getClass());
        return 1;
    }

    // GetCreatureType()
    static int GetCreatureType(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->GetCreatureType());
        return 1;
    }

    // GetClassAsString()
    static int GetClassAsString(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        const char* str = NULL;
        switch(unit->getClass())
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
            str = "DeathKnight";
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

    // GetItemCount(id[, checkbank])
    static int GetItemCount(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        int id = luaL_checknumber(L, 1);
        bool checkinBank = luaL_optbool(L, 2, false);
        sEluna->PushUnsigned(L, player->GetItemCount(id, checkinBank));
        return 1;
    }

    // GetLifetimeKills()
    static int GetLifetimeKills(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
        sEluna->PushUnsigned(L, currentKills);
        return 1;
    }

    // GetPlayerIP()
    static int GetPlayerIP(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushString(L, player->GetSession()->GetRemoteAddress().c_str());
        return 1;
    }

    // GetLevelPlayedTime()
    static int GetLevelPlayedTime(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetLevelPlayedTime());
        return 1;
    }

    // GetTotalPlayedTime()
    static int GetTotalPlayedTime(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetTotalPlayedTime());
        return 1;
    }

    // GetUnitType()
    static int GetUnitType(lua_State* L, Unit* unit)
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

    // GetGuild()
    static int GetGuild(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushGuild(L, player->GetGuild());
        return 1;
    }

    // GetGroup()
    static int GetGroup(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushGroup(L, player->GetGroup());
        return 1;
    }

    // GetGearLevel()
    static int GetGearLevel(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushFloat(L, player->GetAverageItemLevel());
        return 1;
    }

    // GetEntry()
    static int GetEntry(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->GetEntry());
        return 1;
    }

    // GetFaction()
    static int GetFaction(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->getFaction());
        return 1;
    }

    // Set Methods

    // SetFaction(id)
    static int SetFaction(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 factionId = luaL_checkunsigned(L, 1);
        unit->setFaction(factionId);
        return 0;
    }

    // SetLevel(level)
    static int SetLevel(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 newLevel = luaL_checkunsigned(L, 1);
        unit->SetLevel(newLevel);
        return 0;
    }

    //SetPhaseMask(Phase, update)
    static int SetPhaseMask(lua_State* L, Unit* unit)
    {
        TO_UNIT();
        uint32 phaseMask = luaL_checkunsigned(L, 1);
        bool Update = luaL_optbool(L, 2, true);
        unit->SetPhaseMask(phaseMask, Update);
        return 0;
    }

    //SetArenaPoints(amount)
    static int SetArenaPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 arenaP = luaL_checkunsigned(L, 1);
        player->SetArenaPoints(arenaP);
        return 0;
    }

    //SetHonorPoints(amount)
    static int SetHonorPoints(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 honorP = luaL_checkunsigned(L, 1);
        player->SetHonorPoints(honorP);
        return 0;
    }

    // SetLifetimeKills(val)
    static int SetLifetimeKills(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 val = luaL_checkunsigned(L, 1);
        player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, val);
        return 0;
    }

    // SetHealth(amount)
    static int SetHealth(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 amt = luaL_checkunsigned(L, 1);
        unit->SetHealth(amt);
        return 0;
    }

    // SetMaxHealth(amount)
    static int SetMaxHealth(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 amt = luaL_checkunsigned(L, 1);
        unit->SetMaxHealth(amt);
        return 0;
    }

    // SetPower(powerType, amount)
    static int SetPower(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int type = luaL_checkinteger(L, 1);
        uint32 amt = luaL_checkunsigned(L, 2);

        switch(type)
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
            luaL_error(L, "Bad argument #1 for SetPower - Unknown power type (%i)", type);
            break;
        }
        return 0;
    }

    // SetMaxPower(Type, amt)
    static int SetMaxPower(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int type = luaL_checkinteger(L, 1);
        int amt = luaL_checkunsigned(L, 2);

        switch(type)
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
            luaL_error(L, "Bad argument #1 for SetPower - Unknown power type (%i)", type);
            break;
        }
        return 0;
    }

    // SetDisplayID(id)
    static int SetDisplayID(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 model = luaL_checkunsigned(L, 1);
        unit->SetDisplayId(model);
        return 0;
    }

    // SetFacing(o)
    static int SetFacing(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float o = luaL_checknumber(L, 1);
        unit->SetFacingTo(o);
        return 0;
    }

    //SetDeathState(value)
    static int SetDeathState(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint8 ds = luaL_checkunsigned(L, 1);
        unit->setDeathState((DeathState)ds);
        return 0;
    }

    // SetCoinage(amount)
    static int SetCoinage(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 amt = luaL_checkunsigned(L, 1);
        player->SetMoney(amt);
        return 0;
    }

    //SetBindPoint(x, y, z, mapid, areaid)
    static int SetBindPoint(lua_State * L, Unit* unit)
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

    //SetBindPointAtPlayerLoc()
    static int SetBindPointAtPlayerLoc(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        WorldLocation loc;
        player->GetPosition(&loc);
        loc.m_mapId = player->GetMapId();
        player->SetHomebind(loc, player->GetAreaId());
        return 0;
    }

    // SetKnownTitle(id)
    static int SetKnownTitle(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 id = luaL_checkunsigned(L, 1);
        CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
        if (t)
            player->SetTitle(t, false);
        return 0;
    }

    // UnsetKnownTitle(id)
    static int UnsetKnownTitle(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 id = luaL_checkunsigned(L, 1);
        CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
        if (t)
            player->SetTitle(t, true);
        return 0;
    }

    // AdvanceSkillsToMax()
    static int AdvanceSkillsToMax(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->UpdateSkillsToMaxSkillsForLevel();
        return 0;
    }

    // AdvanceAllSkills(value)
    static int AdvanceAllSkills(lua_State* L, Unit * unit)
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

    // AdvanceSkill(skill_id, step)
    static int AdvanceSkill(lua_State* L, Unit* unit)
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


    // Boolean Methods

    // IsInGroup()
    static int IsInGroup(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        sEluna->PushBoolean(L, (player->GetGroup() != NULL));
        return 1;
    }

    // IsInGuild()
    static int IsInGuild(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        sEluna->PushBoolean(L, (player->GetGuildId() != 0));
        return 1;
    }

    // IsGM()
    static int IsGM(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        sEluna->PushBoolean(L, player->isGameMaster());
        return 1;
    }

    // IsAlive()
    static int IsAlive(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        sEluna->PushBoolean(L, unit->isAlive());
        return 1;
    }

    // IsDead()
    static int IsDead(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        sEluna->PushBoolean(L, unit->isDead());
        return 1;
    }

    // IsBanker()
    static int IsBanker(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        sEluna->PushBoolean(L, unit->isBanker());
        return 1;
    }

    // IsBattleMaster()
    static int IsBattleMaster(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        sEluna->PushBoolean(L, unit->isBattleMaster());
        return 1;
    }

    // IsCharmed()
    static int IsCharmed(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        sEluna->PushBoolean(L, unit->isCharmed());
        return 1;
    }

    // IsArmorer()
    static int IsArmorer(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        sEluna->PushBoolean(L, unit->isArmorer());
        return 1;
    }

    // IsAttackingPlayer()
    static int IsAttackingPlayer(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        sEluna->PushBoolean(L, unit->isAttackingPlayer());
        return 1;
    }

    //IsInArenaTeam(type) type : 0 = 2v2, 1 = 3v3, 2 = 5v5
    static int IsInArenaTeam(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 type = luaL_checkunsigned(L, 1);
        if (type < MAX_ARENA_SLOT && player->GetArenaTeamId(type))
            sEluna->PushBoolean(L, true);
        else
            sEluna->PushBoolean(L, false);
        return 1;
    }

    // IsInWorld()
    static int IsInWorld(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        sEluna->PushBoolean(L, unit->IsInWorld());
        return 1;
    }

    // IsPvPFlagged()
    static int IsPvPFlagged(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        sEluna->PushBoolean(L, unit->IsPvP());
        return 1;
    }

    // HasQuest(id)
    static int HasQuest(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        uint32 questId = luaL_checkunsigned(L, 1);
        sEluna->PushBoolean(L, unit->hasQuest(questId));
        return 1;
    }

    // IsHorde()
    static int IsHorde(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        sEluna->PushBoolean(L, (player->GetTeam() == HORDE));
        return 1;
    }

    // IsAlliance()
    static int IsAlliance(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        sEluna->PushBoolean(L, (player->GetTeam() == ALLIANCE));
        return 1;
    }

    // IsInCombat();
    static int IsInCombat(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        sEluna->PushBoolean(L, unit->isInCombat());
        return 1;
    }

    // HasTitle(id)
    static int HasTitle(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 id = luaL_checkunsigned(L, 1);
        sEluna->PushBoolean(L, player->HasTitle(id));
        return 1;
    }

    // HasSpell(id)
    static int HasSpell(lua_State* L, Unit* unit)
    {
        TO_UNIT_BOOL();

        uint32 id = luaL_checkunsigned(L, 1);
        sEluna->PushBoolean(L, unit->HasSpell(id));
        return 1;
    }

    // HasItem(itemId[, count, check_bank])
    static int HasItem(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 itemId = luaL_checkunsigned(L, 1);
        uint32 count = luaL_optunsigned(L, 2, 1);
        bool check_bank = luaL_optbool(L, 3, false);
        sEluna->PushBoolean(L, player->HasItemCount(itemId, count, check_bank));
        return 1;
    }

    // Other Methods

    // Teleport(mapid, x, y, z, o)
    static int Teleport(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 mapId = luaL_checkunsigned(L, 1);
        float X = luaL_checknumber(L, 2);
        float Y = luaL_checknumber(L, 3);
        float Z = luaL_checknumber(L, 4);
        float O = luaL_checknumber(L, 5);
        if (player->isInFlight())
        {
            player->GetMotionMaster()->MovementExpired();
            player->CleanupAfterTaxiFlight();
        }
        sEluna->PushBoolean(L, player->TeleportTo(mapId, X, Y, Z, O));
        return 1;
    }

    // AddLifetimeKills(val)
    static int AddLifetimeKills(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 val = luaL_checkunsigned(L, 1);
        uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
        player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills + val);
        return 0;
    }

    // AddItem(entry, amount)
    static int AddItem(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        uint32 itemId = luaL_checkunsigned(L, 1);
        uint32 itemCount = luaL_checkunsigned(L, 2);
        sEluna->PushBoolean(L, player->AddItem(itemId, itemCount));
        return 0;
    }

    // RemoveItem(entry, amount)
    static int RemoveItem(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 itemId = luaL_checkunsigned(L, 1);
        uint32 itemCount = luaL_checkunsigned(L, 2);

        player->DestroyItemCount(itemId, itemCount, true);
        return 0;
    }

    // RemoveLifetimeKills(val)
    static int RemoveLifetimeKills(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 val = luaL_checkunsigned(L, 1);
        uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
        if (currentKills == 0 || val > currentKills)
        {
            luaL_error(L, "Bad value. Player's Lifetime Kills must be greater than 0 and the value cannot be greater than the actual kills.");
            return 0;
        }
        player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills - val);
        return 0;
    }

    // ResetSpellCooldown(spellId, update(bool~optional))
    static int ResetSpellCooldown(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 spellId = luaL_checkunsigned(L, 1);
        bool update = luaL_optbool(L, 2, true);
        player->RemoveSpellCooldown(spellId, update);
        return 0;
    }

    // ResetTypeCooldowns(category, update(bool~optional))
    static int ResetTypeCooldowns(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 category = luaL_checkunsigned(L, 1);
        bool update = luaL_optbool(L, 2, true);
        player->RemoveSpellCategoryCooldown(category, update);
        return 0;
    }

    // ResetAllCooldowns()
    static int ResetAllCooldowns(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->RemoveAllSpellCooldown();
        return 0;
    }

    // SendBroadcastMessage(msg)
    static int SendBroadcastMessage(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        const char* message = luaL_checkstring(L, 1);
        if (std::string(message).length() > 0)
            ChatHandler(player->GetSession()).SendSysMessage(message);
        return 0;
    }

    // SendAreaTriggerMessage(msg)
    static int SendAreaTriggerMessage(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        const char* msg = luaL_checkstring(L, 1);
        if (std::string(msg).length() > 0)
            player->GetSession()->SendAreaTriggerMessage(msg);
        return 0;
    }

    // SendNotification(msg)
    static int SendNotification(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        const char* msg = luaL_checkstring(L, 1);
        if (std::string(msg).length() > 0)
            player->GetSession()->SendNotification(msg);
        return 0;
    }

    // SendUnitWhisper(msg, receiver, bossWhisper)
    static int SendUnitWhisper(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        const char* msg = luaL_checkstring(L, 1);
        Unit* receiver = sEluna->CHECK_UNIT(L, 2);
        if (receiver && std::string(msg).length() > 0)
            unit->MonsterWhisper(msg, receiver->GetGUID(), false);
        return 0;
    }

    // SendUnitSay(msg, language)
    static int SendUnitSay(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        const char* msg = luaL_checkstring(L, 1);
        uint32 language = luaL_checknumber(L, 2);
        if (std::string(msg).length() > 0)
            unit->MonsterSay(msg, language, unit->GetGUID());
        return 0;
    }

    // SendUnitYell(msg, language)
    static int SendUnitYell(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        const char* msg = luaL_checkstring(L, 1);
        uint32 language = luaL_checknumber(L, 2);
        if (std::string(msg).length() > 0)
            unit->MonsterYell(msg, language, unit->GetGUID());
        return 0;
    }

    // SendPacketToPlayer(packet)
    static int SendPacketToPlayer(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
        if (data)
            player->GetSession()->SendPacket(data);
        return 0;
    }

    // SendPacket(packet)
    static int SendPacket(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
        if (data)
            player->SendMessageToSet(data, false);
        return 0;
    }

    // SendPacketToGroup(packet, sendToPlayersInBattleground)
    static int SendPacketToGroup(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
        bool ignorePlayersInBg = luaL_checkbool(L, 2);
        if (data && player->GetGroup())
            player->GetGroup()->BroadcastPacket(data, ignorePlayersInBg, -1, player->GetGUID());
        return 0;
    }

    // SendPacketToGuild(packet)
    static int SendPacketToGuild(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
        if (data && player->GetGuild())
            player->GetGuild()->BroadcastPacket(data);
        return 0;
    }

    // SendPacketToRankedInGuild(packet, rankId)
    static int SendPacketToRankedInGuild(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        WorldPacket* data = sEluna->CHECK_PACKET(L, 1);
        uint8 ranked = luaL_checkunsigned(L, 2);
        if (data && player->GetGuild())
            player->GetGuild()->BroadcastPacketToRank(data, ranked);
        return 0;
    }

    // :SendVendorWindow(unit)
    static int SendVendorWindow(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        Unit* sendTo = sEluna->CHECK_UNIT(L, 1);
        if (!sendTo)
            return 0;
        player->GetSession()->SendListInventory(sendTo->GetGUID());
        return 0;
    }

    // GiveCoinage(amount)
    static int GiveCoinage(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        int amt = luaL_checkinteger(L, 1);
        if (amt > 0)
            sEluna->PushBoolean(L, player->ModifyMoney(amt));
        else
            sEluna->PushBoolean(L, false);
        return 1;
    }

    // RemoveCoinage(amount)
    static int RemoveCoinage(lua_State* L, Unit* unit)
    {
        TO_PLAYER_BOOL();

        int amt = luaL_checkinteger(L, 1);
        if (amt > 0)
            sEluna->PushBoolean(L, player->ModifyMoney(amt));
        else
            sEluna->PushBoolean(L, false);
        return 1;
    }

    // LearnSpell(id)
    static int LearnSpell(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 id = luaL_checkunsigned(L, 1);
        player->learnSpell(id,  false);
        return 0;
    }

    // DeMorph()
    static int DeMorph(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        unit->DeMorph();
        return 0;
    }

    // ResurrectPlayer(percent, sickness(bool))
    static int ResurrectPlayer(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        float percent = luaL_optnumber(L, 1, 100.0f);
        bool sickness = luaL_optbool(L, 2, false);
        player->ResurrectPlayer(percent, sickness);
        return 0;
    }

    // CastSpell(spellID) - self
    static int CastSpell(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spell = luaL_checkunsigned(L, 1);
        unit->CastSpell(unit, spell, true);
        return 0;
    }

    // CastSpellOnTarget(spellID, unit, triggered) - See if can be gameobject target
    static int CastSpellOnTarget(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spell = luaL_checkunsigned(L, 1);
        Unit* target = sEluna->CHECK_UNIT(L, 2);
        bool triggered = luaL_optbool(L, 3, true);
        if (target)
            unit->CastSpell(target, spell, triggered);
        return 0;
    }

    // CastSpellAoF(x, y, z, id) - to coords
    static int CastSpellAoF(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        float _x = luaL_checknumber(L, 1);
        float _y = luaL_checknumber(L, 2);
        float _z = luaL_checknumber(L, 3);
        uint32 spell = luaL_checkunsigned(L, 4);
        unit->CastSpell(_x, _y, _z, spell, true);
        return 0;
    }

    // FullCastSpell(spellID) - self
    static int FullCastSpell(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spell = luaL_checkunsigned(L, 1);
        unit->CastSpell(unit, spell, false);
        return 0;
    }

    // FullCastSpellOnTarget(spellID, unit) - See if can be gameobject target
    static int FullCastSpellOnTarget(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spell = luaL_checkunsigned(L, 1);
        Unit* target = sEluna->CHECK_UNIT(L, 2);
        if (target)
            unit->CastSpell(target, spell, false);
        return 0;
    }

    // GetAccountId()
    static int GetAccountId(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        sEluna->PushUnsigned(L, player->GetSession()->GetAccountId());
        return 1;
    }

    // GetAccountName()
    static int GetAccountName(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        std::string accName;
        if (sAccountMgr->GetName(player->GetSession()->GetAccountId(), accName))
            sEluna->PushString(L, accName.c_str());
        else
            return 0;
        return 1;
    }

    // GetAITargets()
    static int GetAITargets(lua_State* L, Unit* unit)
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

    // GetAITargetsCount()
    static int GetAITargetsCount(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        sEluna->PushUnsigned(L, creature->getThreatManager().getThreatList().size());
        return 1;
    }

    // Booleans

    // IsDungeonBoss()
    static int IsDungeonBoss(lua_State* L, Unit* unit)
    {
        TO_CREATURE_BOOL();

        sEluna->PushBoolean(L, creature->IsDungeonBoss());
        return 1;
    }

    // IsWorldBoss()
    static int IsWorldBoss(lua_State* L, Unit* unit)
    {
        TO_CREATURE_BOOL();

        sEluna->PushBoolean(L, creature->isWorldBoss());
        return 1;
    }

    // GetAura(spellID)
    static int GetAura(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spellID = luaL_checkunsigned(L, 1);
        sEluna->PushAura(L, unit->GetAura(spellID));
        return 1;
    }

    // GetMapId()
    static int GetMapId(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->GetMapId());
        return 1;
    }

    // GetCombatTime()
    static int GetCombatTime(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        sEluna->PushUnsigned(L, unit->GetCombatTimer());
        return 1;
    }

    // ClearInCombat()
    static int ClearInCombat(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        unit->ClearInCombat();
        return 0;
    }

    // StopSpellCast(spellId(optional))
    static int StopSpellCast(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spellId = luaL_optunsigned(L, 1, 0);
        unit->CastStop(spellId);
        return 0;
    }

    // InterruptSpell(spellType, delayed(optional), instant(optional))
    static int InterruptSpell(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int spellType = luaL_checkint(L, 1);
        bool delayed = luaL_optbool(L, 2, true);
        bool instant = luaL_optbool(L, 3, true);
        switch(spellType)
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

    // AddAura(spellId)
    static int AddAura(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spellId = luaL_checkunsigned(L, 1);
        Unit* target = sEluna->CHECK_UNIT(L, 2);
        if (!target)
            return 0;
        unit->AddAura(spellId, target);
        return 0;
    }

    // RemoveAura(spellId, casterGuid(optional))
    static int RemoveAura(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint32 spellId = luaL_checkunsigned(L, 1);
        unit->RemoveAurasDueToSpell(spellId);
        return 0;
    }

    // RemoveAllAuras()
    static int RemoveAllAuras(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        unit->RemoveAllAuras();
        return 0;
    }

    // GossipMenuAddItem(icon, msg, Intid, code, accept_decline_message, money)
    static int GossipMenuAddItem(lua_State* L, Unit* unit)
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

    // GossipComplete()
    static int GossipComplete(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->CLOSE_GOSSIP_MENU();
        return 0;
    }

    // GossipSendMenu(npc_text, unit)
    static int GossipSendMenu(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 _npcText = luaL_checkunsigned(L, 1);
        Unit* sender = sEluna->CHECK_UNIT(L, 2);
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

    // GossipClearMenu()
    static int GossipClearMenu(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        player->PlayerTalkClass->ClearMenus();
        return 0;
    }

    // PlaySoundToPlayer(soundId)
    static int PlaySoundToPlayer(lua_State* L, Unit* unit)
    {
        TO_PLAYER();

        uint32 soundId = luaL_checkunsigned(L, 1);
        SoundEntriesEntry const* soundEntry = sSoundEntriesStore.LookupEntry(soundId);
        if (!soundEntry)
            return 0;

        player->PlayDirectSound(soundId, player);
        return 0;
    }

    // PlayDirectSound(soundId,  player)
    static int PlayDirectSound(lua_State* L, Unit* unit)
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

    // PlayDistanceSound(soundId,  player)
    static int PlayDistanceSound(lua_State* L, Unit* unit)
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

    // Kill([target, durabilityLoss]) - Creates a timed event. Calls set to 0 will call inf returns eventID.
    static int Kill(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* target = sEluna->CHECK_UNIT(L, 1);
        bool durLoss = luaL_optbool(L, 2, true);
        unit->Kill((target ? target : unit), durLoss);
        return 0;
    }

    // RegisterEvent(function, delay, calls)
    static int RegisterEvent(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        uint32 delay = luaL_checkunsigned(L, 2);
        uint32 repeats = luaL_checkunsigned(L, 3);
        Eluna::LuaEventMap* eventMap = Eluna::LuaEventMap::GetEvents(creature);
        if (!eventMap)
        {
            luaL_error(L, "Creature has no registered creature events, please register one before using RegisterEvent");
            return 0;
        }
        if (!strcmp(luaL_typename(L, 1), "function") || delay > 0)
        {
            lua_settop(L, 1);
            int functionRef = lua_ref(L, true);
            eventMap->ScriptEventCreate(functionRef, delay, repeats);
            sEluna->PushInteger(L, functionRef);
        }
        else
            return 0;
        return 1;

    }

    // RemoveEventByID(eventID)
    static int RemoveEventByID(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        int eventID = luaL_checkinteger(L, 1);
        Eluna::LuaEventMap* eventMap = Eluna::LuaEventMap::GetEvents(creature);
        if (eventMap)
            eventMap->ScriptEventCancel(eventID);
        return 0;
    }

    // RemoveEvents()
    static int RemoveEvents(lua_State* L, Unit* unit)
    {
        TO_CREATURE();

        Eluna::LuaEventMap* eventMap = Eluna::LuaEventMap::GetEvents(creature);
        if (eventMap)
            eventMap->ScriptEventsReset();
        return 0;
    }

    static int GetInt32Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        sEluna->PushInteger(L, unit->GetInt32Value(index));
        return 1;
    }

    static int GetUInt32Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        sEluna->PushUnsigned(L, unit->GetUInt32Value(index));
        return 1;
    }

    static int GetFloatValue(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        sEluna->PushFloat(L, unit->GetFloatValue(index));
        return 1;
    }

    static int GetByteValue(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        sEluna->PushUnsigned(L, unit->GetByteValue(index, offset));
        return 1;
    }

    static int GetUInt16Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        sEluna->PushUnsigned(L, unit->GetUInt16Value(index, offset));
        return 1;
    }

    static int SetInt32Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        int32 value = luaL_checkinteger(L, 2);
        unit->SetInt32Value(index, value);
        return 0;
    }

    static int SetUInt32Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);
        unit->SetUInt32Value(index, value);
        return 0;
    }

    static int UpdateUInt32Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint32 value = luaL_checkunsigned(L, 2);
        unit->UpdateUInt32Value(index, value);
        return 0;
    }

    static int SetFloatValue(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        float value = luaL_checknumber(L, 2);

        unit->SetFloatValue(index, value);
        return 0;
    }

    static int SetByteValue(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        uint8 value = luaL_checkunsigned(L, 3);
        unit->SetByteValue(index, offset, value);
        return 0;
    }

    static int SetUInt16Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        uint16 value = luaL_checkunsigned(L, 3);
        unit->SetUInt16Value(index, offset, value);
        return 0;
    }

    static int SetInt16Value(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        uint16 index = luaL_checkunsigned(L, 1);
        uint8 offset = luaL_checkunsigned(L, 2);
        int16 value = luaL_checkinteger(L, 3);
        unit->SetInt16Value(index, offset, value);
        return 0;
    }

    /* Vehicle */

    // IsOnVehicle()
    static int IsOnVehicle(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        if (unit->GetVehicle() || (unit->ToPlayer() && unit->IsVehicle()))
            sEluna->PushBoolean(L, true);
        else
            sEluna->PushBoolean(L, false);
        return 1;
    }

    // DismissVehicle()
    static int DismissVehicle(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        if (unit->GetVehicle())
            unit->GetVehicle()->Dismiss();
        return 0;
    }

    // AddVehiclePassenger(unit, seatId)
    static int AddVehiclePassenger(lua_State* L, Unit* unit)
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

    // EjectPassenger(unit) (GIVES LINKER ERROR)
    /*
    static int EjectPassenger(lua_State* L, Unit* unit) 
    {
    TO_UNIT();

    Unit* passenger = sEluna->CHECK_UNIT(L, 1);
    Vehicle* _vehicle = unit->GetVehicle();
    if (!_vehicle)
    return 0;

    _vehicle->EjectPassenger(passenger, unit);
    return 0;
    }*/

    // RemovePassenger(unit)
    static int RemovePassenger(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* passenger = sEluna->CHECK_UNIT(L, 1);
        Vehicle* _vehicle = unit->GetVehicle();
        if (!_vehicle)
            return 0;

        _vehicle->RemovePassenger(passenger);
        return 0;
    }

    // RemoveAllPassengers()
    static int RemoveAllPassengers(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        _unit->GetVehicle()->RemoveAllPassengers();
        return 0;
    }

    // GetPassenger(seatId)
    static int GetPassenger(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int8 seatId = luaL_checkunsigned(L, 1);
        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        sEluna->PushUnit(L, _unit->GetVehicle()->GetPassenger(seatId));
        return 1;
    }

    // GetNextEmptySeat(seatId)
    static int GetNextEmptySeat(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int8 seatId = luaL_checkunsigned(L, 1);
        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        //sEluna->PushInteger(L, _unit->GetVehicle()->GetNextEmptySeat(seatId, true));
        //return 1;
        return 0;
    }

    // GetAvailableSeats()
    static int GetAvailableSeats(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        sEluna->PushUnsigned(L, _unit->GetVehicle()->GetAvailableSeatCount());
        return 1;
    }

    // GetVehicleBase()
    static int GetVehicleBase(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        Unit* _unit = unit->GetVehicleBase();
        if (_unit)
            sEluna->PushUnit(L, _unit);
        else
            lua_pushnil(L);
        return 1;
    }

    // HasEmptySeat(seatId)
    static int HasEmptySeat(lua_State* L, Unit* unit)
    {
        TO_UNIT();

        int8 seatId = luaL_checkunsigned(L, 1);
        Unit* _unit = unit->GetVehicleBase();
        if (!_unit)
            return 0;

        sEluna->PushBoolean(L, _unit->GetVehicle()->HasEmptySeat(seatId));
        return 1;
    }
};
#endif
