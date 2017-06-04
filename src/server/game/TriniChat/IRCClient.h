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

#ifndef _IRC_CLIENT_H
#define _IRC_CLIENT_H

#include <boost/asio/io_service.hpp>
#include <boost/asio/strand.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread.hpp>
#include "Player.h"
#include "IRCLog.h"
#include "IRCCmd.h"

using namespace std;
// The maximum ammount of channels used, must be >= config option
#define MAX_CONF_CHANNELS 10
#define MAX_CHAT_LINES 10
#define MAX_CONF_BOTS 10
// time we need to wait before we try another connecton attempt
// Default is 30 seconds
#define MAX_SCRIPT_INST 10
// CLINES is used for the default chatlines
// By using the GetChatLine function its easier and faster
// to receieve the line you need.
enum CLINES
{
    IRC_WOW = 0,
    WOW_IRC = 1,
    JOIN_WOW = 2,
    JOIN_IRC = 3,
    LEAVE_WOW = 4,
    LEAVE_IRC = 5,
    CHANGE_NICK = 6
};
struct Channels
{
    std::string channel;
    std::string password;
    bool split;
    int rank;
};
// CACTION is used by the Handle_WoW_Channel function
// this function is called in channel.h when a player
// joins or leave a channel inside the client.
enum CACTION
{
    CHANNEL_JOIN,
    CHANNEL_LEAVE,
};

enum script_Names
{
    MCS_Players_Online = 0,
};

void TrinityChatThread();

// IRCClient main class
class IRCClient
{

public:
    // IRCClient Constructor
    IRCClient();
    // IRCClient Destructor
    ~IRCClient();
    // ZThread Entry
    bool run();
    static IRCClient* instance(boost::asio::io_service* ioService = nullptr)
    {
        static IRCClient instance;

        if (ioService != nullptr)
        {
            instance._ioService = ioService;
            instance._strand = new boost::asio::strand(*ioService);
        }

        return &instance;
    }
    // Send a message to the specified IRC channel
    void Send_IRC_Channel(std::string sChannel, std::string sMsg, bool NoPrefix = false, std::string nType = "PRIVMSG", uint32 team = 0);
public:
    // AH Function
    void AHCancel(uint64 itmid, std::string itmnme, std::string plname, uint32 faction);
    //bool BeenToGMI(float posx, float posy, std::string player, std::string from);
    // IRCClient active
    bool Active;
    // check if we are running
    bool Running;
    // Connected to IRC
    bool Connected;
    // Socket indentifier
    int SOCKET;
    fd_set sfdset;
    // Send data to IRC, in addition the endline is added \n
    bool SendIRC(std::string data);
    // This function is called in ChatHandler.cpp and processes the chat from game to IRC
    void Send_WoW_IRC(Player *plr, std::string Channel, std::string Msg);
    // Sends a message to all players on the specified channel
    void Send_WoW_Channel(const char *channel, std::string chat, uint32 team = 0);
    // Send a system message to all players
    void Send_WoW_System(std::string Message);
    // Send a message to the specified IRC channel
    //void Send_IRC_Channel(std::string sChannel, std::string sMsg, bool NoPrefix = false, std::string nType = "PRIVMSG");
    // Sends a message to all IRC Channels
    void Send_IRC_Channels(std::string sMsg);
    std::string MakeMsg(std::string msg, std::string var, std::string val)
    {
        std::size_t start = msg.find(var);
        if (start != std::string::npos)
            msg.replace(start, var.length(), val);
        return msg;
    }
    void Send_WoW_Player(string sPlayer, string sMsg);
    void Send_WoW_Player(Player *plr, string sMsg);

    // This function is called in Channel.cpp and processes Join/leave messages
    void Handle_WoW_Channel(std::string Channel, Player *plr, int nAction);
    void ResetIRC();
public:
    void AutoJoinChannel(Player *plr);

public:
    bool Script_Lock[5];
    bool _AmiOp;

public:
    string _Mver;
    // IRC Server host
    string _Host;
    // IRC Server Port
    int _Port;
    // IRC Username
    string _User;
    // IRC Password
    string _Pass;
    // IRC Nickname
    string _Nick;
    //Password for in-game channel
    std::string _irc_pass[MAX_CONF_CHANNELS];
    // Authentication type
    int _Auth;
    string _Auth_Nick;
    // IRC Connect code
    string _ICC;
    // IRC Default channel
    string _defchan;
    // IRC Leave Default channel
    int _ldefc;
    // Wait Connect Time
    int _wct;
    // Check if staff chat is enabled
    int _staffLink;
    // IRC Default Staff channel
    string _staffChan;
    // String that contains bot names
    string _bot_names;
    // Number of bots to ignore
    string _ignore_bots[MAX_CONF_BOTS];
    // Ticket Channel
    string ticann;
    // Ticket Channel Password
    string ticannpw;
    // Status Channel
    string Status;
    // Status Channel Password
    string Statuspw;
    // Announce Channel
    string anchn;
    // Announce Channel Password
    string anchnpw;
    // Auto-announce timer
    int autoanc;
    // IRC Channel count
    int _chan_count;
    // IRC Channel list
    // Array to store our IRC channels
    // each element will corrospond
    // with _wow_chan array below.
    std::string _irc_chan[MAX_CONF_CHANNELS];
    // Game Channel list
    std::string _wow_chan[MAX_CONF_CHANNELS];
    // split chats
    std::array<Channels, MAX_CONF_CHANNELS> splitChannels;
    // AutoJoin Options
    int ajoin;
    string ajchan;
    // Online Command Max Results
    int onlrslt;
    // Channel OnJoin/Restart/Kick Messages
    string JoinMsg;
    string RstMsg;
    string kikmsg;
    // Misc Options
    string ojGM1;
    string ojGM2;
    string ojGM3;
    string ojGM4;
    string logfile;
    string logchan;
    string logchanpw;
    int logmask;
    int games;
    int gmlog;
    // IRC Commands Security Level
    int CACCT;
    int CBAN;
    int CCHAN;
    int CCHAR;
    int CFUN;
    int CHELP;
    int CINCHAN;
    int CINFO;
    int CITEM;
    int CJAIL;
    int CKICK;
    int _KILL;
    int CLEVEL;
    int CLOOKUP;
    int CMONEY;
    int CMUTE;
    int CONLINE;
    int CPM;
    int CRECONNECT;
    int CRELOAD;
    int CREVIVE;
    int CSAVEALL;
    int CSERVERCMD;
    int CSHUTDOWN;
    int CSPELL;
    int CSYSMSG;
    int CTELE;
    int CTOP;
    int CPLAYER;
    int CWHO;
    // BotMask
    int BOTMASK;
    // TicketMask
    int TICMASK;
    // Max connect attempt
    int _MCA;
    // Auto rejoin when kicked from irc
    int _autojoinkick;
    // IRC Command prefix
    string _cmd_prefx;
    int _op_gm;
    int _op_gm_lev;
    // Array that contains our chatlines from the conf file
    // To increase this value change the MAX_CHAT_LINE define above
    // Make sure the number of elements must match your items
    // (remeber this starts at 0 so 0..9 is 10 items)
    // and that you load the line in the LoadConfig function.
    string ILINES[MAX_CHAT_LINES];
    string GetChatLine(int nItem);

    int _Max_Script_Inst;
    // MAX_SCRIPT_INST

    IRCLog iLog;
    IRCClient* thread;

private:
    // Returns default chatline based on enum CLINES
    // Initialize socket library
    bool InitSock();
    // Connect to IRC Server
    bool Connect(const char *cHost, int nPort);
    // Login to IRC Server
    bool Login(std::string sNick, std::string sUser, std::string sPass);
    // Send raw data to IRC
    bool SendData(const char *data);
    // Disconnect from IRC and cleanup socket
    void Disconnect();
    // Processes the data receieved from IRC
    void Handle_IRC(std::string sData);
    // Receieves data from the socket.
    void SockRecv();

    // add boost ioservice
    boost::asio::io_service* _ioService;
    boost::asio::strand* _strand;
};

#define sIRC IRCClient::instance()
#endif
