/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
        bool (*Handler)(ChatHandler*, const char* args);
        std::string        Help;
        ChatCommand*      ChildCommands;
};

class ChatHandler
{
    public:
        WorldSession* GetSession() { return m_session; }
        explicit ChatHandler(WorldSession* session) : m_session(session) {}
        explicit ChatHandler(Player* player) : m_session(player->GetSession()) {}
        virtual ~ChatHandler() {}

        static void FillMessageData(WorldPacket* data, WorldSession* session, uint8 type, uint32 language, const char *channelName, uint64 target_guid, const char *message, Unit* speaker, const char* addonPrefix = NULL);

        void FillMessageData(WorldPacket* data, uint8 type, uint32 language, uint64 target_guid, const char* message)
        {
            FillMessageData(data, m_session, type, language, NULL, target_guid, message, NULL);
        }

        void FillSystemMessageData(WorldPacket* data, const char* message)
        {
            FillMessageData(data, CHAT_MSG_SYSTEM, LANG_UNIVERSAL, 0, message);
        }

        static char* LineFromMessage(char*& pos) { char* start = strtok(pos, "\n"); pos = NULL; return start; }

        // function with different implementation for chat/console
        virtual const char *GetTrinityString(int32 entry) const;
        virtual void SendSysMessage(const char *str);

        void SendSysMessage(int32     entry);
        void PSendSysMessage(const char *format, ...) ATTR_PRINTF(2, 3);
        void PSendSysMessage(int32     entry, ...);
        std::string PGetParseString(int32 entry, ...) const;

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

        char*     extractKeyFromLink(char* text, char const* linkType, char** something1 = NULL);
        char*     extractKeyFromLink(char* text, char const* const* linkTypes, int* found_idx, char** something1 = NULL);

        // if args have single value then it return in arg2 and arg1 == NULL
        void      extractOptFirstArg(char* args, char** arg1, char** arg2);
        char*     extractQuotedArg(char* args);

        uint32    extractSpellIdFromLink(char* text);
        uint64    extractGuidFromLink(char* text);
        GameTele const* extractGameTeleFromLink(char* text);
        bool GetPlayerGroupAndGUIDByName(const char* cname, Player* &player, Group* &group, uint64 &guid, bool offline = false);
        std::string extractPlayerNameFromLink(char* text);
        // select by arg (name/link) or in-game selection online/offline player
        bool extractPlayerTarget(char* args, Player** player, uint64* player_guid = NULL, std::string* player_name = NULL);

        std::string playerLink(std::string const& name) const { return m_session ? "|cffffffff|Hplayer:"+name+"|h["+name+"]|h|r" : name; }
        std::string GetNameLink(Player* chr) const { return playerLink(chr->GetName()); }

        GameObject* GetNearbyGameObject();
        GameObject* GetObjectGlobalyWithGuidOrNearWithDbGuid(uint32 lowguid, uint32 entry);
        bool HasSentErrorMessage() const { return sentErrorMessage; }
        void SetSentErrorMessage(bool val){ sentErrorMessage = val; }
        static bool LoadCommandTable() { return load_command_table; }
        static void SetLoadCommandTable(bool val) { load_command_table = val; }

        // cs_character
        void HandleCharacterLevel(Player* player, uint64 playerGuid, uint32 oldLevel, uint32 newLevel);

    protected:
        explicit ChatHandler() : m_session(NULL) {}      // for CLI subclass
        static bool SetDataForCommandInTable(ChatCommand* table, const char* text, uint32 security, std::string const& help, std::string const& fullcommand);
        bool ExecuteCommandInTable(ChatCommand* table, const char* text, const std::string& fullcmd);
        bool ShowHelpForCommand(ChatCommand* table, const char* cmd);
        bool ShowHelpForSubCommands(ChatCommand* table, char const* cmd, char const* subcmd);

        bool HandleNameAnnounceCommand(const char* args);
        bool HandleGMNameAnnounceCommand(const char* args);
        bool HandleGMAnnounceCommand(const char* args);
        bool HandleGMNotifyCommand(const char* args);

        bool HandleChannelSetOwnership(const char *args);

        bool HandlePossessCommand(const char* args);
        bool HandleUnPossessCommand(const char* args);
        bool HandleBindSightCommand(const char* args);
        bool HandleUnbindSightCommand(const char* args);

        bool HandlePDumpLoadCommand(const char *args);
        bool HandlePDumpWriteCommand(const char *args);

        bool HandleSendItemsCommand(const char* args);
        bool HandleSendMailCommand(const char* args);
        bool HandleSendMessageCommand(const char * args);
        bool HandleSendMoneyCommand(const char* args);

        bool HandleHelpCommand(const char* args);
        bool HandleCommandsCommand(const char* args);
        bool HandleStartCommand(const char* args);
        bool HandleDismountCommand(const char* args);
        bool HandleSaveCommand(const char* args);

        bool HandleSummonCommand(const char* args);
        bool HandleAppearCommand(const char* args);
        bool HandleGroupSummonCommand(const char* args);
        bool HandleRecallCommand(const char* args);
        bool HandleAnnounceCommand(const char* args);
        bool HandleNotifyCommand(const char* args);
        bool HandleTaxiCheatCommand(const char* args);
        bool HandleWhispersCommand(const char* args);

        bool HandleGUIDCommand(const char* args);
        bool HandleItemMoveCommand(const char* args);
        bool HandleDeMorphCommand(const char* args);
        bool HandlePInfoCommand(const char* args);
        bool HandleMuteCommand(const char* args);
        bool HandleUnmuteCommand(const char* args);
        bool HandleMovegensCommand(const char* args);
        bool HandleFreezeCommand(const char *args);
        bool HandleUnFreezeCommand(const char *args);
        bool HandleListFreezeCommand(const char* args);

        bool HandleCooldownCommand(const char* args);
        bool HandleUnLearnCommand(const char* args);
        bool HandleGetDistanceCommand(const char* args);
        bool HandleDieCommand(const char* args);
        bool HandleDamageCommand(const char *args);
        bool HandleReviveCommand(const char* args);
        bool HandleAuraCommand(const char* args);
        bool HandleUnAuraCommand(const char* args);
        bool HandleLinkGraveCommand(const char* args);
        bool HandleNearGraveCommand(const char* args);
        bool HandleActivateObjectCommand(const char* args);
        bool HandleSpawnTransportCommand(const char* args);
        bool HandleExploreCheatCommand(const char* args);
        bool HandleWaterwalkCommand(const char* args);
        bool HandleLevelUpCommand(const char* args);
        bool HandleShowAreaCommand(const char* args);
        bool HandleHideAreaCommand(const char* args);
        bool HandleAddItemCommand(const char* args);
        bool HandleAddItemSetCommand(const char* args);
        bool HandlePetUnlearnCommand(const char* args);
        bool HandlePetLearnCommand(const char* args);
        bool HandleCreatePetCommand(const char* args);

        bool HandleGroupLeaderCommand(const char* args);
        bool HandleGroupDisbandCommand(const char* args);
        bool HandleGroupRemoveCommand(const char* args);

        bool HandleBankCommand(const char* args);
        bool HandleChangeWeather(const char* args);
        bool HandleKickPlayerCommand(const char * args);

        bool HandleMaxSkillCommand(const char* args);
        bool HandleSetSkillCommand(const char* args);
        bool HandleRespawnCommand(const char* args);
        bool HandleComeToMeCommand(const char *args);
        bool HandleCombatStopCommand(const char *args);

        /*bool HandleCharDeleteCommand(const char *args);
        bool HandleSendMessageCommand(const char * args);*/

        bool HandleFlushArenaPointsCommand(const char *args);
        bool HandlePlayAllCommand(const char* args);
        bool HandleRepairitemsCommand(const char* args);

        bool HandleTempGameObjectCommand(const char* args);

        //! Development Commands

        /*bool HandleQuestAdd(const char * args);
        bool HandleQuestRemove(const char * args);
        bool HandleQuestComplete(const char * args);*/

        //bool HandleSet32Bit(const char* args);
        bool HandleSaveAllCommand(const char* args);

        // Utility methods for commands
        void HandleLearnSkillRecipesHelper(Player* player, uint32 skill_id);

    private:
        WorldSession* m_session;                           // != NULL for chat command call and NULL for CLI command

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

#endif
