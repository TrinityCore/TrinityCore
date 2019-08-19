-- 
UPDATE `creature` SET `position_x`=687.612061, `position_y`=-3833.748535, `position_z`=249.323883 WHERE `guid`=132537 AND `id`=23804;

DELETE FROM `creature` WHERE `guid`=111427 AND `id`=24884;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`,  `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(111427, 24884,571,1,1,0,685.137, -3833.74, 249.413, 4.85202,180,0,0);

DELETE FROM `creature_addon` WHERE `guid` IN (111427);
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes1`, `bytes2`, `auras`) VALUES
(111427,0,1,1,"");
