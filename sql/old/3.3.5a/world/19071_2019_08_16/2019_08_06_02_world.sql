-- 
DELETE FROM `creature` WHERE `id` IN (30320);
DELETE FROM `creature` WHERE `guid` IN (116700, 116701, 116702, 116703, 116704, 116710) AND `id` IN (30320);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(116700, 30320, 571, 0, 0, 1, 4, 0, 0, 7425.16, -2497.86, 753.114, 1.58701, 300, 5, 0, 0, 0, 1, 0, 0, 0, 0),
(116701, 30320, 571, 0, 0, 1, 4, 0, 0, 7401.15, -2484.09, 749.789, 3.82183, 300, 5, 0, 0, 0, 1, 0, 0, 0, 0),
(116702, 30320, 571, 0, 0, 1, 4, 0, 0, 7271.1, -2476.58, 755.902, 1.396970, 300, 5, 0, 0, 0, 1, 0, 0, 0, 0),
(116703, 30320, 571, 0, 0, 1, 4, 0, 0, 7396.38, -2514.13, 749.585, 4.52841, 300, 5, 0, 0, 0, 1, 0, 0, 0, 0),
(116704, 30320, 571, 0, 0, 1, 4, 0, 0, 7330.22, -2526.83, 748.825, 4.41848, 300, 5, 0, 0, 0, 1, 0, 0, 0, 0),
(116710, 30320, 571, 0, 0, 1, 4, 0, 0, 7339.37, -2495.46, 749.44, 4.708030, 300, 5, 0, 0, 0, 1, 0, 0, 0, 0);
