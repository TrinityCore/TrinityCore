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
#include "DBCStores.h"
#include "World.h"
#include "Chat.h"
#include "Spell.h"
#include "BattleGroundMgr.h"
#include "CreatureAI.h"

bool IsAreaEffectTarget[TOTAL_SPELL_TARGETS];

SpellMgr::SpellMgr()
{
    for(int i = 0; i < TOTAL_SPELL_EFFECTS; ++i)
    {
        switch(i)
        {
            case SPELL_EFFECT_PERSISTENT_AREA_AURA: //27
            case SPELL_EFFECT_SUMMON:               //28
            case SPELL_EFFECT_TRIGGER_MISSILE:      //32
            case SPELL_EFFECT_TRANS_DOOR:           //50 summon object
            case SPELL_EFFECT_SUMMON_PET:           //56
            case SPELL_EFFECT_ADD_FARSIGHT:         //72
            case SPELL_EFFECT_SUMMON_OBJECT_WILD:   //76
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
            //in 243 this is 0, in 309 it is 1
            //so both item target and unit target is pushed, and cause crash
            //case SPELL_EFFECT_FEED_PET:
            case SPELL_EFFECT_PROSPECTING:
            case SPELL_EFFECT_MILLING:
            case SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC:
                EffectTargetType[i] = SPELL_REQUIRE_ITEM;
                break;
            //caster must be pushed otherwise no sound
            case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
            case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND:
            case SPELL_EFFECT_APPLY_AREA_AURA_ENEMY:
            case SPELL_EFFECT_APPLY_AREA_AURA_PET:
            case SPELL_EFFECT_APPLY_AREA_AURA_OWNER:
            case SPELL_EFFECT_APPLY_AREA_AURA_RAID:
            case SPELL_EFFECT_CHARGE:
            case SPELL_EFFECT_JUMP:
            case SPELL_EFFECT_JUMP2:
            case SPELL_EFFECT_138:
                EffectTargetType[i] = SPELL_REQUIRE_CASTER;
                break;
            //case SPELL_EFFECT_WMO_DAMAGE:
            //case SPELL_EFFECT_WMO_REPAIR:
            //case SPELL_EFFECT_WMO_CHANGE:
            //    EffectTargetType[i] = SPELL_REQUIRE_GOBJECT;
            //    break;
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
            case TARGET_UNIT_RAID_CASTER:
            case TARGET_UNIT_VEHICLE:
            case TARGET_UNIT_PASSENGER:
                SpellTargetType[i] = TARGET_TYPE_UNIT_CASTER;
                break;
            case TARGET_UNIT_MINIPET:
            case TARGET_UNIT_TARGET_ALLY:
            case TARGET_UNIT_TARGET_RAID:
            case TARGET_UNIT_TARGET_ANY:
            case TARGET_UNIT_TARGET_ENEMY:
            case TARGET_UNIT_TARGET_PARTY:
            case TARGET_UNIT_PARTY_TARGET:
            case TARGET_UNIT_CLASS_TARGET:
            case TARGET_UNIT_CHAINHEAL:
                SpellTargetType[i] = TARGET_TYPE_UNIT_TARGET;
                break;
            case TARGET_UNIT_NEARBY_ENEMY:
            case TARGET_UNIT_NEARBY_ALLY:
            case TARGET_UNIT_NEARBY_ALLY_UNK:
            case TARGET_UNIT_NEARBY_ENTRY:
            case TARGET_UNIT_NEARBY_RAID:
                SpellTargetType[i] = TARGET_TYPE_UNIT_NEARBY;
                break;
            case TARGET_UNIT_AREA_ENEMY_SRC:
            case TARGET_UNIT_AREA_ALLY_SRC:
            case TARGET_UNIT_AREA_ENTRY_SRC:
            case TARGET_UNIT_AREA_PARTY_SRC:
            case TARGET_OBJECT_AREA_SRC:
                SpellTargetType[i] = TARGET_TYPE_AREA_SRC;
                break;
            case TARGET_UNIT_AREA_ENEMY_DST:
            case TARGET_UNIT_AREA_ALLY_DST:
            case TARGET_UNIT_AREA_ENTRY_DST:
            case TARGET_UNIT_AREA_PARTY_DST:
            case TARGET_OBJECT_AREA_DST:
                SpellTargetType[i] = TARGET_TYPE_AREA_DST;
                break;
            case TARGET_UNIT_CONE_ENEMY:
            case TARGET_UNIT_CONE_ALLY:
            case TARGET_UNIT_CONE_ENTRY:
            case TARGET_UNIT_CONE_ENEMY_UNKNOWN:
            case TARGET_UNIT_AREA_PATH:
                SpellTargetType[i] = TARGET_TYPE_AREA_CONE;
                break;
            case TARGET_DST_CASTER:
            case TARGET_SRC_CASTER:
            case TARGET_MINION:
            case TARGET_DEST_CASTER_FRONT_LEAP:
            case TARGET_DEST_CASTER_FRONT:
            case TARGET_DEST_CASTER_BACK:
            case TARGET_DEST_CASTER_RIGHT:
            case TARGET_DEST_CASTER_LEFT:
            case TARGET_DEST_CASTER_FRONT_LEFT:
            case TARGET_DEST_CASTER_BACK_LEFT:
            case TARGET_DEST_CASTER_BACK_RIGHT:
            case TARGET_DEST_CASTER_FRONT_RIGHT:
            case TARGET_DEST_CASTER_RANDOM:
            case TARGET_DEST_CASTER_RADIUS:
                SpellTargetType[i] = TARGET_TYPE_DEST_CASTER;
                break;
            case TARGET_DST_TARGET_ENEMY:
            case TARGET_DEST_TARGET_ANY:
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
            case TARGET_DEST_DYNOBJ_ENEMY:
            case TARGET_DEST_DYNOBJ_ALLY:
            case TARGET_DEST_DYNOBJ_NONE:
            case TARGET_DEST_DEST:
            case TARGET_DEST_TRAJ:
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
            case TARGET_DST_DB:
            case TARGET_DST_HOME:
            case TARGET_DST_NEARBY_ENTRY:
                SpellTargetType[i] = TARGET_TYPE_DEST_SPECIAL;
                break;
            case TARGET_UNIT_CHANNEL:
            case TARGET_DEST_CHANNEL:
                SpellTargetType[i] = TARGET_TYPE_CHANNEL;
                break;
            default:
                SpellTargetType[i] = TARGET_TYPE_DEFAULT;
        }
    }

    for(int i = 0; i < TOTAL_SPELL_TARGETS; ++i)
    {
        switch(i)
        {
            case TARGET_UNIT_AREA_ENEMY_DST:
            case TARGET_UNIT_AREA_ENEMY_SRC:
            case TARGET_UNIT_AREA_ALLY_DST:
            case TARGET_UNIT_AREA_ALLY_SRC:
            case TARGET_UNIT_AREA_ENTRY_DST:
            case TARGET_UNIT_AREA_ENTRY_SRC:
            case TARGET_UNIT_AREA_PARTY_DST:
            case TARGET_UNIT_AREA_PARTY_SRC:
            case TARGET_UNIT_PARTY_TARGET:
            case TARGET_UNIT_PARTY_CASTER:
            case TARGET_UNIT_CONE_ENEMY:
            case TARGET_UNIT_CONE_ALLY:
            case TARGET_UNIT_CONE_ENEMY_UNKNOWN:
            case TARGET_UNIT_AREA_PATH:
            case TARGET_UNIT_RAID_CASTER:
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

bool SpellMgr::IsSrcTargetSpell(SpellEntry const *spellInfo) const
{
    for (uint8 i = 0; i< MAX_SPELL_EFFECTS; ++i)
    {
        if(SpellTargetType[spellInfo->EffectImplicitTargetA[i]] == TARGET_TYPE_AREA_SRC || SpellTargetType[spellInfo->EffectImplicitTargetB[i]] == TARGET_TYPE_AREA_SRC)
            return true;
    }
    return false;
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

bool GetDispelChance(Unit* caster, uint32 spellId)
{
    // we assume that aura dispel chance is 100% on start
    // need formula for level difference based chance
    int32 miss_chance = 0;
    // Apply dispel mod from aura caster
    if (caster)
    {
        if ( Player* modOwner = caster->GetSpellModOwner() )
            modOwner->ApplySpellMod(spellId, SPELLMOD_RESIST_DISPEL_CHANCE, miss_chance);
    }
    // Try dispel
    return !roll_chance_i(miss_chance);
}

uint32 GetSpellCastTime(SpellEntry const* spellInfo, Spell * spell)
{
    SpellCastTimesEntry const *spellCastTimeEntry = sSpellCastTimesStore.LookupEntry(spellInfo->CastingTimeIndex);

    // not all spells have cast time index and this is all is pasiive abilities
    if(!spellCastTimeEntry)
        return 0;

    int32 castTime = spellCastTimeEntry->CastTime;

    if (spell && spell->GetCaster())
        spell->GetCaster()->ModSpellCastTime(spellInfo, castTime, spell);

    if (spellInfo->Attributes & SPELL_ATTR_REQ_AMMO && (!spell || !(spell->IsAutoRepeat())))
        castTime += 500;

    return (castTime > 0) ? uint32(castTime) : 0;
}

bool IsPassiveSpell(uint32 spellId)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);
    if (!spellInfo)
        return false;
    if(spellInfo->Attributes & SPELL_ATTR_PASSIVE)
        return true;
    if(spellInfo->activeIconID == 2158)  //flight
        return true;
    return false;
}

bool IsAutocastableSpell(uint32 spellId)
{
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(spellId);
    if(!spellInfo)
        return false;
    if(spellInfo->Attributes & SPELL_ATTR_PASSIVE)
        return false;
    if(spellInfo->activeIconID == 2158)
        return false;
    if(spellInfo->AttributesEx & SPELL_ATTR_EX_UNAUTOCASTABLE_BY_PET)
        return false;
    return true;
}

bool IsHigherHankOfSpell(uint32 spellId_1, uint32 spellId_2)
{
    return spellmgr.GetSpellRank(spellId_1)<spellmgr.GetSpellRank(spellId_2);
}

uint32 CalculatePowerCost(SpellEntry const * spellInfo, Unit const * caster, SpellSchoolMask schoolMask)
{
    // Spell drain all exist power on cast (Only paladin lay of Hands)
    if (spellInfo->AttributesEx & SPELL_ATTR_EX_DRAIN_ALL_POWER)
    {
        // If power type - health drain all
        if (spellInfo->powerType == POWER_HEALTH)
            return caster->GetHealth();
        // Else drain all power
        if (spellInfo->powerType < MAX_POWERS)
            return caster->GetPower(Powers(spellInfo->powerType));
        sLog.outError("CalculateManaCost: Unknown power type '%d' in spell %d", spellInfo->powerType, spellInfo->Id);
        return 0;
    }

    // Base powerCost
    int32 powerCost = spellInfo->manaCost;
    // PCT cost from total amount
    if (spellInfo->ManaCostPercentage)
    {
        switch (spellInfo->powerType)
        {
            // health as power used
            case POWER_HEALTH:
                powerCost += spellInfo->ManaCostPercentage * caster->GetCreateHealth() / 100;
                break;
            case POWER_MANA:
                powerCost += spellInfo->ManaCostPercentage * caster->GetCreateMana() / 100;
                break;
            case POWER_RAGE:
            case POWER_FOCUS:
            case POWER_ENERGY:
            case POWER_HAPPINESS:
                powerCost += spellInfo->ManaCostPercentage * caster->GetMaxPower(Powers(spellInfo->powerType)) / 100;
                break;
            case POWER_RUNE:
            case POWER_RUNIC_POWER:
                sLog.outDebug("CalculateManaCost: Not implemented yet!");
                break;
            default:
                sLog.outError("CalculateManaCost: Unknown power type '%d' in spell %d", spellInfo->powerType, spellInfo->Id);
                return 0;
        }
    }
    SpellSchools school = GetFirstSchoolInMask(schoolMask);
    // Flat mod from caster auras by spell school
    powerCost += caster->GetInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + school);
    // Shiv - costs 20 + weaponSpeed*10 energy (apply only to non-triggered spell with energy cost)
    if ( spellInfo->AttributesEx4 & SPELL_ATTR_EX4_SPELL_VS_EXTEND_COST )
        powerCost += caster->GetAttackTime(OFF_ATTACK)/100;
    // Apply cost mod by spell
    if(Player* modOwner = caster->GetSpellModOwner())
        modOwner->ApplySpellMod(spellInfo->Id, SPELLMOD_COST, powerCost);

    if(spellInfo->Attributes & SPELL_ATTR_LEVEL_DAMAGE_CALCULATION)
        powerCost = int32(powerCost/ (1.117f* spellInfo->spellLevel / caster->getLevel() -0.1327f));

    // PCT mod from user auras by school
    powerCost = int32(powerCost * (1.0f+caster->GetFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER+school)));
    if (powerCost < 0)
        powerCost = 0;
    return powerCost;
}

AuraState GetSpellAuraState(SpellEntry const * spellInfo)
{
    // Seals
    if (IsSealSpell(spellInfo))
        return (AURA_STATE_JUDGEMENT);

    // Conflagrate aura state on Immolate and Shadowflame
    if (spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK &&
        // Immolate
        ((spellInfo->SpellFamilyFlags[0] & 4) ||
        // Shadowflame
        (spellInfo->SpellFamilyFlags[2] & 2)))
        return (AURA_STATE_CONFLAGRATE);

    // Faerie Fire (druid versions)
    if (spellInfo->SpellFamilyName == SPELLFAMILY_DRUID && spellInfo->SpellFamilyFlags[0] & 0x400)
        return (AURA_STATE_FAERIE_FIRE);

    // Sting (hunter's pet ability)
    if (spellInfo->Category == 1133)
        return (AURA_STATE_FAERIE_FIRE);

    // Victorious
    if (spellInfo->SpellFamilyName == SPELLFAMILY_WARRIOR &&  spellInfo->SpellFamilyFlags[1] & 0x00040000)
        return (AURA_STATE_WARRIOR_VICTORY_RUSH);

    // Swiftmend state on Regrowth & Rejuvenation
    if (spellInfo->SpellFamilyName == SPELLFAMILY_DRUID && spellInfo->SpellFamilyFlags[0] & 0x50 )
        return (AURA_STATE_SWIFTMEND);

    // Deadly poison aura state
    if(spellInfo->SpellFamilyName == SPELLFAMILY_ROGUE && spellInfo->SpellFamilyFlags[0] & 0x10000)
        return (AURA_STATE_DEADLY_POISON);

    // Enrage aura state
    if(spellInfo->Dispel == DISPEL_ENRAGE)
        return (AURA_STATE_ENRAGE);

    // Bleeding aura state
    if (GetAllSpellMechanicMask(spellInfo) & 1<<MECHANIC_BLEED)
        return (AURA_STATE_BLEEDING);

    if(GetSpellSchoolMask(spellInfo) & SPELL_SCHOOL_MASK_FROST)
    {
        for (uint8 i = 0;i<MAX_SPELL_EFFECTS;++i)
        {
            if (spellInfo->EffectApplyAuraName[i]==SPELL_AURA_MOD_STUN
                || spellInfo->EffectApplyAuraName[i]==SPELL_AURA_MOD_ROOT)
            {
                return (AURA_STATE_FROZEN);
                break;
            }
        }
    }
    return AURA_STATE_NONE;
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
                    if( spellInfo->EffectApplyAuraName[i] == SPELL_AURA_MOD_POWER_REGEN
                        || spellInfo->EffectApplyAuraName[i] == SPELL_AURA_OBS_MOD_ENERGY)
                        return SPELL_DRINK;
                    else if ( spellInfo->EffectApplyAuraName[i] == SPELL_AURA_MOD_REGEN
                        || spellInfo->EffectApplyAuraName[i] == SPELL_AURA_OBS_MOD_HEALTH)
                        return SPELL_FOOD;
            }
            // this may be a hack
            else if((spellInfo->AttributesEx2 & SPELL_ATTR_EX2_FOOD)
                && !spellInfo->Category)
                return SPELL_WELL_FED;
            // scrolls effects
            else
            {
                uint32 firstSpell = spellmgr.GetFirstSpellInChain(spellInfo->Id);
                switch (firstSpell)
                {
                    case 8118: // Strength
                    case 8099: // Stamina
                    case 8112: // Spirit
                    case 8096: // Intellect
                    case 8115: // Agility
                    case 8091: // Armor
                        return SPELL_SCROLL;
                    case 12880: // Enrage (Enrage)
                    case 57518: // Enrage (Wrecking Crew)
                    case 12292: // Death Wish
                        return SPELL_WARRIOR_ENRAGE;
                }
            }
            break;
        }
        case SPELLFAMILY_MAGE:
        {
            // family flags 18(Molten), 25(Frost/Ice), 28(Mage)
            if (spellInfo->SpellFamilyFlags[0] & 0x12040000)
                return SPELL_MAGE_ARMOR;

            // Arcane brillance and Arcane intelect (normal check fails because of flags difference)
            if (spellInfo->SpellFamilyFlags[0] & 0x400)
                return SPELL_MAGE_ARCANE_BRILLANCE;

            if ((spellInfo->SpellFamilyFlags[0] & 0x1000000) && spellInfo->EffectApplyAuraName[0]==SPELL_AURA_MOD_CONFUSE)
                return SPELL_MAGE_POLYMORPH;

            break;
        }
        case SPELLFAMILY_PRIEST:
        {
            // Divine Spirit and Prayer of Spirit
            if (spellInfo->SpellFamilyFlags[0] & 0x20)
                return SPELL_PRIEST_DIVINE_SPIRIT;

            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            if (spellInfo->SpellFamilyFlags[1] & 0x000080 || spellInfo->SpellFamilyFlags[0] & 0x10000LL)
                return SPELL_POSITIVE_SHOUT;

            break;
        }
        case SPELLFAMILY_WARLOCK:
        {
            // only warlock curses have this
            if (spellInfo->Dispel == DISPEL_CURSE)
                return SPELL_CURSE;

            // Warlock (Demon Armor | Demon Skin | Fel Armor)
            if (spellInfo->SpellFamilyFlags[1] & 0x20000020 || spellInfo->SpellFamilyFlags[2] & 0x00000010)
                return SPELL_WARLOCK_ARMOR;

            //seed of corruption and corruption
            if (spellInfo->SpellFamilyFlags[1] & 0x10 || spellInfo->SpellFamilyFlags[0] & 0x2)
                return SPELL_WARLOCK_CORRUPTION;
            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            // only hunter stings have this
            if (spellInfo->Dispel == DISPEL_POISON)
                return SPELL_STING;

            // only hunter aspects have this (but not all aspects in hunter family)
            if( spellInfo->SpellFamilyFlags.HasFlag(0x00380000, 0x00440000, 0x00001010))
                return SPELL_ASPECT;

            break;
        }
        case SPELLFAMILY_PALADIN:
        {
            if (IsSealSpell(spellInfo))
                return SPELL_SEAL;

            if (spellInfo->SpellFamilyFlags[0] & 0x11010002)
                return SPELL_BLESSING;

            if (spellInfo->SpellFamilyFlags[0] & 0x00002190)
                return SPELL_HAND;

            // Judgement of Wisdom, Judgement of Light, Judgement of Justice
            if (spellInfo->Id == 20184 || spellInfo->Id == 20185 || spellInfo->Id == 20186)
                return SPELL_JUDGEMENT;

            // only paladin auras have this (for palaldin class family)
            if( spellInfo->SpellFamilyFlags[2] & 0x00000020 )
                return SPELL_AURA;

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
            if (spellInfo->Id == SPELL_ID_BLOOD_PRESENCE || spellInfo->Id == SPELL_ID_FROST_PRESENCE || spellInfo->Id == SPELL_ID_UNHOLY_PRESENCE)
            //if (spellInfo->Category == 47)
                return SPELL_PRESENCE;
            break;
    }

    for(int i = 0; i < 3; ++i)
    {
        if(spellInfo->Effect[i] == SPELL_EFFECT_APPLY_AURA)
        {
            switch(spellInfo->EffectApplyAuraName[i])
            {
                case SPELL_AURA_MOD_CHARM:
                case SPELL_AURA_MOD_POSSESS_PET:
                case SPELL_AURA_MOD_POSSESS:
                case SPELL_AURA_AOE_CHARM:
                    return SPELL_CHARM;
                case SPELL_AURA_TRACK_CREATURES:
                case SPELL_AURA_TRACK_RESOURCES:
                case SPELL_AURA_TRACK_STEALTHED:
                    return SPELL_TRACKER;
            }
        }
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
        case SPELL_HAND:
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
        case SPELL_CHARM:
        case SPELL_SCROLL:
        case SPELL_WARRIOR_ENRAGE:
        case SPELL_MAGE_ARCANE_BRILLANCE:
        case SPELL_PRIEST_DIVINE_SPIRIT:
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
        case TARGET_UNIT_TARGET_ENEMY:
        case TARGET_UNIT_AREA_ENEMY_SRC:
        case TARGET_UNIT_AREA_ENEMY_DST:
        case TARGET_UNIT_CONE_ENEMY:
        case TARGET_DEST_DYNOBJ_ENEMY:
        case TARGET_DST_TARGET_ENEMY:
        case TARGET_UNIT_CHANNEL:
            return false;
        default:
            break;
    }
    if (targetB)
        return IsPositiveTarget(targetB, 0);
    return true;
}

bool IsPositiveEffect(uint32 spellId, uint32 effIndex, bool deep)
{
    SpellEntry const *spellproto = sSpellStore.LookupEntry(spellId);
    if (!spellproto) return false;

    switch(spellId)
    {
        case  1852:                                         // Silenced (GM)
        case 46392:                                         // Focused Assault
        case 46393:                                         // Brutal Assault
        case 28441:                                         // not positive dummy spell
        case 37675:                                         // Chaos Blast
        case 41519:                                         // Mark of Stormrage
        case 34877:                                         // Custodian of Time
        case 34700:                                         // Allergic Reaction
        case 31719:                                         // Suspension
        case 61987:                                         // Avenging Wrath Marker
        case 11196:                                         // Recently Bandadged
        case 50524:                                         // Runic Power Feed
            return false;
        case 12042:                                         // Arcane Power
            return true;
    }

    switch(spellproto->Mechanic)
    {
        case MECHANIC_IMMUNE_SHIELD:
            return true;
        default:
            break;
    }

    // Special case: effects which determine positivity of whole spell
    for (uint8 i = 0;i<MAX_SPELL_EFFECTS;++i)
    {
        if (spellproto->EffectApplyAuraName[i] == SPELL_AURA_MOD_STEALTH)
            return true;
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
                        case 35679:                         // Protectorate Demolitionist
                        case 38637:                         // Nether Exhaustion (red)
                        case 38638:                         // Nether Exhaustion (green)
                        case 38639:                         // Nether Exhaustion (blue)
                        case 11196:                         // Recently Bandaged
                            return false;
                        // some spells have unclear target modes for selection, so just make effect positive
                        case 27184:                         
                        case 27190:
                        case 27191:
                        case 27201:
                        case 27202:
                        case 27203:
                            return true;
                        default:
                            break;
                    }
                }   break;
                case SPELL_AURA_MOD_STAT:
                case SPELL_AURA_MOD_DAMAGE_DONE:            // dependent from bas point sign (negative -> negative)
                case SPELL_AURA_MOD_HEALING_DONE:
                case SPELL_AURA_MOD_DAMAGE_PERCENT_DONE:
                    if(spellproto->CalculateSimpleValue(effIndex) < 0)
                        return false;
                    break;
                case SPELL_AURA_MOD_SPELL_CRIT_CHANCE:
                    if(spellproto->CalculateSimpleValue(effIndex) > 0)
                        return true;                        // some expected possitive spells have SPELL_ATTR_EX_NEGATIVE
                    break;
                case SPELL_AURA_ADD_TARGET_TRIGGER:
                    return true;
                case SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE:
                case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
                    if(!deep)
                    {
                        uint32 spellTriggeredId = spellproto->EffectTriggerSpell[effIndex];
                        SpellEntry const *spellTriggeredProto = sSpellStore.LookupEntry(spellTriggeredId);

                        if(spellTriggeredProto)
                        {
                            // non-positive targets of main spell return early
                            for(int i = 0; i < 3; ++i)
                            {
                                if (!spellTriggeredProto->Effect[i])
                                    continue;
                                // if non-positive trigger cast targeted to positive target this main cast is non-positive
                                // this will place this spell auras as debuffs
                                if(IsPositiveTarget(spellTriggeredProto->EffectImplicitTargetA[effIndex],spellTriggeredProto->EffectImplicitTargetB[effIndex]) && !IsPositiveEffect(spellTriggeredId,i, true))
                                    return false;
                            }
                        }
                    }
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
                    if(spellproto->EffectImplicitTargetA[effIndex] == TARGET_UNIT_CASTER)
                        return false;
                    break;
                case SPELL_AURA_MOD_DECREASE_SPEED:         // used in positive spells also
                    // part of positive spell if casted at self
                    if(spellproto->EffectImplicitTargetA[effIndex] != TARGET_UNIT_CASTER)
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
                            if(spellproto->CalculateSimpleValue(effIndex) > 0)
                            {
                                if (!deep)
                                {
                                    bool negative = true;
                                    for (uint8 i=0;i<MAX_SPELL_EFFECTS;++i)
                                    {
                                        if (i != effIndex)
                                            if (IsPositiveEffect(spellId, i, true))
                                            {
                                                negative = false;
                                                break;
                                            }
                                    }
                                    if (negative)
                                        return false;
                                }
                            }
                            break;
                        default:
                            break;
                    }
                }   break;
                case SPELL_AURA_MOD_HEALING_PCT:
                    if(spellproto->CalculateSimpleValue(effIndex) < 0)
                        return false;
                    break;
                case SPELL_AURA_MOD_SKILL:
                    if(spellproto->CalculateSimpleValue(effIndex) < 0)
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

    if (!deep && spellproto->EffectTriggerSpell[effIndex]
        && !spellproto->EffectApplyAuraName[effIndex]
        && IsPositiveTarget(spellproto->EffectImplicitTargetA[effIndex],spellproto->EffectImplicitTargetB[effIndex])
        && !IsPositiveSpell(spellproto->EffectTriggerSpell[effIndex], true))
        return false;

    // ok, positive
    return true;
}

bool IsPositiveSpell(uint32 spellId, bool deep)
{
    SpellEntry const *spellproto = sSpellStore.LookupEntry(spellId);
    if (!spellproto) return false;

    // spells with at least one negative effect are considered negative
    // some self-applied spells have negative effects but in self casting case negative check ignored.
    for (int i = 0; i < 3; ++i)
        if (!IsPositiveEffect(spellId, i, deep))
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
        default:
            break;
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
        case SPELL_MAGE_POLYMORPH:
            if(GetSpellSpecific(spellInfo2->Id) == spec1)
                return true;
            break;
        default:
            break;
    }

    return false;
}

SpellCastResult GetErrorAtShapeshiftedCast (SpellEntry const *spellInfo, uint32 form)
{
    // talents that learn spells can have stance requirements that need ignore
    // (this requirement only for client-side stance show in talent description)
    if( GetTalentSpellCost(spellInfo->Id) > 0 &&
        (spellInfo->Effect[0]==SPELL_EFFECT_LEARN_SPELL || spellInfo->Effect[1]==SPELL_EFFECT_LEARN_SPELL || spellInfo->Effect[2]==SPELL_EFFECT_LEARN_SPELL) )
        return SPELL_CAST_OK;

    uint32 stanceMask = (form ? 1 << (form - 1) : 0);

    if (stanceMask & spellInfo->StancesNot)                 // can explicitly not be casted in this stance
        return SPELL_FAILED_NOT_SHAPESHIFT;

    if (stanceMask & spellInfo->Stances)                    // can explicitly be casted in this stance
        return SPELL_CAST_OK;

    bool actAsShifted = false;
    SpellShapeshiftEntry const *shapeInfo = NULL;
    if (form > 0)
    {
        shapeInfo = sSpellShapeshiftStore.LookupEntry(form);
        if (!shapeInfo)
        {
            sLog.outError("GetErrorAtShapeshiftedCast: unknown shapeshift %u", form);
            return SPELL_CAST_OK;
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

    // Check if stance disables cast of not-stance spells
    // Example: cannot cast any other spells in zombie or ghoul form
    // TODO: Find a way to disable use of these spells clientside
    if (shapeInfo && shapeInfo->flags1 & 0x400)
    {
        if(!(stanceMask & spellInfo->Stances))
            return SPELL_FAILED_ONLY_SHAPESHIFT;
    }

    return SPELL_CAST_OK;
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
            if( spellInfo->EffectImplicitTargetA[i]==TARGET_DST_DB || spellInfo->EffectImplicitTargetB[i]==TARGET_DST_DB )
            {
                found = true;
                break;
            }
        }
        if(!found)
        {
            sLog.outErrorDb("Spell (Id: %u) listed in `spell_target_position` does not have target TARGET_DST_DB (17).",Spell_ID);
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

    // Check all spells
    for(uint32 i = 1; i < sSpellStore.GetNumRows(); ++i)
    {
        SpellEntry const * spellInfo = sSpellStore.LookupEntry(i);
        if(!spellInfo)
            continue;

        bool found = false;
        for(int j = 0; j < 3; ++j)
        {
            switch(spellInfo->EffectImplicitTargetA[j])
            {
                case TARGET_DST_DB:
                    found = true;
                    break;
            }
            if(found)
                break;
            switch(spellInfo->EffectImplicitTargetB[j])
            {
                case TARGET_DST_DB:
                    found = true;
                    break;
            }
            if(found)
                break;
        }
        if(found)
        {
            SpellScriptTarget::const_iterator lower = spellmgr.GetBeginSpellScriptTarget(i);
            SpellScriptTarget::const_iterator upper = spellmgr.GetEndSpellScriptTarget(i);
            if(lower == upper)
                sLog.outDetail("Spell (ID: %u) does not have record in `spell_target_position`", i);
        }
    }

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u spell teleport coordinates", count );
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
    if (mod->mask  & spellInfo->SpellFamilyFlags)
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

        uint32 entry = fields[0].GetUInt32();

        const SpellEntry *spell = sSpellStore.LookupEntry(entry);
        if (!spell)
        {
            sLog.outErrorDb("Spell %u listed in `spell_proc_event` does not exist", entry);
            continue;
        }

        SpellProcEventEntry spe;

        spe.schoolMask      = fields[1].GetUInt32();
        spe.spellFamilyName = fields[2].GetUInt32();
        spe.spellFamilyMask[0] = fields[3].GetUInt32();
        spe.spellFamilyMask[1] = fields[4].GetUInt32();
        spe.spellFamilyMask[2] = fields[5].GetUInt32();
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

void SpellMgr::LoadSpellBonusess()
{
    mSpellBonusMap.clear();                             // need for reload case
    uint32 count = 0;
    //                                                0      1             2          3         4
    QueryResult *result = WorldDatabase.Query("SELECT entry, direct_bonus, dot_bonus, ap_bonus, ap_dot_bonus FROM spell_bonus_data");
    if( !result )
    {
        barGoLink bar( 1 );
        bar.step();
        sLog.outString();
        sLog.outString( ">> Loaded %u spell bonus data", count);
        return;
    }

    barGoLink bar( result->GetRowCount() );
    do
    {
        Field *fields = result->Fetch();
        bar.step();
        uint32 entry = fields[0].GetUInt32();

        const SpellEntry *spell = sSpellStore.LookupEntry(entry);
        if (!spell)
        {
            sLog.outErrorDb("Spell %u listed in `spell_bonus_data` does not exist", entry);
            continue;
        }

        SpellBonusEntry sbe;

        sbe.direct_damage = fields[1].GetFloat();
        sbe.dot_damage    = fields[2].GetFloat();
        sbe.ap_bonus      = fields[3].GetFloat();
        sbe.ap_dot_bonus   = fields[4].GetFloat();

        mSpellBonusMap[entry] = sbe;
        ++count;
    } while( result->NextRow() );

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u extra spell bonus data",  count);
}

bool SpellMgr::IsSpellProcEventCanTriggeredBy(SpellProcEventEntry const* spellProcEvent, uint32 EventProcFlag, SpellEntry const * procSpell, uint32 procFlags, uint32 procExtra, bool active)
{
    // No extra req need
    uint32 procEvent_procEx = PROC_EX_NONE;

    // check prockFlags for condition
    if((procFlags & EventProcFlag) == 0)
        return false;

    bool hasFamilyMask = false;

    /* Check Periodic Auras

    *Dots can trigger if spell has no PROC_FLAG_SUCCESSFUL_NEGATIVE_MAGIC_SPELL
        nor PROC_FLAG_TAKEN_POSITIVE_MAGIC_SPELL

    *Only Hots can trigger if spell has PROC_FLAG_TAKEN_POSITIVE_MAGIC_SPELL

    *Only dots can trigger if spell has both positivity flags or PROC_FLAG_SUCCESSFUL_NEGATIVE_MAGIC_SPELL

    *Aura has to have PROC_FLAG_TAKEN_POSITIVE_MAGIC_SPELL or spellfamily specified to trigger from Hot

    */

    if (procFlags & PROC_FLAG_ON_DO_PERIODIC)
    {
        if (EventProcFlag & PROC_FLAG_SUCCESSFUL_NEGATIVE_MAGIC_SPELL)
        {
            if (!(procExtra & PROC_EX_INTERNAL_DOT))
                return false;
        }
        else if (EventProcFlag & PROC_FLAG_TAKEN_POSITIVE_MAGIC_SPELL
            && !(procExtra & PROC_EX_INTERNAL_HOT))
            return false;
        else if (procExtra & PROC_EX_INTERNAL_HOT)
            procExtra |= PROC_EX_INTERNAL_REQ_FAMILY;
    }

    if (procFlags & PROC_FLAG_ON_TAKE_PERIODIC)
    {
        if (EventProcFlag & PROC_FLAG_TAKEN_NEGATIVE_MAGIC_SPELL)
        {
            if (!(procExtra & PROC_EX_INTERNAL_DOT))
                return false;
        }
        else if (EventProcFlag & PROC_FLAG_TAKEN_POSITIVE_MAGIC_SPELL
            && !(procExtra & PROC_EX_INTERNAL_HOT))
            return false;
        else if (procExtra & PROC_EX_INTERNAL_HOT)
            procExtra |= PROC_EX_INTERNAL_REQ_FAMILY;
    }
    // Trap casts are active by default
    if (procFlags & PROC_FLAG_ON_TRAP_ACTIVATION)
        active = true;

    // Always trigger for this
    if (procFlags & (PROC_FLAG_KILLED | PROC_FLAG_KILL | PROC_FLAG_DEATH))
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
            if(spellProcEvent->spellFamilyMask)
            {
                if ((spellProcEvent->spellFamilyMask & procSpell->SpellFamilyFlags ) == 0)
                    return false;
                hasFamilyMask = true;
                // Some spells are not considered as active even with have spellfamilyflags
                if (!(procEvent_procEx & PROC_EX_ONLY_ACTIVE_SPELL))
                    active = true;
            }
        }
    }

    if (procExtra & (PROC_EX_INTERNAL_REQ_FAMILY))
    {
        if (!hasFamilyMask)
            return false;
    }

    // Check for extra req (if none) and hit/crit
    if (procEvent_procEx == PROC_EX_NONE)
    {
        // No extra req, so can trigger only for hit/crit - spell has to be active
        if((procExtra & (PROC_EX_NORMAL_HIT|PROC_EX_CRITICAL_HIT)) && active)
            return true;
    }
    else // Passive spells hits here only if resist/reflect/immune/evade
    {
        if (procExtra & AURA_SPELL_PROC_EX_MASK)
        {
            // if spell marked as procing only from not active spells
            if (active && procEvent_procEx & PROC_EX_NOT_ACTIVE_SPELL)
                return false;
            // if spell marked as procing only from active spells
            if (!active && procEvent_procEx & PROC_EX_ONLY_ACTIVE_SPELL)
                return false;
            // Exist req for PROC_EX_EX_TRIGGER_ALWAYS
            if (procEvent_procEx & PROC_EX_EX_TRIGGER_ALWAYS)
                return true;
            // PROC_EX_NOT_ACTIVE_SPELL and PROC_EX_ONLY_ACTIVE_SPELL flags handle: if passed checks before
            if ((procExtra & (PROC_EX_NORMAL_HIT|PROC_EX_CRITICAL_HIT)) && ((procEvent_procEx & (AURA_SPELL_PROC_EX_MASK | AURA_REMOVE_PROC_EX_MASK)) == 0))
                return true;
        }
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

        uint32 entry = fields[0].GetUInt32();
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
    mSpellThreatMap.clear();                                // need for reload case

    uint32 count = 0;

    //                                                0      1
    QueryResult *result = WorldDatabase.Query("SELECT entry, Threat FROM spell_threat");
    if( !result )
    {

        barGoLink bar( 1 );

        bar.step();

        sLog.outString();
        sLog.outString( ">> Loaded %u aggro generating spells", count );
        return;
    }

    barGoLink bar( result->GetRowCount() );

    do
    {
        Field *fields = result->Fetch();

        bar.step();

        uint32 entry = fields[0].GetUInt32();
        uint16 Threat = fields[1].GetUInt16();

        if (!sSpellStore.LookupEntry(entry))
        {
            sLog.outErrorDb("Spell %u listed in `spell_threat` does not exist", entry);
            continue;
        }

        mSpellThreatMap[entry] = Threat;

        ++count;
    } while( result->NextRow() );

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u aggro generating spells", count );
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
    for (int i = 0; i < 3; ++i)
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
    for(int i=0;i<3;++i)
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
                    dbc_node.value = 1;
                else
                    dbc_node.value = entry->CalculateSimpleValue(i)*75;
                dbc_node.maxvalue = entry->CalculateSimpleValue(i)*75;

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
            sLog.outErrorDb("Spell %u listed in `spell_learn_spell` learning not existed spell %u",spell_id,node.spell);
            continue;
        }

        if(GetTalentSpellCost(node.spell))
        {
            sLog.outErrorDb("Spell %u listed in `spell_learn_spell` attempt learning talent spell %u, skipped",spell_id,node.spell);
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
                dbc_node.autoLearned = entry->EffectImplicitTargetA[i] == TARGET_UNIT_PET || GetTalentSpellCost(spell) > 0 || IsPassiveSpell(spell) || IsSpellHaveEffect(entry,SPELL_EFFECT_SKILL_STEP);

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
        sLog.outErrorDb(">> Loaded 0 SpellScriptTarget. DB table `spell_script_target` is empty.");
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
            if( spellProto->EffectImplicitTargetA[i]==TARGET_UNIT_NEARBY_ENTRY ||
                spellProto->EffectImplicitTargetB[i]==TARGET_UNIT_NEARBY_ENTRY ||
                spellProto->EffectImplicitTargetA[i]==TARGET_DST_NEARBY_ENTRY ||
                spellProto->EffectImplicitTargetB[i]==TARGET_DST_NEARBY_ENTRY )
            {
                targetfound = true;
                break;
            }
        }
        if(!targetfound)
        {
            sLog.outErrorDb("Table `spell_script_target`: spellId %u listed for TargetEntry %u does not have any implicit target TARGET_UNIT_NEARBY_ENTRY(38) or TARGET_DST_NEARBY_ENTRY (46).",spellId,targetEntry);
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
            case SPELL_TARGET_TYPE_CONTROLLED:
                if( targetEntry==0 )
                    sLog.outErrorDb("Table `spell_script_target`: creature template entry %u does not exist.",targetEntry);
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
    for(uint32 i = 1; i < sSpellStore.GetNumRows(); ++i)
    {
        SpellEntry const * spellInfo = sSpellStore.LookupEntry(i);
        if(!spellInfo)
            continue;

        bool found = false;
        for(int j = 0; j < 3; ++j)
        {
            switch(spellInfo->EffectImplicitTargetA[j])
            {
                case TARGET_UNIT_AREA_ENTRY_SRC:
                case TARGET_UNIT_AREA_ENTRY_DST:
                case TARGET_UNIT_NEARBY_ENTRY:
                case TARGET_DST_NEARBY_ENTRY:
                case TARGET_UNIT_CONE_ENTRY:
                    found = true;
                    break;
            }
            if(found)
                break;
            switch(spellInfo->EffectImplicitTargetB[j])
            {
                case TARGET_UNIT_AREA_ENTRY_SRC:
                case TARGET_UNIT_AREA_ENTRY_DST:
                case TARGET_UNIT_NEARBY_ENTRY:
                case TARGET_DST_NEARBY_ENTRY:
                case TARGET_UNIT_CONE_ENTRY:
                    found = true;
                    break;
            }
            if(found)
                break;
        }
        if(found)
        {
            SpellScriptTarget::const_iterator lower = spellmgr.GetBeginSpellScriptTarget(i);
            SpellScriptTarget::const_iterator upper = spellmgr.GetEndSpellScriptTarget(i);
            if(lower == upper)
                sLog.outDetail("Spell (ID: %u) does not have record in `spell_script_target`", i);
        }
    }

    sLog.outString();
    sLog.outString(">> Loaded %u Spell Script Targets", count);
}

void SpellMgr::LoadSpellPetAuras()
{
    mSpellPetAuraMap.clear();                                  // need for reload case

    uint32 count = 0;

    //                                                0      1         2    3
    QueryResult *result = WorldDatabase.Query("SELECT spell, effectId, pet, aura FROM spell_pet_auras");
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

        uint32 spell = fields[0].GetUInt32();
        uint8 eff = fields[1].GetUInt8();
        uint32 pet = fields[2].GetUInt32();
        uint32 aura = fields[3].GetUInt32();

        SpellPetAuraMap::iterator itr = mSpellPetAuraMap.find((spell<<8) + eff);
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
            if (spellInfo->Effect[eff] != SPELL_EFFECT_DUMMY &&
               (spellInfo->Effect[eff] != SPELL_EFFECT_APPLY_AURA ||
                spellInfo->EffectApplyAuraName[eff] != SPELL_AURA_DUMMY))
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

            PetAura pa(pet, aura, spellInfo->EffectImplicitTargetA[eff] == TARGET_UNIT_PET, spellInfo->CalculateSimpleValue(eff));
            mSpellPetAuraMap[(spell<<8) + eff] = pa;
        }

        ++count;
    } while( result->NextRow() );

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u spell pet auras", count );
}

void SpellMgr::LoadPetLevelupSpellMap()
{
    mPetLevelupSpellMap.clear();                                   // need for reload case

    uint32 count = 0;
    uint32 family_count = 0;

    for (uint32 i = 0; i < sCreatureFamilyStore.GetNumRows(); ++i)
    {
        CreatureFamilyEntry const *creatureFamily = sCreatureFamilyStore.LookupEntry(i);
        if(!creatureFamily)                                 // not exist
            continue;

        for (uint8 j = 0; j < 2; ++j)
        {
            if (!creatureFamily->skillLine[j])
                continue;

            for (uint32 k = 0; k < sSkillLineAbilityStore.GetNumRows(); ++k)
            {
                SkillLineAbilityEntry const *skillLine = sSkillLineAbilityStore.LookupEntry(k);
                if( !skillLine )
                    continue;

                //if (skillLine->skillId!=creatureFamily->skillLine[0] &&
                //    (!creatureFamily->skillLine[1] || skillLine->skillId!=creatureFamily->skillLine[1]))
                //    continue;

                if (skillLine->skillId!=creatureFamily->skillLine[j])
                    continue;

                if(skillLine->learnOnGetSkill != ABILITY_LEARNED_ON_GET_RACE_OR_CLASS_SKILL)
                    continue;

                SpellEntry const *spell = sSpellStore.LookupEntry(skillLine->spellId);
                if(!spell) // not exist or triggered or talent
                    continue;

                if(!spell->spellLevel)
                    continue;

            PetLevelupSpellSet& spellSet = mPetLevelupSpellMap[creatureFamily->ID];
            if(spellSet.empty())
                ++family_count;

            spellSet.insert(PetLevelupSpellSet::value_type(spell->spellLevel,spell->Id)); 
                count++;
            }
        }
    }

    sLog.outString();
    sLog.outString( ">> Loaded %u pet levelup and default spells for %u families", count, family_count );
}

bool LoadPetDefaultSpells_helper(CreatureInfo const* cInfo, PetDefaultSpellsEntry& petDefSpells)
{
    // skip empty list;
    bool have_spell = false;
    for(int j = 0; j < MAX_CREATURE_SPELL_DATA_SLOT; ++j)
    {
        if(petDefSpells.spellid[j])
        {
            have_spell = true;
            break;
        }
    }
    if(!have_spell)
        return false;

    // remove duplicates with levelupSpells if any
    if(PetLevelupSpellSet const *levelupSpells = cInfo->family ? spellmgr.GetPetLevelupSpellList(cInfo->family) : NULL)
    {
        for(int j = 0; j < MAX_CREATURE_SPELL_DATA_SLOT; ++j)
        {
            if(!petDefSpells.spellid[j])
                continue;

            for(PetLevelupSpellSet::const_iterator itr = levelupSpells->begin(); itr != levelupSpells->end(); ++itr)
            {
                if (itr->second == petDefSpells.spellid[j])
                {
                    petDefSpells.spellid[j] = 0;
                    break;
                }
            }
        }
    }

    // skip empty list;
    have_spell = false;
    for(int j = 0; j < MAX_CREATURE_SPELL_DATA_SLOT; ++j)
    {
        if(petDefSpells.spellid[j])
        {
            have_spell = true;
            break;
        }
    }

    return have_spell;
}

void SpellMgr::LoadPetDefaultSpells()
{
    mPetDefaultSpellsMap.clear();

    uint32 countCreature = 0;
    uint32 countData = 0;

    for(uint32 i = 0; i < sCreatureStorage.MaxEntry; ++i )
    {
        CreatureInfo const* cInfo = sCreatureStorage.LookupEntry<CreatureInfo>(i);
        if(!cInfo)
            continue;

        if(!cInfo->PetSpellDataId)
            continue;

        // for creature with PetSpellDataId get default pet spells from dbc
        CreatureSpellDataEntry const* spellDataEntry = sCreatureSpellDataStore.LookupEntry(cInfo->PetSpellDataId);
        if(!spellDataEntry)
            continue;

        int32 petSpellsId = -(int32)cInfo->PetSpellDataId;
        PetDefaultSpellsEntry petDefSpells;
        for(int j = 0; j < MAX_CREATURE_SPELL_DATA_SLOT; ++j)
            petDefSpells.spellid[j] = spellDataEntry->spellId[j];

        if(LoadPetDefaultSpells_helper(cInfo, petDefSpells))
        {
            mPetDefaultSpellsMap[petSpellsId] = petDefSpells;
            ++countData;
        }
    }

    // different summon spells
    for(uint32 i = 0; i < sSpellStore.GetNumRows(); ++i )
    {
        SpellEntry const* spellEntry = sSpellStore.LookupEntry(i);
        if(!spellEntry)
            continue;

        for(int k = 0; k < 3; ++k)
        {
            if(spellEntry->Effect[k]==SPELL_EFFECT_SUMMON || spellEntry->Effect[k]==SPELL_EFFECT_SUMMON_PET)
            {
                uint32 creature_id = spellEntry->EffectMiscValue[k];
                CreatureInfo const* cInfo = sCreatureStorage.LookupEntry<CreatureInfo>(creature_id);
                if(!cInfo)
                    continue;

                // already loaded
                if(cInfo->PetSpellDataId)
                    continue;

                // for creature without PetSpellDataId get default pet spells from creature_template
                int32 petSpellsId = cInfo->Entry;
                if(mPetDefaultSpellsMap.find(cInfo->Entry) != mPetDefaultSpellsMap.end())
                    continue;

                PetDefaultSpellsEntry petDefSpells;
                for(int j = 0; j < MAX_CREATURE_SPELL_DATA_SLOT; ++j)
                    petDefSpells.spellid[j] = cInfo->spells[j];

                if(LoadPetDefaultSpells_helper(cInfo, petDefSpells))
                {
                    mPetDefaultSpellsMap[petSpellsId] = petDefSpells;
                    ++countCreature;
                }
            }
        }
    }

    sLog.outString();
    sLog.outString( ">> Loaded addition spells for %u pet spell data entries and %u summonable creature templates", countData, countCreature );
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
            case SPELL_EFFECT_CREATE_ITEM_2:
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

void SpellMgr::LoadSpellAreas()
{
    mSpellAreaMap.clear();                                  // need for reload case
    mSpellAreaForQuestMap.clear();
    mSpellAreaForActiveQuestMap.clear();
    mSpellAreaForQuestEndMap.clear();
    mSpellAreaForAuraMap.clear();

    uint32 count = 0;

    //                                                0      1     2            3                   4          5           6         7       8
    QueryResult *result = WorldDatabase.Query("SELECT spell, area, quest_start, quest_start_active, quest_end, aura_spell, racemask, gender, autocast FROM spell_area");

    if( !result )
    {
        barGoLink bar( 1 );

        bar.step();

        sLog.outString();
        sLog.outString( ">> Loaded %u spell area requirements", count );
        return;
    }

    barGoLink bar( result->GetRowCount() );

    do
    {
        Field *fields = result->Fetch();

        bar.step();

        uint32 spell = fields[0].GetUInt32();
        SpellArea spellArea;
        spellArea.spellId             = spell;
        spellArea.areaId              = fields[1].GetUInt32();
        spellArea.questStart          = fields[2].GetUInt32();
        spellArea.questStartCanActive = fields[3].GetBool();
        spellArea.questEnd            = fields[4].GetUInt32();
        spellArea.auraSpell           = fields[5].GetInt32();
        spellArea.raceMask            = fields[6].GetUInt32();
        spellArea.gender              = Gender(fields[7].GetUInt8());
        spellArea.autocast            = fields[8].GetBool();

        if(const SpellEntry* spellInfo = sSpellStore.LookupEntry(spell))
        {
            if(spellArea.autocast)
                const_cast<SpellEntry*>(spellInfo)->Attributes |= SPELL_ATTR_CANT_CANCEL;
        }
        else
        {
            sLog.outErrorDb("Spell %u listed in `spell_area` does not exist", spell);
            continue;
        }

        {
            bool ok = true;
            SpellAreaMapBounds sa_bounds = GetSpellAreaMapBounds(spellArea.spellId);
            for(SpellAreaMap::const_iterator itr = sa_bounds.first; itr != sa_bounds.second; ++itr)
            {
                if(spellArea.spellId && itr->second.spellId && spellArea.spellId != itr->second.spellId)
                    continue;
                if(spellArea.areaId && itr->second.areaId && spellArea.areaId!= itr->second.areaId)
                    continue;
                if(spellArea.questStart && itr->second.questStart && spellArea.questStart!= itr->second.questStart)
                    continue;
                if(spellArea.auraSpell && itr->second.auraSpell && spellArea.auraSpell!= itr->second.auraSpell)
                    continue;
                if(spellArea.raceMask && itr->second.raceMask && (spellArea.raceMask & itr->second.raceMask)==0)
                    continue;
                if(spellArea.gender != GENDER_NONE && itr->second.gender != GENDER_NONE && spellArea.gender!= itr->second.gender)
                    continue;

                // duplicate by requirements
                ok =false;
                break;
            }

            if(!ok)
            {
                sLog.outErrorDb("Spell %u listed in `spell_area` already listed with similar requirements.", spell);
                continue;
            }

        }

        if(spellArea.areaId && !GetAreaEntryByAreaID(spellArea.areaId))
        {
            sLog.outErrorDb("Spell %u listed in `spell_area` have wrong area (%u) requirement", spell,spellArea.areaId);
            continue;
        }

        if(spellArea.questStart && !objmgr.GetQuestTemplate(spellArea.questStart))
        {
            sLog.outErrorDb("Spell %u listed in `spell_area` have wrong start quest (%u) requirement", spell,spellArea.questStart);
            continue;
        }

        if(spellArea.questEnd)
        {
            if(!objmgr.GetQuestTemplate(spellArea.questEnd))
            {
                sLog.outErrorDb("Spell %u listed in `spell_area` have wrong end quest (%u) requirement", spell,spellArea.questEnd);
                continue;
            }

            if(spellArea.questEnd==spellArea.questStart && !spellArea.questStartCanActive)
            {
                sLog.outErrorDb("Spell %u listed in `spell_area` have quest (%u) requirement for start and end in same time", spell,spellArea.questEnd);
                continue;
            }
        }

        if(spellArea.auraSpell)
        {
            SpellEntry const* spellInfo = sSpellStore.LookupEntry(abs(spellArea.auraSpell));
            if(!spellInfo)
            {
                sLog.outErrorDb("Spell %u listed in `spell_area` have wrong aura spell (%u) requirement", spell,abs(spellArea.auraSpell));
                continue;
            }

            if(spellInfo->EffectApplyAuraName[0]!=SPELL_AURA_DUMMY && spellInfo->EffectApplyAuraName[0]!=SPELL_AURA_PHASE)
            {
                sLog.outErrorDb("Spell %u listed in `spell_area` have aura spell requirement (%u) without dummy/phase aura in effect 0", spell,abs(spellArea.auraSpell));
                continue;
            }

            if(abs(spellArea.auraSpell)==spellArea.spellId)
            {
                sLog.outErrorDb("Spell %u listed in `spell_area` have aura spell (%u) requirement for itself", spell,abs(spellArea.auraSpell));
                continue;
            }

            // not allow autocast chains by auraSpell field (but allow use as alternative if not present)
            if(spellArea.autocast && spellArea.auraSpell > 0)
            {
                bool chain = false;
                SpellAreaForAuraMapBounds saBound = GetSpellAreaForAuraMapBounds(spellArea.spellId);
                for(SpellAreaForAuraMap::const_iterator itr = saBound.first; itr != saBound.second; ++itr)
                {
                    if(itr->second->autocast && itr->second->auraSpell > 0)
                    {
                        chain = true;
                        break;
                    }
                }

                if(chain)
                {
                    sLog.outErrorDb("Spell %u listed in `spell_area` have aura spell (%u) requirement that itself autocast from aura", spell,spellArea.auraSpell);
                    continue;
                }

                SpellAreaMapBounds saBound2 = GetSpellAreaMapBounds(spellArea.auraSpell);
                for(SpellAreaMap::const_iterator itr2 = saBound2.first; itr2 != saBound2.second; ++itr2)
                {
                    if(itr2->second.autocast && itr2->second.auraSpell > 0)
                    {
                        chain = true;
                        break;
                    }
                }

                if(chain)
                {
                    sLog.outErrorDb("Spell %u listed in `spell_area` have aura spell (%u) requirement that itself autocast from aura", spell,spellArea.auraSpell);
                    continue;
                }
            }
        }

        if(spellArea.raceMask && (spellArea.raceMask & RACEMASK_ALL_PLAYABLE)==0)
        {
            sLog.outErrorDb("Spell %u listed in `spell_area` have wrong race mask (%u) requirement", spell,spellArea.raceMask);
            continue;
        }

        if(spellArea.gender!=GENDER_NONE && spellArea.gender!=GENDER_FEMALE && spellArea.gender!=GENDER_MALE)
        {
            sLog.outErrorDb("Spell %u listed in `spell_area` have wrong gender (%u) requirement", spell,spellArea.gender);
            continue;
        }

        SpellArea const* sa = &mSpellAreaMap.insert(SpellAreaMap::value_type(spell,spellArea))->second;

        // for search by current zone/subzone at zone/subzone change
        if(spellArea.areaId)
            mSpellAreaForAreaMap.insert(SpellAreaForAreaMap::value_type(spellArea.areaId,sa));

        // for search at quest start/reward
        if(spellArea.questStart)
        {
            if(spellArea.questStartCanActive)
                mSpellAreaForActiveQuestMap.insert(SpellAreaForQuestMap::value_type(spellArea.questStart,sa));
            else
                mSpellAreaForQuestMap.insert(SpellAreaForQuestMap::value_type(spellArea.questStart,sa));
        }

        // for search at quest start/reward
        if(spellArea.questEnd)
            mSpellAreaForQuestEndMap.insert(SpellAreaForQuestMap::value_type(spellArea.questEnd,sa));

        // for search at aura apply
        if(spellArea.auraSpell)
            mSpellAreaForAuraMap.insert(SpellAreaForAuraMap::value_type(abs(spellArea.auraSpell),sa));

        ++count;
    } while( result->NextRow() );

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u spell area requirements", count );
}

SpellCastResult SpellMgr::GetSpellAllowedInLocationError(SpellEntry const *spellInfo, uint32 map_id, uint32 zone_id, uint32 area_id, Player const* player)
{
    // normal case
    if( spellInfo->AreaGroupId > 0)
    {
        bool found = false;
        AreaGroupEntry const* groupEntry = sAreaGroupStore.LookupEntry(spellInfo->AreaGroupId);
        while (groupEntry)
        {
            for (uint32 i=0; i<6; ++i)
                if( groupEntry->AreaId[i] == zone_id || groupEntry->AreaId[i] == area_id )
                    found = true;
            if (found || !groupEntry->nextGroup)
                break;
            // Try search in next group
            groupEntry = sAreaGroupStore.LookupEntry(groupEntry->nextGroup);
        }
        
        if(!found)
            return SPELL_FAILED_INCORRECT_AREA;
    }

    // DB base check (if non empty then must fit at least single for allow)
    SpellAreaMapBounds saBounds = spellmgr.GetSpellAreaMapBounds(spellInfo->Id);
    if(saBounds.first != saBounds.second)
    {
        for(SpellAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
        {
            if(itr->second.IsFitToRequirements(player,zone_id,area_id))
                return SPELL_CAST_OK;
        }
        return SPELL_FAILED_INCORRECT_AREA;
    }

    // bg spell checks
    switch(spellInfo->Id)
    {
        case 23333:                                         // Warsong Flag
        case 23335:                                         // Silverwing Flag
            return map_id == 489 && player && player->InBattleGround() ? SPELL_CAST_OK : SPELL_FAILED_REQUIRES_AREA;
        case 34976:                                         // Netherstorm Flag
            return map_id == 566 && player && player->InBattleGround() ? SPELL_CAST_OK : SPELL_FAILED_REQUIRES_AREA;
        case 2584:                                          // Waiting to Resurrect
        case 22011:                                         // Spirit Heal Channel
        case 22012:                                         // Spirit Heal
        case 24171:                                         // Resurrection Impact Visual
        case 42792:                                         // Recently Dropped Flag
        case 43681:                                         // Inactive
        case 44535:                                         // Spirit Heal (mana)
        {
            MapEntry const* mapEntry = sMapStore.LookupEntry(map_id);
            if(!mapEntry)
                return SPELL_FAILED_INCORRECT_AREA;

            return mapEntry->IsBattleGround() && player && player->InBattleGround() ? SPELL_CAST_OK : SPELL_FAILED_REQUIRES_AREA;
        }
        case 44521:                                         // Preparation
        {
            if(!player)
                return SPELL_FAILED_REQUIRES_AREA;

            MapEntry const* mapEntry = sMapStore.LookupEntry(map_id);
            if(!mapEntry)
                return SPELL_FAILED_INCORRECT_AREA;

            if(!mapEntry->IsBattleGround())
                return SPELL_FAILED_REQUIRES_AREA;

            BattleGround* bg = player->GetBattleGround();
            return bg && bg->GetStatus()==STATUS_WAIT_JOIN ? SPELL_CAST_OK : SPELL_FAILED_REQUIRES_AREA;
        }
        case 32724:                                         // Gold Team (Alliance)
        case 32725:                                         // Green Team (Alliance)
        case 35774:                                         // Gold Team (Horde)
        case 35775:                                         // Green Team (Horde)
        {
            MapEntry const* mapEntry = sMapStore.LookupEntry(map_id);
            if(!mapEntry)
                return SPELL_FAILED_INCORRECT_AREA;

            return mapEntry->IsBattleArena() && player && player->InBattleGround() ? SPELL_CAST_OK : SPELL_FAILED_REQUIRES_AREA;
        }
        case 32727:                                         // Arena Preparation
        {
            if(!player)
                return SPELL_FAILED_REQUIRES_AREA;

            MapEntry const* mapEntry = sMapStore.LookupEntry(map_id);
            if(!mapEntry)
                return SPELL_FAILED_INCORRECT_AREA;

            if(!mapEntry->IsBattleArena())
                return SPELL_FAILED_REQUIRES_AREA;

            BattleGround* bg = player->GetBattleGround();
            return bg && bg->GetStatus()==STATUS_WAIT_JOIN ? SPELL_CAST_OK : SPELL_FAILED_REQUIRES_AREA;
        }
    }

    return SPELL_CAST_OK;
}

void SpellMgr::LoadSkillLineAbilityMap()
{
    mSkillLineAbilityMap.clear();

    barGoLink bar( sSkillLineAbilityStore.GetNumRows() );
    uint32 count = 0;

    for (uint32 i = 0; i < sSkillLineAbilityStore.GetNumRows(); ++i)
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
        case SPELLFAMILY_GENERIC:
            // some generic arena related spells have by some strange reason MECHANIC_TURN
            if  (spellproto->Mechanic == MECHANIC_TURN)
                return DIMINISHING_NONE;
            break;
        case SPELLFAMILY_MAGE:
        {
            // Frostbite 0x80000000
            if (spellproto->SpellFamilyFlags[1] & 0x80000000)
                return DIMINISHING_TRIGGER_ROOT;
            // Frost Nova / Freeze (Water Elemental)
            else if (spellproto->SpellIconID == 193)
                return DIMINISHING_CONTROL_ROOT;
            break;
        }
        case SPELLFAMILY_ROGUE:
        {
            // Sap 0x80 Gouge 0x8
            if (spellproto->SpellFamilyFlags[0] & 0x88)
                return DIMINISHING_POLYMORPH;
            // Blind
            else if (spellproto->SpellFamilyFlags[0] & 0x1000000)
                return DIMINISHING_FEAR_BLIND;
            // Cheap Shot
            else if (spellproto->SpellFamilyFlags[0] & 0x400)
                return DIMINISHING_CHEAPSHOT_POUNCE;
            // Crippling poison - Limit to 10 seconds in PvP (No SpellFamilyFlags)
            else if (spellproto->SpellIconID == 163)
                return DIMINISHING_LIMITONLY;
            break;
        }
        case SPELLFAMILY_WARLOCK:
        {
            // Death Coil
            if (spellproto->SpellFamilyFlags[0] & 0x80000)
                return DIMINISHING_DEATHCOIL;
            // Curses/etc
            else if (spellproto->SpellFamilyFlags[0] & 0x80000000)
                return DIMINISHING_LIMITONLY;
            // Howl of Terror
            else if (spellproto->SpellFamilyFlags[1] & 0x8)
                return DIMINISHING_FEAR_BLIND;
            break;
        }
        case SPELLFAMILY_DRUID:
        {
            // Pounce
            if (spellproto->SpellFamilyFlags[0] & 0x20000)
                return DIMINISHING_CHEAPSHOT_POUNCE;
            // Cyclone
            else if (spellproto->SpellFamilyFlags[1] & 0x20)
                return DIMINISHING_CYCLONE;
            //Entangling Roots: to force natures grasp proc to be control root
            else if (spellproto->SpellFamilyFlags[0] & 0x00000200)
                return DIMINISHING_CONTROL_ROOT;
            // Faerie Fire
            else if (spellproto->SpellFamilyFlags[0] & 0x400)
                return DIMINISHING_LIMITONLY;
            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            // Hamstring - limit duration to 10s in PvP
            if (spellproto->SpellFamilyFlags[0] & 0x2)
                return DIMINISHING_LIMITONLY;
            // Intimidating Shout
            else if (spellproto->SpellFamilyFlags[0] & 0x40000)
                return DIMINISHING_FEAR_BLIND;
            // Charge Stun
            else if (spellproto->SpellFamilyFlags[0] & 0x01000000)
                return DIMINISHING_NONE;
            break;
        }
        case SPELLFAMILY_PALADIN:
        {
            // Repentance
            if (spellproto->SpellFamilyFlags[0] & 0x4)
                return DIMINISHING_POLYMORPH;
            break;
        }
        case SPELLFAMILY_PRIEST:
        {
            // Vampiric Embrace
            if ((spellproto->SpellFamilyFlags[0] & 0x4) && spellproto->SpellIconID == 150)
                return DIMINISHING_LIMITONLY;
            break;
        }
        case SPELLFAMILY_DEATHKNIGHT:
        {
            // Hungering Cold (no flags)
            if (spellproto->SpellIconID == 2797)
                return DIMINISHING_POLYMORPH;
            break;
        }
        default:
            break;
    }

    // Get by mechanic
    uint32 mechanic = GetAllSpellMechanicMask(spellproto);
    if (mechanic == MECHANIC_NONE)          return DIMINISHING_NONE;
    if (mechanic & ((1<<MECHANIC_STUN) |
                    (1<<MECHANIC_SHACKLE))) return triggered ? DIMINISHING_TRIGGER_STUN : DIMINISHING_CONTROL_STUN;
    if (mechanic & ((1<<MECHANIC_SLEEP) |
                    (1<<MECHANIC_FREEZE))) return DIMINISHING_FREEZE_SLEEP;
    if (mechanic & (1<<MECHANIC_POLYMORPH)) return DIMINISHING_POLYMORPH;
    if (mechanic & (1<<MECHANIC_ROOT))      return triggered ? DIMINISHING_TRIGGER_ROOT : DIMINISHING_CONTROL_ROOT;
    if (mechanic & ((1<<MECHANIC_FEAR) |
                    (1<<MECHANIC_TURN)))    return DIMINISHING_FEAR_BLIND;
    if (mechanic & (1<<MECHANIC_CHARM))     return DIMINISHING_CHARM;
    if (mechanic & (1<<MECHANIC_SILENCE))   return DIMINISHING_SILENCE;
    if (mechanic & (1<<MECHANIC_DISARM))    return DIMINISHING_DISARM;
    if (mechanic & (1<<MECHANIC_FREEZE))    return DIMINISHING_FREEZE_SLEEP;
    if (mechanic & ((1<<MECHANIC_KNOCKOUT) |
                    (1<<MECHANIC_SAPPED)))  return DIMINISHING_KNOCKOUT;
    if (mechanic & (1<<MECHANIC_BANISH))    return DIMINISHING_BANISH;
    if (mechanic & (1<<MECHANIC_HORROR))    return DIMINISHING_DEATHCOIL;

    // Get by effect
    for (uint8 i = 0 ; i < MAX_SPELL_EFFECTS; ++i)
    {
        if (spellproto->EffectApplyAuraName[i] == SPELL_AURA_MOD_TAUNT)
            return DIMINISHING_TAUNT;
    }
    return DIMINISHING_NONE;
}

int32 GetDiminishingReturnsLimitDuration(DiminishingGroup group, SpellEntry const* spellproto)
{
    if(!IsDiminishingReturnsGroupDurationLimited(group))
        return 0;

    // Explicit diminishing duration
    switch(spellproto->SpellFamilyName)
    {
        case SPELLFAMILY_HUNTER:
        {
            // Wyvern Sting
            if (spellproto->SpellFamilyFlags[1] & 0x1000)
                return 6000;
            break;
        }
        case SPELLFAMILY_PALADIN:
        {
            // Repentance - limit to 6 seconds in PvP
            if (spellproto->SpellFamilyFlags[0] & 0x4)
                return 6000;
            break;
        }
        case SPELLFAMILY_DRUID:
        {
            // Faerie Fire - limit to 40 seconds in PvP (3.1)
            if (spellproto->SpellFamilyFlags[0] & 0x400)
                return 40000;
            break;
        }
        case SPELLFAMILY_PRIEST:
        {
            // Vampiric Embrace - limit to 60 seconds in PvP (3.1)
            if ((spellproto->SpellFamilyFlags[0] & 0x4) && spellproto->SpellIconID == 150)
                return 60000;
            break;
        }
        default:
            break;
    }

    return 10000;
}

bool IsDiminishingReturnsGroupDurationLimited(DiminishingGroup group)
{
    switch(group)
    {
        case DIMINISHING_CONTROL_STUN:
        case DIMINISHING_TRIGGER_STUN:
        case DIMINISHING_FREEZE_SLEEP:
        case DIMINISHING_CONTROL_ROOT:
        case DIMINISHING_TRIGGER_ROOT:
        case DIMINISHING_FEAR_BLIND:
        case DIMINISHING_CHARM:
        case DIMINISHING_POLYMORPH:
        case DIMINISHING_KNOCKOUT:
        case DIMINISHING_CYCLONE:
        case DIMINISHING_BANISH:
        case DIMINISHING_LIMITONLY:
        case DIMINISHING_CHEAPSHOT_POUNCE:
            return true;
        default:
            return false;
    }
    return false;
}

DiminishingReturnsType GetDiminishingReturnsGroupType(DiminishingGroup group)
{
    switch(group)
    {
        case DIMINISHING_TAUNT:
        case DIMINISHING_CONTROL_STUN:
        case DIMINISHING_TRIGGER_STUN:
        case DIMINISHING_CHEAPSHOT_POUNCE:
        case DIMINISHING_CYCLONE:
            return DRTYPE_ALL;
        case DIMINISHING_FEAR_BLIND:
        case DIMINISHING_CONTROL_ROOT:
        case DIMINISHING_TRIGGER_ROOT:
        case DIMINISHING_CHARM:
        case DIMINISHING_POLYMORPH:
        case DIMINISHING_SILENCE:
        case DIMINISHING_DISARM:
        case DIMINISHING_DEATHCOIL:
        case DIMINISHING_FREEZE_SLEEP:
        case DIMINISHING_BANISH:
        case DIMINISHING_KNOCKOUT:
            return DRTYPE_PLAYER;
        default:
            break;
    }

    return DRTYPE_NONE;
}

bool SpellArea::IsFitToRequirements(Player const* player, uint32 newZone, uint32 newArea) const
{
    if(gender!=GENDER_NONE)
    {
        // not in expected gender
        if(!player || gender != player->getGender())
            return false;
    }

    if(raceMask)
    {
        // not in expected race
        if(!player || !(raceMask & player->getRaceMask()))
            return false;
    }

    if(areaId)
    {
        // not in expected zone
        if(newZone!=areaId && newArea!=areaId)
            return false;
    }

    if(questStart)
    {
        // not in expected required quest state
        if(!player || (!questStartCanActive || !player->IsActiveQuest(questStart)) && !player->GetQuestRewardStatus(questStart))
            return false;
    }

    if(questEnd)
    {
        // not in expected forbidden quest state
        if(!player || player->GetQuestRewardStatus(questEnd))
            return false;
    }

    if(auraSpell)
    {
        // not have expected aura
        if(!player)
            return false;
        if(auraSpell > 0)
            // have expected aura
            return player->HasAura(auraSpell);
        else
            // not have expected aura
            return !player->HasAura(-auraSpell);
    }

    return true;
}

//-----------TRINITY-------------

bool SpellMgr::IsNoStackSpellDueToSpell(uint32 spellId_1, uint32 spellId_2, bool sameCaster) const
{
    SpellEntry const *spellInfo_1 = sSpellStore.LookupEntry(spellId_1);
    SpellEntry const *spellInfo_2 = sSpellStore.LookupEntry(spellId_2);

    if(!spellInfo_1 || !spellInfo_2)
        return false;

    SpellSpecific spellId_spec_1 = GetSpellSpecific(spellId_1);
    SpellSpecific spellId_spec_2 = GetSpellSpecific(spellId_2);
    if (spellId_spec_1 && spellId_spec_2)
        if (IsSingleFromSpellSpecificPerTarget(spellId_spec_1, spellId_spec_2)
            ||(sameCaster && IsSingleFromSpellSpecificPerCaster(spellId_spec_1, spellId_spec_2)))
            return true;

    if(spellInfo_1->SpellFamilyName != spellInfo_2->SpellFamilyName)
        return false;

    if(!sameCaster)
    {
        for(uint32 i = 0; i < 3; ++i)
            if (spellInfo_1->Effect[i] == SPELL_EFFECT_APPLY_AURA
                || spellInfo_1->Effect[i] == SPELL_EFFECT_PERSISTENT_AREA_AURA)
            {
                // not channeled AOE effects can stack
                if(IsAreaEffectTarget[spellInfo_1->EffectImplicitTargetA[i]] || IsAreaEffectTarget[spellInfo_1->EffectImplicitTargetB[i]]
                    && !IsChanneledSpell(spellInfo_1))
                        continue;
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
                    case SPELL_AURA_POWER_BURN_MANA:
                    case SPELL_AURA_OBS_MOD_ENERGY:
                    case SPELL_AURA_OBS_MOD_HEALTH:
                    case SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE:
                        return false;
                    default:
                        break;
                }
            }
    }

    spellId_2 = GetLastSpellInChain(spellId_2);
    spellId_1 = GetLastSpellInChain(spellId_1);

    // Hack for Incanter's Absorption
    if (spellId_1 == spellId_2 && (spellId_1 == 44413 || (!sameCaster && spellInfo_1->AttributesEx3 & SPELL_ATTR_EX3_STACKS_FOR_DIFFERENT_CASTERS)))
        return false;

    if (spellId_1 == spellId_2)
        return true;

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
        if (!spellInfo_1->SpellFamilyFlags)
            return false;
    }

    //use data of highest rank spell(needed for spells which ranks have different effects)
    spellInfo_1=sSpellStore.LookupEntry(spellId_1);
    spellInfo_2=sSpellStore.LookupEntry(spellId_2);

    //if spells have exactly the same effect they cannot stack
    for(uint32 i = 0; i < 3; ++i)
        if(spellInfo_1->Effect[i] != spellInfo_2->Effect[i]
            || spellInfo_1->EffectApplyAuraName[i] != spellInfo_2->EffectApplyAuraName[i]
            || spellInfo_1->EffectMiscValue[i] != spellInfo_2->EffectMiscValue[i]) // paladin resist aura
            return false; // need itemtype check? need an example to add that check

    return (!(!sameCaster && spellInfo_1->AttributesEx3 & SPELL_ATTR_EX3_STACKS_FOR_DIFFERENT_CASTERS));
}

bool IsDispelableBySpell(SpellEntry const * dispelSpell, uint32 spellId, bool def)
{
    if (!dispelSpell) return false;
    SpellEntry const *spellproto = sSpellStore.LookupEntry(spellId);
    if (!spellproto) return false;

    if (spellproto->Attributes & SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY)
        return false;

    if(dispelSpell->Attributes & SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY)
        return true;

    return def;
}

void SpellMgr::LoadSpellEnchantProcData()
{
    mSpellEnchantProcEventMap.clear();                             // need for reload case

    uint32 count = 0;

    //                                                0      1             2          3
    QueryResult *result = WorldDatabase.Query("SELECT entry, customChance, PPMChance, procEx FROM spell_enchant_proc_data");
    if( !result )
    {

        barGoLink bar( 1 );

        bar.step();

        sLog.outString();
        sLog.outString( ">> Loaded %u spell enchant proc event conditions", count );
        return;
    }

    barGoLink bar( result->GetRowCount() );
    do
    {
        Field *fields = result->Fetch();

        bar.step();

        uint32 enchantId = fields[0].GetUInt32();

        SpellItemEnchantmentEntry const *ench = sSpellItemEnchantmentStore.LookupEntry(enchantId);
        if (!ench)
        {
            sLog.outErrorDb("Enchancment %u listed in `spell_enchant_proc_data` does not exist", enchantId);
            continue;
        }

        SpellEnchantProcEntry spe;

        spe.customChance = fields[1].GetUInt32();
        spe.PPMChance = fields[2].GetFloat();
        spe.procEx = fields[3].GetUInt32();

        mSpellEnchantProcEventMap[enchantId] = spe;

        ++count;
    } while( result->NextRow() );

    delete result;

    sLog.outString( ">> Loaded %u enchant proc data definitions", count);
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
    flag96 SpellFamilyFlags;
    uint32 TargetAuraState;
    uint32 ManaCost;
    uint32 CastingTimeIndex;
    flag96 Effect;
    flag96 Aura;
    uint16 TalentID;

    bool operator < (const SpellRankEntry & _Right) const
    {
        return (SkillId != _Right.SkillId ? SkillId < _Right.SkillId
            : SpellName!=_Right.SpellName ? SpellName < _Right.SpellName
            : ProcFlags!=_Right.ProcFlags ? ProcFlags < _Right.ProcFlags

            : Effect!=_Right.Effect ? Effect < _Right.Effect
            : Aura!=_Right.Aura ? Aura < _Right.Aura
            : TalentID!=_Right.TalentID ? TalentID < _Right.TalentID
            : (CastingTimeIndex!=_Right.CastingTimeIndex) && (!CastingTimeIndex || !_Right.CastingTimeIndex || CastingTimeIndex==1 || !_Right.CastingTimeIndex==1) ? CastingTimeIndex < _Right.CastingTimeIndex

            : SpellFamilyFlags!=_Right.SpellFamilyFlags ? SpellFamilyFlags < _Right.SpellFamilyFlags
            : (SpellVisual!=_Right.SpellVisual) && (!SpellVisual || !_Right.SpellVisual) ? SpellVisual < _Right.SpellVisual
            : (ManaCost!=_Right.ManaCost) && (!ManaCost || !_Right.ManaCost) ? ManaCost < _Right.ManaCost
            : (DurationIndex!=_Right.DurationIndex) && (!DurationIndex || !_Right.DurationIndex)? DurationIndex < _Right.DurationIndex
            : (RangeIndex!=_Right.RangeIndex) && (!RangeIndex || !_Right.RangeIndex || RangeIndex==1 || !_Right.RangeIndex==1) ? RangeIndex < _Right.RangeIndex
            : TargetAuraState < _Right.TargetAuraState
            );
    }
};

struct SpellRankValue
{
    uint32 Id;
    char const *Rank;
    bool strict;
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
        if (!AbilityInfo->forward_spellid)
            continue;
        ChainedSpells.push_back(AbilityInfo->forward_spellid);
    }

    std::multimap<SpellRankEntry, SpellRankValue> RankMap;

    for (uint32 ability_id=0;ability_id<sSkillLineAbilityStore.GetNumRows();ability_id++)
    {
        SkillLineAbilityEntry const *AbilityInfo=sSkillLineAbilityStore.LookupEntry(ability_id);
        if (!AbilityInfo)
            continue;

        //get only spell with lowest ability_id to prevent doubles
        uint32 spell_id=AbilityInfo->spellId;
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
        if ((SpellInfo->SpellFamilyName==SPELLFAMILY_MAGE) && (SpellInfo->SpellFamilyFlags[0] & 0x1000000) && (SpellInfo->SpellIconID!=82))
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
        entry.CastingTimeIndex=0;
        entry.TalentID=0;
        for (;;)
        {
            AbilityInfo=mSkillLineAbilityMap.lower_bound(spell_id)->second;
            value.Id=spell_id;
            value.Rank=SpellInfo->Rank[sWorld.GetDefaultDbcLocale()];
            value.strict=false;
            RankMap.insert(std::pair<SpellRankEntry, SpellRankValue>(entry,value));
            spell_id=AbilityInfo->forward_spellid;
            SpellInfo=sSpellStore.LookupEntry(spell_id);
            if (!SpellInfo)
                break;
        }
    }

    barGoLink bar(RankMap.size());

    uint32 count=0;

    for (std::multimap<SpellRankEntry, SpellRankValue>::iterator itr = RankMap.begin();itr!=RankMap.end();)
    {
        SpellRankEntry entry=itr->first;
        //trac errors in extracted data
        std::multimap<char const *, std::multimap<SpellRankEntry, SpellRankValue>::iterator> RankErrorMap;
        for (std::multimap<SpellRankEntry, SpellRankValue>::iterator itr2 = RankMap.lower_bound(entry);itr2!=RankMap.upper_bound(entry);itr2++)
        {
            bar.step();
            RankErrorMap.insert(std::pair<char const *, std::multimap<SpellRankEntry, SpellRankValue>::iterator>(itr2->second.Rank,itr2));
        }

        bool error=false;
        //if strict == true strict check is not needed
        if (!itr->second.strict)
            //check for rank duplicates, if there are any do strict check
            for (std::multimap<char const *, std::multimap<SpellRankEntry, SpellRankValue>::iterator>::iterator itr2 = RankErrorMap.begin();itr2!=RankErrorMap.end();)
            {
                char const * err_entry=itr2->first;
                uint32 rank_count=RankErrorMap.count(itr2->first);
                if (rank_count>1)
                {
                    error=true;
                    break;
                }
                else
                    itr2++;
            }
        bool allHaveTalents=true;
        if (error)
        {
            std::list<uint32> ConflictedSpells;
            for (std::multimap<SpellRankEntry, SpellRankValue>::iterator itr2 = RankMap.lower_bound(entry);itr2!=RankMap.upper_bound(entry);itr2=RankMap.lower_bound(entry))
            {
                ConflictedSpells.push_back(itr2->second.Id);
                if (!GetTalentSpellPos(itr2->second.Id))
                    allHaveTalents=false;
                RankMap.erase(itr2);
            }
            SpellRankEntry nextEntry, currEntry;
            for (;!ConflictedSpells.empty();ConflictedSpells.pop_front())
            {
                SpellEntry const *SpellInfo=sSpellStore.LookupEntry(ConflictedSpells.front());
                currEntry.SkillId=entry.SkillId;
                currEntry.SpellName=SpellInfo->SpellName[sWorld.GetDefaultDbcLocale()];
                currEntry.DurationIndex=SpellInfo->DurationIndex;
                currEntry.RangeIndex=SpellInfo->rangeIndex;
                currEntry.ProcFlags=SpellInfo->procFlags;
                currEntry.SpellFamilyFlags=SpellInfo->SpellFamilyFlags;
                //compare talents only when all spells from chain have entry
                //to prevent wrong results with spells which have first rank talented and other not
                if (allHaveTalents)
                    currEntry.TalentID=GetTalentSpellPos(ConflictedSpells.front())->talent_id;
                else
                    currEntry.TalentID=0;
                currEntry.TargetAuraState=SpellInfo->TargetAuraState;
                currEntry.SpellVisual=SpellInfo->SpellVisual[0];
                currEntry.ManaCost=SpellInfo->manaCost;

                //compare effects and casting time
                currEntry.CastingTimeIndex=SpellInfo->CastingTimeIndex;
                currEntry.Effect[0]=SpellInfo->Effect[0];
                currEntry.Effect[1]=SpellInfo->Effect[1];
                currEntry.Effect[2]=SpellInfo->Effect[2];

                currEntry.Aura[0]=SpellInfo->EffectApplyAuraName[0];
                currEntry.Aura[1]=SpellInfo->EffectApplyAuraName[1];
                currEntry.Aura[2]=SpellInfo->EffectApplyAuraName[2];

                SpellRankValue currValue;
                currValue.Id=ConflictedSpells.front();
                currValue.Rank=SpellInfo->Rank[sWorld.GetDefaultDbcLocale()];
                currValue.strict=true;
                RankMap.insert(std::pair<SpellRankEntry, SpellRankValue>(currEntry,currValue));
            }
            itr=RankMap.begin();
            continue;
        }
        else
            for (std::multimap<char const *, std::multimap<SpellRankEntry, SpellRankValue>::iterator>::iterator itr2 = RankErrorMap.begin();itr2!=RankErrorMap.end();)
            {
                char const * err_entry=itr2->first;
                uint32 rank_count=RankErrorMap.count(itr2->first);
                if (rank_count>1)
                for (itr2 = RankErrorMap.lower_bound(err_entry);itr2!=RankErrorMap.upper_bound(err_entry);itr2++)
                {
                    sLog.outDebug("There is a duplicate rank entry (%s) for spell: %u",itr2->first,itr2->second->second.Id);
                    if (!(itr2->second->second.Id==47541 || itr2->second->second.Id==45902 || itr2->second->second.Id==7620))
                    {
                        sLog.outDebug("Spell %u removed from chain data.",itr2->second->second.Id);
                        RankMap.erase(itr2->second);
                    }
                }
                else
                    itr2++;
            }

        //order spells by spellLevel
        std::list<uint32> RankedSpells;
        uint32 min_spell_lvl=0;
        std::multimap<SpellRankEntry, SpellRankValue>::iterator min_itr;
        for (;RankMap.count(entry);)
        {
            for (std::multimap<SpellRankEntry, SpellRankValue>::iterator itr2 = RankMap.lower_bound(entry);itr2!=RankMap.upper_bound(entry);itr2++)
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

        //do not proceed for spells with less than 2 ranks
        itr=RankMap.begin();
        if (RankedSpells.size()<2)
            continue;

        count++;

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
    //for (UNORDERED_MAP<uint32, SpellChainNode>::iterator itr=mSpellChains.begin();itr!=mSpellChains.end();itr++)
       //sLog.outString( "Id: %u, Rank: %d , %s, %u, %u, %u, %u",itr->first,itr->second.rank, sSpellStore.LookupEntry(itr->first)->Rank[sWorld.GetDefaultDbcLocale()], itr->second.first, itr->second.last,itr->second.next ,itr->second.prev);

    sLog.outString();
    sLog.outString( ">> Loaded %u spell chains",count);
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
                case SPELL_AURA_MOD_ROOT:
                    mSpellCustomAttr[i] |= SPELL_ATTR_CU_AURA_CC;
                    mSpellCustomAttr[i] |= SPELL_ATTR_CU_MOVEMENT_IMPAIR;
                    break;
                case SPELL_AURA_MOD_DECREASE_SPEED:
                    mSpellCustomAttr[i] |= SPELL_ATTR_CU_MOVEMENT_IMPAIR;
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
                    break;
                case SPELL_EFFECT_CHARGE:
                case SPELL_EFFECT_JUMP:
                case SPELL_EFFECT_JUMP2:
                case SPELL_EFFECT_138:
                    if(!spellInfo->speed && !spellInfo->SpellFamilyName)
                        spellInfo->speed = SPEED_CHARGE;
                    mSpellCustomAttr[i] |= SPELL_ATTR_CU_CHARGE;
                    break;
                case SPELL_EFFECT_TRIGGER_SPELL:
                    if (SpellTargetType[spellInfo->EffectImplicitTargetA[j]]== TARGET_TYPE_DEST_CASTER ||
                        SpellTargetType[spellInfo->EffectImplicitTargetA[j]]== TARGET_TYPE_DEST_TARGET ||
                        SpellTargetType[spellInfo->EffectImplicitTargetA[j]]== TARGET_TYPE_DEST_DEST ||
                        spellInfo->Targets & (TARGET_FLAG_SOURCE_LOCATION|TARGET_FLAG_DEST_LOCATION))
                        spellInfo->Effect[j] = SPELL_EFFECT_TRIGGER_MISSILE;
                    break;
            }
            
            switch(SpellTargetType[spellInfo->EffectImplicitTargetA[j]])
            {
                case TARGET_TYPE_UNIT_TARGET:
                case TARGET_TYPE_DEST_TARGET:
                    spellInfo->Targets |= TARGET_FLAG_UNIT;
                    break;
                //case TARGET_TYPE_AREA_DST:
                //case TARGET_TYPE_DEST_DEST:
                //    spellInfo->Targets |= TARGET_FLAG_DEST_LOCATION;
                //    break;
            }
        }

        for(uint32 j = 0; j < 3; ++j)
        {
            switch(spellInfo->EffectApplyAuraName[j])
            {
                case SPELL_AURA_MOD_POSSESS:
                case SPELL_AURA_MOD_CONFUSE:
                case SPELL_AURA_MOD_CHARM:
                case SPELL_AURA_AOE_CHARM:
                case SPELL_AURA_MOD_FEAR:
                case SPELL_AURA_MOD_STUN:
                    mSpellCustomAttr[i] |= SPELL_ATTR_CU_AURA_CC;
                    mSpellCustomAttr[i] &= ~SPELL_ATTR_CU_MOVEMENT_IMPAIR;
                    break;
            }
        }     

        if(spellInfo->SpellVisual[0] == 3879)
            mSpellCustomAttr[i] |= SPELL_ATTR_CU_CONE_BACK;

        switch(i)
        {
        // Heart of the Crusader
        case 20335:
        case 20336:
        case 20337:
        // Entries were not updated after spell effect change, we have to do that manually:/
            spellInfo->AttributesEx3 |= SPELL_ATTR_EX3_CAN_PROC_TRIGGERED;
            break;
        case 16007: // Draco-Incarcinatrix 900
            // was 46, but effect is aura effect
            spellInfo->EffectImplicitTargetA[0] = TARGET_UNIT_NEARBY_ENTRY;
            spellInfo->EffectImplicitTargetB[0] = TARGET_DST_NEARBY_ENTRY;
            break;
        case 26029: // dark glare
        case 37433: // spout
        case 43140: case 43215: // flame breath
            mSpellCustomAttr[i] |= SPELL_ATTR_CU_CONE_LINE;
            break;
        case 24340: case 26558: case 28884:     // Meteor
        case 36837: case 38903: case 41276:     // Meteor
        case 57467:                             // Meteor
        case 26789:                             // Shard of the Fallen Star
        case 31436:                             // Malevolent Cleave
        case 35181:                             // Dive Bomb
        case 40810: case 43267: case 43268:     // Saber Lash
        case 42384:                             // Brutal Swipe
        case 45150:                             // Meteor Slash
        case 64422: case 64688:                 // Sonic Screech
            mSpellCustomAttr[i] |= SPELL_ATTR_CU_SHARE_DAMAGE;
            break;
        case 59725:                             // Improved Spell Reflection - aoe aura
            // Target entry seems to be wrong for this spell :/
            spellInfo->EffectImplicitTargetA[0] = TARGET_UNIT_PARTY_CASTER;
            spellInfo->EffectRadiusIndex[0] = 45;
            break;
        case 27820:                             // Mana Detonation
        //case 28062: case 39090:                 // Positive/Negative Charge
        //case 28085: case 39093:
            mSpellCustomAttr[i] |= SPELL_ATTR_CU_EXCLUDE_SELF;
            break;
        case 44978: case 45001: case 45002:     // Wild Magic
        case 45004: case 45006: case 45010:     // Wild Magic
        case 31347: // Doom
        case 41635: // Prayer of Mending
        case 44869: // Spectral Blast
        case 45027: // Revitalize
        case 45976: // Muru Portal Channel
        case 39365: // Thundering Storm
        case 41071: // Raise Dead (HACK)
        case 52124: // Sky Darkener Assault
        case 52479: // Gift of the Harvester
            spellInfo->MaxAffectedTargets = 1;
            break;
        case 41376: // Spite
        case 39992: // Needle Spine
        case 29576: // Multi-Shot
        case 40816: // Saber Lash
        case 37790: // Spread Shot
        case 46771: // Flame Sear
        case 45248: // Shadow Blades
        case 41303: // Soul Drain
        case 54172: // Divine Storm (heal)
        case 29213: // Curse of the Plaguebringer - Noth
        case 28542: // Life Drain - Sapphiron
            spellInfo->MaxAffectedTargets = 3;
            break;
        case 38310: //Multi-Shot
            spellInfo->MaxAffectedTargets = 4;
            break;
        case 42005: // Bloodboil
        case 38296: // Spitfire Totem
        case 37676: // Insidious Whisper
        case 46008: // Negative Energy
        case 45641: // Fire Bloom
        case 55665: // Life Drain - Sapphiron (H)
        case 28796: // Poison Bolt Volly - Faerlina
            spellInfo->MaxAffectedTargets = 5;
            break;
        case 40827: // Sinful Beam
        case 40859: // Sinister Beam
        case 40860: // Vile Beam
        case 40861: // Wicked Beam
        case 54835: // Curse of the Plaguebringer - Noth (H)
        case 54098: // Poison Bolt Volly - Faerlina (H)
            spellInfo->MaxAffectedTargets = 10;
            break;
        case 38794: case 33711: //Murmur's Touch
            spellInfo->MaxAffectedTargets = 1;
            spellInfo->EffectTriggerSpell[0] = 33760;
            break;
        case 17941:    // Shadow Trance
        case 22008:    // Netherwind Focus
        case 31834:    // Light's Grace
        case 34754:    // Clearcasting
        case 34936:    // Backlash
        case 48108:    // Hot Streak
        case 51124:    // Killing Machine
        case 54741:    // Firestarter
        case 57761:    // Fireball!
        case 39805:    // Lightning Overload
        case 52437:    // Sudden Death
        case 64823:    // Item - Druid T8 Balance 4P Bonus
            spellInfo->procCharges=1;
            break;
        case 44544:    // Fingers of Frost
            spellInfo->procCharges=2;
            spellInfo->EffectSpellClassMask[0] = flag96(685904631,1151048,0);
            break;
        case 28200:    // Ascendance (Talisman of Ascendance trinket)
            spellInfo->procCharges=6;
            break;
        case 51852:    // The Eye of Acherus (no spawn in phase 2 in db)
            spellInfo->EffectMiscValue[0] |= 1;
            break;
        case 52025:    // Cleansing Totem Effect
            spellInfo->EffectDieSides[1] = 1;
            break;
        case 51904:     // Summon Ghouls On Scarlet Crusade (core does not know the triggered spell is summon spell)
            spellInfo->EffectImplicitTargetA[0] = TARGET_UNIT_CASTER;
            break;
        case 29809:     // Desecration Arm - 36 instead of 37 - typo? :/
            spellInfo->EffectRadiusIndex[0] = 37;
            break;
        // Master Shapeshifter: missing stance data for forms other than bear - bear version has correct data
        // To prevent aura staying on target after talent unlearned
        case 48420:
            spellInfo->Stances = 1 << (FORM_CAT - 1);
            break;
        case 48421:
            spellInfo->Stances = 1 << (FORM_MOONKIN - 1);
            break;
        case 48422:
            spellInfo->Stances = 1 << (FORM_TREE - 1);
            break;
        default:
            break;
        }

        switch(spellInfo->SpellFamilyName)
        {
            case SPELLFAMILY_WARRIOR:
                // Shout
                if(spellInfo->SpellFamilyFlags[0] & 0x20000
                    || spellInfo->SpellFamilyFlags[1] & 0x20)
                    mSpellCustomAttr[i] |= SPELL_ATTR_CU_AURA_CC;
                break;
            case SPELLFAMILY_DRUID:
                // Starfall Target Selection
                if(spellInfo->SpellFamilyFlags[2] & 0x100)
                    spellInfo->MaxAffectedTargets = 2;
                // Starfall AOE Damage
                else if(spellInfo->SpellFamilyFlags[2] & 0x800000)
                    mSpellCustomAttr[i] |= SPELL_ATTR_CU_EXCLUDE_SELF;
                // Roar
                else if(spellInfo->SpellFamilyFlags[0] & 0x8)
                    mSpellCustomAttr[i] |= SPELL_ATTR_CU_AURA_CC;
                break;
                // Do not allow Deadly throw and Slice and Dice to proc twice
            case SPELLFAMILY_ROGUE:
                if(spellInfo->SpellFamilyFlags[1] & 0x1 || spellInfo->SpellFamilyFlags[0] & 0x40000)
                    spellInfo->AttributesEx4 |= SPELL_ATTR_EX4_CANT_PROC_FROM_SELFCAST;
                break;
        }
    }

    SummonPropertiesEntry *properties = const_cast<SummonPropertiesEntry*>(sSummonPropertiesStore.LookupEntry(121));
    properties->Type = SUMMON_TYPE_TOTEM;

    CreatureAI::FillAISpellInfo();
}

// Fill custom data about enchancments
void SpellMgr::LoadEnchantCustomAttr()
{
    uint32 size = sSpellItemEnchantmentStore.GetNumRows();
    mEnchantCustomAttr.resize(size);

    for (uint32 i = 0;i<size; ++i)
       mEnchantCustomAttr[i] = 0;

    for(uint32 i = 0; i < GetSpellStore()->GetNumRows(); ++i)
    {
        SpellEntry * spellInfo = (SpellEntry*)GetSpellStore()->LookupEntry(i);
        if(!spellInfo)
            continue;

        // TODO: find a better check
        if (!(spellInfo->AttributesEx2 & SPELL_ATTR_EX2_UNK13) || !(spellInfo->Attributes & SPELL_ATTR_NOT_SHAPESHIFT))
            continue;

        for(uint32 j = 0; j < 3; ++j)
        {
            if(spellInfo->Effect[j] == SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY)
            {
                uint32 enchId = spellInfo->EffectMiscValue[j];
                SpellItemEnchantmentEntry const *ench = sSpellItemEnchantmentStore.LookupEntry(enchId);
                if (!enchId)
                    continue;
                mEnchantCustomAttr[enchId] = true;
                break;
            }
        }
    }
}

bool SpellMgr::IsSkillTypeSpell(uint32 spellId, SkillType type) const
{
    SkillLineAbilityMap::const_iterator lower = GetBeginSkillLineAbilityMap(spellId);
    SkillLineAbilityMap::const_iterator upper = GetEndSkillLineAbilityMap(spellId);
    for (;lower!=upper;++lower)
    {
        if (lower->second->skillId==type)
            return true;
    }
    return false;
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

        if(trigger > 0)
        {
            switch(type)
            {
                case 0: mSpellCustomAttr[trigger] |= SPELL_ATTR_CU_LINK_CAST; break;
                case 1: mSpellCustomAttr[trigger] |= SPELL_ATTR_CU_LINK_HIT;  break;
                case 2: mSpellCustomAttr[trigger] |= SPELL_ATTR_CU_LINK_AURA; break;
            }
        }
        else
        {
            mSpellCustomAttr[-trigger] |= SPELL_ATTR_CU_LINK_REMOVE;
        }

        if(type) //we will find a better way when more types are needed
        {
            if(trigger > 0)
                trigger += SPELL_LINKED_MAX_SPELLS * type;
            else
                trigger -= SPELL_LINKED_MAX_SPELLS * type;
        }
        mSpellLinkedMap[trigger].push_back(effect);

        ++count;
    } while( result->NextRow() );

    delete result;

    sLog.outString();
    sLog.outString( ">> Loaded %u linked spells", count );
}

bool SpellMgr::CheckDB() const
{
    SpellScriptTarget::const_iterator lower = GetBeginSpellScriptTarget(30531);
    SpellScriptTarget::const_iterator upper = GetEndSpellScriptTarget(30531);
    if(lower == upper || lower->second.targetEntry != 17256)
        return false;

    return true;
}
