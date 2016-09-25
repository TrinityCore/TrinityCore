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

#include "AreaTriggerTemplate.h"

AreaTriggerTypes AreaTriggerTemplate::GetType()
{
    if (IsSphere())
    {
        return AREATRIGGER_TYPE_SPHERE;
    }
    else if (IsBox())
    {
        return AREATRIGGER_TYPE_BOX;
    }
    else if (IsPolygon())
    {
        return AREATRIGGER_TYPE_POLYGON;
    }
    else if (IsCylinder())
    {
        return AREATRIGGER_TYPE_CYLINDER;
    }

    return AREATRIGGER_TYPE_NONE;
}

// Init the MaxSearchRadius that will be used in TrinitySearcher, avoiding calculate it at each update
void AreaTriggerTemplate::InitMaxSearchRadius()
{
    switch (GetType())
    {
        case AREATRIGGER_TYPE_SPHERE:
        {
            MaxSearchRadius = SphereDatas.Radius;
            break;
        }
        case AREATRIGGER_TYPE_BOX:
        {
            MaxSearchRadius = std::max(std::max(BoxDatas.Extents[0], BoxDatas.Extents[1]), BoxDatas.Extents[2]);
            break;
        }
        case AREATRIGGER_TYPE_POLYGON:
        {
            if (PolygonDatas.Height <= 0.0f)
                PolygonDatas.Height = 1.0f;

            for (AreaTriggerPolygonVertice vertice : PolygonVertices)
            {
                float pointDist = std::sqrt((vertice.VerticeX * vertice.VerticeX) + (vertice.VerticeY * vertice.VerticeY));

                if (pointDist > MaxSearchRadius)
                    MaxSearchRadius = pointDist;
            }

            break;
        }
        case AREATRIGGER_TYPE_CYLINDER:
        {
            MaxSearchRadius = std::sqrt((CylinderDatas.Radius * CylinderDatas.Radius) + (CylinderDatas.Height * CylinderDatas.Height));
            break;
        }
    }
}
