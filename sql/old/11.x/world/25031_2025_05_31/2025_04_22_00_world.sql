SET @CGUID := 5000558;
SET @OGUID := 5000077;

DELETE FROM `creature` WHERE `map` = 48 AND `guid` IN (18716,18717,18718,18719,18720,18721,18722,18723,18724,18725,18726,18727,18728,18729,18730,18731,18732,18733,18734,18735,18736,18737,18738,18739,18740,18741,18742,18743,18744,18745,18746,18747,18748,18749,18750,18751,18752,18753,18754,18755,18756,18989,18990,18992,19226,22274,22318,22332,25066,25067,25730,25731,25732,25733,25734,25735,25736,25737,25904,25905,26005,26006,26007,26008,26010,26011,26012,26013,26014,26015,26016,26017,26018,26028,26051,26052,26108,26109,26110,26111,26112,26113,26114,26115,26116,26117,26118,26119,26120,26121,26129,26130,26131,26132,26133,26134,26135,26136,26137,26138,26139,26140,26141,26142,26143,26144,26145,26146,26147,26148,26149,26150,26151,26152,26153,26154,26155,26156,26157,26170,26173,26285,26286,26287,26288,26289,26290,26291,26292,26293,26294,26295,26296,26297,26298,26299,26300,26301,26302,26303,26304,26305,26306,26307,26308,26309,26310,26311,26312,26313,26314,26315,26316,26317,26318,26319,26320,26321,26322,26323,26324,26325,26326,26327,26328,26329,26330,26331,26332,26333,27352,27390,27396,27397,27399,27400,27401,27402,27403,27404,27405,27406,27407,27408,27409,27410,27411,27412,27413,27414,27415,27416,27417,27418,27419,27420,27421,27422,27423,27424,27425,27426,27427,27428,27429,27430,27431,27432,27433,27434,27435,27436);
DELETE FROM `creature_addon` WHERE `guid` IN (18716,18717,18718,18719,18720,18721,18722,18723,18724,18725,18726,18727,18728,18729,18730,18731,18732,18733,18734,18735,18736,18737,18738,18739,18740,18741,18742,18743,18744,18745,18746,18747,18748,18749,18750,18751,18752,18753,18754,18755,18756,18989,18990,18992,19226,22274,22318,22332,25066,25067,25730,25731,25732,25733,25734,25735,25736,25737,25904,25905,26005,26006,26007,26008,26010,26011,26012,26013,26014,26015,26016,26017,26018,26028,26051,26052,26108,26109,26110,26111,26112,26113,26114,26115,26116,26117,26118,26119,26120,26121,26129,26130,26131,26132,26133,26134,26135,26136,26137,26138,26139,26140,26141,26142,26143,26144,26145,26146,26147,26148,26149,26150,26151,26152,26153,26154,26155,26156,26157,26170,26173,26285,26286,26287,26288,26289,26290,26291,26292,26293,26294,26295,26296,26297,26298,26299,26300,26301,26302,26303,26304,26305,26306,26307,26308,26309,26310,26311,26312,26313,26314,26315,26316,26317,26318,26319,26320,26321,26322,26323,26324,26325,26326,26327,26328,26329,26330,26331,26332,26333,27352,27390,27396,27397,27399,27400,27401,27402,27403,27404,27405,27406,27407,27408,27409,27410,27411,27412,27413,27414,27415,27416,27417,27418,27419,27420,27421,27422,27423,27424,27425,27426,27427,27428,27429,27430,27431,27432,27433,27434,27435,27436);
DELETE FROM `gameobject` WHERE `map` = 48 AND `guid` IN (32607,32608,32609,32610,32612,32613,32614,32615,32616,32617,32618,32619,32620,32621,32622,32624,32682,32683,32684,32685,32686,32687,32688,32689,32690,32691,32692,32930,32931,32932,32933,32934,32935);
DELETE FROM `gameobject_addon` WHERE `guid` IN (32607,32608,32609,32610,32612,32613,32614,32615,32616,32617,32618,32619,32620,32621,32622,32624,32682,32683,32684,32685,32686,32687,32688,32689,32690,32691,32692,32930,32931,32932,32933,32934,32935);

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+279;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -362.893524169921875, 201.9906463623046875, -64.4219512939453125, 1.237135291099548339, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+1, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -378.805816650390625, 255.4728546142578125, -62.7348175048828125, 5.794627189636230468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+2, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -336.073211669921875, 213.0352783203125, -64.4219512939453125, 3.831389427185058593, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+3, 74408, 48, 719, 719, '1', '0', 0, 0, 1, -156.306610107421875, 74.1594696044921875, -45.4138946533203125, 1.154365301132202148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Je'neu Sancrea (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 149802 - Blackfathom Deeps - Entrance - Wounded (Cosmetic))
(@CGUID+4, 74409, 48, 719, 719, '1', '0', 0, 0, 1, -159.019485473632812, 74.3348846435546875, -45.8225135803222656, 1.223053574562072753, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Zeya (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+5, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -334.34234619140625, 19.16041374206542968, -66.022491455078125, 2.11860823631286621, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+6, 76012, 48, 719, 719, '1', '0', 0, 0, 0, -406.209869384765625, 32.11412429809570312, -47.0883865356445312, 4.899518013000488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Gelihast (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 153277 - Slain Boss Cosmetic (Dead))
(@CGUID+7, 74446, 48, 719, 719, '1', '0', 0, 0, 0, -445.078704833984375, 212.9221954345703125, -52.72796630859375, 5.715243339538574218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Ghamoo-Ra (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+8, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -296.320709228515625, 327.425140380859375, -52.595489501953125, 5.847238540649414062, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+9, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -299.7158203125, 328.80621337890625, -53.0249366760253906, 2.841568470001220703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+10, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -312.18597412109375, 35.03331375122070312, -53.044647216796875, 4.596558570861816406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+11, 53488, 48, 719, 719, '1', '0', 0, 0, 0, -151.66802978515625, 101.1497268676757812, -40.7821464538574218, 4.398229598999023437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Summon Enabler Stalker (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 99201 - Summon Enabler)
(@CGUID+12, 74565, 48, 719, 719, '1', '0', 0, 0, 1, -422.84295654296875, 23.19249916076660156, -48.0814437866210937, 3.484652996063232421, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Subjugator Kor'ul (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+13, 75640, 48, 719, 719, '1', '0', 0, 0, 1, -418.51416015625, 0.401635080575942993, -47.7605056762695312, 1.878163933753967285, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+14, 75641, 48, 719, 719, '1', '0', 0, 0, 1, -407.61163330078125, 12.17301845550537109, -47.899169921875, 2.650274991989135742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Bilefin (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+15, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -297.225128173828125, 330.312408447265625, -52.6800384521484375, 1.318370699882507324, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+16, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -298.997955322265625, 326.461761474609375, -52.9633598327636718, 4.63715362548828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+17, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -346.24249267578125, 118.7966766357421875, -51.641265869140625, 4.280693531036376953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+18, 74721, 48, 719, 719, '1', '0', 0, 0, 1, -323.501373291015625, 127.3168106079101562, -48.1792945861816406, 5.996997833251953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Bilefin (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+19, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -307.409332275390625, 42.94194412231445312, -53.044647216796875, 5.007436275482177734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+20, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -161.6925048828125, 74.5139312744140625, -46.02813720703125, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste, 155184 - Cosmetic (Dead))
(@CGUID+21, 74721, 48, 719, 719, '1', '0', 0, 0, 1, -157.973892211914062, 79.47064208984375, -45.8812828063964843, 4.8320465087890625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Bilefin (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste, 155184 - Cosmetic (Dead))
(@CGUID+22, 53488, 48, 719, 719, '1', '0', 0, 0, 0, -156.813980102539062, 85.10284423828125, -45.0317230224609375, 4.398229598999023437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Summon Enabler Stalker (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 99201 - Summon Enabler)
(@CGUID+23, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -426.666046142578125, 94.72563934326171875, -65.2649993896484375, 4.848681926727294921, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+24, 74724, 48, 719, 719, '1', '0', 0, 0, 0, -308.621124267578125, 122.6066436767578125, -51.2540702819824218, 1.512462258338928222, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+25, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -241.205398559570312, 34.1077423095703125, -55.0508842468261718, 4.63715362548828125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+26, 74351, 48, 719, 719, '1', '0', 0, 0, 1, -298.882476806640625, 334.438934326171875, -52.7527198791503906, 4.9577178955078125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+27, 74476, 48, 719, 719, '1', '0', 0, 0, 1, -309.347412109375, 407.310150146484375, -56.6452369689941406, 3.442847251892089843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Domina (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+28, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -325.1910400390625, 56.26333999633789062, -63.61077880859375, 3.32135009765625, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+29, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -307.539093017578125, 47.39595794677734375, -53.044647216796875, 4.696392536163330078, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+30, 75640, 48, 719, 719, '1', '0', 0, 0, 1, -410.00897216796875, 10.18706798553466796, -47.89044189453125, 2.650274991989135742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+31, 75658, 48, 719, 719, '1', '0', 0, 0, 0, -407.702484130859375, 15.57504463195800781, -48.027191162109375, 2.870365619659423828, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 151037 - Loot Bag)
(@CGUID+32, 75658, 48, 719, 719, '1', '0', 0, 0, 0, -414.67462158203125, 1.584379434585571289, -47.7780532836914062, 2.310780048370361328, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 151037 - Loot Bag)
(@CGUID+33, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -362.60028076171875, 14.51226806640625, -57.708648681640625, 0.868568658828735351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+34, 75658, 48, 719, 719, '1', '0', 0, 0, 0, -415.83477783203125, 38.5419464111328125, -48.3403663635253906, 3.96321725845336914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 151037 - Loot Bag)
(@CGUID+35, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -344.7183837890625, 46.24332427978515625, -62.8837242126464843, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -172.863006591796875, 52.41188430786132812, -48.5900840759277343, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+37, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -310.593719482421875, 45.08187484741210937, -53.044647216796875, 6.15199136734008789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+38, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -308.82281494140625, 34.39423370361328125, -53.044647216796875, 4.574986934661865234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+39, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -361.8194580078125, 207.722991943359375, -62.0634727478027343, 5.123128414154052734, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+40, 74724, 48, 719, 719, '1', '0', 0, 0, 0, -255.856857299804687, 55.30404281616210937, -53.8613853454589843, 3.092231512069702148, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+41, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -239.31378173828125, 34.5016632080078125, -54.7899322509765625, 0.251939833164215087, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+42, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -242.644485473632812, 35.8161773681640625, -55.0324440002441406, 2.395078182220458984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+43, 75658, 48, 719, 719, '1', '0', 0, 0, 0, -405.03955078125, 36.39201736450195312, -48.1829109191894531, 3.843509674072265625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 151037 - Loot Bag)
(@CGUID+44, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -364.115081787109375, 135.9359130859375, -51.9147377014160156, 6.179559707641601562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+45, 75658, 48, 719, 719, '1', '0', 0, 0, 0, -402.25384521484375, 27.14090919494628906, -48.2934036254882812, 3.266278028488159179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 151037 - Loot Bag)
(@CGUID+46, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -336.019866943359375, -7.39408206939697265, -69.6404190063476562, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -240.429031372070312, 35.9981231689453125, -54.8194465637207031, 1.318370699882507324, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+48, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -327.91448974609375, 50.73933792114257812, -61.9822349548339843, 0.215691655874252319, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+49, 77232, 48, 719, 719, '1', '0', 0, 0, 1, -185.732742309570312, 53.34617996215820312, -50.6757583618164062, 0.567436516284942626, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+50, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -188.913787841796875, 59.4115142822265625, -50.5849418640136718, 3.487350940704345703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 150392 - Haste)
(@CGUID+51, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -324.623260498046875, 210.5860443115234375, -62.0634727478027343, 0, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+52, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -306.374298095703125, 347.180450439453125, -53.4090614318847656, 4.762895107269287109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+53, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -361.122711181640625, 140.161285400390625, -51.0590286254882812, 5.715023517608642578, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+54, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -316.955780029296875, 41.59795379638671875, -61.9822349548339843, 3.715565681457519531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+55, 75428, 48, 719, 719, '1', '0', 0, 0, 0, -411.959747314453125, 232.8452911376953125, -53.964996337890625, 4.30257415771484375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+56, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -352.583648681640625, 209.1075286865234375, -64.4219512939453125, 4.0742340087890625, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+57, 74380, 48, 719, 719, '1', '0', 0, 0, 1, -364.365325927734375, 139.3770599365234375, -51.2777786254882812, 5.84686136245727539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Storm Mender (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+58, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -361.210357666015625, 219.7187042236328125, -64.4219512939453125, 4.490645408630371093, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+59, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -339.36981201171875, -19.2861270904541015, -66.022491455078125, 0.760089278221130371, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+60, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -439.196136474609375, 121.0803451538085937, -64.329833984375, 3.781057119369506835, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+61, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -327.4605712890625, 29.56825065612792968, -61.9822349548339843, 1.237135291099548339, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+62, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -393.996734619140625, 268.309051513671875, -67.2861862182617187, 0.086942501366138458, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+63, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -444.978302001953125, 140.4239959716796875, -64.3254165649414062, 2.719669103622436523, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+64, 74983, 48, 719, 719, '1', '0', 0, 0, 1, -238.210311889648437, 29.87101173400878906, -54.6128501892089843, 2.006029844284057617, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+65, 75642, 48, 719, 719, '1', '0', 0, 0, 1, -424.434295654296875, 39.60182571411132812, -48.1996917724609375, 4.412259578704833984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Bilefin (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+66, 75643, 48, 719, 719, '1', '0', 0, 0, 1, -422.855926513671875, 38.12192916870117187, -48.2106857299804687, 4.828416824340820312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+67, 74722, 48, 719, 719, '1', '0', 0, 0, 0, -419.73193359375, 202.7319183349609375, -53.2462158203125, 4.151823043823242187, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Razorshell Snapjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+68, 75000, 48, 719, 719, '1', '0', 0, 0, 0, -290.285888671875, 80.22994232177734375, -52.2628250122070312, 5.175164699554443359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150866 - Coiled Rope Usable)
(@CGUID+69, 74988, 48, 719, 719, '1', '0', 0, 0, 1, -306.592559814453125, 38.09068679809570312, -53.044647216796875, 5.674635887145996093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Executioner Gore (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+70, 74721, 48, 719, 719, '1', '0', 0, 0, 1, -348.314483642578125, 115.9613723754882812, -51.8964920043945312, 0.612991511821746826, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Bilefin (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+71, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -306.4000244140625, 45.58740997314453125, -53.044647216796875, 4.553805351257324218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+72, 74980, 48, 719, 719, '1', '0', 0, 0, 1, -241.462158203125, 31.25501251220703125, -55.1041679382324218, 1.361505985260009765, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Storm Mender (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+73, 74984, 48, 719, 719, '1', '0', 0, 0, 1, -236.47320556640625, 37.0731353759765625, -54.2100715637207031, 3.450027227401733398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+74, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -310.644866943359375, 48.44895172119140625, -53.044647216796875, 5.725784778594970703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+75, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -364.431304931640625, 16.56702613830566406, -57.7898979187011718, 0.332549452781677246, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+76, 74998, 48, 719, 719, '1', '0', 0, 0, 0, -271.511871337890625, 70.069976806640625, -58.00103759765625, 5.360785484313964843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+77, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -307.91064453125, 49.22522354125976562, -53.044647216796875, 4.655097007751464843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+78, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -297.409576416015625, 49.46392059326171875, -63.619171142578125, 3.584503173828125, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+79, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -302.855072021484375, 329.396392822265625, -53.4331207275390625, 5.83130645751953125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+80, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -316.5643310546875, 14.51888370513916015, -64.5364456176757812, 5.471619129180908203, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+81, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -307.65069580078125, -12.5444297790527343, -68.9764328002929687, 4.590591907501220703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+82, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -305.733795166015625, 35.33832168579101562, -53.044647216796875, 4.596558570861816406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+83, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -414.797332763671875, 232.7751007080078125, -53.8871726989746093, 2.217177391052246093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+84, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -408.851531982421875, 231.5624542236328125, -54.3552894592285156, 0.445493698120117187, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+85, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -342.998443603515625, 116.4975967407226562, -51.2050247192382812, 3.222946405410766601, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+86, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -459.392120361328125, 117.4138107299804687, -69.4201812744140625, 0.196927875280380249, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+87, 74722, 48, 719, 719, '1', '0', 0, 0, 0, -442.914154052734375, 185.887054443359375, -53.1356849670410156, 3.992783069610595703, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Razorshell Snapjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+88, 74722, 48, 719, 719, '1', '0', 0, 0, 0, -425.98541259765625, 226.5516510009765625, -53.1109809875488281, 3.717952966690063476, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Razorshell Snapjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+89, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -470.861328125, 119.7384872436523437, -70.5599365234375, 1.067281961441040039, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+90, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -466.95831298828125, 144.2032928466796875, -63.8463897705078125, 1.013248682022094726, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+91, 75012, 48, 719, 719, '1', '0', 0, 0, 1, -443.742767333984375, 208.4198760986328125, -52.5463294982910156, 2.122891426086425781, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 152733 - Kill Cultists Transform)
(@CGUID+92, 75011, 48, 719, 719, '1', '0', 0, 0, 1, -440.434234619140625, 215.3530731201171875, -52.7060661315917968, 4.022166252136230468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Storm Mender (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 152738 - Kill Cultists Transform)
(@CGUID+93, 75012, 48, 719, 719, '1', '0', 0, 0, 1, -448.578277587890625, 208.9145965576171875, -52.65692138671875, 1.026227831840515136, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 152733 - Kill Cultists Transform)
(@CGUID+94, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -476.38470458984375, 134.942138671875, -67.9940032958984375, 0.970989346504211425, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+95, 74719, 48, 719, 719, '1', '0', 0, 0, 0, -513.39727783203125, 19.94854164123535156, -45.2733917236328125, 2.999884843826293945, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Rotmouth (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+96, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -510.40521240234375, -5.31408357620239257, -44.8541679382324218, 2.649854898452758789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+97, 74721, 48, 719, 719, '1', '0', 0, 0, 1, -510.189666748046875, -2.50005698204040527, -44.9340286254882812, 3.062057971954345703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Bilefin (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+98, 75060, 48, 719, 719, '1', '0', 0, 0, 0, -514.10205078125, -3.72472381591796875, -44.3570365905761718, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Slain Hero (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 151020 - Slain Hero Cosmetic (Dead))
(@CGUID+99, 74724, 48, 719, 719, '1', '0', 0, 0, 0, -507.260955810546875, -34.1849174499511718, -43.4977340698242187, 3.147732496261596679, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+100, 75658, 48, 719, 719, '1', '0', 0, 0, 0, -512.60198974609375, -7.23037290573120117, -44.3368072509765625, 1.941253185272216796, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 151037 - Loot Bag)
(@CGUID+101, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -401.801239013671875, 277.434478759765625, -69.1136703491210937, 5.436603546142578125, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+102, 76954, 48, 719, 719, '1', '0', 0, 0, 0, -470.226715087890625, 222.037872314453125, -53.2680015563964843, 0.134128510951995849, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Pahboo-Ra (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+103, 74363, 48, 719, 719, '1', '0', 0, 0, 1, -532.98663330078125, -39.0224342346191406, -39.3506965637207031, 6.205827713012695312, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Shadow (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150473 - Sneak)
(@CGUID+104, 74363, 48, 719, 719, '1', '0', 0, 0, 1, -532.05438232421875, -47.7318801879882812, -39.5135536193847656, 0.282784551382064819, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Shadow (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150473 - Sneak)
(@CGUID+105, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -504.97802734375, 195.9175872802734375, -62.5237503051757812, 6.110137939453125, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+106, 75111, 48, 719, 719, '1', '0', 0, 0, 0, -554.29345703125, -3.01120686531066894, -43.8793563842773437, 0.972408533096313476, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+107, 75111, 48, 719, 719, '1', '0', 0, 0, 0, -558.8951416015625, -46.7119941711425781, -37.4464111328125, 1.613408446311950683, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+108, 74719, 48, 719, 719, '1', '0', 0, 0, 0, -564.41778564453125, -8.38104057312011718, -44.4618072509765625, 1.659912109375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Rotmouth (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+109, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -404.6195068359375, 288.598785400390625, -67.23583984375, 2.324868202209472656, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+110, 74724, 48, 719, 719, '1', '0', 0, 0, 0, -573.15557861328125, 7.658147811889648437, -48.2205963134765625, 1.259212493896484375, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+111, 74353, 48, 719, 719, '1', '0', 0, 0, 1, -575.4885, 8.287675, -48.601162, 2.243846654891967773, 7200, 0, 0, 2, NULL, NULL, NULL, NULL, 59679), -- Twilight Aquamancer (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+112, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -591.8138427734375, -31.9458217620849609, -28.8194446563720703, 5.611269950866699218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+113, 74988, 48, 719, 719, '1', '0', 0, 0, 1, -572.7994384765625, -47.375152587890625, -34.726165771484375, 0.166449159383773803, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Executioner Gore (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+114, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -569.0533447265625, -44.4950485229492187, -35.6246223449707031, 2.110424757003784179, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+115, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -571.13153076171875, -40.2963676452636718, -35.1822929382324218, 2.04636383056640625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+116, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -577.07635498046875, -38.5098152160644531, -33.9600715637207031, 3.524544000625610351, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+117, 74721, 48, 719, 719, '1', '0', 0, 0, 1, -588.796875, 47.23926544189453125, -51.6464042663574218, 3.736182212829589843, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Bilefin (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+118, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -568.90789794921875, -41.2823905944824218, -35.6788215637207031, 3.776009321212768554, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+119, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -592.76348876953125, 47.18840408325195312, -52.054779052734375, 6.213494777679443359, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+120, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -574.26531982421875, -39.8338432312011718, -34.6215286254882812, 2.395078182220458984, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+121, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -591.1259765625, 43.42393875122070312, -51.6958808898925781, 1.074402213096618652, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+122, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -578.90545654296875, -42.0233535766601562, -33.48455810546875, 0.706499874591827392, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+123, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -506.508636474609375, 233.7052154541015625, -62.6974639892578125, 5.186086177825927734, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+124, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -534.4970703125, 210.291900634765625, -62.7648773193359375, 2.754434108734130859, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+125, 74380, 48, 719, 719, '1', '0', 0, 0, 1, -596.57574462890625, -38.90814208984375, -28.9670143127441406, 6.095958709716796875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Storm Mender (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+126, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -594.2864990234375, -44.0248603820800781, -29.3454856872558593, 0.121289946138858795, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+127, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -429.131805419921875, 293.08489990234375, -67.1452178955078125, 0.339810937643051147, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+128, 74721, 48, 719, 719, '1', '0', 0, 0, 1, -613.12091064453125, 45.96378707885742187, -55.3730545043945312, 1.80102396011352539, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Bilefin (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+129, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -492.348175048828125, 263.3394775390625, -63.0942878723144531, 1.457226991653442382, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+130, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -617.08837890625, 44.90999603271484375, -55.548614501953125, 1.926034808158874511, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+131, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -465.174530029296875, 284.12408447265625, -63.232025146484375, 4.381064414978027343, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+132, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -535.70013427734375, 230.149261474609375, -62.6443634033203125, 2.176969528198242187, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+133, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -479.31146240234375, 275.234771728515625, -61.5154151916503906, 1.099937081336975097, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+134, 74724, 48, 719, 719, '1', '0', 0, 0, 0, -552.62701416015625, 217.2411041259765625, -58.7537384033203125, 1.34308028221130371, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+135, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -624.94195556640625, -20.7682266235351562, -21.6533641815185546, 5.9411468505859375, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+136, 74724, 48, 719, 719, '1', '0', 0, 0, 0, -625.11834716796875, 74.1041717529296875, -55.6942520141601562, 5.179334163665771484, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+137, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -626.89404296875, -29.8580703735351562, -20.0868053436279296, 5.935100555419921875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+138, 75111, 48, 719, 719, '1', '0', 0, 0, 0, -631.7322998046875, 80.1556396484375, -56.18927001953125, 0.193229377269744873, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+139, 74353, 48, 719, 719, '1', '0', 0, 0, 1, -628.88665771484375, -26.0561122894287109, -18.918680191040039, 5.995213508605957031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Aquamancer (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+140, 74724, 48, 719, 719, '1', '0', 0, 0, 0, -626.94000244140625, 103.5268402099609375, -57.0031394958496093, 0.211502566933631896, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+141, 75980, 48, 719, 719, '1', '0', 0, 0, 0, -548.4141845703125, 230.15911865234375, -59.2654685974121093, 2.509562492370605468, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blindlight Razorjaw (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+142, 74505, 48, 719, 719, '1', '0', 0, 0, 2, -746.05169677734375, 7.979850292205810546, -30.035247802734375, 5.526535511016845703, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Thruk (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150189 - Fishing Pole, 151865 - Fishing Line) (possible waypoints or random movement)
(@CGUID+143, 74724, 48, 719, 719, '1', '0', 0, 0, 0, -557.874755859375, 232.235107421875, -59.2945556640625, 5.449379920959472656, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+144, 74363, 48, 719, 719, '1', '0', 0, 0, 1, -653.78900146484375, -10.256178855895996, -17.8628463745117187, 5.571061134338378906, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Shadow (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150473 - Sneak)
(@CGUID+145, 74721, 48, 719, 719, '1', '0', 0, 0, 1, -607.7921142578125, 183.582794189453125, -53.9785652160644531, 6.158524990081787109, 7200, 0, 0, 2, NULL, NULL, NULL, NULL, 59679), -- Blindlight Bilefin (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste) (possible waypoints or random movement)
(@CGUID+146, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -630.95098876953125, 144.7661895751953125, -58.1286697387695312, 1.780869841575622558, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+147, 75058, 48, 719, 719, '1', '0', 0, 0, 1, -634.984619140625, 139.71124267578125, -58.0989608764648437, 1.478237032890319824, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Aquamancer (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+148, 74724, 48, 719, 719, '1', '0', 0, 0, 0, -660.16888427734375, -8.19596385955810546, -19.3639163970947265, 3.420006990432739257, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+149, 74363, 48, 719, 719, '1', '0', 0, 0, 1, -657.7467041015625, -17.181375503540039, -17.8285179138183593, 6.066316604614257812, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Shadow (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150473 - Sneak)
(@CGUID+150, 74724, 48, 719, 719, '1', '0', 0, 0, 0, -613.89385986328125, 197.5966949462890625, -51.6343841552734375, 3.996978998184204101, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+151, 75285, 48, 719, 719, '1', '0', 0, 0, 1, -641.74346923828125, 145.59283447265625, -57.8680572509765625, 1.239103913307189941, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Storm Mender (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+152, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -626.9046630859375, 173.0816192626953125, -55.094696044921875, 1.725853562355041503, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+153, 74724, 48, 719, 719, '1', '0', 0, 0, 0, -596.4610595703125, 216.090057373046875, -50.7688941955566406, 2.967580080032348632, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+154, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -624.87261962890625, 173.261993408203125, -55.0925445556640625, 2.245894908905029296, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+155, 74720, 48, 719, 719, '1', '0', 0, 0, 1, -599.0008544921875, 233.3719940185546875, -50.8784751892089843, 1.560807347297668457, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Murloc (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+156, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -343.25531005859375, 366.882568359375, -54.3055572509765625, 1.146162748336791992, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+157, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -347.169830322265625, 370.191619873046875, -54.4715805053710937, 1.080088615417480468, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+158, 74997, 48, 719, 719, '1', '0', 0, 0, 0, -289.306182861328125, 82.3385009765625, -52.1100959777832031, 5.113622188568115234, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2
(@CGUID+159, 74721, 48, 719, 719, '1', '0', 0, 0, 1, -601.35107421875, 234.9850311279296875, -50.969329833984375, 0.643592298030853271, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Blindlight Bilefin (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150392 - Haste)
(@CGUID+160, 74353, 48, 719, 719, '1', '0', 0, 0, 1, -617.87603759765625, 219.363037109375, -51.5950546264648437, 0.884397447109222412, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Aquamancer (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+161, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -337.993988037109375, 380.1676025390625, -54.0563468933105468, 0.876892626285552978, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+162, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -328.458404541015625, 389.003814697265625, -53.9305572509765625, 1.271044731140136718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+163, 74380, 48, 719, 719, '1', '0', 0, 0, 1, -331.58404541015625, 390.845855712890625, -54.25, 1.000799894332885742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Storm Mender (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+164, 75039, 48, 719, 719, '1', '0', 0, 0, 0, -319.06976318359375, 406.088653564453125, -48.9191780090332031, 3.626267671585083007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150919 - Dark Sacrifice Hover)
(@CGUID+165, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -338.968170166015625, 404.38568115234375, -54.3458251953125, 0.101379618048667907, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+166, 75046, 48, 719, 719, '1', '0', 0, 0, 0, -320.25439453125, 405.58074951171875, -56.361114501953125, 0.367158293724060058, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 28819 - Submerge Visual)
(@CGUID+167, 75042, 48, 719, 719, '1', '0', 0, 0, 0, -319.487548828125, 405.832061767578125, -56.463531494140625, 3.67789459228515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150922 - Dark Sacrifice Hover)
(@CGUID+168, 75046, 48, 719, 719, '1', '0', 0, 0, 0, -317.934967041015625, 405.28814697265625, -56.4543533325195312, 2.659367561340332031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 28819 - Submerge Visual)
(@CGUID+169, 75046, 48, 719, 719, '1', '0', 0, 0, 0, -318.645477294921875, 407.54949951171875, -56.609375, 4.35746622085571289, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 28819 - Submerge Visual)
(@CGUID+170, 75034, 48, 719, 719, '1', '0', 0, 0, 0, -317.213043212890625, 401.9620361328125, -55.4566001892089843, 2.545964956283569335, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Tormentor (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+171, 76005, 48, 719, 719, '1', '0', 0, 0, 0, -301.872222900390625, 412.18670654296875, -55.6409873962402343, 4.899518013000488281, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Lady Sarevess (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153277 - Slain Boss Cosmetic (Dead))
(@CGUID+172, 75034, 48, 719, 719, '1', '0', 0, 0, 0, -322.13800048828125, 410.004119873046875, -56.3266143798828125, 4.914469242095947265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Tormentor (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+173, 74724, 48, 719, 719, '1', '0', 0, 0, 0, -687.208984375, 25.93608665466308593, -30.8569488525390625, 3.092301607131958007, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+174, 74518, 48, 719, 719, '1', '0', 0, 0, 1, -771.57318115234375, -57.6800193786621093, -29.8483715057373046, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Executioner Gore (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+175, 75307, 48, 719, 719, '1', '0', 0, 0, 0, -301.5260009765625, 412.828704833984375, -57.6359329223632812, 0.32110905647277832, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 151538 - Altar of Blood (Cosmetic))
(@CGUID+176, 75410, 48, 719, 719, '1', '0', 0, 0, 0, -738.81768798828125, -0.25742864608764648, -30.1017169952392578, 1.455712318420410156, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian of the Deep (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+177, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -739.409423828125, -19.1915435791015625, -36.0884284973144531, 0.400786161422729492, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+178, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -696.84857177734375, -29.5365562438964843, -29.9499645233154296, 3.085198640823364257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+179, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -736.34527587890625, -18.4382877349853515, -38.8698348999023437, 0.892154693603515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+180, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -695.279296875, -27.5098514556884765, -29.9499645233154296, 3.085198640823364257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+181, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -692.6990966796875, -31.1909751892089843, -29.9499645233154296, 3.085198640823364257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+182, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -734.70794677734375, -17.4603309631347656, -39.1249885559082031, 5.279833316802978515, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+183, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -744.9705810546875, -16.8998603820800781, -36.70220947265625, 0.176671981811523437, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+184, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -745.28326416015625, -15.0525884628295898, -36.3584480285644531, 5.051862716674804687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+185, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -736.65374755859375, -20.9645023345947265, -39.285858154296875, 1.741476655006408691, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+186, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -722.47491455078125, -56.0345115661621093, -37.6502838134765625, 3.119971990585327148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+187, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -719.76934814453125, -59.62371826171875, -37.6502838134765625, 3.119971990585327148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+188, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -723.9736328125, -58.1146583557128906, -37.6502838134765625, 3.119971990585327148, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+189, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -771.2857666015625, -38.6581382751464843, -37.9787178039550781, 0.010766866616904735, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+190, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -745.31048583984375, -54.9962043762207031, -29.9499645233154296, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+191, 74508, 48, 719, 719, '1', '0', 0, 0, 0, -744.34722900390625, -164.816848754882812, -50.8457260131835937, 2.687306404113769531, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian of the Deep (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 152647 - Hungry)
(@CGUID+192, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -745.52191162109375, -61.1358642578125, -29.9499645233154296, 0, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+193, 74382, 48, 719, 719, '1', '0', 0, 0, 1, -750.587890625, -58.9046211242675781, -29.878204345703125, 0.076723538339138031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Shadowmage (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+194, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -767.88836669921875, -55.1537590026855468, -40.7425537109375, 1.939994215965270996, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+195, 74728, 48, 719, 719, '1', '0', 0, 0, 0, -818.787109375, -150.082473754882812, -25.8002796173095703, 1.598916053771972656, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Lord Bathiel (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+196, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -793.42816162109375, -55.1015357971191406, -39.1168098449707031, 3.817116737365722656, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+197, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -722.36151123046875, -104.123863220214843, -29.9618053436279296, 1.557994008064270019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+198, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -720.26800537109375, -105.603378295898437, -30.0017356872558593, 1.557994008064270019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+199, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -751.64947509765625, -92.242462158203125, -37.8968162536621093, 2.476971864700317382, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+200, 74989, 48, 719, 719, '1', '0', 0, 0, 1, -723.83343505859375, -108.341506958007812, -29.953125, 1.557994008064270019, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+201, 74747, 48, 719, 719, '1', '0', 0, 0, 0, -636.42803955078125, 130.76666259765625, -58.0208358764648437, 1.638848543167114257, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 151052 - Goo Splash)
(@CGUID+202, 74353, 48, 719, 719, '1', '0', 0, 0, 1, -816.98553466796875, -73.3121566772460937, -29.6315345764160156, 1.539357662200927734, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Aquamancer (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+203, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -773.4150390625, -97.9873275756835937, -36.6248664855957031, 5.943145751953125, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+204, 75286, 48, 719, 719, '1', '0', 0, 0, 1, -815.27294921875, -68.232208251953125, -29.6130027770996093, 1.561633467674255371, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Disciple (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+205, 75285, 48, 719, 719, '1', '0', 0, 0, 1, -821.58184814453125, -68.4577865600585937, -29.606973648071289, 1.58161783218383789, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Storm Mender (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+206, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -803.512939453125, -105.904518127441406, -38.5738334655761718, 6.18756723403930664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+207, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -799.0118408203125, -108.50982666015625, -38.077972412109375, 1.210399746894836425, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+208, 75086, 48, 719, 719, '1', '0', 0, 0, 0, -618.61419677734375, 84.1883087158203125, -52.0396766662597656, 3.415910959243774414, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+209, 75522, 48, 719, 719, '1', '0', 0, 0, 0, -804.06878662109375, -113.219291687011718, -35.1666755676269531, 0.810405611991882324, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Bloodtail Grouper (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+210, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -732.322265625, -159.652542114257812, -57.9863014221191406, 0.220640227198600769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+211, 74509, 48, 719, 719, '1', '0', 0, 0, 0, -756.14752197265625, -159.201339721679687, -49.6792984008789062, 3.76980757713317871, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+212, 74509, 48, 719, 719, '1', '0', 0, 0, 0, -736.86773681640625, -172.445083618164062, -56.6519775390625, 1.154121279716491699, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+213, 76037, 48, 719, 719, '1', '0', 0, 0, 1, -832.73114013671875, -123.018943786621093, -25.7867259979248046, 1.5426408052444458, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Storm Mender (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+214, 76038, 48, 719, 719, '1', '0', 0, 0, 1, -817.0291748046875, -136.194122314453125, -25.786722183227539, 1.124861717224121093, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Shadowmage (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+215, 76036, 48, 719, 719, '1', '0', 0, 0, 1, -813.7713623046875, -133.203155517578125, -25.786722183227539, 1.212851524353027343, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Shadow (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150473 - Sneak)
(@CGUID+216, 76037, 48, 719, 719, '1', '0', 0, 0, 1, -799.483642578125, -122.284736633300781, -25.7867259979248046, 1.648723125457763671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Storm Mender (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+217, 76039, 48, 719, 719, '1', '0', 0, 0, 1, -802.4329833984375, -125.887336730957031, -25.7867240905761718, 1.572515130043029785, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Aquamancer (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+218, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -739.3345947265625, -177.522079467773437, -58.625, 3.867975234985351562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+219, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -742.06170654296875, -177.7271728515625, -58.6950225830078125, 3.867975234985351562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+220, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -729.78387451171875, -176.176223754882812, -58.5416679382324218, 4.302101612091064453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+221, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -731.33099365234375, -161.366226196289062, -58.4036827087402343, 0.220640227198600769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+222, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -729.837158203125, -160.794143676757812, -58.35211181640625, 0.220640227198600769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+223, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -793.77960205078125, -139.31182861328125, -38.3793296813964843, 6.18756723403930664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+224, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -732.171875, -177.509307861328125, -58.8350791931152343, 4.302101612091064453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+225, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -743.331298828125, -175.239349365234375, -58.4375, 4.910392284393310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+226, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -741.03204345703125, -176.503158569335937, -58.7301368713378906, 3.867975234985351562, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+227, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -745.066650390625, -176.191848754882812, -57.9809036254882812, 4.910392284393310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+228, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -744.528564453125, -177.697784423828125, -58.0381965637207031, 4.910392284393310546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+229, 74509, 48, 719, 719, '1', '0', 0, 0, 0, -752.98028564453125, -172.451980590820312, -53.4346199035644531, 3.863995552062988281, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+230, 74509, 48, 719, 719, '1', '0', 0, 0, 0, -739.44549560546875, -154.510009765625, -55.377655029296875, 1.962864279747009277, 7200, 10, 0, 1, NULL, NULL, NULL, NULL, 59679), -- Blue Shale Crawler (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+231, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -731.75274658203125, -175.965896606445312, -58.8806571960449218, 4.302101612091064453, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+232, 76036, 48, 719, 719, '1', '0', 0, 0, 1, -822.68536376953125, -133.132843017578125, -25.7867259979248046, 2.433938503265380859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Shadow (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 150473 - Sneak)
(@CGUID+233, 76039, 48, 719, 719, '1', '0', 0, 0, 1, -835.960205078125, -126.380043029785156, -25.7867240905761718, 1.418999314308166503, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Twilight Aquamancer (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+234, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -814.12823486328125, -147.250381469726562, -25.79046630859375, 0.342690229415893554, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 146587 - Kor'kron Cosmetic (Dead))
(@CGUID+235, 76062, 48, 719, 719, '1', '0', 0, 0, 0, -775.461181640625, -164.137969970703125, -48.7102432250976562, 0.220640227198600769, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Guardian Eggs (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 153429 - Guardian Eggs Sparkles)
(@CGUID+236, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -811.66290283203125, -150.903350830078125, -25.826852798461914, 4.237649440765380859, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 146587 - Kor'kron Cosmetic (Dead))
(@CGUID+237, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -817.8804931640625, -145.365371704101562, -25.7867240905761718, 4.113965988159179687, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 146587 - Kor'kron Cosmetic (Dead))
(@CGUID+238, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -823.96856689453125, -146.522140502929687, -25.7867259979248046, 4.494629859924316406, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 146587 - Kor'kron Cosmetic (Dead))
(@CGUID+239, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -815.64227294921875, -153.888015747070312, -25.8123950958251953, 1.416080474853515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 146587 - Kor'kron Cosmetic (Dead))
(@CGUID+240, 75575, 48, 719, 719, '1', '0', 0, 0, 0, -818.32879638671875, -155.0548095703125, -25.7976341247558593, 1.491251468658447265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 152140 - Fire of Aku'mai Visual)
(@CGUID+241, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -822.38262939453125, -150.102005004882812, -25.8185253143310546, 5.451554775238037109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 146587 - Kor'kron Cosmetic (Dead))
(@CGUID+242, 75158, 48, 719, 719, '1', '0', 0, 0, 0, -818.32879638671875, -155.0548095703125, -24.7005138397216796, 1.491251468658447265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Aku'mai (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 152142 - Vision of Aku'mai Cosmetic, 28819 - Submerge Visual)
(@CGUID+243, 75550, 48, 719, 719, '1', '0', 0, 0, 0, -816.89453125, -157.739715576171875, -21.6979503631591796, 1.293437719345092773, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Domina (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 152137 - Optional Boss Killed Cosmetic)
(@CGUID+244, 74979, 48, 719, 719, '1', '0', 0, 0, 0, -825.27337646484375, -153.155197143554687, -25.8208351135253906, 2.204619646072387695, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Frightened Prisoner (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 146587 - Kor'kron Cosmetic (Dead))
(@CGUID+245, 75307, 48, 719, 719, '1', '0', 0, 0, 0, -818.38116455078125, -158.877197265625, -24.4357738494873046, 1.493116736412048339, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 151538 - Altar of Blood (Cosmetic))
(@CGUID+246, 85844, 48, 719, 719, '1', '0', 0, 0, 0, -819.1397705078125, -162.320510864257812, -10.7417640686035156, 1.455818057060241699, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- The Old Gods (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+247, 75086, 48, 719, 719, '1', '0', 0, 0, 0, -543.734619140625, 12.83865547180175781, -39.609405517578125, 4.353049755096435546, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+248, 75463, 48, 719, 719, '1', '0', 0, 0, 0, -435.955718994140625, 9.546426773071289062, -48.01751708984375, 0.784189105033874511, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 151052 - Goo Splash)
(@CGUID+249, 75463, 48, 719, 719, '1', '0', 0, 0, 0, -413.382965087890625, 15.67938232421875, -48.1399688720703125, 5.947166919708251953, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 151052 - Goo Splash)
(@CGUID+250, 75463, 48, 719, 719, '1', '0', 0, 0, 0, -440.31072998046875, 32.77234268188476562, -48.0991172790527343, 5.724055767059326171, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 151052 - Goo Splash)
(@CGUID+251, 75463, 48, 719, 719, '1', '0', 0, 0, 0, -424.703521728515625, 31.49000358581542968, -48.0690803527832031, 1.455721139907836914, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 151052 - Goo Splash)
(@CGUID+252, 75463, 48, 719, 719, '1', '0', 0, 0, 0, -420.430511474609375, 9.022070884704589843, -48.0104293823242187, 5.275362968444824218, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 151052 - Goo Splash)
(@CGUID+253, 75307, 48, 719, 719, '1', '0', 0, 0, 0, -405.92974853515625, 30.99733161926269531, -48.485076904296875, 0.23454885184764862, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 151538 - Altar of Blood (Cosmetic))
(@CGUID+254, 75086, 48, 719, 719, '1', '0', 0, 0, 0, -559.14630126953125, -34.8030204772949218, -33.0530128479003906, 4.694627285003662109, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+255, 75553, 48, 719, 719, '1', '0', 0, 0, 0, -820.5897216796875, -157.739715576171875, -21.9454803466796875, 1.961440443992614746, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Subjugator Kor'ul (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: 152137 - Optional Boss Killed Cosmetic)
(@CGUID+256, 75923, 48, 719, 719, '1', '0', 0, 0, 0, -809.54376220703125, -231.113800048828125, -25.7875289916992187, 2.90024423599243164, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+257, 75923, 48, 719, 719, '1', '0', 0, 0, 0, -810.20538330078125, -242.037918090820312, -25.7860774993896484, 2.853678226470947265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+258, 75111, 48, 719, 719, '1', '0', 0, 0, 0, -824.010986328125, -234.082733154296875, -25.7927093505859375, 3.20606088638305664, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+259, 75923, 48, 719, 719, '1', '0', 0, 0, 0, -827.4666748046875, -241.830245971679687, -25.7896938323974609, 1.496241688728332519, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+260, 75111, 48, 719, 719, '1', '0', 0, 0, 0, -837.22344970703125, -252.982254028320312, -26.281656265258789, 5.3690185546875, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+261, 75923, 48, 719, 719, '1', '0', 0, 0, 0, -842.24853515625, -281.566192626953125, -26.7181148529052734, 1.496241688728332519, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+262, 75923, 48, 719, 719, '1', '0', 0, 0, 0, -858.03570556640625, -288.5264892578125, -26.131204605102539, 0.320683479309082031, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+263, 75923, 48, 719, 719, '1', '0', 0, 0, 0, -849.53692626953125, -303.55255126953125, -28.9682807922363281, 2.283484220504760742, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+264, 75111, 48, 719, 719, '1', '0', 0, 0, 0, -840.0703125, -316.447296142578125, -33.1014175415039062, 3.089374542236328125, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@CGUID+265, 75408, 48, 719, 719, '1', '0', 0, 0, 0, -848.5025634765625, -461.454010009765625, -33.9294471740722656, 1.463392615318298339, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Aku'mai (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+266, 75147, 48, 719, 719, '1', '0', 0, 0, 0, -818.32879638671875, -155.0548095703125, -25.7976341247558593, 1.491251468658447265, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Invisible Man (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 150866 - Coiled Rope Usable)
(@CGUID+267, 75086, 48, 719, 719, '1', '0', 0, 0, 0, -839.31951904296875, -236.412460327148437, -21.3239612579345703, 0.205486312508583068, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+268, 75086, 48, 719, 719, '1', '0', 0, 0, 0, -827.10284423828125, -263.51092529296875, -21.7629299163818359, 2.368447065353393554, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+269, 75086, 48, 719, 719, '1', '0', 0, 0, 0, -854.1376953125, -317.144561767578125, -26.5094890594482421, 0.088799379765987396, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+270, 74747, 48, 719, 719, '1', '0', 0, 0, 0, -841.12042236328125, -350.33868408203125, -33.865447998046875, 1.745183825492858886, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 151052 - Goo Splash)
(@CGUID+271, 74747, 48, 719, 719, '1', '0', 0, 0, 0, -825.9095458984375, -404.826507568359375, -33.869049072265625, 2.43473052978515625, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 151052 - Goo Splash)
(@CGUID+272, 75780, 48, 719, 719, '1', '0', 0, 0, 0, -879.1405029296875, -480.99365234375, -19.8541622161865234, 0.809473156929016113, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+273, 75155, 48, 719, 719, '1', '0', 0, 0, 0, -848.62957763671875, -462.16949462890625, -33.9322052001953125, 1.381942510604858398, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Aku'mai the Devourer (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 152693 - Goo Splash)
(@CGUID+274, 75780, 48, 719, 719, '1', '0', 0, 0, 0, -818.18426513671875, -424.615631103515625, -20.3383426666259765, 2.268755912780761718, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: )
(@CGUID+275, 74747, 48, 719, 719, '1', '0', 0, 0, 0, -848.29156494140625, -408.662139892578125, -34.1396102905273437, 0.627464175224304199, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Deep Terror (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2 (Auras: 151052 - Goo Splash)
(@CGUID+276, 74409, 48, 719, 719, '1', '0', 0, 0, 1, -847.1019287109375, -473.0684814453125, -33.993499755859375, 1.213205695152282714, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 59679), -- Zeya (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2
(@CGUID+277, 75606, 48, 719, 719, '1', '0', 0, 0, 0, -158.814117431640625, 74.34395599365234375, -45.7991371154785156, 1.302562236785888671, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Sentinel Aluwyn (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@CGUID+278, 75607, 48, 719, 719, '1', '0', 0, 0, 0, -156.684402465820312, 74.6537628173828125, -45.4810638427734375, 1.636918306350708007, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60257), -- Ashelan Northwood (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1 (Auras: 149802 - Blackfathom Deeps - Entrance - Wounded (Cosmetic))
(@CGUID+279, 75606, 48, 719, 719, '1', '0', 0, 0, 0, -847.1019287109375, -473.0684814453125, -33.993499755859375, 1.213205695152282714, 7200, 0, 0, 0, NULL, NULL, NULL, NULL, 60257);

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+279;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+3, 0, 0, 0, 0, 0, 1, 1, 64, 0, 0, 0, 0, '149802'), -- Je'neu Sancrea - 149802 - Blackfathom Deeps - Entrance - Wounded (Cosmetic)
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 433, 0, 0, 0, 0, ''), -- Zeya
(@CGUID+8, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+20, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '150392 155184'), -- Blindlight Murloc - 150392 - Haste, 155184 - Cosmetic (Dead)
(@CGUID+21, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, '150392 155184'), -- Blindlight Bilefin - 150392 - Haste, 155184 - Cosmetic (Dead)
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+31, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '151037'), -- Blindlight Murloc - 151037 - Loot Bag
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '151037'), -- Blindlight Murloc - 151037 - Loot Bag
(@CGUID+37, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+43, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, '151037'), -- Blindlight Murloc - 151037 - Loot Bag
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+49, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+52, 0, 0, 0, 0, 0, 1, 0, 474, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+53, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+55, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+57, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Storm Mender
(@CGUID+64, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+74, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+79, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+95, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 0, ''), -- Blindlight Rotmouth
(@CGUID+112, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+114, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+115, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+116, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+118, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+120, 0, 0, 0, 0, 0, 1, 0, 431, 0, 0, 0, 0, ''), -- Frightened Prisoner
(@CGUID+122, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+125, 0, 0, 0, 0, 0, 1, 0, 474, 0, 0, 0, 0, ''), -- Twilight Storm Mender
(@CGUID+126, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+135, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+137, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+139, 0, 0, 0, 0, 0, 1, 0, 474, 0, 0, 0, 0, ''), -- Twilight Aquamancer
(@CGUID+146, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+147, 0, 0, 0, 0, 0, 1, 0, 474, 0, 0, 0, 0, ''), -- Twilight Aquamancer
(@CGUID+151, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Twilight Storm Mender
(@CGUID+160, 0, 0, 0, 0, 0, 1, 0, 474, 0, 0, 0, 0, ''), -- Twilight Aquamancer
(@CGUID+174, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 3, ''), -- Executioner Gore -
(@CGUID+190, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+192, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+193, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Shadowmage
(@CGUID+202, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Aquamancer
(@CGUID+204, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Disciple
(@CGUID+205, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Twilight Storm Mender
(@CGUID+213, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Storm mender
(@CGUID+214, 0, 0, 0, 0, 0, 1, 0, 474, 0, 0, 0, 0, ''), -- Twilight Shadowmage
(@CGUID+216, 0, 0, 0, 0, 0, 1, 0, 375, 0, 0, 0, 0, ''), -- Twilight Storm mender
(@CGUID+217, 0, 0, 0, 0, 0, 1, 0, 474, 0, 0, 0, 0, ''), -- Twilight Aquamancer
(@CGUID+233, 0, 0, 0, 0, 0, 1, 0, 474, 0, 0, 0, 0, ''), -- Twilight Aquamancer
(@CGUID+234, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146587'), -- Frightened Prisoner
(@CGUID+236, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146587'), -- Frightened Prisoner
(@CGUID+237, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146587'), -- Frightened Prisoner
(@CGUID+238, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146587'), -- Frightened Prisoner
(@CGUID+239, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146587'), -- Frightened Prisoner
(@CGUID+241, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146587'), -- Frightened Prisoner
(@CGUID+244, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '146587'), -- Frightened Prisoner
(@CGUID+277, 0, 0, 0, 0, 0, 1, 0, 433, 0, 0, 0, 0, ''), -- Sentinel Aluwyn
(@CGUID+278, 0, 0, 0, 0, 0, 1, 0, 64, 0, 0, 0, 0, '149802'); -- Ashelan Northwood - 149802 - Blackfathom Deeps - Entrance - Wounded (Cosmetic)

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+73;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 19018, 48, 719, 719, '1', '0', 0, -320.238067626953125, 65.97138214111328125, -63.7391891479492187, 0.628316879272460937, 0, 0, 0.309016227722167968, 0.95105677843093872, 7200, 255, 1, 59679), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+1, 3689, 48, 719, 719, '1', '0', 0, -295.37835693359375, 316.711334228515625, -52.3953285217285156, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 7200, 255, 1, 59679), -- Weapon Crate (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+2, 224747, 48, 719, 719, '1', '0', 0, -271.50433349609375, 70.14742279052734375, -58.0973777770996093, 5.643613338470458984, 0, 0, -0.31436347961425781, 0.94930267333984375, 7200, 255, 1, 59679), -- Rope Ladder Post (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+3, 224627, 48, 719, 719, '1', '0', 0, -290.28936767578125, 80.3796539306640625, -52.3303298950195312, 0.718073844909667968, 0, 0, 0.351372718811035156, 0.936235666275024414, 7200, 255, 1, 59679), -- Coiled Rope (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+4, 19018, 48, 719, 719, '1', '0', 0, -421.11395263671875, 121.5354385375976562, -70.3830795288085937, 4.956737518310546875, 0, 0, -0.61566066741943359, 0.788011372089385986, 7200, 255, 1, 59679), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+5, 21117, 48, 719, 719, '1', '0', 0, -818.3607177734375, -200.647247314453125, -25.7910709381103515, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 7200, 255, 1, 59679), -- Portal of Aku'Mai (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+6, 19018, 48, 719, 719, '1', '0', 0, -348.721710205078125, -34.5047073364257812, -68.4577102661132812, 3.45575571060180664, 0, 0, -0.98768806457519531, 0.156436234712600708, 7200, 255, 1, 59679), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+7, 224628, 48, 719, 719, '1', '0', 0, -289.270416259765625, 82.37071990966796875, -52.263702392578125, 5.268967628479003906, 0, 0, -0.48565196990966796, 0.874152243137359619, 7200, 255, 1, 59679), -- Rope Ladder Post (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2
(@OGUID+8, 224826, 48, 719, 719, '1', '0', 0, -406.12542724609375, 30.94713401794433593, -48.5637359619140625, 0.323545306921005249, 0, 0, 0.161067962646484375, 0.986943304538726806, 7200, 255, 1, 59679), -- Altar of Blood (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+9, 19018, 48, 719, 719, '1', '0', 0, -400.426910400390625, 279.811859130859375, -71.1439132690429687, 2.740161895751953125, 0, 0, 0.979924201965332031, 0.199370384216308593, 7200, 255, 1, 59679), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+10, 19018, 48, 719, 719, '1', '0', 0, -427.4090576171875, 311.43017578125, -65.8169937133789062, 0.139624491333961486, 0, 0, 0.06975555419921875, 0.997564136981964111, 7200, 255, 1, 59679), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+11, 19018, 48, 719, 719, '1', '0', 0, -410.671173095703125, 348.6953125, -71.7385101318359375, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 7200, 255, 1, 59679), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+12, 225779, 48, 719, 719, '1', '0', 0, -301.7135009765625, 412.751068115234375, -57.0965728759765625, 0.410105913877487182, 0, 0, 0.203619003295898437, 0.979050219058990478, 7200, 255, 1, 59679), -- Altar of Blood (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+13, 21327, 48, 719, 719, '1', '0', 0, -534.78900146484375, 317.35284423828125, -49.8212776184082031, 3.145930051803588867, -0.01917314529418945, 0.021241188049316406, -0.9995889663696289, 0.001760523067787289, 7200, 255, 1, 59679), -- Campfire (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+14, 19018, 48, 719, 719, '1', '0', 0, -710.160400390625, -49.4720573425292968, -41.5957298278808593, 3.316144466400146484, 0, 0, -0.99619388580322265, 0.087165042757987976, 7200, 255, 1, 59679), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+15, 19018, 48, 719, 719, '1', '0', 0, -731.24261474609375, -49.8700714111328125, -40.9547004699707031, 3.717553615570068359, 0, 0, -0.95881938934326171, 0.284016460180282592, 7200, 255, 1, 59679), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+16, 19018, 48, 719, 719, '1', '0', 0, -805.24713134765625, -65.7192230224609375, -43.6952667236328125, 0.610863447189331054, 0, 0, 0.3007049560546875, 0.953717231750488281, 7200, 255, 1, 59679), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+17, 19018, 48, 719, 719, '1', '0', 0, -727.02532958984375, -118.418769836425781, -37.0087509155273437, 3.298687219619750976, 0, 0, -0.99691677093505859, 0.078466430306434631, 7200, 255, 1, 59679), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+18, 19018, 48, 719, 719, '1', '0', 0, -741.0545654296875, -152.381240844726562, -56.7610855102539062, 0.575957298278808593, 0, 0, 0.284014701843261718, 0.958819925785064697, 7200, 255, 1, 59679), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+19, 19018, 48, 719, 719, '1', '0', 0, -795.3590087890625, -161.435134887695312, -44.3909492492675781, 4.782202720642089843, 0, 0, -0.68199825286865234, 0.731353819370269775, 7200, 255, 1, 59679), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+20, 224720, 48, 719, 719, '1', '0', 0, -818.37078857421875, -155.0125732421875, -25.8814907073974609, 0, 0, 0, 0, 1, 7200, 255, 1, 59679), -- Fire of Aku'mai (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+21, 225586, 48, 719, 719, '1', '0', 0, -818.78558349609375, -154.197341918945312, -25.8946781158447265, 1.285956740379333496, 0, 0, 0.599581718444824218, 0.800313532352447509, 7200, 255, 1, 59679), -- Skull Pile (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+22, 225586, 48, 719, 719, '1', '0', 0, -817.90875244140625, -154.164779663085937, -25.8902015686035156, 0.414663732051849365, 0, 0, 0.205849647521972656, 0.97858363389968872, 7200, 255, 1, 59679), -- Skull Pile (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+23, 225586, 48, 719, 719, '1', '0', 0, -817.26373291015625, -155.200393676757812, -25.8792362213134765, 6.18979644775390625, 0, 0, -0.0466775894165039, 0.998910009860992431, 7200, 255, 1, 59679), -- Skull Pile (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+24, 225786, 48, 719, 719, '1', '0', 0, -818.32696533203125, -159.059036254882812, -24.5173606872558593, 1.58211374282836914, 0, 0, 0.711096763610839843, 0.703094124794006347, 7200, 255, 1, 59679), -- Altar of Blood (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+25, 225586, 48, 719, 719, '1', '0', 0, -819.33074951171875, -155.070877075195312, -25.8925380706787109, 0.479528188705444335, 0, 0, 0.237473487854003906, 0.971394002437591552, 7200, 255, 1, 59679), -- Skull Pile (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+26, 225625, 48, 719, 719, '1', '0', 0, -422.70989990234375, 38.28874588012695312, -48.296875, 5.655460357666015625, 0, 0, -0.30873489379882812, 0.951148152351379394, 7200, 255, 1, 59679), -- Meat Chunk 01 (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2
(@OGUID+27, 225626, 48, 719, 719, '1', '0', 0, -425.61077880859375, 38.35466384887695312, -48.2482643127441406, 5.655460357666015625, 0, 0, -0.30873489379882812, 0.951148152351379394, 7200, 255, 1, 59679), -- Meat Chunk 02 (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2
(@OGUID+28, 225625, 48, 719, 719, '1', '0', 0, -426.631256103515625, 38.04848098754882812, -48.2260513305664062, 0.725825130939483642, 0, 0, 0.354998588562011718, 0.934866845607757568, 7200, 255, 1, 59679), -- Meat Chunk 01 (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2
(@OGUID+29, 225624, 48, 719, 719, '1', '0', 0, -424.37347412109375, 38.03435134887695312, -48.2673606872558593, 5.655460357666015625, 0, 0, -0.30873489379882812, 0.951148152351379394, 7200, 255, 1, 59679), -- Murloc Slop Pile (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2
(@OGUID+30, 225626, 48, 719, 719, '1', '0', 0, -421.35162353515625, 37.805755615234375, -48.3171195983886718, 3.949546098709106445, 0, 0, -0.91950511932373046, 0.393077999353408813, 7200, 255, 1, 59679), -- Meat Chunk 02 (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2
(@OGUID+31, 225625, 48, 719, 719, '1', '0', 0, -422.499420166015625, 37.13415145874023437, -48.2889633178710937, 2.175248622894287109, 0, 0, 0.885525703430175781, 0.464590370655059814, 7200, 255, 1, 59679), -- Meat Chunk 01 (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2
(@OGUID+32, 225626, 48, 719, 719, '1', '0', 0, -426.4981689453125, 40.143310546875, -48.2525711059570312, 3.949546098709106445, 0, 0, -0.91950511932373046, 0.393077999353408813, 7200, 255, 1, 59679), -- Meat Chunk 02 (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2
(@OGUID+33, 225817, 48, 719, 719, '1', '0', 0, -840.57830810546875, -473.478851318359375, -34.0588722229003906, 1.929207086563110351, 0, 0, 0.8218231201171875, 0.569742739200592041, 7200, 255, 1, 59679), -- Spoils of Blackfathom (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject2
(@OGUID+34, 3702, 48, 719, 719, '1', '0', 0, -295.37835693359375, 316.711334228515625, -52.3953285217285156, 2.234017848968505859, 0, 0, 0.898793220520019531, 0.438372820615768432, 7200, 255, 1, 60257), -- Armor Crate (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+35, 19018, 48, 719, 719, '1', '0', 0, -353.398529052734375, -23.7944202423095703, -67.7352752685546875, 4.276057243347167968, 0, 0, -0.84339141845703125, 0.537299633026123046, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+36, 19018, 48, 719, 719, '1', '0', 0, -346.6336669921875, 291.60455322265625, -70.7872161865234375, 3.106652259826660156, 0, 0, 0.999847412109375, 0.017469281330704689, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+37, 19018, 48, 719, 719, '1', '0', 0, -345.409698486328125, 222.0523223876953125, -67.9230422973632812, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+38, 19018, 48, 719, 719, '1', '0', 0, -489.73443603515625, 144.3833770751953125, -72.4147415161132812, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+39, 19018, 48, 719, 719, '1', '0', 0, -526.05059814453125, 149.8927459716796875, -79.7070159912109375, 4.660029888153076171, 0, 0, -0.72537422180175781, 0.688354730606079101, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+40, 19018, 48, 719, 719, '1', '0', 0, -764.240234375, -12.3916549682617187, -35.5402870178222656, 5.93412017822265625, 0, 0, -0.17364788055419921, 0.984807789325714111, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+41, 19018, 48, 719, 719, '1', '0', 0, -730.435302734375, -31.5133304595947265, -41.4730644226074218, 2.111847877502441406, 0, 0, 0.870355606079101562, 0.492423713207244873, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+42, 19018, 48, 719, 719, '1', '0', 0, -755.5645751953125, -121.636993408203125, -37.5904502868652343, 1.797688722610473632, 0, 0, 0.7826080322265625, 0.622514784336090087, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+43, 19018, 48, 719, 719, '1', '0', 0, -727.22869873046875, -169.697708129882812, -59.1201591491699218, 5.235987663269042968, 0, 0, -0.5, 0.866025388240814208, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+44, 19018, 48, 719, 719, '1', '0', 0, -790.217041015625, -176.526947021484375, -45.1691703796386718, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+45, 19018, 48, 719, 719, '1', '0', 0, -347.47064208984375, 76.08115386962890625, -61.8706207275390625, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+46, 19018, 48, 719, 719, '1', '0', 0, -359.85595703125, 279.1282958984375, -77.0189743041992187, 2.617989301681518554, 0, 0, 0.965925216674804687, 0.258821308612823486, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+47, 3702, 48, 719, 719, '1', '0', 0, -614.86407470703125, 252.7447967529296875, -49.4881477355957031, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 7200, 255, 1, 60257), -- Armor Crate (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+48, 19018, 48, 719, 719, '1', '0', 0, -732.46661376953125, -67.330841064453125, -38.4371833801269531, 6.213373661041259765, 0, 0, -0.03489875793457031, 0.999390840530395507, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+49, 19018, 48, 719, 719, '1', '0', 0, -799.32098388671875, -30.2353591918945312, -37.0964469909667968, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+50, 19018, 48, 719, 719, '1', '0', 0, -700.195068359375, -100.683113098144531, -35.678741455078125, 3.94444584846496582, 0, 0, -0.92050457000732421, 0.3907318115234375, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+51, 19018, 48, 719, 719, '1', '0', 0, -437.447662353515625, 292.990814208984375, -65.862457275390625, 6.003933906555175781, 0, 0, -0.13917255401611328, 0.990268170833587646, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+52, 3689, 48, 719, 719, '1', '0', 0, -614.86407470703125, 252.7447967529296875, -49.4881477355957031, 4.817109584808349609, 0, 0, -0.66913032531738281, 0.74314504861831665, 7200, 255, 1, 60257), -- Weapon Crate (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+53, 19018, 48, 719, 719, '1', '0', 0, -713.4542236328125, -21.8693408966064453, -39.3413848876953125, 2.932138919830322265, 0, 0, 0.994521141052246093, 0.104535527527332305, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+54, 19018, 48, 719, 719, '1', '0', 0, -784.3287353515625, -82.7393798828125, -43.0524787902832031, 0.558503925800323486, 0, 0, 0.275636672973632812, 0.961261868476867675, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+55, 19018, 48, 719, 719, '1', '0', 0, -410.16949462890625, 94.1617431640625, -65.5918655395507812, 2.094393253326416015, 0, 0, 0.866024971008300781, 0.50000077486038208, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+56, 19018, 48, 719, 719, '1', '0', 0, -835.62677001953125, -47.6639022827148437, -35.6944770812988281, 3.45575571060180664, 0, 0, -0.98768806457519531, 0.156436234712600708, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+57, 19018, 48, 719, 719, '1', '0', 0, -368.942352294921875, 256.857086181640625, -71.7872772216796875, 5.70722818374633789, 0, 0, -0.28401470184326171, 0.958819925785064697, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+58, 19018, 48, 719, 719, '1', '0', 0, -354.931182861328125, 308.108734130859375, -69.8227081298828125, 2.984498262405395507, 0, 0, 0.996916770935058593, 0.078466430306434631, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+59, 19018, 48, 719, 719, '1', '0', 0, -472.57470703125, 130.778411865234375, -72.3318634033203125, 1.623155713081359863, 0, 0, 0.725374221801757812, 0.688354730606079101, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+60, 19018, 48, 719, 719, '1', '0', 0, -405.57098388671875, 319.073974609375, -68.0789718627929687, 4.258606910705566406, 0, 0, -0.84804725646972656, 0.529920578002929687, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+61, 19018, 48, 719, 719, '1', '0', 0, -753.1727294921875, -21.32537841796875, -37.49896240234375, 5.009094715118408203, 0, 0, -0.59482288360595703, 0.80385679006576538, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+62, 19018, 48, 719, 719, '1', '0', 0, -683.9407958984375, -76.1221084594726562, -36.7330207824707031, 5.759587764739990234, 0, 0, -0.25881862640380859, 0.965925931930541992, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+63, 19018, 48, 719, 719, '1', '0', 0, -807.6165771484375, -120.466972351074218, -37.3080787658691406, 1.291541695594787597, 0, 0, 0.60181427001953125, 0.798636078834533691, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+64, 19018, 48, 719, 719, '1', '0', 0, -781.43231201171875, -165.56109619140625, -47.9077644348144531, 5.829400539398193359, 0, 0, -0.22495079040527343, 0.974370121955871582, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+65, 19018, 48, 719, 719, '1', '0', 0, -331.169464111328125, -27.6077117919921875, -72.2552108764648437, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+66, 19018, 48, 719, 719, '1', '0', 0, -734.4345703125, -96.0345306396484375, -36.9606475830078125, 1.204277276992797851, 0, 0, 0.56640625, 0.824126183986663818, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+67, 19018, 48, 719, 719, '1', '0', 0, -870.4945068359375, -105.115287780761718, -35.4094352722167968, 1.710421562194824218, 0, 0, 0.754709243774414062, 0.656059443950653076, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+68, 19018, 48, 719, 719, '1', '0', 0, -770.51202392578125, -189.07220458984375, -48.8139495849609375, 5.777040958404541015, 0, 0, -0.25037956237792968, 0.968147754669189453, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+69, 19018, 48, 719, 719, '1', '0', 0, -308.599395751953125, 198.4462890625, -65.0973892211914062, 4.520402908325195312, 0, 0, -0.77162456512451171, 0.636078238487243652, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: 0) CreateObject1
(@OGUID+70, 19018, 48, 719, 719, '1', '0', 0, -450.11083984375, 130.31268310546875, -71.376007080078125, 3.612837791442871093, 0, 0, -0.97236919403076171, 0.233448356389999389, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+71, 19018, 48, 719, 719, '1', '0', 0, -686.755126953125, -34.1224174499511718, -36.9233741760253906, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+72, 19018, 48, 719, 719, '1', '0', 0, -760.38995361328125, -52.2364158630371093, -41.6094551086425781, 0.977383077144622802, 0, 0, 0.469470977783203125, 0.882947921752929687, 7200, 255, 1, 60257), -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1
(@OGUID+73, 19018, 48, 719, 719, '1', '0', 0, -760.68328857421875, -155.533584594726562, -51.5061683654785156, 0.471238493919372558, 0, 0, 0.233445167541503906, 0.972369968891143798, 7200, 255, 1, 60257); -- Giant Clam (Area: Blackfathom Deeps - Difficulty: Normal) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+73;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+5, 0, 0, 1, -0.00000004371138828, 0, 0), -- Portal of Aku'Mai
(@OGUID+13, 0, 0, 1, -0.00000004371138828, 0, 0), -- Campfire
(@OGUID+33, 0, 0, 0, 1, 569, 0); -- Spoils of Blackfathom

-- AreaTrigger
DELETE FROM `areatrigger_template` WHERE (`IsCustom`=0 AND `Id` IN (5632,5982,5562,30719));
INSERT INTO `areatrigger_template` (`Id`, `IsCustom`, `Flags`, `VerifiedBuild`) VALUES
(5632, 0, 0, 59679),
(5982, 0, 0, 59679),
(5562, 0, 0, 59679),
(30719, 0, 0, 59679);

DELETE FROM `areatrigger_create_properties` WHERE (`IsCustom`=0 AND `Id` IN (1406,1532,1384,26554));
INSERT INTO `areatrigger_create_properties` (`Id`, `IsCustom`, `AreaTriggerId`, `IsAreatriggerCustom`, `Flags`, `MoveCurveId`, `ScaleCurveId`, `MorphCurveId`, `FacingCurveId`, `AnimId`, `AnimKitId`, `DecalPropertiesId`, `SpellForVisuals`, `TimeToTargetScale`, `Speed`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `VerifiedBuild`) VALUES
(1406, 0, 5632, 0, 0, 0, 0, 0, 0, -1, 0, 0, NULL, 10000, 0, 0, 15, 15, 0, 0, 0, 0, 0, 0, 59679), -- Spell: 150548 (Crushing Singularity)
(1532, 0, 5982, 0, 2, 0, 32462, 0, 0, -1, 0, 82, NULL, 15000, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 59679), -- Spell: 149943 (Executioner's Strike)
(1384, 0, 5562, 0, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 0, 0, 0, 5, 5, 0, 0, 0, 0, 0, 0, 59679), -- Spell: 149866 (Shell Shocker)
(26554, 0, 30719, 0, 4, 0, 0, 0, 0, -1, 0, 0, NULL, 3000, 0, 0, 10, 10, 0, 0, 0, 0, 0, 0, 59679); -- Spell: 361584 (Whirling Surge)

UPDATE `gameobject_template_addon` SET `WorldEffectID`=569 WHERE `entry`=225817; -- Spoils of Blackfathom
UPDATE `gameobject_template_addon` SET `flags`=0x10 WHERE `entry`=224720; -- Fire of Aku'mai
UPDATE `gameobject_template_addon` SET `flags`=0x0 WHERE `entry`=19018; -- Giant Clam
UPDATE `gameobject_template_addon` SET `flags`=0x0 WHERE `entry`=224627; -- Coiled Rope

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (75157 /*75157 (Aku'mai the Venomous) - Amputation*/, 75172 /*75172 (Deep Terror) - Amputation*/, 75155 /*75155 (Aku'mai the Devourer) - Goo Splash*/, 75780 /*75780 (Deep Terror)*/, 75781 /*75781 (Deep Terror) - Ride Vehicle Hardcoded, Goo Splash*/, 75147 /*75147 (Invisible Man) - Coiled Rope Usable*/, 74569 /*74569 (Restorative Waters) - Watery Burst*/, 75553 /*75553 (Subjugator Kor'ul) - Optional Boss Killed Cosmetic*/, 75463 /*75463 (Deep Terror) - Goo Splash*/, 75396 /*75396 (Deep Terror)*/, 75550 /*75550 (Domina) - Optional Boss Killed Cosmetic*/, 75158 /*75158 (Aku'mai) - Vision of Aku'mai Cosmetic, Submerge Visual*/, 75575 /*75575 (Invisible Man) - Fire of Aku'mai Visual*/, 74979 /*74979 (Frightened Prisoner) - Kor'kron Cosmetic (Dead)*/, 76036 /*76036 (Twilight Shadow) - Sneak*/, 75090 /*75090 (Deep Terror) - Goo Splash*/, 75086 /*75086 (Deep Terror)*/, 74747 /*74747 (Deep Terror) - Goo Splash*/, 74728 /*74728 (Twilight Lord Bathiel)*/, 74508 /*74508 (Guardian of the Deep) - Hungry*/, 76062 /*76062 (Guardian Eggs) - Guardian Eggs Sparkles*/, 75307 /*75307 (Invisible Man) - Altar of Blood (Cosmetic)*/, 74518 /*74518 (Executioner Gore)*/, 76005 /*76005 (Lady Sarevess) - Slain Boss Cosmetic (Dead)*/, 75042 /*75042 (Invisible Man) - Dark Sacrifice Hover*/, 75046 /*75046 (Deep Terror) - Submerge Visual*/, 75039 /*75039 (Frightened Prisoner) - Dark Sacrifice Hover*/, 74505 /*74505 (Thruk) - Fishing Pole, Fishing Line*/, 74363 /*74363 (Twilight Shadow) - Sneak*/, 75060 /*75060 (Slain Hero) - Slain Hero Cosmetic (Dead)*/, 75011 /*75011 (Twilight Storm Mender) - Kill Cultists Transform*/, 75012 /*75012 (Twilight Disciple) - Kill Cultists Transform*/, 74984 /*74984 (Blindlight Murloc) - Haste*/, 75000 /*75000 (Invisible Man) - Coiled Rope Usable*/, 75643 /*75643 (Blindlight Murloc) - Haste*/, 75642 /*75642 (Blindlight Bilefin) - Haste*/, 75658 /*75658 (Blindlight Murloc) - Loot Bag*/, 74476 /*74476 (Domina)*/, 74721 /*74721 (Blindlight Bilefin) - Haste*/, 74720 /*74720 (Blindlight Murloc) - Haste*/, 75641 /*75641 (Blindlight Bilefin) - Haste*/, 75640 /*75640 (Blindlight Murloc) - Haste*/, 74565 /*74565 (Subjugator Kor'ul)*/, 74446 /*74446 (Ghamoo-Ra)*/, 76012 /*76012 (Gelihast) - Slain Boss Cosmetic (Dead)*/, 74408 /*74408 (Je'neu Sancrea) - Blackfathom Deeps - Entrance - Wounded (Cosmetic)*/, 75980 /*75980 (Blindlight Razorjaw) - Haste*/, 75607);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(75157, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '153386'), -- 75157 (Aku'mai the Venomous) - Amputation
(75172, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '153386'), -- 75172 (Deep Terror) - Amputation
(75155, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '152693'), -- 75155 (Aku'mai the Devourer) - Goo Splash
(75780, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 75780 (Deep Terror)
(75781, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151079'), -- 75781 (Deep Terror) - Ride Vehicle Hardcoded, Goo Splash
(75147, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150866'), -- 75147 (Invisible Man) - Coiled Rope Usable
(74569, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150027'), -- 74569 (Restorative Waters) - Watery Burst
(75553, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '152137'), -- 75553 (Subjugator Kor'ul) - Optional Boss Killed Cosmetic
(75463, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151052'), -- 75463 (Deep Terror) - Goo Splash
(75396, 0, 0, 9, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 75396 (Deep Terror)
(75550, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '152137'), -- 75550 (Domina) - Optional Boss Killed Cosmetic
(75158, 0, 0, 9, 0, 0, 1, 0, 0, 0, 0, 0, 0, '152142 28819'), -- 75158 (Aku'mai) - Vision of Aku'mai Cosmetic, Submerge Visual
(75575, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '152140'), -- 75575 (Invisible Man) - Fire of Aku'mai Visual
(74979, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 74979 (Frightened Prisoner)
(76036, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150473'), -- 76036 (Twilight Shadow) - Sneak
(75090, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151079'), -- 75090 (Deep Terror) - Goo Splash
(75086, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 75086 (Deep Terror)
(74747, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151052'), -- 74747 (Deep Terror) - Goo Splash
(74728, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 74728 (Twilight Lord Bathiel)
(74508, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '152647'), -- 74508 (Guardian of the Deep) - Hungry
(76062, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '153429'), -- 76062 (Guardian Eggs) - Guardian Eggs Sparkles
(75307, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151538'), -- 75307 (Invisible Man) - Altar of Blood (Cosmetic)
(74518, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 74518 (Executioner Gore)
(76005, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '153277'), -- 76005 (Lady Sarevess) - Slain Boss Cosmetic (Dead)
(75042, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150922'), -- 75042 (Invisible Man) - Dark Sacrifice Hover
(75046, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 75046 (Deep Terror)
(75039, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '150919'), -- 75039 (Frightened Prisoner) - Dark Sacrifice Hover
(74505, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '150189 151865'), -- 74505 (Thruk) - Fishing Pole, Fishing Line
(74363, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150473'), -- 74363 (Twilight Shadow) - Sneak
(75060, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151020'), -- 75060 (Slain Hero) - Slain Hero Cosmetic (Dead)
(75011, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 75011 (Twilight Storm Mender)
(75012, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 75012 (Twilight Disciple)
(74984, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150392'), -- 74984 (Blindlight Murloc) - Haste
(75000, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150866'), -- 75000 (Invisible Man) - Coiled Rope Usable
(75643, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150392'), -- 75643 (Blindlight Murloc) - Haste
(75642, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150392'), -- 75642 (Blindlight Bilefin) - Haste
(75658, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151037'), -- 75658 (Blindlight Murloc) - Loot Bag
(74476, 0, 0, 0, 0, 0, 1, 0, 10, 0, 0, 0, 3, ''), -- 74476 (Domina)
(74721, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150392'), -- 74721 (Blindlight Bilefin) - Haste
(74720, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150392'), -- 74720 (Blindlight Murloc) - Haste
(75641, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150392'), -- 75641 (Blindlight Bilefin) - Haste
(75640, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150392'), -- 75640 (Blindlight Murloc) - Haste
(74565, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 74565 (Subjugator Kor'ul)
(74446, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 74446 (Ghamoo-Ra)
(76012, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '153277'), -- 76012 (Gelihast) - Slain Boss Cosmetic (Dead)
(74408, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 74408 (Je'neu Sancrea) - Blackfathom Deeps - Entrance - Wounded (Cosmetic)
(75980, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '150392'), -- 75980 (Blindlight Razorjaw) - Haste
(75607, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 75607 (Ashelan Northwood) - Blackfathom Deeps - Entrance - Wounded (Cosmetic)

DELETE FROM `gameobject_template_addon` WHERE `entry`=224747;
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(224747, 0, 0x10, 0, 0); -- Rope Ladder Post

-- Template
UPDATE `creature_template` SET `unit_flags2`=0x800, `unit_flags3`=0x40000000 WHERE `entry`=75155; -- Aku'mai the Devourer
UPDATE `creature_template` SET `unit_flags3`=0x40000000 WHERE `entry` IN (75780, 74747, 75090, 75086, 75111); -- Deep Terror
UPDATE `creature_template` SET `unit_flags3`=0x40000001 WHERE `entry` IN (75781, 75463, 75046); -- Deep Terror
UPDATE `creature_template` SET `unit_flags3`=0x41000001 WHERE `entry`=75408; -- Aku'mai
UPDATE `creature_template` SET `unit_flags3`=0x41000001, `flags_extra` = 128 WHERE `entry` IN (75147, 75923, 75575, 75307, 75042, 74997, 74998, 75000); -- Invisible Man
UPDATE `creature_template` SET `unit_flags3`=0x41000001 WHERE `entry`=85844; -- The Old Gods
UPDATE `creature_template` SET `unit_flags3`=0x40000001 WHERE `entry`=75158; -- Aku'mai
UPDATE `creature_template` SET `unit_flags3`=0x8000000 WHERE `entry`=74509; -- Blue Shale Crawler
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=74728; -- Twilight Lord Bathiel
UPDATE `creature_template` SET `unit_flags2`=0x800, `unit_flags3`=0x14000000 WHERE `entry`=74508; -- Guardian of the Deep
UPDATE `creature_template` SET `unit_flags3`=0x41000001 WHERE `entry`=76062; -- Guardian Eggs
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=74518; -- Executioner Gore
UPDATE `creature_template` SET `unit_flags3`=0x40000001 WHERE `entry`=76005; -- Lady Sarevess
UPDATE `creature_template` SET `unit_flags3`=0x40000001 WHERE `entry`=75034; -- Twilight Tormentor
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=74505; -- Thruk
UPDATE `creature_template` SET `faction`=128, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=74716; -- Aqua Guardian
UPDATE `creature_template` SET `unit_flags3`=0x14000000 WHERE `entry`=76954; -- Pahboo-Ra
UPDATE `creature_template` SET `unit_flags2`=0x800, `unit_flags3`=0x14000000 WHERE `entry`=74446; -- Ghamoo-Ra
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=74476; -- Domina
UPDATE `creature_template` SET `unit_flags2`=0x800 WHERE `entry`=74565; -- Subjugator Kor'ul
UPDATE `creature_template` SET `unit_flags`=0x40, `unit_flags3`=0x4000000 WHERE `entry`=74722; -- Razorshell Snapjaw
UPDATE `creature_template` SET `BaseAttackTime`=2000 WHERE `entry`=75641; -- Blindlight Bilefin
UPDATE `creature_template` SET `BaseAttackTime`=1333 WHERE `entry`=75640; -- Blindlight Murloc
UPDATE `creature_template` SET `BaseAttackTime`=2000 WHERE `entry`=75980; -- Blindlight Razorjaw
UPDATE `creature_template` SET `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=75607; -- Ashelan Northwood
UPDATE `creature_template` SET `npcflag`=3, `BaseAttackTime`=2000, `unit_flags`=0x200, `unit_flags2`=0x800 WHERE `entry`=75606; -- Sentinel Aluwyn
UPDATE `creature_template` SET `faction`=18, `BaseAttackTime`=2000, `unit_flags`=0x40, `unit_flags2`=0x800, `unit_flags3`=0x0 WHERE `entry`=74721; -- Blindlight Bilefin

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=75155 AND `DifficultyID`=1); -- 75155 (Aku'mai the Devourer) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=75780 AND `DifficultyID`=1); -- 75780 (Deep Terror) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=75781 AND `DifficultyID`=1); -- 75781 (Deep Terror) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=74747 AND `DifficultyID`=1); -- 74747 (Deep Terror) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60257 WHERE (`Entry`=75408 AND `DifficultyID`=1); -- 75408 (Aku'mai) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60257 WHERE (`Entry`=75147 AND `DifficultyID`=1); -- 75147 (Invisible Man) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60257 WHERE (`Entry`=75923 AND `DifficultyID`=1); -- 75923 (Invisible Man) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=60257 WHERE (`Entry`=75553 AND `DifficultyID`=1); -- 75553 (Subjugator Kor'ul) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=75463 AND `DifficultyID`=1); -- 75463 (Deep Terror) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60257 WHERE (`Entry`=85844 AND `DifficultyID`=1); -- 85844 (The Old Gods) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=2, `LevelScalingDeltaMax`=2, `ContentTuningID`=200, `StaticFlags1`=0x30000000, `VerifiedBuild`=60257 WHERE (`Entry`=75550 AND `DifficultyID`=0); -- 75550 (Domina) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=75158 AND `DifficultyID`=1); -- 75158 (Aku'mai) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60257 WHERE (`Entry`=75575 AND `DifficultyID`=1); -- 75575 (Invisible Man) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=76038 AND `DifficultyID`=1); -- 76038 (Twilight Shadowmage) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=76039 AND `DifficultyID`=1); -- 76039 (Twilight Aquamancer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=76036 AND `DifficultyID`=1); -- 76036 (Twilight Shadow) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=75090 AND `DifficultyID`=1); -- 75090 (Deep Terror) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=75086 AND `DifficultyID`=1); -- 75086 (Deep Terror) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=76037 AND `DifficultyID`=1); -- 76037 (Twilight Storm Mender) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74509 AND `DifficultyID`=1); -- 74509 (Blue Shale Crawler) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74728 AND `DifficultyID`=1); -- 74728 (Twilight Lord Bathiel) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74508 AND `DifficultyID`=1); -- 74508 (Guardian of the Deep) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60257 WHERE (`Entry`=76062 AND `DifficultyID`=1); -- 76062 (Guardian Eggs) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75410 AND `DifficultyID`=1); -- 75410 (Guardian of the Deep) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74518 AND `DifficultyID`=1); -- 74518 (Executioner Gore) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60257 WHERE (`Entry`=75307 AND `DifficultyID`=1); -- 75307 (Invisible Man) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `StaticFlags3`=0x2000000, `VerifiedBuild`=60257 WHERE (`Entry`=74861 AND `DifficultyID`=1); -- 74861 (Voidwalker Minion) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=76005 AND `DifficultyID`=1); -- 76005 (Lady Sarevess) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=75034 AND `DifficultyID`=1); -- 75034 (Twilight Tormentor) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60257 WHERE (`Entry`=75042 AND `DifficultyID`=1); -- 75042 (Invisible Man) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=60257 WHERE (`Entry`=75039 AND `DifficultyID`=1); -- 75039 (Frightened Prisoner) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=75046 AND `DifficultyID`=1); -- 75046 (Deep Terror) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60257 WHERE (`Entry`=74997 AND `DifficultyID`=1); -- 74997 (Invisible Man) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75285 AND `DifficultyID`=1); -- 75285 (Twilight Storm Mender) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75058 AND `DifficultyID`=1); -- 75058 (Twilight Aquamancer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74505 AND `DifficultyID`=1); -- 74505 (Thruk) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74716 AND `DifficultyID`=1); -- 74716 (Aqua Guardian) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74353 AND `DifficultyID`=1); -- 74353 (Twilight Aquamancer) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=75111 AND `DifficultyID`=1); -- 75111 (Deep Terror) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74363 AND `DifficultyID`=1); -- 74363 (Twilight Shadow) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=76954 AND `DifficultyID`=1); -- 76954 (Pahboo-Ra) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75060 AND `DifficultyID`=1); -- 75060 (Slain Hero) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74719 AND `DifficultyID`=1); -- 74719 (Blindlight Rotmouth) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75012 AND `DifficultyID`=1); -- 75012 (Twilight Disciple) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75011 AND `DifficultyID`=1); -- 75011 (Twilight Storm Mender) - CanSwim
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=60257 WHERE (`Entry`=74729 AND `DifficultyID`=1);
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74380 AND `DifficultyID`=1); -- 74380 (Twilight Storm Mender) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75428 AND `DifficultyID`=1); -- 75428 (Frightened Prisoner) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74351 AND `DifficultyID`=1); -- 74351 (Twilight Disciple) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74446 AND `DifficultyID`=1); -- 74446 (Ghamoo-Ra) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74476 AND `DifficultyID`=1); -- 74476 (Domina) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75286 AND `DifficultyID`=1); -- 75286 (Twilight Disciple) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74565 AND `DifficultyID`=1); -- 74565 (Subjugator Kor'ul) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74382 AND `DifficultyID`=1); -- 74382 (Twilight Shadowmage) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75643 AND `DifficultyID`=1); -- 75643 (Blindlight Murloc) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74722 AND `DifficultyID`=1); -- 74722 (Razorshell Snapjaw) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75642 AND `DifficultyID`=1); -- 75642 (Blindlight Bilefin) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=76012 AND `DifficultyID`=1); -- 76012 (Gelihast) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75641 AND `DifficultyID`=1); -- 75641 (Blindlight Bilefin) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75658 AND `DifficultyID`=1); -- 75658 (Blindlight Murloc) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75640 AND `DifficultyID`=1); -- 75640 (Blindlight Murloc) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75522 AND `DifficultyID`=1); -- 75522 (Bloodtail Grouper) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74989 AND `DifficultyID`=1); -- 74989 (Twilight Disciple) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75980 AND `DifficultyID`=1); -- 75980 (Blindlight Razorjaw) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74984 AND `DifficultyID`=1); -- 74984 (Blindlight Murloc) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74983 AND `DifficultyID`=1); -- 74983 (Twilight Disciple) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74980 AND `DifficultyID`=1); -- 74980 (Twilight Storm Mender) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=77232 AND `DifficultyID`=1); -- 77232 (Twilight Disciple) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2884, `VerifiedBuild`=60257 WHERE (`Entry`=53488 AND `DifficultyID`=0); -- 53488 (Summon Enabler Stalker) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000100, `VerifiedBuild`=60257 WHERE (`Entry`=74721 AND `DifficultyID`=1); -- 74721 (Blindlight Bilefin) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75607 AND `DifficultyID`=1); -- 75607 (Ashelan Northwood) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60257 WHERE (`Entry`=74998 AND `DifficultyID`=1); -- 74998 (Invisible Man) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=75606 AND `DifficultyID`=1); -- 75606 (Sentinel Aluwyn) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=60257 WHERE (`Entry`=75000 AND `DifficultyID`=1); -- 75000 (Invisible Man) - Sessile, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74724 AND `DifficultyID`=1); -- 74724 (Blue Shale Crawler) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74979 AND `DifficultyID`=1); -- 74979 (Frightened Prisoner) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74720 AND `DifficultyID`=1); -- 74720 (Blindlight Murloc) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000000, `VerifiedBuild`=60257 WHERE (`Entry`=74988 AND `DifficultyID`=1); -- 74988 (Executioner Gore) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=75360;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(75360, 0.5, 0.625, 0, 59679);

UPDATE `creature_model_info` SET `BoundingRadius`=1.281331300735473632, `VerifiedBuild`=59679 WHERE `DisplayID`=4979;

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=75428 AND `MenuID`=16166);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(75428, 16166, 59679); -- Frightened Prisoner

-- Creature Equip
DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (75607,75606));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(75607, 1, 36606, 0, 0, 0, 0, 0, 0, 0, 0, 60257), -- Ashelan Northwood
(75606, 1, 52962, 0, 0, 0, 0, 0, 0, 0, 0, 60257); -- Sentinel Aluwyn

-- Spellscripts
DELETE FROM `spell_script_names` WHERE `spell_id` IN (155184, 151020, 153277, 146587);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(155184, 'spell_gen_feign_death_all_flags_uninteractible'),
(151020, 'spell_gen_feign_death_all_flags_uninteractible'),
(153277, 'spell_gen_feign_death_all_flags_uninteractible'),
(146587, 'spell_gen_feign_death_all_flags_uninteractible');

-- Vehicle
DELETE FROM `vehicle_template_accessory` WHERE `entry`IN (75086, 75780) AND `seat_id`=0;
INSERT INTO `vehicle_template_accessory` (`entry`, `accessory_entry`, `seat_id`, `minion`, `description`, `summontype`, `summontimer`, `RideSpellID`) VALUES
(75086, 75090, 0, 0, 'Deep Terror - Deep Terror', 8, 0, NULL),
(75780, 75781, 0, 0, 'Deep Terror - Deep Terror', 8, 0, NULL);

-- Spellclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (75086, 75780) AND `spell_id`=46598;
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=76062 AND `spell_id`=152782;
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `cast_flags`, `user_type`) VALUES
(75086, 46598, 1, 0),
(75780, 46598, 1, 0),
(76062, 152782, 3, 0);

-- Spawngroup
DELETE FROM `spawn_group_template` WHERE `groupId` IN (1265, 1266);
INSERT INTO `spawn_group_template` (`groupId`, `groupName`, `groupFlags`) VALUES
(1265, 'Blackfathom Deeps - Alliance Questgiver entrance', 32),
(1266, 'Blackfathom Deeps - Horde Questgiver entrance', 32);

DELETE FROM `spawn_group` WHERE `groupId` IN (1265, 1266);
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(1265, 0, @CGUID+277),
(1265, 0, @CGUID+278),
(1266, 0, @CGUID+4),
(1266, 0, @CGUID+3);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=33 AND `SourceGroup` = 0 AND `SourceEntry` IN (1265, 1266);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(33, 0, 1265, 0, 0, 11, 0, 4485, 1, 0, '', 0, 0, 0, '', 'BFD - Spawn Alliance NPCs if you are Alliance Player'),
(33, 0, 1266, 0, 0, 11, 0, 4486, 1, 0, '', 0, 0, 0, '', 'BFD - Spawn Horde NPCs if you are Horde Player');

-- Path for Blindlight Bilefin
SET @MOVERGUID := @CGUID+145;
SET @ENTRY := 74721;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Blindlight Bilefin - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -615.63574, 184.56567, -53.651443, NULL, 0),
(@PATH, 1, -620.20996, 182.94464, -53.881664, NULL, 0),
(@PATH, 2, -624.35815, 177.863, -54.488346, NULL, 4380),
(@PATH, 3, -620.20996, 182.94464, -53.881664, NULL, 0),
(@PATH, 4, -615.63574, 184.56567, -53.651443, NULL, 0),
(@PATH, 5, -607.7921, 183.5828, -53.978565, NULL, 4342);

UPDATE `creature` SET `position_x`=-615.63574, `position_y`=184.56567, `position_z`=-53.651443, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Twilight Aquamancer
SET @MOVERGUID := @CGUID+111;
SET @ENTRY := 74353;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Twilight Aquamancer - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -576.2246, 9.210975, -48.79748, NULL, 3703),
(@PATH, 1, -605.8611, 46.386097, -54.454456, NULL, 3752);

UPDATE `creature` SET `position_x`=-576.2246, `position_y`=9.210975, `position_z`=-48.79748, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
