#ifndef SC_ACSCRIPTS_H
#define SC_ACSCRIPTS_H

#include "ScriptMgr.h"

class AnticheatScripts: public PlayerScript
{
    public:
        AnticheatScripts();

        void OnLogout(Player* player);
        void OnLogin(Player* player,bool);
};

#endif