-- Pathing for  Entry: 46614 'TDB FORMAT' 
SET @NPC := 376217;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -49.7743, `position_y`= -399.486, `position_z`= 55.6161 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -49.7743, -399.486, 55.6161, 0, 29912, 0, 0, 100, 0),
(@PATH, 2, -67.6667, -391.125, 53.8092, 0, 30312, 0, 0, 100, 0);
-- 0x20208C04802D85800005A70000AF3C40 .go xyz -49.7743 -399.486 55.6161

-- Pathing for  Entry: 46614 'TDB FORMAT' 
SET @NPC := 376216;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -60.68924, `position_y`= -370.1962, `position_z`= 55.10924 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -60.68924, -370.1962, 55.10924, 0, 14134, 0, 0, 100, 0),
(@PATH, 2, -65.22569, -352.5451, 55.41314, 0, 19720, 0, 0, 100, 0);
-- 0x20208C04802D85800005A700012F3C40 .go xyz -60.68924 -370.1962 55.10924


-- Pathing for  Entry: 48230 'TDB FORMAT' 
SET @NPC := 375932;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -92.8507, `position_y`= -402.977, `position_z`= 57.69406 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -92.8507, -402.977, 57.69406, 0, 10785, 0, 0, 100, 0),
(@PATH, 2, -97.6146, -398.762, 58.3701, 0, 257, 0, 0, 100, 0),
(@PATH, 3, -97.6146, -398.762, 58.3701, 2.75762, 10562, 0, 0, 100, 0);
-- 0x24208C04802F19800005A700002F3C40 .go xyz -92.8507 -402.977 57.69406

-- Pathing for  Entry: 48230 'TDB FORMAT' 
SET @NPC := 375855;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -108.347, `position_y`= -436.047, `position_z`= 55.08241 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -108.347, -436.047, 55.08241, 0, 13666, 0, 0, 100, 0),
(@PATH, 2, -115.373, -431.387, 54.99337, 0, 277, 0, 0, 100, 0),
(@PATH, 3, -115.373, -431.387, 54.99337, 3.595378, 9734, 0, 0, 100, 0);
-- 0x24208C04802F19800005A70000AF3C41 .go xyz -108.347 -436.047 55.08241

-- Pathing for  Entry: 48230 'TDB FORMAT' 
SET @NPC := 375929;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -134.064, `position_y`= -411.809, `position_z`= 58.06636 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -134.064, -411.809, 58.06636, 0, 11997, 0, 0, 100, 0),
(@PATH, 2, -135.875, -405.545, 58.063, 0, 232, 0, 0, 100, 0),
(@PATH, 3, -135.875, -405.545, 58.063, 2.984513, 10563, 0, 0, 100, 0);
-- 0x24208C04802F19800005A700012F3C40 .go xyz -134.064 -411.809 58.06636

-- Pathing for  Entry: 48338 'TDB FORMAT' 
SET @NPC := 376078;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -193.28, `position_y`= -501.571, `position_z`= 52.90603 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '89842');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -193.28, -501.571, 52.90603, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -199.88, -506.075, 53.03196, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -205.932, -505.509, 51.93827, 0, 285, 0, 0, 100, 0),
(@PATH, 4, -199.88, -506.075, 53.03196, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -193.28, -501.571, 52.90603, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -188.422, -498.592, 53.21219, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -186.297, -490.74, 53.54514, 0, 188, 0, 0, 100, 0),
(@PATH, 8, -188.422, -498.592, 53.21219, 0, 0, 0, 0, 100, 0);
-- 0x24208C04802F34800005A700002F3C41 .go xyz -193.28 -501.571 52.90603

-- Pathing for  Entry: 48521 'TDB FORMAT' 
SET @NPC := 375881;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -81.6823, `position_y`= -780.378, `position_z`= 17.3339 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -81.6823, -780.378, 17.3339, 0, 6726, 0, 0, 100, 0),
(@PATH, 2, -50.2274, -781.837, 18.2862, 0, 6800, 0, 0, 100, 0);
-- 0x20208C04802F62400005A700002F3C42 .go xyz -81.6823 -780.378 17.3339

-- Pathing for  Entry: 48521 'TDB FORMAT' 
SET @NPC := 376084;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -42.7743, `position_y`= -784.259, `position_z`= 18.5858 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -42.7743, -784.259, 18.5858, 0, 5778, 0, 0, 100, 0),
(@PATH, 2, -32.9757, -790.03, 19.0157, 0, 8079, 0, 0, 100, 0);
-- 0x20208C04802F62400005A70000AF3C42 .go xyz -42.7743 -784.259 18.5858

-- Pathing for  Entry: 48521 'TDB FORMAT' 
SET @NPC := 375949;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -77.7309, `position_y`= -785.984, `position_z`= 38.9725 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -77.7309, -785.984, 38.9725, 0, 7214, 0, 0, 100, 0),
(@PATH, 2, -43.191, -791.116, 39.3433, 0, 10787, 0, 0, 100, 0);
-- 0x20208C04802F62400005A700042F3C42 .go xyz -77.7309 -785.984 38.9725

-- Remove wrong waypoints from Admiral Ripsnarl
DELETE FROM `waypoint_data` WHERE `id`= 3758540;
UPDATE `creature_addon` SET `path_id`= 0 WHERE `guid`= 375854;
UPDATE `creature` SET `position_x` = -66.7813, `position_y`= -837.863, `position_z`= 41.06303, `orientation`= 4.607669, `MovementType`= 0 WHERE `guid`= 375854;

-- Pathing for  Entry: 48351 'TDB FORMAT' 
SET @NPC := 375935;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -210.615, `position_y`= -502.825, `position_z`= 51.33048 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '89842');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -210.615, -502.825, 51.33048, 0, 382, 0, 0, 100, 0),
(@PATH, 2, -216.122, -499.132, 49.54227, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -220.618, -494.74, 48.24886, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -223.776, -491.035, 48.14802, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -227.307, -488.517, 48.42067, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -231.358, -484.927, 48.83553, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -234.658, -482.764, 49.08449, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -239.748, -482.29, 48.99, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -243.995, -482.948, 48.81551, 0, 28, 0, 0, 100, 0),
(@PATH, 10, -234.658, -482.764, 49.08449, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -231.358, -484.927, 48.83553, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -227.307, -488.517, 48.42067, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -223.776, -491.035, 48.14802, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -220.618, -494.74, 48.24886, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -216.122, -499.132, 49.54227, 0, 0, 0, 0, 100, 0);
-- 0x24208C04802F37C00005A700002F3C41 .go xyz -210.615 -502.825 51.33048

-- Correct Oaf Lackey positions
UPDATE `creature` SET `position_x` = -278.099, `position_y`= -502.125, `position_z`= 49.74713, `orientation`= 3.246312 WHERE `guid`= 376239;
UPDATE `creature` SET `position_x` = -300.974, `position_y`= -504.708, `position_z`= 49.47263, `orientation`= 6.161012 WHERE `guid`= 376238;

SET @CGUID := 395105;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 48445, 36, 0, 0, 2, 169, 0, 0, 0, -258.4514, -482.1701, 49.53112, 6.195919, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 48445 (Area: -1 - Difficulty: 0) (Auras: )
(@CGUID+1, 48445, 36, 0, 0, 2, 169, 0, 0, 0, -289.375, -501.9254, 50.2008, 4.607669, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 48445 (Area: -1 - Difficulty: 0) (Auras: )
(@CGUID+2, 48445, 36, 0, 0, 2, 169, 0, 0, 0, -289.2934, -505.3385, 50.09231, 1.53589, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 48445 (Area: -1 - Difficulty: 0) (Auras: )

-- Move Oaf Lackeys to their difficulty
UPDATE `creature` SET `spawnMask`= 1 WHERE `guid` IN (375998, 375934, 375867, 376035, 376238, 376239);

DELETE FROM `waypoint_data` WHERE `id`= 3760560;
DELETE FROM `creature_addon` WHERE `guid`= 376056;
DELETE FROM `creature` WHERE `guid`= 376056;
