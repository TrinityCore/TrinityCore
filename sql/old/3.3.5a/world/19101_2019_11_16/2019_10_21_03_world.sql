-- 
DELETE FROM `creature` WHERE `guid` IN (117321,117322,117323,117365);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(117321, 31220, 571, 0, 0, 1, 1, 0, 0, 6067.22, 1892.13, 632.662, 3.45575, 300, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(117322, 31225, 571, 0, 0, 1, 2, 0, 0, 6027.64, 1921.29, 632.678, 4.34922, 300, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(117323, 31223, 571, 0, 0, 1, 2, 0, 0, 6472.73, 1722.66, 508.784, 5.91667, 300, 0, 0, 0, 0, 0, 0, 0, 0, 12340),
(117365, 31224, 571, 0, 0, 1, 2, 0, 0, 6564.38, 1613.81, 633.546, 1.66397, 300, 0, 0, 0, 0, 0, 0, 0, 0, 12340);
