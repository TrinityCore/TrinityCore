-- 
UPDATE `creature_template` SET `unit_flags`=33555200 WHERE `entry` IN (17302);
DELETE FROM `creature` WHERE `guid` IN (119118, 119119);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(119118, 17611, 540, 3714, 0, 3, 1, 0, 0, 336.7071, -84.05206, 1.992441, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 17611 (Area: 0 - Difficulty: 0)
(119119, 17302, 540, 3714, 0, 2, 1, 0, 0, 149.408, -83.94183, 2.01231, 1.117011, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 17302 (Area: 0 - Difficulty: 0)
