SET @CGUID := 5000008;
SET @OGUID := 5000029;

-- game tele
DELETE FROM `game_tele` WHERE `id`=1967;
INSERT INTO `game_tele` (`id`, `position_x`, `position_y`, `position_z`, `orientation`, `map`, `name`) VALUES 
(1967, 4066.56, -2382.24, 97.8062, 1.5708, 1265, 'AssaultOnTheDarkPortalScenario');

-- Creatures
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 78423, 0, 4, 72, '0', 0, 866, 1190, 0, 1, -11812.2607421875, -3205.59716796875, -29.479166030883789, 3.093542814254760742, 120, 0, 0, 640000, 9573, 0, 0, 0, 50791), -- Archmage Khadgar (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 128281 - Moonbeam Visual)
(@CGUID+1, 78553, 0, 4, 72, '0', 0, 866, 1190, 0, 1, -11811.513671875, -3207.8837890625, -29.5382575988769531, 3.295763015747070312, 120, 0, 0, 4800000, 320750, 0, 0, 0, 50791), -- Thrall (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@CGUID+2, 79675, 0, 4, 72, '0', 0, 866, 1190, 0, 1, -11811.173828125, -3211.630126953125, -30.9784984588623046, 3.190636873245239257, 120, 0, 0, 400000, 0, 0, 0, 0, 50791), -- Lady Liadrin (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@CGUID+3, 78554, 0, 4, 72, '0', 2801, 0, 1190, 0, 1, -11811.8818359375, -3203.59033203125, -29.5511932373046875, 3.358216285705566406, 120, 0, 0, 4800000, 128300, 0, 0, 0, 50791), -- Vindicator Maraad (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 165746 - Retribution Aura)
(@CGUID+4, 78554, 0, 4, 72, '0', 3146, 0, 1190, 0, 1, -11811.8818359375, -3203.59033203125, -29.5511932373046875, 3.358216285705566406, 120, 0, 0, 4800000, 128300, 0, 0, 0, 50791), -- Vindicator Maraad (Area: The Dark Portal - Difficulty: 0) CreateObject1 (Auras: 165746 - Retribution Aura)
(@CGUID+5, 78430, 0, 4, 72, '0', 0, 866, 1190, 0, 1, -11811.48828125, -3201.296875, -29.9500179290771484, 3.295083284378051757, 120, 0, 0, 400000, 100, 0, 0, 0, 50791), -- Cordana Felsong (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@CGUID+6, 78558, 1265, 7025, 7037, '0', 3563, 0, 0, 0, 1, 4066.427001953125, -2372.5712890625, 94.6800384521484375, 1.593950867652893066, 120, 0, 0, 640000, 9573, 0, 0, 0, 50791); -- Archmage Khadgar (Area: The Dark Portal - Difficulty: 0) CreateObject1

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '128281'), -- Archmage Khadgar - 128281 - Moonbeam Visual
(@CGUID+2, 0, 19085, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Lady Liadrin
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '165746'), -- Vindicator Maraad - 165746 - Retribution Aura
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '165746'), -- Vindicator Maraad - 165746 - Retribution Aura
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- Archmage Khadgar

UPDATE `creature_template` SET `unit_flags3`=1048576 WHERE `entry`=78430; -- Cordana Felsong
UPDATE `creature_template` SET `unit_flags3`=9437184 WHERE `entry`=78554; -- Vindicator Maraad
UPDATE `creature_template` SET `unit_flags3`=1048576 WHERE `entry`=78553; -- Thrall

UPDATE `creature_queststarter` SET `VerifiedBuild`=50791 WHERE (`id`=78558 AND `quest`=35933) OR (`id`=78423 AND `quest`=36881);
UPDATE `creature_questender` SET `VerifiedBuild`=50791 WHERE (`id`=78558 AND `quest`=36881) OR (`id`=78558 AND `quest`=34398);

DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=79675 AND `MenuID`=16433);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(79675, 16433, 50791); -- Lady Liadrin

-- Gameobjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 230609, 0, 4, 72, '0', 0, 866, 1190, -11812.37890625, -3205.60595703125, -29.5840053558349609, 0, 0, 0, 0, 1, 120, 255, 1, 50791), -- Collision PC Size x2.5 (Area: The Dark Portal - Difficulty: 0) CreateObject1
(@OGUID+1, 188215, 1265, 7025, 7037, '0', 3563, 0, 0, 4066.33251953125, -2372.5712890625, 94.59978485107421875, 0, 0, 0, 0, 1, 120, 255, 1, 50791); -- Collision PC Size (Area: The Dark Portal - Difficulty: 0) CreateObject1

-- Gossip
UPDATE `gossip_menu_option` SET `GossipOptionID`=43231, `BoxText`='You are about to embark on a dangerous mission, and you may not be able to return immediately. Are you sure?', `BoxBroadcastTextID`= 88773, `VerifiedBuild`=50791 WHERE (`MenuID`=16863 AND `OptionID`=0);

-- Quest
UPDATE `quest_poi` SET `VerifiedBuild`=50791 WHERE (`QuestID`=36881 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=36881 AND `BlobIndex`=0 AND `Idx1`=1) OR (`QuestID`=36881 AND `BlobIndex`=0 AND `Idx1`=0);
UPDATE `quest_poi_points` SET `VerifiedBuild`=50791 WHERE (`QuestID`=36881 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=36881 AND `Idx1`=1 AND `Idx2`=0) OR (`QuestID`=36881 AND `Idx1`=0 AND `Idx2`=0);
UPDATE `quest_details` SET `VerifiedBuild`=50791 WHERE `ID` = 36881;

-- Phase
DELETE FROM `phase_area` WHERE `AreaId` = 7037 AND `PhaseId` = 3563;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7037, 3563, 'See Khadgar at the Dark Portal (Assault on the Dark Portal)');

-- Conditions
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=16863 AND `ConditionValue1` IN (36881, 34398);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 16863, 0, 0, 0, 47, 0, 36881, 8, 0, 0, 0, 0, '', 'Gossip Option 16863 - Show Option 0 if Quest 36881 is in progress'),
(15, 16863, 0, 0, 1, 47, 0, 34398, 8, 0, 0, 0, 0, '', 'Gossip Option 16863 - Show Option 0 if Quest 34398 is in progress');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 3563 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 3563, 0, 0, 0, 47, 0, 34393, 2 | 64, 0, 1, 'Apply Phase 3563 if Quest 34393 is not complete | rewarded');

-- SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=78423; -- 78423 (Archmage Khadgar)
DELETE FROM `smart_scripts` WHERE `entryorguid`=78423 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(78423, 0, 0, 1, 62, 0, 100, 0, 16863, 0, 0, 0, 0, '', 72, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Archmage Khadgar - On Gossip Option 0 Selected - Close Gossip'),
(78423, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, '', 85, 168956, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 'Archmage Khadgar - On Gossip Option 0 Selected - Invoker Cast \'Into the Portal Cinematic\'');
