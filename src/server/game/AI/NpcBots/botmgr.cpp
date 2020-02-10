#include "bot_ai.h"
#include "botdpstracker.h"
#include "bot_Events.h"
#include "botmgr.h"
#include "botdatamgr.h"
#include "Chat.h"
#include "Config.h"
#include "GroupMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Language.h"
#include "Map.h"
#include "MapManager.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
/*
Npc Bot Manager by Trickerer (onlysuffering@gmail.com)
Player NpcBots management
TODO: Move creature hooks here
*/

//config
uint8 _basefollowdist;
uint8 _maxNpcBots;
uint8 _maxClassNpcBots;
uint8 _xpReductionNpcBots;
uint8 _healTargetIconFlags;
uint32 _npcBotsCost;
uint32 _npcBotUpdateDelayBase;
bool _enableNpcBots;
bool _enableNpcBotsDungeons;
bool _enableNpcBotsRaids;
bool _enableNpcBotsBGs;
bool _enableNpcBotsArenas;
bool _enableDungeonFinder;
bool _limitNpcBotsDungeons;
bool _limitNpcBotsRaids;
bool _botPvP;
bool _botMovementFoodInterrupt;
bool _displayEquipment;
bool _showCloak;
bool _showHelm;
bool _enableclass_blademaster;
bool _enableclass_sphynx;
bool _enableclass_archmage;
bool _enableclass_dreadlord;
bool _enableclass_spellbreaker;
bool _enableclass_darkranger;
bool _botStatLimits;
float _botStatLimits_dodge;
float _botStatLimits_parry;
float _botStatLimits_block;
float _botStatLimits_crit;
float _mult_dmg_physical;
float _mult_dmg_spell;
float _mult_healing;

bool __firstload = true;

void AddSC_death_knight_bot();
void AddSC_druid_bot();
void AddSC_hunter_bot();
void AddSC_mage_bot();
void AddSC_paladin_bot();
void AddSC_priest_bot();
void AddSC_rogue_bot();
void AddSC_shaman_bot();
void AddSC_warlock_bot();
void AddSC_warrior_bot();
void AddSC_blademaster_bot();
void AddSC_sphynx_bot();
void AddSC_archmage_bot();
void AddSC_dreadlord_bot();
void AddSC_spellbreaker_bot();
void AddSC_dark_ranger_bot();
void AddSC_archmage_bot_pets();
void AddSC_dark_ranger_bot_pets();
void AddSC_dreadlord_bot_pets();
void AddSC_hunter_bot_pets();
void AddSC_warlock_bot_pets();
void AddSC_deathknight_bot_pets();
void AddSC_priest_bot_pets();
void AddSC_shaman_bot_pets();
void AddSC_mage_bot_pets();
void AddSC_druid_bot_pets();
void AddSC_script_bot_commands();

void AddNpcBotScripts()
{
    AddSC_death_knight_bot();
    AddSC_druid_bot();
    AddSC_hunter_bot();
    AddSC_mage_bot();
    AddSC_paladin_bot();
    AddSC_priest_bot();
    AddSC_rogue_bot();
    AddSC_shaman_bot();
    AddSC_warlock_bot();
    AddSC_warrior_bot();
    AddSC_blademaster_bot();
    AddSC_sphynx_bot();
    AddSC_archmage_bot();
    AddSC_dreadlord_bot();
    AddSC_spellbreaker_bot();
    AddSC_dark_ranger_bot();
    AddSC_archmage_bot_pets();
    AddSC_dark_ranger_bot_pets();
    AddSC_dreadlord_bot_pets();
    AddSC_hunter_bot_pets();
    AddSC_warlock_bot_pets();
    AddSC_deathknight_bot_pets();
    AddSC_priest_bot_pets();
    AddSC_shaman_bot_pets();
    AddSC_mage_bot_pets();
    AddSC_druid_bot_pets();
    AddSC_script_bot_commands();
}

BotMgr::BotMgr(Player* const master) : _owner(master), _dpstracker(new DPSTracker())
{
    //LoadConfig(); already loaded (MapManager.cpp)
    _followdist = _basefollowdist;
    _exactAttackRange = 0;
    _attackRangeMode = BOT_ATTACK_RANGE_SHORT;
    _botsHidden = false;

    _dpstracker->SetOwner(master->GetGUID().GetCounter());
    master->SetBotMgr(this);
}
BotMgr::~BotMgr()
{
    delete _dpstracker;
}

void BotMgr::Initialize()
{
    LoadConfig();

    if (!_enableNpcBots)
        return;

    BotDataMgr::LoadNpcBots();
    bot_ai::InitBotCustomSpells();
}

void BotMgr::ReloadConfig()
{
    LoadConfig(true);
}

void BotMgr::LoadConfig(bool reload)
{
    if (__firstload)
        __firstload = false;
    else if (!reload)
        return;

    _enableNpcBots          = sConfigMgr->GetBoolDefault("NpcBot.Enable", true);
    _maxNpcBots             = sConfigMgr->GetIntDefault("NpcBot.MaxBots", 1);
    _maxClassNpcBots        = sConfigMgr->GetIntDefault("NpcBot.MaxBotsPerClass", 1);
    _basefollowdist         = sConfigMgr->GetIntDefault("NpcBot.BaseFollowDistance", 30);
    _xpReductionNpcBots     = sConfigMgr->GetIntDefault("NpcBot.XpReduction", 0);
    _healTargetIconFlags    = sConfigMgr->GetIntDefault("NpcBot.HealTargetIconsMask", 0);
    _mult_dmg_physical      = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Physical", 1.0f);
    _mult_dmg_spell         = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Spell", 1.0f);
    _mult_healing           = sConfigMgr->GetFloatDefault("NpcBot.Mult.Healing", 1.0f);
    _enableNpcBotsDungeons  = sConfigMgr->GetBoolDefault("NpcBot.Enable.Dungeon", true);
    _enableNpcBotsRaids     = sConfigMgr->GetBoolDefault("NpcBot.Enable.Raid", false);
    _enableNpcBotsBGs       = sConfigMgr->GetBoolDefault("NpcBot.Enable.BG", false);
    _enableNpcBotsArenas    = sConfigMgr->GetBoolDefault("NpcBot.Enable.Arena", false);
    _enableDungeonFinder    = sConfigMgr->GetBoolDefault("NpcBot.Enable.DungeonFinder", true);
    _limitNpcBotsDungeons   = sConfigMgr->GetBoolDefault("NpcBot.Limit.Dungeon", true);
    _limitNpcBotsRaids      = sConfigMgr->GetBoolDefault("NpcBot.Limit.Raid", true);
    _npcBotsCost            = sConfigMgr->GetIntDefault("NpcBot.Cost", 1000000);
    _npcBotUpdateDelayBase  = sConfigMgr->GetIntDefault("NpcBot.UpdateDelay.Base", 0);
    _botPvP                 = sConfigMgr->GetBoolDefault("NpcBot.PvP", true);
    _botMovementFoodInterrupt=sConfigMgr->GetBoolDefault("NpcBot.Movements.InterruptFood", false);
    _displayEquipment       = sConfigMgr->GetBoolDefault("NpcBot.EquipmentDisplay.Enable", true);
    _showCloak              = sConfigMgr->GetBoolDefault("NpcBot.EquipmentDisplay.ShowCloak", true);
    _showHelm               = sConfigMgr->GetBoolDefault("NpcBot.EquipmentDisplay.ShowHelm", false);
    _enableclass_blademaster= sConfigMgr->GetBoolDefault("NpcBot.NewClasses.Blademaster.Enable", true);
    _enableclass_sphynx     = sConfigMgr->GetBoolDefault("NpcBot.NewClasses.ObsidianDestroyer.Enable", true);
    _enableclass_archmage   = sConfigMgr->GetBoolDefault("NpcBot.NewClasses.Archmage.Enable", true);
    _enableclass_dreadlord  = sConfigMgr->GetBoolDefault("NpcBot.NewClasses.Dreadlord.Enable", true);
    _enableclass_spellbreaker=sConfigMgr->GetBoolDefault("NpcBot.NewClasses.SpellBreaker.Enable", true);
    _enableclass_darkranger = sConfigMgr->GetBoolDefault("NpcBot.NewClasses.DarkRanger.Enable", true);
    _botStatLimits          = sConfigMgr->GetBoolDefault("NpcBot.Stats.Limits.Enable", false);
    _botStatLimits_dodge    = sConfigMgr->GetFloatDefault("NpcBot.Stats.Limits.Dodge", 95.0f);
    _botStatLimits_parry    = sConfigMgr->GetFloatDefault("NpcBot.Stats.Limits.Parry", 95.0f);
    _botStatLimits_block    = sConfigMgr->GetFloatDefault("NpcBot.Stats.Limits.Block", 95.0f);
    _botStatLimits_crit     = sConfigMgr->GetFloatDefault("NpcBot.Stats.Limits.Crit", 95.0f);

    //limits
    _mult_dmg_physical      = std::max<float>(_mult_dmg_physical, 0.1f);
    _mult_dmg_spell         = std::max<float>(_mult_dmg_spell, 0.1f);
    _mult_healing           = std::max<float>(_mult_healing,   0.1f);
    _mult_dmg_physical      = std::min<float>(_mult_dmg_physical, 10.f);
    _mult_dmg_spell         = std::min<float>(_mult_dmg_spell, 10.f);
    _mult_healing           = std::min<float>(_mult_healing,   10.f);
}

uint8 BotMgr::GetNpcBotsCount() const
{
    //if (!inWorldOnly)
        return _bots.size();

    //CRITICAL SECTION
    //inWorldOnly is only for one-shot cases (opcodes, etc.)
    //maybe convert to (bot && bot->isInWorld()) ?
    //uint8 count = 0;
    //for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    //    if (ObjectAccessor::GetObjectInWorld(itr->first, (Creature*)nullptr))
    //        ++count;
    //return count;
}

uint8 BotMgr::GetNpcBotsCountByRole(uint16 roles) const
{
    uint8 count = 0;
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        if (itr->second && (roles & itr->second->GetBotRoles()))
            ++count;
    return count;
}

uint8 BotMgr::GetNpcBotSlotByRole(uint16 roles, Creature const* bot) const
{
    uint8 count = 0;
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        if (roles & itr->second->GetBotRoles())
        {
            if (!(roles == BOT_ROLE_DPS && (itr->second->GetBotRoles() & BOT_ROLE_TANK)))
                ++count;
            if (itr->second == bot)
                return count;
        }
    }
    return 1;
}

bool BotMgr::IsNpcBotModEnabled()
{
    return _enableNpcBots;
}

bool BotMgr::IsNpcBotDungeonFinderEnabled()
{
    return _enableDungeonFinder;
}

bool BotMgr::ShowEquippedCloak()
{
    return _showCloak;
}

bool BotMgr::ShowEquippedHelm()
{
    return _showHelm;
}

bool BotMgr::IsClassEnabled(uint8 m_class)
{
    switch (m_class)
    {
        case BOT_CLASS_BM:
            return _enableclass_blademaster;
        case BOT_CLASS_SPHYNX:
            return _enableclass_sphynx;
        case BOT_CLASS_ARCHMAGE:
            return _enableclass_archmage;
        case BOT_CLASS_DREADLORD:
            return _enableclass_dreadlord;
        case BOT_CLASS_SPELLBREAKER:
            return _enableclass_spellbreaker;
        case BOT_CLASS_DARK_RANGER:
            return _enableclass_darkranger;
        default:
            return true;
    }
}

bool BotMgr::IsBotStatsLimitsEnabled()
{
    return _botStatLimits;
}
float BotMgr::GetBotStatLimitDodge()
{
    return _botStatLimits_dodge;
}
float BotMgr::GetBotStatLimitParry()
{
    return _botStatLimits_parry;
}
float BotMgr::GetBotStatLimitBlock()
{
    return _botStatLimits_block;
}
float BotMgr::GetBotStatLimitCrit()
{
    return _botStatLimits_crit;
}

uint8 BotMgr::GetNpcBotXpReduction()
{
    return _xpReductionNpcBots;
}

uint8 BotMgr::GetMaxNpcBots()
{
    return _maxNpcBots <= MAXRAIDSIZE - 1 ? _maxNpcBots : MAXRAIDSIZE - 1;
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
        std::list<ObjectGuid>::iterator itr = _removeList.begin();

        BotMap::iterator bitr = _bots.find(*itr);
        ASSERT(bitr != _bots.end());
        _bots.erase(bitr);

        _removeList.erase(itr);
    }

    _dpstracker->Update(diff);

    if (!HaveBot())
        return;

    //ObjectGuid guid;
    Creature* bot;
    bot_ai* ai;
    bool partyCombat = IsPartyInCombat();
    bool restrictBots = RestrictBots(nullptr, false);
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        //guid = itr->first;
        bot = itr->second;
        ai = bot->GetBotAI();

        if (ai->IAmFree())
            continue;

        if (!bot->IsInWorld())
        {
            ai->CommonTimers(diff);
            continue;
        }

        if (partyCombat == false)
            ai->UpdateReviveTimer(diff);

        //bot->IsAIEnabled = true;

        if (ai->GetReviveTimer() <= diff)
        {
            if (bot->IsInWorld() && !bot->IsAlive() && _owner->IsAlive() && !_owner->IsInCombat() &&
                !_owner->IsBeingTeleported() && !_owner->InArena() && !_owner->IsInFlight() &&
                !_owner->HasFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_FEIGN_DEATH) &&
                !_owner->HasInvisibilityAura() && !_owner->HasStealthAura())
            {
                _reviveBot(bot);
                continue;
            }

            ai->SetReviveTimer(urand(1000, 5000));
        }

        if (_owner->IsAlive() && (bot->IsAlive() || restrictBots) && !ai->IsTempBot() && !ai->IsDuringTeleport() &&
            (restrictBots || bot->GetMap() != _owner->GetMap() ||
            (bot->GetBotCommandState() != COMMAND_STAY && _owner->GetDistance(bot) > SIZE_OF_GRIDS)))
        {
            //_owner->m_Controlled.erase(bot);
            TeleportBot(bot, _owner->GetMap(), _owner);
            continue;
        }

        ai->canUpdate = true;
        bot->Update(diff);
        ai->canUpdate = false;
    }
}

bool BotMgr::RestrictBots(Creature const* bot, bool add) const
{
    if (!_owner->FindMap())
        return true;

    if (_owner->IsInFlight())
        return true;

    if (_botsHidden)
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
        if (map->GetPlayersCountExceptGMs() + uint32(add) > map->GetMaxPlayers())
            return true;
    }

    return false;
}

bool BotMgr::IsPartyInCombat() const
{
    if (_owner->IsInCombat())
        return true;

    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        if (!itr->second->IsInWorld())
            continue;
        if (itr->second->IsInCombat())
            return true;
        if (Unit const* pet = itr->second->GetBotsPet())
            if (pet->IsInCombat())
                return true;
    }

    return false;
}

bool BotMgr::HasBotClass(uint8 botclass) const
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        if (itr->second->GetBotClass() == botclass)
            return true;

    return false;
}

bool BotMgr::HasBotPetType(uint32 petType) const
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        if (itr->second->GetBotsPet() && itr->second->GetBotAI()->GetAIMiscValue(BOTAI_MISC_PET_TYPE) == petType)
            return true;

    return false;
}

void BotMgr::_reviveBot(Creature* bot)
{
    if (bot->IsAlive())
        return;

    if (!bot->GetBotAI()->IAmFree())
        bot->Relocate(bot->GetBotOwner());

    bot->SetDisplayId(bot->GetNativeDisplayId());
    bot->SetUInt32Value(UNIT_NPC_FLAGS, bot->GetCreatureTemplate()->npcflag);
    bot->ClearUnitState(uint32(UNIT_STATE_ALL_STATE));
    bot->RemoveFlag(UNIT_FIELD_FLAGS, uint32(-1));
    bot->SetPvP(bot->GetBotOwner()->IsPvP());
    bot->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
    bot->setDeathState(ALIVE);
    //bot->GetBotAI()->Reset();
    bot->GetBotAI()->SetShouldUpdateStats();

    bot->SetHealth(bot->GetMaxHealth() / 4); //25% of max health
    if (bot->GetMaxPower(POWER_MANA) > 1)
        bot->SetPower(POWER_MANA, bot->GetMaxPower(POWER_MANA) / 4); //25% of max mana

    if (!bot->GetBotAI()->IAmFree())
        bot->GetBotAI()->SetBotCommandState(COMMAND_FOLLOW, true);
}

Creature* BotMgr::GetBot(ObjectGuid guid) const
{
    BotMap::const_iterator itr = _bots.find(guid);
    return itr != _bots.end() ? itr->second : nullptr;
}

void BotMgr::OnOwnerSetGameMaster(bool on)
{
    Creature* bot;
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        bot = itr->second;
        if (!bot)
            continue;

        bot->SetFaction(_owner->GetFaction());
        //bot->getHostileRefManager().setOnlineOfflineState(!on);
        bot->SetByteValue(UNIT_FIELD_BYTES_2, 1, _owner->GetByteValue(UNIT_FIELD_BYTES_2, 1)); //pvp state

        if (on && bot->IsInWorld())
            bot->CombatStop(true);

        if (Unit* pet = bot->GetBotsPet())
        {
            pet->SetFaction(_owner->GetFaction());
            //pet->getHostileRefManager().setOnlineOfflineState(!on);
            pet->SetByteValue(UNIT_FIELD_BYTES_2, 1, _owner->GetByteValue(UNIT_FIELD_BYTES_2, 1)); //pvp state

            if (on)
                pet->CombatStop(true);
        }
    }
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

        //_owner->m_Controlled.erase(bot);
        TeleportBot(bot, newMap, &pos);
    }
}

void BotMgr::_teleportBot(Creature* bot, Map* newMap, float x, float y, float z, float ori)
{
    ASSERT(bot->GetBotAI());
    bot->GetBotAI()->AbortTeleport();

    bot->GetBotAI()->UnsummonAll();
    bot->GetBotAI()->KillEvents(true);

    if (bot->IsInWorld())
    {
        //bot->MonsterWhisper("teleport...", bot->GetBotAI()->GetBotOwnerGuid());
        bot->CastSpell(bot, COSMETIC_TELEPORT_EFFECT, true);
    }

    //bot->IsAIEnabled = false;
    //UnitAI* oldAI = bot->GetAI();
    //bot->SetAI(nullptr);

    //if (bot->IsFreeBot() || bot->GetBotOwner()->GetSession()->isLogingOut())
    //{
    //    bot->FarTeleportTo(newMap, x, y, z, ori);

    //    //bot->SetAI(oldAI);
    //    bot->IsAIEnabled = true;
    //    return;
    //}

    ////start Unit::CleanupBeforeRemoveFromMap()
    bot->InterruptNonMeleeSpells(true);
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
    //bot->getHostileRefManager().setOnlineOfflineState(false);
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
        //bot->IsAIEnabled = true;
        return;
    }

    //update group member online state
    if (Group* gr = bot->GetBotOwner()->GetGroup())
        if (gr->IsMember(bot->GetGUID()))
            gr->SendUpdate();

    //bot->Relocate(x, y, z);
    TeleportFinishEvent* finishEvent = new TeleportFinishEvent(bot->GetBotAI()/*, newMap->GetId(), newMap->GetInstanceId(), x, y, z, ori*/);
    bot->GetBotAI()->GetEvents()->AddEvent(finishEvent, bot->GetBotAI()->GetEvents()->CalculateTime(urand(5000, 8000)));
    bot->GetBotAI()->SetTeleportFinishEvent(finishEvent);
}

void BotMgr::TeleportBot(Creature* bot, Map* newMap, Position* pos)
{
    _teleportBot(bot, newMap, pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), pos->GetOrientation());
}

void BotMgr::CleanupsBeforeBotDelete(ObjectGuid guid, uint8 removetype)
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
        RemoveBotFromGroup(bot, removetype); //Is this code never executed?

    //remove any summons
    bot->GetBotAI()->UnsummonAll();

    ASSERT(bot->GetOwnerGUID() == _owner->GetGUID());
    bot->SetOwnerGUID(ObjectGuid::Empty);
    //_owner->m_Controlled.erase(bot);
    bot->SetControlledByPlayer(false);
    //bot->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PVP_ATTACKABLE);
    bot->SetByteValue(UNIT_FIELD_BYTES_2, 1, 0);
    bot->SetCreatorGUID(ObjectGuid::Empty);
}

void BotMgr::_addBotToRemoveList(ObjectGuid guid)
{
    _removeList.push_back(guid);
}

void BotMgr::RemoveAllBots(uint8 removetype)
{
    while (!_bots.empty())
        RemoveBot(_bots.begin()->second->GetGUID(), removetype);
}
//Bot is being abandoned by player
void BotMgr::RemoveBot(ObjectGuid guid, uint8 removetype)
{
    BotMap::const_iterator itr = _bots.find(guid);
    ASSERT(itr != _bots.end() && "Trying to remove bot which does not belong to this botmgr(a)!!");
    ASSERT(_owner->IsInWorld() && "Trying to remove bot while not in world(a)!!");

    //trying to remove temp bot second time means removing all bots
    //just erase from bots because already cleaned up
    for (std::list<ObjectGuid>::iterator it = _removeList.begin(); it != _removeList.end(); ++it)
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
        //bot->GetBotAI()->OnBotDespawn(bot); //send to self
        _addBotToRemoveList(guid);
        return;
    }

    _bots.erase(itr);

    bot->GetBotAI()->ResetBotAI(removetype == BOT_REMOVE_DISMISS ? BOTAI_RESET_DISMISS : BOTAI_RESET_LOGOUT);

    bot->SetFaction(bot->GetCreatureTemplate()->faction);
    bot->SetLevel(bot->GetCreatureTemplate()->minlevel);

    if (removetype == BOT_REMOVE_DISMISS)
    {
        uint32 newOwner = 0;
        BotDataMgr::UpdateNpcBotData(bot->GetEntry(), NPCBOT_UPDATE_OWNER, &newOwner);
    }

    bot->GetBotAI()->Reset();
    bot->GetBotAI()->canUpdate = true;
}

BotAddResult BotMgr::AddBot(Creature* bot, bool takeMoney)
{
    ASSERT(bot->IsNPCBot());
    ASSERT(bot->GetBotAI() != nullptr);

    bool temporary = bot->GetBotAI()->IsTempBot();

    if (!_enableNpcBots)
    {
        ChatHandler ch(_owner->GetSession());
        ch.SendSysMessage("NpcBot system is currently disabled. Please contact administration.");
        //ch.SetSentErrorMessage(true);
        return BOT_ADD_DISABLED;
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
        uint32 cost = GetNpcBotCost(_owner->GetLevel(), bot);
        if (!_owner->HasEnoughMoney(cost))
        {
            ChatHandler ch(_owner->GetSession());
            std::string str = "You don't have enough money (";
            str += GetNpcBotCostStr(_owner->GetLevel(), bot);
            str += ")!";
            ch.SendSysMessage(str.c_str());
            //ch.SetSentErrorMessage(true);
            return BOT_ADD_CANT_AFFORD;
        }

        _owner->ModifyMoney(-(int32(cost)));
    }

    bot->GetBotAI()->canUpdate = false;

    if (!bot->IsAlive())
        _reviveBot(bot);

    bot->GetBotAI()->UnsummonAll();

    _bots[bot->GetGUID()] = bot;

    ASSERT(!bot->GetOwnerGUID());
    bot->SetOwnerGUID(_owner->GetGUID());
    bot->SetCreatorGUID(_owner->GetGUID()); //needed in case of FFAPVP
    //_owner->m_Controlled.insert(bot);
    bot->SetControlledByPlayer(true);
    bot->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PLAYER_CONTROLLED);
    bot->SetByteValue(UNIT_FIELD_BYTES_2, 1, _owner->GetByteValue(UNIT_FIELD_BYTES_2, 1));
    bot->SetFaction(_owner->GetFaction());
    bot->SetPhaseMask(_owner->GetPhaseMask(), true);

    bot->GetBotAI()->SetBotOwner(_owner);

    bot->GetBotAI()->Reset();

    if (!temporary)
    {
        bot->GetBotAI()->SetBotCommandState(COMMAND_FOLLOW, true);
        if (bot->GetBotAI()->HasRole(BOT_ROLE_PARTY))
            AddBotToGroup(bot);

        uint32 newOwner = _owner->GetGUID().GetCounter();
        BotDataMgr::UpdateNpcBotData(bot->GetEntry(), NPCBOT_UPDATE_OWNER, &newOwner);
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

bool BotMgr::RemoveBotFromGroup(Creature* bot, uint8 removetype)
{
    ASSERT(GetBot(bot->GetGUID()));

    Group* gr = _owner->GetGroup();
    if (!gr || !gr->IsMember(bot->GetGUID()))
        return false;

    if (bot->GetBotAI()->HasRole(BOT_ROLE_PARTY))
        bot->GetBotAI()->ToggleRole(BOT_ROLE_PARTY, true);

    //debug
    //if (gr->RemoveMember(bot->GetGUID()))
    //    TC_LOG_ERROR("entities.player", "RemoveBotFromGroup(): bot %s removed from group", bot->GetName().c_str());
    //else
    //    TC_LOG_ERROR("entities.player", "RemoveBotFromGroup(): RemoveMember() returned FALSE on bot %s", bot->GetName().c_str());

    gr->RemoveMember(bot->GetGUID());

    Map* map = _owner->FindMap();
    gr = _owner->GetGroup(); //check if group has been deleted
    if (map && map->IsDungeon() && removetype != BOT_REMOVE_DISMISS && (!gr || !gr->IsMember(bot->GetGUID()))) //make sure bot is removed from group
    {
        ChatHandler(_owner->GetSession()).PSendSysMessage("Your bot %s has been removed from your group and will be teleported out of the instance in 60 seconds if not invited back", bot->GetName().c_str());

        if (gr && _owner->GetGUID() != gr->GetLeaderGUID())
            if (Player* leader = ObjectAccessor::FindPlayer(gr->GetLeaderGUID()))
                ChatHandler(leader->GetSession()).PSendSysMessage("Bot %s has been removed from your group and will be teleported out of the instance in 60 seconds if not invited back", bot->GetName().c_str());

        bot->GetBotAI()->StartBoot();
    }

    return true;
}

bool BotMgr::RemoveAllBotsFromGroup()
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        RemoveBotFromGroup(itr->second);

    return true;
}

uint32 BotMgr::GetNpcBotCost(uint8 level, Creature const* creature)
{
    //assuming default 1000000
    //level 1: 1000
    //11 : 1666
    //15 : 8333
    //20 : 16666
    //30 : 33333
    //40 : 50000
    //rest is linear
    //rare / rareelite bots have their cost adjusted
    uint32 cost =
        level < 10 ? _npcBotsCost / 5000 : //2 silver
        level < 20 ? _npcBotsCost / 100 :  //1 gold
        level < 30 ? _npcBotsCost / 20 :   //5 gold
        level < 40 ? _npcBotsCost / 5 :    //20 gold
        (_npcBotsCost * level) / DEFAULT_MAX_LEVEL; //50 - 100 gold

    if (!creature->GetBotAI())
        return cost;

    switch (creature->GetBotClass())
    {
        case BOT_CLASS_BM:
        case BOT_CLASS_ARCHMAGE:
        case BOT_CLASS_SPELLBREAKER:
            cost += cost; //200%
            break;
        case BOT_CLASS_SPHYNX:
        case BOT_CLASS_DREADLORD:
        case BOT_CLASS_DARK_RANGER:
            cost += cost * 4; //500%
            break;
        default:
            break;
    }

    return cost;
}

std::string BotMgr::GetNpcBotCostStr(uint8 level, Creature const* creature)
{
    std::ostringstream money;

    if (uint32 cost = GetNpcBotCost(level, creature))
    {
        uint32 gold = uint32(cost / GOLD);
        cost -= (gold * GOLD);
        uint32 silver = uint32(cost / SILVER);
        cost -= (silver * SILVER);

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
        _reviveBot(itr->second);
}

void BotMgr::SendBotCommandState(CommandStates state)
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        itr->second->SetBotCommandState(state, true);
}

void BotMgr::RecallAllBots()
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        if (itr->second->IsInWorld() && itr->second->IsAlive() && !bot_ai::CCed(itr->second, true))
            itr->second->GetMotionMaster()->MovePoint(_owner->GetMapId(), *_owner, false);
}

void BotMgr::RecallBot(Creature* bot)
{
    ASSERT(GetBot(bot->GetGUID()));

    if (bot->IsInWorld() && bot->IsAlive() && !bot_ai::CCed(bot, true))
        bot->GetMotionMaster()->MovePoint(_owner->GetMapId(), *_owner, false);
}

void BotMgr::KillAllBots()
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        KillBot(itr->second);
}

void BotMgr::KillBot(Creature* bot)
{
    ASSERT(GetBot(bot->GetGUID()));

    if (bot->IsInWorld() && bot->IsAlive())
    {
        bot->setDeathState(JUST_DIED);
        bot->GetBotAI()->JustDied(bot);
        //bot->Kill(bot);
    }
}

void BotMgr::SetBotsShouldUpdateStats()
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        itr->second->GetBotAI()->SetShouldUpdateStats();
}

void BotMgr::UpdatePhaseForBots()
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        itr->second->SetPhaseMask(_owner->GetPhaseMask(), itr->second->IsInWorld());
        if (itr->second->GetBotsPet())
            itr->second->GetBotsPet()->SetPhaseMask(_owner->GetPhaseMask(), true); //only if in world
    }
}

void BotMgr::UpdatePvPForBots()
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        itr->second->SetByteValue(UNIT_FIELD_BYTES_2, 1, _owner->GetByteValue(UNIT_FIELD_BYTES_2, 1));
        if (itr->second->GetBotsPet())
            itr->second->GetBotsPet()->SetByteValue(UNIT_FIELD_BYTES_2, 1, _owner->GetByteValue(UNIT_FIELD_BYTES_2, 1));
    }
}

void BotMgr::TrackDamage(Unit const* u, uint32 damage)
{
    _dpstracker->TrackDamage(u, damage);
}

uint32 BotMgr::GetDPSTaken(Unit const* u) const
{
    return _dpstracker->GetDPSTaken(u->GetGUID().GetRawValue());
}

int32 BotMgr::GetHPSTaken(Unit const* unit) const
{
    if (!HaveBot())
        return 0;

    std::list<Unit*> unitList;
    Group const* gr = _owner->GetGroup();
    if (!gr)
    {
        if (_owner->HasUnitState(UNIT_STATE_CASTING))
            unitList.push_back(_owner);
        for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
            if (itr->second->GetTarget() == unit->GetGUID() && itr->second->HasUnitState(UNIT_STATE_CASTING))
                unitList.push_back(itr->second);
    }
    else
    {
        bool Bots = false;
        for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player* player = itr->GetSource();
            if (player == nullptr) continue;
            if (_owner->GetMap() != player->FindMap()) continue;
            if (!Bots)
                Bots = true;
            if (player->HasUnitState(UNIT_STATE_CASTING))
                unitList.push_back(player);
        }
        if (Bots)
        {
            for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                if (itr->GetSource() == nullptr) continue;
                if (_owner->GetMap() != itr->GetSource()->FindMap()) continue;

                if (itr->GetSource()->HaveBot())
                {
                    BotMap const* map = itr->GetSource()->GetBotMgr()->GetBotMap();
                    for (BotMap::const_iterator itr = map->begin(); itr != map->end(); ++itr)
                        if (itr->second->GetTarget() == unit->GetGUID() && itr->second->HasUnitState(UNIT_STATE_CASTING))
                            unitList.push_back(itr->second);
                }
            }
        }
    }

    int32 amount = 0;

    Unit* u;
    Spell const* spell;
    SpellInfo const* spellInfo;
    for (std::list<Unit*>::const_iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
    {
        u = *itr;

        for (uint8 i = CURRENT_FIRST_NON_MELEE_SPELL; i != CURRENT_AUTOREPEAT_SPELL; ++i)
        {
            spell = u->GetCurrentSpell(CurrentSpellTypes(i));
            if (!spell)
                continue;

            ObjectGuid targetGuid = spell->m_targets.GetObjectTargetGUID();
            if (!targetGuid || !targetGuid.IsUnit())
                continue;

            if (targetGuid != unit->GetGUID())
            {
                if (!gr || !gr->IsMember(unit->GetGUID()))
                    continue;
            }

            spellInfo = spell->GetSpellInfo();

            for (uint8 j = 0; j != MAX_SPELL_EFFECTS; ++j)
            {
                if (spellInfo->Effects[j].Effect != SPELL_EFFECT_HEAL)
                    continue;

                if (targetGuid != unit->GetGUID())
                {
                    if (spellInfo->Effects[j].TargetA.GetSelectionCategory() != TARGET_SELECT_CATEGORY_AREA)
                        continue;

                    //Targets t = spellInfo->Effects[j].TargetA.GetTarget();
                    //non-existing case
                    //if (t == TARGET_UNIT_CASTER_AREA_PARTY && !gr->SameSubGroup(u->GetGUID(), unit->GetGUID()))
                    //    continue;
                    Targets t = spellInfo->Effects[j].TargetB.GetTarget();
                    if (t == TARGET_UNIT_LASTTARGET_AREA_PARTY &&
                        !(GetBot(unit->GetGUID()) && GetBot(targetGuid)) &&
                        !gr->SameSubGroup(unit->GetGUID(), targetGuid))
                        continue;
                }

                //do not get target which may be invalid, use caster instead
                int32 healing = u->SpellHealingBonusDone(u, spellInfo, spellInfo->Effects[0].CalcValue(u), HEAL, 0, nullptr);

                if (i == CURRENT_CHANNELED_SPELL)
                    amount += healing / (spellInfo->Effects[j].Amplitude * 0.001f);
                else
                    amount += healing / (std::max<int32>(spell->GetTimer(), 1000) * 0.001f);

                //TC_LOG_ERROR("entities.player", "BotMgr:pendingHeals: found %s's %s on %s in %u (%i, total %i)",
                //    u->GetName().c_str(), spellInfo->SpellName[0], target->GetName().c_str(), pheal->delay, healing, pheal->amount);
            }

            break;
        }
    }

    //HoTs
    Unit::AuraEffectList const& hots = unit->GetAuraEffectsByType(SPELL_AURA_PERIODIC_HEAL);
    for (Unit::AuraEffectList::const_iterator itr = hots.begin(); itr != hots.end(); ++itr)
        amount += (*itr)->GetAmount() / ((*itr)->GetAmplitude() * 0.001f);

    //if (amount != 0)
    //    TC_LOG_ERROR("entities.player", "BotMgr:GetHPSTaken(): %s got %i)", unit->GetName().c_str(), amount);

    return amount;
}

void BotMgr::OnBotDamageDealt(Unit* attacker, Unit* victim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellInfo const* spellInfo)
{
    attacker->ToCreature()->GetBotAI()->OnBotDamageDealt(victim, damage, cleanDamage, damagetype, spellInfo);
}

void BotMgr::OnBotDispelDealt(Unit* dispeller, Unit* dispelled, uint8 num)
{
    dispeller->ToCreature()->GetBotAI()->OnBotDispelDealt(dispelled, num);
}

void BotMgr::ApplyBotEffectMods(Unit const* caster, Unit const* target, SpellInfo const* spellInfo, uint8 effIndex, float& value)
{
    caster->ToCreature()->GetBotAI()->ApplyBotEffectMods(target, spellInfo, effIndex, value);
}

float BotMgr::GetBotDamageTakenMod(Creature const* bot, bool magic)
{
    return bot->GetBotAI()->GetBotDamageTakenMod(magic);
}

float BotMgr::GetBotDamageModPhysical()
{
    return _mult_dmg_physical;
}
float BotMgr::GetBotDamageModSpell()
{
    return _mult_dmg_spell;
}
