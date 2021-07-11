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

#ifndef MANGOS_GRIDNOTIFIERSIMPL_H
#define MANGOS_GRIDNOTIFIERSIMPL_H

#include "GridNotifiers.h"
#include "WorldPacket.h"
#include "Corpse.h"
#include "Player.h"
#include "UpdateData.h"
#include "CreatureAI.h"
#include "SpellAuras.h"
#include "DBCStores.h"
#include "DBCEnums.h"
#include "Spell.h"
#include "SpellMgr.h"

template<class T>
inline void MaNGOS::VisibleNotifier::Visit(GridRefManager<T>& m)
{
    for(typename GridRefManager<T>::iterator iter = m.begin(); iter != m.end(); ++iter)
    {
        i_camera.UpdateVisibilityOf(iter->getSource(), i_data, i_visibleNow);
        i_clientGUIDs.erase(iter->getSource()->GetObjectGuid());
    }
}

inline void MaNGOS::ObjectUpdater::Visit(CreatureMapType& m)
{
    std::vector<Creature*> creaturesToUpdate;
    for (const auto& iter : m)
        creaturesToUpdate.push_back(iter.getSource());
    for (const auto& it : creaturesToUpdate)
    {
        WorldObject::UpdateHelper helper(it);
        helper.UpdateRealTime(i_now, i_timeDiff);
    }
}

inline void CallAIMoveLOS(Creature* c, Unit* moving)
{
    // Creature AI reaction
    if (!c->HasUnitState(UNIT_STAT_LOST_CONTROL | UNIT_STAT_IGNORE_MOVE_LOS) && !c->IsInEvadeMode() && c->AI())
    {
        bool alert = false;
        if (moving->IsVisibleForOrDetect(c, c, true, false, &alert))
              c->AI()->MoveInLineOfSight(moving);
        else
            if (moving->GetTypeId() == TYPEID_PLAYER && moving->HasStealthAura() && alert)
                c->AI()->TriggerAlert(moving);
    }
}

inline void PlayerCreatureRelocationWorker(Player* pl, Creature* c)
{
    CallAIMoveLOS(c, pl);
}

inline void CreatureCreatureRelocationWorker(Creature* c1, Creature* c2)
{
    CallAIMoveLOS(c1, c2);
    CallAIMoveLOS(c2, c1);
}

inline void MaNGOS::PlayerRelocationNotifier::Visit(CreatureMapType& m)
{
    if (!i_player.IsAlive() || i_player.IsTaxiFlying())
        return;

    for(auto & iter : m)
    {
        Creature* c = iter.getSource();
        if (c->IsAlive())
            PlayerCreatureRelocationWorker(&i_player, c);
    }
}

template<>
inline void MaNGOS::CreatureRelocationNotifier::Visit(PlayerMapType& m)
{
    if (!i_creature.IsAlive())
        return;

    for(auto & iter : m)
    {
        Player* player = iter.getSource();
        if (player->IsAlive() && !player->IsTaxiFlying())
            PlayerCreatureRelocationWorker(player, &i_creature);
    }
}

template<>
inline void MaNGOS::CreatureRelocationNotifier::Visit(CreatureMapType& m)
{
    if (!i_creature.IsAlive())
        return;

    for(auto & iter : m)
    {
        Creature* c = iter.getSource();
        if (c != &i_creature && c->IsAlive())
            CreatureCreatureRelocationWorker(c, &i_creature);
    }
}

inline void MaNGOS::DynamicObjectUpdater::VisitHelper(Unit* target)
{
    if (!target->CanSeeInWorld(i_check))
        return;

    if (!target->IsAlive() || target->IsTaxiFlying())
        return;

    if (target->GetTypeId() == TYPEID_UNIT && ((Creature*)target)->IsImmuneToAoe())
        return;

    if (!i_dynobject.IsWithinDistInMap(target, i_dynobject.GetRadius()))
        return;

    //Check targets for not_selectable unit flag and remove
    if (target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE))
        return;

    if (i_dynobject.GetCasterGuid().IsPlayer() && target->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_PLAYER))
        return;

    // Evade target
    if (target->GetTypeId()==TYPEID_UNIT && ((Creature*)target)->IsInEvadeMode())
        return;

    //Check player targets and remove if in GM mode or GM invisibility (for not self casting case)
    if (target->GetTypeId() == TYPEID_PLAYER && target != i_check && (((Player*)target)->IsGameMaster() || ((Player*)target)->GetVisibility() == VISIBILITY_OFF))
        return;

    if (!i_positive && !i_check->IsValidAttackTarget(target))
        return;
    if (i_positive && !i_check->IsFriendlyTo(target))
        return;

    // Must check LoS with the target to prevent casting through objects by targeting
    // the floor. Let creatures cheat
    if (i_dynobject.GetCasterGuid().IsPlayer() && !i_dynobject.IsWithinLOSInMap(target))
        return;

    if (!i_dynobject.NeedsRefresh(target))
        return;

    Unit* pUnit = i_check->ToUnit();

    // Negative AoE from non flagged players cannot target other players
    if (!i_positive)
    {
        if (Player* attackerPlayer = pUnit ? pUnit->GetCharmerOrOwnerPlayerOrPlayerItself() : nullptr)
            if (Player* attackedPlayer = target->GetCharmerOrOwnerPlayerOrPlayerItself())
                if (!attackerPlayer->IsPvP() && !(attackerPlayer->IsFFAPvP() && attackedPlayer->IsFFAPvP()) && !attackerPlayer->IsInDuelWith(attackedPlayer))
                    return;
    }

    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(i_dynobject.GetSpellId());
    SpellEffectIndex eff_index  = i_dynobject.GetEffIndex();

    // Mise en combat
    // Exception : fusee eclairante, piege de givre
    if (pUnit && !i_positive && i_dynobject.GetSpellId() != 1543 && i_dynobject.GetSpellId() != 13810)
    {
        if (CreatureAI* pAi = target->AI())
            pAi->AttackedBy(pUnit);

        target->SetInCombatWithAggressor(pUnit);
        pUnit->SetInCombatWithVictim(target);
    }
    // Check target immune to spell or aura
    if (target->IsImmuneToSpell(spellInfo, false) || target->IsImmuneToSpellEffect(spellInfo, eff_index, false))
        return;

    // Apply PersistentAreaAura on target
    // in case 2 dynobject overlap areas for same spell, same holder is selected, so dynobjects share holder
    SpellAuraHolder* holder = target->GetSpellAuraHolder(spellInfo->Id, i_dynobject.GetCasterGuid());
    bool existing = false;

    if (holder)
    {
        holder->SetInUse(true);
        if (!holder->GetAuraByEffectIndex(eff_index))
        {
            Unit* pCasterUnit = i_dynobject.GetUnitCaster();

            PersistentAreaAura* Aur = new PersistentAreaAura(spellInfo, eff_index, nullptr, holder, target, pCasterUnit);
            holder->AddAura(Aur, eff_index);
            
            target->AddAuraToModList(Aur);
            Aur->ApplyModifier(true,true);
        }
        // Don't update aura time for active channeled spells, otherwise it can become out of sync with the cast
        else if (!i_dynobject.IsChanneled() && holder->GetAuraDuration() >= 0 && uint32(holder->GetAuraDuration()) < i_dynobject.GetDuration())
        {
            holder->SetAuraDuration(i_dynobject.GetDuration());
            holder->UpdateAuraDuration();
        }
        holder->SetInUse(false);

        existing = true;
    }
    else
    {
        WorldObject* pCaster = i_dynobject.GetCaster();
        Unit* pCasterUnit = i_dynobject.GetUnitCaster();

        holder = CreateSpellAuraHolder(spellInfo, target, pCasterUnit, pCaster);
        PersistentAreaAura* Aur = new PersistentAreaAura(spellInfo, eff_index, nullptr, holder, target, pCasterUnit);
        holder->AddAura(Aur, eff_index);

        // Debuff slots may be full, in which case holder is deleted or holder is not able to
        // be added for some reason
        if (!target->AddSpellAuraHolder(holder))
            holder = nullptr;
    }

    if (holder && holder->IsChanneled())
    {
        if (SpellCaster* caster = i_dynobject.GetCaster())
        {
            // Caster is channeling this spell, update current channel spell holders with
            // the new holder. Don't check channel object, as it might be a spell with
            // multiple dyn objs
            if (Spell* spell = caster->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
            {
                if (spell->m_spellInfo->Id == spellInfo->Id)
                {
                    if (!existing)
                        spell->AddChanneledAuraHolder(holder);

                    holder->SetAuraDuration(spell->GetCastedTime());
                    holder->RefreshAuraPeriodicTimers(); // make sure we are ticking in sync with the spell cast time
                    holder->UpdateAuraDuration();
                }
            }
        }
    }

    i_dynobject.AddAffected(target);
}

template<>
inline void MaNGOS::DynamicObjectUpdater::Visit(CreatureMapType& m)
{
    for(auto & itr : m)
        VisitHelper(itr.getSource());
}

template<>
inline void MaNGOS::DynamicObjectUpdater::Visit(PlayerMapType& m)
{
    for(auto & itr : m)
        VisitHelper(itr.getSource());
}

// SEARCHERS & LIST SEARCHERS & WORKERS

// WorldObject searchers & workers

template<class Check>
void MaNGOS::WorldObjectSearcher<Check>::Visit(GameObjectMapType& m)
{
    // already found
    if (i_object)
        return;

    for(auto & itr : m)
    {
        if (i_check(itr.getSource()))
        {
            i_object = itr.getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::WorldObjectSearcher<Check>::Visit(PlayerMapType& m)
{
    // already found
    if (i_object)
        return;

    for(auto & itr : m)
    {
        if (i_check(itr.getSource()))
        {
            i_object = itr.getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::WorldObjectSearcher<Check>::Visit(CreatureMapType& m)
{
    // already found
    if (i_object)
        return;

    for(auto & itr : m)
    {
        if (i_check(itr.getSource()))
        {
            i_object = itr.getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::WorldObjectSearcher<Check>::Visit(CorpseMapType& m)
{
    // already found
    if (i_object)
        return;

    for(auto & itr : m)
    {
        if (i_check(itr.getSource()))
        {
            i_object = itr.getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::WorldObjectSearcher<Check>::Visit(DynamicObjectMapType& m)
{
    // already found
    if (i_object)
        return;

    for(auto & itr : m)
    {
        if (i_check(itr.getSource()))
        {
            i_object = itr.getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::WorldObjectListSearcher<Check>::Visit(PlayerMapType& m)
{
    for(auto & itr : m)
        if (i_check(itr.getSource()))
            i_objects.push_back(itr.getSource());
}

template<class Check>
void MaNGOS::WorldObjectListSearcher<Check>::Visit(CreatureMapType& m)
{
    for(auto & itr : m)
        if (i_check(itr.getSource()))
            i_objects.push_back(itr.getSource());
}

template<class Check>
void MaNGOS::WorldObjectListSearcher<Check>::Visit(CorpseMapType& m)
{
    for(auto & itr : m)
        if (i_check(itr.getSource()))
            i_objects.push_back(itr.getSource());
}

template<class Check>
void MaNGOS::WorldObjectListSearcher<Check>::Visit(GameObjectMapType& m)
{
    for(auto & itr : m)
        if (i_check(itr.getSource()))
            i_objects.push_back(itr.getSource());
}

template<class Check>
void MaNGOS::WorldObjectListSearcher<Check>::Visit(DynamicObjectMapType& m)
{
    for(auto & itr : m)
        if (i_check(itr.getSource()))
            i_objects.push_back(itr.getSource());
}

// Gameobject searchers

template<class Check>
void MaNGOS::GameObjectSearcher<Check>::Visit(GameObjectMapType& m)
{
    // already found
    if (i_object)
        return;

    for(auto & itr : m)
    {
        if (i_check(itr.getSource()))
        {
            i_object = itr.getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::GameObjectLastSearcher<Check>::Visit(GameObjectMapType& m)
{
    for(auto & itr : m)
    {
        if (i_check(itr.getSource()))
            i_object = itr.getSource();
    }
}

template<class Check>
void MaNGOS::GameObjectListSearcher<Check>::Visit(GameObjectMapType& m)
{
    for(auto & itr : m)
        if (i_check(itr.getSource()))
            i_objects.push_back(itr.getSource());
}

// Unit searchers

template<class Check>
void MaNGOS::UnitSearcher<Check>::Visit(CreatureMapType& m)
{
    // already found
    if (i_object)
        return;

    for(auto & itr : m)
    {
        if (i_check(itr.getSource()))
        {
            i_object = itr.getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::UnitSearcher<Check>::Visit(PlayerMapType& m)
{
    // already found
    if (i_object)
        return;

    for(PlayerMapType::iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        if (i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::UnitLastSearcher<Check>::Visit(CreatureMapType& m)
{
    for(auto & itr : m)
    {
        if (i_check(itr.getSource()))
            i_object = itr.getSource();
    }
}

template<class Check>
void MaNGOS::UnitLastSearcher<Check>::Visit(PlayerMapType& m)
{
    for(auto & itr : m)
    {
        if (i_check(itr.getSource()))
            i_object = itr.getSource();
    }
}

template<class Check>
void MaNGOS::UnitListSearcher<Check>::Visit(PlayerMapType& m)
{
    for(auto & itr : m)
        if (i_check(itr.getSource()))
            i_objects.push_back(itr.getSource());
}

template<class Check>
void MaNGOS::UnitListSearcher<Check>::Visit(CreatureMapType& m)
{
    for(auto & itr : m)
        if (i_check(itr.getSource()))
            i_objects.push_back(itr.getSource());
}

// Creature searchers

template<class Check>
void MaNGOS::CreatureSearcher<Check>::Visit(CreatureMapType& m)
{
    // already found
    if (i_object)
        return;

    for(CreatureMapType::iterator itr = m.begin(); itr != m.end(); ++itr)
    {
        if (i_check(itr->getSource()))
        {
            i_object = itr->getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::CreatureLastSearcher<Check>::Visit(CreatureMapType& m)
{
    for(auto & itr : m)
    {
        if (i_check(itr.getSource()))
            i_object = itr.getSource();
    }
}

template<class Check>
void MaNGOS::CreatureListSearcher<Check>::Visit(CreatureMapType& m)
{
    for(auto & itr : m)
        if (i_check(itr.getSource()))
            i_objects.push_back(itr.getSource());
}

template<class Check>
void MaNGOS::PlayerSearcher<Check>::Visit(PlayerMapType& m)
{
    // already found
    if (i_object)
        return;

    for(auto & itr : m)
    {
        if (i_check(itr.getSource()))
        {
            i_object = itr.getSource();
            return;
        }
    }
}

template<class Check>
void MaNGOS::PlayerLastSearcher<Check>::Visit(PlayerMapType& m)
{
    for (const auto& itr : m)
    {
        if (i_check(itr.getSource()))
            i_object = itr.getSource();
    }
}

template<class Check>
void MaNGOS::PlayerListSearcher<Check>::Visit(PlayerMapType& m)
{
    for(auto & itr : m)
        if (i_check(itr.getSource()))
            i_objects.push_back(itr.getSource());
}

template<class Builder>
void MaNGOS::LocalizedPacketDo<Builder>::operator()(Player* p)
{
    int32 loc_idx = p->GetSession()->GetSessionDbLocaleIndex();
    uint32 cache_idx = loc_idx + 1;

    // create if not cached yet
    if (i_data_cache.size() < cache_idx + 1 || !i_data_cache[cache_idx])
    {
        if (i_data_cache.size() < cache_idx + 1)
            i_data_cache.resize(cache_idx + 1);

        auto data = std::unique_ptr<WorldPacket>(new WorldPacket());

        i_builder(*data, loc_idx);

        i_data_cache[cache_idx] = std::move(data);
    }

    p->SendDirectMessage(i_data_cache[cache_idx].get());
}

template<class Builder>
void MaNGOS::LocalizedPacketListDo<Builder>::operator()(Player* p)
{
    int32 loc_idx = p->GetSession()->GetSessionDbLocaleIndex();
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

    for(auto & i : *data_list)
        p->SendDirectMessage(i);
}

#endif                                                      // MANGOS_GRIDNOTIFIERSIMPL_H
