SET @CGUID := 7000294;
SET @OGUID := 7000018;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+129;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 100161, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1514.8004150390625, 2090.989501953125, 242.975738525390625, 2.505118370056152343, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Legion Devastator (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+1, 101704, 1481, 7705, 7740, '0', 0, 0, 0, 0, 686.1805419921875, 2548.427978515625, -75.7154006958007812, 2.890496015548706054, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Empowered Fel Crystal (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+2, 101704, 1481, 7705, 7740, '0', 0, 0, 0, 0, 869.2569580078125, 2578.997314453125, -39.2085800170898437, 2.890496015548706054, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Empowered Fel Crystal (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+3, 93762, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1800.392333984375, 1569.828125, 87.13105010986328125, 2.614033699035644531, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Legion Devastator (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+4, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 703.1475830078125, 2641.513916015625, -71.26806640625, 3.101679325103759765, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+5, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 724.2181396484375, 2626.51123046875, -64.5419769287109375, 2.065718650817871093, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+6, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1111.2742919921875, 2680.05908203125, -85.8960113525390625, 4.677201747894287109, 120, 8, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+7, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 726.86260986328125, 2684.57275390625, -56.918060302734375, 3.641484975814819335, 120, 0, 0, 5, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+8, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 676.310791015625, 2533.799560546875, -79.9267730712890625, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+9, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 774.984375, 2541.229248046875, -71.0860824584960937, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+10, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 721.68402099609375, 2602.260498046875, -67.5101318359375, 1.16307222843170166, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+11, 101704, 1481, 7705, 7740, '0', 0, 0, 0, 0, 851.63018798828125, 2755.415771484375, -24.5067634582519531, 2.890496015548706054, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Empowered Fel Crystal (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+12, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 778.890625, 2570.184814453125, -70.8311691284179687, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+13, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 728.392333984375, 2565.970458984375, -71.2908706665039062, 0.339671969413757324, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 776.12847900390625, 2573.580810546875, -70.8311920166015625, 3.08228611946105957, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+15, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 751.09552001953125, 2570.650146484375, -70.6278839111328125, 5.452545642852783203, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+16, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 743.3955078125, 2542.026611328125, -68.9724655151367187, 0.526438891887664794, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+17, 94705, 1481, 7705, 7740, '0', 0, 0, 0, 1, 720.5509033203125, 2559.158447265625, -69.2248077392578125, 1.717803120613098144, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+18, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 608.8992919921875, 2483.157958984375, -79.7069854736328125, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+19, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 720.59722900390625, 2550.366455078125, -69.839874267578125, 1.352822542190551757, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+20, 97142, 1481, 7705, 7740, '0', 0, 0, 0, 0, 812.545166015625, 2558.103271484375, -50.187835693359375, 0, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Spreader (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200681 - Cosmetic - Random 7XP Fel Ground Crack A01 or A02 [scale x0.50])
(@CGUID+21, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 727.734375, 2504.7373046875, -66.598052978515625, 5.820758342742919921, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+22, 96400, 1481, 7705, 7740, '0', 0, 0, 0, 1, 845.71875, 2560.5009765625, -55.896575927734375, 4.524747848510742187, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Mo'arg Brute (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+23, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 691.3992919921875, 2540.887939453125, -77.6073684692382812, 5.567086696624755859, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+24, 101704, 1481, 7705, 7740, '0', 0, 0, 0, 0, 808.70831298828125, 2442.382080078125, -62.2083282470703125, 3.509678840637207031, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Empowered Fel Crystal (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+25, 99351, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1524.5833740234375, 1248.4757080078125, 78.3298492431640625, 0.096725940704345703, 120, 0, 0, 5647, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Legion Devastator Missile (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+26, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 811.607666015625, 2522.239501953125, -55.1407089233398437, 0.037979871034622192, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+27, 94704, 1481, 7705, 7740, '0', 0, 0, 0, 1, 818.98614501953125, 2519.772705078125, -57.7863235473632812, 5.71709442138671875, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+28, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 720.01739501953125, 2564.593017578125, -68.738922119140625, 4.81127786636352539, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+29, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 666.2257080078125, 2448.654541015625, -74.3717727661132812, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+30, 94705, 1481, 7705, 7740, '0', 0, 0, 0, 1, 724.23614501953125, 2555.50341796875, -69.9330291748046875, 5.370468616485595703, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+31, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 813.49481201171875, 2511.4697265625, -57.0398368835449218, 0.899337232112884521, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+32, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 728.56597900390625, 2549.903564453125, -68.46051025390625, 2.323580026626586914, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+33, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 713.828125, 2559.068603515625, -68.923004150390625, 3.190244197845458984, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+34, 94705, 1481, 7705, 7740, '0', 0, 0, 0, 1, 722.65106201171875, 2557.651123046875, -69.5788345336914062, 4.074540138244628906, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+35, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 792.7734375, 2548.352783203125, -70.14190673828125, 6.135212898254394531, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+36, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 818.01910400390625, 2449.303955078125, -60.3062362670898437, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+37, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 825.826416015625, 2515.428955078125, -60.3531723022460937, 2.38849496841430664, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+38, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 715.80035400390625, 2553.763916015625, -69.244476318359375, 0.840185761451721191, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+39, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 787.5501708984375, 2540.434326171875, -70.2646331787109375, 1.743853092193603515, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+40, 94377, 1481, 7705, 7740, '0', 4925, 0, 0, 0, 784.80902099609375, 2556.115478515625, -70.4079818725585937, 3.135047674179077148, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Cyana Nightglaive (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+41, 97142, 1481, 7705, 7740, '0', 0, 0, 0, 0, 724.8819580078125, 2508.56689453125, -66.7697906494140625, 0.990418970584869384, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Spreader (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200681 - Cosmetic - Random 7XP Fel Ground Crack A01 or A02 [scale x0.50])
(@CGUID+42, 101704, 1481, 7705, 7740, '0', 0, 0, 0, 0, 900.34552001953125, 2482.36279296875, -66.90435791015625, 3.901273250579833984, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Empowered Fel Crystal (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+43, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 788.11981201171875, 2521.74658203125, -59.98577880859375, 2.769697189331054687, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+44, 94704, 1481, 7705, 7740, '0', 0, 0, 0, 1, 817.62677001953125, 2518.3818359375, -57.5501632690429687, 2.571193933486938476, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+45, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 754.671875, 2567.015625, -69.21392822265625, 2.003484964370727539, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+46, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 820.87152099609375, 2528.451416015625, -57.4849739074707031, 4.523828506469726562, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+47, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 724.890625, 2511.853271484375, -66.8638076782226562, 1.769054889678955078, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+48, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 758.78125, 2493.59375, -67.560760498046875, 1.705380201339721679, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+49, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 770.4417724609375, 2493.4384765625, -65.6063995361328125, 2.749657154083251953, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+50, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 720.8629150390625, 2483.55810546875, -67.2875823974609375, 1.671964406967163085, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+51, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 687.8607177734375, 2496.469482421875, -64.9591140747070312, 5.632848739624023437, 120, 4, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+52, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 777.6163330078125, 2488.772705078125, -64.5592880249023437, 5.5130462646484375, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+53, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 671.45660400390625, 2385.857666015625, -73.6159820556640625, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+54, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 748.26043701171875, 2472.088623046875, -62.5730056762695312, 3.935703277587890625, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+55, 93105, 1481, 7705, 7740, '0', 0, 0, 0, 1, 592.58160400390625, 2432.890625, -72.1940078735351562, 3.19030618667602539, 120, 0, 0, 17083, 1534, 0, NULL, NULL, NULL, NULL, 51421), -- Inquisitor Baleful (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 204360 - Cosmetic - Soulgorged)
(@CGUID+56, 94400, 1481, 7705, 7740, '0', 4931, 0, 0, 0, 743.8125, 2467.5625, -62.9644508361816406, 6.068506717681884765, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Belath Dawnblade (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+57, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 699.921875, 2452.022705078125, -67.8506927490234375, 0.245456099510192871, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+58, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 701.40802001953125, 2454.138916015625, -67.4114532470703125, 6.092394351959228515, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+59, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 809.0113525390625, 2456.118408203125, -59.0572853088378906, 2.67821049690246582, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+60, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 805.5399169921875, 2453.045166015625, -58.9226150512695312, 2.841375589370727539, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+61, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 830.32464599609375, 2472.520751953125, -55.8187103271484375, 2.405482053756713867, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+62, 101748, 1481, 7705, 7740, '0', 0, 0, 0, 0, 653.685791015625, 2357.2587890625, -73.8222198486328125, 0.122197546064853668, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Fel Geyser (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+63, 97594, 1481, 7705, 7740, '0', 0, 0, 0, 0, 767.99652099609375, 2433.088623046875, -59.9923248291015625, 2.9993743896484375, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+64, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 842.64306640625, 2485.652587890625, -58.456573486328125, 5.412866592407226562, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+65, 97592, 1481, 7705, 7740, '0', 0, 0, 0, 1, 770.890625, 2403.59716796875, -60.2691802978515625, 1.832386016845703125, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+66, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 782.396484375, 2415.90625, -59.0141258239746093, 1.113476037979125976, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+67, 101704, 1481, 7705, 7740, '0', 0, 0, 0, 0, 959.248291015625, 2501.064208984375, -69.051544189453125, 2.890496015548706054, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Empowered Fel Crystal (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200882 - Visual)
(@CGUID+68, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 867.42706298828125, 2491.817626953125, -58.337371826171875, 1.947656512260437011, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+69, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 712.3975830078125, 2425.47216796875, -66.549835205078125, 0.874155998229980468, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+70, 24021, 1481, 7705, 7740, '0', 0, 0, 0, 0, 774.670166015625, 2388.9462890625, -55.3671035766601562, 1.615941643714904785, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51421), -- ELM General Purpose Bunny (scale x0.01) (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+71, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 850.7530517578125, 2404.57958984375, -52.0062637329101562, 5.874868392944335937, 120, 10, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+72, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 747.02740478515625, 2385.611328125, -60.5574264526367187, 2.766393423080444335, 120, 0, 0, 5, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+73, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 711.33160400390625, 2427.62841796875, -67.1776580810546875, 0.779378354549407958, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: ) (possible waypoints or random movement)
(@CGUID+74, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 804.15118408203125, 2350.269775390625, -55.878143310546875, 2.533825397491455078, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+75, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 717.2257080078125, 2367.1494140625, -61.5453224182128906, 4.921953201293945312, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+76, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 748.9110107421875, 2350.80859375, -62.1968841552734375, 5.332595348358154296, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+77, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 675.63018798828125, 2454.630126953125, -72.4127273559570312, 0.635104954242706298, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+78, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 700.02642822265625, 2362.47802734375, -66.4420242309570312, 4.207536220550537109, 120, 0, 0, 5, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+79, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 685.33685302734375, 2373.4736328125, -72.5990447998046875, 1.312961578369140625, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+80, 101288, 1481, 7705, 7740, '0', 0, 0, 0, 0, 659.02606201171875, 2475.9462890625, -69.5978775024414062, 3.44576430320739746, 120, 4, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Abyssal Basilisk (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+81, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 671.586669921875, 2383.81103515625, -74.4124679565429687, 3.069761991500854492, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+82, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 673.0185546875, 2376.36376953125, -73.850006103515625, 2.546547889709472656, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+83, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 651.16143798828125, 2416.236083984375, -74.4586334228515625, 4.331264019012451171, 120, 0, 0, 5, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+84, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 680.08502197265625, 2333.3330078125, -65.6512069702148437, 3.141592741012573242, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+85, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 675.77789306640625, 2326.7607421875, -63.2224922180175781, 4.885081768035888671, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+86, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 657.12335205078125, 2332.8291015625, -68.4766082763671875, 5.52264404296875, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+87, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 641.3680419921875, 2357.885498046875, -72.45556640625, 1.653881549835205078, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+88, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 683.1820068359375, 2322.04931640625, -66.9907379150390625, 4.415216922760009765, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+89, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 646.5003662109375, 2327.607666015625, -74.0891952514648437, 1.103636860847473144, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+90, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 649.322998046875, 2485.212646484375, -79.271209716796875, 5.407039165496826171, 120, 10, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+91, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 657.01910400390625, 2321.859375, -70.5279388427734375, 5.15083169937133789, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish) (possible waypoints or random movement)
(@CGUID+92, 96400, 1481, 7705, 7740, '0', 0, 0, 0, 1, 622.36456298828125, 2351.5556640625, -72.3597564697265625, 1.20625007152557373, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Mo'arg Brute (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+93, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 587.2965087890625, 2418.483154296875, -70.872833251953125, 4.285918235778808593, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+94, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 595.84027099609375, 2490.647705078125, -73.5553359985351562, 5.15083169937133789, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+95, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 602.310791015625, 2375.43408203125, -71.3903961181640625, 0.46358230710029602, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+96, 94651, 1481, 7705, 7740, '0', 0, 0, 0, 0, 594.9691162109375, 2501.10546875, -84.2200927734375, 1.025486350059509277, 120, 6, 0, 1243, 3801, 1, NULL, NULL, NULL, NULL, 51421), -- Hellish Imp (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 200372 - Hellish)
(@CGUID+97, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 580.74444580078125, 2360.3818359375, -72.1720046997070312, 2.612393617630004882, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+98, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 580.3350830078125, 2479.3427734375, -71.425079345703125, 1.350220441818237304, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+99, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 850.4320068359375, 2342.5, -48.8568229675292968, 4.69892740249633789, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+100, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 908.0164794921875, 2479.31787109375, -65.9530258178710937, 0.882936418056488037, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+101, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 920.80206298828125, 2447.88720703125, -69.81585693359375, 5.5778961181640625, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+102, 93230, 1481, 7705, 7740, '0', 4927, 0, 0, 0, 910.38543701171875, 2473.609375, -66.552337646484375, 3.508423566818237304, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Mannethrel Darkstar (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+103, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 900.19964599609375, 2520.203125, -59.2559967041015625, 3.017223119735717773, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+104, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 905.88714599609375, 2467.420166015625, -66.566497802734375, 0.847090303897857666, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+105, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 934.484375, 2541.452392578125, -55.4511299133300781, 6.169494152069091796, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+106, 94704, 1481, 7705, 7740, '0', 0, 0, 0, 1, 945.82293701171875, 2543.856689453125, -53.827239990234375, 3.35019540786743164, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+107, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 933.1475830078125, 2546.431396484375, -57.3190803527832031, 5.860684871673583984, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+108, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 895.59552001953125, 2532.501708984375, -58.8618659973144531, 3.754224061965942382, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+109, 94705, 1481, 7705, 7740, '0', 0, 0, 0, 1, 947.54168701171875, 2539.96435546875, -53.701812744140625, 2.714356422424316406, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Demon Hunter (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 222589 - Glaive Anim Replacement, 151597 - No NPC Damage Below 45-90%)
(@CGUID+110, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 938.890625, 2531.669189453125, -56.1672134399414062, 0.712100505828857421, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+111, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 935.670166015625, 2535.377685546875, -55.98150634765625, 0.369032442569732666, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: 151597 - No NPC Damage Below 45-90%)
(@CGUID+112, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 912.632568359375, 2545.12744140625, -59.8159637451171875, 2.462733983993530273, 120, 0, 0, 5, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+113, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 879.1925048828125, 2557.44970703125, -51.7525634765625, 4.235692501068115234, 120, 0, 0, 5, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+114, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 882.07183837890625, 2577.910888671875, -56.2125320434570312, 4.423254013061523437, 120, 0, 0, 1129, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+115, 95226, 1481, 7705, 7740, '0', 0, 0, 0, 0, 876.78472900390625, 2576.497314453125, -56.7383956909179687, 1.273130536079406738, 120, 0, 0, 4348, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Anguish Jailer (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+116, 93117, 1481, 7705, 7740, '0', 4932, 0, 0, 0, 879.36285400390625, 2584.901123046875, -56.706451416015625, 3.992730140686035156, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51421), -- Izal Whitemoon (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+117, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 997.85418701171875, 2612.895751953125, -60.6213607788085937, 3.093807220458984375, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+118, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 949.125, 2593.734375, -58.4112968444824218, 3.196338653564453125, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51485), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+119, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 952.8507080078125, 2588.684814453125, -59.1456108093261718, 3.959872722625732421, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51485), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+120, 94655, 1481, 7705, 7740, '0', 0, 0, 0, 0, 980.984375, 2546.1337890625, -46.4631195068359375, 3.774551630020141601, 120, 8, 0, 1129, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Soul Leech (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+121, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1030.361083984375, 2544.067626953125, -39.345489501953125, 0.828900337219238281, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51485), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1
(@CGUID+122, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 982.84893798828125, 2537.442626953125, -44.8555526733398437, 2.840184688568115234, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51485), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+123, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 996.00518798828125, 2563.9765625, -41.9175224304199218, 3.720093488693237304, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51485), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+124, 93112, 1481, 7705, 7740, '0', 0, 0, 0, 1, 1033.154541015625, 2543.7275390625, -39.0434036254882812, 0.87449049949645996, 120, 0, 0, 3106, 0, 0, NULL, NULL, NULL, NULL, 51485), -- Felguard Sentry (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+125, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1060.8021240234375, 2554.94970703125, -35.5891799926757812, 2.352654933929443359, 120, 6, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+126, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1062.99658203125, 2661.22998046875, -77.9292984008789062, 0.646911680698394775, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+127, 99650, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1042.2413330078125, 2619.85498046875, -69.849822998046875, 0.856969892978668212, 120, 8, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Thornclaw Broodling (Area: Molten Shore - Difficulty: 0) CreateObject2
(@CGUID+128, 93115, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1024.092041015625, 2633.796875, -62.987518310546875, 1.566091179847717285, 120, 10, 0, 3106, 0, 1, NULL, NULL, NULL, NULL, 51485), -- Foul Felstalker (Area: Molten Shore - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+129, 99656, 1481, 7705, 7740, '0', 0, 0, 0, 0, 1060.5416259765625, 2678.30908203125, -75.5465011596679687, 5.168666839599609375, 120, 8, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 51485); -- Red Broodling (Area: Molten Shore - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+129;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+65, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'); -- Felguard Sentry - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+7;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 242987, 1481, 7705, 7740, '0', 0, 0, 879.4461669921875, 2584.973876953125, -56.7891921997070312, 3.992181777954101562, 0, 0, -0.91091728210449218, 0.412589073181152343, 120, 255, 1, 51421), -- Jailer Cage (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+1, 241756, 1481, 7705, 7740, '0', 0, 0, 775.185791015625, 2389.072998046875, -58.26275634765625, 1.698262214660644531, -0.03015041351318359, -0.0547800064086914, 0.748689651489257812, 0.659965097904205322, 120, 255, 1, 51421), -- Legion Gateway Activator (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+2, 242990, 1481, 7705, 7740, '0', 0, 0, 910.420166015625, 2473.604248046875, -66.6402816772460937, 3.505491256713867187, 0, 0, -0.98349285125732421, 0.180946916341781616, 120, 255, 1, 51421), -- Jailer Cage (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+3, 244916, 1481, 7705, 7740, '0', 0, 0, 784.71875, 2556.1728515625, -70.4913177490234375, 3.14776921272277832, 0, 0, -0.99999523162841796, 0.003088161814957857, 120, 255, 1, 51421), -- Jailer Cage (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+4, 244440, 1481, 7705, 7740, '0', 0, 0, 751.732666015625, 2460.9306640625, -62.3934745788574218, 0.118905484676361083, 0, 0, 0.059417724609375, 0.998233199119567871, 120, 255, 1, 51421), -- Legion Communicator (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+5, 242989, 1481, 7705, 7740, '0', 0, 0, 743.80206298828125, 2467.59375, -63.0486335754394531, 6.061135768890380859, 0, 0, -0.11079692840576171, 0.99384307861328125, 120, 255, 1, 51421), -- Jailer Cage (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+6, 244439, 1481, 7705, 7740, '0', 0, 0, 937.61981201171875, 2835.83154296875, 1.292487740516662597, 1.279170751571655273, 0, 0, 0.59686279296875, 0.802343368530273437, 120, 255, 1, 51421), -- Legion Communicator (Area: Molten Shore - Difficulty: 0) CreateObject1
(@OGUID+7, 244441, 1481, 7705, 7740, '0', 0, 0, 1246.9132080078125, 2522.4609375, 1.859429240226745605, 3.22068643569946289, 0.08490610122680664, -0.00177192687988281, -0.99562549591064453, 0.038957837969064712, 120, 255, 1, 51421); -- Legion Communicator (Area: Molten Shore - Difficulty: 0) CreateObject1

-- GameObject Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (244441 /*Legion Communicator*/, 244439 /*Legion Communicator*/, 242989 /*Jailer Cage*/, 244440 /*Legion Communicator*/, 244916 /*Jailer Cage*/, 242990 /*Jailer Cage*/, 241756 /*Legion Gateway Activator*/, 242987 /*Jailer Cage*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(244441, 0, 262176, 0, 0), -- Legion Communicator
(244439, 0, 262176, 0, 0), -- Legion Communicator
(242989, 0, 262176, 0, 0), -- Jailer Cage
(244440, 0, 262176, 0, 0), -- Legion Communicator
(244916, 0, 262176, 0, 0), -- Jailer Cage
(242990, 0, 262176, 0, 0), -- Jailer Cage
(241756, 0, 262176, 0, 0), -- Legion Gateway Activator
(242987, 0, 262176, 0, 0); -- Jailer Cage

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (94651, 93105, 95226, 94704, 94705);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(94651, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '200372'), -- 94651 (Hellish Imp) - Hellish
(93105, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- 93105 (Inquisitor Baleful) - Cosmetic - Soulgorged
(95226, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '151597'), -- 95226 (Anguish Jailer) - No NPC Damage Below 45-90%
(94704, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589 151597'), -- 94704 (Demon Hunter) - Glaive Anim Replacement, No NPC Damage Below 45-90%
(94705, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '222589 151597'); -- 94705 (Demon Hunter) - Glaive Anim Replacement, No NPC Damage Below 45-90%

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureId` = 101704;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(101704, 0, 0, 1, 0, 0, 0, NULL);

-- Phasing
DELETE FROM `phase_area` WHERE `PhaseId` IN (4925, 4931, 4927, 4932) AND `AreaId` = 7705;
INSERT INTO `phase_area` (`AreaId`, `PhaseId`, `Comment`) VALUES
(7705, 4925, 'Cyana Nightglaive caged Molten Shore'),
(7705, 4931, 'Belath Dawnblade caged Molten Shore'),
(7705, 4927, 'Mannethrel Darkstar caged Molten Shore'),
(7705, 4932, 'Izal Whitemoon caged Molten Shore');

-- Conditions
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4925 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4925, 0, 0, 0, 47, 0, 40378, 2|64, 0, 1, 'Apply Phase 4925 if Quest 38759 is not complete | rewarded'),
(26, 4925, 0, 0, 0, 48, 0, 280293, 0, 1, 1, 'Apply Phase 4925 if Questobjective 280293 (Cyana Nightglaive) is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4931 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4931, 0, 0, 0, 47, 0, 40378, 2|64, 0, 1, 'Apply Phase 4931 if Quest 38759 is not complete | rewarded'),
(26, 4931, 0, 0, 0, 48, 0, 278928, 0, 1, 1, 'Apply Phase 4931 if Questobjective 278928 (Belath Dawnblade) is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4927 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4927, 0, 0, 0, 47, 0, 40378, 2|64, 0, 1, 'Apply Phase 4927 if Quest 38759 is not complete | rewarded'),
(26, 4927, 0, 0, 0, 48, 0, 278413, 0, 1, 1, 'Apply Phase 4927 if Questobjective 278413 (Mannethrel Darkstar) is not rewarded');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId`=26 AND `SourceGroup` = 4932 AND `SourceEntry` = 0);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `Comment`) VALUES
(26, 4932, 0, 0, 0, 47, 0, 40378, 2|64, 0, 1, 'Apply Phase 4932 if Quest 38759 is not complete | rewarded'),
(26, 4932, 0, 0, 0, 48, 0, 278929, 0, 1, 1, 'Apply Phase 4932 if Questobjective 278929 (Izal Whitemoon) is not rewarded');

-- Demon Hunter smart ai
SET @ENTRY := 94704;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack');

SET @ENTRY := 94705;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack');

-- Demons smartAI
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (93112, 93115, 95226);
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+32), -(@CGUID+19), -(@CGUID+38), -(@CGUID+33), -(@CGUID+28), -(@CGUID+31), -(@CGUID+26), -(@CGUID+46), -(@CGUID+37), -(@CGUID+107), -(@CGUID+105), -(@CGUID+111), -(@CGUID+110));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+32), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+19), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+38), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+33), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+28), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+31), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+26), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+46), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+37), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+107), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+105), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+111), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack'),
(-(@CGUID+110), 0, 0, 0, 1, 0, 100, 0, 1000, 1000, 1000, 1000, 49, 0, 0, 0, 0, 0, 0, 25, 10, 0, 0, 0, 0, 0, 0, 'Every 1 seconds (OOC) - Closest enemy creature in 10 yards: Start Attack');

-- Serverside Spells
DELETE FROM `serverside_spell` WHERE `Id` IN (204714, 204715, 204711, 204712);
INSERT INTO `serverside_spell` (`Id`, `DifficultyID`, `CategoryId`, `Dispel`, `Mechanic`, `Attributes`, `AttributesEx`, `AttributesEx2`, `AttributesEx3`, `AttributesEx4`, `AttributesEx5`, `AttributesEx6`, `AttributesEx7`, `AttributesEx8`, `AttributesEx9`, `AttributesEx10`, `AttributesEx11`, `AttributesEx12`, `AttributesEx13`, `AttributesEx14`, `Stances`, `StancesNot`, `Targets`, `TargetCreatureType`, `RequiresSpellFocus`, `FacingCasterFlags`, `CasterAuraState`, `TargetAuraState`, `ExcludeCasterAuraState`, `ExcludeTargetAuraState`, `CasterAuraSpell`, `TargetAuraSpell`, `ExcludeCasterAuraSpell`, `ExcludeTargetAuraSpell`, `CasterAuraType`, `TargetAuraType`, `ExcludeCasterAuraType`, `ExcludeTargetAuraType`, `CastingTimeIndex`, `RecoveryTime`, `CategoryRecoveryTime`, `StartRecoveryCategory`, `StartRecoveryTime`, `InterruptFlags`, `AuraInterruptFlags1`, `AuraInterruptFlags2`, `ChannelInterruptFlags1`, `ChannelInterruptFlags2`, `ProcFlags`, `ProcFlags2`, `ProcChance`, `ProcCharges`, `ProcCooldown`, `ProcBasePPM`, `MaxLevel`, `BaseLevel`, `SpellLevel`, `DurationIndex`, `RangeIndex`, `Speed`, `LaunchDelay`, `StackAmount`, `EquippedItemClass`, `EquippedItemSubClassMask`, `EquippedItemInventoryTypeMask`, `ContentTuningId`, `SpellName`, `ConeAngle`, `ConeWidth`, `MaxTargetLevel`, `MaxAffectedTargets`, `SpellFamilyName`, `SpellFamilyFlags1`, `SpellFamilyFlags2`, `SpellFamilyFlags3`, `SpellFamilyFlags4`, `DmgClass`, `PreventionType`, `AreaGroupId`, `SchoolMask`, `ChargeCategoryId`) VALUES
(204714, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Set Them Free: Izal Whitemoon Freed Kill Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(204715, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Set Them Free: Mannethrel Darkstar Freed Kill Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(204711, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Set Them Free: Cyana Nightglaive Freed Kill Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0),
(204712, 0, 0, 0, 0, 0, 0, 0, 0, 0x00000080, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -1, 0, 0, 0, 'Set Them Free: Belath Dawnblade Freed Kill Credit', 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);

DELETE FROM `serverside_spell_effect` WHERE `SpellID` IN (204714, 204715, 204711, 204712) AND `EffectIndex` = 0;
INSERT INTO `serverside_spell_effect` (`SpellID`, `EffectIndex`, `DifficultyID`, `Effect`, `EffectAura`, `EffectAmplitude`, `EffectAttributes`, `EffectAuraPeriod`, `EffectBonusCoefficient`, `EffectChainAmplitude`, `EffectChainTargets`, `EffectItemType`, `EffectMechanic`, `EffectPointsPerResource`, `EffectPosFacing`, `EffectRealPointsPerLevel`, `EffectTriggerSpell`, `BonusCoefficientFromAP`, `PvpMultiplier`, `Coefficient`, `Variance`, `ResourceCoefficient`, `GroupSizeBasePointsCoefficient`, `EffectBasePoints`, `EffectMiscValue1`, `EffectMiscValue2`, `EffectRadiusIndex1`, `EffectRadiusIndex2`, `EffectSpellClassMask1`, `EffectSpellClassMask2`, `EffectSpellClassMask3`, `EffectSpellClassMask4`, `ImplicitTarget1`, `ImplicitTarget2`) VALUES
(204714, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 93117, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(204715, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 93230, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(204711, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94377, 0, 0, 0, 0, 0, 0, 0, 1, 0),
(204712, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 94400, 0, 0, 0, 0, 0, 0, 0, 1, 0);

-- Objective completion effect
DELETE FROM `quest_objectives_completion_effect` WHERE `ObjectiveID` IN (278413, 278928, 278929, 280293);
INSERT INTO `quest_objectives_completion_effect` (`ObjectiveID`, `GameEventID`, `SpellID`, `ConversationID`, `UpdatePhaseShift`, `UpdateZoneAuras`) VALUES
(278413, NULL, NULL, NULL, 1, 0),
(278928, NULL, NULL, NULL, 1, 0),
(278929, NULL, NULL, NULL, 1, 0),
(280293, NULL, NULL, NULL, 1, 0);

-- Waypoints for CGUID+15
SET @ENTRY := 95226;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 730.9236, 2635.785, -61.66982, NULL, 0),
(@PATH, 1, 731.9948, 2647.705, -59.80316, NULL, 0),
(@PATH, 2, 732.8715, 2655.212, -58.73685, NULL, 11655),
(@PATH, 3, 731.9948, 2647.705, -59.80316, NULL, 0),
(@PATH, 4, 730.9236, 2635.785, -61.66982, NULL, 0),
(@PATH, 5, 729.9219, 2622.674, -63.41138, NULL, 0),
(@PATH, 6, 730.0816, 2605.233, -65.8267, NULL, 0),
(@PATH, 7, 733.8924, 2592.903, -68.18188, NULL, 0),
(@PATH, 8, 741.0018, 2581.665, -69.03427, NULL, 0),
(@PATH, 9, 751.0955, 2570.65, -70.62788, NULL, 11774),
(@PATH, 10, 741.0018, 2581.665, -69.03427, NULL, 0),
(@PATH, 11, 733.8924, 2592.903, -68.18188, NULL, 0),
(@PATH, 12, 730.0816, 2605.233, -65.8267, NULL, 0),
(@PATH, 13, 729.9219, 2622.674, -63.41138, NULL, 0);

UPDATE `creature` SET `position_x`= 730.9236, `position_y`= 2635.785, `position_z`= -61.66982, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+15;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+15;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+15, @PATH, 1);

-- Waypoint for CGUID+16
SET @ENTRY := 95226;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 718.257, 2523.542, -71.65739, NULL, 0),
(@PATH, 1, 731.3646, 2535.028, -71.03369, NULL, 0),
(@PATH, 2, 750.9809, 2546.435, -69.064, NULL, 0),
(@PATH, 3, 768.6992, 2557.714, -70.30438, NULL, 0),
(@PATH, 4, 773.2726, 2559.714, -70.48952, NULL, 0),
(@PATH, 5, 777.8195, 2558.717, -70.49082, NULL, 20305),
(@PATH, 6, 773.2726, 2559.714, -70.48952, NULL, 0),
(@PATH, 7, 768.7361, 2557.748, -70.32924, NULL, 0),
(@PATH, 8, 750.9809, 2546.435, -69.064, NULL, 0),
(@PATH, 9, 731.3646, 2535.028, -71.03369, NULL, 0),
(@PATH, 10, 718.257, 2523.542, -71.65739, NULL, 0),
(@PATH, 11, 715.7465, 2518.943, -72.43728, NULL, 11632);

UPDATE `creature` SET `position_x`= 718.257, `position_y`= 2523.542, `position_z`= -71.65739, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+16;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+16;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+16, @PATH, 1);

-- Waypoints for CGUID+52
SET @ENTRY := 95226;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, 750.0955, 2503.064, -67.21629, NULL, 0),
(@PATH, 1, 760.8837, 2502.564, -66.86293, NULL, 0),
(@PATH, 2, 770.8629, 2495.41, -65.83532, NULL, 0),
(@PATH, 3, 777.6163, 2488.773, -64.55929, NULL, 14148),
(@PATH, 4, 770.8629, 2495.41, -65.83532, NULL, 0),
(@PATH, 5, 760.8837, 2502.564, -66.86293, NULL, 0),
(@PATH, 6, 750.0955, 2503.064, -67.21629, NULL, 0),
(@PATH, 7, 738.4549, 2498.04, -67.27545, NULL, 0),
(@PATH, 8, 731.1077, 2491.45, -67.30695, NULL, 0),
(@PATH, 9, 724.7691, 2480.991, -67.28758, NULL, 0),
(@PATH, 10, 721.6424, 2471.071, -67.25008, NULL, 0),
(@PATH, 11, 721.8455, 2459.281, -66.11234, NULL, 0),
(@PATH, 12, 725.467, 2449.91, -65.11401, NULL, 0),
(@PATH, 13, 738.2778, 2444.851, -63.89267, NULL, 0),
(@PATH, 14, 748.9583, 2443.33, -63.12173, NULL, 0),
(@PATH, 15, 760.2778, 2444.455, -62.15059, NULL, 18284),
(@PATH, 16, 748.9583, 2443.33, -63.12173, NULL, 0),
(@PATH, 17, 738.2778, 2444.851, -63.89267, NULL, 0),
(@PATH, 18, 725.467, 2449.91, -65.11401, NULL, 0),
(@PATH, 19, 721.8633, 2459.236, -66.18636, NULL, 0),
(@PATH, 20, 721.6424, 2471.071, -67.25008, NULL, 0),
(@PATH, 21, 724.7691, 2480.991, -67.28758, NULL, 0),
(@PATH, 22, 731.1077, 2491.45, -67.30695, NULL, 0),
(@PATH, 23, 738.4549, 2498.04, -67.27545, NULL, 0);

UPDATE `creature` SET `position_x`= 750.0955, `position_y`= 2503.064, `position_z`= -67.21629, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+52;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+52;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+52, @PATH, 1);
