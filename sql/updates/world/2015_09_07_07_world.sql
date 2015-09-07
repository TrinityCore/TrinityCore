-- Felwood (Zone 361) Purple Lotus spawns
SET @LASTGUID := 22;
SET @OGUID    := 234878; 
SET @MOTHER   := 36102;
SET @ACTIVE   := 8;      -- Max number of active spawns
SET @TIMER    := 30;     -- Respawn timer in seconds
-- Purple Lotus spawns for Felwood
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+@LASTGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0,142140,1,1,1,0,5763.727,-765.2587,387.5924,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+1,142140,1,1,1,0,5413.335,-592.3403,354.6357,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+2,142140,1,1,1,0,4410.54,-577.503,266.131,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+3,142140,1,1,1,0,4510.623,-502.9323,302.3309,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+4,142140,1,1,1,0,4570.439,-508.8316,296.6697,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+5,142140,1,1,1,0,4571.208,-378.382,302.4196,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+6,142140,1,1,1,0,5791.531,-770.9254,391.8307,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+7,142140,1,1,1,0,6023.485,-1178.318,374.0818,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+8,142140,1,1,1,0,5943.244,-1229.45,382.2765,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+9,142140,1,1,1,0,4582.349,-475.717,303.4381,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+10,142140,1,1,1,0,3773.559,-1606.056,219.0923,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+11,142140,1,1,1,0,3783.984,-1699.453,258.1099,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+12,142140,1,1,1,0,5979.635,-1254.898,379.3692,6.0912,0,0,0,1, @TIMER, 255, 1),
(@OGUID+13,142140,1,1,1,0,4490.813,-502.7396,303.2567,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+14,142140,1,1,1,0,5786.944,-752.4479,387.9584,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+15,142140,1,1,1,0,4581.618,-472.2639,304.4182,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+16,142140,1,1,1,0,5438.983,-598.691,353.794,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+17,142140,1,1,1,0,4605.38,-503.408,296.6791,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+18,142140,1,1,1,0,4477.104,-557.4861,288.8598,1.850049,0,0,0,1, @TIMER, 255, 1),
(@OGUID+19,142140,1,1,1,0,5412.854,-607.8924,354.2633,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+20,142140,1,1,1,0,5775.338,-782.5955,391.1731,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+21,142140,1,1,1,0,3820.87,-1614.132,222.9598,0,0,0,0,1, @TIMER, 255, 1),
(@OGUID+22,142140,1,1,1,0,6020.882,-1157.257,378.1629,0,0,0,0,1, @TIMER, 255, 1);

-- Add mother pool to pool template
DELETE FROM `pool_template` WHERE `entry`=@MOTHER;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@MOTHER,@ACTIVE, 'Felwood Purple Lotus Mother pool');

-- Pool Purple lotus Spawnpoints
DELETE FROM `pool_gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+@LASTGUID;
INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(@OGUID+0,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+1,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+2,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+3,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+4,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+5,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+6,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+7,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+8,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+9,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+10,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+11,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+12,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+13,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+14,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+15,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+16,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+17,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+18,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+19,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+20,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+21,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint'),
(@OGUID+22,@MOTHER,0, 'Felwood Purple Lotus Spawnpoint');
