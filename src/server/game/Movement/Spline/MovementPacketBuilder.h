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

#ifndef TRINITYSERVER_PACKET_BUILDER_H
#define TRINITYSERVER_PACKET_BUILDER_H

#include "Define.h"

class ByteBuffer;
namespace G3D
{
    class Vector3;
}

namespace Movement
{
    class MoveSpline;
    class PacketBuilder
    {
        static void WriteCommonMonsterMovePart(MoveSpline const& mov, ByteBuffer& data);
    public:

        static void WriteMonsterMove(MoveSpline const& mov, ByteBuffer& data);
        static void WriteStopMovement(G3D::Vector3 const& loc, uint32 splineId, ByteBuffer& data);
        static void WriteCreate(MoveSpline const& mov, ByteBuffer& data);
        static void WriteSplineSync(MoveSpline const& mov, ByteBuffer& data);
    };
}
#endif // TRINITYSERVER_PACKET_BUILDER_H
