SET @CGUID := 7002289;

SET @NPCTEXTID := 570050;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+63;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -331.282989501953125, 1819.2066650390625, 70.00598907470703125, 4.059118270874023437, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+1, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -340.244781494140625, 1779.76220703125, 73.216552734375, 2.941902399063110351, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+2, 128384, 1643, 8721, 0, '0', 0, 0, 0, 0, -383.58160400390625, 1840.5989990234375, 98.67711639404296875, 2.575807094573974609, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Lowlands Greatstag (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+3, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -386.564239501953125, 1841.138916015625, 98.621490478515625, 5.093258380889892578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+4, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -339.814239501953125, 1777.3802490234375, 73.04864501953125, 0.713508069515228271, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+5, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -335.609375, 1827.638916015625, 73.31011199951171875, 3.028375625610351562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+6, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -364.407989501953125, 1828.3646240234375, 89.455078125, 1.606047868728637695, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+7, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -339.20660400390625, 1821.0885009765625, 74.6583404541015625, 1.520454168319702148, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+8, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -406.0069580078125, 1851.4478759765625, 99.57089996337890625, 2.279313325881958007, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+9, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -339.673614501953125, 1825.3160400390625, 75.577056884765625, 1.395488977432250976, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+10, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -380.62847900390625, 1840.2396240234375, 98.59568023681640625, 5.481331825256347656, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+11, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -331.447906494140625, 1779.9097900390625, 69.45906829833984375, 0.506807267665863037, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+12, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -308.864593505859375, 1780.2882080078125, 57.98614501953125, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+13, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -383.9757080078125, 1781.65625, 92.31006622314453125, 3.956746578216552734, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+14, 126695, 1643, 8721, 0, '0', 0, 0, 0, 0, -399.555572509765625, 1776.8629150390625, 95.4489593505859375, 5.629493236541748046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+15, 128386, 1643, 8721, 0, '0', 0, 0, 0, 0, -345.7413330078125, 1827.685791015625, 79.298614501953125, 5.541920661926269531, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Lowlands Fawn (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%) (possible waypoints or random movement)
(@CGUID+16, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -351.54339599609375, 1792.3160400390625, 79.996429443359375, 0.432254374027252197, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+17, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -343.85589599609375, 1784.21533203125, 74.64357757568359375, 1.085415005683898925, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+18, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -384.993072509765625, 1823.1458740234375, 96.4677734375, 0.149884596467018127, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+19, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -332.619781494140625, 1828.3472900390625, 71.61578369140625, 1.732006549835205078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+20, 126695, 1643, 8721, 0, '0', 0, 0, 0, 0, -403.421875, 1768.68408203125, 94.71926116943359375, 5.392589092254638671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+21, 128384, 1643, 8721, 0, '0', 0, 0, 0, 0, -331.25347900390625, 1776.8646240234375, 69.19231414794921875, 3.860527276992797851, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Greatstag (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+22, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -338.359375, 1804.189208984375, 74.14898681640625, 4.369874000549316406, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+23, 128384, 1643, 8721, 0, '0', 0, 0, 0, 0, -339.885406494140625, 1831.4271240234375, 76.5052337646484375, 0.878666877746582031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Greatstag (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+24, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -382.673614501953125, 1837.326416015625, 98.0255584716796875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+25, 126695, 1643, 8721, 0, '0', 0, 0, 0, 0, -317.666656494140625, 1807.795166015625, 88.2340850830078125, 1.739253997802734375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+26, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -335.93402099609375, 1780.19970703125, 71.32276153564453125, 1.976229190826416015, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+27, 126695, 1643, 8721, 0, '0', 0, 0, 0, 0, -366.342010498046875, 1817.6910400390625, 104.2254791259765625, 2.27306675910949707, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+28, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -361.4132080078125, 1761.8958740234375, 81.67656707763671875, 3.873528957366943359, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+29, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -391.024322509765625, 1765.4757080078125, 91.63588714599609375, 4.458143234252929687, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+30, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -408.895843505859375, 1735.6510009765625, 88.07401275634765625, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+31, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -377.244781494140625, 1724.1961669921875, 80.27837371826171875, 0.376091331243515014, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+32, 128385, 1643, 8721, 9167, '0', 0, 0, 0, 0, -445.036468505859375, 1692.5711669921875, 83.4813385009765625, 4.633452892303466796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+33, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -413.020843505859375, 1716.2413330078125, 84.88116455078125, 4.874501705169677734, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+34, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -408.65277099609375, 1757.298583984375, 93.95416259765625, 0.386198848485946655, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+35, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -399.1475830078125, 1667.18408203125, 81.59552001953125, 0.444345623254776, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+36, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -416.883697509765625, 1647.546875, 83.75457000732421875, 4.230954647064208984, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+37, 128386, 1643, 8721, 9167, '0', 0, 0, 0, 0, -480.1788330078125, 1651.5521240234375, 74.2547607421875, 1.58207404613494873, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Lowlands Fawn (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+38, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -378.164947509765625, 1706.21533203125, 90.0366363525390625, 1.124704599380493164, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+39, 128384, 1643, 8721, 9167, '0', 0, 0, 0, 0, -482.359375, 1646.8385009765625, 72.77536773681640625, 1.005631804466247558, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Lowlands Greatstag (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+40, 128386, 1643, 8721, 9167, '0', 0, 0, 0, 0, -451.626739501953125, 1693.1597900390625, 84.01470184326171875, 3.53850865364074707, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Lowlands Fawn (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+41, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -441.76214599609375, 1690.517333984375, 82.924560546875, 5.0346221923828125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+42, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -478.390625, 1657.82470703125, 76.3421630859375, 5.459464073181152343, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+43, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -424.154510498046875, 1638.78125, 83.97412109375, 2.679052114486694335, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+44, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -495.392364501953125, 1649.80908203125, 72.8594970703125, 1.822977781295776367, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+45, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -521.015625, 1643.59033203125, 68.53057861328125, 3.102061271667480468, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+46, 128386, 1643, 8721, 9167, '0', 0, 0, 0, 0, -481.907989501953125, 1659.326416015625, 76.71562957763671875, 2.724853038787841796, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Lowlands Fawn (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+47, 128385, 1643, 8721, 9167, '0', 0, 0, 0, 0, -489.947906494140625, 1652.1441650390625, 74.12432098388671875, 6.038727283477783203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+48, 128384, 1643, 8721, 9167, '0', 0, 0, 0, 0, -448.557281494140625, 1692.7083740234375, 83.6521453857421875, 4.576345443725585937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Greatstag (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+49, 1412, 1643, 8721, 0, '0', 0, 0, 0, 0, -488.6632080078125, 1643.796875, 71.6505126953125, 0.857619404792785644, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Squirrel (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+50, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -535.1632080078125, 1739.9635009765625, 93.47225189208984375, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+51, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -585.84893798828125, 1645.0677490234375, 61.46945953369140625, 0.717470526695251464, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+52, 128384, 1643, 8721, 0, '0', 0, 0, 0, 0, -493.73089599609375, 1633.748291015625, 69.30035400390625, 4.576345443725585937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Greatstag (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+53, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -498.4600830078125, 1633.3802490234375, 68.876739501953125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+54, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -552.26739501953125, 1670.3489990234375, 66.8380279541015625, 1.980223417282104492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+55, 126210, 1643, 8721, 9167, '0', 0, 0, 0, 1, -379.15972900390625, 1711.4166259765625, 81.61458587646484375, 1.950915336608886718, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Caretaker Allen (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject1
(@CGUID+56, 126739, 1643, 8721, 9167, '0', 0, 0, 0, 0, -375.22711181640625, 1709.976318359375, 81.24092864990234375, 1.432383894920349121, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Daisy (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject1
(@CGUID+57, 126738, 1643, 8721, 9167, '0', 0, 0, 0, 0, -389.24652099609375, 1702.7257080078125, 83.29413604736328125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Wendy (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject1 (Auras: 145953 - Cosmetic - Sleep Zzz)
(@CGUID+58, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -411.75, 1875.07470703125, 95.24776458740234375, 1.837626457214355468, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+59, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -473.12152099609375, 1891.984375, 102.5869522094726562, 5.573219776153564453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+60, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -424.185760498046875, 1879.1353759765625, 94.92566680908203125, 1.940552949905395507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+61, 128385, 1643, 8721, 0, '0', 0, 0, 0, 0, -474.907989501953125, 1897.001708984375, 103.643829345703125, 4.633452892303466796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Doe (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+62, 128384, 1643, 8721, 0, '0', 0, 0, 0, 0, -422.083343505859375, 1880.779541015625, 94.2216949462890625, 1.220836758613586425, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Lowlands Greatstag (Area: 0 - Difficulty: 0) CreateObject2 (Auras: 123169 - Mod Scale 105-110%)
(@CGUID+63, 126805, 1643, 8721, 0, '0', 0, 0, 0, 0, -461.510406494140625, 1879.1788330078125, 102.68023681640625, 1.337487339973449707, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490); -- Skittish Squirrel (Area: 0 - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+63;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Lowlands Fawn - 123169 - Mod Scale 105-110%
(@CGUID+9, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+14, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+17, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+20, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Greatstag - 123169 - Mod Scale 105-110%
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Greatstag - 123169 - Mod Scale 105-110%
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169 145953'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+25, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+27, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169 145953'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+34, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+38, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+48, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Lowlands Greatstag - 123169 - Mod Scale 105-110%
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+52, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169'), -- Lowlands Greatstag - 123169 - Mod Scale 105-110%
(@CGUID+53, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169 145953'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, '123169'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+59, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169 145953'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+60, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169 145953'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+61, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169 145953'), -- Lowlands Doe - 123169 - Mod Scale 105-110%
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123169 145953'); -- Lowlands Greatstag - 123169 - Mod Scale 105-110%

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (126738,126739,126210);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(126738, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '145953'), -- 126738 (Wendy) - Cosmetic - Sleep Zzz
(126739, 0, 0, 0, 0, 0, 1, 0, 0, 13889, 0, 0, 0, ''), -- 126739 (Daisy)
(126210, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''); -- 126210 (Caretaker Allen)

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (126353,126263,139156,129756,126738,126739,130138,126210,121610,126264) AND `DifficultyID`=1;
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=60490 WHERE (`Entry`=126353 AND `DifficultyID`=0); -- 126353 (Woodland Bat) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=126263 AND `DifficultyID`=0); -- 126263 (Soulgorged Gravestalker) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60490 WHERE (`Entry`=139156 AND `DifficultyID`=0); -- 139156 (Read Plaque Kill Credit) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60490 WHERE (`Entry`=129756 AND `DifficultyID`=0); -- 129756 (Mysterious Voice) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=126738 AND `DifficultyID`=0); -- 126738 (Wendy) - CanSwim - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=126739 AND `DifficultyID`=0); -- 126739 (Daisy) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=130138 AND `DifficultyID`=0); -- 130138 (Nevermore) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=126210 AND `DifficultyID`=0); -- 126210 (Caretaker Allen) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=60490 WHERE (`Entry`=121610 AND `DifficultyID`=0); -- 121610 (Watchful Raven) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=126264 AND `DifficultyID`=0); -- 126264 (Enraged Spirit) - CanSwim

-- Model
UPDATE `creature_model_info` SET `VerifiedBuild`=60490 WHERE `DisplayID` IN (60055, 81154, 81145, 64978, 134, 79956, 62977, 11686, 78819, 42239, 51297, 51294, 21342, 81086, 80965, 78794, 70442, 80962, 43163, 70722, 70448, 32546, 78821, 78820, 79614, 64016, 70440, 70446);
UPDATE `creature_model_info` SET `BoundingRadius`=0.289735019207000732, `VerifiedBuild`=60490 WHERE `DisplayID`=60964;
UPDATE `creature_model_info` SET `BoundingRadius`=0.217223197221755981, `CombatReach`=1, `VerifiedBuild`=60490 WHERE `DisplayID`=68845;

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=126738 AND `MenuID`=21813) OR (`CreatureID`=126210 AND `MenuID`=21434);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(126738, 21813, 60490), -- Wendy
(126210, 21434, 60490); -- Caretaker Allen

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 140957, 0, 0, 0, 0, 0, 0, 0, 60490); -- 126738 (Wendy)

DELETE FROM `gossip_menu` WHERE (`MenuID`=21813 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(21813, @NPCTEXTID+0, 60490); -- 126738 (Wendy)

UPDATE `gossip_menu` SET `VerifiedBuild`=60490 WHERE (`MenuID`=21434 AND `TextID`=32638);

-- Quest
DELETE FROM `quest_details` WHERE `ID`=48475;
INSERT INTO `quest_details` (`ID`, `Emote1`, `Emote2`, `Emote3`, `Emote4`, `EmoteDelay1`, `EmoteDelay2`, `EmoteDelay3`, `EmoteDelay4`, `VerifiedBuild`) VALUES
(48475, 1, 0, 0, 0, 0, 0, 0, 0, 60490); -- Seeing Spirits

DELETE FROM `creature_queststarter` WHERE (`id`=126210 AND `quest`=48475);
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(126210, 48475, 60490); -- Seeing Spirits offered by Caretaker Allen

-- Path for Baleful Raven
SET @MOVERGUID := @CGUID+25;
SET @ENTRY := 126695;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8687, 'Baleful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -320.87473, 1826.6584, 88.234085, NULL, 0),
(@PATH, 1, -309.80478, 1842.2653, 88.234085, NULL, 0),
(@PATH, 2, -290.94147, 1845.4734, 88.234085, NULL, 0),
(@PATH, 3, -275.33463, 1834.4034, 88.234085, NULL, 0),
(@PATH, 4, -272.1266, 1815.5402, 88.234085, NULL, 0),
(@PATH, 5, -283.1965, 1799.9333, 88.234085, NULL, 0),
(@PATH, 6, -302.05984, 1796.7252, 88.234085, NULL, 0),
(@PATH, 7, -317.66666, 1807.7952, 88.234085, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Baleful Raven
SET @MOVERGUID := @CGUID+27;
SET @ENTRY := 126695;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8687, 'Baleful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -378.70175, 1832.2976, 104.22548, NULL, 0),
(@PATH, 1, -377.113, 1851.3657, 104.22548, NULL, 0),
(@PATH, 2, -362.5064, 1863.7255, 104.22548, NULL, 0),
(@PATH, 3, -343.4383, 1862.1367, 104.22548, NULL, 0),
(@PATH, 4, -331.07855, 1847.5302, 104.22548, NULL, 0),
(@PATH, 5, -332.6673, 1828.462, 104.22548, NULL, 0),
(@PATH, 6, -347.27393, 1816.1023, 104.22548, NULL, 0),
(@PATH, 7, -366.342, 1817.691, 104.22548, NULL, 0),
(@PATH, 8, -378.70175, 1832.2976, 104.22548, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Daisy
SET @MOVERGUID := @CGUID+56;
SET @ENTRY := 126739;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Daisy - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -371.71008, 1711.8125, 80.59722, NULL, 0),
(@PATH, 1, -372.65103, 1709.9705, 80.71875, NULL, 0),
(@PATH, 2, -374.52432, 1706.7795, 81.07465, NULL, 0),
(@PATH, 3, -378.625, 1707.5278, 81.40452, NULL, 0),
(@PATH, 4, -377.62152, 1713.9723, 80.996216, NULL, 0),
(@PATH, 5, -375.8455, 1716.1997, 80.45068, NULL, 0),
(@PATH, 6, -371.43057, 1715.6927, 79.86261, NULL, 0),
(@PATH, 7, -368.54166, 1712.9548, 78.517365, NULL, 0),
(@PATH, 8, -365.4184, 1711.9166, 75.96702, NULL, 0),
(@PATH, 9, -363.24307, 1713.3264, 73.41493, NULL, 0),
(@PATH, 10, -360.09375, 1717.4132, 71.611115, NULL, 0),
(@PATH, 11, -363.18576, 1719.4844, 73.96702, NULL, 0),
(@PATH, 12, -365.41495, 1717.0938, 74.83681, NULL, 0),
(@PATH, 13, -366.1389, 1713.9827, 76.13368, NULL, 0),
(@PATH, 14, -367.00348, 1710.2935, 77.448715, NULL, 0),
(@PATH, 15, -371.1059, 1705.9236, 79.58854, NULL, 0),
(@PATH, 16, -373.717, 1705.2812, 80.85162, NULL, 0),
(@PATH, 17, -375.22745, 1709.974, 81.24132, NULL, 0),
(@PATH, 18, -374.31424, 1716.5295, 80.15633, NULL, 0),
(@PATH, 19, -374.19446, 1721.3923, 79.291214, NULL, 0),
(@PATH, 20, -375.43402, 1725.5555, 79.734184, NULL, 0),
(@PATH, 21, -381.5712, 1726.1406, 80.390884, NULL, 0),
(@PATH, 22, -385.98264, 1724.2327, 80.98118, NULL, 0),
(@PATH, 23, -394.32812, 1717.8594, 81.256935, NULL, 0),
(@PATH, 24, -398.67188, 1712.5642, 81.74055, NULL, 0),
(@PATH, 25, -397.62674, 1709.349, 82.020485, NULL, 0),
(@PATH, 26, -392.81076, 1709.2587, 82.35001, NULL, 0),
(@PATH, 27, -388.37848, 1712.1685, 81.73555, NULL, 0),
(@PATH, 28, -384.4271, 1716.5885, 81.31156, NULL, 0),
(@PATH, 29, -383.68228, 1719.6459, 81.21698, NULL, 0),
(@PATH, 30, -385.85764, 1721.9861, 81.17432, NULL, 0),
(@PATH, 31, -387.375, 1723.743, 81.100624, NULL, 0),
(@PATH, 32, -384.71182, 1727.4584, 80.48967, NULL, 0),
(@PATH, 33, -380.83853, 1729.3923, 80.06493, NULL, 0),
(@PATH, 34, -376.37674, 1729.8108, 79.75145, NULL, 0),
(@PATH, 35, -374.30902, 1727.757, 79.512024, NULL, 0),
(@PATH, 36, -376.67014, 1722.5104, 80.08651, NULL, 0),
(@PATH, 37, -377.5, 1718.6562, 80.32605, NULL, 0),
(@PATH, 38, -374.74133, 1715.1007, 80.62644, NULL, 0),
(@PATH, 39, -372.11807, 1714.8906, 80.31021, NULL, 0),
(@PATH, 40, -371.8941, 1712.8368, 80.61992, NULL, 0),
(@PATH, 41, -371.76736, 1711.8889, 80.611115, NULL, 7234);

UPDATE `creature` SET `position_x`=-371.71008, `position_y`=1711.8125, `position_z`=80.59722, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
