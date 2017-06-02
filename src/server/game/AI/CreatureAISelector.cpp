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

#include "Creature.h"
#include "CreatureAISelector.h"
#include "CreatureAIFactory.h"
#include "Log.h"
#include "MovementGenerator.h"

#include "GameObject.h"
#include "GameObjectAIFactory.h"

#include "ScriptMgr.h"

namespace FactorySelector
{
    template <class T, class Value>
    inline int32 GetPermitFor(T const* obj, Value const& value)
    {
        Permissible<T> const* const p = ASSERT_NOTNULL(dynamic_cast<Permissible<T> const*>(value.second.get()));
        return p->Permit(obj);
    }

    template <class T>
    struct PermissibleOrderPred
    {
    public:
        PermissibleOrderPred(T const* obj) : _obj(obj) { }

        template <class Value>
        bool operator()(Value const& left, Value const& right) const
        {
            return GetPermitFor(_obj, left) < GetPermitFor(_obj, right);
        }

    private:
        T const* const _obj;
    };

    CreatureAI* SelectAI(Creature* creature)
    {
        CreatureAICreator const* ai_factory = nullptr;

        // scriptname in db
        if (CreatureAI* scriptedAI = sScriptMgr->GetCreatureAI(creature))
            return scriptedAI;

        // AIname in db
        std::string const& aiName = creature->GetAIName();
        if (!ai_factory && !aiName.empty())
            ai_factory = sCreatureAIRegistry->GetRegistryItem(aiName);

        // select by permit check
        if (!ai_factory)
        {
            CreatureAIRegistry::RegistryMapType const& items = sCreatureAIRegistry->GetRegisteredItems();
            auto itr = std::max_element(items.begin(), items.end(), PermissibleOrderPred<Creature>(creature));
            if (itr != items.end() && GetPermitFor(creature, *itr) >= 0)
                ai_factory = itr->second.get();
        }

        if (!ai_factory)
            ai_factory = sCreatureAIRegistry->GetRegistryItem("NullCreatureAI");

        return ASSERT_NOTNULL(ai_factory)->Create(creature);
    }

    MovementGenerator* SelectMovementGenerator(Unit* unit)
    {
        MovementGeneratorType type = IDLE_MOTION_TYPE;
        if (unit->GetTypeId() == TYPEID_UNIT)
            type = unit->ToCreature()->GetDefaultMovementType();

        MovementGeneratorCreator const* mv_factory = sMovementGeneratorRegistry->GetRegistryItem(type);
        return ASSERT_NOTNULL(mv_factory)->Create(unit);
    }

    GameObjectAI* SelectGameObjectAI(GameObject* go)
    {
        GameObjectAICreator const* ai_factory = nullptr;

        // scriptname in db
        if (GameObjectAI* scriptedAI = sScriptMgr->GetGameObjectAI(go))
            return scriptedAI;

        // AIname in db
        std::string const& aiName = go->GetAIName();
        if (!ai_factory && !aiName.empty())
            ai_factory = sGameObjectAIRegistry->GetRegistryItem(aiName);

        // select by permit check
        if (!ai_factory)
        {
            GameObjectAIRegistry::RegistryMapType const& items = sGameObjectAIRegistry->GetRegisteredItems();
            auto itr = std::max_element(items.begin(), items.end(), PermissibleOrderPred<GameObject>(go));
            if (itr != items.end() && GetPermitFor(go, *itr) >= 0)
                ai_factory = itr->second.get();
        }

        if (!ai_factory)
            ai_factory = sGameObjectAIRegistry->GetRegistryItem("NullGameObjectAI");

        return ASSERT_NOTNULL(ai_factory)->Create(go);
    }
}
