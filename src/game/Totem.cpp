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

#include "Totem.h"
#include "WorldPacket.h"
#include "Log.h"
#include "Group.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"

Totem::Totem(SummonPropertiesEntry const *properties, Unit *owner) : TempSummon(properties, owner)
{
    m_summonMask |= SUMMON_MASK_TOTEM;
    m_duration = 0;
    m_type = TOTEM_PASSIVE;
}

void Totem::Update( uint32 time )
{
    Unit *owner = GetOwner();
    if (!owner || !owner->isAlive() || !this->isAlive())
    {
        UnSummon();                                         // remove self
        return;
    }

    if (m_duration <= time)
    {
        UnSummon();                                         // remove self
        return;
    }
    else
        m_duration -= time;

    Creature::Update( time );
}

void Totem::InitSummon(uint32 duration)
{
    Unit *owner = GetOwner();
    if(!owner)
        return;

    CreatureInfo const *cinfo = GetCreatureInfo();
    if (owner->GetTypeId()==TYPEID_PLAYER && cinfo)
    {
        uint32 modelid = 0;
        if(((Player*)owner)->GetTeam() == HORDE)
        {
            if(cinfo->Modelid_H1)
                modelid = cinfo->Modelid_H1;
            else if(cinfo->Modelid_H2)
                modelid = cinfo->Modelid_H2;
        }
        else
        {
            if(cinfo->Modelid_A1)
                modelid = cinfo->Modelid_A1;
            else if(cinfo->Modelid_A2)
                modelid = cinfo->Modelid_A2;
        }
        if (modelid)
            SetDisplayId(modelid);
        else
            sLog.outErrorDb("Totem::Summon: Missing modelid information for entry %u, team %u, totem will use default values.",GetEntry(),((Player*)owner)->GetTeam());
    }

    WorldPacket data(SMSG_GAMEOBJECT_SPAWN_ANIM_OBSOLETE, 8);
    data << GetGUID();
    SendMessageToSet(&data,true);

    if(m_type == TOTEM_PASSIVE)
        CastSpell(this, GetSpell(), true);

    if(GetEntry() == SENTRY_TOTEM_ENTRY)
        SetReactState(REACT_AGGRESSIVE);

    m_duration = duration;

    SetCreatorGUID(owner->GetGUID());
    setFaction(owner->getFaction());
    SetLevel(owner->getLevel());

    // Get spell casted by totem
    SpellEntry const * totemSpell = sSpellStore.LookupEntry(GetSpell());
    if (totemSpell)
    {
        // If spell have cast time -> so its active totem
        if (GetSpellCastTime(totemSpell))
            m_type = TOTEM_ACTIVE;
    }

    TempSummon::InitSummon(duration);
}

void Totem::UnSummon()
{
    SendObjectDeSpawnAnim(GetGUID());

    CombatStop();
    RemoveAurasDueToSpell(GetSpell());
    Unit *owner = this->GetOwner();
    if (owner)
    {
        // clear owenr's totem slot
        for(int i = SUMMON_SLOT_TOTEM; i < MAX_TOTEM_SLOT; ++i)
        {
            if(owner->m_SummonSlot[i]==GetGUID())
            {
                owner->m_SummonSlot[i] = 0;
                break;
            }
        }

        owner->RemoveAurasDueToSpell(GetSpell());

        //remove aura all party members too
        Group *pGroup = NULL;
        if (owner->GetTypeId() == TYPEID_PLAYER)
        {
            // Not only the player can summon the totem (scripted AI)
            pGroup = ((Player*)owner)->GetGroup();
            if (pGroup)
            {
                for(GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
                {
                    Player* Target = itr->getSource();
                    if(Target && pGroup->SameSubGroup((Player*)owner, Target))
                        Target->RemoveAurasDueToSpell(GetSpell());
                }
            }
        }
    }

    CleanupsBeforeDelete();
    AddObjectToRemoveList();
}

Unit *Totem::GetOwner()
{
    uint64 ownerid = GetOwnerGUID();
    if(!ownerid)
        return NULL;
    return ObjectAccessor::GetUnit(*this, ownerid);
}

bool Totem::IsImmunedToSpellEffect(SpellEntry const* spellInfo, uint32 index) const
{
    // TODO: possibly all negative auras immuned?
    switch(spellInfo->EffectApplyAuraName[index])
    {
        case SPELL_AURA_PERIODIC_DAMAGE:
        case SPELL_AURA_PERIODIC_LEECH:
        case SPELL_AURA_MOD_FEAR:
        case SPELL_AURA_TRANSFORM:
            return true;
        default:
            break;
    }
    return Creature::IsImmunedToSpellEffect(spellInfo, index);
}

