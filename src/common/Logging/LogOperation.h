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

#ifndef LOGOPERATION_H
#define LOGOPERATION_H

#include "Define.h"
#include <memory>

class Logger;
struct LogMessage;

class LogOperation
{
    public:
        LogOperation(Logger const* _logger, LogMessage* _msg);
        LogOperation(LogOperation const&) = delete;
        LogOperation(LogOperation&&) noexcept = default;
        LogOperation& operator=(LogOperation const&) = delete;
        LogOperation& operator=(LogOperation&&) noexcept = default;
        ~LogOperation();

        void operator()() const;

    protected:
        Logger const* logger;
        std::unique_ptr<LogMessage> msg;
};

#endif
