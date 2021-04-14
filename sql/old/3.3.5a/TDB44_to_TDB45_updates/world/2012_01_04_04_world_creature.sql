-- fix earlier typo in guid (recovered 1846)
DELETE FROM `creature` WHERE `guid` = 1864;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(1864,1096,0,1,1,7197,0,-11958.5,-484.88,17.0796,5.15875,300,0,0,1160,1067,0);

DELETE FROM `creature_addon` WHERE `guid`=1864;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(1864,0,0,0,4097,0,'');


