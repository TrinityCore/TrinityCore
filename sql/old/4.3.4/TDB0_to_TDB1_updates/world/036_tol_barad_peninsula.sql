DELETE FROM `gameobject_template` WHERE `entry` IN (207562, 207563, 207564, 207561, 207553, 207554, 206580, 202738);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `data0`, `data1`, `data2`, `data3`, `data4`, `data5`, `data6`, `data7`, `data8`, `data9`, `data10`, `data11`, `data12`, `data13`, `data14`, `data15`, `data16`, `data17`, `data18`, `data19`, `data20`, `data21`, `data22`, `data23`, `data24`, `data25`, `data26`, `data27`, `data28`, `data29`, `data30`, `data31`, `size`, `questItem1`, `questItem2`, `questItem3`, `questItem4`, `questItem5`, `questItem6`, `unkInt32`, `WDBVerified`) VALUES
(207562, 7, 92, 'Highback Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(207563, 7, 92, 'Highback Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(207564, 7, 92, 'Highback Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(207561, 8, 679, 'Stove', '', '', '', 4, 10, 2061, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2.359921, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(207553, 7, 39, 'Wooden Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(207554, 7, 39, 'Wooden Chair', '', '', '', 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(206580, 3, 9095, 'Barrel of Southsea Rum', '', '', '', 1691, 35536, 30, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 62810, 0, 0, 0, 0, 0, 0, 15595), -- -Unknown-
(202738, 3, 10157, 'Elementium Vein', '', '', '', 1863, 28492, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 83, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0.6, 0, 0, 0, 0, 0, 0, 65, 15595); -- -Unknown-

SET @OGUID := 1524;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+244;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 206586, 732, 1, 1, -239.9826, 1030.608, 49.05208, 5.864307, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+1, 202747, 732, 1, 1, -234.1493, 1050.76, 49.97136, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+2, 202749, 732, 1, 1, -256.8629, 1152.505, -13.18161, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: -Unknown-)
(@OGUID+3, 207562, 732, 1, 1, -88.61193, 1119.875, 16.6035, 2.670348, 0, 0, 0.9723699, 0.2334454, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+4, 207563, 732, 1, 1, -87.21684, 1101.402, 15.91517, 1.099556, 0, 0, 0.9723699, 0.2334454, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+5, 207564, 732, 1, 1, -89.43463, 1102.532, 15.91517, 1.099556, 0, 0, 0.9723699, 0.2334454, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+6, 206586, 732, 1, 1, -148.609, 964.927, 119.146, 5.340709, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+7, 206586, 732, 1, 1, -140.292, 982.448, 119.146, 5.532695, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+8, 206586, 732, 1, 1, -136.1667, 967.967, 81.94935, 5.864307, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+9, 206586, 732, 1, 1, -135.884, 968.944, 119.146, 5.864307, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+10, 206586, 732, 1, 1, -165.6198, 971.5313, 80.3334, 5.532695, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+11, 206586, 732, 1, 1, -214.8698, 948.5139, 49.00949, 5.864307, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+12, 206586, 732, 1, 1, -224.5677, 917.6493, 63.1411, 5.864307, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+13, 206586, 732, 1, 1, -285.8629, 986.0712, 48.89518, 5.864307, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+14, 206586, 732, 1, 1, -282.2517, 942.6858, 48.89518, 5.864307, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+15, 206586, 732, 1, 1, -298.1042, 969.7136, 49.79652, 5.864307, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+16, 206586, 732, 1, 1, -133.9184, 927.6406, 72.64152, 5.864307, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+17, 202741, 732, 1, 1, -175.7483, 900.2882, 72.86546, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+18, 206586, 732, 1, 1, -309.0451, 960.1545, 50.88475, 6.143561, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+19, 206586, 732, 1, 1, -297.969, 954.425, 88.081, 6.143561, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+20, 206586, 732, 1, 1, -309.854, 960.099, 88.081, 0.2268925, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+21, 206586, 732, 1, 1, -315.38, 946.448, 88.081, 5.864307, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Largo's Overlook)
(@OGUID+22, 207561, 732, 1, 1, -14.04208, 1078.008, 17.10312, 6.257006, 0, 0, 0.6977905, 0.7163019, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+23, 207560, 732, 1, 1, -24.03104, 1114.193, 26.52034, 0.8464848, 0, 0, 0.6977905, 0.7163019, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+24, 207559, 732, 1, 1, -20.43975, 1118.128, 26.52034, 3.464487, 0, 0, 0.6977905, 0.7163019, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+25, 207556, 732, 1, 1, -26.64251, 1117.585, 17.11017, 0.06108471, 0, 0, 0.6977905, 0.7163019, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+26, 207557, 732, 1, 1, -19.70367, 1115.157, 17.11017, 2.330013, 0, 0, 0.6977905, 0.7163019, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+27, 207553, 732, 1, 1, -8.202462, 1093.395, 22.22101, 0.7592189, 0, 0, 0.6977905, 0.7163019, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+28, 207558, 732, 1, 1, -26.60631, 1118.967, 17.11017, 0.06108471, 0, 0, 0.6977905, 0.7163019, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+29, 207555, 732, 1, 1, -8.944311, 1106.954, 16.32072, 4.686209, 0, 0, 0.6977905, 0.7163019, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+30, 207554, 732, 1, 1, -6.461882, 1090.83, 22.22101, 1.893679, 0, 0, 0.6977905, 0.7163019, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+31, 207552, 732, 1, 1, -17.84842, 1101.95, 16.80034, 3.115388, 0, 0, 0.6977905, 0.7163019, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+32, 206754, 732, 1, 1, 35.2135, 1122.32, 4.80512, 3.194002, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+33, 202747, 732, 1, 1, -58.61111, 1291.122, 23.72016, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+34, 206754, 732, 1, 1, 37.6458, 1191.87, 5.07445, 3.700105, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+35, 207463, 732, 1, 1, -5.144669, 1203.836, 17.82883, 0.008726148, 0, 0, -0.7040147, 0.7101853, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+36, 202741, 732, 1, 1, -4.118056, 1275.243, 17.77257, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
-- (@OGUID+37, 35591, 732, 1, 1, -89.94599, 1416.513, 0, 5.485636, 0, 0, 0, 1, 7200, 255, 1), -- Fishing Bobber (Area: Rustberg Village) - !!! might be temporary spawn !!!
(@OGUID+37, 202749, 732, 1, 1, -126.4097, 1366.816, -13.28864, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+38, 202780, 732, 1, 1, -91.63194, 1415.649, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+39, 206754, 732, 1, 1, 56.2847, 1100.02, 3.76969, 5.113817, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+40, 206754, 732, 1, 1, 84.1441, 1142.35, 3.84741, 2.91469, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+41, 206754, 732, 1, 1, 85.4826, 1181.1, 3.94473, 3.787367, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+42, 206754, 732, 1, 1, 55.06597, 1228.241, 3.981622, 4.450591, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+43, 206754, 732, 1, 1, 82.53993, 1200.78, 3.769885, 2.35619, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+44, 206754, 732, 1, 1, 73.2378, 1098.91, 3.85399, 4.502952, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+45, 206754, 732, 1, 1, 84.0278, 1113.66, 3.45814, 5.113817, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+46, 206754, 732, 1, 1, 101.274, 1174.36, 0.320402, 1.448622, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+47, 206754, 732, 1, 1, 99.26389, 1185.16, 4.14275, 5.148723, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+48, 206754, 732, 1, 1, 102.6128, 1137.22, 4.086253, 2.513274, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+49, 202780, 732, 1, 1, 113.4549, 1144.49, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+50, 206754, 732, 1, 1, 102.9219, 1100.46, 3.834607, 2.82743, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+51, 202780, 732, 1, 1, 119.6753, 1166.851, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+52, 202780, 732, 1, 1, 112.2726, 1231.58, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+53, 206754, 732, 1, 1, 100.2465, 1223.465, 4.347825, 5.689774, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+54, 206754, 732, 1, 1, 87.07118, 1236.28, 4.203345, 5.759588, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+55, 202780, 732, 1, 1, 103.0295, 1081.29, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+56, 206754, 732, 1, 1, 140.9774, 1121.01, 1.102629, 2.513274, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+57, 202780, 732, 1, 1, 152.3767, 1208.66, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
(@OGUID+58, 206754, 732, 1, 1, 136.4149, 1219.51, 1.662149, 0.6283169, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Rustberg Village)
-- (@OGUID+59, 35591, 732, 1, 1, -92.24333, 1413.403, 0, 5.485636, 0, 0, 0, 1, 7200, 255, 1), -- Fishing Bobber (Area: Rustberg Village) - !!! might be temporary spawn !!!
(@OGUID+59, 202747, 732, 1, 1, -227.1215, 1417.387, 22.58164, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+60, 202780, 732, 1, 1, -391.3524, 1219.71, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Darkwood)
(@OGUID+61, 202747, 732, 1, 1, -312.184, 1131.299, 22.35404, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Darkwood)
(@OGUID+62, 207703, 732, 1, 1, -376.8177, 1052.681, 21.9242, 4.852017, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+63, 207704, 732, 1, 1, -372.2726, 1050.51, 21.98582, 3.752462, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+64, 206885, 732, 1, 1, -328.7101, 1044.45, 22.0359, 2.713986, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+65, 208227, 732, 1, 1, -343.9358, 1030.188, 22.28196, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+66, 202780, 732, 1, 1, -394.5556, 1001.271, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Baradin Base Camp)
(@OGUID+67, 164764, 732, 1, 1, -404.6908, 942.1985, 4.073777, 1.911136, 0, 0, 0.1779436, 0.9840407, 7200, 255, 1), -- Wooden Chair (Area: Baradin Base Camp)
(@OGUID+68, 164766, 732, 1, 1, -414.2343, 948.0369, 4.07617, 1.029743, 0, 0, 0.1779436, 0.9840407, 7200, 255, 1), -- Wooden Chair (Area: Baradin Base Camp)
(@OGUID+69, 164765, 732, 1, 1, -413.5508, 949.3995, 4.07617, 4.24988, 0, 0, 0.1779436, 0.9840407, 7200, 255, 1), -- Wooden Chair (Area: Baradin Base Camp)
(@OGUID+70, 164763, 732, 1, 1, -405.3872, 943.8382, 4.073777, 5.131269, 0, 0, 0.1779436, 0.9840407, 7200, 255, 1), -- Wooden Chair (Area: Baradin Base Camp)
(@OGUID+71, 164761, 732, 1, 1, -401.3389, 941.6107, 4.073636, 4.24988, 0, 0, 0.1779436, 0.9840407, 7200, 255, 1), -- Wooden Chair (Area: Baradin Base Camp)
(@OGUID+72, 164760, 732, 1, 1, -397.9073, 944.2126, 4.040835, 4.24988, 0, 0, 0.1779436, 0.9840407, 7200, 255, 1), -- Wooden Chair (Area: Baradin Base Camp)
(@OGUID+73, 164767, 732, 1, 1, -377.3166, 948.7185, 4.075095, 3.036875, 0, 0, 0.1779436, 0.9840407, 7200, 255, 1), -- Wooden Chair (Area: Baradin Base Camp)
(@OGUID+74, 164759, 732, 1, 1, -398.7304, 942.6029, 4.040835, 1.029743, 0, 0, 0.1779436, 0.9840407, 7200, 255, 1), -- Wooden Chair (Area: Baradin Base Camp)
(@OGUID+75, 164762, 732, 1, 1, -402.1999, 939.9713, 4.073636, 1.029743, 0, 0, 0.1779436, 0.9840407, 7200, 255, 1), -- Wooden Chair (Area: Baradin Base Camp)
(@OGUID+76, 202749, 732, 1, 1, -448.3455, 1333.451, -6.360816, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Darkwood)
(@OGUID+77, 207724, 732, 1, 1, -249.5868, 1541.319, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Darkwood)
(@OGUID+78, 202749, 732, 1, 1, -283.783, 1554.434, -6.282889, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Darkwood)
(@OGUID+79, 202747, 732, 1, 1, -139.9809, 1538.045, 21.47281, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Darkwood)
(@OGUID+80, 207716, 732, 1, 1, -96.8559, 1867.15, 13.9979, 4.66003, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Darkwood)
(@OGUID+81, 207716, 732, 1, 1, -94.5399, 1869.47, 13.9239, 5.916668, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Darkwood)
(@OGUID+82, 207716, 732, 1, 1, -194.285, 1925.24, 2.81094, 2.82743, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Darkwood)
(@OGUID+83, 207716, 732, 1, 1, -207.589, 1896.11, 2.3826, 3.874631, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Darkwood)
(@OGUID+84, 206664, 732, 1, 1, -66.93056, 1596.142, 27.28064, 0.8726639, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+85, 206664, 732, 1, 1, -123.1042, 1680.688, 29.57866, 6.213374, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+86, 206664, 732, 1, 1, -120.2604, 1652.42, 27.76172, 0.8726639, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+87, 207716, 732, 1, 1, -62.6597, 1918.07, 14.0297, 0.1919852, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+88, 207716, 732, 1, 1, -62.1615, 1915.08, 13.7665, 0.9599299, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+89, 206664, 732, 1, 1, -39.63889, 1592.813, 29.65249, 1.483528, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+90, 206664, 732, 1, 1, -39.13195, 1658.207, 27.58644, 3.769912, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+91, 206664, 732, 1, 1, -57.87674, 1680.672, 27.79076, 3.769912, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+92, 206664, 732, 1, 1, -13.90104, 1652.972, 29.45147, 4.118979, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+93, 206664, 732, 1, 1, -60.20139, 1701.432, 29.57583, 2.949595, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+94, 202747, 732, 1, 1, -1.039931, 1617.129, 28.80552, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+95, 206664, 732, 1, 1, 7.102431, 1608.443, 27.61919, 2.18166, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+96, 202741, 732, 1, 1, 9.934028, 1655.38, 28.99449, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+97, 206664, 732, 1, 1, -58.72743, 1734.165, 29.46476, 2.932139, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+98, 206664, 732, 1, 1, 8.43924, 1692.12, 37.44, 0.6806767, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+99, 206664, 732, 1, 1, 10.1493, 1690.76, 58.52, 0.6806767, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+100, 206664, 732, 1, 1, -25.2465, 1731.19, 37.4399, 0.6806767, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+101, 206664, 732, 1, 1, 10.9931, 1700.43, 37.4613, 2.268925, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+102, 206664, 732, 1, 1, -19.0122, 1724.37, 58.52, 0.7155849, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+103, 206664, 732, 1, 1, 38.98264, 1644.806, 29.64439, 3.543024, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+104, 206664, 732, 1, 1, -9.27604, 1723.71, 37.4613, 5.375615, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+105, 206664, 732, 1, 1, 25.0608, 1690.15, 58.52, 2.251473, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+106, 206664, 732, 1, 1, 17.8368, 1707.32, 37.4621, 0.6981314, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+107, 206664, 732, 1, 1, -1.57292, 1729.45, 37.4625, 0.6981314, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+108, 206664, 732, 1, 1, 28.3281, 1696.52, 37.4429, 0.6806767, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+109, 206580, 732, 1, 1, 88.01215, 1589.146, 0.07608081, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+110, 202741, 732, 1, 1, 37.18576, 1585.161, 6.402588, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+111, 206664, 732, 1, 1, 53.6076, 1718.91, 37.4382, 0.6981314, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+112, 206664, 732, 1, 1, 64.9149, 1723.63, 45.569, 2.286379, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+113, 206664, 732, 1, 1, -4.65799, 1734.37, 37.444, 0.6806767, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+114, 206664, 732, 1, 1, -110.25, 1730.969, 27.28255, 5.515242, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+115, 206664, 732, 1, 1, -17.4566, 1739.06, 58.5202, 5.445428, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+116, 206664, 732, 1, 1, -76.23264, 1753.302, 31.83993, 5.864307, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+117, 206583, 732, 1, 1, -108.601, 1845.73, 13.6954, 3.071766, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+118, 206664, 732, 1, 1, 15.559, 1762.53, 37.4377, 0.7155849, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+119, 206664, 732, 1, 1, 22.8472, 1750.36, 37.4438, 3.822273, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+120, 206664, 732, 1, 1, 42.467, 1739.04, 58.5218, 5.480334, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+121, 206664, 732, 1, 1, 33.0642, 1749.72, 58.5217, 2.164206, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+122, 206664, 732, 1, 1, 29.566, 1762.27, 37.4399, 2.268925, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+123, 207549, 732, 1, 1, 48.96424, 1742.969, 46.78454, 5.951573, 0, 0, 0.9366722, -0.3502074, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+124, 207550, 732, 1, 1, 38.09995, 1755.505, 46.78454, 4.97419, 0, 0, 0.9366722, -0.3502074, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+125, 206664, 732, 1, 1, 58.1424, 1735.35, 37.4399, 5.358162, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+126, 206664, 732, 1, 1, 37.8559, 1760.52, 46.803, 4.782203, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+127, 206664, 732, 1, 1, 54.0677, 1742.06, 46.8023, 2.82743, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+128, 206664, 732, 1, 1, 31.0417, 1764.13, 58.5194, 2.303831, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+129, 206664, 732, 1, 1, 59.4427, 1734.37, 58.5203, 3.804818, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Farson Hold)
(@OGUID+130, 202749, 732, 1, 1, -229.4948, 1656.191, -4.808856, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+131, 206580, 732, 1, 1, 19.94965, 1494.582, 2.352138, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+132, 206580, 732, 1, 1, 34.5938, 1460.83, -6.31697, 1.361356, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+133, 206580, 732, 1, 1, 78.5712, 1469.15, -9.89081, 5.480334, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+134, 206580, 732, 1, 1, 82.75174, 1498.104, -5.451673, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+135, 206580, 732, 1, 1, 41.83507, 1538.469, 4.342935, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+136, 202780, 732, 1, 1, 73.93229, 1528.141, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+137, 206580, 732, 1, 1, 114.314, 1518.6, -6.38976, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+138, 206580, 732, 1, 1, 112.9931, 1486.068, -6.310522, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+139, 206580, 732, 1, 1, 135.042, 1560.56, -12.0831, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+140, 206580, 732, 1, 1, 179.4254, 1574.797, -10.40857, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+141, 206580, 732, 1, 1, 157.4444, 1533.111, -12.26408, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+142, 206580, 732, 1, 1, 161.276, 1616.8, -7.306, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+143, 202749, 732, 1, 1, 167.1424, 1612.976, -9.270833, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+144, 206580, 732, 1, 1, 234.191, 1580.73, -16.1448, 5.951575, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+145, 206580, 732, 1, 1, 216.269, 1574.73, -11.5088, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+146, 202749, 732, 1, 1, 206.2448, 1595.826, -12.76932, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+147, 206580, 732, 1, 1, 211.689, 1688.82, -22.1877, 4.06662, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+148, 206580, 732, 1, 1, 163.545, 1698.61, -11.4646, 4.06662, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+149, 206580, 732, 1, 1, 188.991, 1712.81, -19.1486, 4.06662, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+150, 206580, 732, 1, 1, 178.047, 1648.05, -9.91467, 4.06662, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+151, 206580, 732, 1, 1, 178.786, 1630.94, -7.24247, 2.879789, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+152, 206580, 732, 1, 1, 162.283, 1663.835, -10.32674, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+153, 206580, 732, 1, 1, 209.783, 1510.153, -10.27767, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+154, 206580, 732, 1, 1, 170.238, 1487.49, -12.6889, 1.012289, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+155, 202749, 732, 1, 1, 89.29514, 1467.741, -9.804599, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+156, 206580, 732, 1, 1, 138.5208, 1454.811, -7.893365, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+157, 206580, 732, 1, 1, 254.108, 1525.61, -28.2399, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+158, 206580, 732, 1, 1, 195.903, 1474.99, -10.2067, 2.949595, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+159, 202749, 732, 1, 1, 239.6181, 1491.997, -22.47233, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+160, 206580, 732, 1, 1, 275.495, 1529.05, -15.9509, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+161, 206580, 732, 1, 1, 277.799, 1544.24, -32.133, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+162, 206580, 732, 1, 1, 168.832, 1420.79, -13.0249, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+163, 202749, 732, 1, 1, 153.5833, 1430.668, -11.04887, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+164, 206580, 732, 1, 1, 107.509, 1445.16, -11.856, 1.954769, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Cape of Lost Hope)
(@OGUID+165, 206583, 732, 1, 1, -147.245, 1839.2, 3.10274, 4.031712, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+166, 206583, 732, 1, 1, -200.618, 1867.78, 3.00177, 2.792518, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+167, 206583, 732, 1, 1, -129.592, 1876.84, 2.99581, 5.096362, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+168, 206583, 732, 1, 1, -225.821, 1892.91, 12.6755, 4.485497, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+169, 206583, 732, 1, 1, -101.743, 1899.6, 14.1007, 0.5934101, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+170, 206583, 732, 1, 1, -113.809, 1913.78, 2.89415, 4.24115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+171, 206583, 732, 1, 1, -216.807, 1920.87, 2.64486, 0.01745246, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+172, 206583, 732, 1, 1, -196.503, 1936.2, 2.53666, 1.343901, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+173, 206583, 732, 1, 1, -135.9688, 1950.458, 2.32739, 4.206246, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+174, 206583, 732, 1, 1, -184.2656, 1954.401, 1.565051, 5.113817, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+175, 206583, 732, 1, 1, -97.7674, 1938.15, 13.5394, 1.448622, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+176, 206583, 732, 1, 1, -110.47, 1952.22, 2.73792, 4.084071, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+177, 202749, 732, 1, 1, -279.1528, 1834.179, -5.384383, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+178, 202747, 732, 1, 1, -247.0087, 1947.069, 12.9328, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+179, 206583, 732, 1, 1, -214.774, 1999.99, 6.94609, 1.483528, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+180, 206583, 732, 1, 1, -214.606, 1976.63, 2.88317, 4.747296, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+181, 206583, 732, 1, 1, -254.328, 1972.21, 2.88355, 3.001947, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+182, 206583, 732, 1, 1, -250.273, 1931.22, 12.6755, 4.485497, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+183, 206583, 732, 1, 1, -220.759, 1961.44, 12.7739, 6.213374, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+184, 202780, 732, 1, 1, -221.1233, 1999.84, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+185, 202780, 732, 1, 1, -162.5347, 1979.319, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+186, 206583, 732, 1, 1, -107.552, 1974.31, 3.16574, 3.089183, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+187, 202780, 732, 1, 1, -133.1649, 1996.109, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+188, 202780, 732, 1, 1, -217.4392, 2031.53, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+189, 206583, 732, 1, 1, -67.1597, 2000.84, 7.22967, 4.677484, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+190, 207463, 732, 1, 1, -54.64775, 1917.226, 16.03462, 4.843289, 0, 0, 0.9978589, -0.06540316, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+191, 206583, 732, 1, 1, -48.9965, 1954, 13.7509, 2.495818, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+192, 202780, 732, 1, 1, -45.73264, 1989.76, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+193, 202747, 732, 1, 1, -49.71007, 1948.488, 14.03951, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Wellson Shipyard)
(@OGUID+194, 206570, 732, 1, 1, -499.677, 1723.18, 47.8404, 0.03490625, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Restless Front)
(@OGUID+195, 206570, 732, 1, 1, -500.257, 1681.01, 46.9641, 5.916668, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Restless Front)
(@OGUID+196, 202747, 732, 1, 1, -416.1076, 1589.439, 23.65213, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Restless Front)
(@OGUID+197, 202747, 732, 1, 1, -540.3264, 1511.375, 25.28691, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+198, 202738, 732, 1, 1, -500.1233, 1560.696, 23.35341, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+199, 206570, 732, 1, 1, -573.229, 1629.49, 47.4837, 3.508117, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+200, 206570, 732, 1, 1, -669.566, 1722.95, 49.8013, 0.1396245, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+201, 206906, 732, 1, 1, -624.5018, 1686.54, 48.4043, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+202, 206570, 732, 1, 1, -646.337, 1679.91, 48.7341, 0.6981314, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+203, 206570, 732, 1, 1, -593.408, 1680.1, 53.7031, 4.76475, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+204, 206570, 732, 1, 1, -657.59, 1785.86, 53.2631, 2.513274, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+205, 206570, 732, 1, 1, -569.957, 1828.58, 49.7116, 4.01426, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+206, 206570, 732, 1, 1, -619.946, 1861.73, 48.0281, 2.775069, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+207, 206570, 732, 1, 1, -633.54, 1808.26, 54.4899, 1.745327, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+208, 202747, 732, 1, 1, -593.0521, 1791.821, 62.11303, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+209, 202741, 732, 1, 1, -630.0989, 1869.866, 48.19855, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+210, 206570, 732, 1, 1, -543.089, 1813.22, 51.8436, 4.607672, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+211, 206570, 732, 1, 1, -550.5, 1774.53, 61.6969, 3.455756, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+212, 206570, 732, 1, 1, -556.799, 1863.99, 47.1859, 2.234018, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+213, 206570, 732, 1, 1, -551.245, 1737.67, 59.1806, 5.759588, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+214, 206570, 732, 1, 1, -524.391, 1831.32, 46.8172, 4.677484, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+215, 206570, 732, 1, 1, -495.79, 1826.81, 46.5582, 5.061456, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+216, 206570, 732, 1, 1, -560.288, 1917.43, 48.3182, 2.199115, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+217, 202747, 732, 1, 1, -542.9965, 1929.236, 48.84795, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+218, 202780, 732, 1, 1, -643.4427, 1945.601, 0, 3.141593, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+219, 206570, 732, 1, 1, -516.941, 1928.25, 48.4046, 2.286379, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+220, 206570, 732, 1, 1, -498.538, 1886.81, 46.843, 4.729844, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+221, 206570, 732, 1, 1, -467.832, 1859.5, 46.9634, 4.834563, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+222, 206570, 732, 1, 1, -461.568, 1938.52, 49.7012, 1.570796, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+223, 206570, 732, 1, 1, -435.47, 1935.91, 50.9243, 1.518436, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+224, 206570, 732, 1, 1, -437.97, 1859.05, 47.2761, 5.916668, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+225, 206570, 732, 1, 1, -431.13, 1904.49, 48.8493, 0.3490652, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+226, 206570, 732, 1, 1, -397.236, 1890.31, 51.2995, 5.93412, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+227, 206570, 732, 1, 1, -445.958, 1824.12, 47.0099, 5.619962, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+228, 206570, 732, 1, 1, -469.252, 1829.56, 46.4278, 5.358162, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+229, 206570, 732, 1, 1, -456.24, 1796.72, 47.558, 5.166176, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+230, 206570, 732, 1, 1, -487.22, 1793.56, 47.8311, 3.979355, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+231, 206570, 732, 1, 1, -515.429, 1782.74, 50.3623, 3.368496, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+232, 206570, 732, 1, 1, -527.182, 1738.27, 52.8152, 5.742135, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+233, 206570, 732, 1, 1, -549.215, 1695.72, 53.1905, 5.235988, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+234, 206570, 732, 1, 1, -523.049, 1678.04, 48.1368, 1.308995, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Forgotten Hill)
(@OGUID+235, 206883, 732, 1, 1, -602.8611, 1433.04, 22.0059, 1.937312, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Hellscream's Grasp)
(@OGUID+236, 206884, 732, 1, 1, -600.8108, 1402.189, 19.7069, 4.860743, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Hellscream's Grasp)
(@OGUID+237, 208226, 732, 1, 1, -598.7656, 1377.974, 21.91898, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Hellscream's Grasp)
(@OGUID+238, 207706, 732, 1, 1, -605.5816, 1380.351, 21.9965, 2.495818, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Hellscream's Grasp)
(@OGUID+239, 207705, 732, 1, 1, -610.4271, 1379.63, 22.0371, 3.647738, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: Hellscream's Grasp)
(@OGUID+240, 202741, 732, 1, 1, -535.4896, 1142.139, 89.60479, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+241, 202747, 732, 1, 1, -544.9774, 1169.057, 89.61136, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+242, 202747, 732, 1, 1, -396.7188, 1181.056, 15.92825, 0, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+243, 207701, 732, 1, 1, -585.7222, 1091.8, 97.2338, 3.516848, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: 0)
(@OGUID+244, 207702, 732, 1, 1, -565.7518, 1221.899, 92.6479, 4.01722, 0, 0, 0, 1, 7200, 255, 1); -- -Unknown- (Area: 0)

UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47183; -- Ghastly Worker
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `faction_A`=190, `faction_H`=190, `speed_walk`=1.385714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=46645; -- Cursed Stallion
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1.111112, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47181; -- Overlook Spirit
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1.111112, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47182; -- Overlook Spectre
UPDATE `creature_template` SET `HoverHeight`=1 WHERE `entry`=1412; -- Squirrel
UPDATE `creature_template` SET `faction_A`=31, `faction_H`=31, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=47667; -- Wharf Rat
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47657; -- Suspicious Villager
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_walk`=1.285714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=47666; -- Rustberg Horse
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47659; -- Apprehensive Worker
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=46608; -- Tank
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47304; -- Commander Largo
UPDATE `creature_template` SET `faction_A`=32, `faction_H`=32, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=47682; -- Sassy Cat
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47627; -- Rustberg Bandit
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2354, `faction_H`=2354, `speed_walk`=1.385714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47373; -- Warden's Sentry
UPDATE `creature_template` SET `maxlevel`=5, `faction_A`=190, `faction_H`=190, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=47680; -- Rustberg Gull
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47287; -- Captain P. Harris
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=634, `faction_H`=634, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=46606; -- Spiny Tidecrawler
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47642; -- Rustberg Fisherman
UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=84, `faction_A`=190, `faction_H`=190, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47676; -- Baradin Fox
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=4, `HoverHeight`=1 WHERE `entry`=46605; -- Shipwrecked Sailor
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=22, `faction_H`=22, `speed_walk`=1.190476, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `dynamicflags`=4, `HoverHeight`=1 WHERE `entry`=46508; -- Darkwood Lurker
UPDATE `creature_template` SET `faction_A`=634, `faction_H`=634, `speed_walk`=0.8571429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=46509; -- Darkwood Hatchling
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=22, `faction_H`=22, `speed_walk`=1.190476, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=46507; -- Darkwood Broodmother
UPDATE `creature_template` SET `gossip_menu_id`=12420, `minlevel`=85, `maxlevel`=85, `faction_A`=2354, `faction_H`=2354, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=47240; -- Commander Marcus Johnson
UPDATE `creature_template` SET `gossip_menu_id`=12419, `minlevel`=85, `maxlevel`=85, `faction_A`=2354, `faction_H`=2354, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=48255; -- Camp Coordinator Brack
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2354, `faction_H`=2354, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=48252; -- Baradin Recruit
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2376, `faction_H`=2376, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=48253; -- Baradin Guard
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2354, `faction_H`=2354, `npcflag`=128, `speed_walk`=1.385714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=47328; -- Quartermaster Brazie
UPDATE `creature_template` SET `gossip_menu_id`=12421, `minlevel`=85, `maxlevel`=85, `faction_A`=2354, `faction_H`=2354, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=48254; -- Sergeant Gray
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2354, `faction_H`=2354, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=51288; -- Major Marsden
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2354, `faction_H`=2354, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=48251; -- Kevin Geissler
UPDATE `creature_template` SET `gossip_menu_id`=12422, `minlevel`=85, `maxlevel`=85, `faction_A`=2354, `faction_H`=2354, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=48250; -- Lieutenant Farnsworth
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=12, `faction_H`=12, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=50161; -- Dar Rummond
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2354, `faction_H`=2354, `npcflag`=3, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=52015; -- Captain Jake Sones
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2355, `faction_H`=2355, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47428; -- Hellscream's Sentry
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33555200, `HoverHeight`=1 WHERE `entry`=47402; -- Tol Barad - The Restless Front - Quest Bunny
UPDATE `creature_template` SET `minlevel`=60, `maxlevel`=60, `speed_walk`=1.285714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=48325; -- Farson Horse
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=46989; -- Crazed Soldier
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432, `HoverHeight`=1 WHERE `entry`=32780; -- Invisible Stalker (All Phases)
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47130; -- Crazed Guard
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=534, `faction_H`=534, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=48308; -- Farson Hold Prisoner
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=534, `faction_H`=534, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=49455; -- Dehydrated Prisoner
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=714, `faction_H`=714, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=48309; -- Farson Hold Prisoner
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=46630; -- Accursed Longshoreman
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=16, `faction_H`=16, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=47447; -- Keep Lord Farson
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=46643; -- Accursed Shipbuilder
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=46641; -- Ghastly Dockhand
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.385714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32832, `HoverHeight`=1 WHERE `entry`=46648; -- Foreman Wellson
UPDATE `creature_template` SET `minlevel`=28, `maxlevel`=28, `speed_walk`=1.071429, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `VehicleId`=1314, `HoverHeight`=1 WHERE `entry`=48283; -- Wellson Cannon
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=46823; -- Restless Infantry
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=14, `faction_H`=14, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=46825; -- Restless Soldier
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=189, `faction_H`=189, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_flags`=33280, `HoverHeight`=1 WHERE `entry`=46960; -- Ghastly Scavenger
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=974, `faction_H`=974, `speed_walk`=1.142857, `speed_run`=0.777776, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=46569; -- Forgotten Ghoul
UPDATE `creature_template` SET `minlevel`=50, `maxlevel`=54, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_flags`=512, `HoverHeight`=1 WHERE `entry`=46581; -- Violated Corpse
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2355, `faction_H`=2355, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=48357; -- Hellscream's Reach Recruit
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2377, `faction_H`=2377, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=48355; -- Hellscream Guard
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2102, `faction_H`=2102, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=46586; -- Wandering Soul
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554432, `HoverHeight`=1 WHERE `entry`=45492; -- Tower Range Finder
UPDATE `creature_template` SET `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33554688, `HoverHeight`=1 WHERE `entry`=45561; -- Tower Cannon Target
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=21, `faction_H`=21, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=1500, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=46597; -- Skeletal Beastmaster
UPDATE `creature_template` SET `minlevel`=83, `maxlevel`=83, `faction_A`=38, `faction_H`=38, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=32768, `HoverHeight`=1 WHERE `entry`=46570; -- Putrid Worg
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=974, `faction_H`=974, `speed_walk`=1.142857, `speed_run`=0.777776, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=46582; -- Hungry Ghoul
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=974, `faction_H`=974, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `HoverHeight`=1 WHERE `entry`=46571; -- First Lieutenant Connor
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2355, `faction_H`=2355, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=48358; -- Commander Larmash
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2355, `faction_H`=2355, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=48363; -- Captain Prug
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2355, `faction_H`=2355, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=48361; -- Private Sarlosk
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2355, `faction_H`=2355, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=51287; -- Colonel Karzag
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2355, `faction_H`=2355, `npcflag`=128, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=48531; -- Pogg
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2355, `faction_H`=2355, `npcflag`=3, `speed_walk`=1.385714, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=768, `HoverHeight`=1 WHERE `entry`=52016; -- Petty Officer Chulok
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2355, `faction_H`=2355, `npcflag`=2, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=48360; -- 3rd Officer Kronkar
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=2355, `faction_H`=2355, `npcflag`=4224, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=48356; -- Karosh
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=29, `faction_H`=29, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=8, `unit_flags`=33536, `HoverHeight`=1 WHERE `entry`=50164; -- Tulgar Flamefist
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=83, `faction_H`=83, `npcflag`=32769, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=832, `HoverHeight`=1 WHERE `entry`=45067; -- Horde Spirit Guide
UPDATE `creature_template` SET `minlevel`=85, `maxlevel`=85, `faction_A`=84, `faction_H`=84, `npcflag`=32769, `speed_walk`=1.142857, `speed_run`=1, `baseattacktime`=2000, `rangeattacktime`=2000, `unit_class`=2, `unit_flags`=832, `HoverHeight`=1 WHERE `entry`=45066; -- Alliance Spirit Guide


DELETE FROM `creature_template_addon` WHERE `entry` IN (47183, 46645, 47181, 47182, 1412, 1412, 46645, 47181, 47667, 47657, 47666, 47666, 47667, 47659, 47657, 46608, 46645, 47181, 47181, 47181, 47183, 47304, 47181, 47182, 47182, 47183, 47183, 47183, 47182, 47182, 46645, 47183, 47183, 47182, 47181, 47181, 47182, 47181, 47183, 47183, 46645, 46645, 47183, 47182, 47682, 47657, 47666, 47666, 47667, 47657, 47667, 47682, 47667, 47659, 47659, 47659, 47657, 47667, 47657, 47627, 47659, 47627, 47657, 47666, 47666, 47667, 47659, 47627, 47666, 47659, 47659, 47657, 47657, 47659, 47373, 47373, 47373, 47666, 47666, 47680, 47657, 47667, 47682, 47680, 47657, 47682, 47667, 47659, 47287, 46606, 47680, 47680, 47680, 47627, 47657, 47657, 47657, 47680, 47667, 47680, 47666, 47680, 47666, 47642, 47666, 47642, 47642, 47680, 47680, 47680, 47680, 47642, 47680, 47680, 47682, 47680, 47680, 47667, 47680, 47680, 47642, 47667, 47680, 47642, 47627, 47642, 47659, 47627, 46606, 47676, 46605, 46508, 46509, 46509, 46509, 46509, 46509, 46509, 46509, 46509, 46509, 46508, 46507, 46507, 46509, 47676, 46509, 46509, 46509, 46509, 46508, 46508, 46507, 46509, 46509, 46508, 46509, 46509, 46509, 46509, 46509, 46509, 46507, 47676, 46509, 46508, 46509, 46507, 46509, 46509, 46509, 46509, 46509, 46509, 1412, 46509, 46508, 46508, 46509, 46509, 46509, 46509, 46509, 46509, 46509, 46509, 46508, 46509, 1412, 46507, 46509, 46507, 46508, 46509, 46507, 46508, 46509, 46509, 46509, 46509, 46509, 46509, 46508, 46509, 46509, 46507, 46509, 1412, 46509, 46509, 46508, 46508, 46509, 46508, 46509, 46508, 46509, 46509, 46508, 46509, 46509, 46509, 46507, 46508, 46507, 46509, 46509, 46509, 1412, 46508, 47676, 47240, 48255, 48252, 48253, 48252, 47328, 48252, 48252, 48254, 48252, 48253, 48253, 48253, 48253, 1412, 48252, 48252, 51288, 48251, 48250, 50161, 48252, 48252, 48252, 48253, 52015, 48253, 48253, 48253, 1412, 48252, 48253, 48253, 46509, 46509, 46508, 47676, 46508, 46509, 1412, 47676, 47428, 46606, 47676, 46605, 47402, 47402, 1412, 47428, 47428, 48325, 48325, 46989, 46989, 46989, 46989, 46989, 32780, 46989, 47130, 47130, 46989, 46989, 46989, 46989, 46989, 46989, 47130, 47130, 47130, 47130, 47130, 46989, 46989, 46605, 46605, 46605, 46605, 48308, 49455, 49455, 49455, 47130, 47130, 46989, 46605, 46989, 47130, 46989, 46989, 49455, 48309, 46605, 47428, 1412, 47676, 46630, 46989, 46989, 47130, 47130, 46989, 46989, 46989, 47447, 47130, 47130, 46989, 46606, 46605, 46605, 46605, 46606, 46606, 46606, 46606, 46605, 46606, 46606, 46606, 46606, 46605, 46606, 46606, 46606, 46606, 46606, 46606, 46606, 47676, 47676, 46606, 46606, 46606, 1412, 46606, 47676, 46630, 46630, 46630, 46630, 46643, 46641, 46630, 46643, 46641, 46643, 46630, 46643, 46648, 46643, 46643, 46630, 46645, 46643, 46643, 46645, 46645, 46630, 46641, 46641, 46643, 46630, 46643, 46630, 46630, 46630, 46645, 46643, 46645, 46645, 46630, 46645, 46630, 46630, 48283, 48283, 48283, 48283, 48283, 46630, 48283, 48283, 48283, 46630, 47676, 47402, 47402, 47402, 47402, 47402, 46823, 46825, 47402, 47402, 47402, 47402, 47402, 47402, 47402, 47402, 47402, 47402, 47402, 47402, 46825, 46823, 47402, 47402, 47402, 46823, 46825, 1412, 47402, 47402, 47402, 46823, 46825, 47402, 47402, 47402, 47402, 46960, 47402, 47402, 47402, 47402, 47402, 46823, 46825, 47402, 47402, 47402, 47402, 47402, 47402, 47402, 47402, 1412, 47402, 47402, 47402, 47402, 47402, 46960, 46569, 46581, 47402, 47402, 46823, 47402, 46825, 47402, 47402, 47402, 47402, 47402, 47402, 46960, 47402, 46823, 47402, 47402, 46825, 47402, 46960, 47402, 47402, 47402, 47402, 47402, 47402, 47402, 47402, 47402, 47402, 46960, 46960, 46825, 46823, 47402, 47402, 47402, 1412, 47402, 47676, 47402, 1412, 47676, 47402, 47402, 1412, 48357, 48355, 48355, 48355, 47676, 46586, 46569, 46569, 45492, 45561, 46586, 46569, 46569, 46586, 46597, 46570, 46569, 46586, 45561, 45561, 45561, 45561, 46569, 46569, 46586, 46586, 46569, 46569, 46569, 46569, 46569, 46569, 46569, 46586, 46597, 46570, 46597, 46570, 46581, 46581, 46581, 46569, 46569, 46586, 46582, 46569, 46569, 46586, 46569, 46569, 46569, 46569, 46582, 46586, 46581, 46569, 46581, 46571, 46569, 46597, 46570, 47402, 47402, 47402, 46825, 47402, 47402, 47402, 46823, 47402, 47402, 47402, 46825, 47402, 48357, 48357, 48355, 48355, 48357, 48358, 48363, 48355, 48361, 51287, 48355, 48355, 48531, 52016, 48360, 48356, 50164, 48357, 48355, 45067, 45066, 47676, 47676, 47676, 47182, 47183, 47183, 47182, 47181, 47181, 48252, 48252, 48252, 48253, 48253, 48357, 48357, 48355, 48355, 48355);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(47183, 0, 0x0, 0x1, '33900'), -- Ghastly Worker - Shroud of Death
(46645, 0, 0x0, 0x1, '33900'), -- Cursed Stallion - Shroud of Death
(47181, 0, 0x0, 0x1, '33900'), -- Overlook Spirit - Shroud of Death
(47182, 0, 0x0, 0x1, '33900'), -- Overlook Spectre - Shroud of Death
(1412, 0, 0x0, 0x1, ''), -- Squirrel
(47667, 0, 0x0, 0x1, ''), -- Wharf Rat
(47657, 0, 0x0, 0x1, ''), -- Suspicious Villager
(47666, 0, 0x0, 0x1, ''), -- Rustberg Horse
(47659, 0, 0x0, 0x1, ''), -- Apprehensive Worker
(46608, 0, 0x0, 0x1, ''), -- Tank
(47304, 0, 0x0, 0x1, '33900'), -- Commander Largo - Shroud of Death
(47682, 0, 0x0, 0x1, ''), -- Sassy Cat
(47627, 0, 0x20000, 0x1, '10022 77806'), -- Rustberg Bandit - Deadly Poison, Stealth
-- (47373, 28912, 0x0, 0x1, ''), -- Warden's Sentry
(47373, 0, 0x0, 0x1, ''), -- Warden's Sentry
(47680, 0, 0x3000000, 0x1, ''), -- Rustberg Gull
(47287, 0, 0x0, 0x1, ''), -- Captain P. Harris
(46606, 0, 0x0, 0x1, ''), -- Spiny Tidecrawler
-- (47657, 0, 0x0, 0x1, '79877'), -- Suspicious Villager - Bloodthirst
-- (47680, 0, 0x3000001, 0x1, ''), -- Rustberg Gull
(47642, 0, 0x0, 0x1, '34827'), -- Rustberg Fisherman - Water Shield
(47676, 0, 0x0, 0x1, ''), -- Baradin Fox
(46605, 0, 0x0, 0x1, ''), -- Shipwrecked Sailor
(46508, 0, 0x0, 0x1, '13886'), -- Darkwood Lurker - Withering Poison Proc
(46509, 0, 0x0, 0x1, ''), -- Darkwood Hatchling
(46507, 0, 0x0, 0x1, ''), -- Darkwood Broodmother
(47240, 0, 0x0, 0x1, ''), -- Commander Marcus Johnson
(48255, 0, 0x0, 0x1, ''), -- Camp Coordinator Brack
(48252, 0, 0x0, 0x1, ''), -- Baradin Recruit
-- (48253, 0, 0x0, 0x101, ''), -- Baradin Guard
(47328, 28912, 0x0, 0x1, ''), -- Quartermaster Brazie
-- (48252, 0, 0x8, 0x1, ''), -- Baradin Recruit
(48254, 0, 0x0, 0x1, ''), -- Sergeant Gray
(48253, 0, 0x0, 0x100, ''), -- Baradin Guard
(51288, 0, 0x0, 0x1, ''), -- Major Marsden
(48251, 0, 0x0, 0x1, ''), -- Kevin Geissler
(48250, 0, 0x0, 0x1, ''), -- Lieutenant Farnsworth
(50161, 0, 0x0, 0x1, '32783'), -- Dar Rummond - Arcane Channeling
(52015, 0, 0x0, 0x1, ''), -- Captain Jake Sones
-- (48253, 0, 0x1, 0x101, ''), -- Baradin Guard
(47428, 0, 0x0, 0x1, ''), -- Hellscream's Sentry
-- (46605, 0, 0x0, 0x1, '84305'), -- Shipwrecked Sailor - Soaking Wet
(47402, 0, 0x0, 0x1, ''), -- Tol Barad - The Restless Front - Quest Bunny
-- (47428, 29283, 0x0, 0x1, ''), -- Hellscream's Sentry
(48325, 0, 0x0, 0x1, ''), -- Farson Horse
-- (46989, 0, 0x0, 0x1, '81219'), -- Crazed Soldier - Battle Shout
(46989, 0, 0x0, 0x1, ''), -- Crazed Soldier
(32780, 0, 0x0, 0x1, ''), -- Invisible Stalker (All Phases)
-- (47130, 0, 0x0, 0x2, ''), -- Crazed Guard
(48308, 0, 0x0, 0x1, ''), -- Farson Hold Prisoner
(49455, 0, 0x0, 0x1, ''), -- Dehydrated Prisoner
(47130, 0, 0x0, 0x1, ''), -- Crazed Guard
(48309, 0, 0x0, 0x1, ''), -- Farson Hold Prisoner
(46630, 0, 0x0, 0x1, '33900'), -- Accursed Longshoreman - Shroud of Death
(47447, 0, 0x0, 0x1, ''), -- Keep Lord Farson
(46643, 0, 0x0, 0x1, '33900'), -- Accursed Shipbuilder - Shroud of Death
(46641, 0, 0x0, 0x1, '33900'), -- Ghastly Dockhand - Shroud of Death
-- (46641, 0, 0x0, 0x1, '33900 77409'), -- Ghastly Dockhand - Shroud of Death, Sandbag
(46648, 37259, 0x0, 0x1, '33900'), -- Foreman Wellson - Shroud of Death
(48283, 0, 0x0, 0x1, ''), -- Wellson Cannon
(46823, 0, 0x0, 0x1, '33900'), -- Restless Infantry - Shroud of Death
(46825, 0, 0x0, 0x1, '33900'), -- Restless Soldier - Shroud of Death
(46960, 0, 0x0, 0x1, '33900'), -- Ghastly Scavenger - Shroud of Death
-- (46960, 37159, 0x0, 0x1, '33900'), -- Ghastly Scavenger - Shroud of Death
(46569, 0, 0x0, 0x1, ''), -- Forgotten Ghoul
(46581, 0, 0x7, 0x1, ''), -- Violated Corpse
(48357, 0, 0x0, 0x1, ''), -- Hellscream's Reach Recruit
-- (48355, 0, 0x0, 0x101, ''), -- Hellscream Guard
(46586, 0, 0x0, 0x1, ''), -- Wandering Soul
(45492, 0, 0x3000000, 0x1, ''), -- Tower Range Finder
(45561, 0, 0x0, 0x1, ''), -- Tower Cannon Target
(46597, 0, 0x0, 0x1, ''), -- Skeletal Beastmaster
(46570, 0, 0x0, 0x1, ''), -- Putrid Worg
(46582, 0, 0x0, 0x1, ''), -- Hungry Ghoul
(46571, 0, 0x0, 0x1, ''), -- First Lieutenant Connor
(48358, 0, 0x0, 0x1, ''), -- Commander Larmash
(48363, 0, 0x0, 0x1, ''), -- Captain Prug
(48361, 0, 0x0, 0x1, ''), -- Private Sarlosk
(51287, 0, 0x0, 0x1, ''), -- Colonel Karzag
(48531, 0, 0x0, 0x1, ''), -- Pogg
(52016, 17719, 0x3000000, 0x1, ''), -- Petty Officer Chulok
(48360, 0, 0x0, 0x1, ''), -- 3rd Officer Kronkar
(48356, 0, 0x0, 0x1, ''), -- Karosh
(50164, 0, 0x0, 0x1, '32783'), -- Tulgar Flamefist - Arcane Channeling
-- (48357, 0, 0x8, 0x1, ''), -- Hellscream's Reach Recruit
(45067, 0, 0x10000, 0x1, '22011'), -- Horde Spirit Guide - Spirit Heal Channel
(45066, 0, 0x10000, 0x1, '22011'), -- Alliance Spirit Guide - Spirit Heal Channel
(48355, 0, 0x0, 0x100, ''); -- Hellscream Guard


-- `creature_model_info` has empty data.
UPDATE `creature_model_info` SET `bounding_radius`=0.533, `combat_reach`=1.5 WHERE `modelid`=137;
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=146;
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=237;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=1504;
UPDATE `creature_model_info` SET `bounding_radius`=0.9747, `combat_reach`=4.05, `gender`=0 WHERE `modelid`=2578;
UPDATE `creature_model_info` SET `bounding_radius`=0.8725, `combat_reach`=3.75, `gender`=1 WHERE `modelid`=2579;
UPDATE `creature_model_info` SET `bounding_radius`=0.3519, `combat_reach`=1.725, `gender`=0 WHERE `modelid`=2581;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=2584;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=2585;
UPDATE `creature_model_info` SET `bounding_radius`=0.3519, `combat_reach`=1.725, `gender`=1 WHERE `modelid`=2590;
UPDATE `creature_model_info` SET `bounding_radius`=0.2, `combat_reach`=1.25 WHERE `modelid`=3146;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=3494;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=3732;
UPDATE `creature_model_info` SET `bounding_radius`=1.5, `combat_reach`=1.25 WHERE `modelid`=4124;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=4887;
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=7555;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=9255;
UPDATE `creature_model_info` SET `bounding_radius`=1, `combat_reach`=1.5 WHERE `modelid`=10771;
UPDATE `creature_model_info` SET `bounding_radius`=2.5, `combat_reach`=5 WHERE `modelid`=14501;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=16366;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=18889;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=19601;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=21905;
UPDATE `creature_model_info` SET `bounding_radius`=0.3519, `combat_reach`=1.725, `gender`=0 WHERE `modelid`=23105;
UPDATE `creature_model_info` SET `bounding_radius`=1.1, `combat_reach`=1.65 WHERE `modelid`=23960;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=25042;
UPDATE `creature_model_info` SET `bounding_radius`=0.383, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=25053;
UPDATE `creature_model_info` SET `bounding_radius`=0.31, `combat_reach`=1 WHERE `modelid`=26775;
UPDATE `creature_model_info` SET `bounding_radius`=0.279, `gender`=0 WHERE `modelid`=30301;
UPDATE `creature_model_info` SET `bounding_radius`=0.279, `gender`=0 WHERE `modelid`=30302;
UPDATE `creature_model_info` SET `bounding_radius`=1.1, `combat_reach`=1.1 WHERE `modelid`=30643;
UPDATE `creature_model_info` SET `bounding_radius`=1.5, `combat_reach`=1.5 WHERE `modelid`=30644;
UPDATE `creature_model_info` SET `bounding_radius`=0.4511, `combat_reach`=1.3 WHERE `modelid`=30645;
UPDATE `creature_model_info` SET `bounding_radius`=0.39905, `combat_reach`=1.15 WHERE `modelid`=30646;
UPDATE `creature_model_info` SET `bounding_radius`=0.91, `combat_reach`=1.365 WHERE `modelid`=31072;
UPDATE `creature_model_info` SET `bounding_radius`=1.4, `combat_reach`=1.75 WHERE `modelid`=32023;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33195;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=33304;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=34095;
UPDATE `creature_model_info` SET `bounding_radius`=0.208, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=34096;
UPDATE `creature_model_info` SET `bounding_radius`=0.1, `combat_reach`=1.25 WHERE `modelid`=34160;
UPDATE `creature_model_info` SET `bounding_radius`=0.62, `combat_reach`=2 WHERE `modelid`=34168;
UPDATE `creature_model_info` SET `bounding_radius`=0.0775, `combat_reach`=0.25 WHERE `modelid`=35132;
UPDATE `creature_model_info` SET `bounding_radius`=0.520833, `combat_reach`=2.25, `gender`=0 WHERE `modelid`=35145;
UPDATE `creature_model_info` SET `bounding_radius`=0.2754, `combat_reach`=1.35, `gender`=0 WHERE `modelid`=35189;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35190;
UPDATE `creature_model_info` SET `bounding_radius`=0.3519, `combat_reach`=1.725, `gender`=0 WHERE `modelid`=35208;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35299;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35300;
UPDATE `creature_model_info` SET `bounding_radius`=0.347, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35302;
UPDATE `creature_model_info` SET `bounding_radius`=0.47875, `combat_reach`=1.875, `gender`=0 WHERE `modelid`=35515;
UPDATE `creature_model_info` SET `bounding_radius`=0.47875, `combat_reach`=1.875, `gender`=0 WHERE `modelid`=35527;
UPDATE `creature_model_info` SET `bounding_radius`=0.9747, `combat_reach`=4.05, `gender`=0 WHERE `modelid`=35663;
UPDATE `creature_model_info` SET `bounding_radius`=0.9747, `combat_reach`=4.05, `gender`=0 WHERE `modelid`=35732;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=1 WHERE `modelid`=35735;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=35737;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=36729;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=36730;
UPDATE `creature_model_info` SET `bounding_radius`=4, `gender`=0 WHERE `modelid`=37179;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37242;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37243;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37244;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37245;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37246;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37247;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37248;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37250;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37251;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37252;
UPDATE `creature_model_info` SET `bounding_radius`=0.4092, `combat_reach`=1.65, `gender`=0 WHERE `modelid`=37253;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37254;
UPDATE `creature_model_info` SET `bounding_radius`=0.4092, `combat_reach`=1.65, `gender`=0 WHERE `modelid`=37255;
UPDATE `creature_model_info` SET `bounding_radius`=0.3366, `combat_reach`=1.65, `gender`=0 WHERE `modelid`=37256;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37257;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37258;
UPDATE `creature_model_info` SET `bounding_radius`=1.595, `combat_reach`=1.65 WHERE `modelid`=37259;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37260;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37261;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37262;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37263;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37264;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37265;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37266;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37267;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37268;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37269;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37270;
UPDATE `creature_model_info` SET `bounding_radius`=0.372, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37271;
UPDATE `creature_model_info` SET `bounding_radius`=0.306, `combat_reach`=1.5, `gender`=0 WHERE `modelid`=37272;

SET @CGUID := 4916;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+636;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 47183, 732, 1, 1, -253.606, 1022.88, 51.23883, 3.001966, 7200, 0, 0), -- Ghastly Worker (Area: -Unknown-)
(@CGUID+1, 46645, 732, 1, 1, -155.2101, 1055.335, 22.56966, 6.108652, 7200, 0, 0), -- Cursed Stallion (Area: 0)
(@CGUID+2, 47181, 732, 1, 1, -166.036, 1048.8, 26.24793, 0.2268928, 7200, 0, 0), -- Overlook Spirit (Area: 0)
(@CGUID+3, 47182, 732, 1, 1, -237.8094, 1019.489, 49.56272, 2.774447, 7200, 0, 0), -- Overlook Spectre (Area: 0) (possible waypoints or random movement)
(@CGUID+4, 1412, 732, 1, 1, -186.9944, 1185.164, 23.40238, 1.486682, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+5, 1412, 732, 1, 1, -194.4245, 1115.285, 23.46463, 2.888983, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+6, 46645, 732, 1, 1, -143.0104, 1039.271, 23.28833, 1.832596, 7200, 0, 0), -- Cursed Stallion (Area: 0)
(@CGUID+7, 47181, 732, 1, 1, -140.668, 1032.05, 28.34383, 1.32645, 7200, 0, 0), -- Overlook Spirit (Area: 0)
(@CGUID+8, 47667, 732, 1, 1, -102.9505, 1019.301, 21.8511, 3.627928, 7200, 0, 0), -- Wharf Rat (Area: 0)
(@CGUID+9, 47657, 732, 1, 1, -73.7951, 1066.23, 15.14023, 0, 7200, 0, 0), -- Suspicious Villager (Area: 0) (possible waypoints or random movement)
(@CGUID+10, 47666, 732, 1, 1, -91.6389, 1150.61, 16.26823, 1.797689, 7200, 0, 0), -- Rustberg Horse (Area: 0)
(@CGUID+11, 47666, 732, 1, 1, -95.0313, 1146.64, 15.87063, 2.844887, 7200, 0, 0), -- Rustberg Horse (Area: 0)
(@CGUID+12, 47667, 732, 1, 1, -118.3302, 1088.337, 18.21855, 4.473792, 7200, 0, 0), -- Wharf Rat (Area: 0)
(@CGUID+13, 47659, 732, 1, 1, -124.632, 1155.89, 22.37023, 5.742133, 7200, 0, 0), -- Apprehensive Worker (Area: 0)
(@CGUID+14, 47657, 732, 1, 1, -107.3161, 1144.806, 16.21835, 3.516465, 7200, 0, 0), -- Suspicious Villager (Area: 0) (possible waypoints or random movement)
(@CGUID+15, 46608, 732, 1, 1, 64.43997, 1384.001, -5.942527, 5.376483, 7200, 0, 0), -- Tank (Area: 0) (possible waypoints or random movement)
(@CGUID+16, 46645, 732, 1, 1, -212.0295, 968.6875, 49.12563, 3.159046, 7200, 0, 0), -- Cursed Stallion (Area: Largo's Overlook)
(@CGUID+17, 47181, 732, 1, 1, -208.33, 1005.49, 43.11534, 3.983931, 7200, 0, 0), -- Overlook Spirit (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+18, 47181, 732, 1, 1, -149.363, 952.476, 80.43453, 4.171337, 7200, 0, 0), -- Overlook Spirit (Area: Largo's Overlook)
(@CGUID+19, 47181, 732, 1, 1, -161.927, 960.132, 80.37594, 4.171337, 7200, 0, 0), -- Overlook Spirit (Area: Largo's Overlook)
(@CGUID+20, 47183, 732, 1, 1, -209.451, 965.922, 49.38053, 0.7504916, 7200, 0, 0), -- Ghastly Worker (Area: Largo's Overlook)
(@CGUID+21, 47304, 732, 1, 1, -137.663, 968.234, 119.2293, 5.410521, 7200, 0, 0), -- Commander Largo (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+22, 47181, 732, 1, 1, -215.825, 980.094, 48.52542, 4.437435, 7200, 0, 0), -- Overlook Spirit (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+23, 47182, 732, 1, 1, -236.1523, 987.779, 49.38455, 1.030455, 7200, 0, 0), -- Overlook Spectre (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+24, 47182, 732, 1, 1, -221.0855, 953.9129, 50.27006, 2.642941, 7200, 0, 0), -- Overlook Spectre (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+25, 47183, 732, 1, 1, -214.382, 951.266, 49.18351, 5.916666, 7200, 0, 0), -- Ghastly Worker (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+26, 47183, 732, 1, 1, -232.91, 997.321, 49.03963, 0.8203048, 7200, 0, 0), -- Ghastly Worker (Area: Largo's Overlook)
(@CGUID+27, 47183, 732, 1, 1, -268.552, 991.3, 48.93091, 3.501121, 7200, 0, 0), -- Ghastly Worker (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+28, 47182, 732, 1, 1, -272.895, 973.0327, 48.99609, 4.622703, 7200, 0, 0), -- Overlook Spectre (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+29, 47182, 732, 1, 1, -256.6014, 944.2617, 48.97738, 3.178401, 7200, 0, 0), -- Overlook Spectre (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+30, 46645, 732, 1, 1, -253.5729, 969.3768, 49.01215, 5.375614, 7200, 0, 0), -- Cursed Stallion (Area: Largo's Overlook)
(@CGUID+31, 47183, 732, 1, 1, -221.997, 918.941, 63.24753, 2.495821, 7200, 0, 0), -- Ghastly Worker (Area: Largo's Overlook)
(@CGUID+32, 47183, 732, 1, 1, -236.028, 921.722, 63.24753, 6.143559, 7200, 0, 0), -- Ghastly Worker (Area: Largo's Overlook)
(@CGUID+33, 47182, 732, 1, 1, -151.3072, 927.0205, 72.6984, 5.652052, 7200, 0, 0), -- Overlook Spectre (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+34, 47181, 732, 1, 1, -288.965, 963.29, 49.09733, 0.3141593, 7200, 0, 0), -- Overlook Spirit (Area: Largo's Overlook)
(@CGUID+35, 47181, 732, 1, 1, -283.88, 949.557, 48.97853, 0.3141593, 7200, 0, 0), -- Overlook Spirit (Area: Largo's Overlook)
(@CGUID+36, 47182, 732, 1, 1, -165.0845, 910.5573, 72.6984, 6.179362, 7200, 0, 0), -- Overlook Spectre (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+37, 47181, 732, 1, 1, -253.825, 909.168, 55.27702, 2.797486, 7200, 0, 0), -- Overlook Spirit (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+38, 47183, 732, 1, 1, -153.816, 910.148, 72.77963, 0.1396263, 7200, 0, 0), -- Ghastly Worker (Area: Largo's Overlook)
(@CGUID+39, 47183, 732, 1, 1, -277.901, 926.241, 48.97853, 2.827433, 7200, 0, 0), -- Ghastly Worker (Area: Largo's Overlook)
(@CGUID+40, 46645, 732, 1, 1, -180.6649, 909.0781, 72.10211, 2.670354, 7200, 0, 0), -- Cursed Stallion (Area: Largo's Overlook)
(@CGUID+41, 46645, 732, 1, 1, -278.0642, 941.3663, 48.97852, 5.88176, 7200, 0, 0), -- Cursed Stallion (Area: Largo's Overlook)
(@CGUID+42, 47183, 732, 1, 1, -181.168, 895.764, 75.62724, 0.1396263, 7200, 0, 0), -- Ghastly Worker (Area: Largo's Overlook)
(@CGUID+43, 47182, 732, 1, 1, -122.1654, 918.4188, 73.28008, 6.131423, 7200, 0, 0), -- Overlook Spectre (Area: Largo's Overlook) (possible waypoints or random movement)
(@CGUID+44, 47682, 732, 1, 1, -34.0208, 1038.75, 15.10499, 0.3164737, 7200, 0, 0), -- Sassy Cat (Area: Rustberg Village)
(@CGUID+45, 47657, 732, 1, 1, 19.96917, 1054.448, 15.92892, 1.137707, 7200, 0, 0), -- Suspicious Villager (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+46, 47666, 732, 1, 1, -36.2517, 1134.81, 16.22303, 1.22173, 7200, 0, 0), -- Rustberg Horse (Area: Rustberg Village)
(@CGUID+47, 47666, 732, 1, 1, -37.849, 1130.31, 16.57953, 3.281219, 7200, 0, 0), -- Rustberg Horse (Area: Rustberg Village)
(@CGUID+48, 47667, 732, 1, 1, -24.22728, 1090.718, 15.8124, 4.68945, 7200, 0, 0), -- Wharf Rat (Area: Rustberg Village)
(@CGUID+49, 47657, 732, 1, 1, -53.3281, 1153.52, 15.14113, 0, 7200, 0, 0), -- Suspicious Villager (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+50, 47667, 732, 1, 1, 27.86927, 1055.712, 15.14202, 4.285411, 7200, 0, 0), -- Wharf Rat (Area: Rustberg Village)
(@CGUID+51, 47682, 732, 1, 1, -56.809, 1169.12, 15.18972, 2.504935, 7200, 0, 0), -- Sassy Cat (Area: Rustberg Village)
(@CGUID+52, 47667, 732, 1, 1, -3.830703, 1145.35, 15.9049, 4.878881, 7200, 0, 0), -- Wharf Rat (Area: Rustberg Village)
(@CGUID+53, 47659, 732, 1, 1, -24.9635, 1157.57, 15.66483, 1.972222, 7200, 0, 0), -- Apprehensive Worker (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+54, 47659, 732, 1, 1, -39.8003, 1160.94, 15.40003, 5.8294, 7200, 0, 0), -- Apprehensive Worker (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+55, 47659, 732, 1, 1, -30.1806, 1169.4, 15.55623, 5.113815, 7200, 0, 0), -- Apprehensive Worker (Area: Rustberg Village)
(@CGUID+56, 47657, 732, 1, 1, 2.903418, 1152.749, 15.71828, 2.536685, 7200, 0, 0), -- Suspicious Villager (Area: Rustberg Village)
(@CGUID+57, 47667, 732, 1, 1, 34.79231, 1125.461, 4.653233, 3.337752, 7200, 0, 0), -- Wharf Rat (Area: Rustberg Village)
(@CGUID+58, 47657, 732, 1, 1, 0.862847, 1141.34, 16.17093, 0, 7200, 0, 0), -- Suspicious Villager (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+59, 47627, 732, 1, 1, -46.92966, 1104.24, 15.18454, 4.759745, 7200, 0, 0), -- Rustberg Bandit (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+60, 47659, 732, 1, 1, 44.61459, 1046.64, 17.46833, 5.288348, 7200, 0, 0), -- Apprehensive Worker (Area: Rustberg Village)
(@CGUID+61, 47627, 732, 1, 1, -82.88579, 1021.593, 18.30964, 3.441097, 7200, 0, 0), -- Rustberg Bandit (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+62, 47657, 732, 1, 1, -89.92176, 1185.176, 17.75712, 4.152548, 7200, 0, 0), -- Suspicious Villager (Area: 0) (possible waypoints or random movement)
(@CGUID+63, 47666, 732, 1, 1, -77.0608, 1191.19, 15.90863, 3.176499, 7200, 0, 0), -- Rustberg Horse (Area: 0)
(@CGUID+64, 47666, 732, 1, 1, -74.0434, 1187.06, 16.16893, 4.153883, 7200, 0, 0), -- Rustberg Horse (Area: 0)
(@CGUID+65, 47667, 732, 1, 1, -69.93225, 1220.988, 17.21214, 1.50029, 7200, 0, 0), -- Wharf Rat (Area: 0)
(@CGUID+66, 47659, 732, 1, 1, -57.1545, 1206.02, 17.30333, 1.623156, 7200, 0, 0), -- Apprehensive Worker (Area: 0)
(@CGUID+67, 47627, 732, 1, 1, -127.0913, 1181.704, 21.93555, 2.850174, 7200, 0, 0), -- Rustberg Bandit (Area: 0) (possible waypoints or random movement)
(@CGUID+68, 47666, 732, 1, 1, -36.941, 1194.01, 16.23343, 5.934119, 7200, 0, 0), -- Rustberg Horse (Area: 0)
(@CGUID+69, 47659, 732, 1, 1, -44.901, 1199.05, 16.08523, 2.565634, 7200, 0, 0), -- Apprehensive Worker (Area: 0)
(@CGUID+70, 47659, 732, 1, 1, -67.9462, 1313.06, 22.39653, 0.1745329, 7200, 0, 0), -- Apprehensive Worker (Area: 0)
(@CGUID+71, 47657, 732, 1, 1, -54.2338, 1291.245, 23.28953, 0.4811131, 7200, 0, 0), -- Suspicious Villager (Area: 0) (possible waypoints or random movement)
(@CGUID+72, 47657, 732, 1, 1, -42.6337, 1230.5, 15.87423, 0, 7200, 0, 0), -- Suspicious Villager (Area: 0) (possible waypoints or random movement)
(@CGUID+73, 47659, 732, 1, 1, -45.9219, 1311, 25.06113, 3.01942, 7200, 0, 0), -- Apprehensive Worker (Area: 0)
(@CGUID+74, 47373, 732, 1, 1, -100.083, 1302.07, 22.12739, 4.493684, 7200, 0, 0), -- Warden's Sentry (Area: 0) (possible waypoints or random movement)
(@CGUID+75, 47373, 732, 1, 1, -97.15446, 1301.419, 22.17459, 4.493694, 7200, 0, 0), -- Warden's Sentry (Area: 0) (possible waypoints or random movement)
(@CGUID+76, 47373, 732, 1, 1, -103.0115, 1302.721, 22.12739, 4.493742, 7200, 0, 0), -- Warden's Sentry (Area: 0) (possible waypoints or random movement)
(@CGUID+77, 47666, 732, 1, 1, -10.7465, 1190.53, 16.64193, 4.869469, 7200, 0, 0), -- Rustberg Horse (Area: Rustberg Village)
(@CGUID+78, 47666, 732, 1, 1, -14.9931, 1192.07, 16.23473, 3.438299, 7200, 0, 0), -- Rustberg Horse (Area: Rustberg Village)
(@CGUID+79, 47680, 732, 1, 1, 21.4896, 1165.81, 16.63723, 3.490659, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+80, 47657, 732, 1, 1, 4.01069, 1171.009, 15.44223, 4.40417, 7200, 0, 0), -- Suspicious Villager (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+81, 47667, 732, 1, 1, 12.42406, 1262.429, 15.18193, 2.57572, 7200, 0, 0), -- Wharf Rat (Area: Rustberg Village)
(@CGUID+82, 47682, 732, 1, 1, 8.8559, 1239.32, 16.43193, 6.036213, 7200, 0, 0), -- Sassy Cat (Area: Rustberg Village)
(@CGUID+83, 47680, 732, 1, 1, 61.6285, 1241.28, 16.64893, 1.413717, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+84, 47657, 732, 1, 1, 4.03819, 1330.34, 22.78563, 0, 7200, 0, 0), -- Suspicious Villager (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+85, 47682, 732, 1, 1, 12.4531, 1320.27, 22.96337, 4.68656, 7200, 0, 0), -- Sassy Cat (Area: Rustberg Village)
(@CGUID+86, 47667, 732, 1, 1, -20.99347, 1337.255, 22.16056, 3.397336, 7200, 0, 0), -- Wharf Rat (Area: Rustberg Village)
(@CGUID+87, 47659, 732, 1, 1, 20.4566, 1333.9, 23.56103, 0.9424778, 7200, 0, 0), -- Apprehensive Worker (Area: Rustberg Village)
(@CGUID+88, 47287, 732, 1, 1, 272.1866, 1527.9, 2.637254, 5.2396, 7200, 0, 0), -- Captain P. Harris (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+89, 46606, 732, 1, 1, -34.26986, 1405.353, -1.763593, 2.258455, 7200, 0, 0), -- Spiny Tidecrawler (Area: Rustberg Village)
(@CGUID+90, 47680, 732, 1, 1, 44.4462, 1142.11, 4.708973, 0.4712389, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+91, 47680, 732, 1, 1, 24.3559, 1158.64, 17.80383, 2.635447, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+92, 47680, 732, 1, 1, 50.5017, 1180.79, 4.962893, 5.864306, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+93, 47627, 732, 1, 1, -11.42849, 1160.558, 15.17712, 6.23032, 7200, 0, 0), -- Rustberg Bandit (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+94, 47657, 732, 1, 1, 54, 1120.69, 3.841673, 0, 7200, 0, 0), -- Suspicious Villager (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+95, 47657, 732, 1, 1, 73.69012, 1174.478, 3.813898, 1.111974, 7200, 0, 0), -- Suspicious Villager (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+96, 47657, 732, 1, 1, 58.53688, 1208.26, 3.774713, 0.3452742, 7200, 0, 0), -- Suspicious Villager (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+97, 47680, 732, 1, 1, 70.1076, 1136.33, 7.432213, 0.3824535, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+98, 47667, 732, 1, 1, 61.21379, 1195.017, 3.858737, 3.79537, 7200, 0, 0), -- Wharf Rat (Area: Rustberg Village)
(@CGUID+99, 47680, 732, 1, 1, 85.87674, 1152.271, 6.742988, 2.932153, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+100, 47666, 732, 1, 1, 80.875, 1186.83, 4.236124, 3.071779, 7200, 0, 0), -- Rustberg Horse (Area: Rustberg Village)
(@CGUID+101, 47680, 732, 1, 1, 51.3715, 1089.12, 17.99413, 4.08407, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+102, 47666, 732, 1, 1, 80.7014, 1191.77, 4.525574, 3.385939, 7200, 0, 0), -- Rustberg Horse (Area: Rustberg Village)
(@CGUID+103, 47642, 732, 1, 1, 103.076, 1140.82, 4.328693, 0.1745329, 7200, 0, 0), -- Rustberg Fisherman (Area: Rustberg Village)
(@CGUID+104, 47666, 732, 1, 1, 80.5243, 1196.24, 4.277564, 3.141593, 7200, 0, 0), -- Rustberg Horse (Area: Rustberg Village)
(@CGUID+105, 47642, 732, 1, 1, 107.668, 1166.3, 0.4033583, 0.5759587, 7200, 0, 0), -- Rustberg Fisherman (Area: Rustberg Village)
(@CGUID+106, 47642, 732, 1, 1, 102.035, 1197.19, 4.163168, 5.856968, 7200, 0, 0), -- Rustberg Fisherman (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+107, 47680, 732, 1, 1, 87.6962, 1113.63, 8.223973, 2.75762, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+108, 47680, 732, 1, 1, 65.1337, 1085.59, 16.81023, 5.131268, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+109, 47680, 732, 1, 1, 97.6042, 1176.09, 7.778644, 4.206244, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+110, 47680, 732, 1, 1, 98.9965, 1178.96, 21.95403, 2.617994, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+111, 47642, 732, 1, 1, 104.757, 1111.04, 3.904111, 0.1530982, 7200, 0, 0), -- Rustberg Fisherman (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+112, 47680, 732, 1, 1, 103.891, 1153, 19.52573, 3.508112, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+113, 47680, 732, 1, 1, 85.2396, 1221.64, 8.067033, 4.310963, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+114, 47682, 732, 1, 1, 81.5677, 1225.76, 4.019372, 3.037196, 7200, 0, 0), -- Sassy Cat (Area: Rustberg Village)
(@CGUID+115, 47680, 732, 1, 1, 68.9219, 1238.44, 17.84713, 2.181662, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+116, 47680, 732, 1, 1, 110.465, 1114.31, 7.476364, 2.654495, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+117, 47667, 732, 1, 1, 117.417, 1134.12, 4.507441, 1.756016, 7200, 0, 0), -- Wharf Rat (Area: Rustberg Village)
(@CGUID+118, 47680, 732, 1, 1, 129.583, 1143.93, 8.030104, 4.921828, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+119, 47680, 732, 1, 1, 108.012, 1235.59, 9.104223, 3.682645, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+120, 47642, 732, 1, 1, 101.297, 1227.55, 4.584373, 0.1745329, 7200, 0, 0), -- Rustberg Fisherman (Area: Rustberg Village)
(@CGUID+121, 47667, 732, 1, 1, 88.684, 1238.68, 4.799435, 3.165833, 7200, 0, 0), -- Wharf Rat (Area: Rustberg Village)
(@CGUID+122, 47680, 732, 1, 1, 108.0761, 1214.725, 16.88462, 3.885491, 7200, 0, 0), -- Rustberg Gull (Area: Rustberg Village)
(@CGUID+123, 47642, 732, 1, 1, 141.5169, 1130.833, 1.392043, 0.9823421, 7200, 0, 0), -- Rustberg Fisherman (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+124, 47627, 732, 1, 1, 13.30936, 1067.861, 15.1125, 3.388479, 7200, 0, 0), -- Rustberg Bandit (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+125, 47642, 732, 1, 1, 131.368, 1204.44, 3.050225, 4.749482, 7200, 0, 0), -- Rustberg Fisherman (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+126, 47659, 732, 1, 1, -31.776, 1299.42, 22.65253, 2.6529, 7200, 0, 0), -- Apprehensive Worker (Area: Rustberg Village)
(@CGUID+127, 47627, 732, 1, 1, -19.29954, 1333.254, 22.11178, 2.275071, 7200, 0, 0), -- Rustberg Bandit (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+128, 46606, 732, 1, 1, -61.97852, 1458.854, 2.080218, 1.634732, 7200, 0, 0), -- Spiny Tidecrawler (Area: Rustberg Village)
(@CGUID+129, 47676, 732, 1, 1, -104.537, 1444.554, 7.418153, 5.004556, 7200, 0, 0), -- Baradin Fox (Area: Rustberg Village) (possible waypoints or random movement)
(@CGUID+130, 46605, 732, 1, 1, -88.11147, 1433.411, 3.179418, 2.457064, 7200, 0, 0), -- Shipwrecked Sailor (Area: Rustberg Village)
(@CGUID+131, 46508, 732, 1, 1, -216.589, 1426.15, 23.41473, 0, 7200, 0, 0), -- Darkwood Lurker (Area: 0)
(@CGUID+132, 46509, 732, 1, 1, -223.6085, 1390.975, 20.812, 5.496938, 7200, 0, 0), -- Darkwood Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+133, 46509, 732, 1, 1, -212.4077, 1442.276, 23.22685, 3.736785, 7200, 0, 0), -- Darkwood Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+134, 46509, 732, 1, 1, -208.1924, 1405.102, 24.14326, 4.63081, 7200, 0, 0), -- Darkwood Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+135, 46509, 732, 1, 1, -221.2336, 1377.849, 23.21838, 4.212816, 7200, 0, 0), -- Darkwood Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+136, 46509, 732, 1, 1, -218.5313, 1405.781, 22.93488, 1.163083, 7200, 0, 0), -- Darkwood Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+137, 46509, 732, 1, 1, -201.361, 1391.662, 27.26147, 3.723612, 7200, 0, 0), -- Darkwood Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+138, 46509, 732, 1, 1, -206.5467, 1384.625, 24.80199, 2.047733, 7200, 0, 0), -- Darkwood Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+139, 46509, 732, 1, 1, -195.4007, 1453.636, 26.2245, 2.140024, 7200, 0, 0), -- Darkwood Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+140, 46509, 732, 1, 1, -203.155, 1445.299, 24.36686, 3.174684, 7200, 0, 0), -- Darkwood Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+141, 46508, 732, 1, 1, -214.5245, 1413.58, 23.73127, 5.338797, 7200, 0, 0), -- Darkwood Lurker (Area: 0) (possible waypoints or random movement)
(@CGUID+142, 46507, 732, 1, 1, -210.8491, 1394.968, 20.33642, 0.5093732, 7200, 0, 0), -- Darkwood Broodmother (Area: 0) (possible waypoints or random movement)
(@CGUID+143, 46507, 732, 1, 1, -206.3562, 1457.791, 21.7819, 0.7681514, 7200, 0, 0), -- Darkwood Broodmother (Area: 0) (possible waypoints or random movement)
(@CGUID+144, 46509, 732, 1, 1, -204.883, 1462.43, 23.30021, 4.00725, 7200, 0, 0), -- Darkwood Hatchling (Area: 0) (possible waypoints or random movement)
(@CGUID+145, 47676, 732, 1, 1, -117.8763, 1461.72, 13.36725, 0.920079, 7200, 0, 0), -- Baradin Fox (Area: 0)
(@CGUID+146, 46509, 732, 1, 1, -220.7529, 1454.421, 24.08085, 1.297265, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+147, 46509, 732, 1, 1, -210.8821, 1471.86, 25.46426, 0.9641694, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+148, 46509, 732, 1, 1, -236.7561, 1443.671, 24.47298, 0.6304418, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+149, 46509, 732, 1, 1, -240.6319, 1439.803, 23.19222, 0.3837187, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+150, 46508, 732, 1, 1, -189.9762, 1484.48, 26.34999, 2.315932, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+151, 46508, 732, 1, 1, -234.3998, 1364.156, 24.06429, 3.394485, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+152, 46507, 732, 1, 1, -244.2565, 1443.76, 21.95125, 0.03993598, 7200, 0, 0), -- Darkwood Broodmother (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+153, 46509, 732, 1, 1, -238.9319, 1456.112, 25.1346, 0.153363, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+154, 46509, 732, 1, 1, -228.9921, 1353.755, 24.93566, 4.724977, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+155, 46508, 732, 1, 1, -252.084, 1385.417, 21.6706, 4.300957, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+156, 46509, 732, 1, 1, -255.6531, 1425.253, 24.52758, 0.3118991, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+157, 46509, 732, 1, 1, -258.8206, 1406.103, 23.09094, 3.478467, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+158, 46509, 732, 1, 1, -222.9409, 1340.714, 25.65319, 3.012597, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+159, 46509, 732, 1, 1, -254.9445, 1439.429, 23.57015, 1.664229, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+160, 46509, 732, 1, 1, -240.7163, 1354.287, 23.21729, 0.8489602, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+161, 46509, 732, 1, 1, -258.6817, 1442.776, 25.24605, 5.565692, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+162, 46507, 732, 1, 1, -233.681, 1341.89, 20.43885, 5.614292, 7200, 0, 0), -- Darkwood Broodmother (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+163, 47676, 732, 1, 1, -207.0235, 1482.905, 26.24715, 4.302, 7200, 0, 0), -- Baradin Fox (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+164, 46509, 732, 1, 1, -263.9767, 1396.785, 21.86835, 1.067529, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+165, 46508, 732, 1, 1, -255.7096, 1456.799, 26.15881, 5.316637, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+166, 46509, 732, 1, 1, -255.3002, 1459.182, 25.82112, 2.157719, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+167, 46507, 732, 1, 1, -269.6094, 1419.884, 22.07044, 0.9827937, 7200, 0, 0), -- Darkwood Broodmother (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+168, 46509, 732, 1, 1, -228.5926, 1330.648, 24.97698, 3.451567, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+169, 46509, 732, 1, 1, -248.3001, 1345.833, 20.40772, 3.034318, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+170, 46509, 732, 1, 1, -235.8776, 1329.193, 24.62514, 6.247038, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+171, 46509, 732, 1, 1, -277.4615, 1392.498, 21.70585, 5.549361, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+172, 46509, 732, 1, 1, -283.5186, 1421.651, 24.11048, 2.237185, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+173, 46509, 732, 1, 1, -287.9838, 1407.483, 22.68637, 2.922183, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+174, 1412, 732, 1, 1, -278.4414, 1353.481, 22.2906, 3.512673, 7200, 0, 0), -- Squirrel (Area: The Darkwood)
(@CGUID+175, 46509, 732, 1, 1, -291.265, 1325.062, 22.70331, 5.385065, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+176, 46508, 732, 1, 1, -273.8408, 1324.248, 23.06424, 0.244317, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+177, 46508, 732, 1, 1, -208.7644, 1307.598, 24.42764, 4.851524, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+178, 46509, 732, 1, 1, -312.1586, 1422.56, 21.13269, 3.337231, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+179, 46509, 732, 1, 1, -307.6202, 1442.723, 24.46502, 4.927657, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+180, 46509, 732, 1, 1, -319.1435, 1368.383, 21.20801, 1.822482, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+181, 46509, 732, 1, 1, -323.7039, 1358.609, 19.10633, 3.971732, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+182, 46509, 732, 1, 1, -321.1389, 1418.561, 21.17102, 3.542711, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+183, 46509, 732, 1, 1, -322.4633, 1379.269, 22.89344, 3.103699, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+184, 46509, 732, 1, 1, -328.7466, 1429.299, 23.39758, 2.271946, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+185, 46509, 732, 1, 1, -301.8684, 1339.661, 20.37537, 2.127378, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+186, 46508, 732, 1, 1, -288.3393, 1353.904, 22.8243, 4.081065, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+187, 46509, 732, 1, 1, -305.8906, 1431.645, 23.23669, 0.8655584, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+188, 1412, 732, 1, 1, -303.2223, 1463.923, 24.67547, 6.130792, 7200, 0, 0), -- Squirrel (Area: The Darkwood)
(@CGUID+189, 46507, 732, 1, 1, -329.2453, 1370.546, 18.32435, 3.582889, 7200, 0, 0), -- Darkwood Broodmother (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+190, 46509, 732, 1, 1, -310.0111, 1343.365, 22.39344, 2.689991, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+191, 46507, 732, 1, 1, -318.9101, 1437.337, 20.7448, 5.131332, 7200, 0, 0), -- Darkwood Broodmother (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+192, 46508, 732, 1, 1, -301.191, 1403.483, 22.42605, 0.9887147, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+193, 46509, 732, 1, 1, -297.4703, 1322.79, 21.58, 2.941182, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+194, 46507, 732, 1, 1, -305.6973, 1326.607, 20.06366, 5.142823, 7200, 0, 0), -- Darkwood Broodmother (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+195, 46508, 732, 1, 1, -261.7974, 1300.363, 23.26067, 1.599417, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+196, 46509, 732, 1, 1, -297.248, 1306.442, 21.4317, 2.972672, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+197, 46509, 732, 1, 1, -312.9687, 1313.514, 25.95609, 0.5420585, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+198, 46509, 732, 1, 1, -323.2852, 1326.195, 24.65458, 2.120746, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+199, 46509, 732, 1, 1, -306.5498, 1303.951, 21.7951, 4.33787, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+200, 46509, 732, 1, 1, -335.9114, 1357.576, 21.65285, 5.436704, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+201, 46509, 732, 1, 1, -290.0486, 1290.839, 23.34571, 5.909365, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+202, 46508, 732, 1, 1, -334.375, 1344.792, 23.14278, 4.246387, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+203, 46509, 732, 1, 1, -334.7404, 1377.054, 24.09548, 4.366303, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+204, 46509, 732, 1, 1, -343.8013, 1370.607, 23.96138, 0.3768113, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+205, 46507, 732, 1, 1, -302.6459, 1287.671, 20.95753, 3.934877, 7200, 0, 0), -- Darkwood Broodmother (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+206, 46509, 732, 1, 1, -293.2285, 1279.688, 25.1338, 5.253938, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+207, 1412, 732, 1, 1, -272.1826, 1286.711, 22.8838, 2.568883, 7200, 0, 0), -- Squirrel (Area: The Darkwood)
(@CGUID+208, 46509, 732, 1, 1, -313.497, 1285.584, 24.05116, 4.810448, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+209, 46509, 732, 1, 1, -307.7596, 1279.271, 25.1902, 1.254982, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+210, 46508, 732, 1, 1, -343.6656, 1410.529, 24.40498, 6.232425, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+211, 46508, 732, 1, 1, -356.3882, 1334.969, 22.52009, 1.849193, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+212, 46509, 732, 1, 1, -360.6666, 1344.365, 22.39278, 1.405333, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+213, 46508, 732, 1, 1, -344.791, 1301.042, 22.66222, 1.791125, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+214, 46509, 732, 1, 1, -360.6631, 1323.12, 21.77355, 0.8601992, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+215, 46508, 732, 1, 1, -368.1434, 1372.03, 23.53675, 1.444261, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+216, 46509, 732, 1, 1, -359.5428, 1307.937, 21.15417, 2.942833, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+217, 46509, 732, 1, 1, -373.6536, 1358.914, 21.92036, 6.28047, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+218, 46508, 732, 1, 1, -320.933, 1264.166, 25.09918, 5.799214, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+219, 46509, 732, 1, 1, -374.4404, 1341.266, 23.92304, 4.454349, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+220, 46509, 732, 1, 1, -361.7366, 1298.475, 23.74107, 0.6477509, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+221, 46509, 732, 1, 1, -373.822, 1321.283, 23.86315, 0.7786826, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+222, 46507, 732, 1, 1, -380.9017, 1345.976, 23.00703, 4.354815, 7200, 0, 0), -- Darkwood Broodmother (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+223, 46508, 732, 1, 1, -276.6997, 1239.634, 23.79645, 1.434492, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+224, 46507, 732, 1, 1, -370.9232, 1309.147, 20.01867, 5.785845, 7200, 0, 0), -- Darkwood Broodmother (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+225, 46509, 732, 1, 1, -383.449, 1337.749, 25.41315, 0.9021488, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+226, 46509, 732, 1, 1, -377.4786, 1310.107, 24.61877, 0.4357447, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+227, 46509, 732, 1, 1, -378.0258, 1295.742, 26.61406, 3.574016, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+228, 1412, 732, 1, 1, -396.1553, 1304.971, 23.89758, 5.963288, 7200, 0, 0), -- Squirrel (Area: The Darkwood)
(@CGUID+229, 46508, 732, 1, 1, -397.6021, 1319.137, 24.96898, 0.7674894, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+230, 47676, 732, 1, 1, -358.2418, 1108.632, 23.4512, 5.471073, 7200, 0, 0), -- Baradin Fox (Area: 0) (possible waypoints or random movement)
(@CGUID+231, 47240, 732, 1, 1, -347.762, 1063.86, 22.11623, 1.169371, 7200, 0, 0), -- Commander Marcus Johnson (Area: 0)
(@CGUID+232, 48255, 732, 1, 1, -328.106, 1057.76, 22.11473, 2.443461, 7200, 0, 0), -- Camp Coordinator Brack (Area: 0)
(@CGUID+233, 48252, 732, 1, 1, -354.092, 1057.757, 22.13772, 0.3316126, 7200, 0, 0), -- Baradin Recruit (Area: 0) (possible waypoints or random movement)
(@CGUID+234, 48253, 732, 1, 1, -320.9861, 1065.267, 22.27963, 0.6632251, 7200, 0, 0), -- Baradin Guard (Area: 0)
(@CGUID+235, 48252, 732, 1, 1, -388.4861, 1087.125, 28.05382, 5.602507, 7200, 0, 0), -- Baradin Recruit (Area: 0)
(@CGUID+236, 47328, 732, 1, 1, -397.0746, 1083.189, 27.99383, 5.462881, 7200, 0, 0), -- Quartermaster Brazie (Area: 0)
(@CGUID+237, 48252, 732, 1, 1, -363.125, 1092.521, 22.13863, 5.096361, 7200, 0, 0), -- Baradin Recruit (Area: 0)
(@CGUID+238, 48252, 732, 1, 1, -359.2795, 1076.535, 22.12583, 3.351032, 7200, 0, 0), -- Baradin Recruit (Area: 0)
(@CGUID+239, 48254, 732, 1, 1, -369.441, 1072.35, 22.12353, 5.305801, 7200, 0, 0), -- Sergeant Gray (Area: 0)
(@CGUID+240, 48252, 732, 1, 1, -321.8542, 1086.153, 22.36844, 4.049164, 7200, 0, 0), -- Baradin Recruit (Area: 0)
(@CGUID+241, 48253, 732, 1, 1, -336.3906, 1081.236, 22.02444, 1.745329, 7200, 0, 0), -- Baradin Guard (Area: 0)
(@CGUID+242, 48253, 732, 1, 1, -350.8733, 1083.351, 22.13292, 1.064651, 7200, 0, 0), -- Baradin Guard (Area: 0)
(@CGUID+243, 48253, 732, 1, 1, -385.8958, 1086.646, 28.11979, 3.368485, 7200, 0, 0), -- Baradin Guard (Area: 0)
(@CGUID+244, 48253, 732, 1, 1, -385.632, 1076.505, 25.7934, 4.991642, 7200, 0, 0), -- Baradin Guard (Area: 0)
(@CGUID+245, 1412, 732, 1, 1, -329.8031, 1089.619, 22.92476, 3.089694, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+246, 48252, 732, 1, 1, -393.8056, 1092.219, 28.10337, 1.413189, 7200, 0, 0), -- Baradin Recruit (Area: 0) (possible waypoints or random movement)
(@CGUID+247, 48252, 732, 1, 1, -329.5972, 1042.547, 22.12484, 1.396263, 7200, 0, 0), -- Baradin Recruit (Area: 0)
(@CGUID+248, 51288, 732, 1, 1, -369.599, 1042.377, 22.13292, 0.715585, 7200, 0, 0), -- Major Marsden (Area: 0)
(@CGUID+249, 48251, 732, 1, 1, -374.3594, 1052.682, 22.06591, 2.879793, 7200, 0, 0), -- Kevin Geissler (Area: 0)
(@CGUID+250, 48250, 732, 1, 1, -353.014, 1038.44, 22.09193, 1.047198, 7200, 0, 0), -- Lieutenant Farnsworth (Area: 0)
(@CGUID+251, 50161, 732, 1, 1, -347.0781, 1029.786, 22.36349, 0.122173, 7200, 0, 0), -- Dar Rummond (Area: 0)
(@CGUID+252, 48252, 732, 1, 1, -363.4757, 1038.78, 22.12867, 3.228859, 7200, 0, 0), -- Baradin Recruit (Area: 0)
(@CGUID+253, 48252, 732, 1, 1, -340.2621, 1037.34, 22.13274, 1.012291, 7200, 0, 0), -- Baradin Recruit (Area: 0)
(@CGUID+254, 48252, 732, 1, 1, -339.0087, 1039.271, 22.11509, 4.031711, 7200, 0, 0), -- Baradin Recruit (Area: 0)
(@CGUID+255, 48253, 732, 1, 1, -388.2934, 1054.833, 20.3789, 3.874631, 7200, 0, 0), -- Baradin Guard (Area: 0)
(@CGUID+256, 52015, 732, 1, 1, -362.5521, 1034.158, 22.13292, 1.37881, 7200, 0, 0), -- Captain Jake Sones (Area: 0)
(@CGUID+257, 48253, 732, 1, 1, -329.4045, 1034.668, 22.13302, 2.617994, 7200, 0, 0), -- Baradin Guard (Area: 0)
(@CGUID+258, 48253, 732, 1, 1, -339.9375, 1034.632, 22.14242, 2.565634, 7200, 0, 0), -- Baradin Guard (Area: 0)
(@CGUID+259, 48253, 732, 1, 1, -326.5764, 1043.95, 22.14745, 2.842432, 7200, 0, 0), -- Baradin Guard (Area: 0)
(@CGUID+260, 1412, 732, 1, 1, -363.1859, 1062.396, 21.89461, 2.845955, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+261, 48252, 732, 1, 1, -325.0556, 1046.905, 22.14745, 6.143559, 7200, 0, 0), -- Baradin Recruit (Area: 0) (possible waypoints or random movement)
(@CGUID+262, 48253, 732, 1, 1, -364.9675, 1053.321, 21.96168, 2.061174, 7200, 0, 0), -- Baradin Guard (Area: 0) (possible waypoints or random movement)
(@CGUID+263, 48253, 732, 1, 1, -392.3941, 1071.542, 25.87757, 5.288348, 7200, 0, 0), -- Baradin Guard (Area: 0)
(@CGUID+264, 46509, 732, 1, 1, -389.541, 1347.896, 24.73566, 4.958795, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+265, 46509, 732, 1, 1, -383.5115, 1355.803, 23.52937, 0.3099661, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+266, 46508, 732, 1, 1, -390.9531, 1373.575, 22.65071, 0.56523, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+267, 47676, 732, 1, 1, -352.4708, 1460.031, 25.00866, 5.924644, 7200, 0, 0), -- Baradin Fox (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+268, 46508, 732, 1, 1, -345.5333, 1452.408, 23.24279, 6.144154, 7200, 0, 0), -- Darkwood Lurker (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+269, 46509, 732, 1, 1, -326.925, 1442.603, 24.53997, 5.603606, 7200, 0, 0), -- Darkwood Hatchling (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+270, 1412, 732, 1, 1, -196.2481, 1553.938, 22.7041, 0.6281208, 7200, 0, 0), -- Squirrel (Area: The Darkwood)
(@CGUID+271, 47676, 732, 1, 1, -151.8888, 1560.605, 22.96825, 1.839007, 7200, 0, 0), -- Baradin Fox (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+272, 47428, 732, 1, 1, -190.131, 1588.588, 21.44626, 2.681437, 7200, 0, 0), -- Hellscream's Sentry (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+273, 46606, 732, 1, 1, -46.08942, 1479.445, 2.342977, 0.8177702, 7200, 0, 0), -- Spiny Tidecrawler (Area: The Darkwood)
(@CGUID+274, 47676, 732, 1, 1, -54.35971, 1520.875, 7.48626, 3.056504, 7200, 0, 0), -- Baradin Fox (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+275, 46605, 732, 1, 1, -60.14909, 1472.142, 3.276082, 4.736075, 7200, 0, 0), -- Shipwrecked Sailor (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+276, 47402, 732, 1, 1, -364.792, 1557.63, 20.73023, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Darkwood)
(@CGUID+277, 47402, 732, 1, 1, -354.905, 1572.7, 21.45893, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Darkwood)
(@CGUID+278, 1412, 732, 1, 1, -168.2003, 1603.91, 22.37642, 2.518337, 7200, 0, 0), -- Squirrel (Area: The Darkwood)
(@CGUID+279, 47428, 732, 1, 1, -245.5526, 1618.552, 22.18179, 2.888997, 7200, 0, 0), -- Hellscream's Sentry (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+280, 47428, 732, 1, 1, -254.9289, 1617.725, 22.16251, 2.90524, 7200, 0, 0), -- Hellscream's Sentry (Area: The Darkwood) (possible waypoints or random movement)
(@CGUID+281, 48325, 732, 1, 1, -75.0694, 1656.12, 27.35943, 3.455752, 7200, 0, 0), -- Farson Horse (Area: 0)
(@CGUID+282, 48325, 732, 1, 1, -60.2986, 1631.03, 27.58813, 4.08407, 7200, 0, 0), -- Farson Horse (Area: 0)
(@CGUID+283, 46989, 732, 1, 1, -56.85091, 1610.991, 28.5786, 0.173198, 7200, 0, 0), -- Crazed Soldier (Area: 0) (possible waypoints or random movement)
(@CGUID+284, 46989, 732, 1, 1, -114.29, 1605.23, 17.0145, 3.820549, 7200, 0, 0), -- Crazed Soldier (Area: 0) (possible waypoints or random movement)
(@CGUID+285, 46989, 732, 1, 1, -94.71465, 1606.352, 23.84203, 3.194839, 7200, 0, 0), -- Crazed Soldier (Area: 0) (possible waypoints or random movement)
(@CGUID+286, 46989, 732, 1, 1, -79.0208, 1678.44, 28.18153, 4.468043, 7200, 0, 0), -- Crazed Soldier (Area: 0) (possible waypoints or random movement)
(@CGUID+287, 46989, 732, 1, 1, -111.698, 1624.28, 24.49323, 4.468043, 7200, 0, 0), -- Crazed Soldier (Area: 0) (possible waypoints or random movement)
(@CGUID+288, 32780, 732, 1, 1, -115.556, 1603.84, 20.67893, 0, 7200, 0, 0), -- Invisible Stalker (All Phases) (Area: 0)
(@CGUID+289, 46989, 732, 1, 1, -27.7674, 1624.33, 27.09699, 3.388269, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+290, 47130, 732, 1, 1, -44.9219, 1664.98, 27.36393, 3.996804, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+291, 47130, 732, 1, 1, -52.5781, 1673.82, 27.48063, 3.996804, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+292, 46989, 732, 1, 1, -11.65158, 1610.849, 28.84699, 0.4551097, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+293, 46989, 732, 1, 1, -108.4817, 1695.961, 28.26906, 5.495481, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+294, 46989, 732, 1, 1, 12.32856, 1628.969, 28.00536, 2.407071, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+295, 46989, 732, 1, 1, -90.6892, 1727.56, 27.05898, 1.256622, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+296, 46989, 732, 1, 1, -12.8663, 1699.89, 35.00612, 0.6796286, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+297, 46989, 732, 1, 1, -69.401, 1732.54, 29.32743, 4.468043, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+298, 47130, 732, 1, 1, -4.15278, 1700.77, 37.54403, 3.804818, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+299, 47130, 732, 1, 1, -11.3733, 1708.66, 37.54373, 3.839724, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+300, 47130, 732, 1, 1, 3.31944, 1700.37, 58.60433, 3.857178, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold)
(@CGUID+301, 47130, 732, 1, 1, -3.58333, 1708.46, 58.60703, 3.857178, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold)
(@CGUID+302, 47130, 732, 1, 1, -10.559, 1716.15, 58.60423, 3.857178, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold)
(@CGUID+303, 46989, 732, 1, 1, 20.70405, 1696.103, 37.43995, 5.093239, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+304, 46989, 732, 1, 1, -15.6693, 1735.221, 37.43995, 2.487951, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+305, 46605, 732, 1, 1, 62.87312, 1588.239, 2.577536, 0.5868363, 7200, 0, 0), -- Shipwrecked Sailor (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+306, 46605, 732, 1, 1, 78.57619, 1563.299, -1.40414, 5.512299, 7200, 0, 0), -- Shipwrecked Sailor (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+307, 46605, 732, 1, 1, 44.08854, 1556.951, 3.880905, 0, 7200, 0, 0), -- Shipwrecked Sailor (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+308, 46605, 732, 1, 1, 8.73611, 1555.6, 4.381254, 0, 7200, 0, 0), -- Shipwrecked Sailor (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+309, 48308, 732, 1, 1, 20.36111, 1718.2, 28.29747, 0.6632251, 7200, 0, 0), -- Farson Hold Prisoner (Area: Farson Hold)
(@CGUID+310, 49455, 732, 1, 1, 18.01759, 1732.228, 28.21414, 2.220386, 7200, 0, 0), -- Dehydrated Prisoner (Area: Farson Hold)
(@CGUID+311, 49455, 732, 1, 1, 18.00406, 1719.933, 28.21414, 4.19761, 7200, 0, 0), -- Dehydrated Prisoner (Area: Farson Hold)
(@CGUID+312, 49455, 732, 1, 1, 22.86224, 1714.779, 28.21414, 4.805348, 7200, 0, 0), -- Dehydrated Prisoner (Area: Farson Hold)
(@CGUID+313, 47130, 732, 1, 1, 53.3056, 1716.66, 58.60273, 3.857178, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold)
(@CGUID+314, 47130, 732, 1, 1, 46.8438, 1724.1, 58.60273, 3.857178, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold)
(@CGUID+315, 46989, 732, 1, 1, 53.1528, 1727.87, 37.4376, 4.372507, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+316, 46605, 732, 1, 1, 86.00434, 1613.62, 5.286027, 0.9351076, 7200, 0, 0), -- Shipwrecked Sailor (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+317, 46989, 732, 1, 1, 50.07174, 1720.952, 45.5731, 4.500161, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+318, 47130, 732, 1, 1, 17.76563, 1726.913, 36.50685, 5.532694, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+319, 46989, 732, 1, 1, 51.4878, 1729.76, 37.43808, 1.047902, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+320, 46989, 732, 1, 1, 39.39954, 1710.847, 58.52185, 0.6964566, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+321, 49455, 732, 1, 1, 23.00705, 1734.902, 28.21414, 5.566119, 7200, 0, 0), -- Dehydrated Prisoner (Area: Farson Hold)
(@CGUID+322, 48309, 732, 1, 1, 19.70313, 1733.854, 28.29747, 5.811946, 7200, 0, 0), -- Farson Hold Prisoner (Area: Farson Hold)
(@CGUID+323, 46605, 732, 1, 1, -25.85069, 1533.365, 6.639813, 0, 7200, 0, 0), -- Shipwrecked Sailor (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+324, 47428, 732, 1, 1, -177.6332, 1693.997, 2.607693, 1.132203, 7200, 0, 0), -- Hellscream's Sentry (Area: Farson Hold)
(@CGUID+325, 1412, 732, 1, 1, -165.0795, 1710.112, 3.808899, 5.861069, 7200, 0, 0), -- Squirrel (Area: Farson Hold)
(@CGUID+326, 47676, 732, 1, 1, -152.116, 1787.25, 4.573033, 0, 7200, 0, 0), -- Baradin Fox (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+327, 46630, 732, 1, 1, -121.925, 1819.57, 3.035653, 0, 7200, 0, 0), -- Accursed Longshoreman (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+328, 46989, 732, 1, 1, -3.47743, 1747.86, 37.44059, 2.24401, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+329, 46989, 732, 1, 1, 19.53579, 1762.89, 58.51984, 3.612814, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+330, 47130, 732, 1, 1, 12.7448, 1763.5, 58.60263, 3.857178, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold)
(@CGUID+331, 47130, 732, 1, 1, 19.5069, 1756.09, 58.60263, 3.979351, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold)
(@CGUID+332, 46989, 732, 1, 1, 21.85185, 1762.958, 37.43756, 1.571612, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+333, 46989, 732, 1, 1, 19.9583, 1762.82, 45.65583, 4.468043, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+334, 46989, 732, 1, 1, 14.8872, 1759.1, 58.51883, 3.678374, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+335, 47447, 732, 1, 1, 43.1545, 1748.97, 46.89623, 3.857178, 7200, 0, 0), -- Keep Lord Farson (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+336, 47130, 732, 1, 1, 52.71701, 1742.401, 46.88528, 3.822271, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+337, 47130, 732, 1, 1, 37.88195, 1759.741, 46.88659, 3.822271, 7200, 0, 0), -- Crazed Guard (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+338, 46989, 732, 1, 1, 58.32103, 1729.837, 58.51871, 1.227794, 7200, 0, 0), -- Crazed Soldier (Area: Farson Hold) (possible waypoints or random movement)
(@CGUID+339, 46606, 732, 1, 1, -225.1763, 1707.249, 0.9137051, 3.871071, 7200, 0, 0), -- Spiny Tidecrawler (Area: 0)
(@CGUID+340, 46605, 732, 1, 1, -85.32494, 1441.297, 3.025706, 4.402686, 7200, 0, 0), -- Shipwrecked Sailor (Area: 0) (possible waypoints or random movement)
(@CGUID+341, 46605, 732, 1, 1, -23.07057, 1494.289, 5.042646, 0.02198976, 7200, 0, 0), -- Shipwrecked Sailor (Area: 0) (possible waypoints or random movement)
(@CGUID+342, 46605, 732, 1, 1, 15.82451, 1492.544, 2.927187, 3.722553, 7200, 0, 0), -- Shipwrecked Sailor (Area: 0) (possible waypoints or random movement)
(@CGUID+343, 46606, 732, 1, 1, 4.624438, 1520.981, 4.338153, 3.174556, 7200, 0, 0), -- Spiny Tidecrawler (Area: 0)
(@CGUID+344, 46606, 732, 1, 1, 90.90659, 1502.37, -5.604468, 4.585716, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+345, 46606, 732, 1, 1, 48.4375, 1506.25, 1.16151, 1.570796, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+346, 46606, 732, 1, 1, 54.27955, 1536.735, 2.535931, 3.478175, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+347, 46605, 732, 1, 1, 34.02788, 1515.564, 3.37611, 4.461843, 7200, 0, 0), -- Shipwrecked Sailor (Area: Cape of Lost Hope) (possible waypoints or random movement)
(@CGUID+348, 46606, 732, 1, 1, 106.5332, 1565.465, -6.659376, 4.129261, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+349, 46606, 732, 1, 1, 132.584, 1498.397, -9.197948, 0.6405866, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+350, 46606, 732, 1, 1, 112.398, 1597.401, -1.861997, 0.8007745, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+351, 46606, 732, 1, 1, 154.0812, 1547.031, -13.35275, 1.393366, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+352, 46605, 732, 1, 1, 119.9583, 1625.705, 2.815501, 0, 7200, 0, 0), -- Shipwrecked Sailor (Area: Cape of Lost Hope) (possible waypoints or random movement)
(@CGUID+353, 46606, 732, 1, 1, 164.0437, 1608.127, -10.24492, 6.161739, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+354, 46606, 732, 1, 1, 143.9209, 1641.63, -5.649641, 6.131158, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+355, 46606, 732, 1, 1, 194.138, 1571.713, -9.388244, 5.349621, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+356, 46606, 732, 1, 1, 162.9329, 1688.771, -11.50631, 5.678835, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+357, 46606, 732, 1, 1, 171.5892, 1657.453, -10.07078, 0.2341598, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+358, 46606, 732, 1, 1, 191.7206, 1510.729, -9.777934, 3.161058, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+359, 46606, 732, 1, 1, 154.0068, 1462.479, -6.751848, 1.20508, 7200, 0, 0), -- Spiny Tidecrawler (Area: Cape of Lost Hope)
(@CGUID+360, 47676, 732, 1, 1, -290.8848, 1666.146, 18.86118, 3.141593, 7200, 0, 0), -- Baradin Fox (Area: 0) (possible waypoints or random movement)
(@CGUID+361, 47676, 732, 1, 1, -265.906, 1722.33, 6.491121, 2.651051, 7200, 0, 0), -- Baradin Fox (Area: 0) (possible waypoints or random movement)
(@CGUID+362, 46606, 732, 1, 1, -237.4182, 1770.49, -5.353123, 1.146958, 7200, 0, 0), -- Spiny Tidecrawler (Area: 0)
(@CGUID+363, 46606, 732, 1, 1, -245.3711, 1738.291, 1.377598, 1.944773, 7200, 0, 0), -- Spiny Tidecrawler (Area: 0)
(@CGUID+364, 46606, 732, 1, 1, -250.8418, 1805.226, -0.9723101, 3.217766, 7200, 0, 0), -- Spiny Tidecrawler (Area: 0)
(@CGUID+365, 1412, 732, 1, 1, -208.123, 1814.534, 5.245877, 1.537573, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+366, 46606, 732, 1, 1, -255.1659, 1830.006, 1.556987, 4.66494, 7200, 0, 0), -- Spiny Tidecrawler (Area: 0)
(@CGUID+367, 47676, 732, 1, 1, -207.9365, 1812.679, 4.539077, 3.327301, 7200, 0, 0), -- Baradin Fox (Area: 0) (possible waypoints or random movement)
(@CGUID+368, 46630, 732, 1, 1, -217.6887, 1840.025, 2.700094, 5.660149, 7200, 0, 0), -- Accursed Longshoreman (Area: 0) (possible waypoints or random movement)
(@CGUID+369, 46630, 732, 1, 1, -154.278, 1823.94, 3.724873, 0, 7200, 0, 0), -- Accursed Longshoreman (Area: 0) (possible waypoints or random movement)
(@CGUID+370, 46630, 732, 1, 1, -190.717, 1831.81, 3.539853, 0, 7200, 0, 0), -- Accursed Longshoreman (Area: 0) (possible waypoints or random movement)
(@CGUID+371, 46630, 732, 1, 1, -148.149, 1850.85, 2.820783, 0, 7200, 0, 0), -- Accursed Longshoreman (Area: 0) (possible waypoints or random movement)
(@CGUID+372, 46643, 732, 1, 1, -196.451, 1862.43, 2.869573, 2.391101, 7200, 0, 0), -- Accursed Shipbuilder (Area: 0)
(@CGUID+373, 46641, 732, 1, 1, -169.7473, 1852.429, 2.3826, 3.313065, 7200, 0, 0), -- Ghastly Dockhand (Area: 0) (possible waypoints or random movement)
(@CGUID+374, 46630, 732, 1, 1, -113.8557, 1857.073, 14.2825, 5.941073, 7200, 0, 0), -- Accursed Longshoreman (Area: 0) (possible waypoints or random movement)
(@CGUID+375, 46643, 732, 1, 1, -163.722, 1889, 11.93583, 1.448623, 7200, 0, 0), -- Accursed Shipbuilder (Area: 0)
(@CGUID+376, 46641, 732, 1, 1, -206.583, 1897.67, 2.3826, 4.18879, 7200, 0, 0), -- Ghastly Dockhand (Area: 0) (possible waypoints or random movement)
(@CGUID+377, 46643, 732, 1, 1, -210.549, 1874, 2.835423, 4.24115, 7200, 0, 0), -- Accursed Shipbuilder (Area: 0) (possible waypoints or random movement)
(@CGUID+378, 46630, 732, 1, 1, -178.1368, 1890.745, 3.435762, 1.274051, 7200, 0, 0), -- Accursed Longshoreman (Area: 0) (possible waypoints or random movement)
(@CGUID+379, 46643, 732, 1, 1, -155.209, 1883.333, 3.502518, 2.129302, 7200, 0, 0), -- Accursed Shipbuilder (Area: 0) (possible waypoints or random movement)
(@CGUID+380, 46648, 732, 1, 1, -195.8, 1885.55, 2.387666, 4.84668, 7200, 0, 0), -- Foreman Wellson (Area: 0) (possible waypoints or random movement)
(@CGUID+381, 46643, 732, 1, 1, -120.165, 1903.94, 3.110163, 5.288348, 7200, 0, 0), -- Accursed Shipbuilder (Area: 0)
(@CGUID+382, 46643, 732, 1, 1, -182.5816, 1917.825, 3.23891, 1.047198, 7200, 0, 0), -- Accursed Shipbuilder (Area: Wellson Shipyard)
(@CGUID+383, 46630, 732, 1, 1, -209.375, 1912.5, 2.454234, 4.712389, 7200, 0, 0), -- Accursed Longshoreman (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+384, 46645, 732, 1, 1, -214.063, 1900.37, 2.465933, 6.073746, 7200, 0, 0), -- Cursed Stallion (Area: Wellson Shipyard)
(@CGUID+385, 46643, 732, 1, 1, -157.755, 1933.44, 14.98673, 3.700098, 7200, 0, 0), -- Accursed Shipbuilder (Area: Wellson Shipyard)
(@CGUID+386, 46643, 732, 1, 1, -133.293, 1928.82, 3.106574, 2.879793, 7200, 0, 0), -- Accursed Shipbuilder (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+387, 46645, 732, 1, 1, -214.622, 1904.84, 2.465933, 0.4363323, 7200, 0, 0), -- Cursed Stallion (Area: Wellson Shipyard)
(@CGUID+388, 46645, 732, 1, 1, -216.575, 1909.61, 2.465933, 0.6632251, 7200, 0, 0), -- Cursed Stallion (Area: Wellson Shipyard)
(@CGUID+389, 46630, 732, 1, 1, -244.1002, 1906.025, 12.806, 1.011256, 7200, 0, 0), -- Accursed Longshoreman (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+390, 46641, 732, 1, 1, -81.70712, 1892, 13.4611, 3.896728, 7200, 0, 0), -- Ghastly Dockhand (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+391, 46641, 732, 1, 1, -116.677, 1930.69, 2.3826, 1.025343, 7200, 0, 0), -- Ghastly Dockhand (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+392, 46643, 732, 1, 1, -149.826, 1945.9, 14.79063, 0.7853982, 7200, 0, 0), -- Accursed Shipbuilder (Area: Wellson Shipyard)
(@CGUID+393, 46630, 732, 1, 1, -219.9555, 1937.606, 13.2692, 0.9674711, 7200, 0, 0), -- Accursed Longshoreman (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+394, 46643, 732, 1, 1, -158.469, 1952.3, 15.49263, 3.822271, 7200, 0, 0), -- Accursed Shipbuilder (Area: Wellson Shipyard)
(@CGUID+395, 46630, 732, 1, 1, -180.7021, 1954.635, 1.350866, 6.261291, 7200, 0, 0), -- Accursed Longshoreman (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+396, 46630, 732, 1, 1, -73.842, 1901.68, 13.31741, 0.1683255, 7200, 0, 0), -- Accursed Longshoreman (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+397, 46630, 732, 1, 1, -213.438, 1949.86, 12.71952, 0.3311962, 7200, 0, 0), -- Accursed Longshoreman (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+398, 46645, 732, 1, 1, -69.1163, 1877.91, 13.44873, 2.932153, 7200, 0, 0), -- Cursed Stallion (Area: Wellson Shipyard)
(@CGUID+399, 46643, 732, 1, 1, -133.7361, 1960.319, 2.541952, 3.944444, 7200, 0, 0), -- Accursed Shipbuilder (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+400, 46645, 732, 1, 1, -65.375, 1880.48, 13.49413, 1.884956, 7200, 0, 0), -- Cursed Stallion (Area: Wellson Shipyard)
(@CGUID+401, 46645, 732, 1, 1, -62.1302, 1884.84, 13.54443, 2.548181, 7200, 0, 0), -- Cursed Stallion (Area: Wellson Shipyard)
(@CGUID+402, 46630, 732, 1, 1, -94.27148, 1945.313, 13.52767, 0.2766194, 7200, 0, 0), -- Accursed Longshoreman (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+403, 46645, 732, 1, 1, -231.977, 1958.53, 12.75883, 3.455752, 7200, 0, 0), -- Cursed Stallion (Area: Wellson Shipyard)
(@CGUID+404, 46630, 732, 1, 1, -244.8463, 1977.254, 2.881861, 1.507144, 7200, 0, 0), -- Accursed Longshoreman (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+405, 46630, 732, 1, 1, -244.3977, 1947.604, 12.74203, 0.006763977, 7200, 0, 0), -- Accursed Longshoreman (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+406, 48283, 732, 1, 1, -213.472, 2015.89, 6.944275, 1.832596, 7200, 0, 0), -- Wellson Cannon (Area: Wellson Shipyard)
(@CGUID+407, 48283, 732, 1, 1, -209.146, 2015.93, 6.944258, 1.291544, 7200, 0, 0), -- Wellson Cannon (Area: Wellson Shipyard)
(@CGUID+408, 48283, 732, 1, 1, -215.038, 2005.6, 6.945864, 2.984513, 7200, 0, 0), -- Wellson Cannon (Area: Wellson Shipyard)
(@CGUID+409, 48283, 732, 1, 1, -204.722, 2010.73, 6.945255, 0.3839724, 7200, 0, 0), -- Wellson Cannon (Area: Wellson Shipyard)
(@CGUID+410, 48283, 732, 1, 1, -67.0122, 1994.86, 7.23779, 0.296706, 7200, 0, 0), -- Wellson Cannon (Area: Wellson Shipyard)
(@CGUID+411, 46630, 732, 1, 1, -61.2153, 1943.73, 14.06603, 0, 7200, 0, 0), -- Accursed Longshoreman (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+412, 48283, 732, 1, 1, -74.2326, 2016.61, 7.227807, 0.9773844, 7200, 0, 0), -- Wellson Cannon (Area: Wellson Shipyard)
(@CGUID+413, 48283, 732, 1, 1, -66.1337, 2005.47, 7.229457, 0.2268928, 7200, 0, 0), -- Wellson Cannon (Area: Wellson Shipyard)
(@CGUID+414, 48283, 732, 1, 1, -68.8229, 2016.24, 7.227819, 1.308997, 7200, 0, 0), -- Wellson Cannon (Area: Wellson Shipyard)
(@CGUID+415, 46630, 732, 1, 1, -72.3756, 2012.027, 7.228096, 1.527037, 7200, 0, 0), -- Accursed Longshoreman (Area: Wellson Shipyard) (possible waypoints or random movement)
(@CGUID+416, 47676, 732, 1, 1, -343.9779, 1793.629, 24.83666, 2.370006, 7200, 0, 0), -- Baradin Fox (Area: 0) (possible waypoints or random movement)
(@CGUID+417, 47402, 732, 1, 1, -339.066, 1727.75, 24.01813, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+418, 47402, 732, 1, 1, -335.085, 1702.94, 23.23263, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+419, 47402, 732, 1, 1, -347.222, 1714.61, 21.28183, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+420, 47402, 732, 1, 1, -348.521, 1727.41, 24.03803, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+421, 47402, 732, 1, 1, -335.325, 1688.88, 21.51873, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+422, 46823, 732, 1, 1, -335.812, 1707.975, 24.08026, 4.389689, 7200, 0, 0), -- Restless Infantry (Area: 0)
(@CGUID+423, 46825, 732, 1, 1, -336.8207, 1704.959, 23.77016, 1.248371, 7200, 0, 0), -- Restless Soldier (Area: 0)
(@CGUID+424, 47402, 732, 1, 1, -351.061, 1747.3, 23.33963, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+425, 47402, 732, 1, 1, -329.512, 1668.18, 20.34953, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+426, 47402, 732, 1, 1, -361.34, 1700.25, 18.30723, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+427, 47402, 732, 1, 1, -326.569, 1647.6, 24.14293, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+428, 47402, 732, 1, 1, -320.547, 1632.83, 24.92033, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+429, 47402, 732, 1, 1, -355.434, 1676.45, 18.37843, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+430, 47402, 732, 1, 1, -340.785, 1673.69, 18.78833, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+431, 47402, 732, 1, 1, -335.747, 1651.97, 20.74113, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+432, 47402, 732, 1, 1, -375.76, 1717.57, 21.94663, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+433, 47402, 732, 1, 1, -367.108, 1717.89, 20.20613, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+434, 47402, 732, 1, 1, -361.616, 1750.67, 24.85763, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+435, 47402, 732, 1, 1, -365.477, 1736.24, 25.05473, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+436, 46825, 732, 1, 1, -361.1285, 1746.42, 25.75693, 2.129302, 7200, 0, 0), -- Restless Soldier (Area: 0)
(@CGUID+437, 46823, 732, 1, 1, -363.9218, 1748.734, 25.35335, 5.591347, 7200, 0, 0), -- Restless Infantry (Area: 0)
(@CGUID+438, 47402, 732, 1, 1, -404.365, 1700.73, 23.84473, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+439, 47402, 732, 1, 1, -388.429, 1720.21, 25.41343, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+440, 47402, 732, 1, 1, -390.385, 1701.18, 22.64693, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+441, 46823, 732, 1, 1, -391.047, 1715.68, 25.61633, 4.08407, 7200, 0, 0), -- Restless Infantry (Area: 0)
(@CGUID+442, 46825, 732, 1, 1, -393.9441, 1713.434, 25.59428, 0.659382, 7200, 0, 0), -- Restless Soldier (Area: 0)
(@CGUID+443, 1412, 732, 1, 1, -380.8932, 1720.486, 23.91962, 3.175759, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+444, 47402, 732, 1, 1, -376.939, 1677.87, 18.66463, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+445, 47402, 732, 1, 1, -381.837, 1754.79, 24.99493, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+446, 47402, 732, 1, 1, -397.08, 1736.19, 22.88023, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+447, 46823, 732, 1, 1, -382.7129, 1660.256, 18.59947, 4.353555, 7200, 0, 0), -- Restless Infantry (Area: The Restless Front)
(@CGUID+448, 46825, 732, 1, 1, -383.983, 1656.87, 19.20313, 0.8203048, 7200, 0, 0), -- Restless Soldier (Area: The Restless Front)
(@CGUID+449, 47402, 732, 1, 1, -397.429, 1677.37, 17.84113, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+450, 47402, 732, 1, 1, -361.849, 1665.34, 18.73663, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+451, 47402, 732, 1, 1, -380.328, 1661.27, 18.05653, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+452, 47402, 732, 1, 1, -398.908, 1661.82, 19.87893, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+453, 46960, 732, 1, 1, -357.332, 1658.61, 18.189, 0.1047198, 7200, 0, 0), -- Ghastly Scavenger (Area: The Restless Front) (possible waypoints or random movement)
(@CGUID+454, 47402, 732, 1, 1, -407.929, 1657.39, 21.42483, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+455, 47402, 732, 1, 1, -369.05, 1651.51, 18.75573, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+456, 47402, 732, 1, 1, -390.679, 1647.91, 21.84443, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+457, 47402, 732, 1, 1, -419.734, 1659.28, 22.26123, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+458, 47402, 732, 1, 1, -381.411, 1646.34, 20.68653, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+459, 46823, 732, 1, 1, -337.854, 1640.91, 23.25863, 4.660029, 7200, 0, 0), -- Restless Infantry (Area: The Restless Front)
(@CGUID+460, 46825, 732, 1, 1, -339.1444, 1637.568, 22.51832, 1.202339, 7200, 0, 0), -- Restless Soldier (Area: The Restless Front)
(@CGUID+461, 47402, 732, 1, 1, -356.16, 1644.97, 17.83523, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+462, 47402, 732, 1, 1, -368.613, 1635.98, 20.37963, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+463, 47402, 732, 1, 1, -381.05, 1634.7, 23.43153, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+464, 47402, 732, 1, 1, -340.979, 1638.62, 22.19233, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+465, 47402, 732, 1, 1, -431.122, 1643.29, 21.75183, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+466, 47402, 732, 1, 1, -407.087, 1628.98, 18.18943, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+467, 47402, 732, 1, 1, -364.158, 1622.07, 23.90913, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+468, 47402, 732, 1, 1, -347.003, 1625.89, 22.16233, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+469, 1412, 732, 1, 1, -341.666, 1626.563, 21.49153, 0.3589279, 7200, 0, 0), -- Squirrel (Area: The Restless Front)
(@CGUID+470, 47402, 732, 1, 1, -402.389, 1614.13, 18.45333, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+471, 47402, 732, 1, 1, -373.924, 1610.73, 23.42983, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+472, 47402, 732, 1, 1, -358.274, 1612.99, 24.21083, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+473, 47402, 732, 1, 1, -391.866, 1607.69, 22.69703, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+474, 47402, 732, 1, 1, -429.149, 1617.89, 19.73533, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+475, 46960, 732, 1, 1, -413.66, 1606.88, 18.3844, 4.58461, 7200, 0, 0), -- Ghastly Scavenger (Area: The Restless Front) (possible waypoints or random movement)
(@CGUID+476, 46569, 732, 1, 1, -502.811, 1710.82, 48.70473, 1.797689, 7200, 0, 0), -- Forgotten Ghoul (Area: The Restless Front)
(@CGUID+477, 46581, 732, 1, 1, -495.694, 1738.32, 46.67983, 3.682645, 7200, 0, 0), -- Violated Corpse (Area: The Restless Front)
(@CGUID+478, 47402, 732, 1, 1, -431.932, 1602.59, 23.13213, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+479, 47402, 732, 1, 1, -332.49, 1623.53, 23.19813, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+480, 46823, 732, 1, 1, -361.0087, 1593.439, 23.87312, 4.45059, 7200, 0, 0), -- Restless Infantry (Area: The Restless Front)
(@CGUID+481, 47402, 732, 1, 1, -329.91, 1609.66, 22.72343, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+482, 46825, 732, 1, 1, -362.967, 1591.023, 23.21629, 0.7853982, 7200, 0, 0), -- Restless Soldier (Area: The Restless Front)
(@CGUID+483, 47402, 732, 1, 1, -357.429, 1602.71, 24.64843, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+484, 47402, 732, 1, 1, -352.661, 1594.47, 24.44023, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+485, 47402, 732, 1, 1, -345.03, 1593.6, 23.56723, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+486, 47402, 732, 1, 1, -366.689, 1592.88, 22.92953, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+487, 47402, 732, 1, 1, -356.745, 1588.1, 23.52143, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+488, 47402, 732, 1, 1, -350.767, 1585.63, 23.11033, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+489, 46960, 732, 1, 1, -381.9532, 1591.111, 21.14747, 0.2613145, 7200, 0, 0), -- Ghastly Scavenger (Area: The Restless Front) (possible waypoints or random movement)
(@CGUID+490, 47402, 732, 1, 1, -363.286, 1579.21, 21.36363, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+491, 46823, 732, 1, 1, -392.4137, 1573.303, 18.14942, 4.204149, 7200, 0, 0), -- Restless Infantry (Area: The Restless Front)
(@CGUID+492, 47402, 732, 1, 1, -379.177, 1579.98, 18.68373, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+493, 47402, 732, 1, 1, -401.458, 1591.64, 23.30843, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+494, 46825, 732, 1, 1, -393.9391, 1570.565, 18.53442, 1.062417, 7200, 0, 0), -- Restless Soldier (Area: The Restless Front)
(@CGUID+495, 47402, 732, 1, 1, -392.724, 1579.88, 19.13633, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+496, 46960, 732, 1, 1, -366.653, 1569.97, 18.5702, 3.852093, 7200, 0, 0), -- Ghastly Scavenger (Area: The Restless Front) (possible waypoints or random movement)
(@CGUID+497, 47402, 732, 1, 1, -379.964, 1569.19, 18.24303, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+498, 47402, 732, 1, 1, -402.123, 1569.69, 20.67123, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+499, 47402, 732, 1, 1, -393.771, 1561.7, 19.77523, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+500, 47402, 732, 1, 1, -378.33, 1557.23, 19.84153, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+501, 47402, 732, 1, 1, -448.444, 1568.75, 23.63593, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+502, 47402, 732, 1, 1, -457.214, 1597.39, 22.46693, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+503, 47402, 732, 1, 1, -492.523, 1554.43, 21.81043, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+504, 47402, 732, 1, 1, -491.033, 1543.49, 18.87303, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+505, 47402, 732, 1, 1, -425.67, 1590.93, 24.15653, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+506, 47402, 732, 1, 1, -445.639, 1550.52, 21.79153, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+507, 46960, 732, 1, 1, -444.066, 1590.79, 22.1587, 2.897247, 7200, 0, 0), -- Ghastly Scavenger (Area: The Restless Front) (possible waypoints or random movement)
(@CGUID+508, 46960, 732, 1, 1, -492.726, 1511.48, 18.7201, 2.932153, 7200, 0, 0), -- Ghastly Scavenger (Area: The Restless Front) (possible waypoints or random movement)
(@CGUID+509, 46825, 732, 1, 1, -422.378, 1585.55, 24.82113, 1.850049, 7200, 0, 0), -- Restless Soldier (Area: The Restless Front)
(@CGUID+510, 46823, 732, 1, 1, -424.3055, 1588.63, 24.32532, 5.271662, 7200, 0, 0), -- Restless Infantry (Area: The Restless Front)
(@CGUID+511, 47402, 732, 1, 1, -416.957, 1580.53, 24.82153, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+512, 47402, 732, 1, 1, -433.531, 1571.37, 24.19823, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+513, 47402, 732, 1, 1, -435.828, 1563.16, 22.39583, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+514, 1412, 732, 1, 1, -437.7076, 1578.512, 24.09439, 3.422137, 7200, 0, 0), -- Squirrel (Area: The Restless Front)
(@CGUID+515, 47402, 732, 1, 1, -419.703, 1566.04, 22.85193, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+516, 47676, 732, 1, 1, -456.16, 1487.21, 18.75753, 0, 7200, 0, 0), -- Baradin Fox (Area: The Restless Front) (possible waypoints or random movement)
(@CGUID+517, 47402, 732, 1, 1, -449.776, 1604.47, 22.80243, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+518, 1412, 732, 1, 1, -488.6258, 1437.17, 24.22715, 0.3251488, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+519, 47676, 732, 1, 1, -542.483, 1495.89, 24.70783, 0, 7200, 0, 0), -- Baradin Fox (Area: 0) (possible waypoints or random movement)
(@CGUID+520, 47402, 732, 1, 1, -506.344, 1540.72, 23.23343, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+521, 47402, 732, 1, 1, -502.158, 1535.02, 19.82623, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: 0)
(@CGUID+522, 1412, 732, 1, 1, -504.8515, 1547.316, 24.63347, 2.705684, 7200, 0, 0), -- Squirrel (Area: 0)
(@CGUID+523, 48357, 732, 1, 1, -562.0799, 1428.186, 22.13346, 4.101524, 7200, 0, 0), -- Hellscream's Reach Recruit (Area: 0)
(@CGUID+524, 48355, 732, 1, 1, -563.9288, 1432.384, 22.22823, 0.2443461, 7200, 0, 0), -- Hellscream Guard (Area: 0)
(@CGUID+525, 48355, 732, 1, 1, -563.8941, 1410.231, 22.20363, 5.846853, 7200, 0, 0), -- Hellscream Guard (Area: 0) (possible waypoints or random movement)
(@CGUID+526, 48355, 732, 1, 1, -563.929, 1398.98, 22.58263, 0.1047198, 7200, 0, 0), -- Hellscream Guard (Area: 0) (possible waypoints or random movement)
(@CGUID+527, 47676, 732, 1, 1, -506.3584, 1385.245, 22.32938, 1.304081, 7200, 0, 0), -- Baradin Fox (Area: 0) (possible waypoints or random movement)
(@CGUID+528, 46586, 732, 1, 1, -521.208, 1638.32, 47.10563, 0, 7200, 0, 0), -- Wandering Soul (Area: The Restless Front) (possible waypoints or random movement)
(@CGUID+529, 46569, 732, 1, 1, -613.5219, 1659.62, 48.9774, 1.276303, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+530, 46569, 732, 1, 1, -575.802, 1650.64, 49.40943, 1.797689, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+531, 45492, 732, 1, 1, -951.21, 1469.55, 180.1893, 0, 7200, 0, 0), -- Tower Range Finder (Area: Forgotten Hill)
(@CGUID+532, 45561, 732, 1, 1, -937.667, 1462.98, 220.7583, 0, 7200, 0, 0), -- Tower Cannon Target (Area: Forgotten Hill)
(@CGUID+533, 46586, 732, 1, 1, -669.4035, 1693.755, 47.94536, 4.946933, 7200, 0, 0), -- Wandering Soul (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+534, 46569, 732, 1, 1, -657.264, 1693.68, 49.72093, 1.797689, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+535, 46569, 732, 1, 1, -629.641, 1696.78, 54.06843, 1.797689, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+536, 46586, 732, 1, 1, -584.097, 1672.19, 51.12768, 4.711822, 7200, 0, 0), -- Wandering Soul (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+537, 46597, 732, 1, 1, -654.1655, 1720.107, 50.06901, 1.7428, 7200, 0, 0), -- Skeletal Beastmaster (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+538, 46570, 732, 1, 1, -654.3649, 1708.861, 50.06901, 1.999218, 7200, 0, 0), -- Putrid Worg (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+539, 46569, 732, 1, 1, -670.283, 1741.72, 49.28173, 1.797689, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+540, 46586, 732, 1, 1, -648.661, 1737.73, 51.0446, 1.6673, 7200, 0, 0), -- Wandering Soul (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+541, 45561, 732, 1, 1, -962.634, 1462.2, 220.7673, 0, 7200, 0, 0), -- Tower Cannon Target (Area: Forgotten Hill)
(@CGUID+542, 45561, 732, 1, 1, -947.561, 1455.89, 233.0193, 0, 7200, 0, 0), -- Tower Cannon Target (Area: Forgotten Hill)
(@CGUID+543, 45561, 732, 1, 1, -962.757, 1476.2, 235.8503, 0, 7200, 0, 0), -- Tower Cannon Target (Area: Forgotten Hill)
(@CGUID+544, 45561, 732, 1, 1, -957.146, 1458.86, 242.6593, 0, 7200, 0, 0), -- Tower Cannon Target (Area: Forgotten Hill)
(@CGUID+545, 46569, 732, 1, 1, -654.9102, 1798.747, 54.57814, 3.317737, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+546, 46569, 732, 1, 1, -571.0679, 1823.396, 51.28077, 0.1253518, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+547, 46586, 732, 1, 1, -607.0352, 1795.191, 58.78705, 0.372711, 7200, 0, 0), -- Wandering Soul (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+548, 46586, 732, 1, 1, -584.253, 1819.66, 52.76463, 6.029499, 7200, 0, 0), -- Wandering Soul (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+549, 46569, 732, 1, 1, -604.8662, 1878.969, 46.04945, 2.092123, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+550, 46569, 732, 1, 1, -544.585, 1771.439, 59.85944, 4.587973, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+551, 46569, 732, 1, 1, -533.752, 1811.46, 51.74081, 0.3875485, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+552, 46569, 732, 1, 1, -560.9003, 1874.594, 46.9369, 3.533489, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+553, 46569, 732, 1, 1, -487.5607, 1863.571, 46.9278, 0.4180599, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+554, 46569, 732, 1, 1, -572.7311, 1906.424, 49.20108, 0.4038042, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+555, 46569, 732, 1, 1, -540.1494, 1926.244, 48.6778, 4.12107, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+556, 46586, 732, 1, 1, -549.908, 1949.97, 48.74329, 0.683202, 7200, 0, 0), -- Wandering Soul (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+557, 46597, 732, 1, 1, -562.514, 1888.3, 46.6778, 0.8072049, 7200, 0, 0), -- Skeletal Beastmaster (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+558, 46570, 732, 1, 1, -562.4485, 1885.301, 46.6778, 0.8071589, 7200, 0, 0), -- Putrid Worg (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+559, 46597, 732, 1, 1, -538.4165, 1800.679, 52.35487, 1.299271, 7200, 0, 0), -- Skeletal Beastmaster (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+560, 46570, 732, 1, 1, -537.939, 1803.22, 52.24483, 0, 7200, 0, 0), -- Putrid Worg (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+561, 46581, 732, 1, 1, -478.674, 1946.96, 49.26693, 3.176499, 7200, 0, 0), -- Violated Corpse (Area: Forgotten Hill)
(@CGUID+562, 46581, 732, 1, 1, -499.102, 1947.83, 48.91633, 5.497787, 7200, 0, 0), -- Violated Corpse (Area: Forgotten Hill)
(@CGUID+563, 46581, 732, 1, 1, -487.788, 1934.03, 48.13383, 2.268928, 7200, 0, 0), -- Violated Corpse (Area: Forgotten Hill)
(@CGUID+564, 46569, 732, 1, 1, -476.0001, 1882.157, 46.548, 3.128174, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+565, 46569, 732, 1, 1, -521.7513, 1962.487, 49.87758, 0.7759653, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+566, 46586, 732, 1, 1, -451.125, 1949.59, 50.79353, 0.4189579, 7200, 0, 0), -- Wandering Soul (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+567, 46582, 732, 1, 1, -486.91, 1934.54, 48.116, 3.682645, 7200, 0, 0), -- Hungry Ghoul (Area: Forgotten Hill)
(@CGUID+568, 46569, 732, 1, 1, -443.0549, 1926.224, 50.57768, 1.797557, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+569, 46569, 732, 1, 1, -443.8914, 1847.347, 46.96938, 1.754998, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+570, 46586, 732, 1, 1, -443.045, 1834.02, 47.34438, 3.385487, 7200, 0, 0), -- Wandering Soul (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+571, 46569, 732, 1, 1, -402.8918, 1907.888, 51.65094, 1.927295, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+572, 46569, 732, 1, 1, -428.2513, 1894.154, 47.62535, 2.439631, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+573, 46569, 732, 1, 1, -481.91, 1826.19, 46.56703, 1.797689, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+574, 46569, 732, 1, 1, -506.771, 1789.109, 48.22921, 6.021688, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+575, 46582, 732, 1, 1, -496.398, 1738.83, 46.7121, 0.4710633, 7200, 0, 0), -- Hungry Ghoul (Area: Forgotten Hill)
(@CGUID+576, 46586, 732, 1, 1, -506.384, 1753.58, 48.67394, 0.9281309, 7200, 0, 0), -- Wandering Soul (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+577, 46581, 732, 1, 1, -505.516, 1742.62, 48.89993, 0.7330383, 7200, 0, 0), -- Violated Corpse (Area: Forgotten Hill)
(@CGUID+578, 46569, 732, 1, 1, -535.6712, 1740.467, 55.38644, 4.578891, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+579, 46581, 732, 1, 1, -504.865, 1735.8, 48.89883, 2.391101, 7200, 0, 0), -- Violated Corpse (Area: Forgotten Hill)
(@CGUID+580, 46571, 732, 1, 1, -599.1309, 1711.599, 63.42955, 3.120208, 7200, 0, 0), -- First Lieutenant Connor (Area: Forgotten Hill)
(@CGUID+581, 46569, 732, 1, 1, -511.6945, 1687.714, 48.34379, 0.03251244, 7200, 0, 0), -- Forgotten Ghoul (Area: Forgotten Hill)
(@CGUID+582, 46597, 732, 1, 1, -532.674, 1689.7, 49.23832, 0.6757575, 7200, 0, 0), -- Skeletal Beastmaster (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+583, 46570, 732, 1, 1, -533.0023, 1686.718, 49.11332, 0.6757736, 7200, 0, 0), -- Putrid Worg (Area: Forgotten Hill) (possible waypoints or random movement)
(@CGUID+584, 47402, 732, 1, 1, -461.399, 1559.51, 22.17373, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: Forgotten Hill)
(@CGUID+585, 47402, 732, 1, 1, -442.927, 1578.92, 24.04953, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+586, 47402, 732, 1, 1, -441.434, 1599.9, 22.88483, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+587, 46825, 732, 1, 1, -488.698, 1532.32, 18.55773, 5.899213, 7200, 0, 0), -- Restless Soldier (Area: The Restless Front)
(@CGUID+588, 47402, 732, 1, 1, -468.306, 1538.64, 19.12493, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+589, 47402, 732, 1, 1, -479.705, 1525.54, 18.78743, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+590, 47402, 732, 1, 1, -497.465, 1505.16, 19.71903, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+591, 46823, 732, 1, 1, -485.0517, 1531.982, 18.74773, 3.049222, 7200, 0, 0), -- Restless Infantry (Area: The Restless Front)
(@CGUID+592, 47402, 732, 1, 1, -488.816, 1532.05, 18.56403, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+593, 47402, 732, 1, 1, -481.094, 1514.32, 18.50383, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+594, 47402, 732, 1, 1, -497.469, 1525.11, 18.99413, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+595, 46825, 732, 1, 1, -457.479, 1573.42, 24.58333, 5.899213, 7200, 0, 0), -- Restless Soldier (Area: The Restless Front)
(@CGUID+596, 47402, 732, 1, 1, -476.618, 1567.56, 21.84003, 1.064651, 7200, 0, 0), -- Tol Barad - The Restless Front - Quest Bunny (Area: The Restless Front)
(@CGUID+597, 48357, 732, 1, 1, -596.528, 1428.44, 22.13293, 1.047198, 7200, 0, 0), -- Hellscream's Reach Recruit (Area: Hellscream's Grasp)
(@CGUID+598, 48357, 732, 1, 1, -590.7234, 1416.572, 22.00092, 2.180715, 7200, 0, 0), -- Hellscream's Reach Recruit (Area: Hellscream's Grasp) (possible waypoints or random movement)
(@CGUID+599, 48355, 732, 1, 1, -601.7761, 1435.448, 22.13299, 4.468043, 7200, 0, 0), -- Hellscream Guard (Area: Hellscream's Grasp)
(@CGUID+600, 48355, 732, 1, 1, -605.1667, 1434.158, 22.13299, 5.602507, 7200, 0, 0), -- Hellscream Guard (Area: Hellscream's Grasp)
(@CGUID+601, 48357, 732, 1, 1, -578.016, 1394.98, 22.85463, 4.694936, 7200, 0, 0), -- Hellscream's Reach Recruit (Area: Hellscream's Grasp)
(@CGUID+602, 48358, 732, 1, 1, -609.971, 1428.8, 22.13303, 5.358161, 7200, 0, 0), -- Commander Larmash (Area: Hellscream's Grasp)
(@CGUID+603, 48363, 732, 1, 1, -594.509, 1403.89, 21.48223, 6.195919, 7200, 0, 0), -- Captain Prug (Area: Hellscream's Grasp)
(@CGUID+604, 48355, 732, 1, 1, -568.1771, 1379.677, 25.25218, 6.091199, 7200, 0, 0), -- Hellscream Guard (Area: Hellscream's Grasp)
(@CGUID+605, 48361, 732, 1, 1, -584.285, 1387.62, 22.89913, 2.251475, 7200, 0, 0), -- Private Sarlosk (Area: Hellscream's Grasp)
(@CGUID+606, 51287, 732, 1, 1, -613.5452, 1416.637, 22.10571, 5.637414, 7200, 0, 0), -- Colonel Karzag (Area: Hellscream's Grasp)
(@CGUID+607, 48355, 732, 1, 1, -611.1962, 1412.17, 21.83276, 4.21351, 7200, 0, 0), -- Hellscream Guard (Area: Hellscream's Grasp) (possible waypoints or random movement)
(@CGUID+608, 48355, 732, 1, 1, -588.1719, 1382.113, 22.53477, 4.328416, 7200, 0, 0), -- Hellscream Guard (Area: Hellscream's Grasp) (possible waypoints or random movement)
(@CGUID+609, 48531, 732, 1, 1, -619.156, 1411.31, 22.13303, 5.934119, 7200, 0, 0), -- Pogg (Area: Hellscream's Grasp)
(@CGUID+610, 52016, 732, 1, 1, -621.9375, 1405.682, 22.13299, 5.986479, 7200, 0, 0), -- Petty Officer Chulok (Area: Hellscream's Grasp)
(@CGUID+611, 48360, 732, 1, 1, -619.2344, 1397.754, 22.13299, 6.265732, 7200, 0, 0), -- 3rd Officer Kronkar (Area: Hellscream's Grasp)
(@CGUID+612, 48356, 732, 1, 1, -607.5608, 1380.215, 22.09301, 0.418879, 7200, 0, 0), -- Karosh (Area: Hellscream's Grasp)
(@CGUID+613, 50164, 732, 1, 1, -602.4514, 1375.778, 21.82891, 0.5235988, 7200, 0, 0), -- Tulgar Flamefist (Area: Hellscream's Grasp)
(@CGUID+614, 48357, 732, 1, 1, -619.2715, 1390.104, 22.14972, 3.281219, 7200, 0, 0), -- Hellscream's Reach Recruit (Area: Hellscream's Grasp) (possible waypoints or random movement)
(@CGUID+615, 48355, 732, 1, 1, -611.5573, 1374.064, 22.03916, 4.101524, 7200, 0, 0), -- Hellscream Guard (Area: Hellscream's Grasp)
(@CGUID+616, 45067, 732, 1, 1, -545.5989, 1323.38, 22.11739, 0.9599311, 7200, 0, 0), -- Horde Spirit Guide (Area: Hellscream's Grasp)
(@CGUID+617, 45066, 732, 1, 1, -464.741, 1168.69, 15.86763, 0, 7200, 0, 0), -- Alliance Spirit Guide (Area: 0)
(@CGUID+618, 47676, 732, 1, 1, -553.2996, 1174.091, 91.92532, 4.317373, 7200, 0, 0), -- Baradin Fox (Area: 0) (possible waypoints or random movement)
(@CGUID+619, 47676, 732, 1, 1, -438.3537, 1175.566, 14.77156, 4.692861, 7200, 0, 0), -- Baradin Fox (Area: 0) (possible waypoints or random movement)
(@CGUID+620, 47676, 732, 1, 1, -378.1109, 1112.194, 23.07142, 3.453111, 7200, 0, 0), -- Baradin Fox (Area: 0) (possible waypoints or random movement)
(@CGUID+621, 47182, 732, 1, 1, -269.9493, 980.4614, 49.43091, 1.965665, 7200, 0, 0), -- Overlook Spectre (Area: Baradin Base Camp) (possible waypoints or random movement)
(@CGUID+622, 47183, 732, 1, 1, -268.552, 991.3, 48.93091, 3.351032, 7200, 0, 0), -- Ghastly Worker (Area: Baradin Base Camp)
(@CGUID+623, 47183, 732, 1, 1, -253.606, 1022.88, 51.23883, 3.001966, 7200, 0, 0), -- Ghastly Worker (Area: Baradin Base Camp)
(@CGUID+624, 47182, 732, 1, 1, -231.2947, 1019.592, 49.73139, 0.5277099, 7200, 0, 0), -- Overlook Spectre (Area: Baradin Base Camp) (possible waypoints or random movement)
(@CGUID+625, 47181, 732, 1, 1, -283.88, 949.557, 48.97853, 0.3141593, 7200, 0, 0), -- Overlook Spirit (Area: Baradin Base Camp)
(@CGUID+626, 47181, 732, 1, 1, -288.965, 963.29, 49.09733, 0.3141593, 7200, 0, 0), -- Overlook Spirit (Area: Baradin Base Camp)
(@CGUID+627, 48252, 732, 1, 1, -588.118, 1098.523, 97.17506, 3.996804, 7200, 0, 0), -- Baradin Recruit (Area: 0)
(@CGUID+628, 48252, 732, 1, 1, -557.6996, 1102.181, 95.95942, 5.951573, 7200, 0, 0), -- Baradin Recruit (Area: 0)
(@CGUID+629, 48252, 732, 1, 1, -559.4063, 1118.293, 95.80803, 4.276057, 7200, 0, 0), -- Baradin Recruit (Area: 0)
(@CGUID+630, 48253, 732, 1, 1, -589.0677, 1086.505, 97.16693, 0.03490658, 7200, 0, 0), -- Baradin Guard (Area: 0)
(@CGUID+631, 48253, 732, 1, 1, -587.1511, 1085.252, 97.1581, 1.797689, 7200, 0, 0), -- Baradin Guard (Area: 0)
(@CGUID+632, 48357, 732, 1, 1, -571.7483, 1234.813, 91.84469, 0.6981317, 7200, 0, 0), -- Hellscream's Reach Recruit (Area: 0)
(@CGUID+633, 48357, 732, 1, 1, -599.2917, 1213.63, 96.59702, 1.012291, 7200, 0, 0), -- Hellscream's Reach Recruit (Area: 0)
(@CGUID+634, 48355, 732, 1, 1, -593.1371, 1227.898, 93.2985, 5.986479, 7200, 0, 0), -- Hellscream Guard (Area: 0) (possible waypoints or random movement)
(@CGUID+635, 48355, 732, 1, 1, -568.7448, 1221.443, 93.02256, 1.466077, 7200, 0, 0), -- Hellscream Guard (Area: 0) (possible waypoints or random movement)
(@CGUID+636, 48355, 732, 1, 1, -566.6528, 1224.365, 92.73186, 3.490659, 7200, 0, 0); -- Hellscream Guard (Area: 0) (possible waypoints or random movement)


DELETE FROM `npc_vendor` WHERE (`entry`=47328 AND `item`=63517) OR (`entry`=47328 AND `item`=63145) OR (`entry`=47328 AND `item`=63144) OR (`entry`=47328 AND `item`=63391) OR (`entry`=47328 AND `item`=63379) OR (`entry`=47328 AND `item`=63141) OR (`entry`=47328 AND `item`=65175) OR (`entry`=47328 AND `item`=63355) OR (`entry`=47328 AND `item`=63377) OR (`entry`=47328 AND `item`=62473) OR (`entry`=47328 AND `item`=62475) OR (`entry`=47328 AND `item`=62476) OR (`entry`=47328 AND `item`=62474) OR (`entry`=47328 AND `item`=62479) OR (`entry`=47328 AND `item`=62478) OR (`entry`=47328 AND `item`=62477) OR (`entry`=47328 AND `item`=68739) OR (`entry`=47328 AND `item`=62472) OR (`entry`=47328 AND `item`=62471) OR (`entry`=47328 AND `item`=62469) OR (`entry`=47328 AND `item`=62470) OR (`entry`=47328 AND `item`=62468) OR (`entry`=47328 AND `item`=64998) OR (`entry`=47328 AND `item`=63039) OR (`entry`=47328 AND `item`=68769) OR (`entry`=47328 AND `item`=68770) OR (`entry`=47328 AND `item`=68768) OR (`entry`=47328 AND `item`=68774) OR (`entry`=47328 AND `item`=68772) OR (`entry`=47328 AND `item`=68773) OR (`entry`=48251 AND `item`=2901) OR (`entry`=48251 AND `item`=5956) OR (`entry`=48251 AND `item`=2880) OR (`entry`=48251 AND `item`=3466) OR (`entry`=48251 AND `item`=18567) OR (`entry`=48251 AND `item`=3857);
INSERT INTO `npc_vendor` (`entry`, `item`, `slot`, `maxcount`, `ExtendedCost`) VALUES
-- 47328 (Quartermaster Brazie)
(47328, 63517, 1, 0, 3009), -- Baradin's Wardens Commendation
(47328, 63145, 2, 0, 3010), -- Baradin's Wardens Mana Potion
(47328, 63144, 3, 0, 3010), -- Baradin's Wardens Healing Potion
(47328, 63391, 4, 0, 3015), -- Baradin's Wardens Bandage
(47328, 63379, 5, 0, 3013), -- Baradin's Wardens Tabard
(47328, 63141, 6, 0, 3013), -- Tol Barad Searchlight
(47328, 65175, 7, 0, 3013), -- Baradin Footman's Tags
(47328, 63355, 8, 0, 3012), -- Rustberg Gull
(47328, 63377, 9, 0, 3012), -- Baradin's Wardens Battle Standard
(47328, 62473, 10, 0, 3007), -- Blade of the Fearless
(47328, 62475, 11, 0, 3007), -- Dagger of Restless Nights
(47328, 62476, 12, 0, 3007), -- Ravening Slicer
(47328, 62474, 13, 0, 3007), -- Spear of Trailing Shadows
(47328, 62479, 14, 0, 3007), -- Sky Piercer
(47328, 62478, 15, 0, 3007), -- Shimmering Morningstar
(47328, 62477, 16, 0, 3007), -- Insidious Staff
(47328, 68739, 17, 0, 3007), -- Darkheart Hacker
(47328, 62472, 18, 0, 3014), -- Mandala of Stirring Patterns
(47328, 62471, 19, 0, 3014), -- Mirror of Broken Images
(47328, 62469, 20, 0, 3014), -- Impatience of Youth
(47328, 62470, 21, 0, 3014), -- Stump of Time
(47328, 62468, 22, 0, 3014), -- Unsolvable Riddle
(47328, 64998, 23, 0, 3022), -- Reins of the Spectral Steed
(47328, 63039, 24, 0, 3011), -- Reins of the Drake of the West Wind
(47328, 68769, 25, 0, 3013), -- Arcanum of Vicious Agility
(47328, 68770, 26, 0, 3013), -- Arcanum of Vicious Intellect
(47328, 68768, 27, 0, 3013), -- Arcanum of Vicious Strength
(47328, 68774, 28, 0, 3352), -- Greater Inscription of Vicious Agility
(47328, 68772, 29, 0, 3352), -- Greater Inscription of Vicious Intellect
(47328, 68773, 30, 0, 3352), -- Greater Inscription of Vicious Strength
-- 48251 (Kevin Geissler)
(48251, 2901, 1, 0, 0), -- Mining Pick
(48251, 5956, 2, 0, 0), -- Blacksmith Hammer
(48251, 2880, 3, 0, 0), -- Weak Flux
(48251, 3466, 4, 0, 0), -- Strong Flux
(48251, 18567, 5, 0, 0), -- Elemental Flux
(48251, 3857, 6, 0, 0); -- Coal


DELETE FROM `npc_text` WHERE `ID` IN (17463, 17462, 17461, 17464);
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `lang0`, `prob0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`, `text1_0`, `text1_1`, `lang1`, `prob1`, `em1_0`, `em1_1`, `em1_2`, `em1_3`, `em1_4`, `em1_5`, `text2_0`, `text2_1`, `lang2`, `prob2`, `em2_0`, `em2_1`, `em2_2`, `em2_3`, `em2_4`, `em2_5`, `text3_0`, `text3_1`, `lang3`, `prob3`, `em3_0`, `em3_1`, `em3_2`, `em3_3`, `em3_4`, `em3_5`, `text4_0`, `text4_1`, `lang4`, `prob4`, `em4_0`, `em4_1`, `em4_2`, `em4_3`, `em4_4`, `em4_5`, `text5_0`, `text5_1`, `lang5`, `prob5`, `em5_0`, `em5_1`, `em5_2`, `em5_3`, `em5_4`, `em5_5`, `text6_0`, `text6_1`, `lang6`, `prob6`, `em6_0`, `em6_1`, `em6_2`, `em6_3`, `em6_4`, `em6_5`, `text7_0`, `text7_1`, `lang7`, `prob7`, `em7_0`, `em7_1`, `em7_2`, `em7_3`, `em7_4`, `em7_5`, `WDBVerified`) VALUES
(17463, 'Seems like we never run out of things to do around here.  New orders arrive every day at 3am, it''s really strange.', 'Seems like we never run out of things to do around here.  New orders arrive every day at 3am, it''s really strange.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 17463
(17462, 'Welcome to baradin base camp.  I know it does not look like much now, but with a little hard work we can whip this place into shape.', 'Welcome to baradin base camp.  I know it does not look like much now, but with a little hard work we can whip this place into shape.', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 17462
(17461, 'Lots to be done around here, $r.  Are you ready to help?', 'Lots to be done around here, $r.  Are you ready to help?', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595), -- 17461
(17464, 'The Horde have been relentless out here.  Feels like we are fighting two battles at one time.', 'The Horde have been relentless out here.  Feels like we are fighting two battles at one time.
', 0, 1, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, '', '', 0, 0, 0, 0, 0, 0, 0, 0, 15595); -- 17464
