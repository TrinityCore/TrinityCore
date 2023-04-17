/*
 * Copyright (C)
 * Copyright (C)
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

 /// \addtogroup world The World
 /// @{
 /// \file

#ifndef __Frozen_H
#define __Frozen_H

#include "Common.h"
#include "Timer.h"
#include "SharedDefines.h"
#include "QueryResult.h"
#include "QueryResult.h"
#include <map>
#include <set>
#include <list>

class Object;
class WorldPacket;
class WorldSession;
class Player;
class WorldSocket;
class SystemMgr;
class LoginQueryHolder;

struct FakerLocationTemplate
{
    uint32 Map;
    float X;
    float Y;
    float Z;
    float O;
};

extern std::vector<FakerLocationTemplate> FakerLocation;
extern std::unordered_map<uint32, uint32> FakerMap;

/// The Bot
class MyBot
{
public:
    static MyBot* instance()
    {
        static MyBot instance;
        return &instance;
    }
    bool ProcessCommand(Player* player, std::string cmd);
    void Load();
    void Update(Player* faker, uint32 diff);
    void LoginPlayerBot(uint32 cumot = 1);
    void UpdateAllSessions(uint32 diff);
    typedef std::map<ObjectGuid, Player*> PlayerBotMap;
    PlayerBotMap m_playerBots;

    typedef std::map<ObjectGuid, uint32> PlayerBotTime;
    PlayerBotTime m_playerBottime;

    void PlBotupdate();
    void AddPlayerBot(uint32 accid, uint32 playerGuid);
    void LogoutPlayerBot(ObjectGuid guid, bool Save);
    void HandlePlayerBotLogin(LoginQueryHolder* holder);
    QueryResultHolderFuture _charBotLoginCallback;

    uint32 GetMaxBotCount() const { return m_MaxbotCount; }

    /// Increase/Decrease number of players
    inline void IncreaseBotCount()
    {
        uint32 botcout = m_playerBots.size();
        m_MaxbotCount = std::max(m_MaxbotCount, botcout);
    }
    uint32 m_MaxbotCount;
};

#define sMybot MyBot::instance()
#endif
/// @}
