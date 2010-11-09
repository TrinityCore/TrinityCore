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

#include "Common.h"
#include "DatabaseEnv.h"
#include "WorldPacket.h"
#include "Opcodes.h"
#include "Log.h"
#include "UpdateMask.h"
#include "World.h"
#include "ObjectMgr.h"
#include "SpellMgr.h"
#include "Player.h"
#include "SkillExtraItems.h"
#include "Unit.h"
#include "Spell.h"
#include "DynamicObject.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Group.h"
#include "UpdateData.h"
#include "MapManager.h"
#include "ObjectAccessor.h"
#include "SharedDefines.h"
#include "Pet.h"
#include "GameObject.h"
#include "GossipDef.h"
#include "Creature.h"
#include "Totem.h"
#include "CreatureAI.h"
#include "BattlegroundMgr.h"
#include "Battleground.h"
#include "BattlegroundEY.h"
#include "BattlegroundWS.h"
#include "OutdoorPvPMgr.h"
#include "Language.h"
#include "SocialMgr.h"
#include "Util.h"
#include "VMapFactory.h"
#include "TemporarySummon.h"
#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "SkillDiscovery.h"
#include "Formulas.h"
#include "Vehicle.h"
#include "ScriptMgr.h"
#include "GameObjectAI.h"

pEffect SpellEffects[TOTAL_SPELL_EFFECTS]=
{
    &Spell::EffectNULL,                                     //  0
    &Spell::EffectInstaKill,                                //  1 SPELL_EFFECT_INSTAKILL
    &Spell::EffectSchoolDMG,                                //  2 SPELL_EFFECT_SCHOOL_DAMAGE
    &Spell::EffectDummy,                                    //  3 SPELL_EFFECT_DUMMY
    &Spell::EffectUnused,                                   //  4 SPELL_EFFECT_PORTAL_TELEPORT          unused
    &Spell::EffectTeleportUnits,                            //  5 SPELL_EFFECT_TELEPORT_UNITS
    &Spell::EffectApplyAura,                                //  6 SPELL_EFFECT_APPLY_AURA
    &Spell::EffectEnvirinmentalDMG,                         //  7 SPELL_EFFECT_ENVIRONMENTAL_DAMAGE
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
    &Spell::EffectApplyAreaAura,                            // 35 SPELL_EFFECT_APPLY_AREA_AURA_PARTY
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
    &Spell::EffectApplyAreaAura,                            // 65 SPELL_EFFECT_APPLY_AREA_AURA_RAID
    &Spell::EffectRechargeManaGem,                          // 66 SPELL_EFFECT_CREATE_MANA_GEM          (possibly recharge it, misc - is item ID)
    &Spell::EffectHealMaxHealth,                            // 67 SPELL_EFFECT_HEAL_MAX_HEALTH
    &Spell::EffectInterruptCast,                            // 68 SPELL_EFFECT_INTERRUPT_CAST
    &Spell::EffectDistract,                                 // 69 SPELL_EFFECT_DISTRACT
    &Spell::EffectPull,                                     // 70 SPELL_EFFECT_PULL                     one spell: Distract Move
    &Spell::EffectPickPocket,                               // 71 SPELL_EFFECT_PICKPOCKET
    &Spell::EffectAddFarsight,                              // 72 SPELL_EFFECT_ADD_FARSIGHT
    &Spell::EffectUnused,                                   // 73 SPELL_EFFECT_UNTRAIN_TALENTS
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
    &Spell::EffectWMODamage,                                // 87 SPELL_EFFECT_WMO_DAMAGE
    &Spell::EffectWMORepair,                                // 88 SPELL_EFFECT_WMO_REPAIR
    &Spell::EffectUnused,                                   // 89 SPELL_EFFECT_WMO_CHANGE // 0 intact // 1 damaged // 2 destroyed // 3 rebuilding
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
    &Spell::EffectSummonDeadPet,                            //109 SPELL_EFFECT_SUMMON_DEAD_PET
    &Spell::EffectDestroyAllTotems,                         //110 SPELL_EFFECT_DESTROY_ALL_TOTEMS
    &Spell::EffectDurabilityDamage,                         //111 SPELL_EFFECT_DURABILITY_DAMAGE
    &Spell::EffectUnused,                                   //112 SPELL_EFFECT_112
    &Spell::EffectResurrectNew,                             //113 SPELL_EFFECT_RESURRECT_NEW
    &Spell::EffectTaunt,                                    //114 SPELL_EFFECT_ATTACK_ME
    &Spell::EffectDurabilityDamagePCT,                      //115 SPELL_EFFECT_DURABILITY_DAMAGE_PCT
    &Spell::EffectSkinPlayerCorpse,                         //116 SPELL_EFFECT_SKIN_PLAYER_CORPSE       one spell: Remove Insignia, bg usage, required special corpse flags...
    &Spell::EffectSpiritHeal,                               //117 SPELL_EFFECT_SPIRIT_HEAL              one spell: Spirit Heal
    &Spell::EffectSkill,                                    //118 SPELL_EFFECT_SKILL                    professions and more
    &Spell::EffectApplyAreaAura,                            //119 SPELL_EFFECT_APPLY_AREA_AURA_PET
    &Spell::EffectUnused,                                   //120 SPELL_EFFECT_TELEPORT_GRAVEYARD       one spell: Graveyard Teleport Test
    &Spell::EffectWeaponDmg,                                //121 SPELL_EFFECT_NORMALIZED_WEAPON_DMG
    &Spell::EffectUnused,                                   //122 SPELL_EFFECT_122                      unused
    &Spell::EffectSendTaxi,                                 //123 SPELL_EFFECT_SEND_TAXI                taxi/flight related (misc value is taxi path id)
    &Spell::EffectPullTowards,                              //124 SPELL_EFFECT_PULL_TOWARDS
    &Spell::EffectModifyThreatPercent,                      //125 SPELL_EFFECT_MODIFY_THREAT_PERCENT
    &Spell::EffectStealBeneficialBuff,                      //126 SPELL_EFFECT_STEAL_BENEFICIAL_BUFF    spell steal effect?
    &Spell::EffectProspecting,                              //127 SPELL_EFFECT_PROSPECTING              Prospecting spell
    &Spell::EffectApplyAreaAura,                            //128 SPELL_EFFECT_APPLY_AREA_AURA_FRIEND
    &Spell::EffectApplyAreaAura,                            //129 SPELL_EFFECT_APPLY_AREA_AURA_ENEMY
    &Spell::EffectRedirectThreat,                           //130 SPELL_EFFECT_REDIRECT_THREAT
    &Spell::EffectPlayerNotification,                       //131 SPELL_EFFECT_PLAYER_NOTIFICATION
    &Spell::EffectPlayMusic,                                //132 SPELL_EFFECT_PLAY_MUSIC               sound id in misc value (SoundEntries.dbc)
    &Spell::EffectUnlearnSpecialization,                    //133 SPELL_EFFECT_UNLEARN_SPECIALIZATION   unlearn profession specialization
    &Spell::EffectKillCredit,                               //134 SPELL_EFFECT_KILL_CREDIT              misc value is creature entry
    &Spell::EffectNULL,                                     //135 SPELL_EFFECT_CALL_PET
    &Spell::EffectHealPct,                                  //136 SPELL_EFFECT_HEAL_PCT
    &Spell::EffectEnergizePct,                              //137 SPELL_EFFECT_ENERGIZE_PCT
    &Spell::EffectLeapBack,                                 //138 SPELL_EFFECT_LEAP_BACK                Leap back
    &Spell::EffectQuestClear,                               //139 SPELL_EFFECT_CLEAR_QUEST              Reset quest status (miscValue - quest ID)
    &Spell::EffectForceCast,                                //140 SPELL_EFFECT_FORCE_CAST
    &Spell::EffectForceCastWithValue,                       //141 SPELL_EFFECT_FORCE_CAST_WITH_VALUE
    &Spell::EffectTriggerSpellWithValue,                    //142 SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE
    &Spell::EffectApplyAreaAura,                            //143 SPELL_EFFECT_APPLY_AREA_AURA_OWNER
    &Spell::EffectKnockBack,                                //144 SPELL_EFFECT_KNOCK_BACK_DEST
    &Spell::EffectPullTowards,                              //145 SPELL_EFFECT_PULL_TOWARDS_DEST                      Black Hole Effect
    &Spell::EffectActivateRune,                             //146 SPELL_EFFECT_ACTIVATE_RUNE
    &Spell::EffectQuestFail,                                //147 SPELL_EFFECT_QUEST_FAIL               quest fail
    &Spell::EffectUnused,                                   //148 SPELL_EFFECT_148   1 spell - 43509
    &Spell::EffectChargeDest,                               //149 SPELL_EFFECT_CHARGE_DEST
    &Spell::EffectQuestStart,                               //150 SPELL_EFFECT_QUEST_START
    &Spell::EffectTriggerRitualOfSummoning,                 //151 SPELL_EFFECT_TRIGGER_SPELL_2
    &Spell::EffectNULL,                                     //152 SPELL_EFFECT_152                      summon Refer-a-Friend
    &Spell::EffectCreateTamedPet,                           //153 SPELL_EFFECT_CREATE_TAMED_PET         misc value is creature entry
    &Spell::EffectDiscoverTaxi,                             //154 SPELL_EFFECT_DISCOVER_TAXI
    &Spell::EffectTitanGrip,                                //155 SPELL_EFFECT_TITAN_GRIP Allows you to equip two-handed axes, maces and swords in one hand, but you attack $49152s1% slower than normal.
    &Spell::EffectEnchantItemPrismatic,                     //156 SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC
    &Spell::EffectCreateItem2,                              //157 SPELL_EFFECT_CREATE_ITEM_2            create item or create item template and replace by some randon spell loot item
    &Spell::EffectMilling,                                  //158 SPELL_EFFECT_MILLING                  milling
    &Spell::EffectRenamePet,                                //159 SPELL_EFFECT_ALLOW_RENAME_PET         allow rename pet once again
    &Spell::EffectNULL,                                     //160 SPELL_EFFECT_160                      1 spell - 45534
    &Spell::EffectSpecCount,                                //161 SPELL_EFFECT_TALENT_SPEC_COUNT        second talent spec (learn/revert)
    &Spell::EffectActivateSpec,                             //162 SPELL_EFFECT_TALENT_SPEC_SELECT       activate primary/secondary spec
    &Spell::EffectNULL,                                     //163 unused
    &Spell::EffectRemoveAura,                               //164 SPELL_EFFECT_REMOVE_AURA
};

void Spell::EffectNULL(SpellEffIndex /*effIndex*/)
{
    sLog.outDebug("WORLD: Spell Effect DUMMY");
}

void Spell::EffectUnused(SpellEffIndex /*effIndex*/)
{
    // NOT USED BY ANY SPELL OR USELESS OR IMPLEMENTED IN DIFFERENT WAY IN TRINITY
}

void Spell::EffectResurrectNew(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->isAlive())
        return;

    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (!unitTarget->IsInWorld())
        return;

    Player* pTarget = unitTarget->ToPlayer();

    if (pTarget->isRessurectRequested())       // already have one active request
        return;

    uint32 health = damage;
    uint32 mana = m_spellInfo->EffectMiscValue[effIndex];
    ExecuteLogEffectResurrect(effIndex, pTarget);
    pTarget->setResurrectRequestData(m_caster->GetGUID(), m_caster->GetMapId(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), health, mana);
    SendResurrectRequest(pTarget);
}

void Spell::EffectInstaKill(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || !unitTarget->isAlive())
        return;

    // Demonic Sacrifice
    if (m_spellInfo->Id == 18788 && unitTarget->GetTypeId() == TYPEID_UNIT)
    {
        uint32 entry = unitTarget->GetEntry();
        uint32 spellID;
        switch (entry)
        {
            case   416: spellID = 18789; break;               //imp
            case   417: spellID = 18792; break;               //fellhunter
            case  1860: spellID = 18790; break;               //void
            case  1863: spellID = 18791; break;               //succubus
            case 17252: spellID = 35701; break;               //fellguard
            default:
                sLog.outError("EffectInstaKill: Unhandled creature entry (%u) case.", entry);
                return;
        }

        m_caster->CastSpell(m_caster, spellID, true);
    }

    if (m_caster == unitTarget)                              // prevent interrupt message
        finish();

    WorldPacket data(SMSG_SPELLINSTAKILLLOG, 8+8+4);
    data << uint64(m_caster->GetGUID());
    data << uint64(unitTarget->GetGUID());
    data << uint32(m_spellInfo->Id);
    m_caster->SendMessageToSet(&data, true);

    m_caster->DealDamage(unitTarget, unitTarget->GetHealth(), NULL, NODAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
}

void Spell::EffectEnvirinmentalDMG(SpellEffIndex effIndex)
{
    uint32 absorb = 0;
    uint32 resist = 0;

    // Note: this hack with damage replace required until GO casting not implemented
    // environment damage spells already have around enemies targeting but this not help in case not existed GO casting support
    // currently each enemy selected explicitly and self cast damage, we prevent apply self casted spell bonuses/etc
    damage = SpellMgr::CalculateSpellEffectAmount(m_spellInfo, effIndex, m_caster);

    m_caster->CalcAbsorbResist(m_caster, GetSpellSchoolMask(m_spellInfo), SPELL_DIRECT_DAMAGE, damage, &absorb, &resist, m_spellInfo);

    m_caster->SendSpellNonMeleeDamageLog(m_caster, m_spellInfo->Id, damage, GetSpellSchoolMask(m_spellInfo), absorb, resist, false, 0, false);
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->EnvironmentalDamage(DAMAGE_FIRE, damage);
}

void Spell::EffectSchoolDMG(SpellEffIndex /*effIndex*/)
{
}

void Spell::SpellDamageSchoolDmg(SpellEffIndex effIndex)
{
    bool apply_direct_bonus = true;

    if (unitTarget && unitTarget->isAlive())
    {
        switch (m_spellInfo->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
            {
                // Meteor like spells (divided damage to targets)
                if (m_customAttr & SPELL_ATTR_CU_SHARE_DAMAGE)
                {
                    uint32 count = 0;
                    for (std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                        if (ihit->effectMask & (1<<effIndex))
                            ++count;

                    damage /= count;                    // divide to all targets
                }

                switch(m_spellInfo->Id)                     // better way to check unknown
                {
                    // Positive/Negative Charge
                    case 28062:
                    case 28085:
                    case 39090:
                    case 39093:
                        if (!m_triggeredByAuraSpell)
                            break;
                        if (unitTarget == m_caster)
                        {
                            uint8 count = 0;
                            for (std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                                if (ihit->targetGUID != m_caster->GetGUID())
                                    if (Player *target = ObjectAccessor::GetPlayer(*m_caster, ihit->targetGUID))
                                        if (target->HasAura(m_triggeredByAuraSpell->Id))
                                            ++count;
                            if (count)
                            {
                                uint32 spellId = 0;
                                switch (m_spellInfo->Id)
                                {
                                    case 28062: spellId = 29659; break;
                                    case 28085: spellId = 29660; break;
                                    case 39090: spellId = 39089; break;
                                    case 39093: spellId = 39092; break;
                                }
                                m_caster->SetAuraStack(spellId, m_caster, count);
                            }
                        }

                        if (unitTarget->HasAura(m_triggeredByAuraSpell->Id))
                            damage = 0;
                        break;
                    // Consumption
                    case 28865:
                        damage = (((InstanceMap*)m_caster->GetMap())->GetDifficulty() == REGULAR_DIFFICULTY ? 2750 : 4250);
                        break;
                    // percent from health with min
                    case 25599:                             // Thundercrash
                    {
                        damage = unitTarget->GetHealth() / 2;
                        if (damage < 200)
                            damage = 200;
                        break;
                    }
                    // arcane charge. must only affect demons (also undead?)
                    case 45072:
                    {
                        if (unitTarget->GetCreatureType() != CREATURE_TYPE_DEMON
                            && unitTarget->GetCreatureType() != CREATURE_TYPE_UNDEAD)
                            return;
                        break;
                    }
                    case 33671: // gruul's shatter
                    case 50811: // krystallus shatter ( Normal )
                    case 61547: // krystallus shatter ( Heroic )
                    {
                        // don't damage self and only players
                        if (unitTarget->GetGUID() == m_caster->GetGUID() || unitTarget->GetTypeId() != TYPEID_PLAYER)
                            return;

                        float radius = GetSpellRadiusForHostile(sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[0]));
                        if (!radius) return;
                        float distance = m_caster->GetDistance2d(unitTarget);
                        damage = (distance > radius) ? 0 : int32(SpellMgr::CalculateSpellEffectAmount(m_spellInfo, 0) * ((radius - distance)/radius));
                        break;
                    }
                    // TODO: add spell specific target requirement hook for spells
                    // Shadowbolts only affects targets with Shadow Mark (Gothik)
                    case 27831:
                    case 55638:
                        if (!unitTarget->HasAura(27825))
                            return;
                        break;
                    // Cataclysmic Bolt
                    case 38441:
                    {
                        damage = unitTarget->CountPctFromMaxHealth(50);
                        break;
                    }
                    // Tympanic Tantrum
                    case 62775:
                    {
                        damage = unitTarget->CountPctFromMaxHealth(10);
                        break;
                    }
                    // Gargoyle Strike
                    case 51963:
                    {
                        // about +4 base spell dmg per level
                        damage = (m_caster->getLevel() - 60) * 4 + 60;
                        break;
                    }

                    // Loken Pulsing Shockwave
                    case 59837:
                    case 52942:
                    {
                        // don't damage self and only players
                        if(unitTarget->GetGUID() == m_caster->GetGUID() || unitTarget->GetTypeId() != TYPEID_PLAYER)
                            return;

                        float radius = GetSpellRadiusForHostile(sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[0]));
                        if (!radius)
                            return;
                        float distance = m_caster->GetDistance2d(unitTarget);
                        damage = (distance > radius) ? 0 : int32(SpellMgr::CalculateSpellEffectAmount(m_spellInfo, 0) * distance);
                        break;
                    }
                }
                break;
            }
            case SPELLFAMILY_WARRIOR:
            {
                // Bloodthirst
                if (m_spellInfo->SpellFamilyFlags[1] & 0x400)
                    damage = uint32(damage * (m_caster->GetTotalAttackPowerValue(BASE_ATTACK)) / 100);
                // Shield Slam
                else if (m_spellInfo->SpellFamilyFlags[1] & 0x200 && m_spellInfo->Category == 1209)
                    damage += m_caster->ApplyEffectModifiers(m_spellInfo,effIndex,int32(m_caster->GetShieldBlockValue()));
                // Victory Rush
                else if (m_spellInfo->SpellFamilyFlags[1] & 0x100)
                {
                    damage = uint32(damage * m_caster->GetTotalAttackPowerValue(BASE_ATTACK) / 100);
                    m_caster->ModifyAuraState(AURA_STATE_WARRIOR_VICTORY_RUSH, false);
                }
                // Shockwave
                else if (m_spellInfo->Id == 46968)
                {
                    int32 pct = m_caster->CalculateSpellDamage(unitTarget, m_spellInfo, 2);
                    if (pct > 0)
                        damage+= int32(m_caster->GetTotalAttackPowerValue(BASE_ATTACK) * pct / 100);
                    break;
                }
                break;
            }
            case SPELLFAMILY_WARLOCK:
            {
                // Incinerate Rank 1 & 2
                if ((m_spellInfo->SpellFamilyFlags[1] & 0x000040) && m_spellInfo->SpellIconID == 2128)
                {
                    // Incinerate does more dmg (dmg*0.25) if the target have Immolate debuff.
                    // Check aura state for speed but aura state set not only for Immolate spell
                    if (unitTarget->HasAuraState(AURA_STATE_CONFLAGRATE))
                    {
                        if (unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_WARLOCK, 0x4, 0, 0))
                            damage += damage/4;
                    }
                }
                // Conflagrate - consumes Immolate or Shadowflame
                else if (m_spellInfo->TargetAuraState == AURA_STATE_CONFLAGRATE)
                {
                    AuraEffect const* aura = NULL;                // found req. aura for damage calculation

                    Unit::AuraEffectList const &mPeriodic = unitTarget->GetAuraEffectsByType(SPELL_AURA_PERIODIC_DAMAGE);
                    for (Unit::AuraEffectList::const_iterator i = mPeriodic.begin(); i != mPeriodic.end(); ++i)
                    {
                        // for caster applied auras only
                        if ((*i)->GetSpellProto()->SpellFamilyName != SPELLFAMILY_WARLOCK ||
                            (*i)->GetCasterGUID() != m_caster->GetGUID())
                            continue;

                        // Immolate
                        if ((*i)->GetSpellProto()->SpellFamilyFlags[0] & 0x4)
                        {
                            aura = *i;                      // it selected always if exist
                            break;
                        }

                        // Shadowflame
                        if ((*i)->GetSpellProto()->SpellFamilyFlags[2] & 0x00000002)
                            aura = *i;                      // remember but wait possible Immolate as primary priority
                    }

                    // found Immolate or Shadowflame
                    if (aura)
                    {
                        uint32 pdamage = aura->GetAmount() > 0 ? aura->GetAmount() : 0;
                        pdamage = m_caster->SpellDamageBonus(unitTarget, aura->GetSpellProto(), pdamage, DOT, aura->GetBase()->GetStackAmount());
                        uint32 pct_dir = m_caster->CalculateSpellDamage(unitTarget, m_spellInfo, (effIndex + 1));
                        uint8 baseTotalTicks = uint8(m_caster->CalcSpellDuration(aura->GetSpellProto()) / aura->GetSpellProto()->EffectAmplitude[0]);
                        damage += pdamage * baseTotalTicks * pct_dir / 100;

                        uint32 pct_dot = m_caster->CalculateSpellDamage(unitTarget, m_spellInfo, (effIndex + 2)) / 3;
                        m_spellValue->EffectBasePoints[1] = SpellMgr::CalculateSpellEffectBaseAmount(pdamage * baseTotalTicks * pct_dot / 100, m_spellInfo, 1);

                        apply_direct_bonus = false;
                        // Glyph of Conflagrate
                        if (!m_caster->HasAura(56235))
                            unitTarget->RemoveAurasDueToSpell(aura->GetId(), m_caster->GetGUID());

                        break;
                    }
                }
                // Shadow Bite
                else if (m_spellInfo->SpellFamilyFlags[1] & 0x400000)
                {
                    if (m_caster->GetTypeId() == TYPEID_UNIT && m_caster->ToCreature()->isPet())
                    {
                        // Get DoTs on target by owner (5% increase by dot)
                        damage += 5 * unitTarget->GetDoTsByCaster(m_caster->GetOwnerGUID()) / 100;
                    }
                }
                break;
            }
            case SPELLFAMILY_PRIEST:
            {
                // Shadow Word: Death - deals damage equal to damage done to caster
                if ((m_spellInfo->SpellFamilyFlags[1] & 0x2))
                {
                    int32 back_damage = m_caster->SpellDamageBonus(unitTarget, m_spellInfo, (uint32)damage, SPELL_DIRECT_DAMAGE);
                    // Pain and Suffering reduces damage
                    if (AuraEffect * aurEff = m_caster->GetDummyAuraEffect(SPELLFAMILY_PRIEST, 2874, 0))
                        back_damage -= aurEff->GetAmount() * back_damage / 100;

                    if (back_damage < int32(unitTarget->GetHealth()))
                        m_caster->CastCustomSpell(m_caster, 32409, &back_damage, 0, 0, true);
                }
                // Mind Blast - applies Mind Trauma if:
                else if (m_spellInfo->SpellFamilyFlags[2] & 0x00002000)
                {
                    // We are in Shadow Form
                    if (m_caster->m_form == FORM_SHADOW)
                        // We have Improved Mind Blast
                        if (AuraEffect * aurEff = m_caster->GetDummyAuraEffect(SPELLFAMILY_PRIEST,95,0))
                            // Chance has been successfully rolled
                            if (roll_chance_i(aurEff->GetAmount()))
                                m_caster->CastSpell(unitTarget, 48301, true);
                }
                // Smite
                else if (m_spellInfo->SpellFamilyFlags[0] & 0x80)
                {
                    // Glyph of Smite
                    if (AuraEffect * aurEff = m_caster->GetAuraEffect(55692, 0))
                        if (unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_PRIEST, 0x100000, 0, 0, m_caster->GetGUID()))
                            damage += damage * aurEff->GetAmount() / 100;
                }
                // Improved Mind Blast (Mind Blast in shadow form bonus)
                else if (m_caster->m_form == FORM_SHADOW && (m_spellInfo->SpellFamilyFlags[0] & 0x00002000))
                {
                    Unit::AuraEffectList const& ImprMindBlast = m_caster->GetAuraEffectsByType(SPELL_AURA_ADD_FLAT_MODIFIER);
                    for (Unit::AuraEffectList::const_iterator i = ImprMindBlast.begin(); i != ImprMindBlast.end(); ++i)
                    {
                        if ((*i)->GetSpellProto()->SpellFamilyName == SPELLFAMILY_PRIEST &&
                            ((*i)->GetSpellProto()->SpellIconID == 95))
                        {
                            int chance = SpellMgr::CalculateSpellEffectAmount((*i)->GetSpellProto(), 1, m_caster);
                            if (roll_chance_i(chance))
                                // Mind Trauma
                                m_caster->CastSpell(unitTarget, 48301, true, 0);
                            break;
                        }
                    }
                }
                break;
            }
            case SPELLFAMILY_DRUID:
            {
                // Ferocious Bite
                if (m_caster->GetTypeId() == TYPEID_PLAYER && (m_spellInfo->SpellFamilyFlags[0] & 0x000800000) && m_spellInfo->SpellVisual[0] == 6587)
                {
                    // converts each extra point of energy into ($f1+$AP/410) additional damage
                    float ap = m_caster->GetTotalAttackPowerValue(BASE_ATTACK);
                    float multiple = ap / 410 + m_spellInfo->EffectDamageMultiplier[effIndex];
                    int32 energy = -(m_caster->ModifyPower(POWER_ENERGY, -30));
                    damage += int32(energy * multiple);
                    damage += int32(m_caster->ToPlayer()->GetComboPoints() * ap * 7 / 100);
                }
                // Wrath
                else if (m_spellInfo->SpellFamilyFlags[0] & 0x00000001)
                {
                    // Improved Insect Swarm
                    if (AuraEffect const * aurEff = m_caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, 1771, 0))
                        if (unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DRUID, 0x00200000, 0, 0))
                            damage = int32(damage*(100.0f+aurEff->GetAmount())/100.0f);
                }
                break;
            }
            case SPELLFAMILY_ROGUE:
            {
                // Envenom
                if (m_caster->GetTypeId() == TYPEID_PLAYER && (m_spellInfo->SpellFamilyFlags[1] & 0x8))
                {
                    // consume from stack dozes not more that have combo-points
                    if (uint32 combo = m_caster->ToPlayer()->GetComboPoints())
                    {
                        // Lookup for Deadly poison (only attacker applied)
                        if (AuraEffect const * aurEff = unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_ROGUE, 0x10000, 0, 0, m_caster->GetGUID()))
                        {
                            // count consumed deadly poison doses at target
                            bool needConsume = true;
                            uint32 spellId = aurEff->GetId();
                            uint32 doses = aurEff->GetBase()->GetStackAmount();
                            if (doses > combo)
                                doses = combo;
                            // Master Poisoner
                            Unit::AuraEffectList const& auraList = m_caster->ToPlayer()->GetAuraEffectsByType(SPELL_AURA_MOD_AURA_DURATION_BY_DISPEL_NOT_STACK);
                            for (Unit::AuraEffectList::const_iterator iter = auraList.begin(); iter != auraList.end(); ++iter)
                            {
                                if ((*iter)->GetSpellProto()->SpellFamilyName == SPELLFAMILY_ROGUE && (*iter)->GetSpellProto()->SpellIconID == 1960)
                                {
                                    uint32 chance = SpellMgr::CalculateSpellEffectAmount((*iter)->GetSpellProto(), 2, m_caster);

                                    if (chance && roll_chance_i(chance))
                                        needConsume = false;

                                    break;
                                }
                            }

                            if (needConsume)
                                for (uint32 i = 0; i < doses; ++i)
                                    unitTarget->RemoveAuraFromStack(spellId);
                            damage *= doses;
                            damage += int32(((Player*)m_caster)->GetTotalAttackPowerValue(BASE_ATTACK) * 0.09f * doses);
                        }
                        // Eviscerate and Envenom Bonus Damage (item set effect)
                        if (m_caster->HasAura(37169))
                            damage += ((Player*)m_caster)->GetComboPoints()*40;
                    }
                }
                // Eviscerate
                else if ((m_spellInfo->SpellFamilyFlags[0] & 0x00020000) && m_caster->GetTypeId() == TYPEID_PLAYER)
                {
                    if (uint32 combo = ((Player*)m_caster)->GetComboPoints())
                    {
                        float ap = m_caster->GetTotalAttackPowerValue(BASE_ATTACK);
                        damage += irand(int32(ap * combo * 0.03f), int32(ap * combo * 0.07f));

                        // Eviscerate and Envenom Bonus Damage (item set effect)
                        if (m_caster->HasAura(37169))
                            damage += combo*40;
                    }
                }
                break;
            }
            case SPELLFAMILY_HUNTER:
            {
                //Gore
                if (m_spellInfo->SpellIconID == 1578)
                {
                    if (m_caster->HasAura(57627))           // Charge 6 sec post-affect
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
                        if ((*iter)->GetSpellProto()->SpellIconID == 15 && (*iter)->GetSpellProto()->Dispel == 0)
                        {
                            found = true;
                            break;
                        }
                    }

                    // TODO: should this be put on taken but not done?
                    if (found)
                        damage += SpellMgr::CalculateSpellEffectAmount(m_spellInfo, 1);

                    if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    {
                        // Add Ammo and Weapon damage plus RAP * 0.1
                        Item *item = m_caster->ToPlayer()->GetWeaponForAttack(RANGED_ATTACK);
                        if (item)
                        {
                            float dmg_min = item->GetProto()->Damage->DamageMin;
                            float dmg_max = item->GetProto()->Damage->DamageMax;
                            if (dmg_max == 0.0f && dmg_min > dmg_max)
                                damage += int32(dmg_min);
                            else
                                damage += irand(int32(dmg_min), int32(dmg_max));
                            damage += int32(m_caster->ToPlayer()->GetAmmoDPS()*item->GetProto()->Delay*0.001f);
                        }
                    }
                }
                break;
            }
            case SPELLFAMILY_PALADIN:
            {
                // Hammer of the Righteous
                if (m_spellInfo->SpellFamilyFlags[1]&0x00040000)
                {
                    // Add main hand dps * effect[2] amount
                    float average = (m_caster->GetFloatValue(UNIT_FIELD_MINDAMAGE) + m_caster->GetFloatValue(UNIT_FIELD_MAXDAMAGE)) / 2;
                    int32 count = m_caster->CalculateSpellDamage(unitTarget, m_spellInfo, EFFECT_2);
                    damage += count * int32(average * IN_MILLISECONDS) / m_caster->GetAttackTime(BASE_ATTACK);
                    break;
                }
                // Shield of Righteousness
                if (m_spellInfo->SpellFamilyFlags[EFFECT_1] & 0x100000)
                {
                    damage += m_caster->GetShieldBlockValue() * SpellMgr::CalculateSpellEffectAmount(m_spellInfo, EFFECT_1) / 100;
                    break;
                }
                break;
            }
            case SPELLFAMILY_DEATHKNIGHT:
            {
                // Blood Boil - bonus for diseased targets
                if (m_spellInfo->SpellFamilyFlags[0] & 0x00040000 && unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, 0, 0, 0x00000002, m_caster->GetGUID()))
                {
                    damage += m_damage / 2;
                    damage += int32(m_caster->GetTotalAttackPowerValue(RANGED_ATTACK)* 0.035f);
                }
                break;
            }
        }

        if (m_originalCaster && damage > 0 && apply_direct_bonus)
            damage = m_originalCaster->SpellDamageBonus(unitTarget, m_spellInfo, (uint32)damage, SPELL_DIRECT_DAMAGE);

        m_damage += damage;
    }
}

void Spell::EffectDummy(SpellEffIndex effIndex)
{
    if (!unitTarget && !gameObjTarget && !itemTarget)
        return;

    uint32 spell_id = 0;
    int32 bp = 0;
    bool triggered = true;
    SpellCastTargets targets;

    // selection by spell family
    switch (m_spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            switch (m_spellInfo->Id)
            {
                case 8593:                                  // Symbol of life (restore creature to life)
                case 31225:                                 // Shimmering Vessel (restore creature to life)
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_UNIT)
                        return;
                    unitTarget->ToCreature()->setDeathState(JUST_ALIVED);
                    return;
                }
                case 12162:                                 // Deep wounds
                case 12850:                                 // (now good common check for this spells)
                case 12868:
                {
                    if (!unitTarget)
                        return;

                    float damage;
                    // DW should benefit of attack power, damage percent mods etc.
                    // TODO: check if using offhand damage is correct and if it should be divided by 2
                    if (m_caster->haveOffhandWeapon() && m_caster->getAttackTimer(BASE_ATTACK) > m_caster->getAttackTimer(OFF_ATTACK))
                        damage = (m_caster->GetFloatValue(UNIT_FIELD_MINOFFHANDDAMAGE) + m_caster->GetFloatValue(UNIT_FIELD_MAXOFFHANDDAMAGE))/2;
                    else
                        damage = (m_caster->GetFloatValue(UNIT_FIELD_MINDAMAGE) + m_caster->GetFloatValue(UNIT_FIELD_MAXDAMAGE))/2;

                    switch (m_spellInfo->Id)
                    {
                        case 12162: damage *= 0.16f; break; // Rank 1
                        case 12850: damage *= 0.32f; break; // Rank 2
                        case 12868: damage *= 0.48f; break; // Rank 3
                        default:
                            sLog.outError("Spell::EffectDummy: Spell %u not handled in DW",m_spellInfo->Id);
                            return;
                    };

                    // get remaining damage of old Deep Wound aura
                    AuraEffect* deepWound = unitTarget->GetAuraEffect(12721, 0);
                    if (deepWound)
                    {
                        int32 remainingTicks = deepWound->GetBase()->GetDuration() / deepWound->GetAmplitude();
                        damage += remainingTicks * deepWound->GetAmount();
                    }

                    // 1 tick/sec * 6 sec = 6 ticks
                    int32 deepWoundsDotBasePoints0 = int32(damage / 6);
                    m_caster->CastCustomSpell(unitTarget, 12721, &deepWoundsDotBasePoints0, NULL, NULL, true, NULL);
                    return;
                }
                case 13567:                                 // Dummy Trigger
                {
                    // can be used for different aura triggering, so select by aura
                    if (!m_triggeredByAuraSpell || !unitTarget)
                        return;

                    switch (m_triggeredByAuraSpell->Id)
                    {
                        case 26467:                         // Persistent Shield
                            m_caster->CastCustomSpell(unitTarget, 26470, &damage, NULL, NULL, true);
                            break;
                        default:
                            sLog.outError("EffectDummy: Non-handled case for spell 13567 for triggered aura %u",m_triggeredByAuraSpell->Id);
                            break;
                    }
                    return;
                }
                case 17251:                                 // Spirit Healer Res
                {
                    if (!unitTarget || !m_originalCaster)
                        return;

                    if (m_originalCaster->GetTypeId() == TYPEID_PLAYER)
                    {
                        WorldPacket data(SMSG_SPIRIT_HEALER_CONFIRM, 8);
                        data << uint64(unitTarget->GetGUID());
                        m_originalCaster->ToPlayer()->GetSession()->SendPacket(&data);
                    }
                    return;
                }
                case 20577:                                 // Cannibalize
                    if (unitTarget)
                        m_caster->CastSpell(m_caster, 20578, false, NULL);
                    return;
                case 23019:                                 // Crystal Prison Dummy DND
                {
                    if (!unitTarget || !unitTarget->isAlive() || unitTarget->GetTypeId() != TYPEID_UNIT || unitTarget->ToCreature()->isPet())
                        return;

                    Creature* creatureTarget = unitTarget->ToCreature();

                    m_caster->SummonGameObject(179644, creatureTarget->GetPositionX(), creatureTarget->GetPositionY(), creatureTarget->GetPositionZ(), creatureTarget->GetOrientation(), 0, 0, 0, 0, uint32(creatureTarget->GetRespawnTime()-time(NULL)));
                    sLog.outDebug("SummonGameObject at SpellEfects.cpp EffectDummy for Spell 23019");

                    creatureTarget->ForcedDespawn();

                    return;
                }
                case 23448:                                 // Transporter Arrival - Ultrasafe Transporter: Gadgetzan - backfires
                {
                    int32 r = irand(0, 119);
                    if (r < 20)                           // Transporter Malfunction - 1/6 polymorph
                        m_caster->CastSpell(m_caster, 23444, true);
                    else if (r < 100)                     // Evil Twin               - 4/6 evil twin
                        m_caster->CastSpell(m_caster, 23445, true);
                    else                                    // Transporter Malfunction - 1/6 miss the target
                        m_caster->CastSpell(m_caster, 36902, true);
                    return;
                }
                case 23453:                                 // Gnomish Transporter - Ultrasafe Transporter: Gadgetzan
                    if (roll_chance_i(50))                // Gadgetzan Transporter         - success
                        m_caster->CastSpell(m_caster, 23441, true);
                    else                                    // Gadgetzan Transporter Failure - failure
                        m_caster->CastSpell(m_caster, 23446, true);
                    return;
                case 25860:                                 // Reindeer Transformation
                {
                    if (!m_caster->HasAuraType(SPELL_AURA_MOUNTED))
                        return;

                    float flyspeed = m_caster->GetSpeedRate(MOVE_FLIGHT);
                    float speed = m_caster->GetSpeedRate(MOVE_RUN);

                    m_caster->RemoveAurasByType(SPELL_AURA_MOUNTED);

                    //5 different spells used depending on mounted speed and if mount can fly or not
                    if (flyspeed >= 4.1f)
                        // Flying Reindeer
                        m_caster->CastSpell(m_caster, 44827, true); //310% flying Reindeer
                    else if (flyspeed >= 3.8f)
                        // Flying Reindeer
                        m_caster->CastSpell(m_caster, 44825, true); //280% flying Reindeer
                    else if (flyspeed >= 1.6f)
                        // Flying Reindeer
                        m_caster->CastSpell(m_caster, 44824, true); //60% flying Reindeer
                    else if (speed >= 2.0f)
                        // Reindeer
                        m_caster->CastSpell(m_caster, 25859, true); //100% ground Reindeer
                    else
                        // Reindeer
                        m_caster->CastSpell(m_caster, 25858, true); //60% ground Reindeer

                    return;
                }
                case 26074:                                 // Holiday Cheer
                    // implemented at client side
                    return;
                // Polarity Shift
                case 28089:
                    if (unitTarget)
                        unitTarget->CastSpell(unitTarget, roll_chance_i(50) ? 28059 : 28084, true, NULL, NULL, m_caster->GetGUID());
                    break;
                // Polarity Shift
                case 39096:
                    if (unitTarget)
                        unitTarget->CastSpell(unitTarget, roll_chance_i(50) ? 39088 : 39091, true, NULL, NULL, m_caster->GetGUID());
                    break;
                case 29200:                                 // Purify Helboar Meat
                {
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    uint32 spell_id = roll_chance_i(50)
                        ? 29277                             // Summon Purified Helboar Meat
                        : 29278;                            // Summon Toxic Helboar Meat

                    m_caster->CastSpell(m_caster,spell_id,true,NULL);
                    return;
                }
                case 29858:                                 // Soulshatter
                    if (unitTarget && unitTarget->CanHaveThreatList()
                        && unitTarget->getThreatManager().getThreat(m_caster) > 0.0f)
                        m_caster->CastSpell(unitTarget,32835,true);
                    return;
                case 30458:                                 // Nigh Invulnerability
                    if (!m_CastItem) return;
                    if (roll_chance_i(86))                   // Nigh-Invulnerability   - success
                        m_caster->CastSpell(m_caster, 30456, true, m_CastItem);
                    else                                    // Complete Vulnerability - backfire in 14% casts
                        m_caster->CastSpell(m_caster, 30457, true, m_CastItem);
                    return;
                case 30507:                                 // Poultryizer
                    if (!m_CastItem) return;
                    if (roll_chance_i(80))                   // Poultryized! - success
                        m_caster->CastSpell(unitTarget, 30501, true, m_CastItem);
                    else                                    // Poultryized! - backfire 20%
                        m_caster->CastSpell(unitTarget, 30504, true, m_CastItem);
                    return;
                case 35745:                                 // Socrethar's Stone
                {
                    uint32 spell_id;
                    switch(m_caster->GetAreaId())
                    {
                        case 3900: spell_id = 35743; break; // Socrethar Portal
                        case 3742: spell_id = 35744; break; // Socrethar Portal
                        default: return;
                    }

                    m_caster->CastSpell(m_caster, spell_id, true);
                    return;
                }
                case 37674:                                 // Chaos Blast
                {
                    if (!unitTarget)
                        return;

                    int32 basepoints0 = 100;
                    m_caster->CastCustomSpell(unitTarget, 37675, &basepoints0, NULL, NULL, true);
                    return;
                }
                // Wrath of the Astromancer
                case 42784:
                {
                    uint32 count = 0;
                    for (std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                        if (ihit->effectMask & (1<<effIndex))
                            ++count;

                    damage = 12000; // maybe wrong value
                    damage /= count;

                    SpellEntry const *spellInfo = sSpellStore.LookupEntry(42784);

                     // now deal the damage
                    for (std::list<TargetInfo>::iterator ihit= m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                        if (ihit->effectMask & (1<<effIndex))
                        {
                            if (Unit* casttarget = Unit::GetUnit((*unitTarget), ihit->targetGUID))
                                m_caster->DealDamage(casttarget, damage, NULL, SPELL_DIRECT_DAMAGE, SPELL_SCHOOL_MASK_ARCANE, spellInfo, false);
                        }

                    return;
                }
                // Demon Broiled Surprise
                case 43723:
                {
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    Player *player = (Player*)m_caster;

                    if (player && player->GetQuestStatus(11379) == QUEST_STATUS_INCOMPLETE)
                    {
                        Creature *creature = player->FindNearestCreature(19973, 10, false);
                        if (!creature)
                        {
                            SendCastResult(SPELL_FAILED_NOT_HERE);
                            return;
                        }

                        player->CastSpell(player, 43753, false);
                    }
                    return;
                }
                case 44875:                                 // Complete Raptor Capture
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_UNIT)
                        return;

                    unitTarget->ToCreature()->ForcedDespawn();

                    //cast spell Raptor Capture Credit
                    m_caster->CastSpell(m_caster, 42337, true, NULL);
                    return;
                }
                case 47170:                                 // Impale Leviroth
                {
                    if (!unitTarget && unitTarget->GetEntry() != 26452 && unitTarget->HealthAbovePct(95))
                        return;

                        m_caster->DealDamage(unitTarget, unitTarget->CountPctFromMaxHealth(93));
                        return;
                }
                case 49357:                                 // Brewfest Mount Transformation
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;
                    if (!m_caster->HasAuraType(SPELL_AURA_MOUNTED))
                        return;
                    m_caster->RemoveAurasByType(SPELL_AURA_MOUNTED);
                    // Ram for Alliance, Kodo for Horde
                    if (m_caster->ToPlayer()->GetTeam() == ALLIANCE)
                    {
                        if (m_caster->GetSpeedRate(MOVE_RUN) >= 2.0f)
                            // 100% Ram
                            m_caster->CastSpell(m_caster, 43900, true);
                        else
                            // 60% Ram
                            m_caster->CastSpell(m_caster, 43899, true);
                    }
                    else
                    {
                        if (m_caster->ToPlayer()->GetSpeedRate(MOVE_RUN) >= 2.0f)
                            // 100% Kodo
                            m_caster->CastSpell(m_caster, 49379, true);
                        else
                            // 60% Kodo
                            m_caster->CastSpell(m_caster, 49378, true);
                    }
                    return;
                case 52845:                                 // Brewfest Mount Transformation (Faction Swap)
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;
                    if (!m_caster->HasAuraType(SPELL_AURA_MOUNTED))
                        return;
                    m_caster->RemoveAurasByType(SPELL_AURA_MOUNTED);
                    // Ram for Horde, Kodo for Alliance
                    if (m_caster->ToPlayer()->GetTeam() == HORDE)
                    {
                        if (m_caster->GetSpeedRate(MOVE_RUN) >= 2.0f)
                            // 100% Ram
                            m_caster->CastSpell(m_caster, 43900, true);
                        else
                            // 60% Ram
                            m_caster->CastSpell(m_caster, 43899, true);
                    }
                    else
                    {
                        if (m_caster->ToPlayer()->GetSpeedRate(MOVE_RUN) >= 2.0f)
                            // 100% Kodo
                            m_caster->CastSpell(m_caster, 49379, true);
                        else
                            // 60% Kodo
                            m_caster->CastSpell(m_caster, 49378, true);
                    }
                    return;
                case 55004:                                 // Nitro Boosts
                    if (!m_CastItem)
                        return;
                    if (roll_chance_i(95))                  // Nitro Boosts - success
                        m_caster->CastSpell(m_caster, 54861, true, m_CastItem);
                    else                                    // Knocked Up   - backfire 5%
                        m_caster->CastSpell(m_caster, 46014, true, m_CastItem);
                    return;
                case 50243:                                 // Teach Language
                {
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // spell has a 1/3 chance to trigger one of the below
                    if (roll_chance_i(66))
                        return;
                    if (m_caster->ToPlayer()->GetTeam() == ALLIANCE)
                    {
                        // 1000001 - gnomish binary
                        m_caster->CastSpell(m_caster, 50242, true);
                    }
                    else
                    {
                        // 01001000 - goblin binary
                        m_caster->CastSpell(m_caster, 50246, true);
                    }

                    return;
                }
                case 51582:                                 //Rocket Boots Engaged (Rocket Boots Xtreme and Rocket Boots Xtreme Lite)
                {
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    if (Battleground* bg = m_caster->ToPlayer()->GetBattleground())
                        bg->EventPlayerDroppedFlag(m_caster->ToPlayer());

                    m_caster->CastSpell(m_caster, 30452, true, NULL);
                    return;
                }
                case 52759:                                 // Ancestral Awakening
                    if (!unitTarget)
                        return;
                    m_caster->CastCustomSpell(unitTarget, 52752, &damage, NULL, NULL, true);
                    return;
                case 54171:                                   //Divine Storm
                {
                    m_caster->CastCustomSpell(unitTarget, 54172, &damage, 0, 0, true);
                    return;
                }
                case 58418:                                 // Portal to Orgrimmar
                case 58420:                                 // Portal to Stormwind
                    return;                                 // implemented in EffectScript[0]
                case 62324: // Throw Passenger
                {
                    if (m_targets.HasTraj())
                    {
                        if (Vehicle *vehicle = m_caster->GetVehicleKit())
                            if (Unit *passenger = vehicle->GetPassenger(damage - 1))
                            {
                                std::list<Unit*> unitList;
                                // use 99 because it is 3d search
                                SearchAreaTarget(unitList, 99, PUSH_DST_CENTER, SPELL_TARGETS_ENTRY, 33114);
                                float minDist = 99 * 99;
                                Vehicle *target = NULL;
                                for (std::list<Unit*>::iterator itr = unitList.begin(); itr != unitList.end(); ++itr)
                                {
                                    if (Vehicle *seat = (*itr)->GetVehicleKit())
                                        if (!seat->GetPassenger(0))
                                            if (Unit *device = seat->GetPassenger(2))
                                                if (!device->GetCurrentSpell(CURRENT_CHANNELED_SPELL))
                                                {
                                                    float dist = (*itr)->GetExactDistSq(&m_targets.m_dstPos);
                                                    if (dist < minDist)
                                                    {
                                                        minDist = dist;
                                                        target = seat;
                                                    }
                                                }
                                }
                                if (target && target->GetBase()->IsWithinDist2d(&m_targets.m_dstPos, GetSpellRadius(m_spellInfo, effIndex, false) * 2)) // now we use *2 because the location of the seat is not correct
                                    passenger->EnterVehicle(target, 0);
                                else
                                {
                                    passenger->ExitVehicle();
                                    float x, y, z;
                                    m_targets.m_dstPos.GetPosition(x, y, z);
                                    passenger->GetMotionMaster()->MoveJump(x, y, z, m_targets.GetSpeedXY(), m_targets.GetSpeedZ());
                                }
                            }
                    }
                    return;
                }
                case 64385:                                 // Unusual Compass
                {
                    m_caster->SetOrientation(float(urand(0,62832)) / 10000.0f);
                    WorldPacket data;
                    m_caster->BuildHeartBeatMsg(&data);
                    m_caster->SendMessageToSet(&data,true);
                    return;
                }
            }

            break;
        }
        case SPELLFAMILY_WARRIOR:
            // Charge
            if (m_spellInfo->SpellFamilyFlags & SPELLFAMILYFLAG_WARRIOR_CHARGE && m_spellInfo->SpellVisual[0] == 867)
            {
                int32 chargeBasePoints0 = damage;
                m_caster->CastCustomSpell(m_caster, 34846, &chargeBasePoints0, NULL, NULL, true);

                //Juggernaut crit bonus
                if (m_caster->HasAura(64976))
                    m_caster->CastSpell(m_caster, 65156, true);
                return;
            }
            //Slam
            if (m_spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_WARRIOR_SLAM && m_spellInfo->SpellIconID == 559)
            {
                int32 bp0 = damage;
                m_caster->CastCustomSpell(unitTarget, 50783, &bp0, NULL, NULL, true, 0);
                return;
            }
            // Execute
            if (m_spellInfo->SpellFamilyFlags[EFFECT_0] & SPELLFAMILYFLAG_WARRIOR_EXECUTE)
            {
                if (!unitTarget)
                    return;

                spell_id = 20647;

                int32 rageUsed = std::min<int32>(300 - m_powerCost, m_caster->GetPower(POWER_RAGE));
                int32 newRage = std::max<int32>(0, m_caster->GetPower(POWER_RAGE) - rageUsed);

                // Sudden Death rage save
                if (AuraEffect * aurEff = m_caster->GetAuraEffect(SPELL_AURA_PROC_TRIGGER_SPELL, SPELLFAMILY_GENERIC, 1989, EFFECT_0))
                {
                    int32 ragesave = SpellMgr::CalculateSpellEffectAmount(aurEff->GetSpellProto(), EFFECT_1) * 10;
                    newRage = std::max(newRage, ragesave);
                }

                m_caster->SetPower(POWER_RAGE, uint32(newRage));

                // Glyph of Execution bonus
                if (AuraEffect * aurEff = m_caster->GetAuraEffect(58367, EFFECT_0))
                    rageUsed += aurEff->GetAmount() * 10;

                bp = damage + int32(rageUsed * m_spellInfo->EffectDamageMultiplier[effIndex] + m_caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.2f);
                break;
            }
            // Concussion Blow
            if (m_spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_WARRIOR_CONCUSSION_BLOW)
            {
                m_damage+= uint32(damage * m_caster->GetTotalAttackPowerValue(BASE_ATTACK) / 100);
                return;
            }
            switch(m_spellInfo->Id)
            {
                // Bloodthirst
                case 23881:
                {
                    m_caster->CastCustomSpell(unitTarget, 23885, &damage, NULL, NULL, true, NULL);
                    return;
                }
            }
            break;
        case SPELLFAMILY_WARLOCK:
            // Life Tap
            if (m_spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_WARLOCK_LIFETAP)
            {
                float spFactor = 0.0f;
                switch (m_spellInfo->Id)
                {
                    case 11689: spFactor = 0.2f; break;
                    case 27222:
                    case 57946: spFactor = 0.5f; break;
                }
                int32 damage = int32(SpellMgr::CalculateSpellEffectAmount(m_spellInfo, 0) + (6.3875 * m_spellInfo->baseLevel));
                int32 mana = int32(damage + (m_caster->ToPlayer()->GetUInt32Value(PLAYER_FIELD_MOD_DAMAGE_DONE_POS+SPELL_SCHOOL_SHADOW) * spFactor));

                if (unitTarget && (int32(unitTarget->GetHealth()) > damage))
                {
                    // Shouldn't Appear in Combat Log
                    unitTarget->ModifyHealth(-damage);

                    // Improved Life Tap mod
                    if (AuraEffect const * aurEff = m_caster->GetDummyAuraEffect(SPELLFAMILY_WARLOCK, 208, 0))
                        mana = (aurEff->GetAmount() + 100)* mana / 100;

                    m_caster->CastCustomSpell(unitTarget, 31818, &mana, NULL, NULL, true);

                    // Mana Feed
                    int32 manaFeedVal = 0;
                    if (AuraEffect const * aurEff = m_caster->GetAuraEffect(SPELL_AURA_ADD_FLAT_MODIFIER, SPELLFAMILY_WARLOCK, 1982, 0))
                        manaFeedVal = aurEff->GetAmount();

                    if (manaFeedVal > 0)
                    {
                        manaFeedVal = manaFeedVal * mana / 100;
                        m_caster->CastCustomSpell(m_caster, 32553, &manaFeedVal, NULL, NULL, true, NULL);
                    }
                }
                else
                    SendCastResult(SPELL_FAILED_FIZZLE);
                return;
            }
            break;
        case SPELLFAMILY_DRUID:
            // Starfall
            if (m_spellInfo->SpellFamilyFlags[2] & SPELLFAMILYFLAG2_DRUID_STARFALL)
            {
                //Shapeshifting into an animal form or mounting cancels the effect.
                if (m_caster->GetCreatureType() == CREATURE_TYPE_BEAST || m_caster->IsMounted())
                {
                    if (m_triggeredByAuraSpell)
                        m_caster->RemoveAurasDueToSpell(m_triggeredByAuraSpell->Id);
                    return;
                }

                //Any effect which causes you to lose control of your character will supress the starfall effect.
                if (m_caster->hasUnitState(UNIT_STAT_STUNNED | UNIT_STAT_FLEEING | UNIT_STAT_ROOT | UNIT_STAT_CONFUSED))
                    return;

                m_caster->CastSpell(unitTarget, damage, true);
                return;
            }
            break;
        case SPELLFAMILY_PALADIN:
            // Divine Storm
            if (m_spellInfo->SpellFamilyFlags[1] & SPELLFAMILYFLAG1_PALADIN_DIVINESTORM && effIndex == 1)
            {
                int32 dmg = m_damage * damage / 100;
                if (!unitTarget)
                    unitTarget = m_caster;
                m_caster->CastCustomSpell(unitTarget, 54171, &dmg, 0, 0, true);
                return;
            }

            switch(m_spellInfo->Id)
            {
                case 31789:                                 // Righteous Defense (step 1)
                {
                    // Clear targets for eff 1
                    for (std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                        ihit->effectMask &= ~(1<<1);

                    // not empty (checked), copy
                    Unit::AttackerSet attackers = unitTarget->getAttackers();

                    // selected from list 3
                    for (uint32 i = 0; i < std::min(size_t(3), attackers.size()); ++i)
                    {
                        Unit::AttackerSet::iterator aItr = attackers.begin();
                        std::advance(aItr, rand() % attackers.size());
                        AddUnitTarget((*aItr), 1);
                        attackers.erase(aItr);
                    }

                    // now let next effect cast spell at each target.
                    return;
                }
            }
            break;
        case SPELLFAMILY_SHAMAN:
            // Cleansing Totem Pulse
            if (m_spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_SHAMAN_TOTEM_EFFECTS && m_spellInfo->SpellIconID == 1673)
            {
                int32 bp1 = 1;
                // Cleansing Totem Effect
                if (unitTarget)
                    m_caster->CastCustomSpell(unitTarget, 52025, NULL, &bp1, NULL, true, NULL, NULL, m_originalCasterGUID);
                return;
            }
            // Healing Stream Totem
            if (m_spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_SHAMAN_HEALING_STREAM)
            {
                if (!unitTarget)
                    return;
                // Restorative Totems
                if (Unit *owner = m_caster->GetOwner())
                    if (AuraEffect *dummy = owner->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_SHAMAN, 338, 1))
                        damage += damage * dummy->GetAmount() / 100;

                    m_caster->CastCustomSpell(unitTarget, 52042, &damage, 0, 0, true, 0, 0, m_originalCasterGUID);
                return;
            }
            // Mana Spring Totem
            if (m_spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_SHAMAN_MANA_SPRING)
            {
                if (!unitTarget || unitTarget->getPowerType() != POWER_MANA)
                    return;
                m_caster->CastCustomSpell(unitTarget, 52032, &damage, 0, 0, true, 0, 0, m_originalCasterGUID);
                return;
            }
            // Lava Lash
            if (m_spellInfo->SpellFamilyFlags[2] & SPELLFAMILYFLAG2_SHAMAN_LAVA_LASH)
            {
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return;

                if (m_caster->ToPlayer()->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND))
                {
                    // Damage is increased by 25% if your off-hand weapon is enchanted with Flametongue.
                    if (m_caster->GetAuraEffect(SPELL_AURA_DUMMY, SPELLFAMILY_SHAMAN, 0x200000, 0, 0))
                        m_damage += m_damage * damage / 100;
                }
                return;
            }
            break;
        case SPELLFAMILY_DEATHKNIGHT:
            // Death strike
            if (m_spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_DK_DEATH_STRIKE)
            {
                uint32 count = unitTarget->GetDiseasesByCaster(m_caster->GetGUID());
                int32 bp = int32(count * m_caster->CountPctFromMaxHealth(int32(m_spellInfo->EffectDamageMultiplier[0])));
                // Improved Death Strike
                if (AuraEffect const * aurEff = m_caster->GetAuraEffect(SPELL_AURA_ADD_PCT_MODIFIER, SPELLFAMILY_DEATHKNIGHT, 2751, 0))
                    bp = int32(bp * (m_caster->CalculateSpellDamage(m_caster, aurEff->GetSpellProto(), 2) + 100.0f) / 100.0f);
                m_caster->CastCustomSpell(m_caster, 45470, &bp, NULL, NULL, false);
                return;
            }
            // Death Coil
            if (m_spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_DK_DEATH_COIL)
            {
                if (m_caster->IsFriendlyTo(unitTarget))
                {
                    int32 bp = int32(damage * 1.5f);
                    m_caster->CastCustomSpell(unitTarget, 47633, &bp, NULL, NULL, true);
                }
                else
                {
                    int32 bp = damage;
                    m_caster->CastCustomSpell(unitTarget, 47632, &bp, NULL, NULL, true);
                }
                return;
            }
            switch (m_spellInfo->Id)
            {
            case 49560: // Death Grip
                Position pos;
                GetSummonPosition(effIndex, pos);
                if (Unit *unit = unitTarget->GetVehicleBase()) // what is this for?
                    unit->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), damage, true);
                else
                    unitTarget->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), damage, true);
                return;
            case 46584: // Raise Dead
                if (m_caster->GetTypeId() != TYPEID_PLAYER)
                    return;

                // Do we have talent Master of Ghouls?
                if (m_caster->HasAura(52143))
                    // summon as pet
                    bp = 52150;
                else
                    // or guardian
                    bp = 46585;

                if (m_targets.HasDst())
                    targets.setDst(m_targets.m_dstPos);
                else
                {
                    targets.setDst(*m_caster);
                    // Corpse not found - take reagents (only not triggered cast can take them)
                    triggered = false;
                }
                // Remove cooldown - summon spellls have category
                m_caster->ToPlayer()->RemoveSpellCooldown(m_spellInfo->Id, true);
                spell_id = 48289;
                break;
            // Raise dead - take reagents and trigger summon spells
            case 48289:
                if (m_targets.HasDst())
                    targets.setDst(m_targets.m_dstPos);

                spell_id = CalculateDamage(0, NULL);
                break;
            }
            break;
    }

    //spells triggered by dummy effect should not miss
    if (spell_id)
    {
        SpellEntry const *spellInfo = sSpellStore.LookupEntry(spell_id);

        if (!spellInfo)
        {
            sLog.outError("EffectDummy of spell %u: triggering unknown spell id %i\n", m_spellInfo->Id, spell_id);
            return;
        }

        targets.setUnitTarget(unitTarget);
        Spell* spell = new Spell(m_caster, spellInfo, triggered, m_originalCasterGUID, true);
        if (bp) spell->SetSpellValue(SPELLVALUE_BASE_POINT0, bp);
        spell->prepare(&targets);
    }

    // pet auras
    if (PetAura const* petSpell = sSpellMgr.GetPetAura(m_spellInfo->Id,effIndex))
    {
        m_caster->AddPetAura(petSpell);
        return;
    }

    // normal DB scripted effect
    sLog.outDebug("Spell ScriptStart spellid %u in EffectDummy(%u)", m_spellInfo->Id, effIndex);
    m_caster->GetMap()->ScriptsStart(sSpellScripts, uint32(m_spellInfo->Id | (effIndex << 24)), m_caster, unitTarget);

    // Script based implementation. Must be used only for not good for implementation in core spell effects
    // So called only for not proccessed cases
    if (gameObjTarget)
        sScriptMgr.OnDummyEffect(m_caster, m_spellInfo->Id, effIndex, gameObjTarget);
    else if (unitTarget && unitTarget->GetTypeId() == TYPEID_UNIT)
        sScriptMgr.OnDummyEffect(m_caster, m_spellInfo->Id, effIndex, unitTarget->ToCreature());
    else if (itemTarget)
        sScriptMgr.OnDummyEffect(m_caster, m_spellInfo->Id, effIndex, itemTarget);
}

void Spell::EffectTriggerSpellWithValue(SpellEffIndex effIndex)
{
    uint32 triggered_spell_id = m_spellInfo->EffectTriggerSpell[effIndex];

    // normal case
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(triggered_spell_id);

    if (!spellInfo)
    {
        sLog.outError("EffectTriggerSpellWithValue of spell %u: triggering unknown spell id %i", m_spellInfo->Id,triggered_spell_id);
        return;
    }

    int32 bp = damage;
    Unit * caster = GetTriggeredSpellCaster(spellInfo, m_caster, unitTarget);

    caster->CastCustomSpell(unitTarget,triggered_spell_id,&bp,&bp,&bp,true);
}

void Spell::EffectTriggerRitualOfSummoning(SpellEffIndex effIndex)
{
    uint32 triggered_spell_id = m_spellInfo->EffectTriggerSpell[effIndex];
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(triggered_spell_id);

    if (!spellInfo)
    {
        sLog.outError("EffectTriggerRitualOfSummoning of spell %u: triggering unknown spell id %i", m_spellInfo->Id,triggered_spell_id);
        return;
    }

    finish();

    m_caster->CastSpell(unitTarget,spellInfo,false);
}

void Spell::EffectForceCast(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;

    uint32 triggered_spell_id = m_spellInfo->EffectTriggerSpell[effIndex];

    // normal case
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(triggered_spell_id);

    if (!spellInfo)
    {
        sLog.outError("EffectForceCast of spell %u: triggering unknown spell id %i", m_spellInfo->Id,triggered_spell_id);
        return;
    }

    if (damage)
    {
        switch(m_spellInfo->Id)
        {
            case 52588: // Skeletal Gryphon Escape
            case 48598: // Ride Flamebringer Cue
                unitTarget->RemoveAura(damage);
                break;
            case 52463: // Hide In Mine Car
            case 52349: // Overtake
                unitTarget->CastCustomSpell(unitTarget, spellInfo->Id, &damage, NULL, NULL, true, NULL, NULL, m_originalCasterGUID);
                return;
            case 72378: // Blood Nova
            case 73058: // Blood Nova
                spellInfo = sSpellMgr.GetSpellForDifficultyFromSpell(spellInfo, m_caster);
                break;
        }
    }
    Unit * caster = GetTriggeredSpellCaster(spellInfo, m_caster, unitTarget);

    caster->CastSpell(unitTarget, spellInfo, true, NULL, NULL, m_originalCasterGUID);
}

void Spell::EffectForceCastWithValue(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;

    uint32 triggered_spell_id = m_spellInfo->EffectTriggerSpell[effIndex];

    // normal case
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(triggered_spell_id);

    if (!spellInfo)
    {
        sLog.outError("EffectForceCastWithValue of spell %u: triggering unknown spell id %i", m_spellInfo->Id,triggered_spell_id);
        return;
    }
    int32 bp = damage;
    Unit * caster = GetTriggeredSpellCaster(spellInfo, m_caster, unitTarget);

    caster->CastCustomSpell(unitTarget, spellInfo->Id, &bp, &bp, &bp, true, NULL, NULL, m_originalCasterGUID);
}


void Spell::EffectTriggerSpell(SpellEffIndex effIndex)
{
    // only unit case known
    if (!unitTarget)
    {
        if (gameObjTarget || itemTarget)
            sLog.outError("Spell::EffectTriggerSpell (Spell: %u): Unsupported non-unit case!",m_spellInfo->Id);
        return;
    }

    uint32 triggered_spell_id = m_spellInfo->EffectTriggerSpell[effIndex];
    Unit* originalCaster = NULL;

    // special cases
    switch(triggered_spell_id)
    {
        // Mirror Image
        case 58832:
        {
            // Glyph of Mirror Image
            if (m_caster->HasAura(63093))
               m_caster->CastSpell(m_caster, 65047, true); // Mirror Image

            break;
        }
        // Vanish (not exist)
        case 18461:
        {
            unitTarget->RemoveMovementImpairingAuras();
            unitTarget->RemoveAurasByType(SPELL_AURA_MOD_STALKED);

            // if this spell is given to NPC it must handle rest by it's own AI
            if (unitTarget->GetTypeId() != TYPEID_PLAYER)
                return;

            // get highest rank of the Stealth spell
            uint32 spellId = 0;
            SpellEntry const *spellInfo;
            const PlayerSpellMap& sp_list = unitTarget->ToPlayer()->GetSpellMap();
            for (PlayerSpellMap::const_iterator itr = sp_list.begin(); itr != sp_list.end(); ++itr)
            {
                // only highest rank is shown in spell book, so simply check if shown in spell book
                if (!itr->second->active || itr->second->disabled || itr->second->state == PLAYERSPELL_REMOVED)
                    continue;

                spellInfo = sSpellStore.LookupEntry(itr->first);
                if (!spellInfo)
                    continue;

                if (spellInfo->SpellFamilyName == SPELLFAMILY_ROGUE && spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_ROGUE_STEALTH)
                {
                    spellId = spellInfo->Id;
                    break;
                }
            }

            // no Stealth spell found
            if (!spellId)
                return;

            // reset cooldown on it if needed
            if (unitTarget->ToPlayer()->HasSpellCooldown(spellId))
                unitTarget->ToPlayer()->RemoveSpellCooldown(spellId);

            triggered_spell_id =  spellId;
            return;
        }
        // Demonic Empowerment -- succubus
        case 54437:
        {
            unitTarget->RemoveMovementImpairingAuras();
            unitTarget->RemoveAurasByType(SPELL_AURA_MOD_STALKED);
            unitTarget->RemoveAurasByType(SPELL_AURA_MOD_STUN);

            // Cast Lesser Invisibility
            triggered_spell_id = 7870;
            break;
        }
        // just skip
        case 23770:                                         // Sayge's Dark Fortune of *
            // not exist, common cooldown can be implemented in scripts if need.
            return;
        // Brittle Armor - (need add max stack of 24575 Brittle Armor)
        case 29284:
        {
            // Brittle Armor
            SpellEntry const* spell = sSpellStore.LookupEntry(24575);
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
            SpellEntry const* spell = sSpellStore.LookupEntry(26464);
            if (!spell)
                return;

            for (uint32 j = 0; j < spell->StackAmount; ++j)
                m_caster->CastSpell(unitTarget, spell->Id, true);
            return;
        }
        // Righteous Defense
        case 31980:
        {
            m_caster->CastSpell(unitTarget, 31790, true);
            return;
        }
        // Cloak of Shadows
        case 35729:
        {
            uint32 dispelMask = GetDispellMask(DISPEL_ALL);
            Unit::AuraApplicationMap& Auras = unitTarget->GetAppliedAuras();
            for (Unit::AuraApplicationMap::iterator iter = Auras.begin(); iter != Auras.end();)
            {
                // remove all harmful spells on you...
                SpellEntry const* spell = iter->second->GetBase()->GetSpellProto();
                if ((spell->DmgClass == SPELL_DAMAGE_CLASS_MAGIC // only affect magic spells
                    || ((1<<spell->Dispel) & dispelMask))
                    // ignore positive and passive auras
                    && !iter->second->IsPositive() && !iter->second->GetBase()->IsPassive())
                {
                    m_caster->RemoveAura(iter);
                }
                else
                    iter++;
            }
            return;
        }
        // Priest Shadowfiend (34433) need apply mana gain trigger aura on pet
        case 41967:
        {
            if (Unit *pet = unitTarget->GetGuardianPet())
                pet->CastSpell(pet, 28305, true);
            return;
        }
        // Empower Rune Weapon
        case 53258:
            return; // skip, hack-added in spell effect
        // Snake Trap
        case 57879:
            originalCaster = m_originalCaster;
            break;
        // Coldflame
        case 33801:
            return; // just make the core stfu
    }

    // normal case
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(triggered_spell_id);
    if (!spellInfo)
    {
        sLog.outError("EffectTriggerSpell of spell %u: triggering unknown spell id %i", m_spellInfo->Id,triggered_spell_id);
        return;
    }

    // Remove spell cooldown (not category) if spell triggering spell with cooldown and same category
    // Needed by freezing arrow and few other spells
    if (m_caster->GetTypeId() == TYPEID_PLAYER && m_spellInfo->CategoryRecoveryTime && spellInfo->CategoryRecoveryTime
        && m_spellInfo->Category == spellInfo->Category)
        m_caster->ToPlayer()->RemoveSpellCooldown(spellInfo->Id);

    // Note: not exist spells with weapon req. and IsSpellHaveCasterSourceTargets == true
    // so this just for speedup places in else
    Unit * caster = GetTriggeredSpellCaster(spellInfo, m_caster, unitTarget);

    caster->CastSpell(unitTarget,spellInfo,true, 0, 0, (originalCaster ? originalCaster->GetGUID() : 0));
}

void Spell::EffectTriggerMissileSpell(SpellEffIndex effIndex)
{
    uint32 triggered_spell_id = m_spellInfo->EffectTriggerSpell[effIndex];

    // normal case
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(triggered_spell_id);

    if (!spellInfo)
    {
        sLog.outError("EffectTriggerMissileSpell of spell %u (eff: %u): triggering unknown spell id %u",
            m_spellInfo->Id,effIndex,triggered_spell_id);
        return;
    }

    if (m_CastItem)
        sLog.outStaticDebug("WORLD: cast Item spellId - %i", spellInfo->Id);

    // Remove spell cooldown (not category) if spell triggering spell with cooldown and same category
    // Needed by freezing arrow and few other spells
    if (m_caster->GetTypeId() == TYPEID_PLAYER && m_spellInfo->CategoryRecoveryTime && spellInfo->CategoryRecoveryTime
        && m_spellInfo->Category == spellInfo->Category)
        m_caster->ToPlayer()->RemoveSpellCooldown(spellInfo->Id);

    float x, y, z;
    m_targets.m_dstPos.GetPosition(x, y, z);
    m_caster->CastSpell(x, y, z, spellInfo->Id, true, m_CastItem, 0, m_originalCasterGUID);
}

void Spell::EffectJump(SpellEffIndex effIndex)
{
    if (m_caster->isInFlight())
        return;

    float x,y,z,o;
    if (m_targets.getUnitTarget())
    {
        m_targets.getUnitTarget()->GetContactPoint(m_caster,x,y,z,CONTACT_DISTANCE);
        o = m_caster->GetOrientation();
    }
    else if (m_targets.getGOTarget())
    {
        m_targets.getGOTarget()->GetContactPoint(m_caster,x,y,z,CONTACT_DISTANCE);
        o = m_caster->GetOrientation();
    }
    else
    {
        sLog.outError("Spell::EffectJump - unsupported target mode for spell ID %u", m_spellInfo->Id);
        return;
    }

    float speedXY, speedZ;
    CalculateJumpSpeeds(effIndex, m_caster->GetExactDist2d(x, y), speedXY, speedZ);
    m_caster->GetMotionMaster()->MoveJump(x, y, z, speedXY, speedZ);
}

void Spell::EffectJumpDest(SpellEffIndex effIndex)
{
    if (m_caster->isInFlight())
        return;

    // Init dest coordinates
    float x,y,z,o;
    if (m_targets.HasDst())
    {
        m_targets.m_dstPos.GetPosition(x, y, z);

        if (m_spellInfo->EffectImplicitTargetA[effIndex] == TARGET_DEST_TARGET_BACK)
        {
            // explicit cast data from client or server-side cast
            // some spell at client send caster
            Unit* pTarget = NULL;
            if (m_targets.getUnitTarget() && m_targets.getUnitTarget() != m_caster)
                pTarget = m_targets.getUnitTarget();
            else if (m_caster->getVictim())
                pTarget = m_caster->getVictim();
            else if (m_caster->GetTypeId() == TYPEID_PLAYER)
                pTarget = ObjectAccessor::GetUnit(*m_caster, m_caster->ToPlayer()->GetSelection());

            o = pTarget ? pTarget->GetOrientation() : m_caster->GetOrientation();
        }
        else
            o = m_caster->GetOrientation();
    }
    else
    {
        sLog.outError("Spell::EffectJumpDest - unsupported target mode for spell ID %u", m_spellInfo->Id);
        return;
    }

    float speedXY, speedZ;
    CalculateJumpSpeeds(effIndex, m_caster->GetExactDist2d(x, y), speedXY, speedZ);
    m_caster->GetMotionMaster()->MoveJump(x, y, z, speedXY, speedZ);
}

void Spell::CalculateJumpSpeeds(uint8 i, float dist, float & speedXY, float & speedZ)
{
    if (m_spellInfo->EffectMiscValue[i])
        speedZ = float(m_spellInfo->EffectMiscValue[i])/10;
    else if (m_spellInfo->EffectMiscValueB[i])
        speedZ = float(m_spellInfo->EffectMiscValueB[i])/10;
    else
        speedZ = 10.0f;
    speedXY = dist * 10.0f / speedZ;
}

void Spell::EffectTeleportUnits(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || unitTarget->isInFlight())
        return;

    // Pre effects
    uint8 uiMaxSafeLevel = 0;
    switch (m_spellInfo->Id)
    {
        case 48129:  // Scroll of Recall
            uiMaxSafeLevel = 40;
        case 60320:  // Scroll of Recall II
            if (!uiMaxSafeLevel)
                uiMaxSafeLevel = 70;
        case 60321:  // Scroll of Recal III
            if (!uiMaxSafeLevel)
                uiMaxSafeLevel = 80;

            if (unitTarget->getLevel() > uiMaxSafeLevel)
            {
                unitTarget->AddAura(60444,unitTarget); //Apply Lost! Aura
                return;
            }
            break;
    }

    // If not exist data for dest location - return
    if (!m_targets.HasDst())
    {
        sLog.outError("Spell::EffectTeleportUnits - does not have destination for spell ID %u\n", m_spellInfo->Id);
        return;
    }

    // Init dest coordinates
    uint32 mapid = m_targets.m_dstPos.GetMapId();
    if (mapid == MAPID_INVALID)
        mapid = unitTarget->GetMapId();
    float x, y, z, orientation;
    m_targets.m_dstPos.GetPosition(x, y, z, orientation);
    if (!orientation && m_targets.getUnitTarget())
        orientation = m_targets.getUnitTarget()->GetOrientation();
    sLog.outDebug("Spell::EffectTeleportUnits - teleport unit to %u %f %f %f %f\n", mapid, x, y, z, orientation);

    if (mapid == unitTarget->GetMapId())
        unitTarget->NearTeleportTo(x, y, z, orientation, unitTarget == m_caster);
    else if (unitTarget->GetTypeId() == TYPEID_PLAYER)
        unitTarget->ToPlayer()->TeleportTo(mapid, x, y, z, orientation, unitTarget == m_caster ? TELE_TO_SPELL : 0);

    // post effects for TARGET_DST_DB
    switch (m_spellInfo->Id)
    {
        // Dimensional Ripper - Everlook
        case 23442:
        {
            int32 r = irand(0, 119);
            if (r >= 70)                                  // 7/12 success
            {
                if (r < 100)                              // 4/12 evil twin
                    m_caster->CastSpell(m_caster, 23445, true);
                else                                        // 1/12 fire
                    m_caster->CastSpell(m_caster, 23449, true);
            }
            return;
        }
        // Ultrasafe Transporter: Toshley's Station
        case 36941:
        {
            if (roll_chance_i(50))                        // 50% success
            {
                int32 rand_eff = urand(1, 7);
                switch (rand_eff)
                {
                    case 1:
                        // soul split - evil
                        m_caster->CastSpell(m_caster, 36900, true);
                        break;
                    case 2:
                        // soul split - good
                        m_caster->CastSpell(m_caster, 36901, true);
                        break;
                    case 3:
                        // Increase the size
                        m_caster->CastSpell(m_caster, 36895, true);
                        break;
                    case 4:
                        // Decrease the size
                        m_caster->CastSpell(m_caster, 36893, true);
                        break;
                    case 5:
                    // Transform
                    {
                        if (m_caster->ToPlayer()->GetTeam() == ALLIANCE)
                            m_caster->CastSpell(m_caster, 36897, true);
                        else
                            m_caster->CastSpell(m_caster, 36899, true);
                        break;
                    }
                    case 6:
                        // chicken
                        m_caster->CastSpell(m_caster, 36940, true);
                        break;
                    case 7:
                        // evil twin
                        m_caster->CastSpell(m_caster, 23445, true);
                        break;
                }
            }
            return;
        }
        // Dimensional Ripper - Area 52
        case 36890:
        {
            if (roll_chance_i(50))                        // 50% success
            {
                int32 rand_eff = urand(1, 4);
                switch (rand_eff)
                {
                    case 1:
                        // soul split - evil
                        m_caster->CastSpell(m_caster, 36900, true);
                        break;
                    case 2:
                        // soul split - good
                        m_caster->CastSpell(m_caster, 36901, true);
                        break;
                    case 3:
                        // Increase the size
                        m_caster->CastSpell(m_caster, 36895, true);
                        break;
                    case 4:
                        // Transform
                    {
                        if (m_caster->ToPlayer()->GetTeam() == ALLIANCE)
                            m_caster->CastSpell(m_caster, 36897, true);
                        else
                            m_caster->CastSpell(m_caster, 36899, true);
                        break;
                    }
                }
            }
            return;
        }
    }
}

void Spell::EffectApplyAura(SpellEffIndex effIndex)
{
    if (!m_spellAura || !unitTarget)
        return;
    ASSERT(unitTarget == m_spellAura->GetOwner());
    m_spellAura->_ApplyEffectForTargets(effIndex);
}

void Spell::EffectApplyAreaAura(SpellEffIndex effIndex)
{
    if (!m_spellAura || !unitTarget)
        return;
    ASSERT (unitTarget == m_spellAura->GetOwner());
    m_spellAura->_ApplyEffectForTargets(effIndex);
}

void Spell::EffectUnlearnSpecialization(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player *_player = (Player*)unitTarget;
    uint32 spellToUnlearn = m_spellInfo->EffectTriggerSpell[effIndex];

    _player->removeSpell(spellToUnlearn);

    sLog.outDebug("Spell: Player %u has unlearned spell %u from NpcGUID: %u", _player->GetGUIDLow(), spellToUnlearn, m_caster->GetGUIDLow());
}

void Spell::EffectPowerDrain(SpellEffIndex effIndex)
{
    if (m_spellInfo->EffectMiscValue[effIndex] < 0 || m_spellInfo->EffectMiscValue[effIndex] >= int8(MAX_POWERS))
        return;

    Powers powerType = Powers(m_spellInfo->EffectMiscValue[effIndex]);

    if (!unitTarget || !unitTarget->isAlive() || unitTarget->getPowerType() != powerType || damage < 0)
        return;

    // add spell damage bonus
    damage = m_caster->SpellDamageBonus(unitTarget, m_spellInfo, uint32(damage), SPELL_DIRECT_DAMAGE);

    // resilience reduce mana draining effect at spell crit damage reduction (added in 2.4)
    int32 power = damage;
    if (powerType == POWER_MANA)
        power -= unitTarget->GetSpellCritDamageReduction(power);

    int32 newDamage = -(unitTarget->ModifyPower(powerType, -int32(power)));

    float gainMultiplier = 0.0f;

    // Don`t restore from self drain
    if (m_caster != unitTarget)
    {
        gainMultiplier = SpellMgr::CalculateSpellEffectValueMultiplier(m_spellInfo, effIndex, m_originalCaster, this);

        int32 gain = int32(newDamage * gainMultiplier);

        m_caster->EnergizeBySpell(m_caster, m_spellInfo->Id, gain, powerType);
    }
    ExecuteLogEffectTakeTargetPower(effIndex, unitTarget, powerType, newDamage, gainMultiplier);
}

void Spell::EffectSendEvent(SpellEffIndex effIndex)
{
    /*
    we do not handle a flag dropping or clicking on flag in battleground by sendevent system
    */
    sLog.outDebug("Spell ScriptStart %u for spellid %u in EffectSendEvent ", m_spellInfo->EffectMiscValue[effIndex], m_spellInfo->Id);

    Object *pTarget;
    if (focusObject)
        pTarget = focusObject;
    else if (unitTarget)
        pTarget = unitTarget;
    else if (gameObjTarget)
        pTarget = gameObjTarget;
    else
        pTarget = NULL;

    m_caster->GetMap()->ScriptsStart(sEventScripts, m_spellInfo->EffectMiscValue[effIndex], m_caster, pTarget);
}

void Spell::EffectPowerBurn(SpellEffIndex effIndex)
{
    if (m_spellInfo->EffectMiscValue[effIndex] < 0 || m_spellInfo->EffectMiscValue[effIndex] >= int8(MAX_POWERS))
        return;

    Powers powerType = Powers(m_spellInfo->EffectMiscValue[effIndex]);

    if (!unitTarget || !unitTarget->isAlive() || unitTarget->getPowerType() != powerType || damage < 0)
        return;

    // burn x% of target's mana, up to maximum of 2x% of caster's mana (Mana Burn)
    if (m_spellInfo->ManaCostPercentage)
    {
        int32 maxDamage = m_caster->GetMaxPower(powerType) * damage * 2 / 100;
        damage = unitTarget->GetMaxPower(powerType) * damage / 100;
        damage = std::min(damage, maxDamage);
    }

    int32 power = damage;
    // resilience reduce mana draining effect at spell crit damage reduction (added in 2.4)
    if (powerType == POWER_MANA)
        power -= unitTarget->GetSpellCritDamageReduction(power);

    int32 newDamage = -(unitTarget->ModifyPower(powerType, -power));

    // NO - Not a typo - EffectPowerBurn uses effect value multiplier - not effect damage multiplier
    float dmgMultiplier = SpellMgr::CalculateSpellEffectValueMultiplier(m_spellInfo, effIndex, m_originalCaster, this);

    // add log data before multiplication (need power amount, not damage)
    ExecuteLogEffectTakeTargetPower(effIndex, unitTarget, powerType, newDamage, 0.0f);

    newDamage = int32(newDamage * dmgMultiplier);

    m_damage += newDamage;
}

void Spell::EffectHeal(SpellEffIndex /*effIndex*/)
{
}

void Spell::SpellDamageHeal(SpellEffIndex /*effIndex*/)
{
    if (unitTarget && unitTarget->isAlive() && damage >= 0)
    {
        // Try to get original caster
        Unit *caster = m_originalCasterGUID ? m_originalCaster : m_caster;

        // Skip if m_originalCaster not available
        if (!caster)
            return;

        int32 addhealth = damage;

        // Vessel of the Naaru (Vial of the Sunwell trinket)
        if (m_spellInfo->Id == 45064)
        {
            // Amount of heal - depends from stacked Holy Energy
            int damageAmount = 0;
            if (AuraEffect const * aurEff = m_caster->GetAuraEffect(45062, 0))
            {
                damageAmount+= aurEff->GetAmount();
                m_caster->RemoveAurasDueToSpell(45062);
            }

            addhealth += damageAmount;
        }
        // Swiftmend - consumes Regrowth or Rejuvenation
        else if (m_spellInfo->TargetAuraState == AURA_STATE_SWIFTMEND && unitTarget->HasAuraState(AURA_STATE_SWIFTMEND, m_spellInfo, m_caster))
        {
            Unit::AuraEffectList const& RejorRegr = unitTarget->GetAuraEffectsByType(SPELL_AURA_PERIODIC_HEAL);
            // find most short by duration
            AuraEffect *targetAura = NULL;
            for (Unit::AuraEffectList::const_iterator i = RejorRegr.begin(); i != RejorRegr.end(); ++i)
            {
                if ((*i)->GetSpellProto()->SpellFamilyName == SPELLFAMILY_DRUID
                    && (*i)->GetSpellProto()->SpellFamilyFlags[0] & 0x50)
                {
                    if (!targetAura || (*i)->GetBase()->GetDuration() < targetAura->GetBase()->GetDuration())
                        targetAura = *i;
                }
            }

            if (!targetAura)
            {
                sLog.outError("Target(GUID:" UI64FMTD ") has aurastate AURA_STATE_SWIFTMEND but no matching aura.", unitTarget->GetGUID());
                return;
            }

            int32 tickheal = targetAura->GetAmount();
            if (Unit* auraCaster = targetAura->GetCaster())
                tickheal = auraCaster->SpellHealingBonus(unitTarget, targetAura->GetSpellProto(), tickheal, DOT);
            //int32 tickheal = targetAura->GetSpellProto()->EffectBasePoints[idx] + 1;
            //It is said that talent bonus should not be included

            int32 tickcount = 0;
            // Rejuvenation
            if (targetAura->GetSpellProto()->SpellFamilyFlags[0] & 0x10)
                tickcount = 4;
            // Regrowth
            else // if (targetAura->GetSpellProto()->SpellFamilyFlags[0] & 0x40)
                tickcount = 6;

            addhealth += tickheal * tickcount;

            // Glyph of Swiftmend
            if (!caster->HasAura(54824))
                unitTarget->RemoveAura(targetAura->GetId(), targetAura->GetCasterGUID());

            //addhealth += tickheal * tickcount;
            //addhealth = caster->SpellHealingBonus(m_spellInfo, addhealth,HEAL, unitTarget);
        }
        // Glyph of Nourish
        else if (m_spellInfo->SpellFamilyName == SPELLFAMILY_DRUID && m_spellInfo->SpellFamilyFlags[1] & 0x2000000)
        {
            addhealth = caster->SpellHealingBonus(unitTarget, m_spellInfo, addhealth, HEAL);

            if (AuraEffect const* aurEff = m_caster->GetAuraEffect(62971, 0))
            {
                Unit::AuraEffectList const& Periodic = unitTarget->GetAuraEffectsByType(SPELL_AURA_PERIODIC_HEAL);
                for (Unit::AuraEffectList::const_iterator i = Periodic.begin(); i != Periodic.end(); ++i)
                {
                    if (m_caster->GetGUID() == (*i)->GetCasterGUID())
                        addhealth += addhealth * aurEff->GetAmount() / 100;
                }
            }
        }
        // Lifebloom - final heal coef multiplied by original DoT stack
        else if (m_spellInfo->Id == 33778)
            addhealth = caster->SpellHealingBonus(unitTarget, m_spellInfo, addhealth, HEAL, m_spellValue->EffectBasePoints[1]);
        // Riptide - increase healing done by Chain Heal
        else if (m_spellInfo->SpellFamilyName == SPELLFAMILY_SHAMAN && m_spellInfo->SpellFamilyFlags[0] & 0x100)
        {
            addhealth = caster->SpellHealingBonus(unitTarget, m_spellInfo, addhealth, HEAL);
            if (AuraEffect * aurEff = unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_HEAL, SPELLFAMILY_SHAMAN, 0, 0, 0x10, m_originalCasterGUID))
            {
                addhealth = int32(addhealth * 1.25f);
                // consume aura
                unitTarget->RemoveAura(aurEff->GetBase());
            }
        }
        // Death Pact - return pct of max health to caster
        else if (m_spellInfo->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT && m_spellInfo->SpellFamilyFlags[0] & 0x00080000)
            addhealth = caster->SpellHealingBonus(unitTarget, m_spellInfo, int32(caster->CountPctFromMaxHealth(damage)), HEAL);
        else
            addhealth = caster->SpellHealingBonus(unitTarget, m_spellInfo, addhealth, HEAL);

        // Remove Grievious bite if fully healed
        if (unitTarget->HasAura(48920) && (unitTarget->GetHealth() + addhealth >= unitTarget->GetMaxHealth()))
            unitTarget->RemoveAura(48920);

        m_damage -= addhealth;
    }
}

void Spell::EffectHealPct(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || !unitTarget->isAlive() || damage < 0)
        return;

    // Skip if m_originalCaster not available
    if (!m_originalCaster)
        return;

    // Rune Tap - Party
    if (m_spellInfo->Id == 59754 && unitTarget == m_caster)
        return;

    m_healing += m_originalCaster->SpellHealingBonus(unitTarget, m_spellInfo, unitTarget->CountPctFromMaxHealth(damage), HEAL);
}

void Spell::EffectHealMechanical(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || !unitTarget->isAlive() || damage < 0)
        return;

    // Skip if m_originalCaster not available
    if (!m_originalCaster)
        return;

    m_healing += m_originalCaster->SpellHealingBonus(unitTarget, m_spellInfo, uint32(damage), HEAL);
}

void Spell::EffectHealthLeech(SpellEffIndex effIndex)
{
    if (!unitTarget || !unitTarget->isAlive() || damage < 0)
        return;

    sLog.outDebug("HealthLeech :%i", damage);

    float healMultiplier = SpellMgr::CalculateSpellEffectValueMultiplier(m_spellInfo, effIndex, m_originalCaster, this);

    m_damage += damage;
    // get max possible damage, don't count overkill for heal
    uint32 healthGain = uint32(-unitTarget->GetHealthGain(-damage) * healMultiplier);

    if (m_caster->isAlive())
    {
        healthGain = m_caster->SpellHealingBonus(m_caster, m_spellInfo, healthGain, HEAL);
        m_caster->HealBySpell(m_caster, m_spellInfo, uint32(healthGain));
    }
}

void Spell::DoCreateItem(uint32 /*i*/, uint32 itemtype)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = (Player*)unitTarget;

    uint32 newitemid = itemtype;
    ItemPrototype const *pProto = sObjectMgr.GetItemPrototype(newitemid);
    if (!pProto)
    {
        player->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, NULL, NULL);
        return;
    }

    // bg reward have some special in code work
    uint32 bgType = 0;
    switch(m_spellInfo->Id)
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

    // init items_count to 1, since 1 item will be created regardless of specialization
    int items_count=1;
    // the chance to create additional items
    float additionalCreateChance=0.0f;
    // the maximum number of created additional items
    uint8 additionalMaxNum=0;
    // get the chance and maximum number for creating extra items
    if (canCreateExtraItems(player, m_spellInfo->Id, additionalCreateChance, additionalMaxNum))
    {
        // roll with this chance till we roll not to create or we create the max num
        while (roll_chance_f(additionalCreateChance) && items_count <= additionalMaxNum)
            ++items_count;
    }

    // really will be created more items
    num_to_add *= items_count;

    // can the player store the new item?
    ItemPosCountVec dest;
    uint32 no_space = 0;
    uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, newitemid, num_to_add, &no_space);
    if (msg != EQUIP_ERR_OK)
    {
        // convert to possible store amount
        if (msg == EQUIP_ERR_INVENTORY_FULL || msg == EQUIP_ERR_CANT_CARRY_MORE_OF_THIS)
            num_to_add -= no_space;
        else
        {
            // if not created by another reason from full inventory or unique items amount limitation
            player->SendEquipError(msg, NULL, NULL, newitemid);
            return;
        }
    }

    if (num_to_add)
    {
        // create the new item and store it
        Item* pItem = player->StoreNewItem(dest, newitemid, true, Item::GenerateItemRandomPropertyId(newitemid));

        // was it successful? return error if not
        if (!pItem)
        {
            player->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, NULL, NULL);
            return;
        }

        // set the "Crafted by ..." property of the item
        if (pItem->GetProto()->Class != ITEM_CLASS_CONSUMABLE && pItem->GetProto()->Class != ITEM_CLASS_QUEST && newitemid != 6265 && newitemid != 6948)
            pItem->SetUInt32Value(ITEM_FIELD_CREATOR, player->GetGUIDLow());

        // send info to the client
        if (pItem)
            player->SendNewItem(pItem, num_to_add, true, bgType == 0);

        // we succeeded in creating at least one item, so a levelup is possible
        if (bgType == 0)
            player->UpdateCraftSkill(m_spellInfo->Id);
    }

/*
    // for battleground marks send by mail if not add all expected
    if (no_space > 0 && bgType)
    {
        if (Battleground* bg = sBattlegroundMgr.GetBattlegroundTemplate(BattlegroundTypeId(bgType)))
            bg->SendRewardMarkByMail(player, newitemid, no_space);
    }
*/
}

void Spell::EffectCreateItem(SpellEffIndex effIndex)
{
    DoCreateItem(effIndex,m_spellInfo->EffectItemType[effIndex]);
    ExecuteLogEffectCreateItem(effIndex, m_spellInfo->EffectItemType[effIndex]);
}

void Spell::EffectCreateItem2(SpellEffIndex effIndex)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;
    Player* player = (Player*)m_caster;

    uint32 item_id = m_spellInfo->EffectItemType[effIndex];

    if (item_id)
        DoCreateItem(effIndex, item_id);

    // special case: fake item replaced by generate using spell_loot_template
    if (IsLootCraftingSpell(m_spellInfo))
    {
        if (item_id)
        {
            if (!player->HasItemCount(item_id, 1))
                return;

            // remove reagent
            uint32 count = 1;
            player->DestroyItemCount(item_id, count, true);

            // create some random items
            player->AutoStoreLoot(m_spellInfo->Id, LootTemplates_Spell);
        }
        else
            player->AutoStoreLoot(m_spellInfo->Id, LootTemplates_Spell);    // create some random items
    }
    // TODO: ExecuteLogEffectCreateItem(i, m_spellInfo->EffectItemType[i]);
}

void Spell::EffectCreateRandomItem(SpellEffIndex /*effIndex*/)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;
    Player* player = (Player*)m_caster;

    // create some random items
    player->AutoStoreLoot(m_spellInfo->Id, LootTemplates_Spell);
    // TODO: ExecuteLogEffectCreateItem(i, m_spellInfo->EffectItemType[i]);
}

void Spell::EffectPersistentAA(SpellEffIndex effIndex)
{
    if (!m_spellAura)
    {
        float radius = GetSpellRadiusForFriend(sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[effIndex]));
        if (Player* modOwner = m_originalCaster->GetSpellModOwner())
            modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_RADIUS, radius);

        Unit *caster = m_caster->GetEntry() == WORLD_TRIGGER ? m_originalCaster : m_caster;
        // Caster not in world, might be spell triggered from aura removal
        if (!caster->IsInWorld())
            return;
        DynamicObject* dynObj = new DynamicObject;
        if (!dynObj->Create(sObjectMgr.GenerateLowGuid(HIGHGUID_DYNAMICOBJECT), caster, m_spellInfo->Id, m_targets.m_dstPos, radius, false))
        {
            delete dynObj;
            return;
        }
        caster->AddDynObject(dynObj);
        dynObj->GetMap()->Add(dynObj);

        if (Aura * aura = Aura::TryCreate(m_spellInfo, dynObj, caster, &m_spellValue->EffectBasePoints[0]))
            m_spellAura = aura;
        else
        {
            ASSERT(false);
            return;
        }
        m_spellAura->_RegisterForTargets();
    }
    ASSERT(m_spellAura->GetDynobjOwner());
    m_spellAura->_ApplyEffectForTargets(effIndex);
}

void Spell::EffectEnergize(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;
    if (!unitTarget->isAlive())
        return;

    if (m_spellInfo->EffectMiscValue[effIndex] < 0 || m_spellInfo->EffectMiscValue[effIndex] >= int8(MAX_POWERS))
        return;

    Powers power = Powers(m_spellInfo->EffectMiscValue[effIndex]);

    // Some level depends spells
    int level_multiplier = 0;
    int level_diff = 0;
    switch (m_spellInfo->Id)
    {
        case 9512:                                          // Restore Energy
            level_diff = m_caster->getLevel() - 40;
            level_multiplier = 2;
            break;
        case 24571:                                         // Blood Fury
            level_diff = m_caster->getLevel() - 60;
            level_multiplier = 10;
            break;
        case 24532:                                         // Burst of Energy
            level_diff = m_caster->getLevel() - 60;
            level_multiplier = 4;
            break;
        case 31930:                                         // Judgements of the Wise
        case 63375:                                         // Improved Stormstrike
        case 68082:                                         // Glyph of Seal of Command
            damage = damage * unitTarget->GetCreateMana() / 100;
            break;
        case 48542:                                         // Revitalize
            damage = damage * unitTarget->GetMaxPower(power) / 100;
            break;
        default:
            break;
    }

    if (level_diff > 0)
        damage -= level_multiplier * level_diff;

    if (damage < 0)
        return;

    if (unitTarget->GetMaxPower(power) == 0)
        return;

    m_caster->EnergizeBySpell(unitTarget, m_spellInfo->Id, damage, power);

    // Mad Alchemist's Potion
    if (m_spellInfo->Id == 45051)
    {
        // find elixirs on target
        bool guardianFound = false;
        bool battleFound = false;
        Unit::AuraApplicationMap& Auras = unitTarget->GetAppliedAuras();
        for (Unit::AuraApplicationMap::iterator itr = Auras.begin(); itr != Auras.end(); ++itr)
        {
            uint32 spell_id = itr->second->GetBase()->GetId();
            if (!guardianFound)
                if (sSpellMgr.IsSpellMemberOfSpellGroup(spell_id, SPELL_GROUP_ELIXIR_GUARDIAN))
                    guardianFound = true;
            if (!battleFound)
                if (sSpellMgr.IsSpellMemberOfSpellGroup(spell_id, SPELL_GROUP_ELIXIR_BATTLE))
                    battleFound = true;
            if (battleFound && guardianFound)
                break;
        }

        // get all available elixirs by mask and spell level
        std::set<uint32> avalibleElixirs;
        if (!guardianFound)
            sSpellMgr.GetSetOfSpellsInSpellGroup(SPELL_GROUP_ELIXIR_GUARDIAN, avalibleElixirs);
        if (!battleFound)
            sSpellMgr.GetSetOfSpellsInSpellGroup(SPELL_GROUP_ELIXIR_BATTLE, avalibleElixirs);
        for (std::set<uint32>::iterator itr = avalibleElixirs.begin(); itr != avalibleElixirs.end() ;)
        {
            SpellEntry const *spellInfo = sSpellStore.LookupEntry(*itr);
            if (spellInfo->spellLevel < m_spellInfo->spellLevel || spellInfo->spellLevel > unitTarget->getLevel())
                avalibleElixirs.erase(itr++);
            else if (sSpellMgr.IsSpellMemberOfSpellGroup(*itr, SPELL_GROUP_ELIXIR_SHATTRATH))
                avalibleElixirs.erase(itr++);
            else if (sSpellMgr.IsSpellMemberOfSpellGroup(*itr, SPELL_GROUP_ELIXIR_UNSTABLE))
                avalibleElixirs.erase(itr++);
            else
                ++itr;
        }

        if (!avalibleElixirs.empty())
        {
            // cast random elixir on target
            uint32 rand_spell = urand(0,avalibleElixirs.size()-1);
            std::set<uint32>::iterator itr = avalibleElixirs.begin();
            std::advance(itr, rand_spell);
            m_caster->CastSpell(unitTarget,*itr,true,m_CastItem);
        }
    }
}

void Spell::EffectEnergizePct(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;
    if (!unitTarget->isAlive())
        return;

    if (m_spellInfo->EffectMiscValue[effIndex] < 0 || m_spellInfo->EffectMiscValue[effIndex] >= int8(MAX_POWERS))
        return;

    Powers power = Powers(m_spellInfo->EffectMiscValue[effIndex]);

    uint32 maxPower = unitTarget->GetMaxPower(power);
    if (maxPower == 0)
        return;

    uint32 gain = damage * maxPower / 100;
    m_caster->EnergizeBySpell(unitTarget, m_spellInfo->Id, gain, power);
}

void Spell::SendLoot(uint64 guid, LootType loottype)
{
    Player* player = (Player*)m_caster;
    if (!player)
        return;

    if (gameObjTarget)
    {
        if (sScriptMgr.OnGossipHello(player, gameObjTarget))
            return;

        gameObjTarget->AI()->GossipHello(player);

        switch (gameObjTarget->GetGoType())
        {
            case GAMEOBJECT_TYPE_DOOR:
            case GAMEOBJECT_TYPE_BUTTON:
                gameObjTarget->UseDoorOrButton();
                player->GetMap()->ScriptsStart(sGameObjectScripts, gameObjTarget->GetDBTableGUIDLow(), player, gameObjTarget);
                return;

            case GAMEOBJECT_TYPE_QUESTGIVER:
                // start or end quest
                player->PrepareQuestMenu(guid);
                player->SendPreparedQuest(guid);
                return;

            case GAMEOBJECT_TYPE_SPELL_FOCUS:
                // triggering linked GO
                if (uint32 trapEntry = gameObjTarget->GetGOInfo()->spellFocus.linkedTrapId)
                    gameObjTarget->TriggeringLinkedGameObject(trapEntry,m_caster);
                return;

            case GAMEOBJECT_TYPE_GOOBER:
                gameObjTarget->Use(m_caster);
                return;

            case GAMEOBJECT_TYPE_CHEST:
                // TODO: possible must be moved to loot release (in different from linked triggering)
                if (gameObjTarget->GetGOInfo()->chest.eventId)
                {
                    sLog.outDebug("Chest ScriptStart id %u for GO %u", gameObjTarget->GetGOInfo()->chest.eventId,gameObjTarget->GetDBTableGUIDLow());
                    player->GetMap()->ScriptsStart(sEventScripts, gameObjTarget->GetGOInfo()->chest.eventId, player, gameObjTarget);
                }

                // triggering linked GO
                if (uint32 trapEntry = gameObjTarget->GetGOInfo()->chest.linkedTrapId)
                    gameObjTarget->TriggeringLinkedGameObject(trapEntry,m_caster);

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
    if (!m_caster || m_caster->GetTypeId() != TYPEID_PLAYER)
    {
        sLog.outDebug("WORLD: Open Lock - No Player Caster!");
        return;
    }

    Player* player = (Player*)m_caster;

    uint32 lockId = 0;
    uint64 guid = 0;

    // Get lockId
    if (gameObjTarget)
    {
        GameObjectInfo const* goInfo = gameObjTarget->GetGOInfo();
        // Arathi Basin banner opening !
        if ((goInfo->type == GAMEOBJECT_TYPE_BUTTON && goInfo->button.noDamageImmune) ||
            (goInfo->type == GAMEOBJECT_TYPE_GOOBER && goInfo->goober.losOK))
        {
            //CanUseBattlegroundObject() already called in CheckCast()
            // in battleground check
            if (Battleground *bg = player->GetBattleground())
          {
        bg->EventPlayerClickedOnFlag(player, gameObjTarget);
        return;
          }
        }
        else if (goInfo->type == GAMEOBJECT_TYPE_FLAGSTAND)
        {
            //CanUseBattlegroundObject() already called in CheckCast()
            // in battleground check
            if (Battleground *bg = player->GetBattleground())
            {
                if (bg->GetTypeID(true) == BATTLEGROUND_EY)
                    bg->EventPlayerClickedOnFlag(player, gameObjTarget);
                return;
            }
        }else if (m_spellInfo->Id == 1842 && gameObjTarget->GetGOInfo()->type == GAMEOBJECT_TYPE_TRAP && gameObjTarget->GetOwner())
        {
            gameObjTarget->SetLootState(GO_JUST_DEACTIVATED);
            return;
        }
        // TODO: Add script for spell 41920 - Filling, becouse server it freze when use this spell
        // handle outdoor pvp object opening, return true if go was registered for handling
        // these objects must have been spawned by outdoorpvp!
        else if (gameObjTarget->GetGOInfo()->type == GAMEOBJECT_TYPE_GOOBER && sOutdoorPvPMgr.HandleOpenGo(player, gameObjTarget->GetGUID()))
            return;
        lockId = goInfo->GetLockId();
        guid = gameObjTarget->GetGUID();
    }
    else if (itemTarget)
    {
        lockId = itemTarget->GetProto()->LockID;
        guid = itemTarget->GetGUID();
    }
    else
    {
        sLog.outDebug("WORLD: Open Lock - No GameObject/Item Target!");
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
    else
        itemTarget->SetFlag(ITEM_FIELD_FLAGS, ITEM_FLAG_UNLOCKED);

    // not allow use skill grow at item base open
    if (!m_CastItem && skillId != SKILL_NONE)
    {
        // update skill if really known
        if (uint32 pureSkillValue = player->GetPureSkillValue(skillId))
        {
            if (gameObjTarget)
            {
                // Allow one skill-up until respawned
                if (!gameObjTarget->IsInSkillupList(player->GetGUIDLow()) &&
                    player->UpdateGatherSkill(skillId, pureSkillValue, reqSkillValue))
                    gameObjTarget->AddToSkillupList(player->GetGUIDLow());
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
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player *player = (Player*)m_caster;

    // applied only to using item
    if (!m_CastItem)
        return;

    // ... only to item in own inventory/bank/equip_slot
    if (m_CastItem->GetOwnerGUID() != player->GetGUID())
        return;

    uint32 newitemid = m_spellInfo->EffectItemType[effIndex];
    if (!newitemid)
        return;

    uint16 pos = m_CastItem->GetPos();

    Item *pNewItem = Item::CreateItem(newitemid, 1, player);
    if (!pNewItem)
        return;

    for (uint8 j = PERM_ENCHANTMENT_SLOT; j <= TEMP_ENCHANTMENT_SLOT; ++j)
        if (m_CastItem->GetEnchantmentId(EnchantmentSlot(j)))
            pNewItem->SetEnchantment(EnchantmentSlot(j), m_CastItem->GetEnchantmentId(EnchantmentSlot(j)), m_CastItem->GetEnchantmentDuration(EnchantmentSlot(j)), m_CastItem->GetEnchantmentCharges(EnchantmentSlot(j)));

    if (m_CastItem->GetUInt32Value(ITEM_FIELD_DURABILITY) < m_CastItem->GetUInt32Value(ITEM_FIELD_MAXDURABILITY))
    {
        double loosePercent = 1 - m_CastItem->GetUInt32Value(ITEM_FIELD_DURABILITY) / double(m_CastItem->GetUInt32Value(ITEM_FIELD_MAXDURABILITY));
        player->DurabilityLoss(pNewItem, loosePercent);
    }

    if (player->IsInventoryPos(pos))
    {
        ItemPosCountVec dest;
        uint8 msg = player->CanStoreItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), dest, pNewItem, true);
        if (msg == EQUIP_ERR_OK)
        {
            player->DestroyItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), true);

            // prevent crash at access and unexpected charges counting with item update queue corrupt
            if (m_CastItem == m_targets.getItemTarget())
                m_targets.setItemTarget(NULL);

            m_CastItem = NULL;

            player->StoreItem(dest, pNewItem, true);
            return;
        }
    }
    else if (player->IsBankPos(pos))
    {
        ItemPosCountVec dest;
        uint8 msg = player->CanBankItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), dest, pNewItem, true);
        if (msg == EQUIP_ERR_OK)
        {
            player->DestroyItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), true);

            // prevent crash at access and unexpected charges counting with item update queue corrupt
            if (m_CastItem == m_targets.getItemTarget())
                m_targets.setItemTarget(NULL);

            m_CastItem = NULL;

            player->BankItem(dest, pNewItem, true);
            return;
        }
    }
    else if (player->IsEquipmentPos(pos))
    {
        uint16 dest;

        player->DestroyItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), true);

        uint8 msg = player->CanEquipItem(m_CastItem->GetSlot(), dest, pNewItem, true);

        if (msg == EQUIP_ERR_OK || msg == EQUIP_ERR_CANT_DO_RIGHT_NOW)
        {
            if (msg == EQUIP_ERR_CANT_DO_RIGHT_NOW) dest = EQUIPMENT_SLOT_MAINHAND;

            // prevent crash at access and unexpected charges counting with item update queue corrupt
            if (m_CastItem == m_targets.getItemTarget())
                m_targets.setItemTarget(NULL);

            m_CastItem = NULL;

            player->EquipItem(dest, pNewItem, true);
            player->AutoUnequipOffhandIfNeed();
            return;
        }
    }

    // fail
    delete pNewItem;
}

void Spell::EffectProficiency(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    Player *p_target = (Player*)unitTarget;

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
    uint32 entry = m_spellInfo->EffectMiscValue[effIndex];
    if (!entry)
        return;

    SummonPropertiesEntry const *properties = sSummonPropertiesStore.LookupEntry(m_spellInfo->EffectMiscValueB[effIndex]);
    if (!properties)
    {
        sLog.outError("EffectSummonType: Unhandled summon type %u", m_spellInfo->EffectMiscValueB[effIndex]);
        return;
    }

    if (!m_originalCaster)
        return;

    int32 duration = GetSpellDuration(m_spellInfo);
    if (Player* modOwner = m_originalCaster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_DURATION, duration);

    Position pos;
    GetSummonPosition(effIndex, pos);

    /*//totem must be at same Z in case swimming caster and etc.
        if (fabs(z - m_caster->GetPositionZ()) > 5)
            z = m_caster->GetPositionZ();

    uint8 level = m_caster->getLevel();

    // level of creature summoned using engineering item based at engineering skill level
    if (m_caster->GetTypeId() == TYPEID_PLAYER && m_CastItem)
    {
        ItemPrototype const *proto = m_CastItem->GetProto();
        if (proto && proto->RequiredSkill == SKILL_ENGINERING)
        {
            uint16 skill202 = m_caster->ToPlayer()->GetSkillValue(SKILL_ENGINERING);
            if (skill202)
                level = skill202/5;
        }
    }*/

    TempSummon *summon = NULL;

    switch (properties->Category)
    {
        default:
            if (properties->Flags & 512)
            {
                SummonGuardian(effIndex, entry, properties);
                break;
            }
            switch (properties->Type)
            {
                case SUMMON_TYPE_PET:
                case SUMMON_TYPE_GUARDIAN:
                case SUMMON_TYPE_GUARDIAN2:
                case SUMMON_TYPE_MINION:
                    SummonGuardian(effIndex, entry, properties);
                    break;
                case SUMMON_TYPE_VEHICLE:
                case SUMMON_TYPE_VEHICLE2:
                    if (m_originalCaster)
                        summon = m_caster->GetMap()->SummonCreature(entry, pos, properties, duration, m_originalCaster);
                    break;
                case SUMMON_TYPE_TOTEM:
                {
                    summon = m_caster->GetMap()->SummonCreature(entry, pos, properties, duration, m_originalCaster);
                    if (!summon || !summon->isTotem())
                        return;

                    if (damage)                                            // if not spell info, DB values used
                    {
                        summon->SetMaxHealth(damage);
                        summon->SetHealth(damage);
                    }

                    //summon->SetUInt32Value(UNIT_CREATED_BY_SPELL,m_spellInfo->Id);

                    if (m_originalCaster->GetTypeId() == TYPEID_PLAYER
                        && properties->Slot >= SUMMON_SLOT_TOTEM
                        && properties->Slot < MAX_TOTEM_SLOT)
                    {
                        // set display id depending on race
                        uint32 displayId = m_originalCaster->GetModelForTotem(PlayerTotemType(properties->Id));
                        summon->SetNativeDisplayId(displayId);
                        summon->SetDisplayId(displayId);

                        //summon->SendUpdateToPlayerm_originalCaster->ToPlayer();
                        WorldPacket data(SMSG_TOTEM_CREATED, 1+8+4+4);
                        data << uint8(properties->Slot-1);
                        data << uint64(m_originalCaster->GetGUID());
                        data << uint32(duration);
                        data << uint32(m_spellInfo->Id);
                        m_originalCaster->ToPlayer()->SendDirectMessage(&data);
                    }
                    break;
                }
                case SUMMON_TYPE_MINIPET:
                {
                    summon = m_caster->GetMap()->SummonCreature(entry, pos, properties, duration, m_originalCaster);
                    if (!summon || !summon->HasUnitTypeMask(UNIT_MASK_MINION))
                        return;

                    //summon->InitPetCreateSpells();                         // e.g. disgusting oozeling has a create spell as summon...
                    summon->SelectLevel(summon->GetCreatureInfo());       // some summoned creaters have different from 1 DB data for level/hp
                    summon->SetUInt32Value(UNIT_NPC_FLAGS, summon->GetCreatureInfo()->npcflag);

                    summon->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);

                    summon->AI()->EnterEvadeMode();

                    std::string name = m_originalCaster->GetName();
                    name.append(petTypeSuffix[3]);
                    summon->SetName(name);
                    break;
                }
                default:
                {
                    float radius = GetSpellRadiusForHostile(sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[effIndex]));

                    uint32 amount = damage > 0 ? damage : 1;
                    if (m_spellInfo->Id == 18662) // Curse of Doom
                        amount = 1;

                    for (uint32 count = 0; count < amount; ++count)
                    {
                        GetSummonPosition(effIndex, pos, radius, count);

                        TempSummonType summonType = (duration == 0) ? TEMPSUMMON_DEAD_DESPAWN : TEMPSUMMON_TIMED_DESPAWN;

                        summon = m_originalCaster->SummonCreature(entry, pos, summonType, duration);
                        if (!summon)
                            continue;
                        if (properties->Category == SUMMON_CATEGORY_ALLY)
                        {
                            summon->SetUInt64Value(UNIT_FIELD_SUMMONEDBY, m_originalCaster->GetGUID());
                            summon->setFaction(m_originalCaster->getFaction());
                            summon->SetUInt32Value(UNIT_CREATED_BY_SPELL, m_spellInfo->Id);
                        }
                        ExecuteLogEffectSummonObject(effIndex, summon);
                    }
                    return;
                }
            }//switch
            break;
        case SUMMON_CATEGORY_PET:
            SummonGuardian(effIndex, entry, properties);
            break;
        case SUMMON_CATEGORY_PUPPET:
            summon = m_caster->GetMap()->SummonCreature(entry, pos, properties, duration, m_originalCaster);
            break;
        case SUMMON_CATEGORY_VEHICLE:
        {
            float x, y, z;
            m_caster->GetClosePoint(x, y, z, DEFAULT_WORLD_OBJECT_SIZE);
            summon = m_caster->GetMap()->SummonCreature(entry, pos, properties, duration, m_caster);
            if (!summon || !summon->IsVehicle())
                return;

            if (m_spellInfo->EffectBasePoints[effIndex])
            {
                SpellEntry const *spellProto = sSpellStore.LookupEntry(SpellMgr::CalculateSpellEffectAmount(m_spellInfo, effIndex));
                if (spellProto)
                    m_caster->CastSpell(summon, spellProto, true);
            }

            m_caster->EnterVehicle(summon->GetVehicleKit());
            break;
        }
    }

    if (summon)
    {
        summon->SetUInt32Value(UNIT_CREATED_BY_SPELL, m_spellInfo->Id);
        summon->SetCreatorGUID(m_originalCaster->GetGUID());
        ExecuteLogEffectSummonObject(effIndex, summon);
    }
}

void Spell::EffectLearnSpell(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;

    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
    {
        if (m_caster->GetTypeId() == TYPEID_PLAYER)
            EffectLearnPetSpell(effIndex);

        return;
    }

    Player *player = (Player*)unitTarget;

    uint32 spellToLearn = (m_spellInfo->Id == 483 || m_spellInfo->Id == 55884) ? damage : m_spellInfo->EffectTriggerSpell[effIndex];
    player->learnSpell(spellToLearn, false);

    sLog.outDebug("Spell: Player %u has learned spell %u from NpcGUID=%u", player->GetGUIDLow(), spellToLearn, m_caster->GetGUIDLow());
}

typedef std::list< std::pair<uint32, uint64> > DispelList;
typedef std::list< std::pair<Aura *, uint8> > DispelChargesList;
void Spell::EffectDispel(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;

    DispelChargesList dispel_list;

    // Create dispel mask by dispel type
    uint32 dispel_type = m_spellInfo->EffectMiscValue[effIndex];
    uint32 dispelMask  = GetDispellMask(DispelType(dispel_type));

    // we should not be able to dispel diseases if the target is affected by unholy blight
    if (dispelMask & (1 << DISPEL_DISEASE) && unitTarget->HasAura(50536))
        dispelMask &= ~(1 << DISPEL_DISEASE);

    Unit::AuraMap const& auras = unitTarget->GetOwnedAuras();
    for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
    {
        Aura * aura = itr->second;
        AuraApplication * aurApp = aura->GetApplicationOfTarget(unitTarget->GetGUID());
        if (!aurApp)
            continue;

        if ((1<<aura->GetSpellProto()->Dispel) & dispelMask)
        {
            if (aura->GetSpellProto()->Dispel == DISPEL_MAGIC)
            {
                bool positive = aurApp->IsPositive() ? (!(aura->GetSpellProto()->AttributesEx & SPELL_ATTR_EX_NEGATIVE)) : false;

                // do not remove positive auras if friendly target
                //               negative auras if non-friendly target
                if (positive == unitTarget->IsFriendlyTo(m_caster))
                    continue;
            }

            // The charges / stack amounts don't count towards the total number of auras that can be dispelled.
            // Ie: A dispel on a target with 5 stacks of Winters Chill and a Polymorph has 1 / (1 + 1) -> 50% chance to dispell
            // Polymorph instead of 1 / (5 + 1) -> 16%.
            bool dispel_charges = aura->GetSpellProto()->AttributesEx7 & SPELL_ATTR_EX7_DISPEL_CHARGES;
            uint8 charges = dispel_charges ? aura->GetCharges() : aura->GetStackAmount();
            if (charges > 0)
                dispel_list.push_back(std::make_pair(aura, charges));
        }
    }

    if (dispel_list.empty())
        return;

    // Ok if exist some buffs for dispel try dispel it
    uint32 failCount = 0;
    DispelList success_list;
    WorldPacket dataFail(SMSG_DISPEL_FAILED, 8+8+4+4+damage*4);
    // dispel N = damage buffs (or while exist buffs for dispel)
    for (int32 count = 0; count < damage && !dispel_list.empty();)
    {
        // Random select buff for dispel
        DispelChargesList::iterator itr = dispel_list.begin();
        std::advance(itr, urand(0, dispel_list.size() - 1));

        bool success = false;
        // 2.4.3 Patch Notes: "Dispel effects will no longer attempt to remove effects that have 100% dispel resistance."
        if (!GetDispelChance(itr->first->GetCaster(), unitTarget, itr->first->GetId(), !unitTarget->IsFriendlyTo(m_caster), &success))
        {
            dispel_list.erase(itr);
            continue;
        }
        else
        {
            if (success)
            {
                success_list.push_back(std::make_pair(itr->first->GetId(), itr->first->GetCasterGUID()));
                --itr->second;
                if (itr->second <= 0)
                    dispel_list.erase(itr);
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
                dataFail << uint32(itr->first->GetId());                         // Spell Id
            }
            ++count;
        }
    }

    if (failCount)
        m_caster->SendMessageToSet(&dataFail, true);

    if (success_list.empty())
        return;

    WorldPacket dataSuccess(SMSG_SPELLDISPELLOG, 8+8+4+1+4+damage*5);
    // Send packet header
    dataSuccess.append(unitTarget->GetPackGUID());         // Victim GUID
    dataSuccess.append(m_caster->GetPackGUID());           // Caster GUID
    dataSuccess << uint32(m_spellInfo->Id);                // dispel spell id
    dataSuccess << uint8(0);                               // not used
    dataSuccess << uint32(success_list.size());            // count
    for (DispelList::iterator itr = success_list.begin(); itr != success_list.end(); ++itr)
    {
        // Send dispelled spell info
        dataSuccess << uint32(itr->first);              // Spell Id
        dataSuccess << uint8(0);                        // 0 - dispelled !=0 cleansed
        unitTarget->RemoveAurasDueToSpellByDispel(itr->first, itr->second, m_caster);
    }
    m_caster->SendMessageToSet(&dataSuccess, true);

    // On success dispel
    // Devour Magic
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_WARLOCK && m_spellInfo->Category == SPELLCATEGORY_DEVOUR_MAGIC)
    {
        int32 heal_amount = SpellMgr::CalculateSpellEffectAmount(m_spellInfo, 1);
        m_caster->CastCustomSpell(m_caster, 19658, &heal_amount, NULL, NULL, true);
    }
}

void Spell::EffectDualWield(SpellEffIndex /*effIndex*/)
{
    unitTarget->SetCanDualWield(true);
    if (unitTarget->GetTypeId() == TYPEID_UNIT)
        unitTarget->ToCreature()->UpdateDamagePhysical(OFF_ATTACK);
}

void Spell::EffectPull(SpellEffIndex /*effIndex*/)
{
    // TODO: create a proper pull towards distract spell center for distract
    sLog.outDebug("WORLD: Spell Effect DUMMY");
}

void Spell::EffectDistract(SpellEffIndex /*effIndex*/)
{
    // Check for possible target
    if (!unitTarget || unitTarget->isInCombat())
        return;

    // target must be OK to do this
    if (unitTarget->hasUnitState(UNIT_STAT_CONFUSED | UNIT_STAT_STUNNED | UNIT_STAT_FLEEING))
        return;

    float angle = unitTarget->GetAngle(&m_targets.m_dstPos);

    if (unitTarget->GetTypeId() == TYPEID_PLAYER)
    {
        // For players just turn them
        unitTarget->ToPlayer()->SetPosition(unitTarget->GetPositionX(), unitTarget->GetPositionY(), unitTarget->GetPositionZ(), angle, false);
        unitTarget->ToPlayer()->SendTeleportAckPacket();
    }
    else
    {
        // Set creature Distracted, Stop it, And turn it
        unitTarget->SetOrientation(angle);
        unitTarget->StopMoving();
        unitTarget->GetMotionMaster()->MoveDistract(damage * IN_MILLISECONDS);
    }
}

void Spell::EffectPickPocket(SpellEffIndex /*effIndex*/)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    // victim must be creature and attackable
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_UNIT || m_caster->IsFriendlyTo(unitTarget))
        return;

    // victim have to be alive and humanoid or undead
    if (unitTarget->isAlive() && (unitTarget->GetCreatureTypeMask() &CREATURE_TYPEMASK_HUMANOID_OR_UNDEAD) != 0)
        m_caster->ToPlayer()->SendLoot(unitTarget->GetGUID(),LOOT_PICKPOCKETING);
}

void Spell::EffectAddFarsight(SpellEffIndex effIndex)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    float radius = GetSpellRadiusForFriend(sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[effIndex]));
    int32 duration = GetSpellDuration(m_spellInfo);
    // Caster not in world, might be spell triggered from aura removal
    if (!m_caster->IsInWorld())
        return;
    DynamicObject* dynObj = new DynamicObject;
    if (!dynObj->Create(sObjectMgr.GenerateLowGuid(HIGHGUID_DYNAMICOBJECT), m_caster, m_spellInfo->Id, m_targets.m_dstPos, radius, true))
    {
        delete dynObj;
        return;
    }
    dynObj->SetDuration(duration);
    dynObj->SetUInt32Value(DYNAMICOBJECT_BYTES, 0x80000002);
    m_caster->AddDynObject(dynObj);

    dynObj->setActive(true);    //must before add to map to be put in world container
    dynObj->GetMap()->Add(dynObj); //grid will also be loaded

    // Need to update visibility of object for client to accept farsight guid
    m_caster->ToPlayer()->SetViewpoint(dynObj, true);
    //m_caster->ToPlayer()->UpdateVisibilityOf(dynObj);
}

void Spell::EffectTeleUnitsFaceCaster(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;

    if (unitTarget->isInFlight())
        return;

    float dis = (float)m_caster->GetSpellRadiusForTarget(unitTarget, sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[effIndex]));

    float fx,fy,fz;
    m_caster->GetClosePoint(fx,fy,fz,unitTarget->GetObjectSize(),dis);

    unitTarget->NearTeleportTo(fx,fy,fz,-m_caster->GetOrientation(),unitTarget == m_caster);
}

void Spell::EffectLearnSkill(SpellEffIndex effIndex)
{
    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (damage < 0)
        return;

    uint32 skillid =  m_spellInfo->EffectMiscValue[effIndex];
    uint16 skillval = unitTarget->ToPlayer()->GetPureSkillValue(skillid);
    unitTarget->ToPlayer()->SetSkill(skillid, SpellMgr::CalculateSpellEffectAmount(m_spellInfo, effIndex), skillval?skillval:1, damage*75);
}

void Spell::EffectAddHonor(SpellEffIndex /*effIndex*/)
{
    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    // not scale value for item based reward (/10 value expected)
    if (m_CastItem)
    {
        unitTarget->ToPlayer()->RewardHonor(NULL, 1, damage/10);
        sLog.outDebug("SpellEffect::AddHonor (spell_id %u) rewards %d honor points (item %u) for player: %u", m_spellInfo->Id, damage/10, m_CastItem->GetEntry(),unitTarget->ToPlayer()->GetGUIDLow());
        return;
    }

    // do not allow to add too many honor for player (50 * 21) = 1040 at level 70, or (50 * 31) = 1550 at level 80
    if (damage <= 50)
    {
        uint32 honor_reward = Trinity::Honor::hk_honor_at_level(unitTarget->getLevel(), damage);
        unitTarget->ToPlayer()->RewardHonor(NULL, 1, honor_reward);
        sLog.outDebug("SpellEffect::AddHonor (spell_id %u) rewards %u honor points (scale) to player: %u", m_spellInfo->Id, honor_reward, unitTarget->ToPlayer()->GetGUIDLow());
    }
    else
    {
        //maybe we have correct honor_gain in damage already
        unitTarget->ToPlayer()->RewardHonor(NULL, 1, damage);
        sLog.outDebug("SpellEffect::AddHonor (spell_id %u) rewards %u honor points (non scale) for player: %u", m_spellInfo->Id, damage, unitTarget->ToPlayer()->GetGUIDLow());
    }
}

void Spell::EffectTradeSkill(SpellEffIndex /*effIndex*/)
{
    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    // uint32 skillid =  m_spellInfo->EffectMiscValue[i];
    // uint16 skillmax = unitTarget->ToPlayer()->(skillid);
    // unitTarget->ToPlayer()->SetSkill(skillid,skillval?skillval:1,skillmax+75);
}

void Spell::EffectEnchantItemPerm(SpellEffIndex effIndex)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;
    if (!itemTarget)
        return;

    Player* p_caster = (Player*)m_caster;

    // Handle vellums
    if (itemTarget->IsWeaponVellum() || itemTarget->IsArmorVellum())
    {
        // destroy one vellum from stack
        uint32 count = 1;
        p_caster->DestroyItemCount(itemTarget,count,true);
        unitTarget=p_caster;
        // and add a scroll
        DoCreateItem(effIndex,m_spellInfo->EffectItemType[effIndex]);
        itemTarget=NULL;
        m_targets.setItemTarget(NULL);
    }
    else
    {
        // do not increase skill if vellum used
        if (!(m_CastItem && m_CastItem->GetProto()->Flags & ITEM_PROTO_FLAG_TRIGGERED_CAST))
            p_caster->UpdateCraftSkill(m_spellInfo->Id);

        uint32 enchant_id = m_spellInfo->EffectMiscValue[effIndex];
        if (!enchant_id)
            return;

        SpellItemEnchantmentEntry const *pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!pEnchant)
            return;

        // item can be in trade slot and have owner diff. from caster
        Player* item_owner = itemTarget->GetOwner();
        if (!item_owner)
            return;

        if (item_owner != p_caster && p_caster->GetSession()->GetSecurity() > SEC_PLAYER && sWorld.getBoolConfig(CONFIG_GM_LOG_TRADE))
        {
            sLog.outCommand(p_caster->GetSession()->GetAccountId(),"GM %s (Account: %u) enchanting(perm): %s (Entry: %d) for player: %s (Account: %u)",
                p_caster->GetName(),p_caster->GetSession()->GetAccountId(),
                itemTarget->GetProto()->Name1,itemTarget->GetEntry(),
                item_owner->GetName(),item_owner->GetSession()->GetAccountId());
        }

        // remove old enchanting before applying new if equipped
        item_owner->ApplyEnchantment(itemTarget,PERM_ENCHANTMENT_SLOT,false);

        itemTarget->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchant_id, 0, 0);

        // add new enchanting if equipped
        item_owner->ApplyEnchantment(itemTarget,PERM_ENCHANTMENT_SLOT,true);

        itemTarget->SetSoulboundTradeable(NULL, item_owner, false);
    }
}

void Spell::EffectEnchantItemPrismatic(SpellEffIndex effIndex)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;
    if (!itemTarget)
        return;

    Player* p_caster = (Player*)m_caster;

    uint32 enchant_id = m_spellInfo->EffectMiscValue[effIndex];
    if (!enchant_id)
        return;

    SpellItemEnchantmentEntry const *pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
    if (!pEnchant)
        return;

    // support only enchantings with add socket in this slot
    {
        bool add_socket = false;
        for (uint8 i = 0; i < MAX_ITEM_ENCHANTMENT_EFFECTS; ++i)
        {
            if (pEnchant->type[i] == ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET)
            {
                add_socket = true;
                break;
            }
        }
        if (!add_socket)
        {
            sLog.outError("Spell::EffectEnchantItemPrismatic: attempt apply enchant spell %u with SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC (%u) but without ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET (%u), not suppoted yet.",
                m_spellInfo->Id,SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC,ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET);
            return;
        }
    }

    // item can be in trade slot and have owner diff. from caster
    Player* item_owner = itemTarget->GetOwner();
    if (!item_owner)
        return;

    if (item_owner != p_caster && p_caster->GetSession()->GetSecurity() > SEC_PLAYER && sWorld.getBoolConfig(CONFIG_GM_LOG_TRADE))
    {
        sLog.outCommand(p_caster->GetSession()->GetAccountId(),"GM %s (Account: %u) enchanting(perm): %s (Entry: %d) for player: %s (Account: %u)",
            p_caster->GetName(),p_caster->GetSession()->GetAccountId(),
            itemTarget->GetProto()->Name1,itemTarget->GetEntry(),
            item_owner->GetName(),item_owner->GetSession()->GetAccountId());
    }

    // remove old enchanting before applying new if equipped
    item_owner->ApplyEnchantment(itemTarget,PRISMATIC_ENCHANTMENT_SLOT,false);

    itemTarget->SetEnchantment(PRISMATIC_ENCHANTMENT_SLOT, enchant_id, 0, 0);

    // add new enchanting if equipped
    item_owner->ApplyEnchantment(itemTarget,PRISMATIC_ENCHANTMENT_SLOT,true);

    itemTarget->SetSoulboundTradeable(NULL, item_owner, false);
}

void Spell::EffectEnchantItemTmp(SpellEffIndex effIndex)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* p_caster = (Player*)m_caster;

    // Rockbiter Weapon apply to both weapon
    if (!itemTarget)
    return;
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_SHAMAN && m_spellInfo->SpellFamilyFlags[0] & 0x400000)
    {
        uint32 spell_id = 0;

        // enchanting spell selected by calculated damage-per-sec stored in Effect[1] base value
        // Note: damage calculated (correctly) with rounding int32(float(v)) but
        // RW enchantments applied damage int32(float(v)+0.5), this create  0..1 difference sometime
        switch(damage)
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
                sLog.outError("Spell::EffectEnchantItemTmp: Damage %u not handled in S'RW",damage);
                return;
        }

        SpellEntry const *spellInfo = sSpellStore.LookupEntry(spell_id);
        if (!spellInfo)
        {
            sLog.outError("Spell::EffectEnchantItemTmp: unknown spell id %i", spell_id);
            return;

        }

        for (int j = BASE_ATTACK; j <= OFF_ATTACK; ++j)
        {
            if (Item* item = p_caster->GetWeaponForAttack(WeaponAttackType(j)))
            {
                if (item->IsFitToSpellRequirements(m_spellInfo))
                {
                    Spell *spell = new Spell(m_caster, spellInfo, true);
                    SpellCastTargets targets;
                    targets.setItemTarget(item);
                    spell->prepare(&targets);
                }
            }
        }
        return;
    }
    if (!itemTarget)
        return;

    uint32 enchant_id = m_spellInfo->EffectMiscValue[effIndex];

    if (!enchant_id)
    {
        sLog.outError("Spell %u Effect %u (SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY) have 0 as enchanting id",m_spellInfo->Id,effIndex);
        return;
    }

    SpellItemEnchantmentEntry const *pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
    if (!pEnchant)
    {
        sLog.outError("Spell %u Effect %u (SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY) have not existed enchanting id %u ",m_spellInfo->Id,effIndex,enchant_id);
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

    if (item_owner != p_caster && p_caster->GetSession()->GetSecurity() > SEC_PLAYER && sWorld.getBoolConfig(CONFIG_GM_LOG_TRADE))
    {
        sLog.outCommand(p_caster->GetSession()->GetAccountId(),"GM %s (Account: %u) enchanting(temp): %s (Entry: %d) for player: %s (Account: %u)",
            p_caster->GetName(), p_caster->GetSession()->GetAccountId(),
            itemTarget->GetProto()->Name1, itemTarget->GetEntry(),
            item_owner->GetName(), item_owner->GetSession()->GetAccountId());
    }

    // remove old enchanting before applying new if equipped
    item_owner->ApplyEnchantment(itemTarget,TEMP_ENCHANTMENT_SLOT, false);

    itemTarget->SetEnchantment(TEMP_ENCHANTMENT_SLOT, enchant_id, duration * 1000, 0);

    // add new enchanting if equipped
    item_owner->ApplyEnchantment(itemTarget, TEMP_ENCHANTMENT_SLOT, true);
}

void Spell::EffectTameCreature(SpellEffIndex /*effIndex*/)
{
    if (m_caster->GetPetGUID())
        return;

    if (!unitTarget)
        return;

    if (unitTarget->GetTypeId() != TYPEID_UNIT)
        return;

    Creature* creatureTarget = unitTarget->ToCreature();

    if (creatureTarget->isPet())
        return;

    if (m_caster->getClass() != CLASS_HUNTER)
        return;

    // cast finish successfully
    //SendChannelUpdate(0);
    finish();

    Pet* pet = m_caster->CreateTamedPetFrom(creatureTarget,m_spellInfo->Id);
    if (!pet)                                               // in very specific state like near world end/etc.
        return;

    // "kill" original creature
    creatureTarget->ForcedDespawn();

    uint8 level = (creatureTarget->getLevel() < (m_caster->getLevel() - 5)) ? (m_caster->getLevel() - 5) : creatureTarget->getLevel();

    // prepare visual effect for levelup
    pet->SetUInt32Value(UNIT_FIELD_LEVEL, level - 1);

    // add to world
    pet->GetMap()->Add(pet->ToCreature());

    // visual effect for levelup
    pet->SetUInt32Value(UNIT_FIELD_LEVEL, level);

    // caster have pet now
    m_caster->SetMinion(pet, true);

    pet->InitTalentForLevel();

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        m_caster->ToPlayer()->PetSpellInitialize();
    }
}

void Spell::EffectSummonPet(SpellEffIndex effIndex)
{
    Player *owner = NULL;
    if (m_originalCaster)
    {
        if (m_originalCaster->GetTypeId() == TYPEID_PLAYER)
            owner = (Player*)m_originalCaster;
        else if (m_originalCaster->ToCreature()->isTotem())
            owner = m_originalCaster->GetCharmerOrOwnerPlayerOrPlayerItself();
    }

    uint32 petentry = m_spellInfo->EffectMiscValue[effIndex];

    if (!owner)
    {
        SummonPropertiesEntry const *properties = sSummonPropertiesStore.LookupEntry(67);
        if (properties)
            SummonGuardian(effIndex, petentry, properties);
        return;
    }

    Pet *OldSummon = owner->GetPet();

    // if pet requested type already exist
    if (OldSummon)
    {
        if (petentry == 0 || OldSummon->GetEntry() == petentry)
        {
            // pet in corpse state can't be summoned
            if (OldSummon->isDead())
                return;

            ASSERT(OldSummon->GetMap() == owner->GetMap());

            //OldSummon->GetMap()->Remove(OldSummon->ToCreature(),false);

            float px, py, pz;
            owner->GetClosePoint(px, py, pz, OldSummon->GetObjectSize());

            OldSummon->NearTeleportTo(px, py, pz, OldSummon->GetOrientation());
            //OldSummon->Relocate(px, py, pz, OldSummon->GetOrientation());
            //OldSummon->SetMap(owner->GetMap());
            //owner->GetMap()->Add(OldSummon->ToCreature());

            if (owner->GetTypeId() == TYPEID_PLAYER && OldSummon->isControlled())
                owner->ToPlayer()->PetSpellInitialize();

            return;
        }

        if (owner->GetTypeId() == TYPEID_PLAYER)
            owner->ToPlayer()->RemovePet(OldSummon,(OldSummon->getPetType() == HUNTER_PET ? PET_SAVE_AS_DELETED : PET_SAVE_NOT_IN_SLOT),false);
        else
            return;
    }

    float x, y, z;
    owner->GetClosePoint(x, y, z, owner->GetObjectSize());
    Pet* pet = owner->SummonPet(petentry, x, y, z, owner->GetOrientation(), SUMMON_PET, 0);
    if (!pet)
        return;

    if (m_caster->GetTypeId() == TYPEID_UNIT)
    {
        if (m_caster->ToCreature()->isTotem())
            pet->SetReactState(REACT_AGGRESSIVE);
        else
            pet->SetReactState(REACT_DEFENSIVE);
    }

    pet->SetUInt32Value(UNIT_CREATED_BY_SPELL, m_spellInfo->Id);

    // generate new name for summon pet
    std::string new_name=sObjectMgr.GeneratePetName(petentry);
    if (!new_name.empty())
        pet->SetName(new_name);

    ExecuteLogEffectSummonObject(effIndex, pet);
}

void Spell::EffectLearnPetSpell(SpellEffIndex effIndex)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player *_player = (Player*)m_caster;

    Pet *pet = _player->GetPet();
    if (!pet)
        return;
    if (!pet->isAlive())
        return;

    SpellEntry const *learn_spellproto = sSpellStore.LookupEntry(m_spellInfo->EffectTriggerSpell[effIndex]);
    if (!learn_spellproto)
        return;

    pet->learnSpell(learn_spellproto->Id);

    pet->SavePetToDB(PET_SAVE_AS_CURRENT);
    _player->PetSpellInitialize();
}

void Spell::EffectTaunt(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget)
        return;

    // this effect use before aura Taunt apply for prevent taunt already attacking target
    // for spell as marked "non effective at already attacking target"
    if (!unitTarget || !unitTarget->CanHaveThreatList()
        || unitTarget->getVictim() == m_caster)
    {
        SendCastResult(SPELL_FAILED_DONT_REPORT);
        return;
    }

    if (m_spellInfo->Id == 62124)
    {
        int32 damageDone = int32(1 + m_caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.5f);
        bool is_crit = m_caster->isSpellCrit(unitTarget, m_spellInfo, m_spellSchoolMask, m_attackType);
        if (is_crit)
            damageDone *= 2;
        m_caster->DealDamage(unitTarget, damageDone, NULL, SPELL_DIRECT_DAMAGE, SPELL_SCHOOL_MASK_HOLY, m_spellInfo, false);
        m_caster->SendSpellNonMeleeDamageLog(unitTarget, m_spellInfo->Id, damageDone, SPELL_SCHOOL_MASK_HOLY, 0, 0, false, false, is_crit);
    }

    // Also use this effect to set the taunter's threat to the taunted creature's highest value
    if (unitTarget->getThreatManager().getCurrentVictim())
    {
        float myThreat = unitTarget->getThreatManager().getThreat(m_caster);
        float itsThreat = unitTarget->getThreatManager().getCurrentVictim()->getThreat();
        if (itsThreat > myThreat)
            unitTarget->getThreatManager().addThreat(m_caster, itsThreat - myThreat);
    }

    //Set aggro victim to caster
    if (!unitTarget->getThreatManager().getOnlineContainer().empty())
        if (HostileReference* forcedVictim = unitTarget->getThreatManager().getOnlineContainer().getReferenceByTarget(m_caster))
            unitTarget->getThreatManager().setCurrentVictim(forcedVictim);

    if (unitTarget->ToCreature()->IsAIEnabled && !unitTarget->ToCreature()->HasReactState(REACT_PASSIVE))
        unitTarget->ToCreature()->AI()->AttackStart(m_caster);
}

void Spell::EffectWeaponDmg(SpellEffIndex /*effIndex*/)
{
}

void Spell::SpellDamageWeaponDmg(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;
    if (!unitTarget->isAlive())
        return;

    // multiple weapon dmg effect workaround
    // execute only the last weapon damage
    // and handle all effects at once
    for (uint32 j = effIndex + 1; j < MAX_SPELL_EFFECTS; ++j)
    {
        switch (m_spellInfo->Effect[j])
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
        case SPELLFAMILY_GENERIC:
        {
            switch (m_spellInfo->Id)
            {
                case 69055:     // Saber Lash
                case 70814:     // Saber Lash
                {
                    uint32 count = 0;
                    for (std::list<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                        if (ihit->effectMask & (1 << effIndex))
                            ++count;

                    totalDamagePercentMod /= count;
                    break;
                }
            }
            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            // Devastate (player ones)
            if (m_spellInfo->SpellFamilyFlags[1] & 0x40)
            {
                // Player can apply only 58567 Sunder Armor effect.
                bool needCast = !unitTarget->HasAura(58567, m_caster->GetGUID());
                if (needCast)
                    m_caster->CastSpell(unitTarget, 58567, true);

                if (Aura * aur = unitTarget->GetAura(58567, m_caster->GetGUID()))
                {
                    // 58388 - Glyph of Devastate dummy aura.
                    if (int32 num = (needCast ? 0 : 1) + (m_caster->HasAura(58388) ? 1 : 0))
                        aur->ModStackAmount(num);
                    fixed_bonus += (aur->GetStackAmount() - 1) * CalculateDamage(2, unitTarget);
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
                {
                    if (m_caster->GetTypeId() == TYPEID_PLAYER)
                        m_caster->ToPlayer()->AddComboPoints(unitTarget, 1, this);
                }
                // 50% more damage with daggers
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    if (Item* item = m_caster->ToPlayer()->GetWeaponForAttack(m_attackType, true))
                        if (item->GetProto()->SubClass == ITEM_SUBCLASS_WEAPON_DAGGER)
                            totalDamagePercentMod *= 1.5f;
            }
            // Mutilate (for each hand)
            else if (m_spellInfo->SpellFamilyFlags[1] & 0x6)
            {
                bool found = false;
                // fast check
                if (unitTarget->HasAuraState(AURA_STATE_DEADLY_POISON, m_spellInfo, m_caster))
                    found = true;
                // full aura scan
                else
                {
                    Unit::AuraApplicationMap const& auras = unitTarget->GetAppliedAuras();
                    for (Unit::AuraApplicationMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
                    {
                        if (itr->second->GetBase()->GetSpellProto()->Dispel == DISPEL_POISON)
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
            // Seal of Command - Increase damage by 36% on every swing
            if (m_spellInfo->SpellFamilyFlags[0] & 0x2000000)
            {
                totalDamagePercentMod *= 1.36f;            //136% damage
            }

            // Seal of Command Unleashed
            else if (m_spellInfo->Id == 20467)
            {
                spell_bonus += int32(0.08f*m_caster->GetTotalAttackPowerValue(BASE_ATTACK));
                spell_bonus += int32(0.13f*m_caster->SpellBaseDamageBonus(GetSpellSchoolMask(m_spellInfo)));
            }
            break;
        }
        case SPELLFAMILY_SHAMAN:
        {
            // Skyshatter Harness item set bonus
            // Stormstrike
            if (AuraEffect * aurEff = m_caster->IsScriptOverriden(m_spellInfo, 5634))
                m_caster->CastSpell(m_caster, 38430, true, NULL, aurEff);
            break;
        }
        case SPELLFAMILY_DRUID:
        {
            // Mangle (Cat): CP
            if (m_spellInfo->SpellFamilyFlags[1] & 0x400)
            {
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    m_caster->ToPlayer()->AddComboPoints(unitTarget,1, this);
            }
            // Shred, Maul - Rend and Tear
            else if (m_spellInfo->SpellFamilyFlags[0] & 0x00008800 && unitTarget->HasAuraState(AURA_STATE_BLEEDING))
            {
                if (AuraEffect const* rendAndTear = m_caster->GetDummyAuraEffect(SPELLFAMILY_DRUID, 2859, 0))
                {
                    totalDamagePercentMod *= float((rendAndTear->GetAmount() + 100.0f) / 100.0f);
                }
            }
            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            // Kill Shot - bonus damage from Ranged Attack Power
            if (m_spellInfo->SpellFamilyFlags[1] & 0x800000)
                spell_bonus += int32(0.4f*m_caster->GetTotalAttackPowerValue(RANGED_ATTACK));
            break;
        }
        case SPELLFAMILY_DEATHKNIGHT:
        {
            // Plague Strike
            if (m_spellInfo->SpellFamilyFlags[0] & 0x00000001)
            {
                // Glyph of Plague Strike
                if (AuraEffect * aurEff = m_caster->GetAuraEffect(58657,0))
                    totalDamagePercentMod *= float((aurEff->GetAmount() + 100.0f) / 100.0f);
            }
            // Blood Strike
            else if (m_spellInfo->SpellFamilyFlags[0] & 0x400000)
            {
                totalDamagePercentMod *= (float(unitTarget->GetDiseasesByCaster(m_caster->GetGUID())) * 12.5f + 100.0f) / 100.0f;

                // Glyph of Blood Strike
                if (m_caster->GetAuraEffect(59332,0))
                {
                    if (unitTarget->HasAuraType(SPELL_AURA_MOD_DECREASE_SPEED))
                       totalDamagePercentMod *= float((20 + 100.0f) / 100.0f);
                }
            }
            // Death Strike
            else if (m_spellInfo->SpellFamilyFlags[0] & 0x00000010)
            {
                // Glyph of Death Strike
                if (m_caster->GetAuraEffect(59336,0))
                {
                    if (uint32 runic = m_caster->GetPower(POWER_RUNIC_POWER))
                    {
                        if (runic > 25)
                            runic = 25;

                        totalDamagePercentMod *= float((runic + 100.0f) / 100.0f);
                    }
                }
            }
            // Obliterate (12.5% more damage per disease)
            else if (m_spellInfo->SpellFamilyFlags[1] & 0x20000)
            {
                bool consumeDiseases = true;
                // Annihilation
                if (AuraEffect * aurEff = m_caster->GetDummyAuraEffect(SPELLFAMILY_DEATHKNIGHT, 2710, 0))
                {
                    // Do not consume diseases if roll sucesses
                    if (roll_chance_i(aurEff->GetAmount()))
                        consumeDiseases = false;
                }
                totalDamagePercentMod *= (float(CalculateDamage(2, unitTarget) * unitTarget->GetDiseasesByCaster(m_caster->GetGUID(), consumeDiseases) / 2) + 100.0f) / 100.0f;
            }
            // Blood-Caked Strike - Blood-Caked Blade
            else if (m_spellInfo->SpellIconID == 1736)
                totalDamagePercentMod *= (float(unitTarget->GetDiseasesByCaster(m_caster->GetGUID())) * 12.5f + 100.0f) / 100.0f;
            break;
        }
    }

    bool normalized = false;
    float weaponDamagePercentMod = 1.0;
    for (int j = 0; j < MAX_SPELL_EFFECTS; ++j)
    {
        switch(m_spellInfo->Effect[j])
        {
            case SPELL_EFFECT_WEAPON_DAMAGE:
            case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                fixed_bonus += CalculateDamage(j, unitTarget);
                break;
            case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                fixed_bonus += CalculateDamage(j, unitTarget);
                normalized = true;
                break;
            case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                weaponDamagePercentMod *= float(CalculateDamage(j,unitTarget)) / 100.0f;
                break;
            default:
                break;                                      // not weapon damage effect, just skip
        }
    }

    // apply to non-weapon bonus weapon total pct effect, weapon total flat effect included in weapon damage
    if (fixed_bonus || spell_bonus)
    {
        UnitMods unitMod;
        switch(m_attackType)
        {
            default:
            case BASE_ATTACK:   unitMod = UNIT_MOD_DAMAGE_MAINHAND; break;
            case OFF_ATTACK:    unitMod = UNIT_MOD_DAMAGE_OFFHAND;  break;
            case RANGED_ATTACK: unitMod = UNIT_MOD_DAMAGE_RANGED;   break;
        }

        float weapon_total_pct = 1.0f;
        if (m_spellInfo->SchoolMask & SPELL_SCHOOL_MASK_NORMAL)
             weapon_total_pct = m_caster->GetModifierValue(unitMod, TOTAL_PCT);

        if (fixed_bonus)
            fixed_bonus = int32(fixed_bonus * weapon_total_pct);
        if (spell_bonus)
            spell_bonus = int32(spell_bonus * weapon_total_pct);
    }

    int32 weaponDamage = m_caster->CalculateDamage(m_attackType, normalized, true);

    // Sequence is important
    for (int j = 0; j < MAX_SPELL_EFFECTS; ++j)
    {
        // We assume that a spell have at most one fixed_bonus
        // and at most one weaponDamagePercentMod
        switch(m_spellInfo->Effect[j])
        {
            case SPELL_EFFECT_WEAPON_DAMAGE:
            case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
            case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                weaponDamage += fixed_bonus;
                break;
            case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                weaponDamage = int32(weaponDamage * weaponDamagePercentMod);
            default:
                break;                                      // not weapon damage effect, just skip
        }
    }

    if (spell_bonus)
        weaponDamage += spell_bonus;

    if (totalDamagePercentMod != 1.0f)
        weaponDamage = int32(weaponDamage * totalDamagePercentMod);

    // prevent negative damage
    uint32 eff_damage = uint32(weaponDamage > 0 ? weaponDamage : 0);

    // Add melee damage bonuses (also check for negative)
    m_caster->MeleeDamageBonus(unitTarget, &eff_damage, m_attackType, m_spellInfo);
    m_damage+= eff_damage;
}

void Spell::EffectThreat(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || !unitTarget->isAlive() || !m_caster->isAlive())
        return;

    if (!unitTarget->CanHaveThreatList())
        return;

    unitTarget->AddThreat(m_caster, float(damage));
}

void Spell::EffectHealMaxHealth(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || !unitTarget->isAlive())
        return;

    int32 addhealth;
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_PALADIN) // Lay on Hands
    {
        if (m_caster->GetGUID() == unitTarget->GetGUID())
        {
            m_caster->CastSpell(m_caster, 25771, true); // Forbearance
            m_caster->CastSpell(m_caster, 61988, true); // Immune shield marker (serverside)
            m_caster->CastSpell(m_caster, 61987, true); // Avenging Wrath marker
        }
    }

    // damage == 0 - heal for caster max health
    if (damage == 0)
        addhealth = m_caster->GetMaxHealth();
    else
        addhealth = unitTarget->GetMaxHealth() - unitTarget->GetHealth();

    if (m_originalCaster)
         m_healing += m_originalCaster->SpellHealingBonus(unitTarget,m_spellInfo, addhealth, HEAL);
}

void Spell::EffectInterruptCast(SpellEffIndex effIndex)
{
    if (!unitTarget || !unitTarget->isAlive())
        return;

    // TODO: not all spells that used this effect apply cooldown at school spells
    // also exist case: apply cooldown to interrupted cast only and to all spells
    for (uint32 i = CURRENT_FIRST_NON_MELEE_SPELL; i < CURRENT_MAX_SPELL; ++i)
    {
        if (Spell* spell = unitTarget->GetCurrentSpell(CurrentSpellTypes(i)))
        {
            SpellEntry const* curSpellInfo = spell->m_spellInfo;
            // check if we can interrupt spell
            if ((spell->getState() == SPELL_STATE_CASTING
                || (spell->getState() == SPELL_STATE_PREPARING && spell->GetCastTime() > 0.0f))
                && curSpellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_INTERRUPT && curSpellInfo->PreventionType == SPELL_PREVENTION_TYPE_SILENCE)
            {
                if (m_originalCaster)
                {
                    int32 duration = m_originalCaster->ModSpellDuration(m_spellInfo, unitTarget, m_originalCaster->CalcSpellDuration(m_spellInfo), false);
                    unitTarget->ProhibitSpellScholl(GetSpellSchoolMask(curSpellInfo), duration/*GetSpellDuration(m_spellInfo)*/);
                }
                ExecuteLogEffectInterruptCast(effIndex, unitTarget, curSpellInfo->Id);
                unitTarget->InterruptSpell(CurrentSpellTypes(i), false);
            }
        }
    }
}

void Spell::EffectSummonObjectWild(SpellEffIndex effIndex)
{
    uint32 gameobject_id = m_spellInfo->EffectMiscValue[effIndex];

    GameObject* pGameObj = new GameObject;

    WorldObject* target = focusObject;
    if (!target)
        target = m_caster;

    float x, y, z;
    if (m_targets.HasDst())
        m_targets.m_dstPos.GetPosition(x, y, z);
    else
        m_caster->GetClosePoint(x, y, z, DEFAULT_WORLD_OBJECT_SIZE);

    Map *map = target->GetMap();

    if (!pGameObj->Create(sObjectMgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT), gameobject_id, map,
        m_caster->GetPhaseMask(), x, y, z, target->GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f, 100, GO_STATE_READY))
    {
        delete pGameObj;
        return;
    }

    int32 duration = GetSpellDuration(m_spellInfo);

    pGameObj->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
    pGameObj->SetSpellId(m_spellInfo->Id);

    ExecuteLogEffectSummonObject(effIndex, pGameObj);

    // Wild object not have owner and check clickable by players
    map->Add(pGameObj);

    if (pGameObj->GetGoType() == GAMEOBJECT_TYPE_FLAGDROP && m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        Player *pl = m_caster->ToPlayer();
        Battleground* bg = pl->GetBattleground();

        switch(pGameObj->GetMapId())
        {
            case 489:                                       //WS
            {
                if (bg && bg->GetTypeID(true) == BATTLEGROUND_WS && bg->GetStatus() == STATUS_IN_PROGRESS)
                {
                    uint32 team = ALLIANCE;

                    if (pl->GetTeam() == team)
                        team = HORDE;

                    ((BattlegroundWS*)bg)->SetDroppedFlagGUID(pGameObj->GetGUID(),team);
                }
                break;
            }
            case 566:                                       //EY
            {
                if (bg && bg->GetTypeID(true) == BATTLEGROUND_EY && bg->GetStatus() == STATUS_IN_PROGRESS)
                {
                    ((BattlegroundEY*)bg)->SetDroppedFlagGUID(pGameObj->GetGUID());
                }
                break;
            }
        }
    }

    if (uint32 linkedEntry = pGameObj->GetGOInfo()->GetLinkedGameObjectEntry())
    {
        GameObject* linkedGO = new GameObject;
        if (linkedGO->Create(sObjectMgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT), linkedEntry, map,
            m_caster->GetPhaseMask(), x, y, z, target->GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f, 100, GO_STATE_READY))
        {
            linkedGO->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
            linkedGO->SetSpellId(m_spellInfo->Id);

            ExecuteLogEffectSummonObject(effIndex, linkedGO);

            // Wild object not have owner and check clickable by players
            map->Add(linkedGO);
        }
        else
        {
            delete linkedGO;
            linkedGO = NULL;
            return;
        }
    }
}

void Spell::EffectScriptEffect(SpellEffIndex effIndex)
{
    // TODO: we must implement hunter pet summon at login there (spell 6962)

    switch(m_spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            switch(m_spellInfo->Id)
            {
                // Glyph of Backstab
                case 63975:
                {
                    if (AuraEffect const * aurEff = unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE,SPELLFAMILY_ROGUE,0x00100000,0,0,m_caster->GetGUID()))
                    {
                        uint32 countMin = aurEff->GetBase()->GetMaxDuration();
                        uint32 countMax = 12000;
                        countMax += m_caster->HasAura(56801) ? 4000 : 0;

                        if (countMin < countMax)
                        {
                            aurEff->GetBase()->SetDuration(uint32(aurEff->GetBase()->GetDuration()+3000));
                            aurEff->GetBase()->SetMaxDuration(countMin+2000);
                        }

                    }
                    return;
                }
                case 45204: // Clone Me!
                case 41055: // Copy Weapon
                case 45206: // Copy Off-hand Weapon
                    unitTarget->CastSpell(m_caster, damage, false);
                    break;
                case 45205: // Copy Offhand Weapon
                case 41054: // Copy Weapon
                    m_caster->CastSpell(unitTarget, damage, false);
                    break;
                case 55693:                                 // Remove Collapsing Cave Aura
                    if (!unitTarget)
                        return;
                    unitTarget->RemoveAurasDueToSpell(SpellMgr::CalculateSpellEffectAmount(m_spellInfo, effIndex));
                    break;
                // PX-238 Winter Wondervolt TRAP
                case 26275:
                {
                    uint32 spells[4] = { 26272, 26157, 26273, 26274 };

                    // check presence
                    for (uint8 j = 0; j < 4; ++j)
                        if (unitTarget->HasAuraEffect(spells[j],0))
                            return;

                    // select spell
                    uint32 iTmpSpellId = spells[urand(0,3)];

                    // cast
                    unitTarget->CastSpell(unitTarget, iTmpSpellId, true);
                    return;
                }
                // Bending Shinbone
                case 8856:
                {
                    if (!itemTarget && m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    uint32 spell_id = 0;
                    switch(urand(1, 5))
                    {
                    case 1:  spell_id = 8854; break;
                    default: spell_id = 8855; break;
                    }

                    m_caster->CastSpell(m_caster,spell_id,true,NULL);
                    return;
                }
                // Brittle Armor - need remove one 24575 Brittle Armor aura
                case 24590:
                    unitTarget->RemoveAuraFromStack(24575);
                    return;
                // Mercurial Shield - need remove one 26464 Mercurial Shield aura
                case 26465:
                    unitTarget->RemoveAuraFromStack(26464);
                    return;
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
                    if (!unitTarget || !unitTarget->isAlive())
                        return;

                    // Onyxia Scale Cloak
                    if (unitTarget->HasAura(22683))
                        return;

                    // Shadow Flame
                    m_caster->CastSpell(unitTarget, 22682, true);
                    return;
                }
                // Piccolo of the Flaming Fire
                case 17512:
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;
                    unitTarget->HandleEmoteCommand(EMOTE_STATE_DANCE);
                    return;
                }
                // Escape artist
                case 20589:
                    m_caster->RemoveMovementImpairingAuras();
                    return;
                // Decimate
                case 28374:
                case 54426:
                    if (unitTarget)
                    {
                        int32 damage = int32(unitTarget->GetHealth()) - int32(unitTarget->CountPctFromMaxHealth(5));
                        if (damage > 0)
                            m_caster->CastCustomSpell(28375, SPELLVALUE_BASE_POINT0, damage, unitTarget);
                    }
                    return;
                // Mirren's Drinking Hat
                case 29830:
                {
                    uint32 item = 0;
                    switch (urand(1, 6))
                    {
                        case 1:
                        case 2:
                        case 3:
                            item = 23584; break;            // Loch Modan Lager
                        case 4:
                        case 5:
                            item = 23585; break;            // Stouthammer Lite
                        case 6:
                            item = 23586; break;            // Aerie Peak Pale Ale
                    }
                    if (item)
                        DoCreateItem(effIndex,item);
                    break;
                }
                // Improved Sprint
                case 30918:
                {
                    // Removes snares and roots.
                    unitTarget->RemoveMovementImpairingAuras();
                    break;
                }
                // Spirit Walk
                case 58876:
                {
                    // Removes snares and roots.
                    unitTarget->RemoveMovementImpairingAuras();
                    break;
                }
                // Plant Warmaul Ogre Banner
                case 32307:
                {
                    Player *p_caster = dynamic_cast<Player*>(m_caster);
                    if (!p_caster)
                        break;
                    p_caster->RewardPlayerAndGroupAtEvent(18388, unitTarget);
                    Creature *cTarget = dynamic_cast<Creature*>(unitTarget);
                    if (!cTarget)
                        break;
                    cTarget->setDeathState(CORPSE);
                    cTarget->RemoveCorpse();
                    break;
                }
                case 48025:                                     // Headless Horseman's Mount
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // Prevent stacking of mounts and client crashes upon dismounting
                    unitTarget->RemoveAurasByType(SPELL_AURA_MOUNTED);

                    // Triggered spell id dependent on riding skill and zone
                    bool canFly = true;
                    uint32 v_map = GetVirtualMapForMapAndZone(unitTarget->GetMapId(), unitTarget->GetZoneId());
                    if (v_map != 530 && v_map != 571)
                        canFly = false;

                    if (canFly && v_map == 571 && !unitTarget->ToPlayer()->HasSpell(54197))
                        canFly = false;

                    float x, y, z;
                    unitTarget->GetPosition(x, y, z);
                    uint32 areaFlag = unitTarget->GetBaseMap()->GetAreaFlag(x, y, z);
                    AreaTableEntry const *pArea = sAreaStore.LookupEntry(areaFlag);
                    if (canFly && pArea->flags & AREA_FLAG_NO_FLY_ZONE)
                        canFly = false;

                    switch(unitTarget->ToPlayer()->GetBaseSkillValue(SKILL_RIDING))
                    {
                    case 75: unitTarget->CastSpell(unitTarget, 51621, true); break;
                    case 150: unitTarget->CastSpell(unitTarget, 48024, true); break;
                    case 225:
                        {
                            if (canFly)
                                unitTarget->CastSpell(unitTarget, 51617, true);
                            else
                                unitTarget->CastSpell(unitTarget, 48024, true);
                        }break;
                    case 300:
                        {
                            if (canFly)
                                unitTarget->CastSpell(unitTarget, 48023, true);
                            else
                                unitTarget->CastSpell(unitTarget, 48024, true);
                        }break;
                    }
                    return;
                }
                case 47977:                                     // Magic Broom
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // Prevent stacking of mounts and client crashes upon dismounting
                    unitTarget->RemoveAurasByType(SPELL_AURA_MOUNTED);

                    // Triggered spell id dependent on riding skill and zone
                    bool canFly = true;
                    uint32 v_map = GetVirtualMapForMapAndZone(unitTarget->GetMapId(), unitTarget->GetZoneId());
                    if (v_map != 530 && v_map != 571)
                        canFly = false;

                    if (canFly && v_map == 571 && !unitTarget->ToPlayer()->HasSpell(54197))
                        canFly = false;

                    float x, y, z;
                    unitTarget->GetPosition(x, y, z);
                    uint32 areaFlag = unitTarget->GetBaseMap()->GetAreaFlag(x, y, z);
                    AreaTableEntry const *pArea = sAreaStore.LookupEntry(areaFlag);
                    if (canFly && pArea->flags & AREA_FLAG_NO_FLY_ZONE)
                        canFly = false;

                    switch(unitTarget->ToPlayer()->GetBaseSkillValue(SKILL_RIDING))
                    {
                    case 75: unitTarget->CastSpell(unitTarget, 42680, true); break;
                    case 150: unitTarget->CastSpell(unitTarget, 42683, true); break;
                    case 225:
                        {
                            if (canFly)
                                unitTarget->CastSpell(unitTarget, 42667, true);
                            else
                                unitTarget->CastSpell(unitTarget, 42683, true);
                        }break;
                    case 300:
                        {
                            if (canFly)
                                unitTarget->CastSpell(unitTarget, 42668, true);
                            else
                                unitTarget->CastSpell(unitTarget, 42683, true);
                        }break;
                    }
                    return;
                }
                // Mug Transformation
                case 41931:
                {
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    uint8 bag = 19;
                    uint8 slot = 0;
                    Item *item = NULL;

                    while (bag) // 256 = 0 due to var type
                    {
                        item = m_caster->ToPlayer()->GetItemByPos(bag, slot);
                        if (item && item->GetEntry() == 38587) break;
                        ++slot;
                        if (slot == 39)
                        {
                            slot = 0;
                            ++bag;
                        }
                    }
                    if (bag)
                    {
                        if (m_caster->ToPlayer()->GetItemByPos(bag,slot)->GetCount() == 1) m_caster->ToPlayer()->RemoveItem(bag,slot,true);
                        else m_caster->ToPlayer()->GetItemByPos(bag,slot)->SetCount(m_caster->ToPlayer()->GetItemByPos(bag,slot)->GetCount()-1);
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
                    float radius = GetSpellRadiusForHostile(sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[effIndex]));
                    if (unitTarget && unitTarget->GetTypeId() == TYPEID_PLAYER && unitTarget->GetDistance(m_caster) >= radius && !unitTarget->HasAura(46394) && unitTarget != m_caster)
                        unitTarget->CastSpell(unitTarget, 46394, true);

                    break;
                }
                // Goblin Weather Machine
                case 46203:
                {
                    if (!unitTarget)
                        return;

                    uint32 spellId = 0;
                    switch(rand() % 4)
                    {
                        case 0: spellId = 46740; break;
                        case 1: spellId = 46739; break;
                        case 2: spellId = 46738; break;
                        case 3: spellId = 46736; break;
                    }
                    unitTarget->CastSpell(unitTarget, spellId, true);
                    break;
                }
                // 5,000 Gold
                case 46642:
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    unitTarget->ToPlayer()->ModifyMoney(5000 * GOLD);

                    break;
                }
                // Roll Dice - Decahedral Dwarven Dice
                case 47770:
                {
                    char buf[128];
                    const char *gender = "his";
                    if (m_caster->getGender() > 0)
                        gender = "her";
                    sprintf(buf, "%s rubs %s [Decahedral Dwarven Dice] between %s hands and rolls. One %u and one %u.", m_caster->GetName(), gender, gender, urand(1,10), urand(1,10));
                    m_caster->MonsterTextEmote(buf, 0);
                    break;
                }
                // Roll 'dem Bones - Worn Troll Dice
                case 47776:
                {
                    char buf[128];
                    const char *gender = "his";
                    if (m_caster->getGender() > 0)
                        gender = "her";
                    sprintf(buf, "%s causually tosses %s [Worn Troll Dice]. One %u and one %u.", m_caster->GetName(), gender, urand(1,6), urand(1,6));
                    m_caster->MonsterTextEmote(buf, 0);
                    break;
                }
                // Vigilance
                case 50725:
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // Remove Taunt cooldown
                    unitTarget->ToPlayer()->RemoveSpellCooldown(355, true);

                    return;
                }
                // Death Knight Initiate Visual
                case 51519:
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_UNIT)
                        return;

                    uint32 iTmpSpellId = 0;
                    switch (unitTarget->GetDisplayId())
                    {
                        case 25369: iTmpSpellId = 51552; break; // bloodelf female
                        case 25373: iTmpSpellId = 51551; break; // bloodelf male
                        case 25363: iTmpSpellId = 51542; break; // draenei female
                        case 25357: iTmpSpellId = 51541; break; // draenei male
                        case 25361: iTmpSpellId = 51537; break; // dwarf female
                        case 25356: iTmpSpellId = 51538; break; // dwarf male
                        case 25372: iTmpSpellId = 51550; break; // forsaken female
                        case 25367: iTmpSpellId = 51549; break; // forsaken male
                        case 25362: iTmpSpellId = 51540; break; // gnome female
                        case 25359: iTmpSpellId = 51539; break; // gnome male
                        case 25355: iTmpSpellId = 51534; break; // human female
                        case 25354: iTmpSpellId = 51520; break; // human male
                        case 25360: iTmpSpellId = 51536; break; // nightelf female
                        case 25358: iTmpSpellId = 51535; break; // nightelf male
                        case 25368: iTmpSpellId = 51544; break; // orc female
                        case 25364: iTmpSpellId = 51543; break; // orc male
                        case 25371: iTmpSpellId = 51548; break; // tauren female
                        case 25366: iTmpSpellId = 51547; break; // tauren male
                        case 25370: iTmpSpellId = 51545; break; // troll female
                        case 25365: iTmpSpellId = 51546; break; // troll male
                        default: return;
                    }

                    unitTarget->CastSpell(unitTarget, iTmpSpellId, true);
                    Creature* npc = unitTarget->ToCreature();
                    npc->LoadEquipment(npc->GetEquipmentId());
                    return;
                }
                // Emblazon Runeblade
                case 51770:
                {
                    if (!m_originalCaster)
                        return;

                    m_originalCaster->CastSpell(m_originalCaster, damage, false);
                    break;
                }
                // Deathbolt from Thalgran Blightbringer
                // reflected by Freya's Ward
                // Retribution by Sevenfold Retribution
                case 51854:
                {
                    if (!m_caster || !unitTarget)
                        return;
                    if (unitTarget->HasAura(51845))
                        unitTarget->CastSpell(m_caster, 51856, true);
                    else
                        m_caster->CastSpell(unitTarget, 51855, true);
                    break;
                }
                // Summon Ghouls On Scarlet Crusade
                case 51904:
                {
                    if (!m_targets.HasDst())
                        return;

                    float x, y, z;
                    float radius = GetSpellRadius(m_spellInfo, effIndex, true);
                    for (uint8 i = 0; i < 15; ++i)
                    {
                        m_caster->GetRandomPoint(m_targets.m_dstPos, radius, x, y, z);
                        m_caster->CastSpell(x, y, z, 54522, true);
                    }
                    break;
                }
                case 52173: // Coyote Spirit Despawn
                case 60243: // Blood Parrot Despawn
                    if (unitTarget->GetTypeId() == TYPEID_UNIT && unitTarget->ToCreature()->isSummon())
                        unitTarget->ToTempSummon()->UnSummon();
                    return;
                case 52479: // Gift of the Harvester
                    if (unitTarget && m_originalCaster)
                        m_originalCaster->CastSpell(unitTarget, urand(0, 1) ? damage : 52505, true);
                    return;
                // Death Gate
                case 52751:
                {
                    if (!unitTarget || unitTarget->getClass() != CLASS_DEATH_KNIGHT)
                        return;
                    // triggered spell is stored in m_spellInfo->EffectBasePoints[0]
                    unitTarget->CastSpell(unitTarget, damage, false);
                    break;
                }
                case 53110: // Devour Humanoid
                    if (unitTarget)
                        unitTarget->CastSpell(m_caster, damage, true);
                    return;
                // Winged Steed of the Ebon Blade
                case 54729:
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // Prevent stacking of mounts and client crashes upon dismounting
                    unitTarget->RemoveAurasByType(SPELL_AURA_MOUNTED);

                    // Triggered spell id dependent on riding skill
                    if (uint16 skillval = unitTarget->ToPlayer()->GetSkillValue(SKILL_RIDING))
                    {
                        if (skillval >= 300)
                            unitTarget->CastSpell(unitTarget, 54727, true);
                        else
                            unitTarget->CastSpell(unitTarget, 54726, true);
                    }
                    return;
                }
                case 58418:                                 // Portal to Orgrimmar
                case 58420:                                 // Portal to Stormwind
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER || effIndex != 0)
                        return;

                    uint32 spellID = SpellMgr::CalculateSpellEffectAmount(m_spellInfo, 0);
                    uint32 questID = SpellMgr::CalculateSpellEffectAmount(m_spellInfo, 1);

                    if (unitTarget->ToPlayer()->GetQuestStatus(questID) == QUEST_STATUS_COMPLETE && !unitTarget->ToPlayer()->GetQuestRewardStatus (questID))
                        unitTarget->CastSpell(unitTarget, spellID, true);

                    return;
                }
                case 58941:                                 // Rock Shards
                    if (unitTarget && m_originalCaster)
                    {
                        for (uint32 i = 0; i < 3; ++i)
                        {
                            m_originalCaster->CastSpell(unitTarget, 58689, true);
                            m_originalCaster->CastSpell(unitTarget, 58692, true);
                        }
                        if (((InstanceMap*)m_originalCaster->GetMap())->GetDifficulty() == REGULAR_DIFFICULTY)
                        {
                            m_originalCaster->CastSpell(unitTarget, 58695, true);
                            m_originalCaster->CastSpell(unitTarget, 58696, true);
                        }
                        else
                        {
                            m_originalCaster->CastSpell(unitTarget, 60883, true);
                            m_originalCaster->CastSpell(unitTarget, 60884, true);
                        }
                    }
                    return;
                case 58983: // Big Blizzard Bear
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // Prevent stacking of mounts and client crashes upon dismounting
                    unitTarget->RemoveAurasByType(SPELL_AURA_MOUNTED);

                    // Triggered spell id dependent on riding skill
                    if (uint16 skillval = unitTarget->ToPlayer()->GetSkillValue(SKILL_RIDING))
                    {
                        if (skillval >= 150)
                            unitTarget->CastSpell(unitTarget, 58999, true);
                        else
                            unitTarget->CastSpell(unitTarget, 58997, true);
                    }
                    return;
                }
                case 63845: // Create Lance
                {
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    if (m_caster->ToPlayer()->GetTeam() == ALLIANCE)
                        m_caster->CastSpell(m_caster, 63914, true);
                    else
                        m_caster->CastSpell(m_caster, 63919, true);
                    return;
                }
                case 71342:                                     // Big Love Rocket
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // Prevent stacking of mounts and client crashes upon dismounting
                    unitTarget->RemoveAurasByType(SPELL_AURA_MOUNTED);

                    // Triggered spell id dependent on riding skill and zone
                    bool canFly = true;
                    uint32 v_map = GetVirtualMapForMapAndZone(unitTarget->GetMapId(), unitTarget->GetZoneId());
                    if (v_map != 530 && v_map != 571)
                        canFly = false;

                    if (canFly && v_map == 571 && !unitTarget->ToPlayer()->HasSpell(54197))
                        canFly = false;

                    float x, y, z;
                    unitTarget->GetPosition(x, y, z);
                    uint32 areaFlag = unitTarget->GetBaseMap()->GetAreaFlag(x, y, z);
                    AreaTableEntry const *pArea = sAreaStore.LookupEntry(areaFlag);
                    if (canFly && pArea->flags & AREA_FLAG_NO_FLY_ZONE)
                        canFly = false;

                    switch(unitTarget->ToPlayer()->GetBaseSkillValue(SKILL_RIDING))
                    {
                    case 0: unitTarget->CastSpell(unitTarget, 71343, true); break;
                    case 75: unitTarget->CastSpell(unitTarget, 71344, true); break;
                    case 150: unitTarget->CastSpell(unitTarget, 71345, true); break;
                    case 225:
                        {
                        if (canFly)
                                unitTarget->CastSpell(unitTarget, 71346, true);
                            else
                                unitTarget->CastSpell(unitTarget, 71345, true);
                        }break;
                    case 300:
                        {
                        if (canFly)
                            unitTarget->CastSpell(unitTarget, 71347, true);
                        else
                            unitTarget->CastSpell(unitTarget, 71345, true);
                        }break;
                    }
                    return;
                }
                case 72286:                                     // Invincible
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // Prevent stacking of mounts and client crashes upon dismounting
                    unitTarget->RemoveAurasByType(SPELL_AURA_MOUNTED);

                    // Triggered spell id dependent on riding skill and zone
                    bool canFly = true;
                    uint32 v_map = GetVirtualMapForMapAndZone(unitTarget->GetMapId(), unitTarget->GetZoneId());
                    if (v_map != 530 && v_map != 571)
                        canFly = false;

                    if (canFly && v_map == 571 && !unitTarget->ToPlayer()->HasSpell(54197))
                        canFly = false;

                    float x, y, z;
                    unitTarget->GetPosition(x, y, z);
                    uint32 areaFlag = unitTarget->GetBaseMap()->GetAreaFlag(x, y, z);
                    AreaTableEntry const *pArea = sAreaStore.LookupEntry(areaFlag);
                    if (canFly && pArea->flags & AREA_FLAG_NO_FLY_ZONE)
                        canFly = false;

                    switch(unitTarget->ToPlayer()->GetBaseSkillValue(SKILL_RIDING))
                    {
                    case 75: unitTarget->CastSpell(unitTarget, 72281, true); break;
                    case 150: unitTarget->CastSpell(unitTarget, 72282, true); break;
                    case 225:
                        {
                        if (canFly)
                                unitTarget->CastSpell(unitTarget, 72283, true);
                            else
                                unitTarget->CastSpell(unitTarget, 72282, true);
                        }break;
                    case 300:
                        {
                        if (canFly)
                            unitTarget->CastSpell(unitTarget, 72284, true);
                        else
                            unitTarget->CastSpell(unitTarget, 72282, true);
                        }break;
                    }
                    return;
                }
                case 74856:                                     // Blazing Hippogryph
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // Prevent stacking of mounts and client crashes upon dismounting
                    unitTarget->RemoveAurasByType(SPELL_AURA_MOUNTED);

                    // Triggered spell id dependent on riding skill
                    if (uint16 skillval = unitTarget->ToPlayer()->GetSkillValue(SKILL_RIDING))
                    {
                        if (skillval >= 300)
                            unitTarget->CastSpell(unitTarget, 74855, true);
                        else
                            unitTarget->CastSpell(unitTarget, 74854, true);
                    }
                    return;
                }
                case 75614:                                     // Celestial Steed
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // Prevent stacking of mounts and client crashes upon dismounting
                    unitTarget->RemoveAurasByType(SPELL_AURA_MOUNTED);

                    // Triggered spell id dependent on riding skill and zone
                    bool canFly = true;
                    uint32 v_map = GetVirtualMapForMapAndZone(unitTarget->GetMapId(), unitTarget->GetZoneId());
                    if (v_map != 530 && v_map != 571)
                        canFly = false;

                    if (canFly && v_map == 571 && !unitTarget->ToPlayer()->HasSpell(54197))
                        canFly = false;

                    float x, y, z;
                    unitTarget->GetPosition(x, y, z);
                    uint32 areaFlag = unitTarget->GetBaseMap()->GetAreaFlag(x, y, z);
                    AreaTableEntry const *pArea = sAreaStore.LookupEntry(areaFlag);
                    if (canFly && pArea->flags & AREA_FLAG_NO_FLY_ZONE)
                        canFly = false;

                    switch(unitTarget->ToPlayer()->GetBaseSkillValue(SKILL_RIDING))
                    {
                    case 75: unitTarget->CastSpell(unitTarget, 75619, true); break;
                    case 150: unitTarget->CastSpell(unitTarget, 75620, true); break;
                    case 225:
                        {
                            if (canFly)
                                unitTarget->CastSpell(unitTarget, 75617, true);
                            else
                                unitTarget->CastSpell(unitTarget, 75620, true);
                        }break;
                    case 300:
                        {
                            if (canFly)
                            {
                                if (unitTarget->ToPlayer()->Has310Flyer(false))
                                    unitTarget->CastSpell(unitTarget, 76153, true);
                                else
                                    unitTarget->CastSpell(unitTarget, 75618, true);
                            }
                            else
                                unitTarget->CastSpell(unitTarget, 75620, true);
                        }break;
                    }
                    return;
                }
                case 75973:                                     // X-53 Touring Rocket
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // Prevent stacking of mounts
                    unitTarget->RemoveAurasByType(SPELL_AURA_MOUNTED);

                    // Triggered spell id dependent on riding skill
                    if (uint16 skillval = unitTarget->ToPlayer()->GetSkillValue(SKILL_RIDING))
                    {
                        if (skillval >= 300)
                        {
                            if (unitTarget->ToPlayer()->Has310Flyer(false))
                                unitTarget->CastSpell(unitTarget, 76154, true);
                            else
                                unitTarget->CastSpell(unitTarget, 75972, true);
                        }
                        else
                            unitTarget->CastSpell(unitTarget, 75957, true);
                    }
                    return;
                }
                case 59317:                                 // Teleporting
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // return from top
                    if (unitTarget->ToPlayer()->GetAreaId() == 4637)
                        unitTarget->CastSpell(unitTarget, 59316, true);
                    // teleport atop
                    else
                        unitTarget->CastSpell(unitTarget, 59314, true);

                    return;
                // random spell learn instead placeholder
                case 60893:                                 // Northrend Alchemy Research
                case 61177:                                 // Northrend Inscription Research
                case 61288:                                 // Minor Inscription Research
                case 61756:                                 // Northrend Inscription Research (FAST QA VERSION)
                case 64323:                                 // Book of Glyph Mastery
                {
                    if (m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // learn random explicit discovery recipe (if any)
                    if (uint32 discoveredSpell = GetExplicitDiscoverySpell(m_spellInfo->Id, (Player*)m_caster))
                        m_caster->ToPlayer()->learnSpell(discoveredSpell, false);
                    return;
                }
                case 62428: // Load into Catapult
                {
                    if (Vehicle *seat = m_caster->GetVehicleKit())
                        if (Unit *passenger = seat->GetPassenger(0))
                            if (Unit *demolisher = m_caster->GetVehicleBase())
                                passenger->CastSpell(demolisher, damage, true);
                    return;
                }
                case 62482: // Grab Crate
                {
                    if (unitTarget)
                    {
                        if (Vehicle *seat = m_caster->GetVehicleKit())
                        {
                            if (Creature *oldContainer = dynamic_cast<Creature*>(seat->GetPassenger(1)))
                                oldContainer->DisappearAndDie();
                            // TODO: a hack, range = 11, should after some time cast, otherwise too far
                            unitTarget->CastSpell(seat->GetBase(), 62496, true);
                            unitTarget->EnterVehicle(seat, 1);
                        }
                    }
                    return;
                }
                case 60123: // Lightwell
                {
                    if (m_caster->GetTypeId() != TYPEID_UNIT || !m_caster->ToCreature()->isSummon())
                        return;

                    uint32 spell_heal;

                    switch(m_caster->GetEntry())
                    {
                        case 31897: spell_heal = 7001; break;
                        case 31896: spell_heal = 27873; break;
                        case 31895: spell_heal = 27874; break;
                        case 31894: spell_heal = 28276; break;
                        case 31893: spell_heal = 48084; break;
                        case 31883: spell_heal = 48085; break;
                        default:
                            sLog.outError("Unknown Lightwell spell caster %u", m_caster->GetEntry());
                            return;
                    }
                    Aura * chargesaura = m_caster->GetAura(59907);

                    if (chargesaura && chargesaura->GetCharges() > 1)
                    {
                        chargesaura->SetCharges(chargesaura->GetCharges() - 1);
                        m_caster->CastSpell(unitTarget, spell_heal, true, NULL, NULL, m_caster->ToTempSummon()->GetSummonerGUID());
                    }
                    else
                        m_caster->ToTempSummon()->UnSummon();
                    return;
                }
                // Stoneclaw Totem
                case 55328: // Rank 1
                case 55329: // Rank 2
                case 55330: // Rank 3
                case 55332: // Rank 4
                case 55333: // Rank 5
                case 55335: // Rank 6
                case 55278: // Rank 7
                case 58589: // Rank 8
                case 58590: // Rank 9
                case 58591: // Rank 10
                {
                    int32 basepoints0 = damage;
                    // Cast Absorb on totems
                    for (uint8 slot = SUMMON_SLOT_TOTEM; slot < MAX_TOTEM_SLOT; ++slot)
                    {
                        if (!unitTarget->m_SummonSlot[slot])
                            continue;

                        Creature* totem = unitTarget->GetMap()->GetCreature(unitTarget->m_SummonSlot[slot]);
                        if (totem && totem->isTotem())
                        {
                            m_caster->CastCustomSpell(totem, 55277, &basepoints0, NULL, NULL, true);
                        }
                    }
                    // Glyph of Stoneclaw Totem
                    if (AuraEffect *aur=unitTarget->GetAuraEffect(63298, 0))
                    {
                        basepoints0 *= aur->GetAmount();
                        m_caster->CastCustomSpell(unitTarget, 55277, &basepoints0, NULL, NULL, true);
                    }
                    break;
                }
                case 66545: //Summon Memory
                {
                    uint8 uiRandom = urand(0,25);
                    uint32 uiSpells[26] = {66704,66705,66706,66707,66709,66710,66711,66712,66713,66714,66715,66708,66708,66691,66692,66694,66695,66696,66697,66698,66699,66700,66701,66702,66703,66543};

                    m_caster->CastSpell(m_caster,uiSpells[uiRandom],true);
                    break;
                }
                case 45668:                                 // Ultra-Advanced Proto-Typical Shortening Blaster
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_UNIT)
                        return;

                    if (roll_chance_i(50))                  // chance unknown, using 50
                        return;

                    static uint32 const spellPlayer[5] =
                    {
                        45674,                            // Bigger!
                        45675,                            // Shrunk
                        45678,                            // Yellow
                        45682,                            // Ghost
                        45684                             // Polymorph
                    };

                    static uint32 const spellTarget[5] = {
                        45673,                            // Bigger!
                        45672,                            // Shrunk
                        45677,                            // Yellow
                        45681,                            // Ghost
                        45683                             // Polymorph
                    };

                    m_caster->CastSpell(m_caster, spellPlayer[urand(0,4)], true);
                    unitTarget->CastSpell(unitTarget, spellTarget[urand(0,4)], true);
                    break;
                }
                case 64142:                                 // Upper Deck - Create Foam Sword
                    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;
                    Player *plr = unitTarget->ToPlayer();
                    static uint32 const itemId[] = {45061, 45176, 45177, 45178, 45179, 0};
                    // player can only have one of these items
                    for (uint32 const *itr = &itemId[0]; *itr; ++itr)
                        if (plr->HasItemCount(*itr, 1, true))
                            return;
                    DoCreateItem(effIndex, itemId[urand(0,4)]);
                    return;
            }
            break;
        }
        case SPELLFAMILY_PALADIN:
        {
            // Judgement (seal trigger)
            if (m_spellInfo->Category == SPELLCATEGORY_JUDGEMENT)
            {
                if (!unitTarget || !unitTarget->isAlive())
                    return;
                uint32 spellId1 = 0;
                uint32 spellId2 = 0;
                uint32 spellId3 = 0;

                // Judgement self add switch
                switch (m_spellInfo->Id)
                {
                    case 53407: spellId1 = 20184; break;    // Judgement of Justice
                    case 20271:                             // Judgement of Light
                    case 57774: spellId1 = 20185; break;    // Judgement of Light
                    case 53408: spellId1 = 20186; break;    // Judgement of Wisdom
                    default:
                        sLog.outError("Unsupported Judgement (seal trigger) spell (Id: %u) in Spell::EffectScriptEffect",m_spellInfo->Id);
                        return;
                }
                // all seals have aura dummy in 2 effect
                Unit::AuraApplicationMap & sealAuras = m_caster->GetAppliedAuras();
                for (Unit::AuraApplicationMap::iterator iter = sealAuras.begin(); iter != sealAuras.end();)
                {
                    switch (iter->first)
                    {
                        // Heart of the Crusader
                        case 20335: // Rank 1
                            spellId3 = 21183;
                            break;
                        case 20336: // Rank 2
                            spellId3 = 54498;
                            break;
                        case 20337: // Rank 3
                            spellId3 = 54499;
                            break;
                    }
                    Aura * aura = iter->second->GetBase();
                    if (IsSealSpell(aura->GetSpellProto()))
                    {
                        if (AuraEffect * aureff = aura->GetEffect(2))
                            if (aureff->GetAuraType() == SPELL_AURA_DUMMY)
                            {
                                if (sSpellStore.LookupEntry(aureff->GetAmount()))
                                    spellId2 = aureff->GetAmount();
                                break;
                            }
                        if (!spellId2)
                        {
                            switch (iter->first)
                            {
                                // Seal of light, Seal of wisdom, Seal of justice
                                case 20165:
                                case 20166:
                                case 20164:
                                    spellId2 = 54158;
                            }
                        }
                        break;
                    }
                    else
                        ++iter;
                }
                if (spellId1)
                    m_caster->CastSpell(unitTarget, spellId1, true);
                if (spellId2)
                    m_caster->CastSpell(unitTarget, spellId2, true);
                if (spellId3)
                    m_caster->CastSpell(unitTarget, spellId3, true);
                return;
            }
        }
        case SPELLFAMILY_POTION:
        {
            switch(m_spellInfo->Id)
            {
                // Netherbloom
                case 28702:
                {
                    if (!unitTarget)
                        return;
                    // 25% chance of casting a random buff
                    if (roll_chance_i(75))
                        return;

                    // triggered spells are 28703 to 28707
                    // Note: some sources say, that there was the possibility of
                    //       receiving a debuff. However, this seems to be removed by a patch.
                    const uint32 spellid = 28703;

                    // don't overwrite an existing aura
                    for (uint8 i = 0; i < 5; ++i)
                        if (unitTarget->HasAura(spellid + i))
                            return;
                    unitTarget->CastSpell(unitTarget, spellid+urand(0, 4), true);
                    break;
                }

                // Nightmare Vine
                case 28720:
                {
                    if (!unitTarget)
                        return;
                    // 25% chance of casting Nightmare Pollen
                    if (roll_chance_i(75))
                        return;
                    unitTarget->CastSpell(unitTarget, 28721, true);
                    break;
                }
            }
            break;
        }
        case SPELLFAMILY_DEATHKNIGHT:
        {
            // Pestilence
            if (m_spellInfo->SpellFamilyFlags[1]&0x10000)
            {
                // Get diseases on target of spell
                if (m_targets.getUnitTarget() &&  // Glyph of Disease - cast on unit target too to refresh aura
                    (m_targets.getUnitTarget() != unitTarget || m_caster->GetAura(63334)))
                {
                    // And spread them on target
                    // Blood Plague
                    if (m_targets.getUnitTarget()->GetAura(55078))
                        m_caster->CastSpell(unitTarget, 55078, true);
                    // Frost Fever
                    if (m_targets.getUnitTarget()->GetAura(55095))
                        m_caster->CastSpell(unitTarget, 55095, true);
                }
            }
            break;
        }
        case SPELLFAMILY_WARRIOR:
        {
            // Shattering Throw
            if (m_spellInfo->SpellFamilyFlags[1] & 0x00400000)
            {
                if (!unitTarget)
                    return;
                // remove shields, will still display immune to damage part
                unitTarget->RemoveAurasWithMechanic(1<<MECHANIC_IMMUNE_SHIELD, AURA_REMOVE_BY_ENEMY_SPELL);
                return;
            }
            break;
        }
    }

    // normal DB scripted effect
    sLog.outDebug("Spell ScriptStart spellid %u in EffectScriptEffect(%u)", m_spellInfo->Id, effIndex);
    m_caster->GetMap()->ScriptsStart(sSpellScripts, uint32(m_spellInfo->Id | (effIndex << 24)), m_caster, unitTarget);
}

void Spell::EffectSanctuary(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget)
        return;

    std::list<Unit*> targets;
    Trinity::AnyUnfriendlyUnitInObjectRangeCheck u_check(unitTarget, unitTarget, m_caster->GetMap()->GetVisibilityDistance());
    Trinity::UnitListSearcher<Trinity::AnyUnfriendlyUnitInObjectRangeCheck> searcher(unitTarget, targets, u_check);
    unitTarget->VisitNearbyObject(m_caster->GetMap()->GetVisibilityDistance(), searcher);
    for (std::list<Unit*>::iterator iter = targets.begin(); iter != targets.end(); ++iter)
    {
        if (!(*iter)->hasUnitState(UNIT_STAT_CASTING))
            continue;

        for (uint32 i = CURRENT_FIRST_NON_MELEE_SPELL; i < CURRENT_MAX_SPELL; i++)
        {
            if ((*iter)->GetCurrentSpell(i)
            && (*iter)->GetCurrentSpell(i)->m_targets.getUnitTargetGUID() == unitTarget->GetGUID())
            {
                (*iter)->InterruptSpell(CurrentSpellTypes(i), false);
            }
        }
    }

    unitTarget->CombatStop();
    unitTarget->getHostileRefManager().deleteReferences();   // stop all fighting
    // Vanish allows to remove all threat and cast regular stealth so other spells can be used
    if (m_caster->GetTypeId() == TYPEID_PLAYER
        && m_spellInfo->SpellFamilyName == SPELLFAMILY_ROGUE
        && (m_spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG_ROGUE_VANISH))
    {
        m_caster->ToPlayer()->RemoveAurasByType(SPELL_AURA_MOD_ROOT);
        // Overkill
        if (m_caster->ToPlayer()->HasSpell(58426))
           m_caster->CastSpell(m_caster, 58427, true);
    }
}

void Spell::EffectAddComboPoints(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget)
        return;

    if (!m_caster->m_movedPlayer)
        return;

    if (damage <= 0)
        return;

    m_caster->m_movedPlayer->AddComboPoints(unitTarget, damage, this);
}

void Spell::EffectDuel(SpellEffIndex effIndex)
{
    if (!m_caster || !unitTarget || m_caster->GetTypeId() != TYPEID_PLAYER || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player *caster = (Player*)m_caster;
    Player *target = (Player*)unitTarget;

    // caster or target already have requested duel
    if (caster->duel || target->duel || !target->GetSocial() || target->GetSocial()->HasIgnore(caster->GetGUIDLow()))
        return;

    // Players can only fight a duel with each other outside (=not inside dungeons and not in capital cities)
    // Don't have to check the target's map since you cannot challenge someone across maps
    if (caster->GetMap()->Instanceable())
    //if (mapid != 0 && mapid != 1 && mapid != 530 && mapid != 571 && mapid != 609)
    {
        SendCastResult(SPELL_FAILED_NO_DUELING);            // Dueling isn't allowed here
        return;
    }

    AreaTableEntry const* casterAreaEntry = GetAreaEntryByAreaID(caster->GetZoneId());
    if (casterAreaEntry && (casterAreaEntry->flags & AREA_FLAG_CAPITAL))
    {
        SendCastResult(SPELL_FAILED_NO_DUELING);            // Dueling isn't allowed here
        return;
    }

    AreaTableEntry const* targetAreaEntry = GetAreaEntryByAreaID(target->GetZoneId());
    if (targetAreaEntry && (targetAreaEntry->flags & AREA_FLAG_CAPITAL))
    {
        SendCastResult(SPELL_FAILED_NO_DUELING);            // Dueling isn't allowed here
        return;
    }

    //CREATE DUEL FLAG OBJECT
    GameObject* pGameObj = new GameObject;

    uint32 gameobject_id = m_spellInfo->EffectMiscValue[effIndex];

    Map *map = m_caster->GetMap();
    if (!pGameObj->Create(sObjectMgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT), gameobject_id,
        map, m_caster->GetPhaseMask(),
        m_caster->GetPositionX()+(unitTarget->GetPositionX()-m_caster->GetPositionX())/2 ,
        m_caster->GetPositionY()+(unitTarget->GetPositionY()-m_caster->GetPositionY())/2 ,
        m_caster->GetPositionZ(),
        m_caster->GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f, 0, GO_STATE_READY))
    {
        delete pGameObj;
        return;
    }

    pGameObj->SetUInt32Value(GAMEOBJECT_FACTION, m_caster->getFaction());
    pGameObj->SetUInt32Value(GAMEOBJECT_LEVEL, m_caster->getLevel()+1);
    int32 duration = GetSpellDuration(m_spellInfo);
    pGameObj->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
    pGameObj->SetSpellId(m_spellInfo->Id);

    ExecuteLogEffectSummonObject(effIndex, pGameObj);

    m_caster->AddGameObject(pGameObj);
    map->Add(pGameObj);
    //END

    // Send request
    WorldPacket data(SMSG_DUEL_REQUESTED, 8 + 8);
    data << uint64(pGameObj->GetGUID());
    data << uint64(caster->GetGUID());
    caster->GetSession()->SendPacket(&data);
    target->GetSession()->SendPacket(&data);

    // create duel-info
    DuelInfo *duel   = new DuelInfo;
    duel->initiator  = caster;
    duel->opponent   = target;
    duel->startTime  = 0;
    duel->startTimer = 0;
    caster->duel     = duel;

    DuelInfo *duel2   = new DuelInfo;
    duel2->initiator  = caster;
    duel2->opponent   = caster;
    duel2->startTime  = 0;
    duel2->startTimer = 0;
    target->duel      = duel2;

    caster->SetUInt64Value(PLAYER_DUEL_ARBITER, pGameObj->GetGUID());
    target->SetUInt64Value(PLAYER_DUEL_ARBITER, pGameObj->GetGUID());

    sScriptMgr.OnPlayerDuelRequest(target, caster);
}

void Spell::EffectStuck(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (!sWorld.getBoolConfig(CONFIG_CAST_UNSTUCK))
        return;

    Player* pTarget = (Player*)unitTarget;

    sLog.outDebug("Spell Effect: Stuck");
    sLog.outDetail("Player %s (guid %u) used auto-unstuck future at map %u (%f, %f, %f)", pTarget->GetName(), pTarget->GetGUIDLow(), m_caster->GetMapId(), m_caster->GetPositionX(), pTarget->GetPositionY(), pTarget->GetPositionZ());

    if (pTarget->isInFlight())
        return;

    pTarget->TeleportTo(pTarget->GetStartPosition(), unitTarget == m_caster ? TELE_TO_SPELL : 0);
    // homebind location is loaded always
    // pTarget->TeleportTo(pTarget->m_homebindMapId,pTarget->m_homebindX,pTarget->m_homebindY,pTarget->m_homebindZ,pTarget->GetOrientation(), (unitTarget == m_caster ? TELE_TO_SPELL : 0));

    // Stuck spell trigger Hearthstone cooldown
    SpellEntry const *spellInfo = sSpellStore.LookupEntry(8690);
    if (!spellInfo)
        return;
    Spell spell(pTarget, spellInfo, true, 0);
    spell.SendSpellCooldown();
}

void Spell::EffectSummonPlayer(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    // Evil Twin (ignore player summon, but hide this for summoner)
    if (unitTarget->HasAura(23445))
        return;

    float x, y, z;
    m_caster->GetClosePoint(x, y, z, unitTarget->GetObjectSize());

    unitTarget->ToPlayer()->SetSummonPoint(m_caster->GetMapId(),x,y,z);

    WorldPacket data(SMSG_SUMMON_REQUEST, 8+4+4);
    data << uint64(m_caster->GetGUID());                    // summoner guid
    data << uint32(m_caster->GetZoneId());                  // summoner zone
    data << uint32(MAX_PLAYER_SUMMON_DELAY*IN_MILLISECONDS); // auto decline after msecs
    unitTarget->ToPlayer()->GetSession()->SendPacket(&data);
}

static ScriptInfo generateActivateCommand()
{
    ScriptInfo si;
    si.command = SCRIPT_COMMAND_ACTIVATE_OBJECT;
    return si;
}

void Spell::EffectActivateObject(SpellEffIndex effIndex)
{
    if (!gameObjTarget)
        return;

    static ScriptInfo activateCommand = generateActivateCommand();

    int32 delay_secs = m_spellInfo->EffectMiscValue[effIndex];

    gameObjTarget->GetMap()->ScriptCommandStart(activateCommand, delay_secs, m_caster, gameObjTarget);
}

void Spell::EffectApplyGlyph(SpellEffIndex effIndex)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER || m_glyphIndex >= MAX_GLYPH_SLOT_INDEX)
        return;

    Player *player = (Player*)m_caster;

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
    if (minLevel && m_caster->getLevel() < minLevel)
    {
        SendCastResult(SPELL_FAILED_GLYPH_SOCKET_LOCKED);
        return;
    }

    // apply new one
    if (uint32 glyph = m_spellInfo->EffectMiscValue[effIndex])
    {
        if (GlyphPropertiesEntry const *gp = sGlyphPropertiesStore.LookupEntry(glyph))
        {
            if (GlyphSlotEntry const *gs = sGlyphSlotStore.LookupEntry(player->GetGlyphSlot(m_glyphIndex)))
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
                if (GlyphPropertiesEntry const *old_gp = sGlyphPropertiesStore.LookupEntry(oldglyph))
                {
                    player->RemoveAurasDueToSpell(old_gp->SpellId);
                    player->SetGlyph(m_glyphIndex, 0);
                }
            }

            player->CastSpell(m_caster, gp->SpellId, true);
            player->SetGlyph(m_glyphIndex, glyph);
            player->SendTalentsInfoData(false);
        }
    }
}

void Spell::EffectEnchantHeldItem(SpellEffIndex effIndex)
{
    // this is only item spell effect applied to main-hand weapon of target player (players in area)
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* item_owner = (Player*)unitTarget;
    Item* item = item_owner->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

    if (!item)
        return;

    // must be equipped
    if (!item ->IsEquipped())
        return;

    if (m_spellInfo->EffectMiscValue[effIndex])
    {
        uint32 enchant_id = m_spellInfo->EffectMiscValue[effIndex];
        int32 duration = GetSpellDuration(m_spellInfo);          //Try duration index first ..
        if (!duration)
            duration = damage;//+1;            //Base points after ..
        if (!duration)
            duration = 10;                                  //10 seconds for enchants which don't have listed duration

        SpellItemEnchantmentEntry const *pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
        if (!pEnchant)
            return;

        // Always go to temp enchantment slot
        EnchantmentSlot slot = TEMP_ENCHANTMENT_SLOT;

        // Enchantment will not be applied if a different one already exists
        if (item->GetEnchantmentId(slot) && item->GetEnchantmentId(slot) != enchant_id)
            return;

        // Apply the temporary enchantment
        item->SetEnchantment(slot, enchant_id, duration*IN_MILLISECONDS, 0);
        item_owner->ApplyEnchantment(item, slot, true);
    }
}

void Spell::EffectDisEnchant(SpellEffIndex /*effIndex*/)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* p_caster = (Player*)m_caster;
    if (!itemTarget || !itemTarget->GetProto()->DisenchantID)
        return;

    p_caster->UpdateCraftSkill(m_spellInfo->Id);

    m_caster->ToPlayer()->SendLoot(itemTarget->GetGUID(),LOOT_DISENCHANTING);

    // item will be removed at disenchanting end
}

void Spell::EffectInebriate(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player *player = (Player*)unitTarget;
    uint16 currentDrunk = player->GetDrunkValue();
    uint16 drunkMod = damage * 256;
    if (currentDrunk + drunkMod > 0xFFFF)
        currentDrunk = 0xFFFF;
    else
        currentDrunk += drunkMod;
    player->SetDrunkValue(currentDrunk, m_CastItem ? m_CastItem->GetEntry() : 0);
}

void Spell::EffectFeedPet(SpellEffIndex effIndex)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player *_player = (Player*)m_caster;

    Item* foodItem = m_targets.getItemTarget();
    if (!foodItem)
        return;

    Pet *pet = _player->GetPet();
    if (!pet)
        return;

    if (!pet->isAlive())
        return;

    int32 benefit = pet->GetCurrentFoodBenefitLevel(foodItem->GetProto()->ItemLevel);
    if (benefit <= 0)
        return;

    ExecuteLogEffectDestroyItem(effIndex, foodItem->GetEntry());

    uint32 count = 1;
    _player->DestroyItemCount(foodItem, count, true);
    // TODO: fix crash when a spell has two effects, both pointed at the same item target

    m_caster->CastCustomSpell(pet, m_spellInfo->EffectTriggerSpell[effIndex], &benefit, NULL, NULL, true);
}

void Spell::EffectDismissPet(SpellEffIndex effIndex)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Pet* pet = m_caster->ToPlayer()->GetPet();

    // not let dismiss dead pet
    if (!pet||!pet->isAlive())
        return;

    ExecuteLogEffectUnsummonObject(effIndex, pet);
    m_caster->ToPlayer()->RemovePet(pet, PET_SAVE_NOT_IN_SLOT);
}

void Spell::EffectSummonObject(SpellEffIndex effIndex)
{
    uint32 go_id = m_spellInfo->EffectMiscValue[effIndex];

    uint8 slot = 0;
    switch(m_spellInfo->Effect[effIndex])
    {
        case SPELL_EFFECT_SUMMON_OBJECT_SLOT1: slot = 0; break;
        case SPELL_EFFECT_SUMMON_OBJECT_SLOT2: slot = 1; break;
        case SPELL_EFFECT_SUMMON_OBJECT_SLOT3: slot = 2; break;
        case SPELL_EFFECT_SUMMON_OBJECT_SLOT4: slot = 3; break;
        default: return;
    }

    uint64 guid = m_caster->m_ObjectSlot[slot];
    if (guid != 0)
    {
        GameObject* obj = NULL;
        if (m_caster)
            obj = m_caster->GetMap()->GetGameObject(guid);

        if (obj)
        {
            // Recast case - null spell id to make auras not be removed on object remove from world
            if (m_spellInfo->Id == obj->GetSpellId())
                obj->SetSpellId(0);
            m_caster->RemoveGameObject(obj, true);
        }
        m_caster->m_ObjectSlot[slot] = 0;
    }

    GameObject* pGameObj = new GameObject;

    float x, y, z;
    // If dest location if present
    if (m_targets.HasDst())
        m_targets.m_dstPos.GetPosition(x, y, z);
    // Summon in random point all other units if location present
    else
        m_caster->GetClosePoint(x, y, z, DEFAULT_WORLD_OBJECT_SIZE);

    Map *map = m_caster->GetMap();
    if (!pGameObj->Create(sObjectMgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT), go_id, map,
        m_caster->GetPhaseMask(), x, y, z, m_caster->GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f, 0, GO_STATE_READY))
    {
        delete pGameObj;
        return;
    }

    //pGameObj->SetUInt32Value(GAMEOBJECT_LEVEL,m_caster->getLevel());
    int32 duration = GetSpellDuration(m_spellInfo);
    pGameObj->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
    pGameObj->SetSpellId(m_spellInfo->Id);
    m_caster->AddGameObject(pGameObj);

    ExecuteLogEffectSummonObject(effIndex, pGameObj);

    map->Add(pGameObj);

    m_caster->m_ObjectSlot[slot] = pGameObj->GetGUID();
}

void Spell::EffectResurrect(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;
    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (unitTarget->isAlive())
        return;
    if (!unitTarget->IsInWorld())
        return;

    switch (m_spellInfo->Id)
    {
        // Defibrillate (Goblin Jumper Cables) have 33% chance on success
        case 8342:
            if (roll_chance_i(67))
            {
                m_caster->CastSpell(m_caster, 8338, true, m_CastItem);
                return;
            }
            break;
        // Defibrillate (Goblin Jumper Cables XL) have 50% chance on success
        case 22999:
            if (roll_chance_i(50))
            {
                m_caster->CastSpell(m_caster, 23055, true, m_CastItem);
                return;
            }
            break;
        // Defibrillate ( Gnomish Army Knife) have 67% chance on success_list
        case 54732:
            if (roll_chance_i(33))
            {
                return;
            }
            break;
        default:
            break;
    }

    Player* pTarget = unitTarget->ToPlayer();

    if (pTarget->isRessurectRequested())       // already have one active request
        return;

    uint32 health = pTarget->CountPctFromMaxHealth(damage);
    uint32 mana   = pTarget->GetMaxPower(POWER_MANA) * damage / 100;

    ExecuteLogEffectResurrect(effIndex, pTarget);

    pTarget->setResurrectRequestData(m_caster->GetGUID(), m_caster->GetMapId(), m_caster->GetPositionX(), m_caster->GetPositionY(), m_caster->GetPositionZ(), health, mana);
    SendResurrectRequest(pTarget);
}

void Spell::EffectAddExtraAttacks(SpellEffIndex effIndex)
{
    if (!unitTarget || !unitTarget->isAlive() || !unitTarget->getVictim())
        return;

    if (unitTarget->m_extraAttacks)
        return;

    unitTarget->m_extraAttacks = damage;

    ExecuteLogEffectExtraAttacks(effIndex, unitTarget->getVictim(), damage);
}

void Spell::EffectParry(SpellEffIndex /*effIndex*/)
{
    if (unitTarget && unitTarget->GetTypeId() == TYPEID_PLAYER)
        unitTarget->ToPlayer()->SetCanParry(true);
}

void Spell::EffectBlock(SpellEffIndex /*effIndex*/)
{
    if (unitTarget && unitTarget->GetTypeId() == TYPEID_PLAYER)
        unitTarget->ToPlayer()->SetCanBlock(true);
}

void Spell::EffectLeap(SpellEffIndex /*effIndex*/)
{
    if (unitTarget->isInFlight())
        return;

    if (!m_targets.HasDst())
        return;

    unitTarget->NearTeleportTo(m_targets.m_dstPos.GetPositionX(), m_targets.m_dstPos.GetPositionY(), m_targets.m_dstPos.GetPositionZ(), m_targets.m_dstPos.GetOrientation(), unitTarget == m_caster);
}

void Spell::EffectReputation(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player *_player = (Player*)unitTarget;

    int32  rep_change = damage;//+1;           // field store reputation change -1

    uint32 faction_id = m_spellInfo->EffectMiscValue[effIndex];

    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction_id);

    if (!factionEntry)
        return;

    if (RepRewardRate const * repData = sObjectMgr.GetRepRewardRate(faction_id))
    {
        rep_change = int32((float)rep_change * repData->spell_rate);
    }

    _player->GetReputationMgr().ModifyReputation(factionEntry, rep_change);
}

void Spell::EffectQuestComplete(SpellEffIndex effIndex)
{
    Player *pPlayer;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        pPlayer = (Player*)m_caster;
    else if (unitTarget && unitTarget->GetTypeId() == TYPEID_PLAYER)
        pPlayer = (Player*)unitTarget;
    else
        return;

    uint32 quest_id = m_spellInfo->EffectMiscValue[effIndex];
    if (quest_id)
    {
        uint16 log_slot = pPlayer->FindQuestSlot(quest_id);
        if (log_slot < MAX_QUEST_LOG_SIZE)
            pPlayer->AreaExploredOrEventHappens(quest_id);
        else if (!pPlayer->GetQuestRewardStatus(quest_id))   // never rewarded before
            pPlayer->CompleteQuest(quest_id);   // quest not in log - for internal use
    }
}

void Spell::EffectForceDeselect(SpellEffIndex /*effIndex*/)
{
    WorldPacket data(SMSG_CLEAR_TARGET, 8);
    data << uint64(m_caster->GetGUID());
    m_caster->SendMessageToSet(&data, true);
}

void Spell::EffectSelfResurrect(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->isAlive())
        return;
    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    if (!unitTarget->IsInWorld())
        return;

    uint32 health = 0;
    uint32 mana = 0;

    // flat case
    if (damage < 0)
    {
        health = uint32(-damage);
        mana = m_spellInfo->EffectMiscValue[effIndex];
    }
    // percent case
    else
    {
        health = unitTarget->CountPctFromMaxHealth(damage);
        if (unitTarget->GetMaxPower(POWER_MANA) > 0)
            mana = uint32(damage/100.0f*unitTarget->GetMaxPower(POWER_MANA));
    }

    Player *plr = unitTarget->ToPlayer();
    plr->ResurrectPlayer(0.0f);

    plr->SetHealth(health);
    plr->SetPower(POWER_MANA, mana);
    plr->SetPower(POWER_RAGE, 0);
    plr->SetPower(POWER_ENERGY, plr->GetMaxPower(POWER_ENERGY));

    plr->SpawnCorpseBones();
}

void Spell::EffectSkinning(SpellEffIndex /*effIndex*/)
{
    if (unitTarget->GetTypeId() != TYPEID_UNIT)
        return;
    if (!m_caster || m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Creature* creature = unitTarget->ToCreature();
    int32 targetLevel = creature->getLevel();

    uint32 skill = creature->GetCreatureInfo()->GetRequiredLootSkill();

    m_caster->ToPlayer()->SendLoot(creature->GetGUID(),LOOT_SKINNING);
    creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);

    int32 reqValue = targetLevel < 10 ? 0 : targetLevel < 20 ? (targetLevel-10)*10 : targetLevel*5;

    int32 skillValue = m_caster->ToPlayer()->GetPureSkillValue(skill);

    // Double chances for elites
    m_caster->ToPlayer()->UpdateGatherSkill(skill, skillValue, reqValue, creature->isElite() ? 2 : 1);
}

void Spell::EffectCharge(SpellEffIndex /*effIndex*/)
{
    Unit *target = m_targets.getUnitTarget();
    if (!target)
        return;

    float x, y, z;
    target->GetContactPoint(m_caster, x, y, z);
    m_caster->GetMotionMaster()->MoveCharge(x, y, z);

    // not all charge effects used in negative spells
    if (!IsPositiveSpell(m_spellInfo->Id) && m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->Attack(target, true);
}

void Spell::EffectChargeDest(SpellEffIndex /*effIndex*/)
{
    if (m_targets.HasDst())
    {
        float x, y, z;
        m_targets.m_dstPos.GetPosition(x, y, z);
        m_caster->GetMotionMaster()->MoveCharge(x, y, z);
    }
}

void Spell::EffectKnockBack(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;

    // Instantly interrupt non melee spells being casted
    if (unitTarget->IsNonMeleeSpellCasted(true))
        unitTarget->InterruptNonMeleeSpells(true);

    // Typhoon
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_DRUID && m_spellInfo->SpellFamilyFlags[1] & 0x01000000)
    {
        // Glyph of Typhoon
        if (m_caster->HasAura(62135))
            return;
    }

    // Thunderstorm
    if (m_spellInfo->SpellFamilyName == SPELLFAMILY_SHAMAN && m_spellInfo->SpellFamilyFlags[1] & 0x00002000)
    {
        // Glyph of Thunderstorm
        if (m_caster->HasAura(62132))
            return;
    }

    float ratio = m_caster->GetCombatReach() / std::max(unitTarget->GetCombatReach(), 1.0f);
    if (ratio < 1.0f)
        ratio = ratio * ratio * ratio * 0.1f; // volume = length^3
    else
        ratio = 0.1f; // dbc value ratio
    float speedxy = float(m_spellInfo->EffectMiscValue[effIndex]) * ratio;
    float speedz = float(damage) * ratio;
    if (speedxy < 0.1f && speedz < 0.1f)
        return;

    float x, y;
    if (m_spellInfo->Effect[effIndex] == SPELL_EFFECT_KNOCK_BACK_DEST)
    {
        if (m_targets.HasDst())
            m_targets.m_dstPos.GetPosition(x, y);
        else
            return;
    }
    else //if (m_spellInfo->Effect[i] == SPELL_EFFECT_KNOCK_BACK)
    {
        m_caster->GetPosition(x, y);
    }

    unitTarget->KnockbackFrom(x, y, speedxy, speedz);
}

void Spell::EffectLeapBack(SpellEffIndex effIndex)
{
    float speedxy = float(m_spellInfo->EffectMiscValue[effIndex])/10;
    float speedz = float(damage/10);
    if (!speedxy)
    {
        if (m_targets.getUnitTarget())
            m_caster->JumpTo(m_targets.getUnitTarget(), speedz);
    }
    else
    {
        //1891: Disengage
        m_caster->JumpTo(speedxy, speedz, m_spellInfo->SpellIconID != 1891);
    }
}

void Spell::EffectQuestClear(SpellEffIndex effIndex)
{
    Player *pPlayer = NULL;
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        pPlayer = m_caster->ToPlayer();
    else if (unitTarget && unitTarget->GetTypeId() == TYPEID_PLAYER)
        pPlayer = unitTarget->ToPlayer();

    if (!pPlayer)
        return;

    uint32 quest_id = m_spellInfo->EffectMiscValue[effIndex];

    Quest const* pQuest = sObjectMgr.GetQuestTemplate(quest_id);

    if (!pQuest)
        return;

    QuestStatusMap::iterator qs_itr = pPlayer->getQuestStatusMap().find(quest_id);
    // Player has never done this quest
    if (qs_itr == pPlayer->getQuestStatusMap().end())
        return;

    // remove all quest entries for 'entry' from quest log
    for (uint8 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
    {
        uint32 quest = pPlayer->GetQuestSlotQuestId(slot);
        if (quest == quest_id)
        {
            pPlayer->SetQuestSlot(slot, 0);

            // we ignore unequippable quest items in this case, its' still be equipped
            pPlayer->TakeQuestSourceItem(quest, false);
        }
    }

    // set quest status to not started (will be updated in DB at next save)
    pPlayer->SetQuestStatus(quest_id, QUEST_STATUS_NONE);

    // reset rewarded for restart repeatable quest
    QuestStatusData &data = qs_itr->second;
    data.m_rewarded = false;
}

void Spell::EffectSendTaxi(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->ActivateTaxiPathTo(m_spellInfo->EffectMiscValue[effIndex],m_spellInfo->Id);
}

void Spell::EffectPullTowards(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;

    float speedZ = (float)(SpellMgr::CalculateSpellEffectAmount(m_spellInfo, effIndex) / 10);
    float speedXY = (float)(m_spellInfo->EffectMiscValue[effIndex]/10);
    Position pos;
    if (m_spellInfo->Effect[effIndex] == SPELL_EFFECT_PULL_TOWARDS_DEST)
    {
        if (m_targets.HasDst())
            pos.Relocate(m_targets.m_dstPos);
        else
            return;
    }
    else //if (m_spellInfo->Effect[i] == SPELL_EFFECT_PULL_TOWARDS)
    {
        pos.Relocate(m_caster);
    }

    unitTarget->GetMotionMaster()->MoveJump(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), speedXY, speedZ);
}

void Spell::EffectDispelMechanic(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;

    uint32 mechanic = m_spellInfo->EffectMiscValue[effIndex];

    std::queue < std::pair < uint32, uint64 > > dispel_list;

    Unit::AuraMap const& auras = unitTarget->GetOwnedAuras();
    for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
    {
        Aura * aura = itr->second;
        if (!aura->GetApplicationOfTarget(unitTarget->GetGUID()))
            continue;
        bool success = false;
        GetDispelChance(aura->GetCaster(), unitTarget, aura->GetId(), !unitTarget->IsFriendlyTo(m_caster), &success);
        if ((GetAllSpellMechanicMask(aura->GetSpellProto()) & (1 << mechanic)) && success)
            dispel_list.push(std::make_pair(aura->GetId(), aura->GetCasterGUID()));
    }

    for (; dispel_list.size(); dispel_list.pop())
    {
        unitTarget->RemoveAura(dispel_list.front().first, dispel_list.front().second, 0, AURA_REMOVE_BY_ENEMY_SPELL);
    }
}

void Spell::EffectSummonDeadPet(SpellEffIndex /*effIndex*/)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;
    Player *_player = (Player*)m_caster;
    Pet *pet = _player->GetPet();
    if (!pet)
        return;
    if (pet->isAlive())
        return;
    if (damage < 0)
        return;

    float x,y,z;
    _player->GetPosition(x, y, z);
    _player->GetMap()->CreatureRelocation(pet, x, y, z, _player->GetOrientation());

    pet->SetUInt32Value(UNIT_DYNAMIC_FLAGS, 0);
    pet->RemoveFlag (UNIT_FIELD_FLAGS, UNIT_FLAG_SKINNABLE);
    pet->setDeathState(ALIVE);
    pet->clearUnitState(UNIT_STAT_ALL_STATE);
    pet->SetHealth(pet->CountPctFromMaxHealth(damage));

    //pet->AIM_Initialize();
    //_player->PetSpellInitialize();
    pet->SavePetToDB(PET_SAVE_AS_CURRENT);
}

void Spell::EffectDestroyAllTotems(SpellEffIndex /*effIndex*/)
{
    int32 mana = 0;
    for (uint8 slot = SUMMON_SLOT_TOTEM; slot < MAX_TOTEM_SLOT; ++slot)
    {
        if (!m_caster->m_SummonSlot[slot])
            continue;

        Creature* totem = m_caster->GetMap()->GetCreature(m_caster->m_SummonSlot[slot]);
        if (totem && totem->isTotem())
        {
            uint32 spell_id = totem->GetUInt32Value(UNIT_CREATED_BY_SPELL);
            SpellEntry const* spellInfo = sSpellStore.LookupEntry(spell_id);
            if (spellInfo)
            {
                mana += spellInfo->manaCost;
                mana += spellInfo->ManaCostPercentage * m_caster->GetCreateMana() / 100;
            }
            totem->ToTotem()->UnSummon();
        }
    }
    mana = mana * damage / 100;

    if (mana)
        m_caster->CastCustomSpell(m_caster, 39104, &mana, NULL, NULL, true);
}

void Spell::EffectDurabilityDamage(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    int32 slot = m_spellInfo->EffectMiscValue[effIndex];

    // FIXME: some spells effects have value -1/-2
    // Possibly its mean -1 all player equipped items and -2 all items
    if (slot < 0)
    {
        unitTarget->ToPlayer()->DurabilityPointsLossAll(damage, (slot < -1));
        return;
    }

    // invalid slot value
    if (slot >= INVENTORY_SLOT_BAG_END)
        return;

    if (Item* item = unitTarget->ToPlayer()->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
        unitTarget->ToPlayer()->DurabilityPointsLoss(item, damage);

    ExecuteLogEffectDurabilityDamage(effIndex, unitTarget, slot, damage);
}

void Spell::EffectDurabilityDamagePCT(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    int32 slot = m_spellInfo->EffectMiscValue[effIndex];

    // FIXME: some spells effects have value -1/-2
    // Possibly its mean -1 all player equipped items and -2 all items
    if (slot < 0)
    {
        unitTarget->ToPlayer()->DurabilityLossAll(double(damage)/100.0f, (slot < -1));
        return;
    }

    // invalid slot value
    if (slot >= INVENTORY_SLOT_BAG_END)
        return;

    if (damage <= 0)
        return;

    if (Item* item = unitTarget->ToPlayer()->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
        unitTarget->ToPlayer()->DurabilityLoss(item, double(damage)/100.0f);
}

void Spell::EffectModifyThreatPercent(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget)
        return;

    unitTarget->getThreatManager().modifyThreatPercent(m_caster, damage);
}

void Spell::EffectTransmitted(SpellEffIndex effIndex)
{
    uint32 name_id = m_spellInfo->EffectMiscValue[effIndex];

    GameObjectInfo const* goinfo = sObjectMgr.GetGameObjectInfo(name_id);

    if (!goinfo)
    {
        sLog.outErrorDb("Gameobject (Entry: %u) not exist and not created at spell (ID: %u) cast",name_id, m_spellInfo->Id);
        return;
    }

    float fx, fy, fz;

    if (m_targets.HasDst())
        m_targets.m_dstPos.GetPosition(fx, fy, fz);
    //FIXME: this can be better check for most objects but still hack
    else if (m_spellInfo->EffectRadiusIndex[effIndex] && m_spellInfo->speed == 0)
    {
        float dis = GetSpellRadiusForFriend(sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[effIndex]));
        m_caster->GetClosePoint(fx, fy, fz, DEFAULT_WORLD_OBJECT_SIZE, dis);
    }
    else
    {
        //GO is always friendly to it's creator, get range for friends
        float min_dis = GetSpellMinRangeForFriend(sSpellRangeStore.LookupEntry(m_spellInfo->rangeIndex));
        float max_dis = GetSpellMaxRangeForFriend(sSpellRangeStore.LookupEntry(m_spellInfo->rangeIndex));
        float dis = (float)rand_norm() * (max_dis - min_dis) + min_dis;

        m_caster->GetClosePoint(fx, fy, fz, DEFAULT_WORLD_OBJECT_SIZE, dis);
    }

    Map *cMap = m_caster->GetMap();
    if (goinfo->type == GAMEOBJECT_TYPE_FISHINGNODE)
    {
        LiquidData liqData;
        if ( !cMap->IsInWater(fx, fy, fz + 1.f/* -0.5f */, &liqData))             // Hack to prevent fishing bobber from failing to land on fishing hole
        { // but this is not proper, we really need to ignore not materialized objects
            SendCastResult(SPELL_FAILED_NOT_HERE);
            SendChannelUpdate(0);
            return;
        }

        // replace by water level in this case
        //fz = cMap->GetWaterLevel(fx, fy);
        fz = liqData.level;
    }
    // if gameobject is summoning object, it should be spawned right on caster's position
    else if (goinfo->type == GAMEOBJECT_TYPE_SUMMONING_RITUAL)
    {
        m_caster->GetPosition(fx, fy, fz);
    }

    GameObject* pGameObj = new GameObject;

    if (!pGameObj->Create(sObjectMgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT), name_id, cMap,
        m_caster->GetPhaseMask(), fx, fy, fz, m_caster->GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f, 100, GO_STATE_READY))
    {
        delete pGameObj;
        return;
    }

    int32 duration = GetSpellDuration(m_spellInfo);

    switch(goinfo->type)
    {
        case GAMEOBJECT_TYPE_FISHINGNODE:
        {
            m_caster->SetUInt64Value(UNIT_FIELD_CHANNEL_OBJECT,pGameObj->GetGUID());
            m_caster->AddGameObject(pGameObj);              // will removed at spell cancel

            // end time of range when possible catch fish (FISHING_BOBBER_READY_TIME..GetDuration(m_spellInfo))
            // start time == fish-FISHING_BOBBER_READY_TIME (0..GetDuration(m_spellInfo)-FISHING_BOBBER_READY_TIME)
            int32 lastSec = 0;
            switch(urand(0, 3))
            {
                case 0: lastSec =  3; break;
                case 1: lastSec =  7; break;
                case 2: lastSec = 13; break;
                case 3: lastSec = 17; break;
            }

            duration = duration - lastSec*IN_MILLISECONDS + FISHING_BOBBER_READY_TIME*IN_MILLISECONDS;
            break;
        }
        case GAMEOBJECT_TYPE_SUMMONING_RITUAL:
        {
            if (m_caster->GetTypeId() == TYPEID_PLAYER)
            {
          pGameObj->AddUniqueUse(m_caster->ToPlayer());
          m_caster->AddGameObject(pGameObj);          // will removed at spell cancel
            }
            break;
        }
        case GAMEOBJECT_TYPE_DUEL_ARBITER: // 52991
            m_caster->AddGameObject(pGameObj);
            break;
        case GAMEOBJECT_TYPE_FISHINGHOLE:
        case GAMEOBJECT_TYPE_CHEST:
        default:
            break;
    }

    pGameObj->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);

    pGameObj->SetOwnerGUID(m_caster->GetGUID());

    //pGameObj->SetUInt32Value(GAMEOBJECT_LEVEL, m_caster->getLevel());
    pGameObj->SetSpellId(m_spellInfo->Id);

    ExecuteLogEffectSummonObject(effIndex, pGameObj);

    sLog.outStaticDebug("AddObject at SpellEfects.cpp EffectTransmitted");
    //m_caster->AddGameObject(pGameObj);
    //m_ObjToDel.push_back(pGameObj);

    cMap->Add(pGameObj);

    if (uint32 linkedEntry = pGameObj->GetGOInfo()->GetLinkedGameObjectEntry())
    {
        GameObject* linkedGO = new GameObject;
        if (linkedGO->Create(sObjectMgr.GenerateLowGuid(HIGHGUID_GAMEOBJECT), linkedEntry, cMap,
            m_caster->GetPhaseMask(), fx, fy, fz, m_caster->GetOrientation(), 0.0f, 0.0f, 0.0f, 0.0f, 100, GO_STATE_READY))
        {
            linkedGO->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
            //linkedGO->SetUInt32Value(GAMEOBJECT_LEVEL, m_caster->getLevel());
            linkedGO->SetSpellId(m_spellInfo->Id);
            linkedGO->SetOwnerGUID(m_caster->GetGUID());

            ExecuteLogEffectSummonObject(effIndex, linkedGO);

            linkedGO->GetMap()->Add(linkedGO);
        }
        else
        {
            delete linkedGO;
            linkedGO = NULL;
            return;
        }
    }
}

void Spell::EffectProspecting(SpellEffIndex /*effIndex*/)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* p_caster = (Player*)m_caster;
    if (!itemTarget || !(itemTarget->GetProto()->Flags & ITEM_PROTO_FLAG_PROSPECTABLE))
        return;

    if (itemTarget->GetCount() < 5)
        return;

    if (sWorld.getBoolConfig(CONFIG_SKILL_PROSPECTING))
    {
        uint32 SkillValue = p_caster->GetPureSkillValue(SKILL_JEWELCRAFTING);
        uint32 reqSkillValue = itemTarget->GetProto()->RequiredSkillRank;
        p_caster->UpdateGatherSkill(SKILL_JEWELCRAFTING, SkillValue, reqSkillValue);
    }

    m_caster->ToPlayer()->SendLoot(itemTarget->GetGUID(), LOOT_PROSPECTING);
}

void Spell::EffectMilling(SpellEffIndex /*effIndex*/)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* p_caster = (Player*)m_caster;
    if (!itemTarget || !(itemTarget->GetProto()->Flags & ITEM_PROTO_FLAG_MILLABLE))
        return;

    if (itemTarget->GetCount() < 5)
        return;

    if (sWorld.getBoolConfig(CONFIG_SKILL_MILLING))
    {
        uint32 SkillValue = p_caster->GetPureSkillValue(SKILL_INSCRIPTION);
        uint32 reqSkillValue = itemTarget->GetProto()->RequiredSkillRank;
        p_caster->UpdateGatherSkill(SKILL_INSCRIPTION, SkillValue, reqSkillValue);
    }

    m_caster->ToPlayer()->SendLoot(itemTarget->GetGUID(), LOOT_MILLING);
}

void Spell::EffectSkill(SpellEffIndex /*effIndex*/)
{
    sLog.outDebug("WORLD: SkillEFFECT");
}

/* There is currently no need for this effect. We handle it in Battleground.cpp
   If we would handle the resurrection here, the spiritguide would instantly disappear as the
   player revives, and so we wouldn't see the spirit heal visual effect on the npc.
   This is why we use a half sec delay between the visual effect and the resurrection itself */
void Spell::EffectSpiritHeal(SpellEffIndex /*effIndex*/)
{
    /*
    if (!unitTarget || unitTarget->isAlive())
        return;
    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    if (!unitTarget->IsInWorld())
        return;

    //m_spellInfo->EffectBasePoints[i]; == 99 (percent?)
    //unitTarget->ToPlayer()->setResurrect(m_caster->GetGUID(), unitTarget->GetPositionX(), unitTarget->GetPositionY(), unitTarget->GetPositionZ(), unitTarget->GetMaxHealth(), unitTarget->GetMaxPower(POWER_MANA));
    unitTarget->ToPlayer()->ResurrectPlayer(1.0f);
    unitTarget->ToPlayer()->SpawnCorpseBones();
    */
}

// remove insignia spell effect
void Spell::EffectSkinPlayerCorpse(SpellEffIndex /*effIndex*/)
{
    sLog.outDebug("Effect: SkinPlayerCorpse");
    if ((m_caster->GetTypeId() != TYPEID_PLAYER) || (unitTarget->GetTypeId() != TYPEID_PLAYER) || (unitTarget->isAlive()))
        return;

    unitTarget->ToPlayer()->RemovedInsignia((Player*)m_caster);
}

void Spell::EffectStealBeneficialBuff(SpellEffIndex effIndex)
{
    sLog.outDebug("Effect: StealBeneficialBuff");

    if (!unitTarget || unitTarget == m_caster)                 // can't steal from self
        return;

    DispelChargesList steal_list;

    // Create dispel mask by dispel type
    uint32 dispelMask  = GetDispellMask(DispelType(m_spellInfo->EffectMiscValue[effIndex]));
    Unit::AuraMap const& auras = unitTarget->GetOwnedAuras();
    for (Unit::AuraMap::const_iterator itr = auras.begin(); itr != auras.end(); ++itr)
    {
        Aura * aura = itr->second;
        AuraApplication * aurApp = aura->GetApplicationOfTarget(unitTarget->GetGUID());
        if (!aurApp)
            continue;

        if ((1<<aura->GetSpellProto()->Dispel) & dispelMask)
        {
            // Need check for passive? this
            if (!aurApp->IsPositive() || aura->IsPassive() || aura->GetSpellProto()->AttributesEx4 & SPELL_ATTR_EX4_NOT_STEALABLE)
                continue;

            // The charges / stack amounts don't count towards the total number of auras that can be dispelled.
            // Ie: A dispel on a target with 5 stacks of Winters Chill and a Polymorph has 1 / (1 + 1) -> 50% chance to dispell
            // Polymorph instead of 1 / (5 + 1) -> 16%.
            bool dispel_charges = aura->GetSpellProto()->AttributesEx7 & SPELL_ATTR_EX7_DISPEL_CHARGES;
            uint8 charges = dispel_charges ? aura->GetCharges() : aura->GetStackAmount();
            if (charges > 0)
                steal_list.push_back(std::make_pair(aura, charges));
        }
    }

    if (steal_list.empty())
        return;

    // Ok if exist some buffs for dispel try dispel it
    uint32 failCount = 0;
    DispelList success_list;
    WorldPacket dataFail(SMSG_DISPEL_FAILED, 8+8+4+4+damage*4);
    // dispel N = damage buffs (or while exist buffs for dispel)
    for (int32 count = 0; count < damage && !steal_list.empty();)
    {
        // Random select buff for dispel
        DispelChargesList::iterator itr = steal_list.begin();
        std::advance(itr, urand(0, steal_list.size() - 1));

        bool success = false;
        // 2.4.3 Patch Notes: "Dispel effects will no longer attempt to remove effects that have 100% dispel resistance."
        if (!GetDispelChance(itr->first->GetCaster(), unitTarget, itr->first->GetId(), !unitTarget->IsFriendlyTo(m_caster), &success))
        {
            steal_list.erase(itr);
            continue;
        }
        else
        {
            if (success)
            {
                success_list.push_back(std::make_pair(itr->first->GetId(), itr->first->GetCasterGUID()));
                --itr->second;
                if (itr->second <= 0)
                    steal_list.erase(itr);
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
                dataFail << uint32(itr->first->GetId());                         // Spell Id
            }
            ++count;
        }
    }

    if (failCount)
        m_caster->SendMessageToSet(&dataFail, true);

    if (success_list.empty())
        return;

    WorldPacket dataSuccess(SMSG_SPELLSTEALLOG, 8+8+4+1+4+damage*5);
    dataSuccess.append(unitTarget->GetPackGUID());  // Victim GUID
    dataSuccess.append(m_caster->GetPackGUID());    // Caster GUID
    dataSuccess << uint32(m_spellInfo->Id);         // dispel spell id
    dataSuccess << uint8(0);                        // not used
    dataSuccess << uint32(success_list.size());     // count
    for (DispelList::iterator itr = success_list.begin(); itr!=success_list.end(); ++itr)
    {
        dataSuccess << uint32(itr->first);          // Spell Id
        dataSuccess << uint8(0);                    // 0 - steals !=0 transfers
        unitTarget->RemoveAurasDueToSpellBySteal(itr->first, itr->second, m_caster);
    }
    m_caster->SendMessageToSet(&dataSuccess, true);
}

void Spell::EffectKillCreditPersonal(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->KilledMonsterCredit(m_spellInfo->EffectMiscValue[effIndex], 0);
}

void Spell::EffectKillCredit(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    int32 creatureEntry = m_spellInfo->EffectMiscValue[effIndex];
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
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->FailQuest(m_spellInfo->EffectMiscValue[effIndex]);
}

void Spell::EffectQuestStart(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player * player = unitTarget->ToPlayer();
    if (Quest const* qInfo = sObjectMgr.GetQuestTemplate(m_spellInfo->EffectMiscValue[effIndex]))
    {
        if (player->CanTakeQuest(qInfo, false) && player->CanAddQuest(qInfo, false))
        {
            player->AddQuest(qInfo, NULL);
        }
    }
}

void Spell::EffectActivateRune(SpellEffIndex effIndex)
{
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player *plr = (Player*)m_caster;

    if (plr->getClass() != CLASS_DEATH_KNIGHT)
        return;

    // needed later
    m_runesState = m_caster->ToPlayer()->GetRunesState();

    uint32 count = damage;
    if (count == 0) count = 1;
    for (uint32 j = 0; j < MAX_RUNES && count > 0; ++j)
    {
        if (plr->GetRuneCooldown(j) && plr->GetCurrentRune(j) == RuneType(m_spellInfo->EffectMiscValue[effIndex]))
        {
            plr->SetRuneCooldown(j, 0);
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
            if (plr->GetRuneCooldown(i) && (plr->GetCurrentRune(i) == RUNE_FROST ||  plr->GetCurrentRune(i) == RUNE_DEATH))
                plr->SetRuneCooldown(i, 0);
        }
    }
}

void Spell::EffectCreateTamedPet(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER || unitTarget->GetPetGUID() || unitTarget->getClass() != CLASS_HUNTER)
        return;

    uint32 creatureEntry = m_spellInfo->EffectMiscValue[effIndex];
    Pet * pet = unitTarget->CreateTamedPetFrom(creatureEntry, m_spellInfo->Id);
    if (!pet)
        return;

    // add to world
    pet->GetMap()->Add(pet->ToCreature());

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
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    uint32 nodeid = m_spellInfo->EffectMiscValue[effIndex];
    if (sTaxiNodesStore.LookupEntry(nodeid))
        unitTarget->ToPlayer()->GetSession()->SendDiscoverNewTaxiNode(nodeid);
}

void Spell::EffectTitanGrip(SpellEffIndex /*effIndex*/)
{
    if (unitTarget && unitTarget->GetTypeId() == TYPEID_PLAYER)
        unitTarget->ToPlayer()->SetCanTitanGrip(true);
}

void Spell::EffectRedirectThreat(SpellEffIndex /*effIndex*/)
{
    if (unitTarget)
        m_caster->SetReducedThreatPercent((uint32)damage, unitTarget->GetGUID());
}

void Spell::EffectWMODamage(SpellEffIndex /*effIndex*/)
{
    if (gameObjTarget && gameObjTarget->GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
    {
        Unit *caster = m_originalCaster;
        if (!caster)
            return;

        // Do not allow damage if hp is 0
        if (gameObjTarget->GetGOValue()->building.health == 0)
            return;

        FactionTemplateEntry const *casterft, *goft;
        casterft = caster->getFactionTemplateEntry();
        goft = sFactionTemplateStore.LookupEntry(gameObjTarget->GetUInt32Value(GAMEOBJECT_FACTION));
        // Do not allow to damage GO's of friendly factions (ie: Wintergrasp Walls/Ulduar Storm Beacons)
        if ((casterft && goft && !casterft->IsFriendlyTo(*goft)) || !goft)
        {
            gameObjTarget->TakenDamage(uint32(damage), caster);
            WorldPacket data(SMSG_DESTRUCTIBLE_BUILDING_DAMAGE, 8+8+8+4+4);
            data.append(gameObjTarget->GetPackGUID());
            data.append(caster->GetPackGUID());
            if (Unit *who = caster->GetCharmerOrOwner())
                data.append(who->GetPackGUID());
            else
                data << uint8(0);
            data << uint32(damage);
            data << uint32(m_spellInfo->Id);
            gameObjTarget->SendMessageToSet(&data, false);
        }
    }
}

void Spell::EffectWMORepair(SpellEffIndex /*effIndex*/)
{
    if (gameObjTarget && gameObjTarget->GetGoType() == GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING)
        gameObjTarget->Rebuild();
}

void Spell::SummonGuardian(uint32 i, uint32 entry, SummonPropertiesEntry const *properties)
{
    Unit *caster = m_originalCaster;
    if (!caster)
        return;

    if (caster->isTotem())
      caster = caster->ToTotem()->GetOwner();

    // in another case summon new
    uint8 level = caster->getLevel();

    // level of pet summoned using engineering item based at engineering skill level
    if (m_CastItem && caster->GetTypeId() == TYPEID_PLAYER)
        if (ItemPrototype const *proto = m_CastItem->GetProto())
            if (proto->RequiredSkill == SKILL_ENGINERING)
                if (uint16 skill202 = caster->ToPlayer()->GetSkillValue(SKILL_ENGINERING))
                    level = skill202/5;

    //float radius = GetSpellRadiusForFriend(sSpellRadiusStore.LookupEntry(m_spellInfo->EffectRadiusIndex[i]));
    float radius = 5.0f;
    uint32 amount = damage > 0 ? damage : 1;
    int32 duration = GetSpellDuration(m_spellInfo);
    switch (m_spellInfo->Id)
    {
        case 1122: // Inferno
            amount = 1;
            break;
        case 49028: // Dancing Rune Weapon
            if (AuraEffect *aurEff = m_originalCaster->GetAuraEffect(63330, 0)) // glyph of Dancing Rune Weapon
                duration += aurEff->GetAmount();
            break;
    }
    if (Player* modOwner = m_originalCaster->GetSpellModOwner())
        modOwner->ApplySpellMod(m_spellInfo->Id, SPELLMOD_DURATION, duration);

    //TempSummonType summonType = (duration == 0) ? TEMPSUMMON_DEAD_DESPAWN : TEMPSUMMON_TIMED_DESPAWN;
    Map *map = caster->GetMap();

    for (uint32 count = 0; count < amount; ++count)
    {
        Position pos;
        GetSummonPosition(i, pos, radius, count);

        TempSummon *summon = map->SummonCreature(entry, pos, properties, duration, caster);
        if (!summon)
            return;
        if (summon->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
            ((Guardian*)summon)->InitStatsForLevel(level);

        summon->SetUInt32Value(UNIT_CREATED_BY_SPELL, m_spellInfo->Id);
        if (summon->HasUnitTypeMask(UNIT_MASK_MINION) && m_targets.HasDst())
            ((Minion*)summon)->SetFollowAngle(m_caster->GetAngle(summon));

        if (summon->GetEntry() == 27893)
        {
            if (uint32 weapon = m_caster->GetUInt32Value(PLAYER_VISIBLE_ITEM_16_ENTRYID))
            {
                summon->SetDisplayId(11686);
                summon->SetUInt32Value(UNIT_VIRTUAL_ITEM_SLOT_ID, weapon);
            }
            else
                summon->SetDisplayId(1126);
        }

        summon->AI()->EnterEvadeMode();

        ExecuteLogEffectSummonObject(i, summon);
    }
}

void Spell::GetSummonPosition(uint32 i, Position &pos, float radius, uint32 count)
{
    pos.SetOrientation(m_caster->GetOrientation());

    if (m_targets.HasDst())
    {
        // Summon 1 unit in dest location
        if (count == 0)
            pos.Relocate(m_targets.m_dstPos);
        // Summon in random point all other units if location present
        else
        {
            //This is a workaround. Do not have time to write much about it
            switch (m_spellInfo->EffectImplicitTargetA[i])
            {
                case TARGET_MINION:
                case TARGET_DEST_CASTER_RANDOM:
                    m_caster->GetNearPosition(pos, radius * (float)rand_norm(), (float)rand_norm()*static_cast<float>(2*M_PI));
                    break;
                case TARGET_DEST_DEST_RANDOM:
                case TARGET_DEST_TARGET_RANDOM:
                    m_caster->GetRandomPoint(m_targets.m_dstPos, radius, pos);
                    break;
                default:
                    pos.Relocate(m_targets.m_dstPos);
                    break;
            }
        }
    }
    // Summon if dest location not present near caster
    else
    {
        float x, y, z;
        m_caster->GetClosePoint(x,y,z,3.0f);
        pos.Relocate(x, y, z);
    }
}

void Spell::EffectRenamePet(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_UNIT ||
        !unitTarget->ToCreature()->isPet() || ((Pet*)unitTarget)->getPetType() != HUNTER_PET)
        return;

    unitTarget->SetByteFlag(UNIT_FIELD_BYTES_2, 2, UNIT_CAN_BE_RENAMED);
}

void Spell::EffectPlayMusic(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    uint32 soundid = m_spellInfo->EffectMiscValue[effIndex];

    if (!sSoundEntriesStore.LookupEntry(soundid))
    {
        sLog.outError("EffectPlayMusic: Sound (Id: %u) not exist in spell %u.",soundid,m_spellInfo->Id);
        return;
    }

    WorldPacket data(SMSG_PLAY_MUSIC, 4);
    data << uint32(soundid);
    unitTarget->ToPlayer()->GetSession()->SendPacket(&data);
}

void Spell::EffectSpecCount(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->UpdateSpecCount(damage);
}

void Spell::EffectActivateSpec(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->ActivateSpec(damage-1);  // damage is 1 or 2, spec is 0 or 1
}

void Spell::EffectPlayerNotification(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    switch(m_spellInfo->Id)
    {
        case 58730: // Restricted Flight Area
        case 58600: // Restricted Flight Area
            unitTarget->ToPlayer()->GetSession()->SendNotification(LANG_ZONE_NOFLYZONE);
            break;
    }
}

void Spell::EffectRemoveAura(SpellEffIndex effIndex)
{
    if (!unitTarget)
        return;
    // there may be need of specifying casterguid of removed auras
    unitTarget->RemoveAurasDueToSpell(m_spellInfo->EffectTriggerSpell[effIndex]);
}

void Spell::EffectCastButtons(SpellEffIndex effIndex)
{
    if (!unitTarget || m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player *p_caster = (Player*)m_caster;
    uint32 button_id = m_spellInfo->EffectMiscValue[effIndex] + 132;
    uint32 n_buttons = m_spellInfo->EffectMiscValueB[effIndex];

    for (; n_buttons; n_buttons--, button_id++)
    {
        ActionButton const* ab = p_caster->GetActionButton(button_id);
        if (!ab || ab->GetType() != ACTION_BUTTON_SPELL)
            continue;

        uint32 spell_id = ab->GetAction();
        if (!spell_id)
            continue;

        if (p_caster->HasSpellCooldown(spell_id))
            continue;

        SpellEntry const *spellInfo = sSpellStore.LookupEntry(spell_id);
        uint32 cost = CalculatePowerCost(spellInfo, m_caster, GetSpellSchoolMask(spellInfo));

        if (m_caster->GetPower(POWER_MANA) < cost)
            break;

        m_caster->CastSpell(unitTarget, spell_id, true);
        m_caster->ModifyPower(POWER_MANA, -(int32)cost);
        p_caster->AddSpellAndCategoryCooldowns(spellInfo, 0);
    }
}

void Spell::EffectRechargeManaGem(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player *player = m_caster->ToPlayer();

    if (!player)
        return;

    uint32 item_id = m_spellInfo->EffectItemType[0];

    ItemPrototype const *pProto = sObjectMgr.GetItemPrototype(item_id);
    if (!pProto)
    {
        player->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, NULL, NULL);
        return;
    }

    if (Item* pItem = player->GetItemByEntry(item_id))
    {
        for (int x = 0; x < MAX_ITEM_PROTO_SPELLS; ++x)
            pItem->SetSpellCharges(x,pProto->Spells[x].SpellCharges);
        pItem->SetState(ITEM_CHANGED,player);
    }
}

void Spell::EffectBind(SpellEffIndex effIndex)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = (Player*)unitTarget;

    uint32 area_id;
    WorldLocation loc;
    if (m_spellInfo->EffectImplicitTargetA[effIndex] == TARGET_DST_DB || m_spellInfo->EffectImplicitTargetB[effIndex] == TARGET_DST_DB)
    {
        SpellTargetPosition const* st = sSpellMgr.GetSpellTargetPosition(m_spellInfo->Id);
        if (!st)
        {
            sLog.outError( "Spell::EffectBind - unknown teleport coordinates for spell ID %u", m_spellInfo->Id );
            return;
        }

        loc.m_mapId         = st->target_mapId;
        loc.m_positionX   = st->target_X;
        loc.m_positionY   = st->target_Y;
        loc.m_positionZ   = st->target_Y;
        loc.m_orientation = st->target_Orientation;
        area_id = player->GetAreaId();
    }
    else
    {
        player->GetPosition(&loc);
        area_id = player->GetAreaId();
    }

    player->SetHomebind(loc, area_id);

    // binding
    WorldPacket data( SMSG_BINDPOINTUPDATE, (4+4+4+4+4) );
    data << float(loc.m_positionX);
    data << float(loc.m_positionY);
    data << float(loc.m_positionZ);
    data << uint32(loc.m_mapId);
    data << uint32(area_id);
    player->SendDirectMessage( &data );

    sLog.outStaticDebug("New homebind X      : %f", loc.m_positionX);
    sLog.outStaticDebug("New homebind Y      : %f", loc.m_positionY);
    sLog.outStaticDebug("New homebind Z      : %f", loc.m_positionZ);
    sLog.outStaticDebug("New homebind MapId  : %u", loc.m_mapId);
    sLog.outStaticDebug("New homebind AreaId : %u", area_id);

    // zone update
    data.Initialize(SMSG_PLAYERBOUND, 8+4);
    data << uint64(player->GetGUID());
    data << uint32(area_id);
    player->SendDirectMessage( &data );
}
