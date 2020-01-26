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
#include "GameObject.h"
#include "PassiveAI.h"
#include "Log.h"
#include "MovementGenerator.h"
#include "TemporarySummon.h"
#include "CreatureAIFactory.h"
#include "ScriptMgr.h"

namespace FactorySelector
{
    CreatureAI* selectAI(Creature* creature)
    {
        const CreatureAICreator* ai_factory = NULL;

        if (creature->IsPet())
            ai_factory = sCreatureAIRegistry->GetRegistryItem("PetAI");

        //scriptname in db
        if (!ai_factory)
            if (CreatureAI* scriptedAI = sScriptMgr->GetCreatureAI(creature))
                return scriptedAI;

        // AIname in db
        std::string ainame=creature->GetAIName();
        if (!ai_factory && !ainame.empty())
            ai_factory = sCreatureAIRegistry->GetRegistryItem(ainame);

        // select by NPC flags
        if (!ai_factory)
        {
            if (creature->IsVehicle())
                ai_factory = sCreatureAIRegistry->GetRegistryItem("VehicleAI");
            else if (creature->HasUnitTypeMask(UNIT_MASK_CONTROLABLE_GUARDIAN) && ((Guardian*)creature)->GetOwner()->GetTypeId() == TYPEID_PLAYER)
                ai_factory = sCreatureAIRegistry->GetRegistryItem("PetAI");
            else if (creature->HasNpcFlag(UNIT_NPC_FLAG_SPELLCLICK))
                ai_factory = sCreatureAIRegistry->GetRegistryItem("NullCreatureAI");
            else if (creature->IsGuard())
                ai_factory = sCreatureAIRegistry->GetRegistryItem("GuardAI");
            else if (creature->HasUnitTypeMask(UNIT_MASK_CONTROLABLE_GUARDIAN))
                ai_factory = sCreatureAIRegistry->GetRegistryItem("PetAI");
            else if (creature->IsTotem())
                ai_factory = sCreatureAIRegistry->GetRegistryItem("TotemAI");
            else if (creature->IsTrigger())
            {
                if (creature->m_spells[0])
                    ai_factory = sCreatureAIRegistry->GetRegistryItem("TriggerAI");
                else
                    ai_factory = sCreatureAIRegistry->GetRegistryItem("NullCreatureAI");
            }
            else if (creature->IsCritter() && !creature->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
                ai_factory = sCreatureAIRegistry->GetRegistryItem("CritterAI");
        }

        // select by permit check
        if (!ai_factory)
        {
            int best_val = -1;
            typedef CreatureAIRegistry::RegistryMapType RMT;
            RMT const& l = sCreatureAIRegistry->GetRegisteredItems();
            for (RMT::const_iterator iter = l.begin(); iter != l.end(); ++iter)
            {
                const CreatureAICreator* factory = iter->second;
                const SelectableAI* p = dynamic_cast<const SelectableAI*>(factory);
                ASSERT(p);
                int val = p->Permit(creature);
                if (val > best_val)
                {
                    best_val = val;
                    ai_factory = p;
                }
            }
        }

        // select NullCreatureAI if not another cases
        ainame = (ai_factory == NULL) ? "NullCreatureAI" : ai_factory->key();

        TC_LOG_DEBUG("scripts", "Creature %s (%s DB GUID: " UI64FMTD ") is using AI type: %s.", creature->GetName().c_str(), creature->GetGUID().ToString().c_str(), creature->GetSpawnId(), ainame.c_str());
        return (ai_factory == NULL ? new NullCreatureAI(creature) : ai_factory->Create(creature));
    }

    MovementGenerator* selectMovementGenerator(Creature* creature)
    {
        MovementGeneratorRegistry& mv_registry(*MovementGeneratorRegistry::instance());
        ASSERT(creature->GetCreatureTemplate());
        const MovementGeneratorCreator* mv_factory = mv_registry.GetRegistryItem(creature->GetDefaultMovementType());

        /* if (mv_factory == NULL)
        {
            int best_val = -1;
            StringVector l;
            mv_registry.GetRegisteredItems(l);
            for (StringVector::iterator iter = l.begin(); iter != l.end(); ++iter)
            {
            const MovementGeneratorCreator *factory = mv_registry.GetRegistryItem((*iter).c_str());
            const SelectableMovement *p = dynamic_cast<const SelectableMovement *>(factory);
            ASSERT(p != NULL);
            int val = p->Permit(creature);
            if (val > best_val)
            {
                best_val = val;
                mv_factory = p;
            }
            }
        }*/

        return (mv_factory == NULL ? NULL : mv_factory->Create(creature));
    }

    GameObjectAI* SelectGameObjectAI(GameObject* go)
    {
        GameObjectAICreator const* ai_factory = NULL;

        // scriptname in db
        if (GameObjectAI* scriptedAI = sScriptMgr->GetGameObjectAI(go))
            return scriptedAI;

        ai_factory = sGameObjectAIRegistry->GetRegistryItem(go->GetAIName());

        //future goAI types go here

        std::string ainame = (ai_factory == NULL || go->GetScriptId()) ? "NullGameObjectAI" : ai_factory->key();

        TC_LOG_DEBUG("scripts", "%s used AI is %s.", go->GetGUID().ToString().c_str(), ainame.c_str());

        return (ai_factory == NULL ? new NullGameObjectAI(go) : ai_factory->Create(go));
    }
}
