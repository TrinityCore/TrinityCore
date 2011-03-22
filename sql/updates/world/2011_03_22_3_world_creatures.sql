SET @GUID :=48304;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+6;
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`)
VALUES
(@GUID,33233,603,1,1,0,0,560.1334,-143.035431,393.822632,0,120,0,0,1,0,0,0),
(@GUID+1,33233,603,1,1,0,0,572.410645,-138.656357,393.904419,0,120,0,0,1,0,0,0),
(@GUID+2,33233,603,1,1,0,0,585.9284,-146.587509,391.6004,0,120,0,0,1,0,0,0),
(@GUID+3,33233,603,1,1,0,0,589.7287,-137.1148,393.9011,0,120,0,0,1,0,0,0),
(@GUID+4,33233,603,1,1,0,0,605.9284,-140.108887,393.7972,0,120,0,0,1,0,0,0),
(@GUID+5,33233,603,1,1,0,0,630.2436,-276.259064,392.3122,0,120,0,0,1,0,0,0),
(@GUID+6,33233,603,1,1,0,0,638.241638,-272.1735,392.135132,0,120,0,0,1,0,0,0);
