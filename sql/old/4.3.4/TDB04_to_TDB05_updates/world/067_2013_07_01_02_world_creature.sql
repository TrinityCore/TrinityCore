DELETE FROM `creature` WHERE `guid` IN (44456,45095,40507,40508);
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(44456,9197,229,1,1,0,0,-40.63613,-372.2156,50.56116,0.8552113,10800,5,0,1,0,1),
(45095,9197,229,1,1,0,0,-22.85546,-377.8695,49.04873,6.161012,10800,5,0,1,0,1),
(40507,9216,229,1,1,0,0,-44.31393,-364.7873,52.05709,1.832596,10800,5,0,1,0,1),
(40508,9216,229,1,1,0,0,-16.89405,-385.1013,48.95151,0.5934119,10800,5,0,1,0,1);
