--
UPDATE `gameobject` SET `guid`=342 WHERE `guid`=80;
UPDATE `gameobject` SET `guid`=334 WHERE `guid`=1;
UPDATE `gameobject` SET `guid`=361 WHERE `guid`=139;
UPDATE `gameobject` SET `guid`=362 WHERE `guid`=140;

SET @OGUID := 371;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+115; -- delete duplicate spawns
DELETE FROM `gameobject` WHERE `guid`=141 AND `id`=188358;

DELETE FROM `gameobject` WHERE `id`=182263;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(22718,182263,530,1,1,-2532.99,6306.90,14.0280,2.81871,0,0,0.986996,0.160743,181,100,1),-- already in TDB
(371,182263,530,1,1,-2474.44,6111.16,91.7629,3.66388,0,0,0.966096,-0.258184,181,100,1),
(379,182263,530,1,1,-2533.21,6168.56,59.9387,3.75028,0,0,0.954044,-0.299666,181,100,1);

UPDATE `gameobject` SET `guid`=380 WHERE `guid`=20;

INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(2568, 188514, 578, 4228, 4228, 3, 1, 1209.71, 1334.59, 192.375, 1.10828, 0, 0, 0.526214, 0.850352, 180, 0, 1, 0),
(2730, 183043, 530, 3521, 3648, 1, 1, 907.398, 5773.45, 10.7675, -1.58825, 0, 0, 0.71325, -0.700909, 60, 100, 1, 0);

UPDATE `gameobject` SET `guid`=3552 WHERE `guid`=290;
UPDATE `gameobject` SET `guid`=5338 WHERE `guid`=148;
UPDATE `gameobject` SET `guid`=5494 WHERE `guid`=5;

SET @OGUID :=122; -- 4.x
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;

SET @OGUID :=5681; -- need 3 set by TDB
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+2;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0,188600,571,1,1,3980.721,-1956.352,210.6624,1.169369,0,0,0,1,120,255,1),
(@OGUID+1,188600,571,1,1,3957.188,-1908.295,209.97,0.8901166,0,0,0,1,120,255,1),
(@OGUID+2,188600,571,1,1,3964.761,-1884.524,208.2739,1.692969,0,0,0,1,120,255,1);

SET @OGUID := 6024; -- Set by TDB
DELETE FROM gameobject WHERE id IN (190284,190283,186814,186813);
INSERT INTO gameobject (guid,id,map,spawnMask,phaseMask,position_x,position_y,position_z,orientation,rotation0,rotation1,rotation2,rotation3,spawntimesecs,animprogress,state) VALUES
(@OGUID,190284,571,1,1,1595.69,-3905.33,79.7439,0.610864,0,0,0,0,5,0,1),
(@OGUID+1,190283,571,1,1,1597.4,-3903.79,79.702,0,0,0,0,0,60,100,1),
(@OGUID+2,186814,571,1,1,1597.4,-3903.79,79.702,0,0,0,0,0,60,100,1),
(@OGUID+3,186813,571,1,1,1596.3,-3904.79,79.5351,-2.67035,0,0,0,0,5,0,1);

DELETE FROM gameobject WHERE id IN (194241);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(6068, 194241, 571, 65, 4256, 1, 1, 4606.72, -1606.91, 156.659, 1.62734, 0, 0, 0.726811, 0.686837, 300, 0, 1, 0),
(6069, 194241, 571, 65, 4256, 1, 1, 4596.78, -1606.69, 156.659, 1.5488, 0, 0, 0.699286, 0.714842, 300, 0, 1, 0),
(6070, 194241, 571, 65, 4256, 1, 1, 4597.1, -1594.08, 156.658, 1.53702, 0, 0, 0.695063, 0.718949, 300, 0, 1, 0),
(6071, 194241, 571, 65, 4256, 1, 1, 4608.33, -1592.98, 156.658, 0.162569, 0, 0, 0.0811951, 0.996698, 300, 0, 1, 0),
(6072, 194241, 571, 65, 4256, 1, 1, 4602.78, -1600.05, 156.658, 4.08564, 0, 0, 0.890651, -0.454688, 300, 0, 1, 0);

UPDATE `gameobject` SET `guid`=6100 WHERE `guid`=154;
UPDATE `gameobject` SET `guid`=6101 WHERE `guid`=155;
UPDATE `gameobject` SET `guid`=7093 WHERE `guid`=209;
UPDATE `gameobject` SET `guid`=7094 WHERE `guid`=210;
UPDATE `gameobject` SET `guid`=7095 WHERE `guid`=211;
UPDATE `gameobject` SET `guid`=7096 WHERE `guid`=212;
UPDATE `gameobject` SET `guid`=7097 WHERE `guid`=213;

DELETE FROM `gameobject` WHERE `guid`=21080;

UPDATE `gameobject` SET `guid`=21080 WHERE `guid`=1910;

DELETE FROM `gameobject` WHERE `guid` IN (25020,25042,32360,35793,35829,67867);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(25020, 184109, 530, 3523, 3737, 1, 1, 4006.81, 1517.19, -115.933, -1.6057, 0, 0, 0.71934, -0.694658, 181, 100, 1, 0),
(25042, 184143, 530, 3523, 3723, 1, 1, 2760.88, 3203.82, 153.994, -0.558505, 0, 0, 0.275637, -0.961262, 181, 100, 1, 0),
(32360, 185324, 532, 3457, 3457, 1, 1, -11080.6, -1876.43, 219.869, -1.79769, 0, 0, 0, 1, 180, 255, 0, 0),
(35793, 177387, 469, 2677, 2677, 1, 1, -7537.94, -1009.43, 449.242, 5.34938, 0, 0, 0.450124, -0.892966, 250, 0, 1, 0),
(35829, 179118, 469, 2677, 2677, 1, 1, -7587.76, -1261.43, 482, 0.577301, 0, 0, 0, 0, 120, 0, 1, 0),
(67867, 177808, 469, 2677, 2677, 1, 1, -7614.83, -1026.62, 413.382, 5.32326, 0, 0, 0.749162, -0.662387, 25, 0, 1, 0);

UPDATE `gameobject` SET `guid`=99716 WHERE `guid`=208;
