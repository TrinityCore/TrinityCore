/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "AnticheatMgr.h"

class Anticheat_WorldScript : public WorldScript
{
public:
    Anticheat_WorldScript() : WorldScript("Anticheat_WorldScript") { }

    void OnStartup() override
    {
        TC_LOG_INFO("server.loading", "Deleting player reports...");
        SQLTransaction trans = CharacterDatabase.BeginTransaction();
        // delete reports, this table has only meaning at runtime, so we can get updated stats for player
        trans->Append("TRUNCATE TABLE players_reports_status");
        // this table on the other hand holds persistent data, on world startup we just delete no longer existing characters
        trans->Append("DELETE dpr FROM daily_players_reports dpr LEFT JOIN characters c ON c.guid = dpr.guid WHERE c.guid IS NULL");
        CharacterDatabase.DirectCommitTransaction(trans);
    }

    void OnConfigLoad(bool /*isReload*/) override { sAnticheatMgr->LoadSettings(); }
};

void AddSC_Anticheat()
{
    new Anticheat_WorldScript();
}
