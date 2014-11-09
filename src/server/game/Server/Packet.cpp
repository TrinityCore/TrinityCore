/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#include "Packet.h"

inline bool IsInstanceOnlyOpcode(uint32 opcode)
{
    // TODO: Use names when known
    switch (opcode)
    {
        case 0x000F: // Client
        case 0x0111: // Client
        case 0x03E4: // Client
        case 0x0549: // Client
        case 0x054C: // Client
        case 0x055A: // Client
        case 0x056C: // Client
        case 0x057A: // Client
        case 0x057B: // Client
        case 0x05CC: // Client
        case 0x05EA: // Client
        case 0x05EC: // Client
        case 0x05F9: // Client
        case 0x05FB: // Client
        case 0x074C: // Client
        case 0x075B: // Client
        case 0x076C: // Client
        case 0x077B: // Client
        case 0x077C: // Client
        case 0x07CC: // Client
        case 0x07DB: // Client
        case 0x07EC: // Client
        case 0x07FB: // Client
        case 0x07FC: // Client
        case 0x0827: // Client
        case 0x0935: // Client
        case 0x0F0C: // ClientSpell
        case 0x0F10: // ClientSpell
        case 0x0F1B: // ClientSpell
        case 0x0F1C: // ClientSpell
        case 0x0F20: // ClientSpell
        case 0x0F2C: // ClientSpell
        case 0x0F2F: // ClientSpell
        case 0x0F3B: // ClientSpell
        case 0x0F8B: // ClientSpell
        case 0x0F8C: // ClientSpell
        case 0x0F90: // ClientSpell
        case 0x0F9F: // ClientSpell
        case 0x0FA0: // ClientSpell
        case 0x1382: // Client
        case 0x14C9: // Client
        case 0x154A: // Client
        case 0x155A: // Client
        case 0x155C: // Client
        case 0x1567: // ClientQuest
        case 0x156A: // Client
        case 0x156B: // Client
        case 0x157A: // Client
        case 0x157B: // Client
        case 0x15DC: // Client
        case 0x15EB: // Client
        case 0x15FB: // Client
        case 0x170C: // ClientSpell
        case 0x171C: // ClientSpell
        case 0x171F: // ClientSpell
        case 0x172C: // ClientSpell
        case 0x172F: // ClientSpell
        case 0x173C: // ClientSpell
        case 0x173F: // ClientSpell
        case 0x1740: // ClientSpell
        case 0x1790: // ClientSpell
        case 0x179B: // ClientSpell
        case 0x179F: // ClientSpell
        case 0x1D3E: // Client
        case 0x1D82: // ClientQuest
        case 0x1D83: // ClientQuest
        case 0x1D85: // ClientQuest
        case 0x1D87: // ClientQuest
        case 0x1D93: // ClientQuest
        case 0x1D96: // ClientQuest
        case 0x1D97: // ClientQuest
        case 0x1DA1: // ClientQuest
        case 0x1DA2: // ClientQuest
        case 0x1DA3: // ClientQuest
        case 0x1DA4: // ClientQuest
        case 0x1DA5: // ClientQuest
        case 0x1DA7: // ClientQuest
        case 0x1DB0: // Client
        case 0x1DC2: // ClientQuest
        case 0x1DC6: // ClientQuest
        case 0x1DC7: // ClientQuest
        case 0x1DD2: // ClientQuest
        case 0x1DD3: // ClientQuest
        case 0x1DD6: // ClientQuest
        case 0x1DD7: // ClientQuest
        case 0x1DD8: // ClientQuest
        case 0x1DE4: // ClientQuest
        case 0x1DE5: // ClientQuest
        case 0x1DE7: // ClientQuest
        case 0x1F02: // ClientQuest
        case 0x1F06: // ClientQuest
        case 0x1F07: // ClientQuest
        case 0x1F0C: // ClientSpell
        case 0x1F12: // ClientQuest
        case 0x1F13: // ClientQuest
        case 0x1F16: // ClientQuest
        case 0x1F17: // ClientQuest
        case 0x1F18: // ClientQuest
        case 0x1F1C: // ClientSpell
        case 0x1F1F: // ClientSpell
        case 0x1F24: // ClientQuest
        case 0x1F25: // ClientQuest
        case 0x1F27: // ClientQuest
        case 0x1F2C: // ClientSpell
        case 0x1F2F: // ClientSpell
        case 0x1F3C: // ClientSpell
        case 0x1F3F: // ClientSpell
        case 0x1F40: // ClientSpell
        case 0x1F44: // ClientQuest
        case 0x1F48: // ClientQuest
        case 0x1F51: // ClientQuest
        case 0x1F55: // ClientQuest
        case 0x1F57: // ClientQuest
        case 0x1F61: // ClientQuest
        case 0x1F63: // ClientQuest
        case 0x1F64: // ClientQuest
        case 0x1F65: // ClientQuest
        case 0x1F67: // ClientQuest
        case 0x1F85: // ClientQuest
        case 0x1F86: // ClientQuest
        case 0x1F87: // ClientQuest
        case 0x1F90: // ClientSpell
        case 0x1F92: // ClientQuest
        case 0x1F94: // ClientQuest
        case 0x1F96: // ClientQuest
        case 0x1F97: // ClientQuest
        case 0x1F9B: // ClientSpell
        case 0x1F9F: // ClientSpell
        case 0x1FA1: // ClientQuest
        case 0x1FA2: // ClientQuest
        case 0x1FA3: // ClientQuest
        case 0x1FA4: // ClientQuest
        case 0x1FA5: // ClientQuest
        case 0x1FA7: // ClientQuest
        case 0x1FC2: // ClientQuest
        case 0x1FC6: // ClientQuest
        case 0x1FC7: // ClientQuest
        case 0x1FD2: // ClientQuest
        case 0x1FD3: // ClientQuest
        case 0x1FD6: // ClientQuest
        case 0x1FD7: // ClientQuest
        case 0x1FD8: // ClientQuest
        case 0x1FE4: // ClientQuest
        case 0x1FE5: // ClientQuest
        case 0x1FE7: // ClientQuest
            return true;
        default:
            return false;
    }
}

WorldPackets::ServerPacket::ServerPacket(OpcodeServer opcode, size_t initialSize /*= 200*/) : Packet(WorldPacket(opcode, initialSize))
{
    if (IsInstanceOnlyOpcode(opcode))
        _connectionIndex = CONNECTION_TYPE_INSTANCE;
}
