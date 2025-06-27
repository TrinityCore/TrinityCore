-- 
DELETE FROM `creature_template_addon` WHERE `entry`=17231;
INSERT INTO `creature_template_addon` (`entry`, `auras`) VALUES
(17231, "36151");
DELETE FROM `creature` WHERE `guid` IN (62799, 62800, 62801, 62802, 62803);
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`,`spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`) VALUES
(62799, 17231, 533, 3, 1, 0, 0, 2787.71, -3534.53, 250.242, 0.59341, 7200, 0, 0, 300, 0, 0),
(62800, 17231, 533, 3, 1, 0, 0, 2789.92, -3525.28, 250.242, 5.63741, 7200, 0, 0, 300, 0, 0),
(62801, 17231, 533, 3, 1, 0, 0, 2794.29, -3536.64, 250.242, 1.41372, 7200, 0, 0, 300, 0, 0),
(62802, 17231, 533, 3, 1, 0, 0, 2798.66, -3525.69, 250.242, 3.82227, 7200, 0, 0, 300, 0, 0),
(62803, 17231, 533, 3, 1, 0, 0, 2801.12, -3535.08, 250.242, 2.26893, 7200, 0, 0, 300, 0, 0);
