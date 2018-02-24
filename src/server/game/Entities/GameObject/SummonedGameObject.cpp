/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "SummonedGameObject.h"
#include "Log.h"
#include "SpellHistory.h"
#include "SpellInfo.h"
#include "SpellMgr.h"
#include "Unit.h"

SummonedGameObject::SummonedGameObject(WorldObject* owner, SpellInfo const* spell, GOSummonType type, Milliseconds const& lifetime) : m_type(type), m_lifetime(lifetime.count()), m_spellId(spell ? spell->Id : 0)
{
    ASSERT(owner);
    SetGuidValue(OBJECT_FIELD_CREATED_BY, owner->GetGUID());

    switch (type)
    {
        case GO_SUMMON_TIMED_DESPAWN:
        case GO_SUMMON_TIMED_OR_CORPSE_DESPAWN:
            Despawn(lifetime);
            break;
        case GO_SUMMON_MANUAL_DESPAWN:
            break;
    }
}

bool SummonedGameObject::ShouldDespawnOnOwnerDeath() const
{
    if (GetOwnerGUID().IsPlayer())
        return true;
    return (m_type == GO_SUMMON_CORPSE_DESPAWN || m_type == GO_SUMMON_TIMED_OR_CORPSE_DESPAWN);
}

void SummonedGameObject::AddToWorld()
{
    if (ShouldDespawnOnOwnerDeath())
        if (Unit* owner = GetUnitOwner())
            owner->AddGameObject(this);
}

void SummonedGameObject::RemoveFromWorld()
{
    if (Unit* owner = GetUnitOwner())
    {
        // GO created by some spell
        if (m_spellId)
        {
            // @todo all auras? what if another player has a gobj?
            owner->RemoveAurasDueToSpell(m_spellId);

            SpellInfo const* createBySpell = sSpellMgr->GetSpellInfo(m_spellId);
            ASSERT(createBySpell, "GameObject %s (%u) was created by spell %u, but this spell does not exist.", GetName().c_str(), GetEntry(), m_spellId);
            // Need activate spell use for owner
            if (createBySpell->IsCooldownStartedOnEvent())
                // note: item based cooldowns and cooldown spell mods with charges ignored (unknown existing cases)
                owner->GetSpellHistory()->SendCooldownEvent(createBySpell);
        }
        owner->UnlinkGameObject(this);
    }

    GameObject::RemoveFromWorld();
}

void SummonedGameObject::UnlinkFromOwner()
{
    if (Unit* owner = GetUnitOwner())
        owner->UnlinkGameObject(this);
}

WorldObject* SummonedGameObject::GetOwner() const
{
    return ObjectAccessor::GetWorldObject(*this, GetOwnerGUID());
}

Unit* SummonedGameObject::GetUnitOwner() const
{
    return ObjectAccessor::GetUnit(*this, GetOwnerGUID());
}
