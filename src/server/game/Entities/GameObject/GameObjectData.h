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
#include "SharedDefines.h"
#include "SpawnData.h"
#include "WorldPacket.h"

#include <array>
#include <string>
#include <vector>

#define MAX_GAMEOBJECT_QUEST_ITEMS 6

class WorldPacket;

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
    int32   RequiredLevel;
    union                                                   // different GO types have different data field
    {
        //0 GAMEOBJECT_TYPE_DOOR
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
        } door;
        //1 GAMEOBJECT_TYPE_BUTTON
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
        //2 GAMEOBJECT_TYPE_QUESTGIVER
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
        } questgiver;
        //3 GAMEOBJECT_TYPE_CHEST
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 chestLoot;                               // 1 chestLoot (legacy/classic), References: Treasure, NoValue = 0
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
            int32 xpMinLevel;                               // 18 xpMinLevel, int, Min value: -2147483648, Max value: 2147483647, Default value: 0
            uint32 xpDifficulty;                            // 19 xpDifficulty, enum { No Exp, Trivial, Very Small, Small, Substandard, Standard, High, Epic, Dungeon, 5, }; Default: No Exp
            uint32 Unk;                                     // 20 unk, int, Min value: 0, Max value: 123, Default value: 0 // related to needed level for loot?
            uint32 GroupXP;                                 // 21 Group XP, enum { false, true, }; Default: false
            uint32 DamageImmuneOK;                          // 22 Damage Immune OK, enum { false, true, }; Default: false
            uint32 trivialSkillLow;                         // 23 trivialSkillLow, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 trivialSkillHigh;                        // 24 trivialSkillHigh, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 DungeonEncounter;                        // 25 Dungeon Encounter, References: DungeonEncounter, NoValue = 0
        } chest;
        //4 GAMEOBJECT_TYPE_BINDER - empty
        //5 GAMEOBJECT_TYPE_GENERIC
        struct
        {
            uint32 floatingTooltip;                         // 0 floatingTooltip, enum { false, true, }; Default: false
            uint32 highlight;                               // 1 highlight, enum { false, true, }; Default: true
            uint32 serverOnly;                              // 2 serverOnly, enum { false, true, }; Default: false
            uint32 GiganticAOI;                             // 3 Gigantic AOI, enum { false, true, }; Default: false
            uint32 floatOnWater;                            // 4 floatOnWater, enum { false, true, }; Default: false
            int32 questID;                                  // 5 questID, References: QuestV2, NoValue = 0
            uint32 conditionID1;                            // 6 conditionID1, References: PlayerCondition, NoValue = 0
        } _generic;
        //6 GAMEOBJECT_TYPE_TRAP
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
        } trap;
        //7 GAMEOBJECT_TYPE_CHAIR
        struct
        {
            uint32 chairslots;                              // 0 chairslots, int, Min value: 1, Max value: 5, Default value: 1
            uint32 chairheight;                             // 1 chairheight, int, Min value: 0, Max value: 2, Default value: 1
            uint32 onlyCreatorUse;                          // 2 onlyCreatorUse, enum { false, true, }; Default: false
            uint32 triggeredEvent;                          // 3 triggeredEvent, References: GameEvents, NoValue = 0
            uint32 conditionID1;                            // 4 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 InteractRadiusOverride;                  // 5 Interact Radius Override (in hundredths), int, Min value: 0, Max value: 2147483647, Default value: 0
        } chair;
        //8 GAMEOBJECT_TYPE_SPELL_FOCUS
        struct
        {
            uint32 spellFocusType;                          // 0 spellFocusType, References: SpellFocusObject, NoValue = 0
            uint32 radius;                                  // 1 radius, int, Min value: 0, Max value: 50, Default value: 10
            uint32 linkedTrap;                              // 2 linkedTrap, References: GameObjects, NoValue = 0
            uint32 serverOnly;                              // 3 serverOnly, enum { false, true, }; Default: false
            uint32 questID;                                 // 4 questID, References: QuestV2, NoValue = 0
            uint32 GiganticAOI;                             // 5 Gigantic AOI, enum { false, true, }; Default: false
            uint32 floatingTooltip;                         // 6 floatingTooltip, enum { false, true, }; Default: false
        } spellFocus;
        //9 GAMEOBJECT_TYPE_TEXT
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
        //10 GAMEOBJECT_TYPE_GOOBER
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            int32 questID;                                  // 1 questID, References: QuestV2, NoValue = 0
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
        } goober;
        //11 GAMEOBJECT_TYPE_TRANSPORT
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
        } transport;
        //12 GAMEOBJECT_TYPE_AREADAMAGE
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
        } areadamage;
        //13 GAMEOBJECT_TYPE_CAMERA
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
        //15 GAMEOBJECT_TYPE_MO_TRANSPORT
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
        } moTransport;
        // 16 GAMEOBJECT_TYPE_DUEL_ARBITER
        struct
        {
        } duelFlag;
        // 17 GAMEOBJECT_TYPE_FISHINGNODE
        struct
        {
        } fishingNode;
        //18 GAMEOBJECT_TYPE_SUMMONING_RITUAL
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
        } summoningRitual;
        //19 GAMEOBJECT_TYPE_MAILBOX
        struct
        {
            uint32 conditionID1;                            // 0 conditionID1, References: PlayerCondition, NoValue = 0
        } mailbox;
        // 20 GAMEOBJECT_TYPE_DO_NOT_USE
        struct
        {
        } DONOTUSE;
        //21 GAMEOBJECT_TYPE_GUARDPOST
        struct
        {
            uint32 creatureID;                              // 0 creatureID, References: Creature, NoValue = 0
            uint32 charges;                                 // 1 charges, int, Min value: 0, Max value: 65535, Default value: 1
        } guardpost;
        //22 GAMEOBJECT_TYPE_SPELLCASTER
        struct
        {
            uint32 spell;                                   // 0 spell, References: Spell, NoValue = 0
            int32 charges;                                  // 1 charges, int, Min value: -1, Max value: 65535, Default value: 1
            uint32 partyOnly;                               // 2 partyOnly, enum { false, true, }; Default: false
            uint32 allowMounted;                            // 3 allowMounted, enum { false, true, }; Default: false
            uint32 GiganticAOI;                             // 4 Gigantic AOI, enum { false, true, }; Default: false
            uint32 conditionID1;                            // 5 conditionID1, References: PlayerCondition, NoValue = 0
            uint32 playerCast;                              // 6 playerCast, enum { false, true, }; Default: false
        } spellcaster;
        //23 GAMEOBJECT_TYPE_MEETINGSTONE
        struct
        {
            uint32 minLevel;                                // 0 minLevel, int, Min value: 0, Max value: 65535, Default value: 1
            uint32 maxLevel;                                // 1 macLevel, int, Min value: 1, Max value: 65535, Default value: 85
            uint32 areaID;                                  // 2 areaID, References: AreaTable, NoValue = 0
        } meetingstone;
        //24 GAMEOBJECT_TYPE_FLAGSTAND
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
        } flagstand;
        //25 GAMEOBJECT_TYPE_FISHINGHOLE
        struct
        {
            uint32 radius;                                  // 0 radius, int, Min value: 0, Max value: 50, Default value: 0
            uint32 chestLoot;                               // 1 chestLoot (legacy/classic), References: Treasure, NoValue = 0
            uint32 minRestock;                              // 2 minRestock, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 maxRestock;                              // 3 maxRestock, int, Min value: 0, Max value: 65535, Default value: 0
            uint32 open;                                    // 4 open, References: Lock_, NoValue = 0
        } fishinghole;
        //26 GAMEOBJECT_TYPE_FLAGDROP
        struct
        {
            uint32 open;                                    // 0 open, References: Lock_, NoValue = 0
            uint32 eventID;                                 // 1 eventID, References: GameEvents, NoValue = 0
            uint32 pickupSpell;                             // 2 pickupSpell, References: Spell, NoValue = 0
            uint32 noDamageImmune;                          // 3 noDamageImmune, enum { false, true, }; Default: false
            uint32 openTextID;                              // 4 openTextID, References: BroadcastText, NoValue = 0
        } flagdrop;
        //27 GAMEOBJECT_TYPE_MINI_GAME
        struct
        {
            uint32 gameType;                                //0
        } miniGame;
        // 28 GAMEOBJECT_TYPE_DO_NOT_USE_2
        struct
        {
        } DONOTUSE2;
        //29 GAMEOBJECT_TYPE_CAPTURE_POINT
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
        } capturePoint;
        //30 GAMEOBJECT_TYPE_AURA_GENERATOR
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
        //31 GAMEOBJECT_TYPE_DUNGEON_DIFFICULTY
        struct
        {
            uint32 mapID;                                   //0
            uint32 difficulty;                              //1
        } dungeonDifficulty;
        //32 GAMEOBJECT_TYPE_BARBER_CHAIR
        struct
        {
            uint32 chairheight;                             // 0 chairheight, int, Min value: 0, Max value: 2, Default value: 1
            int32 HeightOffset;                             // 1 Height Offset (inches), int, Min value: -100, Max value: 100, Default value: 0
        } barberChair;
        //33 GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING
        struct
        {
            uint32 intactNumHits;                           //0
            uint32 creditProxyCreature;                     //1
            uint32 empty1;                                  //2
            uint32 intactEvent;                             //3
            uint32 empty2;                                  //4
            uint32 damagedNumHits;                          //5
            uint32 empty3;                                  //6
            uint32 empty4;                                  //7
            uint32 empty5;                                  //8
            uint32 damagedEvent;                            //9
            uint32 empty6;                                  //10
            uint32 empty7;                                  //11
            uint32 empty8;                                  //12
            uint32 empty9;                                  //13
            uint32 destroyedEvent;                          //14
            uint32 empty10;                                 //15
            uint32 rebuildingTimeSecs;                      //16
            uint32 empty11;                                 //17
            uint32 destructibleData;                        //18
            uint32 rebuildingEvent;                         //19
            uint32 empty12;                                 //20
            uint32 empty13;                                 //21
            uint32 damageEvent;                             //22
            uint32 empty14;                                 //23
        } building;
        //34 GAMEOBJECT_TYPE_GUILDBANK
        struct
        {
            uint32 conditionID1;                            //0
        } guildbank;
        //35 GAMEOBJECT_TYPE_TRAPDOOR
        struct
        {
            uint32 whenToPause;                             // 0
            uint32 startOpen;                               // 1
            uint32 autoClose;                               // 2
        } trapDoor;

        // not use for specific field access (only for output with loop by all filed), also this determinate max union size
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
            case GAMEOBJECT_TYPE_MAILBOX: return true;
            case GAMEOBJECT_TYPE_BARBER_CHAIR: return false;
            case GAMEOBJECT_TYPE_QUESTGIVER: return questgiver.allowMounted != 0;
            case GAMEOBJECT_TYPE_TEXT: return text.allowMounted != 0;
            case GAMEOBJECT_TYPE_GOOBER: return goober.allowMounted != 0;
            case GAMEOBJECT_TYPE_SPELLCASTER: return spellcaster.allowMounted != 0;
            default: return false;
        }
    }

    bool IsIgnoringLOSChecks() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_BUTTON: return button.requireLOS == 0;
            case GAMEOBJECT_TYPE_QUESTGIVER: return questgiver.requireLOS == 0;
            case GAMEOBJECT_TYPE_CHEST: return chest.requireLOS == 0;
            case GAMEOBJECT_TYPE_GOOBER: return goober.requireLOS == 0;
            case GAMEOBJECT_TYPE_FLAGSTAND: return flagstand.requireLOS == 0;
            case GAMEOBJECT_TYPE_TRAP: return true;
            default: return false;
        }
    }

    uint32 GetLockId() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_DOOR:       return door.open;
            case GAMEOBJECT_TYPE_BUTTON:     return button.open;
            case GAMEOBJECT_TYPE_QUESTGIVER: return questgiver.open;
            case GAMEOBJECT_TYPE_CHEST:      return chest.open;
            case GAMEOBJECT_TYPE_TRAP:       return trap.open;
            case GAMEOBJECT_TYPE_GOOBER:     return goober.open;
            case GAMEOBJECT_TYPE_AREADAMAGE: return areadamage.open;
            case GAMEOBJECT_TYPE_CAMERA:     return camera.open;
            case GAMEOBJECT_TYPE_FLAGSTAND:  return flagstand.open;
            case GAMEOBJECT_TYPE_FISHINGHOLE:return fishinghole.open;
            case GAMEOBJECT_TYPE_FLAGDROP:   return flagdrop.open;
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
            case GAMEOBJECT_TYPE_FLAGSTAND:  return flagstand.noDamageImmune != 0;
            case GAMEOBJECT_TYPE_FLAGDROP:   return flagdrop.noDamageImmune != 0;
            default: return true;
        }
    }

    bool CannotBeUsedUnderImmunity() const // Cannot be used/activated/looted by players under immunity effects (example: Divine Shield)
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_DOOR:       return door.noDamageImmune != 0;
            case GAMEOBJECT_TYPE_BUTTON:     return button.noDamageImmune != 0;
            case GAMEOBJECT_TYPE_QUESTGIVER: return questgiver.noDamageImmune != 0;
            case GAMEOBJECT_TYPE_CHEST:      return true;                           // All chests cannot be opened while immune on 3.3.5a
            case GAMEOBJECT_TYPE_GOOBER:     return goober.noDamageImmune != 0;
            case GAMEOBJECT_TYPE_FLAGSTAND:  return flagstand.noDamageImmune != 0;
            case GAMEOBJECT_TYPE_FLAGDROP:   return flagdrop.noDamageImmune != 0;
            default: return false;
        }
    }

    uint32 GetCharges() const                               // despawn at uses amount
    {
        switch (type)
        {
            //case GAMEOBJECT_TYPE_TRAP:        return trap.charges;
            case GAMEOBJECT_TYPE_GUARDPOST:   return guardpost.charges;
            case GAMEOBJECT_TYPE_SPELLCASTER: return spellcaster.charges;
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
            case GAMEOBJECT_TYPE_AREADAMAGE:    autoCloseTime = areadamage.autoClose; break;
            default: break;
        }
        return autoCloseTime;              // prior to 3.0.3, conversion was / 0x10000;
    }

    uint32 GetLootId() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_CHEST:       return chest.chestLoot;
            case GAMEOBJECT_TYPE_FISHINGHOLE: return fishinghole.chestLoot;
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
            case GAMEOBJECT_TYPE_CHAIR:         return chair.triggeredEvent;
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

    bool IsInfiniteGameObject() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_DOOR:                      return door.InfiniteAOI != 0;
            case GAMEOBJECT_TYPE_FLAGSTAND:                 return true;
            case GAMEOBJECT_TYPE_FLAGDROP:                  return true;
            case GAMEOBJECT_TYPE_DUNGEON_DIFFICULTY:        return true;
            case GAMEOBJECT_TYPE_TRAPDOOR:                  return true;
            case GAMEOBJECT_TYPE_DESTRUCTIBLE_BUILDING:     return true;
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
            case GAMEOBJECT_TYPE_GENERIC:               return _generic.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_TRAP:                  return trap.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_SPELL_FOCUS:           return spellFocus.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_GOOBER:                return goober.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_TRANSPORT:             return true;
            case GAMEOBJECT_TYPE_SPELLCASTER:           return spellcaster.GiganticAOI != 0;
            case GAMEOBJECT_TYPE_CAPTURE_POINT:         return capturePoint.GiganticAOI != 0;
            default: return false;
        }
    }

    uint32 GetServerOnly() const
    {
        switch (type)
        {
            case GAMEOBJECT_TYPE_GENERIC: return _generic.serverOnly;
            case GAMEOBJECT_TYPE_TRAP: return trap.serverOnly;
            case GAMEOBJECT_TYPE_SPELL_FOCUS: return spellFocus.serverOnly;
            case GAMEOBJECT_TYPE_AURA_GENERATOR: return auraGenerator.serverOnly;
            default: return 0;
        }
    }

    void InitializeQueryData();
    WorldPacket BuildQueryData(LocaleConstant loc) const;
};

// From `gameobject_template_addon`
struct GameObjectTemplateAddon
{
    uint32  faction;
    uint32  flags;
    uint32  mingold;
    uint32  maxgold;
    std::array<uint32, 5> artKits;
};

struct GameObjectLocale
{
    std::vector<std::string> Name;
    std::vector<std::string> CastBarCaption;
};

struct TC_GAME_API QuaternionData
{
    float x, y, z, w;

    QuaternionData() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) { }
    QuaternionData(float X, float Y, float Z, float W) : x(X), y(Y), z(Z), w(W) { }

    bool isUnit() const;
    static QuaternionData fromEulerAnglesZYX(float Z, float Y, float X);
};

// `gameobject_addon` table
struct GameObjectAddon
{
    QuaternionData ParentRotation;
    InvisibilityType invisibilityType;
    uint32 InvisibilityValue;
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

enum class GameObjectActions : uint32
{
    // Name from client executable      // Comments
    None,                           // -NONE-
    AnimateCustom0,                 // Animate Custom0
    AnimateCustom1,                 // Animate Custom1
    AnimateCustom2,                 // Animate Custom2
    AnimateCustom3,                 // Animate Custom3
    Disturb,                        // Disturb                          // Triggers trap
    Unlock,                         // Unlock                           // Resets GO_FLAG_LOCKED
    Lock,                           // Lock                             // Sets GO_FLAG_LOCKED
    Open,                           // Open                             // Sets GO_STATE_ACTIVE
    OpenAndUnlock,                  // Open + Unlock                    // Sets GO_STATE_ACTIVE and resets GO_FLAG_LOCKED
    Close,                          // Close                            // Sets GO_STATE_READY
    ToggleOpen,                     // Toggle Open
    Destroy,                        // Destroy                          // Sets GO_STATE_DESTROYED
    Rebuild,                        // Rebuild                          // Resets from GO_STATE_DESTROYED
    Creation,                       // Creation
    Despawn,                        // Despawn
    MakeInert,                      // Make Inert                       // Disables interactions
    MakeActive,                     // Make Active                      // Enables interactions
    CloseAndLock,                   // Close + Lock                     // Sets GO_STATE_READY and sets GO_FLAG_LOCKED
    UseArtKit0,                     // Use ArtKit0                      // 46904: 121
    UseArtKit1,                     // Use ArtKit1                      // 36639: 81, 46903: 122
    UseArtKit2,                     // Use ArtKit2
    UseArtKit3,                     // Use ArtKit3
    SetTapList,                     // Set Tap List
    GoTo1stFloor,                   // Go to 1st floor
    GoTo2ndFloor,                   // Go to 2nd floor
    GoTo3rdFloor,                   // Go to 3rd floor
    GoTo4thFloor,                   // Go to 4th floor
    GoTo5thFloor,                   // Go to 5th floor
    GoTo6thFloor,                   // Go to 6th floor
    GoTo7thFloor,                   // Go to 7th floor
    GoTo8thFloor,                   // Go to 8th floor
    GoTo9thFloor,                   // Go to 9th floor
    GoTo10thFloor,                  // Go to 10th floor
    UseArtKit4,                     // Use ArtKit4
    PlayAnimKit,                    // Play Anim Kit "%s"               // MiscValueB -> Anim Kit ID
    OpenAndPlayAnimKit,             // Open + Play Anim Kit "%s"        // MiscValueB -> Anim Kit ID
    CloseAndPlayAnimKit,            // Close + Play Anim Kit "%s"       // MiscValueB -> Anim Kit ID
};

#endif // GameObjectData_h__
