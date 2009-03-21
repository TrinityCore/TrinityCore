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

#include "TemporarySummon.h"
#include "Log.h"
#include "ObjectAccessor.h"
#include "CreatureAI.h"
#include "ObjectMgr.h"

TempSummon::TempSummon(SummonPropertiesEntry const *properties, Unit *owner) :
Creature(), m_type(TEMPSUMMON_MANUAL_DESPAWN), m_timer(0), m_lifetime(0)
, m_Properties(properties)
{
    m_summonerGUID = owner ? owner->GetGUID() : 0;
    m_summonMask |= SUMMON_MASK_SUMMON;
}

void TempSummon::Update( uint32 diff )
{
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
            if ( m_deathState == CORPSE)
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
            if ( m_deathState == CORPSE || m_deathState == DEAD)
            {
                UnSummon();
                return;
            }

            break;
        }
        case TEMPSUMMON_DEAD_DESPAWN:
        {
            if ( m_deathState == DEAD )
            {
                UnSummon();
                return;
            }
            break;
        }
        case TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN:
        {
            // if m_deathState is DEAD, CORPSE was skipped
            if ( m_deathState == CORPSE || m_deathState == DEAD)
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

            if (!isInCombat() && isAlive() )
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
            sLog.outError("Temporary summoned creature (entry: %u) have unknown type %u of ",GetEntry(),m_type);
            break;
    }

    Creature::Update( diff );
}

void TempSummon::InitSummon(uint32 duration)
{
    m_timer = duration;
    m_lifetime = duration;

    if(m_type == TEMPSUMMON_MANUAL_DESPAWN)
        m_type = (duration == 0) ? TEMPSUMMON_DEAD_DESPAWN : TEMPSUMMON_TIMED_DESPAWN;

    AIM_Initialize();

    if(!m_Properties)
        return;

    Unit* owner = GetSummoner();
    if(uint32 slot = m_Properties->Slot)
    {
        --slot;
        if(owner)
        {
            if(owner->m_TotemSlot[slot] && owner->m_TotemSlot[slot] != GetGUID())
            {
                Creature *OldTotem = ObjectAccessor::GetCreature(*this, owner->m_TotemSlot[slot]);
                if(OldTotem && OldTotem->isSummon())
                    ((TempSummon*)OldTotem)->UnSummon();
            }
            owner->m_TotemSlot[slot] = GetGUID();
        }
    }
}

void TempSummon::SetTempSummonType(TempSummonType type)
{
    m_type = type;
}

void TempSummon::UnSummon()
{
    Unit* owner = GetSummoner();
    if(owner)
    {
        if(owner->GetTypeId() == TYPEID_UNIT && ((Creature*)owner)->IsAIEnabled)
            ((Creature*)owner)->AI()->SummonedCreatureDespawn(this);

        if(m_Properties)
        {
            if(uint32 slot = m_Properties->Slot)
            {
                --slot;
                if(owner->m_TotemSlot[slot] = GetGUID())
                    owner->m_TotemSlot[slot] = 0;
            }
        }
    }

    CleanupsBeforeDelete();
    AddObjectToRemoveList();
}

void TempSummon::SaveToDB()
{
}

Guardian::Guardian(SummonPropertiesEntry const *properties, Unit *owner) : TempSummon(properties, owner)
, m_owner(owner)
{
    m_summonMask |= SUMMON_MASK_GUARDIAN;
    InitCharmInfo();
}

bool Guardian::Create(uint32 guidlow, Map *map, uint32 phaseMask, uint32 Entry, uint32 pet_number)
{
    SetMapId(map->GetId());
    SetInstanceId(map->GetInstanceId());
    SetPhaseMask(phaseMask,false);

    Object::_Create(guidlow, pet_number, HIGHGUID_PET);

    m_DBTableGuid = guidlow;
    m_originalEntry = Entry;

    if(!InitEntry(Entry))
        return false;

    SetByteValue(UNIT_FIELD_BYTES_2, 0, SHEATH_STATE_MELEE);

    return true;
}

void Guardian::InitSummon(uint32 duration)
{
    TempSummon::InitSummon(duration);

    SetReactState(REACT_AGGRESSIVE);
    SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, 0);

    SetOwnerGUID(m_owner->GetGUID());
    SetCreatorGUID(m_owner->GetGUID());
    SetUInt32Value(UNIT_FIELD_FACTIONTEMPLATE, m_owner->getFaction());
    m_owner->AddGuardian(this);
    SetUInt32Value(UNIT_FIELD_BYTES_0, 2048);

    if(m_owner->GetTypeId() == TYPEID_PLAYER)
    {
        m_owner->SetUInt64Value(UNIT_FIELD_SUMMON, GetGUID());
        m_charmInfo->InitCharmCreateSpells();
        //charmInfo->SetPetNumber(objmgr.GeneratePetNumber(), true);
        ((Player*)m_owner)->CharmSpellInitialize();
    }
}

void Guardian::InitStatsForLevel(uint32 petlevel)
{
    SetLevel(petlevel);
    switch(GetEntry())
    {
    case 1964: //force of nature
        SetCreateHealth(30 + 30*petlevel);
        SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel * 2.5f - (petlevel / 2)));
        SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel * 2.5f + (petlevel / 2)));
        break;
    case 15352: //earth elemental 36213
        SetCreateHealth(100 + 120*petlevel);
        SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)));
        SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)));
        break;
    case 15438: //fire elemental
        SetCreateHealth(40*petlevel);
        SetCreateMana(28 + 10*petlevel);
        SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel * 4 - petlevel));
        SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel * 4 + petlevel));
        break;
    default:
        SetCreateMana(28 + 10*petlevel);
        SetCreateHealth(28 + 30*petlevel);
        // FIXME: this is wrong formula, possible each guardian pet have own damage formula
        //these formula may not be correct; however, it is designed to be close to what it should be
        //this makes dps 0.5 of pets level
        SetBaseWeaponDamage(BASE_ATTACK, MINDAMAGE, float(petlevel - (petlevel / 4)));
        //damage range is then petlevel / 2
        SetBaseWeaponDamage(BASE_ATTACK, MAXDAMAGE, float(petlevel + (petlevel / 4)));
        break;
    }
}

void Guardian::UnSummon()
{
    m_owner->m_Guardians.erase(GetGUID());
    TempSummon::UnSummon();
}

