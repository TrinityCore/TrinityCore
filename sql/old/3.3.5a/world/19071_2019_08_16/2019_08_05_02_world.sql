-- 
DELETE FROM `creature_template_movement` WHERE `CreatureId`IN (29349,31598);
INSERT INTO `creature_template_movement` (`CreatureId`,`Ground`,`Swim`,`Flight`,`Rooted`) VALUES
(29349, 1, 1, 1, 0),
(31598, 1, 1, 1, 0);

UPDATE `creature_template_addon` SET `bytes1`=50331648 WHERE `entry` IN (29349,31598);
 DELETE FROM `creature` WHERE `guid` IN (116084, 116104, 116105, 116111, 116112, 116113, 116120, 116121, 116125, 116128, 116130, 116132) AND `id`=29349;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(116084, 29349, 601, 4277, 4405, 3, 1, 0, 0, 542.7188, 517.9711, 336.9682, 4.978864, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 11723), -- 29349 (Area: 4405 - Difficulty: 0) (possible waypoints or random movement)
(116104, 29349, 601, 4277, 4405, 3, 1, 0, 0, 535.3182, 527.1041, 325.2883, 3.817765, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 11723), -- 29349 (Area: 4405 - Difficulty: 0) (possible waypoints or random movement)
(116105, 29349, 601, 4277, 4405, 3, 1, 0, 0, 520.6521, 456.0348, 324.8441, 1.56603, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 11723), -- 29349 (Area: 4405 - Difficulty: 0) (possible waypoints or random movement)
(116111, 29349, 601, 4277, 4405, 3, 1, 0, 0, 562.5114, 559.8456, 330.12, 0.8606349, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 11723), -- 29349 (Area: 4405 - Difficulty: 0) (possible waypoints or random movement)
(116112, 29349, 601, 4277, 4405, 3, 1, 0, 0, 526.8224, 538.0342, 325.2505, 3.610992, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 11723), -- 29349 (Area: 4405 - Difficulty: 0) (possible waypoints or random movement)
(116113, 29349, 601, 4277, 4405, 3, 1, 0, 0, 503.2326, 532.7911, 318.9742, 3.109733, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 11723), -- 29349 (Area: 4405 - Difficulty: 0) (possible waypoints or random movement)
(116120, 29349, 601, 4277, 4405, 3, 1, 0, 0, 510.6967, 551.9977, 319.8427, 2.294438, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 11723), -- 29349 (Area: 4405 - Difficulty: 0) (possible waypoints or random movement)
(116121, 29349, 601, 4277, 4405, 3, 1, 0, 0, 534.4473, 480.184, 320.8186, 3.074911, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 11723), -- 29349 (Area: 4405 - Difficulty: 0) (possible waypoints or random movement)
(116125, 29349, 601, 4277, 4405, 3, 1, 0, 0, 536.2711, 519.256, 316.4399, 4.211335, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 11723), -- 29349 (Area: 4405 - Difficulty: 0) (possible waypoints or random movement)
(116128, 29349, 601, 4277, 4405, 3, 1, 0, 0, 570.606, 497.1762, 334.0921, 5.500285, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 11723), -- 29349 (Area: 4405 - Difficulty: 0) (possible waypoints or random movement)
(116130, 29349, 601, 4277, 4405, 3, 1, 0, 0, 555.2474, 519.0841, 328.507, 1.215193, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 11723), -- 29349 (Area: 4405 - Difficulty: 0) (possible waypoints or random movement)
(116132, 29349, 601, 4277, 4405, 3, 1, 0, 0, 550.5076, 568.0135, 331.5263, 1.164986, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 11723); -- 29349 (Area: 4405 - Difficulty: 0) (possible waypoints or random movement)
