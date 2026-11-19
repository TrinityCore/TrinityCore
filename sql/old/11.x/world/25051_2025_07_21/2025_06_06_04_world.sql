SET @CGUID := 6002301;
SET @OGUID := 6002319;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+415;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 95766, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3173.026123046875, 1967.2708740234375, 216.045318603515625, 1.129136562347412109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crazed Razorbeak (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+1, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3080.4130859375, 1686.98046875, 141.8519439697265625, 3.305698871612548828, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+2, 101679, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3175.98095703125, 1833.6910400390625, 216.8489532470703125, 4.361325740814208984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Poisoner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+3, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3087.745361328125, 1692.5341796875, 141.9624176025390625, 1.271840095520019531, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+4, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3121.83154296875, 1582.3228759765625, 136.6192779541015625, 2.941237688064575195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+5, 95766, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3152.704833984375, 2056.10595703125, 205.5086822509765625, 4.567013263702392578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crazed Razorbeak (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+6, 95779, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3078.632080078125, 1902.6649169921875, 205.8631134033203125, 6.198259353637695312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Festerhide Grizzly (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+7, 100403, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2881.4931640625, 1967.5538330078125, 189.7886505126953125, 3.280079126358032226, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Druidic Preserver (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+8, 103344, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3021.096435546875, 1744.451416015625, 141.90155029296875, 3.04861307144165039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Oakheart (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 165950 - Deep Roots, 218987 - Oakheart Auto Attack Sounds, 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+9, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3126.118896484375, 1599.5555419921875, 136.283905029296875, 2.941237688064575195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+10, 95772, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3121.862060546875, 1968.1319580078125, 205.922882080078125, 1.808841347694396972, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Frenzied Nightclaw (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+11, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3098.8447265625, 1601.670166015625, 136.5464935302734375, 3.415503501892089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+12, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3176.8994140625, 1917.032958984375, 215.217010498046875, 3.319208383560180664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+13, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3115.84912109375, 1587.975341796875, 137.4802093505859375, 2.728613138198852539, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3081.0625, 1639.9010009765625, 136.774200439453125, 5.476709842681884765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+15, 95779, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3221.153564453125, 1856.0069580078125, 214.27862548828125, 1.891584157943725585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Festerhide Grizzly (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+16, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3100.1962890625, 1641.99658203125, 136.98291015625, 4.883166313171386718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+17, 101679, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3075.59814453125, 1932.0694580078125, 205.596893310546875, 3.262818336486816406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Poisoner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+18, 95771, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3149.729248046875, 2044.9427490234375, 205.16839599609375, 1.95502936840057373, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Ruiner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+19, 95766, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3146.596435546875, 2052.69091796875, 205.46527099609375, 5.023776531219482421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crazed Razorbeak (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+20, 95779, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3067.061767578125, 1907.8992919921875, 206.1483612060546875, 1.197031259536743164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Festerhide Grizzly (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+21, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3074.0087890625, 1908.82470703125, 205.7921295166015625, 1.094562411308288574, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+22, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3125.26220703125, 1605.829833984375, 136.3777923583984375, 2.941237688064575195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+23, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3095.1572265625, 1609.8472900390625, 136.51983642578125, 3.415503501892089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+24, 101991, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2926.5322265625, 1748.4739990234375, 145.6834564208984375, 2.53952789306640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Dweller (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+25, 95771, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3173.51904296875, 1978.03125, 215.42999267578125, 4.666612625122070312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Ruiner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+26, 95769, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3067.8095703125, 1750.8924560546875, 274.667327880859375, 4.91750335693359375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Mindshattered Screecher (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+27, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3080.053955078125, 1609.765625, 136.737091064453125, 1.460832834243774414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+28, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3082.335205078125, 1643.8385009765625, 137.003448486328125, 5.476709842681884765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+29, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3205.241455078125, 1937.8177490234375, 216.414276123046875, 1.240940332412719726, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+30, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3101.04345703125, 1639.3541259765625, 137.257080078125, 4.883166313171386718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+31, 95771, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3118.7509765625, 1975.2274169921875, 206.433868408203125, 4.979496479034423828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Ruiner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+32, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3125.338623046875, 1619.8507080078125, 139.5033721923828125, 5.516174793243408203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+33, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3081.022705078125, 1677.1064453125, 141.7228851318359375, 1.870300889015197753, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+34, 95769, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3177.71240234375, 1803.0740966796875, 245.7323455810546875, 5.179020404815673828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Mindshattered Screecher (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+35, 101991, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2999.893310546875, 1771.7691650390625, 142.2218017578125, 0.776527345180511474, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Dweller (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+36, 95769, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3148.862060546875, 1731.591796875, 274.1669921875, 4.734587669372558593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Mindshattered Screecher (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+37, 95772, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3172.538330078125, 1866.7413330078125, 217.523834228515625, 5.36971902847290039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Frenzied Nightclaw (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader, 55701 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+38, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3078.81591796875, 1613.5364990234375, 136.4409637451171875, 1.460832834243774414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+39, 95771, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3122.24560546875, 1972.43408203125, 206.552276611328125, 6.229771137237548828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Ruiner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+40, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3189.239501953125, 2024.9879150390625, 206.916473388671875, 4.602356910705566406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+41, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3089.77685546875, 1675.246826171875, 140.761810302734375, 4.937259674072265625, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+42, 101679, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3108.334228515625, 1998.4722900390625, 205.2881927490234375, 3.508889436721801757, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Poisoner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+43, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3121.5322265625, 1591.4739990234375, 136.461578369140625, 2.941237688064575195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+44, 100403, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2908.12841796875, 1982.53125, 190.1481170654296875, 0.474445343017578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Druidic Preserver (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+45, 95769, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3000.86279296875, 1932.392333984375, 199.4947357177734375, 0.391862839460372924, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Mindshattered Screecher (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+46, 95772, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3067.87841796875, 1942.826416015625, 206.211639404296875, 0.603837668895721435, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Frenzied Nightclaw (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+47, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3171.686767578125, 1856.1441650390625, 215.3274383544921875, 4.302588939666748046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+48, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3096.599853515625, 1604.376708984375, 136.544403076171875, 3.415503501892089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+49, 95779, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3209.843017578125, 1942.0677490234375, 216.404510498046875, 2.88196420669555664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Festerhide Grizzly (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+50, 101679, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3200.087646484375, 1941.6336669921875, 216.342010498046875, 6.154707908630371093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Poisoner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+51, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3068.6181640625, 1916.8680419921875, 205.6707305908203125, 5.609584808349609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+52, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3208.889892578125, 1948.2708740234375, 216.341094970703125, 1.015835046768188476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+53, 95779, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3197.717041015625, 2042.2742919921875, 205.4849395751953125, 4.301177501678466796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Festerhide Grizzly (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+54, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3111.15966796875, 1582.4759521484375, 137.32330322265625, 0.36330077052116394, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+55, 101679, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3073.194580078125, 1942.079833984375, 205.5049896240234375, 3.002068758010864257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Poisoner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+56, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3088.83154296875, 1673.0145263671875, 140.6869049072265625, 2.987396240234375, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+57, 95771, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3162.96923828125, 1891.6009521484375, 214.5116424560546875, 1.704407453536987304, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Ruiner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader) (possible waypoints or random movement)
(@CGUID+58, 95779, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2956.940185546875, 1954.69970703125, 189.5443267822265625, 5.32967376708984375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Festerhide Grizzly (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+59, 100403, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2882.958251953125, 1952.3541259765625, 190.08343505859375, 4.509955883026123046, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Druidic Preserver (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+60, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3122.244873046875, 1597.4947509765625, 136.1370697021484375, 2.941237688064575195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+61, 95772, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3066.78466796875, 1929.7447509765625, 205.4876708984375, 0.036214727908372879, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Frenzied Nightclaw (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+62, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3097.919189453125, 1598.1180419921875, 136.5719451904296875, 3.415503501892089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+63, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3201.50439453125, 1876.3629150390625, 215.06549072265625, 4.695870399475097656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+64, 95769, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3147.0859375, 1872.4774169921875, 219.3874359130859375, 5.56574869155883789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Mindshattered Screecher (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+65, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3081.584228515625, 1646.670166015625, 137.0895538330078125, 5.476709842681884765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+66, 95779, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3207.170166015625, 2032.4271240234375, 205.4849395751953125, 3.409024000167846679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Festerhide Grizzly (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+67, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3097.6181640625, 1640.5069580078125, 136.84027099609375, 4.883166313171386718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+68, 101679, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3007.368896484375, 1934.796875, 198.9202117919921875, 0.891750991344451904, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Poisoner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+69, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3102.866455078125, 1636.6597900390625, 137.885406494140625, 4.883166313171386718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+70, 95771, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3165.9453125, 1891.9732666015625, 214.3617095947265625, 1.698170304298400878, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Ruiner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader) (possible waypoints or random movement)
(@CGUID+71, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3161.70751953125, 1912.8472900390625, 213.0225677490234375, 5.20697784423828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+72, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3087.723876953125, 1682.2362060546875, 141.6096343994140625, 0.537380218505859375, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+73, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3119.934814453125, 1586.4947509765625, 136.3856658935546875, 2.941237688064575195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+74, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3119.603271484375, 1598.6666259765625, 136.288299560546875, 2.941237688064575195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+75, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3091.897705078125, 1591.8541259765625, 137.061187744140625, 5.732283592224121093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+76, 101991, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2970.544677734375, 1752.0450439453125, 141.88043212890625, 3.226922273635864257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Dweller (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+77, 95769, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3179.296875, 1869.57470703125, 220.981781005859375, 3.8600921630859375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Mindshattered Screecher (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+78, 95772, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3169.209228515625, 1830.1822509765625, 216.7613677978515625, 0.473665565252304077, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Frenzied Nightclaw (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+79, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3166.665771484375, 1918.6163330078125, 214.120147705078125, 1.24661719799041748, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+80, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3080.7822265625, 1615.8177490234375, 136.693878173828125, 1.460832834243774414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+81, 95772, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3107.856689453125, 1992.5347900390625, 205.1597137451171875, 3.665262699127197265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Frenzied Nightclaw (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+82, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3204.291748046875, 1933.907958984375, 216.444061279296875, 0.553230166435241699, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+83, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3078.397705078125, 1618.9010009765625, 136.8078155517578125, 1.460832834243774414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+84, 100531, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3102.1240234375, 1609.24951171875, 137.350128173828125, 5.381920814514160156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Bloodtainted Fury (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+85, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3208.096435546875, 1884.3038330078125, 214.986480712890625, 5.516174793243408203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+86, 101679, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3155.541748046875, 2048.84716796875, 204.6464080810546875, 2.427679061889648437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Poisoner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+87, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3091.53271484375, 1676.9195556640625, 140.806884765625, 5.79949951171875, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+88, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3122.153564453125, 1585.217041015625, 136.845489501953125, 2.941237688064575195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+89, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3197.87841796875, 2023.5555419921875, 207.0689697265625, 6.270686626434326171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+90, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3208.348876953125, 1881.2413330078125, 214.923248291015625, 0.22552819550037384, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+91, 95772, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3173.33154296875, 1828.2725830078125, 216.9722137451171875, 1.389292359352111816, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Frenzied Nightclaw (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+92, 95772, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3112.1044921875, 1939.605224609375, 205.182037353515625, 5.546204090118408203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Frenzied Nightclaw (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+93, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3211.809814453125, 1948.607666015625, 216.3592681884765625, 0.22552819550037384, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+94, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3069.0947265625, 1929.545166015625, 205.4849090576171875, 5.516174793243408203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+95, 95766, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3165.822998046875, 1975.5660400390625, 214.9424591064453125, 0.350272268056869506, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Crazed Razorbeak (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+96, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3083.3330078125, 1666.6669921875, 140.5497589111328125, 4.085953712463378906, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+97, 101679, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3077.0556640625, 1956.5382080078125, 203.396636962890625, 5.044626235961914062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Poisoner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader) (possible waypoints or random movement)
(@CGUID+98, 95779, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2954.45751953125, 1966.1632080078125, 189.558135986328125, 0.153801813721656799, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Festerhide Grizzly (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+99, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3169.58154296875, 1862.234375, 215.4186553955078125, 0.22552819550037384, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+100, 95779, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3166.459228515625, 1911.5225830078125, 214.5399322509765625, 4.046029090881347656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Festerhide Grizzly (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+101, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3161.677978515625, 1909.517333984375, 213.356475830078125, 4.587428569793701171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+102, 100403, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2895.059814453125, 1946.4375, 189.809722900390625, 5.037143707275390625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Druidic Preserver (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+103, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3202.95751953125, 1943.7760009765625, 216.341461181640625, 5.642032623291015625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+104, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3122.1572265625, 1601.2117919921875, 136.240875244140625, 2.941237688064575195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+105, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3098.108642578125, 1607.28125, 136.650909423828125, 3.415503501892089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+106, 95772, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3118.727294921875, 1942.082763671875, 204.9502105712890625, 4.943912982940673828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Frenzied Nightclaw (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+107, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3206.140625, 2029.30908203125, 205.4849395751953125, 6.180327415466308593, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+108, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3079.6728515625, 1637.1788330078125, 136.713226318359375, 5.476709842681884765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+109, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3105.197998046875, 1638.173583984375, 138.6006927490234375, 4.883166313171386718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+110, 95771, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3146.692626953125, 2031.7535400390625, 204.5186614990234375, 0.857998073101043701, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Ruiner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader) (possible waypoints or random movement)
(@CGUID+111, 95771, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3104.2734375, 1989.8802490234375, 205.6336822509765625, 0.637599349021911621, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Ruiner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+112, 95779, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3112.06591796875, 1913.6441650390625, 205.994415283203125, 1.891584157943725585, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Festerhide Grizzly (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+113, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3203.70654296875, 1881.84375, 214.986480712890625, 4.191301345825195312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+114, 101679, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3118.587646484375, 1932.3663330078125, 205.2764739990234375, 4.490993022918701171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Poisoner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader) (possible waypoints or random movement)
(@CGUID+115, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3163.9765625, 1907.279541015625, 213.890625, 5.20697784423828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+116, 101991, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2964.019287109375, 1767.762451171875, 141.8322296142578125, 3.935121536254882812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Dweller (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+117, 95771, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3204.04248046875, 1948.0816650390625, 216.3086395263671875, 5.053982257843017578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Ruiner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+118, 95769, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3173.115478515625, 1874.1041259765625, 219.134552001953125, 4.181176185607910156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Mindshattered Screecher (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+119, 95769, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3099.005126953125, 1999.7239990234375, 210.8522491455078125, 5.36971902847290039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Mindshattered Screecher (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+120, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3107.7080078125, 1592.6077880859375, 137.3378448486328125, 0.695252180099487304, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+121, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3079.65283203125, 1642.3072509765625, 136.7940673828125, 5.476709842681884765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+122, 95772, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3137.923828125, 2026.671630859375, 205.263427734375, 0.880341649055480957, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Frenzied Nightclaw (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader) (possible waypoints or random movement)
(@CGUID+123, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3220.112060546875, 1859.625, 214.326751708984375, 3.291383743286132812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+124, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3080.835205078125, 1611.892333984375, 136.6527862548828125, 1.460832834243774414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+125, 95771, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3072.461669921875, 1954.5347900390625, 203.2425384521484375, 5.159012794494628906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadsoul Ruiner (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader) (possible waypoints or random movement)
(@CGUID+126, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3218.140625, 1947.421875, 216.415313720703125, 5.516174793243408203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+127, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3101.3193359375, 1669.4638671875, 140.2072906494140625, 5.66654205322265625, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+128, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3121.75439453125, 1587.654541015625, 136.703125, 2.941237688064575195, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+129, 101991, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2964.877685546875, 1775.5604248046875, 141.671539306640625, 0.982572376728057861, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Dweller (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+130, 95769, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3149.76611328125, 1816.5843505859375, 274.832763671875, 4.751138687133789062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Mindshattered Screecher (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+131, 95772, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3116.3134765625, 1966.329833984375, 205.813629150390625, 1.745428800582885742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Frenzied Nightclaw (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader)
(@CGUID+132, 95772, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3143.380859375, 2022.1748046875, 205.1208648681640625, 0.880186140537261962, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Frenzied Nightclaw (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 195110 - Dungeon Temp Nightmare Shader) (possible waypoints or random movement)
(@CGUID+133, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3071.78466796875, 1902.0035400390625, 205.7034149169921875, 1.751203060150146484, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+134, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3089.77001953125, 1588.875, 136.7725677490234375, 5.732283592224121093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+135, 96512, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2859.0634765625, 1921.376708984375, 190.6622314453125, 1.377102971076965332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Archdruid Glaidalis (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 355784 - [DNT] Send Event <Points> On Enter Combat) (possible waypoints or random movement)
(@CGUID+136, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3120.200439453125, 1571.1632080078125, 136.796905517578125, 4.532831192016601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+137, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3110.958740234375, 1575.4874267578125, 137.3383636474609375, 3.082542657852172851, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+138, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3088.296875, 1591.54345703125, 137.126007080078125, 5.732283592224121093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+139, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3117.849853515625, 1566.4149169921875, 137.057525634765625, 4.532831192016601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+140, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2961.611083984375, 1955.545166015625, 189.75, 3.022137165069580078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+141, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3099.677978515625, 1579.130859375, 137.3378448486328125, 0.696587204933166503, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+142, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3120.47216796875, 1567.9930419921875, 136.779510498046875, 4.532831192016601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+143, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2960.287353515625, 1950.7239990234375, 189.8792572021484375, 2.627848625183105468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+144, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3105.944580078125, 1576.5484619140625, 137.3384552001953125, 0.10224577784538269, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+145, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3087.502685546875, 1583.7239990234375, 136.334320068359375, 5.732283592224121093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+146, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2964.81689453125, 1954.2847900390625, 189.967071533203125, 1.24661719799041748, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+147, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3088.678955078125, 1586.251708984375, 136.5870361328125, 5.732283592224121093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+148, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3107.66748046875, 1573.677001953125, 137.46343994140625, 3.100368976593017578, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+149, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2963.701416015625, 1959.90625, 189.823638916015625, 3.152631998062133789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+150, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3118.154541015625, 1569.4166259765625, 136.652587890625, 4.532831192016601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+151, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2968.288330078125, 1962.513916015625, 190.056427001953125, 2.664785623550415039, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+152, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2958.6728515625, 1960.154541015625, 189.623809814453125, 0.749228179454803466, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+153, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2959.803955078125, 1963.96875, 189.5804901123046875, 1.24661719799041748, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+154, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2963.712646484375, 1963.0625, 189.719940185546875, 0.065945193171501159, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+155, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3085.056396484375, 1576.9930419921875, 136.886260986328125, 3.577846527099609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+156, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2956.052001953125, 1958.2117919921875, 189.563018798828125, 2.398187637329101562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+157, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2961.58251953125, 1966.1978759765625, 189.512451171875, 3.1178436279296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+158, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3102.17822265625, 1573.4578857421875, 137.5008392333984375, 1.115882158279418945, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+159, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3087.8671875, 1574.3680419921875, 136.9429779052734375, 3.577846527099609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+160, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3083.650146484375, 1574.0885009765625, 136.8150634765625, 3.577846527099609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+161, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3112.3056640625, 1566.075439453125, 137.6906280517578125, 3.029905557632446289, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+162, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3115.825439453125, 1564.4879150390625, 137.084869384765625, 4.532831192016601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+163, 99365, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3009.30029296875, 1644.0728759765625, 135.417999267578125, 3.909996509552001953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Taintheart Stalker (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+164, 100539, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2997.317626953125, 1652.0069580078125, 134.4937286376953125, 4.385021686553955078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Taintheart Deadeye (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+165, 100539, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 3000.3603515625, 1656.204833984375, 134.3670654296875, 1.335525751113891601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Taintheart Deadeye (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+166, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3086.248291015625, 1572.0660400390625, 136.81170654296875, 3.577846527099609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+167, 100400, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2951.71875, 1961.015625, 189.605255126953125, 3.9295654296875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+168, 100529, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3083.366455078125, 1567.22509765625, 137.86431884765625, 6.073319911956787109, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+169, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3104.1728515625, 1559.09033203125, 137.13397216796875, 6.052779197692871093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+170, 100533, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 3082.673583984375, 1571.0625, 136.737823486328125, 3.577846527099609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+171, 100404, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2929.159423828125, 1962.1229248046875, 189.7689361572265625, 1.247607707977294921, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Perserver Ray Invisible Stalker (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+172, 111221, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2908.59033203125, 1966.5867919921875, 189.790191650390625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Xal'atath (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+173, 99360, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2896.38134765625, 1761.0911865234375, 153.98388671875, 3.132927179336547851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+174, 99360, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2896.4296875, 1768.1619873046875, 154.1669769287109375, 3.133739709854125976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+175, 100404, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2899.932861328125, 1935.0968017578125, 190.2258148193359375, 3.308646917343139648, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Perserver Ray Invisible Stalker (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+176, 107638, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 1, 2914.62841796875, 1968.670166015625, 189.790191650390625, 5.797448158264160156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Druidic Preserver (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@CGUID+177, 102851, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2896.708251953125, 1967.3489990234375, 189.141082763671875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shield Invisible Stalker (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: 203257 - Giant Shield)
(@CGUID+178, 100404, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2880.32373046875, 1939.061767578125, 189.97808837890625, 5.769999027252197265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Perserver Ray Invisible Stalker (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+179, 100404, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 0, 0, 2914.440673828125, 1994.61865234375, 189.9283447265625, 2.589361429214477539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Perserver Ray Invisible Stalker (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1 (Auras: )
(@CGUID+180, 100404, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2864.2216796875, 1972.44287109375, 190.3155364990234375, 1.319841384887695312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Perserver Ray Invisible Stalker (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+181, 99358, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 1, 2898.47802734375, 1764.78125, 153.1816558837890625, 6.138111114501953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Rotheart Dryad (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+182, 99358, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 1, 2790.903564453125, 1952.3680419921875, 184.96722412109375, 2.487015008926391601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Rotheart Dryad (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+183, 99360, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2785.430419921875, 1954.0206298828125, 185.481964111328125, 3.166965961456298828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+184, 99360, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2779.67822265625, 1947.8023681640625, 185.0550079345703125, 0.949933469295501708, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+185, 99358, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 1, 2771.473876953125, 1901.77783203125, 185.4447174072265625, 4.2144012451171875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Rotheart Dryad (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+186, 99360, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2770.8330078125, 1896.875, 185.7332305908203125, 1.2864762544631958, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+187, 99359, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2765.35595703125, 1900.1597900390625, 185.791290283203125, 5.404621124267578125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Rotheart Keeper (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1
(@CGUID+188, 99360, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2760.70458984375, 1892.124267578125, 185.6893310546875, 0.361052691936492919, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+189, 99360, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2770.185791015625, 1832.91015625, 184.978179931640625, 1.373988986015319824, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+190, 99360, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2761.147216796875, 1847.59521484375, 184.978179931640625, 2.527431011199951171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+191, 99360, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2757.104248046875, 1841.8031005859375, 184.978179931640625, 2.522929191589355468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+192, 99359, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2765.34033203125, 1817.1927490234375, 185.5163116455078125, 0.79311227798461914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Rotheart Keeper (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1
(@CGUID+193, 99359, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2769.4150390625, 1822.0260009765625, 185.26153564453125, 2.83089447021484375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Rotheart Keeper (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1
(@CGUID+194, 99360, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2776.32861328125, 1818.212646484375, 185.92144775390625, 3.975762367248535156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+195, 99358, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 1, 2751.75927734375, 1849.9796142578125, 184.978179931640625, 2.410423755645751953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Rotheart Dryad (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+196, 99360, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2708.7119140625, 1803.78076171875, 185.9521026611328125, 5.42859649658203125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+197, 99360, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2706.68798828125, 1810.946044921875, 185.502716064453125, 1.495867729187011718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+198, 100400, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 1, 2700.713623046875, 1805.3367919921875, 185.8152923583984375, 5.516174793243408203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dead Perserver Druid (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (Auras: 146007 - Spawn Dead)
(@CGUID+199, 99360, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2695.469482421875, 1813.4542236328125, 185.6283416748046875, 3.9028167724609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+200, 99360, 1466, 7673, 8100, '1,2,8,23,24', 0, 0, 0, 0, 2694.49658203125, 1807.3428955078125, 185.4925537109375, 3.102792263031005859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Vilethorn Blossom (Area: The Rotting Grotto - Difficulty: Heroic) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+201, 99365, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2951.103271484375, 1662.91845703125, 124.0630569458007812, 4.21728515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Taintheart Stalker (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+202, 99365, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2949.760498046875, 1650.9132080078125, 122.4742431640625, 2.144927263259887695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Taintheart Stalker (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+203, 100527, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2955.579833984375, 1657.671875, 123.6450424194335937, 0.199534684419631958, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadfire Imp (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 191262 - Nightmare Imp Spawn)
(@CGUID+204, 99366, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 1, 2956.134521484375, 1652.7586669921875, 122.8748931884765625, 0.279656410217285156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Taintheart Summoner (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+205, 99366, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 1, 2863.77001953125, 1571.96826171875, 106.34613037109375, 0.927535951137542724, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Taintheart Summoner (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+206, 100527, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2857.1865234375, 1569.0804443359375, 109.0809478759765625, 0.976495087146759033, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadfire Imp (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 191262 - Nightmare Imp Spawn)
(@CGUID+207, 100527, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2863.695556640625, 1565.9703369140625, 107.762237548828125, 0.927808582782745361, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadfire Imp (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 191262 - Nightmare Imp Spawn)
(@CGUID+208, 100527, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2859.6337890625, 1549.8836669921875, 111.33038330078125, 1.25435948371887207, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadfire Imp (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 191262 - Nightmare Imp Spawn)
(@CGUID+209, 100527, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2852.353271484375, 1552.4774169921875, 110.6430282592773437, 0.599203765392303466, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadfire Imp (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 191262 - Nightmare Imp Spawn)
(@CGUID+210, 100526, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2997.385498046875, 1622.031982421875, 108.865081787109375, 5.2074737548828125, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Tormented Bloodseeker (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+211, 99366, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 1, 2852.20654296875, 1544.3541259765625, 111.1829071044921875, 0.92206573486328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Taintheart Summoner (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+212, 99365, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2860.572021484375, 1546.7413330078125, 112.9158554077148437, 1.050479650497436523, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Taintheart Stalker (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+213, 100526, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2991.571044921875, 1625.774658203125, 108.83544921875, 2.930639982223510742, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Tormented Bloodseeker (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+214, 100526, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2982.971435546875, 1606.3392333984375, 109.2361679077148437, 3.276724815368652343, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Tormented Bloodseeker (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+215, 100526, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2979.171142578125, 1615.93603515625, 108.5813140869140625, 3.2647552490234375, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Tormented Bloodseeker (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+216, 99200, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3009.663330078125, 1481.9583740234375, 134.101959228515625, 1.071526050567626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dresaron (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+217, 100526, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2802.29345703125, 1490.4385986328125, 120.2030792236328125, 1.28908848762512207, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Tormented Bloodseeker (Area: 0 - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+218, 100526, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2821.5302734375, 1494.1859130859375, 117.7938156127929687, 1.194424033164978027, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Tormented Bloodseeker (Area: 0 - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+219, 100526, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2810.759521484375, 1497.6812744140625, 117.8448104858398437, 6.2237396240234375, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Tormented Bloodseeker (Area: 0 - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+220, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2991.25341796875, 1529.3211669921875, 137.065216064453125, 1.602671742439270019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+221, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2984.1328125, 1518.3853759765625, 137.101959228515625, 4.964592456817626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+222, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2986.190185546875, 1528.2916259765625, 136.888702392578125, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+223, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3001.09814453125, 1542.3385009765625, 141.1710052490234375, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+224, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3007.30029296875, 1542.111083984375, 138.8468170166015625, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+225, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3011.7109375, 1538.5086669921875, 138.0221710205078125, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+226, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2984.71435546875, 1525.654541015625, 137.101959228515625, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+227, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2993.018310546875, 1533.234375, 137.891021728515625, 1.602671742439270019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+228, 100526, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2809.16845703125, 1480.3153076171875, 121.5923309326171875, 5.630823612213134765, 7200, 6, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Tormented Bloodseeker (Area: 0 - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+229, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3008.70751953125, 1537.001708984375, 137.907501220703125, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+230, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2996.64404296875, 1532.2864990234375, 137.5473480224609375, 1.602671742439270019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+231, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3003.955810546875, 1544.28125, 140.810516357421875, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+232, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2980.2119140625, 1520.921875, 137.101959228515625, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+233, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2976.4853515625, 1516.4444580078125, 137.1139678955078125, 4.964592456817626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+234, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3004.466064453125, 1536.126708984375, 137.650848388671875, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+235, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2981.599853515625, 1523.8958740234375, 137.131317138671875, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+236, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2984.99560546875, 1514.8038330078125, 137.101959228515625, 4.964592456817626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+237, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3016.955810546875, 1537.4305419921875, 138.0492401123046875, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+238, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2982.658935546875, 1512.013916015625, 137.101959228515625, 4.964592456817626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+239, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3015.333251953125, 1532.810791015625, 137.930450439453125, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+240, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2976.03564453125, 1510.8350830078125, 137.376678466796875, 4.964592456817626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+241, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3010.908935546875, 1533.357666015625, 137.6929168701171875, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+242, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2972.549560546875, 1506.138916015625, 139.1123809814453125, 4.964592456817626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+243, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3034.901123046875, 1539.7135009765625, 137.101959228515625, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+244, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3022.458251953125, 1533.7742919921875, 138.049346923828125, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+245, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3037.95654296875, 1537.609375, 137.18017578125, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+246, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3027.91748046875, 1537.9947509765625, 137.3634490966796875, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+247, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3023.734375, 1537.3629150390625, 138.048828125, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+248, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2972.505126953125, 1501.154541015625, 139.4107666015625, 4.964592456817626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+249, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2977.671875, 1506.4149169921875, 137.96319580078125, 4.964592456817626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+250, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2975.787353515625, 1497.8629150390625, 138.455291748046875, 2.001165390014648437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+251, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3031.243896484375, 1540.5677490234375, 137.101959228515625, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+252, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3054.299560546875, 1551.8385009765625, 136.9461822509765625, 3.577846527099609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+253, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2984.132080078125, 1508.1146240234375, 137.101959228515625, 4.964592456817626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+254, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3019.3447265625, 1533.2586669921875, 138.032470703125, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+255, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3030.2421875, 1535.2725830078125, 137.101959228515625, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+256, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2982.3984375, 1504.1319580078125, 137.5350189208984375, 4.964592456817626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+257, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3020.861083984375, 1536.52783203125, 138.047943115234375, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+258, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3025.69873046875, 1534.6441650390625, 137.890380859375, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+259, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3033.513916015625, 1536.8350830078125, 137.101959228515625, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+260, 100529, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3062.574951171875, 1560.6055908203125, 138.4507904052734375, 3.458965778350830078, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+261, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2971.630126953125, 1495.3038330078125, 139.4844207763671875, 2.001165390014648437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+262, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3058.19970703125, 1553.8055419921875, 136.9444427490234375, 3.577846527099609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+263, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3056.624267578125, 1549.6927490234375, 136.8784637451171875, 3.577846527099609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+264, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3038.9765625, 1534.48095703125, 137.1217193603515625, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+265, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3043.12939453125, 1535.6614990234375, 137.2249298095703125, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+266, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3056.888916015625, 1546.3021240234375, 136.9666595458984375, 3.577846527099609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+267, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3059.85595703125, 1550.763916015625, 136.642364501953125, 3.577846527099609375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+268, 100529, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3071.1513671875, 1556.7197265625, 137.729461669921875, 3.658982753753662109, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+269, 100529, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3078.049072265625, 1563.2261962890625, 138.2171783447265625, 3.457966089248657226, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+270, 100529, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3065.97119140625, 1552.916259765625, 137.4263458251953125, 0.498128294944763183, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: 0 - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+271, 100529, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3077.37841796875, 1559.751953125, 138.2163238525390625, 0.543564856052398681, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+272, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3049.759521484375, 1531.298583984375, 137.153472900390625, 1.652507424354553222, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+273, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3047.05126953125, 1531.013916015625, 137.129669189453125, 1.652507424354553222, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+274, 100529, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3083.5185546875, 1561.295654296875, 138.406036376953125, 2.304334640502929687, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+275, 100529, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3081.001708984375, 1554.4635009765625, 137.99310302734375, 2.895788192749023437, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+276, 100531, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3056.907958984375, 1541.6353759765625, 138.0883636474609375, 3.075070142745971679, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Bloodtainted Fury (Area: 0 - Difficulty: Heroic) CreateObject1 (possible waypoints or random movement)
(@CGUID+277, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3047.033935546875, 1533.8629150390625, 137.2169647216796875, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+278, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3042.17529296875, 1532.1614990234375, 137.1072845458984375, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+279, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3049.098876953125, 1529.282958984375, 137.1078948974609375, 1.652507424354553222, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+280, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3047.74560546875, 1527.09033203125, 137.102081298828125, 1.652507424354553222, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+281, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3051.65966796875, 1528.2760009765625, 137.1023712158203125, 1.652507424354553222, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+282, 100529, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3077.789306640625, 1548.53759765625, 137.467926025390625, 0.660676538944244384, 7200, 3, 0, 1, NULL, NULL, NULL, NULL, 61265), -- Hatespawn Slime (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+283, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3100.421875, 1556.2430419921875, 136.9710540771484375, 6.052779197692871093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+284, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3099.2431640625, 1550.3958740234375, 136.804595947265625, 6.052779197692871093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+285, 111221, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3049.55126953125, 1519.296875, 138.101959228515625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Xal'atath (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+286, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3102.037353515625, 1553.1197509765625, 137.1768646240234375, 6.052779197692871093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+287, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3102.874267578125, 1549.6285400390625, 137.0002288818359375, 6.052779197692871093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+288, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2976.522705078125, 1492.5191650390625, 138.416046142578125, 2.001165390014648437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+289, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3073.94873046875, 1524.642333984375, 136.7371368408203125, 3.421127080917358398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+290, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3064.96435546875, 1515.80908203125, 137.5183563232421875, 3.792139053344726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+291, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3058.708251953125, 1513.935791015625, 137.135406494140625, 4.608548641204833984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+292, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2978.283935546875, 1490.1666259765625, 138.682830810546875, 2.001165390014648437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+293, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3076.887939453125, 1527.4254150390625, 136.9519500732421875, 3.421127080917358398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+294, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3060.803955078125, 1515.8385009765625, 137.2534637451171875, 4.608548641204833984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+295, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3079.29345703125, 1529.6024169921875, 137.123016357421875, 3.421127080917358398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+296, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2981.94091796875, 1490.3472900390625, 138.29522705078125, 2.001165390014648437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+297, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3093.4306640625, 1532.43408203125, 136.693389892578125, 1.938495755195617675, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+298, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3084.459228515625, 1531.6927490234375, 137.1290130615234375, 3.421127080917358398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+299, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3058.064208984375, 1517.3316650390625, 137.134674072265625, 4.608548641204833984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+300, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3059.833251953125, 1519.439208984375, 137.1493072509765625, 4.608548641204833984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+301, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3089.81591796875, 1531.6910400390625, 136.98931884765625, 1.938495755195617675, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+302, 100533, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3083.084228515625, 1528.8125, 136.851806640625, 3.421127080917358398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+303, 100533, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3095.614501953125, 1530.60595703125, 136.503082275390625, 1.938495755195617675, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+304, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3061.817626953125, 1512.76220703125, 137.29339599609375, 4.608548641204833984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+305, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 2986.837646484375, 1483.282958984375, 138.407379150390625, 1.56622314453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+306, 100533, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3092.6806640625, 1529.5885009765625, 136.560760498046875, 1.938495755195617675, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+307, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3064.520751953125, 1510.1822509765625, 137.5076751708984375, 3.792139053344726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+308, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 2985.27783203125, 1487.3541259765625, 138.3145599365234375, 1.56622314453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+309, 100533, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3097.21435546875, 1532.888916015625, 136.510589599609375, 1.938495755195617675, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+310, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3069.275146484375, 1512.0103759765625, 138.032989501953125, 3.792139053344726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+311, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 2982.734375, 1483.640625, 138.782989501953125, 1.56622314453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+312, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3069.377685546875, 1515.5225830078125, 137.7969207763671875, 3.792139053344726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+313, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3068.49560546875, 1506.68408203125, 137.934234619140625, 3.792139053344726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+314, 111001, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 2981.022705078125, 1478.623291015625, 139.128753662109375, 5.021893024444580078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Horror Corrupted Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1
(@CGUID+315, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3058.50439453125, 1501.0416259765625, 137.101959228515625, 3.792139053344726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+316, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3059.6953125, 1503.4410400390625, 137.101959228515625, 3.792139053344726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+317, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 2990.43408203125, 1481.9879150390625, 137.4930572509765625, 1.56622314453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+318, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3062.83251953125, 1505.420166015625, 137.169830322265625, 3.792139053344726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+319, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 2994.837646484375, 1480.470458984375, 137.101959228515625, 2.206718683242797851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+320, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3063.002685546875, 1497.888916015625, 137.95989990234375, 3.792139053344726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+321, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3055.98876953125, 1492.359375, 137.8221435546875, 1.806231498718261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+322, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 2987.04248046875, 1478.189208984375, 138.28125, 1.56622314453125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+323, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3054.452392578125, 1495.998291015625, 137.2459716796875, 1.806231498718261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+324, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 2999.731689453125, 1478.8489990234375, 137.101959228515625, 2.206718683242797851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+325, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3058.436767578125, 1497.3004150390625, 137.841156005859375, 1.806231498718261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+326, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3050.835205078125, 1490.8055419921875, 137.101959228515625, 1.806231498718261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+327, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3067.142333984375, 1500.87158203125, 137.9468536376953125, 3.792139053344726562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+328, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 2994.413330078125, 1476.439208984375, 137.101959228515625, 2.206718683242797851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+329, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3051.599853515625, 1486.454833984375, 137.369293212890625, 3.371537446975708007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+330, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3002.111083984375, 1475.55908203125, 137.101959228515625, 2.206718683242797851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+331, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3021.098876953125, 1472.7742919921875, 137.912353515625, 2.56747746467590332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+332, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3009.4140625, 1475.517333984375, 136.876251220703125, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+333, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3030.701416015625, 1478.8802490234375, 137.101959228515625, 3.141987800598144531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+334, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3035.3291015625, 1478.6805419921875, 137.2830657958984375, 3.141987800598144531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+335, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3040.51220703125, 1482.7725830078125, 137.1024322509765625, 3.371537446975708007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+336, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 2997.7265625, 1475.3350830078125, 137.101959228515625, 2.206718683242797851, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+337, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3047.140625, 1487.9879150390625, 137.1024322509765625, 3.371537446975708007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+338, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3015.137939453125, 1472.34375, 138.1637115478515625, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+339, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3045.8447265625, 1484.10595703125, 137.9618072509765625, 3.371537446975708007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+340, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3026.421875, 1477.782958984375, 137.101959228515625, 2.56747746467590332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+341, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3023.59716796875, 1475.873291015625, 137.101959228515625, 2.56747746467590332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+342, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3043.560791015625, 1479.2396240234375, 138.656402587890625, 3.371537446975708007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+343, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3005.48876953125, 1477.7725830078125, 137.101959228515625, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+344, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3013.252685546875, 1475.467041015625, 137.1011505126953125, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+345, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3036.366455078125, 1482.484375, 137.0092315673828125, 3.141987800598144531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+346, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3055.38720703125, 1488.626708984375, 137.2280731201171875, 1.806231498718261718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+347, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3038.7275390625, 1476.5677490234375, 138.529541015625, 3.141987800598144531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+348, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3017.55908203125, 1468.501708984375, 138.656402587890625, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+349, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3027.2353515625, 1470.4635009765625, 137.794952392578125, 2.56747746467590332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+350, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3022.212646484375, 1468.99658203125, 138.656402587890625, 2.56747746467590332, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+351, 101072, 1466, 7673, 8101, '1,2,8,23,24', 0, 0, 0, 0, 3033.4462890625, 1474.796875, 138.658355712890625, 3.141987800598144531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: Miasmic Gorge - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+352, 111221, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2787.06689453125, 1463.93408203125, 127.6865158081054687, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Xal'atath (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+353, 111833, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2787.06689453125, 1463.93408203125, 127.6865158081054687, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Thal'kiel (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+354, 111042, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2731.064208984375, 1390.73095703125, 167.046905517578125, 1.426256418228149414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+355, 111042, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2752.123291015625, 1361.4600830078125, 137.851593017578125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+356, 111042, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2760.630126953125, 1380.0711669921875, 162.124481201171875, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+357, 111042, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2774.411376953125, 1337.1475830078125, 162.688629150390625, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+358, 99365, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2753.342041015625, 1404.2569580078125, 141.618896484375, 1.170924305915832519, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Taintheart Stalker (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+359, 100539, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 1, 2742.267333984375, 1401.1163330078125, 142.939727783203125, 1.170924305915832519, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Taintheart Deadeye (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+360, 100526, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2752.65625, 1396.4791259765625, 143.1051483154296875, 1.170924305915832519, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Tormented Bloodseeker (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+361, 111042, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2766.595458984375, 1358.60595703125, 151.3061065673828125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+362, 111042, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2767.361083984375, 1329.532958984375, 158.438140869140625, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+363, 111042, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2768.468017578125, 1362.0225830078125, 164.388214111328125, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+364, 111042, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2730.08935546875, 1384.935791015625, 145.052215576171875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+365, 99366, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 1, 2747.263916015625, 1397.1822509765625, 142.8715362548828125, 1.170924305915832519, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Taintheart Summoner (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+366, 111042, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2762.428955078125, 1361.9097900390625, 156.0718231201171875, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+367, 100527, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2744.822021484375, 1407.1614990234375, 142.290985107421875, 0.717811405658721923, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Dreadfire Imp (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1 (Auras: 191262 - Nightmare Imp Spawn)
(@CGUID+368, 111042, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2764.790771484375, 1347.079833984375, 143.996246337890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1
(@CGUID+369, 99192, 1466, 7673, 8097, '1,2,8,23,24', 0, 0, 0, 0, 2693.171875, 1288.69970703125, 128.451690673828125, 2.120859146118164062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Shade of Xavius (Area: Tainted Burrow - Difficulty: Heroic) CreateObject1 (Auras: 195106 - Shade of Xavius, 355784 - [DNT] Send Event <Points> On Enter Combat)
(@CGUID+370, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2722.8046875, 1382.126708984375, 134.9907989501953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+371, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2754.2265625, 1334.9635009765625, 135.99212646484375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+372, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2711.71533203125, 1372.10595703125, 139.21820068359375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+373, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2708.40283203125, 1380.0972900390625, 173.009063720703125, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+374, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2762.915771484375, 1328.2882080078125, 146.932159423828125, 6.157151699066162109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+375, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2713.400146484375, 1379.28125, 167.179168701171875, 1.626155972480773925, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+376, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2702.59716796875, 1366.2569580078125, 147.570098876953125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+377, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2696.072998046875, 1374.9774169921875, 164.2432098388671875, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+378, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2770.1337890625, 1316.420166015625, 146.7998809814453125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+379, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2683.479248046875, 1362.064208984375, 143.4371337890625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+380, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2690.522705078125, 1362.2708740234375, 141.2945556640625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+381, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2671.48095703125, 1370.9461669921875, 171.553131103515625, 4.906589984893798828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+382, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2765.0859375, 1302.095458984375, 158.739532470703125, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+383, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2678.877685546875, 1352.4739990234375, 137.82830810546875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+384, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2762.762939453125, 1297.828125, 141.87750244140625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+385, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2664.68408203125, 1349.6910400390625, 158.098602294921875, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+386, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2756.939208984375, 1288.217041015625, 139.5723114013671875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+387, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2670.126708984375, 1338.5728759765625, 141.0188446044921875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+388, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2664.424560546875, 1339.8680419921875, 155.237823486328125, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+389, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2749.78466796875, 1280.2708740234375, 172.060943603515625, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+390, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2666.720458984375, 1320.3160400390625, 141.549072265625, 5.831089019775390625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+391, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2739.6875, 1282.701416015625, 135.824859619140625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+392, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2748.088623046875, 1283.6302490234375, 144.1412506103515625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+393, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2723.74560546875, 1276.453125, 142.4416351318359375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+394, 101329, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2686.353271484375, 1290.2430419921875, 131.887115478515625, 0.743811309337615966, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Bindings (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 199752 - Nightmare Bindings)
(@CGUID+395, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2669.522705078125, 1308.4271240234375, 151.8138885498046875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+396, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2682.58935546875, 1293.826416015625, 138.4925384521484375, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+397, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2659.085205078125, 1326.1197509765625, 165.299224853515625, 4.939292430877685546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+398, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2672.002685546875, 1293.045166015625, 167.817108154296875, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+399, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2693.060791015625, 1274.876708984375, 144.1371002197265625, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+400, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2709.098876953125, 1273.03125, 138.19110107421875, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+401, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2725.829833984375, 1264.625, 161.265838623046875, 3.432476282119750976, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+402, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2675.24560546875, 1292.66845703125, 159.465240478515625, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+403, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2704.770751953125, 1267.828125, 158.075347900390625, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+404, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2700.007080078125, 1266.6771240234375, 163.684112548828125, 1.752189517021179199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+405, 111042, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2693.036376953125, 1257.54345703125, 161.541534423828125, 1.573426485061645507, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Nightmare Fire (Area: 0 - Difficulty: Heroic) CreateObject1
(@CGUID+406, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2984.1328125, 1518.3853759765625, 137.101959228515625, 4.964592456817626953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+407, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3000.22216796875, 1535.392333984375, 137.4990234375, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+408, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2986.190185546875, 1528.2916259765625, 136.888702392578125, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+409, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3001.09814453125, 1542.3385009765625, 141.1710052490234375, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+410, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2988.223876953125, 1531.609375, 137.0865936279296875, 1.602671742439270019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+411, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2997.287353515625, 1536.314208984375, 138.04278564453125, 1.602671742439270019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+412, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3007.30029296875, 1542.111083984375, 138.8468170166015625, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+413, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2984.884521484375, 1521.2586669921875, 137.101959228515625, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+414, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 3011.7109375, 1538.5086669921875, 138.0221710205078125, 2.548721790313720703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265), -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
(@CGUID+415, 101072, 1466, 7673, 0, '1,2,8,23,24', 0, 0, 0, 0, 2984.71435546875, 1525.654541015625, 137.101959228515625, 2.629638910293579101, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 61265); -- Corrupted Dragon Egg (Area: 0 - Difficulty: Heroic) CreateObject1 (Auras: 243088 - Detection Aura)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+415;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 3, ''), -- Crazed Razorbeak
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 3, ''), -- Crazed Razorbeak
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 3, ''), -- Festerhide Grizzly
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 3, ''), -- Crazed Razorbeak
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+37, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 3, '195110 55701'), -- Frenzied Nightclaw - 195110 - Dungeon Temp Nightmare Shader, 55701 - Cosmetic - Sleep Zzz Breakable
(@CGUID+39, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 3, '195110'), -- Dreadsoul Ruiner - 195110 - Dungeon Temp Nightmare Shader
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+42, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '195110'), -- Dreadsoul Poisoner - 195110 - Dungeon Temp Nightmare Shader
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+52, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+63, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+64, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Mindshattered Screecher
(@CGUID+68, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '195110'), -- Dreadsoul Poisoner - 195110 - Dungeon Temp Nightmare Shader
(@CGUID+71, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+77, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Mindshattered Screecher
(@CGUID+78, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 3, '195110'), -- Frenzied Nightclaw - 195110 - Dungeon Temp Nightmare Shader
(@CGUID+79, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+81, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 3, '195110'), -- Frenzied Nightclaw - 195110 - Dungeon Temp Nightmare Shader
(@CGUID+82, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+85, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+89, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+90, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+93, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+94, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+95, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 3, ''), -- Crazed Razorbeak
(@CGUID+99, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+100, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 3, ''), -- Festerhide Grizzly
(@CGUID+101, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+103, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+113, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+115, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+118, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Mindshattered Screecher
(@CGUID+119, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Mindshattered Screecher
(@CGUID+123, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+126, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+131, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 3, '195110'), -- Frenzied Nightclaw - 195110 - Dungeon Temp Nightmare Shader
(@CGUID+133, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+140, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+143, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+146, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+149, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+151, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+152, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+153, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+154, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+156, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+157, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+163, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Taintheart Stalker
(@CGUID+164, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Taintheart Deadeye
(@CGUID+167, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+198, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- Dead Perserver Druid - 146007 - Spawn Dead
(@CGUID+202, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Taintheart Stalker
(@CGUID+211, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Taintheart Summoner
(@CGUID+358, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Taintheart Stalker

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+19;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 254997, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2875.443603515625, 1935.15283203125, 189.5887908935546875, 4.214973926544189453, 0, 0, -0.859405517578125, 0.51129460334777832, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+1, 254850, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2986.468017578125, 1533.6336669921875, 138.6278839111328125, 2.085666656494140625, 0.072724342346191406, -0.06076431274414062, 0.859196662902832031, 0.502792179584503173, 7200, 255, 0, 61265), -- NightmareBoss2DungeonDoor2 (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+2, 254851, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2896.710205078125, 1967.3507080078125, 189.0579986572265625, 3.141592741012573242, 0, 0, -1, 0, 7200, 255, 0, 61265), -- NightmareDungeonGlaidalisCollision (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+3, 254849, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 3059.9921875, 1526.84033203125, 137.9421234130859375, 3.865909099578857421, -0.09298992156982421, -0.01827621459960937, -0.93145179748535156, 0.351306647062301635, 7200, 255, 0, 61265), -- NightmareBoss2DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+4, 254855, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2743.450927734375, 1375.1351318359375, 128.620269775390625, 0.820303261280059814, 0, 0, 0.398748397827148437, 0.917060375213623046, 7200, 255, 0, 61265), -- Doodad_7du_nightmare_rootwall001 (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+5, 254986, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2932.28564453125, 1982.6788330078125, 189.6621856689453125, 3.272519350051879882, 0, 0, -0.99785804748535156, 0.065416477620601654, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+6, 254987, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2929.772705078125, 1994.4722900390625, 188.7831268310546875, 3.577930212020874023, 0, 0, -0.97629547119140625, 0.216442063450813293, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+7, 254984, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2932.134521484375, 1955.43408203125, 189.7537994384765625, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+8, 254985, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2934.05908203125, 1967.2586669921875, 189.3867645263671875, 3.176533222198486328, 0, 0, -0.999847412109375, 0.017469281330704689, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+9, 254990, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2899.328125, 2014.5103759765625, 189.0978546142578125, 4.564037322998046875, 0, 0, -0.75756454467773437, 0.652760267257690429, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+10, 254991, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2890.12060546875, 2012.296875, 188.3052825927734375, 2.059488296508789062, 0, 0, 0.857167243957519531, 0.515038192272186279, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+11, 254988, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2922.342041015625, 2009.8333740234375, 189.124664306640625, 3.490667104721069335, 0, 0, -0.98480701446533203, 0.173652306199073791, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+12, 254994, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2859.239501953125, 1987.8055419921875, 189.211700439453125, 2.809975385665893554, 0, 0, 0.986285209655761718, 0.165049895644187927, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+13, 254989, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2913.239501953125, 2015.8489990234375, 189.1082000732421875, 4.721118450164794921, 0, 0, -0.70401382446289062, 0.710186243057250976, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+14, 254995, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2857.27783203125, 1976.1597900390625, 189.0169677734375, 2.967041015625, 0, 0, 0.996193885803222656, 0.087165042757987976, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+15, 254992, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2879.70654296875, 2010.2603759765625, 189.7895355224609375, 2.050761699676513671, 0, 0, 0.85491180419921875, 0.518773376941680908, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+16, 254993, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2861.079833984375, 1996.2847900390625, 189.6817169189453125, 2.792518377304077148, 0, 0, 0.984807014465332031, 0.173652306199073791, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+17, 254998, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2866.86376953125, 1942.3055419921875, 189.1374053955078125, 0.610865473747253417, 0, 0, 0.300705909729003906, 0.953716933727264404, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+18, 254999, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2861.864501953125, 1952.7135009765625, 188.6929473876953125, 3.52557229995727539, 0, 0, -0.98162651062011718, 0.190812408924102783, 7200, 255, 0, 61265), -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
(@OGUID+19, 254996, 1466, 7673, 7673, '1,2,8,23,24', 0, 0, 2858.518310546875, 1962.467041015625, 189.176910400390625, 3.342307567596435546, 0, 0, -0.99496841430664062, 0.100189015269279479, 7200, 255, 0, 61265); -- NightmareBoss1DungeonDoor (Area: Darkheart Thicket - Difficulty: Heroic) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+19;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+4, 0, 0, 0.889016270637512207, 0.457875549793243408, 0, 0); -- Doodad_7du_nightmare_rootwall001

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (100652 /*100652 (Malfurion Stormrage) - Ride Vehicle Hardcoded*/, 101329 /*101329 (Nightmare Bindings) - Nightmare Bindings*/, 99192 /*99192 (Shade of Xavius) - Shade of Xavius, [DNT] Send Event <Points> On Enter Combat*/, 101074 /*101074 (Hatespawn Whelpling)*/, 111001 /*111001 (Horror Corrupted Egg)*/, 101072 /*101072 (Corrupted Dragon Egg) - Detection Aura*/, 99200 /*99200 (Dresaron)*/, 99366 /*99366 (Taintheart Summoner)*/, 100526 /*100526 (Tormented Bloodseeker)*/, 100527 /*100527 (Dreadfire Imp) - Nightmare Imp Spawn*/, 102851 /*102851 (Shield Invisible Stalker) - Giant Shield*/, 100539 /*100539 (Taintheart Deadeye)*/, 99365 /*99365 (Taintheart Stalker)*/, 96512 /*96512 (Archdruid Glaidalis) - [DNT] Send Event <Points> On Enter Combat*/, 95769 /*95769 (Mindshattered Screecher)*/, 101991 /*101991 (Nightmare Dweller)*/, 95771 /*95771 (Dreadsoul Ruiner) - Dungeon Temp Nightmare Shader*/, 100400 /*100400 (Dead Perserver Druid) - Spawn Dead*/, 95772 /*95772 (Frenzied Nightclaw) - Dungeon Temp Nightmare Shader*/, 103344 /*103344 (Oakheart) - Deep Roots, Oakheart Auto Attack Sounds, [DNT] Send Event <Points> On Enter Combat*/, 100403 /*100403 (Druidic Preserver)*/, 95779 /*95779 (Festerhide Grizzly)*/, 100533 /*100533 (Corrupted Egg) - Detection Aura*/, 101679 /*101679 (Dreadsoul Poisoner) - Dungeon Temp Nightmare Shader*/, 95766 /*95766 (Crazed Razorbeak)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(100652, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 100652 (Malfurion Stormrage) - Ride Vehicle Hardcoded
(101329, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '199752'), -- 101329 (Nightmare Bindings) - Nightmare Bindings
(99192, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '195106 355784'), -- 99192 (Shade of Xavius) - Shade of Xavius, [DNT] Send Event <Points> On Enter Combat
(101074, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 101074 (Hatespawn Whelpling)
(111001, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 111001 (Horror Corrupted Egg)
(101072, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '243088'), -- 101072 (Corrupted Dragon Egg) - Detection Aura
(99200, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 99200 (Dresaron)
(99366, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 99366 (Taintheart Summoner)
(100526, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 100526 (Tormented Bloodseeker)
(100527, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '191262'), -- 100527 (Dreadfire Imp) - Nightmare Imp Spawn
(102851, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '203257'), -- 102851 (Shield Invisible Stalker) - Giant Shield
(100539, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 100539 (Taintheart Deadeye)
(99365, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 99365 (Taintheart Stalker)
(96512, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '355784'), -- 96512 (Archdruid Glaidalis) - [DNT] Send Event <Points> On Enter Combat
(95769, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 95769 (Mindshattered Screecher)
(101991, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- 101991 (Nightmare Dweller)
(95771, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '195110'), -- 95771 (Dreadsoul Ruiner) - Dungeon Temp Nightmare Shader
(100400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146007'), -- 100400 (Dead Perserver Druid) - Spawn Dead
(95772, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '195110'), -- 95772 (Frenzied Nightclaw) - Dungeon Temp Nightmare Shader
(103344, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '165950 218987 355784'), -- 103344 (Oakheart) - Deep Roots, Oakheart Auto Attack Sounds, [DNT] Send Event <Points> On Enter Combat
(100403, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 100403 (Druidic Preserver)
(95779, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 95779 (Festerhide Grizzly)
(100533, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, '243088'), -- 100533 (Corrupted Egg) - Detection Aura
(101679, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '195110'), -- 101679 (Dreadsoul Poisoner) - Dungeon Temp Nightmare Shader
(95766, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''); -- 95766 (Crazed Razorbeak)

-- Template
UPDATE `creature_template` SET `unit_flags3`=0x1000001, `flags_extra` = 128 WHERE `entry`=102851; -- Shield Invisible Stalker
UPDATE `creature_template` SET `unit_flags3`=0x1000001, `flags_extra` = 128 WHERE `entry`=100404; -- Perserver Ray Invisible Stalker

-- Difficulty (Normal)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=100652 AND `DifficultyID`=1); -- 100652 (Malfurion Stormrage) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=101329 AND `DifficultyID`=1); -- 101329 (Nightmare Bindings) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99192 AND `DifficultyID`=1); -- 99192 (Shade of Xavius) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=111042 AND `DifficultyID`=1); -- 111042 (Nightmare Fire) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=61265 WHERE (`DifficultyID`=1 AND `Entry` IN (111833,111221));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=101072 AND `DifficultyID`=1); -- 101072 (Corrupted Dragon Egg) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100526 AND `DifficultyID`=1); -- 100526 (Tormented Bloodseeker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99366 AND `DifficultyID`=1); -- 99366 (Taintheart Summoner) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100527 AND `DifficultyID`=1); -- 100527 (Dreadfire Imp) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99359 AND `DifficultyID`=1); -- 99359 (Rotheart Keeper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000100, `VerifiedBuild`=61265 WHERE (`Entry`=99360 AND `DifficultyID`=1); -- 99360 (Vilethorn Blossom) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99358 AND `DifficultyID`=1); -- 99358 (Rotheart Dryad) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `VerifiedBuild`=61265 WHERE (`Entry`=102851 AND `DifficultyID`=1); -- 102851 (Shield Invisible Stalker) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=107638 AND `DifficultyID`=1); -- 107638 (Druidic Preserver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `VerifiedBuild`=61265 WHERE (`Entry`=100404 AND `DifficultyID`=1); -- 100404 (Perserver Ray Invisible Stalker) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99200 AND `DifficultyID`=1); -- 99200 (Dresaron) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99365 AND `DifficultyID`=1); -- 99365 (Taintheart Stalker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100539 AND `DifficultyID`=1); -- 100539 (Taintheart Deadeye) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96512 AND `DifficultyID`=1); -- 96512 (Archdruid Glaidalis) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100531 AND `DifficultyID`=1); -- 100531 (Bloodtainted Fury) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000100, `VerifiedBuild`=61265 WHERE (`Entry`=103344 AND `DifficultyID`=1); -- 103344 (Oakheart) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95766 AND `DifficultyID`=1); -- 95766 (Crazed Razorbeak) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95769 AND `DifficultyID`=1); -- 95769 (Mindshattered Screecher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95771 AND `DifficultyID`=1); -- 95771 (Dreadsoul Ruiner) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100400 AND `DifficultyID`=1); -- 100400 (Dead Perserver Druid) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=101991 AND `DifficultyID`=1); -- 101991 (Nightmare Dweller) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100529 AND `DifficultyID`=1); -- 100529 (Hatespawn Slime) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=101679 AND `DifficultyID`=1); -- 101679 (Dreadsoul Poisoner) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95772 AND `DifficultyID`=1); -- 95772 (Frenzied Nightclaw) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=0, `LevelScalingDeltaMax`=0, `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95779 AND `DifficultyID`=1); -- 95779 (Festerhide Grizzly) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100403 AND `DifficultyID`=1); -- 100403 (Druidic Preserver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=485, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=100533 AND `DifficultyID`=1); -- 100533 (Corrupted Egg) - Sessile, CanSwim, Floating

-- Difficulty (Heroic)
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=2 AND `Entry` IN (111042,102851,107638,100404,100403));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`, `VerifiedBuild`) VALUES
(111042, 2, 0, 0, 628, 0x20000100, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 111042 (Nightmare Fire) - Sessile, Floating
(102851, 2, 0, 0, 628, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 102851 (Shield Invisible Stalker) - 
(107638, 2, 0, 0, 628, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 107638 (Druidic Preserver) - CanSwim
(100404, 2, 0, 0, 628, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265), -- 100404 (Perserver Ray Invisible Stalker) - 
(100403, 2, 0, 0, 628, 0x10000000, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 61265); -- 100403 (Druidic Preserver) - CanSwim

UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=0.5, `CreatureDifficultyID`=113192 WHERE (`Entry`=111042 AND `DifficultyID`=2); -- Nightmare Fire
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=114128 WHERE (`Entry`=111833 AND `DifficultyID`=2); -- Thal'kiel
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=103679, `TypeFlags2`=128 WHERE (`Entry`=102851 AND `DifficultyID`=2); -- Shield Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=5, `CreatureDifficultyID`=109096, `TypeFlags`=0x200000 WHERE (`Entry`=107638 AND `DifficultyID`=2); -- Druidic Preserver
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `CreatureDifficultyID`=100914, `TypeFlags2`=128 WHERE (`Entry`=100404 AND `DifficultyID`=2); -- Perserver Ray Invisible Stalker
UPDATE `creature_template_difficulty` SET `HealthScalingExpansion`=6, `HealthModifier`=5, `CreatureDifficultyID`=100913, `TypeFlags`=0x200000 WHERE (`Entry`=100403 AND `DifficultyID`=2); -- Druidic Preserver

UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=100652 AND `DifficultyID`=2); -- 100652 (Malfurion Stormrage) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=61265 WHERE (`Entry`=101329 AND `DifficultyID`=2); -- 101329 (Nightmare Bindings) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99192 AND `DifficultyID`=2); -- 99192 (Shade of Xavius) - CanSwim
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=61265 WHERE (`DifficultyID`=2 AND `Entry` IN (111833,111221));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=101074 AND `DifficultyID`=2); -- 101074 (Hatespawn Whelpling) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=111001 AND `DifficultyID`=2); -- 111001 (Horror Corrupted Egg) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=101072 AND `DifficultyID`=2); -- 101072 (Corrupted Dragon Egg) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99200 AND `DifficultyID`=2); -- 99200 (Dresaron) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100526 AND `DifficultyID`=2); -- 100526 (Tormented Bloodseeker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99366 AND `DifficultyID`=2); -- 99366 (Taintheart Summoner) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100527 AND `DifficultyID`=2); -- 100527 (Dreadfire Imp) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99359 AND `DifficultyID`=2); -- 99359 (Rotheart Keeper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99358 AND `DifficultyID`=2); -- 99358 (Rotheart Dryad) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99360 AND `DifficultyID`=2); -- 99360 (Vilethorn Blossom) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100539 AND `DifficultyID`=2); -- 100539 (Taintheart Deadeye) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99365 AND `DifficultyID`=2); -- 99365 (Taintheart Stalker) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96512 AND `DifficultyID`=2); -- 96512 (Archdruid Glaidalis) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100531 AND `DifficultyID`=2); -- 100531 (Bloodtainted Fury) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95769 AND `DifficultyID`=2); -- 95769 (Mindshattered Screecher) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=101991 AND `DifficultyID`=2); -- 101991 (Nightmare Dweller) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95771 AND `DifficultyID`=2); -- 95771 (Dreadsoul Ruiner) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100400 AND `DifficultyID`=2); -- 100400 (Dead Perserver Druid) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95772 AND `DifficultyID`=2); -- 95772 (Frenzied Nightclaw) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=628, `StaticFlags1`=0x10000100, `VerifiedBuild`=61265 WHERE (`Entry`=103344 AND `DifficultyID`=2); -- 103344 (Oakheart) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95779 AND `DifficultyID`=2); -- 95779 (Festerhide Grizzly) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=100533 AND `DifficultyID`=2); -- 100533 (Corrupted Egg) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=101679 AND `DifficultyID`=2); -- 101679 (Dreadsoul Poisoner) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100529 AND `DifficultyID`=2); -- 100529 (Hatespawn Slime) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=628, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95766 AND `DifficultyID`=2); -- 95766 (Crazed Razorbeak) - CanSwim

-- Difficulty (Mythic)
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=101329 AND `DifficultyID`=23); -- 101329 (Nightmare Bindings) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=100652 AND `DifficultyID`=23); -- 100652 (Malfurion Stormrage) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x20000100, `VerifiedBuild`=61265 WHERE (`Entry`=111042 AND `DifficultyID`=23); -- 111042 (Nightmare Fire) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99192 AND `DifficultyID`=23); -- 99192 (Shade of Xavius) - CanSwim
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=61265 WHERE (`DifficultyID`=23 AND `Entry` IN (111833,111221,120652));
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100532 AND `DifficultyID`=23); -- 100532 (Bloodtainted Burster) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=111001 AND `DifficultyID`=23); -- 111001 (Horror Corrupted Egg) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=101072 AND `DifficultyID`=23); -- 101072 (Corrupted Dragon Egg) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100526 AND `DifficultyID`=23); -- 100526 (Tormented Bloodseeker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99366 AND `DifficultyID`=23); -- 99366 (Taintheart Summoner) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99359 AND `DifficultyID`=23); -- 99359 (Rotheart Keeper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=61265 WHERE (`Entry`=102851 AND `DifficultyID`=23); -- 102851 (Shield Invisible Stalker) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=107638 AND `DifficultyID`=23); -- 107638 (Druidic Preserver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100527 AND `DifficultyID`=23); -- 100527 (Dreadfire Imp) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99360 AND `DifficultyID`=23); -- 99360 (Vilethorn Blossom) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99358 AND `DifficultyID`=23); -- 99358 (Rotheart Dryad) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99200 AND `DifficultyID`=23); -- 99200 (Dresaron) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `VerifiedBuild`=61265 WHERE (`Entry`=100404 AND `DifficultyID`=23); -- 100404 (Perserver Ray Invisible Stalker) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100539 AND `DifficultyID`=23); -- 100539 (Taintheart Deadeye) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=99365 AND `DifficultyID`=23); -- 99365 (Taintheart Stalker) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=96512 AND `DifficultyID`=23); -- 96512 (Archdruid Glaidalis) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100403 AND `DifficultyID`=23); -- 100403 (Druidic Preserver) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=101991 AND `DifficultyID`=23); -- 101991 (Nightmare Dweller) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=629, `StaticFlags1`=0x10000100, `VerifiedBuild`=61265 WHERE (`Entry`=103344 AND `DifficultyID`=23); -- 103344 (Oakheart) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100531 AND `DifficultyID`=23); -- 100531 (Bloodtainted Fury) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x30000100, `VerifiedBuild`=61265 WHERE (`Entry`=100533 AND `DifficultyID`=23); -- 100533 (Corrupted Egg) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100529 AND `DifficultyID`=23); -- 100529 (Hatespawn Slime) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95766 AND `DifficultyID`=23); -- 95766 (Crazed Razorbeak) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95771 AND `DifficultyID`=23); -- 95771 (Dreadsoul Ruiner) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=100400 AND `DifficultyID`=23); -- 100400 (Dead Perserver Druid) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95779 AND `DifficultyID`=23); -- 95779 (Festerhide Grizzly) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95772 AND `DifficultyID`=23); -- 95772 (Frenzied Nightclaw) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=95769 AND `DifficultyID`=23); -- 95769 (Mindshattered Screecher) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=629, `StaticFlags1`=0x10000000, `VerifiedBuild`=61265 WHERE (`Entry`=101679 AND `DifficultyID`=23); -- 101679 (Dreadsoul Poisoner) - CanSwim

-- Creature Template Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` IN (99200, 100533, 101072);
INSERT INTO `creature_template_movement` (`CreatureId`, `HoverInitiallyEnabled`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(99200, 1, 0, 0, NULL),
(100533, 1, 0, 0, NULL),
(101072, 1, 0, 0, NULL);

-- Creature static flag override
DELETE FROM `creature_static_flags_override` WHERE `SpawnId` IN (@CGUID+26, @CGUID+130, @CGUID+34, @CGUID+36);
INSERT INTO `creature_static_flags_override` (`SpawnId`, `DifficultyId`, `StaticFlags1`, `StaticFlags2`, `StaticFlags3`, `StaticFlags4`, `StaticFlags5`, `StaticFlags6`, `StaticFlags7`, `StaticFlags8`) VALUES
(@CGUID+26, 1, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+26, 2, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+26, 23, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+130, 1, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+130, 2, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+130, 23, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+34, 1, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+34, 2, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+34, 23, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+36, 1, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+36, 2, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL),
(@CGUID+36, 23, 0x30000000, NULL, NULL, NULL, NULL, NULL, NULL, NULL);

-- SpellClick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 101329;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(101329, 46598, 1, 0);

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE (`entry`=101329 AND `seat_id`=0);
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`) VALUES
(101329, 100652, 0, 0, 'Nightmare Bindings - Malfurion Stormrage', 8, 0); -- Nightmare Bindings - Malfurion Stormrage

-- Path for Deadsoul Ruiner
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+110;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+110, @CGUID+110, 0, 0, 515, 0, 0),
(@CGUID+110, @CGUID+132, 3, 90, 515, 1, 9),
(@CGUID+110, @CGUID+122, 3, 270, 515, 1, 9);

SET @MOVERGUID := @CGUID+110;
SET @ENTRY := 95771;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Dreadsoul Ruiner - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3157.2622, 2041.0399, 204.51868, NULL, 0),
(@PATH, 1, 3163.8567, 2044.0416, 205.18903, NULL, 5865),
(@PATH, 2, 3157.2622, 2041.0399, 204.51868, NULL, 0),
(@PATH, 3, 3151.1797, 2036.9445, 204.51866, NULL, 0),
(@PATH, 4, 3146.6926, 2031.7535, 204.51866, NULL, 0),
(@PATH, 5, 3141.4236, 2025.3594, 204.56613, NULL, 0),
(@PATH, 6, 3133.6858, 2021.2188, 205.50102, NULL, 0),
(@PATH, 7, 3126.5051, 2019.0209, 205.40163, NULL, 0),
(@PATH, 8, 3119.4424, 2015.2549, 205.80127, NULL, 0),
(@PATH, 9, 3115.8013, 2012.6129, 205.80869, NULL, 5678),
(@PATH, 10, 3126.5051, 2019.0209, 205.40163, NULL, 0),
(@PATH, 11, 3133.6858, 2021.2188, 205.50102, NULL, 0),
(@PATH, 12, 3141.4236, 2025.3594, 204.56613, NULL, 0),
(@PATH, 13, 3146.6926, 2031.7535, 204.51866, NULL, 0),
(@PATH, 14, 3151.1797, 2036.9445, 204.51866, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '195110');

-- Path for Deadsoul Ruiner
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+70;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+70, @CGUID+70, 0, 0, 515, 0, 0),
(@CGUID+70, @CGUID+57, 3, 270, 515, 14, 30);

SET @MOVERGUID := @CGUID+70;
SET @ENTRY := 95771;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Dreadsoul Ruiner - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3164.9402, 1898.066, 214.47389, NULL, 0),
(@PATH, 1, 3165.1562, 1904.507, 214.0743, NULL, 0),
(@PATH, 2, 3166.2822, 1909.5642, 214.23248, NULL, 0),
(@PATH, 3, 3169.6128, 1917.2692, 214.4172, NULL, 0),
(@PATH, 4, 3171.4072, 1921.8993, 214.36871, NULL, 0),
(@PATH, 5, 3179.1277, 1934.2413, 214.22609, NULL, 0),
(@PATH, 6, 3180.697, 1935.9254, 214.5142, NULL, 0),
(@PATH, 7, 3182.539, 1939.0278, 214.89653, NULL, 0),
(@PATH, 8, 3184.5068, 1943.6221, 215.6925, NULL, 0),
(@PATH, 9, 3186.507, 1949.9791, 216.03679, NULL, 0),
(@PATH, 10, 3188.6562, 1958.3055, 216.02122, NULL, 0),
(@PATH, 11, 3188.369, 1964.125, 215.96481, NULL, 0),
(@PATH, 12, 3188.8403, 1974.0295, 215.48521, NULL, 0),
(@PATH, 13, 3188.7544, 1978.9427, 215.16048, NULL, 0),
(@PATH, 14, 3188.4727, 1987.9424, 214.27213, NULL, 6181),
(@PATH, 15, 3188.7544, 1978.9427, 215.16048, NULL, 0),
(@PATH, 16, 3188.8403, 1974.0295, 215.48521, NULL, 0),
(@PATH, 17, 3188.369, 1964.125, 215.96481, NULL, 0),
(@PATH, 18, 3188.6562, 1958.3055, 216.02122, NULL, 0),
(@PATH, 19, 3186.507, 1949.9791, 216.03679, NULL, 0),
(@PATH, 20, 3184.5374, 1943.6962, 215.70009, NULL, 0),
(@PATH, 21, 3182.539, 1939.0278, 214.89653, NULL, 0),
(@PATH, 22, 3180.697, 1935.9254, 214.5142, NULL, 0),
(@PATH, 23, 3171.4072, 1921.8993, 214.36871, NULL, 0),
(@PATH, 24, 3169.6128, 1917.2692, 214.4172, NULL, 0),
(@PATH, 25, 3166.2822, 1909.5642, 214.23248, NULL, 0),
(@PATH, 26, 3165.1562, 1904.507, 214.0743, NULL, 0),
(@PATH, 27, 3164.9402, 1898.066, 214.47389, NULL, 0),
(@PATH, 28, 3165.7378, 1893.5938, 214.35481, NULL, 0),
(@PATH, 29, 3166.1685, 1890.231, 214.36913, NULL, 0),
(@PATH, 30, 3166.4836, 1887.9757, 214.41312, NULL, 5774),
(@PATH, 31, 3165.7378, 1893.5938, 214.35481, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '195110');

-- Path for Dradsoul Poisoner
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+97;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+97, @CGUID+97, 0, 0, 515, 0, 0),
(@CGUID+97, @CGUID+125, 3, 270, 515, 21, 43);

SET @MOVERGUID := @CGUID+97;
SET @ENTRY := 101679;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Dreadsoul Poisoner - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3078.269, 1953.0156, 203.66942, NULL, 0),
(@PATH, 1, 3077.0557, 1956.5382, 203.39664, NULL, 0),
(@PATH, 2, 3075.2075, 1960.2969, 203.21461, NULL, 0),
(@PATH, 3, 3072.7024, 1962.9098, 203.06004, NULL, 0),
(@PATH, 4, 3065.6362, 1963.3038, 202.7882, NULL, 0),
(@PATH, 5, 3059.467, 1963.1077, 202.56364, NULL, 0),
(@PATH, 6, 3053.8298, 1962.75, 202.36253, NULL, 0),
(@PATH, 7, 3046.2534, 1961.7639, 202.08374, NULL, 0),
(@PATH, 8, 3041.954, 1960.882, 201.89261, NULL, 0),
(@PATH, 9, 3036.5999, 1959.5729, 201.58777, NULL, 0),
(@PATH, 10, 3032.3325, 1958.3716, 201.29736, NULL, 0),
(@PATH, 11, 3028.8308, 1957.3317, 201.03915, NULL, 0),
(@PATH, 12, 3024.9287, 1956.4492, 200.61327, NULL, 0),
(@PATH, 13, 3018.1423, 1954.9375, 199.54395, NULL, 0),
(@PATH, 14, 3011, 1953.4375, 198.12189, NULL, 0),
(@PATH, 15, 3000.6042, 1951.7673, 196.0028, NULL, 0),
(@PATH, 16, 2994.6104, 1951.5449, 194.72412, NULL, 0),
(@PATH, 17, 2990.1328, 1951.8577, 193.89697, NULL, 0),
(@PATH, 18, 2986.1367, 1952.0254, 193.05365, NULL, 0),
(@PATH, 19, 2980.371, 1953.6895, 192.06491, NULL, 0),
(@PATH, 20, 2976.539, 1954.8418, 191.33043, NULL, 0),
(@PATH, 21, 2969.8213, 1957.6962, 190.3116, NULL, 6426),
(@PATH, 22, 2976.2607, 1954.9414, 191.33043, NULL, 0),
(@PATH, 23, 2980.3542, 1953.6927, 191.99628, NULL, 0),
(@PATH, 24, 2985.9895, 1952.0312, 193.06342, NULL, 0),
(@PATH, 25, 2989.9854, 1951.8633, 193.89067, NULL, 0),
(@PATH, 26, 2994.486, 1951.5399, 194.76736, NULL, 0),
(@PATH, 27, 3000.4805, 1951.7627, 195.98297, NULL, 0),
(@PATH, 28, 3011, 1953.4375, 198.12189, NULL, 0),
(@PATH, 29, 3018.1423, 1954.9375, 199.54395, NULL, 0),
(@PATH, 30, 3024.9019, 1956.4427, 200.68521, NULL, 0),
(@PATH, 31, 3028.8308, 1957.3317, 201.03915, NULL, 0),
(@PATH, 32, 3032.3325, 1958.3716, 201.29736, NULL, 0),
(@PATH, 33, 3036.5999, 1959.5729, 201.58777, NULL, 0),
(@PATH, 34, 3041.954, 1960.882, 201.89261, NULL, 0),
(@PATH, 35, 3046.2534, 1961.7639, 202.08374, NULL, 0),
(@PATH, 36, 3053.8298, 1962.75, 202.36253, NULL, 0),
(@PATH, 37, 3059.467, 1963.1077, 202.56364, NULL, 0),
(@PATH, 38, 3065.6362, 1963.3038, 202.7882, NULL, 0),
(@PATH, 39, 3072.7024, 1962.9098, 203.06004, NULL, 0),
(@PATH, 40, 3075.2075, 1960.2969, 203.21461, NULL, 0),
(@PATH, 41, 3077.0557, 1956.5382, 203.39664, NULL, 0),
(@PATH, 42, 3078.269, 1953.0156, 203.66942, NULL, 0),
(@PATH, 43, 3078.125, 1947.1024, 203.78828, NULL, 5331);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '195110');

-- Path for Deadsoul Poisoner
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+114;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+114, @CGUID+114, 0, 0, 515, 0, 0),
(@CGUID+114, @CGUID+92, 3, 90, 515, 0, 0),
(@CGUID+114, @CGUID+106, 3, 270, 515, 0, 0);

SET @MOVERGUID := @CGUID+114;
SET @ENTRY := 101679;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Dreadsoul Poisoner - Formtation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3108.27, 1927.1216, 205.95688, NULL, 0),
(@PATH, 1, 3104.3472, 1931.8038, 205.86354, NULL, 0),
(@PATH, 2, 3100.217, 1936.3298, 205.1761, NULL, 0),
(@PATH, 3, 3096.487, 1941.1302, 205.65567, NULL, 0),
(@PATH, 4, 3090.9348, 1943.3976, 205.04755, NULL, 0),
(@PATH, 5, 3087.5676, 1944.4445, 204.68758, NULL, 0),
(@PATH, 6, 3084.8542, 1947.0087, 204.08893, NULL, 0),
(@PATH, 7, 3083.9602, 1950.7448, 204.22432, NULL, 0),
(@PATH, 8, 3085.0374, 1955.6771, 204.0861, NULL, 0),
(@PATH, 9, 3086.5051, 1958.8594, 204.18568, NULL, 0),
(@PATH, 10, 3089.034, 1961.7291, 204.09343, NULL, 0),
(@PATH, 11, 3094.9446, 1961.6858, 205.04822, NULL, 0),
(@PATH, 12, 3100.6243, 1960.6423, 205.01942, NULL, 0),
(@PATH, 13, 3105.6824, 1959.8317, 205.33908, NULL, 0),
(@PATH, 14, 3108.5737, 1956.7257, 204.98367, NULL, 0),
(@PATH, 15, 3111.1946, 1954.401, 204.8354, NULL, 0),
(@PATH, 16, 3113.514, 1950.8611, 204.93567, NULL, 0),
(@PATH, 17, 3114.3403, 1946.8942, 204.94174, NULL, 0),
(@PATH, 18, 3116.6165, 1937.6354, 205.16441, NULL, 0),
(@PATH, 19, 3118.5876, 1932.3663, 205.27647, NULL, 0),
(@PATH, 20, 3117.7231, 1928.5278, 205.71988, NULL, 0),
(@PATH, 21, 3112.6729, 1926.0278, 205.96616, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, 3, '195110');

-- Path for Rotheart Dryad
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+195;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+195, @CGUID+195, 0, 0, 515, 0, 0),
(@CGUID+195, @CGUID+190, 3, 90, 515, 1, 21),
(@CGUID+195, @CGUID+191, 3, 270, 515, 1, 21);

SET @MOVERGUID := @CGUID+195;
SET @ENTRY := 99358;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Rotheart Dryad - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2745.9792, 1857.6389, 184.97818, NULL, 0),
(@PATH, 1, 2745.0676, 1863.5538, 184.9798, NULL, 6465),
(@PATH, 2, 2745.9792, 1857.6389, 184.97818, NULL, 0),
(@PATH, 3, 2747.322, 1853.9601, 184.97818, NULL, 0),
(@PATH, 4, 2752.5166, 1849.3004, 184.97818, NULL, 0),
(@PATH, 5, 2757.8784, 1845.5573, 184.97818, NULL, 0),
(@PATH, 6, 2760.5435, 1843.0973, 184.97818, NULL, 0),
(@PATH, 7, 2763.8098, 1839.1094, 184.97818, NULL, 0),
(@PATH, 8, 2765.784, 1833.908, 184.97818, NULL, 0),
(@PATH, 9, 2764.1685, 1828.4392, 184.97818, NULL, 0),
(@PATH, 10, 2760.0747, 1823.1979, 184.97818, NULL, 0),
(@PATH, 11, 2756.2986, 1820.3733, 184.97818, NULL, 0),
(@PATH, 12, 2749.7336, 1818.9688, 184.97818, NULL, 0),
(@PATH, 13, 2745.4446, 1820.1719, 184.97818, NULL, 0),
(@PATH, 14, 2741.8394, 1822.8038, 184.97818, NULL, 0),
(@PATH, 15, 2738.744, 1826.6267, 184.97818, NULL, 0),
(@PATH, 16, 2737.2952, 1838.6632, 184.97818, NULL, 0),
(@PATH, 17, 2738.2917, 1845.5625, 184.97818, NULL, 0),
(@PATH, 18, 2741.0972, 1853.6372, 184.97818, NULL, 0),
(@PATH, 19, 2743.3855, 1861.4584, 184.97818, NULL, 0),
(@PATH, 20, 2744.7395, 1868.4462, 185.03555, NULL, 0),
(@PATH, 21, 2745.2415, 1873.9913, 185.19017, NULL, 6255),
(@PATH, 22, 2744.7395, 1868.4462, 185.03555, NULL, 0),
(@PATH, 23, 2743.3855, 1861.4584, 184.97818, NULL, 0),
(@PATH, 24, 2741.0972, 1853.6372, 184.97818, NULL, 0),
(@PATH, 25, 2738.2917, 1845.5625, 184.97818, NULL, 0),
(@PATH, 26, 2737.2952, 1838.6632, 184.97818, NULL, 0),
(@PATH, 27, 2738.744, 1826.6267, 184.97818, NULL, 0),
(@PATH, 28, 2741.8394, 1822.8038, 184.97818, NULL, 0),
(@PATH, 29, 2745.4446, 1820.1719, 184.97818, NULL, 0),
(@PATH, 30, 2749.7336, 1818.9688, 184.97818, NULL, 0),
(@PATH, 31, 2756.2986, 1820.3733, 184.97818, NULL, 0),
(@PATH, 32, 2760.0747, 1823.1979, 184.97818, NULL, 0),
(@PATH, 33, 2764.1685, 1828.4392, 184.97818, NULL, 0),
(@PATH, 34, 2765.784, 1833.908, 184.97818, NULL, 0),
(@PATH, 35, 2763.8098, 1839.1094, 184.97818, NULL, 0),
(@PATH, 36, 2760.5435, 1843.0973, 184.97818, NULL, 0),
(@PATH, 37, 2757.8784, 1845.5573, 184.97818, NULL, 0),
(@PATH, 38, 2752.5166, 1849.3004, 184.97818, NULL, 0),
(@PATH, 39, 2747.322, 1853.9601, 184.97818, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Rotheart Dryad
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+181;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+181, @CGUID+181, 0, 0, 515, 0, 0),
(@CGUID+181, @CGUID+173, 3, 90, 515, 5, 11),
(@CGUID+181, @CGUID+174, 3, 270, 515, 5, 11);

SET @MOVERGUID := @CGUID+181;
SET @ENTRY := 99358;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Rotheart Dryad - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2896.6372, 1764.625, 153.87596, NULL, 0),
(@PATH, 1, 2872.2666, 1764.7882, 162.77533, NULL, 0),
(@PATH, 2, 2846.0027, 1767.1545, 173.41426, NULL, 0),
(@PATH, 3, 2824.9497, 1776.3281, 180.51764, NULL, 0),
(@PATH, 4, 2809.8838, 1790.2396, 183.13751, NULL, 0),
(@PATH, 5, 2796.3743, 1802.4358, 184.49573, NULL, 5515),
(@PATH, 6, 2809.8838, 1790.2396, 183.13751, NULL, 0),
(@PATH, 7, 2824.9497, 1776.3281, 180.51764, NULL, 0),
(@PATH, 8, 2846.0027, 1767.1545, 173.41426, NULL, 0),
(@PATH, 9, 2872.2666, 1764.7882, 162.77533, NULL, 0),
(@PATH, 10, 2896.6372, 1764.625, 153.87596, NULL, 0),
(@PATH, 11, 2931.5557, 1759.9514, 144.37218, NULL, 5693);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Nightmare Dweller
SET @MOVERGUID := @CGUID+129;
SET @ENTRY := 101991;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Nightmare Dweller - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2969.0635, 1781.9896, 142.05229, NULL, 0),
(@PATH, 1, 2973.9592, 1784.9584, 142.17845, NULL, 0),
(@PATH, 2, 2981.448, 1788.566, 141.65576, NULL, 0),
(@PATH, 3, 2985.9514, 1790.941, 141.78232, NULL, 0),
(@PATH, 4, 2985.6355, 1795.7552, 141.86922, NULL, 0),
(@PATH, 5, 2982.462, 1802.1493, 141.60648, NULL, 8109),
(@PATH, 6, 2985.6355, 1795.7552, 141.86922, NULL, 0),
(@PATH, 7, 2985.9514, 1790.941, 141.78232, NULL, 0),
(@PATH, 8, 2981.448, 1788.566, 141.65576, NULL, 0),
(@PATH, 9, 2973.9592, 1784.9584, 142.17845, NULL, 0),
(@PATH, 10, 2969.0635, 1781.9896, 142.05229, NULL, 0),
(@PATH, 11, 2966.25, 1777.618, 141.6219, NULL, 0),
(@PATH, 12, 2963.1953, 1773.0382, 141.73239, NULL, 0),
(@PATH, 13, 2959.2422, 1769.9774, 141.62796, NULL, 0),
(@PATH, 14, 2955.626, 1768.8942, 141.72363, NULL, 0),
(@PATH, 15, 2952.9565, 1767.6598, 141.89328, NULL, 0),
(@PATH, 16, 2950.2734, 1766.7604, 142.04645, NULL, 0),
(@PATH, 17, 2947.0781, 1766.0903, 141.7421, NULL, 7157),
(@PATH, 18, 2952.9565, 1767.6598, 141.89328, NULL, 0),
(@PATH, 19, 2959.2422, 1769.9774, 141.62796, NULL, 0),
(@PATH, 20, 2963.1953, 1773.0382, 141.73239, NULL, 0),
(@PATH, 21, 2966.25, 1777.618, 141.6219, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 4);

-- Path for Nightmare Dweller
SET @MOVERGUID := @CGUID+116;
SET @ENTRY := 101991;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Nightmare Dweller - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2946.8342, 1761.8073, 141.9662, NULL, 0),
(@PATH, 1, 2940.6199, 1761.9896, 142.649, NULL, 9311),
(@PATH, 2, 2946.8342, 1761.8073, 141.9662, NULL, 0),
(@PATH, 3, 2954.2822, 1761.5, 141.78482, NULL, 0),
(@PATH, 4, 2961.428, 1765.1285, 141.76926, NULL, 0),
(@PATH, 5, 2964.5999, 1768.3524, 141.84633, NULL, 0),
(@PATH, 6, 2971.4575, 1777.6233, 141.92052, NULL, 0),
(@PATH, 7, 2976.1926, 1780.9427, 141.81848, NULL, 0),
(@PATH, 8, 2982.0833, 1784.6406, 141.33937, NULL, 0),
(@PATH, 9, 2987.927, 1783.981, 141.86421, NULL, 0),
(@PATH, 10, 2993.6467, 1790.3125, 142.23808, NULL, 0),
(@PATH, 11, 3004.3057, 1800.8854, 141.74954, NULL, 6571),
(@PATH, 12, 2993.6467, 1790.3125, 142.23808, NULL, 0),
(@PATH, 13, 2987.927, 1783.981, 141.86421, NULL, 0),
(@PATH, 14, 2982.0833, 1784.6406, 141.33937, NULL, 0),
(@PATH, 15, 2976.1926, 1780.9427, 141.81848, NULL, 0),
(@PATH, 16, 2971.4575, 1777.6233, 141.92052, NULL, 0),
(@PATH, 17, 2964.5999, 1768.3524, 141.84633, NULL, 0),
(@PATH, 18, 2961.428, 1765.1285, 141.76926, NULL, 0),
(@PATH, 19, 2954.2822, 1761.5, 141.78482, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 4);

-- Path for Nightmare Dweller
SET @MOVERGUID := @CGUID+76;
SET @ENTRY := 101991;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Nightmare Dweller - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2960.4792, 1748.5504, 141.99426, NULL, 0),
(@PATH, 1, 2956.381, 1745.7622, 141.92612, NULL, 0),
(@PATH, 2, 2949.1963, 1741.4827, 141.65137, NULL, 0),
(@PATH, 3, 2945.1128, 1735.6267, 141.65932, NULL, 0),
(@PATH, 4, 2942.5286, 1725.4479, 141.88878, NULL, 0),
(@PATH, 5, 2949.3176, 1721.0348, 141.95331, NULL, 0),
(@PATH, 6, 2954.2925, 1719.5642, 141.8361, NULL, 9753),
(@PATH, 7, 2949.3176, 1721.0348, 141.95331, NULL, 0),
(@PATH, 8, 2942.5286, 1725.4479, 141.88878, NULL, 0),
(@PATH, 9, 2945.1128, 1735.6267, 141.65932, NULL, 0),
(@PATH, 10, 2949.1963, 1741.4827, 141.65137, NULL, 0),
(@PATH, 11, 2956.381, 1745.7622, 141.92612, NULL, 0),
(@PATH, 12, 2960.4792, 1748.5504, 141.99426, NULL, 0),
(@PATH, 13, 2968.5166, 1751.8716, 141.90771, NULL, 0),
(@PATH, 14, 2975.0713, 1752.4323, 141.81955, NULL, 0),
(@PATH, 15, 2981.284, 1751.6771, 141.80388, NULL, 0),
(@PATH, 16, 2989.0686, 1748.7135, 141.90778, NULL, 0),
(@PATH, 17, 2993.3308, 1740.743, 142.26688, NULL, 0),
(@PATH, 18, 2998.0808, 1735.6216, 142.27734, NULL, 6248),
(@PATH, 19, 2993.3308, 1740.743, 142.26688, NULL, 0),
(@PATH, 20, 2989.0686, 1748.7135, 141.90778, NULL, 0),
(@PATH, 21, 2981.284, 1751.6771, 141.80388, NULL, 0),
(@PATH, 22, 2975.0713, 1752.4323, 141.81955, NULL, 0),
(@PATH, 23, 2968.5166, 1751.8716, 141.90771, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 4);

-- Path for Nightmare Dweller
SET @MOVERGUID := @CGUID+35;
SET @ENTRY := 101991;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Nightmare Dweller - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2994.2153, 1766.191, 142.1512, NULL, 0),
(@PATH, 1, 2986.7883, 1759.625, 141.97556, NULL, 0),
(@PATH, 2, 2978.1008, 1756.7882, 141.77365, NULL, 0),
(@PATH, 3, 2970.8862, 1756.6962, 141.86322, NULL, 0),
(@PATH, 4, 2962.6711, 1757.066, 141.91296, NULL, 0),
(@PATH, 5, 2955.7969, 1756.4254, 141.76599, NULL, 0),
(@PATH, 6, 2951.0815, 1754.2014, 141.71161, NULL, 0),
(@PATH, 7, 2947.1858, 1749.1702, 141.8297, NULL, 0),
(@PATH, 8, 2945.1223, 1745.5243, 141.68657, NULL, 0),
(@PATH, 9, 2943.289, 1740.0695, 141.57265, NULL, 0),
(@PATH, 10, 2939.3455, 1735.0868, 141.56349, NULL, 0),
(@PATH, 11, 2933.961, 1731.2118, 141.5592, NULL, 0),
(@PATH, 12, 2928.4055, 1731.1823, 141.65372, NULL, 0),
(@PATH, 13, 2923.8186, 1731.151, 141.65576, NULL, 0),
(@PATH, 14, 2919.0034, 1733.2031, 141.71341, NULL, 9937),
(@PATH, 15, 2923.8186, 1731.151, 141.65576, NULL, 0),
(@PATH, 16, 2928.4055, 1731.1823, 141.65372, NULL, 0),
(@PATH, 17, 2933.961, 1731.2118, 141.5592, NULL, 0),
(@PATH, 18, 2939.3455, 1735.0868, 141.56349, NULL, 0),
(@PATH, 19, 2943.289, 1740.0695, 141.57265, NULL, 0),
(@PATH, 20, 2945.1223, 1745.5243, 141.68657, NULL, 0),
(@PATH, 21, 2947.1858, 1749.1702, 141.8297, NULL, 0),
(@PATH, 22, 2951.0815, 1754.2014, 141.71161, NULL, 0),
(@PATH, 23, 2955.7969, 1756.4254, 141.76599, NULL, 0),
(@PATH, 24, 2962.6711, 1757.066, 141.91296, NULL, 0),
(@PATH, 25, 2970.8862, 1756.6962, 141.86322, NULL, 0),
(@PATH, 26, 2978.1008, 1756.7882, 141.77365, NULL, 0),
(@PATH, 27, 2986.7883, 1759.625, 141.97556, NULL, 0),
(@PATH, 28, 2994.2153, 1766.191, 142.1512, NULL, 0),
(@PATH, 29, 2999.8933, 1771.7692, 142.2218, NULL, 8736);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 4);

-- Path for Nightwell Dweller
SET @MOVERGUID := @CGUID+24;
SET @ENTRY := 101991;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Nightmare Dweller - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2931.501, 1746.743, 144.87741, NULL, 0),
(@PATH, 1, 2934.587, 1750.6787, 143.96661, NULL, 0),
(@PATH, 2, 2937.3542, 1753.6372, 143.41158, NULL, 0),
(@PATH, 3, 2943.0156, 1756.0625, 142.22433, NULL, 0),
(@PATH, 4, 2951.6433, 1758.0973, 141.75523, NULL, 0),
(@PATH, 5, 2961.5686, 1760.9392, 141.89896, NULL, 0),
(@PATH, 6, 2969.0479, 1765.4271, 141.90701, NULL, 0),
(@PATH, 7, 2973.0618, 1770.0486, 141.86835, NULL, 0),
(@PATH, 8, 2975.3176, 1775.566, 141.76936, NULL, 0),
(@PATH, 9, 2980.7656, 1779.1528, 141.53395, NULL, 9942),
(@PATH, 10, 2975.3176, 1775.566, 141.76936, NULL, 0),
(@PATH, 11, 2973.0618, 1770.0486, 141.86835, NULL, 0),
(@PATH, 12, 2969.0479, 1765.4271, 141.90701, NULL, 0),
(@PATH, 13, 2961.5686, 1760.9392, 141.89896, NULL, 0),
(@PATH, 14, 2951.6433, 1758.0973, 141.75523, NULL, 0),
(@PATH, 15, 2943.0156, 1756.0625, 142.22433, NULL, 0),
(@PATH, 16, 2937.3542, 1753.6372, 143.41158, NULL, 0),
(@PATH, 17, 2934.606, 1750.7048, 144.02042, NULL, 0),
(@PATH, 18, 2931.5195, 1746.7695, 144.93074, NULL, 0),
(@PATH, 19, 2928.6606, 1747.0122, 145.31699, NULL, 0),
(@PATH, 20, 2926.5322, 1748.474, 145.68346, NULL, 9933);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 4);

-- Path for Mindshattered Screecher
SET @MOVERGUID := @CGUID+26;
SET @ENTRY := 95769;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 16.0866, 'Mindshattered Screecher - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3089.121, 1755.6342, 274.167, NULL, 0),
(@PATH, 1, 3100.4758, 1763.2212, 274.167, NULL, 0),
(@PATH, 2, 3113.8699, 1765.8854, 274.167, NULL, 0),
(@PATH, 3, 3127.2637, 1763.2212, 274.167, NULL, 0),
(@PATH, 4, 3138.6187, 1755.6342, 274.167, NULL, 0),
(@PATH, 5, 3146.2056, 1744.2793, 274.167, NULL, 0),
(@PATH, 6, 3148.8699, 1730.8854, 274.167, NULL, 0),
(@PATH, 7, 3146.2056, 1717.4915, 274.167, NULL, 0),
(@PATH, 8, 3138.6187, 1706.1366, 274.167, NULL, 0),
(@PATH, 9, 3127.2637, 1698.5496, 274.167, NULL, 0),
(@PATH, 10, 3113.8699, 1695.8854, 274.167, NULL, 0),
(@PATH, 11, 3100.4758, 1698.5496, 274.167, NULL, 0),
(@PATH, 12, 3089.121, 1706.1366, 274.167, NULL, 0),
(@PATH, 13, 3081.5342, 1717.4915, 274.167, NULL, 0),
(@PATH, 14, 3078.8699, 1730.8854, 274.167, NULL, 0),
(@PATH, 15, 3081.5342, 1744.2793, 274.167, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Mindshattered Screecher
SET @MOVERGUID := @CGUID+130;
SET @ENTRY := 95769;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 16.0867, 'Mindshattered Screecher - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3089.6357, 1839.6354, 274.83276, NULL, 0),
(@PATH, 1, 3100.8635, 1847.4092, 274.83276, NULL, 0),
(@PATH, 2, 3114.2114, 1850.2946, 274.83276, NULL, 0),
(@PATH, 3, 3127.6477, 1847.8523, 274.83276, NULL, 0),
(@PATH, 4, 3139.1265, 1840.454, 274.83276, NULL, 0),
(@PATH, 5, 3146.9001, 1829.2262, 274.83276, NULL, 0),
(@PATH, 6, 3149.7856, 1815.8782, 274.83276, NULL, 0),
(@PATH, 7, 3147.3433, 1802.4421, 274.83276, NULL, 0),
(@PATH, 8, 3139.945, 1790.9634, 274.83276, NULL, 0),
(@PATH, 9, 3128.7173, 1783.1896, 274.83276, NULL, 0),
(@PATH, 10, 3115.3691, 1780.3041, 274.83276, NULL, 0),
(@PATH, 11, 3101.933, 1782.7465, 274.83276, NULL, 0),
(@PATH, 12, 3090.4543, 1790.1447, 274.83276, NULL, 0),
(@PATH, 13, 3082.6807, 1801.3724, 274.83276, NULL, 0),
(@PATH, 14, 3079.7952, 1814.7205, 274.83276, NULL, 0),
(@PATH, 15, 3082.2375, 1828.1566, 274.83276, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Mindshattered Screecher
SET @MOVERGUID := @CGUID+34;
SET @ENTRY := 95769;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 16.0866, 'Mindshattered Screecher - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3008.8164, 1768.5005, 274.6673, NULL, 0),
(@PATH, 1, 3020.1711, 1776.0875, 274.6673, NULL, 0),
(@PATH, 2, 3033.5652, 1778.7517, 274.6673, NULL, 0),
(@PATH, 3, 3046.959, 1776.0875, 274.6673, NULL, 0),
(@PATH, 4, 3058.314, 1768.5005, 274.6673, NULL, 0),
(@PATH, 5, 3065.901, 1757.1456, 274.6673, NULL, 0),
(@PATH, 6, 3068.5652, 1743.7517, 274.6673, NULL, 0),
(@PATH, 7, 3065.901, 1730.3578, 274.6673, NULL, 0),
(@PATH, 8, 3058.314, 1719.0029, 274.6673, NULL, 0),
(@PATH, 9, 3046.959, 1711.4159, 274.6673, NULL, 0),
(@PATH, 10, 3033.5652, 1708.7517, 274.6673, NULL, 0),
(@PATH, 11, 3020.1711, 1711.4159, 274.6673, NULL, 0),
(@PATH, 12, 3008.8164, 1719.0029, 274.6673, NULL, 0),
(@PATH, 13, 3001.2295, 1730.3578, 274.6673, NULL, 0),
(@PATH, 14, 2998.5652, 1743.7517, 274.6673, NULL, 0),
(@PATH, 15, 3001.2295, 1757.1456, 274.6673, NULL, 0);

UPDATE `creature` SET `position_x`=3008.8164, `position_y`=1768.5005, `position_z`=274.6673, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Mindshattered Screecher
SET @MOVERGUID := @CGUID+36;
SET @ENTRY := 95769;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 16.0865, 'Mindshattered Screecher - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3121.6453, 1812.2123, 245.73233, NULL, 0),
(@PATH, 1, 3133, 1819.7993, 245.73233, NULL, 0),
(@PATH, 2, 3146.7776, 1823.1653, 245.98334, NULL, 0),
(@PATH, 3, 3159.7878, 1819.7993, 245.73233, NULL, 0),
(@PATH, 4, 3171.1428, 1812.2123, 245.73233, NULL, 0),
(@PATH, 5, 3178.7297, 1800.8574, 245.73233, NULL, 0),
(@PATH, 6, 3181.394, 1787.4635, 245.73233, NULL, 0),
(@PATH, 7, 3178.7297, 1774.0696, 245.73233, NULL, 0),
(@PATH, 8, 3171.1428, 1762.7147, 245.73233, NULL, 0),
(@PATH, 9, 3159.788, 1755.1277, 245.73233, NULL, 0),
(@PATH, 10, 3146.394, 1752.4635, 245.73233, NULL, 0),
(@PATH, 11, 3133, 1755.1277, 245.73233, NULL, 0),
(@PATH, 12, 3121.6453, 1762.7147, 245.73233, NULL, 0),
(@PATH, 13, 3114.0583, 1774.0696, 245.73233, NULL, 0),
(@PATH, 14, 3111.394, 1787.4635, 245.73233, NULL, 0),
(@PATH, 15, 3114.0583, 1800.8574, 245.73233, NULL, 0);

UPDATE `creature` SET `position_x`=3121.6453, `position_y`=1812.2123, `position_z`=245.73233, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Bloodtainted Fury
SET @MOVERGUID := @CGUID+84;
SET @ENTRY := 100531;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Bloodtainted Fury - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3088.257, 1653.3334, 138.15742, NULL, 4536),
(@PATH, 1, 3091.0598, 1643.5104, 137.98851, NULL, 0),
(@PATH, 2, 3091.7466, 1629.9913, 137.4015, NULL, 0),
(@PATH, 3, 3093.8499, 1619.7726, 137.35625, NULL, 0),
(@PATH, 4, 3099.6145, 1612.4202, 137.36075, NULL, 0),
(@PATH, 5, 3105.0244, 1605.5851, 137.33784, NULL, 0),
(@PATH, 6, 3113.4497, 1602.8334, 137.34346, NULL, 0),
(@PATH, 7, 3118.361, 1607.8611, 137.33601, NULL, 6989),
(@PATH, 8, 3113.4497, 1602.8334, 137.34346, NULL, 0),
(@PATH, 9, 3105.0244, 1605.5851, 137.33784, NULL, 0),
(@PATH, 10, 3099.6145, 1612.4202, 137.36075, NULL, 0),
(@PATH, 11, 3093.8499, 1619.7726, 137.35625, NULL, 0),
(@PATH, 12, 3091.7466, 1629.9913, 137.4015, NULL, 0),
(@PATH, 13, 3091.0598, 1643.5104, 137.98851, NULL, 0);

UPDATE `creature` SET `position_x`=3088.257, `position_y`=1653.3334, `position_z`=138.15742, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Bloodtainted Fury
SET @MOVERGUID := @CGUID+276;
SET @ENTRY := 100531;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Bloodtainted Fury - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 3063.139, 1541.231, 137.76222, NULL, 0),
(@PATH, 1, 3069.1719, 1542.0555, 137.5909, NULL, 0),
(@PATH, 2, 3076.02, 1542.9185, 137.42834, NULL, 0),
(@PATH, 3, 3082.0156, 1543.2379, 137.3173, NULL, 0),
(@PATH, 4, 3091.2622, 1541.8473, 137.50203, NULL, 0),
(@PATH, 5, 3102.2864, 1539.7812, 137.06802, NULL, 0),
(@PATH, 6, 3109.0312, 1537.9531, 137.79765, NULL, 0),
(@PATH, 7, 3113.7493, 1535.9445, 140.21193, NULL, 0),
(@PATH, 8, 3116.7031, 1532.0365, 141.88133, NULL, 5419),
(@PATH, 9, 3113.7493, 1535.9445, 140.21193, NULL, 0),
(@PATH, 10, 3109.1494, 1537.9023, 137.7218, NULL, 0),
(@PATH, 11, 3102.2864, 1539.7812, 137.06802, NULL, 0),
(@PATH, 12, 3091.2622, 1541.8473, 137.50203, NULL, 0),
(@PATH, 13, 3085.9514, 1543.1719, 137.37375, NULL, 0),
(@PATH, 14, 3082.0156, 1543.2379, 137.3173, NULL, 0),
(@PATH, 15, 3076.02, 1542.9185, 137.42834, NULL, 0),
(@PATH, 16, 3069.1719, 1542.0555, 137.5909, NULL, 0),
(@PATH, 17, 3063.139, 1541.231, 137.76222, NULL, 0),
(@PATH, 18, 3056.908, 1541.6354, 138.08836, NULL, 6454);

UPDATE `creature` SET `position_x`=3063.139, `position_y`=1541.231, `position_z`=137.76222, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `visibilityDistanceType`) VALUES
(@MOVERGUID, @PATH, 1, 3);

-- Path for Taintheart Summoner
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+205;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+205, @CGUID+205, 0, 0, 515, 0, 0),
(@CGUID+205, @CGUID+207, 3, 90, 515, 1, 6),
(@CGUID+205, @CGUID+206, 3, 270, 515, 1, 6);

SET @MOVERGUID := @CGUID+205;
SET @ENTRY := 99366;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Taintheart Summoner - Formation Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2861.4758, 1568.908, 107.91906, NULL, 0),
(@PATH, 1, 2856.9895, 1562.4913, 109.393486, NULL, 0),
(@PATH, 2, 2861.4758, 1568.908, 107.91906, NULL, 0),
(@PATH, 3, 2868.579, 1578.3837, 104.63018, NULL, 0),
(@PATH, 4, 2882.4028, 1587.9132, 100.80292, NULL, 0),
(@PATH, 5, 2896.179, 1592.5486, 98.35439, NULL, 0),
(@PATH, 6, 2905.6284, 1595.099, 96.644455, NULL, 0),
(@PATH, 7, 2896.179, 1592.5486, 98.35439, NULL, 0),
(@PATH, 8, 2879.9045, 1586.191, 101.43369, NULL, 0),
(@PATH, 9, 2873.3271, 1581.6567, 103.3385, NULL, 0),
(@PATH, 10, 2869.827, 1579.2439, 104.3545, NULL, 0),
(@PATH, 11, 2868.579, 1578.3837, 104.63018, NULL, 0);

UPDATE `creature` SET `position_x`=2861.4758, `position_y`=1568.908, `position_z`=107.91906 WHERE `guid` IN (@CGUID+207, @CGUID+206);
UPDATE `creature` SET `position_x`=2861.4758, `position_y`=1568.908, `position_z`=107.91906, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Perserver Ray Invisible Stalker
SET @MOVERGUID := @CGUID+179;
SET @ENTRY := 100404;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Perserver Ray Invisible Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2910.9114, 1996.7935, 189.96616, NULL, 353),
(@PATH, 1, 2923.408, 1986.6024, 189.75598, NULL, 368);

UPDATE `creature` SET `position_x`=2910.9114, `position_y`=1996.7935, `position_z`=189.96616, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Perserver Ray Invisible Stalker
SET @MOVERGUID := @CGUID+175;
SET @ENTRY := 100404;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Perserver Ray Invisible Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2888.6946, 1936.7483, 190.01631, NULL, 0),
(@PATH, 1, 2893.0435, 1935.7084, 190.18222, NULL, 0),
(@PATH, 2, 2897.3923, 1934.6685, 190.34813, NULL, 0),
(@PATH, 3, 2900.9236, 1935.2639, 190.17812, NULL, 0),
(@PATH, 4, 2893.0435, 1935.7084, 190.18222, NULL, 0);

UPDATE `creature` SET `position_x`=2888.6946, `position_y`=1936.7483, `position_z`=190.01631, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Perserver Ray Invisible Stalker
SET @MOVERGUID := @CGUID+178;
SET @ENTRY := 100404;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Perserver Ray Invisible Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2869.3464, 1949.3073, 189.66127, NULL, 0),
(@PATH, 1, 2873.3176, 1944.0573, 189.79013, NULL, 0),
(@PATH, 2, 2877.6484, 1940.5695, 189.93634, NULL, 0),
(@PATH, 3, 2882.6484, 1937.7517, 190.01437, NULL, 0),
(@PATH, 4, 2877.6484, 1940.5695, 189.93634, NULL, 0),
(@PATH, 5, 2873.3176, 1944.0573, 189.79013, NULL, 0);

UPDATE `creature` SET `position_x`=2869.3464, `position_y`=1949.3073, `position_z`=189.66127, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Perserver Ray Invisible Stalker
SET @MOVERGUID := @CGUID+180;
SET @ENTRY := 100404;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Perserver Ray Invisible Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2866.4592, 1950.6199, 189.34901, NULL, 0),
(@PATH, 1, 2865.1277, 1958.4567, 189.57208, NULL, 0),
(@PATH, 2, 2863.7961, 1966.2935, 189.79515, NULL, 0),
(@PATH, 3, 2864.1086, 1972.0017, 190.31932, NULL, 0),
(@PATH, 4, 2865.308, 1976.6805, 190.27916, NULL, 0),
(@PATH, 5, 2866.5076, 1981.3594, 190.239, NULL, 0),
(@PATH, 6, 2865.308, 1976.6805, 190.27916, NULL, 0),
(@PATH, 7, 2864.1086, 1972.0017, 190.31932, NULL, 0),
(@PATH, 8, 2863.7961, 1966.2935, 189.79515, NULL, 0),
(@PATH, 9, 2865.1277, 1958.4567, 189.57208, NULL, 0);

UPDATE `creature` SET `position_x`=2866.4592, `position_y`=1950.6199, `position_z`=189.34901, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Perserver Ray Invisible Stalker
SET @MOVERGUID := @CGUID+171;
SET @ENTRY := 100404;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x01, NULL, 'Perserver Ray Invisible Stalker - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2925.448, 1984.6406, 190.9359, NULL, 0),
(@PATH, 1, 2927.4966, 1979.4132, 190.33942, NULL, 0),
(@PATH, 2, 2929.5452, 1974.1858, 189.74294, NULL, 0),
(@PATH, 3, 2929.683, 1967.9584, 189.69075, NULL, 0),
(@PATH, 4, 2929.4097, 1962.8698, 189.73477, NULL, 0),
(@PATH, 5, 2927.5513, 1957.3212, 189.9886, NULL, 0);

UPDATE `creature` SET `position_x`=2925.448, `position_y`=1984.6406, `position_z`=190.9359, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
