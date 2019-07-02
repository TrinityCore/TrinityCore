/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
 * Copyright (C) 2005-2009 MaNGOS <http://getmangos.com/>
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

#include "TotemAI.h"
#include "CellImpl.h"
#include "Creature.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "ObjectAccessor.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Totem.h"

int32 TotemAI::Permissible(Creature const* creature)
{
    if (creature->IsTotem())
        return PERMIT_BASE_PROACTIVE;

    return PERMIT_BASE_NO;
}

TotemAI::TotemAI(Creature* creature) : CreatureAI(creature), _victimGUID()
{
    ASSERT(creature->IsTotem(), "TotemAI: AI assigned to a no-totem creature (%s)!", creature->GetGUID().ToString().c_str());
}

void TotemAI::MoveInLineOfSight(Unit* /*who*/) { }

void TotemAI::EnterEvadeMode(EvadeReason /*why*/)
{
    me->CombatStop(true);
}

void TotemAI::UpdateAI(uint32 /*diff*/)
{
    if (me->ToTotem()->GetTotemType() != TOTEM_ACTIVE)
        return;

    if (!me->IsAlive() || me->IsNonMeleeSpellCast(false))
        return;

    // Search spell
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(me->ToTotem()->GetSpell());
    if (!spellInfo)
        return;

    // Get spell range
    float max_range = spellInfo->GetMaxRange(false);

    // SPELLMOD_RANGE not applied in this place just because not existence range mods for attacking totems

    // pointer to appropriate target if found any
    Unit* victim = _victimGUID ? ObjectAccessor::GetUnit(*me, _victimGUID) : nullptr;

    // Search victim if no, not attackable, or out of range, or friendly (possible in case duel end)
    if (!victim || !victim->isTargetableForAttack() || !me->IsWithinDistInMap(victim, max_range) || me->IsFriendlyTo(victim) || !me->CanSeeOrDetect(victim))
    {
        victim = nullptr;
        Trinity::NearestAttackableUnitInObjectRangeCheck u_check(me, me->GetCharmerOrOwnerOrSelf(), max_range);
        Trinity::UnitLastSearcher<Trinity::NearestAttackableUnitInObjectRangeCheck> checker(me, victim, u_check);
        Cell::VisitAllObjects(me, checker, max_range);
    }

    // If have target
    if (victim)
    {
        // remember
        _victimGUID = victim->GetGUID();

        // attack
        me->CastSpell(victim, me->ToTotem()->GetSpell());
    }
    else
        _victimGUID.Clear();
}

void TotemAI::AttackStart(Unit* /*victim*/)
{
    // Sentry totem sends ping on attack
    if (me->GetEntry() == SENTRY_TOTEM_ENTRY)
    {
        if (Unit* owner = me->GetOwner())
            if (Player* player = owner->ToPlayer())
            {
                WorldPacket data(MSG_MINIMAP_PING, (8 + 4 + 4));
                data << me->GetGUID();
                data << me->GetPositionX();
                data << me->GetPositionY();
                player->SendDirectMessage(&data);
            }
    }
}
