SET @CGUID := 10001424;

SET @NPCTEXTID := 600000;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+75;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 225973, 2552, 14771, 15110, '0', '0', 0, 0, 1, 2233.564208984375, -2779.51904296875, 198.7369232177734375, 0.81770867109298706, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Oathsworn Peacekeeper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+1, 225979, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2269.67529296875, -2826.4462890625, 265.39208984375, 1.55340743064880371, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry)
(@CGUID+2, 214947, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2312.592529296875, -2794.6005859375, 235.9625091552734375, 0.220409393310546875, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56421), -- Eye of Topaz (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+3, 225979, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2264.0400390625, -2820.885498046875, 265.39208984375, 0.021275993436574935, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry)
(@CGUID+4, 214947, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2306.94921875, -2785.17138671875, 211.4427032470703125, 3.907796144485473632, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56421), -- Eye of Topaz (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+5, 225979, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2269.345458984375, -2815.319580078125, 265.39208984375, 4.705008983612060546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry)
(@CGUID+6, 226001, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2322.085205078125, -2729.65966796875, 199.30517578125, 2.405005216598510742, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Freysworn Mossbinder (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+7, 225980, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2213.407958984375, -2780.710205078125, 198.7369384765625, 5.774527549743652343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry)
(@CGUID+8, 225980, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2210.491455078125, -2780.276123046875, 198.7371673583984375, 5.911242008209228515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry)
(@CGUID+9, 225973, 2552, 14771, 15110, '0', '0', 0, 0, 1, 2239.73779296875, -2786.185791015625, 198.7369384765625, 0.81770867109298706, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Oathsworn Peacekeeper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+10, 225982, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2197.98779296875, -2752.0869140625, 265.39215087890625, 4.60735321044921875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Cleave Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+11, 226001, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2316.64404296875, -2724.350830078125, 199.3135223388671875, 5.472630500793457031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Freysworn Mossbinder (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+12, 225982, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2240.63720703125, -2805.20654296875, 198.73748779296875, 2.43552255630493164, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Cleave Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+13, 225983, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2256.62158203125, -2696.751708984375, 199.302093505859375, 4.814493656158447265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dungeoneer's Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+14, 225980, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2215.498291015625, -2778.68408203125, 198.7369842529296875, 5.16316080093383789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry)
(@CGUID+15, 214947, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2275.459228515625, -2736.95947265625, 204.9427032470703125, 0.742911696434020996, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56421), -- Eye of Topaz (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+16, 219250, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2287.895751953125, -2789.951416015625, 199.302032470703125, 1.691766619682312011, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- PvP Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 228695 - PvP Rules Enabled for Dummy, 228689 - Gnome Male Mask)
(@CGUID+17, 225984, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2268.432373046875, -2696.37841796875, 199.30194091796875, 4.744472503662109375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+18, 225976, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2229.15625, -2723.291748046875, 199.3021087646484375, 6.143868923187255859, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Normal Tank Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker)
(@CGUID+19, 225973, 2552, 14771, 15110, '0', '0', 0, 0, 1, 2237.564208984375, -2783.928955078125, 198.73687744140625, 0.81770867109298706, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Oathsworn Peacekeeper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+20, 214947, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2303.005615234375, -2644.6123046875, 196.8611602783203125, 3.741254568099975585, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56421), -- Eye of Topaz (Area: Contender's Gate - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+21, 219982, 2552, 14771, 15110, '0', '0', 0, 0, 1, 2304.842041015625, -2752.008056640625, 198.7781982421875, 5.25386667251586914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Oathsworn Peacekeeper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+22, 225982, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2242.4462890625, -2803.286376953125, 198.73773193359375, 2.777302026748657226, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Cleave Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+23, 214947, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2236.138916015625, -2714.603271484375, 208.4227294921875, 0.479847282171249389, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56421), -- Eye of Topaz (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+24, 219215, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2218.94091796875, -2698.59033203125, 200.05572509765625, 0.067420586943626403, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Hotharn (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+25, 219251, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2322.795166015625, -2753.64404296875, 199.3019866943359375, 3.139423847198486328, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- PvP Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry, 178806 - PvP Rules Enabled for Dummy)
(@CGUID+26, 214947, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2272.10888671875, -2692.17724609375, 209.72540283203125, 1.434525370597839355, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56421), -- Eye of Topaz (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+27, 225983, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2269.34033203125, -2821.21533203125, 265.392120361328125, 2.366980314254760742, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dungeoneer's Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+28, 225979, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2358.632080078125, -2737.87158203125, 265.39569091796875, 3.181362152099609375, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry)
(@CGUID+29, 214947, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2229.3349609375, -2700.417724609375, 236.993194580078125, 1.523964405059814453, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56421), -- Eye of Topaz (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+30, 219982, 2552, 14771, 15110, '0', '0', 0, 0, 4, 2306.546875, -2754.842529296875, 198.7781982421875, 2.112291812896728515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Oathsworn Peacekeeper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+31, 225976, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2281.833251953125, -2668.170166015625, 265.39581298828125, 3.593718528747558593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Normal Tank Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker)
(@CGUID+32, 225979, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2274.73779296875, -2820.94091796875, 265.39208984375, 3.181847333908081054, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry)
(@CGUID+33, 219222, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2233.385498046875, -2689.611083984375, 200.05572509765625, 3.970124244689941406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Lalandi (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+34, 225977, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2281.489501953125, -2665.177001953125, 265.395751953125, 3.876962661743164062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dungeoneer's Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker)
(@CGUID+35, 225978, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2291.51904296875, -2698.80908203125, 199.30908203125, 3.799666881561279296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Crystalmaw (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker)
(@CGUID+36, 219216, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2329.62841796875, -2789.416748046875, 200.05572509765625, 3.07097625732421875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Rogurn (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+37, 225979, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2265.4150390625, -2696.59033203125, 199.301971435546875, 4.777201175689697265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry)
(@CGUID+38, 219217, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2229.41845703125, -2688.177001953125, 200.05572509765625, 4.84227752685546875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Velerd (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+39, 225982, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2240.282958984375, -2803.10595703125, 198.7371368408203125, 2.673701763153076171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Cleave Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+40, 225982, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2198.470458984375, -2747.895751953125, 265.39208984375, 0.82105255126953125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Cleave Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+41, 225973, 2552, 14771, 15110, '0', '0', 0, 0, 1, 2240.348876953125, -2780.95654296875, 198.7369384765625, 0.81770867109298706, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Oathsworn Peacekeeper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+42, 219250, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2322.06591796875, -2759.8056640625, 199.30206298828125, 3.001209974288940429, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- PvP Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 228695 - PvP Rules Enabled for Dummy, 228689 - Gnome Male Mask)
(@CGUID+43, 225982, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2229.34375, -2761.78466796875, 198.739288330078125, 5.476544857025146484, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Cleave Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+44, 225973, 2552, 14771, 15110, '0', '0', 0, 0, 1, 2238.26904296875, -2778.796875, 198.7369232177734375, 0.81770867109298706, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Oathsworn Peacekeeper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+45, 226004, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2288.38720703125, -2697.170166015625, 199.3046875, 5.514236927032470703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Unbound Stoneshaper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+46, 219982, 2552, 14771, 15110, '0', '0', 0, 0, 3, 2247.790771484375, -2740.9482421875, 198.7782135009765625, 2.07935190200805664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Oathsworn Peacekeeper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+47, 225982, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2238.678955078125, -2807.10595703125, 198.737213134765625, 2.066156625747680664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Cleave Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+48, 225973, 2552, 14771, 15110, '0', '0', 0, 0, 1, 2236.3525390625, -2776.807373046875, 198.736968994140625, 0.81770867109298706, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Oathsworn Peacekeeper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+49, 219251, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2255.64404296875, -2789.257080078125, 198.7388153076171875, 2.749991893768310546, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- PvP Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry, 178806 - PvP Rules Enabled for Dummy)
(@CGUID+50, 219260, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2245.7744140625, -2770.657958984375, 198.737091064453125, 3.975718021392822265, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ruffious (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+51, 219982, 2552, 14771, 15110, '0', '0', 0, 0, 2, 2246.177978515625, -2738.05517578125, 198.7782135009765625, 5.220948219299316406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Oathsworn Peacekeeper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+52, 219073, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2324.038330078125, -2793.0869140625, 200.2828216552734375, 2.340579748153686523, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Ledonir (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+53, 214947, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2274.32666015625, -2753.044677734375, 197.7781982421875, 3.790003299713134765, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56421), -- Eye of Topaz (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+54, 219250, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2291.192626953125, -2791.732666015625, 199.3020782470703125, 1.647102236747741699, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- PvP Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 228689 - Gnome Male Mask, 228695 - PvP Rules Enabled for Dummy)
(@CGUID+55, 225984, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2345.607666015625, -2738.458251953125, 265.395721435546875, 0.033176593482494354, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+56, 214947, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2320.395751953125, -2715.839599609375, 231.9030303955078125, 4.8206787109375, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56421), -- Eye of Topaz (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+57, 219251, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2253.2900390625, -2791.802001953125, 198.73876953125, 2.066817045211791992, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- PvP Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry, 178806 - PvP Rules Enabled for Dummy)
(@CGUID+58, 225985, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2319.23095703125, -2727.0712890625, 199.3096160888671875, 4.058077812194824218, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Kelpfist (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry, 212702 - Combat)
(@CGUID+59, 219212, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2320.100830078125, -2798.8837890625, 200.05572509765625, 1.598256707191467285, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Maara (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+60, 225980, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2212.598876953125, -2778.204833984375, 198.737457275390625, 5.514329910278320312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry)
(@CGUID+61, 219213, 2552, 14771, 15110, '0', '0', 0, 0, 1, 2224.060791015625, -2693.145751953125, 200.126495361328125, 5.56060028076171875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Gilderann (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+62, 225980, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2214.973876953125, -2776.032958984375, 198.737762451171875, 5.072946548461914062, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 167347 - Passive Uber DoT, 457552 - Burning Fire, 349892 - [DNT] No Parry)
(@CGUID+63, 225982, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2194.486083984375, -2748.51904296875, 265.392120361328125, 3.345985889434814453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Cleave Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+64, 214947, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2220.496337890625, -2737.41357421875, 230.496612548828125, 3.478863239288330078, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56421), -- Eye of Topaz (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+65, 225982, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2227.420166015625, -2763.74658203125, 198.7392425537109375, 5.484318256378173828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Cleave Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+66, 225973, 2552, 14771, 15110, '0', '0', 0, 0, 1, 2242.473876953125, -2783.255126953125, 198.7369842529296875, 0.81770867109298706, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Oathsworn Peacekeeper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+67, 225982, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2238.3212890625, -2805.14404296875, 198.7371063232421875, 2.176073074340820312, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Cleave Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 349892 - [DNT] No Parry)
(@CGUID+68, 98148, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2270.609375, -2791.203125, 199.301788330078125, 1.452693104743957519, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Nassar (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+69, 225973, 2552, 14771, 15110, '0', '0', 0, 0, 1, 2235.57470703125, -2781.717041015625, 198.7368621826171875, 0.81770867109298706, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Oathsworn Peacekeeper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+70, 214947, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2348.04052734375, -2692.012451171875, 191.5891876220703125, 5.452363967895507812, 120, 3, 0, 1, NULL, NULL, NULL, NULL, 56421), -- Eye of Topaz (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+71, 226004, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2293.70654296875, -2702.06591796875, 199.31414794921875, 2.366358041763305664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Unbound Stoneshaper (Area: Contender's Gate - Difficulty: 0) CreateObject1
(@CGUID+72, 219250, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2285.107666015625, -2792.3125, 199.302032470703125, 1.665988922119140625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- PvP Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker, 228689 - Gnome Male Mask, 228695 - PvP Rules Enabled for Dummy)
(@CGUID+73, 225976, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2278.270751953125, -2664.5869140625, 265.39581298828125, 4.190438270568847656, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Normal Tank Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker)
(@CGUID+74, 225977, 2552, 14771, 15110, '0', '0', 0, 0, 0, 2226.765625, -2730.62841796875, 199.302032470703125, 6.270664691925048828, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421), -- Dungeoneer's Training Dummy (Area: Contender's Gate - Difficulty: 0) CreateObject1 (Auras: 98892 - Training Dummy Marker)
(@CGUID+75, 225972, 2552, 14771, 15110, '0', '0', 0, 0, 1, 2247.95654296875, -2773.29345703125, 198.737091064453125, 3.882647991180419921, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56421); -- Peacekeeper Captain (Area: Contender's Gate - Difficulty: 0) CreateObject1

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (225972 /*225972 (Peacekeeper Captain)*/, 225985 /*225985 (Kelpfist) - Training Dummy Marker, [DNT] No Parry, Combat*/, 225978 /*225978 (Crystalmaw) - Training Dummy Marker*/, 225977 /*225977 (Dungeoneer's Training Dummy) - Training Dummy Marker*/, 219251 /*219251 (PvP Training Dummy) - Training Dummy Marker, Passive Uber DoT, Burning Fire, [DNT] No Parry, PvP Rules Enabled for Dummy*/, 225976 /*225976 (Normal Tank Dummy) - Training Dummy Marker*/, 225984 /*225984 (Training Dummy) - Training Dummy Marker, [DNT] No Parry*/, 219250 /*219250 (PvP Training Dummy) - Training Dummy Marker, PvP Rules Enabled for Dummy, Gnome Male Mask*/, 225983 /*225983 (Dungeoneer's Training Dummy) - Training Dummy Marker, [DNT] No Parry*/, 225982 /*225982 (Cleave Training Dummy) - Training Dummy Marker, [DNT] No Parry*/, 225980 /*225980 (Training Dummy) - Training Dummy Marker, Passive Uber DoT, Burning Fire, [DNT] No Parry*/, 214947 /*214947 (Eye of Topaz)*/, 225979 /*225979 (Training Dummy) - Training Dummy Marker, Passive Uber DoT, Burning Fire, [DNT] No Parry*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(225972, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ''), -- 225972 (Peacekeeper Captain)
(225985, 0, 0, 0, 0, 0, 1, 0, 0, 10878, 0, 0, 0, '98892 349892 212702'), -- 225985 (Kelpfist) - Training Dummy Marker, [DNT] No Parry, Combat
(225978, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892'), -- 225978 (Crystalmaw) - Training Dummy Marker
(225977, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892'), -- 225977 (Dungeoneer's Training Dummy) - Training Dummy Marker
(219251, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 167347 457552 349892 178806'), -- 219251 (PvP Training Dummy) - Training Dummy Marker, Passive Uber DoT, Burning Fire, [DNT] No Parry, PvP Rules Enabled for Dummy
(225976, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892'), -- 225976 (Normal Tank Dummy) - Training Dummy Marker
(225984, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 349892'), -- 225984 (Training Dummy) - Training Dummy Marker, [DNT] No Parry
(219250, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 228695 228689'), -- 219250 (PvP Training Dummy) - Training Dummy Marker, PvP Rules Enabled for Dummy, Gnome Male Mask
(225983, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 349892'), -- 225983 (Dungeoneer's Training Dummy) - Training Dummy Marker, [DNT] No Parry
(225982, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 349892'), -- 225982 (Cleave Training Dummy) - Training Dummy Marker, [DNT] No Parry
(225980, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 167347 457552 349892'), -- 225980 (Training Dummy) - Training Dummy Marker, Passive Uber DoT, Burning Fire, [DNT] No Parry
(214947, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 214947 (Eye of Topaz)
(225979, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '98892 167347 457552 349892'); -- 225979 (Training Dummy) - Training Dummy Marker, Passive Uber DoT, Burning Fire, [DNT] No Parry

-- Template
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry`=225972; -- Peacekeeper Captain
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=226777; -- Professor Pallin
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=832, `unit_flags2`=2048 WHERE `entry`=222142; -- Tauren Brave
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219383; -- Malukh
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219213; -- Gilderann
UPDATE `creature_template` SET `faction`=3407, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219085; -- Nagad
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219212; -- Maara
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219380; -- Dokhan
UPDATE `creature_template` SET `faction`=3407, `npcflag`=4194433, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=219376; -- Kargand
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=1090519040 WHERE `entry`=215364; -- Ette
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=219217; -- Velerd
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219216; -- Rogurn
UPDATE `creature_template` SET `faction`=7, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=1082130433 WHERE `entry`=225985; -- Kelpfist
UPDATE `creature_template` SET `faction`=7, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=1082130432 WHERE `entry`=225978; -- Crystalmaw
UPDATE `creature_template` SET `faction`=7, `speed_run`=1, `BaseAttackTime`=1500, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=1082130432 WHERE `entry`=225977; -- Dungeoneer's Training Dummy
UPDATE `creature_template` SET `faction`=35, `npcflag`=131, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=219222; -- Lalandi
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1082130433 WHERE `entry`=219251; -- PvP Training Dummy
UPDATE `creature_template` SET `faction`=3407, `npcflag`=130, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219215; -- Hotharn
UPDATE `creature_template` SET `faction`=7, `speed_run`=1, `BaseAttackTime`=1500, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=1082130432 WHERE `entry`=225976; -- Normal Tank Dummy
UPDATE `creature_template` SET `faction`=7, `speed_walk`=0.60000002384185791, `speed_run`=0.60000002384185791, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=1082130433 WHERE `entry`=225984; -- Training Dummy
UPDATE `creature_template` SET `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1082130433 WHERE `entry`=219250; -- PvP Training Dummy
UPDATE `creature_template` SET `faction`=7, `speed_walk`=0.60000002384185791, `speed_run`=0.60000002384185791, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048, `unit_flags3`=1082130433 WHERE `entry`=225983; -- Dungeoneer's Training Dummy
UPDATE `creature_template` SET `faction`=7, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags`=576, `unit_flags2`=2048, `unit_flags3`=1082130433 WHERE `entry`=225982; -- Cleave Training Dummy
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags`=64, `unit_flags2`=2048 WHERE `entry` IN (219982, 225973); -- Oathsworn Peacekeeper
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=214947; -- Eye of Topaz
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=226001; -- Freysworn Mossbinder
UPDATE `creature_template` SET `faction`=3407, `npcflag`=4294967296, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219073; -- Ledonir
UPDATE `creature_template` SET `faction`=3407, `npcflag`=2, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219260; -- Ruffious
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=226004; -- Unbound Stoneshaper

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=219222 AND `MenuID`=35684) OR (`CreatureID`=98148 AND `MenuID`=18847);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(219222, 35684, 56421), -- Lalandi
(98148, 18847, 56421); -- Nassar

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+1;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 268536, 0, 0, 0, 0, 0, 0, 0, 56421), -- 219222 (Lalandi)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 99975, 0, 0, 0, 0, 0, 0, 0, 56421); -- 98148 (Nassar)

DELETE FROM `gossip_menu` WHERE (`MenuID`=35684 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=18847 AND `TextID`=@NPCTEXTID+1);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(35684, @NPCTEXTID+0, 56421), -- 219222 (Lalandi)
(18847, @NPCTEXTID+1, 56421); -- 98148 (Nassar)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=35684 AND `OptionID`=0) OR (`MenuID`=18847 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(35684, 123391, 0, 1, 'Let me browse your goods.', 2823, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56421), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(18847, 44753, 0, 0, 'I will fight alongside the Horde in battlegrounds, for now.', 99976, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56421);

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=43499 AND `DifficultyID`=0); -- 43499 (Consecration) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=225972 AND `DifficultyID`=0); -- 225972 (Peacekeeper Captain) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=226777 AND `DifficultyID`=0); -- 226777 (Professor Pallin) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=982, `VerifiedBuild`=56421 WHERE (`Entry`=98148 AND `DifficultyID`=0); -- 98148 (Nassar) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=222142 AND `DifficultyID`=0); -- 222142 (Tauren Brave) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219383 AND `DifficultyID`=0); -- 219383 (Malukh) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219213 AND `DifficultyID`=0); -- 219213 (Gilderann) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219085 AND `DifficultyID`=0); -- 219085 (Nagad) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219212 AND `DifficultyID`=0); -- 219212 (Maara) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219376 AND `DifficultyID`=0); -- 219376 (Kargand) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=215364 AND `DifficultyID`=0); -- 215364 (Ette) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219150 AND `DifficultyID`=0); -- 219150 (Oathsworn Citizen) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2723, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=225985 AND `DifficultyID`=0); -- 225985 (Kelpfist) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=222336 AND `DifficultyID`=0); -- 222336 (Gilnean Tracker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=805306624, `VerifiedBuild`=56421 WHERE (`Entry`=230031 AND `DifficultyID`=0); -- 230031 (Oathsworn Worker) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219073 AND `DifficultyID`=0); -- 219073 (Ledonir) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2832, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219260 AND `DifficultyID`=0); -- 219260 (Ruffious) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=226004 AND `DifficultyID`=0); -- 226004 (Unbound Stoneshaper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=214838 AND `DifficultyID`=0); -- 214838 (Earthen Wagon) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219378 AND `DifficultyID`=0); -- 219378 (Stabled Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=214772 AND `DifficultyID`=0); -- 214772 (Limestone Falcon) - CanSwim
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=56421 WHERE (`Entry`=229379 AND `DifficultyID`=0);
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219217 AND `DifficultyID`=0); -- 219217 (Velerd) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219216 AND `DifficultyID`=0); -- 219216 (Rogurn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2723, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=225978 AND `DifficultyID`=0); -- 225978 (Crystalmaw) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=226224 AND `DifficultyID`=0); -- 226224 (Forgegrounds Worker) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219180 AND `DifficultyID`=0); -- 219180 (Cornerdweller) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2974, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=225977 AND `DifficultyID`=0); -- 225977 (Dungeoneer's Training Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219222 AND `DifficultyID`=0); -- 219222 (Lalandi) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=181, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=219251 AND `DifficultyID`=0); -- 219251 (PvP Training Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219215 AND `DifficultyID`=0); -- 219215 (Hotharn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219982 AND `DifficultyID`=0); -- 219982 (Oathsworn Peacekeeper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306368, `VerifiedBuild`=56421 WHERE (`Entry`=214948 AND `DifficultyID`=0); -- 214948 (Roaming Stormrook) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=225976 AND `DifficultyID`=0); -- 225976 (Normal Tank Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=225984 AND `DifficultyID`=0); -- 225984 (Training Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=181, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=219250 AND `DifficultyID`=0); -- 219250 (PvP Training Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2974, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=225983 AND `DifficultyID`=0); -- 225983 (Dungeoneer's Training Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=225982 AND `DifficultyID`=0); -- 225982 (Cleave Training Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=198464 AND `DifficultyID`=0); -- 198464 (Rostrum of Transformation) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=215070 AND `DifficultyID`=0); -- 215070 (Ashwhite Kestrel) - CanSwim
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=2803, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=219014 AND `DifficultyID`=0); -- 219014 (Oathsworn Peacekeeper) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2892, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=225980 AND `DifficultyID`=0); -- 225980 (Training Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=226001 AND `DifficultyID`=0); -- 226001 (Freysworn Mossbinder) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=805306624, `VerifiedBuild`=56421 WHERE (`Entry`=214824 AND `DifficultyID`=0); -- 214824 (Cart Hauler) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2078, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=225654 AND `DifficultyID`=0); -- 225654 (Boost) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2829, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=222258 AND `DifficultyID`=0); -- 222258 (Suramar Historian) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2078, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=225664 AND `DifficultyID`=0); -- 225664 (Boost) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=805306368, `VerifiedBuild`=56421 WHERE (`Entry`=214947 AND `DifficultyID`=0); -- 214947 (Eye of Topaz) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2838, `StaticFlags1`=536871168, `VerifiedBuild`=56421 WHERE (`Entry`=225979 AND `DifficultyID`=0); -- 225979 (Training Dummy) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=805306624, `VerifiedBuild`=56421 WHERE (`Entry`=227389 AND `DifficultyID`=0); -- 227389 (Earthen Crate) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56421 WHERE (`Entry`=225973 AND `DifficultyID`=0); -- 225973 (Oathsworn Peacekeeper) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (119213, 119101);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(119213, 0.722000002861022949, 3, 0, 56421),
(119101, 0.347222000360488891, 1.5, 0, 56421);

UPDATE `creature_model_info` SET `VerifiedBuild`=56421 WHERE `DisplayID` IN (120480, 122494, 65644, 120610, 117486, 120543, 119739, 114932, 120633, 119740, 117797, 117659, 72183, 117428, 102553, 120618, 117685, 121156, 118482, 120615, 118462, 117654, 117649, 116218, 114926, 120617, 118464, 120603, 120605, 109867, 120607, 4959, 120604, 120608, 121153, 114500, 117650, 117785, 106697, 117651, 117786, 121157, 106349, 104041, 104040, 120811, 121154, 117652);

-- Unbound Stoneshaper smart ai
SET @ENTRY := 226004;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+45), -(@CGUID+71));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+45), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 11, 454819, 0, 0, 0, 0, 0, 0, 19, 225978, 5, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  454819 on Closest alive creature Crystalmaw (225978) in 5 yards'),
(-(@CGUID+71), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 11, 454819, 0, 0, 0, 0, 0, 0, 19, 225978, 5, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  454819 on Closest alive creature Crystalmaw (225978) in 5 yards');

-- Freysworn Mossbinder smart ai
SET @ENTRY := 226001;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` IN (-(@CGUID+11), -(@CGUID+6));
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(-(@CGUID+11), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 11, 462680, 0, 0, 0, 0, 0, 0, 19, 225985, 5, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  462680 on Closest alive creature Kelpfist (225985) in 5 yards'),
(-(@CGUID+6), 0, 0, 0, '', 25, 0, 100, 0, 0, 0, 0, 0, 11, 462680, 0, 0, 0, 0, 0, 0, 19, 225985, 5, 0, 0, 0, 0, 0, 'On reset - Self: Cast spell  462680 on Closest alive creature Kelpfist (225985) in 5 yards');

-- Vendor data
DELETE FROM `npc_vendor` WHERE (`entry`=219212 AND `item`=224041 AND `ExtendedCost`=8501 AND `type`=1) OR (`entry`=219212 AND `item`=224042 AND `ExtendedCost`=8501 AND `type`=1) OR (`entry`=219212 AND `item`=224043 AND `ExtendedCost`=8501 AND `type`=1) OR (`entry`=219212 AND `item`=224044 AND `ExtendedCost`=8501 AND `type`=1) OR (`entry`=219212 AND `item`=224045 AND `ExtendedCost`=8501 AND `type`=1) OR (`entry`=219212 AND `item`=224046 AND `ExtendedCost`=8501 AND `type`=1) OR (`entry`=219212 AND `item`=224047 AND `ExtendedCost`=8501 AND `type`=1) OR (`entry`=219212 AND `item`=224048 AND `ExtendedCost`=8501 AND `type`=1) OR (`entry`=219212 AND `item`=224049 AND `ExtendedCost`=8501 AND `type`=1) OR (`entry`=219222 AND `item`=210233 AND `ExtendedCost`=8517 AND `type`=1) OR (`entry`=219217 AND `item`=224556 AND `ExtendedCost`=7878 AND `type`=1) OR (`entry`=219217 AND `item`=225739 AND `ExtendedCost`=9046 AND `type`=1) OR (`entry`=219217 AND `item`=218424 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218423 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218421 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218425 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218422 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218431 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218430 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218429 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218428 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218427 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218426 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218435 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218434 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218432 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218433 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218418 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218386 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218413 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218381 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218399 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218367 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218394 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218362 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218410 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218378 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218405 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218373 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218389 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218357 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218391 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218359 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218419 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218387 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218415 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218383 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218401 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218369 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218396 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218364 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218412 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218380 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218407 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218375 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218403 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218371 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218392 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218360 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218420 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218388 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218416 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218384 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218398 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218366 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218397 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218365 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218409 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218377 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218408 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218376 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218404 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218372 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218393 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218361 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218417 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218385 AND `ExtendedCost`=8950 AND `type`=1) OR (`entry`=219217 AND `item`=218414 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218382 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218400 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218368 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218395 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218363 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218411 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218379 AND `ExtendedCost`=8948 AND `type`=1) OR (`entry`=219217 AND `item`=218406 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218374 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218402 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218370 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218390 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218358 AND `ExtendedCost`=8949 AND `type`=1) OR (`entry`=219217 AND `item`=218452 AND `ExtendedCost`=8951 AND `type`=1) OR (`entry`=219217 AND `item`=218444 AND `ExtendedCost`=8951 AND `type`=1) OR (`entry`=219217 AND `item`=218442 AND `ExtendedCost`=8954 AND `type`=1) OR (`entry`=219217 AND `item`=218449 AND `ExtendedCost`=8951 AND `type`=1) OR (`entry`=219217 AND `item`=218440 AND `ExtendedCost`=8953 AND `type`=1) OR (`entry`=219217 AND `item`=218451 AND `ExtendedCost`=8952 AND `type`=1) OR (`entry`=219217 AND `item`=218448 AND `ExtendedCost`=8952 AND `type`=1) OR (`entry`=219217 AND `item`=218443 AND `ExtendedCost`=8952 AND `type`=1) OR (`entry`=219217 AND `item`=218437 AND `ExtendedCost`=8952 AND `type`=1) OR (`entry`=219217 AND `item`=218446 AND `ExtendedCost`=8953 AND `type`=1) OR (`entry`=219217 AND `item`=218439 AND `ExtendedCost`=8953 AND `type`=1) OR (`entry`=219217 AND `item`=218445 AND `ExtendedCost`=8954 AND `type`=1) OR (`entry`=219217 AND `item`=218438 AND `ExtendedCost`=8952 AND `type`=1) OR (`entry`=219217 AND `item`=218436 AND `ExtendedCost`=8952 AND `type`=1) OR (`entry`=219217 AND `item`=218447 AND `ExtendedCost`=8953 AND `type`=1) OR (`entry`=219217 AND `item`=218441 AND `ExtendedCost`=8953 AND `type`=1) OR (`entry`=219217 AND `item`=210232 AND `ExtendedCost`=8515 AND `type`=1) OR (`entry`=219215 AND `item`=225437 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225441 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225435 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225434 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225438 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225439 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225436 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225440 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225442 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225458 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225455 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225454 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225456 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225453 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225457 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225452 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225451 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225450 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225447 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225446 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225448 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225445 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225449 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225444 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225443 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225681 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225680 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225679 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225432 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225433 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225477 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225476 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225475 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225484 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225481 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225480 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225482 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225474 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225470 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225473 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225469 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225472 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225468 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225471 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225467 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225485 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225488 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225489 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225483 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225487 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225479 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225486 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225478 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225466 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225465 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225464 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225463 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225462 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225461 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225460 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=225459 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=224020 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=224018 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=224017 AND `ExtendedCost`=8908 AND `type`=1) OR (`entry`=219215 AND `item`=213778 AND `ExtendedCost`=9130 AND `type`=1) OR (`entry`=219215 AND `item`=215236 AND `ExtendedCost`=9131 AND `type`=1) OR (`entry`=219215 AND `item`=210233 AND `ExtendedCost`=8517 AND `type`=1) OR (`entry`=219215 AND `item`=210232 AND `ExtendedCost`=8515 AND `type`=1) OR (`entry`=219215 AND `item`=210221 AND `ExtendedCost`=9229 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(219212, 9, 224041, 0, 8501, 1, 0, 0, 56421), -- Holy Brigade
(219212, 8, 224042, 0, 8501, 1, 0, 0, 56421), -- Voracious Residue
(219212, 7, 224043, 0, 8501, 1, 0, 0, 56421), -- Famished Residue
(219212, 6, 224044, 0, 8501, 1, 0, 0, 56421), -- Devouring Residue
(219212, 5, 224045, 0, 8501, 1, 0, 0, 56421), -- Kelp Grasp
(219212, 4, 224046, 0, 8501, 1, 0, 0, 56421), -- Sand Tornado
(219212, 3, 224047, 0, 8501, 1, 0, 0, 56421), -- Water Blast
(219212, 2, 224048, 0, 8501, 1, 0, 0, 56421), -- Electric Shock
(219212, 1, 224049, 0, 8501, 1, 0, 0, 56421), -- Web Pull
(219222, 1, 210233, 0, 8517, 1, 122990, 1, 56421), -- Forged Gladiator's Heraldry
(219217, 98, 224556, 0, 7878, 1, 0, 0, 56421), -- Glorious Contender's Strongbox
(219217, 97, 225739, 0, 9046, 1, 0, 0, 56421), -- Algari Distinguishment
(219217, 96, 218424, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Emblem
(219217, 95, 218423, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Insignia of Alacrity
(219217, 94, 218421, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Badge of Ferocity
(219217, 93, 218425, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Sigil of Adaptation
(219217, 92, 218422, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Medallion
(219217, 91, 218431, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Pendant
(219217, 90, 218430, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Choker
(219217, 89, 218429, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Necklace
(219217, 88, 218428, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Signet
(219217, 87, 218427, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Band
(219217, 86, 218426, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Ring
(219217, 85, 218435, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Greatcloak
(219217, 84, 218434, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Cape
(219217, 83, 218432, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Drape
(219217, 82, 218433, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Cloak
(219217, 81, 218418, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Plate Armguards
(219217, 80, 218386, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Plate Cuffs
(219217, 79, 218413, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Plate Greatbelt
(219217, 78, 218381, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Plate Girdle
(219217, 77, 218399, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Plate Handguards
(219217, 76, 218367, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Plate Gauntlets
(219217, 75, 218394, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Plate Stompers
(219217, 74, 218362, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Plate Warboots
(219217, 73, 218410, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Plate Pauldrons
(219217, 72, 218378, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Plate Shoulders
(219217, 71, 218405, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Plate Wargreaves
(219217, 70, 218373, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Plate Legguards
(219217, 69, 218389, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Plate Headguard
(219217, 68, 218357, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Plate Helm
(219217, 67, 218391, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Plate Armor
(219217, 66, 218359, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Chestplate
(219217, 65, 218419, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Chain Bracer
(219217, 64, 218387, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Chain Wristwraps
(219217, 63, 218415, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Chain Clasp
(219217, 62, 218383, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Chain Belt
(219217, 61, 218401, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Chain Handguards
(219217, 60, 218369, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Chain Gauntlets
(219217, 59, 218396, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Chain Stompers
(219217, 58, 218364, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Chain Sabatons
(219217, 57, 218412, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Chain Shoulderguards
(219217, 56, 218380, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Chain Spaulders
(219217, 55, 218407, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Chain Wargreaves
(219217, 54, 218375, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Chain Leggings
(219217, 53, 218403, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Chain Headguard
(219217, 52, 218371, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Chain Helm
(219217, 51, 218392, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Armored Tunic
(219217, 50, 218360, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Armored Vest
(219217, 49, 218420, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Leather Armguards
(219217, 48, 218388, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Leather Wristwraps
(219217, 47, 218416, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Leather Cord
(219217, 46, 218384, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Leather Belt
(219217, 45, 218398, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Leather Grips
(219217, 44, 218366, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Leather Gloves
(219217, 43, 218397, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Leather Footpads
(219217, 42, 218365, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Leather Boots
(219217, 41, 218409, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Leather Mantle
(219217, 40, 218377, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Leather Spaulders
(219217, 39, 218408, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Leather Leggings
(219217, 38, 218376, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Leather Breeches
(219217, 37, 218404, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Leather Mask
(219217, 36, 218372, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Leather Helm
(219217, 35, 218393, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Leather Tunic
(219217, 34, 218361, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Leather Vest
(219217, 33, 218417, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Silk Bindings
(219217, 32, 218385, 0, 8950, 1, 0, 0, 56421), -- Forged Aspirant's Silk Wristwraps
(219217, 31, 218414, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Silk Belt
(219217, 30, 218382, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Silk Cord
(219217, 29, 218400, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Silk Handwraps
(219217, 28, 218368, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Silk Gloves
(219217, 27, 218395, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Silk Footwraps
(219217, 26, 218363, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Silk Treads
(219217, 25, 218411, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Silk Shawl
(219217, 24, 218379, 0, 8948, 1, 0, 0, 56421), -- Forged Aspirant's Silk Mantle
(219217, 23, 218406, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Silk Legwraps
(219217, 22, 218374, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Silk Leggings
(219217, 21, 218402, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Silk Cover
(219217, 20, 218370, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Silk Hood
(219217, 19, 218390, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Silk Shirt
(219217, 18, 218358, 0, 8949, 1, 0, 0, 56421), -- Forged Aspirant's Silk Robe
(219217, 17, 218452, 0, 8951, 1, 0, 0, 56421), -- Forged Aspirant's Wand
(219217, 16, 218444, 0, 8951, 1, 0, 0, 56421), -- Forged Aspirant's Scepter
(219217, 15, 218442, 0, 8954, 1, 0, 0, 56421), -- Forged Aspirant's Censer
(219217, 14, 218449, 0, 8951, 1, 0, 0, 56421), -- Forged Aspirant's Knife
(219217, 13, 218440, 0, 8953, 1, 0, 0, 56421), -- Forged Aspirant's Staff
(219217, 12, 218451, 0, 8952, 1, 0, 0, 56421), -- Forged Aspirant's Chopper
(219217, 11, 218448, 0, 8952, 1, 0, 0, 56421), -- Forged Aspirant's Morningstar
(219217, 10, 218443, 0, 8952, 1, 0, 0, 56421), -- Forged Aspirant's Warglaive
(219217, 9, 218437, 0, 8952, 1, 0, 0, 56421), -- Forged Aspirant's Dagger
(219217, 8, 218446, 0, 8953, 1, 0, 0, 56421), -- Forged Aspirant's Rifle
(219217, 7, 218439, 0, 8953, 1, 0, 0, 56421), -- Forged Aspirant's Polearm
(219217, 6, 218445, 0, 8954, 1, 0, 0, 56421), -- Forged Aspirant's Shield
(219217, 5, 218438, 0, 8952, 1, 0, 0, 56421), -- Forged Aspirant's Mace
(219217, 4, 218436, 0, 8952, 1, 0, 0, 56421), -- Forged Aspirant's Battleaxe
(219217, 3, 218447, 0, 8953, 1, 0, 0, 56421), -- Forged Aspirant's Halberd
(219217, 2, 218441, 0, 8953, 1, 0, 0, 56421), -- Forged Aspirant's Greatsword
(219217, 1, 210232, 0, 8515, 1, 122990, 1, 56421), -- Forged Aspirant's Heraldry
(219215, 69, 225437, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Cloth Bands
(219215, 68, 225441, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Cloth Sash
(219215, 67, 225435, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Cloth Shoulderpads
(219215, 66, 225434, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Cloth Leggings
(219215, 65, 225438, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Cloth Hood
(219215, 64, 225439, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Cloth Gloves
(219215, 63, 225436, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Cloth Treads
(219215, 62, 225440, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Cloth Tunic
(219215, 61, 225442, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Cloth Cloak
(219215, 60, 225458, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Chain Cuffs
(219215, 59, 225455, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Chain Girdle
(219215, 58, 225454, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Chain Epaulets
(219215, 57, 225456, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Chain Leggings
(219215, 56, 225453, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Chain Cowl
(219215, 55, 225457, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Chain Gauntlets
(219215, 54, 225452, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Chain Chainmail
(219215, 53, 225451, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Chain Treads
(219215, 52, 225450, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Leather Wristwraps
(219215, 51, 225447, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Leather Belt
(219215, 50, 225446, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Leather Shoulderpads
(219215, 49, 225448, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Leather Trousers
(219215, 48, 225445, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Leather Mask
(219215, 47, 225449, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Leather Gloves
(219215, 46, 225444, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Leather Chestpiece
(219215, 45, 225443, 0, 8908, 1, 0, 1, 56421), -- Pattern: Algari Competitor's Leather Boots
(219215, 44, 225681, 0, 8908, 1, 0, 1, 56421), -- Design: Determined Bloodstone
(219215, 43, 225680, 0, 8908, 1, 0, 1, 56421), -- Design: Cognitive Bloodstone
(219215, 42, 225679, 0, 8908, 1, 0, 1, 56421), -- Design: Enduring Bloodstone
(219215, 41, 225432, 0, 8908, 1, 0, 1, 56421), -- Design: Algari Competitor's Signet
(219215, 40, 225433, 0, 8908, 1, 0, 1, 56421), -- Design: Algari Competitor's Amulet
(219215, 39, 225477, 0, 8908, 1, 0, 1, 56421), -- Technique: Algari Competitor's Emblem
(219215, 38, 225476, 0, 8908, 1, 0, 1, 56421), -- Technique: Algari Competitor's Insignia of Alacrity
(219215, 37, 225475, 0, 8908, 1, 0, 1, 56421), -- Technique: Algari Competitor's Medallion
(219215, 36, 225484, 0, 8908, 1, 0, 1, 56421), -- Technique: Algari Competitor's Censer
(219215, 35, 225481, 0, 8908, 1, 0, 1, 56421), -- Technique: Algari Competitor's Staff
(219215, 34, 225480, 0, 8908, 1, 0, 1, 56421), -- Technique: Algari Competitor's Pillar
(219215, 33, 225482, 0, 8908, 1, 0, 1, 56421), -- Schematic: Algari Competitor's Rifle
(219215, 32, 225474, 0, 8908, 1, 0, 1, 56421), -- Schematic: Algari Competitor's Plate Bracers
(219215, 31, 225470, 0, 8908, 1, 0, 1, 56421), -- Schematic: Algari Competitor's Plate Goggles
(219215, 30, 225473, 0, 8908, 1, 0, 1, 56421), -- Schematic: Algari Competitor's Mail Bracers
(219215, 29, 225469, 0, 8908, 1, 0, 1, 56421), -- Schematic: Algari Competitor's Mail Goggles
(219215, 28, 225472, 0, 8908, 1, 0, 1, 56421), -- Schematic: Algari Competitor's Leather Bracers
(219215, 27, 225468, 0, 8908, 1, 0, 1, 56421), -- Schematic: Algari Competitor's Leather Goggles
(219215, 26, 225471, 0, 8908, 1, 0, 1, 56421), -- Schematic: Algari Competitor's Cloth Bracers
(219215, 25, 225467, 0, 8908, 1, 0, 1, 56421), -- Schematic: Algari Competitor's Cloth Goggles
(219215, 24, 225485, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Shield
(219215, 23, 225488, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Greatsword
(219215, 22, 225489, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Sword
(219215, 21, 225483, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Scepter
(219215, 20, 225487, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Skewer
(219215, 19, 225479, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Dagger
(219215, 18, 225486, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Axe
(219215, 17, 225478, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Pickaxe
(219215, 16, 225466, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Plate Armguards
(219215, 15, 225465, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Plate Waistguard
(219215, 14, 225464, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Plate Pauldrons
(219215, 13, 225463, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Plate Greaves
(219215, 12, 225462, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Plate Helm
(219215, 11, 225461, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Plate Gauntlets
(219215, 10, 225460, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Plate Sabatons
(219215, 9, 225459, 0, 8908, 1, 0, 1, 56421), -- Plans: Algari Competitor's Plate Breastplate
(219215, 8, 224020, 0, 8908, 1, 0, 1, 56421), -- Recipe: Vicious Flask of the Wrecking Ball
(219215, 7, 224018, 0, 8908, 1, 0, 1, 56421), -- Recipe: Vicious Flask of Classical Spirits
(219215, 6, 224017, 0, 8908, 1, 0, 1, 56421), -- Recipe: Vicious Flask of Honor
(219215, 5, 213778, 0, 9130, 1, 122990, 1, 56421), -- Vicious Jeweler's Setting
(219215, 4, 215236, 0, 9131, 1, 0, 1, 56421), -- Vicious Bloodstone
(219215, 3, 210233, 0, 8517, 1, 122990, 1, 56421), -- Forged Gladiator's Heraldry
(219215, 2, 210232, 0, 8515, 1, 122990, 1, 56421), -- Forged Aspirant's Heraldry
(219215, 1, 210221, 0, 9229, 1, 0, 1, 56421); -- Forged Combatant's Heraldry
