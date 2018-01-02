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

#include "Archaeology.h"
#include "DBCStore.h"
#include "Player.h"

void Archaeology::LoadCompletedProjectsFromDB()
{
    QueryResult result;

    result = CharacterDatabase.PQuery("SELECT project, time, count FROM character_archaeology_completed WHERE guid=%u",
        _player->GetGUID());

    if (!result)
        return;

    do {
        Field *fields = result->Fetch();
        uint16 project = fields[0].GetUInt16();
        int32 time = fields[1].GetInt32();
        int32 count = fields[2].GetInt32();

        _completedProjects[project].first = time;
        _completedProjects[project].second = count;

    } while (result->NextRow());
}

void Archaeology::InitBranches()
{
    for (uint8 i = 0; i < sResearchBranchStore.GetNumRows(); ++i)
        if (const ResearchBranchEntry *branch = sResearchBranchStore.LookupEntry(i))
            if (branch->CurrencyID)
            {
                struct BranchData branchData;
                branchData.branchId = branch->ID;
                branchData.completedRares = 0;
                branchData.project = 0;
                _branches[i] = branchData;
            }
}

void Archaeology::LoadCurrentProjectsFromDB()
{
    QueryResult result;

    InitBranches();

    result = CharacterDatabase.PQuery("SELECT branch, project FROM character_archaeology_projects WHERE guid=%u",
        _player->GetGUID());

    if (!result)
        return;

    do {
        Field *fields = result->Fetch();
        uint8 branch = fields[0].GetUInt8();
        uint16 project = fields[1].GetUInt16();

        if (uint16 old_project = _branches[branch].project)
        {
            TC_LOG_ERROR("player.skills", "ERROR - Archaeology: Tried to assign project %u to branch %u, which already holds project %u!",
                project, branch, old_project);
            continue;
        }

        _branches[branch].project = project;
    } while (result->NextRow());
}

void Archaeology::VisualizeBranch(uint8 position, uint16 project)
{
    if (position < MAX_PROJECTS)
        _player->SetUInt16Value(PLAYER_FIELD_RESEARCH_PROJECT_1 + (position / 2), position % 2, project);
}

void Archaeology::RegenerateBranch(uint8 branch)
{
    uint16 project = sArchaeologyMgr->GetNewProject(&_branches[branch], &_completedProjects, _player->GetSkillValue(SKILL_ARCHAEOLOGY));
    _branches[branch].project = project;

    CharacterDatabase.PExecute("REPLACE INTO character_archaeology_projects VALUES (%u, %u, %u)",
        _player->GetGUID(), branch, project);
}

void Archaeology::VerifyProjects()
{
    for (std::map<uint8, BranchData>::iterator itr = _branches.begin(); itr != _branches.end(); ++itr)
        if (const BranchEntry* branch = sArchaeologyMgr->GetBranchEntry(itr->first))
        {
            uint16 project = itr->second.project;
            if (project)
            {
                if (_completedProjects.find(project) != _completedProjects.end() && sArchaeologyMgr->IsRareProject(project))
                    RegenerateBranch(itr->first);
            }
            else if (_player->GetCurrency(branch->currencyId, false))
                RegenerateBranch(itr->first);
            else
                continue;

            VisualizeBranch(branch->fieldId, _branches[itr->first].project);
        }
}

void Archaeology::CleanProjects()
{
    CharacterDatabase.PExecute("delete from character_archaeology_projects where guid=%u",
        _player->GetGUID());

    for (uint8 i = 0; i < MAX_PROJECTS; ++i)
        VisualizeBranch(i, 0);

    _branches.clear();
}

void Archaeology::ActivateBranch(uint8 branchId, bool force)
{
    if (_branches[branchId].project && !force)
        return;

    RegenerateBranch(branchId);
    VisualizeBranch(sArchaeologyMgr->GetBranchEntry(branchId)->fieldId, _branches[branchId].project);
}

bool Archaeology::ProjectExists(uint16 projectId)
{
    if (const ProjectEntry* project = sArchaeologyMgr->GetProjectEntry(projectId))
        return (_branches[project->branch].project == projectId);

    return false;
}

bool Archaeology::ProjectCompleteable(uint16 projectId)
{
    if (!archData)
        return false;

    if (const ProjectEntry* project = sArchaeologyMgr->GetProjectEntry(projectId))
        if (_branches[project->branch].project == projectId)
        {
            const BranchEntry* branchEntry = sArchaeologyMgr->GetBranchEntry(project->branch);

            // Check Ids
            uint32 currencyId = branchEntry->currencyId;
            uint32 keystoneId = branchEntry->keystoneId;
            if (currencyId != archData->fragId || (archData->keyId && archData->keyId != keystoneId))
                return false;

            // Project can have keystones ?
            if (project->keystone < archData->keyCount)
                return false;

            // Check if the given fragment/keystone usage would be enough
            if (archData->fragCount + archData->keyCount * 12 != project->fragments)
                return false;

            // Check if the player has the keystones
            if (_player->GetCurrency(archData->fragId, false) < archData->fragCount)
                return false;

            // Check if the player has the fragments
            return (!archData->keyId || _player->GetItemCount(archData->keyId) >= archData->keyCount);
        }

    return false;
}

void Archaeology::CompleteProject(uint16 projectId)
{
    const ProjectEntry *project = sArchaeologyMgr->GetProjectEntry(projectId);
    ASSERT(project);
    ASSERT(_branches[project->branch].project == projectId);
    ASSERT(archData);

    _player->ModifyCurrency(archData->fragId, -int32(archData->fragCount), false, true);
    _player->DestroyItemCount(archData->keyId, archData->keyCount, true, false);

    if (_completedProjects.find(projectId) == _completedProjects.end())
    {
        _completedProjects[projectId].first = time(NULL);
        _completedProjects[projectId].second = 1;

        CharacterDatabase.PExecute("REPLACE INTO character_archaeology_completed VALUES (%u, %u, %u, 1);",
            _player->GetGUID(), projectId, time(NULL));
    }
    else
    {
        _completedProjects[projectId].second++;

        CharacterDatabase.PExecute("UPDATE character_archaeology_completed SET count=%u WHERE guid=%u and project=%u;",
            _completedProjects[projectId].second, _player->GetGUID(), projectId);
    }

    _player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ARCHAEOLOGY_PROJECTS, projectId, 1);

    delete archData;
    ActivateBranch(project->branch, true);
}

void Archaeology::SendResearchHistory()
{
    uint32 count = _completedProjects.size();
    WorldPacket packet(SMSG_RESEARCH_SETUP_HISTORY, 4 + 4 + (4 + 4 + 4) * count);
    packet.WriteBits(count, 22);

    packet.FlushBits();

    for (std::map<uint16, std::pair<int32, int32> >::iterator itr = _completedProjects.begin(); itr != _completedProjects.end(); ++itr)
    {
        packet << int32(itr->first);
        packet << int32(itr->second.second);
        packet << uint32(itr->second.first);
    }

    _player->GetSession()->SendPacket(&packet);
}
