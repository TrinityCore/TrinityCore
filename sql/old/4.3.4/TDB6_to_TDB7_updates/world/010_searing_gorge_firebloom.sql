-- Searing Gorge Firebloom herb spawns
SET @OGUID    := 225715;
SET @MOTHER   := 5104;
SET @LASTGUID := 49;
SET @ACTIVE   := 12; -- Max number of active spawns
SET @TIMER    := 30; -- Respawn timer in seconds

-- Firebloom spawns for Searing Gorge
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+@LASTGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 2866, 0, 1, 1, 0, -6659.14, -1842.59, 247.085, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+1, 2866, 0, 1, 1, 0, -7048.58, -1656.77, 243.66, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+2, 2866, 0, 1, 1, 0, -6875.71, -1565.44, 243.821, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+3, 2866, 0, 1, 1, 0, -7009.74, -1439.22, 244.202, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+4, 2866, 0, 1, 1, 0, -6972.66, -1357.08, 244.95, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+5, 2866, 0, 1, 1, 0, -7180.14, -1271.44, 247.319, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+6, 2866, 0, 1, 1, 0, -6712.14, -1251.7, 241.247, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+7, 2866, 0, 1, 1, 0, -7180.8, -1158.43, 249.684, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+8, 2866, 0, 1, 1, 0, -6817.12, -1169.42, 239.921, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+9, 2866, 0, 1, 1, 0, -6930.11, -1018.18, 242.275, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+10, 2866, 0, 1, 1, 0, -7116.77, -993.476, 244.046, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+11, 2866, 0, 1, 1, 0, -6741.74, -959.188, 245.474, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+12, 2866, 0, 1, 1, 0, -6689.6, -1108.15, 241.181, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+13, 2866, 0, 1, 1, 0, -6772.61, -998.483, 241.88, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+14, 2866, 0, 1, 1, 0, -6989.7, -1029.35, 241.667, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+15, 2866, 0, 1, 1, 0, -7210.79, -1229.87, 253.407, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+16, 2866, 0, 1, 1, 0, -7056.43, -1339.28, 248.849, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+17, 2866, 0, 1, 1, 0, -6881.73, -1630.75, 243.319, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+18, 2866, 0, 1, 1, 0, -7130.93, -1563.1, 244.511, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+19, 2866, 0, 1, 1, 0, -7130.42, -1421.52, 242.608, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+20, 2866, 0, 1, 1, 0, -6777.54, -1758.12, 258.062, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+21, 2866, 0, 1, 1, 0, -6412.79, -1971.29, 249.047, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+22, 2866, 0, 1, 1, 0, -7176.45, -1022.8, 241.711, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+23, 2866, 0, 1, 1, 0, -6377.83, -1934.51, 259.662, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+24, 2866, 0, 1, 1, 0, -7120.95, -1120.47, 254.119, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+25, 2866, 0, 1, 1, 0, -6758.95, -1059.32, 240.024, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+26, 2866, 0, 1, 1, 0, -7049.27, -1393.39, 241.676, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+27, 2866, 0, 1, 1, 0, -6947.23, -1624.99, 243.193, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+28, 2866, 0, 1, 1, 0, -6426.89, -2033.43, 249.515, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+29, 2866, 0, 1, 1, 0, -7163.19, -1118.24, 244.398, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+30, 2866, 0, 1, 1, 0, -6772.52, -1806.13, 256.857, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+31, 2866, 0, 1, 1, 0, -6753.41, -1215.32, 244.494, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+32, 2866, 0, 1, 1, 0, -7114.53, -1332.86, 244.681, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+33, 2866, 0, 1, 1, 0, -7048.58, -1656.77, 243.66, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+34, 2866, 0, 1, 1, 0, -6659.14, -1842.59, 247.085, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+35, 2866, 0, 1, 1, 0, -6750.08, -1301.44, 241.763, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+36, 2866, 0, 1, 1, 0, -7005.65, -1102.86, 243.83, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+37, 2866, 0, 1, 1, 0, -7087.94, -1441.66, 245.901, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+38, 2866, 0, 1, 1, 0, -6716.69, -1017.67, 241.486, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+39, 2866, 0, 1, 1, 0, -7039.91, -1580.38, 245.581, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+40, 2866, 0, 1, 1, 0, -6962.73, -1571.87, 242.785, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+41, 2866, 0, 1, 1, 0, -6691.46, -1303.78, 241.734, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+42, 2866, 0, 1, 1, 0, -7059.52, -1143.58, 246.227, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+43, 2866, 0, 1, 1, 0, -7165.52, -983.127, 243.357, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+44, 2866, 0, 1, 1, 0, -6976.97, -996.736, 241.787, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+45, 2866, 0, 1, 1, 0, -7188.47, -1317.22, 246.573, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+46, 2866, 0, 1, 1, 0, -7115.49, -1673.78, 241.667, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+47, 2866, 0, 1, 1, 0, -6351.15, -1981.97, 250.616, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+48, 2866, 0, 1, 1, 0, -6719.47, -1817.90, 252.548, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1), -- Firebloom
(@OGUID+49, 2866, 0, 1, 1, 0, -6793.28, -1114.16, 243.561, 0.122173, 0, 0, 0, 1, @TIMER, 255, 1); -- Firebloom

-- Add mother pool to pool template
DELETE FROM `pool_template` WHERE `entry`=@MOTHER;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@MOTHER,@ACTIVE, 'Searing Gorge Firebloom Mother pool');

-- Pool Firebloom Spawnpoints
DELETE FROM `pool_gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+@LASTGUID;
INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(@OGUID+0,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+1,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+2,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+3,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+4,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+5,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+6,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+7,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+8,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+9,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+10,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+11,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+12,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+13,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+14,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+15,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+16,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+17,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+18,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+19,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+20,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+21,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+22,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+23,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+24,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+25,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+26,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+27,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+28,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+29,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+30,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+31,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+32,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+33,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+34,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+35,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+36,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+37,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+38,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+39,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+40,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+41,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+42,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+43,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+44,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+45,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+46,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+47,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+48,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint'),
(@OGUID+49,@MOTHER,0, 'Searing Gorge Firebloom Spawnpoint');
