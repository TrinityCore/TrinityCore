SET @CGUID := 10004291;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+125;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+1, 221528, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1122.1649169921875, -2280.83154296875, 96.29673004150390625, 3.702281475067138671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+2, 225270, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1126.920166015625, -2299.632080078125, 87.9004974365234375, 6.212477684020996093, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+3, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1104.7708740234375, -2338.68408203125, 84.47222900390625, 6.233168601989746093, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+4, 225270, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1136.2569580078125, -2294.194580078125, 87.714996337890625, 0, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+5, 221528, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1126.03125, -2271.9306640625, 112.3149642944335937, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+6, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1162.1597900390625, -2359.529541015625, 88.80396270751953125, 0.573921084403991699, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+7, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1089, -2422.697998046875, 69.7669677734375, 1.477960944175720214, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+8, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1043.0364990234375, -2352.28125, 69.912322998046875, 5.105098247528076171, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+9, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1060.3038330078125, -2381.032958984375, 72.545196533203125, 3.24641275405883789, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+10, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1139.1961669921875, -2395.7119140625, 80.534881591796875, 2.421428680419921875, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+11, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1113.375, -2401.97216796875, 78.13864898681640625, 5.133153438568115234, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+12, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1079.8975830078125, -2394.6806640625, 75.11767578125, 1.955991506576538085, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+13, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1057.9444580078125, -2345.098876953125, 73.7835693359375, 5.105098247528076171, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+14, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1027.0069580078125, -2467.725830078125, 54.38938140869140625, 1.97751474380493164, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+15, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1045.5885009765625, -2483.3837890625, 61.20178985595703125, 1.178087353706359863, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+16, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1054.298583984375, -2490.795166015625, 58.23914718627929687, 1.623456358909606933, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+17, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1010.39410400390625, -2558.94091796875, 61.08159637451171875, 0.176193580031394958, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+18, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 979.576416015625, -2514.685791015625, 48.61640548706054687, 0.239495739340782165, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+19, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1009.4149169921875, -2477.59033203125, 52.5279541015625, 0.985584735870361328, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+20, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1032.1475830078125, -2527.388916015625, 55.88359451293945312, 3.942825794219970703, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+21, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 981.52777099609375, -2481.460205078125, 48.87318801879882812, 4.337102890014648437, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+22, 225270, 2552, 14717, 14717, '0', 0, 0, 0, 0, 963.73785400390625, -2549.757080078125, 56.24970626831054687, 1.006684184074401855, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+23, 225270, 2552, 14717, 14717, '0', 0, 0, 0, 0, 963.73785400390625, -2549.757080078125, 56.24970626831054687, 1.006684184074401855, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+24, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 914.53302001953125, -2690.1875, 56.6151885986328125, 4.982587337493896484, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+25, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 941.4444580078125, -2600.51904296875, 59.0229949951171875, 0.172539353370666503, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+26, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 968.46875, -2615.876708984375, 67.2250823974609375, 2.541871309280395507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+27, 225271, 2552, 14717, 14717, '0', 0, 0, 0, 0, 968.46875, -2615.876708984375, 67.2250823974609375, 5.683161735534667968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+28, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 998.2430419921875, -2640.37841796875, 71.179931640625, 4.113070964813232421, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+29, 222182, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1028.392333984375, -2649.515625, 72.8268585205078125, 1.241391539573669433, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Basin Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+30, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 976.16668701171875, -2632.545166015625, 68.26599884033203125, 1.314798235893249511, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+31, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1004.12677001953125, -2670.239501953125, 68.78293609619140625, 1.907396197319030761, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+32, 223095, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1008.048583984375, -2644.907958984375, 72.05902862548828125, 1.014679551124572753, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Bedrock Stonecharger (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+33, 222182, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1073.6007080078125, -2518.34716796875, 65.992828369140625, 6.178853034973144531, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Basin Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+34, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1089.9791259765625, -2504.048583984375, 67.2600860595703125, 1.289394736289978027, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+35, 222182, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1075.2691650390625, -2520.91845703125, 66.796875, 0.412375509738922119, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Basin Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+36, 222182, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1090.29345703125, -2507.132080078125, 68.36632537841796875, 5.506326675415039062, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Basin Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+37, 222182, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1107.685791015625, -2511.23095703125, 70.356842041015625, 2.067642450332641601, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Basin Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+38, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1196.892333984375, -2520.407958984375, 83.60590362548828125, 0.863375544548034667, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+39, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1191.6353759765625, -2531.53466796875, 80.45201873779296875, 3.340412855148315429, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+40, 222182, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1202.2864990234375, -2538.833251953125, 81.9010467529296875, 3.980371475219726562, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Basin Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+41, 222182, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1169.8697509765625, -2548.520751953125, 81.8541717529296875, 0.918354928493499755, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Basin Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+42, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1194.342041015625, -2553.657958984375, 81.53229522705078125, 0.111304223537445068, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+43, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1147.9427490234375, -2508.236083984375, 67.1805572509765625, 2.250378370285034179, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+44, 222182, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1184.8941650390625, -2534.736083984375, 78.22570037841796875, 4.346275806427001953, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Basin Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+45, 225270, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1191, -2584.7744140625, 77.12958526611328125, 1.786462187767028808, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+46, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1198.654541015625, -2545.935791015625, 81.08050537109375, 2.170200109481811523, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: ) (possible waypoints or random movement)
(@CGUID+47, 225268, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1138.3194580078125, -2569.958251953125, 63.6722259521484375, 0.584752440452575683, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plainswalker Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+48, 222182, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1001.10772705078125, -2618.928955078125, 79.11199951171875, 5.567833900451660156, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Basin Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+49, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 896.9913330078125, -2709.10595703125, 56.09589767456054687, 3.029442787170410156, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+50, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1131.1197509765625, -2483.388916015625, 67.7689208984375, 5.105098247528076171, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+51, 221528, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1165.7708740234375, -2556.192626953125, 106.3261032104492187, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Soaring Plainshawk (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+52, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1263.4132080078125, -2516.123291015625, 101.02569580078125, 1.612819671630859375, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+53, 225270, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1220.2083740234375, -2472.583251953125, 94.0221710205078125, 3.081252574920654296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+55, 225270, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1271.375, -2505.217041015625, 104.8295364379882812, 0, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+56, 221519, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1237.93408203125, -2503.020751953125, 95.3243255615234375, 1.178087353706359863, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Fluttering Sapphire (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+57, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1176.236083984375, -2436.51220703125, 85.48726654052734375, 5.274718284606933593, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+58, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 959.25, -2682.34716796875, 68.76136016845703125, 5.849575042724609375, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+59, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 988.9617919921875, -2639.536376953125, 70.42768096923828125, 0.744543194770812988, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+60, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 900.0555419921875, -2680.12158203125, 57.3291473388671875, 0.206703931093215942, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+61, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 967.3507080078125, -2645.9931640625, 67.52167510986328125, 0.550886750221252441, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: 106562 - Cosmetic - Sleep Zzz Breakable) (possible waypoints or random movement)
(@CGUID+62, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1007.34722900390625, -2681.451416015625, 69.06223297119140625, 2.291038036346435546, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+63, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1265.623291015625, -2641.6181640625, 84.1369171142578125, 3.744344949722290039, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+64, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1246.9791259765625, -2585.991455078125, 89.93264007568359375, 3.049927234649658203, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+65, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1197.87158203125, -2601.7587890625, 75.5903472900390625, 3.25756072998046875, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+66, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1282.5625, -2582.329833984375, 104.4965286254882812, 1.303998351097106933, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+67, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1206.3211669921875, -2618.064208984375, 76.43619537353515625, 0.011472704820334911, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+68, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1344.3958740234375, -2641.1806640625, 107.1263427734375, 0.79532790184020996, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+69, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1374.6285400390625, -2625.58154296875, 113.7419357299804687, 2.361749172210693359, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+70, 225270, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1294.5225830078125, -2631.5, 93.60721588134765625, 0, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+71, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1329.421875, -2639.132080078125, 103.5290985107421875, 0.938516855239868164, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+72, 221526, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1362.7552490234375, -2576.888916015625, 114.4189987182617187, 1.952292799949645996, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Mosspelt Ramolith (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+73, 225270, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1220.2083740234375, -2472.583251953125, 94.0221710205078125, 3.081252574920654296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+74, 225270, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1191, -2584.7744140625, 77.12958526611328125, 1.786462187767028808, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+75, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 915.96527099609375, -2649.486083984375, 59.52630615234375, 0.928432822227478027, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+76, 222182, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1060.80908203125, -2639.828125, 68.58898162841796875, 5.127486705780029296, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Basin Ferret (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+77, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1030.1788330078125, -2701.3056640625, 64.18717193603515625, 1.071868658065795898, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+78, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 999.71527099609375, -2737.994873046875, 64.1234130859375, 1.38983619213104248, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+79, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1015.94097900390625, -2711.421875, 64.9664306640625, 5.590720653533935546, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+80, 221523, 2552, 14717, 14717, '0', 0, 0, 0, 0, 997.388916015625, -2761.132080078125, 59.82355499267578125, 2.265883684158325195, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+81, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 936.5399169921875, -2729.20654296875, 57.33840560913085937, 4.051886558532714843, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+82, 221684, 2552, 14717, 14717, '0', 0, 0, 0, 0, 948.6632080078125, -2756.4150390625, 58.43769454956054687, 2.346099615097045898, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+83, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 968.46875, -2615.876708984375, 67.2250823974609375, 2.541871309280395507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+84, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 968.46875, -2615.876708984375, 67.2250823974609375, 2.541871309280395507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+85, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 968.46875, -2615.876708984375, 67.2250823974609375, 2.541871309280395507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+86, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 968.46875, -2615.876708984375, 67.2250823974609375, 2.541871309280395507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+87, 221522, 2552, 14717, 14717, '0', 0, 0, 0, 0, 968.46875, -2615.876708984375, 67.2250823974609375, 2.541871309280395507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+88, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1058.7291259765625, -2748.098876953125, 66.98675537109375, 0.595250427722930908, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+89, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1063.6458740234375, -2734.68408203125, 66.21485137939453125, 2.668943643569946289, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+90, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1087.6597900390625, -2740.807373046875, 64.678192138671875, 2.781728267669677734, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+91, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1059.7603759765625, -2741.4462890625, 66.5442352294921875, 5.868555545806884765, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+92, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1062.170166015625, -2734.767333984375, 66.0662994384765625, 5.212418079376220703, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+93, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1041.3958740234375, -2761.541748046875, 66.552215576171875, 2.453649520874023437, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+94, 221523, 2552, 14717, 0, '0', 0, 0, 0, 0, 1098.2083740234375, -2746.772705078125, 64.32537841796875, 4.137695789337158203, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+95, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1029.3958740234375, -2713.40966796875, 62.7799072265625, 0.985504746437072753, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+96, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1057.55908203125, -2762.57470703125, 67.6476593017578125, 3.320479631423950195, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+97, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1045.1510009765625, -2747.119873046875, 66.356414794921875, 5.743844509124755859, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+98, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1084.3524169921875, -2729.62158203125, 64.53009033203125, 1.626362562179565429, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+99, 221523, 2552, 14717, 0, '0', 0, 0, 0, 0, 1053.5625, -2777.520751953125, 65.75418853759765625, 1.624570369720458984, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+100, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1084.5538330078125, -2756.553955078125, 67.06552886962890625, 0.731276631355285644, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+101, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1030.064208984375, -2711.572998046875, 62.62570953369140625, 0.878098547458648681, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+102, 222182, 2552, 14717, 0, '0', 0, 0, 0, 0, 1065.392333984375, -2766.765625, 67.676727294921875, 5.162131309509277343, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Basin Ferret (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+103, 221523, 2552, 14717, 0, '0', 0, 0, 0, 0, 1077.267333984375, -2762.064208984375, 67.47568511962890625, 0.975271403789520263, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+104, 221684, 2552, 14717, 0, '0', 0, 0, 0, 0, 1060.1666259765625, -2818.5556640625, 62.89004135131835937, 2.303490161895751953, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+105, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 997.25347900390625, -2798.505126953125, 63.89038848876953125, 0.475567579269409179, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+106, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 991.1961669921875, -2756.86279296875, 59.80630874633789062, 4.733006000518798828, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+107, 221684, 2552, 14717, 0, '0', 0, 0, 0, 0, 1003.09722900390625, -2789.80029296875, 59.65908432006835937, 0.824124395847320556, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+108, 221684, 2552, 14717, 0, '0', 0, 0, 0, 0, 1025.8489990234375, -2781.220458984375, 63.02301025390625, 3.51348876953125, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+109, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1108.2135009765625, -2676.491455078125, 56.67884445190429687, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+110, 225271, 2552, 14717, 0, '0', 0, 0, 0, 0, 1108.2135009765625, -2676.491455078125, 56.67884445190429687, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Dazzling Peafowl (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+111, 221684, 2552, 14717, 0, '0', 0, 0, 0, 0, 1011.43402099609375, -2822.50341796875, 59.30023193359375, 0.887081742286682128, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+112, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1108.2135009765625, -2676.491455078125, 56.67884445190429687, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+113, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1108.2135009765625, -2676.491455078125, 56.67884445190429687, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+114, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1108.2135009765625, -2676.491455078125, 56.67884445190429687, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+115, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1108.2135009765625, -2676.491455078125, 56.67884445190429687, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+116, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 1108.2135009765625, -2676.491455078125, 56.67884445190429687, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57388), -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+117, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 1010.83331298828125, -2899.885498046875, 46.77925872802734375, 1.850499510765075683, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+118, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 1043.984375, -2908.38720703125, 48.74675369262695312, 4.497695446014404296, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+119, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 973.47222900390625, -2848.819580078125, 48.002532958984375, 3.777703046798706054, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+120, 221684, 2552, 14717, 0, '0', 0, 0, 0, 0, 1034.44970703125, -2931.22216796875, 47.06487274169921875, 3.275208473205566406, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+121, 221684, 2552, 14717, 0, '0', 0, 0, 0, 0, 1034.7708740234375, -2882.944580078125, 50.80033493041992187, 6.090183734893798828, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+122, 221684, 2552, 14717, 0, '0', 0, 0, 0, 0, 1001.14239501953125, -2890.095458984375, 49.24053192138671875, 3.824261665344238281, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Crested Shalehorn (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+123, 221524, 2552, 14717, 0, '0', 0, 0, 0, 0, 1086.5103759765625, -2881.454833984375, 57.72467803955078125, 0.623632013797760009, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Gemwing (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+124, 222182, 2552, 14717, 0, '0', 0, 0, 0, 0, 1044.87158203125, -2848.880126953125, 59.42361068725585937, 5.422306537628173828, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 57388), -- Basin Ferret (Area: 0 - Difficulty: 0) CreateObject2
(@CGUID+125, 221522, 2552, 14717, 0, '0', 0, 0, 0, 0, 984.296875, -2845.4931640625, 51.00248336791992187, 0.749452412128448486, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 57388); -- Plains Peachick (Area: 0 - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+125;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Soaring Plainshawk
(@CGUID+5, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Soaring Plainshawk
(@CGUID+51, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Soaring Plainshawk

-- Template
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800, `unit_flags3`=0x4000000 WHERE `entry`=225271; -- Dazzling Peafowl
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=222182; -- Basin Ferret

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=225271 AND `DifficultyID`=0); -- 225271 (Dazzling Peafowl) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57388 WHERE (`Entry`=222182 AND `DifficultyID`=0); -- 222182 (Basin Ferret) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (120305, 122774, 122773, 105489);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(120305, 1.727734565734863281, 12.80000019073486328, 0, 57388),
(122774, 0.208000004291534423, 1.5, 0, 57388),
(122773, 0.372000008821487426, 1.5, 0, 57388),
(105489, 2.320718288421630859, 2, 0, 57388);

-- Path for Crested Shalehorn
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+53;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+53, @CGUID+53, 0, 0, 515, 0, 0),
(@CGUID+53, @CGUID+73, 3, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+53;
SET @ENTRY := 225270;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Crested Shalehorn - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1195.2865, -2430.8108, 90.967545, NULL, 0),
(@PATH, 1, 1177.5973, -2404.8213, 85.88221, NULL, 0),
(@PATH, 2, 1154.0195, -2382.3887, 84.4075, NULL, 0),
(@PATH, 3, 1153.3027, -2381.6914, 84.73471, NULL, 0),
(@PATH, 4, 1151.1523, -2379.5996, 84.99997, NULL, 0),
(@PATH, 5, 1149.002, -2377.5078, 85.27023, NULL, 0),
(@PATH, 6, 1146.1348, -2374.7188, 85.783516, NULL, 0),
(@PATH, 7, 1143.9844, -2372.627, 86.16864, NULL, 0),
(@PATH, 8, 1143.2676, -2371.9297, 85.971245, NULL, 0),
(@PATH, 9, 1141.834, -2370.5352, 86.33142, NULL, 0),
(@PATH, 10, 1141.1172, -2369.838, 86.10591, NULL, 0),
(@PATH, 11, 1137.5332, -2366.3516, 86.35534, NULL, 0),
(@PATH, 12, 1135.3828, -2364.2598, 86.63578, NULL, 0),
(@PATH, 13, 1133.9492, -2362.8652, 86.81068, NULL, 0),
(@PATH, 14, 1128.9316, -2357.9844, 86.55917, NULL, 0),
(@PATH, 15, 1128.1841, -2357.2395, 86.476364, NULL, 0),
(@PATH, 16, 1123.8223, -2351.7715, 86.0395, NULL, 0),
(@PATH, 17, 1103.8872, -2367.861, 84.04957, NULL, 0),
(@PATH, 18, 1085.1805, -2388.4324, 77.16551, NULL, 0),
(@PATH, 19, 1059.7916, -2405.2795, 66.688965, NULL, 0),
(@PATH, 20, 1025.2622, -2437.625, 54.305477, NULL, 0),
(@PATH, 21, 1007.5712, -2459.2188, 52.816547, NULL, 0),
(@PATH, 22, 985.9514, -2480.5608, 49.280304, NULL, 0),
(@PATH, 23, 1007.5712, -2459.2188, 52.816547, NULL, 0),
(@PATH, 24, 1025.2622, -2437.625, 54.305477, NULL, 0),
(@PATH, 25, 1059.7916, -2405.2795, 66.688965, NULL, 0),
(@PATH, 26, 1085.1805, -2388.4324, 77.16551, NULL, 0),
(@PATH, 27, 1103.8872, -2367.861, 84.04957, NULL, 0),
(@PATH, 28, 1123.7986, -2351.7395, 86.06295, NULL, 0),
(@PATH, 29, 1128.1602, -2357.209, 86.509, NULL, 0),
(@PATH, 30, 1154.0192, -2382.389, 84.607635, NULL, 0),
(@PATH, 31, 1177.5973, -2404.8213, 85.88221, NULL, 0),
(@PATH, 32, 1195.2865, -2430.8108, 90.967545, NULL, 0),
(@PATH, 33, 1207.3923, -2454.5557, 91.54687, NULL, 0),
(@PATH, 34, 1216.7726, -2468.3057, 93.04478, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Crested Shalehorn
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+45;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+45, @CGUID+45, 0, 0, 515, 0, 0),
(@CGUID+45, @CGUID+74, 3, 90, 515, 0, 0);

SET @MOVERGUID := @CGUID+45;
SET @ENTRY := 225270;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Crested Shalehorn - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1207.4479, -2556.554, 82.377174, NULL, 0),
(@PATH, 1, 1204.8229, -2544.7917, 81.97391, NULL, 0),
(@PATH, 2, 1196.3264, -2532.8994, 81.32806, NULL, 0),
(@PATH, 3, 1184.243, -2519.033, 80.025764, NULL, 0),
(@PATH, 4, 1177.3403, -2506.019, 77.81084, NULL, 0),
(@PATH, 5, 1168.2535, -2484.6008, 74.4317, NULL, 0),
(@PATH, 6, 1157.7743, -2467.5852, 73.375694, NULL, 0),
(@PATH, 7, 1145.4774, -2458.7344, 72.52913, NULL, 0),
(@PATH, 8, 1121.1805, -2450.4531, 70.14048, NULL, 0),
(@PATH, 9, 1098.6528, -2440.6494, 68.035416, NULL, 0),
(@PATH, 10, 1073.6493, -2443.554, 61.766502, NULL, 0),
(@PATH, 11, 1098.6528, -2440.6494, 68.035416, NULL, 0),
(@PATH, 12, 1121.1805, -2450.4531, 70.14048, NULL, 0),
(@PATH, 13, 1145.4774, -2458.7344, 72.52913, NULL, 0),
(@PATH, 14, 1157.7743, -2467.5852, 73.375694, NULL, 0),
(@PATH, 15, 1168.2535, -2484.6008, 74.4317, NULL, 0),
(@PATH, 16, 1177.3403, -2506.019, 77.81084, NULL, 0),
(@PATH, 17, 1184.243, -2519.033, 80.025764, NULL, 0),
(@PATH, 18, 1196.3264, -2532.8994, 81.32806, NULL, 0),
(@PATH, 19, 1204.8229, -2544.7917, 81.97391, NULL, 0),
(@PATH, 20, 1207.4365, -2556.5098, 82.45569, NULL, 0),
(@PATH, 21, 1203.8785, -2568.5747, 80.45734, NULL, 0),
(@PATH, 22, 1198.4896, -2579.8455, 78.45331, NULL, 0),
(@PATH, 23, 1203.8785, -2568.5747, 80.45734, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Crested Shalehorn
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+22;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+22, @CGUID+22, 0, 0, 515, 0, 0),
(@CGUID+22, @CGUID+23, 3, 90, 515, 0, 0);

SET @MOVERGUID := @CGUID+22;
SET @ENTRY := 225270;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Crested Shalehorn - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1023.0486, -2545.1423, 56.70486, NULL, 0),
(@PATH, 1, 1036.882, -2546.5208, 58.176758, NULL, 0),
(@PATH, 2, 1058.4774, -2553.9202, 60.529373, NULL, 0),
(@PATH, 3, 1089.9548, -2581.3196, 61.122574, NULL, 0),
(@PATH, 4, 1116.1598, -2612.4446, 57.358685, NULL, 0),
(@PATH, 5, 1119.0156, -2639.7031, 55.25894, NULL, 0),
(@PATH, 6, 1116.1598, -2612.4446, 57.358685, NULL, 0),
(@PATH, 7, 1089.9548, -2581.3196, 61.122574, NULL, 0),
(@PATH, 8, 1058.4774, -2553.9202, 60.529373, NULL, 0),
(@PATH, 9, 1036.882, -2546.5208, 58.176758, NULL, 0),
(@PATH, 10, 1023.0486, -2545.1423, 56.70486, NULL, 0),
(@PATH, 11, 1000.618, -2545.1284, 56.804512, NULL, 0),
(@PATH, 12, 974.86456, -2547.5261, 55.940506, NULL, 0),
(@PATH, 13, 1000.618, -2545.1284, 56.804512, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Dazzling Peafowl
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+27;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+27, @CGUID+27, 0, 0, 515, 0, 0),
(@CGUID+27, @CGUID+26, 2, 0, 515, 0, 0),
(@CGUID+27, @CGUID+83, 4, 0, 515, 0, 0),
(@CGUID+27, @CGUID+84, 6, 0, 515, 0, 0),
(@CGUID+27, @CGUID+85, 8, 0, 515, 0, 0),
(@CGUID+27, @CGUID+86, 10, 0, 515, 0, 0),
(@CGUID+27, @CGUID+87, 12, 0, 515, 0, 0);

SET @MOVERGUID := @CGUID+27;
SET @ENTRY := 225271;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Dazzling Peafowl - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 978.67535, -2625.0208, 69.472694, NULL, 0),
(@PATH, 1, 983.0833, -2630.5781, 69.417046, NULL, 0),
(@PATH, 2, 985.30206, -2638.4878, 70.17841, NULL, 0),
(@PATH, 3, 984.5399, -2648.856, 69.88014, NULL, 0),
(@PATH, 4, 982.2743, -2655.1875, 70.06893, NULL, 0),
(@PATH, 5, 980.1042, -2666.4028, 69.395905, NULL, 0),
(@PATH, 6, 978.76215, -2674.4705, 70.12172, NULL, 0),
(@PATH, 7, 977.9549, -2682.1807, 71.85783, NULL, 0),
(@PATH, 8, 975.50696, -2691.929, 72.5987, NULL, 0),
(@PATH, 9, 976.8715, -2704.1946, 70.05014, NULL, 0),
(@PATH, 10, 978.2153, -2711.1145, 68.464264, NULL, 0),
(@PATH, 11, 979.16016, -2715.0059, 67.3793, NULL, 0),
(@PATH, 12, 979.6328, -2716.9512, 67.034805, NULL, 0),
(@PATH, 13, 980.10547, -2718.8965, 66.72648, NULL, 0),
(@PATH, 14, 980.2066, -2719.3196, 66.73915, NULL, 0),
(@PATH, 15, 982.441, -2730.7778, 63.68891, NULL, 0),
(@PATH, 16, 984.8698, -2741.7673, 62.589317, NULL, 0),
(@PATH, 17, 988.04865, -2753.0105, 60.310764, NULL, 0),
(@PATH, 18, 987.47266, -2762.9902, 59.822792, NULL, 0),
(@PATH, 19, 985.30035, -2771.0713, 60.74354, NULL, 0),
(@PATH, 20, 980.46704, -2777.3108, 59.76716, NULL, 0),
(@PATH, 21, 974.2847, -2787.0503, 57.72168, NULL, 0),
(@PATH, 22, 966.33856, -2792.6216, 56.797966, NULL, 0),
(@PATH, 23, 955.8924, -2799.4565, 54.225204, NULL, 0),
(@PATH, 24, 948.2743, -2803.4358, 53.50727, NULL, 0),
(@PATH, 25, 955.8924, -2799.4565, 54.225204, NULL, 0),
(@PATH, 26, 966.33856, -2792.6216, 56.797966, NULL, 0),
(@PATH, 27, 974.2847, -2787.0503, 57.72168, NULL, 0),
(@PATH, 28, 980.46704, -2777.3108, 59.76716, NULL, 0),
(@PATH, 29, 985.30035, -2771.0713, 60.74354, NULL, 0),
(@PATH, 30, 987.46875, -2763.1216, 59.817932, NULL, 0),
(@PATH, 31, 988.04865, -2753.0105, 60.310764, NULL, 0),
(@PATH, 32, 984.8698, -2741.7673, 62.589317, NULL, 0),
(@PATH, 33, 982.441, -2730.7778, 63.68891, NULL, 0),
(@PATH, 34, 980.2066, -2719.3196, 66.73915, NULL, 0),
(@PATH, 35, 978.2153, -2711.1145, 68.464264, NULL, 0),
(@PATH, 36, 975.50696, -2691.929, 72.5987, NULL, 0),
(@PATH, 37, 977.9385, -2682.2227, 71.78925, NULL, 0),
(@PATH, 38, 978.76215, -2674.4705, 70.12172, NULL, 0),
(@PATH, 39, 980.1042, -2666.4028, 69.395905, NULL, 0),
(@PATH, 40, 982.2743, -2655.1875, 70.06893, NULL, 0),
(@PATH, 41, 984.5399, -2648.856, 69.88014, NULL, 0),
(@PATH, 42, 985.30206, -2638.4878, 70.17841, NULL, 0),
(@PATH, 43, 983.0833, -2630.5781, 69.417046, NULL, 0),
(@PATH, 44, 978.67535, -2625.0208, 69.472694, NULL, 0),
(@PATH, 45, 974.42365, -2619.9583, 68.873566, NULL, 0),
(@PATH, 46, 971.12305, -2617.7012, 67.74394, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Dazzling Peafowl
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+110;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+110, @CGUID+110, 0, 0, 515, 0, 0),
(@CGUID+110, @CGUID+109, 2, 0, 515, 0, 0),
(@CGUID+110, @CGUID+112, 4, 0, 515, 0, 0),
(@CGUID+110, @CGUID+113, 6, 0, 515, 0, 0),
(@CGUID+110, @CGUID+114, 8, 0, 515, 0, 0),
(@CGUID+110, @CGUID+115, 10, 0, 515, 0, 0),
(@CGUID+110, @CGUID+116, 12, 0, 515, 0, 0);

SET @MOVERGUID := @CGUID+110;
SET @ENTRY := 225271;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Dazzling Peafowl - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1086.606, -2688.8767, 57.178745, NULL, 0),
(@PATH, 1, 1074.5104, -2695.4895, 59.630768, NULL, 0),
(@PATH, 2, 1063.4896, -2706.4324, 62.25571, NULL, 0),
(@PATH, 3, 1050.6146, -2720.8801, 63.75382, NULL, 0),
(@PATH, 4, 1039.2812, -2736.0088, 65.03466, NULL, 0),
(@PATH, 5, 1030.875, -2748.132, 64.4334, NULL, 0),
(@PATH, 6, 1026.3976, -2763.4514, 63.79139, NULL, 0),
(@PATH, 7, 1035.4062, -2780.1545, 64.89855, NULL, 0),
(@PATH, 8, 1046.8334, -2791.4185, 64.30891, NULL, 0),
(@PATH, 9, 1058.493, -2802.7761, 62.544025, NULL, 0),
(@PATH, 10, 1064.6562, -2811.2744, 63.181572, NULL, 0),
(@PATH, 11, 1070.9896, -2827.4878, 62.697845, NULL, 0),
(@PATH, 12, 1070.8767, -2845.8784, 61.209446, NULL, 0),
(@PATH, 13, 1065.8577, -2860.9636, 59.355064, NULL, 0),
(@PATH, 14, 1059.5834, -2882.6685, 54.289288, NULL, 0),
(@PATH, 15, 1052.9219, -2901.316, 51.797222, NULL, 0),
(@PATH, 16, 1059.5834, -2882.6685, 54.289288, NULL, 0),
(@PATH, 17, 1065.8577, -2860.9636, 59.355064, NULL, 0),
(@PATH, 18, 1070.8767, -2845.8784, 61.209446, NULL, 0),
(@PATH, 19, 1070.9896, -2827.4878, 62.697845, NULL, 0),
(@PATH, 20, 1064.6562, -2811.2744, 63.181572, NULL, 0),
(@PATH, 21, 1058.493, -2802.7761, 62.544025, NULL, 0),
(@PATH, 22, 1046.8334, -2791.4185, 64.30891, NULL, 0),
(@PATH, 23, 1035.4062, -2780.1545, 64.89855, NULL, 0),
(@PATH, 24, 1026.3976, -2763.4514, 63.79139, NULL, 0),
(@PATH, 25, 1030.875, -2748.132, 64.4334, NULL, 0),
(@PATH, 26, 1039.2812, -2736.0088, 65.03466, NULL, 0),
(@PATH, 27, 1050.6146, -2720.8801, 63.75382, NULL, 0),
(@PATH, 28, 1063.4896, -2706.4324, 62.25571, NULL, 0),
(@PATH, 29, 1074.5104, -2695.4895, 59.630768, NULL, 0),
(@PATH, 30, 1086.606, -2688.8767, 57.178745, NULL, 0),
(@PATH, 31, 1095.8091, -2684.217, 57.06317, NULL, 0),
(@PATH, 32, 1103.625, -2677.8352, 57.09596, NULL, 0),
(@PATH, 33, 1095.8091, -2684.217, 57.06317, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
 