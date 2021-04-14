UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176051; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176048; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176050; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176046; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176049; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176047; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=179264; -- Giant Clam
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=179345; -- Deeprun Chest
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176109; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176104; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176105; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176102; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176101; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176103; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176008; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176012; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176010; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176017; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176009; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176013; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176019; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176018; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176007; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176098; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176107; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176100; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176028; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176027; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176029; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176099; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176025; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176106; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176108; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176023; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176024; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176015; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176011; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176016; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176004; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176005; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176014; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176006; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176026; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176021; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176020; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176022; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176032; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176030; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176035; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176033; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176034; -- Subway Bench
UPDATE `gameobject_template` SET `WDBVerified`=15595 WHERE `entry`=176031; -- Subway Bench

SET @OGUID := 371;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+115;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 208864, 369, 1, 1, -25.81312, -24.38962, -4.297369, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+1, 176044, 369, 1, 1, -61.65418, 19.00144, -4.294851, 0.07854, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+2, 176042, 369, 1, 1, -61.45747, -0.5462993, -4.29485, 6.073748, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+3, 208864, 369, 1, 1, -62.29871, 0.4384706, -4.297353, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+4, 176045, 369, 1, 1, -61.45748, 32.30244, -4.294851, 6.073748, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+5, 176043, 369, 1, 1, -61.65417, -13.84751, -4.294851, 0.07854, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+6, 176041, 369, 1, 1, -64.57018, 21.82545, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+7, 176039, 369, 1, 1, -64.24799, 25.16312, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+8, 176038, 369, 1, 1, -64.39702, -3.870081, -4.294851, 6.204646, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+9, 176037, 369, 1, 1, -64.24799, -7.221647, -4.29485, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+10, 176040, 369, 1, 1, -64.39703, 28.51469, -4.29485, 6.204646, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+11, 176036, 369, 1, 1, -64.57018, -10.55954, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+12, 208864, 369, 1, 1, -63.69213, -15.59292, -4.297354, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+13, 208864, 369, 1, 1, -65.49454, -11.31814, -4.297354, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+14, 208864, 369, 1, 1, -55.16456, -37.43731, -4.297352, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+15, 176051, 369, 1, 1, -80.73289, 18.89098, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+16, 176048, 369, 1, 1, -80.60516, -1.02612, -4.294851, 6.204646, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+17, 208864, 369, 1, 1, -80.1594, -5.485014, -4.297352, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+18, 176050, 369, 1, 1, -80.63712, 24.52901, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+19, 208864, 369, 1, 1, -81.32017, 22.30112, -4.297349, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+20, 176046, 369, 1, 1, -80.63712, -7.943436, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+21, 176049, 369, 1, 1, -80.60516, 31.44611, -4.294851, 6.204646, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+22, 176047, 369, 1, 1, -80.73289, -13.58124, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+23, 208864, 369, 1, 1, -77.95713, 45.4724, -4.297347, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+24, 175668, 369, 1, 1, 112.3642, 5.079133, -4.357647, 0.8508465, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Postbox (Area: -Unknown-)
(@OGUID+25, 175665, 369, 1, 1, 112.0717, 21.57919, -0.967929, 6.278823, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Doodad_DwarfSign_Fireworks01 (Area: -Unknown-)
(@OGUID+26, 208864, 369, 1, 1, 40.01941, -25.9875, -4.297345, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+27, 176054, 369, 1, 1, 23.41197, -10.51944, -4.294851, 3.063024, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+28, 176058, 369, 1, 1, 20.47242, -13.84323, -4.29485, 2.932139, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+29, 176053, 369, 1, 1, 23.26293, -7.167883, -4.29485, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+30, 176059, 369, 1, 1, 20.66912, -0.5420122, -4.29485, 3.220161, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+31, 176052, 369, 1, 1, 23.58513, -3.829993, -4.294851, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+32, 208864, 369, 1, 1, 21.65013, -15.25156, -4.297355, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+33, 208864, 369, 1, 1, 14.71833, -37.30925, -4.297353, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+34, 208864, 369, 1, 1, -0.5995102, 33.58908, -13.86343, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+35, 176055, 369, 1, 1, 22.82857, 25.08885, -4.294851, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+36, 176056, 369, 1, 1, 22.97761, 21.73729, -4.29485, 3.063024, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+37, 176060, 369, 1, 1, 20.23477, 31.25052, -4.294851, 3.220161, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+38, 176057, 369, 1, 1, 23.15076, 28.42652, -4.29485, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+39, 176061, 369, 1, 1, 20.03805, 17.94952, -4.294851, 2.932139, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+40, 208864, 369, 1, 1, 21.24571, 17.08864, -4.29735, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+41, 208864, 369, 1, 1, 16.44149, 46.07506, -4.297347, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+42, 176066, 369, 1, 1, 39.77529, 27.31063, -4.29485, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+43, 176067, 369, 1, 1, 39.87106, 32.94865, -4.294852, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+44, 208864, 369, 1, 1, 37.16822, 44.65622, -4.297347, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+45, 178304, 369, 1, 1, -22.5045, 44.43635, -4.297362, 1.291542, 0, 0, 0, 1, 7200, 255, 1), -- Box o' Squirrels (Area: -Unknown-)
(@OGUID+46, 178304, 369, 1, 1, -19.66363, 44.25616, -4.297363, 5.270896, 0, 0, 0, 1, 7200, 255, 1), -- Box o' Squirrels (Area: -Unknown-)
(@OGUID+47, 178304, 369, 1, 1, -16.77179, 44.47802, -4.297363, 1.832595, 0, 0, 0, 1, 7200, 255, 1), -- Box o' Squirrels (Area: -Unknown-)
(@OGUID+48, 176079, 369, 1, 1, -19.98258, 31.24376, -4.294851, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+49, 176070, 369, 1, 1, -17.01924, 31.44611, -4.294851, 6.204646, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+50, 208864, 369, 1, 1, -18.80994, 28.25147, -4.297366, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+51, 176078, 369, 1, 1, -20.07835, 25.60595, -4.294851, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+52, 176068, 369, 1, 1, -17.0512, 24.52901, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+53, 176077, 369, 1, 1, -20.11032, 18.68863, -4.294851, 3.063024, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+54, 176069, 369, 1, 1, -17.14698, 18.89098, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+55, 176072, 369, 1, 1, -20.56989, -1.323538, -4.294851, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+56, 176074, 369, 1, 1, -17.67365, -1.026116, -4.294851, 6.204646, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+57, 208864, 369, 1, 1, -18.22651, -5.197068, -4.297369, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+58, 176071, 369, 1, 1, -20.66567, -6.961567, -4.294851, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+59, 176075, 369, 1, 1, -17.70562, -7.943431, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+60, 176076, 369, 1, 1, -17.80138, -13.58124, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+61, 176073, 369, 1, 1, -20.69763, -13.87867, -4.294851, 3.063024, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+62, 208864, 369, 1, 1, 9.727059, -23.84358, -13.86343, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+63, 176065, 369, 1, 1, 39.74333, 20.39353, -4.294851, 3.063024, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+64, 176064, 369, 1, 1, 39.63186, -13.18416, -4.294851, 3.063024, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+65, 176063, 369, 1, 1, 39.7596, -0.6290326, -4.294851, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+66, 176062, 369, 1, 1, 39.66383, -6.266838, -4.294851, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+67, 175667, 369, 1, 1, 109.8475, 4.727701, -4.294434, 0.8508465, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Brazier (Area: -Unknown-)
(@OGUID+68, 175666, 369, 1, 1, 109.3507, 16.21418, -4.294434, 0.8508465, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Brazier (Area: -Unknown-)
(@OGUID+69, 179264, 369, 1, 1, -79.30329, 1211.732, -122.8182, 0.4014249, 0, 0, 0, 1, 7200, 255, 0), -- Giant Clam (Area: -Unknown-)
(@OGUID+70, 179264, 369, 1, 1, 37.43438, 1316.428, -121.9855, 3.839725, 0, 0, 0, 1, 7200, 255, 1), -- Giant Clam (Area: -Unknown-)
(@OGUID+71, 179345, 369, 1, 1, 57.43581, 1206.985, -121.5893, 3.630291, 0, 0, 0, 1, 7200, 255, 1), -- Deeprun Chest (Area: -Unknown-)
(@OGUID+72, 176109, 369, 1, 1, -17.67386, 2480.754, -4.294851, 6.204646, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+73, 176104, 369, 1, 1, -17.70583, 2473.837, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+74, 176105, 369, 1, 1, -17.8016, 2468.2, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+75, 176102, 369, 1, 1, -20.57011, 2480.457, -4.294851, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+76, 176101, 369, 1, 1, -20.66589, 2474.819, -4.294851, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+77, 176103, 369, 1, 1, -20.69785, 2467.902, -4.294851, 3.063024, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+78, 176008, 369, 1, 1, 23.49342, 2472.218, -4.294677, 3.063024, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+79, 176012, 369, 1, 1, 20.75057, 2481.732, -4.294677, 3.220161, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+80, 176010, 369, 1, 1, 20.55386, 2501.279, -4.294677, 2.932139, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+81, 176017, 369, 1, 1, 39.70155, 2469.287, -4.294677, 3.063024, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+82, 176009, 369, 1, 1, 23.66658, 2478.907, -4.294677, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+83, 176013, 369, 1, 1, 20.55387, 2468.431, -4.294677, 2.932139, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+84, 176019, 369, 1, 1, 39.82929, 2481.842, -4.294678, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+85, 176018, 369, 1, 1, 39.73352, 2476.204, -4.294677, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+86, 176007, 369, 1, 1, 23.34438, 2475.57, -4.294677, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+87, 176098, 369, 1, 1, -19.9828, 2513.025, -4.294851, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+88, 176107, 369, 1, 1, -17.1472, 2500.672, -4.294851, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+89, 176100, 369, 1, 1, -20.11053, 2500.469, -4.294851, 3.063024, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+90, 176028, 369, 1, 1, -61.13838, 2469.482, -4.294677, 0.07854, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+91, 176027, 369, 1, 1, -61.57273, 2501.275, -4.294676, 0.07854, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+92, 176029, 369, 1, 1, -60.94166, 2482.783, -4.294677, 6.073748, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+93, 176099, 369, 1, 1, -20.07856, 2507.387, -4.294851, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+94, 176025, 369, 1, 1, -64.05437, 2472.306, -4.294677, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+95, 176106, 369, 1, 1, -17.01946, 2513.227, -4.294851, 6.204646, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+96, 176108, 369, 1, 1, -17.05142, 2506.31, -4.29485, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+97, 176023, 369, 1, 1, -63.73218, 2475.644, -4.294677, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+98, 176024, 369, 1, 1, -63.88121, 2478.996, -4.294677, 6.204646, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+99, 176015, 369, 1, 1, 39.82929, 2514.314, -4.294678, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+100, 176011, 369, 1, 1, 20.75057, 2514.581, -4.294677, 3.220161, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+101, 176016, 369, 1, 1, 39.70155, 2501.759, -4.294677, 3.063024, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+102, 176004, 369, 1, 1, 23.66657, 2511.292, -4.294677, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+103, 176005, 369, 1, 1, 23.34438, 2507.955, -4.294677, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+104, 176014, 369, 1, 1, 39.73352, 2508.677, -4.294677, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+105, 176006, 369, 1, 1, 23.49342, 2504.603, -4.294677, 3.063024, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+106, 176026, 369, 1, 1, -61.37602, 2514.576, -4.294676, 6.073748, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+107, 176021, 369, 1, 1, -64.16653, 2507.901, -4.294676, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+108, 176020, 369, 1, 1, -64.48873, 2504.563, -4.294677, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+109, 176022, 369, 1, 1, -64.31558, 2511.252, -4.294677, 6.204646, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+110, 176032, 369, 1, 1, -80.53546, 2513.917, -4.294677, 6.204646, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+111, 176030, 369, 1, 1, -80.56743, 2507, -4.294678, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+112, 176035, 369, 1, 1, -80.77467, 2467.784, -4.294678, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+113, 176033, 369, 1, 1, -80.64693, 2480.339, -4.294677, 6.204646, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+114, 176034, 369, 1, 1, -80.6789, 2473.422, -4.294677, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- Subway Bench (Area: -Unknown-)
(@OGUID+115, 176031, 369, 1, 1, -80.6632, 2501.362, -4.294678, 0, 0, 0, 1, -4.371139E-08, 7200, 255, 1); -- Subway Bench (Area: -Unknown-)

UPDATE `creature_template` SET `faction_A`=31, `faction_H`=31, `speed_walk`=0.7142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=13016; -- Deeprun Rat
UPDATE `creature_template` SET `minlevel`=12, `maxlevel`=12, `faction_A`=55, `faction_H`=55, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=12997; -- Monty
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `faction_A`=55, `faction_H`=55, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512, `HoverHeight`=1 WHERE `entry`=14041; -- Haggle
UPDATE `creature_template` SET `minlevel`=41, `maxlevel`=42, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832, `HoverHeight`=1 WHERE `entry`=5186; -- Basking Shark
UPDATE `creature_template` SET `minlevel`=57, `maxlevel`=57, `faction_A`=7, `faction_H`=7, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=10956; -- Naga Siren
UPDATE `creature_template` SET `minlevel`=62, `maxlevel`=62, `faction_A`=7, `faction_H`=7, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=10942; -- Nessy
UPDATE `creature_template` SET `minlevel`=20, `maxlevel`=20, `faction_A`=55, `faction_H`=55, `speed_walk`=0.1428571, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=512, `HoverHeight`=1 WHERE `entry`=14121; -- Deeprun Diver
UPDATE `creature_template` SET `gossip_menu_id`=4845, `minlevel`=12, `maxlevel`=12, `faction_A`=55, `faction_H`=55, `npcflag`=131, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=13018; -- Nipsy

DELETE FROM `creature_template_addon` WHERE `entry` IN (13016, 13016, 13016, 13016, 13016, 13016, 13016, 13016, 13016, 13016, 13016, 13016, 13016, 13016, 12997, 14041, 13016, 5186, 10956, 10942, 10942, 5186, 10942, 14121, 10942, 5186, 10942, 13016, 5186, 14121, 10942, 5186, 13018);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(13016, 0, 0x0, 0x1, ''), -- Deeprun Rat
(12997, 0, 0x0, 0x101, ''), -- Monty
(14041, 0, 0x0, 0x101, ''), -- Haggle
(5186, 0, 0x0, 0x1, ''), -- Basking Shark
(10956, 0, 0x0, 0x1, ''), -- Naga Siren
(10942, 0, 0x0, 0x1, '3417'), -- Nessy - Thrash
(14121, 0, 0x0, 0x101, '22431'), -- Deeprun Diver - Tag: Bubbles
(13018, 0, 0x0, 0x101, ''); -- Nipsy

UPDATE `creature_model_info` SET `bounding_radius`=0.6, `combat_reach`=1.5 WHERE `modelid`=1557;
UPDATE `creature_model_info` SET `bounding_radius`=0.3519, `combat_reach`=1.725, `gender`=0 WHERE `modelid`=5485;
UPDATE `creature_model_info` SET `bounding_radius`=7.5, `combat_reach`=20 WHERE `modelid`=10244;
UPDATE `creature_model_info` SET `bounding_radius`=0.75, `combat_reach`=1.875, `gender`=1 WHERE `modelid`=11263;
UPDATE `creature_model_info` SET `bounding_radius`=0.3519, `combat_reach`=1.725, `gender`=0 WHERE `modelid`=12965;
UPDATE `creature_model_info` SET `bounding_radius`=0.3519, `combat_reach`=1.725, `gender`=0 WHERE `modelid`=14093;
UPDATE `creature_model_info` SET `bounding_radius`=0.52785, `combat_reach`=2.5875, `gender`=0 WHERE `modelid`=14172;

SET @CGUID := 26;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+32;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 13016, 369, 1, 1, -42.90521, -32.61866, -4.18618, 5.050751, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+1, 13016, 369, 1, 1, -47.44514, 45.0962, -13.86342, 0.9821138, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+2, 13016, 369, 1, 1, 4.959308, 85.12321, -13.86341, 1.31832, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+3, 13016, 369, 1, 1, -50.17727, -22.15102, -13.86343, 1.248308, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+4, 13016, 369, 1, 1, -61.76358, 10.18176, -4.297349, 1.96085, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+5, 13016, 369, 1, 1, -58.41, -12.19245, -4.297352, 1.479001, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+6, 13016, 369, 1, 1, -68.97044, 31.41254, -4.297347, 6.033054, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+7, 13016, 369, 1, 1, -72.52555, -18.03675, -4.297348, 5.222579, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+8, 13016, 369, 1, 1, -77.777, -16.82243, -4.297345, 4.245398, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+9, 13016, 369, 1, 1, -48.19755, 86.61305, -13.86341, 4.16241, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+10, 13016, 369, 1, 1, 5.488541, 49.85864, -13.86341, 4.702066, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+11, 13016, 369, 1, 1, 23.6695, 11.45184, -4.297349, 5.622178, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+12, 13016, 369, 1, 1, 29.00482, 21.21941, -4.297349, 2.687068, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+13, 13016, 369, 1, 1, 29.61788, 38.26885, -4.525192, 3.018909, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+14, 12997, 369, 1, 1, -19.63116, 40.07523, -4.297364, 4.799655, 7200, 0, 0), -- Monty (Area: -Unknown-)
(@CGUID+15, 14041, 369, 1, 1, 30.89553, -16.94747, -4.29735, 0.0809125, 7200, 0, 0), -- Haggle (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+16, 13016, 369, 1, 1, 33.32092, -20.25253, -4.297348, 5.446306, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+17, 5186, 369, 1, 1, -101.827, 1160.8, -119.6302, 1.36491, 7200, 0, 0), -- Basking Shark (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+18, 10956, 369, 1, 1, 50.12223, 1189.931, -121.3143, 1.609128, 7200, 0, 0), -- Naga Siren (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+19, 10942, 369, 1, 1, -113.8064, 1254.373, -123.0315, 0.541052, 7200, 0, 0), -- Nessy (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+20, 10942, 369, 1, 1, -113.8064, 1254.373, -123.0315, 0.541052, 7200, 0, 0), -- Nessy (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+21, 5186, 369, 1, 1, -148.6604, 1274.092, -122.5949, 1.761536, 7200, 0, 0), -- Basking Shark (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+22, 10942, 369, 1, 1, -125.3612, 1163.625, -118.5928, 2.094395, 7200, 0, 0), -- Nessy (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+23, 14121, 369, 1, 1, 44.75809, 1206.403, -122.0373, 2.64896, 7200, 0, 0), -- Deeprun Diver (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+24, 10942, 369, 1, 1, 77.93309, 1342.794, -118.1664, 2.389638, 7200, 0, 0), -- Nessy (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+25, 5186, 369, 1, 1, 72.2432, 1354.585, -119.3735, 2.641814, 7200, 0, 0), -- Basking Shark (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+26, 10942, 369, 1, 1, 75.55157, 1339.963, -117.9171, 1.745329, 7200, 0, 0), -- Nessy (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+27, 13016, 369, 1, 1, 20.61483, 5.486512, -4.293704, 3.468456, 7200, 0, 0), -- Deeprun Rat (Area: -Unknown-)
(@CGUID+28, 5186, 369, 1, 1, 94.47649, 1049.415, -122.2966, 0.7322908, 7200, 0, 0), -- Basking Shark (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+29, 14121, 369, 1, 1, 67.81148, 1113.719, -120.7867, 1.741269, 7200, 0, 0), -- Deeprun Diver (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+30, 10942, 369, 1, 1, -113.8064, 1254.373, -123.0315, 0.541052, 7200, 0, 0), -- Nessy (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+31, 5186, 369, 1, 1, 125.7925, 1192.208, -120.3509, 6.201082, 7200, 0, 0), -- Basking Shark (Area: -Unknown-) (possible waypoints or random movement)
(@CGUID+32, 13018, 369, 1, 1, -17.58867, 2459.482, -4.29719, 5.57304, 7200, 0, 0); -- Nipsy (Area: -Unknown-)

DELETE FROM `npc_vendor` WHERE (`entry`=13018 AND `item`=17119);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`) VALUES
-- 13018 (Nipsy)
(13018, 17119, 120, 0, 0); -- Deeprun Rat Kabob

DELETE FROM `npc_text` WHERE `ID` IN (5894, 5920);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(5894, 'Monty be me name an'' rats be me game.', '', 0, 1, 1, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 5894
(5920, 'You''ll find no finer rat kabob this side of Khaz Modan!', '', 0, 1, 1, 5, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 5920

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=4845 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(4845, 0, 1, 'I wish to make a purchase, Nipsy.', 0, 0, ''); -- Nipsy
