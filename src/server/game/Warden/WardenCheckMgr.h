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

#ifndef _WARDENCHECKMGR_H
#define _WARDENCHECKMGR_H

#include <map>
#include <shared_mutex>
#include "Cryptography/BigNumber.h"

enum WardenActions
{
    WARDEN_ACTION_LOG,
    WARDEN_ACTION_KICK,
    WARDEN_ACTION_BAN
};

struct WardenCheck
{
    uint8 Type;
    BigNumber Data;
    uint32 Address;                                         // PROC_CHECK, MEM_CHECK, PAGE_CHECK
    uint8 Length;                                           // PROC_CHECK, MEM_CHECK, PAGE_CHECK
    std::string Str;                                        // LUA, MPQ, DRIVER
    std::string Comment;
    uint16 CheckId;
    enum WardenActions Action;
};

struct WardenCheckResult
{
    BigNumber Result;                                       // MEM_CHECK
};

class TC_GAME_API WardenCheckMgr
{
    private:
        WardenCheckMgr();
        ~WardenCheckMgr();

    public:
        static WardenCheckMgr* instance();

        // We have a linear key without any gaps, so we use vector for fast access
        typedef std::vector<WardenCheck*> CheckContainer;
        typedef std::map<uint32, WardenCheckResult*> CheckResultContainer;

        WardenCheck* GetWardenDataById(uint16 Id);
        WardenCheckResult* GetWardenResultById(uint16 Id);

        std::vector<uint16> MemChecksIdPool;
        std::vector<uint16> OtherChecksIdPool;

        void LoadWardenChecks();
        void LoadWardenOverrides();

        std::shared_mutex _checkStoreLock;

    private:
        CheckContainer CheckStore;
        CheckResultContainer CheckResultStore;
};

#define sWardenCheckMgr WardenCheckMgr::instance()

#endif
