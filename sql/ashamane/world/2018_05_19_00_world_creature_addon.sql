DELETE FROM `creature_addon` WHERE `path_id`=0 AND `mount`=0 AND `bytes1`=0 AND `bytes2`=0 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras`='';
DELETE FROM `creature_addon` WHERE `path_id`=0 AND `mount`=0 AND `bytes1`=0 AND `bytes2`=0 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE `path_id`=0 AND `mount`=0 AND `bytes1`=0 AND `bytes2`=1 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras`='';
DELETE FROM `creature_addon` WHERE `path_id`=0 AND `mount`=0 AND `bytes1`=0 AND `bytes2`=1 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE `path_id`=0 AND `mount`=0 AND `bytes1`=0 AND `bytes2`=256 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras`='';
DELETE FROM `creature_addon` WHERE `path_id`=0 AND `mount`=0 AND `bytes1`=0 AND `bytes2`=257 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras`='';
DELETE FROM `creature_addon` WHERE `path_id`=0 AND `mount`=0 AND `bytes1`=0 AND `bytes2`=258 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras`='';
DELETE FROM `creature_addon` WHERE `path_id`=0 AND `mount`=0 AND `bytes1`=0 AND `bytes2`=4096 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE `path_id`=0 AND `mount`=0 AND `bytes1`=0 AND `bytes2`=4097 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE `path_id`=0 AND `mount`=0 AND `bytes1`=0 AND `bytes2`=4098 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE `path_id`=0 AND `mount`=0 AND `bytes1`=0 AND `bytes2`=10241 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE `guid` = `path_id` AND `mount`=0 AND `bytes1`=0 AND `bytes2`=0 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE `guid` = `path_id` AND `mount`=0 AND `bytes1`=0 AND `bytes2`=1 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras`='';
DELETE FROM `creature_addon` WHERE `guid` = `path_id` AND `mount`=0 AND `bytes1`=0 AND `bytes2`=1 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE `guid` = `path_id` AND `mount`=0 AND `bytes1`=0 AND `bytes2`=257 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras`='';
DELETE FROM `creature_addon` WHERE `guid` = `path_id` AND `mount`=0 AND `bytes1`=0 AND `bytes2`=257 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE `guid` = `path_id` AND `mount`=0 AND `bytes1`=0 AND `bytes2`=258 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE `guid` = `path_id` AND `mount`=0 AND `bytes1`=0 AND `bytes2`=4096 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE `guid` = `path_id` AND `mount`=0 AND `bytes1`=0 AND `bytes2`=4097 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE `guid` = `path_id` AND `mount`=0 AND `bytes1`=0 AND `bytes2`=4098 AND `emote`=0 AND `aiAnimKit`=0 AND `movementAnimKit`=0 AND `meleeAnimKit`=0 AND `auras` IS NULL;
DELETE FROM `creature_addon` WHERE  `guid` IN (7868,9222,53802,54254,56335,58284,58300,58347,59121,59125,59126,59129,60409,60414,65915,66009,67017,254940,277016,1400112,70996,71372,71991,73843,73844,73845,73846,73847,74626,74639,74727,74740,77286,77287,77288,77506,77507,77509,1410938,77671,78648,10184380,79226,79227,10183888,82797,82805,82806,85830,85831,87284,89261,89262,91804,93113,93253,93258,93271,93317,93329,93332,93415,93420,93427,93447,93487,96140,112775,123676,123677,123678,123679,123680,123681,123682,123683,123684,123685,123686,123687,
125894,136758,160040,161014,161281,162641,162643,70995);

UPDATE `creature_addon` SET `path_id`='0' WHERE  `guid` IN (4963,58288,58299,58301,58302,58304,58337,58341,58343,58345,58809,58924,59459,59462,59497,59563,59736,60418,77145,77146,77765,82449,82450,82451,82452,84283,84284,84286,93107,93673,93676,93677,93678,93723,93724,93725,93726,93727,96148,96151,111427,111428,111429);
UPDATE `creature_addon` SET `path_id`='0' WHERE `guid` = `path_id` AND `bytes1`=0 AND `bytes2`=0;
UPDATE `creature_addon` SET `path_id`='0' WHERE `guid` = `path_id` AND `bytes1`=0 AND `bytes2`=1;
UPDATE `creature_addon` SET `path_id`='0' WHERE `guid` = `path_id` AND `bytes1`=0 AND `bytes2`=2;
UPDATE `creature_addon` SET `path_id`='0' WHERE `guid` = `path_id` AND `bytes1`=0 AND `bytes2`=3;
UPDATE `creature_addon` SET `path_id`='0' WHERE `guid` = `path_id` AND `bytes1`=9 AND `bytes2`=1;
UPDATE `creature_addon` SET `path_id`='0' WHERE `guid` = `path_id` AND `bytes1`=65536;
UPDATE `creature_addon` SET `path_id`='0' WHERE `guid` = `path_id` AND `bytes1`=131072;
UPDATE `creature_addon` SET `path_id`='0' WHERE `guid` = `path_id` AND `bytes1`=196608;
UPDATE `creature_addon` SET `path_id`='0' WHERE `guid` = `path_id` AND `bytes1`=33554432;
UPDATE `creature_addon` SET `path_id`='0' WHERE `guid` = `path_id` AND `bytes1`=50397184;
UPDATE `creature_addon` SET `path_id`='0' WHERE `guid` = `path_id` AND `bytes1`=50331648;
UPDATE `creature_addon` SET `path_id`='177929' WHERE  `guid`=177929;
UPDATE `creature_addon` SET `path_id`='311926' WHERE  `guid`=311926;
UPDATE `creature_addon` SET `path_id`='315650' WHERE  `guid`=315650;
UPDATE `creature_addon` SET `path_id`='20505202' WHERE  `guid`=20505202;
UPDATE `creature_addon` SET `path_id`='20506771' WHERE  `guid`=20506771;
UPDATE `creature_addon` SET `path_id`='20506786' WHERE  `guid`=20506786;
UPDATE `creature_addon` SET `path_id`='20507149' WHERE  `guid`=20507149;
UPDATE `creature_addon` SET `path_id`='20521407' WHERE  `guid`=20521407;
UPDATE `creature_addon` SET `path_id`='20519305' WHERE  `guid`=20519305;
UPDATE `creature_addon` SET `path_id`='20522432' WHERE  `guid`=20522432;
UPDATE `creature_addon` SET `path_id`='20522696' WHERE  `guid`=20522696;
UPDATE `creature_addon` SET `path_id`='20541062' WHERE  `guid`=20541062;
UPDATE `creature_addon` SET `path_id`='20541053' WHERE  `guid`=20541053;

DELETE FROM `creature_template_addon` WHERE `entry` IN (15931,16028,16061,16424,17264,17280,17815,17840,18664,21047,36666,38490);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(15931, 0, 0, 0, 0, 0, 0, 0, 0, '18950'),
(16028, 0, 0, 0, 0, 0, 0, 0, 0, '18950'),
(16061, 0, 0, 0, 1, 0, 0, 0, 0, '18950'),
(16424, 0, 0, 0, 1, 0, 0, 0, 0, '18950'),
(17264, 0, 0, 0, 1, 0, 0, 0, 0, '18950'),
(17280, 0, 0, 0, 0, 0, 0, 0, 0, '18950'),
(17815, 0, 0, 0, 1, 0, 0, 0, 0, '8279'),
(17840, 0, 0, 0, 0, 0, 0, 0, 0, '18950'),
(18664, 0, 0, 0, 1, 0, 0, 0, 0, '12544'),
(21047, 0, 0, 0, 1, 0, 0, 0, 0, '12550'),
(36666, 0, 0, 0, 0, 0, 0, 0, 0, '69144'),
(38490, 0, 0, 0, 0, 0, 0, 0, 0, '18950');

DELETE FROM `creature_addon` WHERE `guid` IN (53805,53810,54481,75046,75048,75049,52229,53599,52213,6300);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(53805, 2026250, 0, 0, 1, 0, 0, 0, 0, '18950'),
(53810, 2026270, 0, 0, 1, 0, 0, 0, 0, '18950'),
(54481, 2026280, 0, 0, 1, 0, 0, 0, 0, '18950'),
(75046, 2026290, 0, 0, 1, 0, 0, 0, 0, '18950'),
(75048, 2026300, 0, 0, 1, 0, 0, 0, 0, '18950'),
(75049, 2026310, 0, 0, 1, 0, 0, 0, 0, '18950'),
(52229, 1277810, 0, 0, 0, 0, 0, 0, 0, '18950'),
(53599, 1281350, 0, 0, 0, 0, 0, 0, 0, '18950'),
(52213, 1283120, 0, 0, 1, 0, 0, 0, 0, '18950'),
(6300, 2087860, 0, 0, 0, 0, 0, 0, 0, '18950');

UPDATE `creature` SET `position_x`='-1164.93', `position_y`='1463.36', `position_z`='68.4186', `MovementType`='2' WHERE  `guid`=53805;
UPDATE `creature` SET `position_x`='-1236.78', `position_y`='1455.89', `position_z`='68.5809', `MovementType`='2' WHERE  `guid`=53810;
UPDATE `creature` SET `position_x`='-1262.9', `position_y`='1656.9', `position_z`='67.687', `MovementType`='2' WHERE  `guid`=54481;
UPDATE `creature` SET `position_x`='-1293.92', `position_y`='1535.08', `position_z`='68.5991', `MovementType`='2' WHERE  `guid`=75046;
UPDATE `creature` SET `position_x`='-1285.15', `position_y`='1630.34', `position_z`='91.7482', `MovementType`='2' WHERE  `guid`=75048;
UPDATE `creature` SET `position_x`='-1323.98', `position_y`='1664.68', `position_z`='68.3831', `MovementType`='2' WHERE  `guid`=75049;
UPDATE `creature` SET `position_x`='3228.72', `position_y`='-3363.87', `position_z`='304.48', `MovementType`='2' WHERE  `guid`=52229;
UPDATE `creature` SET `position_x`='3294.44', `position_y`='-3232.73', `position_z`='294.063', `MovementType`='2' WHERE  `guid`=53599;
UPDATE `creature` SET `position_x`='2758.93', `position_y`='-3107.12', `position_z`='267.685', `MovementType`='2' WHERE  `guid`=52213;
UPDATE `creature` SET `position_x`='-330.674', `position_y`='2139.85', `position_z`='199.97', `MovementType`='2' WHERE  `guid`=6300;

