SET @CGUID := 7002096;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+67;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -487.451385498046875, 1496.84375, 31.3963623046875, 5.135924339294433593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+1, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -447.633697509765625, 1443.8697509765625, 37.33308029174804687, 1.669903278350830078, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+2, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -445.40972900390625, 1424.6007080078125, 35.37855148315429687, 4.152340412139892578, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+3, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -425.3350830078125, 1296.546875, 25.004241943359375, 1.000676393508911132, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+4, 125411, 1643, 8721, 9131, '0', 0, 0, 0, 0, -468.89410400390625, 1447.7396240234375, 34.87308502197265625, 4.771852016448974609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+5, 125411, 1643, 8721, 9131, '0', 0, 0, 0, 0, -460.576385498046875, 1471.1319580078125, 30.77823257446289062, 0.133348196744918823, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+6, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -419.87847900390625, 1286.392333984375, 30.4036712646484375, 6.242053031921386718, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+7, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -425.145843505859375, 1356.3385009765625, 27.44501113891601562, 2.957493543624877929, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 239490 - Wolf  Eating)
(@CGUID+8, 125411, 1643, 8721, 9131, '0', 0, 0, 0, 0, -439.83160400390625, 1323.703125, 30.640533447265625, 5.034078598022460937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+9, 130163, 1643, 8721, 9131, '0', 0, 0, 0, 0, -419.192718505859375, 1309.6649169921875, 23.61578369140625, 3.873012065887451171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+10, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -446.546875, 1332.060791015625, 33.40032958984375, 3.850183963775634765, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+11, 130163, 1643, 8721, 9131, '0', 0, 0, 0, 0, -434.414947509765625, 1347.1927490234375, 29.1687469482421875, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+12, 125411, 1643, 8721, 9131, '0', 0, 0, 0, 0, -425.87847900390625, 1338.546875, 33.87694549560546875, 1.619040131568908691, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+13, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -459.3975830078125, 1299.8385009765625, 31.94246864318847656, 2.255613565444946289, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+14, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -429.7413330078125, 1293.94970703125, 25.68096542358398437, 2.631062984466552734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+15, 130163, 1643, 8721, 9131, '0', 0, 0, 0, 0, -443.395843505859375, 1346.421875, 27.46857643127441406, 1.46605539321899414, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+16, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -437.41839599609375, 1313.2291259765625, 37.04510116577148437, 4.3850860595703125, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+17, 130163, 1643, 8721, 9131, '0', 0, 0, 0, 0, -418.8975830078125, 1366.373291015625, 26.60520553588867187, 2.965266704559326171, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+18, 130163, 1643, 8721, 9131, '0', 0, 0, 0, 0, -438.572906494140625, 1324.1927490234375, 25.534942626953125, 0.645033061504364013, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+19, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -406.62847900390625, 1328.6441650390625, 28.99636268615722656, 0.122732363641262054, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+20, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -438.057281494140625, 1326.123291015625, 25.38248062133789062, 1.329856038093566894, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+21, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -475.328125, 1367.032958984375, 36.98270034790039062, 4.521422386169433593, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+22, 130163, 1643, 8721, 9131, '0', 0, 0, 0, 0, -438.586822509765625, 1306.8333740234375, 26.67637825012207031, 2.506459712982177734, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+23, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -467.104156494140625, 1341.4427490234375, 34.2400970458984375, 4.371328353881835937, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+24, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -443.078125, 1355.53125, 39.85689926147460937, 3.239191055297851562, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+25, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -400.37152099609375, 1354.71875, 30.39715003967285156, 5.434140682220458984, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+26, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -447.09722900390625, 1267.9879150390625, 28.98882102966308593, 1.8246384859085083, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+27, 125411, 1643, 8721, 9131, '0', 0, 0, 0, 0, -400.414947509765625, 1345.84033203125, 24.74455451965332031, 5.034078598022460937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+28, 125411, 1643, 8721, 9131, '0', 0, 0, 0, 0, -399.31597900390625, 1346.9478759765625, 24.99071884155273437, 5.783483505249023437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+29, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -454.826385498046875, 1348.7117919921875, 27.57583045959472656, 5.929026603698730468, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+30, 125411, 1643, 8721, 9131, '0', 0, 0, 0, 0, -493.142364501953125, 1399.592041015625, 37.53430938720703125, 6.038350105285644531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+31, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -429.763885498046875, 1380.78125, 34.94255447387695312, 5.356591224670410156, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+32, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -496.317718505859375, 1372.7447509765625, 37.81076812744140625, 4.652164936065673828, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+33, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -439.4913330078125, 1401.6146240234375, 37.03947067260742187, 5.488053798675537109, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+34, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -438.80902099609375, 1392.7552490234375, 28.51511955261230468, 0.830995738506317138, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+35, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -458.661468505859375, 1386.03125, 38.45607376098632812, 1.003318428993225097, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+36, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -436.1319580078125, 1390.1285400390625, 28.437744140625, 5.812026023864746093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+37, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -461.78472900390625, 1379.939208984375, 30.25023460388183593, 1.645619630813598632, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+38, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -444.310760498046875, 1404.32470703125, 39.46106719970703125, 2.443093776702880859, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+39, 130163, 1643, 8721, 9131, '0', 0, 0, 0, 0, -440.657989501953125, 1403.3975830078125, 29.19698143005371093, 5.839547634124755859, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+40, 130163, 1643, 8721, 9131, '0', 0, 0, 0, 0, -475.041656494140625, 1384.388916015625, 30.44873809814453125, 3.998555183410644531, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+41, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -455.899322509765625, 1360.0833740234375, 36.04158401489257812, 2.927256584167480468, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+42, 130163, 1643, 8721, 9131, '0', 0, 0, 0, 0, -497.357635498046875, 1380.54345703125, 30.58850479125976562, 5.560455322265625, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+43, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -476.4444580078125, 1385.032958984375, 38.40036773681640625, 2.973114967346191406, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+44, 130163, 1643, 8721, 9131, '0', 0, 0, 0, 0, -436.34375, 1367.5399169921875, 27.73424339294433593, 6.029979705810546875, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+45, 130163, 1643, 8721, 9131, '0', 0, 0, 0, 0, -476.611114501953125, 1384.29345703125, 30.24235153198242187, 5.185378551483154296, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Estuarine Snail (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+46, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -530.87152099609375, 1411.748291015625, 20.25837135314941406, 3.615460157394409179, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+47, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -468.84027099609375, 1446, 27.95578765869140625, 1.17425537109375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+48, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -488.911468505859375, 1492.02783203125, 31.82497215270996093, 0.333642959594726562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+49, 1412, 1643, 8721, 9131, '0', 0, 0, 0, 0, -490.899322509765625, 1450.0103759765625, 29.81243896484375, 2.678970098495483398, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Squirrel (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+50, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -507.859375, 1469.4896240234375, 31.26980972290039062, 1.674962759017944335, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+51, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -489.1007080078125, 1441.84033203125, 29.57894706726074218, 3.321293592453002929, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+52, 1412, 1643, 8721, 9131, '0', 0, 0, 0, 0, -504.5694580078125, 1440.486083984375, 30.50030326843261718, 2.476181268692016601, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Squirrel (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+53, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -511.35589599609375, 1493.0728759765625, 31.86927986145019531, 4.682045459747314453, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+54, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -530.30035400390625, 1427.8785400390625, 20.30604171752929687, 3.498346567153930664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+55, 125411, 1643, 8721, 9131, '0', 0, 0, 0, 0, -441.586822509765625, 1425.5382080078125, 29.05639457702636718, 1.559823513031005859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 258247 - Perched)
(@CGUID+56, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -468.453125, 1447.7586669921875, 35.83997344970703125, 0.747399032115936279, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+57, 130136, 1643, 8721, 9131, '0', 0, 0, 0, 0, -489.451385498046875, 1435.9461669921875, 36.62079620361328125, 1.708494424819946289, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Wood Moth (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+58, 125411, 1643, 8721, 9131, '0', 0, 0, 0, 0, -474.55035400390625, 1454.357666015625, 35.95967483520507812, 6.038350105285644531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Watchful Raven (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+59, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -476.44964599609375, 1470.2447509765625, 30.7474212646484375, 3.660201549530029296, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2
(@CGUID+60, 125464, 1643, 8721, 9131, '0', 0, 0, 0, 0, -467.4288330078125, 1442.623291015625, 27.8679046630859375, 5.974909782409667968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Darkmaw Prowler (Area: Watcher's Wood - Difficulty: 0) CreateObject2 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+61, 128576, 1643, 8721, 9130, '0', 0, 0, 0, 0, -299.0694580078125, 1227.203125, 5.773092269897460937, 0.794331490993499755, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Aaron Ridgeley (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@CGUID+62, 128577, 1643, 8721, 9130, '0', 0, 0, 0, 0, -304.6944580078125, 1233.2413330078125, 6.128597259521484375, 1.688931465148925781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Amos Ridgeley (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@CGUID+63, 129486, 1643, 8721, 9130, '0', 0, 0, 0, 1, -259.423614501953125, 1170.9583740234375, 7.688189506530761718, 5.953847408294677734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Waycrest Guard (Area: Hangman's Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+64, 129486, 1643, 8721, 9130, '0', 0, 0, 0, 1, -307.432281494140625, 1229.9288330078125, 6.216454029083251953, 3.451224088668823242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Waycrest Guard (Area: Hangman's Point - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+65, 143745, 1643, 8721, 9130, '0', 0, 0, 0, 1, -288.63714599609375, 1186.96875, 10.36710071563720703, 1.114571213722229003, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Guardsman Bray (Area: Hangman's Point - Difficulty: 0) CreateObject1
(@CGUID+66, 129486, 1643, 8721, 9130, '0', 0, 0, 0, 1, -258.234771728515625, 1202.6529541015625, 4.679214954376220703, 5.300433158874511718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Waycrest Guard (Area: Hangman's Point - Difficulty: 0) CreateObject1 (Auras: 244874 - 8.0 Carry Crate New Anim)
(@CGUID+67, 129486, 1643, 8721, 9130, '0', 0, 0, 0, 1, -298.30035400390625, 1192.4322509765625, 10.31019306182861328, 1.01579296588897705, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60257); -- Waycrest Guard (Area: Hangman's Point - Difficulty: 0) CreateObject1 (Auras: )
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+67;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Darkmaw Prowler - 145953 - Cosmetic - Sleep Zzz
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Darkmaw Prowler - 145953 - Cosmetic - Sleep Zzz
(@CGUID+4, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '258247'), -- Watchful Raven - 258247 - Perched
(@CGUID+5, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '258247'), -- Watchful Raven - 258247 - Perched
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '239490'), -- Darkmaw Prowler - 239490 - Wolf  Eating
(@CGUID+8, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '258247'), -- Watchful Raven - 258247 - Perched
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Darkmaw Prowler - 145953 - Cosmetic - Sleep Zzz
(@CGUID+27, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '258247'), -- Watchful Raven - 258247 - Perched
(@CGUID+28, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '258247'), -- Watchful Raven - 258247 - Perched
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Darkmaw Prowler - 145953 - Cosmetic - Sleep Zzz
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Darkmaw Prowler - 145953 - Cosmetic - Sleep Zzz
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Darkmaw Prowler - 145953 - Cosmetic - Sleep Zzz
(@CGUID+48, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Darkmaw Prowler - 145953 - Cosmetic - Sleep Zzz
(@CGUID+55, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '258247'), -- Watchful Raven - 258247 - Perched
(@CGUID+60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- Darkmaw Prowler - 145953 - Cosmetic - Sleep Zzz
(@CGUID+61, 0, 0, 0, 0, 0, 1, 1, 720, 0, 0, 0, 0, ''), -- Aaron Ridgeley
(@CGUID+62, 0, 0, 0, 0, 0, 1, 1, 69, 0, 0, 0, 0, ''), -- Amos Ridgeley
(@CGUID+63, 0, 0, 0, 0, 0, 1, 1, 716, 0, 0, 0, 0, ''), -- Waycrest Guard
(@CGUID+64, 0, 0, 8, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Waycrest Guard
(@CGUID+65, 0, 0, 0, 0, 0, 1, 0, 717, 0, 0, 0, 0, ''), -- Guardsman Bray
(@CGUID+66, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, ''), -- Waycrest Guard - 244874 - 8.0 Carry Crate New Anim
(@CGUID+67, 0, 0, 0, 0, 0, 1, 1, 716, 0, 0, 0, 0, ''); -- Waycrest Guard

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`Entry` IN (143745,129486,128577,128576) AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=143745 AND `DifficultyID`=0); -- 143745 (Guardsman Bray) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=129486 AND `DifficultyID`=0); -- 129486 (Waycrest Guard) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=128577 AND `DifficultyID`=0); -- 128577 (Amos Ridgeley) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=128576 AND `DifficultyID`=0); -- 128576 (Aaron Ridgeley) - CanSwim - CannotTurn

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=128577 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=6217 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=138293 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=90146 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=4470 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=3371 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=128577 AND `item`=39354 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(128577, 15, 64670, 0, 0, 1, 0, 0, 60257), -- Vanishing Powder
(128577, 14, 39505, 0, 0, 1, 0, 0, 60257), -- Virtuoso Inking Set
(128577, 13, 20815, 0, 0, 1, 0, 0, 60257), -- Jeweler's Toolset
(128577, 12, 5956, 0, 0, 1, 0, 0, 60257), -- Blacksmith Hammer
(128577, 11, 6217, 0, 0, 1, 0, 0, 60257), -- Copper Rod
(128577, 10, 6256, 0, 0, 1, 0, 0, 60257), -- Fishing Pole
(128577, 9, 85663, 0, 0, 1, 0, 0, 60257), -- Herbalist's Spade
(128577, 8, 7005, 0, 0, 1, 0, 0, 60257), -- Skinning Knife
(128577, 7, 2901, 0, 0, 1, 0, 0, 60257), -- Mining Pick
(128577, 6, 138293, 0, 0, 1, 0, 0, 60257), -- Explorer's Pack
(128577, 5, 90146, 0, 0, 1, 0, 0, 60257), -- Tinker's Kit
(128577, 4, 4470, 0, 0, 1, 0, 0, 60257), -- Simple Wood
(128577, 3, 38682, 0, 0, 1, 0, 0, 60257), -- Enchanting Vellum
(128577, 2, 3371, 0, 0, 1, 0, 0, 60257), -- Crystal Vial
(128577, 1, 39354, 0, 0, 1, 0, 0, 60257); -- Light Parchment

-- Waycrest Guard smart ai
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 129486;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = -(@CGUID+66);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(-(@CGUID+66), 0, 0, 0, 34, 0, 100, 0, 2, 0, 0, 0, 0, 80, 12948600, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 0 - Self: Start timed action list id #Waycrest Guard #0 (12948600) (update out of combat)', ''),
(-(@CGUID+66), 0, 1, 0, 34, 0, 100, 0, 2, 7, 0, 0, 0, 80, 12948601, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 7 - Self: Start timed action list id #Waycrest Guard #1 (12948601) (update out of combat)', '');

-- Timed list 12948600 smart ai
SET @ENTRY := 12948600;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, 28, 244874, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Remove aura due to spell  244874', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 4000, 4000, 0, 0, 0, 17, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 4 seconds - Self: Set emote state to 0', '');

-- Timed list 12948601 smart ai
SET @ENTRY := 12948601;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 17, 69, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Set emote state to 69', ''),
(@ENTRY, 9, 1, 0, 0, 0, 100, 0, 5000, 5000, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 5 seconds - Self: Set stand state to STAND', ''),
(@ENTRY, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, 85, 244874, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Cast spell 244874 on self', '');

-- Path for Watchful Raven
SET @MOVERGUID := @CGUID+12;
SET @ENTRY := 125411;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Watchful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -426.43213, 1350.014, 33.876945, NULL, 0),
(@PATH, 1, -434.9321, 1357.7311, 33.876945, NULL, 0),
(@PATH, 2, -446.39926, 1357.1774, 33.876945, NULL, 0),
(@PATH, 3, -454.11627, 1348.6774, 33.876945, NULL, 0),
(@PATH, 4, -453.56262, 1337.2102, 33.876945, NULL, 0),
(@PATH, 5, -445.06262, 1329.4933, 33.876945, NULL, 0),
(@PATH, 6, -433.5955, 1330.0469, 33.876945, NULL, 0),
(@PATH, 7, -425.87848, 1338.5469, 33.876945, NULL, 0),
(@PATH, 8, -426.43213, 1350.014, 33.876945, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Watchful Raven
SET @MOVERGUID := @CGUID+30;
SET @ENTRY := 125411;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Watchful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -482.00424, 1396.8092, 37.53431, NULL, 0),
(@PATH, 1, -476.09613, 1386.9657, 37.53431, NULL, 0),
(@PATH, 2, -478.87894, 1375.8275, 37.53431, NULL, 0),
(@PATH, 3, -488.72253, 1369.9194, 37.53431, NULL, 0),
(@PATH, 4, -499.86066, 1372.7023, 37.53431, NULL, 0),
(@PATH, 5, -505.76877, 1382.5458, 37.53431, NULL, 0),
(@PATH, 6, -502.98596, 1393.684, 37.53431, NULL, 0),
(@PATH, 7, -493.14236, 1399.592, 37.53431, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Watchful Raven
SET @MOVERGUID := @CGUID+58;
SET @ENTRY := 125411;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Watchful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -463.41223, 1451.5748, 35.959675, NULL, 0),
(@PATH, 1, -457.50412, 1441.7313, 35.959675, NULL, 0),
(@PATH, 2, -460.28693, 1430.5931, 35.959675, NULL, 0),
(@PATH, 3, -470.13052, 1424.685, 35.959675, NULL, 0),
(@PATH, 4, -481.26865, 1427.4679, 35.959675, NULL, 0),
(@PATH, 5, -487.17676, 1437.3114, 35.959675, NULL, 0),
(@PATH, 6, -484.39395, 1448.4496, 35.959675, NULL, 0),
(@PATH, 7, -474.55035, 1454.3577, 35.959675, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Waycrest Guard
SET @MOVERGUID := @CGUID+66;
SET @ENTRY := 129486;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Waycrest Guard - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -258.17014, 1181.1892, 4.6187, NULL, 6254),
(@PATH, 1, -254.1493, 1191.9584, 4.5019393, NULL, 0),
(@PATH, 2, -257.7691, 1207.4254, 5.0463357, NULL, 0),
(@PATH, 3, -266.65103, 1212.8993, 4.447849, NULL, 0),
(@PATH, 4, -278.17883, 1220.7517, 5.5116234, NULL, 0),
(@PATH, 5, -295.1146, 1233.0348, 6.0147123, NULL, 0),
(@PATH, 6, -302.29514, 1229.033, 5.8426094, NULL, 0),
(@PATH, 7, -304.3941, 1226.3733, 5.9084063, NULL, 6184),
(@PATH, 8, -301.96182, 1230.3577, 5.8536983, NULL, 0),
(@PATH, 9, -295.08853, 1233.9635, 6.075561, NULL, 0),
(@PATH, 10, -288.61807, 1231.0938, 6.3622932, NULL, 0),
(@PATH, 11, -274.83594, 1219.5273, 5.1534486, NULL, 0),
(@PATH, 12, -267.4705, 1212.6666, 4.384971, NULL, 0),
(@PATH, 13, -261.6007, 1207.7014, 4.761236, NULL, 0),
(@PATH, 14, -254.82812, 1197.5435, 4.5962014, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 0);
