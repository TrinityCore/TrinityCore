/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/** \file
    \ingroup Trinityd
*/

#include "Common.h"
#include "Config/ConfigEnv.h"
#include "Database/DatabaseEnv.h"
#include "AccountMgr.h"
#include "Log.h"
#include "RASocket.h"
#include "Util.h"
#include "World.h"

/// \todo Make this thread safe if in the future 2 admins should be able to log at the same time.
SOCKET r;

#define dropclient {Sendf("I'm busy right now, come back later."); \
        SetCloseAndDelete(); \
        return; \
    }

uint32 iSession=0;                                          ///< Session number (incremented each time a new connection is made)
unsigned int iUsers=0;                                      ///< Number of active administrators

typedef int(* pPrintf)(const char*,...);

void ParseCommand(CliCommandHolder::Print*, char*command);

/// RASocket constructor
RASocket::RASocket(ISocketHandler &h): TcpSocket(h)
{

    ///- Increment the session number
    iSess =iSession++ ;

    ///- Get the config parameters
    bSecure = sConfig.GetBoolDefault( "RA.Secure", true );
    iMinLevel = sConfig.GetIntDefault( "RA.MinLevel", 3 );

    ///- Initialize buffer and data
    iInputLength=0;
    buff=new char[RA_BUFF_SIZE];
    stage=NONE;
}

/// RASocket destructor
RASocket::~RASocket()
{
    ///- Delete buffer and decrease active admins count
    delete [] buff;

    sLog.outRemote("Connection was closed.\n");

    if(stage==OK)
        iUsers--;
}

/// Accept an incoming connection
void RASocket::OnAccept()
{
    std::string ss=GetRemoteAddress();
    sLog.outRemote("Incoming connection from %s.\n",ss.c_str());
    ///- If there is already an active admin, drop the connection
    if(iUsers)
        dropclient

        ///- Else print Motd
            Sendf("%s\r\n",sWorld.GetMotd());
}

/// Read data from the network
void RASocket::OnRead()
{
    ///- Read data and check input length
    TcpSocket::OnRead();

    unsigned int sz=ibuf.GetLength();
    if(iInputLength+sz>=RA_BUFF_SIZE)
    {
        sLog.outRemote("Input buffer overflow, possible DOS attack.\n");
        SetCloseAndDelete();
        return;
    }

    ///- If there is already an active admin (other than you), drop the connection
    if(stage!=OK && iUsers)
        dropclient

            char *inp = new char [sz+1];
    ibuf.Read(inp,sz);

    /// \todo Can somebody explain this 'Linux bugfix'?
    if(stage==NONE)
        if(sz>4)                                            //linux remote telnet
            if(memcmp(inp ,"USER ",5))
            {
                delete [] inp;return;
                printf("lin bugfix");
            }                                               //linux bugfix

    ///- Discard data after line break or line feed
    bool gotenter=false;
    unsigned int y=0;
    for (; y<sz; y++)
        if(inp[y]=='\r'||inp[y]=='\n')
    {
        gotenter=true;
        break;
    }

    //No buffer overflow (checked above)
    memcpy(&buff[iInputLength],inp,y);
    iInputLength+=y;
    delete [] inp;
    if(gotenter)
    {

        buff[iInputLength]=0;
        iInputLength=0;
        switch(stage)
        {
            /// <ul> <li> If the input is 'USER <username>'
            case NONE:
                if(!memcmp(buff,"USER ",5))                 //got "USER" cmd
                {
                    szLogin=&buff[5];

                    ///- Get the password from the account table
                    std::string login = szLogin;

                    ///- Convert Account name to Upper Format
                    AccountMgr::normalizeString(login);

                    ///- Escape the Login to allow quotes in names
                    loginDatabase.escape_string(login);

                    QueryResult* result = loginDatabase.PQuery("SELECT aa.gmlevel FROM account a LEFT JOIN account_access aa ON (a.id = aa.id) WHERE a.username = '%s'",login.c_str ());

                    ///- If the user is not found, deny access
                    if(!result)
                    {
                        Sendf("-No such user.\r\n");
                        sLog.outRemote("User %s does not exist.\n",szLogin.c_str());
                        if(bSecure)SetCloseAndDelete();
                    }
                    else
                    {
                        Field *fields = result->Fetch();

                        //szPass=fields[0].GetString();

                        ///- if gmlevel is too low, deny access
                        if(fields[0].GetUInt32()<iMinLevel)
                        {
                            Sendf("-Not enough privileges.\r\n");
                            sLog.outRemote("User %s has no privilege.\n",szLogin.c_str());
                            if(bSecure)SetCloseAndDelete();
                        }   else
                        {
                            stage=LG;
                        }
                        delete result;
                    }
                }
                break;
                ///<li> If the input is 'PASS <password>' (and the user already gave his username)
            case LG:
                if(!memcmp(buff,"PASS ",5))                 //got "PASS" cmd
                {                                           //login+pass ok
                    ///- If password is correct, increment the number of active administrators
                    std::string login = szLogin;
                    std::string pw = &buff[5];

                    AccountMgr::normalizeString(login);
                    AccountMgr::normalizeString(pw);
                    loginDatabase.escape_string(login);
                    loginDatabase.escape_string(pw);

                    QueryResult *check = loginDatabase.PQuery(
                        "SELECT 1 FROM account WHERE username = '%s' AND sha_pass_hash=SHA1(CONCAT('%s',':','%s'))",
                        login.c_str(), login.c_str(), pw.c_str());

                    if(check)
                    {
                        delete check;
                        r=GetSocket();
                        stage=OK;
                        ++iUsers;

                        Sendf("+Logged in.\r\n");
                        sLog.outRemote("User %s has logged in.\n",szLogin.c_str());
                        Sendf("TC>");
                    }
                    else
                    {
                        ///- Else deny access
                        Sendf("-Wrong pass.\r\n");
                        sLog.outRemote("User %s has failed to log in.\n",szLogin.c_str());
                        if(bSecure)SetCloseAndDelete();
                    }
                }
                break;
                ///<li> If user is logged, parse and execute the command
            case OK:
                if(strlen(buff))
                {
                    sLog.outRemote("Got '%s' cmd.\n",buff);
                    sWorld.QueueCliCommand(&RASocket::zprint , buff);
                }
                else
                    Sendf("TC>");
                break;
                ///</ul>
        };

    }
}

/// Output function
void RASocket::zprint( const char * szText )
{
    if( !szText )
        return;

    #ifdef RA_CRYPT

    char *megabuffer=strdup(szText);
    unsigned int sz=strlen(megabuffer);
    Encrypt(megabuffer,sz);
    send(r,megabuffer,sz,0);
    delete [] megabuffer;

    #else

    unsigned int sz=strlen(szText);
    send(r,szText,sz,0);

    #endif
}
