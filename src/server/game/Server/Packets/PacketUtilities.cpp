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

#include "PacketUtilities.h"
#include "Errors.h"
#include <sstream>

WorldPackets::PacketArrayMaxCapacityException::PacketArrayMaxCapacityException(std::size_t requestedSize, std::size_t sizeLimit)
{
    std::ostringstream builder;
    builder << "Attempted to read more array elements from packet " << requestedSize << " than allowed " << sizeLimit;
    message().assign(builder.str());
}
