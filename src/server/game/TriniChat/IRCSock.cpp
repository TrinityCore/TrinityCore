/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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
#define MAXDATASIZE 512
#include <fcntl.h>

#include <stdio.h>
#include <sys/types.h>


#define _UNICODE

#ifdef _MBCS
#undef _MBCS
#endif

bool IRCClient::InitSock()
{
    #ifdef _WIN32
    WSADATA wsaData;                                        //WSAData
    if (WSAStartup(MAKEWORD(2,0),&wsaData) != 0)
    {
        sLog->outError(LOG_FILTER_GENERAL, "IRC Error: Winsock Initialization Error");
        return false;
    }
    #endif
    if ((sIRC.SOCKET = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1)
    {
        sLog->outError(LOG_FILTER_GENERAL, "IRC Error: Socket Error");
        return false;
    }
    int on = 1;
    if (setsockopt (sIRC.SOCKET, SOL_SOCKET, SO_REUSEADDR, (const char*) &on, sizeof (on)) == -1)
    {
        sLog->outError(LOG_FILTER_GENERAL, "IRC Error: Invalid Socket");
        return false;
    }
    #ifdef _WIN32
    u_long iMode = 0;
    ioctlsocket(sIRC.SOCKET, FIONBIO, &iMode);
    #else
    fcntl(sIRC.SOCKET, F_SETFL, O_NONBLOCK);                // set to non-blocking
    fcntl(sIRC.SOCKET, F_SETFL, O_ASYNC);                   // set to asynchronous I/O
    #endif
    return true;
}

bool IRCClient::Connect(const char *cHost, int nPort)
{
    sIRC.Connected = false;
    struct hostent *he;
    if ((he=gethostbyname(cHost)) == NULL)
    {
        sLog->outError(LOG_FILTER_GENERAL, "IRCLIENT: Could not resolve host: %s", cHost);
        return false;
    }
    struct sockaddr_in their_addr;
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(nPort);
    their_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(their_addr.sin_zero), '\0', 8);
    if (::connect(sIRC.SOCKET, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1)
    {
        sLog->outError(LOG_FILTER_GENERAL, "IRCLIENT: Cannot connect to %s", cHost);
        return false;
    }
    //FD_ZERO(&sIRC.sfdset);
    //FD_SET(sIRC.SOCKET,&sIRC.sfdset);
    sIRC.Connected = true;
    return true;
}

bool IRCClient::Login(std::string sNick, std::string sUser, std::string sPass)
{
    char hostname[128];
    gethostname(hostname, sizeof(hostname));
    if (SendIRC("HELLO"))
        if (SendIRC("PASS " + sPass))
            if (SendIRC("NICK " + sNick))
                if (SendIRC("USER " + sUser + " " + (std::string)hostname + " TriniChat :TriniChat "+sIRC._Mver.c_str()))
                    return true;
    return false;
}

bool IRCClient::SendData(const char *data)
{
    if (sIRC.Connected)
    {
        if (send(sIRC.SOCKET, data, strlen(data), 0) == -1)
        {
            sLog->outError(LOG_FILTER_GENERAL, "IRC Error: Socket Receieve ** \n");
            //Disconnect();
            return false;
        }
    }
    return true;
}

bool IRCClient::SendIRC(std::string data)
{
    std::string RealData = data + "\n";
    return SendData(RealData.c_str());
}

void IRCClient::Disconnect()
{
    if (sIRC.SOCKET)
    {
        #ifdef _WIN32
        closesocket(sIRC.SOCKET);
        //WSACleanup();
        #else
        close(sIRC.SOCKET);
        #endif
    }
}

void IRCClient::SockRecv()
{
//    wchar_t bufferdata;

    char szBuffer[MAXDATASIZE];

    memset(szBuffer, 0, MAXDATASIZE);
    
    int nBytesRecv = ::recv(sIRC.SOCKET, szBuffer, MAXDATASIZE - 1, 0);
    if (nBytesRecv == -1)
    {
        sLog->outError(LOG_FILTER_GENERAL, "Connection lost.");
        sIRC.Connected = false;
    }
    else
    {
        if (-1 == nBytesRecv)
        {
            sLog->outError(LOG_FILTER_GENERAL, "Error occurred while receiving from socket.");
        }
        else
        {
            std::string reply;
            std::istringstream iss(szBuffer);
            while (getline(iss, reply))
            {
                Handle_IRC(reply);
            }
        }
    }
}