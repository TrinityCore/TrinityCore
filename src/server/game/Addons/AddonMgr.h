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

#ifndef _ADDONMGR_H
#define _ADDONMGR_H

#include "Common.h"
#include <ace/Singleton.h>

#include <string>

class WorldSession;

struct AddonInfo
{
    AddonInfo(const std::string& name, uint8 enabled, uint32 crc, uint8 state, bool crcOrPubKey)
    {
        Name = name;
        Enabled = enabled;
        CRC = crc;
        State = state;
        UsePublicKeyOrCRC = crcOrPubKey;
    }

    std::string Name;
    uint8 Enabled;
    uint32 CRC;
    uint8 State;
    bool UsePublicKeyOrCRC;
};

struct SavedAddon
{
    SavedAddon(const std::string& name, uint32 crc)
    {
        Name = name;
        CRC = crc;
    }

    std::string Name;
    uint32 CRC;
};

// List of client addons (for WorldSession).
typedef std::list<AddonInfo> AddonsList;

// List of saved addons (in DB).
typedef std::list<SavedAddon> SavedAddonsList;

#define STANDARD_ADDON_CRC 0x4c1c776d

class AddonMgr
{
    friend class ACE_Singleton<AddonMgr, ACE_Null_Mutex>;
    AddonMgr();
    ~AddonMgr();

    public:

        void LoadFromDB();
        void SaveAddon(AddonInfo const& addon);

        SavedAddon const* GetAddonInfo(const std::string& name) const;

    private:

        SavedAddonsList m_knownAddons;                           // Known addons.
};

#define sAddonMgr ACE_Singleton<AddonMgr, ACE_Null_Mutex>::instance()

#endif

