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

#include "Totem.h"
#include "Group.h"
#include "Map.h"
#include "Player.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellInfo.h"
#include "TotemPackets.h"

Totem::Totem(SummonPropertiesEntry const* properties, Unit* owner) : Minion(properties, owner, false)
{
    m_unitTypeMask |= UNIT_MASK_TOTEM;
    m_duration = 0;
    m_type = TOTEM_PASSIVE;
}

void Totem::Update(uint32 time)
{
    if (!GetOwner()->IsAlive() || !IsAlive())
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

    Creature::Update(time);
}

void Totem::InitStats(uint32 duration)
{
    // client requires SMSG_TOTEM_CREATED to be sent before adding to world and before removing old totem
    if (Player* owner = GetOwner()->ToPlayer())
    {
        if (m_Properties->Slot >= SUMMON_SLOT_TOTEM && m_Properties->Slot < MAX_TOTEM_SLOT)
        {
            WorldPackets::Totem::TotemCreated data;
            data.Totem = GetGUID();
            data.Slot = m_Properties->Slot - SUMMON_SLOT_TOTEM;
            data.Duration = duration;
            data.SpellID = m_unitData->CreatedBySpell;
            owner->SendDirectMessage(data.Write());
        }

        // set display id depending on caster's race
        if (uint32 totemDisplayId = sSpellMgr->GetModelForTotem(m_unitData->CreatedBySpell, owner->getRace()))
            SetDisplayId(totemDisplayId);
    }

    Minion::InitStats(duration);

    // Get spell cast by totem
    if (SpellInfo const* totemSpell = sSpellMgr->GetSpellInfo(GetSpell(), GetMap()->GetDifficultyID()))
        if (totemSpell->CalcCastTime())   // If spell has cast time -> its an active totem
            m_type = TOTEM_ACTIVE;

    m_duration = duration;

    SetLevel(GetOwner()->getLevel());
}

void Totem::InitSummon()
{
    if (m_type == TOTEM_PASSIVE && GetSpell())
        CastSpell(this, GetSpell(), true);

    // Some totems can have both instant effect and passive spell
    if (GetSpell(1))
        CastSpell(this, GetSpell(1), true);
}

void Totem::UnSummon(uint32 msTime)
{
    if (msTime)
    {
        m_Events.AddEvent(new ForcedUnsummonDelayEvent(*this), m_Events.CalculateTime(msTime));
        return;
    }

    CombatStop();
    RemoveAurasDueToSpell(GetSpell(), GetGUID());

    // clear owner's totem slot
    for (uint8 i = SUMMON_SLOT_TOTEM; i < MAX_TOTEM_SLOT; ++i)
    {
        if (GetOwner()->m_SummonSlot[i] == GetGUID())
        {
            GetOwner()->m_SummonSlot[i].Clear();
            break;
        }
    }

    GetOwner()->RemoveAurasDueToSpell(GetSpell(), GetGUID());

    // remove aura all party members too
    if (Player* owner = GetOwner()->ToPlayer())
    {
        owner->SendAutoRepeatCancel(this);

        if (SpellInfo const* spell = sSpellMgr->GetSpellInfo(m_unitData->CreatedBySpell, GetMap()->GetDifficultyID()))
            GetSpellHistory()->SendCooldownEvent(spell, 0, nullptr, false);

        if (Group* group = owner->GetGroup())
        {
            for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
            {
                Player* target = itr->GetSource();
                if (target && target->IsInMap(owner) && group->SameSubGroup(owner, target))
                    target->RemoveAurasDueToSpell(GetSpell(), GetGUID());
            }
        }
    }

    AddObjectToRemoveList();
}

bool Totem::IsImmunedToSpellEffect(SpellInfo const* spellInfo, uint32 index, Unit* caster) const
{
    /// @todo possibly all negative auras immune?
    if (GetEntry() == 5925)
        return false;
    if (SpellEffectInfo const* effect = spellInfo->GetEffect(index))
    {
        switch (effect->ApplyAuraName)
        {
            case SPELL_AURA_PERIODIC_DAMAGE:
            case SPELL_AURA_PERIODIC_LEECH:
            case SPELL_AURA_MOD_FEAR:
            case SPELL_AURA_TRANSFORM:
                return true;
            default:
                break;
        }
    }
    else
        return true;

    return Creature::IsImmunedToSpellEffect(spellInfo, index, caster);
}
