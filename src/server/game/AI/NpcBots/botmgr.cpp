#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "bot_ai.h"
#include "bot_Events.h"
#include "botdatamgr.h"
#include "botdpstracker.h"
#include "botlog.h"
#include "botmgr.h"
#include "botspell.h"
#include "bottext.h"
#include "bpet_ai.h"
#include "Chat.h"
#include "CombatPackets.h"
#include "Config.h"
#include "GroupMgr.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "InstanceScript.h"
#include "Language.h"
#include "Log.h"
#include "Map.h"
#include "MapManager.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "Vehicle.h"
#include "Transport.h"
#include "World.h"
#include "revision_data.h"
/*
Npc Bot Manager by Trickerer (onlysuffering@gmail.com)
Player NpcBots management
TODO: Move creature hooks here
*/

#ifdef _MSC_VER
# pragma warning(push, 4)
#endif

#ifdef AC_COMPILER
# define GetBoolDefault GetOption<bool>
# define GetIntDefault GetOption<int32>
# define GetFloatDefault GetOption<float>
# define GetStringDefault GetOption<std::string>
#endif

static std::list<BotMgr::delayed_teleport_callback_type> delayed_bot_teleports;

//config
uint8 _basefollowdist;
uint8 _maxClassNpcBots;
uint8 _maxAccountNpcBots;
uint8 _xpReductionAmount;
uint8 _xpReductionStartingNumber;
uint8 _mountLevel60;
uint8 _mountLevel100;
uint8 _healTargetIconFlags;
uint8 _tankingTargetIconFlags;
uint8 _offTankingTargetIconFlags;
uint8 _dpsTargetIconFlags;
uint8 _rangedDpsTargetIconFlags;
uint8 _noDpsTargetIconFlags;
uint8 _npcBotOwnerExpireMode;
int32 _botInfoPacketsLimit;
uint32 _npcBotsCost;
uint32 _npcBotUpdateDelayBase;
uint32 _npcBotEngageDelayDPS_default;
uint32 _npcBotEngageDelayHeal_default;
uint32 _npcBotOwnerExpireTime;
uint32 _desiredWanderingBotsCount;
uint32 _targetBGPlayersPerTeamCount_AV;
uint32 _targetBGPlayersPerTeamCount_WS;
uint32 _targetBGPlayersPerTeamCount_AB;
uint32 _targetBGPlayersPerTeamCount_EY;
uint32 _targetBGPlayersPerTeamCount_SA;
uint32 _targetBGPlayersPerTeamCount_IC;
bool _enableNpcBots;
bool _logToDB;
bool _enableNpcBotsDungeons;
bool _enableNpcBotsRaids;
bool _enableNpcBotsBGs;
bool _enableNpcBotsArenas;
bool _enableDungeonFinder;
bool _enableNpcBotsPremade;
bool _limitNpcBotsDungeons;
bool _limitNpcBotsRaids;
bool _hideSpawns;
bool _botPvP;
bool _botMovementFoodInterrupt;
bool _filterRaces;
bool _displayEquipment;
bool _showCloak;
bool _showHelm;
bool _sendEquipListItems;
bool _enableBotGearBank;
bool _transmog_enable;
bool _transmog_mixArmorClasses;
bool _transmog_mixWeaponClasses;
bool _transmog_mixWeaponInvTypes;
bool _transmog_useEquipmentSlots;
bool _enableclass_warrior;
bool _enableclass_paladin;
bool _enableclass_hunter;
bool _enableclass_rogue;
bool _enableclass_priest;
bool _enableclass_deathknight;
bool _enableclass_shaman;
bool _enableclass_mage;
bool _enableclass_warlock;
bool _enableclass_druid;
bool _enableclass_blademaster;
bool _enableclass_sphynx;
bool _enableclass_archmage;
bool _enableclass_dreadlord;
bool _enableclass_spellbreaker;
bool _enableclass_darkranger;
bool _enableclass_necromancer;
bool _enableclass_seawitch;
bool _enableclass_cryptlord;
bool _enableclass_wander_warrior;
bool _enableclass_wander_paladin;
bool _enableclass_wander_hunter;
bool _enableclass_wander_rogue;
bool _enableclass_wander_priest;
bool _enableclass_wander_deathknight;
bool _enableclass_wander_shaman;
bool _enableclass_wander_mage;
bool _enableclass_wander_warlock;
bool _enableclass_wander_druid;
bool _enableclass_wander_blademaster;
bool _enableclass_wander_sphynx;
bool _enableclass_wander_archmage;
bool _enableclass_wander_dreadlord;
bool _enableclass_wander_spellbreaker;
bool _enableclass_wander_darkranger;
bool _enableclass_wander_necromancer;
bool _enableclass_wander_seawitch;
bool _enableclass_wander_cryptlord;
bool _enrageOnDismiss;
bool _botStatLimits;
bool _enableWanderingBotsBG;
bool _enableConfigLevelCapBG;
bool _enableConfigLevelCapBGFirst;
bool _bothk_enable;
bool _bothk_message_enable;
bool _bothk_achievements_enable;
bool _untarget_wnpc_questgiver;
bool _untarget_wnpc_flightmaster;
float _botStatLimits_dodge;
float _botStatLimits_parry;
float _botStatLimits_block;
float _botStatLimits_crit;
float _mult_dmg_physical;
float _mult_dmg_spell;
float _mult_healing;
float _mult_hp;
float _mult_dmg_wanderer;
float _mult_healing_wanderer;
float _mult_hp_wanderer;
float _mult_speed_wanderer;
float _mult_xpgain_wanderer;
float _mult_dmg_warrior;
float _mult_dmg_paladin;
float _mult_dmg_hunter;
float _mult_dmg_rogue;
float _mult_dmg_priest;
float _mult_dmg_deathknight;
float _mult_dmg_shaman;
float _mult_dmg_mage;
float _mult_dmg_warlock;
float _mult_dmg_druid;
float _mult_dmg_blademaster;
float _mult_dmg_obsidiandestroyer;
float _mult_dmg_archmage;
float _mult_dmg_dreadlord;
float _mult_dmg_spellbreaker;
float _mult_dmg_darkranger;
float _mult_dmg_necromancer;
float _mult_dmg_seawitch;
float _mult_dmg_cryptlord;
float _bothk_rate_honor;
std::vector<float> _mult_dmg_levels;
LvlBrackets _max_npcbots;
PctBrackets _botwanderer_pct_level_brackets;
std::vector<uint32> _disabled_instance_maps;
std::vector<uint32> _enabled_wander_node_maps;

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
void AddSC_necromancer_bot();
void AddSC_sea_witch_bot();
void AddSC_crypt_lord_bot();
void AddSC_archmage_bot_pets();
void AddSC_dreadlord_bot_pets();
void AddSC_dark_ranger_bot_pets();
void AddSC_necromancer_bot_pets();
void AddSC_sea_witch_bot_pets();
void AddSC_crypt_lord_bot_pets();
void AddSC_hunter_bot_pets();
void AddSC_warlock_bot_pets();
void AddSC_deathknight_bot_pets();
void AddSC_priest_bot_pets();
void AddSC_shaman_bot_pets();
void AddSC_mage_bot_pets();
void AddSC_druid_bot_pets();
void AddSC_script_bot_commands();
void AddSC_script_bot_giver();
void AddSC_botdatamgr_scripts();

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
    AddSC_necromancer_bot();
    AddSC_sea_witch_bot();
    AddSC_crypt_lord_bot();
    AddSC_archmage_bot_pets();
    AddSC_dreadlord_bot_pets();
    AddSC_dark_ranger_bot_pets();
    AddSC_necromancer_bot_pets();
    AddSC_sea_witch_bot_pets();
    AddSC_crypt_lord_bot_pets();
    AddSC_hunter_bot_pets();
    AddSC_warlock_bot_pets();
    AddSC_deathknight_bot_pets();
    AddSC_priest_bot_pets();
    AddSC_shaman_bot_pets();
    AddSC_mage_bot_pets();
    AddSC_druid_bot_pets();
    AddSC_script_bot_commands();
    AddSC_script_bot_giver();
    AddSC_botdatamgr_scripts();
}

BotMgr::BotMgr(Player* const master) : _owner(master), _dpstracker(new DPSTracker())
{
    _quickrecall = false;
    _data = nullptr;
}
BotMgr::~BotMgr()
{
    if (_data)
        _data->flags &= NPCBOT_MGR_FLAG_MASK_ALL_DB_ALLOWED;

    delete _dpstracker;
}

void BotMgr::LoadData()
{
    ASSERT(!_data, "Trying to load player %u data a second time", _owner->GetGUID().GetCounter());
    _data = BotDataMgr::SelectOrCreateNpcBotMgrData(_owner->GetGUID());
}

void BotMgr::Initialize()
{
    LoadConfig();
    BotLogger::Log(NPCBOT_LOG_SYSTEM_START, uint32(0), std::string_view{ VER_FILEVERSION_STR }.substr(0, MAX_BOT_LOG_PARAM_LENGTH));

    BotDataMgr::LoadNpcBots();
    BotDataMgr::LoadWanderMap();
    BotDataMgr::GenerateWanderingBots();
    BotDataMgr::CreateWanderingBotsSortedGear();
    BotDataMgr::LoadNpcBotGroupData();
    BotDataMgr::LoadNpcBotGearStorage();
    BotDataMgr::LoadNpcBotMgrData();
    BotDataMgr::DeleteOldLogs();

    ResolveConfigConflicts();
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

    _enableNpcBots                  = sConfigMgr->GetBoolDefault("NpcBot.Enable", true);
    _logToDB                        = sConfigMgr->GetBoolDefault("NpcBot.LogToDB", true);
    _maxClassNpcBots                = sConfigMgr->GetIntDefault("NpcBot.MaxBotsPerClass", 1);
    _maxAccountNpcBots              = sConfigMgr->GetIntDefault("NpcBot.MaxBotsPerAccount", 0);
    _filterRaces                    = sConfigMgr->GetBoolDefault("NpcBot.Botgiver.FilterRaces", false);
    _basefollowdist                 = sConfigMgr->GetIntDefault("NpcBot.BaseFollowDistance", 30);
    _xpReductionAmount              = sConfigMgr->GetIntDefault("NpcBot.XpReduction.Amount", 0);
    _xpReductionStartingNumber      = sConfigMgr->GetIntDefault("NpcBot.XpReduction.StartingNumber", 2);
    _mountLevel60                   = sConfigMgr->GetIntDefault("NpcBot.MountLevel.60", 20);
    _mountLevel100                  = sConfigMgr->GetIntDefault("NpcBot.MountLevel.100", 40);
    _healTargetIconFlags            = sConfigMgr->GetIntDefault("NpcBot.HealTargetIconMask", 0);
    _tankingTargetIconFlags         = sConfigMgr->GetIntDefault("NpcBot.TankTargetIconMask", 0);
    _offTankingTargetIconFlags      = sConfigMgr->GetIntDefault("NpcBot.OffTankTargetIconMask", 0);
    _dpsTargetIconFlags             = sConfigMgr->GetIntDefault("NpcBot.DPSTargetIconMask", 0);
    _rangedDpsTargetIconFlags       = sConfigMgr->GetIntDefault("NpcBot.RangedDPSTargetIconMask", 0);
    _noDpsTargetIconFlags           = sConfigMgr->GetIntDefault("NpcBot.NoDPSTargetIconMask", 0);
    _mult_dmg_physical              = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Physical", 1.0f);
    _mult_dmg_spell                 = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Spell", 1.0f);
    _mult_healing                   = sConfigMgr->GetFloatDefault("NpcBot.Mult.Healing", 1.0f);
    _mult_hp                        = sConfigMgr->GetFloatDefault("NpcBot.Mult.HP", 1.0f);
    _mult_dmg_wanderer              = sConfigMgr->GetFloatDefault("NpcBot.Mult.Wanderer.Damage", 1.0f);
    _mult_healing_wanderer          = sConfigMgr->GetFloatDefault("NpcBot.Mult.Wanderer.Healing", 1.0f);
    _mult_hp_wanderer               = sConfigMgr->GetFloatDefault("NpcBot.Mult.Wanderer.HP", 1.0f);
    _mult_speed_wanderer            = sConfigMgr->GetFloatDefault("NpcBot.Mult.Wanderer.Speed", 1.0f);
    _mult_dmg_warrior               = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Warrior", 1.0f);
    _mult_dmg_paladin               = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Paladin", 1.0f);
    _mult_dmg_hunter                = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Hunter", 1.0f);
    _mult_dmg_rogue                 = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Rogue", 1.0f);
    _mult_dmg_priest                = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Priest", 1.0f);
    _mult_dmg_deathknight           = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.DeathKnight", 1.0f);
    _mult_dmg_shaman                = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Shaman", 1.0f);
    _mult_dmg_mage                  = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Mage", 1.0f);
    _mult_dmg_warlock               = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Warlock", 1.0f);
    _mult_dmg_druid                 = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Druid", 1.0f);
    _mult_dmg_blademaster           = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Blademaster", 1.0f);
    _mult_dmg_obsidiandestroyer     = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.ObsidianDestroyer", 1.0f);
    _mult_dmg_archmage              = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Archmage", 1.0f);
    _mult_dmg_dreadlord             = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Dreadlord", 1.0f);
    _mult_dmg_spellbreaker          = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.SpellBreaker", 1.0f);
    _mult_dmg_darkranger            = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.DarkRanger", 1.0f);
    _mult_dmg_necromancer           = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.Necromancer", 1.0f);
    _mult_dmg_seawitch              = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.SeaWitch", 1.0f);
    _mult_dmg_cryptlord             = sConfigMgr->GetFloatDefault("NpcBot.Mult.Damage.CryptLord", 1.0f);
    _enableNpcBotsDungeons          = sConfigMgr->GetBoolDefault("NpcBot.Enable.Dungeon", true);
    _enableNpcBotsRaids             = sConfigMgr->GetBoolDefault("NpcBot.Enable.Raid", false);
    _enableNpcBotsBGs               = sConfigMgr->GetBoolDefault("NpcBot.Enable.BG", false);
    _enableNpcBotsArenas            = sConfigMgr->GetBoolDefault("NpcBot.Enable.Arena", false);
    _enableDungeonFinder            = sConfigMgr->GetBoolDefault("NpcBot.Enable.DungeonFinder", true);
    _enableNpcBotsPremade           = sConfigMgr->GetBoolDefault("NpcBot.Premade.Enable", false);
    _limitNpcBotsDungeons           = sConfigMgr->GetBoolDefault("NpcBot.Limit.Dungeon", true);
    _limitNpcBotsRaids              = sConfigMgr->GetBoolDefault("NpcBot.Limit.Raid", true);
    _hideSpawns                     = sConfigMgr->GetBoolDefault("NpcBot.HideSpawns", false);
    _botInfoPacketsLimit            = sConfigMgr->GetIntDefault("NpcBot.InfoPacketsLimit", -1);
    _npcBotsCost                    = sConfigMgr->GetIntDefault("NpcBot.Cost", 1000000);
    _npcBotUpdateDelayBase          = sConfigMgr->GetIntDefault("NpcBot.UpdateDelay.Base", 0);
    _npcBotEngageDelayDPS_default   = sConfigMgr->GetIntDefault("NpcBot.EngageDelay.DPS", 0);
    _npcBotEngageDelayHeal_default  = sConfigMgr->GetIntDefault("NpcBot.EngageDelay.Heal", 0);
    _npcBotOwnerExpireTime          = sConfigMgr->GetIntDefault("NpcBot.OwnershipExpireTime", 0);
    _npcBotOwnerExpireMode          = sConfigMgr->GetIntDefault("NpcBot.OwnershipExpireMode", 0);
    _botPvP                         = sConfigMgr->GetBoolDefault("NpcBot.PvP", true);
    _botMovementFoodInterrupt       = sConfigMgr->GetBoolDefault("NpcBot.Movements.InterruptFood", false);
    _displayEquipment               = sConfigMgr->GetBoolDefault("NpcBot.EquipmentDisplay.Enable", true);
    _showCloak                      = sConfigMgr->GetBoolDefault("NpcBot.EquipmentDisplay.ShowCloak", true);
    _showHelm                       = sConfigMgr->GetBoolDefault("NpcBot.EquipmentDisplay.ShowHelm", false);
    _sendEquipListItems             = sConfigMgr->GetBoolDefault("NpcBot.Gossip.ShowEquipmentListItems", false);
    _enableBotGearBank              = sConfigMgr->GetBoolDefault("NpcBot.GearBank.Enable", false);
    _transmog_enable                = sConfigMgr->GetBoolDefault("NpcBot.Transmog.Enable", false);
    _transmog_mixArmorClasses       = sConfigMgr->GetBoolDefault("NpcBot.Transmog.MixArmorClasses", false);
    _transmog_mixWeaponClasses      = sConfigMgr->GetBoolDefault("NpcBot.Transmog.MixWeaponClasses", false);
    _transmog_mixWeaponInvTypes     = sConfigMgr->GetBoolDefault("NpcBot.Transmog.MixWeaponInventoryTypes", false);
    _transmog_useEquipmentSlots     = sConfigMgr->GetBoolDefault("NpcBot.Transmog.UseEquipmentSlots", false);
    _enableclass_warrior            = sConfigMgr->GetBoolDefault("NpcBot.Classes.Warrior.Enable", true);
    _enableclass_paladin            = sConfigMgr->GetBoolDefault("NpcBot.Classes.Paladin.Enable", true);
    _enableclass_hunter             = sConfigMgr->GetBoolDefault("NpcBot.Classes.Hunter.Enable", true);
    _enableclass_rogue              = sConfigMgr->GetBoolDefault("NpcBot.Classes.Rogue.Enable", true);
    _enableclass_priest             = sConfigMgr->GetBoolDefault("NpcBot.Classes.Priest.Enable", true);
    _enableclass_deathknight        = sConfigMgr->GetBoolDefault("NpcBot.Classes.DeathKnight.Enable", true);
    _enableclass_shaman             = sConfigMgr->GetBoolDefault("NpcBot.Classes.Shaman.Enable", true);
    _enableclass_mage               = sConfigMgr->GetBoolDefault("NpcBot.Classes.Mage.Enable", true);
    _enableclass_warlock            = sConfigMgr->GetBoolDefault("NpcBot.Classes.Warlock.Enable", true);
    _enableclass_druid              = sConfigMgr->GetBoolDefault("NpcBot.Classes.Druid.Enable", true);
    _enableclass_blademaster        = false; // sConfigMgr->GetBoolDefault("NpcBot.Classes.Blademaster.Enable", false);
    _enableclass_sphynx             = sConfigMgr->GetBoolDefault("NpcBot.Classes.ObsidianDestroyer.Enable", true);
    _enableclass_archmage           = sConfigMgr->GetBoolDefault("NpcBot.Classes.Archmage.Enable", true);
    _enableclass_dreadlord          = sConfigMgr->GetBoolDefault("NpcBot.Classes.Dreadlord.Enable", true);
    _enableclass_spellbreaker       = sConfigMgr->GetBoolDefault("NpcBot.Classes.SpellBreaker.Enable", true);
    _enableclass_darkranger         = sConfigMgr->GetBoolDefault("NpcBot.Classes.DarkRanger.Enable", true);
    _enableclass_necromancer        = sConfigMgr->GetBoolDefault("NpcBot.Classes.Necromancer.Enable", true);
    _enableclass_seawitch           = sConfigMgr->GetBoolDefault("NpcBot.Classes.SeaWitch.Enable", true);
    _enableclass_cryptlord          = sConfigMgr->GetBoolDefault("NpcBot.Classes.CryptLord.Enable", true);
    _enableclass_wander_warrior     = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Warrior.Enable", true);
    _enableclass_wander_paladin     = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Paladin.Enable", true);
    _enableclass_wander_hunter      = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Hunter.Enable", true);
    _enableclass_wander_rogue       = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Rogue.Enable", true);
    _enableclass_wander_priest      = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Priest.Enable", true);
    _enableclass_wander_deathknight = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.DeathKnight.Enable", true);
    _enableclass_wander_shaman      = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Shaman.Enable", true);
    _enableclass_wander_mage        = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Mage.Enable", true);
    _enableclass_wander_warlock     = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Warlock.Enable", true);
    _enableclass_wander_druid       = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Druid.Enable", true);
    _enableclass_wander_blademaster = false; // sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Blademaster.Enable", false);
    _enableclass_wander_sphynx      = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.ObsidianDestroyer.Enable", true);
    _enableclass_wander_archmage    = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Archmage.Enable", true);
    _enableclass_wander_dreadlord   = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Dreadlord.Enable", true);
    _enableclass_wander_spellbreaker= sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.SpellBreaker.Enable", true);
    _enableclass_wander_darkranger  = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.DarkRanger.Enable", true);
    _enableclass_wander_necromancer = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.Necromancer.Enable", true);
    _enableclass_wander_seawitch    = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.SeaWitch.Enable", true);
    _enableclass_wander_cryptlord   = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.Classes.CryptLord.Enable", true);
    _untarget_wnpc_questgiver       = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.SkipTarget.Questgiver", false);
    _untarget_wnpc_flightmaster     = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.SkipTarget.Flightmaster", false);
    _enrageOnDismiss                = sConfigMgr->GetBoolDefault("NpcBot.EnrageOnDismiss", true);
    _botStatLimits                  = sConfigMgr->GetBoolDefault("NpcBot.Stats.Limits.Enable", false);
    _botStatLimits_dodge            = sConfigMgr->GetFloatDefault("NpcBot.Stats.Limits.Dodge", 95.0f);
    _botStatLimits_parry            = sConfigMgr->GetFloatDefault("NpcBot.Stats.Limits.Parry", 95.0f);
    _botStatLimits_block            = sConfigMgr->GetFloatDefault("NpcBot.Stats.Limits.Block", 95.0f);
    _botStatLimits_crit             = sConfigMgr->GetFloatDefault("NpcBot.Stats.Limits.Crit", 95.0f);
    _desiredWanderingBotsCount      = sConfigMgr->GetIntDefault("NpcBot.WanderingBots.Continents.Count", 0);
    _mult_xpgain_wanderer           = sConfigMgr->GetFloatDefault("NpcBot.WanderingBots.Continents.XPGain", 1.0f);
    _enableWanderingBotsBG          = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.BG.Enable", false);
    _enableConfigLevelCapBG         = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.BG.CapLevel", false);
    _enableConfigLevelCapBGFirst    = sConfigMgr->GetBoolDefault("NpcBot.WanderingBots.BG.CapLevelByFirstPlayer", false);
    _targetBGPlayersPerTeamCount_AV = sConfigMgr->GetIntDefault("NpcBot.WanderingBots.BG.TargetTeamPlayersCount.AV", 0);
    _targetBGPlayersPerTeamCount_WS = sConfigMgr->GetIntDefault("NpcBot.WanderingBots.BG.TargetTeamPlayersCount.WS", 8);
    _targetBGPlayersPerTeamCount_AB = sConfigMgr->GetIntDefault("NpcBot.WanderingBots.BG.TargetTeamPlayersCount.AB", 12);
    _targetBGPlayersPerTeamCount_EY = sConfigMgr->GetIntDefault("NpcBot.WanderingBots.BG.TargetTeamPlayersCount.EY", 0);
    _targetBGPlayersPerTeamCount_SA = sConfigMgr->GetIntDefault("NpcBot.WanderingBots.BG.TargetTeamPlayersCount.SA", 0);
    _targetBGPlayersPerTeamCount_IC = sConfigMgr->GetIntDefault("NpcBot.WanderingBots.BG.TargetTeamPlayersCount.IC", 0);
    _bothk_enable                   = sConfigMgr->GetBoolDefault("NpcBot.HK.Enable", true);
    _bothk_message_enable           = sConfigMgr->GetBoolDefault("NpcBot.HK.Message.Enable", false);
    _bothk_achievements_enable      = sConfigMgr->GetBoolDefault("NpcBot.HK.Achievements.Enable", false);
    _bothk_rate_honor               = sConfigMgr->GetFloatDefault("NpcBot.HK.Rate.Honor", 1.0);

    if (reload)
        BotLogger::Log(NPCBOT_LOG_CONFIG_RELOAD, uint32(0));

    _max_npcbots = {};
    std::string max_npcbots_by_levels = sConfigMgr->GetStringDefault("NpcBot.MaxBots", "1,1,1,1,1,1,1,1,1");
    std::vector<std::string_view> toks0 = Trinity::Tokenize(max_npcbots_by_levels, ',', false);
    ASSERT(toks0.size() == BracketsCount, "NpcBot.MaxBots must have exactly %u values", uint32(BracketsCount));
    for (decltype(toks0)::size_type i = 0; i != toks0.size(); ++i)
    {
        Optional<uint8> val = Trinity::StringTo<uint8>(toks0[i]);
        if (val == std::nullopt)
            TC_LOG_ERROR("server.loading", "NpcBot.MaxBots contains invalid uint8 value '{}', set to default", toks0[i]);
        uint8 uval = val.value_or(uint8(0));
        if (i > 0)
        {
            uint8 prev = _max_npcbots[i - 1];
            if (prev > uval)
            {
                TC_LOG_WARN("server.loading", "NpcBot.MaxBots value at offset {} is {} which is lower than previous value {}!", uint32(i), uint32(uval), uint32(prev));
                //uval = prev;
            }
            if (uval >= MAX_RAID_SIZE)
            {
                TC_LOG_ERROR("server.loading", "NpcBot.MaxBots value at offset {} is {} > 39, enforcing max value!", uint32(i), uint32(uval));
                uval = uint8(MAX_RAID_SIZE - 1);
            }
        }
        _max_npcbots[i] = uval;
    }

    _mult_dmg_levels.clear();
    std::string mult_dps_by_levels = sConfigMgr->GetStringDefault("NpcBot.Mult.Damage.Levels", "1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0");
    std::vector<std::string_view> toks1 = Trinity::Tokenize(mult_dps_by_levels, ',', false);
    ASSERT(toks1.size() >= BracketsCount, "NpcBot.Mult.Damage.Levels must have at least %u values", uint32(BracketsCount));
    for (decltype(toks1)::size_type i = 0; i != toks1.size(); ++i)
    {
        Optional<float> val = Trinity::StringTo<float>(toks1[i]);
        if (val == std::nullopt)
            TC_LOG_ERROR("server.loading", "NpcBot.Mult.Damage.Levels contains invalid float value '{}', set to default", toks1[i]);
        float fval = val.value_or(1.0f);
        RoundToInterval(fval, 0.1f, 10.f);
        _mult_dmg_levels.push_back(fval);
    }

    _botwanderer_pct_level_brackets = {};
    std::string wanderers_by_levels = sConfigMgr->GetStringDefault("NpcBot.WanderingBots.Continents.Levels", "20,15,15,10,10,15,15,0,0");
    std::vector<std::string_view> toks2 = Trinity::Tokenize(wanderers_by_levels, ',', false);
    ASSERT(toks2.size() == BracketsCount, "NpcBot.WanderingBots.Continents.Levels must have exactly %u values", uint32(BracketsCount));
    uint32 total_pct = 0;
    for (decltype(toks2)::size_type i = 0; i != toks2.size(); ++i)
    {
        Optional<uint32> val = Trinity::StringTo<uint32>(toks2[i]);
        if (val == std::nullopt)
            TC_LOG_ERROR("server.loading", "NpcBot.Mult.Damage.Levels contains invalid uint32 value '{}', set to default", toks2[i]);
        uint32 uval = val.value_or(uint32(0));
        total_pct += uval;
        _botwanderer_pct_level_brackets[i] = uval;
    }
    ASSERT(total_pct == 100u, "NpcBot.WanderingBots.Continents.Levels sum of values must be exactly 100!");

    _enabled_wander_node_maps.clear();
    std::string enabled_wander_node_maps = sConfigMgr->GetStringDefault("NpcBot.WanderingBots.Continents.Maps", "0,1,530,571");
    std::vector<std::string_view> toks3 = Trinity::Tokenize(enabled_wander_node_maps, ',', false);
    for (decltype(toks3)::size_type i = 0; i != toks3.size(); ++i)
    {
        Optional<uint32> val = Trinity::StringTo<uint32>(toks3[i]);
        if (val == std::nullopt)
        {
            TC_LOG_ERROR("server.loading", "NpcBot.WanderingBots.Continents.Maps contains invalid uint32 value '{}', skipped", toks3[i]);
            continue;
        }
        uint32 uval = val.value_or(uint32(0));
        MapEntry const* mapEntry = sMapStore.LookupEntry(uval);
        if (!mapEntry || !mapEntry->IsContinent())
        {
            TC_LOG_ERROR("server.loading", "NpcBot.WanderingBots.Continents.Maps contains invalid continent map id '{}', skipped", uval);
            continue;
        }
        _enabled_wander_node_maps.push_back(uval);
    }
    if (_enabled_wander_node_maps.empty())
    {
        TC_LOG_ERROR("server.loading", "NpcBot.WanderingBots.Continents.Maps does not provide any valid maps! Wandering bots will not be spawned!");
        _desiredWanderingBotsCount = 0;
    }

    _disabled_instance_maps.clear();
    std::string disabled_instance_maps = sConfigMgr->GetStringDefault("NpcBot.DisableInstances", "");
    std::vector<std::string_view> toks4 = Trinity::Tokenize(disabled_instance_maps, ',', false);
    for (decltype(toks4)::size_type i = 0; i != toks4.size(); ++i)
    {
        Optional<uint32> val = Trinity::StringTo<uint32>(toks4[i]);
        if (val == std::nullopt)
        {
            TC_LOG_ERROR("server.loading", "NpcBot.DisableInstances contains invalid uint32 value '{}', skipped", toks4[i]);
            continue;
        }
        uint32 uval = val.value_or(uint32(0));
        MapEntry const* mapEntry = sMapStore.LookupEntry(uval);
        if (!mapEntry || !mapEntry->IsDungeon())
        {
            TC_LOG_ERROR("server.loading", "NpcBot.DisableInstances contains invalid instance map id '{}', skipped", uval);
            continue;
        }
        _disabled_instance_maps.push_back(uval);
    }

    //limits
    _mountLevel100 = std::max<uint8>(_mountLevel100, _mountLevel60);
    RoundToInterval(_mult_dmg_physical, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_spell, 0.1f, 10.f);
    RoundToInterval(_mult_healing, 0.1f, 10.f);
    RoundToInterval(_mult_hp, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_wanderer, 0.1f, 10.f);
    RoundToInterval(_mult_healing_wanderer, 0.1f, 10.f);
    RoundToInterval(_mult_hp_wanderer, 0.1f, 10.f);
    RoundToInterval(_mult_speed_wanderer, 0.1f, 10.f);
    RoundToInterval(_mult_xpgain_wanderer, 0.0f, 100.f);
    RoundToInterval(_mult_dmg_warrior, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_paladin, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_hunter, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_rogue, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_priest, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_deathknight, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_shaman, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_mage, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_warlock, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_druid, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_blademaster, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_obsidiandestroyer, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_archmage, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_dreadlord, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_spellbreaker, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_darkranger, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_necromancer, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_seawitch, 0.1f, 10.f);
    RoundToInterval(_mult_dmg_cryptlord, 0.1f, 10.f);
    RoundToInterval(_bothk_rate_honor, 0.1f, 10.f);
}

void BotMgr::ResolveConfigConflicts()
{
    uint8 dpsFlags = /*_tankingTargetIconFlags | _offTankingTargetIconFlags | */_dpsTargetIconFlags | _rangedDpsTargetIconFlags;
    if (uint8 interFlags = (_noDpsTargetIconFlags & dpsFlags))
    {
        _noDpsTargetIconFlags &= ~interFlags;
        TC_LOG_ERROR("server.loading", "BotMgr::LoadConfig: NoDPSTargetIconMask intersects with dps targets flags {:#X}! Removed, new mask: {:#X}",
            uint32(interFlags), uint32(_noDpsTargetIconFlags));
    }

    if (!_enabled_wander_node_maps.empty())
    {
        uint8 minbotlevel = DEFAULT_MAX_LEVEL;
        uint8 maxbotlevel = 0;
        for (uint32 mapid : _enabled_wander_node_maps)
        {
            minbotlevel = std::min<uint8>(minbotlevel, BotDataMgr::GetMinLevelForMapId(mapid));
            maxbotlevel = std::max<uint8>(maxbotlevel, BotDataMgr::GetMaxLevelForMapId(mapid));
        }
        for (int8 j = minbotlevel / 10 - 1; j >= 0; --j)
        {
            if (_botwanderer_pct_level_brackets[j] > 0)
            {
                uint32 pct = _botwanderer_pct_level_brackets[j];
                _botwanderer_pct_level_brackets[minbotlevel / 10] += pct;
                _botwanderer_pct_level_brackets[j] = 0;
                TC_LOG_WARN("server.loading", "NpcBot.WanderingBots.Continents.Levels conflicts with NpcBot.WanderingBots.Continents.Maps: no map for levels {}-{}! Transferring extra {}% to levels {}-{}",
                    uint32(j ? j * 10 : 1), uint32(j * 10 + 9), pct, std::max<uint32>(minbotlevel / 10 * 10, 1), uint32(minbotlevel / 10 * 10 + 9));
            }
        }
        for (uint8 i = maxbotlevel / 10 + 1; i < _botwanderer_pct_level_brackets.size(); ++i)
        {
            if (_botwanderer_pct_level_brackets[i] > 0)
            {
                uint32 pct = _botwanderer_pct_level_brackets[i];
                _botwanderer_pct_level_brackets[maxbotlevel / 10] += pct;
                _botwanderer_pct_level_brackets[i] = 0;
                TC_LOG_WARN("server.loading", "NpcBot.WanderingBots.Continents.Levels conflicts with NpcBot.WanderingBots.Continents.Maps: no map for levels {}-{}! Transferring extra {}% to levels {}-{}",
                    uint32(i ? i * 10 : 1), uint32(i * 10 + 9), pct, std::max<uint32>(maxbotlevel, 1), uint32(maxbotlevel + 9));
            }
        }
    }
}

uint8 BotMgr::GetNpcBotsCount() const
{
    //if (!inWorldOnly)
        return (uint8)_bots.size();

    //CRITICAL SECTION
    //inWorldOnly is only for one-shot cases (opcodes, etc.)
    //maybe convert to (bot && bot->isInWorld()) ?
    //uint8 count = 0;
    //for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    //    if (ObjectAccessor::GetObjectInWorld(itr->first, (Creature*)nullptr))
    //        ++count;
    //return count;
}

uint8 BotMgr::GetNpcBotsCountByRole(uint32 roles) const
{
    uint8 count = 0;
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        if (itr->second && (roles & itr->second->GetBotRoles()))
            ++count;
    return count;
}

uint8 BotMgr::GetNpcBotsCountByVehicleEntry(uint32 creEntry) const
{
    uint8 count = 0;
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        if (itr->second && itr->second->GetVehicle() && itr->second->GetVehicleBase()->GetEntry() == creEntry)
            ++count;
    return count;
}

uint8 BotMgr::GetNpcBotSlot(Creature const* bot) const
{
    uint8 count = 0;
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        ++count;
        if (itr->second == bot)
            return count;
    }
    return 1;
}

uint8 BotMgr::GetNpcBotSlotByRole(uint32 roles, Creature const* bot) const
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

uint32 BotMgr::GetAllNpcBotsClassMask() const
{
    uint32 classMask = 0;
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        classMask |= (1 << (BotMgr::GetBotEquipmentClass(itr->second->GetBotClass()) - 1));

    return classMask;
}

bool BotMgr::IsNpcBotModEnabled()
{
    return _enableNpcBots;
}

bool BotMgr::IsNpcBotLogEnabled()
{
    return _logToDB;
}

bool BotMgr::IsNpcBotDungeonFinderEnabled()
{
    return _enableDungeonFinder;
}

bool BotMgr::IsNpcBotsPremadeEnabled()
{
    return _enableNpcBotsPremade;
}

bool BotMgr::DisplayEquipment()
{
    return _displayEquipment;
}

bool BotMgr::ShowEquippedCloak()
{
    return _showCloak;
}

bool BotMgr::ShowEquippedHelm()
{
    return _showHelm;
}

bool BotMgr::SendEquipListItems()
{
    return _sendEquipListItems;
}

bool BotMgr::IsGearBankEnabled()
{
    return _enableBotGearBank;
}

bool BotMgr::IsTransmogEnabled()
{
    return _transmog_enable;
}
bool BotMgr::MixArmorClasses()
{
    return _transmog_mixArmorClasses;
}
bool BotMgr::MixWeaponClasses()
{
    return _transmog_mixWeaponClasses;
}
bool BotMgr::MixWeaponInventoryTypes()
{
    return _transmog_mixWeaponInvTypes;
}
bool BotMgr::TransmogUseEquipmentSlots()
{
    return _transmog_useEquipmentSlots;
}

bool BotMgr::IsClassEnabled(uint8 m_class)
{
    switch (m_class)
    {
        case BOT_CLASS_WARRIOR:
            return _enableclass_warrior;
        case BOT_CLASS_PALADIN:
            return _enableclass_paladin;
        case BOT_CLASS_HUNTER:
            return _enableclass_hunter;
        case BOT_CLASS_ROGUE:
            return _enableclass_rogue;
        case BOT_CLASS_PRIEST:
            return _enableclass_priest;
        case BOT_CLASS_DEATH_KNIGHT:
            return _enableclass_deathknight;
        case BOT_CLASS_SHAMAN:
            return _enableclass_shaman;
        case BOT_CLASS_MAGE:
            return _enableclass_mage;
        case BOT_CLASS_WARLOCK:
            return _enableclass_warlock;
        case BOT_CLASS_DRUID:
            return _enableclass_druid;
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
        case BOT_CLASS_NECROMANCER:
            return _enableclass_necromancer;
        case BOT_CLASS_SEA_WITCH:
            return _enableclass_seawitch;
        case BOT_CLASS_CRYPT_LORD:
            return _enableclass_cryptlord;
        default:
            return true;
    }
}

bool BotMgr::IsWanderingClassEnabled(uint8 m_class)
{
    switch (m_class)
    {
        case BOT_CLASS_WARRIOR:
            return _enableclass_wander_warrior;
        case BOT_CLASS_PALADIN:
            return _enableclass_wander_paladin;
        case BOT_CLASS_HUNTER:
            return _enableclass_wander_hunter;
        case BOT_CLASS_ROGUE:
            return _enableclass_wander_rogue;
        case BOT_CLASS_PRIEST:
            return _enableclass_wander_priest;
        case BOT_CLASS_DEATH_KNIGHT:
            return _enableclass_wander_deathknight;
        case BOT_CLASS_SHAMAN:
            return _enableclass_wander_shaman;
        case BOT_CLASS_MAGE:
            return _enableclass_wander_mage;
        case BOT_CLASS_WARLOCK:
            return _enableclass_wander_warlock;
        case BOT_CLASS_DRUID:
            return _enableclass_wander_druid;
        case BOT_CLASS_BM:
            return _enableclass_wander_blademaster;
        case BOT_CLASS_SPHYNX:
            return _enableclass_wander_sphynx;
        case BOT_CLASS_ARCHMAGE:
            return _enableclass_wander_archmage;
        case BOT_CLASS_DREADLORD:
            return _enableclass_wander_dreadlord;
        case BOT_CLASS_SPELLBREAKER:
            return _enableclass_wander_spellbreaker;
        case BOT_CLASS_DARK_RANGER:
            return _enableclass_wander_darkranger;
        case BOT_CLASS_NECROMANCER:
            return _enableclass_wander_necromancer;
        case BOT_CLASS_SEA_WITCH:
            return _enableclass_wander_seawitch;
        case BOT_CLASS_CRYPT_LORD:
            return _enableclass_wander_cryptlord;
        default:
            return true;
    }
}

bool BotMgr::EnableWanderingUntargetNpcQuestgiver()
{
    return _untarget_wnpc_questgiver;
}
bool BotMgr::EnableWanderingUntargetNpcFlightmaster()
{
    return _untarget_wnpc_flightmaster;
}

bool BotMgr::HideBotSpawns()
{
    return _hideSpawns;
}
bool BotMgr::IsEnrageOnDimissEnabled()
{
    return _enrageOnDismiss;
}
bool BotMgr::IsBotStatsLimitsEnabled()
{
    return _botStatLimits;
}
bool BotMgr::IsPvPEnabled()
{
    return _botPvP;
}
bool BotMgr::IsFoodInterruptedByMovement()
{
    return _botMovementFoodInterrupt;
}
bool BotMgr::FilterRaces()
{
    return _filterRaces;
}
bool BotMgr::IsBotGenerationEnabledBGs()
{
    return _enableWanderingBotsBG;
}
bool BotMgr::IsBotLevelCappedByConfigBG()
{
    return _enableConfigLevelCapBG;
}
bool BotMgr::IsBotLevelCappedByConfigBGFirstPlayer()
{
    return _enableConfigLevelCapBGFirst;
}
bool BotMgr::IsBotGenerationEnabledWorldMapId(uint32 mapId)
{
    return std::find(std::cbegin(_enabled_wander_node_maps), std::cend(_enabled_wander_node_maps), mapId) != std::cend(_enabled_wander_node_maps);
}
bool BotMgr::IsBotHKEnabled()
{
    return _bothk_enable;
}
bool BotMgr::IsBotHKMessageEnabled()
{
    return _bothk_message_enable;
}
bool BotMgr::IsBotHKAchievementsEnabled()
{
    return _bothk_achievements_enable;
}
uint8 BotMgr::GetMaxClassBots()
{
    return _maxClassNpcBots;
}
uint8 BotMgr::GetMaxAccountBots()
{
    return _maxAccountNpcBots;
}
uint8 BotMgr::GetHealTargetIconFlags()
{
    return _healTargetIconFlags;
}
uint8 BotMgr::GetTankTargetIconFlags()
{
    return _tankingTargetIconFlags;
}
uint8 BotMgr::GetOffTankTargetIconFlags()
{
    return _offTankingTargetIconFlags;
}
uint8 BotMgr::GetDPSTargetIconFlags()
{
    return _dpsTargetIconFlags;
}
uint8 BotMgr::GetRangedDPSTargetIconFlags()
{
    return _rangedDpsTargetIconFlags;
}
uint8 BotMgr::GetNoDPSTargetIconFlags()
{
    return _noDpsTargetIconFlags;
}
uint32 BotMgr::GetBaseUpdateDelay()
{
    return _npcBotUpdateDelayBase;
}
uint32 BotMgr::GetOwnershipExpireTime()
{
    return _npcBotOwnerExpireTime;
}
uint8 BotMgr::GetOwnershipExpireMode()
{
    return _npcBotOwnerExpireMode;
}
uint32 BotMgr::GetDesiredWanderingBotsCount()
{
    return _desiredWanderingBotsCount;
}
uint32 BotMgr::GetBGTargetTeamPlayersCount(BattlegroundTypeId bgTypeId)
{
    switch (bgTypeId)
    {
        case BATTLEGROUND_AV:
            return _targetBGPlayersPerTeamCount_AV;
        case BATTLEGROUND_WS:
            return _targetBGPlayersPerTeamCount_WS;
        case BATTLEGROUND_AB:
            return _targetBGPlayersPerTeamCount_AB;
        case BATTLEGROUND_EY:
            return _targetBGPlayersPerTeamCount_EY;
        case BATTLEGROUND_SA:
            return _targetBGPlayersPerTeamCount_SA;
        case BATTLEGROUND_IC:
            return _targetBGPlayersPerTeamCount_IC;
        default:
            return 0;
    }
}
float BotMgr::GetBotHKHonorRate()
{
    return _bothk_rate_honor;
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
    return _xpReductionAmount;
}
uint8 BotMgr::GetNpcBotXpReductionStartingNumber()
{
    return _xpReductionStartingNumber;
}

uint8 BotMgr::GetNpcBotMountLevel60()
{
    return _mountLevel60;
}
uint8 BotMgr::GetNpcBotMountLevel100()
{
    return _mountLevel100;
}

uint8 BotMgr::GetMaxNpcBots(uint8 level)
{
    return _max_npcbots[std::min<size_t>(BracketsCount - 1, level / 10)];
}

int32 BotMgr::GetBotInfoPacketsLimit()
{
    return _botInfoPacketsLimit;
}

bool BotMgr::LimitBots(Map const* map)
{
    if (map->IsBattlegroundOrArena())
        return true;

    if (_limitNpcBotsDungeons && map->IsNonRaidDungeon())
        return true;
    if (_limitNpcBotsRaids && map->IsRaid())
        return true;

    return false;
}

bool BotMgr::IsBotContestedPvP(Creature const* bot)
{
    return bot->GetBotAI()->IsContestedPvP();
}

void BotMgr::SetBotContestedPvP(Creature const* bot)
{
    bot->GetBotAI()->SetContestedPvP();
}

bool BotMgr::CanBotParryWhileCasting(Creature const* bot)
{
    switch (bot->GetBotClass())
    {
        case BOT_CLASS_SEA_WITCH:
            return true;
        default:
            return false;
    }
}

bool BotMgr::IsWanderingWorldBot(Creature const* bot)
{
    return bot->IsWandererBot() && (!bot->FindMap() || !bot->GetMap()->GetEntry() || bot->GetMap()->GetEntry()->IsWorldMap());
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
    bool restrictBots = RestrictBots(_bots.begin()->second, false);

    _aoespots.clear();
    if (partyCombat)
        bot_ai::CalculateAoeSpots(_owner, _aoespots);

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

        if (partyCombat == false || _owner->InBattleground())
            ai->UpdateReviveTimer(diff);

        //bot->IsAIEnabled = true;

        if (ai->GetReviveTimer() <= diff)
        {
            if (bot->IsInMap(_owner) && !bot->IsAlive() && !ai->IsDuringTeleport() && _owner->IsAlive() && !_owner->IsInCombat() &&
                !_owner->IsBeingTeleported() && !_owner->InArena() && !_owner->IsInFlight() &&
                !_owner->HasUnitFlag2(UNIT_FLAG2_FEIGN_DEATH) &&
                !_owner->HasInvisibilityAura() && !_owner->HasStealthAura())
            {
                _reviveBot(bot);
                continue;
            }

            ai->SetReviveTimer(urand(1000, 5000));
        }

        if (_owner->IsAlive() && (bot->IsAlive() || restrictBots) && !ai->IsTempBot() && !ai->IsDuringTeleport() &&
            (restrictBots || bot->GetMap() != _owner->GetMap() ||
            (!bot->GetBotAI()->HasBotCommandState(BOT_COMMAND_STAY) && _owner->GetDistance(bot) > SIZE_OF_GRIDS)))
        {
            //_owner->m_Controlled.erase(bot);
            TeleportBot(bot, _owner->GetMap(), _owner, _quickrecall);
            continue;
        }

        ai->canUpdate = true;
        bot->Update(diff);
        ai->canUpdate = false;
    }

    if (_quickrecall)
    {
        _quickrecall = false;
        _data->RemoveFlag(NPCBOT_MGR_FLAG_HIDE_BOTS);
    }
}

bool BotMgr::IsMapAllowedForBots(Map const* map) const
{
    if ((!_enableNpcBotsBGs && map->IsBattleground()) ||
        (!_enableNpcBotsArenas && map->IsBattleArena()) ||
        (!_enableNpcBotsDungeons && map->IsNonRaidDungeon()) ||
        (!_enableNpcBotsRaids && map->IsRaid()))
        return false;

    if (map->IsDungeon() && !_disabled_instance_maps.empty() && std::find(_disabled_instance_maps.cbegin(), _disabled_instance_maps.cend(), map->GetId()) != _disabled_instance_maps.cend())
        return false;

    return true;
}

bool BotMgr::RestrictBots(Creature const* bot, bool add) const
{
    if (!_owner->FindMap())
        return true;

    if (_owner->IsInFlight())
        return true;

    if (_data->HasFlag(NPCBOT_MGR_FLAG_HIDE_BOTS))
        return true;

    Map const* currMap = _owner->GetMap();

    if (!IsMapAllowedForBots(currMap))
        return true;

    if (LimitBots(currMap))
    {
        //if bot is not in instance group - deny (only if trying to teleport to instance)
        if (add)
        {
            Group const* gr = _owner->GetGroup();
            if (!gr || !gr->IsMember(bot->GetGUID()))
                return true;

            //teleporting raid member bot to non-rain dungeon: prioritize owner sub-group members
            if (gr->isRaidGroup() && currMap->IsNonRaidDungeon())
            {
                uint32 max_members = currMap->ToInstanceMap()->GetMaxPlayers();
                if (gr->GetMembersCount() > max_members)
                {
                    uint8 owner_subgroup = gr->GetMemberGroup(_owner->GetGUID());
                    if (owner_subgroup != gr->GetMemberGroup(bot->GetGUID()))
                    {
                        const std::vector<Unit*> members = GetAllGroupMembers(gr);
                        uint32 sub_members = 0;
                        uint32 sub_members_inside = 0;
                        for (auto const& mslot : gr->GetMemberSlots())
                        {
                            if (mslot.group == owner_subgroup)
                            {
                                decltype(members)::const_iterator it = std::find_if(members.cbegin(), members.cend(), [&](Unit const* unit) { return mslot.guid == unit->GetGUID(); });
                                if (it != members.cend() && (*it)->IsInMap(_owner))
                                    ++sub_members_inside;
                                if (++sub_members >= max_members)
                                    break;
                            }
                        }
                        if (sub_members >= max_members || sub_members_inside < sub_members)
                            return true;
                    }
                }
            }
        }

        uint32 max_players = 0;
        if (currMap->IsDungeon())
            max_players = currMap->ToInstanceMap()->GetMaxPlayers();
        else if (currMap->IsBattleground())
            max_players = _owner->GetBattleground()->GetMaxPlayersPerTeam();
        else if (currMap->IsBattleArena())
            max_players = _owner->GetBattleground()->GetArenaType();

        if (max_players && currMap->GetPlayersCountExceptGMs() + uint32(add) > max_players)
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

bool BotMgr::HasBotWithSpec(uint8 spec, bool alive) const
{
    for (BotMap::const_iterator itr = _bots.cbegin(); itr != _bots.cend(); ++itr)
        if (itr->second->GetBotAI()->GetSpec() == spec && (!alive || itr->second->IsAlive()))
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

bool BotMgr::IsBeingResurrected(WorldObject const* corpse) const
{
    std::vector<Unit const*> casters;
    if (_owner->IsNonMeleeSpellCast(false, true, true))
        casters.push_back(_owner);
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        if (itr->second->IsNonMeleeSpellCast(false, true, true))
            casters.push_back(itr->second);
    }

    if (Group const* group = _owner->GetGroup())
    {
        for (GroupReference const* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player const* player = itr->GetSource();
            if (!player || player == _owner || player->FindMap() != corpse->GetMap())
                continue;

            if (player->IsNonMeleeSpellCast(false, true, true))
                casters.push_back(player);

            if (player->HaveBot())
            {
                BotMap const* map = player->GetBotMgr()->GetBotMap();
                for (BotMap::const_iterator bitr = map->begin(); bitr != map->end(); ++bitr)
                {
                    if (bitr->second->IsNonMeleeSpellCast(false, true, true))
                        casters.push_back(bitr->second);
                }
            }
        }
    }

    for (Unit const* caster : casters)
    {
        if (Spell const* spell = caster->GetCurrentSpell(CURRENT_GENERIC_SPELL))
        {
            if (corpse->GetGUID() == (corpse->ToCorpse() ? spell->m_targets.GetCorpseTargetGUID() : spell->m_targets.GetUnitTargetGUID()))
                return true;
        }
    }

    return false;
}

void BotMgr::_reviveBot(Creature* bot, WorldLocation* dest)
{
    if (bot->IsAlive() || !bot->IsInWorld())
        return;

    if (!bot->GetBotAI()->IAmFree())
    {
        if (!dest)
            bot->CastSpell(bot, COSMETIC_RESURRECTION, false);

        if (!dest)
            dest = bot->GetBotOwner();

        bot->NearTeleportTo(dest->GetPositionX(), dest->GetPositionY(), dest->GetPositionZ(), dest->GetOrientation());
        //some weird pos manipulation
        if (dest != bot)
            bot->Relocate(dest);
    }

    bot->SetDisplayId(bot->GetNativeDisplayId());
    bot->ReplaceAllNpcFlags(NPCFlags(bot->GetCreatureTemplate()->npcflag));
    bot->ClearUnitState(UNIT_STATE_ALL_ERASABLE);
    bot->ReplaceAllUnitFlags(UnitFlags(0));
    bot->SetLootRecipient(nullptr);
    bot->ResetPlayerDamageReq();
    bot->SetPvP(bot->GetBotOwner()->IsPvP());
    bot->Motion_Initialize();
    bot->setDeathState(ALIVE);
    //bot->GetBotAI()->Reset();
    bot->GetBotAI()->SetShouldUpdateStats();

    uint8 restore_factor = (bot->IsWandererBot() || (!bot->GetBotAI()->IAmFree() && bot->GetBotOwner()->InBattleground())) ? 1 : 4;
    bot->SetHealth(bot->GetMaxHealth() / restore_factor); //25% of max health
    if (bot->GetMaxPower(POWER_MANA) > 1)
        bot->SetPower(POWER_MANA, bot->GetMaxPower(POWER_MANA) / restore_factor); //25% of max mana

    if (!bot->GetBotAI()->IAmFree() && !bot->GetBotAI()->HasBotCommandState(BOT_COMMAND_MASK_UNMOVING))
        bot->GetBotAI()->SetBotCommandState(BOT_COMMAND_FOLLOW, true);
}

Creature* BotMgr::GetBot(ObjectGuid guid) const
{
    BotMap::const_iterator itr = _bots.find(guid);
    return itr != _bots.end() ? itr->second : nullptr;
}

Creature* BotMgr::GetBotByName(std::string_view name) const
{
    std::wstring wname;
    if (Utf8toWStr(name, wname))
    {
        wstrToLower(wname);
        for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        {
            if (!itr->second)
                continue;

            std::string basename = itr->second->GetName();
            if (CreatureLocale const* creatureInfo = sObjectMgr->GetCreatureLocale(itr->second->GetEntry()))
            {
                uint32 loc = _owner->GetSession()->GetSessionDbLocaleIndex();
                if (creatureInfo->Name.size() > loc && !creatureInfo->Name[loc].empty())
                    basename = creatureInfo->Name[loc];
            }

            std::wstring wbname;
            if (!Utf8toWStr(basename, wbname))
                continue;

            wstrToLower(wbname);
            if (wbname == wname)
                return itr->second;
        }
    }

    return nullptr;
}

std::list<Creature*> BotMgr::GetAllBotsByClass(uint8 botclass) const
{
    std::list<Creature*> foundBots;
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        if (!itr->second || !itr->second->IsInWorld() || !itr->second->IsAlive())
            continue;

        if (itr->second->GetBotClass() == botclass)
            foundBots.push_back(itr->second);
    }

    return foundBots;
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

        if (bot->IsTempBot())
            continue;

        //_owner->m_Controlled.erase(bot);
        TeleportBot(bot, newMap, &pos);
    }
}

void BotMgr::_teleportBot(Creature* bot, Map* newMap, float x, float y, float z, float ori, bool quick, bool reset, bot_ai* detached_ai)
{
    bot_ai* botai = detached_ai ? detached_ai : bot->GetBotAI();
    ASSERT(botai);
    botai->AbortTeleport();
    botai->SetIsDuringTeleport(true);
    botai->KillEvents(true);
    bot->m_Events.KillAllEvents(false);

    BotLogger::Log(NPCBOT_LOG_TELEPORT_START, bot, bot->IsInGrid(), bot->IsWandererBot(), botai->CanAppearInWorld(), newMap->GetId(), bool(reset));

    BotMgr::AddDelayedTeleportCallback([bot, botai, newMap, x, y, z, ori, quick, reset]() {
        if (bot->GetVehicle())
            bot->ExitVehicle();

        if (bot->GetTransport())
        {
            bot->ClearUnitState(UNIT_STATE_IGNORE_PATHFINDING);
            bot->GetTransport()->RemovePassenger(bot);
        }

        Map* mymap = bot->FindMap();
        if (mymap)
        {
            bot->BotStopMovement();

            if (mymap != newMap)
            {
                bot->RemoveAurasByType(SPELL_AURA_MOD_STUN);
                bot->RemoveAurasByType(SPELL_AURA_MOD_FEAR);
                bot->RemoveAurasByType(SPELL_AURA_MOD_CONFUSE);
                bot->RemoveAurasByType(SPELL_AURA_MOD_ROOT);
                bot->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_TELEPORTED);
            }

            bot->InterruptNonMeleeSpells(true);

            if (bot->IsInWorld())
            {
                botai->UnsummonAll(!botai->IAmFree() || botai->IsWanderer());

                if (Battleground* bg = bot->GetBotBG())
                    bg->EventBotDroppedFlag(bot);

                bot->CastSpell(bot, COSMETIC_TELEPORT_EFFECT, true);

                if (!bot->IsFreeBot())
                    if (InstanceScript* iscr = bot->GetBotOwner()->GetInstanceScript())
                        iscr->OnNPCBotLeave(bot);

                bot->RemoveFromWorld();
            }

            ASSERT(bot->GetGUID());

            bot->RemoveAllGameObjects();

            bot->m_Events.KillAllEvents(false);
            bot->CombatStop();
            bot->ClearComboPoints();
            bot->ClearComboPointHolders();

            if (bot->IsInGrid())
                mymap->RemoveFromMap(bot, false);
        }

        if (botai->IAmFree())
        {
            bot->Relocate(x, y, z, ori);
            if (bot->FindMap())
                bot->ResetMap();
            bot->SetMap(newMap);
            if (!bot->IsWandererBot() && !botai->CanAppearInWorld())
            {
                botai->AbortTeleport();
                TeleportFinishEvent* delayedTeleportEvent = new TeleportFinishEvent(botai, reset);
                std::chrono::milliseconds delay(urand(5000, 8000));
                botai->GetEvents()->AddEvent(delayedTeleportEvent, botai->GetEvents()->CalculateTime(delay));
                botai->SetTeleportFinishEvent(delayedTeleportEvent);
                return;
            }

            BotLogger::Log(NPCBOT_LOG_TELEPORT_FINISH, bot, bot->IsInGrid(), bot->IsWandererBot(), botai->CanAppearInWorld(), newMap->GetId(), bool(reset));

            newMap->AddToMap(bot);
            if (reset)
                botai->Reset();
            botai->SetIsDuringTeleport(false);
            botai->ResetContestedPvP();

            if (newMap->IsBattleground())
            {
                Battleground* bg = botai->GetBG();
                if (!bg)
                {
                    BotDataMgr::DespawnWandererBot(bot->GetEntry());
                    return;
                }

                if (newMap != mymap)
                {
                    //we teleport from base non-instanced map which normally doesn't exist
                    ASSERT(mymap->GetPlayersCountExceptGMs() == 0);

                    bg->AddBot(bot);
                }

                if (!bot->IsAlive())
                {
                    ObjectGuid shGuid = ObjectGuid::Empty;
                    float mindist = 0.0f;
                    for (ObjectGuid bgCreGuid : bg->BgCreatures)
                    {
                        if (Creature const* bgCre = newMap->GetCreature(bgCreGuid))
                        {
                            if (bgCre->IsSpiritService())
                            {
                                float dist = bot->GetExactDist2d(bgCre);
                                if (shGuid == ObjectGuid::Empty || dist < mindist)
                                {
                                    mindist = dist;
                                    shGuid = bgCreGuid;
                                }
                            }
                        }
                    }
                    if (shGuid)
                        bg->AddPlayerToResurrectQueue(shGuid, bot->GetGUID());
                    else
                    {
                        TC_LOG_ERROR("npcbots", "TeleportBot: Bot {} '{}' can't find SpiritHealer in bg {}!",
                            bot->GetEntry(), bot->GetName(), bg->GetName());
                    }
                }
            }

            botai->canUpdate = true;

            return;
        }

        //update group member online state
        if (Group* gr = bot->GetBotOwner()->GetGroup())
            if (gr->IsMember(bot->GetGUID()))
                gr->SendUpdate();

        botai->AbortTeleport();
        TeleportFinishEvent* finishEvent = new TeleportFinishEvent(botai, reset);
        std::chrono::milliseconds delay(quick ? urand(500, 1500) : urand(5000, 8000));
        botai->GetEvents()->AddEvent(finishEvent, botai->GetEvents()->CalculateTime(delay));
        botai->SetTeleportFinishEvent(finishEvent);
    });
}

void BotMgr::TeleportBot(Creature* bot, Map* newMap, Position const* pos, bool quick, bool reset, bot_ai* detached_ai)
{
    _teleportBot(bot, newMap, pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), pos->GetOrientation(), quick, reset, detached_ai);
}

void BotMgr::CleanupsBeforeBotDelete(ObjectGuid guid, uint8 removetype)
{
    BotMap::const_iterator itr = _bots.find(guid);
    ASSERT(itr != _bots.end(), "Trying to remove bot which does not belong to this botmgr(b)!!");
    //ASSERT(_owner->IsInWorld(), "Trying to remove bot while not in world(b)!!");

    Creature* bot = itr->second;

    ASSERT(bot->GetCreator() && bot->GetCreator()->GetGUID() == _owner->GetGUID());

    RemoveBotFromBGQueue(bot);
    if (removetype != BOT_REMOVE_LOGOUT)
        RemoveBotFromGroup(bot);

    CleanupsBeforeBotDelete(bot);
}

void BotMgr::CleanupsBeforeBotDelete(Creature* bot)
{
    //don't allow removing bots while they are teleporting
    if (!bot->IsInWorld())
        bot->GetBotAI()->AbortTeleport();

    if (bot->GetVehicle())
        bot->ExitVehicle();

    //remove any summons
    bot->GetBotAI()->UnsummonAll(false);
    bot->AttackStop();
    bot->CombatStopWithPets(true);

    //bot->SetOwnerGUID(ObjectGuid::Empty);
    //_owner->m_Controlled.erase(bot);
    bot->SetControlledByPlayer(false);
    //bot->RemoveUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
    //bot->RemoveUnitFlag(UNIT_FLAG_PVP_ATTACKABLE);
    bot->SetByteValue(UNIT_FIELD_BYTES_2, 1, 0);
    bot->SetCreator(nullptr);
    //bot->SetCreatorGUID(ObjectGuid::Empty);

    Map* map = bot->FindMap();
    if (!map || map->IsDungeon())
        bot->RemoveFromWorld();
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
    ASSERT(itr != _bots.end(), "Trying to remove bot which does not belong to this botmgr(a)!!");
    //ASSERT(_owner->IsInWorld(), "Trying to remove bot while not in world(a)!!");

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
    CleanupsBeforeBotDelete(guid, removetype);

    ////remove control bar
    //if (GetNpcBotsCount() <= 1 && !_owner->GetPetGUID() && _owner->m_Controlled.empty())
    //    _owner->SendRemoveControlBar();

    if (bot->GetBotAI()->IsTempBot())
    {
        //bot->GetBotAI()->OnBotDespawn(bot); //send to self
        _removeList.push_back(guid);
        return;
    }

    _bots.erase(itr);

    BotAIResetType resetType;
    switch (removetype)
    {
        case BOT_REMOVE_DISMISS: resetType = BOTAI_RESET_DISMISS; break;
        case BOT_REMOVE_UNBIND:  resetType = BOTAI_RESET_UNBIND;    break;
        default:                 resetType = BOTAI_RESET_LOGOUT;  break;
    }
    bot->GetBotAI()->ResetBotAI(resetType);

    bot->SetFaction(bot->GetCreatureTemplate()->faction);
    bot->SetLevel(bot->GetCreatureTemplate()->minlevel);

    if (removetype == BOT_REMOVE_DISMISS)
    {
        BotDataMgr::ResetNpcBotTransmogData(bot->GetEntry(), false);
        uint32 newOwner = 0;
        BotDataMgr::UpdateNpcBotData(bot->GetEntry(), NPCBOT_UPDATE_OWNER, &newOwner);
    }
}

void BotMgr::UnbindBot(ObjectGuid guid)
{
    Creature const* bot = GetBot(guid);
    ASSERT(bot);

    RemoveBot(guid, BOT_REMOVE_UNBIND);
    bot->GetBotAI()->SetBotCommandState(BOT_COMMAND_UNBIND);
}
BotAddResult BotMgr::RebindBot(Creature* bot)
{
    BotAddResult res = AddBot(bot);
    if (res == BOT_ADD_SUCCESS)
        bot->GetBotAI()->RemoveBotCommandState(BOT_COMMAND_UNBIND);
    return res;
}

BotAddResult BotMgr::AddBot(Creature* bot)
{
    ASSERT(bot->IsNPCBot());
    ASSERT(bot->GetBotAI() != nullptr);

    bool owned = bot->GetBotAI()->IsTempBot() || bot->GetBotAI()->GetBotOwnerGuid() == _owner->GetGUID().GetCounter();
    uint8 owned_count = BotDataMgr::GetOwnedBotsCount(_owner->GetGUID());
    uint8 class_count = BotDataMgr::GetOwnedBotsCount(_owner->GetGUID(), bot->GetClassMask());

    if (!_enableNpcBots)
    {
        ChatHandler ch(_owner->GetSession());
        ch.SendSysMessage(bot_ai::LocalizedNpcText(GetOwner(), BOT_TEXT_BOTADDFAIL_DISABLED).c_str());
        return BOT_ADD_DISABLED;
    }
    if (GetBot(bot->GetGUID()))
        return BOT_ADD_ALREADY_HAVE; //Silent error, intended
    if (!bot->GetBotAI()->IAmFree())
    {
        ChatHandler ch(_owner->GetSession());
        ch.PSendSysMessage(bot_ai::LocalizedNpcText(GetOwner(), BOT_TEXT_BOTADDFAIL_OWNED).c_str(),
            bot->GetName().c_str(), bot->GetBotOwner()->GetName().c_str());
        return BOT_ADD_NOT_AVAILABLE;
    }
    if (!owned && owned_count >= GetMaxNpcBots(_owner->GetLevel()))
    {
        ChatHandler ch(_owner->GetSession());
        ch.PSendSysMessage(bot_ai::LocalizedNpcText(GetOwner(), BOT_TEXT_HIREFAIL_MAXBOTS).c_str(), GetMaxNpcBots(_owner->GetLevel()));
        return BOT_ADD_MAX_EXCEED;
    }
    if (!owned && _maxClassNpcBots && class_count >= _maxClassNpcBots)
    {
        ChatHandler ch(_owner->GetSession());
        ch.PSendSysMessage(bot_ai::LocalizedNpcText(GetOwner(), BOT_TEXT_HIREFAIL_MAXCLASSBOTS).c_str(), class_count, _maxClassNpcBots);
        return BOT_ADD_MAX_CLASS_EXCEED;
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
    //        return BOT_ADD_INSTANCE_LIMIT;
    //    }
    //}
    if (!owned)
    {
        uint32 cost = GetNpcBotCost(_owner->GetLevel(), bot->GetBotClass());
        if (!_owner->HasEnoughMoney(cost))
        {
            ChatHandler ch(_owner->GetSession());
            std::string str = bot_ai::LocalizedNpcText(GetOwner(), BOT_TEXT_HIREFAIL_COST) + " (";
            str += GetNpcBotCostStr(_owner->GetLevel(), bot->GetBotClass());
            str += ")!";
            ch.SendSysMessage(str.c_str());
            return BOT_ADD_CANT_AFFORD;
        }

        _owner->ModifyMoney(-(int32(cost)));
    }

    bot->GetBotAI()->canUpdate = false;

    if (!bot->IsAlive())
        _reviveBot(bot);

    bot->GetBotAI()->UnsummonAll(false);

    _bots[bot->GetGUID()] = bot;

    ASSERT(!bot->GetCreator());
    //ASSERT(!bot->GetOwnerGUID());
    //bot->SetOwnerGUID(_owner->GetGUID());
    bot->SetCreator(_owner); //needed in case of FFAPVP
    //bot->SetCreatorGUID(_owner->GetGUID());
    //_owner->m_Controlled.insert(bot);
    bot->SetControlledByPlayer(true);
    //bot->SetUnitFlag(UNIT_FLAG_PLAYER_CONTROLLED);
    bot->SetByteValue(UNIT_FIELD_BYTES_2, 1, _owner->GetByteValue(UNIT_FIELD_BYTES_2, 1));
    bot->SetFaction(_owner->GetFaction());
    bot->SetPhaseMask(_owner->GetPhaseMask(), true);

    bot->GetBotAI()->SetBotOwner(_owner);

    bot->GetBotAI()->Reset();

    if (!bot->IsInWorld())
        TeleportBot(bot, _owner->GetMap(), _owner);

    if (!bot->GetBotAI()->IsTempBot())
    {
        bot->GetBotAI()->SetBotCommandState(BOT_COMMAND_FOLLOW, true);
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

    if (gr->AddMember(bot))
    {
        if (!bot->GetBotAI()->HasRole(BOT_ROLE_PARTY))
            bot->GetBotAI()->ToggleRole(BOT_ROLE_PARTY, true);

        return true;
    }

    return false;
}

void BotMgr::RemoveBotFromBGQueue(Creature const* bot)
{
    for (uint8 i = 0; i < PLAYER_MAX_BATTLEGROUND_QUEUES; ++i)
    {
        if (BattlegroundQueueTypeId bgQueueTypeId = _owner->GetBattlegroundQueueTypeId(i))
            sBattlegroundMgr->GetBattlegroundQueue(bgQueueTypeId).RemovePlayer(bot->GetGUID(), true);
    }
}

bool BotMgr::RemoveBotFromGroup(Creature* bot)
{
    ASSERT(GetBot(bot->GetGUID()));

    Group* gr = _owner->GetGroup();
    if (!gr || !gr->IsMember(bot->GetGUID()))
        return false;

    RemoveBotFromBGQueue(bot);

    if (bot->GetBotAI()->HasRole(BOT_ROLE_PARTY) && !_owner->GetSession()->PlayerLogout())
        bot->GetBotAI()->ToggleRole(BOT_ROLE_PARTY, true);

    //debug
    //if (gr->RemoveMember(bot->GetGUID()))
    //    TC_LOG_ERROR("entities.player", "RemoveBotFromGroup(): bot {} removed from group", bot->GetName());
    //else
    //    TC_LOG_ERROR("entities.player", "RemoveBotFromGroup(): RemoveMember() returned FALSE on bot {}", bot->GetName());

    gr->RemoveMember(bot->GetGUID());

    //if removed from group while in instance / bg then remove from world immediately
    if (bot->IsInWorld() && RestrictBots(bot, true))
        TeleportBot(bot, bot->GetMap(), bot);

    return true;
}

bool BotMgr::RemoveAllBotsFromGroup()
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        RemoveBotFromGroup(itr->second);

    return true;
}

uint32 BotMgr::GetNpcBotCost(uint8 level, uint8 botclass)
{
    //assuming default 1000000
    //level 1: 500  //5  silver
    //10 : 10000    //1  gold
    //20 : 50000    //5  gold
    //30 : 200000   //20 gold
    //40 : 500000   //50 gold
    //rest is linear
    //rare / rareelite bots have their cost adjusted
    uint32 cost =
        level < 10 ? _npcBotsCost / 2000 : //5 silver
        level < 20 ? _npcBotsCost / 100 :  //1 gold
        level < 30 ? _npcBotsCost / 20 :   //5 gold
        level < 40 ? _npcBotsCost / 5 :    //20 gold
        (_npcBotsCost * (level - (level % 10))) / DEFAULT_MAX_LEVEL; //50 - 100 gold

    switch (botclass)
    {
        case BOT_CLASS_BM:
        case BOT_CLASS_ARCHMAGE:
        case BOT_CLASS_SPELLBREAKER:
        case BOT_CLASS_NECROMANCER:
            cost += cost; //200%
            break;
        case BOT_CLASS_SPHYNX:
        case BOT_CLASS_DREADLORD:
        case BOT_CLASS_DARK_RANGER:
        case BOT_CLASS_SEA_WITCH:
        case BOT_CLASS_CRYPT_LORD:
            cost += cost * 4; //500%
            break;
        default:
            break;
    }

    return cost;
}

std::string BotMgr::GetNpcBotCostStr(uint8 level, uint8 botclass)
{
    std::ostringstream money;

    if (uint32 cost = GetNpcBotCost(level, botclass))
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

uint8 BotMgr::BotClassByClassName(std::string const& className)
{
    static const std::map<std::string, uint8> BotClassNamesMap = {
        { "warrior", BOT_CLASS_WARRIOR },
        { "paladin", BOT_CLASS_PALADIN },
        { "hunter", BOT_CLASS_HUNTER },
        { "rogue", BOT_CLASS_ROGUE },
        { "priest", BOT_CLASS_PRIEST },
        { "deathknight", BOT_CLASS_DEATH_KNIGHT },
        { "death_knight", BOT_CLASS_DEATH_KNIGHT },
        { "shaman", BOT_CLASS_SHAMAN },
        { "mage", BOT_CLASS_MAGE },
        { "warlock", BOT_CLASS_WARLOCK },
        { "druid", BOT_CLASS_DRUID },
        { "blademaster", BOT_CLASS_BM },
        { "blade_master", BOT_CLASS_BM },
        { "sphynx", BOT_CLASS_SPHYNX },
        { "obsidiandestroyer", BOT_CLASS_SPHYNX },
        { "obsidian_destroyer", BOT_CLASS_SPHYNX },
        { "destroyer", BOT_CLASS_SPHYNX },
        { "archmage", BOT_CLASS_ARCHMAGE },
        { "dreadlord", BOT_CLASS_DREADLORD },
        { "spellbreaker", BOT_CLASS_SPELLBREAKER },
        { "spell_breaker", BOT_CLASS_SPELLBREAKER },
        { "darkranger", BOT_CLASS_DARK_RANGER },
        { "dark_ranger", BOT_CLASS_DARK_RANGER },
        { "necromancer", BOT_CLASS_NECROMANCER },
        { "necro", BOT_CLASS_NECROMANCER },
        { "seawitch", BOT_CLASS_SEA_WITCH },
        { "sea_witch", BOT_CLASS_SEA_WITCH },
        { "cryptlord", BOT_CLASS_CRYPT_LORD},
        { "crypt_lord", BOT_CLASS_CRYPT_LORD }
    };

    //std::transform(className.begin(), className.end(), className.begin(), std::tolower);
    auto iter = BotClassNamesMap.find(className);
    if (iter != BotClassNamesMap.end())
        return iter->second;

    return BOT_CLASS_NONE;
}

uint8 BotMgr::GetBotPlayerClass(uint8 bot_class)
{
    if (bot_class >= BOT_CLASS_EX_START)
    {
        switch (bot_class)
        {
            case BOT_CLASS_BM:
                return BOT_CLASS_WARRIOR;
            case BOT_CLASS_SPHYNX:
                return BOT_CLASS_WARLOCK;
            case BOT_CLASS_ARCHMAGE:
                return BOT_CLASS_MAGE;
            case BOT_CLASS_DREADLORD:
                return BOT_CLASS_WARLOCK;
            case BOT_CLASS_SPELLBREAKER:
                return BOT_CLASS_PALADIN;
            case BOT_CLASS_DARK_RANGER:
                return BOT_CLASS_HUNTER;
            case BOT_CLASS_NECROMANCER:
                return BOT_CLASS_WARLOCK;
            case BOT_CLASS_SEA_WITCH:
                return BOT_CLASS_MAGE;
            case BOT_CLASS_CRYPT_LORD:
                return BOT_CLASS_WARRIOR;
            default:
                TC_LOG_ERROR("npcbots", "GetPlayerClass: unknown Ex bot class {}!", bot_class);
                return BOT_CLASS_PALADIN;
        }
    }

    return bot_class;
}

uint8 BotMgr::GetBotPlayerRace(uint8 bot_class, uint8 bot_race)
{
    if (bot_class >= BOT_CLASS_EX_START)
    {
        switch (bot_class)
        {
            case BOT_CLASS_BM:
                return RACE_ORC;
            case BOT_CLASS_SPHYNX:
                return RACE_UNDEAD_PLAYER;
            case BOT_CLASS_ARCHMAGE:
                return RACE_HUMAN;
            case BOT_CLASS_DREADLORD:
                return RACE_UNDEAD_PLAYER;
            case BOT_CLASS_SPELLBREAKER:
                return RACE_BLOODELF;
            case BOT_CLASS_DARK_RANGER:
                return RACE_BLOODELF;
            case BOT_CLASS_NECROMANCER:
                return RACE_HUMAN;
            case BOT_CLASS_SEA_WITCH:
                return RACE_TROLL;
            case BOT_CLASS_CRYPT_LORD:
                return RACE_UNDEAD_PLAYER;
            default:
                TC_LOG_ERROR("npcbots", "GetBotPlayerRace: unknown Ex bot class {}!", bot_class);
                return RACE_HUMAN;
        }
    }

    return bot_race;
}

uint8 BotMgr::GetBotPlayerClass(Creature const* bot)
{
    return GetBotPlayerClass(bot->GetBotAI()->GetBotClass());
}

uint8 BotMgr::GetBotPlayerRace(Creature const* bot)
{
    return GetBotPlayerRace(bot->GetBotAI()->GetBotClass(), bot->GetRace());
}

uint8 BotMgr::GetBotEquipmentClass(uint8 bot_class)
{
    if (bot_class >= BOT_CLASS_EX_START)
    {
        switch (bot_class)
        {
            case BOT_CLASS_BM:
                return BOT_CLASS_WARRIOR;
            case BOT_CLASS_SPHYNX:
                return BOT_CLASS_PALADIN;
            case BOT_CLASS_ARCHMAGE:
                return BOT_CLASS_MAGE;
            case BOT_CLASS_DREADLORD:
                return BOT_CLASS_PALADIN;
            case BOT_CLASS_SPELLBREAKER:
                return BOT_CLASS_PALADIN;
            case BOT_CLASS_DARK_RANGER:
                return BOT_CLASS_HUNTER;
            case BOT_CLASS_NECROMANCER:
                return BOT_CLASS_PALADIN;
            case BOT_CLASS_SEA_WITCH:
                return BOT_CLASS_MAGE;
            case BOT_CLASS_CRYPT_LORD:
                return BOT_CLASS_WARRIOR;
            default:
                TC_LOG_ERROR("npcbots", "GetBotEquipmentClass: unknown Ex bot class {}!", bot_class);
                return BOT_CLASS_PALADIN;
        }
    }

    return BotMgr::GetBotPlayerClass(bot_class);
}

std::string BotMgr::GetTargetIconString(uint8 icon_idx) const
{
    std::ostringstream ss;
    ss << "|TInterface\\TargetingFrame\\UI-RaidTargetingIcon_" << uint32(icon_idx + 1) << ":12|t";
    if (size_t(icon_idx) < TargetIconNamesCacheSize)
        ss << _targetIconNamesCache[icon_idx];

    return ss.str();
}
void BotMgr::UpdateTargetIconName(uint8 id, std::string const& name)
{
    if (id >= TargetIconNamesCacheSize)
        return;

    _targetIconNamesCache[id] = name;
}
void BotMgr::ResetTargetIconNames()
{
    _targetIconNamesCache = {};
}

void BotMgr::ReviveAllBots()
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        _reviveBot(itr->second);
}

void BotMgr::SendBotCommandState(uint32 state)
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        itr->second->GetBotAI()->SetBotCommandState(state, true);
}

void BotMgr::SendBotCommandStateRemove(uint32 state)
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        itr->second->GetBotAI()->RemoveBotCommandState(state);
}

void BotMgr::SendBotAwaitState(uint8 state)
{
    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
        itr->second->GetBotAI()->SetBotAwaitState(state);
}

void BotMgr::RecallAllBots(bool teleport)
{
    if (teleport)
    {
        _data->SetFlag(NPCBOT_MGR_FLAG_HIDE_BOTS);
        _quickrecall = true;
    }
    else
    {
        for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
            if (itr->second->IsInWorld() && itr->second->IsAlive() && !bot_ai::CCed(itr->second, true))
                itr->second->GetMotionMaster()->MovePoint(_owner->GetMapId(), *_owner, false);
    }
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

void BotMgr::KillBot(Creature* bot) const
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
            itr->second->GetBotsPet()->SetPhaseMask(_owner->GetPhaseMask(), itr->second->GetBotsPet()->IsInWorld());
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

void BotMgr::BuildBotPartyMemberStatsPacket(ObjectGuid bot_guid, WorldPacket* data)
{
    Creature const* bot = BotDataMgr::FindBot(bot_guid.GetEntry());
    if (!bot)
    {
        *data << uint8(0);
        *data << bot_guid.WriteAsPacked();
        *data << uint32(GROUP_UPDATE_FLAG_STATUS);
        *data << uint16(MEMBER_STATUS_OFFLINE);
        return;
    }

    Creature const* pet = nullptr; //bot->GetBotAI()->GetBotsPet();
    Powers powerType = bot->GetPowerType();

    *data << uint8(0);                                       // only for SMSG_PARTY_MEMBER_STATS_FULL, probably arena/bg related
    *data << bot->GetPackGUID();

    uint32 updateFlags = GROUP_UPDATE_FLAG_STATUS | GROUP_UPDATE_FLAG_CUR_HP | GROUP_UPDATE_FLAG_MAX_HP
                      | GROUP_UPDATE_FLAG_CUR_POWER | GROUP_UPDATE_FLAG_MAX_POWER | GROUP_UPDATE_FLAG_LEVEL
                      | GROUP_UPDATE_FLAG_ZONE | GROUP_UPDATE_FLAG_POSITION | GROUP_UPDATE_FLAG_AURAS
                      | GROUP_UPDATE_FLAG_PET_NAME | GROUP_UPDATE_FLAG_PET_MODEL_ID | GROUP_UPDATE_FLAG_PET_AURAS;

    if (powerType != POWER_MANA)
        updateFlags |= GROUP_UPDATE_FLAG_POWER_TYPE;

    if (pet)
        updateFlags |= GROUP_UPDATE_FLAG_PET_GUID | GROUP_UPDATE_FLAG_PET_CUR_HP | GROUP_UPDATE_FLAG_PET_MAX_HP
                    | GROUP_UPDATE_FLAG_PET_POWER_TYPE | GROUP_UPDATE_FLAG_PET_CUR_POWER | GROUP_UPDATE_FLAG_PET_MAX_POWER;

    if (bot->GetVehicle())
        updateFlags |= GROUP_UPDATE_FLAG_VEHICLE_SEAT;

    uint16 playerStatus = MEMBER_STATUS_ONLINE;
    if (bot->IsPvP())
        playerStatus |= MEMBER_STATUS_PVP;

    if (!bot->IsAlive())
        playerStatus |= MEMBER_STATUS_DEAD;

    if (bot->IsFFAPvP())
        playerStatus |= MEMBER_STATUS_PVP_FFA;

    *data << uint32(updateFlags);
    *data << uint16(playerStatus);                           // GROUP_UPDATE_FLAG_STATUS
    *data << uint32(bot->GetHealth());                    // GROUP_UPDATE_FLAG_CUR_HP
    *data << uint32(bot->GetMaxHealth());                 // GROUP_UPDATE_FLAG_MAX_HP
    if (updateFlags & GROUP_UPDATE_FLAG_POWER_TYPE)
        *data << uint8(powerType);

    *data << uint16(bot->GetPower(powerType));            // GROUP_UPDATE_FLAG_CUR_POWER
    *data << uint16(bot->GetMaxPower(powerType));         // GROUP_UPDATE_FLAG_MAX_POWER
    *data << uint16(bot->GetLevel());                     // GROUP_UPDATE_FLAG_LEVEL
    *data << uint16(bot->GetZoneId());                    // GROUP_UPDATE_FLAG_ZONE
    *data << uint16(bot->GetPositionX());                 // GROUP_UPDATE_FLAG_POSITION
    *data << uint16(bot->GetPositionY());                 // GROUP_UPDATE_FLAG_POSITION

    uint64 auraMask = 0;
    size_t maskPos = data->wpos();
    *data << uint64(auraMask);                               // placeholder
    for (uint8 i = 0; i < MAX_AURAS_GROUP_UPDATE; ++i)
    {
        if (AuraApplication const* aurApp = bot->GetVisibleAura(i))
        {
            auraMask |= uint64(1) << i;
            *data << uint32(aurApp->GetBase()->GetId());
            *data << uint8(aurApp->GetFlags());
        }
    }

    data->put<uint64>(maskPos, auraMask);                    // GROUP_UPDATE_FLAG_AURAS

    if (updateFlags & GROUP_UPDATE_FLAG_PET_GUID)
        *data << uint64(ASSERT_NOTNULL(pet)->GetGUID());

    *data << std::string(pet ? pet->GetName() : "");         // GROUP_UPDATE_FLAG_PET_NAME
    *data << uint16(pet ? pet->GetDisplayId() : 0);          // GROUP_UPDATE_FLAG_PET_MODEL_ID

    if (updateFlags & GROUP_UPDATE_FLAG_PET_CUR_HP)
        *data << uint32(pet->GetHealth());

    if (updateFlags & GROUP_UPDATE_FLAG_PET_MAX_HP)
        *data << uint32(pet->GetMaxHealth());

    if (updateFlags & GROUP_UPDATE_FLAG_PET_POWER_TYPE)
        *data << (uint8)pet->GetPowerType();

    if (updateFlags & GROUP_UPDATE_FLAG_PET_CUR_POWER)
        *data << uint16(pet->GetPower(pet->GetPowerType()));

    if (updateFlags & GROUP_UPDATE_FLAG_PET_MAX_POWER)
        *data << uint16(pet->GetMaxPower(pet->GetPowerType()));

    uint64 petAuraMask = 0;
    maskPos = data->wpos();
    *data << uint64(petAuraMask);                            // placeholder
    if (pet)
    {
        for (uint8 i = 0; i < MAX_AURAS_GROUP_UPDATE; ++i)
        {
            if (AuraApplication const* aurApp = pet->GetVisibleAura(i))
            {
                petAuraMask |= uint64(1) << i;
                *data << uint32(aurApp->GetBase()->GetId());
                *data << uint8(aurApp->GetFlags());
            }
        }
    }

    data->put<uint64>(maskPos, petAuraMask);                 // GROUP_UPDATE_FLAG_PET_AURAS

    if (updateFlags & GROUP_UPDATE_FLAG_VEHICLE_SEAT)
        *data << uint32(bot->GetVehicle()->GetVehicleInfo()->SeatID[bot->m_movementInfo.transport.seat]);
}

void BotMgr::BuildBotPartyMemberStatsChangedPacket(Creature const* bot, WorldPacket* data)
{
    uint32 mask = bot->GetBotAI()->GetGroupUpdateFlag();

    if (mask == GROUP_UPDATE_FLAG_NONE)
        return;

    if (mask & GROUP_UPDATE_FLAG_POWER_TYPE)                // if update power type, update current/max power also
        mask |= (GROUP_UPDATE_FLAG_CUR_POWER | GROUP_UPDATE_FLAG_MAX_POWER);

    if (mask & GROUP_UPDATE_FLAG_PET_POWER_TYPE)            // same for pets
        mask |= (GROUP_UPDATE_FLAG_PET_CUR_POWER | GROUP_UPDATE_FLAG_PET_MAX_POWER);

    uint32 byteCount = 0;
    for (int i = 1; i < GROUP_UPDATE_FLAGS_COUNT; ++i)
        if (mask & (1 << i))
            byteCount += GroupUpdateLength[i];

    data->Initialize(SMSG_PARTY_MEMBER_STATS, size_t(8 + 4 + byteCount));
    *data << bot->GetPackGUID();
    *data << uint32(mask);

    if (mask & GROUP_UPDATE_FLAG_STATUS)
    {
        uint16 playerStatus = MEMBER_STATUS_ONLINE;
        if (bot->IsPvP())
            playerStatus |= MEMBER_STATUS_PVP;

        if (!bot->IsAlive())
            playerStatus |= MEMBER_STATUS_DEAD;

        if (bot->IsFFAPvP())
            playerStatus |= MEMBER_STATUS_PVP_FFA;

        *data << uint16(playerStatus);
    }

    if (mask & GROUP_UPDATE_FLAG_CUR_HP)
        *data << uint32(bot->GetHealth());

    if (mask & GROUP_UPDATE_FLAG_MAX_HP)
        *data << uint32(bot->GetMaxHealth());

    Powers powerType = bot->GetPowerType();
    if (mask & GROUP_UPDATE_FLAG_POWER_TYPE)
        *data << uint8(powerType);

    if (mask & GROUP_UPDATE_FLAG_CUR_POWER)
        *data << uint16(bot->GetPower(powerType));

    if (mask & GROUP_UPDATE_FLAG_MAX_POWER)
        *data << uint16(bot->GetMaxPower(powerType));

    if (mask & GROUP_UPDATE_FLAG_LEVEL)
        *data << uint16(bot->GetLevel());

    if (mask & GROUP_UPDATE_FLAG_ZONE)
        *data << uint16(bot->GetZoneId());

    if (mask & GROUP_UPDATE_FLAG_POSITION)
    {
        *data << uint16(bot->GetPositionX());
        *data << uint16(bot->GetPositionY());
    }

    if (mask & GROUP_UPDATE_FLAG_AURAS)
    {
        uint64 auramask = GetBotAuraUpdateMaskForRaid(bot);
        *data << uint64(auramask);
        for (uint32 i = 0; i < MAX_AURAS_GROUP_UPDATE; ++i)
        {
            if (auramask & (uint64(1) << i))
            {
                AuraApplication const* aurApp = bot->GetVisibleAura(i);
                *data << uint32(aurApp ? aurApp->GetBase()->GetId() : 0);
                *data << uint8(1);
            }
        }
    }

    Creature const* pet = nullptr; //bot->GetBotAI()->GetBotsPet();
    if (mask & GROUP_UPDATE_FLAG_PET_GUID)
    {
        if (pet)
            *data << (uint64) pet->GetGUID();
        else
            *data << (uint64) 0;
    }

    if (mask & GROUP_UPDATE_FLAG_PET_NAME)
    {
        if (pet)
            *data << pet->GetName();
        else
            *data << uint8(0);
    }

    if (mask & GROUP_UPDATE_FLAG_PET_MODEL_ID)
    {
        if (pet)
            *data << uint16(pet->GetDisplayId());
        else
            *data << uint16(0);
    }

    if (mask & GROUP_UPDATE_FLAG_PET_CUR_HP)
    {
        if (pet)
            *data << uint32(pet->GetHealth());
        else
            *data << uint32(0);
    }

    if (mask & GROUP_UPDATE_FLAG_PET_MAX_HP)
    {
        if (pet)
            *data << uint32(pet->GetMaxHealth());
        else
            *data << uint32(0);
    }

    if (mask & GROUP_UPDATE_FLAG_PET_POWER_TYPE)
    {
        if (pet)
            *data << uint8(pet->GetPowerType());
        else
            *data << uint8(0);
    }

    if (mask & GROUP_UPDATE_FLAG_PET_CUR_POWER)
    {
        if (pet)
            *data << uint16(pet->GetPower(pet->GetPowerType()));
        else
            *data << uint16(0);
    }

    if (mask & GROUP_UPDATE_FLAG_PET_MAX_POWER)
    {
        if (pet)
            *data << uint16(pet->GetMaxPower(pet->GetPowerType()));
        else
            *data << uint16(0);
    }

    if (mask & GROUP_UPDATE_FLAG_PET_AURAS)
    {
        if (pet)
        {
            uint64 auramask = GetBotPetAuraUpdateMaskForRaid(pet);
            *data << uint64(auramask);
            for (uint32 i = 0; i < MAX_AURAS_GROUP_UPDATE; ++i)
            {
                if (auramask & (uint64(1) << i))
                {
                    AuraApplication const* aurApp = pet->GetVisibleAura(i);
                    *data << uint32(aurApp ? aurApp->GetBase()->GetId() : 0);
                    *data << uint8(aurApp ? aurApp->GetFlags() : 0);
                }
            }
        }
        else
            *data << uint64(0);
    }

    if (mask & GROUP_UPDATE_FLAG_VEHICLE_SEAT)
    {
        if (Vehicle* veh = bot->GetVehicle())
            *data << uint32(veh->GetVehicleInfo()->SeatID[bot->m_movementInfo.transport.seat]);
        else
            *data << uint32(0);
    }
}

//uint32 BotMgr::GetBotGroupUpdateFlag(Creature const* bot)
//{
//    bot->GetBotAI()->GetGroupUpdateFlags
//}
void BotMgr::SetBotGroupUpdateFlag(Creature const* bot, uint32 flag)
{
    bot->GetBotAI()->SetGroupUpdateFlag(flag);
}
uint64 BotMgr::GetBotAuraUpdateMaskForRaid(Creature const* bot)
{
    return bot->GetBotAI()->GetAuraUpdateMaskForRaid();
}
void BotMgr::SetBotAuraUpdateMaskForRaid(Creature const* bot, uint8 slot)
{
    bot->GetBotAI()->SetAuraUpdateMaskForRaid(slot);
}
void BotMgr::ResetBotAuraUpdateMaskForRaid(Creature const* bot)
{
    bot->GetBotAI()->ResetAuraUpdateMaskForRaid();
}
uint64 BotMgr::GetBotPetAuraUpdateMaskForRaid(Creature const* botpet)
{
    return botpet->GetBotPetAI()->GetAuraUpdateMaskForRaid();
}
void BotMgr::SetBotPetAuraUpdateMaskForRaid(Creature const* botpet, uint8 slot)
{
    botpet->GetBotPetAI()->SetAuraUpdateMaskForRaid(slot);
}
void BotMgr::ResetBotPetAuraUpdateMaskForRaid(Creature const* botpet)
{
    botpet->GetBotPetAI()->ResetAuraUpdateMaskForRaid();
}

uint8 BotMgr::GetBotFollowDist() const
{
    return _data->dist_follow;
}
void BotMgr::SetBotFollowDist(uint8 dist)
{
    _data->dist_follow = dist;
}

void BotMgr::_setBotExactAttackRange(uint8 exactRange)
{
    _data->dist_attack = exactRange;
}

uint8 BotMgr::GetBotExactAttackRange() const
{
    return _data->dist_attack;
}
uint8 BotMgr::GetBotAttackRangeMode() const
{
    return _data->attack_range_mode;
}
void BotMgr::SetBotAttackRangeMode(uint8 mode, uint8 exactRange)
{
    _data->attack_range_mode = mode; _setBotExactAttackRange(exactRange);
}

uint8 BotMgr::GetBotAttackAngleMode() const
{
    return _data->attack_angle_mode;
}
void BotMgr::SetBotAttackAngleMode(uint8 mode)
{
    _data->attack_angle_mode = mode;
}

bool BotMgr::GetBotAllowCombatPositioning() const
{
    return !_data->HasFlag(NPCBOT_MGR_FLAG_DISABLE_COMBAT_POSITIONING);
}
void BotMgr::SetBotAllowCombatPositioning(bool allow)
{
    allow ? _data->RemoveFlag(NPCBOT_MGR_FLAG_DISABLE_COMBAT_POSITIONING) : _data->SetFlag(NPCBOT_MGR_FLAG_DISABLE_COMBAT_POSITIONING);
}

void BotMgr::SetBotsHidden(bool hidden)
{
    hidden ? _data->SetFlag(NPCBOT_MGR_FLAG_HIDE_BOTS) : _data->RemoveFlag(NPCBOT_MGR_FLAG_HIDE_BOTS);
}

uint32 BotMgr::GetEngageDelayDPS() const
{
    return _data->engage_delay_dps;
}
uint32 BotMgr::GetEngageDelayHeal() const { return _data->engage_delay_heal;
}
void BotMgr::SetEngageDelayDPS(uint32 delay)
{
    _data->engage_delay_dps = delay;
}
void BotMgr::SetEngageDelayHeal(uint32 delay)
{
    _data->engage_delay_heal = delay;
}

void BotMgr::PropagateEngageTimers() const
{
    uint32 delay_dps = GetEngageDelayDPS();
    uint32 delay_heal = GetEngageDelayHeal();

    if (!delay_dps && !delay_heal)
        return;

    for (BotMap::const_iterator itr = _bots.begin(); itr != _bots.end(); ++itr)
    {
        if (itr->second->GetBotAI()->IsTank())
            continue;

        bool is_heal = itr->second->GetBotAI()->HasRole(BOT_ROLE_HEAL);
        bool is_dps= itr->second->GetBotAI()->HasRole(BOT_ROLE_DPS);
        uint32 delay = (is_heal && is_dps) ? std::max<uint32>(delay_dps, delay_heal) : is_heal ? delay_heal : is_dps ? delay_dps : 0;

        itr->second->GetBotAI()->ResetEngageTimer(delay);
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
            for (GroupReference const* gitr = gr->GetFirstMember(); gitr != nullptr; gitr = gitr->next())
            {
                if (gitr->GetSource() == nullptr) continue;
                if (_owner->GetMap() != gitr->GetSource()->FindMap()) continue;

                if (gitr->GetSource()->HaveBot())
                {
                    BotMap const* map = gitr->GetSource()->GetBotMgr()->GetBotMap();
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
                if (spellInfo->_effects[j].Effect != SPELL_EFFECT_HEAL)
                    continue;

                if (targetGuid != unit->GetGUID())
                {
                    if (spellInfo->_effects[j].TargetA.GetSelectionCategory() != TARGET_SELECT_CATEGORY_AREA)
                        continue;

                    //Targets t = spellInfo->_effects[j].TargetA.GetTarget();
                    //non-existing case
                    //if (t == TARGET_UNIT_CASTER_AREA_PARTY && !gr->SameSubGroup(u->GetGUID(), unit->GetGUID()))
                    //    continue;
                    Targets t = spellInfo->_effects[j].TargetB.GetTarget();
                    if (t == TARGET_UNIT_LASTTARGET_AREA_PARTY &&
                        !(GetBot(unit->GetGUID()) && GetBot(targetGuid)) &&
                        !gr->SameSubGroup(unit->GetGUID(), targetGuid))
                        continue;
                }

                int32 healing = u->SpellHealingBonusDone(const_cast<Unit*>(unit), spellInfo, spellInfo->_effects[0].CalcValue(u), HEAL, spellInfo->GetEffect(EFFECT_0), {});
                healing = unit->SpellHealingBonusTaken(u, spellInfo, healing, HEAL);

                if (i == CURRENT_CHANNELED_SPELL)
                    amount += int32(healing / (spellInfo->_effects[j].Amplitude * 0.001f));
                else
                    amount += int32(healing / (std::max<int32>(spell->GetTimer(), 1000) * 0.001f));

                //TC_LOG_ERROR("entities.player", "BotMgr:pendingHeals: found {}'s {} on {} in {} ({}, total {})",
                //    u->GetName(), spellInfo->SpellName[0], target->GetName(), pheal->delay, healing, pheal->amount);
            }

            break;
        }
    }

    //HoTs
    Unit::AuraEffectList const& hots = unit->GetAuraEffectsByType(SPELL_AURA_PERIODIC_HEAL);
    for (Unit::AuraEffectList::const_iterator itr = hots.begin(); itr != hots.end(); ++itr)
        amount += int32((*itr)->GetAmount() / ((*itr)->GetAmplitude() * 0.001f));

    //if (amount != 0)
    //    TC_LOG_ERROR("entities.player", "BotMgr:GetHPSTaken(): {} got {})", unit->GetName(), amount);

    return amount;
}

void BotMgr::OnBotWandererKilled(Creature const* bot, Player* looter)
{
    bot->GetBotAI()->SpawnKillReward(looter);
}

void BotMgr::OnBotWandererKilled(GameObject* go)
{
    if (go->GetEntry() == GO_BOT_MONEY_BAG && go->GetSpellId() > go->GetEntry())
    {
        uint32 bot_id = go->GetSpellId() - GO_BOT_MONEY_BAG;
        if (Creature const* bot = BotDataMgr::FindBot(bot_id))
            bot->GetBotAI()->FillKillReward(go);
    }
}

void BotMgr::OnBotKilled(Creature const* bot, Unit* attacker/* = nullptr*/)
{
    bot->GetBotAI()->OnDeath(attacker);
}

void BotMgr::OnBotSpellInterrupt(Unit const* caster, CurrentSpellTypes spellType)
{
    if (spellType == CURRENT_AUTOREPEAT_SPELL)
    {
        WorldPackets::Combat::CancelAutoRepeat cancelAutoRepeat;
        cancelAutoRepeat.Guid = caster->GetPackGUID();
        caster->SendMessageToSet(cancelAutoRepeat.Write(), true);
    }
}

void BotMgr::OnBotSpellGo(Unit const* caster, Spell const* spell, bool ok)
{
    if (caster->ToCreature()->GetBotAI())
        caster->ToCreature()->GetBotAI()->OnBotSpellGo(spell, ok);
    else if (caster->ToCreature()->GetBotPetAI())
        caster->ToCreature()->GetBotPetAI()->OnBotPetSpellGo(spell, ok);
}

void BotMgr::OnBotOwnerSpellGo(Unit const* caster, Spell const* spell, bool ok)
{
    BotMap const* bmap = caster->ToPlayer()->GetBotMgr()->GetBotMap();
    for (BotMap::const_iterator itr = bmap->begin(); itr != bmap->end(); ++itr)
    {
        if (Creature const* bot = itr->second)
        {
            if (!bot->IsInWorld() || !bot->IsAlive())
                continue;

            bot->GetBotAI()->OnBotOwnerSpellGo(spell, ok);
            //if (Creature const* botpet = bot->GetBotsPet())
            //    botpet->GetBotAI()->OnBotPetOwnerSpellGo(spell, ok);
        }
    }
}

void BotMgr::OnBotChannelFinish(Unit const* caster, Spell const* spell)
{
    if (caster->ToCreature()->GetBotAI())
        caster->ToCreature()->GetBotAI()->OnBotChannelFinish(spell);
    //else if (caster->ToCreature()->GetBotPetAI())
    //    caster->ToCreature()->GetBotPetAI()->OnBotPetChannelFinish(spell);
}

void BotMgr::OnVehicleSpellGo(Unit const* caster, Spell const* spell, bool ok)
{
    if (caster->GetCharmerGUID().IsPlayer())
    {
        Unit const* owner = caster->GetCharmer();
        if (owner && owner->ToPlayer()->HaveBot())
        {
            BotMap const* bmap = owner->ToPlayer()->GetBotMgr()->GetBotMap();
            for (BotMap::const_iterator itr = bmap->begin(); itr != bmap->end(); ++itr)
            {
                if (Creature const* bot = itr->second)
                {
                    bot->GetBotAI()->OnBotOwnerSpellGo(spell, ok);
                    //if (Creature const* botpet = bot->GetBotsPet())
                    //    botpet->GetBotAI()->OnBotPetOwnerSpellGo(spell, ok);
                }
            }
        }
    }
    else if (caster->GetCharmerGUID().IsCreature())
    {
        Unit const* bot = caster->GetCharmer();
        if (bot->ToCreature()->GetBotAI())
            bot->ToCreature()->GetBotAI()->OnBotSpellGo(spell, ok);
    }
}

void BotMgr::OnVehicleAttackedBy(Unit* attacker, Unit const* victim)
{
    Unit const* owner = victim->GetCharmer();
    if (victim->GetCharmerGUID().IsPlayer())
        owner = victim->GetCharmer();
    else if (victim->GetCharmerGUID().IsCreature())
        if (Unit const* bot = victim->GetCharmer())
            owner = bot->ToCreature()->GetBotOwner();

    if (owner && owner->GetTypeId() == TYPEID_PLAYER && owner->ToPlayer()->HaveBot())
    {
        BotMap const* bmap = owner->ToPlayer()->GetBotMgr()->GetBotMap();
        for (BotMap::const_iterator itr = bmap->begin(); itr != bmap->end(); ++itr)
            if (Creature const* bot = itr->second)
                bot->GetBotAI()->OnOwnerVehicleDamagedBy(attacker);
    }
}

void BotMgr::OnBotDamageTaken(Unit* attacker, Unit* victim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellInfo const* spellInfo)
{
    victim->ToCreature()->GetBotAI()->OnBotDamageTaken(attacker, damage, cleanDamage , damagetype, spellInfo);
}

void BotMgr::OnBotDamageDealt(Unit* attacker, Unit* victim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellInfo const* spellInfo)
{
    attacker->ToCreature()->GetBotAI()->OnBotDamageDealt(victim, damage, cleanDamage, damagetype, spellInfo);
}

void BotMgr::OnBotDispelDealt(Unit* dispeller, Unit* dispelled, uint8 num)
{
    dispeller->ToCreature()->GetBotAI()->OnBotDispelDealt(dispelled, num);
}

void BotMgr::OnBotEnterVehicle(Creature const* passenger, Vehicle const* vehicle)
{
    passenger->GetBotAI()->OnBotEnterVehicle(vehicle);
}

void BotMgr::OnBotExitVehicle(Creature const* passenger, Vehicle const* vehicle)
{
    passenger->GetBotAI()->OnBotExitVehicle(vehicle);
}

void BotMgr::OnBotOwnerEnterVehicle(Player const* passenger, Vehicle const* vehicle)
{
    BotMap const* bmap = passenger->GetBotMgr()->GetBotMap();
    for (BotMap::const_iterator itr = bmap->begin(); itr != bmap->end(); ++itr)
        if (Creature const* bot = itr->second)
            if (bot->IsInWorld() && bot->IsAlive())
                bot->GetBotAI()->OnBotOwnerEnterVehicle(vehicle);
}

void BotMgr::OnBotOwnerExitVehicle(Player const* passenger, Vehicle const* vehicle)
{
    BotMap const* bmap = passenger->GetBotMgr()->GetBotMap();
    for (BotMap::const_iterator itr = bmap->begin(); itr != bmap->end(); ++itr)
        if (Creature const* bot = itr->second)
            if (bot->IsInWorld() && bot->IsAlive())
                bot->GetBotAI()->OnBotOwnerExitVehicle(vehicle);
}

void BotMgr::OnBotPartyEngage(Player const* owner)
{
    Group const* gr = owner->GetGroup();
    if (gr)
    {
        std::vector<Player const*> affectedPlayers;
        for (GroupReference const* itr = gr->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            Player const* player = itr->GetSource();
            if (!player || owner->GetMap() != player->FindMap() ||
                player->GetDistance(owner) > sWorld->GetMaxVisibleDistanceOnContinents() ||
                !player->HaveBot())
                continue;

            if (player->GetBotMgr()->IsPartyInCombat())
                return;

            affectedPlayers.push_back(player);
        }
        for (Player const* p : affectedPlayers)
            p->GetBotMgr()->PropagateEngageTimers();
    }
    else
        owner->GetBotMgr()->PropagateEngageTimers();
}

void BotMgr::ApplyBotEffectMods(Unit const* caster, SpellInfo const* spellInfo, uint8 effIndex, float& value)
{
    caster->ToCreature()->GetBotAI()->ApplyBotEffectMods(spellInfo, effIndex, value);
}

void BotMgr::ApplyBotThreatMods(Unit const* attacker, SpellInfo const* spellInfo, float& threat)
{
    attacker->ToCreature()->GetBotAI()->ApplyBotThreatMods(spellInfo, threat);
}

void BotMgr::ApplyBotEffectValueMultiplierMods(Unit const* caster, SpellInfo const* spellInfo, SpellEffIndex effIndex, float& multiplier)
{
    caster->ToCreature()->GetBotAI()->ApplyBotEffectValueMultiplierMods(spellInfo, effIndex, multiplier);
}

float BotMgr::GetBotDamageTakenMod(Creature const* bot, bool magic)
{
    return bot->GetBotAI()->GetBotDamageTakenMod(magic);
}

int32 BotMgr::GetBotStat(Creature const* bot, BotStatMods stat)
{
    return bot->GetBotAI()->GetTotalBotStat(stat);
}

float BotMgr::GetBotResilience(Creature const* botOrPet)
{
    if (botOrPet->IsNPCBot())
        return botOrPet->GetBotAI()->GetBotResilience();

    return botOrPet->GetBotPetAI()->GetPetsOwner()->GetBotAI()->GetBotResilience();
}

float BotMgr::GetBotDamageModPhysical()
{
    return _mult_dmg_physical;
}
float BotMgr::GetBotDamageModSpell()
{
    return _mult_dmg_spell;
}
float BotMgr::GetBotHealingMod()
{
    return _mult_healing;
}
float BotMgr::GetBotHPMod()
{
    return _mult_hp;
}
float BotMgr::GetBotWandererDamageMod()
{
    return _mult_dmg_wanderer;
}
float BotMgr::GetBotWandererHealingMod()
{
    return _mult_healing_wanderer;
}
float BotMgr::GetBotWandererHPMod()
{
    return _mult_hp_wanderer;
}
float BotMgr::GetBotWandererSpeedMod()
{
    return _mult_speed_wanderer;
}
float BotMgr::GetBotWandererXPGainMod()
{
    return _mult_xpgain_wanderer;
}
PctBrackets BotMgr::GetBotWandererLevelBrackets()
{
    return _botwanderer_pct_level_brackets;
}
float BotMgr::GetBotDamageModByClass(uint8 botclass)
{
    switch (botclass)
    {
        case BOT_CLASS_WARRIOR:
            return _mult_dmg_warrior;
        case BOT_CLASS_PALADIN:
            return _mult_dmg_paladin;
        case BOT_CLASS_HUNTER:
            return _mult_dmg_hunter;
        case BOT_CLASS_ROGUE:
            return _mult_dmg_rogue;
        case BOT_CLASS_PRIEST:
            return _mult_dmg_priest;
        case BOT_CLASS_DEATH_KNIGHT:
            return _mult_dmg_deathknight;
        case BOT_CLASS_SHAMAN:
            return _mult_dmg_shaman;
        case BOT_CLASS_MAGE:
            return _mult_dmg_mage;
        case BOT_CLASS_WARLOCK:
            return _mult_dmg_warlock;
        case BOT_CLASS_DRUID:
            return _mult_dmg_druid;
        case BOT_CLASS_BM:
            return _mult_dmg_blademaster;
        case BOT_CLASS_SPHYNX:
            return _mult_dmg_obsidiandestroyer;
        case BOT_CLASS_ARCHMAGE:
            return _mult_dmg_archmage;
        case BOT_CLASS_DREADLORD:
            return _mult_dmg_dreadlord;
        case BOT_CLASS_SPELLBREAKER:
            return _mult_dmg_spellbreaker;
        case BOT_CLASS_DARK_RANGER:
            return _mult_dmg_darkranger;
        case BOT_CLASS_NECROMANCER:
            return _mult_dmg_necromancer;
        case BOT_CLASS_SEA_WITCH:
            return _mult_dmg_seawitch;
        case BOT_CLASS_CRYPT_LORD:
            return _mult_dmg_cryptlord;
        default:
            return 1.0;
    }
}

float BotMgr::GetBotDamageModByLevel(uint8 botlevel)
{
    uint8 bracket = botlevel / 10;
    if (bracket < _mult_dmg_levels.size())
        return _mult_dmg_levels[bracket];
    return 1.0f;
}

uint8 BotMgr::GetFollowDistDefault()
{
    return _basefollowdist;
}
uint32 BotMgr::GetEngageDelayDPSDefault()
{
    return _npcBotEngageDelayDPS_default;
}
uint32 BotMgr::GetEngageDelayHealDefault()
{
    return _npcBotEngageDelayHeal_default;
}

std::vector<Unit*> BotMgr::GetAllGroupMembers(Group const* group)
{
    std::vector<Unit*> group_members;
    if (group)
    {
        group_members.reserve(group->GetMembersCount());
        for (GroupReference const* ref = group->GetFirstMember(); ref != nullptr; ref = ref->next())
        {
            if (Player* pl = ref->GetSource())
                group_members.push_back(pl);
        }
        for (GroupBotReference const* ref = group->GetFirstBotMember(); ref != nullptr; ref = ref->next())
        {
            if (Creature* cr = ref->GetSource())
                group_members.push_back(cr);
        }
    }

    return group_members;
}
std::vector<Unit*> BotMgr::GetAllGroupMembers(Unit const* source)
{
    Group const* group = (source->IsNPCBot() && source->ToCreature()->GetBotAI()) ? source->ToCreature()->GetBotAI()->GetGroup() :
        source->IsPlayer() ? source->ToPlayer()->GetGroup() : nullptr;
    return GetAllGroupMembers(group);
}

void BotMgr::InviteBotToBG(ObjectGuid botguid, GroupQueueInfo* ginfo, Battleground* bg)
{
    Creature const* bot = BotDataMgr::FindBot(botguid.GetEntry());
    ASSERT(bot);

    bg->IncreaseInvitedCount(ginfo->Team);
    //TC_LOG_INFO("npcbots", "Battleground: invited NPCBot {} to BG instance {} bgtype {} '{}'",
    //    botguid.GetEntry(), bg->GetInstanceID(), bg->GetTypeID(), bg->GetName());
}

bool BotMgr::IsBotInAreaTriggerRadius(Creature const* bot, AreaTriggerEntry const* trigger)
{
    if (!trigger || !bot->IsInWorld() || bot->GetMap()->GetId() != trigger->ContinentID)
        return false;

    if (trigger->Radius > 0.f)
    {
        // if we have radius check it
        float dist = bot->GetDistance(trigger->Pos.X, trigger->Pos.Y, trigger->Pos.Z);
        if (dist > trigger->Radius)
            return false;
    }
    else
    {
        Position center(trigger->Pos.X, trigger->Pos.Y, trigger->Pos.Z, trigger->BoxYaw);
        if (!bot->IsWithinBox(center, trigger->BoxLength / 2.f, trigger->BoxWidth / 2.f, trigger->BoxHeight / 2.f))
            return false;
    }

    return true;
}

BotMgr::delayed_teleport_mutex_type* BotMgr::_getTpLock()
{
    static BotMgr::delayed_teleport_mutex_type _lock;
    return &_lock;
}
void BotMgr::AddDelayedTeleportCallback(delayed_teleport_callback_type&& callback)
{
    delayed_teleport_lock_type lock(*_getTpLock());
    delayed_bot_teleports.push_back(std::forward<delayed_teleport_callback_type>(callback));
}
void BotMgr::HandleDelayedTeleports()
{
    for (auto& func : delayed_bot_teleports)
        func();
    delayed_bot_teleports.clear();
}

#ifdef _MSC_VER
# pragma warning(pop)
#endif
