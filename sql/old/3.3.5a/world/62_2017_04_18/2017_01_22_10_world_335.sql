-- Durotar - Burning Blade Coven
-- waypoints
UPDATE `creature` SET  `position_x` = -160.8142, `position_y` = -4359.207, `position_z` = 67.14682, `orientation` = 0.3144676 WHERE `guid` = 13062;
UPDATE `creature` SET  `position_x` = -49.65278, `position_y` = -4223.181, `position_z` = 62.25517, `orientation` = 5.201081  WHERE `guid` = 4701;
UPDATE `creature` SET  `position_x` = -93.51848, `position_y` = -4294.795, `position_z` = 60.98821, `orientation` = 3.864847  WHERE `guid` = 12169;
UPDATE `creature` SET  `position_x` = -147.0916, `position_y` = -4273.76,  `position_z` = 63.18432, `orientation` = 2.113575  WHERE `guid` = 4705; 

SET @NPC := 13062;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, -154.1995, -4357.055, 66.81747),
(@PATH, 2, -139.7794, -4370.038, 66.23576),
(@PATH, 3, -132.1772, -4361.437, 67.09566),
(@PATH, 4, -129.8285, -4346.956, 66.25489),
(@PATH, 5, -127.6685, -4337.691, 64.19341),
(@PATH, 6, -113.9779, -4332.429, 65.83784),
(@PATH, 7, -95.87244, -4329.407, 64.50475),
(@PATH, 8, -78.06834, -4330.183, 66.95846),
(@PATH, 9, -69.29854, -4337.840, 67.89400),
(@PATH, 10, -53.12156, -4331.939, 68.31259),
(@PATH, 11, -69.29854, -4337.840, 67.89400),
(@PATH, 12, -78.06834, -4330.183, 66.95846),
(@PATH, 13, -95.87244, -4329.407, 64.50475),
(@PATH, 14, -113.9779, -4332.429, 65.83784),
(@PATH, 15, -127.6269, -4337.513, 64.19106),
(@PATH, 16, -129.8285, -4346.956, 66.25489),
(@PATH, 17, -132.1772, -4361.437, 67.09566),
(@PATH, 18, -139.7794, -4370.038, 66.23576),
(@PATH, 19, -154.1995, -4357.055, 66.81747),
(@PATH, 20, -162.9179, -4360.370, 67.25686);

SET @NPC := 4701;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, -35.73989, -4228.090, 65.26183),
(@PATH, 2, -25.14738, -4238.516, 68.07430),
(@PATH, 3, -28.57471, -4245.481, 68.47588),
(@PATH, 4, -23.61659, -4258.847, 66.65924),
(@PATH, 5, -35.69927, -4270.216, 66.89402),
(@PATH, 6, -56.39381, -4280.354, 70.03080),
(@PATH, 7, -53.37805, -4302.129, 69.88853),
(@PATH, 8, -39.73870, -4310.986, 70.27384),
(@PATH, 9, -53.37805, -4302.129, 69.88853),
(@PATH, 10, -56.39381, -4280.354, 70.03080),
(@PATH, 11, -35.69927, -4270.216, 66.89402),
(@PATH, 12, -23.61659, -4258.847, 66.65924),
(@PATH, 13, -28.57471, -4245.481, 68.47588),
(@PATH, 14, -25.14738, -4238.516, 68.07430),
(@PATH, 15, -35.73989, -4228.090, 65.26189),
(@PATH, 16, -49.53179, -4222.876, 62.26782);

SET @NPC := 12169;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, -107.0685, -4306.758, 62.61592),
(@PATH, 2, -124.8001, -4318.367, 66.01467),
(@PATH, 3, -139.2389, -4303.628, 66.19415),
(@PATH, 4, -143.2203, -4283.829, 64.45527),
(@PATH, 5, -129.4232, -4280.465, 64.74496),
(@PATH, 6, -109.4703, -4285.220, 63.73031),
(@PATH, 7, -94.22346, -4292.266, 60.93617);

SET @NPC := 4705;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`) VALUES
(@PATH, 1, -152.7180, -4264.433, 61.52343),
(@PATH, 2, -150.7954, -4251.991, 59.81219),
(@PATH, 3, -140.4173, -4234.240, 58.08895),
(@PATH, 4, -127.9433, -4229.995, 57.20447),
(@PATH, 5, -110.4441, -4210.701, 54.79549),
(@PATH, 6, -96.40952, -4201.509, 51.43105),
(@PATH, 7, -80.83832, -4204.425, 49.83477),
(@PATH, 8, -79.68057, -4223.967, 53.02843),
(@PATH, 9, -83.51179, -4242.018, 52.78401),
(@PATH, 10, -96.47919, -4250.831, 51.99809),
(@PATH, 11, -83.51179, -4242.018, 52.78401),
(@PATH, 12, -79.68057, -4223.967, 53.02843),
(@PATH, 13, -80.83832, -4204.425, 49.83477),
(@PATH, 14, -96.40952, -4201.509, 51.43105),
(@PATH, 15, -110.2647, -4210.503, 54.78075),
(@PATH, 16, -127.9433, -4229.995, 57.20447),
(@PATH, 17, -140.2861, -4234.015, 58.08995),
(@PATH, 18, -150.7756, -4251.957, 59.79196),
(@PATH, 19, -152.7972, -4264.302, 61.48151),
(@PATH, 20, -145.7213, -4275.718, 63.28702);
