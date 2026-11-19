--
UPDATE `creature_template` SET `ScriptName`="npc_wg_guard" WHERE `entry` IN (30739, 30740);

SET @GUID := 94920;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+17;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@GUID   , 30739, 571, 0, 0, 1, 175, 0, 1, 5150.27, 2786.02, 409.547, 3.22886, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+1 , 30739, 571, 0, 0, 1, 175, 0, 1, 5150.66, 2777.95, 409.405, 2.94961, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+2 , 30739, 571, 0, 0, 1, 175, 0, 1, 5193.63, 2734.17, 409.273, 4.69494, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+3 , 30739, 571, 0, 0, 1, 175, 0, 1, 5200.5, 2733.89, 409.273, 4.67748, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+4 , 30739, 571, 0, 0, 1, 175, 0, 1, 5264.65, 2670.19, 409.182, 3.07178, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+5 , 30739, 571, 0, 0, 1, 175, 0, 1, 5265.31, 2663.15, 409.182, 3.12414, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+6 , 30739, 571, 0, 0, 1, 175, 0, 1, 5307.02, 2613.9, 409.172, 4.69494, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+7 , 30739, 571, 0, 0, 1, 175, 0, 1, 5311.13, 3061.04, 408.81, 1.50098, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+8 , 30739, 571, 0, 0, 1, 175, 0, 1, 5315.87, 2614.22, 408.973, 4.67748, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+9 , 30739, 571, 0, 0, 1, 175, 0, 1, 5318.09, 3060.63, 408.883, 1.62316, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+10, 30739, 571, 0, 0, 1, 175, 0, 1, 5149.4, 2897.04, 409.304, 3.03687, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+11, 30739, 571, 0, 0, 1, 175, 0, 1, 5149.52, 2904.19, 409.276, 3.07178, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+12, 30739, 571, 0, 0, 1, 175, 0, 1, 5192.79, 2948.45, 409.275, 1.50098, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+13, 30739, 571, 0, 0, 1, 175, 0, 1, 5201.65, 2948.78, 409.275, 1.62316, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+14, 30739, 571, 0, 0, 1, 175, 0, 1, 5265.28, 3010.1, 408.896, 2.82743, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+15, 30739, 571, 0, 0, 1, 175, 0, 1, 5265.48, 3017.4, 408.583, 3.07178, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+16, 30739, 571, 0, 0, 1, 175, 0, 1, 5154.23, 2833.82, 409.262, 3.12414, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0),
(@GUID+17, 30739, 571, 0, 0, 1, 175, 0, 1, 5154.12, 2847.89, 409.248, 3.07178, 180, 0, 0, 11001, 0, 0, 0, 0, 0, 0);

UPDATE `creature` SET `curhealth`=11001, `spawntimesecs`=180 WHERE `id` IN (30739, 30740);
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` IN (30739, 30740));

UPDATE `creature` SET `position_x`=5307.75, `position_y`=3008.87, `position_z`=409.193, `orientation`=4.78168 WHERE `guid`=131266;
UPDATE `creature` SET `PhaseId`=175, `modelid`=0, `spawndist`=0, `MovementType`=0 WHERE `guid` IN (131261, 131266, 131258, 131262, 131259, 131260, 131269, 131264, 131839, 131267, 131263);

DELETE FROM `creature` WHERE `guid`=12548;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(12548, 15351, 571, 0, 0, 1, 176, 15389, 0, 5467.59, 2841.06, 418.758, 1.39626, 180, 0, 0, 126000, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (131839, 12548);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(131839, 0, 0, 0, 257, 0, ""),
(12548, 0, 0, 0, 257, 0, "");
