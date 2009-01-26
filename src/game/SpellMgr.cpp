/*
 * Copyright (C) 2005-2008 MaNGOS <http://www.mangosproject.org/>
 *
 * Copyright (C) 2008 Trinity <http://www.trinitycore.org/>
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

#include "SpellMgr.h"
#include "ObjectMgr.h"
#include "SpellAuraDefines.h"
#include "ProgressBar.h"
#include "Database/DBCStores.h"
#include "World.h"
#include "Chat.h"
#include "Spell.h"

SpellMgr::SpellMgr()
{
    for(int i = 0; i < TOTAL_SPELL_EFFECTS; ++i)
    {
        switch(i)
        {
            case SPELL_EFFECT_PERSISTENT_AREA_AURA: //27
            case SPELL_EFFECT_SUMMON:               //28
            case SPELL_EFFECT_TRIGGER_MISSILE:      //32
            //case SPELL_EFFECT_SUMMON_WILD:          //41 not 303
            //case SPELL_EFFECT_SUMMON_GUARDIAN:      //42 not 303
            case SPELL_EFFECT_TRANS_DOOR:           //50 summon object
            case SPELL_EFFECT_SUMMON_PET:           //56
            case SPELL_EFFECT_ADD_FARSIGHT:         //72
            //case SPELL_EFFECT_SUMMON_POSSESSED:     //73
            //case SPELL_EFFECT_SUMMON_TOTEM:         //74
            case SPELL_EFFECT_SUMMON_OBJECT_WILD:   //76
            //case SPELL_EFFECT_SUMMON_TOTEM_SLOT1:   //87
            //case SPELL_EFFECT_SUMMON_TOTEM_SLOT2:   //88
            //case SPELL_EFFECT_SUMMON_TOTEM_SLOT3:   //89
            //case SPELL_EFFECT_SUMMON_TOTEM_SLOT4:   //90
            //case SPELL_EFFECT_SUMMON_CRITTER:       //97 not 303
            case SPELL_EFFECT_SUMMON_OBJECT_SLOT1:  //104
            case SPELL_EFFECT_SUMMON_OBJECT_SLOT2:  //105
            case SPELL_EFFECT_SUMMON_OBJECT_SLOT3:  //106
            case SPELL_EFFECT_SUMMON_OBJECT_SLOT4:  //107
            case SPELL_EFFECT_SUMMON_DEAD_PET:      //109
            //case SPELL_EFFECT_SUMMON_DEMON:         //112 not 303
            case SPELL_EFFECT_TRIGGER_SPELL_2:      //151 ritual of summon
                EffectTargetType[i] = SPELL_REQUIRE_DEST;
                break;
            case SPELL_EFFECT_PARRY: // 0
            case SPELL_EFFECT_BLOCK: // 0
            case SPELL_EFFECT_SKILL: // always with dummy 3 as A
            //case SPELL_EFFECT_LEARN_SPELL: // 0 may be 5 pet
            case SPELL_EFFECT_TRADE_SKILL: // 0 or 1
            case SPELL_EFFECT_PROFICIENCY: // 0
                EffectTargetType[i] = SPELL_REQUIRE_NONE;
                break;
            case SPELL_EFFECT_ENCHANT_ITEM:
            case SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY:
            case SPELL_EFFECT_DISENCHANT:
            case SPELL_EFFECT_FEED_PET:
            case SPELL_EFFECT_PROSPECTING:
                EffectTargetType[i] = SPELL_REQUIRE_ITEM;
                break;
            //caster must be pushed otherwise no sound
            case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
            case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND:
            case SPELL_EFFECT_APPLY_AREA_AURA_ENEMY:
            case SPELL_EFFECT_APPLY_AREA_AURA_PET:
            case SPELL_EFFECT_APPLY_AREA_AURA_OWNER:
                EffectTargetType[i] = SPELL_REQUIRE_CASTER;
                break;
            default:
                EffectTargetType[i] = SPELL_REQUIRE_UNIT;
                break;
        }
    }

    for(int i = 0; i < TOTAL_SPELL_TARGETS; ++i)
    {
        switch(i)
        {
            case TARGET_UNIT_CASTER:
            case TARGET_UNIT_CASTER_FISHING:
            case TARGET_UNIT_MASTER:
            case TARGET_UNIT_PET:
            case TARGET_UNIT_PARTY_CASTER:
            case TARGET_UNIT_RAID:
                SpellTargetType[i] = TARGET_TYPE_UNIT_CASTER;
                break;
            case TARGET_UNIT_MINIPET:
            case TARGET_UNIT_TARGET_ALLY:
            case TARGET_UNIT_TARGET_RAID:
            case TARGET_UNIT_TARGET_ANY:
            case TARGET_UNIT_TARGET_ENEMY:
            case TARGET_UNIT_TARGET_PARTY:
            case TARGET_UNIT_PARTY_TARGET:
                SpellTargetType[i] = TARGET_TYPE_UNIT_TARGET;
                break;
            case TARGET_UNIT_CHANNEL:
            case TARGET_DEST_CHANNEL:
                SpellTargetType[i] = TARGET_TYPE_CHANNEL;
                break;
            case TARGET_UNIT_AREA_ENEMY_GROUND:
            case TARGET_UNIT_AREA_ENEMY:
            case TARGET_UNIT_AREA_ALLY_GROUND:
            case TARGET_UNIT_AREA_ALLY:
            case TARGET_UNIT_AREA_ENTRY_GROUND:
            case TARGET_UNIT_AREA_ENTRY:
            case TARGET_UNIT_AREA_PARTY_GROUND:
            case TARGET_UNIT_AREA_PARTY:
            //case TARGET_UNIT_AREA_ENEMY_CHANNEL:
            //case TARGET_UNIT_AREA_ALLY_CHANNEL:
                SpellTargetType[i] = TARGET_TYPE_AREA_DEST;
                break;
            case TARGET_DEST_TARGET_ENEMY:
            case TARGET_DEST_TARGET_FRONT:
            case TARGET_DEST_TARGET_BACK:
            case TARGET_DEST_TARGET_RIGHT:
            case TARGET_DEST_TARGET_LEFT:
            case TARGET_DEST_TARGET_FRONT_LEFT:
            case TARGET_DEST_TARGET_BACK_LEFT:
            case TARGET_DEST_TARGET_BACK_RIGHT:
            case TARGET_DEST_TARGET_FRONT_RIGHT:
            case TARGET_DEST_TARGET_RANDOM:
            case TARGET_DEST_TARGET_RADIUS:
                SpellTargetType[i] = TARGET_TYPE_DEST_TARGET;
                break;
            case TARGET_DEST_CASTER_GROUND:
            case TARGET_DEST_CASTER:
            case TARGET_DEST_CASTER_FRONT_LEFT:
            case TARGET_DEST_CASTER_BACK_LEFT:
            case TARGET_DEST_CASTER_BACK_RIGHT:
            case TARGET_DEST_CASTER_FRONT_RIGHT:
            case TARGET_DEST_CASTER_FRONT:
            case TARGET_MINION:
            case TARGET_DEST_CASTER_FRONT_LEAP:
            case TARGET_DEST_CASTER_BACK:
            case TARGET_DEST_CASTER_RIGHT:
            case TARGET_DEST_CASTER_LEFT:
            case TARGET_DEST_CASTER_RANDOM:
            case TARGET_DEST_CASTER_RADIUS:
                SpellTargetType[i] = TARGET_TYPE_DEST_CASTER;
                break;
            case TARGET_DEST_DEST:
            case TARGET_DEST_DEST_FRONT_LEFT:
            case TARGET_DEST_DEST_BACK_LEFT:
            case TARGET_DEST_DEST_BACK_RIGHT:
            case TARGET_DEST_DEST_FRONT_RIGHT:
            case TARGET_DEST_DEST_FRONT:
            case TARGET_DEST_DEST_BACK:
            case TARGET_DEST_DEST_RIGHT:
            case TARGET_DEST_DEST_LEFT:
            case TARGET_DEST_DEST_RANDOM:
                SpellTargetType[i] = TARGET_TYPE_DEST_DEST;
                break;
            default:
                SpellTargetType[i] = TARGET_TYPE_DEFAULT;
        }
    }

    for(int i = 0; i < TOTAL_SPELL_TARGETS; ++i)
    {
        switch(i)
        {
            case TARGET_UNIT_AREA_ENEMY_GROUND:
            case TARGET_UNIT_AREA_ENEMY:
            case TARGET_UNIT_AREA_ALLY_GROUND:
            case TARGET_UNIT_AREA_ALLY:
            case TARGET_UNIT_AREA_ENTRY_GROUND:
            case TARGET_UNIT_AREA_ENTRY:
            case TARGET_UNIT_AREA_PARTY_GROUND:
            case TARGET_UNIT_AREA_PARTY:
            //Check persistant aura seperately
            //case TARGET_UNIT_AREA_ENEMY_CHANNEL:
            //case TARGET_UNIT_AREA_ALLY_CHANNEL:
            case TARGET_UNIT_PARTY_TARGET:
            case TARGET_UNIT_PARTY_CASTER:
            case TARGET_UNIT_CONE_ENEMY:
            case TARGET_UNIT_CONE_ALLY:
            case TARGET_UNIT_CONE_ENEMY_UNKNOWN:
            case TARGET_UNIT_RAID:
                IsAreaEffectTarget[i] = true;
                break;
            default:
                IsAreaEffectTarget[i] = false;
                break;
        }
    }
}

SpellMgr::~SpellMgr()
{
}

SpellMgr& SpellMgr::Instance()
{
    static SpellMgr spellMgr;
    return spellMgr;
}

int32 GetSpellDuration(SpellEntry const *spellInfo)
{
    if(!spellInfo)
        return 0;
    SpellDurationEntry const *du = sSpellDurationStore.LookupEntry(spellInfo->DurationIndex);
    if(!du)
        return 0;
    return (du->Duration[0] == -1) ? -1 : abs(du->Duration[0]);
}

int32 GetSpellMaxDuration(SpellEntry const *spellInfo)
{
    if(!spellInfo)
        return 0;
    SpellDurationEntry const *du = sSpellDurationStore.LookupEntry(spellInfo->DurationIndex);
    if(!du)
        return 0;
    return (du->Duration[2] == -1) ? -1 : abs(du->Duration[2]);
}

uint32 GetSpellCastTime(SpellEntry const* spellInfo, Spell const* spell)
{
    SpellCastTimesEntry const *spellCastTimeEntry = sSpellCastTimesStore.LookupEntry(spellInfo->CastingTimeIndex);

    // not all spells have cast time index and this is all is pasiive abilities
    if(!spellCastTimeEntry)
        return 0;

    int32 castTime = spellCastTimeEntry->CastTime;

    if (spell)
    {
        if(Player* modOwner = spell->GetCaster()->GetSpellModOwner())
            modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_CASTING_TIME, castTime, spell);

        if( !(spellInfo->Attributes & (SPELL_ATTR_UNK4|SPELL_ATTR_UNK5)) )
            castTime = int32(castTime * spell->GetCaster()->GetFloatValue(UNIT_MOD_CAST_SPEED));
        else
        {
            if (spell->IsRangedSpell() && !spell->IsAutoRepeat())
                castTime = int32(castTime * spell->GetCaster()->m_modAttackSpeedPct[RANGED_ATTACK]);
        }
    }

    if (spellInfo->Attributes & SPELL_ATTR_RANGED && (!spell || !(spell->IsAutoRepeat())))
        castTime += 500;

    return (castTime > 0) ? uint32(castTime) : 0;
}

bool IsPassiveSpell(uint32 spellId)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);
    if (!spellInfo)
        return false;
    return (spellInfo->Attributes & SPELL_ATTR_PASSIVE) != 0;
}

/*bool IsNoStackAuraDueToAura(uint32 spellId_1, uint32 effIndex_1, uint32 spellId_2, uint32 effIndex_2)
{
    SpellEntry const *spellInfo_1 = sSpellStore.LookupEntry(spellId_1);
    SpellEntry const *spellInfo_2 = sSpellStore.LookupEntry(spellId_2);
    if(!spellInfo_1 || !spellInfo_2) return false;
    if(spellInfo_1->Id == spellId_2) return false;

    if (spellInfo_1->Effect[effIndex_1] != spellInfo_2->Effect[effIndex_2] ||
        spellInfo_1->EffectItemType[effIndex_1] != spellInfo_2->EffectItemType[effIndex_2] ||
        spellInfo_1->EffectMiscValue[effIndex_1] != spellInfo_2->EffectMiscValue[effIndex_2] ||
        spellInfo_1->EffectApplyAuraName[effIndex_1] != spellInfo_2->EffectApplyAuraName[effIndex_2])
        return false;

    return true;
}*/

int32 CompareAuraRanks(uint32 spellId_1, uint32 effIndex_1, uint32 spellId_2, uint32 effIndex_2)
{
    SpellEntry const*spellInfo_1 = sSpellStore.LookupEntry(spellId_1);
    SpellEntry const*spellInfo_2 = sSpellStore.LookupEntry(spellId_2);
    if(!spellInfo_1 || !spellInfo_2) return 0;
    if (spellId_1 == spellId_2) return 0;

    int32 diff = spellInfo_1->EffectBasePoints[effIndex_1] - spellInfo_2->EffectBasePoints[effIndex_2];
    if (spellInfo_1->EffectBasePoints[effIndex_1]+1 < 0 && spellInfo_2->EffectBasePoints[effIndex_2]+1 < 0) return -diff;
    else return diff;
}

SpellSpecific GetSpellSpecific(uint32 spellId)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);
    if(!spellInfo)
        return SPELL_NORMAL;

    switch(spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            //food/drink
            if (spellInfo->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED)
            {
                for(int i = 0; i < 3; i++)
                    if( spellInfo->EffectApplyAuraName[i]==SPELL_AURA_MOD_POWER_REGEN)
                        return SPELL_DRINK;
                    else if ( spellInfo->EffectApplyAuraName[i]==SPELL_AURA_MOD_REGEN)
                        return SPELL_FOOD;
            }
            // this may be a hack
            else if((spellInfo->AttributesEx2 & SPELL_ATTR_EX2_FOOD)
                && !spellInfo->Category)
                return SPELL_WELL_FED;
            break;
        }
        case SPELLFAMILY_MAGE:
        {
            // family flags 18(Molten), 25(Frost/Ice), 28(Mage)
            if (spellInfo->SpellFamilyFlags & 0x12040000)
                return SPELL_MAGE_ARMOR;

            if ((spellInfo->SpellFamilyFlags & 0x1000000) && spellInfo->EffectApplyAuraName[0]==SPELL_AURA_MOD_CONFUSE)
                return SPELL_MAGE_POLYMORPH;

            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            if (spellInfo->SpellFamilyFlags & 0x00008000010000LL)
                return SPELL_POSITIVE_SHOUT;

            break;
        }
        case SPELLFAMILY_WARLOCK:
        {
            // only warlock curses have this
            if (spellInfo->Dispel == DISPEL_CURSE)
                return SPELL_CURSE;

            // family flag 37 (only part spells have family name)
            if (spellInfo->SpellFamilyFlags & 0x2000000000LL)
                return SPELL_WARLOCK_ARMOR;

            //seed of corruption and corruption
            if (spellInfo->SpellFamilyFlags & 0x1000000002LL)
                return SPELL_WARLOCK_CORRUPTION;
            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            // only hunter stings have this
            if (spellInfo->Dispel == DISPEL_POISON)
                return SPELL_STING;

            // only hunter aspects have this (but not all aspects in hunter family)
            if( spellInfo->SpellFamilyFlags & 0x0044000000380000LL || spellInfo->SpellFamilyFlags2 & 0x00003010)
                return SPELL_ASPECT;

            if( spellInfo->SpellFamilyFlags2 & 0x00000002 )
                return SPELL_TRACKER;

            break;
        }
        case SPELLFAMILY_PALADIN:
        {
            if (IsSealSpell(spellInfo))
                return SPELL_SEAL;

            if (spellInfo->SpellFamilyFlags & 0x0000000011010002LL)
                return SPELL_BLESSING;

            if ((spellInfo->SpellFamilyFlags & 0x00000820180400LL) && (spellInfo->AttributesEx3 & 0x200))
                return SPELL_JUDGEMENT;

            for (int i = 0; i < 3; i++)
            {
                // only paladin auras have this (for palaldin class family)
                if (spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AREA_AURA_RAID)
                    return SPELL_AURA;
            }
            break;
        }
        case SPELLFAMILY_SHAMAN:
        {
            if (IsElementalShield(spellInfo))
                return SPELL_ELEMENTAL_SHIELD;

            break;
        }

        case SPELLFAMILY_POTION:
            return spellmgr.GetSpellElixirSpecific(spellInfo->Id);

        case SPELLFAMILY_DEATHKNIGHT:
            if ((spellInfo->Attributes & 0x10) && (spellInfo->AttributesEx2 & 0x10) && (spellInfo->AttributesEx4 & 0x200000))
                return SPELL_PRESENCE;
            break;
    }

    // only warlock armor/skin have this (in additional to family cases)
    if( spellInfo->SpellVisual[0] == 130 && spellInfo->SpellIconID == 89)
    {
        return SPELL_WARLOCK_ARMOR;
    }

    // elixirs can have different families, but potion most ofc.
    if(SpellSpecific sp = spellmgr.GetSpellElixirSpecific(spellInfo->Id))
        return sp;

    return SPELL_NORMAL;
}

bool IsSingleFromSpellSpecificPerCaster(uint32 spellSpec1,uint32 spellSpec2)
{
    switch(spellSpec1)
    {
        case SPELL_SEAL:
        case SPELL_BLESSING:
        case SPELL_AURA:
        case SPELL_STING:
        case SPELL_CURSE:
        case SPELL_ASPECT:
        case SPELL_POSITIVE_SHOUT:
        case SPELL_JUDGEMENT:
        case SPELL_WARLOCK_CORRUPTION:
            return spellSpec1==spellSpec2;
        default:
            return false;
    }
}

bool IsSingleFromSpellSpecificPerTarget(uint32 spellSpec1,uint32 spellSpec2)
{
    switch(spellSpec1)
    {
        case SPELL_TRACKER:
        case SPELL_WARLOCK_ARMOR:
        case SPELL_MAGE_ARMOR:
        case SPELL_ELEMENTAL_SHIELD:
        case SPELL_MAGE_POLYMORPH:
        case SPELL_PRESENCE:
        case SPELL_WELL_FED:
        case SPELL_DRINK:
        case SPELL_FOOD:
            return spellSpec1==spellSpec2;
        case SPELL_BATTLE_ELIXIR:
            return spellSpec2==SPELL_BATTLE_ELIXIR
                || spellSpec2==SPELL_FLASK_ELIXIR;
        case SPELL_GUARDIAN_ELIXIR:
            return spellSpec2==SPELL_GUARDIAN_ELIXIR
                || spellSpec2==SPELL_FLASK_ELIXIR;
        case SPELL_FLASK_ELIXIR:
            return spellSpec2==SPELL_BATTLE_ELIXIR
                || spellSpec2==SPELL_GUARDIAN_ELIXIR
                || spellSpec2==SPELL_FLASK_ELIXIR;
        default:
            return false;
    }
}

bool IsPositiveTarget(uint32 targetA, uint32 targetB)
{
    // non-positive targets
    switch(targetA)
    {
        case TARGET_CHAIN_DAMAGE:
        case TARGET_ALL_ENEMY_IN_AREA:
        case TARGET_ALL_ENEMY_IN_AREA_INSTANT:
        case TARGET_IN_FRONT_OF_CASTER:
        case TARGET_ALL_ENEMY_IN_AREA_CHANNELED:
        case TARGET_CURRENT_ENEMY_COORDINATES:
        case TARGET_UNIT_CHANNEL:
            return false;
        default:
            break;
    }
    if (targetB)
        return IsPositiveTarget(targetB, 0);
    return true;
}

bool IsPositiveEffect(uint32 spellId, uint32 effIndex)
{
    SpellEntry const *spellproto = sSpellStore.LookupEntry(spellId);
    if (!spellproto) return false;

    switch(spellId)
    {
        case 23333:                                         // BG spell
        case 23335:                                         // BG spell
        case 34976:                                         // BG spell
            return true;
        case 28441:                                         // not positive dummy spell
        case 37675:                                         // Chaos Blast
        case 41519:                                         // Mark of Stormrage
        case 34877:                                         // Custodian of Time
            return false;
    }

    switch(spellproto->Effect[effIndex])
    {
        // always positive effects (check before target checks that provided non-positive result in some case for positive effects)
        case SPELL_EFFECT_HEAL:
        case SPELL_EFFECT_LEARN_SPELL:
        case SPELL_EFFECT_SKILL_STEP:
        case SPELL_EFFECT_HEAL_PCT:
        case SPELL_EFFECT_ENERGIZE_PCT:
            return true;

            // non-positive aura use
        case SPELL_EFFECT_APPLY_AURA:
        case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND:
        {
            switch(spellproto->EffectApplyAuraName[effIndex])
            {
                case SPELL_AURA_DUMMY:
                {
                    // dummy aura can be positive or negative dependent from casted spell
                    switch(spellproto->Id)
                    {
                        case 13139:                         // net-o-matic special effect
                        case 23445:                         // evil twin
                        case 38637:                         // Nether Exhaustion (red)
                        case 38638:                         // Nether Exhaustion (green)
                        case 38639:                         // Nether Exhaustion (blue)
                            return false;
                        default:
                            break;
                    }
                }   break;
                case SPELL_AURA_MOD_STAT:
                case SPELL_AURA_MOD_DAMAGE_DONE:            // dependent from bas point sign (negative -> negative)
                case SPELL_AURA_MOD_HEALING_DONE:
                {
                    if(spellproto->EffectBasePoints[effIndex]+int32(spellproto->EffectBaseDice[effIndex]) < 0)
                        return false;
                    break;
                }
                case SPELL_AURA_ADD_TARGET_TRIGGER:
                    return true;
                case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
                    if(spellId != spellproto->EffectTriggerSpell[effIndex])
                    {
                        uint32 spellTriggeredId = spellproto->EffectTriggerSpell[effIndex];
                        SpellEntry const *spellTriggeredProto = sSpellStore.LookupEntry(spellTriggeredId);

                        if(spellTriggeredProto)
                        {
                            // non-positive targets of main spell return early
                            for(int i = 0; i < 3; ++i)
                            {
                                // if non-positive trigger cast targeted to positive target this main cast is non-positive
                                // this will place this spell auras as debuffs
                                if(IsPositiveTarget(spellTriggeredProto->EffectImplicitTargetA[effIndex],spellTriggeredProto->EffectImplicitTargetB[effIndex]) && !IsPositiveEffect(spellTriggeredId,i))
                                    return false;
                            }
                        }
                    }
                    break;
                case SPELL_AURA_PROC_TRIGGER_SPELL:
                    // many positive auras have negative triggered spells at damage for example and this not make it negative (it can be canceled for example)
                    break;
                case SPELL_AURA_MOD_STUN:                   //have positive and negative spells, we can't sort its correctly at this moment.
                    if(effIndex==0 && spellproto->Effect[1]==0 && spellproto->Effect[2]==0)
                        return false;                       // but all single stun aura spells is negative

                    // Petrification
                    if(spellproto->Id == 17624)
                        return false;
                    break;
                case SPELL_AURA_MOD_ROOT:
                case SPELL_AURA_MOD_SILENCE:
                case SPELL_AURA_GHOST:
                case SPELL_AURA_PERIODIC_LEECH:
                case SPELL_AURA_MOD_PACIFY_SILENCE:
                case SPELL_AURA_MOD_STALKED:
                case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
                    return false;
                case SPELL_AURA_PERIODIC_DAMAGE:            // used in positive spells also.
                    // part of negative spell if casted at self (prevent cancel)
                    if(spellproto->EffectImplicitTargetA[effIndex] == TARGET_SELF)
                        return false;
                    break;
                case SPELL_AURA_MOD_DECREASE_SPEED:         // used in positive spells also
                    // part of positive spell if casted at self
                    if(spellproto->EffectImplicitTargetA[effIndex] != TARGET_SELF)
                        return false;
                    // but not this if this first effect (don't found batter check)
                    if(spellproto->Attributes & 0x4000000 && effIndex==0)
                        return false;
                    break;
                case SPELL_AURA_TRANSFORM:
                    // some spells negative
                    switch(spellproto->Id)
                    {
                        case 36897:                         // Transporter Malfunction (race mutation to horde)
                        case 36899:                         // Transporter Malfunction (race mutation to alliance)
                            return false;
                    }
                    break;
                case SPELL_AURA_MOD_SCALE:
                    // some spells negative
                    switch(spellproto->Id)
                    {
                        case 36900:                         // Soul Split: Evil!
                        case 36901:                         // Soul Split: Good
                        case 36893:                         // Transporter Malfunction (decrease size case)
                        case 36895:                         // Transporter Malfunction (increase size case)
                            return false;
                    }
                    break;
                case SPELL_AURA_MECHANIC_IMMUNITY:
                {
                    // non-positive immunities
                    switch(spellproto->EffectMiscValue[effIndex])
                    {
                        case MECHANIC_BANDAGE:
                        case MECHANIC_SHIELD:
                        case MECHANIC_MOUNT:
                        case MECHANIC_INVULNERABILITY:
                            return false;
                        default:
                            break;
                    }
                }   break;
                case SPELL_AURA_ADD_FLAT_MODIFIER:          // mods
                case SPELL_AURA_ADD_PCT_MODIFIER:
                {
                    // non-positive mods
                    switch(spellproto->EffectMiscValue[effIndex])
                    {
                        case SPELLMOD_COST:                 // dependent from bas point sign (negative -> positive)
                            if(spellproto->EffectBasePoints[effIndex]+int32(spellproto->EffectBaseDice[effIndex]) > 0)
                                return false;
                            break;
                        default:
                            break;
                    }
                }   break;
                case SPELL_AURA_MOD_HEALING_PCT:
                    if(spellproto->EffectBasePoints[effIndex]+int32(spellproto->EffectBaseDice[effIndex]) < 0)
                        return false;
                    break;
                case SPELL_AURA_MOD_SKILL:
                    if(spellproto->EffectBasePoints[effIndex]+int32(spellproto->EffectBaseDice[effIndex]) < 0)
                        return false;
                    break;
                case SPELL_AURA_FORCE_REACTION:
                    if(spellproto->Id==42792)               // Recently Dropped Flag (prevent cancel)
                        return false;
                    break;
                default:
                    break;
            }
            break;
        }
        default:
            break;
    }

    // non-positive targets
    if(!IsPositiveTarget(spellproto->EffectImplicitTargetA[effIndex],spellproto->EffectImplicitTargetB[effIndex]))
        return false;

    // AttributesEx check
    if(spellproto->AttributesEx & SPELL_ATTR_EX_NEGATIVE)
        return false;

    // ok, positive
    return true;
}

bool IsPositiveSpell(uint32 spellId)
{
    SpellEntry const *spellproto = sSpellStore.LookupEntry(spellId);
    if (!spellproto) return false;

    // spells with at least one negative effect are considered negative
    // some self-applied spells have negative effects but in self casting case negative check ignored.
    for (int i = 0; i < 3; i++)
        if (!IsPositiveEffect(spellId, i))
            return false;
    return true;
}

bool IsSingleTargetSpell(SpellEntry const *spellInfo)
{
    // all other single target spells have if it has AttributesEx5
    if ( spellInfo->AttributesEx5 & SPELL_ATTR_EX5_SINGLE_TARGET_SPELL )
        return true;

    // TODO - need found Judgements rule
    switch(GetSpellSpecific(spellInfo->Id))
    {
        case SPELL_JUDGEMENT:
            return true;
    }

    // single target triggered spell.
    // Not real client side single target spell, but it' not triggered until prev. aura expired.
    // This is allow store it in single target spells list for caster for spell proc checking
    if(spellInfo->Id==38324)                                // Regeneration (triggered by 38299 (HoTs on Heals))
        return true;

    return false;
}

bool IsSingleTargetSpells(SpellEntry const *spellInfo1, SpellEntry const *spellInfo2)
{
    // TODO - need better check
    // Equal icon and spellfamily
    if( spellInfo1->SpellFamilyName == spellInfo2->SpellFamilyName &&
        spellInfo1->SpellIconID == spellInfo2->SpellIconID )
        return true;

    // TODO - need found Judgements rule
    SpellSpecific spec1 = GetSpellSpecific(spellInfo1->Id);
    // spell with single target specific types
    switch(spec1)
    {
        case SPELL_JUDGEMENT:
            if(GetSpellSpecific(spellInfo2->Id) == spec1)
                return true;
            break;
    }

    return false;
}

bool IsAuraAddedBySpell(uint32 auraType, uint32 spellId)
{
    SpellEntry const *spellproto = sSpellStore.LookupEntry(spellId);
    if (!spellproto) return false;

    for (int i = 0; i < 3; i++)
        if (spellproto->EffectApplyAuraName[i] == auraType)
            return true;
    return false;
}

uint8 GetErrorAtShapeshiftedCast (SpellEntry const *spellInfo, uint32 form)
{
    // talents that learn spells can have stance requirements that need ignore
    // (this requirement only for client-side stance show in talent description)
    if( GetTalentSpellCost(spellInfo->Id) > 0 &&
        (spellInfo->Effect[0]==SPELL_EFFECT_LEARN_SPELL || spellInfo->Effect[1]==SPELL_EFFECT_LEARN_SPELL || spellInfo->Effect[2]==SPELL_EFFECT_LEARN_SPELL) )
        return 0;

    uint32 stanceMask = (form ? 1 << (form - 1) : 0);

    if (stanceMask & spellInfo->StancesNot)                 // can explicitly not be casted in this stance
        return SPELL_FAILED_NOT_SHAPESHIFT;

    if (stanceMask & spellInfo->Stances)                    // can explicitly be casted in this stance
        return 0;

    bool actAsShifted = false;
    if (form > 0)
    {
        SpellShapeshiftEntry const *shapeInfo = sSpellShapeshiftStore.LookupEntry(form);
        if (!shapeInfo)
        {
            sLog.outError("GetErrorAtShapeshiftedCast: unknown shapeshift %u", form);
            return 0;
        }
        actAsShifted = !(shapeInfo->flags1 & 1);            // shapeshift acts as normal form for spells
    }

    if(actAsShifted)
    {
        if (spellInfo->Attributes & SPELL_ATTR_NOT_SHAPESHIFT) // not while shapeshifted
            return SPELL_FAILED_NOT_SHAPESHIFT;
        else if (spellInfo->Stances != 0)                   // needs other shapeshift
            return SPELL_FAILED_ONLY_SHAPESHIFT;
    }
    else
    {
        // needs shapeshift
        if(!(spellInfo->AttributesEx2 & SPELL_ATTR_EX2_NOT_NEED_SHAPESHIFT) && spellInfo->Stances != 0)
            return SPELL_FAILED_ONLY_SHAPESHIFT;
    }

    return 0;
}

void SpellMgr::LoadSpellTargetPositions()
{
    mSpellTargetPositions.clear();                                // need for reload case

    uint32 count = 0;

    //                                                0   1           2                  3                  4                  5
    QueryResult *result = WorldDatabase.Query("SELECT id, target_map, target_position_x, target_position_y, target_position_z, target_orientation FROM spell_target_position");
    if( !result )
    {

        barGoLink bar( 1 );

        bar.step();

        sLog.outString();
        sLog.outString( ">> Loaded %u spell target coordinates", count );
        return;
    }

    barGoLink bar( result->GetRowCount() );

    do
    {
        Field *fields = result->Fetch();

        bar.step();

        ++count;

        uint32 Spell_ID = fields[0].GetUInt32();

        SpellTargetPosition st;

        st.target_mapId       = fields[1].GetUInt32();
        st.target_X           = fields[2].GetFloat();
        st.target_Y           = fields[3].GetFloat();
        st.target_Z           = fields[4].GetFloat();
        st.target_Orientation = fields[5].GetFloat();

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(Spell_ID);
        if(!spellInfo)
        {
            sLog.outErrorDb("Spell (ID:%u) listed in `spell_target_position` does not exist.",Spell_ID);
            continue;
        }

        bool found = false;
        for(int i = 0; i < 3; ++i)
        {
            if( spellInfo->EffectImplicitTargetA[i]==TARGET_TABLE_X_Y_Z_COORDINATES || spellInfo->EffectImplicitTargetB[i]==TARGET_TABLE_X_Y_Z_COORDINATES )
            {
                found = true;
                break;
            }
        }
        if(!found)
        {
            sLog.outErrorDb("Spell (Id: %u) listed in `spell_target_position` does not have target TARGET_TABLE_X_Y_Z_COORDINATES (17).",Spell_ID);
            continue;
        }

        MapEntry const* mapEntry = sMapStore.LookupEntry(st.target_mapId);
        if(!mapEntry)
        {
            sLog.outErrorDb("Spell (ID:%u) target map (ID: %u) does not exist in `Map.dbc`.",Spell_ID,st.target_mapId);
            continue;
        }

        if(st.target_X==0 && st.target_Y==0 && st.target_Z==0)
        {
            sLog.outErrorDb("Spell (ID:%u) target coordinates not provided.",Spell_ID);
            continue;
        }

        mSpellTargetPositions[Spell_ID] = st;

    } while( result->NextRow() );

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u spell teleport coordinates", count );
}

void SpellMgr::LoadSpellAffects()
{
    mSpellAffectMap.clear();                                // need for reload case

    uint32 count = 0;

    //                                                0      1         2                3                4
    QueryResult *result = WorldDatabase.Query("SELECT entry, effectId, SpellClassMask0, SpellClassMask1, SpellClassMask2 FROM spell_affect");
    if( !result )
    {

        barGoLink bar( 1 );

        bar.step();

        sLog.outString();
        sLog.outString( ">> Loaded %u spell affect definitions", count );
        return;
    }

    barGoLink bar( result->GetRowCount() );

    do
    {
        Field *fields = result->Fetch();

        bar.step();

        uint16 entry = fields[0].GetUInt16();
        uint8 effectId = fields[1].GetUInt8();

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(entry);

        if (!spellInfo)
        {
            sLog.outErrorDb("Spell %u listed in `spell_affect` does not exist", entry);
            continue;
        }

        if (effectId >= 3)
        {
            sLog.outErrorDb("Spell %u listed in `spell_affect` have invalid effect index (%u)", entry,effectId);
            continue;
        }

        if( spellInfo->Effect[effectId] != SPELL_EFFECT_APPLY_AURA ||
            spellInfo->EffectApplyAuraName[effectId] != SPELL_AURA_ADD_FLAT_MODIFIER &&
            spellInfo->EffectApplyAuraName[effectId] != SPELL_AURA_ADD_PCT_MODIFIER  &&
            spellInfo->EffectApplyAuraName[effectId] != SPELL_AURA_ADD_TARGET_TRIGGER )
        {
            sLog.outErrorDb("Spell %u listed in `spell_affect` have not SPELL_AURA_ADD_FLAT_MODIFIER (%u) or SPELL_AURA_ADD_PCT_MODIFIER (%u) or SPELL_AURA_ADD_TARGET_TRIGGER (%u) for effect index (%u)", entry,SPELL_AURA_ADD_FLAT_MODIFIER,SPELL_AURA_ADD_PCT_MODIFIER,SPELL_AURA_ADD_TARGET_TRIGGER,effectId);
            continue;
        }

        SpellAffectEntry affect;
        affect.SpellClassMask[0] = fields[2].GetUInt32();
        affect.SpellClassMask[1] = fields[3].GetUInt32();
        affect.SpellClassMask[2] = fields[4].GetUInt32();

        // Spell.dbc have own data
        uint32 const *ptr = 0;
        switch (effectId)
        {
            case 0: ptr = &spellInfo->EffectSpellClassMaskA[0]; break;
            case 1: ptr = &spellInfo->EffectSpellClassMaskB[0]; break;
            case 2: ptr = &spellInfo->EffectSpellClassMaskC[0]; break;
            default:
                continue;
        }
        if(ptr[0] == affect.SpellClassMask[0] || ptr[1] == affect.SpellClassMask[1] || ptr[2] == affect.SpellClassMask[2])
        {
            char text[]="ABC";
            sLog.outErrorDb("Spell %u listed in `spell_affect` have redundant (same with EffectSpellClassMask%c) data for effect index (%u) and not needed, skipped.", entry, text[effectId], effectId);
            continue;
        }

        mSpellAffectMap[(entry<<8) + effectId] = affect;

        ++count;
    } while( result->NextRow() );

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u custom spell affect definitions", count );

    for (uint32 id = 0; id < sSpellStore.GetNumRows(); ++id)
    {
        SpellEntry const* spellInfo = sSpellStore.LookupEntry(id);
        if (!spellInfo)
            continue;

        for (int effectId = 0; effectId < 3; ++effectId)
        {
            if( spellInfo->Effect[effectId] != SPELL_EFFECT_APPLY_AURA ||
                (spellInfo->EffectApplyAuraName[effectId] != SPELL_AURA_ADD_FLAT_MODIFIER &&
                spellInfo->EffectApplyAuraName[effectId] != SPELL_AURA_ADD_PCT_MODIFIER  &&
                spellInfo->EffectApplyAuraName[effectId] != SPELL_AURA_ADD_TARGET_TRIGGER) )
                continue;

            uint32 const *ptr = 0;
            switch (effectId)
            {
                case 0: ptr = &spellInfo->EffectSpellClassMaskA[0]; break;
                case 1: ptr = &spellInfo->EffectSpellClassMaskB[0]; break;
                case 2: ptr = &spellInfo->EffectSpellClassMaskC[0]; break;
                default:
                    continue;
            }
            if(ptr[0] || ptr[1] || ptr[2])
                continue;

            if(mSpellAffectMap.find((id<<8) + effectId) !=  mSpellAffectMap.end())
                continue;

            sLog.outErrorDb("Spell %u (%s) misses spell_affect for effect %u",id,spellInfo->SpellName[sWorld.GetDefaultDbcLocale()], effectId);
        }
    }
}

bool SpellMgr::IsAffectedByMod(SpellEntry const *spellInfo, SpellModifier *mod) const
{
    // false for spellInfo == NULL
    if (!spellInfo || !mod)
        return false;

    SpellEntry const *affect_spell = sSpellStore.LookupEntry(mod->spellId);
    // False if affect_spell == NULL or spellFamily not equal
    if (!affect_spell || affect_spell->SpellFamilyName != spellInfo->SpellFamilyName)
        return false;

    // true
    if (mod->mask  & spellInfo->SpellFamilyFlags ||
        mod->mask2 & spellInfo->SpellFamilyFlags2)
        return true;

    return false;
}

void SpellMgr::LoadSpellProcEvents()
{
    mSpellProcEventMap.clear();                             // need for reload case

    uint32 count = 0;

    //                                                0      1           2                3                 4                 5                 6          7       8        9             10
    QueryResult *result = WorldDatabase.Query("SELECT entry, SchoolMask, SpellFamilyName, SpellFamilyMask0, SpellFamilyMask1, SpellFamilyMask2, procFlags, procEx, ppmRate, CustomChance, Cooldown FROM spell_proc_event");
    if( !result )
    {
        barGoLink bar( 1 );
        bar.step();
        sLog.outString();
        sLog.outString( ">> Loaded %u spell proc event conditions", count  );
        return;
    }

    barGoLink bar( result->GetRowCount() );
    uint32 customProc = 0;
    do
    {
        Field *fields = result->Fetch();

        bar.step();

        uint16 entry = fields[0].GetUInt16();

        const SpellEntry *spell = sSpellStore.LookupEntry(entry);
        if (!spell)
        {
            sLog.outErrorDb("Spell %u listed in `spell_proc_event` does not exist", entry);
            continue;
        }

        SpellProcEventEntry spe;

        spe.schoolMask      = fields[1].GetUInt32();
        spe.spellFamilyName = fields[2].GetUInt32();
        spe.spellFamilyMask = (uint64)fields[3].GetUInt32()|((uint64)fields[4].GetUInt32()<<32);
        spe.spellFamilyMask2= fields[5].GetUInt32();
        spe.procFlags       = fields[6].GetUInt32();
        spe.procEx          = fields[7].GetUInt32();
        spe.ppmRate         = fields[8].GetFloat();
        spe.customChance    = fields[9].GetFloat();
        spe.cooldown        = fields[10].GetUInt32();

        mSpellProcEventMap[entry] = spe;

        if (spell->procFlags==0)
        {
            if (spe.procFlags == 0)
            {
                sLog.outErrorDb("Spell %u listed in `spell_proc_event` probally not triggered spell", entry);
                continue;
            }
            customProc++;
        }
        ++count;
    } while( result->NextRow() );

    delete result;

    sLog.outString();
    if (customProc)
        sLog.outString( ">> Loaded %u extra spell proc event conditions +%u custom",  count, customProc );
    else
        sLog.outString( ">> Loaded %u extra spell proc event conditions", count );
}

bool SpellMgr::IsSpellProcEventCanTriggeredBy(SpellProcEventEntry const * spellProcEvent, uint32 EventProcFlag, SpellEntry const * procSpell, uint32 procFlags, uint32 procExtra, bool active)
{
    // No extra req need
    uint32 procEvent_procEx = PROC_EX_NONE;

    // check prockFlags for condition
    if((procFlags & EventProcFlag) == 0)
        return false;

    // Always trigger for this
    if (EventProcFlag & (PROC_FLAG_KILLED | PROC_FLAG_KILL | PROC_FLAG_ON_TRAP_ACTIVATION))
        return true;

    if (spellProcEvent)     // Exist event data
    {
        // Store extra req
        procEvent_procEx = spellProcEvent->procEx;

        // For melee triggers
        if (procSpell == NULL)
        {
            // Check (if set) for school (melee attack have Normal school)
            if(spellProcEvent->schoolMask && (spellProcEvent->schoolMask & SPELL_SCHOOL_MASK_NORMAL) == 0)
                return false;
        }
        else // For spells need check school/spell family/family mask
        {
            // Check (if set) for school
            if(spellProcEvent->schoolMask && (spellProcEvent->schoolMask & procSpell->SchoolMask) == 0)
                return false;

            // Check (if set) for spellFamilyName
            if(spellProcEvent->spellFamilyName && (spellProcEvent->spellFamilyName != procSpell->SpellFamilyName))
                return false;

            // spellFamilyName is Ok need check for spellFamilyMask if present
            if(spellProcEvent->spellFamilyMask || spellProcEvent->spellFamilyMask2)
            {
                if ((spellProcEvent->spellFamilyMask  & procSpell->SpellFamilyFlags ) == 0 &&
                    (spellProcEvent->spellFamilyMask2 & procSpell->SpellFamilyFlags2) == 0)
                    return false;
                active = true; // Spell added manualy -> so its active spell
            }
        }
    }
    // Check for extra req (if none) and hit/crit
    if (procEvent_procEx == PROC_EX_NONE)
    {
        // No extra req, so can trigger only for active (damage/healing present) and hit/crit
        if((procExtra & (PROC_EX_NORMAL_HIT|PROC_EX_CRITICAL_HIT)) && active)
            return true;
    }
    else // Passive spells hits here only if resist/reflect/immune/evade
    {
        // Exist req for PROC_EX_EX_TRIGGER_ALWAYS
        if (procEvent_procEx & PROC_EX_EX_TRIGGER_ALWAYS)
            return true;
        // Passive spells can`t trigger if need hit
        if ((procEvent_procEx & PROC_EX_NORMAL_HIT) && !active)
            return false;
        // Check Extra Requirement like (hit/crit/miss/resist/parry/dodge/block/immune/reflect/absorb and other)
        if (procEvent_procEx & procExtra)
            return true;
    }
    return false;
}

void SpellMgr::LoadSpellElixirs()
{
    mSpellElixirs.clear();                                  // need for reload case

    uint32 count = 0;

    //                                                0      1
    QueryResult *result = WorldDatabase.Query("SELECT entry, mask FROM spell_elixir");
    if( !result )
    {

        barGoLink bar( 1 );

        bar.step();

        sLog.outString();
        sLog.outString( ">> Loaded %u spell elixir definitions", count );
        return;
    }

    barGoLink bar( result->GetRowCount() );

    do
    {
        Field *fields = result->Fetch();

        bar.step();

        uint16 entry = fields[0].GetUInt16();
        uint8 mask = fields[1].GetUInt8();

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(entry);

        if (!spellInfo)
        {
            sLog.outErrorDb("Spell %u listed in `spell_elixir` does not exist", entry);
            continue;
        }

        mSpellElixirs[entry] = mask;

        ++count;
    } while( result->NextRow() );

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u spell elixir definitions", count );
}

void SpellMgr::LoadSpellThreats()
{
    sSpellThreatStore.Free();                               // for reload

    sSpellThreatStore.Load();

    sLog.outString( ">> Loaded %u aggro generating spells", sSpellThreatStore.RecordCount );
    sLog.outString();
}

bool SpellMgr::IsRankSpellDueToSpell(SpellEntry const *spellInfo_1,uint32 spellId_2) const
{
    SpellEntry const *spellInfo_2 = sSpellStore.LookupEntry(spellId_2);
    if(!spellInfo_1 || !spellInfo_2) return false;
    if(spellInfo_1->Id == spellId_2) return false;

    return GetFirstSpellInChain(spellInfo_1->Id)==GetFirstSpellInChain(spellId_2);
}

bool SpellMgr::canStackSpellRanks(SpellEntry const *spellInfo)
{
    if(IsPassiveSpell(spellInfo->Id))                       // ranked passive spell
        return false;
    if(spellInfo->powerType != POWER_MANA && spellInfo->powerType != POWER_HEALTH)
        return false;
    if(IsProfessionOrRidingSpell(spellInfo->Id))
        return false;

    if(spellmgr.IsSkillBonusSpell(spellInfo->Id))
        return false;

    // All stance spells. if any better way, change it.
    for (int i = 0; i < 3; i++)
    {
        switch(spellInfo->SpellFamilyName)
        {
            case SPELLFAMILY_PALADIN:
                // Paladin aura Spell
                if (spellInfo->Effect[i]==SPELL_EFFECT_APPLY_AREA_AURA_RAID)
                    return false;
                break;
            case SPELLFAMILY_DRUID:
                // Druid form Spell
                if (spellInfo->Effect[i]==SPELL_EFFECT_APPLY_AURA &&
                    spellInfo->EffectApplyAuraName[i] == SPELL_AURA_MOD_SHAPESHIFT)
                    return false;
                break;
            case SPELLFAMILY_ROGUE:
                // Rogue Stealth
                if (spellInfo->Effect[i]==SPELL_EFFECT_APPLY_AURA &&
                    spellInfo->EffectApplyAuraName[i] == SPELL_AURA_MOD_SHAPESHIFT)
                    return false;
        }
    }
    return true;
}

bool SpellMgr::IsNoStackSpellDueToSpell(uint32 spellId_1, uint32 spellId_2, bool sameCaster) const
{
    //if(spellId_1 == spellId_2) // auras due to the same spell
    //    return false;
    SpellEntry const *spellInfo_1 = sSpellStore.LookupEntry(spellId_1);
    SpellEntry const *spellInfo_2 = sSpellStore.LookupEntry(spellId_2);

    if(!spellInfo_1 || !spellInfo_2)
        return false;

    SpellSpecific spellId_spec_1 = GetSpellSpecific(spellId_1);
    SpellSpecific spellId_spec_2 = GetSpellSpecific(spellId_2);
    if (spellId_spec_1 && spellId_spec_2)
        if (IsSingleFromSpellSpecificPerTarget(spellId_spec_1, spellId_spec_2)
            ||(IsSingleFromSpellSpecificPerCaster(spellId_spec_1, spellId_spec_2) && sameCaster))
            return true;

    // spells with different specific always stack
    if(spellId_spec_1 || spellId_spec_2)
        return false;

    if(spellInfo_1->SpellFamilyName != spellInfo_2->SpellFamilyName)
        return false;

    // TODO: Is this needed?
    // Allow stack passive and not passive spells
    if ((spellInfo_1->Attributes & SPELL_ATTR_PASSIVE)!=(spellInfo_2->Attributes & SPELL_ATTR_PASSIVE))
        return false;

    // generic spells
    if(!spellInfo_1->SpellFamilyName)
    {
        if(!spellInfo_1->SpellIconID
            || spellInfo_1->SpellIconID == 1
            || spellInfo_1->SpellIconID != spellInfo_2->SpellIconID)
            return false;
    }

    // check for class spells
    else
    {
        if (spellInfo_1->SpellFamilyFlags != spellInfo_2->SpellFamilyFlags)
            return false;
    }

    if(!sameCaster)
    {
        for(uint32 i = 0; i < 3; ++i)
            if (spellInfo_1->Effect[i] == SPELL_EFFECT_APPLY_AURA
                || spellInfo_1->Effect[i] == SPELL_EFFECT_PERSISTENT_AREA_AURA)
                // not area auras (shaman totem)
                switch(spellInfo_1->EffectApplyAuraName[i])
                {
                    // DOT or HOT from different casters will stack
                    case SPELL_AURA_PERIODIC_DAMAGE:
                    case SPELL_AURA_PERIODIC_HEAL:
                    case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
                    case SPELL_AURA_PERIODIC_ENERGIZE:
                    case SPELL_AURA_PERIODIC_MANA_LEECH:
                    case SPELL_AURA_PERIODIC_LEECH:
                        return false;
                    default:
                        break;
                }
    }

//    not needed now because we compare effects last rank of spells
//    if(spellInfo_1->SpellFamilyName && IsRankSpellDueToSpell(spellInfo_1, spellId_2))
//        return true;

    //use data of highest rank spell(needed for spells which ranks have different effects)
    spellInfo_1=sSpellStore.LookupEntry(GetLastSpellInChain(spellId_1));
    spellInfo_2=sSpellStore.LookupEntry(GetLastSpellInChain(spellId_2));

    //if spells have exactly the same effect they cannot stack
    for(uint32 i = 0; i < 3; ++i)
        if(spellInfo_1->Effect[i] != spellInfo_2->Effect[i]
            || spellInfo_1->EffectApplyAuraName[i] != spellInfo_2->EffectApplyAuraName[i]
            || spellInfo_1->EffectMiscValue[i] != spellInfo_2->EffectMiscValue[i]) // paladin resist aura
            return false; // need itemtype check? need an example to add that check

    return true;
}

bool SpellMgr::IsProfessionOrRidingSpell(uint32 spellId)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);
    if(!spellInfo)
        return false;

    if(spellInfo->Effect[1] != SPELL_EFFECT_SKILL)
        return false;

    uint32 skill = spellInfo->EffectMiscValue[1];

    return IsProfessionOrRidingSkill(skill);
}

bool SpellMgr::IsProfessionSpell(uint32 spellId)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);
    if(!spellInfo)
        return false;

    if(spellInfo->Effect[1] != SPELL_EFFECT_SKILL)
        return false;

    uint32 skill = spellInfo->EffectMiscValue[1];

    return IsProfessionSkill(skill);
}

bool SpellMgr::IsPrimaryProfessionSpell(uint32 spellId)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);
    if(!spellInfo)
        return false;

    if(spellInfo->Effect[1] != SPELL_EFFECT_SKILL)
        return false;

    uint32 skill = spellInfo->EffectMiscValue[1];

    return IsPrimaryProfessionSkill(skill);
}

bool SpellMgr::IsPrimaryProfessionFirstRankSpell(uint32 spellId) const
{
    return IsPrimaryProfessionSpell(spellId) && GetSpellRank(spellId)==1;
}

bool SpellMgr::IsSkillBonusSpell(uint32 spellId) const
{
    SkillLineAbilityMap::const_iterator lower = GetBeginSkillLineAbilityMap(spellId);
    SkillLineAbilityMap::const_iterator upper = GetEndSkillLineAbilityMap(spellId);

    for(SkillLineAbilityMap::const_iterator _spell_idx = lower; _spell_idx != upper; ++_spell_idx)
    {
        SkillLineAbilityEntry const *pAbility = _spell_idx->second;
        if (!pAbility || pAbility->learnOnGetSkill != ABILITY_LEARNED_ON_GET_PROFESSION_SKILL)
            continue;

        if(pAbility->req_skill_value > 0)
            return true;
    }

    return false;
}

SpellEntry const* SpellMgr::SelectAuraRankForPlayerLevel(SpellEntry const* spellInfo, uint32 playerLevel) const
{
    // ignore passive spells
    if(IsPassiveSpell(spellInfo->Id))
        return spellInfo;

    bool needRankSelection = false;
    for(int i=0;i<3;i++)
    {
        if( IsPositiveEffect(spellInfo->Id, i) && (
            spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AURA ||
            spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AREA_AURA_PARTY ||
            spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AREA_AURA_RAID
            ) )
        {
            needRankSelection = true;
            break;
        }
    }

    // not required
    if(!needRankSelection)
        return spellInfo;

    for(uint32 nextSpellId = spellInfo->Id; nextSpellId != 0; nextSpellId = GetPrevSpellInChain(nextSpellId))
    {
        SpellEntry const *nextSpellInfo = sSpellStore.LookupEntry(nextSpellId);
        if(!nextSpellInfo)
            break;

        // if found appropriate level
        if(playerLevel + 10 >= nextSpellInfo->spellLevel)
            return nextSpellInfo;

        // one rank less then
    }

    // not found
    return NULL;
}

void SpellMgr::LoadSpellRequired()
{
    mSpellsReqSpell.clear();                                   // need for reload case
    mSpellReq.clear();                                         // need for reload case

    QueryResult *result = WorldDatabase.Query("SELECT spell_id, req_spell from spell_required");

    if(result == NULL)
    {
        barGoLink bar( 1 );
        bar.step();

        sLog.outString();
        sLog.outString( ">> Loaded 0 spell required records" );
        sLog.outErrorDb("`spell_required` table is empty!");
        return;
    }
    uint32 rows = 0;

    barGoLink bar( result->GetRowCount() );
    do
    {
        bar.step();
        Field *fields = result->Fetch();

        uint32 spell_id = fields[0].GetUInt32();
        uint32 spell_req = fields[1].GetUInt32();

        mSpellsReqSpell.insert (std::pair<uint32, uint32>(spell_req, spell_id));
        mSpellReq[spell_id] = spell_req;
        ++rows;
    } while( result->NextRow() );
    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u spell required records", rows );
}

struct SpellRankEntry
{
    uint32 SkillId;
    char const *SpellName;
    uint32 DurationIndex;
    uint32 RangeIndex;
    uint32 SpellVisual;
    uint32 ProcFlags;
    uint64 SpellFamilyFlags;
    uint32 TargetAuraState;
    uint32 ManaCost;

    bool operator()(const SpellRankEntry & _Left,const SpellRankEntry & _Right)const
    {
        return (_Left.SkillId != _Right.SkillId ? _Left.SkillId < _Right.SkillId
            : _Left.SpellName!=_Right.SpellName ? _Left.SpellName < _Right.SpellName
            : _Left.ProcFlags!=_Right.ProcFlags ? _Left.ProcFlags < _Right.ProcFlags
            : _Left.SpellFamilyFlags!=_Right.SpellFamilyFlags ? _Left.SpellFamilyFlags < _Right.SpellFamilyFlags
            : (_Left.SpellVisual!=_Right.SpellVisual) && (!_Left.SpellVisual || !_Right.SpellVisual) ? _Left.SpellVisual < _Right.SpellVisual
            : (_Left.ManaCost!=_Right.ManaCost) && (!_Left.ManaCost || !_Right.ManaCost) ? _Left.ManaCost < _Right.ManaCost
            : (_Left.DurationIndex!=_Right.DurationIndex) && (!_Left.DurationIndex || !_Right.DurationIndex)? _Left.DurationIndex < _Right.DurationIndex
            : (_Left.RangeIndex!=_Right.RangeIndex) && (!_Left.RangeIndex || !_Right.RangeIndex || _Left.RangeIndex==1 || !_Right.RangeIndex==1) ? _Left.RangeIndex < _Right.RangeIndex
            : _Left.TargetAuraState < _Right.TargetAuraState
            );
    }
};

struct SpellRankValue
{
    uint32 Id;
    char const *Rank;
};

void SpellMgr::LoadSpellChains()
{
    mSpellChains.clear();                                   // need for reload case

    std::vector<uint32> ChainedSpells;
    for (uint32 ability_id=0;ability_id<sSkillLineAbilityStore.GetNumRows();ability_id++)
    {
        SkillLineAbilityEntry const *AbilityInfo=sSkillLineAbilityStore.LookupEntry(ability_id);
        if (!AbilityInfo)
            continue;
        if (AbilityInfo->spellId==20154) //exception to these rules (not needed in 3.0.3)
            continue;
        if (!AbilityInfo->forward_spellid)
            continue;
        ChainedSpells.push_back(AbilityInfo->forward_spellid);
    }

    std::multimap<SpellRankEntry, SpellRankValue,SpellRankEntry> RankMap;

    for (uint32 ability_id=0;ability_id<sSkillLineAbilityStore.GetNumRows();ability_id++)
    {
        SkillLineAbilityEntry const *AbilityInfo=sSkillLineAbilityStore.LookupEntry(ability_id);
        if (!AbilityInfo)
            continue;

        //get only spell with lowest ability_id to prevent doubles
        uint32 spell_id=AbilityInfo->spellId;
        if (spell_id==20154) //exception to these rules (not needed in 3.0.3)
            continue;
        bool found=false;
        for (uint32 i=0; i<ChainedSpells.size(); i++)
        {
           if (ChainedSpells.at(i)==spell_id)
               found=true;
        }
        if (found)
            continue;

        if(mSkillLineAbilityMap.lower_bound(spell_id)->second->id!=ability_id)
            continue;
        SpellEntry const *SpellInfo=sSpellStore.LookupEntry(spell_id);
        if (!SpellInfo)
            continue;
        std::string sRank = SpellInfo->Rank[sWorld.GetDefaultDbcLocale()];
        if(sRank.empty())
            continue;
        //exception to polymorph spells-make pig and turtle other chain than sheep
        if ((SpellInfo->SpellFamilyName==SPELLFAMILY_MAGE) && (SpellInfo->SpellFamilyFlags & 0x1000000) && (SpellInfo->SpellIconID!=82))
            continue;

        SpellRankEntry entry;
        SpellRankValue value;
        entry.SkillId=AbilityInfo->skillId;
        entry.SpellName=SpellInfo->SpellName[sWorld.GetDefaultDbcLocale()];
        entry.DurationIndex=SpellInfo->DurationIndex;
        entry.RangeIndex=SpellInfo->rangeIndex;
        entry.ProcFlags=SpellInfo->procFlags;
        entry.SpellFamilyFlags=SpellInfo->SpellFamilyFlags;
        entry.TargetAuraState=SpellInfo->TargetAuraState;
        entry.SpellVisual=SpellInfo->SpellVisual[0];
        entry.ManaCost=SpellInfo->manaCost;

        for (;;)
        {
            AbilityInfo=mSkillLineAbilityMap.lower_bound(spell_id)->second;
            value.Id=spell_id;
            value.Rank=SpellInfo->Rank[sWorld.GetDefaultDbcLocale()];
            RankMap.insert(std::pair<SpellRankEntry, SpellRankValue>(entry,value));
            spell_id=AbilityInfo->forward_spellid;
            SpellInfo=sSpellStore.LookupEntry(spell_id);
            if (!SpellInfo)
                break;
        }
    }

    barGoLink bar(RankMap.size());

    uint32 count=0;

    for (std::multimap<SpellRankEntry, SpellRankValue,SpellRankEntry>::iterator itr = RankMap.begin();itr!=RankMap.end();)
    {
        SpellRankEntry entry=itr->first;
        //trac errors in extracted data
        std::multimap<char const *, std::multimap<SpellRankEntry, SpellRankValue,SpellRankEntry>::iterator> RankErrorMap;
        for (std::multimap<SpellRankEntry, SpellRankValue,SpellRankEntry>::iterator itr2 = RankMap.lower_bound(entry);itr2!=RankMap.upper_bound(entry);itr2++)
        {
            bar.step();
            RankErrorMap.insert(std::pair<char const *, std::multimap<SpellRankEntry, SpellRankValue,SpellRankEntry>::iterator>(itr2->second.Rank,itr2));
        }
        for (std::multimap<char const *, std::multimap<SpellRankEntry, SpellRankValue,SpellRankEntry>::iterator>::iterator itr2 = RankErrorMap.begin();itr2!=RankErrorMap.end();)
        {
            char const * err_entry=itr2->first;
            uint32 rank_count=RankErrorMap.count(itr2->first);
            if (rank_count>1)
            for (itr2 = RankErrorMap.lower_bound(err_entry);itr2!=RankErrorMap.upper_bound(err_entry);itr2++)
            {
                sLog.outDebug("There is a duplicate rank entry (%s) for spell: %u",itr2->first,itr2->second->second.Id);
                sLog.outDebug("Spell %u removed from chain data.",itr2->second->second.Id);
                RankMap.erase(itr2->second);
                itr=RankMap.lower_bound(entry);
            }
            else
                itr2++;
        }
        //do not proceed for spells with less than 2 ranks
        uint32 spell_max_rank=RankMap.count(entry);
        if (spell_max_rank<2)
        {
            itr=RankMap.upper_bound(entry);
            continue;
        }

        itr=RankMap.upper_bound(entry);

        //order spells by spells by spellLevel
        std::list<uint32> RankedSpells;
        uint32 min_spell_lvl=0;
        std::multimap<SpellRankEntry, SpellRankValue,SpellRankEntry>::iterator min_itr;
        for (;RankMap.count(entry);)
        {
            for (std::multimap<SpellRankEntry, SpellRankValue,SpellRankEntry>::iterator itr2 = RankMap.lower_bound(entry);itr2!=RankMap.upper_bound(entry);itr2++)
            {
                SpellEntry const *SpellInfo=sSpellStore.LookupEntry(itr2->second.Id);
                if (SpellInfo->spellLevel<min_spell_lvl || itr2==RankMap.lower_bound(entry))
                {
                    min_spell_lvl=SpellInfo->spellLevel;
                    min_itr=itr2;
                }
            }
            RankedSpells.push_back(min_itr->second.Id);
            RankMap.erase(min_itr);
        }

        //use data from talent.dbc
        uint16 talent_id=0;
        for(std::list<uint32>::iterator itr2 = RankedSpells.begin();itr2!=RankedSpells.end();)
        {
            if (TalentSpellPos const* TalentPos=GetTalentSpellPos(*itr2))
            {
                talent_id=TalentPos->talent_id;
                RankedSpells.erase(itr2);
                itr2 = RankedSpells.begin();
            }
            else
                itr2++;
        }
        if (talent_id)
        {
            TalentEntry const *TalentInfo = sTalentStore.LookupEntry(talent_id);
            for (uint8 rank=5;rank;rank--)
            {
                if (TalentInfo->RankID[rank-1])
                    RankedSpells.push_front(TalentInfo->RankID[rank-1]);
            }
        }

        count++;

        itr=RankMap.upper_bound(entry);
        uint32 spell_rank=1;
        for(std::list<uint32>::iterator itr2 = RankedSpells.begin();itr2!=RankedSpells.end();spell_rank++)
        {
            uint32 spell_id=*itr2;
            mSpellChains[spell_id].rank=spell_rank;
            mSpellChains[spell_id].first=RankedSpells.front();
            mSpellChains[spell_id].last=RankedSpells.back();

            itr2++;
            if (spell_rank<2)
                mSpellChains[spell_id].prev=0;

            if (spell_id==RankedSpells.back())
                mSpellChains[spell_id].next=0;
            else
            {
                mSpellChains[*itr2].prev=spell_id;
                mSpellChains[spell_id].next=*itr2;
            }
        }
    }

//uncomment these two lines to print yourself list of spell_chains on startup
//    for (UNORDERED_MAP<uint32, SpellChainNode>::iterator itr=mSpellChains.begin();itr!=mSpellChains.end();itr++)
//       sLog.outString( "Id: %u, Rank: %d , %s",itr->first,itr->second.rank, sSpellStore.LookupEntry(itr->first)->Rank[sWorld.GetDefaultDbcLocale()]);

    sLog.outString();
    sLog.outString( ">> Loaded %u spell chains",count);
}

void SpellMgr::LoadSpellLearnSkills()
{
    mSpellLearnSkills.clear();                              // need for reload case

    // search auto-learned skills and add its to map also for use in unlearn spells/talents
    uint32 dbc_count = 0;
    barGoLink bar( sSpellStore.GetNumRows() );
    for(uint32 spell = 0; spell < sSpellStore.GetNumRows(); ++spell)
    {
        bar.step();
        SpellEntry const* entry = sSpellStore.LookupEntry(spell);

        if(!entry)
            continue;

        for(int i = 0; i < 3; ++i)
        {
            if(entry->Effect[i]==SPELL_EFFECT_SKILL)
            {
                SpellLearnSkillNode dbc_node;
                dbc_node.skill    = entry->EffectMiscValue[i];
                if ( dbc_node.skill != SKILL_RIDING )
                    dbc_node.value    = 1;
                else
                    dbc_node.value    = (entry->EffectBasePoints[i]+1)*75;
                dbc_node.maxvalue = (entry->EffectBasePoints[i]+1)*75;

                SpellLearnSkillNode const* db_node = GetSpellLearnSkill(spell);

                mSpellLearnSkills[spell] = dbc_node;
                ++dbc_count;
                break;
            }
        }
    }

    sLog.outString();
    sLog.outString( ">> Loaded %u Spell Learn Skills from DBC", dbc_count );
}

void SpellMgr::LoadSpellLearnSpells()
{
    mSpellLearnSpells.clear();                              // need for reload case

    //                                                0      1        2
    QueryResult *result = WorldDatabase.Query("SELECT entry, SpellID, Active FROM spell_learn_spell");
    if(!result)
    {
        barGoLink bar( 1 );
        bar.step();

        sLog.outString();
        sLog.outString( ">> Loaded 0 spell learn spells" );
        sLog.outErrorDb("`spell_learn_spell` table is empty!");
        return;
    }

    uint32 count = 0;

    barGoLink bar( result->GetRowCount() );
    do
    {
        bar.step();
        Field *fields = result->Fetch();

        uint32 spell_id    = fields[0].GetUInt32();

        SpellLearnSpellNode node;
        node.spell      = fields[1].GetUInt32();
        node.active     = fields[2].GetBool();
        node.autoLearned= false;

        if(!sSpellStore.LookupEntry(spell_id))
        {
            sLog.outErrorDb("Spell %u listed in `spell_learn_spell` does not exist",spell_id);
            continue;
        }

        if(!sSpellStore.LookupEntry(node.spell))
        {
            sLog.outErrorDb("Spell %u listed in `spell_learn_spell` does not exist",node.spell);
            continue;
        }

        mSpellLearnSpells.insert(SpellLearnSpellMap::value_type(spell_id,node));

        ++count;
    } while( result->NextRow() );

    delete result;

    // search auto-learned spells and add its to map also for use in unlearn spells/talents
    uint32 dbc_count = 0;
    for(uint32 spell = 0; spell < sSpellStore.GetNumRows(); ++spell)
    {
        SpellEntry const* entry = sSpellStore.LookupEntry(spell);

        if(!entry)
            continue;

        for(int i = 0; i < 3; ++i)
        {
            if(entry->Effect[i]==SPELL_EFFECT_LEARN_SPELL)
            {
                SpellLearnSpellNode dbc_node;
                dbc_node.spell       = entry->EffectTriggerSpell[i];
                dbc_node.active      = true;                // all dbc based learned spells is active (show in spell book or hide by client itself)

                // ignore learning not existed spells (broken/outdated/or generic learnig spell 483
                if(!sSpellStore.LookupEntry(dbc_node.spell))
                    continue;

                // talent or passive spells or skill-step spells auto-casted and not need dependent learning,
                // pet teaching spells don't must be dependent learning (casted)
                // other required explicit dependent learning
                dbc_node.autoLearned = entry->EffectImplicitTargetA[i]==TARGET_PET || GetTalentSpellCost(spell) > 0 || IsPassiveSpell(spell) || IsSpellHaveEffect(entry,SPELL_EFFECT_SKILL_STEP);

                SpellLearnSpellMap::const_iterator db_node_begin = GetBeginSpellLearnSpell(spell);
                SpellLearnSpellMap::const_iterator db_node_end   = GetEndSpellLearnSpell(spell);

                bool found = false;
                for(SpellLearnSpellMap::const_iterator itr = db_node_begin; itr != db_node_end; ++itr)
                {
                    if(itr->second.spell == dbc_node.spell)
                    {
                        sLog.outErrorDb("Spell %u auto-learn spell %u in spell.dbc then the record in `spell_learn_spell` is redundant, please fix DB.",
                            spell,dbc_node.spell);
                        found = true;
                        break;
                    }
                }

                if(!found)                                  // add new spell-spell pair if not found
                {
                    mSpellLearnSpells.insert(SpellLearnSpellMap::value_type(spell,dbc_node));
                    ++dbc_count;
                }
            }
        }
    }

    sLog.outString();
    sLog.outString( ">> Loaded %u spell learn spells + %u found in DBC", count, dbc_count );
}

void SpellMgr::LoadSpellScriptTarget()
{
    mSpellScriptTarget.clear();                             // need for reload case

    uint32 count = 0;

    QueryResult *result = WorldDatabase.Query("SELECT entry,type,targetEntry FROM spell_script_target");

    if(!result)
    {
        barGoLink bar(1);

        bar.step();

        sLog.outString();
        sLog.outString( ">> Loaded 0 spell script target" );
        sLog.outErrorDb("`spell_script_target` table is empty!");
        return;
    }

    barGoLink bar(result->GetRowCount());

    do
    {
        Field *fields = result->Fetch();
        bar.step();

        uint32 spellId     = fields[0].GetUInt32();
        uint32 type        = fields[1].GetUInt32();
        uint32 targetEntry = fields[2].GetUInt32();

        SpellEntry const* spellProto = sSpellStore.LookupEntry(spellId);

        if(!spellProto)
        {
            sLog.outErrorDb("Table `spell_script_target`: spellId %u listed for TargetEntry %u does not exist.",spellId,targetEntry);
            continue;
        }

        /*bool targetfound = false;
        for(int i = 0; i <3; ++i)
        {
            if( spellProto->EffectImplicitTargetA[i]==TARGET_SCRIPT ||
                spellProto->EffectImplicitTargetB[i]==TARGET_SCRIPT ||
                spellProto->EffectImplicitTargetA[i]==TARGET_SCRIPT_COORDINATES ||
                spellProto->EffectImplicitTargetB[i]==TARGET_SCRIPT_COORDINATES )
            {
                targetfound = true;
                break;
            }
        }
        if(!targetfound)
        {
            sLog.outErrorDb("Table `spell_script_target`: spellId %u listed for TargetEntry %u does not have any implicit target TARGET_SCRIPT(38) or TARGET_SCRIPT_COORDINATES (46).",spellId,targetEntry);
            continue;
        }*/

        if( type >= MAX_SPELL_TARGET_TYPE )
        {
            sLog.outErrorDb("Table `spell_script_target`: target type %u for TargetEntry %u is incorrect.",type,targetEntry);
            continue;
        }

        switch(type)
        {
            case SPELL_TARGET_TYPE_GAMEOBJECT:
            {
                if( targetEntry==0 )
                    break;

                if(!sGOStorage.LookupEntry<GameObjectInfo>(targetEntry))
                {
                    sLog.outErrorDb("Table `spell_script_target`: gameobject template entry %u does not exist.",targetEntry);
                    continue;
                }
                break;
            }
            default:
            {
                //players
                /*if( targetEntry==0 )
                {
                    sLog.outErrorDb("Table `spell_script_target`: target entry == 0 for not GO target type (%u).",type);
                    continue;
                }*/
                if(targetEntry && !sCreatureStorage.LookupEntry<CreatureInfo>(targetEntry))
                {
                    sLog.outErrorDb("Table `spell_script_target`: creature template entry %u does not exist.",targetEntry);
                    continue;
                }
                const CreatureInfo* cInfo = sCreatureStorage.LookupEntry<CreatureInfo>(targetEntry);

                if(spellId == 30427 && !cInfo->SkinLootId)
                {
                    sLog.outErrorDb("Table `spell_script_target` has creature %u as a target of spellid 30427, but this creature has no skinlootid. Gas extraction will not work!", cInfo->Entry);
                    continue;
                }
                break;
            }
        }

        mSpellScriptTarget.insert(SpellScriptTarget::value_type(spellId,SpellTargetEntry(SpellScriptTargetType(type),targetEntry)));

        ++count;
    } while (result->NextRow());

    delete result;

    // Check all spells
    /* Disabled (lot errors at this moment)
    for(uint32 i = 1; i < sSpellStore.nCount; ++i)
    {
        SpellEntry const * spellInfo = sSpellStore.LookupEntry(i);
        if(!spellInfo)
            continue;

        bool found = false;
        for(int j=0; j<3; ++j)
        {
            if( spellInfo->EffectImplicitTargetA[j] == TARGET_SCRIPT || spellInfo->EffectImplicitTargetA[j] != TARGET_SELF && spellInfo->EffectImplicitTargetB[j] == TARGET_SCRIPT )
            {
                SpellScriptTarget::const_iterator lower = spellmgr.GetBeginSpellScriptTarget(spellInfo->Id);
                SpellScriptTarget::const_iterator upper = spellmgr.GetEndSpellScriptTarget(spellInfo->Id);
                if(lower==upper)
                {
                    sLog.outErrorDb("Spell (ID: %u) has effect EffectImplicitTargetA/EffectImplicitTargetB = %u (TARGET_SCRIPT), but does not have record in `spell_script_target`",spellInfo->Id,TARGET_SCRIPT);
                    break;                                  // effects of spell
                }
            }
        }
    }
    */

    sLog.outString();
    sLog.outString(">> Loaded %u Spell Script Targets", count);
}

void SpellMgr::LoadSpellPetAuras()
{
    mSpellPetAuraMap.clear();                                  // need for reload case

    uint32 count = 0;

    //                                                0      1    2
    QueryResult *result = WorldDatabase.Query("SELECT spell, pet, aura FROM spell_pet_auras");
    if( !result )
    {

        barGoLink bar( 1 );

        bar.step();

        sLog.outString();
        sLog.outString( ">> Loaded %u spell pet auras", count );
        return;
    }

    barGoLink bar( result->GetRowCount() );

    do
    {
        Field *fields = result->Fetch();

        bar.step();

        uint16 spell = fields[0].GetUInt16();
        uint16 pet = fields[1].GetUInt16();
        uint16 aura = fields[2].GetUInt16();

        SpellPetAuraMap::iterator itr = mSpellPetAuraMap.find(spell);
        if(itr != mSpellPetAuraMap.end())
        {
            itr->second.AddAura(pet, aura);
        }
        else
        {
            SpellEntry const* spellInfo = sSpellStore.LookupEntry(spell);
            if (!spellInfo)
            {
                sLog.outErrorDb("Spell %u listed in `spell_pet_auras` does not exist", spell);
                continue;
            }
            int i = 0;
            for(; i < 3; ++i)
                if((spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AURA &&
                    spellInfo->EffectApplyAuraName[i] == SPELL_AURA_DUMMY) ||
                    spellInfo->Effect[i] == SPELL_EFFECT_DUMMY)
                    break;

            if(i == 3)
            {
                sLog.outError("Spell %u listed in `spell_pet_auras` does not have dummy aura or dummy effect", spell);
                continue;
            }

            SpellEntry const* spellInfo2 = sSpellStore.LookupEntry(aura);
            if (!spellInfo2)
            {
                sLog.outErrorDb("Aura %u listed in `spell_pet_auras` does not exist", aura);
                continue;
            }

            PetAura pa(pet, aura, spellInfo->EffectImplicitTargetA[i] == TARGET_PET, spellInfo->EffectBasePoints[i] + spellInfo->EffectBaseDice[i]);
            mSpellPetAuraMap[spell] = pa;
        }

        ++count;
    } while( result->NextRow() );

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u spell pet auras", count );
}

// set data in core for now
void SpellMgr::LoadSpellCustomAttr()
{
    mSpellCustomAttr.resize(GetSpellStore()->GetNumRows());

    SpellEntry *spellInfo;
    for(uint32 i = 0; i < GetSpellStore()->GetNumRows(); ++i)
    {
        mSpellCustomAttr[i] = 0;
        spellInfo = (SpellEntry*)GetSpellStore()->LookupEntry(i);
        if(!spellInfo)
            continue;

        bool auraSpell = true;
        for(uint32 j = 0; j < 3; ++j)
        {
            if(spellInfo->Effect[j])
                if(spellInfo->Effect[j] != SPELL_EFFECT_APPLY_AURA
                || SpellTargetType[spellInfo->EffectImplicitTargetA[j]] != TARGET_TYPE_UNIT_TARGET)
                //ignore target party for now
                {
                    auraSpell = false;
                    break;
                }
        }
        if(auraSpell)
            mSpellCustomAttr[i] |= SPELL_ATTR_CU_AURA_SPELL;

        for(uint32 j = 0; j < 3; ++j)
        {
            switch(spellInfo->EffectApplyAuraName[j])
            {
                case SPELL_AURA_PERIODIC_DAMAGE:
                case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
                case SPELL_AURA_PERIODIC_LEECH:
                    mSpellCustomAttr[i] |= SPELL_ATTR_CU_AURA_DOT;
                    break;
                case SPELL_AURA_PERIODIC_HEAL:
                case SPELL_AURA_OBS_MOD_HEALTH:
                    mSpellCustomAttr[i] |= SPELL_ATTR_CU_AURA_HOT;
                    break;
                case SPELL_AURA_MOD_POSSESS:
                case SPELL_AURA_MOD_CONFUSE:
                case SPELL_AURA_MOD_CHARM:
                case SPELL_AURA_MOD_FEAR:
                case SPELL_AURA_MOD_STUN:
                case SPELL_AURA_MOD_ROOT:
                    mSpellCustomAttr[i] |= SPELL_ATTR_CU_AURA_CC;
                    break;
                default:
                    break;
            }

            switch(spellInfo->Effect[j])
            {
                case SPELL_EFFECT_SCHOOL_DAMAGE:
                case SPELL_EFFECT_WEAPON_DAMAGE:
                case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                case SPELL_EFFECT_HEAL:
                    mSpellCustomAttr[i] |= SPELL_ATTR_CU_DIRECT_DAMAGE;
            }
        }

        if(spellInfo->SpellVisual[0] == 3879)
            mSpellCustomAttr[i] |= SPELL_ATTR_CU_CONE_BACK;

        switch(i)
        {
        case 26029: // dark glare
        case 37433: // spout
        case 43140: case 43215: // flame breath
            mSpellCustomAttr[i] |= SPELL_ATTR_CU_CONE_LINE;
            break;
        case 24340: case 26558: case 28884:     // Meteor
        case 36837: case 38903: case 41276:     // Meteor
        case 26789:                             // Shard of the Fallen Star
        case 31436:                             // Malevolent Cleave
        case 35181:                             // Dive Bomb
        case 40810: case 43267: case 43268:     // Saber Lash
        case 42384:                             // Brutal Swipe
        case 45150:                             // Meteor Slash
            mSpellCustomAttr[i] |= SPELL_ATTR_CU_SHARE_DAMAGE;
            break;
        case 44978: case 45001: case 45002:     // Wild Magic
        case 45004: case 45006: case 45010:     // Wild Magic
        case 31347: // Doom
        case 41635: // Prayer of Mending
        case 44869: // Spectral Blast
        case 45027: // Revitalize
        case 45976: // Muru Portal Channel
            spellInfo->MaxAffectedTargets = 1;
            break;
        case 41376: // Spite
        case 39992: // Needle Spine
		case 29576: //Multi-Shot
		case 40816: //Saber Lash
		case 37790: //Spread Shot
		case 46771: //Flame Sear
		case 45248: //Shadow Blades
        case 41303: // Soul Drain
            spellInfo->MaxAffectedTargets = 3;
            break;
		case 38310: //Multi-Shot
			spellInfo->MaxAffectedTargets = 4;
			break;
        case 42005: // Bloodboil
		case 38296: //Spitfire Totem
		case 37676: //Insidious Whisper
		case 46009: //Negative Energy
            spellInfo->MaxAffectedTargets = 5;
            break;
		case 40827: //Sinful Beam
		case 40859: //Sinister Beam
		case 40860: //Vile Beam
		case 40861: //Wicked Beam
			spellInfo->MaxAffectedTargets = 10;
			break;
        case 8122: case 8124: case 10888: case 10890: // Psychic Scream
        case 12494: // Frostbite
            spellInfo->Attributes |= SPELL_ATTR_BREAKABLE_BY_DAMAGE;
            break;
        default:
            break;
        }
    }
}

void SpellMgr::LoadSpellLinked()
{
    mSpellLinkedMap.clear();    // need for reload case
    uint32 count = 0;

    //                                                0              1             2
    QueryResult *result = WorldDatabase.Query("SELECT spell_trigger, spell_effect, type FROM spell_linked_spell");
    if( !result )
    {
        barGoLink bar( 1 );
        bar.step();
        sLog.outString();
        sLog.outString( ">> Loaded %u linked spells", count );
        return;
    }

    barGoLink bar( result->GetRowCount() );

    do
    {
        Field *fields = result->Fetch();

        bar.step();

        int32 trigger = fields[0].GetInt32();
        int32 effect = fields[1].GetInt32();
        int32 type = fields[2].GetInt32();

        SpellEntry const* spellInfo = sSpellStore.LookupEntry(abs(trigger));
        if (!spellInfo)
        {
            sLog.outErrorDb("Spell %u listed in `spell_linked_spell` does not exist", abs(trigger));
            continue;
        }
        spellInfo = sSpellStore.LookupEntry(abs(effect));
        if (!spellInfo)
        {
            sLog.outErrorDb("Spell %u listed in `spell_linked_spell` does not exist", abs(effect));
            continue;
        }

        if(type) //we will find a better way when more types are needed
            trigger += 1000000;
        mSpellLinkedMap[trigger].push_back(effect);

        ++count;
    } while( result->NextRow() );

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u linked spells", count );
}

/// Some checks for spells, to prevent adding depricated/broken spells for trainers, spell book, etc
void SpellMgr::LoadPetLevelupSpellMap()
{
    CreatureFamilyEntry const *creatureFamily;
    SpellEntry const *spell;
    uint32 count = 0;

    for (uint32 i = 0; i < sCreatureFamilyStore.GetNumRows(); ++i)
    {
        creatureFamily = sCreatureFamilyStore.LookupEntry(i);

        if(!creatureFamily)                                 // not exist
            continue;

        if(creatureFamily->petTalentType < 0)               // not hunter pet family
            continue;

        for(uint32 j = 0; j < sSpellStore.GetNumRows(); ++j)
        {
            spell = sSpellStore.LookupEntry(j);

            // not exist
            if(!spell)
                continue;

            // not hunter spell
            if(spell->SpellFamilyName != SPELLFAMILY_HUNTER)
                continue;

            // not pet spell
            if(!(spell->SpellFamilyFlags & 0x1000000000000000LL))
                continue;

            // not Growl or Cower (generics)
            if(spell->SpellIconID != 201 && spell->SpellIconID != 958)
            {
                switch(creatureFamily->ID)
                {
                    case CREATURE_FAMILY_BAT:               // Bite and Sonic Blast
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 1577)
                            continue;
                        break;
                    case CREATURE_FAMILY_BEAR:              // Claw and Swipe
                        if(spell->SpellIconID != 262 && spell->SpellIconID != 1562)
                            continue;
                        break;
                    case CREATURE_FAMILY_BIRD_OF_PREY:      // Claw and Snatch
                        if(spell->SpellIconID != 262 && spell->SpellIconID != 168)
                            continue;
                        break;
                    case CREATURE_FAMILY_BOAR:              // Bite and Gore
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 1578)
                            continue;
                        break;
                    case CREATURE_FAMILY_CARRION_BIRD:      // Bite and Demoralizing Screech
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 1579)
                            continue;
                        break;
                    case CREATURE_FAMILY_CAT:               // Claw and Prowl and Rake
                        if(spell->SpellIconID != 262 && spell->SpellIconID != 495 && spell->SpellIconID != 494)
                            continue;
                        break;
                    case CREATURE_FAMILY_CHIMAERA:          // Bite and Froststorm Breath
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 62)
                            continue;
                        break;
                    case CREATURE_FAMILY_CORE_HOUND:        // Bite and Lava Breath
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 1197)
                            continue;
                        break;
                    case CREATURE_FAMILY_CRAB:              // Claw and Pin
                        if(spell->SpellIconID != 262 && spell->SpellIconID != 2679)
                            continue;
                        break;
                    case CREATURE_FAMILY_CROCOLISK:         // Bite and Bad Attitude
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 1581)
                            continue;
                        break;
                    case CREATURE_FAMILY_DEVILSAUR:         // Bite and Monstrous Bite
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 599)
                            continue;
                        break;
                    case CREATURE_FAMILY_DRAGONHAWK:        // Bite and Fire Breath
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 2128)
                            continue;
                        break;
                    case CREATURE_FAMILY_GORILLA:           // Smack and Thunderstomp
                        if(spell->SpellIconID != 473 && spell->SpellIconID != 148)
                            continue;
                        break;
                    case CREATURE_FAMILY_HYENA:             // Bite and Tendon Rip
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 138)
                            continue;
                        break;
                    case CREATURE_FAMILY_MOTH:              // Serenity Dust and Smack
                        if(spell->SpellIconID != 1714 && spell->SpellIconID != 473)
                            continue;
                        break;
                    case CREATURE_FAMILY_NETHER_RAY:        // Bite and Nether Shock
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 2027)
                            continue;
                        break;
                    case CREATURE_FAMILY_RAPTOR:            // Claw and Savage Rend
                        if(spell->SpellIconID != 262 && spell->SpellIconID != 245)
                            continue;
                        break;
                    case CREATURE_FAMILY_RAVAGER:           // Bite and Ravage
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 2253)
                            continue;
                        break;
                    case CREATURE_FAMILY_RHINO:             // Smack and Stampede
                        if(spell->SpellIconID != 473 && spell->SpellIconID != 3066)
                            continue;
                        break;
                    case CREATURE_FAMILY_SCORPID:           // Claw and Scorpid Poison
                        if(spell->SpellIconID != 262 && spell->SpellIconID != 163)
                            continue;
                        break;
                    case CREATURE_FAMILY_SERPENT:           // Bite and Poison Spit
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 68)
                            continue;
                        break;
                    case CREATURE_FAMILY_SILITHID:          // Claw and Venom Web Spray
                        if(spell->SpellIconID != 262 && (spell->SpellIconID != 272 && spell->SpellVisual[0] != 12013))
                            continue;
                        break;
                    case CREATURE_FAMILY_SPIDER:            // Bite and Web
                        if(spell->SpellIconID != 1680 && (spell->SpellIconID != 272 && spell->SpellVisual[0] != 684))
                            continue;
                        break;
                    case CREATURE_FAMILY_SPIRIT_BEAST:      // Claw and Prowl and Spirit Strike
                        if(spell->SpellIconID != 262 && spell->SpellIconID != 495 && spell->SpellIconID != 255)
                            continue;
                        break;
                    case CREATURE_FAMILY_SPOREBAT:          // Smack and Spore Cloud
                        if(spell->SpellIconID != 473 && spell->SpellIconID != 2681)
                            continue;
                        break;
                    case CREATURE_FAMILY_TALLSTRIDER:       // Claw and Dust Cloud
                        if(spell->SpellIconID != 262 && (spell->SpellIconID != 157 && !(spell->Attributes & 0x4000000)))
                            continue;
                        break;
                    case CREATURE_FAMILY_TURTLE:            // Bite and Shell Shield
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 1588)
                            continue;
                        break;
                    case CREATURE_FAMILY_WARP_STALKER:      // Bite and Warp
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 1952)
                            continue;
                         break;
                    case CREATURE_FAMILY_WASP:              // Smack and Sting
                        if(spell->SpellIconID != 473 && spell->SpellIconID != 110)
                            continue;
                        break;
                    case CREATURE_FAMILY_WIND_SERPENT:      // Bite and Lightning Breath
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 62)
                            continue;
                        break;
                    case CREATURE_FAMILY_WOLF:              // Bite and Furious Howl
                        if(spell->SpellIconID != 1680 && spell->SpellIconID != 1573)
                            continue;
                        break;
                    case CREATURE_FAMILY_WORM:              // Acid Spit and Bite
                        if(spell->SpellIconID != 636 && spell->SpellIconID != 1680)
                            continue;
                        break;
                    default:
                        sLog.outError("LoadPetLevelupSpellMap: Unhandled creature family %u", creatureFamily->ID);
                        continue;
                    }
            }

            mPetLevelupSpellMap[creatureFamily->ID][spell->spellLevel] = spell->Id;
            count++;
        }
    }

    sLog.outString();
    sLog.outString( ">> Loaded %u pet levelup spells", count );
}

/// Some checks for spells, to prevent adding deprecated/broken spells for trainers, spell book, etc
bool SpellMgr::IsSpellValid(SpellEntry const* spellInfo, Player* pl, bool msg)
{
    // not exist
    if(!spellInfo)
        return false;

    bool need_check_reagents = false;

    // check effects
    for(int i=0; i<3; ++i)
    {
        switch(spellInfo->Effect[i])
        {
            case 0:
                continue;

                // craft spell for crafting non-existed item (break client recipes list show)
            case SPELL_EFFECT_CREATE_ITEM:
            {
                if(!ObjectMgr::GetItemPrototype( spellInfo->EffectItemType[i] ))
                {
                    if(msg)
                    {
                        if(pl)
                            ChatHandler(pl).PSendSysMessage("Craft spell %u create not-exist in DB item (Entry: %u) and then...",spellInfo->Id,spellInfo->EffectItemType[i]);
                        else
                            sLog.outErrorDb("Craft spell %u create not-exist in DB item (Entry: %u) and then...",spellInfo->Id,spellInfo->EffectItemType[i]);
                    }
                    return false;
                }

                need_check_reagents = true;
                break;
            }
            case SPELL_EFFECT_LEARN_SPELL:
            {
                SpellEntry const* spellInfo2 = sSpellStore.LookupEntry(spellInfo->EffectTriggerSpell[i]);
                if( !IsSpellValid(spellInfo2,pl,msg) )
                {
                    if(msg)
                    {
                        if(pl)
                            ChatHandler(pl).PSendSysMessage("Spell %u learn to broken spell %u, and then...",spellInfo->Id,spellInfo->EffectTriggerSpell[i]);
                        else
                            sLog.outErrorDb("Spell %u learn to invalid spell %u, and then...",spellInfo->Id,spellInfo->EffectTriggerSpell[i]);
                    }
                    return false;
                }
                break;
            }
        }
    }

    if(need_check_reagents)
    {
        for(int j = 0; j < 8; ++j)
        {
            if(spellInfo->Reagent[j] > 0 && !ObjectMgr::GetItemPrototype( spellInfo->Reagent[j] ))
            {
                if(msg)
                {
                    if(pl)
                        ChatHandler(pl).PSendSysMessage("Craft spell %u have not-exist reagent in DB item (Entry: %u) and then...",spellInfo->Id,spellInfo->Reagent[j]);
                    else
                        sLog.outErrorDb("Craft spell %u have not-exist reagent in DB item (Entry: %u) and then...",spellInfo->Id,spellInfo->Reagent[j]);
                }
                return false;
            }
        }
    }

    return true;
}

uint8 GetSpellAllowedInLocationError(SpellEntry const *spellInfo,uint32 map_id,uint32 zone_id,uint32 area_id)
{
    // normal case
    if( spellInfo->AreaGroupId > 0)
    {
        bool found = false;

        AreaGroupEntry const* groupEntry = sAreaGroupStore.LookupEntry(spellInfo->AreaGroupId);
        if(groupEntry)
        {
            for (uint8 i=0; i<7; i++)
                if( groupEntry->AreaId[i] == zone_id || groupEntry->AreaId[i] == area_id )
                    found = true;
        }

        if(!found)
            return SPELL_FAILED_INCORRECT_AREA;
    }

    // elixirs (all area dependent elixirs have family SPELLFAMILY_POTION, use this for speedup)
    if(spellInfo->SpellFamilyName==SPELLFAMILY_POTION)
    {
        if(uint32 mask = spellmgr.GetSpellElixirMask(spellInfo->Id))
        {
            if(mask & ELIXIR_BATTLE_MASK)
            {
                if(spellInfo->Id==45373)                    // Bloodberry Elixir
                    return zone_id==4075 ? 0 : SPELL_FAILED_REQUIRES_AREA;
            }
            if(mask & ELIXIR_UNSTABLE_MASK)
            {
                // in the Blade's Edge Mountains Plateaus and Gruul's Lair.
                return zone_id ==3522 || map_id==565 ? 0 : SPELL_FAILED_INCORRECT_AREA;
            }
            if(mask & ELIXIR_SHATTRATH_MASK)
            {
                // in Tempest Keep, Serpentshrine Cavern, Caverns of Time: Mount Hyjal, Black Temple, Sunwell Plateau
                if(zone_id ==3607 || map_id==534 || map_id==564 || zone_id==4075)
                    return 0;

                MapEntry const* mapEntry = sMapStore.LookupEntry(map_id);
                if(!mapEntry)
                    return SPELL_FAILED_INCORRECT_AREA;

                return mapEntry->multimap_id==206 ? 0 : SPELL_FAILED_INCORRECT_AREA;
            }

            // elixirs not have another limitations
            return 0;
        }
    }

    // special cases zone check (maps checked by multimap common id)
    switch(spellInfo->Id)
    {
        case 41618:                                         // Bottled Nethergon Energy
        case 41620:                                         // Bottled Nethergon Vapor
        {
            MapEntry const* mapEntry = sMapStore.LookupEntry(map_id);
            if(!mapEntry)
                return SPELL_FAILED_INCORRECT_AREA;

            return mapEntry->multimap_id==206 ? 0 : SPELL_FAILED_REQUIRES_AREA;
        }
        case 41617:                                         // Cenarion Mana Salve
        case 41619:                                         // Cenarion Healing Salve
        {
            MapEntry const* mapEntry = sMapStore.LookupEntry(map_id);
            if(!mapEntry)
                return SPELL_FAILED_INCORRECT_AREA;

            return mapEntry->multimap_id==207 ? 0 : SPELL_FAILED_REQUIRES_AREA;
        }
        case 40216:                                         // Dragonmaw Illusion
        case 42016:                                         // Dragonmaw Illusion
            return area_id == 3759 || area_id == 3966 || area_id == 3939 ? 0 : SPELL_FAILED_INCORRECT_AREA;
        case 51721:                                         // Dominion Over Acherus
        case 54055:                                         // Dominion Over Acherus
            return area_id == 4281 || area_id == 4342 ? 0 : SPELL_FAILED_INCORRECT_AREA;
        case 54119:                                         // Mist of the Kvaldir
            return area_id == 4028 || area_id == 4029 || area_id == 4106 || area_id == 4031 ? 0 : SPELL_FAILED_INCORRECT_AREA;
    }

    return 0;
}

void SpellMgr::LoadSkillLineAbilityMap()
{
    mSkillLineAbilityMap.clear();

    barGoLink bar( sSkillLineAbilityStore.GetNumRows() );
    uint32 count = 0;

    for (uint32 i = 0; i < sSkillLineAbilityStore.GetNumRows(); i++)
    {
        bar.step();
        SkillLineAbilityEntry const *SkillInfo = sSkillLineAbilityStore.LookupEntry(i);
        if(!SkillInfo)
            continue;

        mSkillLineAbilityMap.insert(SkillLineAbilityMap::value_type(SkillInfo->spellId,SkillInfo));
        ++count;
    }

    sLog.outString();
    sLog.outString(">> Loaded %u SkillLineAbility MultiMap Data", count);
}

DiminishingGroup GetDiminishingReturnsGroupForSpell(SpellEntry const* spellproto, bool triggered)
{
    // Explicit Diminishing Groups
    switch(spellproto->SpellFamilyName)
    {
        case SPELLFAMILY_ROGUE:
        {
            // Kidney Shot
            if (spellproto->SpellFamilyFlags & 0x00000200000LL)
                return DIMINISHING_KIDNEYSHOT;
            // Sap
            else if (spellproto->SpellFamilyFlags & 0x00000000080LL)
                return DIMINISHING_POLYMORPH;
            // Gouge
            else if (spellproto->SpellFamilyFlags & 0x00000000008LL)
                return DIMINISHING_POLYMORPH;
            // Blind
            else if (spellproto->SpellFamilyFlags & 0x00001000000LL)
                return DIMINISHING_BLIND_CYCLONE;
            break;
        }
        case SPELLFAMILY_WARLOCK:
        {
            // Death Coil
            if (spellproto->SpellFamilyFlags & 0x00000080000LL)
                return DIMINISHING_DEATHCOIL;
            // Seduction
            if (spellproto->SpellFamilyFlags & 0x00040000000LL)
                return DIMINISHING_FEAR;
            // Fear
            //else if (spellproto->SpellFamilyFlags & 0x40840000000LL)
            //    return DIMINISHING_WARLOCK_FEAR;
            // Curses/etc
            else if (spellproto->SpellFamilyFlags & 0x00080000000LL)
                return DIMINISHING_LIMITONLY;
            break;
        }
        case SPELLFAMILY_DRUID:
        {
            // Cyclone
            if (spellproto->SpellFamilyFlags & 0x02000000000LL)
                return DIMINISHING_BLIND_CYCLONE;
            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            // Hamstring - limit duration to 10s in PvP
            if (spellproto->SpellFamilyFlags & 0x00000000002LL)
                return DIMINISHING_LIMITONLY;
            break;
        }
        default:
            break;
    }

    // Get by mechanic
    uint32 mechanic = GetAllSpellMechanicMask(spellproto);
    if (mechanic == MECHANIC_NONE)          return DIMINISHING_NONE;
    if (mechanic & (1<<MECHANIC_STUN))      return triggered ? DIMINISHING_TRIGGER_STUN : DIMINISHING_CONTROL_STUN;
    if (mechanic & (1<<MECHANIC_SLEEP))     return DIMINISHING_SLEEP;
    if (mechanic & (1<<MECHANIC_POLYMORPH)) return DIMINISHING_POLYMORPH;
    if (mechanic & (1<<MECHANIC_ROOT))      return triggered ? DIMINISHING_TRIGGER_ROOT : DIMINISHING_CONTROL_ROOT;
    if (mechanic & (1<<MECHANIC_FEAR))      return DIMINISHING_FEAR;
    if (mechanic & (1<<MECHANIC_CHARM))     return DIMINISHING_CHARM;
    if (mechanic & (1<<MECHANIC_SILENCE))   return DIMINISHING_SILENCE;
    if (mechanic & (1<<DIMINISHING_DISARM)) return DIMINISHING_DISARM;
    if (mechanic & (1<<MECHANIC_FREEZE))    return DIMINISHING_FREEZE;
    if (mechanic & ((1<<MECHANIC_KNOCKOUT) | (1<<MECHANIC_SAPPED)))    return DIMINISHING_KNOCKOUT;
    if (mechanic & (1<<MECHANIC_BANISH))    return DIMINISHING_BANISH;
    if (mechanic & (1<<MECHANIC_HORROR))    return DIMINISHING_DEATHCOIL;


    return DIMINISHING_NONE;
}

bool IsDiminishingReturnsGroupDurationLimited(DiminishingGroup group)
{
    switch(group)
    {
        case DIMINISHING_CONTROL_STUN:
        case DIMINISHING_TRIGGER_STUN:
        case DIMINISHING_KIDNEYSHOT:
        case DIMINISHING_SLEEP:
        case DIMINISHING_CONTROL_ROOT:
        case DIMINISHING_TRIGGER_ROOT:
        case DIMINISHING_FEAR:
        case DIMINISHING_WARLOCK_FEAR:
        case DIMINISHING_CHARM:
        case DIMINISHING_POLYMORPH:
        case DIMINISHING_FREEZE:
        case DIMINISHING_KNOCKOUT:
        case DIMINISHING_BLIND_CYCLONE:
        case DIMINISHING_BANISH:
        case DIMINISHING_LIMITONLY:
            return true;
    }
    return false;
}

DiminishingReturnsType GetDiminishingReturnsGroupType(DiminishingGroup group)
{
    switch(group)
    {
        case DIMINISHING_BLIND_CYCLONE:
        case DIMINISHING_CONTROL_STUN:
        case DIMINISHING_TRIGGER_STUN:
        case DIMINISHING_KIDNEYSHOT:
            return DRTYPE_ALL;
        case DIMINISHING_SLEEP:
        case DIMINISHING_CONTROL_ROOT:
        case DIMINISHING_TRIGGER_ROOT:
        case DIMINISHING_FEAR:
        case DIMINISHING_CHARM:
        case DIMINISHING_POLYMORPH:
        case DIMINISHING_SILENCE:
        case DIMINISHING_DISARM:
        case DIMINISHING_DEATHCOIL:
        case DIMINISHING_FREEZE:
        case DIMINISHING_BANISH:
        case DIMINISHING_WARLOCK_FEAR:
        case DIMINISHING_KNOCKOUT:
            return DRTYPE_PLAYER;
    }

    return DRTYPE_NONE;
}
