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

#include "Common.h"
#include "CellImpl.h"
#include "Containers.h"
#include "DynamicObject.h"
#include "GridNotifiersImpl.h"
#include "Item.h"
#include "WorldPacket.h"
#include "WorldSession.h"
#include "Opcodes.h"
#include "Log.h"
#include "World.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Player.h"
#include "PlayerAI.h"
#include "UpdateMask.h"
#include "Spell.h"
#include "DynamicObject.h"
#include "Group.h"
#include "ObjectAccessor.h"
#include "Totem.h"
#include "Creature.h"
#include "Formulas.h"
#include "BattleGround.h"
#include "CreatureAI.h"
#include "ScriptMgr.h"
#include "Util.h"
#include "Vehicle.h"
#include "World.h"
#include <sstream>
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "CellImpl.h"
#include "MapManager.h"
#include "MoveSpline.h"
#include "MovementPacketSender.h"
#include "ZoneScript.h"

class ChargeDropEvent : public BasicEvent
{
public:
    ChargeDropEvent(Aura* base, AuraRemoveMode mode) : _base(base), _mode(mode) { }
    bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) override
    {
        // _base is always valid (look in Aura::_Remove())
        _base->ModChargesDelayed(-1, _mode);
        return true;
    }

private:
    Aura* _base;
    AuraRemoveMode _mode;
};

AuraCreateInfo::AuraCreateInfo(ObjectGuid castId, SpellInfo const* spellInfo, Difficulty castDifficulty, uint32 auraEffMask, WorldObject* owner) :
    _castId(castId), _spellInfo(spellInfo), _castDifficulty(castDifficulty), _auraEffectMask(auraEffMask), _owner(owner)
{
    ASSERT(spellInfo);
    ASSERT(auraEffMask);
    ASSERT(owner);

    ASSERT(auraEffMask <= MAX_EFFECT_MASK);
}

AuraApplication::AuraApplication(Unit* target, Unit* caster, Aura* aura, uint32 effMask) :
_target(target), _base(aura), _removeMode(AURA_REMOVE_NONE), _slot(MAX_AURAS),
_flags(AFLAG_NONE), _effectsToApply(effMask), _needClientUpdate(false), _effectMask(0)
using namespace Spells;

#define NULL_AURA_SLOT 0xFF

/**
 * An array with all the different handlers for taking care of
 * the various aura types that are defined in AuraType.
 */
pAuraHandler AuraHandler[TOTAL_AURAS] =
{
    &Aura::HandleNULL,                                      //  0 SPELL_AURA_NONE
    &Aura::HandleBindSight,                                 //  1 SPELL_AURA_BIND_SIGHT
    &Aura::HandleModPossess,                                //  2 SPELL_AURA_MOD_POSSESS
    &Aura::HandlePeriodicDamage,                            //  3 SPELL_AURA_PERIODIC_DAMAGE
    &Aura::HandleAuraDummy,                                 //  4 SPELL_AURA_DUMMY
    &Aura::HandleModConfuse,                                //  5 SPELL_AURA_MOD_CONFUSE
    &Aura::HandleModCharm,                                  //  6 SPELL_AURA_MOD_CHARM
    &Aura::HandleModFear,                                   //  7 SPELL_AURA_MOD_FEAR
    &Aura::HandlePeriodicHeal,                              //  8 SPELL_AURA_PERIODIC_HEAL
    &Aura::HandleModAttackSpeed,                            //  9 SPELL_AURA_MOD_ATTACKSPEED
    &Aura::HandleModThreat,                                 // 10 SPELL_AURA_MOD_THREAT
    &Aura::HandleModTaunt,                                  // 11 SPELL_AURA_MOD_TAUNT
    &Aura::HandleAuraModStun,                               // 12 SPELL_AURA_MOD_STUN
    &Aura::HandleModDamageDone,                             // 13 SPELL_AURA_MOD_DAMAGE_DONE
    &Aura::HandleNoImmediateEffect,                         // 14 SPELL_AURA_MOD_DAMAGE_TAKEN   implemented in Unit::MeleeDamageBonusTaken and Unit::SpellBaseDamageBonusTaken
    &Aura::HandleNoImmediateEffect,                         // 15 SPELL_AURA_DAMAGE_SHIELD      implemented in Unit::DealMeleeDamage
    &Aura::HandleModStealth,                                // 16 SPELL_AURA_MOD_STEALTH
    &Aura::HandleNoImmediateEffect,                         // 17 SPELL_AURA_MOD_STEALTH_DETECT
    &Aura::HandleInvisibility,                              // 18 SPELL_AURA_MOD_INVISIBILITY
    &Aura::HandleInvisibilityDetect,                        // 19 SPELL_AURA_MOD_INVISIBILITY_DETECTION
    &Aura::HandleAuraModTotalHealthPercentRegen,            // 20 SPELL_AURA_OBS_MOD_HEALTH
    &Aura::HandleAuraModTotalManaPercentRegen,              // 21 SPELL_AURA_OBS_MOD_MANA
    &Aura::HandleAuraModResistance,                         // 22 SPELL_AURA_MOD_RESISTANCE
    &Aura::HandlePeriodicTriggerSpell,                      // 23 SPELL_AURA_PERIODIC_TRIGGER_SPELL
    &Aura::HandlePeriodicEnergize,                          // 24 SPELL_AURA_PERIODIC_ENERGIZE
    &Aura::HandleAuraModPacify,                             // 25 SPELL_AURA_MOD_PACIFY
    &Aura::HandleAuraModRoot,                               // 26 SPELL_AURA_MOD_ROOT
    &Aura::HandleAuraModSilence,                            // 27 SPELL_AURA_MOD_SILENCE
    &Aura::HandleNoImmediateEffect,                         // 28 SPELL_AURA_REFLECT_SPELLS        implement in Unit::SpellHitResult
    &Aura::HandleAuraModStat,                               // 29 SPELL_AURA_MOD_STAT
    &Aura::HandleAuraModSkill,                              // 30 SPELL_AURA_MOD_SKILL
    &Aura::HandleAuraModIncreaseSpeed,                      // 31 SPELL_AURA_MOD_INCREASE_SPEED
    &Aura::HandleAuraModIncreaseMountedSpeed,               // 32 SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED
    &Aura::HandleAuraModDecreaseSpeed,                      // 33 SPELL_AURA_MOD_DECREASE_SPEED
    &Aura::HandleAuraModIncreaseHealth,                     // 34 SPELL_AURA_MOD_INCREASE_HEALTH
    &Aura::HandleAuraModIncreaseEnergy,                     // 35 SPELL_AURA_MOD_INCREASE_ENERGY
    &Aura::HandleAuraModShapeshift,                         // 36 SPELL_AURA_MOD_SHAPESHIFT
    &Aura::HandleAuraModEffectImmunity,                     // 37 SPELL_AURA_EFFECT_IMMUNITY
    &Aura::HandleAuraModStateImmunity,                      // 38 SPELL_AURA_STATE_IMMUNITY
    &Aura::HandleAuraModSchoolImmunity,                     // 39 SPELL_AURA_SCHOOL_IMMUNITY
    &Aura::HandleAuraModDmgImmunity,                        // 40 SPELL_AURA_DAMAGE_IMMUNITY
    &Aura::HandleAuraModDispelImmunity,                     // 41 SPELL_AURA_DISPEL_IMMUNITY
    &Aura::HandleAuraProcTriggerSpell,                      // 42 SPELL_AURA_PROC_TRIGGER_SPELL  implemented in Unit::ProcDamageAndSpellFor and Unit::HandleProcTriggerSpell
    &Aura::HandleNoImmediateEffect,                         // 43 SPELL_AURA_PROC_TRIGGER_DAMAGE implemented in Unit::ProcDamageAndSpellFor
    &Aura::HandleAuraTrackCreatures,                        // 44 SPELL_AURA_TRACK_CREATURES
    &Aura::HandleAuraTrackResources,                        // 45 SPELL_AURA_TRACK_RESOURCES
    &Aura::HandleUnused,                                    // 46 SPELL_AURA_MOD_PARRY_SKILL
    &Aura::HandleAuraModParryPercent,                       // 47 SPELL_AURA_MOD_PARRY_PERCENT
    &Aura::HandleUnused,                                    // 48 SPELL_AURA_MOD_DODGE_SKILL
    &Aura::HandleAuraModDodgePercent,                       // 49 SPELL_AURA_MOD_DODGE_PERCENT
    &Aura::HandleUnused,                                    // 50 SPELL_AURA_MOD_BLOCK_SKILL    obsolete?
    &Aura::HandleAuraModBlockPercent,                       // 51 SPELL_AURA_MOD_BLOCK_PERCENT
    &Aura::HandleAuraModCritPercent,                        // 52 SPELL_AURA_MOD_CRIT_PERCENT
    &Aura::HandlePeriodicLeech,                             // 53 SPELL_AURA_PERIODIC_LEECH
    &Aura::HandleModHitChance,                              // 54 SPELL_AURA_MOD_HIT_CHANCE
    &Aura::HandleModSpellHitChance,                         // 55 SPELL_AURA_MOD_SPELL_HIT_CHANCE
    &Aura::HandleAuraTransform,                             // 56 SPELL_AURA_TRANSFORM
    &Aura::HandleModSpellCritChance,                        // 57 SPELL_AURA_MOD_SPELL_CRIT_CHANCE
    &Aura::HandleAuraModIncreaseSwimSpeed,                  // 58 SPELL_AURA_MOD_INCREASE_SWIM_SPEED
    &Aura::HandleNoImmediateEffect,                         // 59 SPELL_AURA_MOD_DAMAGE_DONE_CREATURE implemented in Unit::MeleeDamageBonusDone and Unit::SpellDamageBonusDone
    &Aura::HandleAuraModPacifyAndSilence,                   // 60 SPELL_AURA_MOD_PACIFY_SILENCE
    &Aura::HandleAuraModScale,                              // 61 SPELL_AURA_MOD_SCALE
    &Aura::HandlePeriodicHealthFunnel,                      // 62 SPELL_AURA_PERIODIC_HEALTH_FUNNEL
    &Aura::HandleUnused,                                    // 63 SPELL_AURA_PERIODIC_MANA_FUNNEL obsolete?
    &Aura::HandlePeriodicManaLeech,                         // 64 SPELL_AURA_PERIODIC_MANA_LEECH
    &Aura::HandleModCastingSpeed,                           // 65 SPELL_AURA_MOD_CASTING_SPEED_NOT_STACK
    &Aura::HandleFeignDeath,                                // 66 SPELL_AURA_FEIGN_DEATH
    &Aura::HandleAuraModDisarm,                             // 67 SPELL_AURA_MOD_DISARM
    &Aura::HandleAuraModStalked,                            // 68 SPELL_AURA_MOD_STALKED
    &Aura::HandleSchoolAbsorb,                              // 69 SPELL_AURA_SCHOOL_ABSORB implemented in Unit::CalculateAbsorbAndResist
    &Aura::HandleUnused,                                    // 70 SPELL_AURA_EXTRA_ATTACKS      Useless, used by only one spell that has only visual effect
    &Aura::HandleModSpellCritChanceSchool,                  // 71 SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL
    &Aura::HandleModPowerCostPCT,                           // 72 SPELL_AURA_MOD_POWER_COST_SCHOOL_PCT
    &Aura::HandleModPowerCost,                              // 73 SPELL_AURA_MOD_POWER_COST_SCHOOL
    &Aura::HandleReflectSpellsSchool,                       // 74 SPELL_AURA_REFLECT_SPELLS_SCHOOL  implemented in Unit::SpellHitResult
    &Aura::HandleNoImmediateEffect,                         // 75 SPELL_AURA_MOD_LANGUAGE
    &Aura::HandleFarSight,                                  // 76 SPELL_AURA_FAR_SIGHT
    &Aura::HandleModMechanicImmunity,                       // 77 SPELL_AURA_MECHANIC_IMMUNITY
    &Aura::HandleAuraMounted,                               // 78 SPELL_AURA_MOUNTED
    &Aura::HandleModDamagePercentDone,                      // 79 SPELL_AURA_MOD_DAMAGE_PERCENT_DONE
    &Aura::HandleModPercentStat,                            // 80 SPELL_AURA_MOD_PERCENT_STAT
    &Aura::HandleNoImmediateEffect,                         // 81 SPELL_AURA_SPLIT_DAMAGE_PCT       implemented in Unit::CalculateAbsorbAndResist
    &Aura::HandleWaterBreathing,                            // 82 SPELL_AURA_WATER_BREATHING
    &Aura::HandleModBaseResistance,                         // 83 SPELL_AURA_MOD_BASE_RESISTANCE
    &Aura::HandleModRegen,                                  // 84 SPELL_AURA_MOD_REGEN
    &Aura::HandleModPowerRegen,                             // 85 SPELL_AURA_MOD_POWER_REGEN
    &Aura::HandleChannelDeathItem,                          // 86 SPELL_AURA_CHANNEL_DEATH_ITEM
    &Aura::HandleNoImmediateEffect,                         // 87 SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN implemented in Unit::MeleeDamageBonusTaken and Unit::SpellDamageBonusTaken
    &Aura::HandleNoImmediateEffect,                         // 88 SPELL_AURA_MOD_HEALTH_REGEN_PERCENT implemented in Player::RegenerateHealth
    &Aura::HandlePeriodicDamagePCT,                         // 89 SPELL_AURA_PERIODIC_DAMAGE_PERCENT
    &Aura::HandleUnused,                                    // 90 SPELL_AURA_MOD_RESIST_CHANCE  Useless
    &Aura::HandleNoImmediateEffect,                         // 91 SPELL_AURA_MOD_DETECT_RANGE implemented in Creature::GetAttackDistance
    &Aura::HandlePreventFleeing,                            // 92 SPELL_AURA_PREVENTS_FLEEING
    &Aura::HandleModUnattackable,                           // 93 SPELL_AURA_MOD_UNATTACKABLE
    &Aura::HandleInterruptRegen,                            // 94 SPELL_AURA_INTERRUPT_REGEN implemented in Player::RegenerateAll
    &Aura::HandleAuraGhost,                                 // 95 SPELL_AURA_GHOST
    &Aura::HandleNoImmediateEffect,                         // 96 SPELL_AURA_SPELL_MAGNET implemented in Unit::SelectMagnetTarget
    &Aura::HandleManaShield,                                // 97 SPELL_AURA_MANA_SHIELD implemented in Unit::CalculateAbsorbAndResist
    &Aura::HandleAuraModSkill,                              // 98 SPELL_AURA_MOD_SKILL_TALENT
    &Aura::HandleAuraModAttackPower,                        // 99 SPELL_AURA_MOD_ATTACK_POWER
    &Aura::HandleAurasVisible,                              //100 SPELL_AURA_AURAS_VISIBLE
    &Aura::HandleModResistancePercent,                      //101 SPELL_AURA_MOD_RESISTANCE_PCT
    &Aura::HandleNoImmediateEffect,                         //102 SPELL_AURA_MOD_MELEE_ATTACK_POWER_VERSUS implemented in Unit::MeleeDamageBonusDone
    &Aura::HandleAuraModTotalThreat,                        //103 SPELL_AURA_MOD_TOTAL_THREAT
    &Aura::HandleAuraWaterWalk,                             //104 SPELL_AURA_WATER_WALK
    &Aura::HandleAuraFeatherFall,                           //105 SPELL_AURA_FEATHER_FALL
    &Aura::HandleAuraHover,                                 //106 SPELL_AURA_HOVER
    &Aura::HandleAddModifier,                               //107 SPELL_AURA_ADD_FLAT_MODIFIER
    &Aura::HandleAddModifier,                               //108 SPELL_AURA_ADD_PCT_MODIFIER
    &Aura::HandleNoImmediateEffect,                         //109 SPELL_AURA_ADD_TARGET_TRIGGER
    &Aura::HandleModPowerRegenPCT,                          //110 SPELL_AURA_MOD_POWER_REGEN_PERCENT
    &Aura::HandleUnused,                                    //111 SPELL_AURA_ADD_CASTER_HIT_TRIGGER
    &Aura::HandleNoImmediateEffect,                         //112 SPELL_AURA_OVERRIDE_CLASS_SCRIPTS implemented in diff functions.
    &Aura::HandleNoImmediateEffect,                         //113 SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN implemented in Unit::MeleeDamageBonusTaken
    &Aura::HandleNoImmediateEffect,                         //114 SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN_PCT implemented in Unit::MeleeDamageBonusTaken
    &Aura::HandleNoImmediateEffect,                         //115 SPELL_AURA_MOD_HEALING                 implemented in Unit::SpellBaseHealingBonusTaken
    &Aura::HandleNoImmediateEffect,                         //116 SPELL_AURA_MOD_REGEN_DURING_COMBAT     imppemented in Player::RegenerateAll and Player::RegenerateHealth
    &Aura::HandleNoImmediateEffect,                         //117 SPELL_AURA_MOD_MECHANIC_RESISTANCE     implemented in Unit::MagicSpellHitResult
    &Aura::HandleNoImmediateEffect,                         //118 SPELL_AURA_MOD_HEALING_PCT             implemented in Unit::SpellHealingBonusTaken
    &Aura::HandleUnused,                                    //119 SPELL_AURA_SHARE_PET_TRACKING useless
    &Aura::HandleAuraUntrackable,                           //120 SPELL_AURA_UNTRACKABLE
    &Aura::HandleAuraEmpathy,                               //121 SPELL_AURA_EMPATHY
    &Aura::HandleModOffhandDamagePercent,                   //122 SPELL_AURA_MOD_OFFHAND_DAMAGE_PCT
    &Aura::HandleNoImmediateEffect,                         //123 SPELL_AURA_MOD_TARGET_RESISTANCE  implemented in Unit::CalculateAbsorbAndResist and Unit::CalcArmorReducedDamage
    &Aura::HandleAuraModRangedAttackPower,                  //124 SPELL_AURA_MOD_RANGED_ATTACK_POWER
    &Aura::HandleNoImmediateEffect,                         //125 SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN implemented in Unit::MeleeDamageBonusTaken
    &Aura::HandleNoImmediateEffect,                         //126 SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN_PCT implemented in Unit::MeleeDamageBonusTaken
    &Aura::HandleNoImmediateEffect,                         //127 SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS implemented in Unit::MeleeDamageBonusDone
    &Aura::HandleModPossessPet,                             //128 SPELL_AURA_MOD_POSSESS_PET
    &Aura::HandleAuraModIncreaseSpeed,                      //129 SPELL_AURA_MOD_SPEED_ALWAYS
    &Aura::HandleAuraModIncreaseMountedSpeed,               //130 SPELL_AURA_MOD_MOUNTED_SPEED_ALWAYS
    &Aura::HandleNoImmediateEffect,                         //131 SPELL_AURA_MOD_RANGED_ATTACK_POWER_VERSUS implemented in Unit::MeleeDamageBonusDone
    &Aura::HandleAuraModIncreaseEnergyPercent,              //132 SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT
    &Aura::HandleAuraModIncreaseHealthPercent,              //133 SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT
    &Aura::HandleAuraModRegenInterrupt,                     //134 SPELL_AURA_MOD_MANA_REGEN_INTERRUPT
    &Aura::HandleModHealingDone,                            //135 SPELL_AURA_MOD_HEALING_DONE
    &Aura::HandleNoImmediateEffect,                         //136 SPELL_AURA_MOD_HEALING_DONE_PERCENT   implemented in Unit::SpellHealingBonusDone
    &Aura::HandleModTotalPercentStat,                       //137 SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE
    &Aura::HandleModMeleeSpeedPct,                          //138 SPELL_AURA_MOD_MELEE_HASTE
    &Aura::HandleForceReaction,                             //139 SPELL_AURA_FORCE_REACTION
    &Aura::HandleAuraModRangedHaste,                        //140 SPELL_AURA_MOD_RANGED_HASTE
    &Aura::HandleRangedAmmoHaste,                           //141 SPELL_AURA_MOD_RANGED_AMMO_HASTE
    &Aura::HandleAuraModBaseResistancePercent,              //142 SPELL_AURA_MOD_BASE_RESISTANCE_PCT
    &Aura::HandleAuraModResistanceExclusive,                //143 SPELL_AURA_MOD_RESISTANCE_EXCLUSIVE
    &Aura::HandleAuraSafeFall,                              //144 SPELL_AURA_SAFE_FALL                         implemented in WorldSession::HandleMovementOpcodes
    &Aura::HandleUnused,                                    //145 SPELL_AURA_CHARISMA obsolete?
    &Aura::HandleUnused,                                    //146 SPELL_AURA_PERSUADED obsolete?
    &Aura::HandleModMechanicImmunityMask,                   //147 SPELL_AURA_MECHANIC_IMMUNITY_MASK            implemented in Unit::IsImmuneToSpell and Unit::IsImmuneToSpellEffect (check part)
    &Aura::HandleAuraRetainComboPoints,                     //148 SPELL_AURA_RETAIN_COMBO_POINTS
    &Aura::HandleNoImmediateEffect,                         //149 SPELL_AURA_RESIST_PUSHBACK
    &Aura::HandleShieldBlockValue,                          //150 SPELL_AURA_MOD_SHIELD_BLOCKVALUE_PCT
    &Aura::HandleAuraTrackStealthed,                        //151 SPELL_AURA_TRACK_STEALTHED
    &Aura::HandleNoImmediateEffect,                         //152 SPELL_AURA_MOD_DETECTED_RANGE         implemented in Creature::GetAttackDistance
    &Aura::HandleNoImmediateEffect,                         //153 SPELL_AURA_SPLIT_DAMAGE_FLAT          implemented in Unit::CalculateAbsorbAndResist
    &Aura::HandleNoImmediateEffect,                         //154 SPELL_AURA_MOD_STEALTH_LEVEL          implemented in Unit::IsVisibleForOrDetect
    &Aura::HandleModWaterBreathing,                         //155 SPELL_AURA_MOD_WATER_BREATHING
    &Aura::HandleNoImmediateEffect,                         //156 SPELL_AURA_MOD_REPUTATION_GAIN        implemented in Player::CalculateReputationGain
    &Aura::HandleUnused,                                    //157 SPELL_AURA_PET_DAMAGE_MULTI (single test like spell 20782, also single for 214 aura)
    &Aura::HandleShieldBlockValue,                          //158 SPELL_AURA_MOD_SHIELD_BLOCKVALUE
    &Aura::HandleNoImmediateEffect,                         //159 SPELL_AURA_NO_PVP_CREDIT      only for Honorless Target spell
    &Aura::HandleNoImmediateEffect,                         //160 SPELL_AURA_MOD_AOE_AVOIDANCE                 implemented in Unit::MagicSpellHitResult
    &Aura::HandleNoImmediateEffect,                         //161 SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT
    &Aura::HandleAuraPowerBurn,                             //162 SPELL_AURA_POWER_BURN_MANA
    &Aura::HandleUnused,                                    //163 SPELL_AURA_MOD_CRIT_DAMAGE_BONUS
    &Aura::HandleUnused,                                    //164 useless, only one test spell
    &Aura::HandleNoImmediateEffect,                         //165 SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS implemented in Unit::MeleeDamageBonusDone
    &Aura::HandleAuraModAttackPowerPercent,                 //166 SPELL_AURA_MOD_ATTACK_POWER_PCT
    &Aura::HandleAuraModRangedAttackPowerPercent,           //167 SPELL_AURA_MOD_RANGED_ATTACK_POWER_PCT
    &Aura::HandleNoImmediateEffect,                         //168 SPELL_AURA_MOD_DAMAGE_DONE_VERSUS            implemented in Unit::SpellDamageBonusDone, Unit::MeleeDamageBonusDone
    &Aura::HandleNoImmediateEffect,                         //169 SPELL_AURA_MOD_CRIT_PERCENT_VERSUS           implemented in Unit::DealDamageBySchool, Unit::DoAttackDamage, Unit::SpellCriticalBonus
    &Aura::HandleNULL,                                      //170 SPELL_AURA_DETECT_AMORE       only for Detect Amore spell
    &Aura::HandleAuraModIncreaseSpeed,                      //171 SPELL_AURA_MOD_SPEED_NOT_STACK
    &Aura::HandleAuraModIncreaseMountedSpeed,               //172 SPELL_AURA_MOD_MOUNTED_SPEED_NOT_STACK
    &Aura::HandleUnused,                                    //173 SPELL_AURA_ALLOW_CHAMPION_SPELLS  only for Proclaim Champion spell
    &Aura::HandleModSpellDamagePercentFromStat,             //174 SPELL_AURA_MOD_SPELL_DAMAGE_OF_STAT_PERCENT  implemented in Unit::SpellBaseDamageBonusDone (in 1.12.* only spirit)
    &Aura::HandleModSpellHealingPercentFromStat,            //175 SPELL_AURA_MOD_SPELL_HEALING_OF_STAT_PERCENT implemented in Unit::SpellBaseHealingBonusDone (in 1.12.* only spirit)
    &Aura::HandleSpiritOfRedemption,                        //176 SPELL_AURA_SPIRIT_OF_REDEMPTION   only for Spirit of Redemption spell, die at aura end
    &Aura::HandleAuraAoeCharm,                              //177 SPELL_AURA_AOE_CHARM
    &Aura::HandleNoImmediateEffect,                         //178 SPELL_AURA_MOD_DEBUFF_RESISTANCE          implemented in Unit::MagicSpellHitResult
    &Aura::HandleNoImmediateEffect,                         //179 SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE implemented in Unit::SpellCriticalBonus
    &Aura::HandleNoImmediateEffect,                         //180 SPELL_AURA_MOD_FLAT_SPELL_DAMAGE_VERSUS   implemented in Unit::SpellDamageBonusDone
    &Aura::HandleUnused,                                    //181 SPELL_AURA_MOD_FLAT_SPELL_CRIT_DAMAGE_VERSUS unused
    &Aura::HandleAuraModResistenceOfStatPercent,            //182 SPELL_AURA_MOD_RESISTANCE_OF_STAT_PERCENT
    &Aura::HandleNoImmediateEffect,                         //183 SPELL_AURA_MOD_CRITICAL_THREAT only used in 28746, implemented in ThreatCalcHelper::CalcThreat
    &Aura::HandleNoImmediateEffect,                         //184 SPELL_AURA_MOD_ATTACKER_MELEE_HIT_CHANCE  implemented in Unit::RollMeleeOutcomeAgainst
    &Aura::HandleNoImmediateEffect,                         //185 SPELL_AURA_MOD_ATTACKER_RANGED_HIT_CHANCE implemented in Unit::RollMeleeOutcomeAgainst
    &Aura::HandleNoImmediateEffect,                         //186 SPELL_AURA_MOD_ATTACKER_SPELL_HIT_CHANCE  implemented in Unit::MagicSpellHitResult
    &Aura::HandleNoImmediateEffect,                         //187 SPELL_AURA_MOD_ATTACKER_MELEE_CRIT_CHANCE  implemented in Unit::GetUnitCriticalChance
    &Aura::HandleNoImmediateEffect,                         //188 SPELL_AURA_MOD_ATTACKER_RANGED_CRIT_CHANCE implemented in Unit::GetUnitCriticalChance
    &Aura::HandleUnused,                                    //189 SPELL_AURA_MOD_RATING (not used in 1.12.1)
    &Aura::HandleNoImmediateEffect,                         //190 SPELL_AURA_MOD_FACTION_REPUTATION_GAIN     implemented in Player::CalculateReputationGain
    &Aura::HandleAuraModUseNormalSpeed,                     //191 SPELL_AURA_USE_NORMAL_MOVEMENT_SPEED
    // Nostalrius - custom
    &Aura::HandleAuraAuraSpell,
};

static AuraType const frozenAuraTypes[] = { SPELL_AURA_MOD_ROOT, SPELL_AURA_MOD_STUN, SPELL_AURA_NONE };

Aura::Aura(SpellEntry const* spellproto, SpellEffectIndex eff, int32 *currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster, Item* castItem) :
    m_spellmod(nullptr), m_periodicTimer(0), m_periodicTick(0), m_removeMode(AURA_REMOVE_BY_DEFAULT),
    m_effIndex(eff), m_positive(false), m_isPeriodic(false), m_isAreaAura(false),
    m_isPersistent(false), m_in_use(0), m_spellAuraHolder(holder),
// NOSTALRIUS: auras exclusifs
    m_applied(false)
{
    MANGOS_ASSERT(target);
    MANGOS_ASSERT(spellproto && spellproto == sSpellMgr.GetSpellEntry(spellproto->Id) && "`info` must be pointer to a sSpellMgr element");
    ASSERT(spellproto->EffectApplyAuraName[eff]);

    m_currentBasePoints = currentBasePoints ? *currentBasePoints : spellproto->CalculateSimpleValue(eff);

    m_positive = spellproto->IsPositiveEffect(m_effIndex);
    m_applyTime = time(nullptr);

    float damage;
    if (!caster)
        damage = m_currentBasePoints;
    else
        damage = caster->CalculateSpellEffectValue(target, spellproto, m_effIndex, &m_currentBasePoints);

    damage *= GetStackAmount();

    DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "Aura: construct Spellid : %u, Aura : %u Target : %d Damage : %d", spellproto->Id, spellproto->EffectApplyAuraName[eff], spellproto->EffectImplicitTargetA[eff], damage);

    SetModifier(AuraType(spellproto->EffectApplyAuraName[eff]), damage, spellproto->EffectAmplitude[eff], spellproto->EffectMiscValue[eff]);
    CalculatePeriodic(caster ? caster->GetSpellModOwner() : nullptr, true);
    ComputeExclusive();
    if (IsLastAuraOnHolder() && !m_positive)
    {
        // Exclude passive spells.
        if (holder->IsNeedVisibleSlot(caster))
            holder->CalculateForDebuffLimit();

        holder->CalculateHeartBeat(caster, target);
    }
}

void Aura::Refresh(Unit* caster, Unit* target, SpellAuraHolder* pRefreshWithHolder)
{
    Aura* pHolderAura = pRefreshWithHolder->GetAuraByEffectIndex(m_effIndex);
    if (!pHolderAura)
        return;
    m_periodicTick = 0;
    Player* modOwner = caster ? caster->GetSpellModOwner() : nullptr;
    m_applyTime = time(nullptr);
    CalculatePeriodic(modOwner, true);

    // Re-calculation du montant de degats
    if (IsApplied() || !IsExclusive())
    {
        bool lockStats = false;
        switch (GetSpellProto()->EffectApplyAuraName[m_effIndex])
        {
            case SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE:
                if (GetSpellProto()->Attributes & 0x10)
                    break;
            // no break
            case SPELL_AURA_MOD_STAT:
            case SPELL_AURA_MOD_PERCENT_STAT:
            case SPELL_AURA_MOD_INCREASE_HEALTH:
            case SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT: // Exemple : 27038
                lockStats = true;
                break;
        }
        if (lockStats)
            target->SetCanModifyStats(false);
        //unapply with the old modifiers and reapply with the new.
        ApplyModifier(false, true, false);
        // Refresh de quelques variables du modifier
        m_modifier.m_auraname = pHolderAura->GetModifier()->m_auraname;
        m_modifier.m_amount = pHolderAura->GetModifier()->m_amount;
        m_modifier.m_miscvalue = pHolderAura->GetModifier()->m_miscvalue;
        ApplyModifier(true, true, false);
        if (lockStats)
        {
            target->SetCanModifyStats(true);
            target->UpdateAllStats();
        }
    }
}

void SpellAuraHolder::Refresh(Unit* caster, Unit* target, SpellAuraHolder* pRefreshWithHolder)
{
    m_casterGuid = caster ? caster->GetObjectGuid() : target->GetObjectGuid();
    m_applyTime = time(nullptr);
    m_duration = pRefreshWithHolder->GetAuraDuration();
    m_maxDuration = pRefreshWithHolder->GetAuraMaxDuration();
    for (uint8 i = 0 ; i < MAX_EFFECT_INDEX; ++i)
    {
        if (Aura* pAura = GetAuraByEffectIndex(SpellEffectIndex(i)))
            pAura->Refresh(caster, target, pRefreshWithHolder);
    }
    UpdateAuraDuration();
    UpdateAuraApplication();
}

    // Register Visible Aura
    if (slot < MAX_AURAS)
    {
        _slot = slot;
        GetTarget()->SetVisibleAura(this);
        _needClientUpdate = true;
        TC_LOG_DEBUG("spells", "Aura: {} Effect: {} put to unit visible auras slot: {}", GetBase()->GetId(), GetEffectMask(), slot);
    }
    else
        TC_LOG_ERROR("spells", "Aura: {} Effect: {} could not find empty unit visible slot", GetBase()->GetId(), GetEffectMask());
bool SpellAuraHolder::CanBeRefreshedBy(SpellAuraHolder* other) const
{
    if (!other)
        return false;
    if (other->GetCasterGuid() != GetCasterGuid())
        return false;
    // Meme ID/Effet de sort
    if (other->GetId() != GetId())
        return false;
    if (m_spellProto->StackAmount) // Se stack
        return false;
    if (m_spellProto->procCharges) // Ou a des charges (fix bug visuel)
        return false;
    return true;
}

bool SpellAuraHolder::IsMoreImportantDebuffThan(SpellAuraHolder* other) const
{
    // Same category : last aura applies
    if (m_debuffLimitScore == other->m_debuffLimitScore)
        return m_applyTime > other->m_applyTime;
    // Else, compare categories
    return m_debuffLimitScore > other->m_debuffLimitScore;
}

Aura::~Aura()
{
}

AreaAura::AreaAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32 *currentBasePoints, SpellAuraHolder* holder, Unit* target,
                   Unit* caster, Item* castItem, uint32 originalRankSpellId) : Aura(spellproto, eff, currentBasePoints, holder, target, caster, castItem), m_originalRankSpellId(originalRankSpellId)
{
    m_isAreaAura = true;

    // caster==nullptr in constructor args if target==caster in fact
    Unit* caster_ptr = caster ? caster : target;

    m_radius = GetSpellRadius(sSpellRadiusStore.LookupEntry(spellproto->EffectRadiusIndex[m_effIndex]));
    if (Player* modOwner = caster_ptr->GetSpellModOwner())
        modOwner->ApplySpellMod(spellproto->Id, SPELLMOD_RADIUS, m_radius);

    switch (spellproto->Effect[eff])
    {
        case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
            m_areaAuraType = AREA_AURA_PARTY;
            if (target->GetCharmerOrOwnerOrSelf()->GetTypeId() == TYPEID_UNIT)
                m_areaAuraType = AREA_AURA_CREATURE_GROUP;
            if (target->GetTypeId() == TYPEID_UNIT && ((Creature*)target)->IsTotem())
                m_modifier.m_auraname = SPELL_AURA_NONE;
            break;
        case SPELL_EFFECT_APPLY_AREA_AURA_RAID:
            m_areaAuraType = AREA_AURA_RAID;
            if (target->GetCharmerOrOwnerOrSelf()->GetTypeId() == TYPEID_UNIT)
                m_areaAuraType = AREA_AURA_CREATURE_GROUP;
            if (target->GetTypeId() == TYPEID_UNIT && ((Creature*)target)->IsTotem())
                m_modifier.m_auraname = SPELL_AURA_NONE;
            // Light's Beacon not applied to caster itself (TODO: more generic check for another similar spell if any?)
            else if (target == caster_ptr && spellproto->Id == 53651)
                m_modifier.m_auraname = SPELL_AURA_NONE;
            break;
        case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND:
            m_areaAuraType = AREA_AURA_FRIEND;
            break;
        case SPELL_EFFECT_APPLY_AREA_AURA_ENEMY:
            m_areaAuraType = AREA_AURA_ENEMY;
            if (target == caster_ptr)
                m_modifier.m_auraname = SPELL_AURA_NONE;    // Do not do any effect on self
            break;
        case SPELL_EFFECT_APPLY_AREA_AURA_PET:
            m_areaAuraType = AREA_AURA_PET;
            break;
        case SPELL_EFFECT_APPLY_AREA_AURA_OWNER:
            m_areaAuraType = AREA_AURA_OWNER;
            if (target == caster_ptr)
                m_modifier.m_auraname = SPELL_AURA_NONE;
            break;
        default:
            sLog.outError("Wrong spell effect in AreaAura constructor");
            MANGOS_ASSERT(false);
            break;
    }
}

AreaAura::~AreaAura()
{
}

    // aura is cast by self or an enemy
    // one negative effect and we know aura is negative
    if (IsSelfcast() || !caster || !caster->IsFriendlyTo(GetTarget()))
    {
        bool negativeFound = false;
        for (uint8 i = 0; i < GetBase()->GetSpellInfo()->GetEffects().size(); ++i)
        {
            if (((1 << i) & effMask) && !GetBase()->GetSpellInfo()->IsPositiveEffect(i))
            {
                negativeFound = true;
                break;
            }
        }
        _flags |= negativeFound ? AFLAG_NEGATIVE : AFLAG_POSITIVE;
    }
    // aura is cast by friend
    // one positive effect and we know aura is positive
    else
    {
        bool positiveFound = false;
        for (uint8 i = 0; i < GetBase()->GetSpellInfo()->GetEffects().size(); ++i)
        {
            if (((1 << i) & effMask) && GetBase()->GetSpellInfo()->IsPositiveEffect(i))
            {
                positiveFound = true;
                break;
            }
        }
        _flags |= positiveFound ? AFLAG_POSITIVE : AFLAG_NEGATIVE;
    }
PersistentAreaAura::PersistentAreaAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32 *currentBasePoints, SpellAuraHolder* holder, Unit* target,
                                       Unit* caster, Item* castItem) : Aura(spellproto, eff, currentBasePoints, holder, target, caster, castItem)
{
    m_isPersistent = true;
}

PersistentAreaAura::~PersistentAreaAura()
{
}

SingleEnemyTargetAura::SingleEnemyTargetAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32 *currentBasePoints, SpellAuraHolder* holder, Unit* target,
        Unit* caster, Item* castItem) : Aura(spellproto, eff, currentBasePoints, holder, target, caster, castItem)
{
    if (caster)
        m_castersTargetGuid = caster->GetTypeId() == TYPEID_PLAYER ? ((Player*)caster)->GetSelectionGuid() : caster->GetTargetGuid();
}

SingleEnemyTargetAura::~SingleEnemyTargetAura()
{
}

Unit* SingleEnemyTargetAura::GetTriggerTarget() const
{
    return ObjectAccessor::GetUnit(*(m_spellAuraHolder->GetTarget()), m_castersTargetGuid);
}

Aura* CreateAura(SpellEntry const* spellproto, SpellEffectIndex eff, int32 *currentBasePoints, SpellAuraHolder* holder, Unit* target, Unit* caster, Item* castItem)
{
    if (IsAreaAuraEffect(spellproto->Effect[eff]))
        return new AreaAura(spellproto, eff, currentBasePoints, holder, target, caster, castItem);

    return new Aura(spellproto, eff, currentBasePoints, holder, target, caster, castItem);
}

SpellAuraHolder* CreateSpellAuraHolder(SpellEntry const* spellproto, Unit* target, Unit* caster, WorldObject* realCaster, Item* castItem)
{
    return new SpellAuraHolder(spellproto, target, caster, castItem, realCaster);
}

void Aura::SetModifier(AuraType t, float a, uint32 pt, int32 miscValue)
{
    m_modifier.m_auraname = t;
    m_modifier.m_amount = a;
    m_modifier.m_miscvalue = miscValue;
    m_modifier.periodictime = pt;
}

int32 Aura::GetMiscValue() const
{
    return m_spellAuraHolder->GetSpellProto()->EffectMiscValue[m_effIndex];
}

void Aura::UpdatePeriodicTimer(int32 duration)
{
    if (m_isPeriodic)
    {
        // If duration gets changed, also change the periodic timer so that we
        // aren't losing out on ticks. Required for channeled spells that utilize
        // dynamic objects - don't want periodic timer initialized to the full
        // tick timer on entry into the aura
        // Avoid using modulo if we don't need to (slight perf increase)
        int32 newtick = (duration > m_modifier.periodictime) ? (duration % m_modifier.periodictime) : duration;
        // can be a divisible amount, in which case set it to the full period
        if (!newtick)
            newtick = m_modifier.periodictime;

        m_periodicTimer = newtick;
    }
}

void Aura::UpdateForAffected(uint32 diff)
{
    SetInUse(true);
    Aura::Update(diff);
    SetInUse(false);
}

void Aura::Update(uint32 diff)
{
    if (m_isPeriodic)
    {
        m_periodicTimer -= diff;

        if (m_periodicTimer <= 0) // tick also at m_periodicTimer==0 to prevent lost last tick in case max m_duration == (max m_periodicTimer)*N
        {
            // update before applying (aura can be removed in TriggerSpell or PeriodicTick calls)
            m_periodicTimer += m_modifier.periodictime;
            ++m_periodicTick;                               // for some infinity auras in some cases can overflow and reset
            PeriodicTick();
        }
    }

    if (GetSpellProto()->EffectImplicitTargetA[0] == TARGET_UNIT_RAID_AND_CLASS) // remove greater blessings on leaving raid
    {
        Unit* pTarget = GetTarget();
        ObjectGuid casterGuid = GetCasterGuid();
        if (casterGuid.IsPlayer() && casterGuid != pTarget->GetObjectGuid() && casterGuid != pTarget->GetCharmerOrOwnerGuid())
        {
            Player* pTargetPlayer = pTarget->GetCharmerOrOwnerPlayerOrPlayerItself();
            if (!pTargetPlayer || !pTargetPlayer->GetGroup() || !pTargetPlayer->GetGroup()->IsMember(casterGuid))
                pTarget->RemoveAurasByCasterSpell(GetId(), casterGuid, AURA_REMOVE_BY_GROUP);
        }
    }
}

// Called by caster of this area aura to tick auras for affected targets
void AreaAura::UpdateForAffected(uint32 diff)
{
    Aura::UpdateForAffected(diff);
}

void AreaAura::Update(uint32 diff)
{
    // update for the caster of the aura
    if (GetCasterGuid() == GetTarget()->GetObjectGuid())
    {
        Unit* caster = GetTarget();

        if (!caster->HasUnitState(UNIT_STAT_ISOLATED))
        {
            Unit* owner = caster->GetCharmerOrOwner();
            if (!owner)
                owner = caster;
            Spell::UnitList targets;

            switch (m_areaAuraType)
            {
                case AREA_AURA_PARTY:
                {
                    Group* pGroup = nullptr;

                    if (owner->GetTypeId() == TYPEID_PLAYER)
                        pGroup = ((Player*)owner)->GetGroup();

                    if (pGroup)
                    {
                        uint8 subgroup = ((Player*)owner)->GetSubGroup();
                        for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
                        {
                            Player* Target = itr->getSource();
                            if (Target && Target->IsAlive() && Target->GetSubGroup() == subgroup && (!Target->duel || owner == Target) && caster->IsFriendlyTo(Target))
                            {
                                if (caster->IsWithinDistInMap(Target, m_radius))
                                    targets.push_back(Target);
                                Pet* pet = Target->GetPet();
                                if (pet && pet->IsAlive() && caster->IsWithinDistInMap(pet, m_radius))
                                    targets.push_back(pet);
                            }
                        }
                    }
                    else
                    {
                        // add owner
                        if (owner != caster && caster->IsWithinDistInMap(owner, m_radius))
                            targets.push_back(owner);
                        // add caster's pet
                        Unit* pet = caster->GetPet();
                        if (pet && caster->IsWithinDistInMap(pet, m_radius))
                            targets.push_back(pet);
                    }
                    break;
                }
                case AREA_AURA_RAID:
                {
                    Group* pGroup = nullptr;

                    if (owner->GetTypeId() == TYPEID_PLAYER)
                        pGroup = ((Player*)owner)->GetGroup();

                    if (pGroup)
                    {
                        for (GroupReference* itr = pGroup->GetFirstMember(); itr != nullptr; itr = itr->next())
                        {
                            Player* Target = itr->getSource();
                            if (Target && Target->IsAlive() && caster->IsFriendlyTo(Target))
                            {
                                if (caster->IsWithinDistInMap(Target, m_radius))
                                    targets.push_back(Target);
                                Pet* pet = Target->GetPet();
                                if (pet && pet->IsAlive() && caster->IsWithinDistInMap(pet, m_radius))
                                    targets.push_back(pet);
                            }
                        }
                    }
                    else
                    {
                        // add owner
                        if (owner != caster && caster->IsWithinDistInMap(owner, m_radius))
                            targets.push_back(owner);

                        // add caster's pet
                        Unit* pet = caster->GetPet();
                        if (pet && caster->IsWithinDistInMap(pet, m_radius))
                            targets.push_back(pet);
                    }
                    break;
                }
                case AREA_AURA_FRIEND:
                {
                    MaNGOS::AnyFriendlyUnitInObjectRangeCheck u_check(caster, m_radius);
                    MaNGOS::UnitListSearcher<MaNGOS::AnyFriendlyUnitInObjectRangeCheck> searcher(targets, u_check);
                    Cell::VisitAllObjects(caster, searcher, m_radius);
                    break;
                }
                case AREA_AURA_ENEMY:
                {
                    MaNGOS::AnyAoETargetUnitInObjectRangeCheck u_check(caster, caster, m_radius); // No GetCharmer in searcher
                    MaNGOS::UnitListSearcher<MaNGOS::AnyAoETargetUnitInObjectRangeCheck> searcher(targets, u_check);
                    Cell::VisitAllObjects(caster, searcher, m_radius);
                    break;
                }
                case AREA_AURA_OWNER:
                {
                    if (owner != caster && caster->IsWithinDistInMap(owner, m_radius))
                        targets.push_back(owner);
                    break;
                }
                case AREA_AURA_PET:
                {
                    if (owner != caster && caster->IsWithinDistInMap(owner, m_radius))
                        targets.push_back(owner);
                    break;
                }
                case AREA_AURA_CREATURE_GROUP:
                {
                    if (Creature* pCreature = caster->ToCreature())
                    {
                        if (pCreature->GetCreatureGroup())
                        {
                            MaNGOS::AnyCreatureGroupMembersInObjectRangeCheck u_check(pCreature, m_radius);
                            MaNGOS::UnitListSearcher<MaNGOS::AnyCreatureGroupMembersInObjectRangeCheck> searcher(targets, u_check);
                            Cell::VisitAllObjects(pCreature, searcher, m_radius);
                        }
                        else
                        {
                            // alternative when missing group definition, apply to same faction units
                            MaNGOS::AnySameFactionUnitInObjectRangeCheck u_check(pCreature, m_radius);
                            MaNGOS::UnitListSearcher<MaNGOS::AnySameFactionUnitInObjectRangeCheck> searcher(targets, u_check);
                            Cell::VisitAllObjects(pCreature, searcher, m_radius);
                        }
                    }

                    // add owner
                    if (owner != caster && caster->IsWithinDistInMap(owner, m_radius) && std::find(targets.begin(), targets.end(), owner) == targets.end())
                        targets.push_back(owner);

                    // add caster's pet
                    Unit* pet = caster->GetPet();
                    if (pet && caster->IsWithinDistInMap(pet, m_radius) && std::find(targets.begin(), targets.end(), pet) == targets.end())
                        targets.push_back(pet);

                    break;
                }
            }

            for (const auto target : targets)
            {
                // default flag is to apply aura to current iteration target, set to
                // false if an area aura of the same spellid exists on the target
                bool apply = true;

                SpellEntry const* actualSpellInfo;
                if (GetCasterGuid() == target->GetObjectGuid()) // if caster is same as target then no need to change rank of the spell
                    actualSpellInfo = GetSpellProto();
                else
                    actualSpellInfo = sSpellMgr.SelectAuraRankForLevel(GetSpellProto(), target->GetLevel()); // use spell id according level of the target
                if (!actualSpellInfo)
                    continue;

                Unit::SpellAuraHolderBounds spair = target->GetSpellAuraHolderBounds(actualSpellInfo->Id);
                // we need to ignore present caster self applied area auras sometimes
                // in cases where this is the only aura applied for this spell effect
                for (Unit::SpellAuraHolderMap::const_iterator i = spair.first; i != spair.second; ++i)
                {
                    if (i->second->IsDeleted())
                        continue;

                    Aura* aur = i->second->GetAuraByEffectIndex(m_effIndex);

                    if (aur)
                    {
                        // If this unit is the caster, update the tick. Units won't tick their
                        // own area auras. Make sure we don't double tick if this unit is the caster
                        // though
                        if (i->second->GetCasterGuid() == GetCasterGuid() && i->second->GetTarget()->GetObjectGuid() != GetCasterGuid())
                        {
                            aur->UpdateForAffected(diff);
                        }

void AuraApplication::_HandleEffect(uint8 effIndex, bool apply)
{
    AuraEffect* aurEff = GetBase()->GetEffect(effIndex);
    if (!aurEff)
    {
        TC_LOG_ERROR("spells", "Aura {} has no effect at effectIndex {} but _HandleEffect was called", GetBase()->GetSpellInfo()->Id, uint32(effIndex));
        return;
    }
    ASSERT(aurEff);
    ASSERT(HasEffect(effIndex) == (!apply));
    ASSERT((1<<effIndex) & _effectsToApply);
    TC_LOG_DEBUG("spells", "AuraApplication::_HandleEffect: {}, apply: {}: amount: {}", aurEff->GetAuraType(), apply, aurEff->GetAmount());
                        // in generic case not allow stacking area auras
                        apply = false;
                        break;
                    }
                    else
                        continue;
                }

                if (!apply)
                    continue;

                // Skip some targets (TODO: Might require better checks, also unclear how the actual caster must/can be handled)
                if (actualSpellInfo->AttributesEx3 & SPELL_ATTR_EX3_TARGET_ONLY_PLAYER && target->GetTypeId() != TYPEID_PLAYER)
                    continue;

                int32 actualBasePoints = m_currentBasePoints;
                // recalculate basepoints for lower rank (all AreaAura spell not use custom basepoints?)
                if (actualSpellInfo != GetSpellProto())
                    actualBasePoints = actualSpellInfo->CalculateSimpleValue(m_effIndex);

                SpellAuraHolder* holder = target->GetSpellAuraHolder(actualSpellInfo->Id, GetCasterGuid());

                bool addedToExisting = true;
                if (!holder)
                {
                    holder = CreateSpellAuraHolder(actualSpellInfo, target, caster, caster);
                    addedToExisting = false;
                }

                AreaAura* aur = new AreaAura(actualSpellInfo, m_effIndex, &actualBasePoints, holder, target, caster, nullptr, GetSpellProto()->Id);
                holder->AddAura(aur, m_effIndex);

                if (!holder->IsPassive() && !holder->IsPermanent())
                {
                    // Aura duration has already been decremented in caster holder update, so re-add
                    // for the target's holder or it will be one diff in the future
                    holder->SetAuraDuration(GetAuraDuration() + diff);
                }

                // Caster's aura will tick at the end of this method, so subtract now to remain synced
                holder->RefreshAuraPeriodicTimers(m_periodicTimer - diff);

                if (addedToExisting)
                {
                    target->AddAuraToModList(aur);
                    holder->SetInUse(true);
                    aur->ApplyModifier(true, true);
                    holder->SetInUse(false);
                }
                else if (!target->AddSpellAuraHolder(holder))
                    holder = nullptr;

                DETAIL_LOG("Added aura %u to holder for spell %u on %s", m_effIndex, GetId(), target->GetName());

                // Add holder to spell if it's channeled so the updates are synced
                if (holder && IsChanneled() && !addedToExisting)
                {
                    if (Spell* spell = caster->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                    {
                        spell->AddChanneledAuraHolder(holder);
                    }
                }
            }
        }
        Aura::Update(diff);
    }
    else                                                    // aura at non-caster
    {
        Unit* caster = GetCaster();
        Unit* target = GetTarget();
        uint32 originalRankSpellId = m_originalRankSpellId ? m_originalRankSpellId : GetId(); // caster may have different spell id if target has lower level

        // Aura updates in caster update, see above
        //Aura::Update(diff);

        // only do range/removal check, tick is done on caster update to remain in sync
        // remove aura if out-of-range from caster (after teleport for example)
        // or caster is isolated or caster no longer has the aura
        // or caster is (no longer) friendly
        bool needFriendly = (m_areaAuraType != AREA_AURA_ENEMY);
        if (!caster ||
            caster->HasUnitState(UNIT_STAT_ISOLATED) ||
            !caster->HasAura(originalRankSpellId, GetEffIndex()) ||
            !caster->IsWithinDistInMap(target, m_radius) ||
            caster->IsFriendlyTo(target) != needFriendly
            )
        {
            target->RemoveSingleAuraFromSpellAuraHolder(GetId(), GetEffIndex(), GetCasterGuid(), AURA_REMOVE_BY_RANGE);
        }
        else if (m_areaAuraType == AREA_AURA_PARTY)         // check if in same sub group
        {
            // not check group if target == owner or target == pet
            if (caster->GetCharmerOrOwnerGuid() != target->GetObjectGuid() && caster->GetObjectGuid() != target->GetCharmerOrOwnerGuid())
            {
                Player* check = caster->GetCharmerOrOwnerPlayerOrPlayerItself();

                Group* pGroup = check ? check->GetGroup() : nullptr;
                if (pGroup)
                {
                    Player* checkTarget = target->GetCharmerOrOwnerPlayerOrPlayerItself();
                    if (!checkTarget || !pGroup->SameSubGroup(check, checkTarget))
                        target->RemoveSingleAuraFromSpellAuraHolder(GetId(), GetEffIndex(), GetCasterGuid(), AURA_REMOVE_BY_GROUP);
                }
                else
                    target->RemoveSingleAuraFromSpellAuraHolder(GetId(), GetEffIndex(), GetCasterGuid(), AURA_REMOVE_BY_GROUP);
            }
        }
        else if (m_areaAuraType == AREA_AURA_PET)
        {
            if (target->GetObjectGuid() != caster->GetCharmerOrOwnerGuid())
                target->RemoveSingleAuraFromSpellAuraHolder(GetId(), GetEffIndex(), GetCasterGuid(), AURA_REMOVE_BY_GROUP);
        }
    }
}

void PersistentAreaAura::Update(uint32 diff)
{
    // remove the aura if its caster or the dynamic object causing it was removed
    // or if the target moves too far from the dynamic object

    bool remove = false;
    uint32 spellId = GetId();
    // Nostalrius: piege explosif. Ne doit pas etre retire lorsqu'on sort de la zone.
    if (spellId != 13812 && spellId != 14314 && spellId != 14315)
    {
        remove = true;
        if (SpellCaster* caster = GetRealCaster())
        {
            std::vector<DynamicObject*> dynObjs;
            caster->GetDynObjects(spellId, GetEffIndex(), dynObjs);
            Unit* pUnitTarget = GetTarget();
            for (DynamicObject* obj : dynObjs)
            {
                if (pUnitTarget->IsWithinDistInMap(obj, obj->GetRadius()))
                    remove = false;
                else
                    obj->RemoveAffected(pUnitTarget);           // let later reapply if target return to range
            }
        }
    }

void AuraApplication::UpdateApplyEffectMask(uint32 newEffMask, bool canHandleNewEffects)
{
    if (_effectsToApply == newEffMask)
        return;

    uint32 removeEffMask = (_effectsToApply ^ newEffMask) & (~newEffMask);
    uint32 addEffMask = (_effectsToApply ^ newEffMask) & (~_effectsToApply);

    // quick check, removes application completely
    if (removeEffMask == _effectsToApply && !addEffMask)
    {
        _target->_UnapplyAura(this, AURA_REMOVE_BY_DEFAULT);
        return;
    }

    // update real effects only if they were applied already
    for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
        if (HasEffect(i) && (removeEffMask & (1 << i)))
            _HandleEffect(i, false);

    _effectsToApply = newEffMask;

    if (canHandleNewEffects)
        for (uint8 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            if (addEffMask & (1 << i))
                _HandleEffect(i, true);
}

void AuraApplication::SetNeedClientUpdate()
    // Note: Unit may have been removed from the world (mid-teleport) during this
    // update (since the caster updates area auras). We shouldn't be ticking it
    // when the target is out of range anyway.
    if (remove)
        GetTarget()->RemoveSingleAuraFromSpellAuraHolder(GetHolder(), m_effIndex, AURA_REMOVE_BY_RANGE);
    else
        Aura::Update(diff);
}

void Aura::ApplyModifier(bool apply, bool Real, bool skipCheckExclusive)
{
    // Dans Unit::RemoveAura, ApplyModifier est toujours appelle.
    if (IsApplied() == apply)
        return;
    AuraType aura = m_modifier.m_auraname;

    GetHolder()->SetInUse(true);
    SetInUse(true);
    // NOSTALRIUS: Auras exclusifs.
    if (apply && !skipCheckExclusive && IsExclusive() && !ExclusiveAuraCanApply())
    {
        GetHolder()->SetInUse(false);
        SetInUse(false);
        return;
    }
    m_applied = apply;
    if (aura < TOTAL_AURAS)
        (*this.*AuraHandler [aura])(apply, Real);

    if (!apply && !skipCheckExclusive && IsExclusive())
        ExclusiveAuraUnapply();

    SetInUse(false);
    GetHolder()->SetInUse(false);
}

bool Aura::isAffectedOnSpell(SpellEntry const* spell) const
{
    if (m_spellmod)
        return m_spellmod->isAffectedOnSpell(spell);

    // Check family name
    if (spell->SpellFamilyName != GetSpellProto()->SpellFamilyName)
        return false;

    Aura const* aura = GetBase();
    uint64 mask = sSpellMgr.GetSpellAffectMask(GetId(), GetEffIndex());
    return spell->IsFitToFamilyMask(mask);
}

bool Aura::CanProcFrom(SpellEntry const* spell, uint32 EventProcEx, uint32 procEx, bool active, bool useClassMask) const
{
    // Check EffectClassMask (in pre-3.x stored in spell_affect in fact)
    uint64 mask = sSpellMgr.GetSpellAffectMask(GetId(), GetEffIndex());

    WorldPackets::Spells::AuraDataInfo& auraData = auraInfo.AuraData.emplace();
    auraData.CastID = aura->GetCastId();
    auraData.SpellID = aura->GetId();
    auraData.Visual = aura->GetSpellVisual();
    auraData.Flags = GetFlags();
    if (aura->GetType() != DYNOBJ_AURA_TYPE && aura->GetMaxDuration() > 0 && !aura->GetSpellInfo()->HasAttribute(SPELL_ATTR5_DO_NOT_DISPLAY_DURATION))
        auraData.Flags |= AFLAG_DURATION;
    // Nostalrius: c'est la moindre des choses d'utiliser un peu 'spell_proc_event' non ?
    if (!mask)
        if (SpellProcEventEntry const* entry = sSpellMgr.GetSpellProcEvent(GetId()))
            mask = entry->spellFamilyMask[GetEffIndex()];

    // if no class mask defined, or spell_proc_event has SpellFamilyName=0 - allow proc
    if (!useClassMask || !mask)
    {
        if (!(EventProcEx & PROC_EX_EX_TRIGGER_ALWAYS))
        {
            // Check for extra req (if none) and hit/crit
            if (EventProcEx == PROC_EX_NONE)
            {
                // No extra req, so can trigger only for active (damage/healing present) and hit/crit
                return (procEx & (PROC_EX_NORMAL_HIT | PROC_EX_CRITICAL_HIT)) && active;
            }
            else // Passive spells hits here only if resist/reflect/immune/evade
            {
                // Passive spells can`t trigger if need hit (exclude cases when procExtra include non-active flags)
                if ((EventProcEx & (PROC_EX_NORMAL_HIT | PROC_EX_CRITICAL_HIT) & procEx) && !active)
                    return false;
            }
        }
        return true;
    }
    else
    {
        // SpellFamilyName check is performed in SpellMgr::IsSpellProcEventCanTriggeredBy and it is done once for whole holder
        // note: SpellFamilyName is not checked if no spell_proc_event is defined
        return !!(mask & spell->SpellFamilyFlags);
    }
}

    // send stack amount for aura which could be stacked (never 0 - causes incorrect display) or charges
    // stack amount has priority over charges (checked on retail with spell 50262)
    auraData.Applications = aura->IsUsingStacks() ? aura->GetStackAmount() : aura->GetCharges();
    if (!aura->GetCasterGUID().IsUnit())
        auraData.CastUnit = ObjectGuid::Empty; // optional data is filled in, but cast unit contains empty guid in packet
    else if (!(auraData.Flags & AFLAG_NOCASTER))
        auraData.CastUnit = aura->GetCasterGUID();
void Aura::ReapplyAffectedPassiveAuras(Unit* target)
{
    // we need store cast item guids for self casted spells
    // expected that not exist permanent auras from stackable auras from different items
    std::map<uint32, ObjectGuid> affectedSelf;

    for (Unit::SpellAuraHolderMap::const_iterator itr = target->GetSpellAuraHolderMap().begin(); itr != target->GetSpellAuraHolderMap().end(); ++itr)
    {
        // permanent passive
        // passive spells can be affected only by own or owner spell mods)
        if (itr->second->IsPassive() && itr->second->IsPermanent() &&
                // non deleted and not same aura (any with same spell id)
                !itr->second->IsDeleted() && itr->second->GetId() != GetId() &&
                // and affected by aura
                itr->second->GetCasterGuid() == target->GetObjectGuid() &&
                // and affected by spellmod
                isAffectedOnSpell(itr->second->GetSpellProto()))
            affectedSelf[itr->second->GetId()] = itr->second->GetCastItemGuid();
    }

    if (!affectedSelf.empty())
    {
        auraData.Points.reserve(aura->GetAuraEffects().size());
        bool hasEstimatedAmounts = false;
        for (AuraEffect const* effect : GetBase()->GetAuraEffects())
        {
            if (effect && HasEffect(effect->GetEffIndex()))       // Not all of aura's effects have to be applied on every target
            {
                Trinity::Containers::EnsureWritableVectorIndex(auraData.Points, effect->GetEffIndex()) = float(effect->GetAmount());
                if (effect->GetEstimatedAmount())
                    hasEstimatedAmounts = true;
            }
        }
        if (hasEstimatedAmounts)
        {
            // When sending EstimatedPoints all effects (at least up to the last one that uses GetEstimatedAmount) must have proper value in packet
            auraData.EstimatedPoints.resize(auraData.Points.size());
            for (AuraEffect const* effect : GetBase()->GetAuraEffects())
                if (effect && HasEffect(effect->GetEffIndex()))       // Not all of aura's effects have to be applied on every target
                    auraData.EstimatedPoints[effect->GetEffIndex()] = effect->GetEstimatedAmount().value_or(effect->GetAmount());
        }
    }
}
        Player* pTarget = target->GetTypeId() == TYPEID_PLAYER ? (Player*)target : nullptr;

        for (const auto& map_itr : affectedSelf)
        {
            Item* item = pTarget && map_itr.second ? pTarget->GetItemByGuid(map_itr.second) : nullptr;
            target->RemoveAurasDueToSpell(map_itr.first);
            target->CastSpell(target, map_itr.first, true, item);
        }
    }
}

struct ReapplyAffectedPassiveAurasHelper
{
    explicit ReapplyAffectedPassiveAurasHelper(Aura* _aura) : aura(_aura) {}
    void operator()(Unit* unit) const
    {
        aura->ReapplyAffectedPassiveAuras(unit);
    }
    Aura* aura;
};

void Aura::ReapplyAffectedPassiveAuras()
{
    // not reapply spell mods with charges (use original value because processed and at remove)
    if (GetSpellProto()->procCharges)
        return;

    // not reapply some spell mods ops (mostly speedup case)
    switch (m_modifier.m_miscvalue)
    {
        case SPELLMOD_DURATION:
        case SPELLMOD_CHARGES:
        case SPELLMOD_NOT_LOSE_CASTING_TIME:
        case SPELLMOD_CASTING_TIME:
        case SPELLMOD_COOLDOWN:
        case SPELLMOD_COST:
        case SPELLMOD_ACTIVATION_TIME:
        case SPELLMOD_GLOBAL_COOLDOWN:
        case SPELLMOD_SPEED:
        case SPELLMOD_HASTE:
        case SPELLMOD_ATTACK_POWER:
            return;
    }

    // reapply talents to own passive persistent auras
    ReapplyAffectedPassiveAuras(GetTarget());

    // re-apply talents/passives/area auras applied to pet/totems (it affected by player spellmods)
    GetTarget()->CallForAllControlledUnits(ReapplyAffectedPassiveAurasHelper(this), CONTROLLED_PET | CONTROLLED_TOTEMS);
}

/*********************************************************/
/***               BASIC AURA FUNCTION                 ***/
/*********************************************************/
void Aura::HandleAddModifier(bool apply, bool Real)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER || !Real)
        return;

    if (m_modifier.m_miscvalue >= MAX_SPELLMOD)
        return;

    if (apply)
    {
        // Add custom charges for some mod aura
        switch (GetSpellProto()->Id)
        {
            case 17941:                                     // Shadow Trance
            case 22008:                                     // Netherwind Focus
                GetHolder()->SetAuraCharges(1);
                break;
        }

        m_spellmod = new SpellModifier(
            SpellModOp(m_modifier.m_miscvalue),
            SpellModType(m_modifier.m_auraname),            // SpellModType value == spell aura types
            m_modifier.m_amount,
            this,
            // prevent expire spell mods with (charges > 0 && m_stackAmount > 1)
            // all this spell expected expire not at use but at spell proc event check
            GetSpellProto()->StackAmount > 1 ? 0 : GetHolder()->GetAuraCharges());
    }

    ASSERT(m_spellmod);
    ((Player*)GetTarget())->AddSpellMod(m_spellmod, apply);
    if (!apply)
        m_spellmod = nullptr; // Deja supprime par Player::AddSpellMod.

    ReapplyAffectedPassiveAuras();
}

void Aura::TriggerSpell()
{
    ObjectGuid casterGUID = GetCasterGuid();
    Unit* triggerTarget = GetTriggerTarget();

    if (!casterGUID || !triggerTarget)
        return;

    // generic casting code with custom spells and target/caster customs
    uint32 trigger_spell_id = GetSpellProto()->EffectTriggerSpell[m_effIndex];

    SpellEntry const* triggeredSpellInfo = sSpellMgr.GetSpellEntry(trigger_spell_id);
    SpellEntry const* auraSpellInfo = GetSpellProto();
    uint32 auraId = auraSpellInfo->Id;
    Unit* target = GetTarget();

    uint32 spellRandom;

    // not in banished state
    if (triggerTarget->HasUnitState(UNIT_STAT_ISOLATED))
        return;

    // specific code for cases with no trigger spell provided in field
    if (triggeredSpellInfo == nullptr)
    {
        switch (auraSpellInfo->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
            {
                switch (auraId)
                {
                    // Firestone Passive (1-5 ranks)
                    case 758:
                    case 17945:
                    case 17947:
                    case 17949:
                    {
                        if (triggerTarget->GetTypeId() != TYPEID_PLAYER)
                            return;
                        Item* item = ((Player*)triggerTarget)->GetWeaponForAttack(BASE_ATTACK);
                        if (!item)
                            return;
                        uint32 enchant_id = 0;
                        switch (GetId())
                        {
                            case   758:
                                enchant_id = 1803;
                                break;   // Rank 1
                            case 17945:
                                enchant_id = 1823;
                                break;   // Rank 2
                            case 17947:
                                enchant_id = 1824;
                                break;   // Rank 3
                            case 17949:
                                enchant_id = 1825;
                                break;   // Rank 4
                            default:
                                return;
                        }
                        // remove old enchanting before applying new
                        ((Player*)triggerTarget)->ApplyEnchantment(item, TEMP_ENCHANTMENT_SLOT, false);
                        item->SetEnchantment(TEMP_ENCHANTMENT_SLOT, enchant_id, m_modifier.periodictime + 1000, 0);
                        // add new enchanting
                        ((Player*)triggerTarget)->ApplyEnchantment(item, TEMP_ENCHANTMENT_SLOT, true);
                        return;
                    }
//                    // Periodic Mana Burn
//                    case 812: break;
//                    // Polymorphic Ray
//                    case 6965: break;
//                    // Fire Nova (1-7 ranks)
//                    case 8350:
//                    case 8508:
//                    case 8509:
//                    case 11312:
//                    case 11313:
//                    case 25540:
//                    case 25544:
//                        break;
                    // Thaumaturgy Channel
                    case 9712:
                        trigger_spell_id = 21029;
                        break;
//                    // Egan's Blaster
//                    case 17368: break;
//                    // Haunted
//                    case 18347: break;
//                    // Ranshalla Waiting
//                    case 18953: break;
//                    // Inferno
//                    case 19695: break;
//                    // Frostwolf Muzzle DND
//                    case 21794: break;
//                    // Alterac Ram Collar DND
//                    case 21866: break;
//                    // Celebras Waiting
//                    case 21916: break;
                    // Brood Affliction: Bronze
                    case 23170:
                    {
                        int rand = urand(0, 9);
                        if (rand < 4)   // Ustaag <Nostalrius> : 40% chance
                            target->CastSpell(target, 23171, true, nullptr, this);
                        return;
                    }
                    case 23493:                             // Restoration
                    {
                        int32 heal = triggerTarget->GetMaxHealth() / 10;
                        triggerTarget->DealHeal(triggerTarget, heal, auraSpellInfo);

                        if (int32 mana = triggerTarget->GetMaxPower(POWER_MANA))
                        {
                            mana /= 10;
                            triggerTarget->EnergizeBySpell(triggerTarget, 23493, mana, POWER_MANA);
                        }
                        return;
                    }
//                    // Stoneclaw Totem Passive TEST
//                    case 23792: break;
//                    // Axe Flurry
//                    case 24018: break;
//                    // Mark of Arlokk
//                    case 24210: break;
//                    // Restoration
//                    case 24379: break;
//                    // Happy Pet
//                    case 24716: break;
//                    // Dream Fog
//                    case 24780: break;
//                    // Cannon Prep
//                    case 24832: break;
                    case 24834:                             // Shadow Bolt Whirl
                    {
                        uint32 spellForTick[8] = { 24820, 24821, 24822, 24823, 24835, 24836, 24837, 24838 };
                        trigger_spell_id = spellForTick[GetAuraTicks() % 8];
                        break;
                    }
//                    // Stink Trap
//                    case 24918: break;
//                    // Agro Drones
//                    case 25152: break;
                    case 25371:                             // Consume
                    {
                        int32 bpDamage = triggerTarget->GetMaxHealth() * 10 / 100;
                        triggerTarget->CastCustomSpell(triggerTarget, 25373, bpDamage, {}, {}, true, nullptr, this, casterGUID);
                        return;
                    }
//                    // Pain Spike
//                    case 25572: break;
                    case 26009:                             // Rotate 360
                    case 26136:                             // Rotate -360
                    {
                        float newAngle = target->GetOrientation();

                        if (auraId == 26009)
                            newAngle += M_PI_F / 40;
                        else
                            newAngle -= M_PI_F / 40;

                        newAngle = MapManager::NormalizeOrientation(newAngle);
                        target->SetFacingTo(newAngle);
                        target->CastSpell(target, 26029, true);
                        return;
                    }
//                    // Consume
//                    case 26196: break;
//                    // Berserk
//                    case 26615: break;
//                    // Defile
//                    case 27177: break;
//                    // Teleport: IF/UC
//                    case 27601: break;
//                    // Five Fat Finger Exploding Heart Technique
//                    case 27673: break;
                    // Nitrous Boost
                    case 27746:
                    {
                        if (target->GetPower(POWER_MANA) >= 10)
                        {
                            target->ModifyPower(POWER_MANA, -10);
                            target->SendEnergizeSpellLog(target, 27746, -10, POWER_MANA);
                        }
                        else
                            target->RemoveAurasDueToSpell(27746);
                        return;
                    }
                    // Steam Tank Passive
                    case 27747:
                    {
                        uint32 tonkmana = target->GetPower(POWER_MANA);
                        if (tonkmana < 100)
                        {
                            target->ModifyPower(POWER_MANA, tonkmana > 90 ? (100 - tonkmana) : 10);
                        }
                        return;
                    }
                    case 27808:                             // Frost Blast
                    {
                        int32 bpDamage = triggerTarget->GetMaxHealth() * 26 / 100;
                        triggerTarget->CastCustomSpell(triggerTarget, 29879, bpDamage, {}, {}, true, nullptr, this, casterGUID);
                        return;
                    }
                    // Detonate Mana
                    case 27819:
                    {
                        // 50% Mana Burn
                        int32 bpDamage = (int32)triggerTarget->GetPower(POWER_MANA) / 2;
                        triggerTarget->ModifyPower(POWER_MANA, -bpDamage);
                        triggerTarget->CastCustomSpell(triggerTarget, 27820, bpDamage, {}, {}, true, nullptr, this, triggerTarget->GetObjectGuid());
                        return;
                    }
                    // Stalagg Chain and Feugen Chain
                    case 28096:
                    case 28111:
                    {
                        // X-Chain is casted by Tesla to X, so: caster == Tesla, target = X
                        Unit* pCaster = GetCaster();
                        if (pCaster && pCaster->GetTypeId() == TYPEID_UNIT && !pCaster->IsWithinDistInMap(target, 60.0f))
                        {
                            pCaster->InterruptNonMeleeSpells(true);
                            ((Creature*)pCaster)->SetInCombatWithZone();
                            // Stalagg Tesla Passive or Feugen Tesla Passive
                            pCaster->CastSpell(pCaster, auraId == 28096 ? 28097 : 28109, true, nullptr, nullptr, target->GetObjectGuid());
                        }
                        return;
                    }
//                    // Controller Timer
//                    case 28095: break;
//                    // Stalagg Tesla Passive
//                    case 28097: break;
//                    // Feugen Tesla Passive
//                    case 28109: break;
//                    // Mark of Didier
//                    case 28114: break;
//                    // Communique Timer, camp
//                    case 28346: break;
//
                    case 28522: // Icebolt
                    {
                        if (target && target->IsAlive() && !target->HasAura(31800))
                        {
                            target->CastSpell(target, 31800, true); // Icebolt which causes immunity to frost dmg
                            trigger_spell_id = 28535; //summon ice block
                            break;
                        }
                        else
                        {
                            return;
                        }
                    }
                    // Silithyst
//                  case 29519: break;
                    default:
                        break;
                }
                break;
            }
            case SPELLFAMILY_MAGE:
            {
                switch (auraId)
                {
                    case 66:                                // Invisibility
                        // Here need periodic trigger reducing threat spell (or do it manually)
                        return;
                    default:
                        break;
                }
                break;
            }
//            case SPELLFAMILY_WARRIOR:
//            {
//                switch(auraId)
//                {
//                    // Wild Magic
//                    case 23410: break;
//                    // Corrupted Totems
//                    case 23425: break;
//                    default:
//                        break;
//                }
//                break;
//            }
//            case SPELLFAMILY_PRIEST:
//            {
//                switch(auraId)
//                {
//                    // Blue Beam
//                    case 32930: break;
//                    default:
//                        break;
//                }
//                break;
//            }
            case SPELLFAMILY_DRUID:
            {
                switch (auraId)
                {
                    case 768:                               // Cat Form
                        // trigger_spell_id not set and unknown effect triggered in this case, ignoring for while
                        return;
                    case 22842:                             // Frenzied Regeneration
                    case 22895:
                    case 22896:
                    {
                        float LifePerRage = GetModifier()->m_amount;

std::string AuraApplication::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << "Base: " << (GetBase() ? GetBase()->GetDebugInfo() : "NULL")
        << "\nTarget: " << (GetTarget() ? GetTarget()->GetDebugInfo() : "NULL");
    return sstr.str();
}

uint32 Aura::BuildEffectMaskForOwner(SpellInfo const* spellProto, uint32 availableEffectMask, WorldObject* owner)
{
    ASSERT_NODEBUGINFO(spellProto);
    ASSERT_NODEBUGINFO(owner);
    uint32 effMask = 0;
    switch (owner->GetTypeId())
    {
        case TYPEID_UNIT:
        case TYPEID_PLAYER:
            for (SpellEffectInfo const& spellEffectInfo : spellProto->GetEffects())
            {
                if (spellEffectInfo.IsUnitOwnedAuraEffect())
                    effMask |= 1 << spellEffectInfo.EffectIndex;
            }
            break;
        case TYPEID_DYNAMICOBJECT:
            for (SpellEffectInfo const& spellEffectInfo : spellProto->GetEffects())
                        int32 lRage = target->GetPower(POWER_RAGE);
                        if (lRage > 100)                    // rage stored as rage*10
                            lRage = 100;
                        target->ModifyPower(POWER_RAGE, -lRage);
                        float FRTriggerBasePoints = lRage * LifePerRage / 10;
                        target->CastCustomSpell(target, 22845, dither(FRTriggerBasePoints), {}, {}, true, nullptr, this);
                        return;
                    }
                    default:
                        break;
                }
                break;
            }
            case SPELLFAMILY_SHAMAN:
            {
                switch (auraId)
                {
                    case 28820:                             // Lightning Shield (The Earthshatterer set trigger after cast Lighting Shield)
                    {
                        // Need remove self if Lightning Shield not active
                        Unit::SpellAuraHolderMap const& auras = triggerTarget->GetSpellAuraHolderMap();
                        for (const auto& aura : auras)
                        {
                            SpellEntry const* spell = aura.second->GetSpellProto();
                            if (spell->IsFitToFamily<SPELLFAMILY_SHAMAN, CF_SHAMAN_LIGHTNING_SHIELD>())
                                return;
                        }
                        triggerTarget->RemoveAurasDueToSpell(28820);
                        return;
                    }
                    default:
                        break;
                }
                break;
            }
            default:
                break;
        }

        // Reget trigger spell proto
        triggeredSpellInfo = sSpellMgr.GetSpellEntry(trigger_spell_id);
    }
    else
    {
        // Spell exist but require custom code
        switch (auraId)
        {
            case 7054:
                spellRandom = urand(0, 14) + 7038;
                target->CastSpell(target, spellRandom, true, nullptr, this);
                return;
                break;
            case 8892:  // Goblin Rocket Boots
            case 13141: // Gnomish Rocket Boots
                // 20 ticks, et une chance sur 5 d'exploser.
                if (urand(0, 20 * 5 - 1) != 0)
                    return;
                break;
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
            case 9347:                                      // Mortal Strike
            {
                if (spellEffectInfo.IsEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA))
                    effMask |= 1 << spellEffectInfo.EffectIndex;
                // expected selection current fight target
                triggerTarget = GetTarget()->GetVictim();
                if (!triggerTarget)
                    return;

                // avoid triggering for far target
                SpellRangeEntry const* srange = sSpellRangeStore.LookupEntry(triggeredSpellInfo->rangeIndex);
                float max_range = GetSpellMaxRange(srange);
                if (!triggerTarget->IsWithinDist(GetTarget(), max_range))
                    return;

                break;
            }
#endif
            case 1010:                                      // Curse of Idiocy
            {
                // TODO: spell casted by result in correct way mostly
                // BUT:
                // 1) target show casting at each triggered cast: target don't must show casting animation for any triggered spell
                //      but must show affect apply like item casting
                // 2) maybe aura must be replace by new with accumulative stat mods instead stacking

                // prevent cast by triggered auras
                if (casterGUID == triggerTarget->GetObjectGuid())
                    return;

                // stop triggering after each affected stats lost > 90
                int32 intelectLoss = 0;
                int32 spiritLoss = 0;

                Unit::AuraList const& mModStat = triggerTarget->GetAurasByType(SPELL_AURA_MOD_STAT);
                for (const auto i : mModStat)
                {
                    if (i->GetId() == 1010)
                    {
                        switch (i->GetModifier()->m_miscvalue)
                        {
                            case STAT_INTELLECT:
                                intelectLoss += i->GetModifier()->m_amount;
                                break;
                            case STAT_SPIRIT:
                                spiritLoss   += i->GetModifier()->m_amount;
                                break;
                            default:
                                break;
                        }
                    }
                }

                if (intelectLoss <= -90 && spiritLoss <= -90)
                    return;

                break;
            }
            case 16191:                                     // Mana Tide
            {
            triggerTarget->CastCustomSpell(triggerTarget, trigger_spell_id, dither(m_modifier.m_amount), {}, {}, true, nullptr, this);
                return;
            }
            //Frost Trap Aura
            case 13810:
            {
                Unit* caster = GetCaster();
                if (!caster)
                    return;
                // Pour le talent hunt 'Piege' par exemple (chances de stun)
                caster->ProcDamageAndSpell(ProcSystemArguments(target, (PROC_FLAG_ON_TRAP_ACTIVATION | PROC_FLAG_SUCCESSFUL_AOE), PROC_FLAG_NONE, PROC_EX_NORMAL_HIT, 1, BASE_ATTACK, GetSpellProto()));
                return;
            }
            // Thaddius negative charge
            case 28084:
            {
                // Lets only process the following when in naxx, otherwise it can become expensive as hell
                if (triggerTarget->GetMap()->GetId() != 533)
                    break;
                Unit* caster = GetCaster();

                int numStacks = 0;
                // Finding the amount of other players within 13yd that has the same polarity
                Map::PlayerList const& pList = triggerTarget->GetMap()->GetPlayers();
                for (const auto& it : pList)
                {
                    Player* pPlayer = it.getSource();
                    if (pPlayer->GetGUID() == casterGUID) continue;
                    if (!pPlayer) continue;
                    if (pPlayer->IsDead()) continue;
                    // 2d distance should be good enough
                    if (pPlayer->HasAura(28084) && caster->GetDistance2d(pPlayer) < 13.0f) // 13.0f taken from dbc
                    {
                        ++numStacks;
                    }
                }
                if (numStacks > 0)
                {
                    if (!triggerTarget->HasAura(29660))
                        triggerTarget->AddAura(29660);
                    triggerTarget->GetAura(29660, EFFECT_INDEX_0)->GetHolder()->SetStackAmount(numStacks);
                }
                else
                    triggerTarget->RemoveAurasDueToSpell(29659);
                break;
            }
            // Thaddius positive charge
            case 28059:
            {
                // Lets only process the following when in naxx, otherwise it can become expensive as hell
                if (triggerTarget->GetMap()->GetId() != 533)
                    break;
                Unit* caster = GetCaster();

Aura* Aura::TryRefreshStackOrCreate(AuraCreateInfo& createInfo, bool updateEffectMask)
{
    ASSERT_NODEBUGINFO(createInfo.Caster || !createInfo.CasterGUID.IsEmpty());
                int numStacks = 0;
                // Finding the amount of other players within 13yd that has the same polarity
                Map::PlayerList const& pList = triggerTarget->GetMap()->GetPlayers();
                for (const auto& it : pList)
                {
                    Player* pPlayer = it.getSource();
                    if (!pPlayer) continue;
                    if (pPlayer->GetGUID() == triggerTarget->GetGUID()) continue;
                    if (pPlayer->IsDead()) continue;
                    // 2d distance should be good enough
                    if (pPlayer->HasAura(28059) && caster->GetDistance2d(pPlayer) < 13.0f) // 13.0f taken from dbc
                    {
                        ++numStacks;
                    }
                }
                if (numStacks > 0)
                {
                    if (!triggerTarget->HasAura(29659))
                        triggerTarget->AddAura(29659);
                    triggerTarget->GetAura(29659, EFFECT_INDEX_0)->GetHolder()->SetStackAmount(numStacks);
                }
                else
                    triggerTarget->RemoveAurasDueToSpell(29659);
                break;
            }
            // Activate MG Turret
            case 25026:
            {
                if (target->GetPower(POWER_MANA) >= 10)
                {
                    target->ModifyPower(POWER_MANA, -10);
                    target->SendEnergizeSpellLog(target, 25026, -10, POWER_MANA);
                }
                else
                    target->RemoveAurasDueToSpell(25026);
                break;
            }
            // Flamethrower
            case 25027:
            {
                if (target->GetPower(POWER_MANA) >= 10)
                {
                    target->ModifyPower(POWER_MANA, -10);
                    target->SendEnergizeSpellLog(target, 25027, -10, POWER_MANA);
                }
                else
                    target->RemoveAurasDueToSpell(25027);
                break;
            }
        }
    }

    if (createInfo.IsRefresh)
        *createInfo.IsRefresh = false;

    createInfo._auraEffectMask = Aura::BuildEffectMaskForOwner(createInfo._spellInfo, createInfo._auraEffectMask, createInfo._owner);
    createInfo._targetEffectMask &= createInfo._auraEffectMask;

    uint32 effMask = createInfo._auraEffectMask;
    if (createInfo._targetEffectMask)
        effMask = createInfo._targetEffectMask;

    if (!effMask)
        return nullptr;
    Unit* triggerCaster = triggerTarget;
    WorldObject* triggerTargetObject = nullptr;

    if (Aura* foundAura = createInfo._owner->ToUnit()->_TryStackingOrRefreshingExistingAura(createInfo))
    {
        // we've here aura, which script triggered removal after modding stack amount
        // check the state here, so we won't create new Aura object
        if (foundAura->IsRemoved())
            return nullptr;
    // for channeled spell cast applied from aura owner to channel target (persistent aura affects already applied to true target)
    // some periodic casts applied to targets, so need select proper caster (ex. 15790)
    if (IsChanneled() && GetSpellProto()->Effect[GetEffIndex()] != SPELL_EFFECT_PERSISTENT_AREA_AURA)
    {
        // interesting 2 cases: periodic aura at caster of channeled spell
        if (target->GetObjectGuid() == casterGUID)
        {
            triggerCaster = target;

        if (createInfo.IsRefresh)
            *createInfo.IsRefresh = true;
            if (WorldObject* channelTarget = target->GetMap()->GetWorldObject(target->GetChannelObjectGuid()))
            {
                if (channelTarget->isType(TYPEMASK_UNIT))
                    triggerTarget = (Unit*)channelTarget;
                else
                    triggerTargetObject = channelTarget;
            }
        }
        // or periodic aura at caster channel target
        else if (Unit* caster = GetCaster())
        {
            if (target->GetObjectGuid() == caster->GetChannelObjectGuid())
            {
                triggerCaster = caster;
                triggerTarget = target;
            }
        }
    }

        // add owner
        Unit* unit = createInfo._owner->ToUnit();

        // check effmask on owner application (if existing)
        if (updateEffectMask)
            if (AuraApplication* aurApp = foundAura->GetApplicationOfTarget(unit->GetGUID()))
                aurApp->UpdateApplyEffectMask(effMask, false);
        return foundAura;
    // All ok cast by default case
    if (triggeredSpellInfo)
    {
        if (triggerTargetObject)
            triggerCaster->CastSpell(triggerTargetObject->GetPositionX(), triggerTargetObject->GetPositionY(), triggerTargetObject->GetPositionZ(),
                                     triggeredSpellInfo, true, nullptr, this, casterGUID);
        else
            triggerCaster->CastSpell(triggerTarget, triggeredSpellInfo, true, nullptr, this, casterGUID);
    }
    else
        return Create(createInfo);
    {
        if (Unit* caster = GetCaster())
        {
            if (triggerTarget->GetTypeId() != TYPEID_UNIT || !sScriptMgr.OnEffectDummy(caster, GetId(), GetEffIndex(), (Creature*)triggerTarget))
                sLog.outError("Aura::TriggerSpell: Spell %u have 0 in EffectTriggered[%d], not handled custom case?", GetId(), GetEffIndex());
        }
    }
}

Aura* Aura::TryCreate(AuraCreateInfo& createInfo)
/*********************************************************/
/***                  AURA EFFECTS                     ***/
/*********************************************************/

void Aura::HandleAuraDummy(bool apply, bool Real)
{
    uint32 effMask = createInfo._auraEffectMask;
    if (createInfo._targetEffectMask)
        effMask = createInfo._targetEffectMask;

    effMask = Aura::BuildEffectMaskForOwner(createInfo._spellInfo, effMask, createInfo._owner);
    if (!effMask)
        return nullptr;
    // spells required only Real aura add/remove
    if (!Real)
        return;

    Unit* target = GetTarget();

    return Create(createInfo);
}
    // AT APPLY
    if (apply)
    {
        switch (GetSpellProto()->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
            {
                switch (GetId())
                {
                    case 2584:                              // Waiting to Resurrect
                    {
                        // for cases where aura would re-apply and player is no longer in BG
                        if (Unit* caster = GetCaster())
                        {
                            if (Player* player = caster->ToPlayer())
                                if (!player->InBattleGround())
                                    player->RemoveAurasDueToSpell(2584);
                        }
                        return;
                    }
                    case 6758:                              // Party Fever
                    {
                        if (Player* pPlayer = ToPlayer(target))
                        {
                            if (!pPlayer->IsInCombat())
                                pPlayer->HandleEmoteCommand(EMOTE_STATE_DANCE);
                        }
                        return;
                    }
                    case 8067:                              // Party Time!
                    {
                        m_isPeriodic = true;
                        m_modifier.periodictime = 10 * IN_MILLISECONDS;;
                        return;
                    }
                    case 10255:                             // Stoned
                    {
                        if (Unit* caster = GetCaster())
                        {
                            if (caster->GetTypeId() != TYPEID_UNIT)
                                return;

Aura* Aura::Create(AuraCreateInfo& createInfo)
{
    // try to get caster of aura
    if (!createInfo.CasterGUID.IsEmpty())
    {
        if (createInfo.CasterGUID.IsUnit())
        {
            if (createInfo._owner->GetGUID() == createInfo.CasterGUID)
                createInfo.Caster = createInfo._owner->ToUnit();
            else
                createInfo.Caster = ObjectAccessor::GetUnit(*createInfo._owner, createInfo.CasterGUID);
        }
    }
    else if (createInfo.Caster)
        createInfo.CasterGUID = createInfo.Caster->GetGUID();
                            caster->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                            caster->AddUnitState(UNIT_STAT_ROOT);
                        }
                        return;
                    }
                    case 13139:                             // net-o-matic
                    {
                        // root to self part of (root_target->charge->root_self sequence
                        if (Unit* caster = GetCaster())
                            caster->CastSpell(caster, 13138, true, nullptr, this);
                        GetHolder()->SetAuraDuration(0); // Remove aura (else stays for ever, and casts at login)
                        return;
                    }
                    case 16336: // Haunting Phantoms
                    {
                        m_isPeriodic = true;
                        m_modifier.periodictime = urand(30, 90) * IN_MILLISECONDS;;
                        return;
                    }
                    case 26234:                             // Ragnaros Submerge Visual
                    {
                        if (Unit* caster = GetCaster())
                        {
                            caster->CastSpell(caster, 21107, true); // Ragnaros Submerge Fade
                            caster->CastSpell(caster, 21859, true); // Ragnaros Submerge Effect
                            caster->RemoveAurasDueToSpell(26234);   // Need remove Submerge Visual after apply
                        }
                        return;
                    }
                    case 22646:                             // Goblin Rocket Helmet
                    {
                        if (Unit* caster = GetCaster())
                            caster->CastSpell(caster, 13360, true);
                        return;
                    }
                    case 24596: // Intoxicating Venom
                    {
                        if (target)
                        {
                            m_isPeriodic            = true;
                            m_modifier.periodictime = 1000;
                        }
                        return;
                    }
                    case 29154:
                    {
                        Unit* caster = GetCaster();
                        if (!caster) break;
                        caster->HandleEmote(EMOTE_STATE_SUBMERGED);
                        break;
                    }
                }
                break;
            }
            case SPELLFAMILY_PALADIN:
            {
#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_8_4
                // Judgement of Command
                if (GetSpellProto()->SpellIconID == 561)
                {
                    if (GetCaster() != GetTarget())
                    {
                        m_isPeriodic = true;
                        m_modifier.periodictime = 2000; // guess
                    }
                    return;
                }
#endif
                break;
            }
            case SPELLFAMILY_SHAMAN:
                break;
        }
    }
    // AT REMOVE
    else
    {
        if (IsQuestTameSpell(GetId()) && target->IsAlive())
        {
            if (m_removeMode != AURA_REMOVE_BY_CHANNEL)
                return;

    // check if aura can be owned by owner
    if (createInfo._owner->isType(TYPEMASK_UNIT))
        if (!createInfo._owner->IsInWorld() || createInfo._owner->ToUnit()->IsDuringRemoveFromWorld())
            // owner not in world so don't allow to own not self cast single target auras
            if (createInfo.CasterGUID != createInfo._owner->GetGUID() && createInfo._spellInfo->IsSingleTarget())
                return nullptr;
            Unit* caster = GetCaster();
            if (!caster || !caster->IsAlive())
                return;

    Aura* aura = nullptr;
    switch (createInfo._owner->GetTypeId())
    {
        case TYPEID_UNIT:
        case TYPEID_PLAYER:
        {
            aura = new UnitAura(createInfo);

            // aura can be removed in Unit::_AddAura call
            if (aura->IsRemoved())
                return nullptr;

            // add owner
            uint32 effMask = createInfo._auraEffectMask;
            if (createInfo._targetEffectMask)
                effMask = createInfo._targetEffectMask;

            effMask = Aura::BuildEffectMaskForOwner(createInfo._spellInfo, effMask, createInfo._owner);
            ASSERT_NODEBUGINFO(effMask);

            Unit* unit = createInfo._owner->ToUnit();
            aura->ToUnitAura()->AddStaticApplication(unit, effMask);
            break;
        }
        case TYPEID_DYNAMICOBJECT:
            createInfo._auraEffectMask = Aura::BuildEffectMaskForOwner(createInfo._spellInfo, createInfo._auraEffectMask, createInfo._owner);
            ASSERT_NODEBUGINFO(createInfo._auraEffectMask);

            aura = new DynObjAura(createInfo);
            break;
        default:
            ABORT();
            return nullptr;
    }
            uint32 finalSpellId = 0;
            switch (GetId())
            {
                case 19548:
                    finalSpellId = 19597;
                    break;
                case 19674:
                    finalSpellId = 19677;
                    break;
                case 19687:
                    finalSpellId = 19676;
                    break;
                case 19688:
                    finalSpellId = 19678;
                    break;
                case 19689:
                    finalSpellId = 19679;
                    break;
                case 19692:
                    finalSpellId = 19680;
                    break;
                case 19693:
                    finalSpellId = 19684;
                    break;
                case 19694:
                    finalSpellId = 19681;
                    break;
                case 19696:
                    finalSpellId = 19682;
                    break;
                case 19697:
                    finalSpellId = 19683;
                    break;
                case 19699:
                    finalSpellId = 19685;
                    break;
                case 19700:
                    finalSpellId = 19686;
                    break;
            }

            if (finalSpellId)
                caster->CastSpell(target, finalSpellId, true, nullptr, this);

            return;
        }

    // scripts, etc.
    if (aura->IsRemoved())
        return nullptr;

    return aura;
}
        switch (GetId())
        {
            case 126:   // Kilrogg eye
            case 6272:  // Eye of Yesmur
            case 11403: // Dream Vision
                if (Player* pCaster = ToPlayer(GetCaster()))
                    pCaster->UnsummonPossessedMinion();
                return;
            case 10255:                                     // Stoned
            {
                if (Unit* caster = GetCaster())
                {
                    if (caster->GetTypeId() != TYPEID_UNIT)
                        return;
                    caster->ClearUnitState(UNIT_STAT_ROOT | UNIT_STAT_PENDING_ROOT);
                    caster->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }
                return;
            }
            case 11826:
                if (m_removeMode != AURA_REMOVE_BY_EXPIRE)
                    return;

Aura::Aura(AuraCreateInfo const& createInfo) :
m_spellInfo(createInfo._spellInfo), m_castDifficulty(createInfo._castDifficulty), m_castId(createInfo._castId), m_casterGuid(createInfo.CasterGUID),
m_castItemGuid(createInfo.CastItemGUID), m_castItemId(createInfo.CastItemId),
m_castItemLevel(createInfo.CastItemLevel), m_spellVisual({ createInfo.Caster ? createInfo.Caster->GetCastSpellXSpellVisualId(createInfo._spellInfo) : createInfo._spellInfo->GetSpellXSpellVisualId(), 0 }),
m_applyTime(GameTime::GetGameTime()), m_owner(createInfo._owner), m_timeCla(0), m_updateTargetMapInterval(0),
m_casterLevel(createInfo.Caster ? createInfo.Caster->GetLevel() : m_spellInfo->SpellLevel), m_procCharges(0), m_stackAmount(1),
m_isRemoved(false), m_isSingleTarget(false), m_isUsingCharges(false), m_dropEvent(nullptr),
m_procCooldown(TimePoint::min()),
m_lastProcAttemptTime(GameTime::Now() - Seconds(10)), m_lastProcSuccessTime(GameTime::Now() - Seconds(120))
{
    for (SpellPowerEntry const* power : m_spellInfo->PowerCosts)
        if (power && (power->ManaPerSecond != 0 || power->PowerPctPerSecond > 0.0f))
            m_periodicCosts.push_back(power);
                if (Unit* caster = GetCaster())
                    if (caster->GetTypeId() == TYPEID_PLAYER)
                        caster->CastSpell(target, 11828, true, caster->ToPlayer()->GetItemByGuid(GetCastItemGuid()), this);
                break;
            case 12479:                                     // Hex of Jammal'an
                if (Unit* caster = GetCaster())
                {
                    caster->CastSpell(target, 12480, true, nullptr, this);
                    caster->CastSpell(target, 12483, true, nullptr, this);
                }
                return;
            case 12774:                                     // (DND) Belnistrasz Idol Shutdown Visual
            {
                if (m_removeMode == AURA_REMOVE_BY_DEATH)
                    return;

                // Idom Rool Camera Shake <- wtf, don't drink while making spellnames?
                if (Unit* caster = GetCaster())
                    caster->CastSpell(caster, 12816, true);

    m_maxDuration = CalcMaxDuration(createInfo.Caster);
    m_duration = m_maxDuration;
    m_procCharges = CalcMaxCharges(createInfo.Caster);
    m_isUsingCharges = m_procCharges != 0;
    // m_casterLevel = cast item level/caster level, caster level should be saved to db, confirmed with sniffs
}
                return;
            }
            case 20939: // Undying Soul - Dummy aura used for Unstuck command
            {
                if (m_removeMode == AURA_REMOVE_BY_EXPIRE)
                {
                    if (Unit* caster = GetCaster())
                        if (Player* casterPlayer = caster->ToPlayer())
                        {
                            if (casterPlayer->IsAlive() && !casterPlayer->IsInCombat() && !casterPlayer->IsTaxiFlying())
                            {
                                casterPlayer->AddAura(SPELL_ID_PASSIVE_RESURRECTION_SICKNESS); // Add Resurrection Sickness
                                if (sObjectMgr.GetClosestGraveYard(casterPlayer->GetPositionX(), casterPlayer->GetPositionY(), casterPlayer->GetPositionZ(), casterPlayer->GetMapId(), casterPlayer->GetTeam()))
                                    casterPlayer->DealDamage(casterPlayer, casterPlayer->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
                                else
                                {
                                    // If there is no nearby graveyard, player's ghost would spawn at the same spot.
                                    WorldSafeLocsEntry const* ClosestGrave = casterPlayer->GetTeamId() ? sWorldSafeLocsStore.LookupEntry(10) : sWorldSafeLocsStore.LookupEntry(4);
                                    if (ClosestGrave)
                                    {
                                        casterPlayer->SetHealth(1);
                                        casterPlayer->TeleportTo(ClosestGrave->map_id, ClosestGrave->x, ClosestGrave->y, ClosestGrave->z, sObjectMgr.GetWorldSafeLocFacing(ClosestGrave->ID), 0);
                                    }
                                }
                            }
                        }
                }
                return;
            }
            case 24906:                                     // Emeriss Aura
            {
                if (m_removeMode == AURA_REMOVE_BY_DEATH)
                    target->CastSpell(target, 24904, true, nullptr, this);

AuraScript* Aura::GetScriptByType(std::type_info const& type) const
{
    for (AuraScript* loadedScript : m_loadedScripts)
        if (typeid(*loadedScript) == type)
            return loadedScript;
    return nullptr;
}
                return;
            }
            case 25042:                                     // Mark of Nature
            {
                if (m_removeMode == AURA_REMOVE_BY_DEATH)
                    target->CastSpell(target, 25040, true, nullptr, this);
                return;
            }
            case 25185:                                     // Itch
            {
                if (m_removeMode != AURA_REMOVE_BY_EXPIRE)
                    return;

                if (Unit* caster = GetCaster())
                    caster->CastSpell(target, 25187, true);
                return;
            }
            case 26077:                                     // Itch
            {
                if (m_removeMode != AURA_REMOVE_BY_EXPIRE)
                    return;

void Aura::_InitEffects(uint32 effMask, Unit* caster, int32 const* baseAmount)
{
    // shouldn't be in constructor - functions in AuraEffect::AuraEffect use polymorphism
    _effects.resize(GetSpellInfo()->GetEffects().size());
                if (Unit* caster = GetCaster())
                    caster->CastSpell(target, 26078, true);
                return;
            }
            case 23183:                                     // Mark of Frost
            {
                if (m_removeMode == AURA_REMOVE_BY_DEATH)
                    target->CastSpell(target, 23182, true, nullptr, this);
                    return;
            }
            case 28169:                                     // Mutating Injection
            {
                Unit* caster = GetCaster();
                // Mutagen Explosion
                if (m_removeMode == AuraRemoveMode::AURA_REMOVE_BY_DISPEL)
                {
                    caster->CastSpell(target, 28206, true);
                }
                else
                {
                    caster->CastSpell(target, 28206, true, nullptr, this);
                }

    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
        if (effMask & (1 << spellEffectInfo.EffectIndex))
            _effects[spellEffectInfo.EffectIndex] = new AuraEffect(this, spellEffectInfo, baseAmount ? baseAmount + spellEffectInfo.EffectIndex : nullptr, caster);
}
                // Summons Poison Cloud creature
                target->CastSpell(target, 28240, true, nullptr, this);
                return;
            }
            case 24324: // Ivina < Nostalrius > : Hakkar
            {
                target->RemoveAurasDueToSpell(24321);
                return;
            }
            case 28059: // Thaddius positive charge, removing aplify effect on remove
            {
                if (target->HasAura(29659))
                    target->RemoveAurasDueToSpell(29659);
                break;
            }
            case 28084: // Thaddius negative charge, removing aplify effect on remove
            {
                if (target->HasAura(29660))
                    target->RemoveAurasDueToSpell(29660);
                break;
            }
        }

        /*if (m_removeMode == AURA_REMOVE_BY_DEATH) // redundant, AM is cancelled in aura holder removal
        {
            // Stop caster Arcane Missle chanelling on death
            if (GetSpellProto()->IsFitToFamily<SPELLFAMILY_MAGE, CF_MAGE_ARCANE_MISSILES_CHANNEL>())
            {
                if (Unit* caster = GetCaster())
                    caster->InterruptSpell(CURRENT_CHANNELED_SPELL);

                return;
            }
        }*/
    }

    // AT APPLY & REMOVE

    switch (GetSpellProto()->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            switch (GetId())
            {
                case 6606:                                  // Self Visual - Sleep Until Cancelled (DND)
                {
                    if (apply)
                    {
                        target->m_Events.AddLambdaEventAtOffset([target]
                        {
                            target->HandleEmoteState(EMOTE_STATE_SLEEP);
                            target->SetStandState(UNIT_STAND_STATE_SLEEP);
                        }, 500);
                    }

                    return;
                }
                case 24658:                                 // Unstable Power
                {
                    if (apply)
                    {
                        Unit* caster = GetCaster();
                        if (!caster)
                            return;

Unit* Aura::GetCaster() const
{
    if (GetOwner()->GetGUID() == GetCasterGUID())
        return GetUnitOwner();
                        caster->CastSpell(target, 24659, true, nullptr, nullptr, GetCasterGuid());
                    }
                    else
                        target->RemoveAurasDueToSpell(24659);
                    return;
                }
                case 24661:                                 // Restless Strength
                {
                    if (apply)
                    {
                        Unit* caster = GetCaster();
                        if (!caster)
                            return;

                        caster->CastSpell(target, 24662, true, nullptr, nullptr, GetCasterGuid());
                    }
                    else
                        target->RemoveAurasDueToSpell(24662);
                    return;
                }
                case 29266:                                 // Permanent Feign Death
                {
                    // Unclear what the difference really is between them.
                    // Some has effect1 that makes the difference, however not all.
                    // Some appear to be used depending on creature location, in water, at solid ground, in air/suspended, etc
                    // For now, just handle all the same way
                    if (target->GetTypeId() == TYPEID_UNIT)
                        target->SetFeignDeath(apply);

WorldObject* Aura::GetWorldObjectCaster() const
{
    if (GetCasterGUID().IsUnit())
        return GetCaster();

    return ObjectAccessor::GetWorldObject(*GetOwner(), GetCasterGUID());
}

AuraEffect* Aura::GetEffect(uint32 index) const
{
    if (index >= _effects.size())
        return nullptr;
                    return;
                }
            }
            break;
        }
        case SPELLFAMILY_MAGE:
        {
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
            switch (GetId())
            {
                // Frost Warding
                case 11189:
                case 28332:
                {
                    if (Player* pPlayer = target->ToPlayer())
                    {
                        if (apply)
                        {
                            SpellModifier* mod = new SpellModifier(SPELLMOD_RESIST_MISS_CHANCE, SPELLMOD_FLAT, m_modifier.m_amount, GetId(), UI64LIT(0x0000000000000100));
                            pPlayer->AddSpellMod(mod, true);
                        }
                        else
                        {
                            if (SpellModifier *mod = pPlayer->GetSpellMod(SPELLMOD_RESIST_MISS_CHANCE, GetId()))
                                pPlayer->AddSpellMod(mod, false);
                        }
                    }
                    return;
                }
                // Improved Fire Ward
                case 11094:
                case 13043:
                {
                    if (Player* pPlayer = target->ToPlayer())
                    {
                        if (apply)
                        {
                            SpellModifier *mod = new SpellModifier(SPELLMOD_RESIST_MISS_CHANCE, SPELLMOD_FLAT, m_modifier.m_amount, GetId(), UI64LIT(0x0000000000000008));
                            pPlayer->AddSpellMod(mod, true);
                        }
                        else
                        {
                            if (SpellModifier *mod = pPlayer->GetSpellMod(SPELLMOD_RESIST_MISS_CHANCE, GetId()))
                                pPlayer->AddSpellMod(mod, false);
                        }
                    }
                    return;
                }
            }
#endif
            break;
        }
        case SPELLFAMILY_DRUID:
        {
            // Predatory Strikes
            if (target->GetTypeId() == TYPEID_PLAYER && GetSpellProto()->SpellIconID == 1563)
            {
                ((Player*)target)->UpdateAttackPowerAndDamage();
                return;
            }
            // Enrage
            if ((target->GetTypeId() == TYPEID_PLAYER) && (GetId() == 5229))
            {
                ((Player*)target)->UpdateArmor(); // Spell managed in UpdateArmor()
                return;
            }
            break;
        }
        case SPELLFAMILY_ROGUE:
            break;
        case SPELLFAMILY_HUNTER:
            break;
        case SPELLFAMILY_SHAMAN:
        {
            switch (GetId())
            {
                case 6495:                                  // Sentry Totem
                {
                    if (target->GetTypeId() != TYPEID_PLAYER)
                        return;

                    Totem* totem = target->GetTotem(TOTEM_SLOT_AIR);

                    if (totem && apply)
                        ((Player*)target)->GetCamera().SetView(totem);
                    else
                        ((Player*)target)->GetCamera().ResetView();

                    return;
                }
            }
            break;
        }
    }

    // pet auras
    if (PetAura const* petSpell = sSpellMgr.GetPetAura(GetId()))
    {
        if (apply)
            target->AddPetAura(petSpell);
        else
            target->RemovePetAura(petSpell);
        return;
    }

void Aura::_ApplyForTarget(Unit* target, Unit* caster, AuraApplication* auraApp)
{
    ASSERT(target);
    ASSERT(auraApp);
    // aura mustn't be already applied on target
    ASSERT (!IsAppliedOnTarget(target->GetGUID()) && "Aura::_ApplyForTarget: aura musn't be already applied on target");
    if (target->GetTypeId() == TYPEID_PLAYER)
    {
        SpellAreaForAreaMapBounds saBounds = sSpellMgr.GetSpellAreaForAuraMapBounds(GetId());
        if (saBounds.first != saBounds.second)
        {
            uint32 zone, area;
            target->GetZoneAndAreaId(zone, area);

            std::set<uint32> spellsToCast;
            std::set<uint32> spellsToRemove;

            for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
            {
                // some auras remove at aura remove
                if (!itr->second->IsFitToRequirements((Player*)target, zone, area))
                {
                    spellsToRemove.insert(itr->second->spellId);
                }
                // some auras applied at aura apply
                else if (itr->second->autocast)
                {
                    if (!target->HasAura(itr->second->spellId, EFFECT_INDEX_0))
                        spellsToCast.insert(itr->second->spellId);
                }
            }

void Aura::_UnapplyForTarget(Unit* target, Unit* caster, AuraApplication* auraApp)
            for (auto i : spellsToRemove)
                if (spellsToCast.find(i) == spellsToCast.end())
                    target->RemoveAurasDueToSpell(i);

            for (auto i : spellsToCast)
                target->CastSpell(target, i, true);
        }
    }

    // script has to "handle with care", only use where data are not ok to use in the above code.
    if (target->GetTypeId() == TYPEID_UNIT)
        sScriptMgr.OnAuraDummy(this, apply);
}

void Aura::HandleAuraMounted(bool apply, bool Real)
{
    // only at real add/remove aura
    if (!Real)
        return;

    Unit* target = GetTarget();

    if (apply)
    {
        TC_LOG_ERROR("spells", "Aura::_UnapplyForTarget, target: {}, caster: {}, spell:{} was not found in owners application map!",
        target->GetGUID().ToString(), caster ? caster->GetGUID().ToString().c_str() : "Empty", auraApp->GetBase()->GetSpellInfo()->Id);
        ABORT();
    }
        CreatureInfo const* ci = ObjectMgr::GetCreatureTemplate(m_modifier.m_miscvalue);
        if (!ci)
        {
            sLog.outErrorDb("AuraMounted: `creature_template`='%u' not found in database (only need its display_id)", m_modifier.m_miscvalue);
            return;
        }
        uint32 displayId  = Creature::ChooseDisplayId(ci);
        CreatureDisplayInfoAddon const* minfo = sObjectMgr.GetCreatureDisplayInfoRandomGender(displayId);
        if (minfo)
            displayId = minfo->display_id;

        target->Mount(displayId, GetId());
    }
    else
        target->Unmount(true);
}

    _removedApplications.push_back(auraApp);
void Aura::HandleAuraWaterWalk(bool apply, bool Real)
{
    // only at real add/remove aura
    if (!Real)
        return;

    GetTarget()->SetWaterWalking(apply);
}

void Aura::HandleAuraFeatherFall(bool apply, bool Real)
{
    // only at real add/remove aura
    if (!Real)
        return;

    GetTarget()->SetFeatherFall(apply);
}

void Aura::HandleAuraHover(bool apply, bool Real)
{
    // only at real add/remove aura
    if (!Real)
        return;

    GetTarget()->SetHover(apply);
}

void Aura::HandleWaterBreathing(bool apply, bool /*Real*/)
{
    Unit* target = GetTarget();

    if (target->GetTypeId() == TYPEID_PLAYER)
        static_cast<Player*>(target)->SetWaterBreathingIntervalMultiplier(apply ? 0 : target->GetTotalAuraMultiplier(SPELL_AURA_MOD_WATER_BREATHING));
}

void Aura::HandleModWaterBreathing(bool /*apply*/, bool /*Real*/)
{
    Unit* target = GetTarget();

    if (target->GetTypeId() == TYPEID_PLAYER)
        static_cast<Player*>(target)->SetWaterBreathingIntervalMultiplier(target->GetTotalAuraMultiplier(SPELL_AURA_MOD_WATER_BREATHING));
}

std::pair<unsigned int, float> GetShapeshiftDisplayInfo(ShapeshiftForm form, Unit* target){
    unsigned int display_id = 0;
    float mod = 1;
    switch (form)
    {
    case FORM_CAT:

        if (target->IsPlayer())
        {
            if (Player::TeamForRace(target->GetRace()) == ALLIANCE)
                display_id = 892;
            else
                display_id = 8571;
        }
        else
            display_id = 892;
        mod = 0.80f;
        break;
    case FORM_TRAVEL:
        display_id = 632;
        mod = 0.80f;
        break;
    case FORM_AQUA:
        display_id = 2428;
        mod = 0.80f;
        break;
    case FORM_BEAR:
    case FORM_DIREBEAR:
        if (target->IsPlayer())
        {
            if (Player::TeamForRace(target->GetRace()) == ALLIANCE)
                display_id = 2281;
            else
                display_id = 2289;
        }
        else
            display_id = 2281;
        break;
    case FORM_GHOUL:
        if (Player::TeamForRace(target->GetRace()) == ALLIANCE)
            display_id = 10045;
        break;
    case FORM_CREATUREBEAR:
    {
        uint32 modelId = 0;
        if (CreatureDisplayInfoEntry const* pDisplayInfo = sCreatureDisplayInfoStore.LookupEntry(target->GetNativeDisplayId()))
            modelId = pDisplayInfo->ModelId;

        switch (modelId)
        {
            case MODEL_NELF_FEMALE:
            case MODEL_NELF_MALE:
            {
                display_id = 2281;
                break;
            }
            case MODEL_TAUREN_FEMALE:
            case MODEL_TAUREN_MALE:
            {
                display_id = 2289;
                break;
            }
            default:
            {
                display_id = 902;
                break;
            }
        }
        break;
    }
    case FORM_GHOSTWOLF:
        display_id = 4613;
        mod = 0.80f;
        break;
    case FORM_MOONKIN:
        if (target->IsPlayer())
        {
            if (Player::TeamForRace(target->GetRace()) == ALLIANCE)
                display_id = 15374;
            else
                display_id = 15375;
        }
        else
            display_id = 15374;
        break;
    case FORM_TREE:
        display_id = 864;
        break;
    case FORM_SPIRITOFREDEMPTION:
        display_id = 16031;
        break;
    /*case FORM_BATTLESTANCE:
    case FORM_BERSERKERSTANCE:
    case FORM_DEFENSIVESTANCE:
    case FORM_AMBIENT:
    case FORM_SHADOW:
    case FORM_STEALTH:*/
    default:
        break;
    }
    return {display_id,mod};
}

void Aura::HandleAuraModShapeshift(bool apply, bool Real)
{
    if (!Real)
        return;
    ShapeshiftForm form = ShapeshiftForm(m_modifier.m_miscvalue);

    std::vector<Unit*> targetsToRemove;
    Unit* target = GetTarget();

    // mark all auras as ready to remove
    for (auto const& applicationPair : m_applications)
    SpellShapeshiftFormEntry const* ssEntry = sSpellShapeshiftFormStore.LookupEntry(form);
    if (!ssEntry)
    {
        auto itr = targets.find(applicationPair.second->GetTarget());
        // not found in current area - remove the aura
        if (itr == targets.end())
            targetsToRemove.push_back(applicationPair.second->GetTarget());
        sLog.outError("Unknown shapeshift form %u in spell %u", form, GetId());
        return;
    }

    switch (form)
    {
        case FORM_CAT:
        case FORM_TREE:
        case FORM_TRAVEL:
        case FORM_AQUA:
        case FORM_BEAR:
        case FORM_DIREBEAR:
        case FORM_MOONKIN:
        {
            // Cast Shapeshift Form Effect to remove slows and roots.
            target->CastSpell(target, 9033, true);
            break;
        }
        case FORM_BERSERKERSTANCE:
        {
            // cast regular berserker stance when removing Nefarian warrior call
            if (!apply && GetSpellProto()->Id == 23397)
            {
                HandleShapeshiftBoosts(apply);
                target->CastSpell(target, 2458, true);
                return;
            }
        }
        default:
            break;
    }

    std::pair<uint32, float> info = GetShapeshiftDisplayInfo(form, target);
    uint32 display_id = info.first;
    if (display_id > 0 && !target->GetTransForm())
    {
        if (apply)
        {
            target->SetTransformScale(info.second);
            target->SetDisplayId(display_id);
        }
        else
        {
            // needs readding - remove now, will be applied in next update cycle
            // (dbcs do not have auras which apply on same type of targets but have different radius, so this is not really needed)
            if (itr->first->IsImmunedToSpell(GetSpellInfo(), caster, true) || !CanBeAppliedOn(itr->first))
            {
                targetsToRemove.push_back(applicationPair.second->GetTarget());
                continue;
            }

            // check target immunities (for existing targets)
            for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
                if (itr->first->IsImmunedToSpellEffect(GetSpellInfo(), spellEffectInfo, caster, true))
                    itr->second &= ~(1 << spellEffectInfo.EffectIndex);

            // needs to add/remove effects from application, don't remove from map so it gets updated
            if (applicationPair.second->GetEffectMask() != itr->second)
                continue;

            // nothing to do - aura already applied
            // remove from auras to register list
            targets.erase(itr);
            target->ResetTransformScale();
            target->SetDisplayId(target->GetNativeDisplayId());
        }
    }

    // register auras for units
    for (auto itr = targets.begin(); itr != targets.end();)
    if (apply)
    {
        bool addUnit = true;
        AuraApplication* aurApp = GetApplicationOfTarget(itr->first->GetGUID());
        if (!aurApp)
        {
            // check target immunities (for new targets)
            for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
                if (itr->first->IsImmunedToSpellEffect(GetSpellInfo(), spellEffectInfo, caster))
                    itr->second &= ~(1 << spellEffectInfo.EffectIndex);

            if (!itr->second || itr->first->IsImmunedToSpell(GetSpellInfo(), caster) || !CanBeAppliedOn(itr->first))
                addUnit = false;
        }
        Powers PowerType = POWER_MANA;
        switch (form)
        {
            case FORM_CAT:
                PowerType = POWER_ENERGY;
                break;
            case FORM_BEAR:
            case FORM_DIREBEAR:
                PowerType = POWER_RAGE;
                break;
                /*case FORM_TRAVEL:
                case FORM_AQUA:
                case FORM_GHOUL:
                case FORM_CREATUREBEAR:
                case FORM_GHOSTWOLF:
                case FORM_MOONKIN:
                case FORM_AMBIENT:
                case FORM_SHADOW:
                case FORM_STEALTH:
                case FORM_TREE:
                case FORM_SPIRITOFREDEMPTION:
                break;*/
            case FORM_BATTLESTANCE:
            case FORM_BERSERKERSTANCE:
            case FORM_DEFENSIVESTANCE:
                PowerType = POWER_RAGE;
                break;
            default:
                break;
        }

        // remove other shapeshift before applying a new one
        target->RemoveSpellsCausingAura(SPELL_AURA_MOD_SHAPESHIFT, GetHolder());

        if (!(ssEntry->flags1 & SHAPESHIFT_FORM_FLAG_ALLOW_ACTIVITY))
            target->RemoveSpellsCausingAura(SPELL_AURA_WATER_WALK, GetHolder());

        if (PowerType != POWER_MANA)
        {
            // reset power to default values only at power change
            uint32 powaa = target->GetPower(PowerType);
            if (target->GetPowerType() != PowerType)
                target->SetPowerType(PowerType);

            switch (form)
            {
                case FORM_CAT:
                case FORM_BEAR:
                case FORM_DIREBEAR:
                {
                    // get furor proc chance
                    int32 furorChance = 0;
                    Unit::AuraList const& mDummy = target->GetAurasByType(SPELL_AURA_DUMMY);
                    for (const auto i : mDummy)
                    {
                        if (i->GetSpellProto()->SpellIconID == 238)
                        {
                            furorChance = i->GetModifier()->m_amount;
                            break;
                        }
                    }

                    if (m_modifier.m_miscvalue == FORM_CAT)
                    {
                        target->SetPower(POWER_ENERGY, 0);
                        if (irand(1, 100) <= furorChance)
                            target->CastSpell(target, 17099, true, nullptr, this);
                    }
                    else
                    {
                        target->SetPower(POWER_RAGE, powaa);
                        if (irand(1, 100) <= furorChance)
                            target->CastSpell(target, 17057, true, nullptr, this);
                    }
                    break;
                }
                case FORM_BATTLESTANCE:
                case FORM_DEFENSIVESTANCE:
                case FORM_BERSERKERSTANCE:
                {
                    uint32 Rage_val = 0;
                    //Tactical mastery
                    if (target->GetTypeId() == TYPEID_PLAYER)
                    {
                        Unit::AuraList const& aurasOverrideClassScripts = target->GetAurasByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
                        for (const auto aurasOverrideClassScript : aurasOverrideClassScripts)
                        {
                            // select by script id
                            switch (aurasOverrideClassScript->GetModifier()->m_miscvalue)
                            {
                                case 831:
                                    Rage_val =  50;
                                    break;
                                case 832:
                                    Rage_val = 100;
                                    break;
                                case 833:
                                    Rage_val = 150;
                                    break;
                                case 834:
                                    Rage_val = 200;
                                    break;
                                case 835:
                                    Rage_val = 250;
                                    break;
                            }
                            if (Rage_val != 0)
                                break;
                        }
                    }
                    if (target->GetPower(POWER_RAGE) > Rage_val)
                        target->SetPower(POWER_RAGE, Rage_val);
                    break;
                }
                default:
                    break;
            }
        }

        target->SetShapeshiftForm(form);
    }
    else
    {
        if (target->GetClass() == CLASS_DRUID)
        {
            target->SetPowerType(POWER_MANA);
            target->SetPower(POWER_RAGE, 0);
        }

        target->SetShapeshiftForm(FORM_NONE);
    }

        // Dynobj auras don't hit flying targets
        if (GetType() == DYNOBJ_AURA_TYPE && itr->first->IsInFlight())
            addUnit = false;

        // Do not apply aura if it cannot stack with existing auras
        if (addUnit)
        {
            // Allow to remove by stack when aura is going to be applied on owner
            if (itr->first != GetOwner())
            {
                // check if not stacking aura already on target
                // this one prevents unwanted usefull buff loss because of stacking and prevents overriding auras periodicaly by 2 near area aura owners
                for (Unit::AuraApplicationMap::iterator iter = itr->first->GetAppliedAuras().begin(); iter != itr->first->GetAppliedAuras().end(); ++iter)
                {
                    Aura const* aura = iter->second->GetBase();
                    if (!CanStackWith(aura))
                    {
                        addUnit = false;
                        break;
                    }
                }
            }
        }

        if (!addUnit)
            itr = targets.erase(itr);
        else
        {
            // owner has to be in world, or effect has to be applied to self
            if (!GetOwner()->IsSelfOrInSameMap(itr->first))
            {
                /// @todo There is a crash caused by shadowfiend load addon
                TC_LOG_FATAL("spells", "Aura {}: Owner {} (map {}) is not in the same map as target {} (map {}).", GetSpellInfo()->Id,
                    GetOwner()->GetName(), GetOwner()->IsInWorld() ? GetOwner()->GetMap()->GetId() : uint32(-1),
                    itr->first->GetName(), itr->first->IsInWorld() ? itr->first->GetMap()->GetId() : uint32(-1));
                ABORT();
            }

            if (aurApp)
            {
                aurApp->UpdateApplyEffectMask(itr->second, true); // aura is already applied, this means we need to update effects of current application
                itr = targets.erase(itr);
            }
            else
            {
                itr->first->_CreateAuraApplication(this, itr->second);
                ++itr;
            }
        }
    }
    // adding/removing linked auras
    // add/remove the shapeshift aura's boosts
    HandleShapeshiftBoosts(apply);
    target->UpdateModelData();

    if (target->GetTypeId() == TYPEID_PLAYER)
        ((Player*)target)->InitDataForForm();
}

void Aura::HandleAuraTransform(bool apply, bool Real)
{
    Unit* target = GetTarget();
    if (apply)
    {
        float mod_x = 1;
        uint32 display_id = 0;

        // Discombobulate removes mount auras.
        if (GetId() == 4060 && Real)
            target->RemoveSpellsCausingAura(SPELL_AURA_MOUNTED);

        // update active transform spell only not set or not overwriting negative by positive case
        if (!target->GetTransForm() || !IsPositiveSpell(GetId()) || IsPositiveSpell(target->GetTransForm()))
        {
            if (GetId() == 23603)   // Ustaag <Nostalrius> : Nefarian Class Call Mage
            {
                int rand = 0;
                rand = urand(0, 2);
                switch (rand)
                {
                    case 0:
                        display_id = 1060;
                        break;
                    case 1:
                        display_id = 4473;
                        break;
                    case 2:
                        display_id = 7898;
                        break;
                }
            }
            else if (m_modifier.m_miscvalue == 0)         // special case (spell specific functionality)
            {
                switch (GetId())
                {
                    case 16739:                                 // Orb of Deception
                    {
                        uint8 gender = sObjectMgr.GetCreatureDisplayInfoAddon(target->GetDisplayId())->gender;
                        switch (target->GetRace())
                        {
                            case RACE_TROLL:
                                display_id = gender == GENDER_MALE ?
                                            10135 :
                                            10134 ;
                                break;
                            case RACE_TAUREN:
                                display_id = gender == GENDER_MALE ?
                                            10136 :
                                            10147 ;
                                break;
                            case RACE_HUMAN:
                                display_id = gender == GENDER_MALE ?
                                            10137 :
                                            10138 ;
                                break;
                            case RACE_ORC:
                                display_id = gender == GENDER_MALE ?
                                            10139 :
                                            10140 ;
                                break;
                            case RACE_DWARF:
                                display_id = gender == GENDER_MALE ?
                                            10141 :
                                            10142 ;
                                break;
                            case RACE_NIGHTELF:
                                display_id = gender == GENDER_MALE ?
                                            10143 :
                                            10144 ;
                                break;
                            case RACE_UNDEAD:
                                display_id = gender == GENDER_MALE ?
                                            10146 :
                                            10145 ;
                                break;
                            case RACE_GNOME:
                                if (gender == GENDER_MALE)
                                {
                                    display_id = 10148;
                                    mod_x = DEFAULT_TAUREN_MALE_SCALE;
                                }
                                else
                                {
                                    display_id = 10149;
                                    mod_x = DEFAULT_TAUREN_FEMALE_SCALE;
                                }
                                break;
                            default:
                                break;
                        }
                        break;
                    }
                    default:
                        sLog.outError("Aura::HandleAuraTransform, spell %u does not have creature entry defined, need custom defined display id.", GetId());
                        break;
                }
            }
            else
            {
                float displayScale = mod_x;
                CreatureInfo const* ci = ObjectMgr::GetCreatureTemplate(m_modifier.m_miscvalue);
                if (!ci)
                {
                    display_id = UNIT_DISPLAY_ID_BOX;
                    sLog.outError("Aura::HandleAuraTransform - Unknown creature id (%d) (only need its display_id) for spell %d.", m_modifier.m_miscvalue, GetId());
                }
                else
                    display_id = Creature::ChooseDisplayId(ci, nullptr, nullptr, nullptr, &displayScale);   // Will use the default display id here

                // creature case, need to update equipment
                if (ci && target->IsCreature())
                {
                    ((Creature*)target)->LoadEquipment(ci->equipment_id, true);
                    mod_x = displayScale;
                }
            }

            if (display_id)
            {
                target->SetDisplayId(display_id);
                target->SetTransformScale(mod_x);
            }
            target->SetTransForm(GetId());
        }
    }
    else
    {
        //reset cosmetics only if it's the current transform
        if (target->GetTransForm() == GetId())
        {
            target->SetTransForm(0);
            target->SetDisplayId(target->GetNativeDisplayId());
            target->ResetTransformScale();

            // apply default equipment for creature case
            if (target->GetTypeId() == TYPEID_UNIT)
                ((Creature*)target)->LoadEquipment(((Creature*)target)->GetCreatureInfo()->equipment_id, true);


            // re-apply some from still active with preference negative cases
            Unit::AuraList const& otherTransforms = target->GetAurasByType(SPELL_AURA_TRANSFORM);
            if (!otherTransforms.empty())
            {
                // look for other transform auras
                Aura* handledAura = *otherTransforms.rbegin();
                for (Unit::AuraList::const_reverse_iterator i = otherTransforms.rbegin(); i != otherTransforms.rend(); ++i)
                {
                    // negative auras are preferred
                    if (!(*i)->GetSpellProto()->IsPositiveSpell())
                    {
                        handledAura = *i;
                        break;
                    }
                }
                handledAura->HandleAuraTransform(true,false);
            }
            else //reapply shapeshifting, there should be only one.
            {
                std::pair<unsigned int, float> info = GetShapeshiftDisplayInfo(target->GetShapeshiftForm(), target);
                if (info.first)
                {
                    target->SetDisplayId(info.first);
                    target->SetTransformScale(info.second);
                }
            }
        }
    }
}

void Aura::HandleForceReaction(bool apply, bool Real)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    if (!Real)
        return;

    Player* player = (Player*)GetTarget();

    uint32 faction_id = m_modifier.m_miscvalue;
    ReputationRank faction_rank = ReputationRank(uint32(m_modifier.m_amount));

    player->GetReputationMgr().ApplyForceReaction(faction_id, faction_rank, apply);
    player->GetReputationMgr().SendForceReactions();

    // stop fighting if at apply forced rank friendly or at remove real rank friendly
    if ((apply && faction_rank >= REP_FRIENDLY) || (!apply && player->GetReputationRank(faction_id) >= REP_FRIENDLY))
        player->StopAttackFaction(faction_id);

    // sorry, need to hack ashbringer to make you friendly with scarlet crusade too
    if (m_spellAuraHolder && m_spellAuraHolder->GetSpellProto() &&  m_spellAuraHolder->GetId() == 28282)
    {
        uint32 scarlet_crusade_faction_id = 56;
        ReputationRank scarlet_crusade_rank = ReputationRank(7);
        player->GetReputationMgr().ApplyForceReaction(scarlet_crusade_faction_id, scarlet_crusade_rank, apply);
        player->GetReputationMgr().SendForceReactions();

        // stop fighting if at apply forced rank friendly or at remove real rank friendly
        if ((apply && scarlet_crusade_rank >= REP_FRIENDLY) || (!apply && player->GetReputationRank(scarlet_crusade_faction_id) >= REP_FRIENDLY))
            player->StopAttackFaction(scarlet_crusade_faction_id);
    }

    if (GetId() == 29519 && player->GetZoneId() == 1377)
    {
        if (apply)
            player->CastSpell(player, (player->GetTeam() == ALLIANCE ? 29894 : 29895), true);
        else
        {
            player->RemoveAurasDueToSpell((player->GetTeam() == ALLIANCE ? 29894 : 29895));
            // Outdoor PVP Silithus : Loss of Silithyst Buff.
            if (m_removeMode == AURA_REMOVE_BY_CANCEL || m_removeMode == AURA_REMOVE_BY_DEATH || m_removeMode == AURA_REMOVE_BY_DISPEL)
                if (ZoneScript* pScript = player->GetZoneScript())
                    pScript->HandleDropFlag(player, GetId());
        }
    }

}

void Aura::HandleAuraModSkill(bool apply, bool /*Real*/)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    uint16 const skillId = uint16(GetSpellProto()->EffectMiscValue[m_effIndex]);

    // Can't modify an unknown skill
    if (!GetTarget()->ToPlayer()->HasSkill(skillId))
    {
        // Revert m_applied assigned in Aura::ApplyModidier
        m_applied = !apply;
        return;
    }

    Player* target = static_cast<Player*>(GetTarget());
    Modifier const* mod = GetModifier();
    int16 const amount = int16(mod->m_amount);
    bool const permanent = (mod->m_auraname == SPELL_AURA_MOD_SKILL_TALENT);

    if (target->ModifySkillBonus(skillId, (apply ? amount : -amount), permanent))
    {
        if (skillId == SKILL_DEFENSE)
            target->UpdateDefenseBonusesMod();
    }
}
void Aura::HandleChannelDeathItem(bool apply, bool Real)
{
    if (Real && !apply)
    {
        if (m_removeMode != AURA_REMOVE_BY_DEATH)
            return;
        // Item amount
        if (m_modifier.m_amount <= 0)
            return;

        SpellEntry const* spellInfo = GetSpellProto();
        if (spellInfo->EffectItemType[m_effIndex] == 0)
            return;

        Unit* victim = GetTarget();
        Unit* caster = GetCaster();
        if (!caster || caster->GetTypeId() != TYPEID_PLAYER)
            return;
        // Demonistes : un seul fragment d'ame si on caste "Brulure de l'ombre" et "Siphon d'ame" sur une cible.
        if (spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK)
            if (victim->HasAuraTypeByCaster(SPELL_AURA_CHANNEL_DEATH_ITEM, caster->GetObjectGuid()))
                return;

        // Soul Shard (target req.)
        if (spellInfo->EffectItemType[m_effIndex] == 6265)
        {
            // Only from non-grey units
            if (!((Player*)caster)->IsHonorOrXPTarget(victim) ||
                    (victim->GetTypeId() == TYPEID_UNIT && !victim->ToCreature()->IsTappedBy(caster->ToPlayer())))
                return;
        }

        //Adding items
        uint32 noSpaceForCount = 0;
        uint32 count = m_modifier.m_amount;

        ItemPosCountVec dest;
        InventoryResult msg = ((Player*)caster)->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, spellInfo->EffectItemType[m_effIndex], count, &noSpaceForCount);
        if (msg != EQUIP_ERR_OK)
        {
            count -= noSpaceForCount;
            ((Player*)caster)->SendEquipError(msg, nullptr, nullptr, spellInfo->EffectItemType[m_effIndex]);
            if (count == 0)
                return;
        }

        Item* newitem = ((Player*)caster)->StoreNewItem(dest, spellInfo->EffectItemType[m_effIndex], true);
        ((Player*)caster)->SendNewItem(newitem, count, true, true);
    }
}

void Aura::HandleBindSight(bool apply, bool /*Real*/)
{
    Player* caster = ToPlayer(GetCaster());
    if (!caster)
        return;

    Camera& camera = caster->GetCamera();
    if (apply)
        camera.SetView(GetTarget());
    else
    {
        camera.ResetView();
        caster->SendCreateUpdateToPlayer(caster);
    }
}

void Aura::HandleFarSight(bool apply, bool /*Real*/)
{
    Unit* caster = GetCaster();
    if (!caster || caster->GetTypeId() != TYPEID_PLAYER)
        return;

    if (apply)
        caster->ToPlayer()->SetLongSight(this);
    else
        caster->ToPlayer()->SetLongSight();
}

void Aura::HandleAuraTrackCreatures(bool apply, bool /*Real*/)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    if (apply)
        GetTarget()->RemoveNoStackAurasDueToAuraHolder(GetHolder());

    if (apply)
        GetTarget()->SetFlag(PLAYER_TRACK_CREATURES, uint32(1) << (m_modifier.m_miscvalue - 1));
    else
        GetTarget()->RemoveFlag(PLAYER_TRACK_CREATURES, uint32(1) << (m_modifier.m_miscvalue - 1));
}

void Aura::HandleAuraTrackResources(bool apply, bool /*Real*/)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    if (apply)
        GetTarget()->RemoveNoStackAurasDueToAuraHolder(GetHolder());

    if (apply)
        GetTarget()->SetFlag(PLAYER_TRACK_RESOURCES, uint32(1) << (m_modifier.m_miscvalue - 1));
    else
        GetTarget()->RemoveFlag(PLAYER_TRACK_RESOURCES, uint32(1) << (m_modifier.m_miscvalue - 1));
}

void Aura::HandleAuraTrackStealthed(bool apply, bool /*Real*/)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    if (apply)
        GetTarget()->RemoveNoStackAurasDueToAuraHolder(GetHolder());

    GetTarget()->ApplyModByteFlag(PLAYER_FIELD_BYTES, 0, PLAYER_FIELD_BYTE_TRACK_STEALTHED, apply);
}

void Aura::HandleAuraModScale(bool apply, bool /*Real*/)
{
    GetTarget()->ApplyPercentModFloatValue(OBJECT_FIELD_SCALE_X, m_modifier.m_amount, apply);
    GetTarget()->UpdateModelData();
}

void Aura::HandleModPossess(bool apply, bool Real)
{
    if (!Real)
        return;

    Unit* pTarget = GetTarget();
    Unit* pCaster = GetCaster();
    if (!pCaster || !pTarget)
        return;

#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_9_4
    // Fix issue with control on old clients if player is afflicted by mind control,
    // while he himself is possessing another unit. Client needs to first be told
    // he no longer controls the other unit, have time to respond with set active mover,
    // and only then to be told he is mind controlled in order to have control disabled.
    if (pTarget->GetCharmGuid())
    {
        pTarget->CombatStop(true);
        AuraRemoveMode removeMode = m_removeMode;
        SpellSchoolMask schoolMask = GetSpellProto()->GetSpellSchoolMask();
        pTarget->m_Events.AddLambdaEventAtOffset([pTarget, pCaster, apply, removeMode, schoolMask]
        {
            pCaster->ModPossess(pTarget, apply, removeMode);
            pTarget->AddThreat(pCaster, pTarget->GetHealth(), false, schoolMask);
        }, 500);
    }
    else
#endif
    {
        pCaster->ModPossess(pTarget, apply, m_removeMode);
        if (apply && pCaster->IsPlayer())
        {
            Player* pPlayerCaster = static_cast<Player*>(pCaster);
            UpdateMask updateMask;
            updateMask.SetCount(pTarget->GetValuesCount());
            pTarget->MarkUpdateFieldsWithFlagForUpdate(updateMask, UF_FLAG_OWNER_ONLY);
            if (updateMask.HasData())
            {
                UpdateData newData;
                pTarget->BuildValuesUpdateBlockForPlayer(newData, updateMask, pPlayerCaster);

                if (newData.HasData())
                {
                    WorldPacket newDataPacket;
                    newData.BuildPacket(&newDataPacket);
                    pPlayerCaster->SendDirectMessage(&newDataPacket);
                }
            }
        }
        pTarget->AddThreat(pCaster, pTarget->GetHealth(), false, GetSpellProto()->GetSpellSchoolMask());
    }

    if (!apply && GetId() == 24937) // Controlling Steam Tonk
    {
        pTarget->CastSpell(pTarget, 27771, true); // Cast Damaged Tonk
        pCaster->CastSpell(pCaster, 9179, true); // Cast 3 sec Stun on self
        pCaster->RemoveAurasDueToSpell(24935); // Unroot player

        // Reset Tonk Control Console
        if (GameObject* pConsole = pCaster->FindNearestGameObject(180524, INTERACTION_DISTANCE))
        {
            pConsole->SetGoState(GO_STATE_READY);
            pConsole->SetLootState(GO_READY);
            pConsole->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_IN_USE);
        }
    }
}

void Unit::ModPossess(Unit* pTarget, bool apply, AuraRemoveMode m_removeMode)
{
    // Cannot possess yourself.
    if (pTarget == this)
        return;

    // Only a player can possess units, mobs can charm.
    Player* pCaster = ToPlayer();
    if (!pCaster)
        return;

    if (apply)
    {
        // Remove dummy auras from spells with EffectSummonPossessed.
        pTarget->RemoveAurasDueToSpell(126);
        pTarget->RemoveAurasDueToSpell(6272);
        pTarget->RemoveAurasDueToSpell(11403);

        FactionTemplateEntry const* origFactionTemplate = pTarget->getFactionTemplateEntry();

        pTarget->AddUnitState(UNIT_STAT_POSSESSED);
        pTarget->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_POSSESSED);
        pTarget->SetCharmerGuid(pCaster->GetObjectGuid());
        pTarget->SetPossessorGuid(pCaster->GetObjectGuid());
        pTarget->SetFactionTemplateId(pCaster->GetFactionTemplateId());

        // Target should became visible at SetView call (if not visible before),
        // otherwise client will ignore packets from the target (SetClientControl for example).
        pCaster->GetCamera().SetView(pTarget);

        pCaster->SetCharm(pTarget);
        pCaster->SetMover(pTarget);

        pTarget->CombatStop(true);

        if (CharmInfo *charmInfo = pTarget->InitCharmInfo(pTarget))
        {
            if (m_timeCla > int32(diff))
                m_timeCla -= diff;
            else if (caster && (caster == GetOwner() || !GetSpellInfo()->HasAttribute(SPELL_ATTR2_NO_TARGET_PER_SECOND_COSTS)))
            {
                if (!m_periodicCosts.empty())
                {
                    m_timeCla += 1000 - diff;
            charmInfo->InitPossessCreateSpells();
            charmInfo->SetReactState(REACT_PASSIVE);
            charmInfo->SetCommandState(COMMAND_STAY);
            charmInfo->SetOriginalFactionTemplate(origFactionTemplate);
        }

        pCaster->PossessSpellInitialize();

        if (Creature* pCreature = pTarget->ToCreature())
        {
            if (!pCreature->HasUnitState(UNIT_STAT_CAN_NOT_REACT))
                if (pCreature->AI()->SwitchAiAtControl())
                    pCreature->AIM_Initialize();
        }
        else if (Player* pPlayer = pTarget->ToPlayer())
        {
            if (ObjectGuid lootGuid = pPlayer->GetLootGuid())
                pPlayer->GetSession()->DoLootRelease(lootGuid);
        }

        // Mobs should attack the target being mind controlled.
        // So we call 'MoveInLineOfSight' for nearby mobs.
        pTarget->ScheduleAINotify(0);

        pTarget->UpdateControl();
        if (pTarget->HasUnitState(UNIT_STAT_STUNNED | UNIT_STAT_PENDING_STUNNED | UNIT_STAT_ROOT | UNIT_STAT_PENDING_ROOT))
            pTarget->SetRooted(true);
        pTarget->StopMoving();
        pTarget->SetWalk(pCaster->IsWalking());
    }
    else
    {
        // Clear threat generated when MC ends.
        pTarget->RemoveAttackersThreat(pCaster);

        pCaster->SetMover(nullptr);
        pCaster->SetCharm(nullptr);
        pCaster->UpdateControl();
        pCaster->SetClientControl(pTarget, false);

        // There is a possibility that target became invisible for client at ResetView call.
        // It must be called after movement control unapplying, not before! The reason is same as at aura applying.
        pCaster->GetCamera().ResetView();
        pCaster->RemovePetActionBar();

        // On delete only do caster related effects.
        if (m_removeMode == AURA_REMOVE_BY_DELETE)
            return;

        pTarget->ClearUnitState(UNIT_STAT_POSSESSED);
        pTarget->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_POSSESSED);
        pTarget->SetCharmerGuid(ObjectGuid());
        pTarget->SetPossessorGuid(ObjectGuid());

        if (Player* pPlayerTarget = pTarget->ToPlayer())
        {
            pPlayerTarget->RemoveTemporaryAI();
            pPlayerTarget->RelocateToLastClientPosition(); // Movement extrapolation - prevent undermap.
        }

        pTarget->RestoreFaction();
        pTarget->CombatStop(true);
        pTarget->UpdateControl();
        pTarget->SetWalk(false);

        if (Creature* pCreature = pTarget->ToCreature())
        {
            if (!pCreature->HasUnitState(UNIT_STAT_CAN_NOT_REACT))
            {
                pTarget->StopMoving(true);
                if (pCreature->AI() && pCreature->AI()->SwitchAiAtControl())
                    pCreature->AIM_Initialize();

                pCreature->AttackedBy(pCaster);
            }
        }
        else
            pTarget->StopMoving(true);

        // cast mind exhaustion on self when the posess possess ends if the creature
        // is death knight understudy (razuvious).
        // todo: if there is a way to know a possess has ended through scriptAI, fix this.
        if (pTarget->GetEntry() == 16803)
        {
            pTarget->CastSpell(pTarget, 29051, true);
        }

        if (pTarget->IsPlayer() && pTarget->IsRooted())
            MovementPacketSender::AddMovementFlagChangeToController(pTarget, MOVEFLAG_ROOT, true);
    }

#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_8_4
    pTarget->SendCreateUpdateToPlayer(pCaster);
#endif
}

void Aura::HandleModPossessPet(bool apply, bool Real)
{
    if (!Real)
        return;

    Player* pCaster = ToPlayer(GetCaster());
    if (!pCaster)
        return;

    Unit* pTarget = GetTarget();
    if (!pTarget->IsPet())
        return;

    Pet* pPet = (Pet*)pTarget;
    pCaster->ModPossessPet(pPet, apply, m_removeMode);
}

void Player::ModPossessPet(Pet* pPet, bool apply, AuraRemoveMode m_removeMode)
{
    Player* pCaster = this;
    Camera& camera = pCaster->GetCamera();

    if (apply)
    {
        pPet->AddUnitState(UNIT_STAT_POSSESSED);

        // Target should became visible at SetView call(if not visible before),
        // otherwise client will ignore packets from the target(SetClientControl for example).
        camera.SetView(pPet);

        pCaster->SetCharm(pPet);
        pCaster->SetMover(pPet);

        pPet->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_POSSESSED);
        pPet->SetCharmerGuid(pCaster->GetObjectGuid());
        pPet->SetPossessorGuid(pCaster->GetObjectGuid());

        pPet->StopMoving();
        pPet->GetMotionMaster()->Clear(false);
        pPet->GetMotionMaster()->MoveIdle();
        pPet->UpdateControl();
        pPet->SetWalk(pCaster->IsWalking());

        if (CharmInfo* charmInfo = pPet->GetCharmInfo())
        {
            charmInfo->SetIsAtStay(false);
            charmInfo->SetIsReturning(false);
            charmInfo->SetIsFollowing(false);
        }

        if (pPet->IsRooted())
            MovementPacketSender::AddMovementFlagChangeToController(pPet, MOVEFLAG_ROOT, true);
    }
    else
    {
        pCaster->SetCharm(nullptr);
        pCaster->SetMover(nullptr);

        // There is a possibility that target became invisible for client at ResetView call.
        // It must be called after movement control unapplying, not before! the reason is same as at aura applying.
        camera.ResetView();
        pPet->UpdateControl();
        pPet->SetCharmerGuid(ObjectGuid());
        pPet->SetPossessorGuid(ObjectGuid());

        if (!pPet->HasUnitState(UNIT_STAT_CAN_NOT_REACT))
            pPet->StopMoving(true);

        // To avoid moving the wrong unit on server side between cancellation and mover swap
        // the pet has the controlled state removed in WorldSession::HandleSetActiveMoverOpcode
    }

#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_8_4
    pPet->SendCreateUpdateToPlayer(pCaster);
#endif
}

void Aura::HandleModCharm(bool apply, bool Real)
{
    if (!Real)
        return;

    Unit* target = GetTarget();

    if (!target)
        return;

    // not charm yourself
    if (GetCasterGuid() == target->GetObjectGuid())
        return;

    Unit* caster = GetCaster();

    if (apply)
    {
        if (!caster)
            return;

        FactionTemplateEntry const* origFactionTemplate = target->getFactionTemplateEntry();

        // Remove dummy auras from spells with EffectSummonPossessed
        target->RemoveAurasDueToSpell(126);
        target->RemoveAurasDueToSpell(6272);
        target->RemoveAurasDueToSpell(11403);

        // is it really need after spell check checks?
        target->RemoveSpellsCausingAura(SPELL_AURA_MOD_CHARM, GetHolder());
        target->RemoveSpellsCausingAura(SPELL_AURA_MOD_POSSESS, GetHolder());
        target->RemoveSpellsCausingAura(SPELL_AURA_AOE_CHARM, GetHolder()); // this is a bit dodgy, like most removals of SPELL_AURA_AOE_CHARM

        target->SetCharmerGuid(GetCasterGuid());
        target->SetFactionTemplateId(caster->GetFactionTemplateId());
        target->CastStop(target == caster ? GetId() : 0);
        caster->SetCharm(target);

        target->CombatStop(true);
        target->DeleteThreatList();
        target->GetHostileRefManager().deleteReferences();

        CharmInfo *charmInfo = target->InitCharmInfo(target);
        charmInfo->InitCharmCreateSpells();
        charmInfo->SetReactState(REACT_DEFENSIVE);
        // Default movement is follow
        charmInfo->SetCommandState(COMMAND_FOLLOW);

        charmInfo->SetIsCommandAttack(false);
        charmInfo->SetIsAtStay(false);
        charmInfo->SetIsReturning(true);
        charmInfo->SetIsCommandFollow(true);
        charmInfo->SetIsFollowing(false);
        charmInfo->SetOriginalFactionTemplate(origFactionTemplate);

        target->AttackStop();
        target->InterruptNonMeleeSpells(false);

        if (caster->IsPlayer()) // Units will make the controlled player attack (MoveChase)
            target->GetMotionMaster()->MoveFollow(caster, PET_FOLLOW_DIST, PET_FOLLOW_ANGLE);

        if (Creature* pCreatureTarget = target->ToCreature())
        {
            if (pCreatureTarget->AI() && pCreatureTarget->AI()->SwitchAiAtControl())
                pCreatureTarget->AIM_Initialize();

            if (caster->IsPlayer() && caster->GetClass() == CLASS_WARLOCK)
            {
                CreatureInfo const* cinfo = pCreatureTarget->GetCreatureInfo();
                if (cinfo && cinfo->type == CREATURE_TYPE_DEMON)
                {
                    // creature with pet number expected have class set
                    if (target->GetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS) == 0)
                    {
                        if (cinfo->unit_class == 0)
                            sLog.outErrorDb("Creature (Entry: %u) have unit_class = 0 but used in charmed spell, that will be result client crash.", cinfo->entry);
                        else
                            sLog.outError("Creature (Entry: %u) have unit_class = %u but at charming have class 0!!! that will be result client crash.", cinfo->entry, cinfo->unit_class);

                        target->SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS, CLASS_MAGE);
                    }

                    //just to enable stat window
                    charmInfo->SetPetNumber(sObjectMgr.GeneratePetNumber(), true);
                    //if charmed two demons the same session, the 2nd gets the 1st one's name
                    target->SetUInt32Value(UNIT_FIELD_PET_NAME_TIMESTAMP, uint32(time(nullptr)));
                }
            }
        }
        else if (Player* pPlayer = target->ToPlayer())
        {
            if (ObjectGuid lootGuid = pPlayer->GetLootGuid())
                pPlayer->GetSession()->DoLootRelease(lootGuid);

            pPlayer->SetControlledBy(caster);
            if (pPlayer->i_AI && m_spellAuraHolder->GetId() == 28410)
                pPlayer->i_AI->enablePositiveSpells = true;
        }
        target->UpdateControl();

        if (Player* pPlayerCaster = caster->ToPlayer())
        {
            pPlayerCaster->CharmSpellInitialize();
            
            UpdateMask updateMask;
            updateMask.SetCount(target->GetValuesCount());
            target->MarkUpdateFieldsWithFlagForUpdate(updateMask, UF_FLAG_OWNER_ONLY);
            if (updateMask.HasData())
            {
                UpdateData newData;
                target->BuildValuesUpdateBlockForPlayer(newData, updateMask, pPlayerCaster);

                if (newData.HasData())
                {
                    WorldPacket newDataPacket;
                    newData.BuildPacket(&newDataPacket);
                    pPlayerCaster->SendDirectMessage(&newDataPacket);
                }
            }
        }
    }
    else
    {
        Creature* pCreatureTarget = target->ToCreature();
        Player* pPlayerTarget = target->ToPlayer();

        target->SetCharmerGuid(ObjectGuid());

        if (pCreatureTarget)
        {
            CreatureInfo const* cinfo = pCreatureTarget->GetCreatureInfo();

            // restore faction
            if (target->IsPet())
            {
                if (Unit* owner = target->GetOwner())
                    target->SetFactionTemplateId(owner->GetFactionTemplateId());
                else if (cinfo)
                    target->SetFactionTemplateId(cinfo->faction);
            }
            else if (cinfo)                             // normal creature
                target->SetFactionTemplateId(cinfo->faction);

int32 Aura::CalcMaxDuration(Unit* caster) const
{
    return Aura::CalcMaxDuration(GetSpellInfo(), caster);
}

/*static*/ int32 Aura::CalcMaxDuration(SpellInfo const* spellInfo, WorldObject* caster)
{
    Player* modOwner = nullptr;
    int32 maxDuration;
            // restore UNIT_FIELD_BYTES_0
            if (cinfo && caster && caster->IsPlayer() && caster->GetClass() == CLASS_WARLOCK && cinfo->type == CREATURE_TYPE_DEMON)
            {
                // DB must have proper class set in field at loading, not req. restore, including workaround case at apply
                // target->SetByteValue(UNIT_FIELD_BYTES_0, UNIT_BYTES_0_OFFSET_CLASS, cinfo->unit_class);

                if (target->GetCharmInfo())
                    target->GetCharmInfo()->SetPetNumber(0, true);
                else
                    sLog.outError("Aura::HandleModCharm: target (GUID: %u TypeId: %u) has a charm aura but no charm info!", target->GetGUIDLow(), target->GetTypeId());
            }
        }

    if (caster)
    {
        modOwner = caster->GetSpellModOwner();
        maxDuration = caster->CalcSpellDuration(spellInfo);
    }
    else
        maxDuration = spellInfo->GetDuration();
        if (caster)
        {
            caster->SetCharm(nullptr);
            if (caster->IsPlayer())
                static_cast<Player*>(caster)->RemovePetActionBar();
        }

        target->UpdateControl();

        if (pPlayerTarget)
            pPlayerTarget->SetFactionForRace(target->GetRace());

        if (pPlayerTarget && pPlayerTarget->IsAlive() && caster && caster->IsAlive() && caster->IsInCombat())
        {
            pPlayerTarget->SendAttackSwingCancelAttack();

            if (target->IsNonMeleeSpellCasted(false))
                target->InterruptNonMeleeSpells(false);

            target->AttackStop();
            target->RemoveAllAttackers();
            target->DeleteThreatList();
            target->GetHostileRefManager().deleteReferences();

            caster->SetInCombatWith(target);
            target->SetInCombatWith(caster);

            target->SetInCombatState(false, caster);
        }
        else
        {
            target->CombatStop(true);
            target->DeleteThreatList();
            target->GetHostileRefManager().deleteReferences();
        }

        //target->SetUnitMovementFlags(MOVEFLAG_NONE);
        target->StopMoving();
        target->GetMotionMaster()->Clear(false);
        target->GetMotionMaster()->MoveIdle();

        if (pCreatureTarget)
        {
            if (pCreatureTarget->AI() && pCreatureTarget->AI()->SwitchAiAtControl())
                pCreatureTarget->AIM_Initialize();

            if (caster)
                pCreatureTarget->AttackedBy(caster);
        }
        else if (pPlayerTarget)
        {
            pPlayerTarget->RemoveTemporaryAI();

            // Charmed players are seen as hostile and not in the group for other clients, restore
            // group upon charm end
            if (pPlayerTarget->GetGroup())
                pPlayerTarget->GetGroup()->BroadcastGroupUpdate();
        }
    }
}

void Aura::HandleModConfuse(bool apply, bool Real)
{
    if (!Real)
        return;

    if (spellInfo->IsPassive() && !spellInfo->DurationEntry)
        maxDuration = -1;
    GetTarget()->SetConfused(apply, GetCasterGuid(), GetId());
}

    // IsPermanent() checks max duration (which we are supposed to calculate here)
    if (maxDuration != -1 && modOwner)
        modOwner->ApplySpellMod(spellInfo, SpellModOp::Duration, maxDuration);
void Aura::HandleModFear(bool apply, bool Real)
{
    if (!Real)
        return;

    GetTarget()->SetFeared(apply, GetCasterGuid(), GetId());
}

void Aura::HandleFeignDeath(bool apply, bool Real)
{
    if (!Real)
        return;

    bool success = true;
    Unit* pTarget = GetTarget();

    if (apply)
    {
        HostileReference* pReference = pTarget->GetHostileRefManager().getFirst();
        while (pReference)
        {
            if (Creature* refTarget = ToCreature(pReference->getSourceUnit()))
            {
                if (!refTarget->GetCharmerOrOwnerOrSelf()->IsPlayer() && refTarget->IsWithinDistInMap(pTarget, refTarget->GetAttackDistance(pTarget))
                    && pTarget->MagicSpellHitResult(refTarget, GetHolder()->GetSpellProto(), nullptr) != SPELL_MISS_NONE)
                {
                    success = false;
                    break;
                }
            }
            pReference = pReference->next();
        }
    }

    pTarget->SetFeignDeath(apply, GetCasterGuid(), success);
}

void Aura::RefreshDuration(bool withMods)
{
    Unit* caster = GetCaster();
    if (withMods && caster)
    {
        int32 duration = m_spellInfo->GetMaxDuration();
        // Calculate duration of periodics affected by haste.
        if (m_spellInfo->HasAttribute(SPELL_ATTR8_HASTE_AFFECTS_DURATION))
            duration = int32(duration * caster->m_unitData->ModCastingSpeed);
void Aura::HandleAuraModDisarm(bool apply, bool Real)
{
    if (!Real)
        return;

    Unit* target = GetTarget();

    if (!apply && target->HasAuraType(SPELL_AURA_MOD_DISARM))
        return;

    // Main-hand speed and attack damage is already set for feral form (and they cannot be disarmed anyway)
    // If the form is switched the disarm speed/damage will be applied automatically
    // Only update swing timers for players on disarm
    // https://www.youtube.com/watch?v=8TDUpudEL-M&t=6m5s
    // Furthermore, we need to apply/unapply weapon mods for players on disarm
    // so they don't have weapon stats (or talent boosts) whilst disarmed
    if (target->GetTypeId() == TYPEID_PLAYER && !target->IsInFeralForm())
    {
        Player* pTarget = target->ToPlayer();

        // (un)applying weapon dependent mods is more practical on a non disarmed player
        // if we unapply the aura remove the flag before _ApplyWeaponDependentAuraMods
        if (!apply)
        {
            target->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISARMED, false);
            pTarget->SetRegularAttackTime();
        }

        if (Item* weapon = pTarget->GetWeaponForAttack(BASE_ATTACK, true, true))
            pTarget->_ApplyWeaponDependentAuraMods(weapon, BASE_ATTACK, !apply);

        // if we apply the aura add the flag after _ApplyWeaponDependentAuraMods
        if (apply)
        {
            target->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISARMED, true);
            target->SetAttackTime(BASE_ATTACK, BASE_ATTACK_TIME);
        }
    }
    else
        target->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISARMED, apply);

    // Warrior 'Disarm' skill generates 104 base threat
    // http://wowwiki.wikia.com/wiki/Disarm?direction=prev&oldid=200198 (2006) implies it
    // generates a large amount
    // http://wowwiki.wikia.com/wiki/Threat has threat listed at 104, which is in line
    // with the values of other warrior abilities
    // We can suppose that the same is true for all spells which apply disarm
    if (apply)
    {
        float threat = 104.0f * sSpellMgr.GetSpellThreatMultiplier(GetHolder()->GetSpellProto());
        target->AddThreat(GetCaster(), threat, false, SPELL_SCHOOL_MASK_NONE, GetHolder()->GetSpellProto());
    }

    // Don't update damage if in feral
    if (!target->IsInFeralForm())
        target->UpdateDamagePhysical(BASE_ATTACK);
}

void Aura::HandleAuraModStun(bool apply, bool Real)
{
    if (!Real)
        return;

    Unit* target = GetTarget();

    if (apply)
    {
        if (target->IsTaxiFlying())
            return;
        // Stun/roots effects apply at charge end
        bool inCharge = target->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHARGE_MOTION_TYPE;
        // Frost stun aura -> freeze/unfreeze target
        if (GetSpellProto()->GetSpellSchoolMask() & SPELL_SCHOOL_MASK_FROST)
            target->ModifyAuraState(AURA_STATE_FROZEN, apply);

        target->AddUnitState(inCharge ? UNIT_STAT_PENDING_STUNNED : UNIT_STAT_STUNNED);
        target->SetTargetGuid(ObjectGuid());
        target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
        target->InterruptSpellsWithInterruptFlags(SPELL_INTERRUPT_FLAG_STUN, target->GetObjectGuid() == GetCasterGuid() ? GetId() : 0);

        // Player specific
        if (Player* targetPlayer = target->ToPlayer())
        {
            if (!targetPlayer->IsMounted())
                targetPlayer->SetStandState(UNIT_STAND_STATE_STAND);// in 1.5 client

            // Release loot if any
            if (ObjectGuid lootGuid = targetPlayer->GetLootGuid())
                targetPlayer->GetSession()->DoLootRelease(lootGuid);
        }

        if (!target->movespline->Finalized() || target->GetTypeId() == TYPEID_UNIT)
            if (!inCharge)
                target->StopMoving();

        target->SetRooted(true);
    }
    else
    {
        // Frost stun aura -> freeze/unfreeze target
        if (GetSpellProto()->GetSpellSchoolMask() & SPELL_SCHOOL_MASK_FROST)
        {
            bool found_another = false;
            for (AuraType const* itr = &frozenAuraTypes[0]; *itr != SPELL_AURA_NONE; ++itr)
            {
                Unit::AuraList const& auras = target->GetAurasByType(*itr);
                for (const auto aura : auras)
                {
                    if (aura->GetSpellProto()->GetSpellSchoolMask() & SPELL_SCHOOL_MASK_FROST)
                    {
                        found_another = true;
                        break;
                    }
                }
                if (found_another)
                    break;
            }

            if (!found_another)
                target->ModifyAuraState(AURA_STATE_FROZEN, apply);
        }

        // Real remove called after current aura remove from lists, check if other similar auras active
        if (target->HasAuraType(SPELL_AURA_MOD_STUN))
            return;

        target->ClearUnitState(UNIT_STAT_STUNNED | UNIT_STAT_PENDING_STUNNED);
        target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);


        if (target->GetVictim() && target->IsAlive())
            target->SetTargetGuid(target->GetVictim()->GetObjectGuid());

        if (!target->HasUnitState(UNIT_STAT_ROOT | UNIT_STAT_PENDING_ROOT))         // prevent allow move if have also root effect
            target->SetRooted(false);

        // Wyvern Sting
        if (GetSpellProto()->IsFitToFamily<SPELLFAMILY_HUNTER, CF_HUNTER_MISC>())
        {
            Unit* caster = GetCaster();
            if (!caster || caster->GetTypeId() != TYPEID_PLAYER)
                return;

            uint32 spell_id = 0;

            switch (GetId())
            {
                case 19386:
                    spell_id = 24131;
                    break;
                case 24132:
                    spell_id = 24134;
                    break;
                case 24133:
                    spell_id = 24135;
                    break;
                default:
                    sLog.outError("Spell selection called for unexpected original spell %u, new spell for this spell family?", GetId());
                    return;
            }

            SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(spell_id);

            if (!spellInfo)
                return;

            caster->CastSpell(target, spellInfo, true, nullptr, this);
            return;
        }
    }
}

void Aura::HandleModStealth(bool apply, bool Real)
{
    Unit* target = GetTarget();

    if (apply)
    {
        if (target->GetTypeId() == TYPEID_PLAYER)
        {
            if (SpellAuraHolder* holder = ((Player*)target)->GetSpellAuraHolder(29519))
            {
                if (target->GetZoneId() == 1377)
                {
                    // OutdoorPVP Silithus : Perte du buff silithyste
                    if (ZoneScript* pScript = ((Player*)target)->GetZoneScript())
                        pScript->HandleDropFlag((Player*)target, 29519);
                }
            }
        }

        // drop flag at stealth in bg
        target->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_IMMUNE_OR_LOST_SELECTION);

        // only at real aura add
        if (Real)
        {
            target->SetByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, UNIT_VIS_FLAGS_CREEP);
            if (target->GetTypeId() == TYPEID_PLAYER)
                target->SetByteFlag(PLAYER_FIELD_BYTES2, 1, PLAYER_FIELD_BYTE2_STEALTH);
            // apply only if not in GM invisibility (and overwrite invisibility state)
            if (target->GetVisibility() != VISIBILITY_OFF)
            {
                target->SetVisibility(VISIBILITY_GROUP_NO_DETECT);
                target->SetVisibility(VISIBILITY_GROUP_STEALTH);
            }

            // for RACE_NIGHTELF stealth
            if (target->GetTypeId() == TYPEID_PLAYER && GetId() == 20580)
                target->CastSpell(target, 21009, true, nullptr, this);

            target->InterruptSpellsCastedOnMe();
        }
    }
    else
    {
        // for RACE_NIGHTELF stealth
        if (Real && target->GetTypeId() == TYPEID_PLAYER && GetId() == 20580)
            target->RemoveAurasDueToSpell(21009);

        if (Real && (m_removeMode == AURA_REMOVE_BY_CANCEL) &&
            GetSpellProto()->IsFitToFamilyMask<CF_ROGUE_STEALTH>())
        {
            // https://us.forums.blizzard.com/en/wow/t/wow-classic-not-a-bug-list/175887/45?blzcmp=app
            // "Manually cancelling Stealth after using Vanish will
            //  remove the Vanish buff as well as the Stealth buff."
            target->RemoveAurasDueToSpellByCancel(11327);
            target->RemoveAurasDueToSpellByCancel(11329);
        }

        // only at real aura remove of _last_ SPELL_AURA_MOD_STEALTH
        if (Real && !target->HasAuraType(SPELL_AURA_MOD_STEALTH))
        {
            // if no GM invisibility
            if (target->GetVisibility() != VISIBILITY_OFF)
            {
                target->RemoveByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, UNIT_VIS_FLAGS_CREEP);
                if (target->GetTypeId() == TYPEID_PLAYER)
                    target->RemoveByteFlag(PLAYER_FIELD_BYTES2, 1, PLAYER_FIELD_BYTE2_STEALTH);
                // restore invisibility if any
                if (target->HasAuraType(SPELL_AURA_MOD_INVISIBILITY))
                {
                    target->SetVisibility(VISIBILITY_GROUP_NO_DETECT);
                    target->SetVisibility(VISIBILITY_GROUP_INVISIBILITY);
                }
                else
                    target->SetVisibility(VISIBILITY_ON);
            }
        }
    }
}

void Aura::HandleInvisibility(bool apply, bool Real)
{
    Unit* target = GetTarget();

    if (apply)
    {
        target->m_invisibilityMask |= (1 << m_modifier.m_miscvalue);
        target->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_IMMUNE_OR_LOST_SELECTION);

        if (Real && target->GetTypeId() == TYPEID_PLAYER)
        {
            // apply glow vision
            target->SetByteFlag(PLAYER_FIELD_BYTES2, 1, PLAYER_FIELD_BYTE2_INVISIBILITY_GLOW);
        }

        // apply only if not in GM invisibility and not stealth
        if (target->GetVisibility() == VISIBILITY_ON)
        {
            // Aura not added yet but visibility code expect temporary add aura
            target->SetVisibility(VISIBILITY_GROUP_NO_DETECT);
            target->SetVisibility(VISIBILITY_GROUP_INVISIBILITY);
        }
    }
    else
    {
        // recalculate value at modifier remove (current aura already removed)
        target->m_invisibilityMask = 0;
        Unit::AuraList const& auras = target->GetAurasByType(SPELL_AURA_MOD_INVISIBILITY);
        for (const auto aura : auras)
            target->m_invisibilityMask |= (1 << aura->GetModifier()->m_miscvalue);

        // only at real aura remove and if not have different invisibility auras.
        if (Real && target->m_invisibilityMask == 0)
        {
            // remove glow vision
            if (target->GetTypeId() == TYPEID_PLAYER)
                target->RemoveByteFlag(PLAYER_FIELD_BYTES2, 1, PLAYER_FIELD_BYTE2_INVISIBILITY_GLOW);
            // apply only if not in GM invisibility & not stealthed while invisible
            if (target->GetVisibility() != VISIBILITY_OFF)
            {
                // if have stealth aura then already have stealth visibility
                if (!target->HasAuraType(SPELL_AURA_MOD_STEALTH))
                    target->SetVisibility(VISIBILITY_ON);
            }
        }
    }
}

void Aura::HandleInvisibilityDetect(bool apply, bool Real)
{
    Unit* target = GetTarget();

    if (apply)
        target->m_detectInvisibilityMask |= (1 << m_modifier.m_miscvalue);
    else
    {
        // recalculate value at modifier remove (current aura already removed)
        target->m_detectInvisibilityMask = 0;
        Unit::AuraList const& auras = target->GetAurasByType(SPELL_AURA_MOD_INVISIBILITY_DETECTION);
        for (const auto aura : auras)
            target->m_detectInvisibilityMask |= (1 << aura->GetModifier()->m_miscvalue);
    }
    if (Real && target->GetTypeId() == TYPEID_PLAYER)
        ((Player*)target)->GetCamera().UpdateVisibilityForOwner();
}

void Aura::HandleAuraModRoot(bool apply, bool Real)
{
    // only at real add/remove aura
    if (!Real)
        return;

    Unit* target = GetTarget();

    if (apply)
    {
        // Stun/roots effects apply at charge end
        bool inCharge = target->GetMotionMaster()->GetCurrentMovementGeneratorType() == CHARGE_MOTION_TYPE;
        // Frost root aura -> freeze/unfreeze target
        if (GetSpellProto()->GetSpellSchoolMask() & SPELL_SCHOOL_MASK_FROST)
            target->ModifyAuraState(AURA_STATE_FROZEN, apply);

        target->AddUnitState(inCharge ? UNIT_STAT_PENDING_ROOT : UNIT_STAT_ROOT);

        //Save last orientation
        if (target->GetVictim())
            target->SetOrientation(target->GetAngle(target->GetVictim()));

        if (!target->movespline->Finalized() && !inCharge)
            target->StopMoving();

        target->SetRooted(true);
    }
    else
    {
        // Frost root aura -> freeze/unfreeze target
        if (GetSpellProto()->GetSpellSchoolMask() & SPELL_SCHOOL_MASK_FROST)
        {
            bool found_another = false;
            for (AuraType const* itr = &frozenAuraTypes[0]; *itr != SPELL_AURA_NONE; ++itr)
            {
                Unit::AuraList const& auras = target->GetAurasByType(*itr);
                for (const auto aura : auras)
                {
                    if (aura->GetSpellProto()->GetSpellSchoolMask() & SPELL_SCHOOL_MASK_FROST)
                    {
                        found_another = true;
                        break;
                    }
                }
                if (found_another)
                    break;
            }

            if (!found_another)
                target->ModifyAuraState(AURA_STATE_FROZEN, apply);
        }

        // Real remove called after current aura remove from lists, check if other similar auras active
        if (target->HasAuraType(SPELL_AURA_MOD_ROOT))
            return;

        target->ClearUnitState(UNIT_STAT_ROOT | UNIT_STAT_PENDING_ROOT);

        if (!target->HasUnitState(UNIT_STAT_STUNNED | UNIT_STAT_PENDING_STUNNED))      // prevent allow move if have also stun effect
        {
            target->SetRooted(false);
            //target->SetUnitMovementFlags(MOVEFLAG_NONE);
        }
    }
}

void Aura::HandleAuraModSilence(bool apply, bool Real)
{
    // only at real add/remove aura
    if (!Real)
        return;

    Unit* target = GetTarget();

    if (apply)
    {
        target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED);
        // Stop cast only spells vs PreventionType == SPELL_PREVENTION_TYPE_SILENCE
        for (uint32 i = CURRENT_MELEE_SPELL; i < CURRENT_MAX_SPELL; ++i)
            if (Spell* spell = target->GetCurrentSpell(CurrentSpellTypes(i)))
                if (spell->m_spellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE)
                    // Stop spells on prepare or casting state
                    target->InterruptSpell(CurrentSpellTypes(i), false);
    }
    else
    {
        // Real remove called after current aura remove from lists, check if other similar auras active
        if (target->HasAuraType(SPELL_AURA_MOD_SILENCE))
            return;

        target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SILENCED);
    }
}

void Aura::HandleModThreat(bool apply, bool Real)
{
    // only at real add/remove aura
    if (!Real)
        return;

    m_dropEvent = new ChargeDropEvent(this, removeMode);
    owner->m_Events.AddEvent(m_dropEvent, owner->m_Events.CalculateTime(Milliseconds(delay)));
    Unit* target = GetTarget();

    int level_diff = 0;
    int multiplier = 0;
    switch (GetId())
    {
        // Arcane Shroud
        case 26400:
            level_diff = target->GetLevel() - 60;
            multiplier = 2;
            break;
        // The Eye of Diminution
        case 28862:
            level_diff = target->GetLevel() - 60;
            multiplier = 1;
            break;
    }

    if (level_diff > 0)
        m_modifier.m_amount += multiplier * level_diff;

    if (target->GetTypeId() == TYPEID_PLAYER)
        for (int8 x = 0; x < MAX_SPELL_SCHOOL; x++)
            if (m_modifier.m_miscvalue & int32(1 << x))
                ApplyPercentModFloatVar(target->m_threatModifier[x], m_modifier.m_amount, apply);
}

void Aura::HandleAuraModTotalThreat(bool apply, bool Real)
{
    // only at real add/remove aura
    if (!Real)
        return;

    Unit* target = GetTarget();

    if (!target->IsAlive() || target->GetTypeId() != TYPEID_PLAYER)
        return;

    Unit* caster = GetCaster();

    std::vector<AuraApplication*> applications;
    GetApplicationVector(applications);
    if (!caster || !caster->IsAlive())
        return;

    target->GetHostileRefManager().addTempThreat(m_modifier.m_amount, apply);
}

void Aura::HandleModTaunt(bool apply, bool Real)
{
    // only at real add/remove aura
    if (!Real)
        return;

    Unit* target = GetTarget();

    if (!target->IsAlive() || !target->CanHaveThreatList())
        return;

    for (AuraApplication* aurApp : applications)
        if (!aurApp->GetRemoveMode())
            HandleAuraSpecificMods(aurApp, caster, false, true);
    Unit* caster = GetCaster();

    for (AuraEffect* aurEff : GetAuraEffects())
        if (aurEff)
            aurEff->ChangeAmount(aurEff->CalculateAmount(caster), false, true);
    if (!caster || !caster->IsAlive())
        return;

    for (AuraApplication* aurApp : applications)
        if (!aurApp->GetRemoveMode())
            HandleAuraSpecificMods(aurApp, caster, true, true);
    if (apply)
        target->TauntApply(caster);
    else
    {
        // When taunt aura fades out, mob will switch to previous target if current has less than 1.1 * secondthreat
        target->TauntFadeOut(caster);
    }
}

/*********************************************************/
/***                  MODIFY SPEED                     ***/
/*********************************************************/
void Aura::HandleAuraModIncreaseSpeed(bool apply, bool Real)
{
    // all applied/removed only at real aura add/remove
    if (!Real)
        return;

    if (Unit* caster = GetCaster())
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetSpellProto()->Id, SPELLMOD_SPEED, m_modifier.m_amount);

    GetTarget()->UpdateSpeed(MOVE_RUN, false);
}

void Aura::HandleAuraModIncreaseMountedSpeed(bool /*apply*/, bool Real)
{
    // all applied/removed only at real aura add/remove
    if (!Real)
        return;

    GetTarget()->UpdateSpeed(MOVE_RUN, false);
}

void Aura::HandleAuraModIncreaseSwimSpeed(bool /*apply*/, bool Real)
{
    // all applied/removed only at real aura add/remove
    if (!Real)
        return;

    GetTarget()->UpdateSpeed(MOVE_SWIM, false);
}

void Aura::HandleAuraModDecreaseSpeed(bool apply, bool Real)
{
    // all applied/removed only at real aura add/remove
    if (!Real)
        return;

    if (Unit* caster = GetCaster())
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetSpellProto()->Id, SPELLMOD_SPEED, m_modifier.m_amount);

    Unit* target = GetTarget();

    target->UpdateSpeed(MOVE_RUN, false);
    target->UpdateSpeed(MOVE_SWIM, false);
}

void Aura::HandleAuraModUseNormalSpeed(bool /*apply*/, bool Real)
{
    // all applied/removed only at real aura add/remove
    if (!Real)
        return;

    Unit* target = GetTarget();

    target->UpdateSpeed(MOVE_RUN, false);
    target->UpdateSpeed(MOVE_SWIM, false);
}

/*********************************************************/
/***                     IMMUNITY                      ***/
/*********************************************************/

void Aura::HandleModMechanicImmunity(bool apply, bool /*Real*/)
{
    uint32 misc  = m_modifier.m_miscvalue;
    Unit* target = GetTarget();

    if (apply && GetSpellProto()->AttributesEx & SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY)
        target->RemoveAurasAtMechanicImmunity(1 << (misc - 1), GetId());

    target->ApplySpellImmune(GetId(), IMMUNITY_MECHANIC, misc, apply);
}

void Aura::HandleModMechanicImmunityMask(bool apply, bool /*Real*/)
{
    uint32 mechanic  = m_modifier.m_miscvalue;

    if (apply && GetSpellProto()->AttributesEx & SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY)
        GetTarget()->RemoveAurasAtMechanicImmunity(mechanic, GetId());

    // check implemented in Unit::IsImmuneToSpell and Unit::IsImmuneToSpellEffect
}

//this method is called whenever we add / remove aura which gives m_target some imunity to some spell effect
void Aura::HandleAuraModEffectImmunity(bool apply, bool /*Real*/)
{
    Unit* target = GetTarget();

    // when removing flag aura, handle flag drop
    if (target->IsPlayer() && !target->HasAuraType(SPELL_AURA_MOD_POSSESS) && (GetSpellProto()->AuraInterruptFlags & AURA_INTERRUPT_FLAG_IMMUNE_OR_LOST_SELECTION))
    {
        Player* player = static_cast<Player*>(target);

        if (apply)
            player->pvpInfo.isPvPFlagCarrier = true;
        else
        {
            player->pvpInfo.isPvPFlagCarrier = false;

            if (BattleGround* bg = player->GetBattleGround())
                bg->EventPlayerDroppedFlag(player);
        }
    }

    target->ApplySpellImmune(GetId(), IMMUNITY_EFFECT, m_modifier.m_miscvalue, apply);
}

void Aura::HandleAuraModStateImmunity(bool apply, bool Real)
{
    if (apply && Real && GetSpellProto()->AttributesEx & SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY)
    {
        Unit::AuraList const& auraList = GetTarget()->GetAurasByType(AuraType(m_modifier.m_miscvalue));
        for (Unit::AuraList::const_iterator itr = auraList.begin(); itr != auraList.end();)
        {
            if (auraList.front() != this)                   // skip itself aura (it already added)
            {
                GetTarget()->RemoveAurasDueToSpell(auraList.front()->GetId());
                itr = auraList.begin();
            }
            else
                ++itr;
        }
    }

    GetTarget()->ApplySpellImmune(GetId(), IMMUNITY_STATE, m_modifier.m_miscvalue, apply);
}

    bool refresh = stackAmount >= GetStackAmount() && (m_spellInfo->StackAmount || (!m_spellInfo->HasAttribute(SPELL_ATTR1_AURA_UNIQUE) && !m_spellInfo->HasAttribute(SPELL_ATTR5_AURA_UNIQUE_PER_CASTER)));
void Aura::HandleAuraModSchoolImmunity(bool apply, bool Real)
{
    Unit* target = GetTarget();
    target->ApplySpellImmune(GetId(), IMMUNITY_SCHOOL, m_modifier.m_miscvalue, apply);

    // remove all flag auras (they are positive, but they must be removed when you are immune)
    if (apply && GetSpellProto()->AttributesEx & SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY
              && GetSpellProto()->AttributesEx2 & SPELL_ATTR_EX2_DAMAGE_REDUCED_SHIELD
              && target->IsPlayer() && !target->IsCharmed())
        target->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_IMMUNE_OR_LOST_SELECTION);

    // TODO: optimalize this cycle - use RemoveAurasWithInterruptFlags call or something else
    if (Real && GetSpellProto()->HasAttribute(SPELL_ATTR_EX_DISPEL_AURAS_ON_IMMUNITY)
             && IsPositiveSpell(GetId()))                        // Only positive immunity removes auras
    {
        if (apply)
        {
            uint32 school_mask = m_modifier.m_miscvalue;
            Unit::SpellAuraHolderMap& Auras = target->GetSpellAuraHolderMap();
            for (Unit::SpellAuraHolderMap::iterator iter = Auras.begin(), next; iter != Auras.end(); iter = next)
            {
                next = iter;
                ++next;
                SpellEntry const* spell = iter->second->GetSpellProto();
                if ((spell->GetSpellSchoolMask() & school_mask) // Check for school mask
                    && !(spell->Attributes & SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY)    // Spells unaffected by invulnerability
                    && !iter->second->IsPositive()          // Don't remove positive spells
                    && spell->Id != GetId())                // Don't remove self
                {
                    target->RemoveAurasDueToSpell(spell->Id);
                    if (Auras.empty())
                        break;
                    else
                        next = Auras.begin();
                }
            }
            target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE);
        }
        else
        {
            // Do not remove unit flag if there are more than this auraEffect of that kind on unit
            if (!target->HasAuraType(SPELL_AURA_SCHOOL_IMMUNITY))
                target->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE);
        }

    }

    if (Real && GetSpellProto()->Mechanic == MECHANIC_BANISH)
    {
        if (apply)
            target->AddUnitState(UNIT_STAT_ISOLATED);
        else
            target->ClearUnitState(UNIT_STAT_ISOLATED);
    }
}

void Aura::HandleAuraModDmgImmunity(bool apply, bool /*Real*/)
{
    GetTarget()->ApplySpellImmune(GetId(), IMMUNITY_DAMAGE, m_modifier.m_miscvalue, apply);
}

void Aura::HandleAuraModDispelImmunity(bool apply, bool Real)
{
    // all applied/removed only at real aura add/remove
    if (!Real)
        return;

    if (GetId() == 20594) // Forme de pierre
    {
        GetTarget()->ApplySpellDispelImmunity(GetSpellProto(), DISPEL_DISEASE, apply);
        GetTarget()->ApplySpellDispelImmunity(GetSpellProto(), DISPEL_POISON, apply);
        return;
    }
    GetTarget()->ApplySpellDispelImmunity(GetSpellProto(), DispelType(m_modifier.m_miscvalue), apply);
}

bool Aura::HasMoreThanOneEffectForType(AuraType auraType) const
{
    uint32 count = 0;
    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
        if (HasEffect(spellEffectInfo.EffectIndex) && spellEffectInfo.ApplyAuraName == auraType)
            ++count;
void Aura::HandleAuraProcTriggerSpell(bool apply, bool Real)
{
    if (!Real)
        return;

    switch (GetId())
    {
        // some spell have charges by functionality not have its in spell data
        case 28200:                                         // Ascendance (Talisman of Ascendance trinket)
        {
            if (apply)
                GetHolder()->SetAuraCharges(6);
            break;
        }
        default:
            break;
    }
}

void Aura::HandleAuraModStalked(bool apply, bool /*Real*/)
{
    // used by spells: Hunter's Mark, Mind Vision, Syndicate Tracker (MURP) DND
    if (apply)
    {
        GetTarget()->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_TRACK_UNIT);
        GetTarget()->ForceValuesUpdateAtIndex(UNIT_DYNAMIC_FLAGS);
    }
    else
        GetTarget()->RemoveFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_TRACK_UNIT);
}

/*********************************************************/
/***                   PERIODIC                        ***/
/*********************************************************/

void Aura::HandlePeriodicTriggerSpell(bool apply, bool /*Real*/)
{
    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
        if (HasEffect(spellEffectInfo.EffectIndex) && spellEffectInfo.IsAreaAuraEffect())
            return true;
    m_isPeriodic = apply;

    Unit* target = GetTarget();

    if (!apply)
    {
        switch (GetId())
        {
            case 23620:                                     // Burning Adrenaline
                if (m_removeMode == AURA_REMOVE_BY_DEATH)
                    target->CastSpell(target, 23478, true);
                return;
                /*
                this is not needed. Might have been in the past, but if functions correct without this hack now.
            case 29213:                                     // Curse of the Plaguebringer
                if (m_removeMode != AURA_REMOVE_BY_DISPEL)
                    // Cast Wrath of the Plaguebringer if not dispelled
                    target->CastSpell(target, 29214, true, nullptr, this);
                return;
                */
            default:
                break;
        }
    }
}

void Aura::HandlePeriodicTriggerSpellWithValue(bool apply, bool /*Real*/)
{
    m_isPeriodic = apply;
}

void Aura::HandlePeriodicEnergize(bool apply, bool /*Real*/)
{
    m_isPeriodic = apply;
}

bool Aura::IsRemovedOnShapeLost(Unit* target) const
{
    return GetCasterGUID() == target->GetGUID()
        && m_spellInfo->Stances
        && !m_spellInfo->HasAttribute(SPELL_ATTR2_ALLOW_WHILE_NOT_SHAPESHIFTED_CASTER_FORM)
        && !m_spellInfo->HasAttribute(SPELL_ATTR0_NOT_SHAPESHIFTED);
}

bool Aura::CanBeSaved() const
void Aura::HandleAuraPowerBurn(bool apply, bool /*Real*/)
{
    m_isPeriodic = apply;
}

void Aura::HandlePeriodicHeal(bool apply, bool /*Real*/)
{
    m_isPeriodic = apply;

    // Check if aura is single target, not only spell info
    if (GetCasterGUID() != GetOwner()->GetGUID())
    {
        // owner == caster for area auras, check for possible bad data in DB
        for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
        {
            if (!spellEffectInfo.IsEffect())
                continue;

            if (spellEffectInfo.IsTargetingArea() || spellEffectInfo.IsAreaAuraEffect())
                return false;
        }
    Unit* target = GetTarget();

        if (IsSingleTarget() || GetSpellInfo()->IsSingleTarget())
            return false;
    }

    if (GetSpellInfo()->HasAttribute(SPELL_ATTR0_CU_AURA_CANNOT_BE_SAVED))
        return false;
    // For prevent double apply bonuses
    bool loading = (target->GetTypeId() == TYPEID_PLAYER && ((Player*)target)->GetSession()->PlayerLoading());

    // Custom damage calculation after
    if (apply)
    {
        if (loading)
            return;

        Unit* caster = GetCaster();
        if (!caster)
            return;

        // World of Warcraft Client Patch 1.11.0 (2006-06-20)
        // - Periodic Healing: Spells which do periodic healing will now have
        //   their strength determined at the moment they are cast.Changing the
        //   amount of bonus healing you have during the duration of the periodic
        //   spell will have no impact on how much it heals for.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
        m_modifier.m_amount = caster->SpellHealingBonusDone(target, GetSpellProto(), GetEffIndex(), m_modifier.m_amount, DOT, GetStackAmount());
#endif
    }
}

float Aura::CalculateDotDamage() const
{
    Unit* target = GetTarget();
    Unit* caster = GetCaster();
    SpellEntry const* spellProto = GetSpellProto();

    float damage = m_modifier.m_amount;

    switch (spellProto->SpellFamilyName)
    {
        case SPELL_SPECIFIC_MAGE_POLYMORPH:
            if (aura->GetSpellInfo()->GetSpellSpecific() == spec)
                return true;
        case SPELLFAMILY_DRUID:
        {
            // Rip
            if (spellProto->IsFitToFamilyMask<CF_DRUID_RIP_BITE>())
            {
                // $AP * min(0.06*$cp, 0.24)/6 [Yes, there is no difference, whether 4 or 5 CPs are being used]
                if (caster->GetTypeId() == TYPEID_PLAYER)
                {
                    uint8 cp = ((Player*)caster)->GetComboPoints();

                    if (cp > 4) cp = 4;
                    damage += caster->GetTotalAttackPowerValue(BASE_ATTACK) * cp / 100;
                }
            }
            break;
        }
        case SPELLFAMILY_ROGUE:
        {
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_11_2
            // World of Warcraft Client Patch 1.12.0 (2006-08-22)
            // - Rupture: Rupture now increases in potency with greater attack power.
            if (spellProto->IsFitToFamilyMask<CF_ROGUE_RUPTURE>())
            {
                // Dmg/tick = $AP*min(0.01*$cp, 0.03) [Like Rip: only the first three CP increase the contribution from AP]
                if (caster->IsPlayer())
                {
                    uint8 cp = ((Player*)caster)->GetComboPoints();
                    if (cp > 3) cp = 3;
                    damage += caster->GetTotalAttackPowerValue(BASE_ATTACK) * cp / 100;
                }
            }
            // World of Warcraft Client Patch 1.12.0 (2006-08-22)
            // - Garrote: The damage from this ability has been increased. In
            //   addition, Garrote now increases in potency with greater attack power.
            else if (spellProto->IsFitToFamilyMask<CF_ROGUE_GARROTE>())
                damage += caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.03f;
#endif
            break;
        }
        default:
            break;
    }

    return false;
    if (m_modifier.m_auraname == SPELL_AURA_PERIODIC_DAMAGE)
    {
        // SpellDamageBonusDone for magic spells
        if (spellProto->DmgClass == SPELL_DAMAGE_CLASS_NONE || spellProto->DmgClass == SPELL_DAMAGE_CLASS_MAGIC)
            damage = caster->SpellDamageBonusDone(target, GetSpellProto(), GetEffIndex(), damage, DOT, GetStackAmount());
        // MeleeDamagebonusDone for weapon based spells
        else
        {
            WeaponAttackType attackType = GetSpellProto()->GetWeaponAttackType();
            damage = caster->MeleeDamageBonusDone(target, damage, attackType, GetSpellProto(), GetEffIndex(), DOT, GetStackAmount());
        }
    }

    return damage;
}

void Aura::HandlePeriodicDamage(bool apply, bool Real)
{
    // spells required only Real aura add/remove
    if (!Real)
        return;

    m_isPeriodic = apply;

    // World of Warcraft Client Patch 1.10.0 (2006-03-28)
    // - Damage over time spells are no longer affected by changes in
    //   equipment after the cast.
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
    Unit* target = GetTarget();

    // For prevent double apply bonuses
    bool loading = (target->GetTypeId() == TYPEID_PLAYER && ((Player*)target)->GetSession()->PlayerLoading());

    // Custom damage calculation after
    if (apply)
    {
        if (loading)
            return;

        if (!GetCaster())
            return;

        m_modifier.m_amount = CalculateDotDamage();
    }
#endif
}

void Aura::HandlePeriodicDamagePCT(bool apply, bool /*Real*/)
{
    m_isPeriodic = apply;
}

void Aura::HandlePeriodicLeech(bool apply, bool /*Real*/)
{
    m_isPeriodic = apply;

    // For prevent double apply bonuses
    bool loading = (GetTarget()->GetTypeId() == TYPEID_PLAYER && ((Player*)GetTarget())->GetSession()->PlayerLoading());

    // Custom damage calculation after
    if (apply)
    {
        if (loading)
            return;

        Unit* caster = GetCaster();
        if (!caster)
            return;

        m_modifier.m_amount = caster->SpellDamageBonusDone(GetTarget(), GetSpellProto(), GetEffIndex(), m_modifier.m_amount, DOT, GetStackAmount());
    }
}

void Aura::HandlePeriodicManaLeech(bool apply, bool /*Real*/)
{
    m_isPeriodic = apply;
}

void Aura::HandlePeriodicHealthFunnel(bool apply, bool /*Real*/)
{
    m_isPeriodic = apply;

    // For prevent double apply bonuses
    bool loading = (GetTarget()->GetTypeId() == TYPEID_PLAYER && ((Player*)GetTarget())->GetSession()->PlayerLoading());

    // Custom damage calculation after
    if (apply)
    {
        if (loading)
            return;

        Unit* caster = GetCaster();
        if (!caster)
            return;

        m_modifier.m_amount = caster->SpellDamageBonusDone(GetTarget(), GetSpellProto(), GetEffIndex(), m_modifier.m_amount, DOT, GetStackAmount());
    }
}

/*********************************************************/
/***                  MODIFY STATS                     ***/
/*********************************************************/

/********************************/
/***        RESISTANCE        ***/
/********************************/

void Aura::HandleAuraModResistanceExclusive(bool apply, bool /*Real*/)
{
    if (!m_modifier.m_amount)
        return;

    Unit* target = GetTarget();

    for (uint32 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
    {
        if (m_modifier.m_miscvalue & (1 << i))
        {
            // Apply the value exclusively for each school
            float const amount = m_modifier.m_amount;
            float bonusMax = 0;
            float malusMax = 0;

            for (Aura* aura : target->GetAurasByType(m_modifier.m_auraname))
            {
                if (aura == this || !(aura->GetMiscValue() & (1 << i)))
                    continue;

                float const mod = aura->GetModifier()->m_amount;

                if (mod > bonusMax)
                    bonusMax = mod;
                else if (mod < malusMax)
                    malusMax = mod;
            }

            if (amount > bonusMax)
            {
                target->HandleStatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + i), TOTAL_VALUE, apply ? bonusMax : amount, false);
                target->HandleStatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + i), TOTAL_VALUE, apply ? amount : bonusMax, true);
                // UI bonus info:
                if (target->GetTypeId() == TYPEID_PLAYER)
                {
                    static_cast<Player*>(target)->ApplyResistanceBuffModsMod(SpellSchools(i), true, apply ? bonusMax : amount, false);
                    static_cast<Player*>(target)->ApplyResistanceBuffModsMod(SpellSchools(i), true, apply ? amount : bonusMax, true);
                }
            }
            else if (amount < malusMax)
            {
                target->HandleStatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + i), TOTAL_VALUE, apply ? malusMax : amount, false);
                target->HandleStatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + i), TOTAL_VALUE, apply ? amount : malusMax, true);
                // UI malus info:
                if (target->GetTypeId() == TYPEID_PLAYER)
                {
                    static_cast<Player*>(target)->ApplyResistanceBuffModsMod(SpellSchools(i), false, apply ? malusMax : amount, false);
                    static_cast<Player*>(target)->ApplyResistanceBuffModsMod(SpellSchools(i), false, apply ? amount : malusMax, true);
                }
            }
        }
    }
}

void Aura::HandleAuraModResistance(bool apply, bool /*Real*/)
{
    if (!m_modifier.m_amount)
        return;

    Unit* target = GetTarget();

    for (uint32 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
    {
        if (m_modifier.m_miscvalue & (1 << i))
        {
            target->HandleStatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + i), TOTAL_VALUE, m_modifier.m_amount, apply);
            // UI bonus/malus info:
            if (target->GetTypeId() == TYPEID_PLAYER)
                static_cast<Player*>(target)->ApplyResistanceBuffModsMod(SpellSchools(i), (m_modifier.m_amount > 0), m_modifier.m_amount, apply);
        }
}

    // Faerie Fire (druid versions)
    SpellEntry const* spellProto = GetSpellProto();
    if (spellProto->SpellIconID == 109 && spellProto->IsFitToFamily<SPELLFAMILY_DRUID, CF_DRUID_FAERIE_FIRE>())
    {
        target->ApplySpellDispelImmunity(spellProto, DISPEL_STEALTH, apply);
        target->ApplySpellDispelImmunity(spellProto, DISPEL_INVISIBILITY, apply);
    }
}


void Aura::HandleAurasVisible(bool apply, bool /*Real*/)
{
    GetTarget()->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_AURAS_VISIBLE, apply);
}

void Aura::HandleModResistancePercent(bool apply, bool /*Real*/)
{
    if (!m_modifier.m_amount)
        return;

    Unit* target = GetTarget();

    for (uint32 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
    {
        if (m_modifier.m_miscvalue & (1 << i))
        {
            target->HandleStatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + i), TOTAL_PCT, m_modifier.m_amount, apply);
            // UI bonus/malus info:
            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                static_cast<Player*>(target)->ApplyResistanceBuffModsPercentMod(SpellSchools(i), true, m_modifier.m_amount, apply);
                static_cast<Player*>(target)->ApplyResistanceBuffModsPercentMod(SpellSchools(i), false, m_modifier.m_amount, apply);
            }
        }
    }
}

void Aura::HandleModBaseResistance(bool apply, bool /*Real*/)
{
    if (!m_modifier.m_amount)
        return;

    Unit* target = GetTarget();

    for (uint32 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
    {
        if (m_modifier.m_miscvalue & (1 << i))
            target->HandleStatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + i), BASE_VALUE, m_modifier.m_amount, apply);
    }
}

void Aura::HandleAuraModBaseResistancePercent(bool apply, bool /*Real*/)
{
    if (!m_modifier.m_amount)
        return;

    Unit* target = GetTarget();

    for (uint32 i = SPELL_SCHOOL_NORMAL; i < MAX_SPELL_SCHOOL; ++i)
    {
        if (m_modifier.m_miscvalue & (1 << i))
            target->HandleStatModifier(UnitMods(UNIT_MOD_RESISTANCE_START + i), BASE_PCT, m_modifier.m_amount, apply);
    }
}

/********************************/
/***           STAT           ***/
/********************************/

void Aura::HandleAuraModStat(bool apply, bool /*Real*/)
{
    if (m_modifier.m_miscvalue < -2 || m_modifier.m_miscvalue > 4)
    {
        sLog.outError("WARNING: Spell %u effect %u have unsupported misc value (%i) for SPELL_AURA_MOD_STAT ", GetId(), GetEffIndex(), m_modifier.m_miscvalue);
        return;
    }

    Unit* target = GetTarget();

    // Improved Scorpid Sting
    if (GetSpellProto()->IsFitToFamilyMask<CF_HUNTER_SCORPID_STING>() && (m_modifier.m_miscvalue == STAT_STRENGTH))
    {
        if (apply)
        {
            int32 staminaToRemove = 0;
            Unit::AuraList const& auraClassScripts = GetCaster()->GetAurasByType(SPELL_AURA_OVERRIDE_CLASS_SCRIPTS);
            for (const auto& aura : auraClassScripts)
            {
                bool exitLoop = false;
                switch (aura->GetModifier()->m_miscvalue)
                {
                    case 2388: staminaToRemove = m_modifier.m_amount * 10 / 100; exitLoop = true; break; // Rank 1
                    case 2389: staminaToRemove = m_modifier.m_amount * 20 / 100; exitLoop = true; break; // Rank 2
                    case 2390: staminaToRemove = m_modifier.m_amount * 30 / 100; exitLoop = true; break; // Rank 3
                }
                if (exitLoop)
                    break;
            }
            if (staminaToRemove)
                GetCaster()->CastCustomSpell(target, 19486, staminaToRemove, {}, {}, true);
        }
        else
            target->RemoveAurasDueToSpell(19486, this->GetHolder());
    }

    for (int32 i = STAT_STRENGTH; i < MAX_STATS; i++)
    {
        // -1 or -2 is all stats ( misc < -2 checked in function beginning )
        if (m_modifier.m_miscvalue < 0 || m_modifier.m_miscvalue == i)
        {
            //m_target->ApplyStatMod(Stats(i), m_modifier.m_amount,apply);
            target->HandleStatModifier(UnitMods(UNIT_MOD_STAT_START + i), TOTAL_VALUE, m_modifier.m_amount, apply);
            if (target->GetTypeId() == TYPEID_PLAYER)
                ((Player*)target)->ApplyStatBuffMod(Stats(i), m_modifier.m_amount, apply);
        }
    }
}

void Aura::HandleModPercentStat(bool apply, bool /*Real*/)
{
    if (m_modifier.m_miscvalue < -1 || m_modifier.m_miscvalue > 4)
    {
        sLog.outError("WARNING: Misc Value for SPELL_AURA_MOD_PERCENT_STAT not valid");
        return;
    }

    // only players have base stats
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    for (int32 i = STAT_STRENGTH; i < MAX_STATS; ++i)
    {
        if (m_modifier.m_miscvalue == i || m_modifier.m_miscvalue == -1)
            GetTarget()->HandleStatModifier(UnitMods(UNIT_MOD_STAT_START + i), BASE_PCT, m_modifier.m_amount, apply);
    }
}

void Aura::HandleModSpellDamagePercentFromStat(bool /*apply*/, bool /*Real*/)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    // Magic damage modifiers implemented in Unit::SpellDamageBonusDone
    // This information for client side use only
    // Recalculate bonus
    ((Player*)GetTarget())->UpdateSpellDamageAndHealingBonus();
}

void Aura::HandleModSpellHealingPercentFromStat(bool /*apply*/, bool /*Real*/)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    // Recalculate bonus
    ((Player*)GetTarget())->UpdateSpellDamageAndHealingBonus();
}

void Aura::HandleModHealingDone(bool /*apply*/, bool /*Real*/)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;
    // implemented in Unit::SpellHealingBonusDone
    // this information is for client side only
    ((Player*)GetTarget())->UpdateSpellDamageAndHealingBonus();
}

void Aura::HandleModTotalPercentStat(bool apply, bool /*Real*/)
{
    if (m_modifier.m_miscvalue < -1 || m_modifier.m_miscvalue > 4)
    {
        sLog.outError("WARNING: Misc Value for SPELL_AURA_MOD_PERCENT_STAT not valid");
        return;
    }

    Unit* target = GetTarget();

    //save current and max HP before applying aura
    uint32 curHPValue = target->GetHealth();
    uint32 maxHPValue = target->GetMaxHealth();

    for (int32 i = STAT_STRENGTH; i < MAX_STATS; i++)
    {
        if (m_modifier.m_miscvalue == i || m_modifier.m_miscvalue == -1)
        {
            target->HandleStatModifier(UnitMods(UNIT_MOD_STAT_START + i), TOTAL_PCT, m_modifier.m_amount, apply);
            if (target->GetTypeId() == TYPEID_PLAYER)
                ((Player*)target)->ApplyStatPercentBuffMod(Stats(i), m_modifier.m_amount, apply);
        }
    }

uint32 Aura::GetEffectMask() const
{
    uint32 effMask = 0;
    for (AuraEffect* aurEff : GetAuraEffects())
        if (aurEff)
            effMask |= 1 << aurEff->GetEffIndex();
    return effMask;
    //recalculate current HP/MP after applying aura modifications (only for spells with 0x10 flag)
    if ((m_modifier.m_miscvalue == STAT_STAMINA) && (maxHPValue > 0) && (GetSpellProto()->Attributes & 0x10) && target->IsAlive())
    {
        // newHP = (curHP / maxHP) * newMaxHP = (newMaxHP * curHP) / maxHP -> which is better because no int -> double -> int conversion is needed
        uint32 newHPValue = (target->GetMaxHealth() * curHPValue) / maxHPValue;
        target->SetHealth(newHPValue);
    }
}

void Aura::GetApplicationVector(std::vector<AuraApplication*>& applicationList) const
void Aura::HandleAuraModResistenceOfStatPercent(bool /*apply*/, bool /*Real*/)
{
    for (auto const& applicationPair : m_applications)
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    if (m_modifier.m_miscvalue != SPELL_SCHOOL_MASK_NORMAL)
    {
        if (!applicationPair.second->GetEffectMask())
            continue;

        applicationList.push_back(applicationPair.second);
        // support required adding replace UpdateArmor by loop by UpdateResistence at intellect update
        // and include in UpdateResistence same code as in UpdateArmor for aura mod apply.
        sLog.outError("Aura SPELL_AURA_MOD_RESISTANCE_OF_STAT_PERCENT(182) need adding support for non-armor resistances!");
        return;
    }

    // Recalculate Armor
    GetTarget()->UpdateArmor();
}

/********************************/
/***      HEAL & ENERGIZE     ***/
/********************************/
void Aura::HandleAuraModTotalHealthPercentRegen(bool apply, bool /*Real*/)
{
    m_isPeriodic = apply;
}

void Aura::HandleAuraModTotalManaPercentRegen(bool apply, bool /*Real*/)
{
    if (m_modifier.periodictime == 0)
        m_modifier.periodictime = 1000;

    m_periodicTimer = m_modifier.periodictime;
    m_isPeriodic = apply;
}

void Aura::HandleModRegen(bool apply, bool /*Real*/)        // eating
{
    if (m_modifier.periodictime == 0)
        m_modifier.periodictime = 5000;

    m_periodicTimer = 5000;
    m_isPeriodic = apply;
}

        for (SpellAreaForAreaMap::const_iterator itr = saBounds.first; itr != saBounds.second; ++itr)
        {
            // some auras remove at aura remove
            if (itr->second->flags & SPELL_AREA_FLAG_AUTOREMOVE && !itr->second->IsFitToRequirements(target->ToPlayer(), zone, area))
                target->RemoveAurasDueToSpell(itr->second->spellId);
            // some auras applied at aura apply
            else if (itr->second->flags & SPELL_AREA_FLAG_AUTOCAST)
            {
                if (!target->HasAura(itr->second->spellId))
                    target->CastSpell(target, itr->second->spellId, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                        .SetOriginalCastId(GetCastId()));
            }
        }
    }
void Aura::HandleModPowerRegen(bool apply, bool Real)       // drinking
{
    if (!Real)
        return;

    Powers pt = GetTarget()->GetPowerType();
    if (m_modifier.periodictime == 0)
    {
        // Anger Management (only spell use this aura for rage)
        if (pt == POWER_RAGE)
            m_modifier.periodictime = 3000;
        else
            m_modifier.periodictime = 2000;
    }

    m_periodicTimer = 5000;

    if (m_modifier.m_miscvalue == POWER_MANA)
        (GetTarget())->UpdateManaRegen();

    m_isPeriodic = apply;
}

void Aura::HandleModPowerRegenPCT(bool /*apply*/, bool Real)
{
    // spells required only Real aura add/remove
    if (!Real)
        return;

    // Update manaregen value
    if (m_modifier.m_miscvalue == POWER_MANA)
        (GetTarget())->UpdateManaRegen();
}

    // handle spell_linked_spell table
    if (!onReapply)
    {
        // apply linked auras
        if (apply)
        {
            if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(SPELL_LINK_AURA, GetId()))
            {
                for (std::vector<int32>::const_iterator itr = spellTriggered->begin(); itr != spellTriggered->end(); ++itr)
                {
                    if (*itr < 0)
                        target->ApplySpellImmune(GetId(), IMMUNITY_ID, -(*itr), true);
                    else if (caster)
                        caster->AddAura(*itr, target);
                }
            }
        }
        else
        {
            // remove linked auras
            if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(SPELL_LINK_REMOVE, GetId()))
            {
                for (std::vector<int32>::const_iterator itr = spellTriggered->begin(); itr != spellTriggered->end(); ++itr)
                {
                    if (*itr < 0)
                        target->RemoveAurasDueToSpell(-(*itr));
                    else if (removeMode != AURA_REMOVE_BY_DEATH)
                        target->CastSpell(target, *itr, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                            .SetOriginalCaster(GetCasterGUID())
                            .SetOriginalCastId(GetCastId()));
                }
            }
            if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(SPELL_LINK_AURA, GetId()))
            {
                for (std::vector<int32>::const_iterator itr = spellTriggered->begin(); itr != spellTriggered->end(); ++itr)
                {
                    if (*itr < 0)
                        target->ApplySpellImmune(GetId(), IMMUNITY_ID, -(*itr), false);
                    else
                        target->RemoveAura(*itr, GetCasterGUID(), 0, removeMode);
                }
            }
        }
    }
    else if (apply)
    {
        // modify stack amount of linked auras
        if (std::vector<int32> const* spellTriggered = sSpellMgr->GetSpellLinked(SPELL_LINK_AURA, GetId()))
        {
            for (std::vector<int32>::const_iterator itr = spellTriggered->begin(); itr != spellTriggered->end(); ++itr)
                if (*itr > 0)
                    if (Aura* triggeredAura = target->GetAura(*itr, GetCasterGUID()))
                        triggeredAura->ModStackAmount(GetStackAmount() - triggeredAura->GetStackAmount());
        }
    }
void Aura::HandleAuraModIncreaseHealth(bool apply, bool Real)
{
    Unit* target = GetTarget();

    // Special case with temporary increase max/current health
    switch (GetId())
    {
        case 12976:                                         // Warrior Last Stand triggered spell
        {
            if (Real)
            {
                if (apply)
                {
                    target->HandleStatModifier(UNIT_MOD_HEALTH, TOTAL_VALUE, m_modifier.m_amount, apply);
                    target->ModifyHealth(m_modifier.m_amount);
                }
                else
                {
                    if (int32(target->GetHealth()) > m_modifier.m_amount)
                        target->ModifyHealth(-m_modifier.m_amount);
                    else if (target->IsAlive())
                        target->SetHealth(1);
                    target->HandleStatModifier(UNIT_MOD_HEALTH, TOTAL_VALUE, m_modifier.m_amount, apply);
                }
            }
            return;
        }
        // Druid bear form
        case 1178:
        case 9635:
        {
            if (Real)
            {
                float fHealthPercent = float(target->GetHealth()) / target->GetMaxHealth();
                int32 newMaxHealth = target->GetMaxHealth();
                if (apply)
                    newMaxHealth += m_modifier.m_amount;
                else
                    newMaxHealth -= m_modifier.m_amount;

                uint32 newHealth = ceil(newMaxHealth * fHealthPercent);
                target->HandleStatModifier(UNIT_MOD_HEALTH, TOTAL_VALUE, m_modifier.m_amount, apply);
                target->SetHealth(newHealth);
            }
            return;
        }
        // Trinket BWL (Don de vie)
        case 23782:
        {
            if (Real)
            {
                target->HandleStatModifier(UNIT_MOD_HEALTH, TOTAL_PCT, 15.0f, apply);
                if (apply)
                {
                    int32 healAmount = dither(target->GetMaxHealth() * 0.15f);
                    target->CastCustomSpell(target, 23783, healAmount, {}, {}, true, nullptr, this);
                }
            }
            return;
        }
    }

    // generic case
    target->HandleStatModifier(UNIT_MOD_HEALTH, TOTAL_VALUE, m_modifier.m_amount, apply);
}

void Aura::HandleAuraModIncreaseEnergy(bool apply, bool /*Real*/)
{
    Unit* target = GetTarget();
    Powers powerType = Powers(m_modifier.m_miscvalue);

    UnitMods unitMod = UnitMods(UNIT_MOD_POWER_START + powerType);

    target->HandleStatModifier(unitMod, TOTAL_VALUE, m_modifier.m_amount, apply);
    target->ModifyPower(powerType, apply ? m_modifier.m_amount : -m_modifier.m_amount);
}

void Aura::HandleAuraModIncreaseEnergyPercent(bool apply, bool /*Real*/)
{
    Unit* target = GetTarget();
    Powers powerType = Powers(m_modifier.m_miscvalue);
    float powerPercent = target->GetPowerPercent(powerType);

    UnitMods unitMod = UnitMods(UNIT_MOD_POWER_START + powerType);
    target->HandleStatModifier(unitMod, TOTAL_PCT, m_modifier.m_amount, apply);

    if (target->IsAlive())
        target->SetPower(powerType, target->GetMaxPower(powerType) * powerPercent / 100.0f);
}

void Aura::HandleAuraModIncreaseHealthPercent(bool apply, bool /*Real*/)
{
    Unit* target = GetTarget();
    float healthPercent = target->GetHealthPercent();
    target->HandleStatModifier(UNIT_MOD_HEALTH, TOTAL_PCT, m_modifier.m_amount, apply);

    if (target->IsAlive())
        target->SetHealthPercent(healthPercent);

    if (target->GetMaxHealth() == 1)
        target->DoKillUnit(target);
}

/********************************/
/***          FIGHT           ***/
/********************************/

void Aura::HandleAuraModParryPercent(bool /*apply*/, bool /*Real*/)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    ((Player*)GetTarget())->UpdateParryPercentage();
}

void Aura::HandleAuraModDodgePercent(bool /*apply*/, bool /*Real*/)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    ((Player*)GetTarget())->UpdateDodgePercentage();
    //sLog.outError("BONUS DODGE CHANCE: + %f", float(m_modifier.m_amount));
}

void Aura::HandleAuraModBlockPercent(bool /*apply*/, bool /*Real*/)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    ((Player*)GetTarget())->UpdateBlockPercentage();
    //sLog.outError("BONUS BLOCK CHANCE: + %f", float(m_modifier.m_amount));
}

void Aura::HandleAuraModRegenInterrupt(bool /*apply*/, bool Real)
{
    // spells required only Real aura add/remove
    if (!Real)
        return;

    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    ((Player*)GetTarget())->UpdateManaRegen();
}

void Aura::HandleAuraModCritPercent(bool apply, bool Real)
{
    Unit* target = GetTarget();

    if (target->GetTypeId() != TYPEID_PLAYER)
        return;

    // apply item specific bonuses for already equipped weapon
    if (Real)
    {
        for (int i = 0; i < MAX_ATTACK; ++i)
            if (Item* pItem = ((Player*)target)->GetWeaponForAttack(WeaponAttackType(i), true, false))
                ((Player*)target)->_ApplyWeaponDependentAuraCritMod(pItem, WeaponAttackType(i), this, apply);
    }

    // mods must be applied base at equipped weapon class and subclass comparison
    // with spell->EquippedItemClass and  EquippedItemSubClassMask and EquippedItemInventoryTypeMask
    // m_modifier.m_miscvalue comparison with item generated damage types

    if (GetSpellProto()->EquippedItemClass == -1)
    {
        ((Player*)target)->HandleBaseModValue(CRIT_PERCENTAGE,         FLAT_MOD, m_modifier.m_amount, apply);
        ((Player*)target)->HandleBaseModValue(OFFHAND_CRIT_PERCENTAGE, FLAT_MOD, m_modifier.m_amount, apply);
        ((Player*)target)->HandleBaseModValue(RANGED_CRIT_PERCENTAGE,  FLAT_MOD, m_modifier.m_amount, apply);
    }
    else
    {
        // done in Player::_ApplyWeaponDependentAuraMods
    }
}

void Aura::HandleModHitChance(bool apply, bool /*Real*/)
{
    Unit* target = GetTarget();

    if (GetId() != 22780) // [Ranged Hit Bonus +3] as stated in name ...
        target->m_modMeleeHitChance += apply ? m_modifier.m_amount : (-m_modifier.m_amount);
    target->m_modRangedHitChance += apply ? m_modifier.m_amount : (-m_modifier.m_amount);
}

void Aura::HandleModSpellHitChance(bool apply, bool /*Real*/)
{
    GetTarget()->m_modSpellHitChance += apply ? m_modifier.m_amount : (-m_modifier.m_amount);
}

void Aura::HandleModSpellCritChance(bool apply, bool Real)
{
    // spells required only Real aura add/remove
    if (!Real)
        return;

    if (GetTarget()->GetTypeId() == TYPEID_PLAYER)
        ((Player*)GetTarget())->UpdateAllSpellCritChances();
    else
        GetTarget()->m_baseSpellCritChance += apply ? m_modifier.m_amount : (-m_modifier.m_amount);
}

void Aura::HandleModSpellCritChanceSchool(bool /*apply*/, bool Real)
{
    // spells required only Real aura add/remove
    if (!Real)
        return;

    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    for (int school = SPELL_SCHOOL_NORMAL; school < MAX_SPELL_SCHOOL; ++school)
        if (m_modifier.m_miscvalue & (1 << school))
            ((Player*)GetTarget())->UpdateSpellCritChance(school);
}

/********************************/
/***         ATTACK SPEED     ***/
/********************************/

void Aura::HandleModCastingSpeed(bool apply, bool /*Real*/)
{
    if (apply)
    {
        if (Unit* caster = GetCaster())
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetSpellProto()->Id, SPELLMOD_HASTE, m_modifier.m_amount);
    }

    GetTarget()->ApplyCastTimePercentMod(m_modifier.m_amount, apply);
}

void Aura::HandleModAttackSpeed(bool apply, bool /*Real*/)
{
    if (apply)
    {
        switch (GetSpellInfo()->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
                switch (GetId())
                {
                    case 33572: // Gronn Lord's Grasp, becomes stoned
                        if (GetStackAmount() >= 5 && !target->HasAura(33652))
                            target->CastSpell(target, 33652, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                                .SetOriginalCastId(GetCastId()));
                        break;
                    case 50836: //Petrifying Grip, becomes stoned
                        if (GetStackAmount() >= 5 && !target->HasAura(50812))
                            target->CastSpell(target, 50812, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                                .SetOriginalCastId(GetCastId()));
                        break;
                    case 60970: // Heroic Fury (remove Intercept cooldown)
                        if (target->GetTypeId() == TYPEID_PLAYER)
                            target->GetSpellHistory()->ResetCooldown(20252, true);
                        break;
                }
                break;
            case SPELLFAMILY_DRUID:
                if (!caster)
                    break;
                // Rejuvenation
                if (GetSpellInfo()->SpellFamilyFlags[0] & 0x10 && GetEffect(EFFECT_0))
                {
                    // Druid T8 Restoration 4P Bonus
                    if (caster->HasAura(64760))
                    {
                        CastSpellExtraArgs args(GetEffect(EFFECT_0));
                        args.AddSpellMod(SPELLVALUE_BASE_POINT0, GetEffect(EFFECT_0)->GetAmount());
                        caster->CastSpell(target, 64801, args);
                    }
                }
                break;
        }
        if (Unit* caster = GetCaster())
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetSpellProto()->Id, SPELLMOD_HASTE, m_modifier.m_amount);
    }

    Unit* target = GetTarget();
    target->ApplyAttackTimePercentMod(BASE_ATTACK, m_modifier.m_amount, apply);
    target->ApplyAttackTimePercentMod(OFF_ATTACK, m_modifier.m_amount, apply);
    target->ApplyAttackTimePercentMod(RANGED_ATTACK, m_modifier.m_amount, apply);

    // Seal of the Crusader damage reduction
    // SoC increases attack speed but reduces damage to maintain the same DPS
    if (GetSpellProto()->IsFitToFamily<SPELLFAMILY_PALADIN, CF_PALADIN_SEAL_OF_THE_CRUSADER>())
    {
        float reduction = (-100.0f * m_modifier.m_amount) / (m_modifier.m_amount + 100.0f);
        target->HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, reduction, apply);
    }
}

void Aura::HandleModMeleeSpeedPct(bool apply, bool /*Real*/)
{
    if (apply)
    {
        if (Unit* caster = GetCaster())
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetSpellProto()->Id, SPELLMOD_HASTE, m_modifier.m_amount);
    }

    Unit* target = GetTarget();
    target->ApplyAttackTimePercentMod(BASE_ATTACK, m_modifier.m_amount, apply);
    target->ApplyAttackTimePercentMod(OFF_ATTACK, m_modifier.m_amount, apply);
}

void Aura::HandleAuraModRangedHaste(bool apply, bool /*Real*/)
{
    if (apply)
    {
        if (Unit* caster = GetCaster())
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetSpellProto()->Id, SPELLMOD_HASTE, m_modifier.m_amount);
    }

    GetTarget()->ApplyAttackTimePercentMod(RANGED_ATTACK, m_modifier.m_amount, apply);
}

void Aura::HandleRangedAmmoHaste(bool apply, bool /*Real*/)
{
    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    // Quivers should not increase attack speed for ranged weapons which do not require any ammo.
    Item* ranged_weapon = GetTarget()->ToPlayer()->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
    if (!ranged_weapon || ranged_weapon->GetProto()->AmmoType == 0)
        return;

    if (apply)
    {
        if (Unit* caster = GetCaster())
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetSpellProto()->Id, SPELLMOD_HASTE, m_modifier.m_amount);
    }

    GetTarget()->ApplyAttackTimePercentMod(RANGED_ATTACK, m_modifier.m_amount, apply);
}

/********************************/
/***        ATTACK POWER      ***/
/********************************/

void Aura::HandleAuraModAttackPower(bool apply, bool /*Real*/)
{
    if (apply)
    {
        if (Unit* caster = GetCaster())
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetSpellProto()->Id, SPELLMOD_ATTACK_POWER, m_modifier.m_amount);
    }
    // mods at aura remove
    else
    {
        switch (GetSpellInfo()->SpellFamilyName)
        {
            case SPELLFAMILY_MAGE:
                switch (GetId())
                {
                    case 66: // Invisibility
                        if (removeMode != AURA_REMOVE_BY_EXPIRE)
                            break;
                        target->CastSpell(target, 32612, GetEffect(1));
                        break;
                    default:
                        break;
                }
                break;
            case SPELLFAMILY_PRIEST:
                if (!caster)
                    break;
                // Power word: shield
                if (removeMode == AURA_REMOVE_BY_ENEMY_SPELL && GetSpellInfo()->SpellFamilyFlags[0] & 0x00000001)
                {
                    // Rapture
                    if (Aura const* aura = caster->GetAuraOfRankedSpell(47535))
                    {
                        // check cooldown
                        if (caster->GetTypeId() == TYPEID_PLAYER)
                        {
                            if (caster->GetSpellHistory()->HasCooldown(aura->GetSpellInfo()))
                            {
                                // This additional check is needed to add a minimal delay before cooldown in in effect
                                // to allow all bubbles broken by a single damage source proc mana return
                                if (caster->GetSpellHistory()->GetRemainingCooldown(aura->GetSpellInfo()) <= 11s)
                                    break;
                            }
                            else    // and add if needed
                                caster->GetSpellHistory()->AddCooldown(aura->GetId(), 0, 12s);
                        }

    GetTarget()->HandleStatModifier(UNIT_MOD_ATTACK_POWER, TOTAL_VALUE, m_modifier.m_amount, apply);

#if (SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_3_1) && (SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_8_4)
    // Blood Fury- Add aura to decrease attack power on remove
    if (!apply && GetId() == 23234 && (m_removeMode == AURA_REMOVE_BY_CANCEL || m_removeMode == AURA_REMOVE_BY_EXPIRE))
    {
        Unit* target = GetTarget();
        // using delayed event because of an error in ExclusiveAuraUnapply
        target->m_Events.AddLambdaEventAtOffset([target]
        {
            int32 attackPower = -25 * (target->GetInt32Value(UNIT_FIELD_ATTACK_POWER)) / 100;
            if (attackPower < 0)
                target->CastCustomSpell(target, 23230, attackPower, {}, {}, true, nullptr);
        }, 1);
    }
#endif
}

void Aura::HandleAuraModRangedAttackPower(bool apply, bool /*Real*/)
{
    if ((GetTarget()->GetClassMask() & CLASSMASK_WAND_USERS) != 0)
        return;

    if (apply)
    {
        if (Unit* caster = GetCaster())
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetSpellProto()->Id, SPELLMOD_ATTACK_POWER, m_modifier.m_amount);
    }

    GetTarget()->HandleStatModifier(UNIT_MOD_ATTACK_POWER_RANGED, TOTAL_VALUE, m_modifier.m_amount, apply);
}

void Aura::HandleAuraModAttackPowerPercent(bool apply, bool /*Real*/)
{
    if (apply)
    {
        if (Unit* caster = GetCaster())
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetSpellProto()->Id, SPELLMOD_ATTACK_POWER, m_modifier.m_amount);
    }

    // UNIT_FIELD_ATTACK_POWER_MULTIPLIER = multiplier - 1
    GetTarget()->HandleStatModifier(UNIT_MOD_ATTACK_POWER, TOTAL_PCT, m_modifier.m_amount, apply);
}

void Aura::HandleAuraModRangedAttackPowerPercent(bool apply, bool /*Real*/)
{
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
    if ((GetTarget()->GetClassMask() & CLASSMASK_WAND_USERS) != 0)
        return;

    if (apply)
    {
        if (Unit* caster = GetCaster())
            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetSpellProto()->Id, SPELLMOD_ATTACK_POWER, m_modifier.m_amount);
    }

    // UNIT_FIELD_RANGED_ATTACK_POWER_MULTIPLIER = multiplier - 1
    GetTarget()->HandleStatModifier(UNIT_MOD_ATTACK_POWER_RANGED, TOTAL_PCT, m_modifier.m_amount, apply);
#endif
}

                        // effect on caster
                        if (AuraEffect const* aurEff = aura->GetEffect(0))
                        {
                            float multiplier = float(aurEff->GetAmount());
                            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                            args.SetOriginalCastId(GetCastId());
                            args.AddSpellMod(SPELLVALUE_BASE_POINT0, CalculatePct(caster->GetMaxPower(POWER_MANA), multiplier));
                            caster->CastSpell(caster, 47755, args);
                        }
                    }
                }
                break;
            case SPELLFAMILY_ROGUE:
                // Remove Vanish on stealth remove
                if (GetId() == 1784)
                    target->RemoveAurasWithFamily(SPELLFAMILY_ROGUE, flag128(0x0000800, 0, 0, 0), target->GetGUID());
                break;
/********************************/
/***        DAMAGE BONUS      ***/
/********************************/
void Aura::HandleModDamageDone(bool apply, bool Real)
{
    Unit* target = GetTarget();

    // apply item specific bonuses for already equipped weapon
    if (Real && target->GetTypeId() == TYPEID_PLAYER)
    {
        for (int i = 0; i < MAX_ATTACK; ++i)
            if (Item* pItem = ((Player*)target)->GetWeaponForAttack(WeaponAttackType(i), true, false))
                ((Player*)target)->_ApplyWeaponDependentAuraDamageMod(pItem, WeaponAttackType(i), this, apply);
    }

    // m_modifier.m_miscvalue is bitmask of spell schools
    // 1 ( 0-bit ) - normal school damage (SPELL_SCHOOL_MASK_NORMAL)
    // 126 - full bitmask all magic damages (SPELL_SCHOOL_MASK_MAGIC) including wands
    // 127 - full bitmask any damages
    //
    // mods must be applied base at equipped weapon class and subclass comparison
    // with spell->EquippedItemClass and  EquippedItemSubClassMask and EquippedItemInventoryTypeMask
    // m_modifier.m_miscvalue comparison with item generated damage types

    if ((m_modifier.m_miscvalue & SPELL_SCHOOL_MASK_NORMAL) != 0)
    {
        // apply generic physical damage bonuses including wand case
        if (GetSpellProto()->EquippedItemClass == -1 || target->GetTypeId() != TYPEID_PLAYER)
        {
            target->HandleStatModifier(UNIT_MOD_DAMAGE_PHYSICAL, TOTAL_VALUE, float(m_modifier.m_amount), apply);
        }
        else
        {
            // done in Player::_ApplyWeaponDependentAuraMods
        }

        if (target->GetTypeId() == TYPEID_PLAYER)
        {
            if (m_positive)
                target->ApplyModUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS, m_modifier.m_amount, apply);
            else
                target->ApplyModUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG, m_modifier.m_amount, apply);
        }
    }

    // Skip non magic case for speedup
    if ((m_modifier.m_miscvalue & SPELL_SCHOOL_MASK_MAGIC) == 0)
        return;

    if (GetSpellProto()->EquippedItemClass != -1 || GetSpellProto()->EquippedItemInventoryTypeMask != 0)
    {
        case SPELLFAMILY_HUNTER:
            switch (GetId())
            {
                case 19574: // Bestial Wrath
                    // The Beast Within cast on owner if talent present
                    if (Unit* owner = target->GetOwner())
                    {
                        // Search talent
                        if (owner->HasAura(34692))
                        {
                            if (apply)
                                owner->CastSpell(owner, 34471, GetEffect(0));
                            else
                                owner->RemoveAurasDueToSpell(34471);
                        }
                    }
                    break;
            }
            break;
        case SPELLFAMILY_PALADIN:
            switch (GetId())
            {
                case 31842: // Divine Favor
                    // Item - Paladin T10 Holy 2P Bonus
                    if (target->HasAura(70755))
                    {
                        if (apply)
                            target->CastSpell(target, 71166, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                                .SetOriginalCastId(GetCastId()));
                        else
                            target->RemoveAurasDueToSpell(71166);
                    }
                    break;
        // wand magic case (skip generic to all item spell bonuses)
        // done in Player::_ApplyWeaponDependentAuraMods

        // Skip item specific requirements for not wand magic damage
        return;
    }

    // Magic damage modifiers implemented in Unit::SpellDamageBonusDone
    // This information for client side use only
    if (target->GetTypeId() == TYPEID_PLAYER)
    {
        if (m_positive)
        {
            for (int i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
            {
                if ((m_modifier.m_miscvalue & (1 << i)) != 0)
                    target->ApplyModUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS + i, m_modifier.m_amount, apply);
            }
        }
        else
        {
            for (int i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
            {
                if ((m_modifier.m_miscvalue & (1 << i)) != 0)
                    target->ApplyModUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_NEG + i, m_modifier.m_amount, apply);
            }
        }
        Pet* pet = target->GetPet();
        if (pet)
            pet->UpdateAttackPowerAndDamage();
    }
}

void Aura::HandleModDamagePercentDone(bool apply, bool Real)
{
    DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "AURA MOD DAMAGE type:%u negative:%u", m_modifier.m_miscvalue, m_positive ? 0 : 1);
    Unit* target = GetTarget();

    // apply item specific bonuses for already equipped weapon
    if (Real && target->GetTypeId() == TYPEID_PLAYER)
    {
        for (int i = 0; i < MAX_ATTACK; ++i)
            if (Item* pItem = ((Player*)target)->GetWeaponForAttack(WeaponAttackType(i), true, false))
                ((Player*)target)->_ApplyWeaponDependentAuraDamageMod(pItem, WeaponAttackType(i), this, apply);
    }

    // m_modifier.m_miscvalue is bitmask of spell schools
    // 1 ( 0-bit ) - normal school damage (SPELL_SCHOOL_MASK_NORMAL)
    // 126 - full bitmask all magic damages (SPELL_SCHOOL_MASK_MAGIC) including wand
    // 127 - full bitmask any damages
    //
    // mods must be applied base at equipped weapon class and subclass comparison
    // with spell->EquippedItemClass and  EquippedItemSubClassMask and EquippedItemInventoryTypeMask
    // m_modifier.m_miscvalue comparison with item generated damage types

    if ((m_modifier.m_miscvalue & SPELL_SCHOOL_MASK_NORMAL) != 0)
    {
        // apply generic physical damage bonuses including wand case
        if (GetSpellProto()->EquippedItemClass == -1 || target->GetTypeId() != TYPEID_PLAYER)
        {
            target->HandleStatModifier(UNIT_MOD_DAMAGE_MAINHAND, TOTAL_PCT, m_modifier.m_amount, apply);
            target->HandleStatModifier(UNIT_MOD_DAMAGE_OFFHAND, TOTAL_PCT, m_modifier.m_amount, apply);
            target->HandleStatModifier(UNIT_MOD_DAMAGE_RANGED, TOTAL_PCT, m_modifier.m_amount, apply);

            // For show in client
            if (target->GetTypeId() == TYPEID_PLAYER)
                target->ApplyModSignedFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT, m_modifier.m_amount / 100.0f, apply);
        }
        else
        {
            // done in Player::_ApplyWeaponDependentAuraMods
        }
    }

    // Skip non magic case for speedup
    if ((m_modifier.m_miscvalue & SPELL_SCHOOL_MASK_MAGIC) == 0)
        return;

    if (GetSpellProto()->EquippedItemClass != -1 || GetSpellProto()->EquippedItemInventoryTypeMask != 0)
    {
        // wand magic case (skip generic to all item spell bonuses)
        // done in Player::_ApplyWeaponDependentAuraMods

        // Skip item specific requirements for not wand magic damage
        return;
    }

    // Magic damage percent modifiers implemented in Unit::SpellDamageBonusDone
    // Send info to client
    if (target->GetTypeId() == TYPEID_PLAYER)
        for (int i = SPELL_SCHOOL_HOLY; i < MAX_SPELL_SCHOOL; ++i)
            target->ApplyModSignedFloatValue(PLAYER_FIELD_MOD_DAMAGE_DONE_PCT + i, m_modifier.m_amount / 100.0f, apply);
}

void Aura::HandleModOffhandDamagePercent(bool apply, bool Real)
{
    // spells required only Real aura add/remove
    if (!Real)
        return;

    DEBUG_FILTER_LOG(LOG_FILTER_SPELL_CAST, "AURA MOD OFFHAND DAMAGE");

    GetTarget()->HandleStatModifier(UNIT_MOD_DAMAGE_OFFHAND, TOTAL_PCT, m_modifier.m_amount, apply);
}

/********************************/
/***        POWER COST        ***/
/********************************/

void Aura::HandleModPowerCostPCT(bool apply, bool Real)
{
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_6_1
    // spells required only Real aura add/remove
    if (!Real)
        return;

    float amount = m_modifier.m_amount / 100.0f;
    for (int i = 0; i < MAX_SPELL_SCHOOL; ++i)
        if (m_modifier.m_miscvalue & (1 << i))
            GetTarget()->ApplyModSignedFloatValue(UNIT_FIELD_POWER_COST_MULTIPLIER + i, amount, apply);
#endif
}

void Aura::HandleModPowerCost(bool apply, bool Real)
{
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_6_1
    // spells required only Real aura add/remove
    if (!Real)
        return;

    for (int i = 0; i < MAX_SPELL_SCHOOL; ++i)
        if (m_modifier.m_miscvalue & (1 << i))
            GetTarget()->ApplyModInt32Value(UNIT_FIELD_POWER_COST_MODIFIER + i, m_modifier.m_amount, apply);
#endif
}

/*********************************************************/
/***                    OTHERS                         ***/
/*********************************************************/

void Aura::HandleReflectSpellsSchool(bool apply, bool Real)
{
    // all applied/removed only at real aura add/remove
    if (!Real)
        return;

    if (Unit* pCaster = GetCaster())
        if (Player* modOwner = pCaster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetId(), SPELLMOD_RESIST_MISS_CHANCE, m_modifier.m_amount);
}

void Aura::HandleShapeshiftBoosts(bool apply)
{
    uint32 spellId1 = 0;
    uint32 spellId2 = 0;
    uint32 HotWSpellId = 0;

    ShapeshiftForm form = ShapeshiftForm(GetModifier()->m_miscvalue);

    Unit* target = GetTarget();

    switch (form)
    {
        case FORM_CAT:
            spellId1 = 3025;
            HotWSpellId = 24900;
            break;
        case FORM_TREE:
            spellId1 = 5420;
            break;
        case FORM_TRAVEL:
            spellId1 = 5419;
            break;
        case FORM_AQUA:
            spellId1 = 5421;
            break;
        case FORM_BEAR:
            spellId1 = 1178;
            spellId2 = 21178;
            HotWSpellId = 24899;
            break;
        case FORM_DIREBEAR:
            spellId1 = 9635;
            spellId2 = 21178;
            HotWSpellId = 24899;
            break;
        case FORM_BATTLESTANCE:
            spellId1 = 21156;
            break;
        case FORM_DEFENSIVESTANCE:
            spellId1 = 7376;
            break;
        case FORM_BERSERKERSTANCE:
            spellId1 = 7381;
            break;
        case FORM_MOONKIN:
            spellId1 = 24905;
            break;
        case FORM_SPIRITOFREDEMPTION:
            spellId1 = 27792;
            spellId2 = 27795;                               // must be second, this important at aura remove to prevent to early iterator invalidation.
            break;
        case FORM_GHOSTWOLF:
        case FORM_AMBIENT:
        case FORM_GHOUL:
        case FORM_SHADOW:
        case FORM_STEALTH:
        case FORM_CREATURECAT:
        case FORM_CREATUREBEAR:
            break;
    }

    if (apply)
    {
        if (spellId1)
            target->AddAura(spellId1, 0, target);
        if (spellId2)
            target->AddAura(spellId2, 0, target);

        if (target->GetTypeId() == TYPEID_PLAYER)
        {
            PlayerSpellMap const& sp_list = ((Player*)target)->GetSpellMap();
            for (const auto& itr : sp_list)
            {
                if (itr.second.state == PLAYERSPELL_REMOVED) continue;
                if (itr.first == spellId1 || itr.first == spellId2) continue;
                SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(itr.first);
                if (!spellInfo || !spellInfo->IsNeedCastSpellAtFormApply(form))
                    continue;
                target->CastSpell(target, itr.first, true, nullptr, this);
            }

            // Leader of the Pack
            if (((Player*)target)->HasSpell(17007))
            {
                SpellEntry const* spellInfo = sSpellMgr.GetSpellEntry(24932);
                if (spellInfo && spellInfo->Stances & (1 << (form - 1)))
                    target->CastSpell(target, 24932, true, nullptr, this);
            }
            break;
    }
}

            // Heart of the Wild
            if (HotWSpellId)
            {
                Unit::AuraList const& mModTotalStatPct = target->GetAurasByType(SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE);
                for (const auto i : mModTotalStatPct)
                {
                    if (i->GetSpellProto()->SpellIconID == 240 && i->GetModifier()->m_miscvalue == 3)
                    {
                        int32 HotWMod = i->GetModifier()->m_amount;
                        target->CastCustomSpell(target, HotWSpellId, HotWMod, {}, {}, true, nullptr, this);
                        break;
                    }
                }
            }
        }
    }
    else
    {
        if (spellId1)
            target->RemoveAurasDueToSpell(spellId1);
        if (spellId2)
            target->RemoveAurasDueToSpell(spellId2);

bool Aura::CanBeAppliedOn(Unit* target)
{
    for (uint32 label : GetSpellInfo()->Labels)
        if (target->HasAuraTypeWithMiscvalue(SPELL_AURA_SUPPRESS_ITEM_PASSIVE_EFFECT_BY_SPELL_LABEL, label))
            return false;

    // unit not in world or during remove from world
    if (!target->IsInWorld() || target->IsDuringRemoveFromWorld())
    {
        // area auras mustn't be applied
        if (GetOwner() != target)
            return false;
        // do not apply non-selfcast single target auras
        if (GetCasterGUID() != GetOwner()->GetGUID() && GetSpellInfo()->IsSingleTarget())
            return false;
        return true;
    }
    else
        return CheckAreaTarget(target);
}
        Unit::SpellAuraHolderMap& tAuras = target->GetSpellAuraHolderMap();
        for (Unit::SpellAuraHolderMap::iterator itr = tAuras.begin(); itr != tAuras.end();)
        {
            if (itr->second->IsRemovedOnShapeLost())
            {
                target->RemoveAurasDueToSpell(itr->second->GetId());
                itr = tAuras.begin();
            }
            else
                ++itr;
        }

        // Interrupt current shape specific spells
        for (uint32 i = CURRENT_MELEE_SPELL; i < CURRENT_MAX_SPELL; ++i)
            if (Spell* spell = target->GetCurrentSpell(CurrentSpellTypes(i)))
                if (spell->m_spellInfo->IsRemovedOnShapeLostSpell())
                    target->InterruptSpell(CurrentSpellTypes(i), false);
    }
}

void Aura::HandleAuraEmpathy(bool apply, bool /*Real*/)
{
    Unit* target = GetTarget();
    if (target->GetTypeId() != TYPEID_UNIT)
        return;

    CreatureInfo const* ci = ObjectMgr::GetCreatureTemplate(target->GetEntry());
    if (ci && ci->type == CREATURE_TYPE_BEAST)
        target->ApplyModUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_SPECIALINFO, apply);

    if (apply)
    {
        if (Player* pPlayerCaster = ToPlayer(GetCaster()))
        {
            UpdateMask updateMask;
            updateMask.SetCount(target->GetValuesCount());
            updateMask.SetBit(UNIT_FIELD_HEALTH);
            updateMask.SetBit(UNIT_FIELD_MAXHEALTH);
            target->MarkUpdateFieldsWithFlagForUpdate(updateMask, UF_FLAG_SPECIAL_INFO);

            UpdateData newData;
            target->BuildValuesUpdateBlockForPlayer(newData, updateMask, pPlayerCaster);

            if (newData.HasData())
            {
                WorldPacket newDataPacket;
                newData.BuildPacket(&newDataPacket);
                pPlayerCaster->SendDirectMessage(&newDataPacket);
            }
        }
    }
}

void Aura::HandleAuraUntrackable(bool apply, bool /*Real*/)
{
    if (apply)
        GetTarget()->SetByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, UNIT_VIS_FLAGS_UNTRACKABLE);
    else
        GetTarget()->RemoveByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, UNIT_VIS_FLAGS_UNTRACKABLE);
}

    bool sameCaster = GetCasterGUID() == existingAura->GetCasterGUID();
    SpellInfo const* existingSpellInfo = existingAura->GetSpellInfo();

    // Dynobj auras do not stack when they come from the same spell cast by the same caster
    if (GetType() == DYNOBJ_AURA_TYPE || existingAura->GetType() == DYNOBJ_AURA_TYPE)
    {
        if (sameCaster && m_spellInfo->Id == existingSpellInfo->Id)
            return false;
        return true;
    }
void Aura::HandleAuraModPacify(bool apply, bool /*Real*/)
{
    if (apply)
        GetTarget()->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
    else
        GetTarget()->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED);
}

void Aura::HandleAuraModPacifyAndSilence(bool apply, bool Real)
{
    HandleAuraModPacify(apply, Real);
    HandleAuraModSilence(apply, Real);
}

void Aura::HandleAuraGhost(bool apply, bool /*Real*/)
{
    Unit* pTarget = GetTarget();
    Player* pPlayer = pTarget->ToPlayer();

    for (SpellEffectInfo const& spellEffectInfo : existingSpellInfo->GetEffects())
    if (apply)
    {
        // prevent remove triggering aura by triggered aura
        if (spellEffectInfo.TriggerSpell == GetId())
            return true;
        GetTarget()->SetByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, UNIT_VIS_FLAGS_GHOST);
        if (pPlayer)
            GetTarget()->SetFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST);
    }
    else
    {
        GetTarget()->RemoveByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_VIS_FLAG, UNIT_VIS_FLAGS_GHOST);
        if (pPlayer)
            GetTarget()->RemoveFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST);
    }

    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
    {
        // prevent remove triggered aura by triggering aura refresh
        if (spellEffectInfo.TriggerSpell == existingAura->GetId())
            return true;
    }
    if (pPlayer && pPlayer->GetGroup())
        pPlayer->SetGroupUpdateFlag(GROUP_UPDATE_FLAG_STATUS);
}

void Aura::HandleShieldBlockValue(bool apply, bool /*Real*/)
{
    BaseModType modType = FLAT_MOD;
    if (m_modifier.m_auraname == SPELL_AURA_MOD_SHIELD_BLOCKVALUE_PCT)
        modType = PCT_MOD;

    if (GetTarget()->GetTypeId() == TYPEID_PLAYER)
        ((Player*)GetTarget())->HandleBaseModValue(SHIELD_BLOCK_VALUE, modType, m_modifier.m_amount, apply);
}

    // check spell specific stack rules
    if (m_spellInfo->IsAuraExclusiveBySpecificWith(existingSpellInfo)
        || (sameCaster && m_spellInfo->IsAuraExclusiveBySpecificPerCasterWith(existingSpellInfo)))
        return false;
void Aura::HandleAuraRetainComboPoints(bool apply, bool Real)
{
    // spells required only Real aura add/remove
    if (!Real)
        return;

    if (GetTarget()->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* target = (Player*)GetTarget();

    // combo points was added in SPELL_EFFECT_ADD_COMBO_POINTS handler
    // remove only if aura expire by time (in case combo points amount change aura removed without combo points lost)
    if (!apply && m_removeMode == AURA_REMOVE_BY_EXPIRE && target->GetComboTargetGuid())
        if (Unit* unit = ObjectAccessor::GetUnit(*GetTarget(), target->GetComboTargetGuid()))
            target->AddComboPoints(unit, -m_modifier.m_amount);
}

void Aura::HandleModUnattackable(bool Apply, bool Real)
{
    if (Real && Apply)
    {
        GetTarget()->CombatStop();
        GetTarget()->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_IMMUNE_OR_LOST_SELECTION);
    }
    GetTarget()->ApplyModFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE_2, Apply);
}

void Aura::HandleSpiritOfRedemption(bool apply, bool Real)
{
    // spells required only Real aura add/remove
    if (!Real)
        return;

    Unit* target = GetTarget();

    // prepare spirit state
    if (apply)
    {
        if (target->GetTypeId() == TYPEID_PLAYER)
        {
            // set stand state (expected in this form)
            if (!target->IsStandingUp())
                target->SetStandState(UNIT_STAND_STATE_STAND);
        }

        if (m_spellInfo->HasAttribute(SPELL_ATTR3_DOT_STACKING_RULE))
            return true;
        target->SetHealth(1);
    }
    // die at aura end
    else
        target->DealDamage(target, target->GetHealth(), nullptr, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, GetSpellProto(), false);
}

        // check same periodic auras
        auto hasPeriodicNonAreaEffect = [](SpellInfo const* spellInfo)
        {
            for (SpellEffectInfo const& spellEffectInfo : spellInfo->GetEffects())
            {
                switch (spellEffectInfo.ApplyAuraName)
                {
                    // DOT or HOT from different casters will stack
                    case SPELL_AURA_PERIODIC_DAMAGE:
                    case SPELL_AURA_PERIODIC_WEAPON_PERCENT_DAMAGE:
                    case SPELL_AURA_PERIODIC_DUMMY:
                    case SPELL_AURA_PERIODIC_HEAL:
                    case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
                    case SPELL_AURA_PERIODIC_ENERGIZE:
                    case SPELL_AURA_PERIODIC_MANA_LEECH:
                    case SPELL_AURA_PERIODIC_LEECH:
                    case SPELL_AURA_POWER_BURN:
                    case SPELL_AURA_OBS_MOD_POWER:
                    case SPELL_AURA_OBS_MOD_HEALTH:
                    case SPELL_AURA_PERIODIC_TRIGGER_SPELL_WITH_VALUE:
                    case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
                        // periodic auras which target areas are not allowed to stack this way (replenishment for example)
                        if (spellEffectInfo.IsTargetingArea())
                            return false;
                        return true;
                    default:
                        break;
                }
            }
            return false;
        };

        if (hasPeriodicNonAreaEffect(m_spellInfo) && hasPeriodicNonAreaEffect(existingSpellInfo))
            return true;
    }
void Aura::HandleAuraAoeCharm(bool apply, bool real)
{
    if (!real)
        return;
    if (GetSpellProto()->Id == 28410) // Chains of Kel'Thuzad
    {
        HandleModCharm(apply, real);
    }
}

void Aura::HandleSchoolAbsorb(bool apply, bool Real)
{
    if (!Real)
        return;

    Unit* caster = GetCaster();
    if (!caster)
        return;

    Unit* target = GetTarget();
    SpellEntry const* spellProto = GetSpellProto();
    if (apply)
    {
        // prevent double apply bonuses
        if (target->GetTypeId() != TYPEID_PLAYER || !((Player*)target)->GetSession()->PlayerLoading())
        {
            float DoneActualBenefit = 0.0f;
            switch (spellProto->SpellFamilyName)
            {
                case SPELLFAMILY_PRIEST:
                    // Power Word: Shield
                    if (spellProto->IsFitToFamilyMask<CF_PRIEST_POWER_WORD_SHIELD>())
                    {
                        //+10% from +healing bonus
                        DoneActualBenefit = caster->SpellBaseHealingBonusDone(spellProto->GetSpellSchoolMask()) * 0.1f;
                        break;
                    }
                    break;
                case SPELLFAMILY_MAGE:
                    // Frost ward, Fire ward
                    if (spellProto->IsFitToFamilyMask<CF_MAGE_FIRE_WARD, CF_MAGE_FROST_WARD>())
                    {
                        //+10% from +spd bonus
                        DoneActualBenefit = caster->SpellBaseDamageBonusDone(spellProto->GetSpellSchoolMask()) * 0.1f;
                        break;
                    }
                    break;
                case SPELLFAMILY_WARLOCK:
                    // Shadow Ward
                    if (spellProto->SpellIconID == 207 && spellProto->Category == 56)
                    {
                        //+10% from +spd bonus
                        DoneActualBenefit = caster->SpellBaseDamageBonusDone(spellProto->GetSpellSchoolMask()) * 0.1f;
                        break;
                    }
                    break;
                default:
                    break;
            }

            DoneActualBenefit *= caster->CalculateLevelPenalty(GetSpellProto());

            m_modifier.m_amount += DoneActualBenefit;

            // Power Word: Shield generates half the threat as healing for the same amount
            if (spellProto->IsFitToFamily<SPELLFAMILY_PRIEST, CF_PRIEST_POWER_WORD_SHIELD>() && spellProto->Id != 27779)
                caster->GetHostileRefManager().threatAssist(caster, m_modifier.m_amount * 0.25, spellProto);

            m_modifier.m_amount = dither(m_modifier.m_amount);
        }
    }
}

void Aura::PeriodicTick(SpellEntry const* sProto, AuraType auraType, uint32 data)
{
    Unit* target = GetTarget();
    SpellEntry const* spellProto = sProto ? sProto : GetSpellProto();
    AuraType const aura_type = sProto ? auraType : m_modifier.m_auraname;

    switch (aura_type)
    {
        case SPELL_AURA_PERIODIC_DAMAGE:
        case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
        {
            // don't damage target if not alive, possible death persistent effects
            if (!target->IsAlive())
                return;

            Unit* pCaster = GetCaster();
            if (!pCaster)
                return;

            if (spellProto->Effect[GetEffIndex()] == SPELL_EFFECT_PERSISTENT_AREA_AURA &&
                pCaster->SpellHitResult(target, spellProto, GetEffIndex(), false) != SPELL_MISS_NONE)
                return;

            // Check for immune (not use charges)
            if (!spellProto->HasAttribute(SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY)) // confirmed Impaling spine goes through immunity
            {
                if (target->IsImmuneToDamage(spellProto->GetSpellSchoolMask(), spellProto))
                {
                    pCaster->SendSpellOrDamageImmune(target, spellProto->Id);
                    return;
                }
            }

            uint32 absorb = 0;
            int32 resist = 0;
            float fdamage;
            CleanDamage cleanDamage = CleanDamage(0, BASE_ATTACK, MELEE_HIT_NORMAL, 0, 0);

            if (sProto)
            {
                if (auraType == SPELL_AURA_PERIODIC_DAMAGE)
                    fdamage = data;
                else
                    fdamage = target->GetMaxHealth() * data / 100;
            }
            else
            {
                if (m_modifier.m_auraname == SPELL_AURA_PERIODIC_DAMAGE)
#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_9_4
                    fdamage = (m_modifier.m_amount > 0 ? m_modifier.m_amount : 0);
#else
                    fdamage = CalculateDotDamage();
#endif
                else
                    fdamage = target->GetMaxHealth() * (m_modifier.m_amount > 0 ? m_modifier.m_amount : 0) / 100;
            }

            // Consecration: recalculate the damage on each tick
            if (spellProto->IsFitToFamily<SPELLFAMILY_PALADIN, CF_PALADIN_CONSECRATION>())
                fdamage = pCaster->SpellDamageBonusDone(target, GetSpellProto(), GetEffIndex(), m_currentBasePoints, DOT, GetStackAmount());

bool Aura::IsProcOnCooldown(TimePoint now) const
{
    return m_procCooldown > now;
}
            // SpellDamageBonus for magic spells
            if (spellProto->DmgClass == SPELL_DAMAGE_CLASS_NONE || spellProto->DmgClass == SPELL_DAMAGE_CLASS_MAGIC)
                fdamage = target->SpellDamageBonusTaken(pCaster, spellProto, GetEffIndex(), fdamage, DOT, GetStackAmount());
            // MeleeDamagebonus for weapon based spells
            else
            {
                WeaponAttackType attackType = spellProto->GetWeaponAttackType();
                fdamage = target->MeleeDamageBonusTaken(pCaster, fdamage, attackType, spellProto, GetEffIndex(), DOT, GetStackAmount());
            }

void Aura::AddProcCooldown(SpellProcEntry const* procEntry, TimePoint now)
{
    // cooldowns should be added to the whole aura (see 51698 area aura)
    int32 procCooldown = procEntry->Cooldown.count();
    if (Unit* caster = GetCaster())
        if (Player* modOwner = caster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetSpellInfo(), SpellModOp::ProcCooldown, procCooldown);

    m_procCooldown = now + Milliseconds(procCooldown);
}

void Aura::ResetProcCooldown()
{
    m_procCooldown = GameTime::Now();
}
            // Curse of Agony damage-per-tick calculation
            if (spellProto->IsFitToFamily<SPELLFAMILY_WARLOCK, CF_WARLOCK_CURSE_OF_AGONY>())
                fdamage += ( -1 + ((int)GetAuraTicks() -1)/4) * (spellProto->CalculateSimpleValue(EFFECT_INDEX_0)/2.0);

            // Starshards damage-per-tick calculation
            if (spellProto->IsFitToFamily<SPELLFAMILY_PRIEST, CF_PRIEST_STARSHARDS>())
                fdamage += ( -1 + ((int)GetAuraTicks() -1)/2) * (spellProto->CalculateSimpleValue(EFFECT_INDEX_0)/3.0);

            uint32 pdamage = ditheru(std::max(fdamage, 0.f)); // prevent negative damage due to sickness

            // Calculate armor mitigation if it is a physical spell
            // But not for bleed mechanic spells
            if (spellProto->GetSpellSchoolMask() & SPELL_SCHOOL_MASK_NORMAL && spellProto->GetEffectMechanic(m_effIndex) != MECHANIC_BLEED && !(spellProto->Custom & SPELL_CUSTOM_IGNORE_ARMOR))
            {
                uint32 pdamageReductedArmor = ditheru(pCaster->CalcArmorReducedDamage(target, pdamage));
                cleanDamage.damage += pdamage - pdamageReductedArmor;
                pdamage = pdamageReductedArmor;
            }

void Aura::PrepareProcToTrigger(AuraApplication* aurApp, ProcEventInfo& eventInfo, TimePoint now)
{
    bool prepare = CallScriptPrepareProcHandlers(aurApp, eventInfo);
    if (!prepare)
        return;
            target->CalculateDamageAbsorbAndResist(pCaster, spellProto->GetSpellSchoolMask(), DOT, pdamage, &absorb, &resist, spellProto);

            DETAIL_FILTER_LOG(LOG_FILTER_PERIODIC_AFFECTS, "PeriodicTick: %s attacked %s for %u dmg inflicted by %u",
                              GetCasterGuid().GetString().c_str(), target->GetGuidStr().c_str(), pdamage, GetId());

            pCaster->DealDamageMods(target, pdamage, &absorb);

            // Set trigger flag
            uint32 procAttacker = PROC_FLAG_ON_DO_PERIODIC;
            uint32 procVictim   = PROC_FLAG_ON_TAKE_PERIODIC;

            uint32 const bonus = (resist < 0 ? uint32(std::abs(resist)) : 0);
            pdamage += bonus;
            uint32 const malus = (resist > 0 ? (absorb + uint32(resist)) : absorb);
            pdamage = (pdamage <= malus ? 0 : (pdamage - malus));

            SpellPeriodicAuraLogInfo pInfo(this, pdamage, absorb, resist, 0.0f);
            target->SendPeriodicAuraLog(&pInfo, sProto ? auraType : SPELL_AURA_NONE);

            if (pdamage)
                procVictim |= PROC_FLAG_TAKEN_ANY_DAMAGE;

            pCaster->ProcDamageAndSpell(ProcSystemArguments(target, procAttacker, procVictim, PROC_EX_NORMAL_HIT, pdamage, BASE_ATTACK, spellProto));

            cleanDamage.absorb = absorb;
            cleanDamage.resist = resist;
            pCaster->DealDamage(target, pdamage, &cleanDamage, DOT, spellProto->GetSpellSchoolMask(), spellProto, true);
            // Curse of Doom: If the target dies from this damage, there is a chance that a Doomguard will be summoned.
            if (spellProto->Id == 603 && !target->IsAlive() && !urand(0, 9))
                pCaster->CastSpell(pCaster, 18662, true);
            break;
        }
        case SPELL_AURA_PERIODIC_LEECH:
        case SPELL_AURA_PERIODIC_HEALTH_FUNNEL:
        {
            // don't damage target if not alive, possible death persistent effects
            if (!target->IsInWorld() || !target->IsAlive())
                return;

            Unit* pCaster = GetCaster();
            if (!pCaster)
                return;

            if (!pCaster->IsInWorld() || !pCaster->IsAlive())
                return;

            if (spellProto->Effect[GetEffIndex()] == SPELL_EFFECT_PERSISTENT_AREA_AURA &&
                    pCaster->SpellHitResult(target, spellProto, GetEffIndex(), false) != SPELL_MISS_NONE)
                return;

    PrepareProcChargeDrop(procEntry, eventInfo);

    // cooldowns should be added to the whole aura (see 51698 area aura)
    AddProcCooldown(procEntry, now);

    SetLastProcSuccessTime(now);
}

void Aura::PrepareProcChargeDrop(SpellProcEntry const* procEntry, ProcEventInfo const& eventInfo)
{
    // take one charge, aura expiration will be handled in Aura::TriggerProcOnEvent (if needed)
    if (!(procEntry->AttributesMask & PROC_ATTR_USE_STACKS_FOR_CHARGES) && IsUsingCharges() && (!eventInfo.GetSpellInfo() || !eventInfo.GetSpellInfo()->HasAttribute(SPELL_ATTR6_DO_NOT_CONSUME_RESOURCES)))
    {
        --m_procCharges;
        SetNeedClientUpdateForTargets();
    }
}
            // Check for immune
            if (!spellProto->HasAttribute(SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY))
            {
                if (target->IsImmuneToDamage(spellProto->GetSpellSchoolMask(), spellProto))
                {
                    pCaster->SendSpellOrDamageImmune(target, spellProto->Id);
                    return;
                }
            }

void Aura::ConsumeProcCharges(SpellProcEntry const* procEntry)
{
    // Remove aura if we've used last charge to proc
    if (procEntry->AttributesMask & PROC_ATTR_USE_STACKS_FOR_CHARGES)
    {
        ModStackAmount(-1);
    }
    else if (IsUsingCharges())
    {
        if (!GetCharges())
            Remove();
    }
}
            uint32 absorb = 0;
            int32 resist = 0;
            CleanDamage cleanDamage =  CleanDamage(0, BASE_ATTACK, MELEE_HIT_NORMAL, 0, 0);

            uint32 pdamage = ditheru(m_modifier.m_amount > 0 ? m_modifier.m_amount : 0);

            //Calculate armor mitigation if it is a physical spell
            if (spellProto->GetSpellSchoolMask() & SPELL_SCHOOL_MASK_NORMAL)
            {
                uint32 pdamageReductedArmor = ditheru(pCaster->CalcArmorReducedDamage(target, pdamage));
                cleanDamage.damage += pdamage - pdamageReductedArmor;
                pdamage = pdamageReductedArmor;
            }

uint32 Aura::GetProcEffectMask(AuraApplication* aurApp, ProcEventInfo& eventInfo, TimePoint now) const
{
    SpellProcEntry const* procEntry = sSpellMgr->GetSpellProcEntry(GetSpellInfo());
    // only auras with spell proc entry can trigger proc
    if (!procEntry)
        return 0;
            pdamage = target->SpellDamageBonusTaken(pCaster, spellProto, GetEffIndex(), pdamage, DOT, GetStackAmount());

            target->CalculateDamageAbsorbAndResist(pCaster, spellProto->GetSpellSchoolMask(), DOT, pdamage, &absorb, &resist, spellProto);

            DETAIL_FILTER_LOG(LOG_FILTER_PERIODIC_AFFECTS, "PeriodicTick: %s health leech of %s for %u dmg inflicted by %u abs is %u",
                              GetCasterGuid().GetString().c_str(), target->GetGuidStr().c_str(), pdamage, GetId(), absorb);

            pCaster->DealDamageMods(target, pdamage, &absorb);

            pCaster->SendSpellNonMeleeDamageLog(target, GetId(), pdamage, spellProto->GetSpellSchoolMask(), absorb, resist, true, 0);

            float multiplier = spellProto->EffectMultipleValue[GetEffIndex()] > 0 ? spellProto->EffectMultipleValue[GetEffIndex()] : 1;

            // Set trigger flag
            uint32 procAttacker = PROC_FLAG_ON_DO_PERIODIC;
            uint32 procVictim   = PROC_FLAG_ON_TAKE_PERIODIC;

            uint32 const bonus = (resist < 0 ? uint32(std::abs(resist)) : 0);
            pdamage += bonus;
            uint32 const malus = (resist > 0 ? (absorb + uint32(resist)) : absorb);
            pdamage = (pdamage <= malus ? 0 : (pdamage - malus));

            pdamage = std::min(pdamage, target->GetHealth());

            if (pdamage)
                procVictim |= PROC_FLAG_TAKEN_ANY_DAMAGE;

            cleanDamage.absorb = absorb;
            cleanDamage.resist = resist;

            pCaster->ProcDamageAndSpell(ProcSystemArguments(target, procAttacker, procVictim, PROC_EX_NORMAL_HIT, pdamage, BASE_ATTACK, spellProto));
            int32 new_damage = pCaster->DealDamage(target, pdamage, &cleanDamage, DOT, spellProto->GetSpellSchoolMask(), spellProto, false);

            if (!target->IsAlive() && pCaster->IsNonMeleeSpellCasted(false))
                for (uint32 i = CURRENT_FIRST_NON_MELEE_SPELL; i < CURRENT_MAX_SPELL; ++i)
                    if (Spell* spell = pCaster->GetCurrentSpell(CurrentSpellTypes(i)))
                        if (spell->m_spellInfo->Id == GetId())
                            spell->cancel();

            if (Player* modOwner = pCaster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetId(), SPELLMOD_MULTIPLE_VALUE, multiplier);

            uint32 heal = int32(new_damage * multiplier);

            int32 gain = pCaster->DealHeal(pCaster, heal, spellProto);
            pCaster->GetHostileRefManager().threatAssist(pCaster, gain * 0.5f * sSpellMgr.GetSpellThreatMultiplier(spellProto), spellProto);
            break;
        }
        case SPELL_AURA_PERIODIC_HEAL:
        case SPELL_AURA_OBS_MOD_HEALTH:
        {
            // don't heal target if not alive, mostly death persistent effects from items
            if (!target->IsAlive())
                return;

            Unit* pCaster = GetCaster();
            if (!pCaster)
                return;

            // Don't heal target if it is already at max health. We still need
            // to do procs on the tick, however
            if (target->GetHealth() == target->GetMaxHealth())
            {
                uint32 procAttacker = PROC_FLAG_ON_DO_PERIODIC;
                uint32 procVictim = PROC_FLAG_ON_TAKE_PERIODIC;
                uint32 procEx = PROC_EX_NORMAL_HIT | PROC_EX_PERIODIC_POSITIVE;
                pCaster->ProcDamageAndSpell(ProcSystemArguments(target, procAttacker, procVictim, procEx, 1, BASE_ATTACK, spellProto));

        // check if aura can proc when spell is triggered (exception for hunter auto shot & wands)
        if (!GetSpellInfo()->HasAttribute(SPELL_ATTR3_CAN_PROC_FROM_PROCS) && !(procEntry->AttributesMask & PROC_ATTR_TRIGGERED_CAN_PROC) && !(eventInfo.GetTypeMask() & AUTO_ATTACK_PROC_FLAG_MASK))
            if (spell->IsTriggered() && !spell->GetSpellInfo()->HasAttribute(SPELL_ATTR3_NOT_A_PROC))
                return 0;

        if (spell->m_CastItem && (procEntry->AttributesMask & PROC_ATTR_CANT_PROC_FROM_ITEM_CAST))
            return 0;

        if (spell->GetSpellInfo()->HasAttribute(SPELL_ATTR4_SUPPRESS_WEAPON_PROCS) && GetSpellInfo()->HasAttribute(SPELL_ATTR6_AURA_IS_WEAPON_PROC))
            return 0;

        if (GetSpellInfo()->HasAttribute(SPELL_ATTR12_ONLY_PROC_FROM_CLASS_ABILITIES) && !spell->GetSpellInfo()->HasAttribute(SPELL_ATTR13_ALLOW_CLASS_ABILITY_PROCS))
            return 0;
    }
                return;
            }

            // heal for caster damage (must be alive)
            if (target != pCaster && spellProto->SpellVisual == 163 && !pCaster->IsAlive())
                return;

            if (target->IsImmuneToSchool(spellProto, (1 << GetEffIndex())))
            {
                pCaster->SendSpellOrDamageImmune(target, spellProto->Id);
                return;
            }

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_10_2
            // Ignore non positive values (can be result apply spellmods to aura damage).
            float amount = m_modifier.m_amount > 0 ? m_modifier.m_amount : 0;
#else
            // Before 1.11 the heal bonuses were calculated each tick, not upon initial cast.
            float amount;
            if (aura_type == SPELL_AURA_PERIODIC_HEAL)
            {
                float intAmount = pCaster->SpellHealingBonusDone(target, GetSpellProto(), GetEffIndex(), m_modifier.m_amount, DOT, GetStackAmount());
                amount = intAmount > 0 ? intAmount : 0;
            }
            else
                amount = m_modifier.m_amount > 0 ? m_modifier.m_amount : 0;
#endif

            float fdamage;

            if (m_modifier.m_auraname == SPELL_AURA_OBS_MOD_HEALTH)
                fdamage = target->GetMaxHealth() * amount / 100;
            else
                fdamage = amount;

            uint32 pdamage = ditheru(target->SpellHealingBonusTaken(pCaster, spellProto, GetEffIndex(), fdamage, DOT, GetStackAmount()));

            DETAIL_FILTER_LOG(LOG_FILTER_PERIODIC_AFFECTS, "PeriodicTick: %s heal of %s for %u health inflicted by %u",
                              GetCasterGuid().GetString().c_str(), target->GetGuidStr().c_str(), pdamage, GetId());

            int32 gain = target->ModifyHealth(pdamage);
            SpellPeriodicAuraLogInfo pInfo(this, pdamage, 0, 0, 0.0f);
            target->SendPeriodicAuraLog(&pInfo);

            // Set trigger flag
            uint32 procAttacker = PROC_FLAG_ON_DO_PERIODIC;
            uint32 procVictim   = PROC_FLAG_ON_TAKE_PERIODIC;
            uint32 procEx = PROC_EX_NORMAL_HIT | PROC_EX_PERIODIC_POSITIVE;
            pCaster->ProcDamageAndSpell(ProcSystemArguments(target, procAttacker, procVictim, procEx, gain, BASE_ATTACK, spellProto));

    // Check if current equipment meets aura requirements
    // do that only for passive spells
    /// @todo this needs to be unified for all kinds of auras
    Unit* target = aurApp->GetTarget();
    if (IsPassive() && target->GetTypeId() == TYPEID_PLAYER && GetSpellInfo()->EquippedItemClass != -1)
    {
        if (!GetSpellInfo()->HasAttribute(SPELL_ATTR3_NO_PROC_EQUIP_REQUIREMENT))
        {
            Item* item = nullptr;
            if (GetSpellInfo()->EquippedItemClass == ITEM_CLASS_WEAPON)
            {
                if (target->ToPlayer()->IsInFeralForm())
                    return 0;
            target->GetHostileRefManager().threatAssist(pCaster, float(gain) * 0.5f * sSpellMgr.GetSpellThreatMultiplier(spellProto), spellProto);

            // heal for caster damage, warlock's health funnel already cost hps
            if (target != pCaster && spellProto->SpellVisual == 163 &&
                !(spellProto->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                spellProto->IsFitToFamilyMask<CF_WARLOCK_HEALTH_FUNNEL>()))
            {
                uint32 dmg = spellProto->manaPerSecond;
                if (pCaster->GetHealth() <= dmg && pCaster->GetTypeId() == TYPEID_PLAYER)
                {
                    pCaster->RemoveAurasDueToSpell(GetId());

                if (DamageInfo const* damageInfo = eventInfo.GetDamageInfo())
                {
                    if (damageInfo->GetAttackType() != OFF_ATTACK)
                        item = target->ToPlayer()->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);
                    else
                        item = target->ToPlayer()->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
                }
            }
            else if (GetSpellInfo()->EquippedItemClass == ITEM_CLASS_ARMOR)
            {
                // Check if player is wearing shield
                item = target->ToPlayer()->GetUseableItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);
            }

            if (!item || item->IsBroken() || !item->IsFitToSpellRequirements(GetSpellInfo()))
                return 0;
        }
    }
                    // finish current generic/channeling spells, don't affect autorepeat
                    pCaster->FinishSpell(CURRENT_GENERIC_SPELL);
                    pCaster->FinishSpell(CURRENT_CHANNELED_SPELL);
                }
                else
                {
                    uint32 damage = gain;
                    uint32 absorb = 0;
                    pCaster->DealDamageMods(pCaster, damage, &absorb);
                    pCaster->SendSpellNonMeleeDamageLog(pCaster, GetId(), damage, spellProto->GetSpellSchoolMask(), absorb, 0, true, 0, false);

                    CleanDamage cleanDamage =  CleanDamage(0, BASE_ATTACK, MELEE_HIT_NORMAL, absorb, 0);
                    pCaster->DealDamage(pCaster, damage, &cleanDamage, NODAMAGE, spellProto->GetSpellSchoolMask(), spellProto, true);
                }
            }
            break;
        }
        case SPELL_AURA_PERIODIC_MANA_LEECH:
        {
            // don't damage target if not alive, possible death persistent effects
            if (!target->IsAlive())
                return;

            if (m_modifier.m_miscvalue < 0 || m_modifier.m_miscvalue >= MAX_POWERS)
                return;

            Powers power = Powers(m_modifier.m_miscvalue);

            // power type might have changed between aura applying and tick (druid's shapeshift)
            if (target->GetPowerType() != power)
                return;

            Unit* pCaster = GetCaster();
            if (!pCaster)
                return;

            if (!pCaster->IsAlive())
                return;

            if (GetSpellProto()->Effect[GetEffIndex()] == SPELL_EFFECT_PERSISTENT_AREA_AURA &&
                    pCaster->SpellHitResult(target, spellProto, GetEffIndex(), false) != SPELL_MISS_NONE)
                return;

            // Check for immune (not use charges)
            if (!spellProto->HasAttribute(SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY)) // confirmed Impaling spine goes through immunity
            {
                if (target->IsImmuneToDamage(spellProto->GetSpellSchoolMask(), spellProto))
                {
                    pCaster->SendSpellOrDamageImmune(target, spellProto->Id);
                    return;
                }
            }

    if (m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_PROC_OUTDOORS))
        if (!target->IsOutdoors())
            return 0;

    if (m_spellInfo->HasAttribute(SPELL_ATTR3_ONLY_PROC_ON_CASTER))
        if (target->GetGUID() != GetCasterGUID())
            return 0;

    if (!m_spellInfo->HasAttribute(SPELL_ATTR4_ALLOW_PROC_WHILE_SITTING))
        if (!target->IsStandState())
            return 0;

    bool success = roll_chance_f(CalcProcChance(*procEntry, eventInfo));
            // ignore non positive values (can be result apply spellmods to aura damage
            uint32 pdamage = m_modifier.m_amount > 0 ? m_modifier.m_amount : 0;

            DETAIL_FILTER_LOG(LOG_FILTER_PERIODIC_AFFECTS, "PeriodicTick: %s power leech of %s for %u dmg inflicted by %u",
                              GetCasterGuid().GetString().c_str(), target->GetGuidStr().c_str(), pdamage, GetId());

            int32 drain_amount = target->GetPower(power) > pdamage ? pdamage : target->GetPower(power);

            target->ModifyPower(power, -drain_amount);

            float gain_multiplier = 0;

            if (pCaster->GetMaxPower(power) > 0)
            {
                gain_multiplier = spellProto->EffectMultipleValue[GetEffIndex()];

                if (Player* modOwner = pCaster->GetSpellModOwner())
                    modOwner->ApplySpellMod(GetId(), SPELLMOD_MULTIPLE_VALUE, gain_multiplier);
            }

            SpellPeriodicAuraLogInfo pInfo(this, drain_amount, 0, 0, gain_multiplier);
            target->SendPeriodicAuraLog(&pInfo);

            int32 gain_amount = int32(drain_amount * gain_multiplier);

            if (gain_amount)
            {
                float threat = pCaster->ModifyPower(power, gain_amount) * sSpellMgr.GetSpellThreatMultiplier(spellProto);
                threat *= 0.5; // Mana Drain
                target->AddThreat(pCaster, threat, false, spellProto->GetSpellSchoolMask(), spellProto);
            }
            if (target->GetPower(power) == 0)
            {
                if (spellProto->Id == 21056) //Marque de Kazzak
                {
                    // Explose quand y'a plus de mana a drainer
                    target->CastSpell(target, 21058, true);
                    GetHolder()->SetAuraDuration(0);
                }
            }

            // Improved Drain Mana
            auto improvedManaDrain1 = pCaster->GetAura(17864, EFFECT_INDEX_0);
            auto improvedManaDrain2 = pCaster->GetAura(18393, EFFECT_INDEX_0);

            if (improvedManaDrain2)
                PeriodicTick(improvedManaDrain2->GetHolder()->GetSpellProto(), SPELL_AURA_PERIODIC_DAMAGE, drain_amount * 0.3f);
            else if (improvedManaDrain1)
                PeriodicTick(improvedManaDrain1->GetHolder()->GetSpellProto(), SPELL_AURA_PERIODIC_DAMAGE, drain_amount * 0.15f);

            // Nostalrius: break des controles type 'AURA_INTERRUPT_FLAG_DAMAGE'
            target->RemoveAurasWithInterruptFlags(AURA_INTERRUPT_FLAG_DAMAGE);
            break;
        }
        case SPELL_AURA_PERIODIC_ENERGIZE:
        {
            // don't energize target if not alive, possible death persistent effects
            if (!target->IsAlive())
                return;

    // proc chance is reduced by an additional 3.333% per level past 60
    if ((procEntry.AttributesMask & PROC_ATTR_REDUCE_PROC_60) && eventInfo.GetActor()->GetLevel() > 60)
        chance = std::max(0.f, (1.f - ((eventInfo.GetActor()->GetLevel() - 60) * 1.f / 30.f)) * chance);
            Unit* pCaster = GetCaster();

            if (pCaster)
            {
                if (target->IsImmuneToSchool(spellProto, (1 << GetEffIndex())))
                {
                    pCaster->SendSpellOrDamageImmune(target, spellProto->Id);
                    return;
                }
            }

            // ignore non positive values (can be result apply spellmods to aura damage
            uint32 pdamage = ditheru(m_modifier.m_amount > 0 ? m_modifier.m_amount : 0);

            DETAIL_FILTER_LOG(LOG_FILTER_PERIODIC_AFFECTS, "PeriodicTick: %s energize %s for %u dmg inflicted by %u",
                              GetCasterGuid().GetString().c_str(), target->GetGuidStr().c_str(), pdamage, GetId());

            if (m_modifier.m_miscvalue < 0 || m_modifier.m_miscvalue >= MAX_POWERS)
                break;

            Powers power = Powers(m_modifier.m_miscvalue);

            if (target->GetMaxPower(power) == 0)
                break;

            SpellPeriodicAuraLogInfo pInfo(this, pdamage, 0, 0, 0.0f);
            target->SendPeriodicAuraLog(&pInfo);

            int32 gain = target->ModifyPower(power, pdamage);

#if SUPPORTED_CLIENT_BUILD > CLIENT_BUILD_1_8_4
            if (power != POWER_MANA)     // 1.9 - Mana regeneration over time will no longer generate threat.
#endif
                if (pCaster)
                    target->GetHostileRefManager().threatAssist(pCaster, float(gain) * 0.5f * sSpellMgr.GetSpellThreatMultiplier(spellProto), spellProto);
            break;
        }
        case SPELL_AURA_OBS_MOD_MANA:
        {
            // don't energize target if not alive, possible death persistent effects
            if (!target->IsAlive())
                return;

            Unit* pCaster = GetCaster();

            if (pCaster)
            {
                if (target->IsImmuneToSchool(spellProto, (1 << GetEffIndex())))
                {
                    pCaster->SendSpellOrDamageImmune(target, spellProto->Id);
                    return;
                }
            }

            // ignore non positive values (can be result apply spellmods to aura damage
            float amount = m_modifier.m_amount > 0 ? m_modifier.m_amount : 0;

            uint32 pdamage = ditheru(target->GetMaxPower(POWER_MANA) * amount / 100);

            DETAIL_FILTER_LOG(LOG_FILTER_PERIODIC_AFFECTS, "PeriodicTick: %s energize %s for %u mana inflicted by %u",
                              GetCasterGuid().GetString().c_str(), target->GetGuidStr().c_str(), pdamage, GetId());

            if (target->GetMaxPower(POWER_MANA) == 0)
                break;

            SpellPeriodicAuraLogInfo pInfo(this, pdamage, 0, 0, 0.0f);
            target->SendPeriodicAuraLog(&pInfo);

            int32 gain = target->ModifyPower(POWER_MANA, pdamage);

            if (pCaster)
                target->GetHostileRefManager().threatAssist(pCaster, float(gain) * 0.5f * sSpellMgr.GetSpellThreatMultiplier(spellProto), spellProto);
            break;
        }
        case SPELL_AURA_POWER_BURN_MANA:
        {
            // don't mana burn target if not alive, possible death persistent effects
            if (!target->IsAlive())
                return;

            Unit* pCaster = GetCaster();
            if (!pCaster)
                return;

            // Check for immune (not use charges)
            if (!spellProto->HasAttribute(SPELL_ATTR_UNAFFECTED_BY_INVULNERABILITY)) // confirmed Impaling spine goes through immunity
            {
                if (target->IsImmuneToDamage(spellProto->GetSpellSchoolMask(), spellProto))
                {
                    pCaster->SendSpellOrDamageImmune(target, spellProto->Id);
                    return;
                }
            }

    ConsumeProcCharges(ASSERT_NOTNULL(sSpellMgr->GetSpellProcEntry(GetSpellInfo())));
}
            float pdamage = m_modifier.m_amount > 0 ? m_modifier.m_amount : 0;

            Powers powerType = Powers(m_modifier.m_miscvalue);

            if (!target->IsAlive() || target->GetPowerType() != powerType)
                return;

            uint32 gain = uint32(-target->ModifyPower(powerType, -dither(pdamage)));

            gain = ditheru(gain * spellProto->EffectMultipleValue[GetEffIndex()]);

            // maybe has to be sent different to client, but not by SMSG_PERIODICAURALOG
            SpellNonMeleeDamage damageInfo(pCaster, target, spellProto->Id, SpellSchools(spellProto->School));
            damageInfo.periodicLog = true;

            pCaster->CalculateSpellDamage(&damageInfo, gain, spellProto, GetEffIndex());

            damageInfo.target->CalculateAbsorbResistBlock(pCaster, &damageInfo, spellProto);

            pCaster->DealDamageMods(damageInfo.target, damageInfo.damage, &damageInfo.absorb);

            pCaster->SendSpellNonMeleeDamageLog(&damageInfo);

            // Set trigger flag
            uint32 procAttacker = PROC_FLAG_ON_DO_PERIODIC;
            uint32 procVictim   = PROC_FLAG_ON_TAKE_PERIODIC;
            uint32 procEx       = createProcExtendMask(&damageInfo, SPELL_MISS_NONE);
            if (damageInfo.damage)
                procVictim |= PROC_FLAG_TAKEN_ANY_DAMAGE;

            pCaster->ProcDamageAndSpell(ProcSystemArguments(damageInfo.target, procAttacker, procVictim, procEx, damageInfo.damage, BASE_ATTACK, spellProto));

            pCaster->DealSpellDamage(&damageInfo, true);
            break;
        }
        case SPELL_AURA_MOD_REGEN:
        {
            // Eating anim
            if (spellProto->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED)
                target->HandleEmoteCommand(EMOTE_ONESHOT_EAT);
            break;
        }
        case SPELL_AURA_MOD_POWER_REGEN:
        {
            // don't energize target if not alive, possible death persistent effects
            if (!target->IsAlive())
                return;

            Powers pt = target->GetPowerType();
            if (int32(pt) != m_modifier.m_miscvalue)
                return;

            if (spellProto->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED)
            {
                // eating anim
                target->HandleEmoteCommand(EMOTE_ONESHOT_EAT);
            }
            else if (GetId() == 20577)
            {
                // cannibalize anim
                target->HandleEmoteCommand(EMOTE_STATE_CANNIBALIZE);
            }

            // Anger Management
            // amount = 1+ 16 = 17 = 3,4*5 = 10,2*5/3
            // so 17 is rounded amount for 5 sec tick grow ~ 1 range grow in 3 sec
            if (pt == POWER_RAGE)
                target->ModifyPower(pt, m_modifier.m_amount * 3 / 5);
            break;
        }
        // Here tick dummy auras
        case SPELL_AURA_DUMMY:                              // some spells have dummy aura
        {
            PeriodicDummyTick();
            break;
        }
        case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
        {
            TriggerSpell();
            break;
        }
        default:
            break;
    }
}

    // Formula see http://us.battle.net/wow/en/forum/topic/8197741003#1
    float ppm = m_spellInfo->CalcProcPPM(actor, GetCastItemLevel());
    float averageProcInterval = 60.0f / ppm;
void Aura::PeriodicDummyTick()
{
    SpellEntry const* spell = GetSpellProto();
    Unit* target = GetTarget();
    switch (spell->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            switch (spell->Id)
            {
                // Forsaken Skills
                case 7054:
                {
                    uint32 spellRandom = urand(0, 14) + 7038;
                    sLog.outInfo("7054 %u", spellRandom);

    TimePoint currentTime = GameTime::Now();
    float secondsSinceLastAttempt = std::min(std::chrono::duration_cast<FSeconds>(currentTime - m_lastProcAttemptTime).count(), 10.0f);
    float secondsSinceLastProc = std::min(std::chrono::duration_cast<FSeconds>(currentTime - m_lastProcSuccessTime).count(), 1000.0f);

    float chance = std::max(1.0f, 1.0f + ((secondsSinceLastProc / averageProcInterval - 1.5f) * 3.0f)) * ppm * secondsSinceLastAttempt / 60.0f;
    RoundToInterval(chance, 0.0f, 1.0f);
    return chance * 100.0f;
}
                    target->CastSpell(target, spellRandom, true, nullptr, this);
                    // Possibly need cast one of them (but
                    // 7038 Forsaken Skill: Swords
                    // 7039 Forsaken Skill: Axes
                    // 7040 Forsaken Skill: Daggers
                    // 7041 Forsaken Skill: Maces
                    // 7042 Forsaken Skill: Staves
                    // 7043 Forsaken Skill: Bows
                    // 7044 Forsaken Skill: Guns
                    // 7045 Forsaken Skill: 2H Axes
                    // 7046 Forsaken Skill: 2H Maces
                    // 7047 Forsaken Skill: 2H Swords
                    // 7048 Forsaken Skill: Defense
                    // 7049 Forsaken Skill: Fire
                    // 7050 Forsaken Skill: Frost
                    // 7051 Forsaken Skill: Holy
                    // 7053 Forsaken Skill: Shadow
                    return;
                }
                case 8067:                                  // Party Time!
                {
                    if (target->IsMoving())
                        target->HandleEmoteCommand(PickRandomValue(EMOTE_ONESHOT_APPLAUD, EMOTE_ONESHOT_CHEER, EMOTE_ONESHOT_CHICKEN, EMOTE_ONESHOT_LAUGH));
                    else
                        target->HandleEmoteCommand(PickRandomValue(EMOTE_ONESHOT_APPLAUD, EMOTE_ONESHOT_CHEER, EMOTE_ONESHOT_CHICKEN, EMOTE_ONESHOT_LAUGH, EMOTE_ONESHOT_DANCE));
                    return;
                }
                case 7057:                                  // Haunting Spirits
                    if (roll_chance_i(33))
                        target->CastSpell(target, m_modifier.m_amount, true, nullptr, this);
                    return;
                case 16336:                                 // Haunting Phantoms
                {
                    if (urand(0,1))
                        target->CastSpell(target, 16334, true); // Summon Spiteful Phantom
                    else
                        target->CastSpell(target, 16335, true); // Summon Wrath Phantom
                    return;
                }
                case 24596:                                 // Intoxicating Venom
                    if (target->IsInCombat())
                    {
                        uint32 rand = urand(0, 99);
                        if (rand < 7)
                            target->CastSpell(target, 8379, true, nullptr, this);     // Disarm
                        else if (rand < 14)
                            target->CastSpell(target, 6869, true, nullptr, this);     // Fall Down
                    }
                    return;
            }
            break;
        }

void Aura::_DeleteRemovedApplications()
{
    for (AuraApplication* aurApp : _removedApplications)
        delete aurApp;

    _removedApplications.clear();
}
        case SPELLFAMILY_PALADIN:
        {
#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_8_4
            // Judgement of Command
            if (spell->SpellIconID == 561)
            {
                if (target && target->HasUnitState(UNIT_STAT_STUNNED))
                {
                    if (Unit* pCaster = GetCaster())
                    {
                        uint32 spellId = 0;
                        switch (spell->Id)
                        {
                            case 20425: // Rank 1
                                spellId = 20467;
                                break;
                            case 20962: // Rank 2
                                spellId = 20963;
                                break;
                            case 20961: // Rank 3
                                spellId = 20964;
                                break;
                            case 20967: // Rank 4
                                spellId = 20965;
                                break;
                            case 20968: // Rank 5
                                spellId = 20966;
                                break;
                        }
                        if (spellId)
                            pCaster->CastSpell(target, spellId, true);
                    }
                }
                return;
            }
#endif
            break;
        }
        default:
            break;
    }
}

void Aura::HandlePreventFleeing(bool apply, bool Real)
{
    if (!Real)
        return;

    Unit::AuraList const& fearAuras = GetTarget()->GetAurasByType(SPELL_AURA_MOD_FEAR);
    if (fearAuras.empty())
    {
        TC_LOG_DEBUG("spells", "Aura::LoadScripts: Script `{}` for aura `{}` is loaded now", (*itr)->_GetScriptName()->c_str(), m_spellInfo->Id);
        (*itr)->Register();
        // Units may be feared without spell (Creature::DoFleeToGetAssistance)
        if (GetTarget()->GetTypeId() == TYPEID_UNIT)
            if (GetTarget()->GetMotionMaster()->GetCurrentMovementGeneratorType() == FLEEING_MOTION_TYPE ||
                    GetTarget()->GetMotionMaster()->GetCurrentMovementGeneratorType() == ASSISTANCE_MOTION_TYPE ||
                    GetTarget()->GetMotionMaster()->GetCurrentMovementGeneratorType() == ASSISTANCE_DISTRACT_MOTION_TYPE ||
                    GetTarget()->GetMotionMaster()->GetCurrentMovementGeneratorType() == TIMED_FLEEING_MOTION_TYPE)
                GetTarget()->GetMotionMaster()->MovementExpired(false);
    }
    else
    {
        if (apply)
            GetTarget()->SetFeared(false, fearAuras.front()->GetCasterGuid());
        else
            GetTarget()->SetFeared(true, fearAuras.front()->GetCasterGuid(), fearAuras.front()->GetId());
    }
}

void Aura::HandleManaShield(bool apply, bool Real)
{
    if (!Real)
        return;

    // prevent double apply bonuses
    if (apply && (GetTarget()->GetTypeId() != TYPEID_PLAYER || !((Player*)GetTarget())->GetSession()->PlayerLoading()))
    {
        if (Unit* caster = GetCaster())
        {
            float DoneActualBenefit = 0.0f;

            // Mana Shield
            // 0% coeff in vanilla (changed patch 2.4.0)
            // if (GetSpellProto()->IsFitToFamily<SPELLFAMILY_MAGE, CF_MAGE_MANA_SHIELD>())
            //    DoneActualBenefit = caster->SpellBaseDamageBonusDone(GetSpellSchoolMask(GetSpellProto())) * 0.5f;

            // DoneActualBenefit *= caster->CalculateLevelPenalty(GetSpellProto());

            m_modifier.m_amount += DoneActualBenefit;
        }
    }
}

bool Aura::IsLastAuraOnHolder()
{
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        if (i != GetEffIndex() && GetHolder()->m_auras[i])
            return false;
    return true;
}

SpellAuraHolder::SpellAuraHolder(SpellEntry const* spellproto, Unit* target, Unit* caster, Item *castItem, WorldObject* pRealCaster) :
    m_spellProto(spellproto), m_target(target), m_castItemGuid(castItem ? castItem->GetObjectGuid() : ObjectGuid()),
    m_auraSlot(MAX_AURAS), m_auraLevel(1), m_procCharges(0),
    m_stackAmount(1), m_removeMode(AURA_REMOVE_BY_DEFAULT), m_AuraDRGroup(DIMINISHING_NONE), m_timeCla(1000),
    m_permanent(false), m_isRemovedOnShapeLost(true), m_deleted(false), m_in_use(0),
    m_debuffLimitAffected(false), m_debuffLimitScore(0), _heartBeatRandValue(0), _pveHeartBeatData(nullptr),
    m_spellTriggered(false), m_AuraDRLevel(DIMINISHING_LEVEL_1)
{
    MANGOS_ASSERT(target);
    MANGOS_ASSERT(spellproto && spellproto == sSpellMgr.GetSpellEntry(spellproto->Id) && "`info` must be pointer to a sSpellMgr element");

    if (!caster)
        m_casterGuid = target->GetObjectGuid();
    else
    {
        // remove this assert when not unit casters will be supported
        MANGOS_ASSERT(caster->isType(TYPEMASK_UNIT))
        m_casterGuid = caster->GetObjectGuid();
    }

    if (pRealCaster)
        m_realCasterGuid = pRealCaster->GetObjectGuid();
    else
        m_realCasterGuid = m_casterGuid;

    m_applyTime      = time(nullptr);
    m_isPassive      = IsPassiveSpell(GetId()) || spellproto->Attributes == 0x80;
    m_isDeathPersist = spellproto->IsDeathPersistentSpell();
    m_isSingleTarget = spellproto->HasSingleTargetAura();
    m_procCharges    = spellproto->procCharges;
    m_isChanneled    = spellproto->IsChanneledSpell();

    m_isRemovedOnShapeLost = m_casterGuid == m_target->GetObjectGuid() && m_spellProto->IsRemovedOnShapeLostSpell();

    // Exceptions
    // Attaques circulaires
    if (m_spellProto->Id == 12292)
        m_isRemovedOnShapeLost = false;

    Unit* unitCaster = caster && caster->isType(TYPEMASK_UNIT) ? (Unit*)caster : nullptr;

    m_duration = m_maxDuration = spellproto->CalculateDuration(unitCaster);

    if (m_maxDuration == -1 || (m_isPassive && spellproto->DurationIndex == 0))
        m_permanent = true;
    // Fix de l'affichage dans le journal de combat des buffs tres cours.
    // Exemple: immunite des trinket PvP.
    else if (m_maxDuration < 200)
    {
        m_duration = 300;
        m_maxDuration = 300;
    }

    if (unitCaster)
    {
        if (Player* modOwner = unitCaster->GetSpellModOwner())
            modOwner->ApplySpellMod(GetId(), SPELLMOD_CHARGES, m_procCharges);
    }

    // some custom stack values at aura holder create
    switch (m_spellProto->Id)
    {
        // some auras applied with max stack
        case 24575:                                         // Brittle Armor
        case 24659:                                         // Unstable Power
        case 24662:                                         // Restless Strength
        case 26464:                                         // Mercurial Shield
            m_stackAmount = m_spellProto->StackAmount;
            break;
    }

    for (auto& aura : m_auras)
        aura = nullptr;
    m_makesTargetSecondaryFocus = !GetSpellProto()->IsPositiveSpell() && (GetSpellProto()->AuraInterruptFlags & AURA_INTERRUPT_FLAG_DAMAGE
                                                                    ||  m_spellProto->HasAura(SPELL_AURA_MOD_CONFUSE)
                                                                    ||  m_spellProto->HasAura(SPELL_AURA_MOD_FEAR));
}

void SpellAuraHolder::AddAura(Aura* aura, SpellEffectIndex index)
{
    ASSERT(index == aura->GetEffIndex());
    m_auras[index] = aura;
}

void SpellAuraHolder::RemoveAura(SpellEffectIndex index)
{
    m_auras[index] = nullptr;
}

void SpellAuraHolder::ApplyAuraModifiers(bool apply, bool real)
{
    for (uint8 i = 0; i < MAX_EFFECT_INDEX && !IsDeleted(); ++i)
        if (Aura* aur = GetAuraByEffectIndex(SpellEffectIndex(i)))
            aur->ApplyModifier(apply, real);
}

void SpellAuraHolder::_AddSpellAuraHolder()
{
    if (!GetId())
        return;
    if (!m_target)
        return;

    // Try find slot for aura
    uint8 slot = NULL_AURA_SLOT;
    Unit* caster = GetCaster();

    // Lookup free slot
    // will be < MAX_AURAS slot (if find free) with !secondaura
    if (IsNeedVisibleSlot(caster))
    {
        if (IsPositive())                                   // empty positive slot
        {
            for (uint8 i = 0; i < MAX_POSITIVE_AURAS; i++)
            {
                if (m_target->GetUInt32Value((uint16)(UNIT_FIELD_AURA + i)) == 0)
                {
                    slot = i;
                    break;
                }
            }
        }
        else                                                // empty negative slot
        {
            for (uint8 i = MAX_POSITIVE_AURAS; i < MAX_AURAS; i++)
            {
                if (m_target->GetUInt32Value((uint16)(UNIT_FIELD_AURA + i)) == 0)
                {
                    slot = i;
                    break;
                }
            }
        }
    }

    SetAuraSlot(slot);

    // Not update fields for not first spell's aura, all data already in fields
    if (slot < MAX_AURAS)                                   // slot found
    {
        SetAura(slot, false);
        SetAuraFlag(slot, true);
        SetAuraLevel(slot, caster ? caster->GetLevel() : sWorld.getConfig(CONFIG_UINT32_MAX_PLAYER_LEVEL));
        UpdateAuraApplication();

        // update for out of range group members
        m_target->UpdateAuraForGroup(slot);

        UpdateAuraDuration();
    }

    //*****************************************************
    // Update target aura state flag (at 1 aura apply)
    // TODO: Make it easer
    //*****************************************************
    // Sitdown on apply aura req seated
    if (m_spellProto->AuraInterruptFlags & AURA_INTERRUPT_FLAG_NOT_SEATED && !m_target->IsSittingDown())
        m_target->SetStandState(UNIT_STAND_STATE_SIT);

    // register aura diminishing on apply
    if (getDiminishGroup() != DIMINISHING_NONE)
        m_target->ApplyDiminishingAura(getDiminishGroup(), true);

    // Update Seals information
    if (GetSpellProto()->IsSealSpell())
        m_target->ModifyAuraState(AURA_STATE_JUDGEMENT, true);

    // Break stealth on target
    if (GetSpellProto()->Custom & SPELL_CUSTOM_AURA_APPLY_BREAKS_STEALTH)
        m_target->RemoveSpellsCausingAura(SPELL_AURA_MOD_STEALTH, this);
}

void SpellAuraHolder::_RemoveSpellAuraHolder()
{
    // Remove all triggered by aura spells vs unlimited duration
    // except same aura replace case
    if (m_removeMode != AURA_REMOVE_BY_STACK)
        CleanupTriggeredSpells();

    Unit* caster = GetCaster();

    if (IsPersistent())
    {
        if (SpellCaster* realCaster = GetRealCaster())
        {
            DynamicObject *dynObj = realCaster->GetDynObject(GetId());
            if (dynObj)
                dynObj->RemoveAffected(m_target);
        }
    }

    //passive auras do not get put in slots
    // Note: but totem can be not accessible for aura target in time remove (to far for find in grid)
    //if (m_isPassive && !(caster && caster->GetTypeId() == TYPEID_UNIT && ((Creature*)caster)->isTotem()))
    //    return false;

    uint8 slot = GetAuraSlot();

    if (slot < MAX_AURAS)
    {
        if (m_target->GetUInt32Value((uint16)(UNIT_FIELD_AURA + slot)) == 0)
            return;
        SetAura(slot, true);
        SetAuraFlag(slot, false);
        SetAuraLevel(slot, caster ? caster->GetLevel() : sWorld.getConfig(CONFIG_UINT32_MAX_PLAYER_LEVEL));
    }

    // unregister aura diminishing (and store last time)
    if (getDiminishGroup() != DIMINISHING_NONE)
        m_target->ApplyDiminishingAura(getDiminishGroup(), false);

    m_procCharges = 0;
    m_stackAmount = 1;
    UpdateAuraApplication();

    if (m_removeMode != AURA_REMOVE_BY_DELETE)
    {
        // update for out of range group members
        if (slot < MAX_AURAS)
            m_target->UpdateAuraForGroup(slot);

        //*****************************************************
        // Update target aura state flag (at last aura remove)
        //*****************************************************
        uint32 removeState = 0;
        uint64 removeFamilyFlag = m_spellProto->SpellFamilyFlags;
        switch (m_spellProto->SpellFamilyName)
        {
            case SPELLFAMILY_PALADIN:
                if (m_spellProto->IsSealSpell())
                    removeState = AURA_STATE_JUDGEMENT;     // Update Seals information
                break;
        }

        // Remove state (but need check other auras for it)
        if (removeState)
        {
            bool found = false;
            Unit::SpellAuraHolderMap const& holders = m_target->GetSpellAuraHolderMap();
            for (const auto& holder : holders)
            {
                SpellEntry const* auraSpellInfo = holder.second->GetSpellProto();
                if (auraSpellInfo->IsFitToFamily(SpellFamily(m_spellProto->SpellFamilyName), removeFamilyFlag))
                {
                    found = true;
                    break;
                }
            }

            // this has been last aura
            if (!found)
                m_target->ModifyAuraState(AuraState(removeState), false);
        }

        // reset cooldown state for spells
        if (caster && GetSpellProto()->HasAttribute(SPELL_ATTR_DISABLED_WHILE_ACTIVE))
        {
            // some spells need to start cooldown at aura fade (like stealth)
            caster->AddCooldown(*GetSpellProto());
        }
    }
}

void SpellAuraHolder::CleanupTriggeredSpells()
{
    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        if (!m_spellProto->EffectApplyAuraName[i])
            continue;

        uint32 tSpellId = m_spellProto->EffectTriggerSpell[i];
        if (!tSpellId)
            continue;

        SpellEntry const* tProto = sSpellMgr.GetSpellEntry(tSpellId);
        if (!tProto)
            continue;

        if (tProto->GetDuration() != -1)
            continue;

        // needed for spell 43680, maybe others
        // TODO: is there a spell flag, which can solve this in a more sophisticated way?
        if (m_spellProto->EffectApplyAuraName[i] == SPELL_AURA_PERIODIC_TRIGGER_SPELL &&
                m_spellProto->GetDuration() == int32(m_spellProto->EffectAmplitude[i]))
            continue;

        m_target->RemoveAurasDueToSpell(tSpellId);
    }
}

bool SpellAuraHolder::ModStackAmount(int32 num)
{
    uint32 protoStackAmount = m_spellProto->StackAmount;

    // Can`t mod
    if (!protoStackAmount)
        return true;

    // Modify stack but limit it
    int32 stackAmount = m_stackAmount + num;
    if (stackAmount > (int32)protoStackAmount)
        stackAmount = protoStackAmount;
    else if (stackAmount <= 0) // Last aura from stack removed
    {
        m_stackAmount = 0;
        return true; // need remove aura
    }

    // Update stack amount
    SetStackAmount(stackAmount);
    return false;
}

void SpellAuraHolder::SetStackAmount(uint32 stackAmount)
{
    Unit* target = GetTarget();
    Unit* caster = GetCaster();
    if (!target || !caster)
        return;

    bool refresh = stackAmount >= m_stackAmount;
    if (stackAmount != m_stackAmount)
    {
        m_stackAmount = stackAmount;
        UpdateAuraApplication();

        for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        {
            if (Aura* aur = m_auras[i])
            {
                int32 bp = aur->GetBasePoints();
                float amount = m_stackAmount * caster->CalculateSpellEffectValue(target, m_spellProto, SpellEffectIndex(i), &bp);
                // Reapply if amount change
                if (amount != aur->GetModifier()->m_amount)
                {
                    aur->ApplyModifier(false, true);
                    aur->GetModifier()->m_amount = amount;
                    aur->ApplyModifier(true, true);
                }
            }
        }
    }

    if (refresh)
        // Stack increased refresh duration
        RefreshHolder();
}

uint32 SpellAuraHolder::GetId() const
{
    return m_spellProto->Id;
}

void Aura::CallScriptEffectCalcAmountHandlers(AuraEffect const* aurEff, int32& amount, bool& canBeRecalculated)
Unit* SpellAuraHolder::GetCaster() const
{
    if (GetCasterGuid() == m_target->GetObjectGuid())
        return m_target;

    return ObjectAccessor::GetUnit(*m_target, GetCasterGuid());// player will search at any maps
}

SpellCaster* SpellAuraHolder::GetRealCaster() const
{
    if (GetRealCasterGuid() == GetCasterGuid())
        return GetCaster();

    if (GetRealCasterGuid().IsUnit())
        return ObjectAccessor::GetUnit(*m_target, GetRealCasterGuid());

    if (GetRealCasterGuid().IsGameObject() && m_target->FindMap())
        return m_target->FindMap()->GetGameObject(GetRealCasterGuid());

    return nullptr;
}

bool SpellAuraHolder::IsWeaponBuffCoexistableWith(SpellAuraHolder const* ref) const
{
    // only item casted spells
    if (!GetCastItemGuid())
        return false;

    // Exclude Debuffs
    if (!IsPositive())
        return false;

    // Exclude Non-generic Buffs and Executioner-Enchant
    if (GetSpellProto()->SpellFamilyName != SPELLFAMILY_GENERIC)
        return false;

    // Exclude Stackable Buffs [ie: Blood Reserve]
    if (GetSpellProto()->StackAmount)
        return false;

    // only self applied player buffs
    if (m_target->GetTypeId() != TYPEID_PLAYER || m_target->GetObjectGuid() != GetCasterGuid())
        return false;

    Item* castItem = ((Player*)m_target)->GetItemByGuid(GetCastItemGuid());
    if (!castItem)
        return false;

    // Limit to Weapon-Slots
    if (!castItem->IsEquipped() ||
            (castItem->GetSlot() != EQUIPMENT_SLOT_MAINHAND && castItem->GetSlot() != EQUIPMENT_SLOT_OFFHAND))
        return false;

    // form different weapons
    return ref->GetCastItemGuid() && ref->GetCastItemGuid() != GetCastItemGuid();
}

void Aura::CallScriptEffectCalcPeriodicHandlers(AuraEffect const* aurEff, bool& isPeriodic, int32& amplitude)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_PERIODIC);
        auto effEndItr = (*scritr)->DoEffectCalcPeriodic.end(), effItr = (*scritr)->DoEffectCalcPeriodic.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, isPeriodic, amplitude);
bool SpellAuraHolder::IsNeedVisibleSlot(Unit const* caster) const
{
    // Custom spells cannot be displayed on aura bar.
    if (m_spellProto->IsCustomSpell())
        return false;

    bool totemAura = caster && caster->GetTypeId() == TYPEID_UNIT && ((Creature*)caster)->IsTotem();

    // Check for persistent area auras that only do damage. If it has a secondary effect, it takes
    // up a slot
    bool persistent = m_spellProto->Effect[EFFECT_INDEX_0] == SPELL_EFFECT_PERSISTENT_AREA_AURA;
    bool persistentWithSecondaryEffect = false;

    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
    {
        // Check for persistent aura here since the effect aura is applied to the holder
        // by a dynamic object as the target passes through the object field, meaning
        // m_auras will be unset when this method is called (initialization)
        if (!m_auras[i] && !persistent)
            continue;

        // special area auras cases
        switch (m_spellProto->Effect[i])
        {
            case SPELL_EFFECT_APPLY_AREA_AURA_PET:
            case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
                // passive auras (except totem auras) do not get placed in caster slot
                return (m_target != caster || totemAura || !m_isPassive) && m_auras[i]->GetModifier()->m_auraname != SPELL_AURA_NONE;

                break;
            case SPELL_EFFECT_PERSISTENT_AREA_AURA:
                // If spell aura applies something other than plain damage, it takes
                // up a debuff slot.
                if (m_spellProto->EffectApplyAuraName[i] != SPELL_AURA_PERIODIC_DAMAGE)
                    persistentWithSecondaryEffect = true;

                break;
            default:
                break;
        }
    }

void Aura::CallScriptEffectCalcSpellModHandlers(AuraEffect const* aurEff, SpellModifier*& spellMod)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_SPELLMOD);
        auto effEndItr = (*scritr)->DoEffectCalcSpellMod.end(), effItr = (*scritr)->DoEffectCalcSpellMod.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, spellMod);
    /*  Persistent area auras such as Blizzard/RoF/Volley do not get require debuff slots
        since they just do area damage with no additional effects. However, spells like
        Hurricane do since they have a secondary effect attached to them. There are enough
        persistent area spells in-game that making a switch for all of them is a bit
        unreasonable. Any spell with a secondary affect should take up a slot. Note
        that most (usable) persistent spells only deal damage.

        It was considered whether spells with secondary effects should still deal damage,
        even if there is no room for the other effect, however the debuff tooltip states
        that the spell causes damage AND slows, therefore it must take a debuff slot.
     */
    if (persistent && !persistentWithSecondaryEffect)
    {
        return false;
    }

    // necessary for some spells, e.g. Immolate visual passive 28330
    if (m_spellProto->SpellVisual)
        return true;

    // passive auras (except totem auras) do not get placed in the slots
    return !m_isPassive || totemAura;
}

void SpellAuraHolder::HandleSpellSpecificBoosts(bool apply)
{
    uint32 spellId1 = 0;
    uint32 spellId2 = 0;
    uint32 spellId3 = 0;
    uint32 spellId4 = 0;

    switch (GetSpellProto()->SpellFamilyName)
    {
        case SPELLFAMILY_SHAMAN:
        {
            // Nostalrius : Pas de marche sur l'eau + loup fantome.
            if (apply && GetSpellProto()->Id == 2645)
                if (Unit* pCaster = GetCaster())
                    if (Aura* aura = pCaster->GetAura(546, EFFECT_INDEX_0))
                        pCaster->RemoveAura(aura);
            break;
        }
        case SPELLFAMILY_MAGE:
        {
            return;
        }
        case SPELLFAMILY_HUNTER:
        {
            switch (GetId())
            {
                // The Beast Within and Bestial Wrath - immunity
                case 19574:
                {
                    spellId1 = 24395;
                    spellId2 = 24396;
                    spellId3 = 24397;
                    spellId4 = 26592;
                    break;
                }
                default:
                    return;
            }
            break;
        }
        default:
            return;
    }

void Aura::CallScriptEffectCalcCritChanceHandlers(AuraEffect const* aurEff, AuraApplication const* aurApp, Unit const* victim, float& critChance)
{
    for (AuraScript* loadedScript : m_loadedScripts)
    {
        loadedScript->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_CALC_CRIT_CHANCE, aurApp);
        for (AuraScript::EffectCalcCritChanceHandler const& hook : loadedScript->DoEffectCalcCritChance)
            if (hook.IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                hook.Call(loadedScript, aurEff, victim, critChance);
    // prevent aura deletion, specially in multi-boost case
    SetInUse(true);

    if (apply)
    {
        if (spellId1)
            m_target->CastSpell(m_target, spellId1, true, nullptr, nullptr, GetCasterGuid());
        if (spellId2 && !IsDeleted())
            m_target->CastSpell(m_target, spellId2, true, nullptr, nullptr, GetCasterGuid());
        if (spellId3 && !IsDeleted())
            m_target->CastSpell(m_target, spellId3, true, nullptr, nullptr, GetCasterGuid());
        if (spellId4 && !IsDeleted())
            m_target->CastSpell(m_target, spellId4, true, nullptr, nullptr, GetCasterGuid());
    }
    else
    {
        if (spellId1)
            m_target->RemoveAurasByCasterSpell(spellId1, GetCasterGuid());
        if (spellId2)
            m_target->RemoveAurasByCasterSpell(spellId2, GetCasterGuid());
        if (spellId3)
            m_target->RemoveAurasByCasterSpell(spellId3, GetCasterGuid());
        if (spellId4)
            m_target->RemoveAurasByCasterSpell(spellId4, GetCasterGuid());
    }

    SetInUse(false);
}

void SpellAuraHolder::HandleCastOnAuraRemoval() const
{
    uint32 uiTriggeredSpell = 0;
    AuraRemoveMode mode = GetRemoveMode();

    switch (GetId())
    {
        case 26180:
        {
            if (mode == AURA_REMOVE_BY_DISPEL)
                uiTriggeredSpell = 26233;        // Wyvern Sting (AQ40, Princess Huhuran)
            break;
        }
        case 24002:
        case 24003:
        {
            if (mode == AURA_REMOVE_BY_EXPIRE)
                uiTriggeredSpell = 24004;        // Tranquilizing Poison (ZG, Razzashi Serpent)
            break;
        }
        default:
            return;
    }

void Aura::CallScriptEffectAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& absorbAmount, bool& defaultPrevented)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_ABSORB, aurApp);
        auto effEndItr = (*scritr)->OnEffectAbsorb.end(), effItr = (*scritr)->OnEffectAbsorb.begin();
        for (; effItr != effEndItr; ++effItr)
    if (uiTriggeredSpell)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(GetTarget(), uiTriggeredSpell, true);
        else
            GetTarget()->CastSpell(GetTarget(), uiTriggeredSpell, true);
    }
}

void Aura::HandleAuraSafeFall(bool Apply, bool Real)
{
    // implemented in WorldSession::HandleMovementOpcodes
}

SpellAuraHolder::~SpellAuraHolder()
{
    // note: auras in delete list won't be affected since they clear themselves from holder when adding to deletedAuraslist
    for (const auto& aura : m_auras)
        delete aura;

    delete _pveHeartBeatData;
}

        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAfterAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& absorbAmount)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_ABSORB, aurApp);
        auto effEndItr = (*scritr)->AfterEffectAbsorb.end(), effItr = (*scritr)->AfterEffectAbsorb.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, dmgInfo, absorbAmount);
void SpellAuraHolder::Update(uint32 diff)
{
    // Battements de coeur : 2 fonctionnements.
    // PvP
    if (_heartBeatRandValue)
    {
        float diminishRate = GetDiminishingRate(m_AuraDRLevel);
        float elapsedTime = (m_maxDuration - m_duration) / 1000.0f;
        float averageBreakTime = 12.0f * diminishRate; // 50% chance to break after 12 secs
        float maxBreakTime = 15.0f * diminishRate;
        static float const chanceBreakAtMax = 1.0f; // 1% break > 15 secs. Patch 1.2: "Players now have an increasing chance to break free of the effect, such that it is unlikely the effect will last more than 15 seconds."
        static float const chanceBreakAtMaxLog = log((100 - chanceBreakAtMax) / chanceBreakAtMax);
        float coeff = (1.0f / (maxBreakTime - averageBreakTime)) * chanceBreakAtMaxLog;
        float currHeartBeatValue = 100.0f / (1.0f + exp(coeff * (averageBreakTime - elapsedTime)));
        DEBUG_UNIT(GetTarget(), DEBUG_DR, "|HB Duration [Curr%.2f|Max%u]. Value[Curr%.2f|Limit%.2f]",
                           elapsedTime, m_maxDuration / 1000, currHeartBeatValue, _heartBeatRandValue);
        if (_heartBeatRandValue <=  currHeartBeatValue)
        {
            if (Unit* pTarget = GetTarget())
                pTarget->RemoveSpellAuraHolder(this);
            return;
        }
    }
    // PvE
    if (_pveHeartBeatData)
    {
        if (_pveHeartBeatData->timer <= diff)
        {
            _pveHeartBeatData->timer += 5000 - diff;
            if (Unit* pTarget = GetTarget())
            {
                uint32 missChance = 10000 - _pveHeartBeatData->hitChance;
                uint32 rand = urand(0, 10000);

                if (rand < missChance)
                {
                    delete _pveHeartBeatData;
                    _pveHeartBeatData = nullptr;
                    pTarget->RemoveSpellAuraHolder(this);
                    return;
                }
            }
        }
        else
            _pveHeartBeatData->timer -= diff;
    }

void Aura::CallScriptEffectAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, HealInfo& healInfo, uint32& absorbAmount, bool& defaultPrevented)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_ABSORB, aurApp);
        auto effEndItr = (*scritr)->OnEffectAbsorbHeal.end(), effItr = (*scritr)->OnEffectAbsorbHeal.begin();
        for (; effItr != effEndItr; ++effItr)

            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, healInfo, absorbAmount);

        if (!defaultPrevented)
            defaultPrevented = (*scritr)->_IsDefaultActionPrevented();
        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectAfterAbsorbHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, HealInfo& healInfo, uint32& absorbAmount)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_ABSORB, aurApp);
        auto effEndItr = (*scritr)->AfterEffectAbsorbHeal.end(), effItr = (*scritr)->AfterEffectAbsorbHeal.begin();
        for (; effItr != effEndItr; ++effItr)

            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, healInfo, absorbAmount);

        (*scritr)->_FinishScriptCall();
    }
}

void Aura::CallScriptEffectManaShieldHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& absorbAmount, bool& /*defaultPrevented*/)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_MANASHIELD, aurApp);
        auto effEndItr = (*scritr)->OnEffectManaShield.end(), effItr = (*scritr)->OnEffectManaShield.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, dmgInfo, absorbAmount);
    if (m_duration > 0)
    {
        m_duration -= diff;
        if (m_duration < 0)
            m_duration = 0;

        m_timeCla -= diff;

        if (m_timeCla <= 0)
        {
            if (Unit* caster = GetCaster())
            {
                Powers powertype = Powers(m_spellProto->powerType);
                int32 manaPerSecond = m_spellProto->manaPerSecond + m_spellProto->manaPerSecondPerLevel * caster->GetLevel();
                m_timeCla = 1 * IN_MILLISECONDS;

                Unit* target = GetTarget();
                if (manaPerSecond && // avoid double cost for health funnel :
                    !(m_spellProto->SpellFamilyName == SPELLFAMILY_WARLOCK &&
                    m_spellProto->IsFitToFamilyMask<CF_WARLOCK_HEALTH_FUNNEL>() &&
                    target && (target->GetCharmerOrOwnerGuid() == GetCasterGuid())))
                {
                    if (powertype == POWER_HEALTH && int32(caster->GetHealth()) > manaPerSecond)
                        caster->ModifyHealth(-manaPerSecond);
                    else if (int32(caster->GetPower(powertype)) >= manaPerSecond)
                        caster->ModifyPower(powertype, -manaPerSecond);
                    else
                    {
                        if (target)
                            target->RemoveAurasDueToSpell(m_spellProto->Id, this);
                        if (m_isChanneled)
                            caster->InterruptSpell(CURRENT_CHANNELED_SPELL);
                        if (Player* plCaster = caster->ToPlayer())
                            Spell::SendCastResult(plCaster, m_spellProto, SPELL_FAILED_FIZZLE);
                    }
                }
            }
        }
    }

    for (const auto aura : m_auras)
        if (aura)
            aura->UpdateAura(diff);

    // Channeled aura required check distance from caster
    if (m_isChanneled && GetCasterGuid() != m_target->GetObjectGuid())
    {
        Unit* caster = GetCaster();
        if (!caster)
        {
            m_target->RemoveAurasByCasterSpell(GetId(), GetCasterGuid());
            return;
        }

void Aura::CallScriptEffectAfterManaShieldHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& absorbAmount)
{
    for (auto scritr = m_loadedScripts.begin(); scritr != m_loadedScripts.end(); ++scritr)
    {
        (*scritr)->_PrepareScriptCall(AURA_SCRIPT_HOOK_EFFECT_AFTER_MANASHIELD, aurApp);
        auto effEndItr = (*scritr)->AfterEffectManaShield.end(), effItr = (*scritr)->AfterEffectManaShield.begin();
        for (; effItr != effEndItr; ++effItr)
            if (effItr->IsEffectAffected(m_spellInfo, aurEff->GetEffIndex()))
                effItr->Call(*scritr, aurEff, dmgInfo, absorbAmount);
        // Nostalrius : mise en combat
        if (!(GetSpellProto()->AttributesEx3 & SPELL_ATTR_EX3_NO_INITIAL_AGGRO) && !IsPositive() &&
                caster->IsVisibleForOrDetect(m_target, m_target, false))
        {
            m_target->SetInCombatWith(caster);
            caster->SetInCombatWith(m_target);
        }
        // unlimited range
        if (m_spellProto->Custom & SPELL_CUSTOM_CHAN_NO_DIST_LIMIT)
            return;

        // need check distance for channeled target only
        if (caster->GetChannelObjectGuid() == m_target->GetObjectGuid())
        {
            // spell range + guessed interrupt leeway range
            float max_range = GetSpellMaxRange(sSpellRangeStore.LookupEntry(m_spellProto->rangeIndex));

            if (m_target->IsHostileTo(caster))
                max_range *= 1.33f;
            else // add radius of caster (see Spell::CheckRange)
                max_range += 1.25f;

            if (Player* modOwner = caster->GetSpellModOwner())
                modOwner->ApplySpellMod(GetId(), SPELLMOD_RANGE, max_range, nullptr);

            if (caster->GetCombatDistance(m_target) > max_range)
                caster->InterruptSpell(CURRENT_CHANNELED_SPELL);
        }
    }
}

void SpellAuraHolder::RefreshHolder()
{
    SetAuraDuration(GetAuraMaxDuration());
    UpdateAuraDuration();
}

void Aura::CallScriptEffectSplitHandlers(AuraEffect* aurEff, AuraApplication const* aurApp, DamageInfo& dmgInfo, uint32& splitAmount)
/**
 * Updates periodic timers based on the current duration. Used for channeled spells
 * which are applied using dynamic objects, when we want the tick to be based on
 * the current spell timer rather than a fresh holder.
 * @param duration Custom duration to base tick on (typically in the case of passive auras)
 *
 */
void SpellAuraHolder::RefreshAuraPeriodicTimers(int32 duration)
{
    for (uint8 i = 0 ; i < MAX_EFFECT_INDEX; ++i)
    {
        if (Aura* pAura = GetAuraByEffectIndex(SpellEffectIndex(i)))
        {
            // If the aura is periodic, update the periodic timer to correspond with the new
            // aura timer
            if (pAura->IsPeriodic())
                pAura->UpdatePeriodicTimer(duration > 0 ? duration : m_duration);
        }
    }
}

void SpellAuraHolder::SetAuraMaxDuration(int32 duration)
{
    m_maxDuration = duration;

    // possible overwrite persistent state
    if (duration > 0)
    {
        if (!(IsPassive() && GetSpellProto()->DurationIndex == 0))
            SetPermanent(false);
    }
}

bool SpellAuraHolder::HasMechanic(uint32 mechanic) const
{
    if (mechanic == m_spellProto->Mechanic)
        return true;

    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        if (m_auras[i] && m_spellProto->EffectMechanic[i] == mechanic)
            return true;
    return false;
}

bool SpellAuraHolder::HasMechanicMask(uint32 mechanicMask) const
{
    if (m_spellProto->Mechanic && mechanicMask & (1 << (m_spellProto->Mechanic - 1)))
        return true;

    for (uint8 i = 0; i < MAX_EFFECT_INDEX; ++i)
        if (m_auras[i] && m_spellProto->EffectMechanic[i] && ((1 << (m_spellProto->EffectMechanic[i] - 1)) & mechanicMask))
            return true;
    return false;
}

bool SpellAuraHolder::IsPersistent() const
{
    for (const auto aura : m_auras)
        if (aura)
            if (aura->IsPersistent())
                return true;
    return false;
}

bool SpellAuraHolder::IsAreaAura() const
{
    for (const auto aura : m_auras)
        if (aura)
            if (aura->IsAreaAura())
                return true;
    return false;
}

bool SpellAuraHolder::IsPositive() const
{
    for (const auto aura : m_auras)
        if (aura)
            if (!aura->IsPositive())
                return false;
    return true;
}

bool SpellAuraHolder::IsEmptyHolder() const
{
    for (const auto aura : m_auras)
        if (aura)
            return false;
    return true;
}

void SpellAuraHolder::UnregisterSingleCastHolder()
{
    if (IsSingleTarget())
    {
        if (Unit* caster = GetCaster())
            caster->GetSingleCastSpellTargets().erase(GetSpellProto());

        m_isSingleTarget = false;
    }
}

void SpellAuraHolder::SetAura(uint32 slot, bool remove)
{
    m_target->SetUInt32Value(UNIT_FIELD_AURA + slot, remove ? 0 : GetId());
}

void SpellAuraHolder::SetAuraFlag(uint32 slot, bool add)
{
    uint32 index    = slot >> 3;
    uint32 byte     = (slot & 7) << 2;
    uint32 val      = m_target->GetUInt32Value(UNIT_FIELD_AURAFLAGS + index);
    val &= ~(uint32(AFLAG_MASK_ALL) << byte);
    if (add)
    {
        uint32 flags = AFLAG_NONE;

        if (IsPositive())
        {
            if (!m_spellProto->HasAttribute(SPELL_ATTR_CANT_CANCEL))
                flags |= AFLAG_CANCELABLE;
            flags |= AFLAG_UNK3;
        }
        else
            flags |= AFLAG_UNK4;

        val |= (flags << byte);
    }
    m_target->SetUInt32Value(UNIT_FIELD_AURAFLAGS + index, val);
}

void SpellAuraHolder::SetAuraLevel(uint32 slot, uint32 level)
{
    uint32 index    = slot / 4;
    uint32 byte     = (slot % 4) * 8;
    uint32 val      = m_target->GetUInt32Value(UNIT_FIELD_AURALEVELS + index);
    val &= ~(0xFF << byte);
    val |= (level << byte);
    m_target->SetUInt32Value(UNIT_FIELD_AURALEVELS + index, val);
}

void SpellAuraHolder::UpdateAuraApplication()
{
    if (m_auraSlot >= MAX_AURAS)
        return;

    uint32 stackCount = m_procCharges > 0 ? m_procCharges * m_stackAmount : m_stackAmount;

    uint32 index    = m_auraSlot / 4;
    uint32 byte     = (m_auraSlot % 4) * 8;
    uint32 val      = m_target->GetUInt32Value(UNIT_FIELD_AURAAPPLICATIONS + index);
    val &= ~(0xFF << byte);
    // field expect count-1 for proper amount show, also prevent overflow at client side
    val |= ((uint8(stackCount <= 255 ? stackCount - 1 : 255 - 1)) << byte);
    m_target->SetUInt32Value(UNIT_FIELD_AURAAPPLICATIONS + index, val);
}

void SpellAuraHolder::UpdateAuraDuration() const
{
    if (GetAuraSlot() >= MAX_AURAS || m_isPassive)
        return;

    if (m_target->GetTypeId() == TYPEID_PLAYER)
    {
        WorldPacket data(SMSG_UPDATE_AURA_DURATION, 5);
        data << uint8(GetAuraSlot());
        data << uint32(GetAuraDuration());
        ((Player*)m_target)->SendDirectMessage(&data);
    }
}

void SpellAuraHolder::SetAffectedByDebuffLimit(bool isAffectedByDebuffLimit)
{
    m_debuffLimitAffected = isAffectedByDebuffLimit;
}

/** NOSTALRIUS
 Debuff limitation
    Categories:
     * 4 (highest)  Highest Priority Debuffs (Generally, a debuff that alters the ability of a mob to act normally)
     * 3            Generally, a standalone debuff ability intentionally casted that gives benefits group/raid wide
     * 2            Generally, a debuff that is a secondary result of some other ability but still gives raid-wide benefits
     * 1            Generally, debuffs that are intentionally cast, stand-alone damage-over-time abilities
     * 0            Generally, a debuff that is a secondarily applied damage-over-time effect
  */
void SpellAuraHolder::CalculateForDebuffLimit()
{
    m_debuffLimitAffected = true;
    m_debuffLimitScore = 0;

    // Gouge - Category 1
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_ROGUE, CF_ROGUE_GOUGE>())
    {
        m_debuffLimitScore = 1;
        return;
    }

    // Garrote - Category 2
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_ROGUE, CF_ROGUE_GARROTE>())
    {
        m_debuffLimitScore = 2;
        return;
    }

    // Rupture - Category 2
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_ROGUE, CF_ROGUE_RUPTURE>())
    {
        m_debuffLimitScore = 2;
        return;
    }

    // Rend - Category 2
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_WARRIOR, CF_WARRIOR_REND>())
    {
        m_debuffLimitScore = 2;
        return;
    }

    // Rake - Category 2
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_DRUID, CF_DRUID_RAKE_CLAW>())
    {
        m_debuffLimitScore = 2;
        return;
    }

    // Rip - Category 2
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_DRUID, CF_DRUID_RIP_BITE>())
    {
        m_debuffLimitScore = 2;
        return;
    }

    // Hamstring - Category 3
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_WARRIOR, CF_WARRIOR_HAMSTRING>())
    {
        m_debuffLimitScore = 3;
        return;
    }

    // Kidney Shot - Category 3
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_ROGUE, CF_ROGUE_KIDNEY_SHOT>())
    {
        m_debuffLimitScore = 3;
        return;
    }

    // Bash - Category 3
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_DRUID, CF_DRUID_BASH>())
    {
        m_debuffLimitScore = 3;
        return;
    }

    // Expose Armor - Category 3
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_ROGUE, CF_ROGUE_EXPOSE_ARMOR>())
    {
        m_debuffLimitScore = 3;
        return;
    }
}

std::string Aura::GetDebugInfo() const
{
    std::stringstream sstr;
    sstr << std::boolalpha
        << "Id: " << GetId() << " Name: '" << (*GetSpellInfo()->SpellName)[sWorld->GetDefaultDbcLocale()] << "' Caster: " << GetCasterGUID().ToString()
        << "\nOwner: " << (GetOwner() ? GetOwner()->GetDebugInfo() : "NULL");
    return sstr.str();
}

    // Sunder Armor - Category 3
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_WARRIOR, CF_WARRIOR_SUNDER_ARMOR>())
    {
        m_debuffLimitScore = 3;
        return;
    }

UnitAura::UnitAura(AuraCreateInfo const& createInfo)
    : Aura(createInfo)
{
    m_AuraDRGroup = DIMINISHING_NONE;
    LoadScripts();
    _InitEffects(createInfo._auraEffectMask, createInfo.Caster, createInfo.BaseAmount);
    GetUnitOwner()->_AddAura(this, createInfo.Caster);
}
    // Thunder Clap - Category 3
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_WARRIOR, CF_WARRIOR_THUNDER_CLAP>())
    {
        m_debuffLimitScore = 3;
        return;
    }

void UnitAura::_ApplyForTarget(Unit* target, Unit* caster, AuraApplication* aurApp)
{
    Aura::_ApplyForTarget(target, caster, aurApp);
    // Hemorrhage - Category 3
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_ROGUE, CF_ROGUE_HEMORRHAGE>())
    {
        m_debuffLimitScore = 3;
        return;
    }

    // Mocking Blow - Category 3
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_WARRIOR, CF_WARRIOR_MOCKING_BLOW>())
    {
        m_debuffLimitScore = 3;
        return;
    }

void UnitAura::_UnapplyForTarget(Unit* target, Unit* caster, AuraApplication* aurApp)
{
    Aura::_UnapplyForTarget(target, caster, aurApp);
    // Mortal Strike - Category 3
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_WARRIOR, CF_WARRIOR_MORTAL_STRIKE>())
    {
        m_debuffLimitScore = 3;
        return;
    }

    // Demoralizing Shout - Category 4
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_WARRIOR, CF_WARRIOR_DEMORALIZING_SHOUT>())
    {
        m_debuffLimitScore = 4;
        return;
    }

    // Demoralizing Roar - Category 4
    if (m_spellProto->IsFitToFamily<SPELLFAMILY_DRUID, CF_DRUID_DEMORALIZING_ROAR>())
    {
        m_debuffLimitScore = 4;
        return;
    }

void UnitAura::FillTargetMap(std::unordered_map<Unit*, uint32>& targets, Unit* caster)
{
    Unit* ref = caster;
    if (!ref)
        ref = GetUnitOwner();
    uint32 const firstRank = sSpellMgr.GetFirstSpellInChain(m_spellProto->Id);
    switch (firstRank)
    {
        // Category 0 below
        case 1604: // Dazed
        case 2094: // Blind
        case 3409: // Crippling Poison (Rank 1)
        case 11201: // Crippling Poison (Rank 2)
        case 3600: // Earthbind
        case 4066: // Small Bronze Bomb
        case 4067: // Big Bronze Bomb
        case 4069: // Big Iron Bomb
        case 4507: // Target Dummy Spawn Effect
        case 5246: // Intimidating Shout
        case 5530: // Mace Stun Effect
        case 6358: // Seduction
        case 6788: // Weakened Soul
        case 9672: // Frostbolt (npc spell)
        case 339: // Entangling Roots
        case 2908: // Soothe Animal
        case 8056: // Frost Shock
        case 8122: // Psychic Scream
        case 605: // Mind Control
        case 6770: // Sap (Rank 1)
        case 2070: // Sap (Rank 2)
        case 11297: // Sap (rank 3)
        case 18202: // Rend (item spell)
        case 18075: // Rend (item spell)
        case 17511: // Poison
        case 17504: // Rend (item spell)
        case 17484: // Skullforge Brand
        case 17483: // Shadow Bolt (item spell)
        case 17407: // Wound
        case 17196: // Seeping Willow
        case 16406: // Rend (item spell)
        case 14914: // Holy Fire
        case 21162: // Fireball (item spell)
        case 13752: // Faerie Fire (item spell)
        case 12328: // Death Wish
        case 13526: // Corrosive Poison
        case 13318: // Rend (item spell)
        case 11366: // Pyroblast
        case 133: // Fireball
        case 12721: // Deep Wound
        case 24388: // Brain Damage
        case 21159: // Fireball (item spell)
        case 21151: // Gutgore Ripper
        case 12421: // Mithril Frag Bomb
        case 12562: // The Big One
        case 118: // Polymorph
        case 13237: // Goblin Mortar
        case 13327: // Reckless Charge
        case 13747: // Slow
        case 13808: // M73 Frag Grenade
        case 14251: // Riposte
        case 3355: // Freezing Trap Effect (Rank 1)
        case 14308: // Freezing Trap Effect (Rank 2)
        case 14309: // Freezing Trap Effect (Rank 3)
        case 15235: // Crystal Yield
        case 15487: // Silence
        case 8034: // Frost Brand Attack
        case 16454: // Searing Blast
        case 17153: // Rend (item spell)
        case 5484: // Howl of Terror
        case 18093: // Pyroclasm
        case 18118: // Aftermath
        case 18223: // Curse of Exhaustion
        case 710: // Banish
        case 18798: // Freeze
        case 19229: // Improved Wing Clip
        case 19410: // Improved Concussive Shot
        case 19755: // Frightalon
        case 19784: // Dark Iron Bomb
        case 19872: // Calm Dragonkin
        case 19970: // Entangling Roots
        case 20066: // Repentance
        case 20586: // Windreaper
        case 24375: // War Stomp
        case 24394: // Intimidation
            m_debuffLimitScore = 0;
            return;
        // Category 1 below
        case 1833: // Cheap Shot
        case 5917: // Fumble
        case 7922: // Charge Stun
        case 9658: // Flame Buffet
        case 10578: // Fireball (item spell)
        case 2096: // Mind Vision
        case 453: // Mind Soothe
        case 1714: // Curse of Tongues
        case 11103: // Impact (Rank 1)
        case 12357: // Impact (Rank 2)
        case 12358: // Impact (Rank 3)
        case 12359: // Impact (Rank 4)
        case 12360: // Impact (Rank 5)
        case 11113: // Blast Wave
        case 2974: // Wing Clip
        case 3043: // Scorpid Sting
        case 16413: // Fireball (item spell)
        case 16415: // Fireball (item spell)
        case 17330: // Poison
        case 17506: // Soul Breaker
        case 17639: // Wail of the Banshee
        case 18289: // Creeping Mold
        case 18425: // Kick - Silenced
        case 18469: // Counterspell - Silenced
        case 18498: // Shield Bash - Silenced
        case 19821: // Arcane Bomb
        case 20184: // Judgement of Justice
        case 20511: // Intimidating Shout
        case 22639: // Eskhandar's Rake
        case 23023: // Conflagration
        case 28272: // Polymorph Pig
            m_debuffLimitScore = 1;
            return;
        // Category 2 below
        case 12579: // Winter's Chill
        case 67: // Vindication (Rank 1)
        case 26017: // Vindication (Rank 2)
        case 26018: // Vindication (Rank 3)
        case 23605: // Spell Vulnerability
        case 702: // Curse of Weakness
        case 11374: // Gift of Arthas
        case 8921: // Moonfire
        case 18265: // Siphon Life
        case 980: // Curse of Agony
        case 13797: // Immolation Trap Effect
        case 1978: // Serpent Sting
        case 21992: // Thunderfury
        case 2818: // Deadly Poison
        case 348: // Immolate
        case 23577: // Expose Weakness
        case 17315: // Puncture Armor
        case 16928: // Armor Shatter
        case 17877: // Shadowburn
        case 23415: // Improved Blessing of Protection
        case 9035: // Hex of Weakness
        case 2944: // Devouring Plague
        case 24640: // Scorpid Poison (Rank 1)
        case 24583: // Scorpid Poison (Rank 2)
        case 24586: // Scorpid Poison (Rank 3)
        case 24587: // Scorpid Poison (Rank 4)
        case 12766: // Poison Cloud
        case 2943: // Touch of Weakness (Rank 1)
        case 19249: // Touch of Weakness (Rank 2)
        case 19251: // Touch of Weakness (Rank 3)
        case 19252: // Touch of Weakness (Rank 4)
        case 19253: // Touch of Weakness (Rank 5)
        case 19254: // Touch of Weakness (Rank 6)
        case 8050: // Flame Shock
        case 172: // Corruption
        case 16528: // Numbing Pain
        case 15258: // Shadow Vulnerability
        case 13003: // Shrink Ray
        case 589: // Shadow Word: Pain
        case 12654: // Ignite
            m_debuffLimitScore = 2;
            return;
        // Category 3 below
        case 355: // Taunt
        case 603: // Curse of Doom
        case 676: // Disarm
        case 1161: // Challenging Shout
        case 1543: // Flare
        case 2855: // Detect Magic
        case 4068: // Iron Grenade
        case 5116: // Concussive Shot
        case 5209: // Challenging Roar
        case 5782: // Fear
        case 770: // Faerie Fire
        case 16857: // Faerie Fire (Feral)
        case 120: // Cone of Cold
        case 10: // Blizzard
        case 2120: // Flamestrike
        case 122: // Frost Nova
        case 853: // Hammer of Justice
        case 5760: // Mind-numbing Poison
        case 8692: // Mind-numbing Poison II
        case 11398: // Mind-numbing Poison III
        case 1120: // Drain Soul
        case 5740: // Rain of Fire
        case 689: // Drain Life
        case 5138: // Drain Mana
        case 704: // Curse of Reclessness
        case 1490: // Curse of the Elements
        case 12323: // Piercing Howl
        case 11071: // Forstbite (Rank 1)
        case 12496: // Frostbite (Rank 2)
        case 12497: // Frostbite (Rank 3)
        case 12543: // Hi-Explosive Bomb
        case 12798: // Revenge
        case 12809: // Concussion Blow
        case 13218: // Wound Poison
        case 13810: // Frost Trap Aura
        case 3034: // Viper Sting
        case 1510: // Volley
        case 13812: // Explosive Trap Effect
        case 1130: // Hunter's Mark
        case 15286: // Vampiric Embrace
        case 15268: // Blackout (Rank 1)
        case 15323: // Blackout (Rank 2)
        case 15324: // Blackout (Rank 3)
        case 15325: // Blackout (Rank 4)
        case 15326: // Blackout (Rank 5)
        case 15407: // Mind Flay
        case 16922: // Starfire Stun
        case 17364: // Stormstrike
        case 16914: // Hurricane
        case 17794: // Shadow Vulnerability (Rank 1)
        case 17798: // Shadow Vulnerability (Rank 2)
        case 17797: // Shadow Vulnerability (Rank 3)
        case 17799: // Shadow Vulnerability (Rank 4)
        case 17800: // Shadow Vulnerability (Rank 5)
        case 6789: // Death Coil
        case 17862: // Curse of Shadow
        case 18656: // Corruption (item spell)
        case 2637: // Hibernate
        case 19185: // Entrapment
        case 10797: // Starshards
        case 19503: // Scatter Shot
        case 19675: // Feral Charge Effect
        case 19769: // Thorium Grenade
        case 20006: // Unholy Curse
        case 21183: // Judgement of the Crusader (Rank 1)
        case 20188: // Judgement of the Crusader (Rank 2)
        case 20300: // Judgement of the Crusader (Rank 3)
        case 20301: // Judgement of the Crusader (Rank 4)
        case 20302: // Judgement of the Crusader (Rank 5)
        case 20303: // Judgement of the Crusader (Rank 6)
        case 20185: // Judgement of Light (Rank 1)
        case 20344: // Judgement of Light (Rank 2)
        case 20345: // Judgement of Light (Rank 3)
        case 20346: // Judgement of Light (Rank 4)
        case 20186: // Judgement of Wisdom (Rank 1)
        case 20354: // Judgement of Wisdom (Rank 2)
        case 20355: // Judgement of Wisdom (Rank 3)
        case 20549: // War Stomp
        case 20253: // Intercept Stun (Rank 1)
        case 20614: // Intercept Stun (Rank 2)
        case 20615: // Intercept Stun (Rank 3)
        case 20116: // Consecration (-1.8)
        case 26573: // Consecration (1.9+)
        case 21152: // Earthshaker
        case 22959: // Fire Vulnerability
        case 23454: // Stun
        case 23694: // Improved Hamstring
        case 24423: // Screech (Rank 1)
        case 24577: // Screech (Rank 2)
        case 24578: // Screech (Rank 3)
        case 24579: // Screech (Rank 4)
        case 5570: // Insect Swarm
        case 116: // Frostbolt
        case 25999: // Boar Charge
            m_debuffLimitScore = 3;
            return;
        // Category 4 below
        case 6136: // Chilled
        case 6795: // Growl
        case 17331: // Fang of the Crystal Spider
        case 27648: // Thunderfury
        case 24323: // Hakkar's Blood Siphon
        case 24322: // Hakkar's Blood Siphon
        case 28732: // Faerlina Widow's Embrace
        case 25181: // Ossirian Arcane Weakness
        case 25177: // Ossirian Fire Weakness
        case 25178: // Ossirian Frost Weakness
        case 25180: // Ossirian Nature Weakness
        case 25183: // Ossirian Shadow Weakness
        // Possibly an even higher category
        case 7321: // Chilled
        case 16597: // Curse of Shahram
        case 20005: // Chilled
            m_debuffLimitScore = 4;
            return;
    }

    // Determine based on aura type
    for (uint32 i : m_spellProto->EffectApplyAuraName)
    {
        if (!i)
            continue;

    // add non area aura targets
    // static applications go through spell system first, so we assume they meet conditions
    for (auto const& targetPair : _staticApplications)
    {
        Unit* target = ObjectAccessor::GetUnit(*GetUnitOwner(), targetPair.first);
        if (!target && targetPair.first == GetUnitOwner()->GetGUID())
            target = GetUnitOwner();

        if (target)
            targets.emplace(target, targetPair.second);
    }

    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
    {
        if (!HasEffect(spellEffectInfo.EffectIndex))
            continue;

        // area auras only
        if (spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA))
            continue;

        // skip area update if owner is not in world!
        if (!GetUnitOwner()->IsInWorld())
            continue;

        if (GetUnitOwner()->HasUnitState(UNIT_STATE_ISOLATED))
            continue;

        std::vector<Unit*> units;
        ConditionContainer* condList = spellEffectInfo.ImplicitTargetConditions;

        float radius = spellEffectInfo.CalcRadius(ref);
        float extraSearchRadius = 0.0f;
        uint32 currEffectScore = 0;
        switch (i)
        {
            case SPELL_AURA_MOD_TAUNT:
            case SPELL_AURA_MOD_THREAT:
            case SPELL_AURA_MOD_CHARM:
            case SPELL_AURA_MOD_FEAR:
            case SPELL_AURA_MOD_CONFUSE:
            case SPELL_AURA_MOD_POSSESS:
            case SPELL_AURA_MOD_STUN:
                currEffectScore = 4;
                break;
            case SPELL_AURA_MOD_RESISTANCE:
            case SPELL_AURA_MOD_LANGUAGE:                   // Language curse
            case SPELL_AURA_MOD_STALKED:                    // Hunter mark
            case SPELL_AURA_MOD_DISARM:
            case SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN:
            case SPELL_AURA_PREVENTS_FLEEING:               // Curse of recklessness
            case SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE: // Winter's Chill
            case SPELL_AURA_MOD_MELEE_HASTE:
            case SPELL_AURA_MOD_ATTACK_POWER:
            case SPELL_AURA_MOD_DAMAGE_DONE:
            case SPELL_AURA_MOD_DAMAGE_TAKEN:
            case SPELL_AURA_MOD_HEALING_PCT:                // Mortal Strike
                currEffectScore = 3;
                break;
            case SPELL_AURA_PERIODIC_DAMAGE:
            case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
            case SPELL_AURA_PERIODIC_LEECH:
                currEffectScore = 1;
                break;
            case SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS: // Expose Weakness
                m_debuffLimitScore = 3;
                return;
            case SPELL_AURA_DUMMY:
                if (m_spellProto->SpellVisual == 3582 && m_spellProto->SpellIconID == 150) // Vampiric Embrace
                {
                    m_debuffLimitScore = 3;
                    return;
                }
                break;
        }
        if (currEffectScore > m_debuffLimitScore)
            m_debuffLimitScore = currEffectScore;
    }

    if (IsTriggered())
    {
        if (m_debuffLimitScore > 2)
            m_debuffLimitScore = 2;
        else
            m_debuffLimitScore = 0;
    }
    else if (m_isChanneled && m_debuffLimitScore < 1)
        m_debuffLimitScore = 1;
}

// Fix premiers tics
void Aura::CalculatePeriodic(Player* modOwner, bool create)
{
    //m_modifier.periodictime = GetSpellProto()->EffectAmplitude[m_effIndex];

        SpellTargetCheckTypes selectionType = TARGET_CHECK_DEFAULT;
        switch (spellEffectInfo.Effect)
        {
            case SPELL_EFFECT_APPLY_AREA_AURA_PARTY:
            case SPELL_EFFECT_APPLY_AREA_AURA_PARTY_NONRANDOM:
                selectionType = TARGET_CHECK_PARTY;
                break;
            case SPELL_EFFECT_APPLY_AREA_AURA_RAID:
                selectionType = TARGET_CHECK_RAID;
                break;
            case SPELL_EFFECT_APPLY_AREA_AURA_FRIEND:
                selectionType = TARGET_CHECK_ALLY;
                break;
            case SPELL_EFFECT_APPLY_AREA_AURA_ENEMY:
                selectionType = TARGET_CHECK_ENEMY;
                extraSearchRadius = radius > 0.0f ? EXTRA_CELL_SEARCH_RADIUS : 0.0f;
                break;
            case SPELL_EFFECT_APPLY_AREA_AURA_PET:
                if (!condList || sConditionMgr->IsObjectMeetToConditions(GetUnitOwner(), ref, *condList))
                    units.push_back(GetUnitOwner());
                [[fallthrough]];
            case SPELL_EFFECT_APPLY_AREA_AURA_OWNER:
            {
                if (Unit* owner = GetUnitOwner()->GetCharmerOrOwner())
                    if (GetUnitOwner()->IsWithinDistInMap(owner, radius))
                        if (!condList || sConditionMgr->IsObjectMeetToConditions(owner, ref, *condList))
                            units.push_back(owner);
                break;
            }
            case SPELL_EFFECT_APPLY_AURA_ON_PET:
            {
                if (Unit* pet = ObjectAccessor::GetUnit(*GetUnitOwner(), GetUnitOwner()->GetPetGUID()))
                    if (!condList || sConditionMgr->IsObjectMeetToConditions(pet, ref, *condList))
                        units.push_back(pet);
                break;
            }
            case SPELL_EFFECT_APPLY_AREA_AURA_SUMMONS:
            {
                if (!condList || sConditionMgr->IsObjectMeetToConditions(GetUnitOwner(), ref, *condList))
                    units.push_back(GetUnitOwner());

                selectionType = TARGET_CHECK_SUMMONED;
                break;
            }
            default:
                break;
        }

        if (selectionType != TARGET_CHECK_DEFAULT)
        {
            Trinity::WorldObjectSpellAreaTargetCheck check(radius, GetUnitOwner(), ref, GetUnitOwner(), m_spellInfo, selectionType, condList, TARGET_OBJECT_TYPE_UNIT);
            Trinity::UnitListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> searcher(GetUnitOwner(), units, check);
            Cell::VisitAllObjects(GetUnitOwner(), searcher, radius + extraSearchRadius);

            // by design WorldObjectSpellAreaTargetCheck allows not-in-world units (for spells) but for auras it is not acceptable
            units.erase(std::remove_if(units.begin(), units.end(), [this](Unit* unit) { return !unit->IsSelfOrInSameMap(GetUnitOwner()); }), units.end());
        }

        for (Unit* unit : units)
            targets[unit] |= 1 << spellEffectInfo.EffectIndex;
    }
}
    // prepare periodics
    switch (GetSpellProto()->EffectApplyAuraName[m_effIndex])
    {
        case SPELL_AURA_PERIODIC_DAMAGE:
        case SPELL_AURA_PERIODIC_HEAL:
        case SPELL_AURA_PERIODIC_ENERGIZE:
        case SPELL_AURA_OBS_MOD_HEALTH:
        case SPELL_AURA_PERIODIC_LEECH:
        case SPELL_AURA_PERIODIC_HEALTH_FUNNEL:
        case SPELL_AURA_PERIODIC_MANA_LEECH:
        case SPELL_AURA_PERIODIC_DAMAGE_PERCENT:
        case SPELL_AURA_POWER_BURN_MANA:
        case SPELL_AURA_PERIODIC_TRIGGER_SPELL:
            m_isPeriodic = true;
            break;
        default:
            break;
    }

    if (!m_isPeriodic)
        return;

    // Apply casting time mods
    if (m_modifier.periodictime && modOwner)
    {
        // Apply periodic time mod
        modOwner->ApplySpellMod(GetId(), SPELLMOD_ACTIVATION_TIME, m_modifier.periodictime);
    }

    // Totem griffes de pierre
    if (GetSpellProto()->SpellVisual == 0 && GetSpellProto()->SpellIconID == 689)
        return;

    switch (GetId())
    {
        case 8145:  // Tremor Tortem Passive
        case 6474:  // Earthbind Totem Passive
        case 8179:  // Grounding Totem Passive
        case 8172:  // Disease Cleansing Totem Passive
        case 8167:  // Poison Cleansing Totem Passive
        case 8515:  // Windfury Totem Passive (Rank 1)
        case 10609: // Windfury Totem Passive (Rank 2)
        case 10612: // Windfury Totem Passive (Rank 3)
        case 13797: // Immolation Trap Effect (Rank 1)
        case 14298: // Immolation Trap Effect (Rank 2)
        case 14299: // Immolation Trap Effect (Rank 3)
        case 14300: // Immolation Trap Effect (Rank 4)
        case 14301: // Immolation Trap Effect (Rank 5)
        case 23184: // Mark of Frost
        case 25041: // Mark of Nature
            break;
        default:
            m_periodicTimer = m_modifier.periodictime;
    }
}

// Battements de coeur (chance de briser les CC)
void SpellAuraHolder::CalculateHeartBeat(Unit* caster, Unit* target)
{
    if (_pveHeartBeatData)
    {
        delete _pveHeartBeatData;
        _pveHeartBeatData = nullptr;
    }

    _heartBeatRandValue = 0;

    // Ni les sorts permanents, ni les sorts positifs ne sont affectes.
    // Check si positif fait dans Aura::Aura car ici le dernier Aura ajoute n'est pas encore dans 'm_auras'
    if (!m_permanent && m_maxDuration > 10000)
    {
        if (m_spellProto->Attributes & SPELL_ATTR_DIMINISHING_RETURNS
                // Exception pour la coiffe de controle gnome/Heaume-fusee gobelin
                || m_spellProto->Id == 13181 || m_spellProto->Id == 13327)
        {
            // Pour les joueurs
            if (target->GetCharmerOrOwnerPlayerOrPlayerItself())
                _heartBeatRandValue = rand_norm_f() * 100.0f;
        }
        // En PvE. Ne concerne pas certains sorts avec DR (fear geres avec dmg par exemple).
        if (caster && target->GetTypeId() == TYPEID_UNIT && m_spellProto->IsPvEHeartBeat())
        {
            _pveHeartBeatData = new HeartBeatData;
            _pveHeartBeatData->timer = 5000;
            _pveHeartBeatData->hitChance = caster->MagicSpellHitChance(target, m_spellProto);
        }
    }
}

void Aura::HandleInterruptRegen(bool apply, bool real)
{
    if (!real)
        return;
    if (!apply)
        return;
    GetTarget()->SetInCombatState(false);
}

void UnitAura::AddStaticApplication(Unit* target, uint32 effMask)
{
    // only valid for non-area auras
    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
    {
        if ((effMask & (1 << spellEffectInfo.EffectIndex)) && !spellEffectInfo.IsEffect(SPELL_EFFECT_APPLY_AURA))
            effMask &= ~(1 << spellEffectInfo.EffectIndex);
    }

    if (!effMask)
        return;

    _staticApplications[target->GetGUID()] |= effMask;
// Un nouvel aura ...
void Aura::HandleAuraAuraSpell(bool apply, bool real)
{
    Unit* target = GetTarget();
    if (!real || !target)
        return;
    uint32 spell = GetSpellProto()->EffectTriggerSpell[m_effIndex];
    if (apply)
        target->AddAura(spell, ADD_AURA_PASSIVE, target);
    else
        target->RemoveAurasDueToSpell(spell);
}

DynObjAura::DynObjAura(AuraCreateInfo const& createInfo)
    : Aura(createInfo)
{
    LoadScripts();
    ASSERT(GetDynobjOwner());
    ASSERT(GetDynobjOwner()->IsInWorld());
    ASSERT(createInfo.Caster);
    ASSERT(GetDynobjOwner()->GetMap() == createInfo.Caster->GetMap());
    _InitEffects(createInfo._auraEffectMask, createInfo.Caster, createInfo.BaseAmount);
    GetDynobjOwner()->SetAura(this);
}

// Auras exclusifs
/*
Sorts d'exemple:
11364 (+50), 21849 (+15)
*/

bool _IsExclusiveSpellAura(SpellEntry const* spellproto, SpellEffectIndex eff, AuraType auraname)
{
    // Flametongue Totem / Totem of Wrath / Strength of Earth Totem / Fel Intelligence / Leader of the Pack
    // Moonkin Aura / Mana Spring Totem / Tree of Life Aura / Improved Devotion Aura / Improved Icy Talons / Trueshot Aura
    // Improved Moonkin Form / Sanctified Retribution Aura / Blood Pact
    if (spellproto->Effect[eff] == SPELL_EFFECT_APPLY_AREA_AURA_RAID)
        return false;

    // Exceptions - se stack avec tout.
    switch (spellproto->Id)
    {
        // Terres foudroyees et Zanza
        case 10693:
        case 10691: // +25 esprit
        case 10668:
        case 10671: // +25 endu
        case 10667:
        case 10670: // +25 force
        case 10669:
        case 10672: // +25 agi
        case 10692:
        case 10690: // +25 intel
        case 24382:             // Buff zanza
        // Alcools
        case 25804:
        case 20875:
        case 25722:
        case 25037:
        case 22789:
        case 22790:
        case 6114:
        case 5020:
        case 5021:
        case 23179: //le proc de l'�p�e de Razorgore (+300 force) devrait se cumuler avec TOUT : ID 23179
        case 20007: //le proc Crois� devrait se cumuler avec TOUT : ID 20007
        case 20572: //Le racial Orc (ID 20572)
        case 17038: //l'Eau des Tombe-Hiver (ID 17038)
        case 16329: //le Juju's Might (ID 16329)
        case 25891: //le buff du Bijou Choc de Terre (ID : 25891)
        case 18264: // Charge du maitre (baton epique scholo)
        case 12022: // Chapeau pirate
        case 22817: // PA HT Nord
        // Aura de precision (hunt)
        case 19506:
        case 20905:
        case 20906:
        case 18262: // Pierre � Aiguiser El�mentaire (+2% crit)
        case 24932: // chef de la Meute
        case 24907: // aura S�l�nien
        case 22888: // Buff Onyxia
        case 15366: // Buff Felwood
        case 22820: // HT +3% crit sorts
        case 17628: // Supreme Power
        case 22730: // Bouffe +10 Intell
        case 18141: // Bouffe +10 Esprit
        case 18125: // Bouffe +10 Force
        case 18192: // Bouffe +10 Agility
        case 18191: // Bouffe +10 Endu
        case 25661: // Bouffe +25 Endu
        case 24427: // Diamond Flask
        case 17528: // Mighty Rage Potion
        case 23697: // Alterac Spring Water
        // Love is in the Air buffs
        case 27664:
        case 27665:
        case 27666:
        case 27669:
        case 27670:
        case 27671:
            return false;

        case 17538: // Le +crit du buff de l'Elixir de la Mangouste 17538, devrait se stack avec TOUT.
            return (eff == EFFECT_INDEX_0);
    }
    switch (spellproto->SpellFamilyName)
    {
        case SPELLFAMILY_WARLOCK:
            // Blood Pact
            if (spellproto->IsFitToFamilyMask<CF_WARLOCK_IMP_BUFFS>())
                return false;
            break;
        case SPELLFAMILY_SHAMAN:
            // Strength of Earth (ID 8076, 8162, 8163, 10441, 25362)
            if (spellproto->IsFitToFamilyMask<CF_SHAMAN_STRENGTH_OF_EARTH>())
                return false;
            break;
        case SPELLFAMILY_WARRIOR:
            // Battle Shout (ID 6673, 5242, 6192, 11549, 11550, 11551, 25289)
            if (spellproto->IsFitToFamilyMask<CF_WARRIOR_BATTLE_SHOUT>())
                return false;
            break;
        case SPELLFAMILY_PALADIN:
            // Blessing of Might (ID 19740, 19834, 19835, 19836, 19837, 19838, 25291, 25782, 25916)
            if (spellproto->IsFitToFamilyMask<CF_PALADIN_BLESSING_OF_MIGHT, CF_PALADIN_BLESSINGS>())
                return false;
            break;
        case SPELLFAMILY_HUNTER:
            // Aspect of the Hawk
            if (spellproto->IsFitToFamilyMask<CF_HUNTER_ASPECT_OF_THE_HAWK>())
                return false;
            break;
        case SPELLFAMILY_DRUID:
#if SUPPORTED_CLIENT_BUILD <= CLIENT_BUILD_1_7_1
            // World of Warcraft Client Patch 1.8.0 (2005-10-11)
            // - Multiple Druids casting Hurricane will no longer stack the slowdown effect
            if (spellproto->IsFitToFamilyMask<CF_DRUID_HURRICANE>())
                return false;
#endif
            break;
    }

void DynObjAura::Remove(AuraRemoveMode removeMode)
    // La bouffe
    if (spellproto->AttributesEx2 & SPELL_ATTR_EX2_FOOD_BUFF)
        return false;

    switch (auraname)
    {
        //case SPELL_AURA_PERIODIC_DAMAGE:
        //case SPELL_AURA_DUMMY:
        //    return false;
        case SPELL_AURA_MOD_HEALING_DONE:                               // Demonic Pact
        case SPELL_AURA_MOD_DAMAGE_DONE:                                // Demonic Pact
        case SPELL_AURA_MOD_ATTACK_POWER_PCT:                           // Abomination's Might / Unleashed Rage
        case SPELL_AURA_MOD_RANGED_ATTACK_POWER_PCT:
        case SPELL_AURA_MOD_ATTACK_POWER:                               // (Greater) Blessing of Might / Battle Shout
        case SPELL_AURA_MOD_RANGED_ATTACK_POWER:
        case SPELL_AURA_MOD_POWER_REGEN:                                // (Greater) Blessing of Wisdom
        case SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN:                       // Glyph of Salvation / Pain Suppression / Safeguard ?
        case SPELL_AURA_MOD_STAT:
            return true;
        case SPELL_AURA_MOD_SPELL_CRIT_CHANCE:
            return true;
        case SPELL_AURA_MOD_ATTACKER_SPELL_CRIT_CHANCE:                 // Winter's Chill / Improved Scorch
            if (spellproto->SpellFamilyName == SPELLFAMILY_MAGE)
                return false;
            return true;
        case SPELL_AURA_MOD_RESISTANCE_EXCLUSIVE: // A gere autrement (exlusif par rapport a la resistance)
            return false;
        case SPELL_AURA_MOD_HEALING_PCT:                                // Mortal Strike / Wound Poison / Aimed Shot / Furious Attacks
            // Healing taken debuffs
            if (spellproto->EffectBasePoints[eff] < 0)
                return false;
            return true;
        case SPELL_AURA_MOD_RESISTANCE_PCT:
            // Ancestral Healing / Inspiration
            if (spellproto->SpellFamilyName == SPELLFAMILY_SHAMAN ||
                    spellproto->SpellFamilyName == SPELLFAMILY_PRIEST)
                return false;
            return true;
        case SPELL_AURA_MOD_MELEE_HASTE:
        case SPELL_AURA_MOD_DECREASE_SPEED:
            // Attack and movement speed reduction
            if (spellproto->EffectBasePoints[eff] >= 0)
                return false;
            return true;
        default:
            return false;
    }
}

void Aura::ComputeExclusive()
{
    m_exclusive = false;
    //return;
    if (GetHolder()->IsPassive())
        return;
    m_exclusive = _IsExclusiveSpellAura(GetSpellProto(), GetEffIndex(), GetModifier()->m_auraname);
}

// Results :
// - 0 : Not in the same category.
// - 1 : I am more important. I apply myself.
// - 2 : Other aura is more important. It applies.
int Aura::CheckExclusiveWith(Aura const* other) const
{
    ASSERT(IsExclusive());
    ASSERT(other);
    ASSERT(other->IsExclusive());
    if (other->GetModifier()->m_auraname != GetModifier()->m_auraname)
        return 0;
    if (other->GetModifier()->m_miscvalue != GetModifier()->m_miscvalue)
        return 0;
    if (other->GetSpellProto()->EffectItemType[other->GetEffIndex()] != GetSpellProto()->EffectItemType[GetEffIndex()])
        return 0;
    if (other->IsPositive() != IsPositive())
        return 0;

    // Other aura is better.
    if (other->GetModifier()->m_amount > GetModifier()->m_amount && GetModifier()->m_amount >= 0)
        return 2;
    else if (other->GetModifier()->m_amount < GetModifier()->m_amount && GetModifier()->m_amount < 0)
        return 2;

    return 1;
}

    for (SpellEffectInfo const& spellEffectInfo : GetSpellInfo()->GetEffects())
bool Aura::ExclusiveAuraCanApply()
{
    Unit* target = GetTarget();
    ASSERT(target);
    if (Aura* mostImportant = target->GetMostImportantAuraAfter(this, this))
    {
        if (!HasEffect(spellEffectInfo.EffectIndex))
            continue;

        // we can't use effect type like area auras to determine check type, check targets
        SpellTargetCheckTypes selectionType = spellEffectInfo.TargetA.GetCheckType();
        if (spellEffectInfo.TargetB.GetReferenceType() == TARGET_REFERENCE_TYPE_DEST)
            selectionType = spellEffectInfo.TargetB.GetCheckType();

        std::vector<Unit*> units;
        ConditionContainer* condList = spellEffectInfo.ImplicitTargetConditions;

        Trinity::WorldObjectSpellAreaTargetCheck check(radius, GetDynobjOwner(), dynObjOwnerCaster, dynObjOwnerCaster, m_spellInfo, selectionType, condList, TARGET_OBJECT_TYPE_UNIT);
        Trinity::UnitListSearcher<Trinity::WorldObjectSpellAreaTargetCheck> searcher(GetDynobjOwner(), units, check);
        Cell::VisitAllObjects(GetDynobjOwner(), searcher, radius);

        // by design WorldObjectSpellAreaTargetCheck allows not-in-world units (for spells) but for auras it is not acceptable
        units.erase(std::remove_if(units.begin(), units.end(), [this](Unit* unit) { return !unit->IsSelfOrInSameMap(GetDynobjOwner()); }), units.end());
        if (mostImportant->IsInUse())
        {
            sLog.outInfo("[%s:Map%u:Aura%u:AuraImportant%u] Aura::ExclusiveAuraCanApply IsInUse", target->GetName(), target->GetMapId(), GetId(), mostImportant->GetId());
            return false;
        }
        ASSERT(!mostImportant->IsInUse());
        int checkResult = CheckExclusiveWith(mostImportant);
        switch (checkResult)
        {
            case 1: // I am more important.
                // Normally 'mostImportant' being the most important in its category should be applied.
                if (!mostImportant->IsApplied())
                {
                    sLog.outInfo("[%s:Map%u:Aura%u:AuraImportant%u] Aura::ExclusiveAuraCanApply IsApplied", target->GetName(), target->GetMapId(), GetId(), mostImportant->GetId());
                    return false;
                }
                ASSERT(mostImportant->IsApplied());
                // We deactivate the other aura, and I activate.
                mostImportant->ApplyModifier(false, true, true);
                break;
            case 2: // The other aura is more important, I leave it.
                return false;
            case 0: // Impossible.
            default: // Also impossible.
                ASSERT(false);
        }
    }

    // No other aura found, I apply myself.
    return true;
}

        for (Unit* unit : units)
            targets[unit] |= 1 << spellEffectInfo.EffectIndex;
void Aura::ExclusiveAuraUnapply()
{
    Unit* target = GetTarget();
    ASSERT(target);
    // On restaure le precedent plus grand aura.
    if (Aura* mostImportant = target->GetMostImportantAuraAfter(this, this))
    {
        if (mostImportant->IsInUse())
        {
            sLog.outInfo("[%s:Map%u:Aura%u:AuraImportant%u] Aura::ExclusiveAuraUnapply IsInUse", target->GetName(), target->GetMapId(), GetId(), mostImportant->GetId());
            return;
        }
        if (mostImportant->IsApplied())
        {
            sLog.outInfo("[%s:Map%u:Aura%u:AuraImportant%u] Aura::ExclusiveAuraUnapply IsApplied", target->GetName(), target->GetMapId(), GetId(), mostImportant->GetId());
            return;
        }
        ASSERT(!mostImportant->IsInUse());
        ASSERT(!mostImportant->IsApplied());
        mostImportant->ApplyModifier(true, true, true);
    }
}
