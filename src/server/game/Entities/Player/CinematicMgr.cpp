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

#include "CinematicMgr.h"
#include "Containers.h"
#include "DB2Structure.h"
#include "M2Stores.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "TemporarySummon.h"

CinematicMgr::CinematicMgr(Player* playerref)
{
    player = playerref;
    m_cinematicDiff = 0;
    m_lastCinematicCheck = 0;
    m_activeCinematic = nullptr;
    m_activeCinematicCameraIndex = -1;
    m_cinematicLength = 0;
    m_cinematicCamera = nullptr;
    m_remoteSightPosition = Position(0.0f, 0.0f, 0.0f);
    m_CinematicObject = nullptr;
}

CinematicMgr::~CinematicMgr()
{
    if (m_cinematicCamera && m_activeCinematic)
        EndCinematic();
}

void CinematicMgr::NextCinematicCamera()
{
    // Sanity check for active camera set
    if (!m_activeCinematic || m_activeCinematicCameraIndex >= int32(Trinity::Containers::Size(m_activeCinematic->Camera)))
        return;

    uint32 cinematicCameraId = m_activeCinematic->Camera[++m_activeCinematicCameraIndex];
    if (!cinematicCameraId)
        return;

    if (std::vector<FlyByCamera> const* flyByCameras = GetFlyByCameras(cinematicCameraId))
    {
        // Initialize diff, and set camera
        m_cinematicDiff = 0;
        m_cinematicCamera = flyByCameras;

        if (!m_cinematicCamera->empty())
        {
            FlyByCamera const& firstCamera = m_cinematicCamera->front();
            Position const& pos = firstCamera.locations;
            if (!pos.IsPositionValid())
                return;

            player->GetMap()->LoadGrid(pos.GetPositionX(), pos.GetPositionY());
            m_CinematicObject = player->SummonCreature(VISUAL_WAYPOINT, pos.m_positionX, pos.m_positionY, pos.m_positionZ, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 5 * MINUTE * IN_MILLISECONDS);
            if (m_CinematicObject)
            {
                m_CinematicObject->setActive(true);
                player->SetViewpoint(m_CinematicObject, true);
            }

            // Get cinematic length
            m_cinematicLength = m_cinematicCamera->back().timeStamp;
        }
    }
}

void CinematicMgr::EndCinematic()
{
    if (!m_activeCinematic)
        return;

    m_cinematicDiff = 0;
    m_cinematicCamera = nullptr;
    m_activeCinematic = nullptr;
    m_activeCinematicCameraIndex = -1;
    if (m_CinematicObject)
    {
        if (WorldObject* vpObject = player->GetViewpoint())
            if (vpObject == m_CinematicObject)
                player->SetViewpoint(m_CinematicObject, false);

        m_CinematicObject->AddObjectToRemoveList();
    }
}

void CinematicMgr::UpdateCinematicLocation(uint32 /*diff*/)
{
    if (!m_activeCinematic || m_activeCinematicCameraIndex == -1 || !m_cinematicCamera || m_cinematicCamera->size() == 0)
        return;

    Position lastPosition;
    uint32 lastTimestamp = 0;
    Position nextPosition;
    uint32 nextTimestamp = 0;

    // Obtain direction of travel
    for (FlyByCamera const& cam : *m_cinematicCamera)
    {
        if (cam.timeStamp > m_cinematicDiff)
        {
            nextPosition.Relocate(cam.locations);
            nextTimestamp = cam.timeStamp;
            break;
        }
        lastPosition.Relocate(cam.locations);
        lastTimestamp = cam.timeStamp;
    }
    float angle = lastPosition.GetAngle(&nextPosition);
    angle -= lastPosition.GetOrientation();
    if (angle < 0)
        angle += 2 * float(M_PI);

    // Look for position around 2 second ahead of us.
    int32 workDiff = m_cinematicDiff;

    // Modify result based on camera direction (Humans for example, have the camera point behind)
    workDiff += static_cast<int32>(float(CINEMATIC_LOOKAHEAD) * cos(angle));

    // Get an iterator to the last entry in the cameras, to make sure we don't go beyond the end
    auto endItr = m_cinematicCamera->rbegin();
    if (endItr != m_cinematicCamera->rend() && workDiff > static_cast<int32>(endItr->timeStamp))
        workDiff = endItr->timeStamp;

    // Never try to go back in time before the start of cinematic!
    if (workDiff < 0)
        workDiff = m_cinematicDiff;

    // Obtain the previous and next waypoint based on timestamp
    for (FlyByCamera const& cam : *m_cinematicCamera)
    {
        if (static_cast<int32>(cam.timeStamp) >= workDiff)
        {
            nextPosition.Relocate(cam.locations);
            nextTimestamp = cam.timeStamp;
            break;
        }
        lastPosition.Relocate(cam.locations);
        lastTimestamp = cam.timeStamp;
    }

    // Never try to go beyond the end of the cinematic
    if (workDiff > static_cast<int32>(nextTimestamp))
        workDiff = static_cast<int32>(nextTimestamp);

    // Interpolate the position for this moment in time (or the adjusted moment in time)
    uint32 timeDiff = nextTimestamp - lastTimestamp;
    uint32 interDiff = workDiff - lastTimestamp;
    float xDiff = nextPosition.m_positionX - lastPosition.m_positionX;
    float yDiff = nextPosition.m_positionY - lastPosition.m_positionY;
    float zDiff = nextPosition.m_positionZ - lastPosition.m_positionZ;
    Position interPosition(lastPosition.m_positionX + (xDiff * (float(interDiff) / float(timeDiff))), lastPosition.m_positionY +
        (yDiff * (float(interDiff) / float(timeDiff))), lastPosition.m_positionZ + (zDiff * (float(interDiff) / float(timeDiff))));

    // Advance (at speed) to this position. The remote sight object is used
    // to send update information to player in cinematic
    if (m_CinematicObject && interPosition.IsPositionValid())
        m_CinematicObject->MonsterMoveWithSpeed(interPosition.m_positionX, interPosition.m_positionY, interPosition.m_positionZ, 500.0f, false, true);

    // If we never received an end packet 10 seconds after the final timestamp then force an end
    if (m_cinematicDiff > m_cinematicLength + 10 * IN_MILLISECONDS)
        EndCinematic();
}
