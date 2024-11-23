-- Add missing Battered Chest ID: 2843 with pooling in Northshire Valley, Coldridge Valley, DeathKnell, and Shadowglen
SET @OGUID := 13545; -- 19 required
SET @POOLID := 577; -- 8 required

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+18;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `PhaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 2843, 0, 12, 34, 1, 1, -8564.622, -212.033, 85.301, 2.478, 0, 0, 0.94551849365234375, 0.325568377971649169, 360, 255, 1, 0), -- Northshire Valley, Echo Ridge Mine
(@OGUID+1, 2843, 0, 85, 154, 1, 1, 1788.795, 1345.5, 89.283, 5.341, 0, 0, -0.45398998260498046, 0.891006767749786376, 360, 255, 1, 0), -- DeathKnell
(@OGUID+2, 2843, 0, 85, 155, 1, 1, 2019.491, 1853.655, 102.669, 4.188, 0, 0, -0.86602497100830078, 0.50000077486038208, 360, 255, 1, 0), -- DeathKnell, Night Web's Hollow
(@OGUID+3, 2843, 0, 85, 155, 1, 1, 2041.629, 1935.115, 106.989, 4.677, 0, 0, -0.71933937072753906, 0.694658815860748291, 360, 255, 1, 0), -- DeathKnell, Night Web's Hollow
(@OGUID+4, 2843, 0, 1, 132, 1, 1, -6394.58447265625, 772.35076904296875, 386.2127685546875, 5.078907966613769531, 0, 0, -0.56640625, 0.824126183986663818, 360, 255, 1, 0), -- Coldridge Vally
(@OGUID+5, 2843, 0, 1, 132, 1, 1, -6550.423828125, 351.92535400390625, 392.339447021484375, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 360, 255, 1, 0), -- Coldridge Vally, cave
(@OGUID+6, 2843, 1, 141, 188, 1, 1, 10485.255859375, 1059.9840087890625, 1325.470458984375, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 360, 255, 1, 41446), -- Shadowglen
(@OGUID+7, 2843, 1, 141, 257, 1, 1, 10908.3759765625, 977.76202392578125, 1338.316162109375, 2.827429771423339843, 0, 0, 0.987688064575195312, 0.156436234712600708, 360, 255, 1, 0), -- Shadowglen, Shadowthread Cave
-- From mangos db
(@OGUID+8, 2843, 0, 12, 9, 1, 1, -8955.38, -439.217, 64.7955, -2.86233, 0, 0, 0, 0, 360, 255, 1, 0), -- Northshire Valley
(@OGUID+9, 2843, 0, 85, 155, 1, 1, 2036.59, 1916.59, 102.783, 6.23153, 0, 0, 0.025824, -0.999667, 360, 255, 1, 0), -- DeathKnell, Night Web's Hollow
(@OGUID+10, 2843, 0, 1, 132, 1, 1, -6493.9, 502.314, 387.246, 0.977737, 0, 0, 0.469627, 0.882865, 360, 255, 1, 0), -- Coldridge Vally
(@OGUID+11, 2843, 0, 1, 132, 1, 1, -6520.52, 688.075, 387.612, 6.21242, 0, 0, 0.0353748, -0.999374, 360, 255, 1, 0), -- Coldridge Vally
(@OGUID+12, 2843, 0, 1, 132, 1, 1, -6396.81, 784.359, 386.216, 5.19288, 0, 0, 0.518547, -0.855049, 360, 255, 1, 0), -- Coldridge Vally
(@OGUID+13, 2843, 0, 1, 132, 1, 1, -6516.55, 288.024, 372.061, 0.760217, 0, 0, 0.371021, 0.928624, 360, 255, 1, 0), -- Coldridge Vally, cave
(@OGUID+14, 2843, 0, 1, 132, 1, 1, -6541.69, 362.199, 384.464, 1.23852, 0, 0, 0.580434, 0.814307, 360, 255, 1, 0), -- Coldridge Vally, cave
(@OGUID+15, 2843, 1, 141, 257, 1, 1, 10812.8, 897.368, 1336.4, 0.444496, 0, 0, 0.220423, 0.975404, 360, 255, 1, 0), -- Shadowglen, Shadowthread Cave
(@OGUID+16, 2843, 1, 141, 257, 1, 1, 10942.8, 942.153, 1340.68, 5.62352, 0, 0, 0.323884, -0.946097, 360, 255, 1, 0), -- Shadowglen, Shadowthread Cave
(@OGUID+17, 2843, 1, 141, 188, 1, 1, 10262.1, 961.428, 1340.93, 5.89251, 0, 0, 0.194099, -0.980982, 360, 255, 1, 41446), -- Shadowglen
(@OGUID+18, 2843, 1, 141, 188, 1, 1, 10504.8, 1064.71, 1325.83, -0.279252, 0, 0, 0, 0, 360, 255, 1, 41446); -- Shadowglen

-- Update existing spawns to match new ones.
UPDATE `gameobject` SET `spawntimesecs`=360, `animprogress`=225, `state`=1 WHERE `guid` IN
(26749,34797,26756,34798,85653,1397,85816,1454,85817,45106,85818,85832,45110,49529,49528);

-- Add coin
UPDATE `gameobject_template_addon` SET `mingold`=1, `maxgold`=20 WHERE `entry` = 2843;

DELETE FROM `pool_template` WHERE `entry` BETWEEN @POOLID AND @POOLID+7;
INSERT INTO `pool_template` (`entry`,`max_limit`,`description`) VALUES
(@POOLID,1,'Battered Chest (2843), Northshire, Chest Pool Mine'),
(@POOLID+1,1,'Battered Chest (2843), Northshire, Chest Pool Vineyard'),
(@POOLID+2,1,'Battered Chest (2843), Coldridge Valley, Chest Pool Valley'),
(@POOLID+3,1,'Battered Chest (2843), Coldridge Valley, Chest Pool Cave'),
(@POOLID+4,1,'Battered Chest (2843), Deathknell, Chest Pool Deathknell'),
(@POOLID+5,1,'Battered Chest (2843), Deathknell, Chest Pool Night Web''s Hollow'),
(@POOLID+6,1,'Battered Chest (2843), Shadowglen, Chest Pool Shadowglen'),
(@POOLID+7,1,'Battered Chest (2843), Shadowglen, Chest Pool Shadowthread Cave');

DELETE FROM `pool_members` WHERE `poolSpawnId` BETWEEN @POOLID AND @POOLID+7;
INSERT INTO `pool_members` (`type`,`spawnId`,`poolSpawnId`,`chance`,`description`) VALUES
(1,26749,@POOLID,0,'Battered Chest (2843), Northshire Mine'),
(1,34797,@POOLID,0,'Battered Chest (2843), Northshire Mine'),
(1,@OGUID,@POOLID,0,'Battered Chest (2843), Northshire Mine'),
(1,26756,@POOLID+1,0,'Battered Chest (2843), Northshire Vineyard'),
(1,34798,@POOLID+1,0,'Battered Chest (2843), Northshire Vineyard'),
(1,85653,@POOLID+1,0,'Battered Chest (2843), Northshire Vineyard'),
(1,@OGUID+8,@POOLID+1,0,'Battered Chest (2843), Northshire Vineyard'),
(1,1397,@POOLID+2,0,'Battered Chest (2843), Coldridge Valley'),
(1,85816,@POOLID+2,0,'Battered Chest (2843), Coldridge Valley'),
(1,@OGUID+4,@POOLID+2,0,'Battered Chest (2843), Coldridge Valley'),
(1,@OGUID+10,@POOLID+2,0,'Battered Chest (2843), Coldridge Valley'),
(1,@OGUID+11,@POOLID+2,0,'Battered Chest (2843), Coldridge Valley'),
(1,@OGUID+12,@POOLID+2,0,'Battered Chest (2843), Coldridge Valley'),
(1,1454,@POOLID+3,0,'Battered Chest (2843), Coldridge Valley Cave'),
(1,85817,@POOLID+3,0,'Battered Chest (2843), Coldridge Valley Cave'),
(1,@OGUID+5,@POOLID+3,0,'Battered Chest (2843), Coldridge Valley Cave'),
(1,@OGUID+13,@POOLID+3,0,'Battered Chest (2843), Coldridge Valley Cave'),
(1,@OGUID+14,@POOLID+3,0,'Battered Chest (2843), Coldridge Valley Cave'),
(1,45106,@POOLID+4,0,'Battered Chest (2843), Deathknell'),
(1,85818,@POOLID+4,0,'Battered Chest (2843), Deathknell'),
(1,85832,@POOLID+4,0,'Battered Chest (2843), Deathknell'),
(1,@OGUID+1,@POOLID+4,0,'Battered Chest (2843), Deathknell'),
(1,45110,@POOLID+5,0,'Battered Chest (2843), Night Web''s Hollow'),
(1,@OGUID+2,@POOLID+5,0,'Battered Chest (2843), Night Web''s Hollow'),
(1,@OGUID+3,@POOLID+5,0,'Battered Chest (2843), Night Web''s Hollow'),
(1,@OGUID+9,@POOLID+5,0,'Battered Chest (2843), Night Web''s Hollow'),
(1,49529,@POOLID+6,0,'Battered Chest (2843), Shadowglen'),
(1,@OGUID+6,@POOLID+6,0,'Battered Chest (2843), Shadowglen'),
(1,@OGUID+17,@POOLID+6,0,'Battered Chest (2843), Shadowglen'),
(1,@OGUID+18,@POOLID+6,0,'Battered Chest (2843), Shadowglen'),
(1,49528,@POOLID+7,0,'Battered Chest (2843), Shadowthread Cave'),
(1,@OGUID+7,@POOLID+7,0,'Battered Chest (2843), Shadowthread Cave'),
(1,@OGUID+15,@POOLID+7,0,'Battered Chest (2843), Shadowthread Cave'),
(1,@OGUID+16,@POOLID+7,0,'Battered Chest (2843), Shadowthread Cave');
