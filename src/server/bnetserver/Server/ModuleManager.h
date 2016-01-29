/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#ifndef ModuleManager_h__
#define ModuleManager_h__

#include "PacketsCommon.h"

namespace Battlenet
{
    struct ModuleKey
    {
        std::string Platform;
        std::string Name;

        bool operator<(ModuleKey const& right) const
        {
            int32 res = Platform.compare(right.Platform);
            if (res < 0)
                return true;
            else if (res > 0)
                return false;

            return Name < right.Name;
        }
    };

    struct ModuleInfo : public PrintableComponent
    {
        ModuleInfo() : DataSize(0), Data(nullptr) { Handle.Region = "EU"; }
        ModuleInfo(ModuleInfo const& right) : DataSize(right.DataSize), Data(nullptr)
        {
            Handle.Type = right.Handle.Type;
            Handle.Region = right.Handle.Region;
            memcpy(Handle.ModuleId, right.Handle.ModuleId, 32);
            if (DataSize)
            {
                Data = new uint8[DataSize];
                memcpy(Data, right.Data, DataSize);
            }
        }

        virtual ~ModuleInfo()
        {
            delete[] Data;
        }

        Cache::Handle Handle;
        uint32 DataSize;
        uint8* Data;

        std::string ToString() const override;
    };

    class ModuleManager
    {
        ModuleManager() { }
        ~ModuleManager();

    public:
        void Load();
        ModuleInfo* CreateModule(std::string const& os, std::string const& name) const;

        static ModuleManager* instance()
        {
            static ModuleManager instance;
            return &instance;
        }

    private:
        std::map<ModuleKey, ModuleInfo*> _modules;
    };
}

#define sModuleMgr Battlenet::ModuleManager::instance()

#endif // ModuleManager_h__
