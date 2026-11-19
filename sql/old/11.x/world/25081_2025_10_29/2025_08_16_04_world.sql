SET @CGUID := 10006619;
SET @OGUID := 10001669;

SET @ATSPAWNID := 257;
SET @ATPROPERTIESID := 158;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+166;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 211150, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 788.71356201171875, -1046.6927490234375, 999.807373046875, 1.187576532363891601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive, 424126 - Bot AI Follow Advert)
(@CGUID+1, 242209, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 806.62152099609375, -886.953125, 988.65972900390625, 3.842569589614868164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Overgorged Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1231497 - Overgorged)
(@CGUID+2, 234912, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 770.578125, -904.21356201171875, 984.8878173828125, 3.938329458236694335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+3, 243716, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 748.5340576171875, -942.83856201171875, 996.542724609375, 0.966194331645965576, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 62493), -- Skitterer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+4, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 744.24652099609375, -918.5555419921875, 986.66033935546875, 5.151824951171875, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+5, 247930, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 766.32464599609375, -1042.8507080078125, 997.9656982421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 472701 - Helper)
(@CGUID+6, 234912, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 802.0069580078125, -890.06427001953125, 988.1336669921875, 5.860980510711669921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+7, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 782.9913330078125, -893.81597900390625, 985.5260009765625, 5.246305465698242187, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+8, 242209, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 765.875, -909.11456298828125, 984.95135498046875, 4.534870624542236328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Overgorged Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1231497 - Overgorged, 1235558 - [DNT] Devour Broker)
(@CGUID+9, 211152, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 783.76739501953125, -1046.3472900390625, 999.807373046875, 4.9836883544921875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive, 424126 - Bot AI Follow Advert)
(@CGUID+10, 211137, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 795.328125, -1047.314208984375, 999.807373046875, 2.526835918426513671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive, 424126 - Bot AI Follow Advert)
(@CGUID+11, 211151, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 799.82464599609375, -1045.9635009765625, 999.807373046875, 3.875065565109252929, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive, 424126 - Bot AI Follow Advert)
(@CGUID+12, 211111, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 792.00518798828125, -1045.6649169921875, 999.807373046875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+13, 211149, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 791.96356201171875, -1048.967041015625, 999.807373046875, 1.560390830039978027, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 424283 - Passive, 424126 - Bot AI Follow Advert)
(@CGUID+14, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 765.85418701171875, -903.79864501953125, 985.9324951171875, 5.023896694183349609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+15, 242209, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 806.60418701171875, -891.47052001953125, 988.49822998046875, 2.75700235366821289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Overgorged Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1231497 - Overgorged)
(@CGUID+16, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 768.7430419921875, -906.4305419921875, 985.046875, 1.181327700614929199, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+17, 210930, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 777.3507080078125, -907.80902099609375, 985.04449462890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+18, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 798.1492919921875, -914.58160400390625, 986.1334228515625, 5.24120330810546875, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+19, 238392, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 799.63543701171875, -990.5382080078125, 999.75543212890625, 4.116293907165527343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ve'nari (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+20, 210930, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 789.34375, -964.43402099609375, 999.77008056640625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+21, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 804.92706298828125, -890.3524169921875, 988.5040283203125, 0, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+22, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 706.19268798828125, -888.0538330078125, 984.43182373046875, 4.860374927520751953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+23, 243721, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 699.2586669921875, -872.05169677734375, 981.5482177734375, 1.788300156593322753, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 62493), -- Hoplet (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+24, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 716.295166015625, -848.03643798828125, 978.22686767578125, 0, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1235612 - [DNT] Broker Glow)
(@CGUID+25, 242209, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 749.97393798828125, -879.96527099609375, 980.0126953125, 3.613314151763916015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Overgorged Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1231497 - Overgorged)
(@CGUID+26, 234912, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 681.06427001953125, -853.20489501953125, 976.947021484375, 0.588168680667877197, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+27, 244927, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 742.89239501953125, -856.25347900390625, 978.600341796875, 4.094992637634277343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Terrified Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1236653 - [DNT] Health Tracker Aura)
(@CGUID+28, 234883, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 743.935791015625, -875.4288330078125, 979.55078125, 4.755793571472167968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Voracious Gorger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+29, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 701.32464599609375, -888.56768798828125, 984.38507080078125, 6.034830570220947265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+30, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 744.7413330078125, -883.2899169921875, 980.18572998046875, 0, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+31, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 725.27008056640625, -868.039794921875, 1003.449951171875, 2.43369150161743164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+32, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 707.46356201171875, -897.53302001953125, 986.44744873046875, 4.860374927520751953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+33, 243716, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 816.95977783203125, -839.09600830078125, 986.9251708984375, 3.697086572647094726, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 62493), -- Skitterer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+34, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 743.70660400390625, -878.26910400390625, 979.72711181640625, 0, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+35, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 704.98785400390625, -894.13018798828125, 985.3189697265625, 4.860374927520751953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+36, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 705.20489501953125, -890.4930419921875, 982.607421875, 6.136539936065673828, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+37, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 710.2100830078125, -893.28643798828125, 985.07421875, 2.508646488189697265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+38, 243716, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 812.3748779296875, -867.22406005859375, 987.551025390625, 2.963438034057617187, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 62493), -- Skitterer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+39, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 723.2430419921875, -854.342041015625, 978.47686767578125, 0, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+40, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 701.484375, -893.72052001953125, 985.0186767578125, 4.860374927520751953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+41, 234912, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 741.0625, -885.45660400390625, 981.1209716796875, 0.4515400230884552, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+42, 234912, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 687.154541015625, -853.70831298828125, 977.1395263671875, 2.371732473373413085, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+43, 210931, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 791.90802001953125, -766.310791015625, 997.14996337890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+44, 234872, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 832.48785400390625, -756.41143798828125, 998.8819580078125, 4.135316848754882812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+45, 243716, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 703.1357421875, -811.41070556640625, 975.42022705078125, 4.075915336608886718, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 62493), -- Skitterer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+46, 234883, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 686.84552001953125, -807.16839599609375, 975.486083984375, 3.85953068733215332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Voracious Gorger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+47, 236995, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 683.44189453125, -834.96563720703125, 976.3857421875, 5.508866786956787109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravenous Destroyer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+48, 243716, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 934.33404541015625, -854.18572998046875, 987.49542236328125, 3.061451196670532226, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 62493), -- Skitterer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+49, 234883, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 683.60418701171875, -847.32464599609375, 976.9234619140625, 4.755793571472167968, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Voracious Gorger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+50, 234912, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 685.47222900390625, -814.77081298828125, 974.91839599609375, 2.371732473373413085, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+51, 242209, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 679.3819580078125, -814.26739501953125, 975.05999755859375, 3.828569412231445312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Overgorged Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1231497 - Overgorged, 1235558 - [DNT] Devour Broker)
(@CGUID+52, 210931, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 827.04339599609375, -757.4444580078125, 998.4522705078125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+53, 242209, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 679.654541015625, -807.26910400390625, 975.0899658203125, 5.011611461639404296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Overgorged Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1231497 - Overgorged)
(@CGUID+54, 242631, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 780.25555419921875, -762.82989501953125, 996.07574462890625, 2.532232999801635742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Overcharged Sentinel (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1231234 - Protected Core, 18950 - Invisibility and Stealth Detection)
(@CGUID+55, 243716, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 826.09930419921875, -785.90728759765625, 1002.023193359375, 2.158010482788085937, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 62493), -- Skitterer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+56, 243716, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 666.20269775390625, -840.6624755859375, 976.2896728515625, 4.782403945922851562, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 62493), -- Skitterer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+57, 234962, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 729.57470703125, -755.03472900390625, 994.9681396484375, 3.964251279830932617, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant)
(@CGUID+58, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 650.97918701171875, -786.02777099609375, 979.91436767578125, 6.266290187835693359, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+59, 234957, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 831.29168701171875, -750.61981201171875, 998.52777099609375, 5.052924633026123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Ritualist (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+60, 234872, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 823.79168701171875, -751.53472900390625, 998.13885498046875, 5.048398494720458984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+61, 234960, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 729.41796875, -749.3277587890625, 994.95416259765625, 3.963602066040039062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Tamed Ruinstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+62, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 654.93231201171875, -775.623291015625, 981.38824462890625, 0, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1235612 - [DNT] Broker Glow)
(@CGUID+63, 234960, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 735.2838134765625, -754.767333984375, 994.78411865234375, 3.963635206222534179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Tamed Ruinstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+64, 243716, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 938.01873779296875, -780.37762451171875, 986.2119140625, 3.784772872924804687, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 62493), -- Skitterer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 234872, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 869.42706298828125, -734.26043701171875, 998.39898681640625, 3.815958261489868164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+66, 234872, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 865.3055419921875, -731.71527099609375, 998.390625, 4.73579263687133789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+67, 234872, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 924.513916015625, -755.8211669921875, 998.34600830078125, 2.939950942993164062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+68, 234872, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 754.7413330078125, -723.25347900390625, 994.1304931640625, 5.800194263458251953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+69, 243716, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 754.55523681640625, -724.98797607421875, 994.1812744140625, 1.275599122047424316, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 62493), -- Skitterer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+70, 239223, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 757.69793701171875, -725.60418701171875, 993.9635009765625, 4.512959957122802734, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Devourer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+71, 234962, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 864.0555419921875, -739.69793701171875, 998.7899169921875, 1.391855835914611816, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant)
(@CGUID+72, 234962, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 860.8819580078125, -736.39239501953125, 998.76385498046875, 5.663674831390380859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant)
(@CGUID+73, 243716, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 915.75201416015625, -751.0189208984375, 998.9671630859375, 4.004792690277099609, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 62493), -- Skitterer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+74, 234962, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 918.91668701171875, -746.248291015625, 997.9708251953125, 5.240016460418701171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant)
(@CGUID+75, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 616.79681396484375, -771.62176513671875, 1011.2825927734375, 1.839087247848510742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+76, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 615.00030517578125, -766.95562744140625, 1011.2825927734375, 2.207776069641113281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+77, 242631, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 702.26739501953125, -732.51043701171875, 994.9635009765625, 2.419822216033935546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Overcharged Sentinel (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1231234 - Protected Core, 18950 - Invisibility and Stealth Detection)
(@CGUID+78, 234912, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 629.14239501953125, -757.02777099609375, 985.861083984375, 1.749667167663574218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+79, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 649.36456298828125, -748.5538330078125, 985.71343994140625, 5.24120330810546875, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+80, 234962, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 929.65625, -746.248291015625, 998.9722900390625, 3.857558965682983398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant)
(@CGUID+81, 234872, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 758.734375, -720.91143798828125, 994.08551025390625, 4.925325393676757812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+82, 234883, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 694.951416015625, -725.39410400390625, 995.0728759765625, 5.669498443603515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Voracious Gorger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+83, 234883, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 691.0242919921875, -730.6788330078125, 995.31640625, 5.669498443603515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Voracious Gorger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+84, 235127, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 648.89581298828125, -743.07464599609375, 986.13043212890625, 0, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Broker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+85, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 617.869873046875, -760.4930419921875, 1011.2825927734375, 2.781864643096923828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+86, 210930, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 618.29339599609375, -753.0225830078125, 986.1583251953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+87, 234872, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 926.04864501953125, -739.61981201171875, 999.443359375, 3.853032588958740234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+88, 237514, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 878.04498291015625, -614.083984375, 999.0579833984375, 4.408246040344238281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- A'wazj (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1241865 - [DNT] Boss 02 Hiding Aura)
(@CGUID+89, 234883, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 624.75, -752.25347900390625, 985.7569580078125, 5.888157367706298828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Voracious Gorger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+90, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 627.20208740234375, -756.9000244140625, 1011.2825927734375, 1.879720687866210937, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+91, 234912, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 632.03472900390625, -751.74481201171875, 985.5904541015625, 3.504096508026123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+92, 234870, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 622.5360107421875, -758.696533203125, 1011.2825927734375, 0.7618943452835083, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+93, 234872, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 901.69793701171875, -704.02777099609375, 1001.55718994140625, 0.428333759307861328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1244327 - Bot AI Follow Advert, 42459 - Dual Wield)
(@CGUID+94, 234912, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 639.5867919921875, -722.4913330078125, 988.30303955078125, 0.880445301532745361, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+95, 234960, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 885.37518310546875, -704.7591552734375, 998.199462890625, 0.809664249420166015, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Tamed Ruinstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+96, 234962, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 814.07464599609375, -683.88714599609375, 999.703125, 0.385590583086013793, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant, 1244327 - Bot AI Follow Advert)
(@CGUID+97, 234960, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 809.05206298828125, -689.91143798828125, 1000.68609619140625, 1.082808256149291992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Tamed Ruinstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1244327 - Bot AI Follow Advert, 1247226 - [DNT] Sleeping)
(@CGUID+98, 234962, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 895.35418701171875, -708.48089599609375, 999.92730712890625, 0.254386216402053833, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant, 1244327 - Bot AI Follow Advert)
(@CGUID+99, 234960, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 691.96356201171875, -702.36285400390625, 995.595458984375, 2.697658538818359375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Tamed Ruinstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+100, 234872, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 816.685791015625, -688.83331298828125, 999.97222900390625, 1.009375333786010742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1244327 - Bot AI Follow Advert, 42459 - Dual Wield)
(@CGUID+101, 210931, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 670.3055419921875, -713.5867919921875, 994.13226318359375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+102, 234912, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 685.41839599609375, -699.748291015625, 995.82635498046875, 0.188532114028930664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+103, 234872, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 903.357666015625, -710.05731201171875, 1001.8350830078125, 1.271003246307373046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1244327 - Bot AI Follow Advert, 42459 - Dual Wield)
(@CGUID+104, 210931, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 637.0538330078125, -723.71527099609375, 987.07830810546875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+105, 234962, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 882.47918701171875, -702, 998.1539306640625, 0.809589266777038574, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant)
(@CGUID+106, 234960, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 879.58319091796875, -699.2408447265625, 998.168701171875, 0.808538317680358886, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Tamed Ruinstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@CGUID+107, 234957, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 820.36285400390625, -680.11456298828125, 998.5416259765625, 3.654708147048950195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Ritualist (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1244327 - Bot AI Follow Advert)
(@CGUID+108, 242631, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 651.73089599609375, -707.842041015625, 992.204833984375, 3.753707408905029296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Overcharged Sentinel (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1231234 - Protected Core)
(@CGUID+109, 234962, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 690.421875, -695.97052001953125, 995.88714599609375, 3.622674465179443359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant)
(@CGUID+110, 236995, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 579.76043701171875, -758.09027099609375, 999.7841796875, 6.270386219024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravenous Destroyer (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+111, 245411, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 645.35589599609375, -708.703125, 990.9678955078125, 1.049145936965942382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+112, 234912, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 636.185791015625, -719.02777099609375, 987.6904296875, 0.737778186798095703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+113, 242631, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 1, 751.89105224609375, -678.90765380859375, 993.6595458984375, 4.905517101287841796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Overcharged Sentinel (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: 1231234 - Protected Core, 18950 - Invisibility and Stealth Detection)
(@CGUID+114, 245411, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 0, 0, 649.0225830078125, -712.453125, 991.27947998046875, 1.049145936965942382, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+115, 234872, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 699.11981201171875, -670.95831298828125, 993.77081298828125, 3.962363004684448242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+116, 243716, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 752.083984375, -658.333984375, 993.85589599609375, 3.272621870040893554, 7200, 4, 0, 1, NULL, NULL, NULL, NULL, 62493), -- Skitterer (Area: Breached Dome - Difficulty: Normal) CreateObject1
(@CGUID+117, 248559, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 567.36114501953125, -751.0555419921875, 999.7843017578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- [DNT] 11.2 Dungeon - Sound Stalker - Boss 1 - Portal RP (Area: Breached Dome - Difficulty: Normal) CreateObject1
(@CGUID+118, 239223, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 643.9913330078125, -698.35418701171875, 993.80804443359375, 1.879618525505065917, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Devourer (Area: Breached Dome - Difficulty: Normal) CreateObject1
(@CGUID+119, 234872, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 703.89410400390625, -666.85418701171875, 993.76214599609375, 3.962363004684448242, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+120, 210930, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 580.87677001953125, -751.23614501953125, 1000.1116943359375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+121, 234962, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 874.87847900390625, -677.29864501953125, 998.5096435546875, 3.08336949348449707, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant, 1244327 - Bot AI Follow Advert)
(@CGUID+122, 234872, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 940.64581298828125, -699.66143798828125, 1005.19659423828125, 0.0114984642714262, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1244327 - Bot AI Follow Advert, 42459 - Dual Wield)
(@CGUID+123, 234960, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 850.34027099609375, -674.8055419921875, 997.90301513671875, 1.692969322204589843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Tamed Ruinstalker (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1244327 - Bot AI Follow Advert)
(@CGUID+124, 234962, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 941.015625, -704.045166015625, 1004.9996337890625, 1.135119199752807617, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant, 1244327 - Bot AI Follow Advert)
(@CGUID+125, 210931, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 859.1649169921875, -675.70831298828125, 998.75799560546875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 422357 - Bot AI Follow Advert)
(@CGUID+126, 236995, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 581.05206298828125, -741.3680419921875, 999.7841796875, 6.270386219024658203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravenous Destroyer (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+127, 234962, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 755.0694580078125, -652.421875, 993.73846435546875, 1.940891623497009277, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant)
(@CGUID+128, 234872, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 746.33331298828125, -654.08856201171875, 993.7344970703125, 0.603913307189941406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+129, 234957, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 697.23956298828125, -664.75347900390625, 993.75823974609375, 4.124239921569824218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Ritualist (Area: Breached Dome - Difficulty: Normal) CreateObject1
(@CGUID+130, 234872, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 710.90802001953125, -650.5555419921875, 993.5416259765625, 2.135839223861694335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+131, 234872, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 946.1632080078125, -699.11114501953125, 1005.27703857421875, 3.803048372268676757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1244327 - Bot AI Follow Advert, 42459 - Dual Wield)
(@CGUID+132, 234962, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 741.5, -648.857666015625, 993.72601318359375, 0.603913307189941406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant)
(@CGUID+133, 234872, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 740.140625, -642.232666015625, 994.3038330078125, 5.846123218536376953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+134, 244927, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 749.90972900390625, -645.67535400390625, 993.94268798828125, 3.539202690124511718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Terrified Broker (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1236653 - [DNT] Health Tracker Aura)
(@CGUID+135, 242631, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 862.83331298828125, -651.5, 997.859375, 4.220402240753173828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Overcharged Sentinel (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1231234 - Protected Core, 1244327 - Bot AI Follow Advert, 18950 - Invisibility and Stealth Detection)
(@CGUID+136, 239223, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 709.9600830078125, -645.75, 994.01385498046875, 0.950648367404937744, 7200, 0, 0, 0, NULL, 768, 1, 8193, 62493), -- Slain Devourer (Area: Breached Dome - Difficulty: Normal) CreateObject1
(@CGUID+137, 234872, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 715.23785400390625, -645.638916015625, 993.579833984375, 3.122590541839599609, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+138, 234872, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 856.89410400390625, -649.1319580078125, 997.68572998046875, 4.302438735961914062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1244327 - Bot AI Follow Advert, 42459 - Dual Wield)
(@CGUID+139, 210930, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 515.58331298828125, -746.99481201171875, 999.76617431640625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Path Helper (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 422354 - Bot AI Follow Advert)
(@CGUID+140, 245411, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 490.69964599609375, -775.06768798828125, 998.640625, 0.578041255474090576, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+141, 245412, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 492.414947509765625, -767.24481201171875, 999.579833984375, 4.937733173370361328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Voracious Gorger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+142, 245411, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 456.383697509765625, -800.37677001953125, 998.94964599609375, 0.578041255474090576, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+143, 245411, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 458.098968505859375, -792.5538330078125, 999.33160400390625, 4.937733173370361328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+144, 234872, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 813.248291015625, -632.59375, 1002.31512451171875, 2.858748912811279296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield)
(@CGUID+145, 237454, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 725.8524169921875, -851.14581298828125, 979.23175048828125, 5.712676525115966796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- [DNT] Stalker (Area: Breached Dome - Difficulty: Normal) CreateObject2 (Auras: 1217720 - [DNT] Spawn)
(@CGUID+146, 245411, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 433.444610595703125, -816.49407958984375, 998.8909912109375, 6.122391700744628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes) (possible waypoints or random movement)
(@CGUID+147, 245412, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 473.497406005859375, -747.42254638671875, 1000.48443603515625, 1.482788920402526855, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Voracious Gorger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+148, 245411, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 434.836822509765625, -790.83331298828125, 1000.5291748046875, 5.599171638488769531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+149, 245414, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 448.800079345703125, -795.41400146484375, 1016.30322265625, 0.063262484967708587, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Breached Dome - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+150, 245411, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 471.670135498046875, -703.234375, 999.453125, 0.578041255474090576, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+151, 245414, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 472.421051025390625, -735.558349609375, 1015.946533203125, 5.506346702575683593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Breached Dome - Difficulty: Normal) CreateObject1
(@CGUID+152, 245414, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 477.863067626953125, -733.7972412109375, 1015.946533203125, 5.494325637817382812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Invading Mite (Area: Breached Dome - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+153, 234962, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 817.701416015625, -625.38714599609375, 1002.64581298828125, 3.150900840759277343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Farstalker (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1220676 - [DNT] Cosmetic Weapon Enchant)
(@CGUID+154, 248600, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 865.86114501953125, -647.28643798828125, 1010.85333251953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- [DNT] 11.2 Dungeon - Sound Stalker - Boss 2 - Teleport RP (Area: Breached Dome - Difficulty: Normal) CreateObject1
(@CGUID+155, 239058, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 864.9305419921875, -647.4930419921875, 1008.15643310546875, 4.536348342895507812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Soul-Scribe (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1222797 - [DNT] Cosmetic Immune Aura)
(@CGUID+156, 245411, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 473.385406494140625, -695.41143798828125, 998.9229736328125, 4.937733173370361328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+157, 234893, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 436.888885498046875, -746, 1002.09259033203125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Azhiccar (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1227068 - [DNT] Devourer Vortex, 422356 - Bot AI Follow Advert)
(@CGUID+158, 234957, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 868.65277099609375, -652.40625, 998.20831298828125, 4.302438735961914062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Ritualist (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1244327 - Bot AI Follow Advert)
(@CGUID+159, 245411, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 437.541656494140625, -722.55206298828125, 1002.98089599609375, 1.353150010108947753, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+160, 245411, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 433.302093505859375, -715.76739501953125, 1002.14581298828125, 5.712842464447021484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+161, 245411, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 386.86083984375, -794.16546630859375, 999.38037109375, 1.789253473281860351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes) (possible waypoints or random movement)
(@CGUID+162, 245411, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 433.469970703125, -669.4910888671875, 1000.77911376953125, 0.166753813624382019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes) (possible waypoints or random movement)
(@CGUID+163, 245411, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 429.904327392578125, -671.2701416015625, 1001.05755615234375, 0.444461077451705932, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Ravaging Scavenger (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 1221130 - Consuming Strikes)
(@CGUID+164, 234957, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 837.54205322265625, -624.54974365234375, 998.758544921875, 4.241043567657470703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Ritualist (Area: Breached Dome - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+165, 234872, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 1, 834.34100341796875, -621.7811279296875, 998.89373779296875, 4.230411052703857421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493), -- Wastelander Phaseblade (Area: Breached Dome - Difficulty: Normal) CreateObject1 (Auras: 42459 - Dual Wield) (possible waypoints or random movement)
(@CGUID+166, 237454, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 0, 0, 655.95660400390625, -777.57989501953125, 980.73089599609375, 5.712676525115966796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 62493); -- [DNT] Stalker (Area: Breached Dome - Difficulty: Normal) CreateObject2 (Auras: 1217720 - [DNT] Spawn)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+166;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+4, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Slain Broker
(@CGUID+6, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '1221130'), -- Ravaging Scavenger - 1221130 - Consuming Strikes
(@CGUID+7, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Slain Broker
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1231497 1235558'), -- Overgorged Mite - 1231497 - Overgorged, 1235558 - [DNT] Devour Broker
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '1231497'), -- Overgorged Mite - 1231497 - Overgorged
(@CGUID+16, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Slain Broker
(@CGUID+18, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Slain Broker
(@CGUID+21, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Slain Broker
(@CGUID+24, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '1235612'), -- Slain Broker - 1235612 - [DNT] Broker Glow
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 700, 0, 0, 0, 0, '1231497'), -- Overgorged Mite - 1231497 - Overgorged
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 0, 32571, 0, 0, 0, '1236653'), -- Terrified Broker - 1236653 - [DNT] Health Tracker Aura
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 398, 0, 0, 0, 0, '1221130'), -- Voracious Gorger - 1221130 - Consuming Strikes
(@CGUID+30, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Slain Broker
(@CGUID+34, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Slain Broker
(@CGUID+36, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Slain Broker
(@CGUID+39, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Slain Broker
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 700, 0, 0, 0, 0, '1221130'), -- Ravaging Scavenger - 1221130 - Consuming Strikes
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 0, 21223, 0, 0, 0, '42459'), -- Wastelander Phaseblade - 42459 - Dual Wield
(@CGUID+46, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '1221130'), -- Voracious Gorger - 1221130 - Consuming Strikes
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '1221130'), -- Ravaging Scavenger - 1221130 - Consuming Strikes
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '1231497 1235558'), -- Overgorged Mite - 1231497 - Overgorged, 1235558 - [DNT] Devour Broker
(@CGUID+53, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '1231497'), -- Overgorged Mite - 1231497 - Overgorged
(@CGUID+58, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Slain Broker
(@CGUID+59, 0, 0, 0, 0, 0, 1, 0, 0, 21223, 0, 0, 0, ''), -- Wastelander Ritualist
(@CGUID+60, 0, 0, 0, 0, 0, 1, 0, 0, 21223, 0, 0, 0, '42459'), -- Wastelander Phaseblade - 42459 - Dual Wield
(@CGUID+62, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '1235612'), -- Slain Broker - 1235612 - [DNT] Broker Glow
(@CGUID+67, 0, 0, 0, 0, 0, 1, 0, 0, 21223, 0, 0, 0, '42459'), -- Wastelander Phaseblade - 42459 - Dual Wield
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '42459'), -- Wastelander Phaseblade - 42459 - Dual Wield
(@CGUID+70, 0, 0, 0, 0, 4, 1, 0, 0, 20902, 0, 0, 0, ''), -- Slain Devourer
(@CGUID+74, 0, 0, 0, 0, 0, 1, 0, 0, 21223, 0, 0, 0, '1220676'), -- Wastelander Farstalker - 1220676 - [DNT] Cosmetic Weapon Enchant
(@CGUID+77, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, '1231234 18950'), -- Overcharged Sentinel - 1231234 - Protected Core, 18950 - Invisibility and Stealth Detection
(@CGUID+79, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Slain Broker
(@CGUID+80, 0, 0, 0, 0, 0, 1, 0, 0, 21223, 0, 0, 0, '1220676'), -- Wastelander Farstalker - 1220676 - [DNT] Cosmetic Weapon Enchant
(@CGUID+81, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '42459'), -- Wastelander Phaseblade - 42459 - Dual Wield
(@CGUID+82, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '1221130'), -- Voracious Gorger - 1221130 - Consuming Strikes
(@CGUID+83, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '1221130'), -- Voracious Gorger - 1221130 - Consuming Strikes
(@CGUID+84, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- Slain Broker
(@CGUID+93, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, '1244327 42459'), -- Wastelander Phaseblade - 1244327 - Bot AI Follow Advert, 42459 - Dual Wield
(@CGUID+94, 0, 0, 0, 0, 0, 1, 0, 0, 20902, 0, 0, 0, '1221130'), -- Ravaging Scavenger - 1221130 - Consuming Strikes
(@CGUID+96, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '1220676 1244327'), -- Wastelander Farstalker - 1220676 - [DNT] Cosmetic Weapon Enchant, 1244327 - Bot AI Follow Advert
(@CGUID+97, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1244327 1247226'), -- Tamed Ruinstalker - 1244327 - Bot AI Follow Advert, 1247226 - [DNT] Sleeping
(@CGUID+99, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Tamed Ruinstalker
(@CGUID+100, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '1244327 42459'), -- Wastelander Phaseblade - 1244327 - Bot AI Follow Advert, 42459 - Dual Wield
(@CGUID+102, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '1221130'), -- Ravaging Scavenger - 1221130 - Consuming Strikes
(@CGUID+103, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '1244327 42459'), -- Wastelander Phaseblade - 1244327 - Bot AI Follow Advert, 42459 - Dual Wield
(@CGUID+108, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, '1231234'), -- Overcharged Sentinel - 1231234 - Protected Core
(@CGUID+109, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, '1220676'), -- Wastelander Farstalker - 1220676 - [DNT] Cosmetic Weapon Enchant
(@CGUID+110, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '18950'), -- Ravenous Destroyer - 18950 - Invisibility and Stealth Detection
(@CGUID+111, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Ravaging Scavenger
(@CGUID+112, 0, 0, 0, 0, 0, 1, 0, 0, 20902, 0, 0, 0, '1221130'), -- Ravaging Scavenger - 1221130 - Consuming Strikes
(@CGUID+114, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Ravaging Scavenger
(@CGUID+115, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '42459'), -- Wastelander Phaseblade - 42459 - Dual Wield
(@CGUID+118, 0, 0, 0, 0, 4, 1, 0, 0, 20902, 0, 0, 0, ''), -- Slain Devourer
(@CGUID+119, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, '42459'), -- Wastelander Phaseblade - 42459 - Dual Wield
(@CGUID+121, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1220676 1244327'), -- Wastelander Farstalker - 1220676 - [DNT] Cosmetic Weapon Enchant, 1244327 - Bot AI Follow Advert
(@CGUID+122, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, '1244327 42459'), -- Wastelander Phaseblade - 1244327 - Bot AI Follow Advert, 42459 - Dual Wield
(@CGUID+124, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1220676 1244327'), -- Wastelander Farstalker - 1220676 - [DNT] Cosmetic Weapon Enchant, 1244327 - Bot AI Follow Advert
(@CGUID+126, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, '18950'), -- Ravenous Destroyer - 18950 - Invisibility and Stealth Detection
(@CGUID+127, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, '1220676'), -- Wastelander Farstalker - 1220676 - [DNT] Cosmetic Weapon Enchant
(@CGUID+128, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '42459'), -- Wastelander Phaseblade - 42459 - Dual Wield
(@CGUID+129, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Wastelander Ritualist
(@CGUID+130, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '42459'), -- Wastelander Phaseblade - 42459 - Dual Wield
(@CGUID+131, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '1244327 42459'), -- Wastelander Phaseblade - 1244327 - Bot AI Follow Advert, 42459 - Dual Wield
(@CGUID+132, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, '1220676'), -- Wastelander Farstalker - 1220676 - [DNT] Cosmetic Weapon Enchant
(@CGUID+133, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '42459'), -- Wastelander Phaseblade - 42459 - Dual Wield
(@CGUID+134, 0, 0, 0, 0, 0, 1, 0, 0, 32571, 0, 0, 0, '1236653'), -- Terrified Broker - 1236653 - [DNT] Health Tracker Aura
(@CGUID+135, 0, 0, 0, 0, 0, 1, 0, 0, 21223, 0, 0, 0, '1231234 1244327 18950'), -- Overcharged Sentinel - 1231234 - Protected Core, 1244327 - Bot AI Follow Advert, 18950 - Invisibility and Stealth Detection
(@CGUID+136, 0, 0, 0, 0, 4, 1, 0, 0, 20902, 0, 0, 0, ''), -- Slain Devourer
(@CGUID+137, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '42459'), -- Wastelander Phaseblade - 42459 - Dual Wield
(@CGUID+138, 0, 0, 0, 0, 0, 1, 0, 0, 21223, 0, 0, 0, '1244327 42459'), -- Wastelander Phaseblade - 1244327 - Bot AI Follow Advert, 42459 - Dual Wield
(@CGUID+140, 0, 0, 0, 0, 0, 1, 0, 700, 0, 0, 0, 0, '1221130'), -- Ravaging Scavenger - 1221130 - Consuming Strikes
(@CGUID+141, 0, 0, 0, 0, 0, 1, 0, 700, 0, 0, 0, 0, '1221130'), -- Voracious Gorger - 1221130 - Consuming Strikes
(@CGUID+142, 0, 0, 0, 0, 0, 1, 0, 700, 0, 0, 0, 0, '1221130'), -- Ravaging Scavenger - 1221130 - Consuming Strikes
(@CGUID+143, 0, 0, 0, 0, 0, 1, 0, 700, 0, 0, 0, 0, '1221130'), -- Ravaging Scavenger - 1221130 - Consuming Strikes
(@CGUID+144, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '42459'), -- Wastelander Phaseblade - 42459 - Dual Wield
(@CGUID+150, 0, 0, 0, 0, 0, 1, 0, 700, 0, 0, 0, 0, '1221130'), -- Ravaging Scavenger - 1221130 - Consuming Strikes
(@CGUID+153, 0, 0, 0, 0, 0, 1, 0, 69, 0, 0, 0, 0, '1220676'), -- Wastelander Farstalker - 1220676 - [DNT] Cosmetic Weapon Enchant
(@CGUID+156, 0, 0, 0, 0, 0, 1, 0, 700, 0, 0, 0, 0, '1221130'), -- Ravaging Scavenger - 1221130 - Consuming Strikes
(@CGUID+157, 0, 0, 0, 0, 0, 1, 0, 0, 19254, 0, 0, 0, '1227068 422356'), -- Azhiccar - 1227068 - [DNT] Devourer Vortex, 422356 - Bot AI Follow Advert
(@CGUID+158, 0, 0, 0, 0, 0, 1, 0, 0, 21223, 0, 0, 0, '1244327'), -- Wastelander Ritualist - 1244327 - Bot AI Follow Advert
(@CGUID+159, 0, 0, 0, 0, 0, 1, 0, 700, 0, 0, 0, 0, '1221130'), -- Ravaging Scavenger - 1221130 - Consuming Strikes
(@CGUID+160, 0, 0, 0, 0, 0, 1, 0, 700, 0, 0, 0, 0, '1221130'); -- Ravaging Scavenger - 1221130 - Consuming Strikes

-- GameObjects
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+11;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 542637, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 789.623291015625, -979.3524169921875, 998.59503173828125, 0.052358884364366531, 0, 0, 0.02617645263671875, 0.999657332897186279, 7200, 255, 0, 62493), -- FrontDoor (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@OGUID+1, 252248, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 793.44268798828125, -1081.0867919921875, 1002.5723876953125, 1.529287099838256835, 0, 0, 0.692279815673828125, 0.721629142761230468, 7200, 255, 1, 62493), -- Instance Portal (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@OGUID+2, 526098, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 634.9600830078125, -711.4375, 988.60723876953125, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 7200, 255, 1, 62493), -- Forcefield (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@OGUID+3, 539740, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 900.67364501953125, -579.15277099609375, 999.1014404296875, 5.742135047912597656, 0, 0, -0.26723766326904296, 0.96363067626953125, 7200, 255, 1, 62493), -- Door02 (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@OGUID+4, 539742, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 564.69964599609375, -749.98956298828125, 999.9754638671875, 4.642578601837158203, 0, 0, -0.73135280609130859, 0.6819993257522583, 7200, 255, 0, 62493), -- Door01 (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@OGUID+5, 456468, 2830, 16104, 16104, '1,2,23,8,205', 0, 0, 875.49652099609375, -740.41668701171875, 998.40386962890625, 0, 0, 0, 0, 1, 7200, 255, 1, 62493), -- Collsion Blocker (Area: Eco-Dome Al'dani - Difficulty: Normal) CreateObject1
(@OGUID+6, 456468, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 896.23956298828125, -638.86114501953125, 1001.80450439453125, 0, 0, 0, 0, 1, 7200, 255, 1, 62493), -- Collsion Blocker (Area: Breached Dome - Difficulty: Normal) CreateObject1
(@OGUID+7, 456468, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 858.201416015625, -591.62152099609375, 998.35980224609375, 0, 0, 0, 0, 1, 7200, 255, 1, 62493), -- Collsion Blocker (Area: Breached Dome - Difficulty: Normal) CreateObject1
(@OGUID+8, 456468, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 897.05731201171875, -641.27081298828125, 1002.7979736328125, 0, 0, 0, 0, 1, 7200, 255, 1, 62493), -- Collsion Blocker (Area: Breached Dome - Difficulty: Normal) CreateObject1
(@OGUID+9, 456468, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 898.86114501953125, -638.4444580078125, 1002.20587158203125, 0, 0, 0, 0, 1, 7200, 255, 1, 62493), -- Collsion Blocker (Area: Breached Dome - Difficulty: Normal) CreateObject1
(@OGUID+10, 456468, 2830, 16104, 16419, '1,2,23,8,205', 0, 0, 894.421875, -617.34375, 998.1737060546875, 0, 0, 0, 0, 1, 7200, 255, 1, 62493), -- Collsion Blocker (Area: Breached Dome - Difficulty: Normal) CreateObject1
(@OGUID+11, 246779, 2830, 16104, 16104, '23', 0, 0, 785.6649169921875, -1027.0521240234375, 999.92327880859375, 0, 0, 0, 0, 1, 7200, 255, 1, 62493); -- Font of Power (Area: Eco-Dome Al'dani - Difficulty: Mythic) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+11;

-- Areatrigger
DELETE FROM `areatrigger` WHERE `SpawnId` BETWEEN @ATSPAWNID+0 AND @ATSPAWNID+3;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerCreatePropertiesId`, `IsCustom`, `MapId`, `SpawnDifficulties`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Comment`, `VerifiedBuild`) VALUES
(@ATSPAWNID+0, @ATPROPERTIESID+0, 1, 2830, '1,2,23,8,205', 661.47393798828125, -773.38018798828125, 981.27960205078125, 0, 0, '26060', 0, '', 62493), -- (Area: Devastated Annex - Difficulty: Normal)
(@ATSPAWNID+1, @ATPROPERTIESID+0, 1, 2830, '1,2,23,8,205', 701.87847900390625, -882.42706298828125, 985.9249267578125, 0, 0, '26060', 0, '', 62493), -- (Area: Devastated Annex - Difficulty: Normal)
(@ATSPAWNID+2, @ATPROPERTIESID+0, 1, 2830, '1,2,23,8,205', 746.0867919921875, -858.748291015625, 978.57452392578125, 0, 0, '26060', 0, '', 62493), -- (Area: Devastated Annex - Difficulty: Normal)
(@ATSPAWNID+3, @ATPROPERTIESID+0, 1, 2830, '1,2,23,8,205', 797.4305419921875, -880.33856201171875, 991.81378173828125, 0, 0, '26060', 0, '', 62493); -- (Area: Devastated Annex - Difficulty: Normal)

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=1 AND `Id`=@ATPROPERTIESID+0);
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(@ATPROPERTIESID+0, 1, 6197, 0, 0, 0, 0, 0, 0, -1, 0, 0, 1235695, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 62493); -- SpellForVisuals: 1235695 ([DNT] Ccsmetic Fire)

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (234933 /*234933 (Taah'bat) - Ride Vehicle Hardcoded, [DNT] Boss 02 Hiding Aura*/, 237514 /*237514 (A'wazj) - [DNT] Boss 02 Hiding Aura*/, 238392 /*238392 (Ve'nari)*/, 234960 /*234960 (Tamed Ruinstalker) - Bot AI Follow Advert, [DNT] Sleeping*/, 234957 /*234957 (Wastelander Ritualist) - Bot AI Follow Advert*/, 244927 /*244927 (Terrified Broker) - [DNT] Health Tracker Aura*/, 234872 /*234872 (Wastelander Phaseblade) - Dual Wield*/, 242209 /*242209 (Overgorged Mite) - Overgorged, [DNT] Devour Broker*/, 239223 /*239223 (Slain Devourer)*/, 234962 /*234962 (Wastelander Farstalker) - [DNT] Cosmetic Weapon Enchant*/, 234893 /*234893 (Azhiccar) - [DNT] Devourer Vortex, Bot AI Follow Advert*/, 242631 /*242631 (Overcharged Sentinel) - Protected Core, Invisibility and Stealth Detection*/, 234883 /*234883 (Voracious Gorger) - Consuming Strikes*/, 235127 /*235127 (Slain Broker)*/, 236995 /*236995 (Ravenous Destroyer) - Invisibility and Stealth Detection*/, 234870 /*234870 (Invading Mite)*/, 234912 /*234912 (Ravaging Scavenger) - Consuming Strikes*/, 248559 /*248559 ([DNT] 11.2 Dungeon - Sound Stalker - Boss 1 - Portal RP)*/, 245411 /*245411 (Ravaging Scavenger) - Consuming Strikes*/, 248600 /*248600 ([DNT] 11.2 Dungeon - Sound Stalker - Boss 2 - Teleport RP)*/, 239058 /*239058 (Soul-Scribe) - [DNT] Cosmetic Immune Aura*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(234933, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1241865'), -- 234933 (Taah'bat) - Ride Vehicle Hardcoded, [DNT] Boss 02 Hiding Aura
(237514, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '1241865'), -- 237514 (A'wazj) - [DNT] Boss 02 Hiding Aura
(238392, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 238392 (Ve'nari)
(234960, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1244327'), -- 234960 (Tamed Ruinstalker) - Bot AI Follow Advert
(234957, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1244327'), -- 234957 (Wastelander Ritualist) - Bot AI Follow Advert
(244927, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1236653'), -- 244927 (Terrified Broker) - [DNT] Health Tracker Aura
(234872, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '42459'), -- 234872 (Wastelander Phaseblade) - Dual Wield
(242209, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1231497 1235558'), -- 242209 (Overgorged Mite) - Overgorged, [DNT] Devour Broker
(239223, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- 239223 (Slain Devourer)
(234962, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1220676'), -- 234962 (Wastelander Farstalker) - [DNT] Cosmetic Weapon Enchant
(234893, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1227068 422356'), -- 234893 (Azhiccar) - [DNT] Devourer Vortex, Bot AI Follow Advert
(242631, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1231234 18950'), -- 242631 (Overcharged Sentinel) - Protected Core, Invisibility and Stealth Detection
(234883, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1221130'), -- 234883 (Voracious Gorger) - Consuming Strikes
(235127, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, ''), -- 235127 (Slain Broker)
(236995, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '18950'), -- 236995 (Ravenous Destroyer) - Invisibility and Stealth Detection
(234870, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 234870 (Invading Mite)
(234912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1221130'), -- 234912 (Ravaging Scavenger) - Consuming Strikes
(248559, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 248559 ([DNT] 11.2 Dungeon - Sound Stalker - Boss 1 - Portal RP)
(245411, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '1221130'), -- 245411 (Ravaging Scavenger) - Consuming Strikes
(248600, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 248600 ([DNT] 11.2 Dungeon - Sound Stalker - Boss 2 - Teleport RP)
(239058, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '1222797'); -- 239058 (Soul-Scribe) - [DNT] Cosmetic Immune Aura

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (539742 /*Door01*/, 539740 /*Door02*/, 526098 /*Forcefield*/, 542637 /*FrontDoor*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(539742, 0, 0x30, 0, 0), -- Door01
(539740, 0, 0x30, 0, 0), -- Door02
(526098, 0, 0x30, 0, 0), -- Forcefield
(542637, 0, 0x30, 0, 0); -- FrontDoor

-- Template
DELETE FROM `gameobject_template` WHERE `entry` IN (539740 /*Door02*/, 539742 /*Door01*/, 526098 /*Forcefield*/, 542637 /*FrontDoor*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(539740, 0, 105472, 'Door02', '', '', '', 5.071774959564208984, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62493), -- Door02
(539742, 0, 105472, 'Door01', '', '', '', 4.941481590270996093, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62493), -- Door01
(526098, 0, 108088, 'Forcefield', '', '', '', 1.484811305999755859, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62493), -- Forcefield
(542637, 0, 105472, 'FrontDoor', '', '', '', 5.20880889892578125, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 62493); -- FrontDoor

UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000340, `unit_flags3`=0x40000000 WHERE `entry`=234893; -- Azhiccar
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=239058; -- Soul-Scribe
UPDATE `creature_template` SET `faction`=35, `speed_walk`=3.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `unit_flags3`=0x1000000, `flags_extra` = 128 WHERE `entry`=248600; -- [DNT] 11.2 Dungeon - Sound Stalker - Boss 2 - Teleport RP
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=245414; -- Invading Mite
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x4000800, `unit_flags3`=0x1000001, `flags_extra` = 128 WHERE `entry`=237454; -- [DNT] Stalker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry` IN (245412, 234883); -- Voracious Gorger
UPDATE `creature_template` SET `faction`=35, `speed_walk`=3.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=0x2000100, `unit_flags2`=0x800, `unit_flags3`=0x1000000, `flags_extra` = 128 WHERE `entry`=248559; -- [DNT] 11.2 Dungeon - Sound Stalker - Boss 1 - Portal RP
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry` IN (245411, 234912); -- Ravaging Scavenger
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x2000140, `unit_flags2`=0x800, `unit_flags3`=0x800001 WHERE `entry`=234933; -- Taah'bat
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=0x2000140, `unit_flags3`=0x800001, `VehicleId`=8855 WHERE `entry`=237514; -- A'wazj
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x2000340, `unit_flags2`=0x800, `unit_flags3`=0x81000000 WHERE `entry`=239223; -- Slain Devourer
UPDATE `creature_template` SET `faction`=14, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=234960; -- Tamed Ruinstalker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=234957; -- Wastelander Ritualist
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=234962; -- Wastelander Farstalker
UPDATE `creature_template` SET `faction`=16, `speed_run`=0.992062866687774658, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=242631; -- Overcharged Sentinel
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=236995; -- Ravenous Destroyer
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=234872; -- Wastelander Phaseblade
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=244927; -- Terrified Broker
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=243721; -- Hoplet
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=0x820, `unit_flags3`=0x400001 WHERE `entry`=238392; -- Ve'nari
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.799999952316284179, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=234870; -- Invading Mite
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x2000300, `unit_flags2`=0x4000000, `unit_flags3`=0x41008001, `flags_extra` = 128 WHERE `entry`=247930; -- Helper
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x80000 WHERE `entry`=244639; -- Terrified Broker
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x2000340, `unit_flags2`=0x800, `unit_flags3`=0x81000000 WHERE `entry`=235127; -- Slain Broker
UPDATE `creature_template` SET `faction`=190, `speed_walk`=2.388887882232666015, `speed_run`=1.38888859748840332, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x1 WHERE `entry`=243716; -- Skitterer
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2.799999952316284179, `speed_run`=1.428571462631225585, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800 WHERE `entry`=242209; -- Overgorged Mite

-- Difficulty (Normal)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (234893,239058,248600,245414,237454,245412,248559,245411,234933,237514,239223,234960,234957,234962,242631,236995,234872,234883,244927,243721,238392,234870,247930,244639,235127,243716,234912,242209));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(234893, 1, 2, 2, 2718, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234893 (Azhiccar) - Sessile, CanSwim, Floating
(239058, 1, 2, 2, 2718, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 239058 (Soul-Scribe) - CanSwim, Floating
(248600, 1, 0, 0, 2057, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 248600 ([DNT] 11.2 Dungeon - Sound Stalker - Boss 2 - Teleport RP) - CanSwim, Floating
(245414, 1, 0, 0, 2718, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 245414 (Invading Mite) - CanSwim, Floating
(237454, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 237454 ([DNT] Stalker) - CanSwim
(245412, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 245412 (Voracious Gorger) - CanSwim
(248559, 1, 0, 0, 2057, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 248559 ([DNT] 11.2 Dungeon - Sound Stalker - Boss 1 - Portal RP) - CanSwim, Floating
(245411, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 245411 (Ravaging Scavenger) - CanSwim
(234933, 1, 2, 2, 2718, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234933 (Taah'bat) - Sessile, CanSwim, Floating
(237514, 1, 2, 2, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 237514 (A'wazj) - CanSwim
(239223, 1, 0, 0, 2718, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 239223 (Slain Devourer) - 
(234960, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234960 (Tamed Ruinstalker) - CanSwim
(234957, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234957 (Wastelander Ritualist) - CanSwim
(234962, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234962 (Wastelander Farstalker) - CanSwim
(242631, 1, 1, 1, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 242631 (Overcharged Sentinel) - CanSwim
(236995, 1, 1, 1, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 236995 (Ravenous Destroyer) - CanSwim
(234872, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234872 (Wastelander Phaseblade) - CanSwim
(234883, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234883 (Voracious Gorger) - CanSwim
(244927, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 244927 (Terrified Broker) - CanSwim
(243721, 1, 0, 0, 81, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 243721 (Hoplet) - 
(238392, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 238392 (Ve'nari) - CanSwim
(234870, 1, 0, 0, 2718, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234870 (Invading Mite) - CanSwim, Floating
(247930, 1, 0, 0, 2718, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 247930 (Helper) - Sessile, CanSwim, Floating
(244639, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 244639 (Terrified Broker) - CanSwim
(235127, 1, 0, 0, 2718, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 235127 (Slain Broker) - 
(243716, 1, 0, 0, 81, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 243716 (Skitterer) - 
(234912, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234912 (Ravaging Scavenger) - CanSwim
(242209, 1, 0, 0, 2718, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493); -- 242209 (Overgorged Mite) - CanSwim

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.100000001490116119, `CreatureDifficultyID`=328135, `TypeFlags`=0x40000000 WHERE (`Entry`=248600 AND `DifficultyID`=1); -- [DNT] 11.2 Dungeon - Sound Stalker - Boss 2 - Teleport RP
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=50, `CreatureDifficultyID`=318177 WHERE (`Entry`=239058 AND `DifficultyID`=1); -- Soul-Scribe
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=31.5, `CreatureDifficultyID`=313601, `TypeFlags`=0x200068, `TypeFlags2`=128 WHERE (`Entry`=234893 AND `DifficultyID`=1); -- Azhiccar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=324810, `TypeFlags`=0x200048 WHERE (`Entry`=245414 AND `DifficultyID`=1); -- Invading Mite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=10, `CreatureDifficultyID`=316392, `TypeFlags`=0x40200048, `TypeFlags2`=128 WHERE (`Entry`=237454 AND `DifficultyID`=1); -- [DNT] Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=6, `CreatureDifficultyID`=324808, `TypeFlags`=0x200048 WHERE (`Entry`=245412 AND `DifficultyID`=1); -- Voracious Gorger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.100000001490116119, `CreatureDifficultyID`=328094, `TypeFlags`=0x40000000 WHERE (`Entry`=248559 AND `DifficultyID`=1); -- [DNT] 11.2 Dungeon - Sound Stalker - Boss 1 - Portal RP
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=324807, `TypeFlags`=0x200048 WHERE (`Entry`=245411 AND `DifficultyID`=1); -- Ravaging Scavenger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=35, `CreatureDifficultyID`=316452, `TypeFlags`=0x200068, `TypeFlags2`=128 WHERE (`Entry`=237514 AND `DifficultyID`=1); -- A'wazj
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=35, `CreatureDifficultyID`=313643, `TypeFlags`=0x200068, `TypeFlags2`=128 WHERE (`Entry`=234933 AND `DifficultyID`=1); -- Taah'bat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=318365, `TypeFlags`=0x200048 WHERE (`Entry`=239223 AND `DifficultyID`=1); -- Slain Devourer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313678, `TypeFlags`=0x200048 WHERE (`Entry`=234960 AND `DifficultyID`=1); -- Tamed Ruinstalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=4, `CreatureDifficultyID`=313675, `TypeFlags`=0x200048 WHERE (`Entry`=234957 AND `DifficultyID`=1); -- Wastelander Ritualist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313680, `TypeFlags`=0x200048 WHERE (`Entry`=234962 AND `DifficultyID`=1); -- Wastelander Farstalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=8, `CreatureDifficultyID`=322037, `TypeFlags`=0x200048 WHERE (`Entry`=242631 AND `DifficultyID`=1); -- Overcharged Sentinel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313576, `TypeFlags`=0x200048 WHERE (`Entry`=234872 AND `DifficultyID`=1); -- Wastelander Phaseblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=8, `CreatureDifficultyID`=315899, `TypeFlags`=0x200048 WHERE (`Entry`=236995 AND `DifficultyID`=1); -- Ravenous Destroyer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=323146 WHERE (`Entry`=243721 AND `DifficultyID`=1); -- Hoplet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.25, `CreatureDifficultyID`=324282, `TypeFlags`=0x1000 WHERE (`Entry`=244927 AND `DifficultyID`=1); -- Terrified Broker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=6, `CreatureDifficultyID`=313591, `TypeFlags`=0x200048 WHERE (`Entry`=234883 AND `DifficultyID`=1); -- Voracious Gorger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=313574, `TypeFlags`=0x200048 WHERE (`Entry`=234870 AND `DifficultyID`=1); -- Invading Mite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313620, `TypeFlags`=0x200048 WHERE (`Entry`=234912 AND `DifficultyID`=1); -- Ravaging Scavenger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=323985 WHERE (`Entry`=244639 AND `DifficultyID`=1); -- Terrified Broker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313845, `TypeFlags`=0x200048 WHERE (`Entry`=235127 AND `DifficultyID`=1); -- Slain Broker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=4, `CreatureDifficultyID`=321500, `TypeFlags`=0x200048 WHERE (`Entry`=242209 AND `DifficultyID`=1); -- Overgorged Mite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=323141 WHERE (`Entry`=243716 AND `DifficultyID`=1); -- Skitterer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=50, `CreatureDifficultyID`=317373 WHERE (`Entry`=238392 AND `DifficultyID`=1); -- Ve'nari
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=327449, `TypeFlags`=0x40200048, `TypeFlags2`=34 WHERE (`Entry`=247930 AND `DifficultyID`=1); -- Helper

-- Difficulty (Heroic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (248600,239058,234893,245414,237454,245412,248559,245411,234933,237514,239223,234960,234957,234872,234962,242631,236995,244927,243721,234883,238392,243716,244639,242209,234912,247930,234870,235127));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(248600, 2, 0, 0, 2057, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 248600 ([DNT] 11.2 Dungeon - Sound Stalker - Boss 2 - Teleport RP) - CanSwim, Floating
(239058, 2, 2, 2, 2720, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 239058 (Soul-Scribe) - CanSwim, Floating
(234893, 2, 2, 2, 2720, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234893 (Azhiccar) - Sessile, CanSwim, Floating
(245414, 2, 0, 0, 2720, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 245414 (Invading Mite) - CanSwim, Floating
(237454, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 237454 ([DNT] Stalker) - CanSwim
(245412, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 245412 (Voracious Gorger) - CanSwim
(248559, 2, 0, 0, 2057, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 248559 ([DNT] 11.2 Dungeon - Sound Stalker - Boss 1 - Portal RP) - CanSwim, Floating
(245411, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 245411 (Ravaging Scavenger) - CanSwim
(234933, 2, 2, 2, 2720, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234933 (Taah'bat) - Sessile, CanSwim, Floating
(237514, 2, 2, 2, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 237514 (A'wazj) - CanSwim
(239223, 2, 0, 0, 2720, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 239223 (Slain Devourer) - 
(234960, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234960 (Tamed Ruinstalker) - CanSwim
(234957, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234957 (Wastelander Ritualist) - CanSwim
(234872, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234872 (Wastelander Phaseblade) - CanSwim
(234962, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234962 (Wastelander Farstalker) - CanSwim
(242631, 2, 1, 1, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 242631 (Overcharged Sentinel) - CanSwim
(236995, 2, 1, 1, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 236995 (Ravenous Destroyer) - CanSwim
(244927, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 244927 (Terrified Broker) - CanSwim
(243721, 2, 0, 0, 81, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 243721 (Hoplet) - 
(234883, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234883 (Voracious Gorger) - CanSwim
(238392, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 238392 (Ve'nari) - CanSwim
(243716, 2, 0, 0, 81, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 243716 (Skitterer) - 
(244639, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 244639 (Terrified Broker) - CanSwim
(242209, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 242209 (Overgorged Mite) - CanSwim
(234912, 2, 0, 0, 2720, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234912 (Ravaging Scavenger) - CanSwim
(247930, 2, 0, 0, 2720, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 247930 (Helper) - Sessile, CanSwim, Floating
(234870, 2, 0, 0, 2720, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234870 (Invading Mite) - CanSwim, Floating
(235127, 2, 0, 0, 2720, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493); -- 235127 (Slain Broker) - 

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.100000001490116119, `CreatureDifficultyID`=328135, `TypeFlags`=0x40000000 WHERE (`Entry`=248600 AND `DifficultyID`=2); -- [DNT] 11.2 Dungeon - Sound Stalker - Boss 2 - Teleport RP
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=50, `CreatureDifficultyID`=318177 WHERE (`Entry`=239058 AND `DifficultyID`=2); -- Soul-Scribe
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=324810, `TypeFlags`=0x200048 WHERE (`Entry`=245414 AND `DifficultyID`=2); -- Invading Mite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=31.5, `CreatureDifficultyID`=313601, `TypeFlags`=0x200068, `TypeFlags2`=128 WHERE (`Entry`=234893 AND `DifficultyID`=2); -- Azhiccar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=10, `CreatureDifficultyID`=316392, `TypeFlags`=0x40200048, `TypeFlags2`=128 WHERE (`Entry`=237454 AND `DifficultyID`=2); -- [DNT] Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=6, `CreatureDifficultyID`=324808, `TypeFlags`=0x200048 WHERE (`Entry`=245412 AND `DifficultyID`=2); -- Voracious Gorger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.100000001490116119, `CreatureDifficultyID`=328094, `TypeFlags`=0x40000000 WHERE (`Entry`=248559 AND `DifficultyID`=2); -- [DNT] 11.2 Dungeon - Sound Stalker - Boss 1 - Portal RP
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=324807, `TypeFlags`=0x200048 WHERE (`Entry`=245411 AND `DifficultyID`=2); -- Ravaging Scavenger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=35, `CreatureDifficultyID`=316452, `TypeFlags`=0x200068, `TypeFlags2`=128 WHERE (`Entry`=237514 AND `DifficultyID`=2); -- A'wazj
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=35, `CreatureDifficultyID`=313643, `TypeFlags`=0x200068, `TypeFlags2`=128 WHERE (`Entry`=234933 AND `DifficultyID`=2); -- Taah'bat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=318365, `TypeFlags`=0x200048 WHERE (`Entry`=239223 AND `DifficultyID`=2); -- Slain Devourer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313680, `TypeFlags`=0x200048 WHERE (`Entry`=234962 AND `DifficultyID`=2); -- Wastelander Farstalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313678, `TypeFlags`=0x200048 WHERE (`Entry`=234960 AND `DifficultyID`=2); -- Tamed Ruinstalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=4, `CreatureDifficultyID`=313675, `TypeFlags`=0x200048 WHERE (`Entry`=234957 AND `DifficultyID`=2); -- Wastelander Ritualist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313576, `TypeFlags`=0x200048 WHERE (`Entry`=234872 AND `DifficultyID`=2); -- Wastelander Phaseblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=8, `CreatureDifficultyID`=315899, `TypeFlags`=0x200048 WHERE (`Entry`=236995 AND `DifficultyID`=2); -- Ravenous Destroyer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=8, `CreatureDifficultyID`=322037, `TypeFlags`=0x200048 WHERE (`Entry`=242631 AND `DifficultyID`=2); -- Overcharged Sentinel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.25, `CreatureDifficultyID`=324282, `TypeFlags`=0x1000 WHERE (`Entry`=244927 AND `DifficultyID`=2); -- Terrified Broker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=323146 WHERE (`Entry`=243721 AND `DifficultyID`=2); -- Hoplet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=6, `CreatureDifficultyID`=313591, `TypeFlags`=0x200048 WHERE (`Entry`=234883 AND `DifficultyID`=2); -- Voracious Gorger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=313574, `TypeFlags`=0x200048 WHERE (`Entry`=234870 AND `DifficultyID`=2); -- Invading Mite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313620, `TypeFlags`=0x200048 WHERE (`Entry`=234912 AND `DifficultyID`=2); -- Ravaging Scavenger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=323985 WHERE (`Entry`=244639 AND `DifficultyID`=2); -- Terrified Broker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313845, `TypeFlags`=0x200048 WHERE (`Entry`=235127 AND `DifficultyID`=2); -- Slain Broker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=4, `CreatureDifficultyID`=321500, `TypeFlags`=0x200048 WHERE (`Entry`=242209 AND `DifficultyID`=2); -- Overgorged Mite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=323141 WHERE (`Entry`=243716 AND `DifficultyID`=2); -- Skitterer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=50, `CreatureDifficultyID`=317373 WHERE (`Entry`=238392 AND `DifficultyID`=2); -- Ve'nari
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=327449, `TypeFlags`=0x40200048, `TypeFlags2`=34 WHERE (`Entry`=247930 AND `DifficultyID`=2); -- Helper

-- Difficulty (Mythic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (234893,248600,239058,237454,245414,245412,248559,245411,234933,237514,239223,234957,234962,234960,242631,236995,234872,244927,210931,243721,234883,211137,211111,238392,211150,234912,211151,234870,243716,235127,211149,247930,244639,242209,211152,210930));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(234893, 23, 2, 2, 2722, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234893 (Azhiccar) - Sessile, CanSwim, Floating
(248600, 23, 0, 0, 2057, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 248600 ([DNT] 11.2 Dungeon - Sound Stalker - Boss 2 - Teleport RP) - CanSwim, Floating
(239058, 23, 2, 2, 2722, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 239058 (Soul-Scribe) - CanSwim, Floating
(237454, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 237454 ([DNT] Stalker) - CanSwim
(245414, 23, 0, 0, 2722, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 245414 (Invading Mite) - CanSwim, Floating
(245412, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 245412 (Voracious Gorger) - CanSwim
(248559, 23, 0, 0, 2057, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 248559 ([DNT] 11.2 Dungeon - Sound Stalker - Boss 1 - Portal RP) - CanSwim, Floating
(245411, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 245411 (Ravaging Scavenger) - CanSwim
(234933, 23, 2, 2, 2722, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234933 (Taah'bat) - Sessile, CanSwim, Floating
(237514, 23, 2, 2, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 237514 (A'wazj) - CanSwim
(239223, 23, 0, 0, 2722, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 239223 (Slain Devourer) - 
(234957, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234957 (Wastelander Ritualist) - CanSwim
(234962, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234962 (Wastelander Farstalker) - CanSwim
(234960, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234960 (Tamed Ruinstalker) - CanSwim
(242631, 23, 1, 1, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 242631 (Overcharged Sentinel) - CanSwim
(236995, 23, 1, 1, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 236995 (Ravenous Destroyer) - CanSwim
(234872, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234872 (Wastelander Phaseblade) - CanSwim
(244927, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 244927 (Terrified Broker) - CanSwim
(210931, 23, 0, 0, 2702, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 210931 (Path Helper) - Sessile, CanSwim, Floating
(243721, 23, 0, 0, 81, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 243721 (Hoplet) - 
(234883, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234883 (Voracious Gorger) - CanSwim
(211137, 23, 0, 0, 2702, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 211137 (Path Helper) - Sessile, CanSwim, Floating
(211111, 23, 0, 0, 2702, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 211111 (Path Helper) - Sessile, CanSwim, Floating
(238392, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 238392 (Ve'nari) - CanSwim
(211150, 23, 0, 0, 2702, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 211150 (Path Helper) - Sessile, CanSwim, Floating
(234912, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234912 (Ravaging Scavenger) - CanSwim
(211151, 23, 0, 0, 2702, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 211151 (Path Helper) - Sessile, CanSwim, Floating
(234870, 23, 0, 0, 2722, 0x30000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 234870 (Invading Mite) - CanSwim, Floating
(243716, 23, 0, 0, 81, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 243716 (Skitterer) - 
(235127, 23, 0, 0, 2722, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 235127 (Slain Broker) - 
(211149, 23, 0, 0, 2702, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 211149 (Path Helper) - Sessile, CanSwim, Floating
(247930, 23, 0, 0, 2722, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 247930 (Helper) - Sessile, CanSwim, Floating
(244639, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 244639 (Terrified Broker) - CanSwim
(242209, 23, 0, 0, 2722, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 242209 (Overgorged Mite) - CanSwim
(211152, 23, 0, 0, 2702, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493), -- 211152 (Path Helper) - Sessile, CanSwim, Floating
(210930, 23, 0, 0, 2702, 0x30000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 62493); -- 210930 (Path Helper) - Sessile, CanSwim, Floating

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=31.5, `CreatureDifficultyID`=313601, `TypeFlags`=0x200068, `TypeFlags2`=128 WHERE (`Entry`=234893 AND `DifficultyID`=23); -- Azhiccar
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.100000001490116119, `CreatureDifficultyID`=328135, `TypeFlags`=0x40000000 WHERE (`Entry`=248600 AND `DifficultyID`=23); -- [DNT] 11.2 Dungeon - Sound Stalker - Boss 2 - Teleport RP
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=50, `CreatureDifficultyID`=318177 WHERE (`Entry`=239058 AND `DifficultyID`=23); -- Soul-Scribe
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=10, `CreatureDifficultyID`=316392, `TypeFlags`=0x40200048, `TypeFlags2`=128 WHERE (`Entry`=237454 AND `DifficultyID`=23); -- [DNT] Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=324810, `TypeFlags`=0x200048 WHERE (`Entry`=245414 AND `DifficultyID`=23); -- Invading Mite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=6, `CreatureDifficultyID`=324808, `TypeFlags`=0x200048 WHERE (`Entry`=245412 AND `DifficultyID`=23); -- Voracious Gorger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.100000001490116119, `CreatureDifficultyID`=328094, `TypeFlags`=0x40000000 WHERE (`Entry`=248559 AND `DifficultyID`=23); -- [DNT] 11.2 Dungeon - Sound Stalker - Boss 1 - Portal RP
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=324807, `TypeFlags`=0x200048 WHERE (`Entry`=245411 AND `DifficultyID`=23); -- Ravaging Scavenger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=35, `CreatureDifficultyID`=316452, `TypeFlags`=0x200068, `TypeFlags2`=128 WHERE (`Entry`=237514 AND `DifficultyID`=23); -- A'wazj
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=35, `CreatureDifficultyID`=313643, `TypeFlags`=0x200068, `TypeFlags2`=128 WHERE (`Entry`=234933 AND `DifficultyID`=23); -- Taah'bat
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=318365, `TypeFlags`=0x200048 WHERE (`Entry`=239223 AND `DifficultyID`=23); -- Slain Devourer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313680, `TypeFlags`=0x200048 WHERE (`Entry`=234962 AND `DifficultyID`=23); -- Wastelander Farstalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=4, `CreatureDifficultyID`=313675, `TypeFlags`=0x200048 WHERE (`Entry`=234957 AND `DifficultyID`=23); -- Wastelander Ritualist
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313678, `TypeFlags`=0x200048 WHERE (`Entry`=234960 AND `DifficultyID`=23); -- Tamed Ruinstalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.25, `CreatureDifficultyID`=324282, `TypeFlags`=0x1000 WHERE (`Entry`=244927 AND `DifficultyID`=23); -- Terrified Broker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313576, `TypeFlags`=0x200048 WHERE (`Entry`=234872 AND `DifficultyID`=23); -- Wastelander Phaseblade
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=8, `CreatureDifficultyID`=315899, `TypeFlags`=0x200048 WHERE (`Entry`=236995 AND `DifficultyID`=23); -- Ravenous Destroyer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=8, `CreatureDifficultyID`=322037, `TypeFlags`=0x200048 WHERE (`Entry`=242631 AND `DifficultyID`=23); -- Overcharged Sentinel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=260280, `TypeFlags`=0x40200048, `TypeFlags2`=34 WHERE (`Entry`=210931 AND `DifficultyID`=23); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=323146 WHERE (`Entry`=243721 AND `DifficultyID`=23); -- Hoplet
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=6, `CreatureDifficultyID`=313591, `TypeFlags`=0x200048 WHERE (`Entry`=234883 AND `DifficultyID`=23); -- Voracious Gorger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=313574, `TypeFlags`=0x200048 WHERE (`Entry`=234870 AND `DifficultyID`=23); -- Invading Mite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313620, `TypeFlags`=0x200048 WHERE (`Entry`=234912 AND `DifficultyID`=23); -- Ravaging Scavenger
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=323985 WHERE (`Entry`=244639 AND `DifficultyID`=23); -- Terrified Broker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=5, `CreatureDifficultyID`=313845, `TypeFlags`=0x200048 WHERE (`Entry`=235127 AND `DifficultyID`=23); -- Slain Broker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=4, `CreatureDifficultyID`=321500, `TypeFlags`=0x200048 WHERE (`Entry`=242209 AND `DifficultyID`=23); -- Overgorged Mite
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=0.200000002980232238, `CreatureDifficultyID`=323141 WHERE (`Entry`=243716 AND `DifficultyID`=23); -- Skitterer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=260279, `TypeFlags`=0x40200048, `TypeFlags2`=34 WHERE (`Entry`=210930 AND `DifficultyID`=23); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `HealthModifier`=50, `CreatureDifficultyID`=317373 WHERE (`Entry`=238392 AND `DifficultyID`=23); -- Ve'nari
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=273091 WHERE (`Entry`=171322 AND `DifficultyID`=23); -- Global Affix Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=327449, `TypeFlags`=0x40200048, `TypeFlags2`=34 WHERE (`Entry`=247930 AND `DifficultyID`=23); -- Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=260503, `TypeFlags`=0x40200048, `TypeFlags2`=34 WHERE (`Entry`=211152 AND `DifficultyID`=23); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=260502, `TypeFlags`=0x40200048, `TypeFlags2`=34 WHERE (`Entry`=211151 AND `DifficultyID`=23); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=260501, `TypeFlags`=0x40200048, `TypeFlags2`=34 WHERE (`Entry`=211150 AND `DifficultyID`=23); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=260460, `TypeFlags`=0x40200048, `TypeFlags2`=34 WHERE (`Entry`=211111 AND `DifficultyID`=23); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=260488, `TypeFlags`=0x40200048, `TypeFlags2`=34 WHERE (`Entry`=211137 AND `DifficultyID`=23); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=10, `CreatureDifficultyID`=260500, `TypeFlags`=0x40200048, `TypeFlags2`=34 WHERE (`Entry`=211149 AND `DifficultyID`=23); -- Path Helper

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (131246, 126804, 126487, 131397, 123820, 123861, 126549, 129837, 131410, 124314, 131385, 130488, 131382, 124359, 130323, 124332, 124255, 131383, 131381);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(131246, 6.057178497314453125, 9, 0, 62493),
(126804, 0.835662662982940673, 0, 0, 62493),
(126487, 0.5, 1, 0, 62493),
(131397, 1.491570353507995605, 0, 0, 62493),
(123820, 0.74140477180480957, 0, 0, 62493),
(123861, 0.697013258934020996, 0, 0, 62493),
(126549, 1.174476385116577148, 4.5, 0, 62493),
(129837, 1, 6, 0, 62493),
(131410, 0.74140477180480957, 0, 0, 62493),
(124314, 0.567706227302551269, 0, 0, 62493),
(131385, 2.473866462707519531, 2.5, 0, 62493),
(130488, 1.888888955116271972, 2, 0, 62493),
(131382, 0.855444133281707763, 1, 0, 62493),
(124359, 1.888888955116271972, 2, 0, 62493),
(130323, 1.888888955116271972, 2, 0, 62493),
(124332, 1.888888955116271972, 2, 0, 62493),
(124255, 0.567706227302551269, 0, 0, 62493),
(131383, 2.421499967575073242, 2.20000004768371582, 0, 62493),
(131381, 2.138610363006591796, 2.5, 0, 62493);

UPDATE `creature_model_info` SET `BoundingRadius`=0.855444133281707763, `CombatReach`=1, `VerifiedBuild`=62493 WHERE `DisplayID`=97761;
UPDATE `creature_model_info` SET `VerifiedBuild`=62493 WHERE `DisplayID` IN (92725, 11686);
UPDATE `creature_model_info` SET `BoundingRadius`=2.421499967575073242, `CombatReach`=2.20000004768371582, `VerifiedBuild`=62493 WHERE `DisplayID`=100364;
UPDATE `creature_model_info` SET `BoundingRadius`=2.473866462707519531, `CombatReach`=2.5, `VerifiedBuild`=62493 WHERE `DisplayID`=94225;
UPDATE `creature_model_info` SET `BoundingRadius`=0.314837157726287841, `CombatReach`=0.210000008344650268, `VerifiedBuild`=62493 WHERE `DisplayID`=100725;

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (234957,234962,242631,234872));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(234957, 1, 240499, 0, 0, 0, 0, 0, 0, 0, 0, 62493), -- Wastelander Ritualist
(234962, 1, 233002, 0, 0, 0, 0, 0, 0, 0, 0, 62493), -- Wastelander Farstalker
(242631, 1, 232997, 0, 0, 0, 0, 0, 0, 0, 0, 62493), -- Overcharged Sentinel
(234872, 1, 240503, 0, 0, 240521, 0, 0, 0, 0, 0, 62493); -- Wastelander Phaseblade

-- Path for Ravenous Destroyer
SET @MOVERGUID := @CGUID+47;
SET @ENTRY := 236995;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Ravenous Destroyer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 685.79865, -837.27954, 976.67303, NULL, 0),
(@PATH, 1, 654.8542, -807.0573, 976.6178, NULL, 300),
(@PATH, 2, 685.79865, -837.27954, 976.67303, NULL, 0),
(@PATH, 3, 708.6893, -859.2153, 978.2002, NULL, 190);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '18950');

-- Path for Overcharged Sentinel
SET @MOVERGUID := @CGUID+54;
SET @ENTRY := 242631;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Overcharged Sentinel - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 781.09375, -763.4149, 996.17706, NULL, 0),
(@PATH, 1, 801.8403, -768.80206, 997.70703, NULL, 0),
(@PATH, 2, 812.6528, -769.0191, 997.9746, NULL, 4097),
(@PATH, 3, 801.8403, -768.80206, 997.70703, NULL, 0),
(@PATH, 4, 781.09375, -763.4149, 996.17706, NULL, 0),
(@PATH, 5, 763.441, -751.11633, 995.10803, NULL, 4099);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '1231234 18950');

-- Path for Overcharged Sentinel
SET @MOVERGUID := @CGUID+113;
SET @ENTRY := 242631;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Overcharged Sentinel - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 748.4514, -661.3195, 993.64954, NULL, 0),
(@PATH, 1, 750.3351, -670.9514, 993.655, NULL, 0),
(@PATH, 2, 752.21875, -680.5833, 993.6605, NULL, 0),
(@PATH, 3, 750.9583, -702.5903, 993.6625, NULL, 0),
(@PATH, 4, 749.2552, -724.2743, 993.68945, NULL, 4005),
(@PATH, 5, 750.9583, -702.5903, 993.6625, NULL, 0),
(@PATH, 6, 752.21875, -680.5833, 993.6605, NULL, 0),
(@PATH, 7, 750.3351, -670.9514, 993.655, NULL, 4208);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '1231234 18950');

-- Path for Voracious Gorger
SET @MOVERGUID := @CGUID+147;
SET @ENTRY := 245412;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Voracious Gorger - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 473.47916, -724.52954, 999.7821, NULL, 6703),
(@PATH, 1, 474.2361, -739.0399, 1000.25525, NULL, 0),
(@PATH, 2, 472.33508, -760.5868, 1000.048, NULL, 0),
(@PATH, 3, 466.35764, -775.79865, 998.9132, NULL, 9500),
(@PATH, 4, 472.33508, -760.5868, 1000.048, NULL, 0),
(@PATH, 5, 474.2361, -739.0399, 1000.25525, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Invading Mite
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+149;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+149, @CGUID+149, 0, 0, 515, 0, 0),
(@CGUID+149, @CGUID+151, 3, 50, 515, 0, 0),
(@CGUID+149, @CGUID+152, 3, 310, 515, 0, 0);

SET @MOVERGUID := @CGUID+149;
SET @ENTRY := 245414;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, NULL, 'Invading Mite - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 485.92883, -761.8368, 1017.5908, NULL, 0),
(@PATH, 1, 486.46353, -731.2274, 1013.8856, NULL, 0),
(@PATH, 2, 469.49652, -707.21356, 1017.1382, NULL, 0),
(@PATH, 3, 429.24652, -702.0174, 1013.0372, NULL, 0),
(@PATH, 4, 412.94098, -719.9774, 1017.5797, NULL, 0),
(@PATH, 5, 406.8229, -757.3594, 1018.7889, NULL, 0),
(@PATH, 6, 423.38022, -797.0243, 1016.9368, NULL, 0),
(@PATH, 7, 477.04166, -793.625, 1015.5993, NULL, 0);

UPDATE `creature` SET `position_x`=485.92883, `position_y`=-761.8368, `position_z`=1017.5908, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Invading Mite
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+31;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+31, @CGUID+31, 0, 0, 515, 15, 0),
(@CGUID+31, @CGUID+85, 3, 90, 515, 15, 0),
(@CGUID+31, @CGUID+92, 6, 50, 515, 15, 0),
(@CGUID+31, @CGUID+90, 9, 50, 515, 15, 0),
(@CGUID+31, @CGUID+76, 3, 310, 515, 15, 0),
(@CGUID+31, @CGUID+75, 6, 310, 515, 15, 0);

SET @MOVERGUID := @CGUID+31;
SET @ENTRY := 234870;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x01, NULL, 'Invading Mite - Fornation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 783.78827, -922.2049, 1005.69165, NULL, 0),
(@PATH, 1, 756.98267, -897.2222, 1004.8165, NULL, 0),
(@PATH, 2, 730.17706, -872.23956, 1003.9414, NULL, 0),
(@PATH, 3, 693.84375, -841.1424, 1000.3027, NULL, 0),
(@PATH, 4, 665.7899, -810.0816, 998.4362, NULL, 0),
(@PATH, 5, 643.58856, -775.78125, 1002.4439, NULL, 0),
(@PATH, 6, 603.21875, -757.8559, 1012.8585, NULL, 0),
(@PATH, 7, 570.6424, -751.4531, 1019.7933, NULL, 0),
(@PATH, 8, 531.8177, -749.49304, 1018.8176, NULL, 0),
(@PATH, 9, 484.69446, -750.11633, 1019.8005, NULL, 0),
(@PATH, 10, 450.25174, -778.56946, 1021.546, NULL, 0),
(@PATH, 11, 411.67883, -769.4566, 1022.3061, NULL, 0),
(@PATH, 12, 393.27084, -743.2153, 1018.8939, NULL, 0),
(@PATH, 13, 413.50696, -715.3715, 1021.0075, NULL, 0),
(@PATH, 14, 449.42535, -711.0816, 1025.2242, NULL, 0),
(@PATH, 15, 480.30728, -736.3264, 1023.015, NULL, 0);

UPDATE `creature` SET `position_x`=783.78827, `position_y`=-922.2049, `position_z`=1005.69165, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Wastelander Farstalker
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+57;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+57, @CGUID+57, 0, 0, 515, 0, 0),
(@CGUID+57, @CGUID+61, 4, 70, 515, 1, 0),
(@CGUID+57, @CGUID+63, 4, 290, 515, 1, 0);

SET @MOVERGUID := @CGUID+57;
SET @ENTRY := 234962;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Wastelander Farstalker - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 729.441, -755.17883, 994.9727, NULL, 3930),
(@PATH, 1, 749.5417, -733.54865, 994.53314, NULL, 3932);

UPDATE `creature` SET `position_x`=729.441, `position_y`=-755.17883, `position_z`=994.9727, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '1220676');

-- Path for Wastelander Farstalker
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+105;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+105, @CGUID+105, 0, 0, 515, 0, 0),
(@CGUID+105, @CGUID+106, 4, 70, 515, 4, 1),
(@CGUID+105, @CGUID+95, 4, 290, 515, 4, 1);

SET @MOVERGUID := @CGUID+105;
SET @ENTRY := 234962;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Wastelander Farstalker - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 867.6424, -717.5816, 997.7042, NULL, 0),
(@PATH, 1, 882.4792, -702, 998.15393, NULL, 3602),
(@PATH, 2, 867.6424, -717.5816, 997.7042, NULL, 0),
(@PATH, 3, 842.1198, -712.1493, 997.6674, NULL, 0),
(@PATH, 4, 829.1268, -690.6389, 997.9674, NULL, 3540),
(@PATH, 5, 842.1198, -712.1493, 997.6674, NULL, 0);

UPDATE `creature` SET `position_x`=867.6424, `position_y`=-717.5816, `position_z`=997.7042, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '1220676');

-- Path for Wastelander Ritualist
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+164;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+164, @CGUID+164, 0, 0, 515, 0, 0),
(@CGUID+164, @CGUID+165, 4, 90, 515, 4, 1);

SET @MOVERGUID := @CGUID+164;
SET @ENTRY := 234957;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Wastelander Ritualist - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 837.0347, -625.54517, 998.68677, NULL, 0),
(@PATH, 1, 832.21356, -634.34375, 997.6903, NULL, 2561),
(@PATH, 2, 837.0347, -625.54517, 998.68677, NULL, 0),
(@PATH, 3, 846.2535, -607.32465, 998.34546, NULL, 0),
(@PATH, 4, 849.59375, -599.49133, 998.48206, NULL, 2517),
(@PATH, 5, 846.2535, -607.32465, 998.34546, NULL, 0);

UPDATE `creature` SET `position_x`=837.0347, `position_y`=-625.54517, `position_z`=998.68677, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '1244327');
