/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GOPackets_h__
#define GOPackets_h__

#include "Packet.h"
#include "DB2Stores.h"
#include "GameObject.h"
#include "WorldSession.h"

namespace WorldPackets
{
    namespace GameObject
    {
        class GameObjUse final : public ClientPacket
        {
        public:
            GameObjUse(WorldPacket&& packet) : ClientPacket(CMSG_GAME_OBJ_USE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };

        class GameObjReportUse final : public ClientPacket
        {
        public:
            GameObjReportUse(WorldPacket&& packet) : ClientPacket(CMSG_GAME_OBJ_REPORT_USE, std::move(packet)) { }

            void Read() override;

            ObjectGuid Guid;
        };

        class GameObjectDespawn final : public ServerPacket
        {
        public:
            GameObjectDespawn() : ServerPacket(SMSG_GAME_OBJECT_DESPAWN, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid ObjectGUID;
        };

        class PageText final : public ServerPacket
        {
        public:
            PageText() : ServerPacket(SMSG_PAGE_TEXT, 16) { }

            WorldPacket const* Write() override;

            ObjectGuid GameObjectGUID;
        };

        class GameObjectActivateAnimKit final : public ServerPacket
        {
        public:
            GameObjectActivateAnimKit() : ServerPacket(SMSG_GAME_OBJECT_ACTIVATE_ANIM_KIT, 16 + 4 + 1) { }

            WorldPacket const* Write() override;

            ObjectGuid ObjectGUID;
            int32 AnimKitID = 0;
            bool Maintain = false;
        };
    }
}
#endif // GOPackets_h__
