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

#include "DBCEnums.h"
#include "EnumFlag.h"
#include "SharedDefines.h"
#include "SpawnData.h"
#include "UnitDefines.h"
#include "WorldPacket.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <cmath>

class Spell;
class WorldPacket;
struct ItemTemplate;
enum class VisibilityDistanceType : uint8;

enum CreatureFlagsExtra : uint32
{
    CREATURE_FLAG_EXTRA_INSTANCE_BIND        = 0x00000001,       // creature kill bind instance with killer and killer's group
    CREATURE_FLAG_EXTRA_CIVILIAN             = 0x00000002,       // not aggro (ignore faction/reputation hostility)
    CREATURE_FLAG_EXTRA_NO_PARRY             = 0x00000004,       // creature can't parry
    CREATURE_FLAG_EXTRA_NO_PARRY_HASTEN      = 0x00000008,       // creature can't counter-attack at parry
    CREATURE_FLAG_EXTRA_NO_BLOCK             = 0x00000010,       // creature can't block
    CREATURE_FLAG_EXTRA_NO_CRUSH             = 0x00000020,       // creature can't do crush attacks
    CREATURE_FLAG_EXTRA_NO_XP_AT_KILL        = 0x00000040,       // creature kill not provide XP
    CREATURE_FLAG_EXTRA_TRIGGER              = 0x00000080,       // trigger creature
    CREATURE_FLAG_EXTRA_NO_TAUNT             = 0x00000100,       // creature is immune to taunt auras and effect attack me
    CREATURE_FLAG_EXTRA_NO_MOVE_FLAGS_UPDATE = 0x00000200,       // creature won't update movement flags
    CREATURE_FLAG_EXTRA_GHOST_VISIBILITY     = 0x00000400,       // creature will be only visible for dead players
    CREATURE_FLAG_EXTRA_USE_OFFHAND_ATTACK   = 0x00000800,       // creature will use offhand attacks
    CREATURE_FLAG_EXTRA_NO_SELL_VENDOR       = 0x00001000,       // players can't sell items to this vendor
    CREATURE_FLAG_EXTRA_NO_COMBAT            = 0x00002000,       // creature is not allowed to enter combat
    CREATURE_FLAG_EXTRA_WORLDEVENT           = 0x00004000,       // custom flag for world event creatures (left room for merging)
    CREATURE_FLAG_EXTRA_GUARD                = 0x00008000,       // Creature is guard
    CREATURE_FLAG_EXTRA_UNUSED_16            = 0x00010000,
    CREATURE_FLAG_EXTRA_NO_CRIT              = 0x00020000,       // creature can't do critical strikes
    CREATURE_FLAG_EXTRA_NO_SKILLGAIN         = 0x00040000,       // creature won't increase weapon skills
    CREATURE_FLAG_EXTRA_TAUNT_DIMINISH       = 0x00080000,       // Taunt is a subject to diminishing returns on this creautre
    CREATURE_FLAG_EXTRA_ALL_DIMINISH         = 0x00100000,       // creature is subject to all diminishing returns as player are
    CREATURE_FLAG_EXTRA_NO_PLAYER_DAMAGE_REQ = 0x00200000,       // creature does not need to take player damage for kill credit
    CREATURE_FLAG_EXTRA_UNUSED_22            = 0x00400000,
    CREATURE_FLAG_EXTRA_UNUSED_23            = 0x00800000,
    CREATURE_FLAG_EXTRA_UNUSED_24            = 0x01000000,
    CREATURE_FLAG_EXTRA_UNUSED_25            = 0x02000000,
    CREATURE_FLAG_EXTRA_UNUSED_26            = 0x04000000,
    CREATURE_FLAG_EXTRA_UNUSED_27            = 0x08000000,
    CREATURE_FLAG_EXTRA_DUNGEON_BOSS         = 0x10000000,       // creature is a dungeon boss (SET DYNAMICALLY, DO NOT ADD IN DB)
    CREATURE_FLAG_EXTRA_IGNORE_PATHFINDING   = 0x20000000,       // creature ignore pathfinding
    CREATURE_FLAG_EXTRA_IMMUNITY_KNOCKBACK   = 0x40000000,       // creature is immune to knockback effects
    CREATURE_FLAG_EXTRA_UNUSED_31            = 0x80000000,

    // Masks
    CREATURE_FLAG_EXTRA_UNUSED               = (CREATURE_FLAG_EXTRA_UNUSED_16 | CREATURE_FLAG_EXTRA_UNUSED_22 |
                                                CREATURE_FLAG_EXTRA_UNUSED_23 | CREATURE_FLAG_EXTRA_UNUSED_24 | CREATURE_FLAG_EXTRA_UNUSED_25 |
                                                CREATURE_FLAG_EXTRA_UNUSED_26 | CREATURE_FLAG_EXTRA_UNUSED_27 | CREATURE_FLAG_EXTRA_UNUSED_31),

    CREATURE_FLAG_EXTRA_DB_ALLOWED           = (0xFFFFFFFF & ~(CREATURE_FLAG_EXTRA_UNUSED | CREATURE_FLAG_EXTRA_DUNGEON_BOSS))
};

enum CreatureStaticFlags
{
    CREATURE_STATIC_FLAG_MOUNTABLE                         = 0x00000001,
    CREATURE_STATIC_FLAG_NO_XP                             = 0x00000002, // CREATURE_FLAG_EXTRA_NO_XP
    CREATURE_STATIC_FLAG_NO_LOOT                           = 0x00000004,
    CREATURE_STATIC_FLAG_UNKILLABLE                        = 0x00000008,
    CREATURE_STATIC_FLAG_TAMEABLE                          = 0x00000010, // CREATURE_TYPE_FLAG_TAMEABLE
    CREATURE_STATIC_FLAG_IMMUNE_TO_PC                      = 0x00000020, // UNIT_FLAG_IMMUNE_TO_PC
    CREATURE_STATIC_FLAG_IMMUNE_TO_NPC                     = 0x00000040, // UNIT_FLAG_IMMUNE_TO_NPC
    CREATURE_STATIC_FLAG_CAN_WIELD_LOOT                    = 0x00000080,
    CREATURE_STATIC_FLAG_SESSILE                           = 0x00000100, // creature_template_movement.Rooted = 1
    CREATURE_STATIC_FLAG_UNINTERACTIBLE                    = 0x00000200, // UNIT_FLAG_UNINTERACTIBLE
    CREATURE_STATIC_FLAG_NO_AUTOMATIC_REGEN                = 0x00000400, // Creatures with that flag uses no UNIT_FLAG2_REGENERATE_POWER
    CREATURE_STATIC_FLAG_DESPAWN_INSTANTLY                 = 0x00000800, // Creature instantly disappear when killed
    CREATURE_STATIC_FLAG_CORPSE_RAID                       = 0x00001000,
    CREATURE_STATIC_FLAG_CREATOR_LOOT                      = 0x00002000, // Lootable only by creator(engineering dummies)
    CREATURE_STATIC_FLAG_NO_DEFENSE                        = 0x00004000,
    CREATURE_STATIC_FLAG_NO_SPELL_DEFENSE                  = 0x00008000,
    CREATURE_STATIC_FLAG_BOSS_MOB                          = 0x00010000, // CREATURE_TYPE_FLAG_BOSS_MOB, original description: Raid Boss Mob
    CREATURE_STATIC_FLAG_COMBAT_PING                       = 0x00020000,
    CREATURE_STATIC_FLAG_AQUATIC                           = 0x00040000, // aka Water Only, creature_template_movement.Ground = 0
    CREATURE_STATIC_FLAG_AMPHIBIOUS                        = 0x00080000, // creature_template_movement.Swim = 1
    CREATURE_STATIC_FLAG_NO_MELEE                          = 0x00100000, // "No Melee (Flee)" Prevents melee(does not prevent chasing, does not make creature passive). Not sure what 'Flee' means but another flag is named NO_MELEE_APPROACH
    CREATURE_STATIC_FLAG_VISIBLE_TO_GHOSTS                 = 0x00200000, // CREATURE_TYPE_FLAG_VISIBLE_TO_GHOSTS
    CREATURE_STATIC_FLAG_PVP_ENABLING                      = 0x00400000, // Old UNIT_FLAG_PVP_ENABLING, now UNIT_BYTES_2_OFFSET_PVP_FLAG from UNIT_FIELD_BYTES_2
    CREATURE_STATIC_FLAG_DO_NOT_PLAY_WOUND_ANIM            = 0x00800000, // CREATURE_TYPE_FLAG_DO_NOT_PLAY_WOUND_ANIM
    CREATURE_STATIC_FLAG_NO_FACTION_TOOLTIP                = 0x01000000, // CREATURE_TYPE_FLAG_NO_FACTION_TOOLTIP
    CREATURE_STATIC_FLAG_IGNORE_COMBAT                     = 0x02000000, // Actually only changes react state to passive
    CREATURE_STATIC_FLAG_ONLY_ATTACK_PVP_ENABLING          = 0x04000000, // "Only attack targets that are PvP enabling"
    CREATURE_STATIC_FLAG_CALLS_GUARDS                      = 0x08000000, // Creature will summon a guard if player is within its aggro range (even if creature doesn't attack per se)
    CREATURE_STATIC_FLAG_CAN_SWIM                          = 0x10000000, // UnitFlags 0x8000 UNIT_FLAG_CAN_SWIM
    CREATURE_STATIC_FLAG_FLOATING                          = 0x20000000, // creature_template_movement.Flight = 1
    CREATURE_STATIC_FLAG_MORE_AUDIBLE                      = 0x40000000, // CREATURE_TYPE_FLAG_MORE_AUDIBLE
    CREATURE_STATIC_FLAG_LARGE_AOI                         = 0x80000000  // UnitFlags2 0x200000
};

DEFINE_ENUM_FLAG(CreatureStaticFlags);

enum CreatureStaticFlags2
{
    CREATURE_STATIC_FLAG_2_NO_PET_SCALING                  = 0x00000001,
    CREATURE_STATIC_FLAG_2_FORCE_PARTY_MEMBERS_INTO_COMBAT = 0x00000002, // Original description: Force Raid Combat
    CREATURE_STATIC_FLAG_2_LOCK_TAPPERS_TO_RAID_ON_DEATH   = 0x00000004, // "Lock Tappers To Raid On Death", toggleable by 'Set "RAID_LOCK_ON_DEATH" flag for unit(s)' action, CREATURE_FLAG_EXTRA_INSTANCE_BIND
    CREATURE_STATIC_FLAG_2_SPELL_ATTACKABLE                = 0x00000008, // CREATURE_TYPE_FLAG_SPELL_ATTACKABLE, original description(not valid anymore?): No Harmful Vertex Coloring
    CREATURE_STATIC_FLAG_2_NO_CRUSHING_BLOWS               = 0x00000010, // CREATURE_FLAG_EXTRA_NO_CRUSHING_BLOWS
    CREATURE_STATIC_FLAG_2_NO_OWNER_THREAT                 = 0x00000020,
    CREATURE_STATIC_FLAG_2_NO_WOUNDED_SLOWDOWN             = 0x00000040,
    CREATURE_STATIC_FLAG_2_USE_CREATOR_BONUSES             = 0x00000080,
    CREATURE_STATIC_FLAG_2_IGNORE_FEIGN_DEATH              = 0x00000100, // CREATURE_FLAG_EXTRA_IGNORE_FEIGN_DEATH
    CREATURE_STATIC_FLAG_2_IGNORE_SANCTUARY                = 0x00000200,
    CREATURE_STATIC_FLAG_2_ACTION_TRIGGERS_WHILE_CHARMED   = 0x00000400,
    CREATURE_STATIC_FLAG_2_INTERACT_WHILE_DEAD             = 0x00000800, // CREATURE_TYPE_FLAG_INTERACT_WHILE_DEAD
    CREATURE_STATIC_FLAG_2_NO_INTERRUPT_SCHOOL_COOLDOWN    = 0x00001000,
    CREATURE_STATIC_FLAG_2_RETURN_SOUL_SHARD_TO_MASTER_OF_PET = 0x00002000,
    CREATURE_STATIC_FLAG_2_SKIN_WITH_HERBALISM             = 0x00004000, // CREATURE_TYPE_FLAG_SKIN_WITH_HERBALISM
    CREATURE_STATIC_FLAG_2_SKIN_WITH_MINING                = 0x00008000, // CREATURE_TYPE_FLAG_SKIN_WITH_MINING
    CREATURE_STATIC_FLAG_2_ALERT_CONTENT_TEAM_ON_DEATH     = 0x00010000,
    CREATURE_STATIC_FLAG_2_ALERT_CONTENT_TEAM_AT_90_PCT_HP = 0x00020000,
    CREATURE_STATIC_FLAG_2_ALLOW_MOUNTED_COMBAT            = 0x00040000, // CREATURE_TYPE_FLAG_ALLOW_MOUNTED_COMBAT
    CREATURE_STATIC_FLAG_2_PVP_ENABLING_OOC                = 0x00080000,
    CREATURE_STATIC_FLAG_2_NO_DEATH_MESSAGE                = 0x00100000, // CREATURE_TYPE_FLAG_NO_DEATH_MESSAGE
    CREATURE_STATIC_FLAG_2_IGNORE_PATHING_FAILURE          = 0x00200000,
    CREATURE_STATIC_FLAG_2_FULL_SPELL_LIST                 = 0x00400000,
    CREATURE_STATIC_FLAG_2_DOES_NOT_REDUCE_REPUTATION_FOR_RAIDS = 0x00800000,
    CREATURE_STATIC_FLAG_2_IGNORE_MISDIRECTION             = 0x01000000,
    CREATURE_STATIC_FLAG_2_HIDE_BODY                       = 0x02000000, // UNIT_FLAG2_HIDE_BODY
    CREATURE_STATIC_FLAG_2_SPAWN_DEFENSIVE                 = 0x04000000,
    CREATURE_STATIC_FLAG_2_SERVER_ONLY                     = 0x08000000,
    CREATURE_STATIC_FLAG_2_CAN_SAFE_FALL                   = 0x10000000, // Original description: No Collision
    CREATURE_STATIC_FLAG_2_CAN_ASSIST                      = 0x20000000, // CREATURE_TYPE_FLAG_CAN_ASSIST, original description: Player Can Heal/Buff
    CREATURE_STATIC_FLAG_2_NO_SKILL_GAINS                  = 0x40000000, // CREATURE_FLAG_EXTRA_NO_SKILL_GAINS
    CREATURE_STATIC_FLAG_2_NO_PET_BAR                      = 0x80000000  // CREATURE_TYPE_FLAG_NO_PET_BAR
};

DEFINE_ENUM_FLAG(CreatureStaticFlags2);

enum CreatureStaticFlags3
{
    CREATURE_STATIC_FLAG_3_NO_DAMAGE_HISTORY              = 0x00000001,
    CREATURE_STATIC_FLAG_3_DONT_PVP_ENABLE_OWNER          = 0x00000002,
    CREATURE_STATIC_FLAG_3_DO_NOT_FADE_IN                 = 0x00000004, // UNIT_FLAG2_DO_NOT_FADE_IN
    CREATURE_STATIC_FLAG_3_MASK_UID                       = 0x00000008, // CREATURE_TYPE_FLAG_MASK_UID, original description: Non-Unique In Combat Log
    CREATURE_STATIC_FLAG_3_SKIN_WITH_ENGINEERING          = 0x00000010, // CREATURE_TYPE_FLAG_SKIN_WITH_ENGINEERING
    CREATURE_STATIC_FLAG_3_NO_AGGRO_ON_LEASH              = 0x00000020,
    CREATURE_STATIC_FLAG_3_NO_FRIENDLY_AREA_AURAS         = 0x00000040,
    CREATURE_STATIC_FLAG_3_EXTENDED_CORPSE_DURATION       = 0x00000080,
    CREATURE_STATIC_FLAG_3_CANNOT_SWIM                    = 0x00000100, // UNIT_FLAG_CANNOT_SWIM
    CREATURE_STATIC_FLAG_3_TAMEABLE_EXOTIC                = 0x00000200, // CREATURE_TYPE_FLAG_TAMEABLE_EXOTIC
    CREATURE_STATIC_FLAG_3_GIGANTIC_AOI                   = 0x00000400, // Since MoP, creatures with that flag have UnitFlags2 0x400000
    CREATURE_STATIC_FLAG_3_INFINITE_AOI                   = 0x00000800, // Since MoP, creatures with that flag have UnitFlags2 0x40000000
    CREATURE_STATIC_FLAG_3_CANNOT_PENETRATE_WATER         = 0x00001000, // Waterwalking
    CREATURE_STATIC_FLAG_3_NO_NAME_PLATE                  = 0x00002000, // CREATURE_TYPE_FLAG_NO_NAME_PLATE
    CREATURE_STATIC_FLAG_3_CHECKS_LIQUIDS                 = 0x00004000,
    CREATURE_STATIC_FLAG_3_NO_THREAT_FEEDBACK             = 0x00008000,
    CREATURE_STATIC_FLAG_3_USE_MODEL_COLLISION_SIZE       = 0x00010000, // CREATURE_TYPE_FLAG_USE_MODEL_COLLISION_SIZE
    CREATURE_STATIC_FLAG_3_ATTACKER_IGNORES_FACING        = 0x00020000, // In 3.3.5 used only by Rocket Propelled Warhead
    CREATURE_STATIC_FLAG_3_ALLOW_INTERACTION_WHILE_IN_COMBAT = 0x00040000, // CREATURE_TYPE_FLAG_ALLOW_INTERACTION_WHILE_IN_COMBAT
    CREATURE_STATIC_FLAG_3_SPELL_CLICK_FOR_PARTY_ONLY     = 0x00080000,
    CREATURE_STATIC_FLAG_3_FACTION_LEADER                 = 0x00100000,
    CREATURE_STATIC_FLAG_3_IMMUNE_TO_PLAYER_BUFFS         = 0x00200000,
    CREATURE_STATIC_FLAG_3_COLLIDE_WITH_MISSILES          = 0x00400000, // CREATURE_TYPE_FLAG_COLLIDE_WITH_MISSILES
    CREATURE_STATIC_FLAG_3_CAN_BE_MULTITAPPED             = 0x00800000, // Original description: Do Not Tap (Credit to threat list)
    CREATURE_STATIC_FLAG_3_DO_NOT_PLAY_MOUNTED_ANIMATIONS = 0x01000000, // CREATURE_TYPE_FLAG_DO_NOT_PLAY_MOUNTED_ANIMATIONS, original description: Disable Dodge, Parry and Block Animations
    CREATURE_STATIC_FLAG_3_CANNOT_TURN                    = 0x02000000, // UNIT_FLAG2_CANNOT_TURN
    CREATURE_STATIC_FLAG_3_ENEMY_CHECK_IGNORES_LOS        = 0x04000000,
    CREATURE_STATIC_FLAG_3_FOREVER_CORPSE_DURATION        = 0x08000000, // 7 days
    CREATURE_STATIC_FLAG_3_PETS_ATTACK_WITH_3D_PATHING    = 0x10000000, // "Pets attack with 3d pathing (Kologarn)"
    CREATURE_STATIC_FLAG_3_LINK_ALL                       = 0x20000000, // CREATURE_TYPE_FLAG_LINK_ALL
    CREATURE_STATIC_FLAG_3_AI_CAN_AUTO_TAKEOFF_IN_COMBAT  = 0x40000000,
    CREATURE_STATIC_FLAG_3_AI_CAN_AUTO_LAND_IN_COMBAT     = 0x80000000
};

DEFINE_ENUM_FLAG(CreatureStaticFlags3);

enum CreatureStaticFlags4
{
    CREATURE_STATIC_FLAG_4_NO_BIRTH_ANIM                       = 0x00000001, // SMSG_UPDATE_OBJECT's "NoBirthAnim"
    CREATURE_STATIC_FLAG_4_TREAT_AS_PLAYER_FOR_DIMINISHING_RETURNS = 0x00000002, // Primarily used by ToC champions
    CREATURE_STATIC_FLAG_4_TREAT_AS_PLAYER_FOR_PVP_DEBUFF_DURATION = 0x00000004, // Primarily used by ToC champions
    CREATURE_STATIC_FLAG_4_INTERACT_ONLY_WITH_CREATOR          = 0x00000008, // CREATURE_TYPE_FLAG_INTERACT_ONLY_WITH_CREATOR, original description: Only Display Gossip for Summoner
    CREATURE_STATIC_FLAG_4_DO_NOT_PLAY_UNIT_EVENT_SOUNDS       = 0x00000010, // CREATURE_TYPE_FLAG_DO_NOT_PLAY_UNIT_EVENT_SOUNDS, original description: No Death Scream
    CREATURE_STATIC_FLAG_4_HAS_NO_SHADOW_BLOB                  = 0x00000020, // CREATURE_TYPE_FLAG_HAS_NO_SHADOW_BLOB, original description(wrongly linked type flag or behavior was changed?): Can be Healed by Enemies
    CREATURE_STATIC_FLAG_4_DEALS_TRIPLE_DAMAGE_TO_PC_CONTROLLED_PETS = 0x00000040,
    CREATURE_STATIC_FLAG_4_NO_NPC_DAMAGE_BELOW_85PTC           = 0x00000080,
    CREATURE_STATIC_FLAG_4_OBEYS_TAUNT_DIMINISHING_RETURNS     = 0x00000100, // CREATURE_FLAG_EXTRA_OBEYS_TAUNT_DIMINISHING_RETURNS
    CREATURE_STATIC_FLAG_4_NO_MELEE_APPROACH                   = 0x00000200,
    CREATURE_STATIC_FLAG_4_UPDATE_CREATURE_RECORD_WHEN_INSTANCE_CHANGES_DIFFICULTY = 0x00000400, // Used only by Snobold Vassal
    CREATURE_STATIC_FLAG_4_CANNOT_DAZE                         = 0x00000800, // "Cannot Daze (Combat Stun)"
    CREATURE_STATIC_FLAG_4_FLAT_HONOR_AWARD                    = 0x00001000,
    CREATURE_STATIC_FLAG_4_IGNORE_LOS_WHEN_CASTING_ON_ME       = 0x00002000, // "Other objects can ignore line of sight requirements when casting spells on me", used only by Ice Tomb in 3.3.5
    CREATURE_STATIC_FLAG_4_GIVE_QUEST_KILL_CREDIT_WHILE_OFFLINE = 0x00004000,
    CREATURE_STATIC_FLAG_4_TREAT_AS_RAID_UNIT_FOR_HELPFUL_SPELLS = 0x00008000, // CREATURE_TYPE_FLAG_TREAT_AS_RAID_UNIT, "Treat as Raid Unit For Helpful Spells (Instances ONLY)", used by Valithria Dreamwalker
    CREATURE_STATIC_FLAG_4_DONT_REPOSITION_IF_MELEE_TARGET_IS_TOO_CLOSE = 0x00010000, // "Don't reposition because melee target is too close"
    CREATURE_STATIC_FLAG_4_PET_OR_GUARDIAN_AI_DONT_GO_BEHIND_TARGET = 0x00020000,
    CREATURE_STATIC_FLAG_4_5_MINUTE_LOOT_ROLL_TIMER            = 0x00040000, // Used by Lich King
    CREATURE_STATIC_FLAG_4_FORCE_GOSSIP                        = 0x00080000, // CREATURE_TYPE_FLAG_FORCE_GOSSIP
    CREATURE_STATIC_FLAG_4_DONT_REPOSITION_WITH_FRIENDS_IN_COMBAT = 0x00100000,
    CREATURE_STATIC_FLAG_4_DO_NOT_SHEATHE                      = 0x00200000, // CREATURE_TYPE_FLAG_DO_NOT_SHEATHE, original description: Manual Sheathing control
    CREATURE_STATIC_FLAG_4_IGNORE_SPELL_MIN_RANGE_RESTRICTIONS = 0x00400000, // UnitFlags2 0x8000000, original description: Attacker Ignores Minimum Ranges
    CREATURE_STATIC_FLAG_4_SUPPRESS_INSTANCE_WIDE_RELEASE_IN_COMBAT = 0x00800000,
    CREATURE_STATIC_FLAG_4_PREVENT_SWIM                        = 0x01000000, // UnitFlags2 0x1000000, original description: AI will only swim if target swims
    CREATURE_STATIC_FLAG_4_HIDE_IN_COMBAT_LOG                  = 0x02000000, // UnitFlags2 0x2000000, original description: Don't generate combat log when engaged with NPC's
    CREATURE_STATIC_FLAG_4_ALLOW_NPC_COMBAT_WHILE_UNINTERACTIBLE = 0x04000000,
    CREATURE_STATIC_FLAG_4_PREFER_NPCS_WHEN_SEARCHING_FOR_ENEMIES = 0x08000000,
    CREATURE_STATIC_FLAG_4_ONLY_GENERATE_INITIAL_THREAT        = 0x10000000,
    CREATURE_STATIC_FLAG_4_DO_NOT_TARGET_ON_INTERACTION        = 0x20000000, // CREATURE_TYPE_FLAG_DO_NOT_TARGET_ON_INTERACTION, original description: Doesn't change target on right click
    CREATURE_STATIC_FLAG_4_DO_NOT_RENDER_OBJECT_NAME           = 0x40000000, // CREATURE_TYPE_FLAG_DO_NOT_RENDER_OBJECT_NAME, original description: Hide name in world frame
    CREATURE_STATIC_FLAG_4_QUEST_BOSS                          = 0x80000000  // CREATURE_TYPE_FLAG_QUEST_BOSS
};

DEFINE_ENUM_FLAG(CreatureStaticFlags4);

enum CreatureStaticFlags5
{
    CREATURE_STATIC_FLAG_5_UNTARGETABLE_BY_CLIENT              = 0x00000001, // UnitFlags2 0x4000000 UNIT_FLAG2_UNTARGETABLE_BY_CLIENT
    CREATURE_STATIC_FLAG_5_FORCE_SELF_MOUNTING                 = 0x00000002,
    CREATURE_STATIC_FLAG_5_UNINTERACTIBLE_IF_HOSTILE           = 0x00000004, // UnitFlags2 0x10000000
    CREATURE_STATIC_FLAG_5_DISABLES_XP_AWARD                   = 0x00000008,
    CREATURE_STATIC_FLAG_5_DISABLE_AI_PREDICTION               = 0x00000010,
    CREATURE_STATIC_FLAG_5_NO_LEAVECOMBAT_STATE_RESTORE        = 0x00000020,
    CREATURE_STATIC_FLAG_5_BYPASS_INTERACT_INTERRUPTS          = 0x00000040,
    CREATURE_STATIC_FLAG_5_240_DEGREE_BACK_ARC                 = 0x00000080,
    CREATURE_STATIC_FLAG_5_INTERACT_WHILE_HOSTILE              = 0x00000100, // UnitFlags2 0x4000 UNIT_FLAG2_INTERACT_WHILE_HOSTILE
    CREATURE_STATIC_FLAG_5_DONT_DISMISS_ON_FLYING_MOUNT        = 0x00000200,
    CREATURE_STATIC_FLAG_5_PREDICTIVE_POWER_REGEN              = 0x00000400, // CREATURE_TYPEFLAGS_2_UNK1
    CREATURE_STATIC_FLAG_5_HIDE_LEVEL_INFO_IN_TOOLTIP          = 0x00000800, // CREATURE_TYPEFLAGS_2_UNK2
    CREATURE_STATIC_FLAG_5_HIDE_HEALTH_BAR_UNDER_TOOLTIP       = 0x00001000, // CREATURE_TYPEFLAGS_2_UNK3
    CREATURE_STATIC_FLAG_5_SUPPRESS_HIGHLIGHT_WHEN_TARGETED_OR_MOUSED_OVER = 0x00002000, // UnitFlags2 0x80000
    CREATURE_STATIC_FLAG_5_AI_PREFER_PATHABLE_TARGETS          = 0x00004000,
    CREATURE_STATIC_FLAG_5_FREQUENT_AREA_TRIGGER_CHECKS        = 0x00008000,
    CREATURE_STATIC_FLAG_5_ASSIGN_KILL_CREDIT_TO_ENCOUNTER_LIST= 0x00010000,
    CREATURE_STATIC_FLAG_5_NEVER_EVADE                         = 0x00020000,
    CREATURE_STATIC_FLAG_5_AI_CANT_PATH_ON_STEEP_SLOPES        = 0x00040000,
    CREATURE_STATIC_FLAG_5_AI_IGNORE_LOS_TO_MELEE_TARGET       = 0x00080000,
    CREATURE_STATIC_FLAG_5_NO_TEXT_IN_CHAT_BUBBLE              = 0x00100000, // "Never display emote or chat text in a chat bubble", CREATURE_TYPEFLAGS_2_UNK4
    CREATURE_STATIC_FLAG_5_CLOSE_IN_ON_UNPATHABLE_TARGET       = 0x00200000, // "AI Pets close in on unpathable target"
    CREATURE_STATIC_FLAG_5_DONT_GO_BEHIND_ME                   = 0x00400000, // "Pet/Guardian AI Don't Go Behind Me (use on target)"
    CREATURE_STATIC_FLAG_5_NO_DEATH_THUD                       = 0x00800000, // CREATURE_TYPEFLAGS_2_UNK5
    CREATURE_STATIC_FLAG_5_CLIENT_LOCAL_CREATURE               = 0x01000000,
    CREATURE_STATIC_FLAG_5_CAN_DROP_LOOT_WHILE_IN_A_CHALLENGE_MODE_INSTANCE = 0x02000000,
    CREATURE_STATIC_FLAG_5_HAS_SAFE_LOCATION                   = 0x04000000,
    CREATURE_STATIC_FLAG_5_NO_HEALTH_REGEN                     = 0x08000000,
    CREATURE_STATIC_FLAG_5_NO_POWER_REGEN                      = 0x10000000,
    CREATURE_STATIC_FLAG_5_NO_PET_UNIT_FRAME                   = 0x20000000,
    CREATURE_STATIC_FLAG_5_NO_INTERACT_ON_LEFT_CLICK           = 0x40000000, // CREATURE_TYPEFLAGS_2_UNK6
    CREATURE_STATIC_FLAG_5_GIVE_CRITERIA_KILL_CREDIT_WHEN_CHARMED = 0x80000000
};

DEFINE_ENUM_FLAG(CreatureStaticFlags5);

class CreatureStaticFlagsHolder
{
public:
    explicit CreatureStaticFlagsHolder(CreatureStaticFlags flags = CreatureStaticFlags(), CreatureStaticFlags2 flags2 = CreatureStaticFlags2(),
        CreatureStaticFlags3 flags3 = CreatureStaticFlags3(), CreatureStaticFlags4 flags4 = CreatureStaticFlags4(), CreatureStaticFlags5 flags5 = CreatureStaticFlags5())
        : _flags(flags), _flags2(flags2), _flags3(flags3), _flags4(flags4), _flags5(flags5)
    {
    }

    bool HasFlag(CreatureStaticFlags flag) const { return _flags.HasFlag(flag); }
    bool HasFlag(CreatureStaticFlags2 flag) const { return _flags2.HasFlag(flag); }
    bool HasFlag(CreatureStaticFlags3 flag) const { return _flags3.HasFlag(flag); }
    bool HasFlag(CreatureStaticFlags4 flag) const { return _flags4.HasFlag(flag); }
    bool HasFlag(CreatureStaticFlags5 flag) const { return _flags5.HasFlag(flag); }

    void ApplyFlag(CreatureStaticFlags flag, bool apply) { if (apply) _flags |= flag; else _flags &= ~flag; }
    void ApplyFlag(CreatureStaticFlags2 flag, bool apply) { if (apply) _flags2 |= flag; else _flags2 &= ~flag; }
    void ApplyFlag(CreatureStaticFlags3 flag, bool apply) { if (apply) _flags3 |= flag; else _flags3 &= ~flag; }
    void ApplyFlag(CreatureStaticFlags4 flag, bool apply) { if (apply) _flags4 |= flag; else _flags4 &= ~flag; }
    void ApplyFlag(CreatureStaticFlags5 flag, bool apply) { if (apply) _flags5 |= flag; else _flags5 &= ~flag; }

private:
    EnumFlag<CreatureStaticFlags> _flags;
    EnumFlag<CreatureStaticFlags2> _flags2;
    EnumFlag<CreatureStaticFlags3> _flags3;
    EnumFlag<CreatureStaticFlags4> _flags4;
    EnumFlag<CreatureStaticFlags5> _flags5;
};

enum class CreatureGroundMovementType : uint8
{
    None,
    Run,
    Hover,

    Max
};

enum class CreatureFlightMovementType : uint8
{
    None,
    DisableGravity,
    CanFly,

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

    CreatureGroundMovementType Ground;
    CreatureFlightMovementType Flight;
    bool Swim;
    bool Rooted;
    CreatureRandomMovementType Random;
    uint32 InteractionPauseTimer;

    bool IsGroundAllowed() const { return Ground != CreatureGroundMovementType::None; }
    bool IsSwimAllowed() const { return Swim; }
    bool IsFlightAllowed() const { return Flight != CreatureFlightMovementType::None; }
    bool IsRooted() const { return Rooted; }
    bool IsGravityDisabled() const { return  Flight == CreatureFlightMovementType::DisableGravity; }
    bool CanFly() const { return  Flight == CreatureFlightMovementType::CanFly; }
    bool IsHoverEnabled() const { return  Ground == CreatureGroundMovementType::Hover; }

    CreatureRandomMovementType GetRandom() const { return Random; }

    uint32 GetInteractionPauseTimer() const { return InteractionPauseTimer; }

    std::string ToString() const;
};

static uint32 const CREATURE_NOPATH_EVADE_TIME = 5 * IN_MILLISECONDS;

static uint8 const MAX_KILL_CREDIT = 2;
static uint32 const MAX_CREATURE_MODELS = 4;
static uint32 const MAX_CREATURE_QUEST_ITEMS = 6;
static uint32 const MAX_CREATURE_SPELLS = 8;

// from `creature_template` table
struct TC_GAME_API CreatureTemplate
{
    uint32  Entry;
    uint32  DifficultyEntry[MAX_DIFFICULTY - 1];
    uint32  KillCredit[MAX_KILL_CREDIT];
    uint32  Modelid1;
    uint32  Modelid2;
    uint32  Modelid3;
    uint32  Modelid4;
    std::string  Name;
    std::string FemaleName;
    std::string  Title;
    std::string  IconName;
    uint32  GossipMenuId;
    uint8   minlevel;
    uint8   maxlevel;
    uint32  expansion;
    uint32  expansionUnknown;                               // either 0 or 3, sent to the client / wdb
    uint32  faction;
    uint32  npcflag;
    float   speed_walk;
    float   speed_run;
    float   scale;
    uint32  rank;
    uint32  dmgschool;
    uint32  BaseAttackTime;
    uint32  RangeAttackTime;
    float   BaseVariance;
    float   RangeVariance;
    uint32  unit_class;                                     // enum Classes. Note only 4 classes are known for creatures.
    uint32  unit_flags;                                     // enum UnitFlags mask values
    uint32  unit_flags2;                                    // enum UnitFlags2 mask values
    uint32  dynamicflags;
    CreatureFamily  family;                                 // enum CreatureFamily values (optional)
    uint32  trainer_class;
    uint32  type;                                           // enum CreatureType values
    uint32  type_flags;                                     // enum CreatureTypeFlags mask values
    uint32  type_flags2;                                    // unknown enum, only set for 4 creatures (with value 1)
    uint32  lootid;
    uint32  pickpocketLootId;
    uint32  SkinLootId;
    int32   resistance[MAX_SPELL_SCHOOL];
    uint32  spells[MAX_CREATURE_SPELLS];
    uint32  PetSpellDataId;
    uint32  VehicleId;
    uint32  mingold;
    uint32  maxgold;
    std::string AIName;
    uint32  MovementType;
    CreatureMovementData Movement;
    float   HoverHeight;
    float   ModHealth;
    float   ModHealthExtra;
    float   ModMana;
    float   ModManaExtra;                                   // Added in 4.x, this value is usually 2 for a small group of creatures with double mana
    float   ModArmor;
    float   ModDamage;
    float   ModExperience;
    bool    RacialLeader;
    uint32  movementId;
    bool    RegenHealth;
    uint32  MechanicImmuneMask;
    uint32  SpellSchoolImmuneMask;
    uint32  flags_extra;
    CreatureStaticFlagsHolder StaticFlags;
    uint32  ScriptID;
    WorldPacket QueryData[TOTAL_LOCALES];
    uint32  GetRandomValidModelId() const;
    uint32  GetFirstValidModelId() const;
    uint32  GetFirstInvisibleModel() const;
    uint32  GetFirstVisibleModel() const;

    // helpers
    SkillType GetRequiredLootSkill() const
    {
        if (type_flags & CREATURE_TYPE_FLAG_HERB_SKINNING_SKILL)
            return SKILL_HERBALISM;
        else if (type_flags & CREATURE_TYPE_FLAG_MINING_SKINNING_SKILL)
            return SKILL_MINING;
        else if (type_flags & CREATURE_TYPE_FLAG_ENGINEERING_SKINNING_SKILL)
            return SKILL_ENGINEERING;
        else
            return SKILL_SKINNING;                          // normal case
    }

    bool IsExotic() const
    {
        return (type_flags & CREATURE_TYPE_FLAG_EXOTIC_PET) != 0;
    }

    bool IsTameable(bool canTameExotic) const
    {
        if (type != CREATURE_TYPE_BEAST || family == CREATURE_FAMILY_NONE || (type_flags & CREATURE_TYPE_FLAG_TAMEABLE_PET) == 0)
            return false;

        // if can tame exotic then can tame any tameable
        return canTameExotic || !IsExotic();
    }

    void InitializeQueryData();
    WorldPacket BuildQueryData(LocaleConstant loc) const;
};

#pragma pack(push, 1)

// Defines base stats for creatures (used to calculate HP/mana/armor/attackpower/rangedattackpower/all damage).
struct TC_GAME_API CreatureBaseStats
{
    uint32 BaseHealth[MAX_EXPANSIONS];
    uint32 BaseMana;
    uint32 BaseArmor;
    uint32 AttackPower;
    uint32 RangedAttackPower;
    float BaseDamage[MAX_EXPANSIONS];

    // Helpers

    uint32 GenerateHealth(CreatureTemplate const* info) const
    {
        return uint32(ceil(BaseHealth[info->expansion] * info->ModHealth * info->ModHealthExtra));
    }

    uint32 GenerateMana(CreatureTemplate const* info) const
    {
        // Mana can be 0.
        if (!BaseMana)
            return 0;

        return uint32(ceil(BaseMana * info->ModMana * info->ModManaExtra));
    }

    uint32 GenerateArmor(CreatureTemplate const* info) const
    {
        return uint32(ceil(BaseArmor * info->ModArmor));
    }

    float GenerateBaseDamage(CreatureTemplate const* info) const
    {
        return BaseDamage[info->expansion];
    }

    static CreatureBaseStats const* GetBaseStats(uint8 level, uint8 unitClass);
};

typedef std::unordered_map<uint16, CreatureBaseStats> CreatureBaseStatsContainer;

struct CreatureLocale
{
    std::vector<std::string> Name;
    std::vector<std::string> FemaleName;
    std::vector<std::string> Title;
};

struct EquipmentInfo
{
    uint32  ItemEntry[MAX_EQUIPMENT_ITEMS];
};

// from `creature` table
struct CreatureData : public SpawnData
{
    CreatureData() : SpawnData(SPAWN_TYPE_CREATURE) { }
    uint32 displayid = 0;
    int8 equipmentId = 0;
    float wanderDistance = 0.0f;
    uint32 currentwaypoint = 0;
    uint32 curhealth = 0;
    uint32 curmana = 0;
    uint8 movementType = 0;
    uint32 npcflag = 0;
    uint32 unit_flags = 0;
    uint32 dynamicflags = 0;
};

struct CreatureModelInfo
{
    float bounding_radius;
    float combat_reach;
    uint8 gender;
    uint32 modelid_other_gender;
    bool is_trigger;
};

enum InhabitTypeValues
{
    INHABIT_GROUND = 1,
    INHABIT_WATER  = 2,
    INHABIT_AIR    = 4,
    INHABIT_ROOT   = 8,
    INHABIT_ANYWHERE = INHABIT_GROUND | INHABIT_WATER | INHABIT_AIR | INHABIT_ROOT
};

#pragma pack(pop)

// `creature_addon` table
struct CreatureAddon
{
    uint32 waypointPathId;
    uint32 cyclicSplinePathId;
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

// Vendors
struct VendorItem
{
    VendorItem() : item(0), maxcount(0), incrtime(0), ExtendedCost(0), Type(0), PlayerConditionId(0) { }

    uint32 item;
    uint32 maxcount;                                        // 0 for infinity item amount
    uint32 incrtime;                                        // time for restore items amount if maxcount != 0
    uint32 ExtendedCost;
    uint8  Type;
    uint32 PlayerConditionId;

    //helpers
    bool IsGoldRequired(ItemTemplate const* pProto) const;
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
    uint32 GetItemCount() const { return m_items.size(); }
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

typedef std::unordered_map<uint32, float /*SparringHealthLimit*/> CreatureSparringTemplateMap;

struct CreatureMovementInfo
{
    float WalkSpeed = 0.f;
    float RunSpeed = 0.f;

    bool HasRunSpeedOverriden = false;
    bool HasWalkSpeedOverriden = false;
};

struct CreatureSpellFocusData
{
    Spell const* FocusSpell = nullptr;
    ObjectGuid OriginalUnitTarget;
    uint32 ReacquiringTargetDelay = 0;

public:
    void Reset()
    {
        FocusSpell = nullptr;
        ReacquiringTargetDelay = 0;
    }
};

#endif // CreatureData_h__
