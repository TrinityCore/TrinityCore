--
UPDATE `creature_template` SET `speed_walk` = 0.00399999991, `speed_run` = 0.00142857139, `unit_flags` = 33554432 WHERE `entry` = 17662;
UPDATE `creature_template` SET `speed_walk` = 0.00399999991, `speed_run` = 0.00142857139, `unit_flags` = 33554432 WHERE `entry` = 18602;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 0x00020000 WHERE `entry` IN (16211,31144,31146,32666,32667,33229,35176);

DELETE FROM `creature_template_addon` WHERE `entry` IN (16211,17662,18602,33229);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(16211, 0, 0, 0, 1, 0, 0, '7056'),
(17662, 0, 0, 0, 1, 0, 0, '19951 25900'),
(18602, 0, 0, 0, 1, 0, 0, '19951 25900'),
(33229, 0, 0, 0, 1, 0, 0, '7056');

UPDATE `creature_addon` SET `auras` = '7056 61573' WHERE `auras` = '61573' AND `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 31144);
UPDATE `creature_addon` SET `auras` = '7056 61574' WHERE `auras` = '61574' AND `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 31144);
UPDATE `creature_addon` SET `auras` = '7056 61573' WHERE `auras` = '61573' AND `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 31146);
UPDATE `creature_addon` SET `auras` = '7056 61574' WHERE `auras` = '61574' AND `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 31146);
UPDATE `creature_addon` SET `auras` = '7056 61573' WHERE `auras` = '61573' AND `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 32666);
UPDATE `creature_addon` SET `auras` = '7056 61574' WHERE `auras` = '61574' AND `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 32666);
UPDATE `creature_addon` SET `auras` = '7056 61573' WHERE `auras` = '61573' AND `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 32667);
UPDATE `creature_addon` SET `auras` = '7056 61574' WHERE `auras` = '61574' AND `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 32667);

UPDATE `creature_template` SET `unit_flags` = 33554432 WHERE `entry` IN (24722,25552);
UPDATE `creature_template_addon` SET `auras` = '25900' WHERE `entry` IN (24722,25552);

UPDATE `creature_template` SET `unit_flags` = 33588032 WHERE `entry` IN (24808,25546);
DELETE FROM `creature_template_addon` WHERE `entry` IN (25546);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(25546, 0, 0, 0, 1, 0, 0, '29266');

UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` IN (29672,29674,29676,32616,32617,32618,32619,32620,32621,32622,32623,32624,32625);
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (29672,29674,29676,32616,32617,32618,32619,32620,32621,32622,32623,32624,32625));
DELETE FROM `creature_template_addon` WHERE `entry` IN (29672,29674,29676,32616,32617,32618,32619,32620,32621,32622,32623,32624,32625);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(29672, 0, 0, 0, 1, 0, 0, '28782'),
(29674, 0, 0, 0, 1, 0, 0, '28782'),
(29676, 0, 0, 0, 1, 0, 0, '28782'),
(32616, 0, 0, 0, 1, 0, 0, '28782'),
(32617, 0, 0, 0, 1, 0, 0, '28782'),
(32618, 0, 0, 0, 1, 0, 0, '28782'),
(32619, 0, 0, 0, 1, 0, 0, '28782'),
(32620, 0, 0, 0, 1, 0, 0, '28782'),
(32621, 0, 0, 0, 1, 0, 0, '28782'),
(32622, 0, 0, 0, 1, 0, 0, '28782'),
(32623, 0, 0, 0, 1, 0, 0, '28782'),
(32624, 0, 0, 0, 1, 0, 0, '28782'),
(32625, 0, 0, 0, 1, 0, 0, '28782');

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 536870912, `unit_flags` = `unit_flags` &~ 262144, `dynamicflags` = `dynamicflags` &~ 32 WHERE `entry` IN (40626,40627,40628,40870);
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2147483648 WHERE `entry` IN (31841,31842);

UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2147483648, `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` IN (31012,31324);
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (31012));
DELETE FROM `creature_template_addon` WHERE `entry` IN (31012);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `visibilityDistanceType`, `auras`) VALUES
(31012, 0, 0, 50331657, 1, 0, 0, '58269');

UPDATE `creature_addon` SET `auras` = '5301 28782' WHERE `guid` = 85043;
UPDATE `creature_addon` SET `auras` = '28782' WHERE `guid` = 84994;
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2147483648, `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` IN (33479);

-- Guessed, they were sniffed in TBC but auras weren't added
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~ 2147483648, `unit_flags` = `unit_flags` &~ 262144 WHERE `entry` IN (26724,26738,26739,26740,26741,26742,26743,26744,26745,26747,26748,26749,26751,26752,26753,26754,26755,26756,26757,26758,26759,26765);
UPDATE `creature_template_addon` SET `auras` = '28782' WHERE `entry` IN (26724,26738,26739,26740,26741,26742,26743,26744,26745,26747,26748,26749,26751,26752,26753,26754,26755,26756,26757,26758,26759,26765);
