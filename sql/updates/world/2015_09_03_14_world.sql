--
DELETE FROM `creature` WHERE `guid` IN (203441,203442,203443,203444,203445) AND `id`=31401;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(203441, 31401, 571, 0, 0, 1, 1, 0, 1, 5326.96, 579.806, 221.1, 5.53269, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(203442, 31401, 571, 0, 0, 1, 1, 0, 1, 5327.01, 555.268, 221.1, 0.680678, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(203443, 31401, 571, 0, 0, 1, 1, 0, 1, 5351.54, 580.027, 221.1, 4.11898, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(203444, 31401, 571, 0, 0, 1, 1, 0, 1, 5351.66, 555.277, 221.1, 2.46091, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0),
(203445, 31401, 571, 0, 0, 1, 1, 0, 1, 5397.29, 624.991, 248.94, 0.383972, 120, 0, 0, 1, 0, 0, 0, 0, 0, 0);
