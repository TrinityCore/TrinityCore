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
#include "CharmInfo.h"
#include "CombatLogPackets.h"
#include "CombatPackets.h"
#include "Common.h"
#include "Conversation.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "CreatureTextMgr.h"
#include "DatabaseEnv.h"
#include "DB2Stores.h"
#include "DuelPackets.h"
#include "DynamicObject.h"
#include "GameEventSender.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "GameTime.h"
#include "Garrison.h"
#include "GossipDef.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Group.h"
#include "Guild.h"
#include "InstanceScript.h"
#include "Item.h"
#include "Language.h"
#include "Log.h"
#include "Loot.h"
#include "LootMgr.h"
#include "Map.h"
#include "MiscPackets.h"
#include "MotionMaster.h"
#include "MoveSpline.h"
#include "ObjectAccessor.h"
#include "ObjectMgr.h"
#include "OutdoorPvPMgr.h"
#include "PathGenerator.h"
#include "Pet.h"
#include "PhasingHandler.h"
#include "Player.h"
#include "ReputationMgr.h"
#include "RestMgr.h"
#include "SceneObject.h"
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
#include "TraitMgr.h"
#include "TraitPacketsCommon.h"
#include "Unit.h"
#include "Util.h"
#include "World.h"
#include "WorldPacket.h"
#include "WorldSession.h"

NonDefaultConstructible<SpellEffectHandlerFn> SpellEffectHandlers[TOTAL_SPELL_EFFECTS] =
{
    &Spell::EffectNULL,                                     //  0
    &Spell::EffectInstaKill,                                //  1 SPELL_EFFECT_INSTAKILL
    &Spell::EffectSchoolDMG,                                //  2 SPELL_EFFECT_SCHOOL_DAMAGE
    &Spell::EffectDummy,                                    //  3 SPELL_EFFECT_DUMMY
    &Spell::EffectUnused,                                   //  4 SPELL_EFFECT_PORTAL_TELEPORT          unused
    &Spell::EffectNULL,                                     //  5 SPELL_EFFECT_5
    &Spell::EffectApplyAura,                                //  6 SPELL_EFFECT_APPLY_AURA
    &Spell::EffectEnvironmentalDMG,                         //  7 SPELL_EFFECT_ENVIRONMENTAL_DAMAGE
    &Spell::EffectPowerDrain,                               //  8 SPELL_EFFECT_POWER_DRAIN
    &Spell::EffectHealthLeech,                              //  9 SPELL_EFFECT_HEALTH_LEECH
    &Spell::EffectHeal,                                     // 10 SPELL_EFFECT_HEAL
    &Spell::EffectBind,                                     // 11 SPELL_EFFECT_BIND
    &Spell::EffectNULL,                                     // 12 SPELL_EFFECT_PORTAL
    &Spell::EffectTeleportToReturnPoint,                    // 13 SPELL_EFFECT_TELEPORT_TO_RETURN_POINT
    &Spell::EffectIncreaseCurrencyCap,                      // 14 SPELL_EFFECT_INCREASE_CURRENCY_CAP
    &Spell::EffectTeleportUnitsWithVisualLoadingScreen,     // 15 SPELL_EFFECT_TELEPORT_WITH_SPELL_VISUAL_KIT_LOADING_SCREEN
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
    &Spell::EffectPlayMovie,                                // 45 SPELL_EFFECT_PLAY_MOVIE
    &Spell::EffectUnused,                                   // 46 SPELL_EFFECT_SPAWN clientside, unit appears as if it was just spawned
    &Spell::EffectTradeSkill,                               // 47 SPELL_EFFECT_TRADE_SKILL
    &Spell::EffectUnused,                                   // 48 SPELL_EFFECT_STEALTH                  one spell: Base Stealth
    &Spell::EffectUnused,                                   // 49 SPELL_EFFECT_DETECT                   one spell: Detect
    &Spell::EffectTransmitted,                              // 50 SPELL_EFFECT_TRANS_DOOR
    &Spell::EffectUnused,                                   // 51 SPELL_EFFECT_FORCE_CRITICAL_HIT       unused
    &Spell::EffectNULL,                                     // 52 SPELL_EFFECT_SET_MAX_BATTLE_PET_COUNT
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
    &Spell::EffectRechargeItem,                             // 66 SPELL_EFFECT_RECHARGE_ITEM
    &Spell::EffectHealMaxHealth,                            // 67 SPELL_EFFECT_HEAL_MAX_HEALTH
    &Spell::EffectInterruptCast,                            // 68 SPELL_EFFECT_INTERRUPT_CAST
    &Spell::EffectDistract,                                 // 69 SPELL_EFFECT_DISTRACT
    &Spell::EffectNULL,                                     // 70 SPELL_EFFECT_COMPLETE_AND_REWARD_WORLD_QUEST
    &Spell::EffectPickPocket,                               // 71 SPELL_EFFECT_PICKPOCKET
    &Spell::EffectAddFarsight,                              // 72 SPELL_EFFECT_ADD_FARSIGHT
    &Spell::EffectUntrainTalents,                           // 73 SPELL_EFFECT_UNTRAIN_TALENTS
    &Spell::EffectApplyGlyph,                               // 74 SPELL_EFFECT_APPLY_GLYPH
    &Spell::EffectHealMechanical,                           // 75 SPELL_EFFECT_HEAL_MECHANICAL          one spell: Mechanical Patch Kit
    &Spell::EffectSummonObjectWild,                         // 76 SPELL_EFFECT_SUMMON_OBJECT_WILD
    &Spell::EffectScriptEffect,                             // 77 SPELL_EFFECT_SCRIPT_EFFECT
    &Spell::EffectUnused,                                   // 78 SPELL_EFFECT_ATTACK
    &Spell::EffectSanctuary,                                // 79 SPELL_EFFECT_SANCTUARY
    &Spell::EffectNULL,                                     // 80 SPELL_EFFECT_MODIFY_FOLLOWER_ITEM_LEVEL
    &Spell::EffectNULL,                                     // 81 SPELL_EFFECT_PUSH_ABILITY_TO_ACTION_BAR
    &Spell::EffectNULL,                                     // 82 SPELL_EFFECT_BIND_SIGHT
    &Spell::EffectDuel,                                     // 83 SPELL_EFFECT_DUEL
    &Spell::EffectStuck,                                    // 84 SPELL_EFFECT_STUCK
    &Spell::EffectSummonPlayer,                             // 85 SPELL_EFFECT_SUMMON_PLAYER
    &Spell::EffectActivateObject,                           // 86 SPELL_EFFECT_ACTIVATE_OBJECT
    &Spell::EffectGameObjectDamage,                         // 87 SPELL_EFFECT_GAMEOBJECT_DAMAGE
    &Spell::EffectGameObjectRepair,                         // 88 SPELL_EFFECT_GAMEOBJECT_REPAIR
    &Spell::EffectGameObjectSetDestructionState,            // 89 SPELL_EFFECT_GAMEOBJECT_SET_DESTRUCTION_STATE
    &Spell::EffectKillCreditPersonal,                       // 90 SPELL_EFFECT_KILL_CREDIT              Kill credit but only for single person
    &Spell::EffectNULL,                                     // 91 SPELL_EFFECT_THREAT_ALL
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
    &Spell::EffectNULL,                                     //105 SPELL_EFFECT_SURVEY
    &Spell::EffectChangeRaidMarker,                         //106 SPELL_EFFECT_CHANGE_RAID_MARKER
    &Spell::EffectNULL,                                     //107 SPELL_EFFECT_SHOW_CORPSE_LOOT
    &Spell::EffectDispelMechanic,                           //108 SPELL_EFFECT_DISPEL_MECHANIC
    &Spell::EffectResurrectPet,                             //109 SPELL_EFFECT_RESURRECT_PET
    &Spell::EffectDestroyAllTotems,                         //110 SPELL_EFFECT_DESTROY_ALL_TOTEMS
    &Spell::EffectDurabilityDamage,                         //111 SPELL_EFFECT_DURABILITY_DAMAGE
    &Spell::EffectNULL,                                     //112 SPELL_EFFECT_112
    &Spell::EffectCancelConversation,                       //113 SPELL_EFFECT_CANCEL_CONVERSATION
    &Spell::EffectTaunt,                                    //114 SPELL_EFFECT_ATTACK_ME
    &Spell::EffectDurabilityDamagePCT,                      //115 SPELL_EFFECT_DURABILITY_DAMAGE_PCT
    &Spell::EffectSkinPlayerCorpse,                         //116 SPELL_EFFECT_SKIN_PLAYER_CORPSE       one spell: Remove Insignia, bg usage, required special corpse flags...
    &Spell::EffectSpiritHeal,                               //117 SPELL_EFFECT_SPIRIT_HEAL              one spell: Spirit Heal
    &Spell::EffectSkill,                                    //118 SPELL_EFFECT_SKILL                    professions and more
    &Spell::EffectUnused,                                   //119 SPELL_EFFECT_APPLY_AREA_AURA_PET
    &Spell::EffectTeleportGraveyard,                        //120 SPELL_EFFECT_TELEPORT_GRAVEYARD
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
    &Spell::EffectPullTowardsDest,                          //145 SPELL_EFFECT_PULL_TOWARDS_DEST        Black Hole Effect
    &Spell::EffectNULL,                                     //146 SPELL_EFFECT_RESTORE_GARRISON_TROOP_VITALITY
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
    &Spell::EffectNULL,                                     //163 SPELL_EFFECT_OBLITERATE_ITEM
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
    &Spell::EffectNULL,                                     //175 SPELL_EFFECT_175
    &Spell::EffectSanctuary,                                //176 SPELL_EFFECT_SANCTUARY_2
    &Spell::EffectNULL,                                     //177 SPELL_EFFECT_DESPAWN_PERSISTENT_AREA_AURA
    &Spell::EffectUnused,                                   //178 SPELL_EFFECT_178 unused
    &Spell::EffectCreateAreaTrigger,                        //179 SPELL_EFFECT_CREATE_AREATRIGGER
    &Spell::EffectNULL,                                     //180 SPELL_EFFECT_UPDATE_AREATRIGGER
    &Spell::EffectRemoveTalent,                             //181 SPELL_EFFECT_REMOVE_TALENT
    &Spell::EffectNULL,                                     //182 SPELL_EFFECT_DESPAWN_AREATRIGGER
    &Spell::EffectNULL,                                     //183 SPELL_EFFECT_183
    &Spell::EffectReputation,                               //184 SPELL_EFFECT_REPUTATION_2
    &Spell::EffectNULL,                                     //185 SPELL_EFFECT_185
    &Spell::EffectNULL,                                     //186 SPELL_EFFECT_186
    &Spell::EffectNULL,                                     //187 SPELL_EFFECT_RANDOMIZE_ARCHAEOLOGY_DIGSITES
    &Spell::EffectNULL,                                     //188 SPELL_EFFECT_SUMMON_STABLED_PET_AS_GUARDIAN
    &Spell::EffectNULL,                                     //189 SPELL_EFFECT_LOOT
    &Spell::EffectNULL,                                     //190 SPELL_EFFECT_CHANGE_PARTY_MEMBERS
    &Spell::EffectNULL,                                     //191 SPELL_EFFECT_TELEPORT_TO_DIGSITE
    &Spell::EffectUncageBattlePet,                          //192 SPELL_EFFECT_UNCAGE_BATTLEPET
    &Spell::EffectNULL,                                     //193 SPELL_EFFECT_START_PET_BATTLE
    &Spell::EffectUnused,                                   //194 SPELL_EFFECT_194
    &Spell::EffectPlaySceneScriptPackage,                   //195 SPELL_EFFECT_PLAY_SCENE_SCRIPT_PACKAGE
    &Spell::EffectCreateSceneObject,                        //196 SPELL_EFFECT_CREATE_SCENE_OBJECT
    &Spell::EffectCreatePrivateSceneObject,                 //197 SPELL_EFFECT_CREATE_PERSONAL_SCENE_OBJECT
    &Spell::EffectPlayScene,                                //198 SPELL_EFFECT_PLAY_SCENE
    &Spell::EffectNULL,                                     //199 SPELL_EFFECT_DESPAWN_SUMMON
    &Spell::EffectHealBattlePetPct,                         //200 SPELL_EFFECT_HEAL_BATTLEPET_PCT
    &Spell::EffectEnableBattlePets,                         //201 SPELL_EFFECT_ENABLE_BATTLE_PETS
    &Spell::EffectUnused,                                   //202 SPELL_EFFECT_APPLY_AREA_AURA_SUMMONS
    &Spell::EffectRemoveAura,                               //203 SPELL_EFFECT_REMOVE_AURA_2
    &Spell::EffectChangeBattlePetQuality,                   //204 SPELL_EFFECT_CHANGE_BATTLEPET_QUALITY
    &Spell::EffectLaunchQuestChoice,                        //205 SPELL_EFFECT_LAUNCH_QUEST_CHOICE
    &Spell::EffectNULL,                                     //206 SPELL_EFFECT_ALTER_ITEM
    &Spell::EffectNULL,                                     //207 SPELL_EFFECT_LAUNCH_QUEST_TASK
    &Spell::EffectNULL,                                     //208 SPELL_EFFECT_SET_REPUTATION
    &Spell::EffectUnused,                                   //209 SPELL_EFFECT_209
    &Spell::EffectLearnGarrisonBuilding,                    //210 SPELL_EFFECT_LEARN_GARRISON_BUILDING
    &Spell::EffectNULL,                                     //211 SPELL_EFFECT_LEARN_GARRISON_SPECIALIZATION
    &Spell::EffectRemoveAuraBySpellLabel,                   //212 SPELL_EFFECT_REMOVE_AURA_BY_SPELL_LABEL
    &Spell::EffectJumpDest,                                 //213 SPELL_EFFECT_JUMP_DEST_2
    &Spell::EffectCreateGarrison,                           //214 SPELL_EFFECT_CREATE_GARRISON
    &Spell::EffectNULL,                                     //215 SPELL_EFFECT_UPGRADE_CHARACTER_SPELLS
    &Spell::EffectNULL,                                     //216 SPELL_EFFECT_CREATE_SHIPMENT
    &Spell::EffectNULL,                                     //217 SPELL_EFFECT_UPGRADE_GARRISON
    &Spell::EffectNULL,                                     //218 SPELL_EFFECT_218
    &Spell::EffectCreateConversation,                       //219 SPELL_EFFECT_CREATE_CONVERSATION
    &Spell::EffectAddGarrisonFollower,                      //220 SPELL_EFFECT_ADD_GARRISON_FOLLOWER
    &Spell::EffectNULL,                                     //221 SPELL_EFFECT_ADD_GARRISON_MISSION
    &Spell::EffectCreateHeirloomItem,                       //222 SPELL_EFFECT_CREATE_HEIRLOOM_ITEM
    &Spell::EffectNULL,                                     //223 SPELL_EFFECT_CHANGE_ITEM_BONUSES
    &Spell::EffectActivateGarrisonBuilding,                 //224 SPELL_EFFECT_ACTIVATE_GARRISON_BUILDING
    &Spell::EffectGrantBattlePetLevel,                      //225 SPELL_EFFECT_GRANT_BATTLEPET_LEVEL
    &Spell::EffectNULL,                                     //226 SPELL_EFFECT_TRIGGER_ACTION_SET
    &Spell::EffectNULL,                                     //227 SPELL_EFFECT_TELEPORT_TO_LFG_DUNGEON
    &Spell::EffectNULL,                                     //228 SPELL_EFFECT_228
    &Spell::EffectNULL,                                     //229 SPELL_EFFECT_SET_FOLLOWER_QUALITY
    &Spell::EffectNULL,                                     //230 SPELL_EFFECT_230
    &Spell::EffectNULL,                                     //231 SPELL_EFFECT_INCREASE_FOLLOWER_EXPERIENCE
    &Spell::EffectNULL,                                     //232 SPELL_EFFECT_REMOVE_PHASE
    &Spell::EffectNULL,                                     //233 SPELL_EFFECT_RANDOMIZE_FOLLOWER_ABILITIES
    &Spell::EffectNULL,                                     //234 SPELL_EFFECT_234
    &Spell::EffectUnused,                                   //235 SPELL_EFFECT_235
    &Spell::EffectGiveExperience,                           //236 SPELL_EFFECT_GIVE_EXPERIENCE
    &Spell::EffectGiveRestedExperience,                     //237 SPELL_EFFECT_GIVE_RESTED_EXPERIENCE_BONUS
    &Spell::EffectNULL,                                     //238 SPELL_EFFECT_INCREASE_SKILL
    &Spell::EffectNULL,                                     //239 SPELL_EFFECT_END_GARRISON_BUILDING_CONSTRUCTION
    &Spell::EffectGiveArtifactPower,                        //240 SPELL_EFFECT_GIVE_ARTIFACT_POWER
    &Spell::EffectUnused,                                   //241 SPELL_EFFECT_241
    &Spell::EffectGiveArtifactPowerNoBonus,                 //242 SPELL_EFFECT_GIVE_ARTIFACT_POWER_NO_BONUS
    &Spell::EffectApplyEnchantIllusion,                     //243 SPELL_EFFECT_APPLY_ENCHANT_ILLUSION
    &Spell::EffectNULL,                                     //244 SPELL_EFFECT_LEARN_FOLLOWER_ABILITY
    &Spell::EffectUpgradeHeirloom,                          //245 SPELL_EFFECT_UPGRADE_HEIRLOOM
    &Spell::EffectNULL,                                     //246 SPELL_EFFECT_FINISH_GARRISON_MISSION
    &Spell::EffectNULL,                                     //247 SPELL_EFFECT_ADD_GARRISON_MISSION_SET
    &Spell::EffectNULL,                                     //248 SPELL_EFFECT_FINISH_SHIPMENT
    &Spell::EffectNULL,                                     //249 SPELL_EFFECT_FORCE_EQUIP_ITEM
    &Spell::EffectNULL,                                     //250 SPELL_EFFECT_TAKE_SCREENSHOT
    &Spell::EffectNULL,                                     //251 SPELL_EFFECT_SET_GARRISON_CACHE_SIZE
    &Spell::EffectTeleportUnits,                            //252 SPELL_EFFECT_TELEPORT_UNITS
    &Spell::EffectGiveHonor,                                //253 SPELL_EFFECT_GIVE_HONOR
    &Spell::EffectJumpCharge,                               //254 SPELL_EFFECT_JUMP_CHARGE
    &Spell::EffectLearnTransmogSet,                         //255 SPELL_EFFECT_LEARN_TRANSMOG_SET
    &Spell::EffectUnused,                                   //256 SPELL_EFFECT_256
    &Spell::EffectUnused,                                   //257 SPELL_EFFECT_257
    &Spell::EffectNULL,                                     //258 SPELL_EFFECT_MODIFY_KEYSTONE
    &Spell::EffectRespecAzeriteEmpoweredItem,               //259 SPELL_EFFECT_RESPEC_AZERITE_EMPOWERED_ITEM
    &Spell::EffectNULL,                                     //260 SPELL_EFFECT_SUMMON_STABLED_PET
    &Spell::EffectNULL,                                     //261 SPELL_EFFECT_SCRAP_ITEM
    &Spell::EffectUnused,                                   //262 SPELL_EFFECT_262
    &Spell::EffectNULL,                                     //263 SPELL_EFFECT_REPAIR_ITEM
    &Spell::EffectNULL,                                     //264 SPELL_EFFECT_REMOVE_GEM
    &Spell::EffectLearnAzeriteEssencePower,                 //265 SPELL_EFFECT_LEARN_AZERITE_ESSENCE_POWER
    &Spell::EffectNULL,                                     //266 SPELL_EFFECT_SET_ITEM_BONUS_LIST_GROUP_ENTRY
    &Spell::EffectCreatePrivateConversation,                //267 SPELL_EFFECT_CREATE_PRIVATE_CONVERSATION
    &Spell::EffectNULL,                                     //268 SPELL_EFFECT_APPLY_MOUNT_EQUIPMENT
    &Spell::EffectNULL,                                     //269 SPELL_EFFECT_INCREASE_ITEM_BONUS_LIST_GROUP_STEP
    &Spell::EffectNULL,                                     //270 SPELL_EFFECT_270
    &Spell::EffectUnused,                                   //271 SPELL_EFFECT_APPLY_AREA_AURA_PARTY_NONRANDOM
    &Spell::EffectNULL,                                     //272 SPELL_EFFECT_SET_COVENANT
    &Spell::EffectNULL,                                     //273 SPELL_EFFECT_CRAFT_RUNEFORGE_LEGENDARY
    &Spell::EffectUnused,                                   //274 SPELL_EFFECT_274
    &Spell::EffectUnused,                                   //275 SPELL_EFFECT_275
    &Spell::EffectLearnTransmogIllusion,                    //276 SPELL_EFFECT_LEARN_TRANSMOG_ILLUSION
    &Spell::EffectNULL,                                     //277 SPELL_EFFECT_SET_CHROMIE_TIME
    &Spell::EffectNULL,                                     //278 SPELL_EFFECT_278
    &Spell::EffectNULL,                                     //279 SPELL_EFFECT_LEARN_GARR_TALENT
    &Spell::EffectUnused,                                   //280 SPELL_EFFECT_280
    &Spell::EffectNULL,                                     //281 SPELL_EFFECT_LEARN_SOULBIND_CONDUIT
    &Spell::EffectNULL,                                     //282 SPELL_EFFECT_CONVERT_ITEMS_TO_CURRENCY
    &Spell::EffectNULL,                                     //283 SPELL_EFFECT_COMPLETE_CAMPAIGN
    &Spell::EffectSendChatMessage,                          //284 SPELL_EFFECT_SEND_CHAT_MESSAGE
    &Spell::EffectNULL,                                     //285 SPELL_EFFECT_MODIFY_KEYSTONE_2
    &Spell::EffectGrantBattlePetExperience,                 //286 SPELL_EFFECT_GRANT_BATTLEPET_EXPERIENCE
    &Spell::EffectNULL,                                     //287 SPELL_EFFECT_SET_GARRISON_FOLLOWER_LEVEL
    &Spell::EffectNULL,                                     //288 SPELL_EFFECT_CRAFT_ITEM
    &Spell::EffectModifyAuraStacks,                         //289 SPELL_EFFECT_MODIFY_AURA_STACKS
    &Spell::EffectModifyCooldown,                           //290 SPELL_EFFECT_MODIFY_COOLDOWN
    &Spell::EffectModifyCooldowns,                          //291 SPELL_EFFECT_MODIFY_COOLDOWNS
    &Spell::EffectModifyCooldownsByCategory,                //292 SPELL_EFFECT_MODIFY_COOLDOWNS_BY_CATEGORY
    &Spell::EffectModifySpellCharges,                       //293 SPELL_EFFECT_MODIFY_CHARGES
    &Spell::EffectNULL,                                     //294 SPELL_EFFECT_CRAFT_LOOT
    &Spell::EffectNULL,                                     //295 SPELL_EFFECT_SALVAGE_ITEM
    &Spell::EffectNULL,                                     //296 SPELL_EFFECT_CRAFT_SALVAGE_ITEM
    &Spell::EffectNULL,                                     //297 SPELL_EFFECT_RECRAFT_ITEM
    &Spell::EffectNULL,                                     //298 SPELL_EFFECT_CANCEL_ALL_PRIVATE_CONVERSATIONS
    &Spell::EffectNULL,                                     //299 SPELL_EFFECT_299
    &Spell::EffectUnused,                                   //300 SPELL_EFFECT_300
    &Spell::EffectNULL,                                     //301 SPELL_EFFECT_CRAFT_ENCHANT
    &Spell::EffectNULL,                                     //302 SPELL_EFFECT_GATHERING
    &Spell::EffectCreateTraitTreeConfig,                    //303 SPELL_EFFECT_CREATE_TRAIT_TREE_CONFIG
    &Spell::EffectChangeActiveCombatTraitConfig,            //304 SPELL_EFFECT_CHANGE_ACTIVE_COMBAT_TRAIT_CONFIG
    &Spell::EffectNULL,                                     //305 SPELL_EFFECT_305
    &Spell::EffectNULL,                                     //306 SPELL_EFFECT_UPDATE_INTERACTIONS
    &Spell::EffectNULL,                                     //307 SPELL_EFFECT_307
    &Spell::EffectNULL,                                     //308 SPELL_EFFECT_CANCEL_PRELOAD_WORLD
    &Spell::EffectNULL,                                     //309 SPELL_EFFECT_PRELOAD_WORLD
    &Spell::EffectNULL,                                     //310 SPELL_EFFECT_310
    &Spell::EffectNULL,                                     //311 SPELL_EFFECT_ENSURE_WORLD_LOADED
    &Spell::EffectNULL,                                     //312 SPELL_EFFECT_312
    &Spell::EffectNULL,                                     //313 SPELL_EFFECT_CHANGE_ITEM_BONUSES_2
    &Spell::EffectNULL,                                     //314 SPELL_EFFECT_ADD_SOCKET_BONUS
    &Spell::EffectNULL,                                     //315 SPELL_EFFECT_LEARN_TRANSMOG_APPEARANCE_FROM_ITEM_MOD_APPEARANCE_GROUP
    &Spell::EffectNULL,                                     //316 SPELL_EFFECT_KILL_CREDIT_LABEL_1
    &Spell::EffectNULL,                                     //317 SPELL_EFFECT_KILL_CREDIT_LABEL_2
    &Spell::EffectNULL,                                     //318 SPELL_EFFECT_318
    &Spell::EffectNULL,                                     //319 SPELL_EFFECT_319
    &Spell::EffectNULL,                                     //320 SPELL_EFFECT_320
    &Spell::EffectNULL,                                     //321 SPELL_EFFECT_321
    &Spell::EffectNULL,                                     //322 SPELL_EFFECT_322
    &Spell::EffectNULL,                                     //323 SPELL_EFFECT_323
    &Spell::EffectNULL,                                     //324 SPELL_EFFECT_324
    &Spell::EffectNULL,                                     //325 SPELL_EFFECT_325
    &Spell::EffectNULL,                                     //326 SPELL_EFFECT_326
    &Spell::EffectNULL,                                     //327 SPELL_EFFECT_327
    &Spell::EffectNULL,                                     //328 SPELL_EFFECT_328
    &Spell::EffectNULL,                                     //329 SPELL_EFFECT_329
    &Spell::EffectNULL,                                     //330 SPELL_EFFECT_330
    &Spell::EffectNULL,                                     //331 SPELL_EFFECT_331
    &Spell::EffectNULL,                                     //332 SPELL_EFFECT_332
    &Spell::EffectNULL,                                     //333 SPELL_EFFECT_333
};

void Spell::EffectNULL()
{
    TC_LOG_DEBUG("spells", "WORLD: Spell Effect DUMMY");
}

void Spell::EffectUnused()
{
    // NOT USED BY ANY SPELL OR USELESS OR IMPLEMENTED IN DIFFERENT WAY IN TRINITY
}

void Spell::EffectResurrectNew()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!m_corpseTarget && !unitTarget)
        return;

    Player* player = nullptr;

    if (m_corpseTarget)
        player = ObjectAccessor::FindPlayer(m_corpseTarget->GetOwnerGUID());
    else if (unitTarget)
        player = unitTarget->ToPlayer();

    if (!player || player->IsAlive() || !player->IsInWorld())
        return;

    if (player->IsResurrectRequested())       // already have one active request
        return;

    uint32 health = damage;
    uint32 mana = effectInfo->MiscValue;
    ExecuteLogEffectResurrect(SpellEffectName(effectInfo->Effect), player);
    player->SetResurrectRequestData(m_caster, health, mana, 0);
    SendResurrectRequest(player);
}

void Spell::EffectInstaKill()
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

    Unit::Kill(GetUnitCasterForEffectHandlers(), unitTarget, false);
}

void Spell::EffectEnvironmentalDMG()
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
        Unit* unitCaster = GetUnitCasterForEffectHandlers();
        DamageInfo damageInfo(unitCaster, unitTarget, damage, m_spellInfo, m_spellInfo->GetSchoolMask(), SPELL_DIRECT_DAMAGE, BASE_ATTACK);
        Unit::CalcAbsorbResist(damageInfo);

        SpellNonMeleeDamage log(unitCaster, unitTarget, m_spellInfo, m_SpellVisual, m_spellInfo->GetSchoolMask(), m_castId);
        log.damage = damageInfo.GetDamage();
        log.originalDamage = damage;
        log.absorb = damageInfo.GetAbsorb();
        log.resist = damageInfo.GetResist();

        if (unitCaster)
            unitCaster->SendSpellNonMeleeDamageLog(&log);
    }
}

void Spell::EffectSchoolDMG()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (unitTarget && unitTarget->IsAlive())
    {
        bool apply_direct_bonus = true;

        // Meteor like spells (divided damage to targets)
        if (m_spellInfo->HasAttribute(SPELL_ATTR0_CU_SHARE_DAMAGE))
        {
            // divide to all targets
            if (int64 count = GetUnitTargetCountForEffect(SpellEffIndex(effectInfo->EffectIndex)))
                damage /= count;
        }

        Unit* unitCaster = GetUnitCasterForEffectHandlers();
        switch (m_spellInfo->SpellFamilyName)
        {
            case SPELLFAMILY_GENERIC:
            {
                break;
            }
            case SPELLFAMILY_WARRIOR:
            {
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
                break;
            }
            case SPELLFAMILY_DEATHKNIGHT:
            {
                break;
            }
        }

        if (unitCaster && apply_direct_bonus)
        {
            uint32 bonus = unitCaster->SpellDamageBonusDone(unitTarget, m_spellInfo, (uint32)damage, SPELL_DIRECT_DAMAGE, *effectInfo, 1, this);
            damage = bonus + uint32(bonus * variance);
            damage = unitTarget->SpellDamageBonusTaken(unitCaster, m_spellInfo, (uint32)damage, SPELL_DIRECT_DAMAGE);
        }

        m_damage += damage;
    }
}

void Spell::EffectDummy()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget && !gameObjTarget && !itemTarget && !m_corpseTarget)
        return;

    // pet auras
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
    {
        if (PetAura const* petSpell = sSpellMgr->GetPetAura(m_spellInfo->Id, effectInfo->EffectIndex))
        {
            m_caster->ToPlayer()->AddPetAura(petSpell);
            return;
        }
    }

    // normal DB scripted effect
    TC_LOG_DEBUG("spells", "Spell ScriptStart spellid {} in EffectDummy({})", m_spellInfo->Id, effectInfo->EffectIndex);
    m_caster->GetMap()->ScriptsStart(sSpellScripts, uint32(m_spellInfo->Id | (effectInfo->EffectIndex << 24)), m_caster, unitTarget);
}

void Spell::EffectTriggerSpell()
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
            // Demonic Empowerment -- succubus
            case 54437:
            {
                unitTarget->RemoveMovementImpairingAuras(true);
                unitTarget->RemoveAurasByType(SPELL_AURA_MOD_STALKED);
                unitTarget->RemoveAurasByType(SPELL_AURA_MOD_STUN);

                // Cast Lesser Invisibility
                unitTarget->CastSpell(unitTarget, 7870, this);
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
                    m_caster->CastSpell(unitTarget, spell->Id, this);
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
                    m_caster->CastSpell(unitTarget, spell->Id, this);
                return;
            }
        }
    }

    if (triggered_spell_id == 0)
    {
        TC_LOG_WARN("spells.effect.nospell", "Spell::EffectTriggerSpell: Spell {} [EffectIndex: {}] does not have triggered spell.", m_spellInfo->Id, effectInfo->EffectIndex);
        return;
    }

    // normal case
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggered_spell_id, GetCastDifficulty());
    if (!spellInfo)
    {
        TC_LOG_ERROR("spells.effect.nospell", "Spell::EffectTriggerSpell spell {} tried to trigger unknown spell {}", m_spellInfo->Id, triggered_spell_id);
        return;
    }

    SpellCastTargets targets;
    Optional<int32> targetCount;
    Optional<int32> targetIndex;
    if (effectHandleMode == SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
    {
        if (!spellInfo->NeedsToBeTriggeredByCaster(m_spellInfo))
            return;
        targets.SetUnitTarget(unitTarget);
        targetCount = GetUnitTargetCountForEffect(effectInfo->EffectIndex);
        targetIndex = GetUnitTargetIndexForEffect(unitTarget->GetGUID(), effectInfo->EffectIndex);
    }
    else //if (effectHandleMode == SPELL_EFFECT_HANDLE_LAUNCH)
    {
        if (spellInfo->NeedsToBeTriggeredByCaster(m_spellInfo) && (effectInfo->GetProvidedTargetMask() & TARGET_FLAG_UNIT_MASK))
            return;

        if (spellInfo->GetExplicitTargetMask() & TARGET_FLAG_DEST_LOCATION && m_targets.HasDst())
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

    Milliseconds delay = 0ms;
    if (effectInfo->Effect == SPELL_EFFECT_TRIGGER_SPELL)
        delay = Milliseconds(effectInfo->MiscValue);

    m_caster->m_Events.AddEventAtOffset([caster = m_caster, targets, originalCaster = m_originalCasterGUID, castItemGuid = m_castItemGUID, originalCastId = m_castId,
        spellEffectInfo = effectInfo, value = damage, itemLevel = m_castItemLevel, targetCount, targetIndex]() mutable
    {
        targets.Update(caster); // refresh pointers stored in targets

        // original caster guid only for GO cast
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.SetOriginalCaster(originalCaster);
        args.OriginalCastId = originalCastId;
        args.OriginalCastItemLevel = itemLevel;
        if (!castItemGuid.IsEmpty() && sSpellMgr->AssertSpellInfo(spellEffectInfo->TriggerSpell, caster->GetMap()->GetDifficultyID())->HasAttribute(SPELL_ATTR2_RETAIN_ITEM_CAST))
            if (Player const* triggeringAuraCaster = Object::ToPlayer(caster))
                args.CastItem = triggeringAuraCaster->GetItemByGuid(castItemGuid);

        // set basepoints for trigger with value effect
        if (spellEffectInfo->Effect == SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE)
            for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
                args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0 + i), value);

        if (targetCount)
            args.AddSpellMod(SPELLVALUE_PARENT_SPELL_TARGET_COUNT, *targetCount);

        if (targetIndex)
            args.AddSpellMod(SPELLVALUE_PARENT_SPELL_TARGET_INDEX, *targetIndex);

        caster->CastSpell(std::move(targets), spellEffectInfo->TriggerSpell, args);
    }, delay);
}

void Spell::EffectTriggerMissileSpell()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET
        && effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    uint32 triggered_spell_id = effectInfo->TriggerSpell;
    if (triggered_spell_id == 0)
    {
        TC_LOG_WARN("spells.effect.nospell", "Spell::EffectTriggerMissileSpell: Spell {} [EffectIndex: {}] does not have triggered spell.", m_spellInfo->Id, effectInfo->EffectIndex);
        return;
    }

    // normal case
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggered_spell_id, GetCastDifficulty());
    if (!spellInfo)
    {
        TC_LOG_ERROR("spells.effect.nospell", "Spell::EffectTriggerMissileSpell spell {} tried to trigger unknown spell {}.", m_spellInfo->Id, triggered_spell_id);
        return;
    }

    SpellCastTargets targets;
    Optional<int32> targetCount;
    Optional<int32> targetIndex;
    if (effectHandleMode == SPELL_EFFECT_HANDLE_HIT_TARGET)
    {
        if (!spellInfo->NeedsToBeTriggeredByCaster(m_spellInfo))
            return;
        targets.SetUnitTarget(unitTarget);
        targetCount = GetUnitTargetCountForEffect(effectInfo->EffectIndex);
        targetIndex = GetUnitTargetIndexForEffect(unitTarget->GetGUID(), effectInfo->EffectIndex);
    }
    else //if (effectHandleMode == SPELL_EFFECT_HANDLE_HIT)
    {
        if (spellInfo->NeedsToBeTriggeredByCaster(m_spellInfo) && (effectInfo->GetProvidedTargetMask() & TARGET_FLAG_UNIT_MASK))
            return;

        if (spellInfo->GetExplicitTargetMask() & TARGET_FLAG_DEST_LOCATION)
            targets.SetDst(m_targets);

        if (Unit* unit = m_caster->ToUnit())
            targets.SetUnitTarget(unit);
        else if (GameObject* go = m_caster->ToGameObject())
            targets.SetGOTarget(go);
    }

    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
    args.SetOriginalCaster(m_originalCasterGUID);
    args.SetTriggeringSpell(this);
    args.SetCustomArg(m_customArg);

    // set basepoints for trigger with value effect
    if (effectInfo->Effect == SPELL_EFFECT_TRIGGER_MISSILE_SPELL_WITH_VALUE)
        for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0 + i), damage);

    if (targetCount)
        args.AddSpellMod(SPELLVALUE_PARENT_SPELL_TARGET_COUNT, *targetCount);

    if (targetIndex)
        args.AddSpellMod(SPELLVALUE_PARENT_SPELL_TARGET_INDEX, *targetIndex);

    // original caster guid only for GO cast
    m_caster->CastSpell(std::move(targets), spellInfo->Id, args);
}

void Spell::EffectForceCast()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    uint32 triggered_spell_id = effectInfo->TriggerSpell;
    if (triggered_spell_id == 0)
    {
        TC_LOG_WARN("spells.effect.nospell", "Spell::EffectForceCast: Spell {} [EffectIndex: {}] does not have triggered spell.", m_spellInfo->Id, effectInfo->EffectIndex);
        return;
    }

    // normal case
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggered_spell_id, GetCastDifficulty());

    if (!spellInfo)
    {
        TC_LOG_ERROR("spells.effect.nospell", "Spell::EffectForceCast of spell {}: triggering unknown spell id {}.", m_spellInfo->Id, triggered_spell_id);
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
            {
                CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                args.SetOriginalCaster(m_originalCasterGUID);
                args.SetTriggeringSpell(this);
                args.AddSpellMod(SPELLVALUE_BASE_POINT0, damage);
                unitTarget->CastSpell(unitTarget, spellInfo->Id, args);
                return;
            }
        }
    }

    switch (spellInfo->Id)
    {
        case 72298: // Malleable Goo Summon
            unitTarget->CastSpell(unitTarget, spellInfo->Id, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                .SetOriginalCaster(m_originalCasterGUID)
                .SetTriggeringSpell(this));
            return;
    }

    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
    args.SetTriggeringSpell(this);
    if (effectInfo->Effect == SPELL_EFFECT_FORCE_CAST_WITH_VALUE)
        for (uint32 i = 0; i < MAX_SPELL_EFFECTS; ++i)
            args.AddSpellMod(SpellValueMod(SPELLVALUE_BASE_POINT0 + i), damage);

    unitTarget->CastSpell(m_caster, spellInfo->Id, args);
}

void Spell::EffectTriggerRitualOfSummoning()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    uint32 triggered_spell_id = effectInfo->TriggerSpell;
    if (triggered_spell_id == 0)
    {
        TC_LOG_WARN("spells.effect.nospell", "Spell::EffectTriggerRitualOfSummoning: Spell {} [EffectIndex: {}] does not have triggered spell.", m_spellInfo->Id, effectInfo->EffectIndex);
        return;
    }

    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(triggered_spell_id, GetCastDifficulty());

    if (!spellInfo)
    {
        TC_LOG_ERROR("spells.effect.nospell", "EffectTriggerRitualOfSummoning of spell {}: triggering unknown spell id {}.", m_spellInfo->Id, triggered_spell_id);
        return;
    }

    finish();

    m_caster->CastSpell(nullptr, spellInfo->Id, CastSpellExtraArgs()
        .SetTriggeringSpell(this));
}

void Spell::CalculateJumpSpeeds(SpellEffectInfo const* effInfo, float dist, float& speedXY, float& speedZ)
{
    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    ASSERT(unitCaster);

    float multiplier = effInfo->Amplitude;
    if (multiplier <= 0.0f)
        multiplier = 1.0f;

    float minHeight = effInfo->MiscValue  ? effInfo->MiscValue  / 10.0f :    0.5f; // Lower bound is blizzlike
    float maxHeight = effInfo->MiscValueB ? effInfo->MiscValueB / 10.0f : 1000.0f; // Upper bound is unknown

    unitCaster->GetMotionMaster()->CalculateJumpSpeeds(dist, MOVE_RUN, multiplier, minHeight, maxHeight, speedXY, speedZ);
}

void Spell::EffectJump()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    if (unitCaster->IsInFlight())
        return;

    if (!unitTarget)
        return;

    float speedXY, speedZ;
    CalculateJumpSpeeds(effectInfo, unitCaster->GetExactDist2d(unitTarget), speedXY, speedZ);
    MovementFacingTarget facing;
    if (Unit const* target = m_targets.GetUnitTarget())
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR9_FACE_UNIT_TARGET_UPON_COMPLETION_OF_JUMP_CHARGE))
            facing = target;
    }

    JumpArrivalCastArgs arrivalCast;
    arrivalCast.SpellId = effectInfo->TriggerSpell;
    arrivalCast.Target = unitTarget->GetGUID();
    unitCaster->GetMotionMaster()->MoveJump(*unitTarget, speedXY, speedZ, EVENT_JUMP, facing, m_spellInfo->HasAttribute(SPELL_ATTR9_JUMPCHARGE__NO_FACING_CONTROL), &arrivalCast);
}

void Spell::EffectJumpDest()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    if (unitCaster->IsInFlight())
        return;

    if (!m_targets.HasDst())
        return;

    float speedXY, speedZ;
    CalculateJumpSpeeds(effectInfo, unitCaster->GetExactDist2d(destTarget), speedXY, speedZ);
    MovementFacingTarget facing;
    if (Unit const* target = m_targets.GetUnitTarget())
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR9_FACE_UNIT_TARGET_UPON_COMPLETION_OF_JUMP_CHARGE))
            facing = target;
    }
    else
        facing = destTarget->GetOrientation();

    JumpArrivalCastArgs arrivalCast;
    arrivalCast.SpellId = effectInfo->TriggerSpell;
    unitCaster->GetMotionMaster()->MoveJump(*destTarget, speedXY, speedZ, EVENT_JUMP, facing, m_spellInfo->HasAttribute(SPELL_ATTR9_JUMPCHARGE__NO_FACING_CONTROL), &arrivalCast);
}

TeleportToOptions GetTeleportOptions(WorldObject const* caster, Unit const* unitTarget, SpellDestination const& targetDest)
{
    TeleportToOptions options = TELE_TO_NONE;
    if (caster == unitTarget)
        options |= TELE_TO_SPELL;

    if (targetDest._position.GetMapId() == unitTarget->GetMapId())
    {
        options |= TELE_TO_NOT_LEAVE_COMBAT | TELE_TO_NOT_UNSUMMON_PET;

        if (unitTarget->GetTransGUID() == targetDest._transportGUID)
            options |= TELE_TO_NOT_LEAVE_TRANSPORT;
    }

    return options;
}

void Spell::EffectTeleportUnits()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->IsInFlight())
        return;

    // If not exist data for dest location - return
    if (!m_targets.HasDst())
    {
        TC_LOG_ERROR("spells", "Spell::EffectTeleportUnits - does not have a destination for spellId {}.", m_spellInfo->Id);
        return;
    }

    // Init dest coordinates
    WorldLocation targetDest(*destTarget);
    if (targetDest.GetMapId() == MAPID_INVALID)
        targetDest.m_mapId = unitTarget->GetMapId();

    if (!targetDest.GetOrientation() && m_targets.GetUnitTarget())
        targetDest.SetOrientation(m_targets.GetUnitTarget()->GetOrientation());

    Player* player = unitTarget->ToPlayer();

    // Custom loading screen
    if (player)
    {
        if (uint32 customLoadingScreenId = effectInfo->MiscValue)
            player->SendDirectMessage(WorldPackets::Spells::CustomLoadScreen(m_spellInfo->Id, customLoadingScreenId).Write());

        TeleportToOptions options = GetTeleportOptions(m_caster, unitTarget, m_destTargets[effectInfo->EffectIndex]);

        player->TeleportTo(targetDest, options);

    }
    else if (targetDest.GetMapId() == unitTarget->GetMapId())
        unitTarget->NearTeleportTo(targetDest, unitTarget == m_caster);
    else
        TC_LOG_ERROR("spells", "Spell::EffectTeleportUnits - spellId {} attempted to teleport creature to a different map.", m_spellInfo->Id);
}

class DelayedSpellTeleportEvent : public BasicEvent
{
public:
    explicit DelayedSpellTeleportEvent(Unit* target, WorldLocation const& targetDest, TeleportToOptions options, uint32 spellId)
        : _target(target), _targetDest(targetDest), _options(options), _spellId(spellId){ }

    bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) override
    {
        if (Player* player = _target->ToPlayer())
            player->TeleportTo(_targetDest, _options);
        else if (_targetDest.GetMapId() == _target->GetMapId())
            _target->NearTeleportTo(_targetDest, (_options & TELE_TO_SPELL) != TELE_TO_NONE);
        else
            TC_LOG_ERROR("spells", "Spell::EffectTeleportUnitsWithVisualLoadingScreen - spellId {} attempted to teleport creature to a different map.", _spellId);

        return true;
    }

private:
    Unit* _target;
    WorldLocation _targetDest;
    TeleportToOptions _options;
    uint32 _spellId;
};

void Spell::EffectTeleportUnitsWithVisualLoadingScreen()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    // If not exist data for dest location - return
    if (!m_targets.HasDst())
    {
        TC_LOG_ERROR("spells", "Spell::EffectTeleportUnitsWithVisualLoadingScreen - does not have a destination for spellId {}.", m_spellInfo->Id);
        return;
    }

    // Init dest coordinates
    WorldLocation targetDest(*destTarget);
    if (targetDest.GetMapId() == MAPID_INVALID)
        targetDest.m_mapId = unitTarget->GetMapId();

    if (!targetDest.GetOrientation() && m_targets.GetUnitTarget())
        targetDest.SetOrientation(m_targets.GetUnitTarget()->GetOrientation());

    if (effectInfo->MiscValueB)
        if (Player* playerTarget = unitTarget->ToPlayer())
            playerTarget->SendDirectMessage(WorldPackets::Spells::SpellVisualLoadScreen(effectInfo->MiscValueB, effectInfo->MiscValue).Write());

    TeleportToOptions options = GetTeleportOptions(m_caster, unitTarget, m_destTargets[effectInfo->EffectIndex]);
    unitTarget->m_Events.AddEventAtOffset(new DelayedSpellTeleportEvent(unitTarget, targetDest, options, m_spellInfo->Id),
        Milliseconds(effectInfo->MiscValue));
}

void Spell::EffectApplyAura()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!_spellAura || !unitTarget)
        return;

    // register target/effect on aura
    AuraApplication* aurApp = _spellAura->GetApplicationOfTarget(unitTarget->GetGUID());
    if (!aurApp)
        aurApp = unitTarget->_CreateAuraApplication(_spellAura, 1 << effectInfo->EffectIndex);
    else
        aurApp->UpdateApplyEffectMask(aurApp->GetEffectsToApply() | 1 << effectInfo->EffectIndex, false);
}

void Spell::EffectUnlearnSpecialization()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();
    uint32 spellToUnlearn = effectInfo->TriggerSpell;

    player->RemoveSpell(spellToUnlearn);

    TC_LOG_DEBUG("spells", "Spell: Player {} has unlearned spell {} from Npc {}", player->GetGUID().ToString(), spellToUnlearn, m_caster->GetGUID().ToString());
}

void Spell::EffectPowerDrain()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (effectInfo->MiscValue < 0 || effectInfo->MiscValue >= int8(MAX_POWERS))
        return;

    Powers powerType = Powers(effectInfo->MiscValue);
    if (!unitTarget || !unitTarget->IsAlive() || unitTarget->GetPowerType() != powerType || damage < 0)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    // add spell damage bonus
    if (unitCaster)
    {
        uint32 bonus = unitCaster->SpellDamageBonusDone(unitTarget, m_spellInfo, uint32(damage), SPELL_DIRECT_DAMAGE, *effectInfo, 1, this);
        damage = bonus + uint32(bonus * variance);
        damage = unitTarget->SpellDamageBonusTaken(unitCaster, m_spellInfo, uint32(damage), SPELL_DIRECT_DAMAGE);
    }

    int32 newDamage = -(unitTarget->ModifyPower(powerType, -damage));

    // Don't restore from self drain
    float gainMultiplier = 0.f;
    if (unitCaster && unitCaster != unitTarget)
    {
        gainMultiplier = effectInfo->CalcValueMultiplier(unitCaster, this);
        int32 const gain = int32(newDamage * gainMultiplier);

        unitCaster->EnergizeBySpell(unitCaster, m_spellInfo, gain, powerType);
    }
    ExecuteLogEffectTakeTargetPower(SpellEffectName(effectInfo->Effect), unitTarget, powerType, newDamage, gainMultiplier);
}

void Spell::EffectSendEvent()
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
        else if (m_corpseTarget)
            target = m_corpseTarget;
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

    TC_LOG_DEBUG("spells", "Spell ScriptStart {} for spellid {} in EffectSendEvent ", effectInfo->MiscValue, m_spellInfo->Id);

    GameEvents::Trigger(effectInfo->MiscValue, m_caster, target);
}

void Spell::EffectPowerBurn()
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
    float dmgMultiplier = effectInfo->CalcValueMultiplier(GetUnitCasterForEffectHandlers(), this);

    // add log data before multiplication (need power amount, not damage)
    ExecuteLogEffectTakeTargetPower(SpellEffectName(effectInfo->Effect), unitTarget, powerType, newDamage, 0.0f);

    newDamage = int32(newDamage * dmgMultiplier);

    m_damage += newDamage;
}

void Spell::EffectHeal()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive() || damage < 0)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();

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
    // Death Pact - return pct of max health to caster
    else if (m_spellInfo->SpellFamilyName == SPELLFAMILY_DEATHKNIGHT && m_spellInfo->SpellFamilyFlags[0] & 0x00080000)
        addhealth = unitCaster->SpellHealingBonusDone(unitTarget, m_spellInfo, int32(unitCaster->CountPctFromMaxHealth(damage)), HEAL, *effectInfo, 1, this);
    else
    {
        uint32 bonus = unitCaster->SpellHealingBonusDone(unitTarget, m_spellInfo, addhealth, HEAL, *effectInfo, 1, this);
        addhealth = bonus + uint32(bonus * variance);
    }

    addhealth = unitTarget->SpellHealingBonusTaken(unitCaster, m_spellInfo, addhealth, HEAL);

    // Remove Grievious bite if fully healed
    if (unitTarget->HasAura(48920) && (unitTarget->GetHealth() + addhealth >= unitTarget->GetMaxHealth()))
        unitTarget->RemoveAura(48920);

    m_healing += addhealth;
}

void Spell::EffectHealPct()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive() || damage < 0)
        return;

    uint32 heal = unitTarget->CountPctFromMaxHealth(damage);
    if (Unit* unitCaster = GetUnitCasterForEffectHandlers())
    {
        heal = unitCaster->SpellHealingBonusDone(unitTarget, m_spellInfo, heal, HEAL, *effectInfo, 1, this);
        heal = unitTarget->SpellHealingBonusTaken(unitCaster, m_spellInfo, heal, HEAL);
    }

    m_healing += heal;
}

void Spell::EffectHealMechanical()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive() || damage < 0)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    uint32 heal = damage;
    if (unitCaster)
        heal = unitCaster->SpellHealingBonusDone(unitTarget, m_spellInfo, heal, HEAL, *effectInfo, 1, this);

    heal += uint32(heal * variance);
    if (unitCaster)
        heal = unitTarget->SpellHealingBonusTaken(unitCaster, m_spellInfo, heal, HEAL);

    m_healing += heal;
}

void Spell::EffectHealthLeech()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive() || damage < 0)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    uint32 bonus = 0;
    if (unitCaster)
        bonus = unitCaster->SpellDamageBonusDone(unitTarget, m_spellInfo, uint32(damage), SPELL_DIRECT_DAMAGE, *effectInfo, 1, this);

    damage = bonus + uint32(bonus * variance);

    if (unitCaster)
        damage = unitTarget->SpellDamageBonusTaken(unitCaster, m_spellInfo, uint32(damage), SPELL_DIRECT_DAMAGE);

    TC_LOG_DEBUG("spells", "HealthLeech :{}", damage);

    float healMultiplier = effectInfo->CalcValueMultiplier(unitCaster, this);

    m_damage += damage;

    DamageInfo damageInfo(unitCaster, unitTarget, damage, m_spellInfo, m_spellInfo->GetSchoolMask(), SPELL_DIRECT_DAMAGE, BASE_ATTACK);
    Unit::CalcAbsorbResist(damageInfo);
    uint32 const absorb = damageInfo.GetAbsorb();
    damage -= absorb;

    // get max possible damage, don't count overkill for heal
    uint32 healthGain = uint32(-unitTarget->GetHealthGain(-damage) * healMultiplier);

    if (unitCaster && unitCaster->IsAlive())
    {
        healthGain = unitCaster->SpellHealingBonusDone(unitCaster, m_spellInfo, healthGain, HEAL, *effectInfo, 1, this);
        healthGain = unitCaster->SpellHealingBonusTaken(unitCaster, m_spellInfo, healthGain, HEAL);

        HealInfo healInfo(unitCaster, unitCaster, healthGain, m_spellInfo, m_spellSchoolMask);
        unitCaster->HealBySpell(healInfo);
    }
}

void Spell::DoCreateItem(uint32 itemId, ItemContext context /*= ItemContext::NONE*/, std::vector<int32> const* bonusListIDs /*= nullptr*/)
{
    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();

    uint32 newitemid = itemId;
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
    uint32 perfectItemType = itemId;
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
        if (Item* pItem = player->StoreNewItem(dest, newitemid, true, GenerateItemRandomBonusListId(newitemid), GuidSet(), context, bonusListIDs))
        {
            // set the "Crafted by ..." property of the item
            if (pItem->GetTemplate()->HasSignature())
                pItem->SetCreator(player->GetGUID());

            // send info to the client
            player->SendNewItem(pItem, num_to_add, true, true);

            if (pItem->GetQuality() > ITEM_QUALITY_EPIC || (pItem->GetQuality() == ITEM_QUALITY_EPIC && pItem->GetItemLevel(player) >= MinNewsItemLevel))
                if (Guild* guild = player->GetGuild())
                    guild->AddGuildNews(GUILD_NEWS_ITEM_CRAFTED, player->GetGUID(), 0, pProto->GetId());
        }

        // we succeeded in creating at least one item, so a levelup is possible
        if (!m_CastItem)
            player->UpdateCraftSkill(m_spellInfo);
    }
}

void Spell::EffectCreateItem()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    DoCreateItem(effectInfo->ItemType, m_spellInfo->HasAttribute(SPELL_ATTR0_IS_TRADESKILL) ? ItemContext::Trade_Skill : ItemContext::NONE);
    ExecuteLogEffectCreateItem(SpellEffectName(effectInfo->Effect), effectInfo->ItemType);
}

void Spell::EffectCreateItem2()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();

    ItemContext context = m_spellInfo->HasAttribute(SPELL_ATTR0_IS_TRADESKILL) ? ItemContext::Trade_Skill : ItemContext::NONE;

    // Pick a random item from spell_loot_template
    if (m_spellInfo->IsLootCrafting())
    {
        player->AutoStoreLoot(m_spellInfo->Id, LootTemplates_Spell, context, false, true);
        if (!m_CastItem)
            player->UpdateCraftSkill(m_spellInfo);
    }
    else // If there's no random loot entries for this spell, pick the item associated with this spell
    {
        uint32 item_id = effectInfo->ItemType;

        if (item_id)
            DoCreateItem(item_id, context);
    }

    /// @todo ExecuteLogEffectCreateItem(i, m_spellInfo->Effects[i].ItemType);
}

void Spell::EffectCreateRandomItem()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    Player* player = unitTarget->ToPlayer();

    // create some random items
    player->AutoStoreLoot(m_spellInfo->Id, LootTemplates_Spell, m_spellInfo->HasAttribute(SPELL_ATTR0_IS_TRADESKILL) ? ItemContext::Trade_Skill : ItemContext::NONE);
    /// @todo ExecuteLogEffectCreateItem(i, m_spellInfo->Effects[i].ItemType);
}

void Spell::EffectPersistentAA()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    // only handle at last effect
    for (size_t i = effectInfo->EffectIndex + 1; i < m_spellInfo->GetEffects().size(); ++i)
        if (m_spellInfo->GetEffect(SpellEffIndex(i)).IsEffect(SPELL_EFFECT_PERSISTENT_AREA_AURA))
            return;

    ASSERT(!_dynObjAura);

    float radius = effectInfo->CalcRadius(unitCaster);

    // Caster not in world, might be spell triggered from aura removal
    if (!unitCaster->IsInWorld())
        return;

    DynamicObject* dynObj = new DynamicObject(false);
    if (!dynObj->CreateDynamicObject(unitCaster->GetMap()->GenerateLowGuid<HighGuid::DynamicObject>(), unitCaster, m_spellInfo, *destTarget, radius, DYNAMIC_OBJECT_AREA_SPELL, m_SpellVisual))
    {
        delete dynObj;
        return;
    }

    AuraCreateInfo createInfo(m_castId, m_spellInfo, GetCastDifficulty(), MAX_EFFECT_MASK, dynObj);
    createInfo
        .SetCaster(unitCaster)
        .SetBaseAmount(m_spellValue->EffectBasePoints)
        .SetCastItem(m_castItemGUID, m_castItemEntry, m_castItemLevel);

    if (Aura* aura = Aura::TryCreate(createInfo))
    {
        _dynObjAura = aura->ToDynObjAura();
        _dynObjAura->_RegisterForTargets();
    }
    else
        return;

    ASSERT(_dynObjAura->GetDynobjOwner());
    _dynObjAura->_ApplyEffectForTargets(effectInfo->EffectIndex);
}

void Spell::EffectEnergize()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster || !unitTarget)
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
            damage -= 10 * std::max(0, std::min(30, unitCaster->GetLevel() - 60));
            break;
        case 24532:                                         // Burst of Energy
            // Instantly increases your energy by ${60-4*$max(0,$min(15,$PL-60))}.
            damage -= 4 * std::max(0, std::min(15, unitCaster->GetLevel() - 60));
            break;
        case 67490:                                         // Runic Mana Injector (mana gain increased by 25% for engineers - 3.2.0 patch change)
        {
            if (Player* player = unitCaster->ToPlayer())
                if (player->HasSkill(SKILL_ENGINEERING))
                    AddPct(damage, 25);
            break;
        }
        default:
            break;
    }

    unitCaster->EnergizeBySpell(unitTarget, m_spellInfo, damage, power);
}

void Spell::EffectEnergizePct()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster || !unitTarget)
        return;

    if (!unitTarget->IsAlive())
        return;

    if (effectInfo->MiscValue < 0 || effectInfo->MiscValue >= int8(MAX_POWERS))
        return;

    Powers power = Powers(effectInfo->MiscValue);
    uint32 maxPower = unitTarget->GetMaxPower(power);
    if (!maxPower)
        return;

    uint32 const gain = CalculatePct(maxPower, damage);
    unitCaster->EnergizeBySpell(unitTarget, m_spellInfo, gain, power);
}

void Spell::EffectOpenLock()
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

        if (goInfo->GetNoDamageImmune() && player->HasUnitFlag(UNIT_FLAG_IMMUNE))
            return;

        if (m_spellInfo->Id == 1842 && gameObjTarget->GetGOInfo()->type == GAMEOBJECT_TYPE_TRAP && gameObjTarget->GetOwner())
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

    SpellCastResult res = CanOpenLock(*effectInfo, lockId, skillId, reqSkillValue, skillValue);
    if (res != SPELL_CAST_OK)
    {
        SendCastResult(res);
        return;
    }

    if (gameObjTarget)
        gameObjTarget->Use(player);
    else if (itemTarget)
    {
        itemTarget->SetItemFlag(ITEM_FIELD_FLAG_UNLOCKED);
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
                if (!gameObjTarget->IsInSkillupList(player->GetGUID()))
                {
                    player->UpdateGatherSkill(skillId, pureSkillValue, reqSkillValue, 1, gameObjTarget);
                    gameObjTarget->AddToSkillupList(player->GetGUID());
                }
            }
            else if (itemTarget)
            {
                // Do one skill-up
                player->UpdateGatherSkill(skillId, pureSkillValue, reqSkillValue);
            }
        }
    }
    ExecuteLogEffectOpenLock(SpellEffectName(effectInfo->Effect), gameObjTarget ? (Object*)gameObjTarget : (Object*)itemTarget);
}

void Spell::EffectSummonChangeItem()
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

void Spell::EffectProficiency()
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

void Spell::EffectSummonType()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    uint32 entry = effectInfo->MiscValue;
    if (!entry)
        return;

    SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(effectInfo->MiscValueB);
    if (!properties)
    {
        TC_LOG_ERROR("spells", "EffectSummonType: Unhandled summon type {}.", effectInfo->MiscValueB);
        return;
    }

    WorldObject* caster = m_caster;
    if (m_originalCaster)
        caster = m_originalCaster;

    ObjectGuid privateObjectOwner = [&]()
    {
        if (!(properties->GetFlags().HasFlag(SummonPropertiesFlags::OnlyVisibleToSummoner | SummonPropertiesFlags::OnlyVisibleToSummonerGroup)))
            return ObjectGuid::Empty;

        if (caster->IsPrivateObject())
            return caster->GetPrivateObjectOwner();

        if (properties->GetFlags().HasFlag(SummonPropertiesFlags::OnlyVisibleToSummonerGroup))
            if (caster->IsPlayer() && m_originalCaster->ToPlayer()->GetGroup())
                return caster->ToPlayer()->GetGroup()->GetGUID();

        return caster->GetGUID();
    }();

    Milliseconds duration = Milliseconds(m_spellInfo->CalcDuration(caster));

    Unit* unitCaster = GetUnitCasterForEffectHandlers();

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
        {
            if (properties->GetFlags().HasFlag(SummonPropertiesFlags::JoinSummonerSpawnGroup))
            {
                SummonGuardian(effectInfo, entry, properties, numSummons, privateObjectOwner);
                break;
            }

            switch (SummonTitle(properties->Title))
            {
                case SummonTitle::Pet:
                case SummonTitle::Guardian:
                case SummonTitle::Runeblade:
                case SummonTitle::Minion:
                    SummonGuardian(effectInfo, entry, properties, numSummons, privateObjectOwner);
                    break;
                    // Summons a vehicle, but doesn't force anyone to enter it (see SUMMON_CATEGORY_VEHICLE)
                case SummonTitle::Vehicle:
                case SummonTitle::Mount:
                {
                    if (!unitCaster)
                        return;

                    summon = unitCaster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, unitCaster, m_spellInfo->Id);
                    break;
                }
                case SummonTitle::Lightwell:
                case SummonTitle::Totem:
                {
                    if (!unitCaster)
                        return;

                    summon = unitCaster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, unitCaster, m_spellInfo->Id, 0, privateObjectOwner);
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
                    if (!unitCaster)
                        return;

                    summon = unitCaster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, unitCaster, m_spellInfo->Id, 0, privateObjectOwner);
                    if (!summon || !summon->HasUnitTypeMask(UNIT_MASK_MINION))
                        return;

                    summon->SetImmuneToAll(true);
                    break;
                }
                default:
                {
                    float radius = effectInfo->CalcRadius();

                    TempSummonType summonType = TEMPSUMMON_TIMED_DESPAWN;
                    if (duration == 0ms)
                        summonType = TEMPSUMMON_DEAD_DESPAWN;
                    else if (duration == -1ms)
                        summonType = TEMPSUMMON_MANUAL_DESPAWN;
                    else if (properties->GetFlags().HasFlag(SummonPropertiesFlags::UseDemonTimeout))
                        summonType = TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT;

                    for (uint32 count = 0; count < numSummons; ++count)
                    {
                        Position pos;
                        if (count == 0)
                            pos = *destTarget;
                        else
                            // randomize position for multiple summons
                            pos = caster->GetRandomPoint(*destTarget, radius);

                        summon = caster->GetMap()->SummonCreature(entry, pos, properties, duration, unitCaster, m_spellInfo->Id, 0, privateObjectOwner);
                        if (!summon)
                            continue;

                        summon->SetTempSummonType(summonType);
                        if (properties->Control == SUMMON_CATEGORY_ALLY)
                            summon->SetOwnerGUID(caster->GetGUID());
                        else if (properties->Control == SUMMON_CATEGORY_WILD && caster->IsPlayer()) // there might be more conditions involved
                            summon->SetDemonCreatorGUID(caster->GetGUID());

                        ExecuteLogEffectSummonObject(SpellEffectName(effectInfo->Effect), summon);
                    }
                    return;
                }
            }
            break;
        }
        case SUMMON_CATEGORY_PET:
            SummonGuardian(effectInfo, entry, properties, numSummons, privateObjectOwner);
            break;
        case SUMMON_CATEGORY_PUPPET:
        {
            if (!unitCaster)
                return;

            summon = unitCaster->GetMap()->SummonCreature(entry, *destTarget, properties, duration, unitCaster, m_spellInfo->Id, 0, privateObjectOwner);
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
            int32 basePoints = effectInfo->CalcValue();
            if (basePoints > MAX_VEHICLE_SEATS)
            {
                SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(basePoints, GetCastDifficulty());
                if (spellInfo && spellInfo->HasAura(SPELL_AURA_CONTROL_VEHICLE))
                    spellId = spellInfo->Id;
            }

            CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
            args.SetTriggeringSpell(this);

            // if we have small value, it indicates seat position
            if (basePoints > 0 && basePoints < MAX_VEHICLE_SEATS)
                args.AddSpellMod(SPELLVALUE_BASE_POINT0, basePoints);

            unitCaster->CastSpell(summon, spellId, args);
            break;
        }
    }

    if (summon)
    {
        summon->SetCreatorGUID(caster->GetGUID());
        ExecuteLogEffectSummonObject(SpellEffectName(effectInfo->Effect), summon);
    }
}

void Spell::EffectLearnSpell()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
    {
        if (unitTarget->ToPet())
            EffectLearnPetSpell();
        return;
    }

    Player* player = unitTarget->ToPlayer();

    if (m_CastItem && !effectInfo->TriggerSpell)
    {
        for (ItemEffectEntry const* itemEffect : m_CastItem->GetEffects())
        {
            if (itemEffect->TriggerType != ITEM_SPELLTRIGGER_ON_LEARN)
                continue;

            bool dependent = false;

            if (BattlePetSpeciesEntry const* speciesEntry = BattlePets::BattlePetMgr::GetBattlePetSpeciesBySpell(uint32(itemEffect->SpellID)))
            {
                player->GetSession()->GetBattlePetMgr()->AddPet(speciesEntry->ID, BattlePets::BattlePetMgr::SelectPetDisplay(speciesEntry),
                    BattlePets::BattlePetMgr::RollPetBreed(speciesEntry->ID), BattlePets::BattlePetMgr::GetDefaultPetQuality(speciesEntry->ID));
                // If the spell summons a battle pet, we fake that it has been learned and the battle pet is added
                // marking as dependent prevents saving the spell to database (intended)
                dependent = true;
            }

            player->LearnSpell(itemEffect->SpellID, dependent);
        }
    }

    if (effectInfo->TriggerSpell)
    {
        player->LearnSpell(effectInfo->TriggerSpell, false);
        TC_LOG_DEBUG("spells", "Spell: Player {} has learned spell {} from Npc {}", player->GetGUID().ToString(), effectInfo->TriggerSpell, m_caster->GetGUID().ToString());
    }
}

void Spell::EffectDispel()
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
                if (dispelAura.GetAura()->GetId() == itr->GetAura()->GetId() && dispelAura.GetAura()->GetCaster() == itr->GetAura()->GetCaster())
                    return true;

                return false;
            });

            uint8 dispelledCharges = 1;
            if (itr->GetAura()->GetSpellInfo()->HasAttribute(SPELL_ATTR1_DISPEL_ALL_STACKS))
                dispelledCharges = itr->GetDispelCharges();

            if (successItr == successList.end())
                successList.emplace_back(itr->GetAura(), 0, dispelledCharges);
            else
                successItr->IncrementCharges();

            if (!itr->DecrementCharge(dispelledCharges))
            {
                --remaining;
                std::swap(*itr, dispelList[remaining]);
            }
        }
        else
        {
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

        unitTarget->RemoveAurasDueToSpellByDispel(dispelableAura.GetAura()->GetId(), m_spellInfo->Id, dispelableAura.GetAura()->GetCasterGUID(), m_caster, dispelableAura.GetDispelCharges());

        spellDispellLog.DispellData.emplace_back(dispellData);
    }

    m_caster->SendMessageToSet(spellDispellLog.Write(), true);

    CallScriptSuccessfulDispel(SpellEffIndex(effectInfo->EffectIndex));

    m_hitMask |= PROC_HIT_DISPEL;
}

void Spell::EffectDualWield()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    unitTarget->SetCanDualWield(true);
}

void Spell::EffectDistract()
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

void Spell::EffectPickPocket()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* player = m_caster->ToPlayer();
    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    Creature* creature = Object::ToCreature(unitTarget);
    if (!creature)
        return;

    if (creature->CanGeneratePickPocketLoot())
    {
        creature->StartPickPocketRefillTimer();

        creature->m_loot.reset(new Loot(creature->GetMap(), creature->GetGUID(), LOOT_PICKPOCKETING, nullptr));
        if (uint32 lootid = creature->GetCreatureDifficulty()->PickPocketLootID)
            creature->m_loot->FillLoot(lootid, LootTemplates_Pickpocketing, player, true);

        // Generate extra money for pick pocket loot
        const uint32 a = urand(0, creature->GetLevel() / 2);
        const uint32 b = urand(0, player->GetLevel() / 2);
        creature->m_loot->gold = uint32(10 * (a + b) * sWorld->getRate(RATE_DROP_MONEY));
    }
    else if (creature->m_loot)
    {
        if (creature->m_loot->loot_type == LOOT_PICKPOCKETING && creature->m_loot->isLooted())
            player->SendLootError(creature->m_loot->GetGUID(), creature->GetGUID(), LOOT_ERROR_ALREADY_PICKPOCKETED);

        return;
    }

    player->SendLoot(*creature->m_loot);
}

void Spell::EffectAddFarsight()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    float radius = effectInfo->CalcRadius();
    int32 duration = m_spellInfo->CalcDuration(m_caster);
    // Caster not in world, might be spell triggered from aura removal
    if (!player->IsInWorld())
        return;

    DynamicObject* dynObj = new DynamicObject(true);
    if (!dynObj->CreateDynamicObject(player->GetMap()->GenerateLowGuid<HighGuid::DynamicObject>(), player, m_spellInfo, *destTarget, radius, DYNAMIC_OBJECT_FARSIGHT_FOCUS, m_SpellVisual))
    {
        delete dynObj;
        return;
    }

    dynObj->SetDuration(duration);
    dynObj->SetCasterViewpoint();
}

void Spell::EffectUntrainTalents()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || m_caster->GetTypeId() == TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->SendRespecWipeConfirm(m_caster->GetGUID(), sWorld->getBoolConfig(CONFIG_NO_RESET_TALENT_COST) ? 0 : unitTarget->ToPlayer()->GetNextResetTalentsCost(), SPEC_RESET_TALENTS);
}

void Spell::EffectTeleUnitsFaceCaster()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (unitTarget->IsInFlight())
        return;

    if (m_targets.HasDst())
        unitTarget->NearTeleportTo(destTarget->GetPositionX(), destTarget->GetPositionY(), destTarget->GetPositionZ(), destTarget->GetAbsoluteAngle(m_caster), unitTarget == m_caster);
}

void Spell::EffectLearnSkill()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* playerTarget = Object::ToPlayer(unitTarget);
    if (!playerTarget)
        return;

    if (damage < 1)
        return;

    uint32 skillid = effectInfo->MiscValue;
    SkillRaceClassInfoEntry const* rcEntry = sDB2Manager.GetSkillRaceClassInfo(skillid, playerTarget->GetRace(), playerTarget->GetClass());
    if (!rcEntry)
        return;

    SkillTiersEntry const* tier = sObjectMgr->GetSkillTier(rcEntry->SkillTierID);
    if (!tier)
        return;

    uint16 skillval = std::max<uint16>(1, playerTarget->GetPureSkillValue(skillid));
    uint16 maxSkillVal = tier->GetValueForTierIndex(damage - 1);

    if (rcEntry->Flags & SKILL_FLAG_ALWAYS_MAX_VALUE)
        skillval = maxSkillVal;

    playerTarget->SetSkill(skillid, damage, skillval, maxSkillVal);
}

void Spell::EffectPlayMovie()
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

void Spell::EffectTradeSkill()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;
    // uint32 skillid =  m_spellInfo->Effects[i].MiscValue;
    // uint16 skillmax = unitTarget->ToPlayer()->(skillid);
    // m_caster->ToPlayer()->SetSkill(skillid, skillval?skillval:1, skillmax+75);
}

void Spell::EffectEnchantItemPerm()
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
        DoCreateItem(effectInfo->ItemType, m_spellInfo->HasAttribute(SPELL_ATTR0_IS_TRADESKILL) ? ItemContext::Trade_Skill : ItemContext::NONE);
        itemTarget = nullptr;
        m_targets.SetItemTarget(nullptr);
    }
    else
    {
        // do not increase skill if vellum used
        if (!m_CastItem)
            player->UpdateCraftSkill(m_spellInfo);

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
            sLog->OutCommand(player->GetSession()->GetAccountId(), "GM {} (Account: {}) enchanting(perm): {} (Entry: {}) for player: {} (Account: {})",
                player->GetName(), player->GetSession()->GetAccountId(),
                itemTarget->GetTemplate()->GetDefaultLocaleName(), itemTarget->GetEntry(),
                item_owner->GetName(), item_owner->GetSession()->GetAccountId());
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

void Spell::EffectEnchantItemPrismatic()
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
            TC_LOG_ERROR("spells", "Spell::EffectEnchantItemPrismatic: attempt to apply the enchant spell {} with SPELL_EFFECT_ENCHANT_ITEM_PRISMATIC ({}), but without ITEM_ENCHANTMENT_TYPE_PRISMATIC_SOCKET ({}), not supported yet.",
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
        sLog->OutCommand(player->GetSession()->GetAccountId(), "GM {} (Account: {}) enchanting(perm): {} (Entry: {}) for player: {} (Account: {})",
            player->GetName(), player->GetSession()->GetAccountId(),
            itemTarget->GetTemplate()->GetDefaultLocaleName(), itemTarget->GetEntry(),
            item_owner->GetName(), item_owner->GetSession()->GetAccountId());
    }

    // remove old enchanting before applying new if equipped
    item_owner->ApplyEnchantment(itemTarget, PRISMATIC_ENCHANTMENT_SLOT, false);

    itemTarget->SetEnchantment(PRISMATIC_ENCHANTMENT_SLOT, enchantId, 0, 0, m_caster->GetGUID());

    // add new enchanting if equipped
    item_owner->ApplyEnchantment(itemTarget, PRISMATIC_ENCHANTMENT_SLOT, true);

    item_owner->RemoveTradeableItem(itemTarget);
    itemTarget->ClearSoulboundTradeable(item_owner);
}

void Spell::EffectEnchantItemTmp()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!itemTarget)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    uint32 enchant_id = effectInfo->MiscValue;

    if (!enchant_id)
    {
        TC_LOG_ERROR("spells", "Spell {} Effect {} (SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY) has enchanting id 0.", m_spellInfo->Id, effectInfo->EffectIndex);
        return;
    }

    SpellItemEnchantmentEntry const* pEnchant = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
    if (!pEnchant)
    {
        TC_LOG_ERROR("spells", "Spell {} Effect {} (SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY) has a non-existing enchanting id {} ", m_spellInfo->Id, effectInfo->EffectIndex, enchant_id);
        return;
    }

    // select enchantment duration
    uint32 duration = pEnchant->Duration;

    // item can be in trade slot and have owner diff. from caster
    Player* item_owner = itemTarget->GetOwner();
    if (!item_owner)
        return;

    if (item_owner != player && player->GetSession()->HasPermission(rbac::RBAC_PERM_LOG_GM_TRADE))
    {
        sLog->OutCommand(player->GetSession()->GetAccountId(), "GM {} (Account: {}) enchanting(temp): {} (Entry: {}) for player: {} (Account: {})",
            player->GetName(), player->GetSession()->GetAccountId(),
            itemTarget->GetTemplate()->GetDefaultLocaleName(), itemTarget->GetEntry(),
            item_owner->GetName(), item_owner->GetSession()->GetAccountId());
    }

    // remove old enchanting before applying new if equipped
    item_owner->ApplyEnchantment(itemTarget, TEMP_ENCHANTMENT_SLOT, false);

    itemTarget->SetEnchantment(TEMP_ENCHANTMENT_SLOT, enchant_id, duration * 1000, 0, m_caster->GetGUID());

    // add new enchanting if equipped
    item_owner->ApplyEnchantment(itemTarget, TEMP_ENCHANTMENT_SLOT, true);
}

void Spell::EffectTameCreature()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster || !unitCaster->GetPetGUID().IsEmpty())
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

    uint8 level = (creatureTarget->GetLevelForTarget(m_caster) < (m_caster->GetLevelForTarget(creatureTarget) - 5)) ? (m_caster->GetLevelForTarget(creatureTarget) - 5) : creatureTarget->GetLevelForTarget(m_caster);

    // prepare visual effect for levelup
    pet->SetLevel(level - 1);

    // add to world
    pet->GetMap()->AddToMap(pet->ToCreature());

    // visual effect for levelup
    pet->SetLevel(level);

    // caster have pet now
    unitCaster->SetMinion(pet, true);

    if (unitCaster->GetTypeId() == TYPEID_PLAYER)
    {
        pet->SavePetToDB(PET_SAVE_AS_CURRENT);
        unitCaster->ToPlayer()->PetSpellInitialize();
    }
}

void Spell::EffectSummonPet()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Player* owner = nullptr;
    if (Unit* unitCaster = GetUnitCasterForEffectHandlers())
    {
        owner = unitCaster->ToPlayer();
        if (!owner && unitCaster->IsTotem())
            owner = unitCaster->GetCharmerOrOwnerPlayerOrPlayerItself();
    }

    uint32 petentry = effectInfo->MiscValue;

    if (!owner)
    {
        SummonPropertiesEntry const* properties = sSummonPropertiesStore.LookupEntry(67);
        if (properties)
            SummonGuardian(effectInfo, petentry, properties, 1, ObjectGuid::Empty);
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
            owner->ToPlayer()->RemovePet(OldSummon, PET_SAVE_NOT_IN_SLOT, false);
        else
            return;
    }

    Optional<PetSaveMode> petSlot;
    if (!petentry)
        petSlot = PetSaveMode(damage);

    float x, y, z;
    owner->GetClosePoint(x, y, z, owner->GetCombatReach());
    bool isNew = false;
    Pet* pet = owner->SummonPet(petentry, petSlot, x, y, z, owner->GetOrientation(), 0, &isNew);
    if (!pet)
        return;

    if (isNew)
    {
        if (m_caster->GetTypeId() == TYPEID_UNIT)
        {
            if (m_caster->ToCreature()->IsTotem())
                pet->SetReactState(REACT_AGGRESSIVE);
            else
                pet->SetReactState(REACT_DEFENSIVE);
        }

        pet->SetCreatedBySpell(m_spellInfo->Id);

        // generate new name for summon pet
        std::string new_name = sObjectMgr->GeneratePetName(petentry);
        if (!new_name.empty())
            pet->SetName(new_name);
    }

    ExecuteLogEffectSummonObject(SpellEffectName(effectInfo->Effect), pet);
}

void Spell::EffectLearnPetSpell()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (unitTarget->ToPlayer())
    {
        EffectLearnSpell();
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

void Spell::EffectTaunt()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
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

void Spell::EffectWeaponDmg()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    if (!unitTarget || !unitTarget->IsAlive())
        return;

    // multiple weapon dmg effect workaround
    // execute only the last weapon damage
    // and handle all effects at once
    for (size_t j = effectInfo->EffectIndex + 1; j < m_spellInfo->GetEffects().size(); ++j)
    {
        switch (m_spellInfo->GetEffect(SpellEffIndex(j)).Effect)
        {
            case SPELL_EFFECT_WEAPON_DAMAGE:
            case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
            case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
            case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                return;     // we must calculate only at last weapon effect
            default:
                break;
        }
    }

    // some spell specific modifiers
    float totalDamagePercentMod  = 1.0f;                    // applied to final bonus+weapon damage
    int32 fixed_bonus = 0;
    int32 spell_bonus = 0;                                  // bonus specific for spell

    switch (m_spellInfo->SpellFamilyName)
    {
        case SPELLFAMILY_SHAMAN:
        {
            // Skyshatter Harness item set bonus
            // Stormstrike
            if (AuraEffect* aurEff = unitCaster->IsScriptOverriden(m_spellInfo, 5634))
                unitCaster->CastSpell(nullptr, 38430, aurEff);
            break;
        }
    }

    bool normalized = false;
    float weaponDamagePercentMod = 1.0f;
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        switch (spellEffectInfo.Effect)
        {
            case SPELL_EFFECT_WEAPON_DAMAGE:
            case SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL:
                fixed_bonus += CalculateDamage(spellEffectInfo, unitTarget);
                break;
            case SPELL_EFFECT_NORMALIZED_WEAPON_DMG:
                fixed_bonus += CalculateDamage(spellEffectInfo, unitTarget);
                normalized = true;
                break;
            case SPELL_EFFECT_WEAPON_PERCENT_DAMAGE:
                ApplyPct(weaponDamagePercentMod, CalculateDamage(spellEffectInfo, unitTarget));
                break;
            default:
                break;                                      // not weapon damage effect, just skip
        }
    }

    // if (addPctMods) { percent mods are added in Unit::CalculateDamage } else { percent mods are added in Unit::MeleeDamageBonusDone }
    // this distinction is neccessary to properly inform the client about his autoattack damage values from Script_UnitDamage
    bool const addPctMods = !m_spellInfo->HasAttribute(SPELL_ATTR6_IGNORE_CASTER_DAMAGE_MODIFIERS) && (m_spellSchoolMask & SPELL_SCHOOL_MASK_NORMAL);
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
    Mechanics mechanic = MECHANIC_NONE;

    // Sequence is important
    for (SpellEffectInfo const& spellEffectInfo : m_spellInfo->GetEffects())
    {
        // We assume that a spell have at most one fixed_bonus
        // and at most one weaponDamagePercentMod
        switch (spellEffectInfo.Effect)
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
                continue;                                   // not weapon damage effect, just skip
        }

        if (spellEffectInfo.Mechanic != MECHANIC_NONE && mechanic == MECHANIC_NONE)
            mechanic = spellEffectInfo.Mechanic;
    }

    weaponDamage += spell_bonus;
    weaponDamage = int32(weaponDamage * totalDamagePercentMod);

    // prevent negative damage
    weaponDamage = std::max(weaponDamage, 0);

    // Add melee damage bonuses (also check for negative)
    weaponDamage = unitCaster->MeleeDamageBonusDone(unitTarget, weaponDamage, m_attackType, SPELL_DIRECT_DAMAGE, m_spellInfo, mechanic, m_spellSchoolMask, this);
    m_damage += unitTarget->MeleeDamageBonusTaken(unitCaster, weaponDamage, m_attackType, SPELL_DIRECT_DAMAGE, m_spellInfo);
}

void Spell::EffectThreat()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster || !unitCaster->IsAlive())
        return;

    if (!unitTarget)
        return;

    if (!unitTarget->CanHaveThreatList())
        return;

    unitTarget->GetThreatManager().AddThreat(unitCaster, float(damage), m_spellInfo, true);
}

void Spell::EffectHealMaxHealth()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
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

void Spell::EffectInterruptCast()
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
                && curSpellInfo->CanBeInterrupted(m_caster, unitTarget))
            {
                int32 duration = m_spellInfo->GetDuration();
                duration = unitTarget->ModSpellDuration(m_spellInfo, unitTarget, duration, false, 1 << effectInfo->EffectIndex);
                unitTarget->GetSpellHistory()->LockSpellSchool(curSpellInfo->GetSchoolMask(), Milliseconds(duration));
                m_hitMask |= PROC_HIT_INTERRUPT;
                SendSpellInterruptLog(unitTarget, curSpellInfo->Id);
                unitTarget->InterruptSpell(CurrentSpellTypes(i), false);
            }
        }
    }
}

void Spell::EffectSummonObjectWild()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    WorldObject* target = focusObject;
    if (!target)
        target = m_caster;

    float x, y, z, o;
    if (m_targets.HasDst())
        destTarget->GetPosition(x, y, z, o);
    else
    {
        m_caster->GetClosePoint(x, y, z, DEFAULT_PLAYER_BOUNDING_RADIUS);
        o = target->GetOrientation();
    }

    Map* map = target->GetMap();
    Position pos = Position(x, y, z, o);
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(o, 0.f, 0.f);
    GameObject* go = GameObject::CreateGameObject(effectInfo->MiscValue, map, pos, rot, 255, GO_STATE_READY);
    if (!go)
        return;

    PhasingHandler::InheritPhaseShift(go, m_caster);

    int32 duration = m_spellInfo->CalcDuration(m_caster);

    go->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
    go->SetSpellId(m_spellInfo->Id);

    ExecuteLogEffectSummonObject(SpellEffectName(effectInfo->Effect), go);

    // Wild object not have owner and check clickable by players
    map->AddToMap(go);

    if (GameObject* linkedTrap = go->GetLinkedTrap())
    {
        PhasingHandler::InheritPhaseShift(linkedTrap , m_caster);

        linkedTrap->SetRespawnTime(duration > 0 ? duration / IN_MILLISECONDS : 0);
        linkedTrap->SetSpellId(m_spellInfo->Id);

        ExecuteLogEffectSummonObject(SpellEffectName(effectInfo->Effect), linkedTrap);
    }
}

void Spell::EffectScriptEffect()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();

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
                    m_caster->CastSpell(unitTarget, 22682, this);
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
                        m_caster->CastSpell(m_caster, 42518, this);
                        return;
                    }
                    break;
                }
                // Brutallus - Burn
                case 45141:
                case 45151:
                {
                    //Workaround for Range ... should be global for every ScriptEffect
                    float radius = effectInfo->CalcRadius(nullptr, SpellTargetIndex::TargetB);
                    if (unitTarget && unitTarget->GetTypeId() == TYPEID_PLAYER && unitTarget->GetDistance(m_caster) >= radius && !unitTarget->HasAura(46394) && unitTarget != m_caster)
                        unitTarget->CastSpell(unitTarget, 46394, this);

                    break;
                }
                // Summon Ghouls On Scarlet Crusade
                case 51904:
                {
                    if (!m_targets.HasDst())
                        return;

                    float radius = effectInfo->CalcRadius();
                    for (uint8 i = 0; i < 15; ++i)
                        m_caster->CastSpell(m_caster->GetRandomPoint(*destTarget, radius), 54522, this);
                    break;
                }
                case 52173: // Coyote Spirit Despawn
                case 60243: // Blood Parrot Despawn
                    if (unitTarget->GetTypeId() == TYPEID_UNIT && unitTarget->IsSummon())
                        unitTarget->ToTempSummon()->UnSummon();
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
                                unitCaster->CastSpell(parent, 62496, this);
                                unitTarget->CastSpell(parent, damage, CastSpellExtraArgs()
                                    .SetTriggeringSpell(this)); // DIFFICULTY_NONE, so effect always valid
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
    TC_LOG_DEBUG("spells", "Spell ScriptStart spellid {} in EffectScriptEffect({})", m_spellInfo->Id, effectInfo->EffectIndex);
    m_caster->GetMap()->ScriptsStart(sSpellScripts, uint32(m_spellInfo->Id | (effectInfo->EffectIndex << 24)), m_caster, unitTarget);
}

void Spell::EffectSanctuary()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    auto isAffectedBySanctuary = [](Unit const* attacker)
    {
        Creature const* attackerCreature = attacker->ToCreature();
        return !attackerCreature || !attackerCreature->IsIgnoringSanctuarySpellEffect();
    };

    if (unitTarget->GetTypeId() == TYPEID_PLAYER && !unitTarget->GetMap()->IsDungeon())
    {
        // stop all pve combat for players outside dungeons, suppress pvp combat
        unitTarget->CombatStop(false, false, isAffectedBySanctuary);
    }
    else
    {
        // in dungeons (or for nonplayers), reset this unit on all enemies' threat lists
        for (auto const& [guid, ref] : unitTarget->GetThreatManager().GetThreatenedByMeList())
            if (isAffectedBySanctuary(ref->GetOwner()))
                ref->ScaleThreat(0.0f);
    }

    // makes spells cast before this time fizzle
    unitTarget->m_lastSanctuaryTime = GameTime::GetGameTimeMS();
}

void Spell::EffectDuel()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || m_caster->GetTypeId() != TYPEID_PLAYER || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* caster = m_caster->ToPlayer();
    Player* target = unitTarget->ToPlayer();

    // caster or target already have requested duel
    if (caster->duel || target->duel || !target->GetSocial() || target->GetSocial()->HasIgnore(caster->GetGUID(), caster->GetSession()->GetAccountGUID()))
        return;

    // Players can only fight a duel in zones with this flag
    AreaTableEntry const* casterAreaEntry = sAreaTableStore.LookupEntry(caster->GetAreaId());
    if (casterAreaEntry && !(casterAreaEntry->GetFlags().HasFlag(AreaFlags::AllowDueling)))
    {
        SendCastResult(SPELL_FAILED_NO_DUELING);            // Dueling isn't allowed here
        return;
    }

    AreaTableEntry const* targetAreaEntry = sAreaTableStore.LookupEntry(target->GetAreaId());
    if (targetAreaEntry && !(targetAreaEntry->GetFlags().HasFlag(AreaFlags::AllowDueling)))
    {
        SendCastResult(SPELL_FAILED_NO_DUELING);            // Dueling isn't allowed here
        return;
    }

    //CREATE DUEL FLAG OBJECT
    Map* map = caster->GetMap();
    Position const pos =
    {
        caster->GetPositionX() + (unitTarget->GetPositionX() - caster->GetPositionX()) / 2,
        caster->GetPositionY() + (unitTarget->GetPositionY() - caster->GetPositionY()) / 2,
        caster->GetPositionZ(),
        caster->GetOrientation()
    };
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(pos.GetOrientation(), 0.f, 0.f);

    GameObject* go = GameObject::CreateGameObject(effectInfo->MiscValue, map, pos, rot, 0, GO_STATE_READY);
    if (!go)
        return;

    PhasingHandler::InheritPhaseShift(go, caster);

    go->SetFaction(caster->GetFaction());
    go->SetLevel(caster->GetLevel() + 1);
    int32 duration = m_spellInfo->CalcDuration(caster);
    go->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);
    go->SetSpellId(m_spellInfo->Id);

    ExecuteLogEffectSummonObject(SpellEffectName(effectInfo->Effect), go);

    caster->AddGameObject(go);
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
    bool isMounted = (GetSpellInfo()->Id == 62875);
    caster->duel = std::make_unique<DuelInfo>(target, caster, isMounted);
    target->duel = std::make_unique<DuelInfo>(caster, caster, isMounted);

    caster->SetDuelArbiter(go->GetGUID());
    target->SetDuelArbiter(go->GetGUID());

    sScriptMgr->OnPlayerDuelRequest(target, caster);
}

void Spell::EffectStuck()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!sWorld->getBoolConfig(CONFIG_CAST_UNSTUCK))
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    TC_LOG_DEBUG("spells", "Spell Effect: Stuck");
    TC_LOG_DEBUG("spells", "Player {} {} used the auto-unstuck feature at map {} ({}, {}, {}).", player->GetName(), player->GetGUID().ToString(), player->GetMapId(), player->GetPositionX(), player->GetPositionY(), player->GetPositionZ());

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
        player->KillSelf();
        return;
    }

    player->TeleportTo(player->m_homebind, TELE_TO_SPELL);

    // Stuck spell trigger Hearthstone cooldown
    SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(8690, GetCastDifficulty());
    if (!spellInfo)
        return;
    Spell spell(player, spellInfo, TRIGGERED_FULL_MASK);
    spell.SendSpellCooldown();
}

void Spell::EffectSummonPlayer()
{
    // workaround - this effect should not use target map
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->SendSummonRequestFrom(unitCaster);
}

void Spell::EffectActivateObject()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!gameObjTarget)
        return;

    GameObjectActions action = GameObjectActions(effectInfo->MiscValue);

    gameObjTarget->ActivateObject(action, effectInfo->MiscValueB, m_caster, m_spellInfo->Id, int32(effectInfo->EffectIndex));
}

void Spell::EffectApplyGlyph()
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

    player->RemoveAurasWithInterruptFlags(SpellAuraInterruptFlags2::ChangeGlyph);

    if (GlyphPropertiesEntry const* glyphProperties = sGlyphPropertiesStore.LookupEntry(glyphId))
        player->CastSpell(player, glyphProperties->SpellID, this);

    WorldPackets::Talent::ActiveGlyphs activeGlyphs;
    activeGlyphs.Glyphs.emplace_back(m_misc.SpellId, uint16(glyphId));
    activeGlyphs.IsFullUpdate = false;
    player->SendDirectMessage(activeGlyphs.Write());
}

void Spell::EffectEnchantHeldItem()
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

void Spell::EffectDisEnchant()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (Player* caster = m_caster->ToPlayer())
    {
        if (!m_CastItem)
            caster->UpdateCraftSkill(m_spellInfo);

        itemTarget->m_loot.reset(new Loot(caster->GetMap(), itemTarget->GetGUID(), LOOT_DISENCHANTING, nullptr));
        itemTarget->m_loot->FillLoot(*itemTarget->GetDisenchantLootId(), LootTemplates_Disenchant, caster, true);
        caster->SendLoot(*itemTarget->m_loot);
    }

    // item will be removed at disenchanting end
}

void Spell::EffectInebriate()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsPlayer())
        return;

    Player* player = unitTarget->ToPlayer();

    uint8 currentDrunkValue = player->GetDrunkValue();
    uint8 drunkValue = std::clamp<int32>(damage + currentDrunkValue, 0, 100);
    if (currentDrunkValue == 100 && currentDrunkValue == drunkValue)
        if (roll_chance_f(25.0f))
            player->CastSpell(player, 67468, CastSpellExtraArgs()
                .SetTriggeringSpell(this));    // Drunken Vomit

    player->SetDrunkValue(drunkValue, m_CastItem ? m_CastItem->GetEntry() : 0);
}

void Spell::EffectFeedPet()
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

    ExecuteLogEffectDestroyItem(SpellEffectName(effectInfo->Effect), foodItem->GetEntry());

    int32 pct;
    int32 levelDiff = int32(pet->GetLevel()) - int32(foodItem->GetTemplate()->GetBaseItemLevel());
    if (levelDiff >= 30)
        return;
    else if (levelDiff >= 20)
        pct = int32(12.5); // we can't pass double so keeping the cast here for future references
    else if (levelDiff >= 10)
        pct = 25;
    else
        pct = 50;

    uint32 count = 1;
    player->DestroyItemCount(foodItem, count, true);
    /// @todo fix crash when a spell has two effects, both pointed at the same item target

    CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
    args.SetTriggeringSpell(this);
    args.AddSpellMod(SPELLVALUE_BASE_POINT0, pct);
    m_caster->CastSpell(pet, effectInfo->TriggerSpell, args);
}

void Spell::EffectDismissPet()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsPet())
        return;

    Pet* pet = unitTarget->ToPet();

    ExecuteLogEffectUnsummonObject(SpellEffectName(effectInfo->Effect), pet);
    pet->Remove(PET_SAVE_NOT_IN_SLOT);
}

void Spell::EffectSummonObject()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    uint8 slot = effectInfo->Effect - SPELL_EFFECT_SUMMON_OBJECT_SLOT1;
    ObjectGuid guid = unitCaster->m_ObjectSlot[slot];
    if (!guid.IsEmpty())
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

    float x, y, z, o;
    // If dest location if present
    if (m_targets.HasDst())
        destTarget->GetPosition(x, y, z, o);
    // Summon in random point all other units if location present
    else
    {
        unitCaster->GetClosePoint(x, y, z, DEFAULT_PLAYER_BOUNDING_RADIUS);
        o = unitCaster->GetOrientation();
    }

    Map* map = m_caster->GetMap();
    Position pos = Position(x, y, z, o);
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(o, 0.f, 0.f);

    GameObject* go = GameObject::CreateGameObject(effectInfo->MiscValue, map, pos, rot, 255, GO_STATE_READY);
    if (!go)
        return;

    PhasingHandler::InheritPhaseShift(go, m_caster);

    go->SetFaction(unitCaster->GetFaction());
    go->SetLevel(unitCaster->GetLevel());
    int32 duration = m_spellInfo->CalcDuration(m_caster);
    go->SetRespawnTime(duration > 0 ? duration / IN_MILLISECONDS : 0);
    go->SetSpellId(m_spellInfo->Id);
    unitCaster->AddGameObject(go);

    ExecuteLogEffectSummonObject(SpellEffectName(effectInfo->Effect), go);

    map->AddToMap(go);

    unitCaster->m_ObjectSlot[slot] = go->GetGUID();
}

void Spell::EffectResurrect()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!m_corpseTarget && !unitTarget)
        return;

    Player* player = nullptr;

    if (m_corpseTarget)
        player = ObjectAccessor::FindPlayer(m_corpseTarget->GetOwnerGUID());
    else if (unitTarget)
        player = unitTarget->ToPlayer();

    if (!player || player->IsAlive() || !player->IsInWorld())
        return;

    if (player->IsResurrectRequested())       // already have one active request
        return;

    uint32 health = player->CountPctFromMaxHealth(damage);
    uint32 mana   = CalculatePct(player->GetMaxPower(POWER_MANA), damage);

    ExecuteLogEffectResurrect(SpellEffectName(effectInfo->Effect), player);

    player->SetResurrectRequestData(m_caster, health, mana, 0);
    SendResurrectRequest(player);
}

void Spell::EffectAddExtraAttacks()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsAlive())
        return;

    unitTarget->AddExtraAttacks(damage);

    ExecuteLogEffectExtraAttacks(SpellEffectName(effectInfo->Effect), unitTarget, damage);
}

void Spell::EffectParry()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetCanParry(true);
}

void Spell::EffectBlock()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetCanBlock(true);
}

void Spell::EffectLeap()
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

void Spell::EffectReputation()
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

void Spell::EffectQuestComplete()
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

        QuestStatus questStatus = player->GetQuestStatus(questId);
        if (questStatus == QUEST_STATUS_REWARDED)
            return;

        if (quest->HasFlag(QUEST_FLAGS_COMPLETION_EVENT) || quest->HasFlag(QUEST_FLAGS_COMPLETION_AREA_TRIGGER))
        {
            if (questStatus == QUEST_STATUS_INCOMPLETE)
                player->AreaExploredOrEventHappens(questId);
        }
        else if (quest->HasFlag(QUEST_FLAGS_TRACKING_EVENT)) // Check if the quest is used as a serverside flag
            player->CompleteQuest(questId);
    }
}

void Spell::EffectForceDeselect()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    float dist = unitCaster->GetVisibilityRange();

    // clear focus
    Trinity::PacketSenderOwning<WorldPackets::Combat::BreakTarget> breakTarget;
    breakTarget.Data.UnitGUID = m_caster->GetGUID();
    breakTarget.Data.Write();
    Trinity::MessageDistDelivererToHostile<Trinity::PacketSenderOwning<WorldPackets::Combat::BreakTarget>> notifierBreak(unitCaster, breakTarget, dist);
    Cell::VisitWorldObjects(m_caster, notifierBreak, dist);

    // and selection
    Trinity::PacketSenderOwning<WorldPackets::Spells::ClearTarget> clearTarget;
    clearTarget.Data.Guid = m_caster->GetGUID();
    clearTarget.Data.Write();
    Trinity::MessageDistDelivererToHostile<Trinity::PacketSenderOwning<WorldPackets::Spells::ClearTarget>> notifierClear(unitCaster, clearTarget, dist);
    Cell::VisitWorldObjects(m_caster, notifierClear, dist);

    // we should also force pets to remove us from current target
    Unit::AttackerSet attackerSet;
    for (Unit::AttackerSet::const_iterator itr = unitCaster->getAttackers().begin(); itr != unitCaster->getAttackers().end(); ++itr)
        if ((*itr)->GetTypeId() == TYPEID_UNIT && !(*itr)->CanHaveThreatList())
            attackerSet.insert(*itr);

    for (Unit::AttackerSet::const_iterator itr = attackerSet.begin(); itr != attackerSet.end(); ++itr)
        (*itr)->AttackStop();
}

void Spell::EffectSelfResurrect()
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
        mana = effectInfo->MiscValue;
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
    player->SetFullPower(POWER_ENERGY);
    player->SetPower(POWER_FOCUS, 0);

    player->SpawnCorpseBones();
}

void Spell::EffectSkinning()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (unitTarget->GetTypeId() != TYPEID_UNIT)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    Creature* creature = unitTarget->ToCreature();
    int32 targetLevel = creature->GetLevelForTarget(m_caster);

    uint32 skill = creature->GetCreatureDifficulty()->GetRequiredLootSkill();

    creature->SetUnitFlag3(UNIT_FLAG3_ALREADY_SKINNED);
    creature->SetDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
    Loot* loot = new Loot(creature->GetMap(), creature->GetGUID(), LOOT_SKINNING, nullptr);
    creature->m_personalLoot[player->GetGUID()].reset(loot);
    loot->FillLoot(creature->GetCreatureDifficulty()->SkinLootID, LootTemplates_Skinning, player, true);
    player->SendLoot(*loot);

    if (!IsPartOfSkillLine(skill, m_spellInfo->Id))
        return;

    // Skill gain for skinning
    // This formula is still used (10.0.5.48526)
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

        ContentTuningEntry const* contentTuning = sContentTuningStore.LookupEntry(creature->GetContentTuning());
        if (!contentTuning)
            return;

        uint32 skinningSkill = player->GetProfessionSkillForExp(skill, contentTuning->ExpansionID);
        if (!skinningSkill)
            return;

        if (uint32 pureSkillValue = player->GetPureSkillValue(skinningSkill))
        {
            // Double chances for elites
            player->UpdateGatherSkill(skinningSkill, pureSkillValue, reqValue, creature->IsElite() ? 2 : 1);
        }
    }
}

void Spell::EffectCharge()
{
    if (!unitTarget)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    if (effectHandleMode == SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
    {
        // charge changes fall time
        if (unitCaster->GetTypeId() == TYPEID_PLAYER)
            unitCaster->ToPlayer()->SetFallInformation(0, unitCaster->GetPositionZ());

        float speed = G3D::fuzzyGt(m_spellInfo->Speed, 0.0f) ? m_spellInfo->Speed : SPEED_CHARGE;

        Optional<Movement::SpellEffectExtraData> spellEffectExtraData;
        if (effectInfo->MiscValueB)
        {
            spellEffectExtraData.emplace();
            spellEffectExtraData->Target = unitTarget->GetGUID();
            spellEffectExtraData->SpellVisualId = effectInfo->MiscValueB;
        }
        // Spell is not using explicit target - no generated path
        if (!m_preGeneratedPath)
        {
            Position pos = unitTarget->GetFirstCollisionPosition(unitTarget->GetCombatReach(), unitTarget->GetRelativeAngle(m_caster));

            m_preGeneratedPath = std::make_unique<PathGenerator>(unitCaster);
            m_preGeneratedPath->CalculatePath(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), false);
        }

        if (G3D::fuzzyGt(m_spellInfo->Speed, 0.0f) && m_spellInfo->HasAttribute(SPELL_ATTR9_MISSILE_SPEED_IS_DELAY_IN_SEC))
            speed = m_preGeneratedPath->GetPathLength() / speed;

        unitCaster->GetMotionMaster()->MoveCharge(*m_preGeneratedPath, speed, unitTarget, spellEffectExtraData ? &*spellEffectExtraData : nullptr);

        // abuse implementation detail of MoveCharge accepting PathGenerator argument (instantly started spline)
        UpdateDelayMomentForUnitTarget(unitTarget, unitCaster->movespline->Duration());
    }

    if (effectHandleMode == SPELL_EFFECT_HANDLE_HIT_TARGET)
    {
        // not all charge effects used in negative spells
        if (m_spellInfo->HasAttribute(SPELL_ATTR7_ATTACK_ON_CHARGE_TO_UNIT))
            unitCaster->Attack(unitTarget, true);

        if (effectInfo->TriggerSpell)
            m_caster->CastSpell(unitTarget, effectInfo->TriggerSpell, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                .SetOriginalCaster(m_originalCasterGUID)
                .SetTriggeringSpell(this));
    }
}

void Spell::EffectChargeDest()
{
    if (!destTarget)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    if (effectHandleMode == SPELL_EFFECT_HANDLE_LAUNCH)
    {
        Position pos = destTarget->GetPosition();

        if (!unitCaster->IsWithinLOS(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ()))
        {
            float angle = unitCaster->GetRelativeAngle(pos.GetPositionX(), pos.GetPositionY());
            float dist = unitCaster->GetDistance(pos);
            pos = unitCaster->GetFirstCollisionPosition(dist, angle);
        }

        PathGenerator path(unitCaster);
        path.CalculatePath(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), false);

        float speed = G3D::fuzzyGt(m_spellInfo->Speed, 0.0f) ? m_spellInfo->Speed : SPEED_CHARGE;

        if (G3D::fuzzyGt(m_spellInfo->Speed, 0.0f) && m_spellInfo->HasAttribute(SPELL_ATTR9_MISSILE_SPEED_IS_DELAY_IN_SEC))
            speed = path.GetPathLength() / speed;

        unitCaster->GetMotionMaster()->MoveCharge(path, speed);

        // abuse implementation detail of MoveCharge accepting PathGenerator argument (instantly started spline)
        UpdateDelayMomentForDst(unitCaster->movespline->Duration());
    }
    else if (effectHandleMode == SPELL_EFFECT_HANDLE_HIT)
    {
        if (effectInfo->TriggerSpell)
            m_caster->CastSpell(*destTarget, effectInfo->TriggerSpell, CastSpellExtraArgs(TRIGGERED_FULL_MASK)
                .SetOriginalCaster(m_originalCasterGUID)
                .SetTriggeringSpell(this));
    }
}

void Spell::EffectKnockBack()
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

    float ratio = 0.1f;
    float speedxy = float(effectInfo->MiscValue) * ratio;
    float speedz = float(damage) * ratio;
    if (speedxy < 0.01f && speedz < 0.01f)
        return;

    Position origin;
    if (effectInfo->Effect == SPELL_EFFECT_KNOCK_BACK_DEST)
    {
        if (m_targets.HasDst())
            origin = destTarget->GetPosition();
        else
            return;
    }
    else //if (effectInfo->Effect == SPELL_EFFECT_KNOCK_BACK)
        origin = m_caster->GetPosition();

    unitTarget->KnockbackFrom(origin, speedxy, speedz);

    Unit::ProcSkillsAndAuras(GetUnitCasterForEffectHandlers(), unitTarget, PROC_FLAG_NONE, { PROC_FLAG_NONE, PROC_FLAG_2_KNOCKBACK },
        PROC_SPELL_TYPE_MASK_ALL, PROC_SPELL_PHASE_HIT, PROC_HIT_NONE, nullptr, nullptr, nullptr);
}

void Spell::EffectLeapBack()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (!unitTarget)
        return;

    float speedxy = effectInfo->MiscValue / 10.f;
    float speedz = damage / 10.f;
    // Disengage
    unitTarget->JumpTo(speedxy, speedz, effectInfo->PositionFacing);

    // changes fall time
    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetFallInformation(0, m_caster->GetPositionZ());
}

void Spell::EffectQuestClear()
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
    player->DespawnPersonalSummonsForQuest(quest_id);

    sScriptMgr->OnQuestStatusChange(player, quest_id);
    sScriptMgr->OnQuestStatusChange(player, quest, oldStatus, QUEST_STATUS_NONE);
}

void Spell::EffectSendTaxi()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->ActivateTaxiPathTo(effectInfo->MiscValue, m_spellInfo->Id);
}

void Spell::EffectPullTowards()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    Position pos = m_caster->GetFirstCollisionPosition(m_caster->GetCombatReach(), m_caster->GetRelativeAngle(unitTarget));

    // This is a blizzlike mistake: this should be 2D distance according to projectile motion formulas, but Blizzard erroneously used 3D distance.
    float distXY = unitTarget->GetExactDist(pos);

    // Avoid division by 0
    if (distXY < 0.001)
        return;

    float distZ = pos.GetPositionZ() - unitTarget->GetPositionZ();
    float speedXY = effectInfo->MiscValue ? effectInfo->MiscValue / 10.0f : 30.0f;
    float speedZ = (2 * speedXY * speedXY * distZ + Movement::gravity * distXY * distXY) / (2 * speedXY * distXY);

    if (!std::isfinite(speedZ))
    {
        TC_LOG_ERROR("spells", "Spell {} with SPELL_EFFECT_PULL_TOWARDS called with invalid speedZ. {}", m_spellInfo->Id, GetDebugInfo());
        return;
    }

    unitTarget->JumpTo(speedXY, speedZ, 0.0f, pos);
}

void Spell::EffectPullTowardsDest()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    if (!m_targets.HasDst())
    {
        TC_LOG_ERROR("spells", "Spell {} with SPELL_EFFECT_PULL_TOWARDS_DEST has no dest target", m_spellInfo->Id);
        return;
    }

    Position const* pos = m_targets.GetDstPos();
    // This is a blizzlike mistake: this should be 2D distance according to projectile motion formulas, but Blizzard erroneously used 3D distance
    float distXY = unitTarget->GetExactDist(pos);

    // Avoid division by 0
    if (distXY < 0.001)
        return;

    float distZ = pos->GetPositionZ() - unitTarget->GetPositionZ();

    float speedXY = effectInfo->MiscValue ? effectInfo->MiscValue / 10.0f : 30.0f;
    float speedZ = (2 * speedXY * speedXY * distZ + Movement::gravity * distXY * distXY) / (2 * speedXY * distXY);

    if (!std::isfinite(speedZ))
    {
        TC_LOG_ERROR("spells", "Spell {} with SPELL_EFFECT_PULL_TOWARDS_DEST called with invalid speedZ. {}", m_spellInfo->Id, GetDebugInfo());
        return;
    }

    unitTarget->JumpTo(speedXY, speedZ, 0.0f, *pos);
}

void Spell::EffectChangeRaidMarker()
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

void Spell::EffectDispelMechanic()
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
            if ((aura->GetSpellInfo()->GetAllEffectsMechanicMask() & (UI64LIT(1) << mechanic)))
                dispel_list.emplace_back(aura->GetId(), aura->GetCasterGUID());
    }

    if (dispel_list.empty())
        return;

    for (auto itr = dispel_list.begin(); itr != dispel_list.end(); ++itr)
        unitTarget->RemoveAura(itr->first, itr->second, 0, AURA_REMOVE_BY_ENEMY_SPELL);

    m_hitMask |= PROC_HIT_DISPEL;
}

void Spell::EffectResurrectPet()
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
        PetStable const* petStable = player->GetPetStable();
        auto deadPetItr = std::find_if(petStable->ActivePets.begin(), petStable->ActivePets.end(), [](Optional<PetStable::PetInfo> const& petInfo)
        {
            return petInfo && !petInfo->Health;
        });

        PetSaveMode slot = PetSaveMode(std::distance(petStable->ActivePets.begin(), deadPetItr));

        // Position passed to SummonPet is irrelevant with current implementation,
        // pet will be relocated without using these coords in Pet::LoadPetFromDB
        player->SummonPet(0, slot, 0.0f, 0.0f, 0.0f, 0.0f, 0);
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

    pet->ReplaceAllDynamicFlags(UNIT_DYNFLAG_NONE);
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

void Spell::EffectDestroyAllTotems()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    int32 mana = 0;
    for (uint8 slot = SUMMON_SLOT_TOTEM; slot < MAX_TOTEM_SLOT; ++slot)
    {
        if (!unitCaster->m_SummonSlot[slot])
            continue;

        Creature* totem = unitCaster->GetMap()->GetCreature(unitCaster->m_SummonSlot[slot]);
        if (totem && totem->IsTotem())
        {
            uint32 spell_id = totem->m_unitData->CreatedBySpell;
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id, GetCastDifficulty());
            if (spellInfo)
            {
                std::vector<SpellPowerCost> costs = spellInfo->CalcPowerCost(unitCaster, spellInfo->GetSchoolMask());
                auto m = std::find_if(costs.begin(), costs.end(), [](SpellPowerCost const& cost) { return cost.Power == POWER_MANA; });
                if (m != costs.end())
                    mana += m->Amount;
            }

            totem->ToTotem()->UnSummon();
        }
    }

    ApplyPct(mana, damage);

    if (mana)
    {
        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
        args.SetTriggeringSpell(this);
        args.AddSpellMod(SPELLVALUE_BASE_POINT0, mana);
        unitCaster->CastSpell(unitCaster, 39104, args);
    }
}

void Spell::EffectDurabilityDamage()
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
        ExecuteLogEffectDurabilityDamage(SpellEffectName(effectInfo->Effect), unitTarget, -1, -1);
        return;
    }

    // invalid slot value
    if (slot >= INVENTORY_SLOT_BAG_END)
        return;

    if (Item* item = unitTarget->ToPlayer()->GetItemByPos(INVENTORY_SLOT_BAG_0, slot))
    {
        unitTarget->ToPlayer()->DurabilityPointsLoss(item, damage);
        ExecuteLogEffectDurabilityDamage(SpellEffectName(effectInfo->Effect), unitTarget, item->GetEntry(), slot);
    }
}

void Spell::EffectDurabilityDamagePCT()
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

void Spell::EffectModifyThreatPercent()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster || !unitTarget)
        return;

    unitTarget->GetThreatManager().ModifyThreatByPercent(unitCaster, damage);
}

void Spell::EffectTransmitted()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    uint32 name_id = effectInfo->MiscValue;
    Unit::AuraEffectList const& overrideSummonedGameObjects = unitCaster->GetAuraEffectsByType(SPELL_AURA_OVERRIDE_SUMMONED_OBJECT);
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
        TC_LOG_ERROR("sql.sql", "Gameobject (Entry: {}) does not exist and is not created by spell (ID: {}) cast.", name_id, m_spellInfo->Id);
        return;
    }

    float fx, fy, fz, fo;

    if (m_targets.HasDst())
        destTarget->GetPosition(fx, fy, fz, fo);
    //FIXME: this can be better check for most objects but still hack
    else if (effectInfo->HasRadius(SpellTargetIndex::TargetA) && m_spellInfo->Speed == 0)
    {
        float dis = effectInfo->CalcRadius(unitCaster);
        unitCaster->GetClosePoint(fx, fy, fz, DEFAULT_PLAYER_BOUNDING_RADIUS, dis);
        fo = unitCaster->GetOrientation();
    }
    else
    {
        //GO is always friendly to it's creator, get range for friends
        float min_dis = m_spellInfo->GetMinRange(true);
        float max_dis = m_spellInfo->GetMaxRange(true);
        float dis = rand_norm() * (max_dis - min_dis) + min_dis;

        unitCaster->GetClosePoint(fx, fy, fz, DEFAULT_PLAYER_BOUNDING_RADIUS, dis);
        fo = unitCaster->GetOrientation();
    }

    Map* cMap = unitCaster->GetMap();
    // if gameobject is summoning object, it should be spawned right on caster's position
    if (goinfo->type == GAMEOBJECT_TYPE_RITUAL)
        unitCaster->GetPosition(fx, fy, fz, fo);

    Position pos = { fx, fy, fz, fo };
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(fo, 0.f, 0.f);

    GameObject* go = GameObject::CreateGameObject(name_id, cMap, pos, rot, 255, GO_STATE_READY);
    if (!go)
        return;

    PhasingHandler::InheritPhaseShift(go, m_caster);
    int32 duration = m_spellInfo->CalcDuration(m_caster);

    switch (goinfo->type)
    {
        case GAMEOBJECT_TYPE_FISHINGNODE:
        {
            go->SetFaction(unitCaster->GetFaction());
            ObjectGuid bobberGuid = go->GetGUID();
            // client requires fishing bobber guid in channel object slot 0 to be usable
            unitCaster->SetChannelObject(0, bobberGuid);
            unitCaster->AddGameObject(go);              // will removed at spell cancel

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
        case GAMEOBJECT_TYPE_RITUAL:
        {
            if (unitCaster->GetTypeId() == TYPEID_PLAYER)
            {
                go->AddUniqueUse(unitCaster->ToPlayer());
                unitCaster->AddGameObject(go);      // will be removed at spell cancel
            }
            break;
        }
        case GAMEOBJECT_TYPE_DUEL_ARBITER: // 52991
            unitCaster->AddGameObject(go);
            break;
        case GAMEOBJECT_TYPE_FISHINGHOLE:
        case GAMEOBJECT_TYPE_CHEST:
        default:
            break;
    }

    go->SetRespawnTime(duration > 0 ? duration/IN_MILLISECONDS : 0);

    go->SetOwnerGUID(unitCaster->GetGUID());

    //go->SetLevel(unitCaster->getLevel());
    go->SetSpellId(m_spellInfo->Id);

    ExecuteLogEffectSummonObject(SpellEffectName(effectInfo->Effect), go);

    TC_LOG_DEBUG("spells", "AddObject at SpellEfects.cpp EffectTransmitted");
    //unitCaster->AddGameObject(go);
    //m_ObjToDel.push_back(go);

    cMap->AddToMap(go);

    if (GameObject* linkedTrap = go->GetLinkedTrap())
    {
        PhasingHandler::InheritPhaseShift(linkedTrap, m_caster);

        linkedTrap->SetRespawnTime(duration > 0 ? duration / IN_MILLISECONDS : 0);
        //linkedTrap->SetLevel(unitCaster->getLevel());
        linkedTrap->SetSpellId(m_spellInfo->Id);
        linkedTrap->SetOwnerGUID(unitCaster->GetGUID());

        ExecuteLogEffectSummonObject(SpellEffectName(effectInfo->Effect), linkedTrap);
    }
}

void Spell::EffectProspecting()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    if (!itemTarget || !itemTarget->GetTemplate()->HasFlag(ITEM_FLAG_IS_PROSPECTABLE))
        return;

    if (itemTarget->GetCount() < 5)
        return;

    if (sWorld->getBoolConfig(CONFIG_SKILL_PROSPECTING))
    {
        uint32 SkillValue = player->GetPureSkillValue(SKILL_JEWELCRAFTING);
        uint32 reqSkillValue = itemTarget->GetTemplate()->GetRequiredSkillRank();
        player->UpdateGatherSkill(SKILL_JEWELCRAFTING, SkillValue, reqSkillValue);
    }

    itemTarget->m_loot.reset(new Loot(player->GetMap(), itemTarget->GetGUID(), LOOT_PROSPECTING, nullptr));
    itemTarget->m_loot->FillLoot(itemTarget->GetEntry(), LootTemplates_Prospecting, player, true);
    player->SendLoot(*itemTarget->m_loot);
}

void Spell::EffectMilling()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    if (!itemTarget || !itemTarget->GetTemplate()->HasFlag(ITEM_FLAG_IS_MILLABLE))
        return;

    if (itemTarget->GetCount() < 5)
        return;

    if (sWorld->getBoolConfig(CONFIG_SKILL_MILLING))
    {
        uint32 SkillValue = player->GetPureSkillValue(SKILL_INSCRIPTION);
        uint32 reqSkillValue = itemTarget->GetTemplate()->GetRequiredSkillRank();
        player->UpdateGatherSkill(SKILL_INSCRIPTION, SkillValue, reqSkillValue);
    }

    itemTarget->m_loot.reset(new Loot(player->GetMap(), itemTarget->GetGUID(), LOOT_MILLING, nullptr));
    itemTarget->m_loot->FillLoot(itemTarget->GetEntry(), LootTemplates_Milling, player, true);
    player->SendLoot(*itemTarget->m_loot);
}

void Spell::EffectSkill()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Player* playerTarget = Object::ToPlayer(GetUnitCasterForEffectHandlers());
    if (!playerTarget)
        return;

    if (damage < 1)
        return;

    uint32 skillid = effectInfo->MiscValue;
    if (playerTarget->GetSkillStep(skillid) >= damage)
        return;

    SkillRaceClassInfoEntry const* rcEntry = sDB2Manager.GetSkillRaceClassInfo(skillid, playerTarget->GetRace(), playerTarget->GetClass());
    if (!rcEntry)
        return;

    SkillTiersEntry const* tier = sObjectMgr->GetSkillTier(rcEntry->SkillTierID);
    if (!tier)
        return;

    uint16 skillval = std::max<uint16>(1, playerTarget->GetPureSkillValue(skillid));
    uint16 maxSkillVal = tier->GetValueForTierIndex(damage - 1);

    if (rcEntry->Flags & SKILL_FLAG_ALWAYS_MAX_VALUE)
        skillval = maxSkillVal;

    playerTarget->SetSkill(skillid, damage, skillval, maxSkillVal);
}

void Spell::EffectSpiritHeal()
{
    Unit* caster = GetCaster()->ToUnit();
    if (effectHandleMode == SPELL_EFFECT_HANDLE_HIT)
        caster->CastSpell(nullptr, SPELL_RESURRECTION_VISUAL, true);

    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (Player* playerTarget = unitTarget->ToPlayer())
    {
        if (!playerTarget->IsInWorld())
            return;

        // skip if player does not want to live
        if (!playerTarget->CanAcceptAreaSpiritHealFrom(caster))
            return;

        playerTarget->ResurrectPlayer(1.0f);
        playerTarget->CastSpell(playerTarget, SPELL_PET_SUMMONED, true);
        playerTarget->CastSpell(playerTarget, SPELL_SPIRIT_HEAL_MANA, true);
        playerTarget->SpawnCorpseBones(false);
    }
}

// remove insignia spell effect
void Spell::EffectSkinPlayerCorpse()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    TC_LOG_DEBUG("spells", "Effect: SkinPlayerCorpse");

    Player* player = m_caster->ToPlayer();

    Player* target = nullptr;
    if (unitTarget)
        target = unitTarget->ToPlayer();
    else if (m_corpseTarget)
        target = ObjectAccessor::FindPlayer(m_corpseTarget->GetOwnerGUID());

    if (!player || !target || target->IsAlive())
        return;

    target->RemovedInsignia(player);
}

void Spell::EffectStealBeneficialBuff()
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
            if (!aurApp->IsPositive() || aura->IsPassive() || aura->GetSpellInfo()->HasAttribute(SPELL_ATTR4_CANNOT_BE_STOLEN))
                continue;

            // 2.4.3 Patch Notes: "Dispel effects will no longer attempt to remove effects that have 100% dispel resistance."
            int32 chance = aura->CalcDispelChance(unitTarget, !unitTarget->IsFriendlyTo(m_caster));
            if (!chance)
                continue;

            // The charges / stack amounts don't count towards the total number of auras that can be dispelled.
            // Ie: A dispel on a target with 5 stacks of Winters Chill and a Polymorph has 1 / (1 + 1) -> 50% chance to dispell
            // Polymorph instead of 1 / (5 + 1) -> 16%.
            bool dispelCharges = aura->GetSpellInfo()->HasAttribute(SPELL_ATTR7_DISPEL_REMOVES_CHARGES);
            uint8 charges = dispelCharges ? aura->GetCharges() : aura->GetStackAmount();
            if (charges > 0)
                stealList.emplace_back(aura, chance, charges);
        }
    }

    if (stealList.empty())
        return;

    size_t remaining = stealList.size();

    // Ok if exist some buffs for dispel try dispel it
    std::vector<std::tuple<uint32, ObjectGuid, int32>> successList;
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
            uint8 stolenCharges = 1;
            if (itr->GetAura()->GetSpellInfo()->HasAttribute(SPELL_ATTR1_DISPEL_ALL_STACKS))
                stolenCharges = itr->GetDispelCharges();

            successList.emplace_back(itr->GetAura()->GetId(), itr->GetAura()->GetCasterGUID(), int32(stolenCharges));
            if (!itr->DecrementCharge(stolenCharges))
            {
                --remaining;
                std::swap(*itr, stealList[remaining]);
            }
        }
        else
        {
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

    for (auto const& [spellId, auraCaster, stolenCharges] : successList)
    {
        WorldPackets::CombatLog::SpellDispellData dispellData;
        dispellData.SpellID = spellId;
        dispellData.Harmful = false;      // TODO: use me

        unitTarget->RemoveAurasDueToSpellBySteal(spellId, auraCaster, m_caster, stolenCharges);

        spellDispellLog.DispellData.emplace_back(dispellData);
    }

    m_caster->SendMessageToSet(spellDispellLog.Write(), true);

    m_hitMask |= PROC_HIT_DISPEL;
}

void Spell::EffectKillCreditPersonal()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->KilledMonsterCredit(effectInfo->MiscValue);
}

void Spell::EffectKillCredit()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (int32 creatureEntry = effectInfo->MiscValue)
        unitTarget->ToPlayer()->RewardPlayerAndGroupAtEvent(creatureEntry, unitTarget);
}

void Spell::EffectQuestFail()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->FailQuest(effectInfo->MiscValue);
}

void Spell::EffectQuestStart()
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

void Spell::EffectCreateTamedPet()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER || !unitTarget->GetPetGUID().IsEmpty() || unitTarget->GetClass() != CLASS_HUNTER)
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

void Spell::EffectDiscoverTaxi()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;
    uint32 nodeid = effectInfo->MiscValue;
    if (sTaxiNodesStore.LookupEntry(nodeid))
        unitTarget->ToPlayer()->GetSession()->SendDiscoverNewTaxiNode(nodeid);
}

void Spell::EffectTitanGrip()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() == TYPEID_PLAYER)
        m_caster->ToPlayer()->SetCanTitanGrip(true, uint32(effectInfo->MiscValue));
}

void Spell::EffectRedirectThreat()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    if (unitTarget)
        unitCaster->GetThreatManager().RegisterRedirectThreat(m_spellInfo->Id, unitTarget->GetGUID(), uint32(damage));
}

void Spell::EffectGameObjectDamage()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!gameObjTarget)
        return;

    FactionTemplateEntry const* casterFaction = m_caster->GetFactionTemplateEntry();
    FactionTemplateEntry const* targetFaction = sFactionTemplateStore.LookupEntry(gameObjTarget->GetFaction());
    // Do not allow to damage GO's of friendly factions (ie: Wintergrasp Walls/Ulduar Storm Beacons)
    if (!targetFaction || (casterFaction && !casterFaction->IsFriendlyTo(targetFaction)))
        gameObjTarget->ModifyHealth(-damage, m_caster, GetSpellInfo()->Id);
}

void Spell::EffectGameObjectRepair()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!gameObjTarget)
        return;

    gameObjTarget->ModifyHealth(damage, m_caster);
}

void Spell::EffectGameObjectSetDestructionState()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!gameObjTarget)
        return;

    gameObjTarget->SetDestructibleState(GameObjectDestructibleState(effectInfo->MiscValue), m_caster, true);
}

void Spell::SummonGuardian(SpellEffectInfo const* effect, uint32 entry, SummonPropertiesEntry const* properties, uint32 numGuardians, ObjectGuid privateObjectOwner)
{
    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    if (unitCaster->IsTotem())
        unitCaster = unitCaster->ToTotem()->GetOwner();

    // in another case summon new
    float radius = 5.0f;
    Milliseconds duration = Milliseconds(m_spellInfo->CalcDuration(m_originalCaster));

    //TempSummonType summonType = (duration == 0) ? TEMPSUMMON_DEAD_DESPAWN : TEMPSUMMON_TIMED_DESPAWN;
    Map* map = unitCaster->GetMap();
    for (uint32 count = 0; count < numGuardians; ++count)
    {
        Position pos;
        if (count == 0)
            pos = destTarget->GetPosition();
        else
            // randomize position for multiple summons
            pos = unitCaster->GetRandomPoint(*destTarget, radius);

        TempSummon* summon = map->SummonCreature(entry, pos, properties, duration, unitCaster, m_spellInfo->Id, 0, privateObjectOwner);
        if (!summon)
            return;

        if (summon->IsGuardian())
        {
            // level of pet summoned using engineering item based at engineering skill level
            if (m_CastItem && unitCaster->GetTypeId() == TYPEID_PLAYER)
                if (ItemTemplate const* proto = m_CastItem->GetTemplate())
                    if (proto->GetRequiredSkill() == SKILL_ENGINEERING)
                        if (uint16 skill202 = unitCaster->ToPlayer()->GetSkillValue(SKILL_ENGINEERING))
                            static_cast<Guardian*>(summon)->InitStatsForLevel(skill202 / 5);
        }

        if (summon->HasUnitTypeMask(UNIT_MASK_MINION) && m_targets.HasDst())
            ((Minion*)summon)->SetFollowAngle(unitCaster->GetAbsoluteAngle(summon));

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

        ExecuteLogEffectSummonObject(SpellEffectName(effect->Effect), summon);
    }
}

void Spell::EffectRenamePet()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_UNIT ||
        !unitTarget->IsPet() || ((Pet*)unitTarget)->getPetType() != HUNTER_PET)
        return;

    unitTarget->SetPetFlag(UNIT_PET_FLAG_CAN_BE_RENAMED);
}

void Spell::EffectPlayMusic()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    uint32 soundid = effectInfo->MiscValue;

    if (!sSoundKitStore.LookupEntry(soundid))
    {
        TC_LOG_ERROR("spells", "EffectPlayMusic: Sound (Id: {}) does not exist in spell {}.", soundid, m_spellInfo->Id);
        return;
    }

    unitTarget->ToPlayer()->SendDirectMessage(WorldPackets::Misc::PlayMusic(soundid).Write());
}

void Spell::EffectActivateSpec()
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

void Spell::EffectPlaySound()
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
        TC_LOG_ERROR("spells", "EffectPlaySound: Sound (Id: {}) does not exist in spell {}.", soundId, m_spellInfo->Id);
        return;
    }

    player->PlayDirectSound(soundId, player);
}

void Spell::EffectRemoveAura()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;
    // there may be need of specifying casterguid of removed auras
    unitTarget->RemoveAurasDueToSpell(effectInfo->TriggerSpell);
}

void Spell::EffectDamageFromMaxHealthPCT()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    m_damage += unitTarget->CountPctFromMaxHealth(damage);
}

void Spell::EffectGiveCurrency()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (!sCurrencyTypesStore.LookupEntry(effectInfo->MiscValue))
        return;

    unitTarget->ToPlayer()->ModifyCurrency(effectInfo->MiscValue, damage, CurrencyGainSource::Spell, CurrencyDestroyReason::Spell);
}

void Spell::EffectCastButtons()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    Player* player = m_caster->ToPlayer();
    if (!player)
        return;

    uint32 button_id = effectInfo->MiscValue + 132;
    uint32 n_buttons = effectInfo->MiscValueB;

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

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spell_id, GetCastDifficulty());
        if (!spellInfo)
            continue;

        if (!player->HasSpell(spell_id) || player->GetSpellHistory()->HasCooldown(spell_id))
            continue;

        if (!spellInfo->HasAttribute(SPELL_ATTR7_CAN_BE_MULTI_CAST))
            continue;

        CastSpellExtraArgs args;
        args.TriggerFlags = TRIGGERED_IGNORE_GCD | TRIGGERED_IGNORE_CAST_IN_PROGRESS | TRIGGERED_IGNORE_CAST_TIME | TRIGGERED_CAST_DIRECTLY | TRIGGERED_DONT_REPORT_CAST_ERROR;
        args.OriginalCastId = m_castId;
        args.CastDifficulty = GetCastDifficulty();
        m_caster->CastSpell(m_caster, spellInfo->Id, args);
    }
}

void Spell::EffectRechargeItem()
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

void Spell::EffectBind()
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

    TC_LOG_DEBUG("spells", "EffectBind: New homebind X: {}, Y: {}, Z: {} O: {}, MapId: {}, AreaId: {}",
        homeLoc.GetPositionX(), homeLoc.GetPositionY(), homeLoc.GetPositionZ(), homeLoc.GetOrientation(), homeLoc.GetMapId(), areaId);

    // zone update
    player->SendPlayerBound(m_caster->GetGUID(), areaId);
}

void Spell::EffectTeleportToReturnPoint()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (Player* player = unitTarget->ToPlayer())
        if (WorldLocation const* dest = player->GetStoredAuraTeleportLocation(effectInfo->MiscValue))
            player->TeleportTo(*dest, unitTarget == m_caster ? TELE_TO_SPELL | TELE_TO_NOT_LEAVE_COMBAT : TELE_TO_NONE);
}

void Spell::EffectIncreaseCurrencyCap()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (damage <= 0)
        return;

    if (Player* player = unitTarget->ToPlayer())
        player->IncreaseCurrencyCap(effectInfo->MiscValue, damage);
}

void Spell::EffectSummonRaFFriend()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER || !unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    m_caster->CastSpell(unitTarget, effectInfo->TriggerSpell, this);
}

void Spell::EffectUnlockGuildVaultTab()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    // Safety checks done in Spell::CheckCast
    Player* caster = m_caster->ToPlayer();
    if (Guild* guild = caster->GetGuild())
        guild->HandleBuyBankTab(caster->GetSession(), damage - 1); // Bank tabs start at zero internally
}

void Spell::EffectSummonPersonalGameObject()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    uint32 goId = effectInfo->MiscValue;
    if (!goId)
        return;

    float x, y, z, o;
    if (m_targets.HasDst())
        destTarget->GetPosition(x, y, z, o);
    else
    {
        m_caster->GetClosePoint(x, y, z, DEFAULT_PLAYER_BOUNDING_RADIUS);
        o = m_caster->GetOrientation();
    }

    Map* map = m_caster->GetMap();
    Position pos = Position(x, y, z, o);
    QuaternionData rot = QuaternionData::fromEulerAnglesZYX(o, 0.f, 0.f);
    GameObject* go = GameObject::CreateGameObject(goId, map, pos, rot, 255, GO_STATE_READY);

    if (!go)
    {
        TC_LOG_WARN("spells", "SpellEffect Failed to summon personal gameobject. SpellId {}, effect {}", m_spellInfo->Id, effectInfo->EffectIndex);
        return;
    }

    PhasingHandler::InheritPhaseShift(go, m_caster);

    int32 duration = m_spellInfo->CalcDuration(m_caster);

    go->SetRespawnTime(duration > 0 ? duration / IN_MILLISECONDS : 0);
    go->SetSpellId(m_spellInfo->Id);
    go->SetPrivateObjectOwner(m_caster->GetGUID());

    ExecuteLogEffectSummonObject(SpellEffectName(effectInfo->Effect), go);

    map->AddToMap(go);

    if (GameObject* linkedTrap = go->GetLinkedTrap())
    {
        PhasingHandler::InheritPhaseShift(linkedTrap, m_caster);

        linkedTrap->SetRespawnTime(duration > 0 ? duration / IN_MILLISECONDS : 0);
        linkedTrap->SetSpellId(m_spellInfo->Id);

        ExecuteLogEffectSummonObject(SpellEffectName(effectInfo->Effect), linkedTrap);
    }
}

void Spell::EffectResurrectWithAura()
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

    ExecuteLogEffectResurrect(SpellEffectName(effectInfo->Effect), target);
    target->SetResurrectRequestData(m_caster, health, mana, resurrectAura);
    SendResurrectRequest(target);
}

void Spell::EffectCreateAreaTrigger()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster || !m_targets.HasDst())
        return;

    AreaTriggerCreatePropertiesId createPropertiesId = { uint32(effectInfo->MiscValue), false };
    int32 duration = GetSpellInfo()->CalcDuration(GetCaster());

    AreaTrigger::CreateAreaTrigger(createPropertiesId, destTarget->GetPosition(), duration, unitCaster, nullptr, m_SpellVisual, GetSpellInfo(), this);
}

void Spell::EffectRemoveTalent()
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

void Spell::EffectDestroyItem()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Player* player = unitTarget->ToPlayer();
    if (Item* item = player->GetItemByEntry(effectInfo->ItemType))
        player->DestroyItem(item->GetBagSlot(), item->GetSlot(), true);
}

void Spell::EffectLearnGarrisonBuilding()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (Garrison* garrison = unitTarget->ToPlayer()->GetGarrison())
        garrison->LearnBlueprint(effectInfo->MiscValue);
}

void Spell::EffectRemoveAuraBySpellLabel()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    unitTarget->RemoveAppliedAuras([&](AuraApplication const* aurApp)
    {
        return aurApp->GetBase()->GetSpellInfo()->HasLabel(effectInfo->MiscValue);
    });
}

void Spell::EffectCreateGarrison()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->CreateGarrison(effectInfo->MiscValue);
}

void Spell::EffectCreateConversation()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster || !m_targets.HasDst())
        return;

    Conversation::CreateConversation(effectInfo->MiscValue, unitCaster, destTarget->GetPosition(), ObjectGuid::Empty, GetSpellInfo());
}

void Spell::EffectCancelConversation()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget)
        return;

    std::vector<WorldObject*> objs;
    Trinity::ObjectEntryAndPrivateOwnerIfExistsCheck check(unitTarget->GetGUID(), effectInfo->MiscValue);
    Trinity::WorldObjectListSearcher<Trinity::ObjectEntryAndPrivateOwnerIfExistsCheck> checker(unitTarget, objs, check, GRID_MAP_TYPE_MASK_CONVERSATION);
    Cell::VisitGridObjects(unitTarget, checker, 100.0f);

    for (WorldObject* obj : objs)
    {
        if (Conversation* convo = obj->ToConversation())
            convo->Remove();
    }
}

void Spell::EffectAddGarrisonFollower()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (Garrison* garrison = unitTarget->ToPlayer()->GetGarrison())
        garrison->AddFollower(effectInfo->MiscValue);
}

void Spell::EffectCreateHeirloomItem()
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

    DoCreateItem(m_misc.Raw.Data[0], ItemContext::NONE, &bonusList);
    ExecuteLogEffectCreateItem(SpellEffectName(effectInfo->Effect), m_misc.Raw.Data[0]);
}

void Spell::EffectActivateGarrisonBuilding()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (Garrison* garrison = unitTarget->ToPlayer()->GetGarrison())
        garrison->ActivateBuilding(effectInfo->MiscValue);
}

void Spell::EffectGrantBattlePetLevel()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* playerCaster = m_caster->ToPlayer();
    if (!playerCaster)
        return;

    if (!unitTarget || !unitTarget->IsCreature())
        return;

    playerCaster->GetSession()->GetBattlePetMgr()->GrantBattlePetLevel(unitTarget->GetBattlePetCompanionGUID(), damage);
}

void Spell::EffectGiveExperience()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* playerTarget = Object::ToPlayer(unitTarget);
    if (!playerTarget)
        return;

    uint32 xp = Quest::XPValue(playerTarget, effectInfo->MiscValue, effectInfo->MiscValueB);
    playerTarget->GiveXP(xp, nullptr);
}

void Spell::EffectGiveRestedExperience()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* playerTarget = Object::ToPlayer(unitTarget);
    if (!playerTarget)
        return;

    // effect value is number of resting hours
    playerTarget->GetRestMgr().AddRestBonus(REST_TYPE_XP, damage * HOUR * playerTarget->GetRestMgr().CalcExtraPerSec(REST_TYPE_XP, 0.125f));
}

void Spell::EffectHealBattlePetPct()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (BattlePets::BattlePetMgr* battlePetMgr = unitTarget->ToPlayer()->GetSession()->GetBattlePetMgr())
        battlePetMgr->HealBattlePetsPct(damage);
}

void Spell::EffectEnableBattlePets()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsPlayer())
        return;

    Player* player = unitTarget->ToPlayer();
    player->SetPlayerFlag(PLAYER_FLAGS_PET_BATTLES_UNLOCKED);
    player->GetSession()->GetBattlePetMgr()->UnlockSlot(BattlePets::BattlePetSlot::Slot0);
}

void Spell::EffectChangeBattlePetQuality()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* playerCaster = m_caster->ToPlayer();
    if (!playerCaster)
        return;

    if (!unitTarget || !unitTarget->IsCreature())
        return;

    auto qualityItr = std::lower_bound(sBattlePetBreedQualityStore.begin(), sBattlePetBreedQualityStore.end(), damage, [](BattlePetBreedQualityEntry const* a1, int32 selector)
    {
        return a1->MaxQualityRoll < selector;
    });

    BattlePets::BattlePetBreedQuality quality = BattlePets::BattlePetBreedQuality::Poor;
    if (qualityItr != sBattlePetBreedQualityStore.end())
        quality = BattlePets::BattlePetBreedQuality(qualityItr->QualityEnum);

    playerCaster->GetSession()->GetBattlePetMgr()->ChangeBattlePetQuality(unitTarget->GetBattlePetCompanionGUID(), quality);
}

void Spell::EffectLaunchQuestChoice()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || !unitTarget->IsPlayer())
        return;

    unitTarget->ToPlayer()->SendPlayerChoice(GetCaster()->GetGUID(), effectInfo->MiscValue);
}

void Spell::EffectUncageBattlePet()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (!m_CastItem || !m_caster || m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    uint32 speciesId = m_CastItem->GetModifier(ITEM_MODIFIER_BATTLE_PET_SPECIES_ID);
    uint16 breed = m_CastItem->GetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA) & 0xFFFFFF;
    uint8 quality = (m_CastItem->GetModifier(ITEM_MODIFIER_BATTLE_PET_BREED_DATA) >> 24) & 0xFF;
    uint16 level = m_CastItem->GetModifier(ITEM_MODIFIER_BATTLE_PET_LEVEL);
    uint32 displayId = m_CastItem->GetModifier(ITEM_MODIFIER_BATTLE_PET_DISPLAY_ID);

    BattlePetSpeciesEntry const* speciesEntry = sBattlePetSpeciesStore.LookupEntry(speciesId);
    if (!speciesEntry)
        return;

    Player* player = m_caster->ToPlayer();
    BattlePets::BattlePetMgr* battlePetMgr = player->GetSession()->GetBattlePetMgr();
    if (!battlePetMgr)
        return;

    if (battlePetMgr->GetMaxPetLevel() < level)
    {
        battlePetMgr->SendError(BattlePets::BattlePetError::TooHighLevelToUncage, speciesEntry->CreatureID);
        SendCastResult(SPELL_FAILED_CANT_ADD_BATTLE_PET);
        return;
    }

    if (battlePetMgr->HasMaxPetCount(speciesEntry, player->GetGUID()))
    {
        battlePetMgr->SendError(BattlePets::BattlePetError::CantHaveMorePetsOfType, speciesEntry->CreatureID);
        SendCastResult(SPELL_FAILED_CANT_ADD_BATTLE_PET);
        return;
    }

    battlePetMgr->AddPet(speciesId, displayId, breed, BattlePets::BattlePetBreedQuality(quality), level);

    player->SendPlaySpellVisual(player, BattlePets::SPELL_VISUAL_UNCAGE_PET, 0, 0, 0.f, false);

    player->DestroyItem(m_CastItem->GetBagSlot(), m_CastItem->GetSlot(), true);
    m_CastItem = nullptr;
}

void Spell::EffectUpgradeHeirloom()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (Player* player = m_caster->ToPlayer())
        if (CollectionMgr* collectionMgr = player->GetSession()->GetCollectionMgr())
            collectionMgr->UpgradeHeirloom(m_misc.Raw.Data[0], int32(m_castItemEntry));
}

void Spell::EffectApplyEnchantIllusion()
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

void Spell::EffectUpdatePlayerPhase()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    PhasingHandler::OnConditionChange(unitTarget);
}

void Spell::EffectUpdateZoneAurasAndPhases()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->UpdateAreaDependentAuras(unitTarget->GetAreaId());
}

void Spell::EffectGiveArtifactPower()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    Player* playerCaster = m_caster->ToPlayer();
    if (!playerCaster)
        return;

    if (Aura* artifactAura = playerCaster->GetAura(ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE))
        if (Item* artifact = playerCaster->GetItemByGuid(artifactAura->GetCastItemGUID()))
            artifact->GiveArtifactXp(damage, m_CastItem, uint32(effectInfo->MiscValue));
}

void Spell::EffectGiveArtifactPowerNoBonus()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    if (Aura* artifactAura = unitTarget->GetAura(ARTIFACTS_ALL_WEAPONS_GENERAL_WEAPON_EQUIPPED_PASSIVE))
        if (Item* artifact = unitTarget->ToPlayer()->GetItemByGuid(artifactAura->GetCastItemGUID()))
            artifact->GiveArtifactXp(damage, m_CastItem, 0);
}

void Spell::EffectPlaySceneScriptPackage()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    m_caster->ToPlayer()->GetSceneMgr().PlaySceneByPackageId(effectInfo->MiscValue, SceneFlag::PlayerNonInteractablePhased, destTarget);
}

template<typename TargetInfo>
bool IsUnitTargetSceneObjectAura(Spell const* spell, TargetInfo const& target)
{
    if (target.TargetGUID != spell->GetCaster()->GetGUID())
        return false;

    for (SpellEffectInfo const& spellEffectInfo : spell->GetSpellInfo()->GetEffects())
        if (target.EffectMask & (1 << spellEffectInfo.EffectIndex) && spellEffectInfo.IsUnitOwnedAuraEffect())
            return true;

    return false;
}

void Spell::EffectCreateSceneObject()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster || !m_targets.HasDst())
        return;

    if (SceneObject* sceneObject = SceneObject::CreateSceneObject(effectInfo->MiscValue, unitCaster, destTarget->GetPosition(), ObjectGuid::Empty))
    {
        bool hasAuraTargetingCaster = std::find_if(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [this](TargetInfo const& target)
        {
            return IsUnitTargetSceneObjectAura(this, target);
        }) != m_UniqueTargetInfo.end();

        if (hasAuraTargetingCaster)
            sceneObject->SetCreatedBySpellCast(m_castId);
    }
}

void Spell::EffectCreatePrivateSceneObject()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster || !m_targets.HasDst())
        return;

    if (SceneObject* sceneObject = SceneObject::CreateSceneObject(effectInfo->MiscValue, unitCaster, destTarget->GetPosition(), unitCaster->GetGUID()))
    {
        bool hasAuraTargetingCaster = std::find_if(m_UniqueTargetInfo.begin(), m_UniqueTargetInfo.end(), [this](TargetInfo const& target)
        {
            return IsUnitTargetSceneObjectAura(this, target);
        }) != m_UniqueTargetInfo.end();

        if (hasAuraTargetingCaster)
            sceneObject->SetCreatedBySpellCast(m_castId);
    }
}

void Spell::EffectPlayScene()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT)
        return;

    if (m_caster->GetTypeId() != TYPEID_PLAYER)
        return;

    m_caster->ToPlayer()->GetSceneMgr().PlayScene(effectInfo->MiscValue, destTarget);
}

void Spell::EffectGiveHonor()
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

void Spell::EffectJumpCharge()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    if (unitCaster->IsInFlight())
        return;

    JumpChargeParams const* params = sObjectMgr->GetJumpChargeParams(effectInfo->MiscValue);
    if (!params)
        return;

    float speed = params->Speed;
    if (params->TreatSpeedAsMoveTimeSeconds)
        speed = unitCaster->GetExactDist(destTarget) / params->MoveTimeInSec;

    MovementFacingTarget facing;
    if (Unit const* target = m_targets.GetUnitTarget())
    {
        if (m_spellInfo->HasAttribute(SPELL_ATTR9_FACE_UNIT_TARGET_UPON_COMPLETION_OF_JUMP_CHARGE))
            facing = target;
    }

    Optional<JumpArrivalCastArgs> arrivalCast;
    if (effectInfo->TriggerSpell)
    {
        arrivalCast.emplace();
        arrivalCast->SpellId = effectInfo->TriggerSpell;
    }

    Optional<Movement::SpellEffectExtraData> effectExtra;
    if (params->SpellVisualId || params->ProgressCurveId || params->ParabolicCurveId)
    {
        effectExtra.emplace();
        if (params->SpellVisualId)
            effectExtra->SpellVisualId = *params->SpellVisualId;

        if (params->ProgressCurveId)
            effectExtra->ProgressCurveId = *params->ProgressCurveId;

        if (params->ParabolicCurveId)
            effectExtra->ParabolicCurveId = *params->ParabolicCurveId;
    }

    unitCaster->GetMotionMaster()->MoveJumpWithGravity(*destTarget, speed, params->JumpGravity, EVENT_JUMP, facing,
        m_spellInfo->HasAttribute(SPELL_ATTR9_JUMPCHARGE__NO_FACING_CONTROL),
        arrivalCast ? &*arrivalCast : nullptr,
        effectExtra ? &*effectExtra : nullptr);
}

void Spell::EffectLearnTransmogSet()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    if (!unitTarget || unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    unitTarget->ToPlayer()->GetSession()->GetCollectionMgr()->AddTransmogSet(effectInfo->MiscValue);
}

void Spell::EffectRespecAzeriteEmpoweredItem()
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

void Spell::EffectLearnAzeriteEssencePower()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* playerTarget = unitTarget ? unitTarget->ToPlayer() : nullptr;
    if (!playerTarget)
        return;

    Item* heartOfAzeroth = playerTarget->GetItemByEntry(ITEM_ID_HEART_OF_AZEROTH, ItemSearchLocation::Everywhere);
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

void Spell::EffectCreatePrivateConversation()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_LAUNCH_TARGET)
        return;

    if (unitTarget->GetTypeId() != TYPEID_PLAYER)
        return;

    Conversation::CreateConversation(effectInfo->MiscValue, unitTarget, destTarget->GetPosition(), unitTarget->GetGUID(), GetSpellInfo());
}

void Spell::EffectSendChatMessage()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Unit* unitCaster = GetUnitCasterForEffectHandlers();
    if (!unitCaster)
        return;

    uint32 broadcastTextId = effectInfo->MiscValue;
    if (!sBroadcastTextStore.LookupEntry(broadcastTextId))
        return;

    ChatMsg chatType = ChatMsg(effectInfo->MiscValueB);
    unitCaster->Talk(broadcastTextId, chatType, CreatureTextMgr::GetRangeForChatType(chatType), unitTarget);
}

void Spell::EffectGrantBattlePetExperience()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* playerCaster = m_caster->ToPlayer();
    if (!playerCaster)
        return;

    if (!unitTarget || !unitTarget->IsCreature())
        return;

    playerCaster->GetSession()->GetBattlePetMgr()->GrantBattlePetExperience(unitTarget->GetBattlePetCompanionGUID(), damage, BattlePets::BattlePetXpSource::SpellEffect);
}

void Spell::EffectLearnTransmogIllusion()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* player = Object::ToPlayer(unitTarget);
    if (!player)
        return;

    uint32 illusionId = effectInfo->MiscValue;
    if (!sTransmogIllusionStore.LookupEntry(illusionId))
        return;

    player->GetSession()->GetCollectionMgr()->AddTransmogIllusion(illusionId);
}

void Spell::EffectModifyAuraStacks()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Aura* targetAura = unitTarget->GetAura(effectInfo->TriggerSpell);
    if (!targetAura)
        return;

    switch (effectInfo->MiscValue)
    {
        case 0:
            targetAura->ModStackAmount(damage);
            break;
        case 1:
            targetAura->SetStackAmount(damage);
            break;
        default:
            break;
    }
}

void Spell::EffectModifyCooldown()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    unitTarget->GetSpellHistory()->ModifyCooldown(effectInfo->TriggerSpell, Milliseconds(damage));
}

void Spell::EffectModifyCooldowns()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    unitTarget->GetSpellHistory()->ModifyCoooldowns([this](SpellHistory::CooldownStorageType::iterator itr)
    {
        SpellInfo const* spellOnCooldown = sSpellMgr->AssertSpellInfo(itr->first, DIFFICULTY_NONE);
        if (spellOnCooldown->SpellFamilyName != uint32(effectInfo->MiscValue))
            return false;

        int32 bitIndex = effectInfo->MiscValueB - 1;
        if (bitIndex < 0 || uint32(bitIndex) >= sizeof(flag128) * 8)
            return false;

        flag128 reqFlag;
        reqFlag[bitIndex / 32] = 1u << (bitIndex % 32);
        return bool(spellOnCooldown->SpellFamilyFlags & reqFlag);
    }, Milliseconds(damage));
}

void Spell::EffectModifyCooldownsByCategory()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    unitTarget->GetSpellHistory()->ModifyCoooldowns([this](SpellHistory::CooldownStorageType::iterator itr)
    {
        return sSpellMgr->AssertSpellInfo(itr->first, DIFFICULTY_NONE)->CategoryId == uint32(effectInfo->MiscValue);
    }, Milliseconds(damage));
}

void Spell::EffectModifySpellCharges()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    for (int32 i = 0; i < damage; ++i)
        unitTarget->GetSpellHistory()->RestoreCharge(effectInfo->MiscValue);
}

void Spell::EffectCreateTraitTreeConfig()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* target = Object::ToPlayer(unitTarget);
    if (!target)
        return;

    if (target->IsLoading() && target->m_activePlayerData->TraitConfigs.empty())
        return; // traits not loaded yet

    WorldPackets::Traits::TraitConfig newConfig;
    newConfig.Type = TraitMgr::GetConfigTypeForTree(effectInfo->MiscValue);
    if (newConfig.Type != TraitConfigType::Generic)
        return;

    newConfig.TraitSystemID = sTraitTreeStore.AssertEntry(effectInfo->MiscValue)->TraitSystemID;
    int32 existingConfigForSystem = target->m_activePlayerData->TraitConfigs.FindIndexIf([&](UF::TraitConfig const& config)
    {
        return static_cast<TraitConfigType>(*config.Type) == TraitConfigType::Generic
            && config.TraitSystemID == newConfig.TraitSystemID;
    });

    if (existingConfigForSystem < 0)
        target->CreateTraitConfig(newConfig);
}

void Spell::EffectChangeActiveCombatTraitConfig()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* target = Object::ToPlayer(unitTarget);
    if (!target)
        return;

    WorldPackets::Traits::TraitConfig* traitConfig = std::any_cast<WorldPackets::Traits::TraitConfig>(&m_customArg);
    if (!traitConfig)
        return;

    target->UpdateTraitConfig(std::move(*traitConfig), damage, false);
}

void Spell::EffectTeleportGraveyard()
{
    if (effectHandleMode != SPELL_EFFECT_HANDLE_HIT_TARGET)
        return;

    Player* target = Object::ToPlayer(unitTarget);
    if (!target)
        return;

    target->RepopAtGraveyard();
}
