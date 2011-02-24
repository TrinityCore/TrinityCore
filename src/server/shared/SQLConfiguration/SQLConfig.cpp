/*
 * Copyright (C) 2011 gmlt.A
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

#include "SQLConfig.h"

SQLConfig::SQLConfig()
{
}

SQLConfig::~SQLConfig()
{
}

std::string SQLConfig::GetStringDefault(const char * name, std::string def)
{
    QueryResult result = WorldDatabase.PQuery("SELECT `config_string` FROM `config` WHERE `name` = '%s'", name);
    if (result)
        return result->Fetch()->GetString();
    else
        return def;
};

bool SQLConfig::GetBoolDefault(const char * name, const bool def)
{
    QueryResult result = WorldDatabase.PQuery("SELECT `config_bool` FROM `config` WHERE `name` = '%s'", name);
    if (result)
    {
        int8 val = result->Fetch()->GetInt8();
        return val == 1;
    }
    else
        return def;
};

int32 SQLConfig::GetIntDefault(const char * name, const int32 def)
{
    QueryResult result = WorldDatabase.PQuery("SELECT `config_int` FROM `config` WHERE `name` = '%s'", name);
    if (result)
        return result->Fetch()->GetInt32();
    else
        return def;
};

float SQLConfig::GetFloatDefault(const char * name, const float def)
{
    QueryResult result = WorldDatabase.PQuery("SELECT `config_float` FROM `config` WHERE `name` = '%s'", name);
    if (result)
        return result->Fetch()->GetFloat();
    else
        return def;
};
