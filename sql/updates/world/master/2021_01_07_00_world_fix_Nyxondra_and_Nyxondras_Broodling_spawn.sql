-- Set Panda Turtle not hover
UPDATE `creature_template_addon` SET `bytes1` = '0' WHERE `entry` = '65058';
UPDATE `creature_template_addon` SET `bytes1` = '0' WHERE `entry` = '65061';
UPDATE `creature_template_addon` SET `bytes1` = '0' WHERE `entry` = '65060';
-- Fix Spawn Nyxondras Broodling
DELETE FROM `creature` WHERE (`id` = 46916) AND (`guid` IN (162236, 162237, 162243, 162244, 162245, 162247, 162248, 162250, 162253, 162257, 162314, 162315, 162316, 162317, 162472, 162479, 162496, 162499, 162518, 162523, 162533, 162548, 162551, 162586, 162592, 162851, 162853, 162855));
-- Multi Spawn Nyxondra
DELETE FROM `creature` WHERE (`id` = 46861) AND (`guid` IN (162475, 162527, 162560, 162845));
UPDATE `creature_template` SET `InhabitType` = '4' WHERE `entry` = '46861';
DELETE FROM `creature_addon` WHERE (`guid` IN (162308));
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(162308, 162308, 0, 33554432, 1, 444, 0, 0, 0, 0, NULL);
DELETE FROM `waypoint_data` WHERE (`id` IN (162308));
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (162308, 1, -6612.71, -2160.22, 304.515, 0, 0, 2, 0, 100, 3530000000003058);
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (162308, 2, -6592.37, -2206.12, 296.82, 0, 0, 2, 0, 100, 3530000000003059);
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (162308, 3, -6601.16, -2248.53, 291.828, 0, 0, 2, 0, 100, 3530000000003060);
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (162308, 4, -6631.42, -2245.22, 295.589, 0, 0, 2, 0, 100, 3530000000003061);
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (162308, 5, -6686.37, -2223.88, 303.348, 0, 0, 2, 0, 100, 3530000000003062);
INSERT INTO `waypoint_data`(`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES (162308, 6, -6708.36, -2156.62, 302.257, 0, 0, 2, 0, 100, 3530000000003063);