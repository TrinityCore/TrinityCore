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

#include "AddonMgr.h"
#include "DatabaseEnv.h"
#include "DBCStores.h"
#include "Log.h"
#include "Timer.h"
#include <openssl/md5.h>

namespace AddonMgr
{

// Anonymous namespace ensures file scope of all the stuff inside it, even
// if you add something more to this namespace somewhere else.
namespace
{
    // List of saved addons (in DB).
    typedef std::list<SavedAddon> SavedAddonsList;

    SavedAddonsList m_knownAddons;

    BannedAddonList m_bannedAddons;
}

void LoadFromDB()
{
    uint32 oldMSTime = getMSTime();

    QueryResult result = CharacterDatabase.Query("SELECT name, crc FROM addons");
    if (result)
    {
        uint32 count = 0;

        do
        {
            Field* fields = result->Fetch();

            std::string name = fields[0].GetString();
            uint32 crc = fields[1].GetUInt32();

            m_knownAddons.push_back(SavedAddon(name, crc));

            ++count;
        }
        while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded %u known addons in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
    else
        TC_LOG_INFO("server.loading", ">> Loaded 0 known addons. DB table `addons` is empty!");

    oldMSTime = getMSTime();
    result = CharacterDatabase.Query("SELECT id, name, version, UNIX_TIMESTAMP(timestamp) FROM banned_addons ORDER BY timestamp");
    if (result)
    {
        uint32 count = 0;
        uint32 dbcMaxBannedAddon = sBannedAddOnsStore.GetNumRows();

        do
        {
            Field* fields = result->Fetch();

            BannedAddon addon;
            addon.Id = fields[0].GetUInt32() + dbcMaxBannedAddon;
            addon.Timestamp = uint32(fields[3].GetUInt64());

            std::string name = fields[1].GetString();
            std::string version = fields[2].GetString();

            MD5(reinterpret_cast<uint8 const*>(name.c_str()), name.length(), addon.NameMD5);
            MD5(reinterpret_cast<uint8 const*>(version.c_str()), version.length(), addon.VersionMD5);

            m_bannedAddons.push_back(addon);

            ++count;
        }
        while (result->NextRow());

        TC_LOG_INFO("server.loading", ">> Loaded %u banned addons in %u ms", count, GetMSTimeDiffToNow(oldMSTime));
    }
}

void SaveAddon(std::string const& name, uint32 publicKeyCrc)
{
    PreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_INS_ADDON);

    stmt->setString(0, name);
    stmt->setUInt32(1, publicKeyCrc);

    CharacterDatabase.Execute(stmt);

    m_knownAddons.emplace_back(name, publicKeyCrc);
}

SavedAddon const* GetAddonInfo(const std::string& name)
{
    for (SavedAddonsList::const_iterator it = m_knownAddons.begin(); it != m_knownAddons.end(); ++it)
    {
        SavedAddon const& addon = (*it);
        if (addon.Name == name)
            return &addon;
    }

    return nullptr;
}

BannedAddonList const* GetBannedAddons()
{
    return &m_bannedAddons;
}

} // Namespace
