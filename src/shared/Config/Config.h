/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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

        std::string GetStringDefault(const char * name, std::string def);
        bool GetBoolDefault(const char * name, const bool def);
        int32 GetIntDefault(const char * name, const int32 def);
        float GetFloatDefault(const char * name, const float def);

        std::string GetFilename() const { return mFilename; }
    private:
        std::string mFilename;
        bool mIgnoreCase;
        DOTCONFDocument *mConf;
};

#define sConfig Trinity::Singleton<Config>::Instance()

#endif

