/* 
 * File:   Hw2ChatHandler.h
 * Author: giuseppe
 *
 * Created on 13 agosto 2013, 10.24
 */

#ifndef HW2CHATHANDLER_H
#define	HW2CHATHANDLER_H

#include "Chat.h"

class Player;
class WorldSession;

class Hw2ChatHandler {
    public:
        explicit Hw2ChatHandler(WorldSession* session) { 
            handler=ChatHandler(session); 
        }
        
        bool runCommand(const char* script, const char* cmd, const char* args=NULL);
        bool AzerothQuest(Player *player);  //procedura personale
        bool AzerothSelezionaHandler(uint16 scelta, const char* args);
    protected:
        ChatHandler handler;
};

#endif	/* HW2CHATHANDLER_H */

