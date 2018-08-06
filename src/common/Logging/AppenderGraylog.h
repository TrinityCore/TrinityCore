/*
 * Copyright (C) 2017-2018 AshamaneProject <https://github.com/AshamaneProject>
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

#ifndef APPENDERGRAYLOG_H
#define APPENDERGRAYLOG_H

#include "Appender.h"

class TC_COMMON_API AppenderGraylog : public Appender
{
    public:
        typedef std::integral_constant<AppenderType, APPENDER_GRAYLOG>::type TypeIndex;

        AppenderGraylog(uint8 _id, std::string const& name, LogLevel level, AppenderFlags flags, std::vector<char const*> extraArgs);
        AppenderType getType() const override { return TypeIndex::value; }

        void setRealmId(uint32 realmId, std::string /*realmName*/) override;

    private:
        void _write(LogMessage const* message) override;

        std::string _graylogSourceURL;
        uint32 _realmId;
        std::string _realmName;
};

#endif
