SET @CGUID := 6000900;
SET @OGUID := 6000598;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+69;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 102906, 1481, 7705, 7712, '0', 5533, 0, 0, 1, 1411.625, 1692.0625, 54.54198837280273437, 0.728370308876037597, 120, 0, 0, 3106, 100, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Stalker (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+1, 95447, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1415.82470703125, 1694.529541015625, 54.54123687744140625, 1.942158699035644531, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Warrior (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+2, 95450, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1423.984375, 1702.2691650390625, 54.5418853759765625, 2.023859024047851562, 120, 0, 0, 3106, 100, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Stalker (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+3, 95447, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1417.69970703125, 1697.3350830078125, 54.55347442626953125, 1.963513016700744628, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Warrior (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+4, 95450, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1412.345458984375, 1697.6475830078125, 54.5625, 1.925573587417602539, 120, 0, 0, 3106, 100, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Stalker (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+5, 95449, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1412.7760009765625, 1694.2413330078125, 54.54861068725585937, 1.919604897499084472, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Mystic (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+6, 95447, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1420.3975830078125, 1698.6163330078125, 54.55356979370117187, 1.986568450927734375, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Warrior (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+7, 95449, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1420.282958984375, 1701.2239990234375, 54.55728912353515625, 1.994038701057434082, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Mystic (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+8, 95447, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1421.171875, 1696.6129150390625, 54.55239105224609375, 1.985802173614501953, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Warrior (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+9, 95447, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1422.6597900390625, 1699.970458984375, 54.55168533325195312, 2.006837844848632812, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Warrior (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+10, 95447, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1419.15625, 1693.1961669921875, 54.53298568725585937, 1.961733460426330566, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Warrior (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+11, 95447, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1423.4478759765625, 1697.970458984375, 54.55208206176757812, 2.005845069885253906, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Warrior (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+12, 102905, 1481, 7705, 7712, '0', 5533, 0, 0, 1, 1413.3802490234375, 1692.6353759765625, 54.44904327392578125, 3.337481498718261718, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Mystic (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+13, 95447, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1422.170166015625, 1694.407958984375, 54.55054473876953125, 1.985985159873962402, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Warrior (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+14, 95447, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1415.0538330078125, 1696.529541015625, 54.55555343627929687, 1.942216753959655761, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Warrior (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+15, 95449, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1425.5572509765625, 1700.015625, 54.52951431274414062, 2.027142763137817382, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Mystic (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+16, 90247, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1417.5972900390625, 1701.092041015625, 54.56353378295898437, 1.974173188209533691, 120, 0, 0, 21742, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Battlelord Gaardoun (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+17, 95449, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1415.736083984375, 1699.029541015625, 54.55902862548828125, 1.954349040985107421, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Mystic (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+18, 95447, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1418.484375, 1695.342041015625, 54.54861068725585937, 1.963225841522216796, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Warrior (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+19, 102906, 1481, 7705, 7712, '0', 5533, 0, 0, 1, 1420.2569580078125, 1688.32470703125, 54.73539352416992187, 1.639232635498046875, 120, 0, 0, 3106, 100, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Stalker (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+20, 95450, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1427.3367919921875, 1696.5711669921875, 54.80555343627929687, 2.027734994888305664, 120, 0, 0, 3106, 100, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Stalker (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+21, 95450, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1413.9583740234375, 1691.157958984375, 54.53443145751953125, 1.920032739639282226, 120, 0, 0, 3106, 100, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Stalker (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+22, 95449, 1481, 7705, 7712, '0', 4881, 0, 0, 1, 1421.46875, 1691.6024169921875, 54.53472137451171875, 1.972968935966491699, 120, 0, 0, 2485, 3801, 0, NULL, NULL, NULL, NULL, 52106), -- Ashtongue Mystic (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+23, 93693, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1421.1353759765625, 1811.3785400390625, 62.00347900390625, 5.702109813690185546, 120, 0, 0, 13668, 11403, 0, NULL, NULL, NULL, NULL, 52106), -- Lady S'theno (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+24, 96231, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1424.0625, 1820.8853759765625, 61.99411773681640625, 5.680001258850097656, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Harpooner (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+25, 96228, 1481, 7705, 7712, '0', 4883, 0, 0, 0, 1420.767333984375, 1825.1146240234375, 62.25848388671875, 5.676311016082763671, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Sea-Caller (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+26, 102909, 1481, 7705, 7712, '0', 5534, 0, 0, 1, 1406.013916015625, 1799.7882080078125, 61.86983108520507812, 1.639232635498046875, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Harpooner (Area: Illidari Foothold - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+27, 96228, 1481, 7705, 7712, '0', 4883, 0, 0, 0, 1413.9132080078125, 1815.4427490234375, 61.86469650268554687, 5.703406333923339843, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Sea-Caller (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+28, 96230, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1415.3958740234375, 1811.44970703125, 61.86469650268554687, 5.709230422973632812, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Myrmidon (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+29, 96230, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1408.579833984375, 1814.65283203125, 61.84384536743164062, 5.711519718170166015, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Myrmidon (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+30, 96231, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1411.6492919921875, 1810.6319580078125, 61.86458206176757812, 5.715458869934082031, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Harpooner (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+31, 96230, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1424.5069580078125, 1816.10595703125, 62.12501144409179687, 5.688587188720703125, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Myrmidon (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+32, 102908, 1481, 7705, 7712, '0', 5534, 0, 0, 0, 1409.9375, 1804.5728759765625, 61.87065887451171875, 4.025551795959472656, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Sea-Caller (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+33, 96228, 1481, 7705, 7712, '0', 4883, 0, 0, 0, 1407.7882080078125, 1819.125, 61.99196243286132812, 5.704024314880371093, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Sea-Caller (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+34, 96231, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1413.6458740234375, 1804.892333984375, 61.83557891845703125, 5.724174976348876953, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Harpooner (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+35, 96230, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1424.0728759765625, 1805.9375, 61.19040298461914062, 5.709035873413085937, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Myrmidon (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+36, 96231, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1429.201416015625, 1816.7117919921875, 62.16841506958007812, 5.681227684020996093, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Harpooner (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+37, 96228, 1481, 7705, 7712, '0', 4883, 0, 0, 0, 1407.4791259765625, 1806.7257080078125, 61.87078857421875, 5.728090286254882812, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Sea-Caller (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+38, 96230, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1412.9478759765625, 1820.2899169921875, 61.86469650268554687, 5.695410728454589843, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Myrmidon (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+39, 96231, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1419.3785400390625, 1802.5850830078125, 61.01741409301757812, 5.721629142761230468, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Harpooner (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+40, 96230, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1418.6180419921875, 1815.8819580078125, 61.9149169921875, 5.696618080139160156, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Myrmidon (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+41, 96230, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1427.3228759765625, 1811.517333984375, 61.53296661376953125, 5.693828582763671875, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Myrmidon (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+42, 96231, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1410.25, 1824.8819580078125, 62.00846099853515625, 5.690194129943847656, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Harpooner (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+43, 96230, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1417.829833984375, 1806.767333984375, 61.79859542846679687, 5.71530771255493164, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Myrmidon (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+44, 96231, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1418.15625, 1820.6805419921875, 61.8481903076171875, 5.688055992126464843, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Harpooner (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+45, 96231, 1481, 7705, 7712, '0', 4883, 0, 0, 1, 1403.2847900390625, 1816.3541259765625, 62.5247802734375, 5.714728355407714843, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Coilskar Harpooner (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+46, 96252, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1396.1771240234375, 1742.295166015625, 56.80034637451171875, 6.066824913024902343, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Priestess of Delight (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+47, 96253, 1481, 7705, 7712, '0', 4884, 0, 0, 1, 1397.04345703125, 1738.361083984375, 56.84375, 6.073447704315185546, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Shivarra Destroyer (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+48, 96252, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1391.0399169921875, 1746.8125, 56.80192947387695312, 6.060909271240234375, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Priestess of Delight (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+49, 93707, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1383.5399169921875, 1749.3507080078125, 56.80555343627929687, 6.059463977813720703, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Priestess of Dementia (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+50, 96253, 1481, 7705, 7712, '0', 4884, 0, 0, 1, 1400.90283203125, 1755.4722900390625, 56.62627029418945312, 6.041672706604003906, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Shivarra Destroyer (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+51, 96253, 1481, 7705, 7712, '0', 4884, 0, 0, 1, 1391.7239990234375, 1753.4271240234375, 56.72742843627929687, 6.049134731292724609, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Shivarra Destroyer (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+52, 93707, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1392.7603759765625, 1743.1492919921875, 56.80301666259765625, 6.066640377044677734, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Priestess of Dementia (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+53, 93707, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1393.0989990234375, 1749.71875, 56.800048828125, 6.057927608489990234, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Priestess of Dementia (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+54, 96253, 1481, 7705, 7712, '0', 4884, 0, 0, 1, 1388.4879150390625, 1746.5625, 56.80501556396484375, 6.065701961517333984, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Shivarra Destroyer (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+55, 96252, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1401.657958984375, 1751.857666015625, 56.79340362548828125, 6.047719001770019531, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Priestess of Delight (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+56, 96253, 1481, 7705, 7712, '0', 4884, 0, 0, 1, 1386.5867919921875, 1751.763916015625, 56.78992843627929687, 6.054102420806884765, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Shivarra Destroyer (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+57, 96253, 1481, 7705, 7712, '0', 4884, 0, 0, 1, 1395.953125, 1747.43408203125, 56.801483154296875, 6.059234619140625, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Shivarra Destroyer (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+58, 96252, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1388.9010009765625, 1742.90625, 56.80618667602539062, 6.069037437438964843, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Priestess of Delight (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+59, 96253, 1481, 7705, 7712, '0', 4884, 0, 0, 1, 1386.3941650390625, 1748.4444580078125, 56.80208206176757812, 6.059907913208007812, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Shivarra Destroyer (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+60, 93707, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1393.6927490234375, 1756.8680419921875, 56.4756927490234375, 6.039677619934082031, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Priestess of Dementia (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+61, 94435, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1400.3385009765625, 1745.7742919921875, 56.801483154296875, 6.059029102325439453, 120, 0, 0, 18636, 3068, 0, NULL, NULL, NULL, NULL, 52106), -- Matron Mother Malevolence (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+62, 96252, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1394.8541259765625, 1753.2117919921875, 56.79574203491210937, 6.048208236694335937, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Priestess of Delight (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+63, 96252, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1384.49658203125, 1755.5, 56.88888931274414062, 6.048532962799072265, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Priestess of Delight (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+64, 93707, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1397.810791015625, 1757.4097900390625, 56.44968795776367187, 6.039618968963623046, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Priestess of Dementia (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+65, 96253, 1481, 7705, 7712, '0', 4884, 0, 0, 1, 1390.032958984375, 1756.920166015625, 56.679595947265625, 6.043797016143798828, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Shivarra Destroyer (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+66, 96253, 1481, 7705, 7712, '0', 4884, 0, 0, 1, 1387.1875, 1756.18408203125, 56.51044464111328125, 6.046253204345703125, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Shivarra Destroyer (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+67, 93707, 1481, 7705, 7712, '0', 4884, 0, 0, 0, 1393.578125, 1738.5382080078125, 56.8196563720703125, 6.074434757232666015, 120, 0, 0, 3106, 1534, 0, NULL, NULL, NULL, NULL, 52106), -- Priestess of Dementia (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+68, 96253, 1481, 7705, 7712, '0', 4884, 0, 0, 1, 1398.357666015625, 1751.87158203125, 56.801483154296875, 6.049088954925537109, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106), -- Shivarra Destroyer (Area: Illidari Foothold - Difficulty: 0) CreateObject1
(@CGUID+69, 96253, 1481, 7705, 7712, '0', 4884, 0, 0, 1, 1381.982666015625, 1752.9305419921875, 56.81076431274414062, 6.053945541381835937, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 52106); -- Shivarra Destroyer (Area: Illidari Foothold - Difficulty: 0) CreateObject1

-- GameObject
DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 245686, 1481, 7705, 7712, '0', 5533, 0, 1416.4254150390625, 1690.8663330078125, 54.44605636596679687, 1.11289834976196289, 0, 0, 0.528174400329589843, 0.849135875701904296, 120, 255, 1, 52106); -- DraeneiTotem_Water (scale x1.5) (Area: Illidari Foothold - Difficulty: 0) CreateObject1

-- Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+69;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Ashtongue Stalker
(@CGUID+19, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Ashtongue Stalker
(@CGUID+26, 0, 0, 7, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Coilskar Harpooner

-- Template
UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=52106 WHERE `entry`=245045; -- Rockslide
UPDATE `gameobject_template` SET `ContentTuningId`=699, `VerifiedBuild`=52106 WHERE `entry`=245170; -- Demon Ward
UPDATE `gameobject_template` SET `Data8`=103828, `Data10`=30091, `VerifiedBuild`=52106 WHERE `entry`=254866; -- Anvil
UPDATE `gameobject_template` SET `Data8`=103829, `Data10`=30092, `VerifiedBuild`=52106 WHERE `entry`=254865; -- Forge

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` = 245686 /*DraeneiTotem_Water (scale x1.5)*/;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(245686, 114, 0, 0, 0); -- DraeneiTotem_Water (scale x1.5)

-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` IN (4881, 5533, 4883, 5534, 4884) AND `AreaId` = 7705;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7705, 4881, 'Ashtongue/Battlelord Gaardoun at Illidari Foothold'),
(7705, 5533, 'Injured Ashtongue/Healer at Illidari Foothold'),
(7705, 4883, 'Coilskar/Lady Stheno at Illidari Foothold'),
(7705, 5534, 'Injured Coilskar/Healer at Illidari Foothold'),
(7705, 4884, 'Shivarra/Matron Mother Malevolence at Illidari Foothold');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` IN (4881, 5533, 4883, 5534, 4884) AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4881, 0, 0, 0, 47, 0, 40378, 2|64, 0, 0, 'Apply Phase 4881 if Quest 40378 is completed | rewarded'),
(26, 5533, 0, 0, 0, 48, 0, 40378, 2|64, 0, 0, 'Apply Phase 5533 if Quest 40378 is completed | rewarded'),
(26, 4883, 0, 0, 0, 47, 0, 40379, 2|64, 0, 0, 'Apply Phase 4881 if Quest 40379 is completed | rewarded'),
(26, 5534, 0, 0, 0, 48, 0, 40379, 2|64, 0, 0, 'Apply Phase 5533 if Quest 40379 is completed | rewarded'),
(26, 4884, 0, 0, 0, 48, 0, 38765, 2|64, 0, 0, 'Apply Phase 4884 if Quest 38765 is completed | rewarded');

-- Creature 102905 smart ai
SET @ENTRY := 102905;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 34, 0, 100, 0, 2, 0, 0, 0, 80, 10290500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 0 - Self: Start timed action list id #10290500 (update out of combat)'),
(@ENTRY, 0, 1, 0, '', 34, 0, 100, 0, 2, 2, 0, 0, 80, 10290500, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On movement of type WAYPOINT_MOTION_TYPE inform, point 2 - Self: Start timed action list id #10290500 (update out of combat)');

-- Timed list 10290500 smart ai
SET @ENTRY := 10290500;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES  
(@ENTRY, 9, 0, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 66, 0, 0, 0, 0, 0, 0, 19, 102906, 5, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Look at Closest alive creature Ashtongue Stalker (102906) in 5 yards'),
(@ENTRY, 9, 1, 0, '', 0, 0, 100, 0, 1000, 1000, 0, 0, 128, 4760, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Plays Anim with ID 4760'),
(@ENTRY, 9, 2, 0, '', 0, 0, 100, 0, 16000, 16000, 0, 0, 128, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 17 seconds - Self: Plays Anim with ID 0');

-- Creature 102908 smart ai
SET @ENTRY := 102908;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, '', 60, 0, 100, 0, 1000, 1000, 14000, 14000, 11, 197935, 0, 0, 0, 0, 0, 10, (@CGUID+26), 102909, 0, 0, 0, 0, 0, 'Every 14 seconds (1s initially) - Cast spell 197935 - to Creature Coilskar Harpooner (102909) with guid');

-- Waypoints for CGUID+0
SET @ENTRY := 102905;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1413.38, 1692.635, 54.44904, NULL, 20320),
(@PATH, 1, 1420.476, 1690.905, 54.44016, NULL, 0),
(@PATH, 2, 1421.642, 1690.208, 54.42968, NULL, 19303);

UPDATE `creature` SET `position_x`= 1413.38, `position_y`= 1692.635, `position_z`= 54.44904, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+12;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+12;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+12, @PATH, 1);
