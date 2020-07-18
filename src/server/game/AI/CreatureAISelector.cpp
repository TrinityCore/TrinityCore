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

#include "AIException.h"
#include "Creature.h"
#include "CreatureAISelector.h"
#include "CreatureAIFactory.h"

#include "MovementGenerator.h"

#include "GameObject.h"
#include "GameObjectAIFactory.h"

#include "Log.h"
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

    template <class AI, class T>
    inline FactoryHolder<AI, T> const* SelectFactory(T* obj)
    {
        static_assert(std::is_same<AI, CreatureAI>::value || std::is_same<AI, GameObjectAI>::value, "Invalid template parameter");
        static_assert(std::is_same<AI, CreatureAI>::value == std::is_same<T, Creature>::value, "Incompatible AI for type");
        static_assert(std::is_same<AI, GameObjectAI>::value == std::is_same<T, GameObject>::value, "Incompatible AI for type");

        using AIRegistry = typename FactoryHolder<AI, T>::FactoryHolderRegistry;

        // AIName in db
        std::string const& aiName = obj->GetAIName();
        if (!aiName.empty())
            return AIRegistry::instance()->GetRegistryItem(aiName);

        // select by permit check
        typename AIRegistry::RegistryMapType const& items = AIRegistry::instance()->GetRegisteredItems();
        auto itr = std::max_element(items.begin(), items.end(), PermissibleOrderPred<T>(obj));
        if (itr != items.end() && GetPermitFor(obj, *itr) >= 0)
            return itr->second.get();

        // should _never_ happen, Null AI types defined as PERMIT_BASE_IDLE, it must've been found
        ABORT();
        return nullptr;
    }

    CreatureAI* SelectAI(Creature* creature)
    {
        // special pet case, if a tamed creature uses AIName (example SmartAI) we need to override it
        if (creature->IsPet())
            return ASSERT_NOTNULL(sCreatureAIRegistry->GetRegistryItem("PetAI"))->Create(creature);

        // scriptname in db
        try
        {
            if (CreatureAI* scriptedAI = sScriptMgr->GetCreatureAI(creature))
                return scriptedAI;
        }
        catch (InvalidAIException const& e)
        {
            TC_LOG_ERROR("entities.unit", "Exception trying to assign script '%s' to Creature (Entry: %u), this Creature will have a default AI. Exception message: %s",
                creature->GetScriptName().c_str(), creature->GetEntry(), e.what());
        }

        return SelectFactory<CreatureAI>(creature)->Create(creature);
    }

    MovementGenerator* SelectMovementGenerator(Unit* unit)
    {
        MovementGeneratorType type = unit->GetDefaultMovementType();
        if (Creature* creature = unit->ToCreature())
            if (!creature->GetPlayerMovingMe())
                type = creature->GetDefaultMovementType();

        MovementGeneratorCreator const* mv_factory = sMovementGeneratorRegistry->GetRegistryItem(type);
        return ASSERT_NOTNULL(mv_factory)->Create(unit);
    }

    GameObjectAI* SelectGameObjectAI(GameObject* go)
    {
        // scriptname in db
        if (GameObjectAI* scriptedAI = sScriptMgr->GetGameObjectAI(go))
            return scriptedAI;

        return SelectFactory<GameObjectAI>(go)->Create(go);
    }
}
