SET @GUID := 8000041;

-- Add missing Spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+4;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@GUID,162817,2175,10424,10529,'0',0,14663,0,-1,0,0,243.55556,-2242.9185,83.88086,4.5683498,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Torgok <Binder of Souls>
(@GUID+1,150245,2175,10424,10529,'0',0,13835,0,-1,0,0,169.23438,-2297.9983,82.15651,2.54967,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Lindie Springstock
(@GUID+2,156800,2175,10424,10529,'0',0,13835,0,-1,0,0,186.51042,-2284.6216,81.91817,3.558244,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Quartermaster Richter <Supplies>
(@GUID+3,156807,2175,10424,10529,'0',0,13835,0,-1,0,0,185.90625,-2288.927,81.77783,1.908762,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649), -- Captain Garrick
(@GUID+4,156808,2175,10424,10529,'0',0,13835,0,-1,0,0,169.73827,-2293.4995,82.96085,2.618248,120,0,0,1,0,0,NULL,NULL,NULL,NULL,'',NULL,52649); -- Small Boar

-- Pathing for Small Boar Entry: 156808
SET @NPC := @GUID+4;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `wander_distance`=0,`MovementType`=2,`position_x`=165.30946,`position_y`=-2298.7698,`position_z`=82.51129 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`PathId`,`mount`,`StandState`,`SheathState`,`emote`,`visibilityDistanceType`,`auras`) VALUES (@NPC,@PATH,0,0,1,0,0, '');
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Small Boar Ogre Ruins');
DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,165.30946,-2298.7698,82.51129,NULL,0),
(@PATH,2,170.00575,-2301.923,82.05885,NULL,0),
(@PATH,3,173.15572,-2298.7876,81.85623,NULL,0),
(@PATH,4,168.463,-2294.0735,81.95101,NULL,0);

-- Pathing for Henry Garrick Ogre Ruins
SET @NPC := 8000023;
SET @PATH := @NPC * 10;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Henry Garrick Ogre Ruins');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,231.05,-2297.1802,87.1176,NULL,0),
(@PATH,2,230.88,-2297.09,84.0067,NULL,0),
(@PATH,3,230.71,-2297,80.8958,NULL,0),
(@PATH,4,230.71,-2297,80.8958,1.396685,0);

UPDATE `creature` SET `StringId`= "captain_garrick_plains" WHERE `guid`=8000018;
UPDATE `creature` SET `StringId` = 'henry_garrick_ogre_ruins_prisoner' WHERE `guid`=8000023;
UPDATE `creature_template` SET `ScriptName`="npc_captain_garrick_q55879" WHERE `entry`=174955;
UPDATE `creature_template` SET `ScriptName`="npc_giant_boar_vehicle_q55879" WHERE `entry`=156267;
UPDATE `creature_template` SET `ScriptName`="npc_torgok_q55879" WHERE `entry`=162817;
UPDATE `creature_template` SET `ScriptName`="npc_henry_garrick_prisioner" WHERE `entry`=156799;
UPDATE `creature_template` SET `npcflag`=16777216 WHERE entry IN (156595);
UPDATE `creature_template` SET `VehicleId`=6832 WHERE `entry`=156267;
UPDATE `creature_template` SET `npcflag`=2 WHERE `entry` IN (156799,156807);
UPDATE `creature_template` SET `npcflag`=641 WHERE `entry` IN (156800);
DELETE FROM `creature_template_addon` WHERE `entry` IN (162817);
INSERT INTO `creature_template_addon` (`entry`,`visibilityDistanceType`,`emote`,`auras`) VALUES
(162817,3,617, ''); -- Torgok

-- Henry Garrick & Shuja Grimaxe
UPDATE `creature_template_movement` SET `Ground`=1, `Swim`=1 WHERE `CreatureId` IN (156799,167126);

DELETE FROM `npc_vendor` WHERE (`entry`=156800 AND `item`=168100 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=156800 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(156800, 2, 168100, 0, 0, 1, 0, 0, 53040), -- 168100
(156800, 1, 117, 0, 0, 1, 0, 1, 53040); -- 117

DELETE FROM `creature_template_gossip` WHERE `CreatureID`=156800;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(156800, 24885, 53040); -- 156800

DELETE FROM `gossip_menu` WHERE (`MenuID`=24885 AND `TextID`=201865);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(24885, 201865, 53040); -- 156800

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (24885);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(24885, 49522, 0, 1, 'Let me browse your goods.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 53040);

DELETE FROM `creature_text` WHERE `CreatureID`=162817;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(162817, 0, 0, 'We take soul for ritual, you no stop!', 12, 0, 100, 0, 0, 0, 0, 0, 'Torgok aggro'),
(162817, 1, 0, 'Me never get... to see... ritual...', 12, 0, 100, 0, 0, 0, 0, 0, 'Torgok death');

-- Add Scenes for Ride of the Scientifically Enhanced Boar
DELETE FROM `scene_template` WHERE `SceneId` IN (2338,2341,2423,2422,2421,2420);
INSERT INTO `scene_template` (`SceneId`,`Flags`,`ScriptPackageID`,`Encrypted`,`ScriptName`) VALUES
(2338,16,2712,0,'scene_darkmaul_plains_skeleton_army'),
(2341,17,2933,0,''),
(2423,16,2825,0,''),
(2422,16,2824,0,''),
(2421,16,2823,0,''),
(2420,16,2822,0,'');

-- Summon data for Captain Garrick
DELETE FROM `creature_summoned_data` WHERE `CreatureID` IN (174955);
INSERT INTO `creature_summoned_data` (`CreatureID`,`CreatureIDVisibleToSummoner`,`GroundMountDisplayID`,`FlyingMountDisplayID`, `DespawnOnQuestsRemoved`) VALUES
(174955,156280,NULL,NULL, '55879');

-- Spell Click
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (156595);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`cast_flags`,`user_type`) VALUES
(156595,305068,1,0);

-- Spell Target Position
DELETE FROM `spell_target_position` WHERE `ID` IN (305069);
INSERT INTO `spell_target_position` (`ID`,`EffectIndex`,`MapID`,`PositionX`,`PositionY`,`PositionZ`,`VerifiedBuild`) VALUES
(305069,0,2175,116.44965,-2430.3699,90.6546,52649);

-- Condition for Spell click event condition type Queststate
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=18 AND `SourceGroup` IN (156595) AND `SourceEntry` IN (305068) AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(18, 156595, 305068, 0, 0, 47, 0, 55879, 8, 0, 0, 0, 0, '', 'Spellclick unit Giant Boar will cast spell Summon Darkmaul Plains Questgivers (DNT) on player if quest Ride of the Scientifically Enhanced Boar queststate is INCOMPLETE');

-- Condition for source Spell implicit target condition type Object entry guid
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=325406 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 325406, 0, 0, 31, 0, 3, 162817, 0, 0, 0, 0, '', 'Spell Necrotic Ritual (effect 0) will hit the potential target of the spell if target is unit Torgok.');

-- Condition for Spell Ping Garrick (DNT)
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=1 AND `SourceEntry`=316982 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 316982, 0, 0, 31, 0, 3, 174955, 0, 0, 0, 0, '', 'Spell Ping Garrick (DNT) (effect 0) will hit unit Alliance Captain.'),
(13, 1, 316982, 0, 1, 31, 0, 3, 167146, 0, 0, 0, 0, '', 'Spell Ping Garrick (DNT) (effect 0) will hit unit Horde Warrior.');

DELETE FROM `spell_script_names` WHERE `spell_id` IN (305779,173426,306357,296843);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(305779,'spell_summon_darkmaul_plains_questgivers_q55879'),
(173426,'spell_riding_giant_boar_q55879'),
(306357,'spell_knockback_hint_q56034'),
(296843,'spell_gear_repaired_aura_q55194');

-- Phase Area
DELETE FROM `phase_area` WHERE `AreaId`=10424 AND `PhaseId` IN (14663,13835);
INSERT INTO `phase_area` (`AreaId`,`PhaseId`,`Comment`) VALUES
(10424,14663, 'Cosmetic - NPE - See Torgok <Binder of Souls>'),
(10424,13835, 'Cosmetic - NPE - See Captain Garrick, Lindie Springstock, Quartermaster Richter Ogre Ruins');

-- Phase Names
DELETE FROM `phase_name` WHERE `ID` IN (14663,13835);
INSERT INTO `phase_name` (`ID`,`Name`) VALUES
(14663,'Cosmetic - NPE - See Torgok <Binder of Souls>'),
(13835,'Cosmetic - NPE - See Captain Garrick, Lindie Springstock, Quartermaster Richter Ogre Ruins');

-- Phase Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13775,13783) AND `ConditionValue1`=321670;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (13784,13779,13785,13780,13776,13766,13775) AND `ConditionValue1`=55879;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (14663,13835) AND `SourceEntry`=10424;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(26,13775,10588, 0, 0, 1, 0, 321670, 0, 0, 1, 0, 0, '', 'See Re-sized Boar at Plains if quest Ride if player does not have aura'),
(26,13783,10529, 0, 0, 1, 0, 321670, 0, 0, 1, 0, 0, '', 'See See the Army of Undead if quest Ride if player does not have aura'),
(26,13784,10424, 0, 0, 47, 0, 55879, 66, 0, 1, 0, 0, '', 'See Henry Garrick at Ogre Ruins if quest Ride of the Scientifically Enhanced Boar is not completed | rewarded'),
(26,13779,10588, 0, 0, 47, 0, 55879, 74, 0, 1, 0, 0, '', 'See Captain Garrick at Plains if quest Ride of the Scientifically Enhanced Boar is not taken | completed | rewarded'),
(26,13785,10588, 0, 0, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See The Scout-o-Matic 5000 at Plains if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,13780,10588, 0, 0, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See Austin Huxworth at Darkmaul Plains if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,13780,10588, 0, 1, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See Austin Huxworth at Darkmaul Plains if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,13776,10588, 0, 0, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See Lindie Springstock at Darkmaul Plains if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,13766,10588, 0, 0, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See Alliance crew at Darkmaul Plains if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,13775,10588, 0, 0, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See Re-sized Boar at Plains if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,14663,10424, 0, 0, 47, 0, 55879, 64, 0, 1, 0, 0, '', 'See Torgok <Binder of Souls> if quest Ride of the Scientifically Enhanced Boar is not rewarded'),
(26,14663,10424, 0, 0, 48, 0, 396499, 0, 8, 0, 0, 0, '', 'See Torgok <Binder of Souls> if quest Ride if player has objective complete'),
(26,13835,10424, 0, 0, 47, 0, 55879, 64, 0, 0, 0, 0, '', 'See Garrick, Lindie, Richter at ogre ruins if quest Ride of the Scientifically Enhanced Boar is rewarded');

-- Quest data
DELETE FROM `creature_queststarter` WHERE `id`=156280 AND `quest`=55879;
DELETE FROM `creature_queststarter` WHERE `id`=156807 AND `quest`=55194;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(156280, 55879, 52649), -- Ride of the Scientifically Enhanced Boar accept from Captain Garrick
(156807, 55194, 52649); -- Stocking Up on Supplies accept from Captain Garrick

DELETE FROM `creature_questender` WHERE `id`=156799 AND `quest`=55879;
DELETE FROM `creature_questender` WHERE `id`=156807 AND `quest`=55194;
INSERT INTO `creature_questender` (`id`, `quest`, `VerifiedBuild`) VALUES
(156799, 55879, 52649), -- Ride of the Scientifically Enhanced Boar turn in to Henry Garrick
(156807, 55194, 52649); -- Stocking Up on Supplies turn in to Captain Garrick

DELETE FROM `quest_template_addon` WHERE `ID` IN (55879,55194);
INSERT INTO `quest_template_addon` (`ID`,`AllowableClasses`,`PrevQuestID`,`NextQuestID`,`ScriptName`) VALUES
(55879,0,56034,0,'quest_ride_of_the_scientifically_enhanced_boar'), -- Ride of the Scientifically Enhanced Boar
(55194,0,55879,0,''); -- Stocking Up on Supplies

-- Conversation
DELETE FROM `conversation_template` WHERE `Id` IN (12090,12091,12092,12164,15615);
INSERT INTO `conversation_template` (`Id`,`FirstLineId`,`TextureKitId`,`ScriptName`,`VerifiedBuild`) VALUES
(12090,29443,0,'',52649),
(12091,29446,0,'',52649),
(12092,29447,0,'',52649),
(12164,29660,0,'',52649),
(15615,39167,0,'',52649);

DELETE FROM `conversation_actors` WHERE `ConversationId` IN (12090,12091,12092,12164,15615);
INSERT INTO `conversation_actors` (`ConversationId`,`ConversationActorId`,`ConversationActorGuid`,`Idx`,`CreatureId`,`CreatureDisplayInfoId`,`NoActorObject`,`ActivePlayerObject`,`VerifiedBuild`) VALUES
(12090,0,0,0,0,0,0,1,52649), -- Player
(12090,71372,0,1,0,0,0,0,52649), -- Captain Garrick
(12091,71587,8000023,0,0,0,0,0,52649), -- Henry Garrick
(12092,0,0,0,0,0,0,1,52649), -- Player
(12092,71372,0,1,0,0,0,0,52649), -- Captain Garrick
(12164,71372,0,0,0,0,0,0,52649), -- Captain Garrick
(15615,71372,0,0,0,0,0,0,52649), -- Captain Garrick
(15615,78493,0,1,0,0,0,0,52649); -- Henry Garrick

DELETE FROM `conversation_line_template` WHERE `Id` IN (29443,29444,29446,29660,29447,29448,29450,39167,39163,39164,39165,39166);
INSERT INTO `conversation_line_template` (`Id`,`UiCameraID`,`ActorIdx`,`Flags`,`VerifiedBuild`) VALUES
(29443,0,0,0,52649),
(29444,0,1,0,52649),
(29446,0,0,0,52649),
(29660,0,0,0,52649),
(29447,0,0,0,52649),
(29448,0,1,0,52649),
(29450,0,1,0,52649),
(39167,0,0,0,52649),
(39163,0,1,0,52649),
(39164,0,0,0,52649),
(39165,0,0,0,52649),
(39166,0,1,0,52649);

-- Lindie Springstock SAI 'Ogre Ruins'
SET @NPC := 150245;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,1,1,0,100,0,8000,10000,8000,10000,0,66,0,0,0,0,0,0,19,156808,10,0,0,0,0,0,0,'Face Small Boar'),
(@NPC,0,1,0,61,0,100,0,0,0,0,0,0,5,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Emote OneShotCheer');

-- Captain Garrick SAI 'Ogre Ruins'
SET @NPC := 156807;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@NPC;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@NPC) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@NPC,0,0,47,0,0,100,0,55194,0,0,0,0,11,296845,0,0,0,0,0,7,0,0,0,0,0,0,0,0,'Quest reward Cast Gear repair on player');

-- Loot for Torgok
SET @ID := 162817;
UPDATE `creature_template_difficulty` SET `LootID`=@ID, GoldMin=4, GoldMax=20 WHERE `Entry` IN (@ID);
DELETE FROM `creature_loot_template` WHERE `Entry` IN (@ID);
INSERT INTO `creature_loot_template` (`Entry`,`Item`,`Reference`,`Chance`,`QuestRequired`,`LootMode`,`GroupId`,`MinCount`,`MaxCount`,`Comment`) VALUES
(@ID,176398,0,100,0,1,0,1,1,'Torgok - Torgok\'s Reagent Pouch'),
(@ID,175245,0,5,0,1,0,1,1,'Torgok - Runetusk Necklace'),
(@ID,0,10100,10,0,1,0,1,1,'Torgok - Poor Quality Table Level 1 to 5');

-- Conditions for class loot
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=1 AND `SourceGroup`=@ID;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(1,@ID,176398,0,0,47,0,59610,64,0,1,0,0,'','Item drops if quest 59610 is not rewarded');

DELETE FROM `quest_template` WHERE `ID`=59610;
INSERT INTO `quest_template` (`ID`,`QuestType`,`RewardXPMultiplier`,`RewardMoneyMultiplier`,`RewardArtifactXPMultiplier`,`Flags`,`LogTitle`) VALUES
(59610,2,1,1,1,1024, '[Hidden Tracker] Torgok\'s Reagent Pouch Dropped');
