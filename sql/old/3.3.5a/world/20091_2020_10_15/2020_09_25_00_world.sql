--
SET @POOL := 764;

DELETE FROM `creature_addon` WHERE `guid` IN (29117,29119,42568,45808,77853,78323,78495,84323);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`) VALUES
(29117,291170,0,0,1,0),
(29119,291190,0,0,1,0),
(42568,425680,0,0,1,0),
(45808,458080,0,0,1,0),
(77853,778530,0,0,1,0),
(78323,783230,0,0,1,0),
(78495,784950,0,0,1,0),
(84323,843230,0,0,1,0);

DELETE FROM `creature` WHERE `guid` IN (29117,29119,42568,45808,77853,78323,78495,84323);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`) VALUES
(29117, 18321, 556, 3, 1, 1, -178.946, 289.972, 26.4710, 0, 10800, 0, 2),
(29119, 21904, 556, 3, 1, 0, -95.5819, 299.378, 26.4831, 0, 10800, 0, 2),
(42568, 21904, 556, 3, 1, 0, -87.0797, 275.748, 26.6794, 0, 10800, 0, 2),
(45808, 21904, 556, 3, 1, 0, -235.422, 324.181, 26.9876, 0, 10800, 0, 2),
(77853, 21904, 556, 3, 1, 0, -212.621, 334.339, 26.7031, 0, 10800, 0, 2),
(78323, 18321, 556, 3, 1, 1, -116.988, 275.102, 27.1584, 0, 10800, 0, 2),
(78495, 21904, 556, 3, 1, 0, -70.3576, 312.249, 26.5765, 0, 10800, 0, 2),
(84323, 21904, 556, 3, 1, 0, -49.3515, 289.825, 26.8762, 0, 10800, 0, 2);

UPDATE `creature` SET `position_x` = -178.946, `position_y` = 289.972, `position_z` = 26.4710 WHERE `guid` = 83258 AND `id` = 21904;
UPDATE `creature` SET `position_x` = -95.5819, `position_y` = 299.378, `position_z` = 26.4831 WHERE `guid` = 83267 AND `id` = 18321;
UPDATE `creature` SET `position_x` = -87.0797, `position_y` = 275.748, `position_z` = 26.6794 WHERE `guid` = 83262 AND `id` = 18321;
UPDATE `creature` SET `position_x` = -235.422, `position_y` = 324.181, `position_z` = 26.9876 WHERE `guid` = 83254 AND `id` = 18321;
UPDATE `creature` SET `position_x` = -212.621, `position_y` = 334.339, `position_z` = 26.7031 WHERE `guid` = 83256 AND `id` = 18321;
UPDATE `creature` SET `position_x` = -116.988, `position_y` = 275.102, `position_z` = 27.1584 WHERE `guid` = 83266 AND `id` = 21904;
UPDATE `creature` SET `position_x` = -70.3576, `position_y` = 312.249, `position_z` = 26.5765 WHERE `guid` = 83260 AND `id` = 18321;
UPDATE `creature` SET `position_x` = -49.3515, `position_y` = 289.825, `position_z` = 26.8762 WHERE `guid` = 83261 AND `id` = 18321;
UPDATE `creature` SET `position_x` = -15.6102, `position_y` = 279.939, `position_z` = 26.7315 WHERE `guid` = 83265 AND `id` = 21904;

DELETE FROM `waypoint_data` WHERE `id` IN (832580,832670,832620,832540,832560,832660,832600,832610,832650,291170,291190,425680,458080,778530,783230,784950,843230);
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`) VALUES
(832580,1,-178.94624,289.9725,26.47102),
(832580,2,-167.46309,287.20474,26.719341),
(832580,3,-178.94624,289.9725,26.47102),
(832580,4,-186.66884,286.6715,26.504198),
(832670,1,-95.58192,299.37805,26.483166),
(832670,2,-103.86865,297.52078,26.516693),
(832670,3,-95.58192,299.37805,26.483166),
(832670,4,-95.795074,309.50726,25.902016),
(832620,1,-87.07979,275.7488,26.679401),
(832620,2,-88.232155,269.7406,26.807932),
(832620,3,-87.07979,275.7488,26.679401),
(832620,4,-82.03732,277.92352,26.707567),
(832540,1,-235.42253,324.18118,26.987646),
(832540,2,-226.3113,324.1906,27.157162),
(832540,3,-235.42253,324.18118,26.987646),
(832540,4,-243.1212,329.36237,27.069582),
(832560,1,-212.62154,334.33975,26.703196),
(832560,2,-215.65906,341.38385,26.758604),
(832560,3,-212.62154,334.33975,26.703196),
(832560,4,-205.06012,328.8966,26.6643),
(832660,1,-116.98837,275.10294,27.158407),
(832660,2,-110.64208,271.144,26.157415),
(832660,3,-116.98837,275.10294,27.158407),
(832660,4,-123.93096,274.12927,27.44369),
(832600,1,-70.35762,312.2491,26.576595),
(832600,2,-66.265144,308.89322,26.427582),
(832600,3,-62.638836,301.12744,26.22019),
(832600,4,-66.25406,308.86948,26.425596),
(832610,1,-49.351517,289.82507,26.876232),
(832610,2,-44.706738,282.19345,26.748894),
(832610,3,-49.351517,289.82507,26.876232),
(832610,4,-56.364132,289.20328,26.88951),
(832610,5,-62.931053,283.66907,26.916052),
(832610,6,-56.364132,289.20328,26.88951),
(832650,1,-15.610211,279.9396,26.73158),
(832650,2,-14.914525,293.09634,26.731062),
(291170,1,-178.94624,289.9725,26.47102),
(291170,2,-167.46309,287.20474,26.719341),
(291170,3,-178.94624,289.9725,26.47102),
(291170,4,-186.66884,286.6715,26.504198),
(291190,1,-95.58192,299.37805,26.483166),
(291190,2,-103.86865,297.52078,26.516693),
(291190,3,-95.58192,299.37805,26.483166),
(291190,4,-95.795074,309.50726,25.902016),
(425680,1,-87.07979,275.7488,26.679401),
(425680,2,-88.232155,269.7406,26.807932),
(425680,3,-87.07979,275.7488,26.679401),
(425680,4,-82.03732,277.92352,26.707567),
(458080,1,-235.42253,324.18118,26.987646),
(458080,2,-226.3113,324.1906,27.157162),
(458080,3,-235.42253,324.18118,26.987646),
(458080,4,-243.1212,329.36237,27.069582),
(778530,1,-212.62154,334.33975,26.703196),
(778530,2,-215.65906,341.38385,26.758604),
(778530,3,-212.62154,334.33975,26.703196),
(778530,4,-205.06012,328.8966,26.6643),
(783230,1,-116.98837,275.10294,27.158407),
(783230,2,-110.64208,271.144,26.157415),
(783230,3,-116.98837,275.10294,27.158407),
(783230,4,-123.93096,274.12927,27.44369),
(784950,1,-70.35762,312.2491,26.576595),
(784950,2,-66.265144,308.89322,26.427582),
(784950,3,-62.638836,301.12744,26.22019),
(784950,4,-66.25406,308.86948,26.425596),
(843230,1,-49.351517,289.82507,26.876232),
(843230,2,-44.706738,282.19345,26.748894),
(843230,3,-49.351517,289.82507,26.876232),
(843230,4,-56.364132,289.20328,26.88951),
(843230,5,-62.931053,283.66907,26.916052),
(843230,6,-56.364132,289.20328,26.88951);

-- Wrong id
UPDATE `creature` SET `id` = 18320 WHERE `guid` = 49354 AND `id` = 18319;

DELETE FROM `creature` WHERE `guid` IN (84324,84492,84668,84844,84845,86083,86084,86093,86094,86095,86096,86598,86599);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `MovementType`, `VerifiedBuild`) VALUES
(84324, 18325, 556, 3, 1, 1, -234.595, 335.917, 27.378, 4.18879, 10800, 0, 0, 12340),
(84492, 18326, 556, 3, 1, 1, -202.409, 343.724, 26.7194, 3.71755, 10800, 0, 0, 12340),
(84668, 18325, 556, 3, 1, 1, -178.803, 276.965, 26.7434, 1.81514, 10800, 0, 0, 12340),
(84844, 18326, 556, 3, 1, 1, -118.563, 266.142, 27.1712, 2.35619, 10800, 0, 0, 12340),
(84845, 18319, 556, 3, 1, 1, -118.563, 266.142, 27.1712, 2.35619, 10800, 0, 0, 12340),
(86083, 18325, 556, 3, 1, 1, -101.329, 309.882, 26.6085, 5.81194, 10800, 0, 0, 12340),
(86084, 18319, 556, 3, 1, 1, -101.329, 309.882, 26.6085, 5.81194, 10800, 0, 0, 12340),
(86093, 18325, 556, 3, 1, 1, -84.3041, 266.641, 26.8912, 3.00196, 10800, 0, 0, 12340),
(86094, 18326, 556, 3, 1, 1, -84.3041, 266.641, 26.8912, 3.00196, 10800, 0, 0, 12340),
(86095, 18325, 556, 3, 1, 1, -60.1442, 311.665, 27.2029, 3.87463, 10800, 0, 0, 12340),
(86096, 18326, 556, 3, 1, 1, -60.1442, 311.665, 27.2029, 3.87463, 10800, 0, 0, 12340),
(86598, 18325, 556, 3, 1, 1, -49.5232, 280.174, 26.9464, 2.63544, 10800, 0, 0, 12340),
(86599, 18326, 556, 3, 1, 1, -49.5232, 280.174, 26.9464, 2.63544, 10800, 0, 0, 12340);

DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOL+0 AND @POOL+15;
INSERT INTO `pool_template` (`entry`, `max_limit`, `description`) VALUES
(@POOL+0, 1, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk"),
(@POOL+1, 1, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk"),
(@POOL+2, 1, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk"),
(@POOL+3, 1, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk"),
(@POOL+4, 1, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk"),
(@POOL+5, 1, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk"),
(@POOL+6, 1, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk"),
(@POOL+7, 1, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk"),

(@POOL+8, 1, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman"),
(@POOL+9, 1, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman"),
(@POOL+10, 1, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman"),

(@POOL+11, 1, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer"),
(@POOL+12, 1, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer"),
(@POOL+13, 1, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer"),
(@POOL+14, 1, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer"),
(@POOL+15, 1, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer");

DELETE FROM `pool_members` WHERE `type` = 0 AND `spawnId` IN (29117,83258,29119,83267,42568,83262,45808,83254,77853,83256,78323,83266,78495,83260,84323,83261,84324,83297,12160,84492,83291,84668,49348,84844,84845,86083,86084,86093,86094,86095,86096,86598,86599,49353,12161,83268,83285);
INSERT INTO `pool_members` (`type`, `spawnId`, `poolSpawnId`, `chance`, `description`) VALUES
(0, 29117, @POOL+0, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Sethekk Talon Lord"),
(0, 83258, @POOL+0, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Avian Warhawk"),
(0, 83267, @POOL+1, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Sethekk Talon Lord"),
(0, 29119, @POOL+1, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Avian Warhawk"),
(0, 83262, @POOL+2, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Sethekk Talon Lord"),
(0, 42568, @POOL+2, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Avian Warhawk"),
(0, 83254, @POOL+3, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Sethekk Talon Lord"),
(0, 45808, @POOL+3, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Avian Warhawk"),
(0, 83256, @POOL+4, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Sethekk Talon Lord"),
(0, 77853, @POOL+4, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Avian Warhawk"),
(0, 78323, @POOL+5, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Sethekk Talon Lord"),
(0, 83266, @POOL+5, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Avian Warhawk"),
(0, 83260, @POOL+6, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Sethekk Talon Lord"),
(0, 78495, @POOL+6, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Avian Warhawk"),
(0, 83261, @POOL+7, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Sethekk Talon Lord"),
(0, 84323, @POOL+7, 0, "Sethekk Halls - Sethekk Talon Lord / Avian Warhawk - Avian Warhawk"),

(0, 84324, @POOL+8, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman - Sethekk Prophet"),
(0, 83297, @POOL+8, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman - Sethekk Shaman"),
(0, 12160, @POOL+9, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman - Sethekk Prophet"),
(0, 84492, @POOL+9, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman - Sethekk Shaman"),
(0, 84668, @POOL+10, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman - Sethekk Prophet"),
(0, 83291, @POOL+10, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman - Sethekk Shaman"),

(0, 49348, @POOL+11, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Sethekk Prophet"),
(0, 84844, @POOL+11, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Sethekk Shaman"),
(0, 84845, @POOL+11, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Time-Lost Scryer"),
(0, 86083, @POOL+12, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Sethekk Prophet"),
(0, 49353, @POOL+12, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Sethekk Shaman"),
(0, 86084, @POOL+12, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Time-Lost Scryer"),
(0, 86093, @POOL+13, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Sethekk Prophet"),
(0, 86094, @POOL+13, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Sethekk Shaman"),
(0, 12161, @POOL+13, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Time-Lost Scryer"),
(0, 86095, @POOL+14, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Sethekk Prophet"),
(0, 86096, @POOL+14, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Sethekk Shaman"),
(0, 83268, @POOL+14, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Time-Lost Scryer"),
(0, 86598, @POOL+15, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Sethekk Prophet"),
(0, 86599, @POOL+15, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Sethekk Shaman"),
(0, 83285, @POOL+15, 0, "Sethekk Halls - Sethekk Prophet / Sethekk Shaman / Time-Lost Scryer - Time-Lost Scryer");

/*
DELETE FROM `creature_formations` WHERE `leaderGUID` IN (83289,49354,12163,83287,83284,12162,49153,49159,83293);
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(83289,83289,0,0,3,0,0),
(83289,78323,0,0,3,0,0),
(83289,83266,0,0,3,0,0),
(83289,84845,0,0,3,0,0),
(83289,84844,0,0,3,0,0),
(83289,49348,0,0,3,0,0),
(83289,83283,0,0,3,0,0),

(49354,49354,0,0,3,0,0),
(49354,83267,0,0,3,0,0),
(49354,29119,0,0,3,0,0),
(49354,83290,0,0,3,0,0),
(49354,49353,0,0,3,0,0),
(49354,86084,0,0,3,0,0),
(49354,86083,0,0,3,0,0),

(12163,12163,0,0,3,0,0),
(12163,83262,0,0,3,0,0),
(12163,42568,0,0,3,0,0),
(12163,86094,0,0,3,0,0),
(12163,12161,0,0,3,0,0),
(12163,86093,0,0,3,0,0),
(12163,83278,0,0,3,0,0),

(83287,83287,0,0,3,0,0),
(83287,83260,0,0,3,0,0),
(83287,78495,0,0,3,0,0),
(83287,83281,0,0,3,0,0),
(83287,83268,0,0,3,0,0),
(83287,86096,0,0,3,0,0),
(83287,86095,0,0,3,0,0),

(83284,83284,0,0,3,0,0),
(83284,83282,0,0,3,0,0),
(83284,83261,0,0,3,0,0),
(83284,84323,0,0,3,0,0),
(83284,86598,0,0,3,0,0),
(83284,86599,0,0,3,0,0),
(83284,83285,0,0,3,0,0),

(12162,12162,0,0,3,0,0),
(12162,83265,0,0,3,0,0),
(12162,83279,0,0,3,0,0),
(12162,83286,0,0,3,0,0),
(12162,83269,0,0,3,0,0),

(49153,49153,0,0,3,0,0),
(49153,83295,0,0,3,0,0),
(49153,83254,0,0,3,0,0),
(49153,45808,0,0,3,0,0),
(49153,83297,0,0,3,0,0),
(49153,84324,0,0,3,0,0),

(49159,49159,0,0,3,0,0),
(49159,83292,0,0,3,0,0),
(49159,83256,0,0,3,0,0),
(49159,77853,0,0,3,0,0),
(49159,84492,0,0,3,0,0),
(49159,12160,0,0,3,0,0),

(83293,83293,0,0,3,0,0),
(83293,49161,0,0,3,0,0),
(83293,83258,0,0,3,0,0),
(83293,29117,0,0,3,0,0),
(83293,84668,0,0,3,0,0),
(83293,83291,0,0,3,0,0);
*/
