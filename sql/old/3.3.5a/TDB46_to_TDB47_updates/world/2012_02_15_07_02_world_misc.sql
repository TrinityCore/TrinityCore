-- Love is in the Air
SET @OGUID := 24399;
SET @CGUID := 40506;
SET @OLDGUID := 40489; -- wrong guids
SET @EVENT := 8;

-- Quest chain
DELETE FROM `creature_questrelation` WHERE `quest` IN (24804,24657,24656,24848,24849);
INSERT INTO `creature_questrelation` (`id`, `quest`) VALUES
(38293, 24804), -- A - Uncommon Scents - Junior Inspector
(38325, 24657), -- A - Friendly Chat... - Marion Sutton
(38066, 24656), -- A - Pilfering Perfume - Inspector Snip Snagglebolt
(38066, 24848), -- A - Fireworks At The Gilded Rose - Inspector Snip Snagglebolt
(38325, 24849); -- A - Hot On The Trail - Marion Sutton

DELETE FROM `creature_involvedrelation` WHERE `quest` IN (24804,24657,24656,24848,24849);
INSERT INTO `creature_involvedrelation` (`id`, `quest`) VALUES
(38066, 24804), -- A - Uncommon Scents - Inspector Snip Snagglebolt
(38066, 24657), -- A - Friendly Chat... - Inspector Snip Snagglebolt
(38066, 24656), -- A - Pilfering Perfume - Inspector Snip Snagglebolt
(38325, 24848), -- A - Fireworks At The Gilded Rose - Marion Sutton
(38325, 24849); -- A - Hot On The Trail - Marion Sutton

-- Loot: Crown Chemical Co. Supplies
DELETE FROM `gameobject_loot_template` WHERE `entry`=27766;
INSERT INTO `gameobject_loot_template` VALUES
(27766, 49867, -100, 1, 0, 1, 1); --  Crown Chemical Co. Supplies

-- GO spawns
DELETE FROM `gameobject` WHERE `id` IN (181086,201752,201778) AND `guid` BETWEEN @OGUID+0 AND @OGUID+42;
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
-- Valentine Arch
(@OGUID+0, 181086, 1, 1, 1, 9869.12, 2493.13, 1315.88, 6.16653, 0, 0, 0.0582931, -0.9983, 300, 0, 1),
(@OGUID+1, 181086, 530, 1, 1, -4004.66, -11844.5, 0.19541, 4.93701, 0, 0, 0.623403, -0.7819, 300, 0, 1),
(@OGUID+2, 181086, 0, 1, 1, -4918.78, -983.208, 501.455, 2.30465, 0, 0, 0.913711, 0.406364, 300, 0, 1),
(@OGUID+3, 181086, 0, 1, 1, -8869.51, 636.686, 95.7873, 0.794388, 0, 0, 0.386832, 0.92215, 300, 0, 1),
(@OGUID+4, 181086, 1, 1, 1, 1653.44, -4437.37, 18.1863, 1.72627, 0, 0, 0.759883, 0.65006, 300, 0, 1),
(@OGUID+5, 181086, 1, 1, 1, -1224.34, 68.3642, 129.71, 3.17285, 0, 0, 0.999878, -0.015627, 300, 0, 1),
(@OGUID+6, 181086, 530, 1, 1, 9612.28, -7184.77, 14.285, 1.82938, 0, 0, 0.792374, 0.610036, 300, 0, 1),
(@OGUID+7, 181086, 0, 1, 1, 1629.62, 240.116, 63.8516, 0.155664, 0, 0, 0.0777534, 0.996973, 300, 0, 1),
-- Large Crate
(@OGUID+8, 201752, 0, 1, 1, -9029.77, 353.325, 92.923, 0.8808, 0, 0, 0.426301, 0.904581, 300, 0, 1),
(@OGUID+9, 201752, 0, 1, 1, -9029.87, 351.542, 92.9248, 0.489671, 0, 0, 0.242397, 0.970177, 300, 0, 1),
(@OGUID+10, 201752, 0, 1, 1, -9028.41, 352.69, 92.9163, 0.721364, 0, 0, 0.352912, 0.935656, 300, 0, 1),
(@OGUID+11, 201752, 0, 1, 1, -9027.7, 351.062, 92.9193, 0.689162, 0, 0, 0.337803, 0.941217, 300, 0, 1),
(@OGUID+12, 201752, 0, 1, 1, -9029.08, 349.917, 92.932, 0.657746, 0, 0, 0.322977, 0.946407, 300, 0, 1),
(@OGUID+13, 201752, 0, 1, 1, -9028.77, 352.62, 94.1596, 6.02202, 0, 0, 0.130214, -0.991486, 300, 0, 1),
(@OGUID+14, 201752, 0, 1, 1, -9028.84, 350.443, 94.1755, 0.771628, 0, 0, 0.376314, 0.926492, 300, 0, 1),
(@OGUID+15, 201752, 0, 1, 1, -9026.5, 348.864, 93.0359, 2.17356, 0, 0, 0.885134, 0.465337, 300, 0, 1),
(@OGUID+16, 201752, 0, 1, 1, -9028.21, 348.744, 93.024, 0.889436, 0, 0, 0.430203, 0.902732, 300, 0, 1),
(@OGUID+17, 201752, 1, 1, 1, 1381.97, -4431.17, 30.6588, 5.49617, 0, 0, 0.383432, -0.923569, 300, 0, 1),
(@OGUID+18, 201752, 1, 1, 1, 1380.98, -4432.28, 30.6586, 5.55507, 0, 0, 0.356069, -0.93446, 300, 0, 1),
(@OGUID+19, 201752, 1, 1, 1, 1379.73, -4433.4, 30.6569, 5.69644, 0, 0, 0.28918, -0.957275, 300, 0, 1),
(@OGUID+20, 201752, 1, 1, 1, 1377.96, -4432.16, 30.6489, 5.58649, 0, 0, 0.341345, -0.939938, 300, 0, 1),
(@OGUID+21, 201752, 1, 1, 1, 1379.23, -4431.41, 30.6768, 5.559, 0, 0, 0.354231, -0.935158, 300, 0, 1),
(@OGUID+22, 201752, 1, 1, 1, 1379.85, -4432.91, 31.8999, 5.66896, 0, 0, 0.302309, -0.95321, 300, 0, 1),
(@OGUID+23, 201752, 1, 1, 1, 1380.81, -4431.58, 31.902, 5.64147, 0, 0, 0.315381, -0.948965, 300, 0, 1),
(@OGUID+24, 201752, 1, 1, 1, 1377.67, -4434.36, 30.6055, 5.36265, 0, 0, 0.444186, -0.895935, 300, 0, 1),
-- Crown Chemical Co. Supplies
(@OGUID+25, 201778, 0, 1, 1, -9031.18, 354.399, 92.9752, 6.12019, 0, 0, 0.0814081, -0.996681, 300, 0, 1),
(@OGUID+26, 201778, 0, 1, 1, -9028.76, 352.525, 95.4034, 0.503804, 0, 0, 0.249246, 0.96844, 300, 0, 1),
(@OGUID+27, 201778, 0, 1, 1, -9030.19, 351.409, 94.1683, 0.134668, 0, 0, 0.067283, 0.997734, 300, 0, 1),
(@OGUID+28, 201778, 0, 1, 1, -9031.52, 349.739, 92.9068, 0.338872, 0, 0, 0.168626, 0.98568, 300, 0, 1),
(@OGUID+29, 201778, 0, 1, 1, -9030.55, 347.899, 92.9635, 0.751206, 0, 0, 0.366833, 0.930287, 300, 0, 1),
(@OGUID+30, 201778, 0, 1, 1, -9027.59, 348.911, 94.2683, 1.784, 0, 0, 0.77833, 0.627855, 300, 0, 1),
(@OGUID+31, 201778, 0, 1, 1, -9028.87, 349.971, 95.4191, 1.82327, 0, 0, 0.790507, 0.612452, 300, 0, 1),
(@OGUID+32, 201778, 0, 1, 1, -9031.75, 354.82, 92.9939, 6.0605, 0, 0, 0.111113, -0.993808, 300, 0, 1),
(@OGUID+33, 201778, 0, 1, 1, -9032.22, 352.779, 92.9627, 6.0605, 0, 0, 0.111113, -0.993808, 300, 0, 1),
(@OGUID+34, 201778, 1, 1, 1, 1375.84, -4432.46, 30.5735, 5.69645, 0, 0, 0.289178, -0.957275, 300, 0, 1),
(@OGUID+35, 201778, 1, 1, 1, 1377.99, -4431.81, 31.8923, 5.5001, 0, 0, 0.381614, -0.924322, 300, 0, 1),
(@OGUID+36, 201778, 1, 1, 1, 1379.21, -4430.58, 31.9198, 4.81681, 0, 0, 0.669241, -0.743045, 300, 0, 1),
(@OGUID+37, 201778, 1, 1, 1, 1379.35, -4432.78, 33.143, 5.61791, 0, 0, 0.326536, -0.945185, 300, 0, 1),
(@OGUID+38, 201778, 1, 1, 1, 1380.87, -4431.5, 33.1452, 4.66994, 0, 0, 0.721955, -0.69194, 300, 0, 1),
(@OGUID+39, 201778, 1, 1, 1, 1380.96, -4429.36, 30.6772, 4.6503, 0, 0, 0.728713, -0.68482, 300, 0, 1),
(@OGUID+40, 201778, 1, 1, 1, 1383.08, -4429.42, 30.651, 4.53642, 0, 0, 0.766505, -0.642238, 300, 0, 1),
(@OGUID+41, 201778, 1, 1, 1, 1378.64, -4428.42, 30.6846, 5.23543, 0, 0, 0.500243, -0.865885, 300, 0, 1),
(@OGUID+42, 201778, 1, 1, 1, 1377.05, -4429.39, 30.6467, 5.31397, 0, 0, 0.465863, -0.884857, 300, 0, 1);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=@EVENT AND `guid` BETWEEN @OGUID AND @OGUID+42;
INSERT INTO `game_event_gameobject` (`guid`, `eventEntry`) VALUES
(@OGUID, @EVENT),(@OGUID+1, @EVENT),(@OGUID+2, @EVENT),
(@OGUID+3, @EVENT),(@OGUID+4, @EVENT),(@OGUID+5, @EVENT),
(@OGUID+6, @EVENT),(@OGUID+7, @EVENT),(@OGUID+8, @EVENT),
(@OGUID+9, @EVENT),(@OGUID+10, @EVENT),(@OGUID+11, @EVENT),
(@OGUID+12, @EVENT),(@OGUID+13, @EVENT),(@OGUID+14, @EVENT),
(@OGUID+15, @EVENT),(@OGUID+16, @EVENT),(@OGUID+17, @EVENT),
(@OGUID+18, @EVENT),(@OGUID+19, @EVENT),(@OGUID+20, @EVENT),
(@OGUID+21, @EVENT),(@OGUID+22, @EVENT),(@OGUID+23, @EVENT),
(@OGUID+24, @EVENT),(@OGUID+25, @EVENT),(@OGUID+26, @EVENT),
(@OGUID+27, @EVENT),(@OGUID+28, @EVENT),(@OGUID+29, @EVENT),
(@OGUID+30, @EVENT),(@OGUID+31, @EVENT),(@OGUID+32, @EVENT),
(@OGUID+33, @EVENT),(@OGUID+34, @EVENT),(@OGUID+35, @EVENT),
(@OGUID+36, @EVENT),(@OGUID+37, @EVENT),(@OGUID+38, @EVENT),
(@OGUID+39, @EVENT),(@OGUID+40, @EVENT),(@OGUID+41, @EVENT),
(@OGUID+42, @EVENT);

-- [Q]: Pilfering Perfume
-- Note: this is EndText (misleading field name), NOT ObjectiveText1
UPDATE `quest_template` SET `EndText` = 'Steal perfume package from Crown Chemical Co. outside Stormind' WHERE `Id` = 24656; -- Alliance
UPDATE `quest_template` SET `EndText` = 'Steal perfume package from Crown Chemical Co. outside Orgrimmar' WHERE `Id` = 24541; -- Horde

-- Creature templates and spawns
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=75 WHERE `entry`=37671; -- Crown Supply Guard
UPDATE `creature_template` SET `npcflag`=`npcflag`|1, `gossip_menu_id`=10991 WHERE `entry`=38293; -- Junior Inspector (gossip menu not confirmed)

DELETE FROM `creature` WHERE `id` IN (38293,38065,37671) AND `guid` BETWEEN @CGUID+0 AND @CGUID+3;
DELETE FROM `creature` WHERE `id` IN (38293,38065,37671) AND `guid` BETWEEN @OLDGUID+0 AND @OLDGUID+3;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(@CGUID+0, 38293, 530, 1, 1, 0, 0, -4022.81, -11842.7, 0.0062171, 5.89912, 300, 0, 0, 955, 0, 0, 0, 0, 0), -- Junior Inspector
(@CGUID+1, 38065, 1, 1, 1, 0, 0, 1380.22, -4426.79, 30.6681, 2.03572, 300, 0, 0, 12600, 0, 0, 0, 0, 0), -- Crown Supply Sentry <Crown Chemical Co.>
(@CGUID+2, 37671, 0, 1, 1, 30912, 0, -9033.01, 356.408, 93.1543, 2.09345, 300, 0, 0, 42, 0, 0, 0, 0, 0), -- Crown Supply Guard
(@CGUID+3, 37671, 0, 1, 1, 30912, 0, -9028.63, 344.994, 93.2389, 3.37679, 300, 0, 0, 42, 0, 0, 0, 0, 0); -- Crown Supply Guard

DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+3 AND `eventEntry`=@EVENT;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN @OLDGUID+0 AND @OLDGUID+3 AND `eventEntry`=@EVENT;
INSERT INTO `game_event_creature` (`guid`, `eventEntry`) VALUES
(@CGUID+0, @EVENT),
(@CGUID+1, @EVENT),
(@CGUID+2, @EVENT),
(@CGUID+3, @EVENT);
