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

#include "AchievementMgr.h"
#include "ArchaeologyMgr.h"
#include "ArchaeologyPlayerMgr.h"
#include "MiscPackets.h"
#include "ObjectMgr.h"

ArchaeologyPlayerMgr::ArchaeologyPlayerMgr(Player* player) : m_player(player) { }

void ArchaeologyPlayerMgr::LoadArchaeologyDigSites(PreparedQueryResult result)
{
    if (!result)
        return;

    uint8 mpos = 0;

    do
    {
        Field* fields = result->Fetch();
        uint16 digsite = fields[0].GetUInt16();
        float pos_x = fields[1].GetFloat();
        float pos_y = fields[2].GetFloat();
        uint8 count = fields[3].GetUInt8();

        std::vector<uint32> digsites = GetPlayer()->GetDynamicValues(ACTIVE_PLAYER_DYNAMIC_FIELD_RESERACH_SITE);

        GetPlayer()->AddDynamicValue(ACTIVE_PLAYER_DYNAMIC_FIELD_RESERACH_SITE, digsite);
        GetPlayer()->AddDynamicValue(ACTIVE_PLAYER_DYNAMIC_FIELD_RESEARCH_SITE_PROGRESS, 0);
        SetDigsitePosition(mpos, pos_x, pos_y, count);

        ++mpos;
    }
    while (result->NextRow());
}

void ArchaeologyPlayerMgr::LoadArchaeologyBranchs(PreparedQueryResult result)
{
    if (!result)
        return;

    uint32 mpos = 0;

    do
    {
        Field* fields = result->Fetch();
        uint16 branch = fields[0].GetUInt16();
        GetPlayer()->SetUInt16Value(ACTIVE_PLAYER_FIELD_PROFESSION_SKILL_LINE + mpos / 2, mpos % 2, branch);
        ++mpos;
    }
    while (result->NextRow());
}

void ArchaeologyPlayerMgr::LoadArchaeologyHistory(PreparedQueryResult result)
{
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();

        ArchaeologyHistory artifact;
        artifact.time = fields[1].GetUInt32();
        artifact.count = fields[2].GetUInt16();
        m_ArchaeologyHistoryMap.insert(ArchaeologyHistoryMap::value_type(fields[0].GetUInt16(), artifact));
    }
    while (result->NextRow());
}

void ArchaeologyPlayerMgr::SaveArchaeologyDigSites(SQLTransaction& trans)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ARCHAEOLOGY_DIGSITES);
    stmt->setUInt64(0, GetPlayer()->GetGUID().GetCounter());
    trans->Append(stmt);
    std::vector<uint32> digsites = GetPlayer()->GetDynamicValues(ACTIVE_PLAYER_DYNAMIC_FIELD_RESERACH_SITE);

    for (uint8 i = 0; i < digsites.size(); ++i)
    {
        uint16 digsiteId = digsites[i];
        Digsite digsite = GetDigsitePosition(i);
        PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ARCHAEOLOGY_DIGSITE);

        stmt->setUInt64(0, GetPlayer()->GetGUID().GetCounter());
        stmt->setUInt16(1, digsiteId);
        stmt->setFloat(2, digsite.x);
        stmt->setFloat(3, digsite.y);
        stmt->setUInt8(4, digsite.digCount);

        trans->Append(stmt);
    }
}

void ArchaeologyPlayerMgr::SaveArchaeologyBranchs(SQLTransaction& trans)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ARCHAEOLOGY_BRANCHS);
    stmt->setUInt64(0, GetPlayer()->GetGUID().GetCounter());
    trans->Append(stmt);

    for(uint32 i=0; i < 9; ++i)
    {
        if (GetPlayer()->GetUInt16Value(ACTIVE_PLAYER_FIELD_PROFESSION_SKILL_LINE + i / 2, i % 2))
        {
            uint16 projectId = GetPlayer()->GetUInt16Value(ACTIVE_PLAYER_FIELD_PROFESSION_SKILL_LINE + i / 2, i % 2);

            PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ARCHAEOLOGY_BRANCH);
            stmt->setUInt64(0, GetPlayer()->GetGUID().GetCounter());
            stmt->setUInt16(1, projectId);
            trans->Append(stmt);
        }
    }
}

void ArchaeologyPlayerMgr::SaveArchaeologyHistory(SQLTransaction& trans)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_DEL_ARCHAEOLOGY_HISTORY);
    stmt->setUInt64(0, GetPlayer()->GetGUID().GetCounter());
    trans->Append(stmt);

    if (!m_ArchaeologyHistoryMap.empty())
    {
        for (ArchaeologyHistoryMap::iterator itr = m_ArchaeologyHistoryMap.begin(); itr != m_ArchaeologyHistoryMap.end(); ++itr)
        {
            stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ARCHAEOLOGY_HISTORY);
            stmt->setUInt64(0, GetPlayer()->GetGUID().GetCounter());
            stmt->setUInt16(1, itr->first);
            stmt->setUInt32(2, itr->second.time);
            stmt->setUInt16(3, itr->second.count);
            trans->Append(stmt);
        }
    }
}

Digsite ArchaeologyPlayerMgr::GetDigsitePosition(uint8 memId)
{
    DigsiteMap::iterator itr = m_DigsiteMap.find(memId);

    Digsite digsite;

    if (itr == m_DigsiteMap.end())
    {
        digsite.x = float(0);
        digsite.y = float(0);
        digsite.digCount = uint8(0);
    }
    else
    {
        digsite.x = itr->second.x;
        digsite.y = itr->second.y;
        digsite.digCount = itr->second.digCount;
    }

    return digsite;
}

void ArchaeologyPlayerMgr::SetDigsitePosition(uint8 memId, float x, float y, uint8 digCount)
{
    DigsiteMap::iterator itr = m_DigsiteMap.find(memId);

    if (itr != m_DigsiteMap.end())
        m_DigsiteMap.erase(m_DigsiteMap.find(memId));

    Digsite digsite;

    digsite.x = x;
    digsite.y = y;
    digsite.digCount = digCount;

    m_DigsiteMap.insert(DigsiteMap::value_type(memId, digsite));
}

void ArchaeologyPlayerMgr::SetDigsiteId(uint8 memId, uint16 digsiteId)
{
    uint16 digid = digsiteId;

    DigsiteMap::iterator itr = m_DigsiteMap.find(memId);

    if (itr != m_DigsiteMap.end())
        m_DigsiteMap.erase(m_DigsiteMap.find(memId));

    Digsite digsite;

    digsite.digsiteId = digid;
    digsite.x = 0;
    digsite.y = 0;
    digsite.digCount = 0;

    m_DigsiteMap.insert(DigsiteMap::value_type(memId, digsite));
}

int ArchaeologyPlayerMgr::GetDigsite(int32 x, int32 y)
{
    uint16 digsiteID = 0;
    std::vector<uint16> PlayerDigsites;
    std::vector<uint32> const& digsites = GetPlayer()->GetDynamicValues(ACTIVE_PLAYER_DYNAMIC_FIELD_RESERACH_SITE);

    for (uint32 memId = 0; memId < digsites.size(); ++memId)
    {
        digsiteID = digsites[memId];

        if (digsiteID <= 0)
            continue;

        ResearchSiteEntry const* site = sResearchSiteStore.LookupEntry(digsiteID);

        if (!site)
            continue;

        for (uint32 i = 0; i < sQuestPOIPointStore.GetNumRows(); i++)
        {
            QuestPOIPointEntry const* poi = sQuestPOIPointStore.LookupEntry(i);

            if (!poi)
                continue;

            if (poi->QuestPoiBlobId != site->QuestPoiBlobId)
                continue;

            DigsitePolygon.push_back(std::make_pair(poi->X, poi->Y));
        }

        float x1, x2, y2;
        int crs = 0;

        if (DigsitePolygon.size() == 0)
            continue;

        for (int i = 0; i < (int)DigsitePolygon.size(); i++)
        {
            if (DigsitePolygon[i].first < DigsitePolygon[(i + 1) % DigsitePolygon.size()].first)
            {
                x1 = DigsitePolygon[i].first;
                x2 = DigsitePolygon[(i + 1) % DigsitePolygon.size()].first;
            }
            else
            {
                x1 = DigsitePolygon[(i + 1) % DigsitePolygon.size()].first;
                x2 = DigsitePolygon[i].first;
            }

            if (x > x1 && x <= x2 && (y < DigsitePolygon[i].second || y <= DigsitePolygon[(i + 1) % DigsitePolygon.size()].second))
            {
                float dx = DigsitePolygon[(i + 1) % DigsitePolygon.size()].first - DigsitePolygon[i].first;
                float dy = DigsitePolygon[(i + 1) % DigsitePolygon.size()].second - DigsitePolygon[i].second;
                float k;

                if (fabs(dx) < 0.000001)
                    k = float(0xFFFFFFFF);
                else
                    k = dy / dx;

                float m = DigsitePolygon[i].second - k * DigsitePolygon[i].first;
                y2 = k * x + m;

                if (y <= y2)
                    crs++;
            }
        }

        DigsitePolygon.clear();

        if (crs % 2)
            return memId;
    }

    return -1;
}

bool ArchaeologyPlayerMgr::IsCurrentArtifactSpell(int32 spellId)
{
    for (uint32 i = 0; i < 9; ++i)
    {
        if (GetPlayer()->GetUInt16Value(ACTIVE_PLAYER_FIELD_PROFESSION_SKILL_LINE + i / 2, i % 2))
        {
            for (uint32 i = 0; i < sResearchProjectStore.GetNumRows(); ++i)
            {
                ResearchProjectEntry const* rs = sResearchProjectStore.LookupEntry(i);

                if (!rs || rs->SpellId != spellId)
                    continue;

                return true;
            }
        }
    }
    return false;
}

void ArchaeologyPlayerMgr::CompleteArtifact(uint32 spellId)
{
    uint32 ftime = time(NULL);
    uint32 count = 0;

    for (uint32 memId = 0; memId < 9; ++memId)
    {
        if (GetPlayer()->GetUInt16Value(ACTIVE_PLAYER_FIELD_PROFESSION_SKILL_LINE + memId / 2, memId % 2))
        {
            uint16 artifactId = GetPlayer()->GetUInt16Value(ACTIVE_PLAYER_FIELD_PROFESSION_SKILL_LINE + memId / 2, memId % 2);

            for (uint32 i = 0; i < sResearchProjectStore.GetNumRows(); ++i)
            {
                ResearchProjectEntry const* rs = sResearchProjectStore.LookupEntry(i);

                if (!rs || rs->Id != artifactId || rs->SpellId != int32(spellId))
                    continue;

                for (uint32 i = 0; i < sResearchBranchStore.GetNumRows(); ++i)
                {
                    ResearchBranchEntry const* ab = sResearchBranchStore.LookupEntry(i);

                    if (!ab || ab->Id != rs->ResearchBranchId)
                        continue;

                    ArchaeologyHistoryMap::iterator itr = m_ArchaeologyHistoryMap.find(artifactId);
                    if (itr != m_ArchaeologyHistoryMap.end())
                    {
                        ftime = itr->second.time;
                        count = itr->second.count + 1;
                        m_ArchaeologyHistoryMap.erase(artifactId);
                    }

                    ArchaeologyHistory artifact;
                    artifact.time = ftime;
                    artifact.count = count ? count : 1;
                    m_ArchaeologyHistoryMap.insert(ArchaeologyHistoryMap::value_type(artifactId, artifact));

                    GetPlayer()->GetAchievementMgr()->UpdateCriteria(CRITERIA_TYPE_COMPLETE_ARCHAEOLOGY_PROJECTS, artifactId);

                    WorldPackets::Misc::ResearchComplete researchComplete;
                    researchComplete.researchHistory.id = artifactId;
                    researchComplete.researchHistory.time = artifact.time;
                    researchComplete.researchHistory.count = artifact.count;
                    GetPlayer()->SendDirectMessage(researchComplete.Write());

                    std::vector<uint16> BranchProjects;

                    for (uint32 i = 0; i < sResearchProjectStore.GetNumRows(); ++i)
                    {
                        ResearchProjectEntry const* rs2 = sResearchProjectStore.LookupEntry(i);

                        if (!rs2 || rs2->ResearchBranchId != ab->Id || rs2->Id == artifactId || sArchaeologyMgr->GetArtifactSkillReqLevel(uint32(rs2->SpellId)) > GetPlayer()->GetBaseSkillValue(SKILL_ARCHAEOLOGY))
                            continue;

                        BranchProjects.push_back(rs2->Id);
                    }

                    uint16 selectProject = BranchProjects[urand(0, BranchProjects.size() - 1)];
                    GetPlayer()->SetUInt16Value(ACTIVE_PLAYER_FIELD_PROFESSION_SKILL_LINE + memId / 2, memId % 2, selectProject);
                    BranchProjects.clear();
                    return;
                }
            }
        }
    }
}

bool ArchaeologyPlayerMgr::IsFirstProjectComplete(uint32 artifactId)
{
    ArchaeologyHistoryMap::iterator itr = m_ArchaeologyHistoryMap.find(artifactId);
    if (itr != m_ArchaeologyHistoryMap.end())
        if (itr->second.count == 1)
            return true;

    return false;
}
