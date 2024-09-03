SET @CGUID := 9004296;
SET @OGUID := 9003944;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+226;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 136.5694427490234375, -1057.57470703125, 228.25628662109375, 2.016267061233520507, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+1, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 140.9531707763671875, -1057.386962890625, 228.3657684326171875, 1.704768896102905273, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+2, 184022, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 118.2378463745117187, -1025.517333984375, 228.243896484375, 4.603126049041748046, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Stonevault Geomancer (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+3, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 202.2618255615234375, -1020.10601806640625, 221.1477508544921875, 2.785541534423828125, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+4, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 175.779510498046875, -1059.0816650390625, 229.4671173095703125, 5.522971153259277343, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin') (possible waypoints or random movement)
(@CGUID+5, 184023, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 146.5718994140625, -1064.450439453125, 228.281005859375, 0.039752881973981857, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Vicious Basilisk (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+6, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 119.2587738037109375, -1004.4571533203125, 228.310882568359375, 3.197952985763549804, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+7, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 135.58160400390625, -1060.829833984375, 228.25628662109375, 3.144408226013183593, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+8, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 140.40826416015625, -1061.5501708984375, 228.3074798583984375, 1.378388762474060058, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+9, 184020, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 146.1197967529296875, -1059.59033203125, 228.3364105224609375, 0.017874872311949729, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Hulking Berserker (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369807 - Reckless Rage)
(@CGUID+10, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 173.873260498046875, -1060.2535400390625, 229.50067138671875, 0.10446515679359436, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin') (possible waypoints or random movement)
(@CGUID+11, 184022, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 117.6232681274414062, -1031.40625, 228.243896484375, 1.251535534858703613, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Stonevault Geomancer (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+12, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 139.0104217529296875, -1064.0399169921875, 228.25628662109375, 4.673722743988037109, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+13, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 172.3020782470703125, -1055.48095703125, 229.4637603759765625, 1.955587029457092285, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+14, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 138.8385467529296875, -1055.796875, 228.2562408447265625, 1.368818402290344238, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+15, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 174.90252685546875, -1049.3603515625, 229.6421966552734375, 4.320114612579345703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+16, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 169.1458282470703125, -1056.16845703125, 229.332916259765625, 1.874708294868469238, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+17, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 210.368988037109375, -1034.067138671875, 221.4390106201171875, 6.01050424575805664, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+18, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 147.251800537109375, -1025.181640625, 228.284423828125, 5.70518350601196289, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+19, 184022, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 139.09375, -1060.092041015625, 228.25628662109375, 3.163882255554199218, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Stonevault Geomancer (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+20, 184023, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 103.5691375732421875, -948.1719970703125, 232.1060333251953125, 1.642296195030212402, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Vicious Basilisk (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+21, 184019, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 112.2569427490234375, -947.93402099609375, 232.1589813232421875, 4.916172504425048828, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Burly Rock-Thrower (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+22, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 86.0243072509765625, -1029.154541015625, 229.89495849609375, 2.737435579299926757, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+23, 184020, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 55.44791793823242187, -982.01739501953125, 229.638641357421875, 0.091775722801685333, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Hulking Berserker (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369807 - Reckless Rage)
(@CGUID+24, 184018, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 96.6631927490234375, -861.44964599609375, 226.557220458984375, 4.678445816040039062, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Bromach (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+25, 184019, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 111.939239501953125, -952.68231201171875, 232.159423828125, 1.304666638374328613, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Burly Rock-Thrower (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+26, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 63.27257156372070312, -946.7742919921875, 232.71014404296875, 1.01864635944366455, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+27, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 23.59081840515136718, -984.3819580078125, 230.7005767822265625, 5.993071556091308593, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+28, 184022, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 58.30034637451171875, -950.248291015625, 229.6677703857421875, 0.553441107273101806, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Stonevault Geomancer (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+29, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 78.45915985107421875, -951.30615234375, 232.096923828125, 3.358500003814697265, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+30, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 67.361114501953125, -947.64581298828125, 231.622222900390625, 6.119381904602050781, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+31, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 26.16741943359375, -981.91552734375, 230.824188232421875, 2.076791763305664062, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+32, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 79.62326812744140625, -1024.701416015625, 230.120086669921875, 4.298058509826660156, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+33, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 123.6541519165039062, -917.26287841796875, 231.558441162109375, 0.170834332704544067, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+34, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 302.520843505859375, -833.18402099609375, 220.154541015625, 3.663052797317504882, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+35, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 81.9021148681640625, -956.57244873046875, 232.096923828125, 1.20245981216430664, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+36, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 84.53646087646484375, -1026.1978759765625, 229.630859375, 3.904300689697265625, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+37, 191910, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 94.689239501953125, -880.685791015625, 230.711883544921875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Staff of Prehistoria (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+38, 184022, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 57.90972137451171875, -978.998291015625, 229.638641357421875, 6.266347885131835937, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Stonevault Geomancer (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+39, 184020, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 103.5694427490234375, -900.04339599609375, 227.110870361328125, 4.751626491546630859, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Hulking Berserker (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369807 - Reckless Rage)
(@CGUID+40, 184023, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 103.889892578125, -981.58856201171875, 232.313385009765625, 6.066083431243896484, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Vicious Basilisk (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+41, 184023, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 31.47817230224609375, -980.12664794921875, 230.5608367919921875, 4.465473175048828125, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Vicious Basilisk (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+42, 184022, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 67.28646087646484375, -952.16839599609375, 229.638641357421875, 1.577847838401794433, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Stonevault Geomancer (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+43, 184023, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 101.6785812377929687, -988.805419921875, 229.690673828125, 6.05866861343383789, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Vicious Basilisk (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+44, 184023, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 25.15241050720214843, -978.06756591796875, 231.16851806640625, 2.044177055358886718, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Vicious Basilisk (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+45, 184132, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 309.302093505859375, -835.01214599609375, 220.2625732421875, 5.966654300689697265, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Warder (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+46, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 101.0764083862304687, -1012.09161376953125, 227.690673828125, 2.907162427902221679, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+47, 195343, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 117.7656326293945312, -869.375, 227.541778564453125, 4.821860313415527343, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Runic Protector (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+48, 184019, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 97.28646087646484375, -959.21875, 234.13787841796875, 4.445143699645996093, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Burly Rock-Thrower (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+49, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 83.71314239501953125, -1016.39031982421875, 228.3528289794921875, 5.19045257568359375, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+50, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 61.31597137451171875, -944.15972900390625, 233.5439910888671875, 2.33568429946899414, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+51, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 79.470489501953125, -1027.0694580078125, 233.751861572265625, 2.716207027435302734, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+52, 184022, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 58.03645706176757812, -984.998291015625, 229.638641357421875, 6.266347885131835937, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Stonevault Geomancer (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+53, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 115.0010910034179687, -921.12091064453125, 231.7682647705078125, 5.711815834045410156, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+54, 184020, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 97.79514312744140625, -900.31597900390625, 227.2041473388671875, 4.867263317108154296, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Hulking Berserker (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369807 - Reckless Rage)
(@CGUID+55, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 49.15639114379882812, -951.3629150390625, 229.5735931396484375, 2.452517986297607421, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+56, 184134, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 62.31076431274414062, -948.73956298828125, 230.791900634765625, 0.041291780769824981, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Scavenging Leaper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369998 - Diggin')
(@CGUID+57, 184022, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 100.6927108764648437, -903.08856201171875, 226.960296630859375, 4.668981552124023437, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Stonevault Geomancer (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%)
(@CGUID+58, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 95.81668853759765625, -919.0714111328125, 230.826751708984375, 0.63988572359085083, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+59, 184023, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 94.579803466796875, -984.072021484375, 230.0163421630859375, 4.128936767578125, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Vicious Basilisk (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+60, 184020, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 84.89409637451171875, -1020.9774169921875, 228.2429962158203125, 4.030721664428710937, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Hulking Berserker (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 369807 - Reckless Rage)
(@CGUID+61, 184023, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 93.99819183349609375, -949.2486572265625, 232.1970672607421875, 2.499571800231933593, 7200, 4, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Vicious Basilisk (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+62, 184132, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 292.110504150390625, -810.833984375, 216.8699798583984375, 4.947008132934570312, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Warder (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+63, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 296.214080810546875, -809.79248046875, 216.7903289794921875, 4.958537101745605468, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+64, 184019, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 58.59027862548828125, -759.1492919921875, 213.50543212890625, 5.526475906372070312, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Burly Rock-Thrower (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+65, 184132, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 412.505218505859375, -779.154541015625, 225.4868927001953125, 3.342472791671752929, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Warder (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+66, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 312.333343505859375, -832.68231201171875, 220.1385498046875, 4.809356212615966796, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+67, 184300, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 325.77777099609375, -810.44268798828125, 225.356842041015625, 3.834209442138671875, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Ebonstone Golem (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+68, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 296.5299072265625, -820.33746337890625, 219.5171661376953125, 2.794529914855957031, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+69, 191459, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, -13.421875, -1007.38018798828125, 222.548004150390625, 1.102153420448303222, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Longboat Raid (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 375887 - Longboat Raid!)
(@CGUID+70, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 96.3170928955078125, -818.80767822265625, 229.487548828125, 3.049109697341918945, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+71, 184300, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 377.611114501953125, -789.701416015625, 225.4868927001953125, 0.434723228216171264, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Ebonstone Golem (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+72, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 114.624114990234375, -804.86700439453125, 229.6247100830078125, 6.257524013519287109, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+73, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 96.83853912353515625, -797.796875, 229.429229736328125, 3.104758977890014648, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+74, 184131, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 294.866546630859375, -813.1329345703125, 217.51202392578125, 4.95874643325805664, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Guardian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+75, 195343, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 89.3993072509765625, -837.03125, 228.6688385009765625, 1.15586090087890625, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Runic Protector (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+76, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 92.33159637451171875, -797.7742919921875, 229.429229736328125, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+77, 184132, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 63.05382156372070312, -759.31597900390625, 213.50543212890625, 3.385261297225952148, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Warder (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+78, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 291.711822509765625, -773.2569580078125, 213.453887939453125, 4.166989326477050781, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+79, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 319.90789794921875, -841.0931396484375, 221.13916015625, 2.550336837768554687, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+80, 191911, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 94.90451812744140625, -828.7257080078125, 236.35174560546875, 4.722012042999267578, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Door of Prehistoria (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+81, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 311.885345458984375, -743.9110107421875, 212.57171630859375, 3.248572826385498046, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+82, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 302.163909912109375, -824.9417724609375, 220.4600677490234375, 0.633504807949066162, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+83, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 59.86458206176757812, -764.326416015625, 213.50537109375, 2.735405206680297851, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+84, 195343, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 98.79166412353515625, -834.2882080078125, 229.044158935546875, 4.077471733093261718, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Runic Protector (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+85, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, -9.89088249206542968, -982.23114013671875, 227.090606689453125, 0.994823455810546875, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+86, 184132, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 376.258697509765625, -784.79339599609375, 225.4868927001953125, 0.096576340496540069, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Warder (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+87, 184319, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 49.60416793823242187, -805.54864501953125, 227.257232666015625, 0.04452911764383316, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Refti Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 377723 - Antique Constitution, 18950 - Invisibility and Stealth Detection)
(@CGUID+88, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 329.5382080078125, -733.342041015625, 208.4998321533203125, 1.313577532768249511, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+89, 184319, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 70.1036834716796875, -807.7550048828125, 228.41119384765625, 6.167046070098876953, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Refti Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 377723 - Antique Constitution, 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+90, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 42.52556228637695312, -810.464111328125, 227.3357391357421875, 0.124098002910614013, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+91, 184300, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 328.385406494140625, -815.91143798828125, 225.35650634765625, 3.671220064163208007, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Ebonstone Golem (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+92, 184580, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, -12.7048616409301757, -1010.88372802734375, 222.0821533203125, 2.110162019729614257, 7200, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 46924), -- Olaf (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 369994 - Dwarven Rage) (possible waypoints or random movement)
(@CGUID+93, 184132, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 380.482635498046875, -794.0711669921875, 225.4868927001953125, 0.702047586441040039, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Warder (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+94, 184581, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, -9.47569465637207031, -1003.72222900390625, 222.650299072265625, 3.80088210105895996, 7200, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 46924), -- Baelog (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 369993 - Dwarven Rage) (possible waypoints or random movement)
(@CGUID+95, 184319, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 59.24826431274414062, -745.40106201171875, 213.5054168701171875, 4.748206138610839843, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Refti Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 377723 - Antique Constitution, 18950 - Invisibility and Stealth Detection)
(@CGUID+96, 184582, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, -15.5364580154418945, -1017.42877197265625, 224.00775146484375, 2.072437763214111328, 7200, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 46924), -- Eric "The Swift" (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 369995 - Dwarven Rage) (possible waypoints or random movement)
(@CGUID+97, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 77.3533935546875, -805.6754150390625, 229.3529205322265625, 3.335570812225341796, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+98, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 87.80208587646484375, -723.40277099609375, 213.502227783203125, 4.617581367492675781, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+99, 184022, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 63.19270706176757812, -755.88714599609375, 213.50543212890625, 2.661409854888916015, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Stonevault Geomancer (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%, 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+100, 141587, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 301.98834228515625, -805.2640380859375, 217.174407958984375, 2.337249279022216796, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Rat (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 123168 - Mod Scale 115-120%) (possible waypoints or random movement)
(@CGUID+101, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 289.595489501953125, -776.2430419921875, 213.8235626220703125, 1.037573933601379394, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+102, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 87.97916412353515625, -727.97222900390625, 213.50543212890625, 1.914471387863159179, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+103, 184132, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 161.90972900390625, -623.8194580078125, 214.166778564453125, 5.517126083374023437, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Warder (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+104, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 421.40625, -708.232666015625, 222.8309173583984375, 5.247252464294433593, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375604 - Time Lock)
(@CGUID+105, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 129.42535400390625, -623.39581298828125, 214.166778564453125, 5.517126083374023437, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+106, 184132, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 407.935760498046875, -769.97052001953125, 225.4868927001953125, 3.878768205642700195, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Warder (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+107, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 164.6059112548828125, -625.77081298828125, 214.166778564453125, 3.116961479187011718, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+108, 184132, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 192.7413177490234375, -606.48614501953125, 213.9044647216796875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Warder (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+109, 184331, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 424.63714599609375, -711.39410400390625, 222.8308563232421875, 5.152741909027099609, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Infinite Timereaver (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+110, 186107, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 285.52777099609375, -627.2100830078125, 211.1051788330078125, 1.762875795364379882, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Vault Keeper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 369038 - Titanic Ward)
(@CGUID+111, 184132, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 129.796875, -626.9461669921875, 214.166778564453125, 1.053103327751159667, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Warder (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+112, 184131, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 410.65277099609375, -774.35418701171875, 225.4868927001953125, 3.610661506652832031, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Guardian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+113, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 424.197906494140625, -714.89410400390625, 222.830902099609375, 1.164852857589721679, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock)
(@CGUID+114, 184300, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 326.765625, -717.8524169921875, 208.84844970703125, 1.52671515941619873, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Ebonstone Golem (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+115, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 186.5850677490234375, -609.82989501953125, 214.1789703369140625, 1.689340591430664062, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+116, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 108.0451431274414062, -651.7725830078125, 215.5615234375, 5.705199241638183593, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+117, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 430.1788330078125, -709.404541015625, 222.830902099609375, 3.036176204681396484, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock)
(@CGUID+118, 184132, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 162.67535400390625, -627.2899169921875, 214.166778564453125, 1.053103327751159667, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Warder (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+119, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 146.0416717529296875, -648.78472900390625, 215.561431884765625, 1.652990460395812988, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+120, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 108.1093826293945312, -656.2430419921875, 215.5615234375, 0.433414012193679809, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+121, 184124, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 59.40277862548828125, -653.56597900390625, 218.0670928955078125, 4.621479988098144531, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Sentinel Talondras (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 372717 - Inexorable, 372600 - Inexorable, 372775 - Inexorable, 372778 - Inexorable) (possible waypoints or random movement)
(@CGUID+122, 184300, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 363.82464599609375, -661.326416015625, 213.669708251953125, 0.801672220230102539, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Ebonstone Golem (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+123, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 149.5555572509765625, -648.5242919921875, 215.561431884765625, 1.547887325286865234, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+124, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 525.90972900390625, -670.73614501953125, 209.079010009765625, 3.611143112182617187, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock)
(@CGUID+125, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 150.1527862548828125, -569.6649169921875, 216.692138671875, 1.545411109924316406, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+126, 184301, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 181.9904022216796875, -525.28875732421875, 220.0990447998046875, 2.269370555877685546, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Cavern Seeker (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+127, 184303, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 150.2083282470703125, -541.45489501953125, 216.455841064453125, 4.444916248321533203, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Skittering Crawler (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 369417 - Venomous Fangs)
(@CGUID+128, 184301, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 185.3466033935546875, -507.97149658203125, 220.111083984375, 5.91129302978515625, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Cavern Seeker (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+129, 184132, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 140.3541717529296875, -579.373291015625, 216.6924285888671875, 1.685719132423400878, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Warder (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+130, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 508.3194580078125, -699.2742919921875, 209.079010009765625, 1.765245914459228515, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375604 - Time Lock)
(@CGUID+131, 184303, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 213.81781005859375, -517.806640625, 218.2029571533203125, 3.190463781356811523, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Skittering Crawler (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 369417 - Venomous Fangs) (possible waypoints or random movement)
(@CGUID+132, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 186.920135498046875, -603.2725830078125, 214.1695709228515625, 4.78429412841796875, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+133, 184319, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 528.01214599609375, -676.9617919921875, 209.079010009765625, 2.372736454010009765, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Refti Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 377723 - Antique Constitution, 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock)
(@CGUID+134, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 105.0451431274414062, -609.8211669921875, 214.1791534423828125, 1.709328651428222656, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+135, 184107, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 99.38889312744140625, -606.20489501953125, 214.17913818359375, 0.090770117938518524, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Runic Protector (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+136, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 522.1632080078125, -674.86981201171875, 209.079010009765625, 0.418184459209442138, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock)
(@CGUID+137, 184107, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 147.30035400390625, -575.37847900390625, 216.692138671875, 1.667328953742980957, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Runic Protector (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+138, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 516.8055419921875, -656.97222900390625, 209.079010009765625, 3.036176204681396484, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock)
(@CGUID+139, 184303, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 204.6546630859375, -501.7601318359375, 217.84576416015625, 2.356194496154785156, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Skittering Crawler (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 369417 - Venomous Fangs) (possible waypoints or random movement)
(@CGUID+140, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 512.453125, -662.42364501953125, 209.079010009765625, 5.660106182098388671, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock)
(@CGUID+141, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 144.5381927490234375, -569.5555419921875, 216.692138671875, 1.547353625297546386, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+142, 184301, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 189.3942718505859375, -521.8765869140625, 217.184814453125, 0.727129817008972167, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Cavern Seeker (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+143, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 104.9513931274414062, -603.61114501953125, 214.1791534423828125, 4.912405967712402343, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+144, 184130, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 504.09027099609375, -645.08856201171875, 209.079010009765625, 0.478268563747406005, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Custodian (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375604 - Time Lock)
(@CGUID+145, 184303, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 160.47357177734375, -541.22601318359375, 217.7015838623046875, 5.227938175201416015, 7200, 6, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Skittering Crawler (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 369417 - Venomous Fangs) (possible waypoints or random movement)
(@CGUID+146, 194269, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 0, 74.13187408447265625, -734.13568115234375, 214.829437255859375, 0.018323210999369621, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+147, 194269, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 0, 55.27061080932617187, -725.077880859375, 213.4871063232421875, 5.512996196746826171, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+148, 186420, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 1, 88.625, -725.6961669921875, 213.50543212890625, 3.112815618515014648, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+149, 194269, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 0, 77.06771087646484375, -728.326416015625, 214.2944183349609375, 0, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+150, 186420, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 1, 26.08506965637207031, -731.26910400390625, 213.4991455078125, 3.112815618515014648, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+151, 186420, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 1, 26.49652862548828125, -720.232666015625, 213.501922607421875, 3.112815618515014648, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+152, 186107, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 0, 257.77777099609375, -614.70831298828125, 211.1051788330078125, 0.948536992073059082, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Vault Keeper (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 369038 - Titanic Ward)
(@CGUID+153, 189649, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 0, 147.326385498046875, -664.23785400390625, 227.2744598388671875, 1.604642391204833984, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Spell Bunny (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+154, 186420, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 1, 111.40625, -654.0086669921875, 215.5615234375, 3.10391855239868164, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+155, 186107, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 0, 245.0121612548828125, -586.2100830078125, 211.1051788330078125, 0.149591892957687377, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Vault Keeper (Area: 0 - Difficulty: Mythic) CreateObject1
(@CGUID+156, 194269, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 0, 132.11248779296875, -652.56976318359375, 215.487548828125, 6.125476837158203125, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+157, 186420, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 1, 142.607635498046875, -645.1319580078125, 215.561431884765625, 1.656948566436767578, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+158, 186420, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 1, 152.517364501953125, -644.43927001953125, 215.561431884765625, 1.501072645187377929, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+159, 194269, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 0, 154.068817138671875, -652.91802978515625, 215.5186614990234375, 3.633559226989746093, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+160, 194269, 2451, 13968, 0, '2,8,23,1', '0', 0, 0, 0, 162.29119873046875, -651.06787109375, 215.4876556396484375, 4.377968788146972656, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: 0 - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement
(@CGUID+161, 193554, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 123.0850677490234375, -856.4913330078125, 226.759796142578125, 2.812715768814086914, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Neglected Mole Machine (Area: The Dig - Difficulty: Mythic) CreateObject2 (Auras: 381847 - Mole Machine)
(@CGUID+162, 193530, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 209.4461822509765625, -1027.2274169921875, 220.6237335205078125, 1.6900787353515625, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Neglected Mole Machine (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 381847 - Mole Machine)
(@CGUID+163, 186420, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 132.3194427490234375, -624.94097900390625, 214.166778564453125, 3.16190338134765625, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+164, 186420, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 330.904510498046875, -727.217041015625, 208.6590576171875, 4.638311386108398437, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+165, 186107, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 285.282989501953125, -543.85418701171875, 211.1051788330078125, 4.795243263244628906, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Vault Keeper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 369038 - Titanic Ward)
(@CGUID+166, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 329.61834716796875, -713.67193603515625, 209.072265625, 3.37053227424621582, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+167, 186420, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 311.076385498046875, -683.25347900390625, 211.41796875, 4.817316055297851562, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+168, 186420, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 336.045135498046875, -711.09893798828125, 212.113189697265625, 1.055494904518127441, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+169, 186107, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 327.13714599609375, -585.74652099609375, 211.1051788330078125, 3.293413639068603515, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Vault Keeper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 369038 - Titanic Ward)
(@CGUID+170, 186420, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 198.953125, -609.1163330078125, 214.170318603515625, 4.951356410980224609, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+171, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 319.280364990234375, -699.00909423828125, 208.2165069580078125, 3.403626441955566406, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+172, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 134.458709716796875, -605.880615234375, 214.1465606689453125, 6.070532798767089843, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+173, 186107, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 314.8663330078125, -555.89581298828125, 211.1051788330078125, 4.131069183349609375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Vault Keeper (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 369038 - Titanic Ward)
(@CGUID+174, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 160.0266571044921875, -608.16082763671875, 214.10723876953125, 1.160860538482666015, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+175, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 330.87091064453125, -698.92376708984375, 208.8603057861328125, 4.020357131958007812, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+176, 186420, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 197.765625, -602.59552001953125, 214.020538330078125, 0.702672898769378662, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 393603 - Cosmetic - Reading Book, Standing)
(@CGUID+177, 186420, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 154.0625, -579.5242919921875, 216.692138671875, 1.649409055709838867, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+178, 189649, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 106.9114608764648437, -565.84552001953125, 220.9752655029296875, 4.659701824188232421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Spell Bunny (Area: The Dig - Difficulty: Mythic) CreateObject1
(@CGUID+179, 186465, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 143.703125, -564.64581298828125, 216.692138671875, 5.355870246887207031, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Skittering Crawler (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+180, 186465, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 152.2152862548828125, -563.05731201171875, 216.692138671875, 4.188678264617919921, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Skittering Crawler (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+181, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 169.84637451171875, -546.52056884765625, 215.490447998046875, 4.416788101196289062, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+182, 11073, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 188.3715362548828125, -550.90106201171875, 215.4306488037109375, 4.05782318115234375, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Annora (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 162323 - Permanent Feign Death (Untrackable, Uninteractible, Immune))
(@CGUID+183, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 162.31256103515625, -543.017578125, 217.5104522705078125, 0.863728880882263183, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+184, 195508, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 153.845489501953125, -538.6180419921875, 216.1986236572265625, 5.703025341033935546, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Explorer's League Scout (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+185, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 157.0933990478515625, -532.8721923828125, 215.5217437744140625, 5.53744363784790039, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+186, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 158.7498626708984375, -537.22900390625, 215.963348388671875, 0.057829461991786956, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+187, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 175.2105255126953125, -540.63726806640625, 215.810089111328125, 4.061652183532714843, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+188, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 156.792022705078125, -538.55560302734375, 216.1339874267578125, 2.686432600021362304, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+189, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 184.08984375, -534.30718994140625, 215.519866943359375, 0.520475327968597412, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+190, 184335, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 1, 470.470489501953125, -688.59027099609375, 209.0789947509765625, 3.689583778381347656, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Infinite Agent (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+191, 194269, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 189.9807891845703125, -535.8172607421875, 216.6906585693359375, 5.679711341857910156, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+192, 195508, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 174.1788177490234375, -526.78125, 216.700714111328125, 2.159137487411499023, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Explorer's League Scout (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+193, 195511, 2451, 13968, 14143, '2,8,23,1', '0', 0, 0, 0, 175.90972900390625, -524.02777099609375, 216.2868194580078125, 4.094311237335205078, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Explorer's League Prospector (Area: The Dig - Difficulty: Mythic) CreateObject1 (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+194, 194269, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 228.5059967041015625, -533.44317626953125, 212.00836181640625, 3.671929836273193359, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+195, 195508, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 191.625, -521.90802001953125, 216.227935791015625, 0.273745268583297729, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Explorer's League Scout (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+196, 194269, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 227.2603607177734375, -528.64532470703125, 213.4609375, 4.250735282897949218, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+197, 194269, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 227.0943145751953125, -529.87274169921875, 212.991180419921875, 5.65152740478515625, 7200, 10, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Spiderling (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 259242 - Squish) (possible waypoints or random movement)
(@CGUID+198, 195508, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 191.142364501953125, -514.4930419921875, 215.7587127685546875, 2.251143932342529296, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Explorer's League Scout (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+199, 195511, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 187.83160400390625, -520.55035400390625, 216.03668212890625, 0.504593372344970703, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Explorer's League Prospector (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 29266 - Permanent Feign Death, 28559 - Untrackable)
(@CGUID+200, 184422, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 305.74884033203125, -596.30596923828125, 211.284423828125, 4.133840084075927734, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Emberon (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 369101 - Denergize)
(@CGUID+201, 186420, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 1, 363.1944580078125, -653.8125, 213.669708251953125, 4.000745296478271484, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+202, 186420, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 1, 371.15625, -661.31597900390625, 213.669708251953125, 3.929263591766357421, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Weaver (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+203, 191311, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 502.955322265625, -654.0921630859375, 209.164154052734375, 0.346831262111663818, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Infinite Whelp (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+204, 191311, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 500.755218505859375, -652.7117919921875, 209.17864990234375, 4.250464439392089843, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Infinite Whelp (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+205, 184331, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 1, 500.868072509765625, -678.78125, 209.1192169189453125, 5.603517055511474609, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Infinite Timereaver (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+206, 191311, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 497.791839599609375, -647.88092041015625, 209.2060699462890625, 0.002397023141384124, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Infinite Whelp (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+207, 191311, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 510.9542236328125, -687.38165283203125, 209.175537109375, 1.954499483108520507, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Infinite Whelp (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+208, 191311, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 509.631500244140625, -683.9765625, 209.16168212890625, 3.912199974060058593, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Infinite Whelp (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+209, 191311, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 512.61883544921875, -683.39385986328125, 209.169464111328125, 4.002725601196289062, 7200, 3, 0, 100, 1, NULL, NULL, NULL, NULL, 46924), -- Infinite Whelp (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+210, 184331, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 1, 519.43927001953125, -660.91143798828125, 209.079132080078125, 3.723954677581787109, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Infinite Timereaver (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+211, 184331, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 1, 522.1632080078125, -667.63018798828125, 209.0792083740234375, 3.409252643585205078, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Infinite Timereaver (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+212, 193299, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 394.5, -781.732666015625, 235.837310791015625, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Earthen Focus (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+213, 195344, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 466.19964599609375, -688.1024169921875, 209.0789947509765625, 5.396390438079833984, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Refti Custodian (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 377723 - Antique Constitution, 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock)
(@CGUID+214, 195343, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 483.7100830078125, -653.64410400390625, 209.079010009765625, 3.695492267608642578, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Runic Protector (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock)
(@CGUID+215, 195343, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 476.689239501953125, -688.22222900390625, 209.0789947509765625, 0.491253077983856201, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Runic Protector (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock)
(@CGUID+216, 191220, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 1, 605.9913330078125, -632.734375, 223.663604736328125, 1.155432701110839843, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Chrono-Lord Deios (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 375793 - Sand Essence, 375646 - Floating Sands, 375648 - Empowering Sands)
(@CGUID+217, 195344, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 493.02777099609375, -664.02606201171875, 209.079010009765625, 0.888780474662780761, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Refti Custodian (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 377723 - Antique Constitution, 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock)
(@CGUID+218, 195343, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 508.807281494140625, -641.748291015625, 209.079010009765625, 4.154844284057617187, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Runic Protector (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375604 - Time Lock)
(@CGUID+219, 193554, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 189.326385498046875, -548.07989501953125, 215.1959991455078125, 1.564182043075561523, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Neglected Mole Machine (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 381847 - Mole Machine)
(@CGUID+220, 195343, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 525.62677001953125, -691.65277099609375, 209.079010009765625, 0.542028367519378662, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Runic Protector (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock)
(@CGUID+221, 195344, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 497.5382080078125, -692.54339599609375, 209.079010009765625, 0.627731561660766601, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Refti Custodian (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 377723 - Antique Constitution, 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375604 - Time Lock)
(@CGUID+222, 195343, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 503.22222900390625, -700.32464599609375, 209.079010009765625, 1.329715847969055175, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Runic Protector (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375604 - Time Lock)
(@CGUID+223, 198172, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 591.763916015625, -631.48614501953125, 213.6633758544921875, 0, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Ambient Sound Controller (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1
(@CGUID+224, 193777, 2451, 13968, 14144, '2,8,23,1', '0', 0, 0, 0, 629.43402099609375, -613.8507080078125, 219.20013427734375, 3.561788797378540039, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Discs of Tyr (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1 (Auras: )
(@CGUID+225, 193554, 2451, 13968, 14146, '2,8,23,1', '0', 0, 0, 0, 289.385406494140625, -817.3367919921875, 218.4804534912109375, 6.143541812896728515, 7200, 0, 0, 100, 0, NULL, NULL, NULL, NULL, 46924), -- Neglected Mole Machine (Area: The Vault of Tyr - Difficulty: Mythic) CreateObject1 (Auras: 381847 - Mole Machine)
(@CGUID+226, 184125, 2451, 13968, 14146, '2,8,23,1', '0', 0, 0, 0, 593.3211669921875, -630.72222900390625, 213.6633758544921875, 3.630864143371582031, 7200, 0, 0, 0, 0, NULL, NULL, NULL, NULL, 46924); -- Chrono-Lord Deios (Area: The Vault of Tyr - Difficulty: Mythic) CreateObject2 (Auras: 375793 - Sand Essence)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+226;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+22, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '393603'), -- Earthen Custodian - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '393603'), -- Earthen Warder - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+47, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Runic Protector - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+56, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369998'), -- Scavenging Leaper - 123168 - Mod Scale 115-120%, 369998 - Diggin'
(@CGUID+64, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '123168 159474'), -- Burly Rock-Thrower - 123168 - Mod Scale 115-120%, 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+75, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Runic Protector - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+77, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '159474'), -- Earthen Warder - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+78, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '393603'), -- Earthen Custodian - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+83, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '159474'), -- Earthen Custodian - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+84, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Runic Protector - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+87, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '377723 18950'), -- Refti Custodian - 377723 - Antique Constitution, 18950 - Invisibility and Stealth Detection
(@CGUID+89, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '377723 18950'), -- Refti Custodian - 377723 - Antique Constitution, 18950 - Invisibility and Stealth Detection
(@CGUID+95, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '377723 18950'), -- Refti Custodian - 377723 - Antique Constitution, 18950 - Invisibility and Stealth Detection
(@CGUID+99, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '123168 159474'), -- Stonevault Geomancer - 123168 - Mod Scale 115-120%, 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+104, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '159474 375604'), -- Earthen Custodian - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375604 - Time Lock
(@CGUID+107, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '393603'), -- Earthen Custodian - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+113, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '159474 375616'), -- Earthen Custodian - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock
(@CGUID+116, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '393603'), -- Earthen Custodian - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+119, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Earthen Custodian
(@CGUID+117, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '159474 375616'), -- Earthen Custodian - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock
(@CGUID+123, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Earthen Custodian
(@CGUID+124, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '159474 375616'), -- Earthen Custodian - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock
(@CGUID+125, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Earthen Custodian
(@CGUID+129, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Earthen Warder
(@CGUID+130, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '159474 375604'), -- Earthen Custodian - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375604 - Time Lock
(@CGUID+133, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '377723 159474 375616'), -- Refti Custodian - 377723 - Antique Constitution, 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock
(@CGUID+135, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, '18950'), -- Runic Protector - 18950 - Invisibility and Stealth Detection
(@CGUID+136, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '159474 375616'), -- Earthen Custodian - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock
(@CGUID+138, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '159474 375616'), -- Earthen Custodian - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock
(@CGUID+140, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '159474 375616'), -- Earthen Custodian - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock
(@CGUID+141, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Earthen Custodian
(@CGUID+143, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '393603'), -- Earthen Custodian - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+144, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 4, '159474 375604'), -- Earthen Custodian - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375604 - Time Lock
(@CGUID+148, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '393603'), -- Earthen Weaver - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+150, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '393603'), -- Earthen Weaver - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+151, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '393603'), -- Earthen Weaver - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+163, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '393603'), -- Earthen Weaver - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+167, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '393603'), -- Earthen Weaver - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+168, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '393603'), -- Earthen Weaver - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+170, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '393603'), -- Earthen Weaver - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+176, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '393603'), -- Earthen Weaver - 393603 - Cosmetic - Reading Book, Standing
(@CGUID+177, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Earthen Weaver
(@CGUID+213, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '377723 159474 375616'), -- Refti Custodian - 377723 - Antique Constitution, 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock
(@CGUID+214, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474 375616'), -- Runic Protector - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock
(@CGUID+215, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474 375616'), -- Runic Protector - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock
(@CGUID+217, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '377723 159474 375616'), -- Refti Custodian - 377723 - Antique Constitution, 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock
(@CGUID+218, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474 375604'), -- Runic Protector - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375604 - Time Lock
(@CGUID+220, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474 375616'), -- Runic Protector - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375616 - Time Lock
(@CGUID+221, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '377723 159474 375604'), -- Refti Custodian - 377723 - Antique Constitution, 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375604 - Time Lock
(@CGUID+222, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474 375604'); -- Runic Protector - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune), 375604 - Time Lock

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+39;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 380927, 2451, 13968, 14143, '2,8,23,1', '0', 0, 183.2135467529296875, -1030.013916015625, 227.90625, 0.702438950538635253, -0.17608404159545898, -0.02231979370117187, 0.345112800598144531, 0.921625375747680664, 7200, 255, 1, 46924), -- Crumbling Rock Vein (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+1, 376405, 2451, 13968, 14143, '2,8,23,1', '0', 0, 208.7283782958984375, -1034.265869140625, 221.32281494140625, 3.43096017837524414, 0, 0, -0.98955154418945312, 0.144179463386535644, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+2, 376267, 2451, 13968, 14143, '2,8,23,1', '0', 0, 307.8135986328125, -843.21575927734375, 220.2015380859375, 4.368259906768798828, 0, 0, -0.8177337646484375, 0.575596630573272705, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+3, 376196, 2451, 13968, 14143, '2,8,23,1', '0', 0, 88.6299591064453125, -881.8270263671875, 227.5588226318359375, 4.588237285614013671, 0, 0, -0.74961090087890625, 0.661878764629364013, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+4, 376193, 2451, 13968, 14143, '2,8,23,1', '0', 0, 114.58782958984375, -904.644287109375, 229.5789947509765625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+5, 376194, 2451, 13968, 14143, '2,8,23,1', '0', 0, 116.271270751953125, -907.36651611328125, 229.8446044921875, 4.597093582153320312, 0, 0, -0.74667263031005859, 0.665191650390625, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+6, 376195, 2451, 13968, 14143, '2,8,23,1', '0', 0, 82.57865142822265625, -882.11077880859375, 229.7735443115234375, 3.43096017837524414, 0, 0, -0.98955154418945312, 0.144179463386535644, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+7, 376404, 2451, 13968, 14143, '2,8,23,1', '0', 0, 94.679443359375, -880.52685546875, 228.33209228515625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 46924), -- Staff of Prehistoria (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+8, 380929, 2451, 13968, 14143, '2,8,23,1', '0', 0, 69.89583587646484375, -868.107666015625, 229.539337158203125, 0.702438950538635253, -0.17608404159545898, -0.02231979370117187, 0.345112800598144531, 0.921625375747680664, 7200, 255, 1, 46924), -- Crumbling Rock Vein (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+9, 376268, 2451, 13968, 14143, '2,8,23,1', '0', 0, 299.82916259765625, -839.8382568359375, 220.3253936767578125, 5.126949310302734375, 0, 0, -0.5464487075805664, 0.837492585182189941, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+10, 376556, 2451, 13968, 14143, '2,8,23,1', '0', 0, 361.7691650390625, -797.193603515625, 225.2603912353515625, 0.454789340496063232, 0, 0, 0.225440025329589843, 0.974257051944732666, 7200, 255, 0, 46924), -- Door (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+11, 376557, 2451, 13968, 14143, '2,8,23,1', '0', 0, 94.923614501953125, -827.51568603515625, 229.3477630615234375, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 7200, 255, 1, 46924), -- Vault Door (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+12, 376197, 2451, 13968, 14143, '2,8,23,1', '0', 0, 73.748077392578125, -852.1722412109375, 226.3390960693359375, 2.358930826187133789, 0, 0, 0.924402236938476562, 0.381419092416763305, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+13, 376198, 2451, 13968, 14143, '2,8,23,1', '0', 0, 80.19626617431640625, -846.37744140625, 226.46295166015625, 3.117512226104736328, 0, 0, 0.999927520751953125, 0.012039870955049991, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+14, 380928, 2451, 13968, 14143, '2,8,23,1', '0', 0, -32.1631965637207031, -982.576416015625, 228.63848876953125, 0.702438950538635253, -0.17608404159545898, -0.02231979370117187, 0.345112800598144531, 0.921625375747680664, 7200, 255, 1, 46924), -- Crumbling Rock Vein (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+15, 380917, 2451, 13968, 14143, '2,8,23,1', '0', 0, -12.390625, -1001.19097900390625, 222.5824737548828125, 1.596738338470458984, -0.24791431427001953, -0.06134033203125, 0.713240623474121093, 0.652735531330108642, 7200, 255, 1, 46924), -- Staff of Prehistoria (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+16, 376269, 2451, 13968, 14143, '2,8,23,1', '0', 0, -24.5193328857421875, -1007.2398681640625, 232.6027679443359375, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+17, 376270, 2451, 13968, 14143, '2,8,23,1', '0', 0, -29.9840240478515625, -996.43670654296875, 231.4534454345703125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+18, 376271, 2451, 13968, 14143, '2,8,23,1', '0', 0, -29.92279052734375, -999.3486328125, 232.014068603515625, 3.9889678955078125, 0, 0, -0.91157913208007812, 0.411124706268310546, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+19, 377366, 2451, 13968, 14143, '2,8,23,1', '0', 0, 59.35430145263671875, -690.905029296875, 217.8275604248046875, 4.712392330169677734, 0, 0, -0.70710563659667968, 0.707107901573181152, 7200, 255, 1, 46924), -- Door (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+20, 376636, 2451, 13968, 14143, '2,8,23,1', '0', 0, 427.00909423828125, -766.7564697265625, 225.2603912353515625, 3.596386909484863281, 0, 0, -0.97425651550292968, 0.225442290306091308, 7200, 255, 0, 46924), -- Door (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+21, 376554, 2451, 13968, 14143, '2,8,23,1', '0', 0, 92.50649261474609375, -653.486083984375, 217.9700469970703125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 46924), -- Door (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+22, 376640, 2451, 13968, 14143, '2,8,23,1', '0', 0, 323.494903564453125, -623.78765869140625, 211.073333740234375, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 7200, 255, 1, 46924), -- Vault Door (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+23, 376637, 2451, 13968, 14143, '2,8,23,1', '0', 0, 547.11376953125, -652.29345703125, 213.6589202880859375, 3.583360671997070312, 0, 0, -0.97570419311523437, 0.219092100858688354, 7200, 255, 0, 46924), -- Door (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+24, 376191, 2451, 13968, 14143, '2,8,23,1', '0', 0, 247.78277587890625, -548.20391845703125, 211.19573974609375, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 7200, 255, 1, 46924), -- Vault Door (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+25, 376265, 2451, 13968, 14143, '2,8,23,1', '0', 0, 312.24200439453125, -686.4134521484375, 211.3748626708984375, 3.08925628662109375, 0, 0, 0.999657630920410156, 0.026165224611759185, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+26, 376266, 2451, 13968, 14143, '2,8,23,1', '0', 0, 311.27838134765625, -684.65704345703125, 211.3363494873046875, 4.034459114074707031, 0, 0, -0.9019927978515625, 0.431751072406768798, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+27, 376264, 2451, 13968, 14143, '2,8,23,1', '0', 0, 336.338623046875, -709.657958984375, 211.856231689453125, 0.331524223089218139, -0.05638551712036132, 0.033933639526367187, 0.166760444641113281, 0.983798861503601074, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+28, 384653, 2451, 13968, 14143, '2,8,23,1', '0', 0, 99.4375, -792.857666015625, 229.3459014892578125, 5.304136276245117187, 0, 0, -0.47020626068115234, 0.882556557655334472, 7200, 255, 1, 46924), -- Ancient Volume (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+29, 376406, 2451, 13968, 14143, '2,8,23,1', '0', 0, 177.1710205078125, -527.97454833984375, 216.43511962890625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 46924), -- Stool (Area: The Dig - Difficulty: Mythic) CreateObject1
(@OGUID+30, 384311, 2451, 13968, 14144, '2,8,23,1', '0', 0, 249.982635498046875, -520.748291015625, 213.728729248046875, 0, 0, 0, 0, 1, 7200, 255, 1, 46924), -- Ancient Volume (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1
(@OGUID+31, 384637, 2451, 13968, 14144, '2,8,23,1', '0', 0, 731.3868408203125, -525.65875244140625, 195.4986572265625, 3.545702934265136718, 0, 0, -0.97965621948242187, 0.200682997703552246, 7200, 255, 1, 46924), -- 10DU_Uldaman_FountainWater02 (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1
(@OGUID+32, 384638, 2451, 13968, 14144, '2,8,23,1', '0', 0, 726.65960693359375, -514.608642578125, 195.4986572265625, 3.545702934265136718, 0, 0, -0.97965621948242187, 0.200682997703552246, 7200, 255, 1, 46924), -- 10DU_Uldaman_FountainWater02 (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1
(@OGUID+33, 384639, 2451, 13968, 14144, '2,8,23,1', '0', 0, 720.8857421875, -502.80975341796875, 195.4986572265625, 3.545702934265136718, 0, 0, -0.97965621948242187, 0.200682997703552246, 7200, 255, 1, 46924), -- 10DU_Uldaman_FountainWater02 (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1
(@OGUID+34, 384634, 2451, 13968, 14144, '2,8,23,1', '0', 0, 762.85638427734375, -592.4775390625, 195.4986572265625, 3.545702934265136718, 0, 0, -0.97965621948242187, 0.200682997703552246, 7200, 255, 1, 46924), -- 10DU_Uldaman_FountainWater02 (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1
(@OGUID+35, 384635, 2451, 13968, 14144, '2,8,23,1', '0', 0, 767.77667236328125, -603.303466796875, 195.4986572265625, 3.545702934265136718, 0, 0, -0.97965621948242187, 0.200682997703552246, 7200, 255, 1, 46924), -- 10DU_Uldaman_FountainWater02 (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1
(@OGUID+36, 384636, 2451, 13968, 14144, '2,8,23,1', '0', 0, 773.37274169921875, -615.4598388671875, 195.4986572265625, 3.545702934265136718, 0, 0, -0.97965621948242187, 0.200682997703552246, 7200, 255, 1, 46924), -- 10DU_Uldaman_FountainWater02 (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1
(@OGUID+37, 384312, 2451, 13968, 14144, '2,8,23,1', '0', 0, 492.875, -641.701416015625, 208.9956817626953125, 4.697664260864257812, 0, 0, -0.71229362487792968, 0.701881647109985351, 7200, 255, 1, 46924), -- Ancient Volume (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1
(@OGUID+38, 384654, 2451, 13968, 14144, '2,8,23,1', '0', 0, 383.84027099609375, -814.375, 229.08837890625, 5.666731834411621093, 0, 0, -0.30336952209472656, 0.952872991561889648, 7200, 255, 1, 46924), -- Ancient Volume (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1
(@OGUID+39, 377257, 2451, 13968, 14144, '2,8,23,1', '0', 0, 629.83880615234375, -613.68408203125, 219.7007598876953125, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 1, 46924); -- Discs of Tyr (Area: Hall of the Keepers - Difficulty: Mythic) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+39;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0, 1, 20126, 0), -- Crumbling Rock Vein
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+3, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+4, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+5, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+6, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+7, 0, 0, 1, -0.00000004371138828, 0, 4543), -- Staff of Prehistoria
(@OGUID+8, 0, 0, 0, 1, 20126, 0), -- Crumbling Rock Vein
(@OGUID+9, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+10, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+11, 0, 0, 1, -0.00000004371138828, 0, 0), -- Vault Door
(@OGUID+12, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+13, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+14, 0, 0, 0, 1, 20126, 0), -- Crumbling Rock Vein
(@OGUID+16, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+17, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+18, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+19, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+20, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+21, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+22, 0, 0, 1, -0.00000004371138828, 0, 0), -- Vault Door
(@OGUID+23, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+24, 0, 0, 1, -0.00000004371138828, 0, 0), -- Vault Door
(@OGUID+25, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+26, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+27, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+29, 0, 0, 1, -0.00000004371138828, 0, 0), -- Stool
(@OGUID+31, 0, 0, 1, -0.00000004371138828, 0, 0), -- 10DU_Uldaman_FountainWater02
(@OGUID+32, 0, 0, 1, -0.00000004371138828, 0, 0), -- 10DU_Uldaman_FountainWater02
(@OGUID+33, 0, 0, 1, -0.00000004371138828, 0, 0), -- 10DU_Uldaman_FountainWater02
(@OGUID+34, 0, 0, 1, -0.00000004371138828, 0, 0), -- 10DU_Uldaman_FountainWater02
(@OGUID+35, 0, 0, 1, -0.00000004371138828, 0, 0), -- 10DU_Uldaman_FountainWater02
(@OGUID+36, 0, 0, 1, -0.00000004371138828, 0, 0), -- 10DU_Uldaman_FountainWater02
(@OGUID+39, 0, 0, 1, -0.00000004371138828, 0, 0); -- Discs of Tyr

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (191566 /*191566 (Eternal Orb) - Eternity Zone*/, 184125 /*184125 (Chrono-Lord Deios) - Sand Essence*/, 193777 /*193777 (Discs of Tyr)*/, 198213 /*198213 (Vault Keeper) - Purging Flames*/, 191220 /*191220 (Chrono-Lord Deios) - Sand Essence, Floating Sands, Empowering Sands*/, 195344 /*195344 (Refti Custodian) - Antique Constitution, Permanent Feign Death (NO Stun, Untrackable, Immune), Time Lock*/, 193299 /*193299 (Earthen Focus)*/, 191311 /*191311 (Infinite Whelp)*/, 184422 /*184422 (Emberon) - Denergize*/, 195511 /*195511 (Explorer's League Prospector) - Permanent Feign Death, Untrackable*/, 184335 /*184335 (Infinite Agent)*/, 195508 /*195508 (Explorer's League Scout) - Permanent Feign Death, Untrackable*/, 11073 /*11073 (Annora) - Permanent Feign Death (Untrackable, Uninteractible, Immune)*/, 186465 /*186465 (Skittering Crawler) - Permanent Feign Death, Untrackable*/, 191914 /*191914 (Eric "The Swift") - Dwarven Rage*/, 191913 /*191913 (Olaf) - Dwarven Rage*/, 191912 /*191912 (Baelog) - Dwarven Rage*/, 193530 /*193530 (Neglected Mole Machine) - Mole Machine*/, 193554 /*193554 (Neglected Mole Machine) - Mole Machine*/, 186664 /*186664 (Stonevault Ambusher) - Mod Scale 115-120%*/, 186696 /*186696 (Quaking Totem) - Spawn Visual*/, 186658 /*186658 (Stonevault Geomancer) - Mod Scale 115-120%*/, 186945 /*186945 (Longboat Raid) - Longboat Raid!*/, 189988 /*189988 (Thing From Beyond) - Avoidance*/, 186420 /*186420 (Earthen Weaver) - Cosmetic - Reading Book, Standing*/, 189085 /*189085 (Past Self) - Past Self*/, 110063 /*110063 (Beast) - Dire*/, 165189 /*165189 (Generic Hunter Pet) - Calcified Carapace*/, 184107 /*184107 (Runic Protector) - Invisibility and Stealth Detection*/, 184303 /*184303 (Skittering Crawler) - Venomous Fangs*/, 184301 /*184301 (Cavern Seeker)*/, 184124 /*184124 (Sentinel Talondras) - Inexorable, Inexorable, Inexorable, Inexorable*/, 186107 /*186107 (Vault Keeper) - Titanic Ward*/, 184331 /*184331 (Infinite Timereaver)*/, 184582 /*184582 (Eric "The Swift") - Dwarven Rage*/, 184581 /*184581 (Baelog) - Dwarven Rage*/, 184580 /*184580 (Olaf) - Dwarven Rage*/, 184319 /*184319 (Refti Custodian) - Antique Constitution, Invisibility and Stealth Detection*/, 191911 /*191911 (Door of Prehistoria)*/, 184131 /*184131 (Earthen Guardian)*/, 194269 /*194269 (Spiderling) - Squish*/, 191459 /*191459 (Longboat Raid) - Longboat Raid!*/, 184300 /*184300 (Ebonstone Golem) - Invisibility and Stealth Detection*/, 195343 /*195343 (Runic Protector) - Permanent Feign Death (NO Stun, Untrackable, Immune)*/, 184132 /*184132 (Earthen Warder) - Cosmetic - Reading Book, Standing*/, 191910 /*191910 (Staff of Prehistoria)*/, 184130 /*184130 (Earthen Custodian) - Cosmetic - Reading Book, Standing*/, 184018 /*184018 (Bromach)*/, 184019 /*184019 (Burly Rock-Thrower) - Mod Scale 115-120%*/, 184020 /*184020 (Hulking Berserker) - Mod Scale 115-120%, Reckless Rage*/, 184023 /*184023 (Vicious Basilisk)*/, 184022 /*184022 (Stonevault Geomancer) - Mod Scale 115-120%*/, 141587 /*141587 (Rat) - Mod Scale 115-120%*/, 184134 /*184134 (Scavenging Leaper) - Mod Scale 115-120%, Diggin'*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(191566, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '376271'), -- 191566 (Eternal Orb) - Eternity Zone
(184125, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 184125 (Chrono-Lord Deios) - Sand Essence
(193777, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 193777 (Discs of Tyr)
(198213, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '392673'), -- 198213 (Vault Keeper) - Purging Flames
(191220, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '375646 375648'), -- 191220 (Chrono-Lord Deios) - Sand Essence, Floating Sands, Empowering Sands
(193299, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 193299 (Earthen Focus)
(191311, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 191311 (Infinite Whelp)
(184422, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369101'), -- 184422 (Emberon) - Denergize
(195511, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '29266 28559'), -- 195511 (Explorer's League Prospector) - Permanent Feign Death, Untrackable
(184335, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 184335 (Infinite Agent)
(195508, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '29266 28559'), -- 195508 (Explorer's League Scout) - Permanent Feign Death, Untrackable
(11073, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '162323'), -- 11073 (Annora) - Permanent Feign Death (Untrackable, Uninteractible, Immune)
(186465, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '29266 28559'), -- 186465 (Skittering Crawler) - Permanent Feign Death, Untrackable
(191914, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '369995'), -- 191914 (Eric "The Swift") - Dwarven Rage
(191913, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '369994'), -- 191913 (Olaf) - Dwarven Rage
(191912, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '369993'), -- 191912 (Baelog) - Dwarven Rage
(193530, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '381847'), -- 193530 (Neglected Mole Machine) - Mole Machine
(193554, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '381847'), -- 193554 (Neglected Mole Machine) - Mole Machine
(186664, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123168'), -- 186664 (Stonevault Ambusher) - Mod Scale 115-120%
(186696, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '388314'), -- 186696 (Quaking Totem) - Spawn Visual
(186658, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123168'), -- 186658 (Stonevault Geomancer) - Mod Scale 115-120%
(186945, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '369861'), -- 186945 (Longboat Raid) - Longboat Raid!
(189988, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '65220'), -- 189988 (Thing From Beyond) - Avoidance
(186420, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 186420 (Earthen Weaver)
(189085, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '371869'), -- 189085 (Past Self) - Past Self
(110063, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '219197'), -- 110063 (Beast) - Dire
(184107, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '18950'), -- 184107 (Runic Protector) - Invisibility and Stealth Detection
(184303, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '369417'), -- 184303 (Skittering Crawler) - Venomous Fangs
(184301, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 184301 (Cavern Seeker)
(184124, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '372717 372600 372775 372778'), -- 184124 (Sentinel Talondras) - Inexorable, Inexorable, Inexorable, Inexorable
(186107, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 186107 (Vault Keeper) - Titanic Ward
(184331, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 184331 (Infinite Timereaver)
(184582, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369995'), -- 184582 (Eric "The Swift") - Dwarven Rage
(184581, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369993'), -- 184581 (Baelog) - Dwarven Rage
(184580, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '369994'), -- 184580 (Olaf) - Dwarven Rage
(184319, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '377723 18950'), -- 184319 (Refti Custodian) - Antique Constitution, Invisibility and Stealth Detection
(191911, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 191911 (Door of Prehistoria)
(184131, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 184131 (Earthen Guardian)
(194269, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '259242'), -- 194269 (Spiderling) - Squish
(191459, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, '375887'), -- 191459 (Longboat Raid) - Longboat Raid!
(184300, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '18950'), -- 184300 (Ebonstone Golem) - Invisibility and Stealth Detection
(184132, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 184132 (Earthen Warder)
(191910, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 191910 (Staff of Prehistoria)
(184130, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 184130 (Earthen Custodian)
(184018, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 184018 (Bromach)
(184019, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168'), -- 184019 (Burly Rock-Thrower) - Mod Scale 115-120%
(184020, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168 369807'), -- 184020 (Hulking Berserker) - Mod Scale 115-120%, Reckless Rage
(184023, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 184023 (Vicious Basilisk)
(184022, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168'), -- 184022 (Stonevault Geomancer) - Mod Scale 115-120%
(141587, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '123168'), -- 141587 (Rat) - Mod Scale 115-120%
(184134, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, '123168'); -- 184134 (Scavenging Leaper) - Mod Scale 115-120%; Diggin'

-- Template
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67108864, `unit_flags3`=16809985, `flags_extra` = 128 WHERE `entry` IN (212228, 210931, 211149, 211151, 211137, 211150, 211152, 210930, 211111); -- Path Helper
UPDATE `creature_template` SET `faction`=16, `speed_walk`=0.800000011920928955, `speed_run`=0.285714298486709594, `BaseAttackTime`=1500, `unit_flags`=33554752, `unit_flags3`=524289 WHERE `entry`=191566; -- Eternal Orb
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=320, `unit_flags2`=32, `unit_flags3`=1 WHERE `entry`=184125; -- Chrono-Lord Deios
UPDATE `creature_template` SET `faction`=16, `speed_walk`=0.800000011920928955, `speed_run`=0.285714298486709594, `BaseAttackTime`=1500, `unit_flags`=33554752, `unit_flags3`=1 WHERE `entry`=193777; -- Discs of Tyr
UPDATE `creature_template` SET `faction`=35, `speed_walk`=3.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=16777216 WHERE `entry`=198172; -- Ambient Sound Controller
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=16777216 WHERE `entry`=198213; -- Vault Keeper
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=320, `unit_flags2`=2048 WHERE `entry`=191220; -- Chrono-Lord Deios
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=195344; -- Refti Custodian
UPDATE `creature_template` SET `faction`=16, `speed_walk`=0.800000011920928955, `speed_run`=0.285714298486709594, `BaseAttackTime`=1500, `unit_flags`=33554752, `unit_flags3`=1 WHERE `entry`=193299; -- Earthen Focus
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2080 WHERE `entry`=191311; -- Infinite Whelp
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=64, `VehicleId`=8008 WHERE `entry`=184422; -- Emberon
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=195511; -- Explorer's League Prospector
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2080 WHERE `entry`=184335; -- Infinite Agent
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=195508; -- Explorer's League Scout
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=186465; -- Skittering Crawler
UPDATE `creature_template` SET `faction`=35, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=191914; -- Eric "The Swift"
UPDATE `creature_template` SET `faction`=35, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=191913; -- Olaf
UPDATE `creature_template` SET `faction`=35, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=191912; -- Baelog
UPDATE `creature_template` SET `faction`=190, `npcflag`=281474976710657, `speed_walk`=0.800000011920928955, `speed_run`=0.285714298486709594, `BaseAttackTime`=1500, `unit_flags`=320, `unit_flags2`=16416, `unit_flags3`=1 WHERE `entry`=193530; -- Neglected Mole Machine
UPDATE `creature_template` SET `faction`=190, `npcflag`=16777216, `speed_walk`=0.800000011920928955, `speed_run`=0.285714298486709594, `BaseAttackTime`=1500, `unit_flags`=320, `unit_flags2`=16384, `unit_flags3`=1 WHERE `entry`=193554; -- Neglected Mole Machine
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=186664; -- Stonevault Ambusher
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=524288 WHERE `entry`=186696; -- Quaking Totem
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=186658; -- Stonevault Geomancer
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.571428537368774414, `BaseAttackTime`=1500, `unit_flags`=33554688, `unit_flags2`=67110912, `unit_flags3`=1, `VehicleId`=7751 WHERE `entry` IN (186945, 191459); -- Longboat Raid
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=186420; -- Earthen Weaver
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184107; -- Runic Protector
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184303; -- Skittering Crawler
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184301; -- Cavern Seeker
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=2048 WHERE `entry`=186107; -- Vault Keeper
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2080 WHERE `entry`=184331; -- Infinite Timereaver
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184319; -- Refti Custodian
UPDATE `creature_template` SET `faction`=16, `speed_walk`=0.800000011920928955, `speed_run`=0.285714298486709594, `BaseAttackTime`=1500, `unit_flags`=33554752, `unit_flags3`=1 WHERE `entry`=191911; -- Door of Prehistoria
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184131; -- Earthen Guardian
UPDATE `creature_template` SET `faction`=190, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1 WHERE `entry`=194269; -- Spiderling
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184300; -- Ebonstone Golem
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=195343; -- Runic Protector
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184132; -- Earthen Warder
UPDATE `creature_template` SET `faction`=16, `speed_walk`=0.800000011920928955, `speed_run`=0.285714298486709594, `BaseAttackTime`=1500, `unit_flags`=33554752, `unit_flags3`=1 WHERE `entry`=191910; -- Staff of Prehistoria
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184130; -- Earthen Custodian
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184019; -- Burly Rock-Thrower
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184020; -- Hulking Berserker
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184023; -- Vicious Basilisk
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184022; -- Stonevault Geomancer
UPDATE `creature_template` SET `faction`=16, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=184134; -- Scavenging Leaper
UPDATE `creature_template` SET `faction`=16, `speed_walk`=2, `speed_run`=0.714285731315612792, `BaseAttackTime`=1500, `unit_flags`=64, `unit_flags3`=268435456 WHERE `entry`=184124; -- Sentinel Talondras
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=268435456 WHERE `entry`=184582; -- Eric "The Swift"
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=268435456 WHERE `entry`=184581; -- Baelog
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=268435456 WHERE `entry`=184580; -- Olaf
UPDATE `creature_template` SET `faction`=16, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=268435456 WHERE `entry`=184018; -- Bromach

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (191220,184335,191913,186664,186420,184124,184331,184582,184581,184580,184131,184130,184018,184020,184022));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(191220, 1, 119410, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Chrono-Lord Deios
(184335, 1, 12993, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Infinite Agent
(191913, 1, 0, 0, 0, 57452, 0, 0, 0, 0, 0, 46924), -- Olaf
(186664, 1, 107264, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Stonevault Ambusher
(186420, 1, 194960, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Earthen Weaver
(184124, 1, 192172, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Sentinel Talondras
(184331, 1, 191866, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Infinite Timereaver
(184582, 1, 152427, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Eric "The Swift"
(184581, 1, 0, 0, 0, 0, 0, 0, 5260, 0, 0, 46924), -- Baelog
(184580, 1, 0, 0, 0, 57452, 0, 0, 0, 0, 0, 46924), -- Olaf
(184131, 1, 111354, 0, 0, 193838, 0, 0, 0, 0, 0, 46924), -- Earthen Guardian
(184130, 1, 110165, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Earthen Custodian
(184018, 1, 133982, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Bromach
(184020, 1, 106885, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- Hulking Berserker
(184022, 1, 110280, 0, 0, 0, 0, 0, 0, 0, 0, 46924); -- Stonevault Geomancer

-- SpellScriptNames
DELETE FROM `spell_script_names` WHERE `spell_id` IN (162323, 28559, 159474);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(162323, 'spell_gen_feign_death_all_flags_uninteractible'),
(28559, 'spell_gen_feign_death_all_flags_uninteractible'),
(159474, 'spell_gen_feign_death_all_flags_no_uninteractible');

-- Difficulty (Normal)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=1 AND `Entry` IN (191566,184125,193777,198172,191220,195344,191311,212200,195511,195508,186465,191914,191913,191912,198489,212225,186945,184422,193530,213786,193554,186664,186658,184335,189649,186420,212228,215641,193299,186107,184301,184303,184107,184124,184331,191911,184319,184300,184131,184582,191459,184580,184132,184581,184130,184018,191910,195343,210931,184019,218647,218977,218646,210930,184022,184023,184020,211150,211149,211152,211151,211111,211137,184134)) OR (`DifficultyID`=0 AND `Entry` IN (193655,193650,193654,193653,193679,193678,193677,193675,193674,193652,193684,193680,193682,193686,193647,193644,193645,193648,213645));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(191566, 1, 9, 5, 1, 219771, 2097224, 128), -- Eternal Orb
(184125, 1, 9, 50, 1, 208024, 2097256, 128), -- Chrono-Lord Deios
(193777, 1, 9, 5, 1, 222006, 2097224, 0), -- Discs of Tyr
(198172, 1, 8, 0.100000001490116119, 1, 226544, 1073741824, 0), -- Ambient Sound Controller
(191220, 1, 9, 45, 1, 219425, 2097256, 0), -- Chrono-Lord Deios
(195344, 1, 9, 9, 1, 223584, 2097224, 0), -- Refti Custodian
(191311, 1, 9, 1, 1, 219516, 2097224, 0), -- Infinite Whelp
(212200, 1, 9, 1, 1, 261552, 1075839048, 34), -- Path Helper
(195511, 1, 9, 1, 1, 223751, 2097224, 0), -- Explorer's League Prospector
(195508, 1, 9, 1, 1, 223748, 2097224, 0), -- Explorer's League Scout
(186465, 1, 9, 4, 1, 210786, 2097224, 0), -- Skittering Crawler
(191914, 1, 9, 15, 1, 220123, 2097224, 0), -- Eric "The Swift"
(191913, 1, 9, 16, 1, 220122, 2097224, 0), -- Olaf
(191912, 1, 9, 15, 1, 220121, 2097224, 0), -- Baelog
(198489, 1, 9, 1, 2, 226868, 0, 0), -- Denizen of the Dream
(212225, 1, 9, 1, 1, 261577, 1075839048, 34), -- Path Helper
(186945, 1, 9, 1, 1, 211392, 2097160, 67108992), -- Longboat Raid
(184422, 1, 9, 25, 1, 226175, 2097256, 128), -- Emberon
(193530, 1, 9, 1, 1, 221751, 2097224, 0), -- Neglected Mole Machine
(213786, 1, 9, 1, 1, 263183, 1075839048, 34), -- Path Helper
(193554, 1, 9, 1, 1, 221775, 2097224, 0), -- Neglected Mole Machine
(186664, 1, 9, 2, 1, 227272, 2097224, 128), -- Stonevault Ambusher
(186658, 1, 9, 2, 1, 227269, 2097224, 128), -- Stonevault Geomancer
(184335, 1, 9, 6, 1, 208361, 2097224, 0), -- Infinite Agent
(189649, 1, 9, 1, 1, 216334, 1024, 0), -- Spell Bunny
(186420, 1, 9, 4.5, 1, 210741, 2097224, 0), -- Earthen Weaver
(212228, 1, 9, 1, 1, 261580, 1075839048, 34), -- Path Helper
(193655, 0, 9, 60, 1, 221876, 72, 65536), -- Frozion
(193650, 0, 9, 60, 1, 221871, 72, 65536), -- Emblazion
(193654, 0, 9, 60, 1, 221875, 72, 65536), -- Gravlion
(193653, 0, 9, 60, 1, 221874, 72, 65536), -- Gaelzion
(193679, 0, 9, 30, 1, 221900, 72, 65536), -- Leerain
(193678, 0, 9, 30, 1, 221899, 72, 65536), -- Fieraan
(193677, 0, 9, 30, 1, 221898, 72, 65536), -- Maeleera
(193675, 0, 9, 60, 1, 221896, 72, 65536), -- Kain Firebrand
(193674, 0, 9, 60, 1, 221895, 72, 65536), -- Voraazka
(193652, 0, 9, 60, 1, 221873, 72, 65536), -- Grizzlerock
(193684, 0, 9, 30, 1, 221905, 72, 65536), -- Pipspark Thundersnap
(193680, 0, 9, 60, 1, 221901, 72, 65536), -- Zurgaz Corebreaker
(193682, 0, 9, 60, 1, 221903, 72, 65536), -- Rouen Icewind
(193686, 0, 9, 30, 1, 221907, 72, 65536), -- Neela Firebane
(193647, 0, 9, 60, 1, 221868, 72, 65536), -- Karantun
(193644, 0, 9, 60, 1, 221865, 72, 65536), -- Bouldron
(193645, 0, 9, 60, 1, 221866, 72, 65536), -- Crystalus
(193648, 0, 9, 60, 1, 221869, 72, 65536), -- Infernum
(213645, 0, 9, 2.5, 1, 263049, 4096, 0), -- Captain Garrick
(215641, 1, 9, 1, 1, 265118, 1075839048, 34), -- Path Helper
(193299, 1, 9, 5, 1, 221515, 2097224, 0), -- Earthen Focus
(186107, 1, 9, 1.75, 1, 210406, 2097224, 128), -- Vault Keeper
(184301, 1, 9, 4, 1, 208325, 2097224, 0), -- Cavern Seeker
(184303, 1, 9, 4, 1, 208327, 2097224, 0), -- Skittering Crawler
(184107, 1, 9, 8, 1, 208005, 2097224, 0), -- Runic Protector
(184124, 1, 9, 35, 1, 208023, 2097256, 129), -- Sentinel Talondras
(184331, 1, 9, 8, 1, 208357, 2097224, 0), -- Infinite Timereaver
(191911, 1, 9, 5, 1, 220117, 2097224, 0), -- Door of Prehistoria
(184319, 1, 9, 9, 1, 208345, 2097224, 0), -- Refti Custodian
(184300, 1, 9, 9, 1, 208324, 2097224, 0), -- Ebonstone Golem
(184131, 1, 9, 8, 1, 208030, 2097224, 0), -- Earthen Guardian
(184582, 1, 9, 15, 1, 208637, 2097256, 128), -- Eric "The Swift"
(191459, 1, 9, 1, 1, 219664, 2097160, 67108992), -- Longboat Raid
(184580, 1, 9, 16, 1, 208635, 270532712, 128), -- Olaf
(184132, 1, 9, 4.25, 1, 208031, 2097224, 0), -- Earthen Warder
(184581, 1, 9, 15, 1, 208636, 270532712, 128), -- Baelog
(184130, 1, 9, 5, 1, 208029, 2097224, 0), -- Earthen Custodian
(184018, 1, 9, 30, 1, 207916, 2097256, 128), -- Bromach
(191910, 1, 9, 5, 1, 220116, 2097224, 0), -- Staff of Prehistoria
(195343, 1, 9, 8, 1, 223583, 2097224, 0), -- Runic Protector
(210931, 1, 9, 1, 1, 260280, 1075839048, 34), -- Path Helper
(184019, 1, 9, 5, 1, 207917, 2097224, 0), -- Burly Rock-Thrower
(218647, 1, 9, 1, 1, 268162, 0, 0), -- Glamrok
(218977, 1, 9, 1, 1, 268541, 0, 0), -- Happy
(218646, 1, 9, 1, 1, 268161, 0, 0), -- Bubbles
(210930, 1, 9, 1, 1, 260279, 1075839048, 34), -- Path Helper
(184022, 1, 9, 4.5, 1, 207920, 2097224, 0), -- Stonevault Geomancer
(184023, 1, 9, 4, 1, 207921, 2097225, 0), -- Vicious Basilisk
(184020, 1, 9, 7.5, 1, 207918, 2097224, 0), -- Hulking Berserker
(211150, 1, 9, 1, 1, 260501, 1075839048, 34), -- Path Helper
(211149, 1, 9, 1, 1, 260500, 1075839048, 34), -- Path Helper
(211152, 1, 9, 1, 1, 260503, 1075839048, 34), -- Path Helper
(211151, 1, 9, 1, 1, 260502, 1075839048, 34), -- Path Helper
(211111, 1, 9, 1, 1, 260460, 1075839048, 34), -- Path Helper
(211137, 1, 9, 1, 1, 260488, 1075839048, 34), -- Path Helper
(184134, 1, 9, 1.75, 1, 208033, 2097224, 0); -- Scavenging Leaper

UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `VerifiedBuild`=55664 WHERE (`Entry`=191566 AND `DifficultyID`=1); -- 191566 (Eternal Orb) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184125 AND `DifficultyID`=1); -- 184125 (Chrono-Lord Deios) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=536870912, `VerifiedBuild`=55664 WHERE (`Entry`=193777 AND `DifficultyID`=1); -- 193777 (Discs of Tyr) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2057, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=198172 AND `DifficultyID`=1); -- 198172 (Ambient Sound Controller) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2555, `StaticFlags1`=805306368, `VerifiedBuild`=55664 WHERE (`Entry`=191220 AND `DifficultyID`=1); -- 191220 (Chrono-Lord Deios) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2555, `StaticFlags1`=268435712, `VerifiedBuild`=55664 WHERE (`Entry`=195344 AND `DifficultyID`=1); -- 195344 (Refti Custodian) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=191311 AND `DifficultyID`=1); -- 191311 (Infinite Whelp) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=212200 AND `DifficultyID`=1); -- 212200 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435712, `VerifiedBuild`=55664 WHERE (`Entry`=195511 AND `DifficultyID`=1); -- 195511 (Explorer's League Prospector) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0, `VerifiedBuild`=55664 WHERE (`Entry`=11073 AND `DifficultyID`=1); -- 11073 (Annora) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435712, `VerifiedBuild`=55664 WHERE (`Entry`=195508 AND `DifficultyID`=1); -- 195508 (Explorer's League Scout) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435712, `VerifiedBuild`=55664 WHERE (`Entry`=186465 AND `DifficultyID`=1); -- 186465 (Skittering Crawler) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=191914 AND `DifficultyID`=1); -- 191914 (Eric "The Swift") - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=191913 AND `DifficultyID`=1); -- 191913 (Olaf) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=191912 AND `DifficultyID`=1); -- 191912 (Baelog) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=482, `StaticFlags3`=262144, `VerifiedBuild`=55664 WHERE (`Entry`=198489 AND `DifficultyID`=1); -- 198489 (Denizen of the Dream) - AllowInteractionWhileInCombat
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=212225 AND `DifficultyID`=1); -- 212225 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2555, `StaticFlags1`=536870912, `VerifiedBuild`=55664 WHERE (`Entry`=186945 AND `DifficultyID`=1); -- 186945 (Longboat Raid) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184422 AND `DifficultyID`=1); -- 184422 (Emberon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=536871168, `StaticFlags3`=33554432, `VerifiedBuild`=55664 WHERE (`Entry`=193530 AND `DifficultyID`=1); -- 193530 (Neglected Mole Machine) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=213786 AND `DifficultyID`=1); -- 213786 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=536871168, `VerifiedBuild`=55664 WHERE (`Entry`=193554 AND `DifficultyID`=1); -- 193554 (Neglected Mole Machine) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=186658 AND `DifficultyID`=1); -- 186658 (Stonevault Geomancer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=186664 AND `DifficultyID`=1); -- 186664 (Stonevault Ambusher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184335 AND `DifficultyID`=1); -- 184335 (Infinite Agent) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=536870912, `VerifiedBuild`=55664 WHERE (`Entry`=189649 AND `DifficultyID`=1); -- 189649 (Spell Bunny) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=186420 AND `DifficultyID`=1); -- 186420 (Earthen Weaver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=212228 AND `DifficultyID`=1); -- 212228 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=55664 WHERE (`DifficultyID`=0 AND `Entry`=2110) OR (`DifficultyID`=1 AND `Entry` IN (32258,15475));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=213645 AND `DifficultyID`=0); -- 213645 (Captain Garrick) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536870912, `VerifiedBuild`=55664 WHERE (`Entry`=2830 AND `DifficultyID`=1); -- 2830 (Parched Buzzard) - Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=4846 AND `DifficultyID`=1); -- 4846 (Shadowforge Digger) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=4844 AND `DifficultyID`=1); -- 4844 (Shadowforge Surveyor) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=215641 AND `DifficultyID`=1); -- 215641 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=536870912, `VerifiedBuild`=55664 WHERE (`Entry`=193299 AND `DifficultyID`=1); -- 193299 (Earthen Focus) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=186107 AND `DifficultyID`=1); -- 186107 (Vault Keeper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=805306368, `VerifiedBuild`=55664 WHERE (`Entry`=184301 AND `DifficultyID`=1); -- 184301 (Cavern Seeker) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184107 AND `DifficultyID`=1); -- 184107 (Runic Protector) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184303 AND `DifficultyID`=1); -- 184303 (Skittering Crawler) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184331 AND `DifficultyID`=1); -- 184331 (Infinite Timereaver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=536870912, `VerifiedBuild`=55664 WHERE (`Entry`=191911 AND `DifficultyID`=1); -- 191911 (Door of Prehistoria) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184124 AND `DifficultyID`=1); -- 184124 (Sentinel Talondras) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184131 AND `DifficultyID`=1); -- 184131 (Earthen Guardian) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184300 AND `DifficultyID`=1); -- 184300 (Ebonstone Golem) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184319 AND `DifficultyID`=1); -- 184319 (Refti Custodian) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184018 AND `DifficultyID`=1); -- 184018 (Bromach) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184132 AND `DifficultyID`=1); -- 184132 (Earthen Warder) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2555, `StaticFlags1`=536870912, `VerifiedBuild`=55664 WHERE (`Entry`=191459 AND `DifficultyID`=1); -- 191459 (Longboat Raid) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184130 AND `DifficultyID`=1); -- 184130 (Earthen Custodian) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=536870912, `VerifiedBuild`=55664 WHERE (`Entry`=191910 AND `DifficultyID`=1); -- 191910 (Staff of Prehistoria) - Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184582 AND `DifficultyID`=1); -- 184582 (Eric "The Swift") - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184581 AND `DifficultyID`=1); -- 184581 (Baelog) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184580 AND `DifficultyID`=1); -- 184580 (Olaf) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=210931 AND `DifficultyID`=1); -- 210931 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=195343 AND `DifficultyID`=1); -- 195343 (Runic Protector) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184019 AND `DifficultyID`=1); -- 184019 (Burly Rock-Thrower) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184023 AND `DifficultyID`=1); -- 184023 (Vicious Basilisk) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184020 AND `DifficultyID`=1); -- 184020 (Hulking Berserker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=211151 AND `DifficultyID`=1); -- 211151 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=211150 AND `DifficultyID`=1); -- 211150 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=211149 AND `DifficultyID`=1); -- 211149 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=210930 AND `DifficultyID`=1); -- 210930 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=211152 AND `DifficultyID`=1); -- 211152 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=211111 AND `DifficultyID`=1); -- 211111 (Path Helper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184022 AND `DifficultyID`=1); -- 184022 (Stonevault Geomancer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2555, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184134 AND `DifficultyID`=1); -- 184134 (Scavenging Leaper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2702, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=211137 AND `DifficultyID`=1); -- 211137 (Path Helper) - Sessile, CanSwim, Floating

-- Difficulty (Heroic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (198213,184422,186696,186664,186658,192573));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(198213, 2, 9, 2, 1, 226585, 1612709976, 67108870), -- Vault Keeper
(184422, 2, 9, 25, 1, 226176, 2097256, 128), -- Emberon
(186696, 2, 9, 1.799999952316284179, 1, 211021, 2097224, 67108992), -- Quaking Totem
(186664, 2, 9, 2, 1, 227273, 2097224, 128), -- Stonevault Ambusher
(186658, 2, 9, 2, 1, 227270, 2097224, 128), -- Stonevault Geomancer
(192573, 2, 9, 600, 1, 220783, 4, 0); -- Alexstrasza the Life-Binder

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (191566,184125,193777,198172,191220,195344,191311,212200,195511,11073,195508,186465,193299,184335,215641,191914,191913,191912,212225,193530,213786,193554,189649,198489,186945,186420,212228,184301,184303,186107,184107,191910,184018,191459,184582,184581,184124,184580,184300,210931,210930,184019,184331,195343,184131,191911,184132,184319,184130,184020,211111,184023,211152,184022,211150,211149,211151,211137,184134));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(191566, 2, 0, 0, 2156, 0, 0, 0, 0, 0, 0, 0, 0, 55664), -- 191566 (Eternal Orb) - 
(184125, 2, 2, 2, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184125 (Chrono-Lord Deios) - CanSwim
(193777, 2, 0, 0, 2156, 536870912, 0, 0, 0, 0, 0, 0, 0, 55664), -- 193777 (Discs of Tyr) - Floating
(198172, 2, 0, 0, 2057, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 198172 (Ambient Sound Controller) - CanSwim
(191220, 2, 2, 2, 2156, 805306368, 0, 0, 0, 0, 0, 0, 0, 55664), -- 191220 (Chrono-Lord Deios) - CanSwim, Floating
(195344, 2, 1, 1, 2156, 268435712, 0, 0, 0, 0, 0, 0, 0, 55664), -- 195344 (Refti Custodian) - Sessile, CanSwim
(191311, 2, 0, 0, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 191311 (Infinite Whelp) - CanSwim
(212200, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 212200 (Path Helper) - Sessile, CanSwim, Floating
(195511, 2, 0, 0, 2156, 268435712, 0, 0, 0, 0, 0, 0, 0, 55664), -- 195511 (Explorer's League Prospector) - Sessile, CanSwim
(11073, 2, 0, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 55664), -- 11073 (Annora) - 
(195508, 2, 0, 0, 2156, 268435712, 0, 0, 0, 0, 0, 0, 0, 55664), -- 195508 (Explorer's League Scout) - Sessile, CanSwim
(186465, 2, 0, 0, 2156, 268435712, 0, 0, 0, 0, 0, 0, 0, 55664), -- 186465 (Skittering Crawler) - Sessile, CanSwim
(193299, 2, 0, 0, 2156, 536870912, 0, 0, 0, 0, 0, 0, 0, 55664), -- 193299 (Earthen Focus) - Floating
(184335, 2, 0, 0, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184335 (Infinite Agent) - CanSwim
(215641, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 215641 (Path Helper) - Sessile, CanSwim, Floating
(191914, 2, 2, 2, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 191914 (Eric "The Swift") - CanSwim
(191913, 2, 2, 2, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 191913 (Olaf) - CanSwim
(191912, 2, 2, 2, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 191912 (Baelog) - CanSwim
(212225, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 212225 (Path Helper) - Sessile, CanSwim, Floating
(193530, 2, 0, 0, 2156, 536871168, 0, 33554432, 0, 0, 0, 0, 0, 55664), -- 193530 (Neglected Mole Machine) - Sessile, Floating - CannotTurn
(213786, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 213786 (Path Helper) - Sessile, CanSwim, Floating
(193554, 2, 0, 0, 2156, 536871168, 0, 0, 0, 0, 0, 0, 0, 55664), -- 193554 (Neglected Mole Machine) - Sessile, Floating
(189649, 2, 0, 0, 2156, 536870912, 0, 0, 0, 0, 0, 0, 0, 55664), -- 189649 (Spell Bunny) - Floating
(198489, 2, 0, 0, 482, 0, 0, 262144, 0, 0, 0, 0, 0, 55664), -- 198489 (Denizen of the Dream) - AllowInteractionWhileInCombat
(186945, 2, 1, 1, 2156, 536870912, 0, 0, 0, 0, 0, 0, 0, 55664), -- 186945 (Longboat Raid) - Floating
(186420, 2, 0, 0, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 186420 (Earthen Weaver) - CanSwim
(212228, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 212228 (Path Helper) - Sessile, CanSwim, Floating
(184301, 2, 0, 0, 2156, 805306368, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184301 (Cavern Seeker) - CanSwim, Floating
(184303, 2, 0, 0, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184303 (Skittering Crawler) - CanSwim
(186107, 2, 0, 0, 2156, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 186107 (Vault Keeper) - Sessile, CanSwim, Floating
(184107, 2, 1, 1, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184107 (Runic Protector) - CanSwim
(191910, 2, 0, 0, 2156, 536870912, 0, 0, 0, 0, 0, 0, 0, 55664), -- 191910 (Staff of Prehistoria) - Floating
(184018, 2, 2, 2, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184018 (Bromach) - CanSwim
(191459, 2, 1, 1, 2156, 536870912, 0, 0, 0, 0, 0, 0, 0, 55664), -- 191459 (Longboat Raid) - Floating
(184582, 2, 2, 2, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184582 (Eric "The Swift") - CanSwim
(184581, 2, 2, 2, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184581 (Baelog) - CanSwim
(184124, 2, 2, 2, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184124 (Sentinel Talondras) - CanSwim
(184580, 2, 2, 2, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184580 (Olaf) - CanSwim
(184300, 2, 1, 1, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184300 (Ebonstone Golem) - CanSwim
(210931, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 210931 (Path Helper) - Sessile, CanSwim, Floating
(210930, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 210930 (Path Helper) - Sessile, CanSwim, Floating
(184019, 2, 0, 0, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184019 (Burly Rock-Thrower) - CanSwim
(184331, 2, 1, 1, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184331 (Infinite Timereaver) - CanSwim
(195343, 2, 1, 1, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 195343 (Runic Protector) - CanSwim
(184131, 2, 1, 1, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184131 (Earthen Guardian) - CanSwim
(191911, 2, 0, 0, 2156, 536870912, 0, 0, 0, 0, 0, 0, 0, 55664), -- 191911 (Door of Prehistoria) - Floating
(184132, 2, 0, 0, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184132 (Earthen Warder) - CanSwim
(184319, 2, 1, 1, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184319 (Refti Custodian) - CanSwim
(184130, 2, 0, 0, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184130 (Earthen Custodian) - CanSwim
(184020, 2, 1, 1, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184020 (Hulking Berserker) - CanSwim
(211111, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 211111 (Path Helper) - Sessile, CanSwim, Floating
(184023, 2, 0, 0, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184023 (Vicious Basilisk) - CanSwim
(211152, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 211152 (Path Helper) - Sessile, CanSwim, Floating
(184022, 2, 0, 0, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664), -- 184022 (Stonevault Geomancer) - CanSwim
(211150, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 211150 (Path Helper) - Sessile, CanSwim, Floating
(211149, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 211149 (Path Helper) - Sessile, CanSwim, Floating
(211151, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 211151 (Path Helper) - Sessile, CanSwim, Floating
(211137, 2, 0, 0, 2702, 805306624, 0, 0, 0, 0, 0, 0, 0, 55664), -- 211137 (Path Helper) - Sessile, CanSwim, Floating
(184134, 2, 0, 0, 2156, 268435456, 0, 0, 0, 0, 0, 0, 0, 55664); -- 184134 (Scavenging Leaper) - CanSwim

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=219771, `TypeFlags`=2097224, `TypeFlags2`=128 WHERE (`Entry`=191566 AND `DifficultyID`=2); -- Eternal Orb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=50, `CreatureDifficultyID`=208024, `TypeFlags`=2097256, `TypeFlags2`=128 WHERE (`Entry`=184125 AND `DifficultyID`=2); -- Chrono-Lord Deios
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=222006, `TypeFlags`=2097224 WHERE (`Entry`=193777 AND `DifficultyID`=2); -- Discs of Tyr
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.100000001490116119, `CreatureDifficultyID`=226544, `TypeFlags`=1073741824 WHERE (`Entry`=198172 AND `DifficultyID`=2); -- Ambient Sound Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=45, `CreatureDifficultyID`=219425, `TypeFlags`=2097256 WHERE (`Entry`=191220 AND `DifficultyID`=2); -- Chrono-Lord Deios
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=9, `CreatureDifficultyID`=223584, `TypeFlags`=2097224 WHERE (`Entry`=195344 AND `DifficultyID`=2); -- Refti Custodian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=219516, `TypeFlags`=2097224 WHERE (`Entry`=191311 AND `DifficultyID`=2); -- Infinite Whelp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=261552, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=212200 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=223751, `TypeFlags`=2097224 WHERE (`Entry`=195511 AND `DifficultyID`=2); -- Explorer's League Prospector
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=223748, `TypeFlags`=2097224 WHERE (`Entry`=195508 AND `DifficultyID`=2); -- Explorer's League Scout
UPDATE `creature_template_difficulty` SET `HealthModifier`=1.299999952316284179, `CreatureDifficultyID`=7558 WHERE (`Entry`=11073 AND `DifficultyID`=2); -- Annora
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=4, `CreatureDifficultyID`=210786, `TypeFlags`=2097224 WHERE (`Entry`=186465 AND `DifficultyID`=2); -- Skittering Crawler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=265118, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=215641 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=221515, `TypeFlags`=2097224 WHERE (`Entry`=193299 AND `DifficultyID`=2); -- Earthen Focus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=6, `CreatureDifficultyID`=208361, `TypeFlags`=2097224 WHERE (`Entry`=184335 AND `DifficultyID`=2); -- Infinite Agent
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=15, `CreatureDifficultyID`=220123, `TypeFlags`=2097224 WHERE (`Entry`=191914 AND `DifficultyID`=2); -- Eric "The Swift"
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=16, `CreatureDifficultyID`=220122, `TypeFlags`=2097224 WHERE (`Entry`=191913 AND `DifficultyID`=2); -- Olaf
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=15, `CreatureDifficultyID`=220121, `TypeFlags`=2097224 WHERE (`Entry`=191912 AND `DifficultyID`=2); -- Baelog
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=261577, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=212225 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=221751, `TypeFlags`=2097224 WHERE (`Entry`=193530 AND `DifficultyID`=2); -- Neglected Mole Machine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=263183, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=213786 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=221775, `TypeFlags`=2097224 WHERE (`Entry`=193554 AND `DifficultyID`=2); -- Neglected Mole Machine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=216334, `TypeFlags`=1024 WHERE (`Entry`=189649 AND `DifficultyID`=2); -- Spell Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `ManaModifier`=2, `CreatureDifficultyID`=226868 WHERE (`Entry`=198489 AND `DifficultyID`=2); -- Denizen of the Dream
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=211392, `TypeFlags`=2097160, `TypeFlags2`=67108992 WHERE (`Entry`=186945 AND `DifficultyID`=2); -- Longboat Raid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=4.5, `CreatureDifficultyID`=210741, `TypeFlags`=2097224 WHERE (`Entry`=186420 AND `DifficultyID`=2); -- Earthen Weaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=261580, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=212228 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=4, `CreatureDifficultyID`=208325, `TypeFlags`=2097224 WHERE (`Entry`=184301 AND `DifficultyID`=2); -- Cavern Seeker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=4, `CreatureDifficultyID`=208327, `TypeFlags`=2097224 WHERE (`Entry`=184303 AND `DifficultyID`=2); -- Skittering Crawler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=8, `CreatureDifficultyID`=208005, `TypeFlags`=2097224 WHERE (`Entry`=184107 AND `DifficultyID`=2); -- Runic Protector
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=1.75, `CreatureDifficultyID`=210406, `TypeFlags`=2097224, `TypeFlags2`=128 WHERE (`Entry`=186107 AND `DifficultyID`=2); -- Vault Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=8, `CreatureDifficultyID`=208357, `TypeFlags`=2097224 WHERE (`Entry`=184331 AND `DifficultyID`=2); -- Infinite Timereaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=35, `CreatureDifficultyID`=208023, `TypeFlags`=2097256, `TypeFlags2`=129 WHERE (`Entry`=184124 AND `DifficultyID`=2); -- Sentinel Talondras
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=219664, `TypeFlags`=2097160, `TypeFlags2`=67108992 WHERE (`Entry`=191459 AND `DifficultyID`=2); -- Longboat Raid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=220117, `TypeFlags`=2097224 WHERE (`Entry`=191911 AND `DifficultyID`=2); -- Door of Prehistoria
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=15, `CreatureDifficultyID`=208637, `TypeFlags`=2097256, `TypeFlags2`=128 WHERE (`Entry`=184582 AND `DifficultyID`=2); -- Eric "The Swift"
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=9, `CreatureDifficultyID`=208345, `TypeFlags`=2097224 WHERE (`Entry`=184319 AND `DifficultyID`=2); -- Refti Custodian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=9, `CreatureDifficultyID`=208324, `TypeFlags`=2097224 WHERE (`Entry`=184300 AND `DifficultyID`=2); -- Ebonstone Golem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=8, `CreatureDifficultyID`=208030, `TypeFlags`=2097224 WHERE (`Entry`=184131 AND `DifficultyID`=2); -- Earthen Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=16, `CreatureDifficultyID`=208635, `TypeFlags`=270532712, `TypeFlags2`=128 WHERE (`Entry`=184580 AND `DifficultyID`=2); -- Olaf
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=15, `CreatureDifficultyID`=208636, `TypeFlags`=270532712, `TypeFlags2`=128 WHERE (`Entry`=184581 AND `DifficultyID`=2); -- Baelog
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=4.25, `CreatureDifficultyID`=208031, `TypeFlags`=2097224 WHERE (`Entry`=184132 AND `DifficultyID`=2); -- Earthen Warder
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=208029, `TypeFlags`=2097224 WHERE (`Entry`=184130 AND `DifficultyID`=2); -- Earthen Custodian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=30, `CreatureDifficultyID`=207916, `TypeFlags`=2097256, `TypeFlags2`=128 WHERE (`Entry`=184018 AND `DifficultyID`=2); -- Bromach
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=220116, `TypeFlags`=2097224 WHERE (`Entry`=191910 AND `DifficultyID`=2); -- Staff of Prehistoria
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=8, `CreatureDifficultyID`=223583, `TypeFlags`=2097224 WHERE (`Entry`=195343 AND `DifficultyID`=2); -- Runic Protector
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=260280, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=210931 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=260279, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=210930 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=207917, `TypeFlags`=2097224 WHERE (`Entry`=184019 AND `DifficultyID`=2); -- Burly Rock-Thrower
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=4.5, `CreatureDifficultyID`=207920, `TypeFlags`=2097224 WHERE (`Entry`=184022 AND `DifficultyID`=2); -- Stonevault Geomancer
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=7.5, `CreatureDifficultyID`=207918, `TypeFlags`=2097224 WHERE (`Entry`=184020 AND `DifficultyID`=2); -- Hulking Berserker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=1.75, `CreatureDifficultyID`=208033, `TypeFlags`=2097224 WHERE (`Entry`=184134 AND `DifficultyID`=2); -- Scavenging Leaper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=4, `CreatureDifficultyID`=207921, `TypeFlags`=2097225 WHERE (`Entry`=184023 AND `DifficultyID`=2); -- Vicious Basilisk
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=260488, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=211137 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=260502, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=211151 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=260500, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=211149 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=260503, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=211152 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=260460, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=211111 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=260501, `TypeFlags`=1075839048, `TypeFlags2`=34 WHERE (`Entry`=211150 AND `DifficultyID`=2); -- Path Helper
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2156, `StaticFlags1`=805306624, `VerifiedBuild`=55664 WHERE (`Entry`=198213 AND `DifficultyID`=2); -- 198213 (Vault Keeper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2156, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=184422 AND `DifficultyID`=2); -- 184422 (Emberon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2156, `StaticFlags1`=805306624, `StaticFlags3`=33554432, `VerifiedBuild`=55664 WHERE (`Entry`=186696 AND `DifficultyID`=2); -- 186696 (Quaking Totem) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2156, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=186658 AND `DifficultyID`=2); -- 186658 (Stonevault Geomancer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2156, `StaticFlags1`=268435456, `VerifiedBuild`=55664 WHERE (`Entry`=186664 AND `DifficultyID`=2); -- 186664 (Stonevault Ambusher) - CanSwim

-- Difficulty (Mythic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (184125,184422,184335,186664,186696,186658,189988,186420,189085,188274,185903,184301,186107,194269,184132,184018,184019,184022,184023,184020,184134));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`) VALUES
(184125, 23, 9, 55, 1, 208024, 2097256, 128), -- Chrono-Lord Deios
(184422, 23, 9, 25, 1, 226177, 2097256, 128), -- Emberon
(184335, 23, 9, 8, 1, 208361, 2097224, 0), -- Infinite Agent
(186664, 23, 9, 3, 1, 227274, 2097224, 128), -- Stonevault Ambusher
(186696, 23, 9, 2, 1, 211021, 2097224, 67108992), -- Quaking Totem
(186658, 23, 9, 3, 1, 227271, 2097224, 128), -- Stonevault Geomancer
(189988, 23, 9, 1, 1, 216677, 0, 1), -- Thing From Beyond
(186420, 23, 9, 5, 1, 210741, 2097224, 0), -- Earthen Weaver
(189085, 23, 9, 1, 1, 215771, 83894272, 0), -- Past Self
(188274, 23, 9, 4, 1, 214960, 2147483721, 0), -- Sutaan
(185903, 23, 9, 1, 1, 210168, 1, 0), -- Ravenous Rockfang
(184301, 23, 9, 5, 1, 208325, 2097224, 0), -- Cavern Seeker
(186107, 23, 9, 2, 1, 210406, 2097224, 128), -- Vault Keeper
(194269, 23, 9, 1, 1, 222498, 0, 0), -- Spiderling
(184132, 23, 9, 4.5, 1, 208031, 2097224, 0), -- Earthen Warder
(184018, 23, 9, 28, 1, 207916, 2097256, 128), -- Bromach
(184019, 23, 9, 6, 1, 207917, 2097224, 0), -- Burly Rock-Thrower
(184022, 23, 9, 5, 1, 207920, 2097224, 0), -- Stonevault Geomancer
(184023, 23, 9, 5.5, 1, 207921, 2097225, 0), -- Vicious Basilisk
(184020, 23, 9, 8, 1, 207918, 2097224, 0), -- Hulking Berserker
(184134, 23, 9, 2, 1, 208033, 2097224, 0); -- Scavenging Leaper

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=23 AND `Entry` IN (191566,193777,198172,198213,191220,195344,193299,191311,195511,195508,11073,186465,191914,191913,191912,193530,193554,189649,186945,184107,184303,184124,184331,184582,184581,184580,184319,191911,184131,191459,184300,195343,191910,184130));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(191566, 23, 0, 0, 2157, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- 191566 (Eternal Orb) - 
(193777, 23, 0, 0, 2157, 536870912, 0, 0, 0, 0, 0, 0, 0, 46924), -- 193777 (Discs of Tyr) - Floating
(198172, 23, 0, 0, 2057, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 198172 (Ambient Sound Controller) - CanSwim
(198213, 23, 0, 0, 2157, 805306624, 0, 0, 0, 0, 0, 0, 0, 46924), -- 198213 (Vault Keeper) - Sessile, CanSwim, Floating
(191220, 23, 2, 2, 2157, 805306368, 0, 0, 0, 0, 0, 0, 0, 46924), -- 191220 (Chrono-Lord Deios) - CanSwim, Floating
(195344, 23, 1, 1, 2157, 268435712, 0, 0, 0, 0, 0, 0, 0, 46924), -- 195344 (Refti Custodian) - Sessile, CanSwim
(193299, 23, 0, 0, 2157, 536870912, 0, 0, 0, 0, 0, 0, 0, 46924), -- 193299 (Earthen Focus) - Floating
(191311, 23, 0, 0, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 191311 (Infinite Whelp) - CanSwim
(195511, 23, 0, 0, 2157, 268435712, 0, 0, 0, 0, 0, 0, 0, 46924), -- 195511 (Explorer's League Prospector) - Sessile, CanSwim
(195508, 23, 0, 0, 2157, 268435712, 0, 0, 0, 0, 0, 0, 0, 46924), -- 195508 (Explorer's League Scout) - Sessile, CanSwim
(11073, 23, 0, 0, 217, 0, 0, 0, 0, 0, 0, 0, 0, 46924), -- 11073 (Annora) - 
(186465, 23, 0, 0, 2157, 268435712, 0, 0, 0, 0, 0, 0, 0, 46924), -- 186465 (Skittering Crawler) - Sessile, CanSwim
(191914, 23, 2, 2, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 191914 (Eric "The Swift") - CanSwim
(191913, 23, 2, 2, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 191913 (Olaf) - CanSwim
(191912, 23, 2, 2, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 191912 (Baelog) - CanSwim
(193530, 23, 0, 0, 2157, 536871168, 0, 33554432, 0, 0, 0, 0, 0, 46924), -- 193530 (Neglected Mole Machine) - Sessile, Floating - CannotTurn
(193554, 23, 0, 0, 2157, 536871168, 0, 0, 0, 0, 0, 0, 0, 46924), -- 193554 (Neglected Mole Machine) - Sessile, Floating
(189649, 23, 0, 0, 2157, 536870912, 0, 0, 0, 0, 0, 0, 0, 46924), -- 189649 (Spell Bunny) - Floating
(186945, 23, 1, 1, 2157, 536870912, 0, 0, 0, 0, 0, 0, 0, 46924), -- 186945 (Longboat Raid) - Floating
(184107, 23, 1, 1, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 184107 (Runic Protector) - CanSwim
(184303, 23, 0, 0, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 184303 (Skittering Crawler) - CanSwim
(184124, 23, 2, 2, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 184124 (Sentinel Talondras) - CanSwim
(184331, 23, 1, 1, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 184331 (Infinite Timereaver) - CanSwim
(184582, 23, 2, 2, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 184582 (Eric "The Swift") - CanSwim
(184581, 23, 2, 2, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 184581 (Baelog) - CanSwim
(184580, 23, 2, 2, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 184580 (Olaf) - CanSwim
(184319, 23, 1, 1, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 184319 (Refti Custodian) - CanSwim
(191911, 23, 0, 0, 2157, 536870912, 0, 0, 0, 0, 0, 0, 0, 46924), -- 191911 (Door of Prehistoria) - Floating
(184131, 23, 1, 1, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 184131 (Earthen Guardian) - CanSwim
(191459, 23, 1, 1, 2157, 536870912, 0, 0, 0, 0, 0, 0, 0, 46924), -- 191459 (Longboat Raid) - Floating
(184300, 23, 1, 1, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 184300 (Ebonstone Golem) - CanSwim
(195343, 23, 1, 1, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924), -- 195343 (Runic Protector) - CanSwim
(191910, 23, 0, 0, 2157, 536870912, 0, 0, 0, 0, 0, 0, 0, 46924), -- 191910 (Staff of Prehistoria) - Floating
(184130, 23, 0, 0, 2157, 268435456, 0, 0, 0, 0, 0, 0, 0, 46924); -- 184130 (Earthen Custodian) - CanSwim

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=219771, `TypeFlags`=2097224, `TypeFlags2`=128 WHERE (`Entry`=191566 AND `DifficultyID`=23); -- Eternal Orb
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=222006, `TypeFlags`=2097224 WHERE (`Entry`=193777 AND `DifficultyID`=23); -- Discs of Tyr
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=8, `HealthModifier`=0.100000001490116119, `CreatureDifficultyID`=226544, `TypeFlags`=1073741824 WHERE (`Entry`=198172 AND `DifficultyID`=23); -- Ambient Sound Controller
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=2, `CreatureDifficultyID`=226585, `TypeFlags`=1612709976, `TypeFlags2`=67108870 WHERE (`Entry`=198213 AND `DifficultyID`=23); -- Vault Keeper
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=45, `CreatureDifficultyID`=219425, `TypeFlags`=2097256 WHERE (`Entry`=191220 AND `DifficultyID`=23); -- Chrono-Lord Deios
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=9, `CreatureDifficultyID`=223584, `TypeFlags`=2097224 WHERE (`Entry`=195344 AND `DifficultyID`=23); -- Refti Custodian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=221515, `TypeFlags`=2097224 WHERE (`Entry`=193299 AND `DifficultyID`=23); -- Earthen Focus
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=219516, `TypeFlags`=2097224 WHERE (`Entry`=191311 AND `DifficultyID`=23); -- Infinite Whelp
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=223751, `TypeFlags`=2097224 WHERE (`Entry`=195511 AND `DifficultyID`=23); -- Explorer's League Prospector
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=223748, `TypeFlags`=2097224 WHERE (`Entry`=195508 AND `DifficultyID`=23); -- Explorer's League Scout
UPDATE `creature_template_difficulty` SET `HealthModifier`=1.299999952316284179, `CreatureDifficultyID`=7558 WHERE (`Entry`=11073 AND `DifficultyID`=23); -- Annora
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=4, `CreatureDifficultyID`=210786, `TypeFlags`=2097224 WHERE (`Entry`=186465 AND `DifficultyID`=23); -- Skittering Crawler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=15, `CreatureDifficultyID`=220123, `TypeFlags`=2097224 WHERE (`Entry`=191914 AND `DifficultyID`=23); -- Eric "The Swift"
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=16, `CreatureDifficultyID`=220122, `TypeFlags`=2097224 WHERE (`Entry`=191913 AND `DifficultyID`=23); -- Olaf
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=15, `CreatureDifficultyID`=220121, `TypeFlags`=2097224 WHERE (`Entry`=191912 AND `DifficultyID`=23); -- Baelog
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=221751, `TypeFlags`=2097224 WHERE (`Entry`=193530 AND `DifficultyID`=23); -- Neglected Mole Machine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=221775, `TypeFlags`=2097224 WHERE (`Entry`=193554 AND `DifficultyID`=23); -- Neglected Mole Machine
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=216334, `TypeFlags`=1024 WHERE (`Entry`=189649 AND `DifficultyID`=23); -- Spell Bunny
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=211392, `TypeFlags`=2097160, `TypeFlags2`=67108992 WHERE (`Entry`=186945 AND `DifficultyID`=23); -- Longboat Raid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=8, `CreatureDifficultyID`=208005, `TypeFlags`=2097224 WHERE (`Entry`=184107 AND `DifficultyID`=23); -- Runic Protector
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=4, `CreatureDifficultyID`=208327, `TypeFlags`=2097224 WHERE (`Entry`=184303 AND `DifficultyID`=23); -- Skittering Crawler
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=35, `CreatureDifficultyID`=208023, `TypeFlags`=2097256, `TypeFlags2`=129 WHERE (`Entry`=184124 AND `DifficultyID`=23); -- Sentinel Talondras
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=8, `CreatureDifficultyID`=208357, `TypeFlags`=2097224 WHERE (`Entry`=184331 AND `DifficultyID`=23); -- Infinite Timereaver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=9, `CreatureDifficultyID`=208345, `TypeFlags`=2097224 WHERE (`Entry`=184319 AND `DifficultyID`=23); -- Refti Custodian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `CreatureDifficultyID`=219664, `TypeFlags`=2097160, `TypeFlags2`=67108992 WHERE (`Entry`=191459 AND `DifficultyID`=23); -- Longboat Raid
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=220117, `TypeFlags`=2097224 WHERE (`Entry`=191911 AND `DifficultyID`=23); -- Door of Prehistoria
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=15, `CreatureDifficultyID`=208637, `TypeFlags`=2097256, `TypeFlags2`=128 WHERE (`Entry`=184582 AND `DifficultyID`=23); -- Eric "The Swift"
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=15, `CreatureDifficultyID`=208636, `TypeFlags`=270532712, `TypeFlags2`=128 WHERE (`Entry`=184581 AND `DifficultyID`=23); -- Baelog
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=16, `CreatureDifficultyID`=208635, `TypeFlags`=270532712, `TypeFlags2`=128 WHERE (`Entry`=184580 AND `DifficultyID`=23); -- Olaf
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=9, `CreatureDifficultyID`=208324, `TypeFlags`=2097224 WHERE (`Entry`=184300 AND `DifficultyID`=23); -- Ebonstone Golem
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=8, `CreatureDifficultyID`=208030, `TypeFlags`=2097224 WHERE (`Entry`=184131 AND `DifficultyID`=23); -- Earthen Guardian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=208029, `TypeFlags`=2097224 WHERE (`Entry`=184130 AND `DifficultyID`=23); -- Earthen Custodian
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=5, `CreatureDifficultyID`=220116, `TypeFlags`=2097224 WHERE (`Entry`=191910 AND `DifficultyID`=23); -- Staff of Prehistoria
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=9, `HealthModifier`=8, `CreatureDifficultyID`=223583, `TypeFlags`=2097224 WHERE (`Entry`=195343 AND `DifficultyID`=23); -- Runic Protector
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=184125 AND `DifficultyID`=23); -- 184125 (Chrono-Lord Deios) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=184422 AND `DifficultyID`=23); -- 184422 (Emberon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=184335 AND `DifficultyID`=23); -- 184335 (Infinite Agent) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=186664 AND `DifficultyID`=23); -- 186664 (Stonevault Ambusher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=805306624, `StaticFlags3`=33554432, `VerifiedBuild`=46924 WHERE (`Entry`=186696 AND `DifficultyID`=23); -- 186696 (Quaking Totem) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=186658 AND `DifficultyID`=23); -- 186658 (Stonevault Geomancer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=186420 AND `DifficultyID`=23); -- 186420 (Earthen Weaver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=482, `StaticFlags1`=805306624, `VerifiedBuild`=46924 WHERE (`Entry`=189085 AND `DifficultyID`=23); -- 189085 (Past Self) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=805306368, `VerifiedBuild`=46924 WHERE (`Entry`=184301 AND `DifficultyID`=23); -- 184301 (Cavern Seeker) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=805306624, `VerifiedBuild`=46924 WHERE (`Entry`=186107 AND `DifficultyID`=23); -- 186107 (Vault Keeper) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `VerifiedBuild`=46924 WHERE (`Entry`=194269 AND `DifficultyID`=23); -- 194269 (Spiderling) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=184132 AND `DifficultyID`=23); -- 184132 (Earthen Warder) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=184018 AND `DifficultyID`=23); -- 184018 (Bromach) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=184019 AND `DifficultyID`=23); -- 184019 (Burly Rock-Thrower) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=184020 AND `DifficultyID`=23); -- 184020 (Hulking Berserker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=184023 AND `DifficultyID`=23); -- 184023 (Vicious Basilisk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=184022 AND `DifficultyID`=23); -- 184022 (Stonevault Geomancer) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2157, `StaticFlags1`=268435456, `VerifiedBuild`=46924 WHERE (`Entry`=184134 AND `DifficultyID`=23); -- 184134 (Scavenging Leaper) - CanSwim

-- Path for Hulking Berserker
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+9;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+9, @CGUID+9, 0, 0, 515, 2, 11),
(@CGUID+9, @CGUID+5, 3, 300, 515, 2, 11);

SET @ENTRY := 184020;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Hulking Berserker - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 150.9705, -1030.097, 228.2411, NULL, 0),
(@PATH, 1, 146.1337, -1029.047, 228.2844, NULL, 0),
(@PATH, 2, 139.7483, -1028.911, 228.2844, NULL, 5334),
(@PATH, 3, 146.1337, -1029.047, 228.2844, NULL, 0),
(@PATH, 4, 150.9705, -1030.097, 228.2411, NULL, 0),
(@PATH, 5, 152.9931, -1033.504, 228.1535, NULL, 0),
(@PATH, 6, 153.4844, -1043.142, 228.2614, NULL, 0),
(@PATH, 7, 153.309, -1053.929, 228.3192, NULL, 0),
(@PATH, 8, 153.3021, -1056.26, 228.2311, NULL, 0),
(@PATH, 9, 150.8333, -1059.241, 228.2462, NULL, 0),
(@PATH, 10, 148.651, -1059.545, 228.2844, NULL, 0),
(@PATH, 11, 146.1198, -1059.59, 228.3364, NULL, 5501),
(@PATH, 12, 150.8333, -1059.241, 228.2462, NULL, 0),
(@PATH, 13, 153.3021, -1056.26, 228.2311, NULL, 0),
(@PATH, 14, 153.309, -1053.929, 228.3192, NULL, 0),
(@PATH, 15, 153.4844, -1043.142, 228.2614, NULL, 0),
(@PATH, 16, 152.9931, -1033.504, 228.1535, NULL, 0);

UPDATE `creature` SET `position_x`= 150.9705, `position_y`= -1030.097, `position_z`= 228.2411, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+9;
UPDATE `creature` SET `position_x`= 150.9705, `position_y`= -1030.097, `position_z`= 228.2411 WHERE `guid`= @CGUID+5;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+9;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+9, @PATH, 1);

-- Path for Emberon
SET @ENTRY := 184422;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Emberon - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 294.8177, -607.6268, 211.2252, NULL, 0),
(@PATH, 1, 281.4392, -609.6493, 211.187, NULL, 0),
(@PATH, 2, 274.6979, -608.6962, 211.2844, NULL, 0),
(@PATH, 3, 267.2309, -604.1077, 211.2844, NULL, 0),
(@PATH, 4, 260.6823, -590.1458, 211.3806, NULL, 0),
(@PATH, 5, 260.2969, -581.8386, 211.4514, NULL, 0),
(@PATH, 6, 263.3424, -574.3845, 211.3009, NULL, 0),
(@PATH, 7, 268.3333, -568.0278, 211.2235, NULL, 0),
(@PATH, 8, 276.7917, -563.0035, 211.1924, NULL, 0),
(@PATH, 9, 286.8524, -561.5121, 211.1861, NULL, 0),
(@PATH, 10, 294.2813, -564.3993, 211.3012, NULL, 0),
(@PATH, 11, 304.1354, -570.993, 211.2251, NULL, 0),
(@PATH, 12, 307.8785, -577.2917, 211.1923, NULL, 0),
(@PATH, 13, 308.8351, -585.7118, 211.1769, NULL, 0),
(@PATH, 14, 306.375, -595.3472, 211.2844, NULL, 0),
(@PATH, 15, 301.1094, -603.4097, 211.2601, NULL, 0);

UPDATE `creature` SET `position_x`= 294.8177, `position_y`= -607.6268, `position_z`= 211.2252, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+200;
UPDATE `creature_template_addon` SET `PathId` = @PATH WHERE `entry` = @ENTRY;

-- Path for Refti Custodian
SET @ENTRY := 184319;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Refti Custodian - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 87.11806, -808.5695, 229.4875, NULL, 0),
(@PATH, 1, 93.87153, -808.7864, 229.4875, NULL, 0),
(@PATH, 2, 101.5382, -808.8004, 229.5266, NULL, 4375),
(@PATH, 3, 93.87153, -808.7864, 229.4875, NULL, 0),
(@PATH, 4, 87.11806, -808.5695, 229.4875, NULL, 0),
(@PATH, 5, 78.45486, -808.7292, 229.2552, NULL, 0),
(@PATH, 6, 68.65972, -807.5833, 227.9465, NULL, 0),
(@PATH, 7, 58.3316, -806.7327, 227.2844, NULL, 4442),
(@PATH, 8, 68.56504, -807.5755, 227.8845, NULL, 0),
(@PATH, 9, 78.45486, -808.7292, 229.2552, NULL, 0);

UPDATE `creature` SET `position_x`= 87.11806, `position_y`= -808.5695, `position_z`= 229.4875, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+89;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+89;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@CGUID+89, @PATH, 1, '377723 18950');

-- Path for Earthen Guardian
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+74;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+74, @CGUID+74, 0, 0, 515, 4, 9),
(@CGUID+74, @CGUID+62, 3, 300, 515, 4, 9),
(@CGUID+74, @CGUID+63, 3, 60, 515, 4, 9);

SET @ENTRY := 184131;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Earthen Guardian - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 291.1233, -798.2465, 215.9655, NULL, 0),
(@PATH, 1, 288.6736, -783.5538, 215.5752, NULL, 0),
(@PATH, 2, 294.2222, -774.1996, 213.7347, NULL, 0),
(@PATH, 3, 299.1424, -767.1788, 212.295, NULL, 0),
(@PATH, 4, 307.4528, -762.0431, 211.8926, NULL, 3943),
(@PATH, 5, 299.1424, -767.1788, 212.295, NULL, 0),
(@PATH, 6, 294.2222, -774.1996, 213.7347, NULL, 0),
(@PATH, 7, 288.6736, -783.5538, 215.5752, NULL, 0),
(@PATH, 8, 291.1233, -798.2465, 215.9655, NULL, 0),
(@PATH, 9, 294.8665, -813.1329, 217.512, NULL, 3960);

UPDATE `creature` SET `position_x`= 291.1233, `position_y`= -798.2465, `position_z`= 215.9655, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+74;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+74;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+74, @PATH, 1);

-- Path for Infinite Timereaver
SET @ENTRY := 184331;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Infinite Timereaver - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 495.7292, -674.6285, 209.0969, NULL, 0),
(@PATH, 1, 496.4445, -667.0746, 209.0969, NULL, 4020),
(@PATH, 2, 495.7292, -674.6285, 209.0969, NULL, 0),
(@PATH, 3, 500.8681, -678.7813, 209.1192, NULL, 4032);

UPDATE `creature` SET `position_x`= 495.7292, `position_y`= -674.6285, `position_z`= 209.0969, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+205;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+205;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+205, @PATH, 1);
