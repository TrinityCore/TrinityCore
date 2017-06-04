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

#include "IRCClient.h"
#include "IRCCmd.h"
#include "IRCFunc.h"
#include "Language.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "WorldPacket.h"
#include "ChannelMgr.h"
#include "Config.h"
#include "Channel.h"
#include "World.h"

IRCCmd Command;
void IRCClient::Handle_IRC(std::string sData)
{
    // If first 5 chars are ERROR then something is wrong
    // either link is being closed, nickserv ghost command, etc...
    if (sData.substr(0, 5) == "ERROR")
    {
        Disconnect();
        return;
    }
    if (sData.substr(0, 4) == "PING")
    {
        // if the first 4 characters contain PING
        // the server is checking if we are still alive
        // sen back PONG back plus whatever the server send with it
        SendIRC("PONG " + sData.substr(4, sData.size() - 4));
    }
    else
    {
        // if the first line contains : its an irc message
        // such as private messages channel join etc.
        if (sData.substr(0, 1) == ":")
        {
            // find the spaces in the receieved line
            size_t p1 = sData.find(" ");
            size_t p2 = sData.find(" ", p1 + 1);
            // because the irc protocol uses simple spaces
            // to seperate data we can easy pick them out
            // since we know the position of the spaces
            std::string USR = sData.substr(1, p1 - 1);
            std::string CMD = sData.substr(p1 + 1, p2 - p1 - 1);
            // trasform the commands to lowercase to make sure they always match
            std::transform(CMD.begin(), CMD.end(), CMD.begin(), towlower);
            // Extract the username from the first part
            std::string szUser = GetUser(USR);
            // if we receieved the internet connect code
            // we know for sure that were in and we can
            // authenticate ourself.
            if (CMD == sIRC->_ICC)
            {
                // _Auth is defined in trinitycore.conf (irc.auth)
                // 0 do not authenticate
                // 1 use nickserv
                // 2 use quakenet
                // aditionally you can provide you own authentication method here
                switch(sIRC->_Auth)
                {
                    case 1:
                        SendIRC("PRIVMSG nickserv :IDENTIFY " + sIRC->_Pass);
                        break;
                    case 2:
                        SendIRC("PRIVMSG nickserv :IDENTIFY " + sIRC->_Auth_Nick + " " + sIRC->_Pass);
                        break;
                    case 3:
                        SendIRC("PRIVMSG Q@CServe.quakenet.org :AUTH " + sIRC->_Nick + " " + sIRC->_Pass);
                        break;
                    case 4:
                        SendIRC("PRIVMSG Q@CServe.quakenet.org :AUTH " + sIRC->_Auth_Nick + " " + sIRC->_Pass);
                        break;
                }
                // if we join a default channel leave this now.
                if (sIRC->_ldefc==1)
                    SendIRC("PART #" + sIRC->_defchan);
                // Loop thru the channel array and send a command to join them on IRC.
                for (int i=1;i < sIRC->_chan_count + 1;i++)
                {
                        if (sIRC->_irc_pass[i].size() > 0)
                        {
                            //SendIRC("JOIN #" + sIRC->_irc_chan[i] + " " + sIRC->_irc_pass[i]);
                            if(!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
                            {
                                bool split = false;
                                for(uint32 j=0;j<sIRC->splitChannels.size();++j)
                                {
                                    if(sIRC->_irc_chan[i] == sIRC->splitChannels[j].channel)
                                    {
                                        SendIRC("JOIN #" + sIRC->_irc_chan[i] + "-alliance " + sIRC->_irc_pass[i]);
                                        SendIRC("JOIN #" + sIRC->_irc_chan[i] + "-horde " + sIRC->_irc_pass[i]);
                                        split = true;
                                    }
                                }
                                if(!split)
                                    SendIRC("JOIN #"+sIRC->_irc_chan[i]+" "+sIRC->_irc_pass[i]);
                            }
                            else
                                SendIRC("JOIN #" + sIRC->_irc_chan[i] + " " + sIRC->_irc_pass[i]);
                        }
                        else
                        {
                            if(!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
                            {
                                bool split = false;
                                for(uint32 j=0;j<sIRC->splitChannels.size();++j)
                                {
                                    if(sIRC->_irc_chan[i] == sIRC->splitChannels[j].channel)
                                    {
                                        SendIRC("JOIN #" + sIRC->_irc_chan[i] + "-alliance");
                                        SendIRC("JOIN #" + sIRC->_irc_chan[i] + "-horde");
                                        split = true;
                                    }
                                }
                                if(!split)
                                    SendIRC("JOIN #" + sIRC->_irc_chan[i]);
                            }
                            else
                                SendIRC("JOIN #" + sIRC->_irc_chan[i]);
                        }
                }
                // See if there's a log channel available, if so: join it.
                if (sIRC->logchan.size() > 0)
                {
                    if (sIRC->logchanpw.size() > 0)
                        SendIRC("JOIN #" + sIRC->logchan + " " + sIRC->logchanpw);
                    else
                        SendIRC("JOIN #" + sIRC->logchan);
                }
                // See if there's a Status channel available, if so: join it.
                if (sIRC->Status.size() > 0)
                {
                    if (sIRC->Statuspw.size() > 0)
                        SendIRC("JOIN #" + sIRC->Status + " " + sIRC->Statuspw);
                    else
                        SendIRC("JOIN #" + sIRC->Status);
                }
                // See if there's a Ticket channel available, if so: join it.
                if (sIRC->ticann.size() > 0)
                {
                    if (sIRC->ticannpw.size() > 0)
                        SendIRC("JOIN #" + sIRC->ticann + " " + sIRC->ticannpw);
                    else
                        SendIRC("JOIN #" + sIRC->ticann);
                }
                // See if there's an Announce channel available, if so: join it.
                if (sIRC->anchn.size() > 0)
                {
                    if (sIRC->anchnpw.size() > 0)
                        SendIRC("JOIN #" + sIRC->anchn + " " + sIRC->anchnpw);
                    else
                        SendIRC("JOIN #" + sIRC->anchn);
                }
            }
            // someone joined the channel this could be the bot or another user
            if (CMD == "join")
            {
                size_t p = sData.find(":", p1);
                std::string CHAN = sData.substr(p + 1, sData.size() - p - 2);
                // if the user is us it means we join the channel
                if ((szUser == sIRC->_Nick))
                {
                    // its us that joined the channel
                    Send_IRC_Channel(CHAN, MakeMsg(MakeMsg(sIRC->JoinMsg, "$Ver", sIRC->_Mver.c_str()), "$Trigger", sIRC->_cmd_prefx.c_str()), true);
                }
                else
                {
                    // if the user is not us its someone else that joins
                    // so we construct a message and send this to the clients.
                    // TriniChat now uses Send_WoW_Channel to send to the client
                    // this makes TriniChat handle the packets instead of previously the world.
                    if ((sIRC->BOTMASK & 2) != 0)
                        Send_WoW_Channel(GetWoWChannel(CHAN).c_str(), IRCcol2WoW(MakeMsg(MakeMsg(GetChatLine(JOIN_IRC), "$Name", szUser), "$Channel", GetWoWChannel(CHAN))));
                }
            }
            // someone on irc left or quit the channel
            if (CMD == "part" || CMD == "quit")
            {
                size_t p3 = sData.find(" ", p2 + 1);
                std::string CHAN = sData.substr(p2 + 1, p3 - p2 - 1);
                // Logout IRC Nick From TriniChat If User Leaves Or Quits IRC.
                if (Command.IsLoggedIn(szUser))
                {
                    _CDATA CDATA;
                    CDATA.USER      = szUser;
                    Command.Handle_Logout(&CDATA);
                }
                // Construct a message and inform the clients on the same channel.
                if ((sIRC->BOTMASK & 2) != 0)
                    Send_WoW_Channel(GetWoWChannel(CHAN).c_str(), IRCcol2WoW(MakeMsg(MakeMsg(GetChatLine(LEAVE_IRC), "$Name", szUser), "$Channel", GetWoWChannel(CHAN))));
            }
            // someone changed their nick
            if (CMD == "nick" && (sIRC->BOTMASK & 128) != 0)
            {
                MakeMsg(MakeMsg(GetChatLine(CHANGE_NICK), "$Name", szUser), "$NewName", sData.substr(sData.find(":", p2) + 1));
                // If the user is logged in and changes their nick
                // then we want to either log them out or update
                // their nick in the bot. I chose to update the bots user list.
                if (Command.IsLoggedIn(szUser))
                {
                    std::string NewNick = sData.substr(sData.find(":", p2) + 1);
                    // On freenode I noticed the server sends an extra character
                    // at the end of the string, so we need to erase the last
                    // character of the string. if you have a problem with getting
                    // the last letter of your nick erased, then remove the - 1.
                    NewNick.erase(NewNick.length() - 1, 1);

                    for (std::list<_client*>::iterator i=Command._CLIENTS.begin(); i!=Command._CLIENTS.end();i++)
                    {
                        if ((*i)->Name == szUser)
                        {
                            (*i)->Name     = NewNick;
                            sIRC->Send_IRC_Channel(NewNick.c_str(), "I Noticed You Changed Your Nick, I Have Updated My Internal Database Accordingly.", true, "NOTICE");

                            // Figure why not output to the logfile, makes tracing problems easier.
                            sIRC->iLog.WriteLog(" %s : %s Changed Nick To: %s", sIRC->iLog.GetLogDateTimeStr().c_str(), szUser.c_str(), NewNick.c_str());
                        }
                    }
                }

            }
            // someone was kicked from irc
            if (CMD == "kick")
            {
                // extract the details
                size_t p3 = sData.find(" ", p2 + 1);
                size_t p4 = sData.find(" ", p3 + 1);
                std::string CHAN = sData.substr(p2 + 1, p3 - p2 - 1);
                std::string WHO = sData.substr(p3 + 1, p4 - p3 - 1);
                std::string BY = sData.substr(p4 + 1, sData.size() - p4 - 1);
                // if the one kicked was us
                if (WHO == sIRC->_Nick)
                {
                    // and autojoin is enabled
                    // return to the channel
                    if (sIRC->_autojoinkick == 1)
                    {
                        SendIRC("JOIN " + CHAN);
                        Send_IRC_Channel(CHAN, sIRC->kikmsg, true);
                    }
                }
                else
                {
                    // if it is not us who was kicked we need to inform the clients someone
                    // was removed from the channel
                    // construct a message and send it to the players.
                    Send_WoW_Channel(GetWoWChannel(CHAN).c_str(), "<IRC>[" + WHO + "]: Was Kicked From " + CHAN + " By: " + szUser);
                }
            }
            // a private chat message was receieved.
            if (CMD == "privmsg" || CMD == "notice")
            {
                // extract the values
                size_t p = sData.find(" ", p2 + 1);
                std::string FROM = sData.substr(p2 + 1, p - p2 - 1);
                std::string CHAT = sData.substr(p + 2, sData.size() - p - 3);
                // if this is our username it means we recieved a PM
                if (FROM == sIRC->_Nick)
                {
                    if (CHAT.find("\001VERSION\001") < CHAT.size())
                    {
                        Send_IRC_Channel(szUser, MakeMsg("\001VERSION TriniChat %s ?2008-2009 |Death|, Cybrax, Machiavelli\001", "%s" , sIRC->_Mver.c_str()), true, "PRIVMSG");
                    }
                    // a pm is required for certain commands
                    // such as login. to validate the command
                    // we send it to the command class wich handles
                    // evrything else.
                    Command.IsValid(szUser, FROM, CHAT, CMD);
                }
                else
                {
                    // if our name is not in it, it means we receieved chat on one of the channels
                    // magchat is in. the first thing we do is check if it is a command or not
                    if (!Command.IsValid(szUser, FROM, CHAT, CMD))
                    {
                        if(Command.IsLoggedIn(szUser))
                        {
                            std::string newMsg = "", userSaved = szUser;
                            if(Command.GMChat(szUser))
                            {
                                newMsg += "|TInterface\\ChatFrame\\UI-ChatIcon-Blizz:12:20:0:0:32:16:4:28:0:16|t ";
                                newMsg += szUser;
                                szUser = newMsg;
                            }
                            uint32 toTeam = 0;
                            std::string fixStaffChan = "#"+sIRC->_staffChan;
                            if(FROM[FROM.length()-9] == '-')
                            {
                                uint32 removeAlliance = FROM.length()-9;
                                FROM.erase(removeAlliance, FROM.length()-removeAlliance);
                                toTeam = ALLIANCE;
                            }
                            else if(FROM[FROM.length()-6] == '-')
                            {
                                uint32 removeHorde = FROM.length()-6;
                                FROM.erase(removeHorde, FROM.length()-removeHorde);
                                toTeam = HORDE;
                            }
                            bool ignored = false;
                            switch(sIRC->_staffLink)
                            {
                                case 1:
                                    if(fixStaffChan == FROM)
                                    {
                                        for(uint8 i = 0;i<MAX_CONF_BOTS; i++)
                                        {
                                            if(sIRC->_ignore_bots[i] != "")
                                            {
                                                if(Command.MakeUpper(sIRC->_ignore_bots[i]) == Command.MakeUpper(userSaved))
                                                    ignored = true;
                                            }
                                        }
                                        if(!ignored)
                                        {
                                            //setup gm chat
                                            sWorld->SendGMText(LANG_GM_ANNOUNCE_COLOR, szUser.c_str(), CHAT.c_str());
                                        }
                                    }
                                    else
                                    {
                                        for(uint8 i = 0;i<MAX_CONF_BOTS; i++)
                                        {
                                            if(sIRC->_ignore_bots[i] != "")
                                            {
                                                if(Command.MakeUpper(sIRC->_ignore_bots[i]) == Command.MakeUpper(userSaved))
                                                    ignored = true;
                                            }
                                        }
                                        if(!ignored)
                                        {
                                            Send_WoW_Channel(GetWoWChannel(FROM).c_str(), IRCcol2WoW(MakeMsg(MakeMsg(GetChatLine(IRC_WOW), "$Name", szUser), "$Msg", CHAT)), toTeam);
                                        }
                                    }
                                    break;
                                case 0:
                                    Send_WoW_Channel(GetWoWChannel(FROM).c_str(), IRCcol2WoW(MakeMsg(MakeMsg(GetChatLine(IRC_WOW), "$Name", szUser), "$Msg", CHAT)), toTeam);
                                    break;
                            }
                        }
                        else
                        {
                            // warn only in case of chat channels, not staff or system ones.
                            // TODO: find a better way for this
                            std::string fixStaffChan = "#" + sIRC->_staffChan;
                            std::string statusChan = "#" + sIRC->Status;
                            std::string announceChan = "#" + sIRC->anchn;
                            std::string ticketChan = "#" + sIRC->ticann;
                            std::string logChan = "#" + sIRC->logchan;
                            if (FROM != fixStaffChan && FROM != statusChan && FROM != announceChan && FROM != ticketChan && FROM != logChan)
                                sIRC->Send_IRC_Channel(szUser.c_str(), "You are not logged in.Your message won't be sent to the ingame channel until you login.", true, "NOTICE");
                        }
                    }
                    // if we indeed receieved a command we do not want to display this to the players
                    // so only incanse the isvalid command returns false it will be sent to all player.
                    // the isvalid function will automaitcly process the command on true.
                }
            }
            if (CMD == "mode")
            {
                // extract the mode details
                size_t p3 = sData.find(" ", p2 + 1);
                size_t p4 = sData.find(" ", p3 + 1);
                size_t p5 = sData.find(" ", p4 + 1);
                std::string CHAN = sData.substr(p2 + 1, p3 - p2 - 1);
                std::string MODE = sData.substr(p3 + 1, p4 - p3 - 1);
                std::string NICK = sData.substr(p4 + 1, p5 - p4 - 1);
                _AmiOp = false;
                //A mode was changed on us
                if (NICK.c_str() == sIRC->_Nick)
                    _AmiOp = true;

            }
        }
    }
}

// This function is called in Channel.h
// based on nAction it will inform the people on
// irc when someone leaves one of the game channels.
// nAction is based on the struct CACTION
void IRCClient::Handle_WoW_Channel(std::string Channel, Player *plr, int nAction)
{
    // make sure that we are connected
    if (sIRC->Connected && (sIRC->BOTMASK & 1)!= 0)
    {
        if (Channel_Valid(Channel))
        {
            std::string GMRank = "";
            std::string pname = plr->GetName().c_str();
            bool DoGMAnnounce = false;
            if (plr->GetSession()->GetSecurity() > 0 && (sIRC->BOTMASK & 8)!= 0)
                DoGMAnnounce = true;
            if (plr->IsGameMaster() && (sIRC->BOTMASK & 16)!= 0)
                DoGMAnnounce = true;
            if (DoGMAnnounce)
            {
                switch(plr->GetSession()->GetSecurity())    //switch case to determine what rank the "gm" is
                {
                    case SEC_PLAYER: GMRank = ""; break;
                    case SEC_MODERATOR: GMRank = "\0037" + sIRC->ojGM1; break;
                    case SEC_GAMEMASTER: GMRank = "\0037" + sIRC->ojGM2; break;
                    case SEC_ADMINISTRATOR: GMRank = "\0037" + sIRC->ojGM3; break;
                    case SEC_CONSOLE: GMRank = "\0037" + sIRC->ojGM4; break;
                }
            }
            std::string ChatTag = "";
            switch (plr->GetTeam())
            {
                case 67:ChatTag.append("\0034");break;      //horde
                case 469:ChatTag.append("\00312");break;    //alliance
            }
            std::string query = "INSERT INTO `irc_inchan` VALUES (%d,'"+pname+"','"+Channel+"')";
            std::string lchan = "DELETE FROM `irc_inchan` WHERE `guid` = %d AND `channel` = '"+Channel+"'";
            switch(nAction)
            {
                case CHANNEL_JOIN:
                    Send_IRC_Channel(GetIRCChannel(Channel), MakeMsg(MakeMsg(MakeMsg(GetChatLine(JOIN_WOW), "$Name", ChatTag + plr->GetName().c_str()), "$Channel", Channel), "$GM", GMRank), false, "PRIVMSG", plr->GetTeam());
                    WorldDatabase.PExecute(lchan.c_str(), plr->GetGUID());
                    WorldDatabase.PExecute(query.c_str(), plr->GetGUID());
                    break;
                case CHANNEL_LEAVE:
                    Send_IRC_Channel(GetIRCChannel(Channel), MakeMsg(MakeMsg(MakeMsg(GetChatLine(LEAVE_WOW), "$Name", ChatTag + plr->GetName().c_str()), "$Channel", Channel), "$GM", GMRank), false, "PRIVMSG", plr->GetTeam());
                    WorldDatabase.PExecute(lchan.c_str(), plr->GetGUID());
                    break;
            }
        }
    }
}

// This function sends chat to a irc channel or user
// to prevent the # beeing appended to send a msg to a user
// set the NoPrefix to true
void IRCClient::Send_IRC_Channel(std::string sChannel, std::string sMsg, bool NoPrefix, std::string nType, uint32 team)
{
    if (!sWorld->getBoolConfig(CONFIG_ALLOW_TWO_SIDE_INTERACTION_CHANNEL))
    {
        bool split = false;
        for(uint32 i=0;i<splitChannels.size();++i)
        {
            if(splitChannels[i].channel == sChannel)
                split = true;
        }
        if(split)
        {
            switch(team)
            {
            case ALLIANCE: // 1
                sChannel += "-alliance";
                break;
            case HORDE: // 2
                sChannel += "-horde";
                break;
            default: // this is to keep system channels the same
                break;
            }
        }
    }
    std::string mType = "PRIVMSG";
    if (Command.MakeUpper(nType.c_str()) == "NOTICE")
        mType = "NOTICE";
    if (Command.MakeUpper(nType.c_str()) == "ERROR" && (sIRC->BOTMASK & 32)!= 0)
        mType = "NOTICE";
    if (sIRC->Connected)
    {
        if (NoPrefix)
            SendIRC(mType + " " + sChannel + " :" + sMsg);
        else
            SendIRC(mType + " #" + sChannel + " :" + sMsg);
    }
}

// This function sends a message to all irc channels
// that TriniChat has in its configuration
void IRCClient::Send_IRC_Channels(std::string sMsg)
{
    for (int i=1;i < sIRC->_chan_count + 1;i++)
        Send_IRC_Channel(sIRC->_irc_chan[i], sMsg);
}

// This function is called in ChatHandler.cpp, any channel chat from wow will come
// to this function, validates the channel and constructs a message that is send to IRC
void IRCClient::Send_WoW_IRC(Player *plr, std::string Channel, std::string Msg)
{
    // Check if the channel exist in our configuration
    if (Channel_Valid(Channel) && Msg.substr(0, 1) != ".")
    {
        Send_IRC_Channel(GetIRCChannel(Channel), MakeMsgP(WOW_IRC, Msg, plr), false, "PRIVMSG", plr->GetTeam());
    }
}

void IRCClient::Send_WoW_Player(std::string sPlayer, std::string sMsg)
{
    normalizePlayerName(sPlayer);
    if (Player* plr = sObjectAccessor->FindPlayerByName(sPlayer.c_str()))
        Send_WoW_Player(plr, sMsg);
}

void IRCClient::Send_WoW_Player(Player *plr, string sMsg)
{
    WorldPacket data(SMSG_MESSAGECHAT, 200);
    data << (uint8)CHAT_MSG_SYSTEM;
    data << (uint32)LANG_UNIVERSAL;
    data << (uint64)plr->GetGUID();
    data << (uint32)0;
    data << (uint64)plr->GetGUID();
    data << (uint32)(sMsg.length()+1);
    data << sMsg;
    data << (uint8)0;
    plr->GetSession()->SendPacket(&data);
}

// This function will construct and send a packet to all players
// on the given channel ingame. (previuosly found in world.cpp)
// it loops thru all sessions and checks if they are on the channel
// if so construct a packet and send it.
void IRCClient::Send_WoW_Channel(const char *channel, std::string chat, uint32 team)
{
    if (!(strlen(channel) > 0))
        return;

    #ifdef USE_UTF8
        std::string chat2 = chat;
        if (ConvertUTF8(chat2.c_str(), chat2))
            chat = chat2;
    #endif

    HashMapHolder<Player>::MapType const& m = sObjectAccessor->GetPlayers();
    for (HashMapHolder<Player>::MapType::const_iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        if (itr->second && itr->second->GetSession()->GetPlayer() && itr->second->GetSession()->GetPlayer()->IsInWorld() && itr->second->GetSession()->GetPlayer()->GetTeam() == team)
        {
            if (ChannelMgr* cMgr = ChannelMgr::forTeam(itr->second->GetSession()->GetPlayer()->GetTeam()))
            {
                if (cMgr->GetChannel(channel, itr->second->GetSession()->GetPlayer()))
                {
                    WorldPacket data;
                    data.Initialize(SMSG_MESSAGECHAT);
                    data << (uint8)CHAT_MSG_CHANNEL;
                    data << (uint32)LANG_UNIVERSAL;
                    data << (uint64)0;
                    data << (uint32)0;
                    data << channel;
                    data << (uint64)0;
                    data << (uint32) (strlen(chat.c_str()) + 1);
                    data << IRCcol2WoW(chat.c_str());
                    data << (uint8)0;
                    itr->second->GetSession()->SendPacket(&data);
                }
            }
        }
    }
}

void IRCClient::Send_WoW_System(std::string Message)
{
    HashMapHolder<Player>::MapType const& m = sObjectAccessor->GetPlayers();
    for (HashMapHolder<Player>::MapType::const_iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        if (itr->second && itr->second->GetSession()->GetPlayer() && itr->second->GetSession()->GetPlayer()->IsInWorld())
        {
            WorldPacket data;
            data.Initialize(CHAT_MSG_SYSTEM);
            data << (uint8)CHAT_MSG_SYSTEM;
            data << (uint32)LANG_UNIVERSAL;
            data << (uint64)0;
            data << (uint32)0;
            data << (uint64)0;
            data << (uint32) (strlen(Message.c_str()) + 1);
            data << Message.c_str();
            data << (uint8)0;
            itr->second->GetSession()->SendPacket(&data);
        }
    }
}
void IRCClient::ResetIRC()
{
    SendData("QUIT");
    Disconnect();
}

#define CHAT_INVITE_NOTICE 0x18

// this function should be called on player login Player::AddToWorld
void IRCClient::AutoJoinChannel(Player *plr)
{
    // this will work if at least 1 player is logged in regrdless if he is on the channel or not
    // the first person that login empty server is the one with bad luck and wont be invited,
    // if at least 1 player is online the player will be inited to the chanel

    std::string m_name = sIRC->ajchan;
    WorldPacket data;
    data.Initialize(SMSG_CHANNEL_NOTIFY, 1+m_name.size()+1);
    data << uint8(CHAT_INVITE_NOTICE);
    data << m_name.c_str();

    HashMapHolder<Player>::MapType const& m = sObjectAccessor->GetPlayers();
    for (HashMapHolder<Player>::MapType::const_iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        if (itr->second && itr->second->GetSession()->GetPlayer() && itr->second->GetSession()->GetPlayer()->IsInWorld())
        {
            data << uint64(itr->second->GetGUID());
            break;
        }
    }
    plr->GetSession()->SendPacket(&data);
}
