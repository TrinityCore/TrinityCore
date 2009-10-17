/*
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
 *
 * Copyright (C) 2008-2009 Trinity <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef TRINITY_GRIDNOTIFIERSIMPL_H
#define TRINITY_GRIDNOTIFIERSIMPL_H

#include "GridNotifiers.h"
#include "WorldPacket.h"
#include "Corpse.h"
#include "Player.h"
#include "UpdateData.h"
#include "CreatureAI.h"
#include "SpellAuras.h"

inline void
Trinity::ObjectUpdater::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator iter=m.begin(); iter != m.end(); ++iter)
        if(iter->getSource()->IsInWorld() && !iter->getSource()->isSpiritService())
            iter->getSource()->Update(i_timeDiff);
}

inline void PlayerCreatureRelocationWorker(Player* pl, Creature* c)
{
    if(!pl->isAlive() || !c->isAlive() || pl->isInFlight())
        return;

    // Creature AI reaction
    if(c->HasReactState(REACT_AGGRESSIVE) && !c->hasUnitState(UNIT_STAT_SIGHTLESS))
        if(c->_IsWithinDist(pl, c->m_SightDistance, true) && c->IsAIEnabled)
            c->AI()->MoveInLineOfSight(pl);
}

inline void CreatureCreatureRelocationWorker(Creature* c1, Creature* c2)
{
    if(c1->HasReactState(REACT_AGGRESSIVE) && !c1->hasUnitState(UNIT_STAT_SIGHTLESS))
        if(c1->_IsWithinDist(c2, c1->m_SightDistance, true) && c1->IsAIEnabled)
            c1->AI()->MoveInLineOfSight(c2);

    if(c2->HasReactState(REACT_AGGRESSIVE) && !c2->hasUnitState(UNIT_STAT_SIGHTLESS))
        if(c1->_IsWithinDist(c2, c2->m_SightDistance, true) && c2->IsAIEnabled)
            c2->AI()->MoveInLineOfSight(c1);
}

template<class T>
inline void
Trinity::PlayerVisibilityNotifier::Visit(GridRefManager<T> &m)
{
    for (typename GridRefManager<T>::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        i_player.UpdateVisibilityOf(iter->getSource(),i_data,i_visibleNow);
        i_clientGUIDs.erase(iter->getSource()->GetGUID());
    }
}

template<>
inline void
Trinity::PlayerRelocationNotifier::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        i_clientGUIDs.erase(iter->getSource()->GetGUID());

        if(iter->getSource()->m_Notified) //self is also skipped in this check
            continue;

        i_player.UpdateVisibilityOf(iter->getSource(),i_data,i_visibleNow);
        iter->getSource()->UpdateVisibilityOf(&i_player);

        //if (!i_player.GetSharedVisionList().empty())
        //    for (SharedVisionList::const_iterator it = i_player.GetSharedVisionList().begin(); it != i_player.GetSharedVisionList().end(); ++it)
        //        (*it)->UpdateVisibilityOf(iter->getSource());

        // Cancel Trade
        if(i_player.GetTrader()==iter->getSource())
            if(!i_player.IsWithinDistInMap(iter->getSource(), 5)) // iteraction distance
                i_player.GetSession()->SendCancelTrade();   // will clode both side trade windows
    }
}

template<>
inline void
Trinity::PlayerRelocationNotifier::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        i_clientGUIDs.erase(iter->getSource()->GetGUID());

        if(iter->getSource()->m_Notified)
            continue;

        i_player.UpdateVisibilityOf(iter->getSource(),i_data,i_visibleNow);

        PlayerCreatureRelocationWorker(&i_player, iter->getSource());
    }
}

template<>
inline void
Trinity::CreatureRelocationNotifier::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        if(iter->getSource()->m_Notified)
            continue;

        iter->getSource()->UpdateVisibilityOf(&i_creature);

        PlayerCreatureRelocationWorker(iter->getSource(), &i_creature);
    }
}

template<>
inline void
Trinity::CreatureRelocationNotifier::Visit(CreatureMapType &m)
{
    if(!i_creature.isAlive())
        return;

    for (CreatureMapType::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        if(iter->getSource()->m_Notified)
            continue;

        if(!iter->getSource()->isAlive())
            continue;

        CreatureCreatureRelocationWorker(iter->getSource(), &i_creature);
    }
}

inline void Trinity::DynamicObjectUpdater::VisitHelper(Unit* target)
{
    if(!target->isAlive() || target->isInFlight() )
        return;

    if(target->GetTypeId()==TYPEID_UNIT && ((Creature*)target)->isTotem())
        return;

    if (!i_dynobject.IsWithinDistInMap(target, i_dynobject.GetRadius()))
        return;

    //Check targets for not_selectable unit flag and remove
    if (target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE))
        return;

    // Evade target
    if( target->GetTypeId()==TYPEID_UNIT && ((Creature*)target)->IsInEvadeMode() )
        return;

    //Check player targets and remove if in GM mode or GM invisibility (for not self casting case)
    if( target->GetTypeId()==TYPEID_PLAYER && target != i_check && (((Player*)target)->isGameMaster() || ((Player*)target)->GetVisibility()==VISIBILITY_OFF) )
        return;

    if (i_dynobject.IsAffecting(target))
        return;

    if(target->HasAura(i_dynobject.GetSpellId(), i_check->GetGUID()))
        return;

    uint32 eff_index = 0;
    for (; eff_index < MAX_SPELL_EFFECTS; ++eff_index)
        if(i_dynobject.HasEffect(eff_index))
            break;

    if(eff_index == MAX_SPELL_EFFECTS)
        return;

    SpellEntry const *spellInfo = sSpellStore.LookupEntry(i_dynobject.GetSpellId());
    if(spellInfo->EffectImplicitTargetB[eff_index] == TARGET_DEST_DYNOBJ_ALLY
        || spellInfo->EffectImplicitTargetB[eff_index] == TARGET_UNIT_AREA_ALLY_DST)
    {
        if(!i_check->IsFriendlyTo(target))
            return;
    }
    else if( i_check->GetTypeId()==TYPEID_PLAYER )
    {
        if (i_check->IsFriendlyTo( target ))
            return;

        i_check->CombatStart(target);
    }
    else
    {
        if (!i_check->IsHostileTo( target ))
            return;

        i_check->CombatStart(target);
    }

    // Check target immune to spell or aura
    if (target->IsImmunedToSpell(spellInfo) || target->IsImmunedToSpellEffect(spellInfo, eff_index))
        return;

    // Apply PersistentAreaAura on target
    Aura *aur = new Aura(spellInfo, i_dynobject.GetEffectMask(), target, &i_dynobject, i_check);
    aur->SetAuraDuration(i_dynobject.GetDuration());
    if(target->AddAura(aur, true))
        i_dynobject.AddAffected(target);
}

template<>
inline void
Trinity::DynamicObjectUpdater::Visit(CreatureMapType  &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        VisitHelper(itr->getSource());
}

template<>
inline void
Trinity::DynamicObjectUpdater::Visit(PlayerMapType  &m)
{
    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        VisitHelper(itr->getSource());
}

// SEARCHERS & LIST SEARCHERS & WORKERS

// WorldObject searchers & workers

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(GameObjectMapType &m)
{
    // already found
    if(i_object)
        return;

    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if (i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(PlayerMapType &m)
{
    // already found
    if(i_object)
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(CreatureMapType &m)
{
    // already found
    if(i_object)
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(CorpseMapType &m)
{
    // already found
    if(i_object)
        return;

    for (CorpseMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectSearcher<Check>::Visit(DynamicObjectMapType &m)
{
    // already found
    if(i_object)
        return;

    for (DynamicObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(itr->getSource()->InSamePhase(i_phaseMask))
            if(i_check(itr->getSource()))
                i_objects.push_back(itr->getSource());
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(itr->getSource()->InSamePhase(i_phaseMask))
            if(i_check(itr->getSource()))
                i_objects.push_back(itr->getSource());
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(CorpseMapType &m)
{
    for (CorpseMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(itr->getSource()->InSamePhase(i_phaseMask))
            if(i_check(itr->getSource()))
                i_objects.push_back(itr->getSource());
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(GameObjectMapType &m)
{
    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(itr->getSource()->InSamePhase(i_phaseMask))
            if(i_check(itr->getSource()))
                i_objects.push_back(itr->getSource());
}

template<class Check>
void Trinity::WorldObjectListSearcher<Check>::Visit(DynamicObjectMapType &m)
{
    for (DynamicObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(itr->getSource()->InSamePhase(i_phaseMask))
            if(i_check(itr->getSource()))
                i_objects.push_back(itr->getSource());
}

// Gameobject searchers

template<class Check>
void Trinity::GameObjectSearcher<Check>::Visit(GameObjectMapType &m)
{
    // already found
    if(i_object)
        return;

    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void Trinity::GameObjectLastSearcher<Check>::Visit(GameObjectMapType &m)
{
    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
            i_object = itr->getSource();
    }
}

template<class Check>
void Trinity::GameObjectListSearcher<Check>::Visit(GameObjectMapType &m)
{
    for (GameObjectMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(itr->getSource()->InSamePhase(i_phaseMask))
            if(i_check(itr->getSource()))
                i_objects.push_back(itr->getSource());
}

// Unit searchers

template<class Check>
void Trinity::UnitSearcher<Check>::Visit(CreatureMapType &m)
{
    // already found
    if(i_object)
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void Trinity::UnitSearcher<Check>::Visit(PlayerMapType &m)
{
    // already found
    if(i_object)
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void Trinity::UnitLastSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
            i_object = itr->getSource();
    }
}

template<class Check>
void Trinity::UnitLastSearcher<Check>::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
            i_object = itr->getSource();
    }
}

template<class Check>
void Trinity::UnitListSearcher<Check>::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(itr->getSource()->InSamePhase(i_phaseMask))
            if(i_check(itr->getSource()))
                i_objects.push_back(itr->getSource());
}

template<class Check>
void Trinity::UnitListSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(itr->getSource()->InSamePhase(i_phaseMask))
            if(i_check(itr->getSource()))
                i_objects.push_back(itr->getSource());
}

// Creature searchers

template<class Check>
void Trinity::CreatureSearcher<Check>::Visit(CreatureMapType &m)
{
    // already found
    if(i_object)
        return;

    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void Trinity::CreatureLastSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
            i_object = itr->getSource();
    }
}

template<class Check>
void Trinity::CreatureListSearcher<Check>::Visit(CreatureMapType &m)
{
    for (CreatureMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(itr->getSource()->InSamePhase(i_phaseMask))
            if( i_check(itr->getSource()))
                i_objects.push_back(itr->getSource());
}

template<class Check>
void Trinity::PlayerListSearcher<Check>::Visit(PlayerMapType &m)
{
    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
        if(itr->getSource()->InSamePhase(i_phaseMask))
            if( i_check(itr->getSource()))
                i_objects.push_back(itr->getSource());
}

template<class Check>
void Trinity::PlayerSearcher<Check>::Visit(PlayerMapType &m)
{
    // already found
    if(i_object)
        return;

    for (PlayerMapType::iterator itr=m.begin(); itr != m.end(); ++itr)
    {
        if(!itr->getSource()->InSamePhase(i_phaseMask))
            continue;

        if(i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Builder>
void MaNGOS::LocalizedPacketDo<Builder>::operator()( Player* p )
{
    int32 loc_idx = p->GetSession()->GetSessionDbLocaleIndex();
    uint32 cache_idx = loc_idx+1;
    WorldPacket* data;

    // create if not cached yet
    if(i_data_cache.size() < cache_idx+1 || !i_data_cache[cache_idx])
    {
        if(i_data_cache.size() < cache_idx+1)
            i_data_cache.resize(cache_idx+1);

        data = new WorldPacket(SMSG_MESSAGECHAT, 200);

        i_builder(*data,loc_idx);

        i_data_cache[cache_idx] = data;
    }
    else
        data = i_data_cache[cache_idx];

    p->SendDirectMessage(data);
}

template<class Builder>
void MaNGOS::LocalizedPacketListDo<Builder>::operator()( Player* p )
{
    int32 loc_idx = p->GetSession()->GetSessionDbLocaleIndex();
    uint32 cache_idx = loc_idx+1;
    WorldPacketList* data_list;

    // create if not cached yet
    if(i_data_cache.size() < cache_idx+1 || i_data_cache[cache_idx].empty())
    {
        if(i_data_cache.size() < cache_idx+1)
            i_data_cache.resize(cache_idx+1);

        data_list = &i_data_cache[cache_idx];

        i_builder(*data_list,loc_idx);
    }
    else
        data_list = &i_data_cache[cache_idx];

    for (size_t i = 0; i < data_list->size(); ++i)
        p->SendDirectMessage((*data_list)[i]);
}

struct ObjectDistanceOrder : public std::binary_function<const WorldObject, const WorldObject, bool>
{
    const Unit* m_pSource;

    ObjectDistanceOrder(const Unit* pSource) : m_pSource(pSource) {};

    bool operator()(const WorldObject* pLeft, const WorldObject* pRight) const
    {
        return m_pSource->GetDistanceOrder(pLeft, pRight);
    }
};

struct ObjectDistanceOrderReversed : public std::binary_function<const WorldObject, const WorldObject, bool>
{
    const Unit* m_pSource;

    ObjectDistanceOrderReversed(const Unit* pSource) : m_pSource(pSource) {};

    bool operator()(const WorldObject* pLeft, const WorldObject* pRight) const
    {
        return !m_pSource->GetDistanceOrder(pLeft, pRight);
    }
};

#endif                                                      // MANGOS_GRIDNOTIFIERSIMPL_H
