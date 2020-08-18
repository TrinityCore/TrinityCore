-- 
DELETE FROM `creature` WHERE `guid` IN (80435,80436);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(80435, 23512, 530, 0, 0, '0', 0, 0, 0, 1474.1, 7256.4, 375.19, 3.921138, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(80436, 23512, 530, 0, 0, '0', 0, 0, 0, 2948.5, 7076, 370.8263, 5.262608, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `creature_template_addon` WHERE `entry` = 23512;
INSERT INTO `creature_template_addon` (`entry`,`auras`) VALUES (23512, '35411');
