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

#ifndef _ARCHAEOLOGY_H
#define _ARCHAEOLOGY_H

#include "ArchaeologyMgr.h"
#include "Common.h"
#include "WorldSession.h"

#define DIGS_PER_SITE 3
class Player;

struct ArchData
{
    uint32 FragId = 0;
    uint32 FragCount = 0;
    uint32 KeyId = 0;
    uint32 KeyCount = 0;
};

enum ContinentState
{
    STATE_NULL          = 0,
    STATE_USE           = 1,
    STATE_EXT           = 2,
};

class Archaeology
{
    public:
        explicit Archaeology(Player* player);

        void Initialize();

        void Learn();
        void UnLearn();
        void Update();

        void UseSite();

        void SendResearchHistory();

        void ActivateBranch(uint8 branchId, bool force = false);
        bool ProjectCompleteable(uint16 projectId);
        bool ProjectExists(uint16 projectId);

        void CompleteProject(uint16 projectId);
        void SetArchData(ArchData const& data);

    private:
        Player* _player;
        std::unique_ptr<ArchData> _archData;

        // Site Functionality
        ContinentState _continentState[CONTINENT_SITES];
        SiteData _site[CONTINENT_SITES * COUNT_CONT];

        void LoadSitesFromDB();
        void VerifySites();

        Continent GetContinent();
        uint32 GetNearestSite(float &distance);
        void SetSite(uint32 posi, uint16 entry, uint32 state = 0);
        void RegeneratePosition(uint32 position, Continent continent);
        void RegenerateContinent(Continent continent);
        void RegenerateAllSites();

        // Project Functionality
        std::map<uint16, std::pair<int32, int32>> _completedProjects;
        std::map<uint8, BranchData> _branches;

        void LoadCompletedProjectsFromDB();
        void LoadCurrentProjectsFromDB();
        void InitBranches();
        void VerifyProjects();
        void CleanProjects();

        void RegenerateBranch(uint8 branch);
        void VisualizeBranch(uint8 position, uint16 project);
};

#endif
