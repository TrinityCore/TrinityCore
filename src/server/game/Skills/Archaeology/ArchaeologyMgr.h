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

#ifndef _ARCHAEOLOGY_MGR_H
#define _ARCHAEOLOGY_MGR_H

#include "SharedDefines.h"
#include <map>
#include <vector>

class SitePolygonGraph;

#define CONTINENT_SITES 4
#define MAX_PROJECTS 16
#define POINT_PER_POLYGON 12
#define EPIC_CHANCE 0.05f
#define MAX_RARE_CHANCE 0.2f

enum Continent
{
    CONT_EASTERN        = 0,
    CONT_KALIMDOR       = 1,
    CONT_OUTLAND        = 2,
    CONT_NORTHREND      = 3,
    COUNT_CONT          = 4,
};

enum SkillStart
{
    SKILL_OUTLAND   = 300,
    SKILL_NORTHREND = 375,
    SKILL_CATA      = 450,
};

enum FindObject
{
    FIND_OBJECT_DRAENEI     = 207188,
    FIND_OBJECT_DWARF       = 204282,
    FIND_OBJECT_FOSSIL      = 206836,
    FIND_OBJECT_NERUBIAN    = 203078,
    FIND_OBJECT_NIGHT_ELF   = 203071,
    FIND_OBJECT_ORC         = 207187,
    FIND_OBJECT_TOL_VIR     = 207190,
    FIND_OBJECT_TROLL       = 202655,
    FIND_OBJECT_VRYKUL      = 207189,
};

struct SiteEntry
{
    uint16 id;
    uint32 mapId;
    uint16 questPOI;
    uint32 reqSkill;
    uint32 minLevel;
};

struct SiteData
{
    uint16 Entry = 0;
    uint16 State = 0;
    float X = 0.0f;
    float Y = 0.0f;
    float Tele_x = 0.0f;
    float Tele_y = 0.0f;
    float Tele_angle = 0.0f;
};

struct BranchEntry
{
    uint8 fieldId;
    float rareChance;
    uint32 currencyId;
    uint32 keystoneId;
};

struct BranchData
{
    uint8 CompletedRares;
    uint32 Project;
};

struct ProjectEntry
{
    uint16 entry;
    uint8 branch;
    uint8 rarity;
    uint32 reqSkill;
    uint32 fragments;
    uint8 keystone;
    uint32 spell;
};

class TC_GAME_API ArchaeologyMgr
{
    public:
        static ArchaeologyMgr* instance();
        void LoadData();

        // Site Functionality
        uint16 GetNewSite(Continent continent, std::array<SiteData, 16>& sites, bool extended, uint32 playerLevel);
        bool SetSiteCoords(SiteData &site);
        uint32 GetSiteType(uint16 entry);

        // Project Functionality
        uint8 Currency2BranchId(uint32 currencyId) { return _currencyMap[currencyId]; }
        BranchEntry const* GetBranchEntry(uint8 branchId) { return &_branchMap[branchId]; }
        ProjectEntry const* GetProjectEntry(uint16 projectId) { return &_projects[projectId]; }

        bool IsRareProject(uint16 project) { return _projects[project].rarity >= ITEM_QUALITY_RARE; }
        uint16 GetNewProject(uint8 branchId, BranchData* branch, std::map<uint16, std::pair<int32, int32>> *completedMap, uint32 PlayerSkill);

    private:
        ArchaeologyMgr();
        ~ArchaeologyMgr();

        bool isSiteValid(SiteData *sites, uint16 entry);

        std::map<uint32, std::vector<SiteEntry>>            _siteMap;
        std::map<uint16, SitePolygonGraph*>                 _polygonMap;
        std::map<uint16, uint32>                            _objectMap;

        std::map<uint32 /*currencyId*/, uint8 /*branchId*/> _currencyMap;
        std::map<uint8 /*branchId*/, BranchEntry>           _branchMap;

        std::map<uint16, ProjectEntry>                      _projects;
        std::map<uint8, std::vector<uint16>>                _commonProjects;
        std::map<uint8, std::vector<uint16>>                _rareProjects;
};

#define sArchaeologyMgr ArchaeologyMgr::instance()

#endif
