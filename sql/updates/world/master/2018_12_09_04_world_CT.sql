SET @CGUID = 5000530;
SET @OGUID = 5000530;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+79;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 29152, 0, 0, 0, '0', '0', 0, 0, 0, -8063.032, 1297.846, 32.78537, 2.548181, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stormwind Dock Worker (Area: -Unknown- - Difficulty: Normal)
(@CGUID+1, 29152, 0, 0, 0, '0', '0', 0, 0, 0, -8064.595, 1302.762, 34.478, 3.036873, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stormwind Dock Worker (Area: -Unknown- - Difficulty: Normal)
(@CGUID+2, 29152, 0, 0, 0, '0', '0', 0, 0, 0, -8046.333, 1305.567, 33.73145, 3.159046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stormwind Dock Worker (Area: -Unknown- - Difficulty: Normal)
(@CGUID+3, 29152, 0, 0, 0, '0', '0', 0, 0, 0, -8077.287, 1298.039, 17.40116, 0.8905672, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Stormwind Dock Worker (Area: -Unknown- - Difficulty: Normal)
(@CGUID+4, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7921.799, 1273.422, 343.4275, 3.069589, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+5, 40789, 0, 1519, 6555, '0', '0', 0, 0, 0, -7915.59, 1261.06, 316.7263, 2.032872, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Generic Controller Bunny (CSA) (Area: Northern Elwynn Mountains - Difficulty: Normal) (Auras: 132221 - FX_Uni_Zeppelin_Propeller_Blades_Loop)
(@CGUID+6, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7925.913, 1276.002, 343.5111, 0.1261023, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+7, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7924.332, 1276.031, 343.4268, 3.14876, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+8, 66292, 0, 1519, 6555, '0', '0', 0, 0, 0, -7879.8, 1279.516, 358.5605, 4.728822, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sky Admiral Rogers (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+9, 66480, 0, 1519, 6555, '0', '0', 0, 0, 0, -7873.549, 1287.455, 341.7665, 1.134044, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Engineer (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+10, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7885.134, 1315.392, 338.9548, 0.01831935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+11, 64866, 0, 1519, 6555, '0', '0', 0, 0, 0, -7878.922, 1280.262, 358.5596, 4.733302, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Corporal Rasmussen (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+12, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7883.45, 1317.521, 338.9523, 0.01831935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+13, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7888.035, 1261.608, 358.5618, 0.08890111, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+14, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7885.151, 1319.556, 338.9543, 0.01831935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+15, 55825, 0, 1519, 6555, '0', '0', 0, 0, 0, -7883.679, 1263.526, 358.5716, 2.055117, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Amber Kearnen (Area: Northern Elwynn Mountains - Difficulty: Normal) (Auras: 131904 - Kearnen's Sniper Rifle)
(@CGUID+16, 55819, 0, 1519, 6555, '0', '0', 0, 0, 0, -7886.452, 1278.299, 358.5595, 5.194313, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sully "The Pickle" McLeary (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+17, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7885.174, 1317.523, 338.9548, 0.01831935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+18, 55823, 0, 1519, 6555, '0', '0', 0, 0, 0, -7884.512, 1266.432, 358.568, 5.011447, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Mishka (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+19, 66473, 0, 1519, 6555, '0', '0', 0, 0, 0, -7893.859, 1306.307, 338.9651, 2.20691, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+20, 66473, 0, 1519, 6555, '0', '0', 0, 0, 0, -7894.149, 1317.889, 338.9651, 2.20691, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+21, 55830, 0, 1519, 6555, '0', '0', 0, 0, 0, -7885.571, 1276.634, 358.5608, 2.303565, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Nimm Codejack (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+22, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7872.691, 1282.875, 358.5561, 3.080679, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+23, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7887.368, 1282.554, 358.5563, 6.19046, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+24, 66473, 0, 1519, 6555, '0', '0', 0, 0, 0, -7894.155, 1327.891, 338.9651, 2.20691, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+25, 64861, 0, 1519, 6555, '0', '0', 0, 0, 0, -7887.71, 1286.335, 341.6577, 1.766042, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Captain Day (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+26, 64863, 0, 1519, 6555, '0', '0', 0, 0, 0, -7880.924, 1280.243, 358.5597, 4.738608, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sky Mage Harlan (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+27, 55832, 0, 1519, 6555, '0', '0', 0, 0, 0, -7882.62, 1265.509, 358.5713, 3.663314, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Nodd Codejack (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+28, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7872.063, 1261.825, 358.562, 3.193963, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+29, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7883.415, 1315.389, 338.9523, 0.01831935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+30, 64860, 0, 1519, 6555, '0', '0', 0, 0, 0, -7871.978, 1286.137, 341.7505, 2.807393, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Captain Kerwin (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+31, 64862, 0, 1519, 6555, '0', '0', 0, 0, 0, -7883.45, 1340.964, 338.9415, 0.08491009, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Airman Ellis (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+32, 66460, 0, 1519, 6555, '0', '0', 0, 0, 0, -7885.137, 1327.727, 338.9454, 0.1137537, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter Pilot (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+33, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7875.502, 1315.352, 338.9449, 3.161203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+34, 64858, 0, 1519, 6555, '0', '0', 0, 0, 0, -7877.587, 1329.174, 338.9409, 2.971559, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Airman Hicks (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+35, 66480, 0, 1519, 6555, '0', '0', 0, 0, 0, -7872.804, 1304.172, 339.2349, 4.737677, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Engineer (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+36, 66480, 0, 1519, 6555, '0', '0', 0, 0, 0, -7893.823, 1352.995, 338.9148, 1.610516, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Engineer (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+37, 55370, 0, 1519, 6555, '0', '0', 0, 0, 0, -7881.208, 1328.651, 350.8466, 0, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- General Purpose Bunny ZTO (Area: Northern Elwynn Mountains - Difficulty: Normal) (Auras: 130860 - Skyfire Defense Patrols)
(@CGUID+38, 66480, 0, 1519, 6555, '0', '0', 0, 0, 0, -7872.366, 1303.059, 339.2785, 2.0365, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Engineer (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+39, 66460, 0, 1519, 6555, '0', '0', 0, 0, 0, -7875.781, 1328.082, 338.941, 2.986098, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter Pilot (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+40, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7877.354, 1319.441, 338.9434, 3.161203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+41, 40789, 0, 1519, 6555, '0', '0', 0, 0, 0, -7880.45, 1331.93, 340.0284, 1.560335, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Generic Controller Bunny (CSA) (Area: Northern Elwynn Mountains - Difficulty: Normal) (Auras: 132223 - FX_AllianceGunship_Idle_Main_Loop)
(@CGUID+42, 66460, 0, 1519, 6555, '0', '0', 0, 0, 0, -7875.729, 1330.123, 338.9402, 3.065017, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter Pilot (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+43, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7877.295, 1317.38, 338.9452, 3.161203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+44, 66473, 0, 1519, 6555, '0', '0', 0, 0, 0, -7866.559, 1306.533, 338.9651, 0.8264614, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+45, 66460, 0, 1519, 6555, '0', '0', 0, 0, 0, -7885.122, 1339.752, 338.942, 6.27965, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter Pilot (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+46, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7877.219, 1315.356, 338.9474, 3.161203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+47, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7875.578, 1317.38, 338.9427, 3.161203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+48, 64859, 0, 1519, 6555, '0', '0', 0, 0, 0, -7880.585, 1326.615, 338.8594, 1.572215, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Sky Captain Callanan (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+49, 66473, 0, 1519, 6555, '0', '0', 0, 0, 0, -7866.804, 1318.089, 338.9651, 0.8264614, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+50, 66473, 0, 1519, 6555, '0', '0', 0, 0, 0, -7894.038, 1341.648, 338.9651, 2.20691, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+51, 66460, 0, 1519, 6555, '0', '0', 0, 0, 0, -7885.262, 1342.182, 338.9436, 0.07160814, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter Pilot (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+52, 66460, 0, 1519, 6555, '0', '0', 0, 0, 0, -7885.554, 1330.129, 338.9424, 0.1888975, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter Pilot (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+53, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7883.434, 1319.554, 338.9518, 0.01831935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+54, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7875.635, 1319.436, 338.9409, 3.161203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+55, 64865, 0, 1519, 6555, '0', '0', 0, 0, 0, -7884.005, 1329.339, 338.9432, 0.2071945, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Airman Rogers (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+56, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7885.194, 1347.033, 338.9465, 0.01831935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+57, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7877.377, 1348.944, 338.941, 3.161203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+58, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7883.531, 1349.089, 338.9448, 0.01831935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+59, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7883.479, 1347.023, 338.9453, 0.01831935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+60, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7885.252, 1349.09, 338.946, 0.01831935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+61, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7885.327, 1351.115, 338.9453, 0.01831935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+62, 66480, 0, 1519, 6555, '0', '0', 0, 0, 0, -7892.847, 1356.231, 338.886, 3.191249, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Engineer (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+63, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7875.694, 1351.075, 338.9398, 3.161203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+64, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7875.67, 1346.911, 338.9397, 3.161203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+65, 66473, 0, 1519, 6555, '0', '0', 0, 0, 0, -7867.073, 1328.108, 338.9651, 0.8264614, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+66, 66460, 0, 1519, 6555, '0', '0', 0, 0, 0, -7875.816, 1342.451, 338.9389, 3.137353, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter Pilot (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+67, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7877.385, 1346.911, 338.9409, 3.161203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+68, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7877.412, 1351.078, 338.941, 3.161203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+69, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7883.608, 1351.111, 338.9441, 0.01831935, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+70, 66473, 0, 1519, 6555, '0', '0', 0, 0, 0, -7867.33, 1341.944, 338.9651, 0.8264614, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+71, 66460, 0, 1519, 6555, '0', '0', 0, 0, 0, -7875.719, 1340.413, 338.9389, 3.058434, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Gyrocopter Pilot (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+72, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7875.647, 1348.943, 338.9397, 3.161203, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+73, 64864, 0, 1519, 6555, '0', '0', 0, 0, 0, -7877.444, 1341.37, 338.9393, 3.084581, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Airman Clifton (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+74, 66480, 0, 1519, 6555, '0', '0', 0, 0, 0, -7874.806, 1377.591, 341.9192, 4.946594, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Engineer (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+75, 40789, 0, 1519, 6555, '0', '0', 0, 0, 0, -7917.61, 1389.77, 302.9963, 2.98015, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Generic Controller Bunny (CSA) (Area: Northern Elwynn Mountains - Difficulty: Normal) (Auras: 132221 - FX_Uni_Zeppelin_Propeller_Blades_Loop)
(@CGUID+76, 66480, 0, 1519, 6555, '0', '0', 0, 0, 0, -7887.297, 1373.201, 341.8466, 3.001966, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Engineer (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+77, 40789, 0, 1519, 6555, '0', '0', 0, 0, 0, -7843.48, 1265.74, 308.8354, 5.264349, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Generic Controller Bunny (CSA) (Area: Northern Elwynn Mountains - Difficulty: Normal) (Auras: 132221 - FX_Uni_Zeppelin_Propeller_Blades_Loop)
(@CGUID+78, 66300, 0, 1519, 6555, '0', '0', 0, 0, 0, -7835.601, 1276.997, 343.51, 3.143929, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843), -- Skyfire Marine (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@CGUID+79, 40789, 0, 1519, 6555, '0', '0', 0, 0, 0, -7842.08, 1389.66, 301.8313, 2.753257, 120, 0, 0, 0, 0, 0, 0, 0, 0, 27843); -- Generic Controller Bunny (CSA) (Area: Northern Elwynn Mountains - Difficulty: Normal) (Auras: 132221 - FX_Uni_Zeppelin_Propeller_Blades_Loop)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+79;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Stormwind Dock Worker
(@CGUID+1, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Stormwind Dock Worker
(@CGUID+2, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Stormwind Dock Worker
(@CGUID+3, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Stormwind Dock Worker
(@CGUID+4, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+5, 0, 0, 0, 1, 0, 0, 0, 0, '132221'), -- Generic Controller Bunny (CSA) - 132221 - FX_Uni_Zeppelin_Propeller_Blades_Loop
(@CGUID+6, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+7, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+8, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sky Admiral Rogers
(@CGUID+9, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Engineer
(@CGUID+10, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+11, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Corporal Rasmussen
(@CGUID+12, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+13, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+14, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+15, 0, 0, 0, 1, 0, 0, 0, 0, '131904'), -- Amber Kearnen - 131904 - Kearnen's Sniper Rifle
(@CGUID+16, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sully "The Pickle" McLeary
(@CGUID+17, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+18, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Mishka
(@CGUID+19, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter
(@CGUID+20, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter
(@CGUID+21, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nimm Codejack
(@CGUID+22, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+23, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+24, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter
(@CGUID+25, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Captain Day
(@CGUID+26, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Sky Mage Harlan
(@CGUID+27, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Nodd Codejack
(@CGUID+28, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+29, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+30, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Captain Kerwin
(@CGUID+31, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Airman Ellis
(@CGUID+32, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter Pilot
(@CGUID+33, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+34, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Airman Hicks
(@CGUID+35, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Engineer
(@CGUID+36, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Engineer
(@CGUID+37, 0, 0, 50331648, 1, 0, 0, 0, 0, '130860'), -- General Purpose Bunny ZTO - 130860 - Skyfire Defense Patrols
(@CGUID+38, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Engineer
(@CGUID+39, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter Pilot
(@CGUID+40, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+41, 0, 0, 0, 1, 0, 0, 0, 0, '132223'), -- Generic Controller Bunny (CSA) - 132223 - FX_AllianceGunship_Idle_Main_Loop
(@CGUID+42, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter Pilot
(@CGUID+43, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+44, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter
(@CGUID+45, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter Pilot
(@CGUID+46, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+47, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+48, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- Sky Captain Callanan
(@CGUID+49, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter
(@CGUID+50, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter
(@CGUID+51, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter Pilot
(@CGUID+52, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter Pilot
(@CGUID+53, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+54, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+55, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Airman Rogers
(@CGUID+56, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+57, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+58, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+59, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+60, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+61, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+62, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Engineer
(@CGUID+63, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+64, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+65, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter
(@CGUID+66, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter Pilot
(@CGUID+67, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+68, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+69, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+70, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter
(@CGUID+71, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter Pilot
(@CGUID+72, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+73, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- Airman Clifton
(@CGUID+74, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Engineer
(@CGUID+75, 0, 0, 0, 1, 0, 0, 0, 0, '132221'), -- Generic Controller Bunny (CSA) - 132221 - FX_Uni_Zeppelin_Propeller_Blades_Loop
(@CGUID+76, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Engineer
(@CGUID+77, 0, 0, 0, 1, 0, 0, 0, 0, '132221'), -- Generic Controller Bunny (CSA) - 132221 - FX_Uni_Zeppelin_Propeller_Blades_Loop
(@CGUID+78, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- Skyfire Marine
(@CGUID+79, 0, 0, 0, 1, 0, 0, 0, 0, '132221'); -- Generic Controller Bunny (CSA) - 132221 - FX_Uni_Zeppelin_Propeller_Blades_Loop

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 294556, 0, 1519, 6555, '0', '0', 0, -9035.306, 1582.431, 0, 4.965549, 0, 0, -0.6121826, 0.7907164, 120, 255, 1, 27843),
(@OGUID+1, 215648, 0, 1519, 6555, '0', '0', 0, -7892.502, 1353.516, 338.8274, 0, 0, 0, 0, 1, 120, 255, 1, 27843), -- Medical Supply Crate (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@OGUID+2, 215648, 0, 1519, 6555, '0', '0', 0, -7894.49, 1354.682, 339.8929, 0, 0, 0, 0, 1, 120, 255, 1, 27843), -- Medical Supply Crate (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@OGUID+3, 215648, 0, 1519, 6555, '0', '0', 0, -7895.234, 1354.653, 338.8319, 0, 0, 0, 0, 1, 120, 255, 1, 27843), -- Medical Supply Crate (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@OGUID+4, 215648, 0, 1519, 6555, '0', '0', 0, -7893.981, 1355.556, 338.817, 0, 0, 0, 0, 1, 120, 255, 1, 27843), -- Medical Supply Crate (Area: Northern Elwynn Mountains - Difficulty: Normal)
(@OGUID+5, 215648, 0, 1519, 6555, '0', '0', 0, -7892.528, 1354.906, 338.8163, 0, 0, 0, 0, 1, 120, 255, 1, 27843); -- Medical Supply Crate (Area: Northern Elwynn Mountains - Difficulty: Normal)

DELETE FROM `creature_template_addon` WHERE `entry` IN (65900 /*65900 (Jadori Ironeye)*/, 65937 /*65937 (Craftsman Hui)*/, 67026 /*67026 (Hao of the Stag's Horns)*/, 65981 /*65981 (Sikki)*/, 66666 /*66666 (Paw'don Defender) - Invisibility and Stealth Detection*/, 65983 /*65983 (Soraka)*/, 67024 /*67024 (Rockseeker Guo)*/, 67025 /*67025 (Orchard Keeper Li Mei)*/, 65982 /*65982 (Bucci)*/, 65926 /*65926 (Tender Long)*/, 54627 /*54627 (Twinspire Taskmaster)*/, 61492 /*61492 (Wounded Pilot) - Wounded Crewman Healing Tracker Proc, Permanent Feign Death (Stun, Anim Only), Critically Wounded*/, 54896 /*54896 (Glade Porcupine)*/, 66092 /*66092 (Point Bunny)*/, 59979 /*59979 (Twinspire Peon)*/, 66501 /*66501 (Sully "The Pickle" McLeary)*/, 66424 /*66424 (Sha Harbinger)*/, 66688 /*66688 (Sha Tendrils) - Sha Tendrils*/, 66433 /*66433 (Skyfire Gyrocopter) - Wrecked Gyrocopter 2*/, 66432 /*66432 (Horde War Wagon) - Permanent Feign Death*/, 63001 /*Silkbead Snail*/, 55336 /*55336 (Silkbead Snail)*/, 66423 /*66423 (Sha Haunt)*/, 66441 /*66441 (Skyfire Marine)*/, 67011 /*Garrosh'ar Grunt - Permanent Feign Death (Stun, Untrackable), Bloody Water Cosmetic*/, 66942 /*Sha Haunt - Permanent Feign Death (Stun, Untrackable)*/, 66747 /*Bloody Pool - Permanent Feign Death (Stun, Untrackable), Bloody Water Cosmetic*/, 66396 /*66396 (Ga'trul) - Greater Demonic Circle: Teleport*/, 66384 /*66384 (Barricade 2 Target Bunny)*/, 66383 /*66383 (Barricade 1 Target Bunny)*/, 66294 /*66294 (Garrosh'ar Grunt) - Permanent Feign Death*/, 64775 /*Masked Tanuki*/, 59311 /*59311 (Veridian Carp)*/, 54616 /*54616 (Sully "The Pickle" McLeary)*/, 66327 /*66327 (Garrosh'ar Shredder)*/, 66457 /*66457 (Garrosh'ar Grunt) - Permanent Feign Death*/, 66280 /*66280 (Garrosh'ar Peon)*/, 66459 /*66459 (Garrosh'ar Shredder) - Permanent Feign Death*/, 67061 /*67061 (Parachute Gear Bunny)*/, 66290 /*66290 (Garrosh'ar Gear-Greaser)*/, 66282 /*66282 (Garrosh'ar Grunt)*/, 66974 /*66974 (Alliance Paratrooper)*/, 66963 /*66963 (Alliance Battlemage) - Arcane Channeling*/, 66371 /*66371 (Fire Stalker) - Cosmetic - Fire, Generic Quest Invisibility 10*/, 62992 /*Bucktooth Flapper*/, 62994 /*Emerald Turtle*/, 62997 /*Jungle Darter*/, 59668 /*59668 (Jungle Darter)*/, 59312 /*59312 (Grove Viper)*/, 64761 /*Jumping Spider*/, 66559 /*66559 (Ship 2 Explosives)*/, 66530 /*66530 (Ship 1 Explosives)*/, 66890 /*66890 (Skyfire Gyrocopter Master)*/, 65840 /*65840 (Strongarm Airman) - Ride Vehicle Hardcoded*/, 66889 /*66889 (Skyfire Gyrocopter) - Ride Vehicle Hardcoded*/, 59666 /*59666 (Emerald Turtle)*/, 66339 /*66339 (Horde War Wagon) - War Wagon Cargo*/, 66397 /*66397 (Garrosh'ar Shredder)*/, 59357 /*59357 (Bucktooth Flapper)*/, 66399 /*66399 (Garrosh'ar Peon)*/, 66435 /*66435 (Garrosh'ar Explosive Barrel)*/, 66341 /*66341 (Garrosh'ar Gear-Greaser) - Ride Vehicle Hardcoded*/, 66434 /*66434 (Garrosh'ar Cannon)*/, 66398 /*Garrosh'ar Grunt*/, 66382 /*66382 (Gyrocopter Facing Bunny)*/, 66509 /*66509 (Amber Kearnen)*/, 66510 /*66510 (Sully "The Pickle" McLeary)*/, 54618 /*54618 (Nimm Codejack)*/, 66527 /*66527 (Mishka)*/, 54615 /*54615 (Nodd Codejack)*/, 66299 /*66299 (Gyrocopter Turret) - Ride Vehicle Hardcoded*/, 66297 /*66297 (Skyfire Gyrocopter) - Gyrocopter Anim Set, Ground*/, 54617 /*Rell Nightwind*/, 62167 /*62167 (General Purpose Bunny ZTO)*/, 64864 /*64864 (Airman Clifton)*/, 64865 /*64865 (Airman Rogers)*/, 64859 /*64859 (Sky Captain Callanan)*/, 55370 /*55370 (General Purpose Bunny ZTO) - Skyfire Defense Patrols*/, 64858 /*64858 (Airman Hicks)*/, 66460 /*Skyfire Gyrocopter Pilot*/, 64862 /*64862 (Airman Ellis)*/, 64860 /*64860 (Captain Kerwin)*/, 55832 /*55832 (Nodd Codejack)*/, 64863 /*64863 (Sky Mage Harlan)*/, 64861 /*64861 (Captain Day)*/, 55830 /*55830 (Nimm Codejack)*/, 66473 /*Skyfire Gyrocopter*/, 55823 /*55823 (Mishka)*/, 55819 /*55819 (Sully "The Pickle" McLeary)*/, 55825 /*55825 (Amber Kearnen) - Kearnen's Sniper Rifle*/, 64866 /*64866 (Corporal Rasmussen)*/, 66480 /*66480 (Skyfire Engineer)*/, 66292 /*Sky Admiral Rogers*/, 66300 /*Skyfire Marine*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `auras`) VALUES
(65900, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 65900 (Jadori Ironeye)
(65937, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 65937 (Craftsman Hui)
(67026, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67026 (Hao of the Stag's Horns)
(65981, 0, 0, 8, 257, 0, 0, 0, 0, ''), -- 65981 (Sikki)
(66666, 0, 0, 0, 256, 0, 0, 0, 0, '18950'), -- 66666 (Paw'don Defender) - Invisibility and Stealth Detection
(65983, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 65983 (Soraka)
(67024, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67024 (Rockseeker Guo)
(67025, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67025 (Orchard Keeper Li Mei)
(65982, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 65982 (Bucci)
(65926, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 65926 (Tender Long)
(54627, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 54627 (Twinspire Taskmaster)
(61492, 0, 0, 0, 1, 0, 0, 0, 0, '119550 130865 130854'), -- 61492 (Wounded Pilot) - Wounded Crewman Healing Tracker Proc, Permanent Feign Death (Stun, Anim Only), Critically Wounded
(54896, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 54896 (Glade Porcupine)
(66092, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66092 (Point Bunny)
(59979, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59979 (Twinspire Peon)
(66501, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66501 (Sully "The Pickle" McLeary)
(66424, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66424 (Sha Harbinger)
(66688, 0, 0, 0, 1, 0, 0, 0, 0, '131011'), -- 66688 (Sha Tendrils) - Sha Tendrils
(66433, 0, 0, 0, 1, 0, 0, 0, 0, '130683'), -- 66433 (Skyfire Gyrocopter) - Wrecked Gyrocopter 2
(66432, 0, 0, 0, 1, 0, 0, 0, 0, '70628'), -- 66432 (Horde War Wagon) - Permanent Feign Death
(63001, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Silkbead Snail
(55336, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55336 (Silkbead Snail)
(66423, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66423 (Sha Haunt)
(66441, 0, 0, 3, 1, 0, 0, 0, 0, ''), -- 66441 (Skyfire Marine)
(67011, 0, 0, 262144, 1, 0, 0, 0, 0, '119073 131770'), -- Garrosh'ar Grunt - Permanent Feign Death (Stun, Untrackable), Bloody Water Cosmetic
(66942, 0, 0, 262144, 1, 0, 0, 0, 0, '119073'), -- Sha Haunt - Permanent Feign Death (Stun, Untrackable)
(66747, 0, 0, 262144, 1, 0, 0, 0, 0, '119073 131770'), -- Bloody Pool - Permanent Feign Death (Stun, Untrackable), Bloody Water Cosmetic
(66396, 0, 0, 0, 1, 0, 0, 0, 0, '130624'), -- 66396 (Ga'trul) - Greater Demonic Circle: Teleport
(66384, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66384 (Barricade 2 Target Bunny)
(66383, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66383 (Barricade 1 Target Bunny)
(66294, 0, 0, 0, 1, 0, 0, 0, 0, '70628'), -- 66294 (Garrosh'ar Grunt) - Permanent Feign Death
(64775, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Masked Tanuki
(59311, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59311 (Veridian Carp)
(54616, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 54616 (Sully "The Pickle" McLeary)
(66327, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66327 (Garrosh'ar Shredder)
(66457, 0, 0, 0, 1, 0, 0, 0, 0, '114371'), -- 66457 (Garrosh'ar Grunt) - Permanent Feign Death
(66280, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66280 (Garrosh'ar Peon)
(66459, 0, 0, 0, 1, 0, 0, 0, 0, '70628'), -- 66459 (Garrosh'ar Shredder) - Permanent Feign Death
(67061, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 67061 (Parachute Gear Bunny)
(66290, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66290 (Garrosh'ar Gear-Greaser)
(66282, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66282 (Garrosh'ar Grunt)
(66974, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66974 (Alliance Paratrooper)
(66963, 0, 0, 0, 1, 0, 0, 0, 0, '39550'), -- 66963 (Alliance Battlemage) - Arcane Channeling
(66371, 0, 0, 50397184, 1, 0, 0, 0, 0, '130483 80852'), -- 66371 (Fire Stalker) - Cosmetic - Fire, Generic Quest Invisibility 10
(62992, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Bucktooth Flapper
(62994, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Emerald Turtle
(62997, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jungle Darter
(59668, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59668 (Jungle Darter)
(59312, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59312 (Grove Viper)
(64761, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Jumping Spider
(66559, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66559 (Ship 2 Explosives)
(66530, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66530 (Ship 1 Explosives)
(66890, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- 66890 (Skyfire Gyrocopter Master)
(65840, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 65840 (Strongarm Airman) - Ride Vehicle Hardcoded
(66889, 0, 0, 50331648, 1, 0, 0, 0, 0, '46598'), -- 66889 (Skyfire Gyrocopter) - Ride Vehicle Hardcoded
(59666, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59666 (Emerald Turtle)
(66339, 0, 0, 0, 1, 0, 0, 0, 0, '130504'), -- 66339 (Horde War Wagon) - War Wagon Cargo
(66397, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66397 (Garrosh'ar Shredder)
(59357, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 59357 (Bucktooth Flapper)
(66399, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66399 (Garrosh'ar Peon)
(66435, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66435 (Garrosh'ar Explosive Barrel)
(66341, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 66341 (Garrosh'ar Gear-Greaser) - Ride Vehicle Hardcoded
(66434, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66434 (Garrosh'ar Cannon)
(66398, 0, 0, 0, 2, 0, 0, 0, 0, ''), -- Garrosh'ar Grunt
(66382, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66382 (Gyrocopter Facing Bunny)
(66509, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 66509 (Amber Kearnen)
(66510, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66510 (Sully "The Pickle" McLeary)
(54618, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- 54618 (Nimm Codejack)
(66527, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66527 (Mishka)
(54615, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 54615 (Nodd Codejack)
(66299, 0, 0, 0, 1, 0, 0, 0, 0, '46598'), -- 66299 (Gyrocopter Turret) - Ride Vehicle Hardcoded
(66297, 0, 0, 0, 1, 0, 0, 0, 0, '131025'), -- 66297 (Skyfire Gyrocopter) - Gyrocopter Anim Set, Ground
(54617, 0, 0, 8, 1, 0, 0, 0, 0, ''), -- Rell Nightwind
(62167, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 62167 (General Purpose Bunny ZTO)
(64864, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64864 (Airman Clifton)
(64865, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64865 (Airman Rogers)
(64859, 0, 0, 0, 256, 0, 0, 0, 0, ''), -- 64859 (Sky Captain Callanan)
(55370, 0, 0, 50331648, 1, 0, 0, 0, 0, '130860'), -- 55370 (General Purpose Bunny ZTO) - Skyfire Defense Patrols
(64858, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64858 (Airman Hicks)
(66460, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter Pilot
(64862, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64862 (Airman Ellis)
(64860, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64860 (Captain Kerwin)
(55832, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55832 (Nodd Codejack)
(64863, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64863 (Sky Mage Harlan)
(64861, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64861 (Captain Day)
(55830, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55830 (Nimm Codejack)
(66473, 0, 0, 50331648, 1, 0, 0, 0, 0, ''), -- Skyfire Gyrocopter
(55823, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55823 (Mishka)
(55819, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 55819 (Sully "The Pickle" McLeary)
(55825, 0, 0, 0, 1, 0, 0, 0, 0, '131904'), -- 55825 (Amber Kearnen) - Kearnen's Sniper Rifle
(64866, 0, 0, 0, 257, 0, 0, 0, 0, ''), -- 64866 (Corporal Rasmussen)
(66480, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- 66480 (Skyfire Engineer)
(66292, 0, 0, 0, 1, 0, 0, 0, 0, ''), -- Sky Admiral Rogers
(66300, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- Skyfire Marine

UPDATE `creature_template_addon` SET `auras`='132221' WHERE `entry`=40789; -- 40789 (Generic Controller Bunny (CSA))
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=29152; -- 29152 (Stormwind Dock Worker)

UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=44668;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45638;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45627;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=44721;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45752;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=44723;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45604;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45607;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=44722;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347222, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=44681;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2832, `CombatReach`=1.8, `VerifiedBuild`=27843 WHERE `DisplayID`=45236;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2976, `CombatReach`=1.2, `VerifiedBuild`=27843 WHERE `DisplayID`=45227;
UPDATE `creature_model_info` SET `BoundingRadius`=0.31, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=40123;
UPDATE `creature_model_info` SET `BoundingRadius`=0.465, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45700;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2976, `CombatReach`=1.2, `VerifiedBuild`=27843 WHERE `DisplayID`=45226;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2976, `CombatReach`=1.2, `VerifiedBuild`=27843 WHERE `DisplayID`=45228;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45551;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45549;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45550;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3, `CombatReach`=0.6, `VerifiedBuild`=27843 WHERE `DisplayID`=44411;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45548;
UPDATE `creature_model_info` SET `BoundingRadius`=0.25, `CombatReach`=0.5, `VerifiedBuild`=27843 WHERE `DisplayID`=40884;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4278, `CombatReach`=1.725, `VerifiedBuild`=27843 WHERE `DisplayID`=44933;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=44969;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=44971;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=44968;
UPDATE `creature_model_info` SET `BoundingRadius`=0.236, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=44970;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3366, `CombatReach`=1.65, `VerifiedBuild`=27843 WHERE `DisplayID`=43210;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45802;
UPDATE `creature_model_info` SET `BoundingRadius`=0.4279, `CombatReach`=1.65, `VerifiedBuild`=27843 WHERE `DisplayID`=45799;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3519, `CombatReach`=1.725, `VerifiedBuild`=27843 WHERE `DisplayID`=45800;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2625, `CombatReach`=0.375, `VerifiedBuild`=27843 WHERE `DisplayID`=36578;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2557212, `VerifiedBuild`=27843 WHERE `DisplayID`=6297;
UPDATE `creature_model_info` SET `BoundingRadius`=0.425056, `CombatReach`=0.3, `VerifiedBuild`=27843 WHERE `DisplayID`=43199;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=44972;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2976, `CombatReach`=1.2, `VerifiedBuild`=27843 WHERE `DisplayID`=44962;
UPDATE `creature_model_info` SET `BoundingRadius`=1, `CombatReach`=6, `VerifiedBuild`=27843 WHERE `DisplayID`=36555;
UPDATE `creature_model_info` SET `BoundingRadius`=0.34, `CombatReach`=2, `VerifiedBuild`=27843 WHERE `DisplayID`=46085;
UPDATE `creature_model_info` SET `BoundingRadius`=0.2976, `CombatReach`=1.2, `VerifiedBuild`=27843 WHERE `DisplayID`=44961;
UPDATE `creature_model_info` SET `BoundingRadius`=2.5, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=44868;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=44973;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=46035;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=46033;
UPDATE `creature_model_info` SET `BoundingRadius`=0.465, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45102;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=46036;
UPDATE `creature_model_info` SET `BoundingRadius`=0.372, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=46037;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3511482, `CombatReach`=0.69, `VerifiedBuild`=27843 WHERE `DisplayID`=44981;
UPDATE `creature_model_info` SET `BoundingRadius`=0.389, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=38873;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45177;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45178;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3366, `CombatReach`=1.65, `VerifiedBuild`=27843 WHERE `DisplayID`=45176;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45205;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45179;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45180;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3519, `CombatReach`=1.725, `VerifiedBuild`=27843 WHERE `DisplayID`=38871;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45182;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45181;
UPDATE `creature_model_info` SET `BoundingRadius`=0.3519, `CombatReach`=1.725, `VerifiedBuild`=27843 WHERE `DisplayID`=38875;
UPDATE `creature_model_info` SET `BoundingRadius`=0.347, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=38872;
UPDATE `creature_model_info` SET `BoundingRadius`=0.306, `CombatReach`=1.5, `VerifiedBuild`=27843 WHERE `DisplayID`=45183;

DELETE FROM `creature_equip_template` WHERE (`CreatureID`=59979 AND `ID`=1) OR (`CreatureID`=66294 AND `ID`=1) OR (`CreatureID`=54616 AND `ID`=1) OR (`CreatureID`=66457 AND `ID`=2) OR (`CreatureID`=66457 AND `ID`=1) OR (`CreatureID`=66290 AND `ID`=3) OR (`CreatureID`=66290 AND `ID`=2) OR (`CreatureID`=66282 AND `ID`=2) OR (`CreatureID`=66282 AND `ID`=1) OR (`CreatureID`=66399 AND `ID`=1) OR (`CreatureID`=66398 AND `ID`=1) OR (`CreatureID`=66480 AND `ID`=3) OR (`CreatureID`=66480 AND `ID`=2);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`) VALUES
(59979, 1, 19014, 0, 0, 0, 0, 0, 0, 0, 0), -- Twinspire Peon
(66294, 1, 5289, 0, 0, 0, 0, 0, 0, 0, 0), -- Garrosh'ar Grunt
(54616, 1, 6219, 0, 0, 0, 0, 0, 0, 0, 0), -- Sully "The Pickle" McLeary
(66457, 2, 5289, 0, 0, 0, 0, 0, 0, 0, 0), -- Garrosh'ar Grunt
(66457, 1, 10612, 0, 0, 12452, 0, 0, 0, 0, 0), -- Garrosh'ar Grunt
(66290, 3, 6219, 0, 0, 0, 0, 0, 0, 0, 0), -- Garrosh'ar Gear-Greaser
(66290, 2, 45123, 0, 0, 0, 0, 0, 0, 0, 0), -- Garrosh'ar Gear-Greaser
(66282, 2, 5289, 0, 0, 0, 0, 0, 0, 0, 0), -- Garrosh'ar Grunt
(66282, 1, 10612, 0, 0, 12452, 0, 0, 0, 0, 0), -- Garrosh'ar Grunt
(66399, 1, 1415, 0, 0, 0, 0, 0, 0, 0, 0), -- Garrosh'ar Peon
(66398, 1, 0, 0, 0, 0, 0, 0, 15323, 0, 0), -- Garrosh'ar Grunt
(66480, 3, 13607, 0, 0, 0, 0, 0, 0, 0, 0), -- Skyfire Engineer
(66480, 2, 1911, 0, 0, 0, 0, 0, 0, 0, 0); -- Skyfire Engineer

UPDATE `creature_equip_template` SET `ItemID1`=1911 WHERE (`CreatureID`=54615 AND `ID`=1); -- Nodd Codejack
UPDATE `creature_equip_template` SET `ItemID1`=2048 WHERE (`CreatureID`=66480 AND `ID`=1); -- Skyfire Engineer

DELETE FROM `gossip_menu` WHERE (`MenuId`=14990 AND `TextId`=21203) OR (`MenuId`=14990 AND `TextId`=21190) OR (`MenuId`=13313 AND `TextId`=18838) OR (`MenuId`=14971 AND `TextId`=21617) OR (`MenuId`=13117 AND `TextId`=18451) OR (`MenuId`=14971 AND `TextId`=21166);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(14990, 21203, 27843), -- Rell Nightwind
(14990, 21190, 27843), -- Rell Nightwind
(13313, 18838, 27843), -- 54616 (Sully "The Pickle" McLeary)
(14971, 21617, 27843), -- Sky Admiral Rogers
(13117, 18451, 27843), -- 54615 (Nodd Codejack)
(14971, 21166, 27843); -- Sky Admiral Rogers

DELETE FROM `gossip_menu_option` WHERE (`MenuId`=14971 AND `OptionIndex`=1) OR (`MenuId`=14971 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(14971, 1, 0, 'You really have it in for the Horde, don\'t you?', 68469, 27843),
(14971, 0, 0, 'I am ready to depart.', 67429, 27843);

UPDATE `creature_template` SET `npcflag`=81 WHERE `entry`=67026; -- Hao of the Stag's Horns
UPDATE `creature_template` SET `minlevel`=120, `maxlevel`=120 WHERE `entry`=66666; -- Paw'don Defender
UPDATE `creature_template` SET `npcflag`=17 WHERE `entry`=65983; -- Soraka
UPDATE `creature_template` SET `npcflag`=81 WHERE `entry`=67025; -- Orchard Keeper Li Mei
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=54896; -- Glade Porcupine
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=66092; -- Point Bunny
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=66501; -- Sully "The Pickle" McLeary
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=66688; -- Sha Tendrils
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=66433; -- Skyfire Gyrocopter
UPDATE `creature_template` SET `unit_flags3`=8193 WHERE `entry`=66432; -- Horde War Wagon
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=66441; -- Skyfire Marine
UPDATE `creature_template` SET `unit_flags3`=8193 WHERE `entry`=67011; -- Garrosh'ar Grunt
UPDATE `creature_template` SET `unit_flags3`=8193 WHERE `entry`=66942; -- Sha Haunt
UPDATE `creature_template` SET `unit_flags`=570688256, `unit_flags3`=8193 WHERE `entry`=66747; -- Bloody Pool
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=66396; -- Ga'trul
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=66384; -- Barricade 2 Target Bunny
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=66383; -- Barricade 1 Target Bunny
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=570720256, `unit_flags2`=2049, `unit_flags3`=8193 WHERE `entry`=66294; -- Garrosh'ar Grunt
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=64775; -- Masked Tanuki
UPDATE `creature_template` SET `gossip_menu_id`=13313, `unit_flags`=33024, `unit_flags3`=1 WHERE `entry`=54616; -- Sully "The Pickle" McLeary
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=66327; -- Garrosh'ar Shredder
UPDATE `creature_template` SET `unit_flags3`=8193 WHERE `entry`=66457; -- Garrosh'ar Grunt
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=66280; -- Garrosh'ar Peon
UPDATE `creature_template` SET `unit_flags3`=8192 WHERE `entry`=66459; -- Garrosh'ar Shredder
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=67061; -- Parachute Gear Bunny
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=66290; -- Garrosh'ar Gear-Greaser
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=66282; -- Garrosh'ar Grunt
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=66974; -- Alliance Paratrooper
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=66963; -- Alliance Battlemage
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=66371; -- Fire Stalker
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=62994; -- Emerald Turtle
UPDATE `creature_template` SET `speed_run`=1.357143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=104892416 WHERE `entry`=66559; -- Ship 2 Explosives
UPDATE `creature_template` SET `speed_run`=1.357143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=104892416 WHERE `entry`=66530; -- Ship 1 Explosives
UPDATE `creature_template` SET `speed_run`=1.357143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=2490 WHERE `entry`=66890; -- Skyfire Gyrocopter Master
UPDATE `creature_template` SET `unit_flags`=33587200, `unit_flags2`=2048 WHERE `entry`=65840; -- Strongarm Airman
UPDATE `creature_template` SET `speed_run`=1.357143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=4196352, `unit_flags3`=1, `VehicleId`=2445 WHERE `entry`=66889; -- Skyfire Gyrocopter
UPDATE `creature_template` SET `speed_run`=1.142857 WHERE `entry`=59666; -- Emerald Turtle
UPDATE `creature_template` SET `speed_run`=1, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=768, `unit_flags2`=71305216, `unit_flags3`=1, `VehicleId`=2460 WHERE `entry`=66339; -- Horde War Wagon
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=66397; -- Garrosh'ar Shredder
UPDATE `creature_template` SET `speed_walk`=0.8, `speed_run`=0.7142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=66399; -- Garrosh'ar Peon
UPDATE `creature_template` SET `speed_run`=1.357143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=102795264 WHERE `entry`=66435; -- Garrosh'ar Explosive Barrel
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=66341; -- Garrosh'ar Gear-Greaser
UPDATE `creature_template` SET `speed_run`=1.357143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=102795264 WHERE `entry`=66434; -- Garrosh'ar Cannon
UPDATE `creature_template` SET `speed_walk`=0.8, `speed_run`=0.7142857, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2099200 WHERE `entry`=66398; -- Garrosh'ar Grunt
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=4196352 WHERE `entry`=66382; -- Gyrocopter Facing Bunny
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=66509; -- Amber Kearnen
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=66510; -- Sully "The Pickle" McLeary
UPDATE `creature_template` SET `npcflag`=17, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=66527; -- Mishka
UPDATE `creature_template` SET `gossip_menu_id`=13117 WHERE `entry`=54615; -- Nodd Codejack
UPDATE `creature_template` SET `faction`=35, `speed_run`=1.357143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33554944, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=2459 WHERE `entry`=66299; -- Gyrocopter Turret
UPDATE `creature_template` SET `speed_run`=1.357143, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048, `unit_flags3`=1, `VehicleId`=2458 WHERE `entry`=66297; -- Skyfire Gyrocopter
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=54617; -- Rell Nightwind
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=62167; -- General Purpose Bunny ZTO
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=64864; -- Airman Clifton
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=64865; -- Airman Rogers
UPDATE `creature_template` SET `unit_flags3`=1 WHERE `entry`=55370; -- General Purpose Bunny ZTO
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=64858; -- Airman Hicks
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=66460; -- Skyfire Gyrocopter Pilot
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=64862; -- Airman Ellis
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=64860; -- Captain Kerwin
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=55832; -- Nodd Codejack
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=64863; -- Sky Mage Harlan
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=64861; -- Captain Day
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=55830; -- Nimm Codejack
UPDATE `creature_template` SET `unit_flags`=0, `unit_flags3`=1 WHERE `entry`=66473; -- Skyfire Gyrocopter
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=55823; -- Mishka
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=55819; -- Sully "The Pickle" McLeary
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=55825; -- Amber Kearnen
UPDATE `creature_template` SET `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=33556480 WHERE `entry`=64866; -- Corporal Rasmussen
UPDATE `creature_template` SET `gossip_menu_id`=14971, `npcflag`=3, `BaseAttackTime`=2000, `RangeAttackTime`=2000, `unit_flags`=33024, `unit_flags2`=2048 WHERE `entry`=66292; -- Sky Admiral Rogers
UPDATE `creature_template` SET `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=66300; -- Skyfire Marine

UPDATE `quest_template` SET `RewardBonusMoney`=840, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=27843 WHERE `ID`=31737; -- The Cost of War
UPDATE `quest_template` SET `RewardBonusMoney`=840, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=27843 WHERE `ID`=31736; -- Envoy of the Alliance
UPDATE `quest_template` SET `RewardBonusMoney`=840, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=27843 WHERE `ID`=31735; -- The Right Tool For The Job
UPDATE `quest_template` SET `RewardBonusMoney`=840, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=27843 WHERE `ID`=31734; -- Welcome Wagons
UPDATE `quest_template` SET `RewardBonusMoney`=840, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=27843 WHERE `ID`=30069; -- No Plan Survives Contact with the Enemy
UPDATE `quest_template` SET `RewardBonusMoney`=840, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=27843 WHERE `ID`=31733; -- Touching Ground
UPDATE `quest_template` SET `RewardBonusMoney`=840, `AllowableRaces`=6130900294268439629, `VerifiedBuild`=27843 WHERE `ID`=31732; -- Unleash Hell


DELETE FROM `creature_template_model` WHERE (`CreatureID`=64761 AND `CreatureDisplayID`=43199);
INSERT INTO `creature_template_model` (`CreatureID`, `Idx`, `CreatureDisplayID`, `DisplayScale`, `Probability`, `VerifiedBuild`) VALUES
(64761, 1, 43199, 1, 1, 27843); -- Jumping Spider

UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=67026 AND `CreatureDisplayID`=45627); -- Hao of the Stag's Horns
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=67024 AND `CreatureDisplayID`=45604); -- Rockseeker Guo
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66092 AND `CreatureDisplayID`=1126); -- Point Bunny
UPDATE `creature_template_model` SET `Idx`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66501 AND `CreatureDisplayID`=26558); -- Sully "The Pickle" McLeary
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66688 AND `CreatureDisplayID`=1126); -- Sha Tendrils
UPDATE `creature_template_model` SET `Probability`=2, `VerifiedBuild`=27843 WHERE (`CreatureID`=63001 AND `CreatureDisplayID`=38380); -- Silkbead Snail
UPDATE `creature_template_model` SET `Probability`=2, `VerifiedBuild`=27843 WHERE (`CreatureID`=55336 AND `CreatureDisplayID`=38380); -- Silkbead Snail
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66747 AND `CreatureDisplayID`=30707); -- Bloody Pool
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=55455 AND `CreatureDisplayID`=1126); -- General Purpose Bunny (DLA)
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66407 AND `CreatureDisplayID`=38873); -- Rell Nightwind
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66388 AND `CreatureDisplayID`=1126); -- Barricade 1 Missile Bunny
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66389 AND `CreatureDisplayID`=1126); -- Barricade 1 Explode Bunny
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66384 AND `CreatureDisplayID`=1126); -- Barricade 2 Target Bunny
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66383 AND `CreatureDisplayID`=1126); -- Barricade 1 Target Bunny
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66294 AND `CreatureDisplayID`=44971); -- Garrosh'ar Grunt
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66294 AND `CreatureDisplayID`=44970); -- Garrosh'ar Grunt
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66294 AND `CreatureDisplayID`=44969); -- Garrosh'ar Grunt
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=64775 AND `CreatureDisplayID`=40093); -- Masked Tanuki
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=54616 AND `CreatureDisplayID`=38872); -- Sully "The Pickle" McLeary
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=67061 AND `CreatureDisplayID`=20570); -- Parachute Gear Bunny
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66558 AND `CreatureDisplayID`=45040); -- Skyfire Gyrocopter Master
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66371 AND `CreatureDisplayID`=1126); -- Fire Stalker
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66528 AND `CreatureDisplayID`=45040); -- Skyfire Gyrocopter Master
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66516 AND `CreatureDisplayID`=45040); -- Skyfire Gyrocopter Master
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=62997 AND `CreatureDisplayID`=6297); -- Jungle Darter
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=59668 AND `CreatureDisplayID`=6297); -- Jungle Darter
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66295 AND `CreatureDisplayID`=25587); -- Skyfire Gyrocopter
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66890 AND `CreatureDisplayID`=45040); -- Skyfire Gyrocopter Master
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66889 AND `CreatureDisplayID`=25587); -- Skyfire Gyrocopter
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66382 AND `CreatureDisplayID`=20570); -- Gyrocopter Facing Bunny
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66509 AND `CreatureDisplayID`=38876); -- Amber Kearnen
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66510 AND `CreatureDisplayID`=38872); -- Sully "The Pickle" McLeary
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=54617 AND `CreatureDisplayID`=38873); -- Rell Nightwind
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66527 AND `CreatureDisplayID`=38870); -- Mishka
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66299 AND `CreatureDisplayID`=44981); -- Gyrocopter Turret
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=66297 AND `CreatureDisplayID`=25587); -- Skyfire Gyrocopter
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=54618 AND `CreatureDisplayID`=38875); -- Nimm Codejack
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=54615 AND `CreatureDisplayID`=38871); -- Nodd Codejack
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=62167 AND `CreatureDisplayID`=1126); -- General Purpose Bunny ZTO
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=55370 AND `CreatureDisplayID`=1126); -- General Purpose Bunny ZTO
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=55832 AND `CreatureDisplayID`=38871); -- Nodd Codejack
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=55830 AND `CreatureDisplayID`=38875); -- Nimm Codejack
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=55825 AND `CreatureDisplayID`=38876); -- Amber Kearnen
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=55823 AND `CreatureDisplayID`=38870); -- Mishka
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=55819 AND `CreatureDisplayID`=38872); -- Sully "The Pickle" McLeary
UPDATE `creature_template_model` SET `Probability`=0, `VerifiedBuild`=27843 WHERE (`CreatureID`=40789 AND `CreatureDisplayID`=26418); -- Generic Controller Bunny (CSA)



UPDATE `gameobject_template` SET `Data4`=0, `VerifiedBuild`=27843 WHERE `entry`=216301; -- Stove
UPDATE `gameobject_template` SET `Data8`=0, `VerifiedBuild`=27843 WHERE `entry`=213090; -- Doodad_PA_EastTemple_DoorTower001
UPDATE `gameobject_template` SET `Data0`=2859, `Data4`=25, `Data5`=50, `Data6`=30, `Data12`=680, `RequiredLevel`=80, `VerifiedBuild`=27843 WHERE `entry`=209353; -- Rain Poppy
UPDATE `gameobject_template` SET `Data0`=2859, `Data4`=1, `Data5`=25, `Data6`=30, `Data12`=683, `RequiredLevel`=80, `VerifiedBuild`=27843 WHERE `entry`=209349; -- Green Tea Leaf
UPDATE `gameobject_template` SET `Data0`=2867, `Data4`=25, `Data5`=75, `Data6`=30, `Data12`=680, `RequiredLevel`=80, `VerifiedBuild`=27843 WHERE `entry`=209311; -- Ghost Iron Deposit

DELETE FROM `npc_text` WHERE `ID` IN (21203 /*21203*/, 21190 /*21190*/, 21617 /*21617*/, 18451 /*18451*/, 21166 /*21166*/);
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(21203, 1, 0, 0, 0, 0, 0, 0, 0, 67594, 0, 0, 0, 0, 0, 0, 0, 27843), -- 21203
(21190, 1, 0, 0, 0, 0, 0, 0, 0, 67535, 0, 0, 0, 0, 0, 0, 0, 27843), -- 21190
(21617, 1, 0, 0, 0, 0, 0, 0, 0, 68467, 0, 0, 0, 0, 0, 0, 0, 27843), -- 21617
(18451, 1, 0, 0, 0, 0, 0, 0, 0, 53772, 0, 0, 0, 0, 0, 0, 0, 27843), -- 18451
(21166, 1, 0, 0, 0, 0, 0, 0, 0, 67428, 0, 0, 0, 0, 0, 0, 0, 27843); -- 21166


DELETE FROM `creature_text` WHERE (`CreatureID`=54615 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=54616 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=54617 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=66282 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=66406 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=66407 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=66978 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=67012 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=67012 AND `GroupID`='1' AND `ID`='0') OR (`CreatureID`=67048 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=67048 AND `GroupID`='1' AND `ID`='0') OR (`CreatureID`=67048 AND `GroupID`='2' AND `ID`='0') OR (`CreatureID`=67048 AND `GroupID`='3' AND `ID`='0') OR (`CreatureID`=67048 AND `GroupID`='4' AND `ID`='0') OR (`CreatureID`=67050 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=67051 AND `GroupID`='0' AND `ID`='0') OR (`CreatureID`=67051 AND `GroupID`='1' AND `ID`='0') OR (`CreatureID`=67051 AND `GroupID`='2' AND `ID`='0') OR (`CreatureID`=67051 AND `GroupID`='3' AND `ID`='0') OR (`CreatureID`=67051 AND `GroupID`='4' AND `ID`='0') OR (`CreatureID`=67051 AND `GroupID`='5' AND `ID`='0');
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(54615, 0, 0, 'Over here, $n! Your gyrocopter\'s ready to go!', 12, 0, 100, 3, 0, 0, 68502, 'Nodd Codejack to Player'),
(54616, 0, 0, 'Level two grappling is done. Now to tighten up level three...', 12, 0, 100, 0, 0, 0, 67467, 'Sully \"The Pickle\" McLeary'),
(54617, 0, 0, 'We are from the Alliance, and mean you no harm. Tell me, what was that shadow you drew out of me?', 12, 0, 100, 1, 0, 32672, 67741, 'Rell Nightwind to Player'),
(66282, 0, 0, 'KIL MOG RO\'TH ', 12, 0, 100, 0, 0, 0, 0, 'Garrosh\'ar Grunt to Player'),
(66406, 0, 0, 'By our sweat and your blood, this land WILL be ours!', 12, 0, 100, 0, 0, 32473, 67592, 'Ga\'trul to Player'),
(66407, 0, 0, 'A warlock! He couldn\'t have ported far - there must be another base.', 12, 0, 100, 1, 0, 32666, 67593, 'Rell Nightwind to Player'),
(66978, 0, 0, 'Men, you\'ve trained for this. You\'re among the elite.  You are Skyfire men!', 12, 0, 100, 0, 0, 32550, 68303, 'Sky Admiral Rogers to Player'),
(67012, 0, 0, 'This is not the place to explain. In short, your own doubts have been made manifest, as a consequence of your actions.', 12, 0, 100, 1, 0, 32563, 67742, 'Taran Zhu to Player'),
(67012, 1, 0, 'Oh, I understand perfectly. I have eyes. But Pandaria is not like whatever land you came from; it lives and breathes. You should be careful what kind of energy you bring here. Now put those weapons away!', 12, 0, 100, 1, 0, 32564, 67744, 'Taran Zhu to Player'),
(67048, 0, 0, 'Admiral, we\'re seeing a significant native presence here. Ornate structures-', 12, 0, 100, 0, 0, 32528, 68006, 'Rell Nightwind to Player'),
(67048, 1, 0, 'You heard the admiral. Concentrate fire on the Horde base. Begin your attack runs.', 12, 0, 100, 0, 0, 32529, 68008, 'Rell Nightwind to Player'),
(67048, 2, 0, 'Use your torpedo rockets on those ships.', 12, 0, 100, 0, 0, 32530, 68010, 'Rell Nightwind to Player'),
(67048, 3, 0, 'Confirmed kill. Nice shooting.', 12, 0, 100, 0, 0, 32531, 68011, 'Rell Nightwind to Player'),
(67048, 4, 0, 'Negative, Admiral. No sign of Captain Taylor OR his flagship.', 12, 0, 100, 0, 0, 32532, 68015, 'Rell Nightwind to Player'),
(67050, 0, 0, 'What in blazes is this?', 12, 0, 100, 0, 0, 27840, 68005, 'Sully \"The Pickle\" McLeary to Player'), -- BroadcastTextID: 54672 - 68005
(67051, 0, 0, 'Cut the chatter, people. Eyes on the target!', 12, 0, 100, 0, 0, 32539, 68007, 'Admiral Rogers to Player'),
(67051, 1, 0, 'Well done. No mercy!', 12, 0, 100, 0, 0, 32540, 68012, 'Admiral Rogers to Player'),
(67051, 2, 0, 'Pay \'em back! Hit them with everything you\'ve got!', 12, 0, 100, 0, 0, 32543, 68019, 'Admiral Rogers to Player'),
(67051, 3, 0, 'That one\'s for Theramore!', 12, 0, 100, 0, 0, 32541, 68013, 'Admiral Rogers to Player'),
(67051, 4, 0, 'Any sign of the flagship down there?', 12, 0, 100, 0, 0, 32542, 68014, 'Admiral Rogers to Player'),
(67051, 5, 0, 'That\'s enough - all wings, report back. Prepare for ground assault.', 12, 0, 100, 0, 0, 32789, 68020, 'Admiral Rogers to Player');

UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=213271; -- Doodad_PA_EastTemple_DoorRound004
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=213270; -- Doodad_PA_EastTemple_DoorRound003
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=213268; -- Doodad_PA_EastTemple_DoorRound001
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=213269; -- Doodad_PA_EastTemple_DoorRound002
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=215586; -- Sha GroundPatch Large Tendrils
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=215567; -- Sha GroundPatch Small Tendrils
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=215566; -- Sha GroundPatch Med Tendrils
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=215394; -- Ga'trul Demonic Circle
UPDATE `gameobject_template_addon` SET `faction`=1375 WHERE `entry`=215387; -- Horde Crate
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=213090; -- Doodad_PA_EastTemple_DoorTower001
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=215133; -- Applebloom Cider
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213839; -- Brazier
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213840; -- Brazier
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=215390; -- Powder Keg
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=215388; -- Orc Refuge Board
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=215389; -- Orc Refuge Board 2
UPDATE `gameobject_template_addon` SET `flags`=32 WHERE `entry`=215318; -- Archimonde Fire
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=209353; -- Rain Poppy
UPDATE `gameobject_template_addon` SET `flags`=278528 WHERE `entry`=209349; -- Green Tea Leaf
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213838; -- Brazier
UPDATE `gameobject_template_addon` SET `flags`=4 WHERE `entry`=213841; -- Brazier
UPDATE `gameobject_template_addon` SET `faction`=1732, `flags`=32 WHERE `entry`=215834; -- Gunship Portal
UPDATE `gameobject_template_addon` SET `faction`=1375, `flags`=32 WHERE `entry`=215835; -- Alliance Gunship Portal Effects
UPDATE `gameobject_template_addon` SET `faction`=94, `flags`=278528 WHERE `entry`=209311; -- Ghost Iron Deposit

DELETE FROM `scene_template` WHERE (`SceneId`=91 AND `ScriptPackageID`=241) OR (`SceneId`=94 AND `ScriptPackageID`=248);
INSERT INTO `scene_template` (`SceneId`, `Flags`, `ScriptPackageID`) VALUES
(91, 1, 241),
(94, 11, 248);


DELETE FROM `quest_poi` WHERE (`QuestID`=31737 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=31736 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=31734 AND `BlobIndex`=0 AND `Idx1`=2) OR (`QuestID`=30069 AND `BlobIndex`=0 AND `Idx1`=3) OR (`QuestID`=31733 AND `BlobIndex`=0 AND `Idx1`=2);
INSERT INTO `quest_poi` (`QuestID`, `BlobIndex`, `Idx1`, `ObjectiveIndex`, `QuestObjectiveID`, `QuestObjectID`, `MapID`, `UiMapID`, `Priority`, `Flags`, `WorldEffectID`, `PlayerConditionID`, `SpawnTrackingID`, `AlwaysAllowMergingBlobs`, `VerifiedBuild`) VALUES
(31737, 0, 3, 32, 0, 0, 870, 371, 0, 0, 0, 0, 716878, 0, 27843), -- The Cost of War
(31736, 0, 2, 32, 0, 0, 870, 371, 0, 0, 0, 0, 716878, 0, 27843), -- Envoy of the Alliance
(31734, 0, 2, 32, 0, 0, 870, 371, 0, 0, 0, 0, 715064, 0, 27843), -- Welcome Wagons
(30069, 0, 3, 32, 0, 0, 870, 371, 0, 0, 0, 0, 715064, 0, 27843), -- No Plan Survives Contact with the Enemy
(31733, 0, 2, 32, 0, 0, 870, 371, 0, 0, 0, 0, 715084, 0, 27843); -- Touching Ground

UPDATE `quest_poi` SET `ObjectiveIndex`=1, `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31737 AND `BlobIndex`=0 AND `Idx1`=2); -- The Cost of War
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31737 AND `BlobIndex`=0 AND `Idx1`=1); -- The Cost of War
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31737 AND `BlobIndex`=0 AND `Idx1`=0); -- The Cost of War
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31736 AND `BlobIndex`=0 AND `Idx1`=1); -- Envoy of the Alliance
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31736 AND `BlobIndex`=0 AND `Idx1`=0); -- Envoy of the Alliance
UPDATE `quest_poi` SET `ObjectiveIndex`=32, `QuestObjectiveID`=0, `QuestObjectID`=0, `WorldEffectID`=0, `SpawnTrackingID`=715078, `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31735 AND `BlobIndex`=0 AND `Idx1`=4); -- The Right Tool For The Job
UPDATE `quest_poi` SET `ObjectiveIndex`=2, `QuestObjectiveID`=269131, `QuestObjectID`=66396, `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31735 AND `BlobIndex`=0 AND `Idx1`=3); -- The Right Tool For The Job
UPDATE `quest_poi` SET `ObjectiveIndex`=1, `WorldEffectID`=0, `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31735 AND `BlobIndex`=0 AND `Idx1`=2); -- The Right Tool For The Job
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31735 AND `BlobIndex`=0 AND `Idx1`=1); -- The Right Tool For The Job
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31735 AND `BlobIndex`=0 AND `Idx1`=0); -- The Right Tool For The Job
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31734 AND `BlobIndex`=0 AND `Idx1`=1); -- Welcome Wagons
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31734 AND `BlobIndex`=0 AND `Idx1`=0); -- Welcome Wagons
UPDATE `quest_poi` SET `ObjectiveIndex`=1, `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=30069 AND `BlobIndex`=0 AND `Idx1`=2); -- No Plan Survives Contact with the Enemy
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=30069 AND `BlobIndex`=0 AND `Idx1`=1); -- No Plan Survives Contact with the Enemy
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=30069 AND `BlobIndex`=0 AND `Idx1`=0); -- No Plan Survives Contact with the Enemy
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31733 AND `BlobIndex`=0 AND `Idx1`=1); -- Touching Ground
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31733 AND `BlobIndex`=0 AND `Idx1`=0); -- Touching Ground
UPDATE `quest_poi` SET `ObjectiveIndex`=32, `QuestObjectiveID`=0, `QuestObjectID`=0, `SpawnTrackingID`=715084, `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `BlobIndex`=0 AND `Idx1`=5); -- Unleash Hell
UPDATE `quest_poi` SET `ObjectiveIndex`=3, `WorldEffectID`=0, `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `BlobIndex`=0 AND `Idx1`=4); -- Unleash Hell
UPDATE `quest_poi` SET `ObjectiveIndex`=2, `QuestObjectiveID`=269137, `QuestObjectID`=66400, `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `BlobIndex`=0 AND `Idx1`=3); -- Unleash Hell
UPDATE `quest_poi` SET `ObjectiveIndex`=1, `QuestObjectiveID`=269136, `QuestObjectID`=66397, `WorldEffectID`=0, `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `BlobIndex`=0 AND `Idx1`=2); -- Unleash Hell
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `BlobIndex`=0 AND `Idx1`=1); -- Unleash Hell
UPDATE `quest_poi` SET `AlwaysAllowMergingBlobs`=0, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `BlobIndex`=0 AND `Idx1`=0); -- Unleash Hell

DELETE FROM `quest_poi_points` WHERE (`QuestID`=31737 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=31736 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=31734 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=30069 AND `Idx1`=3 AND `Idx2`=0) OR (`QuestID`=31733 AND `Idx1`=2 AND `Idx2`=0) OR (`QuestID`=31732 AND `Idx1`=2 AND `Idx2`=10) OR (`QuestID`=31732 AND `Idx1`=2 AND `Idx2`=9) OR (`QuestID`=31732 AND `Idx1`=2 AND `Idx2`=8) OR (`QuestID`=31732 AND `Idx1`=2 AND `Idx2`=7) OR (`QuestID`=31732 AND `Idx1`=2 AND `Idx2`=6) OR (`QuestID`=31732 AND `Idx1`=2 AND `Idx2`=5) OR (`QuestID`=31732 AND `Idx1`=2 AND `Idx2`=4) OR (`QuestID`=31732 AND `Idx1`=2 AND `Idx2`=3) OR (`QuestID`=31732 AND `Idx1`=2 AND `Idx2`=2) OR (`QuestID`=31732 AND `Idx1`=2 AND `Idx2`=1);
INSERT INTO `quest_poi_points` (`QuestID`, `Idx1`, `Idx2`, `X`, `Y`, `VerifiedBuild`) VALUES
(31737, 3, 0, -835, -1793, 27843), -- The Cost of War
(31736, 2, 0, -835, -1793, 27843), -- Envoy of the Alliance
(31734, 2, 0, -568, -1593, 27843), -- Welcome Wagons
(30069, 3, 0, -568, -1593, 27843), -- No Plan Survives Contact with the Enemy
(31733, 2, 0, -665, -1482, 27843), -- Touching Ground
(31732, 2, 10, -899, -1663, 27843), -- Unleash Hell
(31732, 2, 9, -828, -1595, 27843), -- Unleash Hell
(31732, 2, 8, -709, -1523, 27843), -- Unleash Hell
(31732, 2, 7, -593, -1525, 27843), -- Unleash Hell
(31732, 2, 6, -516, -1613, 27843), -- Unleash Hell
(31732, 2, 5, -511, -1653, 27843), -- Unleash Hell
(31732, 2, 4, -514, -1678, 27843), -- Unleash Hell
(31732, 2, 3, -521, -1727, 27843), -- Unleash Hell
(31732, 2, 2, -556, -1746, 27843), -- Unleash Hell
(31732, 2, 1, -716, -1782, 27843); -- Unleash Hell

UPDATE `quest_poi_points` SET `Y`=-1703, `VerifiedBuild`=27843 WHERE (`QuestID`=31737 AND `Idx1`=2 AND `Idx2`=3); -- The Cost of War
UPDATE `quest_poi_points` SET `Y`=-1626, `VerifiedBuild`=27843 WHERE (`QuestID`=31737 AND `Idx1`=2 AND `Idx2`=2); -- The Cost of War
UPDATE `quest_poi_points` SET `Y`=-1718, `VerifiedBuild`=27843 WHERE (`QuestID`=31737 AND `Idx1`=2 AND `Idx2`=0); -- The Cost of War
UPDATE `quest_poi_points` SET `Y`=-1703, `VerifiedBuild`=27843 WHERE (`QuestID`=31737 AND `Idx1`=1 AND `Idx2`=8); -- The Cost of War
UPDATE `quest_poi_points` SET `Y`=-1542, `VerifiedBuild`=27843 WHERE (`QuestID`=31737 AND `Idx1`=1 AND `Idx2`=4); -- The Cost of War
UPDATE `quest_poi_points` SET `Y`=-1540, `VerifiedBuild`=27843 WHERE (`QuestID`=31737 AND `Idx1`=1 AND `Idx2`=3); -- The Cost of War
UPDATE `quest_poi_points` SET `Y`=-1673, `VerifiedBuild`=27843 WHERE (`QuestID`=31737 AND `Idx1`=1 AND `Idx2`=1); -- The Cost of War
UPDATE `quest_poi_points` SET `X`=-768, `Y`=-1701, `VerifiedBuild`=27843 WHERE (`QuestID`=31735 AND `Idx1`=4 AND `Idx2`=0); -- The Right Tool For The Job
UPDATE `quest_poi_points` SET `X`=-833, `Y`=-1797, `VerifiedBuild`=27843 WHERE (`QuestID`=31735 AND `Idx1`=3 AND `Idx2`=0); -- The Right Tool For The Job
UPDATE `quest_poi_points` SET `X`=-821, `Y`=-1761, `VerifiedBuild`=27843 WHERE (`QuestID`=31735 AND `Idx1`=2 AND `Idx2`=0); -- The Right Tool For The Job
UPDATE `quest_poi_points` SET `Y`=-1701, `VerifiedBuild`=27843 WHERE (`QuestID`=31735 AND `Idx1`=0 AND `Idx2`=2); -- The Right Tool For The Job
UPDATE `quest_poi_points` SET `Y`=-1735, `VerifiedBuild`=27843 WHERE (`QuestID`=31734 AND `Idx1`=1 AND `Idx2`=4); -- Welcome Wagons
UPDATE `quest_poi_points` SET `Y`=-1733, `VerifiedBuild`=27843 WHERE (`QuestID`=30069 AND `Idx1`=1 AND `Idx2`=1); -- No Plan Survives Contact with the Enemy
UPDATE `quest_poi_points` SET `X`=-665, `Y`=-1482, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `Idx1`=5 AND `Idx2`=0); -- Unleash Hell
UPDATE `quest_poi_points` SET `X`=-979, `Y`=-1471, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `Idx1`=4 AND `Idx2`=0); -- Unleash Hell
UPDATE `quest_poi_points` SET `X`=-975, `Y`=-1626, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `Idx1`=3 AND `Idx2`=0); -- Unleash Hell
UPDATE `quest_poi_points` SET `X`=-831, `Y`=-1800, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `Idx1`=2 AND `Idx2`=0); -- Unleash Hell
UPDATE `quest_poi_points` SET `Y`=-1480, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `Idx1`=1 AND `Idx2`=9); -- Unleash Hell
UPDATE `quest_poi_points` SET `Y`=-1645, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `Idx1`=1 AND `Idx2`=5); -- Unleash Hell
UPDATE `quest_poi_points` SET `Y`=-1482, `VerifiedBuild`=27843 WHERE (`QuestID`=31732 AND `Idx1`=0 AND `Idx2`=0); -- Unleash Hell

DELETE FROM `quest_request_items` WHERE `ID`=29548;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(29548, 273, 0, 0, 0, 'Ah, a veteran of the Cataclysm campaigns! Good, I could use more experienced hands.', 27843); -- The Mission

UPDATE `creature` SET `terrainSwapMap` = 1066 WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+79;
UPDATE `gameobject` SET `terrainSwapMap` = 1066 WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;

DELETE FROM `terrain_swap_defaults` WHERE `TerrainSwapMap` IN (1066);
INSERT INTO `terrain_swap_defaults` VALUES
(0, 1066, 'Stormwind Gunship Pandaria Start Area');

DELETE FROM `terrain_worldmap` WHERE `TerrainSwapMap` IN (1066);
INSERT INTO `terrain_worldmap` VALUES
(1066, 165, 'Stormwind Gunship Pandaria Start Area');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 25 AND `SourceEntry` = 1066;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(25, 0, 1066, 0, 0, 28, 0, 29548, 0, 0, 0, 0, 0, '', 'TerrainSwap 1066 only when player has quest 29548 complete'),
(25, 0, 1066, 0, 0, 8, 0, 29548, 0, 0, 1, 0, 0, '', 'TerrainSwap 1066 only when player has quest 29548 not rewarded');





