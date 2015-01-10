/*
 * Copyright (C) 2008-2015 TrinityCore <http://www.trinitycore.org/>
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

#ifndef TRINITYCORE_GAMEOBJECT_H
#define TRINITYCORE_GAMEOBJECT_H

#include "Common.h"
#include "SharedDefines.h"
#include "Unit.h"
#include "Object.h"
#include "LootMgr.h"
#include "DatabaseEnv.h"

class GameObjectAI;
class Group;
class Transport;

#define MAX_GAMEOBJECT_QUEST_ITEMS 6

// from `gameobject_template`
struct GameObjectTemplate
{
    uint32  entry;
    uint32  type;
    uint32  displayId;
    std::string name;
    std::string IconName;
    std::string castBarCaption;
    std::string unk1;
    uint32  faction;
    uint32  flags;
    float   size;
    uint32  questItems[MAX_GAMEOBJECT_QUEST_ITEMS];
    int32   unkInt32;
    union
    {
        // 0 GAMEOBJECT_TYPE_DOOR
        struct
        {
            uint32 startOpen;                               // 0 startOpen, enum { false, true, }; Default: false
            uint32 open;                                    // 1 open, References: Lock_, NoValue = 0
            uint32 autoClose;                               // 2 autoClose (ms), int, Min value: 0, Max value: 2147483647, Default value: 3000
            uint32 noDamageImmune;                          // 3 noDamageImmune, enum { false, true, }; Default: false
            uint32 openTextID;                              // 4 openTextID, References: BroadcastText, NoValue = 0
            uint32 closeTextID;                             // 5 closeTextID, References: BroadcastText, NoValue = 0
            uint32 IgnoredByPathing;                        // 6 Ignored By Pathing, enum { false, true, }; Default: false
            uint32 conditionID1;                            // 7 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 EnablePortalsonopen;                     // 8 Enable Portals on open, enum { false, true, }; Default: false
            uint32 GiganticAOI;                             // 9 Gigantic AOI, enum { false, true, }; Default: false
            uint32 InfiniteAOI;                             // 10 Infinite AOI, enum { false, true, }; Default: false
        } door;
        // 1 GAMEOBJECT_TYPE_BUTTON
        struct
        {
            uint32 startOpen;                               // 0 startOpen, enum { false, true, }; Default: false
            uint32 open;                                    // 1 open, References: Lock_, NoValue = 0
            uint32 autoClose;                               // 2 autoClose (ms), int, Min value: 0, Max value: 2147483647, Default value: 3000
            uint32 linkedTrap;                              // 3 linkedTrap, References: GameObjects, NoValue = 0
            uint32 noDamageImmune;                          // 4 noDamageImmune, enum { false, true, }; Default: false
            uint32 GiganticAOI;                             // 5 Gigantic AOI, enum { false, true, }; Default: false
            uint32 openTextID;                              // 6 openTextID, References: BroadcastText, NoValue = 0
            uint32 closeTextID;                             // 7 closeTextID, References: BroadcastText, NoValue = 0
            uint32 requireLOS;                              // 8 require LOS, enum { false, true, }; Default: false
            uint32 conditionID1;                            // 9 conditionID1, References: PlayerCondition, NoValue = 0
        } button;
        // 2 GAMEOBJECT_TYPE_QUESTGIVER
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 questGiver;                              // 1 questGiver, References: QuestGiver, NoValue = 0
            uint32 pageMaterial;                            // 2 pageMaterial, References: PageTextMaterial, NoValue = 0
            uint32 gossipID;                                // 3 gossipID, References: Gossip, NoValue = 0
            uint32 customAnim;                              // 4 customAnim, int, Min value: 0, Max value: 4, Default value: 0
            uint32 noDamageImmune;                          // 5 noDamageImmune, enum { false, true, }; Default: false
            uint32 openTextID;                              // 6 openTextID, References: BroadcastText, NoValue = 0
            uint32 requireLOS;                              // 7 require LOS, enum { false, true, }; Default: false
            uint32 allowMounted;                            // 8 allowMounted, enum { false, true, }; Default: false
            uint32 GiganticAOI;                             // 9 Gigantic AOI, enum { false, true, }; Default: false
            uint32 conditionID1;                            // 10 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 NeverUsableWhileMounted;                 // 11 Never Usable While Mounted, enum { false, true, }; Default: false
        } questgiver;
        // 3 GAMEOBJECT_TYPE_CHEST
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 chestLoot;                               // 1 chestLoot, References: Treasure, NoValue = 0
            uint32 chestRestockTime;                        // 2 chestRestockTime, int, Min value: 0, Max value: 1800000, Default value: 0
            uint32 consumable;                              // 3 consumable, enum { false, true, }; Default: false
            uint32 minRestock;                              // 4 minRestock, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 maxRestock;                              // 5 maxRestock, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 triggeredEvent;                          // 6 triggeredEvent, References: GameEvents, NoValue = 0
            uint32 linkedTrap;                              // 7 linkedTrap, References: GameObjects, NoValue = 0
            uint32 questID;                                 // 8 questID, References: QuestV2, NoValue = 0
            uint32 level;                                   // 9 level, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 requireLOS;                              // 10 require LOS, enum { false, true, }; Default: false
            uint32 leaveLoot;                               // 11 leaveLoot, enum { false, true, }; Default: false
            uint32 notInCombat;                             // 12 notInCombat, enum { false, true, }; Default: false
            uint32 logloot;                                 // 13 log loot, enum { false, true, }; Default: false
            uint32 openTextID;                              // 14 openTextID, References: BroadcastText, NoValue = 0
            uint32 usegrouplootrules;                       // 15 use group loot rules, enum { false, true, }; Default: false
            uint32 floatingTooltip;                         // 16 floatingTooltip, enum { false, true, }; Default: false
            uint32 conditionID1;                            // 17 conditionID1, References: PlayerCondition, NoValue = 0
            int32 xpLevel;                                  // 18 xpLevel, int, Min value: -1, Max value: 100, Default value: 0
            uint32 xpDifficulty;                            // 19 xpDifficulty, enum { No Exp, Trivial, Very Small, Small, Substandard, Standard, High, Epic, Dungeon, Placeholder2, }; Default: No Exp
            uint32 lootLevel;                               // 20 lootLevel, int, Min value: 0, Max value: 100, Default value: 0
            uint32 GroupXP;                                 // 21 Group XP, enum { false, true, }; Default: false
            uint32 DamageImmuneOK;                          // 22 Damage Immune OK, enum { false, true, }; Default: false
            uint32 trivialSkillLow;                         // 23 trivialSkillLow, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 trivialSkillHigh;                        // 24 trivialSkillHigh, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 DungeonEncounter;                        // 25 Dungeon Encounter, References: DungeonEncounter, NoValue = 0
            uint32 spell;                                   // 26 spell, References: Spell, NoValue = 0
            uint32 GiganticAOI;                             // 27 Gigantic AOI, enum { false, true, }; Default: false
            uint32 LargeAOI;                                // 28 Large AOI, enum { false, true, }; Default: false
            uint32 SpawnVignette;                           // 29 Spawn Vignette, References: vignette, NoValue = 0
            uint32 chestPersonalLoot;                       // 30 chest Personal Loot, References: Treasure, NoValue = 0
            uint32 turnpersonallootsecurityoff;             // 31 turn personal loot security off, enum { false, true, }; Default: false
            uint32 ChestProperties;                         // 32 Chest Properties, References: ChestProperties, NoValue = 0
        } chest;
        // 4 GAMEOBJECT_TYPE_BINDER
        struct
        {
        } binder;
        // 5 GAMEOBJECT_TYPE_GENERIC
        struct
        {
            uint32 floatingTooltip;                         // 0 floatingTooltip, enum { false, true, }; Default: false
            uint32 highlight;                               // 1 highlight, enum { false, true, }; Default: true
            uint32 serverOnly;                              // 2 serverOnly, enum { false, true, }; Default: false
            uint32 GiganticAOI;                             // 3 Gigantic AOI, enum { false, true, }; Default: false
            uint32 floatOnWater;                            // 4 floatOnWater, enum { false, true, }; Default: false
            uint32 questID;                                 // 5 questID, References: QuestV2, NoValue = 0
            uint32 conditionID1;                            // 6 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 LargeAOI;                                // 7 Large AOI, enum { false, true, }; Default: false
            uint32 UseGarrisonOwnerGuildColors;             // 8 Use Garrison Owner Guild Colors, enum { false, true, }; Default: false
        } generic;
        // 6 GAMEOBJECT_TYPE_TRAP
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 level;                                   // 1 level, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 radius;                                  // 2 radius, int, Min value: 0, Max value: 100, Default value: 0
            uint32 spell;                                   // 3 spell, References: Spell, NoValue = 0
            uint32 charges;                                 // 4 charges, int, Min value: 0, Max value: 65535, Default value: 1
            uint32 cooldown;                                // 5 cooldown, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 autoClose;                               // 6 autoClose (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 startDelay;                              // 7 startDelay, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 serverOnly;                              // 8 serverOnly, enum { false, true, }; Default: false
            uint32 stealthed;                               // 9 stealthed, enum { false, true, }; Default: false
            uint32 GiganticAOI;                             // 10 Gigantic AOI, enum { false, true, }; Default: false
            uint32 stealthAffected;                         // 11 stealthAffected, enum { false, true, }; Default: false
            uint32 openTextID;                              // 12 openTextID, References: BroadcastText, NoValue = 0
            uint32 closeTextID;                             // 13 closeTextID, References: BroadcastText, NoValue = 0
            uint32 IgnoreTotems;                            // 14 Ignore Totems, enum { false, true, }; Default: false
            uint32 conditionID1;                            // 15 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 playerCast;                              // 16 playerCast, enum { false, true, }; Default: false
            uint32 SummonerTriggered;                       // 17 Summoner Triggered, enum { false, true, }; Default: false
        } trap;
        // 7 GAMEOBJECT_TYPE_CHAIR
        struct
        {
            uint32 chairslots;                              // 0 chairslots, int, Min value: 1, Max value: 5, Default value: 1
            uint32 chairheight;                             // 1 chairheight, int, Min value: 0, Max value: 2, Default value: 1
            uint32 onlyCreatorUse;                          // 2 onlyCreatorUse, enum { false, true, }; Default: false
            uint32 triggeredEvent;                          // 3 triggeredEvent, References: GameEvents, NoValue = 0
            uint32 conditionID1;                            // 4 conditionID1, References: PlayerCondition, NoValue = 0
        } chair;
        // 8 GAMEOBJECT_TYPE_SPELL_FOCUS
        struct
        {
            uint32 spellFocusType;                          // 0 spellFocusType, References: SpellFocusObject, NoValue = 0
            uint32 radius;                                  // 1 radius, int, Min value: 0, Max value: 50, Default value: 10
            uint32 linkedTrap;                              // 2 linkedTrap, References: GameObjects, NoValue = 0
            uint32 serverOnly;                              // 3 serverOnly, enum { false, true, }; Default: false
            uint32 questID;                                 // 4 questID, References: QuestV2, NoValue = 0
            uint32 GiganticAOI;                             // 5 Gigantic AOI, enum { false, true, }; Default: false
            uint32 floatingTooltip;                         // 6 floatingTooltip, enum { false, true, }; Default: false
            uint32 floatOnWater;                            // 7 floatOnWater, enum { false, true, }; Default: false
            uint32 conditionID1;                            // 8 conditionID1, References: PlayerCondition, NoValue = 0
        } spellFocus;
        // 9 GAMEOBJECT_TYPE_TEXT
        struct
        {
            uint32 pageID;                                  // 0 pageID, References: PageText, NoValue = 0
            uint32 language;                                // 1 language, References: Languages, NoValue = 0
            uint32 pageMaterial;                            // 2 pageMaterial, References: PageTextMaterial, NoValue = 0
            uint32 allowMounted;                            // 3 allowMounted, enum { false, true, }; Default: false
            uint32 conditionID1;                            // 4 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 NeverUsableWhileMounted;                 // 5 Never Usable While Mounted, enum { false, true, }; Default: false
        } text;
        // 10 GAMEOBJECT_TYPE_GOOBER
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 questID;                                 // 1 questID, References: QuestV2, NoValue = 0
            uint32 eventID;                                 // 2 eventID, References: GameEvents, NoValue = 0
            uint32 autoClose;                               // 3 autoClose (ms), int, Min value: 0, Max value: 2147483647, Default value: 3000
            uint32 customAnim;                              // 4 customAnim, int, Min value: 0, Max value: 4, Default value: 0
            uint32 consumable;                              // 5 consumable, enum { false, true, }; Default: false
            uint32 cooldown;                                // 6 cooldown, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 pageID;                                  // 7 pageID, References: PageText, NoValue = 0
            uint32 language;                                // 8 language, References: Languages, NoValue = 0
            uint32 pageMaterial;                            // 9 pageMaterial, References: PageTextMaterial, NoValue = 0
            uint32 spell;                                   // 10 spell, References: Spell, NoValue = 0
            uint32 noDamageImmune;                          // 11 noDamageImmune, enum { false, true, }; Default: false
            uint32 linkedTrap;                              // 12 linkedTrap, References: GameObjects, NoValue = 0
            uint32 GiganticAOI;                             // 13 Gigantic AOI, enum { false, true, }; Default: false
            uint32 openTextID;                              // 14 openTextID, References: BroadcastText, NoValue = 0
            uint32 closeTextID;                             // 15 closeTextID, References: BroadcastText, NoValue = 0
            uint32 requireLOS;                              // 16 require LOS, enum { false, true, }; Default: false
            uint32 allowMounted;                            // 17 allowMounted, enum { false, true, }; Default: false
            uint32 floatingTooltip;                         // 18 floatingTooltip, enum { false, true, }; Default: false
            uint32 gossipID;                                // 19 gossipID, References: Gossip, NoValue = 0
            uint32 WorldStateSetsState;                     // 20 WorldStateSetsState, enum { false, true, }; Default: false
            uint32 floatOnWater;                            // 21 floatOnWater, enum { false, true, }; Default: false
            uint32 conditionID1;                            // 22 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 playerCast;                              // 23 playerCast, enum { false, true, }; Default: false
            uint32 SpawnVignette;                           // 24 Spawn Vignette, References: vignette, NoValue = 0
            uint32 startOpen;                               // 25 startOpen, enum { false, true, }; Default: false
            uint32 DontPlayOpenAnim;                        // 26 Dont Play Open Anim, enum { false, true, }; Default: false
            uint32 IgnoreBoundingBox;                       // 27 Ignore Bounding Box, enum { false, true, }; Default: false
            uint32 NeverUsableWhileMounted;                 // 28 Never Usable While Mounted, enum { false, true, }; Default: false
            uint32 SortFarZ;                                // 29 Sort Far Z, enum { false, true, }; Default: false
            uint32 SyncAnimationtoObjectLifetime;           // 30 Sync Animation to Object Lifetime (global track only), enum { false, true, }; Default: false
        } goober;
        // 11 GAMEOBJECT_TYPE_TRANSPORT
        struct
        {
            uint32 Timeto2ndfloor;                          // 0 Time to 2nd floor (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 startOpen;                               // 1 startOpen, enum { false, true, }; Default: false
            uint32 autoClose;                               // 2 autoClose (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 Reached1stfloor;                         // 3 Reached 1st floor, References: GameEvents, NoValue = 0
            uint32 Reached2ndfloor;                         // 4 Reached 2nd floor, References: GameEvents, NoValue = 0
            int32 mapID;                                    // 5 mapID, References: Map, NoValue = -1
            uint32 Timeto3rdfloor;                          // 6 Time to 3rd floor (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 Reached3rdfloor;                         // 7 Reached 3rd floor, References: GameEvents, NoValue = 0
            uint32 Timeto4thfloor;                          // 8 Time to 4th floor (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 Reached4thfloor;                         // 9 Reached 4th floor, References: GameEvents, NoValue = 0
            uint32 Timeto5thfloor;                          // 10 Time to 5th floor (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 Reached5thfloor;                         // 11 Reached 5th floor, References: GameEvents, NoValue = 0
            uint32 Timeto6thfloor;                          // 12 Time to 6th floor (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 Reached6thfloor;                         // 13 Reached 6th floor, References: GameEvents, NoValue = 0
            uint32 Timeto7thfloor;                          // 14 Time to 7th floor (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 Reached7thfloor;                         // 15 Reached 7th floor, References: GameEvents, NoValue = 0
            uint32 Timeto8thfloor;                          // 16 Time to 8th floor (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 Reached8thfloor;                         // 17 Reached 8th floor, References: GameEvents, NoValue = 0
            uint32 Timeto9thfloor;                          // 18 Time to 9th floor (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 Reached9thfloor;                         // 19 Reached 9th floor, References: GameEvents, NoValue = 0
            uint32 Timeto10thfloor;                         // 20 Time to 10th floor (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 Reached10thfloor;                        // 21 Reached 10th floor, References: GameEvents, NoValue = 0
            uint32 onlychargeheightcheck;                   // 22 only charge height check. (yards), int, Min value: 0, Max value: 65535, Default value: 0
            uint32 onlychargetimecheck;                     // 23 only charge time check, int, Min value: 0, Max value: 65535, Default value: 0
        } transport;
        // 12 GAMEOBJECT_TYPE_AREADAMAGE
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 radius;                                  // 1 radius, int, Min value: 0, Max value: 50, Default value: 3
            uint32 damageMin;                               // 2 damageMin, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 damageMax;                               // 3 damageMax, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 damageSchool;                            // 4 damageSchool, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 autoClose;                               // 5 autoClose (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 openTextID;                              // 6 openTextID, References: BroadcastText, NoValue = 0
            uint32 closeTextID;                             // 7 closeTextID, References: BroadcastText, NoValue = 0
        } areaDamage;
        // 13 GAMEOBJECT_TYPE_CAMERA
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 camera;                                  // 1 camera, References: CinematicSequences, NoValue = 0
            uint32 eventID;                                 // 2 eventID, References: GameEvents, NoValue = 0
            uint32 openTextID;                              // 3 openTextID, References: BroadcastText, NoValue = 0
            uint32 conditionID1;                            // 4 conditionID1, References: PlayerCondition, NoValue = 0
        } camera;
        // 14 GAMEOBJECT_TYPE_MAP_OBJECT
        struct
        {
        } mapobject;
        // 15 GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT
        struct
        {
            uint32 taxiPathID;                              // 0 taxiPathID, References: TaxiPath, NoValue = 0
            uint32 moveSpeed;                               // 1 moveSpeed, int, Min value: 1, Max value: 60, Default value: 1
            uint32 accelRate;                               // 2 accelRate, int, Min value: 1, Max value: 20, Default value: 1
            uint32 startEventID;                            // 3 startEventID, References: GameEvents, NoValue = 0
            uint32 stopEventID;                             // 4 stopEventID, References: GameEvents, NoValue = 0
            uint32 transportPhysics;                        // 5 transportPhysics, References: TransportPhysics, NoValue = 0
            int32 mapID;                                    // 6 mapID, References: Map, NoValue = -1
            uint32 worldState1;                             // 7 worldState1, References: WorldState, NoValue = 0
            uint32 allowstopping;                           // 8 allow stopping, enum { false, true, }; Default: false
            uint32 InitStopped;                             // 9 Init Stopped, enum { false, true, }; Default: false
            uint32 TrueInfiniteAOI;                         // 10 True Infinite AOI (programmer only!), enum { false, true, }; Default: false
        } moTransport;
        // 16 GAMEOBJECT_TYPE_DUEL_ARBITER
        struct
        {
        } duelFlag;
        // 17 GAMEOBJECT_TYPE_FISHINGNODE
        struct
        {
        } fishingNode;
        // 18 GAMEOBJECT_TYPE_RITUAL
        struct
        {
            uint32 casters;                                 // 0 casters, int, Min value: 1, Max value: 10, Default value: 1
            uint32 spell;                                   // 1 spell, References: Spell, NoValue = 0
            uint32 animSpell;                               // 2 animSpell, References: Spell, NoValue = 0
            uint32 ritualPersistent;                        // 3 ritualPersistent, enum { false, true, }; Default: false
            uint32 casterTargetSpell;                       // 4 casterTargetSpell, References: Spell, NoValue = 0
            uint32 casterTargetSpellTargets;                // 5 casterTargetSpellTargets, int, Min value: 1, Max value: 10, Default value: 1
            uint32 castersGrouped;                          // 6 castersGrouped, enum { false, true, }; Default: true
            uint32 ritualNoTargetCheck;                     // 7 ritualNoTargetCheck, enum { false, true, }; Default: true
            uint32 conditionID1;                            // 8 conditionID1, References: PlayerCondition, NoValue = 0
        } ritual;
        // 19 GAMEOBJECT_TYPE_MAILBOX
        struct
        {
            uint32 conditionID1;                            // 0 conditionID1, References: PlayerCondition, NoValue = 0
        } mailbox;
        // 20 GAMEOBJECT_TYPE_DO_NOT_USE
        struct
        {
        } DONOTUSE;
        // 21 GAMEOBJECT_TYPE_GUARDPOST
        struct
        {
            uint32 creatureID;                              // 0 creatureID, References: Creature, NoValue = 0
            uint32 charges;                                 // 1 charges, int, Min value: 0, Max value: 65535, Default value: 1
        } guardPost;
        // 22 GAMEOBJECT_TYPE_SPELLCASTER
        struct
        {
            uint32 spell;                                   // 0 spell, References: Spell, NoValue = 0
            int32 charges;                                  // 1 charges, int, Min value: -1, Max value: 65535, Default value: 1
            uint32 partyOnly;                               // 2 partyOnly, enum { false, true, }; Default: false
            uint32 allowMounted;                            // 3 allowMounted, enum { false, true, }; Default: false
            uint32 GiganticAOI;                             // 4 Gigantic AOI, enum { false, true, }; Default: false
            uint32 conditionID1;                            // 5 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 playerCast;                              // 6 playerCast, enum { false, true, }; Default: false
            uint32 NeverUsableWhileMounted;                 // 7 Never Usable While Mounted, enum { false, true, }; Default: false
        } spellCaster;
        // 23 GAMEOBJECT_TYPE_MEETINGSTONE
        struct
        {
            uint32 minLevel;                                // 0 minLevel, int, Min value: 0, Max value: 65535, Default value: 1
            uint32 maxLevel;                                // 1 maxLevel, int, Min value: 1, Max value: 65535, Default value: 60
            uint32 areaID;                                  // 2 areaID, References: AreaTable, NoValue = 0
        } meetingStone;
        // 24 GAMEOBJECT_TYPE_FLAGSTAND
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 pickupSpell;                             // 1 pickupSpell, References: Spell, NoValue = 0
            uint32 radius;                                  // 2 radius, int, Min value: 0, Max value: 50, Default value: 0
            uint32 returnAura;                              // 3 returnAura, References: Spell, NoValue = 0
            uint32 returnSpell;                             // 4 returnSpell, References: Spell, NoValue = 0
            uint32 noDamageImmune;                          // 5 noDamageImmune, enum { false, true, }; Default: false
            uint32 openTextID;                              // 6 openTextID, References: BroadcastText, NoValue = 0
            uint32 requireLOS;                              // 7 require LOS, enum { false, true, }; Default: true
            uint32 conditionID1;                            // 8 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 playerCast;                              // 9 playerCast, enum { false, true, }; Default: false
            uint32 GiganticAOI;                             // 10 Gigantic AOI, enum { false, true, }; Default: false
            uint32 InfiniteAOI;                             // 11 Infinite AOI, enum { false, true, }; Default: false
            uint32 cooldown;                                // 12 cooldown, int, Min value: 0, Max value: 2147483647, Default value: 3000
        } flagStand;
        // 25 GAMEOBJECT_TYPE_FISHINGHOLE
        struct
        {
            uint32 radius;                                  // 0 radius, int, Min value: 0, Max value: 50, Default value: 0
            uint32 chestLoot;                               // 1 chestLoot, References: Treasure, NoValue = 0
            uint32 minRestock;                              // 2 minRestock, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 maxRestock;                              // 3 maxRestock, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 open;                                    // 4 open, References: Lock_, NoValue = 0
        } fishingHole;
        // 26 GAMEOBJECT_TYPE_FLAGDROP
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 eventID;                                 // 1 eventID, References: GameEvents, NoValue = 0
            uint32 pickupSpell;                             // 2 pickupSpell, References: Spell, NoValue = 0
            uint32 noDamageImmune;                          // 3 noDamageImmune, enum { false, true, }; Default: false
            uint32 openTextID;                              // 4 openTextID, References: BroadcastText, NoValue = 0
            uint32 playerCast;                              // 5 playerCast, enum { false, true, }; Default: false
            uint32 ExpireDuration;                          // 6 Expire Duration, int, Min value: 0, Max value: 60000, Default value: 10000
            uint32 GiganticAOI;                             // 7 Gigantic AOI, enum { false, true, }; Default: false
            uint32 InfiniteAOI;                             // 8 Infinite AOI, enum { false, true, }; Default: false
            uint32 cooldown;                                // 9 cooldown, int, Min value: 0, Max value: 2147483647, Default value: 3000
        } flagDrop;
        // 27 GAMEOBJECT_TYPE_MINI_GAME
        struct
        {
        } DONOTUSE3;
        // 28 GAMEOBJECT_TYPE_DO_NOT_USE_2
        struct
        {
        } DONOTUSE2;
        // 29 GAMEOBJECT_TYPE_CONTROL_ZONE
        struct
        {
            uint32 radius;                                  // 0 radius, int, Min value: 0, Max value: 100, Default value: 10
            uint32 spell;                                   // 1 spell, References: Spell, NoValue = 0
            uint32 worldState1;                             // 2 worldState1, References: WorldState, NoValue = 0
            uint32 worldstate2;                             // 3 worldstate2, References: WorldState, NoValue = 0
            uint32 CaptureEventHorde;                       // 4 Capture Event (Horde), References: GameEvents, NoValue = 0
            uint32 CaptureEventAlliance;                    // 5 Capture Event (Alliance), References: GameEvents, NoValue = 0
            uint32 ContestedEventHorde;                     // 6 Contested Event (Horde), References: GameEvents, NoValue = 0
            uint32 ContestedEventAlliance;                  // 7 Contested Event (Alliance), References: GameEvents, NoValue = 0
            uint32 ProgressEventHorde;                      // 8 Progress Event (Horde), References: GameEvents, NoValue = 0
            uint32 ProgressEventAlliance;                   // 9 Progress Event (Alliance), References: GameEvents, NoValue = 0
            uint32 NeutralEventHorde;                       // 10 Neutral Event (Horde), References: GameEvents, NoValue = 0
            uint32 NeutralEventAlliance;                    // 11 Neutral Event (Alliance), References: GameEvents, NoValue = 0
            uint32 neutralPercent;                          // 12 neutralPercent, int, Min value: 0, Max value: 100, Default value: 0
            uint32 worldstate3;                             // 13 worldstate3, References: WorldState, NoValue = 0
            uint32 minSuperiority;                          // 14 minSuperiority, int, Min value: 1, Max value: 65535, Default value: 1
            uint32 maxSuperiority;                          // 15 maxSuperiority, int, Min value: 1, Max value: 65535, Default value: 1
            uint32 minTime;                                 // 16 minTime, int, Min value: 1, Max value: 65535, Default value: 1
            uint32 maxTime;                                 // 17 maxTime, int, Min value: 1, Max value: 65535, Default value: 1
            uint32 GiganticAOI;                             // 18 Gigantic AOI, enum { false, true, }; Default: false
            uint32 highlight;                               // 19 highlight, enum { false, true, }; Default: true
            uint32 startingValue;                           // 20 startingValue, int, Min value: 0, Max value: 100, Default value: 50
            uint32 unidirectional;                          // 21 unidirectional, enum { false, true, }; Default: false
            uint32 killbonustime;                           // 22 kill bonus time %, int, Min value: 0, Max value: 100, Default value: 0
            uint32 speedWorldState1;                        // 23 speedWorldState1, References: WorldState, NoValue = 0
            uint32 speedWorldState2;                        // 24 speedWorldState2, References: WorldState, NoValue = 0
            uint32 UncontestedTime;                         // 25 Uncontested Time, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 FrequentHeartbeat;                       // 26 Frequent Heartbeat, enum { false, true, }; Default: false
        } controlZone;
        // 30 GAMEOBJECT_TYPE_AURA_GENERATOR
        struct
        {
            uint32 startOpen;                               // 0 startOpen, enum { false, true, }; Default: true
            uint32 radius;                                  // 1 radius, int, Min value: 0, Max value: 100, Default value: 10
            uint32 auraID1;                                 // 2 auraID1, References: Spell, NoValue = 0
            uint32 conditionID1;                            // 3 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 auraID2;                                 // 4 auraID2, References: Spell, NoValue = 0
            uint32 conditionID2;                            // 5 conditionID2, References: PlayerCondition, NoValue = 0
            uint32 serverOnly;                              // 6 serverOnly, enum { false, true, }; Default: false
        } auraGenerator;
        // 31 GAMEOBJECT_TYPE_DUNGEON_DIFFICULTY
        struct
        {
            uint32 InstanceType;                            // 0 Instance Type, enum { Not Instanced, Party Dungeon, Raid Dungeon, PVP Battlefield, Arena Battlefield, Scenario, }; Default: Party Dungeon
            uint32 DifficultyNormal;                        // 1 Difficulty Normal, References: animationdata, NoValue = 0
            uint32 DifficultyHeroic;                        // 2 Difficulty Heroic, References: animationdata, NoValue = 0
            uint32 DifficultyEpic;                          // 3 Difficulty Epic, References: animationdata, NoValue = 0
            uint32 DifficultyLegendary;                     // 4 Difficulty Legendary, References: animationdata, NoValue = 0
            uint32 HeroicAttachment;                        // 5 Heroic Attachment, References: gameobjectdisplayinfo, NoValue = 0
            uint32 ChallengeAttachment;                     // 6 Challenge Attachment, References: gameobjectdisplayinfo, NoValue = 0
            uint32 DifficultyAnimations;                    // 7 Difficulty Animations, References: GameObjectDiffAnim, NoValue = 0
            uint32 LargeAOI;                                // 8 Large AOI, enum { false, true, }; Default: false
            uint32 GiganticAOI;                             // 9 Gigantic AOI, enum { false, true, }; Default: false
            uint32 Legacy;                                  // 10 Legacy, enum { false, true, }; Default: false
        } dungeonDifficulty;
        // 32 GAMEOBJECT_TYPE_BARBER_CHAIR
        struct
        {
            uint32 chairheight;                             // 0 chairheight, int, Min value: 0, Max value: 2, Default value: 1
            int32 HeightOffset;                             // 1 Height Offset (inches), int, Min value: -100, Max value: 100, Default value: 0
        } barberChair;
        // 33 GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING
        struct
        {
            int32 Unused;                                   // 0 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 CreditProxyCreature;                     // 1 Credit Proxy Creature, References: Creature, NoValue = 0
            uint32 HealthRec;                               // 2 Health Rec, References: DestructibleHitpoint, NoValue = 0
            uint32 IntactEvent;                             // 3 Intact Event, References: GameEvents, NoValue = 0
            uint32 PVPEnabling;                             // 4 PVP Enabling, enum { false, true, }; Default: false
            uint32 InteriorVisible;                         // 5 Interior Visible, enum { false, true, }; Default: false
            uint32 InteriorLight;                           // 6 Interior Light, enum { false, true, }; Default: false
            int32 Unused1;                                  // 7 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            int32 Unused2;                                  // 8 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 DamagedEvent;                            // 9 Damaged Event, References: GameEvents, NoValue = 0
            int32 Unused3;                                  // 10 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            int32 Unused4;                                  // 11 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            int32 Unused5;                                  // 12 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            int32 Unused6;                                  // 13 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 DestroyedEvent;                          // 14 Destroyed Event, References: GameEvents, NoValue = 0
            int32 Unused7;                                  // 15 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 RebuildingTime;                          // 16 Rebuilding: Time (secs), int, Min value: 0, Max value: 65535, Default value: 0
            int32 Unused8;                                  // 17 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 DestructibleModelRec;                    // 18 Destructible Model Rec, References: DestructibleModelData, NoValue = 0
            uint32 RebuildingEvent;                         // 19 Rebuilding: Event, References: GameEvents, NoValue = 0
            int32 Unused9;                                  // 20 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            int32 Unused10;                                 // 21 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 DamageEvent;                             // 22 Damage Event, References: GameEvents, NoValue = 0
        } destructibleBuilding;
        // 34 GAMEOBJECT_TYPE_GUILD_BANK
        struct
        {
            uint32 conditionID1;                            // 0 conditionID1, References: PlayerCondition, NoValue = 0
        } guildbank;
        // 35 GAMEOBJECT_TYPE_TRAPDOOR
        struct
        {
            int32 Unused;                                   // 0 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 startOpen;                               // 1 startOpen, enum { false, true, }; Default: false
            uint32 autoClose;                               // 2 autoClose (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 BlocksPathsDown;                         // 3 Blocks Paths Down, enum { false, true, }; Default: false
        } trapdoor;
        // 36 GAMEOBJECT_TYPE_NEW_FLAG
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 pickupSpell;                             // 1 pickupSpell, References: Spell, NoValue = 0
            uint32 openTextID;                              // 2 openTextID, References: BroadcastText, NoValue = 0
            uint32 requireLOS;                              // 3 require LOS, enum { false, true, }; Default: true
            uint32 conditionID1;                            // 4 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 GiganticAOI;                             // 5 Gigantic AOI, enum { false, true, }; Default: false
            uint32 InfiniteAOI;                             // 6 Infinite AOI, enum { false, true, }; Default: false
            uint32 ExpireDuration;                          // 7 Expire Duration, int, Min value: 0, Max value: 3600000, Default value: 10000
            uint32 RespawnTime;                             // 8 Respawn Time, int, Min value: 0, Max value: 3600000, Default value: 20000
            uint32 FlagDrop;                                // 9 Flag Drop, References: GameObjects, NoValue = 0
            int32 ExclusiveCategory;                        // 10 Exclusive Category (BGs Only), int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 worldState1;                             // 11 worldState1, References: WorldState, NoValue = 0
            uint32 ReturnonDefenderInteract;                // 12 Return on Defender Interact, enum { false, true, }; Default: false
        } newflag;
        // 37 GAMEOBJECT_TYPE_NEW_FLAG_DROP
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
        } newflagdrop;
        // 38 GAMEOBJECT_TYPE_GARRISON_BUILDING
        struct
        {
            int32 mapID;                                    // 0 mapID, References: Map, NoValue = -1
        } garrisonBuilding;
        // 39 GAMEOBJECT_TYPE_GARRISON_PLOT
        struct
        {
            uint32 PlotInstance;                            // 0 Plot Instance, References: GarrPlotInstance, NoValue = 0
            int32 mapID;                                    // 1 mapID, References: Map, NoValue = -1
        } garrisonPlot;
        // 40 GAMEOBJECT_TYPE_CLIENT_CREATURE
        struct
        {
            uint32 CreatureDisplayInfo;                     // 0 Creature Display Info, References: CreatureDisplayInfo, NoValue = 0
            uint32 AnimKit;                                 // 1 Anim Kit, References: AnimKit, NoValue = 0
            uint32 creatureID;                              // 2 creatureID, References: Creature, NoValue = 0
        } clientCreature;
        // 41 GAMEOBJECT_TYPE_CLIENT_ITEM
        struct
        {
            uint32 Item;                                    // 0 Item, References: Item, NoValue = 0
        } clientItem;
        // 42 GAMEOBJECT_TYPE_CAPTURE_POINT
        struct
        {
            uint32 CaptureTime;                             // 0 Capture Time (ms), int, Min value: 0, Max value: 2147483647, Default value: 60000
            uint32 GiganticAOI;                             // 1 Gigantic AOI, enum { false, true, }; Default: false
            uint32 highlight;                               // 2 highlight, enum { false, true, }; Default: true
            uint32 open;                                    // 3 open, References: Lock_, NoValue = 0
            uint32 AssaultBroadcastHorde;                   // 4 Assault Broadcast (Horde), References: BroadcastText, NoValue = 0
            uint32 CaptureBroadcastHorde;                   // 5 Capture Broadcast (Horde), References: BroadcastText, NoValue = 0
            uint32 DefendedBroadcastHorde;                  // 6 Defended Broadcast (Horde), References: BroadcastText, NoValue = 0
            uint32 AssaultBroadcastAlliance;                // 7 Assault Broadcast (Alliance), References: BroadcastText, NoValue = 0
            uint32 CaptureBroadcastAlliance;                // 8 Capture Broadcast (Alliance), References: BroadcastText, NoValue = 0
            uint32 DefendedBroadcastAlliance;               // 9 Defended Broadcast (Alliance), References: BroadcastText, NoValue = 0
            uint32 worldState1;                             // 10 worldState1, References: WorldState, NoValue = 0
            uint32 ContestedEventHorde;                     // 11 Contested Event (Horde), References: GameEvents, NoValue = 0
            uint32 CaptureEventHorde;                       // 12 Capture Event (Horde), References: GameEvents, NoValue = 0
            uint32 DefendedEventHorde;                      // 13 Defended Event (Horde), References: GameEvents, NoValue = 0
            uint32 ContestedEventAlliance;                  // 14 Contested Event (Alliance), References: GameEvents, NoValue = 0
            uint32 CaptureEventAlliance;                    // 15 Capture Event (Alliance), References: GameEvents, NoValue = 0
            uint32 DefendedEventAlliance;                   // 16 Defended Event (Alliance), References: GameEvents, NoValue = 0
            uint32 SpellVisual1;                            // 17 Spell Visual 1, References: SpellVisual, NoValue = 0
            uint32 SpellVisual2;                            // 18 Spell Visual 2, References: SpellVisual, NoValue = 0
            uint32 SpellVisual3;                            // 19 Spell Visual 3, References: SpellVisual, NoValue = 0
            uint32 SpellVisual4;                            // 20 Spell Visual 4, References: SpellVisual, NoValue = 0
            uint32 SpellVisual5;                            // 21 Spell Visual 5, References: SpellVisual, NoValue = 0
        } capturePoint;
        // 43 GAMEOBJECT_TYPE_PHASEABLE_MO
        struct
        {
            int32 mapID;                                    // 0 mapID, References: Map, NoValue = -1
            int32 namedset;                                 // 1 named set, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
        } phaseableMO;
        // 44 GAMEOBJECT_TYPE_GARRISON_MONUMENT
        struct
        {
            uint32 TrophyTypeID;                            // 0 Trophy Type ID, References: TrophyType, NoValue = 0
            uint32 TrophyInstanceID;                        // 1 Trophy Instance ID, References: TrophyInstance, NoValue = 0
        } garrisonMonument;
        // 45 GAMEOBJECT_TYPE_GARRISON_SHIPMENT
        struct
        {
            uint32 ShipmentContainer;                       // 0 Shipment Container, References: CharShipmentContainer, NoValue = 0
        } garrisonShipment;
        // 46 GAMEOBJECT_TYPE_GARRISON_MONUMENT_PLAQUE
        struct
        {
            uint32 TrophyInstanceID;                        // 0 Trophy Instance ID, References: TrophyInstance, NoValue = 0
        } garrisonMonumentPlaque;
        struct
        {
            uint32 data[MAX_GAMEOBJECT_DATA];
        } raw;
    };

    std::string AIName;
    uint32 ScriptId;

    // helpers
    bool IsDespawnAtAction() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_CHEST:  return chest.consumable != 0;
            case GAMEOBJECT_TYPE_GOOBER: return goober.consumable != 0;
            default: return false;
        }
    }

    bool IsUsableMounted() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_QUESTGIVER: return questgiver.allowMounted != 0;
            case GAMEOBJECT_TYPE_TEXT: return text.allowMounted != 0;
            case GAMEOBJECT_TYPE_GOOBER: return goober.allowMounted != 0;
            case GAMEOBJECT_TYPE_SPELLCASTER: return spellCaster.allowMounted != 0;
            default: return false;
        }
    }

    uint32 GetLockId() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_DOOR:          return door.open;
            case GAMEOBJECT_TYPE_BUTTON:        return button.open;
            case GAMEOBJECT_TYPE_QUESTGIVER:    return questgiver.open;
            case GAMEOBJECT_TYPE_CHEST:         return chest.open;
            case GAMEOBJECT_TYPE_TRAP:          return trap.open;
            case GAMEOBJECT_TYPE_GOOBER:        return goober.open;
            case GAMEOBJECT_TYPE_AREADAMAGE:    return areaDamage.open;
            case GAMEOBJECT_TYPE_CAMERA:        return camera.open;
            case GAMEOBJECT_TYPE_FLAGSTAND:     return flagStand.open;
            case GAMEOBJECT_TYPE_FISHINGHOLE:   return fishingHole.open;
            case GAMEOBJECT_TYPE_FLAGDROP:      return flagDrop.open;
            case GAMEOBJECT_TYPE_NEW_FLAG:      return newflag.open;
            case GAMEOBJECT_TYPE_NEW_FLAG_DROP: return newflagdrop.open;
            case GAMEOBJECT_TYPE_CAPTURE_POINT: return capturePoint.open;
            default: return 0;
        }
    }

    bool GetDespawnPossibility() const                      // despawn at targeting of cast?
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_DOOR:       return door.noDamageImmune != 0;
            case GAMEOBJECT_TYPE_BUTTON:     return button.noDamageImmune != 0;
            case GAMEOBJECT_TYPE_QUESTGIVER: return questgiver.noDamageImmune != 0;
            case GAMEOBJECT_TYPE_GOOBER:     return goober.noDamageImmune != 0;
            case GAMEOBJECT_TYPE_FLAGSTAND:  return flagStand.noDamageImmune != 0;
            case GAMEOBJECT_TYPE_FLAGDROP:   return flagDrop.noDamageImmune != 0;
            default: return true;
        }
    }

    uint32 GetCharges() const                               // despawn at uses amount
    {
        switch (type)
        {
            //case GAMEOBJECT_TYPE_TRAP:        return trap.charges;
            case GAMEOBJECT_TYPE_GUARDPOST:   return guardPost.charges;
            case GAMEOBJECT_TYPE_SPELLCASTER: return spellCaster.charges;
            default: return 0;
        }
    }

    uint32 GetLinkedGameObjectEntry() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_BUTTON:      return button.linkedTrap;
            case GAMEOBJECT_TYPE_CHEST:       return chest.linkedTrap;
            case GAMEOBJECT_TYPE_SPELL_FOCUS: return spellFocus.linkedTrap;
            case GAMEOBJECT_TYPE_GOOBER:      return goober.linkedTrap;
            default: return 0;
        }
    }

    uint32 GetAutoCloseTime() const
    {
        uint32 autoCloseTime = 0;
        switch (type)
        {
            case GAMEOBJECT_TYPE_DOOR:          autoCloseTime = door.autoClose; break;
            case GAMEOBJECT_TYPE_BUTTON:        autoCloseTime = button.autoClose; break;
            case GAMEOBJECT_TYPE_TRAP:          autoCloseTime = trap.autoClose; break;
            case GAMEOBJECT_TYPE_GOOBER:        autoCloseTime = goober.autoClose; break;
            case GAMEOBJECT_TYPE_TRANSPORT:     autoCloseTime = transport.autoClose; break;
            case GAMEOBJECT_TYPE_AREADAMAGE:    autoCloseTime = areaDamage.autoClose; break;
            case GAMEOBJECT_TYPE_TRAPDOOR:      autoCloseTime = trapdoor.autoClose; break;
            default: break;
        }
        return autoCloseTime / IN_MILLISECONDS;              // prior to 3.0.3, conversion was / 0x10000;
    }

    uint32 GetLootId() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_CHEST:       return chest.chestLoot;
            case GAMEOBJECT_TYPE_FISHINGHOLE: return fishingHole.chestLoot;
            default: return 0;
        }
    }

    uint32 GetGossipMenuId() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_QUESTGIVER:    return questgiver.gossipID;
            case GAMEOBJECT_TYPE_GOOBER:        return goober.gossipID;
            default: return 0;
        }
    }

    uint32 GetEventScriptId() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_GOOBER:        return goober.eventID;
            case GAMEOBJECT_TYPE_CHEST:         return chest.triggeredEvent;
            case GAMEOBJECT_TYPE_CAMERA:        return camera.eventID;
            default: return 0;
        }
    }

    uint32 GetCooldown() const                              // Cooldown preventing goober and traps to cast spell
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_TRAP:        return trap.cooldown;
            case GAMEOBJECT_TYPE_GOOBER:      return goober.cooldown;
            default: return 0;
        }
    }
};

// Benchmarked: Faster than std::map (insert/find)
typedef std::unordered_map<uint32, GameObjectTemplate> GameObjectTemplateContainer;

class OPvPCapturePoint;
struct TransportAnimation;

union GameObjectValue
{
    //11 GAMEOBJECT_TYPE_TRANSPORT
    struct
    {
        uint32 PathProgress;
        TransportAnimation const* AnimationInfo;
        uint32 CurrentSeg;
        std::vector<uint32>* StopFrames;
        uint32 StateUpdateTimer;
    } Transport;
    //25 GAMEOBJECT_TYPE_FISHINGHOLE
    struct
    {
        uint32 MaxOpens;
    } FishingHole;
    //29 GAMEOBJECT_TYPE_CAPTURE_POINT
    struct
    {
        OPvPCapturePoint *OPvPObj;
    } CapturePoint;
    //33 GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING
    struct
    {
        uint32 Health;
        uint32 MaxHealth;
    } Building;
};

struct GameObjectLocale
{
    StringVector Name;
    StringVector CastBarCaption;
};

// client side GO show states
enum GOState
{
    GO_STATE_ACTIVE             = 0,                        // show in world as used and not reset (closed door open)
    GO_STATE_READY              = 1,                        // show in world as ready (closed door close)
    GO_STATE_ACTIVE_ALTERNATIVE = 2,                        // show in world as used in alt way and not reset (closed door open by cannon fire)
    GO_STATE_TRANSPORT_ACTIVE   = 24,
    GO_STATE_TRANSPORT_STOPPED  = 25
};

#define MAX_GO_STATE              3
#define MAX_GO_STATE_TRANSPORT_STOP_FRAMES 9

// from `gameobject`
struct GameObjectData
{
    explicit GameObjectData() : id(0), mapid(0), phaseMask(0), posX(0.0f), posY(0.0f), posZ(0.0f), orientation(0.0f),
                                rotation0(0.0f), rotation1(0.0f), rotation2(0.0f), rotation3(0.0f), spawntimesecs(0),
                                animprogress(0), go_state(GO_STATE_ACTIVE), spawnMask(0), artKit(0), phaseid(0), phaseGroup(0), dbData(true) { }
    uint32 id;                                              // entry in gamobject_template
    uint16 mapid;
    uint32 phaseMask;
    float posX;
    float posY;
    float posZ;
    float orientation;
    float rotation0;
    float rotation1;
    float rotation2;
    float rotation3;
    int32  spawntimesecs;
    uint32 animprogress;
    GOState go_state;
    uint32 spawnMask;
    uint8 artKit;
    uint32 phaseid;
    uint32 phaseGroup;
    bool dbData;
};

// For containers:  [GO_NOT_READY]->GO_READY (close)->GO_ACTIVATED (open) ->GO_JUST_DEACTIVATED->GO_READY        -> ...
// For bobber:      GO_NOT_READY  ->GO_READY (close)->GO_ACTIVATED (open) ->GO_JUST_DEACTIVATED-><deleted>
// For door(closed):[GO_NOT_READY]->GO_READY (close)->GO_ACTIVATED (open) ->GO_JUST_DEACTIVATED->GO_READY(close) -> ...
// For door(open):  [GO_NOT_READY]->GO_READY (open) ->GO_ACTIVATED (close)->GO_JUST_DEACTIVATED->GO_READY(open)  -> ...
enum LootState
{
    GO_NOT_READY = 0,
    GO_READY,                                               // can be ready but despawned, and then not possible activate until spawn
    GO_ACTIVATED,
    GO_JUST_DEACTIVATED
};

class Unit;
class GameObjectModel;

// 5 sec for bobber catch
#define FISHING_BOBBER_READY_TIME 5

class GameObject : public WorldObject, public GridObject<GameObject>, public MapObject
{
    public:
        explicit GameObject();
        ~GameObject();

        void BuildValuesUpdate(uint8 updatetype, ByteBuffer* data, Player* target) const override;

        void AddToWorld() override;
        void RemoveFromWorld() override;
        void CleanupsBeforeDelete(bool finalCleanup = true) override;

        bool Create(ObjectGuid::LowType guidlow, uint32 name_id, Map* map, uint32 phaseMask, float x, float y, float z, float ang, float rotation0, float rotation1, float rotation2, float rotation3, uint32 animprogress, GOState go_state, uint32 artKit = 0);
        void Update(uint32 p_time) override;
        GameObjectTemplate const* GetGOInfo() const { return m_goInfo; }
        GameObjectData const* GetGOData() const { return m_goData; }
        GameObjectValue const* GetGOValue() const { return &m_goValue; }

        bool IsTransport() const;
        bool IsDynTransport() const;
        bool IsDestructibleBuilding() const;

        ObjectGuid::LowType GetDBTableGUIDLow() const { return m_DBTableGuid; }

        void UpdateRotationFields(float rotation2 = 0.0f, float rotation3 = 0.0f);

        // overwrite WorldObject function for proper name localization
        std::string const& GetNameForLocaleIdx(LocaleConstant locale_idx) const override;

        void SaveToDB();
        void SaveToDB(uint32 mapid, uint32 spawnMask, uint32 phaseMask);
        bool LoadFromDB(ObjectGuid::LowType guid, Map* map) { return LoadGameObjectFromDB(guid, map, false); }
        bool LoadGameObjectFromDB(ObjectGuid::LowType guid, Map* map, bool addToMap = true);
        void DeleteFromDB();

        void SetOwnerGUID(ObjectGuid owner)
        {
            // Owner already found and different than expected owner - remove object from old owner
            if (!owner.IsEmpty() && !GetOwnerGUID().IsEmpty() && GetOwnerGUID() != owner)
            {
                ASSERT(false);
            }
            m_spawnedByDefault = false;                     // all object with owner is despawned after delay
            SetGuidValue(GAMEOBJECT_FIELD_CREATED_BY, owner);
        }
        ObjectGuid GetOwnerGUID() const { return GetGuidValue(GAMEOBJECT_FIELD_CREATED_BY); }
        Unit* GetOwner() const;

        void SetSpellId(uint32 id)
        {
            m_spawnedByDefault = false;                     // all summoned object is despawned after delay
            m_spellId = id;
        }
        uint32 GetSpellId() const { return m_spellId;}

        time_t GetRespawnTime() const { return m_respawnTime; }
        time_t GetRespawnTimeEx() const
        {
            time_t now = time(NULL);
            if (m_respawnTime > now)
                return m_respawnTime;
            else
                return now;
        }

        void SetRespawnTime(int32 respawn)
        {
            m_respawnTime = respawn > 0 ? time(NULL) + respawn : 0;
            m_respawnDelayTime = respawn > 0 ? respawn : 0;
        }
        void Respawn();
        bool isSpawned() const
        {
            return m_respawnDelayTime == 0 ||
                (m_respawnTime > 0 && !m_spawnedByDefault) ||
                (m_respawnTime == 0 && m_spawnedByDefault);
        }
        bool isSpawnedByDefault() const { return m_spawnedByDefault; }
        void SetSpawnedByDefault(bool b) { m_spawnedByDefault = b; }
        uint32 GetRespawnDelay() const { return m_respawnDelayTime; }
        void Refresh();
        void Delete();
        void getFishLoot(Loot* loot, Player* loot_owner);
        void getFishLootJunk(Loot* loot, Player* loot_owner);
        GameobjectTypes GetGoType() const { return GameobjectTypes(GetByteValue(GAMEOBJECT_BYTES_1, 1)); }
        void SetGoType(GameobjectTypes type) { SetByteValue(GAMEOBJECT_BYTES_1, 1, type); }
        GOState GetGoState() const { return GOState(GetByteValue(GAMEOBJECT_BYTES_1, 0)); }
        void SetGoState(GOState state);
        uint32 GetTransportPeriod() const;
        void SetTransportState(GOState state, uint32 stopFrame = 0);
        uint8 GetGoArtKit() const { return GetByteValue(GAMEOBJECT_BYTES_1, 2); }
        void SetGoArtKit(uint8 artkit);
        uint8 GetGoAnimProgress() const { return GetByteValue(GAMEOBJECT_BYTES_1, 3); }
        void SetGoAnimProgress(uint8 animprogress) { SetByteValue(GAMEOBJECT_BYTES_1, 3, animprogress); }
        static void SetGoArtKit(uint8 artkit, GameObject* go, ObjectGuid::LowType lowguid = UI64LIT(0));

        void SetInPhase(uint32 id, bool update, bool apply);
        void EnableCollision(bool enable);

        void Use(Unit* user);

        LootState getLootState() const { return m_lootState; }
        // Note: unit is only used when s = GO_ACTIVATED
        void SetLootState(LootState s, Unit* unit = NULL);

        uint16 GetLootMode() { return m_LootMode; }
        bool HasLootMode(uint16 lootMode) { return (m_LootMode & lootMode) != 0; }
        void SetLootMode(uint16 lootMode) { m_LootMode = lootMode; }
        void AddLootMode(uint16 lootMode) { m_LootMode |= lootMode; }
        void RemoveLootMode(uint16 lootMode) { m_LootMode &= ~lootMode; }
        void ResetLootMode() { m_LootMode = LOOT_MODE_DEFAULT; }

        void AddToSkillupList(ObjectGuid const& PlayerGuidLow) { m_SkillupList.insert(PlayerGuidLow); }
        bool IsInSkillupList(ObjectGuid const& playerGuid) const
        {
            return m_SkillupList.count(playerGuid) > 0;
        }
        void ClearSkillupList() { m_SkillupList.clear(); }

        void AddUniqueUse(Player* player);
        void AddUse() { ++m_usetimes; }

        uint32 GetUseCount() const { return m_usetimes; }
        uint32 GetUniqueUseCount() const { return m_unique_users.size(); }

        void SaveRespawnTime() override;

        Loot        loot;

        Player* GetLootRecipient() const;
        Group* GetLootRecipientGroup() const;
        void SetLootRecipient(Unit* unit);
        bool IsLootAllowedFor(Player const* player) const;
        bool HasLootRecipient() const { return !m_lootRecipient.IsEmpty() || !m_lootRecipientGroup.IsEmpty(); }
        uint32 m_groupLootTimer;                            // (msecs)timer used for group loot
        ObjectGuid lootingGroupLowGUID;                     // used to find group which is looting

        bool hasQuest(uint32 quest_id) const override;
        bool hasInvolvedQuest(uint32 quest_id) const override;
        bool ActivateToQuest(Player* target) const;
        void UseDoorOrButton(uint32 time_to_restore = 0, bool alternative = false, Unit* user = NULL);
                                                            // 0 = use `gameobject`.`spawntimesecs`
        void ResetDoorOrButton();

        void TriggeringLinkedGameObject(uint32 trapEntry, Unit* target);

        bool IsNeverVisible() const override;

        bool IsAlwaysVisibleFor(WorldObject const* seer) const override;
        bool IsInvisibleDueToDespawn() const override;

        uint8 getLevelForTarget(WorldObject const* target) const override
        {
            if (Unit* owner = GetOwner())
                return owner->getLevelForTarget(target);

            return 1;
        }

        GameObject* LookupFishingHoleAround(float range);

        void CastSpell(Unit* target, uint32 spell, bool triggered = true);
        void SendCustomAnim(uint32 anim);
        bool IsInRange(float x, float y, float z, float radius) const;

        void ModifyHealth(int32 change, Unit* attackerOrHealer = NULL, uint32 spellId = 0);
        // sets GameObject type 33 destruction flags and optionally default health for that state
        void SetDestructibleState(GameObjectDestructibleState state, Player* eventInvoker = NULL, bool setHealth = false);
        GameObjectDestructibleState GetDestructibleState() const
        {
            if (HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED))
                return GO_DESTRUCTIBLE_DESTROYED;
            if (HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_DAMAGED))
                return GO_DESTRUCTIBLE_DAMAGED;
            return GO_DESTRUCTIBLE_INTACT;
        }

        void EventInform(uint32 eventId, WorldObject* invoker = NULL);

        uint64 GetRotation() const { return m_rotation; }
        virtual uint32 GetScriptId() const { return GetGOInfo()->ScriptId; }
        GameObjectAI* AI() const { return m_AI; }

        std::string GetAIName() const;
        void SetDisplayId(uint32 displayid);
        uint32 GetDisplayId() const { return GetUInt32Value(GAMEOBJECT_DISPLAYID); }

        uint32 GetFaction() const { return GetUInt32Value(GAMEOBJECT_FACTION); }
        void SetFaction(uint32 faction) { SetUInt32Value(GAMEOBJECT_FACTION, faction); }

        GameObjectModel* m_model;
        void GetRespawnPosition(float &x, float &y, float &z, float* ori = NULL) const;

        Transport* ToTransport() { if (GetGOInfo()->type == GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT) return reinterpret_cast<Transport*>(this); else return NULL; }
        Transport const* ToTransport() const { if (GetGOInfo()->type == GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT) return reinterpret_cast<Transport const*>(this); else return NULL; }

        float GetStationaryX() const override { if (GetGOInfo()->type != GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT) return m_stationaryPosition.GetPositionX(); return GetPositionX(); }
        float GetStationaryY() const override { if (GetGOInfo()->type != GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT) return m_stationaryPosition.GetPositionY(); return GetPositionY(); }
        float GetStationaryZ() const override { if (GetGOInfo()->type != GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT) return m_stationaryPosition.GetPositionZ(); return GetPositionZ(); }
        float GetStationaryO() const override { if (GetGOInfo()->type != GAMEOBJECT_TYPE_MAP_OBJ_TRANSPORT) return m_stationaryPosition.GetOrientation(); return GetOrientation(); }

        float GetInteractionDistance() const;

        void UpdateModelPosition();

    protected:
        bool AIM_Initialize();
        void UpdateModel();                                 // updates model in case displayId were changed
        uint32      m_spellId;
        time_t      m_respawnTime;                          // (secs) time of next respawn (or despawn if GO have owner()),
        uint32      m_respawnDelayTime;                     // (secs) if 0 then current GO state no dependent from timer
        LootState   m_lootState;
        ObjectGuid  m_lootStateUnitGUID;                    // GUID of the unit passed with SetLootState(LootState, Unit*)
        bool        m_spawnedByDefault;
        time_t      m_cooldownTime;                         // used as internal reaction delay time store (not state change reaction).
                                                            // For traps this: spell casting cooldown, for doors/buttons: reset time.
        GuidSet m_SkillupList;

        ObjectGuid m_ritualOwnerGUID;                       // used for GAMEOBJECT_TYPE_RITUAL where GO is not summoned (no owner)
        GuidSet m_unique_users;
        uint32 m_usetimes;

        typedef std::map<uint32, ObjectGuid> ChairSlotAndUser;
        ChairSlotAndUser ChairListSlots;

        ObjectGuid::LowType m_DBTableGuid;                               ///< For new or temporary gameobjects is 0 for saved it is lowguid
        GameObjectTemplate const* m_goInfo;
        GameObjectData const* m_goData;
        GameObjectValue m_goValue;

        uint64 m_rotation;
        Position m_stationaryPosition;

        ObjectGuid m_lootRecipient;
        ObjectGuid m_lootRecipientGroup;
        uint16 m_LootMode;                                  // bitmask, default LOOT_MODE_DEFAULT, determines what loot will be lootable
    private:
        void RemoveFromOwner();
        void SwitchDoorOrButton(bool activate, bool alternative = false);

        //! Object distance/size - overridden from Object::_IsWithinDist. Needs to take in account proper GO size.
        bool _IsWithinDist(WorldObject const* obj, float dist2compare, bool /*is3D*/) const override
        {
            //! Following check does check 3d distance
            return IsInRange(obj->GetPositionX(), obj->GetPositionY(), obj->GetPositionZ(), dist2compare);
        }

        GameObjectAI* m_AI;
};
#endif
