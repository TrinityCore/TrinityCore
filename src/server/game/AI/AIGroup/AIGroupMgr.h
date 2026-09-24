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

#ifndef TRINITYCORE_AI_GROUP_MGR_H
#define TRINITYCORE_AI_GROUP_MGR_H

#include "Define.h"
#include "EnumFlag.h"
#include <unordered_map>

class WorldObject;

// EnumeratedString's EnumID 1158 and g_groupActionsList
enum AI_GROUP_ACTION
{
    AI_GROUP_SPAWN                                  = 0,     // NYI // Spawn
    AI_GROUP_IDLE                                   = 1,     // NYI // Idle
    AI_GROUP_MOVETO                                 = 2,     // NYI // Move within distance of a point
    AI_GROUP_TELEPORT                               = 3,     // NYI // Teleport to a point in the world
    AI_GROUP_WANDER                                 = 4,     // Wander
    AI_GROUP_ATTACK_ALL                             = 5,     // NYI // Attack all players within a given radius; old AI_GROUP_WANDER_SPAWNRELATIVE_OBSOLETE
    AI_GROUP_WANDER_AREA                            = 6,     // Wander a convex poly area (not yet implemented)
    AI_GROUP_FOLLOW_GUID                            = 7,     // NYI // Follow a unit
    AI_GROUP_FOLLOW_PATH                            = 8,     // NYI // Follow a path
    AI_GROUP_PATROL_LINE                            = 9,     // NYI // Patrol back and forth along a path
    AI_GROUP_PATROL_CIRCLE                          = 10,    // NYI // Patrol in a circular path
    AI_GROUP_GUARD_GUID                             = 11,    // NYI // Guard a unit
    AI_GROUP_GUARD_AREA                             = 12,    // NYI // Guard an area (not yet implemented)
    AI_GROUP_SET_FORMATION                          = 13,    // NYI // Set a specific formation and spread
    AI_GROUP_UNIT_CHANGE_MODE_OBSOLETE              = 14,    // Obsolete // Change mode on unit(s) in the group (obsolete)
    AI_GROUP_UNIT_SAY                               = 15,    // NYI // Unit(s) say something
    AI_GROUP_UNIT_CAST                              = 16,    // NYI // Unit(s) cast a spell
    AI_GROUP_UNIT_ACTIVATE_OBJECT                   = 17,    // NYI // Unit(s) activate a game object
    AI_GROUP_GENERATE_EVENT                         = 18,    // NYI // Generate an event
    AI_GROUP_DESPAWN                                = 19,    // NYI // Despawn
    AI_GROUP_SET_RADIUS_OBSOLETE                    = 20,    // Obsolete // Unit(s) start a conversation (public unless target is a player)
    AI_GROUP_SET_FACTION_OBSOLETE                   = 21,    // Obsolete // Unit(s) cancel a conversation (public unless target is a player)
    AI_GROUP_UNIT_SET_FACING                        = 22,    // NYI // Unit(s) face a particular angle
    AI_GROUP_UNIT_FACE_GUID                         = 23,    // NYI // Unit(s) face a unit or game object or point
    AI_GROUP_UNIT_EMOTE                             = 24,    // NYI // Emote State - Set and Forget (formerly perform an emote)
    AI_GROUP_MOVETO_GUID                            = 25,    // NYI // Move within distance of a unit or game object
    AI_GROUP_ATTACK_GUID                            = 26,    // NYI // Attack unit
    AI_GROUP_UNIT_MOUNT                             = 27,    // NYI // Unit(s) mount a creature
    AI_GROUP_UNIT_DISMOUNT                          = 28,    // NYI // Unit(s) dismount
    AI_GROUP_UNINTERACTIBLE                         = 29,    // NYI // Set "Uninteractible" flag for unit(s); old AI_GROUP_BEASTMASTER_ON
    AI_GROUP_UNINTERACTIBLE_RESET                   = 30,    // NYI // Reset "Uninteractible" flag for unit(s); old AI_GROUP_BEASTMASTER_OFF
    AI_GROUP_UNIT_MODE                              = 31,    // NYI // Change mode for unit(s)
    AI_GROUP_UNIT_MODE_RESET                        = 32,    // NYI // Reset mode for unit(s)
    AI_GROUP_UNIT_FACTION                           = 33,    // NYI // Change faction template for unit(s)
    AI_GROUP_UNIT_FACTION_RESET                     = 34,    // NYI // Reset faction template for unit(s)
    AI_GROUP_UNIT_RADIUS                            = 35,    // NYI // Change radius record for unit(s)
    AI_GROUP_UNIT_RADIUS_RESET                      = 36,    // NYI // Reset radius record for unit(s)
    AI_GROUP_QUEST_COMPLETE                         = 37,    // NYI // Escort quest actions completed
    AI_GROUP_UNIT_QUESTGIVER                        = 38,    // NYI // Unit(s) become a quest giver
    AI_GROUP_UNIT_TRAINER                           = 39,    // NYI // Unit(s) become a trainer
    AI_GROUP_SPLINE_PATH                            = 40,    // NYI // Follow a short path exactly (no pathing)
    AI_GROUP_PLAYER_ACTION                          = 41,    // NYI // Player performs an action (Programmer -Internal Use Only)
    AI_GROUP_RETURN_HOME                            = 42,    // NYI // Move everybody back to spawn positions
    AI_GROUP_UNIT_SAY_RANDOM                        = 43,    // NYI // Unit(s) say something random
    AI_GROUP_UNIT_YELL                              = 44,    // NYI // Unit(s) yell something
    AI_GROUP_UNIT_YELL_RANDOM                       = 45,    // NYI // Unit(s) yell something random
    AI_GROUP_UNIT_SET_ITEM_MAINHAND                 = 46,    // NYI // Set the item in the mainhand slot for unit(s)
    AI_GROUP_UNIT_RESET_ITEM_MAINHAND               = 47,    // NYI // Reset the item in the mainhand slot for unit(s)
    AI_GROUP_UNIT_CHAT_EMOTE                        = 48,    // NYI // Unit(s) chat emote something
    AI_GROUP_UNIT_CHAT_EMOTE_RANDOM                 = 49,    // NYI // Unit(s) chat emote something random
    AI_GROUP_UNIT_GENERATE_EVENT                    = 50,    // NYI // Unit(s) in the group generates an event
    AI_GROUP_VENDOR_IDLE_OBSOLETE                   = 51,    // Obsolete // Vendor wander + face + idle action sequence (obsolete)
    AI_GROUP_QUEST_FAILED                           = 52,    // NYI // Escort quest actions failed
    AI_GROUP_UNIT_TRIGGERS                          = 53,    // NYI // Change action triggers for unit(s)
    AI_GROUP_UNIT_TRIGGERS_RESET                    = 54,    // NYI // Reset action triggers for unit(s)
    AI_GROUP_UNIT_LEAVE_COMBAT                      = 55,    // NYI // Leave combat (combat action only)
    AI_GROUP_IDLE_COMBAT_START                      = 56,    // NYI // Idle until group goes into combat
    AI_GROUP_IDLE_COMBAT_STOP                       = 57,    // NYI // Idle until group returns from combat
    AI_GROUP_UNIT_IMMUNEPC                          = 58,    // NYI // Set "ImmunePC" flag for unit(s)
    AI_GROUP_UNIT_IMMUNEPC_RESET                    = 59,    // NYI // Reset "ImmunePC" flag for unit(s)
    AI_GROUP_UNIT_IMMUNENPC                         = 60,    // NYI // Set "ImmuneNPC" flag for unit(s)
    AI_GROUP_UNIT_IMMUNENPC_RESET                   = 61,    // NYI // Reset "ImmuneNPC" flag for unit(s)
    AI_GROUP_UNIT_UNKILLABLE                        = 62,    // NYI // Set "Unkillable" flag for unit(s)
    AI_GROUP_UNIT_UNKILLABLE_RESET                  = 63,    // NYI // Reset "Unkillable" flag for unit(s)
    AI_GROUP_UNIT_SPELLS                            = 64,    // NYI // Set the spells record for unit(s)
    AI_GROUP_UNIT_SPELLS_RESET                      = 65,    // NYI // Reset the spells record for unit(s)
    AI_GROUP_ATTACK_ALL_INSTANCE                    = 66,    // NYI // Attack everybody in the instance
    AI_GROUP_UNIT_SEND_LOCAL_EVENT                  = 67,    // NYI // Unit(s) send a local event
    AI_GROUP_UNIT_BROADCAST_LOCAL_EVENT             = 68,    // NYI // Unit(s) broadcast a local event
    AI_GROUP_UNIT_FLEE                              = 69,    // NYI // Flee combat (combat action only)
    AI_GROUP_UNIT_RETREAT                           = 70,    // NYI // Retreat (combat action only)
    AI_GROUP_OBJECT_CHAT_EMOTE                      = 71,    // NYI // Object(s) chat emote something
    AI_GROUP_OBJECT_CHAT_EMOTE_RANDOM               = 72,    // NYI // Object(s) chat emote something random
    AI_GROUP_AVOID                                  = 73,    // NYI // Move outside a certain distance of a point
    AI_GROUP_AVOID_GUID                             = 74,    // NYI // Move outside a certain distance of a unit or game object
    AI_GROUP_OBJECT_ACTIVATE                        = 75,    // NYI // Activate object(s) in the group
    AI_GROUP_UNIT_ACTIVATE_OBJECTS                  = 76,    // NYI // Unit(s) activate nearby game objects
    AI_GROUP_UNIT_STRINGID                          = 77,    // NYI // Set the string ID for unit(s)
    AI_GROUP_UNIT_STRINGID_RESET                    = 78,    // NYI // Reset the string ID for unit(s)
    AI_GROUP_PERIODIC_EVENT                         = 79,    // NYI // Set a periodic event for the group
    AI_GROUP_UNIT_SET_ITEM_OFFHAND                  = 80,    // NYI // Set the item in the offhand slot for unit(s)
    AI_GROUP_UNIT_RESET_ITEM_OFFHAND                = 81,    // NYI // Reset the item in the offhand slot for unit(s)
    AI_GROUP_UNIT_SET_ITEM_RANGED                   = 82,    // NYI // Set the item in the ranged slot for unit(s)
    AI_GROUP_UNIT_RESET_ITEM_RANGED                 = 83,    // NYI // Reset the item in the ranged slot for unit(s)
    AI_GROUP_UNIT_SHEATHE                           = 84,    // NYI // Unit(s) sheathe their weapons
    AI_GROUP_UNIT_UNSHEATHE                         = 85,    // NYI // Unit(s) unsheathe their melee weapons
    AI_GROUP_UNIT_CANCEL_CAST                       = 86,    // NYI // Unit(s) cancel casting a spell
    AI_GROUP_UNIT_CANCEL_AURA                       = 87,    // NYI // Unit(s) cancel an aura on themselves
    AI_GROUP_UNIT_FINISH_CAST                       = 88,    // NYI // Unit(s) wait until they finish casting
    AI_GROUP_EMOTE_STATE                            = 89,    // NYI // Emote State with Idle (formerly continually emote)
    AI_GROUP_UNIT_CALL_FOR_HELP                     = 90,    // NYI // Call for help (combat action only)
    AI_GROUP_FLIGHT_PATH                            = 91,    // NYI // Follow a flight spline path exactly
    AI_GROUP_UNIT_COMBAT_TRIGGER                    = 92,    // NYI // Trigger actions on units in combat
    // ^ Alpha Build 3368
    // Below created from descriptions
    AI_GROUP_UNIT_GOSSIP                            = 93,    // NYI // Unit(s) become a gossip
    AI_GROUP_UNIT_KILL_CREDIT                       = 94,    // NYI // Unit(s) assign kill credit
    AI_GROUP_UNIT_WHISPER                           = 95,    // NYI // Unit(s) whisper to a player
    AI_GROUP_UNIT_WHISPER_RANDOM                    = 96,    // NYI // Unit(s) whisper to a player something random
    AI_GROUP_UNIT_NO_LOOT                           = 97,    // NYI // Set "No Loot" flag for unit(s) in the group
    AI_GROUP_UNIT_NO_LOOT_RESET                     = 98,    // NYI // Reset "No Loot" flag for unit(s) in the group
    AI_GROUP_UNIT_NO_XP                             = 99,    // NYI // Set "No XP" flag for unit(s) in the group
    AI_GROUP_UNIT_NO_XP_RESET                       = 100,   // NYI // Reset "No XP" flag for unit(s) in the group
    AI_GROUP_UNIT_PVP_ENABLING                      = 101,   // NYI // Set "PVP" flag for unit(s) in the group
    AI_GROUP_UNIT_PVP_ENABLING_RESET                = 102,   // NYI // Reset "PVP" flag for unit(s) in the group
    AI_GROUP_UNIT_PLAY_MUSIC                        = 103,   // NYI // Unit(s) play music
    AI_GROUP_UNIT_PLAY_SOUND                        = 104,   // NYI // Unit(s) play a sound
    AI_GROUP_UNIT_SET_LOOT                          = 105,   // NYI // Set the loot for a unit
    AI_GROUP_UNIT_FLOATING                          = 106,   // NYI // Set "Floating" flag for unit(s) in the group
    AI_GROUP_UNIT_FLOATING_RESET                    = 107,   // NYI // Reset "Floating" flag for unit(s) in the group
    AI_GROUP_OBJECT_PLAY_MUSIC                      = 108,   // NYI // Object(s) play music
    AI_GROUP_OBJECT_PLAY_SOUND                      = 109,   // NYI // Object(s) play a sound
    AI_GROUP_SPAWN_FORCED                           = 110,   // NYI // Spawn (forced)
    AI_GROUP_UNIT_UNSHEATHE_RANGE                   = 111,   // NYI // Unit(s) unsheathe their range weapons
    AI_GROUP_UNIT_CHAT_EMOTE_ZONE                   = 112,   // NYI // Unit(s) chat emote something to the zone
    AI_GROUP_UNIT_CHAT_EMOTE_ZONE_RANDOM            = 113,   // NYI // Unit(s) chat emote something random to the zone
    AI_GROUP_UNIT_YELL_ZONE                         = 114,   // NYI // Unit(s) yell something to the zone
    AI_GROUP_UNIT_YELL_ZONE_RANDOM                  = 115,   // NYI // Unit(s) yell something random to the zone
    AI_GROUP_UNIT_PLAY_MUSIC_ZONE                   = 116,   // NYI // Unit(s) play music to the zone
    AI_GROUP_UNIT_PLAY_SOUND_ZONE                   = 117,   // NYI // Unit(s) play a sound to the zone
    AI_GROUP_OBJECT_CHAT_EMOTE_ZONE                 = 118,   // NYI // Object(s) chat emote something to the zone
    AI_GROUP_OBJECT_CHAT_EMOTE_ZONE_RANDOM          = 119,   // NYI // Object(s) chat emote something random to the zone
    AI_GROUP_OBJECT_PLAY_MUSIC_ZONE                 = 120,   // NYI // Object(s) play music to the zone
    AI_GROUP_OBJECT_PLAY_SOUND_ZONE                 = 121,   // NYI // Object(s) play a sound to the zone
    AI_GROUP_UNIT_IGNORE_COMBAT                     = 122,   // NYI // Set "Ignore combat" flag for unit(s)
    AI_GROUP_UNIT_IGNORE_COMBAT_RESET               = 123,   // NYI // Reset "Ignore combat" flag for unit(s)
    AI_GROUP_RANDOM_ACTION_SET                      = 124,   // NYI // Perform a random set of actions
    AI_GROUP_RESTART_ACTIONS_WSE                    = 125,   // NYI // Restart the current actions if world state expression is true
    AI_GROUP_ABORT_ACTION_SET_WSE                   = 126,   // NYI // Abort action set if world state expression is true
    AI_GROUP_UNIT_BOSS_EMOTE                        = 127,   // NYI // Unit(s) boss emote something
    AI_GROUP_UNIT_BOSS_EMOTE_ZONE                   = 128,   // NYI // Unit(s) boss emote something to the zone
    AI_GROUP_TRIGGER_ACTIONS_NEAREST_UNIT_IC        = 129,   // NYI // Trigger actions on nearest unit in combat
    // ^ 1.12.1
    AI_GROUP_UNIT_CAST_FAILURE                      = 130,   // NYI // Unit(s) cast a spell and report failure to owner
    AI_GROUP_UNIT_NO_REPUTATION                     = 131,   // NYI // Set "No Reputation" flag for unit(s) in the group
    AI_GROUP_UNIT_NO_REPUTATION_RESET               = 132,   // NYI // Reset "No Reputation" flag for unit(s) in the group
    AI_GROUP_SPLINE_PATH_LOOP                       = 133,   // NYI // Follow a flight spline path exactly, and loop forever
    AI_GROUP_UNIT_VENDOR                            = 134,   // NYI // Unit(s) become a vendor
    AI_GROUP_UNIT_RESET_VENDOR_LISTS                = 135,   // NYI // Reset vendor lists for unit(s) in the group
    AI_GROUP_TRIGGER_ACTIONS_UNITS                  = 136,   // NYI // Trigger actions on units
    AI_GROUP_TRIGGER_ACTIONS_NEAREST_UNIT           = 137,   // NYI // Trigger actions on nearest unit
    AI_GROUP_UNIT_SAY_ZONE                          = 138,   // NYI // Unit(s) say something to the zone
    AI_GROUP_UNIT_SAY_ZONE_RANDOM                   = 139,   // NYI // Unit(s) say something random to the zone
    AI_GROUP_UNIT_SEND_LOCAL_EVENT_SELF             = 140,   // NYI // Unit(s) send a local event to self (if outside of combat)
    AI_GROUP_UNIT_SESSILE                           = 141,   // NYI // Set "Sessile" flag for unit(s)
    AI_GROUP_UNIT_SESSILE_RESET                     = 142,   // NYI // Reset "Sessile" flag for unit(s)
    AI_GROUP_UNIT_RAID_LOCK                         = 143,   // NYI // Set "RAID_LOCK_ON_DEATH" flag for unit(s)
    AI_GROUP_UNIT_RAID_LOCK_RESET                   = 144,   // NYI // Reset "RAID_LOCK_ON_DEATH" flag for unit(s)
    AI_GROUP_QUEST_COMPLETE_TRIGGERING_PLAYER       = 145,   // NYI // Quest complete for triggering player
    AI_GROUP_QUEST_CLEARED_TRIGGERING_PLAYER        = 146,   // NYI // Quest cleared for triggering player
    AI_GROUP_UNIT_CHAT_PARTY                        = 147,   // NYI // Unit(s) chat to a player's party
    AI_GROUP_UNIT_CLEAR_COOLDOWNS                   = 148,   // NYI // Unit(s) clear cooldowns
    AI_GROUP_UNIT_PLAY_TARGETED_SOUND               = 149,   // NYI // Unit(s) play a targeted sound
    AI_GROUP_UNIT_PLAY_TARGETED_MUSIC               = 150,   // NYI // Unit(s) play targeted music
    AI_GROUP_UNIT_RESET_INITIAL_SPELL_COOLDOWNS     = 151,   // NYI // Unit(s) reset initial spell cooldowns
    AI_GROUP_UNIT_NO_MELEE                          = 152,   // NYI // Set "No Melee" flag for unit(s) in the group
    AI_GROUP_UNIT_NO_MELEE_RESET                    = 153,   // NYI // Reset "No Melee" flag for unit(s) in the group
    AI_GROUP_FALL_TO_THE_GROUND                     = 154,   // NYI // Fall to the ground
    AI_GROUP_UNIT_UPDATE_INTERACTION                = 155,   // NYI // Unit(s) update interaction
    AI_GROUP_UNIT_BOSS_WHISPER                      = 156,   // NYI // Unit(s) boss whispers someone
    AI_GROUP_UNIT_BOSS_WHISPER_RANDOM               = 157,   // NYI // Unit(s) boss whispers someone randomly
    AI_GROUP_MOVE_RELATIVE                          = 158,   // NYI // Move relative to current facing
    AI_GROUP_UNIT_DONT_CLEAR_TAP                    = 159,   // NYI // Unit(s) don't clear tap when leaving combat
    AI_GROUP_UNIT_KILL_CREDIT_TAP                   = 160,   // NYI // Unit(s) assign kill credit to tap list
    AI_GROUP_UNIT_CAST_WITH_POINTS                  = 161,   // NYI // Unit(s) cast a spell with points
    AI_GROUP_UNIT_RIDE_VEHICLE                      = 162,   // NYI // Unit(s) ride a vehicle
    AI_GROUP_UNIT_ABANDON_VEHICLE                   = 163,   // NYI // Unit(s) abandon their vehicles
    AI_GROUP_VEHICLE_RECALL_OR_RESPAWN_PASSENGERS   = 164,   // NYI // Vehicle(s) recall or respawn each passenger
    AI_GROUP_PLAY_MOVIE                             = 165,   // NYI // Target player plays a movie file
    // ^ 2.4.3
    AI_GROUP_JUMP_POINT                             = 166,   // NYI // Jump to a point
    AI_GROUP_JUMP_GUID                              = 167,   // NYI // Jump to an object or unit
    AI_GROUP_MOVETO_THEN_JUMP                       = 168,   // NYI // Move to a point, then jump to end of path
    AI_GROUP_VEHICLE_RECALL_LIVING_PASSENGERS       = 169,   // NYI // Vehicle(s) recall each living passenger
    AI_GROUP_VEHICLE_RESPAWN_ALL_PASSENGERS         = 170,   // NYI // Vehicle(s) respawn all passengers
    AI_GROUP_UNIT_FATAL_FALL_DISTANCE               = 171,   // NYI // Unit(s) Set fatal fall distance
    AI_GROUP_UNIT_FATAL_FALL_DISTANCE_RESET         = 172,   // NYI // Unit(s) Reset fatal fall distance
    AI_GROUP_UNIT_SET_ANIMATION_TIER                = 173,   // NYI // Unit(s) Set Animation/Movement Tier
    AI_GROUP_UNIT_SEND_TAP_LIST                     = 174,   // NYI // Unit(s) send their tap list to another unit
    AI_GROUP_UNIT_GET_TAP_LIST                      = 175,   // NYI // Unit(s) get their tap list from another unit
    AI_GROUP_UNIT_HOVER_HEIGHT                      = 176,   // NYI // Unit(s) set their hover height
    AI_GROUP_UNIT_HOVER_HEIGHT_RESET                = 177,   // NYI // Unit(s) Reset their hover height
    AI_GROUP_TIER_TRANSITION_LAND                   = 178,   // NYI // Tier Transition Land
    AI_GROUP_TIER_TRANSITION_TAKE_OFF               = 179,   // NYI // Tier Transition Take off
    AI_GROUP_TIER_TRANSITION_MOVETO                 = 180,   // NYI // Tier Transition Move To
    AI_GROUP_TIER_TRANSITION_MOVETO_GUID            = 181,   // NYI // Tier Transition Move To a Unit or Game Object
    AI_GROUP_TIER_TRANSITION_FOLLOW_PATH            = 182,   // NYI // Tier Transition Follow Path
    AI_GROUP_UNIT_KILL_CREDIT_PLAYER                = 183,   // NYI // Unit(s) assign kill credit to player
    AI_GROUP_SUSPEND_TRIGGER_ACTION                 = 184,   // NYI // Suspend Trigger action (creature action only)
    AI_GROUP_UNIT_VEHICLE_RECORD                    = 185,   // NYI // Unit(s) change their vehicle record ID
    AI_GROUP_UNIT_VEHICLE_RECORD_RESET              = 186,   // NYI // Unit(s) reset their vehicle record ID
    AI_GROUP_UNIT_IMMUNITIES                        = 187,   // NYI // Unit(s) change their creature immunity template ID
    AI_GROUP_UNIT_IMMUNITIES_RESET                  = 188,   // NYI // Unit(s) reset their creature immunity template ID
    AI_GROUP_SEND_CONTENT_ALERT                     = 189,   // NYI // Send a content alert
    AI_GROUP_UNIT_SAY_PLAYER                        = 190,   // NYI, Cata+? // Unit(s) says something only to a player
    AI_GROUP_UNIT_YELL_PLAYER                       = 191,   // NYI, Cata+? // Unit(s) yells something only to a player
    AI_GROUP_UNIT_START_QUEST                       = 192,   // NYI // Unit(s) starts a quest
    AI_GROUP_UNIT_SAY_PLAYER_RANDOM                 = 193,   // NYI, Cata+? // Unit(s) says something random only to a player
    AI_GROUP_UNIT_YELL_PLAYER_RANDOM                = 194,   // NYI, Cata+? // Unit(s) yells something random only to a player
    AI_GROUP_UNIT_START_LOOPING_ANIM_KIT            = 195,   // Cata+ // Unit(s) start a looping anim kit
    AI_GROUP_UNIT_STOP_LOOPING_ANIM_KIT             = 196,   // Cata+ // Unit(s) stop their looping anim kit
    AI_GROUP_UNIT_PLAY_ONESHOT_ANIM_KIT             = 197,   // Cata+ // Unit(s) play a one-shot anim kit
    AI_GROUP_UNIT_SET_MOVEMENT_ANIM_KIT             = 198,   // Cata+ // Unit(s) set their movement anim kit
    AI_GROUP_UNIT_SET_MELEE_ANIM_KIT                = 199,   // Cata+ // Unit(s) set their melee anim kit
    AI_GROUP_UNIT_INTERACT_SPELL                    = 200,   // NYI, Cata+? // Set InteractSpell for unit(s) in the group
    AI_GROUP_UNIT_INTERACT_SPELL_RESET              = 201,   // NYI, Cata+? // Reset InteractSpell for unit(s) in the group
    AI_GROUP_UNIT_INTERACT_SPELL_CONDITION          = 202,   // NYI, Cata+? // Set InteractSpellCondition for unit(s) in the group
    AI_GROUP_UNIT_INTERACT_SPELL_CONDITION_RESET    = 203,   // NYI, Cata+? // Reset InteractSpellCondition for unit(s) in the group
    AI_GROUP_UNIT_NO_NPC_DAMAGE_BELOW_85_PTC        = 204,   // Cata+ // Set "No NPC damage below 85%" flag for unit(s)
    AI_GROUP_UNIT_NO_NPC_DAMAGE_BELOW_85_PTC_RESET  = 205,   // Cata+ // Reset "No NPC damage below 85%" flag for unit(s)
    AI_GROUP_UNIT_FACE_ANGLE_RELATIVE               = 206,   // NYI // Unit(s) face angle relative to current
    AI_GROUP_UNIT_BOSS_UNIT_FRAMES_PRIORITY         = 207,   // Cata+ // Unit(s) sets his boss unit frames priority
    AI_GROUP_UNIT_BOSS_UNIT_FRAMES_PRIORITY_RESET   = 208,   // Cata+ // Unit(s) resets his boss unit frames priority
    AI_GROUP_UNIT_NO_THREAT_FEEDBACK                = 209,   // NYI // Set "No Threat Feedback" flag for unit(s)
    AI_GROUP_UNIT_NO_THREAT_FEEDBACK_RESET          = 210,   // NYI // Reset "No Threat Feedback" flag for unit(s)
    AI_GROUP_UNIT_CHAT_EMOTE_PLAYER                 = 211,   // NYI // Unit(s) chat emote something to a player
    AI_GROUP_UNIT_CHAT_EMOTE_PLAYER_RANDOM          = 212,   // NYI // Unit(s) chat emote something random to a player
    AI_GROUP_UNIT_EMOTE_PLAYER                      = 213,   // NYI // Unit(s) perform an emote to a player
    AI_GROUP_UNIT_SET_QUEST_LOOT                    = 214,   // NYI // Set the quest loot for a unit
    // ^ 3.3.5a
    AI_GROUP_MAX                                    = 215
};

// EnumeratedString's EnumID 598 and g_actionTriggers
enum UnitActionTriggers
{
    None                        = 0,
    OnReaction                  = 1,    // NYI // Unit detects {$Detection Type}.
    OnEnterCombat               = 2,    // NYI // Unit enters combat.
    OnLeaveCombat               = 3,    // NYI // Unit leaves combat.
    OnCombatTick                = 4,    // NYI // Unit triggers this each heartbeat.
    OnHealthRange               = 5,    // NYI // Unit health is between {#Health Min} and {#Health Max}.
    OnEnergyRange               = 6,    // NYI // Unit mana is between {#Mana Min} and {#Mana Max}.
    OnDeath                     = 7,    // NYI // Unit dies.
    OnSpell                     = 8,    // NYI // Unit is hit by spell {Spell}.
    OnKill                      = 9,    // NYI // Unit kills an enemy target.
    OnSpawn                     = 10,   // NYI // Unit spawns.
    OnEmote                     = 11,   // NYI // Unit receives emote {EmotesText}.
    OnMelee                     = 12,   // NYI // Unit receives a melee attack.
    OnInteract                  = 13,   // NYI // Unit is right clicked.
    OnCombatTrigger             = 14,   // NYI // Unit receives 'combat' trigger {#Trigger ID}.
    // [^ Alpha]
    OnSpellCast                 = 15,   // NYI // Unit casts spell {Spell}.
    OnPickPocket                = 16,   // NYI // Unit is pickpocketed.
    OnSkinned                   = 17,   // NYI // Unit is skinned.
    OnCombatReturn              = 18,   // NYI // Unit returns to its home position after combat.
    OnPathFailing               = 19,   // NYI // Unit fails to path to its target{#AfterSeconds}.
    OnHealthRangeRandom         = 20,   // NYI // Unit is within randomized health range {#Health Min} to {#Health Max}.
    OnEnergyRangeRandom         = 21,   // NYI // Unit is within randomized mana range {#Mana Min} to {#Mana Max}.
    // [^ 1.12.1]
    OnGeneralTrigger            = 22,   // NYI // Unit receives general trigger ID {#Trigger ID}.
    OnDespawn                   = 23,   // NYI // Unit receives a despawn request. (Instantaneous)
    OnSpellFailed               = 24,   // NYI // Unit fails to cast spell {Spell}.
    OnCharmBreak                = 25,   // NYI // Unit ceases to be charmed.
    OnPassengerControlEnd       = 26,   // NYI // Passenger in seat {#Seat Index} stops controlling it.
    OnVehicleReturn             = 27,   // NYI // Passenger in seat {#Seat Index} begins returning towards a vehicle.
    OnVehicleRide               = 28,   // NYI // Passenger in seat {#Seat Index} begins riding a vehicle.
    OnVehicleAbandon            = 29,   // NYI // Passenger in seat {#Seat Index} leaves its vehicle.
    // [^ 2.4.3]
    OnSpellStart                = 30,   // NYI // Unit starts casting spell {Spell}.
    OnAuraApplied               = 31,   // NYI // Unit has aura {Spell} applied.
    OnAuraRemoved               = 32,   // NYI // Unit has aura {Spell} removed.
    OnPassengerRide             = 33,   // NYI // Unit adds a passenger in seat {#Seat Index}.
    OnPassengerAbandon          = 34,   // NYI // Unit removes a passenger in seat {#Seat Index}.
    OnPassengerSpawn            = 35,   // NYI // Unit spawns a passenger in seat {#Seat Index}.
    // [^ 3.3.5]
    // [^ 4.3.4]
    OnLootLockReleased          = 36,   // NYI // Player closes loot window which {$Loot Window}.
    OnChannelStart              = 37,   // NYI // Unit starts channeling spell {Spell}.
    OnChannelInterrupted        = 38,   // NYI // Unit is interrupted channeling spell {Spell}.
    OnChannelFinished           = 39,   // NYI // Unit finishes channeling spell {Spell}.
    OnHealthDepleted            = 40,   // NYI // Unit reaches 0 health (or 1 if unkillable).
    // [^ 7.3.2]
    Max
};

// Custom flags, can't find anything original
enum ActionTriggersFlags
{
    NotRepeatable               = 0x001,   // Trigger is not repeatable
    Unremovable                 = 0x002,   // Trigger will be not removed when action triggers are changed

    ActionTriggersFlagsAll      = (NotRepeatable | Unremovable)
};

// EnumeratedString's EnumID 880. First flag is shown in Action Set editor (Loop)
enum class ActionSetFlags : uint32
{
    Looping                                   = 0x00000001,   // Action set is looping (see example in Action Set editor screenshot)
    Resumable                                 = 0x00000002,   // Makes action set resumable if it was interrupted with a higher priority action set
    PauseForCombat                            = 0x00000004,   // NYI
    NoCorpseHeartbeat                         = 0x00000008,   // NYI
    ChainActionsTogetherWithoutStopping       = 0x00000010,   // NYI
    PauseUntilAllMembersAreDoneReturning      = 0x00000020,   // NYI
    AllowAllActionsWhileDead                  = 0x00000040,   // Allows to start action set in OnDeath trigger. Action set will continue to run even if the unit is dead
    TreatLikeCreatureActionSet                = 0x00000080,   // NYI
    DoNotResetCombatState                     = 0x00000100,   // NYI
    ResetCombatAtStart                        = 0x00000200,   // NYI
    RespectRecursivePriority                  = 0x00000400    // NYI
};

DEFINE_ENUM_FLAG(ActionSetFlags);

// EnumeratedString's EnumID 909. Shown in Action Set editor (Priority: Medium)
enum class ActionSetPriorityType : uint8
{
    Any                                       = 0,
    Low                                       = 1,
    LowToMid                                  = 2,
    MidToHigh                                 = 3,
    High                                      = 4,
    Medium                                    = 5,
    Max
};

// From g_aiGroupUnits. Max Unit should be max size of already existing formation
enum class AIGroupUnit : uint8
{
    RandomUnit                                = 0,
    AllUnits                                  = 1,
    Unit1                                     = 2,
    Unit2                                     = 3,
    Unit3                                     = 4,
    Unit4                                     = 5,
    Unit5                                     = 6,
    Unit6                                     = 7,
    Unit7                                     = 8,
    Unit8                                     = 9,
    Unit9                                     = 10,
    Unit10                                    = 11,
    Max
};

// Custom
enum AIGroupTargetType : uint8
{
    AIGROUP_TARGET_NONE                           = 0,    // NONE
    AIGROUP_TARGET_SELF                           = 1,    // Self
    AIGROUP_TARGET_VICTIM                         = 2,    // Our current target (ie: highest aggro)
    AIGROUP_TARGET_HOSTILE_SECOND_AGGRO           = 3,    // Second highest aggro, maxdist, playerOnly, powerType + 1
    AIGROUP_TARGET_HOSTILE_LAST_AGGRO             = 4,    // Dead last on aggro, maxdist, playerOnly, powerType + 1
    AIGROUP_TARGET_HOSTILE_RANDOM                 = 5,    // Just any random target on our threat list, maxdist, playerOnly, powerType + 1
    AIGROUP_TARGET_HOSTILE_RANDOM_NOT_TOP         = 6,    // Any random target except top threat, maxdist, playerOnly, powerType + 1
    AIGROUP_TARGET_ACTION_INVOKER                 = 7,    // Unit who caused this Event to occur
    AIGROUP_TARGET_UNUSED                         = 8,    // Unused
    AIGROUP_TARGET_CREATURE_RANGE                 = 9,    // CreatureEntry(0any), minDist, maxDist
    AIGROUP_TARGET_CREATURE_GUID                  = 10,   // guid, entry
    AIGROUP_TARGET_CREATURE_DISTANCE              = 11,   // CreatureEntry(0any), maxDist
    AIGROUP_TARGET_STORED                         = 12,   // Unused
    AIGROUP_TARGET_GAMEOBJECT_RANGE               = 13,   // entry(0any), min, max
    AIGROUP_TARGET_GAMEOBJECT_GUID                = 14,   // guid, entry
    AIGROUP_TARGET_GAMEOBJECT_DISTANCE            = 15,   // entry(0any), maxDist
    AIGROUP_TARGET_INVOKER_PARTY                  = 16,   // invoker's party members
    AIGROUP_TARGET_PLAYER_RANGE                   = 17,   // min, max
    AIGROUP_TARGET_PLAYER_DISTANCE                = 18,   // maxDist
    AIGROUP_TARGET_CLOSEST_CREATURE               = 19,   // CreatureEntry(0any), maxDist, dead?
    AIGROUP_TARGET_CLOSEST_GAMEOBJECT             = 20,   // entry(0any), maxDist
    AIGROUP_TARGET_CLOSEST_PLAYER                 = 21,   // maxDist
    AIGROUP_TARGET_ACTION_INVOKER_VEHICLE         = 22,   // Unit's vehicle who caused this Event to occur
    AIGROUP_TARGET_OWNER_OR_SUMMONER              = 23,   // Unit's owner or summoner, Use Owner/Charmer of this unit
    AIGROUP_TARGET_THREAT_LIST                    = 24,   // All units on creature's threat list, maxdist
    AIGROUP_TARGET_CLOSEST_ENEMY                  = 25,   // maxDist, playerOnly
    AIGROUP_TARGET_CLOSEST_FRIENDLY               = 26,   // maxDist, playerOnly
    AIGROUP_TARGET_LOOT_RECIPIENTS                = 27,   // all players that have tagged this creature (for kill credit)
    AIGROUP_TARGET_FARTHEST                       = 28,   // maxDist, playerOnly, isInLos
    AIGROUP_TARGET_VEHICLE_PASSENGER              = 29,   // seatMask (0 - all seats)
    AIGROUP_TARGET_CLOSEST_UNSPAWNED_GAMEOBJECT   = 30,   // entry(0any), maxDist

    AIGROUP_TARGET_END                            = 31
};

struct AIGroupTarget
{
    AIGroupTarget(AIGroupTargetType targetType = AIGROUP_TARGET_NONE, uint32 param1 = 0, uint32 param2 = 0, uint32 param3 = 0, uint32 param4 = 0) : Type(targetType)
    {
        Raw.Param1 = param1;
        Raw.Param2 = param2;
        Raw.Param3 = param3;
        Raw.Param4 = param4;
    }

    AIGroupTargetType Type;

    union
    {
        struct
        {
            uint32 MaxDist;
            bool PlayerOnly;
            uint32 PowerType;
        } HostileRandom;

        struct
        {
            uint32 Creature;
            uint32 MinDist;
            uint32 MaxDist;
            uint32 MaxSize;
        } UnitRange;

        struct
        {
            uint32 DbGuid;
            uint32 Entry;
        } UnitGuid;

        struct
        {
            uint32 Creature;
            uint32 Dist;
            uint32 MaxSize;
        } UnitDistance;

        struct
        {
            uint32 Id;
        } Stored;

        struct
        {
            uint32 Entry;
            uint32 MinDist;
            uint32 MaxDist;
            uint32 MaxSize;
        } GameObjectRange;

        struct
        {
            uint32 DbGuid;
            uint32 Entry;
        } GameObjectGuid;

        struct
        {
            uint32 Entry;
            uint32 Dist;
            uint32 MaxSize;
        } GameObjectDistance;

        struct
        {
            uint32 MinDist;
            uint32 MaxDist;
        } PlayerRange;

        struct
        {
            uint32 Dist;
        } PlayerDistance;

        struct
        {
            uint32 Entry;
            uint32 Dist;
            bool Dead;
        } ClosestCreature;

        struct
        {
            uint32 Entry;
            uint32 Dist;
        } ClosestGameObject;

        struct
        {
            uint32 MaxDist;
            bool PlayerOnly;
        } ClosestUnit;

        struct
        {
            bool UseCharmerOrOwner;
        } Owner;

        struct
        {
            uint32 MaxDist;
        } ThreatList;

        struct
        {
            uint32 SeatMask;
        } Vehicle;

        struct
        {
            uint32 MaxDist;
            bool PlayerOnly;
            bool IsInLos;
        } Farthest;

        struct
        {
            uint32 Param1;
            uint32 Param2;
            uint32 Param3;
            uint32 Param4;
        } Raw;
    };
};

struct ActionTriggersHolder
{
    ActionTriggersHolder() : Id(0), Index(0), Chance(0), Flags(0), CombatCondition(-1), TriggerId(0),
    TriggerParam1(0), TriggerParam2(0), ActionSetId(0), RepeatMin(0), RepeatMax(0), RepeatTimer(0), IsTriggerActive(false), IsTriggerUsed(false) { }

    uint32 Id;
    uint16 Index;
    uint8 Chance;
    uint32 Flags;
    int32 CombatCondition;
    uint8 TriggerId;
    uint32 TriggerParam1;
    uint32 TriggerParam2;
    uint32 ActionSetId;
    uint32 RepeatMin;
    uint32 RepeatMax;
    uint32 RepeatTimer;
    bool IsTriggerActive;
    bool IsTriggerUsed;
};

struct ActionSetEventHolder
{
    ActionSetEventHolder() : Id(0), Index(0), Type(0), Unit(0), Point(0), Path(0), TimeA(0), MoveSpeed(0),
    StringId(""), TimeB(0), LinearPath(0), CircularPath(0), FlightPath(0), TargetType(0), TargetParam1(0),
    TargetParam2(0), TargetParam3(0), TargetParam4(0), Extra0(0), Extra1(0), Extra2(0), Extra3(0), Extra4(0) { }

    uint32 Id;
    uint16 Index;
    uint16 Type;
    uint8 Unit;
    uint32 Point;
    uint32 Path;
    uint32 TimeA;
    uint8 MoveSpeed;
    std::string StringId;
    uint32 TimeB;
    bool LinearPath;
    bool CircularPath;
    bool FlightPath;
    uint8 TargetType;
    uint32 TargetParam1;
    uint32 TargetParam2;
    uint32 TargetParam3;
    uint32 TargetParam4;
    double Extra0;
    double Extra1;
    double Extra2;
    double Extra3;
    double Extra4;
};

struct ActionSetHolder
{
    ActionSetHolder() : Id(0), Flags(0), Priority(0), Name("") { }

    uint32 Id;
    uint32 Flags;
    uint8 Priority;
    std::string Name;
};

typedef std::vector<ActionTriggersHolder> AIGroupEventList;
typedef std::unordered_map<uint32, AIGroupEventList> AIGroupEventMap;
typedef std::vector<ActionSetEventHolder> AIGroupActionSet;
typedef std::unordered_map<uint32, AIGroupActionSet> AIGroupActionSetMap;
typedef std::vector<WorldObject*> AIGroupObjectVector;

struct AIGroupActiveActionSet
{
    AIGroupActiveActionSet(uint32 id, AIGroupActionSet actions, ObjectGuid invokerGuid) :
        Id(id), Actions(std::move(actions)), InvokerGuid(invokerGuid), CurrentAction(0), ActionTimer(0), ActionStarted(false) { }

    uint32 Id;
    AIGroupActionSet Actions;
    ObjectGuid InvokerGuid;
    uint16 CurrentAction;
    uint32 ActionTimer;
    bool ActionStarted;
};

typedef std::vector<AIGroupActiveActionSet> AIGroupActiveActionSetList;

class TC_GAME_API AIGroupMgr
{
    private:
        AIGroupMgr() { }
        ~AIGroupMgr() { }

        std::unordered_map<uint32, std::string> _actionTriggerNames;
        std::unordered_map<uint32, ActionSetHolder> _actionSets;
        AIGroupEventMap mEventMap;
        AIGroupActionSetMap mActionSetMap;

    public:
        static AIGroupMgr* Instance();

        void LoadActionSetsFromDB();
        void LoadActionSetsNamesFromDB();
        void LoadActionTriggersFromDB();
        void LoadActionTriggersNamesFromDB();

        struct ActionTriggerTypeInfo
        {
            char const* Name;
            bool HasTriggerParam1;
            bool HasTriggerParam2;
        };
        static ActionTriggerTypeInfo const StaticActionTriggerTypeData[UnitActionTriggers::Max];

        std::string GetTriggersName(uint32 triggersId) const;
        std::string GetActionSetName(uint32 actionSetId) const;
        uint8 GetActionSetPriority(uint32 actionSetId) const;
        uint32 GetActionSetFlags(uint32 actionSetId) const;

        uint8 GetPriorityPercentForPriorityType(ActionSetPriorityType type);

        AIGroupEventList GetScript(uint32 triggersId);
        AIGroupActionSet GetActionSet(uint32 actionSetId);
};

#define sAIGroupMgr AIGroupMgr::Instance()

#endif
