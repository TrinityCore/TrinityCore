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
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "TotemAI.h"
#include "Totem.h"
#include "Creature.h"
#include "DBCStores.h"
#include "ObjectAccessor.h"
#include "SpellMgr.h"

#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"

int
TotemAI::Permissible(const Creature *creature)
{
    if (creature->isTotem())
        return PERMIT_BASE_PROACTIVE;

    return PERMIT_BASE_NO;
}

TotemAI::TotemAI(Creature *c) : CreatureAI(c), i_victimGuid(0)
{
    assert(c->isTotem());
}

void
TotemAI::MoveInLineOfSight(Unit *)
{
}

void TotemAI::EnterEvadeMode()
{
    me->CombatStop(true);
}

void
TotemAI::UpdateAI(const uint32 /*diff*/)
{
  if (me->ToTotem()->GetTotemType() != TOTEM_ACTIVE)
        return;

    if (!me->isAlive() || me->IsNonMeleeSpellCasted(false))
        return;

    // Search spell
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(me->ToTotem()->GetSpell());
    if (!spellInfo)
        return;

    // Get spell range
    SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(spellInfo->rangeIndex);
    float max_range = GetSpellMaxRangeForHostile(srange);

    // SPELLMOD_RANGE not applied in this place just because not existence range mods for attacking totems

    // pointer to appropriate target if found any
    Unit* victim = i_victimGuid ? ObjectAccessor::GetUnit(*me, i_victimGuid) : NULL;

    // Search victim if no, not attackable, or out of range, or friendly (possible in case duel end)
    if (!victim ||
        !victim->isTargetableForAttack() || !me->IsWithinDistInMap(victim, max_range) ||
        me->IsFriendlyTo(victim) || !victim->isVisibleForOrDetect(me,false))
    {
        victim = NULL;
        Trinity::NearestAttackableUnitInObjectRangeCheck u_check(me, me, max_range);
        Trinity::UnitLastSearcher<Trinity::NearestAttackableUnitInObjectRangeCheck> checker(me, victim, u_check);
        me->VisitNearbyObject(max_range, checker);
    }

    // If have target
    if (victim)
    {
        // remember
        i_victimGuid = victim->GetGUID();

        // attack
        me->SetInFront(victim);                         // client change orientation by self
        me->CastSpell(victim, me->ToTotem()->GetSpell(), false);
    }
    else
        i_victimGuid = 0;
}

void
TotemAI::AttackStart(Unit *)
{
    // Sentry totem sends ping on attack
    if (me->GetEntry() == SENTRY_TOTEM_ENTRY && me->GetOwner()->GetTypeId() == TYPEID_PLAYER)
    {
        WorldPacket data(MSG_MINIMAP_PING, (8+4+4));
        data << me->GetGUID();
        data << me->GetPositionX();
        data << me->GetPositionY();
        ((Player*)me->GetOwner())->GetSession()->SendPacket(&data);
    }
}
