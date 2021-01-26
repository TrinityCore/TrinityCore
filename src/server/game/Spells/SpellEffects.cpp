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

#include "Spell.h"
#include "AccountMgr.h"
#include "AreaTrigger.h"
#include "AzeriteEmpoweredItem.h"
#include "AzeriteItem.h"
#include "Battleground.h"
#include "BattlegroundMgr.h"
#include "BattlePetMgr.h"
#include "CellImpl.h"
#include "CombatLogPackets.h"
#include "CombatPackets.h"
#include "Common.h"
#include "Conversation.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DuelPackets.h"
#include "DynamicObject.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GameTime.h"
#include "Garrison.h"
#include "GossipDef.h"
#include "GridNotifiers.h"
#include "Group.h"
#include "Guild.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "LootMgr.h"
#include "Map.h"
#include "MiscPackets.h"
#include "MotionMaster.h"
#include "ObjectMgr.h"
#include "Opcodes.h"
#include "OutdoorPvPMgr.h"
#include "PathGenerator.h"
#include "Pet.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "ScriptMgr.h"
#include "SharedDefines.h"
#include "SkillExtraItems.h"
#include "SocialMgr.h"
#include "SpellAuraEffects.h"
#include "SpellAuras.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellPackets.h"
#include "TalentPackets.h"
#include "TemporarySummon.h"
#include "Totem.h"
#include "Unit.h"
#include "Util.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"

NonDefaultConstructible<pEffect> SpellEffects[TOTAL_SPELL_EFFECTS] =
{
    &Spell::EffectNULL,                                     //  0
    &Spell::EffectInstaKill,                                //  1 SPELL_EFFECT_INSTAKILL
    &Spell::EffectSchoolDMG,                                //  2 SPELL_EFFECT_SCHOOL_DAMAGE
    &Spell::EffectDummy,                                    //  3 SPELL_EFFECT_DUMMY
    &Spell::EffectUnused,                                   //  4 SPELL_EFFECT_PORTAL_TELEPORT          unused
    &Spell::EffectUnused,                                   //  5 SPELL_EFFECT_TELEPORT_UNITS_OLD
    &Spell::EffectApplyAura,                                //  6 SPELL_EFFECT_APPLY_AURA
    &Spell::EffectEnvironmentalDMG,                         //  7 SPELL_EFFECT_ENVIRONMENTAL_DAMAGE
    &Spell::EffectPowerDrain,                               //  8 SPELL_EFFECT_POWER_DRAIN
    &Spell::EffectHealthLeech,                              //  9 SPELL_EFFECT_HEALTH_LEECH
    &Spell::EffectHeal,                                     // 10 SPELL_EFFECT_HEAL
    &Spell::EffectBind,                                     // 11 SPELL_EFFECT_BIND
    &Spell::EffectNULL,                                     // 12 SPELL_EFFECT_PORTAL
    &Spell::EffectUnused,                                   // 13 SPELL_EFFECT_RITUAL_BASE              unused
    &Spell::EffectUnused,                                   // 14 SPELL_EFFECT_INCREASE_CURRENCY_CAP
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
    &Spell::EffectPlayMovie,                                // 45 SPELL_EFFECT_PLAY_MOVIE
    &Spell::EffectUnused,                                   // 46 SPELL_EFFECT_SPAWN clientside, unit appears as if it was just spawned
    &Spell::EffectTradeSkill,                               // 47 SPELL_EFFECT_TRADE_SKILL
    &Spell::EffectUnused,                                   // 48 SPELL_EFFECT_STEALTH                  one spell: Base Stealth
    &Spell::EffectUnused,                                   // 49 SPELL_EFFECT_DETECT                   one spell: Detect
    &Spell::EffectTransmitted,                              // 50 SPELL_EFFECT_TRANS_DOOR
    &Spell::EffectUnused,                                   // 51 SPELL_EFFECT_FORCE_CRITICAL_HIT       unused
    &Spell::EffectUnused,                                   // 52 SPELL_EFFECT_SET_MAX_BATTLE_PET_COUNT
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
    &Spell::EffectRechargeItem,                             // 66 SPELL_EFFECT_RECHARGE_ITEM
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
    &Spell::EffectUnused,                                   // 81 SPELL_EFFECT_PUSH_ABILITY_TO_ACTION_BAR
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
    &Spell::EffectUnused,                                   //105 SPELL_EFFECT_SURVEY
    &Spell::EffectChangeRaidMarker,                         //106 SPELL_EFFECT_CHANGE_RAID_MARKER
    &Spell::EffectUnused,                                   //107 SPELL_EFFECT_SHOW_CORPSE_LOOT
    &Spell::EffectDispelMechanic,                           //108 SPELL_EFFECT_DISPEL_MECHANIC
    &Spell::EffectResurrectPet,                             //109 SPELL_EFFECT_RESURRECT_PET
    &Spell::EffectDestroyAllTotems,                         //110 SPELL_EFFECT_DESTROY_ALL_TOTEMS
    &Spell::EffectDurabilityDamage,                         //111 SPELL_EFFECT_DURABILITY_DAMAGE
    &Spell::EffectUnused,                                   //112 SPELL_EFFECT_112
    &Spell::EffectUnused,                                   //113 SPELL_EFFECT_113
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
    &Spell::EffectApplyAreaAura,                            //143 SPELL_EFFECT_APPLY_AREA_AURA_OWNER
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
    &Spell::EffectNULL,                                     //161 SPELL_EFFECT_TALENT_SPEC_COUNT        second talent spec (learn/revert)
    &Spell::EffectActivateSpec,                             //162 SPELL_EFFECT_TALENT_SPEC_SELECT       activate primary/secondary spec
    &Spell::EffectUnused,                                   //163 SPELL_EFFECT_OBLITERATE_ITEM
    &Spell::EffectRemoveAura,                               //164 SPELL_EFFECT_REMOVE_AURA
    &Spell::EffectDamageFromMaxHealthPCT,                   //165 SPELL_EFFECT_DAMAGE_FROM_MAX_HEALTH_PCT
    &Spell::EffectGiveCurrency,                             //166 SPELL_EFFECT_GIVE_CURRENCY
    &Spell::EffectUpdatePlayerPhase,                        //167 SPELL_EFFECT_UPDATE_PLAYER_PHASE
    &Spell::EffectNULL,                                     //168 SPELL_EFFECT_ALLOW_CONTROL_PET
    &Spell::EffectDestroyItem,                              //169 SPELL_EFFECT_DESTROY_ITEM
    &Spell::EffectUpdateZoneAurasAndPhases,                 //170 SPELL_EFFECT_UPDATE_ZONE_AURAS_AND_PHASES
    &Spell::EffectSummonPersonalGameObject,                 //171 SPELL_EFFECT_SUMMON_PERSONAL_GAMEOBJECT
    &Spell::EffectResurrectWithAura,                        //172 SPELL_EFFECT_RESURRECT_WITH_AURA
    &Spell::EffectUnlockGuildVaultTab,                      //173 SPELL_EFFECT_UNLOCK_GUILD_VAULT_TAB
    &Spell::EffectApplyAura,                                //174 SPELL_EFFECT_APPLY_AURA_ON_PET
    &Spell::EffectUnused,                                   //175 SPELL_EFFECT_175  unused
    &Spell::EffectSanctuary,                                //176 SPELL_EFFECT_SANCTUARY_2
    &Spell::EffectNULL,                                     //177 SPELL_EFFECT_177
    &Spell::EffectUnused,                                   //178 SPELL_EFFECT_178 unused
    &Spell::EffectCreateAreaTrigger,                        //179 SPELL_EFFECT_CREATE_AREATRIGGER
    &Spell::EffectNULL,                                     //180 SPELL_EFFECT_UPDATE_AREATRIGGER
    &Spell::EffectRemoveTalent,                             //181 SPELL_EFFECT_REMOVE_TALENT
    &Spell::EffectNULL,                                     //182 SPELL_EFFECT_DESPAWN_AREATRIGGER
    &Spell::EffectNULL,                                     //183 SPELL_EFFECT_183
    &Spell::EffectNULL,                                     //184 SPELL_EFFECT_REPUTATION
    &Spell::EffectNULL,                                     //185 SPELL_EFFECT_185
    &Spell::EffectNULL,                                     //186 SPELL_EFFECT_186
    &Spell::EffectNULL,                                     //187 SPELL_EFFECT_RANDOMIZE_ARCHAEOLOGY_DIGSITES
    &Spell::EffectNULL,                                     //188 SPELL_EFFECT_188
    &Spell::EffectNULL,                                     //189 SPELL_EFFECT_LOOT
    &Spell::EffectNULL,                                     //190 SPELL_EFFECT_190
    &Spell::EffectNULL,                                     //191 SPELL_EFFECT_TELEPORT_TO_DIGSITE
    &Spell::EffectUncageBattlePet,                          //192 SPELL_EFFECT_UNCAGE_BATTLEPET
    &Spell::EffectNULL,                                     //193 SPELL_EFFECT_START_PET_BATTLE
    &Spell::EffectNULL,                                     //194 SPELL_EFFECT_194
    &Spell::EffectNULL,                                     //195 SPELL_EFFECT_195
    &Spell::EffectNULL,                                     //196 SPELL_EFFECT_196
    &Spell::EffectNULL,                                     //197 SPELL_EFFECT_197
    &Spell::EffectPlayScene,                                //198 SPELL_EFFECT_PLAY_SCENE
    &Spell::EffectNULL,                                     //199 SPELL_EFFECT_199
    &Spell::EffectHealBattlePetPct,                         //200 SPELL_EFFECT_HEAL_BATTLEPET_PCT
    &Spell::EffectEnableBattlePets,                         //201 SPELL_EFFECT_ENABLE_BATTLE_PETS
    &Spell::EffectApplyAura,                                //202 SPELL_EFFECT_202
    &Spell::EffectNULL,                                     //203 SPELL_EFFECT_203
    &Spell::EffectNULL,                                     //204 SPELL_EFFECT_CHANGE_BATTLEPET_QUALITY
    &Spell::EffectLaunchQuestChoice,                        //205 SPELL_EFFECT_LAUNCH_QUEST_CHOICE
    &Spell::EffectNULL,                                     //206 SPELL_EFFECT_ALTER_ITEM
    &Spell::EffectNULL,                                     //207 SPELL_EFFECT_LAUNCH_QUEST_TASK
    &Spell::EffectNULL,                                     //208 SPELL_EFFECT_208
    &Spell::EffectNULL,                                     //209 SPELL_EFFECT_209
    &Spell::EffectLearnGarrisonBuilding,                    //210 SPELL_EFFECT_LEARN_GARRISON_BUILDING
    &Spell::EffectNULL,                                     //211 SPELL_EFFECT_LEARN_GARRISON_SPECIALIZATION
    &Spell::EffectNULL,                                     //212 SPELL_EFFECT_212
    &Spell::EffectNULL,                                     //213 SPELL_EFFECT_213
    &Spell::EffectCreateGarrison,                           //214 SPELL_EFFECT_CREATE_GARRISON
    &Spell::EffectNULL,                                     //215 SPELL_EFFECT_UPGRADE_CHARACTER_SPELLS
    &Spell::EffectNULL,                                     //216 SPELL_EFFECT_CREATE_SHIPMENT
    &Spell::EffectNULL,                                     //217 SPELL_EFFECT_UPGRADE_GARRISON
    &Spell::EffectNULL,                                     //218 SPELL_EFFECT_218
    &Spell::EffectCreateConversation,                       //219 SPELL_EFFECT_CREATE_CONVERSATION
    &Spell::EffectAddGarrisonFollower,                      //220 SPELL_EFFECT_ADD_GARRISON_FOLLOWER
    &Spell::EffectNULL,                                     //221 SPELL_EFFECT_221
    &Spell::EffectCreateHeirloomItem,                       //222 SPELL_EFFECT_CREATE_HEIRLOOM_ITEM
    &Spell::EffectNULL,                                     //223 SPELL_EFFECT_CHANGE_ITEM_BONUSES
    &Spell::EffectActivateGarrisonBuilding,                 //224 SPELL_EFFECT_ACTIVATE_GARRISON_BUILDING
    &Spell::EffectNULL,                                     //225 SPELL_EFFECT_GRANT_BATTLEPET_LEVEL
    &Spell::EffectNULL,                                     //226 SPELL_EFFECT_226
    &Spell::EffectNULL,                                     //227 SPELL_EFFECT_TELEPORT_TO_LFG_DUNGEON
    &Spell::EffectNULL,                                     //228 SPELL_EFFECT_228
    &Spell::EffectNULL,                                     //229 SPELL_EFFECT_SET_FOLLOWER_QUALITY
    &Spell::EffectNULL,                                     //230 SPELL_EFFECT_INCREASE_FOLLOWER_ITEM_LEVEL
    &Spell::EffectNULL,                                     //231 SPELL_EFFECT_INCREASE_FOLLOWER_EXPERIENCE
    &Spell::EffectNULL,                                     //232 SPELL_EFFECT_REMOVE_PHASE
    &Spell::EffectNULL,                                     //233 SPELL_EFFECT_RANDOMIZE_FOLLOWER_ABILITIES
    &Spell::EffectNULL,                                     //234 SPELL_EFFECT_234
    &Spell::EffectNULL,                                     //235 SPELL_EFFECT_235
    &Spell::EffectNULL,                                     //236 SPELL_EFFECT_GIVE_EXPERIENCE
    &Spell::EffectNULL,                                     //237 SPELL_EFFECT_GIVE_RESTED_EXPERIENCE_BONUS
    &Spell::EffectNULL,                                     //238 SPELL_EFFECT_INCREASE_SKILL
    &Spell::EffectNULL,                                     //239 SPELL_EFFECT_END_GARRISON_BUILDING_CONSTRUCTION
    &Spell::EffectGiveArtifactPower,                        //240 SPELL_EFFECT_GIVE_ARTIFACT_POWER
    &Spell::EffectNULL,                                     //241 SPELL_EFFECT_241
    &Spell::EffectGiveArtifactPowerNoBonus,                 //242 SPELL_EFFECT_GIVE_ARTIFACT_POWER_NO_BONUS
    &Spell::EffectApplyEnchantIllusion,                     //243 SPELL_EFFECT_APPLY_ENCHANT_ILLUSION
    &Spell::EffectNULL,                                     //244 SPELL_EFFECT_LEARN_FOLLOWER_ABILITY
    &Spell::EffectUpgradeHeirloom,                          //245 SPELL_EFFECT_UPGRADE_HEIRLOOM
    &Spell::EffectNULL,                                     //246 SPELL_EFFECT_FINISH_GARRISON_MISSION
    &Spell::EffectNULL,                                     //247 SPELL_EFFECT_ADD_GARRISON_MISSION
    &Spell::EffectNULL,                                     //248 SPELL_EFFECT_FINISH_SHIPMENT
    &Spell::EffectNULL,                                     //249 SPELL_EFFECT_FORCE_EQUIP_ITEM
    &Spell::EffectNULL,                                     //250 SPELL_EFFECT_TAKE_SCREENSHOT
    &Spell::EffectNULL,                                     //251 SPELL_EFFECT_SET_GARRISON_CACHE_SIZE
    &Spell::EffectTeleportUnits,                            //252 SPELL_EFFECT_TELEPORT_UNITS
    &Spell::EffectGiveHonor,                                //253 SPELL_EFFECT_GIVE_HONOR
    &Spell::EffectNULL,                                     //254 SPELL_EFFECT_254
    &Spell::EffectLearnTransmogSet,                         //255 SPELL_EFFECT_LEARN_TRANSMOG_SET
    &Spell::EffectNULL,                                     //256 SPELL_EFFECT_256
    &Spell::EffectNULL,                                     //257 SPELL_EFFECT_257
    &Spell::EffectNULL,                                     //258 SPELL_EFFECT_MODIFY_KEYSTONE
    &Spell::EffectRespecAzeriteEmpoweredItem,               //259 SPELL_EFFECT_RESPEC_AZERITE_EMPOWERED_ITEM
    &Spell::EffectNULL,                                     //260 SPELL_EFFECT_SUMMON_STABLED_PET
    &Spell::EffectNULL,                                     //261 SPELL_EFFECT_SCRAP_ITEM
    &Spell::EffectNULL,                                     //262 SPELL_EFFECT_262
    &Spell::EffectNULL,                                     //263 SPELL_EFFECT_REPAIR_ITEM
    &Spell::EffectNULL,                                     //264 SPELL_EFFECT_REMOVE_GEM
    &Spell::EffectLearnAzeriteEssencePower,                 //265 SPELL_EFFECT_LEARN_AZERITE_ESSENCE_POWER
    &Spell::EffectNULL,                                     //266 SPELL_EFFECT_266
    &Spell::EffectNULL,                                     //267 SPELL_EFFECT_267
    &Spell::EffectNULL,                                     //268 SPELL_EFFECT_APPLY_MOUNT_EQUIPMENT
    &Spell::EffectNULL,                                     //269 SPELL_EFFECT_UPGRADE_ITEM
    &Spell::EffectNULL,                                     //270 SPELL_EFFECT_270
    &Spell::EffectApplyAreaAura,                            //271 SPELL_EFFECT_APPLY_AREA_AURA_PARTY_NONRANDOM
    &Spell::EffectNULL,                                     //272 SPELL_EFFECT_SET_COVENANT
    &Spell::EffectNULL,                                     //273 SPELL_EFFECT_CRAFT_RUNEFORGE_LEGENDARY
    &Spell::EffectNULL,                                     //274 SPELL_EFFECT_274
    &Spell::EffectNULL,                                     //275 SPELL_EFFECT_275
    &Spell::EffectNULL,                                     //276 SPELL_EFFECT_LEARN_TRANSMOG_ILLUSION
    &Spell::EffectNULL,                                     //277 SPELL_EFFECT_SET_CHROMIE_TIME
    &Spell::EffectNULL,                                     //278 SPELL_EFFECT_270
    &Spell::EffectNULL,                                     //279 SPELL_EFFECT_LEARN_GARR_TALENT
    &Spell::EffectNULL,                                     //280 SPELL_EFFECT_270
    &Spell::EffectNULL,                                     //281 SPELL_EFFECT_LEARN_SOULBIND_CONDUIT
    &Spell::EffectNULL,                                     //282 SPELL_EFFECT_CONVERT_ITEMS_TO_CURRENCY
    &Spell::EffectNULL,                                     //283 SPELL_EFFECT_283
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
    uint32 mana = effectInfo->MiscValue;
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

    WorldPackets::CombatLog::SpellInstakillLog data;
    data.Target = unitTarget->GetGUID();
    data.Caster = m_caster->GetGUID();
    data.SpellID = m_spellInfo->Id;

    m_caster->SendMessageToSet(data.Write(), true);

    m_caster->DealDamage(unitTarget, unitTarget->GetHealth(), nullptr, NODAMAGE, SPELL_SCHOOL_MASK_NORMAL, nullptr, false);
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
        DamageInfo damageInfo(m_caster, unitTarget, damage, m_spellInfo, m_spellInfo->GetSchoolMask(), SPELL_DIRECT_DAMAGE, BASE_ATTACK);
        m_caster->CalcAbsorbResist(damageInfo);

        SpellNonMeleeDamage log(m_caster, unitTarget, m_spellInfo, m_SpellVisual, m_spellInfo->GetSchoolMask(), m_castId);
        log.damage = damageInfo.GetDamage();
        log.originalDamage = damage;
        log.absorb = damageInfo.GetAbsorb();
        log.resist = damageInfo.GetResist();

        m_caster->SendSpellNonMeleeDamageLog(&log);
    }
}

void Spell::EffectSchoolDMG(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (unitTarget && unitTarget->IsAlive())
    {
        bool apply_direct_bonus = true;

        // Meteor like spells (divided damage to targets)
        if (m_spellInfo->HasAttribute(SPELL_ATTR0_CU_SHARE_DAMAGE))
        {
            uint32 count = std::count_if(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [effIndex](TargetInfo const& targetInfo)
            {
                return targetInfo.effectMask & (1 << effIndex);
            });

            // divide to all targets
            if (count)
                damage /= count;
        }

        switch (m_spellInfo->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
            {
                switch (m_spellInfo->Id)                     // better way to check unknown
                {
                    // Consumption
                    case 28865:
                        damage = (m_caster->GetMap()->GetDifficultyID() == DIFFICULTY_NONE ? 2750 : 4250);
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
                    // Gargoyle Strike
                    case 51963:
                    {
                        // about +4 base spell dmg per level
                        damage = (m_caster->getLevel() - 60) * 4 + 60;
                        break;
                    }
                }
                break;
            }
            case SPELLFAMILY_WARRIOR:
            {
                // Victory Rush
                if (m_spellInfo->Id == 34428)
                    ApplyPct(damage, m_caster->GetTotalAttackPowerValue(BASE_ATTACK));
                // Shockwave
                else if (m_spellInfo->Id == 46968)
                {
                    int32 pct = m_caster->CalculateSpellDamage(unitTarget, m_spellInfo, 2);
                    if (pct > 0)
                        damage += int32(CalculatePct(m_caster->GetTotalAttackPowerValue(BASE_ATTACK), pct));
                    break;
                }
                break;
            }
            case SPELLFAMILY_WARLOCK:
            {
                break;
            }
            case SPELLFAMILY_PRIEST:
            {
                break;
            }
            case SPELLFAMILY_DRUID:
            {
                // Ferocious Bite
                if (m_caster->GetTypeId() == TYPEID_PLAYER && m_spellInfo->SpellFamilyFlags[3] & 0x1000)
                {
                    // converts each extra point of energy ( up to 25 energy ) into additional damage
                    int32 energy = -(m_caster->ModifyPower(POWER_ENERGY, -25));
                    // 25 energy = 100% more damage
                    AddPct(damage, energy * 4);
                }
                break;
            }
            case SPELLFAMILY_DEATHKNIGHT:
            {
                // Blood Boil - bonus for diseased targets
                if (m_spellInfo->SpellFamilyFlags[0] & 0x00040000)
                {
                    if (unitTarget->GetAuraEffect(SPELL_AURA_PERIODIC_DAMAGE, SPELLFAMILY_DEATHKNIGHT, flag128(0, 0, 0x00000002), m_caster->GetGUID()))
                    {
                        damage += m_damage / 2;
                        damage += int32(m_caster->GetTotalAttackPowerValue(BASE_ATTACK) * 0.035f);
                    }
                }
                break;
            }
        }

        if (m_originalCaster && apply_direct_bonus)
        {
            uint32 bonus = m_originalCaster->SpellDamageBonusDone(unitTarget, m_spellInfo, (uint32)damage, SPELL_DIRECT_DAMAGE, effectInfo);
            damage = bonus + uint32(bonus * variance);
            damage = unitTarget->SpellDamageBonusTaken(m_originalCaster, m_spellInfo, (uint32)damage, SPELL_DIRECT_DAMAGE, effectInfo);
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

    // selection by spell family
    switch (m_spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_PALADIN:
            switch (m_spellInfo->Id)
            {
                case 31789:                                 // Righteous Defense (step 1)
                {
                    // Clear targets for eff 1
                    for (std::vector<TargetInfo>::iterator ihit = m_UniqueTargetInfo.begin(); ihit != m_UniqueTargetInfo.end(); ++ihit)
                        ihit->effectMask &= ~(1<<1);

                    // not empty (checked), copy
                    Unit::AttackerSet attackers = unitTarget->getAttackers();

                    // remove invalid attackers
                    for (Unit::AttackerSet::iterator aItr = attackers.begin(); aItr != attackers.end();)
                        if (!(*aItr)->IsValidAttackTarget(m_caster))
                            attackers.erase(aItr++);
                        else
                            ++aItr;

                    // selected from list 3
                    uint32 maxTargets = std::min<uint32>(3, attackers.size());
                    for (uint32 i = 0; i < maxTargets; ++i)
                    {
                        Unit* attacker = Trinity::Containers::SelectRandomContainerElement(attackers);
                        AddUnitTarget(attacker, 1 << 1);
                        attackers.erase(attacker);
                    }

                    // now let next effect cast spell at each target.
                    return;
                }
            }
            break;
        default:
            break;
    }

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

void Spell::EffectTriggerSpell(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET
        && effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    uint32 triggered_spell_id = effectInfo->TriggerSpell;

    /// @todo move those to spell scripts
    if (effectInfo->Effect == SPELL_EFFECT_TRIGGER_SPELL
        && effectHandleMode == SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
    {
        // special cases
        switch (triggered_spell_id)
        {
            // Vanish (not exist)
            case 18461:
            {
                unitTarget->RemoveMovementImpairingAuras(true);
                unitTarget->RemoveAurasByType(SPELL_AURA_MOD_STALKED);
                return;
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
            // Brittle Armor - (need add max stack of 24575 Brittle Armor)
            case 29284:
            {
                // Brittle Armor
                SpellInfo const* spell = sSpellMgr->GetSpellInfo(24575, GetCastDifficulty());
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
                SpellInfo const* spell = sSpellMgr->GetSpellInfo(26464, GetCastDifficulty());
                if (!spell)
                    return;

                for (uint32 j = 0; j < spell->StackAmount; ++j)
                    m_caster->CastSpell(unitTarget, spell->Id, true);
                return;
            }
        }
    }

    // normal case
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggered_spell_id, GetCastDifficulty());
    if (!spellInfo)
    {
        TC_LOG_ERROR("spells.effecttriggerspell", "Spell::EffectTriggerSpell spell %u tried to trigger unknown spell %u", m_spellInfo->Id, triggered_spell_id);
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
        if (spellInfo->NeedsToBeTriggeredByCaster(m_spellInfo) && (effectInfo->GetProvidedTargetMask() & TARGET_FLAG_UNIT_MASK))
            return;

        if (spellInfo->GetExplicitTargetMask() & TARGET_FLAG_DEST_LOCATION)
            targets.SetDst(m_targets);

        if (Unit* target = m_targets.GetUnitTarget())
            targets.SetUnitTarget(target);
        else
            targets.SetUnitTarget(m_caster);
    }

    CustomSpellValues values;
    // set basepoints for trigger with value effect
    if (effectInfo->Effect == SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE)
    {
        values.AddSpellMod(SPELLVALUE_BASE_POINT0, damage);
        values.AddSpellMod(SPELLVALUE_BASE_POINT1, damage);
        values.AddSpellMod(SPELLVALUE_BASE_POINT2, damage);
    }

    // original caster guid only for GO cast
    m_caster->CastSpell(targets, spellInfo, &values, TRIGGERED_FULL_MASK, nullptr, nullptr, m_originalCasterGUID);
}

void Spell::EffectTriggerMissileSpell(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET
        && effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    uint32 triggered_spell_id = effectInfo->TriggerSpell;

    // normal case
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggered_spell_id, GetCastDifficulty());
    if (!spellInfo)
    {
        TC_LOG_ERROR("spells.effecttrigermissilespell", "Spell::EffectTriggerMissileSpell spell %u tried to trigger unknown spell %u.", m_spellInfo->Id, triggered_spell_id);
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
        if (spellInfo->NeedsToBeTriggeredByCaster(m_spellInfo) && (effectInfo->GetProvidedTargetMask() & TARGET_FLAG_UNIT_MASK))
            return;

        if (spellInfo->GetExplicitTargetMask() & TARGET_FLAG_DEST_LOCATION)
            targets.SetDst(m_targets);

        targets.SetUnitTarget(m_caster);
    }

    CustomSpellValues values;
    // set basepoints for trigger with value effect
    if (effectInfo->Effect == SPELL_EFFECT_TRIGGER_MISSILE_SPELL_WITH_VALUE)
    {
        // maybe need to set value only when basepoints == 0?
        values.AddSpellMod(SPELLVALUE_BASE_POINT0, damage);
        values.AddSpellMod(SPELLVALUE_BASE_POINT1, damage);
        values.AddSpellMod(SPELLVALUE_BASE_POINT2, damage);
    }

    // original caster guid only for GO cast
    m_caster->CastSpell(targets, spellInfo, &values, TRIGGERED_FULL_MASK, nullptr, nullptr, m_originalCasterGUID);
}

void Spell::EffectForceCast(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    uint32 triggered_spell_id = effectInfo->TriggerSpell;

    // normal case
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggered_spell_id, GetCastDifficulty());

    if (!spellInfo)
    {
        TC_LOG_ERROR("spells", "Spell::EffectForceCast of spell %u: triggering unknown spell id %i.", m_spellInfo->Id, triggered_spell_id);
        return;
    }

    if (effectInfo->Effect == SPELL_EFFECT_FORCE_CAST && damage)
    {
        switch (m_spellInfo->Id)
        {
            case 52588: // Skeletal Gryphon Escape
            case 48598: // Ride Flamebringer Cue
                unitTarget->RemoveAura(damage);
                break;
            case 52463: // Hide In Mine Car
            case 52349: // Overtake
                unitTarget->CastCustomSpell(unitTarget, spellInfo->Id, &damage, nullptr, nullptr, true, nullptr, nullptr, m_originalCasterGUID);
                return;
        }
    }

    switch (spellInfo->Id)
    {
        case 72298: // Malleable Goo Summon
            unitTarget->CastSpell(unitTarget, spellInfo->Id, true, nullptr, nullptr, m_originalCasterGUID);
            return;
    }

    CustomSpellValues values;
    // set basepoints for trigger with value effect
    if (effectInfo->Effect == SPELL_EFFECT_FORCE_CAST_WITH_VALUE)
    {
        // maybe need to set value only when basepoints == 0?
        values.AddSpellMod(SPELLVALUE_BASE_POINT0, damage);
        values.AddSpellMod(SPELLVALUE_BASE_POINT1, damage);
        values.AddSpellMod(SPELLVALUE_BASE_POINT2, damage);
    }

    SpellCastTargets targets;
    targets.SetUnitTarget(m_caster);

    unitTarget->CastSpell(targets, spellInfo, &values, TRIGGERED_FULL_MASK);
}

void Spell::EffectTriggerRitualOfSummoning(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    uint32 triggered_spell_id = effectInfo->TriggerSpell;
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggered_spell_id, GetCastDifficulty());

    if (!spellInfo)
    {
        TC_LOG_ERROR("spells", "EffectTriggerRitualOfSummoning of spell %u: triggering unknown spell id %i.", m_spellInfo->Id, triggered_spell_id);
        return;
    }

    finish();

    m_caster->CastSpell(nullptr, spellInfo, false);
}

void Spell::EffectJump(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (m_caster->IsInFlight())
        return;

    if (!unitTarget)
        return;

    float speedXY, speedZ;
    CalculateJumpSpeeds(effectInfo, m_caster->GetExactDist2d(unitTarget), speedXY, speedZ);
    JumpArrivalCastArgs arrivalCast;
    arrivalCast.SpellId = effectInfo->TriggerSpell;
    arrivalCast.Target = unitTarget->GetGUID();
    m_caster->GetMotionMaster()->MoveJump(*unitTarget, speedXY, speedZ, EVENT_JUMP, false, &arrivalCast);
}

void Spell::EffectJumpDest(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    if (m_caster->IsInFlight())
        return;

    if (!m_targets.HasDst())
        return;

    float speedXY, speedZ;
    CalculateJumpSpeeds(effectInfo, m_caster->GetExactDist2d(destTarget), speedXY, speedZ);
    JumpArrivalCastArgs arrivalCast;
    arrivalCast.SpellId = effectInfo->TriggerSpell;
    m_caster->GetMotionMaster()->MoveJump(*destTarget, speedXY, speedZ, EVENT_JUMP, !m_targets.GetObjectTargetGUID().IsEmpty(), &arrivalCast);
}

void Spell::CalculateJumpSpeeds(SpellEffectInfo const* effInfo, float dist, float& speedXY, float& speedZ)
{
    if (effInfo->MiscValue)
        speedZ = float(effInfo->MiscValue) / 10;
    else if (effInfo->MiscValueB)
        speedZ = float(effInfo->MiscValueB) / 10;
    else
        speedZ = 10.0f;

    speedXY = dist * 10.0f / speedZ;
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
    uint32 mapid = destTarget->GetMapId();
    if (mapid == MAPID_INVALID)
        mapid = unitTarget->GetMapId();
    float x, y, z, orientation;
    destTarget->GetPosition(x, y, z, orientation);
    if (!orientation && m_targets.GetUnitTarget())
        orientation = m_targets.GetUnitTarget()->GetOrientation();
    TC_LOG_DEBUG("spells", "Spell::EffectTeleportUnits - teleport unit to %u %f %f %f %f\n", mapid, x, y, z, orientation);

    if (Player* player = unitTarget->ToPlayer())
    {
        // Custom loading screen
        if (uint32 customLoadingScreenId = effectInfo->MiscValue)
            player->SendDirectMessage(WorldPackets::Spells::CustomLoadScreen(m_spellInfo->Id, customLoadingScreenId).Write());

        player->TeleportTo(mapid, x, y, z, orientation, unitTarget == m_caster ? TELE_TO_SPELL | TELE_TO_NOT_LEAVE_COMBAT : 0);
    }
    else if (mapid == unitTarget->GetMapId())
        unitTarget->NearTeleportTo(x, y, z, orientation, unitTarget == m_caster);
    else
    {
        TC_LOG_ERROR("spells", "Spell::EffectTeleportUnits - spellId %u attempted to teleport creature to a different map.", m_spellInfo->Id);
        return;
    }

    // post effects for TARGET_DEST_DB
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
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!m_spellAura || !unitTarget)
        return;
    ASSERT(unitTarget == m_spellAura->GetOwner());
    m_spellAura->_ApplyEffectForTargets(effIndex);
}

void Spell::EffectApplyAreaAura(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!m_spellAura || !unitTarget)
        return;
    ASSERT (unitTarget == m_spellAura->GetOwner());
    m_spellAura->_ApplyEffectForTargets(effIndex);
}

void Spell::EffectUnlearnSpecialization(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();
    uint32 spellToUnlearn = effectInfo->TriggerSpell;

    player->RemoveSpell(spellToUnlearn);

    TC_LOG_DEBUG("spells", "Spell: %s has unlearned spell %u from %s", player->GetGUID().ToString().c_str(), spellToUnlearn, m_caster->GetGUID().ToString().c_str());
}

void Spell::EffectPowerDrain(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (effectInfo->MiscValue < 0 || effectInfo->MiscValue >= int8(MAX_POWERS))
        return;

    Powers powerType = Powers(effectInfo->MiscValue);

    if (!unitTarget || !unitTarget->IsAlive() || unitTarget->GetPowerType() != powerType || damage < 0)
        return;

    // add spell damage bonus
    uint32 bonus = m_caster->SpellDamageBonusDone(unitTarget, m_spellInfo, (uint32)damage, SPELL_DIRECT_DAMAGE, effectInfo);
    damage = bonus + uint32(bonus * variance);
    damage = unitTarget->SpellDamageBonusTaken(m_caster, m_spellInfo, uint32(damage), SPELL_DIRECT_DAMAGE, effectInfo);

    int32 newDamage = -(unitTarget->ModifyPower(powerType, -damage));

    float gainMultiplier = 0.0f;

    // Don't restore from self drain
    if (m_caster != unitTarget)
    {
        gainMultiplier = effectInfo->CalcValueMultiplier(m_originalCaster, this);

        int32 gain = int32(newDamage* gainMultiplier);

        m_caster->EnergizeBySpell(m_caster, m_spellInfo->Id, gain, powerType);
    }
    ExecuteLogEffectTakeTargetPower(effIndex, unitTarget, powerType, newDamage, gainMultiplier);
}

void Spell::EffectSendEvent(SpellEffIndex /*effIndex*/)
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
        if (effectInfo->GetProvidedTargetMask() & (TARGET_FLAG_UNIT_MASK | TARGET_FLAG_GAMEOBJECT_MASK))
            return;
        // some spells have no target entries in dbc and they use focus target
        if (focusObject)
            target = focusObject;
        /// @todo there should be a possibility to pass dest target to event script
    }

    TC_LOG_DEBUG("spells", "Spell ScriptStart %u for spellid %u in EffectSendEvent ", effectInfo->MiscValue, m_spellInfo->Id);

    if (ZoneScript* zoneScript = m_caster->GetZoneScript())
        zoneScript->ProcessEvent(target, effectInfo->MiscValue);
    else if (InstanceScript* instanceScript = m_caster->GetInstanceScript())    // needed in case Player is the caster
        instanceScript->ProcessEvent(target, effectInfo->MiscValue);

    m_caster->GetMap()->ScriptsStart(sEventScripts, effectInfo->MiscValue, m_caster, target);
}

void Spell::EffectPowerBurn(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (effectInfo->MiscValue < 0 || effectInfo->MiscValue >= int8(MAX_POWERS))
        return;

    Powers powerType = Powers(effectInfo->MiscValue);

    if (!unitTarget || !unitTarget->IsAlive() || unitTarget->GetPowerType() != powerType || damage < 0)
        return;

    int32 newDamage = -(unitTarget->ModifyPower(powerType, -damage));

    // NO - Not a typo - EffectPowerBurn uses effect value multiplier - not effect damage multiplier
    float dmgMultiplier = effectInfo->CalcValueMultiplier(m_originalCaster, this);

    // add log data before multiplication (need power amount, not damage)
    ExecuteLogEffectTakeTargetPower(effIndex, unitTarget, powerType, newDamage, 0.0f);

    newDamage = int32(newDamage* dmgMultiplier);

    m_damage += newDamage;
}

void Spell::EffectHeal(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (unitTarget && unitTarget->IsAlive() && damage >= 0)
    {
        // Try to get original caster
        Unit* caster = !m_originalCasterGUID.IsEmpty() ? m_originalCaster : m_caster;

        // Skip if m_originalCaster not available
        if (!caster)
            return;

        int32 addhealth = damage;

        // Vessel of the Naaru (Vial of the Sunwell trinket)
        if (m_spellInfo->Id == 45064)
        {
            // Amount of heal - depends from stacked Holy Energy
            int damageAmount = 0;
            if (AuraEffect const* aurEff = m_caster->GetAuraEffect(45062, 0))
            {
                damageAmount+= aurEff->GetAmount();
                m_caster->RemoveAurasDueToSpell(45062);
            }

            addhealth += damageAmount;
        }
        // Runic Healing Injector (heal increased by 25% for engineers - 3.2.0 patch change)
        else if (m_spellInfo->Id == 67489)
        {
            if (Player* player = m_caster->ToPlayer())
                if (player->HasSkill(SKILL_ENGINEERING))
                    AddPct(addhealth, 25);
        }
        // Death Pact - return pct of max health to caster
        else if (m_spellInfo->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT && m_spellInfo->SpellFamilyFlags[0] & 0x00080000)
            addhealth = caster->SpellHealingBonusDone(unitTarget, m_spellInfo, int32(caster->CountPctFromMaxHealth(damage)), HEAL, effectInfo);
        else
        {
            addhealth = caster->SpellHealingBonusDone(unitTarget, m_spellInfo, addhealth, HEAL, effectInfo);
            uint32 bonus = caster->SpellHealingBonusDone(unitTarget, m_spellInfo, addhealth, HEAL, effectInfo);
            damage = bonus + uint32(bonus * variance);
        }

        addhealth = unitTarget->SpellHealingBonusTaken(caster, m_spellInfo, addhealth, HEAL, effectInfo);

        // Remove Grievious bite if fully healed
        if (unitTarget->HasAura(48920) && (unitTarget->GetHealth() + addhealth >= unitTarget->GetMaxHealth()))
            unitTarget->RemoveAura(48920);

        m_damage -= addhealth;
    }
}

void Spell::EffectHealPct(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive() || damage < 0)
        return;

    // Skip if m_originalCaster not available
    if (!m_originalCaster)
        return;

    uint32 heal = m_originalCaster->SpellHealingBonusDone(unitTarget, m_spellInfo, unitTarget->CountPctFromMaxHealth(damage), HEAL, effectInfo);
    heal = unitTarget->SpellHealingBonusTaken(m_originalCaster, m_spellInfo, heal, HEAL, effectInfo);

    m_healing += heal;
}

void Spell::EffectHealMechanical(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive() || damage < 0)
        return;

    // Skip if m_originalCaster not available
    if (!m_originalCaster)
        return;

    uint32 heal = m_originalCaster->SpellHealingBonusDone(unitTarget, m_spellInfo, uint32(damage), HEAL, effectInfo);
    heal += uint32(heal * variance);

    m_healing += unitTarget->SpellHealingBonusTaken(m_originalCaster, m_spellInfo, heal, HEAL, effectInfo);
}

void Spell::EffectHealthLeech(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive() || damage < 0)
        return;

    uint32 bonus = m_caster->SpellDamageBonusDone(unitTarget, m_spellInfo, (uint32)damage, SPELL_DIRECT_DAMAGE, effectInfo);
    damage = bonus + uint32(bonus * variance);
    damage = unitTarget->SpellDamageBonusTaken(m_caster, m_spellInfo, uint32(damage), SPELL_DIRECT_DAMAGE, effectInfo);

    TC_LOG_DEBUG("spells", "HealthLeech :%i", damage);

    float healMultiplier = effectInfo->CalcValueMultiplier(m_originalCaster, this);

    m_damage += damage;
    // get max possible damage, don't count overkill for heal
    uint32 healthGain = uint32(-unitTarget->GetHealthGain(-damage) * healMultiplier);

    if (m_caster->IsAlive())
    {
        healthGain = m_caster->SpellHealingBonusDone(m_caster, m_spellInfo, healthGain, HEAL, effectInfo);
        healthGain = m_caster->SpellHealingBonusTaken(m_caster, m_spellInfo, healthGain, HEAL, effectInfo);

        HealInfo healInfo(m_caster, m_caster, healthGain, m_spellInfo, m_spellSchoolMask);
        m_caster->HealBySpell(healInfo);
    }
}

void Spell::DoCreateItem(uint32 /*i*/, uint32 itemtype, ItemContext context /*= ItemContext::NONE*/, std::vector<int32> const& bonusListIDs /*= std::vector<int32>()*/)
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

    uint32 num_to_add = damage;

    if (num_to_add < 1)
        num_to_add = 1;
    if (num_to_add > pProto->GetMaxStackSize())
        num_to_add = pProto->GetMaxStackSize();

    /* == gem perfection handling == */
    // this is bad, should be done using spell_loot_template (and conditions)

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
        if (msg == EQUIP_ERR_INV_FULL || msg == EQUIP_ERR_ITEM_MAX_COUNT)
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
        Item* pItem = player->StoreNewItem(dest, newitemid, true, GenerateItemRandomBonusListId(newitemid), GuidSet(), context, bonusListIDs);

        // was it successful? return error if not
        if (!pItem)
        {
            player->SendEquipError(EQUIP_ERR_ITEM_NOT_FOUND, nullptr, nullptr);
            return;
        }

        // set the "Crafted by ..." property of the item
        if (pItem->GetTemplate()->GetClass() != ITEM_CLASS_CONSUMABLE && pItem->GetTemplate()->GetClass() != ITEM_CLASS_QUEST && newitemid != 6265 && newitemid != 6948)
            pItem->SetCreator(player->GetGUID());

        // send info to the client
        player->SendNewItem(pItem, num_to_add, true, true);

        if (pItem->GetQuality() > ITEM_QUALITY_EPIC || (pItem->GetQuality() == ITEM_QUALITY_EPIC && pItem->GetItemLevel(player) >= MinNewsItemLevel))
            if (Guild* guild = player->GetGuild())
                guild->AddGuildNews(GUILD_NEWS_ITEM_CRAFTED, player->GetGUID(), 0, pProto->GetId());


        // we succeeded in creating at least one item, so a levelup is possible
        player->UpdateCraftSkill(m_spellInfo->Id);
    }
}

void Spell::EffectCreateItem(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    DoCreateItem(effIndex, effectInfo->ItemType, m_spellInfo->HasAttribute(SPELL_ATTR0_TRADESPELL) ? ItemContext::Trade_Skill : ItemContext::NONE);
    ExecuteLogEffectCreateItem(effIndex, effectInfo->ItemType);
}

void Spell::EffectCreateItem2(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();

    uint32 item_id = effectInfo->ItemType;
    ItemContext context = m_spellInfo->HasAttribute(SPELL_ATTR0_TRADESPELL) ? ItemContext::Trade_Skill : ItemContext::NONE;

    if (item_id)
        DoCreateItem(effIndex, item_id, context);

    // special case: fake item replaced by generate using spell_loot_template
    if (m_spellInfo->IsLootCrafting())
    {
        if (item_id)
        {
            if (!player->HasItemCount(item_id))
                return;

            // remove reagent
            uint32 count = 1;
            player->DestroyItemCount(item_id, count, true);

            // create some random items
            player->AutoStoreLoot(m_spellInfo->Id, LootTemplates_Spell, context);
        }
        else
            player->AutoStoreLoot(m_spellInfo->Id, LootTemplates_Spell, context);    // create some random items

        player->UpdateCraftSkill(m_spellInfo->Id);
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
    player->AutoStoreLoot(m_spellInfo->Id, LootTemplates_Spell, m_spellInfo->HasAttribute(SPELL_ATTR0_TRADESPELL) ? ItemContext::Trade_Skill : ItemContext::NONE);
    /// @todo ExecuteLogEffectCreateItem(i, m_spellInfo->Effects[i].ItemType);
}

void Spell::EffectPersistentAA(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!m_spellAura)
    {
        Unit* caster = m_caster->GetEntry() == WORLD_TRIGGER ? m_originalCaster : m_caster;
        float radius = effectInfo->CalcRadius(caster);

        // Caster not in world, might be spell triggered from aura removal
        if (!caster->IsInWorld())
            return;
        DynamicObject* dynObj = new DynamicObject(false);
        if (!dynObj->CreateDynamicObject(caster->GetMap()->GenerateLowGuid<HighGuid::DynamicObject>(), caster, m_spellInfo, *destTarget, radius, DYNAMIC_OBJECT_AREA_SPELL, m_SpellVisual))
        {
            delete dynObj;
            return;
        }

        if (Aura* aura = Aura::TryCreate(m_spellInfo, m_castId, MAX_EFFECT_MASK, dynObj, caster, GetCastDifficulty(), &m_spellValue->EffectBasePoints[0], nullptr, ObjectGuid::Empty, ObjectGuid::Empty, m_castItemEntry, m_castItemLevel))
        {
            m_spellAura = aura;
            m_spellAura->_RegisterForTargets();
        }
        else
            return;
    }

    ASSERT(m_spellAura->GetDynobjOwner());
    m_spellAura->_ApplyEffectForTargets(effIndex);
}

void Spell::EffectEnergize(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;
    if (!unitTarget->IsAlive())
        return;

    if (effectInfo->MiscValue < 0 || effectInfo->MiscValue >= int8(MAX_POWERS))
        return;

    Powers power = Powers(effectInfo->MiscValue);

    if (unitTarget->GetMaxPower(power) == 0)
        return;

    // Some level depends spells
    switch (m_spellInfo->Id)
    {
        case 24571:                                         // Blood Fury
            // Instantly increases your rage by ${(300-10*$max(0,$PL-60))/10}.
            damage -= 10 * std::max(0, std::min(30, m_caster->getLevel() - 60));
            break;
        case 24532:                                         // Burst of Energy
            // Instantly increases your energy by ${60-4*$max(0,$min(15,$PL-60))}.
            damage -= 4 * std::max(0, std::min(15, m_caster->getLevel() - 60));
            break;
        case 67490:                                         // Runic Mana Injector (mana gain increased by 25% for engineers - 3.2.0 patch change)
        {
            if (Player* player = m_caster->ToPlayer())
                if (player->HasSkill(SKILL_ENGINEERING))
                    AddPct(damage, 25);
            break;
        }
        default:
            break;
    }

    m_caster->EnergizeBySpell(unitTarget, m_spellInfo->Id, damage, power);
}

void Spell::EffectEnergizePct(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;
    if (!unitTarget->IsAlive())
        return;

    if (effectInfo->MiscValue < 0 || effectInfo->MiscValue >= int8(MAX_POWERS))
        return;

    Powers power = Powers(effectInfo->MiscValue);
    uint32 maxPower = unitTarget->GetMaxPower(power);
    if (maxPower == 0)
        return;

    uint32 gain = CalculatePct(maxPower, damage);
    m_caster->EnergizeBySpell(unitTarget, m_spellInfo->Id, gain, power);
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
            TC_LOG_ERROR("entities.player.cheat", "Possible hacking attempt: Player %s [%s] tried to loot a gameobject [%s] which is on respawn times without being in GM mode!",
                player->GetName().c_str(), player->GetGUID().ToString().c_str(), gameObjTarget->GetGUID().ToString().c_str());
            return;
        }
        // special case, already has GossipHello inside so return and avoid calling twice
        if (gameObjTarget->GetGoType() == GAMEOBJECT_TYPE_GOOBER)
        {
            gameObjTarget->Use(m_caster);
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
                if (uint32 trapEntry = gameObjTarget->GetGOInfo()->spellFocus.linkedTrap)
                    gameObjTarget->TriggeringLinkedGameObject(trapEntry, m_caster);
                return;

            case GAMEOBJECT_TYPE_CHEST:
                /// @todo possible must be moved to loot release (in different from linked triggering)
                if (gameObjTarget->GetGOInfo()->chest.triggeredEvent)
                {
                    TC_LOG_DEBUG("spells", "Chest ScriptStart id %u for GO " UI64FMTD, gameObjTarget->GetGOInfo()->chest.triggeredEvent, gameObjTarget->GetSpawnId());
                    player->GetMap()->ScriptsStart(sEventScripts, gameObjTarget->GetGOInfo()->chest.triggeredEvent, player, gameObjTarget);
                }

                // triggering linked GO
                if (uint32 trapEntry = gameObjTarget->GetGOInfo()->chest.linkedTrap)
                    gameObjTarget->TriggeringLinkedGameObject(trapEntry, m_caster);

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
        // Arathi Basin banner opening. /// @todo Verify correctness of this check
        if ((goInfo->type == GAMEOBJECT_TYPE_BUTTON && goInfo->button.noDamageImmune) ||
            (goInfo->type == GAMEOBJECT_TYPE_GOOBER && goInfo->goober.requireLOS))
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
        lockId = itemTarget->GetTemplate()->GetLockID();
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
        itemTarget->AddItemFlag(ITEM_FIELD_FLAG_UNLOCKED);
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
                if (!gameObjTarget->IsInSkillupList(player->GetGUID()) &&
                    player->UpdateGatherSkill(skillId, pureSkillValue, reqSkillValue))
                    gameObjTarget->AddToSkillupList(player->GetGUID());
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

void Spell::EffectSummonChangeItem(SpellEffIndex /*effIndex*/)
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

    uint32 newitemid = effectInfo->ItemType;
    if (!newitemid)
        return;

    uint16 pos = m_CastItem->GetPos();

    Item* pNewItem = Item::CreateItem(newitemid, 1, m_CastItem->GetContext(), player);
    if (!pNewItem)
        return;

    for (uint8 j = PERM_ENCHANTMENT_SLOT; j <= TEMP_ENCHANTMENT_SLOT; ++j)
        if (m_CastItem->GetEnchantmentId(EnchantmentSlot(j)))
            pNewItem->SetEnchantment(EnchantmentSlot(j), m_CastItem->GetEnchantmentId(EnchantmentSlot(j)), m_CastItem->GetEnchantmentDuration(EnchantmentSlot(j)), m_CastItem->GetEnchantmentCharges(EnchantmentSlot(j)));

    if (*m_CastItem->m_itemData->Durability < *m_CastItem->m_itemData->MaxDurability)
    {
        double lossPercent = 1 - *m_CastItem->m_itemData->Durability / double(m_CastItem->m_itemData->MaxDurability);
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
            m_castItemLevel = -1;

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
            m_castItemLevel = -1;

            player->BankItem(dest, pNewItem, true);
            return;
        }
    }
    else if (player->IsEquipmentPos(pos))
    {
        uint16 dest;

        player->DestroyItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), true);

        InventoryResult msg = player->CanEquipItem(m_CastItem->GetSlot(), dest, pNewItem, true);

        if (msg == EQUIP_ERR_OK || msg == EQUIP_ERR_CLIENT_LOCKED_OUT)
        {
            if (msg == EQUIP_ERR_CLIENT_LOCKED_OUT) dest = EQUIPMENT_SLOT_MAINHAND;

            // prevent crash at access and unexpected charges counting with item update queue corrupt
            if (m_CastItem == m_targets.GetItemTarget())
                m_targets.SetItemTarget(nullptr);

            m_CastItem = nullptr;
            m_castItemGUID.Clear();
            m_castItemEntry = 0;
            m_castItemLevel = -1;

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

    uint32 entry = effectInfo->MiscValue;
    if (!entry)
        return;

    SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(effectInfo->MiscValueB);
    if (!properties)
    {
        TC_LOG_ERROR("spells", "EffectSummonType: Unhandled summon type %u.", effectInfo->MiscValueB);
        return;
    }

    if (!m_originalCaster)
        return;

    bool personalSpawn = (properties->Flags & SUMMON_PROP_FLAG_PERSONAL_SPAWN) != 0;

    int32 duration = m_spellInfo->CalcDuration(m_originalCaster);

    TempSummon* summon = nullptr;

    // determine how many units should be summoned
    uint32 numSummons;

    // some spells need to summon many units, for those spells number of summons is stored in effect value
    // however so far noone found a generic check to find all of those (there's no related data in summonproperties.dbc
    // and in spell attributes, possibly we need to add a table for those)
    // so here's a list of MiscValueB values, which is currently most generic check
    switch (effectInfo->MiscValueB)
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

    switch (properties->Control)
    {
        case SUMMON_CATEGORY_WILD:
        case SUMMON_CATEGORY_ALLY:
        case SUMMON_CATEGORY_UNK:
            if (properties->Flags & 512)
            {
                SummonGuardian(effIndex, entry, properties, numSummons);
                break;
            }
            switch (SummonTitle(properties->Title))
            {
                case SummonTitle::Pet:
                case SummonTitle::Guardian:
                case SummonTitle::Runeblade:
                case SummonTitle::Minion:
                    SummonGuardian(effIndex, entry, properties, numSummons);
                    break;
                // Summons a vehicle, but doesn't force anyone to enter it (see SUMMON_CATEGORY_VEHICLE)
                case SummonTitle::Vehicle:
                case SummonTitle::Mount:
                    summon = m_caster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, m_originalCaster, m_spellInfo->Id);
                    break;
                case SummonTitle::Lightwell:
                case SummonTitle::Totem:
                {
                    summon = m_caster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, m_originalCaster, m_spellInfo->Id, 0, personalSpawn);
                    if (!summon || !summon->IsTotem())
                        return;

                    if (damage)                                            // if not spell info, DB values used
                    {
                        summon->SetMaxHealth(damage);
                        summon->SetHealth(damage);
                    }
                    break;
                }
                case SummonTitle::Companion:
                {
                    summon = m_caster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, m_originalCaster, m_spellInfo->Id, 0, personalSpawn);
                    if (!summon || !summon->HasUnitTypeMask(UNIT_MASK_MINION))
                        return;

                    summon->SelectLevel();       // some summoned creaters have different from 1 DB data for level/hp
                    summon->SetNpcFlags(NPCFlags(summon->GetCreatureTemplate()->npcflag & 0xFFFFFFFF));
                    summon->SetNpcFlags2(NPCFlags2(summon->GetCreatureTemplate()->npcflag >> 32));
                    summon->SetImmuneToAll(true);

                    summon->AI()->EnterEvadeMode();
                    break;
                }
                default:
                {
                    float radius = effectInfo->CalcRadius();

                    TempSummonType summonType = (duration == 0) ? TEMPSUMMON_DEAD_DESPAWN : TEMPSUMMON_TIMED_DESPAWN;

                    for (uint32 count = 0; count < numSummons; ++count)
                    {
                        Position pos;
                        if (count == 0)
                            pos = *destTarget;
                        else
                            // randomize position for multiple summons
                            pos = m_caster->GetRandomPoint(*destTarget, radius);

                        summon = m_originalCaster->SummonCreature(entry, pos, summonType, duration, 0, personalSpawn);
                        if (!summon)
                            continue;

                        if (properties->Control == SUMMON_CATEGORY_ALLY)
                        {
                            summon->SetOwnerGUID(m_originalCaster->GetGUID());
                            summon->SetFaction(m_originalCaster->GetFaction());
                            summon->SetCreatedBySpell(m_spellInfo->Id);
                        }

                        ExecuteLogEffectSummonObject(effIndex, summon);
                    }
                    return;
                }
            }//switch
            break;
        case SUMMON_CATEGORY_PET:
            SummonGuardian(effIndex, entry, properties, numSummons);
            break;
        case SUMMON_CATEGORY_PUPPET:
            summon = m_caster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, m_originalCaster, m_spellInfo->Id, 0, personalSpawn);
            break;
        case SUMMON_CATEGORY_VEHICLE:
            // Summoning spells (usually triggered by npc_spellclick) that spawn a vehicle and that cause the clicker
            // to cast a ride vehicle spell on the summoned unit.
            summon = m_originalCaster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, m_caster, m_spellInfo->Id);
            if (!summon || !summon->IsVehicle())
                return;

            // The spell that this effect will trigger. It has SPELL_AURA_CONTROL_VEHICLE
            uint32 spellId = VEHICLE_SPELL_RIDE_HARDCODED;
            int32 basePoints = effectInfo->CalcValue();
            if (basePoints > MAX_VEHICLE_SEATS)
            {
                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(basePoints, GetCastDifficulty());
                if (spellInfo && spellInfo->HasAura(SPELL_AURA_CONTROL_VEHICLE))
                    spellId = spellInfo->Id;
            }

            // if we have small value, it indicates seat position
            if (basePoints > 0 && basePoints < MAX_VEHICLE_SEATS)
                m_originalCaster->CastCustomSpell(spellId, SPELLVALUE_BASE_POINT0, basePoints, summon, true);
            else
                m_originalCaster->CastSpell(summon, spellId, true);

            uint32 faction = properties->Faction;
            if (!faction)
                faction = m_originalCaster->GetFaction();

            summon->SetFaction(faction);
            break;
    }

    if (summon)
    {
        summon->SetCreatorGUID(m_originalCaster->GetGUID());
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

    uint32 spellToLearn = (m_spellInfo->Id == 483 || m_spellInfo->Id == 55884) ? damage : effectInfo->TriggerSpell;
    player->LearnSpell(spellToLearn, false);

    TC_LOG_DEBUG("spells", "Spell: %s has learned spell %u from %s", player->GetGUID().ToString().c_str(), spellToLearn, m_caster->GetGUID().ToString().c_str());
}

void Spell::EffectDispel(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    // Create dispel mask by dispel type
    uint32 dispel_type = effectInfo->MiscValue;
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

    WorldPackets::Spells::DispelFailed dispelFailed;
    dispelFailed.CasterGUID = m_caster->GetGUID();
    dispelFailed.VictimGUID = unitTarget->GetGUID();
    dispelFailed.SpellID = m_spellInfo->Id;

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
                if (dispelAura.GetAura()->GetId() == itr->GetAura()->GetId())
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
            ++failCount;
            dispelFailed.FailedSpells.push_back(int32(itr->GetAura()->GetId()));
        }
        ++count;
    }

    if (!dispelFailed.FailedSpells.empty())
        m_caster->SendMessageToSet(dispelFailed.Write(), true);

    if (successList.empty())
        return;

    WorldPackets::CombatLog::SpellDispellLog spellDispellLog;
    spellDispellLog.IsBreak = false; // TODO: use me
    spellDispellLog.IsSteal = false;

    spellDispellLog.TargetGUID = unitTarget->GetGUID();
    spellDispellLog.CasterGUID = m_caster->GetGUID();
    spellDispellLog.DispelledBySpellID = m_spellInfo->Id;

    for (DispelableAura const& dispelableAura : successList)
    {
        WorldPackets::CombatLog::SpellDispellData dispellData;
        dispellData.SpellID = dispelableAura.GetAura()->GetId();
        dispellData.Harmful = false;      // TODO: use me
        dispellData.Rolled = boost::none; // TODO: use me
        dispellData.Needed = boost::none; // TODO: use me

        unitTarget->RemoveAurasDueToSpellByDispel(dispelableAura.GetAura()->GetId(), m_spellInfo->Id, dispelableAura.GetAura()->GetCasterGUID(), m_caster, dispelableAura.GetDispelCharges());

        spellDispellLog.DispellData.emplace_back(dispellData);
    }

    m_caster->SendMessageToSet(spellDispellLog.Write(), true);

    CallScriptSuccessfulDispel(effIndex);
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

    if (unitTarget->GetTypeId() == TYPEID_UNIT)
        unitTarget->GetMotionMaster()->MoveDistract(damage * IN_MILLISECONDS);

    unitTarget->StopMoving();
    unitTarget->SetFacingTo(unitTarget->GetAngle(destTarget));
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

void Spell::EffectAddFarsight(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    float radius = effectInfo->CalcRadius();
    int32 duration = m_spellInfo->CalcDuration(m_caster);
    // Caster not in world, might be spell triggered from aura removal
    if (!m_caster->IsInWorld())
        return;

    DynamicObject* dynObj = new DynamicObject(true);
    if (!dynObj->CreateDynamicObject(m_caster->GetMap()->GenerateLowGuid<HighGuid::DynamicObject>(), m_caster, m_spellInfo, *destTarget, radius, DYNAMIC_OBJECT_FARSIGHT_FOCUS, m_SpellVisual))
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

    unitTarget->ToPlayer()->SendRespecWipeConfirm(m_caster->GetGUID(), sWorld->getBoolConfig(CONFIG_NO_RESET_TALENT_COST) ? 0 : unitTarget->ToPlayer()->GetNextResetTalentsCost());
}

void Spell::EffectTeleUnitsFaceCaster(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (unitTarget->IsInFlight())
        return;

    float dis = effectInfo->CalcRadius(m_caster);

    float fx, fy, fz;
    m_caster->GetClosePoint(fx, fy, fz, unitTarget->GetCombatReach(), dis);

    unitTarget->NearTeleportTo(fx, fy, fz, -m_caster->GetOrientation(), unitTarget == m_caster);
}

void Spell::EffectLearnSkill(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (damage < 1)
        return;

    uint32 skillid = effectInfo->MiscValue;
    SkillRaceClassInfoEntry const* rcEntry = sDB2Manager.GetSkillRaceClassInfo(skillid, unitTarget->getRace(), unitTarget->getClass());
    if (!rcEntry)
        return;

    SkillTiersEntry const* tier = sObjectMgr->GetSkillTier(rcEntry->SkillTierID);
    if (!tier)
        return;

    uint16 skillval = unitTarget->ToPlayer()->GetPureSkillValue(skillid);
    unitTarget->ToPlayer()->SetSkill(skillid, damage, std::max<uint16>(skillval, 1), tier->Value[damage - 1]);
}

void Spell::EffectPlayMovie(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    uint32 movieId = effectInfo->MiscValue;
    if (!sMovieStore.LookupEntry(movieId))
        return;

    unitTarget->ToPlayer()->SendMovieStart(movieId);
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
    if (itemTarget->IsVellum())
    {
        // destroy one vellum from stack
        uint32 count = 1;
        player->DestroyItemCount(itemTarget, count, true);
        unitTarget = player;
        // and add a scroll
        damage = 1;
        DoCreateItem(effIndex, effectInfo->ItemType, m_spellInfo->HasAttribute(SPELL_ATTR0_TRADESPELL) ? ItemContext::Trade_Skill : ItemContext::NONE);
        itemTarget = nullptr;
        m_targets.SetItemTarget(nullptr);
    }
    else
    {
        // do not increase skill if vellum used
        if (!(m_CastItem && m_CastItem->GetTemplate()->GetFlags() & ITEM_FLAG_NO_REAGENT_COST))
            player->UpdateCraftSkill(m_spellInfo->Id);

        uint32 enchant_id = effectInfo->MiscValue;
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
                itemTarget->GetTemplate()->GetDefaultLocaleName(), itemTarget->GetEntry(),
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

void Spell::EffectEnchantItemPrismatic(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!itemTarget)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    uint32 enchantId = effectInfo->MiscValue;
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
            if (enchant->Effect[i] == ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET)
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
            itemTarget->GetTemplate()->GetDefaultLocaleName(), itemTarget->GetEntry(),
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

    if (!itemTarget)
        return;

    uint32 enchant_id = effectInfo->MiscValue;

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
        duration = 3600;                                    // 30 mins
    // other cases with this SpellVisual already selected
    else if (m_spellInfo->GetSpellVisual() == 215)
        duration = 1800;                                    // 30 mins
    // some fishing pole bonuses except Glow Worm which lasts full hour
    else if (m_spellInfo->GetSpellVisual() == 563 && m_spellInfo->Id != 64401)
        duration = 600;                                     // 10 mins
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
            itemTarget->GetTemplate()->GetDefaultLocaleName(), itemTarget->GetEntry(),
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

    if (!m_caster->GetPetGUID().IsEmpty())
        return;

    if (!unitTarget)
        return;

    if (unitTarget->GetTypeId() != TYPEID_UNIT)
        return;

    Creature* creatureTarget = unitTarget->ToCreature();

    if (creatureTarget->IsPet())
        return;

    if (m_caster->getClass() != CLASS_HUNTER)
        return;

    // cast finish successfully
    //SendChannelUpdate(0);
    finish();

    Pet* pet = m_caster->CreateTamedPetFrom(creatureTarget, m_spellInfo->Id);
    if (!pet)                                               // in very specific state like near world end/etc.
        return;

    // "kill" original creature
    creatureTarget->DespawnOrUnsummon();

    uint8 level = (creatureTarget->GetLevelForTarget(m_caster) < (m_caster->GetLevelForTarget(creatureTarget) - 5)) ? (m_caster->GetLevelForTarget(creatureTarget) - 5) : creatureTarget->GetLevelForTarget(m_caster);

    // prepare visual effect for levelup
    pet->SetLevel(level - 1);

    // add to world
    pet->GetMap()->AddToMap(pet->ToCreature());

    // visual effect for levelup
    pet->SetLevel(level);

    // caster have pet now
    m_caster->SetMinion(pet, true);

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        m_caster->ToPlayer()->PetSpellInitialize();
    }
}

void Spell::EffectSummonPet(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Player* owner = nullptr;
    if (m_originalCaster)
    {
        owner = m_originalCaster->ToPlayer();
        if (!owner && m_originalCaster->IsTotem())
            owner = m_originalCaster->GetCharmerOrOwnerPlayerOrPlayerItself();
    }

    uint32 petentry = effectInfo->MiscValue;

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
    Pet* pet = owner->SummonPet(petentry, x, y, z, owner->GetOrientation(), SUMMON_PET, 0);
    if (!pet)
        return;

    if (m_caster->GetTypeId() == TYPEID_UNIT)
    {
        if (m_caster->IsTotem())
            pet->SetReactState(REACT_AGGRESSIVE);
        else
            pet->SetReactState(REACT_DEFENSIVE);
    }

    pet->SetCreatedBySpell(m_spellInfo->Id);

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

    SpellInfo const* learn_spellproto = sSpellMgr->GetSpellInfo(effectInfo->TriggerSpell, DIFFICULTY_NONE);
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

    // this effect use before aura Taunt apply for prevent taunt already attacking target
    // for spell as marked "non effective at already attacking target"
    if (!unitTarget || !unitTarget->CanHaveThreatList() || unitTarget->GetVictim() == m_caster)
    {
        SendCastResult(SPELL_FAILED_DONT_REPORT);
        return;
    }

    if (!unitTarget->GetThreatManager().getOnlineContainer().empty())
    {
        // Also use this effect to set the taunter's threat to the taunted creature's highest value
        float myThreat = unitTarget->GetThreatManager().getThreat(m_caster);
        float topThreat = unitTarget->GetThreatManager().getOnlineContainer().getMostHated()->getThreat();
        if (topThreat > myThreat)
            unitTarget->GetThreatManager().doAddThreat(m_caster, topThreat - myThreat);

        //Set aggro victim to caster
        if (HostileReference* forcedVictim = unitTarget->GetThreatManager().getOnlineContainer().getReferenceByTarget(m_caster))
            unitTarget->GetThreatManager().setCurrentVictim(forcedVictim);
    }

    if (unitTarget->ToCreature()->IsAIEnabled && !unitTarget->ToCreature()->HasReactState(REACT_PASSIVE))
        unitTarget->ToCreature()->AI()->AttackStart(m_caster);
}

void Spell::EffectWeaponDmg(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive())
        return;

    // multiple weapon dmg effect workaround
    // execute only the last weapon damage
    // and handle all effects at once
    for (uint8 index = effIndex + 1; index < MAX_SPELL_EFFECTS; ++index)
    {
        SpellEffectInfo const* effect = m_spellInfo->GetEffect(index);
        if (!effect)
            continue;
        switch (effect->Effect)
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
                // Player can apply only 58567 Sunder Armor effect.
                bool needCast = !unitTarget->HasAura(58567, m_caster->GetGUID());
                if (needCast)
                    m_caster->CastSpell(unitTarget, 58567, true);

                if (Aura* aur = unitTarget->GetAura(58567, m_caster->GetGUID()))
                {
                    if (int32 num = (needCast ? 0 : 1))
                        aur->ModStackAmount(num);
                    fixed_bonus += (aur->GetStackAmount() - 1) * CalculateDamage(2, unitTarget);
                }
            }
            break;
        }
        case SPELLFAMILY_ROGUE:
        {
            // Hemorrhage
            if (m_spellInfo->SpellFamilyFlags[0] & 0x2000000)
            {
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    m_caster->ToPlayer()->AddComboPoints(1, this);
                // 50% more damage with daggers
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    if (Item* item = m_caster->ToPlayer()->GetWeaponForAttack(m_attackType, true))
                        if (item->GetTemplate()->GetSubClass() == ITEM_SUBCLASS_WEAPON_DAGGER)
                            totalDamagePercentMod *= 1.5f;
            }
            break;
        }
        case SPELLFAMILY_SHAMAN:
        {
            // Skyshatter Harness item set bonus
            // Stormstrike
            if (AuraEffect* aurEff = m_caster->IsScriptOverriden(m_spellInfo, 5634))
                m_caster->CastSpell(m_caster, 38430, true, nullptr, aurEff);
            break;
        }
        case SPELLFAMILY_DRUID:
        {
            // Mangle (Cat): CP
            if (m_spellInfo->SpellFamilyFlags[1] & 0x400)
            {
                if (m_caster->GetTypeId() == TYPEID_PLAYER)
                    m_caster->ToPlayer()->AddComboPoints(1, this);
            }
            break;
        }
        case SPELLFAMILY_HUNTER:
        {
            // Kill Shot - bonus damage from Ranged Attack Power
            if (m_spellInfo->SpellFamilyFlags[1] & 0x800000)
                spell_bonus += int32(0.45f * m_caster->GetTotalAttackPowerValue(RANGED_ATTACK));
            break;
        }
        case SPELLFAMILY_DEATHKNIGHT:
        {
            // Blood Strike
            if (m_spellInfo->SpellFamilyFlags[0] & 0x400000)
            {
                if (SpellEffectInfo const* effect = m_spellInfo->GetEffect(EFFECT_2))
                {
                    float bonusPct = effect->CalcValue(m_caster) * unitTarget->GetDiseasesByCaster(m_caster->GetGUID()) / 2.0f;
                    // Death Knight T8 Melee 4P Bonus
                    if (AuraEffect const* aurEff = m_caster->GetAuraEffect(64736, EFFECT_0))
                        AddPct(bonusPct, aurEff->GetAmount());
                    AddPct(totalDamagePercentMod, bonusPct);
                }
                break;
            }
            break;
        }
    }

    bool normalized = false;
    float weaponDamagePercentMod = 1.0f;
    for (SpellEffectInfo const* effect : m_spellInfo->GetEffects())
    {
        if (!effect)
            continue;
        switch (effect->Effect)
        {
            case SPELL_EFFECT_WEAPON_DAMAGE:
            case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                fixed_bonus += CalculateDamage(effect->EffectIndex, unitTarget);
                break;
            case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                fixed_bonus += CalculateDamage(effect->EffectIndex, unitTarget);
                normalized = true;
                break;
            case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                ApplyPct(weaponDamagePercentMod, CalculateDamage(effect->EffectIndex, unitTarget));
                break;
            default:
                break;                                      // not weapon damage effect, just skip
        }
    }

    // if (addPctMods) { percent mods are added in Unit::CalculateDamage } else { percent mods are added in Unit::MeleeDamageBonusDone }
    // this distinction is neccessary to properly inform the client about his autoattack damage values from Script_UnitDamage
    bool const addPctMods = !m_spellInfo->HasAttribute(SPELL_ATTR6_NO_DONE_PCT_DAMAGE_MODS) && (m_spellSchoolMask & SPELL_SCHOOL_MASK_NORMAL);
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

        float weapon_total_pct = m_caster->GetPctModifierValue(unitMod, TOTAL_PCT);
        if (fixed_bonus)
            fixed_bonus = int32(fixed_bonus * weapon_total_pct);
        if (spell_bonus)
            spell_bonus = int32(spell_bonus * weapon_total_pct);
    }

    int32 weaponDamage = m_caster->CalculateDamage(m_attackType, normalized, addPctMods);

    // Sequence is important
    for (SpellEffectInfo const* effect : m_spellInfo->GetEffects())
    {
        if (!effect)
            continue;
        // We assume that a spell have at most one fixed_bonus
        // and at most one weaponDamagePercentMod
        switch (effect->Effect)
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

    weaponDamage += spell_bonus;
    weaponDamage = int32(weaponDamage * totalDamagePercentMod);

    // prevent negative damage
    uint32 eff_damage(std::max(weaponDamage, 0));

    // Add melee damage bonuses (also check for negative)
    uint32 damageBonusDone = m_caster->MeleeDamageBonusDone(unitTarget, eff_damage, m_attackType, m_spellInfo);

    m_damage += unitTarget->MeleeDamageBonusTaken(m_caster, damageBonusDone, m_attackType, m_spellInfo);
}

void Spell::EffectThreat(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive() || !m_caster->IsAlive())
        return;

    if (!unitTarget->CanHaveThreatList())
        return;

    unitTarget->GetThreatManager().AddThreat(m_caster, float(damage));
}

void Spell::EffectHealMaxHealth(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive())
        return;

    int32 addhealth = 0;

    // damage == 0 - heal for caster max health
    if (damage == 0)
        addhealth = m_caster->GetMaxHealth();
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
                && (curSpellInfo->PreventionType & SPELL_PREVENTION_TYPE_SILENCE)
                && ((i == CURRENT_GENERIC_SPELL && curSpellInfo->InterruptFlags & SPELL_INTERRUPT_FLAG_INTERRUPT)
                || (i == CURRENT_CHANNELED_SPELL && curSpellInfo->HasChannelInterruptFlag(CHANNEL_INTERRUPT_FLAG_INTERRUPT))))
            {
                if (m_originalCaster)
                {
                    int32 duration = m_spellInfo->GetDuration();
                    unitTarget->GetSpellHistory()->LockSpellSchool(curSpellInfo->GetSchoolMask(), unitTarget->ModSpellDuration(m_spellInfo, unitTarget, duration, false, 1 << effIndex));
                    if (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MAGIC)
                        m_originalCaster->ProcSkillsAndAuras(unitTarget, PROC_FLAG_DONE_SPELL_MAGIC_DMG_CLASS_NEG, PROC_FLAG_TAKEN_SPELL_MAGIC_DMG_CLASS_NEG,
                            PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_HIT, PROC_HIT_INTERRUPT, nullptr, nullptr, nullptr);
                    else if (m_spellInfo->DmgClass == SPELL_DAMAGE_CLASS_MELEE)
                        m_originalCaster->ProcSkillsAndAuras(unitTarget, PROC_FLAG_DONE_SPELL_MELEE_DMG_CLASS, PROC_FLAG_TAKEN_SPELL_MELEE_DMG_CLASS,
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

    WorldObject* target = focusObject;
    if (!target)
        target = m_caster;

    float x, y, z;
    if (m_targets.HasDst())
        destTarget->GetPosition(x, y, z);
    else
        m_caster->GetClosePoint(x, y, z, DEFAULT_PLAYER_BOUNDING_RADIUS);

    Map* map = target->GetMap();
    Position pos = Position(x, y, z, target->GetOrientation());
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(target->GetOrientation(), 0.f, 0.f);
    GameObject* go = GameObject::CreateGameObject(effectInfo->MiscValue, map, pos, rot, 255, GO_STATE_READY);
    if (!go)
        return;

    PhasingHandler::InheritPhaseShift(go, m_caster);

    int32 duration = m_spellInfo->CalcDuration(m_caster);

    go->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
    go->SetSpellId(m_spellInfo->Id);

    ExecuteLogEffectSummonObject(effIndex, go);

    // Wild object not have owner and check clickable by players
    map->AddToMap(go);

    if (go->GetGoType() == GAMEOBJECT_TYPE_FLAGDROP)
        if (Player* player = m_caster->ToPlayer())
            if (Battleground* bg = player->GetBattleground())
                bg->SetDroppedFlagGUID(go->GetGUID(), player->GetTeam() == ALLIANCE ? TEAM_HORDE: TEAM_ALLIANCE);

    if (GameObject* linkedTrap = go->GetLinkedTrap())
    {
        PhasingHandler::InheritPhaseShift(linkedTrap , m_caster);

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

    switch (m_spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_GENERIC:
        {
            switch (m_spellInfo->Id)
            {
                case 55693:                                 // Remove Collapsing Cave Aura
                    if (!unitTarget)
                        return;
                    unitTarget->RemoveAurasDueToSpell(effectInfo->CalcValue());
                    break;
                // Bending Shinbone
                case 8856:
                {
                    if (!itemTarget && m_caster->GetTypeId() != TYPEID_PLAYER)
                        return;

                    uint32 spell_id = roll_chance_i(20) ? 8854 : 8855;

                    m_caster->CastSpell(m_caster, spell_id, true, nullptr);
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
                    if (!unitTarget || !unitTarget->IsAlive())
                        return;

                    // Onyxia Scale Cloak
                    if (unitTarget->HasAura(22683))
                        return;

                    // Shadow Flame
                    m_caster->CastSpell(unitTarget, 22682, true);
                    return;
                }
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
                        DoCreateItem(effIndex, item);
                    break;
                }
                case 20589: // Escape artist
                case 30918: // Improved Sprint
                {
                    // Removes snares and roots.
                    unitTarget->RemoveMovementImpairingAuras(true);
                    break;
                }
                // Plant Warmaul Ogre Banner
                case 32307:
                    if (Player* caster = m_caster->ToPlayer())
                    {
                        caster->RewardPlayerAndGroupAtEvent(18388, unitTarget);
                        if (Creature* target = unitTarget->ToCreature())
                            target->DespawnOrUnsummon();
                    }
                    break;
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
                    float radius = effectInfo->CalcRadius();
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
                    switch (rand32() % 4)
                    {
                        case 0: spellId = 46740; break;
                        case 1: spellId = 46739; break;
                        case 2: spellId = 46738; break;
                        case 3: spellId = 46736; break;
                    }
                    unitTarget->CastSpell(unitTarget, spellId, true);
                    break;
                }
                // 5, 000 Gold
                case 46642:
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    unitTarget->ToPlayer()->ModifyMoney(5000 * GOLD);

                    break;
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
                    npc->LoadEquipment();
                    return;
                }
                // Deathbolt from Thalgran Blightbringer
                // reflected by Freya's Ward
                // Retribution by Sevenfold Retribution
                case 51854:
                {
                    if (!unitTarget)
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
                    float radius = effectInfo->CalcRadius();
                    for (uint8 i = 0; i < 15; ++i)
                    {
                        m_caster->GetRandomPoint(*destTarget, radius, x, y, z);
                        m_caster->CastSpell(x, y, z, 54522, true);
                    }
                    break;
                }
                case 52173: // Coyote Spirit Despawn
                case 60243: // Blood Parrot Despawn
                    if (unitTarget->GetTypeId() == TYPEID_UNIT && unitTarget->IsSummon())
                        unitTarget->ToTempSummon()->UnSummon();
                    return;
                case 52479: // Gift of the Harvester
                    if (unitTarget && m_originalCaster)
                        m_originalCaster->CastSpell(unitTarget, urand(0, 1) ? damage : 52505, true);
                    return;
                case 53110: // Devour Humanoid
                    if (unitTarget)
                        unitTarget->CastSpell(m_caster, damage, true);
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
                case 58418:                                 // Portal to Orgrimmar
                case 58420:                                 // Portal to Stormwind
                {
                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER || effIndex != 0)
                        return;

                    // Effects for 58418 and 58420 are all DIFFICULTY_NONE so always valid
                    uint32 spellID = m_spellInfo->GetEffect(EFFECT_0)->CalcValue();
                    uint32 questID = m_spellInfo->GetEffect(EFFECT_1)->CalcValue();

                    if (unitTarget->ToPlayer()->GetQuestStatus(questID) == QUEST_STATUS_COMPLETE)
                        unitTarget->CastSpell(unitTarget, spellID, true);

                    return;
                }
                case 59317:                                 // Teleporting
                {

                    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
                        return;

                    // return from top
                    if (unitTarget->ToPlayer()->GetAreaId() == 4637)
                        unitTarget->CastSpell(unitTarget, 59316, true);
                    // teleport atop
                    else
                        unitTarget->CastSpell(unitTarget, 59314, true);

                    return;
                }
                case 62482: // Grab Crate
                {
                    if (unitTarget)
                    {
                        if (Unit* seat = m_caster->GetVehicleBase())
                        {
                            if (Unit* parent = seat->GetVehicleBase())
                            {
                                /// @todo a hack, range = 11, should after some time cast, otherwise too far
                                m_caster->CastSpell(parent, 62496, true);
                                unitTarget->CastSpell(parent, m_spellInfo->GetEffect(EFFECT_0)->CalcValue()); // DIFFICULTY_NONE, so effect always valid
                            }
                        }
                    }
                    return;
                }
                case 60123: // Lightwell
                {
                    if (m_caster->GetTypeId() != TYPEID_UNIT || !m_caster->IsSummon())
                        return;

                    uint32 spell_heal;

                    switch (m_caster->GetEntry())
                    {
                        case 31897: spell_heal = 7001; break;
                        case 31896: spell_heal = 27873; break;
                        case 31895: spell_heal = 27874; break;
                        case 31894: spell_heal = 28276; break;
                        case 31893: spell_heal = 48084; break;
                        case 31883: spell_heal = 48085; break;
                        default:
                            TC_LOG_ERROR("spells", "Unknown Lightwell spell caster %u.", m_caster->GetEntry());
                            return;
                    }

                    // proc a spellcast
                    if (Aura* chargesAura = m_caster->GetAura(59907))
                    {
                        m_caster->CastSpell(unitTarget, spell_heal, true, nullptr, nullptr, m_caster->ToTempSummon()->GetSummonerGUID());
                        if (chargesAura->ModCharges(-1))
                            m_caster->ToTempSummon()->UnSummon();
                    }

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
                        if (totem && totem->IsTotem())
                        {
                            m_caster->CastCustomSpell(totem, 55277, &basepoints0, nullptr, nullptr, true);
                        }
                    }
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

                    static uint32 const spellTarget[5] =
                    {
                        45673,                            // Bigger!
                        45672,                            // Shrunk
                        45677,                            // Yellow
                        45681,                            // Ghost
                        45683                             // Polymorph
                    };

                    m_caster->CastSpell(m_caster, spellPlayer[urand(0, 4)], true);
                    unitTarget->CastSpell(unitTarget, spellTarget[urand(0, 4)], true);
                    break;
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

    if (unitTarget->GetTypeId() == TYPEID_PLAYER)
        unitTarget->ToPlayer()->SendAttackSwingCancelAttack();     // melee and ranged forced attack cancel

    unitTarget->getHostileRefManager().UpdateVisibility();

    Unit::AttackerSet const& attackers = unitTarget->getAttackers();
    for (Unit::AttackerSet::const_iterator itr = attackers.begin(); itr != attackers.end();)
    {
        if (!(*itr)->CanSeeOrDetect(unitTarget))
            (*(itr++))->AttackStop();
        else
            ++itr;
    }

    unitTarget->m_lastSanctuaryTime = GameTime::GetGameTimeMS();

    // Vanish allows to remove all threat and cast regular stealth so other spells can be used
    if (m_caster->GetTypeId() == TYPEID_PLAYER
        && m_spellInfo->SpellFamilyName == SPELLFAMILY_ROGUE
        && (m_spellInfo->SpellFamilyFlags[0] & SPELLFAMILYFLAG0_ROGUE_VANISH))
    {
        m_caster->ToPlayer()->RemoveAurasByType(SPELL_AURA_MOD_ROOT);
        m_caster->ToPlayer()->RemoveAurasByType(SPELL_AURA_MOD_ROOT_2);
        // Overkill
        if (m_caster->ToPlayer()->HasSpell(58426))
           m_caster->CastSpell(m_caster, 58427, true);
    }
}

void Spell::EffectAddComboPoints(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (!m_caster->m_playerMovingMe)
        return;

    if (damage <= 0)
        return;

    m_caster->m_playerMovingMe->AddComboPoints(damage, this);
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
    if (casterAreaEntry && !(casterAreaEntry->Flags[0] & AREA_FLAG_ALLOW_DUELS))
    {
        SendCastResult(SPELL_FAILED_NO_DUELING);            // Dueling isn't allowed here
        return;
    }

    AreaTableEntry const* targetAreaEntry = sAreaTableStore.LookupEntry(target->GetAreaId());
    if (targetAreaEntry && !(targetAreaEntry->Flags[0] & AREA_FLAG_ALLOW_DUELS))
    {
        SendCastResult(SPELL_FAILED_NO_DUELING);            // Dueling isn't allowed here
        return;
    }

    //CREATE DUEL FLAG OBJECT
    Map* map = m_caster->GetMap();
    Position const pos =
    {
        m_caster->GetPositionX() + (unitTarget->GetPositionX() - m_caster->GetPositionX()) / 2,
        m_caster->GetPositionY() + (unitTarget->GetPositionY() - m_caster->GetPositionY()) / 2,
        m_caster->GetPositionZ(),
        m_caster->GetOrientation()
    };
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(pos.GetOrientation(), 0.f, 0.f);

    GameObject* go = GameObject::CreateGameObject(effectInfo->MiscValue, map, pos, rot, 0, GO_STATE_READY);
    if (!go)
        return;

    PhasingHandler::InheritPhaseShift(go, m_caster);

    go->SetFaction(m_caster->GetFaction());
    go->SetLevel(m_caster->getLevel()+1);
    int32 duration = m_spellInfo->CalcDuration(m_caster);
    go->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
    go->SetSpellId(m_spellInfo->Id);

    ExecuteLogEffectSummonObject(effIndex, go);

    m_caster->AddGameObject(go);
    map->AddToMap(go);
    //END

    // Send request
    WorldPackets::Duel::DuelRequested packet;
    packet.ArbiterGUID = go->GetGUID();
    packet.RequestedByGUID = caster->GetGUID();
    packet.RequestedByWowAccount = caster->GetSession()->GetAccountGUID();

    WorldPacket const* worldPacket = packet.Write();
    caster->SendDirectMessage(worldPacket);
    target->SendDirectMessage(worldPacket);

    // create duel-info
    DuelInfo* duel   = new DuelInfo;
    duel->initiator  = caster;
    duel->opponent   = target;
    duel->startTime  = 0;
    duel->startTimer = 0;
    duel->isMounted  = (GetSpellInfo()->Id == 62875); // Mounted Duel
    caster->duel     = duel;

    DuelInfo* duel2   = new DuelInfo;
    duel2->initiator  = caster;
    duel2->opponent   = caster;
    duel2->startTime  = 0;
    duel2->startTimer = 0;
    duel2->isMounted  = (GetSpellInfo()->Id == 62875); // Mounted Duel
    target->duel      = duel2;

    caster->SetDuelArbiter(go->GetGUID());
    target->SetDuelArbiter(go->GetGUID());

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
    TC_LOG_DEBUG("spells", "Player %s (%s) used the auto-unstuck feature at map %u (%f, %f, %f).", player->GetName().c_str(), player->GetGUID().ToString().c_str(), player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());

    if (player->IsInFlight())
        return;

    // if player is dead without death timer is teleported to graveyard, otherwise not apply the effect
    if (player->isDead())
    {
        if (!player->GetDeathTimer())
            player->RepopAtGraveyard();

        return;
    }

    // the player dies if hearthstone is in cooldown, else the player is teleported to home
    if (player->GetSpellHistory()->HasCooldown(8690))
    {
        player->Kill(player);
        return;
    }

    player->TeleportTo(player->m_homebindMapId, player->m_homebindX, player->m_homebindY, player->m_homebindZ, player->GetOrientation(), TELE_TO_SPELL);

    // Stuck spell trigger Hearthstone cooldown
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(8690, GetCastDifficulty());
    if (!spellInfo)
        return;
    Spell spell(player, spellInfo, TRIGGERED_FULL_MASK);
    spell.SendSpellCooldown();
}

void Spell::EffectSummonPlayer(SpellEffIndex /*effIndex*/)
{
    // workaround - this effect should not use target map
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->SendSummonRequestFrom(m_caster);
}

void Spell::EffectActivateObject(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!gameObjTarget)
        return;

    ScriptInfo activateCommand;
    activateCommand.command = SCRIPT_COMMAND_ACTIVATE_OBJECT;

    // int32 unk = effectInfo->MiscValue; // This is set for EffectActivateObject spells; needs research

    gameObjTarget->GetMap()->ScriptCommandStart(activateCommand, 0, m_caster, gameObjTarget);
}

void Spell::EffectApplyGlyph(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    std::vector<uint32>& glyphs = player->GetGlyphs(player->GetActiveTalentGroup());
    std::size_t replacedGlyph = glyphs.size();
    for (std::size_t i = 0; i < glyphs.size(); ++i)
    {
        if (std::vector<uint32> const* activeGlyphBindableSpells = sDB2Manager.GetGlyphBindableSpells(glyphs[i]))
        {
            if (std::find(activeGlyphBindableSpells->begin(), activeGlyphBindableSpells->end(), m_misc.SpellId) != activeGlyphBindableSpells->end())
            {
                replacedGlyph = i;
                player->RemoveAurasDueToSpell(sGlyphPropertiesStore.AssertEntry(glyphs[i])->SpellID);
                break;
            }
        }
    }

    uint32 glyphId = effectInfo->MiscValue;
    if (replacedGlyph < glyphs.size())
    {
        if (glyphId)
            glyphs[replacedGlyph] = glyphId;
        else
            glyphs.erase(glyphs.begin() + replacedGlyph);
    }
    else if (glyphId)
        glyphs.push_back(glyphId);

    if (GlyphPropertiesEntry const* glyphProperties = sGlyphPropertiesStore.LookupEntry(glyphId))
        player->CastSpell(player, glyphProperties->SpellID, true);

    WorldPackets::Talent::ActiveGlyphs activeGlyphs;
    activeGlyphs.Glyphs.emplace_back(m_misc.SpellId, uint16(glyphId));
    activeGlyphs.IsFullUpdate = false;
    player->SendDirectMessage(activeGlyphs.Write());
}

void Spell::EffectEnchantHeldItem(SpellEffIndex /*effIndex*/)
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

    if (effectInfo->MiscValue)
    {
        uint32 enchant_id = effectInfo->MiscValue;
        int32 duration = m_spellInfo->GetDuration(); //Try duration index first ..
        if (!duration)
            duration = damage;//+1;                  //Base points after ..
        if (!duration)
            duration = 10 * IN_MILLISECONDS;         //10 seconds for enchants which don't have listed duration

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

    int32 benefit = pet->GetCurrentFoodBenefitLevel(foodItem->GetTemplate()->GetBaseItemLevel());
    if (benefit <= 0)
        return;

    ExecuteLogEffectDestroyItem(effIndex, foodItem->GetEntry());

    uint32 count = 1;
    player->DestroyItemCount(foodItem, count, true);
    /// @todo fix crash when a spell has two effects, both pointed at the same item target

    m_caster->CastCustomSpell(pet, effectInfo->TriggerSpell, &benefit, nullptr, nullptr, true);
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

    uint8 slot = effectInfo->Effect - SPELL_EFFECT_SUMMON_OBJECT_SLOT1;
    ObjectGuid guid = m_caster->m_ObjectSlot[slot];
    if (!guid.IsEmpty())
    {
        if (GameObject* obj = m_caster->GetMap()->GetGameObject(guid))
        {
            // Recast case - null spell id to make auras not be removed on object remove from world
            if (m_spellInfo->Id == obj->GetSpellId())
                obj->SetSpellId(0);
            m_caster->RemoveGameObject(obj, true);
        }
        m_caster->m_ObjectSlot[slot].Clear();
    }

    float x, y, z;
    // If dest location if present
    if (m_targets.HasDst())
        destTarget->GetPosition(x, y, z);
    // Summon in random point all other units if location present
    else
        m_caster->GetClosePoint(x, y, z, DEFAULT_PLAYER_BOUNDING_RADIUS);

    Map* map = m_caster->GetMap();
    Position pos = Position(x, y, z, m_caster->GetOrientation());
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(m_caster->GetOrientation(), 0.f, 0.f);

    GameObject* go = GameObject::CreateGameObject(effectInfo->MiscValue, map, pos, rot, 255, GO_STATE_READY);
    if (!go)
        return;

    PhasingHandler::InheritPhaseShift(go, m_caster);

    //go->SetLevel(m_caster->getLevel());
    int32 duration = m_spellInfo->CalcDuration(m_caster);
    go->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
    go->SetSpellId(m_spellInfo->Id);
    m_caster->AddGameObject(go);

    ExecuteLogEffectSummonObject(effIndex, go);

    map->AddToMap(go);

    m_caster->m_ObjectSlot[slot] = go->GetGUID();
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
    pos = unitTarget->GetFirstCollisionPosition(unitTarget->GetDistance(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()), 0.0f);
    unitTarget->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), pos.GetOrientation(), unitTarget == m_caster);
}

void Spell::EffectReputation(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();

    int32  repChange = damage;

    uint32 factionId = effectInfo->MiscValue;

    FactionEntry const* factionEntry = sFactionStore.LookupEntry(factionId);
    if (!factionEntry)
        return;

    repChange = player->CalculateReputationGain(REPUTATION_SOURCE_SPELL, 0, repChange, factionId);

    player->GetReputationMgr().ModifyReputation(factionEntry, repChange);
}

void Spell::EffectQuestComplete(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    Player* player = unitTarget->ToPlayer();

    uint32 questId = effectInfo->MiscValue;
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

    float dist = m_caster->GetVisibilityRange();

    // clear focus
    WorldPackets::Combat::BreakTarget breakTarget;
    breakTarget.UnitGUID = m_caster->GetGUID();
    Trinity::MessageDistDelivererToHostile notifierBreak(m_caster, breakTarget.Write(), dist);
    Cell::VisitWorldObjects(m_caster, notifierBreak, dist);

    // and selection
    WorldPackets::Spells::ClearTarget clearTarget;
    clearTarget.Guid = m_caster->GetGUID();
    Trinity::MessageDistDelivererToHostile notifierClear(m_caster, clearTarget.Write(), dist);
    Cell::VisitWorldObjects(m_caster, notifierClear, dist);

    // we should also force pets to remove us from current target
    Unit::AttackerSet attackerSet;
    for (Unit::AttackerSet::const_iterator itr = m_caster->getAttackers().begin(); itr != m_caster->getAttackers().end(); ++itr)
        if ((*itr)->GetTypeId() == TYPEID_UNIT && !(*itr)->CanHaveThreatList())
            attackerSet.insert(*itr);

    for (Unit::AttackerSet::const_iterator itr = attackerSet.begin(); itr != attackerSet.end(); ++itr)
        (*itr)->AttackStop();
}

void Spell::EffectSelfResurrect(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!m_caster || m_caster->IsAlive())
        return;
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;
    if (!m_caster->IsInWorld())
        return;

    uint32 health = 0;
    uint32 mana = 0;

    // flat case
    if (damage < 0)
    {
        health = uint32(-damage);
        mana = effectInfo->MiscValue;
    }
    // percent case
    else
    {
        health = m_caster->CountPctFromMaxHealth(damage);
        if (m_caster->GetMaxPower(POWER_MANA) > 0)
            mana = CalculatePct(m_caster->GetMaxPower(POWER_MANA), damage);
    }

    Player* player = m_caster->ToPlayer();
    player->ResurrectPlayer(0.0f);

    player->SetHealth(health);
    player->SetPower(POWER_MANA, mana);
    player->SetPower(POWER_RAGE, 0);
    player->SetFullPower(POWER_ENERGY);
    player->SetPower(POWER_FOCUS, 0);

    player->SpawnCorpseBones();
}

void Spell::EffectSkinning(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (unitTarget->GetTypeId() != TYPEID_UNIT)
        return;
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Creature* creature = unitTarget->ToCreature();
    int32 targetLevel = creature->GetLevelForTarget(m_caster);

    uint32 skill = creature->GetCreatureTemplate()->GetRequiredLootSkill();

    creature->RemoveUnitFlag(UNIT_FLAG_SKINNABLE);
    creature->AddDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
    m_caster->ToPlayer()->SendLoot(creature->GetGUID(), LOOT_SKINNING);

    if (skill == SKILL_SKINNING)
    {
        int32 reqValue;
        if (targetLevel <= 10)
            reqValue = 1;
        else if (targetLevel < 20)
            reqValue = (targetLevel - 10) * 10;
        else if (targetLevel <= 73)
            reqValue = targetLevel * 5;
        else if (targetLevel < 80)
            reqValue = targetLevel * 10 - 365;
        else if (targetLevel <= 84)
            reqValue = targetLevel * 5 + 35;
        else if (targetLevel <= 87)
            reqValue = targetLevel * 15 - 805;
        else if (targetLevel <= 92)
            reqValue = (targetLevel - 62) * 20;
        else if (targetLevel <= 104)
            reqValue = targetLevel * 5 + 175;
        else if (targetLevel <= 107)
            reqValue = targetLevel * 15 - 905;
        else if (targetLevel <= 112)
            reqValue = (targetLevel - 72) * 20;
        else if (targetLevel <= 122)
            reqValue = (targetLevel - 32) * 10;
        else
            reqValue = 900;

        // TODO: Specialize skillid for each expansion
        // new db field?
        // tied to one of existing expansion fields in creature_template?

        // Double chances for elites
        m_caster->ToPlayer()->UpdateGatherSkill(skill, damage, reqValue, creature->isElite() ? 2 : 1);
    }
}

void Spell::EffectCharge(SpellEffIndex /*effIndex*/)
{
    if (!unitTarget)
        return;

    if (effectHandleMode == SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
    {
        // charge changes fall time
        if (m_caster->GetTypeId() == TYPEID_PLAYER)
            m_caster->ToPlayer()->SetFallInformation(0, m_caster->GetPositionZ());

        float speed = G3D::fuzzyGt(m_spellInfo->Speed, 0.0f) ? m_spellInfo->Speed : SPEED_CHARGE;

        Optional<Movement::SpellEffectExtraData> spellEffectExtraData;
        if (effectInfo->MiscValueB)
        {
            spellEffectExtraData = boost::in_place();
            spellEffectExtraData->Target = unitTarget->GetGUID();
            spellEffectExtraData->SpellVisualId = effectInfo->MiscValueB;
        }
        // Spell is not using explicit target - no generated path
        if (!m_preGeneratedPath)
        {
            //unitTarget->GetContactPoint(m_caster, pos.m_positionX, pos.m_positionY, pos.m_positionZ);
            Position pos = unitTarget->GetFirstCollisionPosition(unitTarget->GetCombatReach(), unitTarget->GetRelativeAngle(m_caster));
            if (G3D::fuzzyGt(m_spellInfo->Speed, 0.0f) && m_spellInfo->HasAttribute(SPELL_ATTR9_SPECIAL_DELAY_CALCULATION))
                speed = pos.GetExactDist(m_caster) / speed;

            m_caster->GetMotionMaster()->MoveCharge(pos.m_positionX, pos.m_positionY, pos.m_positionZ, speed, EVENT_CHARGE, false, unitTarget, spellEffectExtraData.get_ptr());
        }
        else
        {
            if (G3D::fuzzyGt(m_spellInfo->Speed, 0.0f) && m_spellInfo->HasAttribute(SPELL_ATTR9_SPECIAL_DELAY_CALCULATION))
            {
                G3D::Vector3 pos = m_preGeneratedPath->GetActualEndPosition();
                speed = Position(pos.x, pos.y, pos.z).GetExactDist(m_caster) / speed;
            }

            m_caster->GetMotionMaster()->MoveCharge(*m_preGeneratedPath, speed, unitTarget, spellEffectExtraData.get_ptr());
        }
    }

    if (effectHandleMode == SPELL_EFFECT_HANDLE_HIT_TARGET)
    {
        // not all charge effects used in negative spells
        if (!m_spellInfo->IsPositive() && m_caster->GetTypeId() == TYPEID_PLAYER)
            m_caster->Attack(unitTarget, true);

        if (effectInfo->TriggerSpell)
            m_caster->CastSpell(unitTarget, effectInfo->TriggerSpell, true, nullptr, nullptr, m_originalCasterGUID);
    }
}

void Spell::EffectChargeDest(SpellEffIndex /*effIndex*/)
{
    if (!destTarget)
        return;

    if (effectHandleMode == SPELL_EFFECT_HANDLE_LAUNCH)
    {
        Position pos = destTarget->GetPosition();

        if (!m_caster->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
        {
            float angle = m_caster->GetRelativeAngle(pos.GetPositionX(), pos.GetPositionY());
            float dist = m_caster->GetDistance(pos);
            pos = m_caster->GetFirstCollisionPosition(dist, angle);
        }

        m_caster->GetMotionMaster()->MoveCharge(pos.m_positionX, pos.m_positionY, pos.m_positionZ);
    }
    else if (effectHandleMode == SPELL_EFFECT_HANDLE_HIT)
    {
        if (effectInfo->TriggerSpell)
            m_caster->CastSpell(destTarget->GetPositionX(), destTarget->GetPositionY(), destTarget->GetPositionZ(), effectInfo->TriggerSpell, true, nullptr, nullptr, m_originalCasterGUID);
    }
}

void Spell::EffectKnockBack(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (m_caster->GetTypeId() == TYPEID_PLAYER || m_caster->GetOwnerGUID().IsPlayer() || m_caster->IsHunterPet())
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
    float speedxy = float(effectInfo->MiscValue) * ratio;
    float speedz = float(damage) * ratio;
    if (speedxy < 0.01f && speedz < 0.01f)
        return;

    float x, y;
    if (effectInfo->Effect == SPELL_EFFECT_KNOCK_BACK_DEST)
    {
        if (m_targets.HasDst())
            destTarget->GetPosition(x, y);
        else
            return;
    }
    else //if (m_spellInfo->Effects[i].Effect == SPELL_EFFECT_KNOCK_BACK)
    {
        m_caster->GetPosition(x, y);
    }

    unitTarget->KnockbackFrom(x, y, speedxy, speedz);
}

void Spell::EffectLeapBack(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (!unitTarget)
        return;

    float speedxy = effectInfo->MiscValue / 10.f;
    float speedz = damage / 10.f;
    // Disengage
    unitTarget->JumpTo(speedxy, speedz, m_spellInfo->IconFileDataId != 132572);

    // changes fall time
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetFallInformation(0, m_caster->GetPositionZ());
}

void Spell::EffectQuestClear(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    Player* player = unitTarget->ToPlayer();

    uint32 quest_id = effectInfo->MiscValue;

    Quest const* quest = sObjectMgr->GetQuestTemplate(quest_id);

    if (!quest)
        return;

    QuestStatus oldStatus = player->GetQuestStatus(quest_id);

    // Player has never done this quest
    if (oldStatus == QUEST_STATUS_NONE)
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
    sScriptMgr->OnQuestStatusChange(player, quest, oldStatus, QUEST_STATUS_NONE);
}

void Spell::EffectSendTaxi(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->ActivateTaxiPathTo(effectInfo->MiscValue, m_spellInfo->Id);
}

void Spell::EffectPullTowards(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    Position pos;
    if (effectInfo->Effect == SPELL_EFFECT_PULL_TOWARDS_DEST)
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

    float speedXY = float(effectInfo->MiscValue) * 0.1f;
    float speedZ = unitTarget->GetDistance(pos) / speedXY * 0.5f * Movement::gravity;

    unitTarget->GetMotionMaster()->MoveJump(pos, speedXY, speedZ);
}

void Spell::EffectChangeRaidMarker(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player || !m_targets.HasDst())
        return;

    Group* group = player->GetGroup();
    if (!group || (group->isRaidGroup() && !group->IsLeader(player->GetGUID()) && !group->IsAssistant(player->GetGUID())))
        return;

    float x, y, z;
    destTarget->GetPosition(x, y, z);

    group->AddRaidMarker(damage, player->GetMapId(), x, y, z);
}

void Spell::EffectDispelMechanic(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    uint32 mechanic = effectInfo->MiscValue;
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

    pet->SetDynamicFlags(UNIT_DYNFLAG_NONE);
    pet->RemoveUnitFlag(UNIT_FLAG_SKINNABLE);
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

    int32 mana = 0;
    for (uint8 slot = SUMMON_SLOT_TOTEM; slot < MAX_TOTEM_SLOT; ++slot)
    {
        if (!m_caster->m_SummonSlot[slot])
            continue;

        Creature* totem = m_caster->GetMap()->GetCreature(m_caster->m_SummonSlot[slot]);
        if (totem && totem->IsTotem())
        {
            uint32 spell_id = totem->m_unitData->CreatedBySpell;
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id, GetCastDifficulty());
            if (spellInfo)
            {
                std::vector<SpellPowerCost> costs = spellInfo->CalcPowerCost(m_caster, spellInfo->GetSchoolMask());
                auto m = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA; });
                if (m != costs.end())
                    mana += m->Amount;
            }

            totem->ToTotem()->UnSummon();
        }
    }

    ApplyPct(mana, damage);

    if (mana)
        m_caster->CastCustomSpell(m_caster, 39104, &mana, nullptr, nullptr, true);
}

void Spell::EffectDurabilityDamage(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    int32 slot = effectInfo->MiscValue;

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

void Spell::EffectDurabilityDamagePCT(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    int32 slot = effectInfo->MiscValue;

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

    if (!unitTarget)
        return;

    unitTarget->GetThreatManager().ModifyThreatByPercent(m_caster, damage);
}

void Spell::EffectTransmitted(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    uint32 name_id = effectInfo->MiscValue;

    Unit::AuraEffectList const& overrideSummonedGameObjects = m_caster->GetAuraEffectsByType(SPELL_AURA_OVERRIDE_SUMMONED_OBJECT);
    for (AuraEffect const* aurEff : overrideSummonedGameObjects)
    {
        if (uint32(aurEff->GetMiscValue()) == name_id)
        {
            name_id = uint32(aurEff->GetMiscValueB());
            break;
        }
    }

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
    else if (effectInfo->HasRadius() && m_spellInfo->Speed == 0)
    {
        float dis = effectInfo->CalcRadius(m_originalCaster);
        m_caster->GetClosePoint(fx, fy, fz, DEFAULT_PLAYER_BOUNDING_RADIUS, dis);
    }
    else
    {
        //GO is always friendly to it's creator, get range for friends
        float min_dis = m_spellInfo->GetMinRange(true);
        float max_dis = m_spellInfo->GetMaxRange(true);
        float dis = (float)rand_norm() * (max_dis - min_dis) + min_dis;

        m_caster->GetClosePoint(fx, fy, fz, DEFAULT_PLAYER_BOUNDING_RADIUS, dis);
    }

    Map* cMap = m_caster->GetMap();
    // if gameobject is summoning object, it should be spawned right on caster's position
    if (goinfo->type == GAMEOBJECT_TYPE_RITUAL)
        m_caster->GetPosition(fx, fy, fz);

    Position pos = { fx, fy, fz, m_caster->GetOrientation() };
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(m_caster->GetOrientation(), 0.f, 0.f);

    GameObject* go = GameObject::CreateGameObject(name_id, cMap, pos, rot, 255, GO_STATE_READY);
    if (!go)
        return;

    PhasingHandler::InheritPhaseShift(go, m_caster);

    int32 duration = m_spellInfo->CalcDuration(m_caster);

    switch (goinfo->type)
    {
        case GAMEOBJECT_TYPE_FISHINGNODE:
        {
            go->SetFaction(m_caster->GetFaction());
            ObjectGuid bobberGuid = go->GetGUID();
            // client requires fishing bobber guid in channel object slot 0 to be usable
            m_caster->SetChannelObject(0, bobberGuid);
            m_caster->AddGameObject(go);              // will removed at spell cancel

            // end time of range when possible catch fish (FISHING_BOBBER_READY_TIME..GetDuration(m_spellInfo))
            // start time == fish-FISHING_BOBBER_READY_TIME (0..GetDuration(m_spellInfo)-FISHING_BOBBER_READY_TIME)
            int32 lastSec = 0;
            switch (urand(0, 3))
            {
                case 0: lastSec =  3; break;
                case 1: lastSec =  7; break;
                case 2: lastSec = 13; break;
                case 3: lastSec = 17; break;
            }

            duration = duration - lastSec*IN_MILLISECONDS + FISHING_BOBBER_READY_TIME*IN_MILLISECONDS;
            break;
        }
        case GAMEOBJECT_TYPE_RITUAL:
        {
            if (m_caster->GetTypeId() == TYPEID_PLAYER)
            {
                go->AddUniqueUse(m_caster->ToPlayer());
                m_caster->AddGameObject(go);      // will be removed at spell cancel
            }
            break;
        }
        case GAMEOBJECT_TYPE_DUEL_ARBITER: // 52991
            m_caster->AddGameObject(go);
            break;
        case GAMEOBJECT_TYPE_FISHINGHOLE:
        case GAMEOBJECT_TYPE_CHEST:
        default:
            break;
    }

    go->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);

    go->SetOwnerGUID(m_caster->GetGUID());

    //go->SetLevel(m_caster->getLevel());
    go->SetSpellId(m_spellInfo->Id);

    ExecuteLogEffectSummonObject(effIndex, go);

    TC_LOG_DEBUG("spells", "AddObject at SpellEfects.cpp EffectTransmitted");
    //m_caster->AddGameObject(go);
    //m_ObjToDel.push_back(go);

    cMap->AddToMap(go);

    if (GameObject* linkedTrap = go->GetLinkedTrap())
    {
        PhasingHandler::InheritPhaseShift(linkedTrap, m_caster);

        linkedTrap->SetRespawnTime(duration > 0 ? duration / IN_MILLISECONDS : 0);
        //linkedTrap->SetLevel(m_caster->getLevel());
        linkedTrap->SetSpellId(m_spellInfo->Id);
        linkedTrap->SetOwnerGUID(m_caster->GetGUID());

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

    if (!itemTarget || !(itemTarget->GetTemplate()->GetFlags() & ITEM_FLAG_IS_PROSPECTABLE))
        return;

    if (itemTarget->GetCount() < 5)
        return;

    if (sWorld->getBoolConfig(CONFIG_SKILL_PROSPECTING))
    {
        uint32 SkillValue = player->GetPureSkillValue(SKILL_JEWELCRAFTING);
        uint32 reqSkillValue = itemTarget->GetTemplate()->GetRequiredSkillRank();
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

    if (!itemTarget || !(itemTarget->GetTemplate()->GetFlags() & ITEM_FLAG_IS_MILLABLE))
        return;

    if (itemTarget->GetCount() < 5)
        return;

    if (sWorld->getBoolConfig(CONFIG_SKILL_MILLING))
    {
        uint32 SkillValue = player->GetPureSkillValue(SKILL_INSCRIPTION);
        uint32 reqSkillValue = itemTarget->GetTemplate()->GetRequiredSkillRank();
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

void Spell::EffectStealBeneficialBuff(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    TC_LOG_DEBUG("spells", "Effect: StealBeneficialBuff");

    if (!unitTarget || unitTarget == m_caster)                 // can't steal from self
        return;

    DispelChargesList stealList;

    // Create dispel mask by dispel type
    uint32 dispelMask = SpellInfo::GetDispelMask(DispelType(effectInfo->MiscValue));
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

    WorldPackets::Spells::DispelFailed dispelFailed;
    dispelFailed.CasterGUID = m_caster->GetGUID();
    dispelFailed.VictimGUID = unitTarget->GetGUID();
    dispelFailed.SpellID = m_spellInfo->Id;

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
            ++failCount;
            dispelFailed.FailedSpells.push_back(int32(itr->GetAura()->GetId()));
        }
        ++count;
    }

    if (!dispelFailed.FailedSpells.empty())
        m_caster->SendMessageToSet(dispelFailed.Write(), true);

    if (successList.empty())
        return;

    WorldPackets::CombatLog::SpellDispellLog spellDispellLog;
    spellDispellLog.IsBreak = false; // TODO: use me
    spellDispellLog.IsSteal = true;

    spellDispellLog.TargetGUID = unitTarget->GetGUID();
    spellDispellLog.CasterGUID = m_caster->GetGUID();
    spellDispellLog.DispelledBySpellID = m_spellInfo->Id;

    for (std::pair<uint32, ObjectGuid> const& dispell : successList)
    {
        WorldPackets::CombatLog::SpellDispellData dispellData;
        dispellData.SpellID = dispell.first;
        dispellData.Harmful = false;      // TODO: use me
        dispellData.Rolled = boost::none; // TODO: use me
        dispellData.Needed = boost::none; // TODO: use me

        unitTarget->RemoveAurasDueToSpellBySteal(dispell.first, dispell.second, m_caster);

        spellDispellLog.DispellData.emplace_back(dispellData);
    }

    m_caster->SendMessageToSet(spellDispellLog.Write(), true);
}

void Spell::EffectKillCreditPersonal(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->KilledMonsterCredit(effectInfo->MiscValue);
}

void Spell::EffectKillCredit(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (int32 creatureEntry = effectInfo->MiscValue)
        unitTarget->ToPlayer()->RewardPlayerAndGroupAtEvent(creatureEntry, unitTarget);
}

void Spell::EffectQuestFail(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->FailQuest(effectInfo->MiscValue);
}

void Spell::EffectQuestStart(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    Player* player = unitTarget->ToPlayer();
    if (!player)
        return;

    if (Quest const* quest = sObjectMgr->GetQuestTemplate(effectInfo->MiscValue))
    {
        if (!player->CanTakeQuest(quest, false))
            return;

        if (quest->IsAutoAccept() && player->CanAddQuest(quest, false))
        {
            player->AddQuestAndCheckCompletion(quest, player);
            player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, player->GetGUID(), true, true);
        }
        else
            player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, player->GetGUID(), true, false);
    }
}

void Spell::EffectActivateRune(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = m_caster->ToPlayer();

    if (player->getClass() != CLASS_DEATH_KNIGHT)
        return;

    // needed later
    m_runesState = m_caster->ToPlayer()->GetRunesState();

    uint32 count = damage;
    if (count == 0)
        count = 1;

    // first restore fully depleted runes
    for (int32 j = 0; j < player->GetMaxPower(POWER_RUNES) && count > 0; ++j)
    {
        if (player->GetRuneCooldown(j) == player->GetRuneBaseCooldown())
        {
            player->SetRuneCooldown(j, 0);
            --count;
        }
    }

    // then the rest if we still got something left
    for (int32 j = 0; j < player->GetMaxPower(POWER_RUNES) && count > 0; ++j)
    {
        player->SetRuneCooldown(j, 0);
        --count;
    }
}

void Spell::EffectCreateTamedPet(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER || !unitTarget->GetPetGUID().IsEmpty() || unitTarget->getClass() != CLASS_HUNTER)
        return;

    uint32 creatureEntry = effectInfo->MiscValue;
    Pet* pet = unitTarget->CreateTamedPetFrom(creatureEntry, m_spellInfo->Id);
    if (!pet)
        return;

    // relocate
    float px, py, pz;
    unitTarget->GetClosePoint(px, py, pz, pet->GetCombatReach(), PET_FOLLOW_DIST, pet->GetFollowAngle());
    pet->Relocate(px, py, pz, unitTarget->GetOrientation());

    // add to world
    pet->GetMap()->AddToMap(pet->ToCreature());

    // unitTarget has pet now
    unitTarget->SetMinion(pet, true);

    if (unitTarget->GetTypeId() == TYPEID_PLAYER)
    {
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        unitTarget->ToPlayer()->PetSpellInitialize();
    }
}

void Spell::EffectDiscoverTaxi(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    uint32 nodeid = effectInfo->MiscValue;
    if (sTaxiNodesStore.LookupEntry(nodeid))
        unitTarget->ToPlayer()->GetSession()->SendDiscoverNewTaxiNode(nodeid);
}

void Spell::EffectTitanGrip(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetCanTitanGrip(true, uint32(effectInfo->MiscValue));
}

void Spell::EffectRedirectThreat(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (unitTarget)
        m_caster->SetRedirectThreat(unitTarget->GetGUID(), uint32(damage));
}

void Spell::EffectGameObjectDamage(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!gameObjTarget)
        return;

    Unit* caster = m_originalCaster;
    if (!caster)
        return;

    FactionTemplateEntry const* casterFaction = caster->GetFactionTemplateEntry();
    FactionTemplateEntry const* targetFaction = sFactionTemplateStore.LookupEntry(gameObjTarget->GetFaction());
    // Do not allow to damage GO's of friendly factions (ie: Wintergrasp Walls/Ulduar Storm Beacons)
    if (!targetFaction || (casterFaction && targetFaction && !casterFaction->IsFriendlyTo(targetFaction)))
        gameObjTarget->ModifyHealth(-damage, caster, GetSpellInfo()->Id);
}

void Spell::EffectGameObjectRepair(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!gameObjTarget)
        return;

    gameObjTarget->ModifyHealth(damage, m_caster);
}

void Spell::EffectGameObjectSetDestructionState(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!gameObjTarget || !m_originalCaster)
        return;

    Player* player = m_originalCaster->GetCharmerOrOwnerPlayerOrPlayerItself();
    gameObjTarget->SetDestructibleState(GameObjectDestructibleState(effectInfo->MiscValue), player, true);
}

void Spell::SummonGuardian(uint32 i, uint32 entry, SummonPropertiesEntry const* properties, uint32 numGuardians)
{
    Unit* caster = m_originalCaster;
    if (!caster)
        return;

    if (caster->IsTotem())
        caster = caster->ToTotem()->GetOwner();

    // in another case summon new
    uint8 level = caster->getLevel();

    // level of pet summoned using engineering item based at engineering skill level
    if (m_CastItem && caster->GetTypeId() == TYPEID_PLAYER)
        if (ItemTemplate const* proto = m_CastItem->GetTemplate())
            if (proto->GetRequiredSkill() == SKILL_ENGINEERING)
                if (uint16 skill202 = caster->ToPlayer()->GetSkillValue(SKILL_ENGINEERING))
                    level = skill202 / 5;

    float radius = 5.0f;
    int32 duration = m_spellInfo->CalcDuration(m_originalCaster);

    //TempSummonType summonType = (duration == 0) ? TEMPSUMMON_DEAD_DESPAWN : TEMPSUMMON_TIMED_DESPAWN;
    Map* map = caster->GetMap();

    for (uint32 count = 0; count < numGuardians; ++count)
    {
        Position pos;
        if (count == 0)
            pos = *destTarget;
        else
            // randomize position for multiple summons
            pos = m_caster->GetRandomPoint(*destTarget, radius);

        TempSummon* summon = map->SummonCreature(entry, pos, properties, duration, caster, m_spellInfo->Id);
        if (!summon)
            return;

        if (summon->HasUnitTypeMask(UNIT_MASK_GUARDIAN))
            ((Guardian*)summon)->InitStatsForLevel(level);

        if (properties && properties->Control == SUMMON_CATEGORY_ALLY)
            summon->SetFaction(caster->GetFaction());

        if (summon->HasUnitTypeMask(UNIT_MASK_MINION) && m_targets.HasDst())
            ((Minion*)summon)->SetFollowAngle(m_caster->GetAngle(summon));

        if (summon->GetEntry() == 27893)
        {
            UF::VisibleItem const& weapon = m_caster->ToPlayer()->m_playerData->VisibleItems[EQUIPMENT_SLOT_MAINHAND];
            if (weapon.ItemID)
            {
                summon->SetDisplayId(11686); // modelid2
                summon->SetVirtualItem(0, weapon.ItemID, weapon.ItemAppearanceModID, weapon.ItemVisual);
            }
            else
                summon->SetDisplayId(1126); // modelid1
        }

        summon->AI()->EnterEvadeMode();

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

    unitTarget->AddPetFlag(UNIT_PET_FLAG_CAN_BE_RENAMED);
}

void Spell::EffectPlayMusic(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    uint32 soundid = effectInfo->MiscValue;

    if (!sSoundKitStore.LookupEntry(soundid))
    {
        TC_LOG_ERROR("spells", "EffectPlayMusic: Sound (Id: %u) does not exist in spell %u.", soundid, m_spellInfo->Id);
        return;
    }

    unitTarget->ToPlayer()->SendDirectMessage(WorldPackets::Misc::PlayMusic(soundid).Write());
}

void Spell::EffectActivateSpec(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();
    uint32 specID = m_misc.SpecializationId;
    ChrSpecializationEntry const* spec = sChrSpecializationStore.AssertEntry(specID);

    // Safety checks done in Spell::CheckCast
    if (!spec->IsPetSpecialization())
        player->ActivateTalentGroup(spec);
    else
        player->GetPet()->SetSpecialization(specID);
}

void Spell::EffectPlaySound(SpellEffIndex /*effIndex*/)
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
        case 91604: // Restricted Flight Area
            player->GetSession()->SendNotification(LANG_ZONE_NOFLYZONE);
            break;
        default:
            break;
    }

    uint32 soundId = effectInfo->MiscValue;

    if (!sSoundKitStore.LookupEntry(soundId))
    {
        TC_LOG_ERROR("spells", "EffectPlaySound: Sound (Id: %u) does not exist in spell %u.", soundId, m_spellInfo->Id);
        return;
    }

    player->PlayDirectSound(soundId, player);
}

void Spell::EffectRemoveAura(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;
    // there may be need of specifying casterguid of removed auras
    unitTarget->RemoveAurasDueToSpell(effectInfo->TriggerSpell);
}

void Spell::EffectDamageFromMaxHealthPCT(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    m_damage += unitTarget->CountPctFromMaxHealth(damage);
}

void Spell::EffectGiveCurrency(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (!sCurrencyTypesStore.LookupEntry(effectInfo->MiscValue))
        return;

    unitTarget->ToPlayer()->ModifyCurrency(effectInfo->MiscValue, damage);
}

void Spell::EffectCastButtons(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* p_caster = m_caster->ToPlayer();
    uint32 button_id = effectInfo->MiscValue + 132;
    uint32 n_buttons = effectInfo->MiscValueB;

    for (; n_buttons; --n_buttons, ++button_id)
    {
        ActionButton const* ab = p_caster->GetActionButton(button_id);
        if (!ab || ab->GetType() != ACTION_BUTTON_SPELL)
            continue;

        //! Action button data is unverified when it's set so it can be "hacked"
        //! to contain invalid spells, so filter here.
        uint32 spell_id = ab->GetAction();
        if (!spell_id)
            continue;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id, GetCastDifficulty());
        if (!spellInfo)
            continue;

        if (!p_caster->HasSpell(spell_id) || p_caster->GetSpellHistory()->HasCooldown(spell_id))
            continue;

        if (!spellInfo->HasAttribute(SPELL_ATTR9_SUMMON_PLAYER_TOTEM))
            continue;

        TriggerCastFlags triggerFlags = TriggerCastFlags(TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_CAST_DIRECTLY | TRIGGERED_DONT_REPORT_CAST_ERROR);
        m_caster->CastSpell(m_caster, spellInfo, triggerFlags);
    }
}

void Spell::EffectRechargeItem(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    Player* player = unitTarget->ToPlayer();
    if (!player)
        return;

    if (Item* item = player->GetItemByEntry(effectInfo->ItemType))
    {
        for (ItemEffectEntry const* itemEffect : item->GetEffects())
            if (itemEffect->LegacySlotIndex <= item->m_itemData->SpellCharges.size())
                item->SetSpellCharges(itemEffect->LegacySlotIndex, itemEffect->Charges);

        item->SetState(ITEM_CHANGED, player);
    }
}

void Spell::EffectBind(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();

    WorldLocation homeLoc;
    uint32 areaId = player->GetAreaId();

    if (effectInfo->MiscValue)
        areaId = effectInfo->MiscValue;

    if (m_targets.HasDst())
        homeLoc.WorldRelocate(*destTarget);
    else
        homeLoc = player->GetWorldLocation();

    player->SetHomebind(homeLoc, areaId);
    player->SendBindPointUpdate();

    TC_LOG_DEBUG("spells", "EffectBind: New homebind X: %f, Y: %f, Z: %f, MapId: %u, AreaId: %u",
        homeLoc.GetPositionX(), homeLoc.GetPositionY(), homeLoc.GetPositionZ(), homeLoc.GetMapId(), areaId);

    // zone update
    WorldPackets::Misc::PlayerBound packet(m_caster->GetGUID(), areaId);
    player->SendDirectMessage(packet.Write());
}

void Spell::EffectSummonRaFFriend(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER || !unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    m_caster->CastSpell(unitTarget, effectInfo->TriggerSpell, true);
}

void Spell::EffectUnlockGuildVaultTab(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    // Safety checks done in Spell::CheckCast
    Player* caster = m_caster->ToPlayer();
    if (Guild* guild = caster->GetGuild())
        guild->HandleBuyBankTab(caster->GetSession(), damage - 1); // Bank tabs start at zero internally
}

void Spell::EffectSummonPersonalGameObject(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    uint32 goId = effectInfo->MiscValue;
    if (!goId)
        return;

    float x, y, z;
    if (m_targets.HasDst())
        destTarget->GetPosition(x, y, z);
    else
        m_caster->GetClosePoint(x, y, z, DEFAULT_PLAYER_BOUNDING_RADIUS);

    Map* map = m_caster->GetMap();
    Position pos = Position(x, y, z, m_caster->GetOrientation());
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(m_caster->GetOrientation(), 0.f, 0.f);
    GameObject* go = GameObject::CreateGameObject(goId, map, pos, rot, 255, GO_STATE_READY);

    if (!go)
    {
        TC_LOG_WARN("spells", "SpellEffect Failed to summon personal gameobject. SpellId %u, effect %u", m_spellInfo->Id, effIndex);
        return;
    }

    PhasingHandler::InheritPhaseShift(go, m_caster);

    int32 duration = m_spellInfo->CalcDuration(m_caster);

    go->SetRespawnTime(duration > 0 ? duration / IN_MILLISECONDS : 0);
    go->SetSpellId(m_spellInfo->Id);
    go->SetVisibleByUnitOnly(m_caster->GetGUID());

    ExecuteLogEffectSummonObject(effIndex, go);

    map->AddToMap(go);

    if (GameObject* linkedTrap = go->GetLinkedTrap())
    {
        PhasingHandler::InheritPhaseShift(linkedTrap, m_caster);

        linkedTrap->SetRespawnTime(duration > 0 ? duration / IN_MILLISECONDS : 0);
        linkedTrap->SetSpellId(m_spellInfo->Id);

        ExecuteLogEffectSummonObject(effIndex, linkedTrap);
    }
}

void Spell::EffectResurrectWithAura(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsInWorld())
        return;

    Player* target = unitTarget->ToPlayer();
    if (!target)
        return;

    if (unitTarget->IsAlive())
        return;

    if (target->IsResurrectRequested())       // already have one active request
        return;

    uint32 health = target->CountPctFromMaxHealth(damage);
    uint32 mana   = CalculatePct(target->GetMaxPower(POWER_MANA), damage);
    uint32 resurrectAura = 0;
    if (sSpellMgr->GetSpellInfo(effectInfo->TriggerSpell, DIFFICULTY_NONE))
        resurrectAura = effectInfo->TriggerSpell;

    if (resurrectAura && target->HasAura(resurrectAura))
        return;

    ExecuteLogEffectResurrect(effIndex, target);
    target->SetResurrectRequestData(m_caster, health, mana, resurrectAura);
    SendResurrectRequest(target);
}

void Spell::EffectCreateAreaTrigger(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!m_targets.HasDst())
        return;

    int32 duration = GetSpellInfo()->CalcDuration(GetCaster());

    AreaTrigger::CreateAreaTrigger(effectInfo->MiscValue, GetCaster(), nullptr, GetSpellInfo(), destTarget->GetPosition(), duration, m_SpellVisual, m_castId);
}

void Spell::EffectRemoveTalent(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    TalentEntry const* talent = sTalentStore.LookupEntry(m_misc.TalentId);
    if (!talent)
        return;

    Player* player = unitTarget ? unitTarget->ToPlayer() : nullptr;
    if (!player)
        return;

    player->RemoveTalent(talent);
    player->SendTalentsInfoData();
}

void Spell::EffectDestroyItem(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();
    if (Item* item = player->GetItemByEntry(effectInfo->ItemType))
        player->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);
}

void Spell::EffectLearnGarrisonBuilding(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (Garrison* garrison = unitTarget->ToPlayer()->GetGarrison())
        garrison->LearnBlueprint(effectInfo->MiscValue);
}

void Spell::EffectCreateGarrison(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->CreateGarrison(effectInfo->MiscValue);
}

void Spell::EffectCreateConversation(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!m_targets.HasDst())
        return;

    Conversation::CreateConversation(effectInfo->MiscValue, GetCaster(), destTarget->GetPosition(), { GetCaster()->GetGUID() }, GetSpellInfo());
}

void Spell::EffectAddGarrisonFollower(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (Garrison* garrison = unitTarget->ToPlayer()->GetGarrison())
        garrison->AddFollower(effectInfo->MiscValue);
}

void Spell::EffectCreateHeirloomItem(SpellEffIndex effIndex)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    CollectionMgr* collectionMgr = player->GetSession()->GetCollectionMgr();
    if (!collectionMgr)
        return;

    std::vector<int32> bonusList;
    bonusList.push_back(collectionMgr->GetHeirloomBonus(m_misc.Raw.Data[0]));

    DoCreateItem(effIndex, m_misc.Raw.Data[0], ItemContext::NONE, bonusList);
    ExecuteLogEffectCreateItem(effIndex, m_misc.Raw.Data[0]);
}

void Spell::EffectActivateGarrisonBuilding(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (Garrison* garrison = unitTarget->ToPlayer()->GetGarrison())
        garrison->ActivateBuilding(effectInfo->MiscValue);
}

void Spell::EffectHealBattlePetPct(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (BattlePetMgr* battlePetMgr = unitTarget->ToPlayer()->GetSession()->GetBattlePetMgr())
        battlePetMgr->HealBattlePetsPct(damage);
}

void Spell::EffectEnableBattlePets(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* plr = unitTarget->ToPlayer();
    plr->AddPlayerFlag(PLAYER_FLAGS_PET_BATTLES_UNLOCKED);
    plr->GetSession()->GetBattlePetMgr()->UnlockSlot(0);
}

void Spell::EffectLaunchQuestChoice(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsPlayer())
        return;

    unitTarget->ToPlayer()->SendPlayerChoice(GetCaster()->GetGUID(), effectInfo->MiscValue);
}

void Spell::EffectUncageBattlePet(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!m_CastItem || !m_caster || m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* plr = m_caster->ToPlayer();

    // are we allowed to learn battle pets without it?
    /*if (plr->HasPlayerFlag(PLAYER_FLAGS_PET_BATTLES_UNLOCKED))
        return; // send some error*/

    uint32 speciesId = m_CastItem->GetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID);
    uint16 breed = m_CastItem->GetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA) & 0xFFFFFF;
    uint8 quality = (m_CastItem->GetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA) >> 24) & 0xFF;
    uint16 level = m_CastItem->GetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL);
    uint32 creatureId = m_CastItem->GetModifier(ITEM_MODIFIER_BATTLE_PET_DISPLAY_ID);

    BattlePetSpeciesEntry const* speciesEntry = sBattlePetSpeciesStore.LookupEntry(speciesId);
    if (!speciesEntry)
        return;

    BattlePetMgr* battlePetMgr = plr->GetSession()->GetBattlePetMgr();
    if (!battlePetMgr)
        return;

    // TODO: This means if you put your highest lvl pet into cage, you won't be able to uncage it again which is probably wrong.
    // We will need to store maxLearnedLevel somewhere to avoid this behaviour.
    if (battlePetMgr->GetMaxPetLevel() < level)
    {
        battlePetMgr->SendError(BATTLEPETRESULT_TOO_HIGH_LEVEL_TO_UNCAGE, creatureId); // or speciesEntry.CreatureID
        SendCastResult(SPELL_FAILED_CANT_ADD_BATTLE_PET);
        return;
    }

    if (battlePetMgr->GetPetCount(speciesId) >= MAX_BATTLE_PETS_PER_SPECIES)
    {
        battlePetMgr->SendError(BATTLEPETRESULT_CANT_HAVE_MORE_PETS_OF_THAT_TYPE, creatureId); // or speciesEntry.CreatureID
        SendCastResult(SPELL_FAILED_CANT_ADD_BATTLE_PET);
        return;
    }

    battlePetMgr->AddPet(speciesId, creatureId, breed, quality, level);

    if (!plr->HasSpell(speciesEntry->SummonSpellID))
        plr->LearnSpell(speciesEntry->SummonSpellID, false);

    plr->DestroyItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), true);
    m_CastItem = nullptr;
}

void Spell::EffectUpgradeHeirloom(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (Player* player = m_caster->ToPlayer())
        if (CollectionMgr* collectionMgr = player->GetSession()->GetCollectionMgr())
            collectionMgr->UpgradeHeirloom(m_misc.Raw.Data[0], int32(m_castItemEntry));
}

void Spell::EffectApplyEnchantIllusion(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!itemTarget)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player || player->GetGUID() != itemTarget->GetOwnerGUID())
        return;

    itemTarget->SetState(ITEM_CHANGED, player);
    itemTarget->SetModifier(ITEM_MODIFIER_ENCHANT_ILLUSION_ALL_SPECS, effectInfo->MiscValue);
    if (itemTarget->IsEquipped())
        player->SetVisibleItemSlot(itemTarget->GetSlot(), itemTarget);

    player->RemoveTradeableItem(itemTarget);
    itemTarget->ClearSoulboundTradeable(player);
}

void Spell::EffectUpdatePlayerPhase(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    PhasingHandler::OnConditionChange(unitTarget);
}

void Spell::EffectUpdateZoneAurasAndPhases(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->UpdateAreaDependentAuras(unitTarget->GetAreaId());
}

void Spell::EffectGiveArtifactPower(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    if (Aura* artifactAura = m_caster->GetAura(ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE))
        if (Item* artifact = m_caster->ToPlayer()->GetItemByGuid(artifactAura->GetCastItemGUID()))
            artifact->GiveArtifactXp(damage, m_CastItem, uint32(effectInfo->MiscValue));
}

void Spell::EffectGiveArtifactPowerNoBonus(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (Aura* artifactAura = unitTarget->GetAura(ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE))
        if (Item* artifact = unitTarget->ToPlayer()->GetItemByGuid(artifactAura->GetCastItemGUID()))
            artifact->GiveArtifactXp(damage, m_CastItem, 0);
}

void Spell::EffectPlayScene(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    m_caster->ToPlayer()->GetSceneMgr().PlayScene(effectInfo->MiscValue, destTarget);
}

void Spell::EffectGiveHonor(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    WorldPackets::Combat::PvPCredit packet;
    packet.Honor = damage;
    packet.OriginalHonor = damage;

    Player* playerTarget = unitTarget->ToPlayer();
    playerTarget->AddHonorXP(damage);
    playerTarget->SendDirectMessage(packet.Write());
}

void Spell::EffectLearnTransmogSet(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->GetSession()->GetCollectionMgr()->AddTransmogSet(effectInfo->MiscValue);
}

void Spell::EffectRespecAzeriteEmpoweredItem(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!itemTarget || !itemTarget->IsAzeriteEmpoweredItem())
        return;

    Player* owner = m_caster->ToPlayer();
    if (!owner)
        return;

    AzeriteEmpoweredItem* azeriteEmpoweredItem = itemTarget->ToAzeriteEmpoweredItem();
    owner->ModifyMoney(-azeriteEmpoweredItem->GetRespecCost());

    // reapply all item mods - item level change affects stats and auras
    if (azeriteEmpoweredItem->IsEquipped())
        owner->_ApplyItemMods(azeriteEmpoweredItem, azeriteEmpoweredItem->GetSlot(), false);

    azeriteEmpoweredItem->ClearSelectedAzeritePowers();

    if (azeriteEmpoweredItem->IsEquipped())
        owner->_ApplyItemMods(azeriteEmpoweredItem, azeriteEmpoweredItem->GetSlot(), true);

    azeriteEmpoweredItem->SetState(ITEM_CHANGED, owner);
    owner->SetNumRespecs(owner->GetNumRespecs() + 1);
}

void Spell::EffectLearnAzeriteEssencePower(SpellEffIndex /*effIndex*/)
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* playerTarget = unitTarget ? unitTarget->ToPlayer() : nullptr;
    if (!playerTarget)
        return;

    Item* heartOfAzeroth = playerTarget->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ITEM_SEARCH_EVERYWHERE);
    if (!heartOfAzeroth)
        return;

    AzeriteItem* azeriteItem = heartOfAzeroth->ToAzeriteItem();
    if (!azeriteItem)
        return;

    // remove old rank and apply new one
    if (azeriteItem->IsEquipped())
    {
        if (UF::SelectedAzeriteEssences const* selectedEssences = azeriteItem->GetSelectedAzeriteEssences())
        {
            for (int32 slot = 0; slot < MAX_AZERITE_ESSENCE_SLOT; ++slot)
            {
                if (selectedEssences->AzeriteEssenceID[slot] == uint32(effectInfo->MiscValue))
                {
                    bool major = AzeriteItemMilestoneType(sDB2Manager.GetAzeriteItemMilestonePower(slot)->Type) == AzeriteItemMilestoneType::MajorEssence;
                    playerTarget->ApplyAzeriteEssence(azeriteItem, effectInfo->MiscValue, MAX_AZERITE_ESSENCE_RANK, major, false);
                    playerTarget->ApplyAzeriteEssence(azeriteItem, effectInfo->MiscValue, effectInfo->MiscValueB, major, false);
                    break;
                }
            }
        }
    }

    azeriteItem->SetEssenceRank(effectInfo->MiscValue, effectInfo->MiscValueB);
    azeriteItem->SetState(ITEM_CHANGED, playerTarget);
}
