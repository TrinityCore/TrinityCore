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

#ifndef GameObjectData_h__
#define GameObjectData_h__

#include "Common.h"
#include "DBCEnums.h"
#include "QuaternionData.h"
#include "SharedDefines.h"
#include "SpawnData.h"
#include "WorldPacket.h"
#include <string>

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
    float   size;
    int32   ContentTuningId;
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
            uint32 DoorisOpaque;                            // 8 Door is Opaque (Disable portal on close), enum { false, true, }; Default: true
            uint32 GiganticAOI;                             // 9 Gigantic AOI, enum { false, true, }; Default: false
            uint32 InfiniteAOI;                             // 10 Infinite AOI, enum { false, true, }; Default: false
            uint32 NotLOSBlocking;                          // 11 Not LOS Blocking, enum { false, true, }; Default: false
            uint32 InteractRadiusOverride;                  // 12 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 10 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 12 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 9 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 requireLOS;                              // 10 require LOS, enum { false, true, }; Default: false
            uint32 leaveLoot;                               // 11 leaveLoot, enum { false, true, }; Default: false
            uint32 notInCombat;                             // 12 notInCombat, enum { false, true, }; Default: false
            uint32 logloot;                                 // 13 log loot, enum { false, true, }; Default: false
            uint32 openTextID;                              // 14 openTextID, References: BroadcastText, NoValue = 0
            uint32 usegrouplootrules;                       // 15 use group loot rules, enum { false, true, }; Default: false
            uint32 floatingTooltip;                         // 16 floatingTooltip, enum { false, true, }; Default: false
            uint32 conditionID1;                            // 17 conditionID1, References: PlayerCondition, NoValue = 0
            int32 Unused;                                   // 18 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 xpDifficulty;                            // 19 xpDifficulty, enum { No Exp, Trivial, Very Small, Small, Substandard, Standard, High, Epic, Dungeon, 5, }; Default: No Exp
            uint32 Unused2;                                 // 20 Unused, int, Min value: 0, Max value: 123, Default value: 0
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
            uint32 chestPushLoot;                           // 33 chest Push Loot, References: Treasure, NoValue = 0
        } chest;
        // 4 GAMEOBJECT_TYPE_BINDER
        struct
        {
            uint32 InteractRadiusOverride;                  // 0 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 9 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } generic;
        // 6 GAMEOBJECT_TYPE_TRAP
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 Unused;                                  // 1 Unused, int, Min value: 0, Max value: 65535, Default value: 0
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
            uint32 requireLOS;                              // 18 require LOS, enum { false, true, }; Default: false
            uint32 TriggerCondition;                        // 19 Trigger Condition, References: PlayerCondition, NoValue = 0
            uint32 Checkallunits;                           // 20 Check all units (spawned traps only check players), enum { false, true, }; Default: false
            uint32 InteractRadiusOverride;                  // 21 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } trap;
        // 7 GAMEOBJECT_TYPE_CHAIR
        struct
        {
            uint32 chairslots;                              // 0 chairslots, int, Min value: 1, Max value: 5, Default value: 1
            uint32 chairheight;                             // 1 chairheight, int, Min value: 0, Max value: 2, Default value: 1
            uint32 onlyCreatorUse;                          // 2 onlyCreatorUse, enum { false, true, }; Default: false
            uint32 triggeredEvent;                          // 3 triggeredEvent, References: GameEvents, NoValue = 0
            uint32 conditionID1;                            // 4 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 InteractRadiusOverride;                  // 5 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 9 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 6 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 AllowMultiInteract;                      // 20 Allow Multi-Interact, enum { false, true, }; Default: false
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
            uint32 NoFuzzyHit;                              // 31 No Fuzzy Hit, enum { false, true, }; Default: false
            uint32 LargeAOI;                                // 32 Large AOI, enum { false, true, }; Default: false
            uint32 InteractRadiusOverride;                  // 33 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } goober;
        // 11 GAMEOBJECT_TYPE_TRANSPORT
        struct
        {
            uint32 Timeto2ndfloor;                          // 0 Time to 2nd floor (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 startOpen;                               // 1 startOpen, enum { false, true, }; Default: false
            uint32 autoClose;                               // 2 autoClose (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 Reached1stfloor;                         // 3 Reached 1st floor, References: GameEvents, NoValue = 0
            uint32 Reached2ndfloor;                         // 4 Reached 2nd floor, References: GameEvents, NoValue = 0
            int32 SpawnMap;                                 // 5 Spawn Map, References: Map, NoValue = -1
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
            uint32 InteractRadiusOverride;                  // 24 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 8 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } areaDamage;
        // 13 GAMEOBJECT_TYPE_CAMERA
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 camera;                                  // 1 camera, References: CinematicSequences, NoValue = 0
            uint32 eventID;                                 // 2 eventID, References: GameEvents, NoValue = 0
            uint32 openTextID;                              // 3 openTextID, References: BroadcastText, NoValue = 0
            uint32 conditionID1;                            // 4 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 InteractRadiusOverride;                  // 5 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            int32 SpawnMap;                                 // 6 Spawn Map, References: Map, NoValue = -1
            uint32 worldState1;                             // 7 worldState1, References: WorldState, NoValue = 0
            uint32 allowstopping;                           // 8 allow stopping, enum { false, true, }; Default: false
            uint32 InitStopped;                             // 9 Init Stopped, enum { false, true, }; Default: false
            uint32 TrueInfiniteAOI;                         // 10 True Infinite AOI (programmer only!), enum { false, true, }; Default: false
            uint32 InteractRadiusOverride;                  // 11 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 Allowareaexplorationwhileonthistransport;// 12 Allow area exploration while on this transport, enum { false, true, }; Default: false
        } moTransport;
        // 16 GAMEOBJECT_TYPE_DUEL_ARBITER
        struct
        {
            uint32 InteractRadiusOverride;                  // 0 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } duelFlag;
        // 17 GAMEOBJECT_TYPE_FISHINGNODE
        struct
        {
            uint32 InteractRadiusOverride;                  // 0 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 9 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } ritual;
        // 19 GAMEOBJECT_TYPE_MAILBOX
        struct
        {
            uint32 conditionID1;                            // 0 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 InteractRadiusOverride;                  // 1 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 Preferonlyifinlineofsight;               // 2 Prefer only if in line of sight (expensive), enum { false, true, }; Default: false
            uint32 InteractRadiusOverride;                  // 3 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 8 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } spellCaster;
        // 23 GAMEOBJECT_TYPE_MEETINGSTONE
        struct
        {
            uint32 Unused;                                  // 0 Unused, int, Min value: 0, Max value: 65535, Default value: 1
            uint32 Unused2;                                 // 1 Unused, int, Min value: 1, Max value: 65535, Default value: 60
            uint32 areaID;                                  // 2 areaID, References: AreaTable, NoValue = 0
            uint32 InteractRadiusOverride;                  // 3 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 13 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } flagStand;
        // 25 GAMEOBJECT_TYPE_FISHINGHOLE
        struct
        {
            uint32 radius;                                  // 0 radius, int, Min value: 0, Max value: 50, Default value: 0
            uint32 chestLoot;                               // 1 chestLoot, References: Treasure, NoValue = 0
            uint32 minRestock;                              // 2 minRestock, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 maxRestock;                              // 3 maxRestock, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 open;                                    // 4 open, References: Lock_, NoValue = 0
            uint32 InteractRadiusOverride;                  // 5 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 10 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } flagDrop;
        // 27 GAMEOBJECT_TYPE_MINI_GAME
        struct
        {
        } miniGame;
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
            uint32 EnablingWorldStateExpression;            // 27 Enabling World State Expression, References: WorldStateExpression, NoValue = 0
            uint32 InteractRadiusOverride;                  // 28 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 7 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 InteractRadiusOverride;                  // 11 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } dungeonDifficulty;
        // 32 GAMEOBJECT_TYPE_BARBER_CHAIR
        struct
        {
            uint32 chairheight;                             // 0 chairheight, int, Min value: 0, Max value: 2, Default value: 1
            int32 HeightOffset;                             // 1 Height Offset (inches), int, Min value: -100, Max value: 100, Default value: 0
            uint32 SitAnimKit;                              // 2 Sit Anim Kit, References: AnimKit, NoValue = 0
            uint32 InteractRadiusOverride;                  // 3 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 Displaymouseoverasanameplate;            // 23 Display mouseover as a nameplate, enum { false, true, }; Default: false
            int32 Thexoffsetofthedestructiblenameplateifitisenabled;// 24 The x offset (in hundredths) of the destructible nameplate, if it is enabled, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            int32 Theyoffsetofthedestructiblenameplateifitisenabled;// 25 The y offset (in hundredths) of the destructible nameplate, if it is enabled, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            int32 Thezoffsetofthedestructiblenameplateifitisenabled;// 26 The z offset (in hundredths) of the destructible nameplate, if it is enabled, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 InteractRadiusOverride;                  // 27 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } destructibleBuilding;
        // 34 GAMEOBJECT_TYPE_GUILD_BANK
        struct
        {
            uint32 conditionID1;                            // 0 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 InteractRadiusOverride;                  // 1 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } guildbank;
        // 35 GAMEOBJECT_TYPE_TRAPDOOR
        struct
        {
            uint32 AutoLink;                                // 0 Auto Link, enum { false, true, }; Default: false
            uint32 startOpen;                               // 1 startOpen, enum { false, true, }; Default: false
            uint32 autoClose;                               // 2 autoClose (ms), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 BlocksPathsDown;                         // 3 Blocks Paths Down, enum { false, true, }; Default: false
            int32 PathBlockerBump;                          // 4 Path Blocker Bump (ft), int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 GiganticAOI;                             // 5 Gigantic AOI, enum { false, true, }; Default: false
            uint32 InfiniteAOI;                             // 6 Infinite AOI, enum { false, true, }; Default: false
            uint32 DoorisOpaque;                            // 7 Door is Opaque (Disable portal on close), enum { false, true, }; Default: false
            uint32 InteractRadiusOverride;                  // 8 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 SpawnVignette;                           // 13 Spawn Vignette, References: vignette, NoValue = 0
            uint32 InteractRadiusOverride;                  // 14 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } newflag;
        // 37 GAMEOBJECT_TYPE_NEW_FLAG_DROP
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 SpawnVignette;                           // 1 Spawn Vignette, References: vignette, NoValue = 0
            uint32 InteractRadiusOverride;                  // 2 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } newflagdrop;
        // 38 GAMEOBJECT_TYPE_GARRISON_BUILDING
        struct
        {
            int32 SpawnMap;                                 // 0 Spawn Map, References: Map, NoValue = -1
            uint32 InteractRadiusOverride;                  // 1 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } garrisonBuilding;
        // 39 GAMEOBJECT_TYPE_GARRISON_PLOT
        struct
        {
            uint32 PlotInstance;                            // 0 Plot Instance, References: GarrPlotInstance, NoValue = 0
            int32 SpawnMap;                                 // 1 Spawn Map, References: Map, NoValue = -1
            uint32 InteractRadiusOverride;                  // 2 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
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
            uint32 SpawnVignette;                           // 22 Spawn Vignette, References: vignette, NoValue = 0
            uint32 InteractRadiusOverride;                  // 23 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } capturePoint;
        // 43 GAMEOBJECT_TYPE_PHASEABLE_MO
        struct
        {
            int32 SpawnMap;                                 // 0 Spawn Map, References: Map, NoValue = -1
            int32 AreaNameSet;                              // 1 Area Name Set (Index), int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 DoodadSetA;                              // 2 Doodad Set A, int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 DoodadSetB;                              // 3 Doodad Set B, int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 InteractRadiusOverride;                  // 4 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } phaseableMO;
        // 44 GAMEOBJECT_TYPE_GARRISON_MONUMENT
        struct
        {
            uint32 TrophyTypeID;                            // 0 Trophy Type ID, References: TrophyType, NoValue = 0
            uint32 TrophyInstanceID;                        // 1 Trophy Instance ID, References: TrophyInstance, NoValue = 0
            uint32 InteractRadiusOverride;                  // 2 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } garrisonMonument;
        // 45 GAMEOBJECT_TYPE_GARRISON_SHIPMENT
        struct
        {
            uint32 ShipmentContainer;                       // 0 Shipment Container, References: CharShipmentContainer, NoValue = 0
            uint32 GiganticAOI;                             // 1 Gigantic AOI, enum { false, true, }; Default: false
            uint32 LargeAOI;                                // 2 Large AOI, enum { false, true, }; Default: false
            uint32 InteractRadiusOverride;                  // 3 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } garrisonShipment;
        // 46 GAMEOBJECT_TYPE_GARRISON_MONUMENT_PLAQUE
        struct
        {
            uint32 TrophyInstanceID;                        // 0 Trophy Instance ID, References: TrophyInstance, NoValue = 0
            uint32 InteractRadiusOverride;                  // 1 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } garrisonMonumentPlaque;
        // 47 GAMEOBJECT_TYPE_ITEM_FORGE
        struct
        {
            uint32 conditionID1;                            // 0 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 LargeAOI;                                // 1 Large AOI, enum { false, true, }; Default: false
            uint32 IgnoreBoundingBox;                       // 2 Ignore Bounding Box, enum { false, true, }; Default: false
            uint32 CameraMode;                              // 3 Camera Mode, References: CameraMode, NoValue = 0
            uint32 FadeRegionRadius;                        // 4 Fade Region Radius, int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 ForgeType;                               // 5 Forge Type, enum { Artifact Forge, Relic Forge, Heart Forge, Soulbind Forge, Anima Reservoir, }; Default: Relic Forge
            uint32 InteractRadiusOverride;                  // 6 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 GarrTalentTreeID;                        // 7 GarrTalentTree ID, References: GarrTalentTree, NoValue = 0
        } itemForge;
        // 48 GAMEOBJECT_TYPE_UI_LINK
        struct
        {
            uint32 UILinkType;                              // 0 UI Link Type, enum { Adventure Journal, Obliterum Forge, Scrapping Machine, }; Default: Adventure Journal
            uint32 allowMounted;                            // 1 allowMounted, enum { false, true, }; Default: false
            uint32 GiganticAOI;                             // 2 Gigantic AOI, enum { false, true, }; Default: false
            uint32 spellFocusType;                          // 3 spellFocusType, References: SpellFocusObject, NoValue = 0
            uint32 radius;                                  // 4 radius, int, Min value: 0, Max value: 50, Default value: 10
            uint32 InteractRadiusOverride;                  // 5 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } UILink;
        // 49 GAMEOBJECT_TYPE_KEYSTONE_RECEPTACLE
        struct
        {
            uint32 InteractRadiusOverride;                  // 0 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } KeystoneReceptacle;
        // 50 GAMEOBJECT_TYPE_GATHERING_NODE
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 chestLoot;                               // 1 chestLoot, References: Treasure, NoValue = 0
            uint32 Unused;                                  // 2 Unused, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 notInCombat;                             // 3 notInCombat, enum { false, true, }; Default: false
            uint32 trivialSkillLow;                         // 4 trivialSkillLow, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 trivialSkillHigh;                        // 5 trivialSkillHigh, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 ObjectDespawnDelay;                      // 6 Object Despawn Delay, int, Min value: 0, Max value: 600, Default value: 15
            uint32 triggeredEvent;                          // 7 triggeredEvent, References: GameEvents, NoValue = 0
            uint32 requireLOS;                              // 8 require LOS, enum { false, true, }; Default: false
            uint32 openTextID;                              // 9 openTextID, References: BroadcastText, NoValue = 0
            uint32 floatingTooltip;                         // 10 floatingTooltip, enum { false, true, }; Default: false
            uint32 conditionID1;                            // 11 conditionID1, References: PlayerCondition, NoValue = 0
            int32 Unused2;                                  // 12 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 xpDifficulty;                            // 13 xpDifficulty, enum { No Exp, Trivial, Very Small, Small, Substandard, Standard, High, Epic, Dungeon, 5, }; Default: No Exp
            uint32 spell;                                   // 14 spell, References: Spell, NoValue = 0
            uint32 GiganticAOI;                             // 15 Gigantic AOI, enum { false, true, }; Default: false
            uint32 LargeAOI;                                // 16 Large AOI, enum { false, true, }; Default: false
            uint32 SpawnVignette;                           // 17 Spawn Vignette, References: vignette, NoValue = 0
            uint32 MaxNumberofLoots;                        // 18 Max Number of Loots, int, Min value: 1, Max value: 40, Default value: 10
            uint32 logloot;                                 // 19 log loot, enum { false, true, }; Default: false
            uint32 linkedTrap;                              // 20 linkedTrap, References: GameObjects, NoValue = 0
            uint32 PlayOpenAnimationonOpening;              // 21 Play Open Animation on Opening, enum { false, true, }; Default: false
            uint32 turnpersonallootsecurityoff;             // 22 turn personal loot security off, enum { false, true, }; Default: false
            uint32 ClearObjectVignetteonOpening;            // 23 Clear Object Vignette on Opening, enum { false, true, }; Default: false
            uint32 InteractRadiusOverride;                  // 24 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } gatheringNode;
        // 51 GAMEOBJECT_TYPE_CHALLENGE_MODE_REWARD
        struct
        {
            int32 Unused;                                   // 0 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 WhenAvailable;                           // 1 When Available, References: GameObjectDisplayInfo, NoValue = 0
            uint32 open;                                    // 2 open, References: Lock_, NoValue = 0
            uint32 openTextID;                              // 3 openTextID, References: BroadcastText, NoValue = 0
            uint32 InteractRadiusOverride;                  // 4 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } challengeModeReward;
        // 52 GAMEOBJECT_TYPE_MULTI
        struct
        {
            uint32 MultiProperties;                         // 0 Multi Properties, References: MultiProperties, NoValue = 0
        } multi;
        // 53 GAMEOBJECT_TYPE_SIEGEABLE_MULTI
        struct
        {
            uint32 MultiProperties;                         // 0 Multi Properties, References: MultiProperties, NoValue = 0
            uint32 InitialDamage;                           // 1 Initial Damage, enum { None, Raw, Ratio, }; Default: None
        } siegeableMulti;
        // 54 GAMEOBJECT_TYPE_SIEGEABLE_MO
        struct
        {
            uint32 SiegeableProperties;                     // 0 Siegeable Properties, References: SiegeableProperties, NoValue = 0
            uint32 DoodadSetA;                              // 1 Doodad Set A, int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 DoodadSetB;                              // 2 Doodad Set B, int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 DoodadSetC;                              // 3 Doodad Set C, int, Min value: 0, Max value: 2147483647, Default value: 0
            int32 SpawnMap;                                 // 4 Spawn Map, References: Map, NoValue = -1
            int32 AreaNameSet;                              // 5 Area Name Set (Index), int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 InteractRadiusOverride;                  // 6 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } siegeableMO;
        // 55 GAMEOBJECT_TYPE_PVP_REWARD
        struct
        {
            int32 Unused;                                   // 0 Unused, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 WhenAvailable;                           // 1 When Available, References: GameObjectDisplayInfo, NoValue = 0
            uint32 open;                                    // 2 open, References: Lock_, NoValue = 0
            uint32 openTextID;                              // 3 openTextID, References: BroadcastText, NoValue = 0
            uint32 InteractRadiusOverride;                  // 4 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } pvpReward;
        // 56 GAMEOBJECT_TYPE_PLAYER_CHOICE_CHEST
        struct
        {
            uint32 spell;                                   // 0 spell, References: Spell, NoValue = 0
            uint32 WhenAvailable;                           // 1 When Available, References: GameObjectDisplayInfo, NoValue = 0
            uint32 GiganticAOI;                             // 2 Gigantic AOI, enum { false, true, }; Default: false
            uint32 PlayerChoice;                            // 3 Player Choice, References: PlayerChoice, NoValue = 0
            uint32 MawPowerFilter;                          // 4 Maw Power Filter, References: MawPowerFilter, NoValue = 0
            uint32 Script;                                  // 5 Script, References: SpellScript, NoValue = 0
            uint32 SpellVisual1;                            // 6 Spell Visual 1, References: SpellVisual, NoValue = 0
            uint32 InteractRadiusOverride;                  // 7 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
            uint32 Dontupdateplayerinteractability;         // 8 Don't update player interactability, enum { false, true, }; Default: false
        } playerChoiceChest;
        // 57 GAMEOBJECT_TYPE_LEGENDARY_FORGE
        struct
        {
            uint32 PlayerChoice;                            // 0 Player Choice, References: PlayerChoice, NoValue = 0
            uint32 CustomItemBonusFilter;                   // 1 Custom Item Bonus Filter, References: CustomItemBonusFilter, NoValue = 0
            uint32 InteractRadiusOverride;                  // 2 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } legendaryForge;
        // 58 GAMEOBJECT_TYPE_GARR_TALENT_TREE
        struct
        {
            uint32 UiMapID;                                 // 0 Ui Map ID, References: UiMap, NoValue = 0
            uint32 GarrTalentTreeID;                        // 1 GarrTalentTree ID, References: GarrTalentTree, NoValue = 0
            uint32 InteractRadiusOverride;                  // 2 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } garrTalentTree;
        // 59 GAMEOBJECT_TYPE_WEEKLY_REWARD_CHEST
        struct
        {
            uint32 WhenAvailable;                           // 0 When Available, References: GameObjectDisplayInfo, NoValue = 0
            uint32 open;                                    // 1 open, References: Lock_, NoValue = 0
            uint32 InteractRadiusOverride;                  // 2 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } weeklyRewardChest;
        // 60 GAMEOBJECT_TYPE_CLIENT_MODEL
        struct
        {
            uint32 LargeAOI;                                // 0 Large AOI, enum { false, true, }; Default: false
            uint32 GiganticAOI;                             // 1 Gigantic AOI, enum { false, true, }; Default: false
            uint32 InfiniteAOI;                             // 2 Infinite AOI, enum { false, true, }; Default: false
            uint32 TrueInfiniteAOI;                         // 3 True Infinite AOI (programmer only!), enum { false, true, }; Default: false
        } clientModel;
        struct
        {
            uint32 data[MAX_GAMEOBJECT_DATA];
        } raw;
    };

    std::string AIName;
    uint32 ScriptId;
    WorldPacket QueryData[TOTAL_LOCALES];

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
            case GAMEOBJECT_TYPE_MAILBOX:       return true;
            case GAMEOBJECT_TYPE_BARBER_CHAIR:  return false;
            case GAMEOBJECT_TYPE_QUESTGIVER:    return questgiver.allowMounted != 0;
            case GAMEOBJECT_TYPE_TEXT:          return text.allowMounted != 0;
            case GAMEOBJECT_TYPE_GOOBER:        return goober.allowMounted != 0;
            case GAMEOBJECT_TYPE_SPELLCASTER:   return spellCaster.allowMounted != 0;
            case GAMEOBJECT_TYPE_UI_LINK:       return UILink.allowMounted != 0;
            default: return false;
        }
    }

    uint32 GetLockId() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_DOOR:                  return door.open;
            case GAMEOBJECT_TYPE_BUTTON:                return button.open;
            case GAMEOBJECT_TYPE_QUESTGIVER:            return questgiver.open;
            case GAMEOBJECT_TYPE_CHEST:                 return chest.open;
            case GAMEOBJECT_TYPE_TRAP:                  return trap.open;
            case GAMEOBJECT_TYPE_GOOBER:                return goober.open;
            case GAMEOBJECT_TYPE_AREADAMAGE:            return areaDamage.open;
            case GAMEOBJECT_TYPE_CAMERA:                return camera.open;
            case GAMEOBJECT_TYPE_FLAGSTAND:             return flagStand.open;
            case GAMEOBJECT_TYPE_FISHINGHOLE:           return fishingHole.open;
            case GAMEOBJECT_TYPE_FLAGDROP:              return flagDrop.open;
            case GAMEOBJECT_TYPE_NEW_FLAG:              return newflag.open;
            case GAMEOBJECT_TYPE_NEW_FLAG_DROP:         return newflagdrop.open;
            case GAMEOBJECT_TYPE_CAPTURE_POINT:         return capturePoint.open;
            case GAMEOBJECT_TYPE_GATHERING_NODE:        return gatheringNode.open;
            case GAMEOBJECT_TYPE_CHALLENGE_MODE_REWARD: return challengeModeReward.open;
            case GAMEOBJECT_TYPE_PVP_REWARD:            return pvpReward.open;
            case GAMEOBJECT_TYPE_WEEKLY_REWARD_CHEST:   return weeklyRewardChest.open;
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
            case GAMEOBJECT_TYPE_BUTTON:            return button.linkedTrap;
            case GAMEOBJECT_TYPE_CHEST:             return chest.linkedTrap;
            case GAMEOBJECT_TYPE_SPELL_FOCUS:       return spellFocus.linkedTrap;
            case GAMEOBJECT_TYPE_GOOBER:            return goober.linkedTrap;
            case GAMEOBJECT_TYPE_GATHERING_NODE:    return gatheringNode.linkedTrap;
            default: return 0;
        }
    }

    uint32 GetAutoCloseTime() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_DOOR:          return door.autoClose;
            case GAMEOBJECT_TYPE_BUTTON:        return button.autoClose;
            case GAMEOBJECT_TYPE_TRAP:          return trap.autoClose;
            case GAMEOBJECT_TYPE_GOOBER:        return goober.autoClose;
            case GAMEOBJECT_TYPE_TRANSPORT:     return transport.autoClose;
            case GAMEOBJECT_TYPE_AREADAMAGE:    return areaDamage.autoClose;
            case GAMEOBJECT_TYPE_TRAPDOOR:      return trapdoor.autoClose;
            default: return 0;
        }
    }

    uint32 GetLootId() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_CHEST:                 return chest.chestLoot;
            case GAMEOBJECT_TYPE_FISHINGHOLE:           return fishingHole.chestLoot;
            case GAMEOBJECT_TYPE_GATHERING_NODE:        return gatheringNode.chestLoot;
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
            case GAMEOBJECT_TYPE_GOOBER:            return goober.eventID;
            case GAMEOBJECT_TYPE_CHEST:             return chest.triggeredEvent;
            case GAMEOBJECT_TYPE_CAMERA:            return camera.eventID;
            case GAMEOBJECT_TYPE_GATHERING_NODE:    return gatheringNode.triggeredEvent;
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

    bool IsInfiniteGameObject() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_DOOR:          return door.InfiniteAOI != 0;
            case GAMEOBJECT_TYPE_FLAGSTAND:     return flagStand.InfiniteAOI != 0;
            case GAMEOBJECT_TYPE_FLAGDROP:      return flagDrop.InfiniteAOI != 0;
            case GAMEOBJECT_TYPE_TRAPDOOR:      return trapdoor.InfiniteAOI != 0;
            case GAMEOBJECT_TYPE_NEW_FLAG:      return newflag.InfiniteAOI != 0;
            case GAMEOBJECT_TYPE_CLIENT_MODEL:  return newflag.InfiniteAOI != 0;
            default: return false;
        }
    }

    bool IsGiganticGameObject() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_DOOR:                  return door.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_BUTTON:                return button.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_QUESTGIVER:            return questgiver.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_CHEST:                 return chest.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_GENERIC:               return generic.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_TRAP:                  return trap.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_SPELL_FOCUS:           return spellFocus.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_GOOBER:                return goober.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_SPELLCASTER:           return spellCaster.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_FLAGSTAND:             return flagStand.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_FLAGDROP:              return flagDrop.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_CONTROL_ZONE:          return controlZone.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_DUNGEON_DIFFICULTY:    return dungeonDifficulty.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_TRAPDOOR:              return trapdoor.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_NEW_FLAG:              return newflag.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_CAPTURE_POINT:         return capturePoint.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_GARRISON_SHIPMENT:     return garrisonShipment.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_UI_LINK:               return UILink.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_GATHERING_NODE:        return gatheringNode.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_PLAYER_CHOICE_CHEST:   return gatheringNode.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_CLIENT_MODEL:          return gatheringNode.GiganticAOI != 0;
            default: return false;
        }
    }

    bool IsLargeGameObject() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_CHEST:                 return chest.LargeAOI != 0;
            case GAMEOBJECT_TYPE_GENERIC:               return generic.LargeAOI != 0;
            case GAMEOBJECT_TYPE_GOOBER:                return goober.LargeAOI != 0;
            case GAMEOBJECT_TYPE_DUNGEON_DIFFICULTY:    return dungeonDifficulty.LargeAOI != 0;
            case GAMEOBJECT_TYPE_GARRISON_SHIPMENT:     return garrisonShipment.LargeAOI != 0;
            case GAMEOBJECT_TYPE_ITEM_FORGE:            return itemForge.LargeAOI != 0;
            case GAMEOBJECT_TYPE_GATHERING_NODE:        return gatheringNode.LargeAOI != 0;
            case GAMEOBJECT_TYPE_CLIENT_MODEL:          return clientModel.LargeAOI != 0;
            default: return false;
        }
    }

    uint32 GetSpellFocusType() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_SPELL_FOCUS:   return spellFocus.spellFocusType;
            case GAMEOBJECT_TYPE_UI_LINK:       return UILink.spellFocusType;
            default: return 0;
        }
    }

    uint32 GetSpellFocusRadius() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_SPELL_FOCUS:   return spellFocus.radius;
            case GAMEOBJECT_TYPE_UI_LINK:       return UILink.radius;
            default: return 0;
        }
    }

    void InitializeQueryData();
    WorldPacket BuildQueryData(LocaleConstant loc) const;
};

// From `gameobject_template_addon`, `gameobject_overrides`
struct GameObjectOverride
{
    uint32 Faction;
    uint32 Flags;
};

// From `gameobject_template_addon`
struct GameObjectTemplateAddon : public GameObjectOverride
{
    uint32 Mingold;
    uint32 Maxgold;
    uint32 WorldEffectID;
    uint32 AIAnimKitID;
};

struct GameObjectLocale
{
    std::vector<std::string> Name;
    std::vector<std::string> CastBarCaption;
    std::vector<std::string> Unk1;
};

// `gameobject_addon` table
struct GameObjectAddon
{
    QuaternionData ParentRotation;
    InvisibilityType invisibilityType;
    uint32 InvisibilityValue;
    uint32 WorldEffectID;
    uint32 AIAnimKitID;
};

// `gameobject` table
struct GameObjectData : public SpawnData
{
    GameObjectData() : SpawnData(SPAWN_TYPE_GAMEOBJECT) { }
    QuaternionData rotation;
    uint32 animprogress = 0;
    GOState goState = GO_STATE_ACTIVE;
    uint8 artKit = 0;
};

#endif // GameObjectData_h__
