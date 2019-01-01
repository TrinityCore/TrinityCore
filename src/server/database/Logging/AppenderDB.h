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

#ifndef APPENDERDB_H
#define APPENDERDB_H

#include "Appender.h"

class TC_DATABASE_API AppenderDB: public Appender
{
    public:
        typedef std::integral_constant<AppenderType, APPENDER_DB>::type TypeIndex;

        AppenderDB(uint8 id, std::string const& name, LogLevel level, AppenderFlags flags, std::vector<char const*> extraArgs);
        ~AppenderDB();

        void setRealmId(uint32 realmId) override;
        AppenderType getType() const override { return TypeIndex::value; }

    private:
        uint32 realmId;
        bool enabled;
        void _write(LogMessage const* message) override;
};

#endif
