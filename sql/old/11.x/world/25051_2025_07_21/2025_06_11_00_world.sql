SET @CGUID := 3000010;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 38895, 0, 6454, 5692, '0', 1660, 0, 0, 0, 1757.392333984375, 1666.0972900390625, 121.2991867065429687, 5.401799201965332031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Lilian Voss (Area: The Deathknell Graves - Difficulty: 0) CreateObject1
(@CGUID+1, 49230, 0, 6454, 5692, '0', 1661, 0, 0, 0, 1753.845458984375, 1640.6632080078125, 117.5885696411132812, 5.686965465545654296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Marshal Redpath (Area: The Deathknell Graves - Difficulty: 0) CreateObject1
(@CGUID+2, 49231, 0, 6454, 5692, '0', 1662, 0, 0, 0, 1740.3541259765625, 1704.37158203125, 128.859344482421875, 1.500983119010925292, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 61265); -- Valdred Moray (Area: The Deathknell Graves - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Lilian Voss
(@CGUID+2, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Valdred Moray

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (49231 /*49231 (Valdred Moray)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(49231, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 49231 (Valdred Moray)

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=75, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=66167 AND `DifficultyID`=0); -- 66167 (Marshal Redpath) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=75, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=66166 AND `DifficultyID`=0); -- 66166 (Lilian Voss) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=75, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=66168 AND `DifficultyID`=0); -- 66168 (Valdred Moray) - CanSwim

-- Phase
DELETE FROM `phase_area` WHERE `PhaseId` IN (1660,1661,1662);
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(5692, 1660, 'See Lilian Voss in Deathknell'),
(5692, 1661, 'See Marshal Redpath in Deathknell'),
(5692, 1662, 'See Valdred Moray in Deathknell');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (1660,1661,1662) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 1660, 0, 0, 0, 47, 0, 24960, 8, 0, 0, 'Apply Phase 1660 if Quest 24960 is in progress'),
(26, 1660, 0, 0, 0, 48, 0, 256141, 0, 1, 1, 'Apply Phase 1660 if Questobjective 256141 is not rewarded'),
(26, 1661, 0, 0, 0, 47, 0, 24960, 8, 0, 0, 'Apply Phase 1661 if Quest 24960 is in progress'),
(26, 1661, 0, 0, 0, 48, 0, 256142, 0, 1, 1, 'Apply Phase 1661 if Questobjective 256142 is not rewarded'),
(26, 1662, 0, 0, 0, 47, 0, 24960, 8, 0, 0, 'Apply Phase 1662 if Quest 24960 is in progress'),
(26, 1662, 0, 0, 0, 48, 0, 256143, 0, 1, 1, 'Apply Phase 1662 if Questobjective 256143 is not rewarded');

-- Quest
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (256141,256142,256143);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(256141, NULL, NULL, NULL, 1, 0),
(256142, NULL, NULL, NULL, 1, 0),
(256143, NULL, NULL, NULL, 1, 0);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=49231 AND `MenuID`=12487) OR (`CreatureID`=49231 AND `MenuID`=12489) OR (`CreatureID`=38895 AND `MenuID`=12483) OR (`CreatureID`=38895 AND `MenuID`=12484) OR (`CreatureID`=49230 AND `MenuID`=12485) OR (`CreatureID`=49230 AND `MenuID`=12486);;
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(49231, 12487, 61265), -- Valdred Moray
(38895, 12483, 61265), -- Lilian Voss
(49230, 12485, 61265); -- Marshal Redpath

UPDATE `gossip_menu` SET `VerifiedBuild`=61265 WHERE (`MenuID`=12489 AND `TextID`=17571) OR (`MenuID`=12488 AND `TextID`=17570) OR (`MenuID`=12487 AND `TextID`=17569);

UPDATE `gossip_menu_option` SET `GossipOptionID`=39803, `OptionText`='You talk to Undertaker Mordo.  He\'ll tell you what to do.  That\'s all I know.', `VerifiedBuild`=61265 WHERE (`MenuID`=12489 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=39543, `OptionText`='Calm down, Valdred.  Undertaker Mordo probably sewed some new ones on for you.', `VerifiedBuild`=61265 WHERE (`MenuID`=12488 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=39542, `OptionText`='Don\'t you remember?  You died.', `VerifiedBuild`=61265 WHERE (`MenuID`=12487 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=39163, `OptionText`='I\'m not an abomination, I\'m simply undead.  I just want to speak with you.', `VerifiedBuild`=61265 WHERE (`MenuID`=12483 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=39164, `VerifiedBuild`=61265 WHERE (`MenuID`=12484 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=39165, `OptionText`='I\'m not here to fight.  I\'ve only been asked to speak with you.', `VerifiedBuild`=61265 WHERE (`MenuID`=12485 AND `OptionID`=0);
UPDATE `gossip_menu_option` SET `GossipOptionID`=39166, `VerifiedBuild`=61265 WHERE (`MenuID`=12486 AND `OptionID`=0);

-- Spelltarget pos
UPDATE `spell_target_position` SET `VerifiedBuild`=61265 WHERE (`ID`=91876 AND `EffectIndex`=0 AND `OrderIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=61265 WHERE (`ID`=91874 AND `EffectIndex`=0 AND `OrderIndex`=0);
UPDATE `spell_target_position` SET `VerifiedBuild`=61265 WHERE (`ID`=91873 AND `EffectIndex`=0 AND `OrderIndex`=0);

-- Delete hack SAI
SET @ENTRY := 2307;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 25089, 0, 0, 0, 0, 85, 91938, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Beyond the Graves (25089) - Player who accepted quest: Cast spell 91938 on self', '');

 -- Valdred Moray smart ai
SET @ENTRY := 49231;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 12489, 0, 0, 0, 0, 85, 91876, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 12489 selected - Gossip player: Cast spell 91876 on self', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 12489 selected - Gossip player: Close gossip', '');

-- Valdred Moray smart ai
SET @ENTRY := 66168;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 6616800, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Valdred Moray #0 (6616800) (update always) // -inline', ''),
(@ENTRY, 0, 1, 2, 34, 0, 100, 0, 2, 4, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 4 - Self: Talk 1 to invoker', ''),
(@ENTRY, 0, 2, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 4 - Self: Despawn in 1 s', '');

-- Timed list 6616800 smart ai
SET @ENTRY := 6616800;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Look at Owner/Summoner', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 0, 53, 0, 6616800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 2 seconds - Self: Start path #6616800, walk, do not repeat, Passive', '');

-- Lilian Voss smart ai
SET @ENTRY := 38895;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 12484, 0, 0, 0, 0, 85, 91874, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 12484 selected - Gossip player: Cast spell 91874 on self', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 12484 selected - Gossip player: Close gossip', '');

-- Lilian Voss smart ai
SET @ENTRY := 66166;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 6616600, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Lilian Voss #0 (6616600) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 9, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 9 - Self: Despawn in 1 s', '');

 -- Timed list 6616600 smart ai
SET @ENTRY := 6616600;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Look at Owner/Summoner', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 53, 0, 6616600, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Start path #6616600, walk, do not repeat, Passive', '');

-- Marshal Redpath smart ai
SET @ENTRY := 49230;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 62, 0, 100, 0, 12486, 0, 0, 0, 0, 85, 91873, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 12486 selected - Gossip player: Cast spell 91873 on self', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On gossip action 0 from menu 12486 selected - Gossip player: Close gossip', '');

-- Marshal Redpath smart ai
SET @ENTRY := 66167;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 80, 6616700, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start timed action list id #Marshal Redpath #0 (6616700) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 34, 0, 100, 0, 2, 9, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 9 - Self: Despawn in 1 s', '');

-- Timed list 6616700 smart ai
SET @ENTRY := 6616700;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Look at Owner/Summoner', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Talk 0 to invoker', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, 53, 0, 6616700, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Start path #6616700, walk, do not repeat, Passive', '');

-- The Wakening
SET @ENTRY := 24960;
INSERT IGNORE INTO `quest_template_addon` (`ID`) VALUES (@ENTRY);
UPDATE `quest_template_addon` SET `ScriptName` = 'SmartQuest' WHERE `ID` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 5 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 5, 0, 0, 47, 0, 100, 0, 0, 0, 0, 0, 0, 85, 82238, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On quest accepted - Player who accepted: Cast spell 82238 on self', '');

-- Path for Valdred Moray
SET @ENTRY := 66168;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Valdred Moray - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1731.5817, 1699.7726, 127.54116, NULL, 0),
(@PATH, 1, 1720.118, 1691.7692, 131.76662, NULL, 0),
(@PATH, 2, 1708.849, 1685.158, 133.62527, NULL, 0),
(@PATH, 3, 1701.5798, 1679.4288, 134.18205, NULL, 0),
(@PATH, 4, 1692.6459, 1675.5365, 134.95877, NULL, 0);

-- Path for Lilian Voss
SET @ENTRY := 66166;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Lilian Voss - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1761.3629, 1639.5035, 115.48903, NULL, 0),
(@PATH, 1, 1767.8837, 1619.9254, 111.43228, NULL, 0),
(@PATH, 2, 1774.5435, 1603.1997, 108.29928, NULL, 0),
(@PATH, 3, 1786.2552, 1595.231, 104.58866, NULL, 0),
(@PATH, 4, 1806.8037, 1590.8623, 99.21434, NULL, 0),
(@PATH, 5, 1819.6666, 1589.4514, 95.8779, NULL, 0),
(@PATH, 6, 1842.1945, 1588.6788, 93.397705, NULL, 0),
(@PATH, 7, 1853.8959, 1587.6111, 92.88051, NULL, 0),
(@PATH, 8, 1859.9584, 1580.5486, 93.13185, NULL, 0),
(@PATH, 9, 1860.9028, 1577.3872, 94.34933, NULL, 0);

-- Path for Marshal Redpath
SET @ENTRY := 66167;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Marshal Redpath - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1750.1472, 1626.4747, 113.73333, NULL, 0),
(@PATH, 1, 1751.6462, 1610.0747, 113.23333, NULL, 0),
(@PATH, 2, 1751.1472, 1596.7247, 113.73333, NULL, 0),
(@PATH, 3, 1750.3972, 1585.9747, 114.48333, NULL, 0),
(@PATH, 4, 1748.6472, 1574.9747, 114.23333, NULL, 0),
(@PATH, 5, 1749.1472, 1560.4747, 114.73333, NULL, 0),
(@PATH, 6, 1750.8972, 1552.2247, 114.48333, NULL, 0),
(@PATH, 7, 1758.8972, 1543.4747, 114.73333, NULL, 0),
(@PATH, 8, 1763.3972, 1538.4747, 114.73333, NULL, 0),
(@PATH, 9, 1763.9045, 1533.3195, 113.88832, NULL, 0);
