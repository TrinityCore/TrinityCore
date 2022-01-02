-- 
DELETE FROM `creature_template_movement` WHERE `CreatureId`IN (29259,28534,29047);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`) VALUES
(29259, 2, 1, 1, 0),
(28534, 2, 1, 1, 0),
(29047, 2, 1, 1, 0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (29259,28534);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`, `auras`) VALUES
(29259, 50397184, 1, '10848'),
(28534, 50397184, 1, '10848');

UPDATE `waypoint_data` SET `position_z`=159 WHERE `id` IN (1287390);
UPDATE `creature` SET `id`=29259, `position_x`=1887.429, `position_y`=-5776.158, `position_z`=106.6308, `orientation`=4.660029 WHERE `guid` IN (125672) AND `id`=6491;
UPDATE `creature` SET `id`=29259, `position_x`=2128.62, `position_y`=-5288.736, `position_z`=85.93806, `orientation`=3.176499 WHERE `guid` IN (125673) AND `id`=6491;
UPDATE `creature` SET `id`=29259, `position_x`=2372.552, `position_y`=-5774.20312, `position_z`=154.0692, `orientation`=3.353652 WHERE `guid` IN (125671) AND `id`=6491;
