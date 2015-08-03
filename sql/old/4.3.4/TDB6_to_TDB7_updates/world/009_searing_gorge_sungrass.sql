-- Searing Gorge Sungrass herb spawns
SET @OGUID    := 225675;
SET @MOTHER   := 5103;
SET @LASTGUID := 38;
SET @ACTIVE   := 10; -- Max number of active spawns
SET @TIMER    := 30; -- Respawn timer in seconds

-- Sungrass spawns for Searing Gorge
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+@LASTGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 142142, 0, 1, 1, 0, -6488.46, -1983.53, 245.561, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+1, 142142, 0, 1, 1, 0, -7165.82, -1725.36, 244.418, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+2, 142142, 0, 1, 1, 0, -6897.78, -1657.34, 244.887, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+3, 142142, 0, 1, 1, 0, -6682.21, -1600.56, 240.013, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+4, 142142, 0, 1, 1, 0, -6598.1, -1561.9, 272.75, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+5, 142142, 0, 1, 1, 0, -7175.13, -1528.78, 242.017, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+6, 142142, 0, 1, 1, 0, -6678.16, -1532.83, 242.345, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+7, 142142, 0, 1, 1, 0, -6749.29, -1355.85, 241.973, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+8, 142142, 0, 1, 1, 0, -7050.66, -1071.32, 241.667, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+9, 142142, 0, 1, 1, 0, -6836.75, -947.476, 241.12, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+10, 142142, 0, 1, 1, 0, -6825.69, -1031.18, 242.904, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+11, 142142, 0, 1, 1, 0, -6945.42, -1763.82, 241.667, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+12, 142142, 0, 1, 1, 0, -7181.3, -1650.17, 241.675, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+13, 142142, 0, 1, 1, 0, -7163.64, -1477.69, 244.141, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+14, 142142, 0, 1, 1, 0, -6577.83, -1876.26, 245.112, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+15, 142142, 0, 1, 1, 0, -6640.62, -1687.83, 259.912, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+16, 142142, 0, 1, 1, 0, -6605.99, -1497.52, 270.985, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+17, 142142, 0, 1, 1, 0, -6657.49, -1524.34, 245.075, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+18, 142142, 0, 1, 1, 0, -6731.03, -1400.56, 241.43, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+19, 142142, 0, 1, 1, 0, -7100.76, -1075.07, 241.861, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+20, 142142, 0, 1, 1, 0, -6924.08, -1713.59, 241.623, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+21, 142142, 0, 1, 1, 0, -6695, -1490.66, 241.691, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+22, 142142, 0, 1, 1, 0, -7126.3, -1474.8, 243.117, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+23, 142142, 0, 1, 1, 0, -7220.56, -1770.41, 244.265, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+24, 142142, 0, 1, 1, 0, -6881.99, -1724.36, 241.331, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+25, 142142, 0, 1, 1, 0, -6548.66, -1952.09, 246.079, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+26, 142142, 0, 1, 1, 0, -6628.37, -1592.54, 250.342, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+27, 142142, 0, 1, 1, 0, -7091.21, -1035.07, 240.303, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+28, 142142, 0, 1, 1, 0, -7223.13, -1719.13, 242.301, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+29, 142142, 0, 1, 1, 0, -6689.39, -1385.89, 240.544, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+30, 142142, 0, 1, 1, 0, -6787.19, -951.471, 241.044, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+31, 142142, 0, 1, 1, 0, -6604.85, -1451.49, 266.117, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+32, 142142, 0, 1, 1, 0, -6659.13, -1394.77, 242.71, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+33, 142142, 0, 1, 1, 0, -7087.63, -1099.26, 248.753, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+34, 142142, 0, 1, 1, 0, -6608.75, -1896.15, 245.117, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+35, 142142, 0, 1, 1, 0, -7095.25, -1514.37, 242.422, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+36, 142142, 0, 1, 1, 0, -6679.11, -1452.7, 242.124, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+37, 142142, 0, 1, 1, 0, -6851.63, -993.259, 240.569, 0, 0, 0, 0, 1, @TIMER, 255, 1), -- Sungrass
(@OGUID+38, 142142, 0, 1, 1, 0, -6616.93, -1426.98, 265.773, 0, 0, 0, 0, 1, @TIMER, 255, 1); -- Sungrass

-- Add mother pool to pool template
DELETE FROM `pool_template` WHERE `entry`=@MOTHER;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@MOTHER,@ACTIVE, 'Searing Gorge Sungrass Mother pool');

-- Pool Sungrass Spawnpoints
DELETE FROM `pool_gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+@LASTGUID;
INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(@OGUID+0,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+1,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+2,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+3,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+4,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+5,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+6,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+7,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+8,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+9,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+10,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+11,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+12,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+13,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+14,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+15,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+16,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+17,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+18,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+19,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+20,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+21,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+22,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+23,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+24,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+25,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+26,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+27,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+28,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+29,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+30,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+31,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+32,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+33,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+34,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+35,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+36,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+37,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint'),
(@OGUID+38,@MOTHER,0, 'Searing Gorge Sungrass Spawnpoint');
