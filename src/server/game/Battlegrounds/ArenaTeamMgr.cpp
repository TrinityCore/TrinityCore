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

#include "Define.h"
#include "ArenaTeamMgr.h"
#include "World.h"
#include "Log.h"
#include "DatabaseEnv.h"
#include "Player.h"

ArenaTeamMgr::ArenaTeamMgr()
{
    NextArenaTeamId = 1;
}

ArenaTeamMgr::~ArenaTeamMgr()
{
    for (ArenaTeamContainer::iterator itr = ArenaTeamStore.begin(); itr != ArenaTeamStore.end(); ++itr)
        delete itr->second;
}

ArenaTeamMgr* ArenaTeamMgr::instance()
{
    static ArenaTeamMgr instance;
    return &instance;
}

// Arena teams collection
ArenaTeam* ArenaTeamMgr::GetArenaTeamById(uint32 arenaTeamId) const
{
    ArenaTeamContainer::const_iterator itr = ArenaTeamStore.find(arenaTeamId);
    if (itr != ArenaTeamStore.end())
        return itr->second;

    return nullptr;
}

ArenaTeam* ArenaTeamMgr::GetArenaTeamByName(const std::string& arenaTeamName) const
{
    std::string search = arenaTeamName;
    std::transform(search.begin(), search.end(), search.begin(), ::toupper);
    for (ArenaTeamContainer::const_iterator itr = ArenaTeamStore.begin(); itr != ArenaTeamStore.end(); ++itr)
    {
        std::string teamName = itr->second->GetName();
        std::transform(teamName.begin(), teamName.end(), teamName.begin(), ::toupper);
        if (search == teamName)
            return itr->second;
    }
    return nullptr;
}

ArenaTeam* ArenaTeamMgr::GetArenaTeamByCaptain(ObjectGuid guid) const
{
    for (ArenaTeamContainer::const_iterator itr = ArenaTeamStore.begin(); itr != ArenaTeamStore.end(); ++itr)
        if (itr->second->GetCaptain() == guid)
            return itr->second;

    return nullptr;
}

void ArenaTeamMgr::AddArenaTeam(ArenaTeam* arenaTeam)
{
    ArenaTeamStore[arenaTeam->GetId()] = arenaTeam;
}

void ArenaTeamMgr::RemoveArenaTeam(uint32 arenaTeamId)
{
    ArenaTeamStore.erase(arenaTeamId);
}

uint32 ArenaTeamMgr::GenerateArenaTeamId()
{
    if (NextArenaTeamId >= 0xFFFFFFFE)
    {
        TC_LOG_ERROR("bg.battleground", "Arena team ids overflow!! Can't continue, shutting down server. ");
        World::StopNow(ERROR_EXIT_CODE);
    }
    return NextArenaTeamId++;
}

void ArenaTeamMgr::LoadArenaTeams()
{
    uint32 oldMSTime = getMSTime();

    // Clean out the trash before loading anything
    CharacterDatabase.DirectExecute("DELETE FROM arena_team_member WHERE arenaTeamId NOT IN (SELECT arenaTeamId FROM arena_team)");       // One-time query

    //                                                        0        1         2         3          4              5            6            7           8
    QueryResult result = CharacterDatabase.Query("SELECT arenaTeamId, name, captainGuid, type, backgroundColor, emblemStyle, emblemColor, borderStyle, borderColor, "
    //      9        10        11         12           13       14
        "rating, weekGames, weekWins, seasonGames, seasonWins, `rank` FROM arena_team ORDER BY arenaTeamId ASC");

    if (!result)
    {
        TC_LOG_INFO("server.loading", ">> Loaded 0 arena teams. DB table `arena_team` is empty!");
        return;
    }

    QueryResult result2 = CharacterDatabase.Query(
        //              0              1           2             3              4                 5          6     7          8                  9
        "SELECT arenaTeamId, atm.guid, atm.weekGames, atm.weekWins, atm.seasonGames, atm.seasonWins, c.name, class, personalRating, matchMakerRating FROM arena_team_member atm"
        " INNER JOIN arena_team ate USING (arenaTeamId)"
        " LEFT JOIN characters AS c ON atm.guid = c.guid"
        " LEFT JOIN character_arena_stats AS cas ON c.guid = cas.guid AND (cas.slot = 0 AND ate.type = 2 OR cas.slot = 1 AND ate.type = 3 OR cas.slot = 2 AND ate.type = 5)"
        " ORDER BY atm.arenateamid ASC");

    uint32 count = 0;
    do
    {
        ArenaTeam* newArenaTeam = new ArenaTeam;

        if (!newArenaTeam->LoadArenaTeamFromDB(result) || !newArenaTeam->LoadMembersFromDB(result2))
        {
            newArenaTeam->Disband(nullptr);
            delete newArenaTeam;
            continue;
        }

        AddArenaTeam(newArenaTeam);

        ++count;
    }
    while (result->NextRow());

    TC_LOG_INFO("server.loading", ">> Loaded %u arena teams in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
}
