-- 
DELETE FROM `creature` WHERE `guid` IN (52762, 52763, 52764, 52765, 77804);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `curhealth`, `curmana`, `MovementType`) VALUES 
(52762, 21636, 530, 1, 0, -3049.0556, 4495.867, -42.944, 6.090739, 600, 0, 5914, 0, 0),
(52763, 21636, 530, 1, 0, -2980.0466, 4363.27, -49.227, 1.616328, 600, 0, 5914, 0, 0),
(52764, 21636, 530, 1, 0, -2961.9802, 4363.849, -49.227, 1.886506, 600, 0, 5914, 0, 0),
(52765, 21636, 530, 1, 0, -2962.7990, 4378.178, -49.227, 3.089739, 600, 0, 5914, 0, 0),
(77804, 21636, 530, 1, 0, -2981.7517, 4378.619, -49.227, 6.209339, 600, 0, 5914, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry`=21636;
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(21636, 0, 0, 0, 1, 0, '17327');
