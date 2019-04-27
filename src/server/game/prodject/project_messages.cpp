#include "project_messages.h"
#include "Language.h"
#include "Map.h"
#include "ChatPackets.h"
#include "WorldSession.h"
#include "Player.h"
#include "Log.h"
#include <stdarg.h>

namespace PROJECT {
namespace Messages {

void SendToPlayer(Player * player, Types type, const char * message, ...)
{
    if (!player)
        return;

    char tmp_msg[16384];
    va_list ap;
    va_start(ap, message);
    vsprintf(tmp_msg, message, ap);
    va_end(ap);

    WorldPackets::Chat::Chat packet;
    packet.Initialize(type & Types::AREA_TRIGGER ? CHAT_MSG_RAID_BOSS_EMOTE : CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, player, tmp_msg);
    player->GetSession()->SendPacket(packet.Write());
}

void SendToMap(Map * map, uint8 type, const char * message, ...)
{
    if (!map)
        return;

    char tmp_msg[16384];
    va_list ap;
    va_start(ap, message);
    vsprintf(tmp_msg, message, ap);
    va_end(ap);

    Map::PlayerList const &playerList = map->GetPlayers();
    for (Map::PlayerList::const_iterator i = playerList.begin(); i != playerList.end(); ++i)
    {
        if (Player * player = i->GetSource())
            if (player->IsInWorld())
            {
                WorldPackets::Chat::Chat packet;
                packet.Initialize(type & Types::AREA_TRIGGER ? CHAT_MSG_RAID_BOSS_EMOTE : CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, player, tmp_msg);
                player->GetSession()->SendPacket(packet.Write());
            }
    }
}

void SendToPlayer(Player * player, Types type, uint32 stringId, ...)
{
    if (!player)
        return;

    char tmp_msg[16384];
    va_list ap;
    const char * message = PROJECT::Language::GetLanguageString(stringId, player);

    // remove \r characters
    std::string tmpStr = message;
    int idx;
    while ((idx = tmpStr.find_first_of('\r')) >= 0)
        tmpStr.replace(idx, 1, "");
    message = tmpStr.c_str();

    va_start(ap, stringId);
    vsprintf(tmp_msg, message, ap);
    va_end(ap);

    WorldPackets::Chat::Chat packet;
    packet.Initialize(type & Types::AREA_TRIGGER ? CHAT_MSG_RAID_BOSS_EMOTE : CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, player, tmp_msg);
    player->GetSession()->SendPacket(packet.Write());
}

void SendToWorld(uint32 messageId, const char * str, ...)
{
    if (!str)
        return;

    char tmp_msg[255];
    va_list ap;
    va_start(ap, str);
    vsprintf(tmp_msg, str, ap);
    va_end(ap);

    sWorld->SendWorldText(messageId, tmp_msg);
}

void SendToWorld(const char * str, ...)
{
    if (!str)
        return;

    char tmp_msg[255];
    va_list ap;
    va_start(ap, str);
    vsprintf(tmp_msg, str, ap);
    va_end(ap);

    SendToWorld(LANG_SYSTEMMESSAGE, tmp_msg);
}

void SendToWorldDebug(const char * debugType, const char * str, ...)
{
    if (!str)
        return;

    char tmp_msg[4096];
    va_list ap;
    va_start(ap, str);
    vsprintf(tmp_msg, str, ap);
    va_end(ap);

    sWorld->SendWorldText(999016, debugType, tmp_msg);
}

void SendToGM(const char * str, ...)
{
    if (!str)
        return;

    char tmp_msg[255];
    va_list ap;
    va_start(ap, str);
    vsprintf(tmp_msg, str, ap);
    va_end(ap);

    WorldPackets::Chat::Chat packet;
    packet.Initialize(CHAT_MSG_SYSTEM, LANG_UNIVERSAL, nullptr, nullptr, tmp_msg);
    sWorld->SendGlobalGMMessage(packet.Write());
}

void SendNotificationToGM(const char * str, ...)
{
    if (!str)
        return;

    char tmp_msg[2048];
    va_list ap;
    va_start(ap, str);
    vsprintf(tmp_msg, str, ap);
    va_end(ap);

    sWorld->SendGlobalGMMessage(WorldPackets::Chat::PrintNotification(tmp_msg).Write());
}

void SendToConsole(const char * str, ...)
{
    if (!str)
        return;

    char tmp_msg[1024];
    va_list ap;
    va_start(ap, str);
    vsprintf(tmp_msg, str, ap);
    va_end(ap);

    TC_LOG_INFO("misc", "%s", tmp_msg);
}

} // Messages
} // PROJECT
