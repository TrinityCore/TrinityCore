-- Lion's Rest spawns
SET @CGUID:=452693;
SET @OGUID:=301120;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+17 OR `guid` IN (313455,313780,313781,313783,313865,313866,313754,313782,313846,313857);
INSERT INTO `creature` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`PhaseId`,`PhaseGroup`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`,`VerifiedBuild`) VALUES
(@CGUID+0,  5505, 0, 0, 0, 1, 0, 0, 0, 0, -8693.819, 984.0191, 77.31424, 2.636569, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Theridran (Area: -Lion's Rest-)
(@CGUID+1,112958, 0, 0, 0, 1, 0, 0, 0, 0, -8741.636, 1061.229, 79.58313, 1.983743, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Soulare of Andorhal (Area: -Lion's Rest-)
(@CGUID+2,  5502, 0, 0, 0, 1, 0, 0, 0, 0, -8758.826, 1013.203, 79.58459, 2.546376, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Shylamiir (Area: -Lion's Rest-)
(@CGUID+3, 11827, 0, 0, 0, 1, 0, 0, 0, 0, -8749.707, 946.7552, 85.35487, 6.038985, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Kimberly Grant (Area: -Lion's Rest-)
(@CGUID+4, 11828, 0, 0, 0, 1, 0, 0, 0, 0, -8749.866, 944.9496, 85.35487, 0.1462256,120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Kelly Grant (Area: -Lion's Rest-)
(@CGUID+5,114246, 0, 0, 0, 1, 0, 0, 0, 0, -8705.697, 937.4265, 85.50231, 3.205591, 120,10, 0, 0, 0, 1, 0, 0, 0, 23420), -- Karl Wogksch (Area: -Lion's Rest-)
(@CGUID+6,  9977, 0, 0, 0, 1, 0, 0, 0, 0, -8697.276, 984.6198, 78.25348, 0.2270845,120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Sylista (Area: -Lion's Rest-)
(@CGUID+7,  7295, 0, 0, 0, 1, 0, 0, 0, 0, -8694.314, 986.7344, 77.20554, 4.761206, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Shailiea (Area: -Lion's Rest-)
(@CGUID+8,  5506, 0, 0, 0, 1, 0, 0, 0, 0, -8823.567, 941.2604, 91.32404, 0.9397598,120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Maldryn (Area: -Lion's Rest-)
(@CGUID+9,  5504, 0, 0, 0, 1, 0, 0, 0, 0, -8737.526, 911.7239, 85.3549,  4.781983, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Sheldras Moontree (Area: -Lion's Rest-)
(@CGUID+10,   68, 0, 0, 0, 1, 0, 0, 0, 0, -8719.207, 951.8316, 85.35484, 3.169507, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormwind City Guard (Area: -Lion's Rest-)
(@CGUID+11,   68, 0, 0, 0, 1, 0, 0, 0, 0, -8719.127, 941.743,  85.35488, 3.22979,  120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormwind City Guard (Area: -Lion's Rest-)
(@CGUID+12,   68, 0, 0, 0, 1, 0, 0, 0, 0, -8753.232, 951.5469, 85.35602, 6.176689, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormwind City Guard (Area: -Lion's Rest-)
(@CGUID+13,   68, 0, 0, 0, 1, 0, 0, 0, 0, -8753.536, 941.3785, 85.35492, 0.2123818,120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormwind City Guard (Area: -Lion's Rest-)
(@CGUID+14,   68, 0, 0, 0, 1, 0, 0, 0, 0, -8732.926, 1027.547, 79.5823,  4.894801, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormwind City Guard (Area: -Lion's Rest-)
(@CGUID+15,   68, 0, 0, 0, 1, 0, 0, 0, 0, -8740.507, 1027.59,  79.5823,  4.791157, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormwind City Guard (Area: -Lion's Rest-)
(@CGUID+16,42421, 0, 0, 0, 1, 0, 0, 0, 0, -8655.056, 918.3768, 97.87857, 2.692133, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420), -- Stormwind Fisherman (Area: Stormwind Harbor)
(@CGUID+17,  297, 0, 0, 0, 1, 0, 0, 0, 0, -8861.116, 957.566, 103.3211,  4.607669, 120, 0, 0, 0, 0, 0, 0, 0, 0, 23420); -- Caretaker Folsom (Area: Stormwind Harbor)

DELETE FROM `creature_template_addon` WHERE `entry` IN (112958,5502,11827,11828,5504,114246,9977,7295,5505,5506,112912);
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`aiAnimKit`,`movementAnimKit`,`meleeAnimKit`,`auras`) VALUES
(112958,0, 0, 0,   1, 0, 0, 0, 0, ''), -- Soulare of Andorhal
(5502,  0, 0, 0, 257, 0, 0, 0, 0, ''), -- Shylamiir
(11827, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Kimberly Grant
(11828, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Kelly Grant
(5504,  0, 0, 0, 257, 0, 0, 0, 0, ''), -- Sheldras Moontree
(114246,0, 0, 0, 256, 0, 0, 0, 0, ''), -- Karl Wogksch
(9977,  0, 0, 0, 257, 0, 0, 0, 0, ''), -- Sylista
(7295,  0, 0, 0, 257, 0, 0, 0, 0, ''), -- Shailiea
(5505,  0, 0, 0, 257, 0, 0, 0, 0, ''), -- Theridran
(5506,  0, 0, 0, 257, 0, 0, 0, 0, ''); -- Maldryn

UPDATE `creature_template` SET `minlevel`=90, `maxlevel`=90, `faction`=2110, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=2, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=112958; -- Soulare of Andorhal
UPDATE `creature_template` SET `npcflag`=17, `unit_flags`=512, `flags_extra`=0 WHERE `entry`=5502; -- Shylamiir
UPDATE `creature_template` SET `unit_flags`=512, `flags_extra`=0 WHERE `entry`=11828; -- Kelly Grant
UPDATE `creature_template` SET `unit_flags`=512, `flags_extra`=0 WHERE `entry`=11827; -- Kimberly Grant
UPDATE `creature_template` SET `gossip_menu_id`=0, `flags_extra`=0 WHERE `entry`=5504; -- Sheldras Moontree
UPDATE `creature_template` SET `minlevel`=30, `maxlevel`=30, `faction`=12, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_class`=1, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=114246; -- Karl Wogksch
UPDATE `creature_template` SET `gossip_menu_id`=0, `npcflag`=4194433, `flags_extra`=0 WHERE `entry`=9977; -- Sylista
UPDATE `creature_template` SET `unit_flags`=512, `flags_extra`=0 WHERE `entry`=7295; -- Shailiea
UPDATE `creature_template` SET `gossip_menu_id`=0, `unit_flags`=512, `flags_extra`=0 WHERE `entry`=5505; -- Theridran
UPDATE `creature_template` SET `gossip_menu_id`=0, `unit_flags`=512, `flags_extra`=0 WHERE `entry`=5506; -- Maldryn

DELETE FROM `gossip_menu` WHERE (`MenuID`=14103 AND `TextID`=4783) OR (`MenuID`=14102 AND `TextID`=4783);
INSERT INTO `gossip_menu` (`MenuID`,`TextID`) VALUES
(14103, 4783), -- 5505 (Theridran)
(14102, 4783); -- 5504 (Sheldras Moontree)

-- Lion's Rest gameobjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+37 OR `guid` IN (219909,219989);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`zoneId`,`areaId`,`spawnMask`,`PhaseId`,`PhaseGroup`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`,`VerifiedBuild`) VALUES
(@OGUID+0,  254108, 0, 0, 0, 1, 0, 0, -8776.596, 942.9097, 85.27396, 1.570796, 0, 0,  0.7071066, 0.7071069, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+1,  254102, 0, 0, 0, 1, 0, 0, -8756.877, 1008.974, 79.49895, 1.544616, 0, 0, 0.6977901,  0.7163023, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+2,  254104, 0, 0, 0, 1, 0, 0, -8733.457, 997.9514, 79.49966, 3.141593, 0, 0, -1,         0,         120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+3,  254095, 0, 0, 0, 1, 0, 0, -8715.493, 1008.25,  79.49896, 1.579522, 0, 0, 0.7101851,  0.704015,  120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+4,  254103, 0, 0, 0, 1, 0, 0, -8740.054, 998.0452, 79.49966,        0, 0, 0, 0,          1,         120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+5,  254094, 0, 0, 0, 1, 0, 0, -8733.29,  1014.542, 79.49966, 3.132858, 0, 0, 0.9999905,  0.00436732,120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+6,  254100, 0, 0, 0, 1, 0, 0, -8739.946, 1006.385, 79.49966,        0, 0, 0, 0,          1,         120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+7,  254101, 0, 0, 0, 1, 0, 0, -8733.386, 1006.177, 79.49966, 3.141593, 0, 0, -1,         0,         120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+8,  254099, 0, 0, 0, 1, 0, 0, -8739.913, 1014.516, 79.49966, 6.257008, 0, 0, -0.01308823,0.9999143, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+9,  254090, 0, 0, 0, 1, 0, 0, -8728.752, 1059.432, 79.49894, 4.319694, 0, 0, -0.8314686, 0.5555717, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+10, 254091, 0, 0, 0, 1, 0, 0, -8721.917, 1054.064, 79.49721, 3.909541, 0, 0, -0.9271832, 0.3746083, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+11, 254096, 0, 0, 0, 1, 0, 0, -8737.323, 1060.873, 79.49894, 4.677484, 0, 0, -0.7193394, 0.6946588, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+12, 254097, 0, 0, 0, 1, 0, 0, -8745.264, 1058.743, 79.49895, 5.253445, 0, 0, -0.4924221, 0.8703565, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+13, 254098, 0, 0, 0, 1, 0, 0, -8751.582, 1052.863, 79.49895, 5.637416, 0, 0, -0.3173037, 0.948324,  120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+14, 254088, 0, 0, 0, 1, 0, 0, -8695.686, 950.0261, 85.27152, 4.71239,  0, 0, -0.7071066, 0.7071069, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+15, 254089, 0, 0, 0, 1, 0, 0, -8695.616, 943.3038, 85.27222, 1.570796, 0, 0,  0.7071066, 0.7071069, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+16, 254092, 0, 0, 0, 1, 0, 0, -8713.389, 950.0121, 85.27222, 4.71239,  0, 0, -0.7071066, 0.7071069, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+17, 254093, 0, 0, 0, 1, 0, 0, -8713.408, 943.257,  85.27222, 1.56207,  0, 0,  0.7040148, 0.7101853, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+18, 254105, 0, 0, 0, 1, 0, 0, -8739.446, 968.0712, 85.27222, 6.265733, 0, 0, -0.00872612,0.9999619, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+19, 254106, 0, 0, 0, 1, 0, 0, -8734.576, 967.9792, 85.27151, 3.150327, 0, 0, -0.9999905, 0.00436732,120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+20, 254117, 0, 0, 0, 1, 0, 0, -8735.426, 919.9445, 85.27156, 3.150327, 0, 0, -0.9999905, 0.00436732,120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+21, 254118, 0, 0, 0, 1, 0, 0, -8740.283, 919.783,  85.27145,        0, 0, 0,          0, 1,         120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+22, 254115, 0, 0, 0, 1, 0, 0, -8759.185, 949.6875, 85.27222, 4.71239,  0, 0, -0.7071066, 0.7071069, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+23, 254116, 0, 0, 0, 1, 0, 0, -8758.993, 942.9705, 85.27222, 1.570796, 0, 0,  0.7071066, 0.7071069, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+24, 254107, 0, 0, 0, 1, 0, 0, -8776.781, 949.6632, 85.27222, 4.71239,  0, 0, -0.7071066, 0.7071069, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+25, 254121, 0, 0, 0, 1, 0, 0, -8648.596, 955.2656, 91.2407, 2.574359,  0, 0,  0.9600496, 0.2798298, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+26, 254119, 0, 0, 0, 1, 0, 0, -8663.191, 961.6042, 91.2407, 5.515242,  0, 0, -0.3746061, 0.927184,  120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+27, 254120, 0, 0, 0, 1, 0, 0, -8652.234, 945.1927, 91.2407, 3.028127,  0, 0,  0.9983912, 0.05670215,120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+28, 254122, 0, 0, 0, 1, 0, 0, -8826.399, 923.9288, 91.23985,0.7504908, 0, 0,  0.3665009, 0.9304177, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+29, 254123, 0, 0, 0, 1, 0, 0, -8841.748, 943.6146, 91.2478, 0.4363316, 0, 0,  0.2164392, 0.9762961, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+30, 254110, 0, 0, 0, 1, 0, 0, -8810.929, 944.717,  91.2407, 5.794496,  0, 0, -0.2419205, 0.9702961, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+31, 254114, 0, 0, 0, 1, 0, 0, -8810.774, 953.8768, 91.24074,0.383973,  0, 0,  0.1908092, 0.9816271, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+32, 254109, 0, 0, 0, 1, 0, 0, -8818.886, 940.0903, 91.2407, 4.721118,  0, 0, -0.7040138, 0.7101862, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+33, 254113, 0, 0, 0, 1, 0, 0, -8818.41,  959.2396, 91.2407, 1.492256,  0, 0,  0.6788006, 0.7343227, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+34, 254111, 0, 0, 0, 1, 0, 0, -8827.359, 945.0261, 91.2407, 3.673924,  0, 0, -0.9647865, 0.2630341, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+35, 254112, 0, 0, 0, 1, 0, 0, -8826.882, 955.0938, 91.2407, 2.565632,  0, 0,  0.9588194, 0.2840165, 120, 255, 1, 23420), -- Bench (Area: -Lion's Rest-)
(@OGUID+36,   1561, 0, 0, 0, 1, 0, 0, -8859.705, 957.8403, 103.2185,3.455756,  0, 0, -0.9876881, 0.1564362, 120, 255, 1, 23420), -- Sealed Crate (Area: The Canals)
(@OGUID+37, 203800, 0, 0, 0, 1, 0, 0, -8653.264, 919.0452, 97.76823,       0,  0, 0,          0, 1,         120, 255, 1, 23420); -- Barrel of Canal Fish (Area: Stormwind Harbor)

-- Stormwind City Cemetery gameobject
DELETE FROM `page_text` WHERE `ID`= 3715; -- Tiffin Ellerian Wrynn Memorial (206500)
INSERT INTO `page_text` (`ID`,`Text`,`NextPageID`,`PlayerConditionID`,`Flags`,`VerifiedBuild`) VALUES
(3715,'Tiffin Ellerian Wrynn \nQueen of Stormwind \nFair and just, a wit as quick as her smile. \nMay the Light inherit your warmth, for our world grows cold in your absence. ',0,0,0,23420);
