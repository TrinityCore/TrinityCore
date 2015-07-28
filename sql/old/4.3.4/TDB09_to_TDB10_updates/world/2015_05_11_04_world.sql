-- 
-- ONLY UPDATE FOR WOTLK 3.X - no cherrypick to 4.x, 5.x, 6.x
/*
SET @GUID := 6245; -- Set by TDB team (4)
SET @POOL := 202482; -- Set by TDB team (1)

DELETE FROM `gameobject` WHERE `id`=202083 AND `guid` BETWEEN @GUID+0 AND @GUID+3;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
-- https://github.com/TrinityCore/TrinityCore/commit/205cb06df9c3535e186b2e7fae10c72ab5de9e3c
(@GUID+0,202083,0,1,1,-2944.48,-3277.68,62.27,3.32798,0,0,0.995661,-0.093059,18000,100,1),
-- https://www.youtube.com/watch?v=c1Dz_-ycIuU#t=124s
(@GUID+1,202083,0,1,1,-3000.93,-3329.01,64.9771,4.10851,0,0,0.885393,-0.464843,18000,100,1),
-- https://www.youtube.com/watch?v=yWSvwdNHspY#t=30s , https://www.youtube.com/watch?v=c1Dz_-ycIuU#t=95s
(@GUID+2,202083,0,1,1,-3020.76,-3245.81,58.8009,5.38478,0,0,0.434249,-0.900793,18000,100,1),
-- https://www.youtube.com/watch?v=f0rCteF0Ras#t=200s , https://www.youtube.com/watch?v=yWSvwdNHspY#t=30s
(@GUID+3,202083,0,1,1,-2992.36,-3188.19,55.1982,3.01524,0,0,0.998005,0.0631367,18000,100,1);

DELETE FROM `pool_template` WHERE `entry`=@POOL;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@POOL,1,"Razormaw Matriarch's Nest (202083)");

DELETE FROM `pool_gameobject` WHERE `guid` IN (14999, @GUID+0, @GUID+1, @GUID+2, @GUID+3);
INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(14999,@POOL,25,"Razormaw Matriarch's Nest (202083) P1"),
(@GUID+0,@POOL,25,"Razormaw Matriarch's Nest (202083) P2"),
(@GUID+1,@POOL,25,"Razormaw Matriarch's Nest (202083) P3"),
(@GUID+2,@POOL,25,"Razormaw Matriarch's Nest (202083) P4");
*/
