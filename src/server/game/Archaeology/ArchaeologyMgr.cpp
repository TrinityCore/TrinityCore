/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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
#include "Map.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DBCEnums.h"
#include "Player.h"
#include "Log.h"
#include "Common.h"
#include <Random.h>

ArchaeologyMgr::ArchaeologyMgr() { }

ArchaeologyMgr::~ArchaeologyMgr() { }

void ArchaeologyMgr::LoadDigsites()
{
    uint32 oldMSTime = getMSTime();

    mResearchDigsitesMap.clear();

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_ARCHAEOLOGY_DIGSITES);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 archaeology digsites. DB table `archaeology_digsites` is empty.");
        return;
    }

    uint32 digCount = 0;

    do
    {
        Field* fields = result->Fetch();
        uint32 digid = fields[0].GetUInt16();

        if (!sResearchSiteStore.LookupEntry(digid))
        {
            TC_LOG_INFO("server.loading", "ArchaeologyMgr: Digsite (id: %u) found in table `archaeology_digsites` but does not exist in DBC, skipped!.", digid);
            continue;
        }

        ResearchSiteEntry const *rd = sResearchSiteStore.LookupEntry(digid);
        ResearchDigsitesEntry temp;

        temp.id               = fields[0].GetUInt16();
        temp.mapId            = uint16(rd->MapId);
        temp.minLevel         = fields[1].GetUInt8();
        temp.minSkillLevel    = fields[2].GetUInt16();
        temp.currencyId       = fields[3].GetUInt16();
        temp.QuestPoitBlobId  = uint16(rd->QuestPoiBlobId);

        mResearchDigsitesMap.insert(DigsitesMap::value_type(digid, temp));
        ++digCount;

    } while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u archaeology digsites in %u ms", digCount, GetMSTimeDiffToNow(oldMSTime));
}

void ArchaeologyMgr::InitBranch(Player* player, uint32 currencyId)
{
    if (!player->HasSkill(SKILL_ARCHAEOLOGY))
        return;

    if (IsActiveBranch(player, currencyId))
        return;

    uint16 selectProject = 0;
    uint32 count = 0;
    std::vector<uint16> BranchProjects;

    for(uint32 i = 0; i < 9; ++i)
        if (player->GetUInt16Value(ACTIVE_PLAYER_FIELD_PROFESSION_SKILL_LINE + i / 2, i % 2))
            count = i + 1;

    for(uint32 i = 0; i < sResearchBranchStore.GetNumRows(); ++i)
    {
        ResearchBranchEntry const* ab = sResearchBranchStore.LookupEntry(i);
        if (!ab || ab->CurrencyId != currencyId)
            continue;

        for(uint32 i = 0; i < sResearchProjectStore.GetNumRows(); ++i)
        {
            ResearchProjectEntry const* rs = sResearchProjectStore.LookupEntry(i);

            if (!rs || rs->ResearchBranchId != ab->Id || GetArtifactSkillReqLevel(uint32(rs->SpellId)) > player->GetBaseSkillValue(SKILL_ARCHAEOLOGY))
                continue;

            BranchProjects.push_back(rs->Id);
        }

        selectProject = BranchProjects[urand(0, BranchProjects.size()-1)];
        player->SetUInt16Value(ACTIVE_PLAYER_FIELD_PROFESSION_SKILL_LINE + count / 2, count % 2, selectProject);
        BranchProjects.clear();
    }
}

void ArchaeologyMgr::ChangeDigsite(Player* player, uint8 memId)
{
    std::vector<uint16> SitesInMap;
    std::vector<uint32> digsites = player->GetDynamicValues(ACTIVE_PLAYER_DYNAMIC_FIELD_RESERACH_SITE);

    for(DigsitesMap::iterator itr = mResearchDigsitesMap.begin(); itr != mResearchDigsitesMap.end(); ++itr)
    {
        bool isActiveDigsite = false;

        ArchaeologyMgr::ResearchDigsitesEntry DigsiteInfo = itr->second;

        if (player->GetMapId() != DigsiteInfo.mapId || DigsiteInfo.minLevel > player->getLevel() || DigsiteInfo.minSkillLevel > player->GetSkillValue(SKILL_ARCHAEOLOGY))
            continue;

        for (uint8 i = 0; i < 24; ++i)
        {
            if (DigsiteInfo.id != digsites[i])
                continue;

            isActiveDigsite = true;
        }

        if (isActiveDigsite)
            continue;

        SitesInMap.push_back(DigsiteInfo.id);
    }

    uint16 selectDigsite = SitesInMap[urand(0, SitesInMap.size()-1)];

    player->SetDynamicValue(ACTIVE_PLAYER_DYNAMIC_FIELD_RESERACH_SITE, memId, selectDigsite);
    player->GetArchaeologyMgr().SetDigsiteId(memId, selectDigsite);

    std::vector<uint32> tempContainer;

    digsites.erase(digsites.begin()+memId);
    digsites.emplace(digsites.begin()+memId, selectDigsite);

    digsites.swap(tempContainer);

    player->ClearDynamicValue(ACTIVE_PLAYER_DYNAMIC_FIELD_RESERACH_SITE);

    for (uint32 i = 0; i < tempContainer.size(); ++i)
    {
        player->AddDynamicValue(ACTIVE_PLAYER_DYNAMIC_FIELD_RESERACH_SITE, tempContainer[i]);
        player->AddDynamicValue(ACTIVE_PLAYER_DYNAMIC_FIELD_RESEARCH_SITE_PROGRESS, 0);

        player->GetArchaeologyMgr().SetDigsitePosition(i, 0, 0, 0);
    }

    tempContainer.clear();

    SitesInMap.clear();
}

void ArchaeologyMgr::AddDigsitesToMap(Player* player, uint32 mapId)
{
    if (!player->HasSkill(SKILL_ARCHAEOLOGY))
        return;

    std::vector<uint16> SitesInMap;
    uint8 count;

    switch(mapId)
    {
        case 0:   count = 0; break;
        case 1:   count = 4; break;
        case 530: count = 8; break;
        case 571: count = 12; break;
        default:  return;
    }

    for(DigsitesMap::iterator itr = mResearchDigsitesMap.begin(); itr != mResearchDigsitesMap.end(); ++itr)
    {
        ArchaeologyMgr::ResearchDigsitesEntry DigsiteInfo = itr->second;

        if (DigsiteInfo.mapId != mapId || DigsiteInfo.minLevel > player->getLevel() || DigsiteInfo.minSkillLevel > player->GetSkillValue(SKILL_ARCHAEOLOGY))
            continue;

        SitesInMap.push_back(DigsiteInfo.id);
    }

    if (!SitesInMap.size())
        return;

    for(uint32 addedsites = 0; addedsites < 4; ++addedsites)
    {
        bool isActiveDigsite = false;
        uint16 selectDigsite = 0;

        do
        {
            isActiveDigsite = false;
            selectDigsite = SitesInMap[urand(0, SitesInMap.size()-1)];
            std::vector<uint32> const& site_now = player->GetDynamicValues(ACTIVE_PLAYER_DYNAMIC_FIELD_RESERACH_SITE);
            uint32 offset = std::find(site_now.begin(), site_now.end(), selectDigsite) - site_now.begin();

            for(uint32 i = 0; i < 16; ++i)
            {
                if (offset != selectDigsite)
                    continue;

                isActiveDigsite = true;
            }
        }
        while (isActiveDigsite);

        player->AddDynamicValue(ACTIVE_PLAYER_DYNAMIC_FIELD_RESERACH_SITE, selectDigsite);
        player->AddDynamicValue(ACTIVE_PLAYER_DYNAMIC_FIELD_RESEARCH_SITE_PROGRESS, 0);
        ++count;
    }

    SitesInMap.clear();
}

bool ArchaeologyMgr::IsActiveBranch(Player* player, uint32 currencyId)
{
    for(uint32 i=0; i < 9; ++i)
    {
        if (player->GetUInt16Value(ACTIVE_PLAYER_FIELD_PROFESSION_SKILL_LINE + i / 2, i % 2))
        {
            uint16 projectId = player->GetUInt16Value(ACTIVE_PLAYER_FIELD_PROFESSION_SKILL_LINE + i / 2, i % 2);
            ResearchProjectEntry const* rs = sResearchProjectStore.LookupEntry(projectId);
            ResearchBranchEntry const* ab = sResearchBranchStore.LookupEntry(rs->ResearchBranchId);

            if (ab->CurrencyId == currencyId)
                return true;
        }
    }
    return false;
}

void ArchaeologyMgr::GenerateRandomPosition(Player* player, uint8 count)
{
    float x, y, z;
    Position treasurePos = player->GetPosition();
    uint8 memId = player->GetArchaeologyMgr().GetDigsite(player->GetPositionX(), player->GetPositionY());

    do
    {
        player->GetRandomPoint(treasurePos, 300.0f, x, y, z);
    }
    while (player->GetArchaeologyMgr().GetDigsite(x, y) == -1);

    //std::vector<uint32> const& site_now = player->GetDynamicValues(PLAYER_DYNAMIC_FIELD_RESEARCH_SITE);

    player->GetArchaeologyMgr().SetDigsitePosition(memId, x, y, count);
}

int ArchaeologyMgr::GetCurrencyId(uint16 digsiteId)
{
    DigsitesMap::iterator itr = mResearchDigsitesMap.find(digsiteId);
    return uint16(itr->second.currencyId);
}

int ArchaeologyMgr::GetArtifactSkillReqLevel(uint32 spellId)
{
    uint8 reqSkillLevel = 1;

    PreparedStatement* stmt = WorldDatabase.GetPreparedStatement(WORLD_SEL_ARCHAEOLOGY_ARTIFACT);
    stmt->setUInt32(0, spellId);
    PreparedQueryResult result = WorldDatabase.Query(stmt);

    if (result)
    {
        Field* fields = result->Fetch();
        reqSkillLevel = fields[0].GetUInt8();
    }

    return reqSkillLevel;
}
