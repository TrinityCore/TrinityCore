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

#ifndef SQLCONFIG_H
#define SQLCONFIG_H

#include <ace/Singleton.h>
#include "DatabaseEnv.h"

class SQLConfig
{
    friend class ACE_Singleton<SQLConfig, ACE_Null_Mutex>;
    SQLConfig();
    public:
        ~SQLConfig();

        std::string GetStringDefault(const char * name, std::string def);
        bool GetBoolDefault(const char * name, const bool def);
        int32 GetIntDefault(const char * name, const int32 def);
        float GetFloatDefault(const char * name, const float def);
};

#define sSQLConfig ACE_Singleton<SQLConfig, ACE_Null_Mutex>::instance()

#endif
