-- Creature
UPDATE `creature` SET `PhaseId` = 8691 WHERE `guid` = 7003603;

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 8691;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES
(8691, 'Cosmetic - See Smoochums on the rock in Glenbrook Hunting Grounds');

DELETE FROM `phase_area` WHERE `PhaseId` = 8691;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(8721, 8691, 'See Smoochums on the rock in Glenbrook Hunting Grounds');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 8691 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 8691, 0, 0, 0, 47, 0, 47428, 64, 0, 1, 'Apply Phase 8691 if Quest 47428 is not rewarded');

-- Smoochums smart ai
SET @ENTRY := 121684;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 1, 20, 0, 100, 0, 47428, 0, 0, 0, 0, 80, 12168400, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On player rewarded quest Kitty? (47428) - Self: Start timed action list id #Smoochums #0 (12168400) (update out of combat)', ''),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 0, 85, 82238, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player rewarded quest Kitty? (47428) - Rewarded player: Cast spell 82238 on self', '');

-- Timed list 12168400 smart ai
SET @ENTRY := 12168400;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 149, 8, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Become personal clone for Last action invoker for 0 seconds (manual despawn)', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0x20, 1000, 1000, 0, 0, 0, 97, 7, 0, 0, 1, 0, 0, 0, 8, 0, 0, 0, -308.526, 2107.78, 75.6347, 0, 'After 1 seconds - Self: Jump to pos (-308.526, 2107.78, 75.6347) with speed XY 0, speed Z 0 and gravity 0', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 12168400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Start path #12168400, walk, do not repeat, Passive', ''),
(@ENTRY, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 41, 5000, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Despawn in 5 s', '');

-- Path for Smoochums
SET @ENTRY := 121684;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Smoochums - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -308.526, 2107.78, 75.6347, NULL, 0),
(@PATH, 1, -317.18057, 2088.8142, 75.09699, NULL, 0),
(@PATH, 2, -331.1736, 2102.217, 76.74794, NULL, 0);
