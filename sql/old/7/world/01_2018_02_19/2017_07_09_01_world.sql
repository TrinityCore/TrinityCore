-- Rohh the Silent Spawn Redridge Mountains
DELETE FROM `creature` WHERE `guid`=334934;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(334934, 947, 0, 0, 0, 1, 1, 169, 0, 0, -9124.02, -3233.616, 101.1988, 2.460914, 3600, 0, 0, 0, 0, 0, 0, 0, 0, 24015);
DELETE FROM `creature_addon` WHERE `guid`=334934;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (334934,0,0,131072,1,0, '22766');
-- Remove more overspawns in Redridge Mountains
DELETE FROM `creature` WHERE `guid` IN (334803,334745,334730,334933,45824,45825,334651,334653,334654);
DELETE FROM `creature_addon` WHERE `guid` IN (334803,334745,334730,334933,45824,45825,334651,334653,334654);
