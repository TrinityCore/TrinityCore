SET @CGUID = 5000000;
SET @OGUID = 5000000;

DELETE FROM `areatrigger_template` WHERE `Id`=19612;
INSERT INTO `areatrigger_template` (`Id`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `VerifiedBuild`) VALUES
(19612, 0, 0, 8, 8, 0, 0, 0, 0, 28153);


DELETE FROM `spell_areatrigger` WHERE (`SpellMiscId`=14955 AND `AreaTriggerId`=19612);
INSERT INTO `spell_areatrigger` (`SpellMiscId`, `AreaTriggerId`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `TimeToTarget`, `TimeToTargetScale`, `VerifiedBuild`) VALUES
(14955, 19612, 0, 0, 0, 0, 0, 0, 0, 0, 8000, 28153); -- SpellId : 281516


DELETE FROM `gameobject_template_addon` WHERE `entry` IN (277620 /*AQROOT*/, 277611 /*AQRUNE*/, 268414 /*Alliance Banner*/, 267179 /*Alliance Banner*/, 280948 /*Twilight Outhouse*/, 281078 /*Pipe*/, 281071 /*Goblin Battery*/, 281073 /*Smoke Stack*/, 281420 /*Campfire*/, 281072 /*Oil Pump*/, 280720 /*Horde Crate*/, 281076 /*Pipe*/, 281077 /*Pipe*/, 281074 /*Fuel Can*/, 281075 /*Oil Drum*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`) VALUES
(277620, 114, 32), -- AQROOT
(277611, 114, 32), -- AQRUNE
(268414, 0, 8192), -- Alliance Banner
(267179, 0, 8192), -- Alliance Banner
(280948, 0, 36), -- Twilight Outhouse
(281078, 0, 32), -- Pipe
(281071, 0, 32), -- Goblin Battery
(281073, 0, 32), -- Smoke Stack
(281420, 35, 0), -- Campfire
(281072, 0, 32), -- Oil Pump
(280720, 0, 8192), -- Horde Crate
(281076, 0, 32), -- Pipe
(281077, 0, 32), -- Pipe
(281074, 0, 32), -- Fuel Can
(281075, 0, 32); -- Oil Drum

UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=180718; -- The Scarab Gong

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+524;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 137905, 1, 0, 0, '0', '0', 0, 0, 0, -7075.868, 1189.227, -113.345, 2.036627, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: -Unknown- - Difficulty: Normal) (Auras: 271753 - Azerite Explosion) (possible waypoints or random movement)
(@CGUID+1, 132526, 1, 0, 0, '0', '0', 0, 0, 0, -6911.79, 1366.756, -21.81257, 2.004591, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: -Unknown- - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+2, 137905, 1, 0, 0, '0', '0', 0, 0, 0, -6986.143, 1257.006, -111.4485, 3.740965, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: -Unknown- - Difficulty: Normal) (Auras: 271753 - Azerite Explosion)
(@CGUID+3, 137905, 1, 0, 0, '0', '0', 0, 0, 0, -6985.625, 1218.33, -123.7488, 4.698565, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: -Unknown- - Difficulty: Normal) (Auras: 271753 - Azerite Explosion)
(@CGUID+4, 137905, 1, 0, 0, '0', '0', 0, 0, 0, -7117.114, 1183.907, -118.4647, 0.4540367, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: -Unknown- - Difficulty: Normal) (Auras: 271753 - Azerite Explosion) (possible waypoints or random movement)
(@CGUID+5, 131897, 1, 0, 0, '0', '0', 0, 0, 0, -6887.681, 1254.29, -86.86057, 4.702624, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Stonelash Pincer (Area: -Unknown- - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+6, 132526, 1, 0, 0, '0', '0', 0, 0, 0, -7151.075, 1450.525, 26.1303, 4.433132, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: -Unknown- - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+7, 137905, 1, 0, 0, '0', '0', 0, 0, 0, -7120.086, 1354.572, -81.56769, 4.610681, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: -Unknown- - Difficulty: Normal) (Auras: 271753 - Azerite Explosion)
(@CGUID+8, 137905, 1, 0, 0, '0', '0', 0, 0, 0, -7155.74, 1258.95, -104.8171, 5.052982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: -Unknown- - Difficulty: Normal) (Auras: 271753 - Azerite Explosion)
(@CGUID+9, 137905, 1, 0, 0, '0', '0', 0, 0, 0, -7149.92, 1222.75, -113.3659, 4.790584, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: -Unknown- - Difficulty: Normal) (Auras: 271753 - Azerite Explosion)
(@CGUID+10, 137905, 1, 0, 0, '0', '0', 0, 0, 0, -7198.366, 1258.521, -119.8641, 3.047751, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: -Unknown- - Difficulty: Normal) (Auras: 271753 - Azerite Explosion)
(@CGUID+11, 137905, 1, 0, 0, '0', '0', 0, 0, 0, -7170.752, 1214.661, -118.7117, 0.4557909, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: -Unknown- - Difficulty: Normal) (Auras: 271753 - Azerite Explosion)
(@CGUID+12, 137904, 1, 0, 0, '0', '0', 0, 0, 0, -7278.937, 1177.674, -127.1644, 2.816444, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: -Unknown- - Difficulty: Normal)
(@CGUID+13, 137905, 1, 0, 0, '0', '0', 0, 0, 0, -7276.959, 1215.654, -111.571, 0.07827114, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: -Unknown- - Difficulty: Normal)
(@CGUID+14, 137907, 1, 0, 0, '0', '0', 0, 0, 0, -7364.535, 1007.446, -143.5228, 6.088018, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Infused Crag (Area: -Unknown- - Difficulty: Normal)
(@CGUID+15, 137906, 1, 0, 0, '0', '0', 0, 0, 0, -7283.613, 967.2552, -168.7877, 5.273163, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Infused Bedrock (Area: -Unknown- - Difficulty: Normal) (Auras: 270813 - Azerite Empowered)
(@CGUID+16, 137904, 1, 0, 0, '0', '0', 0, 0, 0, -7279.041, 1180.973, -126.1374, 0.2383531, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: -Unknown- - Difficulty: Normal)
(@CGUID+17, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7343.813, 1128.888, -139.0064, 3.520468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+18, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7343.719, 1138.073, -135.2426, 1.625536, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+19, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7331.508, 1186.257, -116.3883, 3.784313, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+20, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7338.753, 1218.461, -101.9791, 3.708863, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+21, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7345.806, 1218.662, -101.036, 0.4566479, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+22, 137906, 1, 9310, 0, '0', '0', 0, 0, 0, -7312.509, 945.2952, -160.0768, 5.497658, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Infused Bedrock (Area: 0 - Difficulty: Normal) (Auras: 270813 - Azerite Empowered)
(@CGUID+23, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7341.039, 1217.675, -101.913, 0.9009342, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+24, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7374.443, 1173.855, -115.8987, 5.678382, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+25, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7389.586, 1062.489, -133.3778, 3.582527, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+26, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7483.871, 1057.718, -87.51243, 0.7066713, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+27, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7345.901, 994.0642, -167.3793, 4.804286, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+28, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7455.472, 960.2991, -102.054, 5.69082, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+29, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7415.205, 1022.432, -121.4684, 5.063498, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+30, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7332.297, 969.7198, -174.029, 3.462417, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+31, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7362.101, 969.4514, -159.159, 2.442604, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+32, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7393.985, 991.1776, -132.0743, 5.923728, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+33, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7402.096, 942.0758, -142.8378, 5.555164, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+34, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7426.446, 945.2433, -116.4104, 0.7259938, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+35, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7419.806, 970.1365, -119.556, 5.839649, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+36, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7359.876, 968.1094, -160.2752, 2.269037, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+37, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7412.146, 975.0823, -123.1413, 4.712389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+38, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7426.829, 901.7607, -117.2419, 3.628848, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+39, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7417.197, 906.25, -121.7597, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+40, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7383.706, 865.4929, -134.874, 3.345448, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+41, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7349.722, 898.0796, -147.3465, 1.807252, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+42, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7431.672, 859.2739, -128.483, 5.776711, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+43, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7441.448, 857.1709, -125.1134, 1.370143, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+44, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7438.073, 855.0789, -125.9181, 5.609207, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+45, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -7591.17, 852.8671, -5.586007, 0.3065051, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+46, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7376.415, 872.2011, -137.562, 3.518653, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+47, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7451.099, 808.4943, -118.3836, 2.284297, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+48, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7467.892, 831.8247, -115.4584, 2.933091, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+49, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7430.268, 820.7064, -126.23, 1.04947, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+50, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7452.002, 806.162, -117.8074, 3.862075, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+51, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7447.498, 805.5692, -119.3284, 2.294267, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+52, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7461.135, 797.0302, -114.4145, 5.440219, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+53, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -7502.285, 814.9271, -102.9405, 3.186572, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+54, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7466.526, 746.2937, -135.978, 6.258776, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+55, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -7498.083, 756.7429, -122.5404, 1.451406, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+56, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7498.299, 719.9849, -121.0497, 3.954608, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+57, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7508.551, 730.8411, -116.9114, 1.508256, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+58, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7503.061, 725.0484, -119.3789, 0.5107948, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+59, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7496.804, 716.7515, -121.1627, 3.1006, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+60, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -7509.185, 716.2104, -116.104, 2.844528, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+61, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -7369.221, 584.662, -96.20671, 3.69026, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+62, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -7570.479, 715.3965, -86.7227, 0.3226762, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+63, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -7554.719, 537.887, -85.81622, 0.3594568, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+64, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7364.754, 509.371, -64.56779, 0.9375164, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+65, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -7408.303, 495.3941, -67.12229, 5.674059, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+66, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7481.272, 485.0914, -61.72497, 5.590448, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+67, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7296.183, 569.8426, -75.05768, 1.038611, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+68, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -7429.495, 463.0638, -8.761136, 0.2602409, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+69, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -7298.647, 551.9708, -28.60918, 0.4530139, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+70, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -7544.493, 451.83, -41.55721, 2.809342, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+71, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -7381.945, 541.8951, -80.24465, 5.631757, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+72, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7530.607, 409.604, -26.53341, 6.161376, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+73, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -7508.582, 464.98, -50.69681, 4.53789, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+74, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -7269.337, 484.5298, -49.37672, 2.574714, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+75, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7599.654, 349.8737, -28.16335, 3.53898, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+76, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -7483.515, 321.5482, -4.471429, 2.462043, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+77, 132064, 1, 9310, 0, '0', '0', 0, 0, 0, -7437.637, 334.2517, -2.684457, 2.947378, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Horde Grunt (Area: 0 - Difficulty: Normal) (Auras: )
(@CGUID+78, 131896, 1, 9310, 9474, '0', '0', 0, 0, 0, -7416.446, 321.4701, -2.932932, 4.747806, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: Southwind Village - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+79, 132526, 1, 9310, 9474, '0', '0', 0, 0, 0, -7639.831, 335.9958, -9.566914, 6.127581, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: Southwind Village - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+80, 132064, 1, 9310, 9474, '0', '0', 0, 0, 0, -7360.389, 356.6076, -3.643618, 0.5328879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Horde Grunt (Area: Southwind Village - Difficulty: Normal) (Auras: )
(@CGUID+81, 132064, 1, 9310, 9474, '0', '0', 0, 0, 0, -7444.458, 314.1059, -2.945526, 2.542165, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Horde Grunt (Area: Southwind Village - Difficulty: Normal) (Auras: )
(@CGUID+82, 131896, 1, 9310, 9474, '0', '0', 0, 0, 0, -7384.194, 311.744, -3.057875, 3.638588, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: Southwind Village - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+83, 132138, 1, 9310, 9474, '0', '0', 0, 0, 0, -7431.075, 292.3125, -2.975043, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Gaula Axefury (Area: Southwind Village - Difficulty: Normal)
(@CGUID+84, 132141, 1, 9310, 9474, '0', '0', 0, 0, 0, -7433.681, 304.5191, -2.974672, 3.595099, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Worker (Area: Southwind Village - Difficulty: Normal)
(@CGUID+85, 132141, 1, 9310, 9474, '0', '0', 0, 0, 0, -7371.266, 289.9618, -2.766698, 5.100441, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Worker (Area: Southwind Village - Difficulty: Normal)
(@CGUID+86, 132040, 1, 9310, 9474, '0', '0', 0, 0, 0, -7403.108, 269.7118, -0.9695809, 1.117256, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Pixni Rustbomb (Area: Southwind Village - Difficulty: Normal)
(@CGUID+87, 132142, 1, 9310, 9474, '0', '0', 0, 0, 0, -7408.016, 261.9774, -0.9894266, 2.388845, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Mechanic (Area: Southwind Village - Difficulty: Normal)
(@CGUID+88, 132045, 1, 9310, 9474, '0', '0', 0, 0, 0, -7380.056, 295.2691, -3.283098, 1.952276, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Gizmax Greasebolt (Area: Southwind Village - Difficulty: Normal)
(@CGUID+89, 132141, 1, 9310, 9474, '0', '0', 0, 0, 0, -7389.647, 276.8125, -1.004041, 5.589616, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Worker (Area: Southwind Village - Difficulty: Normal)
(@CGUID+90, 132142, 1, 9310, 9474, '0', '0', 0, 0, 0, -7415.17, 255.2813, -1.076886, 4.477619, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Mechanic (Area: Southwind Village - Difficulty: Normal)
(@CGUID+91, 132141, 1, 9310, 9474, '0', '0', 0, 0, 0, -7419.288, 274.25, -2.975044, 5.589616, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Worker (Area: Southwind Village - Difficulty: Normal)
(@CGUID+92, 132064, 1, 9310, 9474, '0', '0', 0, 0, 0, -7418.868, 280.6649, -2.975044, 0.9407478, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Horde Grunt (Area: Southwind Village - Difficulty: Normal) (Auras: )
(@CGUID+93, 131904, 1, 9310, 9474, '0', '0', 0, 0, 0, -7352.794, 349.2037, -3.515232, 3.43528, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Spiky Lizard (Area: Southwind Village - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+94, 132141, 1, 9310, 9474, '0', '0', 0, 0, 0, -7377.747, 259.401, -1.125537, 3.248656, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Worker (Area: Southwind Village - Difficulty: Normal)
(@CGUID+95, 132141, 1, 9310, 9474, '0', '0', 0, 0, 0, -7379.906, 266.3924, -1.008891, 4.090143, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Worker (Area: Southwind Village - Difficulty: Normal)
(@CGUID+96, 132141, 1, 9310, 9474, '0', '0', 0, 0, 0, -7364.019, 297.783, -2.766698, 6.077197, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Worker (Area: Southwind Village - Difficulty: Normal)
(@CGUID+97, 132141, 1, 9310, 9474, '0', '0', 0, 0, 0, -7354.393, 301.1927, -2.116301, 3.894418, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Worker (Area: Southwind Village - Difficulty: Normal)
(@CGUID+98, 132142, 1, 9310, 9474, '0', '0', 0, 0, 0, -7405.538, 251.3333, -0.998072, 4.271355, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Mechanic (Area: Southwind Village - Difficulty: Normal)
(@CGUID+99, 132139, 1, 9310, 9474, '0', '0', 0, 0, 0, -7367.149, 288.1771, -2.850032, 4.9461, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Hagras Wartaker (Area: Southwind Village - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+100, 132141, 1, 9310, 9474, '0', '0', 0, 0, 0, -7398.971, 243.5069, -1.086954, 3.834605, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Bilgewater Worker (Area: Southwind Village - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+101, 132147, 1, 9310, 9474, '0', '0', 0, 0, 0, -7353.71, 307.8472, -2.106222, 2.110142, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Grol Warblade (Area: Southwind Village - Difficulty: Normal)
(@CGUID+102, 132064, 1, 9310, 9474, '0', '0', 0, 0, 0, -7341.731, 348.1476, -1.876928, 0.8986368, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Horde Grunt (Area: Southwind Village - Difficulty: Normal) (Auras: )
(@CGUID+103, 132064, 1, 9310, 9474, '0', '0', 0, 0, 0, -7261.962, 308.8004, 26.73944, 1.38493, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Horde Grunt (Area: Southwind Village - Difficulty: Normal) (Auras: )
(@CGUID+104, 132064, 1, 9310, 9474, '0', '0', 0, 0, 0, -7267.582, 322.2379, 23.21716, 1.26267, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Horde Grunt (Area: Southwind Village - Difficulty: Normal) (Auras: )
(@CGUID+105, 131897, 1, 9310, 9474, '0', '0', 0, 0, 0, -7231.998, 484.0009, -45.57016, 3.878533, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: Southwind Village - Difficulty: Normal)
(@CGUID+106, 132140, 1, 9310, 9474, '0', '0', 0, 0, 0, -7249.319, 330.3802, 23.2705, 3.035537, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Urok Windcleaver (Area: Southwind Village - Difficulty: Normal)
(@CGUID+107, 132064, 1, 9310, 9474, '0', '0', 0, 0, 0, -7253.283, 321.0087, 23.26065, 1.461946, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Horde Grunt (Area: Southwind Village - Difficulty: Normal) (Auras: )
(@CGUID+108, 131896, 1, 9310, 9474, '0', '0', 0, 0, 0, -7208.937, 479.8296, -42.79738, 3.547947, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: Southwind Village - Difficulty: Normal)
(@CGUID+109, 131890, 1, 9310, 9474, '0', '0', 0, 0, 0, -7176.93, 561.0499, -74.48562, 3.662919, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: Southwind Village - Difficulty: Normal)
(@CGUID+110, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -7057.346, 395.2483, 4.231034, 3.270976, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+111, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7141.686, 577.1927, -81.92771, 6.036567, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+112, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -7128.503, 474.245, -31.95248, 3.301705, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+113, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -7018.599, 343.5596, -18.16517, 4.889098, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+114, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -7098.176, 420.4111, -17.67989, 1.074896, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+115, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6986.6, 303.2207, -15.70856, 0.8517825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+116, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6984.051, 355.3446, -25.87151, 2.470964, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+117, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -7032.969, 218.12, 5.155095, 4.675297, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+118, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6953.229, 292.5368, -18.92648, 4.661552, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+119, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -7032.445, 419.9859, -33.32022, 0.2787237, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+120, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -6904.551, 329.8818, 8.360155, 0.06553617, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+121, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6982.388, 198.6986, -8.238968, 6.092052, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+122, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6891.637, 309.457, -36.51756, 2.436355, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+123, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6941.691, 233.5606, -9.89402, 1.938255, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+124, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6985.549, 323.0742, -19.63886, 0.607231, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+125, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -6916.414, 354.6563, -39.5449, 1.143583, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+126, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6863.56, 204.6036, -26.11861, 0.8392879, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+127, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6908.753, 144.0439, -6.478353, 1.670659, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+128, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6917.293, 212.6961, -12.28877, 4.896499, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+129, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -6843.001, 116.0712, 17.80361, 3.41122, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+130, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6833.804, 87.04735, -9.327794, 4.687004, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+131, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6751.461, 204.4853, -23.52596, 1.753622, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+132, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -6879.369, 152.8438, -13.92726, 2.569674, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+133, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6847.278, 12.39039, 5.225222, 4.908217, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+134, 131906, 1, 9310, 0, '0', '0', 0, 0, 0, -6983.064, 115.6245, 5.540802, 2.034444, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: 0 - Difficulty: Normal)
(@CGUID+135, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6996.974, 133.9442, 6.231366, 3.37673, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+136, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6941.822, 98.86965, 4.630747, 0.5601813, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+137, 131906, 1, 9310, 0, '0', '0', 0, 0, 0, -6906.034, 58.74223, 4.358404, 6.237386, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: 0 - Difficulty: Normal)
(@CGUID+138, 131906, 1, 9310, 0, '0', '0', 0, 0, 0, -6934.544, 75.65382, 4.764661, 1.561827, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: 0 - Difficulty: Normal)
(@CGUID+139, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6799.241, -29.48829, 9.93949, 2.876737, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+140, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6871.893, 40.36719, 1.371446, 6.004886, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+141, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6700.938, 124.7509, -6.395807, 3.024833, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+142, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6757.889, -0.4573016, -6.082384, 3.170881, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+143, 131906, 1, 9310, 0, '0', '0', 0, 0, 0, -6891.059, -5.358173, 4.361999, 3.529155, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: 0 - Difficulty: Normal)
(@CGUID+144, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6832.825, -33.47071, 14.72287, 3.596802, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+145, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6876.86, -34.93257, 4.475925, 1.74941, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+146, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6703.301, -49.05051, -3.590695, 5.813687, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+147, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6699.017, -103.7852, 13.13375, 1.22436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+148, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6649.935, 20.65391, 0.2275286, 2.147417, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+149, 131906, 1, 9310, 0, '0', '0', 0, 0, 0, -6827.769, -63.93301, 4.471502, 1.57607, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: 0 - Difficulty: Normal)
(@CGUID+150, 131906, 1, 9310, 0, '0', '0', 0, 0, 0, -6802.227, -64.13057, 4.467385, 1.89284, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: 0 - Difficulty: Normal)
(@CGUID+151, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -6736.872, -29.07979, -2.541597, 2.252095, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+152, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6777.443, -60.18359, 4.412501, 5.04276, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+153, 131906, 1, 9310, 0, '0', '0', 0, 0, 0, -6752.404, -61.46812, 4.530621, 2.519169, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: 0 - Difficulty: Normal)
(@CGUID+154, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6682.46, 67.76318, -5.756326, 1.69594, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+155, 131906, 1, 9310, 0, '0', '0', 0, 0, 0, -6590.751, -68.55331, -2.373489, 1.013849, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: 0 - Difficulty: Normal)
(@CGUID+156, 131906, 1, 9310, 0, '0', '0', 0, 0, 0, -6673.606, -138.639, 5.840014, 0.3353683, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: 0 - Difficulty: Normal)
(@CGUID+157, 131906, 1, 9310, 0, '0', '0', 0, 0, 0, -6637.975, -132.1068, 3.000364, 0.2165503, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: 0 - Difficulty: Normal)
(@CGUID+158, 128607, 1, 9310, 0, '0', '0', 0, 0, 0, -6467.526, -219.9097, 5.90872, 2.209932, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Zidormi (Area: 0 - Difficulty: Normal) (Auras: 132482 - Aura Tall - Yellow)
(@CGUID+159, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6372.479, 157.2969, 7.993381, 5.797306, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+160, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6358.51, 154.3594, 7.244524, 4.640099, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+161, 131952, 1, 9310, 9473, '0', '0', 0, 0, 0, -6373.019, 159.0504, 7.910769, 6.025314, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Edmund Hackney (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+162, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6363.597, 153.1667, 7.24241, 4.640099, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+163, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6402.231, 170.2118, 7.710173, 5.346641, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+164, 132606, 1, 9310, 9473, '0', '0', 0, 0, 0, -6387.191, 166, 7.191402, 1.45722, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Tammy Tinkspinner (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+165, 132192, 1, 9310, 9473, '0', '0', 0, 0, 0, -6393.783, 165.2986, 7.225242, 1.186363, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Khargus Stonemantle (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+166, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6413.375, 170.8733, 8.614973, 4.640099, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+167, 131946, 1, 9310, 9473, '0', '0', 0, 0, 0, -6375.734, 190.8941, 7.187927, 3.955294, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Guard (Area: Staghelm Point - Difficulty: Normal) (Auras: )
(@CGUID+168, 131897, 1, 9310, 9473, '0', '0', 0, 0, 0, -6392.086, 272.3722, 14.07553, 2.821695, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+169, 131963, 1, 9310, 9473, '0', '0', 0, 0, 0, -6350.344, 166.2118, 7.436775, 2.827001, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Nolan Speed (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+170, 131946, 1, 9310, 9473, '0', '0', 0, 0, 0, -6367.849, 180.3802, 7.04162, 3.812891, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Guard (Area: Staghelm Point - Difficulty: Normal) (Auras: )
(@CGUID+171, 131946, 1, 9310, 9473, '0', '0', 0, 0, 0, -6355.155, 190.0972, 8.428913, 3.681581, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Guard (Area: Staghelm Point - Difficulty: Normal) (Auras: )
(@CGUID+172, 132995, 1, 9310, 9473, '0', '0', 0, 0, 0, -6421.249, 176.5747, 10.65917, 1.492454, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Laurette Royston (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+173, 130030, 1, 9310, 9473, '0', '0', 0, 0, 0, -6349.722, 168.3941, 7.461002, 3.415187, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Kelsey Steelspark (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+174, 131947, 1, 9310, 9473, '0', '0', 0, 0, 0, -6363.427, 191.9566, 8.457399, 3.836665, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Clifford Bentham (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+175, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6362.804, 208.974, 6.860863, 5.346641, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+176, 131946, 1, 9310, 9473, '0', '0', 0, 0, 0, -6391.955, 210.4097, 6.993229, 1.519549, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Guard (Area: Staghelm Point - Difficulty: Normal) (Auras: )
(@CGUID+177, 131897, 1, 9310, 9473, '0', '0', 0, 0, 0, -6320.694, 301.9164, 15.42194, 0.1728606, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+178, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6352.135, 205.8542, 8.405431, 0.6743329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+179, 131904, 1, 9310, 9473, '0', '0', 0, 0, 0, -6412.288, 192.163, 8.044199, 3.027203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+180, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6375.547, 199.1615, 7.031729, 5.733685, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+181, 131946, 1, 9310, 9473, '0', '0', 0, 0, 0, -6409.596, 210.4583, 7.616734, 1.643263, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Guard (Area: Staghelm Point - Difficulty: Normal) (Auras: )
(@CGUID+182, 131946, 1, 9310, 9473, '0', '0', 0, 0, 0, -6353.59, 201.3576, 8.465784, 0.8306133, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Guard (Area: Staghelm Point - Difficulty: Normal) (Auras: )
(@CGUID+183, 131897, 1, 9310, 9473, '0', '0', 0, 0, 0, -6379.911, 342.9928, 7.258012, 0.5353911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+184, 131946, 1, 9310, 9473, '0', '0', 0, 0, 0, -6431.587, 231.5608, 8.743492, 4.616896, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Guard (Area: Staghelm Point - Difficulty: Normal) (Auras: )
(@CGUID+185, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6429.146, 240.0781, 8.927922, 1.21527, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+186, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6429.038, 237.9236, 8.757113, 0.5084071, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+187, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6433.771, 233.8715, 8.946104, 0.5814, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+188, 133755, 1, 9310, 9473, '0', '0', 0, 0, 0, -6360.462, 168.533, 7.295906, 2.662037, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Guard (Area: Staghelm Point - Difficulty: Normal) (Auras: )
(@CGUID+189, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6428.719, 254.342, 9.064209, 3.440813, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+190, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6447.828, 236.217, 11.27814, 1.773962, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+191, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6429.071, 248.6736, 9.18414, 6.125846, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+192, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6437.191, 239.6684, 10.4653, 4.555366, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+193, 133755, 1, 9310, 9473, '0', '0', 0, 0, 0, -6367.504, 187.338, 8.492949, 4.108608, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Guard (Area: Staghelm Point - Difficulty: Normal) (Auras: )
(@CGUID+194, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6445.096, 243.0885, 10.56838, 1.712131, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+195, 131946, 1, 9310, 9473, '0', '0', 0, 0, 0, -6453.962, 233.3646, 9.423562, 4.775047, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Guard (Area: Staghelm Point - Difficulty: Normal) (Auras: )
(@CGUID+196, 132190, 1, 9310, 9473, '0', '0', 0, 0, 0, -6443.245, 259.25, 10.55568, 2.312069, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Worker (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+197, 131946, 1, 9310, 9473, '0', '0', 0, 0, 0, -6493.035, 226.9688, 9.420428, 2.899656, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Guard (Area: Staghelm Point - Difficulty: Normal) (Auras: )
(@CGUID+198, 131904, 1, 9310, 9473, '0', '0', 0, 0, 0, -6479.079, 225.2588, 10.57777, 5.902308, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+199, 131946, 1, 9310, 9473, '0', '0', 0, 0, 0, -6496.188, 219.1806, 9.826569, 2.981967, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Guard (Area: Staghelm Point - Difficulty: Normal) (Auras: )
(@CGUID+200, 132526, 1, 9310, 9473, '0', '0', 0, 0, 0, -6566.226, 363.4933, 16.35878, 0.08587734, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+201, 131897, 1, 9310, 9473, '0', '0', 0, 0, 0, -6491.933, 386.4084, -1.536403, 0.9047727, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+202, 131904, 1, 9310, 9473, '0', '0', 0, 0, 0, -6434.024, 291.5147, 12.57252, 3.111562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+203, 131896, 1, 9310, 9473, '0', '0', 0, 0, 0, -6552.637, 247.4682, 5.718244, 4.045044, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+204, 131890, 1, 9310, 9473, '0', '0', 0, 0, 0, -6614.33, 370.1439, -4.304201, 4.651798, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+205, 131904, 1, 9310, 9473, '0', '0', 0, 0, 0, -6466.564, 333.2337, 0.8386922, 6.098572, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: Staghelm Point - Difficulty: Normal)
(@CGUID+206, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6409.11, 498.3923, 7.114638, 0.1043378, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+207, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6451.429, 403.1492, 5.281747, 5.052217, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+208, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6552.49, 521.0195, -19.01095, 2.507436, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+209, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6491.057, 485.3965, 0.4074943, 4.689749, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+210, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6454.785, 602.9798, -15.25036, 2.556297, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+211, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -6382.736, 426.3484, 7.757999, 4.77937, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+212, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6342.964, 544.8914, 3.549949, 1.629437, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+213, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6488.82, 615.7874, -22.81071, 5.160652, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+214, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6366.817, 495.7311, 13.31735, 1.827659, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+215, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -6475.037, 656.7646, -14.01999, 2.092822, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+216, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6381.325, 686.4772, 3.232842, 4.859396, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+217, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6418.158, 684.613, -8.948092, 5.39963, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+218, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6605.113, 602.4337, -45.12741, 3.263039, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+219, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6457.165, 766.8447, -14.37818, 2.165306, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+220, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6627.581, 727.9596, -71.08446, 5.506771, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+221, 132062, 1, 9310, 0, '0', '0', 0, 0, 0, -6617.479, 691.3837, -53.96692, 6.051624, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Laborer (Area: 0 - Difficulty: Normal)
(@CGUID+222, 132062, 1, 9310, 0, '0', '0', 0, 0, 0, -6615.439, 690.5816, -53.97232, 2.616395, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Laborer (Area: 0 - Difficulty: Normal)
(@CGUID+223, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6608.208, 676.8663, -54.48503, 1.515259, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+224, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6595.132, 670.125, -54.07973, 3.035326, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+225, 133022, 1, 9310, 0, '0', '0', 0, 0, 0, -6606.731, 677.2327, -54.48504, 3.726905, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Inactive Shredder (Area: 0 - Difficulty: Normal)
(@CGUID+226, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6698.515, 635.1381, -64.17794, 1.108846, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+227, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6698.188, 768.4385, -84.22971, 3.781693, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+228, 132062, 1, 9310, 0, '0', '0', 0, 0, 0, -6635.997, 646.2396, -54.3941, 3.046413, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Laborer (Area: 0 - Difficulty: Normal)
(@CGUID+229, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6512.967, 768.1334, -37.06083, 4.234544, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+230, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -6672.832, 834.1697, -53.81641, 5.475079, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+231, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -6549.557, 787.5371, -54.67896, 2.770907, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+232, 132042, 1, 9310, 0, '0', '0', 0, 0, 0, -6638.17, 646.5104, -54.4121, 5.744195, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Mook (Area: 0 - Difficulty: Normal)
(@CGUID+233, 132062, 1, 9310, 0, '0', '0', 0, 0, 0, -6636.672, 644.8264, -54.40625, 2.63079, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Laborer (Area: 0 - Difficulty: Normal)
(@CGUID+234, 131957, 1, 9310, 0, '0', '0', 0, 0, 0, -6598.672, 678.7969, -54.68985, 0.1357861, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- SI:7 Operative (Area: 0 - Difficulty: Normal) (Auras: 262360 - Stealth)
(@CGUID+235, 131957, 1, 9310, 0, '0', '0', 0, 0, 0, -6607.393, 694.8403, -54.48503, 1.758327, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- SI:7 Operative (Area: 0 - Difficulty: Normal) (Auras: 262360 - Stealth)
(@CGUID+236, 131957, 1, 9310, 0, '0', '0', 0, 0, 0, -6614.437, 658.4464, -53.81836, 4.167365, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- SI:7 Operative (Area: 0 - Difficulty: Normal) (Auras: 262360 - Stealth)
(@CGUID+237, 131957, 1, 9310, 0, '0', '0', 0, 0, 0, -6649.433, 658.0117, -55.2309, 5.098768, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- SI:7 Operative (Area: 0 - Difficulty: Normal) (Auras: 262360 - Stealth)
(@CGUID+238, 131957, 1, 9310, 0, '0', '0', 0, 0, 0, -6647.037, 674.6996, -54.56824, 5.782904, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- SI:7 Operative (Area: 0 - Difficulty: Normal) (Auras: 262360 - Stealth)
(@CGUID+239, 132062, 1, 9310, 0, '0', '0', 0, 0, 0, -6729.371, 658.6024, -80.09901, 1.254306, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Bilgewater Laborer (Area: 0 - Difficulty: Normal) (Auras: 261780 - Carrying Crate) (possible waypoints or random movement)
(@CGUID+240, 131957, 1, 9310, 0, '0', '0', 0, 0, 0, -6627.63, 691.2309, -54.48503, 4.908071, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- SI:7 Operative (Area: 0 - Difficulty: Normal) (Auras: 262360 - Stealth)
(@CGUID+241, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6766.405, 728.7969, -84.18069, 4.63026, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+242, 132062, 1, 9310, 0, '0', '0', 0, 0, 0, -6757.188, 819.4531, -90.93576, 3.046413, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Laborer (Area: 0 - Difficulty: Normal)
(@CGUID+243, 133022, 1, 9310, 0, '0', '0', 0, 0, 0, -6771.587, 773.4184, -90.92156, 1.007724, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Inactive Shredder (Area: 0 - Difficulty: Normal)
(@CGUID+244, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6772.432, 774.1667, -90.91745, 3.780318, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+245, 131957, 1, 9310, 0, '0', '0', 0, 0, 0, -6784.018, 741.4788, -84.25771, 4.672736, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- SI:7 Operative (Area: 0 - Difficulty: Normal)
(@CGUID+246, 132042, 1, 9310, 0, '0', '0', 0, 0, 0, -6759.361, 819.7239, -90.9566, 5.744195, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Mook (Area: 0 - Difficulty: Normal)
(@CGUID+247, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6772.583, 773.8906, -90.91798, 3.937161, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+248, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6770.347, 774.2743, -90.92174, 5.081407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+249, 133022, 1, 9310, 0, '0', '0', 0, 0, 0, -6825.974, 739.8663, -92.55225, 2.643281, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153); -- Inactive Shredder (Area: 0 - Difficulty: Normal)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+250, 131957, 1, 9310, 0, '0', '0', 0, 0, 0, -6830.106, 770.3657, -92.89883, 2.579965, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- SI:7 Operative (Area: 0 - Difficulty: Normal)
(@CGUID+251, 131957, 1, 9310, 0, '0', '0', 0, 0, 0, -6758.334, 733.333, -84.22408, 3.122948, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- SI:7 Operative (Area: 0 - Difficulty: Normal) (Auras: 262360 - Stealth)
(@CGUID+252, 133022, 1, 9310, 0, '0', '0', 0, 0, 0, -6818.351, 686.7101, -92.555, 3.272924, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Inactive Shredder (Area: 0 - Difficulty: Normal)
(@CGUID+253, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6830.014, 804.7778, -98.57578, 1.890264, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+254, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6683.83, 822.4861, -83.18402, 0.9610859, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+255, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6838.653, 810.0868, -98.27324, 1.064982, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+256, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6815.925, 823.0121, -94.25817, 4.190429, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+257, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6813.974, 857.092, -94.91609, 4.295659, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+258, 131957, 1, 9310, 0, '0', '0', 0, 0, 0, -6763.411, 792.1026, -90.92493, 1.821478, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- SI:7 Operative (Area: 0 - Difficulty: Normal) (Auras: 262360 - Stealth)
(@CGUID+259, 131957, 1, 9310, 0, '0', '0', 0, 0, 0, -6768.24, 839.2874, -98.20029, 2.537719, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- SI:7 Operative (Area: 0 - Difficulty: Normal) (Auras: 262360 - Stealth)
(@CGUID+260, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -6749.304, 906.2837, -94.02852, 1.60402, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+261, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6683.156, 852.5139, -83.21773, 3.954898, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+262, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6675.347, 821.6094, -83.56438, 4.236633, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+263, 132055, 1, 9310, 0, '0', '0', 0, 0, 0, -6690.403, 854.0018, -83.05377, 0.3218974, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal)
(@CGUID+264, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6786.459, 941.1239, -103.4034, 2.604269, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+265, 131957, 1, 9310, 0, '0', '0', 0, 0, 0, -6791.949, 884.1739, -96.66096, 3.321332, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- SI:7 Operative (Area: 0 - Difficulty: Normal) (Auras: 262360 - Stealth)
-- (@CGUID+266, 132055, UNKNOWN, 9310, 0, '0', '0', 0, 0, 0, 0.01586911, 0, 4.580903, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Prospector (Area: 0 - Difficulty: Normal) (Auras: 46598 - Ride Vehicle Hardcoded) - !!! on transport - transport template not found !!!
(@CGUID+267, 132164, 1, 9310, 0, '0', '0', 0, 0, 0, -6704.851, 880.6399, -84.1606, 3.449295, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Bilgewater Shredder (Area: 0 - Difficulty: Normal) (Auras: )
(@CGUID+268, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -6731.548, 966.4369, -95.06044, 1.303902, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+269, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6852.373, 951.0995, -105.2298, 0.02067707, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+270, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6768.471, 1016.888, -100.9669, 6.181377, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+271, 137907, 1, 9310, 0, '0', '0', 0, 0, 0, -6768.63, 1113.278, -104.3041, 3.452736, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Infused Crag (Area: 0 - Difficulty: Normal)
(@CGUID+272, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -6712.08, 1086.988, -97.29707, 0.7020204, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+273, 137906, 1, 9310, 0, '0', '0', 0, 0, 0, -6820.125, 1149.592, -101.1245, 4.237589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Infused Bedrock (Area: 0 - Difficulty: Normal) (Auras: 270813 - Azerite Empowered)
(@CGUID+274, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -6701.118, 1133.648, -100.1445, 4.031542, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+275, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -6698.658, 1127.471, -99.36203, 4.48376, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+276, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -6733.026, 1186.148, -100.5494, 5.195685, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+277, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -6762.625, 1177.01, -101.1334, 6.185929, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+278, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -6772.108, 1192.07, -100.0116, 5.626, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+279, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6805.79, 1169.028, -101.108, 2.979099, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+280, 137904, 1, 9310, 0, '0', '0', 0, 0, 0, -6765.008, 1174.721, -101.0304, 6.049416, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Minor Azerite Infused Elemental (Area: 0 - Difficulty: Normal)
(@CGUID+281, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -6797.564, 1178.68, -101.2088, 4.233174, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+282, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -6650.629, 1122.847, -90.18946, 5.36887, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+283, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -6666.774, 1116.979, -92.92337, 3.684861, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+284, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6690.712, 1211.749, -101.2287, 3.121114, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+285, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -6694.487, 1190.121, -102.2026, 4.198086, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+286, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -6670.285, 1170.561, -96.79929, 5.491744, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+287, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -6752.515, 1238.881, -101.1407, 6.085528, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+288, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -6710.72, 1233.875, -105.915, 1.963634, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+289, 137905, 1, 9310, 0, '0', '0', 0, 0, 0, -6754.049, 1232.96, -101.1748, 0.8326407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+290, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6644.71, 1253.199, -78.82872, 1.851367, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+291, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6518.582, 1349.161, -30.32945, 5.241481, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+292, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -6504.468, 1334.931, -9.834399, 3.489332, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+293, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6602.492, 1332.356, -45.47117, 1.787171, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+294, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -6780.446, 1478.316, 8.648502, 2.504278, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+295, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -6606.894, 1515.884, -4.375501, 0.9742225, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+296, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -6591.542, 1444.847, -27.94475, 0.9372597, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+297, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6561.431, 1426.951, -23.48448, 5.459796, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+298, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6468.999, 1432.778, -18.14299, 2.323654, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+299, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6582.53, 1544.917, -21.77788, 1.277468, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+300, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6590.718, 1491.306, -25.65751, 0.2828946, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+301, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -6552.477, 1486.021, -19.34501, 5.856297, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+302, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6455.006, 1615.452, 11.92391, 3.491217, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+303, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6698.293, 1635.335, 0.7982259, 5.087989, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+304, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -6677.432, 1644.805, 29.18074, 4.301373, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+305, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6401.176, 1497.078, 1.749393, 3.300306, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+306, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -6417.173, 1608.249, 26.58167, 0.7205462, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+307, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6377.015, 1633.815, 5.843017, 1.878342, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+308, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6455.476, 1712.263, 14.87134, 2.059873, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+309, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -6311.729, 1607.22, 13.25499, 2.047544, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+310, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -6305.221, 1771.28, 2.565204, 3.867587, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+311, 131909, 1, 9310, 0, '0', '0', 0, 0, 0, -6421.528, 1789.958, 1.767035, 2.122676, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Wasteland Crusher (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+312, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -6301.521, 1700.625, 15.03446, 4.603173, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+313, 131909, 1, 9310, 9472, '0', '0', 0, 0, 0, -6395.264, 1832.091, 7.103391, 0.5126023, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Wasteland Crusher (Area: The Crystal Vale - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+314, 131896, 1, 9310, 9472, '0', '0', 0, 0, 0, -6262.334, 1777.572, 11.00604, 4.838863, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+315, 131906, 1, 9310, 9472, '0', '0', 0, 0, 0, -6333.44, 1824.127, 5.790307, 0.76793, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Sand Stormer (Area: The Crystal Vale - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+316, 131943, 1, 9310, 9472, '0', '0', 0, 0, 0, -6234.278, 1778.269, 13.75649, 3.471486, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Highlord Demitrian (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+317, 131904, 1, 9310, 9472, '0', '0', 0, 0, 0, -6250.775, 1716.333, 5.752361, 6.27342, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+318, 131896, 1, 9310, 9472, '0', '0', 0, 0, 0, -6230.705, 1790.619, 10.81212, 5.150784, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+319, 131906, 1, 9310, 9472, '0', '0', 0, 0, 0, -6186.059, 1740.962, 21.33282, 3.819403, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+320, 131896, 1, 9310, 9472, '0', '0', 0, 0, 0, -6213.494, 1715.402, 7.858884, 5.40508, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+321, 131904, 1, 9310, 9472, '0', '0', 0, 0, 0, -6198.347, 1767.857, 16.3997, 3.352959, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+322, 131906, 1, 9310, 9472, '0', '0', 0, 0, 0, -6231.149, 1684.984, 8.266939, 3.745613, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+323, 131896, 1, 9310, 9472, '0', '0', 0, 0, 0, -6221.342, 1665.591, 6.450218, 2.97425, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+324, 131906, 1, 9310, 9472, '0', '0', 0, 0, 0, -6156.296, 1767.416, 27.83282, 3.742134, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+325, 131906, 1, 9310, 9472, '0', '0', 0, 0, 0, -6425.49, 1870.368, 6.341438, 4.231795, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+326, 131909, 1, 9310, 9472, '0', '0', 0, 0, 0, -6461.76, 1800.889, 7.799157, 2.151965, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Wasteland Crusher (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+327, 131906, 1, 9310, 9472, '0', '0', 0, 0, 0, -6471.62, 1831.846, 5.577109, 1.615732, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+328, 131896, 1, 9310, 9472, '0', '0', 0, 0, 0, -6461.596, 1849.526, 5.81404, 2.431882, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+329, 131909, 1, 9310, 9472, '0', '0', 0, 0, 0, -6540.894, 1830.25, 5.849147, 2.233639, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Wasteland Crusher (Area: The Crystal Vale - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+330, 131906, 1, 9310, 9472, '0', '0', 0, 0, 0, -6486.416, 1876.295, 0.7485478, 1.779298, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+331, 131909, 1, 9310, 9472, '0', '0', 0, 0, 0, -6520.228, 1826.944, 6.546357, 0.4191161, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Wasteland Crusher (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+332, 131897, 1, 9310, 9472, '0', '0', 0, 0, 0, -6659.799, 1718.731, 8.389245, 5.29335, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+333, 131909, 1, 9310, 9472, '0', '0', 0, 0, 0, -6523.228, 1879.672, 5.725792, 2.37746, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Wasteland Crusher (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+334, 131904, 1, 9310, 9472, '0', '0', 0, 0, 0, -6493.746, 1898.377, 4.91422, 1.104965, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+335, 131906, 1, 9310, 9472, '0', '0', 0, 0, 0, -6520.791, 1918.426, 6.27761, 2.248282, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+336, 131909, 1, 9310, 9472, '0', '0', 0, 0, 0, -6596.875, 1883.333, 4.832941, 2.3907, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Wasteland Crusher (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+337, 131903, 1, 9310, 9472, '0', '0', 0, 0, 0, -6647.806, 1842.437, 4.5719, 0.119316, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+338, 131909, 1, 9310, 9472, '0', '0', 0, 0, 0, -6562.201, 1920.772, 5.336772, 3.640834, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Wasteland Crusher (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+339, 131909, 1, 9310, 9472, '0', '0', 0, 0, 0, -6621.638, 1891.775, 4.575172, 2.599456, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Wasteland Crusher (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+340, 131893, 1, 9310, 9472, '0', '0', 0, 0, 0, -6640.79, 1850.442, 7.029176, 0.05810612, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+341, 131896, 1, 9310, 9472, '0', '0', 0, 0, 0, -6586.934, 1925.528, 6.115941, 1.584896, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+342, 131895, 1, 9310, 9472, '0', '0', 0, 0, 0, -6675.165, 1837.884, 10.40033, 2.349622, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+343, 131903, 1, 9310, 9472, '0', '0', 0, 0, 0, -6671.978, 1827.266, 3.30805, 2.747789, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+344, 131893, 1, 9310, 9472, '0', '0', 0, 0, 0, -6656.135, 1885.431, 6.604425, 3.882101, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+345, 131893, 1, 9310, 9472, '0', '0', 0, 0, 0, -6660.456, 1825.149, 4.726001, 0.7250158, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+346, 131893, 1, 9310, 9472, '0', '0', 0, 0, 0, -6658.858, 1844.158, 3.999956, 3.678294, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+347, 131903, 1, 9310, 9472, '0', '0', 0, 0, 0, -6665.035, 1828.118, 4.528857, 2.589506, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+348, 131893, 1, 9310, 9472, '0', '0', 0, 0, 0, -6679.733, 1820.606, 1.647621, 2.337587, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+349, 131895, 1, 9310, 9472, '0', '0', 0, 0, 0, -6656.431, 1864.668, 18.16315, 3.776586, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+350, 131893, 1, 9310, 9472, '0', '0', 0, 0, 0, -6684.458, 1838.974, 6.018191, 5.951779, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+351, 131903, 1, 9310, 9472, '0', '0', 0, 0, 0, -6703.069, 1859.6, 6.731276, 2.175177, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+352, 131897, 1, 9310, 9472, '0', '0', 0, 0, 0, -6759.351, 1739.813, -2.714024, 1.738265, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+353, 131903, 1, 9310, 9472, '0', '0', 0, 0, 0, -6704.439, 1851.302, 6.78694, 5.519135, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+354, 131893, 1, 9310, 9472, '0', '0', 0, 0, 0, -6699.285, 1906.207, 5.626241, 5.079844, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+355, 131903, 1, 9310, 9472, '0', '0', 0, 0, 0, -6685.798, 1798.63, 4.199528, 4.065836, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+356, 131904, 1, 9310, 9472, '0', '0', 0, 0, 0, -6647.507, 1924.373, 4.575046, 0.9559202, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+357, 131895, 1, 9310, 9472, '0', '0', 0, 0, 0, -6690.063, 1847.238, 11.8996, 0.3777364, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+358, 131893, 1, 9310, 9472, '0', '0', 0, 0, 0, -6704.908, 1821.655, 0.7013516, 5.162445, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+359, 131903, 1, 9310, 9472, '0', '0', 0, 0, 0, -6725.51, 1868.75, 4.4324, 1.056867, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+360, 131903, 1, 9310, 9472, '0', '0', 0, 0, 0, -6696.93, 1805.495, 2.216986, 2.743223, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+361, 131892, 1, 9310, 9472, '0', '0', 0, 0, 0, -6711.529, 1867.618, 5.39567, 1.921728, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Sentinel (Area: The Crystal Vale - Difficulty: Normal)
(@CGUID+362, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6746.462, 1885.83, 9.972859, 2.349622, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+363, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6724.154, 1825.308, 6.875111, 0.7951066, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+364, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6743.006, 1857.227, 1.82915, 4.071087, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+365, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6720.267, 1816.134, 5.383938, 3.1006, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+366, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6743.179, 1872.483, 5.825601, 3.421935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+367, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6733.534, 1864.028, 4.093799, 2.542649, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+368, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6755.757, 1828.141, 5.505129, 4.641151, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+369, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6746.233, 1816.882, 10.75114, 3.601318, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+370, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6756.275, 1839.036, 5.649829, 4.398252, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+371, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6775.757, 1849.313, 2.390549, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+372, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6718.42, 1797.395, -2.075392, 0.1717282, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+373, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6769.781, 1852.826, 6.124828, 0.8999119, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+374, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6691.508, 1797.718, 3.326237, 0.7660636, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+375, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6766.705, 1842.181, 3.999584, 1.646588, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+376, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6705.507, 1790.516, -0.1236093, 3.052815, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+377, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6742.411, 1763.549, 3.441889, 0.8634053, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+378, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6786.276, 1804.986, 4.758525, 3.198243, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+379, 131890, 1, 9310, 9478, '0', '0', 0, 0, 0, -6741.886, 1667.319, 17.42459, 1.721573, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+380, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6794.122, 1821.566, 0.5154905, 5.619229, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+381, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6818.69, 1827.111, -2.31468, 0.336913, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+382, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6767.967, 1804.172, 7.902544, 3.839098, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+383, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6766.666, 1773.438, -0.3067555, 2.793996, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+384, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6806.524, 1818.726, -2.153303, 4.985554, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+385, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6742.403, 1798.934, 9.97578, 2.349622, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+386, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6762.5, 1788.021, 2.246669, 4.206917, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+387, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6751.702, 1773.825, 3.652187, 4.326354, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+388, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6753.156, 1783.453, 1.521938, 1.604883, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+389, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6776.629, 1779.291, -0.4466481, 4.757751, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+390, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6776.569, 1775.818, -0.2467645, 1.428003, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+391, 132526, 1, 9310, 9478, '0', '0', 0, 0, 0, -6883.599, 1692.11, 38.2775, 1.99006, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+392, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6790.948, 1761.235, -0.292757, 4.463619, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+393, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6785.435, 1754.814, 3.267668, 4.744874, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+394, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6838.582, 1841.764, 3.685585, 2.499615, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+395, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6855.559, 1763.566, 4.976041, 5.898392, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+396, 131892, 1, 9310, 9478, '0', '0', 0, 0, 0, -6878.163, 1797.66, 6.223454, 1.783322, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Sentinel (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+397, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6851.281, 1849.71, 11.51399, 2.246378, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+398, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6878.846, 1803.671, 6.076904, 0.3276911, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+399, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6845.578, 1837.134, 4.069339, 1.428003, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+400, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6786.471, 1746.114, 1.988493, 0.3732663, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+401, 132584, 1, 9310, 9478, '0', '0', 0, 0, 0, -6817.688, 1786.141, 0.8112894, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Xaarshej (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+402, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6828.282, 1749.953, -1.925011, 5.507769, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+403, 131897, 1, 9310, 9478, '0', '0', 0, 0, 0, -6846.666, 1651.597, 4.711682, 4.97513, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+404, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6777.539, 1731.583, -3.517432, 5.154892, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+405, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6854.7, 1801.498, 1.257923, 1.428003, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+406, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6846.052, 1774.244, 2.393046, 5.513284, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+407, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6807.546, 1757.302, 2.321234, 2.309941, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+408, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6814.311, 1742.557, 1.815018, 1.408356, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+409, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6832.157, 1802.477, 0.1414964, 0.8301444, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+410, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6846.878, 1757.217, 2.2769, 2.349622, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+411, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6872.15, 1822.205, 5.258742, 6.037398, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+412, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6872.785, 1832.514, 11.61259, 2.349622, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+413, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6889.133, 1746.593, 1.164092, 0.7288001, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+414, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6866.236, 1727.925, 1.537485, 5.269603, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+415, 131892, 1, 9310, 9478, '0', '0', 0, 0, 0, -6827.562, 1733.513, 2.905019, 2.535986, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Sentinel (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+416, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6836.355, 1725.306, 1.796283, 1.490439, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+417, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6805.118, 1714.705, -3.043868, 5.259403, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+418, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6851.062, 1726.446, 3.184368, 2.043311, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+419, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6893.639, 1799.617, 3.43185, 1.853142, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+420, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6890.306, 1826.845, 9.959215, 1.135215, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+421, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6853.323, 1714.582, 9.851616, 4.836137, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+422, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6908.901, 1781.37, 6.472883, 2.349622, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+423, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6897.315, 1816.652, 5.885382, 2.762214, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+424, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6890.376, 1775.536, 2.691835, 0.07771, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+425, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6879.62, 1757.682, 3.020696, 5.720448, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+426, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6873.208, 1702.697, 9.323971, 4.148588, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+427, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6923.259, 1819.321, 5.177749, 0.5570449, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+428, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6851.365, 1706.2, 10.68171, 2.349622, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+429, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6865.765, 1692.834, 8.32221, 4.415811, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+430, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6843.865, 1693.258, 7.026185, 4.736873, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+431, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6917.259, 1842.856, 16.11249, 2.349622, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+432, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6930.787, 1776.345, 3.143395, 5.755916, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+433, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6927.788, 1777.177, 3.85317, 1.428003, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+434, 131892, 1, 9310, 9478, '0', '0', 0, 0, 0, -6892.251, 1735.729, -0.5509957, 4.602561, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Sentinel (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+435, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6912.906, 1775.406, 5.129968, 0.8901269, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+436, 131890, 1, 9310, 9478, '0', '0', 0, 0, 0, -6966.097, 1643.458, 13.15918, 3.547511, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+437, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6935.237, 1785.245, 1.642886, 3.296389, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+438, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6922.116, 1784.243, 7.079799, 1.300003, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+439, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6931.633, 1819.264, 5.203798, 6.111331, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+440, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6916.497, 1817.336, 5.012026, 4.400542, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+441, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6923.167, 1828.807, 7.691277, 2.349622, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+442, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6944.559, 1763.848, -0.2645755, 1.95094, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+443, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6948.105, 1818.799, 2.682545, 3.740998, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+444, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6947.594, 1831.205, 5.421543, 1.428003, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+445, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6948.307, 1805.453, 4.830309, 3.747181, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+446, 131897, 1, 9310, 9478, '0', '0', 0, 0, 0, -6966.942, 1600.014, -1.084781, 3.853077, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+447, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6977.356, 1793.977, 3.945973, 4.24253, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+448, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6984.042, 1798.262, 4.361442, 2.288774, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+449, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6979.016, 1739.649, 3.049938, 2.598247, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+450, 131895, 1, 9310, 9478, '0', '0', 0, 0, 0, -6986.912, 1814.542, 7.708189, 0.5329688, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Spitfire (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+451, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -6968.643, 1812.618, 4.012182, 2.936375, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+452, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6980.189, 1746.326, 3.424732, 5.477441, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+453, 131892, 1, 9310, 9478, '0', '0', 0, 0, 0, -6998.499, 1781.104, 3.945973, 3.787461, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Sentinel (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+454, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6972.614, 1826.519, 4.165351, 4.433971, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+455, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6997.506, 1813.079, 5.329927, 3.023635, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+456, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -7014.108, 1825.7, 1.60224, 2.077536, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+457, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6987.5, 1836.459, 4.268933, 6.006725, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+458, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -7012.493, 1829.028, 0.7887841, 5.938459, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+459, 131897, 1, 9310, 9478, '0', '0', 0, 0, 0, -7078.408, 1659.57, 4.49984, 1.584467, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+460, 131893, 1, 9310, 9478, '0', '0', 0, 0, 0, -7020.301, 1811.159, 5.859752, 1.177614, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Drone (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+461, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -7008.637, 1818.763, 5.041693, 2.300198, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+462, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -6991.375, 1833.357, 4.584572, 1.421291, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+463, 131892, 1, 9310, 9478, '0', '0', 0, 0, 0, -7009.725, 1856.146, 6.782928, 4.248304, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Sentinel (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+464, 131903, 1, 9310, 9478, '0', '0', 0, 0, 0, -7007.78, 1854.729, 6.262424, 4.178831, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Silithid Broodling (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+465, 131897, 1, 9310, 9478, '0', '0', 0, 0, 0, -7184.826, 1669.282, 18.08841, 0.2725246, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+466, 132526, 1, 9310, 9478, '0', '0', 0, 0, 0, -6975.776, 1544.074, 8.360578, 1.396497, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+467, 131890, 1, 9310, 9478, '0', '0', 0, 0, 0, -7208.719, 1765.339, -1.916391, 3.48186, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+468, 131890, 1, 9310, 9478, '0', '0', 0, 0, 0, -7215.282, 1592.413, 5.170897, 4.709867, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+469, 131890, 1, 9310, 9478, '0', '0', 0, 0, 0, -7263.434, 1639.253, 10.21159, 1.500394, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+470, 132526, 1, 9310, 9478, '0', '0', 0, 0, 0, -7255.208, 1635.36, 27.46104, 1.60541, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: Hive'Zora - Difficulty: Normal)
(@CGUID+471, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -7315.763, 1660.678, 11.0162, 4.96329, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+472, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7327.084, 1619.43, 4.415812, 2.715531, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+473, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7333.229, 1533.438, 5.271777, 5.782825, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+474, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -7273.494, 1606.355, 4.798065, 2.446159, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+475, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -7274.859, 1682.276, 15.95426, 3.28941, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+476, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7390.956, 1508.997, -0.7485738, 5.702225, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+477, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7517.865, 1568.569, -23.23916, 1.259234, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+478, 131909, 1, 9310, 0, '0', '0', 0, 0, 0, -7480.441, 1639.459, -41.70774, 0.4484698, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Wasteland Crusher (Area: 0 - Difficulty: Normal)
(@CGUID+479, 131909, 1, 9310, 0, '0', '0', 0, 0, 0, -7468.863, 1693.479, -42.12165, 4.313393, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Wasteland Crusher (Area: 0 - Difficulty: Normal)
(@CGUID+480, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -7561.9, 1588.474, -9.814617, 2.105752, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+481, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7557.527, 1509.602, -14.59673, 1.179176, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+482, 131909, 1, 9310, 0, '0', '0', 0, 0, 0, -7479.637, 1753.54, -39.04737, 0.005166885, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Wasteland Crusher (Area: 0 - Difficulty: Normal)
(@CGUID+483, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -7614.559, 1564.306, -3.156546, 0.4313162, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+484, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -7739.312, 1588.604, 31.03131, 3.801659, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+485, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7700.886, 1500.087, 3.110572, 5.627966, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+486, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7714.236, 1668.944, 7.65708, 3.181611, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+487, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7765.464, 1598.721, 8.86324, 1.98466, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+488, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -7649.547, 1531.582, -1.886804, 4.988666, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+489, 132526, 1, 9310, 0, '0', '0', 0, 0, 0, -7659.487, 1408.358, 29.13792, 2.58727, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+490, 131890, 1, 9310, 0, '0', '0', 0, 0, 0, -7783.749, 1554.742, 9.646736, 2.357558, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- -Unknown- (Area: 0 - Difficulty: Normal)
(@CGUID+491, 131897, 1, 9310, 0, '0', '0', 0, 0, 0, -7809.01, 1714.299, 3.62462, 2.079908, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Stonelash Pincer (Area: 0 - Difficulty: Normal)
(@CGUID+492, 131904, 1, 9310, 0, '0', '0', 0, 0, 0, -7759.499, 1682.793, 3.180866, 0.1558407, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Spiky Lizard (Area: 0 - Difficulty: Normal)
(@CGUID+493, 131907, 1, 9310, 0, '0', '0', 0, 0, 0, -7748.325, 1720.67, 12.56792, 1.984927, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Ritualist (Area: 0 - Difficulty: Normal) (Auras: 51733 - Shadow Channelling)
(@CGUID+494, 131907, 1, 9310, 0, '0', '0', 0, 0, 0, -7831.049, 1684.238, 2.203705, 0.277813, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Ritualist (Area: 0 - Difficulty: Normal)
(@CGUID+495, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -7815.319, 1587.788, 6.636096, 0.9696078, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+496, 131907, 1, 9310, 0, '0', '0', 0, 0, 0, -7827.507, 1684.729, 2.322544, 3.389898, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Ritualist (Area: 0 - Difficulty: Normal)
(@CGUID+497, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -7849.169, 1637.757, 1.223908, 1.330543, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)
(@CGUID+498, 132199, 1, 9310, 0, '0', '0', 0, 0, 0, -7830.275, 1746.605, 0.779479, 5.548194, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Earthbreaker (Area: 0 - Difficulty: Normal)
(@CGUID+499, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -7882.306, 1712.55, -0.6958075, 6.188562, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153); -- Scorpid Skitterer (Area: 0 - Difficulty: Normal)

INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+500, 131896, 1, 9310, 0, '0', '0', 0, 0, 0, -7912.407, 1631.908, -1.059496, 5.630448, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: 0 - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+501, 131907, 1, 9310, 9475, '0', '0', 0, 0, 0, -7921.236, 1744.887, -7.594441, 4.874136, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Ritualist (Area: Twilight Outpost - Difficulty: Normal) (Auras: 51733 - Shadow Channelling)
(@CGUID+502, 131907, 1, 9310, 9475, '0', '0', 0, 0, 0, -7914.12, 1738.53, -8.589351, 2.83887, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Ritualist (Area: Twilight Outpost - Difficulty: Normal) (Auras: 51733 - Shadow Channelling)
(@CGUID+503, 131908, 1, 9310, 9475, '0', '0', 0, 0, 0, -7935.208, 1724.844, -2.828068, 1.690175, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Survivor (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+504, 131907, 1, 9310, 9475, '0', '0', 0, 0, 0, -7824.997, 1775.715, -1.456447, 1.20157, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Ritualist (Area: Twilight Outpost - Difficulty: Normal) (Auras: 51733 - Shadow Channelling)
(@CGUID+505, 132199, 1, 9310, 9475, '0', '0', 0, 0, 0, -7941.185, 1732.291, -2.22055, 2.718116, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Earthbreaker (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+506, 131908, 1, 9310, 9475, '0', '0', 0, 0, 0, -7949.969, 1728.885, -1.020649, 1.04138, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Survivor (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+507, 131907, 1, 9310, 9475, '0', '0', 0, 0, 0, -7945.332, 1726.24, -1.412531, 4.498615, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Ritualist (Area: Twilight Outpost - Difficulty: Normal) (Auras: 51733 - Shadow Channelling)
(@CGUID+508, 131907, 1, 9310, 9475, '0', '0', 0, 0, 0, -7929.309, 1778.53, 1.239468, 4.961885, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Ritualist (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+509, 131909, 1, 9310, 9475, '0', '0', 0, 0, 0, -8012.299, 1706.87, 4.071802, 5.744488, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Wasteland Crusher (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+510, 131906, 1, 9310, 9475, '0', '0', 0, 0, 0, -8011.717, 1750.216, -0.8617011, 2.614081, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+511, 131897, 1, 9310, 9475, '0', '0', 0, 0, 0, -8066.173, 1591.913, 13.25251, 6.061407, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153), -- Stonelash Pincer (Area: Twilight Outpost - Difficulty: Normal) (possible waypoints or random movement)
(@CGUID+512, 131896, 1, 9310, 9475, '0', '0', 0, 0, 0, -7963.368, 1803.291, 1.09927, 0.7771564, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+513, 131907, 1, 9310, 9475, '0', '0', 0, 0, 0, -7891.505, 1804.727, 2.065448, 1.478595, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Ritualist (Area: Twilight Outpost - Difficulty: Normal) (Auras: 51733 - Shadow Channelling)
(@CGUID+514, 131896, 1, 9310, 9475, '0', '0', 0, 0, 0, -7986.631, 1718.333, 0.7590671, 0.919952, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Scorpid Skitterer (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+515, 131906, 1, 9310, 9475, '0', '0', 0, 0, 0, -7986.869, 1684.215, 0.8985172, 3.747199, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+516, 131909, 1, 9310, 9475, '0', '0', 0, 0, 0, -8012.435, 1699.483, 5.637468, 0.6544446, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Wasteland Crusher (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+517, 131908, 1, 9310, 9475, '0', '0', 0, 0, 0, -8003.031, 1801.293, 3.213257, 5.942888, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Survivor (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+518, 132591, 1, 9310, 9475, '0', '0', 0, 0, 0, -7942.149, 1825.916, 4.127298, 1.125085, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Ogmot the Mad (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+519, 131908, 1, 9310, 9475, '0', '0', 0, 0, 0, -8005.34, 1794.734, 3.07808, 5.917713, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Survivor (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+520, 131907, 1, 9310, 9475, '0', '0', 0, 0, 0, -8015.299, 1800.66, 3.368836, 2.738364, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Ritualist (Area: Twilight Outpost - Difficulty: Normal) (Auras: 51733 - Shadow Channelling)
(@CGUID+521, 131906, 1, 9310, 9475, '0', '0', 0, 0, 0, -8071.612, 1732.503, -1.824285, 1.338364, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+522, 131906, 1, 9310, 9475, '0', '0', 0, 0, 0, -8070.266, 1684.021, 6.616852, 4.912848, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Sand Stormer (Area: Twilight Outpost - Difficulty: Normal)
(@CGUID+523, 133263, 1, 9310, 10030, '0', '0', 0, 0, 0, -8056.943, 1630.45, 25.31619, 4.472199, 120, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Rhonormu (Area: The Scarab Wall - Difficulty: Normal) (Auras: 132482 - Aura Tall - Yellow)
(@CGUID+524, 131897, 1, 9310, 10030, '0', '0', 0, 0, 0, -8072.568, 1531.042, 2.734401, 5.147842, 120, 10, 0, 0, 0, 1, 0, 0, 0, 28153); -- Stonelash Pincer (Area: The Scarab Wall - Difficulty: Normal) (possible waypoints or random movement)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+524;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 1, 0, 0, 0, 0, '271753'), -- -Unknown- - 271753 - Azerite Explosion
(@CGUID+1, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+2, 0, 0, 0, 1, 0, 0, 0, 0, '271753'), -- -Unknown- - 271753 - Azerite Explosion
(@CGUID+3, 0, 0, 0, 1, 0, 0, 0, 0, '271753'), -- -Unknown- - 271753 - Azerite Explosion
(@CGUID+4, 0, 0, 0, 1, 0, 0, 0, 0, '271753'), -- -Unknown- - 271753 - Azerite Explosion
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+6, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+7, 0, 0, 0, 1, 0, 0, 0, 0, '271753'), -- -Unknown- - 271753 - Azerite Explosion
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, '271753'), -- -Unknown- - 271753 - Azerite Explosion
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, '271753'), -- -Unknown- - 271753 - Azerite Explosion
(@CGUID+10, 0, 0, 0, 1, 0, 0, 0, 0, '271753'), -- -Unknown- - 271753 - Azerite Explosion
(@CGUID+11, 0, 0, 0, 1, 0, 0, 0, 0, '271753'), -- -Unknown- - 271753 - Azerite Explosion
(@CGUID+12, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+13, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+14, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Infused Crag
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, '270813'), -- Infused Bedrock - 270813 - Azerite Empowered
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+17, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+19, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+20, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+22, 0, 0, 0, 1, 0, 0, 0, 0, '270813'), -- Infused Bedrock - 270813 - Azerite Empowered
(@CGUID+23, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+24, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+25, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+26, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+28, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+29, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+30, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+31, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+33, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+34, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+36, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+37, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+38, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+40, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+41, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+43, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+44, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+45, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+46, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+47, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+48, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+49, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+50, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+51, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+53, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+54, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+55, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+56, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+57, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+58, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+59, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+60, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+61, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+62, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+63, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+64, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+65, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+66, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+67, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+68, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+69, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+70, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+72, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+73, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+75, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+76, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+77, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Horde Grunt
(@CGUID+78, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+79, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+80, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Horde Grunt
(@CGUID+81, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Horde Grunt
(@CGUID+82, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+83, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Gaula Axefury
(@CGUID+84, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Worker
(@CGUID+85, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Worker
(@CGUID+86, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Pixni Rustbomb
(@CGUID+87, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Mechanic
(@CGUID+88, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Gizmax Greasebolt
(@CGUID+89, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Worker
(@CGUID+90, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Mechanic
(@CGUID+91, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Worker
(@CGUID+92, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Horde Grunt
(@CGUID+93, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+94, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Worker
(@CGUID+95, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Worker
(@CGUID+96, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Worker
(@CGUID+97, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Worker
(@CGUID+98, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Mechanic
(@CGUID+99, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Hagras Wartaker
(@CGUID+100, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Bilgewater Worker
(@CGUID+101, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Grol Warblade
(@CGUID+102, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Horde Grunt
(@CGUID+103, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Horde Grunt
(@CGUID+104, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Horde Grunt
(@CGUID+105, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+106, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Urok Windcleaver
(@CGUID+107, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Horde Grunt
(@CGUID+108, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+109, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+110, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+111, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+112, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+113, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+114, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+115, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+116, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+117, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+118, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+119, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+120, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+121, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+122, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+123, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+124, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+125, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+126, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+127, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+128, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+129, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+130, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+131, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+132, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+133, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+134, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+135, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+136, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+137, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+138, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+139, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+140, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+141, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+142, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+143, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+144, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+145, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+146, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+147, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+148, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+149, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+150, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+151, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+152, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+153, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+154, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+155, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+156, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+157, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+158, 0, 0, 33554432, 1, 0, 0, 0, 0, '132482'), -- Zidormi - 132482 - Aura Tall - Yellow
(@CGUID+159, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+160, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+161, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Edmund Hackney
(@CGUID+162, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+163, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+164, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Tammy Tinkspinner
(@CGUID+165, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Khargus Stonemantle
(@CGUID+166, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+167, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Alliance Guard
(@CGUID+168, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+169, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nolan Speed
(@CGUID+170, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Alliance Guard
(@CGUID+171, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Alliance Guard
(@CGUID+172, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Laurette Royston
(@CGUID+173, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Kelsey Steelspark
(@CGUID+174, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Clifford Bentham
(@CGUID+175, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+176, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Alliance Guard
(@CGUID+177, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+178, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+179, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+180, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+181, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Alliance Guard
(@CGUID+182, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Alliance Guard
(@CGUID+183, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+184, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Alliance Guard
(@CGUID+185, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+186, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+187, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+188, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Alliance Guard
(@CGUID+189, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+190, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+191, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+192, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+193, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Alliance Guard
(@CGUID+194, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+195, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Alliance Guard
(@CGUID+196, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Alliance Worker
(@CGUID+197, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Alliance Guard
(@CGUID+198, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+199, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Alliance Guard
(@CGUID+200, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+201, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+202, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+203, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+204, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+205, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+206, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+207, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+208, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+209, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+210, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+211, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+212, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+213, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+214, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+215, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+216, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+217, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+218, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+219, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+220, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+221, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Bilgewater Laborer
(@CGUID+222, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Bilgewater Laborer
(@CGUID+223, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+224, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+225, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Inactive Shredder
(@CGUID+226, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+227, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+228, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Bilgewater Laborer
(@CGUID+229, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+230, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+231, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+232, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Mook
(@CGUID+233, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Bilgewater Laborer
(@CGUID+234, 0, 0, 131072, 1, 0, 0, 0, 0, '262360'), -- SI:7 Operative - 262360 - Stealth
(@CGUID+235, 0, 0, 131072, 1, 0, 0, 0, 0, '262360'), -- SI:7 Operative - 262360 - Stealth
(@CGUID+236, 0, 0, 131072, 1, 0, 0, 0, 0, '262360'), -- SI:7 Operative - 262360 - Stealth
(@CGUID+237, 0, 0, 131072, 1, 0, 0, 0, 0, '262360'), -- SI:7 Operative - 262360 - Stealth
(@CGUID+238, 0, 0, 131072, 1, 0, 0, 0, 0, '262360'), -- SI:7 Operative - 262360 - Stealth
(@CGUID+239, 0, 0, 0, 0, 0, 0, 0, 0, '261780'), -- Bilgewater Laborer - 261780 - Carrying Crate
(@CGUID+240, 0, 0, 131072, 1, 0, 0, 0, 0, '262360'), -- SI:7 Operative - 262360 - Stealth
(@CGUID+241, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+242, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Bilgewater Laborer
(@CGUID+243, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Inactive Shredder
(@CGUID+244, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+245, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SI:7 Operative
(@CGUID+246, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Mook
(@CGUID+247, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+248, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+249, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Inactive Shredder

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+250, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- SI:7 Operative
(@CGUID+251, 0, 0, 131072, 1, 0, 0, 0, 0, '262360'), -- SI:7 Operative - 262360 - Stealth
(@CGUID+252, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Inactive Shredder
(@CGUID+253, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+254, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+255, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+256, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+257, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+258, 0, 0, 131072, 1, 0, 0, 0, 0, '262360'), -- SI:7 Operative - 262360 - Stealth
(@CGUID+259, 0, 0, 131072, 1, 0, 0, 0, 0, '262360'), -- SI:7 Operative - 262360 - Stealth
(@CGUID+260, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+261, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+262, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+263, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Prospector
(@CGUID+264, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+265, 0, 0, 131072, 1, 0, 0, 0, 0, '262360'), -- SI:7 Operative - 262360 - Stealth
(@CGUID+266, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- Bilgewater Prospector - 46598 - Ride Vehicle Hardcoded
(@CGUID+267, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bilgewater Shredder
(@CGUID+268, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+269, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+270, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+271, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Infused Crag
(@CGUID+272, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+273, 0, 0, 0, 1, 0, 0, 0, 0, '270813'), -- Infused Bedrock - 270813 - Azerite Empowered
(@CGUID+274, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+275, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+276, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+277, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+278, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+279, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+280, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Minor Azerite Infused Elemental
(@CGUID+281, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+282, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+283, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+284, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+285, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+286, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+287, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+288, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+289, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+290, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+291, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+292, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+293, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+294, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+295, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+296, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+297, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+298, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+299, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+300, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+301, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+302, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+303, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+304, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+305, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+306, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+307, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+308, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+309, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+310, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+311, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+312, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+313, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+314, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+315, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+316, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Highlord Demitrian
(@CGUID+317, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+318, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+319, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+320, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+321, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+322, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+323, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+324, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+325, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+326, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+327, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+328, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+329, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+330, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+331, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+332, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+333, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+334, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+335, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+336, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+337, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+338, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+339, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+340, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+341, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+342, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+343, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+344, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+345, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+346, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+347, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+348, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+349, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+350, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+351, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+352, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+353, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+354, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+355, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+356, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+357, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+358, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+359, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+360, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+361, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Sentinel
(@CGUID+362, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+363, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+364, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+365, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+366, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+367, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+368, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+369, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+370, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+371, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+372, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+373, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+374, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+375, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+376, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+377, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+378, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+379, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+380, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+381, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+382, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+383, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+384, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+385, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+386, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+387, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+388, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+389, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+390, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+391, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+392, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+393, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+394, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+395, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+396, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Sentinel
(@CGUID+397, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+398, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+399, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+400, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+401, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Xaarshej
(@CGUID+402, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+403, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+404, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+405, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+406, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+407, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+408, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+409, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+410, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+411, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+412, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+413, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+414, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+415, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Sentinel
(@CGUID+416, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+417, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+418, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+419, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+420, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+421, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+422, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+423, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+424, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+425, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+426, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+427, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+428, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+429, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+430, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+431, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+432, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+433, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+434, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Sentinel
(@CGUID+435, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+436, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+437, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+438, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+439, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+440, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+441, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+442, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+443, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+444, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+445, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+446, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+447, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+448, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+449, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+450, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Silithid Spitfire
(@CGUID+451, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+452, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+453, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Sentinel
(@CGUID+454, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+455, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+456, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+457, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+458, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+459, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+460, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Drone
(@CGUID+461, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+462, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+463, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Sentinel
(@CGUID+464, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silithid Broodling
(@CGUID+465, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+466, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+467, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+468, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+469, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+470, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+471, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+472, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+473, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+474, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+475, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+476, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+477, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+478, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+479, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+480, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+481, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+482, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+483, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+484, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+485, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+486, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+487, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+488, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+489, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+490, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- -Unknown-
(@CGUID+491, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+492, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(@CGUID+493, 0, 0, 0, 1, 0, 0, 0, 0, '51733'), -- Twilight Ritualist - 51733 - Shadow Channelling
(@CGUID+494, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Twilight Ritualist
(@CGUID+495, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+496, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Twilight Ritualist
(@CGUID+497, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+498, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Twilight Earthbreaker
(@CGUID+499, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Scorpid Skitterer

INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+500, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+501, 0, 0, 0, 1, 0, 0, 0, 0, '51733'), -- Twilight Ritualist - 51733 - Shadow Channelling
(@CGUID+502, 0, 0, 0, 1, 0, 0, 0, 0, '51733'), -- Twilight Ritualist - 51733 - Shadow Channelling
(@CGUID+503, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Twilight Survivor
(@CGUID+504, 0, 0, 0, 1, 0, 0, 0, 0, '51733'), -- Twilight Ritualist - 51733 - Shadow Channelling
(@CGUID+505, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Twilight Earthbreaker
(@CGUID+506, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Twilight Survivor
(@CGUID+507, 0, 0, 0, 1, 0, 0, 0, 0, '51733'), -- Twilight Ritualist - 51733 - Shadow Channelling
(@CGUID+508, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Twilight Ritualist
(@CGUID+509, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+510, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+511, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Stonelash Pincer
(@CGUID+512, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+513, 0, 0, 0, 1, 0, 0, 0, 0, '51733'), -- Twilight Ritualist - 51733 - Shadow Channelling
(@CGUID+514, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(@CGUID+515, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+516, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Wasteland Crusher
(@CGUID+517, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Twilight Survivor
(@CGUID+518, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Ogmot the Mad
(@CGUID+519, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Twilight Survivor
(@CGUID+520, 0, 0, 0, 1, 0, 0, 0, 0, '51733'), -- Twilight Ritualist - 51733 - Shadow Channelling
(@CGUID+521, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+522, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sand Stormer
(@CGUID+523, 0, 0, 33554432, 1, 0, 0, 0, 0, '132482'), -- Rhonormu - 132482 - Aura Tall - Yellow
(@CGUID+524, 0, 0, 0, 1, 0, 0, 0, 0, ''); -- Stonelash Pincer

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+125;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 281075, 1, 9310, 0, '0', '0', 0, -7082.708, 575.1285, -89.63243, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+1, 281075, 1, 9310, 0, '0', '0', 0, -7082.444, 573.7639, -89.39757, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+2, 281075, 1, 9310, 0, '0', '0', 0, -7083.219, 574.4774, -89.40452, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+3, 281075, 1, 9310, 0, '0', '0', 0, -7081.934, 574.4149, -89.61964, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+4, 187852, 1, 9310, 9474, '0', '0', 0, -7414.071, 288.6528, -2.908523, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Bonfire (Area: Southwind Village - Difficulty: Normal)
(@OGUID+5, 281074, 1, 9310, 9474, '0', '0', 0, -6962.825, 512.408, -92.80399, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: Southwind Village - Difficulty: Normal)
(@OGUID+6, 281074, 1, 9310, 9474, '0', '0', 0, -6962.104, 512.5555, -92.80298, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: Southwind Village - Difficulty: Normal)
(@OGUID+7, 281074, 1, 9310, 9474, '0', '0', 0, -6962.472, 511.8021, -92.80431, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: Southwind Village - Difficulty: Normal)
(@OGUID+8, 281077, 1, 9310, 9474, '0', '0', 0, -7009.486, 649.9358, -98.84048, 4.563384, -0.6383252, 0.4202366, 0.582653, 0.2765096, 120, 255, 1, 28153), -- Pipe (Area: Southwind Village - Difficulty: Normal)
(@OGUID+9, 281074, 1, 9310, 9474, '0', '0', 0, -6948.972, 547.066, -93.72791, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: Southwind Village - Difficulty: Normal)
(@OGUID+10, 281075, 1, 9310, 9474, '0', '0', 0, -7006.538, 643.1476, -98.84048, 0.849806, 0, 0, 0.4122324, 0.9110787, 120, 255, 1, 28153), -- Oil Drum (Area: Southwind Village - Difficulty: Normal)
(@OGUID+11, 281074, 1, 9310, 9474, '0', '0', 0, -6949.325, 547.6702, -93.72569, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: Southwind Village - Difficulty: Normal)
(@OGUID+12, 281076, 1, 9310, 9474, '0', '0', 0, -7007.976, 652.1962, -98.84048, 5.460248, 0.6175151, 0.291728, -0.5878468, 0.4335966, 120, 255, 1, 28153), -- Pipe (Area: Southwind Village - Difficulty: Normal)
(@OGUID+13, 281076, 1, 9310, 9474, '0', '0', 0, -6996.749, 638.993, -98.72914, 0.2333222, 0.3863721, 0.563158, -0.2892561, 0.6707463, 120, 255, 1, 28153), -- Pipe (Area: Southwind Village - Difficulty: Normal)
(@OGUID+14, 281075, 1, 9310, 9474, '0', '0', 0, -7004.021, 652.3889, -98.84048, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: Southwind Village - Difficulty: Normal)
(@OGUID+15, 281075, 1, 9310, 9474, '0', '0', 0, -7003.51, 653.0417, -98.84048, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: Southwind Village - Difficulty: Normal)
(@OGUID+16, 281074, 1, 9310, 9474, '0', '0', 0, -6948.604, 547.8195, -93.7309, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: Southwind Village - Difficulty: Normal)
(@OGUID+17, 281075, 1, 9310, 0, '0', '0', 0, -6900.606, 610.4462, -97.96912, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+18, 281074, 1, 9310, 0, '0', '0', 0, -6908.887, 607.1771, -97.22978, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+19, 281074, 1, 9310, 0, '0', '0', 0, -6904.74, 612.592, -97.63871, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+20, 281074, 1, 9310, 0, '0', '0', 0, -6875.399, 508.3993, -93.69618, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+21, 281074, 1, 9310, 0, '0', '0', 0, -6875.752, 509.0052, -93.70928, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+22, 281074, 1, 9310, 0, '0', '0', 0, -6875.031, 509.1528, -93.69965, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+23, 281075, 1, 9310, 0, '0', '0', 0, -6851.901, 531.9688, -92.80729, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+24, 280720, 1, 9310, 0, '0', '0', 0, -7084.575, 571.7621, -88.40055, 1.336027, 0, 0, 0.6194277, 0.7850537, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+25, 281072, 1, 9310, 0, '0', '0', 0, -6825.028, 477.1389, -92.83506, 5.960216, 0, 0, -0.1607838, 0.9869897, 120, 255, 1, 28153), -- Oil Pump (Area: 0 - Difficulty: Normal)
(@OGUID+26, 281075, 1, 9310, 0, '0', '0', 0, -6828.425, 474.9653, -93.23674, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+27, 280720, 1, 9310, 0, '0', '0', 0, -7084.641, 571.3854, -87.62797, 0.4506849, 0, 0, 0.2234402, 0.9747177, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+28, 280720, 1, 9310, 0, '0', '0', 0, -7085.408, 571.6927, -88.32465, 0.7094408, 0, 0, 0.3473282, 0.9377436, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+29, 281075, 1, 9310, 0, '0', '0', 0, -6828.99, 475.5504, -93.16058, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+30, 280720, 1, 9310, 0, '0', '0', 0, -7084.713, 570.8871, -88.18924, 1.309931, 0, 0, 0.6091318, 0.793069, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+31, 281075, 1, 9310, 0, '0', '0', 0, -6851.637, 530.6042, -92.88175, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+32, 281075, 1, 9310, 0, '0', '0', 0, -6852.412, 531.3177, -92.90104, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+33, 281075, 1, 9310, 0, '0', '0', 0, -6851.127, 531.2552, -92.79688, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+34, 281075, 1, 9310, 0, '0', '0', 0, -6860.259, 682.8559, -89.92451, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+35, 281075, 1, 9310, 0, '0', '0', 0, -6859.484, 682.1424, -89.89928, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+36, 281074, 1, 9310, 0, '0', '0', 0, -6857.561, 682.3924, -89.8462, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+37, 280720, 1, 9310, 0, '0', '0', 0, -6937.309, 486.599, -93.26389, 0.7094408, 0, 0, 0.3473282, 0.9377436, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+38, 281076, 1, 9310, 0, '0', '0', 0, -6856.984, 682.3663, -89.80804, 3.10971, -0.5071335, 0.4574337, 0.6266155, 0.3753971, 120, 255, 1, 28153), -- Pipe (Area: 0 - Difficulty: Normal)
(@OGUID+39, 281077, 1, 9310, 0, '0', '0', 0, -6857.528, 685.0313, -89.52522, 5.115731, -0.7626619, 0.256588, 0.5936823, 0.007122047, 120, 255, 1, 28153), -- Pipe (Area: 0 - Difficulty: Normal)
(@OGUID+40, 281074, 1, 9310, 0, '0', '0', 0, -6858.281, 682.2448, -89.80035, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+41, 281075, 1, 9310, 0, '0', '0', 0, -6858.974, 682.7934, -89.80035, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+42, 280720, 1, 9310, 0, '0', '0', 0, -6936.542, 486.2917, -92.78776, 0.4506849, 0, 0, 0.2234402, 0.9747177, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+43, 280720, 1, 9310, 0, '0', '0', 0, -6936.476, 486.6684, -93.33681, 1.336027, 0, 0, 0.6194277, 0.7850537, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+44, 281075, 1, 9310, 0, '0', '0', 0, -6859.749, 683.507, -89.88194, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+45, 281074, 1, 9310, 0, '0', '0', 0, -6857.929, 681.6389, -89.88387, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+46, 280720, 1, 9310, 0, '0', '0', 0, -6935.601, 485.5434, -93.39584, 0.9142306, 0, 0, 0.4413614, 0.8973294, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+47, 280720, 1, 9310, 0, '0', '0', 0, -6936.615, 485.7934, -93.31495, 1.309931, 0, 0, 0.6091318, 0.793069, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+48, 180474, 1, 9310, 0, '0', '0', 0, -6330.928, -3.34761, 6.551298, 1.954769, 0, 0, 0.8290377, 0.5591928, 120, 255, 1, 28153), -- Brazier (Area: 0 - Difficulty: Normal)
(@OGUID+49, 180474, 1, 9310, 0, '0', '0', 0, -6330.928, -3.34761, 6.55303, 1.954769, 0, 0, 0.8290377, 0.5591928, 120, 255, 1, 28153), -- Brazier (Area: 0 - Difficulty: Normal)
(@OGUID+50, 180474, 1, 9310, 0, '0', '0', 0, -6330.928, -3.34761, 6.551298, 1.954769, 0, 0, 0.8290377, 0.5591928, 120, 255, 1, 28153), -- Brazier (Area: 0 - Difficulty: Normal)
(@OGUID+51, 180473, 1, 9310, 0, '0', '0', 0, -6317.038, 17.19212, 6.071098, 1.518436, 0, 0, 0.6883545, 0.7253745, 120, 255, 1, 28153), -- Brazier (Area: 0 - Difficulty: Normal)
(@OGUID+52, 180475, 1, 9310, 0, '0', '0', 0, -6308.316, 5.307922, 6.335299, 2.4969, -0.06923532, -0.06627846, 0.9453268, 0.3117224, 120, 255, 1, 28153), -- Brazier (Area: 0 - Difficulty: Normal)
(@OGUID+53, 180473, 1, 9310, 0, '0', '0', 0, -6317.038, 17.19212, 6.07283, 1.518436, 0, 0, 0.6883545, 0.7253745, 120, 255, 1, 28153), -- Brazier (Area: 0 - Difficulty: Normal)
(@OGUID+54, 180473, 1, 9310, 0, '0', '0', 0, -6317.038, 17.19212, 6.071098, 1.518436, 0, 0, 0.6883545, 0.7253745, 120, 255, 1, 28153), -- Brazier (Area: 0 - Difficulty: Normal)
(@OGUID+55, 180475, 1, 9310, 0, '0', '0', 0, -6308.316, 5.307922, 6.33703, 2.4969, -0.06923532, -0.06627846, 0.9453268, 0.3117224, 120, 255, 1, 28153), -- Brazier (Area: 0 - Difficulty: Normal)
(@OGUID+56, 180475, 1, 9310, 0, '0', '0', 0, -6308.316, 5.307922, 6.335299, 2.4969, -0.06923532, -0.06627846, 0.9453268, 0.3117224, 120, 255, 1, 28153), -- Brazier (Area: 0 - Difficulty: Normal)
(@OGUID+57, 232234, 1, 9310, 9473, '0', '0', 0, -6354.548, 169.417, 7.192785, 4.490471, 0.008128643, -0.002209663, -0.7810507, 0.6244108, 120, 255, 1, 28153), -- Woodbench (Area: Staghelm Point - Difficulty: Normal)
(@OGUID+58, 232235, 1, 9310, 9473, '0', '0', 0, -6354.104, 165.0079, 7.170113, 1.251508, -0.001811504, -0.008226395, 0.585659, 0.8105137, 120, 255, 1, 28153), -- Woodbench (Area: Staghelm Point - Difficulty: Normal)
(@OGUID+59, 281420, 1, 9310, 9473, '0', '0', 0, -6388.118, 183.5556, 7.199183, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Campfire (Area: Staghelm Point - Difficulty: Normal)
(@OGUID+60, 232224, 1, 9310, 9473, '0', '0', 0, -6358.425, 165.9913, 7.109894, 1.302302, -0.002019882, -0.008177757, 0.6060534, 0.7953794, 120, 255, 1, 28153), -- Woodbench (Area: Staghelm Point - Difficulty: Normal)
(@OGUID+61, 232225, 1, 9310, 9473, '0', '0', 0, -6358.09, 170.672, 7.146444, 4.490551, 0.008128643, -0.002209663, -0.7810259, 0.6244419, 120, 255, 1, 28153), -- Woodbench (Area: Staghelm Point - Difficulty: Normal)
(@OGUID+62, 281075, 1, 9310, 0, '0', '0', 0, -6774.804, 673.125, -84.30729, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+63, 281075, 1, 9310, 0, '0', '0', 0, -6775.314, 672.4739, -84.30958, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+64, 281077, 1, 9310, 0, '0', '0', 0, -6776.863, 696.0087, -84.03072, 0.5973819, 0.6407676, 0.416503, -0.4867735, 0.4230765, 120, 255, 1, 28153), -- Pipe (Area: 0 - Difficulty: Normal)
(@OGUID+65, 281076, 1, 9310, 0, '0', '0', 0, -6764.283, 720.3143, -83.96006, 3.10971, -0.5071335, 0.4574337, 0.6266155, 0.3753971, 120, 255, 1, 28153), -- Pipe (Area: 0 - Difficulty: Normal)
(@OGUID+66, 281075, 1, 9310, 0, '0', '0', 0, -6767.818, 718.3229, -84.26387, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+67, 281075, 1, 9310, 0, '0', '0', 0, -6768.328, 717.6719, -84.26385, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+68, 281072, 1, 9310, 0, '0', '0', 0, -6681.162, 838.1146, -83.85331, 4.667041, 0, 0, -0.7229567, 0.6908934, 120, 255, 1, 28153), -- Oil Pump (Area: 0 - Difficulty: Normal)
(@OGUID+69, 281073, 1, 9310, 0, '0', '0', 0, -6777.832, 723.5746, -79.70141, 5.901289, 0, 0, -0.1897898, 0.9818248, 120, 255, 1, 28153), -- Smoke Stack (Area: 0 - Difficulty: Normal)
(@OGUID+70, 281075, 1, 9310, 0, '0', '0', 0, -6780.297, 725.3038, -84.26362, 6.08441, 0, 0, -0.09922409, 0.9950651, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+71, 281071, 1, 9310, 0, '0', '0', 0, -6776.34, 725.2726, -84.26373, 2.54799, 0, 0, 0.9562769, 0.2924628, 120, 255, 1, 28153), -- Goblin Battery (Area: 0 - Difficulty: Normal)
(@OGUID+72, 281072, 1, 9310, 0, '0', '0', 0, -6770.285, 721.2327, -84.26384, 5.66478, 0, 0, -0.3042994, 0.9525765, 120, 255, 1, 28153), -- Oil Pump (Area: 0 - Difficulty: Normal)
(@OGUID+73, 281076, 1, 9310, 0, '0', '0', 0, -6781.566, 721.6163, -84.17661, 4.165775, -0.6685467, 0.139555, 0.7304087, 0.008541433, 120, 255, 1, 28153), -- Pipe (Area: 0 - Difficulty: Normal)
(@OGUID+74, 281077, 1, 9310, 0, '0', '0', 0, -6764.828, 722.9774, -84.07285, 2.212851, 0.1418433, 0.7509584, -0.03066158, 0.6442063, 120, 255, 1, 28153), -- Pipe (Area: 0 - Difficulty: Normal)
(@OGUID+75, 281075, 1, 9310, 0, '0', '0', 0, -6809.503, 704.4323, -84.49785, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+76, 281076, 1, 9310, 0, '0', '0', 0, -6808.12, 702.1702, -84.30856, 4.165775, -0.6685467, 0.139555, 0.7304087, 0.008541433, 120, 255, 1, 28153), -- Pipe (Area: 0 - Difficulty: Normal)
(@OGUID+77, 281075, 1, 9310, 0, '0', '0', 0, -6810.278, 705.1458, -84.58796, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+78, 281075, 1, 9310, 0, '0', '0', 0, -6808.993, 705.0833, -84.34375, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+79, 281075, 1, 9310, 0, '0', '0', 0, -6809.768, 705.7969, -84.42709, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+80, 281075, 1, 9310, 0, '0', '0', 0, -6817.931, 682.9514, -92.66575, 5.361387, 0, 0, -0.4447536, 0.8956529, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+81, 281075, 1, 9310, 0, '0', '0', 0, -6817.101, 682.9305, -92.65968, 5.361387, 0, 0, -0.4447536, 0.8956529, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+82, 281078, 1, 9310, 0, '0', '0', 0, -6816.069, 690.1893, -92.18214, 4.918148, 0.6525202, -0.2732248, 0.6521063, 0.2726224, 120, 255, 1, 28153), -- Pipe (Area: 0 - Difficulty: Normal)
(@OGUID+83, 280720, 1, 9310, 0, '0', '0', 0, -6616.077, 692.5417, -53.52299, 3.818847, 0, 0, -0.9432116, 0.3321927, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+84, 280720, 1, 9310, 0, '0', '0', 0, -6617.165, 693.0504, -54.05515, 4.282392, 0, 0, -0.8416853, 0.5399684, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+85, 281074, 1, 9310, 0, '0', '0', 0, -6774.938, 775.8906, -90.99788, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+86, 281075, 1, 9310, 0, '0', '0', 0, -6823.156, 714.9688, -92.69318, 0.534937, 0, 0, 0.2642908, 0.964443, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+87, 281074, 1, 9310, 0, '0', '0', 0, -6820.559, 690.3316, -92.67723, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+88, 281074, 1, 9310, 0, '0', '0', 0, -6775.658, 775.743, -90.99781, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+89, 280720, 1, 9310, 0, '0', '0', 0, -6616.115, 693.0364, -54.0505, 4.678091, 0, 0, -0.7191286, 0.694877, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+90, 280720, 1, 9310, 0, '0', '0', 0, -6636.559, 667.7465, -54.56835, 1.336027, 0, 0, 0.6194277, 0.7850537, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+91, 281074, 1, 9310, 0, '0', '0', 0, -6775.306, 775.1371, -90.99778, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+92, 280720, 1, 9310, 0, '0', '0', 0, -6616.056, 692.1476, -54.05152, 4.704186, 0, 0, -0.710001, 0.7042007, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+93, 281074, 1, 9310, 0, '0', '0', 0, -6820.912, 690.9375, -92.68243, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+94, 281075, 1, 9310, 0, '0', '0', 0, -6824.194, 718.7483, -92.70067, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+95, 281075, 1, 9310, 0, '0', '0', 0, -6830.696, 697.2778, -92.69633, 0.534937, 0, 0, 0.2642908, 0.964443, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+96, 281074, 1, 9310, 0, '0', '0', 0, -6820.191, 691.0851, -92.66734, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Fuel Can (Area: 0 - Difficulty: Normal)
(@OGUID+97, 281075, 1, 9310, 0, '0', '0', 0, -6823.684, 719.3993, -92.70045, 0, 0, 0, 0, 1, 120, 255, 1, 28153), -- Oil Drum (Area: 0 - Difficulty: Normal)
(@OGUID+98, 280720, 1, 9310, 0, '0', '0', 0, -6614.08, 691.2604, -54.06202, 0.09355141, 0, 0, 0.04675865, 0.9989062, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+99, 280720, 1, 9310, 0, '0', '0', 0, -6637.393, 667.6771, -54.56836, 0.7094408, 0, 0, 0.3473282, 0.9377436, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+100, 280720, 1, 9310, 0, '0', '0', 0, -6636.625, 667.3698, -54.00499, 0.4506849, 0, 0, 0.2234402, 0.9747177, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+101, 280720, 1, 9310, 0, '0', '0', 0, -6636.698, 666.8715, -54.56835, 1.309931, 0, 0, 0.6091318, 0.793069, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+102, 281072, 1, 9310, 0, '0', '0', 0, -6801.365, 783.3924, -99.89594, 5.290906, 0, 0, -0.4760342, 0.8794268, 120, 255, 1, 28153), -- Oil Pump (Area: 0 - Difficulty: Normal)
(@OGUID+103, 280720, 1, 9310, 0, '0', '0', 0, -6615.257, 692.4132, -54.05211, 4.077601, 0, 0, -0.8924704, 0.451106, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+104, 280720, 1, 9310, 0, '0', '0', 0, -6775.936, 673.7344, -84.27778, 1.309931, 0, 0, 0.6091318, 0.793069, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+105, 280720, 1, 9310, 0, '0', '0', 0, -6776.63, 674.5399, -84.27084, 0.7094408, 0, 0, 0.3473282, 0.9377436, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+106, 280720, 1, 9310, 0, '0', '0', 0, -6775.797, 674.6094, -84.27033, 1.336027, 0, 0, 0.6194277, 0.7850537, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+107, 280720, 1, 9310, 0, '0', '0', 0, -6775.863, 674.2327, -83.76853, 0.4506849, 0, 0, 0.2234402, 0.9747177, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+108, 280720, 1, 9310, 0, '0', '0', 0, -6824.241, 717.6129, -92.7002, 5.954091, 0, 0, -0.163806, 0.9864926, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+109, 280720, 1, 9310, 0, '0', '0', 0, -6824.113, 716.7952, -92.13813, 5.695333, 0, 0, -0.289712, 0.9571139, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+110, 280720, 1, 9310, 0, '0', '0', 0, -6823.755, 716.9288, -92.68577, 0.2974901, 0, 0, 0.1481972, 0.9889578, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+111, 280720, 1, 9310, 0, '0', '0', 0, -6830.035, 695.0417, -92.69477, 0.9142306, 0, 0, 0.4413614, 0.8973294, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+112, 280720, 1, 9310, 0, '0', '0', 0, -6824.28, 715.6077, -92.69913, 6.158882, 0, 0, -0.06211185, 0.9980692, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+113, 280720, 1, 9310, 0, '0', '0', 0, -6824.578, 716.6059, -92.69444, 0.2713933, 0, 0, 0.1352806, 0.9908074, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+114, 280720, 1, 9310, 0, '0', '0', 0, -6830.91, 696.1667, -92.696, 1.336027, 0, 0, 0.6194277, 0.7850537, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+115, 280720, 1, 9310, 0, '0', '0', 0, -6831.743, 696.0972, -92.69618, 0.7094408, 0, 0, 0.3473282, 0.9377436, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+116, 280720, 1, 9310, 0, '0', '0', 0, -6831.049, 695.2917, -92.69572, 1.309931, 0, 0, 0.6091318, 0.793069, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+117, 280720, 1, 9310, 0, '0', '0', 0, -6830.976, 695.7899, -92.14733, 0.4506849, 0, 0, 0.2234402, 0.9747177, 120, 255, 1, 28153), -- Horde Crate (Area: 0 - Difficulty: Normal)
(@OGUID+118, 180904, 1, 9310, 0, '0', '0', 0, -8138.581, 1525.419, 17.29988, 6.259562, 0, 0, -0.01181126, 0.9999302, 120, 255, 0, 28153), -- Ancient Door (Area: 0 - Difficulty: Normal)
(@OGUID+119, 180904, 1, 9310, 0, '0', '0', 0, -8138.581, 1525.419, 17.29988, 6.259562, 0, 0, -0.01181126, 0.9999302, 120, 255, 0, 28153), -- Ancient Door (Area: 0 - Difficulty: Normal)
(@OGUID+120, 280948, 1, 9310, 0, '0', '0', 0, -7752.149, 1782.134, 5.097941, 0.1257733, 0, 0, 0.06284523, 0.9980233, 120, 255, 1, 28153), -- Twilight Outhouse (Area: 0 - Difficulty: Normal)
(@OGUID+121, 267179, 1, 9310, 9475, '0', '0', 0, -8056.868, 1641.622, 24.33679, 4.678658, 0, 0, -0.7189312, 0.6950812, 120, 255, 1, 28153), -- Alliance Banner (Area: Twilight Outpost - Difficulty: Normal)
(@OGUID+122, 267179, 1, 9310, 9475, '0', '0', 0, -8080.682, 1641.852, 24.33722, 4.636778, 0, 0, -0.7333279, 0.6798752, 120, 255, 1, 28153), -- Alliance Banner (Area: Twilight Outpost - Difficulty: Normal)
(@OGUID+123, 268414, 1, 9310, 10030, '0', '0', 0, -8118.078, 1560.155, 29.51556, 6.259391, -0.00352478, -0.01268387, -0.01193905, 0.999842, 120, 255, 1, 28153), -- Alliance Banner (Area: The Scarab Wall - Difficulty: Normal)
(@OGUID+124, 280895, 1, 9310, 10030, '0', '0', 0, -8073.774, 1634.17, 24.34326, 5.655492, 0, 0, -0.3087196, 0.9511531, 120, 255, 1, 28153), -- Skeleton (Area: The Scarab Wall - Difficulty: Normal)
(@OGUID+125, 268414, 1, 9310, 10030, '0', '0', 0, -8119.83, 1489.87, 28.61662, 6.257213, -0.001005173, -0.01316643, -0.01299572, 0.9998283, 120, 255, 1, 28153); -- Alliance Banner (Area: The Scarab Wall - Difficulty: Normal)

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+119;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`) VALUES
(@OGUID+48, 0, 0, 0.8457279, 0.5336145), -- Brazier
(@OGUID+49, 0, 0, 0.8457279, 0.5336145), -- Brazier
(@OGUID+50, 0, 0, 0.8457279, 0.5336145), -- Brazier
(@OGUID+51, 0, 0, 0.8457279, 0.5336145), -- Brazier
(@OGUID+52, 0, 0, 0.8457279, 0.5336145), -- Brazier
(@OGUID+53, 0, 0, 0.8457279, 0.5336145), -- Brazier
(@OGUID+54, 0, 0, 0.8457279, 0.5336145), -- Brazier
(@OGUID+55, 0, 0, 0.8457279, 0.5336145), -- Brazier
(@OGUID+56, 0, 0, 0.8457279, 0.5336145), -- Brazier
(@OGUID+57, -0.007245169, -0.004297485, 0.9919854, 0.1260714), -- Woodbench
(@OGUID+58, -0.007245169, -0.004297485, 0.9919854, 0.1260714), -- Woodbench
(@OGUID+60, -0.007245169, -0.004297485, 0.9919854, 0.1260714), -- Woodbench
(@OGUID+61, -0.007245169, -0.004297485, 0.9919854, 0.1260714), -- Woodbench
(@OGUID+118, 0, 0, 1, -0.00000004371139), -- Ancient Door
(@OGUID+119, 0, 0, 1, -0.00000004371139); -- Ancient Door

DELETE FROM `spell_target_position` WHERE (`ID`=271210 AND `EffectIndex`=0);
INSERT INTO `spell_target_position` (`ID`, `EffectIndex`, `MapID`, `PositionX`, `PositionY`, `PositionZ`, `VerifiedBuild`) VALUES
(271210, 0, 1643, 1143.6, -525.6, 17.5, 28153); -- Spell: Portal: Kul Tiras Efffect: 252 (SPELL_EFFECT_TELEPORT_UNITS)


DELETE FROM `creature_template_addon` WHERE `entry` IN (132580 /*132580 (Ssinkrix)*/, 132886 /*132886 (Twilight Hermit)*/, 15454 /*15454 (Anachronos Quest Trigger Invisible)*/, 49746 /*49746 (Scarab Hatchling)*/, 133263 /*133263 (Rhonormu) - Aura Tall - Yellow*/, 132591 /*132591 (Ogmot the Mad)*/, 131908 /*131908 (Twilight Survivor)*/, 132199 /*132199 (Twilight Earthbreaker)*/, 131907 /*131907 (Twilight Ritualist) - Shadow Channelling*/, 132584 /*132584 (Xaarshej)*/, 131892 /*131892 (Silithid Sentinel)*/, 131895 /*131895 (Silithid Spitfire)*/, 131893 /*131893 (Silithid Drone)*/, 131903 /*131903 (Silithid Broodling)*/, 131943 /*131943 (Highlord Demitrian)*/, 131909 /*131909 (Wasteland Crusher)*/, 132164 /*132164 (Bilgewater Shredder)*/, 131957 /*131957 (SI:7 Operative) - Stealth*/, 132042 /*132042 (Bilgewater Mook)*/, 133022 /*133022 (Inactive Shredder)*/, 132055 /*132055 (Bilgewater Prospector)*/, 132062 /*132062 (Bilgewater Laborer)*/, 133755 /*133755 (Alliance Guard)*/, 131947 /*131947 (Clifford Bentham)*/, 130030 /*130030 (Kelsey Steelspark)*/, 132995 /*132995 (Laurette Royston)*/, 131963 /*131963 (Nolan Speed)*/, 131946 /*131946 (Alliance Guard)*/, 132192 /*132192 (Khargus Stonemantle)*/, 132606 /*132606 (Tammy Tinkspinner)*/, 131952 /*131952 (Edmund Hackney)*/, 132190 /*132190 (Alliance Worker)*/, 128607 /*128607 (Zidormi) - Aura Tall - Yellow*/, 131906 /*131906 (Sand Stormer)*/, 132140 /*132140 (Urok Windcleaver)*/, 132147 /*132147 (Grol Warblade)*/, 132139 /*132139 (Hagras Wartaker)*/, 132045 /*132045 (Gizmax Greasebolt)*/, 132142 /*132142 (Bilgewater Mechanic)*/, 132040 /*132040 (Pixni Rustbomb)*/, 132141 /*132141 (Bilgewater Worker)*/, 132138 /*132138 (Gaula Axefury)*/, 132064 /*132064 (Horde Grunt)*/, 131904 /*Spiky Lizard*/, 131890 /*131890*/, 131896 /*Scorpid Skitterer*/, 137906 /*137906 (Infused Bedrock) - Azerite Empowered*/, 137907 /*137907 (Infused Crag)*/, 137904 /*137904 (Minor Azerite Infused Elemental)*/, 131897 /*131897 (Stonelash Pincer)*/, 132526 /*132526*/, 137905 /*137905 - Azerite Explosion*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(132580, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132580 (Ssinkrix)
(132886, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132886 (Twilight Hermit)
(15454, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 15454 (Anachronos Quest Trigger Invisible)
(49746, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 49746 (Scarab Hatchling)
(133263, 0, 0, 33554432, 1, 0, 0, 0, 0, '132482'), -- 133263 (Rhonormu) - Aura Tall - Yellow
(132591, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132591 (Ogmot the Mad)
(131908, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131908 (Twilight Survivor)
(132199, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132199 (Twilight Earthbreaker)
(131907, 0, 0, 0, 1, 0, 0, 0, 0, '51733'), -- 131907 (Twilight Ritualist) - Shadow Channelling
(132584, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132584 (Xaarshej)
(131892, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131892 (Silithid Sentinel)
(131895, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 131895 (Silithid Spitfire)
(131893, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131893 (Silithid Drone)
(131903, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131903 (Silithid Broodling)
(131943, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131943 (Highlord Demitrian)
(131909, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131909 (Wasteland Crusher)
(132164, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132164 (Bilgewater Shredder)
(131957, 0, 0, 131072, 1, 0, 0, 0, 0, '262360'), -- 131957 (SI:7 Operative) - Stealth
(132042, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132042 (Bilgewater Mook)
(133022, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 133022 (Inactive Shredder)
(132055, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132055 (Bilgewater Prospector)
(132062, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 132062 (Bilgewater Laborer)
(133755, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 133755 (Alliance Guard)
(131947, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131947 (Clifford Bentham)
(130030, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 130030 (Kelsey Steelspark)
(132995, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132995 (Laurette Royston)
(131963, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131963 (Nolan Speed)
(131946, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 131946 (Alliance Guard)
(132192, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132192 (Khargus Stonemantle)
(132606, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132606 (Tammy Tinkspinner)
(131952, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 131952 (Edmund Hackney)
(132190, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132190 (Alliance Worker)
(128607, 0, 0, 33554432, 1, 0, 0, 0, 0, '132482'), -- 128607 (Zidormi) - Aura Tall - Yellow
(131906, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131906 (Sand Stormer)
(132140, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132140 (Urok Windcleaver)
(132147, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132147 (Grol Warblade)
(132139, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 132139 (Hagras Wartaker)
(132045, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132045 (Gizmax Greasebolt)
(132142, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132142 (Bilgewater Mechanic)
(132040, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132040 (Pixni Rustbomb)
(132141, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132141 (Bilgewater Worker)
(132138, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 132138 (Gaula Axefury)
(132064, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 132064 (Horde Grunt)
(131904, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Spiky Lizard
(131890, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131890
(131896, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Scorpid Skitterer
(137906, 0, 0, 0, 1, 0, 0, 0, 0, '270813'), -- 137906 (Infused Bedrock) - Azerite Empowered
(137907, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137907 (Infused Crag)
(137904, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 137904 (Minor Azerite Infused Elemental)
(131897, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 131897 (Stonelash Pincer)
(132526, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 132526
(137905, 0, 0, 0, 1, 0, 0, 0, 0, '271753'); -- 137905 - Azerite Explosion

UPDATE `creature_template_addon` SET `bytes2`=1 WHERE `entry`=15801; -- 15801 (GONG BOY DND DNR)

DELETE FROM `creature_template_scaling` WHERE `Entry` IN (132580, 132591, 131908, 132199, 131907, 132584, 131892, 131895, 131893, 131909, 132164, 131957, 132042, 133022, 132055, 132062, 132190, 131906, 132142, 132141, 131890, 137906, 137907, 137904, 131897, 132526, 137905);
INSERT INTO `creature_template_scaling` (`Entry`, `LevelScalingMin`, `LevelScalingMax`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `VerifiedBuild`) VALUES
(132580, 110, 110, 0, 0, 28153),
(132591, 110, 110, 0, 0, 28153),
(131908, 110, 120, 0, 0, 28153),
(132199, 110, 120, 0, 0, 28153),
(131907, 110, 120, 0, 0, 28153),
(132584, 110, 110, 0, 0, 28153),
(131892, 110, 120, 0, 0, 28153),
(131895, 110, 120, 0, 0, 28153),
(131893, 110, 120, 0, 0, 28153),
(131909, 110, 120, 0, 0, 28153),
(132164, 110, 110, 0, 0, 28153),
(131957, 110, 120, 0, 0, 28153),
(132042, 110, 110, 0, 0, 28153),
(133022, 110, 120, 0, 0, 28153),
(132055, 110, 110, 0, 0, 28153),
(132062, 110, 110, 0, 0, 28153),
(132190, 110, 110, 0, 0, 28153),
(131906, 110, 120, 0, 0, 28153),
(132142, 110, 110, 0, 0, 28153),
(132141, 110, 110, 0, 0, 28153),
(131890, 110, 120, 0, 0, 28153),
(137906, 110, 120, 0, 0, 28153),
(137907, 110, 120, 0, 0, 28153),
(137904, 110, 120, 0, 0, 28153),
(131897, 110, 120, 0, 0, 28153),
(132526, 110, 120, 0, 0, 28153),
(137905, 110, 120, 0, 0, 28153);

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (82491, 82812, 82492, 82231, 82210, 82198, 82152, 82199, 82147, 82149, 82151, 82204, 82260, 82197, 82196, 82203, 82206, 82275, 82273, 82144, 82645, 82153, 82282, 82502, 82146, 82276, 82272, 82246, 82256, 82245, 82248, 82252, 82250, 82188, 82251, 82185, 82249, 82247, 82244, 82155, 84157, 82119, 83052);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(82491, 2.521286, 2.55, 0, 28153),
(82812, 0.306, 1.5, 0, 28153),
(82492, 2.521286, 2.55, 0, 28153),
(82231, 1.928042, 1.95, 0, 28153),
(82210, 0.4, 1.2, 0, 28153),
(82198, 0.306, 1.5, 0, 28153),
(82152, 0.306, 1.5, 0, 28153),
(82199, 0.306, 1.5, 0, 28153),
(82147, 0.208, 1.5, 0, 28153),
(82149, 0.347, 1.5, 0, 28153),
(82151, 0.306, 1.5, 0, 28153),
(82204, 0.306, 1.5, 0, 28153),
(82260, 3.225, 6, 0, 28153),
(82197, 0.306, 1.5, 0, 28153),
(82196, 0.306, 1.5, 0, 28153),
(82203, 0.306, 1.5, 0, 28153),
(82206, 0.306, 1.5, 0, 28153),
(82275, 0.306, 1.5, 0, 28153),
(82273, 0.347, 1.5, 0, 28153),
(82144, 0.306, 1.5, 0, 28153),
(82645, 0.208, 1.5, 0, 28153),
(82153, 0.306, 1.5, 0, 28153),
(82282, 0.347, 1.5, 0, 28153),
(82502, 0.3519, 1.725, 0, 28153),
(82146, 0.306, 1.5, 0, 28153),
(82276, 0.208, 1.5, 0, 28153),
(82272, 0.347, 1.5, 0, 28153),
(82246, 0.372, 1.5, 0, 28153),
(82256, 0.372, 1.5, 0, 28153),
(82245, 0.372, 1.5, 0, 28153),
(82248, 0.306, 1.5, 0, 28153),
(82252, 0.306, 1.5, 0, 28153),
(82250, 0.306, 1.5, 0, 28153),
(82188, 0.306, 1.5, 0, 28153),
(82251, 0.306, 1.5, 0, 28153),
(82185, 0.306, 1.5, 0, 28153),
(82249, 0.306, 1.5, 0, 28153),
(82247, 0.306, 1.5, 0, 28153),
(82244, 0.236, 1.5, 0, 28153),
(82155, 6.824797, 7.5, 0, 28153),
(84157, 0.31, 1, 0, 28153),
(82119, 0.75, 1.5, 0, 28153),
(83052, 1.002216, 1.5, 0, 28153);

UPDATE `creature_model_info` SET `BoundingRadius`=0.1713126, `VerifiedBuild`=28153 WHERE `DisplayID`=36594;
UPDATE `creature_model_info` SET `BoundingRadius`=0.1713126, `VerifiedBuild`=28153 WHERE `DisplayID`=36595;
UPDATE `creature_model_info` SET `BoundingRadius`=0.1713126, `VerifiedBuild`=28153 WHERE `DisplayID`=35112;
UPDATE `creature_model_info` SET `BoundingRadius`=0.1713126, `VerifiedBuild`=28153 WHERE `DisplayID`=35113;
UPDATE `creature_model_info` SET `BoundingRadius`=1.715799, `CombatReach`=3, `VerifiedBuild`=28153 WHERE `DisplayID`=53683;
UPDATE `creature_model_info` SET `BoundingRadius`=1.77, `CombatReach`=1.5, `VerifiedBuild`=28153 WHERE `DisplayID`=37547;
UPDATE `creature_model_info` SET `BoundingRadius`=0.9, `CombatReach`=1.5, `VerifiedBuild`=28153 WHERE `DisplayID`=30995;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=1.5, `VerifiedBuild`=28153 WHERE `DisplayID`=47677;
UPDATE `creature_model_info` SET `BoundingRadius`=1.317242, `CombatReach`=1.61, `VerifiedBuild`=28153 WHERE `DisplayID`=69809;
UPDATE `creature_model_info` SET `BoundingRadius`=0.31, `CombatReach`=1.5, `VerifiedBuild`=28153 WHERE `DisplayID`=42280;

DELETE FROM `npc_vendor` WHERE (`entry`=132139 AND `item`=12162 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132139 AND `item`=66101 AND `ExtendedCost`=3314 AND `type`=1) OR (`entry`=132139 AND `item`=66130 AND `ExtendedCost`=3314 AND `type`=1) OR (`entry`=132139 AND `item`=66131 AND `ExtendedCost`=3314 AND `type`=1) OR (`entry`=132139 AND `item`=66132 AND `ExtendedCost`=3314 AND `type`=1) OR (`entry`=132139 AND `item`=66100 AND `ExtendedCost`=3314 AND `type`=1) OR (`entry`=132139 AND `item`=66122 AND `ExtendedCost`=3314 AND `type`=1) OR (`entry`=132139 AND `item`=66123 AND `ExtendedCost`=3314 AND `type`=1) OR (`entry`=132139 AND `item`=66124 AND `ExtendedCost`=3314 AND `type`=1) OR (`entry`=132139 AND `item`=66129 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66116 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66110 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66114 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66112 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66115 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66121 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66128 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66108 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66104 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66111 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66106 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66113 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=67606 AND `ExtendedCost`=3314 AND `type`=1) OR (`entry`=132139 AND `item`=67603 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66120 AND `ExtendedCost`=3313 AND `type`=1) OR (`entry`=132139 AND `item`=66127 AND `ExtendedCost`=3312 AND `type`=1) OR (`entry`=132139 AND `item`=66109 AND `ExtendedCost`=3312 AND `type`=1) OR (`entry`=132139 AND `item`=66105 AND `ExtendedCost`=3312 AND `type`=1) OR (`entry`=132139 AND `item`=66107 AND `ExtendedCost`=3312 AND `type`=1) OR (`entry`=132139 AND `item`=66119 AND `ExtendedCost`=3312 AND `type`=1) OR (`entry`=132139 AND `item`=66103 AND `ExtendedCost`=3312 AND `type`=1) OR (`entry`=132139 AND `item`=66126 AND `ExtendedCost`=3312 AND `type`=1) OR (`entry`=132139 AND `item`=66125 AND `ExtendedCost`=3312 AND `type`=1) OR (`entry`=132139 AND `item`=66118 AND `ExtendedCost`=3312 AND `type`=1) OR (`entry`=132139 AND `item`=66117 AND `ExtendedCost`=3312 AND `type`=1) OR (`entry`=132139 AND `item`=3857 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132139 AND `item`=18567 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132139 AND `item`=160298 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132139 AND `item`=3466 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132139 AND `item`=2880 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132139 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132139 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=81918 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=81917 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=58269 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=58268 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=35953 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=33454 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=27854 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=8952 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=4599 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=3771 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=3770 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=2287 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=132138 AND `item`=117 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=130216 AND `item`=160544 AND `ExtendedCost`=6306 AND `type`=1) OR (`entry`=130216 AND `item`=163515 AND `ExtendedCost`=6430 AND `type`=1) OR (`entry`=130216 AND `item`=163555 AND `ExtendedCost`=6424 AND `type`=1) OR (`entry`=130216 AND `item`=161563 AND `ExtendedCost`=6312 AND `type`=1) OR (`entry`=130216 AND `item`=161560 AND `ExtendedCost`=6312 AND `type`=1) OR (`entry`=130216 AND `item`=161557 AND `ExtendedCost`=6312 AND `type`=1) OR (`entry`=130216 AND `item`=161555 AND `ExtendedCost`=6312 AND `type`=1) OR (`entry`=130216 AND `item`=160537 AND `ExtendedCost`=6305 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(132139, 87, 12162, 1, 0, 1, 0, 0, 28153), -- Plans: Hardened Iron Shortsword
(132139, 41, 66101, 0, 3314, 1, 0, 0, 28153), -- Plans: Pyrium Shield Spike
(132139, 40, 66130, 0, 3314, 1, 0, 0, 28153), -- Plans: Vicious Ornate Pyrium Legguards
(132139, 39, 66131, 0, 3314, 1, 0, 0, 28153), -- Plans: Vicious Ornate Pyrium Helm
(132139, 38, 66132, 0, 3314, 1, 0, 0, 28153), -- Plans: Vicious Ornate Pyrium Breastplate
(132139, 37, 66100, 0, 3314, 1, 0, 0, 28153), -- Plans: Ebonsteel Belt Buckle
(132139, 36, 66122, 0, 3314, 1, 0, 0, 28153), -- Plans: Vicious Pyrium Legguards
(132139, 35, 66123, 0, 3314, 1, 0, 0, 28153), -- Plans: Vicious Pyrium Helm
(132139, 34, 66124, 0, 3314, 1, 0, 0, 28153), -- Plans: Vicious Pyrium Breastplate
(132139, 33, 66129, 0, 3313, 1, 0, 0, 28153), -- Plans: Vicious Ornate Pyrium Shoulders
(132139, 32, 66116, 0, 3313, 1, 0, 0, 28153), -- Plans: Elementium Stormshield
(132139, 31, 66110, 0, 3313, 1, 0, 0, 28153), -- Plans: Elementium Spellblade
(132139, 30, 66114, 0, 3313, 1, 0, 0, 28153), -- Plans: Elementium Shank
(132139, 29, 66112, 0, 3313, 1, 0, 0, 28153), -- Plans: Elementium Poleaxe
(132139, 28, 66115, 0, 3313, 1, 0, 0, 28153), -- Plans: Elementium Earthguard
(132139, 27, 66121, 0, 3313, 1, 0, 0, 28153), -- Plans: Vicious Pyrium Shoulders
(132139, 26, 66128, 0, 3313, 1, 0, 0, 28153), -- Plans: Vicious Ornate Pyrium Boots
(132139, 25, 66108, 0, 3313, 1, 0, 0, 28153), -- Plans: Light Elementium Chestguard
(132139, 24, 66104, 0, 3313, 1, 0, 0, 28153), -- Plans: Hardened Elementium Hauberk
(132139, 23, 66111, 0, 3313, 1, 0, 0, 28153), -- Plans: Elementium Hammer
(132139, 22, 66106, 0, 3313, 1, 0, 0, 28153), -- Plans: Elementium Deathplate
(132139, 21, 66113, 0, 3313, 1, 0, 0, 28153), -- Plans: Elementium Bonesplitter
(132139, 20, 67606, 0, 3314, 1, 0, 0, 28153), -- Plans: Forged Elementium Mindcrusher
(132139, 19, 67603, 0, 3313, 1, 0, 0, 28153), -- Plans: Elementium Gutslicer
(132139, 18, 66120, 0, 3313, 1, 0, 0, 28153), -- Plans: Vicious Pyrium Boots
(132139, 17, 66127, 0, 3312, 1, 0, 0, 28153), -- Plans: Vicious Ornate Pyrium Belt
(132139, 16, 66109, 0, 3312, 1, 0, 0, 28153), -- Plans: Light Elementium Belt
(132139, 15, 66105, 0, 3312, 1, 0, 0, 28153), -- Plans: Hardened Elementium Girdle
(132139, 14, 66107, 0, 3312, 1, 0, 0, 28153), -- Plans: Elementium Girdle of Pain
(132139, 13, 66119, 0, 3312, 1, 0, 0, 28153), -- Plans: Vicious Pyrium Belt
(132139, 12, 66103, 0, 3312, 1, 0, 0, 28153), -- Plans: Pyrium Weapon Chain
(132139, 11, 66126, 0, 3312, 1, 0, 0, 28153), -- Plans: Vicious Ornate Pyrium Gauntlets
(132139, 10, 66125, 0, 3312, 1, 0, 0, 28153), -- Plans: Vicious Ornate Pyrium Bracers
(132139, 9, 66118, 0, 3312, 1, 0, 0, 28153), -- Plans: Vicious Pyrium Gauntlets
(132139, 8, 66117, 0, 3312, 1, 0, 0, 28153), -- Plans: Vicious Pyrium Bracers
(132139, 7, 3857, 0, 0, 1, 0, 0, 28153), -- Coal
(132139, 6, 18567, 0, 0, 1, 0, 0, 28153), -- Elemental Flux
(132139, 5, 160298, 0, 0, 1, 0, 0, 28153), -- Durable Flux
(132139, 4, 3466, 0, 0, 1, 0, 0, 28153), -- Strong Flux
(132139, 3, 2880, 0, 0, 1, 0, 0, 28153), -- Weak Flux
(132139, 2, 5956, 0, 0, 1, 0, 0, 28153), -- Blacksmith Hammer
(132139, 1, 2901, 0, 0, 1, 0, 0, 28153), -- Mining Pick
(132138, 13, 81918, 0, 0, 1, 0, 0, 28153), -- Pickled Pig's Snout
(132138, 12, 81917, 0, 0, 1, 0, 0, 28153), -- Mutton Stew
(132138, 11, 58269, 0, 0, 1, 0, 0, 28153), -- Massive Turkey Leg
(132138, 10, 58268, 0, 0, 1, 0, 0, 28153), -- Roasted Beef
(132138, 9, 35953, 0, 0, 1, 0, 0, 28153), -- Mead Basted Caribou
(132138, 8, 33454, 0, 0, 1, 0, 0, 28153), -- Salted Venison
(132138, 7, 27854, 0, 0, 1, 0, 0, 28153), -- Smoked Talbuk Venison
(132138, 6, 8952, 0, 0, 1, 0, 0, 28153), -- Roasted Quail
(132138, 5, 4599, 0, 0, 1, 0, 0, 28153), -- Cured Ham Steak
(132138, 4, 3771, 0, 0, 1, 0, 0, 28153), -- Wild Hog Shank
(132138, 3, 3770, 0, 0, 1, 0, 0, 28153), -- Mutton Chop
(132138, 2, 2287, 0, 0, 1, 0, 0, 28153), -- Haunch of Meat
(132138, 1, 117, 0, 0, 1, 0, 0, 28153), -- Tough Jerky
(130216, 8, 160544, 0, 6306, 1, 0, 0, 28153), -- Champions of Azeroth Tabard
(130216, 7, 163515, 0, 6430, 1, 0, 0, 28153), -- Shard of Azerite
(130216, 6, 163555, 0, 6424, 1, 0, 0, 28153), -- Drop of Azerite
(130216, 5, 161563, 0, 6312, 1, 0, 0, 28153), -- Helm of the Azerothian Champion
(130216, 4, 161560, 0, 6312, 1, 0, 0, 28153), -- Azerothian Champion's Spaulders
(130216, 3, 161557, 0, 6312, 1, 0, 0, 28153), -- Vest of the Azerothian Champion
(130216, 2, 161555, 0, 6312, 1, 0, 0, 28153), -- Azerothian Champion's Crown
(130216, 1, 160537, 0, 6305, 1, 0, 0, 28153); -- Drape of the Azerothian Champion


DELETE FROM `creature_equip_template` WHERE (`CreatureID`=131908 AND `ID`=1) OR (`CreatureID`=132199 AND `ID`=1) OR (`CreatureID`=131907 AND `ID`=1) OR (`CreatureID`=131957 AND `ID`=1) OR (`CreatureID`=132062 AND `ID`=1) OR (`CreatureID`=133755 AND `ID`=1) OR (`CreatureID`=131947 AND `ID`=1) OR (`CreatureID`=130030 AND `ID`=1) OR (`CreatureID`=131946 AND `ID`=1) OR (`CreatureID`=132192 AND `ID`=1) OR (`CreatureID`=131952 AND `ID`=1) OR (`CreatureID`=132190 AND `ID`=1) OR (`CreatureID`=132140 AND `ID`=1) OR (`CreatureID`=132147 AND `ID`=1) OR (`CreatureID`=132138 AND `ID`=1) OR (`CreatureID`=132064 AND `ID`=1);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(131908, 1, 52057, 0, 0, 0, 0, 0, 0, 0, 0), -- Twilight Survivor
(132199, 1, 117384, 0, 0, 0, 0, 0, 0, 0, 0), -- Twilight Earthbreaker
(131907, 1, 65102, 0, 0, 0, 0, 0, 0, 0, 0), -- Twilight Ritualist
(131957, 1, 5278, 0, 0, 5278, 0, 0, 0, 0, 0), -- SI:7 Operative
(132062, 1, 118559, 0, 0, 0, 0, 0, 0, 0, 0), -- Bilgewater Laborer
(133755, 1, 1899, 0, 0, 143, 0, 0, 2551, 0, 0), -- Alliance Guard
(131947, 1, 2703, 0, 0, 0, 0, 0, 0, 0, 0), -- Clifford Bentham
(130030, 1, 56090, 0, 0, 0, 0, 0, 0, 0, 0), -- Kelsey Steelspark
(131946, 1, 1899, 0, 0, 143, 0, 0, 2551, 0, 0), -- Alliance Guard
(132192, 1, 1910, 0, 0, 0, 0, 0, 0, 0, 0), -- Khargus Stonemantle
(131952, 1, 45123, 0, 0, 0, 0, 0, 0, 0, 0), -- Edmund Hackney
(132190, 1, 1903, 0, 0, 0, 0, 0, 0, 0, 0), -- Alliance Worker
(132140, 1, 3433, 0, 0, 0, 0, 0, 0, 0, 0), -- Urok Windcleaver
(132147, 1, 111703, 0, 0, 0, 0, 0, 0, 0, 0), -- Grol Warblade
(132138, 1, 2827, 0, 0, 2196, 0, 0, 2551, 0, 0), -- Gaula Axefury
(132064, 1, 5289, 0, 0, 0, 0, 0, 2507, 0, 0); -- Horde Grunt


DELETE FROM `gossip_menu` WHERE (`MenuId`=22104 AND `TextId`=33845) OR (`MenuId`=22218 AND `TextId`=34038) OR (`MenuId`=22209 AND `TextId`=33743);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(22104, 33845, 28153), -- 132147 (Grol Warblade)
(22218, 34038, 28153), -- 132064 (Horde Grunt)
(22209, 33743, 28153); -- Magni Bronzebeard

UPDATE `gossip_menu` SET `VerifiedBuild`=28153 WHERE (`MenuId`=21720 AND `TextId`=33093); -- 0
DELETE FROM `gossip_menu_option` WHERE (`MenuId`=22104 AND `OptionIndex`=0) OR (`MenuId`=21720 AND `OptionIndex`=0) OR (`MenuId`=22209 AND `OptionIndex`=3);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(22104, 0, 0, 'Show me the events that brought the Horde to Silithus.', 161807, 28153),
(21720, 0, 0, 'Can you show me what Silithus was like before the Wound in the World?', 138524, 28153),
(22209, 3, 1, 'Let me browse your goods.', 7509, 28153);






UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=132580; -- Ssinkrix
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2136, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=132886; -- Twilight Hermit
UPDATE `creature_template` SET `minlevel`=7, `maxlevel`=7 WHERE `entry`=15801; -- GONG BOY DND DNR
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction`=1779, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=133263; -- Rhonormu
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=132591; -- Ogmot the Mad
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2146, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=131908; -- Twilight Survivor
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2146, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132199; -- Twilight Earthbreaker
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2146, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=131907; -- Twilight Ritualist
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=14, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=132584; -- Xaarshej
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=310, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=131892; -- Silithid Sentinel
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=310, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=131895; -- Silithid Spitfire
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=310, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=131893; -- Silithid Drone
UPDATE `creature_template` SET `faction`=190, `speed_walk`=0.4, `speed_run`=0.2857143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=131903; -- Silithid Broodling
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=131943; -- Highlord Demitrian
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `speed_walk`=1.4, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=131909; -- Wasteland Crusher
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2667, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048, `VehicleId`=5764 WHERE `entry`=132164; -- Bilgewater Shredder
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2618, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=131957; -- SI:7 Operative
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2667, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=132042; -- Bilgewater Mook
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=67635200 WHERE `entry`=133022; -- Inactive Shredder
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2667, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=132055; -- Bilgewater Prospector
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=2667, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=132062; -- Bilgewater Laborer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2774, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=133755; -- Alliance Guard
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1732, `npcflag`=128, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=131947; -- Clifford Bentham
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=35, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=130030; -- Kelsey Steelspark
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=12, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132995; -- Laurette Royston
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1732, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=131963; -- Nolan Speed
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2774, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=131946; -- Alliance Guard
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1732, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132192; -- Khargus Stonemantle
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1732, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132606; -- Tammy Tinkspinner
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1732, `npcflag`=4224, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=131952; -- Edmund Hackney
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1732, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132190; -- Alliance Worker
UPDATE `creature_template` SET `gossip_menu_id`=21720, `minlevel`=110, `maxlevel`=110, `faction`=1779, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=128607; -- Zidormi
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `speed_walk`=1.4, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=131906; -- Sand Stormer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=29, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132140; -- Urok Windcleaver
UPDATE `creature_template` SET `gossip_menu_id`=22104, `minlevel`=120, `maxlevel`=120, `faction`=2773, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132147; -- Grol Warblade
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1735, `npcflag`=4224, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132139; -- Hagras Wartaker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1735, `npcflag`=2, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132045; -- Gizmax Greasebolt
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1735, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132142; -- Bilgewater Mechanic
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1735, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132040; -- Pixni Rustbomb
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1735, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132141; -- Bilgewater Worker
UPDATE `creature_template` SET `minlevel`=110, `maxlevel`=110, `faction`=1735, `npcflag`=640, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=132138; -- Gaula Axefury
UPDATE `creature_template` SET `gossip_menu_id`=22218, `minlevel`=120, `maxlevel`=120, `faction`=2773, `npcflag`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=132064; -- Horde Grunt
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=131904; -- Spiky Lizard
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=310, `speed_walk`=1.4, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=131890; -- -Unknown-
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.8571429, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=131896; -- Scorpid Skitterer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=137906; -- Infused Bedrock
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2099200 WHERE `entry`=137907; -- Infused Crag
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137904; -- Minor Azerite Infused Elemental
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=310, `speed_walk`=1.4, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=131897; -- Stonelash Pincer
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=14, `speed_walk`=1.4, `speed_run`=1.428571, `BaseAttackTime`=1500, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=132526; -- -Unknown-
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120, `faction`=2190, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=137905; -- -Unknown-

SET NAMES 'utf8';
SET @GROUP_ID = 0;
SET @ID = 0;
DELETE FROM `creature_text` WHERE (`CreatureID`=131952 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=135668 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=135671 AND `GroupID`='0' AND `ID`='0');
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(131952, 0, 0, 'Goibon Uden lo ', 12, 0, 100, 0, 0, 0, 0, 'Edmund Hackney to Player'),
(135668, 0, 0, 'If we can\'t stop this corruption, who will?', 12, 0, 100, 1, 0, 0, 154266, 'Cenarion Circle Druid'),
(135671, 0, 0, 'Nature cries out in pain... how do we stop this madness?', 12, 0, 100, 1, 0, 0, 154263, 'Earthen Ring Shaman');

UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=28153 WHERE (`CreatureID`=15801 AND `CreatureDisplayID`=13069); -- GONG BOY DND DNR
UPDATE `creature_template_model` SET `Probability`=100, `VerifiedBuild`=28153 WHERE (`CreatureID`=15454 AND `CreatureDisplayID`=13069); -- Anachronos Quest Trigger Invisible
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=28153 WHERE (`CreatureID`=15454 AND `CreatureDisplayID`=1126); -- Anachronos Quest Trigger Invisible
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=28153 WHERE (`CreatureID`=133263 AND `CreatureDisplayID`=82812); -- Rhonormu
UPDATE `creature_template_model` SET `Probability`=15, `VerifiedBuild`=28153 WHERE (`CreatureID`=131908 AND `CreatureDisplayID`=69280); -- Twilight Survivor
UPDATE `creature_template_model` SET `Probability`=30, `VerifiedBuild`=28153 WHERE (`CreatureID`=131908 AND `CreatureDisplayID`=69279); -- Twilight Survivor
UPDATE `creature_template_model` SET `Probability`=30, `VerifiedBuild`=28153 WHERE (`CreatureID`=131908 AND `CreatureDisplayID`=69278); -- Twilight Survivor
UPDATE `creature_template_model` SET `Probability`=30, `VerifiedBuild`=28153 WHERE (`CreatureID`=131908 AND `CreatureDisplayID`=69277); -- Twilight Survivor
UPDATE `creature_template_model` SET `Probability`=2, `VerifiedBuild`=28153 WHERE (`CreatureID`=132199 AND `CreatureDisplayID`=53490); -- Twilight Earthbreaker
UPDATE `creature_template_model` SET `Probability`=2, `VerifiedBuild`=28153 WHERE (`CreatureID`=132199 AND `CreatureDisplayID`=57146); -- Twilight Earthbreaker
UPDATE `creature_template_model` SET `Probability`=2, `VerifiedBuild`=28153 WHERE (`CreatureID`=132199 AND `CreatureDisplayID`=53856); -- Twilight Earthbreaker
UPDATE `creature_template_model` SET `Probability`=20, `VerifiedBuild`=28153 WHERE (`CreatureID`=131907 AND `CreatureDisplayID`=69284); -- Twilight Ritualist
UPDATE `creature_template_model` SET `Probability`=25, `VerifiedBuild`=28153 WHERE (`CreatureID`=131907 AND `CreatureDisplayID`=69283); -- Twilight Ritualist
UPDATE `creature_template_model` SET `Probability`=30, `VerifiedBuild`=28153 WHERE (`CreatureID`=131907 AND `CreatureDisplayID`=69282); -- Twilight Ritualist
UPDATE `creature_template_model` SET `Probability`=30, `VerifiedBuild`=28153 WHERE (`CreatureID`=131907 AND `CreatureDisplayID`=69281); -- Twilight Ritualist
UPDATE `creature_template_model` SET `Probability`=100, `VerifiedBuild`=28153 WHERE (`CreatureID`=131943 AND `CreatureDisplayID`=14395); -- Highlord Demitrian
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=28153 WHERE (`CreatureID`=128607 AND `CreatureDisplayID`=27756); -- Zidormi
UPDATE `creature_template_model` SET `Probability`=100, `VerifiedBuild`=28153 WHERE (`CreatureID`=132140 AND `CreatureDisplayID`=82246); -- Urok Windcleaver
UPDATE `creature_template_model` SET `Probability`=100, `VerifiedBuild`=28153 WHERE (`CreatureID`=132147 AND `CreatureDisplayID`=82256); -- Grol Warblade
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=28153 WHERE (`CreatureID`=132064 AND `CreatureDisplayID`=4601); -- Horde Grunt
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=28153 WHERE (`CreatureID`=132064 AND `CreatureDisplayID`=4602); -- Horde Grunt

DELETE FROM `gameobject_template` WHERE `entry` IN (277620 /*AQROOT*/, 277611 /*AQRUNE*/, 277692 /*Meeting Stone*/, 277626 /*Meeting Stone*/, 268414 /*Alliance Banner*/, 280895 /*Skeleton*/, 267179 /*Alliance Banner*/, 280948 /*Twilight Outhouse*/, 281078 /*Pipe*/, 281073 /*Smoke Stack*/, 281071 /*Goblin Battery*/, 281420 /*Campfire*/, 281072 /*Oil Pump*/, 280720 /*Horde Crate*/, 281077 /*Pipe*/, 281076 /*Pipe*/, 281074 /*Fuel Can*/, 281075 /*Oil Drum*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `RequiredLevel`, `VerifiedBuild`) VALUES
(277620, 0, 4133, 'AQROOT', '', '', '', 1.07, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- AQROOT
(277611, 0, 4134, 'AQRUNE', '', '', '', 1.04, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- AQRUNE
(277692, 23, 5491, 'Meeting Stone', '', '', '', 1, 15, 255, 3428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Meeting Stone
(277626, 23, 5491, 'Meeting Stone', '', '', '', 1, 15, 255, 3428, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Meeting Stone
(268414, 5, 16173, 'Alliance Banner', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Banner
(280895, 5, 4093, 'Skeleton', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Skeleton
(267179, 5, 19418, 'Alliance Banner', '', '', '', 2, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Alliance Banner
(280948, 2, 47342, 'Twilight Outhouse', 'quest', '', '', 1, 0, 21796, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Twilight Outhouse
(281078, 5, 15509, 'Pipe', '', '', '', 0.5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Pipe
(281073, 5, 29755, 'Smoke Stack', '', '', '', 0.25, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Smoke Stack
(281071, 5, 10827, 'Goblin Battery', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Goblin Battery
(281420, 8, 16847, 'Campfire', '', '', '', 1, 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Campfire
(281072, 5, 9550, 'Oil Pump', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Oil Pump
(280720, 5, 5531, 'Horde Crate', '', '', '', 0.5, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Horde Crate
(281077, 5, 47461, 'Pipe', '', '', '', 0.5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Pipe
(281076, 5, 29776, 'Pipe', '', '', '', 0.5, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Pipe
(281074, 5, 8099, 'Fuel Can', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153), -- Fuel Can
(281075, 5, 9663, 'Oil Drum', '', '', '', 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 28153); -- Oil Drum

UPDATE `gameobject_template` SET `Data3`=1, `VerifiedBuild`=28153 WHERE `entry`=180718; -- The Scarab Gong

DELETE FROM `npc_text` WHERE `ID` IN (33845 /*33845*/, 34038 /*34038*/, 33743 /*33743*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(33845, 1, 0, 0, 0, 0, 0, 0, 0, 146359, 0, 0, 0, 0, 0, 0, 0, 28153), -- 33845
(34038, 1, 1, 1, 1, 0, 0, 0, 0, 147388, 147389, 147380, 147390, 0, 0, 0, 0, 28153), -- 34038
(33743, 1, 0, 0, 0, 0, 0, 0, 0, 145171, 0, 0, 0, 0, 0, 0, 0, 28153); -- 33743


UPDATE `creature` SET `terrainSwapMap` = 1817 WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+524;
UPDATE `gameobject` SET `terrainSwapMap` = 1817 WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+125;
