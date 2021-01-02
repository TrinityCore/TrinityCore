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

#ifndef _WARDEN_WIN_H
#define _WARDEN_WIN_H

#include "Cryptography/ARC4.h"
#include "Cryptography/BigNumber.h"
#include "ByteBuffer.h"
#include "Warden.h"
#include <array>
#include <list>
#include <utility>

#pragma pack(push, 1)

struct WardenInitModuleRequest
{
    uint8 Command1;
    uint16 Size1;
    uint32 CheckSumm1;
    uint8 Unk1;
    uint8 Unk2;
    uint8 Type;
    uint8 String_library1;
    uint32 Function1[4];

    uint8 Command2;
    uint16 Size2;
    uint32 CheckSumm2;
    uint8 Unk3;
    uint8 Unk4;
    uint8 String_library2;
    uint32 Function2;
    uint8 Function2_set;

    uint8 Command3;
    uint16 Size3;
    uint32 CheckSumm3;
    uint8 Unk5;
    uint8 Unk6;
    uint8 String_library3;
    uint32 Function3;
    uint8 Function3_set;
};
static_assert(sizeof(WardenInitModuleRequest) == (1 + 2 + 4 + 1 + 1 + 1 + 1 + (4 * 4) + 1 + 2 + 4 + 1 + 1 + 1 + 4 + 1 + 1 + 2 + 4 + 1 + 1 + 1 + 4 + 1));

#pragma pack(pop)

class WorldSession;
class Warden;

class TC_GAME_API WardenWin : public Warden
{
    public:
        WardenWin();

        void Init(WorldSession* session, SessionKey const& K) override;
        void InitializeModuleForClient(ClientWardenModule& module) override;
        void InitializeModule() override;
        void RequestHash() override;
        void HandleHashResult(ByteBuffer &buff) override;
        void RequestChecks() override;
        void HandleCheckResult(ByteBuffer &buff) override;

        size_t DEBUG_ForceSpecificChecks(std::vector<uint16> const& checks) override;

    private:
        uint32 _serverTicks;
        std::array<std::pair<std::vector<uint16>, std::vector<uint16>::const_iterator>, NUM_CHECK_CATEGORIES> _checks;
        std::vector<uint16> _currentChecks;
};

#endif
