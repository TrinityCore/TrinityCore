#ifndef PROJECT_MESSAGES_H
#define PROJECT_MESSAGES_H

#include "project.h"
#include "project_language.h"
#include "World.h"
#include "WorldSession.h"
#include "Player.h"

#define PROJECT_SEND_CHAT_MESSAGE_TO_PLAYER(msg) PROJECT::Messages::SendToPlayer(player, PROJECT::Messages::Types::CHAT, msg)
#define PROJECT_SEND_LANGUAGE_MESSAGE_TO_PLAYER(stringId) PROJECT::Messages::SendToPlayer(player, PROJECT::Messages::Types::CHAT, stringId)

// forward declaration for functions used in template function since their arguments are not template-parameter dependent
TC_GAME_API extern const char * PROJECT::Language::GetLanguageString(uint32 stringId, PROJECT::Language::Languages language);
TC_GAME_API extern PROJECT::Language::Languages PROJECT::Language::GetLanguageForPlayer(Player * player);

class Map;

namespace PROJECT
{
    namespace Messages
    {
        enum Types
        {
            AREA_TRIGGER = 1,
            CHAT         = 2,
            BOTH         = AREA_TRIGGER | CHAT,
        };
        void TC_GAME_API SendToPlayer(Player * player, Types type, const char * message, ...);
        void TC_GAME_API SendToPlayer(Player * player, Types type, uint32 stringId, ...);
        void TC_GAME_API SendToMap(Map * map, uint8 type, const char * message, ...);

        void TC_GAME_API SendToWorld(const char * str, ...);
        void TC_GAME_API SendToWorld(uint32 stringId, const char * str, ...);
        void TC_GAME_API SendToWorldDebug(const char * debugType, const char * str, ...);
        void TC_GAME_API SendToGM(const char * str, ...);

        void TC_GAME_API SendNotificationToGM(const char * str, ...);

        void TC_GAME_API SendToConsole(const char * str, ...);

        template<class PREDICATE> void SendToWorldCondition(uint32 stringId, PREDICATE predicate, ...)
        {
            va_list ap;

            char * messages[PROJECT::Language::Languages::MAX];
            char * tmpMsgs[PROJECT::Language::Languages::MAX];
            for (int i = 0; i < PROJECT::Language::Languages::MAX; i++)
            {
                messages[i] = const_cast<char *>(PROJECT::Language::GetLanguageString(stringId, (PROJECT::Language::Languages)i));

                // remove \r characters
                std::string tmpStr = messages[i];
                int idx;
                while ((idx = tmpStr.find_first_of('\r')) >= 0)
                    tmpStr.replace(idx, 1, "");
                messages[i] = const_cast<char *>(tmpStr.c_str());

                va_start(ap, predicate);
                tmpMsgs[i] = (char *)malloc(1024);
                vsprintf(tmpMsgs[i], messages[i], ap);
                va_end(ap);
            }

            for (SessionMap::const_iterator itr = sWorld->m_sessions.begin(); itr != sWorld->m_sessions.end(); ++itr)
            {
                if (!itr->second)
                    continue;

                Player * player = itr->second->GetPlayer();
                if (!player || !player->IsInWorld())
                    continue;

                if (!predicate(player))
                    continue;

                SendToPlayer(player, CHAT, tmpMsgs[PROJECT::Language::GetLanguageForPlayer(player)]);
            }
        }

    }
}

#endif
