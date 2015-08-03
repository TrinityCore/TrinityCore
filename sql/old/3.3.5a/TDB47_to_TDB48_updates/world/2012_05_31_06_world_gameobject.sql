-- Add Missing Draconic for Dummies Objects
SET @GUID := 4595;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @GUID AND @GUID+2;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID,180665,0,1,1,-8340.196,413.7499,124.489677,2.82742977,0,0,0.987688,0.156436,180,255,1),
(@GUID+1,180666,0,1,1,1628.83984,133.9376,-60.96726,-0.401424885,0,0,-0.199368,0.979925,180,255,1),
(@GUID+2,180667,469,1,1,-7526.57,-924.776,458.826,0.558504,0,0,0.275637,0.961262,180,255,1);
