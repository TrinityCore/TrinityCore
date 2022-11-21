SET @CGUID := 1051385;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+21;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 160394, 2175, 10424, 10527, '0', 0, 0, 0, 0, 85.24202728271484375, -2275.666259765625, 60.3869476318359375, 1.411876201629638671, 7200, 4, 0, 124, 0, 1, 0, 0, 0, 45114), -- Barrow Spider (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+1, 160433, 2175, 10424, 10527, '0', 0, 0, 0, 0, 78.1845550537109375, -2186.92724609375, 24.75084877014160156, 5.387650966644287109, 7200, 2, 0, 37, 0, 1, 0, 0, 0, 45114), -- Barrow Spiderling (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+2, 160394, 2175, 10424, 10527, '0', 0, 0, 0, 0, 107.0506134033203125, -2219.107177734375, 31.8289947509765625, 3.13928842544555664, 7200, 4, 0, 124, 0, 1, 0, 0, 0, 45114), -- Barrow Spider (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+3, 160394, 2175, 10424, 10527, '0', 0, 0, 0, 0, 70.72725677490234375, -2275.736083984375, 43.4692230224609375, 1.070562481880187988, 7200, 4, 0, 124, 0, 1, 0, 0, 0, 45114), -- Barrow Spider (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-)
(@CGUID+4, 160433, 2175, 10424, 10527, '0', 0, 0, 0, 0, 118.5678329467773437, -2274.194580078125, 42.686126708984375, 2.738408327102661132, 7200, 2, 0, 37, 0, 1, 0, 0, 0, 45114), -- Barrow Spiderling (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+5, 160394, 2175, 10424, 10527, '0', 0, 0, 0, 0, 99.0129241943359375, -2253.35009765625, 39.6536865234375, 2.930016994476318359, 7200, 4, 0, 124, 0, 1, 0, 0, 0, 45114), -- Barrow Spider (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-)
(@CGUID+6, 160433, 2175, 10424, 10527, '0', 0, 0, 0, 0, 32.54230499267578125, -2230.325927734375, 11.46560192108154296, 3.190922260284423828, 7200, 2, 0, 37, 0, 1, 0, 0, 0, 45114), -- Barrow Spiderling (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+7, 160433, 2175, 10424, 10527, '0', 0, 0, 0, 0, 71.9236297607421875, -2187.74951171875, 24.16413116455078125, 4.715922355651855468, 7200, 2, 0, 37, 0, 1, 0, 0, 0, 45114), -- Barrow Spiderling (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+8, 160433, 2175, 10424, 10527, '0', 0, 0, 0, 0, 119.7234115600585937, -2274.120361328125, 42.29446029663085937, 2.505269289016723632, 7200, 2, 0, 37, 0, 1, 0, 0, 0, 45114), -- Barrow Spiderling (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+9, 160433, 2175, 10424, 10527, '0', 0, 0, 0, 0, 97.93556976318359375, -2277.023193359375, -2.46034550666809082, 0.868991851806640625, 7200, 2, 0, 37, 0, 1, 0, 0, 0, 45114), -- Barrow Spiderling (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+10, 160394, 2175, 10424, 10527, '0', 0, 0, 0, 0, 56.20186233520507812, -2224.949462890625, -18.92352294921875, 0.664193809032440185, 7200, 4, 0, 124, 0, 1, 0, 0, 0, 45114), -- Barrow Spider (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+11, 160433, 2175, 10424, 10527, '0', 0, 0, 0, 0, 107.1527786254882812, -2234.09033203125, -9.71255207061767578, 0.525046288967132568, 7200, 2, 0, 37, 0, 1, 0, 0, 0, 45114), -- Barrow Spiderling (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-)
(@CGUID+12, 160433, 2175, 10424, 10527, '0', 0, 0, 0, 0, 20.85238838195800781, -2228.399169921875, 11.68490886688232421, 5.239824771881103515, 7200, 2, 0, 37, 0, 1, 0, 0, 0, 45114), -- Barrow Spiderling (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+13, 160433, 2175, 10424, 10527, '0', 0, 0, 0, 0, 118.593963623046875, -2254.896728515625, -4.04590606689453125, 2.35221409797668457, 7200, 4, 0, 37, 0, 1, 0, 0, 0, 45114), -- Barrow Spiderling (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+14, 160394, 2175, 10424, 10527, '0', 0, 0, 0, 0, 34.791473388671875, -2262.621826171875, 1.035332322120666503, 3.411931753158569335, 7200, 4, 0, 124, 0, 1, 0, 0, 0, 45114), -- Barrow Spider (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-)
(@CGUID+15, 160394, 2175, 10424, 10527, '0', 0, 0, 0, 0, 38.88898468017578125, -2189.22705078125, 20.4829559326171875, 1.494288206100463867, 7200, 4, 0, 124, 0, 1, 0, 0, 0, 45114), -- Barrow Spider (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+16, 160394, 2175, 10424, 10527, '0', 0, 0, 0, 0, 83.48264312744140625, -2248.259521484375, -16.4877910614013671, 4.009123802185058593, 7200, 4, 0, 124, 0, 1, 0, 0, 0, 45114), -- Barrow Spider (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+17, 160394, 2175, 10424, 10527, '0', 0, 0, 0, 0, 69.45362091064453125, -2272.9072265625, -1.13438236713409423, 5.281130790710449218, 7200, 4, 0, 124, 0, 1, 0, 0, 0, 45114), -- Barrow Spider (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-)
(@CGUID+18, 160433, 2175, 10424, 10527, '0', 0, 0, 0, 0, 111.3011703491210937, -2233.8525390625, -8.82757472991943359, 0.504135966300964355, 7200, 2, 0, 37, 0, 1, 0, 0, 0, 45114), -- Barrow Spiderling (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+19, 160433, 2175, 10424, 10527, '0', 0, 0, 0, 0, 97.45998382568359375, -2275.99462890625, -2.31414794921875, 0.219286605715751647, 7200, 2, 0, 37, 0, 1, 0, 0, 0, 45114), -- Barrow Spiderling (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+20, 160433, 2175, 10424, 10527, '0', 0, 0, 0, 0, 119.559417724609375, -2264.964599609375, -4.58145523071289062, 1.759042859077453613, 7200, 2, 0, 37, 0, 1, 0, 0, 0, 45114), -- Barrow Spiderling (Area: -Unknown- - Difficulty: 0) (Auras: 316915 - -Unknown-) (possible waypoints or random movement)
(@CGUID+21, 156900, 2175, 10424, 10527, '0', 0, 0, 0, 0, 69.98264312744140625, -2122.057373046875, -30.1194019317626953, 5.326576709747314453, 7200, 0, 0, 310, 191, 0, 0, 0, 0, 45114); -- Hrun the Exiled (Area: -Unknown- - Difficulty: 0)

UPDATE `creature` SET `wander_distance`=0 AND `MovementType`=0 WHERE `guid` IN (1051196, 1051194);

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` IN (1051196, 1051194);
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(1051196, 0, 0, 1, 1, 0, 0, 0, 0, 3, ''), -- Hungry Vulture
(1051194, 0, 0, 1, 1, 0, 0, 0, 0, 3, ''); -- Hungry Vulture

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (160433 /*160433 (Barrow Spiderling) - -Unknown-*/, 160394 /*160394 (Barrow Spider) - -Unknown-*/, 156900);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(160433, 0, 0, 0, 1, 0, 0, 0, 0, 0, '316915'), -- 160433 (Barrow Spiderling) - -Unknown-
(160394, 0, 0, 0, 1, 0, 0, 0, 0, 0, '316915'), -- 160394 (Barrow Spider) - -Unknown-
(156900, 0, 0, 0, 1, 468, 0, 0, 0, 0, ''); -- 156900 (Hrun the Exiled)

-- Creature Template
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10, `dynamicflags`=0 WHERE `entry`=160433; -- Barrow Spiderling
UPDATE `creature_template` SET `minlevel`=10, `maxlevel`=10 WHERE `entry`=160394; -- Barrow Spider

-- Scaling
UPDATE `creature_template_scaling` SET `VerifiedBuild`=45114 WHERE (`DifficultyID`=0 AND `Entry` IN (161224,156900,167216,168382,167212,167215,167217,167213,167222,167221,160433,160394));

UPDATE `creature_model_info` SET `VerifiedBuild`=45114 WHERE `DisplayID` IN (75371, 92803, 91670, 64062, 99444, 96320, 96314, 96364, 1072, 96384, 96363, 97258, 96541, 10824, 1157);
UPDATE `creature_model_info` SET `BoundingRadius`=0.928183615207672119, `CombatReach`=0.655102074146270751, `VerifiedBuild`=45114 WHERE `DisplayID`=1088;
UPDATE `creature_model_info` SET `BoundingRadius`=2.125280141830444335, `CombatReach`=1.5, `VerifiedBuild`=45114 WHERE `DisplayID`=283;
