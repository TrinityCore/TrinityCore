-- Template Updates
UPDATE `creature_template` SET `dynamicflags`= 0, `unit_flags`= 64, `unit_flags2`= 2048 WHERE `entry` IN (48439, 48280);
UPDATE `creature` SET `dynamicflags`= 0, `unit_flags`= 0x00040000 | 0x02000000 WHERE `guid` IN (375819, 375821, 375822, 375825, 375826, 375900, 375901, 375903, 375908, 375909, 375965, 375966, 375968, 375969, 375970, 376020, 376025, 376026, 376027, 376095, 376096, 376102, 376103);

-- Spawns
DELETE FROM `creature` WHERE `guid` IN (376095, 376096, 376103, 376102);
DELETE FROM `creature_addon` WHERE `guid` IN (376095, 376096, 376103, 376102);

SET @CGUID := 395092;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 48280, 36, 1581, 0, 3, 169, 0, 0, 0, -234.0347, -587.6945, 51.32703, 1.64061, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Craftsman (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+1, 48280, 36, 1581, 0, 3, 169, 0, 0, 0, -212.6719, -550.0243, 51.31293, 3.787364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Craftsman (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+2, 48439, 36, 1581, 0, 3, 169, 0, 0, 0, -207.7934, -550.9514, 51.31293, 3.525565, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- Goblin Engineer (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)
(@CGUID+3, 48439, 36, 1581, 0, 3, 169, 0, 0, 0, -225.4444, -566.316, 51.31293, 3.961897, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- Goblin Engineer (Area: 0 - Difficulty: 0) (Auras: 78087 - Cosmetic - Cower (Upper Body) Anim Kit) (possible waypoints or random movement)

-- Addons
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3;
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(@CGUID+0, '78087'),
(@CGUID+1, '78087'),
(@CGUID+2, '78087'),
(@CGUID+3, '78087');

-- Spawn Group
DELETE FROM `spawn_group_template` WHERE `groupId`= 411;
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(411, 'The Deadmines - Goblin Event', 4);

DELETE FROM `spawn_group` WHERE `groupId`= 411;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(411, 0, @CGUID+0),
(411, 0, @CGUID+1),
(411, 0, @CGUID+2),
(411, 0, @CGUID+3);

-- Pathing for  Entry: 48439 'TDB FORMAT' 
SET @NPC := 48439;
SET @PATH := @NPC * 10;
DELETE FROM `waypoints` WHERE `entry`=@PATH;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@PATH, 1, -235.3973, -578.3387, 51.22309, 'Goblin Engineer'),
(@PATH, 2, -263.34, -578.0696, 50.60181, 'Goblin Engineer'),
(@PATH, 3, -270.181, -581.222, 49.80238, 'Goblin Engineer'),
(@PATH, 4, -274.22, -589.346, 50.73989, 'Goblin Engineer'),
(@PATH, 5, -282.41, -598.974, 50.23107, 'Goblin Engineer'),
(@PATH, 6, -294.247, -603.863, 47.59248, 'Goblin Engineer'),
(@PATH, 7, -300.056, -602.877, 47.76314, 'Goblin Engineer'),
(@PATH, 8, -308.102, -592.106, 47.84224, 'Goblin Engineer'),
(@PATH, 9, -302.649, -582.62, 47.66353, 'Goblin Engineer'),
(@PATH, 10, -295.884, -569.358, 48.47172, 'Goblin Engineer'),
(@PATH, 11, -292.951, -559.064, 48.92119, 'Goblin Engineer'),
(@PATH, 12, -291.146, -543.854, 49.43869, 'Goblin Engineer'),
(@PATH, 13, -290.2934, -529.8975, 49.53617, 'Goblin Engineer'),
(@PATH, 14, -290.212, -512.45, 49.84246, 'Goblin Engineer'),
(@PATH, 15, -291.21, -499.033, 50.27398, 'Goblin Engineer'),
(@PATH, 16, -290.438, -489.743, 49.99445, 'Goblin Engineer'),
(@PATH, 17, -286.747, -487.845, 49.96106, 'Goblin Engineer'),
(@PATH, 18, -278.252, -485.319, 48.83867, 'Goblin Engineer'),
(@PATH, 19, -273.8264, -477.7031, 49.24369, 'Goblin Engineer');
-- 0x20208C04802F4DC00005A700002F3EFD .go xyz -263.34 -578.0696 50.60181

-- Pathing for  Entry: 48439 'TDB FORMAT' 
SET @NPC := 48439;
SET @PATH := @NPC * 10 + 1;
DELETE FROM `waypoints` WHERE `entry`=@PATH;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@PATH, 1, -234.6187, -577.6969, 51.22667, 'Goblin Engineer'),
(@PATH, 2, -249.611, -578.644, 51.1494, 'Goblin Engineer'),
(@PATH, 3, -263.34, -578.0696, 50.60181, 'Goblin Engineer'),
(@PATH, 4, -270.181, -581.222, 49.80238, 'Goblin Engineer'),
(@PATH, 5, -274.22, -589.346, 50.73989, 'Goblin Engineer'),
(@PATH, 6, -282.41, -598.974, 50.23107, 'Goblin Engineer'),
(@PATH, 7, -294.247, -603.863, 47.59248, 'Goblin Engineer'),
(@PATH, 8, -300.056, -602.877, 47.76314, 'Goblin Engineer'),
(@PATH, 9, -308.102, -592.106, 47.84224, 'Goblin Engineer'),
(@PATH, 10, -302.649, -582.62, 47.66353, 'Goblin Engineer'),
(@PATH, 11, -295.884, -569.358, 48.47172, 'Goblin Engineer'),
(@PATH, 12, -292.951, -559.064, 48.92119, 'Goblin Engineer'),
(@PATH, 13, -291.146, -543.854, 49.43869, 'Goblin Engineer'),
(@PATH, 14, -290.2934, -529.8975, 49.53617, 'Goblin Engineer'),
(@PATH, 15, -290.212, -512.45, 49.84246, 'Goblin Engineer'),
(@PATH, 16, -291.21, -499.033, 50.27398, 'Goblin Engineer'),
(@PATH, 17, -290.438, -489.743, 49.99445, 'Goblin Engineer'),
(@PATH, 18, -286.747, -487.845, 49.96106, 'Goblin Engineer'),
(@PATH, 19, -278.252, -485.319, 48.83867, 'Goblin Engineer'),
(@PATH, 20, -277.722, -495.944, 49.69218, 'Goblin Engineer');
-- 0x20208C04802F4DC00005A70000AF3EFD .go xyz -234.6187 -577.6969 51.22667

-- Pathing for  Entry: 48280 'TDB FORMAT' 
SET @NPC := 48280;
SET @PATH := @NPC * 10;
DELETE FROM `waypoints` WHERE `entry`=@PATH;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@PATH, 1, -235.8079, -580.0833, 51.22581, 'Goblin Craftsman'),
(@PATH, 2, -263.34, -578.0696, 50.60181, 'Goblin Craftsman'),
(@PATH, 3, -270.181, -581.222, 49.80238, 'Goblin Craftsman'),
(@PATH, 4, -274.22, -589.346, 50.73989, 'Goblin Craftsman'),
(@PATH, 5, -282.41, -598.974, 50.23107, 'Goblin Craftsman'),
(@PATH, 6, -294.247, -603.863, 47.59248, 'Goblin Craftsman'),
(@PATH, 7, -300.056, -602.877, 47.76314, 'Goblin Craftsman'),
(@PATH, 8, -308.102, -592.106, 47.84224, 'Goblin Craftsman'),
(@PATH, 9, -302.649, -582.62, 47.66353, 'Goblin Craftsman'),
(@PATH, 10, -295.884, -569.358, 48.47172, 'Goblin Craftsman'),
(@PATH, 11, -292.951, -559.064, 48.92119, 'Goblin Craftsman'),
(@PATH, 12, -291.146, -543.854, 49.43869, 'Goblin Craftsman'),
(@PATH, 13, -290.2934, -529.8975, 49.53617, 'Goblin Craftsman'),
(@PATH, 14, -290.212, -512.45, 49.84246, 'Goblin Craftsman'),
(@PATH, 15, -291.21, -499.033, 50.27398, 'Goblin Craftsman'),
(@PATH, 16, -290.438, -489.743, 49.99445, 'Goblin Craftsman'),
(@PATH, 17, -286.747, -487.845, 49.96106, 'Goblin Craftsman'),
(@PATH, 18, -278.252, -485.319, 48.83867, 'Goblin Craftsman'),
(@PATH, 19, -283.125, -478.1354, 49.10189, 'Goblin Craftsman');
-- 0x20208C04802F26000005A700002F3EFD .go xyz -235.8079 -580.0833 51.22581

-- Pathing for  Entry: 48280 'TDB FORMAT' 
SET @NPC := 48280;
SET @PATH := @NPC * 10 + 1;
DELETE FROM `waypoints` WHERE `entry`=@PATH;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@PATH, 1, -236.035, -579.109, 51.22141, 'Goblin Craftsman'),
(@PATH, 2, -263.34, -578.0696, 50.60181, 'Goblin Craftsman'),
(@PATH, 3, -270.181, -581.222, 49.80238, 'Goblin Craftsman'),
(@PATH, 4, -274.22, -589.346, 50.73989, 'Goblin Craftsman'),
(@PATH, 5, -282.41, -598.974, 50.23107, 'Goblin Craftsman'),
(@PATH, 6, -294.247, -603.863, 47.59248, 'Goblin Craftsman'),
(@PATH, 7, -308.102, -592.106, 47.84224, 'Goblin Craftsman'),
(@PATH, 8, -302.649, -582.62, 47.66353, 'Goblin Craftsman'),
(@PATH, 9, -295.884, -569.358, 48.47172, 'Goblin Craftsman'),
(@PATH, 10, -292.951, -559.064, 48.92119, 'Goblin Craftsman'),
(@PATH, 11, -291.146, -543.854, 49.43869, 'Goblin Craftsman'),
(@PATH, 12, -290.2934, -529.8975, 49.53617, 'Goblin Craftsman'),
(@PATH, 13, -290.212, -512.45, 49.84246, 'Goblin Craftsman'),
(@PATH, 14, -291.21, -499.033, 50.27398, 'Goblin Craftsman'),
(@PATH, 15, -290.438, -489.743, 49.99445, 'Goblin Craftsman'),
(@PATH, 16, -278.252, -485.319, 48.83867, 'Goblin Craftsman'),
(@PATH, 17, -272.104, -488.595, 49.31833, 'Goblin Craftsman');
-- 0x20208C04802F26000005A70000AF3EFD .go xyz -263.34 -578.0696 50.60181

DELETE FROM `creature_text` WHERE `CreatureID` IN (48280, 48439);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(48280, 0, 0, 'They\'re alive...', 12, 0, 100, 0, 0, 0, 48475, 'Goblin Craftsman to Player'),
(48280, 1, 0, 'THEY\'RE ALIVE!!!', 14, 0, 100, 0, 0, 0, 48476, 'Goblin Craftsman to Player'),
(48280, 2, 0, 'NOOOOOOO!!!', 14, 0, 100, 0, 0, 0, 48478, 'Goblin Craftsman to Player'),
(48439, 0, 0, 'RUN!', 14, 0, 100, 0, 0, 0, 48477, 'Goblin Engineer to Player');

-- Gameobject Heavy Door 17154 SAI
SET @ENTRY := 17154;
UPDATE `gameobject_template` SET `AIName`="SmartGameObjectAI" WHERE `entry`= @ENTRY;
SET @ENTRY := -235345;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=1;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 1, 0, 0, 70, 0, 100, 0, 2, 0, 0, 0, 34, 8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On GoState changed to GO_STATE_ACTIVE - Set instance data #8 to 0 // ");

-- Creature Goblin Craftsman 48280 SAI
SET @ENTRY := 48280;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
SET @ENTRY := -395092;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 800, 800, 0, 0, 53, 1, 482800, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 800 and 800 ms) - Self: Start path #482800, run, do not repeat, Passive // "),
(@ENTRY, 0, 1, 0, 40, 0, 100, 0, 1, 482800, 0, 0, 80, 4828000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 1 of path 482800 reached - Start timed action list id #4828000 // "),
(@ENTRY, 0, 2, 3, 8, 0, 100, 0, 48348, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On spell Emote Talk Exclamation (48348) hit  - Self: Talk 1 // "),
(@ENTRY, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 8, 0, 0, 0, 0, 0, 0, 6.26573, " Linked - Self: Look at (0, 0, 0, 6.26573) // "),
(@ENTRY, 0, 4, 0, 40, 0, 100, 0, 19, 482800, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 19 of path 482800 reached - Self: Despawn in 1000 ms // ");

-- TimedActionList  4828000 SAI
SET @ENTRY := 4828000;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 54, 5000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Self: Pause path for 5000 ms // "),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 500, 500, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Self: Talk 0 // "),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 2200, 2200, 0, 0, 11, 48348, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Self: Cast spell Emote Talk Exclamation (48348) on Self // ");

-- Creature Goblin Craftsman 48280 SAI
SET @ENTRY := -395093;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 800, 800, 0, 0, 53, 1, 482801, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 800 and 800 ms) - Self: Start path #482801, run, do not repeat, Passive // "),
(@ENTRY, 0, 1, 0, 40, 0, 100, 0, 1, 482801, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 1 of path 482801 reached - Self: Talk 2 // "),
(@ENTRY, 0, 2, 0, 40, 0, 100, 0, 17, 482801, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 17 of path 482801 reached - Self: Despawn in 1000 ms // ");

-- Creature Goblin Engineer 48439 SAI
SET @ENTRY := 48439;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
SET @ENTRY := -395094;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 2000, 2000, 0, 0, 53, 1, 484391, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 2000 and 2000 ms) - Self: Start path #484390, run, do not repeat, Passive // "),
(@ENTRY, 0, 1, 0, 58, 0, 100, 0, 0, 0, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On any waypoint of any path ended - Self: Despawn in 1000 ms // "),
(@ENTRY, 0, 2, 0, 40, 0, 100, 0, 20, 484391, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 20 of path 484391 reached - Self: Despawn in 1000 ms // ");

-- Creature Goblin Engineer 48439 SAI
SET @ENTRY := -395095;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 60, 0, 100, 1, 2000, 2000, 0, 0, 53, 1, 484390, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Every 0 and 0 ms (for the first time, timer between 2000 and 2000 ms) - Self: Start path #484390, run, do not repeat, Passive // "),
(@ENTRY, 0, 1, 0, 40, 0, 100, 0, 1, 484390, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 1 of path 484390 reached - Self: Talk 0 // "),
(@ENTRY, 0, 2, 0, 40, 0, 100, 0, 19, 484390, 0, 0, 41, 1000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 19 of path 484390 reached - Self: Despawn in 1000 ms // ");

