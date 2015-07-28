-- Searing Gorge Dark Iron Pillow spawns for quest http://www.wowhead.com/quest=28057
SET @OGUID    := 225650;
SET @MOTHER   := 5102;
SET @LASTGUID := 23;
SET @ACTIVE   := 8; -- Max number of active spawns
SET @TIMER    := 30; -- Respawn timer in seconds

-- Dark Iron Pillow spawns for Searing Gorge
DELETE FROM gameobject WHERE id=179828;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+@LASTGUID;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 179828, 0, 1, 1, 0, -6569.39, -1335.83, 210.199, 2.33874, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+1, 179828, 0, 1, 1, 0, -6527.64, -1340.23, 212.095, 1.832595, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+2, 179828, 0, 1, 1, 0, -6518.91, -1364.86, 210.541, 5.654869, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+3, 179828, 0, 1, 1, 0, -6572.96, -1327.58, 212.095, 3.560473, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+4, 179828, 0, 1, 1, 0, -6570.39, -1332.69, 212.095, 5.375615, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+5, 179828, 0, 1, 1, 0, -6547.68, -1325.57, 212.376, 2.757613, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+6, 179828, 0, 1, 1, 0, -6575.96, -1323.57, 210.144, 4.293513, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+7, 179828, 0, 1, 1, 0, -6552.55, -1317.99, 212.64, 4.939284, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+8, 179828, 0, 1, 1, 0, -6576.94, -1319.12, 210.249, 6.03884, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+9, 179828, 0, 1, 1, 0, -6551.49, -1318.46, 210.419, 0.6981314, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+10, 179828, 0, 1, 1, 0, -6528.67, -1339.02, 210.124, 2.670348, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+11, 179828, 0, 1, 1, 0, -6543.81, -1358.71, 210.544, 3.752462, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+12, 179828, 0, 1, 1, 0, -6554.68, -1351.74, 212.682, 2.146753, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+13, 179828, 0, 1, 1, 0, -6562.07, -1344.44, 212.619, 1.256636, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+14, 179828, 0, 1, 1, 0, -6554.33, -1313.8, 210.26, 5.288348, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+15, 179828, 0, 1, 1, 0, -6543.61, -1329.85, 212.564, 5.393069, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+16, 179828, 0, 1, 1, 0, -6544.77, -1329.61, 210.26, 5.305802, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+17, 179828, 0, 1, 1, 0, -6551.14, -1354.85, 210.421, 4.363324, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+18, 179828, 0, 1, 1, 0, -6550.27, -1321.75, 210.433, 5.445428, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+19, 179828, 0, 1, 1, 0, -6518.33, -1342.21, 212.095, 4.991644, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+20, 179828, 0, 1, 1, 0, -6558.36, -1347.93, 210.26, 3.351047, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+21, 179828, 0, 1, 1, 0, -6531.65, -1337.63, 210.18, 4.398232, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+22, 179828, 0, 1, 1, 0, -6508.78, -1365.26, 212.859, 0.6457717, 0, 0, 0, 1, @TIMER, 255, 1), -- Dark Iron Pillow
(@OGUID+23, 179828, 0, 1, 1, 0, -6528.76, -1363.6, 212.657, 2.617989, 0, 0, 0, 1, @TIMER, 255, 1); -- Dark Iron Pillow

-- Add mother pool to pool template
DELETE FROM `pool_template` WHERE `entry`=@MOTHER;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@MOTHER,@ACTIVE, 'Searing Gorge Dark Iron Pillow Mother pool');

-- Pool Dark Iron Pillow Spawnpoints
DELETE FROM `pool_gameobject` WHERE `guid` BETWEEN @OGUID AND @OGUID+@LASTGUID;
INSERT INTO `pool_gameobject` (`guid`,`pool_entry`,`chance`,`description`) VALUES
(@OGUID+0,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+1,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+2,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+3,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+4,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+5,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+6,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+7,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+8,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+9,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+10,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+11,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+12,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+13,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+14,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+15,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+16,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+17,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+18,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+19,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+20,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+21,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+22,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn'),
(@OGUID+23,@MOTHER,0, 'Searing Gorge Dark Iron Pillow Spawn');
