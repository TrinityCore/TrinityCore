/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef _WHOLISTSTORAGE_H
#define _WHOLISTSTORAGE_H

#include "Common.h"
#include "ObjectGuid.h"

class WhoListPlayerInfo
{
public:
    WhoListPlayerInfo(ObjectGuid guid, uint32 team, AccountTypes security, uint8 level, uint8 clss, uint8 race, uint32 zoneid, uint8 gender, bool visible, std::wstring const& widePlayerName,
        std::wstring const& wideGuildName, std::string const& playerName, std::string const& guildName) :
        _guid(guid), _team(team), _security(security), _level(level), _class(clss), _race(race), _zoneid(zoneid), _gender(gender), _visible(visible),
        _widePlayerName(widePlayerName), _wideGuildName(wideGuildName), _playerName(playerName), _guildName(guildName) {}

    ObjectGuid GetGuid() const { return _guid; }
    uint32 GetTeam() const { return _team; }
    AccountTypes GetSecurity() const { return _security; }
    uint8 GetLevel() const { return _level; }
    uint8 GetClass() const { return _class; }
    uint8 GetRace() const { return _race; }
    uint32 GetZoneId() const { return _zoneid; }
    uint8 GetGender() const { return _gender; }
    bool IsVisible() const { return _visible; }
    std::wstring const& GetWidePlayerName() const { return _widePlayerName; }
    std::wstring const& GetWideGuildName() const { return _wideGuildName; }
    std::string const& GetPlayerName() const { return _playerName; }
    std::string const& GetGuildName() const { return _guildName; }

private:
    ObjectGuid _guid;
    uint32 _team;
    AccountTypes _security;
    uint8 _level;
    uint8 _class;
    uint8 _race;
    uint32 _zoneid;
    uint8 _gender;
    bool _visible;
    std::wstring _widePlayerName;
    std::wstring _wideGuildName;
    std::string _playerName;
    std::string _guildName;
};

typedef std::vector<WhoListPlayerInfo> WhoListInfoVector;

class TC_GAME_API WhoListStorageMgr
{
private:
    WhoListStorageMgr() { };
    ~WhoListStorageMgr() { };

public:
    static WhoListStorageMgr* instance();

    void Update();
    WhoListInfoVector const& GetWhoList() const { return _whoListStorage; }

protected:
    WhoListInfoVector _whoListStorage;
};

#define sWhoListStorageMgr WhoListStorageMgr::instance()

#endif // _WHOLISTSTORAGE_H
