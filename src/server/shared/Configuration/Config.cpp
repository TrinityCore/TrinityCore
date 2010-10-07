/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "Config.h"
#include <ace/Configuration_Import_Export.h>

static bool GetValueHelper(ACE_Configuration_Heap *mConf, const char *name, ACE_TString &result)
{
    if (!mConf)
        return false;

    ACE_GUARD_RETURN(ACE_Thread_Mutex, guard, sConfig.mMtx, false);

    ACE_TString section_name;
    ACE_Configuration_Section_Key section_key;
    ACE_Configuration_Section_Key root_key = mConf->root_section();

    int i = 0;
    while (mConf->enumerate_sections(root_key, i, section_name) == 0)
    {
        mConf->open_section(root_key, section_name.c_str(), 0, section_key);
        if (mConf->get_string_value(section_key, name, result) == 0)
            return true;
        ++i;
    }

    return false;
}

Config::Config() : mConf(NULL)
{
}

Config::~Config()
{
    delete mConf;
}

bool Config::SetSource(const char *file)
{
    mFilename = file;
    return Reload();
}

bool Config::Reload()
{
    delete mConf;
    mConf = new ACE_Configuration_Heap;
    if (mConf->open() == 0)
    {
        ACE_Ini_ImpExp config_importer(*mConf);
        if (config_importer.import_config(mFilename.c_str()) == 0)
            return true;
    }
    delete mConf;
    mConf = NULL;
    return false;
}

std::string Config::GetStringDefault(const char * name, std::string def)
{
    ACE_TString val;
    return GetValueHelper(mConf, name, val) ? val.c_str() : def;
};

bool Config::GetBoolDefault(const char * name, const bool def)
{
    ACE_TString val;
    if (!GetValueHelper(mConf, name, val))
        return def;
    const char* str = val.c_str();

    if(strcmp(str, "true") == 0 || strcmp(str, "TRUE") == 0 ||
        strcmp(str, "yes") == 0 || strcmp(str, "YES") == 0 ||
        strcmp(str, "1") == 0)
        return true;
    else
        return false;
};

int32 Config::GetIntDefault(const char * name, const int32 def)
{
    ACE_TString val;
    return GetValueHelper(mConf, name, val) ? atoi(val.c_str()) : def;
};

float Config::GetFloatDefault(const char * name, const float def)
{
    ACE_TString val;
    return GetValueHelper(mConf, name, val) ? (float)atof(val.c_str()) : def;
};
