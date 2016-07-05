#include "bot_ai.h"
#include "bot_Events.h"
#include "botmgr.h"
#include "Chat.h"
#include "Config.h"
#include "GroupMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Language.h"
#include "MapManager.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellAuras.h"
/*
Npc Bot Manager by Graff (onlysuffering@gmail.com)
Player NpcBots management
%Complete: ???
*/

//config
int8 _basefollowdist;
uint8 _maxNpcBots;
uint8 _maxClassNpcBots;
uint8 _xpReductionNpcBots;
uint8 _healTargetIconFlags;
uint32 _npcBotsCost;
bool _enableNpcBots;
bool _allowgm;
bool _enableNpcBotsDungeons;
bool _enableNpcBotsRaids;
bool _enableNpcBotsBGs;
bool _enableNpcBotsArenas;
bool _enableDungeonFinder;
bool _limitNpcBotsDungeons;
bool _limitNpcBotsRaids;
bool _botPvP;
float _mult_dmg_melee;
float _mult_dmg_spell;
float _mult_healing;

bool __firstload = true;

BotMgr::BotMgr(Player* const master) : _owner(master)
{
    //LoadConfig(); already loaded (MapManager.cpp)
    _followdist = _basefollowdist;

    master->SetBotMgr(this);
}
BotMgr::~BotMgr() { }

void BotMgr::LoadConfig(bool force)
{
    if (__firstload)
        __firstload = false;
    else if (!force)
        return;

    _enableNpcBots          = sConfigMgr->GetBoolDefault("NpcBot.Enable", true);
    _allowgm                = sConfigMgr->GetBoolDefault("NpcBot.AllowGM", true);
    _maxNpcBots             = sConfigMgr->GetIntDefault("NpcBot.MaxBots", 1);
    _maxClassNpcBots        = sConfigMgr->GetIntDefault("NpcBot.MaxBotsPerClass", 1);
    _basefollowdist         = sConfigMgr->GetIntDefault("NpcBot.BaseFollowDistance", 30);
    _xpReductionNpcBots     = sConfigMgr->GetIntDefault("NpcBot.XpReduction", 0);
    _healTargetIconFlags    = sConfigMgr->GetIntDefault("NpcBot.HealTargetIconsMask", 0);
    _mult_dmg_melee         = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Melee", 1.0);
    _mult_dmg_spell         = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Spell", 1.0);
    _mult_healing           = sConfigMgr->GetFloatDefault("NpcBot.Mult.Healing", 1.0);
    _enableNpcBotsDungeons  = sConfigMgr->GetBoolDefault("NpcBot.Enable.Dungeon", true);
    _enableNpcBotsRaids     = sConfigMgr->GetBoolDefault("NpcBot.Enable.Raid", false);
    _enableNpcBotsBGs       = sConfigMgr->GetBoolDefault("NpcBot.Enable.BG", false);
    _enableNpcBotsArenas    = sConfigMgr->GetBoolDefault("NpcBot.Enable.Arena", false);
    _enableDungeonFinder    = sConfigMgr->GetBoolDefault("NpcBot.Enable.DungeonFinder", true);
    _limitNpcBotsDungeons   = sConfigMgr->GetBoolDefault("NpcBot.Limit.Dungeon", true);
    _limitNpcBotsRaids      = sConfigMgr->GetBoolDefault("NpcBot.Limit.Raid", true);
    _npcBotsCost            = sConfigMgr->GetIntDefault("NpcBot.Cost", 1000000);
    _botPvP                 = sConfigMgr->GetBoolDefault("NpcBot.PvP", true);

    //limits
    _mult_dmg_melee         = std::max(_mult_dmg_melee, 0.1f);
    _mult_dmg_spell         = std::max(_mult_dmg_spell, 0.1f);
    _mult_healing           = std::max(_mult_healing,   0.1f);
    _mult_dmg_melee         = std::min(_mult_dmg_melee, 10.f);
    _mult_dmg_spell         = std::min(_mult_dmg_spell, 10.f);
    _mult_healing           = std::min(_mult_healing,   10.f);
}

uint8 BotMgr::GetNpcBotsCount(bool inWorldOnly) const
{
    if (!inWorldOnly)
        return _bots.size();

    //CRITICAL SECTION
    //inWorldOnly is only for one-shot cases (opcodes, etc.)
    uint8 count = 0;
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        if (ObjectAccessor::GetCreatureOrPetOrVehicle(*_owner, itr->first))
            ++count;
    return count;
}

bool BotMgr::IsNpcBotModEnabled()
{
    return _enableNpcBots;
}

bool BotMgr::IsAllowGMModEnabled()
{
    return _allowgm;
}

bool BotMgr::IsNpcBotDungeonFinderEnabled()
{
    return _enableDungeonFinder;
}

uint8 BotMgr::GetNpcBotXpReduction()
{
    return _xpReductionNpcBots;
}

uint8 BotMgr::GetMaxNpcBots()
{
    return _maxNpcBots <= 4 ? _maxNpcBots : 4;
}

bool BotMgr::LimitBots(Map const* map)
{
    if (_limitNpcBotsDungeons && map->IsNonRaidDungeon())
        return true;
    if (_limitNpcBotsRaids && map->IsRaid())
        return true;

    return false;
}

void BotMgr::Update(uint32 diff)
{
    //remove temp bots from bot map before updating it
    while (!_removeList.empty())
    {
        GuidList::iterator itr = _removeList.begin();

        BotMap::iterator bitr = _bots.find(*itr);
        ASSERT(bitr != _bots.end());
        _bots.erase(bitr);

        _removeList.erase(itr);
        continue;
    }

    if (!HaveBot())
        return;

    //uint64 guid;
    Creature* bot;
    bot_minion_ai* ai;
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        //guid = itr->first;
        bot = itr->second;
        ai = bot->GetBotMinionAI();

        if (ai->IAmFree())
            continue;

        if (!bot->IsInWorld())
        {
            ai->CommonTimers(diff);
            continue;
        }

        if (!_isPartyInCombat())
            ai->UpdateReviveTimer(diff);

        bot->SetCanUpdate(true);
        bot->IsAIEnabled = true;

        if (ai->GetReviveTimer() <= diff)
        {
            if (bot->isDead() && _owner->IsAlive() && !_owner->IsInCombat() && !_owner->IsBeingTeleported() && !_owner->InArena() &&
                !_owner->IsInFlight() && !_owner->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) &&
                !_owner->HasInvisibilityAura() && !_owner->HasStealthAura())
            {
                _reviveBot(bot);
                continue;
            }

            ai->SetReviveTimer(urand(1000, 5000));
        }

        if (_owner->IsAlive() && bot->IsAlive() && !ai->IsTempBot() && !ai->IsDuringTeleport() &&
            (RestrictBots(bot, false) ||
            bot->GetMap() != _owner->GetMap() ||
            (bot->GetBotCommandState() != COMMAND_STAY && _owner->GetDistance(bot) > 100.f))) // _owner->GetDistance(bot) > SIZE_OF_GRIDS
        {
            _owner->m_Controlled.erase(bot);
            TeleportBot(bot, _owner->GetMap(), _owner);
            continue;
        }

        bot->Update(diff);
        bot->SetCanUpdate(false);

        if (Creature* pet = bot->GetBotsPet())
        {
            pet->SetCanUpdate(true);
            pet->IsAIEnabled = true;
            pet->Update(diff);
            pet->SetCanUpdate(false);
        }
    }
}

bool BotMgr::RestrictBots(Creature const* bot, bool add) const
{
    if (!_owner->FindMap())
        return true;

    if (_owner->IsInFlight())
        return true;

    Map const* currMap = _owner->GetMap();

    if ((!_enableNpcBotsBGs && currMap->IsBattleground()) ||
        (!_enableNpcBotsArenas && currMap->IsBattleArena()) ||
        (!_enableNpcBotsDungeons && currMap->IsNonRaidDungeon()) ||
        (!_enableNpcBotsRaids && currMap->IsRaid()))
        return true;

    if (LimitBots(currMap))
    {
        //if bot is not in instance group - deny (only if trying to teleport to instance)
        if (add)
            if (!_owner->GetGroup() || !_owner->GetGroup()->IsMember(bot->GetGUID()))
                return true;

        InstanceMap const* map = currMap->ToInstanceMap();
        uint32 count = map->GetPlayersCountExceptGMs();
        if (count + uint8(add) > map->GetMaxPlayers())
            return true;
    }

    return false;
}

void BotMgr::_reviveBot(Creature* bot)
{
    if (bot->IsAlive())
        return;

    if (!bot->GetBotAI()->IAmFree())
        bot->Relocate(bot->GetBotOwner());

    bot->SetUInt32Value(UNIT_NPC_FLAGS, bot->GetCreatureTemplate()->npcflag);
    bot->ClearUnitState(uint32(UNIT_STATE_ALL_STATE));
    bot->setDeathState(ALIVE);
    //bot->GetBotAI()->Reset();
    bot->SetBotShouldUpdateStats();

    bot->SetHealth(bot->GetMaxHealth() / 6); //~15% of max health
    if (bot->getPowerType() == POWER_MANA)
        bot->SetPower(POWER_MANA, bot->GetMaxPower(POWER_MANA) / 5); //20% of max mana

    if (!bot->GetBotAI()->IAmFree())
        bot->SetBotCommandState(COMMAND_FOLLOW, true);
}

Creature* BotMgr::GetBot(ObjectGuid guid) const
{
    BotMap::const_iterator itr = _bots.find(guid);
    return itr != _bots.end() ? itr->second : NULL;
}

bool BotMgr::_isPartyInCombat() const
{
    if (_owner->IsInCombat())
        return true;

    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        if (itr->second->IsInCombat())
            return true;
        if (Creature* pet = itr->second->GetBotsPet())
            if (pet->IsInCombat())
                return true;
    }

    return false;
}

void BotMgr::OnTeleportFar(uint32 mapId, float x, float y, float z, float ori)
{
    Map* newMap = sMapMgr->CreateBaseMap(mapId);
    Creature* bot;
    Position pos;
    pos.Relocate(x, y, z, ori);

    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        bot = itr->second;
        ASSERT(bot && "BotMgr::OnTeleportFar(): bot does not exist!!!");

        if (bot->IsTempBot())
            continue;

        _owner->m_Controlled.erase(bot);
        TeleportBot(bot, newMap, &pos);
    }
}

void BotMgr::_teleportBot(Creature* bot, Map* newMap, float x, float y, float z, float ori)
{
    ASSERT(bot->GetBotAI());
    bot->GetBotAI()->AbortTeleport();

    bot->SetBotsPetDied();
    bot->GetBotAI()->UnsummonAll();
    bot->KillEvents(true);

    if (bot->IsInWorld())
    {
        //bot->Whisper("teleport...", LANG_UNIVERSAL, bot->GetBotAI()->GetBotOwnerGuid());
        bot->CastSpell(bot, COSMETIC_TELEPORT_EFFECT, true);
    }

    bot->IsAIEnabled = false;
    //UnitAI* oldAI = bot->GetAI();
    //bot->SetAI(NULL);

    //if (bot->IsFreeBot() || bot->GetBotOwner()->GetSession()->isLogingOut())
    //{
    //    bot->FarTeleportTo(newMap, x, y, z, ori);

    //    //bot->SetAI(oldAI);
    //    bot->IsAIEnabled = true;
    //    return;
    //}

    ////start Unit::CleanupBeforeRemoveFromMap()
    if (bot->IsInWorld())
        bot->RemoveFromWorld();

    ASSERT(bot->GetGUID());

    // A unit may be in removelist and not in world, but it is still in grid
    // and may have some references during delete
    //RemoveAllAuras();
    bot->RemoveAllGameObjects();

    //if (finalCleanup)
    //    m_cleanupDone = true;

    bot->m_Events.KillAllEvents(false);                      // non-delatable (currently casted spells) will not deleted now but it will deleted at call in Map::RemoveAllObjectsInRemoveList
    bot->CombatStop();
    bot->ClearComboPointHolders();
    //bot->DeleteThreatList();
    bot->getHostileRefManager().setOnlineOfflineState(false);
    //bot->GetMotionMaster()->Clear(false);                    // remove different non-standard movement generators.
    //end Unit::CleanupBeforeRemoveFromMap()

    //bot->CleanupBeforeRemoveFromMap(false);

    bot->BotStopMovement();

    if (Map* mymap = bot->FindMap())
        mymap->RemoveFromMap(bot, false);

    if (bot->IsFreeBot()/* || bot->GetBotOwner()->GetSession()->isLogingOut()*/)
    {
        //bot->FarTeleportTo(newMap, x, y, z, ori);

        //Creature::FarTeleportTo()
        //{
        //CleanupBeforeRemoveFromMap(false); //done above
        //GetMap()->RemoveFromMap(this, false); //done above
        //Relocate(X, Y, Z, O);
        //SetMap(map);
        //GetMap()->AddToMap(this);
        //}
        bot->Relocate(x, y, z, ori);
        bot->SetMap(newMap);
        bot->GetMap()->AddToMap(bot);
        //end Creature::FarTeleportTo()

        //bot->SetAI(oldAI);
        bot->IsAIEnabled = true;
        return;
    }

    //update group member online state
    if (Group* gr = bot->GetBotOwner()->GetGroup())
        if (gr->IsMember(bot->GetGUID()))
            gr->SendUpdate();

    //bot->Relocate(x, y, z);
    TeleportFinishEvent* finishEvent = new TeleportFinishEvent(bot->GetBotMinionAI()/*, newMap->GetId(), newMap->GetInstanceId(), x, y, z, ori*/);
    bot->GetBotAI()->GetEvents()->AddEvent(finishEvent, bot->GetBotAI()->GetEvents()->CalculateTime(urand(5000, 8000)));
    bot->GetBotMinionAI()->SetTeleportFinishEvent(finishEvent);
}

void BotMgr::TeleportBot(Creature* bot, Map* newMap, Position* pos)
{
    _teleportBot(bot, newMap, pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), pos->GetOrientation());
}

void BotMgr::CleanupsBeforeBotDelete(ObjectGuid guid)
{
    BotMap::const_iterator itr = _bots.find(guid);
    ASSERT(itr != _bots.end() && "Trying to remove bot which does not belong to this botmgr(b)!!");
    ASSERT(_owner->IsInWorld() && "Trying to remove bot while not in world(b)!!");

    Creature* bot = itr->second;

    //don't allow removing bots while they are teleporting
    if (!bot->IsInWorld())
    {
        bot->GetBotAI()->AbortTeleport();
        //if (!bot->IsInWorld())
        //{
        //    TC_LOG_ERROR("entities.player", "BotMgr::CleanupsBeforeBotDelete(): Failed to abort %s's teleport! Still out of world!", bot->GetName().c_str());
        //    ASSERT(false);
        //}
    }

    //if player is logging out group will be disbanded (and bots removed) normal way
    //WorldSession.cpp:: if (_player->GetGroup() && !_player->GetGroup()->isRaidGroup() && m_Socket)
    if (!_owner->GetSession()->PlayerLogout())
        RemoveBotFromGroup(bot);

    bot->SetBotsPetDied();
    bot->OnBotDespawn(NULL);

    //_owner->SetMinion((Minion*)bot->ToTempSummon(), false);
    ASSERT(bot->GetOwnerGUID() == _owner->GetGUID());
    bot->SetOwnerGUID(ObjectGuid::Empty);
    _owner->m_Controlled.erase(bot);
    bot->m_ControlledByPlayer = false;
    bot->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
    bot->SetByteValue(UNIT_FIELD_BYTES_2, 1, 0);
    bot->SetGuidValue(UNIT_FIELD_CREATEDBY, ObjectGuid::Empty);

    bot->SetIAmABot(false);
}

void BotMgr::_addBotToRemoveList(ObjectGuid guid)
{
    _removeList.push_back(guid);
}

void BotMgr::RemoveAllBots(uint8 removetype)
{
    while (!_bots.empty())
        RemoveBot(_bots.begin()->first, removetype);
}
//Bot is being abandoned by player
void BotMgr::RemoveBot(ObjectGuid guid, uint8 removetype)
{
    BotMap::const_iterator itr = _bots.find(guid);
    ASSERT(itr != _bots.end() && "Trying to remove bot which does not belong to this botmgr(a)!!");
    ASSERT(_owner->IsInWorld() && "Trying to remove bot while not in world(a)!!");

    //trying to remove temp bot second time means removing all bots
    //just erase from bots because already cleaned up
    for (GuidList::iterator it = _removeList.begin(); it != _removeList.end(); ++it)
    {
        if (*it == guid)
        {
            _removeList.erase(it);
            _bots.erase(itr);
            return;
        }
    }

    Creature* bot = itr->second;
    CleanupsBeforeBotDelete(guid);

    ////remove control bar
    //if (GetNpcBotsCount() <= 1 && !_owner->GetPetGUID() && _owner->m_Controlled.empty())
    //    _owner->SendRemoveControlBar();

    if (bot->GetBotAI()->IsTempBot())
    {
        bot->GetBotAI()->OnBotDespawn(bot); //send to self
        _addBotToRemoveList(guid);
        return;
    }

    _bots.erase(itr);

    bot->GetBotAI()->ResetBotAI(removetype == BOT_REMOVE_DISMISS ? BOTAI_RESET_DISMISS : BOTAI_RESET_LOGOUT);

    bot->setFaction(bot->GetCreatureTemplate()->faction);
    bot->SetLevel(bot->GetCreatureTemplate()->minlevel);

    if (removetype == BOT_REMOVE_DISMISS)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_OWNER);
        //"UPDATE characters_npcbot SET owner = ? WHERE entry = ?", CONNECTION_ASYNC
        stmt->setUInt32(0, uint32(0));
        stmt->setUInt32(1, bot->GetEntry());
        CharacterDatabase.Execute(stmt);
    }

    bot->AI()->Reset();
}

BotAddResult BotMgr::AddBot(Creature* bot, bool takeMoney)
{
    ASSERT(bot->IsNPCBot());
    ASSERT(bot->GetBotAI() != NULL);

    bool temporary = bot->GetBotAI()->IsTempBot();

    if (!_enableNpcBots)
    {
        ChatHandler ch(_owner->GetSession());
        ch.SendSysMessage("NpcBot system is currently disabled. Please contact administration.");
        //ch.SetSentErrorMessage(true);
        return BOT_ADD_DISABLED;
    }
    // Is this the best place for this?
    if (_owner->IsGameMaster())
        {
            if (!_allowgm)
            {
                ChatHandler ch(_owner->GetSession());
                ch.SendSysMessage("NpcBot system is only available for players. GM's are not permitted to have bots.");
                //ch.SetSentErrorMessage(true);
                return BOT_ADD_DISABLED;
            }
        }
    if (GetBot(bot->GetGUID()))
        return BOT_ADD_ALREADY_HAVE; //Silent error, intended
    if (!bot->GetBotAI()->IAmFree())
    {
        ChatHandler ch(_owner->GetSession());
        ch.PSendSysMessage("%s will not join you, already has master: %s",
            bot->GetName().c_str(), bot->GetBotOwner()->GetName().c_str());
        //ch.SetSentErrorMessage(true);
        return BOT_ADD_NOT_AVAILABLE;
    }
    if (bot->GetBotAI()->IsDuringTeleport())
    {
        ChatHandler ch(_owner->GetSession());
        ch.PSendSysMessage("%s cannot join you while about to teleport", bot->GetName().c_str());
        //ch.SetSentErrorMessage(true);
        return BOT_ADD_BUSY;
    }
    if (!temporary && _owner->GetNpcBotsCount() >= GetMaxNpcBots())
    {
        ChatHandler ch(_owner->GetSession());
        ch.PSendSysMessage("Youre exceed max npcbots (%u)", GetMaxNpcBots());
        //ch.SetSentErrorMessage(true);
        return BOT_ADD_MAX_EXCEED;
    }
    if (!temporary && HaveBot() && _maxClassNpcBots)
    {
        uint8 count = 0;
        for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
            if (itr->second->GetBotClass() == bot->GetBotClass())
                ++count;

        if (count >= _maxClassNpcBots)
        {
            ChatHandler ch(_owner->GetSession());
            ch.PSendSysMessage("You cannot have more bots of that class! %u of %u", count, _maxClassNpcBots);
            //ch.SetSentErrorMessage(true);
            return BOT_ADD_MAX_CLASS_EXCEED;
        }
    }
    //Map* curMap = _owner->GetMap();
    //if (!temporary && LimitBots(curMap))
    //{
    //    InstanceMap* map = curMap->ToInstanceMap();
    //    uint32 count = map->GetPlayersCountExceptGMs();
    //    if (count >= map->GetMaxPlayers())
    //    {
    //        ChatHandler ch(_owner->GetSession());
    //        ch.PSendSysMessage("Instance players limit exceed (%u of %u)", count, map->GetMaxPlayers());
    //        //ch.SetSentErrorMessage(true);
    //        return BOT_ADD_INSTANCE_LIMIT;
    //    }
    //}
    if (!temporary && takeMoney)
    {
        uint32 cost = GetNpcBotCost(_owner->getLevel(), bot);
        if (!_owner->HasEnoughMoney(cost))
        {
            ChatHandler ch(_owner->GetSession());
            std::string str = "You don't have enough money (";
            str += GetNpcBotCostStr(_owner->getLevel(), bot);
            str += ")!";
            ch.SendSysMessage(str.c_str());
            //ch.SetSentErrorMessage(true);
            return BOT_ADD_CANT_AFFORD;
        }

        _owner->ModifyMoney(-(int32(cost)));
    }

    bot->SetBotsPetDied();
    bot->GetBotAI()->UnsummonAll();

    _bots[bot->GetGUID()] = bot;

    bot->SetIAmABot(true);
    bot->SetBotOwner(_owner);
    bot->SetGuidValue(UNIT_FIELD_CREATEDBY, _owner->GetGUID());

    //_owner->SetMinion((Minion*)bot->ToTempSummon(), true);
    ASSERT(!bot->GetOwnerGUID());
    bot->SetOwnerGUID(_owner->GetGUID());
    _owner->m_Controlled.insert(bot);
    bot->m_ControlledByPlayer = true;
    bot->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
    bot->SetByteValue(UNIT_FIELD_BYTES_2, 1, _owner->GetByteValue(UNIT_FIELD_BYTES_2, 1));

    //bot->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PC | UNIT_FLAG_IMMUNE_TO_NPC);
    //bot->SetByteValue(UNIT_FIELD_BYTES_0, 0, botrace);
    bot->setFaction(_owner->getFaction());
    //bot->SetLevel(_owner->getLevel());
    //bot->SetBotClass(botclass);
    //bot->AIM_Initialize();
    //bot->InitBotAI();
    //AddBotToGroup(bot);
    //InitBotEquips(m_bot);


    //CharmInfo charmInfo(_owner); //owner to not set reaction and other stuff, just empty charm
    //charmInfo.InitPetActionBar();

    //uint8 addlist = 0;
    //for (uint8 i = 0; i != MAX_SPELL_CHARM; ++i)
    //    if (charmInfo.GetCharmSpell(i)->GetAction())
    //        ++addlist;

    //WorldPacket data(SMSG_PET_SPELLS, 8+2+4+4+4*MAX_UNIT_ACTION_BAR_INDEX+1+4*addlist+1);
    //data << uint64(bot->GetGUID());
    //data << uint16(0);
    //data << uint32(0);

    //data << uint8(bot->GetReactState()) << uint8(bot->GetBotCommandState()) << uint16(0);

    //charmInfo.BuildActionBar(&data);

    //data << uint8(addlist);

    //if (addlist)
    //{
    //    for (uint8 i = 0; i != MAX_SPELL_CHARM; ++i)
    //    {
    //        CharmSpellInfo* cspell = charmInfo.GetCharmSpell(i);
    //        if (cspell->GetAction())
    //            data << uint32(cspell->packedData);
    //    }
    //}

    //data << uint8(0); // cooldowns count

    //_owner->GetSession()->SendPacket(&data);


    bot->GetBotAI()->Reset();

    if (!bot->GetBotAI()->IsTempBot())
    {
        bot->SetBotCommandState(COMMAND_FOLLOW, true);
        if (bot->GetBotAI()->HasRole(BOT_ROLE_PARTY))
            AddBotToGroup(bot);
    }

    if (!temporary)
    {
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_NPCBOT_OWNER);
        //"UPDATE characters_npcbot SET owner = ? WHERE entry = ?", CONNECTION_ASYNC
        stmt->setUInt32(0, _owner->GetGUID().GetCounter());
        stmt->setUInt32(1, bot->GetEntry());
        CharacterDatabase.Execute(stmt);
    }

    return BOT_ADD_SUCCESS;
}

bool BotMgr::AddBotToGroup(Creature* bot)
{
    ASSERT(GetBot(bot->GetGUID()));

    Group* gr = _owner->GetGroup();
    if (gr)
    {
        if (gr->IsMember(bot->GetGUID()))
            return true;

        if (gr->IsFull())
        {
            if (!gr->isRaidGroup()) //non-raid group is full
                gr->ConvertToRaid();
            else
                return false;
        }
    }
    else
    {
        gr = new Group;
        if (!gr->Create(_owner))
        {
            delete gr;
            return false;
        }
        sGroupMgr->AddGroup(gr);
    }

    if (gr->AddMember((Player*)bot))
    {
        if (!bot->GetBotAI()->HasRole(BOT_ROLE_PARTY))
            bot->GetBotAI()->ToggleRole(BOT_ROLE_PARTY, true);

        bot->GetBotAI()->CancelBoot();
        return true;
    }

    return false;
}

bool BotMgr::RemoveBotFromGroup(Creature* bot)
{
    ASSERT(GetBot(bot->GetGUID()));

    Group* gr = _owner->GetGroup();
    if (!gr || !gr->IsMember(bot->GetGUID()))
        return false;

    gr->RemoveMember(bot->GetGUID());

    if (bot->GetBotAI()->HasRole(BOT_ROLE_PARTY))
        bot->GetBotAI()->ToggleRole(BOT_ROLE_PARTY, true);

    Map* map = _owner->FindMap();
    gr = _owner->GetGroup(); //check if group has been deleted
    if (map && map->IsDungeon() && (!gr || !gr->IsMember(bot->GetGUID()))) //make sure bot is removed from group
    {
        ChatHandler(_owner->GetSession()).PSendSysMessage("Your bot %s has been removed from your group and will be teleported out of the instance in 60 seconds if not invited back", bot->GetName().c_str());

        if (gr && _owner->GetGUID() != gr->GetLeaderGUID())
            if (Player* leader = ObjectAccessor::FindPlayer(gr->GetLeaderGUID()))
                ChatHandler(leader->GetSession()).PSendSysMessage("Bot %s has been removed from your group and will be teleported out of the instance in 60 seconds if not invited back", bot->GetName().c_str());

        bot->GetBotAI()->StartBoot();
    }

    return true;
}

bool BotMgr::RemoveAllBotsFromGroup(bool newGroup)
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        RemoveBotFromGroup(itr->second);
        itr->second->GetBotAI()->SetNeedParty(newGroup);
    }

    return true;
}

uint32 BotMgr::GetNpcBotCost(uint8 level, Creature* creature)
{
    if (!creature || !creature->GetBotAI())
        return (_npcBotsCost * level) / DEFAULT_MAX_LEVEL;

    uint32 base;
    switch (creature->GetBotAI()->GetBotClass())
    {
        case BOT_CLASS_BM:
            //base = GetNpcBotCost(level, NULL) * 9;
            //base = 100000; //10 gold
            //break;
        case BOT_CLASS_WARRIOR:
        case BOT_CLASS_PALADIN:
        case BOT_CLASS_HUNTER:
        case BOT_CLASS_ROGUE:
        case BOT_CLASS_PRIEST:
        case BOT_CLASS_DEATH_KNIGHT:
        case BOT_CLASS_SHAMAN:
        case BOT_CLASS_MAGE:
        case BOT_CLASS_WARLOCK:
        case BOT_CLASS_DRUID:
        default:
            base = 0;
            break;
    }

    return base + GetNpcBotCost(level, NULL);
}

std::string BotMgr::GetNpcBotCostStr(uint8 level, Creature* creature)
{
    std::ostringstream money;

    if (uint32 cost = GetNpcBotCost(level, creature))
    {
        uint32 gold = uint32(cost / 10000);
        cost -= (gold * 10000);
        uint32 silver = uint32(cost / 100);
        cost -= (silver * 100);

        if (gold != 0)
            money << gold << " |TInterface\\Icons\\INV_Misc_Coin_01:8|t";
        if (silver != 0)
            money << silver << " |TInterface\\Icons\\INV_Misc_Coin_03:8|t";
        if (cost)
            money << cost << " |TInterface\\Icons\\INV_Misc_Coin_05:8|t";
    }

    return money.str();
}

void BotMgr::ReviveAllBots()
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        _reviveBot(itr->second);
    }
}

void BotMgr::SendBotCommandState(CommandStates state)
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        itr->second->SetBotCommandState(state, true);
    }
}

void BotMgr::SetBotsShouldUpdateStats()
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        itr->second->SetBotShouldUpdateStats();
    }
}
