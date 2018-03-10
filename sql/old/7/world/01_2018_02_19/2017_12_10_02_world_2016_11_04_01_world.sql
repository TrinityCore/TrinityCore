-- 
DELETE FROM `creature` WHERE `guid` IN (1070, 1115, 1158,121595,1162);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseID`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(1070, 31787, 571, 0, 0, 1, 0, 0, 0, 6016.53, 2052.48, 636.058, 5.23599, 300, 0, 0, 12175, 3893, 0, 0, 0, 0, 0),
(1115, 31787, 571, 0, 0, 1, 0, 0, 0, 6110.05, 2330.27, 636.336, 0.575959, 300, 0, 0, 12175, 3893, 0, 0, 0, 0, 0),
(1158, 31787, 571, 0, 0, 1, 0, 0, 0, 6121.4, 2309.11, 636.225, 0.575959, 300, 0, 0, 12175, 3893, 0, 0, 0, 0, 0),
(121595, 31787, 571, 0, 0, 1, 0, 0, 0, 5952.47, 2197.624, 636.041, 5.23587, 300, 0, 0, 12175, 3893, 0, 0, 0, 0, 0),
(1162, 31787, 571, 0, 0, 1, 0, 0, 0, 5990.604, 2116.24, 636.041, 1.876254, 300, 0, 0, 12175, 3893, 0, 0, 0, 0, 0);

UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (31787);
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id`=31787);
 
DELETE FROM `creature_template_addon` WHERE `entry` = 31787;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`emote`) VALUES (31787,50331648,1,429);
