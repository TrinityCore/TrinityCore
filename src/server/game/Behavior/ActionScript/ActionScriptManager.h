/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_ACTIONSCRIPTMANAGER_H
#define TRINITY_ACTIONSCRIPTMANAGER_H

#include "ActionScript.h"
#include "Define.h"
#include "SpawnData.h"
#include <unordered_map>
#include <memory>

class TC_GAME_API ActionScriptManager
{
    private:
        static ActionScriptManager& _instance();
    public:
        static ActionScriptManager const& instance() { return _instance(); }
        static void GlobalInit();

        ActionScript const* GetScriptForTemplate(SpawnObjectType type, uint32 templateId, uint32 index)
        {
            auto it = _scriptsByTemplate.find({ type, templateId });
            if (it == _scriptsByTemplate.end())
                return nullptr;
            auto const& scripts = it->second;
            if (!(index < scripts.size()))
                return nullptr;
            if (!scripts[index])
                return nullptr;
            return GetScriptById(*scripts[index]);
        }

        ActionScript const* GetScriptById(uint32 id)
        {
            auto it = _scripts.find(id);
            if (it == _scripts.end())
                return nullptr;
            return &it->second;
        }
        size_t GetScriptCount() { return _scripts.size(); }

    private:
        std::unordered_map<std::pair<SpawnObjectType, uint32>, std::vector<Optional<uint32>>> _scriptsByTemplate;
        std::unordered_map<uint32, ActionScript> _scripts;
        void Init();
};

#define sActionScriptMgr ActionScriptManager::instance()
        

#endif
