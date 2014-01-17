-- Spawn Blackened Urn (194092) GO based on sniff by Aokromes
SET @GUID := 334; -- Set by TDB team

DELETE FROM `gameobject` WHERE `id`=194092;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(@GUID,194092,532,1,1,-11126.87,-1874.455,91.47264,6.056293,0,0,-0.113203,0.9935719,180,100,1);
