/*
 * This file is part of the KitronCore Project. See AUTHORS file for Copyright information
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

#ifndef Kitron_GRIDNOTIFIERSIMPL_H
#define Kitron_GRIDNOTIFIERSIMPL_H

#include "GridNotifiers.h"
#include "Corpse.h"
#include "CreatureAI.h"
#include "Player.h"
#include "SpellAuras.h"
#include "UpdateData.h"
#include "WorldPacket.h"
#include "WorldSession.h"

template<class T>
inline void Kitron::VisibleNotifier::Visit(GridRefManager<T> &m)
{
    for (typename GridRefManager<T>::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        vis_guids.erase(iter->GetSource()->GetGUID());
        i_player.UpdateVisibilityOf(iter->GetSource(), i_data, i_visibleNow);
    }
}

// SEARCHERS & LIST SEARCHERS & WORKERS

// WorldObject searchers & workers

template<class Check>
void Kitron::WorldObjectSearcher<Check>::Visit(GameObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_GAMEOBJECT))
        return;

    // already found
    if (i_object)
        return;

    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Kitron::WorldObjectSearcher<Check>::Visit(PlayerMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_PLAYER))
        return;

    // already found
    if (i_object)
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Kitron::WorldObjectSearcher<Check>::Visit(CreatureMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CREATURE))
        return;

    // already found
    if (i_object)
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Kitron::WorldObjectSearcher<Check>::Visit(CorpseMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CORPSE))
        return;

    // already found
    if (i_object)
        return;

    for (CorpseMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Kitron::WorldObjectSearcher<Check>::Visit(DynamicObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_DYNAMICOBJECT))
        return;

    // already found
    if (i_object)
        return;

    for (DynamicObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Kitron::WorldObjectLastSearcher<Check>::Visit(GameObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_GAMEOBJECT))
        return;

    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Kitron::WorldObjectLastSearcher<Check>::Visit(PlayerMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_PLAYER))
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Kitron::WorldObjectLastSearcher<Check>::Visit(CreatureMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CREATURE))
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Kitron::WorldObjectLastSearcher<Check>::Visit(CorpseMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CORPSE))
        return;

    for (CorpseMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Kitron::WorldObjectLastSearcher<Check>::Visit(DynamicObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_DYNAMICOBJECT))
        return;

    for (DynamicObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Kitron::WorldObjectListSearcher<Check>::Visit(PlayerMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_PLAYER))
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

template<class Check>
void Kitron::WorldObjectListSearcher<Check>::Visit(CreatureMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CREATURE))
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

template<class Check>
void Kitron::WorldObjectListSearcher<Check>::Visit(CorpseMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CORPSE))
        return;

    for (CorpseMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

template<class Check>
void Kitron::WorldObjectListSearcher<Check>::Visit(GameObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_GAMEOBJECT))
        return;

    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

template<class Check>
void Kitron::WorldObjectListSearcher<Check>::Visit(DynamicObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_DYNAMICOBJECT))
        return;

    for (DynamicObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

// Gameobject searchers

template<class Check>
void Kitron::GameObjectSearcher<Check>::Visit(GameObjectMapType &m)
{
    // already found
    if (i_object)
        return;

    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Kitron::GameObjectLastSearcher<Check>::Visit(GameObjectMapType &m)
{
    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Kitron::GameObjectListSearcher<Check>::Visit(GameObjectMapType &m)
{
    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (itr->GetSource()->InSamePhase(i_phaseMask))
            if (i_check(itr->GetSource()))
                Insert(itr->GetSource());
}

// Unit searchers

template<class Check>
void Kitron::UnitSearcher<Check>::Visit(CreatureMapType &m)
{
    // already found
    if (i_object)
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Kitron::UnitSearcher<Check>::Visit(PlayerMapType &m)
{
    // already found
    if (i_object)
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Kitron::UnitLastSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Kitron::UnitLastSearcher<Check>::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Kitron::UnitListSearcher<Check>::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (itr->GetSource()->InSamePhase(i_phaseMask))
            if (i_check(itr->GetSource()))
                Insert(itr->GetSource());
}

template<class Check>
void Kitron::UnitListSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (itr->GetSource()->InSamePhase(i_phaseMask))
            if (i_check(itr->GetSource()))
                Insert(itr->GetSource());
}

// Creature searchers

template<class Check>
void Kitron::CreatureSearcher<Check>::Visit(CreatureMapType &m)
{
    // already found
    if (i_object)
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Kitron::CreatureLastSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Kitron::CreatureListSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (itr->GetSource()->InSamePhase(i_phaseMask))
            if (i_check(itr->GetSource()))
                Insert(itr->GetSource());
}

template<class Check>
void Kitron::PlayerListSearcher<Check>::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (itr->GetSource()->InSamePhase(i_phaseMask))
            if (i_check(itr->GetSource()))
                Insert(itr->GetSource());
}

template<class Check>
void Kitron::PlayerSearcher<Check>::Visit(PlayerMapType &m)
{
    // already found
    if (i_object)
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Kitron::PlayerLastSearcher<Check>::Visit(PlayerMapType& m)
{
    for (PlayerMapType::iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Builder>
void Kitron::LocalizedPacketDo<Builder>::operator()(Player* p)
{
    LocaleConstant loc_idx = p->GetSession()->GetSessionDbLocaleIndex();
    uint32 cache_idx = loc_idx+1;
    WorldPacket* data;

    // create if not cached yet
    if (i_data_cache.size() < cache_idx + 1 || !i_data_cache[cache_idx])
    {
        if (i_data_cache.size() < cache_idx + 1)
            i_data_cache.resize(cache_idx + 1);

        data = new WorldPacket();

        i_builder(*data, loc_idx);

        i_data_cache[cache_idx] = data;
    }
    else
        data = i_data_cache[cache_idx];

    p->SendDirectMessage(data);
}

template<class Builder>
void Kitron::LocalizedPacketListDo<Builder>::operator()(Player* p)
{
    LocaleConstant loc_idx = p->GetSession()->GetSessionDbLocaleIndex();
    uint32 cache_idx = loc_idx+1;
    WorldPacketList* data_list;

    // create if not cached yet
    if (i_data_cache.size() < cache_idx+1 || i_data_cache[cache_idx].empty())
    {
        if (i_data_cache.size() < cache_idx+1)
            i_data_cache.resize(cache_idx+1);

        data_list = &i_data_cache[cache_idx];

        i_builder(*data_list, loc_idx);
    }
    else
        data_list = &i_data_cache[cache_idx];

    for (size_t i = 0; i < data_list->size(); ++i)
        p->SendDirectMessage((*data_list)[i]);
}

#endif                                                      // Kitron_GRIDNOTIFIERSIMPL_H
