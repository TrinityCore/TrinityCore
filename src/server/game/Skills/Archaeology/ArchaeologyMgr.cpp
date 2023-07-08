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

#include "ArchaeologyMgr.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "Log.h"
#include "Random.h"
#include "SitePolygonGraph.h"
#include "SpellMgr.h"
#include "Timer.h"

ArchaeologyMgr::ArchaeologyMgr()
{
}

ArchaeologyMgr::~ArchaeologyMgr()
{
}

ArchaeologyMgr* ArchaeologyMgr::instance()
{
    static ArchaeologyMgr instance;
    return &instance;
}

void ArchaeologyMgr::LoadData()
{
    uint32 oldMSTime = getMSTime();
    std::list<std::pair<uint16, uint32> > sites;

    QueryResult result = WorldDatabase.Query("SELECT Id, MapId, QuestPOI, ReqSkill, MinLevel, GameobjectEntry FROM archaeology_sites");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 archaeology sites. DB table `archaeology_site` is empty!");
        return;
    }

    uint32 count = 0;
    do
    {
        Field* fields = result->Fetch();
        SiteEntry entry;
        entry.id = fields[0].GetUInt16();
        entry.mapId = fields[1].GetUInt32();
        entry.questPOI = fields[2].GetUInt16();
        entry.reqSkill = fields[3].GetUInt32();
        entry.minLevel = fields[4].GetUInt32();
        _objectMap[entry.id] = fields[5].GetUInt32();

        switch (entry.mapId)
        {
        case 0:
            _siteMap[CONT_EASTERN + COUNT_CONT].push_back(entry);

            if (entry.reqSkill < 450)
                _siteMap[CONT_EASTERN].push_back(entry);
            break;
        case 1:
            _siteMap[CONT_KALIMDOR + COUNT_CONT].push_back(entry);

            if (entry.reqSkill < 450)
                _siteMap[CONT_KALIMDOR].push_back(entry);
            break;
        case 530:
            _siteMap[CONT_OUTLAND].push_back(entry);
            break;
        case 571:
            _siteMap[CONT_NORTHREND].push_back(entry);
            break;
        }

        sites.push_back(std::pair<uint16, uint32>(entry.id, entry.questPOI));
        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u archaeology sites in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

    oldMSTime = getMSTime();
    count = 0;

    for (uint32 i = 0; i < sQuestPOIPointStore.GetNumRows(); i++)
    {
        const QuestPOIPointEntry* entry = sQuestPOIPointStore.LookupEntry(i);
        if (!entry)
            continue;

        for (std::list<std::pair<uint16, uint32> >::iterator itr = sites.begin(); itr != sites.end();)
        {
            if (itr->second == entry->QuestPOIBlobID)
            {
                uint16 site = itr->first;
                uint16 poiRel = itr->second;

                if (_polygonMap[site])
                {
                    TC_LOG_ERROR("server.loading", "Archaeology: Tried to overwrite polygonData of site %u", site);
                    break;
                }

                // Create Site Polygon
                _polygonMap[site] = new SitePolygonGraph();
                _polygonMap[site]->add_node(entry->X, entry->Y);

                for (uint32 j = 1; j < 12; j++)
                {
                    entry = sQuestPOIPointStore.LookupEntry(++i);
                    if (poiRel != entry->QuestPOIBlobID)
                    {
                        TC_LOG_ERROR("server.loading", "Archaeology: Tried to use POI %u not related to site %u", entry->ID, poiRel);
                        break;
                    }

                    // Add new perimeter point
                    _polygonMap[site]->add_node(entry->X, entry->Y);
                }

                // Generate ALL inscribed and boundary geometries for the polygon!
                _polygonMap[site]->finalize_polygon();

                // NEXT!
                count++;
                sites.erase(itr++);
            }
            else
                itr++;
        }
    }

    for (std::list<std::pair<uint16, uint32> >::iterator itr = sites.begin(); itr != sites.end(); itr++)
        TC_LOG_ERROR("player.skills", "Archaeology: SiteEntry:%u links at POIBlob:%u which does not exist", itr->first, itr->second);

    TC_LOG_INFO("server.loading", ">> Loaded %u archaeology site polygons in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

    oldMSTime = getMSTime();
    count = 0;

    for (uint32 branchId = 0; branchId < sResearchBranchStore.GetNumRows(); branchId++)
        if (const ResearchBranchEntry* branchEntry = sResearchBranchStore.LookupEntry(branchId))
        {
            if (branchEntry->CurrencyID == 0)
                continue;

            _currencyMap[branchEntry->CurrencyID] = branchId;

            BranchEntry branch;
            branch.fieldId = ++count;
            branch.rareChance = 0;
            branch.currencyId = branchEntry->CurrencyID;
            branch.keystoneId = branchEntry->ItemID;
            _branchMap[branchId] = branch;
        }

    TC_LOG_INFO("server.loading", ">> Loaded %u archaeology branches in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

    oldMSTime = getMSTime();
    count = 0;

    std::map<uint8, uint8> rareCount, epicCount;

    result = WorldDatabase.Query("SELECT Entry, Branch, Rarity, ReqSkill, Fragments, Keystone, Spell FROM archaeology_projects");
    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 archaeology projects. DB table `archaeology_projects` is empty!");
        return;
    }

    do
    {
        Field* fields = result->Fetch();

        uint16 entry = fields[0].GetUInt16();

        ProjectEntry project;
        project.entry = entry;
        project.branch = fields[1].GetUInt8();
        project.rarity = fields[2].GetUInt8();
        project.reqSkill = fields[3].GetUInt16();
        project.fragments = fields[4].GetUInt8();
        project.keystone = fields[5].GetUInt8();
        project.spell = fields[6].GetUInt32();

        _projects[entry] = project;

        if (ITEM_QUALITY_RARE > project.rarity)
            _commonProjects[project.branch].push_back(entry);
        else
        {
            _rareProjects[project.branch].push_back(entry);
            if (project.rarity == ITEM_QUALITY_RARE)
                rareCount[project.branch]++;
            else
                epicCount[project.branch]++;
        }
        ++count;
    }
    while (result->NextRow());
    TC_LOG_INFO("server.loading", ">> Loaded %u archaeology projects in %u ms", count, GetMSTimeDiffToNow(oldMSTime));

    oldMSTime = getMSTime();
    count = 0;

    for (std::map<uint8, BranchEntry>::iterator itr = _branchMap.begin(); itr != _branchMap.end(); ++itr)
    {
        uint8 entry = itr->first;
        float chance = 1.0f;
        chance -= float(epicCount[entry]) * EPIC_CHANCE;
        chance /= float(rareCount[entry]);
        itr->second.rareChance = std::min(chance, MAX_RARE_CHANCE);

        ++count;
    }
    TC_LOG_INFO("server.loading", ">> Calculated %u archaeology branch chances in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}

bool ArchaeologyMgr::isSiteValid(SiteData* sites, uint16 entry)
{
    for (uint32 i = 0; i < CONTINENT_SITES; ++i)
        if (sites[i].Entry == entry)
            return false;

    return true;
}

uint16 ArchaeologyMgr::GetNewSite(Continent continent, std::array<SiteData, 16>& sites, bool extended, uint32 playerLevel)
{
    std::vector<SiteEntry>* siteList;
    uint32 offset = continent* CONTINENT_SITES;
    uint16 entry;

    if (extended)
        siteList = &(_siteMap[continent + COUNT_CONT]);
    else
        siteList = &(_siteMap[continent]);

    do
    {
        uint32 position = urand(0, siteList->size() - 1);
        entry = uint16(siteList->at(position).id);
        if (siteList->at(position).minLevel > playerLevel)
            continue;
    }
    while (!isSiteValid(&(sites[offset]), entry));

    return entry;
}

bool ArchaeologyMgr::SetSiteCoords(SiteData &site)
{
    if (SitePolygonGraph* poly = _polygonMap[site.Entry])
    {
        // Calculate random point of interest
        SitePolygonGraphNode node = poly->randomize_poi();

        // Get random point into Polygon
        site.X = node.getX();
        site.Y = node.getY();

        return true;
    }
    return false;
}

uint32 ArchaeologyMgr::GetSiteType(uint16 entry)
{
    if (!_objectMap[entry])
        TC_LOG_ERROR("player.skills", "Archaeology: Entry %u has no find object Type!", entry);

    return _objectMap[entry];
}

uint16 ArchaeologyMgr::GetNewProject(uint8 branchId, BranchData* branch, std::map<uint16, std::pair<int32, int32>>* completedMap, uint32 playerSkill)
{
    std::vector<uint16>* _rares = &_rareProjects[branchId];
    std::vector<uint16>* _commons = &_commonProjects[branchId];

    float rareChance = float(_rares->size() - branch->CompletedRares) / float(_commons->size() + _rares->size());
    float roll1 = frand(.0f, 1.0f);

    // Are we eligible for a Rare Project ?
    if (rareChance > roll1)
    {
        float roll2 = float(rand_norm());
        float rareChance = _branchMap[branchId].rareChance;

        for (std::vector<uint16>::iterator itr = _rares->begin(); itr != _rares->end(); ++itr)
        {
            float chance = (_projects[*itr].rarity == ITEM_QUALITY_RARE) ? rareChance : EPIC_CHANCE;

            // Are we in our choose range ?
            if (chance < roll2)
            {
                roll2 -= chance;
                continue;
            }

            // Do we have the required SkillLevel ?
            if (_projects[*itr].reqSkill > playerSkill)
                break;

            // Did we already complete the artifact ?
            if (completedMap->find(*itr) != completedMap->end())
                break;

            return *itr;
        }
    }

    // did we already complete all commons of the branch
    uint32 begin = urand(0, _commons->size() - 1);
    uint32 end = (begin == 0) ? _commons->size() - 1 : begin - 1;

    uint32 secondArtifact = 0;

    for (uint16 itr = begin; itr != end; itr = (itr + 1) % _commons->size())
    {
        uint16 projectId = _commons->at(itr);

        // Do we have the required SkillLevel ?
        if (_projects[projectId].reqSkill > playerSkill)
            continue;

        // Did we already complete the artifact ?
        if (completedMap->find(projectId) != completedMap->end())
        {
            if (!secondArtifact)
                secondArtifact = projectId;

            continue;
        }

        return _projects[projectId].entry;
    }
    // looks like we didn't find an eligible common artifact => relax the non repetitive restriction
    return secondArtifact;
}
