-- 
UPDATE `creature` SET `position_x`=4596.64, `position_y`=-5691.18, `position_z`=183.133, `orientation`=4.63763 WHERE `guid`= 109382;
UPDATE `creature` SET `position_x`=4608.88, `position_y`=-5706.52, `position_z`=183.029, `orientation`=3.25691 WHERE `guid`= 109383;
UPDATE `creature` SET `position_x`=4585.63, `position_y`=-5700.52, `position_z`=155.355, `orientation`=4.26387 WHERE `guid`= 109384;
UPDATE `creature` SET `position_x`=4606.12, `position_y`=-5697.23, `position_z`=183.111, `orientation`=3.92763 WHERE `guid`= 109390;
UPDATE `creature` SET `position_x`=4588.61, `position_y`=-5683.01, `position_z`=126.053, `orientation`=5.82758 WHERE `guid`= 109403;
UPDATE `creature` SET `position_x`=4599.43, `position_y`=-5707.74, `position_z`=155.169, `orientation`=4.38449 WHERE `guid`= 109405;
UPDATE `creature` SET `position_x`=4589.81, `position_y`=-5703.59, `position_z`=184.507, `orientation`=4.61573 WHERE `guid`= 109406;
UPDATE `creature` SET `position_x`=4597.47, `position_y`=-5697.71, `position_z`=184.591, `orientation`=4.31096 WHERE `guid`= 109407;
UPDATE `creature` SET `position_x`=4623.16, `position_y`=-5699.11, `position_z`=144.509, `orientation`=0.99815 WHERE `guid`= 109408;
UPDATE `creature` SET `position_x`=4598.15, `position_y`=-5705.81, `position_z`=184.591, `orientation`=4.10152 WHERE `guid`= 109409;

DELETE FROM `creature_addon` WHERE `guid` IN (109382, 109383, 109384, 109390, 109403, 109405, 109406, 109407, 109408, 109409);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) values
(109382,0,0,8,0,0,""),
(109383,0,0,8,0,0,""),
(109390,0,0,8,0,0,""),
(109406,0,0,8,0,0,""),
(109407,0,0,8,0,0,""),
(109409,0,0,8,0,0,"");
