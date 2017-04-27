/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITY_RELAYHANDLER_H
#define TRINITY_RELAYHANDLER_H

#include "Common.h"

enum RelayTargetType
{
    RELAYTARGETTYPE_IRCBRIDGE,
    RELAYTARGETTYPE_MAX
};

enum RelayReportType
{
    RELAYREPORTTYPE_RECONNECT,
    RELAYREPORTTYPE_ERROR
};

class TC_GAME_API RelayHandler
{
    public:
        RelayHandler();
        ~RelayHandler();

        static RelayHandler* instance();

        void Send(std::string const message) { _data.push(message); }
        std::string GetNext();

    private:
        std::queue<std::string> _data;
};

#define sRelayHandler RelayHandler::instance()

#endif // TRINITY_RELAYHANDLER_H
