/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef ModelIgnoreFlags_h__
#define ModelIgnoreFlags_h__

#include "Define.h"

namespace VMAP
{
enum class ModelIgnoreFlags : uint32
{
    Nothing = 0x00,
    M2      = 0x01
};

inline ModelIgnoreFlags operator&(ModelIgnoreFlags left, ModelIgnoreFlags right) { return ModelIgnoreFlags(uint32(left) & uint32(right)); }
}

#endif // ModelIgnoreFlags_h__
