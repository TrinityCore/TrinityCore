-- 
UPDATE `creature` SET `phaseMask`=64 WHERE `id` IN (32617,32619,32620,32623,32625);
DELETE FROM `creature` WHERE `guid` IN (120544, 120545, 120555, 120591, 120597);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(120544, 32616, 571, 0, 0, 1, 128, 0, 0, 5415.12, 2811.42, 418.758, 2.32129, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(120545, 32618, 571, 0, 0, 1, 128, 0, 0, 5467.56, 2810.08, 418.758, 0.837758, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(120555, 32621, 571, 0, 0, 1, 128, 0, 0, 5407.84, 2819.29, 418.676, 0.471239, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(120591, 32622, 571, 0, 0, 1, 128, 0, 0, 5468.27, 2871.14, 418.758, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(120597, 32624, 571, 0, 0, 1, 128, 0, 0, 5476.1, 2818.04, 418.758, 4.38078, 120, 0, 0, 0, 0, 0, 0, 0, 0, 0);
