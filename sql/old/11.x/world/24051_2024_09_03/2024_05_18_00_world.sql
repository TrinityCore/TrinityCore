-- Creature
SET @CGUID := 4000130;
SET @SPAWNGROUP := 71;

UPDATE `creature_template` SET `ScriptName`='boss_lava_guard_gordoth' WHERE `entry`=61528;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=61724;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=61716;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=61822;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=61823;

DELETE FROM `creature_template_addon` WHERE `entry` IN (61404, 61821, 61716);

DELETE FROM `creature_addon` WHERE `guid` IN (4000010, 4000118, 4000124, 4000015, 4000019);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(4000010, 0, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''),
(4000118, 0, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''),
(4000124, 0, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''),
(4000015, 0, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''),
(4000019, 0, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, '');

DELETE FROM `creature_static_flags_override` WHERE `SpawnId` IN (@CGUID+2, @CGUID+7) AND `DifficultyId`=0;
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(@CGUID+2, 0, 268435456, NULL, 0, NULL, NULL, NULL, NULL, NULL),
(@CGUID+7, 0, 268435456, NULL, 0, NULL, NULL, NULL, NULL, NULL);

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+7;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
-- Horde
(@CGUID+0, 61724, 389, 2437, 2437, '1', 0, 0, 0, 1, -299.520751953125, 221.1774749755859375, -25.1318569183349609, 3.087508440017700195, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54673), -- Commander Bagran (Area: Ragefire Chasm - Difficulty: Normal) CreateObject2
(@CGUID+1, 61404, 389, 2437, 2437, '1', 0, 0, 0, 1, -296.936126708984375, 223.105926513671875, -24.9686126708984375, 3.026282072067260742, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54673), -- Kor'kron Elite (Area: Ragefire Chasm - Difficulty: Normal) CreateObject2
(@CGUID+2, 61716, 389, 2437, 2437, '1', 0, 0, 0, 1, -299.498779296875, 215.7811431884765625, -25.4272956848144531, 2.846178770065307617, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54673), -- Invoker Xorenth (Area: Ragefire Chasm - Difficulty: Normal) CreateObject2
(@CGUID+3, 61404, 389, 2437, 2437, '1', 0, 0, 0, 1, -297.062896728515625, 218.29010009765625, -25.3582916259765625, 3.026282072067260742, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54673), -- Kor'kron Elite (Area: Ragefire Chasm - Difficulty: Normal) CreateObject2

-- Alliance
(@CGUID+4, 61821, 389, 2437, 2437, '1', 0, 0, 0, 1, -296.398834228515625, 221.740570068359375, -25.15625, 2.834229469299316406, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54717), -- SI:7 Commando (Area: Ragefire Chasm - Difficulty: Normal) CreateObject2
(@CGUID+5, 61821, 389, 2437, 2437, '1', 0, 0, 0, 1, -296.525543212890625, 216.924713134765625, -25.3940963745117187, 3.067924737930297851, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54717), -- SI:7 Commando (Area: Ragefire Chasm - Difficulty: Normal) CreateObject2
(@CGUID+6, 61822, 389, 2437, 2437, '1', 0, 0, 0, 1, -299.025115966796875, 219.8191070556640625, -25.3599357604980468, 2.975675582885742187, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54717), -- SI:7 Field Commander Dirken (Area: Ragefire Chasm - Difficulty: Normal) CreateObject2
(@CGUID+7, 61823, 389, 2437, 2437, '1', 0, 0, 0, 1, -299.02191162109375, 215.8939666748046875, -25.431009292602539, 2.871391773223876953, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 54717); -- High Sorceress Aryna (Area: Ragefire Chasm - Difficulty: Normal) CreateObject2

-- Spawn groups
DELETE FROM `spawn_group_template` WHERE `groupId` IN (@SPAWNGROUP+0, @SPAWNGROUP+1);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(@SPAWNGROUP+0, 'RFC - Alliance end dungeon spawns', 4),
(@SPAWNGROUP+1, 'RFC - Horde end dungeon spawns', 4);

DELETE FROM `spawn_group` WHERE `groupId` IN (@SPAWNGROUP+0, @SPAWNGROUP+1) AND `spawnType`=0;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(@SPAWNGROUP+0, 0, @CGUID+4),
(@SPAWNGROUP+0, 0, @CGUID+5),
(@SPAWNGROUP+0, 0, @CGUID+6),
(@SPAWNGROUP+0, 0, @CGUID+7),
(@SPAWNGROUP+1, 0, @CGUID+0),
(@SPAWNGROUP+1, 0, @CGUID+1),
(@SPAWNGROUP+1, 0, @CGUID+2),
(@SPAWNGROUP+1, 0, @CGUID+3);

DELETE FROM `instance_spawn_groups` WHERE `instanceMapId`=389 AND `bossStateId`=3;
INSERT INTO `instance_spawn_groups` (`instanceMapId`, `bossStateId`, `bossStates`, `spawnGroupId`, `flags`) VALUES
(389, 3, 0x08, @SPAWNGROUP+0, 0x05),
(389, 3, 0x08, @SPAWNGROUP+1, 0x09);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceGroup`=0 AND `SourceEntry` IN (@SPAWNGROUP+0, @SPAWNGROUP+1);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, @SPAWNGROUP+0, 0, 0, 11, 0, 6592, 1, 0, '', 0, 0, 0, '', 'RFC - Spawn Alliance NPCs if Lava Guard Gordoth encounter is done'),
(33, 0, @SPAWNGROUP+1, 0, 0, 11, 0, 6592, 1, 0, '', 0, 0, 0, '', 'RFC - Spawn Horde NPCs if Lava Guard Gordoth encounter is done');

DELETE FROM `creature_formations` WHERE `leaderGUID` IN (@CGUID+0, @CGUID+6);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+0, @CGUID+0, 0, 0, 512, 0, 0),
(@CGUID+0, @CGUID+1, 4, 45, 512, 0, 0),
(@CGUID+0, @CGUID+3, 4, 315, 512, 0, 0),
(@CGUID+6, @CGUID+6, 0, 0, 512, 0, 0),
(@CGUID+6, @CGUID+4, 4, 45, 512, 0, 0),
(@CGUID+6, @CGUID+5, 4, 315, 512, 0, 0);

-- Areatrigger
DELETE FROM `areatrigger_scripts` WHERE `entry`=7899;
INSERT INTO `areatrigger_scripts` (`entry`, `ScriptName`) VALUES
(7899, 'at_lava_guard_gordoth_intro');

-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-(@CGUID+0), -(@CGUID+6)) AND `source_type`= 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+0), 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 0, 6172400, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Commander Bagran - On Just Created - Self: Start waypoint 6172400'),
(-(@CGUID+6), 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 0, 6182200, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'SI:7 Field Commander Dirken - On Just Created - Self: Start waypoint 6182200');

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-(@CGUID+2), -(@CGUID+7)) AND `source_type`= 0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `action_param_string`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_param_string`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+2), 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 6171600, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Invoker Xorenth - On Just Created - Self: Start waypoint 6171600'),
(-(@CGUID+2), 0, 1, 0, '', 40, 0, 100, 0, 1, 6171600, 0, 0, 0, '', 90, 8, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'Invoker Xorenth - On Waypoint Reached - Self: Set StandState Kneel'),

(-(@CGUID+7), 0, 0, 0, '', 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 6182300, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'High Sorceress Aryna - On Just Created - Self: Start waypoint 6182300'),
(-(@CGUID+7), 0, 1, 0, '', 40, 0, 100, 0, 1, 6182300, 0, 0, 0, '', 90, 8, 0, 0, 0, 0, 0, 0, NULL, 1, 0, 0, 0, 0, NULL, 0, 0, 0, 0, 'High Sorceress Aryna - On Waypoint Reached - Self: Set Emotestate Kneel');

-- Waypoints
-- Horde
SET @ENTRY := 61724;
SET @PATH := @ENTRY * 100;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Commander Bagran - Lava Guard Gordoth encounter done Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -319.3589, 221.9741, -21.71945, NULL, 0),
(@PATH, 1, -326.1815, 221.1362, -20.62629, NULL, 0),
(@PATH, 2, -336.6703, 218.9815, -20.65222, NULL, 0);

SET @ENTRY := 61716;
SET @PATH := @ENTRY * 100;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Invoker Xorenth - Lava Guard Gordoth encounter done Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -326.3615, 217.6746, -20.42875, NULL, 0),
(@PATH, 1, -356.8222, 205.9922, -22.21798, NULL, 0);

UPDATE `creature` SET `MovementType`= 2 WHERE `guid`= @CGUID+2;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+2;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+2, @PATH, 1);

-- Alliance
SET @ENTRY := 61822;
SET @PATH := @ENTRY * 100;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'SI:7 Field Commander Dirken - Lava Guard Gordoth encounter done Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -319.3589, 221.9741, -21.71945, NULL, 0),
(@PATH, 1, -326.1815, 221.1362, -20.62629, NULL, 0),
(@PATH, 2, -336.6703, 218.9815, -20.65222, NULL, 0);

UPDATE `creature` SET `MovementType`= 2 WHERE `guid`= @CGUID+6;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+6;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+6, @PATH, 1);

SET @ENTRY := 61823;
SET @PATH := @ENTRY * 100;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'High Sorceress Aryna - Lava Guard Gordoth encounter done Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -326.3615, 217.6746, -20.42875, NULL, 0),
(@PATH, 1, -356.8222, 205.9922, -22.21798, NULL, 0);

UPDATE `creature` SET `MovementType`= 2 WHERE `guid`= @CGUID+7;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+7, @PATH, 1);

UPDATE `gameobject` SET `state`=1 WHERE `guid` IN(4000054, 4000055, 4000057);
