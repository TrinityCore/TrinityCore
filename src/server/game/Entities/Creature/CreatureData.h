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

#ifndef CreatureData_h__
#define CreatureData_h__

#include "Common.h"
#include "DBCEnums.h"
#include "EnumFlag.h"
#include "Optional.h"
#include "SharedDefines.h"
#include "SpawnData.h"
#include "UnitDefines.h"
#include "WorldPacket.h"
#include <string>
#include <unordered_map>
#include <cmath>

struct ItemTemplate;
enum class VisibilityDistanceType : uint8;

enum CreatureStaticFlags : uint32
{
    CREATURE_STATIC_FLAG_MOUNTABLE                                  = 0x00000001, // Mountable
    CREATURE_STATIC_FLAG_NO_XP                                      = 0x00000002, // No XP | CREATURE_FLAG_EXTRA_NO_XP
    CREATURE_STATIC_FLAG_NO_LOOT                                    = 0x00000004, // No Loot
    CREATURE_STATIC_FLAG_UNKILLABLE                                 = 0x00000008, // Unkillable
    CREATURE_STATIC_FLAG_TAMEABLE                                   = 0x00000010, // Tameable | CREATURE_TYPE_FLAG_TAMEABLE
    CREATURE_STATIC_FLAG_IMMUNE_PC                                  = 0x00000020, // ImmunePC | UNIT_FLAG_IMMUNE_TO_PC
    CREATURE_STATIC_FLAG_IMMUNE_NPC                                 = 0x00000040, // ImmuneNPC | UNIT_FLAG_IMMUNE_TO_NPC
    CREATURE_STATIC_FLAG_CAN_WIELD_LOOT                             = 0x00000080, // CanWieldLoot
    CREATURE_STATIC_FLAG_SESSILE                                    = 0x00000100, // Sessile | Rooted movementflag, creature is permanently rooted in place
    CREATURE_STATIC_FLAG_UNINTERACTIBLE                             = 0x00000200, // Uninteractible | UNIT_FLAG_UNINTERACTIBLE
    CREATURE_STATIC_FLAG_NO_AUTOMATIC_REGEN                         = 0x00000400, // No Automatic Regen | Creatures with that flag uses no UNIT_FLAG2_REGENERATE_POWER
    CREATURE_STATIC_FLAG_DESPAWN_INSTANTLY                          = 0x00000800, // Despawn Instantly | Creature instantly disappear when killed
    CREATURE_STATIC_FLAG_CORPSE_RAID                                = 0x00001000, // CorpseRaid
    CREATURE_STATIC_FLAG_CREATOR_LOOT                               = 0x00002000, // Creator Loot | Lootable only by creator (engineering dummies)
    CREATURE_STATIC_FLAG_NO_DEFENSE                                 = 0x00004000, // No Defense
    CREATURE_STATIC_FLAG_NO_SPELL_DEFENSE                           = 0x00008000, // No Spell Defense
    CREATURE_STATIC_FLAG_RAID_BOSS_MOB                              = 0x00010000, // Raid Boss Mob | CREATURE_TYPE_FLAG_BOSS_MOB
    CREATURE_STATIC_FLAG_COMBAT_PING                                = 0x00020000, // Combat Ping
    CREATURE_STATIC_FLAG_AQUATIC                                    = 0x00040000, // Aquatic (aka Water Only)
    CREATURE_STATIC_FLAG_AMPHIBIOUS                                 = 0x00080000, // Amphibious | Creatures will be able to enter and leave water but can only move on the ocean floor when CREATURE_STATIC_FLAG_CAN_SWIM is not present
    CREATURE_STATIC_FLAG_NO_MELEE_FLEE                              = 0x00100000, // No Melee (Flee) | Prevents melee (moves as-if feared, does not make creature passive)
    CREATURE_STATIC_FLAG_VISIBLE_TO_GHOSTS                          = 0x00200000, // Visible to Ghosts | CREATURE_TYPE_FLAG_VISIBLE_TO_GHOSTS
    CREATURE_STATIC_FLAG_PVP_ENABLING                               = 0x00400000, // PvP Enabling | Old UNIT_FLAG_PVP_ENABLING, now UNIT_BYTES_2_OFFSET_PVP_FLAG from UNIT_FIELD_BYTES_2
    CREATURE_STATIC_FLAG_DO_NOT_PLAY_WOUND_ANIM                     = 0x00800000, // Do Not Play Wound Anim | CREATURE_TYPE_FLAG_DO_NOT_PLAY_WOUND_ANIM
    CREATURE_STATIC_FLAG_NO_FACTION_TOOLTIP                         = 0x01000000, // No Faction Tooltip | CREATURE_TYPE_FLAG_NO_FACTION_TOOLTIP
    CREATURE_STATIC_FLAG_IGNORE_COMBAT                              = 0x02000000, // Ignore Combat | Actually only changes react state to passive
    CREATURE_STATIC_FLAG_ONLY_ATTACK_TARGETS_THAT_ARE_PVP_ENABLING  = 0x04000000, // Only attack targets that are PvP enabling
    CREATURE_STATIC_FLAG_CALLS_GUARDS                               = 0x08000000, // Calls Guards | Creature will summon a guard if player is within its aggro range (even if creature doesn't attack per se)
    CREATURE_STATIC_FLAG_CAN_SWIM                                   = 0x10000000, // Can Swim | UnitFlags 0x8000 UNIT_FLAG_CAN_SWIM
    CREATURE_STATIC_FLAG_FLOATING                                   = 0x20000000, // Floating <Don't Use> | sets DisableGravity movementflag on spawn/reset
    CREATURE_STATIC_FLAG_MORE_AUDIBLE                               = 0x40000000, // More Audible: Caution, Expensive | CREATURE_TYPE_FLAG_MORE_AUDIBLE
    CREATURE_STATIC_FLAG_LARGE_AOI                                  = 0x80000000  // Large (AOI): Caution, Expensive | UnitFlags2 0x200000
};

DEFINE_ENUM_FLAG(CreatureStaticFlags);

enum CreatureStaticFlags2 : uint32
{
    CREATURE_STATIC_FLAG_2_NO_PET_SCALING                           = 0x00000001, // No Pet Scaling
    CREATURE_STATIC_FLAG_2_FORCE_RAID_COMBAT                        = 0x00000002, // Force Raid Combat
    CREATURE_STATIC_FLAG_2_LOCK_TAPPERS_TO_RAID_ON_DEATH            = 0x00000004, // Lock Tappers To Raid On Death | toggleable by 'Set "RAID_LOCK_ON_DEATH" flag for unit(s)' action, CREATURE_FLAG_EXTRA_INSTANCE_BIND
    CREATURE_STATIC_FLAG_2_NO_HARMFUL_VERTEX_COLORING               = 0x00000008, // No Harmful Vertex Coloring
    CREATURE_STATIC_FLAG_2_NO_CRUSHING_BLOWS                        = 0x00000010, // No Crushing Blows | CREATURE_FLAG_EXTRA_NO_CRUSHING_BLOWS
    CREATURE_STATIC_FLAG_2_NO_OWNER_THREAT                          = 0x00000020, // No Owner Threat
    CREATURE_STATIC_FLAG_2_NO_WOUNDED_SLOWDOWN                      = 0x00000040, // No Wounded Slowdown
    CREATURE_STATIC_FLAG_2_USE_CREATOR_BONUSES                      = 0x00000080, // Use Creator Bonuses
    CREATURE_STATIC_FLAG_2_IGNORE_FEIGN_DEATH                       = 0x00000100, // Ignore Feign Death | CREATURE_FLAG_EXTRA_IGNORE_FEIGN_DEATH
    CREATURE_STATIC_FLAG_2_IGNORE_SANCTUARY                         = 0x00000200, // Ignore Sanctuary | Ignores SPELL_EFFECT_SANCTUARY
    CREATURE_STATIC_FLAG_2_ACTION_TRIGGERS_WHILE_CHARMED            = 0x00000400, // Action Triggers While Charmed
    CREATURE_STATIC_FLAG_2_INTERACT_WHILE_DEAD                      = 0x00000800, // Interact While Dead | CREATURE_TYPE_FLAG_INTERACT_WHILE_DEAD
    CREATURE_STATIC_FLAG_2_NO_INTERRUPT_SCHOOL_COOLDOWN             = 0x00001000, // No Interrupt School Cooldown
    CREATURE_STATIC_FLAG_2_RETURN_SOUL_SHARD_TO_MASTER_OF_PET       = 0x00002000, // Return soul shard to master of pet
    CREATURE_STATIC_FLAG_2_SKIN_WITH_HERBALISM                      = 0x00004000, // Skin With Herbalism | CREATURE_TYPE_FLAG_SKIN_WITH_HERBALISM
    CREATURE_STATIC_FLAG_2_SKIN_WITH_MINING                         = 0x00008000, // Skin With Mining | CREATURE_TYPE_FLAG_SKIN_WITH_MINING
    CREATURE_STATIC_FLAG_2_ALERT_CONTENT_TEAM_ON_DEATH              = 0x00010000, // Alert Content Team on Death
    CREATURE_STATIC_FLAG_2_ALERT_CONTENT_TEAM_AT_90_PCT_HEALTH      = 0x00020000, // Alert Content Team at 90% Health
    CREATURE_STATIC_FLAG_2_ALLOW_MOUNTED_COMBAT                     = 0x00040000, // Allow Mounted Combat | CREATURE_TYPE_FLAG_ALLOW_MOUNTED_COMBAT
    CREATURE_STATIC_FLAG_2_PVP_ENABLING_OOC                         = 0x00080000, // PvP Enabling OOC
    CREATURE_STATIC_FLAG_2_NO_DEATH_MESSAGE                         = 0x00100000, // No Death Message | CREATURE_TYPE_FLAG_NO_DEATH_MESSAGE
    CREATURE_STATIC_FLAG_2_IGNORE_PATHING_FAILURE                   = 0x00200000, // Ignore Pathing Failure
    CREATURE_STATIC_FLAG_2_FULL_SPELL_LIST                          = 0x00400000, // Full Spell List
    CREATURE_STATIC_FLAG_2_DOESNT_REDUCE_REPUTATION_FOR_RAIDS       = 0x00800000, // Doesn't Reduce Reputation for raids
    CREATURE_STATIC_FLAG_2_IGNORE_MISDIRECTION                      = 0x01000000, // Ignore Misdirection
    CREATURE_STATIC_FLAG_2_HIDE_BODY                                = 0x02000000, // Hide Body | UNIT_FLAG2_HIDE_BODY
    CREATURE_STATIC_FLAG_2_SPAWN_DEFENSIVE                          = 0x04000000, // Spawn Defensive
    CREATURE_STATIC_FLAG_2_SERVER_ONLY                              = 0x08000000, // Server Only
    CREATURE_STATIC_FLAG_2_NO_COLLISION                             = 0x10000000, // No Collision
    CREATURE_STATIC_FLAG_2_PLAYER_CAN_HEAL_OR_BUFF                  = 0x20000000, // Player Can Heal/Buff | CREATURE_TYPE_FLAG_CAN_ASSIST
    CREATURE_STATIC_FLAG_2_NO_SKILL_GAINS                           = 0x40000000, // No Skill Gains | CREATURE_FLAG_EXTRA_NO_SKILL_GAINS
    CREATURE_STATIC_FLAG_2_NO_PET_BAR                               = 0x80000000  // No Pet Bar | CREATURE_TYPE_FLAG_NO_PET_BAR
};

DEFINE_ENUM_FLAG(CreatureStaticFlags2);

enum CreatureStaticFlags3 : uint32
{
    CREATURE_STATIC_FLAG_3_NO_DAMAGE_HISTORY                        = 0x00000001, // No Damage History
    CREATURE_STATIC_FLAG_3_DONT_PVP_ENABLE_OWNER                    = 0x00000002, // Don't PvP Enable Owner
    CREATURE_STATIC_FLAG_3_DONT_FADE_IN                             = 0x00000004, // Don't Fade In | UNIT_FLAG2_DO_NOT_FADE_IN
    CREATURE_STATIC_FLAG_3_NON_UNIQUE_IN_COMBAT_LOG                 = 0x00000008, // Non-Unique In Combat Log
    CREATURE_STATIC_FLAG_3_SKIN_WITH_ENGINEERING                    = 0x00000010, // Skin With Engineering | CREATURE_TYPE_FLAG_SKIN_WITH_ENGINEERING
    CREATURE_STATIC_FLAG_3_NO_AGGRO_ON_LEASH                        = 0x00000020, // No Aggro On Leash
    CREATURE_STATIC_FLAG_3_NO_FRIENDLY_AREA_AURAS                   = 0x00000040, // No Friendly Area Auras
    CREATURE_STATIC_FLAG_3_EXTENDED_CORPSE_DURATION                 = 0x00000080, // Extended Corpse Duration
    CREATURE_STATIC_FLAG_3_CANT_SWIM                                = 0x00000100, // Can't Swim | UNIT_FLAG_CANNOT_SWIM
    CREATURE_STATIC_FLAG_3_TAMEABLE_EXOTIC                          = 0x00000200, // Tameable (Exotic) | CREATURE_TYPE_FLAG_TAMEABLE_EXOTIC
    CREATURE_STATIC_FLAG_3_GIGANTIC_AOI                             = 0x00000400, // Gigantic (AOI): Caution, Expensive | UnitFlags2 0x400000
    CREATURE_STATIC_FLAG_3_INFINITE_AOI                             = 0x00000800, // Infinite (AOI): Caution, Expensive | UnitFlags2 0x40000000
    CREATURE_STATIC_FLAG_3_CANNOT_PENETRATE_WATER                   = 0x00001000, // Cannot Penetrate Water | Waterwalking
    CREATURE_STATIC_FLAG_3_NO_NAME_PLATE                            = 0x00002000, // No Name Plate | CREATURE_TYPE_FLAG_NO_NAME_PLATE
    CREATURE_STATIC_FLAG_3_CHECKS_LIQUIDS                           = 0x00004000, // Checks Liquids: Caution, Expensive
    CREATURE_STATIC_FLAG_3_NO_THREAT_FEEDBACK                       = 0x00008000, // No Threat Feedback
    CREATURE_STATIC_FLAG_3_USE_MODEL_COLLISION_SIZE                 = 0x00010000, // Use Model Collision Size (TALK TO A PROGRAMMER FIRST) | CREATURE_TYPE_FLAG_USE_MODEL_COLLISION_SIZE
    CREATURE_STATIC_FLAG_3_ATTACKER_IGNORES_FACING                  = 0x00020000, // Attacker Ignores Facing
    CREATURE_STATIC_FLAG_3_ALLOW_INTERACTION_WHILE_IN_COMBAT        = 0x00040000, // Allow Interaction While in Combat | CREATURE_TYPE_FLAG_ALLOW_INTERACTION_WHILE_IN_COMBAT
    CREATURE_STATIC_FLAG_3_SPELL_CLICK_FOR_PARTY_ONLY               = 0x00080000, // Spell Click for Party Only
    CREATURE_STATIC_FLAG_3_FACTION_LEADER                           = 0x00100000, // Faction Leader
    CREATURE_STATIC_FLAG_3_IMMUNE_TO_PLAYER_BUFFS                   = 0x00200000, // Immune to Player Buffs
    CREATURE_STATIC_FLAG_3_COLLIDE_WITH_MISSILES                    = 0x00400000, // Collide With Missiles | CREATURE_TYPE_FLAG_COLLIDE_WITH_MISSILES
    CREATURE_STATIC_FLAG_3_DO_NOT_TAP                               = 0x00800000, // Do Not Tap (Credit to threat list)
    CREATURE_STATIC_FLAG_3_DISABLE_DODGE_PARRY_AND_BLOCK_ANIMATIONS = 0x01000000, // Disable Dodge, Parry and Block Animations | CREATURE_TYPE_FLAG_DO_NOT_PLAY_MOUNTED_ANIMATIONS
    CREATURE_STATIC_FLAG_3_CANNOT_TURN                              = 0x02000000, // Cannot Turn | UNIT_FLAG2_CANNOT_TURN
    CREATURE_STATIC_FLAG_3_ENEMY_CHECK_IGNORES_LINE_OF_SIGHT        = 0x04000000, // Enemy Check Ignores Line of Sight
    CREATURE_STATIC_FLAG_3_FOREVER_CORPSE_DURATION                  = 0x08000000, // Forever Corpse Duration (7 days)
    CREATURE_STATIC_FLAG_3_PETS_ATTACK_WITH_3D_PATHING              = 0x10000000, // Pets attack with 3d pathing (Kologarn)
    CREATURE_STATIC_FLAG_3_LINK_ALL_FLAG                            = 0x20000000, // LinkAll flag (TALK TO A PROGRAMMER FIRST) | CREATURE_TYPE_FLAG_LINK_ALL
    CREATURE_STATIC_FLAG_3_AI_CAN_AUTO_TAKEOFF_IN_COMBAT            = 0x40000000, // AI Can Auto Takeoff in Combat
    CREATURE_STATIC_FLAG_3_AI_CAN_AUTO_LAND_IN_COMBAT               = 0x80000000  // AI Can Auto Land in Combat
};

DEFINE_ENUM_FLAG(CreatureStaticFlags3);

enum CreatureStaticFlags4 : uint32
{
    CREATURE_STATIC_FLAG_4_NO_BIRTH_ANIM                            = 0x00000001, // No Birth Anim
    CREATURE_STATIC_FLAG_4_TREAT_AS_PLAYER_FOR_DIMINISHING_RETURNS  = 0x00000002, // Treat as Player for Diminishing Returns
    CREATURE_STATIC_FLAG_4_TREAT_AS_PLAYER_FOR_PVP_DEBUFF_DURATION  = 0x00000004, // Treat as Player for PvP Debuff Duration
    CREATURE_STATIC_FLAG_4_ONLY_DISPLAY_GOSSIP_FOR_SUMMONER         = 0x00000008, // Only Display Gossip for Summoner | CREATURE_TYPE_FLAG_INTERACT_ONLY_WITH_CREATOR
    CREATURE_STATIC_FLAG_4_NO_DEATH_SCREAM                          = 0x00000010, // No Death Scream | CREATURE_TYPE_FLAG_DO_NOT_PLAY_UNIT_EVENT_SOUNDS
    CREATURE_STATIC_FLAG_4_CAN_BE_HEALED_BY_ENEMIES                 = 0x00000020, // Can be Healed by Enemies | CREATURE_TYPE_FLAG_HAS_NO_SHADOW_BLOB
    CREATURE_STATIC_FLAG_4_DEALS_TRIPLE_DAMAGE_TO_PC_CONTROLLED_PETS= 0x00000040, // Deals triple damage to PC controlled pets
    CREATURE_STATIC_FLAG_4_NO_NPC_DAMAGE_BELOW_85_PCT               = 0x00000080, // No NPC damage below 85%
    CREATURE_STATIC_FLAG_4_OBEYS_TAUNT_DIMINISHING_RETURNS          = 0x00000100, // Obeys Taunt Diminishing Returns | CREATURE_FLAG_EXTRA_OBEYS_TAUNT_DIMINISHING_RETURNS
    CREATURE_STATIC_FLAG_4_NO_MELEE_APPROACH                        = 0x00000200, // No Melee (Approach) | Prevents melee (chases into melee range, does not make creature passive)
    CREATURE_STATIC_FLAG_4_UPDATE_CREATURE_RECORD_WHEN_INSTANCE_CHANGES_DIFFICULTY = 0x00000400, // Update Creature Record when instance changes difficulty
    CREATURE_STATIC_FLAG_4_CANNOT_DAZE                              = 0x00000800, // Cannot Daze (Combat Stun)
    CREATURE_STATIC_FLAG_4_FLAT_HONOR_AWARD                         = 0x00001000, // Flat Honor Award
    CREATURE_STATIC_FLAG_4_IGNORE_LOS_WHEN_CASTING_ON_ME            = 0x00002000, // Other objects can ignore line of sight requirements when casting spells on me
    CREATURE_STATIC_FLAG_4_GIVE_QUEST_KILL_CREDIT_WHILE_OFFLINE     = 0x00004000, // Give quest kill credit while offline
    CREATURE_STATIC_FLAG_4_TREAT_AS_RAID_UNIT_FOR_HELPFUL_SPELLS    = 0x00008000, // Treat as Raid Unit For Helpful Spells (Instances ONLY) | CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT
    CREATURE_STATIC_FLAG_4_DONT_REPOSITION_BECAUSE_MELEE_TARGET_IS_TOO_CLOSE = 0x00010000, // Don't reposition because melee target is too close
    CREATURE_STATIC_FLAG_4_PET_OR_GUARDIAN_AI_DONT_GO_BEHIND_TARGET = 0x00020000, // Pet/Guardian AI Don't Go Behind Target
    CREATURE_STATIC_FLAG_4_5_MINUTE_LOOT_ROLL_TIMER                 = 0x00040000, // 5 Minute loot roll timer
    CREATURE_STATIC_FLAG_4_FORCE_GOSSIP                             = 0x00080000, // Force Gossip | CREATURE_TYPE_FLAG_FORCE_GOSSIP
    CREATURE_STATIC_FLAG_4_DONT_REPOSITION_WITH_FRIENDS_IN_COMBAT   = 0x00100000, // Don't reposition with friends in combat
    CREATURE_STATIC_FLAG_4_MANUAL_SHEATHING_CONTROL                 = 0x00200000, // Manual Sheathing control | CREATURE_TYPE_FLAG_DO_NOT_SHEATHE
    CREATURE_STATIC_FLAG_4_ATTACKER_IGNORES_MINIMUM_RANGES          = 0x00400000, // Attacker Ignores Minimum Ranges | UnitFlags2 0x8000000
    CREATURE_STATIC_FLAG_4_SUPPRESS_INSTANCE_WIDE_RELEASE_IN_COMBAT = 0x00800000, // Suppress Instance Wide Release in Combat
    CREATURE_STATIC_FLAG_4_AI_WILL_ONLY_SWIM_IF_TARGET_SWIMS        = 0x01000000, // AI will only swim if target swims | UnitFlags2 0x1000000
    CREATURE_STATIC_FLAG_4_DONT_GENERATE_COMBAT_LOG_WHEN_ENGAGED_WITH_NPCS = 0x02000000, // Don't generate combat log when engaged with NPC's | UnitFlags2 0x2000000
    CREATURE_STATIC_FLAG_4_ALLOW_NPC_COMBAT_WHILE_UNINTERACTIBLE    = 0x04000000, // Allow NPC Combat while Uninteractible
    CREATURE_STATIC_FLAG_4_PREFER_NPCS_WHEN_SEARCHING_FOR_ENEMIES   = 0x08000000, // Prefer NPCs When Searching For Enemies
    CREATURE_STATIC_FLAG_4_ONLY_GENERATE_INITIAL_THREAT             = 0x10000000, // Only Generate Initial Threat
    CREATURE_STATIC_FLAG_4_DOESNT_CHANGE_TARGET_ON_RIGHT_CLICK      = 0x20000000, // Doesn't change target on right click | CREATURE_TYPE_FLAG_DO_NOT_TARGET_ON_INTERACTION
    CREATURE_STATIC_FLAG_4_HIDE_NAME_IN_WORLD_FRAME                 = 0x40000000, // Hide name in world frame | CREATURE_TYPE_FLAG_DO_NOT_RENDER_OBJECT_NAME
    CREATURE_STATIC_FLAG_4_QUEST_BOSS                               = 0x80000000  // Quest Boss | CREATURE_TYPE_FLAG_QUEST_BOSS
};

DEFINE_ENUM_FLAG(CreatureStaticFlags4);

enum CreatureStaticFlags5 : uint32
{
    CREATURE_STATIC_FLAG_5_UNTARGETABLE_BY_CLIENT                   = 0x00000001, // Untargetable By Client | UnitFlags2 0x4000000 UNIT_FLAG2_UNTARGETABLE_BY_CLIENT
    CREATURE_STATIC_FLAG_5_FORCE_SELF_MOUNTING                      = 0x00000002, // Force Self Mounting
    CREATURE_STATIC_FLAG_5_UNINTERACTIBLE_IF_HOSTILE                = 0x00000004, // Uninteractible If Hostile | UnitFlags2 0x10000000 UNIT_FLAG2_UNINTERACTIBLE_IF_HOSTILE
    CREATURE_STATIC_FLAG_5_DISABLES_XP_AWARD                        = 0x00000008, // Disables XP Award
    CREATURE_STATIC_FLAG_5_DISABLE_AI_PREDICTION                    = 0x00000010, // Disable AI prediction
    CREATURE_STATIC_FLAG_5_NO_LEAVE_COMBAT_STATE_RESTORE            = 0x00000020, // No LeaveCombat State Restore
    CREATURE_STATIC_FLAG_5_BYPASS_INTERACT_INTERRUPTS               = 0x00000040, // Bypass Interact Interrupts
    CREATURE_STATIC_FLAG_5_240_DEGREE_BACK_ARC                      = 0x00000080, // 240 Degree Back Arc
    CREATURE_STATIC_FLAG_5_INTERACT_WHILE_HOSTILE                   = 0x00000100, // Interact while Hostile | UnitFlags2 0x4000 UNIT_FLAG2_INTERACT_WHILE_HOSTILE
    CREATURE_STATIC_FLAG_5_DONT_DISMISS_ON_FLYING_MOUNT             = 0x00000200, // Don't Dismiss On Flying Mount
    CREATURE_STATIC_FLAG_5_PREDICTIVE_POWER_REGEN                   = 0x00000400, // Predictive Power Regen | CREATURE_TYPE_FLAG_2_PREDICTIVE_POWER_REGEN
    CREATURE_STATIC_FLAG_5_HIDE_LEVEL_INFO_IN_TOOLTIP               = 0x00000800, // Hide Level Info In Tooltip | CREATURE_TYPE_FLAG_2_HIDE_LEVEL_INFO_IN_TOOLTIP
    CREATURE_STATIC_FLAG_5_HIDE_HEALTH_BAR_UNDER_TOOLTIP            = 0x00001000, // Hide Health Bar Under Tooltip | CREATURE_TYPE_FLAG_2_HIDE_HEALTH_BAR_UNDER_TOOLTIP
    CREATURE_STATIC_FLAG_5_SUPPRESS_HIGHLIGHT_WHEN_TARGETED_OR_MOUSED_OVER = 0x00002000, // Suppress highlight when targeted or moused over | UnitFlags2 0x80000 UNIT_FLAG2_SUPPRESS_HIGHLIGHT_WHEN_TARGETED_OR_MOUSED_OVER
    CREATURE_STATIC_FLAG_5_AI_PREFER_PATHABLE_TARGETS               = 0x00004000, // AI Prefer pathable targets
    CREATURE_STATIC_FLAG_5_FREQUENT_AREA_TRIGGER_CHECKS             = 0x00008000, // Frequent Area Trigger Checks (EXPENSIVE/TALK TO A PROGRAMMER FIRST)
    CREATURE_STATIC_FLAG_5_ASSIGN_KILL_CREDIT_TO_ENCOUNTER_LIST     = 0x00010000, // Assign Kill Credit to Encounter List
    CREATURE_STATIC_FLAG_5_NEVER_EVADE                              = 0x00020000, // Never Evade
    CREATURE_STATIC_FLAG_5_AI_CANT_PATH_ON_STEEP_SLOPES             = 0x00040000, // AI Can't path on Steep Slopes
    CREATURE_STATIC_FLAG_5_AI_IGNORE_LOS_TO_MELEE_TARGET            = 0x00080000, // AI Ignore Los To Melee Target
    CREATURE_STATIC_FLAG_5_NEVER_DISPLAY_EMOTE_OR_CHAT_TEXT_IN_A_CHAT_BUBBLE = 0x00100000, // Never display emote or chat text in a chat bubble | CREATURE_TYPEFLAGS_2_UNK4
    CREATURE_STATIC_FLAG_5_AI_PETS_CLOSE_IN_ON_UNPATHABLE_TARGET    = 0x00200000, // AI Pets close in on unpathable target
    CREATURE_STATIC_FLAG_5_PET_OR_GUARDIAN_AI_DONT_GO_BEHIND_ME     = 0x00400000, // Pet/Guardian AI Don't Go Behind Me (use on target)
    CREATURE_STATIC_FLAG_5_NO_DEATH_THUD                            = 0x00800000, // No Death Thud | CREATURE_TYPE_FLAG_2_NO_DEATH_THUD
    CREATURE_STATIC_FLAG_5_CLIENT_LOCAL_CREATURE                    = 0x01000000, // Client Local Creature
    CREATURE_STATIC_FLAG_5_CAN_DROP_LOOT_WHILE_IN_A_CHALLENGE_MODE_INSTANCE = 0x02000000, // Can drop loot while in a challenge mode instance
    CREATURE_STATIC_FLAG_5_HAS_SAFE_LOCATION                        = 0x04000000, // Has Safe Location
    CREATURE_STATIC_FLAG_5_NO_HEALTH_REGEN                          = 0x08000000, // No Health Regen
    CREATURE_STATIC_FLAG_5_NO_POWER_REGEN                           = 0x10000000, // No Power Regen
    CREATURE_STATIC_FLAG_5_NO_PET_UNIT_FRAME                        = 0x20000000, // No Pet Unit Frame
    CREATURE_STATIC_FLAG_5_NO_INTERACT_ON_LEFT_CLICK                = 0x40000000, // No Interact On Left Click | CREATURE_TYPE_FLAG_2_NO_INTERACT_ON_LEFT_CLICK
    CREATURE_STATIC_FLAG_5_GIVE_CRITERIA_KILL_CREDIT_WHEN_CHARMED   = 0x80000000  // Give criteria kill credit when charmed
};

DEFINE_ENUM_FLAG(CreatureStaticFlags5);

enum CreatureStaticFlags6 : uint32
{
    CREATURE_STATIC_FLAG_6_DO_NOT_AUTO_RESUMMON_THIS_COMPANION_CREATURE = 0x00000001, // Do not auto-resummon this companion creature
    CREATURE_STATIC_FLAG_6_SMOOTH_PHASING_REPLACE_VISIBLE_UNIT_IF_AVAILABLE = 0x00000002, // Smooth Phasing: Replace visible unit if available (ASK PROGRAMMER FIRST)
    CREATURE_STATIC_FLAG_6_IGNORE_THE_REALM_COALESCING_HIDING_CODE  = 0x00000004, // Ignore the realm coalescing hiding code (always show)
    CREATURE_STATIC_FLAG_6_TAPS_TO_FACTION                          = 0x00000008, // Taps to Faction
    CREATURE_STATIC_FLAG_6_ONLY_QUEST_GIVER_FOR_SUMMONER            = 0x00000010, // Only QuestGiver for Summoner
    CREATURE_STATIC_FLAG_6_AI_COMBAT_RETURN_PRECISE                 = 0x00000020, // AI Combat Return Precise
    CREATURE_STATIC_FLAG_6_HOME_REALM_ONLY_LOOT                     = 0x00000040, // Home realm only loot
    CREATURE_STATIC_FLAG_6_NO_INTERACT_RESPONSE                     = 0x00000080, // No Interact Response | TFLAG2_UNK7
    CREATURE_STATIC_FLAG_6_NO_INITIAL_POWER                         = 0x00000100, // No Initial Power
    CREATURE_STATIC_FLAG_6_DONT_CANCEL_CHANNEL_ON_MASTER_MOUNTING   = 0x00000200, // Don't Cancel Channel On Master Mounting
    CREATURE_STATIC_FLAG_6_CAN_TOGGLE_BETWEEN_DEATH_AND_PERSONAL_LOOT = 0x00000400, // Can Toggle between Death and Personal Loot
    CREATURE_STATIC_FLAG_6_ALWAYS_STAND_ON_TARGET                   = 0x00000800, // Always, ALWAYS tries to stand right on top of his move to target. ALWAYS!!
    CREATURE_STATIC_FLAG_6_UNCONSCIOUS_ON_DEATH                     = 0x00001000, // Unconscious on Death
    CREATURE_STATIC_FLAG_6_DONT_REPORT_TO_LOCAL_DEFENSE_CHANNEL_ON_DEATH = 0x00002000, // Don't report to local defense channel on death
    CREATURE_STATIC_FLAG_6_PREFER_UNENGAGED_MONSTERS_WHEN_PICKING_A_TARGET = 0x00004000, // Prefer unengaged monsters when picking a target
    CREATURE_STATIC_FLAG_6_USE_PVP_POWER_AND_RESILIENCE_WHEN_PLAYERS_ATTACK_THIS_CREATURE = 0x00008000, // Use PVP power and resilience when players attack this creature
    CREATURE_STATIC_FLAG_6_DONT_CLEAR_DEBUFFS_ON_LEAVE_COMBAT       = 0x00010000, // Don't clear debuffs on leave combat
    CREATURE_STATIC_FLAG_6_PERSONAL_LOOT_HAS_FULL_SECURITY          = 0x00020000, // Personal loot has full security (guaranteed push/mail delivery)
    CREATURE_STATIC_FLAG_6_TRIPLE_SPELL_VISUALS                     = 0x00040000, // Triple Spell Visuals
    CREATURE_STATIC_FLAG_6_USE_GARRISON_OWNER_LEVEL                 = 0x00080000, // Use Garrison Owner Level
    CREATURE_STATIC_FLAG_6_IMMEDIATE_AOI_UPDATE_ON_SPAWN            = 0x00100000, // Immediate AOI Update On Spawn
    CREATURE_STATIC_FLAG_6_UI_CAN_GET_POSITION                      = 0x00200000, // UI Can Get Position
    CREATURE_STATIC_FLAG_6_SEAMLESS_TRANSFER_PROHIBITED             = 0x00400000, // Seamless Transfer Prohibited
    CREATURE_STATIC_FLAG_6_ALWAYS_USE_GROUP_LOOT_METHOD             = 0x00800000, // Always use Group Loot Method
    CREATURE_STATIC_FLAG_6_NO_BOSS_KILL_BANNER                      = 0x01000000, // No Boss Kill Banner
    CREATURE_STATIC_FLAG_6_FORCE_TRIGGERING_PLAYER_LOOT_ONLY        = 0x02000000, // Force Triggering Player Loot Only
    CREATURE_STATIC_FLAG_6_SHOW_BOSS_FRAME_WHILE_UNINTERACTABLE     = 0x04000000, // Show Boss Frame While Uninteractable
    CREATURE_STATIC_FLAG_6_SCALES_TO_PLAYER_LEVEL                   = 0x08000000, // Scales to Player Level
    CREATURE_STATIC_FLAG_6_AI_DONT_LEAVE_MELEE_FOR_RANGED_WHEN_TARGET_GETS_ROOTED = 0x10000000, // AI don't leave melee for ranged when target gets rooted
    CREATURE_STATIC_FLAG_6_DONT_USE_COMBAT_REACH_FOR_CHAINING       = 0x20000000, // Don't Use Combat Reach For Chaining
    CREATURE_STATIC_FLAG_6_DO_NOT_PLAY_PROCEDURAL_WOUND_ANIM        = 0x40000000, // Do not play procedural wound anim
    CREATURE_STATIC_FLAG_6_APPLY_PROCEDURAL_WOUND_ANIM_TO_BASE      = 0x80000000, // Apply procedural wound anim to Base | TFLAG2_UNK14
};

DEFINE_ENUM_FLAG(CreatureStaticFlags6);

enum CreatureStaticFlags7 : uint32
{
    CREATURE_STATIC_FLAG_7_IMPORTANT_NPC                            = 0x00000001, // Important NPC
    CREATURE_STATIC_FLAG_7_IMPORTANT_QUEST_NPC                      = 0x00000002, // Important Quest NPC
    CREATURE_STATIC_FLAG_7_LARGE_NAMEPLATE                          = 0x00000004, // Large Nameplate
    CREATURE_STATIC_FLAG_7_TRIVIAL_PET                              = 0x00000008, // Trivial Pet (Ignored by helpful AOEs)
    CREATURE_STATIC_FLAG_7_AI_ENEMIES_DONT_BACKUP_WHEN_I_GET_ROOTED = 0x00000010, // AI Enemies Don't backup when I get rooted
    CREATURE_STATIC_FLAG_7_NO_AUTOMATIC_COMBAT_ANCHOR               = 0x00000020, // No Automatic Combat Anchor
    CREATURE_STATIC_FLAG_7_ONLY_TARGETABLE_BY_CREATOR               = 0x00000040, // Only Targetable By Creator
    CREATURE_STATIC_FLAG_7_TREAT_AS_PLAYER_FOR_IS_PLAYER_CONTROLLED = 0x00000080, // 8.0.1 Flag - Treat as Player for IsPlayerControlled()
    CREATURE_STATIC_FLAG_7_GENERATE_NO_THREAT_OR_DAMAGE             = 0x00000100, // 8.0.1 Flag - Generate No Threat or Damage
    CREATURE_STATIC_FLAG_7_INTERACT_ONLY_ON_QUEST                   = 0x00000200, // 8.0.1 Flag - Interact Only on Quest
    CREATURE_STATIC_FLAG_7_DISABLE_KILL_CREDIT_FOR_OFFLINE_PLAYERS  = 0x00000400, // Disable Kill Credit for Offline Players
    CREATURE_STATIC_FLAG_7_AI_ADDITIONAL_PATHING                    = 0x00080000, // AI Additional Pathing
};

DEFINE_ENUM_FLAG(CreatureStaticFlags7);

enum CreatureStaticFlags8 : uint32
{
    CREATURE_STATIC_FLAG_8_FORCE_CLOSE_IN_ON_PATH_FAIL_BEHAVIOR     = 0x00000002, // Force Close In On Path Fail Behavior
    CREATURE_STATIC_FLAG_8_USE_2D_CHASING_CALCULATION               = 0x00000020, // Use 2D Chasing Calculation
    CREATURE_STATIC_FLAG_8_USE_FAST_CLASSIC_HEARTBEAT               = 0x00000040, // Use Fast Classic Heartbeat
};

DEFINE_ENUM_FLAG(CreatureStaticFlags8);

class CreatureStaticFlagsHolder
{
public:
    explicit CreatureStaticFlagsHolder(CreatureStaticFlags flags = CreatureStaticFlags(), CreatureStaticFlags2 flags2 = CreatureStaticFlags2(),
        CreatureStaticFlags3 flags3 = CreatureStaticFlags3(), CreatureStaticFlags4 flags4 = CreatureStaticFlags4(),
        CreatureStaticFlags5 flags5 = CreatureStaticFlags5(), CreatureStaticFlags6 flags6 = CreatureStaticFlags6(),
        CreatureStaticFlags7 flags7 = CreatureStaticFlags7(), CreatureStaticFlags8 flags8 = CreatureStaticFlags8())
            : _flags(flags), _flags2(flags2), _flags3(flags3), _flags4(flags4), _flags5(flags5), _flags6(flags6), _flags7(flags7), _flags8(flags8)
    {
    }

    bool HasFlag(CreatureStaticFlags flag) const { return _flags.HasFlag(flag); }
    bool HasFlag(CreatureStaticFlags2 flag) const { return _flags2.HasFlag(flag); }
    bool HasFlag(CreatureStaticFlags3 flag) const { return _flags3.HasFlag(flag); }
    bool HasFlag(CreatureStaticFlags4 flag) const { return _flags4.HasFlag(flag); }
    bool HasFlag(CreatureStaticFlags5 flag) const { return _flags5.HasFlag(flag); }
    bool HasFlag(CreatureStaticFlags6 flag) const { return _flags6.HasFlag(flag); }
    bool HasFlag(CreatureStaticFlags7 flag) const { return _flags7.HasFlag(flag); }
    bool HasFlag(CreatureStaticFlags8 flag) const { return _flags8.HasFlag(flag); }

    void ApplyFlag(CreatureStaticFlags flag, bool apply) { if (apply) _flags |= flag; else _flags &= ~flag; }
    void ApplyFlag(CreatureStaticFlags2 flag, bool apply) { if (apply) _flags2 |= flag; else _flags2 &= ~flag; }
    void ApplyFlag(CreatureStaticFlags3 flag, bool apply) { if (apply) _flags3 |= flag; else _flags3 &= ~flag; }
    void ApplyFlag(CreatureStaticFlags4 flag, bool apply) { if (apply) _flags4 |= flag; else _flags4 &= ~flag; }
    void ApplyFlag(CreatureStaticFlags5 flag, bool apply) { if (apply) _flags5 |= flag; else _flags5 &= ~flag; }
    void ApplyFlag(CreatureStaticFlags6 flag, bool apply) { if (apply) _flags6 |= flag; else _flags6 &= ~flag; }
    void ApplyFlag(CreatureStaticFlags7 flag, bool apply) { if (apply) _flags7 |= flag; else _flags7 &= ~flag; }
    void ApplyFlag(CreatureStaticFlags8 flag, bool apply) { if (apply) _flags8 |= flag; else _flags8 &= ~flag; }

    EnumFlag<CreatureStaticFlags> GetFlags() const { return _flags; }
    EnumFlag<CreatureStaticFlags2> GetFlags2() const { return _flags2; }
    EnumFlag<CreatureStaticFlags3> GetFlags3() const { return _flags3; }
    EnumFlag<CreatureStaticFlags4> GetFlags4() const { return _flags4; }
    EnumFlag<CreatureStaticFlags5> GetFlags5() const { return _flags5; }
    EnumFlag<CreatureStaticFlags6> GetFlags6() const { return _flags6; }
    EnumFlag<CreatureStaticFlags7> GetFlags7() const { return _flags7; }
    EnumFlag<CreatureStaticFlags8> GetFlags8() const { return _flags8; }

private:
    EnumFlag<CreatureStaticFlags> _flags;
    EnumFlag<CreatureStaticFlags2> _flags2;
    EnumFlag<CreatureStaticFlags3> _flags3;
    EnumFlag<CreatureStaticFlags4> _flags4;
    EnumFlag<CreatureStaticFlags5> _flags5;
    EnumFlag<CreatureStaticFlags6> _flags6;
    EnumFlag<CreatureStaticFlags7> _flags7;
    EnumFlag<CreatureStaticFlags8> _flags8;
};

// EnumUtils: DESCRIBE THIS
enum CreatureFlagsExtra : uint32
{
    CREATURE_FLAG_EXTRA_INSTANCE_BIND        = 0x00000001,       // creature kill bind instance with killer and killer's group
    CREATURE_FLAG_EXTRA_CIVILIAN             = 0x00000002,       // not aggro (ignore faction/reputation hostility)
    CREATURE_FLAG_EXTRA_NO_PARRY             = 0x00000004,       // creature can't parry
    CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN      = 0x00000008,       // creature can't counter-attack at parry
    CREATURE_FLAG_EXTRA_NO_BLOCK             = 0x00000010,       // creature can't block
    CREATURE_FLAG_EXTRA_NO_CRUSHING_BLOWS    = 0x00000020,       // creature can't do crush attacks
    CREATURE_FLAG_EXTRA_NO_XP                = 0x00000040,       // creature kill does not provide XP
    CREATURE_FLAG_EXTRA_TRIGGER              = 0x00000080,       // trigger creature
    CREATURE_FLAG_EXTRA_NO_TAUNT             = 0x00000100,       // creature is immune to taunt auras and 'attack me' effects
    CREATURE_FLAG_EXTRA_UNUSED_9             = 0x00000200,
    CREATURE_FLAG_EXTRA_GHOST_VISIBILITY     = 0x00000400,       // creature will only be visible to dead players
    CREATURE_FLAG_EXTRA_USE_OFFHAND_ATTACK   = 0x00000800,       // creature will use offhand attacks
    CREATURE_FLAG_EXTRA_NO_SELL_VENDOR       = 0x00001000,       // players can't sell items to this vendor
    CREATURE_FLAG_EXTRA_CANNOT_ENTER_COMBAT  = 0x00002000,       // creature is not allowed to enter combat
    CREATURE_FLAG_EXTRA_WORLDEVENT           = 0x00004000,       // custom flag for world event creatures (left room for merging)
    CREATURE_FLAG_EXTRA_GUARD                = 0x00008000,       // Creature is guard
    CREATURE_FLAG_EXTRA_IGNORE_FEIGN_DEATH   = 0x00010000,       // creature ignores feign death
    CREATURE_FLAG_EXTRA_NO_CRIT              = 0x00020000,       // creature can't do critical strikes
    CREATURE_FLAG_EXTRA_NO_SKILL_GAINS       = 0x00040000,       // creature won't increase weapon skills
    CREATURE_FLAG_EXTRA_OBEYS_TAUNT_DIMINISHING_RETURNS = 0x00080000,       // Taunt is subject to diminishing returns on this creature
    CREATURE_FLAG_EXTRA_ALL_DIMINISH         = 0x00100000,       // creature is subject to all diminishing returns as players are
    CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ = 0x00200000,       // creature does not need to take player damage for kill credit
    CREATURE_FLAG_EXTRA_UNUSED_22            = 0x00400000,
    CREATURE_FLAG_EXTRA_UNUSED_23            = 0x00800000,
    CREATURE_FLAG_EXTRA_UNUSED_24            = 0x01000000,
    CREATURE_FLAG_EXTRA_UNUSED_25            = 0x02000000,
    CREATURE_FLAG_EXTRA_UNUSED_26            = 0x04000000,
    CREATURE_FLAG_EXTRA_UNUSED_27            = 0x08000000,
    CREATURE_FLAG_EXTRA_DUNGEON_BOSS         = 0x10000000,       // creature is a dungeon boss
    CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING   = 0x20000000,       // creature ignore pathfinding
    CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK   = 0x40000000,       // creature is immune to knockback effects
    CREATURE_FLAG_EXTRA_UNUSED_31            = 0x80000000,

    // Masks
    CREATURE_FLAG_EXTRA_UNUSED               = (CREATURE_FLAG_EXTRA_UNUSED_22 |
                                                CREATURE_FLAG_EXTRA_UNUSED_23 | CREATURE_FLAG_EXTRA_UNUSED_24 | CREATURE_FLAG_EXTRA_UNUSED_25 |
                                                CREATURE_FLAG_EXTRA_UNUSED_26 | CREATURE_FLAG_EXTRA_UNUSED_27 | CREATURE_FLAG_EXTRA_UNUSED_31), // SKIP

    CREATURE_FLAG_EXTRA_DB_ALLOWED           = (0xFFFFFFFF & ~(CREATURE_FLAG_EXTRA_UNUSED | CREATURE_FLAG_EXTRA_DUNGEON_BOSS)) // SKIP
};

enum class CreatureChaseMovementType : uint8
{
    Run,
    CanWalk,
    AlwaysWalk,

    Max
};

enum class CreatureRandomMovementType : uint8
{
    Walk,
    CanRun,
    AlwaysRun,

    Max
};

struct TC_GAME_API CreatureMovementData
{
    CreatureMovementData();

    bool HoverInitiallyEnabled;
    CreatureChaseMovementType Chase;
    CreatureRandomMovementType Random;
    uint32 InteractionPauseTimer;

    CreatureChaseMovementType GetChase() const { return Chase; }
    CreatureRandomMovementType GetRandom() const { return Random; }

    bool IsHoverInitiallyEnabled() const { return HoverInitiallyEnabled; }

    uint32 GetInteractionPauseTimer() const { return InteractionPauseTimer; }

    std::string ToString() const;
};

const uint32 CREATURE_REGEN_INTERVAL = 2 * IN_MILLISECONDS;
const uint32 PET_FOCUS_REGEN_INTERVAL = 4 * IN_MILLISECONDS;
const uint32 CREATURE_NOPATH_EVADE_TIME = 5 * IN_MILLISECONDS;

const uint8 MAX_KILL_CREDIT = 2;
const uint32 MAX_CREATURE_MODELS = 4;
const uint32 MAX_CREATURE_NAMES = 4;
const uint32 MAX_CREATURE_SPELLS = 8;

struct CreatureModel
{
    static CreatureModel const DefaultInvisibleModel;
    static CreatureModel const DefaultVisibleModel;

    CreatureModel() :
        CreatureDisplayID(0), DisplayScale(0.0f), Probability(0.0f) { }

    CreatureModel(uint32 creatureDisplayID, float displayScale, float probability) :
        CreatureDisplayID(creatureDisplayID), DisplayScale(displayScale), Probability(probability) { }

    uint32 CreatureDisplayID;
    float DisplayScale;
    float Probability;
};

struct CreatureDifficulty
{
    int16 DeltaLevelMin;
    int16 DeltaLevelMax;
    int32 ContentTuningID;
    int32 HealthScalingExpansion;
    float HealthModifier;
    float ManaModifier;
    float ArmorModifier;
    float DamageModifier;
    int32 CreatureDifficultyID;
    uint32 TypeFlags;
    uint32 TypeFlags2;
    uint32 TypeFlags3;
    uint32 LootID;
    uint32 PickPocketLootID;
    uint32 SkinLootID;
    uint32 GoldMin;
    uint32 GoldMax;

    CreatureStaticFlagsHolder StaticFlags;

    // Helpers
    int32 GetHealthScalingExpansion() const
    {
        return HealthScalingExpansion == EXPANSION_LEVEL_CURRENT ? CURRENT_EXPANSION : HealthScalingExpansion;
    }

    SkillType GetRequiredLootSkill() const
    {
        if (TypeFlags & CREATURE_TYPE_FLAG_SKIN_WITH_HERBALISM)
            return SKILL_HERBALISM;
        else if (TypeFlags & CREATURE_TYPE_FLAG_SKIN_WITH_MINING)
            return SKILL_MINING;
        else if (TypeFlags & CREATURE_TYPE_FLAG_SKIN_WITH_ENGINEERING)
            return SKILL_ENGINEERING;
        else
            return SKILL_SKINNING; // Default case
    }
};

// from `creature_template` table
struct TC_GAME_API CreatureTemplate
{
    uint32  Entry;
    uint32  KillCredit[MAX_KILL_CREDIT];
    std::vector<CreatureModel> Models;
    std::string  Name;
    std::string FemaleName;
    std::string  SubName;
    std::string  TitleAlt;
    std::string  IconName;
    std::vector<uint32> GossipMenuIds;
    std::unordered_map<Difficulty, CreatureDifficulty> difficultyStore;
    uint32  RequiredExpansion;
    uint32  VignetteID;
    uint32  faction;
    uint64  npcflag;
    float   speed_walk;
    float   speed_run;
    float   scale;
    CreatureClassifications  Classification;
    uint32  dmgschool;
    uint32  BaseAttackTime;
    uint32  RangeAttackTime;
    float   BaseVariance;
    float   RangeVariance;
    uint32  unit_class;                                     // enum Classes. Note only 4 classes are known for creatures.
    uint32  unit_flags;                                     // enum UnitFlags mask values
    uint32  unit_flags2;                                    // enum UnitFlags2 mask values
    uint32  unit_flags3;                                    // enum UnitFlags3 mask values
    CreatureFamily  family;                                 // enum CreatureFamily values (optional)
    uint32  trainer_class;
    uint32  type;                                           // enum CreatureType values
    int32   resistance[MAX_SPELL_SCHOOL];
    uint32  spells[MAX_CREATURE_SPELLS];
    uint32  VehicleId;
    std::string AIName;
    uint32  MovementType;
    CreatureMovementData Movement;
    float   ModExperience;
    bool    RacialLeader;
    uint32  movementId;
    int32   WidgetSetID;
    int32   WidgetSetUnitConditionID;
    bool    RegenHealth;
    int32   CreatureImmunitiesId;
    uint32  flags_extra;
    uint32  ScriptID;
    std::string StringId;
    WorldPacket QueryData[TOTAL_LOCALES];
    CreatureModel const* GetModelByIdx(uint32 idx) const;
    CreatureModel const* GetRandomValidModel() const;
    CreatureModel const* GetFirstValidModel() const;
    CreatureModel const* GetModelWithDisplayId(uint32 displayId) const;
    CreatureModel const* GetFirstInvisibleModel() const;
    CreatureModel const* GetFirstVisibleModel() const;
    CreatureDifficulty const* GetDifficulty(Difficulty difficulty) const;

    // Helpers
    bool IsExotic(CreatureDifficulty const* creatureDifficulty) const
    {
        return (creatureDifficulty->TypeFlags & CREATURE_TYPE_FLAG_TAMEABLE_EXOTIC) != 0;
    }

    bool IsTameable(bool canTameExotic, CreatureDifficulty const* creatureDifficulty) const
    {
        if (type != CREATURE_TYPE_BEAST || family == CREATURE_FAMILY_NONE || (creatureDifficulty->TypeFlags & CREATURE_TYPE_FLAG_TAMEABLE) == 0)
            return false;

        // if can tame exotic then can tame any tameable
        return canTameExotic || !IsExotic(creatureDifficulty);
    }

    void InitializeQueryData();
    WorldPacket BuildQueryData(LocaleConstant loc, Difficulty difficulty) const;

    CreatureTemplate();
    CreatureTemplate(CreatureTemplate const& other) = delete;
    CreatureTemplate(CreatureTemplate&& other) noexcept;
    CreatureTemplate& operator=(CreatureTemplate const& other) = delete;
    CreatureTemplate& operator=(CreatureTemplate&& other) noexcept;
    ~CreatureTemplate();
};

// Defines base stats for creatures (used to calculate HP/mana/armor/attackpower/rangedattackpower/all damage).
struct TC_GAME_API CreatureBaseStats
{
    uint32 BaseMana;
    uint32 AttackPower;
    uint32 RangedAttackPower;

    // Helpers
    static CreatureBaseStats const* GetBaseStats(uint8 level, uint8 unitClass);
};

struct CreatureLocale
{
    std::vector<std::string> Name;
    std::vector<std::string> NameAlt;
    std::vector<std::string> Title;
    std::vector<std::string> TitleAlt;
};

struct EquipmentItem
{
    uint32 ItemId = 0;
    uint16 AppearanceModId = 0;
    uint16 ItemVisual = 0;
};

struct EquipmentInfo
{
    EquipmentItem Items[MAX_EQUIPMENT_ITEMS];
};

// from `creature` table
struct CreatureData : public SpawnData
{
    CreatureData() : SpawnData(SPAWN_TYPE_CREATURE) { }
    Optional<CreatureModel> display;
    int8 equipmentId = 0;
    float wander_distance = 0.0f;
    uint32 currentwaypoint = 0;
    uint32 curHealthPct = 0;
    uint8 movementType = 0;
    Optional<uint64> npcflag;
    Optional<uint32> unit_flags;                                  // enum UnitFlags mask values
    Optional<uint32> unit_flags2;                                 // enum UnitFlags2 mask values
    Optional<uint32> unit_flags3;                                 // enum UnitFlags3 mask values
};

struct CreatureModelInfo
{
    float bounding_radius;
    float combat_reach;
    int8 gender;
    uint32 displayId_other_gender;
    bool is_trigger;
};

struct CreatureSummonedData
{
    Optional<uint32> CreatureIDVisibleToSummoner;
    Optional<uint32> GroundMountDisplayID;
    Optional<uint32> FlyingMountDisplayID;
    Optional<std::vector<uint32>> DespawnOnQuestsRemoved;
};

// `creature_addon` table
struct CreatureAddon
{
    uint32 PathId;
    uint32 mount;
    uint8 standState;
    uint8 animTier;
    uint8 sheathState;
    uint8 pvpFlags;
    uint8 visFlags;
    uint32 emote;
    uint16 aiAnimKit;
    uint16 movementAnimKit;
    uint16 meleeAnimKit;
    std::vector<uint32> auras;
    VisibilityDistanceType visibilityDistanceType;
};

// `creature_static_flags_override` table
struct CreatureStaticFlagsOverride
{
    Optional<CreatureStaticFlags> StaticFlags1;
    Optional<CreatureStaticFlags2> StaticFlags2;
    Optional<CreatureStaticFlags3> StaticFlags3;
    Optional<CreatureStaticFlags4> StaticFlags4;
    Optional<CreatureStaticFlags5> StaticFlags5;
    Optional<CreatureStaticFlags6> StaticFlags6;
    Optional<CreatureStaticFlags7> StaticFlags7;
    Optional<CreatureStaticFlags8> StaticFlags8;
};

// Vendors
struct VendorItem
{
    VendorItem() : item(0), maxcount(0), incrtime(0), ExtendedCost(0), Type(0), PlayerConditionId(0), IgnoreFiltering(false) { }

    uint32 item;
    uint32 maxcount;                                        // 0 for infinity item amount
    uint32 incrtime;                                        // time for restore items amount if maxcount != 0
    uint32 ExtendedCost;
    uint8  Type;
    std::vector<int32> BonusListIDs;
    uint32 PlayerConditionId;
    bool IgnoreFiltering;
};

struct VendorItemData
{
    std::vector<VendorItem> m_items;

    VendorItem const* GetItem(uint32 slot) const
    {
        if (slot >= m_items.size())
            return nullptr;

        return &m_items[slot];
    }
    bool Empty() const { return m_items.empty(); }
    uint32 GetItemCount() const { return uint32(m_items.size()); }
    void AddItem(VendorItem vItem)
    {
        m_items.emplace_back(std::move(vItem));
    }
    bool RemoveItem(uint32 item_id, uint8 type);
    VendorItem const* FindItemCostPair(uint32 item_id, uint32 extendedCost, uint8 type) const;
    void Clear()
    {
        m_items.clear();
    }
};

#endif // CreatureData_h__
