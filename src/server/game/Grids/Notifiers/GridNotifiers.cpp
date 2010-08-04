/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2010 Trinity <http://www.trinitycore.org/>
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
#include "GridNotifiersImpl.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "UpdateData.h"
#include "Item.h"
#include "Map.h"
#include "Transport.h"
#include "ObjectAccessor.h"
#include "CellImpl.h"

using namespace Trinity;

void
VisibleNotifier::SendToSelf()
{
    // at this moment i_clientGUIDs have guids that not iterate at grid level checks
    // but exist one case when this possible and object not out of range: transports
    if (Transport* transport = i_player.GetTransport())
        for (Transport::PlayerSet::const_iterator itr = transport->GetPassengers().begin();itr != transport->GetPassengers().end();++itr)
        {
            if (vis_guids.find((*itr)->GetGUID()) != vis_guids.end())
            {
                vis_guids.erase((*itr)->GetGUID());

                i_player.UpdateVisibilityOf((*itr), i_data, i_visibleNow);

                if (!(*itr)->isNeedNotify(NOTIFY_VISIBILITY_CHANGED))
                    (*itr)->UpdateVisibilityOf(&i_player);
            }
        }

    for (Player::ClientGUIDs::const_iterator it = vis_guids.begin();it != vis_guids.end(); ++it)
    {
        i_player.m_clientGUIDs.erase(*it);
        i_data.AddOutOfRangeGUID(*it);

        if (IS_PLAYER_GUID(*it))
        {
            Player* plr = ObjectAccessor::FindPlayer(*it);
            if (plr && plr->IsInWorld() && !plr->isNeedNotify(NOTIFY_VISIBILITY_CHANGED))
                plr->UpdateVisibilityOf(&i_player);
        }
    }

    if (!i_data.HasData())
        return;

    WorldPacket packet;
    i_data.BuildPacket(&packet);
    i_player.GetSession()->SendPacket(&packet);

    for (std::set<Unit*>::const_iterator it = i_visibleNow.begin(); it != i_visibleNow.end(); ++it)
        i_player.SendInitialVisiblePackets(*it);
}

void
VisibleChangesNotifier::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator iter=m.begin(); iter != m.end(); ++iter)
    {
        if (iter->getSource() == &i_object)
            continue;

        iter->getSource()->UpdateVisibilityOf(&i_object);

        if (!iter->getSource()->GetSharedVisionList().empty())
            for (SharedVisionList::const_iterator i = iter->getSource()->GetSharedVisionList().begin();
                i != iter->getSource()->GetSharedVisionList().end(); ++i)
                if ((*i)->m_seer == iter->getSource())
                    (*i)->UpdateVisibilityOf(&i_object);
    }
}

void
VisibleChangesNotifier::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
        if (!iter->getSource()->GetSharedVisionList().empty())
            for (SharedVisionList::const_iterator i = iter->getSource()->GetSharedVisionList().begin();
                i != iter->getSource()->GetSharedVisionList().end(); ++i)
                if ((*i)->m_seer == iter->getSource())
                    (*i)->UpdateVisibilityOf(&i_object);
}

void
VisibleChangesNotifier::Visit(DynamicObjectMapType &m)
{
    for (DynamicObjectMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
        if (IS_PLAYER_GUID(iter->getSource()->GetCasterGUID()))
            if (Player* caster = (Player*)iter->getSource()->GetCaster())
                if (caster->m_seer == iter->getSource())
                    caster->UpdateVisibilityOf(&i_object);
}

inline void CreatureUnitRelocationWorker(Creature* c, Unit* u)
{
    if (!u->isAlive() || !c->isAlive() || c == u || u->isInFlight())
        return;

    if (c->HasReactState(REACT_AGGRESSIVE) && !c->hasUnitState(UNIT_STAT_SIGHTLESS))
        if (c->_IsWithinDist(u, c->m_SightDistance, true) && c->IsAIEnabled)
            c->AI()->MoveInLineOfSight_Safe(u);
}

void PlayerRelocationNotifier::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator iter=m.begin(); iter != m.end(); ++iter)
    {
        Player* plr = iter->getSource();

        vis_guids.erase(plr->GetGUID());

        i_player.UpdateVisibilityOf(plr,i_data,i_visibleNow);

        if (plr->m_seer->isNeedNotify(NOTIFY_VISIBILITY_CHANGED))
            continue;

        plr->UpdateVisibilityOf(&i_player);
    }
}

void PlayerRelocationNotifier::Visit(CreatureMapType &m)
{
    bool relocated_for_ai = (&i_player == i_player.m_seer);

    for (CreatureMapType::iterator iter=m.begin(); iter != m.end(); ++iter)
    {
        Creature * c = iter->getSource();

        vis_guids.erase(c->GetGUID());

        i_player.UpdateVisibilityOf(c,i_data,i_visibleNow);

        if (relocated_for_ai && !c->isNeedNotify(NOTIFY_VISIBILITY_CHANGED))
            CreatureUnitRelocationWorker(c, &i_player);
    }
}

void CreatureRelocationNotifier::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator iter=m.begin(); iter != m.end(); ++iter)
    {
        Player * pl = iter->getSource();

        if (!pl->m_seer->isNeedNotify(NOTIFY_VISIBILITY_CHANGED))
            pl->UpdateVisibilityOf(&i_creature);

        CreatureUnitRelocationWorker(&i_creature, pl);
    }
}

void CreatureRelocationNotifier::Visit(CreatureMapType &m)
{
    if (!i_creature.isAlive())
        return;

    for (CreatureMapType::iterator iter=m.begin(); iter != m.end(); ++iter)
    {
        Creature* c = iter->getSource();
        CreatureUnitRelocationWorker(&i_creature, c);

        if (!c->isNeedNotify(NOTIFY_VISIBILITY_CHANGED))
            CreatureUnitRelocationWorker(c, &i_creature);
    }
}

void DelayedUnitRelocation::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        Creature * unit = iter->getSource();
        if (!unit->isNeedNotify(NOTIFY_VISIBILITY_CHANGED))
            continue;

        CreatureRelocationNotifier relocate(*unit);

        TypeContainerVisitor<CreatureRelocationNotifier, WorldTypeMapContainer > c2world_relocation(relocate);
        TypeContainerVisitor<CreatureRelocationNotifier, GridTypeMapContainer >  c2grid_relocation(relocate);

        cell.Visit(p, c2world_relocation, i_map, *unit, i_radius);
        cell.Visit(p, c2grid_relocation, i_map, *unit, i_radius);
    }
}

void DelayedUnitRelocation::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        Player * player = iter->getSource();
        WorldObject const *viewPoint = player->m_seer;

        if (!viewPoint->isNeedNotify(NOTIFY_VISIBILITY_CHANGED))
            continue;

        if (player != viewPoint && !viewPoint->IsPositionValid())
            continue;

        CellPair pair2(Trinity::ComputeCellPair(viewPoint->GetPositionX(), viewPoint->GetPositionY()));
        Cell cell2(pair2);
        //cell.SetNoCreate(); need load cells around viewPoint or player, that's why its commented

        PlayerRelocationNotifier relocate(*player);
        TypeContainerVisitor<PlayerRelocationNotifier, WorldTypeMapContainer > c2world_relocation(relocate);
        TypeContainerVisitor<PlayerRelocationNotifier, GridTypeMapContainer >  c2grid_relocation(relocate);

        cell2.Visit(pair2, c2world_relocation, i_map, *viewPoint, i_radius);
        cell2.Visit(pair2, c2grid_relocation, i_map, *viewPoint, i_radius);

        relocate.SendToSelf();
    }
}

void AIRelocationNotifier::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        Creature *c = iter->getSource();
        CreatureUnitRelocationWorker(c, &i_unit);
        if (isCreature)
            CreatureUnitRelocationWorker((Creature*)&i_unit, c);
    }
}

void
MessageDistDeliverer::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        Player *target = iter->getSource();
        if (!target->InSamePhase(i_phaseMask))
            continue;

        if (target->GetExactDistSq(i_source) > i_distSq)
            continue;

        // Send packet to all who are sharing the player's vision
        if (!target->GetSharedVisionList().empty())
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

void
MessageDistDeliverer::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        if (!iter->getSource()->InSamePhase(i_phaseMask))
            continue;

        if (iter->getSource()->GetExactDistSq(i_source) > i_distSq)
            continue;

        // Send packet to all who are sharing the creature's vision
        if (!iter->getSource()->GetSharedVisionList().empty())
        {
            SharedVisionList::const_iterator i = iter->getSource()->GetSharedVisionList().begin();
            for (; i != iter->getSource()->GetSharedVisionList().end(); ++i)
                if ((*i)->m_seer == iter->getSource())
                    SendPacket(*i);
        }
    }
}

void
MessageDistDeliverer::Visit(DynamicObjectMapType &m)
{
    for (DynamicObjectMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        if (!iter->getSource()->InSamePhase(i_phaseMask))
            continue;

        if (iter->getSource()->GetExactDistSq(i_source) > i_distSq)
            continue;

        if (IS_PLAYER_GUID(iter->getSource()->GetCasterGUID()))
        {
            // Send packet back to the caster if the caster has vision of dynamic object
            Player* caster = (Player*)iter->getSource()->GetCaster();
            if (caster && caster->m_seer == iter->getSource())
                SendPacket(caster);
        }
    }
}

/*
void
MessageDistDeliverer::VisitObject(Player* plr)
{
    if (!i_ownTeamOnly || (i_source.GetTypeId() == TYPEID_PLAYER && plr->GetTeam() == ((Player&)i_source).GetTeam()))
    {
        SendPacket(plr);
    }
}
*/

template<class T> void
ObjectUpdater::Visit(GridRefManager<T> &m)
{
    for (typename GridRefManager<T>::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        if (iter->getSource()->IsInWorld())
            iter->getSource()->Update(i_timeDiff);
    }
}

bool CannibalizeObjectCheck::operator()(Corpse* u)
{
    // ignore bones
    if (u->GetType() == CORPSE_BONES)
        return false;

    Player* owner = ObjectAccessor::FindPlayer(u->GetOwnerGUID());

    if (!owner || i_funit->IsFriendlyTo(owner))
        return false;

    if (i_funit->IsWithinDistInMap(u, i_range))
        return true;

    return false;
}

bool CarrionFeederObjectCheck::operator()(Corpse* u)
{
    // ignore bones
    if (u->GetType() == CORPSE_BONES)
        return false;

    Player* owner = ObjectAccessor::FindPlayer(u->GetOwnerGUID());

    if (!owner || i_funit->IsFriendlyTo(owner))
        return false;

    if (i_funit->IsWithinDistInMap(u, i_range))
        return true;

    return false;
}

template void ObjectUpdater::Visit<GameObject>(GameObjectMapType &);
template void ObjectUpdater::Visit<DynamicObject>(DynamicObjectMapType &);
