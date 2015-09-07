-- Felwood (Zone 361) Dreamfoil spawns
SET @LASTGUID := 35;
SET @OGUID    := 234901; 
SET @MOTHER   := 36103;
SET @ACTIVE   := 14;     -- Max number of active spawns
SET @TIMER    := 30;     -- Respawn timer in seconds
-- Dreamfoil spawns for Felwood
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+@LASTGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0,176584,1,1,1,0,3865.57,-1046.15,247.336,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+1,176584,1,1,1,0,3700.62,-1186.99,208.13,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+2,176584,1,1,1,0,3586.38,-1146.28,219.939,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+3,176584,1,1,1,0,3678.47,-1017.09,224.188,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+4,176584,1,1,1,0,3979.42,-893.372,268.279,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+5,176584,1,1,1,0,4041.43,-921.87,256.878,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+6,176584,1,1,1,0,3805.02,-749.884,322.543,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+7,176584,1,1,1,0,3949.8,-1052.18,249.246,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+8,176584,1,1,1,0,3800.53,-1371.68,202.24,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+9,176584,1,1,1,0,4256.24,-776.979,262.738,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+10,176584,1,1,1,0,4010.97,-567.955,337.562,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+11,176584,1,1,1,0,5493.3,-921.868,363.531,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+12,176584,1,1,1,0,5671.03,-905.542,379.026,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+13,176584,1,1,1,0,5697.67,-832.205,381.739,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+14,176584,1,1,1,0,6402.12,-1483.1,440.596,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+15,176584,1,1,1,0,6528.81,-1452.71,439.227,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+16,176584,1,1,1,0,6654.21,-1948.33,549.592,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+17,176584,1,1,1,0,6720.35,-1882.56,549.814,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+18,176584,1,1,1,0,6906.41,-1882.52,569.043,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+19,176584,1,1,1,0,3939.77,-911.8,268.716,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+20,176584,1,1,1,0,3908.64,-1030.79,247.034,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+21,176584,1,1,1,0,6881.99,-1599.02,498.766,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+22,176584,1,1,1,0,3734.22,-1036.64,226.422,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+23,176584,1,1,1,0,3956.57,-596.193,340.313,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+24,176584,1,1,1,0,6501.64,-1493.57,440.36,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+25,176584,1,1,1,0,3746.67,-1247.57,209.393,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+26,176584,1,1,1,0,6906.09,-1825.46,569.449,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+27,176584,1,1,1,0,6557.53,-1315.2,439.583,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+28,176584,1,1,1,0,3817.45,-1452.38,208.074,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+29,176584,1,1,1,0,6293.14,-1651.14,479.565,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+30,176584,1,1,1,0,6697.98,-1983.71,560.364,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+31,176584,1,1,1,0,3626.37,-1060.27,219.535,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+32,176584,1,1,1,0,4071.1,-743.139,282.596,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+33,176584,1,1,1,0,3552.56,-1100.48,219.524,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+34,176584,1,1,1,0,6604.7,-1891.19,544.602,4.380776,0,0,0,1, @TIMER, 255, 1),
(@OGUID+35,176584,1,1,1,0,6799.43,-1864.51,550.92,4.380776,0,0,0,1, @TIMER, 255, 1);

-- Add mother pool to pool template
DELETE FROM `pool_template` WHERE `entry`=@MOTHER;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@MOTHER,@ACTIVE, 'Felwood Dreamfoil Mother pool');

-- Pool Dreamfoil Spawnpoints
DELETE FROM `pool_gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+@LASTGUID;
INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(@OGUID+0,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+1,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+2,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+3,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+4,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+5,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+6,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+7,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+8,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+9,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+10,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+11,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+12,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+13,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+14,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+15,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+16,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+17,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+18,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+19,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+20,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+21,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+22,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+23,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+24,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+25,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+26,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+27,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+28,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+29,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+30,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+31,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+32,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+33,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+34,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint'),
(@OGUID+35,@MOTHER,0, 'Felwood Dreamfoil Spawnpoint');
