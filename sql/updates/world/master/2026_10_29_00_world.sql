SET @CGUID := 10006986;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 224782, 2739, 15342, 15380, '0', 23761, 0, 0, 0, 1434.1875, -253.083328247070312, 8.140850067138671875, 1.595028400421142578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 70575), -- Dawn (Area: Awakening Machine - Difficulty: 0) CreateObject1
(@CGUID+1, 224783, 2739, 15342, 15380, '0', 23761, 0, 0, 0, 1432.3333740234375, -253.154510498046875, 8.17717742919921875, 1.7108689546585083, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 70575); -- Foreman Uzjax (Area: Awakening Machine - Difficulty: 0) CreateObject1

UPDATE `creature` SET `StringId` = 'CloneTarget' WHERE `guid` IN (@CGUID+0, @CGUID+1);

-- Template
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=224782; -- Dawn
UPDATE `creature_template` SET `faction`=3398, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=224783; -- Foreman Uzjax

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=782, `StaticFlags1`=0x10000000, `VerifiedBuild`=70575 WHERE (`Entry`=224782 AND `DifficultyID`=0); -- 224782 (Dawn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2803, `StaticFlags1`=0x10000000, `VerifiedBuild`=70575 WHERE (`Entry`=224783 AND `DifficultyID`=0); -- 224783 (Foreman Uzjax) - CanSwim

-- Phase
DELETE FROM `phase_name` WHERE `ID` = 23761;
INSERT INTO `phase_name` (`ID`, `Name`) VALUES 
(23761, 'Cosmetic - See Dawn and Foreman Uzjax');

DELETE FROM `phase_area` WHERE `AreaId`= 15380 AND `PhaseId` = 23761;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES 
(15380, 23761, 'See Dawn and Foreman Uzjax');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23761 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23761, 0, 0, 0, 47, 0, 79200, 2|8|64, 0, 0, 'Apply Phase 23761 if Quest 79200 is in progress | complete | rewarded');

-- Correct QuestID in last condition
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=26 AND `SourceGroup` = 23759 AND `SourceEntry`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUE
(26, 23759, 0, 0, 0, 47, 0, 79200, 2|8|64, 0, 1, 'Apply Phase 23759 if Quest 79200 is not in progress | complete | rewarded');

-- Conversation
DELETE FROM `conversation_template` WHERE `Id`=25327;
INSERT INTO `conversation_template` (`Id`, `FirstLineID`, `TextureKitId`, `VerifiedBuild`) VALUES
(25327, 68940, 0, 70575);

UPDATE `conversation_template` SET `ScriptName` = 'conversation_quest_who_am_i';

DELETE FROM `conversation_actors` WHERE (`ConversationId`=25327 AND `Idx` IN (1,0));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(25327, 98762, 1, 221839, 118887, 0, 0, 70575),
(25327, 98764, 0, 221841, 114674, 0, 0, 70575);

DELETE FROM `conversation_line_template` WHERE `Id` IN (68939, 68940);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(68939, 1809, 1, 0, 0, 70575),
(68940, 1808, 0, 0, 0, 70575);

-- Dawn smart ai
SET @ENTRY := 221839;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 19, 0, 100, 0, 79200, 0, 0, 0, 0, 143, 25327, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'On player accepted quest Who am I? (79200) - Player who accepted quest: Start conversation 25327', '');

-- Creature 224782 smart ai
SET @ENTRY := 224782;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 22478200, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start path #22478200, walk, do not repeat, Passive', ''),
(@ENTRY, 0, 1, 0, 58, 0, 100, 0, 3, 22478200, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 22478200 ended - Self: Despawn instantly', '');

-- Creature 224783 smart ai
SET @ENTRY := 224783;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 54, 0, 100, 0, 0, 0, 0, 0, 0, 53, 0, 22478300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On just summoned - Self: Start path #22478300, walk, do not repeat, Passive', ''),
(@ENTRY, 0, 1, 0, 58, 0, 100, 0, 3, 22478300, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On waypoint 3 of path 22478300 ended - Self: Despawn instantly', '');

-- Path for Dawn
SET @ENTRY := 224782;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Dawn - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1435.9567, -262.17883, 10.993773, NULL, 0),
(@PATH, 1, 1434.3264, -260.70834, 10.993773, NULL, 0),
(@PATH, 2, 1434.481, -259.19272, 10.952013, NULL, 0),
(@PATH, 3, 1434.1875, -253.08333, 8.412861, NULL, 0);

-- Path for Foreman Uzjax
SET @ENTRY := 224783;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Foreman Uzjax - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1437.724, -263.50522, 10.790649, NULL, 0),
(@PATH, 1, 1431.5452, -261.45834, 10.993773, NULL, 0),
(@PATH, 2, 1431.3438, -259.52258, 10.945606, NULL, 0),
(@PATH, 3, 1432.3334, -253.15451, 8.441866, NULL, 0);
