/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
#include <ace/Auto_Ptr.h>
#include <ace/Configuration_Import_Export.h>
#include <ace/Thread_Mutex.h>

namespace ConfigMgr
{

namespace
{
    typedef ACE_Thread_Mutex LockType;
    typedef ACE_Guard<LockType> GuardType;

    std::string _filename;
    ACE_Auto_Ptr<ACE_Configuration_Heap> _config;
    LockType m_configLock;

    // Defined here as it must not be exposed to end-users.
    bool GetValueHelper(const char* name, ACE_TString &result)
    {
        GuardType guard(m_configLock);

        if (_config.get() == 0)
            return false;

        ACE_TString section_name;
        ACE_Configuration_Section_Key section_key;
        const ACE_Configuration_Section_Key &root_key = _config->root_section();

        int i = 0;
        while (_config->enumerate_sections(root_key, i, section_name) == 0)
        {
            _config->open_section(root_key, section_name.c_str(), 0, section_key);
            if (_config->get_string_value(section_key, name, result) == 0)
                return true;
            ++i;
        }

        return false;
    }
}

bool Load(const char* file)
{
    GuardType guard(m_configLock);

    if (file)
        _filename = file;

    _config.reset(new ACE_Configuration_Heap);
    if (_config->open() == 0)
    {
        ACE_Ini_ImpExp config_importer(*_config.get());
        if (config_importer.import_config(_filename.c_str()) == 0)
            return true;
    }
    _config.reset();
    return false;
}

std::string GetStringDefault(const char* name, const std::string &def)
{
    ACE_TString val;
    return GetValueHelper(name, val) ? val.c_str() : def;
};

bool GetBoolDefault(const char* name, bool def)
{
    ACE_TString val;

    if (!GetValueHelper(name, val))
        return def;

    return (val == "true" || val == "TRUE" || val == "yes" || val == "YES" ||
        val == "1");
};

int GetIntDefault(const char* name, int def)
{
    ACE_TString val;
    return GetValueHelper(name, val) ? atoi(val.c_str()) : def;
};

float GetFloatDefault(const char* name, float def)
{
    ACE_TString val;
    return GetValueHelper(name, val) ? (float)atof(val.c_str()) : def;
};

const std::string & GetFilename()
{
    GuardType guard(m_configLock);
    return _filename;
}

} // namespace
