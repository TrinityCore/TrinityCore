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
#ifndef TRINITYCORE_TOTEM_H
#define TRINITYCORE_TOTEM_H
#include "TemporarySummon.h"
enum TotemType
{
    TOTEM_PASSIVE    = 0,
    TOTEM_ACTIVE     = 1,
    TOTEM_STATUE     = 2 // copied straight from MaNGOS, may need more implementation to work
};
#define SENTRY_TOTEM_ENTRY  3968
class Totem : public Minion
{
    public:
        explicit Totem(SummonPropertiesEntry const *properties, Unit *owner);
        virtual ~Totem(){};
        void Update( uint32 time );
        void InitStats(uint32 duration);
        void InitSummon();
        void UnSummon();
        uint32 GetSpell(uint8 slot=0) const { return m_spells[slot]; }
        uint32 GetTotemDuration() const { return m_duration; }
        TotemType GetTotemType() const { return m_type; }
        bool UpdateStats(Stats /*stat*/) { return true; }
        bool UpdateAllStats() { return true; }
        void UpdateResistances(uint32 /*school*/) {}
        void UpdateArmor() {}
        void UpdateMaxHealth() {}
        void UpdateMaxPower(Powers /*power*/) {}
        void UpdateAttackPowerAndDamage(bool /*ranged*/ ) {}
        void UpdateDamagePhysical(WeaponAttackType /*attType*/) {}
        bool IsImmunedToSpellEffect(SpellEntry const* spellInfo, uint32 index) const;
    protected:
        TotemType m_type;
        uint32 m_duration;
};
#endif

