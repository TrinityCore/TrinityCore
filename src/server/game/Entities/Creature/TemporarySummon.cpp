/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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

#include "Log.h"
#include "ObjectAccessor.h"
#include "CreatureAI.h"
#include "ObjectMgr.h"
#include "TemporarySummon.h"

TempSummon::TempSummon(SummonPropertiesEntry const *properties, Unit *owner) :
Creature(), m_Properties(properties), m_type(TEMPSUMMON_MANUAL_DESPAWN),
m_timer(0), m_lifetime(0)
{
    m_summonerGUID = owner ? owner->GetGUID() : 0;
    m_unitTypeMask |= UNIT_MASK_SUMMON;
}

Unit* TempSummon::GetSummoner() const
{
    return m_summonerGUID ? ObjectAccessor::GetUnit(*this, m_summonerGUID) : NULL;
}

void TempSummon::Update(uint32 diff)
{
    Creature::Update(diff);

    if (m_deathState == DEAD)
    {
        UnSummon();
        return;
    }
    switch(m_type)
    {
        case TEMPSUMMON_MANUAL_DESPAWN:
            break;
        case TEMPSUMMON_TIMED_DESPAWN:
        {
            if (m_timer <= diff)
            {
                UnSummon();
                return;
            }

            m_timer -= diff;
            break;
        }
        case TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT:
        {
            if (!isInCombat())
            {
                if (m_timer <= diff)
                {
                    UnSummon();
                    return;
                }

                m_timer -= diff;
            }
            else if (m_timer != m_lifetime)
                m_timer = m_lifetime;

            break;
        }

        case TEMPSUMMON_CORPSE_TIMED_DESPAWN:
        {
            if (m_deathState == CORPSE)
            {
                if (m_timer <= diff)
                {
                    UnSummon();
                    return;
                }

                m_timer -= diff;
            }
            break;
        }
        case TEMPSUMMON_CORPSE_DESPAWN:
        {
            // if m_deathState is DEAD, CORPSE was skipped
            if (m_deathState == CORPSE || m_deathState == DEAD)
            {
                UnSummon();
                return;
            }

            break;
        }
        case TEMPSUMMON_DEAD_DESPAWN:
        {
            if (m_deathState == DEAD)
            {
                UnSummon();
                return;
            }
            break;
        }
        case TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN:
        {
            // if m_deathState is DEAD, CORPSE was skipped
            if (m_deathState == CORPSE || m_deathState == DEAD)
            {
                UnSummon();
                return;
            }

            if (!isInCombat())
            {
                if (m_timer <= diff)
                {
                    UnSummon();
                    return;
                }
                else
                    m_timer -= diff;
            }
            else if (m_timer != m_lifetime)
                m_timer = m_lifetime;
            break;
        }
        case TEMPSUMMON_TIMED_OR_DEAD_DESPAWN:
        {
            // if m_deathState is DEAD, CORPSE was skipped
            if (m_deathState == DEAD)
            {
                UnSummon();
                return;
            }

            if (!isInCombat() && isAlive())
            {
                if (m_timer <= diff)
                {
                    UnSummon();
                    return;
                }
                else
                    m_timer -= diff;
            }
            else if (m_timer != m_lifetime)
                m_timer = m_lifetime;
            break;
        }
        default:
            UnSummon();
            sLog->outError("Temporary summoned creature (entry: %u) have unknown type %u of ",GetEntry(),m_type);
            break;
    }
}

void TempSummon::InitStats(uint32 duration)
{
    ASSERT(!isPet());

    m_timer = duration;
    m_lifetime = duration;

    if (m_type == TEMPSUMMON_MANUAL_DESPAWN)
        m_type = (duration == 0) ? TEMPSUMMON_DEAD_DESPAWN : TEMPSUMMON_TIMED_DESPAWN;

    Unit *owner = GetSummoner();

    if (owner && isTrigger() && m_spells[0])
    {
        setFaction(owner->getFaction());
        SetLevel(owner->getLevel());
        if (owner->GetTypeId() == TYPEID_PLAYER)
            m_ControlledByPlayer = true;
    }

    if (!m_Properties)
        return;

    if (owner)
    {
        if (uint32 slot = m_Properties->Slot)
        {
            if (owner->m_SummonSlot[slot] && owner->m_SummonSlot[slot] != GetGUID())
            {
                Creature *oldSummon = GetMap()->GetCreature(owner->m_SummonSlot[slot]);
                if (oldSummon && oldSummon->isSummon())
                    oldSummon->ToTempSummon()->UnSummon();
            }
            owner->m_SummonSlot[slot] = GetGUID();
        }
    }

    if (m_Properties->Faction)
        setFaction(m_Properties->Faction);
    else if (IsVehicle()) // properties should be vehicle
        setFaction(owner->getFaction());
}

void TempSummon::InitSummon()
{
    Unit* owner = GetSummoner();
    if (owner)
    {
        if (owner->GetTypeId() == TYPEID_UNIT && owner->ToCreature()->IsAIEnabled)
            owner->ToCreature()->AI()->JustSummoned(this);
        if (IsAIEnabled)
            AI()->IsSummonedBy(owner);
    }
}

void TempSummon::SetTempSummonType(TempSummonType type)
{
    m_type = type;
}

void TempSummon::UnSummon()
{
    //ASSERT(!isPet());
    if (isPet())
    {
        ((Pet*)this)->Remove(PET_SAVE_NOT_IN_SLOT);
        ASSERT(!IsInWorld());
        return;
    }

    Unit* owner = GetSummoner();
    if (owner && owner->GetTypeId() == TYPEID_UNIT && owner->ToCreature()->IsAIEnabled)
        owner->ToCreature()->AI()->SummonedCreatureDespawn(this);

    AddObjectToRemoveList();
}

void TempSummon::RemoveFromWorld()
{
    if (!IsInWorld())
        return;

    if (m_Properties)
        if (uint32 slot = m_Properties->Slot)
            if (Unit* owner = GetSummoner())
                if (owner->m_SummonSlot[slot] == GetGUID())
                    owner->m_SummonSlot[slot] = 0;

    //if (GetOwnerGUID())
    //    sLog->outError("Unit %u has owner guid when removed from world", GetEntry());

    Creature::RemoveFromWorld();
}

Minion::Minion(SummonPropertiesEntry const *properties, Unit *owner) : TempSummon(properties, owner)
, m_owner(owner)
{
    ASSERT(m_owner);
    m_unitTypeMask |= UNIT_MASK_MINION;
    m_followAngle = PET_FOLLOW_ANGLE;
}

void Minion::InitStats(uint32 duration)
{
    TempSummon::InitStats(duration);

    SetReactState(REACT_PASSIVE);

    SetCreatorGUID(m_owner->GetGUID());
    setFaction(m_owner->getFaction());

    m_owner->SetMinion(this, true);
}

void Minion::RemoveFromWorld()
{
    if (!IsInWorld())
        return;

    m_owner->SetMinion(this, false);
    TempSummon::RemoveFromWorld();
}

bool Minion::IsGuardianPet() const
{
    return isPet() || (m_Properties && m_Properties->Category == SUMMON_CATEGORY_PET);
}

Guardian::Guardian(SummonPropertiesEntry const *properties, Unit *owner) : Minion(properties, owner)
, m_bonusSpellDamage(0)
{
    memset(m_statFromOwner, 0, sizeof(float)*MAX_STATS);
    m_unitTypeMask |= UNIT_MASK_GUARDIAN;
    if (properties && properties->Type == SUMMON_TYPE_PET)
    {
        m_unitTypeMask |= UNIT_MASK_CONTROLABLE_GUARDIAN;
        InitCharmInfo();
    }
}

void Guardian::InitStats(uint32 duration)
{
    Minion::InitStats(duration);

    InitStatsForLevel(m_owner->getLevel());

    if (m_owner->GetTypeId() == TYPEID_PLAYER && HasUnitTypeMask(UNIT_MASK_CONTROLABLE_GUARDIAN))
        m_charmInfo->InitCharmCreateSpells();

    SetReactState(REACT_AGGRESSIVE);
}

void Guardian::InitSummon()
{
    TempSummon::InitSummon();

    if (m_owner->GetTypeId() == TYPEID_PLAYER
        && m_owner->GetMinionGUID() == GetGUID()
        && !m_owner->GetCharmGUID())
        m_owner->ToPlayer()->CharmSpellInitialize();
}

Puppet::Puppet(SummonPropertiesEntry const *properties, Unit *owner) : Minion(properties, owner)
{
    ASSERT(owner->GetTypeId() == TYPEID_PLAYER);
    m_owner = (Player*)owner;
    m_unitTypeMask |= UNIT_MASK_PUPPET;
}

void Puppet::InitStats(uint32 duration)
{
    Minion::InitStats(duration);
    SetLevel(m_owner->getLevel());
    SetReactState(REACT_PASSIVE);
}

void Puppet::InitSummon()
{
    Minion::InitSummon();
    if (!SetCharmedBy(m_owner, CHARM_TYPE_POSSESS))
        ASSERT(false);
}

void Puppet::Update(uint32 time)
{
    Minion::Update(time);
    //check if caster is channelling?
    if (IsInWorld())
    {
        if (!isAlive())
        {
            UnSummon();
            // TODO: why long distance .die does not remove it
        }
    }
}

void Puppet::RemoveFromWorld()
{
    if (!IsInWorld())
        return;

    RemoveCharmedBy(NULL);
    Minion::RemoveFromWorld();
}
