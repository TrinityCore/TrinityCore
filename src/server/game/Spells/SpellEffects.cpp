/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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

#include "Spell.h"
#include "AccountMgr.h"
#include "Battleground.h"
#include "CellImpl.h"
#include "Common.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "DatabaseEnv.h"
#include "DynamicObject.h"
#include "Formulas.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GossipDef.h"
#include "GridNotifiers.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "LootMgr.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "OutdoorPvPMgr.h"
#include "PathGenerator.h"
#include "Pet.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "SkillExtraItems.h"
#include "SharedDefines.h"
#include "SocialMgr.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "TemporarySummon.h"
#include "Totem.h"
#include "UpdateMask.h"
#include "Unit.h"
#include "Util.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"

SpellEffectHandlerFn SpellEffectHandlers[TOTAL_SPELL_EFFECTS] =
{
    &Spell::EffectNULL,                                     //  0
    &Spell::EffectInstaKill,                                //  1 SPELL_EFFECT_INSTAKILL
    &Spell::EffectSchoolDMG,                                //  2 SPELL_EFFECT_SCHOOL_DAMAGE
    &Spell::EffectDummy,                                    //  3 SPELL_EFFECT_DUMMY
    &Spell::EffectUnused,                                   //  4 SPELL_EFFECT_PORTAL_TELEPORT          unused
    &Spell::EffectTeleportUnits,                            //  5 SPELL_EFFECT_TELEPORT_UNITS
    &Spell::EffectApplyAura,                                //  6 SPELL_EFFECT_APPLY_AURA
    &Spell::EffectEnvironmentalDMG,                         //  7 SPELL_EFFECT_ENVIRONMENTAL_DAMAGE
    &Spell::EffectPowerDrain,                               //  8 SPELL_EFFECT_POWER_DRAIN
    &Spell::EffectHealthLeech,                              //  9 SPELL_EFFECT_HEALTH_LEECH
    &Spell::EffectHeal,                                     // 10 SPELL_EFFECT_HEAL
    &Spell::EffectBind,                                     // 11 SPELL_EFFECT_BIND
    &Spell::EffectNULL,                                     // 12 SPELL_EFFECT_PORTAL
    &Spell::EffectUnused,                                   // 13 SPELL_EFFECT_RITUAL_BASE              unused
    &Spell::EffectUnused,                                   // 14 SPELL_EFFECT_RITUAL_SPECIALIZE        unused
    &Spell::EffectUnused,                                   // 15 SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL   unused
    &Spell::EffectQuestComplete,                            // 16 SPELL_EFFECT_QUEST_COMPLETE
    &Spell::EffectWeaponDmg,                                // 17 SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL
    &Spell::EffectResurrect,                                // 18 SPELL_EFFECT_RESURRECT
    &Spell::EffectAddExtraAttacks,                          // 19 SPELL_EFFECT_ADD_EXTRA_ATTACKS
    &Spell::EffectUnused,                                   // 20 SPELL_EFFECT_DODGE                    one spell: Dodge
    &Spell::EffectUnused,                                   // 21 SPELL_EFFECT_EVADE                    one spell: Evade (DND)
    &Spell::EffectParry,                                    // 22 SPELL_EFFECT_PARRY
    &Spell::EffectBlock,                                    // 23 SPELL_EFFECT_BLOCK                    one spell: Block
    &Spell::EffectCreateItem,                               // 24 SPELL_EFFECT_CREATE_ITEM
    &Spell::EffectUnused,                                   // 25 SPELL_EFFECT_WEAPON
    &Spell::EffectUnused,                                   // 26 SPELL_EFFECT_DEFENSE                  one spell: Defense
    &Spell::EffectPersistentAA,                             // 27 SPELL_EFFECT_PERSISTENT_AREA_AURA
    &Spell::EffectSummonType,                               // 28 SPELL_EFFECT_SUMMON
    &Spell::EffectLeap,                                     // 29 SPELL_EFFECT_LEAP
    &Spell::EffectEnergize,                                 // 30 SPELL_EFFECT_ENERGIZE
    &Spell::EffectWeaponDmg,                                // 31 SPELL_EFFECT_WEAPON_PERCENT_DAMAGE
    &Spell::EffectTriggerMissileSpell,                      // 32 SPELL_EFFECT_TRIGGER_MISSILE
    &Spell::EffectOpenLock,                                 // 33 SPELL_EFFECT_OPEN_LOCK
    &Spell::EffectSummonChangeItem,                         // 34 SPELL_EFFECT_SUMMON_CHANGE_ITEM
    &Spell::EffectUnused,                                   // 35 SPELL_EFFECT_APPLY_AREA_AURA_PARTY
    &Spell::EffectLearnSpell,                               // 36 SPELL_EFFECT_LEARN_SPELL
    &Spell::EffectUnused,                                   // 37 SPELL_EFFECT_SPELL_DEFENSE            one spell: SPELLDEFENSE (DND)
    &Spell::EffectDispel,                                   // 38 SPELL_EFFECT_DISPEL
    &Spell::EffectUnused,                                   // 39 SPELL_EFFECT_LANGUAGE
    &Spell::EffectDualWield,                                // 40 SPELL_EFFECT_DUAL_WIELD
    &Spell::EffectJump,                                     // 41 SPELL_EFFECT_JUMP
    &Spell::EffectJumpDest,                                 // 42 SPELL_EFFECT_JUMP_DEST
    &Spell::EffectTeleUnitsFaceCaster,                      // 43 SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER
    &Spell::EffectLearnSkill,                               // 44 SPELL_EFFECT_SKILL_STEP
    &Spell::EffectAddHonor,                                 // 45 SPELL_EFFECT_ADD_HONOR                honor/pvp related
    &Spell::EffectUnused,                                   // 46 SPELL_EFFECT_SPAWN clientside, unit appears as if it was just spawned
    &Spell::EffectTradeSkill,                               // 47 SPELL_EFFECT_TRADE_SKILL
    &Spell::EffectUnused,                                   // 48 SPELL_EFFECT_STEALTH                  one spell: Base Stealth
    &Spell::EffectUnused,                                   // 49 SPELL_EFFECT_DETECT                   one spell: Detect
    &Spell::EffectTransmitted,                              // 50 SPELL_EFFECT_TRANS_DOOR
    &Spell::EffectUnused,                                   // 51 SPELL_EFFECT_FORCE_CRITICAL_HIT       unused
    &Spell::EffectUnused,                                   // 52 SPELL_EFFECT_GUARANTEE_HIT            one spell: zzOLDCritical Shot
    &Spell::EffectEnchantItemPerm,                          // 53 SPELL_EFFECT_ENCHANT_ITEM
    &Spell::EffectEnchantItemTmp,                           // 54 SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY
    &Spell::EffectTameCreature,                             // 55 SPELL_EFFECT_TAMECREATURE
    &Spell::EffectSummonPet,                                // 56 SPELL_EFFECT_SUMMON_PET
    &Spell::EffectLearnPetSpell,                            // 57 SPELL_EFFECT_LEARN_PET_SPELL
    &Spell::EffectWeaponDmg,                                // 58 SPELL_EFFECT_WEAPON_DAMAGE
    &Spell::EffectCreateRandomItem,                         // 59 SPELL_EFFECT_CREATE_RANDOM_ITEM       create item base at spell specific loot
    &Spell::EffectProficiency,                              // 60 SPELL_EFFECT_PROFICIENCY
    &Spell::EffectSendEvent,                                // 61 SPELL_EFFECT_SEND_EVENT
    &Spell::EffectPowerBurn,                                // 62 SPELL_EFFECT_POWER_BURN
    &Spell::EffectThreat,                                   // 63 SPELL_EFFECT_THREAT
    &Spell::EffectTriggerSpell,                             // 64 SPELL_EFFECT_TRIGGER_SPELL
    &Spell::EffectUnused,                                   // 65 SPELL_EFFECT_APPLY_AREA_AURA_RAID
    &Spell::EffectRechargeManaGem,                          // 66 SPELL_EFFECT_CREATE_MANA_GEM          (possibly recharge it, misc - is item ID)
    &Spell::EffectHealMaxHealth,                            // 67 SPELL_EFFECT_HEAL_MAX_HEALTH
    &Spell::EffectInterruptCast,                            // 68 SPELL_EFFECT_INTERRUPT_CAST
    &Spell::EffectDistract,                                 // 69 SPELL_EFFECT_DISTRACT
    &Spell::EffectPull,                                     // 70 SPELL_EFFECT_PULL                     one spell: Distract Move
    &Spell::EffectPickPocket,                               // 71 SPELL_EFFECT_PICKPOCKET
    &Spell::EffectAddFarsight,                              // 72 SPELL_EFFECT_ADD_FARSIGHT
    &Spell::EffectUntrainTalents,                           // 73 SPELL_EFFECT_UNTRAIN_TALENTS
    &Spell::EffectApplyGlyph,                               // 74 SPELL_EFFECT_APPLY_GLYPH
    &Spell::EffectHealMechanical,                           // 75 SPELL_EFFECT_HEAL_MECHANICAL          one spell: Mechanical Patch Kit
    &Spell::EffectSummonObjectWild,                         // 76 SPELL_EFFECT_SUMMON_OBJECT_WILD
    &Spell::EffectScriptEffect,                             // 77 SPELL_EFFECT_SCRIPT_EFFECT
    &Spell::EffectUnused,                                   // 78 SPELL_EFFECT_ATTACK
    &Spell::EffectSanctuary,                                // 79 SPELL_EFFECT_SANCTUARY
    &Spell::EffectAddComboPoints,                           // 80 SPELL_EFFECT_ADD_COMBO_POINTS
    &Spell::EffectUnused,                                   // 81 SPELL_EFFECT_CREATE_HOUSE             one spell: Create House (TEST)
    &Spell::EffectNULL,                                     // 82 SPELL_EFFECT_BIND_SIGHT
    &Spell::EffectDuel,                                     // 83 SPELL_EFFECT_DUEL
    &Spell::EffectStuck,                                    // 84 SPELL_EFFECT_STUCK
    &Spell::EffectSummonPlayer,                             // 85 SPELL_EFFECT_SUMMON_PLAYER
    &Spell::EffectActivateObject,                           // 86 SPELL_EFFECT_ACTIVATE_OBJECT
    &Spell::EffectGameObjectDamage,                         // 87 SPELL_EFFECT_GAMEOBJECT_DAMAGE
    &Spell::EffectGameObjectRepair,                         // 88 SPELL_EFFECT_GAMEOBJECT_REPAIR
    &Spell::EffectGameObjectSetDestructionState,            // 89 SPELL_EFFECT_GAMEOBJECT_SET_DESTRUCTION_STATE
    &Spell::EffectKillCreditPersonal,                       // 90 SPELL_EFFECT_KILL_CREDIT              Kill credit but only for single person
    &Spell::EffectUnused,                                   // 91 SPELL_EFFECT_THREAT_ALL               one spell: zzOLDBrainwash
    &Spell::EffectEnchantHeldItem,                          // 92 SPELL_EFFECT_ENCHANT_HELD_ITEM
    &Spell::EffectForceDeselect,                            // 93 SPELL_EFFECT_FORCE_DESELECT
    &Spell::EffectSelfResurrect,                            // 94 SPELL_EFFECT_SELF_RESURRECT
    &Spell::EffectSkinning,                                 // 95 SPELL_EFFECT_SKINNING
    &Spell::EffectCharge,                                   // 96 SPELL_EFFECT_CHARGE
    &Spell::EffectCastButtons,                              // 97 SPELL_EFFECT_CAST_BUTTON (totem bar since 3.2.2a)
    &Spell::EffectKnockBack,                                // 98 SPELL_EFFECT_KNOCK_BACK
    &Spell::EffectDisEnchant,                               // 99 SPELL_EFFECT_DISENCHANT
    &Spell::EffectInebriate,                                //100 SPELL_EFFECT_INEBRIATE
    &Spell::EffectFeedPet,                                  //101 SPELL_EFFECT_FEED_PET
    &Spell::EffectDismissPet,                               //102 SPELL_EFFECT_DISMISS_PET
    &Spell::EffectReputation,                               //103 SPELL_EFFECT_REPUTATION
    &Spell::EffectSummonObject,                             //104 SPELL_EFFECT_SUMMON_OBJECT_SLOT1
    &Spell::EffectSummonObject,                             //105 SPELL_EFFECT_SUMMON_OBJECT_SLOT2
    &Spell::EffectSummonObject,                             //106 SPELL_EFFECT_SUMMON_OBJECT_SLOT3
    &Spell::EffectSummonObject,                             //107 SPELL_EFFECT_SUMMON_OBJECT_SLOT4
    &Spell::EffectDispelMechanic,                           //108 SPELL_EFFECT_DISPEL_MECHANIC
    &Spell::EffectResurrectPet,                             //109 SPELL_EFFECT_RESURRECT_PET
    &Spell::EffectDestroyAllTotems,                         //110 SPELL_EFFECT_DESTROY_ALL_TOTEMS
    &Spell::EffectDurabilityDamage,                         //111 SPELL_EFFECT_DURABILITY_DAMAGE
    &Spell::EffectUnused,                                   //112 SPELL_EFFECT_112
    &Spell::EffectResurrectNew,                             //113 SPELL_EFFECT_RESURRECT_NEW
    &Spell::EffectTaunt,                                    //114 SPELL_EFFECT_ATTACK_ME
    &Spell::EffectDurabilityDamagePCT,                      //115 SPELL_EFFECT_DURABILITY_DAMAGE_PCT
    &Spell::EffectSkinPlayerCorpse,                         //116 SPELL_EFFECT_SKIN_PLAYER_CORPSE       one spell: Remove Insignia, bg usage, required special corpse flags...
    &Spell::EffectSpiritHeal,                               //117 SPELL_EFFECT_SPIRIT_HEAL              one spell: Spirit Heal
    &Spell::EffectSkill,                                    //118 SPELL_EFFECT_SKILL                    professions and more
    &Spell::EffectUnused,                                   //119 SPELL_EFFECT_APPLY_AREA_AURA_PET
    &Spell::EffectUnused,                                   //120 SPELL_EFFECT_TELEPORT_GRAVEYARD       one spell: Graveyard Teleport Test
    &Spell::EffectWeaponDmg,                                //121 SPELL_EFFECT_NORMALIZED_WEAPON_DMG
    &Spell::EffectUnused,                                   //122 SPELL_EFFECT_122                      unused
    &Spell::EffectSendTaxi,                                 //123 SPELL_EFFECT_SEND_TAXI                taxi/flight related (misc value is taxi path id)
    &Spell::EffectPullTowards,                              //124 SPELL_EFFECT_PULL_TOWARDS
    &Spell::EffectModifyThreatPercent,                      //125 SPELL_EFFECT_MODIFY_THREAT_PERCENT
    &Spell::EffectStealBeneficialBuff,                      //126 SPELL_EFFECT_STEAL_BENEFICIAL_BUFF    spell steal effect?
    &Spell::EffectProspecting,                              //127 SPELL_EFFECT_PROSPECTING              Prospecting spell
    &Spell::EffectUnused,                                   //128 SPELL_EFFECT_APPLY_AREA_AURA_FRIEND
    &Spell::EffectUnused,                                   //129 SPELL_EFFECT_APPLY_AREA_AURA_ENEMY
    &Spell::EffectRedirectThreat,                           //130 SPELL_EFFECT_REDIRECT_THREAT
    &Spell::EffectPlaySound,                                //131 SPELL_EFFECT_PLAY_SOUND               sound id in misc value (SoundEntries.dbc)
    &Spell::EffectPlayMusic,                                //132 SPELL_EFFECT_PLAY_MUSIC               sound id in misc value (SoundEntries.dbc)
    &Spell::EffectUnlearnSpecialization,                    //133 SPELL_EFFECT_UNLEARN_SPECIALIZATION   unlearn profession specialization
    &Spell::EffectKillCredit,                               //134 SPELL_EFFECT_KILL_CREDIT              misc value is creature entry
    &Spell::EffectNULL,                                     //135 SPELL_EFFECT_CALL_PET
    &Spell::EffectHealPct,                                  //136 SPELL_EFFECT_HEAL_PCT
    &Spell::EffectEnergizePct,                              //137 SPELL_EFFECT_ENERGIZE_PCT
    &Spell::EffectLeapBack,                                 //138 SPELL_EFFECT_LEAP_BACK                Leap back
    &Spell::EffectQuestClear,                               //139 SPELL_EFFECT_CLEAR_QUEST              Reset quest status (miscValue - quest ID)
    &Spell::EffectForceCast,                                //140 SPELL_EFFECT_FORCE_CAST
    &Spell::EffectForceCast,                                //141 SPELL_EFFECT_FORCE_CAST_WITH_VALUE
    &Spell::EffectTriggerSpell,                             //142 SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE
    &Spell::EffectUnused,                                   //143 SPELL_EFFECT_APPLY_AREA_AURA_OWNER
    &Spell::EffectKnockBack,                                //144 SPELL_EFFECT_KNOCK_BACK_DEST
    &Spell::EffectPullTowards,                              //145 SPELL_EFFECT_PULL_TOWARDS_DEST                      Black Hole Effect
    &Spell::EffectActivateRune,                             //146 SPELL_EFFECT_ACTIVATE_RUNE
    &Spell::EffectQuestFail,                                //147 SPELL_EFFECT_QUEST_FAIL               quest fail
    &Spell::EffectTriggerMissileSpell,                      //148 SPELL_EFFECT_TRIGGER_MISSILE_SPELL_WITH_VALUE
    &Spell::EffectChargeDest,                               //149 SPELL_EFFECT_CHARGE_DEST
    &Spell::EffectQuestStart,                               //150 SPELL_EFFECT_QUEST_START
    &Spell::EffectTriggerRitualOfSummoning,                 //151 SPELL_EFFECT_TRIGGER_SPELL_2
    &Spell::EffectSummonRaFFriend,                          //152 SPELL_EFFECT_SUMMON_RAF_FRIEND        summon Refer-a-Friend
    &Spell::EffectCreateTamedPet,                           //153 SPELL_EFFECT_CREATE_TAMED_PET         misc value is creature entry
    &Spell::EffectDiscoverTaxi,                             //154 SPELL_EFFECT_DISCOVER_TAXI
    &Spell::EffectTitanGrip,                                //155 SPELL_EFFECT_TITAN_GRIP Allows you to equip two-handed axes, maces and swords in one hand, but you attack $49152s1% slower than normal.
    &Spell::EffectEnchantItemPrismatic,                     //156 SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC
    &Spell::EffectCreateItem2,                              //157 SPELL_EFFECT_CREATE_ITEM_2            create item or create item template and replace by some randon spell loot item
    &Spell::EffectMilling,                                  //158 SPELL_EFFECT_MILLING                  milling
    &Spell::EffectRenamePet,                                //159 SPELL_EFFECT_ALLOW_RENAME_PET         allow rename pet once again
    &Spell::EffectForceCast,                                //160 SPELL_EFFECT_FORCE_CAST_2
    &Spell::EffectSpecCount,                                //161 SPELL_EFFECT_TALENT_SPEC_COUNT        second talent spec (learn/revert)
    &Spell::EffectActivateSpec,                             //162 SPELL_EFFECT_TALENT_SPEC_SELECT       activate primary/secondary spec
    &Spell::EffectNULL,                                     //163 unused
    &Spell::EffectRemoveAura,                               //164 SPELL_EFFECT_REMOVE_AURA
};

void Spell::EffectNULL(SpellEffIndex /*effIndex*/)
{
    TC_LOG_DEBUG("spells", "WORLD: Spell Effect DUMMY");
}

void Spell::EffectUnused(SpellEffIndex /*effIndex*/)
{
    // NOT USED BY ANY SPELL OR USELESS OR IMPLEMENTED IN DIFFERENT WAY IN TRINITY
}

void Spell::EffectResurrectNew(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->IsAlive())
        return;

    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (!unitTarget->IsInWorld())
        return;

    Player* target = unitTarget->ToPlayer();

    if (target->IsResurrectRequested())       // already have one active request
        return;

    uint32 health = damage;
    uint32 mana = m_spellInfo->Effects[effIndex].MiscValue;
    ExecuteLogEffectResurrect(effIndex, target);
    target->SetResurrectRequestData(m_caster, health, mana, 0);
    SendResurrectRequest(target);
}

void Spell::EffectInstaKill(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive())
        return;

    if (unitTarget->GetTypeId() == TYPEID_PLAYER)
        if (unitTarget->ToPlayer()->GetCommandStatus(CHEAT_GOD))
            return;

    if (m_caster == unitTarget)                              // prevent interrupt message
        finish();

    WorldPacket data(SMSG_SPELLINSTAKILLLOG, 8+8+4);
    data << uint64(m_caster->GetGUID());
    data << uint64(unitTarget->GetGUID());
    data << uint32(m_spellInfo->Id);
    m_caster->SendMessageToSet(&data, true);

    Unit::DealDamage(unitCaster, unitTarget, unitTarget->GetHealth(), nullptr, NODAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
}

void Spell::EffectEnvironmentalDMG(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive())
        return;

    // CalcAbsorbResist already in Player::EnvironmentalDamage
    if (unitTarget->GetTypeId() == TYPEID_PLAYER)
        unitTarget->ToPlayer()->EnvironmentalDamage(DAMAGE_FIRE, damage);
    else
    {
        DamageInfo damageInfo(unitCaster, unitTarget, damage, m_spellInfo, m_spellInfo->GetSchoolMask(), SPELL_DIRECT_DAMAGE, BASE_ATTACK);
        Unit::CalcAbsorbResist(damageInfo);

        uint32 const absorb = damageInfo.GetAbsorb();
        uint32 const resist = damageInfo.GetResist();
        if (unitCaster)
            unitCaster->SendSpellNonMeleeDamageLog(unitTarget, m_spellInfo->Id, damage, m_spellInfo->GetSchoolMask(), absorb, resist, false, 0, false);
    }
}

void Spell::EffectSchoolDMG(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (unitTarget && unitTarget->IsAlive())
    {
        bool apply_direct_bonus = true;
        switch (m_spellInfo->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
            {
                // Meteor like spells (divided damage to targets)
                if (m_spellInfo->HasAttribute(SPELL_ATTR0_CU_SHARE_DAMAGE))
                {
                    uint32 count = 0;
                    for (auto ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                    {
                        if (ihit->MissCondition != SPELL_MISS_NONE)
                            continue;

                        if (ihit->EffectMask & (1 << effIndex))
                            ++count;
                    }

                    // divide to all targets
                    if (count)
                        damage /= count;
                }

                break;
            }
            case SPELLFAMILY_WARRIOR:
            {
                if (!unitCaster)
                    break;

                // Shield Slam
                if ((m_spellInfo->SpellFamilyFlags[1] & 0x200) && m_spellInfo->GetCategory() == 1209)
                {
                    uint8 level = unitCaster->GetLevel();
                    uint32 block_value = unitCaster->GetShieldBlockValue(uint32(float(level) * 24.5f), uint32(float(level) * 34.5f));
                    damage += int32(unitCaster->ApplyEffectModifiers(m_spellInfo, effIndex, float(block_value)));
                }
                // Victory Rush
                else if (m_spellInfo->SpellFamilyFlags[1] & 0x100)
                    ApplyPct(damage, unitCaster->GetTotalAttackPowerValue(BASE_ATTACK));
                // Shockwave
                else if (m_spellInfo->Id == 46968)
                {
                    int32 pct = unitCaster->CalculateSpellDamage(m_spellInfo, EFFECT_2);
                    if (pct > 0)
                        damage += int32(CalculatePct(unitCaster->GetTotalAttackPowerValue(BASE_ATTACK), pct));
                    break;
                }
                break;
            }
            case SPELLFAMILY_WARLOCK:
            {
                if (!unitCaster)
                    break;

                // Incinerate Rank 1 & 2
                if ((m_spellInfo->SpellFamilyFlags[1] & 0x000040) && m_spellInfo->SpellIconID == 2128)
                {
                    // Incinerate does more dmg (dmg*0.25) if the target have Immolate debuff.
                    // Check aura state for speed but aura state set not only for Immolate spell
                    if (unitTarget->HasAuraState(AURA_STATE_CONFLAGRATE))
                    {
                        if (unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x4, 0, 0))
                            damage += damage / 4;
                    }
                }
                // Conflagrate - consumes Immolate or Shadowflame
                else if (m_spellInfo->TargetAuraState == AURA_STATE_CONFLAGRATE)
                {
                    AuraEffect const* aura = nullptr;                // found req. aura for damage calculation

                    Unit::AuraEffectList const& mPeriodic = unitTarget->GetAuraEffectsByType(SPELL_AURA_PERIODIC_DAMAGE);
                    for (Unit::AuraEffectList::const_iterator i = mPeriodic.begin(); i != mPeriodic.end(); ++i)
                    {
                        // for caster applied auras only
                        if ((*i)->GetSpellInfo()->SpellFamilyName != SPELLFAMILY_WARLOCK ||
                            (*i)->GetCasterGUID() != unitCaster->GetGUID())
                            continue;

                        // Immolate
                        if ((*i)->GetSpellInfo()->SpellFamilyFlags[0] & 0x4)
                        {
                            aura = *i;                      // it selected always if exist
                            break;
                        }

                        // Shadowflame
                        if ((*i)->GetSpellInfo()->SpellFamilyFlags[2] & 0x00000002)
                            aura = *i;                      // remember but wait possible Immolate as primary priority
                    }

                    // found Immolate or Shadowflame
                    if (aura)
                    {
                        // Calculate damage of Immolate/Shadowflame tick
                        int32 pdamage = aura->GetAmount();
                        pdamage = unitTarget->SpellDamageBonusTaken(unitCaster, aura->GetSpellInfo(), pdamage, DOT);

                        // And multiply by amount of ticks to get damage potential
                        pdamage *= aura->GetSpellInfo()->GetMaxTicks();

                        int32 pct_dir = unitCaster->CalculateSpellDamage(m_spellInfo, EFFECT_1);
                        damage += CalculatePct(pdamage, pct_dir);

                        int32 pct_dot = unitCaster->CalculateSpellDamage(m_spellInfo, EFFECT_2);
                        int32 const dotBasePoints = CalculatePct(pdamage, pct_dot);

                        ASSERT(m_spellInfo->GetMaxTicks() > 0);
                        m_spellValue->EffectBasePoints[EFFECT_1] = dotBasePoints / m_spellInfo->GetMaxTicks();

                        apply_direct_bonus = false;
                        // Glyph of Conflagrate
                        if (!unitCaster->HasAura(56235))
                            unitTarget->RemoveAurasDueToSpell(aura->GetId(), unitCaster->GetGUID());

                        break;
                    }
                }
                // Shadow Bite
                else if (m_spellInfo->SpellFamilyFlags[1] & 0x400000)
                {
                    if (unitCaster->GetTypeId() == TYPEID_UNIT && unitCaster->IsPet())
                    {
                        if (Player* owner = unitCaster->GetOwner()->ToPlayer())
                        {
                            if (AuraEffect* aurEff = owner->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_WARLOCK, 214, 0))
                            {
                                int32 bp0 = aurEff->GetId() == 54037 ? 4 : 8;
                                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                                args.AddSpellMod(SPELLVALUE_BASE_POINT0, bp0);
                                unitCaster->CastSpell(nullptr, 54425, args);
                            }
                        }
                    }
                }
                break;
            }
            case SPELLFAMILY_PRIEST:
            {
                if (!unitCaster)
                    break;

                // Improved Mind Blast (Mind Blast in shadow form bonus)
                if (unitCaster->GetShapeshiftForm() == FORM_SHADOW && (m_spellInfo->SpellFamilyFlags[0] & 0x00002000))
                {
                    Unit::AuraEffectList const& ImprMindBlast = unitCaster->GetAuraEffectsByType(SPELL_AURA_ADD_FLAT_MODIFIER);
                    for (Unit::AuraEffectList::const_iterator i = ImprMindBlast.begin(); i != ImprMindBlast.end(); ++i)
                    {
                        if ((*i)->GetSpellInfo()->SpellFamilyName == SPELLFAMILY_PRIEST &&
                            ((*i)->GetSpellInfo()->SpellIconID == 95))
                        {
                            // Mind Trauma
                            int32 const chance = (*i)->GetSpellInfo()->Effects[EFFECT_1].CalcValue(unitCaster);
                            if (roll_chance_i(chance))
                                unitCaster->CastSpell(unitTarget, 48301, true);
                            break;
                        }
                    }
                }
                break;
            }
            case SPELLFAMILY_DRUID:
            {
                if (!unitCaster)
                    break;

                // Ferocious Bite
                if (unitCaster->GetTypeId() == TYPEID_PLAYER && (m_spellInfo->SpellFamilyFlags[0] & 0x000800000) && m_spellInfo->SpellVisual[0] == 6587)
                {
                    // converts each extra point of energy into ($f1+$AP/410) additional damage
                    float ap = unitCaster->GetTotalAttackPowerValue(BASE_ATTACK);
                    float multiple = ap / 410 + m_spellInfo->Effects[effIndex].DamageMultiplier;
                    int32 energy = -(unitCaster->ModifyPower(POWER_ENERGY, -30));
                    damage += int32(energy * multiple);
                    damage += int32(CalculatePct(unitCaster->ToPlayer()->GetComboPoints() * ap, 7));
                }
                // Wrath
                else if (m_spellInfo->SpellFamilyFlags[0] & 0x00000001)
                {
                    // Improved Insect Swarm
                    if (AuraEffect const* aurEff = unitCaster->GetDummyAuraEffect(SPELLFAMILY_DRUID, 1771, 0))
                        if (unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x00200000, 0, 0))
                            AddPct(damage, aurEff->GetAmount());
                }
                break;
            }
            case SPELLFAMILY_ROGUE:
            {
                if (!unitCaster)
                    break;

                // Envenom
                if (m_spellInfo->SpellFamilyFlags[1] & 0x00000008)
                {
                    if (Player* player = unitCaster->ToPlayer())
                    {
                        // consume from stack dozes not more that have combo-points
                        if (uint32 combo = player->GetComboPoints())
                        {
                            // Lookup for Deadly poison (only attacker applied)
                            if (AuraEffect const* aurEff = unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_ROGUE, 0x00010000, 0, 0, unitCaster->GetGUID()))
                            {
                                // count consumed deadly poison doses at target
                                bool needConsume = true;
                                uint32 spellId = aurEff->GetId();

                                uint32 doses = aurEff->GetBase()->GetStackAmount();
                                if (doses > combo)
                                    doses = combo;

                                // Master Poisoner
                                Unit::AuraEffectList const& auraList = player->GetAuraEffectsByType(SPELL_AURA_MOD_AURA_DURATION_BY_DISPEL_NOT_STACK);
                                for (Unit::AuraEffectList::const_iterator iter = auraList.begin(); iter != auraList.end(); ++iter)
                                {
                                    if ((*iter)->GetSpellInfo()->SpellFamilyName == SPELLFAMILY_ROGUE && (*iter)->GetSpellInfo()->SpellIconID == 1960)
                                    {
                                        uint32 chance = (*iter)->GetSpellInfo()->Effects[EFFECT_2].CalcValue(unitCaster);

                                        if (chance && roll_chance_i(chance))
                                            needConsume = false;

                                        break;
                                    }
                                }

                                if (needConsume)
                                    for (uint32 i = 0; i < doses; ++i)
                                        unitTarget->RemoveAuraFromStack(spellId, unitCaster->GetGUID());

                                damage *= doses;
                                damage += int32(player->GetTotalAttackPowerValue(BASE_ATTACK) * 0.09f * combo);
                            }

                            // Eviscerate and Envenom Bonus Damage (item set effect)
                            if (unitCaster->HasAura(37169))
                                damage += combo * 40;
                        }
                    }
                }
                // Eviscerate
                else if (m_spellInfo->SpellFamilyFlags[0] & 0x00020000)
                {
                    if (Player* player = unitCaster->ToPlayer())
                    {
                        if (uint32 combo = player->GetComboPoints())
                        {
                            float ap = unitCaster->GetTotalAttackPowerValue(BASE_ATTACK);
                            damage += std::lroundf(ap * combo * 0.07f);

                            // Eviscerate and Envenom Bonus Damage (item set effect)
                            if (unitCaster->HasAura(37169))
                                damage += combo*40;
                        }
                    }
                }
                break;
            }
            case SPELLFAMILY_HUNTER:
            {
                if (!unitCaster)
                    break;

                //Gore
                if (m_spellInfo->SpellIconID == 1578)
                {
                    if (unitCaster->HasAura(57627))           // Charge 6 sec post-affect
                        damage *= 2;
                }
                // Steady Shot
                else if (m_spellInfo->SpellFamilyFlags[1] & 0x1)
                {
                    bool found = false;
                    // check dazed affect
                    Unit::AuraEffectList const& decSpeedList = unitTarget->GetAuraEffectsByType(SPELL_AURA_MOD_DECREASE_SPEED);
                    for (Unit::AuraEffectList::const_iterator iter = decSpeedList.begin(); iter != decSpeedList.end(); ++iter)
                    {
                        if ((*iter)->GetSpellInfo()->SpellIconID == 15 && (*iter)->GetSpellInfo()->Dispel == 0)
                        {
                            found = true;
                            break;
                        }
                    }

                    /// @todo should this be put on taken but not done?
                    if (found)
                        damage += m_spellInfo->Effects[EFFECT_1].CalcValue();

                    if (Player* caster = unitCaster->ToPlayer())
                    {
                        // Add Ammo and Weapon damage plus RAP * 0.1
                        float dmg_min = 0.f;
                        float dmg_max = 0.f;
                        for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
                        {
                            dmg_min += caster->GetWeaponDamageRange(RANGED_ATTACK, MINDAMAGE, i);
                            dmg_max += caster->GetWeaponDamageRange(RANGED_ATTACK, MAXDAMAGE, i);
                        }

                        if (dmg_max == 0.0f && dmg_min > dmg_max)
                            damage += int32(dmg_min);
                        else
                            damage += irand(int32(dmg_min), int32(dmg_max));
                        damage += int32(caster->GetAmmoDPS() * caster->GetAttackTime(RANGED_ATTACK) * 0.001f);
                    }
                }
                break;
            }
            case SPELLFAMILY_PALADIN:
            {
                if (!unitCaster)
                    break;

                // Hammer of the Righteous
                if (m_spellInfo->SpellFamilyFlags[1] & 0x00040000)
                {
                    float minTotal = 0.f;
                    float maxTotal = 0.f;

                    float tmpMin, tmpMax;
                    for (uint8 i = 0; i < MAX_ITEM_PROTO_DAMAGES; ++i)
                    {
                        unitCaster->CalculateMinMaxDamage(BASE_ATTACK, false, false, tmpMin, tmpMax, i);
                        minTotal += tmpMin;
                        maxTotal += tmpMax;
                    }

                    float average = (minTotal + maxTotal) / 2;
                    // Add main hand dps * effect[2] amount
                    int32 count = unitCaster->CalculateSpellDamage(m_spellInfo, EFFECT_2);
                    damage += count * int32(average * IN_MILLISECONDS) / unitCaster->GetAttackTime(BASE_ATTACK);
                    break;
                }
                // Shield of Righteousness
                if (m_spellInfo->SpellFamilyFlags[EFFECT_1] & 0x100000)
                {
                    uint8 level = unitCaster->GetLevel();
                    uint32 block_value = unitCaster->GetShieldBlockValue(uint32(float(level) * 29.5f), uint32(float(level) * 39.5f));
                    damage += CalculatePct(block_value, m_spellInfo->Effects[EFFECT_1].CalcValue());
                    break;
                }
                break;
            }
            case SPELLFAMILY_DEATHKNIGHT:
            {
                if (!unitCaster)
                    break;

                // Blood Boil - bonus for diseased targets
                if (m_spellInfo->SpellFamilyFlags[0] & 0x00040000)
                {
                    if (unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0, 0, 0x00000002, unitCaster->GetGUID()))
                    {
                        damage += m_damage / 2;
                        damage += int32(unitCaster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.035f);
                    }
                }
                break;
            }
        }

        if (unitCaster && damage > 0 && apply_direct_bonus)
        {
            damage = unitCaster->SpellDamageBonusDone(unitTarget, m_spellInfo, (uint32)damage, SPELL_DIRECT_DAMAGE, effIndex, { });
            damage = unitTarget->SpellDamageBonusTaken(unitCaster, m_spellInfo, (uint32)damage, SPELL_DIRECT_DAMAGE);
        }

        m_damage += damage;
    }
}

void Spell::EffectDummy(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget && !gameObjTarget && !itemTarget)
        return;

    // pet auras
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (PetAura const* petSpell = sSpellMgr->GetPetAura(m_spellInfo->Id, effIndex))
        {
            m_caster->ToPlayer()->AddPetAura(petSpell);
            return;
        }
    }

    // normal DB scripted effect
    TC_LOG_DEBUG("spells", "Spell ScriptStart spellid %u in EffectDummy(%u)", m_spellInfo->Id, effIndex);
    m_caster->GetMap()->ScriptsStart(sSpellScripts, uint32(m_spellInfo->Id | (effIndex << 24)), m_caster, unitTarget);
}

void Spell::EffectTriggerSpell(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET
        && effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    uint32 triggered_spell_id = m_spellInfo->Effects[effIndex].TriggerSpell;

    /// @todo move those to spell scripts
    if (m_spellInfo->Effects[effIndex].Effect == SPELL_EFFECT_TRIGGER_SPELL
        && effectHandleMode == SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
    {
        // special cases
        switch (triggered_spell_id)
        {
            // Mirror Image
            case 58832:
            {
                if (!unitCaster)
                    break;

                // Glyph of Mirror Image
                if (unitCaster->HasAura(63093))
                    unitCaster->CastSpell(nullptr, 65047, true); // Mirror Image
                break;
            }
            // Demonic Empowerment -- succubus
            case 54437:
            {
                unitTarget->RemoveMovementImpairingAuras(true);
                unitTarget->RemoveAurasByType(SPELL_AURA_MOD_STALKED);
                unitTarget->RemoveAurasByType(SPELL_AURA_MOD_STUN);

                // Cast Lesser Invisibility
                unitTarget->CastSpell(unitTarget, 7870, true);
                return;
            }
            // just skip
            case 23770:                                         // Sayge's Dark Fortune of *
                // not exist, common cooldown can be implemented in scripts if need.
                return;
            // Brittle Armor - (need add max stack of 24575 Brittle Armor)
            case 29284:
            {
                // Brittle Armor
                SpellInfo const* spell = sSpellMgr->GetSpellInfo(24575);
                if (!spell)
                    return;

                for (uint32 j = 0; j < spell->StackAmount; ++j)
                    m_caster->CastSpell(unitTarget, spell->Id, true);
                return;
            }
            // Mercurial Shield - (need add max stack of 26464 Mercurial Shield)
            case 29286:
            {
                // Mercurial Shield
                SpellInfo const* spell = sSpellMgr->GetSpellInfo(26464);
                if (!spell)
                    return;

                for (uint32 j = 0; j < spell->StackAmount; ++j)
                    m_caster->CastSpell(unitTarget, spell->Id, true);
                return;
            }
        }
    }

    if (triggered_spell_id == 0)
    {
        TC_LOG_WARN("spells.effect.nospell", "Spell::EffectTriggerSpell: Spell %u [EffectIndex: %u] does not have triggered spell.", m_spellInfo->Id, effIndex);
        return;
    }

    // normal case
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggered_spell_id);
    if (!spellInfo)
    {
        TC_LOG_ERROR("spells.effect.nospell", "Spell::EffectTriggerSpell spell %u tried to trigger unknown spell %u", m_spellInfo->Id, triggered_spell_id);
        return;
    }

    SpellCastTargets targets;
    if (effectHandleMode == SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
    {
        if (!spellInfo->NeedsToBeTriggeredByCaster(m_spellInfo))
            return;
        targets.SetUnitTarget(unitTarget);
    }
    else //if (effectHandleMode == SPELL_EFFECT_HANDLE_LAUNCH)
    {
        if (spellInfo->NeedsToBeTriggeredByCaster(m_spellInfo) && (m_spellInfo->Effects[effIndex].GetProvidedTargetMask() & TARGET_FLAG_UNIT_MASK))
            return;

        if (spellInfo->GetExplicitTargetMask() & TARGET_FLAG_DEST_LOCATION)
            targets.SetDst(m_targets);

        if (Unit* target = m_targets.GetUnitTarget())
            targets.SetUnitTarget(target);
        else
        {
            if (Unit* unit = m_caster->ToUnit())
                targets.SetUnitTarget(unit);
            else if (GameObject* go = m_caster->ToGameObject())
                targets.SetGOTarget(go);
        }
    }

    CastSpellExtraArgs args(m_originalCasterGUID);
    // set basepoints for trigger with value effect
    if (m_spellInfo->Effects[effIndex].Effect == SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE)
        for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0 + i), damage);

    // original caster guid only for GO cast
    m_caster->CastSpell(targets, spellInfo->Id, args);
}

void Spell::EffectTriggerMissileSpell(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET
        && effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    uint32 triggered_spell_id = m_spellInfo->Effects[effIndex].TriggerSpell;
    if (triggered_spell_id == 0)
    {
        TC_LOG_WARN("spells.effect.nospell", "Spell::EffectTriggerMissileSpell: Spell %u [EffectIndex: %u] does not have triggered spell.", m_spellInfo->Id, effIndex);
        return;
    }

    // normal case
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggered_spell_id);
    if (!spellInfo)
    {
        TC_LOG_ERROR("spells.effect.nospell", "Spell::EffectTriggerMissileSpell spell %u tried to trigger unknown spell %u.", m_spellInfo->Id, triggered_spell_id);
        return;
    }

    SpellCastTargets targets;
    if (effectHandleMode == SPELL_EFFECT_HANDLE_HIT_TARGET)
    {
        if (!spellInfo->NeedsToBeTriggeredByCaster(m_spellInfo))
            return;
        targets.SetUnitTarget(unitTarget);
    }
    else //if (effectHandleMode == SPELL_EFFECT_HANDLE_HIT)
    {
        if (spellInfo->NeedsToBeTriggeredByCaster(m_spellInfo) && (m_spellInfo->Effects[effIndex].GetProvidedTargetMask() & TARGET_FLAG_UNIT_MASK))
            return;

        if (spellInfo->GetExplicitTargetMask() & TARGET_FLAG_DEST_LOCATION)
            targets.SetDst(m_targets);

        if (Unit* unit = m_caster->ToUnit())
            targets.SetUnitTarget(unit);
        else if (GameObject* go = m_caster->ToGameObject())
            targets.SetGOTarget(go);
    }

    CastSpellExtraArgs args(m_originalCasterGUID);
    // set basepoints for trigger with value effect
    if (m_spellInfo->Effects[effIndex].Effect == SPELL_EFFECT_TRIGGER_MISSILE_SPELL_WITH_VALUE)
        for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0 + i), damage);

    // original caster guid only for GO cast
    m_caster->CastSpell(targets, spellInfo->Id, args);
}

void Spell::EffectForceCast(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    uint32 triggered_spell_id = m_spellInfo->Effects[effIndex].TriggerSpell;
    if (triggered_spell_id == 0)
    {
        TC_LOG_WARN("spells.effect.nospell", "Spell::EffectForceCast: Spell %u [EffectIndex: %u] does not have triggered spell.", m_spellInfo->Id, effIndex);
        return;
    }

    // normal case
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggered_spell_id);

    if (!spellInfo)
    {
        TC_LOG_ERROR("spells.effect.nospell", "Spell::EffectForceCast of spell %u: triggering unknown spell id %i.", m_spellInfo->Id, triggered_spell_id);
        return;
    }

    if (m_spellInfo->Effects[effIndex].Effect == SPELL_EFFECT_FORCE_CAST && damage)
    {
        switch (m_spellInfo->Id)
        {
            case 52588: // Skeletal Gryphon Escape
            case 48598: // Ride Flamebringer Cue
                unitTarget->RemoveAura(damage);
                break;
            case 52463: // Hide In Mine Car
            case 52349: // Overtake
            {
                CastSpellExtraArgs args(m_originalCasterGUID);
                args.AddSpellMod(SPELLVALUE_BASE_POINT0, damage);
                unitTarget->CastSpell(unitTarget, spellInfo->Id, args);
                return;
            }
        }
    }

    switch (spellInfo->Id)
    {
        case 72298: // Malleable Goo Summon
            unitTarget->CastSpell(unitTarget, spellInfo->Id, m_originalCasterGUID);
            return;
    }

    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
    if (m_spellInfo->Effects[effIndex].Effect == SPELL_EFFECT_FORCE_CAST_WITH_VALUE)
        for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0 + i), damage);

    unitTarget->CastSpell(m_caster, spellInfo->Id, args);
}

void Spell::EffectTriggerRitualOfSummoning(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    uint32 triggered_spell_id = m_spellInfo->Effects[effIndex].TriggerSpell;
    if (triggered_spell_id == 0)
    {
        TC_LOG_WARN("spells.effect.nospell", "Spell::EffectTriggerRitualOfSummoning: Spell %u [EffectIndex: %u] does not have triggered spell.", m_spellInfo->Id, effIndex);
        return;
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggered_spell_id);

    if (!spellInfo)
    {
        TC_LOG_ERROR("spells.effect.nospell", "EffectTriggerRitualOfSummoning of spell %u: triggering unknown spell id %i.", m_spellInfo->Id, triggered_spell_id);
        return;
    }

    finish();

    m_caster->CastSpell(nullptr, spellInfo->Id, false);
}

void Spell::CalculateJumpSpeeds(SpellInfo const* spellInfo, uint8 i, float dist, float& speedXY, float& speedZ)
{
    float runSpeed = unitCaster->IsControlledByPlayer() ? playerBaseMoveSpeed[MOVE_RUN] : baseMoveSpeed[MOVE_RUN];
    if (Creature* creature = unitCaster->ToCreature())
        runSpeed *= creature->GetCreatureTemplate()->speed_run;

    float multiplier = m_spellInfo->Effects[i].ValueMultiplier;
    if (multiplier <= 0.0f)
        multiplier = 1.0f;

    speedXY = std::min(runSpeed * 3.0f * multiplier, std::max(28.0f, unitCaster->GetSpeed(MOVE_RUN) * 4.0f));

    float duration = dist / speedXY;
    float durationSqr = duration * duration;
    float minHeight = spellInfo->Effects[i].MiscValue  ? spellInfo->Effects[i].MiscValue  / 10.0f :    0.5f; // Lower bound is blizzlike
    float maxHeight = spellInfo->Effects[i].MiscValueB ? spellInfo->Effects[i].MiscValueB / 10.0f : 1000.0f; // Upper bound is unknown
    float height;
    if (durationSqr < minHeight * 8 / Movement::gravity)
        height = minHeight;
    else if (durationSqr > maxHeight * 8 / Movement::gravity)
        height = maxHeight;
    else
        height = Movement::gravity * durationSqr / 8;

    speedZ = std::sqrt(2 * Movement::gravity * height);
}

void Spell::EffectJump(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (!unitCaster)
        return;

    if (unitCaster->IsInFlight())
        return;

    if (!unitTarget)
        return;

    float speedXY, speedZ;
    CalculateJumpSpeeds(m_spellInfo, effIndex, unitCaster->GetExactDist2d(unitTarget), speedXY, speedZ);
    unitCaster->GetMotionMaster()->MoveJump(*unitTarget, speedXY, speedZ, EVENT_JUMP, false);
}

void Spell::EffectJumpDest(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    if (!unitCaster)
        return;

    if (unitCaster->IsInFlight())
        return;

    if (!m_targets.HasDst())
        return;

    float speedXY, speedZ;
    CalculateJumpSpeeds(m_spellInfo, effIndex, unitCaster->GetExactDist2d(destTarget), speedXY, speedZ);
    unitCaster->GetMotionMaster()->MoveJump(*destTarget, speedXY, speedZ, EVENT_JUMP, !m_targets.GetObjectTargetGUID().IsEmpty());
}

void Spell::EffectTeleportUnits(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->IsInFlight())
        return;

    // If not exist data for dest location - return
    if (!m_targets.HasDst())
    {
        TC_LOG_ERROR("spells", "Spell::EffectTeleportUnits - does not have a destination for spellId %u.", m_spellInfo->Id);
        return;
    }

    // Init dest coordinates
    WorldLocation targetDest(*destTarget);
    if (targetDest.GetMapId() == MAPID_INVALID)
        targetDest.m_mapId = unitTarget->GetMapId();

    if (!targetDest.GetOrientation() && m_targets.GetUnitTarget())
        targetDest.SetOrientation(m_targets.GetUnitTarget()->GetOrientation());

    if (targetDest.GetMapId() == unitTarget->GetMapId())
        unitTarget->NearTeleportTo(targetDest, unitTarget == m_caster);
    else if (unitTarget->GetTypeId() == TYPEID_PLAYER)
        unitTarget->ToPlayer()->TeleportTo(targetDest, unitTarget == m_caster ? TELE_TO_SPELL : 0);
    else
    {
        TC_LOG_ERROR("spells", "Spell::EffectTeleportUnits - spellId %u attempted to teleport creature to a different map.", m_spellInfo->Id);
        return;
    }
}

void Spell::EffectApplyAura(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!_spellAura || !unitTarget)
        return;

    // register target/effect on aura
    AuraApplication* aurApp = _spellAura->GetApplicationOfTarget(unitTarget->GetGUID());
    if (!aurApp)
        aurApp = unitTarget->_CreateAuraApplication(_spellAura, 1 << effIndex);
    else
        aurApp->UpdateApplyEffectMask(aurApp->GetEffectsToApply() | 1 << effIndex);
}

void Spell::EffectUnlearnSpecialization(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();
    uint32 spellToUnlearn = m_spellInfo->Effects[effIndex].TriggerSpell;

    player->RemoveSpell(spellToUnlearn);

    TC_LOG_DEBUG("spells", "Spell: Player %u has unlearned spell %u from NpcGUID: %u", player->GetGUID().GetCounter(), spellToUnlearn, m_caster->GetGUID().GetCounter());
}

void Spell::EffectPowerDrain(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (m_spellInfo->Effects[effIndex].MiscValue < 0 || m_spellInfo->Effects[effIndex].MiscValue >= int8(MAX_POWERS))
        return;

    Powers powerType = Powers(m_spellInfo->Effects[effIndex].MiscValue);
    if (!unitTarget || !unitTarget->IsAlive() || unitTarget->GetPowerType() != powerType || damage < 0)
        return;

    // add spell damage bonus
    if (unitCaster)
    {
        damage = unitCaster->SpellDamageBonusDone(unitTarget, m_spellInfo, uint32(damage), SPELL_DIRECT_DAMAGE, effIndex, { });
        damage = unitTarget->SpellDamageBonusTaken(unitCaster, m_spellInfo, uint32(damage), SPELL_DIRECT_DAMAGE);
    }

    // resilience reduce mana draining effect at spell crit damage reduction (added in 2.4)
    int32 power = damage;
    if (powerType == POWER_MANA)
        power -= unitTarget->GetSpellCritDamageReduction(power);

    int32 newDamage = -(unitTarget->ModifyPower(powerType, -int32(power)));

    // Don't restore from self drain
    float gainMultiplier = 0.f;
    if (unitCaster && unitCaster != unitTarget)
    {
        gainMultiplier = m_spellInfo->Effects[effIndex].CalcValueMultiplier(unitCaster, this);
        int32 const gain = int32(newDamage * gainMultiplier);

        unitCaster->EnergizeBySpell(unitCaster, m_spellInfo, gain, powerType);
    }
    ExecuteLogEffectTakeTargetPower(effIndex, unitTarget, powerType, newDamage, gainMultiplier);
}

void Spell::EffectSendEvent(SpellEffIndex effIndex)
{
    // we do not handle a flag dropping or clicking on flag in battleground by sendevent system
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET
        && effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    WorldObject* target = nullptr;

    // call events for object target if present
    if (effectHandleMode == SPELL_EFFECT_HANDLE_HIT_TARGET)
    {
        if (unitTarget)
            target = unitTarget;
        else if (gameObjTarget)
            target = gameObjTarget;
    }
    else // if (effectHandleMode == SPELL_EFFECT_HANDLE_HIT)
    {
        // let's prevent executing effect handler twice in case when spell effect is capable of targeting an object
        // this check was requested by scripters, but it has some downsides:
        // now it's impossible to script (using sEventScripts) a cast which misses all targets
        // or to have an ability to script the moment spell hits dest (in a case when there are object targets present)
        if (m_spellInfo->Effects[effIndex].GetProvidedTargetMask() & (TARGET_FLAG_UNIT_MASK | TARGET_FLAG_GAMEOBJECT_MASK))
            return;
        // some spells have no target entries in dbc and they use focus target
        if (focusObject)
            target = focusObject;
        /// @todo there should be a possibility to pass dest target to event script
    }

    TC_LOG_DEBUG("spells", "Spell ScriptStart %u for spellid %u in EffectSendEvent ", m_spellInfo->Effects[effIndex].MiscValue, m_spellInfo->Id);

    if (ZoneScript* zoneScript = m_caster->GetZoneScript())
        zoneScript->ProcessEvent(target, m_spellInfo->Effects[effIndex].MiscValue);
    else if (InstanceScript* instanceScript = m_caster->GetInstanceScript())    // needed in case Player is the caster
        instanceScript->ProcessEvent(target, m_spellInfo->Effects[effIndex].MiscValue);

    m_caster->GetMap()->ScriptsStart(sEventScripts, m_spellInfo->Effects[effIndex].MiscValue, m_caster, target);
}

void Spell::EffectPowerBurn(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (m_spellInfo->Effects[effIndex].MiscValue < 0 || m_spellInfo->Effects[effIndex].MiscValue >= int8(MAX_POWERS))
        return;

    Powers powerType = Powers(m_spellInfo->Effects[effIndex].MiscValue);
    if (!unitTarget || !unitTarget->IsAlive() || unitTarget->GetPowerType() != powerType || damage < 0)
        return;

    // burn x% of target's mana, up to maximum of 2x% of caster's mana (Mana Burn)
    ///@todo: move this to scripts
    if (unitCaster && m_spellInfo->Id == 8129)
    {
        int32 maxDamage = int32(CalculatePct(unitCaster->GetMaxPower(powerType), damage * 2));
        damage = int32(CalculatePct(unitTarget->GetMaxPower(powerType), damage));
        damage = std::min(damage, maxDamage);
    }

    int32 power = damage;
    // resilience reduce mana draining effect at spell crit damage reduction (added in 2.4)
    if (powerType == POWER_MANA)
        power -= unitTarget->GetSpellCritDamageReduction(power);

    int32 newDamage = -(unitTarget->ModifyPower(powerType, -power));

    // NO - Not a typo - EffectPowerBurn uses effect value multiplier - not effect damage multiplier
    float dmgMultiplier = m_spellInfo->Effects[effIndex].CalcValueMultiplier(unitCaster, this);

    // add log data before multiplication (need power amount, not damage)
    ExecuteLogEffectTakeTargetPower(effIndex, unitTarget, powerType, newDamage, 0.0f);

    newDamage = int32(newDamage * dmgMultiplier);

    m_damage += newDamage;
}

void Spell::EffectHeal(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive() || damage < 0)
        return;

    // Skip if m_originalCaster not available
    if (!unitCaster)
        return;

    int32 addhealth = damage;

    // Vessel of the Naaru (Vial of the Sunwell trinket)
    ///@todo: move this to scripts
    if (m_spellInfo->Id == 45064)
    {
        // Amount of heal - depends from stacked Holy Energy
        int32 damageAmount = 0;
        if (AuraEffect const* aurEff = unitCaster->GetAuraEffect(45062, 0))
        {
            damageAmount += aurEff->GetAmount();
            unitCaster->RemoveAurasDueToSpell(45062);
        }

        addhealth += damageAmount;
    }
    // Swiftmend - consumes Regrowth or Rejuvenation
    else if (m_spellInfo->TargetAuraState == AURA_STATE_SWIFTMEND && unitTarget->HasAuraState(AURA_STATE_SWIFTMEND, m_spellInfo, unitCaster))
    {
        Unit::AuraEffectList const& RejorRegr = unitTarget->GetAuraEffectsByType(SPELL_AURA_PERIODIC_HEAL);
        // find most short by duration
        AuraEffect* targetAura = nullptr;
        for (Unit::AuraEffectList::const_iterator i = RejorRegr.begin(); i != RejorRegr.end(); ++i)
        {
            if ((*i)->GetSpellInfo()->SpellFamilyName == SPELLFAMILY_DRUID
                && (*i)->GetSpellInfo()->SpellFamilyFlags[0] & 0x50)
            {
                if (!targetAura || (*i)->GetBase()->GetDuration() < targetAura->GetBase()->GetDuration())
                    targetAura = *i;
            }
        }

        if (!targetAura)
        {
            TC_LOG_ERROR("spells", "Target (%s) has the aurastate AURA_STATE_SWIFTMEND, but no matching aura.", unitTarget->GetGUID().ToString().c_str());
            return;
        }

        int32 tickheal = targetAura->GetAmount();
        unitTarget->SpellHealingBonusTaken(unitCaster, targetAura->GetSpellInfo(), tickheal, DOT);

        int32 tickcount = 0;
        // Rejuvenation
        if (targetAura->GetSpellInfo()->SpellFamilyFlags[0] & 0x10)
            tickcount = 4;
        // Regrowth
        else // if (targetAura->GetSpellInfo()->SpellFamilyFlags[0] & 0x40)
            tickcount = 6;

        addhealth += tickheal * tickcount;

        // Glyph of Swiftmend
        if (!unitCaster->HasAura(54824))
            unitTarget->RemoveAura(targetAura->GetId(), targetAura->GetCasterGUID());
    }
    // Nourish
    else if (m_spellInfo->SpellFamilyName == SPELLFAMILY_DRUID && m_spellInfo->SpellFamilyFlags[1] & 0x2000000)
    {
        addhealth = unitCaster->SpellHealingBonusDone(unitTarget, m_spellInfo, addhealth, HEAL, effIndex, { });

        // Glyph of Nourish
        if (AuraEffect const* aurEff = unitCaster->GetAuraEffect(62971, 0))
        {
            uint32 auraCount = 0;
            Unit::AuraEffectList const& periodicHeals = unitTarget->GetAuraEffectsByType(SPELL_AURA_PERIODIC_HEAL);
            for (AuraEffect const* hot : periodicHeals)
            {
                if (unitCaster->GetGUID() == hot->GetCasterGUID())
                    ++auraCount;
            }

            AddPct(addhealth, aurEff->GetAmount() * auraCount);
        }
    }
    // Death Pact - return pct of max health to caster
    else if (m_spellInfo->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT && m_spellInfo->SpellFamilyFlags[0] & 0x00080000)
        addhealth = unitCaster->SpellHealingBonusDone(unitTarget, m_spellInfo, int32(unitCaster->CountPctFromMaxHealth(damage)), HEAL, effIndex, { });
    else
        addhealth = unitCaster->SpellHealingBonusDone(unitTarget, m_spellInfo, addhealth, HEAL, effIndex, { });

    addhealth = unitTarget->SpellHealingBonusTaken(unitCaster, m_spellInfo, addhealth, HEAL);

    // Remove Grievious bite if fully healed
    if (unitTarget->HasAura(48920) && (unitTarget->GetHealth() + addhealth >= unitTarget->GetMaxHealth()))
        unitTarget->RemoveAura(48920);

    m_healing += addhealth;
}

void Spell::EffectHealPct(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive() || damage < 0)
        return;

    uint32 heal = unitTarget->CountPctFromMaxHealth(damage);
    if (unitCaster)
    {
        heal = unitCaster->SpellHealingBonusDone(unitTarget, m_spellInfo, heal, HEAL, effIndex, { });
        heal = unitTarget->SpellHealingBonusTaken(unitCaster, m_spellInfo, heal, HEAL);
    }

    m_healing += heal;
}

void Spell::EffectHealMechanical(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive() || damage < 0)
        return;

    uint32 heal = damage;
    if (unitCaster)
    {
        heal = unitCaster->SpellHealingBonusDone(unitTarget, m_spellInfo, heal, HEAL, effIndex, { });
        heal = unitTarget->SpellHealingBonusTaken(unitCaster, m_spellInfo, heal, HEAL);
    }

    m_healing += heal;
}

void Spell::EffectHealthLeech(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive() || damage < 0)
        return;

    if (unitCaster)
    {
        damage = unitCaster->SpellDamageBonusDone(unitTarget, m_spellInfo, uint32(damage), SPELL_DIRECT_DAMAGE, effIndex, { });
        damage = unitTarget->SpellDamageBonusTaken(unitCaster, m_spellInfo, uint32(damage), SPELL_DIRECT_DAMAGE);
    }

    TC_LOG_DEBUG("spells", "HealthLeech :%i", damage);

    float healMultiplier = m_spellInfo->Effects[effIndex].CalcValueMultiplier(unitCaster, this);

    m_damage += damage;

    DamageInfo damageInfo(unitCaster, unitTarget, damage, m_spellInfo, m_spellInfo->GetSchoolMask(), SPELL_DIRECT_DAMAGE, BASE_ATTACK);
    Unit::CalcAbsorbResist(damageInfo);
    uint32 const absorb = damageInfo.GetAbsorb();
    damage -= absorb;

    // get max possible damage, don't count overkill for heal
    uint32 healthGain = uint32(-unitTarget->GetHealthGain(-damage) * healMultiplier);

    if (unitCaster && unitCaster->IsAlive())
    {
        healthGain = unitCaster->SpellHealingBonusDone(unitCaster, m_spellInfo, healthGain, HEAL, effIndex, { });
        healthGain = unitCaster->SpellHealingBonusTaken(unitCaster, m_spellInfo, healthGain, HEAL);

        HealInfo healInfo(unitCaster, unitCaster, healthGain, m_spellInfo, m_spellSchoolMask);
        unitCaster->HealBySpell(healInfo);
    }
}

void Spell::DoCreateItem(uint32 /*i*/, uint32 itemtype)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();

    uint32 newitemid = itemtype;
    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(newitemid);
    if (!pProto)
    {
        player->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr);
        return;
    }

    // bg reward have some special in code work
    uint32 bgType = 0;
    switch (m_spellInfo->Id)
    {
        case SPELL_AV_MARK_WINNER:
        case SPELL_AV_MARK_LOSER:
            bgType = BATTLEGROUND_AV;
            break;
        case SPELL_WS_MARK_WINNER:
        case SPELL_WS_MARK_LOSER:
            bgType = BATTLEGROUND_WS;
            break;
        case SPELL_AB_MARK_WINNER:
        case SPELL_AB_MARK_LOSER:
            bgType = BATTLEGROUND_AB;
            break;
        default:
            break;
    }

    uint32 num_to_add = damage;

    if (num_to_add < 1)
        num_to_add = 1;
    if (num_to_add > pProto->GetMaxStackSize())
        num_to_add = pProto->GetMaxStackSize();

    /* == gem perfection handling == */

    // the chance of getting a perfect result
    float perfectCreateChance = 0.0f;
    // the resulting perfect item if successful
    uint32 perfectItemType = itemtype;
    // get perfection capability and chance
    if (CanCreatePerfectItem(player, m_spellInfo->Id, perfectCreateChance, perfectItemType))
        if (roll_chance_f(perfectCreateChance)) // if the roll succeeds...
            newitemid = perfectItemType;        // the perfect item replaces the regular one

    /* == gem perfection handling over == */


    /* == profession specialization handling == */

    // init items_count to 1, since 1 item will be created regardless of specialization
    int items_count=1;
    // the chance to create additional items
    float additionalCreateChance=0.0f;
    // the maximum number of created additional items
    uint8 additionalMaxNum=0;
    // get the chance and maximum number for creating extra items
    if (CanCreateExtraItems(player, m_spellInfo->Id, additionalCreateChance, additionalMaxNum))
        // roll with this chance till we roll not to create or we create the max num
        while (roll_chance_f(additionalCreateChance) && items_count <= additionalMaxNum)
            ++items_count;

    // really will be created more items
    num_to_add *= items_count;

    /* == profession specialization handling over == */


    // can the player store the new item?
    ItemPosCountVec dest;
    uint32 no_space = 0;
    InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, newitemid, num_to_add, &no_space);
    if (msg != EQUIP_ERR_OK)
    {
        // convert to possible store amount
        if (msg == EQUIP_ERR_INVENTORY_FULL || msg == EQUIP_ERR_CANT_CARRY_MORE_OF_THIS)
            num_to_add -= no_space;
        else
        {
            // if not created by another reason from full inventory or unique items amount limitation
            player->SendEquipError(msg, nullptr, nullptr, newitemid);
            return;
        }
    }

    if (num_to_add)
    {
        // create the new item and store it
        Item* pItem = player->StoreNewItem(dest, newitemid, true, GenerateItemRandomPropertyId(newitemid));

        // was it successful? return error if not
        if (!pItem)
        {
            player->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr);
            return;
        }

        // set the "Crafted by ..." property of the item
        if (pItem->GetTemplate()->HasSignature())
            pItem->SetGuidValue(ITEM_FIELD_CREATOR, player->GetGUID());

        // send info to the client
        player->SendNewItem(pItem, num_to_add, true, bgType == 0);

        // we succeeded in creating at least one item, so a levelup is possible
        if (bgType == 0)
            player->UpdateCraftSkill(m_spellInfo->Id);
    }

/*
    // for battleground marks send by mail if not add all expected
    if (no_space > 0 && bgType)
    {
        if (Battleground* bg = sBattlegroundMgr->GetBattlegroundTemplate(BattlegroundTypeId(bgType)))
            bg->SendRewardMarkByMail(player, newitemid, no_space);
    }
*/
}

void Spell::EffectCreateItem(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    DoCreateItem(effIndex, m_spellInfo->Effects[effIndex].ItemType);
    ExecuteLogEffectCreateItem(effIndex, m_spellInfo->Effects[effIndex].ItemType);
}

void Spell::EffectCreateItem2(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();

    // Pick a random item from spell_loot_template
    if (m_spellInfo->IsLootCrafting())
    {
        player->AutoStoreLoot(m_spellInfo->Id, LootTemplates_Spell, false, true);
        player->UpdateCraftSkill(m_spellInfo->Id);
    }
    else // If there's no random loot entries for this spell, pick the item associated with this spell
    {
        uint32 item_id = m_spellInfo->Effects[effIndex].ItemType;

        if (item_id)
            DoCreateItem(effIndex, item_id);
    }

    /// @todo ExecuteLogEffectCreateItem(i, m_spellInfo->Effects[i].ItemType);
}

void Spell::EffectCreateRandomItem(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    Player* player = unitTarget->ToPlayer();

    // create some random items
    player->AutoStoreLoot(m_spellInfo->Id, LootTemplates_Spell);
    /// @todo ExecuteLogEffectCreateItem(i, m_spellInfo->Effects[i].ItemType);
}

void Spell::EffectPersistentAA(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!unitCaster)
        return;

    // only handle at last effect
    for (uint8 i = effIndex + 1; i < MAX_SPELL_EFFECTS; ++i)
        if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_PERSISTENT_AREA_AURA)
            return;

    ASSERT(!_dynObjAura);

    float radius = m_spellInfo->Effects[effIndex].CalcRadius(unitCaster);

    // Caster not in world, might be spell triggered from aura removal
    if (!unitCaster->IsInWorld())
        return;

    DynamicObject* dynObj = new DynamicObject(false);
    if (!dynObj->CreateDynamicObject(unitCaster->GetMap()->GenerateLowGuid<HighGuid::DynamicObject>(), unitCaster, m_spellInfo->Id, *destTarget, radius, DYNAMIC_OBJECT_AREA_SPELL))
    {
        delete dynObj;
        return;
    }

    AuraCreateInfo createInfo(m_spellInfo, MAX_EFFECT_MASK, dynObj);
    createInfo
        .SetCaster(unitCaster)
        .SetBaseAmount(m_spellValue->EffectBasePoints);

    if (Aura* aura = Aura::TryCreate(createInfo))
    {
        _dynObjAura = aura->ToDynObjAura();
        _dynObjAura->_RegisterForTargets();
    }
    else
        return;

    ASSERT(_dynObjAura->GetDynobjOwner());
    _dynObjAura->_ApplyEffectForTargets(effIndex);
}

void Spell::EffectEnergize(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitCaster || !unitTarget)
        return;

    if (!unitTarget->IsAlive())
        return;

    if (m_spellInfo->Effects[effIndex].MiscValue < 0 || m_spellInfo->Effects[effIndex].MiscValue >= int8(MAX_POWERS))
        return;

    Powers power = Powers(m_spellInfo->Effects[effIndex].MiscValue);
    if (unitTarget->GetTypeId() == TYPEID_PLAYER && unitTarget->GetPowerType() != power && m_spellInfo->SpellFamilyName != SPELLFAMILY_POTION
        && !m_spellInfo->HasAttribute(SPELL_ATTR7_CAN_RESTORE_SECONDARY_POWER))
        return;

    if (unitTarget->GetMaxPower(power) == 0)
        return;

    // Some level depends spells
    ///@todo: move this to scripts
    int32 level_multiplier = 0;
    int32 level_diff = 0;
    switch (m_spellInfo->Id)
    {
        case 9512:                                          // Restore Energy
            level_diff = unitCaster->GetLevel() - 40;
            level_multiplier = 2;
            break;
        case 24571:                                         // Blood Fury
            level_diff = unitCaster->GetLevel() - 60;
            level_multiplier = 10;
            break;
        case 24532:                                         // Burst of Energy
            level_diff = unitCaster->GetLevel() - 60;
            level_multiplier = 4;
            break;
        case 31930:                                         // Judgements of the Wise
        case 63375:                                         // Improved Stormstrike
        case 68082:                                         // Glyph of Seal of Command
            damage = int32(CalculatePct(unitTarget->GetCreateMana(), damage));
            break;
        case 48542:                                         // Revitalize
            damage = int32(CalculatePct(unitTarget->GetMaxPower(power), damage));
            break;
        case 67490:                                         // Runic Mana Injector (mana gain increased by 25% for engineers - 3.2.0 patch change)
        {
            if (Player* player = unitCaster->ToPlayer())
                if (player->HasSkill(SKILL_ENGINEERING))
                    AddPct(damage, 25);
            break;
        }
        case 71132:                                         // Glyph of Shadow Word: Pain
            damage = int32(CalculatePct(unitTarget->GetCreateMana(), 1));  // set 1 as value, missing in dbc
            break;
        default:
            break;
    }

    if (level_diff > 0)
        damage -= level_multiplier * level_diff;

    if (damage < 0)
        return;

    unitCaster->EnergizeBySpell(unitTarget, m_spellInfo, damage, power);
}

void Spell::EffectEnergizePct(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitCaster || !unitTarget)
        return;

    if (!unitTarget->IsAlive())
        return;

    if (m_spellInfo->Effects[effIndex].MiscValue < 0 || m_spellInfo->Effects[effIndex].MiscValue >= int8(MAX_POWERS))
        return;

    Powers power = Powers(m_spellInfo->Effects[effIndex].MiscValue);

    if (unitTarget->GetTypeId() == TYPEID_PLAYER && unitTarget->GetPowerType() != power && !m_spellInfo->HasAttribute(SPELL_ATTR7_CAN_RESTORE_SECONDARY_POWER))
        return;

    uint32 maxPower = unitTarget->GetMaxPower(power);
    if (!maxPower)
        return;

    uint32 const gain = CalculatePct(maxPower, damage);
    unitCaster->EnergizeBySpell(unitTarget, m_spellInfo, gain, power);
}

void Spell::SendLoot(ObjectGuid guid, LootType loottype)
{
    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    if (gameObjTarget)
    {
        // Players shouldn't be able to loot gameobjects that are currently despawned
        if (!gameObjTarget->isSpawned() && !player->IsGameMaster())
        {
            TC_LOG_ERROR("entities.player.cheat", "Possible hacking attempt: Player %s [guid: %u] tried to loot a gameobject [entry: %u id: %u] which is on respawn timer without being in GM mode!",
                            player->GetName().c_str(), player->GetGUID().GetCounter(), gameObjTarget->GetEntry(), gameObjTarget->GetGUID().GetCounter());
            return;
        }
        // special case, already has GossipHello inside so return and avoid calling twice
        if (gameObjTarget->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
        {
            gameObjTarget->Use(player);
            return;
        }

        player->PlayerTalkClass->ClearMenus();
        if (gameObjTarget->AI()->GossipHello(player))
            return;

        switch (gameObjTarget->GetGoType())
        {
            case GAMEOBJECT_TYPE_DOOR:
            case GAMEOBJECT_TYPE_BUTTON:
                gameObjTarget->UseDoorOrButton(0, false, player);
                return;

            case GAMEOBJECT_TYPE_QUESTGIVER:
                player->PrepareGossipMenu(gameObjTarget, gameObjTarget->GetGOInfo()->questgiver.gossipID, true);
                player->SendPreparedGossip(gameObjTarget);
                return;

            case GAMEOBJECT_TYPE_SPELL_FOCUS:
                // triggering linked GO
                if (uint32 trapEntry = gameObjTarget->GetGOInfo()->spellFocus.linkedTrapId)
                    gameObjTarget->TriggeringLinkedGameObject(trapEntry, player);
                return;

            case GAMEOBJECT_TYPE_CHEST:
                /// @todo possible must be moved to loot release (in different from linked triggering)
                if (gameObjTarget->GetGOInfo()->chest.eventId)
                {
                    TC_LOG_DEBUG("spells", "Chest ScriptStart id %u for GO %u", gameObjTarget->GetGOInfo()->chest.eventId, gameObjTarget->GetSpawnId());
                    player->GetMap()->ScriptsStart(sEventScripts, gameObjTarget->GetGOInfo()->chest.eventId, player, gameObjTarget);
                }

                // triggering linked GO
                if (uint32 trapEntry = gameObjTarget->GetGOInfo()->chest.linkedTrapId)
                    gameObjTarget->TriggeringLinkedGameObject(trapEntry, player);

                // Don't return, let loots been taken
            default:
                break;
        }
    }

    // Send loot
    player->SendLoot(guid, loottype);
}

void Spell::EffectOpenLock(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
    {
        TC_LOG_DEBUG("spells", "WORLD: Open Lock - No Player Caster!");
        return;
    }

    Player* player = m_caster->ToPlayer();

    uint32 lockId = 0;
    ObjectGuid guid;

    // Get lockId
    if (gameObjTarget)
    {
        GameObjectTemplate const* goInfo = gameObjTarget->GetGOInfo();

        if (goInfo->CannotBeUsedUnderImmunity() && m_caster->HasFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE))
            return;

        // Arathi Basin banner opening. /// @todo Verify correctness of this check
        if ((goInfo->type == GAMEOBJECT_TYPE_BUTTON && goInfo->button.noDamageImmune) ||
            (goInfo->type == GAMEOBJECT_TYPE_GOOBER && goInfo->goober.losOK))
        {
            //CanUseBattlegroundObject() already called in CheckCast()
            // in battleground check
            if (Battleground* bg = player->GetBattleground())
            {
                bg->EventPlayerClickedOnFlag(player, gameObjTarget);
                return;
            }
        }
        else if (goInfo->type == GAMEOBJECT_TYPE_FLAGSTAND)
        {
            //CanUseBattlegroundObject() already called in CheckCast()
            // in battleground check
            if (Battleground* bg = player->GetBattleground())
            {
                if (bg->GetTypeID(true) == BATTLEGROUND_EY)
                    bg->EventPlayerClickedOnFlag(player, gameObjTarget);
                return;
            }
        }
        else if (m_spellInfo->Id == 1842 && gameObjTarget->GetGOInfo()->type == GAMEOBJECT_TYPE_TRAP && gameObjTarget->GetOwner())
        {
            gameObjTarget->SetLootState(GO_JUST_DEACTIVATED);
            return;
        }
        /// @todo Add script for spell 41920 - Filling, becouse server it freze when use this spell
        // handle outdoor pvp object opening, return true if go was registered for handling
        // these objects must have been spawned by outdoorpvp!
        else if (gameObjTarget->GetGOInfo()->type == GAMEOBJECT_TYPE_GOOBER && sOutdoorPvPMgr->HandleOpenGo(player, gameObjTarget))
            return;
        lockId = goInfo->GetLockId();
        guid = gameObjTarget->GetGUID();
    }
    else if (itemTarget)
    {
        lockId = itemTarget->GetTemplate()->LockID;
        guid = itemTarget->GetGUID();
    }
    else
    {
        TC_LOG_DEBUG("spells", "WORLD: Open Lock - No GameObject/Item Target!");
        return;
    }

    SkillType skillId = SKILL_NONE;
    int32 reqSkillValue = 0;
    int32 skillValue;

    SpellCastResult res = CanOpenLock(effIndex, lockId, skillId, reqSkillValue, skillValue);
    if (res != SPELL_CAST_OK)
    {
        SendCastResult(res);
        return;
    }

    if (gameObjTarget)
        SendLoot(guid, LOOT_SKINNING);
    else if (itemTarget)
    {
        itemTarget->SetFlag(ITEM_FIELD_FLAGS, ITEM_FIELD_FLAG_UNLOCKED);
        itemTarget->SetState(ITEM_CHANGED, itemTarget->GetOwner());
    }

    // not allow use skill grow at item base open
    if (!m_CastItem && skillId != SKILL_NONE)
    {
        // update skill if really known
        if (uint32 pureSkillValue = player->GetPureSkillValue(skillId))
        {
            if (gameObjTarget)
            {
                // Allow one skill-up until respawned
                if (!gameObjTarget->IsInSkillupList(player->GetGUID().GetCounter()) &&
                    player->UpdateGatherSkill(skillId, pureSkillValue, reqSkillValue))
                    gameObjTarget->AddToSkillupList(player->GetGUID().GetCounter());
            }
            else if (itemTarget)
            {
                // Do one skill-up
                player->UpdateGatherSkill(skillId, pureSkillValue, reqSkillValue);
            }
        }
    }
    ExecuteLogEffectOpenLock(effIndex, gameObjTarget ? (Object*)gameObjTarget : (Object*)itemTarget);
}

void Spell::EffectSummonChangeItem(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = m_caster->ToPlayer();

    // applied only to using item
    if (!m_CastItem)
        return;

    // ... only to item in own inventory/bank/equip_slot
    if (m_CastItem->GetOwnerGUID() != player->GetGUID())
        return;

    uint32 newitemid = m_spellInfo->Effects[effIndex].ItemType;
    if (!newitemid)
        return;

    uint16 pos = m_CastItem->GetPos();

    Item* pNewItem = Item::CreateItem(newitemid, 1, player);
    if (!pNewItem)
        return;

    for (uint8 j = PERM_ENCHANTMENT_SLOT; j <= TEMP_ENCHANTMENT_SLOT; ++j)
        if (m_CastItem->GetEnchantmentId(EnchantmentSlot(j)))
            pNewItem->SetEnchantment(EnchantmentSlot(j), m_CastItem->GetEnchantmentId(EnchantmentSlot(j)), m_CastItem->GetEnchantmentDuration(EnchantmentSlot(j)), m_CastItem->GetEnchantmentCharges(EnchantmentSlot(j)));

    if (m_CastItem->GetUInt32Value(ITEM_FIELD_DURABILITY) < m_CastItem->GetUInt32Value(ITEM_FIELD_MAXDURABILITY))
    {
        double lossPercent = 1 - m_CastItem->GetUInt32Value(ITEM_FIELD_DURABILITY) / double(m_CastItem->GetUInt32Value(ITEM_FIELD_MAXDURABILITY));
        player->DurabilityLoss(pNewItem, lossPercent);
    }

    if (player->IsInventoryPos(pos))
    {
        ItemPosCountVec dest;
        InventoryResult msg = player->CanStoreItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), dest, pNewItem, true);
        if (msg == EQUIP_ERR_OK)
        {
            player->DestroyItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), true);

            // prevent crash at access and unexpected charges counting with item update queue corrupt
            if (m_CastItem == m_targets.GetItemTarget())
                m_targets.SetItemTarget(nullptr);

            m_CastItem = nullptr;
            m_castItemGUID.Clear();
            m_castItemEntry = 0;

            player->StoreItem(dest, pNewItem, true);
            player->SendNewItem(pNewItem, 1, true, false);
            player->ItemAddedQuestCheck(newitemid, 1);
            return;
        }
    }
    else if (player->IsBankPos(pos))
    {
        ItemPosCountVec dest;
        if (player->CanBankItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), dest, pNewItem, true) == EQUIP_ERR_OK)
        {
            player->DestroyItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), true);

            // prevent crash at access and unexpected charges counting with item update queue corrupt
            if (m_CastItem == m_targets.GetItemTarget())
                m_targets.SetItemTarget(nullptr);

            m_CastItem = nullptr;
            m_castItemGUID.Clear();
            m_castItemEntry = 0;

            player->BankItem(dest, pNewItem, true);
            return;
        }
    }
    else if (player->IsEquipmentPos(pos))
    {
        uint16 dest;

        player->DestroyItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), true);

        InventoryResult msg = player->CanEquipItem(m_CastItem->GetSlot(), dest, pNewItem, true);

        if (msg == EQUIP_ERR_OK || msg == EQUIP_ERR_CANT_DO_RIGHT_NOW)
        {
            if (msg == EQUIP_ERR_CANT_DO_RIGHT_NOW) dest = EQUIPMENT_SLOT_MAINHAND;

            // prevent crash at access and unexpected charges counting with item update queue corrupt
            if (m_CastItem == m_targets.GetItemTarget())
                m_targets.SetItemTarget(nullptr);

            m_CastItem = nullptr;
            m_castItemGUID.Clear();
            m_castItemEntry = 0;

            player->EquipItem(dest, pNewItem, true);
            player->AutoUnequipOffhandIfNeed();
            player->SendNewItem(pNewItem, 1, true, false);
            player->ItemAddedQuestCheck(newitemid, 1);
            return;
        }
    }

    // fail
    delete pNewItem;
}

void Spell::EffectProficiency(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;
    Player* p_target = m_caster->ToPlayer();

    uint32 subClassMask = m_spellInfo->EquippedItemSubClassMask;
    if (m_spellInfo->EquippedItemClass == ITEM_CLASS_WEAPON && !(p_target->GetWeaponProficiency() & subClassMask))
    {
        p_target->AddWeaponProficiency(subClassMask);
        p_target->SendProficiency(ITEM_CLASS_WEAPON, p_target->GetWeaponProficiency());
    }
    if (m_spellInfo->EquippedItemClass == ITEM_CLASS_ARMOR && !(p_target->GetArmorProficiency() & subClassMask))
    {
        p_target->AddArmorProficiency(subClassMask);
        p_target->SendProficiency(ITEM_CLASS_ARMOR, p_target->GetArmorProficiency());
    }
}

void Spell::EffectSummonType(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    uint32 entry = m_spellInfo->Effects[effIndex].MiscValue;
    if (!entry)
        return;

    SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(m_spellInfo->Effects[effIndex].MiscValueB);
    if (!properties)
    {
        TC_LOG_ERROR("spells", "EffectSummonType: Unhandled summon type %u.", m_spellInfo->Effects[effIndex].MiscValueB);
        return;
    }

    WorldObject* caster = m_caster;
    if (m_originalCaster)
        caster = m_originalCaster;

    int32 duration = m_spellInfo->GetDuration();
    if (Player* modOwner = caster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_DURATION, duration);

    TempSummon* summon = nullptr;

    // determine how many units should be summoned
    uint32 numSummons;

    // some spells need to summon many units, for those spells number of summons is stored in effect value
    // however so far noone found a generic check to find all of those (there's no related data in summonproperties.dbc
    // and in spell attributes, possibly we need to add a table for those)
    // so here's a list of MiscValueB values, which is currently most generic check
    switch (properties->Id)
    {
        case 64:
        case 61:
        case 1101:
        case 66:
        case 648:
        case 2301:
        case 1061:
        case 1261:
        case 629:
        case 181:
        case 715:
        case 1562:
        case 833:
        case 1161:
        case 713:
            numSummons = (damage > 0) ? damage : 1;
            break;
        default:
            numSummons = 1;
            break;
    }

    switch (properties->Category)
    {
        case SUMMON_CATEGORY_WILD:
        case SUMMON_CATEGORY_ALLY:
        case SUMMON_CATEGORY_UNK:
        {
            if (properties->Flags & 512)
            {
                SummonGuardian(effIndex, entry, properties, numSummons);
                break;
            }

            switch (properties->Type)
            {
                case SUMMON_TYPE_PET:
                case SUMMON_TYPE_GUARDIAN:
                case SUMMON_TYPE_GUARDIAN2:
                case SUMMON_TYPE_MINION:
                    SummonGuardian(effIndex, entry, properties, numSummons);
                    break;
                    // Summons a vehicle, but doesn't force anyone to enter it (see SUMMON_CATEGORY_VEHICLE)
                case SUMMON_TYPE_VEHICLE:
                case SUMMON_TYPE_VEHICLE2:
                {
                    if (!unitCaster)
                        return;

                    summon = unitCaster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, unitCaster, m_spellInfo->Id);
                    break;
                }
                case SUMMON_TYPE_LIGHTWELL:
                case SUMMON_TYPE_TOTEM:
                {
                    if (!unitCaster)
                        return;

                    summon = unitCaster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, unitCaster, m_spellInfo->Id);
                    if (!summon || !summon->IsTotem())
                        return;

                    // Mana Tide Totem
                    if (m_spellInfo->Id == 16190)
                        damage = unitCaster->CountPctFromMaxHealth(10);

                    if (damage)                                            // if not spell info, DB values used
                    {
                        summon->SetMaxHealth(damage);
                        summon->SetHealth(damage);
                    }
                    break;
                }
                case SUMMON_TYPE_MINIPET:
                {
                    if (!unitCaster)
                        return;

                    summon = unitCaster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, unitCaster, m_spellInfo->Id);
                    if (!summon || !summon->HasUnitTypeMask(UNIT_MASK_MINION))
                        return;

                    summon->SelectLevel();       // some summoned creaters have different from 1 DB data for level/hp
                    summon->SetUInt32Value(UNIT_NPC_FLAGS, summon->GetCreatureTemplate()->npcflag);
                    summon->SetImmuneToAll(true);
                    break;
                }
                default:
                {
                    float radius = m_spellInfo->Effects[effIndex].CalcRadius();

                    TempSummonType summonType = (duration == 0) ? TEMPSUMMON_DEAD_DESPAWN : TEMPSUMMON_TIMED_DESPAWN;

                    for (uint32 count = 0; count < numSummons; ++count)
                    {
                        Position pos;
                        if (count == 0)
                            pos = *destTarget;
                        else
                            // randomize position for multiple summons
                            pos = caster->GetRandomPoint(*destTarget, radius);

                        summon = caster->SummonCreature(entry, pos, summonType, duration, 0, m_spellInfo->Id);
                        if (!summon)
                            continue;

                        if (properties->Category == SUMMON_CATEGORY_ALLY)
                        {
                            summon->SetOwnerGUID(caster->GetGUID());
                            summon->SetFaction(caster->GetFaction());
                        }

                        ExecuteLogEffectSummonObject(effIndex, summon);
                    }
                    return;
                }
            }
            break;
        }
        case SUMMON_CATEGORY_PET:
            SummonGuardian(effIndex, entry, properties, numSummons);
            break;
        case SUMMON_CATEGORY_PUPPET:
        {
            if (!unitCaster)
                return;

            summon = unitCaster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, unitCaster, m_spellInfo->Id);
            break;
        }
        case SUMMON_CATEGORY_VEHICLE:
        {
            if (!unitCaster)
                return;

            // Summoning spells (usually triggered by npc_spellclick) that spawn a vehicle and that cause the clicker
            // to cast a ride vehicle spell on the summoned unit.
            summon = unitCaster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, unitCaster, m_spellInfo->Id);
            if (!summon || !summon->IsVehicle())
                return;

            // The spell that this effect will trigger. It has SPELL_AURA_CONTROL_VEHICLE
            uint32 spellId = VEHICLE_SPELL_RIDE_HARDCODED;
            int32 basePoints = m_spellInfo->Effects[effIndex].CalcValue();
            if (basePoints > MAX_VEHICLE_SEATS)
            {
                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(basePoints);
                if (spellInfo && spellInfo->HasAura(SPELL_AURA_CONTROL_VEHICLE))
                    spellId = spellInfo->Id;
            }

            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);

            // if we have small value, it indicates seat position
            if (basePoints > 0 && basePoints < MAX_VEHICLE_SEATS)
                args.AddSpellMod(SPELLVALUE_BASE_POINT0, basePoints);

            unitCaster->CastSpell(summon, spellId, args);

            uint32 faction = properties->Faction;
            if (!faction)
                faction = unitCaster->GetFaction();

            summon->SetFaction(faction);
            break;
        }
    }

    if (summon)
    {
        summon->SetCreatorGUID(caster->GetGUID());
        ExecuteLogEffectSummonObject(effIndex, summon);
    }
}

void Spell::EffectLearnSpell(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
    {
        if (unitTarget->ToPet())
            EffectLearnPetSpell(effIndex);
        return;
    }

    Player* player = unitTarget->ToPlayer();

    uint32 spellToLearn = (m_spellInfo->Id == 483 || m_spellInfo->Id == 55884) ? damage : m_spellInfo->Effects[effIndex].TriggerSpell;
    player->LearnSpell(spellToLearn, false);

    TC_LOG_DEBUG("spells", "Spell: Player %u has learned spell %u from NpcGUID: %u", player->GetGUID().GetCounter(), spellToLearn, m_caster->GetGUID().GetCounter());
}

void Spell::EffectDispel(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    // Create dispel mask by dispel type
    uint32 dispel_type = m_spellInfo->Effects[effIndex].MiscValue;
    uint32 dispelMask  = SpellInfo::GetDispelMask(DispelType(dispel_type));

    DispelChargesList dispelList;
    unitTarget->GetDispellableAuraList(m_caster, dispelMask, dispelList, targetMissInfo == SPELL_MISS_REFLECT);
    if (dispelList.empty())
        return;

    size_t remaining = dispelList.size();

    // Ok if exist some buffs for dispel try dispel it
    uint32 failCount = 0;
    DispelChargesList successList;
    successList.reserve(damage);

    WorldPacket dataFail(SMSG_DISPEL_FAILED, 8 + 8 + 4 + 4 + damage * 4);
    // dispel N = damage buffs (or while exist buffs for dispel)
    for (int32 count = 0; count < damage && remaining > 0;)
    {
        // Random select buff for dispel
        auto itr = dispelList.begin();
        std::advance(itr, urand(0, remaining - 1));

        if (itr->RollDispel())
        {
            auto successItr = std::find_if(successList.begin(), successList.end(), [&itr](DispelableAura& dispelAura) -> bool
            {
                if (dispelAura.GetAura()->GetId() == itr->GetAura()->GetId() && dispelAura.GetAura()->GetCaster() == itr->GetAura()->GetCaster())
                    return true;

                return false;
            });

            if (successItr == successList.end())
                successList.emplace_back(itr->GetAura(), 0, 1);
            else
                successItr->IncrementCharges();

            if (!itr->DecrementCharge())
            {
                --remaining;
                std::swap(*itr, dispelList[remaining]);
            }
        }
        else
        {
            if (!failCount)
            {
                // Failed to dispell
                dataFail << uint64(m_caster->GetGUID());            // Caster GUID
                dataFail << uint64(unitTarget->GetGUID());          // Victim GUID
                dataFail << uint32(m_spellInfo->Id);                // dispel spell id
            }
            ++failCount;
            dataFail << uint32(itr->GetAura()->GetId());            // Spell Id
        }
        ++count;
    }

    if (failCount)
        m_caster->SendMessageToSet(&dataFail, true);

    if (successList.empty())
        return;

    WorldPacket dataSuccess(SMSG_SPELLDISPELLOG, 8 + 8 + 4 + 1 + 4 + successList.size() * 5);
    // Send packet header
    dataSuccess << unitTarget->GetPackGUID();         // Victim GUID
    dataSuccess << m_caster->GetPackGUID();           // Caster GUID
    dataSuccess << uint32(m_spellInfo->Id);                // dispel spell id
    dataSuccess << uint8(0);                               // not used
    dataSuccess << uint32(successList.size());            // count
    for (DispelChargesList::iterator itr = successList.begin(); itr != successList.end(); ++itr)
    {
        // Send dispelled spell info
        dataSuccess << uint32(itr->GetAura()->GetId());         // Spell Id
        dataSuccess << uint8(0);                                // 0 - dispelled !=0 cleansed
        unitTarget->RemoveAurasDueToSpellByDispel(itr->GetAura()->GetId(), m_spellInfo->Id, itr->GetAura()->GetCasterGUID(), m_caster, itr->GetDispelCharges());
    }
    m_caster->SendMessageToSet(&dataSuccess, true);

    // On success dispel
    // Devour Magic
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK && m_spellInfo->GetCategory() == SPELLCATEGORY_DEVOUR_MAGIC)
    {
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, m_spellInfo->Effects[EFFECT_1].CalcValue());
        m_caster->CastSpell(m_caster, 19658, args);
        // Glyph of Felhunter
        if (Unit* owner = m_caster->GetOwner())
            if (owner->GetAura(56249))
                owner->CastSpell(owner, 19658, args);
    }
}

void Spell::EffectDualWield(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    unitTarget->SetCanDualWield(true);
}

void Spell::EffectPull(SpellEffIndex effIndex)
{
    /// @todo create a proper pull towards distract spell center for distract
    EffectNULL(effIndex);
}

void Spell::EffectDistract(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    // Check for possible target
    if (!unitTarget || unitTarget->IsEngaged())
        return;

    // target must be OK to do this
    if (unitTarget->HasUnitState(UNIT_STATE_CONFUSED | UNIT_STATE_STUNNED | UNIT_STATE_FLEEING))
        return;

    unitTarget->GetMotionMaster()->MoveDistract(damage * IN_MILLISECONDS, unitTarget->GetAbsoluteAngle(destTarget));
}

void Spell::EffectPickPocket(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    // victim must be creature and attackable
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_UNIT || m_caster->IsFriendlyTo(unitTarget))
        return;

    // victim have to be alive and humanoid or undead
    if (unitTarget->IsAlive() && (unitTarget->GetCreatureTypeMask() &CREATURE_TYPEMASK_HUMANOID_OR_UNDEAD) != 0)
        m_caster->ToPlayer()->SendLoot(unitTarget->GetGUID(), LOOT_PICKPOCKETING);
}

void Spell::EffectAddFarsight(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    float radius = m_spellInfo->Effects[effIndex].CalcRadius();
    int32 duration = m_spellInfo->GetDuration();
    // Caster not in world, might be spell triggered from aura removal
    if (!player->IsInWorld())
        return;

    DynamicObject* dynObj = new DynamicObject(true);
    if (!dynObj->CreateDynamicObject(player->GetMap()->GenerateLowGuid<HighGuid::DynamicObject>(), player, m_spellInfo->Id, *destTarget, radius, DYNAMIC_OBJECT_FARSIGHT_FOCUS))
    {
        delete dynObj;
        return;
    }

    dynObj->SetDuration(duration);
    dynObj->SetCasterViewpoint();
}

void Spell::EffectUntrainTalents(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || m_caster->GetTypeId() == TYPEID_PLAYER)
        return;

    if (ObjectGuid guid = m_caster->GetGUID()) // the trainer is the caster
        unitTarget->ToPlayer()->SendTalentWipeConfirm(guid);
}

void Spell::EffectTeleUnitsFaceCaster(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (unitTarget->IsInFlight())
        return;

    float dis = m_spellInfo->Effects[effIndex].CalcRadius(m_caster);

    float fx, fy, fz;
    m_caster->GetClosePoint(fx, fy, fz, unitTarget->GetCombatReach(), dis);

    unitTarget->NearTeleportTo(fx, fy, fz, -m_caster->GetOrientation(), unitTarget == m_caster);
}

void Spell::EffectLearnSkill(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (damage < 0)
        return;

    uint32 skillid = m_spellInfo->Effects[effIndex].MiscValue;
    SkillRaceClassInfoEntry const* rcEntry = GetSkillRaceClassInfo(skillid, unitTarget->GetRace(), unitTarget->GetClass());
    if (!rcEntry)
        return;

    SkillTiersEntry const* tier = sSkillTiersStore.LookupEntry(rcEntry->SkillTier);
    if (!tier)
        return;

    uint16 skillval = unitTarget->ToPlayer()->GetPureSkillValue(skillid);
    unitTarget->ToPlayer()->SetSkill(skillid, m_spellInfo->Effects[effIndex].CalcValue(), std::max<uint16>(skillval, 1), tier->MaxSkill[damage - 1]);
}

void Spell::EffectAddHonor(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    // not scale value for item based reward (/10 value expected)
    if (m_CastItem)
    {
        unitTarget->ToPlayer()->RewardHonor(nullptr, 1, damage/10);
        TC_LOG_DEBUG("spells", "SpellEffect::AddHonor (spell_id %u) rewards %d honor points (item %u) for player: %u", m_spellInfo->Id, damage/10, m_CastItem->GetEntry(), unitTarget->ToPlayer()->GetGUID().GetCounter());
        return;
    }

    // do not allow to add too many honor for player (50 * 21) = 1040 at level 70, or (50 * 31) = 1550 at level 80
    if (damage <= 50)
    {
        uint32 honor_reward = Trinity::Honor::hk_honor_at_level(unitTarget->GetLevel(), float(damage));
        unitTarget->ToPlayer()->RewardHonor(nullptr, 1, honor_reward);
        TC_LOG_DEBUG("spells", "SpellEffect::AddHonor (spell_id %u) rewards %u honor points (scale) to player: %u", m_spellInfo->Id, honor_reward, unitTarget->ToPlayer()->GetGUID().GetCounter());
    }
    else
    {
        //maybe we have correct honor_gain in damage already
        unitTarget->ToPlayer()->RewardHonor(nullptr, 1, damage);
        TC_LOG_DEBUG("spells", "SpellEffect::AddHonor (spell_id %u) rewards %u honor points (non scale) for player: %u", m_spellInfo->Id, damage, unitTarget->ToPlayer()->GetGUID().GetCounter());
    }
}

void Spell::EffectTradeSkill(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;
    // uint32 skillid =  m_spellInfo->Effects[i].MiscValue;
    // uint16 skillmax = unitTarget->ToPlayer()->(skillid);
    // m_caster->ToPlayer()->SetSkill(skillid, skillval?skillval:1, skillmax+75);
}

void Spell::EffectEnchantItemPerm(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!itemTarget)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    // Handle vellums
    if (itemTarget->IsWeaponVellum() || itemTarget->IsArmorVellum())
    {
        // destroy one vellum from stack
        uint32 count = 1;
        player->DestroyItemCount(itemTarget, count, true);
        unitTarget = player;
        // and add a scroll
        DoCreateItem(effIndex, m_spellInfo->Effects[effIndex].ItemType);
        itemTarget = nullptr;
        m_targets.SetItemTarget(nullptr);
    }
    else
    {
        // do not increase skill if vellum used
        if (!(m_CastItem && m_CastItem->GetTemplate()->Flags & ITEM_FLAG_NO_REAGENT_COST))
            player->UpdateCraftSkill(m_spellInfo->Id);

        uint32 enchant_id = m_spellInfo->Effects[effIndex].MiscValue;
        if (!enchant_id)
            return;

        SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!pEnchant)
            return;

        // item can be in trade slot and have owner diff. from caster
        Player* item_owner = itemTarget->GetOwner();
        if (!item_owner)
            return;

        if (item_owner != player && player->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
        {
            sLog->outCommand(player->GetSession()->GetAccountId(), "GM %s (Account: %u) enchanting(perm): %s (Entry: %d) for player: %s (Account: %u)",
                player->GetName().c_str(), player->GetSession()->GetAccountId(),
                itemTarget->GetTemplate()->Name1.c_str(), itemTarget->GetEntry(),
                item_owner->GetName().c_str(), item_owner->GetSession()->GetAccountId());
        }

        // remove old enchanting before applying new if equipped
        item_owner->ApplyEnchantment(itemTarget, PERM_ENCHANTMENT_SLOT, false);

        itemTarget->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchant_id, 0, 0, m_caster->GetGUID());

        // add new enchanting if equipped
        item_owner->ApplyEnchantment(itemTarget, PERM_ENCHANTMENT_SLOT, true);

        item_owner->RemoveTradeableItem(itemTarget);
        itemTarget->ClearSoulboundTradeable(item_owner);
    }
}

void Spell::EffectEnchantItemPrismatic(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!itemTarget)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    uint32 enchantId = m_spellInfo->Effects[effIndex].MiscValue;
    if (!enchantId)
        return;

    SpellItemEnchantmentEntry const* enchant = sSpellItemEnchantmentStore.LookupEntry(enchantId);
    if (!enchant)
        return;

    // support only enchantings with add socket in this slot
    {
        bool add_socket = false;
        for (uint8 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; ++i)
        {
            if (enchant->type[i] == ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET)
            {
                add_socket = true;
                break;
            }
        }
        if (!add_socket)
        {
            TC_LOG_ERROR("spells", "Spell::EffectEnchantItemPrismatic: attempt to apply the enchant spell %u with SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC (%u), but without ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET (%u), not supported yet.",
                m_spellInfo->Id, SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC, ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET);
            return;
        }
    }

    // item can be in trade slot and have owner diff. from caster
    Player* item_owner = itemTarget->GetOwner();
    if (!item_owner)
        return;

    if (item_owner != player && player->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
    {
        sLog->outCommand(player->GetSession()->GetAccountId(), "GM %s (Account: %u) enchanting(perm): %s (Entry: %d) for player: %s (Account: %u)",
            player->GetName().c_str(), player->GetSession()->GetAccountId(),
            itemTarget->GetTemplate()->Name1.c_str(), itemTarget->GetEntry(),
            item_owner->GetName().c_str(), item_owner->GetSession()->GetAccountId());
    }

    // remove old enchanting before applying new if equipped
    item_owner->ApplyEnchantment(itemTarget, PRISMATIC_ENCHANTMENT_SLOT, false);

    itemTarget->SetEnchantment(PRISMATIC_ENCHANTMENT_SLOT, enchantId, 0, 0, m_caster->GetGUID());

    // add new enchanting if equipped
    item_owner->ApplyEnchantment(itemTarget, PRISMATIC_ENCHANTMENT_SLOT, true);

    item_owner->RemoveTradeableItem(itemTarget);
    itemTarget->ClearSoulboundTradeable(item_owner);
}

void Spell::EffectEnchantItemTmp(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    // Rockbiter Weapon apply to both weapon
    if (!itemTarget)
        return;
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_SHAMAN && m_spellInfo->SpellFamilyFlags[0] & 0x400000)
    {
        uint32 spell_id = 0;

        // enchanting spell selected by calculated damage-per-sec stored in Effect[1] base value
        // Note: damage calculated (correctly) with rounding int32(float(v)) but
        // RW enchantments applied damage int32(float(v)+0.5), this create  0..1 difference sometime
        switch (damage)
        {
            // Rank 1
            case  2: spell_id = 36744; break;               //  0% [ 7% == 2, 14% == 2, 20% == 2]
            // Rank 2
            case  4: spell_id = 36753; break;               //  0% [ 7% == 4, 14% == 4]
            case  5: spell_id = 36751; break;               // 20%
            // Rank 3
            case  6: spell_id = 36754; break;               //  0% [ 7% == 6, 14% == 6]
            case  7: spell_id = 36755; break;               // 20%
            // Rank 4
            case  9: spell_id = 36761; break;               //  0% [ 7% == 6]
            case 10: spell_id = 36758; break;               // 14%
            case 11: spell_id = 36760; break;               // 20%
            default:
                TC_LOG_ERROR("spells", "Spell::EffectEnchantItemTmp: Damage %u not handled in S'RW.", damage);
                return;
        }

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id);
        if (!spellInfo)
        {
            TC_LOG_ERROR("spells", "Spell::EffectEnchantItemTmp: unknown spell id %i", spell_id);
            return;

        }

        for (int j = BASE_ATTACK; j <= OFF_ATTACK; ++j)
        {
            if (Item* item = player->GetWeaponForAttack(WeaponAttackType(j)))
            {
                if (item->IsFitToSpellRequirements(m_spellInfo))
                {
                    Spell* spell = new Spell(m_caster, spellInfo, TRIGGERED_FULL_MASK);
                    SpellCastTargets targets;
                    targets.SetItemTarget(item);
                    spell->prepare(targets);
                }
            }
        }
        return;
    }

    uint32 enchant_id = m_spellInfo->Effects[effIndex].MiscValue;

    if (!enchant_id)
    {
        TC_LOG_ERROR("spells", "Spell %u Effect %u (SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY) has enchanting id 0.", m_spellInfo->Id, effIndex);
        return;
    }

    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
    if (!pEnchant)
    {
        TC_LOG_ERROR("spells", "Spell %u Effect %u (SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY) has a non-existing enchanting id %u ", m_spellInfo->Id, effIndex, enchant_id);
        return;
    }

    // select enchantment duration
    uint32 duration;

    // rogue family enchantments exception by duration
    if (m_spellInfo->Id == 38615)
        duration = 1800;                                    // 30 mins
    // other rogue family enchantments always 1 hour (some have spell damage=0, but some have wrong data in EffBasePoints)
    else if (m_spellInfo->SpellFamilyName == SPELLFAMILY_ROGUE)
        duration = 3600;                                    // 1 hour
    // shaman family enchantments
    else if (m_spellInfo->SpellFamilyName == SPELLFAMILY_SHAMAN)
        duration = 1800;                                    // 30 mins
    // other cases with this SpellVisual already selected
    else if (m_spellInfo->SpellVisual[0] == 215)
        duration = 1800;                                    // 30 mins
    // some fishing pole bonuses except Glow Worm which lasts full hour
    else if (m_spellInfo->SpellVisual[0] == 563 && m_spellInfo->Id != 64401)
        duration = 600;                                     // 10 mins
    // shaman rockbiter enchantments
    else if (m_spellInfo->SpellVisual[0] == 0)
        duration = 1800;                                    // 30 mins
    else if (m_spellInfo->Id == 29702)
        duration = 300;                                     // 5 mins
    else if (m_spellInfo->Id == 37360)
        duration = 300;                                     // 5 mins
    // default case
    else
        duration = 3600;                                    // 1 hour

    // item can be in trade slot and have owner diff. from caster
    Player* item_owner = itemTarget->GetOwner();
    if (!item_owner)
        return;

    if (item_owner != player && player->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
    {
        sLog->outCommand(player->GetSession()->GetAccountId(), "GM %s (Account: %u) enchanting(temp): %s (Entry: %d) for player: %s (Account: %u)",
            player->GetName().c_str(), player->GetSession()->GetAccountId(),
            itemTarget->GetTemplate()->Name1.c_str(), itemTarget->GetEntry(),
            item_owner->GetName().c_str(), item_owner->GetSession()->GetAccountId());
    }

    // remove old enchanting before applying new if equipped
    item_owner->ApplyEnchantment(itemTarget, TEMP_ENCHANTMENT_SLOT, false);

    itemTarget->SetEnchantment(TEMP_ENCHANTMENT_SLOT, enchant_id, duration * 1000, 0, m_caster->GetGUID());

    // add new enchanting if equipped
    item_owner->ApplyEnchantment(itemTarget, TEMP_ENCHANTMENT_SLOT, true);
}

void Spell::EffectTameCreature(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitCaster || unitCaster->GetPetGUID())
        return;

    if (!unitTarget)
        return;

    if (unitTarget->GetTypeId() != TYPEID_UNIT)
        return;

    Creature* creatureTarget = unitTarget->ToCreature();

    if (creatureTarget->IsPet())
        return;

    if (unitCaster->GetClass() != CLASS_HUNTER)
        return;

    // cast finish successfully
    //SendChannelUpdate(0);
    finish();

    Pet* pet = unitCaster->CreateTamedPetFrom(creatureTarget, m_spellInfo->Id);
    if (!pet)                                               // in very specific state like near world end/etc.
        return;

    // "kill" original creature
    creatureTarget->DespawnOrUnsummon();

    uint8 level = (creatureTarget->GetLevel() < (unitCaster->GetLevel() - 5)) ? (unitCaster->GetLevel() - 5) : creatureTarget->GetLevel();

    // prepare visual effect for levelup
    pet->SetUInt32Value(UNIT_FIELD_LEVEL, level - 1);

    // add to world
    pet->GetMap()->AddToMap(pet->ToCreature());

    // visual effect for levelup
    pet->SetUInt32Value(UNIT_FIELD_LEVEL, level);

    // caster have pet now
    unitCaster->SetMinion(pet, true);

    pet->InitTalentForLevel();

    if (unitCaster->GetTypeId() == TYPEID_PLAYER)
    {
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        unitCaster->ToPlayer()->PetSpellInitialize();
    }
}

void Spell::EffectSummonPet(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Player* owner = nullptr;
    if (unitCaster)
    {
        owner = unitCaster->ToPlayer();
        if (!owner && unitCaster->IsTotem())
            owner = unitCaster->GetCharmerOrOwnerPlayerOrPlayerItself();
    }

    uint32 petentry = m_spellInfo->Effects[effIndex].MiscValue;

    if (!owner)
    {
        SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(67);
        if (properties)
            SummonGuardian(effIndex, petentry, properties, 1);
        return;
    }

    Pet* OldSummon = owner->GetPet();

    // if pet requested type already exist
    if (OldSummon)
    {
        if (petentry == 0 || OldSummon->GetEntry() == petentry)
        {
            // pet in corpse state can't be summoned
            if (OldSummon->isDead())
                return;

            ASSERT(OldSummon->GetMap() == owner->GetMap());

            //OldSummon->GetMap()->Remove(OldSummon->ToCreature(), false);

            float px, py, pz;
            owner->GetClosePoint(px, py, pz, OldSummon->GetCombatReach());

            OldSummon->NearTeleportTo(px, py, pz, OldSummon->GetOrientation());
            //OldSummon->Relocate(px, py, pz, OldSummon->GetOrientation());
            //OldSummon->SetMap(owner->GetMap());
            //owner->GetMap()->Add(OldSummon->ToCreature());
            if (OldSummon->getPetType() == SUMMON_PET)
            {
                OldSummon->SetHealth(OldSummon->GetMaxHealth());
                OldSummon->SetPower(OldSummon->GetPowerType(),
                    OldSummon->GetMaxPower(OldSummon->GetPowerType()));
            }

            if (owner->GetTypeId() == TYPEID_PLAYER && OldSummon->isControlled())
                owner->ToPlayer()->PetSpellInitialize();

            return;
        }

        if (owner->GetTypeId() == TYPEID_PLAYER)
            owner->ToPlayer()->RemovePet(OldSummon, (OldSummon->getPetType() == HUNTER_PET ? PET_SAVE_AS_DELETED : PET_SAVE_NOT_IN_SLOT), false);
        else
            return;
    }

    float x, y, z;
    owner->GetClosePoint(x, y, z, owner->GetCombatReach());
    Pet* pet = owner->SummonPet(petentry, x, y, z, owner->GetOrientation(), SUMMON_PET, 0, true);
    if (!pet)
        return;

    if (m_caster->GetTypeId() == TYPEID_UNIT)
    {
        if (m_caster->ToCreature()->IsTotem())
            pet->SetReactState(REACT_AGGRESSIVE);
        else
            pet->SetReactState(REACT_DEFENSIVE);
    }

    pet->SetUInt32Value(UNIT_CREATED_BY_SPELL, m_spellInfo->Id);

    // generate new name for summon pet
    std::string new_name = sObjectMgr->GeneratePetName(petentry);
    if (!new_name.empty())
        pet->SetName(new_name);

    ExecuteLogEffectSummonObject(effIndex, pet);
}

void Spell::EffectLearnPetSpell(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (unitTarget->ToPlayer())
    {
        EffectLearnSpell(effIndex);
        return;
    }
    Pet* pet = unitTarget->ToPet();
    if (!pet)
        return;

    SpellInfo const* learn_spellproto = sSpellMgr->GetSpellInfo(m_spellInfo->Effects[effIndex].TriggerSpell);
    if (!learn_spellproto)
        return;

    pet->learnSpell(learn_spellproto->Id);
    pet->SavePetToDB(PET_SAVE_AS_CURRENT);
    pet->GetOwner()->PetSpellInitialize();
}

void Spell::EffectTaunt(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitCaster)
        return;

    // this effect use before aura Taunt apply for prevent taunt already attacking target
    // for spell as marked "non effective at already attacking target"
    if (!unitTarget || unitTarget->IsTotem())
    {
        SendCastResult(SPELL_FAILED_DONT_REPORT);
        return;
    }

    // Hand of Reckoning can hit some entities that can't have a threat list (including players' pets)
    if (m_spellInfo->Id == 62124)
        if (unitTarget->GetTypeId() != TYPEID_PLAYER && unitTarget->GetTarget() != unitCaster->GetGUID())
            unitCaster->CastSpell(unitTarget, 67485, true);

    if (!unitTarget->CanHaveThreatList())
    {
        SendCastResult(SPELL_FAILED_DONT_REPORT);
        return;
    }

    ThreatManager& mgr = unitTarget->GetThreatManager();
    if (mgr.GetCurrentVictim() == unitCaster)
    {
        SendCastResult(SPELL_FAILED_DONT_REPORT);
        return;
    }

    if (!mgr.IsThreatListEmpty())
        // Set threat equal to highest threat currently on target
        mgr.MatchUnitThreatToHighestThreat(unitCaster);
}

void Spell::EffectWeaponDmg(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (!unitCaster)
        return;

    if (!unitTarget || !unitTarget->IsAlive())
        return;

    // multiple weapon dmg effect workaround
    // execute only the last weapon damage
    // and handle all effects at once
    for (uint8 j = effIndex + 1; j < MAX_SPELL_EFFECTS; ++j)
    {
        switch (m_spellInfo->Effects[j].Effect)
        {
            case SPELL_EFFECT_WEAPON_DAMAGE:
            case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
            case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
            case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                return;     // we must calculate only at last weapon effect
            break;
        }
    }

    // some spell specific modifiers
    float totalDamagePercentMod  = 1.0f;                    // applied to final bonus+weapon damage
    int32 fixed_bonus = 0;
    int32 spell_bonus = 0;                                  // bonus specific for spell

    switch (m_spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_WARRIOR:
        {
            // Devastate (player ones)
            if (m_spellInfo->SpellFamilyFlags[1] & 0x40)
            {
                unitCaster->CastSpell(unitTarget, 58567, true);
                // 58388 - Glyph of Devastate dummy aura.
                if (unitCaster->HasAura(58388))
                    unitCaster->CastSpell(unitTarget, 58567, true);

                if (Aura* aur = unitTarget->GetAura(58567, unitCaster->GetGUID()))
                    fixed_bonus += (aur->GetStackAmount() - 1) * CalculateDamage(EFFECT_2); // subtract 1 so fixed bonus is not applied twice
            }
            else if (m_spellInfo->SpellFamilyFlags[0] & 0x8000000) // Mocking Blow
            {
                if (unitTarget->IsImmunedToSpellEffect(m_spellInfo, EFFECT_1, unitCaster) || unitTarget->GetTypeId() == TYPEID_PLAYER)
                {
                    m_damage = 0;
                    return;
                }
            }
            break;
        }
        case SPELLFAMILY_ROGUE:
        {
            // Fan of Knives, Hemorrhage, Ghostly Strike
            if ((m_spellInfo->SpellFamilyFlags[1] & 0x40000)
                || (m_spellInfo->SpellFamilyFlags[0] & 0x6000000))
            {
                // Hemorrhage
                if (m_spellInfo->SpellFamilyFlags[0] & 0x2000000)
                    AddComboPointGain(unitTarget, 1);

                // 50% more damage with daggers
                if (unitCaster->GetTypeId() == TYPEID_PLAYER)
                    if (Item* item = unitCaster->ToPlayer()->GetWeaponForAttack(m_attackType, true))
                        if (item->GetTemplate()->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER)
                            totalDamagePercentMod *= 1.5f;
            }
            // Mutilate (for each hand)
            else if (m_spellInfo->SpellFamilyFlags[1] & 0x6)
            {
                bool found = false;
                // fast check
                if (unitTarget->HasAuraState(AURA_STATE_DEADLY_POISON, m_spellInfo, unitCaster))
                    found = true;
                // full aura scan
                else
                {
                    Unit::AuraApplicationMap const& auras = unitTarget->GetAppliedAuras();
                    for (Unit::AuraApplicationMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                    {
                        if (itr->second->GetBase()->GetSpellInfo()->Dispel == DISPEL_POISON)
                        {
                            found = true;
                            break;
                        }
                    }
                }

                if (found)
                    totalDamagePercentMod *= 1.2f;          // 120% if poisoned
            }
            break;
        }
        case SPELLFAMILY_PALADIN:
        {
            // Seal of Command Unleashed
            if (m_spellInfo->Id == 20467)
            {
                spell_bonus += int32(0.08f * unitCaster->GetTotalAttackPowerValue(BASE_ATTACK));
                spell_bonus += int32(0.13f * unitCaster->SpellBaseDamageBonusDone(m_spellInfo->GetSchoolMask()));
            }
            break;
        }
        case SPELLFAMILY_SHAMAN:
        {
            // Skyshatter Harness item set bonus
            // Stormstrike
            if (AuraEffect* aurEff = unitCaster->IsScriptOverriden(m_spellInfo, 5634))
                unitCaster->CastSpell(nullptr, 38430, aurEff);
            break;
        }
        case SPELLFAMILY_DRUID:
        {
            // Mangle (Cat): CP
            if (m_spellInfo->SpellFamilyFlags[1] & 0x400)
                AddComboPointGain(unitTarget, 1);

            // Shred, Maul - Rend and Tear
            else if (m_spellInfo->SpellFamilyFlags[0] & 0x00008800 && unitTarget->HasAuraState(AURA_STATE_BLEEDING))
            {
                if (AuraEffect const* rendAndTear = unitCaster->GetDummyAuraEffect(SPELLFAMILY_DRUID, 2859, 0))
                    AddPct(totalDamagePercentMod, rendAndTear->GetAmount());
            }
            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            // Kill Shot - bonus damage from Ranged Attack Power
            if (m_spellInfo->SpellFamilyFlags[1] & 0x800000)
                spell_bonus += int32(0.4f * unitCaster->GetTotalAttackPowerValue(RANGED_ATTACK));
            break;
        }
        case SPELLFAMILY_DEATHKNIGHT:
        {
            // Plague Strike
            if (m_spellInfo->SpellFamilyFlags[0] & 0x1)
            {
                // Glyph of Plague Strike
                if (AuraEffect const* aurEff = unitCaster->GetAuraEffect(58657, EFFECT_0))
                    AddPct(totalDamagePercentMod, aurEff->GetAmount());
                break;
            }
            // Blood Strike
            if (m_spellInfo->SpellFamilyFlags[0] & 0x400000)
            {
                float bonusPct = m_spellInfo->Effects[EFFECT_2].CalcValue() * unitTarget->GetDiseasesByCaster(unitCaster->GetGUID()) / 2.0f;
                // Death Knight T8 Melee 4P Bonus
                if (AuraEffect const* aurEff = unitCaster->GetAuraEffect(64736, EFFECT_0))
                    AddPct(bonusPct, aurEff->GetAmount());
                AddPct(totalDamagePercentMod, bonusPct);

                // Glyph of Blood Strike
                if (unitCaster->GetAuraEffect(59332, EFFECT_0))
                    if (unitTarget->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED))
                       AddPct(totalDamagePercentMod, 20);
                break;
            }
            // Death Strike
            if (m_spellInfo->SpellFamilyFlags[0] & 0x10)
            {
                // Glyph of Death Strike
                if (AuraEffect const* aurEff = unitCaster->GetAuraEffect(59336, EFFECT_0))
                    if (uint32 runic = std::min<uint32>(unitCaster->GetPower(POWER_RUNIC_POWER), aurEff->GetSpellInfo()->Effects[EFFECT_1].CalcValue()))
                        AddPct(totalDamagePercentMod, runic);
                break;
            }
            // Obliterate (12.5% more damage per disease)
            if (m_spellInfo->SpellFamilyFlags[1] & 0x20000)
            {
                bool consumeDiseases = true;
                // Annihilation
                if (AuraEffect const* aurEff = unitCaster->GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, 2710, EFFECT_0))
                    // Do not consume diseases if roll sucesses
                    if (roll_chance_i(aurEff->GetAmount()))
                        consumeDiseases = false;

                float bonusPct = m_spellInfo->Effects[EFFECT_2].CalcValue() * unitTarget->GetDiseasesByCaster(unitCaster->GetGUID(), consumeDiseases) / 2.0f;
                // Death Knight T8 Melee 4P Bonus
                if (AuraEffect const* aurEff = unitCaster->GetAuraEffect(64736, EFFECT_0))
                    AddPct(bonusPct, aurEff->GetAmount());
                AddPct(totalDamagePercentMod, bonusPct);
                break;
            }
            // Blood-Caked Strike - Blood-Caked Blade
            if (m_spellInfo->SpellIconID == 1736)
            {
                AddPct(totalDamagePercentMod, unitTarget->GetDiseasesByCaster(unitCaster->GetGUID()) * 50.0f);
                break;
            }
            // Heart Strike
            if (m_spellInfo->SpellFamilyFlags[0] & 0x1000000)
            {
                float bonusPct = m_spellInfo->Effects[EFFECT_2].CalcValue() * unitTarget->GetDiseasesByCaster(unitCaster->GetGUID());
                // Death Knight T8 Melee 4P Bonus
                if (AuraEffect const* aurEff = unitCaster->GetAuraEffect(64736, EFFECT_0))
                    AddPct(bonusPct, aurEff->GetAmount());

                AddPct(totalDamagePercentMod, bonusPct);
                break;
            }
            break;
        }
    }

    bool normalized = false;
    float weaponDamagePercentMod = 1.0f;
    for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
    {
        switch (m_spellInfo->Effects[j].Effect)
        {
            case SPELL_EFFECT_WEAPON_DAMAGE:
            case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                fixed_bonus += CalculateDamage(j);
                break;
            case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                fixed_bonus += CalculateDamage(j);
                normalized = true;
                break;
            case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                ApplyPct(weaponDamagePercentMod, CalculateDamage(j));
                break;
            default:
                break;                                      // not weapon damage effect, just skip
        }
    }

    // if (addPctMods) { percent mods are added in Unit::CalculateDamage } else { percent mods are added in Unit::MeleeDamageBonusDone }
    // this distinction is neccessary to properly inform the client about his autoattack damage values from Script_UnitDamage
    bool const addPctMods = !m_spellInfo->HasAttribute(SPELL_ATTR6_LIMIT_PCT_DAMAGE_MODS) && (m_spellSchoolMask & SPELL_SCHOOL_MASK_NORMAL);
    if (addPctMods)
    {
        UnitMods unitMod;
        switch (m_attackType)
        {
            default:
            case BASE_ATTACK:   unitMod = UNIT_MOD_DAMAGE_MAINHAND; break;
            case OFF_ATTACK:    unitMod = UNIT_MOD_DAMAGE_OFFHAND;  break;
            case RANGED_ATTACK: unitMod = UNIT_MOD_DAMAGE_RANGED;   break;
        }

        float weapon_total_pct = unitCaster->GetPctModifierValue(unitMod, TOTAL_PCT);
        if (fixed_bonus)
            fixed_bonus = int32(fixed_bonus * weapon_total_pct);
        if (spell_bonus)
            spell_bonus = int32(spell_bonus * weapon_total_pct);
    }

    int32 weaponDamage = unitCaster->CalculateDamage(m_attackType, normalized, addPctMods);

    // Sequence is important
    for (uint8 j = 0; j < MAX_SPELL_EFFECTS; ++j)
    {
        // We assume that a spell have at most one fixed_bonus
        // and at most one weaponDamagePercentMod
        switch (m_spellInfo->Effects[j].Effect)
        {
            case SPELL_EFFECT_WEAPON_DAMAGE:
            case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
            case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                weaponDamage += fixed_bonus;
                break;
            case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                weaponDamage = int32(weaponDamage * weaponDamagePercentMod);
                break;
            default:
                break;                                      // not weapon damage effect, just skip
        }
    }

    weaponDamage += spell_bonus;
    weaponDamage = int32(weaponDamage * totalDamagePercentMod);

    // apply spellmod to Done damage
    if (Player* modOwner = unitCaster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_DAMAGE, weaponDamage);

    // prevent negative damage
    weaponDamage = std::max(weaponDamage, 0);

    // Add melee damage bonuses (also check for negative)
    weaponDamage = unitCaster->MeleeDamageBonusDone(unitTarget, weaponDamage, m_attackType, m_spellInfo);
    m_damage += unitTarget->MeleeDamageBonusTaken(unitCaster, weaponDamage, m_attackType, m_spellInfo);
}

void Spell::EffectThreat(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitCaster || !unitCaster->IsAlive())
        return;

    if (!unitTarget)
        return;

    if (!unitTarget->CanHaveThreatList())
        return;

    unitTarget->GetThreatManager().AddThreat(unitCaster, float(damage), m_spellInfo, true);
}

void Spell::EffectHealMaxHealth(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitCaster)
        return;

    if (!unitTarget || !unitTarget->IsAlive())
        return;

    int32 addhealth = 0;

    // damage == 0 - heal for caster max health
    if (damage == 0)
        addhealth = unitCaster->GetMaxHealth();
    else
        addhealth = unitTarget->GetMaxHealth() - unitTarget->GetHealth();

    m_healing += addhealth;
}

void Spell::EffectInterruptCast(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive())
        return;

    /// @todo not all spells that used this effect apply cooldown at school spells
    // also exist case: apply cooldown to interrupted cast only and to all spells
    // there is no CURRENT_AUTOREPEAT_SPELL spells that can be interrupted
    for (uint32 i = CURRENT_FIRST_NON_MELEE_SPELL; i < CURRENT_AUTOREPEAT_SPELL; ++i)
    {
        if (Spell* spell = unitTarget->GetCurrentSpell(CurrentSpellTypes(i)))
        {
            SpellInfo const* curSpellInfo = spell->m_spellInfo;
            // check if we can interrupt spell
            if ((spell->getState() == SPELL_STATE_CASTING
                || (spell->getState() == SPELL_STATE_PREPARING && spell->GetCastTime() > 0.0f))
                && curSpellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE
                && ((i == CURRENT_GENERIC_SPELL && curSpellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_INTERRUPT)
                || (i == CURRENT_CHANNELED_SPELL && curSpellInfo->ChannelInterruptFlags & CHANNEL_INTERRUPT_FLAG_INTERRUPT)))
            {
                if (unitCaster)
                {
                    int32 duration = m_spellInfo->GetDuration();
                    unitTarget->GetSpellHistory()->LockSpellSchool(curSpellInfo->GetSchoolMask(), unitTarget->ModSpellDuration(m_spellInfo, unitTarget, duration, false, 1 << effIndex));
                    if (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC)
                        Unit::ProcSkillsAndAuras(unitCaster, unitTarget, PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG, PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_NEG,
                            PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_HIT, PROC_HIT_INTERRUPT, nullptr, nullptr, nullptr);
                    else if (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE)
                        Unit::ProcSkillsAndAuras(unitCaster, unitTarget, PROC_FLAG_DONE_SPELL_MELEE_DMG_CLASS, PROC_FLAG_TAKEN_SPELL_MELEE_DMG_CLASS,
                            PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_HIT, PROC_HIT_INTERRUPT, nullptr, nullptr, nullptr);
                }
                ExecuteLogEffectInterruptCast(effIndex, unitTarget, curSpellInfo->Id);
                unitTarget->InterruptSpell(CurrentSpellTypes(i), false);
            }
        }
    }
}

void Spell::EffectSummonObjectWild(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    uint32 gameobject_id = m_spellInfo->Effects[effIndex].MiscValue;

    GameObject* pGameObj = new GameObject();

    WorldObject* target = focusObject;
    if (!target)
        target = m_caster;

    float x, y, z;
    if (m_targets.HasDst())
        destTarget->GetPosition(x, y, z);
    else
        m_caster->GetClosePoint(x, y, z, DEFAULT_PLAYER_BOUNDING_RADIUS);

    Map* map = target->GetMap();

    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(target->GetOrientation(), 0.f, 0.f);
    if (!pGameObj->Create(map->GenerateLowGuid<HighGuid::GameObject>(), gameobject_id, map, m_caster->GetPhaseMask(), Position(x, y, z, target->GetOrientation()), rot, 255, GO_STATE_READY))
    {
        delete pGameObj;
        return;
    }

    int32 duration = m_spellInfo->GetDuration();

    pGameObj->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
    pGameObj->SetSpellId(m_spellInfo->Id);

    ExecuteLogEffectSummonObject(effIndex, pGameObj);

    // Wild object not have owner and check clickable by players
    map->AddToMap(pGameObj);

    if (pGameObj->GetGoType() == GAMEOBJECT_TYPE_FLAGDROP)
        if (Player* player = m_caster->ToPlayer())
            if (Battleground* bg = player->GetBattleground())
                bg->SetDroppedFlagGUID(pGameObj->GetGUID(), player->GetTeam() == ALLIANCE ? TEAM_HORDE: TEAM_ALLIANCE);

    if (GameObject* linkedTrap = pGameObj->GetLinkedTrap())
    {
        linkedTrap->SetRespawnTime(duration > 0 ? duration / IN_MILLISECONDS : 0);
        linkedTrap->SetSpellId(m_spellInfo->Id);

        ExecuteLogEffectSummonObject(effIndex, linkedTrap);
    }
}

void Spell::EffectScriptEffect(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    /// @todo we must implement hunter pet summon at login there (spell 6962)
    /// @todo: move this to scripts
    switch (m_spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            switch (m_spellInfo->Id)
            {
                // Shadow Flame (All script effects, not just end ones to prevent player from dodging the last triggered spell)
                case 22539:
                case 22972:
                case 22975:
                case 22976:
                case 22977:
                case 22978:
                case 22979:
                case 22980:
                case 22981:
                case 22982:
                case 22983:
                case 22984:
                case 22985:
                {
                    if (!unitTarget || !unitTarget->IsAlive())
                        return;

                    // Onyxia Scale Cloak
                    if (unitTarget->HasAura(22683))
                        return;

                    // Shadow Flame
                    m_caster->CastSpell(unitTarget, 22682, true);
                    return;
                }
                // Mug Transformation
                case 41931:
                {
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    uint8 bag = 19;
                    uint8 slot = 0;
                    Item* item = nullptr;

                    while (bag) // 256 = 0 due to var type
                    {
                        item = m_caster->ToPlayer()->GetItemByPos(bag, slot);
                        if (item && item->GetEntry() == 38587)
                            break;

                        ++slot;
                        if (slot == 39)
                        {
                            slot = 0;
                            ++bag;
                        }
                    }
                    if (bag)
                    {
                        if (m_caster->ToPlayer()->GetItemByPos(bag, slot)->GetCount() == 1) m_caster->ToPlayer()->RemoveItem(bag, slot, true);
                        else m_caster->ToPlayer()->GetItemByPos(bag, slot)->SetCount(m_caster->ToPlayer()->GetItemByPos(bag, slot)->GetCount()-1);
                        // Spell 42518 (Braufest - Gratisprobe des Braufest herstellen)
                        m_caster->CastSpell(m_caster, 42518, true);
                        return;
                    }
                    break;
                }
                // Brutallus - Burn
                case 45141:
                case 45151:
                {
                    //Workaround for Range ... should be global for every ScriptEffect
                    float radius = m_spellInfo->Effects[effIndex].CalcRadius();
                    if (unitTarget && unitTarget->GetTypeId() == TYPEID_PLAYER && unitTarget->GetDistance(m_caster) >= radius && !unitTarget->HasAura(46394) && unitTarget != m_caster)
                        unitTarget->CastSpell(unitTarget, 46394, true);

                    break;
                }
                // Summon Ghouls On Scarlet Crusade
                case 51904:
                {
                    if (!m_targets.HasDst())
                        return;

                    float x, y, z;
                    float radius = m_spellInfo->Effects[effIndex].CalcRadius();
                    for (uint8 i = 0; i < 15; ++i)
                    {
                        m_caster->GetRandomPoint(*destTarget, radius, x, y, z);
                        m_caster->CastSpell({x, y, z}, 54522, true);
                    }
                    break;
                }
                case 52173: // Coyote Spirit Despawn
                case 60243: // Blood Parrot Despawn
                    if (unitTarget->GetTypeId() == TYPEID_UNIT && unitTarget->IsSummon())
                        unitTarget->ToTempSummon()->UnSummon();
                    return;
                case 52479: // Gift of the Harvester
                    if (unitTarget && unitCaster)
                        unitCaster->CastSpell(unitTarget, urand(0, 1) ? damage : 52505, true);
                    return;
                case 57347: // Retrieving (Wintergrasp RP-GG pickup spell)
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_UNIT || m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    unitTarget->ToCreature()->DespawnOrUnsummon();

                    return;
                }
                case 57349: // Drop RP-GG (Wintergrasp RP-GG at death drop spell)
                {
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // Delete item from inventory at death
                    m_caster->ToPlayer()->DestroyItemCount(damage, 5, true);

                    return;
                }
                case 62482: // Grab Crate
                {
                    if (!unitCaster)
                        return;

                    if (unitTarget)
                    {
                        if (Unit* seat = unitCaster->GetVehicleBase())
                        {
                            if (Unit* parent = seat->GetVehicleBase())
                            {
                                /// @todo a hack, range = 11, should after some time cast, otherwise too far
                                unitCaster->CastSpell(parent, 62496, true);
                                unitTarget->CastSpell(parent, m_spellInfo->Effects[EFFECT_0].CalcValue());
                            }
                        }
                    }
                    return;
                }
            }
            break;
        }
    }

    // normal DB scripted effect
    TC_LOG_DEBUG("spells", "Spell ScriptStart spellid %u in EffectScriptEffect(%u)", m_spellInfo->Id, effIndex);
    m_caster->GetMap()->ScriptsStart(sSpellScripts, uint32(m_spellInfo->Id | (effIndex << 24)), m_caster, unitTarget);
}

void Spell::EffectSanctuary(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (unitTarget->GetTypeId() == TYPEID_PLAYER && !unitTarget->GetMap()->IsDungeon())
    {
        // stop all pve combat for players outside dungeons, suppress pvp combat
        unitTarget->CombatStop(false, false);
    }
    else
    {
        // in dungeons (or for nonplayers), reset this unit on all enemies' threat lists
        for (auto const& pair : unitTarget->GetThreatManager().GetThreatenedByMeList())
            pair.second->ScaleThreat(0.0f);
    }

    // makes spells cast before this time fizzle
    unitTarget->m_lastSanctuaryTime = GameTime::GetGameTimeMS();
}

void Spell::EffectAddComboPoints(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (damage <= 0)
        return;

    AddComboPointGain(unitTarget, damage);
}

void Spell::EffectDuel(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || m_caster->GetTypeId() != TYPEID_PLAYER || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* caster = m_caster->ToPlayer();
    Player* target = unitTarget->ToPlayer();

    // caster or target already have requested duel
    if (caster->duel || target->duel || !target->GetSocial() || target->GetSocial()->HasIgnore(caster->GetGUID()))
        return;

    // Players can only fight a duel in zones with this flag
    AreaTableEntry const* casterAreaEntry = sAreaTableStore.LookupEntry(caster->GetAreaId());
    if (casterAreaEntry && !(casterAreaEntry->flags & AREA_FLAG_ALLOW_DUELS))
    {
        SendCastResult(SPELL_FAILED_NO_DUELING);            // Dueling isn't allowed here
        return;
    }

    AreaTableEntry const* targetAreaEntry = sAreaTableStore.LookupEntry(target->GetAreaId());
    if (targetAreaEntry && !(targetAreaEntry->flags & AREA_FLAG_ALLOW_DUELS))
    {
        SendCastResult(SPELL_FAILED_NO_DUELING);            // Dueling isn't allowed here
        return;
    }

    //CREATE DUEL FLAG OBJECT
    GameObject* pGameObj = new GameObject;

    uint32 gameobject_id = m_spellInfo->Effects[effIndex].MiscValue;

    Position const pos =
    {
        caster->GetPositionX() + (unitTarget->GetPositionX() - caster->GetPositionX()) / 2,
        caster->GetPositionY() + (unitTarget->GetPositionY() - caster->GetPositionY()) / 2,
        caster->GetPositionZ(),
        caster->GetOrientation()
    };

    Map* map = caster->GetMap();
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(pos.GetOrientation(), 0.f, 0.f);
    if (!pGameObj->Create(map->GenerateLowGuid<HighGuid::GameObject>(), gameobject_id, map, caster->GetPhaseMask(), pos, rot, 0, GO_STATE_READY))
    {
        delete pGameObj;
        return;
    }

    pGameObj->SetFaction(caster->GetFaction());
    pGameObj->SetUInt32Value(GAMEOBJECT_LEVEL, caster->GetLevel() + 1);
    int32 duration = m_spellInfo->GetDuration();
    pGameObj->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
    pGameObj->SetSpellId(m_spellInfo->Id);

    ExecuteLogEffectSummonObject(effIndex, pGameObj);

    caster->AddGameObject(pGameObj);
    map->AddToMap(pGameObj);
    //END

    // Send request
    WorldPacket data(SMSG_DUEL_REQUESTED, 8 + 8);
    data << uint64(pGameObj->GetGUID());
    data << uint64(caster->GetGUID());
    caster->SendDirectMessage(&data);
    target->SendDirectMessage(&data);

    // create duel-info
    bool isMounted = (GetSpellInfo()->Id == 62875);
    caster->duel = std::make_unique<DuelInfo>(target, caster, isMounted);
    target->duel = std::make_unique<DuelInfo>(caster, caster, isMounted);

    caster->SetGuidValue(PLAYER_DUEL_ARBITER, pGameObj->GetGUID());
    target->SetGuidValue(PLAYER_DUEL_ARBITER, pGameObj->GetGUID());

    sScriptMgr->OnPlayerDuelRequest(target, caster);
}

void Spell::EffectStuck(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!sWorld->getBoolConfig(CONFIG_CAST_UNSTUCK))
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    TC_LOG_DEBUG("spells", "Spell Effect: Stuck");
    TC_LOG_DEBUG("spells", "Player %s (guid %u) used the auto-unstuck feature at map %u (%f, %f, %f).", player->GetName().c_str(), player->GetGUID().GetCounter(), player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());

    if (player->IsInFlight())
        return;

    // if player is dead - teleport to graveyard
    if (!player->IsAlive())
    {
        if (player->HasAuraType(SPELL_AURA_PREVENT_RESURRECTION))
            return;

        // player is in corpse
        if (!player->HasFlag(PLAYER_FLAGS, PLAYER_FLAGS_GHOST))
            player->BuildPlayerRepop();
        player->RepopAtGraveyard();
        return;
    }

    // no hearthstone in bag or on cooldown
    Item* hearthStone = player->GetItemByEntry(6948 /*Hearthstone*/);
    if (!hearthStone || player->GetSpellHistory()->HasCooldown(8690 /*Spell Hearthstone*/))
    {
        float o = rand_norm() * 2 * M_PI;
        Position pos = *player;
        player->MovePositionToFirstCollision(pos, 5.0f, o);
        player->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), player->GetOrientation());
        return;
    }

    // we have hearthstone not on cooldown, just use it
    player->CastSpell(player, 8690, TriggerCastFlags(TRIGGERED_FULL_MASK&~TRIGGERED_IGNORE_SPELL_AND_CATEGORY_CD));
}

void Spell::EffectSummonPlayer(SpellEffIndex /*effIndex*/)
{
    // workaround - this effect should not use target map
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitCaster)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->SendSummonRequestFrom(unitCaster);
}

void Spell::EffectActivateObject(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!gameObjTarget)
        return;

    ScriptInfo activateCommand;
    activateCommand.command = SCRIPT_COMMAND_ACTIVATE_OBJECT;

    // int32 unk = m_spellInfo->Effects[effIndex].MiscValue; // This is set for EffectActivateObject spells; needs research

    gameObjTarget->GetMap()->ScriptCommandStart(activateCommand, 0, m_caster, gameObjTarget);
}

void Spell::EffectApplyGlyph(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_glyphIndex >= MAX_GLYPH_SLOT_INDEX)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    // glyph sockets level requirement
    uint8 minLevel = 0;
    switch (m_glyphIndex)
    {
        case 0:
        case 1: minLevel = 15; break;
        case 2: minLevel = 50; break;
        case 3: minLevel = 30; break;
        case 4: minLevel = 70; break;
        case 5: minLevel = 80; break;
    }
    if (minLevel && player->GetLevel() < minLevel)
    {
        SendCastResult(SPELL_FAILED_GLYPH_SOCKET_LOCKED);
        return;
    }

    // apply new one
    if (uint32 glyph = m_spellInfo->Effects[effIndex].MiscValue)
    {
        if (GlyphPropertiesEntry const* gp = sGlyphPropertiesStore.LookupEntry(glyph))
        {
            if (GlyphSlotEntry const* gs = sGlyphSlotStore.LookupEntry(player->GetGlyphSlot(m_glyphIndex)))
            {
                if (gp->TypeFlags != gs->TypeFlags)
                {
                    SendCastResult(SPELL_FAILED_INVALID_GLYPH);
                    return;                                 // glyph slot mismatch
                }
            }

            // remove old glyph
            if (uint32 oldglyph = player->GetGlyph(m_glyphIndex))
            {
                if (GlyphPropertiesEntry const* old_gp = sGlyphPropertiesStore.LookupEntry(oldglyph))
                {
                    player->RemoveAurasDueToSpell(old_gp->SpellId);
                    player->SetGlyph(m_glyphIndex, 0);
                }
            }

            player->CastSpell(player, gp->SpellId, true);
            player->SetGlyph(m_glyphIndex, glyph);
            player->SendTalentsInfoData(false);
        }
    }
}

void Spell::EffectEnchantHeldItem(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    // this is only item spell effect applied to main-hand weapon of target player (players in area)
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* item_owner = unitTarget->ToPlayer();
    Item* item = item_owner->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

    if (!item)
        return;

    // must be equipped
    if (!item->IsEquipped())
        return;

    if (m_spellInfo->Effects[effIndex].MiscValue)
    {
        uint32 enchant_id = m_spellInfo->Effects[effIndex].MiscValue;
        int32 duration = m_spellInfo->GetDuration();  // Try duration index first ..
        if (!duration)
            duration = damage;//+1;                   // Base points after ..
        if (!duration)
            duration = 10 * IN_MILLISECONDS;          // 10 seconds for enchants which don't have listed duration

        if (m_spellInfo->Id == 14792) // Venomhide Poison
            duration = 5 * MINUTE * IN_MILLISECONDS;

        SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!pEnchant)
            return;

        // Always go to temp enchantment slot
        EnchantmentSlot slot = TEMP_ENCHANTMENT_SLOT;

        // Enchantment will not be applied if a different one already exists
        if (item->GetEnchantmentId(slot) && item->GetEnchantmentId(slot) != enchant_id)
            return;

        // Apply the temporary enchantment
        item->SetEnchantment(slot, enchant_id, duration, 0, m_caster->GetGUID());
        item_owner->ApplyEnchantment(item, slot, true);
    }
}

void Spell::EffectDisEnchant(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!itemTarget || !itemTarget->GetTemplate()->DisenchantID)
        return;

    if (Player* caster = m_caster->ToPlayer())
    {
        caster->UpdateCraftSkill(m_spellInfo->Id);
        caster->SendLoot(itemTarget->GetGUID(), LOOT_DISENCHANTING);
    }

    // item will be removed at disenchanting end
}

void Spell::EffectInebriate(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();
    uint8 currentDrunk = player->GetDrunkValue();
    uint8 drunkMod = damage;
    if (currentDrunk + drunkMod > 100)
    {
        currentDrunk = 100;
        if (rand_chance() < 25.0f)
            player->CastSpell(player, 67468, false);    // Drunken Vomit
    }
    else
        currentDrunk += drunkMod;

    player->SetDrunkValue(currentDrunk, m_CastItem ? m_CastItem->GetEntry() : 0);
}

void Spell::EffectFeedPet(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    Item* foodItem = itemTarget;
    if (!foodItem)
        return;

    Pet* pet = player->GetPet();
    if (!pet)
        return;

    if (!pet->IsAlive())
        return;

    int32 benefit = pet->GetCurrentFoodBenefitLevel(foodItem->GetTemplate()->ItemLevel);
    if (benefit <= 0)
        return;

    ExecuteLogEffectDestroyItem(effIndex, foodItem->GetEntry());

    uint32 count = 1;
    player->DestroyItemCount(foodItem, count, true);
    /// @todo fix crash when a spell has two effects, both pointed at the same item target

    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
    args.AddSpellMod(SPELLVALUE_BASE_POINT0, benefit);
    m_caster->CastSpell(pet, m_spellInfo->Effects[effIndex].TriggerSpell, args);
}

void Spell::EffectDismissPet(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsPet())
        return;

    Pet* pet = unitTarget->ToPet();

    ExecuteLogEffectUnsummonObject(effIndex, pet);
    pet->GetOwner()->RemovePet(pet, PET_SAVE_NOT_IN_SLOT);
}

void Spell::EffectSummonObject(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!unitCaster)
        return;

    uint32 go_id = m_spellInfo->Effects[effIndex].MiscValue;
    uint8 slot = m_spellInfo->Effects[effIndex].Effect - SPELL_EFFECT_SUMMON_OBJECT_SLOT1;

    if (ObjectGuid guid = unitCaster->m_ObjectSlot[slot])
    {
        if (GameObject* obj = unitCaster->GetMap()->GetGameObject(guid))
        {
            // Recast case - null spell id to make auras not be removed on object remove from world
            if (m_spellInfo->Id == obj->GetSpellId())
                obj->SetSpellId(0);
            unitCaster->RemoveGameObject(obj, true);
        }
        unitCaster->m_ObjectSlot[slot].Clear();
    }

    GameObject* go = new GameObject();
    float x, y, z;
    // If dest location if present
    if (m_targets.HasDst())
        destTarget->GetPosition(x, y, z);
    // Summon in random point all other units if location present
    else
        unitCaster->GetClosePoint(x, y, z, DEFAULT_PLAYER_BOUNDING_RADIUS);

    Map* map = unitCaster->GetMap();
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(unitCaster->GetOrientation(), 0.f, 0.f);
    if (!go->Create(map->GenerateLowGuid<HighGuid::GameObject>(), go_id, map, unitCaster->GetPhaseMask(), Position(x, y, z, unitCaster->GetOrientation()), rot, 255, GO_STATE_READY))
    {
        delete go;
        return;
    }

    go->SetFaction(unitCaster->GetFaction());
    go->SetUInt32Value(GAMEOBJECT_LEVEL, unitCaster->GetLevel());
    int32 duration = m_spellInfo->GetDuration();
    go->SetRespawnTime(duration > 0 ? duration / IN_MILLISECONDS : 0);
    go->SetSpellId(m_spellInfo->Id);
    unitCaster->AddGameObject(go);

    ExecuteLogEffectSummonObject(effIndex, go);

    map->AddToMap(go);

    unitCaster->m_ObjectSlot[slot] = go->GetGUID();
}

void Spell::EffectResurrect(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (unitTarget->IsAlive() || !unitTarget->IsInWorld())
        return;

    Player* target = unitTarget->ToPlayer();

    if (target->IsResurrectRequested())       // already have one active request
        return;

    uint32 health = target->CountPctFromMaxHealth(damage);
    uint32 mana   = CalculatePct(target->GetMaxPower(POWER_MANA), damage);

    ExecuteLogEffectResurrect(effIndex, target);

    target->SetResurrectRequestData(m_caster, health, mana, 0);
    SendResurrectRequest(target);
}

void Spell::EffectAddExtraAttacks(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive())
        return;

    if (unitTarget->m_extraAttacks)
        return;

    unitTarget->m_extraAttacks = damage;

    ExecuteLogEffectExtraAttacks(effIndex, unitTarget, damage);
}

void Spell::EffectParry(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetCanParry(true);
}

void Spell::EffectBlock(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetCanBlock(true);
}

void Spell::EffectLeap(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->IsInFlight())
        return;

    if (!m_targets.HasDst())
        return;

    Position pos = destTarget->GetPosition();
    unitTarget->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), unitTarget == m_caster);
}

void Spell::EffectReputation(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();

    int32  repChange = damage;

    uint32 factionId = m_spellInfo->Effects[effIndex].MiscValue;

    FactionEntry const* factionEntry = sFactionStore.LookupEntry(factionId);
    if (!factionEntry)
        return;

    repChange = player->CalculateReputationGain(REPUTATION_SOURCE_SPELL, 0, repChange, factionId);

    player->GetReputationMgr().ModifyReputation(factionEntry, repChange);
}

void Spell::EffectQuestComplete(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    Player* player = unitTarget->ToPlayer();

    uint32 questId = m_spellInfo->Effects[effIndex].MiscValue;
    if (questId)
    {
        Quest const* quest = sObjectMgr->GetQuestTemplate(questId);
        if (!quest)
            return;

        uint16 logSlot = player->FindQuestSlot(questId);
        if (logSlot < MAX_QUEST_LOG_SIZE)
            player->AreaExploredOrEventHappens(questId);
        else if (quest->HasFlag(QUEST_FLAGS_TRACKING))  // Check if the quest is used as a serverside flag.
            player->SetRewardedQuest(questId);          // If so, set status to rewarded without broadcasting it to client.
    }
}

void Spell::EffectForceDeselect(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!unitCaster)
        return;

    float dist = unitCaster->GetVisibilityRange();

    // clear focus
    WorldPacket data(SMSG_BREAK_TARGET, unitCaster->GetPackGUID().size());
    data << unitCaster->GetPackGUID();
    Trinity::MessageDistDelivererToHostile notifierBreak(unitCaster, &data, dist);
    Cell::VisitWorldObjects(unitCaster, notifierBreak, dist);

    // and selection
    data.Initialize(SMSG_CLEAR_TARGET, 8);
    data << uint64(unitCaster->GetGUID());
    Trinity::MessageDistDelivererToHostile notifierClear(unitCaster, &data, dist);
    Cell::VisitWorldObjects(unitCaster, notifierClear, dist);

    // we should also force pets to remove us from current target
    Unit::AttackerSet attackerSet;
    for (Unit::AttackerSet::const_iterator itr = unitCaster->getAttackers().begin(); itr != unitCaster->getAttackers().end(); ++itr)
        if ((*itr)->GetTypeId() == TYPEID_UNIT && !(*itr)->CanHaveThreatList())
            attackerSet.insert(*itr);

    for (Unit::AttackerSet::const_iterator itr = attackerSet.begin(); itr != attackerSet.end(); ++itr)
        (*itr)->AttackStop();
}

void Spell::EffectSelfResurrect(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player || !player->IsInWorld() || player->IsAlive())
        return;

    uint32 health = 0;
    uint32 mana = 0;

    // flat case
    if (damage < 0)
    {
        health = uint32(-damage);
        mana = m_spellInfo->Effects[effIndex].MiscValue;
    }
    // percent case
    else
    {
        health = player->CountPctFromMaxHealth(damage);
        if (player->GetMaxPower(POWER_MANA) > 0)
            mana = CalculatePct(player->GetMaxPower(POWER_MANA), damage);
    }

    player->ResurrectPlayer(0.0f);

    player->SetHealth(health);
    player->SetPower(POWER_MANA, mana);
    player->SetPower(POWER_RAGE, 0);
    player->SetPower(POWER_ENERGY, player->GetMaxPower(POWER_ENERGY));

    player->SpawnCorpseBones();
}

void Spell::EffectSkinning(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (unitTarget->GetTypeId() != TYPEID_UNIT)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    Creature* creature = unitTarget->ToCreature();
    int32 targetLevel = creature->GetLevel();

    uint32 skill = creature->GetCreatureTemplate()->GetRequiredLootSkill();

    creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);
    creature->SetFlag(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_LOOTABLE);
    player->SendLoot(creature->GetGUID(), LOOT_SKINNING);

    int32 const reqValue = targetLevel < 10 ? 0 : (targetLevel < 20 ? (targetLevel - 10) * 10 : targetLevel * 5);
    int32 const skillValue = player->GetPureSkillValue(skill);

    // Double chances for elites
    player->UpdateGatherSkill(skill, skillValue, reqValue, creature->isElite() ? 2 : 1);
}

void Spell::EffectCharge(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget)
        return;

    if (!unitCaster)
        return;

    if (effectHandleMode == SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
    {
        // charge changes fall time
        if (unitCaster->GetTypeId() == TYPEID_PLAYER)
            unitCaster->ToPlayer()->SetFallInformation(0, unitCaster->GetPositionZ());

        float speed = G3D::fuzzyGt(m_spellInfo->Speed, 0.0f) ? m_spellInfo->Speed : SPEED_CHARGE;
        // Spell is not using explicit target - no generated path
        if (!m_preGeneratedPath)
        {
            //unitTarget->GetContactPoint(m_caster, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
            Position pos = unitTarget->GetFirstCollisionPosition(unitTarget->GetCombatReach(), unitTarget->GetRelativeAngle(m_caster));
            unitCaster->GetMotionMaster()->MoveCharge(pos.m_positionX, pos.m_positionY, pos.m_positionZ, speed);
        }
        else
            unitCaster->GetMotionMaster()->MoveCharge(*m_preGeneratedPath, speed);
    }

    if (effectHandleMode == SPELL_EFFECT_HANDLE_HIT_TARGET)
    {
        // not all charge effects used in negative spells
        if (!m_spellInfo->IsPositive() && m_caster->GetTypeId() == TYPEID_PLAYER)
            unitCaster->Attack(unitTarget, true);
    }
}

void Spell::EffectChargeDest(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    if (!unitCaster)
        return;

    if (m_targets.HasDst())
    {
        Position pos = destTarget->GetPosition();

        if (!unitCaster->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
        {
            float angle = unitCaster->GetRelativeAngle(pos.GetPositionX(), pos.GetPositionY());
            float dist = unitCaster->GetDistance(pos);
            pos = unitCaster->GetFirstCollisionPosition(dist, angle);
        }

        unitCaster->GetMotionMaster()->MoveCharge(pos.m_positionX, pos.m_positionY, pos.m_positionZ);
    }
}

void Spell::EffectKnockBack(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (m_caster->GetAffectingPlayer())
        if (Creature* creatureTarget = unitTarget->ToCreature())
            if (creatureTarget->isWorldBoss() || creatureTarget->IsDungeonBoss())
                return;

    // Spells with SPELL_EFFECT_KNOCK_BACK (like Thunderstorm) can't knockback target if target has ROOT/STUN
    if (unitTarget->HasUnitState(UNIT_STATE_ROOT | UNIT_STATE_STUNNED))
        return;

    // Instantly interrupt non melee spells being cast
    if (unitTarget->IsNonMeleeSpellCast(true))
        unitTarget->InterruptNonMeleeSpells(true);

    float ratio = 0.1f;
    float speedxy = float(m_spellInfo->Effects[effIndex].MiscValue) * ratio;
    float speedz = float(damage) * ratio;
    if (speedxy < 0.01f && speedz < 0.01f)
        return;

    float x, y;
    if (m_spellInfo->Effects[effIndex].Effect == SPELL_EFFECT_KNOCK_BACK_DEST)
    {
        if (m_targets.HasDst())
            destTarget->GetPosition(x, y);
        else
            return;
    }
    else //if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_KNOCK_BACK)
        m_caster->GetPosition(x, y);

    unitTarget->KnockbackFrom(x, y, speedxy, speedz);
}

void Spell::EffectLeapBack(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (!unitTarget)
        return;

    float speedxy = m_spellInfo->Effects[effIndex].MiscValue / 10.f;
    float speedz = damage/ 10.f;
    //1891: Disengage
    unitTarget->JumpTo(speedxy, speedz, m_spellInfo->SpellIconID != 1891);

    // changes fall time
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetFallInformation(0, m_caster->GetPositionZ());
}

void Spell::EffectQuestClear(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    Player* player = unitTarget->ToPlayer();

    uint32 quest_id = m_spellInfo->Effects[effIndex].MiscValue;

    Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);

    if (!quest)
        return;

    // Player has never done this quest
    if (player->GetQuestStatus(quest_id) == QUEST_STATUS_NONE)
        return;

    // remove all quest entries for 'entry' from quest log
    for (uint8 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
    {
        uint32 logQuest = player->GetQuestSlotQuestId(slot);
        if (logQuest == quest_id)
        {
            player->SetQuestSlot(slot, 0);

            // we ignore unequippable quest items in this case, it's still be equipped
            player->TakeQuestSourceItem(logQuest, false);

            if (quest->HasFlag(QUEST_FLAGS_FLAGS_PVP))
            {
                player->pvpInfo.IsHostile = player->pvpInfo.IsInHostileArea || player->HasPvPForcingQuest();
                player->UpdatePvPState();
            }
        }
    }

    player->RemoveActiveQuest(quest_id, false);
    player->RemoveRewardedQuest(quest_id);

    sScriptMgr->OnQuestStatusChange(player, quest_id);
}

void Spell::EffectSendTaxi(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->ActivateTaxiPathTo(m_spellInfo->Effects[effIndex].MiscValue, m_spellInfo->Id);
}

void Spell::EffectPullTowards(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    Position pos;
    if (m_spellInfo->Effects[effIndex].Effect == SPELL_EFFECT_PULL_TOWARDS_DEST)
    {
        if (m_targets.HasDst())
            pos.Relocate(*destTarget);
        else
            return;
    }
    else //if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_PULL_TOWARDS)
    {
        pos.Relocate(m_caster);
    }

    float speedXY = float(m_spellInfo->Effects[effIndex].MiscValue) * 0.1f;
    float speedZ = unitTarget->GetDistance(pos) / speedXY * 0.5f * Movement::gravity;

    unitTarget->GetMotionMaster()->MoveJump(pos, speedXY, speedZ);
}

void Spell::EffectDispelMechanic(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    uint32 mechanic = m_spellInfo->Effects[effIndex].MiscValue;
    DispelList dispel_list;
    Unit::AuraMap const& auras = unitTarget->GetOwnedAuras();
    for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
    {
        Aura* aura = itr->second;
        if (!aura->GetApplicationOfTarget(unitTarget->GetGUID()))
            continue;
        if (roll_chance_i(aura->CalcDispelChance(unitTarget, !unitTarget->IsFriendlyTo(m_caster))))
            if ((aura->GetSpellInfo()->GetAllEffectsMechanicMask() & (1 << mechanic)))
                dispel_list.emplace_back(aura->GetId(), aura->GetCasterGUID());
    }

    for (auto itr = dispel_list.begin(); itr != dispel_list.end(); ++itr)
        unitTarget->RemoveAura(itr->first, itr->second, 0, AURA_REMOVE_BY_ENEMY_SPELL);
}

void Spell::EffectResurrectPet(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (damage < 0)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    // Maybe player dismissed dead pet or pet despawned?
    bool hadPet = true;

    if (!player->GetPet())
    {
        // Position passed to SummonPet is irrelevant with current implementation,
        // pet will be relocated without using these coords in Pet::LoadPetFromDB
        player->SummonPet(0, 0.0f, 0.0f, 0.0f, 0.0f, SUMMON_PET, 0);
        hadPet = false;
    }

    // TODO: Better to fail Hunter's "Revive Pet" at cast instead of here when casting ends
    Pet* pet = player->GetPet(); // Attempt to get current pet
    if (!pet || pet->IsAlive())
        return;

    // If player did have a pet before reviving, teleport it
    if (hadPet)
    {
        // Reposition the pet's corpse before reviving so as not to grab aggro
        // We can use a different, more accurate version of GetClosePoint() since we have a pet
        float x, y, z; // Will be used later to reposition the pet if we have one
        player->GetClosePoint(x, y, z, pet->GetCombatReach(), PET_FOLLOW_DIST, pet->GetFollowAngle());
        pet->NearTeleportTo(x, y, z, player->GetOrientation());
        pet->Relocate(x, y, z, player->GetOrientation()); // This is needed so SaveStayPosition() will get the proper coords.
    }

    pet->SetUInt32Value(UNIT_DYNAMIC_FLAGS, UNIT_DYNFLAG_NONE);
    pet->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);
    pet->setDeathState(ALIVE);
    pet->ClearUnitState(UNIT_STATE_ALL_ERASABLE);
    pet->SetHealth(pet->CountPctFromMaxHealth(damage));

    // Reset things for when the AI to takes over
    CharmInfo *ci = pet->GetCharmInfo();
    if (ci)
    {
        // In case the pet was at stay, we don't want it running back
        ci->SaveStayPosition();
        ci->SetIsAtStay(ci->HasCommandState(COMMAND_STAY));

        ci->SetIsFollowing(false);
        ci->SetIsCommandAttack(false);
        ci->SetIsCommandFollow(false);
        ci->SetIsReturning(false);
    }

    pet->SavePetToDB(PET_SAVE_AS_CURRENT);
}

void Spell::EffectDestroyAllTotems(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!unitCaster)
        return;

    int32 mana = 0;
    for (uint8 slot = SUMMON_SLOT_TOTEM_FIRE; slot < MAX_TOTEM_SLOT; ++slot)
    {
        if (!unitCaster->m_SummonSlot[slot])
            continue;

        Creature* totem = unitCaster->GetMap()->GetCreature(unitCaster->m_SummonSlot[slot]);
        if (totem && totem->IsTotem())
        {
            uint32 spell_id = totem->GetUInt32Value(UNIT_CREATED_BY_SPELL);
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id);
            if (spellInfo)
            {
                mana += spellInfo->ManaCost;
                mana += int32(CalculatePct(unitCaster->GetCreateMana(), spellInfo->ManaCostPercentage));
            }
            totem->ToTotem()->UnSummon();
        }
    }
    ApplyPct(mana, damage);
    if (mana)
    {
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, mana);
        unitCaster->CastSpell(unitCaster, 39104, args);
    }
}

void Spell::EffectDurabilityDamage(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    int32 slot = m_spellInfo->Effects[effIndex].MiscValue;

    // -1 means all player equipped items and -2 all items
    if (slot < 0)
    {
        unitTarget->ToPlayer()->DurabilityPointsLossAll(damage, (slot < -1));
        ExecuteLogEffectDurabilityDamage(effIndex, unitTarget, -1, -1);
        return;
    }

    // invalid slot value
    if (slot >= INVENTORY_SLOT_BAG_END)
        return;

    if (Item* item = unitTarget->ToPlayer()->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
    {
        unitTarget->ToPlayer()->DurabilityPointsLoss(item, damage);
        ExecuteLogEffectDurabilityDamage(effIndex, unitTarget, item->GetEntry(), slot);
    }
}

void Spell::EffectDurabilityDamagePCT(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    int32 slot = m_spellInfo->Effects[effIndex].MiscValue;

    // FIXME: some spells effects have value -1/-2
    // Possibly its mean -1 all player equipped items and -2 all items
    if (slot < 0)
    {
        unitTarget->ToPlayer()->DurabilityLossAll(float(damage) / 100.0f, (slot < -1));
        return;
    }

    // invalid slot value
    if (slot >= INVENTORY_SLOT_BAG_END)
        return;

    if (damage <= 0)
        return;

    if (Item* item = unitTarget->ToPlayer()->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
        unitTarget->ToPlayer()->DurabilityLoss(item, float(damage) / 100.0f);
}

void Spell::EffectModifyThreatPercent(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitCaster || !unitTarget)
        return;

    unitTarget->GetThreatManager().ModifyThreatByPercent(unitCaster, damage);
}

void Spell::EffectTransmitted(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!unitCaster)
        return;

    uint32 name_id = m_spellInfo->Effects[effIndex].MiscValue;
    GameObjectTemplate const* goinfo = sObjectMgr->GetGameObjectTemplate(name_id);
    if (!goinfo)
    {
        TC_LOG_ERROR("sql.sql", "Gameobject (Entry: %u) does not exist and is not created by spell (ID: %u) cast.", name_id, m_spellInfo->Id);
        return;
    }

    float fx, fy, fz;

    if (m_targets.HasDst())
        destTarget->GetPosition(fx, fy, fz);
    //FIXME: this can be better check for most objects but still hack
    else if (m_spellInfo->Effects[effIndex].HasRadius() && m_spellInfo->Speed == 0)
    {
        float dis = m_spellInfo->Effects[effIndex].CalcRadius(unitCaster);
        unitCaster->GetClosePoint(fx, fy, fz, DEFAULT_PLAYER_BOUNDING_RADIUS, dis);
    }
    else
    {
        //GO is always friendly to it's creator, get range for friends
        float min_dis = m_spellInfo->GetMinRange(true);
        float max_dis = m_spellInfo->GetMaxRange(true);
        float dis = (float)rand_norm() * (max_dis - min_dis) + min_dis;

        unitCaster->GetClosePoint(fx, fy, fz, DEFAULT_PLAYER_BOUNDING_RADIUS, dis);
    }

    Map* cMap = unitCaster->GetMap();
    // if gameobject is summoning object, it should be spawned right on caster's position
    if (goinfo->type == GAMEOBJECT_TYPE_SUMMONING_RITUAL)
        unitCaster->GetPosition(fx, fy, fz);

    GameObject* pGameObj = new GameObject;

    Position pos = { fx, fy, fz, unitCaster->GetOrientation() };
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(unitCaster->GetOrientation(), 0.f, 0.f);
    if (!pGameObj->Create(cMap->GenerateLowGuid<HighGuid::GameObject>(), name_id, cMap, unitCaster->GetPhaseMask(), pos, rot, 255, GO_STATE_READY))
    {
        delete pGameObj;
        return;
    }

    int32 duration = m_spellInfo->GetDuration();
    switch (goinfo->type)
    {
        case GAMEOBJECT_TYPE_FISHINGNODE:
        {
            unitCaster->SetChannelObjectGuid(pGameObj->GetGUID());
            unitCaster->AddGameObject(pGameObj);              // will removed at spell cancel

            // end time of range when possible catch fish (FISHING_BOBBER_READY_TIME..GetDuration(m_spellInfo))
            // start time == fish-FISHING_BOBBER_READY_TIME (0..GetDuration(m_spellInfo)-FISHING_BOBBER_READY_TIME)
            int32 lastSec = 0;
            switch (urand(0, 2))
            {
                case 0: lastSec =  3; break;
                case 1: lastSec =  7; break;
                case 2: lastSec = 13; break;
            }

            // Duration of the fishing bobber can't be higher than the Fishing channeling duration
            duration = std::min(duration, duration - lastSec*IN_MILLISECONDS + FISHING_BOBBER_READY_TIME*IN_MILLISECONDS);
            break;
        }
        case GAMEOBJECT_TYPE_SUMMONING_RITUAL:
        {
            if (unitCaster->GetTypeId() == TYPEID_PLAYER)
            {
                pGameObj->AddUniqueUse(unitCaster->ToPlayer());
                unitCaster->AddGameObject(pGameObj);      // will be removed at spell cancel
            }
            break;
        }
        case GAMEOBJECT_TYPE_DUEL_ARBITER: // 52991
            unitCaster->AddGameObject(pGameObj);
            break;
        case GAMEOBJECT_TYPE_FISHINGHOLE:
        case GAMEOBJECT_TYPE_CHEST:
        default:
            break;
    }

    pGameObj->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);

    pGameObj->SetOwnerGUID(unitCaster->GetGUID());

    //pGameObj->SetUInt32Value(GAMEOBJECT_LEVEL, unitCaster->GetLevel());
    pGameObj->SetSpellId(m_spellInfo->Id);

    ExecuteLogEffectSummonObject(effIndex, pGameObj);

    TC_LOG_DEBUG("spells", "AddObject at SpellEfects.cpp EffectTransmitted");
    //unitCaster->AddGameObject(pGameObj);
    //m_ObjToDel.push_back(pGameObj);

    cMap->AddToMap(pGameObj);

    if (GameObject* linkedTrap = pGameObj->GetLinkedTrap())
    {
        linkedTrap->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
        //linkedTrap->SetUInt32Value(GAMEOBJECT_LEVEL, unitCaster->GetLevel());
        linkedTrap->SetSpellId(m_spellInfo->Id);
        linkedTrap->SetOwnerGUID(unitCaster->GetGUID());

        ExecuteLogEffectSummonObject(effIndex, linkedTrap);
    }
}

void Spell::EffectProspecting(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    if (!itemTarget || !(itemTarget->GetTemplate()->Flags & ITEM_FLAG_IS_PROSPECTABLE))
        return;

    if (itemTarget->GetCount() < 5)
        return;

    if (sWorld->getBoolConfig(CONFIG_SKILL_PROSPECTING))
    {
        uint32 SkillValue = player->GetPureSkillValue(SKILL_JEWELCRAFTING);
        uint32 reqSkillValue = itemTarget->GetTemplate()->RequiredSkillRank;
        player->UpdateGatherSkill(SKILL_JEWELCRAFTING, SkillValue, reqSkillValue);
    }

    player->SendLoot(itemTarget->GetGUID(), LOOT_PROSPECTING);
}

void Spell::EffectMilling(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    if (!itemTarget || !(itemTarget->GetTemplate()->Flags & ITEM_FLAG_IS_MILLABLE))
        return;

    if (itemTarget->GetCount() < 5)
        return;

    if (sWorld->getBoolConfig(CONFIG_SKILL_MILLING))
    {
        uint32 SkillValue = player->GetPureSkillValue(SKILL_INSCRIPTION);
        uint32 reqSkillValue = itemTarget->GetTemplate()->RequiredSkillRank;
        player->UpdateGatherSkill(SKILL_INSCRIPTION, SkillValue, reqSkillValue);
    }

    player->SendLoot(itemTarget->GetGUID(), LOOT_MILLING);
}

void Spell::EffectSkill(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    TC_LOG_DEBUG("spells", "WORLD: SkillEFFECT");
}

/* There is currently no need for this effect. We handle it in Battleground.cpp
   If we would handle the resurrection here, the spiritguide would instantly disappear as the
   player revives, and so we wouldn't see the spirit heal visual effect on the npc.
   This is why we use a half sec delay between the visual effect and the resurrection itself */
void Spell::EffectSpiritHeal(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    /*
    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    if (!unitTarget->IsInWorld())
        return;

    //m_spellInfo->Effects[i].BasePoints; == 99 (percent?)
    //unitTarget->ToPlayer()->setResurrect(m_caster->GetGUID(), unitTarget->GetPositionX(), unitTarget->GetPositionY(), unitTarget->GetPositionZ(), unitTarget->GetMaxHealth(), unitTarget->GetMaxPower(POWER_MANA));
    unitTarget->ToPlayer()->ResurrectPlayer(1.0f);
    unitTarget->ToPlayer()->SpawnCorpseBones();
    */
}

// remove insignia spell effect
void Spell::EffectSkinPlayerCorpse(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    TC_LOG_DEBUG("spells", "Effect: SkinPlayerCorpse");

    Player* player = m_caster->ToPlayer();
    Player* target = unitTarget->ToPlayer();
    if (!player || !target || target->IsAlive())
        return;

    target->RemovedInsignia(player);
}

void Spell::EffectStealBeneficialBuff(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    TC_LOG_DEBUG("spells", "Effect: StealBeneficialBuff");

    if (!unitTarget || unitTarget == m_caster)                 // can't steal from self
        return;

    DispelChargesList stealList;

    // Create dispel mask by dispel type
    uint32 dispelMask  = SpellInfo::GetDispelMask(DispelType(m_spellInfo->Effects[effIndex].MiscValue));
    Unit::AuraMap const& auras = unitTarget->GetOwnedAuras();
    for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
    {
        Aura* aura = itr->second;
        AuraApplication const* aurApp = aura->GetApplicationOfTarget(unitTarget->GetGUID());
        if (!aurApp)
            continue;

        if ((aura->GetSpellInfo()->GetDispelMask()) & dispelMask)
        {
            // Need check for passive? this
            if (!aurApp->IsPositive() || aura->IsPassive() || aura->GetSpellInfo()->HasAttribute(SPELL_ATTR4_NOT_STEALABLE))
                continue;

            // 2.4.3 Patch Notes: "Dispel effects will no longer attempt to remove effects that have 100% dispel resistance."
            int32 chance = aura->CalcDispelChance(unitTarget, !unitTarget->IsFriendlyTo(m_caster));
            if (!chance)
                continue;

            // The charges / stack amounts don't count towards the total number of auras that can be dispelled.
            // Ie: A dispel on a target with 5 stacks of Winters Chill and a Polymorph has 1 / (1 + 1) -> 50% chance to dispell
            // Polymorph instead of 1 / (5 + 1) -> 16%.
            bool dispelCharges = aura->GetSpellInfo()->HasAttribute(SPELL_ATTR7_DISPEL_CHARGES);
            uint8 charges = dispelCharges ? aura->GetCharges() : aura->GetStackAmount();
            if (charges > 0)
                stealList.emplace_back(aura, chance, charges);
        }
    }

    if (stealList.empty())
        return;

    size_t remaining = stealList.size();

    // Ok if exist some buffs for dispel try dispel it
    uint32 failCount = 0;
    DispelList successList;
    successList.reserve(damage);

    WorldPacket dataFail(SMSG_DISPEL_FAILED, 8 + 8 + 4 + 4 + damage * 4);
    // dispel N = damage buffs (or while exist buffs for dispel)
    for (int32 count = 0; count < damage && remaining > 0;)
    {
        // Random select buff for dispel
        DispelChargesList::iterator itr = stealList.begin();
        std::advance(itr, urand(0, remaining - 1));

        if (itr->RollDispel())
        {
            successList.emplace_back(itr->GetAura()->GetId(), itr->GetAura()->GetCasterGUID());
            if (!itr->DecrementCharge())
            {
                --remaining;
                std::swap(*itr, stealList[remaining]);
            }
        }
        else
        {
            if (!failCount)
            {
                // Failed to dispell
                dataFail << uint64(m_caster->GetGUID());            // Caster GUID
                dataFail << uint64(unitTarget->GetGUID());          // Victim GUID
                dataFail << uint32(m_spellInfo->Id);                // dispel spell id
            }
            ++failCount;
            dataFail << uint32(itr->GetAura()->GetId());            // Spell Id
        }
        ++count;
    }

    if (failCount)
        m_caster->SendMessageToSet(&dataFail, true);

    if (successList.empty())
        return;

    WorldPacket dataSuccess(SMSG_SPELLSTEALLOG, 8 + 8 + 4 + 1 + 4 + damage * 5);
    dataSuccess << unitTarget->GetPackGUID();   // Victim GUID
    dataSuccess << m_caster->GetPackGUID();     // Caster GUID
    dataSuccess << uint32(m_spellInfo->Id);     // dispel spell id
    dataSuccess << uint8(0);                    // not used
    dataSuccess << uint32(successList.size());  // count
    for (auto itr = successList.begin(); itr != successList.end(); ++itr)
    {
        dataSuccess << uint32(itr->first);          // Spell Id
        dataSuccess << uint8(0);                    // 0 - steals !=0 transfers
        unitTarget->RemoveAurasDueToSpellBySteal(itr->first, itr->second, m_caster);
    }
    m_caster->SendMessageToSet(&dataSuccess, true);
}

void Spell::EffectKillCreditPersonal(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->KilledMonsterCredit(m_spellInfo->Effects[effIndex].MiscValue);
}

void Spell::EffectKillCredit(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    int32 creatureEntry = m_spellInfo->Effects[effIndex].MiscValue;
    if (!creatureEntry)
    {
        if (m_spellInfo->Id == 42793) // Burn Body
            creatureEntry = 24008; // Fallen Combatant
    }

    if (creatureEntry)
        unitTarget->ToPlayer()->RewardPlayerAndGroupAtEvent(creatureEntry, unitTarget);
}

void Spell::EffectQuestFail(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->FailQuest(m_spellInfo->Effects[effIndex].MiscValue);
}

void Spell::EffectQuestStart(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    Player* player = unitTarget->ToPlayer();
    if (!player)
        return;

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(m_spellInfo->Effects[effIndex].MiscValue))
    {
        if (!player->CanTakeQuest(quest, false))
            return;

        if (quest->IsAutoAccept() && player->CanAddQuest(quest, false))
            player->AddQuestAndCheckCompletion(quest, player);

        player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, player->GetGUID(), true);
    }
}

void Spell::EffectActivateRune(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = m_caster->ToPlayer();

    if (player->GetClass() != CLASS_DEATH_KNIGHT)
        return;

    // needed later
    m_runesState = m_caster->ToPlayer()->GetRunesState();

    uint32 count = damage;
    if (count == 0)
        count = 1;

    for (uint32 j = 0; j < MAX_RUNES && count > 0; ++j)
    {
        if (player->GetRuneCooldown(j) && player->GetCurrentRune(j) == RuneType(m_spellInfo->Effects[effIndex].MiscValue))
        {
            player->SetRuneCooldown(j, 0);
            --count;
        }
    }

    // Empower rune weapon
    if (m_spellInfo->Id == 47568)
    {
        // Need to do this just once
        if (effIndex != 0)
            return;

        for (uint32 i = 0; i < MAX_RUNES; ++i)
        {
            if (player->GetRuneCooldown(i) && (player->GetBaseRune(i) == RUNE_FROST))
                player->SetRuneCooldown(i, 0);
        }
    }
}

void Spell::EffectCreateTamedPet(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER || unitTarget->GetPetGUID() || unitTarget->GetClass() != CLASS_HUNTER)
        return;

    uint32 creatureEntry = m_spellInfo->Effects[effIndex].MiscValue;
    Pet* pet = unitTarget->CreateTamedPetFrom(creatureEntry, m_spellInfo->Id);
    if (!pet)
        return;

    // add to world
    pet->GetMap()->AddToMap(pet->ToCreature());

    // unitTarget has pet now
    unitTarget->SetMinion(pet, true);

    pet->InitTalentForLevel();

    if (unitTarget->GetTypeId() == TYPEID_PLAYER)
    {
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        unitTarget->ToPlayer()->PetSpellInitialize();
    }
}

void Spell::EffectDiscoverTaxi(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    uint32 nodeid = m_spellInfo->Effects[effIndex].MiscValue;
    if (sTaxiNodesStore.LookupEntry(nodeid))
        unitTarget->ToPlayer()->GetSession()->SendDiscoverNewTaxiNode(nodeid);
}

void Spell::EffectTitanGrip(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetCanTitanGrip(true, m_spellInfo->Effects[effIndex].MiscValue);
}

void Spell::EffectRedirectThreat(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitCaster)
        return;

    if (unitTarget)
        unitCaster->GetThreatManager().RegisterRedirectThreat(m_spellInfo->Id, unitTarget->GetGUID(), uint32(damage));
}

void Spell::EffectGameObjectDamage(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!gameObjTarget)
        return;

    FactionTemplateEntry const* casterFaction = m_caster->GetFactionTemplateEntry();
    FactionTemplateEntry const* targetFaction = sFactionTemplateStore.LookupEntry(gameObjTarget->GetFaction());
    // Do not allow to damage GO's of friendly factions (ie: Wintergrasp Walls/Ulduar Storm Beacons)
    if (!targetFaction || (casterFaction && !casterFaction->IsFriendlyTo(*targetFaction)))
        gameObjTarget->ModifyHealth(-damage, m_caster, GetSpellInfo()->Id);
}

void Spell::EffectGameObjectRepair(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!gameObjTarget)
        return;

    gameObjTarget->ModifyHealth(damage, m_caster);
}

void Spell::EffectGameObjectSetDestructionState(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!gameObjTarget)
        return;

    gameObjTarget->SetDestructibleState(GameObjectDestructibleState(m_spellInfo->Effects[effIndex].MiscValue), m_caster, true);
}

void Spell::SummonGuardian(uint32 i, uint32 entry, SummonPropertiesEntry const* properties, uint32 numGuardians)
{
    if (!unitCaster)
        return;

    if (unitCaster->IsTotem())
        unitCaster = unitCaster->ToTotem()->GetOwner();

    // in another case summon new
    uint8 level = unitCaster->GetLevel();

    // level of pet summoned using engineering item based at engineering skill level
    if (m_CastItem && unitCaster->GetTypeId() == TYPEID_PLAYER)
        if (ItemTemplate const* proto = m_CastItem->GetTemplate())
            if (proto->RequiredSkill == SKILL_ENGINEERING)
                if (uint16 skill202 = unitCaster->ToPlayer()->GetSkillValue(SKILL_ENGINEERING))
                    level = skill202 / 5;

    float radius = 5.0f;
    int32 duration = m_spellInfo->GetDuration();

    if (Player* modOwner = unitCaster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_DURATION, duration);

    //TempSummonType summonType = (duration == 0) ? TEMPSUMMON_DEAD_DESPAWN : TEMPSUMMON_TIMED_DESPAWN;
    Map* map = unitCaster->GetMap();
    for (uint32 count = 0; count < numGuardians; ++count)
    {
        Position pos;
        if (count == 0)
            pos = *destTarget;
        else
            // randomize position for multiple summons
            pos = unitCaster->GetRandomPoint(*destTarget, radius);

        TempSummon* summon = map->SummonCreature(entry, pos, properties, duration, unitCaster, m_spellInfo->Id);
        if (!summon)
            return;

        if (summon->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
            ((Guardian*)summon)->InitStatsForLevel(level);

        if (properties && properties->Category == SUMMON_CATEGORY_ALLY)
            summon->SetFaction(unitCaster->GetFaction());

        if (summon->HasUnitTypeMask(UNIT_MASK_MINION) && m_targets.HasDst())
            ((Minion*)summon)->SetFollowAngle(unitCaster->GetAbsoluteAngle(summon));

        if (summon->GetEntry() == 27893)
        {
            if (uint32 weapon = unitCaster->GetUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID))
            {
                summon->SetDisplayId(11686); // modelid2
                summon->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, weapon);
            }
            else
                summon->SetDisplayId(1126); // modelid1
        }

        ExecuteLogEffectSummonObject(i, summon);
    }
}

void Spell::EffectRenamePet(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_UNIT ||
        !unitTarget->IsPet() || ((Pet*)unitTarget)->getPetType() != HUNTER_PET)
        return;

    unitTarget->SetByteFlag(UNIT_FIELD_BYTES_2, UNIT_BYTES_2_OFFSET_PET_FLAGS, UNIT_CAN_BE_RENAMED);
}

void Spell::EffectPlayMusic(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    uint32 soundid = m_spellInfo->Effects[effIndex].MiscValue;

    if (!sSoundEntriesStore.LookupEntry(soundid))
    {
        TC_LOG_ERROR("spells", "EffectPlayMusic: Sound (Id: %u) does not exist in spell %u.", soundid, m_spellInfo->Id);
        return;
    }

    WorldPacket data(SMSG_PLAY_MUSIC, 4);
    data << uint32(soundid);
    unitTarget->ToPlayer()->SendDirectMessage(&data);
}

void Spell::EffectSpecCount(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->UpdateSpecCount(damage);
}

void Spell::EffectActivateSpec(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->ActivateSpec(damage-1);  // damage is 1 or 2, spec is 0 or 1
}

void Spell::EffectPlaySound(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    Player* player = unitTarget->ToPlayer();
    if (!player)
        return;

    switch (m_spellInfo->Id)
    {
        case 58730: // Restricted Flight Area
        case 58600: // Restricted Flight Area
            player->GetSession()->SendNotification(LANG_ZONE_NOFLYZONE);
            break;
        default:
            break;
    }

    uint32 soundId = m_spellInfo->Effects[effIndex].MiscValue;

    if (!sSoundEntriesStore.LookupEntry(soundId))
    {
        TC_LOG_ERROR("spells", "EffectPlaySound: Sound (Id: %u) does not exist in spell %u.", soundId, m_spellInfo->Id);
        return;
    }

    player->PlayDirectSound(soundId, player);
}

void Spell::EffectRemoveAura(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;
    // there may be need of specifying casterguid of removed auras
    unitTarget->RemoveAurasDueToSpell(m_spellInfo->Effects[effIndex].TriggerSpell);
}

void Spell::EffectCastButtons(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    uint32 button_id = m_spellInfo->Effects[effIndex].MiscValue + 132;
    uint32 n_buttons = m_spellInfo->Effects[effIndex].MiscValueB;

    for (; n_buttons; --n_buttons, ++button_id)
    {
        ActionButton const* ab = player->GetActionButton(button_id);
        if (!ab || ab->GetType() != ACTION_BUTTON_SPELL)
            continue;

        //! Action button data is unverified when it's set so it can be "hacked"
        //! to contain invalid spells, so filter here.
        uint32 spell_id = ab->GetAction();
        if (!spell_id)
            continue;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id);
        if (!spellInfo)
            continue;

        if (!player->HasSpell(spell_id) || player->GetSpellHistory()->HasCooldown(spell_id))
            continue;

        if (!spellInfo->HasAttribute(SPELL_ATTR7_SUMMON_PLAYER_TOTEM))
            continue;

        uint32 cost = spellInfo->CalcPowerCost(player, spellInfo->GetSchoolMask());
        if (player->GetPower(POWER_MANA) < cost)
            continue;

        TriggerCastFlags triggerFlags = TriggerCastFlags(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_CAST_DIRECTLY);
        player->CastSpell(player, spell_id, triggerFlags);
    }
}

void Spell::EffectRechargeManaGem(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = m_caster->ToPlayer();

    if (!player)
        return;

    uint32 item_id = m_spellInfo->Effects[EFFECT_0].ItemType;

    ItemTemplate const* pProto = sObjectMgr->GetItemTemplate(item_id);
    if (!pProto)
    {
        player->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr);
        return;
    }

    if (Item* pItem = player->GetItemByEntry(item_id))
    {
        for (int x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
            pItem->SetSpellCharges(x, pProto->Spells[x].SpellCharges);
        pItem->SetState(ITEM_CHANGED, player);
    }
}

void Spell::EffectBind(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();

    WorldLocation homeLoc;
    uint32 areaId = player->GetAreaId();

    if (m_spellInfo->Effects[effIndex].MiscValue)
        areaId = m_spellInfo->Effects[effIndex].MiscValue;

    if (m_targets.HasDst())
        homeLoc.WorldRelocate(*destTarget);
    else
        homeLoc = player->GetWorldLocation();

    player->SetHomebind(homeLoc, areaId);

    // binding
    WorldPacket data(SMSG_BINDPOINTUPDATE, 4 * 3 + 4 + 4);
    data << TaggedPosition<Position::XYZ>(homeLoc);
    data << uint32(homeLoc.GetMapId());
    data << uint32(areaId);
    player->SendDirectMessage(&data);

    TC_LOG_DEBUG("spells", "EffectBind: New homebind X: %f, Y: %f, Z: %f, MapId: %u, AreaId: %u",
        homeLoc.GetPositionX(), homeLoc.GetPositionY(), homeLoc.GetPositionZ(), homeLoc.GetMapId(), areaId);

    // zone update
    data.Initialize(SMSG_PLAYERBOUND, 8 + 4);
    data << uint64(m_caster->GetGUID());
    data << uint32(areaId);
    player->SendDirectMessage(&data);
}

void Spell::EffectSummonRaFFriend(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER || !unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    m_caster->CastSpell(unitTarget, m_spellInfo->Effects[effIndex].TriggerSpell, true);
}
