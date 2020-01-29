-- Northshire Peasant emote states
UPDATE `creature_template_addon` SET `emote`= 234 WHERE `entry`= 11260;

-- Creature Lien Farner 47384 SAI
SET @ENTRY := 47384;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 7000, 11000, 7000, 11000, 10, 273, 273, 273, 396, 6, 274, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 7000 and 11000 ms (and later repeats every 7000 and 11000 ms) - Self: Play random emote: ONESHOT_YES(DNR) (273), ONESHOT_YES(DNR) (273), ONESHOT_YES(DNR) (273), ONESHOT_TALK_NOSHEATHE (396), ONESHOT_QUESTION (6), ONESHOT_NO(DNR) (274) // ");

-- Creature Tharynn Bouden 66 SAI
SET @ENTRY := 66;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 6000, 11000, 6000, 11000, 10, 274, 273, 6, 396, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "When out of combat and timer at the begining between 6000 and 11000 ms (and later repeats every 6000 and 11000 ms) - Self: Play random emote: ONESHOT_NO(DNR) (274), ONESHOT_YES(DNR) (273), ONESHOT_QUESTION (6), ONESHOT_TALK_NOSHEATHE (396),  // ");

-- Pathing for  Entry: 1975 'TDB FORMAT' 
SET @NPC := 281135;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -9416.485, `position_y`= -1331.1586, `position_z`= 51.53237 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -9416.485, -1331.1586, 51.53237, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -9421.154, -1326.5717, 51.663944, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -9425.933, -1324.0469, 51.53237, 0, 12659, 0, 0, 100, 0),
(@PATH, 4, -9417.531, -1330.5028, 51.53237, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -9412.813, -1334.5887, 51.53238, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -9408.221, -1337.9055, 50.1282, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -9400.745, -1336.9156, 50.132378, 0, 16957, 0, 0, 100, 0),
(@PATH, 8, -9416.485, -1331.1586, 51.53237, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -9421.154, -1326.5717, 51.663944, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -9425.933, -1324.0469, 51.53237, 0, 12607, 0, 0, 100, 0),
(@PATH, 11, -9417.531, -1330.5028, 51.53237, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -9412.813, -1334.5887, 51.53238, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -9408.221, -1337.9055, 50.1282, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -9400.745, -1336.9156, 50.132378, 0, 24325, 0, 0, 100, 0),
(@PATH, 15, -9416.485, -1331.1586, 51.53237, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -9421.154, -1326.5717, 51.663944, 0, 0, 0, 0, 100, 0),
(@PATH, 17, -9425.933, -1324.0469, 51.53237, 0, 15063, 0, 0, 100, 0),
(@PATH, 18, -9417.531, -1330.5028, 51.53237, 0, 0, 0, 0, 100, 0),
(@PATH, 19, -9412.813, -1334.5887, 51.53238, 0, 0, 0, 0, 100, 0),
(@PATH, 20, -9408.221, -1337.9055, 50.1282, 0, 0, 0, 0, 100, 0),
(@PATH, 21, -9400.745, -1336.9156, 50.132378, 0, 16914, 0, 0, 100, 0),
(@PATH, 22, -9416.485, -1331.1586, 51.53237, 0, 0, 0, 0, 100, 0),
(@PATH, 23, -9421.154, -1326.5717, 51.663944, 0, 0, 0, 0, 100, 0),
(@PATH, 24, -9425.933, -1324.0469, 51.53237, 0, 15157, 0, 0, 100, 0),
(@PATH, 25, -9417.531, -1330.5028, 51.53237, 0, 0, 0, 0, 100, 0),
(@PATH, 26, -9412.813, -1334.5887, 51.53238, 0, 0, 0, 0, 100, 0),
(@PATH, 27, -9408.221, -1337.9055, 50.1282, 0, 0, 0, 0, 100, 0),
(@PATH, 28, -9400.745, -1336.9156, 50.132378, 0, 18172, 0, 0, 100, 0),
(@PATH, 29, -9404.866, -1339.135, 50.17714, 0, 0, 0, 0, 100, 0),
(@PATH, 30, -9409.12, -1338.372, 50.149223, 0, 0, 0, 0, 100, 0),
(@PATH, 31, -9411.633, -1336.6923, 50.998768, 0, 0, 0, 0, 100, 0);
-- 0x203AF0000001EDC000000300014FE397 .go xyz -9416.485 -1331.1586 51.53237

-- Pathing for  Entry: 802 'TDB FORMAT' 
SET @NPC := 281147;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -9480.154, `position_y`= -1311.3298, `position_z`= 41.851837 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -9480.154, -1311.3298, 41.851837, 0, 24203, 0, 0, 100, 0),
(@PATH, 2, -9472.406, -1337.1412, 44.007977, 0, 24281, 0, 0, 100, 0);
-- 0x203AF0000000C88000000300004FFC2C .go xyz -9480.154 -1311.3298 41.851837

-- Pathing for  Entry: 801 'TDB FORMAT' 
SET @NPC := 281148;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -9480.765, `position_y`= -1317.8301, `position_z`= 41.210686 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -9480.765, -1317.8301, 41.210686, 0, 24234, 0, 0, 100, 0),
(@PATH, 2, -9473.375, -1332.4625, 42.71877, 0, 24313, 0, 0, 100, 0);
-- 0x203AF0000000C84000000300004FFC2C .go xyz -9480.765 -1317.8301 41.210686

UPDATE `creature` SET `MovementType`= 1, `spawndist`= 3 WHERE `guid` IN (281134, 281136);
