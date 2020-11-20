UPDATE `quest_details` SET `Emote1`= 1, `Emote2`= 1, `Emote3`= 1, `Emote4`= 1 WHERE `ID`= 12619;
UPDATE `quest_details` SET `Emote1`= 1, `Emote2`= 1, `Emote3`= 1, `Emote4`= 0 WHERE `ID`= 12842;
UPDATE `quest_details` SET `Emote1`= 1, `Emote2`= 1, `Emote3`= 1, `Emote4`= 25 WHERE `ID`= 12848;
UPDATE `quest_details` SET `Emote1`= 1, `Emote2`= 1, `Emote3`= 1, `Emote4`= 1 WHERE `ID`= 12636;
UPDATE `quest_details` SET `Emote1`= 396, `Emote2`= 397, `Emote3`= 396, `Emote4`= 0 WHERE `ID`= 12641;
UPDATE `quest_details` SET `Emote1`= 6, `Emote2`= 1, `Emote3`= 1, `Emote4`= 66 WHERE `ID`= 12670;
UPDATE `quest_details` SET `Emote1`= 1, `Emote2`= 1, `Emote3`= 1, `Emote4`= 5 WHERE `ID`= 12678;
UPDATE `quest_details` SET `Emote1`= 1, `Emote2`= 1, `Emote3`= 1, `Emote4`= 1 WHERE `ID`= 12680;
UPDATE `quest_details` SET `Emote1`= 1, `Emote2`= 1, `Emote3`= 1, `Emote4`= 0 WHERE `ID`= 12733;
UPDATE `quest_details` SET `Emote1`= 1, `Emote2`= 1, `Emote3`= 1, `Emote4`= 0 WHERE `ID`= 12679;
UPDATE `quest_details` SET `Emote1`= 1, `Emote2`= 1, `Emote3`= 1, `Emote4`= 0 WHERE `ID`= 12687;

DELETE FROM `waypoint_data` WHERE `id`= 1287390;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_Y`, `position_z`) VALUES
(1287390, 0, 2360.7605, -5774.658, 153.60991),
(1287390, 1, 2365.823, -5770.872, 153.60991),
(1287390, 2, 2371.8052, -5767.541, 153.14471),
(1287390, 3, 2371.6038, -5775.583, 153.60991),
(1287390, 4, 2376.499, -5781.667, 153.60991),
(1287390, 5, 2372.2847, -5788.8706, 153.60991);

UPDATE `creature_addon` SET `cyclicSplinePathId`= 1287390, `waypointPathId`= 0, `bytes1`= 50331648 WHERE `guid`= 128739;
UPDATE `creature` SET `MovementType`= 3 WHERE `guid`= 128739;
UPDATE `creature_template` SET `flags_extra`= 512 WHERE `entry`= 29047;
UPDATE `creature_template_movement` SET `Ground`= 0 WHERE `CreatureId`= 29047;
