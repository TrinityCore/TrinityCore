-- 
UPDATE `creature_template` SET `InhabitType`=12 WHERE `entry` =43999;
DELETE FROM `creature` WHERE `guid`=252295;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`) VALUES
(252295, 43999, 671, 0, 0, 15, 169, 0, 0, 0, -1161.88, -798.63, 835.117, 0, 7200, 0, 0, 154980);
