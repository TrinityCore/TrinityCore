// Copyright 2010 by WarHead - United Worlds of MaNGOS - http://www.uwom.de

#include "ScriptMgr.h"
#include "Chat.h"
#include "OutdoorPvPTW.h"
#include "OutdoorPvPMgr.h"

class tw_commandscript : public CommandScript
{
public:
    tw_commandscript() : CommandScript("tw_commandscript") { }

    ChatCommand* GetCommands() const
    {
        static ChatCommand twCommandTable[] =
        {
            { "status",         SEC_PLAYER, true,   &HandleTausendwinterStatusCmd,          "", NULL },
            { "aktivieren",     SEC_GGM,    true,   &HandleTausendwinterAktivierenCmd,      "", NULL },
            { "deaktivieren",   SEC_GGM,    true,   &HandleTausendwinterDeaktivierenCmd,    "", NULL },
            { "start",          SEC_GGM,    true,   &HandleTausendwinterStartCmd,           "", NULL },
            { "stop",           SEC_GGM,    true,   &HandleTausendwinterStopCmd,            "", NULL },
            { "wechseln",       SEC_GGM,    true,   &HandleTausendwinterWechselnCmd,        "", NULL },
            { "zeit",           SEC_GGM,    true,   &HandleTausendwinterZeitCmd,            "", NULL },
            { NULL,             0,          false,  NULL,                                   "", NULL }
        };
        static ChatCommand commandTable[] =
        {
            { "tw", SEC_PLAYER, true,   NULL,   "", twCommandTable },
            { NULL, 0,          false,  NULL,   "", NULL }
        };
        return commandTable;
    }

    static bool HandleTausendwinterStatusCmd(ChatHandler* handler, const char* /*args*/)
    {
        Tausendwinter * pTW = (Tausendwinter*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER);
        if (!pTW)
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_VAR_INIT_FEHLER);
            handler->SetSentErrorMessage(true);
            return false;
        }
        else if (!sWorld->getBoolConfig(CONFIG_TW_AKTIVIERT))
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_DEAKTIVIERT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        else
        {
            handler->PSendSysMessage(LANG_TAUSENDWINTER_STATUS_INFO_TEIL_1,
                pTW->HoleVerteidigerTeamId() == TEAM_ALLIANCE ? sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_ALLY) : sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_HORDE));

            handler->PSendSysMessage(LANG_TAUSENDWINTER_STATUS_INFO_TEIL_2,
                pTW->IstKampf() ? sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_JA) : sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_NEIN));

            handler->PSendSysMessage(LANG_TAUSENDWINTER_STATUS_INFO_TEIL_3, secsToTimeString(pTW->HoleZeitInSekunden(), true).c_str());

            handler->PSendSysMessage(LANG_TAUSENDWINTER_STATUS_INFO_TEIL_4, pTW->HoleSpieleranzahl(TEAM_ALLIANCE), pTW->HoleSpieleranzahl(TEAM_HORDE));

            return true;
        }
    }

    static bool HandleTausendwinterStartCmd(ChatHandler* handler, const char* /*args*/)
    {
        Tausendwinter * pTW = (Tausendwinter*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER);
        if (!pTW)
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_VAR_INIT_FEHLER);
            handler->SetSentErrorMessage(true);
            return false;
        }
        else if (!sWorld->getBoolConfig(CONFIG_TW_AKTIVIERT))
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_DEAKTIVIERT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        else
        {
            pTW->ErzwingeKampfStarten();
            sWorld->SendZoneText(NORDEND_TAUSENDWINTER, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_KAMPF_WURDE_GESTARTET), handler->GetSession()->GetPlayerName()));
            return true;
        }
    }

    static bool HandleTausendwinterStopCmd(ChatHandler* handler, const char* /*args*/)
    {
        Tausendwinter * pTW = (Tausendwinter*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER);
        if (!pTW)
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_VAR_INIT_FEHLER);
            handler->SetSentErrorMessage(true);
            return false;
        }
        else if (!sWorld->getBoolConfig(CONFIG_TW_AKTIVIERT))
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_DEAKTIVIERT);
            handler->SetSentErrorMessage(true);
            return false;
        }
        else
        {
            pTW->ErzwingeKampfBeenden();
            sWorld->SendZoneText(NORDEND_TAUSENDWINTER, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_KAMPF_WURDE_BEENDET), handler->GetSession()->GetPlayerName()));
            return true;
        }
    }

    static bool HandleTausendwinterAktivierenCmd(ChatHandler* handler, const char* /*args*/)
    {
        Tausendwinter * pTW = (Tausendwinter*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER);
        if (!pTW)
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_VAR_INIT_FEHLER);
            handler->SetSentErrorMessage(true);
            return false;
        }
        else
        {
            pTW->ErzwingeKampfStarten();
            sWorld->setBoolConfig(CONFIG_TW_AKTIVIERT, true);
            sWorld->SendServerMessage(SERVER_MSG_STRING, sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_AKTIVIERT), handler->GetSession()->GetPlayer());
            return true;
        }
    }

    static bool HandleTausendwinterDeaktivierenCmd(ChatHandler* handler, const char* /*args*/)
    {
        Tausendwinter * pTW = (Tausendwinter*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER);
        if (!pTW)
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_VAR_INIT_FEHLER);
            handler->SetSentErrorMessage(true);
            return false;
        }
        else
        {
            pTW->ErzwingeKampfBeenden();
            sWorld->setBoolConfig(CONFIG_TW_AKTIVIERT, false);
            sWorld->SendServerMessage(SERVER_MSG_STRING, sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_DEAKTIVIERT), handler->GetSession()->GetPlayer());
            return true;
        }
    }

    static bool HandleTausendwinterZeitCmd(ChatHandler* handler, const char* args)
    {
        if (!args)
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_KEINE_ZEIT);
            handler->SetSentErrorMessage(true);
            return false;
        }

        Tausendwinter * pTW = (Tausendwinter*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER);
        if (!pTW)
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_VAR_INIT_FEHLER);
            handler->SetSentErrorMessage(true);
            return false;
        }

        int32 Zeit = atoi(args);

        if (Zeit < 1)
            Zeit = 1;

        if (pTW->IstKampf() && Zeit > 60)
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_IM_KAMPF_MAX_60);
            handler->SetSentErrorMessage(true);
            return false;
        }
        else if (Zeit > 1440)
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_MAX_1440);
            handler->SetSentErrorMessage(true);
            return false;
        }
        pTW->SetzeZeit(uint32(Zeit *= IN_MILLISECONDS * MINUTE));
        sWorld->SendZoneText(NORDEND_TAUSENDWINTER, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_ZEIT_GEAENDERT), handler->GetSession()->GetPlayerName(),
            secsToTimeString(pTW->HoleZeitInSekunden(), true).c_str()));

        return true;
    }

    static bool HandleTausendwinterWechselnCmd(ChatHandler* handler, const char* /*args*/)
    {
        Tausendwinter * pTW = (Tausendwinter*)sOutdoorPvPMgr->GetOutdoorPvPToZoneId(NORDEND_TAUSENDWINTER);
        if (!pTW)
        {
            handler->SendSysMessage(LANG_TAUSENDWINTER_VAR_INIT_FEHLER);
            handler->SetSentErrorMessage(true);
            return false;
        }
        else
        {
            pTW->ErzwingeTeamwechsel();
            sWorld->SendZoneText(NORDEND_TAUSENDWINTER, fmtstring(sObjectMgr->GetTrinityStringForDBCLocale(LANG_TAUSENDWINTER_WECHSEL_DES_BESITZERS),
                pTW->HoleAngreiferTeamId() == TEAM_ALLIANCE ? sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_ALLY) : sObjectMgr->GetTrinityStringForDBCLocale(LANG_BG_AB_HORDE)));
            return true;
        }
    }
};

void AddSC_tw_commandscript()
{
    new tw_commandscript();
}
