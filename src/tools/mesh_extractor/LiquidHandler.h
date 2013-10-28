/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

#ifndef LIQUID_H
#define LIQUID_H
#include "ADT.h"
#include "Utils.h"
#include "Define.h"

#include <vector>

class LiquidHandler
{
public:
    LiquidHandler(ADT* adt);

    ADT* Source;
    std::vector<Vector3> Vertices;
    std::vector<Triangle<uint32> > Triangles;
    std::vector<MCNKLiquidData> MCNKData;
private:
    void HandleNewLiquid();
};
#endif