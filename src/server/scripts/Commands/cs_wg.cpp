/*
 * Copyright (C) 2008 - 2012 Trinity <http://www.trinitycore.org/>
 *
 * Copyright (C) 2012 Patch supported by ChaosUA & TCRU community http://trinity-core.ru/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "ScriptMgr.h"
#include "Chat.h"
#include "OutdoorPvPMgr.h"
#include "OutdoorPvPWG.h"

class wg_commandscript : public CommandScript
{
public:
    wg_commandscript() : CommandScript("wg_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand wintergraspCommandTable[] =
        {
            { "status",         SEC_ADMINISTRATOR,  false, &HandleWintergraspStatusCommand,       "", NULL },
            { "enable",         SEC_ADMINISTRATOR,  false, &HandleWintergraspEnableCommand,       "", NULL },
            { "start",          SEC_ADMINISTRATOR,  false, &HandleWintergraspStartCommand,        "", NULL },
            { "stop",           SEC_ADMINISTRATOR,  false, &HandleWintergraspStopCommand,         "", NULL },
            { "switch",         SEC_ADMINISTRATOR,  false, &HandleWintergraspSwitchTeamCommand,   "", NULL },
            { "timer",          SEC_ADMINISTRATOR,  false, &HandleWintergraspTimerCommand,        "", NULL },
            { NULL,             0,                  false, NULL,                                                           "", NULL }
        };

        static ChatCommand commandTable[] =
        {
            { "wg",             SEC_ADMINISTRATOR,  false, NULL,                                         "", wintergraspCommandTable },
            { NULL,             0,                  false, NULL,                                                            "", NULL }
        };
        return commandTable;
    }

    static bool HandleWintergraspStatusCommand(ChatHandler* handler, const char* /*args*/)
    {
        OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197);

       if (!pvpWG || !sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
        {
            handler->SendSysMessage(LANG_BG_WG_DISABLE);
            handler->SetSentErrorMessage(true);
            return false;
        }

        handler->PSendSysMessage(LANG_BG_WG_STATUS, sObjectMgr->GetTrinityStringForDBCLocale(
            pvpWG->getDefenderTeam() == TEAM_ALLIANCE ? LANG_BG_AB_ALLY : LANG_BG_AB_HORDE),
            secsToTimeString(pvpWG->GetTimer(), true).c_str(),
            pvpWG->isWarTime() ? "Yes" : "No",
            pvpWG->GetNumPlayersH(),
            pvpWG->GetNumPlayersA());
        return true;
    }

    static bool HandleWintergraspStartCommand(ChatHandler* handler, const char* /*args*/)
    {
        OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197);

        if (!pvpWG || !sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
        {
            handler->SendSysMessage(LANG_BG_WG_DISABLE);
            handler->SetSentErrorMessage(true);
            return false;
        }
        pvpWG->forceStartBattle();
        handler->PSendSysMessage(LANG_BG_WG_BATTLE_FORCE_START);
        return true;
    }

    static bool HandleWintergraspStopCommand(ChatHandler* handler, const char* /*args*/)
{
    OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197);

    if (!pvpWG || !sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
    {
        handler->SendSysMessage(LANG_BG_WG_DISABLE);
        handler->SetSentErrorMessage(true);
        return false;
    }
    pvpWG->forceStopBattle();
    handler->PSendSysMessage(LANG_BG_WG_BATTLE_FORCE_STOP);
    return true;
}

    static bool HandleWintergraspEnableCommand(ChatHandler* handler, const char* args)
{
    if(!*args)
        return false;

    OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197);

    /*if (!pvpWG || !sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
    {
        handler->SendSysMessage(LANG_BG_WG_DISABLE);
        handler->SetSentErrorMessage(true);
        return false;
    }*/

    if (!strncmp(args, "on", 3))
    {
        if (!sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
        {
            pvpWG->forceStopBattle();
            sWorld->setBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED, true);
        }
        handler->PSendSysMessage(LANG_BG_WG_ENABLE);
        return true;
    }
    else if (!strncmp(args, "off", 4))
    {
        if (sWorld->getBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED))
        {
            pvpWG->forceStopBattle();
            sWorld->setBoolConfig(CONFIG_OUTDOORPVP_WINTERGRASP_ENABLED, false);
        }
        handler->PSendSysMessage(LANG_BG_WG_DISABLE);
        return true;
    }
    else
    {
        handler->SendSysMessage(LANG_USE_BOL);
        handler->SetSentErrorMessage(true);
        return false;
    }
}

    static bool HandleWintergraspTimerCommand(ChatHandler* handler, const char* args)
{
    if(!*args)
        return false;

    OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197);

    if (!pvpWG)
    {
        handler->SendSysMessage(LANG_BG_WG_DISABLE);
        handler->SetSentErrorMessage(true);
        return false;
    }

    int32 time = atoi (args);

    // Min value 1 min
    if (1 > time)
        time = 1;
    // Max value during wartime = 60. No wartime = 1440 (day)
    if (pvpWG->isWarTime())
    {
        if (60 < time)
            return false;
    }
    else
        if (1440 < time)
            return false;
    time *= MINUTE * IN_MILLISECONDS;

    pvpWG->setTimer((uint32)time);
    sWorld->SendWintergraspState(); //Update WG time at bg tab
    handler->PSendSysMessage(LANG_BG_WG_CHANGE_TIMER, secsToTimeString(pvpWG->GetTimer(), true).c_str());
    return true;
}

    static bool HandleWintergraspSwitchTeamCommand(ChatHandler* handler, const char* /*args*/)
    {
        OutdoorPvPWG *pvpWG = (OutdoorPvPWG*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(4197);

        if (!pvpWG)
        {
            handler->SendSysMessage(LANG_BG_WG_DISABLE);
            handler->SetSentErrorMessage(true);
            return false;
        }
        uint32 timer = pvpWG->GetTimer();
        pvpWG->forceChangeTeam();
        pvpWG->setTimer(timer);
        handler->PSendSysMessage(LANG_BG_WG_SWITCH_FACTION, handler->GetTrinityString(pvpWG->getDefenderTeam() == TEAM_ALLIANCE ? LANG_BG_AB_ALLY : LANG_BG_AB_HORDE));
        return true;
    }
};

void AddSC_wg_commandscript()
{
    new wg_commandscript();
}
