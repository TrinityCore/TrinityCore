/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITYCORE_CHAT_H
#define TRINITYCORE_CHAT_H

#include "SharedDefines.h"
#include "Player.h"

#include <vector>

class ChatHandler;
class WorldSession;
class WorldObject;
class Creature;
class Player;
class Unit;
struct GameTele;

class ChatCommand
{
    public:
        const char *       Name;
        uint32             SecurityLevel;                   // function pointer required correct align (use uint32)
        bool               AllowConsole;
        bool (*Handler)(ChatHandler*, char* args);
        std::string        Help;
        ChatCommand *      ChildCommands;
};

class ChatHandler
{
    public:
        WorldSession * GetSession() { return m_session; }
        explicit ChatHandler(WorldSession* session) : m_session(session) {}
        explicit ChatHandler(Player* player) : m_session(player->GetSession()) {}
         ~ChatHandler() {}

        static void FillMessageData(WorldPacket *data, WorldSession* session, uint8 type, uint32 language, const char *channelName, uint64 target_guid, const char *message, Unit *speaker);

        void FillMessageData(WorldPacket *data, uint8 type, uint32 language, uint64 target_guid, const char* message)
        {
            FillMessageData(data, m_session, type, language, NULL, target_guid, message, NULL);
        }

        void FillSystemMessageData(WorldPacket *data, const char* message)
        {
            FillMessageData(data, CHAT_MSG_SYSTEM, LANG_UNIVERSAL, 0, message);
        }

        static char* LineFromMessage(char*& pos) { char* start = strtok(pos,"\n"); pos = NULL; return start; }

        // function with different implementation for chat/console
        virtual const char *GetTrinityString(int32 entry) const;
        virtual void SendSysMessage(const char *str);

        void SendSysMessage(int32     entry);
        void PSendSysMessage(const char *format, ...) ATTR_PRINTF(2,3);
        void PSendSysMessage(int32     entry, ...);
        std::string PGetParseString(int32 entry, ...);

        int ParseCommands(const char* text);

        static ChatCommand* getCommandTable();

        bool isValidChatMessage(const char* msg);
        void SendGlobalSysMessage(const char *str);

        bool hasStringAbbr(const char* name, const char* part);

        // function with different implementation for chat/console
        virtual bool isAvailable(ChatCommand const& cmd) const;
        virtual std::string GetNameLink() const { return GetNameLink(m_session->GetPlayer()); }
        virtual bool needReportToTarget(Player* chr) const;
        virtual LocaleConstant GetSessionDbcLocale() const;
        virtual int GetSessionDbLocaleIndex() const;

        bool HasLowerSecurity(Player* target, uint64 guid, bool strong = false);
        bool HasLowerSecurityAccount(WorldSession* target, uint32 account, bool strong = false);

        void SendGlobalGMSysMessage(const char *str);
        Player*   getSelectedPlayer();
        Creature* getSelectedCreature();
        Unit*     getSelectedUnit();
        WorldObject* getSelectedObject();

        // extraction different type params from args string, all functions update (char** args) to first unparsed tail symbol at return
        void  SkipWhiteSpaces(char** args);
        bool  ExtractInt32(char** args, int32& val);
        bool  ExtractOptInt32(char** args, int32& val, int32 defVal);
        bool  ExtractUInt32Base(char** args, uint32& val, uint32 base);
        bool  ExtractUInt32(char** args, uint32& val) { return ExtractUInt32Base(args,val, 10); }
        bool  ExtractOptUInt32(char** args, uint32& val, uint32 defVal);
        bool  ExtractFloat(char** args, float& val);
        bool  ExtractOptFloat(char** args, float& val, float defVal);
        char* ExtractQuotedArg(char** args);                // string with " or [] or ' around
        char* ExtractLinkArg(char** args);                  // shift-link like arg
        char* ExtractLiteralArg(char** args, char const* lit = NULL);
                                                            // literal string (until whitespace and not started from "['|), any or 'lit' if provided
        char* ExtractQuotedOrLiteralArg(char** args);
        bool  ExtractOnOff(char** args, bool& value);
        char* ExtractArg(char** args);                      // any name/number/quote/shift-link strings
        char* ExtractOptNotLastArg(char** args);            // extract name/number/quote/shift-link arg only if more data in args for parse

        char*     extractKeyFromLink(char* text, char const* linkType, char** something1 = NULL);
        char*     extractKeyFromLink(char* text, char const* const* linkTypes, int* found_idx, char** something1 = NULL);

        uint32    extractSpellIdFromLink(char* text);
        uint64    extractGuidFromLink(char* text);
        GameTele const* extractGameTeleFromLink(char* text);
        bool GetPlayerGroupAndGUIDByName(const char* cname, Player* &plr, Group* &group, uint64 &guid, bool offline = false);
        std::string extractPlayerNameFromLink(char* text);
        // select by arg (name/link) or in-game selection online/offline player
        bool extractPlayerTarget(char* args, Player** player, uint64* player_guid = NULL, std::string* player_name = NULL);

        std::string playerLink(std::string const& name) const { return m_session ? "|cffffffff|Hplayer:"+name+"|h["+name+"]|h|r" : name; }
        std::string GetNameLink(Player* chr) const { return playerLink(chr->GetName()); }

        GameObject* GetNearbyGameObject();
        GameObject* GetObjectGlobalyWithGuidOrNearWithDbGuid(uint32 lowguid,uint32 entry);
        bool HasSentErrorMessage() { return sentErrorMessage;}
        void SetSentErrorMessage(bool val){ sentErrorMessage = val;};
        static bool LoadCommandTable() { return load_command_table;}
        static void SetLoadCommandTable(bool val){ load_command_table = val;};
        bool HandleBanHelper(BanMode mode,char* args);

    protected:
        explicit ChatHandler() : m_session(NULL) {}      // for CLI subclass
        static bool SetDataForCommandInTable(ChatCommand *table, const char* text, uint32 security, std::string const& help, std::string const& fullcommand);
        bool ExecuteCommandInTable(ChatCommand *table, const char* text, const std::string& fullcmd);
        bool ShowHelpForCommand(ChatCommand *table, const char* cmd);
        bool ShowHelpForSubCommands(ChatCommand *table, char const* cmd, char const* subcmd);

        bool HandleNameAnnounceCommand(char* args);
        bool HandleGMNameAnnounceCommand(char* args);
        bool HandleGMAnnounceCommand(char* args);
        bool HandleGMNotifyCommand(char* args);

        bool HandleBanAccountCommand(char* args);
        bool HandleBanAccountByCharCommand(char* args);
        bool HandleBanCharacterCommand(char* args);
        bool HandleBanIPCommand(char* args);
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

        bool HandleCharacterCustomizeCommand(char* args);
        bool HandleCharacterChangeFactionCommand(char* args);
        bool HandleCharacterChangeRaceCommand(char* args);
        bool HandleCharacterDeletedDeleteCommand(char* args);
        bool HandleCharacterDeletedListCommand(char* args);
        bool HandleCharacterDeletedRestoreCommand(char* args);
        bool HandleCharacterDeletedOldCommand(char* args);
        bool HandleCharacterEraseCommand(char* args);
        bool HandleCharacterLevelCommand(char* args);
        bool HandleCharacterRenameCommand(char* args);
        bool HandleCharacterReputationCommand(char* args);
        bool HandleCharacterTitlesCommand(char* args);

        bool HandleChannelSetOwnership(char* args);

        bool HandlePossessCommand(char* args);
        bool HandleUnPossessCommand(char* args);
        bool HandleBindSightCommand(char* args);
        bool HandleUnbindSightCommand(char* args);

        bool HandleGuildCreateCommand(char* args);
        bool HandleGuildInviteCommand(char* args);
        bool HandleGuildUninviteCommand(char* args);
        bool HandleGuildRankCommand(char* args);
        bool HandleGuildDeleteCommand(char* args);

        bool HandleInstanceListBindsCommand(char* args);
        bool HandleInstanceUnbindCommand(char* args);
        bool HandleInstanceStatsCommand(char* args);
        bool HandleInstanceSaveDataCommand(char* args);

        bool HandleListAurasCommand(char* args);
        bool HandleListCreatureCommand(char* args);
        bool HandleListItemCommand(char* args);
        bool HandleListObjectCommand(char* args);

        bool HandleLookupAreaCommand(char* args);
        bool HandleLookupCreatureCommand(char* args);
        bool HandleLookupEventCommand(char* args);
        bool HandleLookupFactionCommand(char* args);
        bool HandleLookupItemCommand(char* args);
        bool HandleLookupItemSetCommand(char* args);
        bool HandleLookupObjectCommand(char* args);
        bool HandleLookupPlayerIpCommand(char* args);
        bool HandleLookupPlayerAccountCommand(char* args);
        bool HandleLookupPlayerEmailCommand(char* args);
        bool HandleLookupQuestCommand(char* args);
        bool HandleLookupSkillCommand(char* args);
        bool HandleLookupSpellCommand(char* args);
        bool HandleLookupTaxiNodeCommand(char* args);
        bool HandleLookupTeleCommand(char* args);
        bool HandleLookupMapCommand(char* args);
        bool HandleLookupTitleCommand(char* args);

        bool HandlePDumpLoadCommand(char* args);
        bool HandlePDumpWriteCommand(char* args);

        bool HandleResetAchievementsCommand(char* args);
        bool HandleResetAllCommand(char* args);
        bool HandleResetHonorCommand(char* args);
        bool HandleResetLevelCommand(char* args);
        bool HandleResetSpellsCommand(char* args);
        bool HandleResetStatsCommand(char* args);
        bool HandleResetTalentsCommand(char* args);

        bool HandleSendItemsCommand(char* args);
        bool HandleSendMailCommand(char* args);
        bool HandleSendMessageCommand(char* args);
        bool HandleSendMoneyCommand(char* args);

        bool HandleServerCorpsesCommand(char* args);
        bool HandleServerExitCommand(char* args);
        bool HandleServerIdleRestartCommand(char* args);
        bool HandleServerIdleShutDownCommand(char* args);
        bool HandleServerInfoCommand(char* args);
        bool HandleServerMotdCommand(char* args);
        bool HandleServerPLimitCommand(char* args);
        bool HandleServerRestartCommand(char* args);
        bool HandleServerSetLogLevelCommand(char* args);
        bool HandleServerSetMotdCommand(char* args);
        bool HandleServerShutDownCommand(char* args);
        bool HandleServerShutDownCancelCommand(char* args);
        bool HandleServerSetClosedCommand(char* args);
        bool HandleServerToggleQueryLogging(char* args);

        bool HandleServerSetLogFileLevelCommand(char* args);
        bool HandleServerSetDiffTimeCommand(char* args);

        bool HandleUnBanAccountCommand(char* args);
        bool HandleUnBanAccountByCharCommand(char* args);
        bool HandleUnBanCharacterCommand(char* args);
        bool HandleUnBanIPCommand(char* args);

        bool HandleWintergraspStatusCommand(char* args);
        bool HandleWintergraspStartCommand(char* args);
        bool HandleWintergraspStopCommand(char* args);
        bool HandleWintergraspEnableCommand(char* args);
        bool HandleWintergraspSwitchTeamCommand(char* args);
        bool HandleWintergraspTimerCommand(char* args);

        bool HandleHelpCommand(char* args);
        bool HandleCommandsCommand(char* args);
        bool HandleStartCommand(char* args);
        bool HandleDismountCommand(char* args);
        bool HandleSaveCommand(char* args);

        bool HandleSummonCommand(char* args);
        bool HandleAppearCommand(char* args);
        bool HandleGroupSummonCommand(char* args);
        bool HandleRecallCommand(char* args);
        bool HandleAnnounceCommand(char* args);
        bool HandleNotifyCommand(char* args);
        bool HandleGPSCommand(char* args);
        bool HandleTaxiCheatCommand(char* args);
        bool HandleWhispersCommand(char* args);

        bool HandleGUIDCommand(char* args);
        bool HandleItemMoveCommand(char* args);
        bool HandleDeMorphCommand(char* args);
        bool HandlePInfoCommand(char* args);
        bool HandleMuteCommand(char* args);
        bool HandleUnmuteCommand(char* args);
        bool HandleMovegensCommand(char* args);
        bool HandleFreezeCommand(char* args);
        bool HandleUnFreezeCommand(char* args);
        bool HandleListFreezeCommand(char* args);
        bool HandlePartyInfoCommand(char* args);

        bool HandleCooldownCommand(char* args);
        bool HandleUnLearnCommand(char* args);
        bool HandleGetDistanceCommand(char* args);
        bool HandleDieCommand(char* args);
        bool HandleDamageCommand(char* args);
        bool HandleReviveCommand(char* args);
        bool HandleAuraCommand(char* args);
        bool HandleUnAuraCommand(char* args);
        bool HandleLinkGraveCommand(char* args);
        bool HandleNearGraveCommand(char* args);
        bool HandleActivateObjectCommand(char* args);
        bool HandleSpawnTransportCommand(char* args);
        bool HandleExploreCheatCommand(char* args);
        bool HandleHoverCommand(char* args);
        bool HandleWaterwalkCommand(char* args);
        bool HandleLevelUpCommand(char* args);
        bool HandleShowAreaCommand(char* args);
        bool HandleHideAreaCommand(char* args);
        bool HandleAddItemCommand(char* args);
        bool HandleAddItemSetCommand(char* args);
        bool HandlePetTpCommand(char* args);
        bool HandlePetUnlearnCommand(char* args);
        bool HandlePetLearnCommand(char* args);
        bool HandleCreatePetCommand(char* args);

        bool HandleGroupLeaderCommand(char* args);
        bool HandleGroupDisbandCommand(char* args);
        bool HandleGroupRemoveCommand(char* args);

        bool HandleBankCommand(char* args);
        bool HandleChangeWeatherCommand(char* args);
        bool HandleKickPlayerCommand(char* args);

        // GM ticket command handlers
        bool HandleGMTicketListCommand(char* args);
        bool HandleGMTicketListOnlineCommand(char* args);
        bool HandleGMTicketListClosedCommand(char* args);
        bool HandleGMTicketListEscalatedCommand(char* args);
        bool HandleGMTicketGetByIdCommand(char* args);
        bool HandleGMTicketGetByNameCommand(char* args);
        bool HandleGMTicketCloseByIdCommand(char* args);
        bool HandleGMTicketAssignToCommand(char* args);
        bool HandleGMTicketUnAssignCommand(char* args);
        bool HandleGMTicketCommentCommand(char* args);
        bool HandleGMTicketDeleteByIdCommand(char* args);
        bool HandleGMTicketReloadCommand(char* args);
        bool HandleToggleGMTicketSystem(char* args);
        bool HandleGMTicketEscalateCommand(char* args);
        bool HandleGMTicketCompleteCommand(char* args);
        bool HandleGMTicketResponseAppendCommand(char* args);
        bool HandleGMTicketResponseAppendLnCommand(char* args);

        bool HandleMaxSkillCommand(char* args);
        bool HandleSetSkillCommand(char* args);
        bool HandleRespawnCommand(char* args);
        bool HandleComeToMeCommand(char* args);
        bool HandleCombatStopCommand(char* args);

        /*bool HandleCharDeleteCommand(char* args);
        bool HandleSendMessageCommand(char* args);*/

        bool HandleFlushArenaPointsCommand(char* args);

        // Jail by WarHead Edited by Vlad
        bool HandleJailCommand(char* args);
        bool HandleJailInfoCommand(char* args);
        bool HandleUnJailCommand(char* args);
        bool HandleClearJailCommand(char* args);
		
        bool HandlePlayAllCommand(char* args);
        bool HandleRepairitemsCommand(char* args);

        bool HandleTempGameObjectCommand(char* args);

        // ChatSpy system
        bool HandleChatSpyResetCommand(char* args);
        bool HandleChatSpyCancelCommand(char* args);
        bool HandleChatSpySetCommand(char* args);
        bool HandleChatSpyStatusCommand(char* args);
        bool HandleChatSpyModeCommand(char* args);

        //! Development Commands

        /*bool HandleQuestAdd(const char * args);
        bool HandleQuestRemove(const char * args);
        bool HandleQuestComplete(const char * args);*/

        //bool HandleSet32Bit(const char* args);
        bool HandleSaveAllCommand(char* args);

        // Utility methods for commands
        bool LookupPlayerSearchCommand(QueryResult result, int32 limit);
        bool HandleBanListHelper(QueryResult result);
        bool HandleBanInfoHelper(uint32 accountid, char const* accountname);
        bool HandleUnBanHelper(BanMode mode,char* args);
        void HandleCharacterLevel(Player* player, uint64 player_guid, uint32 oldlevel, uint32 newlevel);
        void HandleLearnSkillRecipesHelper(Player* player,uint32 skill_id);

        // Stores informations about a deleted character
        struct DeletedInfo
        {
            uint32      lowguid;                            ///< the low GUID from the character
            std::string name;                               ///< the character name
            uint32      accountId;                          ///< the account id
            std::string accountName;                        ///< the account name
            time_t      deleteDate;                         ///< the date at which the character has been deleted
        };

        typedef std::list<DeletedInfo> DeletedInfoList;
        bool GetDeletedCharacterInfoList(DeletedInfoList& foundList, std::string searchString = "");
        std::string GenerateDeletedCharacterGUIDsWhereStr(DeletedInfoList::const_iterator& itr, DeletedInfoList::const_iterator const& itr_end);
        void HandleCharacterDeletedListHelper(DeletedInfoList const& foundList);
        void HandleCharacterDeletedRestoreHelper(DeletedInfo const& delInfo);

    private:
        WorldSession * m_session;                           // != NULL for chat command call and NULL for CLI command

        // common global flag
        static bool load_command_table;
        bool sentErrorMessage;
};

class CliHandler : public ChatHandler
{
    public:
        typedef void Print(void*, char const*);
        explicit CliHandler(void* callbackArg, Print* zprint) : m_callbackArg(callbackArg), m_print(zprint) {}

        // overwrite functions
        const char *GetTrinityString(int32 entry) const;
        bool isAvailable(ChatCommand const& cmd) const;
        void SendSysMessage(const char *str);
        std::string GetNameLink() const;
        bool needReportToTarget(Player* chr) const;
        LocaleConstant GetSessionDbcLocale() const;
        int GetSessionDbLocaleIndex() const;

    private:
        void* m_callbackArg;
        Print* m_print;
};

char const *fmtstring(char const *format, ...);

#endif

