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

#include "BitStream.h"

template<>
bool Battlenet::BitStream::Read<bool>(uint32 /*bitCount*/)
{
    return Read<uint8>(1) != 0;
}

template<>
void Battlenet::BitStream::Write<bool>(bool value, uint32 /*bitCount*/)
{
    Write<uint8>(value ? 1 : 0, 1);
}
