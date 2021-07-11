/*
 * Copyright (C) 2005-2011 MaNGOS <http://getmangos.com/>
 * Copyright (C) 2009-2011 MaNGOSZero <https://github.com/mangos/zero>
 * Copyright (C) 2011-2016 Nostalrius <https://nostalrius.org>
 * Copyright (C) 2016-2017 Elysium Project <https://github.com/elysium-project>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "GridNotifiers.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "UpdateData.h"
#include "Item.h"
#include "Map.h"
#include "Transport.h"
#include "ObjectAccessor.h"
#include "BattleGroundMgr.h"

#include "MovementBroadcaster.h"
#include "PlayerBroadcaster.h"
#include "World.h"

using namespace MaNGOS;

void
VisibleChangesNotifier::Visit(CameraMapType& m)
{
    for (const auto& iter : m)
        iter.getSource()->UpdateVisibilityOf(&i_object);
}

void
VisibleNotifier::Notify()
{
    Player& player = *i_camera.GetOwner();
    // at this moment i_clientGUIDs have guids that not iterate at grid level checks
    // but exist one case when this possible and object not out of range: transports
    if (GenericTransport* transport = player.GetTransport())
    {
        for (const auto itr : transport->GetPassengers())
        {
            if (i_clientGUIDs.find(itr->GetObjectGuid()) != i_clientGUIDs.end())
            {
                i_clientGUIDs.erase(itr->GetObjectGuid());
                switch (itr->GetTypeId())
                {
                    case TYPEID_GAMEOBJECT:
                        player.UpdateVisibilityOf(&player, itr->ToGameObject(), i_data, i_visibleNow);
                        break;
                    case TYPEID_PLAYER:
                        player.UpdateVisibilityOf(&player, itr->ToPlayer(), i_data, i_visibleNow);
                        itr->ToPlayer()->UpdateVisibilityOf(itr, &player);
                        break;
                    case TYPEID_UNIT:
                        player.UpdateVisibilityOf(&player, itr->ToCreature(), i_data, i_visibleNow);
                        break;
                    case TYPEID_DYNAMICOBJECT:
                        player.UpdateVisibilityOf(&player, (DynamicObject*)itr, i_data, i_visibleNow);
                        break;
                    default:
                        break;
                }
            }
        }
    }

    // Update current map active objects, modifies i_clientGUIDs so we are not sending
    // out of range updates for an active obj
    if (player.GetMap())
        player.GetMap()->UpdateActiveObjectVisibility(&player, i_clientGUIDs, i_data, i_visibleNow);

    // generate outOfRange for not iterate objects
    i_data.AddOutOfRangeGUID(i_clientGUIDs);
    std::unique_lock<std::shared_timed_mutex> lock(player.m_visibleGUIDs_lock);
    for (ObjectGuidSet::iterator itr = i_clientGUIDs.begin(); itr != i_clientGUIDs.end(); ++itr)
    {
        if ((*itr).IsPlayer())
        {
            if (Player* targetPlayer = player.GetMap()->GetPlayer(*itr))
                if (targetPlayer->m_broadcaster)
                    targetPlayer->m_broadcaster->RemoveListener(&player);
        }
        else if ((*itr).IsCreature() && player.IsInCombat() && !player.GetMap()->IsDungeon())
        {
            // Make sure mobs who become out of range leave combat before grid unload.
            if (Creature* targetCreature = player.GetMap()->GetCreature(*itr))
                player.BeforeVisibilityDestroy(targetCreature);
        }

        player.m_visibleGUIDs.erase(*itr);

        DEBUG_FILTER_LOG(LOG_FILTER_VISIBILITY_CHANGES, "%s is out of range (no in active cells set) now for %s",
                         itr->GetString().c_str(), player.GetGuidStr().c_str());
    }
    lock.unlock();

    if (i_data.HasData())
    {
        // send create/outofrange packet to player (except player create updates that already sent using SendUpdateToPlayer)
        i_data.Send(player.GetSession());

        // send out of range to other players if need
        ObjectGuidSet const& oor = i_data.GetOutOfRangeGUIDs();
        for (const auto& iter : oor)
        {
            if (!iter.IsPlayer())
                continue;

            if (Player* plr = ObjectAccessor::FindPlayer(iter))
                plr->UpdateVisibilityOf(plr->GetCamera().GetBody(), &player);
        }
    }
}

void
MessageDeliverer::Visit(CameraMapType& m)
{
    for (const auto& iter : m)
    {
        Player* owner = iter.getSource()->GetOwner();

        if (i_toSelf || owner != &i_player)
        {
            if (WorldSession* session = owner->GetSession())
                session->SendPacket(i_message);
        }
    }
}

void MessageDelivererExcept::Visit(CameraMapType& m)
{
    for (const auto& iter : m)
    {
        Player* owner = iter.getSource()->GetOwner();

        if (owner == i_skipped_receiver)
            continue;

        if (WorldSession* session = owner->GetSession())
            session->SendPacket(i_message);
    }
}


void
ObjectMessageDeliverer::Visit(CameraMapType& m)
{
    for (const auto& iter : m)
    {
        if (WorldSession* session = iter.getSource()->GetOwner()->GetSession())
            session->SendPacket(i_message);
    }
}

void
MessageDistDeliverer::Visit(CameraMapType& m)
{
    for (const auto& iter : m)
    {
        Player* owner = iter.getSource()->GetOwner();

        if ((i_toSelf || owner != &i_player) &&
                (!i_ownTeamOnly || owner->GetTeam() == i_player.GetTeam()) &&
                (!i_dist || iter.getSource()->GetBody()->IsWithinDist(&i_player, i_dist)))
        {
            if (WorldSession* session = owner->GetSession())
                session->SendPacket(i_message);
        }
    }
}

void
ObjectMessageDistDeliverer::Visit(CameraMapType& m)
{
    for (const auto& iter : m)
    {
        if (!i_dist || iter.getSource()->GetBody()->IsWithinDist(&i_object, i_dist))
        {
            if (WorldSession* session = iter.getSource()->GetOwner()->GetSession())
                session->SendPacket(i_message);
        }
    }
}

template<class T> void
ObjectUpdater::Visit(GridRefManager<T>& m)
{
    for (typename GridRefManager<T>::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        WorldObject::UpdateHelper helper(iter->getSource());
        helper.UpdateRealTime(i_now, i_timeDiff);
    }
}

bool CannibalizeObjectCheck::operator()(Corpse* u)
{
    if (u->IsFriendlyTo(i_fobj))
        return false;

    return i_fobj->IsWithinDistInMap(u, i_range);
}

void MaNGOS::RespawnDo::operator()(Creature* u) const
{
    // prevent respawn creatures for not active BG event
    Map* map = u->GetMap();
    if (map->IsBattleGround())
    {
        BattleGroundEventIdx eventId = sBattleGroundMgr.GetCreatureEventIndex(u->GetGUIDLow());
        if (!((BattleGroundMap*)map)->GetBG()->IsActiveEvent(eventId.event1, eventId.event2))
            return;
    }

    u->Respawn();
}

void MaNGOS::RespawnDo::operator()(GameObject* u) const
{
    // prevent respawn gameobject for not active BG event
    Map* map = u->GetMap();
    if (map->IsBattleGround())
    {
        BattleGroundEventIdx eventId = sBattleGroundMgr.GetGameObjectEventIndex(u->GetGUIDLow());
        if (!((BattleGroundMap*)map)->GetBG()->IsActiveEvent(eventId.event1, eventId.event2))
            return;
    }

    u->Respawn();
}


template void ObjectUpdater::Visit<GameObject>(GameObjectMapType&);
template void ObjectUpdater::Visit<DynamicObject>(DynamicObjectMapType&);
