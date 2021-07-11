/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef MANGOSSERVER_CHAT_H
#define MANGOSSERVER_CHAT_H

#include "ObjectGuid.h"
#include "StringFormat.h"
#include <fmt/printf.h>
#include "Common.h"
#include "SharedDefines.h"
#include "ObjectGuid.h"

struct AreaTriggerTeleport;
struct AreaTriggerEntry;
struct FactionEntry;
struct FactionState;
struct GameTele;
class SpellEntry;

class QueryResult;
class ChatHandler;
class WorldSession;
class WorldPacket;
class MailDraft;
class Object;
class GameObject;
class Creature;
class Player;
class Unit;
class Pet;
class GmTicket;
struct ItemPrototype;
struct SkillLineEntry;

#define SPELL_PLAYER_MUTED_VISUAL 1852

enum LocaleConstant : uint8;

class TC_GAME_API ChatHandler
enum CommandFlags
{
    COMMAND_FLAGS_ONLY_ON_SELF      = 0x1,
    COMMAND_FLAGS_CRITICAL          = 0x2,
};

class ChatCommand
{
public:
        char const*        Name;
        uint8              SecurityLevel;                   // function pointer required correct align (use uint32)
        bool               AllowConsole;
        bool (ChatHandler::*Handler)(char* args);
        std::string        Help;
        ChatCommand *      ChildCommands;
        uint8              Flags;
        std::string        FullName;
};

enum ChatCommandSearchResult
{
    CHAT_COMMAND_OK,                                        // found accessible command by command string
    CHAT_COMMAND_UNKNOWN,                                   // first level command not found
    CHAT_COMMAND_UNKNOWN_SUBCOMMAND,                        // command found but some level subcommand not find in subcommand list
};

enum PlayerChatTag
{
    CHAT_TAG_NONE               = 0,
    CHAT_TAG_AFK                = 1,
    CHAT_TAG_DND                = 2,
    CHAT_TAG_GM                 = 3,
};

class PartyBotAI;
class BattleBotAI;

class ChatHandler
{
    friend class PartyBotAI;
    friend class BattleBotAI;
    public:
        bool IsConsole() const { return (m_session == nullptr); }
        WorldSession* GetSession() { return m_session; }
        WorldSession const* GetSession() const { return m_session; }
        Player* GetPlayer() const;
        explicit ChatHandler(WorldSession* session) : m_session(session), sentErrorMessage(false) { }
        virtual ~ChatHandler() { }
        explicit ChatHandler(WorldSession* session);
        explicit ChatHandler(Player* player);
        virtual ~ChatHandler();

        static char* LineFromMessage(char*& pos);
        static char* LineFromMessage(char*& pos) { char* start = strtok(pos,"\n"); pos = nullptr; return start; }

        // function with different implementation for chat/console
        virtual char const* GetTrinityString(uint32 entry) const;
        virtual void SendSysMessage(std::string_view str, bool escapeCharacters = false);
        virtual char const* GetMangosString(int32 entry) const;
        char const* GetOnOffStr(bool value) const;

        virtual void SendSysMessage(char const* str);

        template<typename... Args>
        void PSendSysMessage(const char* fmt, Args&&... args)
        {
            SendSysMessage(fmt::sprintf(fmt, std::forward<Args>(args)...));
        }
        void SendSysMessage(int32 entry);
        void PSendSysMessage(char const* format, ...) ATTR_PRINTF(2,3);
        void PSendSysMessage(int32 entry, ...  );
        std::string PGetParseString(int32 entry, ...);

        bool ParseCommands(char const* text);
        ChatCommand const* FindCommand(char const* text);

        template<typename... Args>
        std::string PGetParseString(uint32 entry, Args&&... args) const
        {
            return fmt::sprintf(GetTrinityString(entry), std::forward<Args>(args)...);
        }
        bool isValidChatMessage(char const* msg);
        bool HasSentErrorMessage() { return sentErrorMessage;}

        bool _ParseCommands(std::string_view text);
        virtual bool ParseCommands(std::string_view text);
        std::string playerLink(std::string const& name) const { return m_session ? "|cffffffff|Hplayer:"+name+"|h["+name+"]|h|r" : name; }
        std::string GetNameLink(Player* chr) const;
        std::string GetItemLink(ItemPrototype const* pItem) const;

        GameObject* GetGameObjectWithGuid(uint32 lowguid,uint32 entry);
        WorldSession* GetSession() { return m_session; }

        void SendGlobalSysMessage(const char *str);
        void SendBanResult(BanMode mode, BanReturn result, std::string& banTarget, uint32 duration_secs, std::string& reason);

        /**
        * \brief Prepare SMSG_GM_MESSAGECHAT/SMSG_MESSAGECHAT
        *
        * Method:    BuildChatPacket build message chat packet generic way
        * FullName:  ChatHandler::BuildChatPacket
        * Access:    public static
        * Returns:   void
        *
        * \param WorldPacket& data             : Provided packet will be filled with requested info
        * \param ChatMsg msgtype               : Message type from ChatMsg enum from SharedDefines.h
        * \param uint32 chatTag                : Chat tag from PlayerChatTag in Chat.h
        * \param char const* message           : Message to send
        * \param Language language             : Language from Language enum in SharedDefines.h
        * \param ObjectGuid const& senderGuid  : May be null in some case but often required for ignore list
        * \param char const* senderName        : Required for type *MONSTER* or *BATTLENET, but also if GM is true
        * \param ObjectGuid const& targetGuid  : Often null, but needed for type *MONSTER* or *BATTLENET or *BATTLEGROUND* or *ACHIEVEMENT
        * \param char const* targetName        : Often null, but needed for type *MONSTER* or *BATTLENET or *BATTLEGROUND*
        * \param char const* channelName       : Required only for CHAT_MSG_CHANNEL
        * \param uint8 playerRank              : Used only for Defensive Channels (Value over 0 will show rank name before character name in channel)
        **/
        static void BuildChatPacket(
            WorldPacket& data, ChatMsg msgtype, char const* message, Language language = LANG_UNIVERSAL, uint32 chatTag = CHAT_TAG_NONE,
            ObjectGuid const& senderGuid = ObjectGuid(), char const* senderName = nullptr,
            ObjectGuid const& targetGuid = ObjectGuid(), char const* targetName = nullptr,
            char const* channelName = nullptr, uint8 playerRank = 0);
    protected:
        explicit ChatHandler() : m_session(nullptr), sentErrorMessage(false) {}      // for CLI subclass

        bool hasStringAbbr(char const* name, char const* part);

        // function with different implementation for chat/console
        virtual uint32 GetAccountId() const;
        virtual AccountTypes GetAccessLevel() const;
        virtual bool isAvailable(ChatCommand const& cmd) const;
        virtual std::string GetNameLink() const;
        virtual bool needReportToTarget(Player* chr) const;
        virtual LocaleConstant GetSessionDbcLocale() const;
        virtual int GetSessionDbLocaleIndex() const;

        bool HasLowerSecurity(Player* target, ObjectGuid guid = ObjectGuid(), bool strong = false);
        bool HasLowerSecurityAccount(WorldSession* target, uint32 account, bool strong = false);

        void SendGlobalGMSysMessage(const char *str);
        Player* getSelectedPlayer();
        Creature* getSelectedCreature();
        Unit* getSelectedUnit();
        WorldObject* getSelectedObject();
        // Returns either the selected player or self if there is no selected player
        Player* getSelectedPlayerOrSelf();
        void SendGlobalSysMessage(char const* str);

        bool SetDataForCommandInTable(ChatCommand *table, char const* text, uint8 security, std::string const& help, uint8 flags);
        void ExecuteCommand(char const* text);
        bool ShowHelpForCommand(ChatCommand *table, char const* cmd);
        bool ShowHelpForSubCommands(ChatCommand *table, char const* cmd);
        ChatCommandSearchResult FindCommand(ChatCommand* table, char const*& text, ChatCommand*& command, ChatCommand** parentCommand = nullptr, std::string* cmdNamePtr = nullptr, bool allAvailable = false, bool exactlyName = false);

        void CheckIntegrity(ChatCommand *table, ChatCommand *parentCommand);
        void FillFullCommandsName(ChatCommand* table, std::string prefix);
        ChatCommand* getCommandTable();
        
        bool HandleAnticheatCommand(char*);
        bool HandleClientInfosCommand(char*);
        bool HandleClientSearchCommand(char*);
        bool HandleReloadAnticheatCommand(char*);
        bool HandleViewLogCommand(char*);

        //Cheats
        bool HandleCheatStatusCommand(char *);
        bool HandleCheatGodCommand(char *);
        bool HandleCheatCooldownCommand(char *);
        bool HandleCheatCastTimeCommand(char *);
        bool HandleCheatPowerCommand(char *);
        bool HandleCheatDebuffImmunityCommand(char *);
        bool HandleCheatAlwaysCritCommand(char *);
        bool HandleCheatNoCastCheckCommand(char *);
        bool HandleCheatAlwaysProcCommand(char *);
        bool HandleCheatTriggerPassCommand(char *);
        bool HandleCheatIgnoreTriggersCommand(char *);
        bool HandleCheatWaterwalkCommand(char* args);
        bool HandleCheatWallclimbCommand(char* args);

        //Custom
        bool HandleListAddonsCommand(char *);
        bool HandleUpdateWorldStateCommand(char *);
        bool HandleSendSpellVisualCommand(char *);
        bool HandleSendSpellImpactCommand(char *);
        bool HandleDebugUnitCommand(char *);
        bool HandleDebugTimeCommand(char *);
        bool HandleDebugMoveFlagsCommand(char *);
        bool HandleDebugMoveSplineCommand(char *);
        bool HandleDebugExp(char*);
        bool HandleVideoTurn(char*);
        bool HandleDebugLootTableCommand(char*);
        bool HandleDebugItemEnchantCommand(int lootid, unsigned int simCount);
        bool HandleServiceDeleteCharacters(char* args);

        bool HandleSpamerMute(char* args);
        bool HandleSpamerUnmute(char* args);
        bool HandleSpamerList(char* args);
        bool HandleWhisperRestrictionCommand(char* args);
        bool HandleUnstuckCommand(char* args);
        bool HandleGoldRemoval(char* args);
        bool HandleAntiSpamAdd(char* args);
        bool HandleAntiSpamRemove(char* args);
        bool HandleAntiSpamReplace(char* args);
        bool HandleAntiSpamRemoveReplace(char* args);

        // Packet dump
        bool HandleReplayPlayCommand(char *);
        bool HandleReplayRecordCommand(char *);
        bool HandleReplayForwardCommand(char*);
        bool HandleReplayStopCommand(char*);
        bool HandleReplaySpeedCommand(char*);
        bool HandleDebugRecvPacketDumpWrite(char *);
        // Mmaps
        bool HandleMmap(char* args);
        bool HandleMmapConnection(char* args);
        bool HandleMmapTestArea(char* args);
        bool HandleMmapDebug(char* args);
        bool HandleMmapUnload(char *args);
        bool HandleMmapLoad(char* args);
        bool HandleMmapPathCommand(char* args);
        bool HandleMmapLocCommand(char* args);
        bool HandleMmapLoadedTilesCommand(char* args);
        bool HandleMmapStatsCommand(char* args);

        bool HandleDebugMoveToCommand(char* args);
        bool HandleDebugMoveDistanceCommand(char* args);
        bool HandleDebugFaceMeCommand(char* args);
        // AHBot
        bool HandleAHBotReloadCommand(char *);
        bool HandleAHBotUpdateCommand(char *);
        //Bg
        bool HandleGoWarsongCommand(char *);
        bool HandleGoArathiCommand(char *);
        bool HandleGoAlteracCommand(char*);
        // Bots commandes
        bool HandleBotAddAllCommand(char *);
        bool HandleBotAddRandomCommand(char *args);
        bool HandleBotAddCommand(char * args);
        bool HandleBotDeleteCommand(char * args);
        bool HandleBotInfoCommand(char * args);
        bool HandleBotReloadCommand(char * args);
        bool HandleBotStopCommand(char * args);
        bool HandleBotStartCommand(char * args);
        bool PartyBotAddRequirementCheck(Player const* pPlayer, Player const* pTarget);
        bool HandlePartyBotAddCommand(char * args);
        bool HandlePartyBotCloneCommand(char * args);
        bool HandlePartyBotSetRoleCommand(char * args);
        bool HandlePartyBotAttackStartCommand(char * args);
        bool HandlePartyBotAttackStopCommand(char * args);
        bool HandlePartyBotAoECommand(char * args);
        bool HandlePartyBotControlMarkCommand(char * args);
        bool HandlePartyBotFocusMarkCommand(char * args);
        bool HandlePartyBotClearMarksCommand(char * args);
        bool HandlePartyBotComeToMeCommand(char * args);
        bool HandlePartyBotUseGObjectCommand(char * args);
        bool HandlePartyBotPauseCommand(char * args);
        bool HandlePartyBotUnpauseCommand(char * args);
        bool HandlePartyBotRemoveCommand(char * args);
        bool HandleBattleBotAddCommand(char* args, uint8 bg);
        bool HandleBattleBotAddAlteracCommand(char* args);
        bool HandleBattleBotAddArathiCommand(char* args);
        bool HandleBattleBotAddWarsongCommand(char* args);
        bool HandleBattleBotRemoveCommand(char* args);
        bool HandleBattleBotShowPathCommand(char* args);
        bool HandleBattleBotShowAllPathsCommand(char* args);

        // spell_disabled
        bool HandleReloadSpellDisabledCommand(char *args);
        // AutoBroadCast
        bool HandleReloadAutoBroadcastCommand(char *args);
        // SpellMods
        bool HandleReloadSpellModsCommand(char *args);
        // MapLootDisabled
        bool HandleReloadMapLootDisabledCommand(char *args);
        // Autres reload
        bool HandleReloadCharacterPetCommand(char *args);
        bool HandleReloadSpellGroupCommand(char *args);
        bool HandleReloadSpellGroupStackRulesCommand(char *args);
        bool HandleGroupAddSpellCommand(char *args);
        bool HandleGroupSetRuleCommand(char *args);
        // Cinematic
        bool HandleReloadCinematicWaypointsCommand(char *args);
        bool HandleCinematicAddWpCommand(char *args);
        bool HandleCinematicGoTimeCommand(char *args);
        bool HandleCinematicListWpCommand(char *args);
        // script_waypoints
        bool HandleEscortAddWpCommand(char *args);
        bool HandleEscortModifyWpCommand(char *args);
        bool HandleEscortClearWpCommand(char *args);
        bool HandleEscortCreateCommand(char *args);
        bool HandleEscortShowWpCommand(char *args);
        bool HandleEscortHideWpCommand(char *args);
        // World Gestion
        bool HandleWorldUpdateCommand(char *args);
        bool HandleWorldTestCommand(char *args);
        bool HandleWorldDetailCommand(char *args);
        // Managing saved variables
        bool HandleVariableCommand(char* args);
        bool HandleReloadVariablesCommand(char* args);
        //  AQ variables
        bool HandleGetWarEffortResource(char* args);
        bool HandleSetWarEffortResource(char* args);
        // Deplacement
        bool HandleGoForwardCommand(char* args);
        bool HandleGoUpCommand(char* args);
        bool HandleGoRelativeCommand(char* args);
        // Other
        bool HandlePossessCommand(char* args);
        bool HandleDebugForceUpdateCommand(char *args);
        bool HandleGameObjectTempAddCommand(char *args);
        // Clean characters
        bool HandleCleanCharactersToDeleteCommand(char *args);
        bool HandleCleanCharactersItemsCommand(char *args);
        // Debug
        bool HandleDebugLoSCommand(char* args);
        bool HandleDebugLoSAllowCommand(char* args);
        bool HandleDebugAssertFalseCommand(char* args);
        bool HandleDebugPvPCreditCommand(char* args);
        bool HandleDebugMonsterChatCommand(char *args);
        // Formations
        bool HandleNpcGroupAddCommand(char *args);
        bool HandleNpcGroupAddRelCommand(char *args);
        bool HandleNpcGroupDelCommand(char *args);
        bool HandleNpcGroupLinkCommand(char* args);

        bool HandleReloadCreatureGroupsCommand(char *args);
        // Characters
        bool HandleCharacterChangeRaceCommand(char *args);
        bool HandleCharacterCopySkinCommand(char *args);
        bool HandleCharacterFillFlysCommand(char *args);
        bool HandleCharacterCityTitleCommand(char *args);
        bool HandleCharacterPremadeGearCommand(char *args);
        bool HandleCharacterPremadeSpecCommand(char *args);
        bool HandleCharacterPremadeSaveGearCommand(char *args);
        bool HandleCharacterPremadeSaveSpecCommand(char *args);
        bool HandleFactionChangeItemsCommand(char *args);
        // bg
        bool HandleBGStatusCommand(char *args);
        bool HandleBGStartCommand(char *args);
        bool HandleBGStopCommand(char *args);
        bool HandleBGCustomCommand(char *args);
        // Spell
        bool HandleSpellEffectsCommand(char *args);
        bool HandleSpellInfosCommand(char *args);
        bool HandleSpellSearchCommand(char *args);
        // Other
        bool HandleFreezeCommand(char *args);
        bool HandleUnfreezeCommand(char *args);
        bool HandleSpellIconFixCommand(char *args);
        bool HandleUnitStatCommand(char *args);
        bool HandleDebugControlCommand(char *args);
        // Reload
        bool HandleReloadCreatureTemplate(char* args);
        bool HandleReloadItemTemplate(char* args);
        bool HandleReloadMapTemplate(char* args);
        bool HandleReloadGameObjectTemplate(char* args);
        bool HandleReloadExplorationBaseXp(char* args);
        bool HandleReloadPetNameGeneration(char* args);
        bool HandleReloadCreatureOnKillReputation(char* args);
        bool HandleReloadGameWeather(char* args);
        bool HandleReloadFactionChangeReputations(char* args);
        bool HandleReloadFactionChangeSpells(char* args);
        bool HandleReloadFactionChangeItems(char* args);
        bool HandleReloadFactionChangeQuests(char* args);
        bool HandleReloadFactionChangeMounts(char* args);
        bool HandleReloadCreatureDisplayInfoAddon(char* args);
        bool HandleReloadIPBanList(char* args);
        bool HandleReloadAccountBanList(char* args);
        bool HandleReloadCreatureCommand(char* args);
        bool HandleReloadGameObjectCommand(char* args);
        bool HandleReloadInstanceBuffRemoval(char* args);
        bool HandleReloadPetitions(char* args);
        // Channel
        bool HandleChannelJoinCommand(char*);
        bool HandleChannelLeaveCommand(char*);

        bool HandleAccountCommand(char* args);
        bool HandleAccountCharactersCommand(char* args);
        bool HandleAccountCreateCommand(char* args);
        bool HandleAccountDeleteCommand(char* args);
        bool HandleAccountLockCommand(char* args);
        bool HandleAccountOnlineListCommand(char* args);
        bool HandleAccountPasswordCommand(char* args);
        bool HandleAccountSetAddonCommand(char* args);
        bool HandleAccountSetGmLevelCommand(char* args);
        bool HandleAccountSetPasswordCommand(char* args);
        bool HandleAccountSetLockedCommand(char* args);

        bool HandleAuctionAllianceCommand(char* args);
        bool HandleAuctionGoblinCommand(char* args);
        bool HandleAuctionHordeCommand(char* args);
        bool HandleAuctionCommand(char* args);

        bool HandleWarnCharacterCommand(char *args);
        bool HandleAddCharacterNoteCommand(char *args);
        bool HandleBanAccountCommand(char* args);
        bool HandleBanCharacterCommand(char* args);
        bool HandleBanIPCommand(char* args);
        bool HandleBanAllIPCommand(char* args);
        bool HandleBanInfoAccountCommand(char* args);
        bool HandleBanInfoCharacterCommand(char* args);
        bool HandleBanInfoIPCommand(char* args);
        bool HandleBanListAccountCommand(char* args);
        bool HandleBanListCharacterCommand(char* args);
        bool HandleBanListIPCommand(char* args);

        bool HandleCastCommand(char* args);
        bool HandleCastBackCommand(char* args);
        bool HandleCastDistCommand(char* args);
        bool HandleCastSelfCommand(char* args);
        bool HandleCastTargetCommand(char* args);

        bool HandleCharacterAIInfoCommand(char* args);
        bool HandleCharacterDeletedDeleteCommand(char* args);
        bool HandleCharacterDeletedListCommand(char* args, bool useName);
        bool HandleCharacterDeletedListAccountCommand(char* args);
        bool HandleCharacterDeletedListNameCommand(char* args);
        bool HandleCharacterDeletedRestoreCommand(char* args);
        bool HandleCharacterDeletedOldCommand(char* args);
        bool HandleCharacterEraseCommand(char* args);
        bool HandleCharacterLevelCommand(char* args);
        bool HandleCharacterRenameCommand(char* args);
        bool HandleCharacterReputationCommand(char* args);
        bool HandleCharacterHasItemCommand(char* args);

        bool HandleDebugAnimCommand(char* args);
        bool HandleDebugBattlegroundCommand(char* args);
        bool HandleDebugUnitBytes1Command(char* args);
        bool HandleDebugUnitBytes2Command(char* args);
        bool HandleDebugConditionCommand(char* args);
        bool HandleDebugGetItemStateCommand(char* args);
        bool HandleDebugGetItemValueCommand(char* args);
        bool HandleDebugGetLootRecipientCommand(char* args);
        bool HandleDebugGetValueByIndexCommand(char* args);
        bool HandleDebugGetValueByNameCommand(char* args);
        bool HandleDebugModItemValueCommand(char* args);
        bool HandleDebugModValueCommand(char* args);
        bool HandleDebugSetAuraStateCommand(char* args);
        bool HandleDebugSetItemValueCommand(char* args);
        bool HandleDebugSetValueByIndexCommand(char* args);
        bool HandleDebugSetValueByNameCommand(char* args);
        bool HandleDebugSpellCheckCommand(char* args);
        bool HandleDebugSpellCoefsCommand(char* args);
        bool HandleDebugSpellModsCommand(char* args);
        bool HandleDebugUpdateWorldStateCommand(char* args);
        bool HandleDebugOverflowCommand(char* args);
        bool HandleDebugChatFreezeCommand(char* args);

        bool HandleDebugPlayCinematicCommand(char* args);
        bool HandleDebugPlaySoundCommand(char* args);
        bool HandleDebugPlayScriptText(char* args);
        bool HandleDebugPlayMusicCommand(char* args);
        
        bool HandleDebugSendBuyErrorCommand(char* args);
        bool HandleDebugSendChannelNotifyCommand(char* args);
        bool HandleDebugSendChatMsgCommand(char* args);
        bool HandleDebugSendEquipErrorCommand(char* args);
        bool HandleDebugSendOpcodeCommand(char* args);
        bool HandleDebugSendPoiCommand(char* args);
        bool HandleDebugSendQuestPartyMsgCommand(char* args);
        bool HandleDebugSendQuestInvalidMsgCommand(char* args);
        bool HandleDebugSendMailErrorCommand(char* args);
        bool HandleDebugSendSellErrorCommand(char* args);
        bool HandleDebugSendSpellFailCommand(char* args);
        bool HandleDebugSendOpenBagCommand(char* args);

        /*
        Send the visual of the next channeled spell after args, suggested macro :
        /run if not f then f=ChatFrame_OnEvent ChatFrame_OnEvent=function(e)f(e)if p==0 and e=='CHAT_MSG_SYSTEM'then n=gsub(arg1,'%D*(%d*)%s.*','%1')end end end n=n or 0 SendChatMessage('.debug send chanvisualnext '..(p==1 and n or -1))p=p==1 and 0 or 1
        */
        bool HandleDebugSendNextChannelSpellVisualCommand(char* args);
        bool HandleSendSpellChannelVisualCommand(char* args);

        bool HandleEventListCommand(char* args);
        bool HandleEventStartCommand(char* args);
        bool HandleEventStopCommand(char* args);
        bool HandleEventEnableCommand(char* args);
        bool HandleEventDisableCommand(char* args);
        bool HandleEventInfoCommand(char* args);

        bool HandleGameObjectAddCommand(char* args);
        bool HandleGameObjectDeleteCommand(char* args);
        bool HandleGameObjectMoveCommand(char* args);
        bool HandleGameObjectNearCommand(char* args);
        bool HandleGameObjectTargetCommand(char* args);
        bool HandleGameObjectTurnCommand(char* args);
        bool HandleGameObjectDespawnCommand(char* args);
        bool HandleGameObjectToggleCommand(char* args);
        bool HandleGameObjectResetCommand(char* args);
        bool HandleGameObjectSelectCommand(char* args);
        bool HandleGameObjectRespawnCommand(char* args);
        bool HandleGameObjectInfoCommand(char* args);
        bool HandleGameObjectUpdateFieldsInfoCommand(char* args);
        bool HandleGameObjectUseCommand(char* args);
        bool HandleGameObjectSetGoStateCommand(char* args);
        bool HandleGameObjectSetLootStateCommand(char* args);
        bool HandleGameObjectSendCustomAnimCommand(char* args);
        bool HandleGameObjectSendSpawnAnimCommand(char* args);
        bool HandleGameObjectSendDespawnAnimCommand(char* args);
        GameObject* getSelectedGameObject();

        bool HandleGMCommand(char* args);
        bool HandleGMChatCommand(char* args);
        bool HandleGMFlyCommand(char* args);
        bool HandleGMListFullCommand(char* args);
        bool HandleGMListIngameCommand(char* args);
        bool HandleGMVisibleCommand(char* args);

        bool HandleGoCommand(char* args);
        bool HandleGoCreatureCommand(char* args);
        bool HandleGoGraveyardCommand(char* args);
        bool HandleGoGridCommand(char* args);
        bool HandleGoObjectCommand(char* args);
        bool HandleGoTargetCommand(char* args);
        bool HandleGoTaxinodeCommand(char* args);
        bool HandleGoTriggerCommand(char* args);
        bool HandleGoXYCommand(char* args);
        bool HandleGoXYZCommand(char* args);
        bool HandleGoXYZOCommand(char* args);
        bool HandleGoZoneXYCommand(char* args);

        bool HandleGuildCreateCommand(char* args);
        bool HandleGuildInviteCommand(char* args);
        bool HandleGuildUninviteCommand(char* args);
        bool HandleGuildRankCommand(char* args);
        bool HandleGuildDeleteCommand(char* args);
        bool HandleGuildRenameCommand(char* args);

        bool HandleGroupAddItemCommand(char* args);
        bool HandleGroupReviveCommand(char* args);
        bool HandleGroupReplenishCommand(char* args);
        bool HandleGroupSummonCommand(char* args);

        bool HandleHonorShow(char* args);
        bool HandleHonorAddCommand(char* args);
        bool HandleHonorAddKillCommand(char* args);
        bool HandleHonorSetRPCommand(char*args);
        bool HandleHonorResetCommand(char*args);

        bool HandleInstanceListBindsCommand(char* args);
        bool HandleInstanceUnbindCommand(char* args);
        bool HandleInstanceGroupUnbindCommand(char* args);
        void HandleInstanceUnbindHelper(Player* player, bool got_map, uint32 mapid);
        bool HandleInstanceStatsCommand(char* args);
        bool HandleInstanceSaveDataCommand(char* args);
        bool HandleInstanceSwitchCommand(char* args);
        bool HandleInstanceContinentsCommand(char* args);
        bool HandleInstanceGetDataCommand(char* args);
        bool HandleInstancePerfInfosCommand(char* args);
        bool HandleInstanceBindingMode(char* args);
        bool HandlePBCastStatsCommand(char* args);
        bool HandlePBCastSetThreadsCommand(char* args);

        bool HandleLearnCommand(char* args);
        bool HandleLearnAllCommand(char* args);
        bool HandleLearnAllGMCommand(char* args);
        bool HandleLearnAllCraftsCommand(char* args);
        bool HandleLearnAllRecipesCommand(char* args);
        bool HandleLearnAllDefaultCommand(char* args);
        bool HandleLearnAllLangCommand(char* args);
        bool HandleLearnAllMyClassCommand(char* args);
        bool HandleLearnAllMySpellsCommand(char* args);
        bool HandleLearnAllMyTalentsCommand(char* args);
        bool HandleLearnAllMyTaxisCommand(char* args);

        bool HandleListAurasCommand(char* args);
        bool HandleListCreatureCommand(char* args);
        bool HandleListItemCommand(char* args);
        bool HandleListObjectCommand(char* args);
        bool HandleListTalentsCommand(char* args);
        bool HandleListMoveGensCommand(char* args);
        bool HandleListHostileRefsCommand(char* args);
        bool HandleListThreatCommand(char* args);

        bool HandleLookupAccountEmailCommand(char* args);
        bool HandleLookupAccountIpCommand(char* args);
        bool HandleLookupAccountIponlineCommand(char* args);
        bool HandleLookupAccountNameCommand(char* args);
        bool HandleLookupAreaCommand(char* args);
        bool HandleLookupCreatureCommand(char* args);
        bool HandleLookupCreatureModelCommand(char* args);
        bool HandleLookupEventCommand(char* args);
        bool HandleLookupFactionCommand(char* args);
        bool HandleLookupItemCommand(char* args);
        bool HandleLookupItemSetCommand(char* args);
        bool HandleLookupObjectCommand(char* args);
        bool HandleLookupPlayerIpCommand(char* args);
        bool HandleLookupPlayerAccountCommand(char* args);
        bool HandleLookupPlayerEmailCommand(char* args);
        bool HandleLookupPlayerNameCommand(char* args);
        bool HandleLookupPlayerCharacterCommand(char* args);
        bool HandleLookupPoolCommand(char* args);
        bool HandleLookupQuestCommand(char* args);
        bool HandleLookupSkillCommand(char* args);
        bool HandleLookupSpellCommand(char* args);
        bool HandleLookupSoundCommand(char* args);
        bool HandleLookupTaxiNodeCommand(char* args);
        bool HandleLookupTeleCommand(char* args);
        bool HandleLookupGuildCommand(char* args);

        bool HandleModifyHPCommand(char* args);
        bool HandleModifyManaCommand(char* args);
        bool HandleModifyRageCommand(char* args);
        bool HandleModifyEnergyCommand(char* args);
        bool HandleModifyMoneyCommand(char* args);
        bool HandleModifyASpeedCommand(char* args);
        bool HandleModifySpeedCommand(char* args);
        bool HandleModifyBWalkCommand(char* args);
        bool HandleModifyFlyCommand(char* args);
        bool HandleModifySwimCommand(char* args);
        bool HandleModifyScaleCommand(char* args);
        bool HandleModifyMountCommand(char* args);
        bool HandleModifyFactionCommand(char* args);
        bool HandleModifyTalentCommand(char* args);
        bool HandleModifyHonorCommand(char* args);
        bool HandleModifyRepCommand(char* args);
        bool HandleModifyGenderCommand(char* args);
        bool HandleModifyStrengthCommand(char* args);
        bool HandleModifyAgilityCommand(char* args);
        bool HandleModifyStaminaCommand(char* args);
        bool HandleModifyIntellectCommand(char* args);
        bool HandleModifySpiritCommand(char* args);
        bool HandleModifyArmorCommand(char* args);
        bool HandleModifyHolyCommand(char* args);
        bool HandleModifyFireCommand(char* args);
        bool HandleModifyNatureCommand(char* args);
        bool HandleModifyFrostCommand(char* args);
        bool HandleModifyShadowCommand(char* args);
        bool HandleModifyArcaneCommand(char* args);
        bool HandleModifyMeleeApCommand(char* args);
        bool HandleModifyRangedApCommand(char* args);
        bool HandleModifySpellPowerCommand(char* args);
        bool HandleModifyMeleeCritCommand(char* args);
        bool HandleModifyRangedCritCommand(char* args);
        bool HandleModifySpellCritCommand(char* args);
        bool HandleModifyMainSpeedCommand(char* args);
        bool HandleModifyOffSpeedCommand(char* args);
        bool HandleModifyRangedSpeedCommand(char* args);
        bool HandleModifyCastSpeedCommand(char* args);
        bool HandleModifyBlockCommand(char* args);
        bool HandleModifyDodgeCommand(char* args);
        bool HandleModifyParryCommand(char* args);

        bool HandleModifyCrCommand(char *args);
        bool HandleModifyBrCommand(char *args);

        bool HandleModifyHairStyleCommand(char *args);
        bool HandleModifyHairColorCommand(char *args);
        bool HandleModifySkinColorCommand(char *args);
        bool HandleModifyAccessoriesCommand(char *args);

        //-----------------------Npc Commands-----------------------
        bool HandleNpcAddCommand(char* args);
        bool HandleNpcAddEntryCommand(char* args);
        bool HandleNpcAddWeaponCommand(char* args);
        bool HandleNpcSummonCommand(char* args);
        bool HandleNpcAddVendorItemCommand(char* args);
        bool HandleNpcAIInfoCommand(char* args);
        bool HandleNpcAllowMovementCommand(char* args);
        bool HandleNpcAllowAttackCommand(char* args);
        bool HandleNpcSetEntryCommand(char* args);
        bool HandleNpcSpawnSetEntryCommand(char* args);
        bool HandleNpcSetLevelCommand(char* args);
        bool HandleNpcDespawnCommand(char* args);
        bool HandleNpcDeleteCommand(char* args);
        bool HandleNpcDelVendorItemCommand(char* args);
        bool HandleNpcEvadeCommand(char* args);
        bool HandleNpcSetFactionIdCommand(char* args);
        bool HandleNpcSetFlagCommand(char* args);
        bool HandleNpcFollowCommand(char* args);
        bool HandleNpcInfoCommand(char* args);
        bool HandleNpcSpawnInfoCommand(char* args);
        bool HandleNpcMoveCommand(char* args);
        bool HandleNpcSpawnMoveCommand(char* args);
        bool HandleNpcMoveHelperCommand(char* args, bool save);
        bool HandleNpcPlayEmoteCommand(char* args);
        bool HandleNpcSayCommand(char* args);
        bool HandleNpcSetDeathStateCommand(char* args);
        bool HandleNpcSetDisplayIdCommand(char* args);
        bool HandleNpcSpawnSetDisplayIdCommand(char* args);
        bool HandleNpcSetMoveTypeCommand(char* args);
        bool HandleNpcSpawnSetMoveTypeCommand(char* args);
        bool HandleNpcSpawnWanderDistCommand(char* args);
        bool HandleNpcSetWanderDistCommand(char* args);
        bool HandleNpcSetSpawnTimeCommand(char* args);
        bool HandleNpcSpawnSpawnTimeCommand(char* args);
        bool HandleNpcTameCommand(char* args);
        bool HandleNpcTextEmoteCommand(char* args);
        bool HandleNpcUnFollowCommand(char* args);
        bool HandleNpcWhisperCommand(char* args);
        bool HandleNpcYellCommand(char* args);
        //----------------------------------------------------------

        bool HandleUnitAIInfoCommand(char* args);
        bool HandleUnitInfoCommand(char* args);
        bool HandleUnitSpeedInfoCommand(char* args);
        bool HandleUnitStatInfoCommand(char* args);
        bool HandleUnitUpdateFieldsInfoCommand(char* args);

        bool HandlePDumpLoadCommand(char* args);
        bool HandlePDumpWriteCommand(char* args);

        bool HandlePoolListCommand(char* args);
        bool HandlePoolSpawnsCommand(char* args);
        bool HandlePoolUpdateCommand(char* args);
        bool HandlePoolInfoCommand(char* args);

        bool HandleQuestAddCommand(char* args);
        bool HandleQuestRemoveCommand(char* args);
        bool HandleQuestCompleteCommand(char* args);
        bool HandleQuestStatusCommand(char* args);

        bool HandlePetListCommand(char* args);
        bool HandlePetRenameCommand(char* args);
        bool HandlePetDeleteCommand(char* args);
        bool HandlePetLoyaltyCommand(char* args);
        bool HandlePetInfoCommand(char* args);

        bool HandleReloadAllCommand(char* args);
        bool HandleReloadAllAreaCommand(char* args);
        bool HandleReloadAllGossipsCommand(char* args);
        bool HandleReloadAllItemCommand(char* args);
        bool HandleReloadAllLootCommand(char* args);
        bool HandleReloadAllNpcCommand(char* args);
        bool HandleReloadAllQuestCommand(char* args);
        bool HandleReloadAllScriptsCommand(char* args);
        bool HandleReloadAllSpellCommand(char* args);
        bool HandleReloadAllLocalesCommand(char* args);

        bool HandleReloadConfigCommand(char* args);

        bool HandleReloadAreaTriggerTavernCommand(char* args);
        bool HandleReloadAreaTriggerTeleportCommand(char* args);
        bool HandleReloadEventScriptsCommand(char* args);
        bool HandleReloadGenericScriptsCommand(char* args);
        bool HandleReloadEventAIEventsCommand(char* args);
        bool HandleReloadCommandCommand(char* args);
        bool HandleReloadBattleEventCommand(char* args);
        bool HandleReloadConditionsCommand(char* args);
        bool HandleReloadCreatureSpellsCommand(char* args);
        bool HandleReloadCreatureSpellScriptsCommand(char* args);
        bool HandleReloadCreatureQuestRelationsCommand(char* args);
        bool HandleReloadCreatureQuestInvRelationsCommand(char* args);
        bool HandleReloadGameGraveyardZoneCommand(char* args);
        bool HandleReloadGameObjectScriptsCommand(char* args);
        bool HandleReloadGameTeleCommand(char* args);
        bool HandleReloadTaxiPathTransitionsCommand(char* args);
        bool HandleReloadGossipMenuCommand(char* args);
        bool HandleReloadGossipMenuOptionCommand(char* args);
        bool HandleReloadGossipScriptsCommand(char* args);
        bool HandleReloadGOQuestRelationsCommand(char* args);
        bool HandleReloadGORequirementsCommand(char* args);
        bool HandleReloadGOQuestInvRelationsCommand(char* args);
        bool HandleReloadItemEnchantementsCommand(char* args);
        bool HandleReloadItemRequiredTragetCommand(char* args);
        bool HandleReloadLocalesCreatureCommand(char* args);
        bool HandleReloadLocalesGameobjectCommand(char* args);
        bool HandleReloadLocalesGossipMenuOptionCommand(char* args);
        bool HandleReloadLocalesItemCommand(char* args);
        bool HandleReloadLocalesPageTextCommand(char* args);
        bool HandleReloadLocalesPointsOfInterestCommand(char* args);
        bool HandleReloadLocalesQuestCommand(char* args);
        bool HandleReloadLootTemplatesCreatureCommand(char* args);
        bool HandleReloadLootTemplatesDisenchantCommand(char* args);
        bool HandleReloadLootTemplatesFishingCommand(char* args);
        bool HandleReloadLootTemplatesGameobjectCommand(char* args);
        bool HandleReloadLootTemplatesItemCommand(char* args);
        bool HandleReloadLootTemplatesMailCommand(char* args);
        bool HandleReloadLootTemplatesPickpocketingCommand(char* args);
        bool HandleReloadLootTemplatesReferenceCommand(char* args);
        bool HandleReloadLootTemplatesSkinningCommand(char* args);
        bool HandleReloadMangosStringCommand(char* args);
        bool HandleReloadNpcGossipCommand(char* args);
        bool HandleReloadNpcTextCommand(char* args);
        bool HandleReloadNpcTrainerCommand(char* args);
        bool HandleReloadNpcVendorCommand(char* args);
        bool HandleReloadPageTextsCommand(char* args);
        bool HandleReloadPointsOfInterestCommand(char* args);
        bool HandleReloadQuestAreaTriggersCommand(char* args);
        bool HandleReloadQuestEndScriptsCommand(char* args);
        bool HandleReloadQuestStartScriptsCommand(char* args);
        bool HandleReloadQuestTemplateCommand(char* args);
        bool HandleReloadQuestGreetingCommand(char* args);
        bool HandleReloadTrainerGreetingCommand(char* args);
        bool HandleReloadReservedNameCommand(char* args);
        bool HandleReloadReputationRewardRateCommand(char* args);
        bool HandleReloadReputationSpilloverTemplateCommand(char* args);
        bool HandleReloadSkillFishingBaseLevelCommand(char* args);
        bool HandleReloadSpellAffectCommand(char* args);
        bool HandleReloadSpellAreaCommand(char* args);
        bool HandleReloadSpellChainCommand(char* args);
        bool HandleReloadSpellElixirCommand(char* args);
        bool HandleReloadSpellLearnSpellCommand(char* args);
        bool HandleReloadSpellProcEventCommand(char* args);
        bool HandleReloadSpellProcItemEnchantCommand(char* args);
        bool HandleReloadSpellScriptTargetCommand(char* args);
        bool HandleReloadSpellScriptsCommand(char* args);
        bool HandleReloadSpellTargetPositionCommand(char* args);
        bool HandleReloadSpellThreatsCommand(char* args);
        bool HandleReloadSpellPetAurasCommand(char* args);

        bool HandleResetAchievementsCommand(char* args);
        bool HandleResetAllCommand(char* args);
        bool HandleResetHonorCommand(char* args);
        bool HandleResetLevelCommand(char* args);
        bool HandleResetSpellsCommand(char* args);
        bool HandleResetStatsCommand(char* args);
        bool HandleResetTalentsCommand(char* args);
        bool HandleResetItemsCommand(char* args);

        bool HandleSendItemsCommand(char* args);
        bool HandleSendMailCommand(char* args);
        bool HandleSendMessageCommand(char* args);
        bool HandleSendMoneyCommand(char* args);

        bool HandleSendMassItemsCommand(char* args);
        bool HandleSendMassMailCommand(char* args);
        bool HandleSendMassMoneyCommand(char* args);

        bool HandleServerCorpsesCommand(char* args);
        bool HandleServerExitCommand(char* args);
        bool HandleServerIdleRestartCommand(char* args);
        bool HandleServerIdleShutDownCommand(char* args);
        bool HandleServerInfoCommand(char* args);
        bool HandleServerLogFilterCommand(char* args);
        bool HandleServerLogLevelCommand(char* args);
        bool HandleServerMotdCommand(char* args);
        bool HandleServerPLimitCommand(char* args);
        bool HandleServerResetAllRaidCommand(char* args);
        bool HandleServerRestartCommand(char* args);
        bool HandleServerSetMotdCommand(char* args);
        bool HandleServerShutDownCommand(char* args);
        bool HandleServerShutDownCancelCommand(char* args);

        bool HandleTeleCommand(char* args);
        bool HandleTeleAddCommand(char* args);
        bool HandleTeleDelCommand(char* args);
        bool HandleTeleGroupCommand(char* args);
        bool HandleTeleNameCommand(char* args);

        bool HandleTriggerActiveCommand(char* args);
        bool HandleTriggerNearCommand(char* args);
        bool HandleTriggerCommand(char* args);

        bool HandleUnBanAccountCommand(char* args);
        bool HandleUnBanCharacterCommand(char* args);
        bool HandleUnBanIPCommand(char* args);

        bool HandleWpAddCommand(char* args);
        bool HandleWpModifyCommand(char* args);
        bool HandleWpShowCommand(char* args);
        bool HandleWpExportCommand(char* args);

        bool HandleHelpCommand(char* args);
        bool HandleCommandsCommand(char* args);
        bool HandleStartCommand(char* args);
        bool HandleMountCommand(char* args);
        bool HandleDismountCommand(char* args);
        bool HandleSaveCommand(char* args);

        bool HandleNamegoCommand(char* args);
        bool HandleGonameCommand(char* args);
        bool HandleGroupgoCommand(char* args);
        bool HandleGocorpseCommand(char* args);
        bool HandleRecallCommand(char* args);
        bool HandleAnnounceCommand(char* args);
        bool HandleNotifyCommand(char* args);
        bool HandleGPSCommand(char* args);
        bool HandleTaxiCheatCommand(char* args);
        bool HandleWhispersCommand(char* args);
        bool HandleModifyDrunkCommand(char* args);
        bool HandleModifyExhaustionCommand(char* args);
        bool HandleSetViewCommand(char* args);

        bool HandleGUIDCommand(char* args);
        bool HandleItemMoveCommand(char* args);
        bool HandleDeMorphCommand(char* args);
        bool HandleGroupInfoCommand(char* args);
        bool HandlePInfoCommand(char* args);
        bool HandleMuteCommand(char* args);
        bool HandleUnmuteCommand(char* args);
        bool HandleMovegensCommand(char* args);

        bool HandleCooldownListCommand(char* args);
        bool HandleCooldownClearCommand(char* args);
        bool HandleCooldownClearClientSideCommand(char* args);
        bool HandleUnLearnCommand(char* args);
        bool HandleUnLearnAllGMCommand(char* args);
        bool HandleUnLearnAllCraftsCommand(char* args);
        bool HandleUnLearnAllRecipesCommand(char* args);
        bool HandleRemoveRidingCommand(char* args);
        bool HandleGetDistanceCommand(char* args);
        bool HandleGetAngleCommand(char* args);
        bool HandleModifyEmoteStateCommand(char* args);
        bool HandleNameDieCommand(char* args);
        bool HandleDieCommand(char* args);
        bool HandleKnockBackCommand(char* args);
        bool HandleFearCommand(char* args);
        bool HandleDamageCommand(char* args);
        bool HandleAoEDamageCommand(char* args);
        bool HandleReviveCommand(char* args);
        bool HandleReplenishCommand(char* args);
        bool HandleModifyMorphCommand(char* args);
        bool HandleNameAuraCommand(char* args);
        bool HandleAuraCommand(char* args);
        bool HandleUnAuraCommand(char* args);
        bool HandleLinkGraveCommand(char* args);
        bool HandleNearGraveCommand(char* args);
        bool HandleExploreCheatCommand(char* args);
        bool HandleHoverCommand(char* args);
        bool HandleModifyXpRateCommand(char* args);
        bool HandleLevelUpCommand(char* args);
        bool HandleShowAreaCommand(char* args);
        bool HandleHideAreaCommand(char* args);
        bool HandleAddItemCommand(char* args);
        bool HandleDeleteItemCommand(char* args);
        bool HandleAddItemSetCommand(char* args);

        bool HandleBankCommand(char* args);
        bool HandleChangeWeatherCommand(char* args);
        bool HandleKickPlayerCommand(char* args);

        // GM Tickets commands
        bool ViewTicketByIdOrName(char* ticketId, char* name);
        bool ViewTicket(GmTicket* ticket);
        bool HandleGMTicketResponseResetCommand(char* args);
        bool HandleGMTicketResponseAppendCommand(char* args);
        bool HandleGMTicketResponseAppendLnCommand(char* args);
        bool HandleGMTicketAssignToCommand(char* args);
        bool HandleGMTicketCloseByIdCommand(char* args);
        bool HandleGMTicketListClosedCommand(char* args);
        bool HandleGMTicketCounterCommand(char* args);
        bool HandleGMTicketCommentCommand(char* args);
        bool HandleGMTicketCompleteCommand(char* args);
        bool HandleGMTicketDeleteByIdCommand(char* args);
        bool HandleGMTicketEscalateCommand(char* args);
        bool HandleGMTicketListEscalatedCommand(char* args);
        bool HandleGMTicketNextCommand(char* args);
        bool HandleGMTicketNotifyCommand(char* args);
        bool HandleGMTicketListCommand(char* args);
        bool HandleGMTicketListOnlineCommand(char* args);
        bool HandleGMTicketReloadCommand(char* args);
        bool HandleGMTicketPreviousCommand(char* args);
        bool HandleGMTicketResetCommand(char* args);
        bool HandleToggleGMTicketSystem(char* args);
        bool HandleGMTicketUnAssignCommand(char* args);
        bool HandleGMTicketGetByIdOrNameCommand(char* args);
        bool HandleGMTicketGetByIdCommand(char* args);
        bool HandleGMTicketGetByNameCommand(char* args);

        bool HandleMaxSkillCommand(char* args);
        bool HandleSetSkillCommand(char* args);
        bool HandleRespawnCommand(char* args);
        bool HandleComeToMeCommand(char* args);
        bool HandleCombatStopCommand(char* args);
        bool HandleRepairitemsCommand(char* args);
        bool HandleStableCommand(char* args);
        bool HandleQuitCommand(char* args);

        //! Development Commands
        bool HandleSaveAllCommand(char* args);
        bool HandleDebugMoveCommand(char* args);

        Player*   GetSelectedPlayer() const;
        Creature* GetSelectedCreature() const;
        Unit*     GetSelectedUnit() const;
        Pet*      GetSelectedPet() const;

        // extraction different type params from args string, all functions update (char** args) to first unparsed tail symbol at return
        void  SkipWhiteSpaces(char** args);
        bool  ExtractInt32(char** args, int32& val);
        bool  ExtractOptInt32(char** args, int32& val, int32 defVal);
        bool  ExtractUInt32Base(char** args, uint32& val, uint32 base);
        bool  ExtractUInt32(char** args, uint32& val) { return ExtractUInt32Base(args,val, 10); }
        bool  ExtractOptUInt32(char** args, uint32& val, uint32 defVal);
        bool  ExtractFloat(char** args, float& val);
        bool  ExtractOptFloat(char** args, float& val, float defVal);
        char* ExtractQuotedArg(char** args, bool asis = false);
                                                            // string with " or [] or ' around
        char* ExtractLiteralArg(char** args, char const* lit = nullptr);
                                                            // literal string (until whitespace and not started from "['|), any or 'lit' if provided
        char* ExtractQuotedOrLiteralArg(char** args, bool asis = false);
        bool  ExtractOnOff(char** args, bool& value);
        char* ExtractLinkArg(char** args, char const* const* linkTypes = nullptr, int* foundIdx = nullptr, char** keyPair = nullptr, char** somethingPair = nullptr);
                                                            // shift-link like arg (with aditional info if need)
        char* ExtractArg(char** args, bool asis = false);   // any name/number/quote/shift-link strings
        char* ExtractOptNotLastArg(char** args);            // extract name/number/quote/shift-link arg only if more data in args for parse

        char* ExtractKeyFromLink(char** text, char const* linkType, char** something1 = nullptr);
        char* ExtractKeyFromLink(char** text, char const* const* linkTypes, int* found_idx = nullptr, char** something1 = nullptr);
        bool  ExtractUint32KeyFromLink(char** text, char const* linkType, uint32& value);

        char* extractKeyFromLink(char* text, char const* linkType, char** something1 = nullptr);
        char* extractKeyFromLink(char* text, char const* const* linkTypes, int* found_idx, char** something1 = nullptr);
        char* extractQuotedArg(char* args);
        uint32 extractSpellIdFromLink(char* text);
        ObjectGuid::LowType extractLowGuidFromLink(char* text, HighGuid& guidHigh);
        bool GetPlayerGroupAndGUIDByName(const char* cname, Player*& player, Group*& group, ObjectGuid& guid, bool offline = false);
        std::string extractPlayerNameFromLink(char* text);
        // select by arg (name/link) or in-game selection online/offline player or self if a creature is selected
        bool extractPlayerTarget(char* args, Player** player, ObjectGuid* player_guid = nullptr, std::string* player_name = nullptr);
        uint32 ExtractAccountId(char** args, std::string* accountName = nullptr, Player** targetIfNullArg = nullptr);
        uint32 ExtractSpellIdFromLink(char** text);
        ObjectGuid ExtractGuidFromLink(char** text);
        GameTele const* ExtractGameTeleFromLink(char** text);
        bool   ExtractLocationFromLink(char** text, uint32& mapid, float& x, float& y, float& z);
        bool   ExtractRaceMask(char** text, uint32& raceMask, char const** maskName = nullptr);
        std::string ExtractPlayerNameFromLink(char** text);
        bool ExtractPlayerTarget(char** args, Player** player, ObjectGuid* player_guid = nullptr, std::string* player_name = nullptr, bool use_extended_response = false);
                                                            // select by arg (name/link) or in-game selection online/offline player

        // Utility methods for commands
        bool ShowAccountIpListHelper(char* args, bool onlineonly);
        void ShowFactionListHelper(FactionEntry const* factionEntry, LocaleConstant loc, FactionState const* repState = nullptr, Player* target = nullptr);
        void ShowItemListHelper(uint32 itemId, int loc_idx, Player* target = nullptr);
        void ShowQuestListHelper(uint32 questId, int32 loc_idx, Player* target = nullptr);
        void ShowSpellListHelper(Player* target, SpellEntry const* spellInfo, LocaleConstant loc);
        void ShowPoolListHelper(uint16 pool_id);
        void ShowTriggerListHelper(AreaTriggerEntry const* atEntry);
        void ShowTriggerTargetListHelper(uint32 id, AreaTriggerTeleport const* at, bool subpart = false);
        void ShowAllUpdateFieldsHelper(Object const* pTarget);
        void ShowUpdateFieldHelper(Object const* pTarget, uint16 index);
        SkillLineEntry const* FindSkillLineEntryFromProfessionName(char* args, std::string& nameOut);
        bool LookupPlayerSearchCommand(QueryResult* result, uint32* limit = nullptr);
        bool HandleBanListHelper(QueryResult* result);
        bool HandleBanHelper(BanMode mode, char* args);
        bool HandleBanInfoHelper(uint32 accountid, char const* accountname);
        bool HandleUnBanHelper(BanMode mode, char* args);
        bool HandlePartyBotPauseHelper(char* args, bool pause);
        void HandleCharacterLevel(Player* player, ObjectGuid player_guid, uint32 oldlevel, uint32 newlevel);
        void HandleLearnSkillRecipesHelper(Player* player, uint32 skill_id);
        void HandleUnLearnSkillRecipesHelper(Player* player,uint32 skill_id);
        bool HandleGoHelper(Player* _player, uint32 mapid, float x, float y, float const* zPtr = nullptr, float const* ortPtr = nullptr);
        bool HandleGetValueHelper(Object* target, uint32 field, char* typeStr);
        bool HandlerDebugModValueHelper(Object* target, uint32 field, char* typeStr, char* valStr);
        bool HandleSetValueHelper(Object* target, uint32 field, char* typeStr, char* valStr);

        bool HandleSendItemsHelper(MailDraft& draft, char* args);
        bool HandleSendMailHelper(MailDraft& draft, char* args);
        bool HandleSendMoneyHelper(MailDraft& draft, char* args);

        std::string playerLink(std::string const& name) const;
        std::string GetNameLink(Player* chr) const;
        bool HandleAuraHelper(uint32 spellId, int32 duration, Unit*);
        bool HandleDieHelper(Unit* target);

        GameObject* GetNearbyGameObject();
        GameObject* GetObjectFromPlayerMapByDbGuid(ObjectGuid::LowType lowguid);
        Creature* GetCreatureFromPlayerMapByDbGuid(ObjectGuid::LowType lowguid);
        bool HasSentErrorMessage() const { return sentErrorMessage; }
        void SetSentErrorMessage(bool val){ sentErrorMessage = val; }
    protected:
        explicit ChatHandler() : m_session(nullptr), sentErrorMessage(false) { }     // for CLI subclass
        template<typename T>
        void ShowNpcOrGoSpawnInformation(uint32 guid);
        template <typename T>
        std::string PrepareStringNpcOrGoSpawnInformation(uint32 guid);

        /**
         * Stores informations about a deleted character
         */
        struct DeletedInfo
        {
            uint32      lowguid;                            ///< the low GUID from the character
            std::string name;                               ///< the character name
            uint32      accountId;                          ///< the account id
            std::string accountName;                        ///< the account name
            time_t      deleteDate;                         ///< the date at which the character has been deleted
        };

        typedef std::list<DeletedInfo> DeletedInfoList;
        bool GetDeletedCharacterInfoList(DeletedInfoList& foundList, bool useName, std::string searchString = "");
        std::string GenerateDeletedCharacterGUIDsWhereStr(DeletedInfoList::const_iterator& itr, DeletedInfoList::const_iterator const& itr_end);
        void HandleCharacterDeletedListHelper(DeletedInfoList const& foundList);
        void HandleCharacterDeletedRestoreHelper(DeletedInfo const& delInfo);

        void SetSentErrorMessage(bool val){ sentErrorMessage = val;};
    private:
        WorldSession* m_session;                           // != nullptr for chat command call and nullptr for CLI command

        // common global flag
        static bool load_command_table;
        bool sentErrorMessage;
};

class CliHandler : public ChatHandler
{
    public:
        using Print = void(void*, std::string_view);
        explicit CliHandler(void* callbackArg, Print* zprint) : m_callbackArg(callbackArg), m_print(zprint) { }
        typedef void Print(void*, char const*);
        explicit CliHandler(uint32 accountId, AccountTypes accessLevel, void* callbackArg, Print* zprint)
            : m_accountId(accountId), m_loginAccessLevel(accessLevel), m_callbackArg(callbackArg), m_print(zprint) {}

        // overwrite functions
        char const* GetTrinityString(uint32 entry) const override;
        bool HasPermission(uint32 /*permission*/) const override { return true; }
        void SendSysMessage(std::string_view, bool escapeCharacters) override;
        bool ParseCommands(std::string_view str) override;
        char const* GetMangosString(int32 entry) const override;
        uint32 GetAccountId() const override;
        AccountTypes GetAccessLevel() const override;
        bool isAvailable(ChatCommand const& cmd) const override;
        void SendSysMessage(char const* str) override;
        std::string GetNameLink() const override;
        bool needReportToTarget(Player* chr) const override;
        LocaleConstant GetSessionDbcLocale() const override;
        int GetSessionDbLocaleIndex() const override;

    private:
        uint32 m_accountId;
        AccountTypes m_loginAccessLevel;
        void* m_callbackArg;
        Print* m_print;
};

class NullChatHandler : public ChatHandler
{
    public:
        static std::string const PREFIX;

        using ChatHandler::ChatHandler;
        bool ParseCommands(std::string_view str) override;
        void SendSysMessage(std::string_view, bool escapeCharacters) override;
        using ChatHandler::SendSysMessage;
        bool IsHumanReadable() const override { return humanReadable; }

    private:
        void Send(std::string const& msg);
        void SendAck();
        void SendOK();
        void SendFailed();
        explicit NullChatHandler() {}

        // overwrite functions
        char const* GetMangosString(int32 entry) const override;
        uint32 GetAccountId() const override { return 0; }
        AccountTypes GetAccessLevel() const override { return SEC_PLAYER; }
        bool isAvailable(ChatCommand const& cmd) const override { return false; }
        void SendSysMessage(char const* str) override {}
        std::string GetNameLink() const override { return ""; }
        LocaleConstant GetSessionDbcLocale() const override;
        int GetSessionDbLocaleIndex() const override;
};


#endif
