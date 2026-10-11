SET @CGUID := 10006210;
SET @OGUID := 10001544;

SET @ATSPAWNID := 117;
SET @ATPROPERTIESID := 99;

SET @NPCTEXTID := 600105;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+381;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 231014, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1685.5086669921875, -2708.342041015625, 337.111114501953125, 2.406500577926635742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Loaderbot (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+1, 231380, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1832.5087890625, -2595.5234375, 360.69036865234375, 5.808621406555175781, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Undercrawler (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+2, 231380, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1887.900146484375, -2765.186279296875, 342.06201171875, 5.051291465759277343, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Undercrawler (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+3, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1740.5863037109375, -2761.196044921875, 335.041259765625, 1.121158003807067871, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion)
(@CGUID+4, 222876, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1840.593994140625, -2627.3017578125, 366.09722900390625, 5.572440624237060546, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+5, 73783, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1977.66845703125, -2693.34033203125, 373.544403076171875, 3.409895896911621093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Danger Ahead (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+6, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1920.154541015625, -2723.310791015625, 361.356597900390625, 1.600920438766479492, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+7, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1891.72119140625, -2784.556396484375, 341.897216796875, 1.54991912841796875, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+8, 235065, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1706.82373046875, -2760.9140625, 335.91436767578125, 2.285087823867797851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Targeting Stalker (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 1213693 - [DNT] Zeppelin Targeting Trigger)
(@CGUID+9, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1905.361083984375, -2623.6025390625, 371.888031005859375, 3.598980903625488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+10, 235862, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1716.0555419921875, -2713.15966796875, 335.031585693359375, 2.540085792541503906, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Venture Co. Electrician (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+11, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1740.357666015625, -2715.19091796875, 338.411376953125, 2.904015302658081054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+12, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1920.1197509765625, -2725.84033203125, 360.979583740234375, 3.445685148239135742, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+13, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1890.5191650390625, -2749.84033203125, 349.26287841796875, 5.822384834289550781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+14, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1765.1632080078125, -2625.3994140625, 356.3797607421875, 3.430500268936157226, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+15, 220173, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1948.327880859375, -2833.710205078125, 364.708038330078125, 2.530206203460693359, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Lightdarter (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+16, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1758.390625, -2664.6806640625, 342.97808837890625, 5.831896781921386718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+17, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1973.465087890625, -2903.482421875, 370.27532958984375, 4.675077438354492187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+18, 231496, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1717.7222900390625, -2753.619873046875, 335.0416259765625, 1.608176231384277343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Diver (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+19, 222875, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1853.8466796875, -2666.09375, 359.6085205078125, 3.173839807510375976, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+20, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 2, 1860.7239990234375, -2764.880126953125, 348.47882080078125, 2.713489532470703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+21, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1764.654541015625, -2595.767333984375, 372.523223876953125, 4.41660165786743164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+22, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1919.7899169921875, -2724.057373046875, 360.97967529296875, 5.119798183441162109, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+23, 210931, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1715.717041015625, -2776.05908203125, 335.12640380859375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+24, 235862, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1713.51220703125, -2705.15625, 335.033203125, 5.969997406005859375, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Venture Co. Electrician (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+25, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1819.05908203125, -2784.677001953125, 350.2559814453125, 1.568600296974182128, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+26, 220173, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1789.1376953125, -2596.455810546875, 369.7667236328125, 5.586931705474853515, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Lightdarter (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+27, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1735.52685546875, -2852.63916015625, 334.90350341796875, 5.974795341491699218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+28, 210930, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1862.734375, -2718.645751953125, 347.3203125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+29, 211137, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1924.8785400390625, -2705.123291015625, 358.70916748046875, 3.05991673469543457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+30, 231014, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1687.420166015625, -2718.708251953125, 337.23480224609375, 4.089860439300537109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Loaderbot (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+31, 211150, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1802, -2762.713623046875, 350.2559814453125, 2.187007427215576171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+32, 229686, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1799.5816650390625, -2763.85595703125, 350.2559814453125, 4.973515033721923828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Surveyor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+33, 211149, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1702.857666015625, -2729.37158203125, 337.07159423828125, 1.506066083908081054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+34, 226403, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1615.875, -2860.092041015625, 363.510345458984375, 0.777988195419311523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Keeza Quickfuse (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 462284 - [DNT] Gun, 462000 - [DNT] Jetpack Flames, 422359 - Bot AI Follow Advert)
(@CGUID+35, 222876, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1783.573486328125, -2847.901611328125, 348.648468017578125, 1.617728590965270996, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 233019, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1932.8125, -2697.1494140625, 358.70916748046875, 3.429440736770629882, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Renzik "The Shiv" (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471701 - Stealth)
(@CGUID+37, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1802.829833984375, -2744.8125, 350.2559814453125, 3.988157272338867187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+38, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1884.0054931640625, -2803.62841796875, 341.8577880859375, 3.816333770751953125, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+39, 226402, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1619.861083984375, -2862.6650390625, 362.4051513671875, 4.565266609191894531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Bront (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422359 - Bot AI Follow Advert, 1216276 - [DNT] Hold Crate)
(@CGUID+40, 211137, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1706.1666259765625, -2729.0625, 337.0709228515625, 0.362468481063842773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+41, 210932, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1698.2916259765625, -2805.82470703125, 338.64923095703125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+42, 211149, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1927.93408203125, -2706.89404296875, 358.70916748046875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+43, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1783.357666015625, -2554.421875, 381.13507080078125, 3.689175367355346679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+44, 222876, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1785.828369140625, -2619.986328125, 362.490814208984375, 3.420428752899169921, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+45, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 2, 1745.0103759765625, -2569.361083984375, 355.731201171875, 2.871733427047729492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+46, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1695.9404296875, -2655.177001953125, 342.894744873046875, 3.149593114852905273, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+47, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1921.295166015625, -2721.265625, 358.943023681640625, 1.002538442611694335, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+48, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1909.998291015625, -2623.47216796875, 373.376373291015625, 5.562898159027099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+49, 211151, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1932.2847900390625, -2703.7900390625, 358.70916748046875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+50, 231380, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1969.5555419921875, -2729.36572265625, 341.233856201171875, 6.036411285400390625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Undercrawler (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+51, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1888.79345703125, -2745.260498046875, 348.7833251953125, 0.942034125328063964, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+52, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1977.3536376953125, -2906.536376953125, 370.27532958984375, 4.675055980682373046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+53, 222875, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1783.53759765625, -2577.25634765625, 374.03179931640625, 4.606694221496582031, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+54, 222751, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1920.46337890625, -2809.6767578125, 360.376129150390625, 2.481462717056274414, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Azure Flickerfly (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+55, 211150, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1926.7742919921875, -2703.454833984375, 358.70916748046875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+56, 210931, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1690.513916015625, -2708.3681640625, 337.0709228515625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+57, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1920.0521240234375, -2724.170166015625, 361.39459228515625, 2.158802986145019531, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+58, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1808.7520751953125, -2617.40673828125, 364.550750732421875, 0.208501949906349182, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics) (possible waypoints or random movement)
(@CGUID+59, 235862, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1711.517333984375, -2709.729248046875, 335.033203125, 0.028819663450121879, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Venture Co. Electrician (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+60, 220173, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1811.1246337890625, -2674.012939453125, 351.011749267578125, 2.37060403823852539, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Lightdarter (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+61, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1919.6771240234375, -2725.05908203125, 360.979736328125, 3.30828261375427246, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+62, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1781.361083984375, -2557.045166015625, 379.98004150390625, 5.249244213104248046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+63, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1910.921875, -2775.392333984375, 346.439483642578125, 5.799915313720703125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+64, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1748.3421630859375, -2854.979736328125, 336.4466552734375, 5.332071304321289062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+65, 222876, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1795.8895263671875, -2644.839111328125, 359.37677001953125, 0.955429315567016601, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+66, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1793.491455078125, -2823.439208984375, 343.54656982421875, 2.432966470718383789, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+67, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1919.3697509765625, -2724.3369140625, 360.979766845703125, 2.010924100875854492, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+68, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1921.5052490234375, -2853.09375, 358.41455078125, 6.077171802520751953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+69, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1916.548583984375, -2763.286376953125, 346.439483642578125, 5.483588695526123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+70, 235065, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1738.3961181640625, -2794.96923828125, 335.7244873046875, 0.441139370203018188, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Targeting Stalker (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 1213693 - [DNT] Zeppelin Targeting Trigger)
(@CGUID+71, 222751, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1924.7066650390625, -2858.410888671875, 361.09796142578125, 2.623551607131958007, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Azure Flickerfly (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+72, 230740, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1801.8350830078125, -2767.69970703125, 350.2559814453125, 1.032552242279052734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Shreddinator 3000 (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+73, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 2, 1745.1666259765625, -2571.697998046875, 355.732666015625, 3.367669343948364257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+74, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1812.545166015625, -2688.444580078125, 347.29541015625, 2.863586187362670898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+75, 231380, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1832.602783203125, -2814.7490234375, 344.07025146484375, 4.341724872589111328, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Undercrawler (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+76, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1953.630126953125, -2733.459716796875, 341.301513671875, 4.121676445007324218, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+77, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1781.94970703125, -2693.595458984375, 347.3203125, 5.783085346221923828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+78, 235848, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1722.1510009765625, -2707.814208984375, 335.033203125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Electrified Water (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+79, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1782.5, -2688.083251953125, 347.3203125, 0.182448908686637878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics)
(@CGUID+80, 229212, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1749.6129150390625, -2670.8681640625, 342.97808837890625, 0.306473374366760253, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Demolitionist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 461805 - Locked and Loaded, 468599 - [DNT] Darkfuse Demolitionist Cosmetic, 1217843 - Advert)
(@CGUID+81, 234992, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1598.392578125, -2806.021240234375, 420.000030517578125, 2.378621578216552734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Zeppelin Stalker (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+82, 230740, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1848.8541259765625, -2727.583251953125, 347.8983154296875, 0.264270812273025512, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Shreddinator 3000 (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+83, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1709.060791015625, -2694.84033203125, 337.113037109375, 4.537569046020507812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+84, 211149, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1793.185791015625, -2762.876708984375, 350.2559814453125, 0.890235602855682373, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+85, 211152, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1802.8992919921875, -2758.69970703125, 350.2559814453125, 2.626580476760864257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+86, 231014, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1838.2864990234375, -2747.67529296875, 351.362701416015625, 5.634812831878662109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Loaderbot (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+87, 229686, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1737.923583984375, -2718.579833984375, 337.68212890625, 2.542589187622070312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Surveyor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+88, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1921.248291015625, -2725.654541015625, 360.9791259765625, 3.445685148239135742, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+89, 220173, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1983.68212890625, -2861.038818359375, 370.3482666015625, 2.681706905364990234, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Lightdarter (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+90, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1927.7135009765625, -2733.083251953125, 360.31939697265625, 2.665873289108276367, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+91, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1920.96875, -2765.007080078125, 346.439483642578125, 5.286438941955566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+92, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1964.4183349609375, -2906.052001953125, 370.38763427734375, 4.675091743469238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+93, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1779.7725830078125, -2576.138916015625, 373.8642578125, 1.855023980140686035, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics)
(@CGUID+94, 211150, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1709.8680419921875, -2733.6181640625, 337.071533203125, 2.802837371826171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+95, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1920.420166015625, -2725.6025390625, 360.979400634765625, 4.652664661407470703, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+96, 234481, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1726.814208984375, -2767.4306640625, 387.396240234375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mine Field (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+97, 210931, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1703.6163330078125, -2732.661376953125, 337.071533203125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+98, 211152, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1708.3819580078125, -2736.94970703125, 337.100006103515625, 3.24241042137145996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+99, 231380, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1838.22314453125, -2617.070068359375, 366.223175048828125, 2.033694744110107421, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Undercrawler (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+100, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1771.3603515625, -2821.156005859375, 335.042877197265625, 5.85053253173828125, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+101, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1759.6197509765625, -2596.104248046875, 372.523223876953125, 5.095066070556640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+102, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1908.9305419921875, -2770.7744140625, 346.439483642578125, 5.549450397491455078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+103, 235065, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1745.80224609375, -2787.859375, 336.006439208984375, 3.318830490112304687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Targeting Stalker (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 1213693 - [DNT] Zeppelin Targeting Trigger)
(@CGUID+104, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1925.861083984375, -2724.001708984375, 360.091064453125, 5.290589809417724609, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+105, 231014, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1685.392333984375, -2713.689208984375, 337.08349609375, 3.334879636764526367, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Loaderbot (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+106, 222876, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1826.3575439453125, -2589.267333984375, 364.8365478515625, 3.926990985870361328, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+107, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1909.7552490234375, -2628.74658203125, 372.98406982421875, 4.247971057891845703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+108, 73783, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1978.4791259765625, -2697.005126953125, 373.36614990234375, 3.101511955261230468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Danger Ahead (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+109, 231380, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1818.345458984375, -2852.4619140625, 355.964874267578125, 3.640370607376098632, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Undercrawler (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+110, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1949.385986328125, -2731.960205078125, 341.12933349609375, 0.058641102164983749, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+111, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1779.7899169921875, -2690.791748046875, 347.3203125, 0.126362726092338562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+112, 230748, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1761.548583984375, -2585.048583984375, 372.523223876953125, 5.693526268005371093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Bloodwarper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+113, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1919.388916015625, -2724.553955078125, 361.394989013671875, 6.017384529113769531, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+114, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1737.5694580078125, -2689.451416015625, 337.0709228515625, 3.653389692306518554, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+115, 222614, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1830.7216796875, -2616.90185546875, 364.045166015625, 1.689461350440979003, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Azure Flickerfly (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+116, 220173, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1869.0523681640625, -2749.181640625, 348.764312744140625, 0.984458386898040771, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Lightdarter (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+117, 231014, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1842.3941650390625, -2747.578125, 351.4876708984375, 4.791621208190917968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Loaderbot (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+118, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1858.5728759765625, -2769.376708984375, 350.01629638671875, 2.202503919601440429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+119, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1920.748291015625, -2724.270751953125, 361.39459228515625, 1.900124430656433105, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+120, 229212, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1691.59033203125, -2652.7119140625, 342.894744873046875, 3.149616241455078125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Demolitionist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 461805 - Locked and Loaded, 468599 - [DNT] Darkfuse Demolitionist Cosmetic, 1217843 - Advert)
(@CGUID+121, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1920.9879150390625, -2725.022705078125, 361.39459228515625, 5.550251483917236328, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+122, 231380, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1769.1495361328125, -2852.474365234375, 346.537872314453125, 2.356884479522705078, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Undercrawler (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+123, 220173, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1913.3206787109375, -2838.170654296875, 357.94342041015625, 0.877879679203033447, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Lightdarter (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+124, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1756.9583740234375, -2659.40625, 342.97808837890625, 5.831896781921386718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+125, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1822.6944580078125, -2783.798583984375, 350.2559814453125, 1.799241185188293457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+126, 211111, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1929.154541015625, -2701.420166015625, 358.70916748046875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+127, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1715.7991943359375, -2840.108154296875, 334.92413330078125, 0.447936177253723144, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+128, 229212, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1812.12841796875, -2619.85009765625, 363.857208251953125, 6.050528526306152343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Demolitionist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 461805 - Locked and Loaded, 468599 - [DNT] Darkfuse Demolitionist Cosmetic, 1217843 - Advert)
(@CGUID+129, 222876, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1804.8056640625, -2821.376953125, 342.76708984375, 1.978509306907653808, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+130, 230740, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1770.0572509765625, -2612.272705078125, 369.2841796875, 3.893946647644042968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Shreddinator 3000 (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+131, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1798.8975830078125, -2742.888916015625, 350.2559814453125, 4.946031093597412109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+132, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1915.4583740234375, -2623.600830078125, 375.460693359375, 3.012313127517700195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+133, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1864.0941162109375, -2819.2724609375, 341.736846923828125, 2.142595529556274414, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+134, 229686, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1805.8836669921875, -2770.01904296875, 350.2559814453125, 2.800972223281860351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Surveyor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+135, 211137, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1791.3177490234375, -2756.4306640625, 350.2559814453125, 6.029822826385498046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+136, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1764.5396728515625, -2751.787353515625, 336.7877197265625, 1.533771872520446777, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion)
(@CGUID+137, 226398, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1650.71533203125, -2579.671875, 355.717254638671875, 3.15631413459777832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Big M.O.M.M.A. (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 472036 - Mobilize Mechadrones, 473386 - Mobilize Mechadrones, 471652 - Broadcast Orders, 422356 - Bot AI Follow Advert, 472038 - Mobilize Mechadrones)
(@CGUID+138, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1858.7691650390625, -2773.817626953125, 352.26953125, 4.887012004852294921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+139, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1923.1927490234375, -2762.69970703125, 346.439483642578125, 5.365091323852539062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+140, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1746.79638671875, -2849.685791015625, 336.2259521484375, 4.95758819580078125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+141, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1778.3704833984375, -2571.339599609375, 373.7955322265625, 1.854870080947875976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics) (possible waypoints or random movement)
(@CGUID+142, 222751, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1865.906005859375, -2687.475341796875, 359.114837646484375, 1.166269779205322265, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Azure Flickerfly (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+143, 222876, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1865.451416015625, -2788.963623046875, 352.1298828125, 4.106782913208007812, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+144, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1921.0086669921875, -2718.401123046875, 358.7100830078125, 5.119798183441162109, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+145, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1695.9002685546875, -2650.17724609375, 342.894775390625, 3.149646520614624023, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+146, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1731.7552490234375, -2682.15625, 337.0709228515625, 5.180438995361328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+147, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1891.0225830078125, -2743.03466796875, 348.783355712890625, 3.952124595642089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+148, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1978.7044677734375, -2911.29248046875, 370.27532958984375, 4.856203079223632812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+149, 230564, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1713.2100830078125, -2767.265625, 385.1263427734375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Weapons Stockpile (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+150, 231496, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1677.5631103515625, -2763.33642578125, 334.943450927734375, 2.863619089126586914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Diver (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+151, 222875, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1846.098876953125, -2726.880859375, 347.94989013671875, 3.757756948471069335, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+152, 222751, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1986.841064453125, -2753.86962890625, 368.701171875, 3.778840065002441406, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Azure Flickerfly (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+153, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 2, 1854.857666015625, -2772.10595703125, 350.80108642578125, 1.416117787361145019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+154, 73783, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1965.2882080078125, -2787.572998046875, 356.856842041015625, 2.659839630126953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Danger Ahead (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+155, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1920.4097900390625, -2724.8056640625, 361.744293212890625, 4.499503135681152343, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+156, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1823.1649169921875, -2698.109130859375, 347.310943603515625, 2.363372802734375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+157, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1912.8472900390625, -2724.257080078125, 358.776123046875, 2.665873289108276367, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+158, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1778.935791015625, -2555.09716796875, 380.4573974609375, 4.248642444610595703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+159, 231380, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1943.582763671875, -2757.902587890625, 341.507843017578125, 3.14268803596496582, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Undercrawler (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+160, 231385, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1718.4635009765625, -2622.0400390625, 342.977508544921875, 3.390687942504882812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Inspector (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+161, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1810.5838623046875, -2622.567138671875, 365.02569580078125, 0.190406039357185363, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics)
(@CGUID+162, 211151, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1706.6649169921875, -2732.897705078125, 337.071502685546875, 4.428132534027099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+163, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1732.2293701171875, -2862.62353515625, 334.811767578125, 1.107523679733276367, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+164, 210930, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1702.717041015625, -2629.138916015625, 342.97705078125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+165, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1749.229736328125, -2751.441162109375, 334.979156494140625, 3.895787715911865234, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion)
(@CGUID+166, 237350, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1700.3663330078125, -2734.93408203125, 337.23480224609375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+167, 222876, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1751.310791015625, -2867.195556640625, 341.193450927734375, 0.183318942785263061, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+168, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1856.185791015625, -2819.57470703125, 342.0634765625, 5.752785205841064453, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+169, 211151, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1802.1649169921875, -2751.7275390625, 350.2559814453125, 3.812301874160766601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+170, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1864.5382080078125, -2765.366455078125, 348.6995849609375, 0.363153964281082153, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+171, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1920.861083984375, -2724.94091796875, 360.979248046875, 1.002538442611694335, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+172, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1908.779541015625, -2778.013916015625, 346.439483642578125, 5.761525630950927734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+173, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1742.7042236328125, -2854.853271484375, 335.552703857421875, 5.252975940704345703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+174, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1783.169921875, -2569.9375, 374.7972412109375, 1.853104710578918457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics) (possible waypoints or random movement)
(@CGUID+175, 222751, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1941.634765625, -2881.344970703125, 372.686187744140625, 5.924696922302246093, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Azure Flickerfly (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+176, 222876, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1889.0308837890625, -2641.02685546875, 362.501220703125, 3.963602066040039062, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+177, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1814.0316162109375, -2824.91357421875, 341.92755126953125, 1.21800851821899414, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+178, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 2, 1735.1822509765625, -2720.713623046875, 337.823883056640625, 2.559911489486694335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+179, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1920.154541015625, -2724.8369140625, 361.744781494140625, 1.600920438766479492, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+180, 231380, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1750.1595458984375, -2865.51806640625, 341.089996337890625, 4.735822200775146484, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Undercrawler (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+181, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1922.63720703125, -2849.569580078125, 358.465362548828125, 6.073724269866943359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+182, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1970.7100830078125, -2910.9931640625, 370.27532958984375, 4.674970149993896484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+183, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1919.3228759765625, -2722.2431640625, 362.894775390625, 3.30828261375427246, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+184, 222875, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1839.2640380859375, -2636.134521484375, 362.37396240234375, 1.776424407958984375, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Meek Bloodlasher (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+185, 222751, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1990.746337890625, -2822.474609375, 366.3397216796875, 4.576292037963867187, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Azure Flickerfly (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+186, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1782.2725830078125, -2696.944580078125, 347.75103759765625, 5.937697410583496093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics)
(@CGUID+187, 230740, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1760.0382080078125, -2553.951416015625, 365.21923828125, 1.603787064552307128, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Shreddinator 3000 (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+188, 238023, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1861.609375, -2781.132080078125, 352.626708984375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 472701 - Helper)
(@CGUID+189, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1707.5833740234375, -2696.54345703125, 337.112823486328125, 4.895283699035644531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+190, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1811.851318359375, -2698.0576171875, 347.236968994140625, 2.677875518798828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+191, 231385, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1714.486083984375, -2619.5244140625, 342.97747802734375, 5.196485519409179687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Inspector (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+192, 211152, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1930.4288330078125, -2700.68408203125, 358.70916748046875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+193, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1719.5625, -2860.938232421875, 335.1878662109375, 5.447381019592285156, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+194, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1754.814208984375, -2667.1806640625, 342.97808837890625, 5.831896781921386718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+195, 210930, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1799.796875, -2753.407958984375, 350.2559814453125, 5.667355060577392578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+196, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1920.5035400390625, -2724.34033203125, 360.9793701171875, 1.261217117309570312, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+197, 229212, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1750.263916015625, -2659.373291015625, 342.97808837890625, 5.694385051727294921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Demolitionist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 461805 - Locked and Loaded, 468599 - [DNT] Darkfuse Demolitionist Cosmetic, 1217843 - Advert)
(@CGUID+198, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1895.3697509765625, -2744.951416015625, 349.262451171875, 5.621158599853515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+199, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1757.4132080078125, -2617.28125, 355.884063720703125, 4.219912528991699218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+200, 237350, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1798.1024169921875, -2757.954833984375, 350.2559814453125, 5.667355060577392578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+201, 231014, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1836.4305419921875, -2752.395751953125, 350.7568359375, 0.081770233809947967, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Loaderbot (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+202, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1968.5242919921875, -2903.297607421875, 370.27911376953125, 4.675017356872558593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+203, 229686, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1706.8489990234375, -2694.6650390625, 337.114166259765625, 5.396539688110351562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Surveyor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+204, 231496, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1717.6749267578125, -2758.70166015625, 335.0430908203125, 1.561436891555786132, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Diver (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+205, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1919.342041015625, -2725.053955078125, 361.39508056640625, 2.908510684967041015, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+206, 73783, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1964.467041015625, -2792.366455078125, 356.807525634765625, 2.913769960403442382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Danger Ahead (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+207, 220173, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 2013.2998046875, -2772.42724609375, 370.328399658203125, 2.89780426025390625, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Lightdarter (Area: The Waterworks - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+208, 227145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1775.444091796875, -2806.849853515625, 335.0430908203125, 6.058311939239501953, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Waterworks Crocolisk (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+209, 231642, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1920.10595703125, -2725.263916015625, 361.39508056640625, 4.205869674682617187, 7200, 0, 0, 0, NULL, 33536, 2049, 2214600704, 59570), -- Waterworks Opportunist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+210, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1784.572021484375, -2574.73681640625, 374.507904052734375, 1.855285525321960449, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics) (possible waypoints or random movement)
(@CGUID+211, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1693.566162109375, -2647.6962890625, 342.894744873046875, 0.008226370438933372, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+212, 230740, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1684.6632080078125, -2854.053955078125, 352.269683837890625, 2.310088872909545898, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Shreddinator 3000 (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+213, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1673.3072509765625, -2821.767333984375, 338.364288330078125, 2.806096076965332031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+214, 229686, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1697.76220703125, -2870.19970703125, 352.73736572265625, 2.990256786346435546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Surveyor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+215, 210932, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1667.2916259765625, -2745.9619140625, 334.96728515625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+216, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 2, 1697.5972900390625, -2867.265625, 352.2310791015625, 3.233671903610229492, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+217, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1694.829833984375, -2871.921875, 352.2310791015625, 2.270637750625610351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+218, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1674.179443359375, -2727.398193359375, 335.04815673828125, 0.236150652170181274, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion)
(@CGUID+219, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1678.02783203125, -2821.583251953125, 338.364288330078125, 5.884578227996826171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+220, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1658.4798583984375, -2707.22509765625, 334.5732421875, 4.664650440216064453, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion)
(@CGUID+221, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1690.5052490234375, -2618.50341796875, 342.992218017578125, 5.047539234161376953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+222, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1683.7691650390625, -2621.401123046875, 342.9752197265625, 5.533737659454345703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+223, 210931, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1671.5035400390625, -2859.123291015625, 352.234039306640625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+224, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1681.8316650390625, -2627.71533203125, 342.977142333984375, 5.901432991027832031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+225, 210932, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1672.763916015625, -2857.545166015625, 352.232177734375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+226, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1666.2816162109375, -2712.334716796875, 334.31927490234375, 2.127713203430175781, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion)
(@CGUID+227, 230740, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1673.5572509765625, -2861.7744140625, 352.303741455078125, 1.616809368133544921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Shreddinator 3000 (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+228, 210932, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1651.4132080078125, -2812.185791015625, 338.363250732421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422360 - Bot AI Follow Advert)
(@CGUID+229, 210930, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1700.3992919921875, -2573.751708984375, 355.748779296875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+230, 231496, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1647.5546875, -2731.9404296875, 334.991943359375, 2.205225467681884765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Diver (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+231, 231496, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1646.5177001953125, -2754.119873046875, 334.993804931640625, 2.66987156867980957, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Diver (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+232, 231496, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1648.6527099609375, -2730.520751953125, 334.989349365234375, 2.484977483749389648, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Diver (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+233, 231496, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1644.393310546875, -2727.443603515625, 334.99322509765625, 5.464846611022949218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Diver (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+234, 231496, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1641.0260009765625, -2750.79345703125, 334.993804931640625, 2.631136655807495117, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Diver (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+235, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1641.763916015625, -2708.765625, 334.993804931640625, 4.245005130767822265, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion)
(@CGUID+236, 210931, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1649.282958984375, -2816.626708984375, 338.364288330078125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+237, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1660.532958984375, -2605.350830078125, 347.089874267578125, 4.794686317443847656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+238, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1647.4739990234375, -2630.295166015625, 347.089874267578125, 0.229267269372940063, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+239, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1634.1649169921875, -2695.001708984375, 334.971099853515625, 0.415274381637573242, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion)
(@CGUID+240, 235065, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1635.2655029296875, -2734.5927734375, 335.993804931640625, 4.604640483856201171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Targeting Stalker (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 1213693 - [DNT] Zeppelin Targeting Trigger) (possible waypoints or random movement)
(@CGUID+241, 235065, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1635.6385498046875, -2778.447021484375, 336.0023193359375, 0.58201533555984497, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Targeting Stalker (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 1213693 - [DNT] Zeppelin Targeting Trigger) (possible waypoints or random movement)
(@CGUID+242, 210931, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1652.404541015625, -2631.666748046875, 347.089874267578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+243, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1649.3472900390625, -2633.09033203125, 347.089874267578125, 6.094414234161376953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics)
(@CGUID+244, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1635.2396240234375, -2817.569580078125, 338.359375, 1.014660596847534179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+245, 230748, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1698.6788330078125, -2534.857666015625, 360.314056396484375, 5.464444160461425781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Bloodwarper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+246, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1701.7083740234375, -2528.522705078125, 360.309417724609375, 4.307297706604003906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+247, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1654.453125, -2608.86279296875, 347.089874267578125, 5.567626953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+248, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 2, 1632.9461669921875, -2814.40625, 338.359375, 1.292200922966003417, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+249, 237366, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1689.5416259765625, -2536.4462890625, 360.3050537109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- [DNT] Mech Boss Stalker (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 1217612 - [DNT] Mech Boss Stalker)
(@CGUID+250, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1694.1475830078125, -2528.354248046875, 360.3050537109375, 5.170874595642089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+251, 211151, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1690.9583740234375, -2540.640625, 360.3050537109375, 4.428132534027099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+252, 211137, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1685.920166015625, -2541.4306640625, 360.3050537109375, 0.362468481063842773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+253, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1643.8853759765625, -2625.68408203125, 347.089874267578125, 5.920135498046875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+254, 237442, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1691.09033203125, -2539.59375, 360.3050537109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- [DNT] Transmitter (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 1217701 - [DNT] Transmitter, 1217713 - [DNT] Transmitter Communication)
(@CGUID+255, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1632.4068603515625, -2790.756591796875, 335.135711669921875, 2.453327417373657226, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion) (possible waypoints or random movement)
(@CGUID+256, 229686, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1633.21875, -2821.296875, 338.359619140625, 1.095357060432434082, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Surveyor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+257, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1625.442138671875, -2787.58837890625, 335.00244140625, 2.778645038604736328, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion) (possible waypoints or random movement)
(@CGUID+258, 211150, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1696.625, -2531.776123046875, 360.3050537109375, 2.802837371826171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+259, 211149, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1696.0521240234375, -2537.25, 360.305572509765625, 1.506066083908081054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+260, 229252, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1644.96533203125, -2623.19091796875, 347.089874267578125, 5.88285684585571289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Hyena (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics)
(@CGUID+261, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 2, 1668.7222900390625, -2895.03125, 352.611358642578125, 3.221558809280395507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+262, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1680.8055419921875, -2533.475830078125, 360.3050537109375, 4.581990242004394531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+263, 211152, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1683.0555419921875, -2535.067626953125, 360.3050537109375, 3.24241042137145996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+264, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1678.3228759765625, -2534.09033203125, 360.3050537109375, 6.209539413452148437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes)
(@CGUID+265, 231385, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1647.5816650390625, -2535.625, 360.80487060546875, 3.021192073822021484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Inspector (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+266, 231223, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1615.4793701171875, -2723.751708984375, 334.993804931640625, 2.595632076263427734, 7200, 12, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Disturbed Kelp (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+267, 231014, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1614.761474609375, -2629.933837890625, 355.6900634765625, 4.848991870880126953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Loaderbot (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+268, 231385, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1645.0728759765625, -2536.12841796875, 360.79949951171875, 1.393642783164978027, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Inspector (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+269, 229686, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1629.421875, -2815.6494140625, 338.359771728515625, 0.480611085891723632, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Surveyor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+270, 231014, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1606.501708984375, -2629.40283203125, 355.788848876953125, 3.625954151153564453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Loaderbot (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+271, 231014, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1605.704833984375, -2626.29345703125, 355.773406982421875, 3.03995680809020996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Loaderbot (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+272, 231014, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1608.0694580078125, -2632.267333984375, 355.979888916015625, 0.735899567604064941, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Loaderbot (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+273, 231014, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1605.1597900390625, -2622.614501953125, 355.773406982421875, 3.205184459686279296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Loaderbot (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+274, 231223, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1599.3834228515625, -2767.412353515625, 334.993804931640625, 4.706446647644042968, 7200, 12, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Disturbed Kelp (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+275, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1612.866455078125, -2802.407470703125, 335.001495361328125, 5.07647705078125, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion) (possible waypoints or random movement)
(@CGUID+276, 235065, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1607.7642822265625, -2764.74755859375, 335.993804931640625, 0.101623907685279846, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Targeting Stalker (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 1213693 - [DNT] Zeppelin Targeting Trigger) (possible waypoints or random movement)
(@CGUID+277, 231223, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1597.4483642578125, -2758.503662109375, 334.993804931640625, 0.105232611298561096, 7200, 12, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Disturbed Kelp (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+278, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1612.9801025390625, -2792.6650390625, 335.00048828125, 6.01872110366821289, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion) (possible waypoints or random movement)
(@CGUID+279, 231223, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1598.3250732421875, -2725.144775390625, 334.98370361328125, 4.6290283203125, 7200, 12, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Disturbed Kelp (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+280, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1604.166015625, -2800, 335.002593994140625, 1.16017162799835205, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion) (possible waypoints or random movement)
(@CGUID+281, 211149, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1629.673583984375, -2851.838623046875, 362.239532470703125, 0.6922684907913208, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+282, 211137, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1634.6458740234375, -2853.053955078125, 362.13031005859375, 5.831856250762939453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+283, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1574.359619140625, -2631.94384765625, 376.6846923828125, 3.917546749114990234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes) (possible waypoints or random movement)
(@CGUID+284, 231223, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1578.0675048828125, -2734.93798828125, 335.00872802734375, 5.860599517822265625, 7200, 12, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Disturbed Kelp (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+285, 211137, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1572.71533203125, -2750.0625, 335.578857421875, 0.362468481063842773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+286, 211149, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1571.342041015625, -2740.678955078125, 335.64697265625, 1.506066083908081054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+287, 211151, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1571.9913330078125, -2746.140625, 336.2994384765625, 4.428132534027099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+288, 231223, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1583.979248046875, -2779.0751953125, 334.99554443359375, 3.430066347122192382, 7200, 12, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Disturbed Kelp (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+289, 211151, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1633.0972900390625, -2858.78466796875, 362.214263916015625, 3.614335060119628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+290, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1570.8477783203125, -2628.365966796875, 376.60003662109375, 0.792456507682800292, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes) (possible waypoints or random movement)
(@CGUID+291, 211152, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1568.8004150390625, -2737.767333984375, 335.497650146484375, 3.24241042137145996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+292, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1601.54296875, -2813.35107421875, 335.060821533203125, 4.146162033081054687, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion) (possible waypoints or random movement)
(@CGUID+293, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1659.467041015625, -2894.885498046875, 352.611358642578125, 5.298562526702880859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+294, 211150, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1569.4774169921875, -2750.6181640625, 335.897857666015625, 2.802837371826171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+295, 211150, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1625.65625, -2856.234375, 362.33001708984375, 1.989039421081542968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+296, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1592.18603515625, -2809.1083984375, 335.293670654296875, 4.774156570434570312, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion) (possible waypoints or random movement)
(@CGUID+297, 229686, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1664.3697509765625, -2897.854248046875, 352.61138916015625, 1.294706940650939941, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Surveyor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+298, 211152, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1627.703125, -2860.385498046875, 362.317626953125, 2.428612232208251953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+299, 231497, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1579.185546875, -2807.806396484375, 334.894287109375, 3.50841379165649414, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 59570), -- Bombshell Crab (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 468679 - Crabsplosion) (possible waypoints or random movement)
(@CGUID+300, 229212, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1545.111083984375, -2658.48095703125, 377.853271484375, 0.89964991807937622, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Demolitionist (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 461805 - Locked and Loaded, 468599 - [DNT] Darkfuse Demolitionist Cosmetic, 1217843 - Advert)
(@CGUID+301, 211137, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1599.2257080078125, -2852.14404296875, 362.253448486328125, 0.362468481063842773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+302, 211149, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1598.6822509765625, -2855.7431640625, 362.19134521484375, 1.506066083908081054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+303, 211152, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1595.5694580078125, -2853.265625, 362.434600830078125, 3.24241042137145996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+304, 211152, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1541.092041015625, -2650.3056640625, 377.853271484375, 3.24241042137145996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+305, 211149, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1536.4635009765625, -2651.49658203125, 377.853302001953125, 1.506066083908081054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+306, 211151, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1537.1927490234375, -2654.5625, 377.853302001953125, 4.428132534027099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+307, 211151, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1600.3853759765625, -2858.63720703125, 362.824462890625, 4.428132534027099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+308, 210933, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1538.3680419921875, -2746.0556640625, 332.339202880859375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+309, 229069, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1542.484375, -2659.989501953125, 377.923309326171875, 0.6137734055519104, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Mechadrone Sniper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+310, 211150, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1538.6822509765625, -2647.069580078125, 377.853271484375, 2.802837371826171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+311, 211150, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1593.123291015625, -2849.9619140625, 362.193939208984375, 2.802837371826171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+312, 230748, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1541.6336669921875, -2654.451416015625, 377.853271484375, 0.136143460869789123, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Bloodwarper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+313, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1517.748291015625, -2681.76220703125, 377.3887939453125, 0.197191104292869567, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+314, 211137, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1533.2447509765625, -2652.87158203125, 377.85333251953125, 0.362468481063842773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+315, 211152, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1531.0086669921875, -2741.57470703125, 334.76898193359375, 3.24241042137145996, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+316, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1516.9617919921875, -2688.189208984375, 377.723388671875, 1.312857389450073242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+317, 237350, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1534.4010009765625, -2648.420166015625, 377.853302001953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@CGUID+318, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1521.3802490234375, -2685.276123046875, 377.38848876953125, 1.312857389450073242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+319, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 2, 1517.076416015625, -2685.23095703125, 377.7218017578125, 0.408161401748657226, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+320, 211137, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1535.3472900390625, -2742.967041015625, 332.9130859375, 0.362468481063842773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+321, 211149, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1532.15283203125, -2745.916748046875, 333.712371826171875, 1.506066083908081054, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+322, 211151, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1536.3697509765625, -2748.263916015625, 332.847808837890625, 4.428132534027099609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+323, 211150, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1531.1771240234375, -2748.85595703125, 334.811279296875, 2.802837371826171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive)
(@CGUID+324, 210933, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1517.2396240234375, -2784.26220703125, 282.298980712890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+325, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1471.647705078125, -2762.170654296875, 275.804595947265625, 5.144999027252197265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+326, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1522.435791015625, -2832.3125, 282.88818359375, 4.457602500915527343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+327, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1473.922119140625, -2755.297607421875, 275.9781494140625, 5.577538490295410156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+328, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1516.1632080078125, -2832.578125, 282.88818359375, 5.084807872772216796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+329, 231385, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1516.717041015625, -2825.796875, 282.88818359375, 4.93492746353149414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Inspector (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+330, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1466.07421875, -2753.396484375, 275.55853271484375, 4.676136970520019531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+331, 226404, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1195.8333740234375, -2906.882080078125, 277.057861328125, 3.141592741012573242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Geezle Gigazap (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 423679 - Bot AI Follow Advert)
(@CGUID+332, 236982, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1475.4896240234375, -2779.538330078125, 282.565582275390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+333, 236982, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1473.9097900390625, -2780.90625, 282.6800537109375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+334, 236982, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1476.013916015625, -2785.916748046875, 282.51171875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+335, 236982, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1474.078125, -2787.651123046875, 282.710693359375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+336, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1492.3421630859375, -2813.04638671875, 275.409515380859375, 0.219249695539474487, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+337, 236982, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1475.75, -2782.6181640625, 282.51171875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+338, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1466.2734375, -2751.826416015625, 276.19659423828125, 1.411541700363159179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+339, 236982, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1474.1875, -2784.392333984375, 282.686767578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+340, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1484.9410400390625, -2810.508544921875, 276.657073974609375, 3.234717369079589843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+341, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1486.161376953125, -2816.39990234375, 276.3297119140625, 0.354098916053771972, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+342, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1490.8670654296875, -2820.02392578125, 275.390350341796875, 5.544058799743652343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+343, 231312, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1438.8194580078125, -2761.625, 282.310394287109375, 5.031886577606201171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Electrician (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+344, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1430.8804931640625, -2742.703857421875, 276.9569091796875, 2.614778518676757812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+345, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1445.857666015625, -2777.560791015625, 282.259429931640625, 2.187564611434936523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+346, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1429.679443359375, -2748.732177734375, 276.958099365234375, 2.545665502548217773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+347, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1426.228271484375, -2745.909912109375, 276.951080322265625, 0.894280552864074707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+348, 231385, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1438.2222900390625, -2782.625, 282.25946044921875, 0.893407464027404785, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Inspector (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+349, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1426.6466064453125, -2741.1845703125, 276.96087646484375, 5.051245689392089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+350, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1441.703125, -2777.171875, 282.259429931640625, 0.908395707607269287, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+351, 231325, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1422.6666259765625, -2799.71875, 282.295440673828125, 5.568677425384521484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Jumpstarter (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head)
(@CGUID+352, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1393.3883056640625, -2749.99951171875, 275.630401611328125, 5.288521766662597656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+353, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1398.0062255859375, -2753.08984375, 274.45635986328125, 4.440966129302978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+354, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1391.16748046875, -2755.345458984375, 275.6390380859375, 2.874580860137939453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+355, 231385, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1405.1497802734375, -2781.786865234375, 282.5653076171875, 3.161825180053710937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Inspector (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+356, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1396.0369873046875, -2758.185302734375, 274.828887939453125, 3.113324880599975585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+357, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1437.7685546875, -2820.953369140625, 276.067657470703125, 4.092041015625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+358, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1434.390380859375, -2818.5390625, 276.076995849609375, 4.808085918426513671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+359, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1440.8720703125, -2822.97802734375, 276.062255859375, 0.553957998752593994, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+360, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1437.017333984375, -2815.423828125, 276.00701904296875, 1.042781949043273925, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+361, 231312, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1353.5572509765625, -2738.614501953125, 282.88818359375, 5.353015422821044921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Electrician (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+362, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 2, 1356.1510009765625, -2742.91845703125, 282.564910888671875, 5.199371337890625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+363, 231312, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1358.9879150390625, -2738.96533203125, 282.88818359375, 3.788318872451782226, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Electrician (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+364, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1358.170166015625, -2745.333251953125, 282.2989501953125, 4.031980037689208984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+365, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1352.9635009765625, -2745.447998046875, 282.2989501953125, 0.087425187230110168, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+366, 231312, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1384.65283203125, -2786.6259765625, 282.56158447265625, 3.109779119491577148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Electrician (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%) (possible waypoints or random movement)
(@CGUID+367, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1392.4844970703125, -2802.521484375, 275.639068603515625, 1.462056159973144531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+368, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1396.9150390625, -2817.5810546875, 275.126983642578125, 4.900309085845947265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+369, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1397.3572998046875, -2811.5400390625, 275.142730712890625, 4.637372970581054687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+370, 232228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1388.4134521484375, -2812.244873046875, 275.94830322265625, 3.225090503692626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Waterworks Bottomfeeder (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 1224583 - Immunity) (possible waypoints or random movement)
(@CGUID+371, 210933, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1357.3125, -2784.592041015625, 282.2989501953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+372, 231312, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1344.545166015625, -2783.6875, 282.2989501953125, 5.414937019348144531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Electrician (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+373, 231312, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1344.9583740234375, -2789.829833984375, 282.2989501953125, 1.123493909835815429, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Electrician (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+374, 231385, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1369.0208740234375, -2854.609375, 282.809539794921875, 3.690963983535766601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Inspector (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+375, 228144, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1359.810791015625, -2848.593994140625, 283.15533447265625, 4.7144927978515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Soldier (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes) (possible waypoints or random movement)
(@CGUID+376, 229250, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 3, 1354.8038330078125, -2845.260498046875, 283.15533447265625, 4.714467525482177734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Contractor (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+377, 231325, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1351.579833984375, -2898.654541015625, 285.498443603515625, 5.36533212661743164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Jumpstarter (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection, 1216610 - Battery Discharge)
(@CGUID+378, 231385, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1347.1978759765625, -2853.6875, 282.80975341796875, 5.446704387664794921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Darkfuse Inspector (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+379, 231312, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1351.5069580078125, -2891.33154296875, 285.498443603515625, 4.722340583801269531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Venture Co. Electrician (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
(@CGUID+380, 210933, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 0, 1345.8489990234375, -2903.411376953125, 285.498443603515625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570), -- Path Helper (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 423677 - Bot AI Follow Advert)
(@CGUID+381, 231312, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 0, 1, 1343.96533203125, -2898.572998046875, 285.498443603515625, 6.272477149963378906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59570); -- Venture Co. Electrician (Area: The Waterworks - Difficulty: Normal) CreateObject1 (Auras: 471891 - Mod Scale 95-105%)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+381;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '471891'), -- Loaderbot - 471891 - Mod Scale 95-105%
(@CGUID+6, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 358422'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+12, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+20, 0, 0, 0, 0, 0, 0, 0, 569, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+22, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+24, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Venture Co. Electrician
(@CGUID+25, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '471891'), -- Loaderbot - 471891 - Mod Scale 95-105%
(@CGUID+32, 0, 0, 0, 0, 0, 2, 0, 1043, 0, 0, 0, 0, '471891'), -- Venture Co. Surveyor - 471891 - Mod Scale 95-105%
(@CGUID+36, 0, 0, 0, 0, 0, 2, 0, 0, 31248, 0, 0, 0, '471701'), -- Renzik "The Shiv" - 471701 - Stealth
(@CGUID+37, 0, 0, 0, 0, 0, 0, 0, 173, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+43, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 358422'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+45, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+47, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+48, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 358422'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 378, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+57, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+61, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 469766 469771 358422'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+63, 0, 0, 0, 0, 0, 1, 0, 714, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+67, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+68, 0, 0, 0, 0, 0, 0, 0, 716, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+69, 0, 0, 0, 0, 0, 1, 0, 714, 0, 0, 0, 0, ''), -- Mechadrone Sniper
(@CGUID+73, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+77, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+79, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 469766 469771'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics
(@CGUID+82, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '18950'), -- Shreddinator 3000 - 18950 - Invisibility and Stealth Detection
(@CGUID+86, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, '471891'), -- Loaderbot - 471891 - Mod Scale 95-105%
(@CGUID+87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Surveyor - 471891 - Mod Scale 95-105%
(@CGUID+88, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+90, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+91, 0, 0, 0, 0, 0, 1, 0, 714, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+95, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+101, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+102, 0, 0, 0, 0, 0, 1, 0, 714, 0, 0, 0, 0, ''), -- Mechadrone Sniper
(@CGUID+104, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+105, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '471891'), -- Loaderbot - 471891 - Mod Scale 95-105%
(@CGUID+107, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 358422'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+111, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+113, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+114, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 358422'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+117, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, '471891'), -- Loaderbot - 471891 - Mod Scale 95-105%
(@CGUID+118, 0, 0, 0, 0, 0, 0, 0, 569, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+119, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+121, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+124, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+130, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '18950'), -- Shreddinator 3000 - 18950 - Invisibility and Stealth Detection
(@CGUID+131, 0, 0, 0, 0, 0, 0, 0, 173, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+132, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 358422'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+134, 0, 0, 0, 0, 0, 2, 0, 1043, 0, 0, 0, 0, '471891'), -- Venture Co. Surveyor - 471891 - Mod Scale 95-105%
(@CGUID+138, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+139, 0, 0, 0, 0, 0, 1, 0, 714, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+141, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 469766 469771'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics
(@CGUID+144, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+146, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 358422'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+147, 0, 0, 0, 0, 0, 1, 0, 378, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+150, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Diver - 471891 - Mod Scale 95-105%
(@CGUID+153, 0, 0, 0, 0, 0, 0, 0, 569, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+155, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+157, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+158, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 358422'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+160, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'), -- Darkfuse Inspector - 471891 - Mod Scale 95-105%
(@CGUID+171, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+172, 0, 0, 0, 0, 0, 1, 0, 714, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+174, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 469766 469771'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics
(@CGUID+179, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+181, 0, 0, 0, 0, 0, 0, 0, 716, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+183, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+186, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 469766 469771'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics
(@CGUID+187, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '18950'), -- Shreddinator 3000 - 18950 - Invisibility and Stealth Detection
(@CGUID+191, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'), -- Darkfuse Inspector - 471891 - Mod Scale 95-105%
(@CGUID+194, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+196, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+201, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, '471891'), -- Loaderbot - 471891 - Mod Scale 95-105%
(@CGUID+203, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Surveyor - 471891 - Mod Scale 95-105%
(@CGUID+205, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+209, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Waterworks Opportunist - 471891 - Mod Scale 95-105%
(@CGUID+212, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '18950'), -- Shreddinator 3000 - 18950 - Invisibility and Stealth Detection
(@CGUID+214, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Surveyor - 471891 - Mod Scale 95-105%
(@CGUID+221, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+222, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+224, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+227, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '18950'), -- Shreddinator 3000 - 18950 - Invisibility and Stealth Detection
(@CGUID+238, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+243, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 469766 469771'), -- Darkfuse Hyena - 471891 - Mod Scale 95-105%, 469766 - Pack Tactics, 469771 - Pack Tactics
(@CGUID+244, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+246, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+248, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+249, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1217612'), -- [DNT] Mech Boss Stalker - 1217612 - [DNT] Mech Boss Stalker
(@CGUID+250, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+253, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+262, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+264, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891 462735'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%, 462735 - Blood-Infused Strikes
(@CGUID+265, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'), -- Darkfuse Inspector - 471891 - Mod Scale 95-105%
(@CGUID+268, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'), -- Darkfuse Inspector - 471891 - Mod Scale 95-105%
(@CGUID+270, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, '471891'), -- Loaderbot - 471891 - Mod Scale 95-105%
(@CGUID+271, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, '471891'), -- Loaderbot - 471891 - Mod Scale 95-105%
(@CGUID+272, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, '471891'), -- Loaderbot - 471891 - Mod Scale 95-105%
(@CGUID+273, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, '471891'), -- Loaderbot - 471891 - Mod Scale 95-105%
(@CGUID+297, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Surveyor - 471891 - Mod Scale 95-105%
(@CGUID+313, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891 358422'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+316, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891 358422'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+318, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891 358422'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+319, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891 358422'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+326, 0, 0, 0, 0, 0, 0, 0, 431, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+328, 0, 0, 0, 0, 0, 0, 0, 431, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+332, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '471891'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%
(@CGUID+333, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '471891'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%
(@CGUID+334, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '471891'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%
(@CGUID+335, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '471891'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%
(@CGUID+337, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '471891'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%
(@CGUID+339, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '471891'), -- Darkfuse Soldier - 471891 - Mod Scale 95-105%
(@CGUID+343, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Electrician - 471891 - Mod Scale 95-105%
(@CGUID+345, 0, 0, 0, 0, 0, 0, 0, 431, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+350, 0, 0, 0, 0, 0, 0, 0, 431, 0, 0, 0, 0, '471891'), -- Venture Co. Contractor - 471891 - Mod Scale 95-105%
(@CGUID+351, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950 358422'), -- Darkfuse Jumpstarter - 18950 - Invisibility and Stealth Detection, 358422 - Cosmetic - Sleep Zzz (With Aggro Change) - Head
(@CGUID+361, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Electrician - 471891 - Mod Scale 95-105%
(@CGUID+363, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Electrician - 471891 - Mod Scale 95-105%
(@CGUID+366, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Electrician - 471891 - Mod Scale 95-105%
(@CGUID+372, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Electrician - 471891 - Mod Scale 95-105%
(@CGUID+373, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Electrician - 471891 - Mod Scale 95-105%
(@CGUID+374, 0, 0, 0, 0, 0, 0, 0, 425, 0, 0, 0, 0, '471891'), -- Darkfuse Inspector - 471891 - Mod Scale 95-105%
(@CGUID+378, 0, 0, 0, 0, 0, 0, 0, 425, 0, 0, 0, 0, '471891'), -- Darkfuse Inspector - 471891 - Mod Scale 95-105%
(@CGUID+379, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- Venture Co. Electrician - 471891 - Mod Scale 95-105%
(@CGUID+381, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'); -- Venture Co. Electrician - 471891 - Mod Scale 95-105%

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+120;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 467128, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2230.265625, -2777.329833984375, 415.491912841796875, 5.593783378601074218, 0, 0, -0.33791542053222656, 0.941176474094390869, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+1, 467131, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2189.510498046875, -2807.58154296875, 414.369720458984375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+2, 451440, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1812.8634033203125, -3670.60595703125, 322.09124755859375, 0.933750271797180175, 0, 0, 0.450098037719726562, 0.892979145050048828, 7200, 255, 1, 59570), -- Gate (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+3, 467109, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2152.37158203125, -2806.34375, 415.695709228515625, 5.637415885925292968, 0, 0, -0.31730365753173828, 0.948323965072631835, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+4, 467108, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2241.5869140625, -2792.307373046875, 415.550689697265625, 3.857182979583740234, 0, 0, -0.93667125701904296, 0.350209832191467285, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+5, 467111, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2178.8837890625, -2809.515625, 414.779693603515625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+6, 502540, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1760.5362548828125, -2635.798583984375, 343.8375244140625, 6.283170223236083984, 0, 0, -0.00000762939453125, 1, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+7, 467110, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2191.96533203125, -2798.744873046875, 414.599884033203125, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+8, 467105, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2193.244873046875, -2796.604248046875, 415.19293212890625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+9, 446173, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1799.7823486328125, -2619.586669921875, 337.671875, 4.607654571533203125, 0, 0, -0.7431497573852539, 0.669125139713287353, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+10, 467104, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2233.1337890625, -2743.26904296875, 426.894439697265625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+11, 467107, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2194.479248046875, -2800.92529296875, 414.41033935546875, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+12, 446175, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1793.5518798828125, -2621.89111328125, 338.058013916015625, 5.689757347106933593, 0, 0, -0.29237937927246093, 0.956302404403686523, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+13, 467106, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2194.470458984375, -2807.59716796875, 414.364501953125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+14, 502539, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1701.72705078125, -2517.775146484375, 360.257568359375, 1.570798397064208984, 0, 0, 0.7071075439453125, 0.707105994224548339, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+15, 446174, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1775.6444091796875, -2631.152587890625, 343.4681396484375, 4.502936363220214843, 0, 0, -0.77715015411376953, 0.629315197467803955, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+16, 446167, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2136.539306640625, -2865.205078125, 410.61285400390625, 0.863936781883239746, 0, 0, 0.418659210205078125, 0.908143401145935058, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+17, 502538, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1600.6009521484375, -2572.224365234375, 356.344573974609375, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+18, 446166, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2127.705322265625, -2840.83251953125, 410.4111328125, 3.900813102722167968, 0, 0, -0.92880916595458984, 0.370558410882949829, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+19, 467116, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2178.8681640625, -2807.569580078125, 414.420166015625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+20, 467119, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2161.182373046875, -2826.15283203125, 416.575225830078125, 1.265363454818725585, 0, 0, 0.591309547424316406, 0.806444704532623291, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+21, 467113, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2180.0087890625, -2796.84375, 415.21197509765625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+22, 465030, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1797.3055419921875, -2758.33154296875, 350.172637939453125, 0.033685367554426193, 0, 0, 0.016841888427734375, 0.99985814094543457, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+23, 467112, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2189.515625, -2809.541748046875, 414.703033447265625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+24, 446173, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2253.793212890625, -2843.693115234375, 410.286041259765625, 3.81354522705078125, 0, 0, -0.94408893585205078, 0.329690933227539062, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+25, 467115, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2181.361083984375, -2809.517333984375, 414.760589599609375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+26, 446172, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2142.991943359375, -2829.213623046875, 415.824981689453125, 5.47874307632446289, 0, 0, -0.39146327972412109, 0.920193731784820556, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+27, 467114, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2176.404541015625, -2798.76904296875, 414.6519775390625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+28, 446175, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2247.7822265625, -2840.864501953125, 410.67218017578125, 4.895649909973144531, 0, 0, -0.63943862915039062, 0.768842101097106933, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+29, 467093, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2152.135498046875, -2808.5244140625, 415.695709228515625, 0.32288438081741333, 0, 0, 0.160741806030273437, 0.98699653148651123, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+30, 446174, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2228.625, -2834.583740234375, 416.082305908203125, 3.708833217620849609, 0, 0, -0.96004867553710937, 0.279833078384399414, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+31, 467092, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2233.08154296875, -2754.145751953125, 426.814605712890625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+32, 467159, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2176.3837890625, -2800.928955078125, 414.40814208984375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+33, 446169, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2139.345703125, -2865.102783203125, 410.58941650390625, 2.556905269622802734, 0, 0, 0.957571029663085937, 0.288197338581085205, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+34, 467158, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2191.9931640625, -2807.595458984375, 414.38360595703125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+35, 446168, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2127.953857421875, -2858.549072265625, 410.341339111328125, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+36, 446171, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2153.8125, -2837.654541015625, 416.45904541015625, 5.595084190368652343, 0, 0, -0.33730316162109375, 0.941396117210388183, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+37, 467152, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2222.62841796875, -2731.439208984375, 427.225341796875, 6.274457454681396484, 0, 0, -0.004364013671875, 0.999990463256835937, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+38, 446170, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2155.556640625, -2837.59375, 416.4393310546875, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+39, 467155, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2190.76220703125, -2811.335205078125, 415.134735107421875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+40, 467154, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2181.364501953125, -2798.74658203125, 414.646820068359375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+41, 467165, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2180.138916015625, -2811.30908203125, 415.130035400390625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+42, 467101, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2246.345458984375, -2787.96875, 415.550689697265625, 0.767943859100341796, 0, 0, 0.374606132507324218, 0.927184045314788818, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+43, 467102, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2191.998291015625, -2809.5556640625, 414.716949462890625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+44, 507960, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1597.592041015625, -2852.701416015625, 362.32647705078125, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+45, 467163, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2249.522705078125, -2790.53466796875, 415.550689697265625, 2.583087682723999023, 0, 0, 0.961261749267578125, 0.275637149810791015, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+46, 467099, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2187.954833984375, -2836.7587890625, 416.431549072265625, 1.658061861991882324, 0, 0, 0.737277030944824218, 0.67559051513671875, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+47, 467162, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2181.34375, -2800.90625, 414.402984619140625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+48, 467098, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2192.001708984375, -2800.932373046875, 414.429443359375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+49, 507972, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1689.5416259765625, -2536.442626953125, 360.221710205078125, 4.940446376800537109, 0, 0, -0.62205886840820312, 0.78297048807144165, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+50, 467143, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2194.475830078125, -2809.557373046875, 414.697845458984375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+51, 467142, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2190.7744140625, -2796.62158203125, 415.21197509765625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+52, 467137, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2194.442626953125, -2798.73779296875, 414.580841064453125, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+53, 467136, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2154.048583984375, -2809.142333984375, 415.695709228515625, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+54, 507968, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1594.2135009765625, -2858.8681640625, 362.264373779296875, 0.69795691967010498, 0, 0, 0.341938018798828125, 0.939722537994384765, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+55, 467139, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2234.954833984375, -2777.22216796875, 415.550689697265625, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+56, 467148, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2232.572998046875, -2775.272705078125, 415.550689697265625, 4.660032272338867187, 0, 0, -0.7253732681274414, 0.688355743885040283, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+57, 467151, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2177.661376953125, -2811.30908203125, 415.149139404296875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+58, 467150, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2176.385498046875, -2807.5712890625, 414.419403076171875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+59, 465030, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1701.0538330078125, -2735.37841796875, 337.151458740234375, 0.731034398078918457, 0, 0, 0.357432365417480468, 0.933939039707183837, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+60, 467145, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2244.0625, -2790.24658203125, 415.550689697265625, 0, 0, 0, 0, 1, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+61, 467147, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2176.401123046875, -2809.501708984375, 414.765777587890625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+62, 467125, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2181.345458984375, -2807.56591796875, 414.409576416015625, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+63, 467124, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2189.482666015625, -2798.760498046875, 414.58599853515625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+64, 252245, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1935.5989990234375, -2682.71875, 360.488616943359375, 3.931607961654663085, 0, 0, -0.92299365997314453, 0.384815186262130737, 7200, 255, 1, 59570), -- Instance Portal (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+65, 449751, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1889.132080078125, -3677.3740234375, 321.547393798828125, 1.719147920608520507, 0, 0, 0.757564544677734375, 0.652760267257690429, 7200, 255, 1, 59570), -- Gate (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+66, 467126, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2178.866455078125, -2800.913330078125, 414.422027587890625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+67, 446181, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2180.4287109375, -2855.10693359375, 415.801055908203125, 1.596853137016296386, 0, 0, 0.716259002685546875, 0.697834551334381103, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+68, 505620, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1556.69384765625, -2745.087890625, 335.4949951171875, 0, 0, 0, 0, 1, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+69, 467123, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2177.53125, -2796.850830078125, 415.23101806640625, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+70, 446180, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2182.61669921875, -2853.029052734375, 415.7889404296875, 3.155945539474487304, 0, 0, -0.99997425079345703, 0.007176239509135484, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+71, 467122, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2189.267333984375, -2836.55029296875, 416.38800048828125, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+72, 446183, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2191.200927734375, -2849.893798828125, 416.359344482421875, 1.694466829299926757, 0, 0, 0.749451637268066406, 0.66205906867980957, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+73, 467133, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2225.310791015625, -2727.510498046875, 427.230560302734375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+74, 446182, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2192.6591796875, -2848.46142578125, 416.380645751953125, 3.183935880661010742, 0, 0, -0.99977588653564453, 0.021169962361454963, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+75, 446177, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2195.72216796875, -2872.779296875, 410.66156005859375, 0.471128672361373901, 0, 0, 0.233391761779785156, 0.972382783889770507, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+76, 467135, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2189.51904296875, -2800.94970703125, 414.415557861328125, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+77, 446176, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2198.355712890625, -2873.758056640625, 410.66156005859375, 2.164099931716918945, 0, 0, 0.882922172546386718, 0.469519376754760742, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+78, 467134, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2193.239501953125, -2811.328125, 415.115692138671875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+79, 446179, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2182.593505859375, -2850.351318359375, 415.7889404296875, 3.155945539474487304, 0, 0, -0.99997425079345703, 0.007176239509135484, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+80, 467129, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2178.88720703125, -2798.75341796875, 414.665863037109375, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+81, 446178, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 2180.69384765625, -2848.21875, 415.7889404296875, 4.721118450164794921, 0, 0, -0.70401382446289062, 0.710186243057250976, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+82, 507783, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1561.4254150390625, -2674.734375, 382.900665283203125, 5.498618602752685546, 0, 0, -0.38229942321777343, 0.924038469791412353, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+83, 503552, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1648.8802490234375, -2860.779541015625, 361.916412353515625, 0, 0, 0, 0, 1, 7200, 255, 0, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+84, 465030, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1532.5850830078125, -2646.701416015625, 377.76995849609375, 5.451939582824707031, 0, 0, -0.40375995635986328, 0.914864957332611083, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+85, 508146, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1689.5416259765625, -2536.888916015625, 360.221710205078125, 0, 0, 0, 0, 1, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+86, 528436, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1603.59033203125, -2569.817626953125, 356.321929931640625, 5.5065155029296875, 0, 0, -0.3786478042602539, 0.925540864467620849, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+87, 446229, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1591.767822265625, -2534.42041015625, 350.236968994140625, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+88, 505397, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1584.064208984375, -2564.930419921875, 355.941314697265625, 4.889959335327148437, 0, 0, -0.64162349700927734, 0.76701974868774414, 7200, 255, 1, 59570), -- Cooking Fire (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+89, 446211, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1578.2568359375, -2565.21142578125, 352.514190673828125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 59570), -- Booth (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+90, 465705, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1582.32568359375, -2551.603271484375, 349.779205322265625, 4.889959335327148437, 0, 0, -0.64162349700927734, 0.76701974868774414, 7200, 255, 1, 59570), -- Cooking Fire (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+91, 446225, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1585.593017578125, -2532.410888671875, 350.19122314453125, 0.078538097441196441, 0, 0, 0.039258956909179687, 0.999229073524475097, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+92, 446227, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1582.3682861328125, -2541.643310546875, 349.536834716796875, 2.652894020080566406, 0, 0, 0.970294952392578125, 0.241925001144409179, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+93, 446226, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1587.8897705078125, -2534.707763671875, 350.191162109375, 1.317722797393798828, 0, 0, 0.612216949462890625, 0.790689826011657714, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+94, 446232, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1571.7706298828125, -2565.127685546875, 352.516876220703125, 0, 0, 0, 0, 1, 7200, 255, 1, 59570), -- Booth (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+95, 446209, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1580.611572265625, -2543.626708984375, 349.536834716796875, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+96, 446217, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1578.972900390625, -2545.30810546875, 349.5386962890625, 2.373644113540649414, 0, 0, 0.927183151245117187, 0.37460830807685852, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+97, 446231, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1568.076904296875, -2564.072021484375, 352.524322509765625, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 7200, 255, 1, 59570), -- Booth (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+98, 446224, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1578.7415771484375, -2538.12158203125, 349.536865234375, 5.026547431945800781, 0, 0, -0.58778572082519531, 0.809016644954681396, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+99, 459313, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1575.627197265625, -2551.75146484375, 349.498748779296875, 3.946045398712158203, 0, 0, -0.92019176483154296, 0.391467899084091186, 7200, 255, 1, 59570), -- Stool (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+100, 459312, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1574.6529541015625, -2550.788330078125, 349.498748779296875, 3.92149972915649414, 0, 0, -0.9249267578125, 0.380145370960235595, 7200, 255, 1, 59570), -- Stool (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+101, 446221, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1576.955810546875, -2539.77197265625, 349.53680419921875, 5.497786521911621093, 0, 0, -0.38268375396728515, 0.923879444599151611, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+102, 459314, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1572.859130859375, -2548.954833984375, 349.498748779296875, 3.926935672760009765, 0, 0, -0.9238901138305664, 0.382657855749130249, 7200, 255, 1, 59570), -- Stool (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+103, 446220, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1577.2694091796875, -2546.775390625, 349.540283203125, 1.893678903579711914, 0, 0, 0.811573028564453125, 0.584250986576080322, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+104, 446218, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1585.914794921875, -2528.68896484375, 350.225494384765625, 5.12254190444946289, 0, 0, -0.54829311370849609, 0.83628624677658081, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+105, 446214, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1575.3690185546875, -2541.389404296875, 349.538421630859375, 5.497786521911621093, 0, 0, -0.38268375396728515, 0.923879444599151611, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+106, 446210, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1563.7535400390625, -2559.533203125, 352.533416748046875, 5.497786521911621093, 0, 0, -0.38268375396728515, 0.923879444599151611, 7200, 255, 1, 59570), -- Booth (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+107, 459315, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1571.9171142578125, -2548.018310546875, 349.498748779296875, 3.928936958312988281, 0, 0, -0.92350673675537109, 0.383582204580307006, 7200, 255, 1, 59570), -- Stool (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+108, 446219, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1573.869140625, -2543.013427734375, 349.5880126953125, 5.663594245910644531, 0, 0, -0.30486392974853515, 0.952395915985107421, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+109, 528436, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1549.0555419921875, -2745.151123046875, 335.488677978515625, 6.280925273895263671, 0, 0, -0.0011301040649414, 0.99999934434890747, 7200, 255, 1, 59570), -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+110, 446230, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1555.900146484375, -2551.618896484375, 352.5333251953125, 5.497786521911621093, 0, 0, -0.38268375396728515, 0.923879444599151611, 7200, 255, 1, 59570), -- Booth (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+111, 446213, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1560.3809814453125, -2556.0556640625, 352.53338623046875, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 7200, 255, 1, 59570), -- Booth (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+112, 446212, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1565.0731201171875, -2538.189453125, 350.2476806640625, 0.776669740676879882, 0, 0, 0.378647804260253906, 0.925540864467620849, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+113, 446208, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1571.1346435546875, -2531.95654296875, 350.26861572265625, 4.40695810317993164, 0, 0, -0.80644416809082031, 0.59131026268005371, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+114, 446216, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1571.25341796875, -2536.64404296875, 350.191314697265625, 2.417279243469238281, 0, 0, 0.9351348876953125, 0.354291886091232299, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+115, 446207, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1569.1956787109375, -2538.690673828125, 350.191314697265625, 2.068211555480957031, 0, 0, 0.859405517578125, 0.51129460334777832, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+116, 446215, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1560.238037109375, -2483.83203125, 340.685791015625, 5.497786521911621093, 0, 0, -0.38268375396728515, 0.923879444599151611, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+117, 446223, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1564.2811279296875, -2487.952392578125, 340.6611328125, 2.583080768585205078, 0, 0, 0.961260795593261718, 0.275640487670898437, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+118, 446222, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1518.1845703125, -2534.713134765625, 337.727874755859375, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+119, 446228, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1513.9564208984375, -2530.37451171875, 337.770355224609375, 5.218533515930175781, 0, 0, -0.5075387954711914, 0.861628890037536621, 7200, 255, 1, 59570), -- Chair (Area: The Waterworks - Difficulty: Normal) CreateObject1
(@OGUID+120, 489974, 2773, 15452, 15710, '1,2,23,8,205', '0', 0, 1513.16845703125, -2754.45654296875, 278.761138916015625, 6.150043964385986328, 0, 0, -0.06652164459228515, 0.997784972190856933, 7200, 255, 1, 59570); -- -Unknown- (Area: The Waterworks - Difficulty: Normal) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+120;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+2, 0, 0, 0.450098305940628051, 0.892979025840759277, 0, 0), -- Gate
(@OGUID+6, 0, 0, -0.00000849564639793, 1, 0, 0), -- -Unknown-
(@OGUID+9, 0, 0, -0.00000849564639793, 1, 0, 0), -- Chair
(@OGUID+12, 0, 0, -0.00000849564639793, 1, 0, 0), -- Chair
(@OGUID+14, 0, 0, 0.707107901573181152, 0.707105636596679687, 0, 0), -- -Unknown-
(@OGUID+15, 0, 0, -0.00000849564639793, 1, 0, 0), -- Chair
(@OGUID+16, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+17, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- -Unknown-
(@OGUID+18, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+24, 0, 0, -0.38671103119850158, 0.922200918197631835, 0, 0), -- Chair
(@OGUID+26, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+28, 0, 0, -0.38671103119850158, 0.922200918197631835, 0, 0), -- Chair
(@OGUID+30, 0, 0, -0.38671103119850158, 0.922200918197631835, 0, 0), -- Chair
(@OGUID+33, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+35, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+36, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+38, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+65, 0, 0, 0.757564961910247802, 0.652759790420532226, 0, 0), -- Gate
(@OGUID+67, 0, 0, -0.70401471853256225, 0.710185348987579345, 0, 0), -- Chair
(@OGUID+68, 0, 0, 0.000000325841369885, 1, 0, 0), -- -Unknown-
(@OGUID+70, 0, 0, -0.70401471853256225, 0.710185348987579345, 0, 0), -- Chair
(@OGUID+72, 0, 0, -0.70401471853256225, 0.710185348987579345, 0, 0), -- Chair
(@OGUID+74, 0, 0, -0.70401471853256225, 0.710185348987579345, 0, 0), -- Chair
(@OGUID+75, 0, 0, -0.70401471853256225, 0.710185348987579345, 0, 0), -- Chair
(@OGUID+77, 0, 0, -0.70401471853256225, 0.710185348987579345, 0, 0), -- Chair
(@OGUID+79, 0, 0, -0.70401471853256225, 0.710185348987579345, 0, 0), -- Chair
(@OGUID+81, 0, 0, -0.70401471853256225, 0.710185348987579345, 0, 0), -- Chair
(@OGUID+87, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+88, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Cooking Fire
(@OGUID+89, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Booth
(@OGUID+90, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Cooking Fire
(@OGUID+91, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+92, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+93, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+94, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Booth
(@OGUID+95, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+96, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+97, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Booth
(@OGUID+98, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+99, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Stool
(@OGUID+100, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Stool
(@OGUID+101, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+102, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Stool
(@OGUID+103, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+104, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+105, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+106, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Booth
(@OGUID+107, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Stool
(@OGUID+108, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+110, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Booth
(@OGUID+111, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Booth
(@OGUID+112, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+113, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+114, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+115, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+116, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+117, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+118, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+119, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Chair
(@OGUID+120, 0, 0, 0, 1, 569, 0); -- -Unknown-

-- AreaTrigger
DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (37775,37858,37911,38022));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(37775, 0, 0, 59570),
(37858, 0, 0, 59570),
(37911, 0, 0, 59570),
(38022, 0, 0, 59570);

DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATSPAWNID+0 AND @ATSPAWNID+81;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWNID+0, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2036.8228759765625, -2701.411376953125, 376.76470947265625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+1, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2017.73095703125, -2741.9931640625, 372.044586181640625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+2, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1974.876708984375, -2889.74658203125, 370.27532958984375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+3, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1978.32470703125, -2783.880126953125, 359.885894775390625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+4, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1996.8489990234375, -2763.90283203125, 365.671875, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+5, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1982.4635009765625, -2778.84375, 361.08526611328125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+6, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1967.8785400390625, -2843.486083984375, 365.141998291015625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+7, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1980.689208984375, -2790.95654296875, 359.783782958984375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+8, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1974.59375, -2810.6494140625, 359.596832275390625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+9, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1999.5208740234375, -2771.654541015625, 365.346954345703125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+10, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1971.9410400390625, -2796.95654296875, 358.326995849609375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+11, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1966.904541015625, -2930.072998046875, 370.27532958984375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+12, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2043.967041015625, -2726.86279296875, 378.857818603515625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+13, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1968.3836669921875, -2804.4375, 358.615753173828125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+14, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1974.0572509765625, -2856.1806640625, 367.074676513671875, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+15, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1985.1353759765625, -2696.6962890625, 375.417144775390625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+16, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1975.09033203125, -2832.854248046875, 362.60198974609375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+17, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2029.296875, -2731.770751953125, 375.274505615234375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+18, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2012.1146240234375, -2747.3125, 370.5841064453125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+19, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1977.407958984375, -2795.611083984375, 358.92449951171875, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+20, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1973.9271240234375, -2788.87158203125, 358.744049072265625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+21, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1952.4774169921875, -2933.9150390625, 370.388031005859375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+22, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1974.8211669921875, -2915.416748046875, 370.27532958984375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+23, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2023.7430419921875, -2736.1650390625, 373.66461181640625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+24, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1987.420166015625, -2773.803955078125, 362.479827880859375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+25, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1967.7447509765625, -2834.9375, 363.411041259765625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+26, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2040.7864990234375, -2719.51904296875, 378.27874755859375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+27, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2044.5538330078125, -2704.16845703125, 377.245269775390625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+28, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1967.79345703125, -2827.979248046875, 361.976593017578125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+29, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2014.7586669921875, -2753.81591796875, 370.383453369140625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+30, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2007.157958984375, -2752.65625, 368.864776611328125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+31, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1959.40625, -2928.373291015625, 370.2852783203125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+32, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1967.015625, -2860.479248046875, 368.26214599609375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+33, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1975.435791015625, -2803.548583984375, 358.958892822265625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+34, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1968.670166015625, -2819.260498046875, 360.800628662109375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+35, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2004.2447509765625, -2765.154541015625, 367.076324462890625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+36, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2021.1771240234375, -2748.765625, 372.27142333984375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+37, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2039.4583740234375, -2696.098876953125, 376.90240478515625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+38, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2012.5677490234375, -2692.927001953125, 376.424835205078125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+39, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2002.876708984375, -2692.298583984375, 376.424835205078125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+40, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2002.1475830078125, -2758.5712890625, 367.33160400390625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+41, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1973.967041015625, -2881.154541015625, 370.27532958984375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+42, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2031.2379150390625, -2697.614501953125, 376.537933349609375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+43, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2044.623291015625, -2712.029541015625, 378.034088134765625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+44, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1973.7708740234375, -2899.5400390625, 370.27532958984375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+45, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2032.3177490234375, -2692.692626953125, 376.618560791015625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+46, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2035.9375, -2726.517333984375, 376.975677490234375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+47, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1984.670166015625, -2785.729248046875, 360.92108154296875, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+48, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1967.904541015625, -2852.116455078125, 366.6163330078125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+49, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2032.859375, -2738.338623046875, 375.787261962890625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+50, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1974.9114990234375, -2825.685791015625, 361.265869140625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+51, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1989.5191650390625, -2692.944580078125, 376.19866943359375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+52, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1992.3853759765625, -2768.401123046875, 364.088836669921875, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+53, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1953.3836669921875, -2942.921875, 370.27532958984375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+54, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1966.8194580078125, -2886.32470703125, 370.275848388671875, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+55, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2047.5728759765625, -2720.09375, 379.68365478515625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+56, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2026.7291259765625, -2743.213623046875, 374.00885009765625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+57, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2010.1285400390625, -2759.66845703125, 368.91351318359375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+58, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2007.9566650390625, -2695.119873046875, 376.42486572265625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+59, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1973.6614990234375, -2907.4375, 370.27532958984375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+60, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1966.9722900390625, -2903.866455078125, 370.284698486328125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+61, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1973.68408203125, -2863.989501953125, 368.509674072265625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+62, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1973.2864990234375, -2872.420166015625, 369.724578857421875, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+63, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1964.9114990234375, -2921.90966796875, 370.292388916015625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+64, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1968.8541259765625, -2811.87158203125, 359.65753173828125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+65, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1967.048583984375, -2914.279541015625, 370.29034423828125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+66, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1975.2066650390625, -2817.835205078125, 360.368927001953125, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+67, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1972.826416015625, -2922.842041015625, 370.27532958984375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+68, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1974.6805419921875, -2848.163330078125, 365.566314697265625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+69, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1966.7447509765625, -2868.3994140625, 369.666656494140625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+70, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1966.9166259765625, -2895.020751953125, 370.27532958984375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+71, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1997.064208984375, -2695.057373046875, 376.42486572265625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+72, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1982.7100830078125, -2691.595458984375, 375.256561279296875, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+73, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2024.80908203125, -2693.885498046875, 376.4586181640625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+74, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1974.595458984375, -2840.092041015625, 364.103515625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+75, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1994.8316650390625, -2776.342041015625, 363.71295166015625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+76, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2039.12158203125, -2709.27783203125, 377.383270263671875, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+77, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1959.9947509765625, -2935.520751953125, 370.27532958984375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+78, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2018.5399169921875, -2695.060791015625, 376.42486572265625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+79, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 2038.4149169921875, -2732.25341796875, 377.33636474609375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+80, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1967.015625, -2877.986083984375, 370.28216552734375, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570), -- (Area: The Waterworks - Difficulty: Normal)
(@ATSPAWNID+81, @ATPROPERTIESID+0, 1, 2773, '1,2,23,8,205', 1989.3524169921875, -2780.904541015625, 362.171051025390625, 0, 0, '0', 0, 'Operation: Floodgate - Mine Field', 59570); -- (Area: The Waterworks - Difficulty: Normal)

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=1 AND `Id` = @ATPROPERTIESID+0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(@ATPROPERTIESID+0, 1, 37775, 0, 0, 0, 0, 0, 0, -1, 0, 0, 473415, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 59570); -- SpellForVisuals: 473415 (Mine Field)

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (35788,35852,35970));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(35788, 0, 37858, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 12000, 30.03076553344726562, 1, 0.75, 3.75, 3, 0.75, 3.75, 3, 0, 0, 59570), -- Spell: 474336 (Shreddation)
(35852, 0, 37911, 0, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 8, 8, 0, 0, 0, 0, 0, 0, 59570), -- Spell: 1213693 ([DNT] Zeppelin Targeting Trigger)
(35970, 0, 38022, 0, 0, 0, 0, 0, 0, -1, 0, 652, NULL, 0, 0, 1, 25, 25, 1, 25, 25, 1, 0, 0, 59570); -- Spell: 1215088 ([DNT] Electrified Water)

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (226404 /*226404 (Geezle Gigazap) - Bot AI Follow Advert*/, 237366 /*237366 ([DNT] Mech Boss Stalker) - [DNT] Mech Boss Stalker*/, 229069 /*229069 (Mechadrone Sniper)*/, 230564 /*230564 (Weapons Stockpile)*/, 235848 /*235848 (Electrified Water)*/, 234991 /*234991 (Zeppelin) - Ride Vehicle Hardcoded*/, 230748 /*230748 (Darkfuse Bloodwarper) - Invisibility and Stealth Detection*/, 226398 /*226398 (Big M.O.M.M.A.) - Mobilize Mechadrones, Mobilize Mechadrones, Broadcast Orders, Bot AI Follow Advert, Mobilize Mechadrones*/, 237442 /*237442 ([DNT] Transmitter) - [DNT] Transmitter, [DNT] Transmitter Communication*/, 234481 /*234481 (Mine Field)*/, 234992 /*234992 (Zeppelin Stalker)*/, 231312 /*231312 (Venture Co. Electrician) - Mod Scale 95-105%*/, 231380 /*231380 (Undercrawler) - Mod Scale 95-105%*/, 230740 /*230740 (Shreddinator 3000) - Invisibility and Stealth Detection*/, 222751 /*222751 (Azure Flickerfly)*/, 229212 /*229212 (Darkfuse Demolitionist) - Mod Scale 95-105%, Locked and Loaded, [DNT] Darkfuse Demolitionist Cosmetic, Advert*/, 238023 /*238023 (Helper) - Helper*/, 231642 /*231642 (Waterworks Opportunist) - Mod Scale 95-105%*/, 236982 /*236982 (Darkfuse Soldier) - Mod Scale 95-105%*/, 226402 /*226402 (Bront) - Bot AI Follow Advert, [DNT] Hold Crate*/, 220173 /*220173 (Lightdarter)*/, 228424 /*228424 (Darkfuse Mechadrone) - Advert*/, 226403 /*226403 (Keeza Quickfuse) - [DNT] Gun, [DNT] Jetpack Flames, Bot AI Follow Advert*/, 229686 /*229686 (Venture Co. Surveyor) - Mod Scale 95-105%*/, 231424 /*231424 (Silva Stratospark) - Ride Vehicle Hardcoded*/, 231496 /*231496 (Venture Co. Diver) - Mod Scale 95-105%*/, 228144 /*228144 (Darkfuse Soldier) - Mod Scale 95-105%, Blood-Infused Strikes*/, 227145 /*227145 (Waterworks Crocolisk) - Mod Scale 95-105%*/, 235065 /*235065 (Targeting Stalker) - [DNT] Zeppelin Targeting Trigger*/, 231176 /*231176 (Scaffolding) - Tower, Advert*/, 235862 /*235862 (Venture Co. Electrician)*/, 229251 /*229251 (Venture Co. Architect) - Mod Scale 95-105%, Dual Wield, Invisibility and Stealth Detection*/, 232228 /*232228 (Waterworks Bottomfeeder) - Mod Scale 95-105%, Immunity*/, 229252 /*229252 (Darkfuse Hyena) - Mod Scale 95-105%, Cosmetic - Sleep Zzz (With Aggro Change) - Head*/, 231385 /*231385 (Darkfuse Inspector) - Mod Scale 95-105%*/, 231014 /*231014 (Loaderbot) - Mod Scale 95-105%*/, 230927 /*230927 (Darkfuse Shredder Pilot) - Ride Vehicle Hardcoded, Mod Scale 95-105%*/, 231497 /*231497 (Bombshell Crab) - Crabsplosion*/, 231223 /*231223 (Disturbed Kelp) - Mod Scale 95-105%*/, 229250 /*229250 (Venture Co. Contractor) - Mod Scale 95-105%*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(226404, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '423679'), -- 226404 (Geezle Gigazap) - Bot AI Follow Advert
(237366, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1217612'), -- 237366 ([DNT] Mech Boss Stalker) - [DNT] Mech Boss Stalker
(229069, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 229069 (Mechadrone Sniper)
(230564, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 230564 (Weapons Stockpile)
(235848, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 235848 (Electrified Water)
(234991, 0, 0, 0, 3, 0, 1, 0, 0, 31762, 0, 0, 0, ''), -- 234991 (Zeppelin) 
(230748, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- 230748 (Darkfuse Bloodwarper) - Invisibility and Stealth Detection
(237442, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1217701 1217713'), -- 237442 ([DNT] Transmitter) - [DNT] Transmitter, [DNT] Transmitter Communication
(234481, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 234481 (Mine Field)
(234992, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 234992 (Zeppelin Stalker)
(231312, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, '471891'), -- 231312 (Venture Co. Electrician) - Mod Scale 95-105%
(231380, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- 231380 (Undercrawler) - Mod Scale 95-105%
(230740, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- 230740 (Shreddinator 3000) - Invisibility and Stealth Detection
(222751, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 222751 (Azure Flickerfly)
(229212, 0, 0, 0, 0, 0, 2, 0, 0, 14559, 0, 0, 0, '471891 461805 468599 1217843'), -- 229212 (Darkfuse Demolitionist) - Mod Scale 95-105%, Locked and Loaded, [DNT] Darkfuse Demolitionist Cosmetic, Advert
(238023, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '472701'), -- 238023 (Helper) - Helper
(231642, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '471891'), -- 231642 (Waterworks Opportunist) - Mod Scale 95-105%
(236982, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- 236982 (Darkfuse Soldier) - Mod Scale 95-105%
(220173, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 220173 (Lightdarter)
(228424, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '1217843'), -- 228424 (Darkfuse Mechadrone) - Advert
(226403, 0, 0, 0, 2, 0, 1, 0, 0, 30768, 0, 0, 4, '462284 462000'), -- 226403 (Keeza Quickfuse) - [DNT] Gun, [DNT] Jetpack Flames
(229686, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, '471891'), -- 229686 (Venture Co. Surveyor) - Mod Scale 95-105%
(231424, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 231424 (Silva Stratospark)
(231496, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- 231496 (Venture Co. Diver) - Mod Scale 95-105%
(228144, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 462735'), -- 228144 (Darkfuse Soldier) - Mod Scale 95-105%, Blood-Infused Strikes
(227145, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- 227145 (Waterworks Crocolisk) - Mod Scale 95-105%
(235065, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1213693'), -- 235065 (Targeting Stalker) - [DNT] Zeppelin Targeting Trigger
(231176, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1213783 1217843'), -- 231176 (Scaffolding) - Tower, Advert
(235862, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- 235862 (Venture Co. Electrician)
(229251, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 42459 18950'), -- 229251 (Venture Co. Architect) - Mod Scale 95-105%, Dual Wield, Invisibility and Stealth Detection
(232228, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891 1224583'), -- 232228 (Waterworks Bottomfeeder) - Mod Scale 95-105%, Immunity
(229252, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- 229252 (Darkfuse Hyena) - Mod Scale 95-105%
(231385, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'), -- 231385 (Darkfuse Inspector) - Mod Scale 95-105%
(231014, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- 231014 (Loaderbot) - Mod Scale 95-105%
(230927, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- 230927 (Darkfuse Shredder Pilot) - Mod Scale 95-105%
(231497, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '468679'), -- 231497 (Bombshell Crab) - Crabsplosion
(231223, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '471891'), -- 231223 (Disturbed Kelp) - Mod Scale 95-105%
(229250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '471891'); -- 229250 (Venture Co. Contractor) - Mod Scale 95-105%

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (508146 /*Cylinder Collision (7.5 Scale, No Camera Collision)*/, 507960 /*Gate*/, 507783 /*Goblin Glider Crate*/, 528436 /*[DNT] Collision*/, 503552 /*Fire Barrier*/, 505620 /*Dam Gate*/, 465030 /*Weapons Stockpile*/, 502538 /*Door*/, 502539 /*Door*/, 489974 /*Grappling Hook*/, 507968 /*Weapons Stockpile*/, 502540 /*Door*/, 507972 /*Weapons Stockpile*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(508146, 0, 0x800000, 0, 0), -- Cylinder Collision (7.5 Scale, No Camera Collision)
(507960, 0, 0x30, 0, 0), -- Gate
(507783, 0, 0x2000, 0, 0), -- Goblin Glider Crate
(528436, 0, 0x4800000, 0, 0), -- [DNT] Collision
(503552, 0, 0x10, 0, 0), -- Fire Barrier
(505620, 0, 0x30, 0, 0), -- Dam Gate
(465030, 0, 0x2000, 0, 0), -- Weapons Stockpile
(502538, 0, 0x32, 0, 0), -- Door
(502539, 0, 0x32, 0, 0), -- Door
(489974, 0, 0x0, 569, 0), -- Grappling Hook
(507968, 0, 0x2010, 0, 0), -- Weapons Stockpile
(502540, 0, 0x32, 0, 0), -- Door
(507972, 0, 0x2010, 0, 0); -- Weapons Stockpile

-- Template
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=231325; -- Darkfuse Jumpstarter
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=231312; -- Venture Co. Electrician
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=236982; -- Darkfuse Soldier
UPDATE `creature_template` SET `faction`=16, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=3000, `unit_flags`=0x340 WHERE `entry`=226404; -- Geezle Gigazap
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=232228; -- Waterworks Bottomfeeder
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=231223; -- Disturbed Kelp
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x40000001, `flags_extra` = 128 WHERE `entry`=237442; -- [DNT] Transmitter
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x40000001, `flags_extra` = 128 WHERE `entry`=237366; -- [DNT] Mech Boss Stalker
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000000, `unit_flags3`=0x41008001, `flags_extra` = 128 WHERE `entry`=238023; -- Helper
UPDATE `creature_template` SET `faction`=16, `speed_walk`=5.599999904632568359, `speed_run`=2, `BaseAttackTime`=1500, `unit_flags`=0x2000340, `unit_flags2`=0x4000800, `unit_flags3`=0x1008000 WHERE `entry`=231424; -- Silva Stratospark
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000000, `unit_flags3`=0x41008001, `flags_extra` = 128 WHERE `entry`=237350; -- Path Helper
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=231385; -- Darkfuse Inspector
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x40000001 WHERE `entry`=230564; -- Weapons Stockpile
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=1.428571462631225585, `BaseAttackTime`=3000, `unit_flags`=0x40, `VehicleId`=8710 WHERE `entry`=226398; -- Big M.O.M.M.A.
UPDATE `creature_template` SET `faction`=634, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x40080000, `VehicleId`=8706 WHERE `entry`=231176; -- Scaffolding
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=222614; -- Azure Flickerfly
UPDATE `creature_template` SET `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=234991; -- Zeppelin
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=230748; -- Darkfuse Bloodwarper
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x40000001 WHERE `entry`=234481; -- Mine Field
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x1, `VehicleId`=8818, `flags_extra` = 128 WHERE `entry`=234992; -- Zeppelin Stalker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=229212; -- Darkfuse Demolitionist
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x40000001, `flags_extra` = 128 WHERE `entry`=235848; -- Electrified Water
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `VehicleId`=8689 WHERE `entry`=230740; -- Shreddinator 3000
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=229251; -- Venture Co. Architect
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=222751; -- Azure Flickerfly
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=1.428571462631225585, `BaseAttackTime`=3000, `unit_flags`=0x40 WHERE `entry`=226402; -- Bront
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=233019; -- Renzik "The Shiv"
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=1.428571462631225585, `BaseAttackTime`=3000, `unit_flags`=0x40, `unit_flags3`=0x40000000 WHERE `entry`=226403; -- Keeza Quickfuse
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=229686; -- Venture Co. Surveyor
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=231496; -- Venture Co. Diver
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=228144; -- Darkfuse Soldier
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=220173; -- Lightdarter
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=229069; -- Mechadrone Sniper
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=229250; -- Venture Co. Contractor
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x340, `unit_flags2`=0x800, `unit_flags3`=0x80000000 WHERE `entry`=235862; -- Venture Co. Electrician
UPDATE `creature_template` SET `faction`=16, `speed_walk`=1.20000004768371582, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=229252; -- Darkfuse Hyena
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=0x2000000, `unit_flags2`=0x800, `unit_flags3`=0x1, `flags_extra` = 128 WHERE `entry`=235065; -- Targeting Stalker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=227145; -- Waterworks Crocolisk
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800, `unit_flags3`=0xC1000000 WHERE `entry`=231642; -- Waterworks Opportunist
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=222876; -- Meek Bloodlasher
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x400000 WHERE `entry`=231497; -- Bombshell Crab
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800 WHERE `entry`=230927; -- Darkfuse Shredder Pilot
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=231380; -- Undercrawler
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.799999952316284179, `speed_run`=2, `BaseAttackTime`=2000, `unit_flags`=0x40 WHERE `entry`=228424; -- Darkfuse Mechadrone
UPDATE `creature_template` SET `faction`=16, `speed_run`=0.992062866687774658, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=231014; -- Loaderbot

DELETE FROM `gameobject_template` WHERE `entry` IN (508146 /*Cylinder Collision (7.5 Scale, No Camera Collision)*/, 507960 /*Gate*/, 502540 /*Door*/, 489974 /*Grappling Hook*/, 507783 /*Goblin Glider Crate*/, 502538 /*Door*/, 465030 /*Weapons Stockpile*/, 505620 /*Dam Gate*/, 528436 /*[DNT] Collision*/, 507968 /*Weapons Stockpile*/, 502539 /*Door*/, 503552 /*Fire Barrier*/, 507972 /*Weapons Stockpile*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(508146, 5, 19131, 'Cylinder Collision (7.5 Scale, No Camera Collision)', '', '', '', 7.5, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Cylinder Collision (7.5 Scale, No Camera Collision)
(507960, 0, 97769, 'Gate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Gate
(502540, 0, 84815, 'Door', '', '', '', 1.051020741462707519, 0, 920, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(489974, 10, 77771, 'Grappling Hook', 'questinteract', '', '', 2, 0, 0, 0, 1000, 0, 0, 0, 0, 0, 0, 470109, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Grappling Hook
(507783, 10, 100571, 'Goblin Glider Crate', 'taxi', '', '', 7, 3963, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1217114, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 59570), -- Goblin Glider Crate
(502538, 0, 84815, 'Door', '', '', '', 1.034092187881469726, 0, 920, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(465030, 10, 100462, 'Weapons Stockpile', 'questinteract', '', '', 3, 3968, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 464293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6909, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 59570), -- Weapons Stockpile
(505620, 0, 100102, 'Dam Gate', '', '', '', 0.999999284744262695, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Dam Gate
(528436, 1, 7735, '[DNT] Collision', '', '', '', 15.19999980926513671, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- [DNT] Collision
(507968, 10, 100462, 'Weapons Stockpile', 'questinteract', '', '', 3, 3968, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 464293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6909, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 59570), -- Weapons Stockpile
(502539, 0, 85281, 'Door', '', '', '', 1.583146095275878906, 0, 920, 3000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Door
(503552, 0, 75069, 'Fire Barrier', '', '', '', 0.75, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Fire Barrier
(507972, 10, 100462, 'Weapons Stockpile', 'questinteract', '', '', 3, 3968, 0, 0, 3000, 0, 0, 0, 0, 0, 0, 464293, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6909, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 59570); -- Weapons Stockpile

-- Difficulty
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=226404 AND `DifficultyID`=0); -- 226404 (Geezle Gigazap) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x20000100, `VerifiedBuild`=59570 WHERE (`Entry`=237366 AND `DifficultyID`=0); -- 237366 ([DNT] Mech Boss Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x20000100, `VerifiedBuild`=59570 WHERE (`Entry`=230564 AND `DifficultyID`=0); -- 230564 (Weapons Stockpile) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x20000100, `VerifiedBuild`=59570 WHERE (`Entry`=235848 AND `DifficultyID`=0); -- 235848 (Electrified Water) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x20000100, `VerifiedBuild`=59570 WHERE (`Entry`=234991 AND `DifficultyID`=0); -- 234991 (Zeppelin) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=230748 AND `DifficultyID`=0); -- 230748 (Darkfuse Bloodwarper) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=226398 AND `DifficultyID`=0); -- 226398 (Big M.O.M.M.A.) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x20000100, `VerifiedBuild`=59570 WHERE (`Entry`=237442 AND `DifficultyID`=0); -- 237442 ([DNT] Transmitter) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x20000100, `VerifiedBuild`=59570 WHERE (`Entry`=234481 AND `DifficultyID`=0); -- 234481 (Mine Field) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x20000000, `VerifiedBuild`=59570 WHERE (`Entry`=234992 AND `DifficultyID`=0); -- 234992 (Zeppelin Stalker) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=231312 AND `DifficultyID`=0); -- 231312 (Venture Co. Electrician) - CanSwim
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=59570 WHERE (`DifficultyID`=0 AND `Entry` IN (210933,222875,210932)) OR (`DifficultyID`=1 AND `Entry` IN (210930,211151,211152,210931,211149,211150,211137));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=231380 AND `DifficultyID`=0); -- 231380 (Undercrawler) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=230740 AND `DifficultyID`=0); -- 230740 (Shreddinator 3000) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=0x30000000, `VerifiedBuild`=59570 WHERE (`Entry`=222751 AND `DifficultyID`=0); -- 222751 (Azure Flickerfly) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=229212 AND `DifficultyID`=0); -- 229212 (Darkfuse Demolitionist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x30000100, `VerifiedBuild`=59570 WHERE (`Entry`=238023 AND `DifficultyID`=0); -- 238023 (Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x30000100, `VerifiedBuild`=59570 WHERE (`Entry`=231642 AND `DifficultyID`=0); -- 231642 (Waterworks Opportunist) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x30000100, `VerifiedBuild`=59570 WHERE (`Entry`=236982 AND `DifficultyID`=0); -- 236982 (Darkfuse Soldier) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=226402 AND `DifficultyID`=0); -- 226402 (Bront) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x30000000, `VerifiedBuild`=59570 WHERE (`Entry`=220173 AND `DifficultyID`=0); -- 220173 (Lightdarter) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=228424 AND `DifficultyID`=0); -- 228424 (Darkfuse Mechadrone) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=0x30000100, `VerifiedBuild`=59570 WHERE (`Entry`=226403 AND `DifficultyID`=0); -- 226403 (Keeza Quickfuse) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=229686 AND `DifficultyID`=0); -- 229686 (Venture Co. Surveyor) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2718, `StaticFlags1`=0x20000100, `VerifiedBuild`=59570 WHERE (`Entry`=231424 AND `DifficultyID`=0); -- 231424 (Silva Stratospark) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=231496 AND `DifficultyID`=0); -- 231496 (Venture Co. Diver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=0x30000100, `VerifiedBuild`=59570 WHERE (`Entry`=237350 AND `DifficultyID`=0); -- 237350 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=228144 AND `DifficultyID`=0); -- 228144 (Darkfuse Soldier) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=227145 AND `DifficultyID`=0); -- 227145 (Waterworks Crocolisk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x20000000, `VerifiedBuild`=59570 WHERE (`Entry`=235065 AND `DifficultyID`=0); -- 235065 (Targeting Stalker) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=59570 WHERE (`Entry`=231176 AND `DifficultyID`=0); -- 231176 (Scaffolding) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=235862 AND `DifficultyID`=0); -- 235862 (Venture Co. Electrician) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2718, `StaticFlags1`=0x30000100, `VerifiedBuild`=59570 WHERE (`Entry`=229251 AND `DifficultyID`=0); -- 229251 (Venture Co. Architect) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=232228 AND `DifficultyID`=0); -- 232228 (Waterworks Bottomfeeder) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=222876 AND `DifficultyID`=0); -- 222876 (Meek Bloodlasher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=229252 AND `DifficultyID`=0); -- 229252 (Darkfuse Hyena) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=229069 AND `DifficultyID`=0); -- 229069 (Mechadrone Sniper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=231385 AND `DifficultyID`=0); -- 231385 (Darkfuse Inspector) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=231014 AND `DifficultyID`=0); -- 231014 (Loaderbot) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x30000100, `VerifiedBuild`=59570 WHERE (`Entry`=230927 AND `DifficultyID`=0); -- 230927 (Darkfuse Shredder Pilot) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=231497 AND `DifficultyID`=0); -- 231497 (Bombshell Crab) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=231223 AND `DifficultyID`=0); -- 231223 (Disturbed Kelp) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2718, `StaticFlags1`=0x10000000, `VerifiedBuild`=59570 WHERE (`Entry`=229250 AND `DifficultyID`=0); -- 229250 (Venture Co. Contractor) - CanSwim

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (231312,236982,231385,230748,229212,229251,233019,229686,231496,228144,229250,235862,230927)) OR (`ID`=3 AND `CreatureID`=229250) OR (`ID`=2 AND `CreatureID`=229250);
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(231312, 1, 0, 0, 0, 0, 0, 0, 232468, 0, 0, 59570), -- Venture Co. Electrician
(236982, 1, 226833, 0, 0, 226834, 0, 0, 0, 0, 0, 59570), -- Darkfuse Soldier
(231385, 1, 226844, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Darkfuse Inspector
(230748, 1, 232648, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Darkfuse Bloodwarper
(229212, 1, 0, 0, 0, 0, 0, 0, 136631, 0, 0, 59570), -- Darkfuse Demolitionist
(229251, 1, 227452, 0, 0, 227452, 0, 0, 228221, 0, 0, 59570), -- Venture Co. Architect
(233019, 1, 0, 0, 0, 0, 0, 0, 227293, 0, 0, 59570), -- Renzik "The Shiv"
(229686, 1, 226855, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Venture Co. Surveyor
(229250, 3, 222469, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Venture Co. Contractor
(229250, 2, 226387, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Venture Co. Contractor
(231496, 1, 155071, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Venture Co. Diver
(228144, 1, 226833, 0, 0, 226834, 0, 0, 0, 0, 0, 59570), -- Darkfuse Soldier
(229250, 1, 55350, 0, 0, 0, 0, 0, 0, 0, 0, 59570), -- Venture Co. Contractor
(235862, 1, 0, 0, 0, 0, 0, 0, 232468, 0, 0, 59570), -- Venture Co. Electrician
(230927, 1, 226385, 0, 0, 0, 0, 0, 0, 0, 0, 59570); -- Darkfuse Shredder Pilot

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=233019 AND `MenuID`=37834);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(233019, 37834, 59570); -- Renzik "The Shiv"

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 280431, 0, 0, 0, 0, 0, 0, 0, 59570); -- 233019 (Renzik "The Shiv")

DELETE FROM `gossip_menu` WHERE (`MenuID`=37834 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(37834, @NPCTEXTID+0, 59570); -- 233019 (Renzik "The Shiv")

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=37834 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(37834, 131811, 0, 0, 'Roger that!', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 59570);

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`seat_id`=0 AND `entry` IN (230740,231176,234992,226398));
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(230740, 230927, 0, 0, 'Shreddinator 3000 - Darkfuse Shredder Pilot', 8, 0), -- Shreddinator 3000 - Darkfuse Shredder Pilot
(231176, 229251, 0, 0, 'Scaffolding - Venture Co. Architect', 8, 0), -- Scaffolding - Venture Co. Architect
(234992, 234991, 0, 0, 'Zeppelin Stalker - Zeppelin', 8, 0), -- Zeppelin Stalker - Zeppelin
(226398, 231424, 0, 0, 'Big M.O.M.M.A. - Silva Stratospark', 8, 0); -- Big M.O.M.M.A. - Silva Stratospark

-- NPC Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (230740,231176,234992,226398);
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(230740, 46598, 1, 0),
(231176, 465413, 1, 0),
(234992, 46598, 1, 0),
(226398, 46598, 1, 0);

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (124181, 122517, 124182, 127501, 122475, 127502, 127503, 122098, 126963, 126962, 124178, 122082, 124211, 124177, 122887, 122753, 122867, 124689, 126200, 126383, 124729, 122755, 122085, 122881, 122754, 122097, 124731, 121293, 122215, 124734, 123036, 122080, 124735, 122083, 122888, 122752, 126613, 122084, 121297, 120779, 124732, 125461, 121696, 124724, 126964, 126961);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(124181, 0.305999994277954101, 1.5, 0, 59570),
(122517, 0.372000008821487426, 1.20000004768371582, 0, 59570),
(124182, 0.305999994277954101, 1.5, 0, 59570),
(127501, 0.108499996364116668, 1.05000007152557373, 0, 59570),
(122475, 0.305999994277954101, 1.5, 0, 59570),
(127502, 0.108499996364116668, 1.049999952316284179, 0, 59570),
(127503, 0.108499996364116668, 1.049999952316284179, 0, 59570),
(122098, 0.305999994277954101, 1.5, 0, 59570),
(126963, 3.0694732666015625, 0, 0, 59570),
(126962, 3.0694732666015625, 0, 0, 59570),
(124178, 0.305999994277954101, 1.5, 0, 59570),
(122082, 0.305999994277954101, 1.5, 0, 59570),
(124211, 0.305999994277954101, 1.5, 0, 59570),
(124177, 0.305999994277954101, 1.5, 0, 59570),
(122887, 0.305999994277954101, 1.5, 0, 59570),
(122753, 0.236000001430511474, 1.5, 0, 59570),
(122867, 2.671681642532348632, 4, 0, 59570),
(124689, 0.5, 6, 0, 59570),
(126200, 0.200000002980232238, 1, 0, 59570),
(126383, 0.372000008821487426, 1.20000004768371582, 0, 59570),
(124729, 0.305999994277954101, 1.5, 0, 59570),
(122755, 0.347222000360488891, 1.5, 0, 59570),
(122085, 0.305999994277954101, 1.5, 0, 59570),
(122881, 2.893195867538452148, 2.5, 0, 59570),
(122754, 0.698715150356292724, 1.5, 0, 59570),
(122097, 0.305999994277954101, 1.5, 0, 59570),
(124731, 0.305999994277954101, 1.5, 0, 59570),
(121293, 0.629803121089935302, 1.5, 0, 59570),
(122215, 0.310000002384185791, 0, 0, 59570),
(124734, 0.347000002861022949, 1.5, 0, 59570),
(123036, 0.305999994277954101, 1.5, 0, 59570),
(122080, 0.730333805084228515, 1.5, 0, 59570),
(124735, 0.347000002861022949, 1.5, 0, 59570),
(122083, 0.208000004291534423, 1.5, 0, 59570),
(122888, 0.305999994277954101, 1.5, 0, 59570),
(122752, 0.372000008821487426, 1.5, 0, 59570),
(126613, 0.749745070934295654, 1, 0, 59570),
(122084, 0.305999994277954101, 1.5, 0, 59570),
(121297, 0.629803121089935302, 1.5, 0, 59570),
(120779, 0.989673256874084472, 0.875, 0, 59570),
(124732, 0.305999994277954101, 1.5, 0, 59570),
(125461, 0.749745011329650878, 1, 0, 59570),
(121696, 0.713658928871154785, 0, 0, 59570),
(124724, 0.305999994277954101, 1.5, 0, 59570),
(126964, 3.0694732666015625, 0, 0, 59570),
(126961, 3.0694732666015625, 0, 0, 59570);

UPDATE `creature_model_info` SET `VerifiedBuild`=59570 WHERE `DisplayID` IN (114712, 112446, 114527, 114158, 114778, 114715, 119704, 112449, 114714, 120369, 23767, 118223, 114621, 114716, 81674, 94282, 75850, 114713, 51525, 118217, 112448, 112447);
UPDATE `creature_model_info` SET `BoundingRadius`=0.363841086626052856, `VerifiedBuild`=59570 WHERE `DisplayID` IN (114622, 114623);

-- Path for Darkfuse Demolitionist
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+128;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+128, @CGUID+128, 0, 0, 515, 0, 0),
(@CGUID+128, @CGUID+58, 2, 300, 515, 1, 11),
(@CGUID+128, @CGUID+161, 2, 60, 515, 1, 11);

SET @MOVERGUID := @CGUID+128;
SET @ENTRY := 229212;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Darkfuse Demolitionist - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1803.099, -2621.5051, 366.37354, NULL, 0),
(@PATH, 1, 1799.9618, -2624.139, 366.34204, NULL, 0),
(@PATH, 2, 1807.6094, -2618.7795, 365.49432, NULL, 0),
(@PATH, 3, 1814.0729, -2620.309, 363.08633, NULL, 0),
(@PATH, 4, 1819.7188, -2623.1736, 361.9132, NULL, 0),
(@PATH, 5, 1825.993, -2624.052, 362.2915, NULL, 0),
(@PATH, 6, 1833.2396, -2621.6077, 364.6026, NULL, 0),
(@PATH, 7, 1836.4635, -2626.9375, 364.82596, NULL, 0),
(@PATH, 8, 1838.8264, -2631.5417, 364.34756, NULL, 0),
(@PATH, 9, 1840.4236, -2637.5347, 362.12827, NULL, 0),
(@PATH, 10, 1837.8945, -2644.0566, 362.42886, NULL, 0),
(@PATH, 11, 1834.5078, -2649.0137, 364.0622, NULL, 0),
(@PATH, 12, 1837.8854, -2644.0815, 362.3529, NULL, 0),
(@PATH, 13, 1840.4236, -2637.5347, 362.12827, NULL, 0),
(@PATH, 14, 1839.9082, -2635.6016, 362.61365, NULL, 0),
(@PATH, 15, 1839.6504, -2634.6348, 363.04767, NULL, 0),
(@PATH, 16, 1839.3926, -2633.668, 363.28186, NULL, 0),
(@PATH, 17, 1838.877, -2631.7344, 364.34488, NULL, 0),
(@PATH, 18, 1837.9121, -2629.7598, 364.7748, NULL, 0),
(@PATH, 19, 1836.4635, -2626.9375, 364.82596, NULL, 0),
(@PATH, 20, 1833.2396, -2621.6077, 364.6026, NULL, 0),
(@PATH, 21, 1832.292, -2621.9277, 363.7836, NULL, 0),
(@PATH, 22, 1830.3975, -2622.5684, 363.26575, NULL, 0),
(@PATH, 23, 1829.4502, -2622.8887, 362.92273, NULL, 0),
(@PATH, 24, 1828.5029, -2623.209, 362.69992, NULL, 0),
(@PATH, 25, 1827.5557, -2623.5293, 362.5066, NULL, 0),
(@PATH, 26, 1825.993, -2624.052, 362.2915, NULL, 0),
(@PATH, 27, 1819.7188, -2623.1736, 361.9132, NULL, 0),
(@PATH, 28, 1814.0729, -2620.309, 363.08633, NULL, 0),
(@PATH, 29, 1807.6094, -2618.7795, 365.49432, NULL, 0);

UPDATE `creature` SET `position_x`=1803.099, `position_y`=-2621.5051, `position_z`=366.37354, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 2, 0, 0, 14559, 0, 0, 0, '471891 461805 468599 1217843');

-- Path for Darkfuse Demolitionist
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+120;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+120, @CGUID+120, 0, 0, 515, 0, 0),
(@CGUID+120, @CGUID+145, 5, 0, 515, 2, 5),
(@CGUID+120, @CGUID+46, 5, 330, 515, 2, 5),
(@CGUID+120, @CGUID+211, 5, 30, 515, 2, 5);

SET @MOVERGUID := @CGUID+120;
SET @ENTRY := 229212;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Darkfuse Demolitionist - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1708.467, -2652.429, 342.9029, NULL, 0),
(@PATH, 1, 1700.2622, -2652.6423, 342.89474, NULL, 0),
(@PATH, 2, 1691.5903, -2652.712, 342.89474, NULL, 8979),
(@PATH, 3, 1700.2622, -2652.6423, 342.89474, NULL, 0),
(@PATH, 4, 1708.467, -2652.429, 342.9029, NULL, 0),
(@PATH, 5, 1720.691, -2652.5452, 342.906, NULL, 6525);

UPDATE `creature` SET `position_x`=1708.467, `position_y`=-2652.429, `position_z`=342.9029, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 0, 0, 2, 0, 0, 14559, 0, 0, 0, '471891 461805 468599 1217843');

-- Path for Mechadrone Sniper
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+74;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+74, @CGUID+74, 0, 0, 515, 0, 0),
(@CGUID+74, @CGUID+190, 6, 270, 515, 0, 0),
(@CGUID+74, @CGUID+156, 6, 0, 515, 0, 0);

SET @MOVERGUID := @CGUID+74;
SET @ENTRY := 229069;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Mechadrone Sniper - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1827.8247, -2706.2656, 347.237, NULL, 0),
(@PATH, 1, 1824.9844, -2701.212, 347.2929, NULL, 0),
(@PATH, 2, 1820.7084, -2695.6301, 347.27814, NULL, 0),
(@PATH, 3, 1812.5452, -2688.4446, 347.2954, NULL, 0),
(@PATH, 4, 1806.717, -2686.7812, 347.2386, NULL, 0),
(@PATH, 5, 1796.6927, -2688.4932, 347.23697, NULL, 0),
(@PATH, 6, 1790.9166, -2698.0503, 347.23697, NULL, 0),
(@PATH, 7, 1790.3073, -2704.8872, 347.23697, NULL, 0),
(@PATH, 8, 1792.5834, -2711.5557, 347.13892, NULL, 0),
(@PATH, 9, 1803.7327, -2719.4324, 347.237, NULL, 0),
(@PATH, 10, 1807.981, -2720.3315, 347.23697, NULL, 0),
(@PATH, 11, 1814.5486, -2720.9636, 347.23697, NULL, 0),
(@PATH, 12, 1823.5851, -2718.144, 347.23697, NULL, 0),
(@PATH, 13, 1828.7517, -2710.9236, 347.237, NULL, 0),
(@PATH, 14, 1824.9844, -2701.212, 347.2929, NULL, 0),
(@PATH, 15, 1820.7084, -2695.6301, 347.27814, NULL, 0),
(@PATH, 16, 1817.1337, -2692.0227, 347.23444, NULL, 0),
(@PATH, 17, 1806.717, -2686.7812, 347.2386, NULL, 0),
(@PATH, 18, 1801.2535, -2686.7258, 347.23697, NULL, 0),
(@PATH, 19, 1793.3577, -2692.0972, 347.23624, NULL, 0),
(@PATH, 20, 1790.9166, -2698.0503, 347.23697, NULL, 0),
(@PATH, 21, 1792.5834, -2711.5557, 347.13892, NULL, 0),
(@PATH, 22, 1797.1389, -2715.8525, 347.23694, NULL, 0),
(@PATH, 23, 1803.7327, -2719.4324, 347.237, NULL, 0),
(@PATH, 24, 1814.5486, -2720.9636, 347.23697, NULL, 0),
(@PATH, 25, 1819.2726, -2720.0781, 347.23697, NULL, 0),
(@PATH, 26, 1826.3125, -2715.04, 347.23697, NULL, 0);

UPDATE `creature` SET `position_x`=1827.8247, `position_y`=-2706.2656, `position_z`=347.237, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Mechadrone Sniper
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+64;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+64, @CGUID+64, 0, 0, 515, 0, 0),
(@CGUID+64, @CGUID+140, 5, 40, 515, 3, 10),
(@CGUID+64, @CGUID+173, 5, 320, 515, 3, 10);

SET @MOVERGUID := @CGUID+64;
SET @ENTRY := 229069;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Mechadrone Sniper - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1736.257, -2815.658, 335.04297, NULL, 0),
(@PATH, 1, 1737.5173, -2832.804, 335.00754, NULL, 0),
(@PATH, 2, 1743.3976, -2848.0486, 335.84253, NULL, 0),
(@PATH, 3, 1750.2517, -2857.6423, 338.85696, NULL, 8704),
(@PATH, 4, 1737.5173, -2832.804, 335.00754, NULL, 0),
(@PATH, 5, 1736.257, -2815.658, 335.04297, NULL, 0),
(@PATH, 6, 1736.0122, -2798.434, 334.8394, NULL, 0),
(@PATH, 7, 1746.0104, -2788.4915, 335.0431, NULL, 0),
(@PATH, 8, 1755.2952, -2794.2395, 335.0431, NULL, 0),
(@PATH, 9, 1761.6007, -2807.5347, 335.04282, NULL, 0),
(@PATH, 10, 1754.276, -2824.8994, 335.0431, NULL, 4288),
(@PATH, 11, 1761.6007, -2807.5347, 335.04282, NULL, 0),
(@PATH, 12, 1755.2952, -2794.2395, 335.0431, NULL, 0),
(@PATH, 13, 1746.0104, -2788.4915, 335.0431, NULL, 0),
(@PATH, 14, 1736.0122, -2798.434, 334.8394, NULL, 0);

UPDATE `creature` SET `position_x`=1736.257, `position_y`=-2815.658, `position_z`=335.04297, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Mechadrone Sniper
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+182;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+182, @CGUID+182, 0, 0, 515, 0, 0),
(@CGUID+182, @CGUID+148, 5, 270, 515, 16, 34),
(@CGUID+182, @CGUID+52, 5, 60, 515, 16, 34),
(@CGUID+182, @CGUID+92, 5, 300, 515, 16, 34),
(@CGUID+182, @CGUID+17, 5, 20, 515, 16, 34),
(@CGUID+182, @CGUID+202, 5, 340, 515, 16, 34);

SET @MOVERGUID := @CGUID+182;
SET @ENTRY := 229069;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Mechadrone Sniper - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1968.6514, -2895.416, 370.27533, NULL, 0),
(@PATH, 1, 1968.5017, -2876.0247, 370.22607, NULL, 0),
(@PATH, 2, 1968.5735, -2863.4082, 368.69772, NULL, 0),
(@PATH, 3, 1968.8943, -2850.918, 366.3586, NULL, 0),
(@PATH, 4, 1969.1113, -2838.5234, 363.9765, NULL, 0),
(@PATH, 5, 1969.4783, -2825.898, 361.59735, NULL, 0),
(@PATH, 6, 1970.5331, -2813.0107, 359.78882, NULL, 0),
(@PATH, 7, 1973.3293, -2800.4172, 358.60297, NULL, 0),
(@PATH, 8, 1977.9498, -2788.4602, 359.50702, NULL, 0),
(@PATH, 9, 1984.7167, -2778.8625, 361.48007, NULL, 0),
(@PATH, 10, 1992.389, -2770.513, 363.81714, NULL, 0),
(@PATH, 11, 2002.6564, -2760.1384, 367.1557, NULL, 0),
(@PATH, 12, 2010.9415, -2750.3406, 369.8913, NULL, 0),
(@PATH, 13, 2020.232, -2742.4656, 372.5094, NULL, 0),
(@PATH, 14, 2028.0723, -2735.0352, 374.6935, NULL, 0),
(@PATH, 15, 2038.7057, -2726.864, 377.62442, NULL, 0),
(@PATH, 16, 2038.9404, -2725.3372, 377.7468, NULL, 5570),
(@PATH, 17, 2038.4282, -2724.023, 377.68756, NULL, 0),
(@PATH, 18, 2028.7758, -2733.7012, 374.90326, NULL, 0),
(@PATH, 19, 2020.4493, -2742.5808, 372.54984, NULL, 0),
(@PATH, 20, 2010.7744, -2750.7812, 369.865, NULL, 0),
(@PATH, 21, 2003.0609, -2759.3687, 367.31952, NULL, 0),
(@PATH, 22, 1994.8315, -2767.5903, 364.699, NULL, 0),
(@PATH, 23, 1987.3861, -2776.006, 362.242, NULL, 0),
(@PATH, 24, 1977.1681, -2788.6057, 359.3554, NULL, 0),
(@PATH, 25, 1976.049, -2801.131, 358.89102, NULL, 0),
(@PATH, 26, 1970.3706, -2813.4666, 359.85712, NULL, 0),
(@PATH, 27, 1969.3749, -2826.0132, 361.61835, NULL, 0),
(@PATH, 28, 1969.0879, -2838.4746, 363.9765, NULL, 0),
(@PATH, 29, 1968.9268, -2850.8203, 366.2711, NULL, 0),
(@PATH, 30, 1968.3805, -2863.507, 368.73013, NULL, 0),
(@PATH, 31, 1968.53, -2876.1897, 370.23026, NULL, 0),
(@PATH, 32, 1968.6727, -2888.9521, 370.27545, NULL, 0),
(@PATH, 33, 1968.5914, -2901.5044, 370.27563, NULL, 0),
(@PATH, 34, 1968.5243, -2903.2976, 370.2791, NULL, 4437);

UPDATE `creature` SET `position_x`=1968.6514, `position_y`=-2895.416, `position_z`=370.27533, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Darkfuse Hyena
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+141;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+141, @CGUID+141, 0, 0, 515, 0, 0),
(@CGUID+141, @CGUID+174, 5, 90, 515, 4, 16),
(@CGUID+141, @CGUID+210, 7, 50, 515, 4, 16),
(@CGUID+141, @CGUID+93, 5, 0, 515, 4, 16);

SET @MOVERGUID := @CGUID+141;
SET @ENTRY := 229252;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Darkfuse Hyena - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1782.8195, -2586.5815, 371.05515, NULL, 0),
(@PATH, 1, 1783.9375, -2595.934, 368.63156, NULL, 0),
(@PATH, 2, 1781.4202, -2604.9324, 367.96027, NULL, 0),
(@PATH, 3, 1784.1493, -2611.0903, 365.47086, NULL, 0),
(@PATH, 4, 1788.7135, -2616.6614, 363.78906, NULL, 5513),
(@PATH, 5, 1785.5449, -2612.795, 364.6541, NULL, 0),
(@PATH, 6, 1784.2773, -2611.248, 365.59384, NULL, 0),
(@PATH, 7, 1784.1493, -2611.0903, 365.47086, NULL, 0),
(@PATH, 8, 1783.7441, -2610.1758, 365.91602, NULL, 0),
(@PATH, 9, 1782.9336, -2608.3477, 366.559, NULL, 0),
(@PATH, 10, 1782.5283, -2607.4336, 366.81683, NULL, 0),
(@PATH, 11, 1782.123, -2606.5195, 367.38434, NULL, 0),
(@PATH, 12, 1781.7178, -2605.6055, 367.60376, NULL, 0),
(@PATH, 13, 1781.4202, -2604.9324, 367.96027, NULL, 0),
(@PATH, 14, 1783.9375, -2595.934, 368.63156, NULL, 0),
(@PATH, 15, 1782.8195, -2586.5815, 371.05515, NULL, 0),
(@PATH, 16, 1779.7726, -2576.139, 373.86426, NULL, 5446);

UPDATE `creature` SET `position_x`=1782.8195, `position_y`=-2586.5815, `position_z`=371.05515, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Darkfuse Soldier
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+290;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+290, @CGUID+290, 0, 0, 515, 0, 0),
(@CGUID+290, @CGUID+283, 4, 270, 515, 12, 25);

SET @MOVERGUID := @CGUID+290;
SET @ENTRY := 228144;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Darkfuse Soldier - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1601.776, -2598.125, 358.50946, NULL, 0),
(@PATH, 1, 1599.5382, -2600.3577, 360.2273, NULL, 0),
(@PATH, 2, 1596.8785, -2603.5503, 362.6748, NULL, 0),
(@PATH, 3, 1594.342, -2605.9253, 364.7236, NULL, 0),
(@PATH, 4, 1591.7223, -2608.179, 366.6635, NULL, 0),
(@PATH, 5, 1589.7413, -2610.158, 368.23935, NULL, 0),
(@PATH, 6, 1587.2084, -2612.3333, 370.11356, NULL, 0),
(@PATH, 7, 1584.9479, -2614.5833, 371.91684, NULL, 0),
(@PATH, 8, 1583.1979, -2616.5347, 373.42917, NULL, 0),
(@PATH, 9, 1580.1389, -2619.5312, 374.82327, NULL, 0),
(@PATH, 10, 1575.5122, -2624.0574, 374.8089, NULL, 0),
(@PATH, 11, 1571.8298, -2627.3699, 375.74985, NULL, 0),
(@PATH, 12, 1570.25, -2628.9722, 377.11746, NULL, 7652),
(@PATH, 13, 1575.5122, -2624.0574, 374.8089, NULL, 0),
(@PATH, 14, 1580.1389, -2619.5312, 374.82327, NULL, 0),
(@PATH, 15, 1583.1979, -2616.5347, 373.42917, NULL, 0),
(@PATH, 16, 1584.9479, -2614.5833, 371.91684, NULL, 0),
(@PATH, 17, 1587.2084, -2612.3333, 370.11356, NULL, 0),
(@PATH, 18, 1589.7413, -2610.158, 368.23935, NULL, 0),
(@PATH, 19, 1591.7223, -2608.179, 366.6635, NULL, 0),
(@PATH, 20, 1594.342, -2605.9253, 364.7236, NULL, 0),
(@PATH, 21, 1596.8785, -2603.5503, 362.6748, NULL, 0),
(@PATH, 22, 1599.5382, -2600.3577, 360.2273, NULL, 0),
(@PATH, 23, 1601.776, -2598.125, 358.50946, NULL, 0),
(@PATH, 24, 1604.0817, -2595.6824, 356.5478, NULL, 0),
(@PATH, 25, 1606.3976, -2593.3733, 355.7944, NULL, 5276);

UPDATE `creature` SET `position_x`=1601.776, `position_y`=-2598.125, `position_z`=358.50946 WHERE `guid`=@CGUID+283;
UPDATE `creature` SET `position_x`=1601.776, `position_y`=-2598.125, `position_z`=358.50946, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '471891 462735');

-- Path for Darkfuse Soldier
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+375;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+375, @CGUID+375, 0, 0, 515, 0, 0),
(@CGUID+375, @CGUID+376, 4, 270, 515, 13, 28);

SET @MOVERGUID := @CGUID+375;
SET @ENTRY := 228144;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Darkfuse Soldier - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1359.7959, -2841.4187, 283.15533, NULL, 0),
(@PATH, 1, 1359.7738, -2838.3354, 283.15533, NULL, 0),
(@PATH, 2, 1359.742, -2835.2869, 283.15533, NULL, 0),
(@PATH, 3, 1359.7106, -2832.2734, 283.09677, NULL, 0),
(@PATH, 4, 1359.71, -2828.9563, 283.02435, NULL, 0),
(@PATH, 5, 1359.7009, -2825.6748, 282.95276, NULL, 0),
(@PATH, 6, 1359.705, -2823.541, 282.43213, NULL, 0),
(@PATH, 7, 1359.7191, -2820.718, 282.35846, NULL, 0),
(@PATH, 8, 1359.7289, -2817.6584, 282.415, NULL, 0),
(@PATH, 9, 1359.737, -2814.6685, 282.4601, NULL, 0),
(@PATH, 10, 1359.7452, -2811.6218, 282.4688, NULL, 0),
(@PATH, 11, 1359.7999, -2808.6843, 282.45398, NULL, 0),
(@PATH, 12, 1359.864, -2805.6655, 282.43884, NULL, 0),
(@PATH, 13, 1359.9121, -2803.4065, 282.42752, NULL, 5331),
(@PATH, 14, 1359.8245, -2807.5303, 282.4482, NULL, 0),
(@PATH, 15, 1359.76, -2810.5593, 282.4634, NULL, 0),
(@PATH, 16, 1359.7399, -2813.5925, 282.47635, NULL, 0),
(@PATH, 17, 1359.7316, -2816.6804, 282.42978, NULL, 0),
(@PATH, 18, 1359.724, -2819.4688, 282.3877, NULL, 0),
(@PATH, 19, 1359.7101, -2822.528, 282.53586, NULL, 0),
(@PATH, 20, 1359.6968, -2825.1558, 282.94147, NULL, 0),
(@PATH, 21, 1359.6812, -2828.3035, 283.01025, NULL, 0),
(@PATH, 22, 1359.6993, -2831.2048, 283.0735, NULL, 0),
(@PATH, 23, 1359.7308, -2834.215, 283.13907, NULL, 0),
(@PATH, 24, 1359.7623, -2837.2336, 283.15533, NULL, 0),
(@PATH, 25, 1359.7937, -2840.3193, 283.15533, NULL, 0),
(@PATH, 26, 1359.7999, -2843.3506, 283.15533, NULL, 0),
(@PATH, 27, 1359.8062, -2846.3574, 283.15533, NULL, 0),
(@PATH, 28, 1359.8108, -2848.594, 283.15533, NULL, 2919);

UPDATE `creature` SET `position_x`=1359.7959, `position_y`=-2841.4187, `position_z`=283.15533, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '471891 462735');

-- Path for Loaderbot
SET @MOVERGUID := @CGUID+267;
SET @ENTRY := 231014;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Loaderbot - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1614.4548, -2627.7031, 355.69006, NULL, 0),
(@PATH, 1, 1613.7413, -2625.1355, 355.69006, NULL, 0),
(@PATH, 2, 1612.7778, -2623.0696, 355.69006, NULL, 0),
(@PATH, 3, 1611.2726, -2620.5574, 355.69006, NULL, 7770),
(@PATH, 4, 1613.7413, -2625.1355, 355.69006, NULL, 0),
(@PATH, 5, 1614.4548, -2627.7031, 355.69006, NULL, 0),
(@PATH, 6, 1614.8629, -2630.6719, 355.69006, NULL, 0),
(@PATH, 7, 1614.8716, -2633.5955, 356.02472, NULL, 7776);

UPDATE `creature` SET `position_x`=1614.4548, `position_y`=-2627.7031, `position_z`=355.69006, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Targeting Stalker
SET @MOVERGUID := @CGUID+241;
SET @ENTRY := 235065;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Targeting Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1655.0209, -2768.677, 336.01913, NULL, 0),
(@PATH, 1, 1664.2778, -2760.9983, 335.93927, NULL, 0),
(@PATH, 2, 1673.5348, -2753.3196, 335.8594, NULL, 0),
(@PATH, 3, 1673.5348, -2753.3196, 335.8594, NULL, 0),
(@PATH, 4, 1675.7048, -2744.073, 335.52448, NULL, 0),
(@PATH, 5, 1672.1927, -2735.0886, 335.69806, NULL, 0),
(@PATH, 6, 1667.8091, -2726.9548, 335.9411, NULL, 0),
(@PATH, 7, 1662.2223, -2719.4565, 335.60913, NULL, 0),
(@PATH, 8, 1649.0052, -2711.2449, 335.5873, NULL, 0),
(@PATH, 9, 1641.6216, -2712.2466, 335.9938, NULL, 0),
(@PATH, 10, 1636.0764, -2727.0955, 335.9938, NULL, 0),
(@PATH, 11, 1634.9166, -2737.8176, 335.9938, NULL, 0),
(@PATH, 12, 1632.106, -2746.948, 335.9938, NULL, 0),
(@PATH, 13, 1635.7986, -2752.8281, 335.9938, NULL, 0),
(@PATH, 14, 1643.0747, -2758.9011, 335.9938, NULL, 0);

UPDATE `creature` SET `position_x`=1655.0209, `position_y`=-2768.677, `position_z`=336.01913, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1213693');

-- Path for Targeting Stalker
SET @MOVERGUID := @CGUID+103;
SET @ENTRY := 235065;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Targeting Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1706.0382, -2791.3909, 336.20038, NULL, 0),
(@PATH, 1, 1718.7743, -2794.8057, 336.0252, NULL, 0),
(@PATH, 2, 1731.5104, -2798.2205, 335.85004, NULL, 0),
(@PATH, 3, 1731.5104, -2798.2205, 335.85004, NULL, 0),
(@PATH, 4, 1740.5625, -2793.9463, 335.685, NULL, 0),
(@PATH, 5, 1741.9514, -2784.0781, 336.04214, NULL, 0),
(@PATH, 6, 1739.2188, -2775.7727, 335.99893, NULL, 0),
(@PATH, 7, 1735.4514, -2768.2812, 336.01645, NULL, 0),
(@PATH, 8, 1724.7361, -2762.4307, 336.0431, NULL, 0),
(@PATH, 9, 1711.7031, -2763, 336.0429, NULL, 0),
(@PATH, 10, 1707.4323, -2771.0295, 336.0348, NULL, 0),
(@PATH, 11, 1708.5973, -2779.6494, 336.0431, NULL, 0);

UPDATE `creature` SET `position_x`=1706.0382, `position_y`=-2791.3909, `position_z`=336.20038, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1213693');

-- Path for Targeting Stalker
SET @MOVERGUID := @CGUID+70;
SET @ENTRY := 235065;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Targeting Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1730.2067, -2823.2344, 336.0431, NULL, 0),
(@PATH, 1, 1733.1338, -2831.7422, 335.8249, NULL, 0),
(@PATH, 2, 1734.0573, -2834.4324, 335.61093, NULL, 0),
(@PATH, 3, 1743.1841, -2829.7551, 336.0431, NULL, 0),
(@PATH, 4, 1750.8229, -2820.8838, 336.04193, NULL, 0),
(@PATH, 5, 1758.993, -2816.4531, 336.04224, NULL, 0),
(@PATH, 6, 1764.941, -2809.5642, 336.0431, NULL, 0),
(@PATH, 7, 1766.2413, -2802.5781, 336.0431, NULL, 0),
(@PATH, 8, 1759.5052, -2793.8125, 336.0431, NULL, 0),
(@PATH, 9, 1747.3038, -2787.5903, 336.0431, NULL, 0),
(@PATH, 10, 1735.0435, -2789.7864, 335.74384, NULL, 0),
(@PATH, 11, 1729.356, -2797.427, 335.85712, NULL, 0),
(@PATH, 12, 1736.4062, -2811.4185, 336.0376, NULL, 0);

UPDATE `creature` SET `position_x`=1730.2067, `position_y`=-2823.2344, `position_z`=336.0431, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1213693');

-- Path for Targeting Stalker
SET @MOVERGUID := @CGUID+276;
SET @ENTRY := 235065;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Targeting Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1589.1233, -2772.5798, 335.9938, NULL, 0),
(@PATH, 1, 1590.3594, -2782.8074, 335.9938, NULL, 0),
(@PATH, 2, 1594.9635, -2791.3645, 335.9938, NULL, 0),
(@PATH, 3, 1607.0712, -2791.9739, 335.97577, NULL, 0),
(@PATH, 4, 1616.6077, -2788.929, 335.99878, NULL, 0),
(@PATH, 5, 1626.8125, -2784.2551, 336.0019, NULL, 0),
(@PATH, 6, 1637.1858, -2777.429, 336.0024, NULL, 0),
(@PATH, 7, 1644.9166, -2765.111, 335.9941, NULL, 0),
(@PATH, 8, 1641.9896, -2755.3977, 335.9938, NULL, 0),
(@PATH, 9, 1635.2952, -2748.0798, 335.9938, NULL, 0),
(@PATH, 10, 1621.3091, -2745.2031, 335.9938, NULL, 0),
(@PATH, 11, 1610.2916, -2746.4426, 335.9938, NULL, 0),
(@PATH, 12, 1600.7448, -2751.5417, 335.9938, NULL, 0),
(@PATH, 13, 1590.8716, -2761.7588, 335.9935, NULL, 0);

UPDATE `creature` SET `position_x`=1589.1233, `position_y`=-2772.5798, `position_z`=335.9938, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1213693');

-- Path for Targeting Stalker
SET @MOVERGUID := @CGUID+8;
SET @ENTRY := 235065;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Targeting Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1693.6302, -2754.2986, 335.32767, NULL, 0),
(@PATH, 1, 1682.4774, -2748.9463, 335.09604, NULL, 0),
(@PATH, 2, 1674.8142, -2748.2622, 335.70123, NULL, 0),
(@PATH, 3, 1665.6598, -2750.4792, 335.96146, NULL, 0),
(@PATH, 4, 1663.0677, -2754.5088, 335.9934, NULL, 0),
(@PATH, 5, 1666.8455, -2760.3525, 335.9418, NULL, 0),
(@PATH, 6, 1675.8594, -2763.1267, 335.9339, NULL, 0),
(@PATH, 7, 1684.8646, -2766.1077, 335.9677, NULL, 0),
(@PATH, 8, 1696.2812, -2768.4739, 335.92453, NULL, 0),
(@PATH, 9, 1706.6163, -2774.875, 336.04077, NULL, 0),
(@PATH, 10, 1712.8125, -2767.8213, 336.0431, NULL, 0),
(@PATH, 11, 1703.8021, -2757.4236, 335.82245, NULL, 0);

UPDATE `creature` SET `position_x`=1693.6302, `position_y`=-2754.2986, `position_z`=335.32767, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1213693');

-- Path for Targeting Stalker
SET @MOVERGUID := @CGUID+240;
SET @ENTRY := 235065;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Targeting Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1630.908, -2731.6963, 335.9938, NULL, 0),
(@PATH, 1, 1630.2673, -2719.5383, 335.9837, NULL, 0),
(@PATH, 2, 1626.8334, -2710.323, 335.9926, NULL, 0),
(@PATH, 3, 1616.9705, -2703.25, 335.9837, NULL, 0),
(@PATH, 4, 1608.1719, -2704.467, 335.9837, NULL, 0),
(@PATH, 5, 1597.9028, -2714.5608, 335.9837, NULL, 0),
(@PATH, 6, 1592.1892, -2722.9792, 335.9837, NULL, 0),
(@PATH, 7, 1589.099, -2735.3645, 335.9837, NULL, 0),
(@PATH, 8, 1587.6805, -2746.7605, 335.99414, NULL, 0),
(@PATH, 9, 1589.5209, -2761.5261, 335.99268, NULL, 0),
(@PATH, 10, 1597.2153, -2765.823, 335.9938, NULL, 0),
(@PATH, 11, 1611.4166, -2764.375, 335.9938, NULL, 0),
(@PATH, 12, 1623.9723, -2756.9636, 335.9938, NULL, 0),
(@PATH, 13, 1630.3837, -2745.7605, 335.9938, NULL, 0);

UPDATE `creature` SET `position_x`=1630.908, `position_y`=-2731.6963, `position_z`=335.9938, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1213693');

-- Path for Venture Co. Diver
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+18;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+18, @CGUID+18, 0, 0, 515, 0, 0),
(@CGUID+18, @CGUID+204, 3, 0, 515, 0, 0);

SET @MOVERGUID := @CGUID+18;
SET @ENTRY := 231496;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Venture Co. Diver - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1718.0747, -2763.0435, 335.0431, NULL, 0),
(@PATH, 1, 1716.8663, -2776.231, 335.0428, NULL, 0),
(@PATH, 2, 1713.4479, -2786.3298, 335.04532, NULL, 0),
(@PATH, 3, 1707.6754, -2795.9775, 334.9735, NULL, 5394),
(@PATH, 4, 1713.4479, -2786.3298, 335.04532, NULL, 0),
(@PATH, 5, 1716.8663, -2776.231, 335.0428, NULL, 0),
(@PATH, 6, 1718.0747, -2763.0435, 335.0431, NULL, 0),
(@PATH, 7, 1717.7223, -2753.6199, 335.04163, NULL, 6451);

UPDATE `creature` SET `position_x`=1718.0747, `position_y`=-2763.0435, `position_z`=335.0431, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Venture Co. Diver
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+233;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+233, @CGUID+233, 0, 0, 515, 0, 0),
(@CGUID+233, @CGUID+230, 4, 30, 515, 6, 13),
(@CGUID+233, @CGUID+232, 4, 330, 515, 6, 13);

SET @MOVERGUID := @CGUID+233;
SET @ENTRY := 231496;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Venture Co. Diver - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1649.4635, -2732.8594, 334.98883, NULL, 0),
(@PATH, 1, 1654.9462, -2738.4531, 334.97574, NULL, 0),
(@PATH, 2, 1660.2101, -2742.7292, 334.96573, NULL, 0),
(@PATH, 3, 1664.7118, -2746.486, 334.93478, NULL, 0),
(@PATH, 4, 1670.2483, -2749.8872, 334.8786, NULL, 0),
(@PATH, 5, 1674.9166, -2752.6562, 334.8051, NULL, 0),
(@PATH, 6, 1680.7118, -2756.0278, 334.64862, NULL, 6419),
(@PATH, 7, 1674.9166, -2752.6562, 334.8051, NULL, 0),
(@PATH, 8, 1670.2483, -2749.8872, 334.8786, NULL, 0),
(@PATH, 9, 1664.7118, -2746.486, 334.93478, NULL, 0),
(@PATH, 10, 1660.2101, -2742.7292, 334.96573, NULL, 0),
(@PATH, 11, 1654.9462, -2738.4531, 334.97574, NULL, 0),
(@PATH, 12, 1649.4635, -2732.8594, 334.98883, NULL, 0),
(@PATH, 13, 1643.7048, -2726.7083, 334.9938, NULL, 5264);

UPDATE `creature` SET `position_x`=1649.4635, `position_y`=-2732.8594, `position_z`=334.98883, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Venture Co. Diver
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+150;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+150, @CGUID+150, 0, 0, 515, 0, 0),
(@CGUID+150, @CGUID+231, 4, 30, 515, 6, 13),
(@CGUID+150, @CGUID+234, 4, 330, 515, 6, 13);

SET @MOVERGUID := @CGUID+150;
SET @ENTRY := 231496;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Venture Co. Diver - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1647.4688, -2754.4011, 334.9938, NULL, 0),
(@PATH, 1, 1654.625, -2757.5, 334.9938, NULL, 0),
(@PATH, 2, 1661.6372, -2760.1042, 334.96735, NULL, 0),
(@PATH, 3, 1668.5695, -2762.3125, 334.89072, NULL, 0),
(@PATH, 4, 1673.3716, -2763.0156, 334.92206, NULL, 0),
(@PATH, 5, 1680.2361, -2765.106, 334.98407, NULL, 0),
(@PATH, 6, 1687.0955, -2768.5208, 335.00317, NULL, 9242),
(@PATH, 7, 1680.2361, -2765.106, 334.98407, NULL, 0),
(@PATH, 8, 1673.3716, -2763.0156, 334.92206, NULL, 0),
(@PATH, 9, 1668.5695, -2762.3125, 334.89072, NULL, 0),
(@PATH, 10, 1661.6372, -2760.1042, 334.96735, NULL, 0),
(@PATH, 11, 1654.625, -2757.5, 334.9938, NULL, 0),
(@PATH, 12, 1647.4688, -2754.4011, 334.9938, NULL, 0),
(@PATH, 13, 1641.026, -2750.7935, 334.9938, NULL, 8041);

UPDATE `creature` SET `position_x`=1647.4688, `position_y`=-2754.4011, `position_z`=334.9938, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Darkfuse Inspector
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+355;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+355, @CGUID+355, 0, 0, 515, 0, 0),
(@CGUID+355, @CGUID+366, 3, 270, 515, 5, 11);

SET @MOVERGUID := @CGUID+355;
SET @ENTRY := 231385;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Darkfuse Inspector - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1414.7726, -2781.7344, 282.56155, NULL, 0),
(@PATH, 1, 1408.1788, -2781.7258, 282.56155, NULL, 0),
(@PATH, 2, 1402.8541, -2781.8333, 282.61862, NULL, 0),
(@PATH, 3, 1397.2014, -2781.8855, 282.56155, NULL, 0),
(@PATH, 4, 1391.8889, -2781.8542, 282.56155, NULL, 0),
(@PATH, 5, 1384.8125, -2781.6284, 282.56158, NULL, 5645),
(@PATH, 6, 1391.8889, -2781.8542, 282.56155, NULL, 0),
(@PATH, 7, 1397.2014, -2781.8855, 282.56155, NULL, 0),
(@PATH, 8, 1402.8541, -2781.8333, 282.61862, NULL, 0),
(@PATH, 9, 1408.1788, -2781.7258, 282.56155, NULL, 0),
(@PATH, 10, 1414.7726, -2781.7344, 282.56155, NULL, 0),
(@PATH, 11, 1422.1211, -2781.5796, 282.56158, NULL, 4416);

UPDATE `creature` SET `position_x`=1414.7726, `position_y`=-2781.7344, `position_z`=282.56155, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Zeppelin Stalker
SET @MOVERGUID := @CGUID+81;
SET @ENTRY := 234992;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 4.9130, 'Zeppelin Stalker - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1722.5017, -2800.6807, 420, NULL, 0),
(@PATH, 1, 1673.3802, -2825.2551, 420, NULL, 0),
(@PATH, 2, 1613.1649, -2817.2275, 420, NULL, 0),
(@PATH, 3, 1575.7986, -2768.8628, 420, NULL, 0),
(@PATH, 4, 1581.4861, -2693.8923, 420, NULL, 0),
(@PATH, 5, 1611.5486, -2654.0781, 420, NULL, 0),
(@PATH, 6, 1650.4358, -2637.304, 420, NULL, 0),
(@PATH, 7, 1698.4983, -2641.0469, 420, NULL, 0),
(@PATH, 8, 1738.6146, -2687.9426, 420, NULL, 0),
(@PATH, 9, 1740.7084, -2750, 420, NULL, 0);

UPDATE `creature` SET `position_x`=1722.5017, `position_y`=-2800.6807, `position_z`=420, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Big Momma
SET @MOVERGUID = @CGUID+137;
SET @ENTRY := 226398;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Big M.O.M.M.A. - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1658.3767, -2579.559, 355.71725, NULL, 0),
(@PATH, 1, 1666.4062, -2579.5312, 355.71725, NULL, 0),
(@PATH, 2, 1675.1459, -2579.573, 355.71725, NULL, 0),
(@PATH, 3, 1683.3594, -2579.5469, 355.74667, NULL, 0),
(@PATH, 4, 1691.9913, -2579.4602, 355.7836, NULL, 8064),
(@PATH, 5, 1683.3594, -2579.5469, 355.74667, NULL, 0),
(@PATH, 6, 1675.1459, -2579.573, 355.71725, NULL, 0),
(@PATH, 7, 1666.4062, -2579.5312, 355.71725, NULL, 0),
(@PATH, 8, 1658.3767, -2579.559, 355.71725, NULL, 0),
(@PATH, 9, 1650.7153, -2579.6719, 355.71725, NULL, 4455);

UPDATE `creature` SET `position_x`=1658.3767, `position_y`=-2579.559, `position_z`=355.71725, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@ENTRY, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''); -- 226398 (Big M.O.M.M.A.)

-- Path for Bront
SET @MOVERGUID = @CGUID+39;
SET @ENTRY := 226402;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Bront - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1620.1285, -2858.9236, 362.37427, NULL, 0),
(@PATH, 1, 1620.5452, -2855.0034, 362.29813, NULL, 0),
(@PATH, 2, 1620.9618, -2851.0833, 362.222, NULL, 0),
(@PATH, 3, 1620.375, -2847.8074, 362.1573, NULL, 0),
(@PATH, 4, 1620.375, -2847.8074, 362.1573, NULL, 0),
(@PATH, 5, 1618.6129, -2845.1128, 362.10468, NULL, 0),
(@PATH, 6, 1615.9115, -2843.9739, 362.0869, NULL, 0),
(@PATH, 7, 1611.25, -2843.8784, 362.08826, NULL, 0),
(@PATH, 8, 1608.243, -2844.7673, 362.09497, NULL, 0),
(@PATH, 9, 1605.8177, -2845.7761, 362.09277, NULL, 0),
(@PATH, 10, 1602.8091, -2846.5557, 362.07898, NULL, 6571),
(@PATH, 11, 1608.243, -2844.7673, 362.09497, NULL, 0),
(@PATH, 12, 1615.9115, -2843.9739, 362.0869, NULL, 0),
(@PATH, 13, 1618.6129, -2845.1128, 362.10468, NULL, 0),
(@PATH, 14, 1620.9618, -2851.0833, 362.222, NULL, 0),
(@PATH, 15, 1620.5452, -2855.0034, 362.29813, NULL, 0),
(@PATH, 16, 1620.3507, -2859.361, 362.3615, NULL, 0),
(@PATH, 17, 1619.8611, -2862.665, 362.40515, NULL, 7829);

UPDATE `creature` SET `position_x`=1620.1285, `position_y`=-2858.9236, `position_z`=362.37427, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_template_addon` WHERE `entry`=@ENTRY;
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@ENTRY, @PATH, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '1216276'); -- 226402 (Bront) - [DNT] Hold Crate
