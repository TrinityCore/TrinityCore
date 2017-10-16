-- 
DELETE FROM `creature` WHERE `guid` IN (36898);
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(36898, 15214, 585, 0, 0, 3, 1, 0, 0, 233.9639, 0.211427, -2.97703, 6.21302, 300, 0, 0, 0, 0, 0, 0, 0, 0, 0);
DELETE FROM `creature_addon` WHERE `guid`=36898;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (36898,0,0,0,0,0, '32567 45801');
UPDATE  `creature` SET `orientation`=5.648 WHERE `guid` IN (96825);
UPDATE  `creature` SET `orientation`=1.10716 WHERE `guid` IN (96830);
UPDATE `waypoint_data` SET `orientation`=5.648 WHERE `id` IN (968250);
UPDATE `waypoint_data` SET `orientation`=1.107 WHERE `id` IN (968300);
