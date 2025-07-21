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

#ifndef TRINITY_GRIDNOTIFIERSIMPL_H
#define TRINITY_GRIDNOTIFIERSIMPL_H

#include "GridNotifiers.h"
#include "Corpse.h"
#include "CreatureAI.h"
#include "Player.h"
#include "SpellAuras.h"
#include "UpdateData.h"
#include "WorldPacket.h"
#include "WorldSession.h"

template<class T>
inline void Trinity::VisibleNotifier::Visit(GridRefManager<T> &m)
{
    for (typename GridRefManager<T>::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        vis_guids.erase(iter->GetSource()->GetGUID());
        i_player.UpdateVisibilityOf(iter->GetSource(), i_data, i_visibleNow);
    }
}

// SEARCHERS & LIST SEARCHERS & WORKERS

// WorldObject searchers & workers

template <class Check, class Result>
template <class T>
void Trinity::WorldObjectSearcherBase<Check, Result>::Visit(GridRefManager<T>& m)
{
    if (!(i_mapTypeMask & GridMapTypeMaskForType<T>::value))
        return;

    if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
        return;

    for (GridReference<T> const& ref : m)
    {
        if (i_check(ref.GetSource()))
        {
            this->Insert(ref.GetSource());

            if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
                return;
        }
    }
}

// Gameobject searchers

template <class Check, class Result>
void Trinity::GameObjectSearcherBase<Check, Result>::Visit(GameObjectMapType& m)
{
    if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
        return;

    for (GridReference<GameObject> const& ref : m)
    {
        if (!ref.GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(ref.GetSource()))
        {
            this->Insert(ref.GetSource());

            if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
                return;
        }
    }
}

// Unit searchers

template <class Check, class Result>
template <class T>
void Trinity::UnitSearcherBase<Check, Result>::VisitImpl(GridRefManager<T>& m)
{
    if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
        return;

    for (GridReference<T> const& ref : m)
    {
        if (!ref.GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(ref.GetSource()))
        {
            this->Insert(ref.GetSource());

            if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
                return;
        }
    }
}

// Creature searchers

template <class Check, class Result>
void Trinity::CreatureSearcherBase<Check, Result>::Visit(CreatureMapType& m)
{
    if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
        return;

    for (GridReference<Creature> const& ref : m)
    {
        if (!ref.GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(ref.GetSource()))
        {
            this->Insert(ref.GetSource());

            if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
                return;
        }
    }
}

// Player searchers

template <class Check, class Result>
void Trinity::PlayerSearcherBase<Check, Result>::Visit(PlayerMapType& m)
{
    if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
        return;

    for (GridReference<Player> const& ref : m)
    {
        if (!ref.GetSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(ref.GetSource()))
        {
            this->Insert(ref.GetSource());

            if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
                return;
        }
    }
}

template<class Builder>
void Trinity::LocalizedPacketDo<Builder>::operator()(Player* p)
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
void Trinity::LocalizedPacketListDo<Builder>::operator()(Player* p)
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

#endif                                                      // TRINITY_GRIDNOTIFIERSIMPL_H
