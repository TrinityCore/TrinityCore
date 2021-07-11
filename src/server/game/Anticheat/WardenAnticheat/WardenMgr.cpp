/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "Common.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "ProgressBar.h"
#include "Util.h"
#include "Log.h"
#include "Database/DatabaseEnv.h"
#include "WardenMgr.h"
#include "Warden.h"
#include <mutex>
#include <ace/OS_NS_dirent.h>
#include <openssl/md5.h>
#include "Anticheat.h"

WardenMgr::WardenMgr() : CheckStore(), CheckResultStore() { }

WardenMgr::~WardenMgr()
{
    for (CheckMap::iterator it = CheckStore.begin(); it != CheckStore.end(); ++it)
        delete it->second;

    for (CheckResultMap::iterator it = CheckResultStore.begin(); it != CheckResultStore.end(); ++it)
        delete it->second;

    CheckStore.clear();
    CheckResultStore.clear();
}

void WardenMgr::LoadWardenChecks()
{
    // Check if Warden is enabled by config before loading anything
    if (!sWorld.getConfig(CONFIG_BOOL_AC_WARDEN_WIN_ENABLED) && !sWorld.getConfig(CONFIG_BOOL_AC_WARDEN_OSX_ENABLED))
    {
        BarGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Warden disabled, loading checks skipped.");
        return;
    }

    //                                                                0     1        2       3       4         5          6         7      8          9
    std::unique_ptr<QueryResult> result (WorldDatabase.Query("SELECT `id`, `build`, `type`, `data`, `result`, `address`, `length`, `str`, `penalty`, `comment` FROM `warden_checks` ORDER BY `build` ASC, `id` ASC"));

    if (!result)
    {
        BarGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Loaded 0 warden data and results");
        return;
    }

    uint32 count = 0;
    Field* fields;
    BarGoLink bar(result->GetRowCount());

    do
    {
        bar.step();
        fields = result->Fetch();

        uint16 id               = fields[0].GetUInt16();
        uint16 build            = fields[1].GetUInt16();
        uint8 checkType         = fields[2].GetUInt8();
        std::string data        = fields[3].GetString();
        std::string checkResult = fields[4].GetString();
        uint32 address          = fields[5].GetUInt32();
        uint8 length            = fields[6].GetUInt8();
        std::string str         = fields[7].GetString();
        int8 penalty            = fields[8].GetUInt8();
        std::string comment     = fields[9].GetString();

        WardenCheck* wardenCheck = new WardenCheck();
        wardenCheck->Type = checkType;
        wardenCheck->CheckId = id;

        if (penalty < WARDEN_ACTION_LOG || penalty >= WARDEN_ACTION_MAX)
            penalty = sWorld.getConfig(CONFIG_UINT32_AC_WARDEN_DEFAULT_PENALTY);

        // Initialize action with default action from config
        wardenCheck->Action = WardenActions(penalty);

        if (checkType == PAGE_CHECK_A || checkType == PAGE_CHECK_B || checkType == DRIVER_CHECK)
        {
            wardenCheck->Data.SetHexStr(data.c_str());
            int len = data.size() / 2;

            if (wardenCheck->Data.GetNumBytes() < len)
            {
                uint8 temp[24];
                memset(temp, 0, len);
                memcpy(temp, wardenCheck->Data.AsByteArray().data(), wardenCheck->Data.GetNumBytes());
                std::reverse(temp, temp + len);
                wardenCheck->Data.SetBinary((uint8*)temp, len);
            }
        }

        if (checkType == MEM_CHECK || checkType == PAGE_CHECK_A || checkType == PAGE_CHECK_B || checkType == PROC_CHECK)
        {
            wardenCheck->Address = address;
            wardenCheck->Length = length;
        }

        // PROC_CHECK support missing
        if (checkType == MEM_CHECK || checkType == MPQ_CHECK || checkType == LUA_STR_CHECK || checkType == DRIVER_CHECK || checkType == MODULE_CHECK)
            wardenCheck->Str = str;

        CheckStore.insert(std::pair<uint16, WardenCheck*>(build, wardenCheck));

        if (checkType == MPQ_CHECK || checkType == MEM_CHECK)
        {
            WardenCheckResult* wr = new WardenCheckResult();
            wr->Id = id;
            wr->Result.SetHexStr(checkResult.c_str());
            int len = checkResult.size() / 2;
            if (wr->Result.GetNumBytes() < len)
            {
                uint8 *temp = new uint8[len];
                memset(temp, 0, len);
                memcpy(temp, wr->Result.AsByteArray().data(), wr->Result.GetNumBytes());
                std::reverse(temp, temp + len);
                wr->Result.SetBinary((uint8*)temp, len);
                delete[] temp;
            }
            CheckResultStore.insert(std::pair<uint16, WardenCheckResult*>(build, wr));
        }

        if (comment.empty())
            wardenCheck->Comment = "";
        else
            wardenCheck->Comment = comment;

        ++count;
    } while (result->NextRow());

    sLog.outString();
    sLog.outString(">> Loaded %u warden checks.", count);
}

void WardenMgr::LoadWardenModules()
{
    // Check if Warden is enabled by config before loading anything
    if (!sWorld.getConfig(CONFIG_BOOL_AC_WARDEN_WIN_ENABLED) && !sWorld.getConfig(CONFIG_BOOL_AC_WARDEN_OSX_ENABLED))
    {
        BarGoLink bar(1);
        bar.step();
        sLog.outString();
        sLog.outString(">> Warden disabled, loading modules skipped.");
        return;
    }

    BarGoLink bar(1);
    std::string moduleDirectory = sWorld.GetWardenModuleDirectory();
    ACE_DIR* pDirectory = ACE_OS::opendir(ACE_TEXT(moduleDirectory.c_str()));

    if (pDirectory)
    {
        ACE_DIRENT* pFile;

        while (!!(pFile = ACE_OS::readdir(pDirectory)))
            if (!memcmp(&pFile->d_name[strlen(pFile->d_name) - 4], ".bin", 4))
                LoadWardenModule(moduleDirectory + "/" + pFile->d_name);
        
        //ACE_OS::closedir(pDirectory);
    }
    bar.step();

    MANGOS_ASSERT(!(m_vWindowsModules.empty() && sWorld.getConfig(CONFIG_BOOL_AC_WARDEN_WIN_ENABLED)));
    MANGOS_ASSERT(!(m_vMacModules.empty() && sWorld.getConfig(CONFIG_BOOL_AC_WARDEN_OSX_ENABLED)));

    sLog.outString();
    sLog.outString(">> Loaded %u windows and %u mac modules.", m_vWindowsModules.size(), m_vMacModules.size());
}

void WardenMgr::LoadWardenModule(std::string module_name)
{
    WardenModule module;
    uint32 len = 0;

    {
        FILE * pBinFile = fopen(module_name.c_str(), "rb");
        if (pBinFile == 0)
        {
            sLog.outError("Failed to load warden module binary: %s", module_name.c_str());
            return;
        }

        // Check size of module.
        fseek(pBinFile, 0, SEEK_END);
        len = ftell(pBinFile);
        fseek(pBinFile, 0, SEEK_SET);

        if (len < WARDEN_SIGNATURE_SIZE)
        {
            sLog.outError("Warden module binary too small: %s", module_name.c_str());
            fclose(pBinFile);
            return;
        }

        // Read data from module.
        module.binaryData.resize(len);
        fread(module.binaryData.data(), len, 1, pBinFile);

        // Calculate MD5 hash.
        MD5_CTX ctx;
        MD5_Init(&ctx);
        MD5_Update(&ctx, module.binaryData.data(), len);
        module.binaryHash.resize(MD5_DIGEST_LENGTH);
        MD5_Final(&module.binaryHash[0], &ctx);

        fclose(pBinFile);
    }

    {
        // Name of key file.
        module_name = module_name.substr(0, module_name.length() - 4);
        module_name += ".key";

        FILE * pKeyFile = fopen(module_name.c_str(), "rb");
        if (pKeyFile == 0)
        {
            sLog.outError("Failed to load warden module key: %s", module_name.c_str());
            return;
        }

        fseek(pKeyFile, 0, SEEK_END);
        len = ftell(pKeyFile);
        fseek(pKeyFile, 0, SEEK_SET);

        if (len != WARDEN_KEY_SIZE)
        {
            sLog.outError("Warden module key too small: %s", module_name.c_str());
            fclose(pKeyFile);
            return;
        }

        // Read the key.
        fread(module.moduleKey.data(), 16, 1, pKeyFile);
        fclose(pKeyFile);
    }

    {
        // Name of challenge and response file.
        module_name = module_name.substr(0, module_name.length() - 4);
        module_name += ".cr";

        FILE * pCRFile = fopen(module_name.c_str(), "rb");
        if (pCRFile == 0)
        {
            sLog.outError("Failed to load warden module challenge and response data: %s", module_name.c_str());
            return;
        }

        fseek(pCRFile, 0, SEEK_END);
        len = ftell(pCRFile);
        fseek(pCRFile, 0, SEEK_SET);

        auto const crSize = len - WARDEN_SCAN_TYPES_COUNT;

        if (!!(crSize % sizeof(ChallengeResponseEntry)))
        {
            sLog.outError("Invalid warden module challenge and response data: %s", module_name.c_str());
            fclose(pCRFile);
            return;
        }

        module.challengeData.resize(crSize / sizeof(ChallengeResponseEntry));

        fread(module.scanTypes.data(), WARDEN_SCAN_TYPES_COUNT, 1, pCRFile);
        fread(module.challengeData.data(), crSize, 1, pCRFile);

        fclose(pCRFile);
    }

    bool isWindowsModule = false;

    for (auto i = 0; i < WARDEN_SCAN_TYPES_COUNT; ++i)
    {
        if (module.scanTypes[i] != 0)
        {
            isWindowsModule = true;
            break;
        }
    }

    if (isWindowsModule)
        m_vWindowsModules.push_back(module);
    else
        m_vMacModules.push_back(module);
}

WardenCheck* WardenMgr::GetWardenDataById(uint16 build, uint16 id)
{
    WardenCheck* result = nullptr;

    ReadGuard guard(m_lock);
    for (CheckMap::iterator it = CheckStore.lower_bound(build); it != CheckStore.upper_bound(build); ++it)
    {
        if (it->second->CheckId == id)
            result = it->second;
    }

    return result;
}

WardenCheckResult* WardenMgr::GetWardenResultById(uint16 build, uint16 id)
{
    WardenCheckResult* result = nullptr;

    ReadGuard guard(m_lock);
    for (CheckResultMap::iterator it = CheckResultStore.lower_bound(build); it != CheckResultStore.upper_bound(build); ++it)
    {
        if (it->second->Id == id)
            result = it->second;
    }

    return result;
}

void WardenMgr::GetWardenCheckIds(bool isMemCheck, uint16 build, std::list<uint16>& idl)
{
    idl.clear(); // just to be sure

    ReadGuard guard(m_lock);
    for (CheckMap::iterator it = CheckStore.lower_bound(build); it != CheckStore.upper_bound(build); ++it)
    {
        if (isMemCheck)
        {
            if ((it->second->Type == MEM_CHECK) || (it->second->Type == MODULE_CHECK))
                idl.push_back(it->second->CheckId);
        }
        else
            idl.push_back(it->second->CheckId);
    }
}

WardenModule* WardenMgr::GetRandomWardenModule(bool windows)
{
    if (windows)
        return &m_vWindowsModules[urand(0, m_vWindowsModules.size() - 1)];
    else
        return &m_vMacModules[urand(0, m_vMacModules.size() - 1)];
}