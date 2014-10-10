/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

#ifndef ComponentManager_h__
#define ComponentManager_h__

#include "Define.h"
#include <cstring>
#include <string>
#include <set>

namespace Battlenet
{
    struct Component
    {
        std::string Program;
        std::string Platform;
        uint32 Build;
    };

    class ComponentMgr
    {
        ComponentMgr() { }
        ~ComponentMgr();

    public:
        void Load();
        bool HasComponent(Component const* component) const;
        bool HasProgram(std::string const& program) const { return _programs.count(program) != 0; }
        bool HasPlatform(std::string const& platform) const { return _platforms.count(platform) != 0; }

        static ComponentMgr* instance()
        {
            static ComponentMgr instance;
            return &instance;
        }

    private:
        std::set<Component*> _components;
        std::set<std::string> _programs;
        std::set<std::string> _platforms;
    };
}

#define sComponentMgr Battlenet::ComponentMgr::instance()

#endif // ComponentManager_h__
