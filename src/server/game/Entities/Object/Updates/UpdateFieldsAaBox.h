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

#ifndef TRINITYCORE_UPDATE_FIELDS_AA_BOX_H
#define TRINITYCORE_UPDATE_FIELDS_AA_BOX_H

#include "Position.h"

namespace UF
{
struct AaBox
{
    TaggedPosition<Position::XYZ> Low;
    TaggedPosition<Position::XYZ> High;

    friend bool operator==(AaBox const&, AaBox const&) noexcept = default;

    friend ByteBuffer& operator<<(ByteBuffer& data, AaBox const& box)
    {
        data << box.Low;
        data << box.High;
        return data;
    }
};
}

#endif // TRINITYCORE_UPDATE_FIELDS_AA_BOX_H
