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

#ifndef APPENDERDB_H
#define APPENDERDB_H

#include "Appender.h"
#include <vector>

class TC_DATABASE_API AppenderDB: public Appender
{
    public:
        static constexpr AppenderType type = APPENDER_DB;

        AppenderDB(uint8 id, std::string name, LogLevel level, AppenderFlags flags, std::vector<std::string_view> const& args);
        ~AppenderDB();

        void setRealmId(uint32 realmId) override;
        AppenderType getType() const override { return type; }

    private:
        uint32 realmId;
        bool enabled;
        void _write(LogMessage const* message) override;
};

#endif
