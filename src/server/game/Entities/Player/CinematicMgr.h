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

#ifndef CinematicMgr_h__
#define CinematicMgr_h__

#include "Define.h"
#include "Object.h"

#define CINEMATIC_LOOKAHEAD (2 * IN_MILLISECONDS)
#define CINEMATIC_UPDATEDIFF 500

class Player;
struct CinematicSequencesEntry;
struct FlyByCamera;

class TC_GAME_API CinematicMgr
{
    friend class Player;
public:
    explicit CinematicMgr(Player* playerref);
    ~CinematicMgr();
    // Cinematic camera data and remote sight functions
    bool IsOnCinematic() const { return (m_cinematicCamera != nullptr); }
    void BeginCinematic(CinematicSequencesEntry const* cinematic)
    {
        m_activeCinematic = cinematic;
        m_activeCinematicCameraIndex = -1;
    }
    void NextCinematicCamera();
    void EndCinematic();
    void UpdateCinematicLocation(uint32 diff);

private:
    // Remote location information
    Player*     player;

protected:
    uint32      m_cinematicDiff;
    uint32      m_lastCinematicCheck;
    CinematicSequencesEntry const* m_activeCinematic;
     int32      m_activeCinematicCameraIndex;
    uint32      m_cinematicLength;
    std::vector<FlyByCamera> const* m_cinematicCamera;
    Position    m_remoteSightPosition;
    TempSummon* m_CinematicObject;
};

#endif // CinematicMgr_h__
