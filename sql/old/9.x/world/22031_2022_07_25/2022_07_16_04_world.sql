SET @CGUID := 460562;
SET @OGUID := 395621;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+58;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
-- arround Starfall Area
(@CGUID+0, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1497.0208740234375, 189.076385498046875, 64.3804931640625, 1.570796370506286621, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+1, 74146, 1116, 6719, 6922, '0', 0, 0, 0, 1, 1483.3228759765625, 21.95833396911621093, 51.65166473388671875, 4.839774131774902343, 7200, 0, 0, 715, 0, 0, 0, 0, 0, 44325), -- Podling Nibbler (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+2, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1479.5850830078125, 138.92535400390625, 67.232574462890625, 2.094395160675048828, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+3, 82425, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1580.9114990234375, 62.18576431274414062, 64.76389312744140625, 2.094395160675048828, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165966 - Flower Spell)
(@CGUID+4, 82378, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1592.681884765625, 19.79453468322753906, 56.88349151611328125, 3.605240345001220703, 7200, 0, 0, 4926, 0, 0, 0, 0, 0, 44325), -- Moonbark Ancient (Area: -Unknown- - Difficulty: 0)
(@CGUID+5, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1550.6961669921875, 33.66840362548828125, 59.78125, 1.570796370506286621, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+6, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1582.296875, 62.47048568725585937, 64.91320037841796875, 2.094395160675048828, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+7, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1487.7379150390625, 137.907989501953125, 67.55590057373046875, 2.094395160675048828, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+8, 72829, 1116, 6719, 6922, '0', 0, 0, 0, 1, 1483.3228759765625, 21.95833396911621093, 51.65166473388671875, 4.839774131774902343, 7200, 0, 0, 1478, 0, 0, 0, 0, 0, 44325), -- Podling Bopper (Area: -Unknown- - Difficulty: 0)
(@CGUID+9, 82425, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1549.685791015625, 32.70659637451171875, 59.61667633056640625, 1.570796370506286621, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165966 - Flower Spell)
(@CGUID+10, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1554.138916015625, 28.546875, 58.62847137451171875, 1.570796370506286621, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+11, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1498.2222900390625, 189.9496612548828125, 64.4482574462890625, 1.570796370506286621, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+12, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1479.7396240234375, 137.8993072509765625, 67.23810577392578125, 2.094395160675048828, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+13, 82425, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1484.8004150390625, 138.157989501953125, 67.4537353515625, 2.094395160675048828, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165966 - Flower Spell)
(@CGUID+14, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1578.3472900390625, 59.59375, 64.1466064453125, 2.094395160675048828, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+15, 82378, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1578.2525634765625, 138.3149566650390625, 72.64150238037109375, 5.971622943878173828, 7200, 0, 0, 4926, 0, 0, 0, 0, 0, 44325), -- Moonbark Ancient (Area: -Unknown- - Difficulty: 0)
(@CGUID+16, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1501.7569580078125, 193.109375, 64.71401214599609375, 1.570796370506286621, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+17, 74146, 1116, 6719, 6922, '0', 0, 0, 0, 1, 1480.298583984375, 45.5711822509765625, 54.77335739135742187, 1.698181033134460449, 7200, 0, 0, 715, 0, 0, 0, 0, 0, 44325), -- Podling Nibbler (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%)
(@CGUID+18, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1486.798583984375, 137.5572967529296875, 67.52127838134765625, 2.094395160675048828, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+19, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1552.7535400390625, 28.26215362548828125, 58.62152862548828125, 1.570796370506286621, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+20, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1579.7379150390625, 59.65277862548828125, 64.24840545654296875, 2.094395160675048828, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+21, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1578.751708984375, 58.76909637451171875, 64.03403472900390625, 2.094395160675048828, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+22, 82378, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1456.270263671875, 298.112823486328125, 61.76134109497070312, 1.534648776054382324, 7200, 0, 0, 4926, 0, 0, 0, 0, 0, 44325), -- Moonbark Ancient (Area: -Unknown- - Difficulty: 0)
(@CGUID+23, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1551.0260009765625, 208.333984375, 72.52042388916015625, 5.24076700210571289, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+24, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1553.513916015625, 208.333984375, 72.81888580322265625, 4.825351715087890625, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+25, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1550.27783203125, 207.65625, 72.56595611572265625, 2.231862068176269531, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+26, 82425, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1546.6961669921875, 209.4340362548828125, 72.58475494384765625, 5.575625896453857421, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165966 - Flower Spell)
(@CGUID+27, 82425, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1501.423583984375, 194.1875, 64.67360687255859375, 1.570796370506286621, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165966 - Flower Spell)
(@CGUID+28, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1547.140625, 208.333984375, 72.58475494384765625, 5.626758575439453125, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
(@CGUID+29, 80818, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1502.611083984375, 193.6631927490234375, 64.79534912109375, 1.570796370506286621, 7200, 0, 0, 739, 0, 0, 0, 0, 0, 44325), -- Luminous Orchid (Area: -Unknown- - Difficulty: 0) (Auras: 165960 - Flower Spell)
-- Drybone Hollow Area
(@CGUID+30, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1472.6441650390625, -37.9635429382324218, 56.1920928955078125, 3.054596662521362304, 7200, 0, 0, 3695, 0, 0, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk, 145363 - Permanent Feign Death (Stun, Untrackable, Immune))
(@CGUID+31, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1353.247314453125, -118.747444152832031, 73.98520660400390625, 6.2636566162109375, 7200, 10, 0, 3695, 0, 1, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk) (possible waypoints or random movement)
(@CGUID+32, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1412.0833740234375, -28.7941913604736328, 68.843048095703125, 0.033223349601030349, 7200, 10, 0, 3695, 0, 1, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk) (possible waypoints or random movement)
(@CGUID+33, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1399.673583984375, -113.138893127441406, 69.02782440185546875, 0.109899066388607025, 7200, 0, 0, 3695, 0, 0, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk)
(@CGUID+34, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1417.953125, -99.6891403198242187, 69.12538909912109375, 5.555084705352783203, 7200, 10, 0, 3695, 0, 1, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk) (possible waypoints or random movement)
(@CGUID+35, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1519, -63.2569465637207031, 53.48203659057617187, 3.936436414718627929, 7200, 0, 0, 3695, 0, 0, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk, 145363 - Permanent Feign Death (Stun, Untrackable, Immune))
(@CGUID+36, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1371.8975830078125, -84.1487274169921875, 79.3175201416015625, 5.468388557434082031, 7200, 10, 0, 3695, 0, 1, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk) (possible waypoints or random movement)
(@CGUID+37, 74630, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1427.1146240234375, -185.276046752929687, 46.35763931274414062, 1.867728710174560546, 7200, 0, 0, 3079, 0, 0, 0, 0, 0, 44325), -- Pearltusk Grazer (Area: -Unknown- - Difficulty: 0) (Auras: 145363 - Permanent Feign Death (Stun, Untrackable, Immune))
(@CGUID+38, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1333.5504150390625, -23.7361106872558593, 79.564239501953125, 1.020556926727294921, 7200, 0, 0, 3695, 0, 0, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk)
(@CGUID+39, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1344.8072509765625, -12.9253473281860351, 77.6403961181640625, 3.812715530395507812, 7200, 0, 0, 3695, 0, 0, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk)
(@CGUID+40, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1388.5845947265625, -257.28839111328125, 39.38071441650390625, 4.980096817016601562, 7200, 10, 0, 3695, 0, 1, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk) (possible waypoints or random movement)
(@CGUID+41, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1332.670166015625, -238.593856811523437, 45.24496841430664062, 4.672371387481689453, 7200, 10, 0, 3695, 0, 1, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk) (possible waypoints or random movement)
(@CGUID+42, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1326.361083984375, -136.114578247070312, 71.15111541748046875, 4.995287895202636718, 7200, 0, 0, 3695, 0, 0, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk)
(@CGUID+43, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1424.0830078125, 27.38682937622070312, 64.88159942626953125, 3.908333778381347656, 7200, 10, 0, 3695, 0, 1, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk) (possible waypoints or random movement)
(@CGUID+44, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1318.16943359375, -49.0639724731445312, 80.20215606689453125, 1.744161367416381835, 7200, 10, 0, 3695, 0, 1, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk) (possible waypoints or random movement)
(@CGUID+45, 82452, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1375.2171630859375, -176.95135498046875, 53.05428314208984375, 2.322344303131103515, 7200, 10, 0, 3695, 0, 1, 0, 0, 0, 44325), -- Ancient Pearltusk (Area: -Unknown- - Difficulty: 0) (Auras: 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk)
(@CGUID+46, 82175, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1524.5260009765625, -45.0850715637207031, 64.13011932373046875, 3.707200050354003906, 7200, 0, 0, 1478, 0, 0, 0, 0, 0, 44325), -- Silverwing Kaliri (Area: -Unknown- - Difficulty: 0)
(@CGUID+47, 82175, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1471.5711669921875, -45.6458320617675781, 59.42312240600585937, 6.116333484649658203, 7200, 0, 0, 1478, 0, 0, 0, 0, 0, 44325), -- Silverwing Kaliri (Area: -Unknown- - Difficulty: 0)
(@CGUID+48, 82175, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1503.4207763671875, -66.45074462890625, 81.74698638916015625, 3.468613147735595703, 7200, 0, 0, 1478, 0, 0, 0, 0, 0, 44325), -- Silverwing Kaliri (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+49, 82175, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1481.583740234375, -81.8828201293945312, 75.0546112060546875, 2.488287925720214843, 7200, 0, 0, 1478, 0, 0, 0, 0, 0, 44325), -- Silverwing Kaliri (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+50, 82175, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1454.1947021484375, -49.0236740112304687, 85.34436798095703125, 4.817780494689941406, 7200, 0, 0, 1478, 0, 0, 0, 0, 0, 44325), -- Silverwing Kaliri (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+51, 82175, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1464.0740966796875, -93.2930831909179687, 78.9487457275390625, 3.498936653137207031, 7200, 0, 0, 1478, 0, 0, 0, 0, 0, 44325), -- Silverwing Kaliri (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+52, 82175, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1519.1024169921875, -42.40625, 60.33039474487304687, 2.898360729217529296, 7200, 0, 0, 1478, 0, 0, 0, 0, 0, 44325), -- Silverwing Kaliri (Area: -Unknown- - Difficulty: 0)
(@CGUID+53, 82175, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1524.19970703125, -26.010416030883789, 80.04514312744140625, 3.776721477508544921, 7200, 0, 0, 1478, 0, 0, 0, 0, 0, 44325), -- Silverwing Kaliri (Area: -Unknown- - Difficulty: 0)
(@CGUID+54, 82175, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1515.9410400390625, -16.0763893127441406, 81.74346923828125, 4.005383968353271484, 7200, 0, 0, 1478, 0, 0, 0, 0, 0, 44325), -- Silverwing Kaliri (Area: -Unknown- - Difficulty: 0)
(@CGUID+55, 82175, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1525.43408203125, -40.6284713745117187, 65.33887481689453125, 3.226366996765136718, 7200, 0, 0, 1478, 0, 0, 0, 0, 0, 44325), -- Silverwing Kaliri (Area: -Unknown- - Difficulty: 0)
(@CGUID+56, 82175, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1512.57470703125, -12.5763893127441406, 81.13185882568359375, 4.153119564056396484, 7200, 0, 0, 1478, 0, 0, 0, 0, 0, 44325), -- Silverwing Kaliri (Area: -Unknown- - Difficulty: 0)
(@CGUID+57, 75484, 1116, 6719, 7232, '0', 0, 0, 0, 0, 1504.1678466796875, -76.0144195556640625, 52.23441696166992187, 2.87240910530090332, 7200, 0, 0, 19704, 0, 0, 0, 0, 0, 44325), -- Kuu'rat (Area: -Unknown- - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+58, 80998, 1116, 6719, 6922, '0', 0, 0, 0, 0, 1283.873291015625, 34.70486068725585937, 75.69969940185546875, 2.453835010528564453, 7200, 0, 0, 2463, 0, 0, 0, 0, 0, 44325); -- Taarvos (Area: -Unknown- - Difficulty: 0)

-- Creature Addon
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+58;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+47, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Silverwing Kaliri
(@CGUID+56, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Silverwing Kaliri
(@CGUID+54, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Silverwing Kaliri
(@CGUID+53, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Silverwing Kaliri
(@CGUID+55, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Silverwing Kaliri
(@CGUID+46, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Silverwing Kaliri
(@CGUID+52, 0, 0, 3, 1, 0, 0, 0, 0, 0, ''), -- Silverwing Kaliri
(@CGUID+30, 0, 0, 262144, 1, 0, 0, 0, 0, 3, '123167 166137 145363'), -- Ancient Pearltusk - 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk, 145363 - Permanent Feign Death (Stun, Untrackable, Immune)
(@CGUID+35, 0, 0, 262144, 1, 0, 0, 0, 0, 3, '123167 166137 145363'); -- Ancient Pearltusk - 123167 - Mod Scale 95-100%, 166137 - Ancient Pearltusk, 145363 - Permanent Feign Death (Stun, Untrackable, Immune)

-- Creature Template
DELETE FROM `creature_template_addon` WHERE `entry` IN (82425 /*82425 (Luminous Orchid) - Flower Spell*/, 74146 /*74146 (Podling Nibbler) - Mod Scale 95-100%*/, 80818 /*80818 (Luminous Orchid) - Flower Spell*/, 74630 /*74630 (Pearltusk Grazer) - Permanent Feign Death (Stun, Untrackable, Immune)*/, 82175 /*82175 (Silverwing Kaliri)*/, 80998 /*80998 (Taarvos)*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(82425, 0, 0, 0, 1, 429, 0, 0, 0, 0, '165966'), -- 82425 (Luminous Orchid) - Flower Spell
(74146, 0, 0, 0, 1, 0, 0, 0, 0, 0, '123167'), -- 74146 (Podling Nibbler) - Mod Scale 95-100%
(80818, 0, 0, 0, 1, 429, 0, 0, 0, 0, '165960'), -- 80818 (Luminous Orchid) - Flower Spell
(74630, 0, 0, 262144, 1, 0, 0, 0, 0, 0, '145363'), -- 74630 (Pearltusk Grazer) - Permanent Feign Death (Stun, Untrackable, Immune)
(82175, 0, 0, 50331648, 1, 0, 0, 0, 0, 0, ''), -- 82175 (Silverwing Kaliri)
(80998, 0, 0, 0, 257, 0, 0, 0, 0, 0, ''); -- 80998 (Taarvos)

UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=72829; -- Podling Bopper
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=2669 WHERE `entry`=74146; -- Podling Nibbler
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40 WHERE `entry`=80998; -- Taarvos
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `unit_flags`=32768 WHERE `entry`=75484; -- Kuu'rat
UPDATE `creature_template` SET `minlevel`=40, `maxlevel`=40, `faction`=31, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=537166592, `unit_flags2`=2049, `unit_flags3`=8192 WHERE `entry`=74630; -- Pearltusk Grazer

-- Creature MovementType
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 82175;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(82175, 1, 0, 1, 0, 0, 0, NULL);

-- Creature Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (72829,82425,74146,80818,74150,73870,73686,79966,78275,75486,80998,75422,74712,74148,74630,75484,74169,73915,74176));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(72829, 0, 0, 0, 63, 44325),
(82425, 0, 0, 0, 63, 44325),
(74146, 0, 0, 0, 63, 44325),
(80818, 0, 0, 0, 63, 44325),
(74150, 0, 0, 0, 63, 44325),
(73870, 0, 0, 0, 63, 44325),
(73686, 0, 0, 0, 63, 44325),
(79966, 0, 0, 0, 63, 44325),
(78275, 0, 0, 0, 63, 44325),
(75486, 0, 0, 0, 63, 44325),
(80998, 0, 0, 0, 63, 44325),
(75422, 0, 0, 0, 81, 44325),
(74712, 0, 0, 0, 63, 44325),
(74148, 0, 0, 0, 63, 44325),
(74630, 0, 0, 0, 63, 44325),
(75484, 0, 0, 0, 63, 44325),
(74169, 0, 0, 0, 63, 44325),
(73915, 0, 0, 0, 81, 44325),
(74176, 0, 0, 0, 63, 44325);

-- Vendor Data
DELETE FROM `npc_vendor` WHERE (`entry`=80998 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80998 AND `item`=115355 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80998 AND `item`=115354 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80998 AND `item`=115353 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80998 AND `item`=115352 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80998 AND `item`=115351 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=80998 AND `item`=117452 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(80998, 7, 64670, 0, 0, 1, 0, 0, 44325), -- Vanishing Powder
(80998, 6, 115355, 0, 0, 1, 0, 0, 44325), -- Marbled Clefthoof Steak
(80998, 5, 115354, 0, 0, 1, 0, 0, 44325), -- Sliced Zangar Buttons
(80998, 4, 115353, 0, 0, 1, 0, 0, 44325), -- Tanaan Sweetmelon
(80998, 3, 115352, 0, 0, 1, 0, 0, 44325), -- Telmor-Aruuna Hard Cheese
(80998, 2, 115351, 0, 0, 1, 0, 0, 44325), -- "Rylak Claws"
(80998, 1, 117452, 0, 0, 1, 0, 0, 44325); -- Gorgrond Mineral Water

-- Add SpellScript to Feign Death Aura
DELETE FROM `spell_script_names` WHERE `spell_id` = 145363;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(145363, 'spell_gen_feign_death_all_flags');

DELETE FROM `gameobject` WHERE `guid` = @OGUID+0;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 237016, 1116, 6719, 6922, '0', 0, 0, 1288.34375, 39.26041793823242187, 76.92043304443359375, 5.683261871337890625, 0, 0, -0.29548358917236328, 0.955347836017608642, 7200, 255, 1, 44325); -- Wanted: Kuu'rat (Area: -Unknown- - Difficulty: 0)

UPDATE `gameobject_template` SET `ContentTuningId`=63, `VerifiedBuild`=44325 WHERE `entry`=237016; -- Wanted: Kuu'rat

-- SAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (82378, 82452);
DELETE FROM `smart_scripts` WHERE `source_type` IN (0, 9) AND `entryOrGuid` IN (-(@CGUID+4), -(@CGUID+39), -(@CGUID+38), -(@CGUID+42), -(@CGUID+33), 8237800);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-(@CGUID+4), 0, 0, 0, 34, 0, 100, 0, 2, 5, 0, 0, 80, 8237800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 5 - run Actionlist - to self'),
(-(@CGUID+4), 0, 1, 0, 34, 0, 100, 0, 2, 16, 0, 0, 80, 8237800, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OnMovementInform PathID 16 - run Actionlist - to self'),
-- Moonbark Actionlist
(8237800, 9, 0, 0, 34, 0, 100, 0, 1000, 1000, 1000, 1000, 11, 165950, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 1s - cast "Deep Roots" - to self'),
(8237800, 9, 1, 0, 34, 0, 100, 0, 20000, 20000, 20000, 20000, 11, 165953, 3, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 21s - cast "Cancel Deep Roots" - to self'),
-- Ancient Pearltusk
(-(@CGUID+39), 0, 0, 0, 1, 0, 100, 0, 1000, 3000, 1000, 3000, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 1s to 3s - Play Emote 35 - to self'),
(-(@CGUID+38), 0, 0, 0, 1, 0, 100, 0, 1000, 3000, 1000, 3000, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 1s to 3s - Play Emote 35 - to self'),
(-(@CGUID+42), 0, 0, 0, 1, 0, 100, 0, 1000, 3000, 1000, 3000, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 1s to 3s - Play Emote 35 - to self'),
(-(@CGUID+33), 0, 0, 0, 1, 0, 100, 0, 1000, 3000, 1000, 3000, 5, 35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'OOC Every 1s to 3s - Play Emote 35 - to self');

-- Waypoints for CGUID+15
SET @PATH := @CGUID+15 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1591.694, 133.9705, 71.99809, NULL, 0),
(@PATH, 1, 1615.198, 138.0382, 71.99126, NULL, 0),
(@PATH, 2, 1630.2, 160.684, 73.67547, NULL, 0),
(@PATH, 3, 1622.918, 178.8299, 73.11132, NULL, 0),
(@PATH, 4, 1605.651, 186.3507, 73.08373, NULL, 0),
(@PATH, 5, 1570.665, 189.0347, 72.50399, NULL, 0),
(@PATH, 6, 1539.441, 170.7274, 70.07035, NULL, 0),
(@PATH, 7, 1529.292, 152.9531, 68.878, NULL, 0),
(@PATH, 8, 1515.189, 132.1146, 67.86848, NULL, 0),
(@PATH, 9, 1491.599, 113.7691, 67.15544, NULL, 0),
(@PATH, 10, 1450.806, 111.0955, 66.71104, NULL, 0),
(@PATH, 11, 1434.55, 130.4844, 67.58933, NULL, 0),
(@PATH, 12, 1449.234, 154.7656, 66.43216, NULL, 0),
(@PATH, 13, 1480.064, 163.0868, 65.96194, NULL, 0),
(@PATH, 14, 1504.049, 159.2274, 66.34602, NULL, 0),
(@PATH, 15, 1544.401, 149.217, 70.71866, NULL, 0);

UPDATE `creature` SET `position_x`= 1591.694, `position_y`= 133.9705, `position_z`= 71.99809, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+15;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+15;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `visibilityDistanceType`) VALUES
(@CGUID+15, @PATH, 1, 3);

-- Waypoints for CGUID+4
SET @PATH := @CGUID+4 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1503.045, 39.66493, 62.96973, NULL, 0),
(@PATH, 1, 1519.88, 41.78646, 62.34852, NULL, 0),
(@PATH, 2, 1541.033, 47.02604, 62.60479, NULL, 0),
(@PATH, 3, 1555.174, 55.67708, 63.26799, NULL, 0),
(@PATH, 4, 1563.797, 50.59961, 62.27422, NULL, 0),
(@PATH, 5, 1565.354, 42.25868, 60.90764, NULL, 22859),
(@PATH, 6, 1567.976, 55.625, 63.12945, NULL, 0),
(@PATH, 7, 1570.557, 64.15625, 64.53936, NULL, 0),
(@PATH, 8, 1575.898, 72.62153, 66.21881, NULL, 0),
(@PATH, 9, 1581.368, 78.85243, 67.24799, NULL, 0),
(@PATH, 10, 1591.557, 84.37153, 67.89667, NULL, 0),
(@PATH, 11, 1604.247, 88.48959, 68.42217, NULL, 0),
(@PATH, 12, 1621.318, 83.79166, 68.85662, NULL, 0),
(@PATH, 13, 1637.554, 71.60938, 69.06905, NULL, 0),
(@PATH, 14, 1653.781, 63.77951, 70.28802, NULL, 0),
(@PATH, 15, 1668.688, 59.48958, 71.44853, NULL, 0),
(@PATH, 16, 1677.328, 61.24653, 71.9091, 2.912247, 24854),
(@PATH, 17, 1654.851, 53.81076, 70.05756, NULL, 0),
(@PATH, 18, 1636.384, 48.31597, 67.57709, NULL, 0),
(@PATH, 19, 1619.052, 37.17882, 63.81988, NULL, 0),
(@PATH, 20, 1604.714, 25.81076, 60.59085, NULL, 0),
(@PATH, 21, 1588.804, 17.86285, 56.04565, NULL, 0),
(@PATH, 22, 1563.717, 9.920139, 56.38276, NULL, 0),
(@PATH, 23, 1544.203, 19.94444, 58.22443, NULL, 0),
(@PATH, 24, 1520.34, 28.3316, 60.58909, NULL, 0),
(@PATH, 25, 1506.946, 30.22569, 61.67369, NULL, 0);

UPDATE `creature` SET `position_x`= 1503.045, `position_y`= 39.66493, `position_z`= 62.96973, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+4;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+4;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `visibilityDistanceType`) VALUES
(@CGUID+4, @PATH, 1, 3);

-- Waypoints for CGUID+22
SET @PATH := @CGUID+22 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1471.708, 359.4375, 57.14211, NULL, 0),
(@PATH, 1, 1457.41, 329.2257, 61.45536, NULL, 0),
(@PATH, 2, 1456.089, 293.0851, 61.64457, NULL, 12071),
(@PATH, 3, 1457.39, 329.0859, 61.40007, NULL, 0),
(@PATH, 4, 1471.708, 359.4375, 57.14211, NULL, 0),
(@PATH, 5, 1496.611, 393.2517, 53.3642, NULL, 8486);

UPDATE `creature` SET `position_x`= 1471.708, `position_y`= 359.4375, `position_z`= 57.14211, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+22;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+22;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`, `visibilityDistanceType`) VALUES
(@CGUID+22, @PATH, 1, 3);

-- Waypoints for CGUID+57
SET @PATH := @CGUID+57 * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 1515.934, -75.875, 52.67513, NULL, 29158),
(@PATH, 1, 1461.729, -58.2934, 56.88169, NULL, 18213);

UPDATE `creature` SET `position_x`= 1515.934, `position_y`= -75.875, `position_z`= 52.67513, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+57;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+57;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+57, @PATH, 1);
