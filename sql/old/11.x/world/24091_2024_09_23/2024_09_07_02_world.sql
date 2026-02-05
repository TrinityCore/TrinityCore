SET @CGUID := 10001719;
SET @OGUID := 10000301;

SET @NPCTEXTID := 600011;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+97;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 219150, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2353.86279296875, -2647.361083984375, 190.347198486328125, 4.5439910888671875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+1, 226224, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2319.7587890625, -2676.9375, 193.2548065185546875, 3.981282472610473632, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Forgegrounds Worker (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+2, 219180, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2292.36328125, -2601.333984375, 191.3491973876953125, 1.509398221969604492, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Cornerdweller (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+3, 219180, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2275.458984375, -2492.143310546875, 195.8531646728515625, 1.409483075141906738, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Cornerdweller (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+4, 219180, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2294.046142578125, -2571.403076171875, 190.141693115234375, 5.675129890441894531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Cornerdweller (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+5, 229927, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2340.897705078125, -2560.234375, 199.66973876953125, 2.263186216354370117, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 459180 - [DNT] Earthen Laborer Carry Cosmetic)
(@CGUID+6, 229927, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2362.697998046875, -2635.54345703125, 181.496673583984375, 2.744360685348510742, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+7, 219180, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2343.0341796875, -2600.339599609375, 190.644500732421875, 4.353372097015380859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Cornerdweller (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+8, 219382, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2357.278564453125, -2590.2626953125, 181.6656494140625, 2.149456501007080078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+9, 219150, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2273.991455078125, -2496.638916015625, 195.8531494140625, 3.792924880981445312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 436812 - Carrying Crate [DNT])
(@CGUID+10, 219151, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2356.729248046875, -2581.788330078125, 181.4966888427734375, 2.793790102005004882, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+11, 219150, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2355.5556640625, -2615.833251953125, 181.4966888427734375, 3.250143051147460937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+12, 229927, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2360.810791015625, -2634.751708984375, 181.496673583984375, 5.885953426361083984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT])
(@CGUID+13, 219151, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2296.328125, -2499.71875, 199.6061553955078125, 1.475012540817260742, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+14, 219180, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2335.701416015625, -2571.116943359375, 190.1421051025390625, 5.110941886901855468, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Cornerdweller (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+15, 219150, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2377.319580078125, -2542.1650390625, 182.37060546875, 0.44134223461151123, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+16, 219150, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2318.75, -2668.833984375, 190.1421051025390625, 4.712388992309570312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+17, 219382, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2338.78125, -2558.23095703125, 199.66973876953125, 6.228725910186767578, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 459770 - [DNT] Earthen Carry Cosmetic Random, 382759 - Conversation Aura: Talk Only [DNT])
(@CGUID+18, 219151, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2299.034423828125, -2542.387939453125, 199.331573486328125, 6.168309688568115234, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+19, 219180, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2311.857666015625, -2662.977783203125, 190.142120361328125, 0.000740055402275174, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Cornerdweller (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+20, 226224, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2316.204833984375, -2673.848876953125, 190.225433349609375, 1.12424015998840332, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Forgegrounds Worker (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+21, 226224, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2314.09716796875, -2659.545166015625, 190.2254486083984375, 2.869104385375976562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Forgegrounds Worker (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+22, 219180, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2322.9169921875, -2677.083984375, 190.142120361328125, 3.504083156585693359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Cornerdweller (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+23, 226224, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2314.526123046875, -2671.967041015625, 190.225433349609375, 5.068048954010009765, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Forgegrounds Worker (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+24, 229927, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2298.47705078125, -2620.891357421875, 190.1424560546875, 1.617825746536254882, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+25, 219150, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2355.048583984375, -2580.9619140625, 181.496673583984375, 5.914702892303466796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+26, 219150, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2301.154541015625, -2556.734375, 199.483856201171875, 5.733943462371826171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+27, 229927, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2386.244873046875, -2574.880126953125, 182.2740020751953125, 3.47468113899230957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+28, 219151, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2394.694580078125, -2556.145751953125, 181.49127197265625, 5.544882774353027343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+29, 219180, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2293.228515625, -2527.083984375, 199.254852294921875, 3.837195873260498046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Cornerdweller (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+30, 219151, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2353.848876953125, -2649.217041015625, 190.3448333740234375, 1.851560115814208984, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+31, 219180, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2270.853515625, -2628.237548828125, 191.4625244140625, 3.546666383743286132, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Cornerdweller (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+32, 219382, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2343.8369140625, -2495.817626953125, 199.3381805419921875, 3.165543317794799804, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+33, 219382, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2384.6650390625, -2536.515625, 181.41314697265625, 1.954768776893615722, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+34, 219382, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2284.992919921875, -2586.855712890625, 191.5871734619140625, 0.403910160064697265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+35, 219382, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2339.302001953125, -2622.482666015625, 190.5157318115234375, 1.358306407928466796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+36, 219382, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2341.798583984375, -2495.866455078125, 199.3381805419921875, 0.023950384929776191, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT])
(@CGUID+37, 219382, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2338.460205078125, -2589.032958984375, 190.49774169921875, 5.937212467193603515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 463530 - [DNT] Flavor - Holding Gem)
(@CGUID+38, 219382, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2385.7275390625, -2576.59375, 182.242431640625, 2.512468814849853515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT])
(@CGUID+39, 219382, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2360.239501953125, -2561.757080078125, 181.567779541015625, 2.392238855361938476, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 463521 - [DNT] Flavor - Holding Ingot)
(@CGUID+40, 219382, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2341.710205078125, -2558.390625, 199.66973876953125, 2.968693733215332031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 459770 - [DNT] Earthen Carry Cosmetic Random)
(@CGUID+41, 219088, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2298.453125, -2573.723876953125, 190.2270355224609375, 5.56817626953125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Uthaga (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+42, 219387, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2340.661376953125, -2593.385498046875, 190.496368408203125, 3.241416215896606445, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Belga (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+43, 219089, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2309.92529296875, -2558.428955078125, 199.4368896484375, 1.060198068618774414, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Kardu (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+44, 219090, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2307.0556640625, -2558.279541015625, 199.4647674560546875, 1.433295130729675292, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Brrigan (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+45, 219091, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2308.435791015625, -2526.84033203125, 199.3381805419921875, 5.3060150146484375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Grink (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+46, 219334, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2314.140625, -2501.263916015625, 199.3381805419921875, 1.428107857704162597, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Freysworn Arborist (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+47, 219383, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2310.598876953125, -2651.625, 190.3296661376953125, 0.82410132884979248, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Malukh (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 452224 - Cosmetic - Reading Book - All Races [DNT])
(@CGUID+48, 219385, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2339.31591796875, -2616.416748046875, 190.486175537109375, 3.39575052261352539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Nerada (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+49, 217088, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2276.482666015625, -2574.6025390625, 191.5135040283203125, 1.525740981101989746, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Nernabel (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+50, 230110, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2309.882080078125, -2573.99658203125, 190.2233123779296875, 2.093092203140258789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Kirin Tor Crystalshaper (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+51, 217090, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2276.7275390625, -2548.63720703125, 199.4884185791015625, 1.55078589916229248, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Loldren (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+52, 226777, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2310.442626953125, -2647.845458984375, 190.225433349609375, 4.132022857666015625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Professor Pallin (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 452224 - Cosmetic - Reading Book - All Races [DNT])
(@CGUID+53, 219085, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2301.62158203125, -2644.494873046875, 190.2254486083984375, 1.204764485359191894, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Nagad (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+54, 219086, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2296.26904296875, -2632.95654296875, 190.225799560546875, 0.177240297198295593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Llande (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+55, 219087, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2308.59716796875, -2572.2900390625, 190.224090576171875, 5.388869762420654296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Makir (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+56, 219249, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2298.25341796875, -2558.364501953125, 199.453857421875, 0.72074514627456665, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Dogan (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: 458385 - [DNT] Female Earthen/Dwarf Taking Notes)
(@CGUID+57, 226732, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2270.982666015625, -2610.223876953125, 191.5344085693359375, 2.267348289489746093, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Hagatha Moorehead (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+58, 219390, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2355.73095703125, -2535.545166015625, 199.3381805419921875, 2.402045011520385742, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Gortra (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+59, 226733, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2278.5244140625, -2608.3681640625, 191.5344085693359375, 0.811259567737579345, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Endora Moorehead (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+60, 219092, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2312.77783203125, -2521.744873046875, 199.3381805419921875, 5.702303409576416015, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Tarig (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+61, 226734, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2281.3212890625, -2612.083251953125, 192.9552459716796875, 2.91370701789855957, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Badluck (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+62, 220674, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2310.6337890625, -2493.682373046875, 198.498779296875, 1.844522953033447265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- [DNT] Watering Beam Stalker (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+63, 220674, 2552, 14771, 14771, '0', '0', 0, 0, 0, 2319.7744140625, -2493.204833984375, 209.985015869140625, 1.587289810180664062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- [DNT] Watering Beam Stalker (Area: Dornogal - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+64, 219382, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2411.0625, -2568.736083984375, 181.49127197265625, 3.436902284622192382, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 463521 - [DNT] Flavor - Holding Ingot)
(@CGUID+65, 229927, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2388.182373046875, -2521.439208984375, 199.384918212890625, 5.4217071533203125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+66, 227073, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2349.279541015625, -2490.501708984375, 199.2577667236328125, 6.113698959350585937, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56461), -- Molvzira (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+67, 229379, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2304.522705078125, -2649.013916015625, 190.2254486083984375, 1.365419745445251464, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Villager (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 452224 - Cosmetic - Reading Book - All Races [DNT])
(@CGUID+68, 229379, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2356.866455078125, -2635.703125, 183.7164306640625, 0.77998131513595581, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Villager (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+69, 229927, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2407.366455078125, -2545.904541015625, 181.5457305908203125, 0.838715732097625732, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+70, 219382, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2389.583251953125, -2523.0087890625, 200.477569580078125, 2.512468814849853515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT])
(@CGUID+71, 219382, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2422.083251953125, -2611.932373046875, 181.49127197265625, 1.582080602645874023, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+72, 220674, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2317.76220703125, -2480.23095703125, 204.150787353515625, 1.844522953033447265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- [DNT] Watering Beam Stalker (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+73, 219150, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2386.791748046875, -2505.23095703125, 199.254852294921875, 0.214764982461929321, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+74, 219334, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2336.5400390625, -2475.017333984375, 200.6531982421875, 3.010880470275878906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Freysworn Arborist (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+75, 229379, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2388.21875, -2494.55908203125, 199.3803253173828125, 5.55316019058227539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Villager (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+76, 219093, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2323.6025390625, -2471.68408203125, 200.6531982421875, 5.076449871063232421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Vorig (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+77, 229379, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2317.939208984375, -2471.458251953125, 200.723388671875, 1.451171875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Villager (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+78, 219254, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2388.819580078125, -2497.703125, 199.438507080078125, 2.811736583709716796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Parnith (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+79, 220674, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2314.35595703125, -2473.748291015625, 205.1726837158203125, 1.587289810180664062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- [DNT] Watering Beam Stalker (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+80, 219101, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2329.89404296875, -2473.298583984375, 200.6531982421875, 4.086390495300292968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Akdan (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+81, 219334, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2321.225830078125, -2474.454833984375, 200.6531982421875, 3.039106369018554687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Freysworn Arborist (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+82, 219150, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2402.788330078125, -2507.42529296875, 181.4951171875, 2.964183568954467773, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+83, 219382, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2407.119873046875, -2497.12158203125, 181.495147705078125, 5.346004486083984375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 463535 - [DNT] Inspect Gem)
(@CGUID+84, 227072, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2361.710205078125, -2471.33154296875, 199.338623046875, 5.573934555053710937, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Barzvitz (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+85, 229927, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2377.819580078125, -2468.1806640625, 199.3381805419921875, 2.263186216354370117, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 459180 - [DNT] Earthen Laborer Carry Cosmetic)
(@CGUID+86, 219382, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2378.632080078125, -2466.3369140625, 199.3381805419921875, 2.968693733215332031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 459770 - [DNT] Earthen Carry Cosmetic Random)
(@CGUID+87, 219382, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2375.703125, -2466.17529296875, 199.3381805419921875, 6.228060722351074218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 459770 - [DNT] Earthen Carry Cosmetic Random, 382759 - Conversation Aura: Talk Only [DNT])
(@CGUID+88, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2378.08251953125, -2595.78125, 181.4133148193359375, 4.7100372314453125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+89, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 4, 2323.904296875, -2611.4912109375, 190.13409423828125, 4.678479671478271484, 120, 10, 0, 1, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection) (possible waypoints or random movement)
(@CGUID+90, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 5, 2355.982177734375, -2505.93994140625, 199.254852294921875, 3.939965724945068359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+91, 219275, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2352.90966796875, -2616.3056640625, 181.569549560546875, 0.416329294443130493, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Dern (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+92, 219255, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2392.64404296875, -2526.052001953125, 181.61822509765625, 5.55438232421875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Karbath (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+93, 219274, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2352.5244140625, -2619.79345703125, 181.608306884765625, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Brakh (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+94, 219256, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2366.685791015625, -2554.116455078125, 181.558868408203125, 5.497240543365478515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Badur (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+95, 219273, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2353.022705078125, -2587.951416015625, 181.6050567626953125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Breek (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+96, 226779, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2356.4775390625, -2624.682373046875, 181.4966888427734375, 2.683548212051391601, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Halga Steelbarrow (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+97, 219247, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2399.888916015625, -2502.416748046875, 181.4951171875, 0.356605798006057739, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461); -- Unak (Area: The Forgegrounds - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+97;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 0, 27161, 0, 0, 0, ''), -- Forgegrounds Worker
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '459180'), -- Unbound Crafter - 459180 - [DNT] Earthen Laborer Carry Cosmetic
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436812'), -- Oathsworn Citizen - 436812 - Carrying Crate [DNT]
(@CGUID+11, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Oathsworn Citizen
(@CGUID+12, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '435518'), -- Unbound Crafter - 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT]
(@CGUID+15, 0, 0, 0, 0, 0, 1, 0, 1021, 0, 0, 0, 0, ''), -- Oathsworn Citizen
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '459770 382759'), -- Unbound Trader - 459770 - [DNT] Earthen Carry Cosmetic Random, 382759 - Conversation Aura: Talk Only [DNT]
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Forgegrounds Worker
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 0, 27161, 0, 0, 0, ''), -- Forgegrounds Worker
(@CGUID+23, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Forgegrounds Worker
(@CGUID+27, 0, 0, 0, 0, 0, 1, 0, 0, 2085, 0, 0, 0, ''), -- Unbound Crafter
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '436812'), -- Oathsworn Citizen - 436812 - Carrying Crate [DNT]
(@CGUID+33, 0, 0, 0, 0, 0, 1, 0, 569, 25374, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+35, 0, 0, 0, 0, 0, 1, 0, 0, 30852, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '435518'), -- Unbound Trader - 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT]
(@CGUID+37, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '463530'), -- Unbound Trader - 463530 - [DNT] Flavor - Holding Gem
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 0, 2085, 0, 0, 0, '435518'), -- Unbound Trader - 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT]
(@CGUID+39, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '463521'), -- Unbound Trader - 463521 - [DNT] Flavor - Holding Ingot
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '459770'), -- Unbound Trader - 459770 - [DNT] Earthen Carry Cosmetic Random
(@CGUID+64, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '463521'), -- Unbound Trader - 463521 - [DNT] Flavor - Holding Ingot
(@CGUID+67, 0, 0, 0, 0, 0, 1, 0, 0, 8998, 0, 0, 0, '452224'), -- Unbound Villager - 452224 - Cosmetic - Reading Book - All Races [DNT]
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 426, 0, 0, 0, 0, ''), -- Unbound Villager
(@CGUID+69, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Unbound Crafter
(@CGUID+70, 0, 0, 0, 0, 0, 1, 0, 0, 2085, 0, 0, 0, '435518'), -- Unbound Trader - 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT]
(@CGUID+71, 0, 0, 0, 0, 0, 1, 0, 720, 0, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+75, 0, 0, 0, 0, 0, 1, 0, 483, 0, 0, 0, 0, ''), -- Unbound Villager
(@CGUID+82, 0, 0, 0, 0, 0, 1, 0, 606, 0, 0, 0, 0, ''), -- Oathsworn Citizen
(@CGUID+83, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '463535'), -- Unbound Trader - 463535 - [DNT] Inspect Gem
(@CGUID+85, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '459180'), -- Unbound Crafter - 459180 - [DNT] Earthen Laborer Carry Cosmetic
(@CGUID+86, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '459770'), -- Unbound Trader - 459770 - [DNT] Earthen Carry Cosmetic Random
(@CGUID+87, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '459770 382759'); -- Unbound Trader - 459770 - [DNT] Earthen Carry Cosmetic Random, 382759 - Conversation Aura: Talk Only [DNT]

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+11;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 433868, 2552, 14771, 15043, '0', '0', 0, 2282.26953125, -2487.53564453125, 195.6896514892578125, 3.918267250061035156, 0, 0, -0.92553997039794921, 0.378649920225143432, 120, 255, 1, 56461), -- Alchemy Table (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+1, 433873, 2552, 14771, 15043, '0', '0', 0, 2275.0908203125, -2535.1923828125, 199.6295166015625, 5.454157352447509765, 0, 0, -0.40274524688720703, 0.915312111377716064, 120, 255, 1, 56461), -- Inscription Table (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+2, 441163, 2552, 14771, 15043, '0', '0', 0, 862.810791015625, -2091.192626953125, 131.1217498779296875, 1.232055544853210449, 0.27150583267211914, 0.156063079833984375, 0.556610107421875, 0.769489526748657226, 120, 255, 1, 56461), -- Dormant Rock Giant (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+3, 430484, 2552, 14771, 15043, '0', '0', 0, 2337.9931640625, -2494.04345703125, 199.122772216796875, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 56461), -- Mailbox (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+4, 441170, 2552, 14771, 15043, '0', '0', 0, 1089.90283203125, -1622.91845703125, 75.974761962890625, 3.426843643188476562, -0.21815156936645507, -0.16581153869628906, -0.94667911529541015, 0.169455230236053466, 120, 255, 1, 56461), -- Dormant Rock Giant (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+5, 429068, 2552, 14771, 15043, '0', '0', 0, 2296.1494140625, -2338.529541015625, 181.589691162109375, 0.759216904640197753, 0, 0, 0.370556831359863281, 0.928809821605682373, 120, 255, 1, 56461), -- Bench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+6, 429070, 2552, 14771, 15043, '0', '0', 0, 2346.31591796875, -2342.0869140625, 181.685150146484375, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 56461), -- Bench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+7, 459295, 2552, 14771, 15043, '0', '0', 0, 2242.55517578125, -2357.0009765625, 198.5645904541015625, 5.489060401916503906, 0, 0, -0.38671112060546875, 0.922200918197631835, 120, 255, 1, 56461), -- Bench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+8, 459296, 2552, 14771, 15043, '0', '0', 0, 2241.461181640625, -2355.91015625, 219.022613525390625, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 56461), -- Bench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+9, 429737, 2552, 14771, 15043, '0', '0', 0, 2332.192626953125, -2338.8994140625, 181.5892791748046875, 2.129300594329833984, 0, 0, 0.874619483947753906, 0.484810054302215576, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+10, 439315, 2552, 14771, 15043, '0', '0', 0, 2518.49658203125, -2463.460205078125, 200.2258148193359375, 5.015543460845947265, 0, 0, -0.59222793579101562, 0.805770456790924072, 120, 255, 1, 56461), -- Collector's Cache (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+11, 429071, 2552, 14771, 15043, '0', '0', 0, 2346.541748046875, -2322.125, 181.8417510986328125, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 56461); -- Bench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+11;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.923879504203796386, 0.38268357515335083, 0, 0), -- Alchemy Table
(@OGUID+1, 0, 0, 1, -0.00000004371138828, 0, 0), -- Inscription Table
(@OGUID+7, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Bench
(@OGUID+8, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0); -- Bench

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (226734 /*226734 (Badluck)*/, 219249 /*219249 (Dogan) - [DNT] Female Earthen/Dwarf Taking Notes*/, 226777 /*226777 (Professor Pallin) - Cosmetic - Reading Book - All Races [DNT]*/, 217090 /*217090 (Loldren)*/, 230110 /*230110 (Kirin Tor Crystalshaper)*/, 219383 /*219383 (Malukh) - Cosmetic - Reading Book - All Races [DNT]*/, 220674 /*220674 ([DNT] Watering Beam Stalker)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(226734, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 226734 (Badluck)
(219249, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '458385'), -- 219249 (Dogan) - [DNT] Female Earthen/Dwarf Taking Notes
(226777, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '452224'), -- 226777 (Professor Pallin) - Cosmetic - Reading Book - All Races [DNT]
(217090, 0, 0, 0, 0, 0, 1, 0, 0, 27930, 0, 0, 0, ''), -- 217090 (Loldren)
(230110, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 230110 (Kirin Tor Crystalshaper)
(219383, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '452224'), -- 219383 (Malukh) - Cosmetic - Reading Book - All Races [DNT]
(220674, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 220674 ([DNT] Watering Beam Stalker)

-- Template
UPDATE `creature_template` SET `faction`=35, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226734; -- Badluck
UPDATE `creature_template` SET `faction`=3407, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219092; -- Tarig
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226733; -- Endora Moorehead
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219390; -- Gortra
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226732; -- Hagatha Moorehead
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219249; -- Dogan
UPDATE `creature_template` SET `faction`=3407, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219087; -- Makir
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219086; -- Llande
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1073741824 WHERE `entry`=217090; -- Loldren
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=230110; -- Kirin Tor Crystalshaper
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=217088; -- Nernabel
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33555200, `unit_flags2`=67110912, `unit_flags3`=1090519040 WHERE `entry`=198464; -- Rostrum of Transformation
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219334; -- Freysworn Arborist
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=219378; -- Stabled Ramolith
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=33554688, `unit_flags2`=2048, `unit_flags3`=16777216, `flags_extra` = 128 WHERE `entry`=220674; -- [DNT] Watering Beam Stalker
UPDATE `creature_template` SET `faction`=3407, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219273; -- Breek
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=1090519040 WHERE `entry`=219991; -- Ruufus
UPDATE `creature_template` SET `faction`=3408, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=8388608 WHERE `entry`=219166; -- Oathsworn Peacekeeper
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=226224; -- Forgegrounds Worker
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219091; -- Grink
UPDATE `creature_template` SET `faction`=3407, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219090; -- Brrigan
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219089; -- Kardu
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219387; -- Belga
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219088; -- Uthaga
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219256; -- Badur
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=227072; -- Barzvitz
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219247; -- Unak
UPDATE `creature_template` SET `faction`=3407, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219101; -- Akdan
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219254; -- Parnith
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219093; -- Vorig
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223643; -- Borgos
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223650; -- Forge Hand
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219255; -- Karbath
UPDATE `creature_template` SET `faction`=3407, `npcflag`=82, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=223644; -- Darean
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=227073; -- Molvzira
UPDATE `creature_template` SET `faction`=188, `npcflag`=1073741824, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=222713; -- Magmashell Crawler

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226734 AND `DifficultyID`=0); -- 226734 (Badluck) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219092 AND `DifficultyID`=0); -- 219092 (Tarig) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226733 AND `DifficultyID`=0); -- 226733 (Endora Moorehead) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219390 AND `DifficultyID`=0); -- 219390 (Gortra) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226732 AND `DifficultyID`=0); -- 226732 (Hagatha Moorehead) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219249 AND `DifficultyID`=0); -- 219249 (Dogan) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219087 AND `DifficultyID`=0); -- 219087 (Makir) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219086 AND `DifficultyID`=0); -- 219086 (Llande) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306624, `StaticFlags3`=33554432, `VerifiedBuild`=56461 WHERE (`Entry`=217090 AND `DifficultyID`=0); -- 217090 (Loldren) - Sessile, CanSwim, Floating - CannotTurn
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=230110 AND `DifficultyID`=0); -- 230110 (Kirin Tor Crystalshaper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=217088 AND `DifficultyID`=0); -- 217088 (Nernabel) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219334 AND `DifficultyID`=0); -- 219334 (Freysworn Arborist) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=536870912, `VerifiedBuild`=56461 WHERE (`Entry`=220674 AND `DifficultyID`=0); -- 220674 ([DNT] Watering Beam Stalker) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219273 AND `DifficultyID`=0); -- 219273 (Breek) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=536871168, `VerifiedBuild`=56461 WHERE (`Entry`=219991 AND `DifficultyID`=0); -- 219991 (Ruufus) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2803, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219166 AND `DifficultyID`=0); -- 219166 (Oathsworn Peacekeeper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219091 AND `DifficultyID`=0); -- 219091 (Grink) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219090 AND `DifficultyID`=0); -- 219090 (Brrigan) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219089 AND `DifficultyID`=0); -- 219089 (Kardu) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219387 AND `DifficultyID`=0); -- 219387 (Belga) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219088 AND `DifficultyID`=0); -- 219088 (Uthaga) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219256 AND `DifficultyID`=0); -- 219256 (Badur) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=227072 AND `DifficultyID`=0); -- 227072 (Barzvitz) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219247 AND `DifficultyID`=0); -- 219247 (Unak) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219101 AND `DifficultyID`=0); -- 219101 (Akdan) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219254 AND `DifficultyID`=0); -- 219254 (Parnith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219093 AND `DifficultyID`=0); -- 219093 (Vorig) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=223643 AND `DifficultyID`=0); -- 223643 (Borgos) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219255 AND `DifficultyID`=0); -- 219255 (Karbath) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=223644 AND `DifficultyID`=0); -- 223644 (Darean) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=227073 AND `DifficultyID`=0); -- 227073 (Molvzira) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=222713 AND `DifficultyID`=0); -- 222713 (Magmashell Crawler) - CanSwim

-- model
DELETE FROM `creature_model_info` WHERE `DisplayID`=121169;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(121169, 2.675816059112548828, 4, 0, 56461);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=219256 AND `MenuID`=34039) OR (`CreatureID`=219390 AND `MenuID` = 35156) OR (`CreatureID`=219101 AND `MenuID`=36351) OR (`CreatureID`=219092 AND `MenuID`=36362) OR (`CreatureID`=217090 AND `MenuID`=34157) OR (`CreatureID`=219090 AND `MenuID`=36361) OR (`CreatureID`=219087 AND `MenuID`=36359) OR (`CreatureID`=217088 AND `MenuID`=34183) OR (`CreatureID`=219085 AND `MenuID`=36347);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(219256, 34039, 56461), -- Badur
(219390, 35156, 56461), -- Gortra
(219101, 36351, 56461), -- Akdan
(219092, 36362, 56461), -- Tarig
(217090, 34157, 56461), -- Loldren
(219090, 36361, 56461), -- Brrigan
(219087, 36359, 56461), -- Makir
(217088, 34183, 56461), -- Nernabel
(219085, 36347, 56461); -- Nagad

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+5;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 266030, 0, 0, 0, 0, 0, 0, 0, 56461), -- 219390 (Gortra)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 258184, 0, 0, 0, 0, 0, 0, 0, 56461), -- 217090 (Loldren)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 266032, 0, 0, 0, 0, 0, 0, 0, 56461), -- 219390 (Gortra)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 266033, 0, 0, 0, 0, 0, 0, 0, 56461), -- 219390 (Gortra)
(@NPCTEXTID+4, 1, 0, 0, 0, 0, 0, 0, 0, 258186, 0, 0, 0, 0, 0, 0, 0, 56461), -- 217088 (Nernabel)
(@NPCTEXTID+5, 1, 0, 0, 0, 0, 0, 0, 0, 257693, 0, 0, 0, 0, 0, 0, 0, 56461); -- 219256 (Badur)

DELETE FROM `gossip_menu` WHERE (`MenuID`=35156 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=34157 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=35157 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=35158 AND `TextID`=@NPCTEXTID+3) OR (`MenuID`=34183 AND `TextID`=@NPCTEXTID+4) OR (`MenuID`=34039 AND `TextID`=@NPCTEXTID+5);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(35156, @NPCTEXTID+0, 56461), -- 219390 (Gortra)
(34157, @NPCTEXTID+1, 56461), -- 217090 (Loldren)
(35157, @NPCTEXTID+2, 56461), -- 219390 (Gortra)
(35158, @NPCTEXTID+3, 56461), -- 219390 (Gortra)
(34183, @NPCTEXTID+4, 56461), -- 217088 (Nernabel)
(34039, @NPCTEXTID+5, 56461); -- 219256 (Badur)

DELETE FROM `gossip_menu` WHERE (`TextID`=14126 AND `MenuID` IN (36351,36362,36361,36359,36347));
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(36351, 14126, 56461), -- 219101 (Akdan)
(36362, 14126, 56461), -- 219092 (Tarig)
(36361, 14126, 56461), -- 219090 (Brrigan)
(36359, 14126, 56461), -- 219087 (Makir)
(36347, 14126, 56461); -- 219085 (Nagad)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (36361,35157,35156,36351,36362,36347,35158,36359)) OR (`OptionID`=1 AND `MenuID`=35156);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(36361, 124248, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(35157, 122733, 0, 0, 'Let\'s talk about something else.', 172206, 0, 0, 35156, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461), -- OptionBroadcastTextID: 172206 - 174968
(35156, 122731, 1, 0, 'Tell me about the Rostrum of Transformation.', 0, 0, 0, 35158, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(35156, 122732, 0, 0, 'How do I customize my mount?', 0, 0, 0, 35157, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(36351, 124240, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(36362, 124249, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(36347, 124234, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(35158, 122734, 0, 0, 'Let\'s talk about something else.', 172206, 0, 0, 35156, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461), -- OptionBroadcastTextID: 172206 - 174968
(36359, 124247, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461);

-- Trainer
DELETE FROM `creature_trainer` WHERE (`CreatureID`=219092 AND `MenuID`=36362 AND `OptionID`=0) OR (`CreatureID`=219087 AND `MenuID`=36359 AND `OptionID`=0) OR (`CreatureID`=219085 AND `MenuID`=36347 AND `OptionID`=0) OR (`CreatureID`=219090 AND `MenuID`=36361 AND `OptionID`=0) OR (`CreatureID`=219101 AND `MenuID`=36351 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(219092, 1114, 36362, 0),
(219087, 1122, 36359, 0),
(219085, 1117, 36347, 0),
(219090, 1121, 36361, 0),
(219101, 1120, 36351, 0);

DELETE FROM `trainer` WHERE `Id` IN (1120, 1114, 1121, 1122, 1117);
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(1120, 2, 'Hello, friend!', 56461),
(1114, 2, 'Hello, friend!', 56461),
(1121, 2, 'Hello, friend!', 56461),
(1122, 2, 'Hello, friend!', 56461),
(1117, 2, 'Hello, friend!', 56461);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=1120 AND `SpellId` IN (423349,265820)) OR (`TrainerId`=1114 AND `SpellId` IN (264212,462122,462121,423322)) OR (`TrainerId`=1121 AND `SpellId` IN (444203,444222,444221,444215,444214,444213,444212,444211,444210,444208,444206,444204,444201,444200,444196,444191,444190,423350,264495)) OR (`TrainerId`=1122 AND `SpellId` IN (423351,435377,435375,435373,435371,434540,434539,434538,434537,435337,435380,435379,435324,435327,435326,435325,435323,434563,434549,434547,434542,264533)) OR (`TrainerId`=1117 AND `SpellId` IN (423346,445361,445360,445365,445374,445338,445351,445385,445317,445379,445324,445371,445373,445348,445344,445376,445392,445340,445381,445358,264457));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(1120, 423349, 950000, 182, 1, 0, 0, 0, 68, 56461), -- No Faction found! MoneyCost not recalculated!
(1120, 265820, 10, 0, 0, 0, 0, 0, 5, 56461), -- No Faction found! MoneyCost not recalculated!
(1114, 264212, 10, 0, 0, 0, 0, 0, 5, 56461), -- No Faction found! MoneyCost not recalculated!
(1114, 462122, 1187500, 2871, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1114, 462121, 997500, 2871, 5, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1114, 423322, 950000, 171, 1, 0, 0, 0, 68, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444203, 2565000, 2878, 50, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444222, 1045000, 2878, 10, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444221, 1330000, 2878, 15, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444215, 2280000, 2878, 45, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444214, 2280000, 2878, 45, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444213, 1900000, 2878, 35, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444212, 1900000, 2878, 35, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444211, 1520000, 2878, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444210, 1520000, 2878, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444208, 1520000, 2878, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444206, 1520000, 2878, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444204, 1520000, 2878, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444201, 1425000, 2878, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444200, 1425000, 2878, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444196, 1425000, 2878, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444191, 1425000, 2878, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 444190, 1520000, 2878, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 423350, 950000, 773, 1, 0, 0, 0, 68, 56461), -- No Faction found! MoneyCost not recalculated!
(1121, 264495, 10, 0, 0, 0, 0, 0, 5, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 423351, 950000, 755, 1, 0, 0, 0, 68, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 435377, 1187500, 2879, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 435375, 1187500, 2879, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 435373, 1140000, 2879, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 435371, 1092500, 2879, 15, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 434540, 1045000, 2879, 10, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 434539, 1045000, 2879, 10, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 434538, 997500, 2879, 5, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 434537, 950000, 2879, 1, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 435337, 1425000, 2879, 50, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 435380, 1092500, 2879, 15, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 435379, 1045000, 2879, 10, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 435324, 950000, 2879, 1, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 435327, 1187500, 2879, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 435326, 1092500, 2879, 15, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 435325, 1187500, 2879, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 435323, 1092500, 2879, 15, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 434563, 1140000, 2879, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 434549, 1140000, 2879, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 434547, 1140000, 2879, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 434542, 1140000, 2879, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1122, 264533, 10, 0, 0, 0, 0, 0, 5, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 423346, 950000, 333, 1, 0, 0, 0, 68, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445361, 950000, 2874, 15, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445360, 1140000, 2874, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445365, 1235000, 2874, 30, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445374, 1615000, 2874, 50, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445338, 1045000, 2874, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445351, 1045000, 2874, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445385, 1425000, 2874, 40, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445317, 1710000, 2874, 55, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445379, 1710000, 2874, 55, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445324, 1425000, 2874, 40, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445371, 760000, 2874, 10, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445373, 1615000, 2874, 50, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445348, 1330000, 2874, 35, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445344, 950000, 2874, 15, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445376, 1235000, 2874, 30, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445392, 760000, 2874, 10, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445340, 1520000, 2874, 45, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445381, 1140000, 2874, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 445358, 570000, 2874, 5, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1117, 264457, 10, 0, 0, 0, 0, 0, 5, 56461); -- No Faction found! MoneyCost not recalculated!

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=219274 AND `item`=227701 AND `ExtendedCost`=9121 AND `type`=1) OR (`entry`=219274 AND `item`=227700 AND `ExtendedCost`=9121 AND `type`=1) OR (`entry`=219274 AND `item`=227699 AND `ExtendedCost`=9121 AND `type`=1) OR (`entry`=219255 AND `item`=227701 AND `ExtendedCost`=9121 AND `type`=1) OR (`entry`=219255 AND `item`=227700 AND `ExtendedCost`=9121 AND `type`=1) OR (`entry`=219255 AND `item`=227699 AND `ExtendedCost`=9121 AND `type`=1) OR (`entry`=219247 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=227073 AND `item`=114978 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=227073 AND `item`=114980 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=227073 AND `item`=114979 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219093 AND `item`=212754 AND `ExtendedCost`=8502 AND `type`=1) OR (`entry`=219093 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219093 AND `item`=210828 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219093 AND `item`=211806 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219091 AND `item`=212754 AND `ExtendedCost`=8502 AND `type`=1) OR (`entry`=219091 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219091 AND `item`=210828 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219091 AND `item`=211806 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219249 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219249 AND `item`=39489 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219249 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219249 AND `item`=211806 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219249 AND `item`=226205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219249 AND `item`=226204 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219089 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219089 AND `item`=39489 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219089 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219089 AND `item`=211806 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219089 AND `item`=226205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219089 AND `item`=226204 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219385 AND `item`=212754 AND `ExtendedCost`=8502 AND `type`=1) OR (`entry`=219385 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219385 AND `item`=210828 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219385 AND `item`=211806 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219387 AND `item`=228493 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219387 AND `item`=228492 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219387 AND `item`=228494 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219088 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219086 AND `item`=227208 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219086 AND `item`=220789 AND `ExtendedCost`=8581 AND `type`=1) OR (`entry`=219086 AND `item`=220790 AND `ExtendedCost`=8582 AND `type`=1) OR (`entry`=219086 AND `item`=220788 AND `ExtendedCost`=8580 AND `type`=1) OR (`entry`=219086 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219383 AND `item`=228609 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219383 AND `item`=228608 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(219274, 3, 227701, 0, 9121, 1, 0, 0, 56461), -- Preserved Defender's Kris
(219274, 2, 227700, 0, 9121, 1, 0, 0, 56461), -- Preserved Defender's Spear
(219274, 1, 227699, 0, 9121, 1, 0, 0, 56461), -- Earthen Ceremonial Chopper
(219255, 3, 227701, 0, 9121, 1, 0, 0, 56461), -- Preserved Defender's Kris
(219255, 2, 227700, 0, 9121, 1, 0, 0, 56461), -- Preserved Defender's Spear
(219255, 1, 227699, 0, 9121, 1, 0, 0, 56461), -- Earthen Ceremonial Chopper
(219247, 71, 20815, 0, 0, 1, 0, 0, 56461), -- Jeweler's Toolset
(227073, 3, 114978, 0, 0, 1, 0, 0, 56461), -- Farmer's Shovel
(227073, 2, 114980, 0, 0, 1, 0, 0, 56461), -- Farmer's Broom
(227073, 1, 114979, 0, 0, 1, 0, 0, 56461), -- Farmer's Hoe
(219093, 4, 212754, 0, 8502, 1, 0, 0, 56461), -- Crystalforged Cauldron
(219093, 3, 85663, 0, 0, 1, 0, 0, 56461), -- Herbalist's Spade
(219093, 2, 210828, 0, 0, 1, 0, 0, 56461), -- Dilution Solution
(219093, 1, 211806, 0, 0, 1, 0, 0, 56461), -- Gilded Vial
(219091, 4, 212754, 0, 8502, 1, 0, 0, 56461), -- Crystalforged Cauldron
(219091, 3, 85663, 0, 0, 1, 0, 0, 56461), -- Herbalist's Spade
(219091, 2, 210828, 0, 0, 1, 0, 0, 56461), -- Dilution Solution
(219091, 1, 211806, 0, 0, 1, 0, 0, 56461), -- Gilded Vial
(219249, 6, 85663, 0, 0, 1, 0, 0, 56461), -- Herbalist's Spade
(219249, 5, 39489, 0, 0, 1, 0, 0, 56461), -- Scribe's Satchel
(219249, 4, 39505, 0, 0, 1, 0, 0, 56461), -- Virtuoso Inking Set
(219249, 3, 211806, 0, 0, 1, 0, 0, 56461), -- Gilded Vial
(219249, 2, 226205, 0, 0, 1, 0, 0, 56461), -- Distilled Algari Freshwater
(219249, 1, 226204, 0, 0, 1, 0, 0, 56461), -- Fresh Parchment
(219089, 6, 85663, 0, 0, 1, 0, 0, 56461), -- Herbalist's Spade
(219089, 5, 39489, 0, 0, 1, 0, 0, 56461), -- Scribe's Satchel
(219089, 4, 39505, 0, 0, 1, 0, 0, 56461), -- Virtuoso Inking Set
(219089, 3, 211806, 0, 0, 1, 0, 0, 56461), -- Gilded Vial
(219089, 2, 226205, 0, 0, 1, 0, 0, 56461), -- Distilled Algari Freshwater
(219089, 1, 226204, 0, 0, 1, 0, 0, 56461), -- Fresh Parchment
(219385, 4, 212754, 0, 8502, 1, 0, 0, 56461), -- Crystalforged Cauldron
(219385, 3, 85663, 0, 0, 1, 0, 0, 56461), -- Herbalist's Spade
(219385, 2, 210828, 0, 0, 1, 0, 0, 56461), -- Dilution Solution
(219385, 1, 211806, 0, 0, 1, 0, 0, 56461), -- Gilded Vial
(219387, 3, 228493, 0, 0, 1, 0, 0, 56461), -- Sour Topaz Bites
(219387, 2, 228492, 0, 0, 1, 0, 0, 56461), -- Spicy Rubies
(219387, 1, 228494, 0, 0, 1, 0, 0, 56461), -- Crunchy Rock Candy
(219088, 66, 20815, 0, 0, 1, 0, 0, 56461), -- Jeweler's Toolset
(219086, 5, 227208, 0, 0, 1, 0, 0, 56461), -- Bismuth Rod
(219086, 4, 220789, 0, 8581, 1, 0, 0, 56461), -- Nascent Gilded Harbinger Crest
(219086, 3, 220790, 0, 8582, 1, 0, 0, 56461), -- Nascent Runed Harbinger Crest
(219086, 2, 220788, 0, 8580, 1, 0, 0, 56461), -- Nascent Weathered Harbinger Crest
(219086, 1, 38682, 0, 0, 1, 0, 0, 56461), -- Enchanting Vellum
(219383, 2, 228609, 0, 0, 1, 0, 0, 56461), -- Rock Roasting for Dummies
(219383, 1, 228608, 0, 0, 1, 0, 0, 56461); -- On the Application of Arathi Technology to Earthen Life

-- Freysworn Arborist smart ai
SET @ENTRY := 219334;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+46), -(@CGUID+81));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+46), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 11, 455493, 0, 0, 0, 0, 0, 0, 19, 220674, 10, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  455493 on Closest alive creature Watering Beam Stalker (220674) in 10 yards'),
(-(@CGUID+81), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 11, 455493, 0, 0, 0, 0, 0, 0, 19, 220674, 10, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  455493 on Closest alive creature Watering Beam Stalker (220674) in 10 yards');

-- Path for Unbound Trader
SET @MOVERGUID := @CGUID+34;
SET @ENTRY := 219382;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Unbound Trader - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2295.8525, -2580.0173, 190.14233, NULL, 0),
(@PATH, 1, 2296.5938, -2576.5383, 190.14345, NULL, 0),
(@PATH, 2, 2296.6338, -2574.5972, 190.1437, NULL, 8635),
(@PATH, 3, 2294.2327, -2581.1025, 190.74263, NULL, 0),
(@PATH, 4, 2291.5989, -2581.6858, 190.85544, NULL, 0),
(@PATH, 5, 2280.6997, -2585.337, 191.60114, NULL, 0),
(@PATH, 6, 2279.1667, -2588.639, 191.60895, NULL, 0),
(@PATH, 7, 2277.8489, -2594.7239, 191.59567, NULL, 8348),
(@PATH, 8, 2280.3577, -2588.837, 191.64418, NULL, 0),
(@PATH, 9, 2289.757, -2584.8196, 190.76324, NULL, 0);

UPDATE `creature` SET `position_x`=2295.8525, `position_y`=-2580.0173, `position_z`=190.14233, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Unbound Trader
SET @MOVERGUID := @CGUID+8;
SET @ENTRY := 219382;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Unbound Trader - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2359.691, -2596.7656, 181.41336, NULL, 0),
(@PATH, 1, 2360.6182, -2603.9446, 181.41336, NULL, 0),
(@PATH, 2, 2360.4463, -2611.2378, 181.41336, NULL, 0),
(@PATH, 3, 2360.1458, -2616.6963, 181.41336, NULL, 0),
(@PATH, 4, 2357.5034, -2621.1807, 181.41336, NULL, 37),
(@PATH, 5, 2356.2014, -2622.757, 181.41336, NULL, 16354),
(@PATH, 6, 2360.6284, -2615.1458, 181.41336, NULL, 0),
(@PATH, 7, 2360.9758, -2608.8125, 181.41336, NULL, 0),
(@PATH, 8, 2360.8872, -2601.842, 181.41336, NULL, 0),
(@PATH, 9, 2360.5278, -2592.0696, 181.41335, NULL, 0),
(@PATH, 10, 2356.5852, -2589.2014, 181.66565, NULL, 16669);

UPDATE `creature` SET `position_x`=2359.691, `position_y`=-2596.7656, `position_z`=181.41336, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Oathsworn Citizen
SET @MOVERGUID := @CGUID+9;
SET @ENTRY := 219150;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Citizen - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2281.816, -2495.4236, 195.85315, NULL, 0),
(@PATH, 1, 2289.008, -2503.924, 199.66258, NULL, 0),
(@PATH, 2, 2288.8972, -2509.1052, 199.66566, NULL, 0),
(@PATH, 3, 2295.0886, -2511.0989, 199.66565, NULL, 0),
(@PATH, 4, 2304.3577, -2513.1736, 199.99841, NULL, 0),
(@PATH, 5, 2314.059, -2516.9045, 199.25485, NULL, 0),
(@PATH, 6, 2315.4895, -2519.8508, 199.25485, NULL, 0),
(@PATH, 7, 2313.2993, -2522.8105, 199.46252, NULL, 4236),
(@PATH, 8, 2315.1807, -2517.1042, 199.25485, NULL, 0),
(@PATH, 9, 2313.3855, -2515.1182, 199.82454, NULL, 0),
(@PATH, 10, 2309.5208, -2514.092, 200.00739, NULL, 0),
(@PATH, 11, 2303.7188, -2513.8057, 199.91127, NULL, 0),
(@PATH, 12, 2298.6753, -2512.889, 199.96118, NULL, 0),
(@PATH, 13, 2294.9683, -2511.3035, 199.66733, NULL, 0),
(@PATH, 14, 2292.1926, -2510.2449, 199.66565, NULL, 0),
(@PATH, 15, 2288.875, -2508.5017, 199.66566, NULL, 0),
(@PATH, 16, 2288.5603, -2502.1348, 199.87422, NULL, 0),
(@PATH, 17, 2282.2014, -2495.573, 195.85315, NULL, 0),
(@PATH, 18, 2280.757, -2496.5295, 195.88914, NULL, 0),
(@PATH, 19, 2278.9497, -2496.3542, 195.85315, NULL, 0),
(@PATH, 20, 2275.0278, -2495.8489, 195.85315, NULL, 0),
(@PATH, 21, 2273.9915, -2496.639, 195.85315, NULL, 3185);

UPDATE `creature` SET `position_x`=2281.816, `position_y`=-2495.4236, `position_z`=195.85315, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Oathsworn Citizen
SET @MOVERGUID := @CGUID+16;
SET @ENTRY := 219150;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Citizen - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2336.4497, -2618.0383, 190.1421, NULL, 13214),
(@PATH, 1, 2339.632, -2595.0798, 190.46252, NULL, 5183),
(@PATH, 2, 2311.4307, -2598.6284, 190.13893, NULL, 0),
(@PATH, 3, 2314.4878, -2610.7708, 190.13763, NULL, 0),
(@PATH, 4, 2314.2449, -2635.559, 190.14197, NULL, 0),
(@PATH, 5, 2320.4602, -2650.0696, 190.14212, NULL, 0),
(@PATH, 6, 2318.6719, -2674.4358, 190.1421, NULL, 8327);

UPDATE `creature` SET `position_x`=2336.4497, `position_y`=-2618.0383, `position_z`=190.1421, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Oathsworn Citizen
SET @MOVERGUID := @CGUID+18;
SET @ENTRY := 219151;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Citizen - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2302.4514, -2634.587, 190.14247, NULL, 20750),
(@PATH, 1, 2308.7673, -2577.0608, 190.14069, NULL, 0),
(@PATH, 2, 2313.3801, -2572.0798, 190.13927, NULL, 3891),
(@PATH, 3, 2276.9426, -2544.9636, 199.40453, NULL, 6879),
(@PATH, 4, 2322.29, -2584.9602, 190.1421, NULL, 0);

UPDATE `creature` SET `position_x`=2302.4514, `position_y`=-2634.587, `position_z`=190.14247, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Oathsworn Citizen
SET @MOVERGUID := @CGUID+73;
SET @ENTRY := 219150;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Citizen - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2382.4739, -2503.179, 199.25485, NULL, 0),
(@PATH, 1, 2382.191, -2500.7153, 199.25485, NULL, 0),
(@PATH, 2, 2383.333, -2498.7864, 199.25485, NULL, 15731),
(@PATH, 3, 2388.1128, -2495.3315, 199.49783, NULL, 8273),
(@PATH, 4, 2382.0312, -2498.9463, 199.25485, NULL, 0),
(@PATH, 5, 2382.1494, -2502.1216, 199.25485, NULL, 0),
(@PATH, 6, 2384.691, -2505.6892, 199.25485, NULL, 0),
(@PATH, 7, 2386.7917, -2505.231, 199.25485, NULL, 13781);

UPDATE `creature` SET `position_x`=2382.4739, `position_y`=-2503.179, `position_z`=199.25485, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Oathsworn Crafter
SET @MOVERGUID := @CGUID+24;
SET @ENTRY := 229927;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Unbound Crafter - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2297.2014, -2608.0347, 190.14247, NULL, 8604),
(@PATH, 1, 2298.3784, -2621.0312, 190.14247, NULL, 0),
(@PATH, 2, 2296.8594, -2628.2395, 190.14249, NULL, 0),
(@PATH, 3, 2294.823, -2631.7292, 190.14246, NULL, 11239),
(@PATH, 4, 2298.4792, -2620.9375, 190.14246, NULL, 0),
(@PATH, 5, 2298.073, -2612.3057, 190.14247, NULL, 0);

UPDATE `creature` SET `position_x`=2297.2014, `position_y`=-2608.0347, `position_z`=190.14247, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Molvzira
SET @MOVERGUID := @CGUID+66;
SET @ENTRY := 227073;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Molvzira - Scripted Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2351.5635, -2489.2031, 199.63759, NULL, 0),
(@PATH, 1, 2349.2795, -2490.5017, 199.25777, NULL, 11262),
(@PATH, 2, 2356.4307, -2484.4966, 199.25536, NULL, 0),
(@PATH, 3, 2356.25, -2481.25, 199.25557, NULL, 0),
(@PATH, 4, 2353.519, -2479.0815, 199.25766, NULL, 0),
(@PATH, 5, 2350.6511, -2480.7778, 199.66565, NULL, 13995),
(@PATH, 6, 2354.167, -2478.54, 199.25732, NULL, 9282),
(@PATH, 7, 2356.5972, -2483.4775, 199.25595, NULL, 0),
(@PATH, 8, 2355.5088, -2484.809, 199.25589, NULL, 0),
(@PATH, 9, 2353.1824, -2484.894, 199.66565, NULL, 10371);

UPDATE `creature` SET `position_x`=2351.5635, `position_y`=-2489.2031, `position_z`=199.63759, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Oathsworn Peacekeeper
SET @MOVERGUID := @CGUID+88;
SET @ENTRY := 219014;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Peacekeeper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2378.3057, -2612.4133, 181.4133, NULL, 3529),
(@PATH, 1, 2378.0764, -2598.427, 181.41331, NULL, 0),
(@PATH, 2, 2378.1199, -2579.9514, 181.41333, NULL, 0),
(@PATH, 3, 2377.6423, -2562.8594, 181.41327, NULL, 5982),
(@PATH, 4, 2378.1199, -2579.9514, 181.41333, NULL, 0),
(@PATH, 5, 2378.0764, -2598.427, 181.41331, NULL, 0);

UPDATE `creature` SET `position_x`=2378.3057, `position_y`=-2612.4133, `position_z`=181.4133, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '18950');

-- Path for Oathsworn Peacekeeper
SET @MOVERGUID := @CGUID+89;
SET @ENTRY := 219014;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Peacekeeper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2376.3281, -2485.059, 199.25484, NULL, 4385),
(@PATH, 1, 2311.639, -2544.8994, 199.25485, NULL, 4272);

UPDATE `creature` SET `position_x`=2376.3281, `position_y`=-2485.059, `position_z`=199.25484, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '18950');

-- Path for Oathsworn Peacekeeper
SET @MOVERGUID := @CGUID+90;
SET @ENTRY := 219014;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Peacekeeper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2328.2847, -2510.8628, 199.25485, NULL, 3451),
(@PATH, 1, 2327.4253, -2636.8525, 190.1421, NULL, 6042);

UPDATE `creature` SET `position_x`=2328.2847, `position_y`=-2510.8628, `position_z`=199.25485, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '18950');
