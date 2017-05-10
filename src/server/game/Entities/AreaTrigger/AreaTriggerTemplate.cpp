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

#include "AreaTriggerTemplate.h"

#include <cmath>

// Init the MaxSearchRadius that will be used in TrinitySearcher, avoiding calculate it at each update
void AreaTriggerTemplate::InitMaxSearchRadius()
{
    switch (Type)
    {
        case AREATRIGGER_TYPE_SPHERE:
        {
            MaxSearchRadius = std::max(SphereDatas.Radius, SphereDatas.RadiusTarget);
            break;
        }
        case AREATRIGGER_TYPE_BOX:
        {
            MaxSearchRadius = std::sqrt(BoxDatas.Extents[0] * BoxDatas.Extents[0] / 4 + BoxDatas.Extents[1] * BoxDatas.Extents[1] / 4);
            break;
        }
        case AREATRIGGER_TYPE_POLYGON:
        {
            if (PolygonDatas.Height <= 0.0f)
                PolygonDatas.Height = 1.0f;

            for (G3D::Vector2 const& vertice : PolygonVertices)
            {
                float pointDist = vertice.length();

                if (pointDist > MaxSearchRadius)
                    MaxSearchRadius = pointDist;
            }

            break;
        }
        case AREATRIGGER_TYPE_CYLINDER:
        {
            MaxSearchRadius = CylinderDatas.Radius;
            break;
        }
        default:
            break;
    }
}
