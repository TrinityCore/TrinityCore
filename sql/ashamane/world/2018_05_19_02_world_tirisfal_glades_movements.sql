UPDATE `creature` SET `spawntimesecs`='180', `spawndist`='5', `MovementType`='1' WHERE  `id` IN (61905,10356);

DELETE FROM `creature_addon` WHERE  `guid`=192606;
UPDATE `creature` SET `position_x`='2220.16', `position_y`='1034.98', `position_z`='35.4363', `MovementType`='2' WHERE  `guid`=192606;

DELETE FROM `creature_addon` WHERE  `guid`=192891;
UPDATE `creature` SET `position_x`='2243.38', `position_y`='1014.55', `position_z`='36.9146', `MovementType`='2' WHERE  `guid`=192891;

DELETE FROM `creature_addon` WHERE  `guid`=192512;
UPDATE `creature` SET `position_x`='2370.84', `position_y`='398.24', `position_z`='37.7116', `MovementType`='2' WHERE  `guid`=192512;

DELETE FROM `creature_addon` WHERE  `guid`=192725;
UPDATE `creature` SET `position_x`='2208.81', `position_y`='255.006', `position_z`='33.5904', `MovementType`='2' WHERE  `guid`=192725;

DELETE FROM `creature_addon` WHERE  `guid`=193060;
UPDATE `creature` SET `position_x`='2282.96', `position_y`='390.353', `position_z`='34.1148', `MovementType`='2' WHERE  `guid`=193060;

DELETE FROM `creature_addon` WHERE  `guid`=192943;
UPDATE `creature` SET `position_x`='2427.29', `position_y`='343.707', `position_z`='34.6791', `MovementType`='2' WHERE  `guid`=192943;

UPDATE `creature_addon` SET `path_id`='3257150' WHERE  `guid`=194297;
UPDATE `creature` SET `position_x`='2745.419922', `position_y`='978.708984', `position_z`='109.392998', `MovementType`='2' WHERE  `guid`=194297;

DELETE FROM `creature_addon` WHERE  `guid`=192502;
UPDATE `creature` SET `position_x`='2129.376709', `position_y`='953.351624', `position_z`='29.058704', `MovementType`='2' WHERE  `guid`=192502;

DELETE FROM `creature_addon` WHERE `guid`=192822;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(192822, 3259270, 0, 0, 1, 0, 0, 0, 0, NULL);
UPDATE `creature` SET `position_x`='1798.26', `position_y`='645.24', `position_z`='39.4603', `MovementType`='2' WHERE  `guid`=192822;
UPDATE `creature_addon` SET `path_id`='3274301' WHERE  `guid`=193916;
UPDATE `creature` SET `position_x`='1983.83', `position_y`='-440.439', `position_z`='34.5588', `MovementType`='2' WHERE  `guid`=193916;

DELETE FROM `creature_addon` WHERE `guid`=192616;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES 
(192616, 3275990, 0, 0, 1, 0, 0, 0, 0, NULL);
UPDATE `creature` SET `position_x`='1752.673', `position_y`='-714.7821', `position_z`='60.37662', `MovementType`='2' WHERE  `guid`=192616;

UPDATE `creature_addon` SET `path_id`='3252650' WHERE  `guid`=193655;
UPDATE `creature` SET `position_x`='1932.444', `position_y`='1590.943', `position_z`='83.48648', `MovementType`='2' WHERE  `guid`=193655;

UPDATE `creature_addon` SET `path_id`='3273900' WHERE  `guid`=194519;
UPDATE `creature` SET `position_x`='2868.919', `position_y`='-497.5436', `position_z`='101.3836', `MovementType`='2' WHERE  `guid`=194519;

UPDATE `creature_template_addon` SET `path_id`='3252810' WHERE  `entry`=1739;
UPDATE `creature` SET `position_x`='1864.6', `position_y`='1588.79', `position_z`='91.9528', `MovementType`='2' WHERE  `guid`=192496;

DELETE FROM `creature_addon` WHERE `guid`=192699;
UPDATE `creature_template_addon` SET `path_id`='3251470' WHERE  `entry`=2315;
UPDATE `creature` SET `position_x`='1843.27', `position_y`='1622.26', `position_z`='96.934', `MovementType`='2' WHERE  `guid`=192699;

