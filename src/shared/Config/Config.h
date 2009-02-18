/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <Policies/Singleton.h>
#include "Platform/Define.h"

class DOTCONFDocument;

class TRINITY_DLL_SPEC Config
{
    public:
        Config();
        ~Config();

        bool SetSource(const char *file, bool ignorecase = true);
        bool Reload();

        bool GetString(const char* name, std::string *value);
        bool GetString(const char* name, char const **value);
        std::string GetStringDefault(const char* name, const char* def);

        bool GetBool(const char* name, bool *value);
        bool GetBoolDefault(const char* name, const bool def = false);

        bool GetInt(const char* name, int *value);
        int GetIntDefault(const char* name, const int def);

        bool GetFloat(const char* name, float *value);
        float GetFloatDefault(const char* name, const float def);

        std::string GetFilename() const { return mFilename; }
    private:
        std::string mFilename;
        bool mIgnoreCase;
        DOTCONFDocument *mConf;
};

#define sConfig Trinity::Singleton<Config>::Instance()

#endif

