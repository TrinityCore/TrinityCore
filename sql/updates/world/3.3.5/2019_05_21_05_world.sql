-- 
DELETE FROM `creature` WHERE `guid` IN (105477)  AND `id`=20417;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(105477, 20417, 530, 0, 0, 1, 1, 0, 0, 2421.398, 2756.137, 135.6086, 6.073746, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);
UPDATE `gameobject` SET `rotation0`=0.392848, `rotation1`=0.587938, `rotation2`=0.587938,`rotation3`=0.392847, `state`=0 WHERE `guid`=25023; 
UPDATE `gameobject` SET `rotation0`=0.150033, `rotation1`=0.691007, `rotation2`=0.691007,`rotation3`=0.150032, `state`=0 WHERE `guid`=25024; 
UPDATE `gameobject` SET `rotation0`=0.591052, `rotation1`=-0.38814, `rotation2`=-0.38814,`rotation3`=0.591051, `state`=0 WHERE `guid`=25025; 
UPDATE `gameobject` SET `rotation0`=0.557208, `rotation1`=0.435338, `rotation2`=0.435338,`rotation3`=0.557208, `state`=0 WHERE `guid`=25026; 
