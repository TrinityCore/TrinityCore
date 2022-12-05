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

#include "Archaeology.h"
#include "ArchaeologyPackets.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "GameTime.h"
#include "Log.h"
#include "Player.h"

void Archaeology::LoadCompletedProjectsFromDB()
{
    QueryResult result = CharacterDatabase.PQuery("SELECT project, time, count FROM character_archaeology_completed WHERE guid = %u", _player->GetGUID().GetCounter());
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint16 project = fields[0].GetUInt16();
        int32 time = fields[1].GetInt32();
        int32 count = fields[2].GetInt32();

        _completedProjects.emplace(project, std::make_pair(time, count));
    } while (result->NextRow());
}

void Archaeology::InitBranches()
{
    for (ResearchBranchEntry const* branch : sResearchBranchStore)
    {
        if (branch->CurrencyID)
        {
            BranchData& branchData = _branches[uint8(branch->ID)];
            branchData.CompletedRares = 0;
            branchData.Project = 0;
        }
    }
}

void Archaeology::LoadCurrentProjectsFromDB()
{
    InitBranches();

    QueryResult result = CharacterDatabase.PQuery("SELECT branch, project FROM character_archaeology_projects WHERE guid = %u", _player->GetGUID().GetCounter());
    if (!result)
        return;

    do
    {
        Field* fields = result->Fetch();
        uint8 branch = fields[0].GetUInt8();
        uint16 project = fields[1].GetUInt16();

        if (uint16 old_project = _branches[branch].Project)
        {
            TC_LOG_ERROR("player.skills", "ERROR - Archaeology: Tried to assign project %u to branch %u, which already holds project %u!", project, branch, old_project);
            continue;
        }

        BranchData& branchData = _branches[branch];
        branchData.Project = project;
    } while (result->NextRow());
}

void Archaeology::VisualizeBranch(uint8 position, uint16 project)
{
    if (position < MAX_PROJECTS)
        _player->SetUInt16Value(PLAYER_FIELD_RESEARCH_PROJECT_1 + (position / 2), position % 2, project);
}

void Archaeology::RegenerateBranch(uint8 branch)
{
    uint16 project = sArchaeologyMgr->GetNewProject(branch, &_branches[branch], &_completedProjects, _player->GetSkillValue(SKILL_ARCHAEOLOGY));
    _branches[branch].Project = project;

    CharacterDatabase.PExecute("REPLACE INTO character_archaeology_projects VALUES (%u, %u, %u)", _player->GetGUID().GetCounter(), branch, project);
}

void Archaeology::VerifyProjects()
{
    for (std::map<uint8, BranchData>::iterator itr = _branches.begin(); itr != _branches.end(); ++itr)
    {
        if (BranchEntry const* branch = sArchaeologyMgr->GetBranchEntry(itr->first))
        {
            uint16 project = itr->second.Project;
            if (project)
            {
                if (_completedProjects.find(project) != _completedProjects.end() && sArchaeologyMgr->IsRareProject(project))
                    RegenerateBranch(itr->first);
            }
            else if (_player->GetCurrency(branch->currencyId, false))
                RegenerateBranch(itr->first);
            else
                continue;

            VisualizeBranch(branch->fieldId, _branches[itr->first].Project);
        }
    }
}

void Archaeology::CleanProjects()
{
    CharacterDatabase.PExecute("delete from character_archaeology_projects where guid=%u", _player->GetGUID().GetCounter());

    for (uint8 i = 0; i < MAX_PROJECTS; ++i)
        VisualizeBranch(i, 0);

    _branches.clear();
}

void Archaeology::ActivateBranch(uint8 branchId, bool force)
{
    if (_branches[branchId].Project && !force)
        return;

    RegenerateBranch(branchId);
    VisualizeBranch(sArchaeologyMgr->GetBranchEntry(branchId)->fieldId, _branches[branchId].Project);
}

bool Archaeology::ProjectExists(uint16 projectId)
{
    if (ProjectEntry const* project = sArchaeologyMgr->GetProjectEntry(projectId))
        return (_branches[project->branch].Project == projectId);

    return false;
}

bool Archaeology::ProjectCompleteable(uint16 projectId)
{
    if (!_archData)
        return false;

    ProjectEntry const* project = sArchaeologyMgr->GetProjectEntry(projectId);
    if (!project)
        return false;

    if (_branches[project->branch].Project != projectId)
        return false;

    BranchEntry const* branchEntry = sArchaeologyMgr->GetBranchEntry(project->branch);
    if (!branchEntry)
        return false;

    // Check Ids
    uint32 currencyId = branchEntry->currencyId;
    uint32 keystoneId = branchEntry->keystoneId;
    if (currencyId != _archData->FragId || (_archData->KeyId && _archData->KeyId != keystoneId))
        return false;

    // Project can have keystones ?
    if (project->keystone < _archData->KeyCount)
        return false;

    // Check if the given fragment/keystone usage would be enough
    if (_archData->FragCount + _archData->KeyCount * 12 != project->fragments)
        return false;

    // Check if the player has the keystones
    if (_player->GetCurrency(_archData->FragId, false) < _archData->FragCount)
        return false;

    // Check if the player has the fragments
    return (!_archData->KeyId || _player->GetItemCount(_archData->KeyId) >= _archData->KeyCount);
}

void Archaeology::CompleteProject(uint16 projectId)
{
    ProjectEntry const* project = sArchaeologyMgr->GetProjectEntry(projectId);
    ASSERT(project);
    ASSERT(_branches[project->branch].Project == projectId);
    ASSERT(_archData);

    _player->ModifyCurrency(_archData->FragId, -int32(_archData->FragCount), false, false);
    _player->DestroyItemCount(_archData->KeyId, _archData->KeyCount, true, false);

    WorldPackets::Archaeology::ResearchComplete packet;
    packet.Research.CompletionCount = 1;
    packet.Research.FirstCompleted = GameTime::GetGameTime();
    packet.Research.ProjectID = projectId;
    _player->SendDirectMessage(packet.Write());

    if (_completedProjects.find(projectId) == _completedProjects.end())
    {
        _completedProjects[projectId].first = GameTime::GetGameTime();
        _completedProjects[projectId].second = 1;

        CharacterDatabase.PExecute("REPLACE INTO character_archaeology_completed VALUES (%u, %u, %u, 1);", _player->GetGUID().GetCounter(), projectId, GameTime::GetGameTime());
    }
    else
    {
        _completedProjects[projectId].second++;

        CharacterDatabase.PExecute("UPDATE character_archaeology_completed SET count=%u WHERE guid=%u and project=%u;",
            _completedProjects[projectId].second, _player->GetGUID().GetCounter(), projectId);
    }

    _player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_COMPLETE_ARCHAEOLOGY_PROJECTS, projectId, 1);

    _archData.reset();
    ActivateBranch(project->branch, true);
}

void Archaeology::SetArchData(ArchData const& data)
{
    _archData = Trinity::make_unique<ArchData>(std::move(data));
}

void Archaeology::SendResearchHistory()
{
    WorldPackets::Archaeology::SetupResearchHistory packet;
    for (std::pair<uint16, std::pair<int32, int32>> itr : _completedProjects)
        packet.History.emplace_back(itr.first, itr.second.second, itr.second.first);

    _player->SendDirectMessage(packet.Write());
}
