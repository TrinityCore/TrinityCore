/*
 * MangChat By |Death| And Cybrax
 *
 * This Program Is Free Software; You Can Redistribute It And/Or Modify It Under The Terms 
 * Of The GNU General Public License
 * Written and Developed by Cybrax. cybraxvd@gmail.com
 * |Death| <death@hell360.net>, Lice <lice@yeuxverts.net>, Dj_baby & Sanaell, Tase
 * With Help And Support From The MaNGOS Project Community.
 * PLEASE RETAIN THE COPYRIGHT OF THE AUTHORS.
 */
#include "IRCCmd.h"
#include "IRCClient.h"
#include "Database/DatabaseEnv.h"
#include "ObjectMgr.h"
#include "MapManager.h"
// Constructor
IRCCmd::IRCCmd(){}
// Destructor
IRCCmd::~IRCCmd(){}

std::string IRCCmd::MakeUpper(std::string Channel)
{
    std::string tmpchan = Channel;
    std::transform(tmpchan.begin(), tmpchan.end(), tmpchan.begin(), towupper);
    return tmpchan;
}
bool IRCCmd::ParamsValid(_CDATA *CD, int pCnt)
{
    CD->PCOUNT = pCnt;
    if(CD->PARAMS.size() == 0)
        return false;
    return ValidParams(CD->PARAMS, pCnt);
}

int IRCCmd::ParamsValid(_CDATA *CD, int pCnt, int rLev)
{
    //CD->PCOUNT = pCnt;
    if(!CanUse(CD->USER, rLev))
        return E_AUTH;
    else if(pCnt == 0)
        return E_OK;
    else if(CD->PARAMS.size() == 0)
        return E_SIZE;
    else if(!ValidParams(CD->PARAMS, pCnt))
        return E_SIZE;
    return E_OK;
}

// This function checks if chat from irc is a command or not
// return true on yes and false on no
bool IRCCmd::IsValid(std::string USER, std::string FROM, std::string CHAT, std::string TYPE)
{
    // If the first line of our chat is the command prefix we have a command
    if(CHAT.substr(0, 1) == sIRC._cmd_prefx && CHAT.size() > 1 )
    {
        _CDATA CDATA;
        bool cValid    = false;
        bool AuthValid = true;
        bool dontlog   = true;
        std::string* _PARAMS = getArray(CHAT, 2);
        CDATA.USER      = USER;
        CDATA.FROM      = FROM;
        CDATA.TYPE      = TYPE;
        CDATA.PCOUNT    = 0;
        CDATA.CMD       = MakeUpper(_PARAMS[0].substr(1, _PARAMS[0].size() - 1));
        CDATA.PARAMS    = _PARAMS[1];   
        if(CDATA.CMD == "LOGIN")
        {
            if(FROM == sIRC._Nick)
            {             
                if(ParamsValid(&CDATA, 2))  
                    Handle_Login(&CDATA);
                else
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"login <Player> <Password> )", true, "ERROR");
            }
            else
                sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Please Send A PM To Login!", true, "ERROR");
            if(GetLevel(USER) >= sIRC.gmlog)
                dontlog = false;
            cValid = true;
        }
        else if(CDATA.CMD == "LOGOUT")
        {
            if(FROM == sIRC._Nick)
            {
                Handle_Logout(&CDATA);
            }
            else
                sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Please Send A PM To Logout!", true, "ERROR");
            cValid = true;
        }
        else if(CDATA.CMD == "ACCT")
        {
            switch(ParamsValid(&CDATA, 2, sIRC.CACCT))
            {
                case E_OK:
                    Account_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"acct <Player> <(un)lock/mail/pass/rename> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "BAN")
        {
            switch(ParamsValid(&CDATA, 2, sIRC.CBAN))
            {
                case E_OK:
                    Ban_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"ban <Player> <acct/ip> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "CHAN")
        {
            switch(ParamsValid(&CDATA, 1, sIRC.CCHAN))
            {
                case E_OK:
                    Chan_Control(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"chan <op> <IRC User> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "CHAR")
        {
            switch(ParamsValid(&CDATA, 2, sIRC.CCHAR))
            {
                case E_OK:
                    Char_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"char <Player> <mailcheat/taxicheat/maxskill/setskill> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "FUN")
        {
            switch(ParamsValid(&CDATA, 2, sIRC.CFUN))
            {
                case E_OK:
                    Fun_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"fun <Player> <Sound/Say> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "HELP")
        {
            switch(ParamsValid(&CDATA, 0, sIRC.CHELP))
            {
                case E_OK:
                    Help_IRC(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"help <Command> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "INCHAN")
        {
            switch(ParamsValid(&CDATA, 1, sIRC.CINCHAN))
            {
                case E_OK:
                    Inchan_Server(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"inchan <Channel> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "INFO")
        {
            switch(ParamsValid(&CDATA, 0, sIRC.CINFO))
            {
                case E_OK:
                    Info_Server(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"info )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "ITEM")
        {
            CDATA.PCOUNT = 3;
            switch(ParamsValid(&CDATA, 2, sIRC.CITEM))
            {
                case E_OK:
                    Item_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"item <Player> <add> <ItemID/[ItemName]> <Amount> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "JAIL")
        {
            CDATA.PCOUNT = 3;
            switch(ParamsValid(&CDATA, 1, sIRC.CJAIL))
            {
                case E_OK:
                    Jail_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"jail <Player> <release/Reason>)", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "KICK")
        {
            CDATA.PCOUNT = 2;
            switch(ParamsValid(&CDATA, 1, sIRC.CKICK))
            {
                case E_OK:
                    Kick_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"kick <Player> <Reason> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "KILL")
        {
            CDATA.PCOUNT = 2;
            switch(ParamsValid(&CDATA, 1, sIRC._KILL))
            {
                case E_OK:
                    Kill_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"kill <Player> <Reason> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "LEVEL")
        {
            CDATA.PCOUNT = 2;
            switch(ParamsValid(&CDATA, 2, sIRC.CLEVEL))
            {
                case E_OK:
                    Level_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"level <Player> <NewLevel> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "LOOKUP")
        {
            CDATA.PCOUNT = 2;
            switch(ParamsValid(&CDATA, 2, sIRC.CLOOKUP))
            {
                case E_OK:
                    Lookup_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"lookup <acct/char/creature/faction/go/item/quest/skill/spell/tele> <ID/Name> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "MONEY")
        {
            CDATA.PCOUNT = 2;
            switch(ParamsValid(&CDATA, 2, sIRC.CMONEY))
            {
                case E_OK:
                    Money_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"money <Player> <(-)Money> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "MUTE")
        {
            switch(ParamsValid(&CDATA, 2, sIRC.CMUTE))
            {
                case E_OK:
                    Mute_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"mute <Player> <release/TimeInMins> <Reason> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "ONLINE")
        {
            switch(ParamsValid(&CDATA, 0, sIRC.CONLINE))
            {
                case E_OK:
                    Online_Players(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"online )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "PM")
        {
            switch(ParamsValid(&CDATA, 2, sIRC.CPM))
            {
                case E_OK:
                    PM_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"pm <Player> <Message> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "RELOAD")
        {
            switch(ParamsValid(&CDATA, 0, sIRC.CRESTART))
            {
                case E_OK:
                    sIRC.Send_IRC_Channels("Reloading MangChat Config Options. (Command Disabled)");
                    //sIRC.LoadConfig();
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "RESTART")
        {
            switch(ParamsValid(&CDATA, 0, sIRC.CRESTART))
            {
                case E_OK:
                    sIRC.Send_IRC_Channels(sIRC.RstMsg);
                    sIRC.ResetIRC();
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "REVIVE")
        {
            CDATA.PCOUNT = 2;
            switch(ParamsValid(&CDATA, 1, sIRC.CREVIVE))
            {
                case E_OK:
                    Revive_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"revive <Player> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "SAVEALL")
        {
            switch(ParamsValid(&CDATA, 0, sIRC.CSAVEALL))
            {
                case E_OK:
                    Saveall_Player(&CDATA);
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "SHUTDOWN")
        {
            switch(ParamsValid(&CDATA, 1, sIRC.CSHUTDOWN))
            {
                case E_OK:
                    Shutdown_Mangos(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"shutdown <TimeInSeconds> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "SPELL")
        {
            switch(ParamsValid(&CDATA, 2, sIRC.CSPELL))
            {
                case E_OK:
                    Spell_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"spell <Player> <Cast/Learn/UnLearn> <SpellID> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "SYSMSG")
        {
            CDATA.PCOUNT = 2;
            switch(ParamsValid(&CDATA, 2, sIRC.CSYSMSG))
            {
                case E_OK:
                    Sysmsg_Server(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"sysmsg <a/e/n/add/del/list> <Message> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "TELE")
        {
            switch(ParamsValid(&CDATA, 2, sIRC.CTELE))
            {
                case E_OK:
                    Tele_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"tele <Player> <l/c/r/to> <Loc.Name/MAPID X Y Z/Recall/Player> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "TOP")
        {
            CDATA.PCOUNT = 1;
            switch(ParamsValid(&CDATA, 1, sIRC.CTOP))
            {
                case E_OK:
                    Top_Player(&CDATA);
                    break;
                case E_SIZE:
                    sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Syntax Error! ( "+sIRC._cmd_prefx+"top <accttime/chartime/money> <limit> )", true, "ERROR");
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        else if(CDATA.CMD == "WHO")
        {
            switch(ParamsValid(&CDATA, 0, sIRC.CWHO))
            {
                case E_OK:
                    Who_Logged(&CDATA);
                    break;
                case E_AUTH:
                    AuthValid = false;
                    break;
            }
            cValid = true;
        }
        if(!AuthValid && IsLoggedIn(USER))
            sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Access Denied! Your Security Level Is Too Low To Use This Command!", true, "ERROR");
        if(cValid == false && (sIRC.BOTMASK & 4) != 0)
            sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : Unknown Command!", true, "ERROR");
        if(cValid && dontlog)
        {
            sIRC.iLog.WriteLog(" %s : [ %s(%d) ] Used Command: [ %s ] With Parameters: [ %s ]", sIRC.iLog.GetLogDateTimeStr().c_str(), CDATA.USER.c_str(), GetLevel(USER), CDATA.CMD.c_str(), CDATA.PARAMS.c_str());
        }
        return cValid;
    }
    return false;
}

bool IRCCmd::CanUse(std::string USER, int nLevel)
{
    if(IsLoggedIn(USER))
    {
        if(GetLevel(USER) >= nLevel)
            return true;
        else
            return false;
    }
    else if(nLevel == 0)
    {
        return true;
    }
    else
        sIRC.Send_IRC_Channel(USER, "\0034[ERROR] : You Are Not Logged In!", true, "ERROR");
    return false;
}

std::string IRCCmd::ChanOrPM(_CDATA *CD)
{
    if(CD->FROM == sIRC._Nick)
        return CD->USER;
    else
        return CD->FROM;
}

Player *IRCCmd::GetPlayer(std::string WHO)
{
    normalizePlayerName(WHO);
    return ObjectAccessor::Instance().FindPlayerByName(WHO.c_str());
}

_client *IRCCmd::GetClient(std::string cname)
{
    for(std::list<_client*>::iterator i=_CLIENTS.begin(); i!=_CLIENTS.end();i++)
    {
        if((*i)->Name == cname)
            return (*i);
    }
    return (NULL);
}

bool IRCCmd::IsLoggedIn(std::string USER)
{
    for(std::list<_client*>::iterator i=_CLIENTS.begin(); i!=_CLIENTS.end();i++)
    {
        if((*i)->Name == USER)
            return true;
    }
    return false;
}

bool IRCCmd::AcctIsLoggedIn(std::string USER)
{
    for(std::list<_client*>::iterator i=_CLIENTS.begin(); i!=_CLIENTS.end();i++)
    {
        if(MakeUpper((*i)->UName) == MakeUpper(USER))
            return true;
    }
    return false;
}

std::string IRCCmd::AcctIsBanned(std::string ACCT)
{
    uint32 acctid = objmgr.GetAccountByAccountName(ACCT);
    std::string banned = "NOTBANNED";
    QueryResult *result = loginDatabase.PQuery("SELECT banreason FROM ip_banned WHERE ip=(SELECT last_ip FROM account WHERE id = '%i')", acctid);
    if(result)
    {
        banned = (*result)[0].GetCppString();
        delete result;  
        return "IP Banned. Reason:" + banned;   
    }
    QueryResult *result2 = loginDatabase.PQuery("SELECT banreason FROM account_banned WHERE id='%i'", acctid);  
    if(result2)
    {
        banned = (*result2)[0].GetCppString();
        delete result2; 
        return "Account Banned. Reason:" + banned;
    }
    return banned;
}

int IRCCmd::GetLevel(std::string sName)
{
    for(std::list<_client*>::iterator i=_CLIENTS.begin(); i!=_CLIENTS.end();i++)
    {
        if((*i)->Name == sName)
            return (*i)->GMLevel;
    }
    return 0;
}

int IRCCmd::AcctLevel(std::string plnme)
{
    uint64 guid = objmgr.GetPlayerGUIDByName(plnme);
    uint32 account_id = 0;
    uint32 security = 0;
    account_id = objmgr.GetPlayerAccountIdByGUID(guid);
    security = objmgr.GetSecurityByAccount(account_id);
    return security;
}

std::string IRCCmd::GetAccName(std::string sName)
{
    for(std::list<_client*>::iterator i=_CLIENTS.begin(); i!=_CLIENTS.end();i++)
    {
        if((*i)->Name == sName)
            return (*i)->UName;
    }
    return "";
}

std::string IRCCmd::GetNameFromAcct(std::string sName)
{
    for(std::list<_client*>::iterator i=_CLIENTS.begin(); i!=_CLIENTS.end();i++)
    {
        if((*i)->UName == sName)
            return (*i)->Name;
    }
    return "";
}

int IRCCmd::GetAcctIDFromName(std::string sName)
{
    for(std::list<_client*>::iterator i=_CLIENTS.begin(); i!=_CLIENTS.end();i++)
    {
        if((*i)->Name == sName)
        {
            uint32 acct_id = 0;
            acct_id = objmgr.GetAccountByAccountName((*i)->UName.c_str());
            return acct_id;
        }
    }
    return 0;
}

std::string IRCCmd::GetAcctNameFromID(uint32 acctid)
{
    QueryResult *result = loginDatabase.PQuery("SELECT username FROM account WHERE id = '%d'", acctid);
    if(result)
    {
        std::string name = (*result)[0].GetCppString();
        delete result;
        return name;
    }

    return "";
}

std::string IRCCmd::GetIPFromPlayer(std::string player)
{
    QueryResult *result = CharacterDatabase.PQuery("SELECT account FROM characters WHERE name = '%s'", player.c_str());
    if(result)
    {
        std::string acctid = (*result)[0].GetCppString();
        delete result;
        QueryResult *result2 = loginDatabase.PQuery("SELECT last_ip FROM account WHERE id = '%s'", acctid.c_str());
        if(result2)
        {
            std::string ip = (*result2)[0].GetCppString();
            delete result2;
            return ip;
        }       
    }

    return "";
}

std::string IRCCmd::SecToDay(std::string secons)
{
    unsigned int seconds = atoi(secons.c_str());
    unsigned int days = seconds / 86400;
    unsigned int hours = seconds / 3600 % 24;
    unsigned int mins = seconds / 60 % 60;
    char tottime[1000];
    sprintf(tottime, "%iDays:%iHours:%iMinutes", days, hours, mins);

    return tottime;
}

bool IRCCmd::ValidParams(std::string PARAMS, int nCount)
{
    if(nCount == 1 && PARAMS.size() == 0)
        return false;
    int pcount = 0;
    size_t p = -1;
    for(int i = 0;i < nCount;i++)
    {
        p = PARAMS.find(" ", p + 1);
        if(p == -1)
            break;
        else
            pcount++;
    }
    nCount--;
    if(pcount >= nCount)
        return true;
    else
        return false;
}

std::string* IRCCmd::getArray(std::string PARAMS, int nCount)
{
    std::string *array = new std::string[nCount];
    if(PARAMS.size() > 0)
    {
        int pcnt = 0;
        size_t ps = 0;
        size_t pc = -1;
        for(int i = 0;i < nCount;i++)
        {
            pc = PARAMS.find(" ", pc + 1);
            if(i + 1 == nCount && nCount != 1)
            {
                if(ps > 0 && pc > 0)
                    array[i] = PARAMS.substr(ps, PARAMS.size() - ps);
            }
            else
                array[i] = PARAMS.substr(ps, pc - ps);
            ps = pc + 1;
        }
    }
    return array;
}

std::string IRCCmd::MakeMsg(const char *sLine, ... )
{
    va_list ap;
    char tmpoutp[1024];
    va_start(ap, sLine);
    vsnprintf(tmpoutp, 1024, sLine, ap );
    va_end(ap);
    std::string outp = tmpoutp;
    return outp;
}

void IRCClient::AHFunc(uint64 itmid, std::string itmnme, std::string plname, uint32 faction)
{
    IRCCmd Command;
    Player* plr = Command.GetPlayer(plname);
    if(plr)
    {
        std::string itemname = itmnme;

        char  temp [7];
        sprintf(temp, "%u", itmid);
        std::string itemid = temp;

        std::string wowname = "";
        std::string ircname = "";
        switch (plr->GetTeam())
        {
            case 67:wowname="|cffff0000"+plname+"|r";ircname="\0034"+plname;break;      //horde
            case 469:wowname="|cff1589FF"+plname+"|r";ircname="\00312"+plname;break;    //alliance
        }
        
        std::string wowfact = "|cffFF8040[Auction House]:|r";
        std::string ircfact = "\00304,08\037/!\\\037\017\00307 Auction House \00304,08\037/!\\\037\017";
        switch(faction)
        {
            //neutral
            case 7:wowfact="|cffff8040[Neutral Auction House]:|r";ircfact="\00304,08\037/!\\\037\017\00307 Neutral Auction House \00304,08\037/!\\\037\017";break;
            //horde
            case 6:wowfact="|cffff0000[Horde Auction House]:|r";ircfact="\00304,08\037/!\\\037\017\00304 Horde Auction House \00304,08\037/!\\\037\017";break;
            //alliance
            case 2:wowfact="|cff1589FF[Alliance Auction House]:|r";ircfact="\00304,08\037/!\\\037\017\00312 Alliance Auction House \00304,08\037/!\\\037\017";break;    
        }
        std::string wowstr = Command.MakeMsg("%s A New Item Has Been Added |cffffffff|Hitem:%s:0:0:0:0:0:0:0|h[%s]|h|r. By: %s",wowfact.c_str(), itemid.c_str(), itemname.c_str(), wowname.c_str());
        std::string ircstr = Command.MakeMsg("%s A New Item Has Been Added [%s]. By: %s", ircfact.c_str(), itemname.c_str(), ircname.c_str());
        
        sIRC.Send_WoW_Channel(sIRC._wow_chan[sIRC.Status].c_str(), wowstr.c_str());
        sIRC.Send_IRC_Channel(sIRC._irc_chan[sIRC.Status].c_str(), ircstr.c_str());
    }
}
