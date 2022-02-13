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
        if (!target->IsInPhase(i_source))
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
void Trinity::MessageDistDeliverer<PacketSender>::Visit(CreatureMapType& m) const
{
    for (CreatureMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        Creature* target = iter->GetSource();
        if (!target->IsInPhase(i_source))
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
void Trinity::MessageDistDeliverer<PacketSender>::Visit(DynamicObjectMapType& m) const
{
    for (DynamicObjectMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        DynamicObject* target = iter->GetSource();
        if (!target->IsInPhase(i_source))
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

template<typename PacketSender>
void Trinity::MessageDistDelivererToHostile<PacketSender>::Visit(PlayerMapType& m) const
{
    for (PlayerMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        Player* target = iter->GetSource();
        if (!target->IsInPhase(i_source))
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
        if (!target->IsInPhase(i_source))
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
        if (!target->IsInPhase(i_source))
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

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(GameObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_GAMEOBJECT))
        return;

    // already found
    if (i_object)
        return;

    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(PlayerMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_PLAYER))
        return;

    // already found
    if (i_object)
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(CreatureMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CREATURE))
        return;

    // already found
    if (i_object)
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(CorpseMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CORPSE))
        return;

    // already found
    if (i_object)
        return;

    for (CorpseMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(DynamicObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_DYNAMICOBJECT))
        return;

    // already found
    if (i_object)
        return;

    for (DynamicObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(AreaTriggerMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_AREATRIGGER))
        return;

    // already found
    if (i_object)
        return;

    for (AreaTriggerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(SceneObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_SCENEOBJECT))
        return;

    // already found
    if (i_object)
        return;

    for (SceneObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(ConversationMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CONVERSATION))
        return;

    // already found
    if (i_object)
        return;

    for (ConversationMapType::iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectLastSearcher<Check>::Visit(GameObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_GAMEOBJECT))
        return;

    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Trinity::WorldObjectLastSearcher<Check>::Visit(PlayerMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_PLAYER))
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Trinity::WorldObjectLastSearcher<Check>::Visit(CreatureMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CREATURE))
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Trinity::WorldObjectLastSearcher<Check>::Visit(CorpseMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CORPSE))
        return;

    for (CorpseMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Trinity::WorldObjectLastSearcher<Check>::Visit(DynamicObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_DYNAMICOBJECT))
        return;

    for (DynamicObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Trinity::WorldObjectLastSearcher<Check>::Visit(AreaTriggerMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_AREATRIGGER))
        return;

    for (AreaTriggerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Trinity::WorldObjectLastSearcher<Check>::Visit(SceneObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_SCENEOBJECT))
        return;

    for (SceneObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Trinity::WorldObjectLastSearcher<Check>::Visit(ConversationMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CONVERSATION))
        return;

    for (ConversationMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(PlayerMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_PLAYER))
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(CreatureMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CREATURE))
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(CorpseMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CORPSE))
        return;

    for (CorpseMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(GameObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_GAMEOBJECT))
        return;

    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(DynamicObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_DYNAMICOBJECT))
        return;

    for (DynamicObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(AreaTriggerMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_AREATRIGGER))
        return;

    for (AreaTriggerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(SceneObjectMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_SCENEOBJECT))
        return;

    for (SceneObjectMapType::iterator itr = m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(ConversationMapType &m)
{
    if (!(i_mapTypeMask & GRID_MAP_TYPE_MASK_CONVERSATION))
        return;

    for (ConversationMapType::iterator itr = m.begin(); itr != m.end(); ++itr)
        if (i_check(itr->GetSource()))
            Insert(itr->GetSource());
}

// Gameobject searchers

template<class Check>
void Trinity::GameObjectSearcher<Check>::Visit(GameObjectMapType &m)
{
    // already found
    if (i_object)
        return;

    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::GameObjectLastSearcher<Check>::Visit(GameObjectMapType &m)
{
    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Trinity::GameObjectListSearcher<Check>::Visit(GameObjectMapType &m)
{
    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (itr->GetSource()->IsInPhase(_searcher))
            if (i_check(itr->GetSource()))
                Insert(itr->GetSource());
}

// Unit searchers

template<class Check>
void Trinity::UnitSearcher<Check>::Visit(CreatureMapType &m)
{
    // already found
    if (i_object)
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::UnitSearcher<Check>::Visit(PlayerMapType &m)
{
    // already found
    if (i_object)
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::UnitLastSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Trinity::UnitLastSearcher<Check>::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Trinity::UnitListSearcher<Check>::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (itr->GetSource()->IsInPhase(_searcher))
            if (i_check(itr->GetSource()))
                Insert(itr->GetSource());
}

template<class Check>
void Trinity::UnitListSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (itr->GetSource()->IsInPhase(_searcher))
            if (i_check(itr->GetSource()))
                Insert(itr->GetSource());
}

// Creature searchers

template<class Check>
void Trinity::CreatureSearcher<Check>::Visit(CreatureMapType &m)
{
    // already found
    if (i_object)
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::CreatureLastSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
    }
}

template<class Check>
void Trinity::CreatureListSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (itr->GetSource()->IsInPhase(_searcher))
            if (i_check(itr->GetSource()))
                Insert(itr->GetSource());
}

template<class Check>
void Trinity::PlayerListSearcher<Check>::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if (itr->GetSource()->IsInPhase(_searcher))
            if (i_check(itr->GetSource()))
                Insert(itr->GetSource());
}

template<class Check>
void Trinity::PlayerSearcher<Check>::Visit(PlayerMapType &m)
{
    // already found
    if (i_object)
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
        {
            i_object = itr->GetSource();
            return;
        }
    }
}

template<class Check>
void Trinity::PlayerLastSearcher<Check>::Visit(PlayerMapType& m)
{
    for (PlayerMapType::iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        if (!itr->GetSource()->IsInPhase(_searcher))
            continue;

        if (i_check(itr->GetSource()))
            i_object = itr->GetSource();
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
