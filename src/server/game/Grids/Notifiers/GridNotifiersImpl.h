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
#include "Player.h"
#include "UpdateData.h"
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

template<typename PacketSender>
void Trinity::MessageDistDeliverer<PacketSender>::Visit(PlayerMapType& m) const
{
    for (PlayerMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        Player* target = iter->GetSource();
        if (!target->InSamePhase(*i_phaseShift))
            continue;

        if ((!required3dDist ? target->GetExactDist2dSq(i_source) : target->GetExactDistSq(i_source)) > i_distSq)
            continue;

        // Send packet to all who are sharing the player's vision
        if (target->HasSharedVision())
        {
            SharedVisionList::const_iterator i = target->GetSharedVisionList().begin();
            for (; i != target->GetSharedVisionList().end(); ++i)
                if ((*i)->m_seer == target)
                    SendPacket(*i);
        }

        if (target->m_seer == target || target->GetVehicle())
            SendPacket(target);
    }
}

template<typename PacketSender>
void Trinity::MessageDistDeliverer<PacketSender>::Visit(CreatureMapType& m) const
{
    for (CreatureMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        Creature* target = iter->GetSource();
        if (!target->InSamePhase(*i_phaseShift))
            continue;

        if ((!required3dDist ? target->GetExactDist2dSq(i_source) : target->GetExactDistSq(i_source)) > i_distSq)
            continue;

        // Send packet to all who are sharing the creature's vision
        if (target->HasSharedVision())
        {
            SharedVisionList::const_iterator i = target->GetSharedVisionList().begin();
            for (; i != target->GetSharedVisionList().end(); ++i)
                if ((*i)->m_seer == target)
                    SendPacket(*i);
        }
    }
}

template<typename PacketSender>
void Trinity::MessageDistDeliverer<PacketSender>::Visit(DynamicObjectMapType& m) const
{
    for (DynamicObjectMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        DynamicObject* target = iter->GetSource();
        if (!target->InSamePhase(*i_phaseShift))
            continue;

        if ((!required3dDist ? target->GetExactDist2dSq(i_source) : target->GetExactDistSq(i_source)) > i_distSq)
            continue;

        if (Unit* caster = target->GetCaster())
        {
            // Send packet back to the caster if the caster has vision of dynamic object
            Player* player = caster->ToPlayer();
            if (player && player->m_seer == target)
                SendPacket(player);
        }
    }
}

template<typename PacketSender>
void Trinity::MessageDistDelivererToHostile<PacketSender>::Visit(PlayerMapType& m) const
{
    for (PlayerMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        Player* target = iter->GetSource();
        if (!target->InSamePhase(*i_phaseShift))
            continue;

        if (target->GetExactDist2dSq(i_source) > i_distSq)
            continue;

        // Send packet to all who are sharing the player's vision
        if (target->HasSharedVision())
        {
            SharedVisionList::const_iterator i = target->GetSharedVisionList().begin();
            for (; i != target->GetSharedVisionList().end(); ++i)
                if ((*i)->m_seer == target)
                    SendPacket(*i);
        }

        if (target->m_seer == target || target->GetVehicle())
            SendPacket(target);
    }
}

template<typename PacketSender>
void Trinity::MessageDistDelivererToHostile<PacketSender>::Visit(CreatureMapType& m) const
{
    for (CreatureMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        Creature* target = iter->GetSource();
        if (!target->InSamePhase(*i_phaseShift))
            continue;

        if (target->GetExactDist2dSq(i_source) > i_distSq)
            continue;

        // Send packet to all who are sharing the creature's vision
        if (target->HasSharedVision())
        {
            SharedVisionList::const_iterator i = target->GetSharedVisionList().begin();
            for (; i != target->GetSharedVisionList().end(); ++i)
                if ((*i)->m_seer == target)
                    SendPacket(*i);
        }
    }
}

template<typename PacketSender>
void Trinity::MessageDistDelivererToHostile<PacketSender>::Visit(DynamicObjectMapType& m) const
{
    for (DynamicObjectMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        DynamicObject* target = iter->GetSource();
        if (!target->InSamePhase(*i_phaseShift))
            continue;

        if (target->GetExactDist2dSq(i_source) > i_distSq)
            continue;

        if (Unit* caster = target->GetCaster())
        {
            // Send packet back to the caster if the caster has vision of dynamic object
            Player* player = caster->ToPlayer();
            if (player && player->m_seer == target)
                SendPacket(player);
        }
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
        if (!ref.GetSource()->InSamePhase(*i_phaseShift))
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
        if (!ref.GetSource()->InSamePhase(*i_phaseShift))
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
        if (!ref.GetSource()->InSamePhase(*i_phaseShift))
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
        if (!ref.GetSource()->InSamePhase(*i_phaseShift))
            continue;

        if (i_check(ref.GetSource()))
        {
            this->Insert(ref.GetSource());

            if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
                return;
        }
    }
}

// AreaTrigger searchers

template <class Check, class Result>
void Trinity::AreaTriggerSearcherBase<Check, Result>::Visit(AreaTriggerMapType& m)
{
    if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
        return;

    for (GridReference<AreaTrigger> const& ref : m)
    {
        if (!ref.GetSource()->InSamePhase(*i_phaseShift))
            continue;

        if (i_check(ref.GetSource()))
        {
            this->Insert(ref.GetSource());

            if (this->ShouldContinue() == WorldObjectSearcherContinuation::Return)
                return;
        }
    }
}

template<typename Localizer>
void Trinity::LocalizedDo<Localizer>::operator()(Player const* p)
{
    LocaleConstant loc_idx = p->GetSession()->GetSessionDbLocaleIndex();
    uint32 cache_idx = loc_idx + 1;
    LocalizedAction* action;

    // create if not cached yet
    if (_localizedCache.size() < cache_idx + 1 || !_localizedCache[cache_idx])
    {
        if (_localizedCache.size() < cache_idx + 1)
            _localizedCache.resize(cache_idx + 1);

        action = _localizer(loc_idx);
        _localizedCache[cache_idx].reset(action);
    }
    else
        action = _localizedCache[cache_idx].get();

    (*action)(p);
}

#endif                                                      // TRINITY_GRIDNOTIFIERSIMPL_H
