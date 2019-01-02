/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#ifndef TRINITY_GAMEOBJECTAIFACTORY_H
#define TRINITY_GAMEOBJECTAIFACTORY_H

#include "ObjectRegistry.h"
#include "SelectableAI.h"

class GameObject;
class GameObjectAI;

template <class REAL_GO_AI, bool is_db_allowed = true>
struct GameObjectAIFactory : public SelectableAI<GameObject, GameObjectAI, is_db_allowed>
{
    GameObjectAIFactory(std::string const& name) : SelectableAI<GameObject, GameObjectAI, is_db_allowed>(name) { }

    GameObjectAI* Create(GameObject* go) const override
    {
        return new REAL_GO_AI(go);
    }

    int32 Permit(GameObject const* go) const override
    {
        return REAL_GO_AI::Permissible(go);
    }
};

typedef SelectableAI<GameObject, GameObjectAI>::FactoryHolderRegistry GameObjectAIRegistry;

#define sGameObjectAIRegistry GameObjectAIRegistry::instance()

#endif
