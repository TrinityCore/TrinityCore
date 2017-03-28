/*
 * Copyright (C) 2008-2017 Trinity <http://www.trinitycore.org/>
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

#ifndef _IRC_CMD_H
#define _IRC_CMD_H

#define MAX_CLIENTS 50
//include boost
#include "boost/thread.hpp"
#include "boost/date_time.hpp"
#include "Common.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "BattlegroundMgr.h"

struct ChannelUser
{
    int UserType;
    std::string Name;
    std::string UName;
    int UserLevel;
};

struct _client
{
    bool        LoggedIn;
    std::string Name;
    std::string UName;
    int         GMLevel;
    bool        GMChat;
};
struct _CDATA
{
    std::string CMD;
    std::string USER;
    std::string FROM;
    std::string PARAMS;
    std::string TYPE;
    int PCOUNT;
};
enum APVERR
{
    E_OK,
    E_SIZE,
    E_AUTH,
    E_IVALID,
};
enum ESOUNDS
{
    S_ENTERWORLD    = 602,
    S_QUESTFAILED   = 847,
    S_INVITE        = 880,
    S_LEVELUP       = 888,
    S_COINSOUND     = 895,
    S_WHISPER       = 3081,
    S_STEALTH       = 3325,
};
class IRCCmd
{
    public:
        IRCCmd();
        ~IRCCmd();

        void    Handle_Logout(_CDATA *CD);
        bool    IsLoggedIn(std::string USER);
        bool    IsValid(std::string USER, std::string FROM, std::string CHAT, std::string TYPE);
        bool    AcctIsLoggedIn(std::string USER);
        _client *GetClient(std::string cname);

    public:
        static std::string MakeMsg(const char *sLine, ...);
        static std::string ChanOrPM(_CDATA *CD);
        bool GMChat(std::string sName);
        int AcctLevel(std::string plnme);
        int GetLevel(std::string sName);
        std::string MakeUpper(std::string Channel);
        std::string  AcctIsBanned(std::string ACCT);
        std::list<_client*> _CLIENTS;
        Player* GetPlayer(std::string WHO);

    private:
        // TriniChat Commands
        void    Handle_Login(_CDATA *CD);
        void    Account_Player(_CDATA *CD);
        void    Ban_Player(_CDATA *CD);
        void    Chan_Control(_CDATA *CD);
        void    Char_Player(_CDATA *CD);
        void    Fun_Player(_CDATA *CD);
        void    Help_IRC(_CDATA *CD);
        void    Inchan_Server(_CDATA *CD);
        void    Info_Server(_CDATA *CD);
        void    Item_Player(_CDATA *CD);
        void    Jail_Player(_CDATA *CD);
        void    Kick_Player(_CDATA *CD);
        void    Kill_Player(_CDATA *CD);
        void    Player_Player(_CDATA *CD);
        void    Lookup_Player(_CDATA *CD);
        void    Level_Player(_CDATA *CD);
        void    Money_Player(_CDATA *CD);
        void    Mute_Player(_CDATA *CD);
        void    Online_Players(_CDATA *CD);
        void    PM_Player(_CDATA *CD);
        void    Restart_Trinity(_CDATA *CD);
        void    Revive_Player(_CDATA *CD);
        void    Saveall_Player(_CDATA *CD);
        void    Server(_CDATA *CD);
        void    Shutdown_Trinity(_CDATA *CD);
        void    Spell_Player(_CDATA *CD);
        void    Sysmsg_Server(_CDATA *CD);
        void    Tele_Player(_CDATA *CD);
        void    Top_Player(_CDATA *CD);
        void    Who_Logged(_CDATA *CD);
        bool    CanUse(std::string USER, int nLevel);
        bool    ValidParams(std::string PARAMS, int nCount = 1);
        bool    ParamsValid(_CDATA *CD, int pCnt);
        int     ParamsValid(_CDATA *CD, int pCnt, int rLev);
        std::string GetAccName(std::string sName);
        std::string GetNameFromAcct(std::string sName);
        std::string GetAcctNameFromID(uint32 acctid);
        std::string GetIPFromPlayer(std::string player);
        std::string SecToDay(std::string secons);
        int GetAcctIDFromName(std::string sName);
        std::string* getArray(std::string PARAMS, int nCount = 1);
};
inline void MakeLower(std::string& str)
{
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}
#endif
