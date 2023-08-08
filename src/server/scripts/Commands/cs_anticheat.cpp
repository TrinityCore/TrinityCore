/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#include "Language.h"
#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "ObjectAccessor.h"
#include "Chat.h"
#include "AnticheatMgr.h"
#include "Player.h"
#include "World.h"
#include "WorldSession.h"
#include "SpellAuras.h"
#include "DatabaseEnv.h"

using namespace Trinity::ChatCommands;

enum Spells
{
    SHACKLES = 38505,
    LFG_SPELL_DUNGEON_DESERTER = 71041,
    BG_SPELL_DESERTER = 26013,
    SILENCED = 23207
};

class anticheat_commandscript : public CommandScript
{
public:
    anticheat_commandscript() : CommandScript("anticheat_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable anticheatCommandTable =
        {
            { "global",      HandleAntiCheatGlobalCommand,   rbac::RBAC_ROLE_GAMEMASTER,              Console::Yes },
            { "player",      HandleAntiCheatPlayerCommand,   rbac::RBAC_ROLE_GAMEMASTER,              Console::Yes },
            { "delete",      HandleAntiCheatDeleteCommand,   rbac::RBAC_ROLE_ADMINISTRATOR,           Console::Yes },
            { "purge",       HandleAntiCheatPurgeCommand,    rbac::RBAC_ROLE_ADMINISTRATOR,           Console::Yes },
            { "handle",      HandleAntiCheatHandleCommand,   rbac::RBAC_ROLE_ADMINISTRATOR,           Console::Yes },
            { "jail",        HandleAnticheatJailCommand,     rbac::RBAC_ROLE_GAMEMASTER,              Console::Yes },
            { "parole",      HandleAnticheatParoleCommand,   rbac::RBAC_ROLE_ADMINISTRATOR,           Console::Yes },
            { "warn",        HandleAnticheatWarnCommand,     rbac::RBAC_ROLE_GAMEMASTER,              Console::Yes }
        };

        static ChatCommandTable commandTable =
        {
            { "anticheat", anticheatCommandTable },
        };

        return commandTable;
    }

    static bool HandleAnticheatWarnCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
            return false;

        if (!player)
            player = PlayerIdentifier::FromTarget(handler);
        if (!player || !player->IsConnected())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        ChatHandler(player->GetConnectedPlayer()->GetSession()).SendSysMessage("The anticheat system has reported several times that you may be cheating. You will be monitored to confirm if this is accurate.");
        return true;
    }

    static bool HandleAnticheatJailCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
            return false;

        if (!player)
            player = PlayerIdentifier::FromTarget(handler);
        if (!player || !player->IsConnected())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* pTarget = player->GetConnectedPlayer();

        // teleport both to jail.
        if (!handler->IsConsole())
        {
            handler->GetSession()->GetPlayer()->TeleportTo(1, 16226.5f, 16403.6f, -64.5f, 3.2f);
        }

        WorldLocation loc = WorldLocation(1, 16226.5f, 16403.6f, -64.5f, 3.2f);// GM Jail Location
        pTarget->TeleportTo(loc);
        pTarget->SetHomebind(loc, 876);// GM Jail Homebind location
        pTarget->CastSpell(pTarget, SHACKLES);// shackle him in place to ensure no exploit happens for jail break attempt
        if (Aura* dungdesert = pTarget->AddAura(LFG_SPELL_DUNGEON_DESERTER, pTarget))// LFG_SPELL_DUNGEON_DESERTER
        {
            dungdesert->SetDuration(-1);
        }
        if (Aura* bgdesert = pTarget->AddAura(BG_SPELL_DESERTER, pTarget))// BG_SPELL_DESERTER
        {
            bgdesert->SetDuration(-1);
        }
        if (Aura* silent = pTarget->AddAura(SILENCED, pTarget))// SILENCED
        {
            silent->SetDuration(-1);
        }

        return true;
    }

    static bool HandleAnticheatParoleCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
            return false;

        if (!player)
            player = PlayerIdentifier::FromTarget(handler);
        if (!player || !player->IsConnected())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Player* pTarget = player->GetConnectedPlayer();

        WorldLocation Aloc = WorldLocation(0, -8833.37f, 628.62f, 94.00f, 1.06f);// Stormwind
        WorldLocation Hloc = WorldLocation(1, 1569.59f, -4397.63f, 16.06f, 0.54f);// Orgrimmar

        if (pTarget->GetTeamId() == TEAM_ALLIANCE)
        {
            pTarget->TeleportTo(0, -8833.37f, 628.62f, 94.00f, 1.06f);//Stormwind
            pTarget->SetHomebind(Aloc, 1519);// Stormwind Homebind location
        }
        else
        {
            pTarget->TeleportTo(1, 1569.59f, -4397.63f, 7.7f, 0.54f);//Orgrimmar
            pTarget->SetHomebind(Hloc, 1653);// Orgrimmar Homebind location
        }
        pTarget->RemoveAura(SHACKLES);// remove shackles
        pTarget->RemoveAura(LFG_SPELL_DUNGEON_DESERTER);// LFG_SPELL_DUNGEON_DESERTER
        pTarget->RemoveAura(BG_SPELL_DESERTER);// BG_SPELL_DESERTER
        pTarget->RemoveAura(SILENCED);// SILENCED
        sAnticheatMgr->AnticheatDeleteCommand(pTarget->GetGUID());// deletes auto reports on player
        return true;
    }

    static bool HandleAntiCheatDeleteCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
            return false;

        if (!player)
            player = PlayerIdentifier::FromTarget(handler);
        if (!player || !player->IsConnected())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }
        sAnticheatMgr->AnticheatDeleteCommand(player->GetGUID());
        handler->PSendSysMessage("Anticheat players_reports_status deleted for player %s", player->GetName().c_str());
        return true;
    }
    static bool HandleAntiCheatPurgeCommand(ChatHandler* handler)
    {
        // For the sins I am about to commit, may CTHULHU forgive me
        // this will purge the daily_player_reports which is the cumlative statistics of auto reports
        sAnticheatMgr->AnticheatPurgeCommand(handler);
        handler->PSendSysMessage("The Anticheat daily_player_reports has been purged.");
        return true;
    }

    static bool HandleAntiCheatPlayerCommand(ChatHandler* handler, Optional<PlayerIdentifier> player)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
            return false;

        if (!player)
        {
            player = PlayerIdentifier::FromTarget(handler);
        }
        if (!player || !player->IsConnected())
        {
            handler->SendSysMessage(LANG_PLAYER_NOT_FOUND);
            handler->SetSentErrorMessage(true);
            return false;
        }

        uint32 guid = player->GetGUID().GetCounter();

        float average = sAnticheatMgr->GetAverage(guid);
        uint32 total_reports = sAnticheatMgr->GetTotalReports(guid);
        uint32 speed_reports = sAnticheatMgr->GetTypeReports(guid,0);
        uint32 fly_reports = sAnticheatMgr->GetTypeReports(guid,1);
        uint32 jump_reports = sAnticheatMgr->GetTypeReports(guid,3);
        uint32 waterwalk_reports = sAnticheatMgr->GetTypeReports(guid,2);
        uint32 teleportplane_reports = sAnticheatMgr->GetTypeReports(guid,4);
        uint32 climb_reports = sAnticheatMgr->GetTypeReports(guid,5);
        uint32 teleport_reports = sAnticheatMgr->GetTypeReports(guid, 6);
        uint32 ignorecontrol_reports = sAnticheatMgr->GetTypeReports(guid, 7);
        uint32 zaxis_reports = sAnticheatMgr->GetTypeReports(guid, 8);
        uint32 antiswim_reports = sAnticheatMgr->GetTypeReports(guid, 9);
        uint32 gravity_reports = sAnticheatMgr->GetTypeReports(guid, 10);
        uint32 antiknockback_reports = sAnticheatMgr->GetTypeReports(guid, 11);
        uint32 no_fall_damage_reports = sAnticheatMgr->GetTypeReports(guid, 12);
        uint32 op_ack_reports = sAnticheatMgr->GetTypeReports(guid, 13);
        uint32 counter_measures_reports = sAnticheatMgr->GetTypeReports(guid, 14);

        uint32 latency = 0;
        latency = player->GetConnectedPlayer()->GetSession()->GetLatency();

        if (!handler->IsConsole())
        {
            // account ban info
            QueryResult resultADB = LoginDatabase.PQuery("SELECT FROM_UNIXTIME(bandate), unbandate-bandate, active, unbandate, banreason, bannedby FROM account_banned WHERE id = '%u' ORDER BY bandate ASC", player->GetConnectedPlayer()->GetSession()->GetAccountId());
            // character ban info
            QueryResult resultCDB = CharacterDatabase.PQuery("SELECT FROM_UNIXTIME(bandate), unbandate-bandate, active, unbandate, banreason, bannedby FROM character_banned WHERE guid = '%u' ORDER BY bandate ASC", player->GetConnectedPlayer()->GetSession()->GetAccountId());
            //                                                           0      1      2     3
            QueryResult resultLDB = CharacterDatabase.PQuery("SELECT accountId, type, time, data FROM account_data WHERE `data` LIKE '%%CastSpellByName%%' AND accountId ='%u'", player->GetConnectedPlayer()->GetSession()->GetAccountId());

            handler->PSendSysMessage("|cFFFFA500-----------------------------------------------------------------");
            handler->PSendSysMessage("|cFF20B2AAInformation about player: |cffffff00%s", player->GetName().c_str());
            handler->PSendSysMessage("|cffff0000IP Address: |cffffff00%s |cffff0000Latency |cffffff00%u ms", player->GetConnectedPlayer()->GetSession()->GetRemoteAddress().c_str(), latency);
            if (resultADB)
            {
                do
                {
                    Field* fields = resultADB->Fetch();
                    std::string startbanEnd = TimeToTimestampStr(fields[3].GetUInt64());
                    std::string bannedReason = fields[4].GetString();
                    std::string bannedBy = fields[5].GetString();
                    handler->PSendSysMessage("|cffff0000Account Previously Banned: |cffffff00Yes");
                    handler->PSendSysMessage("|cffff0000Ban Ended: |cffffff00%s", startbanEnd.c_str());
                    handler->PSendSysMessage("|cffff0000Ban by: |cffffff00%s |cffff0000Ban Reason: |cffffff00%s", bannedBy.c_str(), bannedReason.c_str());
                } while (resultADB->NextRow());
            }
            if (!resultADB)
            {
                handler->PSendSysMessage("|cffff0000Account Previously Banned: |cffffff00No");
            }
            if (resultCDB)
            {
                do
                {
                    Field* fields = resultCDB->Fetch();
                    std::string startbanEnd = TimeToTimestampStr(fields[3].GetUInt64());
                    std::string bannedReason = fields[4].GetString();
                    std::string bannedBy = fields[5].GetString();
                    handler->PSendSysMessage("|cffff0000Character Previously Banned: |cffffff00Yes");
                    handler->PSendSysMessage("|cffff0000Ban Ended: |cffffff00%s", startbanEnd.c_str());
                    handler->PSendSysMessage("|cffff0000Ban by: |cffffff00%s |cffff0000Ban Reason: |cffffff00%s", bannedBy.c_str(), bannedReason.c_str());
                } while (resultCDB->NextRow());
            }
            if (!resultCDB)
            {
                handler->PSendSysMessage("|cffff0000Character Previously Banned: |cffffff00No");
            }
            if (resultLDB)
            {
                do
                {
                    handler->PSendSysMessage("|cffff0000Macro Requiring Lua unlock Detected: |cffffff00Yes");
                } while (resultLDB->NextRow());
            }
            if (!resultLDB)
            {
                handler->PSendSysMessage("|cffff0000Macro Requiring Lua unlock Detected: |cffffff00No");
            }
            handler->PSendSysMessage("|cffff0000Counter Measures Deployed: |cffffff00%u", counter_measures_reports);
            handler->PSendSysMessage("|cffff0000Average: |cffffff00%f |cffff0000Total Reports: |cffffff00%u ", average, total_reports);
            handler->PSendSysMessage("|cffff0000Speed Reports: |cffffff00%u |cffff0000Fly Reports: |cffffff00%u |cffff0000Jump Reports: |cffffff00%u ", speed_reports, fly_reports, jump_reports);
            handler->PSendSysMessage("|cffff0000Walk On Water Reports:|cffffff00 %u |cffff0000Teleport To Plane Reports: |cffffff00%u", waterwalk_reports, teleportplane_reports);
            handler->PSendSysMessage("|cffff0000Teleport Reports: |cffffff00%u |cffff0000Climb Reports: |cffffff00%u", teleport_reports, climb_reports);
            handler->PSendSysMessage("|cffff0000Ignore Control Reports: |cffffff00%u |cffff0000Ignore Z-Axis Reports: |cffffff00%u", ignorecontrol_reports, zaxis_reports);
            handler->PSendSysMessage("|cffff0000Ignore Anti-Swim Reports: |cffffff00%u |cffff0000Gravity Reports: |cffffff00%u", antiswim_reports, gravity_reports);
            handler->PSendSysMessage("|cffff0000Anti-Knock Back Reports: |cffffff00%u |cffff0000No Fall Damage Reports: |cffffff00%u", antiknockback_reports, no_fall_damage_reports);
            handler->PSendSysMessage("|cffff0000Op Ack Reports: |cffffff00%u", op_ack_reports);
        }
        if (handler->IsConsole())
        {
            // account ban info
            QueryResult resultADB = LoginDatabase.PQuery("SELECT FROM_UNIXTIME(bandate), unbandate-bandate, active, unbandate, banreason, bannedby FROM account_banned WHERE id = '%u' ORDER BY bandate ASC", player->GetConnectedPlayer()->GetSession()->GetAccountId());
            // character ban info
            QueryResult resultCDB = CharacterDatabase.PQuery("SELECT FROM_UNIXTIME(bandate), unbandate-bandate, active, unbandate, banreason, bannedby FROM character_banned WHERE guid = '%u' ORDER BY bandate ASC", player->GetConnectedPlayer()->GetSession()->GetAccountId());
            //                                                           0      1      2     3
            QueryResult resultLDB = CharacterDatabase.PQuery("SELECT accountId, type, time, data FROM account_data WHERE `data` LIKE '%%CastSpellByName%%' AND accountId ='%u'", player->GetConnectedPlayer()->GetSession()->GetAccountId());

            handler->PSendSysMessage("-----------------------------------------------------------------");
            handler->PSendSysMessage("Information about player %s", player->GetName().c_str());
            handler->PSendSysMessage("IP Address: %s || Latency %u ms", player->GetConnectedPlayer()->GetSession()->GetRemoteAddress().c_str(), latency);
            if (resultADB)
            {
                do
                {
                    Field* fields = resultADB->Fetch();
                    std::string startbanEnd = TimeToTimestampStr(fields[3].GetUInt64());
                    std::string bannedReason = fields[4].GetString();
                    std::string bannedBy = fields[5].GetString();
                    handler->PSendSysMessage("Account Previously Banned: Yes");
                    handler->PSendSysMessage("Ban Ended: %s", startbanEnd.c_str());
                    handler->PSendSysMessage("Ban by: %s || Ban Reason: %s", bannedBy.c_str(), bannedReason.c_str());
                } while (resultADB->NextRow());
            }
            if (!resultADB)
            {
                handler->PSendSysMessage("Account Previously Banned: No");
            }
            if (resultCDB)
            {
                do
                {
                    Field* fields = resultCDB->Fetch();
                    std::string startbanEnd = TimeToTimestampStr(fields[3].GetUInt64());
                    std::string bannedReason = fields[4].GetString();
                    std::string bannedBy = fields[5].GetString();
                    handler->PSendSysMessage("Character Previously Banned: Yes");
                    handler->PSendSysMessage("Ban Ended: %s", startbanEnd.c_str());
                    handler->PSendSysMessage("Ban by: %s || Ban Reason: %s", bannedBy.c_str(), bannedReason.c_str());
                } while (resultCDB->NextRow());
            }
            if (!resultCDB)
            {
                handler->PSendSysMessage("Character Previously Banned: No");
            }
            if (resultLDB)
            {
                do
                {
                    handler->PSendSysMessage("Macro Requiring Lua unlock Detected: Yes");
                } while (resultLDB->NextRow());
            }
            if (!resultLDB)
            {
                handler->PSendSysMessage("Macro Requiring Lua unlock Detected: No");
            }
            handler->PSendSysMessage("Counter Measures Deployed: %u", counter_measures_reports);
            handler->PSendSysMessage("Average: %f || Total Reports: %u ", average, total_reports);
            handler->PSendSysMessage("Speed Reports: %u || Fly Reports: %u || Jump Reports: %u ", speed_reports, fly_reports, jump_reports);
            handler->PSendSysMessage("Walk On Water Reports: %u  || Teleport To Plane Reports: %u", waterwalk_reports, teleportplane_reports);
            handler->PSendSysMessage("Teleport Reports: %u || Climb Reports: %u", teleport_reports, climb_reports);
            handler->PSendSysMessage("Ignore Control Reports: %u || Ignore Z-Axis Reports: %u", ignorecontrol_reports, zaxis_reports);
            handler->PSendSysMessage("Ignore Anti-Swim Reports: %u || Gravity Reports: %u", antiswim_reports, gravity_reports);
            handler->PSendSysMessage("Anti-Knock Back Reports: %u || No Fall Damage Reports: %u", antiknockback_reports, no_fall_damage_reports);
            handler->PSendSysMessage("Op Ack Reports: %u", op_ack_reports);
        }
        return true;
    }

    static bool HandleAntiCheatHandleCommand(ChatHandler* handler, bool enable)
    {
        if (enable)
        {
            sWorld->setBoolConfig(CONFIG_ANTICHEAT_ENABLE,true);
            handler->SendSysMessage("The Anticheat System is now: Enabled!");
        }
        else
        {
            sWorld->setBoolConfig(CONFIG_ANTICHEAT_ENABLE,false);
            handler->SendSysMessage("The Anticheat System is now: Disabled!");
        }

        return true;
    }

    static bool HandleAntiCheatGlobalCommand(ChatHandler* handler)
    {
        if (!sWorld->getBoolConfig(CONFIG_ANTICHEAT_ENABLE))
        {
            handler->PSendSysMessage("The Anticheat System is disabled.");
            return true;
        }

        sAnticheatMgr->AnticheatGlobalCommand(handler);

        return true;
    }
};

void AddSC_anticheat_commandscript()
{
    new anticheat_commandscript();
}
