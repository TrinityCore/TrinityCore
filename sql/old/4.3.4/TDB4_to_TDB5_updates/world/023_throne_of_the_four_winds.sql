SET @OGUID := 164457;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+16;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 207737, 754, 1, 1, -271, 814.8698, 203.034, 3.141593, 1.317221E-43, 0, 0, 0, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+1, 207924, 754, 1, 1, -255.0611, 849.3882, 200.6729, 3.926991, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+2, 207923, 754, 1, 1, -255.054, 783.7366, 200.6729, 2.356195, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+3, 207922, 754, 1, 1, -49.5817, 815.0962, 191.0817, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+4, 207930, 754, 1, 1, -83.87373, 609.6168, 200.673, 5.497789, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+5, 207925, 754, 1, 1, -80.94135, 1020.569, 200.6729, 0.7853968, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+6, 206701, 754, 1, 1, -51.24957, 576.9064, 203.034, 1.570796, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+7, 206699, 754, 1, 1, -47.91377, 1053.286, 203.034, 4.71239, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+8, 207929, 754, 1, 1, -18.22198, 609.6238, 200.6729, 3.926991, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+9, 207926, 754, 1, 1, -15.28961, 1020.576, 200.6729, 2.35619, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+10, 207928, 754, 1, 1, 155.8977, 780.8041, 200.673, 0.7853968, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+11, 207927, 754, 1, 1, 155.8907, 846.4558, 200.6729, 5.497789, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+12, 206700, 754, 1, 1, 188.6082, 813.4283, 203.0285, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+13, 207976, 754, 1, 1, -322.2661, 816.2766, 202.1453, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+14, 207977, 754, 1, 1, -322.2661, 816.2766, 202.1453, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+15, 207979, 754, 1, 1, -322.2661, 816.2766, 202.1453, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+16, 207978, 754, 1, 1, -322.2661, 816.2766, 202.1453, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1); -- -Unknown- (Area: 0)


UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction_A`=16, `faction_H`=16, `speed_walk`=2.4, `speed_run`=1.428571, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags2`=1075838976, `VehicleId`=1318 WHERE `entry`=45872; -- Rohash
UPDATE `creature_template` SET `minlevel`=88, `maxlevel`=88, `faction_A`=16, `faction_H`=16, `speed_walk`=2.4, `speed_run`=1.428571, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags2`=1075838976, `VehicleId`=1321 WHERE `entry`=45870; -- Anshal
UPDATE `creature_template` SET `unit_flags2`=1075838976, `dynamicflags`=0 WHERE `entry`=45871; -- Nezir


DELETE FROM `creature_template_addon` WHERE `entry` IN (46753, 36171, 45872, 45870, 45871, 48977, 47806, 46419, 47924, 47926, 47925, 46766);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(46753, 0, 0x0, 0x1, ''), -- Al'Akir
(36171, 0, 0x0, 0x1, ''), -- World Trigger (Infinite AOI)
(45872, 0, 0x0, 0x1, ''), -- Rohash
(45870, 0, 0x0, 0x1, ''), -- Anshal
(45871, 0, 0x0, 0x1, ''), -- Nezir
(48977, 0, 0x3000000, 0x1, ''), -- Lightning Strike Trigger
(47806, 0, 0x3000000, 0x1, ''), -- Relentless Storm Initial Vehicle
(46419, 0, 0x3000000, 0x1, ''), -- Hurricane
(47924, 0, 0x0, 0x1, ''), -- East Wind
(47926, 0, 0x0, 0x1, ''), -- North Wind
(47925, 0, 0x0, 0x1, ''), -- West Wind
(46766, 0, 0x0, 0x1, ''); -- Ice Storm Trigger


SET @CGUID := 222202;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+28;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 53488, 754, 1, 1, -306.4236, 816.6371, 199.572, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: -Unknown-)
(@CGUID+1, 53488, 754, 1, 1, -284.4271, 815.6476, 199.572, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: -Unknown-)
(@CGUID+2, 53488, 754, 1, 1, -296.2552, 832.4618, 199.572, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: -Unknown-)
(@CGUID+3, 53488, 754, 1, 1, -298.184, 799.3733, 199.572, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: -Unknown-)
(@CGUID+4, 21252, 754, 1, 1, -288.87, 817.814, 199.5723, 6.161012, 7200, 0, 0), -- World Trigger (Not Immune PC) (Area: -Unknown-)
(@CGUID+5, 21252, 754, 1, 1, -287.795, 816.681, 199.5723, 6.161012, 7200, 0, 0), -- World Trigger (Not Immune PC) (Area: -Unknown-)
(@CGUID+6, 46753, 754, 1, 1, -49.64583, 815.0816, 191.1009, 3.124139, 7200, 0, 0), -- Al'Akir (Area: -Unknown-)
(@CGUID+7, 36171, 754, 1, 1, -48.5313, 814.708, 191.1013, 0, 7200, 0, 0), -- World Trigger (Infinite AOI) (Area: -Unknown-)
(@CGUID+8, 45872, 754, 1, 1, -51.4635, 576.25, 200.0943, 1.518436, 7200, 0, 0), -- Rohash (Area: -Unknown-)
(@CGUID+9, 45870, 754, 1, 1, -47.9531, 1053.44, 200.0943, 4.764749, 7200, 0, 0), -- Anshal (Area: -Unknown-)
(@CGUID+10, 45871, 754, 1, 1, 189.394, 812.569, 200.0943, 3.351032, 7200, 0, 0), -- Nezir (Area: -Unknown-)
(@CGUID+11, 48977, 754, 1, 1, -51.04167, 818.6719, 191.1009, 0, 7200, 0, 0), -- Lightning Strike Trigger (Area: -Unknown-)
(@CGUID+12, 47806, 754, 1, 1, -46.7309, 815.668, 219.3093, 2.199115, 7200, 0, 0), -- Relentless Storm Initial Vehicle (Area: -Unknown-)
(@CGUID+13, 47806, 754, 1, 1, -46.7309, 815.668, 214.7853, 0.2443461, 7200, 0, 0), -- Relentless Storm Initial Vehicle (Area: -Unknown-)
(@CGUID+14, 47806, 754, 1, 1, -46.7309, 815.668, 216.4923, 3.124139, 7200, 0, 0), -- Relentless Storm Initial Vehicle (Area: -Unknown-)
(@CGUID+15, 47806, 754, 1, 1, -46.7309, 815.668, 220.5503, 1.151917, 7200, 0, 0), -- Relentless Storm Initial Vehicle (Area: -Unknown-)
(@CGUID+16, 47806, 754, 1, 1, -46.7309, 815.668, 214.1063, 1.675516, 7200, 0, 0), -- Relentless Storm Initial Vehicle (Area: -Unknown-)
(@CGUID+17, 46419, 754, 1, 1, -51.4479, 576.844, 251.4623, 2.338741, 7200, 0, 0), -- Hurricane (Area: -Unknown-)
(@CGUID+18, 46419, 754, 1, 1, -51.4479, 576.844, 248.5193, 2.338741, 7200, 0, 0), -- Hurricane (Area: -Unknown-)
(@CGUID+19, 46419, 754, 1, 1, -51.4479, 576.844, 250.6343, 2.338741, 7200, 0, 0), -- Hurricane (Area: -Unknown-)
(@CGUID+20, 46419, 754, 1, 1, -51.4479, 576.844, 249.8813, 2.338741, 7200, 0, 0), -- Hurricane (Area: -Unknown-)
(@CGUID+21, 46419, 754, 1, 1, -51.4479, 576.844, 247.5933, 2.338741, 7200, 0, 0), -- Hurricane (Area: -Unknown-)
(@CGUID+22, 47924, 754, 1, 1, -51.0087, 577.257, 199.5723, 0, 7200, 0, 0), -- East Wind (Area: -Unknown-)
(@CGUID+23, 19871, 754, 1, 1, -49.84143, 536.6068, 206.2773, 3.171784, 7200, 0, 0), -- World Trigger (Not Immune NPC) (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+24, 47926, 754, 1, 1, 188.601, 813.483, 199.5723, 0, 7200, 0, 0), -- North Wind (Area: -Unknown-)
(@CGUID+25, 47925, 754, 1, 1, -48.0816, 1053.93, 199.5723, 0, 7200, 0, 0), -- West Wind (Area: -Unknown-)
(@CGUID+26, 46766, 754, 1, 1, -26.2274, 860.302, 191.2083, 0, 7200, 0, 0), -- Ice Storm Trigger (Area: -Unknown-)
(@CGUID+27, 46766, 754, 1, 1, -6.0625, 842.55, 191.2083, 0, 7200, 0, 0), -- Ice Storm Trigger (Area: -Unknown-)
(@CGUID+28, 46766, 754, 1, 1, 0.385417, 816.236, 191.2083, 0, 7200, 0, 0); -- Ice Storm Trigger (Area: -Unknown-)
