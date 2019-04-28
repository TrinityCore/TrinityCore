#ifndef PROJECT_HANDLER_PLACEHOLDER_H
#define PROJECT_HANDLER_PLACEHOLDER_H

#ifdef PROJECT_CUSTOM
#include "project_handler.h"
#else

#include "project_packet_Misc.h"
#include "project_packet_Launcher.h"

#define _emptyPacket WorldSession* session

namespace PacketHandler
{
    namespace Misc
    {
        TC_GAME_API inline void SendDisplayPlayerChoice(Player* player, PROJECT::Packets::Misc::DisplayPlayerChoice& packet) {};
    }

    namespace Garrisons
    {
        inline void HandleOpenShipmentNpcCustom(Player* player, ObjectGuid guid) {};
        inline void HandleOpenTalentNpcCustom(Player* player, ObjectGuid guid) {};
    }

    namespace BattlePay
    {
        inline void SendGetDistributionListResponse(WorldSession * session) {};
    }


    namespace Launcher
    {
        inline void HandleLauncherGetEncryptionKey(_emptyPacket) {};
        inline void HandleLauncherUpdate(WorldSession* session, PROJECT::Packets::Launcher::Update& packet) {};
        inline void HandleLauncherLoadedDlls(WorldSession* session, PROJECT::Packets::Launcher::LoadedDlls& packet) {};
    }
}

#endif

#endif
