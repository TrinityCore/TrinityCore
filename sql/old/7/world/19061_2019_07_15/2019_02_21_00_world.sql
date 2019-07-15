-- Pathing for  Entry: 45265 'TDB FORMAT' 
SET @NPC := 253837;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '84849');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-424.701,-538.622,894.0889,0,0,0,0,100,0),
(@PATH,2,-449.543,-538.153,894.0859,0,0,0,0,100,0),
(@PATH,3,-424.701,-538.622,894.0889,0,0,0,0,100,0),
(@PATH,4,-403.469,-539.156,894.0871,0,0,0,0,100,0);
-- 0x20307C53E02C344000034900004E80CA .go xyz -424.701 -538.622 894.0889

DELETE FROM `creature_formations` WHERE `leaderGUID`= 253837;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
-- Front Line
(253837, 253837, 0, 0, 515, 0, 0),
(253837, 253838, 6, 90, 515, 2, 4),
(253837, 253840, 12, 90, 515, 2, 4),
(253837, 253849, 6, 270, 515, 2, 4),
(253837, 253834, 12, 270, 515, 2, 4),
-- Back Line
(253837, 253836, 5, 0, 515, 2, 4),
(253837, 253843, 8, 45, 515, 2, 4),
(253837, 253835, 8, 315, 515, 2, 4),
(253837, 253844, 12, 65, 515, 2, 4),
(253837, 253847, 12, 295, 515, 2, 4);

-- Pathing for  Entry: 45265 'TDB FORMAT' 
SET @NPC := 253794;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '84849');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-423.875,-523.818,894.0902,0,0,0,0,100,0),
(@PATH,2,-401.708,-524.644,894.087,0,0,0,0,100,0),
(@PATH,3,-423.875,-523.818,894.0902,0,0,0,0,100,0),
(@PATH,4,-448.594,-523.03,894.0881,0,0,0,0,100,0);
-- 0x20307C53E02C344000034900044E80CA .go xyz -423.875 -523.818 894.0902

DELETE FROM `creature_formations` WHERE `leaderGUID`= 253794;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
-- Front Line
(253794, 253794, 0, 0, 515, 0, 0),
(253794, 253791, 6, 90, 515, 2, 4),
(253794, 253784, 12, 90, 515, 2, 4),
(253794, 253782, 6, 270, 515, 2, 4),
(253794, 253797, 12, 270, 515, 2, 4),
-- Back Line
(253794, 253795, 5, 0, 515, 2, 4),
(253794, 253798, 8, 45, 515, 2, 4),
(253794, 253790, 8, 315, 515, 2, 4),
(253794, 253788, 12, 65, 515, 2, 4),
(253794, 253792, 12, 295, 515, 2, 4);

-- Pathing for  Entry: 45265 'TDB FORMAT' 
SET @NPC := 253842;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '84849');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-323.597,-534.234,894.5809,0,0,0,0,100,0),
(@PATH,2,-321.976,-565.561,894.5803,0,0,0,0,100,0),
(@PATH,3,-323.597,-534.234,894.5809,0,0,0,0,100,0),
(@PATH,4,-361.729,-533.083,894.58,0,0,0,0,100,0);
-- 0x20307C53E02C344000034900014E80CA .go xyz -323.597 -534.234 894.5809

DELETE FROM `creature_formations` WHERE `leaderGUID`= 253842;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(253842, 253842, 0, 0, 515, 0, 0),
(253842, 253830, 6, 0, 515, 2, 4),
(253842, 253846, 6, 270, 515, 2, 4),
(253842, 253827, 9, 315, 515, 2, 4);

-- Set existing trash spawns to spawnMask 10 (25 normal and 25 heroic)
UPDATE `creature` SET `spawnDifficulties`="3,4,5,6" WHERE `map`=671 AND `spawnDifficulties`= "0,1,2,3";
UPDATE `creature` SET `spawnDifficulties`="5,6" WHERE `map`=671 AND `spawnDifficulties`= "2,3";
UPDATE `creature` SET `spawnDifficulties`= "6,4" WHERE `guid` IN (253849, 253847, 253798, 253795, 253791, 253783, 253779, 253843, 253838, 253835, 253799, 253790, 253782, 253778, 253846, 253842, 253837, 253834, 253830, 253827, 253797, 253794, 253789, 253787, 253844, 253840, 253836, 253800, 253792, 253788, 253784, 253780, 254253, 254250, 254249, 254170, 254167, 254164, 254258, 254254, 254252, 254166, 254165, 254163, 254256, 254255, 254251, 254161, 254160, 254159, 253948, 253941, 253938, 253936, 253934, 253932, 253928, 253926, 253898, 253892, 253947, 253935, 253931, 253925, 253896, 253949, 253945, 253940, 253939, 253911, 253906, 253996, 253995, 253993, 253990, 253943, 253918, 253913, 253909, 253902, 253994, 253992, 253991, 253989, 253942, 253921, 253912, 253908, 253900, 253952, 253946, 253930, 253924, 253916, 253907, 253944, 253933, 253929, 253923, 253915, 253905, 254037, 253997, 253986, 253937, 253927, 253922, 253919, 253903, 253901, 253988, 253987, 253985, 253984, 253983, 253982, 253920, 253917, 253914);

SET @CGUID := 339661;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+72;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 45261, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -449.3764, -510.8528, 894.088, 6.245684, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Shadow Knight (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 84827 - Shield Mastery)
(@CGUID+1, 45264, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -450.0513, -528.8401, 894.0882, 6.245687, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Crossfire (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+2, 45266, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -449.6014, -516.8486, 894.088, 6.245687, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Dark Mender (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+3, 45265, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -479.318, -524.196, 890.6763, 3.159046, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 84849 - Soul Blade)
(@CGUID+4, 45261, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -452.4585, -530.6738, 894.0883, 5.195304, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Shadow Knight (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 84827 - Shield Mastery)
(@CGUID+5, 45264, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -478.148, -538.096, 890.6763, 3.01942, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Crossfire (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+6, 45266, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -476.521, -528.498, 890.6763, 3.211406, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Dark Mender (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+7, 45261, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -476.142, -533.194, 890.6763, 3.141593, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Shadow Knight (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 84827 - Shield Mastery)
(@CGUID+8, 45265, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -447.8682, -522.9178, 894.1266, 6.245685, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 84849 - Soul Blade)
(@CGUID+9, 45266, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -398.1873, -548.8336, 894.0871, 4.744542, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Dark Mender (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+10, 45265, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -355.0883, -530.9302, 894.6034, 6.178656, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 84849 - Soul Blade)
(@CGUID+11, 45261, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -396.8199, -530.0619, 894.087, 1.859064, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Shadow Knight (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 84827 - Shield Mastery)
(@CGUID+12, 45266, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -397.8061, -533.0828, 894.087, 3.124424, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Dark Mender (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+13, 45265, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -356.887, -525.3019, 894.58, 0.9683747, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 84849 - Soul Blade)
(@CGUID+14, 46952, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -451.438, -685.332, 894.6663, 0.01745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Seer (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+15, 46951, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -448.806, -672.181, 894.6663, 6.038839, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+16, 46951, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -448.602, -697.616, 894.6633, 0.4363323, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+17, 47087, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -591.8993, -631.7761, 834.7148, 5.183628, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+18, 47086, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -595.0799, -636.0504, 834.7148, 5.794493, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+19, 47161, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -582.2778, -636.3976, 834.7148, 3.438299, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 42459 - Dual Wield)
(@CGUID+20, 46951, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -647.797, -672.542, 834.7153, 3.822271, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+21, 46952, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -656.394, -696.481, 834.7153, 2.042035, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Seer (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+22, 47151, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -656.922, -709.627, 834.7153, 1.902409, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Wind Breaker (Area: The Bastion of Twilight - Difficulty: 5) (Auras: )
(@CGUID+23, 47081, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -651.21, -703.512, 834.7153, 2.495821, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Elemental Firelord (Area: The Bastion of Twilight - Difficulty: 5) (Auras: )
(@CGUID+24, 46951, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -654.521, -673.438, 834.7153, 6.213372, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+25, 47151, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -623.816, -647.6996, 834.7148, 2.740167, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Wind Breaker (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+26, 47150, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -625.9271, -640.4375, 834.7148, 3.926991, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Earth Ravager (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+27, 47081, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -637.8854, -652.0816, 834.7148, 0.296706, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Elemental Firelord (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+28, 47152, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -582.17, -723.396, 834.7153, 0.6457718, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+29, 46951, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -649.672, -679.969, 834.7153, 3.508112, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+30, 46951, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -646.448, -697.309, 834.7153, 2.548181, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+31, 47086, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -596.8507, -640.4045, 834.7148, 0.06981317, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+32, 46952, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -641.885, -685.115, 834.7153, 3.124139, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Seer (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+33, 47161, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -586.7327, -631.717, 834.7148, 4.782202, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 42459 - Dual Wield)
(@CGUID+34, 46951, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -653.477, -694.368, 834.7153, 2.321288, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+35, 46951, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -649.323, -689.858, 834.7153, 2.80998, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+36, 47151, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -588.076, -717.471, 834.7153, 5.445427, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Wind Breaker (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+37, 47150, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -589.455, -724.906, 834.7153, 0.3490658, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Earth Ravager (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+38, 47081, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -573.538, -719.878, 834.7153, 3.001966, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Elemental Firelord (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+39, 46952, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -648.806, -684.971, 834.7153, 3.228859, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Seer (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+40, 47152, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -585.385, -722.53, 834.7153, 0.2617994, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+41, 46951, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -660.42, -697.372, 834.7153, 1.745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+42, 46952, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -657.023, -669.576, 834.7153, 4.328416, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Seer (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+43, 46951, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -660.252, -667.686, 834.7153, 4.433136, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Chosen Warrior (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+44, 47150, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -665.729, -709.622, 834.7153, 1.37881, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Earth Ravager (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+45, 47086, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -623.269, -738.898, 834.7143, 2.321288, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+46, 47086, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -627.818, -740.076, 834.7153, 1.762783, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+47, 47152, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -628.493, -644.3871, 834.7148, 3.839724, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+48, 47161, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -636.273, -735.965, 834.7153, 0.7504916, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+49, 47152, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -631.7535, -645.0538, 834.7148, 4.223697, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+50, 47087, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -633.142, -740.071, 834.7153, 1.151917, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+51, 47161, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -635.175, -729.597, 834.7153, 5.689773, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+52, 47161, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -649.372, -666.09, 834.7153, 3.717551, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+53, 47087, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -653.559, -657.622, 834.7153, 3.961897, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 5) (Auras: )
(@CGUID+54, 47086, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -651.559, -661.814, 834.7153, 3.787364, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Crimsonborne Firestarter (Area: The Bastion of Twilight - Difficulty: 5) (Auras: )
(@CGUID+55, 47161, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -656.227, -664.17, 834.7143, 3.961897, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Brute (Area: The Bastion of Twilight - Difficulty: 5) (Auras: )
(@CGUID+56, 47087, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -660.941, -661.828, 834.7143, 4.13643, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Azureborne Destroyer (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+57, 45687, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -1116.228, -788.7411, 835.0055, 1.793802, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight-Shifter (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+58, 45687, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -1123.416, -797.5894, 835.0095, 4.676396, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight-Shifter (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+59, 47152, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -662.403, -701.109, 834.7143, 2.251475, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+60, 47152, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -666.064, -703.797, 834.7143, 1.553343, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Elementalist (Area: The Bastion of Twilight - Difficulty: 5) (Auras: )
(@CGUID+61, 45700, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -1108.446, -789.4514, 835.0883, 5.934119, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Portal Shaper (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+62, 45699, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -1113.38, -784.057, 835.1293, 3.735005, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Shadow Mender (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 85575 - Shadow Mending)
(@CGUID+63, 45700, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -1108.448, -806.9549, 835.0883, 0.1745329, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Portal Shaper (Area: The Bastion of Twilight - Difficulty: 5) (Auras: )
(@CGUID+64, 45699, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -1114.54, -811.313, 835.1293, 2.460914, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Shadow Mender (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 85575 - Shadow Mending)
(@CGUID+65, 45687, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -1210.611, -791.2717, 835.046, 3.944117, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 27326), -- Twilight-Shifter (Area: The Bastion of Twilight - Difficulty: 5) (Auras: ) (possible waypoints or random movement)
(@CGUID+66, 45687, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -1201.732, -805.6627, 835.0444, 4.658576, 7200, 10, 0, 0, 0, 1, 0, 0, 0, 27326), -- Twilight-Shifter (Area: The Bastion of Twilight - Difficulty: 5) (possible waypoints or random movement)
(@CGUID+67, 45700, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -1215.52, -791.188, 835.1293, 3.438299, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Portal Shaper (Area: The Bastion of Twilight - Difficulty: 5) (Auras: )
(@CGUID+68, 45699, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -1211.81, -813.09, 835.1293, 0.8901179, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Shadow Mender (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 85575 - Shadow Mending)
(@CGUID+69, 45700, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -1216.38, -807.493, 835.1293, 2.722714, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Portal Shaper (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+70, 45699, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -1210.52, -786.564, 835.1293, 5.654867, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Shadow Mender (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 85575 - Shadow Mending)
(@CGUID+71, 45264, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -398.0121, -545.0811, 894.087, 3.124424, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326), -- Twilight Crossfire (Area: The Bastion of Twilight - Difficulty: 5)
(@CGUID+72, 45265, 671, 5334, 5334, "3,5", 169, 0, 0, 0, -399.2076, -539.0597, 894.0872, 3.124425, 7200, 0, 0, 0, 0, 0, 0, 0, 0, 27326); -- Twilight Soul Blade (Area: The Bastion of Twilight - Difficulty: 5) (Auras: 84849 - Soul Blade)

-- Pathing for  Entry: 45265 'TDB FORMAT' 
SET @NPC := @CGUID+72;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '84849');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-424.701,-538.622,894.0889,0,0,0,0,100,0),
(@PATH,2,-449.543,-538.153,894.0859,0,0,0,0,100,0),
(@PATH,3,-424.701,-538.622,894.0889,0,0,0,0,100,0),
(@PATH,4,-403.469,-539.156,894.0871,0,0,0,0,100,0);
-- 0x20307C53E02C344000034900004E80CA .go xyz -424.701 -538.622 894.0889

DELETE FROM `creature_formations` WHERE `leaderGUID`= @CGUID+72;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
-- Front Line
(@CGUID+72, @CGUID+72, 0, 0,   515, 0, 0),
(@CGUID+72, @CGUID+12, 6, 90,  515, 2, 4),
(@CGUID+72, @CGUID+11, 12, 90, 515, 2, 4),
(@CGUID+72, @CGUID+71, 6, 270, 515, 2, 4),
(@CGUID+72, @CGUID+9, 12, 270, 515, 2, 4);

-- Pathing for  Entry: 45265 'TDB FORMAT' 
SET @NPC := @CGUID+8;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '84849');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-423.875,-523.818,894.0902,0,0,0,0,100,0),
(@PATH,2,-401.708,-524.644,894.087,0,0,0,0,100,0),
(@PATH,3,-423.875,-523.818,894.0902,0,0,0,0,100,0),
(@PATH,4,-448.594,-523.03,894.0881,0,0,0,0,100,0);
-- 0x20307C53E02C344000034900044E80CA .go xyz -423.875 -523.818 894.0902

DELETE FROM `creature_formations` WHERE `leaderGUID`= @CGUID+8;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
-- Front Line
(@CGUID+8, @CGUID+8, 0, 0, 515, 0, 0),
(@CGUID+8, @CGUID+1, 6, 90, 515, 2, 4),
(@CGUID+8, @CGUID+4, 12, 90, 515, 2, 4),
(@CGUID+8, @CGUID+2, 6, 270, 515, 2, 4),
(@CGUID+8, @CGUID+0, 12, 270, 515, 2, 4);

-- Pathing for  Entry: 45265 'TDB FORMAT' 
SET @NPC := @CGUID+10;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '84849');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-323.597,-534.234,894.5809,0,0,0,0,100,0),
(@PATH,2,-321.976,-565.561,894.5803,0,0,0,0,100,0),
(@PATH,3,-323.597,-534.234,894.5809,0,0,0,0,100,0),
(@PATH,4,-361.729,-533.083,894.58,0,0,0,0,100,0);
-- 0x20307C53E02C344000034900014E80CA .go xyz -323.597 -534.234 894.5809

DELETE FROM `creature_formations` WHERE `leaderGUID`= @CGUID+10;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+10, @CGUID+10, 0, 0, 515, 0, 0),
(@CGUID+10, @CGUID+13, 6, 270, 515, 2, 4);
