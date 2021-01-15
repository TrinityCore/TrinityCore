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

#include "AreaTriggerTemplate.h"
#include <G3D/Vector3.h>
#include <algorithm>
#include <cstring>
#include <cmath>

AreaTriggerScaleInfo::AreaTriggerScaleInfo()
{
    memset(Data.Raw, 0, sizeof(Data.Raw));
}

AreaTriggerTemplate::AreaTriggerTemplate()
{
    Id = 0;
    Type = AREATRIGGER_TYPE_MAX;
    Flags = 0;
    ScriptId = 0;
    MaxSearchRadius = 0.0f;

    memset(DefaultDatas.Data, 0, sizeof(DefaultDatas.Data));
}

AreaTriggerTemplate::~AreaTriggerTemplate()
{
}

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

            Position center(0.0f, 0.0f);
            for (TaggedPosition<Position::XY> const& vertice : PolygonVertices)
            {
                float pointDist = center.GetExactDist2d(vertice);

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

AreaTriggerMiscTemplate::AreaTriggerMiscTemplate()
{
    MiscId = 0;
    AreaTriggerEntry = 0;

    MoveCurveId = 0;
    ScaleCurveId = 0;
    MorphCurveId = 0;
    FacingCurveId = 0;

    AnimId = 0;
    AnimKitId = 0;

    DecalPropertiesId = 0;

    TimeToTarget = 0;
    TimeToTargetScale = 0;

    // legacy code from before it was known what each curve field does
    // wtf? thats not how you pack curve data
    float tmp = 1.0000001f;
    memcpy(&ExtraScale.Data.Raw[5], &tmp, sizeof(tmp));
    // also OverrideActive does nothing on ExtraScale
    ExtraScale.Data.Structured.OverrideActive = 1;

    Template = nullptr;
}

AreaTriggerMiscTemplate::~AreaTriggerMiscTemplate()
{
}

bool AreaTriggerMiscTemplate::HasSplines() const
{
    return SplinePoints.size() >= 2;
}
