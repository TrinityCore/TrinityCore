-- 
UPDATE `gameobject` SET `PhaseId`=0, `PhaseGroup`=370 WHERE `guid` IN (151102,151103,151104,151105,151106) AND `id` IN (202184,202347,202348,202349,202350);

DELETE FROM `gameobject` WHERE `guid`=151103;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(151103, 214539, 571, 210, 4862, '0', 0, 370, 5778.9140625, 2066.111083984375, 636.21966552734375, 0.451657503843307495, 0, 0, 0.223914146423339843, 0.974608898162841796, 120, 255, 1, 67823); -- Instance Portal (Raid 4 Difficulties)
