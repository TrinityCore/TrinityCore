/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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

#ifndef _WARDEN_MAC_H
#define _WARDEN_MAC_H

#include "ARC4.h"
#include "ByteBuffer.h"
#include "Warden.h"

class WorldSession;
class Warden;

class TC_GAME_API WardenMac : public Warden
{
    public:
        WardenMac();
        ~WardenMac();

        void Init(WorldSession* session, SessionKey const& k) override;
        void InitializeModuleForClient(ClientWardenModule& module) override;
        void InitializeModule() override;
        void RequestHash() override;
        void HandleHashResult(ByteBuffer& buff) override;
        void RequestChecks() override;
        size_t DEBUG_ForceSpecificChecks(std::vector<uint16> const& /*checks*/) override { return 0; }
        void HandleCheckResult(ByteBuffer& buff) override;
};

#endif
