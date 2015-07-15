-- 
DELETE FROM `creature` WHERE `guid` IN (45823, 45824, 45825, 45826);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(45823, 3855, 33, 0, 0, 1, 1, 657, 0, -194.644, 2289.77, 95.899, 2.57587, 7200, 3, 0, 1212, 912, 1, 0, 0, 0, 0),
(45824, 446, 0, 0, 0, 1, 1, 609, 1, -8936.93, -2315.47, 132.649, 3.19395, 300, 0, 0, 417, 0, 0, 0, 0, 0, 0),
(45825, 446, 0, 0, 0, 1, 1, 609, 1, -8947.99, -2335.42, 132.569, 4.33752, 300, 3, 0, 417, 0, 1, 0, 0, 0, 0),
(45826, 430, 0, 0, 0, 1, 1, 10789, 1, -9096.31, -2380.26, 123.354, 3.48563, 300, 5, 0, 354, 1020, 1, 0, 0, 0, 0);
 
DELETE FROM `creature_addon` WHERE `guid` IN (45823, 45824, 45825, 45826);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(45823, 0, 0, 0, 4097, 0, ''),
(45824, 0, 0, 0, 4097, 0, ''),
(45825, 0, 0, 0, 4097, 0, ''),
(45826, 0, 0, 0, 4097, 0, '');
