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

#include "Totem.h"
#include "WorldPacket.h"
#include "Log.h"
#include "Group.h"
#include "Player.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"

Totem::Totem(SummonPropertiesEntry const *properties, Unit *owner) : Minion(properties, owner)
{
    m_unitTypeMask |= UNIT_MASK_TOTEM;
    m_duration = 0;
    m_type = TOTEM_PASSIVE;
}

void Totem::Update(uint32 time)
{
    if (!m_owner->isAlive() || !isAlive())
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
    Minion::InitStats(duration);

    CreatureInfo const *cinfo = GetCreatureInfo();
    if (m_owner->GetTypeId() == TYPEID_PLAYER && cinfo)
    {
        uint32 display_id = sObjectMgr.ChooseDisplayId(m_owner->ToPlayer()->GetTeam(), cinfo);
        CreatureModelInfo const *minfo = sObjectMgr.GetCreatureModelRandomGender(display_id);
        if (minfo)
            display_id = minfo->modelid;
        switch (m_owner->ToPlayer()->GetTeam())
        {
            case ALLIANCE:
                display_id = cinfo->Modelid1;
                break;
            case HORDE:
                if (cinfo->Modelid3)
                    display_id = cinfo->Modelid3;
                else
                    display_id = cinfo->Modelid1;

                switch (((Player*)m_owner)->getRace())
                {
                    case RACE_ORC:
                        if (cinfo->Modelid2)
                            display_id = cinfo->Modelid2;
                        else
                            display_id = cinfo->Modelid1;
                        break;
                    case RACE_TROLL:
                        if (cinfo->Modelid4)
                            display_id = cinfo->Modelid4;
                        else
                            display_id = cinfo->Modelid1;
                        break;
                    default:
                        break;
                }
                break;
            default:
                break;
        }
        SetDisplayId(display_id);
    }

    // Get spell casted by totem
    SpellEntry const * totemSpell = sSpellStore.LookupEntry(GetSpell());
    if (totemSpell)
    {
        // If spell have cast time -> so its active totem
        if (GetSpellCastTime(totemSpell))
            m_type = TOTEM_ACTIVE;
    }

    if (GetEntry() == SENTRY_TOTEM_ENTRY)
        SetReactState(REACT_AGGRESSIVE);

    m_duration = duration;

    SetLevel(m_owner->getLevel());
}

void Totem::InitSummon()
{
    if (m_type == TOTEM_PASSIVE)
        CastSpell(this, GetSpell(), true);

    // Some totems can have both instant effect and passive spell
    if (GetSpell(1))
        CastSpell(this, GetSpell(1), true);
}

void Totem::UnSummon()
{
    CombatStop();
    RemoveAurasDueToSpell(GetSpell());

    // clear owner's totem slot
    for (int i = SUMMON_SLOT_TOTEM; i < MAX_TOTEM_SLOT; ++i)
    {
        if (m_owner->m_SummonSlot[i] == GetGUID())
        {
            m_owner->m_SummonSlot[i] = 0;
            break;
        }
    }

    m_owner->RemoveAurasDueToSpell(GetSpell());

    //remove aura all party members too
    Group *pGroup = NULL;
    if (m_owner->GetTypeId() == TYPEID_PLAYER)
    {
        m_owner->ToPlayer()->SendAutoRepeatCancel(this);
        // Not only the player can summon the totem (scripted AI)
        pGroup = m_owner->ToPlayer()->GetGroup();
        if (pGroup)
        {
            for (GroupReference *itr = pGroup->GetFirstMember(); itr != NULL; itr = itr->next())
            {
                Player* Target = itr->getSource();
                if (Target && pGroup->SameSubGroup((Player*)m_owner, Target))
                    Target->RemoveAurasDueToSpell(GetSpell());
            }
        }
    }

    AddObjectToRemoveList();
}

bool Totem::IsImmunedToSpellEffect(SpellEntry const* spellInfo, uint32 index) const
{
    // TODO: possibly all negative auras immune?
    if (GetEntry() == 5925)
        return false;
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
