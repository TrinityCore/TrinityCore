-- 
DELETE FROM `creature` WHERE `guid` IN (105360,105429)  AND `id`=20391;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(105360, 20391, 560, 0, 0, 3, 1, 0, 0, 1736.54, 1073.2, 6.96295, 2.18166, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(105429, 20391, 560, 0, 0, 3, 1, 0, 0, 1815.18, 1035.5, 11.1722, 3.94444, 300, 0, 0, 1, 0, 0, 0, 0, 0, 0);
