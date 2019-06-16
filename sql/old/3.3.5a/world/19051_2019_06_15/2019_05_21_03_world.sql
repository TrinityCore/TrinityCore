-- 
DELETE FROM `creature` WHERE `guid`=105354 AND `id`=20359;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(105354, 20359, 560, 0, 0, 3, 1, 0, 0, 1911.3525, 1080.2274, 21.6609, 4.134215, 300, 0, 0, 115, 126, 0, 0, 0, 0, 0);
UPDATE `creature` SET `position_x`=1910.961426, `position_y`=1077.719971, `position_z`=21.876644, `orientation`=1.101913 WHERE `guid`=84017; 
UPDATE `creature` SET `position_x`=1909.114502, `position_y`=1079.315918, `position_z`=21.995821, `orientation`=0.342432 WHERE `guid`=84016; 
