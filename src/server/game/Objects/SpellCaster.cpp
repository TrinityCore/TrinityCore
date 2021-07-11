/*
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

#include "SpellCaster.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "Totem.h"
#include "CreatureAI.h"
#include "Chat.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "World.h"
#include "WorldPacket.h"
#include "Opcodes.h"

Unit* SpellCaster::SelectMagnetTarget(Unit* victim, Spell* spell, SpellEffectIndex eff)
{
    if (!victim)
        return nullptr;

    SpellEntry const* pProto = spell->m_spellInfo;
    if (!pProto) return nullptr;
    // Example spell: Cause Insanity (Hakkar)
    if (pProto->AttributesEx & SPELL_ATTR_EX_CANT_BE_REDIRECTED)
        return victim;
    // Magic case

    if (pProto->AttributesEx3 & SPELL_ATTR_EX3_NO_INITIAL_AGGRO)
        return victim;

    if ((pProto->DmgClass == SPELL_DAMAGE_CLASS_MAGIC || pProto->SpellVisual == 7250) && pProto->Dispel != DISPEL_POISON && !(pProto->Attributes & 0x10))
    {
        Unit::AuraList const& magnetAuras = victim->GetAurasByType(SPELL_AURA_SPELL_MAGNET);
        for (const auto magnetAura : magnetAuras)
        {
            if (Unit* magnet = magnetAura->GetCaster())
            {
                if (magnet->IsAlive() && magnet->IsWithinLOSInMap(this) && spell->CheckTarget(magnet, eff))
                {
                    if (SpellAuraHolder* holder = magnetAura->GetHolder())
                        if (holder->DropAuraCharge())
                        {
                            magnet->RemoveAurasDueToSpell(holder->GetId()); // Remove from grounding totem also
                            victim->RemoveSpellAuraHolder(holder);
                        }
                    return magnet;
                }
            }
        }
    }

    return victim;
}

uint32 SpellCaster::GetLevelForTarget(SpellCaster const* target) const
{
    // Bosses are 3 levels higher than players.
    if (Creature const* pCreature = ToCreature())
    {
        if (!pCreature->IsWorldBoss() || !target || !target->IsUnit())
            return pCreature->GetLevel();

        uint32 level = static_cast<Unit const*>(target)->GetLevel() + sWorld.getConfig(CONFIG_UINT32_WORLD_BOSS_LEVEL_DIFF);
        if (level < 1)
            return 1;
        if (level > 255)
            return 255;
        return level;
    }

    if (Unit const* pUnit = ToUnit())
        return pUnit->GetLevel();

    if (GameObject const* pGo = ToGameObject())
    {
        uint32 level = 0;

        switch (pGo->GetGOInfo()->type)
        {
            case GAMEOBJECT_TYPE_CHEST:
                level = pGo->GetGOInfo()->chest.level;
                break;
            case GAMEOBJECT_TYPE_TRAP:
                level = pGo->GetGOInfo()->trap.level;
                break;
        }

        if (!level)
            level = pGo->GetUInt32Value(GAMEOBJECT_LEVEL);

        if (level)
            return level;
    }

    if (Unit const* pUnit = ::ToUnit(target))
        return pUnit->GetLevel();

    return PLAYER_MAX_LEVEL;
}

uint32 SpellCaster::GetWeaponSkillValue(WeaponAttackType attType, SpellCaster const* target) const
{
    if (Player const* pPlayer = ToPlayer())
    {
        Item* item = pPlayer->GetWeaponForAttack(attType, true, true);

        // feral or unarmed skill only for base attack
        if (attType != BASE_ATTACK && !item)
            return 0;

        if (pPlayer->IsInFeralForm())
            return GetSkillMaxForLevel();              // always maximized SKILL_FERAL_COMBAT in fact

        // weapon skill or (unarmed for base attack)
        uint32  skill = item ? item->GetProto()->GetProficiencySkill() : SKILL_UNARMED;

// Daemon: pas en preBC !
//        // in PvP use full skill instead current skill value
//        value = (target && target->GetTypeId() == TYPEID_PLAYER)
//            ? ((Player*)this)->GetSkillMax(skill)
//            : ((Player*)this)->GetSkillValue(skill);
        return pPlayer->GetSkillValue(skill);
    }

    return GetUnitMeleeSkill(target);
}

uint32 SpellCaster::GetDefenseSkillValue(SpellCaster const* target) const
{
    if (Player const* pPlayer = ToPlayer())
    {
        // in PvP use full skill instead current skill value
        uint32 value = (target && target->IsPlayer())
            ? pPlayer->GetSkillMax(SKILL_DEFENSE)
            : pPlayer->GetSkillValue(SKILL_DEFENSE);
        return value;
    }

    return GetUnitMeleeSkill(target);
}

// Calculate spell hit result can be:
// Every spell can: Evade/Immune/Reflect/Sucesful hit
// For melee based spells:
//   Miss
//   Dodge
//   Parry
// For spells
//   Resist
SpellMissInfo SpellCaster::SpellHitResult(Unit* pVictim, SpellEntry const* spell, SpellEffectIndex effIndex, bool CanReflect, Spell* spellPtr)
{
    // Return evade for units in evade mode
    if (pVictim->GetTypeId() == TYPEID_UNIT && ((Creature*)pVictim)->IsInEvadeMode())
        return SPELL_MISS_EVADE;

    // Check for immune (use charges)
    if (pVictim != this && pVictim->IsImmuneToSpell(spell, pVictim == this))
        return SPELL_MISS_IMMUNE;

    // All positive spells can`t miss
    // TODO: client not show miss log for this spells - so need find info for this in dbc and use it!
    if (spell->IsPositiveSpell(this, pVictim) || spell->IsPositiveEffect(effIndex, this, pVictim))
        return SPELL_MISS_NONE;

    // Check for immune (use charges)
    SpellSchoolMask schoolMask;
    if (spellPtr)
        schoolMask = spellPtr->m_spellSchoolMask;
    else
        schoolMask = spell->GetSpellSchoolMask();

    if (pVictim != this && pVictim->IsImmuneToDamage(schoolMask, spell))
        return SPELL_MISS_IMMUNE;

    // Try victim reflect spell
    if (CanReflect)
    {
        int32 reflectchance = pVictim->GetTotalAuraModifier(SPELL_AURA_REFLECT_SPELLS);
        Unit::AuraList const& mReflectSpellsSchool = pVictim->GetAurasByType(SPELL_AURA_REFLECT_SPELLS_SCHOOL);
        for (const auto i : mReflectSpellsSchool)
            if (i->GetModifier()->m_miscvalue & spell->GetSpellSchoolMask())
                reflectchance += i->GetModifier()->m_amount;
        if (reflectchance > 0 && roll_chance_i(reflectchance))
        {
            // Start triggers for remove charges if need (trigger only for victim, and mark as active spell)
            ProcDamageAndSpell(ProcSystemArguments(pVictim, PROC_FLAG_NONE, PROC_FLAG_TAKEN_NEGATIVE_SPELL_HIT, PROC_EX_REFLECT, 1, BASE_ATTACK, spell));
            return SPELL_MISS_REFLECT;
        }
    }

    switch (spell->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_NONE:
            return SPELL_MISS_NONE;
        case SPELL_DAMAGE_CLASS_MAGIC:
            return MagicSpellHitResult(pVictim, spell, spellPtr);
        case SPELL_DAMAGE_CLASS_MELEE:
        case SPELL_DAMAGE_CLASS_RANGED:
            return MeleeSpellHitResult(pVictim, spell, spellPtr);
    }
    return SPELL_MISS_NONE;
}

ProcSystemArguments::ProcSystemArguments(Unit* pVictim_, uint32 procFlagsAttacker_, uint32 procFlagsVictim_, uint32 procExtra_, uint32 amount_, WeaponAttackType attType_,
    SpellEntry const* procSpell_, Spell const* spell)
    : pVictim(pVictim_), procFlagsAttacker(procFlagsAttacker_), procFlagsVictim(procFlagsVictim_), procExtra(procExtra_), amount(amount_),
    attType(attType_), procSpell(procSpell_), isSpellTriggeredByAura(spell && spell->IsTriggeredByAura())
{
    if (spell)
        appliedSpellModifiers = spell->m_appliedMods;

    if (pVictim_)
        victimGuid = pVictim_->GetObjectGuid();
}

void SpellCaster::UpdatePendingProcs(uint32 diff)
{
    if (sWorld.getConfig(CONFIG_UINT32_SPELL_PROC_DELAY) && IsInWorld())
    {
        if (m_procsUpdateTimer < diff)
        {
            m_procsUpdateTimer = sWorld.getConfig(CONFIG_UINT32_SPELL_PROC_DELAY);
            if (!m_pendingProcChecks.empty())
            {
                std::vector<ProcSystemArguments> procData = std::move(m_pendingProcChecks);
                m_pendingProcChecks.clear();
                for (auto& proc : procData)
                    ProcDamageAndSpell_delayed(proc);
            }
        }
        else
            m_procsUpdateTimer -= diff;
    }
}

void SpellCaster::ProcDamageAndSpell(ProcSystemArguments&& data)
{
    if ((data.pVictim && !IsInMap(data.pVictim)) || !IsInWorld())
        return;

    if (data.procFlagsAttacker)
        if (Unit* pUnit = ToUnit())
            pUnit->ProcSkillsAndReactives(false, data.pVictim, data.procFlagsAttacker, data.procExtra, data.attType);

    if (data.procFlagsVictim && data.pVictim && data.pVictim->IsAlive())
        data.pVictim->ProcSkillsAndReactives(true, IsUnit() ? static_cast<Unit*>(this) : data.pVictim, data.procFlagsVictim, data.procExtra, data.attType);
    
    // Always execute On Kill procs instantly. Fixes Improved Drain Soul talent.
    if (!sWorld.getConfig(CONFIG_UINT32_SPELL_PROC_DELAY) || (data.procFlagsAttacker & PROC_FLAG_KILL))
        ProcDamageAndSpell_real(data);
    else
        m_pendingProcChecks.emplace_back(std::move(data));
}

void SpellCaster::ProcDamageAndSpell_delayed(ProcSystemArguments& data)
{
    if (data.pVictim)
    {
        data.pVictim = GetMap()->GetUnit(data.victimGuid);
        if (!data.pVictim)
            return;
    }

    ProcDamageAndSpell_real(data);
}

void SpellCaster::ProcDamageAndSpell_real(ProcSystemArguments& data)
{
    ProcTriggeredList procTriggered;

    // Not much to do if no flags are set.
    if (data.procFlagsAttacker)
        if (Unit* pUnit = ToUnit())
            pUnit->ProcDamageAndSpellFor(false, data.pVictim, data.procFlagsAttacker, data.procExtra, data.attType, data.procSpell, data.amount, procTriggered, data.appliedSpellModifiers, data.isSpellTriggeredByAura);

    // Now go on with a victim's events'n'auras
    // Not much to do if no flags are set or there is no victim
    if (data.pVictim && data.pVictim->IsAlive() && data.procFlagsVictim)
    {
        // http://blue.cardplace.com/cache/wow-paladin/1069149.htm
        // "Charges will not generate off auto attacks or npc attacks by trying"
        // "to sit down and force a crit. However, ability crits from physical"
        // "abilities such as Sinister Strike, Hamstring, Auto-shot, Aimed shot,"
        // "etc will generate a charge if you're sitting."
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_7_1
        data.pVictim->ProcDamageAndSpellFor(true, IsUnit() ? static_cast<Unit*>(this) : data.pVictim, data.procFlagsVictim, !data.procSpell && !data.pVictim->IsStandingUp() ? data.procExtra & ~PROC_EX_CRITICAL_HIT : data.procExtra, data.attType, data.procSpell, data.amount, procTriggered, data.appliedSpellModifiers, data.isSpellTriggeredByAura);
#else
        data.pVictim->ProcDamageAndSpellFor(true, IsUnit() ? static_cast<Unit*>(this) : data.pVictim, data.procFlagsVictim, data.procExtra, data.attType, data.procSpell, data.amount, procTriggered, data.appliedSpellModifiers, data.isSpellTriggeredByAura);
#endif
    
        // Standing up on damage taken must happen after proc checks.
        if (Player* pVictimPlayer = data.pVictim->ToPlayer())
            if (pVictimPlayer->IsStandUpScheduled())
                pVictimPlayer->SetStandState(UNIT_STAND_STATE_STAND);
    }

    if (Unit* pUnit = ToUnit())
        pUnit->HandleTriggers(data.pVictim, data.procExtra, data.amount, data.procSpell, procTriggered);
}

// Melee based spells can be miss, parry or dodge on this step
// Crit or block - determined on damage calculation phase! (and can be both in some time)
float SpellCaster::MeleeSpellMissChance(Unit* pVictim, WeaponAttackType attType, int32 skillDiff, SpellEntry const* spell, Spell* spellPtr)
{
    if (!pVictim || !pVictim->IsStandingUp())
        return 0.0f;

    // Calculate hit chance (more correct for chance mod)
    float hitChance = 0.0f;
    float missChance = 0.0f;

    // PvP - PvE melee chances
    if (pVictim->GetTypeId() == TYPEID_PLAYER)
        missChance = 5.0f - skillDiff * 0.04f;
    else if (skillDiff < -10)
        missChance = 5.0f - skillDiff * 0.2f;
    else
        missChance = 5.0f - skillDiff * 0.1f;

    // Low level reduction
    if (!pVictim->IsPlayer() && pVictim->GetLevel() < 10)
        missChance *= pVictim->GetLevel() / 10.0f;

    if (Unit* pUnit = ToUnit())
    {
        // Spellmod from SPELLMOD_RESIST_MISS_CHANCE
        if (Player* modOwner = pUnit->GetSpellModOwner())
            modOwner->ApplySpellMod(spell->Id, SPELLMOD_RESIST_MISS_CHANCE, hitChance, spellPtr);

        // Bonuses from attacker aura and ratings
        if (attType == RANGED_ATTACK)
            hitChance += pUnit->m_modRangedHitChance;
        else
            hitChance += pUnit->m_modMeleeHitChance;
    } 

    // There is some code in 1.12 that explicitly adds a modifier that causes the first 1% of +hit gained from
    // talents or gear to be ignored against monsters with more than 10 Defense Skill above the attacking players Weapon Skill.
    // https://us.forums.blizzard.com/en/wow/t/bug-hit-tables/185675/33
    if (skillDiff < -10 && hitChance > 0)
        hitChance -= 1.0f;

    // Hit chance depends from victim auras
    if (attType == RANGED_ATTACK)
        hitChance += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_RANGED_HIT_CHANCE);
    else
        hitChance += pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE);

    missChance -= hitChance;

    // Limit miss chance from 0 to 60%
    if (missChance < 0.0f)
        return 0.0f;
    if (missChance > 60.0f)
        return 60.0f;
    return missChance;
}

// Melee based spells hit result calculations
SpellMissInfo SpellCaster::MeleeSpellHitResult(Unit* pVictim, SpellEntry const* spell, Spell* spellPtr)
{
    WeaponAttackType attType = BASE_ATTACK;

    if (spell->DmgClass == SPELL_DAMAGE_CLASS_RANGED)
        attType = RANGED_ATTACK;

    // Warrior spell Execute (5308) should never dodge, miss, resist ... Only the trigger can (20647)
    if (spell->IsFitToFamily<SPELLFAMILY_WARRIOR, CF_WARRIOR_EXECUTE>() && spell->Id != 20647)
        return SPELL_MISS_NONE;

    // bonus from skills is 0.04% per skill Diff
    int32 attackerWeaponSkill = (spell->EquippedItemClass == ITEM_CLASS_WEAPON) ? int32(GetWeaponSkillValue(attType, pVictim)) : GetSkillMaxForLevel();
    int32 skillDiff = attackerWeaponSkill - int32(pVictim->GetSkillMaxForLevel(this));
    int32 fullSkillDiff = attackerWeaponSkill - int32(pVictim->GetDefenseSkillValue(this));
    int32 minWeaponSkill = GetSkillMaxForLevel(pVictim) < attackerWeaponSkill ? GetSkillMaxForLevel(pVictim) : attackerWeaponSkill;
    int32 cappedSkillDiff = minWeaponSkill - pVictim->GetSkillMaxForLevel(this);

    uint32 roll = urand(0, 9999);

    uint32 missChance = uint32(MeleeSpellMissChance(pVictim, attType, fullSkillDiff, spell, spellPtr) * 100.0f);
    // Roll miss
    uint32 tmp = spell->AttributesEx3 & SPELL_ATTR_EX3_CANT_MISS ? 0 : missChance;
    if (roll < tmp)
        return SPELL_MISS_MISS;

    // Chance resist mechanic for spell (effect resistance handled later)
    int32 resist_mech = 0;
    if (spell->Mechanic)
        resist_mech = pVictim->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_MECHANIC_RESISTANCE, spell->Mechanic) * 100;
    // Roll chance
    tmp += resist_mech;
    if (roll < tmp)
        return SPELL_MISS_RESIST;

    bool canDodge = true;
    bool canParry = true;

    // Same spells cannot be parry/dodge
    if (spell->Attributes & SPELL_ATTR_IMPOSSIBLE_DODGE_PARRY_BLOCK)
        return SPELL_MISS_NONE;

    // Ranged attack cannot be parry/dodge
    if (attType == RANGED_ATTACK)
        return SPELL_MISS_NONE;

    bool from_behind = !pVictim->HasInArc(this, M_PI_F);

    // Check for attack from behind
    if (from_behind)
    {
        // Can`t dodge from behind in PvP (but its possible in PvE)
        if (GetTypeId() == TYPEID_PLAYER && pVictim->GetTypeId() == TYPEID_PLAYER)
            canDodge = false;
        // Can`t parry
        canParry = false;
    }
    // Check creatures flags_extra for disable parry
    if (Creature* pCreatureVictim = pVictim->ToCreature())
    { 
        if (pCreatureVictim->HasExtraFlag(CREATURE_FLAG_EXTRA_NO_PARRY))
            canParry = false;
    }
    // Check if the player can parry
    else
    {
        if (!((Player*)pVictim)->CanParry())
            canParry = false;
    }

    if (canDodge)
    {
        // Roll dodge
        int32 dodgeModifier = pVictim->IsPlayer() ? skillDiff * 4 : skillDiff * 10;
        int32 dodgeChance = int32(pVictim->GetUnitDodgeChance() * 100.0f) - dodgeModifier;

        if (dodgeChance < 0)
            dodgeChance = 0;

        // Low level reduction
        if (!pVictim->IsPlayer() && pVictim->GetLevel() < 10)
            dodgeChance *= pVictim->GetLevel() / 10.0f;

        tmp += dodgeChance;
        if (roll < tmp)
            return SPELL_MISS_DODGE;
    }

    if (canParry)
    {
        // Roll parry
        int32 parryModifier = pVictim->IsPlayer() ? skillDiff * 4 : cappedSkillDiff < -10 ? 60 * cappedSkillDiff : 20 * cappedSkillDiff;
        int32 parryChance = int32(pVictim->GetUnitParryChance() * 100.0f) - parryModifier;

        // Can`t parry from behind
        if (parryChance < 0)
            parryChance = 0;

        // Low level reduction
        if (!pVictim->IsPlayer() && pVictim->GetLevel() < 10)
            parryChance *= pVictim->GetLevel() / 10.0f;

        tmp += parryChance;
        if (roll < tmp)
            return SPELL_MISS_PARRY;
    }

    return SPELL_MISS_NONE;
}

SpellMissInfo SpellCaster::MagicSpellHitResult(Unit* pVictim, SpellEntry const* spell, Spell* spellPtr)
{
    // Can`t miss on dead target (on skinning for example)
    if (!pVictim->IsAlive())
        return SPELL_MISS_NONE;

    // Spell cannot be resisted (not exist on dbc, custom flag)
    if (spell->AttributesEx4 & SPELL_ATTR_EX4_IGNORE_RESISTANCES)
        return SPELL_MISS_NONE;

    int32 hitChance = MagicSpellHitChance(pVictim, spell, spellPtr);
    int32 missChance = 10000 - hitChance;
    int32 rand = irand(0, 10000);

    if (rand < missChance)
        return SPELL_MISS_RESIST;

    return SPELL_MISS_NONE;
}

int32 SpellCaster::MagicSpellHitChance(Unit* pVictim, SpellEntry const* spell, Spell* spellPtr)
{
     if (spell->AttributesEx3 & SPELL_ATTR_EX3_CANT_MISS)
        return 10000;

    SpellSchoolMask schoolMask = spell->GetSpellSchoolMask();
    // PvP - PvE spell misschances per leveldif > 2
    int32 lchance = pVictim->GetTypeId() == TYPEID_PLAYER ? 7 : 11;
    int32 leveldif = int32(pVictim->GetLevelForTarget(this)) - int32(GetLevelForTarget(pVictim));

    // Base hit chance from attacker and victim levels
    float modHitChance;
    if (leveldif < 3)
        modHitChance = 96 - leveldif;
    else
        modHitChance = 94 - (leveldif - 2) * lchance;

    //DEBUG_UNIT(this, DEBUG_SPELL_COMPUTE_RESISTS, "%s [%u] : Binary [%s]. Base hit chance %f, level diff: %d", spell->SpellName[2].c_str(), spell->Id, spell->IsBinary() ? "YES" : "NO", modHitChance, leveldif);

    // Spellmod from SPELLMOD_RESIST_MISS_CHANCE
    if (Unit* pUnit = ToUnit())
    {
        if (Player* modOwner = pUnit->GetSpellModOwner())
        {
            modOwner->ApplySpellMod(spell->Id, SPELLMOD_RESIST_MISS_CHANCE, modHitChance, spellPtr);
            //DEBUG_UNIT(this, DEBUG_SPELL_COMPUTE_RESISTS, "SPELLMOD_RESIST_MISS_CHANCE : %f", modHitChance);
        }
    }
    
    // Chance hit from victim SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE auras
    modHitChance += pVictim->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE, schoolMask);
    //DEBUG_UNIT(this, DEBUG_SPELL_COMPUTE_RESISTS, "SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE (+ %i) : %f", pVictim->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE, schoolMask), modHitChance);

    // Reduce spell hit chance for Area of effect spells from victim SPELL_AURA_MOD_AOE_AVOIDANCE aura
    if (spell->IsAreaOfEffectSpell())
    {
        modHitChance -= pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_AOE_AVOIDANCE);
        //DEBUG_UNIT(this, DEBUG_SPELL_COMPUTE_RESISTS, "SPELL_AURA_MOD_AOE_AVOIDANCE (- %i) : %f", pVictim->GetTotalAuraModifier(SPELL_AURA_MOD_AOE_AVOIDANCE), modHitChance);
    }

    // Chance resist mechanic for spell (effect resistance handled later)
    int32 resist_mech = 0;
    if (spell->Mechanic)
        resist_mech = pVictim->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_MECHANIC_RESISTANCE, spell->Mechanic);
    // Apply mod
    modHitChance -= resist_mech;
    //DEBUG_UNIT(this, DEBUG_SPELL_COMPUTE_RESISTS, "SPELL_AURA_MOD_MECHANIC_RESISTANCE (- %i) : %f", resist_mech, modHitChance);

    // Chance resist debuff
    modHitChance -= pVictim->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_DEBUFF_RESISTANCE, int32(spell->Dispel));
    //DEBUG_UNIT(this, DEBUG_SPELL_COMPUTE_RESISTS, "SPELL_AURA_MOD_DEBUFF_RESISTANCE (- %i) : %f", pVictim->GetTotalAuraModifierByMiscValue(SPELL_AURA_MOD_DEBUFF_RESISTANCE, int32(spell->Dispel)), modHitChance);

    // Increase hit chance from attacker SPELL_AURA_MOD_SPELL_HIT_CHANCE and attacker ratings
    if (Unit* pUnit = ToUnit())
        modHitChance += int32(pUnit->m_modSpellHitChance);
    //DEBUG_UNIT(this, DEBUG_SPELL_COMPUTE_RESISTS, "SPELL_AURA_MOD_SPELL_HIT_CHANCE (+ %i) : %f", int32(m_modSpellHitChance), modHitChance);

    // Nostalrius: sorts binaires.
    if (spell->IsBinary())
    {
        // Get base victim resistance for school
        float resistModHitChance = GetSpellResistChance(pVictim, schoolMask, false);
        modHitChance *= (1 - resistModHitChance);
        //DEBUG_UNIT(this, DEBUG_SPELL_COMPUTE_RESISTS, "x %f : HitChance = %f", (1 - resistModHitChance), modHitChance);
    }

    int32 HitChance = modHitChance * 100;
    if (HitChance < 100) HitChance = 100;
    if (HitChance > 9900) HitChance = 9900;
    return HitChance;
}

float SpellCaster::GetSpellResistChance(Unit const* victim, uint32 schoolMask, bool innateResists) const
{
    Unit const* pUnit = ToUnit();
    // Get base victim resistance for school
    float const baseResistance = victim->GetResistance(GetFirstSchoolInMask(SpellSchoolMask(schoolMask)));
    // Get attacker spell penetration from SPELL_AURA_MOD_TARGET_RESISTANCE aura
    float const selfResistance = pUnit ? pUnit->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, schoolMask) : 0;

    float resistModHitChance = baseResistance + selfResistance;

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    if ((resistModHitChance < 0.0f) && (baseResistance >= 0.0f))
        resistModHitChance = 0.0f;
#endif

    // Magic vulnerability calculation
    if (resistModHitChance < 0.0f)
    {
        // Victim's level based skill, penalize when calculating for low levels (< 20):
        float const skill = std::max(GetSkillMaxForLevel(victim), uint16(100));
        // Convert resistance value to vulnerability percentage through comparision with skill
        resistModHitChance = (float(resistModHitChance) / skill) * 100;
        return (resistModHitChance * 0.01f);
    }

    uint32 const uiLevel = GetLevel();

    // Computing innate resists, resistance bonus when attacking a creature higher level. Not affected by modifiers.
    if (innateResists && victim->GetTypeId() == TYPEID_UNIT)
    {
        int32 leveldiff = int32(victim->GetLevelForTarget(this)) - int32(GetLevelForTarget(victim));
        resistModHitChance += int32((8.0f * leveldiff) * uiLevel / 63.0f);
    }
    resistModHitChance *= (float)(0.15f / uiLevel);

    if (resistModHitChance < 0.0f)
        resistModHitChance = 0.0f;
    if (resistModHitChance > 0.75f)
        resistModHitChance = 0.75f;

    return resistModHitChance;
}

void SpellCaster::SendSpellMiss(Unit* target, uint32 spellId, SpellMissInfo missInfo)
{
    WorldPacket data(SMSG_SPELLLOGMISS, (4 + 8 + 1 + 4 + 8 + 1));
    data << uint32(spellId);
    data << GetObjectGuid();
    data << uint8(0);                                       // unk8
    data << uint32(1);                                      // target count
    // for(i = 0; i < target count; ++i)
    data << target->GetObjectGuid();                        // target GUID
    data << uint8(missInfo);
    // Nostalrius: + 2 * float if unk8=1
    // end loop
    SendObjectMessageToSet(&data, true);
}

void SpellCaster::SendSpellOrDamageImmune(Unit* target, uint32 spellId) const
{
    WorldPacket data(SMSG_SPELLORDAMAGE_IMMUNE, (8 + 8 + 4 + 1));
    data << GetObjectGuid();
    data << target->GetObjectGuid();
    data << uint32(spellId);
    data << uint8(0);
    SendMessageToSet(&data, true);
}

uint32 SpellCaster::SpellCriticalDamageBonus(SpellEntry const* spellProto, uint32 damage, Unit* pVictim, Spell* spell)
{
    // Calculate critical bonus
    int32 crit_bonus;
    switch (spellProto->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:                      // for melee based spells is 100%
        case SPELL_DAMAGE_CLASS_RANGED:
            crit_bonus = damage;
            break;
        default:
            crit_bonus = damage / 2;                        // for spells is 50%
            break;
    }

    Unit const* pUnit = ToUnit();

    // adds additional damage to crit_bonus (from talents)
    if (pUnit)
    {
        if (Player* modOwner = pUnit->GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_CRIT_DAMAGE_BONUS, crit_bonus, spell);
    }
    

    if (!pVictim)
        return damage += crit_bonus;

    uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();

    float critPctDamageMod = pUnit ? pUnit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, creatureTypeMask) : 1;

    damage = (damage + crit_bonus) * critPctDamageMod;

    return damage;
}

float SpellCaster::SpellCriticalHealingBonus(SpellEntry const* spellProto, uint32 damage, Unit const* pVictim) const
{
    // Calculate critical bonus
    float crit_bonus;
    switch (spellProto->DmgClass)
    {
        case SPELL_DAMAGE_CLASS_MELEE:                      // for melee based spells is 100%
        case SPELL_DAMAGE_CLASS_RANGED:
            // TODO: write here full calculation for melee/ranged spells
            crit_bonus = damage;
            break;
        default:
            crit_bonus = damage / 2;                        // for spells is 50%
            break;
    }

    if (pVictim)
    {
        if (Unit const* pUnit = ToUnit())
        {
            uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();
            crit_bonus = crit_bonus * pUnit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_CRIT_PERCENT_VERSUS, creatureTypeMask);
        }
    }

    if (crit_bonus > 0)
        damage += crit_bonus;

    return damage;
}

int32 SpellCaster::DealHeal(Unit* pVictim, uint32 addhealth, SpellEntry const* spellProto, bool critical)
{
    Unit* pUnit = ToUnit();

    // Script Event HealedBy
    if (pVictim->AI() && pUnit)
        pVictim->AI()->HealedBy(pUnit, addhealth);

    int32 gain = pVictim->ModifyHealth(int32(addhealth));

    SpellCaster* pHealer = this;

    if (IsCreature() && ((Creature*)this)->IsTotem() && ((Totem*)this)->GetTotemType() != TOTEM_STATUE)
        pHealer = pUnit->GetOwner();

    if (IsPlayer() || pVictim->IsPlayer())
        pHealer->SendHealSpellLog(pVictim, spellProto->Id, addhealth, critical);

    return gain;
}

void SpellCaster::SendHealSpellLog(Unit const* pVictim, uint32 SpellID, uint32 Damage, bool critical) const
{
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    // we guess size
    WorldPacket data(SMSG_SPELLHEALLOG, (8 + 8 + 4 + 4 + 1));
    data << pVictim->GetPackGUID();
    data << GetPackGUID();
    data << uint32(SpellID);
    data << uint32(Damage);
    data << uint8(critical ? 1 : 0);
    // data << uint8(0);                                    // [-ZERO]
    SendMessageToSet(&data, true);
#endif
}

void SpellCaster::EnergizeBySpell(Unit* pVictim, uint32 SpellID, uint32 Damage, Powers powertype)
{
    SendEnergizeSpellLog(pVictim, SpellID, Damage, powertype);
    // needs to be called after sending spell log
    pVictim->ModifyPower(powertype, Damage);
}

void SpellCaster::SendEnergizeSpellLog(Unit const* pVictim, uint32 SpellID, uint32 Damage, Powers powertype) const
{
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    WorldPacket data(SMSG_SPELLENERGIZELOG, (8 + 8 + 4 + 4 + 4 + 1));
    data << pVictim->GetPackGUID();
    data << GetPackGUID();
    data << uint32(SpellID);
    data << uint32(powertype);
    data << uint32(Damage);
    SendMessageToSet(&data, true);
#endif
}

void SpellCaster::SendSpellNonMeleeDamageLog(SpellNonMeleeDamage* log)
{
    WorldPacket data(SMSG_SPELLNONMELEEDAMAGELOG, (16 + 4 + 4 + 1 + 4 + 4 + 1 + 1 + 4 + 4 + 1)); // we guess size
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    data << log->target->GetPackGUID();
    data << log->attacker->GetPackGUID();
#else
    data << log->target->GetGUID();
    data << log->attacker->GetGUID();
#endif
    data << uint32(log->SpellID);
    data << uint32(log->damage);                            // damage amount
    data << uint8(log->school);                             // damage school
    data << uint32(log->absorb);                            // AbsorbedDamage
    data << int32(log->resist);                             // resist
    data << uint8(log->periodicLog);                        // if 1, then client show spell name (example: %s's ranged shot hit %s for %u school or %s suffers %u school damage from %s's spell_name
    data << uint8(log->unused);                             // unused
    data << uint32(log->blocked);                           // blocked
    data << uint32(log->HitInfo);
    data << uint8(0);                                       // flag to use extend data
    SendMessageToSet(&data, true);
}

void SpellCaster::SendSpellNonMeleeDamageLog(Unit* target, uint32 spellId, uint32 damage, SpellSchoolMask damageSchoolMask, uint32 absorbedDamage, int32 resist, bool isPeriodic, uint32 blocked, bool criticalHit, bool split)
{
    SpellNonMeleeDamage log(this, target, spellId, GetFirstSchoolInMask(damageSchoolMask));
    log.damage = damage;
    log.damage += (resist < 0 ? uint32(std::abs(resist)) : 0);
    log.damage -= (absorbedDamage + (resist > 0 ? uint32(resist) : 0) + blocked);
    log.absorb = absorbedDamage;
    log.resist = resist;
    log.periodicLog = isPeriodic;
    log.blocked = blocked;
    log.HitInfo = 0;
    if (criticalHit)
        log.HitInfo |= SPELL_HIT_TYPE_CRIT;
    if (split)
        log.HitInfo |= SPELL_HIT_TYPE_SPLIT;
    SendSpellNonMeleeDamageLog(&log);
}

SpellSchoolMask SpellCaster::GetMeleeDamageSchoolMask() const
{
    return SPELL_SCHOOL_MASK_NORMAL;
}

float SpellCaster::CalcArmorReducedDamage(Unit* pVictim, uint32 const damage) const
{
    uint32 newdamage = 0;
    float armor = (float)pVictim->GetArmor();
    Unit const* pUnit = ToUnit();

    // Ignore enemy armor by SPELL_AURA_MOD_TARGET_RESISTANCE aura
    if (pUnit)
        armor += pUnit->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_TARGET_RESISTANCE, SPELL_SCHOOL_MASK_NORMAL);

    if (armor < 0.0f)
        armor = 0.0f;

    float tmpvalue = 0.1f * armor / (8.5f * float(GetLevel()) + 40.0f);
    tmpvalue = tmpvalue / (1.0f + tmpvalue);

    if (tmpvalue < 0.0f)
        tmpvalue = 0.0f;
    if (tmpvalue > 0.75f)
        tmpvalue = 0.75f;

    newdamage = damage - (damage * tmpvalue);

    return (newdamage > 1) ? newdamage : 1;
}

float SpellCaster::CalculateSpellEffectValue(Unit const* target, SpellEntry const* spellProto, SpellEffectIndex effect_index, int32 const* effBasePoints, Spell* spell) const
{
    Unit const* pUnit = ToUnit();
    Player const* pPlayer = ToPlayer();

    uint8 comboPoints = pPlayer ? pPlayer->GetComboPoints() : 0;

    int32 level = GetLevel();

    if (level > (int32)spellProto->maxLevel && spellProto->maxLevel > 0)
        level = (int32)spellProto->maxLevel;
    else if (level < (int32)spellProto->baseLevel)
        level = (int32)spellProto->baseLevel;
    level -= (int32)spellProto->spellLevel;

    int32 baseDice = int32(spellProto->EffectBaseDice[effect_index]);
    float basePointsPerLevel = spellProto->EffectRealPointsPerLevel[effect_index];
    float randomPointsPerLevel = spellProto->EffectDicePerLevel[effect_index];
    float value = effBasePoints
                       ? *effBasePoints - baseDice
                       : spellProto->EffectBasePoints[effect_index];

    value += level * basePointsPerLevel;
    int32 randomPoints = int32(spellProto->EffectDieSides[effect_index] + level * randomPointsPerLevel);
    float comboDamage = spellProto->EffectPointsPerComboPoint[effect_index];

    switch (randomPoints)
    {
        case 0:
        case 1:
            value += baseDice;
            break;              // range 1..1
        default:
        {
            // range can have positive (1..rand) and negative (rand..1) values, so order its for irand
            int32 randvalue = baseDice >= randomPoints
                              ? irand(randomPoints, baseDice)
                              : irand(baseDice, randomPoints);

            value += randvalue;
            break;
        }
    }

    // random damage
    if (comboDamage != 0 && pPlayer && target && (target->GetObjectGuid() == pPlayer->GetComboTargetGuid()))
        value += comboDamage * comboPoints;

    if (pUnit)
    {
        if (Player* modOwner = pUnit->GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_ALL_EFFECTS, value, spell);
    }

    if (spellProto->Attributes & SPELL_ATTR_LEVEL_DAMAGE_CALCULATION && spellProto->spellLevel &&
            spellProto->Effect[effect_index] != SPELL_EFFECT_WEAPON_PERCENT_DAMAGE &&
            spellProto->Effect[effect_index] != SPELL_EFFECT_KNOCK_BACK &&
            (spellProto->Effect[effect_index] != SPELL_EFFECT_APPLY_AURA || spellProto->EffectApplyAuraName[effect_index] != SPELL_AURA_MOD_DECREASE_SPEED))
        value = value * 0.25f * exp(GetLevel() * (70 - spellProto->spellLevel) / 1000.0f);

    return value;
}

void SpellCaster::CalculateSpellDamage(SpellNonMeleeDamage* damageInfo, float damage, SpellEntry const* spellInfo, SpellEffectIndex effectIndex, WeaponAttackType attackType, Spell* spell)
{
    SpellSchoolMask damageSchoolMask = GetSchoolMask(damageInfo->school);
    Unit* pVictim = damageInfo->target;
    if (!pVictim)
        return;

    if (damage < 0)
        return;

    if (!pVictim->IsAlive())
        return;

    // Check spell crit chance
    bool crit = IsSpellCrit(pVictim, spellInfo, damageSchoolMask, attackType, spell);

    // damage bonus (per damage class)
    switch (spellInfo->DmgClass)
    {
        // Melee and Ranged Spells
        case SPELL_DAMAGE_CLASS_RANGED:
        case SPELL_DAMAGE_CLASS_MELEE:
        {
            //Calculate damage bonus
            damage = MeleeDamageBonusDone(pVictim, damage, attackType, spellInfo, effectIndex, SPELL_DIRECT_DAMAGE, 1, spell);
            damage = pVictim->MeleeDamageBonusTaken(this, damage, attackType, spellInfo, effectIndex, SPELL_DIRECT_DAMAGE, 1, spell);

            // if crit add critical bonus
            if (crit)
            {
                damageInfo->HitInfo |= SPELL_HIT_TYPE_CRIT;
                damage = SpellCriticalDamageBonus(spellInfo, damage, pVictim, spell);
            }
            break;
        }
        // Magical Attacks
        case SPELL_DAMAGE_CLASS_NONE:
        case SPELL_DAMAGE_CLASS_MAGIC:
        {
            // Calculate damage bonus
            damage = SpellDamageBonusDone(pVictim, spellInfo, effectIndex, damage, SPELL_DIRECT_DAMAGE, 1, spell);
            damage = pVictim->SpellDamageBonusTaken(this, spellInfo, effectIndex, damage, SPELL_DIRECT_DAMAGE, 1, spell);

            // If crit add critical bonus
            if (crit)
            {
                damageInfo->HitInfo |= SPELL_HIT_TYPE_CRIT;
                damage = SpellCriticalDamageBonus(spellInfo, damage, pVictim, spell);
            }
            break;
        }
    }

    // damage mitigation
    if (damage > 0)
    {
        // physical damage => armor
        if (damageSchoolMask & SPELL_SCHOOL_MASK_NORMAL && !(spellInfo->Custom & SPELL_CUSTOM_IGNORE_ARMOR))
            damage = CalcArmorReducedDamage(pVictim, damage);
    }
    else
        damage = 0;
    damageInfo->damage = ditheru(damage);
}

/**
 * Calculates caster part of melee damage bonuses,
 * also includes different bonuses dependent from target auras
 */
float SpellCaster::MeleeDamageBonusDone(Unit* pVictim, float pdamage, WeaponAttackType attType, SpellEntry const* spellProto, SpellEffectIndex effectIndex, DamageEffectType damagetype, uint32 stack, Spell* spell, bool flat)
{
    if (!pVictim)
        return pdamage;

    if (pdamage == 0)
        return pdamage;

    // differentiate for weapon damage based spells
    bool isWeaponDamageBasedSpell = !(spellProto && (damagetype == DOT || spellProto->HasEffect(SPELL_EFFECT_SCHOOL_DAMAGE)));
    Item* pWeapon          = GetTypeId() == TYPEID_PLAYER ? ((Player*)this)->GetWeaponForAttack(attType, true, false) : nullptr;
    uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();
    uint32 schoolMask       = spellProto ? spellProto->GetSpellSchoolMask() : GetMeleeDamageSchoolMask();

    // FLAT damage bonus auras
    // =======================
    float DoneFlat  = 0;
    float APbonus   = 0;

    Unit* pUnit = ToUnit();

    // ..done flat, already included in weapon damage based spells
    if (pUnit && !isWeaponDamageBasedSpell)
    {
        Unit::AuraList const& mModDamageDone = pUnit->GetAurasByType(SPELL_AURA_MOD_DAMAGE_DONE);
        for (const auto i : mModDamageDone)
        {
            if (i->GetModifier()->m_miscvalue & schoolMask &&                         // schoolmask has to fit with the intrinsic spell school
                    (i->GetModifier()->m_miscvalue & GetMeleeDamageSchoolMask() ||    // AND schoolmask has to fit with weapon damage school (essential for non-physical spells)
                     spellProto->DmgClass == SPELL_DAMAGE_CLASS_RANGED) &&               // Some ranged physical attacks use magic damage, ex. Arcane Shot
                    ((i->GetSpellProto()->EquippedItemClass == -1) ||                     // general, weapon independent
                     (pWeapon && pWeapon->IsFitToSpellRequirements(i->GetSpellProto()))))  // OR used weapon fits aura requirements
                DoneFlat += i->GetModifier()->m_amount;
        }

        // Pets just add their bonus damage to their melee damage
        if (GetTypeId() == TYPEID_UNIT && ((Creature*)this)->IsPet())
            DoneFlat += ((Pet*)this)->GetBonusDamage();
    }

    // ..done flat (by creature type mask)
    if (pUnit)
        DoneFlat += pUnit->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_DAMAGE_DONE_CREATURE, creatureTypeMask);

    // ..done flat (base at attack power for marked target and base at attack power for creature type)
    if (attType == RANGED_ATTACK)
    {
        APbonus += pVictim->GetTotalAuraModifier(SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS);
        if (pUnit)
            APbonus += pUnit->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_RANGED_ATTACK_POWER_VERSUS, creatureTypeMask);
    }
    else
    {
        APbonus += pVictim->GetTotalAuraModifier(SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS);
        if (pUnit)
            APbonus += pUnit->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_MELEE_ATTACK_POWER_VERSUS, creatureTypeMask);
    }

    // PERCENT damage auras
    // ====================
    float DonePercent   = 1.0f;

    // ..done pct, already included in weapon damage based spells
    if (pUnit && !isWeaponDamageBasedSpell)
    {
        Unit::AuraList const& mModDamagePercentDone = pUnit->GetAurasByType(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
        for (const auto i : mModDamagePercentDone)
        {
            if (i->GetModifier()->m_miscvalue & schoolMask &&                         // schoolmask has to fit with the intrinsic spell school
                    i->GetModifier()->m_miscvalue & GetMeleeDamageSchoolMask() &&         // AND schoolmask has to fit with weapon damage school (essential for non-physical spells)
                    ((i->GetSpellProto()->EquippedItemClass == -1) ||                     // general, weapon independent
                     (pWeapon && pWeapon->IsFitToSpellRequirements(i->GetSpellProto()))))  // OR used weapon fits aura requirements
                DonePercent *= (i->GetModifier()->m_amount + 100.0f) / 100.0f;
        }

        if (pUnit && attType == OFF_ATTACK)
            DonePercent *= pUnit->GetModifierValue(UNIT_MOD_DAMAGE_OFFHAND, TOTAL_PCT);                    // no school check required
    }

    // Pet happiness increases damage of Hunter pet melee spells
    if (IsPet() && ((Pet*)this)->getPetType() == HUNTER_PET)
    {
        if (Pet* pet = ((Pet*)this))
        {
            switch (pet->GetHappinessState())
            {
                case HAPPY:     DonePercent *= 1.25; break;
                case CONTENT:   break;
                case UNHAPPY:   DonePercent *= 0.75; break;
            }
        }
    }

    // ..done pct (by creature type mask)
    if (pUnit)
        DonePercent *= pUnit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS, creatureTypeMask);

    // final calculation
    // =================

    float DoneTotal = 0.0f;

    // scaling of non weapon based spells
    if (!isWeaponDamageBasedSpell)
    {
        // apply ap bonus and benefit affected by spell power implicit coeffs and spell level penalties
        DoneTotal = SpellBonusWithCoeffs(spellProto, effectIndex, DoneTotal, DoneFlat, APbonus, damagetype, true, this, spell);
    }
    // weapon damage based spells
    else if (APbonus || DoneFlat)
    {
        bool normalized = spellProto ? spellProto->HasEffect(SPELL_EFFECT_NORMALIZED_WEAPON_DMG) : false;
        DoneTotal += APbonus / 14.0f * GetAPMultiplier(attType, normalized);

        // for weapon damage based spells we still have to apply damage done percent mods
        // (that are already included into pdamage) to not-yet included DoneFlat
        // e.g. from doneVersusCreature, apBonusVs...
        UnitMods unitMod;
        switch (attType)
        {
            default:
            case BASE_ATTACK:
                unitMod = UNIT_MOD_DAMAGE_MAINHAND;
                break;
            case OFF_ATTACK:
                unitMod = UNIT_MOD_DAMAGE_OFFHAND;
                break;
            case RANGED_ATTACK:
                unitMod = UNIT_MOD_DAMAGE_RANGED;
                break;
        }

        DoneTotal += DoneFlat;

        if (pUnit)
            DoneTotal *= pUnit->GetModifierValue(unitMod, TOTAL_PCT);
    }

    if (!flat)
        DoneTotal = 0.0f;

    float tmpDamage = pdamage + DoneTotal * int32(stack) * DonePercent;

    // apply spellmod to Done damage
    if (spellProto && pUnit)
    {
        if (Player* modOwner = pUnit->GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto->Id, damagetype == DOT ? SPELLMOD_DOT : SPELLMOD_DAMAGE, tmpDamage, spell);
    }

    // bonus result can be negative
    return tmpDamage > 0 ? tmpDamage : 0;
}

/**
 * Calculates caster part of healing spell bonuses,
 * also includes different bonuses dependent from target auras
 */
float SpellCaster::SpellHealingBonusDone(Unit* pVictim, SpellEntry const* spellProto, SpellEffectIndex effectIndex, float healamount, DamageEffectType damagetype, uint32 stack, Spell* spell)
{
    Unit* pUnit = ToUnit();

    // For totems get healing bonus from owner (statue isn't totem in fact)
    if (GetTypeId() == TYPEID_UNIT && ((Creature*)this)->IsTotem() && ((Totem*)this)->GetTotemType() != TOTEM_STATUE)
        if (Unit* owner = pUnit->GetOwner())
            return owner->SpellHealingBonusDone(pVictim, spellProto, effectIndex, healamount, damagetype, stack, spell);

    // No heal amount for this class spells
    if (((spellProto->DmgClass == SPELL_DAMAGE_CLASS_NONE) && spellProto->HasAttribute(SPELL_ATTR_PASSIVE)) ||
        (spellProto->Custom & SPELL_CUSTOM_FIXED_DAMAGE))
    {
        //DEBUG_UNIT(this, DEBUG_SPELLS_DAMAGE, "SpellHealingBonusDone[spell=%u]: has fixed damage (SPELL_DAMAGE_CLASS_NONE)", spellProto->Id);
        return healamount < 0 ? 0 : healamount;
    }

    // Healing Done
    // Done total percent damage auras
    float  DoneTotalMod = 1.0f;
    float  DoneTotal = 0;

    if (pUnit)
    {
        // Healing done percent
        Unit::AuraList const& mHealingDonePct = pUnit->GetAurasByType(SPELL_AURA_MOD_HEALING_DONE_PERCENT);
        for (const auto i : mHealingDonePct)
            DoneTotalMod *= (100.0f + i->GetModifier()->m_amount) / 100.0f;

        // done scripted mod (take it from owner)
        Unit* owner = pUnit->GetOwner();
        if (!owner)
            owner = pUnit;

        Unit::AuraList const& mOverrideClassScript = owner->GetAurasByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
        for (const auto i : mOverrideClassScript)
        {
            if (!i->isAffectedOnSpell(spellProto))
                continue;
            switch (i->GetModifier()->m_miscvalue)
            {
                case 4415: // Increased Rejuvenation Healing
                    DoneTotal += i->GetModifier()->m_amount / 4; // 4 ticks
                    break;
                case 3736: // Hateful Totem of the Third Wind / Increased Lesser Healing Wave / Savage Totem of the Third Wind
                    DoneTotal += i->GetModifier()->m_amount;
                    break;
                default:
                    break;
            }
        }
    }

    // Done fixed damage bonus auras
    float DoneAdvertisedBenefit  = SpellBaseHealingBonusDone(spellProto->GetSpellSchoolMask());

    // apply ap bonus and benefit affected by spell power implicit coeffs and spell level penalties
    DoneTotal = SpellBonusWithCoeffs(spellProto, effectIndex, DoneTotal, DoneAdvertisedBenefit, 0, damagetype, true, this, spell);

    // use float as more appropriate for negative values and percent applying
    float heal = (healamount + DoneTotal * int32(stack)) * DoneTotalMod;

    if (pUnit)
    {
        // apply spellmod to Done amount
        if (Player* modOwner = pUnit->GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto->Id, damagetype == DOT ? SPELLMOD_DOT : SPELLMOD_DAMAGE, heal, spell);
    }
    
    //DEBUG_UNIT(this, DEBUG_SPELLS_DAMAGE, "SpellHealingBonusDone[spell=%u]: (base=%u + %i) * %f. HealingPwr=%i", spellProto->Id, healamount, DoneTotal, DoneTotalMod, DoneAdvertisedBenefit);
    return heal < 0 ? 0 : heal;
}

float SpellCaster:: SpellBaseHealingBonusDone(SpellSchoolMask schoolMask)
{
    float AdvertisedBenefit = 0;

    if (Unit* pUnit = ToUnit())
    {
        Unit::AuraList const& mHealingDone = pUnit->GetAurasByType(SPELL_AURA_MOD_HEALING_DONE);
        for (const auto i : mHealingDone)
            if ((i->GetModifier()->m_miscvalue & schoolMask) != 0)
                AdvertisedBenefit += i->GetModifier()->m_amount;

        // Healing bonus of spirit, intellect and strength
        if (GetTypeId() == TYPEID_PLAYER)
        {
            // Healing bonus from stats
            Unit::AuraList const& mHealingDoneOfStatPercent = pUnit->GetAurasByType(SPELL_AURA_MOD_SPELL_HEALING_OF_STAT_PERCENT);
            for (const auto i : mHealingDoneOfStatPercent)
            {
                // 1.12.* have only 1 stat type support
                Stats usedStat = STAT_SPIRIT;
                AdvertisedBenefit += pUnit->GetStat(usedStat) * i->GetModifier()->m_amount / 100.0f;
            }
        }
    }
    
    return AdvertisedBenefit;
}

/**
 * Calculates caster part of spell damage bonuses,
 * also includes different bonuses dependent from target auras
 */
float SpellCaster::SpellDamageBonusDone(Unit* pVictim, SpellEntry const* spellProto, SpellEffectIndex effectIndex, float pdamage, DamageEffectType damagetype, uint32 stack, Spell* spell)
{
    if (!spellProto || !pVictim || damagetype == DIRECT_DAMAGE)
        return pdamage;

    if (spellProto->Custom & SPELL_CUSTOM_FIXED_DAMAGE)
        return pdamage;

    // Ignite damage already includes modifiers
    if (spellProto->IsFitToFamily<SPELLFAMILY_MAGE, CF_MAGE_IGNITE>())
        return pdamage;

    Unit* pUnit = ToUnit();

    // For totems get damage bonus from owner (statue isn't totem in fact)
    if (pUnit && GetTypeId() == TYPEID_UNIT && ((Creature*)this)->IsTotem() && ((Totem*)this)->GetTotemType() != TOTEM_STATUE)
    {
        if (Unit* owner = pUnit->GetOwner())
            return owner->SpellDamageBonusDone(pVictim, spellProto, effectIndex, pdamage, damagetype, stack, spell);
    }

    float DoneTotalMod = 1.0f;
    float DoneTotal = 0;
    Item* pWeapon = GetTypeId() == TYPEID_PLAYER ? ((Player*)this)->GetWeaponForAttack(BASE_ATTACK, true, false) : nullptr;

    // Creature damage
    if (GetTypeId() == TYPEID_UNIT && !((Creature*)this)->IsPet())
        DoneTotalMod *= Creature::_GetSpellDamageMod(((Creature*)this)->GetCreatureInfo()->rank);

    if (pUnit)
    {
        Unit::AuraList const& mModDamagePercentDone = pUnit->GetAurasByType(SPELL_AURA_MOD_DAMAGE_PERCENT_DONE);
        for (const auto i : mModDamagePercentDone)
        {
            if ((i->GetModifier()->m_miscvalue & spellProto->GetSpellSchoolMask()) &&
                i->GetSpellProto()->EquippedItemClass == -1 &&
                spellProto->EquippedItemClass == -1 &&
                // -1 == any item class (not wand then)
                i->GetSpellProto()->EquippedItemInventoryTypeMask == 0)
                // 0 == any inventory type (not wand then)
            {
                DoneTotalMod *= (i->GetModifier()->m_amount + 100.0f) / 100.0f;
            }
            // Paladin seals benefit from weapon modifiers
            else if (i->GetModifier()->m_miscvalue & GetMeleeDamageSchoolMask() &&
                spellProto->SpellFamilyName == SPELLFAMILY_PALADIN && spellProto->IsFitToFamilyMask<CF_PALADIN_SEALS>() &&
                ((i->GetSpellProto()->EquippedItemClass == -1) ||
                (pWeapon && pWeapon->IsFitToSpellRequirements(i->GetSpellProto()))))
            {
                DoneTotalMod *= (i->GetModifier()->m_amount + 100.0f) / 100.0f;
            }
        }
    }

    uint32 creatureTypeMask = pVictim->GetCreatureTypeMask();

    // Add pct bonus from spell damage versus
    if (pUnit)
        DoneTotalMod *= pUnit->GetTotalAuraMultiplierByMiscMask(SPELL_AURA_MOD_DAMAGE_DONE_VERSUS, creatureTypeMask);

    // Add flat bonus from spell damage creature
    if (pUnit)
        DoneTotal += pUnit->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_DAMAGE_DONE_CREATURE, creatureTypeMask);

    // done scripted mod (take it from owner)
    Unit* owner = pUnit ? pUnit->GetOwner() : nullptr;
    if (!owner) owner = pUnit;
    if (owner)
    {
        Unit::AuraList const& mOverrideClassScript = owner->GetAurasByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
        for (const auto i : mOverrideClassScript)
        {
            if (!i->isAffectedOnSpell(spellProto))
                continue;
            switch (i->GetModifier()->m_miscvalue)
            {
            case 4418: // Increased Shock Damage
            case 4554: // Increased Lightning Damage
            case 4555: // Improved Moonfire
            {
                DoneTotal += i->GetModifier()->m_amount;
                break;
            }
            }
        }
    }

    // Pet happiness increases damage of Hunter pet spells (e.g. Lightning Breath)
    if (IsPet() && ((Pet*)this)->getPetType() == HUNTER_PET)
    {
        if (Pet* pet = ((Pet*)this))
        {
            switch (pet->GetHappinessState())
            {
                case HAPPY:     DoneTotalMod *= 1.25; break;
                case CONTENT:   break;
                case UNHAPPY:   DoneTotalMod *= 0.75; break;
            }
        }
    }

    // Done fixed damage bonus auras
    int32 DoneAdvertisedBenefit = SpellBaseDamageBonusDone(spellProto->GetSpellSchoolMask());

    // Add flat bonus from spell damage versus
    if (pUnit)
        DoneAdvertisedBenefit += pUnit->GetTotalAuraModifierByMiscMask(SPELL_AURA_MOD_FLAT_SPELL_DAMAGE_VERSUS, creatureTypeMask);

    // Pets just add their bonus damage to their spell damage
    // note that their spell damage is just gain of their own auras
    if (GetTypeId() == TYPEID_UNIT && ((Creature*)this)->IsPet())
        DoneAdvertisedBenefit += ((Pet*)this)->GetBonusDamage();

    // apply ap bonus and benefit affected by spell power implicit coeffs and spell level penalties
    DoneTotal = SpellBonusWithCoeffs(spellProto, effectIndex, DoneTotal, DoneAdvertisedBenefit, 0, damagetype, true, this, spell);

    float tmpDamage = (pdamage + DoneTotal * int32(stack)) * DoneTotalMod;
    // apply spellmod to Done damage (flat and pct)
    if (pUnit)
    {
        if (Player* modOwner = pUnit->GetSpellModOwner())
            modOwner->ApplySpellMod(spellProto->Id, damagetype == DOT ? SPELLMOD_DOT : SPELLMOD_DAMAGE, tmpDamage, spell);
    }

    //DEBUG_UNIT(this, DEBUG_SPELLS_DAMAGE, "SpellDmgBonus[spell=%u]: (base=%u + %i) * %f. SP=%i", spellProto->Id, pdamage, DoneTotal, DoneTotalMod, DoneAdvertisedBenefit);
    return tmpDamage > 0 ? tmpDamage : 0;
}

int32 SpellCaster::SpellBaseDamageBonusDone(SpellSchoolMask schoolMask)
{
    int32 DoneAdvertisedBenefit = 0;

    if (Unit* pUnit = ToUnit())
    {
        Unit::AuraList const& mDamageDone = pUnit->GetAurasByType(SPELL_AURA_MOD_DAMAGE_DONE);
        for (const auto i : mDamageDone)
        {
            if ((i->GetModifier()->m_miscvalue & schoolMask) != 0 &&
                i->GetSpellProto()->EquippedItemClass == -1 &&                   // -1 == any item class (not wand then)
                i->GetSpellProto()->EquippedItemInventoryTypeMask == 0)          //  0 == any inventory type (not wand then)
                DoneAdvertisedBenefit += i->GetModifier()->m_amount;
        }

        if (GetTypeId() == TYPEID_PLAYER)
        {
            // Damage bonus from stats
            Unit::AuraList const& mDamageDoneOfStatPercent = pUnit->GetAurasByType(SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT);
            for (const auto i : mDamageDoneOfStatPercent)
            {
                if (i->GetModifier()->m_miscvalue & schoolMask)
                {
                    // stat used stored in miscValueB for this aura
                    Stats usedStat = STAT_SPIRIT;
                    DoneAdvertisedBenefit += int32(pUnit->GetStat(usedStat) * i->GetModifier()->m_amount / 100.0f);
                }
            }
        }
    }
    
    return DoneAdvertisedBenefit;
}

float SpellCaster::SpellBonusWithCoeffs(SpellEntry const* spellProto, SpellEffectIndex effectIndex, float total, float benefit, float ap_benefit,  DamageEffectType damagetype, bool donePart, SpellCaster* pCaster, Spell* spell) const
{
    // Distribute Damage over multiple effects, reduce by AoE
    float coeff = 0.0f;

    // Not apply this to creature casted spells
    // Daemon: n'importe quoi. Et apres on se demande pourquoi les degats du sceau du croise sont abuses ...
    //if (GetTypeId()==TYPEID_UNIT && !((Creature*)this)->IsPet())
    //    coeff = 1.0f;
    // Check for table values
    if (spellProto->EffectBonusCoefficient[effectIndex] >= 0.0f)
        coeff = spellProto->EffectBonusCoefficient[effectIndex];
    // Calculate default coefficient
    else if (benefit)
        coeff = spellProto->CalculateDefaultCoefficient(damagetype);

    if (benefit)
    {
        // Calculate level penalty only if spell does not have coefficient set in template,
        // since the coefficients already have the level penalty accounted for.
        float LvlPenalty = (spellProto->EffectBonusCoefficient[effectIndex] >= 0.0f) ? 1.0f : CalculateLevelPenalty(spellProto);

        // Calculate custom coefficient
        coeff = spellProto->CalculateCustomCoefficient(pCaster, damagetype, coeff, spell, donePart);

        // Spellmod SpellDamage
        if (Unit const* pUnit = ToUnit())
        {
            if (Player* modOwner = pUnit->GetSpellModOwner())
            {
                coeff *= 100.0f;
                modOwner->ApplySpellMod(spellProto->Id, SPELLMOD_SPELL_BONUS_DAMAGE, coeff, spell);
                coeff /= 100.0f;
            }
        }
        
        // Nostalrius.
        bool bUsePenalty = true;
        // Flash of Light
        if (spellProto->Id == 19993)
        {
            bUsePenalty = false;
            if (Unit const* pUnit = ToUnit())
            {
                if (pUnit->HasAura(28853)) total += 53.0f;  // Libram of Divinity
                if (pUnit->HasAura(28851)) total += 83.0f;  // Libram of Light
            }
        }

        // Dragonbreath Chili
        if (spellProto->Id == 15851)
            bUsePenalty = false;

        if (bUsePenalty)
            total += benefit * coeff * LvlPenalty;
        else
            total += benefit * coeff;

    }

    return total;
};

void SpellCaster::DealDamageMods(Unit* victim, uint32& damage, uint32* absorb)
{
    Unit* pUnit = ToUnit();
    // [Nostalrius] Pas de degats sous esprit de redemption
    if (!victim->IsAlive() ||
        victim->IsTaxiFlying() ||
        (victim->IsCreature() && static_cast<Creature*>(victim)->IsInEvadeMode()) ||
        (pUnit && pUnit->GetClass() == CLASS_PRIEST && pUnit->HasAura(27827)))
    {
        if (absorb)
            *absorb += damage;
        damage = 0;
        return;
    }

    uint32 originalDamage = damage;

    //Script Event damage Deal
    if (Creature* pCreature = ToCreature())
        if (pCreature->AI())
            pCreature->AI()->DamageDeal(victim, damage);

    //Script Event damage taken
    if (Creature* pCreature = victim->ToCreature())
        if (pCreature->AI() && pUnit)
            pCreature->AI()->DamageTaken(pUnit, damage);

    if (absorb && originalDamage > damage)
        *absorb += (originalDamage - damage);
}

float SpellCaster::CalculateLevelPenalty(SpellEntry const* spellProto)
{
    // Fix Nostalrius. La formule de MaNGOSZero est BC.
    uint32 spellLevel = spellProto->spellLevel;
    if (spellLevel <= 0 || spellLevel > 20)
        return 1.0f;
    return 1 - ((20.0f - spellLevel) * 0.0375f);

    /*
        float LvlPenalty = 0.0f;

        if (spellLevel < 20)
            LvlPenalty = 20.0f - spellLevel * 3.75f;
        float LvlFactor = (float(spellLevel) + 6.0f) / float(GetLevel());
        if (LvlFactor > 1.0f)
            LvlFactor = 1.0f;

        return (100.0f - LvlPenalty) * LvlFactor / 100.0f;
    */
}

float SpellCaster::GetAPMultiplier(WeaponAttackType attType, bool normalized) const
{
    Unit const* pUnit = ToUnit();
    if (!pUnit)
        return 0;

    if (!normalized || GetTypeId() != TYPEID_PLAYER)
        return float(pUnit->GetAttackTime(attType)) / 1000.0f;

    Item* Weapon = ((Player*)this)->GetWeaponForAttack(attType, true, false);
    if (!Weapon)
        return 2.4f;                                         // fist attack

    switch (Weapon->GetProto()->InventoryType)
    {
        case INVTYPE_2HWEAPON:
            return 3.3f;
        case INVTYPE_RANGED:
        case INVTYPE_RANGEDRIGHT:
        case INVTYPE_THROWN:
            return 2.8f;
        case INVTYPE_WEAPON:
        case INVTYPE_WEAPONMAINHAND:
        case INVTYPE_WEAPONOFFHAND:
        default:
            return Weapon->GetProto()->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER ? 1.7f : 2.4f;
    }
}

void SpellCaster::DealSpellDamage(SpellNonMeleeDamage* damageInfo, bool durabilityLoss)
{
    if (!damageInfo)
        return;

    Unit* pVictim = damageInfo->target;

    if (!pVictim)
        return;

    if (!pVictim->IsAlive() || pVictim->IsTaxiFlying() || (pVictim->GetTypeId() == TYPEID_UNIT && ((Creature*)pVictim)->IsInEvadeMode()))
        return;

    SpellEntry const* spellProto = sSpellMgr.GetSpellEntry(damageInfo->SpellID);
    if (spellProto == nullptr)
    {
        sLog.outError("SpellCaster::DealSpellDamage have wrong damageInfo->SpellID: %u", damageInfo->SpellID);
        return;
    }

    // Call default DealDamage (send critical in hit info for threat calculation)
    CleanDamage cleanDamage(0, BASE_ATTACK, damageInfo->HitInfo & SPELL_HIT_TYPE_CRIT ? MELEE_HIT_CRIT : MELEE_HIT_NORMAL, damageInfo->absorb, damageInfo->resist);
    DealDamage(pVictim, damageInfo->damage, &cleanDamage, SPELL_DIRECT_DAMAGE, GetSchoolMask(damageInfo->school), spellProto, durabilityLoss, damageInfo->spell);
}

uint32 SpellCaster::DealDamage(Unit* pVictim, uint32 damage, CleanDamage const* cleanDamage, DamageEffectType damagetype, SpellSchoolMask damageSchoolMask, SpellEntry const* spellProto, bool durabilityLoss, Spell* spell)
{
    // Should never happen since DealDamage is overriden in Unit class.
    if (pVictim == this)
        return 0;

    return pVictim->DealDamage(pVictim, damage, cleanDamage, damagetype, damageSchoolMask, spellProto, durabilityLoss, spell);
}

bool SpellCaster::CheckAndIncreaseCastCounter()
{
    uint32 maxCasts = sWorld.getConfig(CONFIG_UINT32_MAX_SPELL_CASTS_IN_CHAIN);

    if (maxCasts && m_castCounter >= maxCasts)
        return false;

    ++m_castCounter;
    return true;
}

void SpellCaster::SetCurrentCastedSpell(Spell* pSpell)
{
    MANGOS_ASSERT(pSpell);                                  // nullptr may be never passed here, use InterruptSpell or InterruptNonMeleeSpells

    CurrentSpellTypes CSpellType = pSpell->GetCurrentContainer();

    if (pSpell == m_currentSpells[CSpellType]) return;      // avoid breaking self
    // break same type spell if it is not delayed
    InterruptSpell(CSpellType, false);

    // special breakage effects:
    switch (CSpellType)
    {
        case CURRENT_GENERIC_SPELL:
        {
            // generic spells always break channeled not delayed spells
            InterruptSpell(CURRENT_CHANNELED_SPELL, false);

            // autorepeat breaking
            if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL])
            {
                // break autorepeat if not Auto Shot
                if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Category == 351)
                    InterruptSpell(CURRENT_AUTOREPEAT_SPELL);

                if (Unit* pUnit = ToUnit())
                    pUnit->m_AutoRepeatFirstCast = true;
            }
        }
        break;

        case CURRENT_CHANNELED_SPELL:
        {
            // channel spells always break generic non-delayed and any channeled spells
            InterruptSpell(CURRENT_GENERIC_SPELL, false);
            InterruptSpell(CURRENT_CHANNELED_SPELL);

            // it also does break autorepeat if not Auto Shot
            if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL] &&
                    m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Category == 351)
                InterruptSpell(CURRENT_AUTOREPEAT_SPELL);
        }
        break;

        case CURRENT_AUTOREPEAT_SPELL:
        {
            // only Auto Shoot does not break anything
            if (pSpell->m_spellInfo->Category == 351)
            {
                // generic autorepeats break generic non-delayed and channeled non-delayed spells
                InterruptSpell(CURRENT_GENERIC_SPELL, false);
                InterruptSpell(CURRENT_CHANNELED_SPELL, false);
            }
            // special action: set first cast flag
            if (Unit* pUnit = ToUnit())
                pUnit->m_AutoRepeatFirstCast = true;
        }
        break;

        default:
        {
            // other spell types don't break anything now
        } break;
    }

    // current spell (if it is still here) may be safely deleted now
    if (m_currentSpells[CSpellType])
        m_currentSpells[CSpellType]->SetReferencedFromCurrent(false);

    // set new current spell
    m_currentSpells[CSpellType] = pSpell;
    pSpell->SetReferencedFromCurrent(true);

    pSpell->m_selfContainer = &(m_currentSpells[pSpell->GetCurrentContainer()]);
}

Spell* SpellCaster::FindCurrentSpellBySpellId(uint32 spell_id) const
{
    for (uint32 i = 0; i < CURRENT_MAX_SPELL; ++i)
        if (m_currentSpells[i] && m_currentSpells[i]->m_spellInfo->Id == spell_id)
            return m_currentSpells[i];
    return nullptr;
}

bool SpellCaster::IsNonMeleeSpellCasted(bool withDelayed, bool skipChanneled, bool skipAutorepeat) const
{
    // We don't do loop here to explicitly show that melee spell is excluded.
    // Maybe later some special spells will be excluded too.

    // generic spells are casted when they are not finished and not delayed
    if (m_currentSpells[CURRENT_GENERIC_SPELL] &&
            (m_currentSpells[CURRENT_GENERIC_SPELL]->getState() != SPELL_STATE_FINISHED) &&
            (withDelayed || m_currentSpells[CURRENT_GENERIC_SPELL]->getState() != SPELL_STATE_DELAYED))
        return (true);

    // channeled spells may be delayed, but they are still considered casted
    else if (!skipChanneled && m_currentSpells[CURRENT_CHANNELED_SPELL] &&
             (m_currentSpells[CURRENT_CHANNELED_SPELL]->getState() != SPELL_STATE_FINISHED))
        return (true);

    // autorepeat spells may be finished or delayed, but they are still considered casted
    else if (!skipAutorepeat && m_currentSpells[CURRENT_AUTOREPEAT_SPELL])
        return (true);

    return (false);
}

bool SpellCaster::IsNextSwingSpellCasted() const
{
    if (m_currentSpells[CURRENT_MELEE_SPELL] && m_currentSpells[CURRENT_MELEE_SPELL]->m_spellInfo->IsNextMeleeSwingSpell())
        return (true);

    return (false);
}

bool SpellCaster::IsNoMovementSpellCasted() const
{
    if (m_currentSpells[CURRENT_GENERIC_SPELL] &&
            (m_currentSpells[CURRENT_GENERIC_SPELL]->getState() != SPELL_STATE_FINISHED) &&
             m_currentSpells[CURRENT_GENERIC_SPELL]->getState() != SPELL_STATE_DELAYED &&
             m_currentSpells[CURRENT_GENERIC_SPELL]->m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT)
        return (true);
    else if (m_currentSpells[CURRENT_CHANNELED_SPELL] &&
             m_currentSpells[CURRENT_CHANNELED_SPELL]->getState() != SPELL_STATE_FINISHED &&
             m_currentSpells[CURRENT_CHANNELED_SPELL]->m_spellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_MOVEMENT)
        return (true);
    // don't need to check for AUTOREPEAT_SPELL

    return (false);
}

void SpellCaster::InterruptSpellsWithInterruptFlags(uint32 flags, uint32 except)
{
    for (uint32 i = CURRENT_FIRST_NON_MELEE_SPELL; i < CURRENT_MAX_SPELL; ++i)
        if (Spell* spell = GetCurrentSpell(CurrentSpellTypes(i)))
            if (spell->GetCastedTime() && (spell->getState() == SPELL_STATE_PREPARING || (spell->IsChanneled() && spell->getState() == SPELL_STATE_CASTING)))
                if (!spell->m_spellInfo->IsNextMeleeSwingSpell() && !spell->IsAutoRepeat() && !spell->IsTriggered() && (spell->m_spellInfo->InterruptFlags & flags) && spell->m_spellInfo->Id != except)
                    InterruptSpell(CurrentSpellTypes(i));
}

void SpellCaster::InterruptSpellsWithChannelFlags(uint32 flags, uint32 except)
{
    if (Spell* spell = m_currentSpells[CURRENT_CHANNELED_SPELL])
        if (spell->getState() == SPELL_STATE_CASTING)
            if ((spell->m_spellInfo->ChannelInterruptFlags & flags) && spell->m_spellInfo->Id != except)
                InterruptSpell(CURRENT_CHANNELED_SPELL);
}

void SpellCaster::InterruptNonMeleeSpells(bool withDelayed, uint32 spell_id)
{
    // generic spells are interrupted if they are not finished or delayed
    if (m_currentSpells[CURRENT_GENERIC_SPELL] && (!spell_id || m_currentSpells[CURRENT_GENERIC_SPELL]->m_spellInfo->Id == spell_id))
        InterruptSpell(CURRENT_GENERIC_SPELL, withDelayed);

    // autorepeat spells are interrupted if they are not finished or delayed
    if (m_currentSpells[CURRENT_AUTOREPEAT_SPELL] && (!spell_id || m_currentSpells[CURRENT_AUTOREPEAT_SPELL]->m_spellInfo->Id == spell_id))
        InterruptSpell(CURRENT_AUTOREPEAT_SPELL, withDelayed);

    // channeled spells are interrupted if they are not finished, even if they are delayed
    if (m_currentSpells[CURRENT_CHANNELED_SPELL] && (!spell_id || m_currentSpells[CURRENT_CHANNELED_SPELL]->m_spellInfo->Id == spell_id))
        InterruptSpell(CURRENT_CHANNELED_SPELL, true);
}

void SpellCaster::InterruptSpell(CurrentSpellTypes spellType, bool withDelayed)
{
    MANGOS_ASSERT(spellType < CURRENT_MAX_SPELL);

    if (m_currentSpells[spellType] && (withDelayed || m_currentSpells[spellType]->getState() != SPELL_STATE_DELAYED))
    {
        // send autorepeat cancel message for autorepeat spells
        if (spellType == CURRENT_AUTOREPEAT_SPELL)
        {
            if (GetTypeId() == TYPEID_PLAYER)
                ((Player*)this)->SendAutoRepeatCancel();
        }

        if (m_currentSpells[spellType]->getState() != SPELL_STATE_FINISHED)
            m_currentSpells[spellType]->cancel();

        // cancel can interrupt spell already (caster cancel ->target aura remove -> caster iterrupt)
        if (m_currentSpells[spellType])
        {
            m_currentSpells[spellType]->SetReferencedFromCurrent(false);
            m_currentSpells[spellType] = nullptr;
        }
    }
}

void SpellCaster::FinishSpell(CurrentSpellTypes spellType, bool ok /*= true*/)
{
    Spell* spell = m_currentSpells[spellType];
    if (!spell)
        return;

    if (spellType == CURRENT_CHANNELED_SPELL)
        spell->SendChannelUpdate(0);

    spell->finish(ok);
}

void SpellCaster::GetDynObjects(uint32 spellId, SpellEffectIndex effectIndex, std::vector<DynamicObject*>& dynObjsOut)
{
    for (DynObjectGUIDs::iterator i = m_dynObjGUIDs.begin(); i != m_dynObjGUIDs.end();)
    {
        DynamicObject* dynObj = GetMap()->GetDynamicObject(*i);
        if (!dynObj)
        {
            i = m_dynObjGUIDs.erase(i);
            continue;
        }

        if (dynObj->GetSpellId() == spellId && dynObj->GetEffIndex() == effectIndex)
            dynObjsOut.push_back(dynObj);
        ++i;
    }
}

DynamicObject* SpellCaster::GetDynObject(uint32 spellId, SpellEffectIndex effIndex)
{
    for (DynObjectGUIDs::iterator i = m_dynObjGUIDs.begin(); i != m_dynObjGUIDs.end();)
    {
        DynamicObject* dynObj = GetMap()->GetDynamicObject(*i);
        if (!dynObj)
        {
            i = m_dynObjGUIDs.erase(i);
            continue;
        }

        if (dynObj->GetSpellId() == spellId && dynObj->GetEffIndex() == effIndex)
            return dynObj;
        ++i;
    }
    return nullptr;
}

DynamicObject* SpellCaster::GetDynObject(uint32 spellId)
{
    for (DynObjectGUIDs::iterator i = m_dynObjGUIDs.begin(); i != m_dynObjGUIDs.end();)
    {
        DynamicObject* dynObj = GetMap()->GetDynamicObject(*i);
        if (!dynObj)
        {
            i = m_dynObjGUIDs.erase(i);
            continue;
        }

        if (dynObj->GetSpellId() == spellId)
            return dynObj;
        ++i;
    }
    return nullptr;
}

void SpellCaster::AddDynObject(DynamicObject* dynObj)
{
    m_dynObjGUIDs.push_back(dynObj->GetObjectGuid());
    dynObj->SetWorldMask(GetWorldMask()); // Nostalrius : phasing
}

void SpellCaster::RemoveDynObject(uint32 spellid)
{
    if (m_dynObjGUIDs.empty())
        return;
    for (DynObjectGUIDs::iterator i = m_dynObjGUIDs.begin(); i != m_dynObjGUIDs.end();)
    {
        DynamicObject* dynObj = GetMap()->GetDynamicObject(*i);
        if (!dynObj)
            i = m_dynObjGUIDs.erase(i);
        else if (spellid == 0 || dynObj->GetSpellId() == spellid)
        {
            dynObj->Delete();
            i = m_dynObjGUIDs.erase(i);
        }
        else
            ++i;
    }
}

void SpellCaster::RemoveAllDynObjects()
{
    while (!m_dynObjGUIDs.empty())
    {
        if (DynamicObject* dynObj = GetMap()->GetDynamicObject(*m_dynObjGUIDs.begin()))
            dynObj->Delete();
        m_dynObjGUIDs.erase(m_dynObjGUIDs.begin());
    }
}

SpellCastResult SpellCaster::CastSpell(SpellCaster* pTarget, uint32 spellId, bool triggered, Item* castItem, Aura* triggeredByAura, ObjectGuid originalCaster, SpellEntry const* triggeredBy, SpellEntry const* triggeredByParent)
{
    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellId);

    if (!spellInfo)
    {
        if (triggeredByAura)
            sLog.outError("CastSpell: unknown spell id %i by caster: %s triggered by aura %u (eff %u)", spellId, GetGuidStr().c_str(), triggeredByAura->GetId(), triggeredByAura->GetEffIndex());
        else
            sLog.outError("CastSpell: unknown spell id %i by caster: %s", spellId, GetGuidStr().c_str());
        return SPELL_FAILED_SPELL_UNAVAILABLE;
    }

    return CastSpell(pTarget, spellInfo, triggered, castItem, triggeredByAura, originalCaster, triggeredBy, triggeredByParent);
}

SpellCastResult SpellCaster::CastSpell(SpellCaster* pTarget, SpellEntry const* spellInfo, bool triggered, Item* castItem, Aura* triggeredByAura, ObjectGuid originalCaster, SpellEntry const* triggeredBy, SpellEntry const* triggeredByParent)
{
    if (!spellInfo)
    {
        if (triggeredByAura)
            sLog.outError("CastSpell: unknown spell by caster: %s triggered by aura %u (eff %u)", GetGuidStr().c_str(), triggeredByAura->GetId(), triggeredByAura->GetEffIndex());
        else
            sLog.outError("CastSpell: unknown spell by caster: %s", GetGuidStr().c_str());
        return SPELL_FAILED_SPELL_UNAVAILABLE;
    }

    if (castItem)
        DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "WORLD: cast Item spellId - %i", spellInfo->Id);

    if (triggeredByAura)
    {
        if (!originalCaster)
            originalCaster = triggeredByAura->GetCasterGuid();

        triggeredBy = triggeredByAura->GetSpellProto();
    }

    Spell* spell;

    if (Unit* pUnit = ToUnit())
        spell = new Spell(pUnit, spellInfo, triggered, originalCaster, triggeredBy, nullptr, triggeredByParent);
    else if (GameObject* pGameObject = ToGameObject())
        spell = new Spell(pGameObject, spellInfo, triggered, originalCaster, triggeredBy, nullptr, triggeredByParent);
    else
        return SPELL_FAILED_ERROR;

    SpellCastTargets targets;

    // Don't set unit target on destination target based spells, otherwise the spell will cancel
    // as soon as the target dies or leaves the area of the effect
    if (spellInfo->Targets & TARGET_FLAG_DEST_LOCATION)
        targets.setDestination(pTarget->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ());
    else if (Unit* pUnitTarget = pTarget->ToUnit())
        targets.setUnitTarget(pUnitTarget);
    else if (GameObject* pGoTarget = pTarget->ToGameObject())
        targets.setGOTarget(pGoTarget);
    else
        return SPELL_FAILED_ERROR;

    if (spellInfo->Targets & TARGET_FLAG_SOURCE_LOCATION)
        if (SpellCaster* caster = spell->GetCastingObject())
            targets.setSource(caster->GetPositionX(), caster->GetPositionY(), caster->GetPositionZ());

    spell->SetCastItem(castItem);
    return spell->prepare(std::move(targets), triggeredByAura);
}

void SpellCaster::CastCustomSpell(Unit* pTarget, uint32 spellId, optional<int32> bp0, optional<int32> bp1, optional<int32> bp2, bool triggered, Item* castItem, Aura* triggeredByAura, ObjectGuid originalCaster, SpellEntry const* triggeredBy)
{
    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellId);

    if (!spellInfo)
    {
        if (triggeredByAura)
            sLog.outError("CastCustomSpell: unknown spell id %i by caster: %s triggered by aura %u (eff %u)", spellId, GetGuidStr().c_str(), triggeredByAura->GetId(), triggeredByAura->GetEffIndex());
        else
            sLog.outError("CastCustomSpell: unknown spell id %i by caster: %s", spellId, GetGuidStr().c_str());
        return;
    }

    CastCustomSpell(pTarget, spellInfo, bp0, bp1, bp2, triggered, castItem, triggeredByAura, originalCaster, triggeredBy);
}

void SpellCaster::CastCustomSpell(Unit* pTarget, SpellEntry const* spellInfo, optional<int32> bp0, optional<int32> bp1, optional<int32> bp2, bool triggered, Item* castItem, Aura* triggeredByAura, ObjectGuid originalCaster, SpellEntry const* triggeredBy)
{
    if (!spellInfo)
    {
        if (triggeredByAura)
            sLog.outError("CastCustomSpell: unknown spell by caster: %s triggered by aura %u (eff %u)", GetGuidStr().c_str(), triggeredByAura->GetId(), triggeredByAura->GetEffIndex());
        else
            sLog.outError("CastCustomSpell: unknown spell by caster: %s", GetGuidStr().c_str());
        return;
    }

    if (castItem)
        DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "WORLD: cast Item spellId - %i", spellInfo->Id);

    if (triggeredByAura)
    {
        if (!originalCaster)
            originalCaster = triggeredByAura->GetCasterGuid();

        triggeredBy = triggeredByAura->GetSpellProto();
    }

    Spell* spell;

    if (Unit* pUnit = ToUnit())
        spell = new Spell(pUnit, spellInfo, triggered, originalCaster, triggeredBy);
    else if (GameObject* pGameObject = ToGameObject())
        spell = new Spell(pGameObject, spellInfo, triggered, originalCaster, triggeredBy);
    else
        return;

    if (bp0)
        spell->m_currentBasePoints[EFFECT_INDEX_0] = *bp0;

    if (bp1)
        spell->m_currentBasePoints[EFFECT_INDEX_1] = *bp1;

    if (bp2)
        spell->m_currentBasePoints[EFFECT_INDEX_2] = *bp2;

    SpellCastTargets targets;
    targets.setUnitTarget(pTarget);
    spell->SetCastItem(castItem);
    spell->prepare(std::move(targets), triggeredByAura);
}

// used for scripting
SpellCastResult SpellCaster::CastSpell(float x, float y, float z, uint32 spellId, bool triggered, Item* castItem, Aura* triggeredByAura, ObjectGuid originalCaster, SpellEntry const* triggeredBy)
{
    SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spellId);

    if (!spellInfo)
    {
        if (triggeredByAura)
            sLog.outError("CastSpell(x,y,z): unknown spell id %i by caster: %s triggered by aura %u (eff %u)", spellId, GetGuidStr().c_str(), triggeredByAura->GetId(), triggeredByAura->GetEffIndex());
        else
            sLog.outError("CastSpell(x,y,z): unknown spell id %i by caster: %s", spellId, GetGuidStr().c_str());
        return SPELL_FAILED_SPELL_UNAVAILABLE;
    }

    return CastSpell(x, y, z, spellInfo, triggered, castItem, triggeredByAura, originalCaster, triggeredBy);
}

// used for scripting
SpellCastResult SpellCaster::CastSpell(float x, float y, float z, SpellEntry const* spellInfo, bool triggered, Item* castItem, Aura* triggeredByAura, ObjectGuid originalCaster, SpellEntry const* triggeredBy)
{
    if (!spellInfo)
    {
        if (triggeredByAura)
            sLog.outError("CastSpell(x,y,z): unknown spell by caster: %s triggered by aura %u (eff %u)", GetGuidStr().c_str(), triggeredByAura->GetId(), triggeredByAura->GetEffIndex());
        else
            sLog.outError("CastSpell(x,y,z): unknown spell by caster: %s", GetGuidStr().c_str());
        return SPELL_FAILED_SPELL_UNAVAILABLE;
    }

    if (castItem)
        DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "WORLD: cast Item spellId - %i", spellInfo->Id);

    if (triggeredByAura)
    {
        if (!originalCaster)
            originalCaster = triggeredByAura->GetCasterGuid();

        triggeredBy = triggeredByAura->GetSpellProto();
    }

    Spell* spell;

    if (Unit* pUnit = ToUnit())
        spell = new Spell(pUnit, spellInfo, triggered, originalCaster, triggeredBy);
    else if (GameObject* pGameObject = ToGameObject())
        spell = new Spell(pGameObject, spellInfo, triggered, originalCaster, triggeredBy);
    else
        return SPELL_FAILED_ERROR;

    SpellCastTargets targets;
    targets.setDestination(x, y, z);
    spell->SetCastItem(castItem);
    return spell->prepare(std::move(targets), triggeredByAura);
}

void SpellCaster::AddGCD(SpellEntry const& spellEntry, uint32 forcedDuration /*= 0*/, bool /*updateClient = false*/)
{
    uint32 gcdRecTime = forcedDuration ? forcedDuration : spellEntry.StartRecoveryTime;
    if (!gcdRecTime)
        return;

    m_GCDCatMap.emplace(spellEntry.StartRecoveryCategory, std::chrono::milliseconds(gcdRecTime) + sWorld.GetCurrentClockTime());
}

bool SpellCaster::HasGCD(SpellEntry const* spellEntry) const
{
    if (spellEntry)
    {
        auto gcdItr = m_GCDCatMap.find(spellEntry->StartRecoveryCategory);
        return gcdItr != m_GCDCatMap.end();
    }

    return !m_GCDCatMap.empty();
}

void SpellCaster::AddCooldown(SpellEntry const& spellEntry, ItemPrototype const* /*itemProto = nullptr*/, bool /*permanent = false*/, uint32 forcedDuration /*= 0*/)
{
    uint32 recTimeDuration = forcedDuration ? forcedDuration : spellEntry.RecoveryTime;
    if (recTimeDuration || spellEntry.CategoryRecoveryTime)
        m_cooldownMap.AddCooldown(sWorld.GetCurrentClockTime(), spellEntry.Id, recTimeDuration, spellEntry.Category, spellEntry.CategoryRecoveryTime);
}

void SpellCaster::UpdateCooldowns(TimePoint const& now)
{
    // handle GCD
    auto cdItr = m_GCDCatMap.begin();
    while (cdItr != m_GCDCatMap.end())
    {
        auto& cd = cdItr->second;
        if (cd <= now)
            cdItr = m_GCDCatMap.erase(cdItr);
        else
            ++cdItr;
    }

    // handle spell and category cooldowns
    m_cooldownMap.Update(now);

    // handle spell lockouts
    auto lockoutCDItr = m_lockoutMap.begin();
    while (lockoutCDItr != m_lockoutMap.end())
    {
        if (lockoutCDItr->second <= now)
            lockoutCDItr = m_lockoutMap.erase(lockoutCDItr);
        else
            ++lockoutCDItr;
    }
}

bool SpellCaster::CheckLockout(SpellSchoolMask schoolMask) const
{
    for (auto& lockoutItr : m_lockoutMap)
    {
        SpellSchoolMask lockoutSchoolMask = SpellSchoolMask(1 << lockoutItr.first);
        if (lockoutSchoolMask & schoolMask)
            return true;
    }

    return false;
}

bool SpellCaster::GetExpireTime(SpellEntry const& spellEntry, TimePoint& expireTime, bool& isPermanent) const
{
    auto spellItr = m_cooldownMap.FindBySpellId(spellEntry.Id);
    if (spellItr != m_cooldownMap.end())
    {
        auto& cdData = spellItr->second;
        if (cdData->IsPermanent())
        {
            isPermanent = true;
            return true;
        }

        TimePoint spellExpireTime = TimePoint();
        TimePoint catExpireTime = TimePoint();
        bool foundSpellCD = cdData->GetSpellCDExpireTime(spellExpireTime);
        bool foundCatCD = cdData->GetSpellCDExpireTime(catExpireTime);
        if (foundCatCD || foundSpellCD)
        {
            expireTime = spellExpireTime > catExpireTime ? spellExpireTime : catExpireTime;
            return true;
        }
    }
    return false;
}

bool SpellCaster::IsSpellReady(SpellEntry const& spellEntry, ItemPrototype const* itemProto /*= nullptr*/) const
{
    uint32 spellCategory = spellEntry.Category;

    // overwrite category by provided category in item prototype during item cast if need
    if (itemProto)
    {
        for (const auto& Spell : itemProto->Spells)
        {
            if (Spell.SpellId == spellEntry.Id)
            {
                spellCategory = Spell.SpellCategory;
                break;
            }
        }
    }

    if (m_cooldownMap.FindBySpellId(spellEntry.Id) != m_cooldownMap.end())
        return false;

    if (spellCategory && m_cooldownMap.FindByCategory(spellCategory) != m_cooldownMap.end())
        return false;

    if (spellEntry.PreventionType == SPELL_PREVENTION_TYPE_SILENCE && CheckLockout(spellEntry.GetSpellSchoolMask()))
        return false;

    return true;
}

bool SpellCaster::IsSpellReady(uint32 spellId, ItemPrototype const* itemProto /*= nullptr*/) const
{
    SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(spellId);
    if (!spellEntry)
        return false;

    return IsSpellReady(*spellEntry, itemProto);
}

void SpellCaster::LockOutSpells(SpellSchoolMask schoolMask, uint32 duration)
{
    for (uint32 i = 0; i < MAX_SPELL_SCHOOL; ++i)
    {
        if (schoolMask & (1 << i))
            m_lockoutMap.emplace(SpellSchools(i), std::chrono::milliseconds(duration) + sWorld.GetCurrentClockTime());
    }
}

void SpellCaster::RemoveSpellCooldown(uint32 spellId, bool updateClient /*= true*/)
{
    SpellEntry const* spellEntry = sSpellMgr.GetSpellEntry(spellId);
    if (!spellEntry)
        return;

    RemoveSpellCooldown(*spellEntry, updateClient);
}

void SpellCaster::RemoveSpellCooldown(SpellEntry const& spellEntry, bool /*updateClient = true*/)
{
    m_cooldownMap.RemoveBySpellId(spellEntry.Id);
}

void SpellCaster::RemoveSpellCategoryCooldown(uint32 category, bool /*updateClient = true*/)
{
    m_cooldownMap.RemoveByCategory(category);
}

void SpellCaster::ResetGCD(SpellEntry const* spellEntry /*= nullptr*/)
{
    if (!spellEntry)
    {
        m_GCDCatMap.clear();
        return;
    }

    auto gcdItr = m_GCDCatMap.find(spellEntry->StartRecoveryCategory);
    if (gcdItr != m_GCDCatMap.end())
        m_GCDCatMap.erase(gcdItr);
}

void ConvertMillisecondToStr(std::chrono::milliseconds& duration, std::stringstream& durationStr)
{
    std::chrono::minutes mm = std::chrono::duration_cast<std::chrono::minutes>(duration % std::chrono::hours(1));
    std::chrono::seconds ss = std::chrono::duration_cast<std::chrono::seconds>(duration % std::chrono::minutes(1));
    std::chrono::milliseconds msec = std::chrono::duration_cast<std::chrono::milliseconds>(duration % std::chrono::seconds(1));
    durationStr << mm.count() << "m " << ss.count() << "s " << msec.count() << "ms";
}

void SpellCaster::PrintCooldownList(ChatHandler& chat) const
{
    // print gcd
    auto now = sWorld.GetCurrentClockTime();
    uint32 cdCount = 0;
    uint32 permCDCount = 0;

    for (auto& cdItr : m_GCDCatMap)
    {
        auto& cdData = cdItr.second;
        std::stringstream cdLine;
        std::stringstream durationStr;
        if (cdData > now)
        {
            auto cdDuration = cdData - now;
            ConvertMillisecondToStr(cdDuration, durationStr);
            ++cdCount;
        }
        else
            continue;

        cdLine << "GCD category" << "(" << cdItr.first << ") have " << durationStr.str() << " cd";
        chat.PSendSysMessage("%s", cdLine.str().c_str());
    }

    // print spell and category cd
    for (auto& cdItr : m_cooldownMap)
    {
        auto& cdData = cdItr.second;
        std::stringstream cdLine;
        std::stringstream durationStr("permanent");
        std::stringstream spellStr;
        std::stringstream catStr;
        if (cdData->IsPermanent())
            ++permCDCount;
        else
        {
            TimePoint spellExpireTime;
            TimePoint catExpireTime;
            bool foundSpellCD = cdData->GetSpellCDExpireTime(spellExpireTime);
            bool foundcatCD = cdData->GetCatCDExpireTime(catExpireTime);

            if (foundSpellCD && spellExpireTime > now)
            {
                auto cdDuration = std::chrono::duration_cast<std::chrono::milliseconds>(spellExpireTime - now);
                spellStr << "RecTime(";
                ConvertMillisecondToStr(cdDuration, spellStr);
                spellStr << ")";
            }

            if (foundcatCD && catExpireTime > now)
            {
                auto cdDuration = std::chrono::duration_cast<std::chrono::milliseconds>(catExpireTime - now);
                if (foundSpellCD)
                    catStr << ", ";
                catStr << "CatRecTime(";
                ConvertMillisecondToStr(cdDuration, catStr);
                catStr << ")";
            }

            if (!foundSpellCD && !foundcatCD)
                continue;

            durationStr << spellStr.str() << catStr.str();
            ++cdCount;
        }

        cdLine << "Spell" << "(" << cdItr.first << ") have " << durationStr.str() << " cd";
        chat.PSendSysMessage("%s", cdLine.str().c_str());
    }

    // print spell lockout
    static std::string schoolName[] = { "SPELL_SCHOOL_NORMAL", "SPELL_SCHOOL_HOLY", "SPELL_SCHOOL_FIRE", "SPELL_SCHOOL_NATURE", "SPELL_SCHOOL_FROST", "SPELL_SCHOOL_SHADOW", "SPELL_SCHOOL_ARCANE" };

    for (auto& lockoutItr : m_lockoutMap)
    {
        std::stringstream cdLine;
        std::stringstream durationStr;
        auto& cdData = lockoutItr.second;
        if (cdData > now)
        {
            auto cdDuration = std::chrono::duration_cast<std::chrono::milliseconds>(cdData - now);
            ConvertMillisecondToStr(cdDuration, durationStr);
            ++cdCount;
        }
        else
            continue;
        cdLine << "LOCKOUT for " << schoolName[lockoutItr.first] << " with " << durationStr.str() << " remaining time cd";
        chat.PSendSysMessage("%s", cdLine.str().c_str());
    }

    chat.PSendSysMessage("Found %u cooldown%s.", cdCount, (cdCount > 1) ? "s" : "");
    chat.PSendSysMessage("Found %u permanent cooldown%s.", permCDCount, (permCDCount > 1) ? "s" : "");
}
