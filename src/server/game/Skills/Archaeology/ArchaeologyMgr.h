/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include <map>
#include <vector>
#include "SitePolygonGraph.h"
#include "Define.h"

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
    uint16 entry;
    uint16 state;
    float x;
    float y;
    float tele_x;
    float tele_y;
    float tele_angle;
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
    uint8 branchId;
    uint8 completedRares;
    uint32 project;
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

namespace archaeology
{

class TC_GAME_API ArchaeologyMgr
{
public:
    static ArchaeologyMgr* instance();
    void LoadData();

    // Site Functionality
    static uint32 GetFindCurrency(uint32 go_entry);
    uint16 GetNewSite(Continent continent, SiteData *sites, bool extended, uint32 playerLevel);
    bool SetSiteCoords(SiteData &site);
    uint32 GetSiteType(uint16 entry);

    // Project Functionality
    uint8 Currency2BranchId(uint32 currencyId) { return _currencyMap[currencyId]; }
    const BranchEntry *GetBranchEntry(uint8 branchId) { return &_branchMap[branchId]; }
    const ProjectEntry *GetProjectEntry(uint16 projectId) { return &_projects[projectId]; }

    bool IsRareProject(uint16 project) { return _projects[project].rarity >= ITEM_QUALITY_RARE; }
    uint16 GetNewProject(BranchData *branch, std::map<uint16, std::pair<int32, int32> > *completedMap, uint32 PlayerSkill);

private:
    ArchaeologyMgr();
    ~ArchaeologyMgr();

    bool isSiteValid(SiteData *sites, uint16 entry);

    std::map<uint32, std::vector<SiteEntry> >   _siteMap;
    std::map<uint16, SitePolygonGraph* >        _polygonMap;
    std::map<uint16, uint32>                    _objectMap;

    std::map<uint32, uint8>                     _currencyMap;       // currencyId -> branchId
    std::map<uint8, BranchEntry>                _branchMap;    // branchId -> BranchEntry

    std::map<uint16, ProjectEntry>              _projects;
    std::map<uint8, std::vector<uint16> >       _commonProjects;
    std::map<uint8, std::vector<uint16> >       _rareProjects;
};

} // namespace archaeology

#define sArchaeologyMgr archaeology::ArchaeologyMgr::instance()

#endif
