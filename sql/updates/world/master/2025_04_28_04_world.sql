SET @CGUID := 7002353;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+92;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -424.961822509765625, 1748.44970703125, 92.5981292724609375, 6.102526664733886718, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual) (possible waypoints or random movement)
(@CGUID+1, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -420.385406494140625, 1755.6007080078125, 92.14043426513671875, 0.152837216854095458, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+2, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -437.270843505859375, 1729.5035400390625, 92.00506591796875, 0.466372579336166381, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+3, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -463.3507080078125, 1745.5833740234375, 96.350555419921875, 0.556369781494140625, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+4, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -436.013885498046875, 1781.02783203125, 94.00632476806640625, 3.798026561737060546, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+5, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -413.970489501953125, 1794.498291015625, 95.25592041015625, 5.817714214324951171, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual) (possible waypoints or random movement)
(@CGUID+6, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -400.142364501953125, 1811.420166015625, 97.04012298583984375, 1.928223371505737304, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual) (possible waypoints or random movement)
(@CGUID+7, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -475.84722900390625, 1756.1632080078125, 96.76013946533203125, 3.655564308166503906, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+8, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -407.392364501953125, 1795.6129150390625, 95.34847259521484375, 2.816500425338745117, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual) (possible waypoints or random movement)
(@CGUID+9, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -447.0382080078125, 1830.467041015625, 101.6640090942382812, 4.357326507568359375, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+10, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -495.02777099609375, 1776.9583740234375, 96.76025390625, 1.704124093055725097, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+11, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -454.118072509765625, 1761.9010009765625, 94.64751434326171875, 1.26748514175415039, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+12, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -442.32464599609375, 1829.5850830078125, 101.4440155029296875, 2.591252565383911132, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+13, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -504.53125, 1782.1336669921875, 96.15648651123046875, 0.315600991249084472, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+14, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -412.723968505859375, 1791.1302490234375, 94.8449554443359375, 5.244734764099121093, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+15, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -425.138885498046875, 1836.7899169921875, 101.8654556274414062, 3.760784626007080078, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+16, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -447.326385498046875, 1755.920166015625, 94.82379150390625, 0.217512458562850952, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual) (possible waypoints or random movement)
(@CGUID+17, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -472.30902099609375, 1790.8004150390625, 99.27557373046875, 2.69078683853149414, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+18, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -468.68402099609375, 1755.0867919921875, 96.67352294921875, 5.165207862854003906, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual) (possible waypoints or random movement)
(@CGUID+19, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -468.99652099609375, 1816.451416015625, 101.00665283203125, 4.957080841064453125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+20, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -426.557281494140625, 1812.845458984375, 97.585662841796875, 1.447107553482055664, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+21, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -458.3038330078125, 1745.09033203125, 95.87766265869140625, 0.715039193630218505, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+22, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -420.0625, 1826.8055419921875, 100.4961395263671875, 4.384131431579589843, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+23, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -475.791656494140625, 1754.8507080078125, 96.69510650634765625, 1.421695232391357421, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual) (possible waypoints or random movement)
(@CGUID+24, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -456.138885498046875, 1793.8038330078125, 97.2566986083984375, 1.334032535552978515, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+25, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -402.75347900390625, 1805.9583740234375, 96.47498321533203125, 3.983613491058349609, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+26, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -403.623260498046875, 1812.3177490234375, 97.2945098876953125, 2.392928600311279296, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+27, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -460.326385498046875, 1775.4305419921875, 96.36371612548828125, 0.344874024391174316, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+28, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -459.477447509765625, 1779.953125, 96.53836822509765625, 4.966044425964355468, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual) (possible waypoints or random movement)
(@CGUID+29, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -449.755218505859375, 1824.529541015625, 100.7829971313476562, 6.146008491516113281, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+30, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -421.642364501953125, 1771.390625, 99.19312286376953125, 4.241673469543457031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+31, 130138, 1643, 8721, 9167, '0', 0, 0, 0, 0, -475.09375, 1864.98095703125, 107.37579345703125, 3.889963150024414062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Nevermore (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+32, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -413.2257080078125, 1790.5885009765625, 101.1359786987304687, 5.638782978057861328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+33, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -433.2882080078125, 1815.71875, 101.1051483154296875, 4.377702713012695312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+34, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -446.493072509765625, 1850.173583984375, 103.4479446411132812, 2.003583908081054687, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+35, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -474.890625, 1865.0504150390625, 107.4640731811523437, 3.401221513748168945, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 105944 - Perch)
(@CGUID+36, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -492.342010498046875, 1872.55908203125, 101.187042236328125, 5.477861881256103515, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+37, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -465.383697509765625, 1843.5711669921875, 101.6364364624023437, 5.782931327819824218, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+38, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -480.111114501953125, 1862.4288330078125, 101.1535491943359375, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+39, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -464.588531494140625, 1851.0728759765625, 102.7361068725585937, 0.970551371574401855, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+40, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -500.243072509765625, 1861.076416015625, 100.4368438720703125, 6.007052421569824218, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+41, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -454.505218505859375, 1789.9254150390625, 103.0033187866210937, 0.418187648057937622, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+42, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -485.09027099609375, 1865.5816650390625, 100.91558837890625, 4.600997447967529296, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+43, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -463.060760498046875, 1871.626708984375, 105.5849990844726562, 4.46068572998046875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+44, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -484.828125, 1805.9617919921875, 101.5054931640625, 2.85821533203125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+45, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -508.526031494140625, 1793.53125, 95.499114990234375, 2.601032733917236328, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+46, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -493.09027099609375, 1825.05908203125, 95.4622344970703125, 1.238264203071594238, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+47, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -527.8194580078125, 1853.3004150390625, 98.33451080322265625, 5.314780235290527343, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+48, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -488.47222900390625, 1807.40283203125, 95.6839599609375, 2.748979806900024414, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+49, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -507.885406494140625, 1838.626708984375, 95.620758056640625, 5.00980377197265625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
(@CGUID+50, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -544.3038330078125, 1823.7274169921875, 94.7962493896484375, 4.561226844787597656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
(@CGUID+51, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -493.45660400390625, 1828.390625, 95.79207611083984375, 3.674591064453125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
(@CGUID+52, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -480.84375, 1837.767333984375, 100.999267578125, 1.543462753295898437, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+53, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -545.046875, 1828.48095703125, 95.12216949462890625, 5.494287490844726562, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+54, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -512.79339599609375, 1827.734375, 111.2680282592773437, 5.638783931732177734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+55, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -554.1788330078125, 1879.3160400390625, 105.3750762939453125, 4.876602649688720703, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+56, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -498.1632080078125, 1866.73095703125, 100.4882888793945312, 2.422044992446899414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
(@CGUID+57, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -499.614593505859375, 1864.6146240234375, 100.5574951171875, 2.432436466217041015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
(@CGUID+58, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -562.107666015625, 1866.0052490234375, 107.6851654052734375, 0.098503835499286651, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+59, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -535.2413330078125, 1788.1285400390625, 95.749725341796875, 0.526741743087768554, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+60, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -468.354156494140625, 1877.2396240234375, 114.1690292358398437, 5.638783931732177734, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+61, 126262, 1643, 8721, 9167, '0', 0, 0, 0, 0, -589.890625, 1843.9774169921875, 106.64581298828125, 5.341200828552246093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Wicker-Bound Hunter (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 250429 - Drunk Anims)
(@CGUID+62, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -589.625, 1753.78125, 92.23384857177734375, 2.876176357269287109, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+63, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -599.732666015625, 1797.7430419921875, 99.01905059814453125, 5.89038848876953125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+64, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -563.26739501953125, 1764.84033203125, 91.925140380859375, 3.248028516769409179, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+65, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -547.5, 1753.232666015625, 93.4578857421875, 1.620805144309997558, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+66, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -623.2430419921875, 1733.407958984375, 89.12578582763671875, 3.955065250396728515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
(@CGUID+67, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -562.5, 1794.779541015625, 95.72721099853515625, 4.122288227081298828, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+68, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -571.94964599609375, 1769.6649169921875, 91.9902801513671875, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
(@CGUID+69, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -638.13714599609375, 1785.5660400390625, 89.84827423095703125, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
(@CGUID+70, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -609.2586669921875, 1772.923583984375, 93.78314971923828125, 4.608075141906738281, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+71, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -602.107666015625, 1808.9461669921875, 102.6182022094726562, 2.046470165252685546, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+72, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -536.78472900390625, 1772.9010009765625, 94.54510498046875, 2.257477045059204101, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
(@CGUID+73, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -545.484375, 1766.4444580078125, 93.25164794921875, 2.020539283752441406, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+74, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -587.47918701171875, 1762.6875, 92.38199615478515625, 5.470413684844970703, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+75, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -545.888916015625, 1755.0035400390625, 93.50949859619140625, 2.470139503479003906, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+76, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -598.40972900390625, 1800.1041259765625, 99.934783935546875, 5.047957897186279296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+77, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -614.61981201171875, 1769.4375, 104.2079544067382812, 5.63878488540649414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+78, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -545.04864501953125, 1752.6666259765625, 100.4619827270507812, 2.874317884445190429, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+79, 126695, 1643, 8721, 9167, '0', 0, 0, 0, 0, -570.453125, 1847.529541015625, 109.17706298828125, 5.695280075073242187, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Baleful Raven (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+80, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -625.6492919921875, 1782.3055419921875, 89.8484344482421875, 3.744440078735351562, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+81, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -575.55902099609375, 1808.4322509765625, 101.0833587646484375, 2.885944604873657226, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+82, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -612.015625, 1754.923583984375, 90.2921905517578125, 0.800732612609863281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
(@CGUID+83, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -595.56427001953125, 1850.1146240234375, 106.3765182495117187, 2.384652137756347656, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+84, 139136, 1643, 8721, 9167, '0', 0, 0, 0, 1, -614.38543701171875, 1908.845458984375, 109.7161865234375, 2.863366365432739257, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Brutus Thornton (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+85, 126245, 1643, 8721, 9167, '0', 0, 0, 0, 1, -674.86981201171875, 1927.578125, 113.983917236328125, 1.383040308952331542, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Sister Westwood (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257853 - Witch Channel)
(@CGUID+86, 126264, 1643, 8721, 9167, '0', 0, 0, 0, 0, -667.109375, 1843.1510009765625, 107.7098541259765625, 2.741529226303100585, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Enraged Spirit (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 251383 - Shadowy Ghost Visual)
(@CGUID+87, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -654.36285400390625, 1867.1597900390625, 110.81414794921875, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
(@CGUID+88, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -646.359375, 1823.654541015625, 103.9217529296875, 3.085023880004882812, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+89, 126710, 1643, 8721, 9167, '0', 0, 0, 0, 0, -690.328125, 1872.6875, 111.1768951416015625, 3.771871089935302734, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Foraging Rat (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+90, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -647.77606201171875, 1825.07470703125, 104.16375732421875, 2.256420612335205078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 60490), -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
(@CGUID+91, 126805, 1643, 8721, 9167, '0', 0, 0, 0, 0, -645.953125, 1838.1978759765625, 105.0419921875, 0.514383196830749511, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 60490), -- Skittish Squirrel (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2
(@CGUID+92, 126263, 1643, 8721, 9167, '0', 0, 0, 0, 0, -584.87152099609375, 1906.126708984375, 110.1590194702148437, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 60490); -- Soulgorged Gravestalker (Area: Barrowknoll Cemetery - Difficulty: 0) CreateObject2 (Auras: 257251 - Bramblepelt)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+92;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+30, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 455, 0, 0, 0, 0, ''), -- Nevermore
(@CGUID+32, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+33, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+41, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+43, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+44, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+54, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+60, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+76, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Baleful Raven
(@CGUID+78, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Baleful Raven

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (126262,130138,126263,126264,126245);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(126262, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '250429'), -- 126262 (Wicker-Bound Hunter) - Drunk Anims
(130138, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 130138 (Nevermore)
(126263, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '257251'), -- 126263 (Soulgorged Gravestalker) - Bramblepelt
(126264, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '251383'), -- 126264 (Enraged Spirit) - Shadowy Ghost Visual
(126245, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 126245 (Sister Westwood) - Witch Channel

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE `Entry` IN (137131,138245,127877,137134,139688,121684,124429,139367,127876,139368,127808,127780,126262,126245,127874,128161,130269,139136) AND `DifficultyID`=1;
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=137131 AND `DifficultyID`=0); -- 137131 (Coven Hexcaller) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=138245 AND `DifficultyID`=0); -- 138245 (Hexthralled Crossbowman) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `StaticFlags3`=0x40000, `VerifiedBuild`=60490 WHERE (`Entry`=127877 AND `DifficultyID`=0); -- 127877 (Longfang) - CanSwim - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=137134 AND `DifficultyID`=0); -- 137134 (Hexthralled Soldier) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60490 WHERE (`Entry`=139688 AND `DifficultyID`=0); -- 139688 (Meet Nathanos Kill Credit) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000100, `VerifiedBuild`=60490 WHERE (`Entry`=121684 AND `DifficultyID`=0); -- 121684 (Smoochums) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=124429 AND `DifficultyID`=0); -- 124429 (Scavenging Rat) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60490 WHERE (`Entry`=139367 AND `DifficultyID`=0); -- 139367 (Nathanos RP Kill Credit) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000100, `VerifiedBuild`=60490 WHERE (`Entry`=127876 AND `DifficultyID`=0); -- 127876 (Chillmist Alpha) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60490 WHERE (`Entry`=139368 AND `DifficultyID`=0); -- 139368 (Valentine RP Kill Credit) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=127808 AND `DifficultyID`=0); -- 127808 (Mountain Fawn) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=60490 WHERE (`Entry`=127780 AND `DifficultyID`=0); -- 127780 (Alpine Falcon) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=126262 AND `DifficultyID`=0); -- 126262 (Wicker-Bound Hunter) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=126245 AND `DifficultyID`=0); -- 126245 (Sister Westwood) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=127874 AND `DifficultyID`=0); -- 127874 (Chillmist Prowler) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=128161 AND `DifficultyID`=0); -- 128161 (Inert Soulbound Monstrosity) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=130269 AND `DifficultyID`=0); -- 130269 (Brook Turtle) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60490 WHERE (`Entry`=139136 AND `DifficultyID`=0); -- 139136 (Brutus Thornton) - CanSwim

-- Baleful Raven smart ai
SET @ENTRY := 126695;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 25, 0, 100, 0, 0, 0, 0, 0, 0, 85, 105944, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell 105944 on self', '');

UPDATE `creature` SET `StringID` = 'ChannelPerched' WHERE `guid` = @CGUID+35;

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 126695 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 126695, 0, 0, 58, 1, 0, 0, 0, 'ChannelPerched', 0, 'Object has StringID ChannelPerched');

-- Path for Baleful Raven
SET @MOVERGUID := @CGUID+32;
SET @ENTRY := 126695;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8626, 'Baleful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -400.98813, 1781.3931, 111.13598, NULL, 0),
(@PATH, 1, -398.837, 1766.2377, 111.13598, NULL, 0),
(@PATH, 2, -408.0324, 1754, 111.13598, NULL, 0),
(@PATH, 3, -423.18784, 1751.8489, 111.13598, NULL, 0),
(@PATH, 4, -435.42545, 1761.0443, 111.13598, NULL, 0),
(@PATH, 5, -437.5766, 1776.1998, 111.13598, NULL, 0),
(@PATH, 6, -428.38116, 1788.4374, 111.13598, NULL, 0),
(@PATH, 7, -413.2257, 1790.5885, 111.13598, NULL, 0),
(@PATH, 8, -400.98813, 1781.3931, 111.13598, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Baleful Raven
SET @MOVERGUID := @CGUID+54;
SET @ENTRY := 126695;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8646, 'Baleful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -497.49643, 1816.2401, 121.26803, NULL, 0),
(@PATH, 1, -494.8075, 1797.2958, 121.26803, NULL, 0),
(@PATH, 2, -506.3018, 1781.9988, 121.26803, NULL, 0),
(@PATH, 3, -525.2461, 1779.3099, 121.26803, NULL, 0),
(@PATH, 4, -540.5431, 1790.8042, 121.26803, NULL, 0),
(@PATH, 5, -543.232, 1809.7484, 121.26803, NULL, 0),
(@PATH, 6, -531.73773, 1825.0454, 121.26803, NULL, 0),
(@PATH, 7, -512.7934, 1827.7344, 121.26803, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Baleful Raven
SET @MOVERGUID := @CGUID+60;
SET @ENTRY := 126695;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8646, 'Baleful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -453.0572, 1865.7454, 124.16903, NULL, 0),
(@PATH, 1, -450.36826, 1846.801, 124.16903, NULL, 0),
(@PATH, 2, -461.86255, 1831.504, 124.16903, NULL, 0),
(@PATH, 3, -480.80682, 1828.8152, 124.16903, NULL, 0),
(@PATH, 4, -496.10382, 1840.3094, 124.16903, NULL, 0),
(@PATH, 5, -498.79276, 1859.2537, 124.16903, NULL, 0),
(@PATH, 6, -487.29846, 1874.5507, 124.16903, NULL, 0),
(@PATH, 7, -468.35416, 1877.2396, 124.16903, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Baleful Raven
SET @MOVERGUID := @CGUID+77;
SET @ENTRY := 126695;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8646, 'Baleful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -599.3228, 1757.9432, 114.207954, NULL, 0),
(@PATH, 1, -596.6339, 1738.9989, 114.207954, NULL, 0),
(@PATH, 2, -608.1282, 1723.7019, 114.207954, NULL, 0),
(@PATH, 3, -627.0725, 1721.0131, 114.207954, NULL, 0),
(@PATH, 4, -642.3695, 1732.5073, 114.207954, NULL, 0),
(@PATH, 5, -645.0584, 1751.4515, 114.207954, NULL, 0),
(@PATH, 6, -633.56415, 1766.7485, 114.207954, NULL, 0),
(@PATH, 7, -614.6198, 1769.4375, 114.207954, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Baleful Raven
SET @MOVERGUID := @CGUID+79;
SET @ENTRY := 126695;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8646, 'Baleful Raven - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -554.5315, 1836.9174, 119.17706, NULL, 0),
(@PATH, 1, -550.77716, 1818.1552, 119.17706, NULL, 0),
(@PATH, 2, -561.38934, 1802.2335, 119.17706, NULL, 0),
(@PATH, 3, -580.15155, 1798.4791, 119.17706, NULL, 0),
(@PATH, 4, -596.0732, 1809.0913, 119.17706, NULL, 0),
(@PATH, 5, -599.8276, 1827.8535, 119.17706, NULL, 0),
(@PATH, 6, -589.2154, 1843.7751, 119.17706, NULL, 0),
(@PATH, 7, -570.4531, 1847.5295, 119.17706, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Soulgorged Gravestalker
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+57;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+57, @CGUID+57, 0, 0, 515, 0, 0),
(@CGUID+57, @CGUID+56, 3, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+57;
SET @ENTRY := 126263;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Soulgorged Gravestalker - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -504.1146, 1867.6997, 100.58554, NULL, 0),
(@PATH, 1, -501.4184, 1869.5834, 100.4252, NULL, 0),
(@PATH, 2, -503.9757, 1872.0416, 100.46937, NULL, 0),
(@PATH, 3, -508.5, 1875.0348, 100.7457, NULL, 0),
(@PATH, 4, -513.2674, 1876.5226, 101.34225, NULL, 0),
(@PATH, 5, -516.63715, 1876.382, 102.03911, NULL, 0),
(@PATH, 6, -521.059, 1876.0591, 102.74149, NULL, 0),
(@PATH, 7, -526.13544, 1876.618, 103.46618, NULL, 0),
(@PATH, 8, -528.8924, 1876.1632, 103.74081, NULL, 0),
(@PATH, 9, -537.17017, 1875.6041, 104.31077, NULL, 0),
(@PATH, 10, -548.5799, 1875.0399, 105.09595, NULL, 0),
(@PATH, 11, -557.6597, 1873.7673, 106.38108, NULL, 0),
(@PATH, 12, -561.32465, 1872.3455, 107.18373, NULL, 0),
(@PATH, 13, -562.4132, 1870.7952, 107.43373, NULL, 0),
(@PATH, 14, -560.65106, 1869.3038, 107.27438, NULL, 0),
(@PATH, 15, -556.8715, 1869.9514, 106.74236, NULL, 0),
(@PATH, 16, -553.6302, 1870.3698, 106.29243, NULL, 0),
(@PATH, 17, -550.8733, 1871.1146, 105.77406, NULL, 0),
(@PATH, 18, -547.38367, 1871.2952, 105.33613, NULL, 0),
(@PATH, 19, -540.3976, 1871.9462, 104.62759, NULL, 0),
(@PATH, 20, -533.2483, 1872.4723, 103.96465, NULL, 0),
(@PATH, 21, -523.2031, 1873.2743, 102.96288, NULL, 0),
(@PATH, 22, -514.1667, 1873.0192, 101.63744, NULL, 0),
(@PATH, 23, -507.9375, 1870.7812, 100.84825, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '257251');

-- Path for Soulgorged Gravestalker
SET @MOVERGUID := @CGUID+49;
SET @ENTRY := 126263;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Soulgorged Gravestalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -506.77432, 1835.0017, 95.38501, NULL, 0),
(@PATH, 1, -503.13022, 1833.6163, 95.30821, NULL, 0),
(@PATH, 2, -499.2691, 1838.0435, 95.32926, NULL, 0),
(@PATH, 3, -496.2205, 1839.9305, 98.68577, NULL, 0),
(@PATH, 4, -492.97223, 1843.5955, 99.765724, NULL, 0),
(@PATH, 5, -487.4566, 1848.7673, 100.27493, NULL, 0),
(@PATH, 6, -483.97916, 1849.1841, 100.27167, NULL, 0),
(@PATH, 7, -478.31946, 1844.1389, 100.27167, NULL, 0),
(@PATH, 8, -472.10416, 1838.3785, 100.27167, NULL, 0),
(@PATH, 9, -472.66495, 1840.6788, 100.27167, NULL, 0),
(@PATH, 10, -477.16666, 1845.1337, 100.27167, NULL, 0),
(@PATH, 11, -482.81076, 1850.7587, 100.18891, NULL, 0),
(@PATH, 12, -486.82465, 1853.9462, 100.33358, NULL, 0),
(@PATH, 13, -491.7986, 1859.6041, 100.33358, NULL, 0),
(@PATH, 14, -493.03473, 1859.5591, 100.33358, NULL, 0),
(@PATH, 15, -489.64062, 1855.0365, 100.33358, NULL, 0),
(@PATH, 16, -488.2691, 1851.7413, 100.30458, NULL, 0),
(@PATH, 17, -490.43228, 1846.9705, 100.11347, NULL, 0),
(@PATH, 18, -493.77084, 1843.6979, 99.76815, NULL, 0),
(@PATH, 19, -497.46008, 1840.0139, 97.89931, NULL, 0),
(@PATH, 20, -498.9132, 1837.8993, 95.36014, NULL, 0),
(@PATH, 21, -502.5191, 1833.3091, 95.31396, NULL, 0),
(@PATH, 22, -507.1962, 1834.618, 95.37985, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '257251');

-- Path for Soulgorged Gravestalker
SET @MOVERGUID := @CGUID+51;
SET @ENTRY := 126263;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Soulgorged Gravestalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -498.0469, 1822.717, 95.30903, NULL, 0),
(@PATH, 1, -497.96182, 1824.25, 95.32118, NULL, 0),
(@PATH, 2, -497.87674, 1825.783, 95.333336, NULL, 0),
(@PATH, 3, -496.94272, 1822.5104, 95.35243, NULL, 0),
(@PATH, 4, -495.2986, 1816.2604, 95.4184, NULL, 0),
(@PATH, 5, -495.65103, 1810.2188, 95.39757, NULL, 0),
(@PATH, 6, -498.2257, 1804.3195, 95.368935, NULL, 0),
(@PATH, 7, -502.10416, 1798.618, 95.3133, NULL, 0),
(@PATH, 8, -507.2639, 1794.3507, 95.34881, NULL, 0),
(@PATH, 9, -510.61978, 1792.5, 95.459305, NULL, 0),
(@PATH, 10, -516.3403, 1791.4445, 95.50821, NULL, 0),
(@PATH, 11, -523.5018, 1791.625, 95.58664, NULL, 0),
(@PATH, 12, -529.69446, 1795.6146, 95.72307, NULL, 0),
(@PATH, 13, -531.8768, 1793.9861, 95.547104, NULL, 0),
(@PATH, 14, -526.9965, 1790.1337, 95.79614, NULL, 0),
(@PATH, 15, -518.3108, 1790.8577, 95.57664, NULL, 0),
(@PATH, 16, -511.0816, 1792.8923, 95.44728, NULL, 0),
(@PATH, 17, -503.21527, 1795.4584, 95.310165, NULL, 0),
(@PATH, 18, -498.56946, 1803.6962, 95.344795, NULL, 0),
(@PATH, 19, -496.45486, 1809.9185, 95.364586, NULL, 0),
(@PATH, 20, -495.68057, 1819.0868, 95.40278, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '257251');

-- Path for Soulgorged Gravestalker
SET @MOVERGUID := @CGUID+50;
SET @ENTRY := 126263;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Soulgorged Gravestalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -544.50696, 1823.731, 94.7005, NULL, 0),
(@PATH, 1, -544.65106, 1821.4479, 94.77702, NULL, 0),
(@PATH, 2, -544.41144, 1816.9305, 94.90853, NULL, 0),
(@PATH, 3, -543.9531, 1812.3385, 94.85419, NULL, 0),
(@PATH, 4, -542.6597, 1806.7188, 95.2855, NULL, 0),
(@PATH, 5, -541.30035, 1802.4567, 95.37656, NULL, 0),
(@PATH, 6, -540.17535, 1799.2916, 95.358765, NULL, 0),
(@PATH, 7, -538.56946, 1797.0764, 95.33209, NULL, 0),
(@PATH, 8, -536.6389, 1797.2048, 95.40559, NULL, 0),
(@PATH, 9, -537.30206, 1798.8073, 95.40431, NULL, 0),
(@PATH, 10, -539.2969, 1801.7188, 95.43816, NULL, 0),
(@PATH, 11, -540.6059, 1804.2692, 95.49097, NULL, 0),
(@PATH, 12, -542.2552, 1807.3247, 95.28709, NULL, 0),
(@PATH, 13, -543.2847, 1810.8889, 95.04554, NULL, 0),
(@PATH, 14, -543.9844, 1814.9462, 94.90232, NULL, 0),
(@PATH, 15, -544.408, 1817.092, 94.899445, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '257251');

-- Path for Soulgorged Gravestalker
SET @MOVERGUID := @CGUID+72;
SET @ENTRY := 126263;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Soulgorged Gravestalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -544.81946, 1781.8317, 94.31515, NULL, 0),
(@PATH, 1, -545.42365, 1783.4392, 94.37674, NULL, 0),
(@PATH, 2, -549.2153, 1780, 93.229836, NULL, 0),
(@PATH, 3, -553.1424, 1777.4479, 92.247345, NULL, 0),
(@PATH, 4, -561.67706, 1771.1754, 91.802635, NULL, 0),
(@PATH, 5, -568.1094, 1769.3473, 91.84539, NULL, 0),
(@PATH, 6, -573.4531, 1769.4462, 91.9488, NULL, 0),
(@PATH, 7, -576.46704, 1770.4462, 92.050354, NULL, 0),
(@PATH, 8, -582.9358, 1775.4305, 92.34549, NULL, 0),
(@PATH, 9, -585.7083, 1780.1077, 93.05035, NULL, 0),
(@PATH, 10, -583.2726, 1774.8142, 92.334366, NULL, 0),
(@PATH, 11, -579.3559, 1770.2396, 92.21843, NULL, 0),
(@PATH, 12, -574.23615, 1766.7865, 92.05601, NULL, 0),
(@PATH, 13, -568.5972, 1765.6719, 91.93334, NULL, 0),
(@PATH, 14, -562.19617, 1767.5573, 91.80234, NULL, 0),
(@PATH, 15, -555.67017, 1770.7048, 91.80654, NULL, 0),
(@PATH, 16, -548.658, 1777.3264, 92.916664, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '257251');

-- Path for Soulgorged Gravestalker
SET @MOVERGUID := @CGUID+90;
SET @ENTRY := 126263;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Soulgorged Gravestalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -659.40625, 1839.2812, 106.55522, NULL, 0),
(@PATH, 1, -668.0174, 1849.6632, 108.4801, NULL, 0),
(@PATH, 2, -673.6198, 1859.6459, 110.04689, NULL, 1850),
(@PATH, 3, -668.0174, 1849.6632, 108.4801, NULL, 0),
(@PATH, 4, -659.40625, 1839.2812, 106.55522, NULL, 0),
(@PATH, 5, -647.934, 1825.481, 104.12843, NULL, 3274);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '257251');

-- Path for Brutus Thornton
SET @MOVERGUID := @CGUID+84;
SET @ENTRY := 139136;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Brutus Thornton - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -624.86804, 1910.5938, 109.73627, NULL, 0),
(@PATH, 1, -629.1285, 1909.7709, 110.05121, NULL, 0),
(@PATH, 2, -631.30554, 1905.9618, 110.06363, NULL, 0),
(@PATH, 3, -628.9393, 1904.1823, 109.72213, NULL, 0),
(@PATH, 4, -624.33856, 1903.0243, 109.72095, NULL, 0),
(@PATH, 5, -618.6424, 1902.4791, 109.63285, NULL, 0),
(@PATH, 6, -614.60767, 1900.5764, 109.63285, NULL, 0),
(@PATH, 7, -614.5434, 1896.7673, 109.63284, NULL, 0),
(@PATH, 8, -617.8542, 1894.9098, 109.55992, NULL, 0),
(@PATH, 9, -622.42535, 1896.2622, 109.55971, NULL, 0),
(@PATH, 10, -625.52954, 1897.6406, 109.5757, NULL, 0),
(@PATH, 11, -629.0469, 1898.9966, 109.64529, NULL, 0),
(@PATH, 12, -631.9149, 1900.1702, 109.72095, NULL, 6097),
(@PATH, 13, -625.52954, 1897.6406, 109.5757, NULL, 0),
(@PATH, 14, -622.42535, 1896.2622, 109.55971, NULL, 0),
(@PATH, 15, -617.8542, 1894.9098, 109.55992, NULL, 0),
(@PATH, 16, -614.5434, 1896.7673, 109.63284, NULL, 0),
(@PATH, 17, -614.60767, 1900.5764, 109.63285, NULL, 0),
(@PATH, 18, -618.6424, 1902.4791, 109.63285, NULL, 0),
(@PATH, 19, -624.33856, 1903.0243, 109.72095, NULL, 0),
(@PATH, 20, -628.9393, 1904.1823, 109.72213, NULL, 0),
(@PATH, 21, -631.30554, 1905.9618, 110.06363, NULL, 0),
(@PATH, 22, -629.1285, 1909.7709, 110.05121, NULL, 0),
(@PATH, 23, -624.86804, 1910.5938, 109.73627, NULL, 0),
(@PATH, 24, -620.3177, 1910.5399, 109.63285, NULL, 0),
(@PATH, 25, -614.9844, 1909.724, 109.63284, NULL, 4802),
(@PATH, 26, -620.3177, 1910.5399, 109.63285, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
