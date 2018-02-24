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

#ifndef TRINITYCORE_SUMMONEDGAMEOBJECT_H
#define TRINITYCORE_SUMMONEDGAMEOBJECT_H

#include "GameObject.h"

class SpellInfo;

class TC_GAME_API SummonedGameObject : public GameObject
{
    public:
        explicit SummonedGameObject(WorldObject* owner, SpellInfo const* spell, GOSummonType type, Milliseconds const& lifetime = 0ms);

        void Despawn(Milliseconds const& delay) { DespawnOrUnsummon(delay); }

        void AddToWorld() override;
        void RemoveFromWorld() override;

        void UnlinkFromOwner();
        WorldObject* GetOwner() const;
        Unit* GetUnitOwner() const;

        void ClearSpellId() { m_spellId = 0; }
        uint32 GetSpellId() const { return m_spellId; }

        GOSummonType GetSummonType() const { return m_type; }
        uint32 GetFullDuration() const { return m_lifetime; }

    private:
        bool ShouldDespawnOnOwnerDeath() const;

        GOSummonType const m_type;
        uint32 const m_lifetime;
        uint32 m_spellId;
};

#endif
