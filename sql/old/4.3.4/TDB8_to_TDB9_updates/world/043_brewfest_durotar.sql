UPDATE `creature_template` SET `speed_run`=0.8571429, `RangeAttackTime`=2000 WHERE `entry`=23487; -- Wild Wolpertinger

SET @CGUID := 361975;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+17;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 23487, 1, 1, 1, 0, 1212.667, -4187.151, 24.87226, 6.039544, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+1, 23487, 1, 1, 1, 0, 1117.449, -4122.83, 19.00484, 3.117203, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+2, 23487, 1, 1, 1, 0, 1153.845, -4174.462, 21.30283, 5.984973, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+3, 23487, 1, 1, 1, 0, 1218.27, -4216.097, 25.45043, 1.632762, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+4, 23487, 1, 1, 1, 0, 1188.064, -4216.208, 22.55934, 6.068075, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+5, 23487, 1, 1, 1, 0, 1177.832, -4244.035, 23.4973, 1.253698, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+6, 23487, 1, 1, 1, 0, 1246.517, -4212.86, 24.87316, 1.675304, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+7, 23487, 1, 1, 1, 0, 1144.646, -4275.15, 22.34255, 0.347768, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+8, 23487, 1, 1, 1, 0, 1185.133, -4278.976, 21.27065, 4.749744, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+9, 23487, 1, 1, 1, 0, 1278.271, -4229.201, 26.52122, 1.635286, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+10, 23487, 1, 1, 1, 0, 1208.683, -4299.609, 21.31664, 3.853282, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+11, 23487, 1, 1, 1, 0, 1212.091, -4294.003, 21.31664, 4.99473, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+12, 23487, 1, 1, 1, 0, 1185.491, -4327.13, 21.31347, 3.877954, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+13, 23487, 1, 1, 1, 0, 1156.816, -4321.151, 21.95646, 2.575829, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+14, 23487, 1, 1, 1, 0, 1208.821, -4339.256, 21.31665, 1.149127, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+15, 23487, 1, 1, 1, 0, 1154.214, -4344.812, 26.07152, 4.258274, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+16, 23487, 1, 1, 1, 0, 1149.479, -4384.896, 25.87045, 4.254403, 120, 0, 0), -- Wild Wolpertinger (Area: Durotar) (Auras: )
(@CGUID+17, 23487, 1, 1, 1, 0, 1319.168, -4238.876, 30.29514, 0.8725554, 120, 0, 0); -- Wild Wolpertinger (Area: Durotar) (Auras: )
