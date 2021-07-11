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

#include "Totem.h"
#include "Group.h"
#include "Player.h"
#include "SpellMgr.h"
#include "CreatureAI.h"
#include "InstanceData.h"
#include "ObjectAccessor.h"

Totem::Totem() : Creature(CREATURE_SUBTYPE_TOTEM)
{
    m_duration = 0;
    m_type = TOTEM_PASSIVE;
}

bool Totem::Create(uint32 guidlow, CreatureCreatePos& cPos, CreatureInfo const* cinfo, Unit* owner)
{
    SetMap(cPos.GetMap());

    if (!CreateFromProto(guidlow, cinfo, cinfo->entry))
        return false;

    cPos.SelectFinalPoint(this);

    // totem must be at same Z in case swimming caster and etc.
    if (fabs(cPos.m_pos.z - owner->GetPositionZ()) > 5.0f)
        cPos.m_pos.z = owner->GetPositionZ();

    if (!cPos.Relocate(this))
        return false;

    //Notify the map's instance data.
    //Only works if you create the object in it, not if it is moves to that map.
    //Normally non-players do not teleport to other maps.
    if (InstanceData* iData = GetMap()->GetInstanceData())
        iData->OnCreatureCreate(this);

    LoadCreatureAddon();

    SetWalk(true, true);

    return true;
}

void Totem::Update(uint32 update_diff, uint32 time)
{
    Unit* owner = GetOwner();
    if (!owner || !owner->IsAlive() || !IsAlive() || !isWithinVisibilityDistanceOf(owner, owner))
    {
        UnSummon();                                         // remove self
        return;
    }

    if (GetMotionMaster()->GetCurrentMovementGeneratorType() != IDLE_MOTION_TYPE)
        GetMotionMaster()->MoveIdle();

    // Do final update before unsummon, or we lose ticks on the totem's spell
    Creature::Update(update_diff, time);

    if (m_duration <= update_diff)
    {
        UnSummon();                                         // remove self
        return;
    }
    else
        m_duration -= update_diff;
}

void Totem::Summon(Unit* owner)
{
    AIM_Initialize();
    owner->GetMap()->Add((Creature*)this);

    SendObjectSpawnAnim();

    if (owner->GetTypeId() == TYPEID_UNIT && ((Creature*)owner)->AI())
        ((Creature*)owner)->AI()->JustSummoned((Creature*)this);

    // there are some totems, which exist just for their visual appeareance
    if (!GetSpell())
        return;

    switch (m_type)
    {
        case TOTEM_PASSIVE:
            CastSpell(this, GetSpell(), true);
            break;
        case TOTEM_STATUE:
            CastSpell(GetOwner(), GetSpell(), true);
            break;
        default:
            break;
    }
}

void Totem::UnSummon()
{
    SendObjectDeSpawnAnim();

    CombatStop();
    RemoveAurasDueToSpell(GetSpell());

    if (Unit* owner = GetOwner())
    {
        owner->_RemoveTotem(this);
        owner->RemoveAurasDueToSpell(GetSpell());

        //remove aura all party members too
        if (owner->GetTypeId() == TYPEID_PLAYER)
        {
            // Not only the player can summon the totem (scripted AI)
            if (Group* pGroup = ((Player*)owner)->GetGroup())
            {
                for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
                {
                    Player* Target = itr->getSource();
                    if (Target && pGroup->SameSubGroup((Player*)owner, Target))
                        Target->RemoveAurasDueToSpell(GetSpell());
                }
            }
        }

        if (owner->GetTypeId() == TYPEID_UNIT && ((Creature*)owner)->AI())
            ((Creature*)owner)->AI()->SummonedCreatureDespawn((Creature*)this);
    }

    // any totem unsummon look like as totem kill, req. for proper animation
    if (IsAlive())
        SetDeathState(DEAD);

    AddObjectToRemoveList();
}

void Totem::SetOwner(Unit* owner)
{
    SetCreatorGuid(owner->GetObjectGuid());
    SetOwnerGuid(owner->GetObjectGuid());
    SetFactionTemplateId(owner->GetFactionTemplateId());
    SetLevel(owner->GetLevel());
}

Unit* Totem::GetOwner()
{
    if (ObjectGuid ownerGuid = GetOwnerGuid())
        return ObjectAccessor::GetUnit(*this, ownerGuid);

    return nullptr;
}

void Totem::SetTypeBySummonSpell(SpellEntry const* spellProto)
{
    // Get spell casted by totem
    SpellEntry const* totemSpell = sSpellMgr.GetSpellEntry(GetSpell());
    if (totemSpell)
    {
        // If spell have cast time -> so its active totem
        if (totemSpell->GetCastTime())
            m_type = TOTEM_ACTIVE;
    }
    if (spellProto->SpellIconID == 2056)
        m_type = TOTEM_STATUE;                              //Jewelery statue
}

bool Totem::IsImmuneToSpellEffect(SpellEntry const* spellInfo, SpellEffectIndex index, bool castOnSelf) const
{
    // Check for Mana Spring & Healing Stream totems
    switch (spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_SHAMAN:
            if (spellInfo->IsFitToFamilyMask(UI64LIT(0x00000002000)) ||
                    spellInfo->IsFitToFamilyMask(UI64LIT(0x00000004000)) ||
                    spellInfo->IsFitToFamilyMask(UI64LIT(0x00004000000)))
                return false;
            break;
        default:
            break;
    }

    // Totems should not be immune to self casted spells.
    if (castOnSelf)
        return false;

    switch (spellInfo->Effect[index])
    {
        case SPELL_EFFECT_ATTACK_ME:
        // immune to any type of regeneration effects hp/mana etc.
        case SPELL_EFFECT_HEAL:
        case SPELL_EFFECT_HEAL_MAX_HEALTH:
        case SPELL_EFFECT_HEAL_MECHANICAL:
        case SPELL_EFFECT_ENERGIZE:
            return true;
        default:
            break;
    }

    if (!spellInfo->IsPositiveSpell())
    {
        // immune to all negative auras
        if (spellInfo->IsSpellAppliesAura(1 << index))
            return true;
    }
    else
    {
        // immune to any type of regeneration auras hp/mana etc.
        if (spellInfo->IsPeriodicRegenerateEffect(index))
            return true;
    }
    return Creature::IsImmuneToSpellEffect(spellInfo, index, castOnSelf);
}
