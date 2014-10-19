SET @OGUID = 350;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+15;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 152574, 1, 1, 1, -4446.321, 2055.25, 46.2946, 5.078911, 0, 0, 0, 1, 120, 255, 1), -- The Twin Colossals (Area: -Unknown-)
(@OGUID+1, 152575, 1, 1, 1, -4446.337, 2055.234, 45.57238, 5.078911, 0, 0, 0, 1, 120, 255, 1), -- Desolace (Area: -Unknown-)
(@OGUID+2, 152576, 1, 1, 1, -4446.405, 2055.313, 46.27639, 0.4014249, 0, 0, 0, 1, 120, 255, 1), -- Feathermoon Stronghold (Area: -Unknown-)
(@OGUID+3, 152577, 1, 1, 1, -4446.406, 2055.24, 46.28632, 1.97222, 0, 0, 0, 1, 120, 255, 1), -- High Wilderness (Area: -Unknown-)
(@OGUID+4, 152578, 1, 1, 1, -4446.406, 2055.24, 45.61965, 1.97222, 0, 0, 0, 1, 120, 255, 1), -- Lower Wilds (Area: -Unknown-)
(@OGUID+5, 152579, 1, 1, 1, -4446.382, 2055.252, 44.95401, 1.97222, 0, 0, 0, 1, 120, 255, 1), -- Thousand Needles (Area: -Unknown-)
(@OGUID+6, 152580, 1, 1, 1, -4445.276, 2058.181, 44.99755, 5.515241, 0, 0, 0, 1, 120, 255, 1), -- Ravenwind (Area: -Unknown-)
(@OGUID+7, 152581, 1, 1, 1, -2481.316, 2319.047, 117.022, 3.141593, 0, 0, 0, 1, 120, 255, 1), -- Feathermoon Stronghold (Area: -Unknown-)
(@OGUID+8, 152582, 1, 1, 1, -2481.335, 2319.078, 117.0233, 4.834563, 0, 0, 0, 1, 120, 255, 1), -- Desolace (Area: -Unknown-)
(@OGUID+9, 152584, 1, 1, 1, -4394.5, 193.806, 27.9585, 4.502952, 0, 0, 0, 1, 120, 255, 1), -- High Wilderness (Area: -Unknown-)
(@OGUID+10, 152585, 1, 1, 1, -4394.48, 193.833, 27.1208, 4.537859, 0, 0, 0, 1, 120, 255, 1), -- The Twin Colossals (Area: -Unknown-)
(@OGUID+11, 152586, 1, 1, 1, -4394.51, 193.682, 26.249, 4.546584, 0, 0, 0, 1, 120, 255, 1), -- Desolace (Area: -Unknown-)
(@OGUID+12, 152587, 1, 1, 1, -4394.08, 191.271, 27.9996, 1.911136, 0, 0, 0, 1, 120, 255, 1), -- Thousand Needles (Area: -Unknown-)
(@OGUID+13, 202213, 1, 1, 1, -3045.392, 2214.656, 41.99305, 2.731435, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+14, 207948, 1, 1, 1, -2766.859, 2626.18, 68.35954, 2.286379, 0, 0, 0, 1, 120, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+15, 207949, 1, 1, 1, -2755.554, 2611.556, 65.74285, 5.122542, 0, 0, 0, 1, 120, 255, 1); -- -Unknown- (Area: -Unknown-)
