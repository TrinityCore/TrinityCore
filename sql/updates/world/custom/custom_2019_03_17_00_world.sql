-- Pathing for  Entry: 54 'TDB FORMAT' 
SET @NPC := 280684;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -9464.4, `position_y`= 94.0174, `position_z`= 58.54224 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -9464.4, 94.0174, 58.54224, 3.159046, 12375, 0, 0, 100, 0),
(@PATH, 2, -9464.4, 94.0174, 58.54224, 0.03490658, 29250, 0, 0, 100, 0),
(@PATH, 3, -9460.3, 101.247, 58.47567, 0, 236, 0, 0, 100, 0),
(@PATH, 4, -9460.3, 101.247, 58.47567, 1.054814, 12250, 0, 0, 100, 0),
(@PATH, 5, -9464.4, 94.0174, 58.54224, 0, 284, 0, 0, 100, 0),
(@PATH, 6, -9464.4, 94.0174, 58.54224, 0.03490658, 21922, 0, 0, 100, 0);
-- 0x203CC80000000D80003C9800004BA8CF .go xyz -9464.4 94.0174 58.54224

-- Pathing for  Entry: 2046 'TDB FORMAT' 
SET @NPC := 280686;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -9464.06, `position_y`= 88.934, `position_z`= 58.53813 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -9464.06, 88.934, 58.53813, 2.373648, 12468, 0, 0, 100, 0),
(@PATH, 2, -9464.16, 87.8281, 58.53032, 0, 462, 0, 0, 100, 0),
(@PATH, 3, -9464.16, 87.8281, 58.53032, 0.2268928, 31906, 0, 0, 100, 0),
(@PATH, 4, -9464.06, 88.934, 58.53813, 0, 383, 0, 0, 100, 0);
-- 0x203CC8000001FF80003C9800004B7B8D .go xyz -9464.06 88.934 58.53813

-- Creature Andrew Krighton 2046 SAI
SET @ENTRY := 2046;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`= @ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 1, 40, 0, 100, 0, 1, 0, 0, 0, 17, 233, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On wapoint 1 of any path reached - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 233 // "),
(@ENTRY, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 67, 0, 10000, 10000, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, " Linked - Trigger timed event #0 in 10000 - 10000 ms // "),
(@ENTRY, 0, 2, 0, 59, 0, 100, 0, 0, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "On timed event 0 triggered - Self: Set emote state (UNIT_NPC_EMOTESTATE) to 0 // ");
