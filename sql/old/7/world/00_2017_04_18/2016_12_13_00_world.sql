-- add Spirit Healer to 5 starter areas:
SET @CGUID := 452536; -- 5 free GUIDs from TDB 703.00

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+5;
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`PhaseId`,`PhaseGroup`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`VerifiedBuild`) VALUES
(@CGUID+0, 6491,  0,0,0,1,1,0,0,0, -8946.229, -183.4772, 79.99528, 5.88176,  120,0,0,0,0,0,0,0,0,23222), -- Northshire Valley, Elwynn Forest
(@CGUID+1, 6491,  0,0,0,1,1,0,0,0, -6169.814,  346.8438, 400.1516, 5.27905,  120,0,0,0,0,0,0,0,0,23222), -- Coldridge Valley, Dun Morogh
(@CGUID+2, 6491,  1,0,0,1,1,0,0,0,  10391.85,  826.4149, 1317.602, 4.118977, 120,0,0,0,0,0,0,0,0,23222), -- Aldrassil, Teldrassil
(@CGUID+3, 6491,  1,0,0,1,1,0,0,0, -637.971,  -4295.86,  40.90933, 1.169371, 120,0,0,0,0,0,0,0,0,23222), -- Valley of Trials, Durotar
(@CGUID+4, 6491,  1,0,0,1,1,0,0,0, -1039.63,  -5416.73,  13.37213, 3.141593, 120,0,0,0,0,0,0,0,0,23222); -- Echo Isles, Durotar

UPDATE `creature` SET `PhaseId`= 1 WHERE `guid`= 351326 AND `ID`= 39660; -- KTC Headquarters GY, Kezan

-- set correct GhostZone info for current starter zones:
UPDATE `graveyard_zone` SET `GhostZone`= 6176 WHERE `ID`= 100; -- Dun Morogh, Anvilmar GY
UPDATE `graveyard_zone` SET `GhostZone`= 6450 WHERE `ID`= 93; -- Teldrassil, Aldrassil GY
UPDATE `graveyard_zone` SET `GhostZone`= 6452 WHERE `ID`= 34; -- Mulgore, Red Cloud Mesa GY
UPDATE `graveyard_zone` SET `GhostZone`= 6453, `Faction`= 67 WHERE `ID`= 1700; -- Durotar, Echo Isles GY
UPDATE `graveyard_zone` SET `GhostZone`= 6454 WHERE `ID`= 94; -- Tirisfal Glades, Deathknell GY
UPDATE `graveyard_zone` SET `GhostZone`= 6455, `Faction`= 67 WHERE `ID`= 912; -- Eversong Woods, Sunstrider Isle
UPDATE `graveyard_zone` SET `Faction`= 67 WHERE `ID`= 1689; -- Kezan - KTC Headquarters GY
UPDATE `graveyard_zone` SET `Faction`= 67, `Comment`= "Eversong Woods, Farstrider Retreat GY - Eversong Woods" WHERE `ID`= 914;
--
