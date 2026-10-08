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
#include "ObjectGuid.h"
#include <initializer_list>
#include <string_view>
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
    AI_GROUP_UNIT_UNINTERACTIBLE                    = 29,    // NYI // Set "Uninteractible" flag for unit(s); old AI_GROUP_BEASTMASTER_ON
    AI_GROUP_UNIT_UNINTERACTIBLE_RESET              = 30,    // NYI // Reset "Uninteractible" flag for unit(s); old AI_GROUP_BEASTMASTER_OFF
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
    AI_GROUP_UNIT_CAST_RANDOM_UNIT                  = 215,   // NYI // Unit(s) cast a spell on a random unit
    AI_GROUP_UNIT_CAST_RANDOM_PLAYER                = 216,   // NYI // Unit(s) cast a spell on a random player
    AI_GROUP_UNIT_CAST_OTHER_UNIT                   = 217,   // NYI // Unit(s) tell some other unit to cast a spell
    AI_GROUP_MOVE_CIRCLE_RELATIVE                   = 218,   // NYI // Move in a circle relative to position
    AI_GROUP_RETURN_HOME_INSTANTLY                  = 219,   // NYI // Move everybody back to spawn positions instantly
    AI_GROUP_ABORT_ACTION_SET_NO_STRINGID           = 220,   // NYI // Abort action set if stringID is not found
    AI_GROUP_ABORT_ACTION_SET_COMBAT_CONDITION_TRUE = 221,   // NYI // Abort action set if combat condition is true
    AI_GROUP_FORCE_COMBAT                           = 222,   // NYI // Force combat with a unit
    AI_GROUP_STOP_FORCE_COMBAT                      = 223,   // NYI // Stop Force combat
    AI_GROUP_UNIT_UNTARGETABLE_BY_CLIENT            = 224,   // NYI // Unit(s) Set Untargetable By Client
    AI_GROUP_UNIT_UNTARGETABLE_BY_CLIENT_RESET      = 225,   // NYI // Unit(s) Reset Untargetable By Client
    AI_GROUP_UNIT_NO_MELEE_APPROACH                 = 226,   // NYI // Set "No Melee Approach" flag for unit(s) in the group
    AI_GROUP_UNIT_NO_MELEE_APPROACH_RESET           = 227,   // NYI // Reset "No Melee Approach" flag for unit(s) in the group
    AI_GROUP_UNIT_RAID_LOCK_TAP_LIST                = 228,   // NYI // Unit(s) Raid Lock everyone on their tap list
    AI_GROUP_UNIT_CANNOT_TURN                       = 229,   // NYI // Set "Cannot Turn" flag for unit(s) in the group
    AI_GROUP_UNIT_CANNOT_TURN_RESET                 = 230,   // NYI // Reset "Cannot Turn" flag for unit(s) in the group
    AI_GROUP_UNIT_PREFER_NPCS_ENEMIES               = 231,   // NYI // Set "Prefer NPCs When Searching For Enemies" flag for unit(s) in the group
    AI_GROUP_UNIT_PREFER_NPCS_ENEMIES_RESET         = 232,   // NYI // Reset "Prefer NPCs When Searching For Enemies" flag for unit(s) in the group
    AI_GROUP_OBJECT_FACTION                         = 233,   // NYI // Change faction template for object(s)
    AI_GROUP_OBJECT_FACTION_RESET                   = 234,   // NYI // Reset faction template for object(s)
    AI_GROUP_UNIT_PERFORM_SPELL_VISUAL_KIT          = 235,   // NYI // Unit(s) perform spell visual kit on self
    AI_GROUP_UNIT_PERFORM_SPELL_VISUAL              = 236,   // NYI // Unit(s) perform spell visual
    AI_GROUP_UNIT_PERFORM_SPELL_VISUAL_ACTIONS      = 237,   // NYI // Unit(s) perform spell visual and trigger actions
    AI_GROUP_UNIT_NO_LEAVECOMBAT_STATE_RESTORE      = 238,   // NYI // Unit(s) Set "No LeaveCombat State Restore" flag
    AI_GROUP_OBJECT_STRINGID                        = 239,   // NYI // Set the string ID for object(s)
    AI_GROUP_OBJECT_STRINGID_RESET                  = 240,   // NYI // Reset the string ID for object(s)
    AI_GROUP_UNIT_DESPAWN_PERSISTENT_AURA_OBJECTS   = 241,   // NYI // Unit(s) despawn persistent area aura objects
    AI_GROUP_UNIT_DEFAULT_MOUNT                     = 242,   // NYI // Unit(s) set the default mount
    AI_GROUP_UNIT_DEFAULT_MOUNT_RESET               = 243,   // NYI // Unit(s) reset the default mount
    AI_GROUP_ABORT_ACTION_SET_FOUND_STRINGID        = 244,   // NYI // Abort action set if stringID is found
    AI_GROUP_UNSUPPRESS_NPC_GREETINGS               = 245,   // NYI // NPC Greetings - Un-Suppress them
    AI_GROUP_SUPPRESS_NPC_GREETINGS                 = 246,   // NYI // NPC Greetings - Suppress Them
    AI_GROUP_UNIT_CLEAR_BOSS_EMOTES                 = 247,   // NYI // Unit(s) clears boss emotes
    AI_GROUP_UNIT_CLEAR_BOSS_EMOTES_ZONE            = 248,   // NYI // Unit(s) clears boss emotes for the zone
    AI_GROUP_UNIT_CLEAR_BOSS_EMOTES_PLAYER          = 249,   // NYI // Unit(s) clears boss emotes for a player
    AI_GROUP_UNIT_INTERACT_WHILE_HOSTILE            = 250,   // NYI // Unit(s) Set Interact While Hostile
    AI_GROUP_UNIT_INTERACT_WHILE_HOSTILE_RESET      = 251,   // NYI // Unit(s) Reset Interact While Hostile
    AI_GROUP_UNIT_MODEL_HIGHLIGHT_SUPPRESSION       = 252,   // NYI // Unit(s) set the model highlight suppression
    AI_GROUP_UNIT_MODEL_HIGHLIGHT_SUPPRESSION_RESET = 253,   // NYI // Unit(s) reset the model highlight suppression
    AI_GROUP_FOLLOW_TAXI_PATH                       = 254,   // NYI // Follow a taxi path
    AI_GROUP_FOLLOW_TAXI_PATH_RELATIVE              = 255,   // NYI // Follow a taxi path relative
    AI_GROUP_START_DUNGEON_ENCOUNTER                = 256,   // NYI // Start a Dungeon Encounter
    AI_GROUP_END_DUNGEON_ENCOUNTER                  = 257,   // NYI // End a Dungeon Encounter
    // ^ 4.3.4
    AI_GROUP_UNIT_WILD_BATTLEPET_LEVEL              = 258,   // NYI // Unit(s) set Wild BattlePet Level
    AI_GROUP_UNIT_WILD_BATTLEPET_LEVEL_RESET        = 259,   // NYI // Unit(s) reset Wild BattlePet Level
    AI_GROUP_UNIT_TRACK_PLAYER_STAT                 = 260,   // NYI // Unit(s) track player stat
    AI_GROUP_UNIT_CANNOT_PENETRATE_WATER            = 261,   // NYI // Set "Cannot Penetrate Water" flag for unit(s) in the group
    AI_GROUP_UNIT_CANNOT_PENETRATE_WATER_RESET      = 262,   // NYI // Reset "Cannot Penetrate Water" flag for unit(s) in the group
    AI_GROUP_UNIT_DESPAWN_STRINGID                  = 263,   // NYI // Unit(s) Despawn units/objects matching string ID
    AI_GROUP_UNIT_SET_SAFE_LOCATION                 = 264,   // NYI // Unit(s) Set Safe Location
    AI_GROUP_UNIT_TREAT_UNIT_AS_RAID_UNIT           = 265,   // NYI // Set "Treat Unit As Raid Unit" flag for unit(s)
    AI_GROUP_UNIT_TREAT_UNIT_AS_RAID_UNIT_RESET     = 266,   // NYI // Reset "Treat Unit As Raid Unit" flag for unit(s)
    AI_GROUP_UNIT_DESPAWN_SUMMONED_AREA_TRIGGERS    = 267,   // NYI // Unit(s) Despawn all summoned area triggers
    AI_GROUP_UNIT_ADD_PERMANENT_WORLD_EFFECT        = 268,   // NYI // Add permanent World Effect to unit(s)
    AI_GROUP_UNIT_REMOVE_PERMANENT_WORLD_EFFECT     = 269,   // NYI // Remove permanent World Effect from unit(s)
    AI_GROUP_UNIT_CAST_WITH_POINTS_OTHER_UNIT       = 270,   // NYI // Unit(s) tell some other unit to cast a spell with points
    AI_GROUP_UNIT_SET_ANCHOR_POINT                  = 271,   // NYI // Unit(s) Set Anchor Point
    AI_GROUP_CIRCLE_UNIT                            = 272,   // NYI // Circle a Unit
    AI_GROUP_RUN_SPELL_SCRIPT                       = 273,   // NYI // Run a spell script
    AI_GROUP_TURN_IN_PLACE_DEGREES                  = 274,   // NYI // Turn in Place(Degrees)
    AI_GROUP_TURN_IN_PLACE_TIMED                    = 275,   // NYI // Turn in Place(Timed)
    AI_GROUP_UNIT_PREFER_UNENGAGED_TARGETS          = 276,   // NYI // Set "Prefer Unengaged Targets" flag for unit(s) in the group
    AI_GROUP_UNIT_GENERATE_SPAWNGROUP_EVENT         = 277,   // NYI // Unit(s) in the group generates a spawngroup event
    AI_GROUP_PUSH_ACTIONSET                         = 278,   // NYI // Push Actionset
    // ^ 6.0.1 Build 18125
    AI_GROUP_MOVE_ON_PATH_GRAPH_TO_POINT            = 279,   // NYI // Move on path graph to point
    AI_GROUP_TRIGGER_ACTIONS_ON_SELF                = 280,   // NYI // Trigger actions on self
    AI_GROUP_UNIT_EJECT_PASSENGER                   = 281,   // NYI // Unit(s) eject passenger
    AI_GROUP_PERFORM_ACTIONSET                      = 282,   // NYI // Perform actionset
    AI_GROUP_UNIT_PAUSE_SPELL_COOLDOWNS             = 283,   // NYI // Unit(s) Pause Spell Cooldowns
    AI_GROUP_UNIT_RESUME_SPELL_COOLDOWNS            = 284,   // NYI // Unit(s) Resume Spell Cooldowns
    AI_GROUP_UNIT_TRIGGER_SPELL_CATEGORY_COOLDOWN   = 285,   // NYI // Unit(s) Trigger a Spell Category Cooldown
    AI_GROUP_UNIT_PLAY_SOUND_ON_ITSELF_SPEAKERBOT   = 286,   // NYI // Unit(s) Plays a sound on itself [Speakerbot]
    AI_GROUP_UNIT_STOP_SPEAKERBOT_SOUND             = 287,   // NYI // Unit(s) Stops the [Speakerbot] sound it is playing
    // ^ 6.0.3 Build 19342
    // ^ 6.1.2 Build 19865
    // ^ 6.2.0 Build 20253
    AI_GROUP_UNIT_BECOME_PERSONAL_INVIS_CLONE       = 288,   // NYI // Unit(s) Becomes a personal invis clone for triggering player
    AI_GROUP_MOVE_ON_PATH_GRAPH_TO_GUID             = 289,   // NYI // Move on path graph to unit or game object
    AI_GROUP_MOVE_ON_PATH_GRAPH_MULTIPLE_POINTS     = 290,   // NYI // Move on path graph - multiple points
    AI_GROUP_UNIT_NEVER_EVADE                       = 291,   // NYI // Unit(s) "Never Evade" flag
    AI_GROUP_UNIT_NEVER_EVADE_RESET                 = 292,   // NYI // Reset Unit(s) "Never Evade" flag
    AI_GROUP_UNIT_DONT_LEAVE_COMBAT                 = 293,   // NYI // Unit(s) Set "Don't leave combat" flag
    AI_GROUP_UNIT_CANCEL_CURRENT_SPELL              = 294,   // NYI // Unit(s) Cancel Current Spell
    AI_GROUP_UNIT_SAY_GAME_REGION                   = 295,   // NYI // Unit(s) say something to the entire game region
    AI_GROUP_UNIT_SAY_GAME_REGION_RANDOM            = 296,   // NYI // Unit(s) say something random to the entire game region
    AI_GROUP_UNIT_YELL_GAME_REGION                  = 297,   // NYI // Unit(s) yell something to the entire game region
    AI_GROUP_UNIT_YELL_GAME_REGION_RANDOM           = 298,   // NYI // Unit(s) yell something random to the entire game region
    AI_GROUP_COMBAT_POSITION                        = 299,   // NYI // Combat Position
    AI_GROUP_COMBAT_CHASE                           = 300,   // NYI // Combat Chase
    AI_GROUP_UNIT_DONT_DISMISS_ON_FLYING_MOUNT      = 301,   // NYI // Set "Don't Dismiss On Flying Mount" for unit(s)
    AI_GROUP_UNIT_DONT_DISMISS_ON_FLYING_MOUNT_RES  = 302,   // NYI // Reset "Don't Dismiss On Flying Mount" for unit(s)
    // ^ 7.3.5 Build 25717
    AI_GROUP_RESERVED_1                             = 303,
    AI_GROUP_RESERVED_2                             = 304,
    AI_GROUP_RESERVED_3                             = 305,
    AI_GROUP_RESERVED_4                             = 306,
    AI_GROUP_RESERVED_5                             = 307,
    AI_GROUP_RESERVED_6                             = 308,
    AI_GROUP_RESERVED_7                             = 309,
    AI_GROUP_RESERVED_8                             = 310,
    AI_GROUP_RESERVED_9                             = 311,
    AI_GROUP_RESERVED_10                            = 312,
    AI_GROUP_RESERVED_11                            = 313,
    AI_GROUP_RESERVED_12                            = 314,
    AI_GROUP_RESERVED_13                            = 315,
    AI_GROUP_RESERVED_14                            = 316,
    AI_GROUP_RESERVED_15                            = 317,
    AI_GROUP_RESERVED_16                            = 318,
    AI_GROUP_RESERVED_17                            = 319,
    AI_GROUP_RESERVED_18                            = 320,
    AI_GROUP_RESERVED_19                            = 321,
    AI_GROUP_RESERVED_20                            = 322,
    AI_GROUP_RESERVED_21                            = 323,
    AI_GROUP_RESERVED_22                            = 324,
    AI_GROUP_RESERVED_23                            = 325,
    AI_GROUP_RESERVED_24                            = 326,
    AI_GROUP_RESERVED_25                            = 327,
    AI_GROUP_RESERVED_26                            = 328,
    AI_GROUP_RESERVED_27                            = 329,
    AI_GROUP_RESERVED_28                            = 330,
    AI_GROUP_RESERVED_29                            = 331,
    AI_GROUP_RESERVED_30                            = 332,
    AI_GROUP_RESERVED_31                            = 333,
    AI_GROUP_RESERVED_32                            = 334,
    AI_GROUP_RESERVED_33                            = 335,
    AI_GROUP_RESERVED_34                            = 336,
    AI_GROUP_RESERVED_35                            = 337,
    AI_GROUP_RESERVED_36                            = 338,
    AI_GROUP_RESERVED_37                            = 339,
    AI_GROUP_RESERVED_38                            = 340,
    AI_GROUP_RESERVED_39                            = 341,
    AI_GROUP_RESERVED_40                            = 342,
    AI_GROUP_RESERVED_41                            = 343,
    AI_GROUP_RESERVED_42                            = 344,
    AI_GROUP_RESERVED_43                            = 345,
    AI_GROUP_RESERVED_44                            = 346,
    AI_GROUP_RESERVED_45                            = 347,
    AI_GROUP_RESERVED_46                            = 348,
    AI_GROUP_RESERVED_47                            = 349,
    AI_GROUP_RESERVED_48                            = 350,
    AI_GROUP_RESERVED_49                            = 351,
    AI_GROUP_RESERVED_50                            = 352,
    AI_GROUP_RESERVED_51                            = 353,
    AI_GROUP_RESERVED_52                            = 354,
    AI_GROUP_RESERVED_53                            = 355,
    AI_GROUP_RESERVED_54                            = 356,
    AI_GROUP_RESERVED_55                            = 357,
    AI_GROUP_RESERVED_56                            = 358,
    AI_GROUP_RESERVED_57                            = 359,
    AI_GROUP_RESERVED_58                            = 360,
    AI_GROUP_RESERVED_59                            = 361,
    AI_GROUP_RESERVED_60                            = 362,
    AI_GROUP_RESERVED_61                            = 363,
    AI_GROUP_RESERVED_62                            = 364,
    AI_GROUP_RESERVED_63                            = 365,
    AI_GROUP_RESERVED_64                            = 366,
    AI_GROUP_RESERVED_65                            = 367,
    AI_GROUP_RESERVED_66                            = 368,
    AI_GROUP_RESERVED_67                            = 369,
    AI_GROUP_RESERVED_68                            = 370,
    AI_GROUP_RESERVED_69                            = 371,
    AI_GROUP_RESERVED_70                            = 372,
    AI_GROUP_RESERVED_71                            = 373,
    AI_GROUP_RESERVED_72                            = 374,
    AI_GROUP_RESERVED_73                            = 375,
    AI_GROUP_RESERVED_74                            = 376,
    AI_GROUP_RESERVED_75                            = 377,
    AI_GROUP_RESERVED_76                            = 378,
    AI_GROUP_RESERVED_77                            = 379,
    AI_GROUP_RESERVED_78                            = 380,
    AI_GROUP_RESERVED_79                            = 381,
    AI_GROUP_RESERVED_80                            = 382,
    AI_GROUP_RESERVED_81                            = 383,
    AI_GROUP_RESERVED_82                            = 384,
    AI_GROUP_RESERVED_83                            = 385,
    AI_GROUP_RESERVED_84                            = 386,
    AI_GROUP_RESERVED_85                            = 387,
    AI_GROUP_RESERVED_86                            = 388,
    AI_GROUP_RESERVED_87                            = 389,
    AI_GROUP_RESERVED_88                            = 390,
    AI_GROUP_RESERVED_89                            = 391,
    AI_GROUP_RESERVED_90                            = 392,
    AI_GROUP_RESERVED_91                            = 393,
    AI_GROUP_RESERVED_92                            = 394,
    AI_GROUP_RESERVED_93                            = 395,
    AI_GROUP_RESERVED_94                            = 396,
    AI_GROUP_RESERVED_95                            = 397,
    AI_GROUP_RESERVED_96                            = 398,
    AI_GROUP_RESERVED_97                            = 399,
    AI_GROUP_RESERVED_98                            = 400,
    AI_GROUP_RESERVED_99                            = 401,
    AI_GROUP_RESERVED_100                           = 402,
    // ^ Reserved
    AI_GROUP_CU_1                                   = 403,
    AI_GROUP_CU_2                                   = 404,
    AI_GROUP_CU_3                                   = 405,
    AI_GROUP_CU_4                                   = 406,
    AI_GROUP_CU_5                                   = 407,
    AI_GROUP_CU_6                                   = 408,
    AI_GROUP_CU_7                                   = 409,
    AI_GROUP_CU_8                                   = 410,
    AI_GROUP_CU_9                                   = 411,
    AI_GROUP_CU_10                                  = 412,
    // ^ Custom
    AI_GROUP_MAX                                    = 413
};

// From g_groupActionsAbbr
constexpr std::string_view AIGroupActionsAbbr[] =
{
    "Spawn",                               // 0
    "Idle",                                // 1
    "Move",                                // 2
    "Teleport",                            // 3
    "WRpoint",                             // 4
    "WRadius",                             // 5
    "WPoly",                               // 6
    "FGUID",                               // 7
    "FPath",                               // 8
    "PLinear",                             // 9
    "PCirc",                               // 10
    "GGUID",                               // 11
    "GArea",                               // 12
    "Formation",                           // 13
    "ChangeMode",                          // 14
    "USay",                                // 15
    "UCast",                               // 16
    "UActivateObject",                     // 17
    "CEvent",                              // 18
    "Despawn",                             // 19
    "Radius",                              // 20
    "Faction",                             // 21
    "UFacing",                             // 22
    "UFaceGUID",                           // 23
    "UEmote",                              // 24
    "MGUID",                               // 25
    "AGUID",                               // 26
    "UMount",                              // 27
    "UDismount",                           // 28
    "UUninteractible",                     // 29
    "UUninteractibleReset",                // 30
    "UMode",                               // 31
    "UModeReset",                          // 32
    "UFaction",                            // 33
    "UFactionReset",                       // 34
    "URadius",                             // 35
    "URadiusReset",                        // 36
    "QuestComplete",                       // 37
    "UQuestGiver",                         // 38
    "UTrainer",                            // 39
    "SPath",                               // 40
    "PAction",                             // 41
    "GoHome",                              // 42
    "USayRandom",                          // 43
    "UYell",                               // 44
    "UYellRandom",                         // 45
    "UMItem",                              // 46
    "UMItemReset",                         // 47
    "UChatEmote",                          // 48
    "UChatEmoteRandom",                    // 49
    "UEvent",                              // 50
    "VendorIdle",                          // 51
    "QuestFailed",                         // 52
    "UTriggers",                           // 53
    "UTriggersReset",                      // 54
    "ULeaveCombat",                        // 55
    "IdleCombatStart",                     // 56
    "IdleCombatStop",                      // 57
    "UImmunePC",                           // 58
    "UImmunePCReset",                      // 59
    "UImmuneNPC",                          // 60
    "UImmuneNPCReset",                     // 61
    "UUnkillable",                         // 62
    "UUnkillableReset",                    // 63
    "USpells",                             // 64
    "USpellsReset",                        // 65
    "AttackAllInstance",                   // 66
    "ULocalEvent",                         // 67
    "UBLocalEvent",                        // 68
    "UFlee",                               // 69
    "URetreat",                            // 70
    "OChatEmote",                          // 71
    "OChatEmoteRandom",                    // 72
    "Avoid",                               // 73
    "AvoidGUID",                           // 74
    "OActivate",                           // 75
    "UActivateOOO",                        // 76
    "UStringID",                           // 77
    "UStringIDReset",                      // 78
    "PeriodicEvent",                       // 79
    "UOItem",                              // 80
    "UOItemReset",                         // 81
    "URItem",                              // 82
    "URItemReset",                         // 83
    "USheathe",                            // 84
    "UUnsheathe",                          // 85
    "UCancelCast",                         // 86
    "UCancelAura",                         // 87
    "UFinishCast",                         // 88
    "EmoteState",                          // 89
    "UCallForHelp",                        // 90
    "FlightPath",                          // 91
    "CombatTrigger",                       // 92
    // Above from Alpha, below generated from action names
    "UGossip",                             // 93
    "UKillCredit",                         // 94
    "UWhisper",                            // 95
    "UWhisperRandom",                      // 96
    "UNoLoot",                             // 97
    "UNoLootReset",                        // 98
    "UNoXP",                               // 99
    "UNoXPReset",                          // 100
    "UPVPEnabling",                        // 101
    "UPVPEnablingReset",                   // 102
    "UPlayMusic",                          // 103
    "UPlaySound",                          // 104
    "USetLoot",                            // 105
    "UFloating",                           // 106
    "UFloatingReset",                      // 107
    "OPlayMusic",                          // 108
    "OPlaySound",                          // 109
    "SpawnForced",                         // 110
    "UUnsheatheRange",                     // 111
    "UChatEmoteZone",                      // 112
    "UChatEmoteZoneRandom",                // 113
    "UYellZone",                           // 114
    "UYellZoneRandom",                     // 115
    "UPlayMusicZone",                      // 116
    "UPlaySoundZone",                      // 117
    "OChatEmoteZone",                      // 118
    "OChatEmoteZoneRandom",                // 119
    "OPlayMusicZone",                      // 120
    "OPlaySoundZone",                      // 121
    "UIgnoreCombat",                       // 122
    "UIgnoreCombatReset",                  // 123
    "RandomActionSet",                     // 124
    "RestartActionsWSE",                   // 125
    "AbortActionSetWSE",                   // 126
    "UBossEmote",                          // 127
    "UBossEmoteZone",                      // 128
    "CombatTriggerNearestUnit",            // 129
    "UCastFailure",                        // 130
    "UNoReputation",                       // 131
    "UNoReputationReset",                  // 132
    "SplinePathLoop",                      // 133
    "UVendor",                             // 134
    "UResetVendorLists",                   // 135
    "TriggerActionsUnits",                 // 136
    "TriggerActionsNearestUnit",           // 137
    "USayZone",                            // 138
    "USayZoneRandom",                      // 139
    "USendLocalEventSelf",                 // 140
    "USessile",                            // 141
    "USessileReset",                       // 142
    "URaidLock",                           // 143
    "URaidLockReset",                      // 144
    "QuestCompleteTriggeringPlayer",       // 145
    "QuestClearedTriggeringPlayer",        // 146
    "UChatParty",                          // 147
    "UClearCooldowns",                     // 148
    "UPlayTargetedSound",                  // 149
    "UPlayTargetedMusic",                  // 150
    "UResetInitialSpellCooldowns",         // 151
    "UNoMelee",                            // 152
    "UNoMeleeReset",                       // 153
    "FallToGround",                        // 154
    "UUpdateInteraction",                  // 155
    "UBossWhisper",                        // 156
    "UBossWhisperRandom",                  // 157
    "MoveRelative",                        // 158
    "UDontClearTap",                       // 159
    "UKillCreditTap",                      // 160
    "UCastWithPoints",                     // 161
    "URideVehicle",                        // 162
    "UAbandonVehicle",                     // 163
    "VehicleRecallOrRespawnPassengers",    // 164
    "PlayMovie",                           // 165
    "JumpPoint",                           // 166
    "JumpGUID",                            // 167
    "MoveToThenJump",                      // 168
    "VehicleRecallLivingPassengers",       // 169
    "VehicleRespawnAllPassengers",         // 170
    "UFatalFallDistance",                  // 171
    "UFatalFallDistanceReset",             // 172
    "USetAnimTier",                        // 173
    "USendTapList",                        // 174
    "UGetTapList",                         // 175
    "UHoverHeight",                        // 176
    "UHoverHeightReset",                   // 177
    "TierTransitionLand",                  // 178
    "TierTransitionTakeOff",               // 179
    "TierTransitionMoveTo",                // 180
    "TierTransitionMoveToGUID",            // 181
    "TierTransitionFollowPath",            // 182
    "UKillCreditPlayer",                   // 183
    "SuspendTriggerAction",                // 184
    "UVehicleRecord",                      // 185
    "UVehicleRecordReset",                 // 186
    "UImmunities",                         // 187
    "UImmunitiesReset",                    // 188
    "SendContentAlert",                    // 189
    "USayPlayer",                          // 190
    "UYellPlayer",                         // 191
    "UStartQuest",                         // 192
    "USayPlayerRandom",                    // 193
    "UYellPlayerRandom",                   // 194
    "UStartLoopingAnimKit",                // 195
    "UStopLoopingAnimKit",                 // 196
    "UPlayOneshotAnimKit",                 // 197
    "USetMovementAnimKit",                 // 198
    "USetMeleeAnimKit",                    // 199
    "UInteractSpell",                      // 200
    "UInteractSpellReset",                 // 201
    "UInteractSpellCondition",             // 202
    "UInteractSpellConditionReset",        // 203
    "UNoNPCDamageBelow85Ptc",              // 204
    "UNoNPCDamageBelow85PtcReset",         // 205
    "UFaceAngleRelative",                  // 206
    "UBossUnitFramesPriority",             // 207
    "UBossUnitFramesPriorityReset",        // 208
    "UNoThreatFeedback",                   // 209
    "UNoThreatFeedbackReset",              // 210
    "UChatEmotePlayer",                    // 211
    "UChatEmotePlayerRandom",              // 212
    "UEmotePlayer",                        // 213
    "USetQuestLoot",                       // 214
    "UCastRandomUnit",                     // 215
    "UCastRandomPlayer",                   // 216
    "UCastOtherUnit",                      // 217
    "MoveCircleRelative",                  // 218
    "ReturnHomeInstantly",                 // 219
    "AbortActionSetNoStringID",            // 220
    "AbortActionSetCombatConditionTrue",   // 221
    "ForceCombat",                         // 222
    "StopForceCombat",                     // 223
    "UUntargetableByClient",               // 224
    "UUntargetableByClientReset",          // 225
    "UNoMeleeApproach",                    // 226
    "UNoMeleeApproachReset",               // 227
    "URaidLockTapList",                    // 228
    "UCannotTurn",                         // 229
    "UCannotTurnReset",                    // 230
    "UPreferNPCsEnemies",                  // 231
    "UPreferNPCsEnemiesReset",             // 232
    "OFaction",                            // 233
    "OFactionReset",                       // 234
    "UPerformSpellVisualKit",              // 235
    "UPerformSpellVisual",                 // 236
    "UPerformSpellVisualActions",          // 237
    "UNoLeaveCombatStateRestore",          // 238
    "OStringID",                           // 239
    "OStringIDReset",                      // 240
    "UDespawnPersistentAuraObjects",       // 241
    "UDefaultMount",                       // 242
    "UDefaultMountReset",                  // 243
    "AbortActionSetFoundStringID",         // 244
    "UnsuppressNPCGreetings",              // 245
    "SuppressNPCGreetings",                // 246
    "UClearBossEmotes",                    // 247
    "UClearBossEmotesZone",                // 248
    "UClearBossEmotesPlayer",              // 249
    "UInteractWhileHostile",               // 250
    "UInteractWhileHostileReset",          // 251
    "UModelHighlightSuppression",          // 252
    "UModelHighlightSuppressionReset",     // 253
    "FollowTaxiPath",                      // 254
    "FollowTaxiPathRelative",              // 255
    "StartDungeonEncounter",               // 256
    "EndDungeonEncounter",                 // 257
    "UWildBattlePetLevel",                 // 258
    "UWildBattlePetLevelReset",            // 259
    "UTrackPlayerStat",                    // 260
    "UCannotPenetrateWater",               // 261
    "UCannotPenetrateWaterReset",          // 262
    "UDespawnStringID",                    // 263
    "USetSafeLocation",                    // 264
    "UTreatUnitAsRaidUnit",                // 265
    "UTreatUnitAsRaidUnitReset",           // 266
    "UDespawnSummonedAreaTriggers",        // 267
    "UAddPermanentWorldEffect",            // 268
    "URemovePermanentWorldEffect",         // 269
    "UCastWithPointsOtherUnit",            // 270
    "USetAnchorPoint",                     // 271
    "CircleUnit",                          // 272
    "RunSpellScript",                      // 273
    "TurnInPlaceDegrees",                  // 274
    "TurnInPlaceTimed",                    // 275
    "UPreferUnengagedTargets",             // 276
    "UGenerateSpawnGroupEvent",            // 277
    "PushActionSet",                       // 278
    "MoveOnPathGraphToPoint",              // 279
    "TriggerActionsOnSelf",                // 280
    "UEjectPassenger",                     // 281
    "PerformActionSet",                    // 282
    "UPauseSpellCooldowns",                // 283
    "UResumeSpellCooldowns",               // 284
    "UTriggerSpellCategoryCooldown",       // 285
    "UPlaySoundOnItselfSpeakerbot",        // 286
    "UStopSpeakerbotSound",                // 287
    "UBecomePersonalInvisClone",           // 288
    "MoveOnPathGraphToGUID",               // 289
    "MoveOnPathGraphMultiplePoints",       // 290
    "UNeverEvade",                         // 291
    "UNeverEvadeReset",                    // 292
    "UDontLeaveCombat",                    // 293
    "UCancelCurrentSpell",                 // 294
    "USayGameRegion",                      // 295
    "USayGameRegionRandom",                // 296
    "UYellGameRegion",                     // 297
    "UYellGameRegionRandom",               // 298
    "CombatPosition",                      // 299
    "CombatChase",                         // 300
    "UDontDismissOnFlyingMount",           // 301
    "UDontDismissOnFlyingMountReset"       // 302
};

// EnumeratedString's EnumID 598 and g_actionTriggers
enum ActionTriggers
{
    None                        = 0,
    OnReaction                  = 1,    // NYI // Unit detects {$Detection Type}.
    OnEnterCombat               = 2,    // Unit enters combat.
    OnLeaveCombat               = 3,    // NYI // Unit leaves combat.
    OnCombatTick                = 4,    // NYI // Unit triggers this each heartbeat.
    OnHealthRange               = 5,    // NYI // Unit health is between {#Health Min} and {#Health Max}.
    OnEnergyRange               = 6,    // NYI // Unit mana is between {#Mana Min} and {#Mana Max}.
    OnDeath                     = 7,    // Unit dies.
    OnSpell                     = 8,    // Unit is hit by spell {Spell}.
    OnKill                      = 9,    // Unit kills an enemy target.
    OnSpawn                     = 10,   // Unit spawns.
    OnEmote                     = 11,   // Unit receives emote {EmotesText}.
    OnMelee                     = 12,   // NYI // Unit receives a melee attack.
    OnInteract                  = 13,   // NYI // Unit is right clicked.
    OnCombatTrigger             = 14,   // NYI // Unit receives 'combat' trigger {#Trigger ID}.
    // [^ Alpha]
    OnSpellCast                 = 15,   // Unit casts spell {Spell}.
    OnPickPocket                = 16,   // NYI // Unit is pickpocketed.
    OnSkinned                   = 17,   // NYI // Unit is skinned.
    OnCombatReturn              = 18,   // Unit returns to its home position after combat.
    OnPathFailing               = 19,   // NYI // Unit fails to path to its target{#AfterSeconds}.
    OnHealthRangeRandom         = 20,   // NYI // Unit is within randomized health range {#Health Min} to {#Health Max}.
    OnEnergyRangeRandom         = 21,   // NYI // Unit is within randomized mana range {#Mana Min} to {#Mana Max}.
    // [^ 1.12.1]
    OnGeneralTrigger            = 22,   // NYI // Unit receives general trigger ID {#Trigger ID}.
    OnDespawn                   = 23,   // Unit receives a despawn request. (Instantaneous)
    OnSpellFailed               = 24,   // Unit fails to cast spell {Spell}.
    OnCharmBreak                = 25,   // NYI // Unit ceases to be charmed.
    OnPassengerControlEnd       = 26,   // NYI // Passenger in seat {#Seat Index} stops controlling it.
    OnVehicleReturn             = 27,   // NYI // Passenger in seat {#Seat Index} begins returning towards a vehicle.
    OnVehicleRide               = 28,   // NYI // Passenger in seat {#Seat Index} begins riding a vehicle.
    OnVehicleAbandon            = 29,   // NYI // Passenger in seat {#Seat Index} leaves its vehicle.
    // [^ 2.4.3]
    OnSpellStart                = 30,   // Unit starts casting spell {Spell}.
    OnAuraApplied               = 31,   // Unit has aura {Spell} applied.
    OnAuraRemoved               = 32,   // Unit has aura {Spell} removed.
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
    PauseForCombat                            = 0x00000004,   // Pauses the action set while the creature is in combat
    NoCorpseHeartbeat                         = 0x00000008,   // NYI
    ChainActionsTogetherWithoutStopping       = 0x00000010,   // NYI
    PauseUntilAllMembersAreDoneReturning      = 0x00000020,   // Action set is paused until creature is done returning home
    AllowAllActionsWhileDead                  = 0x00000040,   // Allows to start action set in OnDeath trigger. Action set will continue to run even if the unit is dead
    TreatLikeCreatureActionSet                = 0x00000080,   // NYI
    DoNotResetCombatState                     = 0x00000100,   // NYI
    ResetCombatAtStart                        = 0x00000200,   // NYI
    RespectRecursivePriority                  = 0x00000400,   // NYI

    ActionSetFlagsAll                         = (Looping | Resumable | PauseForCombat | PauseUntilAllMembersAreDoneReturning | AllowAllActionsWhileDead)
};

// EnumeratedString's EnumID 1114
enum class ActionFlags : uint32
{
    MovementHurry                               = 0x00000001, // NYI // movement: Hurry
    MovementNoPathing                           = 0x00000002, // NYI // movement: Don't use pathfinder to connect dots (no pathing)
    MovementNoPathSmoothing                     = 0x00000004, // NYI // movement: Don't round corners (no path smoothing)
    OnlyTargetUnitsAndObjectsWithSameCreator    = 0x00000008, // NYI // stringID: Only Target Units and Objects with Same Creator
    MovementCheckForDoors                       = 0x00000010, // NYI // movement: Check for Doors when pathing (performance)
    MovementMoveBackwards                       = 0x00000020, // NYI // movement: move backwards
    UsesTravelTimeNotTravelSpeed                = 0x00000040, // NYI // uses travel time not travel speed
    MovementDisableCompression                  = 0x00000080, // NYI // movement: disable compression (because precision matters)
    HideChatOutput                              = 0x00000100, // NYI // hide chat output
    QuestNotificationStyle                      = 0x00000200, // NYI // quest notification style
    IgnoreCrossRealmPlayers                     = 0x00000400, // NYI // ignore cross realm players
    PauseIfCantFindNamedPoint                   = 0x00000800, // NYI // pause if can't find named point (otherwise skip action)
    OnlyTargetUnitsWithSharedPhase              = 0x00001000, // NYI // stringID: Only Target Units with shared phase
    CleanupAction                               = 0x00002000, // NYI // Cleanup Action (Run Once On Stop or Interrupt)
    AbortActionSetIfTargetIsNotFound            = 0x00004000, // NYI // Abort action set if no target is found
    DoNotChainIntoThisAction                    = 0x00008000, // NYI // Do Not Chain Into This Action (Wait For Regular AI Update)
    RandomizeTargets                            = 0x00010000, // NYI // Randomize Targets (instead of sort)
    DespawnAtEndOfPathOrOnPathFail              = 0x00020000, // NYI // Despawn At End of Path or on path fail (while animating)
    EnableAISteering                            = 0x00040000, // NYI // Enable AI Steering (Avoid Obstacles - client side)
    DisableAISteering                           = 0x00080000, // NYI // Disable AI Steering (Don't Avoid Obstacles - client side)
    InterruptAnyChargeOrJumpCharge              = 0x00100000, // NYI // Interrupt any Charge or Jump Charge
    AutoDismount                                = 0x00200000, // NYI // Auto-Dismount
    AlsoSuppressGreetingsOnGossipPanelOpen      = 0x00400000  // NYI // Also suppress greetings on gossip panel open
};

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

// From g_aiMoveSpeed
enum class MoveSpeed : uint8
{
    Normal                                    = 0,
    Hurry                                     = 1,
    Meander                                   = 2,
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
    TriggerParam1(0), TriggerParam2(0), ActionSetId(0), RepeatMin(0), RepeatMax(0),
    RepeatTimer(0), HealthRangeMin(0), HealthRangeMax(0), EnergyRangeMin(0), EnergyRangeMax(0), IsTriggerActive(false), IsTriggerUsed(false) { }

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
    uint32 HealthRangeMin;
    uint32 HealthRangeMax;
    uint32 EnergyRangeMin;
    uint32 EnergyRangeMax;
    bool IsTriggerActive;
    bool IsTriggerUsed;
};

struct ActionSetEventHolder
{
    ActionSetEventHolder() : Id(0), Index(0), Type(0), Unit(0), Point(0), Path(0), TimeA(0), MoveSpeed(0),
    StringId(""), TimeB(0), LinearPath(0), CircularPath(0), FlightPath(0), Extra0(0), Extra1(0), Extra2(0),
    Extra3(0), Extra4(0), TargetType(0), TargetParam1(0), TargetParam2(0), TargetParam3(0), TargetParam4(0) { }

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
    double Extra0;
    double Extra1;
    double Extra2;
    double Extra3;
    double Extra4;
    uint8 TargetType;
    uint32 TargetParam1;
    uint32 TargetParam2;
    uint32 TargetParam3;
    uint32 TargetParam4;
};

struct ActionSetHolder
{
    ActionSetHolder() : Id(0), Flags(0), Priority(0), Name("") { }

    uint32 Id;
    uint32 Flags;
    uint8 Priority;
    std::string Name;
};

struct RandomActionSetHolder
{
    RandomActionSetHolder() : Id(0), Index(0), Probability(0.0f), ActionSetId(0) { }

    uint32 Id;
    uint16 Index;
    float Probability;
    uint32 ActionSetId;
};

typedef std::vector<ActionTriggersHolder> AIGroupEventList;
typedef std::unordered_map<uint32, AIGroupEventList> AIGroupEventMap;
typedef std::vector<ActionSetEventHolder> AIGroupActionSet;
typedef std::unordered_map<uint32, AIGroupActionSet> AIGroupActionSetMap;
typedef std::vector<RandomActionSetHolder> AIGroupRandomActionSet;
typedef std::unordered_map<uint32, AIGroupRandomActionSet> AIGroupRandomActionSetMap;
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
        AIGroupRandomActionSetMap mRandomActionSetMap;

        static bool IsActionValid(ActionSetEventHolder const& action);
        static bool IsActionTypeValid(ActionSetEventHolder const& action);
        static void LogUselessActionParams(ActionSetEventHolder const& action);
        static bool IsSpellValid(ActionSetEventHolder const& action);
        static bool IsBroadcastTextValid(ActionSetEventHolder const& action);
        static bool IsCreatureValid(ActionSetEventHolder const& action);
        static bool IsAnimTierValid(ActionSetEventHolder const& action);
        static bool IsEmoteValid(ActionSetEventHolder const& action);
        static bool IsSoundValid(ActionSetEventHolder const& action);
        static bool IsQuestValid(ActionSetEventHolder const& action);
        static bool IsZoneValid(ActionSetEventHolder const& action);
        static bool IsItemValid(ActionSetEventHolder const& action);
        static bool IsBooleanValid(ActionSetEventHolder const& action);

        static bool IsTriggerNotRepeatable(ActionTriggers trigger);

    public:
        static AIGroupMgr* Instance();

        void LoadActionSetsFromDB();
        void LoadActionSetsNamesFromDB();
        void LoadRandomActionSetsFromDB();
        void LoadActionTriggersFromDB();
        void LoadActionTriggersNamesFromDB();

        enum ActionTypeField : uint16
        {
            FieldUnit          = 0x0001,
            FieldPoint         = 0x0002,
            FieldPath          = 0x0004,
            FieldTimeA         = 0x0008,
            FieldMoveSpeed     = 0x0010,
            FieldStringId      = 0x0020,
            FieldTimeB         = 0x0040,
            FieldLinearPath    = 0x0080,
            FieldCircularPath  = 0x0100,
            FieldFlightPath    = 0x0200,
            FieldExtra0        = 0x0400,
            FieldExtra1        = 0x0800,
            FieldExtra2        = 0x1000,
            FieldExtra3        = 0x2000,
            FieldExtra4        = 0x4000
        };

        enum ObjectTypeMask : uint8
        {
            ObjectTypeMaskUnit          = 0x01,
            ObjectTypeMaskObject        = 0x02,
            ObjectTypeMaskAll           = ObjectTypeMaskUnit | ObjectTypeMaskObject
        };

        static constexpr ObjectTypeMask GetObjectTypeMask(AI_GROUP_ACTION action)
        {
            switch (action)
            {
                case AI_GROUP_SPAWN:
                case AI_GROUP_MOVETO:
                case AI_GROUP_TELEPORT:
                case AI_GROUP_WANDER:
                case AI_GROUP_ATTACK_ALL:
                case AI_GROUP_WANDER_AREA:
                case AI_GROUP_FOLLOW_GUID:
                case AI_GROUP_FOLLOW_PATH:
                case AI_GROUP_PATROL_LINE:
                case AI_GROUP_PATROL_CIRCLE:
                case AI_GROUP_GUARD_GUID:
                case AI_GROUP_GUARD_AREA:
                case AI_GROUP_SET_FORMATION:
                case AI_GROUP_UNIT_CHANGE_MODE_OBSOLETE:
                case AI_GROUP_UNIT_SAY:
                case AI_GROUP_UNIT_CAST:
                case AI_GROUP_UNIT_ACTIVATE_OBJECT:
                case AI_GROUP_SET_RADIUS_OBSOLETE:
                case AI_GROUP_SET_FACTION_OBSOLETE:
                case AI_GROUP_UNIT_SET_FACING:
                case AI_GROUP_UNIT_FACE_GUID:
                case AI_GROUP_UNIT_EMOTE:
                case AI_GROUP_MOVETO_GUID:
                case AI_GROUP_ATTACK_GUID:
                case AI_GROUP_UNIT_MOUNT:
                case AI_GROUP_UNIT_DISMOUNT:
                case AI_GROUP_UNIT_UNINTERACTIBLE:
                case AI_GROUP_UNIT_UNINTERACTIBLE_RESET:
                case AI_GROUP_UNIT_MODE:
                case AI_GROUP_UNIT_MODE_RESET:
                case AI_GROUP_UNIT_FACTION:
                case AI_GROUP_UNIT_FACTION_RESET:
                case AI_GROUP_UNIT_RADIUS:
                case AI_GROUP_UNIT_RADIUS_RESET:
                case AI_GROUP_QUEST_COMPLETE:
                case AI_GROUP_UNIT_QUESTGIVER:
                case AI_GROUP_UNIT_TRAINER:
                case AI_GROUP_SPLINE_PATH:
                case AI_GROUP_PLAYER_ACTION:
                case AI_GROUP_RETURN_HOME:
                case AI_GROUP_UNIT_SAY_RANDOM:
                case AI_GROUP_UNIT_YELL:
                case AI_GROUP_UNIT_YELL_RANDOM:
                case AI_GROUP_UNIT_SET_ITEM_MAINHAND:
                case AI_GROUP_UNIT_RESET_ITEM_MAINHAND:
                case AI_GROUP_UNIT_CHAT_EMOTE:
                case AI_GROUP_UNIT_CHAT_EMOTE_RANDOM:
                case AI_GROUP_UNIT_GENERATE_EVENT:
                case AI_GROUP_VENDOR_IDLE_OBSOLETE:
                case AI_GROUP_QUEST_FAILED:
                case AI_GROUP_UNIT_TRIGGERS:
                case AI_GROUP_UNIT_TRIGGERS_RESET:
                case AI_GROUP_UNIT_LEAVE_COMBAT:
                case AI_GROUP_IDLE_COMBAT_START:
                case AI_GROUP_IDLE_COMBAT_STOP:
                case AI_GROUP_UNIT_IMMUNEPC:
                case AI_GROUP_UNIT_IMMUNEPC_RESET:
                case AI_GROUP_UNIT_IMMUNENPC:
                case AI_GROUP_UNIT_IMMUNENPC_RESET:
                case AI_GROUP_UNIT_UNKILLABLE:
                case AI_GROUP_UNIT_UNKILLABLE_RESET:
                case AI_GROUP_UNIT_SPELLS:
                case AI_GROUP_UNIT_SPELLS_RESET:
                case AI_GROUP_ATTACK_ALL_INSTANCE:
                case AI_GROUP_UNIT_SEND_LOCAL_EVENT:
                case AI_GROUP_UNIT_BROADCAST_LOCAL_EVENT:
                case AI_GROUP_UNIT_FLEE:
                case AI_GROUP_UNIT_RETREAT:
                case AI_GROUP_AVOID:
                case AI_GROUP_AVOID_GUID:
                case AI_GROUP_UNIT_ACTIVATE_OBJECTS:
                case AI_GROUP_UNIT_STRINGID:
                case AI_GROUP_UNIT_STRINGID_RESET:
                case AI_GROUP_UNIT_SET_ITEM_OFFHAND:
                case AI_GROUP_UNIT_RESET_ITEM_OFFHAND:
                case AI_GROUP_UNIT_SET_ITEM_RANGED:
                case AI_GROUP_UNIT_RESET_ITEM_RANGED:
                case AI_GROUP_UNIT_SHEATHE:
                case AI_GROUP_UNIT_UNSHEATHE:
                case AI_GROUP_UNIT_CANCEL_CAST:
                case AI_GROUP_UNIT_CANCEL_AURA:
                case AI_GROUP_UNIT_FINISH_CAST:
                case AI_GROUP_EMOTE_STATE:
                case AI_GROUP_UNIT_CALL_FOR_HELP:
                case AI_GROUP_FLIGHT_PATH:
                case AI_GROUP_UNIT_COMBAT_TRIGGER:
                case AI_GROUP_UNIT_GOSSIP:
                case AI_GROUP_UNIT_KILL_CREDIT:
                case AI_GROUP_UNIT_WHISPER:
                case AI_GROUP_UNIT_WHISPER_RANDOM:
                case AI_GROUP_UNIT_NO_LOOT:
                case AI_GROUP_UNIT_NO_LOOT_RESET:
                case AI_GROUP_UNIT_NO_XP:
                case AI_GROUP_UNIT_NO_XP_RESET:
                case AI_GROUP_UNIT_PVP_ENABLING:
                case AI_GROUP_UNIT_PVP_ENABLING_RESET:
                case AI_GROUP_UNIT_PLAY_MUSIC:
                case AI_GROUP_UNIT_PLAY_SOUND:
                case AI_GROUP_UNIT_SET_LOOT:
                case AI_GROUP_UNIT_FLOATING:
                case AI_GROUP_UNIT_FLOATING_RESET:
                case AI_GROUP_SPAWN_FORCED:
                case AI_GROUP_UNIT_UNSHEATHE_RANGE:
                case AI_GROUP_UNIT_CHAT_EMOTE_ZONE:
                case AI_GROUP_UNIT_CHAT_EMOTE_ZONE_RANDOM:
                case AI_GROUP_UNIT_YELL_ZONE:
                case AI_GROUP_UNIT_YELL_ZONE_RANDOM:
                case AI_GROUP_UNIT_PLAY_MUSIC_ZONE:
                case AI_GROUP_UNIT_PLAY_SOUND_ZONE:
                case AI_GROUP_UNIT_IGNORE_COMBAT:
                case AI_GROUP_UNIT_IGNORE_COMBAT_RESET:
                case AI_GROUP_RESTART_ACTIONS_WSE:
                case AI_GROUP_ABORT_ACTION_SET_WSE:
                case AI_GROUP_UNIT_BOSS_EMOTE:
                case AI_GROUP_UNIT_BOSS_EMOTE_ZONE:
                case AI_GROUP_TRIGGER_ACTIONS_NEAREST_UNIT_IC:
                case AI_GROUP_UNIT_CAST_FAILURE:
                case AI_GROUP_UNIT_NO_REPUTATION:
                case AI_GROUP_UNIT_NO_REPUTATION_RESET:
                case AI_GROUP_SPLINE_PATH_LOOP:
                case AI_GROUP_UNIT_VENDOR:
                case AI_GROUP_UNIT_RESET_VENDOR_LISTS:
                case AI_GROUP_TRIGGER_ACTIONS_UNITS:
                case AI_GROUP_TRIGGER_ACTIONS_NEAREST_UNIT:
                case AI_GROUP_UNIT_SAY_ZONE:
                case AI_GROUP_UNIT_SAY_ZONE_RANDOM:
                case AI_GROUP_UNIT_SEND_LOCAL_EVENT_SELF:
                case AI_GROUP_UNIT_SESSILE:
                case AI_GROUP_UNIT_SESSILE_RESET:
                case AI_GROUP_UNIT_RAID_LOCK:
                case AI_GROUP_UNIT_RAID_LOCK_RESET:
                case AI_GROUP_QUEST_COMPLETE_TRIGGERING_PLAYER:
                case AI_GROUP_QUEST_CLEARED_TRIGGERING_PLAYER:
                case AI_GROUP_UNIT_CHAT_PARTY:
                case AI_GROUP_UNIT_CLEAR_COOLDOWNS:
                case AI_GROUP_UNIT_PLAY_TARGETED_SOUND:
                case AI_GROUP_UNIT_PLAY_TARGETED_MUSIC:
                case AI_GROUP_UNIT_RESET_INITIAL_SPELL_COOLDOWNS:
                case AI_GROUP_UNIT_NO_MELEE:
                case AI_GROUP_UNIT_NO_MELEE_RESET:
                case AI_GROUP_FALL_TO_THE_GROUND:
                case AI_GROUP_UNIT_UPDATE_INTERACTION:
                case AI_GROUP_UNIT_BOSS_WHISPER:
                case AI_GROUP_UNIT_BOSS_WHISPER_RANDOM:
                case AI_GROUP_MOVE_RELATIVE:
                case AI_GROUP_UNIT_DONT_CLEAR_TAP:
                case AI_GROUP_UNIT_KILL_CREDIT_TAP:
                case AI_GROUP_UNIT_CAST_WITH_POINTS:
                case AI_GROUP_UNIT_RIDE_VEHICLE:
                case AI_GROUP_UNIT_ABANDON_VEHICLE:
                case AI_GROUP_VEHICLE_RECALL_OR_RESPAWN_PASSENGERS:
                case AI_GROUP_PLAY_MOVIE:
                case AI_GROUP_JUMP_POINT:
                case AI_GROUP_JUMP_GUID:
                case AI_GROUP_MOVETO_THEN_JUMP:
                case AI_GROUP_VEHICLE_RECALL_LIVING_PASSENGERS:
                case AI_GROUP_VEHICLE_RESPAWN_ALL_PASSENGERS:
                case AI_GROUP_UNIT_FATAL_FALL_DISTANCE:
                case AI_GROUP_UNIT_FATAL_FALL_DISTANCE_RESET:
                case AI_GROUP_UNIT_SET_ANIMATION_TIER:
                case AI_GROUP_UNIT_SEND_TAP_LIST:
                case AI_GROUP_UNIT_GET_TAP_LIST:
                case AI_GROUP_UNIT_HOVER_HEIGHT:
                case AI_GROUP_UNIT_HOVER_HEIGHT_RESET:
                case AI_GROUP_TIER_TRANSITION_LAND:
                case AI_GROUP_TIER_TRANSITION_TAKE_OFF:
                case AI_GROUP_TIER_TRANSITION_MOVETO:
                case AI_GROUP_TIER_TRANSITION_MOVETO_GUID:
                case AI_GROUP_TIER_TRANSITION_FOLLOW_PATH:
                case AI_GROUP_UNIT_KILL_CREDIT_PLAYER:
                case AI_GROUP_SUSPEND_TRIGGER_ACTION:
                case AI_GROUP_UNIT_VEHICLE_RECORD:
                case AI_GROUP_UNIT_VEHICLE_RECORD_RESET:
                case AI_GROUP_UNIT_IMMUNITIES:
                case AI_GROUP_UNIT_IMMUNITIES_RESET:
                case AI_GROUP_SEND_CONTENT_ALERT:
                case AI_GROUP_UNIT_SAY_PLAYER:
                case AI_GROUP_UNIT_YELL_PLAYER:
                case AI_GROUP_UNIT_START_QUEST:
                case AI_GROUP_UNIT_SAY_PLAYER_RANDOM:
                case AI_GROUP_UNIT_YELL_PLAYER_RANDOM:
                case AI_GROUP_UNIT_START_LOOPING_ANIM_KIT:
                case AI_GROUP_UNIT_STOP_LOOPING_ANIM_KIT:
                case AI_GROUP_UNIT_PLAY_ONESHOT_ANIM_KIT:
                case AI_GROUP_UNIT_SET_MOVEMENT_ANIM_KIT:
                case AI_GROUP_UNIT_SET_MELEE_ANIM_KIT:
                case AI_GROUP_UNIT_INTERACT_SPELL:
                case AI_GROUP_UNIT_INTERACT_SPELL_RESET:
                case AI_GROUP_UNIT_INTERACT_SPELL_CONDITION:
                case AI_GROUP_UNIT_INTERACT_SPELL_CONDITION_RESET:
                case AI_GROUP_UNIT_NO_NPC_DAMAGE_BELOW_85_PTC:
                case AI_GROUP_UNIT_NO_NPC_DAMAGE_BELOW_85_PTC_RESET:
                case AI_GROUP_UNIT_FACE_ANGLE_RELATIVE:
                case AI_GROUP_UNIT_BOSS_UNIT_FRAMES_PRIORITY:
                case AI_GROUP_UNIT_BOSS_UNIT_FRAMES_PRIORITY_RESET:
                case AI_GROUP_UNIT_NO_THREAT_FEEDBACK:
                case AI_GROUP_UNIT_NO_THREAT_FEEDBACK_RESET:
                case AI_GROUP_UNIT_CHAT_EMOTE_PLAYER:
                case AI_GROUP_UNIT_CHAT_EMOTE_PLAYER_RANDOM:
                case AI_GROUP_UNIT_EMOTE_PLAYER:
                case AI_GROUP_UNIT_SET_QUEST_LOOT:
                case AI_GROUP_UNIT_CAST_RANDOM_UNIT:
                case AI_GROUP_UNIT_CAST_RANDOM_PLAYER:
                case AI_GROUP_UNIT_CAST_OTHER_UNIT:
                case AI_GROUP_MOVE_CIRCLE_RELATIVE:
                case AI_GROUP_RETURN_HOME_INSTANTLY:
                case AI_GROUP_ABORT_ACTION_SET_NO_STRINGID:
                case AI_GROUP_ABORT_ACTION_SET_COMBAT_CONDITION_TRUE:
                case AI_GROUP_FORCE_COMBAT:
                case AI_GROUP_STOP_FORCE_COMBAT:
                case AI_GROUP_UNIT_UNTARGETABLE_BY_CLIENT:
                case AI_GROUP_UNIT_UNTARGETABLE_BY_CLIENT_RESET:
                case AI_GROUP_UNIT_NO_MELEE_APPROACH:
                case AI_GROUP_UNIT_NO_MELEE_APPROACH_RESET:
                case AI_GROUP_UNIT_RAID_LOCK_TAP_LIST:
                case AI_GROUP_UNIT_CANNOT_TURN:
                case AI_GROUP_UNIT_CANNOT_TURN_RESET:
                case AI_GROUP_UNIT_PREFER_NPCS_ENEMIES:
                case AI_GROUP_UNIT_PREFER_NPCS_ENEMIES_RESET:
                case AI_GROUP_UNIT_PERFORM_SPELL_VISUAL_KIT:
                case AI_GROUP_UNIT_PERFORM_SPELL_VISUAL:
                case AI_GROUP_UNIT_PERFORM_SPELL_VISUAL_ACTIONS:
                case AI_GROUP_UNIT_NO_LEAVECOMBAT_STATE_RESTORE:
                case AI_GROUP_UNIT_DESPAWN_PERSISTENT_AURA_OBJECTS:
                case AI_GROUP_UNIT_DEFAULT_MOUNT:
                case AI_GROUP_UNIT_DEFAULT_MOUNT_RESET:
                case AI_GROUP_ABORT_ACTION_SET_FOUND_STRINGID:
                case AI_GROUP_UNSUPPRESS_NPC_GREETINGS:
                case AI_GROUP_SUPPRESS_NPC_GREETINGS:
                case AI_GROUP_UNIT_CLEAR_BOSS_EMOTES:
                case AI_GROUP_UNIT_CLEAR_BOSS_EMOTES_ZONE:
                case AI_GROUP_UNIT_CLEAR_BOSS_EMOTES_PLAYER:
                case AI_GROUP_UNIT_INTERACT_WHILE_HOSTILE:
                case AI_GROUP_UNIT_INTERACT_WHILE_HOSTILE_RESET:
                case AI_GROUP_UNIT_MODEL_HIGHLIGHT_SUPPRESSION:
                case AI_GROUP_UNIT_MODEL_HIGHLIGHT_SUPPRESSION_RESET:
                case AI_GROUP_FOLLOW_TAXI_PATH:
                case AI_GROUP_FOLLOW_TAXI_PATH_RELATIVE:
                case AI_GROUP_START_DUNGEON_ENCOUNTER:
                case AI_GROUP_END_DUNGEON_ENCOUNTER:
                case AI_GROUP_UNIT_WILD_BATTLEPET_LEVEL:
                case AI_GROUP_UNIT_WILD_BATTLEPET_LEVEL_RESET:
                case AI_GROUP_UNIT_TRACK_PLAYER_STAT:
                case AI_GROUP_UNIT_CANNOT_PENETRATE_WATER:
                case AI_GROUP_UNIT_CANNOT_PENETRATE_WATER_RESET:
                case AI_GROUP_UNIT_DESPAWN_STRINGID:
                case AI_GROUP_UNIT_SET_SAFE_LOCATION:
                case AI_GROUP_UNIT_TREAT_UNIT_AS_RAID_UNIT:
                case AI_GROUP_UNIT_TREAT_UNIT_AS_RAID_UNIT_RESET:
                case AI_GROUP_UNIT_DESPAWN_SUMMONED_AREA_TRIGGERS:
                case AI_GROUP_UNIT_ADD_PERMANENT_WORLD_EFFECT:
                case AI_GROUP_UNIT_REMOVE_PERMANENT_WORLD_EFFECT:
                case AI_GROUP_UNIT_CAST_WITH_POINTS_OTHER_UNIT:
                case AI_GROUP_UNIT_SET_ANCHOR_POINT:
                case AI_GROUP_CIRCLE_UNIT:
                case AI_GROUP_RUN_SPELL_SCRIPT:
                case AI_GROUP_TURN_IN_PLACE_DEGREES:
                case AI_GROUP_TURN_IN_PLACE_TIMED:
                case AI_GROUP_UNIT_PREFER_UNENGAGED_TARGETS:
                case AI_GROUP_UNIT_GENERATE_SPAWNGROUP_EVENT:
                case AI_GROUP_PUSH_ACTIONSET:
                case AI_GROUP_MOVE_ON_PATH_GRAPH_TO_POINT:
                case AI_GROUP_TRIGGER_ACTIONS_ON_SELF:
                case AI_GROUP_UNIT_EJECT_PASSENGER:
                case AI_GROUP_PERFORM_ACTIONSET:
                case AI_GROUP_UNIT_PAUSE_SPELL_COOLDOWNS:
                case AI_GROUP_UNIT_RESUME_SPELL_COOLDOWNS:
                case AI_GROUP_UNIT_TRIGGER_SPELL_CATEGORY_COOLDOWN:
                case AI_GROUP_UNIT_PLAY_SOUND_ON_ITSELF_SPEAKERBOT:
                case AI_GROUP_UNIT_STOP_SPEAKERBOT_SOUND:
                case AI_GROUP_UNIT_BECOME_PERSONAL_INVIS_CLONE:
                case AI_GROUP_MOVE_ON_PATH_GRAPH_TO_GUID:
                case AI_GROUP_MOVE_ON_PATH_GRAPH_MULTIPLE_POINTS:
                case AI_GROUP_UNIT_NEVER_EVADE:
                case AI_GROUP_UNIT_NEVER_EVADE_RESET:
                case AI_GROUP_UNIT_DONT_LEAVE_COMBAT:
                case AI_GROUP_UNIT_CANCEL_CURRENT_SPELL:
                case AI_GROUP_UNIT_SAY_GAME_REGION:
                case AI_GROUP_UNIT_SAY_GAME_REGION_RANDOM:
                case AI_GROUP_UNIT_YELL_GAME_REGION:
                case AI_GROUP_UNIT_YELL_GAME_REGION_RANDOM:
                case AI_GROUP_COMBAT_POSITION:
                case AI_GROUP_COMBAT_CHASE:
                case AI_GROUP_UNIT_DONT_DISMISS_ON_FLYING_MOUNT:
                case AI_GROUP_UNIT_DONT_DISMISS_ON_FLYING_MOUNT_RES:
                    return ObjectTypeMaskUnit;
                case AI_GROUP_OBJECT_CHAT_EMOTE:
                case AI_GROUP_OBJECT_CHAT_EMOTE_RANDOM:
                case AI_GROUP_OBJECT_ACTIVATE:
                case AI_GROUP_OBJECT_PLAY_MUSIC:
                case AI_GROUP_OBJECT_PLAY_SOUND:
                case AI_GROUP_OBJECT_CHAT_EMOTE_ZONE:
                case AI_GROUP_OBJECT_CHAT_EMOTE_ZONE_RANDOM:
                case AI_GROUP_OBJECT_PLAY_MUSIC_ZONE:
                case AI_GROUP_OBJECT_PLAY_SOUND_ZONE:
                case AI_GROUP_OBJECT_FACTION:
                case AI_GROUP_OBJECT_FACTION_RESET:
                case AI_GROUP_OBJECT_STRINGID:
                case AI_GROUP_OBJECT_STRINGID_RESET:
                    return ObjectTypeMaskObject;
                case AI_GROUP_IDLE:
                case AI_GROUP_GENERATE_EVENT:
                case AI_GROUP_DESPAWN:
                case AI_GROUP_PERIODIC_EVENT:
                case AI_GROUP_RANDOM_ACTION_SET:
                    return ObjectTypeMaskAll;
                default:
                    return static_cast<ObjectTypeMask>(0);
            }
        }

        struct ActionSetTypeInfo
        {
            char const* Name;
            bool HasUnit;
            bool HasPoint;
            bool HasPath;
            bool HasTimeA;
            bool HasMoveSpeed;
            bool HasStringId;
            bool HasTimeB;
            bool HasLinearPath;
            bool HasCircularPath;
            bool HasFlightPath;
            bool HasExtra0;
            bool HasExtra1;
            bool HasExtra2;
            bool HasExtra3;
            bool HasExtra4;

            ActionSetTypeInfo() : Name(""), HasUnit(false), HasPoint(false), HasPath(false), HasTimeA(false),
                HasMoveSpeed(false), HasStringId(false), HasTimeB(false), HasLinearPath(false), HasCircularPath(false),
                HasFlightPath(false), HasExtra0(false), HasExtra1(false), HasExtra2(false), HasExtra3(false), HasExtra4(false) { }

            ActionSetTypeInfo(char const* name, std::initializer_list<ActionTypeField> usedFields) : ActionSetTypeInfo()
            {
                Name = name;
                for (ActionTypeField field : usedFields)
                    switch (field)
                    {
                        case FieldUnit: HasUnit = true; break;
                        case FieldPoint: HasPoint = true; break;
                        case FieldPath: HasPath = true; break;
                        case FieldTimeA: HasTimeA = true; break;
                        case FieldMoveSpeed: HasMoveSpeed = true; break;
                        case FieldStringId: HasStringId = true; break;
                        case FieldTimeB: HasTimeB = true; break;
                        case FieldLinearPath: HasLinearPath = true; break;
                        case FieldCircularPath: HasCircularPath = true; break;
                        case FieldFlightPath: HasFlightPath = true; break;
                        case FieldExtra0: HasExtra0 = true; break;
                        case FieldExtra1: HasExtra1 = true; break;
                        case FieldExtra2: HasExtra2 = true; break;
                        case FieldExtra3: HasExtra3 = true; break;
                        case FieldExtra4: HasExtra4 = true; break;
                    }
            }
        };
        static ActionSetTypeInfo const StaticActionSetTypeData[AI_GROUP_MAX];

        struct ActionTriggerTypeInfo
        {
            char const* Name;
            bool HasTriggerParam1;
            bool HasTriggerParam2;
        };
        static ActionTriggerTypeInfo const StaticActionTriggerTypeData[ActionTriggers::Max];

        std::string GetTriggersName(uint32 triggersId) const;
        std::string GetActionSetName(uint32 actionSetId) const;
        uint8 GetActionSetPriority(uint32 actionSetId) const;
        uint32 GetActionSetFlags(uint32 actionSetId) const;

        uint8 GetPriorityPercentForPriorityType(ActionSetPriorityType type);

        AIGroupEventList GetScript(uint32 triggersId);
        AIGroupActionSet GetActionSet(uint32 actionSetId);
        AIGroupRandomActionSet GetRandomActionSet(uint32 randomActionSetId);
};

#define sAIGroupMgr AIGroupMgr::Instance()

#endif
