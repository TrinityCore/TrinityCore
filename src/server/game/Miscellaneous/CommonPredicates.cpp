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

#include "CommonPredicates.h"
#include "Unit.h"

Trinity::Predicates::IsVictimOf::IsVictimOf(Unit const* attacker) : _victim(attacker ? attacker->GetVictim() : nullptr) { }

bool Trinity::Predicates::PowerPctOrderPred::operator()(WorldObject const* objA, WorldObject const* objB) const
{
    Unit const* a = objA->ToUnit();
    Unit const* b = objB->ToUnit();
    float rA = a ? a->GetPowerPct(_power) : 0.0f;
    float rB = b ? b->GetPowerPct(_power) : 0.0f;
    return _ascending ? rA < rB : rA > rB;
}

bool Trinity::Predicates::PowerPctOrderPred::operator()(Unit const* a, Unit const* b) const
{
    float rA = a->GetPowerPct(_power);
    float rB = b->GetPowerPct(_power);
    return _ascending ? rA < rB : rA > rB;
}

bool Trinity::Predicates::HealthPctOrderPred::operator()(WorldObject const* objA, WorldObject const* objB) const
{
    Unit const* a = objA->ToUnit();
    Unit const* b = objB->ToUnit();
    float rA = (a && a->GetMaxHealth()) ? float(a->GetHealth()) / float(a->GetMaxHealth()) : 0.0f;
    float rB = (b && b->GetMaxHealth()) ? float(b->GetHealth()) / float(b->GetMaxHealth()) : 0.0f;
    return _ascending ? rA < rB : rA > rB;
}

bool Trinity::Predicates::HealthPctOrderPred::operator()(Unit const* a, Unit const* b) const
{
    float rA = a->GetMaxHealth() ? float(a->GetHealth()) / float(a->GetMaxHealth()) : 0.0f;
    float rB = b->GetMaxHealth() ? float(b->GetHealth()) / float(b->GetMaxHealth()) : 0.0f;
    return _ascending ? rA < rB : rA > rB;
}
