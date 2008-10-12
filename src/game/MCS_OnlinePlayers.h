#ifndef _IRC_CLIENT_ONLINE
#define _IRC_CLIENT_ONLINE

#include "IRCClient.h"
#include "IRCCmd.h"

// the reason to run this command multithreaded
// is to be able to "spread" the output over irc
// for servers with high player count
// in order not to freeze the mangchat core with sleep
// a new thread is spawned it will output the player data
// evry "10 players" and pauzes to not spam irc
// in addition the command is locked so i cannot be used
// while active.

class mcs_OnlinePlayers : public ZThread::Runnable
{
    public:
        mcs_OnlinePlayers();
        mcs_OnlinePlayers(_CDATA *_CD);
        ~mcs_OnlinePlayers();
        void run();
    public:
        _CDATA *CD;
};

#endif
