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

#ifndef CombatLogPacketsCommon_h__
#define CombatLogPacketsCommon_h__

#include "Packet.h"

class Spell;
class Unit;

namespace WorldPackets
{
    namespace Spells
    {
        struct SpellLogPowerData
        {
            SpellLogPowerData(int32 powerType, int32 amount, int32 cost) : PowerType(powerType), Amount(amount), Cost(cost) { }

            int32 PowerType = 0;
            int32 Amount = 0;
            int32 Cost = 0;
        };

        struct SpellCastLogData
        {
            int64 Health = 0;
            int32 AttackPower = 0;
            int32 SpellPower = 0;
            int32 Armor = 0;
            std::vector<SpellLogPowerData> PowerData;

            void Initialize(Unit const* unit);
            void Initialize(Spell const* spell);
        };

        struct ContentTuningParams
        {
            enum ContentTuningType : uint32
            {
                TYPE_CREATURE_TO_PLAYER_DAMAGE          = 1,
                TYPE_PLAYER_TO_CREATURE_DAMAGE          = 2,
                TYPE_CREATURE_TO_CREATURE_DAMAGE        = 4,
                TYPE_PLAYER_TO_PLAYER_SANDBOX_SCALING   = 7, // NYI
                TYPE_PLAYER_TO_PLAYER_EXPECTED_STAT     = 8,
            };

            enum ContentTuningFlags : uint32
            {
                NO_LEVEL_SCALING        = 0x1,
                NO_ITEM_LEVEL_SCALING   = 0x2
            };

            uint32 Type = 0;
            int16 PlayerLevelDelta = 0;
            float PlayerItemLevel = 0;
            float TargetItemLevel = 0;
            uint16 ScalingHealthItemLevelCurveID = 0;
            uint8 TargetLevel = 0;
            uint8 Expansion = 0;
            int8 TargetScalingLevelDelta = 0;
            uint32 Flags = NO_LEVEL_SCALING | NO_ITEM_LEVEL_SCALING;
            int32 PlayerContentTuningID = 0;
            int32 TargetContentTuningID = 0;

            template<class T, class U>
            bool GenerateDataForUnits(T* attacker, U* target);
        };

        struct SpellCastVisual
        {
            int32 SpellXSpellVisualID = 0;
            int32 ScriptVisualID = 0;
        };

        ByteBuffer& operator<<(ByteBuffer& data, SpellCastLogData const& spellCastLogData);
        ByteBuffer& operator<<(ByteBuffer& data, ContentTuningParams const& contentTuningParams);
        ByteBuffer& operator>>(ByteBuffer& data, SpellCastVisual& visual);
        ByteBuffer& operator<<(ByteBuffer& data, SpellCastVisual const& visual);
    }

    namespace CombatLog
    {
        class CombatLogServerPacket : public ServerPacket
        {
        public:
            CombatLogServerPacket(OpcodeServer opcode, size_t initialSize = 200, ConnectionType connection = CONNECTION_TYPE_DEFAULT)
                : ServerPacket(opcode, initialSize, connection), _fullLogPacket(opcode, initialSize, connection) { }

            WorldPacket const* GetFullLogPacket() const { return &_fullLogPacket; }
            WorldPacket const* GetBasicLogPacket() const { return &_worldPacket; }

            Spells::SpellCastLogData LogData;

        protected:
            template<typename T>
            void operator<<(T const& val)
            {
                _worldPacket << val;
                _fullLogPacket << val;
            }

            void WriteLogDataBit()
            {
                _worldPacket.WriteBit(false);
                _fullLogPacket.WriteBit(true);
            }

            void FlushBits()
            {
                _worldPacket.FlushBits();
                _fullLogPacket.FlushBits();
            }

            bool WriteBit(bool bit)
            {
                _worldPacket.WriteBit(bit);
                _fullLogPacket.WriteBit(bit);
                return bit;
            }

            void WriteBits(uint32 value, uint32 bitCount)
            {
                _worldPacket.WriteBits(value, bitCount);
                _fullLogPacket.WriteBits(value, bitCount);
            }

            ByteBuffer& WriteLogData();

            WorldPacket _fullLogPacket;
        };
    }
}

#endif // CombatLogPacketsCommon_h__
