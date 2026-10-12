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

#include "ObjectGridLoader.h"
#include "AreaTrigger.h"
#include "AreaTriggerDataStore.h"
#include "CellImpl.h"
#include "Conversation.h"
#include "Corpse.h"
#include "Creature.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "GameTime.h"
#include "Log.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "SceneObject.h"

void ObjectGridEvacuator::Visit(CreatureMapType &m)
{
    // creature in unloading grid can have respawn point in another grid
    // if it will be unloaded then it will not respawn in original grid until unload/load original grid
    // move to respawn point to prevent this case. For player view in respawn grid this will be normal respawn.
    for (CreatureMapType::iterator iter = m.begin(); iter != m.end();)
    {
        Creature* c = iter->GetSource();
        ++iter;

        ASSERT(!c->IsPet() && "ObjectGridRespawnMover must not be called for pets");
        c->GetMap()->CreatureRespawnRelocation(c, true);
    }
}

void ObjectGridEvacuator::Visit(GameObjectMapType &m)
{
    // gameobject in unloading grid can have respawn point in another grid
    // if it will be unloaded then it will not respawn in original grid until unload/load original grid
    // move to respawn point to prevent this case. For player view in respawn grid this will be normal respawn.
    for (GameObjectMapType::iterator iter = m.begin(); iter != m.end();)
    {
        GameObject* go = iter->GetSource();
        ++iter;

        go->GetMap()->GameObjectRespawnRelocation(go, true);
    }
}

template <class T>
void ObjectGridLoaderBase::AddToMap(T* obj, Map* map, uint32& objectCount)
{
    CellCoord cellCoord = Trinity::ComputeCellCoord(obj->GetPositionX(), obj->GetPositionY());
    Cell cell(cellCoord);

    map->AddToGrid<T>(obj, cell);
    obj->AddToWorld();
    if (obj->isActiveObject())
        map->AddToActive(obj);

    ++objectCount;
}

template <class T>
void LoadHelper(GridGuidSet const& guid_set, uint32& count, Map* map, uint32 phaseId = 0, Optional<ObjectGuid> phaseOwner = {})
{
    for (GridGuidSet::const_iterator i_guid = guid_set.begin(); i_guid != guid_set.end(); ++i_guid)
    {
        // Don't spawn at all if there's a respawn timer
        ObjectGuid::LowType guid = *i_guid;
        if (!map->ShouldBeSpawnedOnGridLoad<T>(guid))
            continue;

        T* obj = new T;
        //TC_LOG_INFO("misc", "DEBUG: LoadHelper from table: {} for (guid: {}) Loading", table, guid);
        if (!obj->LoadFromDB(guid, map, false, phaseOwner.has_value() /*allowDuplicate*/))
        {
            delete obj;
            continue;
        }

        if (phaseOwner)
        {
            PhasingHandler::InitDbPersonalOwnership(obj->GetPhaseShift(), *phaseOwner);
            map->GetMultiPersonalPhaseTracker().RegisterTrackedObject(phaseId, *phaseOwner, obj);
        }

        ObjectGridLoaderBase::AddToMap(obj, map, count);
    }
}

void ObjectGridLoader::LoadN()
{
    i_gameObjects = 0; i_creatures = 0; i_corpses = 0; i_areaTriggers = 0;

    //Load creatures and game objects
    if (GridObjectGuids const* grid_guids = sObjectMgr->GetGridObjectGuids(i_map->GetId(), i_map->GetDifficultyID(), i_grid.GetGridId()))
    {
        LoadHelper<GameObject>(grid_guids->gameobjects, i_gameObjects, i_map);
        LoadHelper<Creature>(grid_guids->creatures, i_creatures, i_map);
    }

    //Load areatriggers
    if (GridGuidSet const* areaTriggers = sAreaTriggerDataStore->GetAreaTriggersForMapAndGrid(i_map->GetId(), i_map->GetDifficultyID(), i_grid.GetGridId()))
        LoadHelper<AreaTrigger>(*areaTriggers, i_areaTriggers, i_map);

    //Load corpses (not bones)
    if (std::unordered_set<Corpse*> const* corpses = i_map->GetCorpsesInGrid(i_grid.GetGridId()))
        for (Corpse* corpse : *corpses)
            AddToMap(corpse, i_map, i_corpses);

    TC_LOG_DEBUG("maps", "{} GameObjects, {} Creatures, {} AreaTrriggers, and {} Corpses/Bones loaded for grid {} on map {}",
        i_gameObjects, i_creatures, i_areaTriggers, i_corpses, i_grid.GetGridId(), i_map->GetId());
}

void PersonalPhaseGridLoader::Load(uint32 phaseId)
{
    if (GridObjectGuids const* grid_guids = sObjectMgr->GetCellPersonalObjectGuids(i_map->GetId(), i_map->GetDifficultyID(), phaseId, i_grid.GetGridId()))
    {
        LoadHelper<GameObject>(grid_guids->gameobjects, i_gameObjects, i_map, phaseId, _phaseOwner);
        LoadHelper<Creature>(grid_guids->creatures, i_creatures, i_map, phaseId, _phaseOwner);
    }
}

template<class T>
void ObjectGridUnloader::Visit(GridRefManager<T> &m)
{
    while (!m.empty())
    {
        T* obj = m.front()->GetSource();
        //Some creatures may summon other temp summons in CleanupsBeforeDelete()
        //So we need this even after cleaner (maybe we can remove cleaner)
        //Example: Flame Leviathan Turret 33139 is summoned when a creature is deleted
        /// @todo Check if that script has the correct logic. Do we really need to summons something before deleting?
        obj->CleanupsBeforeDelete();
        ///- object will get delinked from the manager when deleted
        delete obj;
    }
}

void ObjectGridStoper::Visit(CreatureMapType &m)
{
    // stop any fights at grid de-activation and remove dynobjects/areatriggers created at cast by creatures
    for (CreatureMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        iter->GetSource()->RemoveAllDynObjects();
        iter->GetSource()->RemoveAllAreaTriggers();
        if (iter->GetSource()->IsInCombat())
            iter->GetSource()->CombatStop();
    }
}

template<class T>
void ObjectGridCleaner::Visit(GridRefManager<T> &m)
{
    for (typename GridRefManager<T>::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        iter->GetSource()->SetDestroyedObject(true);
        iter->GetSource()->CleanupsBeforeDelete();
    }
}

template void ObjectGridLoaderBase::AddToMap(GameObject*, Map*, uint32&);
template void ObjectGridLoaderBase::AddToMap(Creature*, Map*, uint32&);
template void ObjectGridLoaderBase::AddToMap(AreaTrigger*, Map*, uint32&);
template void ObjectGridLoaderBase::AddToMap(Corpse*, Map*, uint32&);

template void ObjectGridUnloader::Visit(CreatureMapType &);
template void ObjectGridUnloader::Visit(GameObjectMapType &);
template void ObjectGridUnloader::Visit(DynamicObjectMapType &);
template void ObjectGridUnloader::Visit(AreaTriggerMapType&);
template void ObjectGridUnloader::Visit(SceneObjectMapType&);
template void ObjectGridUnloader::Visit(ConversationMapType&);

template void ObjectGridCleaner::Visit(CreatureMapType &);
template void ObjectGridCleaner::Visit<GameObject>(GameObjectMapType &);
template void ObjectGridCleaner::Visit<DynamicObject>(DynamicObjectMapType &);
template void ObjectGridCleaner::Visit<Corpse>(CorpseMapType &);
template void ObjectGridCleaner::Visit<AreaTrigger>(AreaTriggerMapType &);
template void ObjectGridCleaner::Visit<SceneObject>(SceneObjectMapType &);
template void ObjectGridCleaner::Visit<Conversation>(ConversationMapType &);
