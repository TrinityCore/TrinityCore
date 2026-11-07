SET @CGUID := 11000393;
SET @OGUID := 11000007;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+36;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 245555, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -787.592041015625, -1104.4722900390625, 674.07940673828125, 0, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Swarming Shade (Area: The Dreamrift - Difficulty: Normal) CreateObject1
(@CGUID+1, 245575, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -786.60418701171875, -1115.8160400390625, 673.8848876953125, 0, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Haunting Essence (Area: The Dreamrift - Difficulty: Normal) CreateObject1
(@CGUID+2, 245555, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -781.30816650390625, -1107.08740234375, 674.44989013671875, 1.942371964454650878, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Swarming Shade (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 80808 - Cosmetic - Alpha State 0%)
(@CGUID+3, 254774, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -766.6632080078125, -1136.6927490234375, 673.79669189453125, 0.806599557399749755, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Sergeant Quackers (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+4, 245556, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -789.8753662109375, -1116.27734375, 673.68304443359375, 3.501076698303222656, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Colossal Horror (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 80808 - Cosmetic - Alpha State 0%)
(@CGUID+5, 253132, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -744.56390380859375, -1093.241943359375, 679.43487548828125, 1.016281485557556152, 604800, 4, 0, 1, NULL, NULL, NULL, NULL, 66527), -- Underrift Moth (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader)
(@CGUID+6, 245555, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -788.3236083984375, -1101.9854736328125, 674.07781982421875, 5.043668746948242187, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Swarming Shade (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 80808 - Cosmetic - Alpha State 0%)
(@CGUID+7, 249066, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 1, -777.65277099609375, -1086.185791015625, 674.4271240234375, 4.425620079040527343, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Amarakk (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1270994 - Hold the Line!)
(@CGUID+8, 249280, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 1, -762.05731201171875, -1036.6180419921875, 674.36676025390625, 4.338056087493896484, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- En'liahn (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+9, 245555, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -749.8524169921875, -1100.49658203125, 677.4171142578125, 0, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Swarming Shade (Area: The Dreamrift - Difficulty: Normal) CreateObject1
(@CGUID+10, 253131, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -761.59344482421875, -1030.9364013671875, 674.26953125, 0.122570976614952087, 604800, 4, 0, 1, NULL, NULL, NULL, NULL, 66527), -- Rift Potadpole (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader)
(@CGUID+11, 245575, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -776.73956298828125, -1121.5208740234375, 674.255126953125, 0.033210199326276779, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Haunting Essence (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 80808 - Cosmetic - Alpha State 0%)
(@CGUID+12, 253457, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -1395.4017333984375, -1124.0120849609375, 726.40887451171875, 1.565437197685241699, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Astray Manifestation (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader, 1259121 - [DNT] Alnsight Cosmetic Alpha)
(@CGUID+13, 245556, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -796.70587158203125, -1111.998046875, 673.1402587890625, 4.521075248718261718, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Colossal Horror (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 80808 - Cosmetic - Alpha State 0%)
(@CGUID+14, 256116, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -792.02081298828125, -1112.888916015625, 673.601806640625, 0.530372798442840576, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Chimaerus (Area: The Dreamrift - Difficulty: Normal) CreateObject1
(@CGUID+15, 245575, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -784.99481201171875, -1110.9322509765625, 674.1256103515625, 0, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Haunting Essence (Area: The Dreamrift - Difficulty: Normal) CreateObject1
(@CGUID+16, 253131, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -804.8173828125, -1036.3851318359375, 673.2769775390625, 1.975446701049804687, 604800, 4, 0, 1, NULL, NULL, NULL, NULL, 66527), -- Rift Potadpole (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader)
(@CGUID+17, 245555, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -778.6251220703125, -1112.8759765625, 674.52203369140625, 5.302561759948730468, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Swarming Shade (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 80808 - Cosmetic - Alpha State 0%)
(@CGUID+18, 253132, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -763.65814208984375, -1129.8997802734375, 677.9564208984375, 3.431071758270263671, 604800, 4, 0, 1, NULL, NULL, NULL, NULL, 66527), -- Underrift Moth (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader)
(@CGUID+19, 245575, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -796.4923095703125, -1100.3033447265625, 673.22271728515625, 0.942626953125, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Haunting Essence (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 80808 - Cosmetic - Alpha State 0%)
(@CGUID+20, 245555, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -786.15277099609375, -1105.8004150390625, 674.1788330078125, 0, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Swarming Shade (Area: The Dreamrift - Difficulty: Normal) CreateObject1
(@CGUID+21, 253131, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -788.488525390625, -1132.46923828125, 672.62481689453125, 2.233999252319335937, 604800, 4, 0, 1, NULL, NULL, NULL, NULL, 66527), -- Rift Potadpole (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader)
(@CGUID+22, 249279, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 1, -766.09552001953125, -1107.185791015625, 675.7486572265625, 3.503299951553344726, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Shul'ka Seila (Area: The Dreamrift - Difficulty: Normal) CreateObject1
(@CGUID+23, 253457, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -902.89300537109375, -1078.7047119140625, 651.3525390625, 3.120233535766601562, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Astray Manifestation (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader, 1259121 - [DNT] Alnsight Cosmetic Alpha)
(@CGUID+24, 245569, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -1367.41748046875, -1264.350830078125, 680.83599853515625, 0.430401623249053955, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Chimaerus (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection, 1245748 - Alndust Energy, 80808 - Cosmetic - Alpha State 0%, 295475 - Mod Scale 35%)
(@CGUID+25, 253457, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -789.73095703125, -1255.195556640625, 449.121795654296875, 5.222716331481933593, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Astray Manifestation (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader, 1259121 - [DNT] Alnsight Cosmetic Alpha)
(@CGUID+26, 253132, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -1033.3594970703125, -1096.6724853515625, 688.58746337890625, 2.143465518951416015, 604800, 4, 0, 1, NULL, NULL, NULL, NULL, 66527), -- Underrift Moth (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader)
(@CGUID+27, 253457, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -869.4849853515625, -1113.739013671875, 663.9140625, 2.407356739044189453, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Astray Manifestation (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader, 1259121 - [DNT] Alnsight Cosmetic Alpha)
(@CGUID+28, 253132, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -893.964111328125, -1183.1029052734375, 703.5771484375, 3.064356327056884765, 604800, 4, 0, 1, NULL, NULL, NULL, NULL, 66527), -- Underrift Moth (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader)
(@CGUID+29, 253457, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -703.7301025390625, -1646.969482421875, 573.26953125, 6.229364395141601562, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Astray Manifestation (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader, 1259121 - [DNT] Alnsight Cosmetic Alpha)
(@CGUID+30, 253132, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -816.53460693359375, -1232.308837890625, 662.25335693359375, 3.370735883712768554, 604800, 4, 0, 1, NULL, NULL, NULL, NULL, 66527), -- Underrift Moth (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader)
(@CGUID+31, 253132, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -878.702392578125, -1069.8460693359375, 689.0340576171875, 5.784270286560058593, 604800, 4, 0, 1, NULL, NULL, NULL, NULL, 66527), -- Underrift Moth (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader)
(@CGUID+32, 253457, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -1058.811767578125, -1180.6024169921875, 661.79571533203125, 1.474488019943237304, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Astray Manifestation (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader, 1259121 - [DNT] Alnsight Cosmetic Alpha)
(@CGUID+33, 253457, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -1316.7847900390625, -1010.940185546875, 669.6724853515625, 5.51616668701171875, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Astray Manifestation (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader, 1259121 - [DNT] Alnsight Cosmetic Alpha) (possible waypoints or random movement)
(@CGUID+34, 253132, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -948.98907470703125, -1311.2615966796875, 662.25335693359375, 0.771706342697143554, 604800, 4, 0, 1, NULL, NULL, NULL, NULL, 66527), -- Underrift Moth (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader)
(@CGUID+35, 253457, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -1289.2391357421875, -1316.3736572265625, 554.36346435546875, 5.050086021423339843, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527), -- Astray Manifestation (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader, 1259121 - [DNT] Alnsight Cosmetic Alpha) (possible waypoints or random movement)
(@CGUID+36, 253457, 2939, 16531, 16531, '14,15,16,17', '0', 0, 0, 0, -1303.168212890625, -968.7440185546875, 735.102294921875, 5.915684223175048828, 604800, 0, 0, 0, NULL, NULL, NULL, NULL, 66527); -- Astray Manifestation (Area: The Dreamrift - Difficulty: Normal) CreateObject1 (Auras: 1238822 - [DNT] Azerite Shader, 1259121 - [DNT] Alnsight Cosmetic Alpha)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+36;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Swarming Shade
(@CGUID+1, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Haunting Essence
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80808'), -- Swarming Shade - 80808 - Cosmetic - Alpha State 0%
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '123168'), -- Sergeant Quackers - 123168 - Mod Scale 115-120%
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80808'), -- Colossal Horror - 80808 - Cosmetic - Alpha State 0%
(@CGUID+5, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1238822'), -- Underrift Moth - 1238822 - [DNT] Azerite Shader
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80808'), -- Swarming Shade - 80808 - Cosmetic - Alpha State 0%
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '1270994'), -- Amarakk - 1270994 - Hold the Line!
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- En'liahn
(@CGUID+9, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Swarming Shade
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1238822'), -- Rift Potadpole - 1238822 - [DNT] Azerite Shader
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80808'), -- Haunting Essence - 80808 - Cosmetic - Alpha State 0%
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80808'), -- Colossal Horror - 80808 - Cosmetic - Alpha State 0%
(@CGUID+15, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Haunting Essence
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1238822'), -- Rift Potadpole - 1238822 - [DNT] Azerite Shader
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80808'), -- Swarming Shade - 80808 - Cosmetic - Alpha State 0%
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80808'), -- Haunting Essence - 80808 - Cosmetic - Alpha State 0%
(@CGUID+20, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Swarming Shade
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1238822'), -- Rift Potadpole - 1238822 - [DNT] Azerite Shader
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''); -- Shul'ka Seila

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 253128, 2939, 16531, 16531, '14,15,16,17', '0', 0, -713.8680419921875, -1057.4114990234375, 677.00860595703125, 0.175276935100555419, 0, 0, 0.087526321411132812, 0.996162176132202148, 604800, 255, 1, 66527); -- Instance Portal (Area: The Dreamrift - Difficulty: Normal) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+0;

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (245569 /*245569 (Chimaerus) - Invisibility and Stealth Detection, Alndust Energy, Cosmetic - Alpha State 0%, Mod Scale 35%*/, 253457 /*253457 (Astray Manifestation) - [DNT] Azerite Shader, [DNT] Alnsight Cosmetic Alpha*/, 256116 /*256116 (Chimaerus)*/, 256995 /*256995 (En'liahn) - Ride Vehicle Hardcoded*/, 253131 /*253131 (Rift Potadpole) - [DNT] Azerite Shader*/, 249066 /*249066 (Amarakk) - Hold the Line!*/, 253132 /*253132 (Underrift Moth) - [DNT] Azerite Shader*/, 245556 /*245556 (Colossal Horror) - Cosmetic - Alpha State 0%*/, 254774 /*254774 (Sergeant Quackers) - Mod Scale 115-120%*/, 245575 /*245575 (Haunting Essence)*/, 245555 /*245555 (Swarming Shade)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(245569, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 5, '18950 1245748 80808 295475'), -- 245569 (Chimaerus) - Invisibility and Stealth Detection, Alndust Energy, Cosmetic - Alpha State 0%, Mod Scale 35%
(253457, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, '1238822 1259121'), -- 253457 (Astray Manifestation) - [DNT] Azerite Shader, [DNT] Alnsight Cosmetic Alpha
(256116, 0, 0, 0, 0, 0, 1, 0, 0, 15498, 0, 0, 3, ''), -- 256116 (Chimaerus)
(256995, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 256995 (En'liahn) - Ride Vehicle Hardcoded
(253131, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1238822'), -- 253131 (Rift Potadpole) - [DNT] Azerite Shader
(249066, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1270994'), -- 249066 (Amarakk) - Hold the Line!
(253132, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1238822'), -- 253132 (Underrift Moth) - [DNT] Azerite Shader
(245556, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '80808'), -- 245556 (Colossal Horror) - Cosmetic - Alpha State 0%
(254774, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123168'), -- 254774 (Sergeant Quackers) - Mod Scale 115-120%
(245575, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- 245575 (Haunting Essence)
(245555, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''); -- 245555 (Swarming Shade)

-- Template
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.111111998558044433, `speed_run`=1.785714268684387207, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags3`=0x800000 WHERE `entry`=245569; -- Chimaerus
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.799999952316284179, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=0x2000340, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=253457; -- Astray Manifestation
UPDATE `creature_template` SET `faction`=3512, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=249279; -- Shul'ka Seila
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.111111998558044433, `speed_run`=1.785714268684387207, `BaseAttackTime`=2000 WHERE `entry`=256116; -- Chimaerus
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x4000800, `unit_flags3`=0x41008001 WHERE `entry`=256995; -- En'liahn
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=253131; -- Rift Potadpole
UPDATE `creature_template` SET `faction`=3512, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800, `VehicleId`=9302 WHERE `entry`=249280; -- En'liahn
UPDATE `creature_template` SET `faction`=3512, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=249066; -- Amarakk
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=253132; -- Underrift Moth
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000040, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=245556; -- Colossal Horror
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=254774; -- Sergeant Quackers
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x0801, `unit_flags3`=0x01000000|0x00002000 WHERE `entry`=245575; -- Haunting Essence
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x0801, `unit_flags3`=0x01000000|0x00002000 WHERE `entry`=245555; -- Swarming Shade

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (249279,249280,249066));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(249279, 1, 252376, 0, 0, 0, 0, 0, 0, 0, 0, 66527), -- Shul'ka Seila
(249280, 1, 254201, 0, 0, 0, 0, 0, 0, 0, 0, 66527), -- En'liahn
(249066, 1, 252376, 0, 0, 0, 0, 0, 0, 0, 0, 66527); -- Amarakk

-- SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 249280;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(249280, 46598, 1, 0);

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=249280 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(249280, 256995, 0, 1, 'En\'liahn - En\'liahn', 0, 0); -- En'liahn - En'liahn

-- Difficulty
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=3607, `StaticFlags1`=0x20000000, `VerifiedBuild`=66527 WHERE (`Entry`=245569 AND `DifficultyID`=0); -- 245569 (Chimaerus) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=3607, `StaticFlags1`=0x30000000, `VerifiedBuild`=66527 WHERE (`Entry`=253457 AND `DifficultyID`=0); -- 253457 (Astray Manifestation) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3607, `StaticFlags1`=0x10000000, `VerifiedBuild`=66527 WHERE (`Entry`=249279 AND `DifficultyID`=0); -- 249279 (Shul'ka Seila) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=3, `LevelScalingDeltaMax`=3, `ContentTuningID`=3607, `VerifiedBuild`=66527 WHERE (`Entry`=256116 AND `DifficultyID`=0); -- 256116 (Chimaerus) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=328, `StaticFlags1`=0x20000100, `VerifiedBuild`=66527 WHERE (`Entry`=256995 AND `DifficultyID`=0); -- 256995 (En'liahn) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=66527 WHERE (`Entry`=253131 AND `DifficultyID`=0); -- 253131 (Rift Potadpole) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3607, `StaticFlags1`=0x10000000, `VerifiedBuild`=66527 WHERE (`Entry`=249280 AND `DifficultyID`=0); -- 249280 (En'liahn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3607, `StaticFlags1`=0x10000000, `VerifiedBuild`=66527 WHERE (`Entry`=249066 AND `DifficultyID`=0); -- 249066 (Amarakk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x30000000, `VerifiedBuild`=66527 WHERE (`Entry`=253132 AND `DifficultyID`=0); -- 253132 (Underrift Moth) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=3607, `StaticFlags1`=0x10000000, `VerifiedBuild`=66527 WHERE (`Entry`=245556 AND `DifficultyID`=0); -- 245556 (Colossal Horror) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3607, `StaticFlags1`=0x10000000, `StaticFlags3`=0x40000, `VerifiedBuild`=66527 WHERE (`Entry`=254774 AND `DifficultyID`=0); -- 254774 (Sergeant Quackers) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=3607, `StaticFlags1`=0x10000000, `VerifiedBuild`=66527 WHERE (`Entry`=245575 AND `DifficultyID`=0); -- 245575 (Haunting Essence) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=3607, `StaticFlags1`=0x10000000, `VerifiedBuild`=66527 WHERE (`Entry`=245555 AND `DifficultyID`=0); -- 245555 (Swarming Shade) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (142894, 137646, 138354, 138356, 136680, 138355, 117925, 142323, 140806, 140805);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(142894, 6.216385841369628906, 1.5, 0, 66527),
(137646, 0.581943452358245849, 1.80000007152557373, 0, 66527),
(138354, 0.85696578025817871, 0, 0, 66527),
(138356, 0.85696578025817871, 0, 0, 66527),
(136680, 4.019346237182617187, 4, 0, 66527),
(138355, 0.85696578025817871, 0, 0, 66527),
(117925, 0.244999989867210388, 0.699999988079071044, 0, 66527),
(142323, 6.026553630828857421, 8, 0, 66527),
(140806, 0.5, 1.5, 0, 66527),
(140805, 0.5, 1.5, 0, 66527);

-- Path for Chimaerus
SET @MOVERGUID := @CGUID+24;
SET @ENTRY := 245569;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 48.8461, 'Chimaerus - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1326.6702, -1159.257, 680.889, NULL, 0),
(@PATH, 1, -1372.625, -1121.7795, 680.889, NULL, 0),
(@PATH, 2, -1427.2153, -1121.9358, 680.889, NULL, 0),
(@PATH, 3, -1481.4774, -1167.4392, 702.4301, NULL, 0),
(@PATH, 4, -1478.8698, -1226.9497, 694.1883, NULL, 0),
(@PATH, 5, -1430.5834, -1262.0938, 680.889, NULL, 0),
(@PATH, 6, -1399.3125, -1275.0486, 680.889, NULL, 0),
(@PATH, 7, -1346.5885, -1253.4757, 680.889, NULL, 0),
(@PATH, 8, -1326.5973, -1230.5695, 681.6359, NULL, 0),
(@PATH, 9, -1325.3334, -1207.382, 681.5873, NULL, 0);

UPDATE `creature_template_addon` SET `PathId` = @PATH WHERE `entry` = 245569;
UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;

-- Path for Astray Manifestation
SET @MOVERGUID := @CGUID+23;
SET @ENTRY := 253457;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 26.5463, 'Astray Manifestation - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -914.04865, -1082.533, 651.35266, NULL, 0),
(@PATH, 1, -900.75867, -1119.7986, 651.35266, NULL, 0),
(@PATH, 2, -829.7049, -1294.7882, 651.35266, NULL, 0),
(@PATH, 3, -912.5903, -1383.9497, 651.35266, NULL, 0),
(@PATH, 4, -979.3333, -1407.7639, 651.35266, NULL, 0),
(@PATH, 5, -1025.5555, -1355.007, 651.35266, NULL, 0),
(@PATH, 6, -1051.1666, -1160.5695, 651.35266, NULL, 0),
(@PATH, 7, -886.15625, -1079.118, 651.35266, NULL, 0);

UPDATE `creature` SET `position_x`=-914.04865, `position_y`=-1082.533, `position_z`=651.35266, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 3, 1, 4, '1238822 1259121');

-- Path for Astray Manifestation
SET @MOVERGUID := @CGUID+27;
SET @ENTRY := 253457;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 31.0180, 'Astray Manifestation - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -767.5607, -1420.4409, 761.4145, NULL, 0),
(@PATH, 1, -786.2465, -1320.3212, 714.5774, NULL, 0),
(@PATH, 2, -804.9323, -1220.2014, 667.7403, NULL, 0),
(@PATH, 3, -841.7344, -1179.5416, 663.91846, NULL, 0),
(@PATH, 4, -868.09894, -1115.0052, 663.91846, NULL, 0),
(@PATH, 5, -1103.231, -937.52954, 663.91846, NULL, 0),
(@PATH, 6, -1077.3403, -853.11456, 747.8006, NULL, 0),
(@PATH, 7, -790.8368, -1147.599, 747.8006, NULL, 0),
(@PATH, 8, -777.5278, -1340.2639, 738.9389, NULL, 0);

UPDATE `creature` SET `position_x`=-767.5607, `position_y`=-1420.4409, `position_z`=761.4145, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 3, 1, 4, '1238822 1259121');

-- Path for Astray Manifestation
SET @MOVERGUID := @CGUID+32;
SET @ENTRY := 253457;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 38.1586, 'Astray Manifestation - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1056.6041, -1143.1007, 659.01245, NULL, 0),
(@PATH, 1, -1060.0591, -1103.3403, 656.1166, NULL, 0),
(@PATH, 2, -1031.6233, -881.30035, 638.4762, NULL, 0),
(@PATH, 3, -1256.9618, -836.0174, 291.0168, NULL, 0),
(@PATH, 4, -1545.908, -762.23267, 638.4762, NULL, 0),
(@PATH, 5, -1670.1892, -1274.717, 661.67267, NULL, 0),
(@PATH, 6, -1160.7084, -1572.2692, 661.67267, NULL, 0),
(@PATH, 7, -1053.651, -1144.75, 661.67267, NULL, 0);

UPDATE `creature` SET `position_x`=-1056.6041, `position_y`=-1143.1007, `position_z`=659.01245, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 3, 1, 4, '1238822 1259121');

-- Path for Astray Manifestation
SET @MOVERGUID := @CGUID+36;
SET @ENTRY := 253457;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 23.5770, 'Astray Manifestation - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1371.6805, -963.25183, 711.4533, NULL, 0),
(@PATH, 1, -1279.4341, -1070.8038, 652.33527, NULL, 0),
(@PATH, 2, -1219.356, -1374.2223, 708.2347, NULL, 0),
(@PATH, 3, -1272.3854, -1497.2743, 711.2215, NULL, 0),
(@PATH, 4, -1505.5035, -1468.8872, 701.2363, NULL, 0),
(@PATH, 5, -1643.3993, -1230.4827, 740.2478, NULL, 0),
(@PATH, 6, -1429.7916, -975.10767, 740.2478, NULL, 0);

UPDATE `creature` SET `position_x`=-1371.6805, `position_y`=-963.25183, `position_z`=711.4533, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 3, 1, 4, '1238822 1259121');

-- Path for Astray Manifestation
SET @MOVERGUID := @CGUID+33;
SET @ENTRY := 253457;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 14.0324, 'Astray Manifestation - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1164.5659, -1025.3942, 815.8983, NULL, 0),
(@PATH, 1, -1681.4479, -1004.4375, 707.2032, NULL, 0),
(@PATH, 2, -1817.6442, -1077.4531, 717.4851, NULL, 0),
(@PATH, 3, -1865.1423, -1035.3229, 717.48517, NULL, 0),
(@PATH, 4, -1897.4149, -960.434, 736.22473, NULL, 0),
(@PATH, 5, -1827.783, -918.77954, 734.0309, NULL, 0),
(@PATH, 6, -1539.033, -759.4149, 719.5612, NULL, 0),
(@PATH, 7, -1387.2778, -928.3906, 734.0309, NULL, 0);

UPDATE `creature` SET `position_x`=-1164.5659, `position_y`=-1025.3942, `position_z`=815.8983, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 3, 1, 4, '1238822 1259121');

-- Path for Astray Manifestation
SET @MOVERGUID := @CGUID+12;
SET @ENTRY := 253457;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 33.2557, 'Astray Manifestation - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1465.5643, -1411.0834, 715.65674, NULL, 0),
(@PATH, 1, -1477.5521, -1388.1459, 727.24725, NULL, 0),
(@PATH, 2, -1489.5399, -1365.2084, 738.83777, NULL, 0),
(@PATH, 3, -1403.5608, -1210.8247, 727.24725, NULL, 0),
(@PATH, 4, -1390.7048, -987.8594, 727.24725, NULL, 0),
(@PATH, 5, -1331.1459, -847.26044, 727.24725, NULL, 0),
(@PATH, 6, -1681.6406, -791.1285, 727.24725, NULL, 0),
(@PATH, 7, -1886.1719, -953.566, 727.24725, NULL, 0),
(@PATH, 8, -1641.0573, -1412.9913, 727.24725, NULL, 0),
(@PATH, 9, -1510.7031, -1449.2952, 727.24725, NULL, 0);

UPDATE `creature` SET `position_x`=-1465.5643, `position_y`=-1411.0834, `position_z`=715.65674, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `AnimTier`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 3, 1, 4, '1238822 1259121');
