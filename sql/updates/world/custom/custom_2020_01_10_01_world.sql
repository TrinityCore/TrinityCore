-- Pathing for  Entry: 3877 'TDB FORMAT' 
SET @NPC := 371034;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`= 0, `MovementType`= 2, `position_x`= -250.569, `position_y`= 2180.54, `position_z`= 94.13151 WHERE `guid`= @NPC;
DELETE FROM `creature_addon` WHERE `guid`= @NPC;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES (@NPC, @PATH, 0, 0, 1, 0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH, 1, -250.569, 2180.54, 94.13151, 0, 0, 0, 0, 100, 0),
(@PATH, 2, -253.447, 2164.11, 94.1315, 0, 0, 0, 0, 100, 0),
(@PATH, 3, -253.467, 2160.45, 94.01281, 0, 0, 0, 0, 100, 0),
(@PATH, 4, -245.95, 2158.8, 92.57565, 0, 0, 0, 0, 100, 0),
(@PATH, 5, -248.748, 2151.16, 91.11265, 0, 0, 0, 0, 100, 0),
(@PATH, 6, -253.988, 2152.38, 91.13149, 0, 0, 0, 0, 100, 0),
(@PATH, 7, -261.921, 2148.34, 94.08473, 0, 0, 0, 0, 100, 0),
(@PATH, 8, -266.539, 2151.69, 95.78161, 0, 0, 0, 0, 100, 0),
(@PATH, 9, -269.817, 2142.98, 96.047, 0, 0, 0, 0, 100, 0),
(@PATH, 10, -266.539, 2151.69, 95.78161, 0, 0, 0, 0, 100, 0),
(@PATH, 11, -261.921, 2148.34, 94.08473, 0, 0, 0, 0, 100, 0),
(@PATH, 12, -253.988, 2152.38, 91.13149, 0, 0, 0, 0, 100, 0),
(@PATH, 13, -248.748, 2151.16, 91.11265, 0, 0, 0, 0, 100, 0),
(@PATH, 14, -245.95, 2158.8, 92.57565, 0, 0, 0, 0, 100, 0),
(@PATH, 15, -253.467, 2160.45, 94.01281, 0, 0, 0, 0, 100, 0),
(@PATH, 16, -253.447, 2164.11, 94.1315, 0, 0, 0, 0, 100, 0);
-- 0x203094042003C9400071740004CB9BCD .go xyz -250.569 2180.54 94.13151
