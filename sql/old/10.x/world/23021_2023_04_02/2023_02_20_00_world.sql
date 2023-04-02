SET @CGUID := 9003226;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+111;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4211.8505859375, 2702.470458984375, 165.643096923828125, 0.434289664030075073, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+1, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4235.79345703125, 2681.10986328125, 150.0263671875, 1.344360828399658203, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+2, 195157, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4166.58544921875, 2673.771240234375, 173.4408416748046875, 4.5475616455078125, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 48069), -- Barbbed Crystalspine (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+3, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4307.57666015625, 2742.71533203125, 176.57257080078125, 5.046611785888671875, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+4, 192267, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4169.0126953125, 2726.482666015625, 165.1304473876953125, 2.81891632080078125, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48069), -- Azure Crystalspine (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+5, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4213.6884765625, 2670.965087890625, 165.7321319580078125, 3.772629261016845703, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+6, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4242.37646484375, 2711.66455078125, 151.8766632080078125, 1.661776900291442871, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+7, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4172.14697265625, 2740.5322265625, 165.5316009521484375, 5.903526782989501953, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+8, 195157, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4174.880859375, 2684.339599609375, 169.0303955078125, 0.213801190257072448, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 48069), -- Barbbed Crystalspine (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+9, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4249.15087890625, 2717.45849609375, 153.030517578125, 3.262069463729858398, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+10, 187575, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4070.208251953125, 2818.279541015625, 190.5749053955078125, 2.176314830780029296, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Trapped Vorquin (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+11, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4256.04931640625, 2673.98046875, 148.9407958984375, 6.207997322082519531, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+12, 195180, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4190.251953125, 2647.182373046875, 170.5604400634765625, 2.892724514007568359, 120, 0, 0, 41990, 2991, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+13, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4309.673828125, 2667.4462890625, 192.513397216796875, 0.64114534854888916, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+14, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4301.48779296875, 2716.634521484375, 156.0707550048828125, 2.16880345344543457, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+15, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4303.2216796875, 2721.427001953125, 155.8691253662109375, 0.172917351126670837, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+16, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4211.03125, 2646.432373046875, 178.35791015625, 6.083437442779541015, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+17, 195157, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4337.34130859375, 2735.5361328125, 157.242034912109375, 1.82335054874420166, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 48069), -- Barbbed Crystalspine (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+18, 195157, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4316.47216796875, 2680.27099609375, 160.1566314697265625, 2.869260787963867187, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 48069), -- Barbbed Crystalspine (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+19, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4316.978515625, 2665.441650390625, 161.7811431884765625, 0.320820510387420654, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+20, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4291.48291015625, 2649.994140625, 162.2578582763671875, 0.86344003677368164, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+21, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4313.234375, 2645.134521484375, 172.8873291015625, 4.268334865570068359, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+22, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4258.76025390625, 2631.3984375, 153.00360107421875, 0.113459542393684387, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+23, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4363.884765625, 2703.764404296875, 156.3873443603515625, 2.593083858489990234, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+24, 61325, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4368.318359375, 2697.807861328125, 154.919342041015625, 0.385007679462432861, 120, 10, 0, 1, 0, 1, 0, 0, 0, 48069), -- Adder (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+25, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4384.00537109375, 2619.4150390625, 178.8418731689453125, 5.524446487426757812, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+26, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4399.078125, 2622.0126953125, 148.5913848876953125, 2.468378067016601562, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+27, 195157, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4397.69140625, 2604.25390625, 149.513519287109375, 4.142812728881835937, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 48069), -- Barbbed Crystalspine (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+28, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4291.31884765625, 2608.11083984375, 165.436431884765625, 4.671559810638427734, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+29, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4379.92919921875, 2565.437255859375, 154.228759765625, 0.205634489655494689, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+30, 195157, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4321.55224609375, 2577.16650390625, 159.62298583984375, 2.118429183959960937, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 48069), -- Barbbed Crystalspine (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+31, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4355.76123046875, 2572.8271484375, 158.0794219970703125, 0.367454171180725097, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+32, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4358.333984375, 2566.146484375, 157.8403167724609375, 1.570796370506286621, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+33, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4297.73095703125, 2536.7421875, 205.3217620849609375, 0.868324756622314453, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+34, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4269.9482421875, 2596.6708984375, 157.808563232421875, 0.388482987880706787, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+35, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4295.1943359375, 2536.6171875, 199.391632080078125, 4.506357669830322265, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+36, 3300, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4322.5078125, 2560.964111328125, 162.8597869873046875, 3.913179636001586914, 120, 10, 0, 1, 0, 1, 0, 0, 0, 48069), -- Adder (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+37, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4368.8369140625, 2508.3056640625, 181.1074981689453125, 5.279808998107910156, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+38, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4335.49609375, 2547.108154296875, 163.0054931640625, 1.60987710952758789, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+39, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4339.79443359375, 2542.3515625, 160.836151123046875, 1.584467291831970214, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+40, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4303.78564453125, 2563.5419921875, 167.3995513916015625, 1.667064309120178222, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+41, 195163, 2444, 13646, 0, '0', 0, 0, 0, 0, -4380.0771484375, 2516.5390625, 164.254608154296875, 3.033046722412109375, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 48069), -- Azure Cryer (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+42, 195157, 2444, 13646, 0, '0', 0, 0, 0, 0, -4366.88037109375, 2509.536376953125, 165.0111541748046875, 1.594266176223754882, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 48069), -- Barbbed Crystalspine (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+43, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4375.8740234375, 2496.13037109375, 167.4701385498046875, 1.462675809860229492, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+44, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4321.2666015625, 2436.314208984375, 198.9516143798828125, 4.168862342834472656, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0) (Auras: 391254 - Hearty) (possible waypoints or random movement)
(@CGUID+45, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4295.45947265625, 2534.330322265625, 167.6557159423828125, 2.906887769699096679, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (Auras: 391254 - Hearty) (possible waypoints or random movement)
(@CGUID+46, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4303.126953125, 2504.209228515625, 168.7238311767578125, 5.060910224914550781, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+47, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4285.53271484375, 2521.015380859375, 183.1460723876953125, 4.99868011474609375, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+48, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4282.439453125, 2505.357666015625, 176.552398681640625, 3.720691680908203125, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (Auras: 391254 - Hearty)
(@CGUID+49, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4353.68310546875, 2448.59423828125, 173.608734130859375, 3.417345523834228515, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+50, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4280.53662109375, 2500.463134765625, 173.7683563232421875, 5.438046455383300781, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+51, 3300, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4339.802734375, 2451.3623046875, 171.8633270263671875, 0.567702174186706542, 120, 10, 0, 1, 0, 1, 0, 0, 0, 48069), -- Adder (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+52, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4263.47900390625, 2557.721435546875, 177.4149017333984375, 1.825109720230102539, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+53, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4333.33154296875, 2447.908203125, 172.1757659912109375, 1.873351931571960449, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+54, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4259.509765625, 2563.213623046875, 183.7916412353515625, 3.05177164077758789, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+55, 195157, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4252.466796875, 2535.496337890625, 173.1934814453125, 1.923738479614257812, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 48069), -- Barbbed Crystalspine (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+56, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4258.640625, 2559.2978515625, 179.489166259765625, 3.471705198287963867, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+57, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4296.48681640625, 2454.722412109375, 171.1009063720703125, 1.34710848331451416, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+58, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4223.392578125, 2492.75, 200.547698974609375, 2.331579446792602539, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+59, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4252.44140625, 2491.3828125, 175.8339385986328125, 5.468079566955566406, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+60, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4212.64599609375, 2500.59033203125, 201.999114990234375, 1.999914169311523437, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+61, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4252.86279296875, 2562.522705078125, 180.0658416748046875, 6.083437442779541015, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+62, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4331.13916015625, 2427.24658203125, 178.380950927734375, 4.4434814453125, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+63, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4214.7099609375, 2570.194580078125, 185.2623443603515625, 1.741789579391479492, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+64, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4283.46875, 2437.314208984375, 175.6943206787109375, 0.044160537421703338, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+65, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4244.71337890625, 2544.608154296875, 175.949310302734375, 3.340090036392211914, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+66, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4278.189453125, 2436.663330078125, 173.560546875, 5.525745868682861328, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+67, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4307.26904296875, 2399.8125, 182.993377685546875, 0.977453589439392089, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+68, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4221.10205078125, 2431.79541015625, 185.4755401611328125, 1.498045682907104492, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+69, 195180, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4306.06591796875, 2401.986083984375, 182.5072021484375, 0, 120, 0, 0, 41990, 2991, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+70, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4281.3212890625, 2380.399658203125, 199.3084259033203125, 1.953945279121398925, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+71, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4260.35400390625, 2431.19384765625, 177.8799285888671875, 6.080814838409423828, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+72, 195157, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4286.7607421875, 2391.35205078125, 182.3059234619140625, 1.870300889015197753, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 48069), -- Barbbed Crystalspine (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+73, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4280.2216796875, 2378.379150390625, 185.7504425048828125, 1.181444883346557617, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+74, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4293.9306640625, 2348.364501953125, 218.51068115234375, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+75, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4267.4716796875, 2399.642822265625, 181.2533111572265625, 3.849583625793457031, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+76, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4245.98291015625, 2372.46533203125, 187.50140380859375, 5.926384925842285156, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+77, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4250.83349609375, 2383.2744140625, 186.650177001953125, 6.271991729736328125, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+78, 3300, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4228.0791015625, 2419.608642578125, 184.3948516845703125, 0.768825113773345947, 120, 10, 0, 1, 0, 1, 0, 0, 0, 48069), -- Adder (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+79, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4228.384765625, 2388.98388671875, 188.0280914306640625, 0.334095597267150878, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+80, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4216.2373046875, 2429.021240234375, 184.074920654296875, 0.159848332405090332, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+81, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4207.98291015625, 2405.56591796875, 192.0597381591796875, 4.641986846923828125, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+82, 195163, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4226.513671875, 2476.286376953125, 183.302337646484375, 1.549315214157104492, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+83, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4211.47900390625, 2377.6025390625, 208.498321533203125, 3.592342138290405273, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+84, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4202.3427734375, 2530.530517578125, 186.057891845703125, 2.86835479736328125, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+85, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4196.34130859375, 2447.736572265625, 187.776123046875, 4.916008949279785156, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+86, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4232.439453125, 2508.779296875, 180.7894439697265625, 0.656774699687957763, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+87, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4180.7841796875, 2484.653564453125, 186.2248077392578125, 0.606128811836242675, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+88, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4172.15087890625, 2434.153076171875, 207.210693359375, 0.592333912849426269, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+89, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4175.697265625, 2478.1435546875, 188.974945068359375, 1.44741058349609375, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+90, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4162.08837890625, 2535.249267578125, 200.809326171875, 3.630257129669189453, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+91, 195157, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4175.17578125, 2503.08154296875, 186.0137481689453125, 3.387044906616210937, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 48069), -- Barbbed Crystalspine (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+92, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4152.830078125, 2448.33154296875, 204.393585205078125, 6.236660957336425781, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+93, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4145.13525390625, 2464.290771484375, 200.3946685791015625, 5.099063873291015625, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0) (Auras: 391254 - Hearty)
(@CGUID+94, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4168.86572265625, 2399.37353515625, 234.780731201171875, 2.23126983642578125, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+95, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4164.78662109375, 2525.41748046875, 190.4100341796875, 2.572016239166259765, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+96, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4138.429, 2594.932, 184.6999, 3.807716846466064453, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+97, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4138.429, 2594.932, 184.6999, 2.572016239166259765, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+98, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4118.5244140625, 2435.397705078125, 221.000274658203125, 4.575698375701904296, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+99, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4139.5068359375, 2404.7587890625, 244.6556243896484375, 3.592342376708984375, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+100, 193612, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4108.73388671875, 2460.528076171875, 216.0564117431640625, 1.660748958587646484, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Highpeaks Goat (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+101, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4234.0478515625, 2560.27197265625, 166.53216552734375, 4.602810382843017578, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+102, 192267, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4103.57958984375, 2520.07080078125, 203.7567596435546875, 1.059932112693786621, 120, 4, 0, 5, 0, 1, 0, 0, 0, 48069), -- Azure Crystalspine (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+103, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4219.353515625, 2569.263427734375, 165.32733154296875, 2.353432178497314453, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+104, 195151, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4133.19482421875, 2610.274169921875, 189.6019439697265625, 3.908645391464233398, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Perching Hunter (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+105, 195157, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4111.5458984375, 2633.2646484375, 184.2353363037109375, 5.224689483642578125, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 48069), -- Barbbed Crystalspine (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+106, 195157, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4119.2666015625, 2670.69677734375, 180.861602783203125, 2.079192638397216796, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 48069), -- Barbbed Crystalspine (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+107, 195150, 2444, 13646, 0, '0', 0, 0, 0, 0, -4190.619140625, 2645.2744140625, 170.910675048828125, 1.427232265472412109, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: 0 - Difficulty: 0)
(@CGUID+108, 195180, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4245.4755859375, 2578.338623046875, 162.1513519287109375, 2.892724514007568359, 120, 0, 0, 41990, 2991, 0, 0, 0, 0, 48069), -- Azure Cryer (Area: Traitor's Rest - Difficulty: 0) (Auras: 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune))
(@CGUID+109, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4249.20849609375, 2576.157958984375, 162.4102325439453125, 4.074855804443359375, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+110, 195150, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4245.75341796875, 2576.510498046875, 162.2897491455078125, 1.427232265472412109, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Grinning Cur (Area: Traitor's Rest - Difficulty: 0)
(@CGUID+111, 195373, 2444, 13646, 13844, '0', 0, 0, 0, 0, -4276.990234375, 2605.9794921875, 216.44659423828125, 4.703416824340820312, 120, 0, 0, 27, 0, 0, 0, 0, 0, 48069); -- Pepper Hammer (Area: Traitor's Rest - Difficulty: 0) (Auras: )
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+111;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+3, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+5, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+7, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+12, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Azure Cryer - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+13, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+14, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Grinning Cur
(@CGUID+16, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+19, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+21, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+25, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+32, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+33, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+35, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+37, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+40, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+44, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '391254'), -- Perching Hunter - 391254 - Hearty
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '391254'), -- Grinning Cur - 391254 - Hearty
(@CGUID+48, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, '391254'), -- Grinning Cur - 391254 - Hearty
(@CGUID+49, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Grinning Cur
(@CGUID+52, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+54, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+56, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+58, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+60, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+61, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+63, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+64, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Grinning Cur
(@CGUID+66, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Grinning Cur
(@CGUID+68, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+69, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Azure Cryer - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+70, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+76, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Highpeaks Goat
(@CGUID+77, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+82, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Azure Cryer
(@CGUID+84, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+90, 0, 0, 1, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+92, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Highpeaks Goat
(@CGUID+93, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '391254'), -- Highpeaks Goat - 391254 - Hearty
(@CGUID+98, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Highpeaks Goat
(@CGUID+101, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Grinning Cur
(@CGUID+104, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Perching Hunter
(@CGUID+108, 0, 0, 0, 0, 4, 1, 0, 0, 0, 0, 0, 0, '159474'), -- Azure Cryer - 159474 - Permanent Feign Death (NO Stun, Untrackable, Immune)
(@CGUID+109, 0, 0, 3, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Grinning Cur
(@CGUID+111, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Pepper Hammer

UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=195373; -- Pepper Hammer
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=7, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=193612; -- Highpeaks Goat
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=31, `BaseAttackTime`=2000, `unit_flags`=536904448, `unit_flags2`=67110913, `unit_flags3`=8192 WHERE `entry`=195180; -- Azure Cryer
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=2576, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=195163; -- Azure Cryer
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=195157; -- Barbbed Crystalspine
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=2106, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=195150; -- Grinning Cur
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=195151; -- Perching Hunter

-- Creature Movement
DELETE FROM `creature_template_movement` WHERE `CreatureID` IN (195373, 195151);
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(195373, 0, 0, 1, 0, 0, 0, NULL),
(195151, 0, 0, 1, 0, 0, 0, NULL);

-- Waypoints for CGUID+15
SET @PATH := (@CGUID+15) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4326.814, 2726.979, 157.8759, NULL, 0),
(@PATH, 1, -4317.268, 2721.312, 156.7052, NULL, 0),
(@PATH, 2, -4306.229, 2720.902, 155.9509, NULL, 0),
(@PATH, 3, -4291.806, 2723.423, 155.5153, NULL, 0),
(@PATH, 4, -4272.625, 2727.585, 155.0159, NULL, 0),
(@PATH, 5, -4265.141, 2734.292, 154.9411, NULL, 2434),
(@PATH, 6, -4282.583, 2754.837, 157.8437, NULL, 0),
(@PATH, 7, -4292.056, 2753.691, 157.6234, NULL, 0),
(@PATH, 8, -4309.537, 2749.512, 159.8941, NULL, 6964),
(@PATH, 9, -4314.063, 2741.667, 160.773, NULL, 0),
(@PATH, 10, -4325.554, 2738.984, 159.5191, NULL, 0);

UPDATE `creature` SET `position_x`= -4326.814, `position_y`= 2726.979, `position_z`= 157.8759, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+15;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+15;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+15, @PATH, 1);

-- Waypoints for CGUID+46
SET @PATH := (@CGUID+46) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4303.127, 2504.209, 168.7238, NULL, 2117),
(@PATH, 1, -4288.893, 2499.451, 167.2502, NULL, 0),
(@PATH, 2, -4288.29, 2499.221, 167.2608, NULL, 183),
(@PATH, 3, -4296.62, 2485.848, 168.6971, NULL, 990),
(@PATH, 4, -4283.821, 2486.83, 169.1356, NULL, 0),
(@PATH, 5, -4281.408, 2490.125, 169.2276, NULL, 3666),
(@PATH, 6, -4303.573, 2489.387, 168.4029, NULL, 0),
(@PATH, 7, -4307.601, 2495.299, 168.6292, NULL, 0),
(@PATH, 8, -4311.222, 2506.273, 167.8769, NULL, 0),
(@PATH, 9, -4305.948, 2512.98, 166.5105, NULL, 0);

UPDATE `creature` SET `position_x`= -4303.127, `position_y`= 2504.209, `position_z`= 168.7238, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+46;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+46;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+46, @PATH, 1);

-- Waypoints for CGUID+9
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+9;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+9, @CGUID+9, 0, 0, 515, 0, 0),
(@CGUID+9, @CGUID+6, 4, 0, 515, 0, 0);

SET @PATH := (@CGUID+9) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4282.912, 2694.457, 163.1742, NULL, 0),
(@PATH, 1, -4276.394, 2698.624, 162.2345, NULL, 0),
(@PATH, 2, -4270.281, 2714.786, 158.7636, NULL, 0),
(@PATH, 3, -4243.573, 2718.134, 152.2558, NULL, 0),
(@PATH, 4, -4241.568, 2694.206, 149.7404, NULL, 0),
(@PATH, 5, -4254.057, 2674.89, 148.924, NULL, 7833),
(@PATH, 6, -4241.568, 2694.206, 149.674, NULL, 0),
(@PATH, 7, -4243.573, 2718.134, 152.2558, NULL, 0),
(@PATH, 8, -4270.182, 2714.919, 158.7611, NULL, 0),
(@PATH, 9, -4276.394, 2698.624, 162.2345, NULL, 0),
(@PATH, 10, -4282.912, 2694.457, 163.1742, NULL, 0),
(@PATH, 11, -4298.075, 2700.285, 165.2602, NULL, 8047);

UPDATE `creature` SET `position_x`= -4282.912, `position_y`= 2694.457, `position_z`= 163.1742, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+9;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+9;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+9, @PATH, 1);

-- Waypoints for CGUID+95
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+95;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+95, @CGUID+95, 0, 0, 515, 0, 0),
(@CGUID+95, @CGUID+96, 6, 30, 515, 0, 0),
(@CGUID+95, @CGUID+97, 6, 330, 515, 0, 0);

SET @PATH := (@CGUID+95) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -4138.429, 2594.932, 184.6999, NULL, 0),
(@PATH, 1, -4126.434, 2573.929, 189.846, NULL, 0),
(@PATH, 2, -4123.031, 2545.889, 195.8732, NULL, 0),
(@PATH, 3, -4149.615, 2515.702, 194.008, NULL, 0),
(@PATH, 4, -4171.361, 2529.609, 186.8895, NULL, 0),
(@PATH, 5, -4196.949, 2550.491, 171.3997, NULL, 0),
(@PATH, 6, -4216.906, 2592.789, 160.7364, NULL, 0),
(@PATH, 7, -4228.698, 2632.544, 157.0086, NULL, 0),
(@PATH, 8, -4237.5, 2677.013, 149.3615, NULL, 0),
(@PATH, 9, -4223.226, 2718.688, 155.7813, NULL, 0),
(@PATH, 10, -4188.672, 2718.195, 159.5577, NULL, 0),
(@PATH, 11, -4160.441, 2709.962, 169.1994, NULL, 0),
(@PATH, 12, -4154.128, 2663.032, 176.9632, NULL, 0),
(@PATH, 13, -4152.415, 2618.303, 180.4322, NULL, 6522),
(@PATH, 14, -4154.128, 2663.032, 176.9632, NULL, 0),
(@PATH, 15, -4160.441, 2709.962, 169.1994, NULL, 0),
(@PATH, 16, -4188.672, 2718.195, 159.5577, NULL, 0),
(@PATH, 17, -4223.226, 2718.688, 155.7813, NULL, 0),
(@PATH, 18, -4237.5, 2677.013, 149.3615, NULL, 0),
(@PATH, 19, -4228.698, 2632.544, 157.0086, NULL, 0),
(@PATH, 20, -4216.906, 2592.789, 160.7364, NULL, 0),
(@PATH, 21, -4196.932, 2550.494, 171.5142, NULL, 0),
(@PATH, 22, -4171.344, 2529.611, 186.8734, NULL, 0),
(@PATH, 23, -4149.615, 2515.702, 194.008, NULL, 0),
(@PATH, 24, -4123.031, 2545.889, 195.8732, NULL, 0),
(@PATH, 25, -4126.434, 2573.929, 189.846, NULL, 0),
(@PATH, 26, -4138.429, 2594.932, 184.6999, NULL, 0),
(@PATH, 27, -4152.897, 2617.677, 180.4497, NULL, 0);

UPDATE `creature` SET `position_x`= -4138.429, `position_y`= 2594.932, `position_z`= 184.6999, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+95;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+95;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+95, @PATH, 1);
