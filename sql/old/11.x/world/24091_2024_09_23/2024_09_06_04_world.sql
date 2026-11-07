SET @CGUID := 10001665;
SET @OGUID := 10000249;

SET @NPCTEXTID := 600010;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+53;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 219150, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2503.2822265625, -2676.067626953125, 200.157867431640625, 1.660859107971191406, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+1, 219151, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2437.788330078125, -2702.475830078125, 200.157867431640625, 2.81162261962890625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+2, 219382, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2500.33154296875, -2676.151123046875, 200.157867431640625, 1.358306407928466796, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+3, 219150, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2446.92529296875, -2731.760498046875, 201.1471710205078125, 4.668757438659667968, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 258872 - Sit and Talk)
(@CGUID+4, 219150, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2443.93408203125, -2737.28466796875, 201.0841217041015625, 2.275865077972412109, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+5, 219150, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2456.701416015625, -2719.6806640625, 201.1589508056640625, 0.785396754741668701, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 258872 - Sit and Talk)
(@CGUID+6, 219150, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2411.208251953125, -2681.810791015625, 200.07470703125, 4.151256084442138671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+7, 219382, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2538.21875, -2703.4375, 200.157867431640625, 3.537421703338623046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 459770 - [DNT] Earthen Carry Cosmetic Random)
(@CGUID+8, 219151, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2462.5556640625, -2730.578125, 201.0841217041015625, 5.689484119415283203, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+9, 219151, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2436.34716796875, -2701.635498046875, 200.157867431640625, 5.872753620147705078, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+10, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 3, 2545.650146484375, -2680.671875, 200.15777587890625, 3.631974220275878906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+11, 219151, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2445.16845703125, -2733.92529296875, 201.1471710205078125, 0.008726147934794425, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 258872 - Sit and Talk)
(@CGUID+12, 219014, 2552, 14771, 15043, '0', '0', 0, 0, 3, 2399.70654296875, -2716.442626953125, 200.07470703125, 3.884848833084106445, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Peacekeeper (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 18950 - Invisibility and Stealth Detection)
(@CGUID+13, 219382, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2452.032958984375, -2761.498291015625, 200.0769805908203125, 4.747295379638671875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+14, 219150, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2499.088623046875, -2708.982666015625, 200.157867431640625, 3.798208951950073242, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+15, 219150, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2454.968994140625, -2760.965087890625, 200.0764923095703125, 6.241481304168701171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+16, 219151, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2456.3212890625, -2715.810791015625, 201.0980224609375, 5.462882041931152343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 258872 - Sit and Talk)
(@CGUID+17, 219382, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2535.212646484375, -2705.595458984375, 200.157867431640625, 0.622611641883850097, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Trader (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 459770 - [DNT] Earthen Carry Cosmetic Random, 382759 - Conversation Aura: Talk Only [DNT])
(@CGUID+18, 219150, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2463.9931640625, -2731.4619140625, 201.0841217041015625, 2.872225522994995117, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+19, 219151, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2497.757080078125, -2709.982666015625, 200.157867431640625, 0.768862068653106689, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Oathsworn Citizen (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 251820 - Breakable WALean 01)
(@CGUID+20, 229927, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2433.08154296875, -2719.55029296875, 201.0926055908203125, 3.73255777359008789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 436791 - Holding Mead Mug [DNT])
(@CGUID+21, 229927, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2460.657958984375, -2671.75, 200.6573638916015625, 2.344138860702514648, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+22, 229927, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2541.6103515625, -2748.9111328125, 204.9890899658203125, 5.474595069885253906, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+23, 229927, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2459.2275390625, -2670.28466796875, 200.6573638916015625, 5.48573160171508789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Unbound Crafter (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT], 459180 - [DNT] Earthen Laborer Carry Cosmetic)
(@CGUID+24, 219317, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2486.307373046875, -2739.46533203125, 200.286376953125, 3.305488824844360351, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Kornak (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+25, 226756, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2393.67529296875, -2760.092041015625, 201.458770751953125, 4.130352020263671875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Giada Goldleash (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+26, 224294, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2448.27783203125, -2735.725830078125, 201.1122283935546875, 1.610736846923828125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Osidion (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+27, 217080, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2430.30908203125, -2760.866455078125, 200.159454345703125, 0.483198612928390502, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Gostrof (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+28, 219324, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2452.27783203125, -2768.270751953125, 200.160308837890625, 1.910495281219482421, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Gerred (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+29, 219094, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2408.279541015625, -2681.960205078125, 200.2407073974609375, 6.190485000610351562, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Kotag (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+30, 226785, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2506.799560546875, -2673.163330078125, 200.701202392578125, 2.644577503204345703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Kondal Huntsworn (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+31, 219080, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2481.810791015625, -2673.819580078125, 200.55517578125, 0.972874045372009277, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Marbb (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+32, 219233, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2390.61767578125, -2762.58935546875, 201.5907135009765625, 3.826643943786621093, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56461), -- Spicy (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+33, 219081, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2470.83154296875, -2676.3525390625, 200.157867431640625, 4.771876811981201171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Krinn (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+34, 219327, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2421.97216796875, -2757.59033203125, 200.2057952880859375, 5.45415496826171875, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Nagar (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 439049 - Earthen - Carving)
(@CGUID+35, 219082, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2502.234375, -2670.564208984375, 200.497467041015625, 4.642032623291015625, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Kradan (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+36, 219100, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2405.173583984375, -2683.5869140625, 200.318878173828125, 5.367927074432373046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Berred (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+37, 219318, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2452.123291015625, -2735.661376953125, 201.0841217041015625, 1.649842619895935058, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Jorid (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 442720 - Holding Mead Mug [DNT])
(@CGUID+38, 219083, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2496.642333984375, -2672.890625, 200.497467041015625, 4.937139511108398437, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Ginnad (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+39, 219326, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2430.623291015625, -2764.432373046875, 200.36248779296875, 5.671784877777099609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Rodal (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 115865 - Cosmetic - Sit Chair High (Lower/Upper Body - High/Low Priority) (Anim Kit))
(@CGUID+40, 219076, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2492.609375, -2712.48779296875, 200.157867431640625, 2.716422080993652343, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Kornd (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+41, 219232, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2394.254150390625, -2762.01953125, 201.5907135009765625, 2.169971704483032226, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 56461), -- Geo (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+42, 219379, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2453.385498046875, -2748.161376953125, 200.3009796142578125, 4.349019050598144531, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Morek (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+43, 219230, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2392.03466796875, -2761.998291015625, 201.458770751953125, 1.597427964210510253, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Erani (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+44, 226731, 2552, 14771, 15043, '0', '0', 0, 0, 1, 2412.288330078125, -2679.51904296875, 200.2407073974609375, 2.509370326995849609, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Nelphi (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+45, 219325, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2435.38720703125, -2766.916748046875, 200.159210205078125, 1.564327001571655273, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Killm (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+46, 215365, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2413.76904296875, -2669.3125, 201.1446685791015625, 4.807636260986328125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Twill (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+47, 219380, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2376.428955078125, -2713.585205078125, 200.1703948974609375, 1.503886580467224121, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Dokhan (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+48, 219378, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2345.010498046875, -2703.4306640625, 190.228790283203125, 3.728802680969238281, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Stabled Ramolith (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+49, 219378, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2354.355712890625, -2698.137451171875, 189.9368133544921875, 5.927546977996826171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Stabled Ramolith (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+50, 219378, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2343.1806640625, -2701.310791015625, 190.2318572998046875, 3.946012735366821289, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Stabled Ramolith (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+51, 219378, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2354.91845703125, -2703.873291015625, 190.468780517578125, 1.837377190589904785, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Stabled Ramolith (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+52, 219376, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2360.491455078125, -2696.01904296875, 190.202056884765625, 1.981480240821838378, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461), -- Kargand (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@CGUID+53, 229379, 2552, 14771, 15043, '0', '0', 0, 0, 0, 2366.736083984375, -2697.083251953125, 190.5257110595703125, 6.22163248062133789, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 56461); -- Unbound Villager (Area: The Forgegrounds - Difficulty: 0) CreateObject1 (Auras: 463527 - [DNT] Earthen Pitchfork Shoveling)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+53;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+2, 0, 0, 0, 0, 0, 1, 0, 0, 30852, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, '258872'), -- Oathsworn Citizen - 258872 - Sit and Talk
(@CGUID+4, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Oathsworn Citizen
(@CGUID+5, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '258872'), -- Oathsworn Citizen - 258872 - Sit and Talk
(@CGUID+7, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '459770'), -- Unbound Trader - 459770 - [DNT] Earthen Carry Cosmetic Random
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, '258872'), -- Oathsworn Citizen - 258872 - Sit and Talk
(@CGUID+13, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Unbound Trader
(@CGUID+16, 0, 0, 0, 0, 0, 1, 0, 461, 0, 0, 0, 0, '258872'), -- Oathsworn Citizen - 258872 - Sit and Talk
(@CGUID+17, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '459770 382759'), -- Unbound Trader - 459770 - [DNT] Earthen Carry Cosmetic Random, 382759 - Conversation Aura: Talk Only [DNT]
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '251820'), -- Oathsworn Citizen - 251820 - Breakable WALean 01
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 415, 0, 0, 0, 0, '436791'), -- Unbound Crafter - 436791 - Holding Mead Mug [DNT
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '435518 459180'), -- Unbound Crafter - 435518 - Conversation Aura: Talk/Laugh/Exclaim [DNT], 459180 - [DNT] Earthen Laborer Carry Cosmetic
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Morek
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 569, 0, 0, 0, 0, ''), -- Dokhan
(@CGUID+48, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Stabled Ramolith
(@CGUID+50, 0, 0, 0, 0, 0, 1, 0, 418, 0, 0, 0, 0, ''), -- Stabled Ramolith
(@CGUID+51, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Stabled Ramolith
(@CGUID+53, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '463527'); -- Unbound Villager - 463527 - [DNT] Earthen Pitchfork Shoveling

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+51;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 428933, 2552, 14771, 15043, '0', '0', 0, 2443.939208984375, -2719.2744140625, 201.1658477783203125, 2.434729337692260742, 0, 0, 0.938190460205078125, 0.346119433641433715, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+1, 428998, 2552, 14771, 15043, '0', '0', 0, 2410.5400390625, -2677.95654296875, 200.17120361328125, 5.471609115600585937, 0, 0, -0.39474296569824218, 0.918791592121124267, 120, 255, 1, 56461), -- Tailor's Work Table (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+2, 428928, 2552, 14771, 15043, '0', '0', 0, 2440.515625, -2719.928955078125, 201.1844024658203125, 0.829030334949493408, 0, 0, 0.402746200561523437, 0.915311694145202636, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+3, 428929, 2552, 14771, 15043, '0', '0', 0, 2440.5712890625, -2716.350830078125, 201.1520538330078125, 5.576329231262207031, 0, 0, -0.3461160659790039, 0.938191711902618408, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+4, 428930, 2552, 14771, 15043, '0', '0', 0, 2444.125, -2715.62158203125, 201.1785125732421875, 3.953172922134399414, 0, 0, -0.91879081726074218, 0.394744753837585449, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+5, 428874, 2552, 14771, 15043, '0', '0', 0, 2387.001708984375, -2668.100830078125, 181.6264495849609375, 0.724311470985412597, 0, 0, 0.354290962219238281, 0.935135245323181152, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+6, 429001, 2552, 14771, 15043, '0', '0', 0, 2299.507080078125, -2636.748291015625, 190.3200836181640625, 0.715584874153137207, 0, 0, 0.350207328796386718, 0.936672210693359375, 120, 255, 1, 56461), -- Enchanter's Lectern (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+7, 428916, 2552, 14771, 15043, '0', '0', 0, 2349.25, -2642.642333984375, 190.2673492431640625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 56461), -- Bench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+8, 428853, 2552, 14771, 15043, '0', '0', 0, 2352.4619140625, -2583.328125, 181.52471923828125, 6.274459362030029296, 0, 0, -0.00436305999755859, 0.999990463256835937, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+9, 441782, 2552, 14771, 15043, '0', '0', 0, 2354.45654296875, -2719.760498046875, 265.437713623046875, 1.247910022735595703, 0, 0, 0.584249496459960937, 0.811574101448059082, 120, 255, 1, 56461), -- Stool (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+10, 428915, 2552, 14771, 15043, '0', '0', 0, 2354.59375, -2707.291748046875, 190.5108642578125, 1.509708642959594726, 0, 0, 0.685182571411132812, 0.728371381759643554, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+11, 466997, 2552, 14771, 15043, '0', '0', 0, 2408.517333984375, -2544.78125, 181.5067901611328125, 2.364918231964111328, 0, 0, 0.925539970397949218, 0.378649920225143432, 120, 255, 1, 56461), -- Anvil (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+12, 466998, 2552, 14771, 15043, '0', '0', 0, 2396.189208984375, -2557.489501953125, 181.467437744140625, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 56461), -- Anvil (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+13, 466999, 2552, 14771, 15043, '0', '0', 0, 2391.498291015625, -2610.404541015625, 181.506500244140625, 5.5065155029296875, 0, 0, -0.3786478042602539, 0.925540864467620849, 120, 255, 1, 56461), -- Anvil (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+14, 439920, 2552, 14771, 15043, '0', '0', 0, 2409.356201171875, -2557.957275390625, 189.892303466796875, 5.508151531219482421, 0, 0, -0.37789058685302734, 0.925850272178649902, 120, 255, 1, 56461), -- Blacksmithing (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+15, 445209, 2552, 14771, 15043, '0', '0', 0, 2422.4072265625, -2590.423828125, 182.6091461181640625, 3.255151271820068359, -0.03769922256469726, -0.04834747314453125, -0.99640274047851562, 0.058505181223154067, 120, 255, 1, 56461), -- Incident Report (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+16, 467000, 2552, 14771, 15043, '0', '0', 0, 2407.45654296875, -2626.850830078125, 181.506500244140625, 2.312558174133300781, 0, 0, 0.915310859680175781, 0.402748137712478637, 120, 255, 1, 56461), -- Anvil (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+17, 441764, 2552, 14771, 15043, '0', '0', 0, 2356.109375, -2757.802001953125, 265.40533447265625, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 120, 255, 1, 56461), -- Stool (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+18, 428973, 2552, 14771, 15043, '0', '0', 0, 2403.757080078125, -2668.59033203125, 181.4822845458984375, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+19, 441762, 2552, 14771, 15043, '0', '0', 0, 2351.560791015625, -2719.819580078125, 265.42626953125, 0.628316879272460937, 0, 0, 0.309016227722167968, 0.95105677843093872, 120, 255, 1, 56461), -- Stool (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+20, 439916, 2552, 14771, 15043, '0', '0', 0, 2521.404052734375, -2565.486572265625, 181.5045928955078125, 0.69569021463394165, 0, 0, 0.340872764587402343, 0.940109431743621826, 120, 255, 1, 56461), -- Engineering Special Dessert Table (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+21, 441771, 2552, 14771, 15043, '0', '0', 0, 2333.578125, -2737.708251953125, 265.40533447265625, 2.914689540863037109, 0, 0, 0.993571281433105468, 0.113208353519439697, 120, 255, 1, 56461), -- Stool (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+22, 439917, 2552, 14771, 15043, '0', '0', 0, 2512.712890625, -2557.281494140625, 181.4816436767578125, 5.617882251739501953, 0, 0, -0.32655048370361328, 0.945179760456085205, 120, 255, 1, 56461), -- Engineering Workbench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+23, 439918, 2552, 14771, 15043, '0', '0', 0, 2520.2412109375, -2558.00537109375, 189.72467041015625, 3.92476963996887207, 0, 0, -0.92430400848388671, 0.38165709376335144, 120, 255, 1, 56461), -- Engineering (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+24, 430482, 2552, 14771, 15043, '0', '0', 0, 2524.046142578125, -2498.65966796875, 200.3031768798828125, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 56461), -- Bench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+25, 439919, 2552, 14771, 15043, '0', '0', 0, 2412.91015625, -2561.537353515625, 181.421783447265625, 5.490406513214111328, 0, 0, -0.38609027862548828, 0.922460973262786865, 120, 255, 1, 56461), -- Blacksmith's Table (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+26, 439915, 2552, 14771, 15043, '0', '0', 0, 2517.156982421875, -2561.0517578125, 181.5465087890625, 3.909638166427612304, 0, 0, -0.92716503143310546, 0.374653190374374389, 120, 255, 1, 56461), -- Tinker's Workbench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+27, 415584, 2552, 14771, 15043, '0', '0', 0, 2407.25, -2592.62841796875, 182.075836181640625, 6.034471511840820312, 0, 0, -0.12403678894042968, 0.99227762222290039, 120, 255, 1, 56461), -- Sizzling Magma Core (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+28, 442746, 2552, 14771, 15043, '0', '0', 0, 2395.494873046875, -2220.7587890625, -646.01690673828125, 0, 0, 0, 0, 1, 120, 255, 1, 56461), -- Forgotten Conduit (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+29, 428919, 2552, 14771, 15043, '0', '0', 0, 2515.30810546875, -2489.9375, 200.3030548095703125, 0.802850961685180664, 0, 0, 0.390730857849121093, 0.920504987239837646, 120, 255, 1, 56461), -- Bench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+30, 428910, 2552, 14771, 15043, '0', '0', 0, 2612.833251953125, -2510.380126953125, 224.0318450927734375, 5.619960308074951171, 0, 0, -0.32556819915771484, 0.945518553256988525, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+31, 428912, 2552, 14771, 15043, '0', '0', 0, 2616.98779296875, -2514.81591796875, 224.0128021240234375, 2.164205789566040039, 0, 0, 0.882946968078613281, 0.469472706317901611, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+32, 439316, 2552, 14771, 15043, '0', '0', 0, 2512.0244140625, -2485.19970703125, 202.1114044189453125, 4.692202568054199218, -0.49535989761352539, 0.492458343505859375, -0.51727581024169921, 0.494498878717422485, 120, 255, 1, 56461), -- Trading Post Post (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+33, 467066, 2552, 14771, 15043, '0', '0', 0, 2349.75, -2540.80029296875, 199.2550048828125, 5.510816574096679687, 0, 0, -0.37665653228759765, 0.926352977752685546, 120, 255, 1, 56461), -- Rostrum of Transformation (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+34, 428975, 2552, 14771, 15043, '0', '0', 0, 2399.9150390625, -2500.647705078125, 181.4115142822265625, 6.248279094696044921, 0, 0, -0.01745223999023437, 0.999847710132598876, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+35, 428999, 2552, 14771, 15043, '0', '0', 0, 2303.907958984375, -2570.49658203125, 190.2948760986328125, 4.738570213317871093, 0, 0, -0.69779014587402343, 0.716302275657653808, 120, 255, 1, 56461), -- Jeweler's Bench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+36, 433871, 2552, 14771, 15043, '0', '0', 0, 2269.29296875, -2617.91796875, 191.54840087890625, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 56461), -- Enchanting Table (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+37, 452658, 2552, 14771, 15043, '0', '0', 0, 2277.3896484375, -2626.935546875, 191.630126953125, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+38, 429000, 2552, 14771, 15043, '0', '0', 0, 2303.70654296875, -2558.953125, 199.375091552734375, 1.579522013664245605, 0, 0, 0.710185050964355468, 0.704015016555786132, 120, 255, 1, 56461), -- Scribe's Drafting Table (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+39, 428977, 2552, 14771, 15043, '0', '0', 0, 2292.890625, -2795.458251953125, 199.218841552734375, 2.155482053756713867, 0, 0, 0.880890846252441406, 0.473319470882415771, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+40, 441768, 2552, 14771, 15043, '0', '0', 0, 2260.7744140625, -2670.944580078125, 265.40557861328125, 0.785396754741668701, 0, 0, 0.38268280029296875, 0.923879802227020263, 120, 255, 1, 56461), -- Stool (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+41, 433869, 2552, 14771, 15043, '0', '0', 0, 2277.751953125, -2574.947265625, 191.4210662841796875, 1.631884694099426269, 0, 0, 0.728371620178222656, 0.68518233299255371, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+42, 433870, 2552, 14771, 15043, '0', '0', 0, 2271.0986328125, -2594.341796875, 191.4429473876953125, 0.733038187026977539, 0, 0, 0.358367919921875, 0.933580458164215087, 120, 255, 1, 56461), -- Jewelcrafting Table (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+43, 452657, 2552, 14771, 15043, '0', '0', 0, 2274.18798828125, -2584.619140625, 191.5822906494140625, 6.265733242034912109, 0, 0, -0.00872611999511718, 0.999961912631988525, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+44, 428997, 2552, 14771, 15043, '0', '0', 0, 2311.45654296875, -2524.638916015625, 199.32843017578125, 5.61123514175415039, 0, 0, -0.32968997955322265, 0.944089233875274658, 120, 255, 1, 56461), -- Alchemist's Lab Bench (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+45, 441770, 2552, 14771, 15043, '0', '0', 0, 2289.15283203125, -2816.25, 265.40533447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 56461), -- Stool (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+46, 433720, 2552, 14771, 15043, '0', '0', 0, 2275.56591796875, -2546.99658203125, 200.5850372314453125, 5.995408535003662109, 0, 0, -0.14339256286621093, 0.989665865898132324, 120, 255, 1, 56461), -- Auditor's Manifest (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+47, 452648, 2552, 14771, 15043, '0', '0', 0, 2276.80029296875, -2548.4873046875, 199.4709625244140625, 1.553344011306762695, 0, 0, 0.700909614562988281, 0.71325010061264038, 120, 255, 1, 56461), -- Chair (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+48, 441769, 2552, 14771, 15043, '0', '0', 0, 2251.357666015625, -2823.661376953125, 265.426300048828125, 2.199114561080932617, 0, 0, 0.8910064697265625, 0.453990638256072998, 120, 255, 1, 56461), -- Stool (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+49, 441781, 2552, 14771, 15043, '0', '0', 0, 2264.7744140625, -2841.072998046875, 265.40533447265625, 3.926995515823364257, 0, 0, -0.92387866973876953, 0.38268551230430603, 120, 255, 1, 56461), -- Stool (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+50, 441778, 2552, 14771, 15043, '0', '0', 0, 2251.298583984375, -2820.763916015625, 265.437713623046875, 2.818698406219482421, 0, 0, 0.986995697021484375, 0.160746723413467407, 120, 255, 1, 56461), -- Stool (Area: The Forgegrounds - Difficulty: 0) CreateObject1
(@OGUID+51, 441761, 2552, 14771, 15043, '0', '0', 0, 2200.595458984375, -2768.388916015625, 265.42938232421875, 2.356189966201782226, 0, 0, 0.923878669738769531, 0.38268551230430603, 120, 255, 1, 56461); -- Stool (Area: The Forgegrounds - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+51;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+14, 0, 0, 1, -0.00000004371138828, 0, 0), -- Blacksmithing
(@OGUID+15, 0, 0, 1, -0.00000004371138828, 0, 0), -- Incident Report
(@OGUID+20, 0, 0, 1, -0.00000004371138828, 0, 0), -- Engineering Special Dessert Table
(@OGUID+22, 0, 0, 1, -0.00000004371138828, 0, 0), -- Engineering Workbench
(@OGUID+23, 0, 0, 1, -0.00000004371138828, 0, 0), -- Engineering
(@OGUID+25, 0, 0, 1, -0.00000004371138828, 0, 0), -- Blacksmith's Table
(@OGUID+26, 0, 0, 1, -0.00000004371138828, 0, 0), -- Tinker's Workbench
(@OGUID+28, 0, 0, 0, 1, 0, 5605), -- Forgotten Conduit
(@OGUID+36, 0, 0, 1, -0.00000004371138828, 0, 0), -- Enchanting Table
(@OGUID+37, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+41, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+42, 0, 0, 1, -0.00000004371138828, 0, 0), -- Jewelcrafting Table
(@OGUID+43, 0, 0, 1, -0.00000004371138828, 0, 0), -- Chair
(@OGUID+47, 0, 0, 1, -0.00000004371138828, 0, 0); -- Chair

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (215365 /*215365 (Twill)*/, 219230 /*219230 (Erani)*/, 219326 /*219326 (Rodal) - Cosmetic - Sit Chair High (Lower/Upper Body - High/Low Priority) (Anim Kit)*/, 219318 /*219318 (Jorid) - Holding Mead Mug [DNT]*/, 219327 /*219327 (Nagar) - Earthen - Carving*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(215365, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 215365 (Twill)
(219230, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- 219230 (Erani)
(219326, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '115865'), -- 219326 (Rodal) - Cosmetic - Sit Chair High (Lower/Upper Body - High/Low Priority) (Anim Kit)
(219318, 0, 0, 0, 0, 0, 1, 0, 0, 16425, 0, 0, 0, '442720'), -- 219318 (Jorid) - Holding Mead Mug [DNT]
(219327, 0, 0, 4, 0, 0, 1, 0, 0, 0, 0, 0, 0, '439049'); -- 219327 (Nagar) - Earthen - Carving

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (439316 /*Trading Post Post*/, 442746 /*Forgotten Conduit*/, 415584 /*Sizzling Magma Core*/, 428973 /*Chair*/, 428874 /*Chair*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(439316, 0, 262144, 0, 0), -- Trading Post Post
(442746, 0, 262176, 0, 5605), -- Forgotten Conduit
(415584, 0, 2113540, 0, 0), -- Sizzling Magma Core
(428973, 114, 0, 0, 0), -- Chair
(428874, 114, 0, 0, 0); -- Chair

-- Template
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219326; -- Rodal
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219280; -- Durakh
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=224294; -- Osidion
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219327; -- Nagar
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219379; -- Morek
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219081; -- Krinn
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=67108864 WHERE `entry`=230037; -- Trained Ramolith
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219318; -- Jorid
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=222712; -- Magmashell Crawler
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226731; -- Nelphi
UPDATE `creature_template` SET `faction`=3407, `npcflag`=83, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219094; -- Kotag
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219285; -- Ramdah
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219325; -- Killm
UPDATE `creature_template` SET `faction`=35, `npcflag`=16777216, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048, `unit_flags3`=1090519040 WHERE `entry`=215365; -- Twill
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=217080; -- Gostrof
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219324; -- Gerred
UPDATE `creature_template` SET `faction`=3407, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=227426; -- Barzelin
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219100; -- Berred
UPDATE `creature_template` SET `faction`=190, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=189105; -- Whiskuk
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=768, `unit_flags2`=2048 WHERE `entry`=226756; -- Giada Goldleash
UPDATE `creature_template` SET `faction`=3407, `npcflag`=4194465, `BaseAttackTime`=2000, `unit_flags`=512, `unit_flags2`=2048 WHERE `entry`=219230; -- Erani
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219232; -- Geo
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219385; -- Nerada
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219180; -- Cornerdweller
UPDATE `creature_template` SET `faction`=35, `speed_run`=1, `BaseAttackTime`=2000, `unit_flags2`=2048, `unit_flags3`=1082130433 WHERE `entry`=225979; -- Training Dummy
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2048 WHERE `entry`=226779; -- Halga Steelbarrow
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219274; -- Brakh
UPDATE `creature_template` SET `faction`=3407, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=219275; -- Dern

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219385 AND `DifficultyID`=0); -- 219385 (Nerada) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226779 AND `DifficultyID`=0); -- 226779 (Halga Steelbarrow) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219274 AND `DifficultyID`=0); -- 219274 (Brakh) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219275 AND `DifficultyID`=0); -- 219275 (Dern) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219233 AND `DifficultyID`=0); -- 219233 (Spicy) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `VerifiedBuild`=56461 WHERE (`Entry`=226756 AND `DifficultyID`=0); -- 226756 (Giada Goldleash) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=373, `VerifiedBuild`=56461 WHERE (`Entry`=219230 AND `DifficultyID`=0); -- 219230 (Erani) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219232 AND `DifficultyID`=0); -- 219232 (Geo) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219380 AND `DifficultyID`=0); -- 219380 (Dokhan) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=223650 AND `DifficultyID`=0); -- 223650 (Forge Hand) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=805306368, `VerifiedBuild`=56461 WHERE (`Entry`=230100 AND `DifficultyID`=0); -- 230100 (Wall Climb Vehicle) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2762, `StaticFlags1`=805306624, `VerifiedBuild`=56461 WHERE (`Entry`=230098 AND `DifficultyID`=0); -- 230098 (Spindle) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=189105 AND `DifficultyID`=0); -- 189105 (Whiskuk) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=536870912, `VerifiedBuild`=56461 WHERE (`Entry`=223793 AND `DifficultyID`=0); -- 223793 ([DNT] Forgegrounds Stalker) - Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219324 AND `DifficultyID`=0); -- 219324 (Gerred) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=227426 AND `DifficultyID`=0); -- 227426 (Barzelin) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219100 AND `DifficultyID`=0); -- 219100 (Berred) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2145, `StaticFlags1`=805306624, `VerifiedBuild`=56461 WHERE (`Entry`=222217 AND `DifficultyID`=0); -- 222217 (Crusher) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219094 AND `DifficultyID`=0); -- 219094 (Kotag) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219285 AND `DifficultyID`=0); -- 219285 (Ramdah) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219325 AND `DifficultyID`=0); -- 219325 (Killm) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=536871168, `VerifiedBuild`=56461 WHERE (`Entry`=215365 AND `DifficultyID`=0); -- 215365 (Twill) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2145, `StaticFlags1`=805306624, `VerifiedBuild`=56461 WHERE (`Entry`=222238 AND `DifficultyID`=0); -- 222238 (Crusher) - Sessile, CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435712, `VerifiedBuild`=56461 WHERE (`Entry`=219326 AND `DifficultyID`=0); -- 219326 (Rodal) - Sessile, CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219280 AND `DifficultyID`=0); -- 219280 (Durakh) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=224294 AND `DifficultyID`=0); -- 224294 (Osidion) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219327 AND `DifficultyID`=0); -- 219327 (Nagar) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219379 AND `DifficultyID`=0); -- 219379 (Morek) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219081 AND `DifficultyID`=0); -- 219081 (Krinn) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=230037 AND `DifficultyID`=0); -- 230037 (Trained Ramolith) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2734, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=219318 AND `DifficultyID`=0); -- 219318 (Jorid) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=371, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=222712 AND `DifficultyID`=0); -- 222712 (Magmashell Crawler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=268435456, `VerifiedBuild`=56461 WHERE (`Entry`=226731 AND `DifficultyID`=0); -- 226731 (Nelphi) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID`=121168;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(121168, 2.675816059112548828, 4, 0, 56461);

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=217080 AND `MenuID`=34050) OR (`CreatureID`=219230 AND `MenuID`=29540) OR (`CreatureID`=219094 AND `MenuID`=36354) OR (`CreatureID`=219080 AND `MenuID`=36358) OR (`CreatureID`=219083 AND `MenuID`=36349) OR (`CreatureID`=219376 AND `MenuID` = 9821);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(217080, 34050, 56461), -- Gostrof
(219230, 29540, 56461), -- Erani
(219094, 36354, 56461), -- Kotag
(219080, 36358, 56461), -- Marbb
(219083, 36349, 56461), -- Ginnad
(219376, 9821, 56461); -- Kargand

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+0;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 257741, 0, 0, 0, 0, 0, 0, 0, 56461); -- 217080 (Gostrof)

DELETE FROM `gossip_menu` WHERE (`MenuID`=34050 AND `TextID`=@NPCTEXTID+0);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(34050, @NPCTEXTID+0, 56461); -- 217080 (Gostrof)

DELETE FROM `gossip_menu` WHERE (`TextID`=14126 AND `MenuID` IN (36354,36358,36349));
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(36354, 14126, 56461), -- 219094 (Kotag)
(36358, 14126, 56461), -- 219080 (Marbb)
(36349, 14126, 56461); -- 219083 (Ginnad)

UPDATE `gossip_menu` SET `VerifiedBuild`=56461 WHERE (`MenuID`=29540 AND `TextID`=590103);
DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (36358,36349,36354));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(36358, 124246, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(36349, 124237, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461),
(36354, 124243, 0, 3, 'Train me.', 3266, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 56461);

UPDATE `gossip_menu_option` SET `VerifiedBuild`=56461 WHERE (`MenuID`=29540 AND `OptionID`=0);

-- Trainer
DELETE FROM `creature_trainer` WHERE (`CreatureID`=219094 AND `MenuID`=36354 AND `OptionID`=0) OR (`CreatureID`=219080 AND `MenuID`=36358 AND `OptionID`=0) OR (`CreatureID`=219083 AND `MenuID`=36349 AND `OptionID`=0);
INSERT INTO `creature_trainer` (`CreatureID`, `TrainerID`, `MenuID`, `OptionID`) VALUES
(219094, 1126, 36354, 0),
(219080, 1123, 36358, 0),
(219083, 1125, 36349, 0);

DELETE FROM `trainer` WHERE `Id` IN (1126, 1123, 1125);
INSERT INTO `trainer` (`Id`, `Type`, `Greeting`, `VerifiedBuild`) VALUES
(1126, 2, 'Hello, friend!', 56461),
(1123, 2, 'Hello, friend!', 56461),
(1125, 2, 'Hello, friend!', 56461);

DELETE FROM `trainer_spell` WHERE (`TrainerId`=1126 AND `SpellId` IN (423355,264617,446975,456706,454397,447002,446998,446997,446996,446978,446976,446969,446968,446967,446966,446965,446964,446963,446962,446961,446960,446959,446958,446957,446956,446955,446929)) OR (`TrainerId`=1123 AND `SpellId` IN (423352,444087,444086,444079,444078,444077,444076,444075,444120,444118,444116,444114,444112,444110,444107,444105,444122,444104,443709,443708,443707,443706,443705,443704,443703,443701,443700,443699,443698,443697,443696,443695,264578)) OR (`TrainerId`=1125 AND `SpellId` IN (423354,265856));
INSERT INTO `trainer_spell` (`TrainerId`, `SpellId`, `MoneyCost`, `ReqSkillLine`, `ReqSkillRank`, `ReqAbility1`, `ReqAbility2`, `ReqAbility3`, `ReqLevel`, `VerifiedBuild`) VALUES
(1126, 423355, 950000, 197, 1, 0, 0, 0, 68, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 264617, 10, 0, 0, 0, 0, 0, 5, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446975, 2565000, 2883, 50, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 456706, 2565000, 2883, 50, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 454397, 1520000, 2883, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 447002, 760000, 2883, 5, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446998, 1995000, 2883, 40, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446997, 2280000, 2883, 45, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446996, 1995000, 2883, 40, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446978, 1900000, 2883, 35, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446976, 1520000, 2883, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446969, 1520000, 2883, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446968, 1520000, 2883, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446967, 1520000, 2883, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446966, 1520000, 2883, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446965, 1520000, 2883, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446964, 1520000, 2883, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446963, 1900000, 2883, 35, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446962, 1900000, 2883, 35, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446961, 1520000, 2883, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446960, 1330000, 2883, 15, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446959, 1615000, 2883, 30, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446958, 1520000, 2883, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446957, 1425000, 2883, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446956, 760000, 2883, 5, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446955, 1045000, 2883, 10, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1126, 446929, 760000, 2883, 5, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 423352, 950000, 165, 1, 0, 0, 0, 68, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444087, 1235000, 2880, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444086, 1235000, 2880, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444079, 1235000, 2880, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444078, 1235000, 2880, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444077, 1235000, 2880, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444076, 1235000, 2880, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444075, 1235000, 2880, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444120, 570000, 2880, 5, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444118, 950000, 2880, 15, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444116, 1235000, 2880, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444114, 1330000, 2880, 30, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444112, 760000, 2880, 10, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444110, 1330000, 2880, 30, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444107, 1425000, 2880, 35, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444105, 1425000, 2880, 35, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444122, 950000, 2880, 50, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 444104, 760000, 2880, 10, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443709, 1045000, 2880, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443708, 1520000, 2880, 40, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443707, 1615000, 2880, 45, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443706, 1710000, 2880, 50, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443705, 1235000, 2880, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443704, 570000, 2880, 5, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443703, 760000, 2880, 10, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443701, 1045000, 2880, 20, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443700, 1520000, 2880, 40, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443699, 1615000, 2880, 45, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443698, 1710000, 2880, 50, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443697, 1235000, 2880, 25, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443696, 570000, 2880, 5, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 443695, 760000, 2880, 10, 0, 0, 0, 0, 56461), -- No Faction found! MoneyCost not recalculated!
(1123, 264578, 10, 0, 0, 0, 0, 0, 5, 56461), -- No Faction found! MoneyCost not recalculated!
(1125, 423354, 950000, 393, 1, 0, 0, 0, 68, 56461), -- No Faction found! MoneyCost not recalculated!
(1125, 265856, 10, 0, 0, 0, 0, 0, 5, 56461); -- No Faction found! MoneyCost not recalculated!

-- Vendor
DELETE FROM `npc_vendor` WHERE (`entry`=219380 AND `item`=228489 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219380 AND `item`=228488 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=224294 AND `item`=219100 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219101 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219102 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219103 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219104 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219106 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219107 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219108 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219109 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219111 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219112 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219113 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219116 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219117 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219118 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219119 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219120 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219121 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219122 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219123 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219124 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219126 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219127 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219128 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219129 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219130 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219131 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219133 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=224294 AND `item`=219134 AND `ExtendedCost`=8570 AND `type`=1) OR (`entry`=219318 AND `item`=188152 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=64670 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=138293 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=6256 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=10498 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=6219 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=20815 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=6218 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=222701 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=222700 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=222699 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=222697 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=222696 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=222695 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=224764 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=38682 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=200860 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219318 AND `item`=211806 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219379 AND `item`=228458 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219379 AND `item`=60241 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219324 AND `item`=228455 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219324 AND `item`=228456 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219325 AND `item`=228482 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219325 AND `item`=228481 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219327 AND `item`=228487 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219327 AND `item`=228485 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219327 AND `item`=228483 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219230 AND `item`=222978 AND `ExtendedCost`=5887 AND `type`=1) OR (`entry`=219230 AND `item`=221811 AND `ExtendedCost`=5887 AND `type`=1) OR (`entry`=219230 AND `item`=221761 AND `ExtendedCost`=5887 AND `type`=1) OR (`entry`=219230 AND `item`=221494 AND `ExtendedCost`=5887 AND `type`=1) OR (`entry`=219230 AND `item`=224101 AND `ExtendedCost`=5887 AND `type`=1) OR (`entry`=219230 AND `item`=122457 AND `ExtendedCost`=7237 AND `type`=1) OR (`entry`=219230 AND `item`=98715 AND `ExtendedCost`=6433 AND `type`=1) OR (`entry`=219230 AND `item`=86143 AND `ExtendedCost`=6435 AND `type`=1) OR (`entry`=219230 AND `item`=116429 AND `ExtendedCost`=6436 AND `type`=1) OR (`entry`=219100 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219100 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219100 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219100 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219100 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219100 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219100 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219100 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219100 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219100 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219100 AND `item`=228930 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219100 AND `item`=224764 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219100 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=228930 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=224764 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219081 AND `item`=212667 AND `ExtendedCost`=9343 AND `type`=1) OR (`entry`=219081 AND `item`=212664 AND `ExtendedCost`=9342 AND `type`=1) OR (`entry`=219082 AND `item`=2324 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=2325 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=2604 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=2605 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=4340 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=4341 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=4342 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=6260 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=6261 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=10290 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=228930 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=224764 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=7005 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219082 AND `item`=212667 AND `ExtendedCost`=9343 AND `type`=1) OR (`entry`=219082 AND `item`=212664 AND `ExtendedCost`=9342 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(219380, 2, 228489, 0, 0, 1, 0, 0, 56461), -- Fashionable Flask
(219380, 1, 228488, 0, 0, 1, 0, 0, 56461), -- Small Glass Vase
(224294, 60, 219100, 0, 8570, 1, 0, 0, 56461), -- Cardinal Educator's Knowledge
(224294, 59, 219101, 0, 8570, 1, 0, 0, 56461), -- Lilac Educator's Knowledge
(224294, 58, 219102, 0, 8570, 1, 0, 0, 56461), -- Leafy Educator's Knowledge
(224294, 57, 219103, 0, 8570, 1, 0, 0, 56461), -- Cobalt Educator's Knowledge
(224294, 56, 219104, 0, 8570, 1, 0, 0, 56461), -- Midnight Educator's Knowledge
(224294, 55, 219106, 0, 8570, 1, 0, 0, 56461), -- Maroon Quotidian Wear
(224294, 54, 219107, 0, 8570, 1, 0, 0, 56461), -- Earthy Quotidian Wear
(224294, 53, 219108, 0, 8570, 1, 0, 0, 56461), -- Umber Quotidian Wear
(224294, 52, 219109, 0, 8570, 1, 0, 0, 56461), -- Taupe Quotidian Wear
(224294, 51, 219111, 0, 8570, 1, 0, 0, 56461), -- Royal Patron's Elegance
(224294, 50, 219112, 0, 8570, 1, 0, 0, 56461), -- Verdant Patron's Elegance
(224294, 49, 219113, 0, 8570, 1, 0, 0, 56461), -- Celestial Patron's Elegance
(224294, 47, 219116, 0, 8570, 1, 0, 0, 56461), -- Arcane Peddler's Trinkets
(224294, 46, 219117, 0, 8570, 1, 0, 0, 56461), -- Curious Peddler's Trinkets
(224294, 45, 219118, 0, 8570, 1, 0, 0, 56461), -- Peculiar Peddler's Trinkets
(224294, 44, 219119, 0, 8570, 1, 0, 0, 56461), -- Occult Peddler's Trinkets
(224294, 43, 219120, 0, 8570, 1, 0, 0, 56461), -- Toiler's Khaki Uniform
(224294, 42, 219121, 0, 8570, 1, 0, 0, 56461), -- Toiler's Ochre Uniform
(224294, 41, 219122, 0, 8570, 1, 0, 0, 56461), -- Toiler's Burgundy Uniform
(224294, 40, 219123, 0, 8570, 1, 0, 0, 56461), -- Toiler's Beige Uniform
(224294, 39, 219124, 0, 8570, 1, 0, 0, 56461), -- Toiler's Navy Uniform
(224294, 38, 219126, 0, 8570, 1, 0, 0, 56461), -- Woven Artisan's Talent
(224294, 37, 219127, 0, 8570, 1, 0, 0, 56461), -- Cast Artisan's Talent
(224294, 36, 219128, 0, 8570, 1, 0, 0, 56461), -- Stained Artisan's Talent
(224294, 35, 219129, 0, 8570, 1, 0, 0, 56461), -- Sooty Artisan's Talent
(224294, 34, 219130, 0, 8570, 1, 0, 0, 56461), -- Saffron Cartographer's Orientation
(224294, 33, 219131, 0, 8570, 1, 0, 0, 56461), -- Oceanic Cartographer's Orientation
(224294, 32, 219133, 0, 8570, 1, 0, 0, 56461), -- Deep Cartographer's Orientation
(224294, 31, 219134, 0, 8570, 1, 0, 0, 56461), -- Mossy Cartographer's Orientation
(219318, 23, 188152, 0, 0, 1, 0, 0, 56461), -- Gateway Control Shard
(219318, 22, 64670, 0, 0, 1, 0, 0, 56461), -- Vanishing Powder
(219318, 21, 138293, 0, 0, 1, 0, 0, 56461), -- Explorer's Pack
(219318, 20, 85663, 0, 0, 1, 0, 0, 56461), -- Herbalist's Spade
(219318, 19, 2901, 0, 0, 1, 0, 0, 56461), -- Mining Pick
(219318, 18, 7005, 0, 0, 1, 0, 0, 56461), -- Skinning Knife
(219318, 17, 39505, 0, 0, 1, 0, 0, 56461), -- Virtuoso Inking Set
(219318, 16, 6256, 0, 0, 1, 0, 0, 56461), -- Fishing Pole
(219318, 15, 10498, 0, 0, 1, 0, 0, 56461), -- Gyromatic Micro-Adjustor
(219318, 14, 6219, 0, 0, 1, 0, 0, 56461), -- Arclight Spanner
(219318, 13, 20815, 0, 0, 1, 0, 0, 56461), -- Jeweler's Toolset
(219318, 12, 6218, 0, 0, 1, 0, 0, 56461), -- Runed Copper Rod
(219318, 11, 5956, 0, 0, 1, 0, 0, 56461), -- Blacksmith Hammer
(219318, 10, 222701, 0, 0, 1, 0, 0, 56461), -- Clumped Flour
(219318, 9, 222700, 0, 0, 1, 0, 0, 56461), -- Granulated Spices
(219318, 8, 222699, 0, 0, 1, 0, 0, 56461), -- Khaz Algar Tomato
(219318, 7, 222697, 0, 0, 1, 0, 0, 56461), -- Coreway Dust
(219318, 6, 222696, 0, 0, 1, 0, 0, 56461), -- Crunchy Peppers
(219318, 5, 222695, 0, 0, 1, 0, 0, 56461), -- Twined Herbs
(219318, 4, 224764, 0, 0, 1, 0, 0, 56461), -- Mosswool Thread
(219318, 3, 38682, 0, 0, 1, 0, 0, 56461), -- Enchanting Vellum
(219318, 2, 200860, 0, 0, 1, 0, 0, 56461), -- Draconic Stopper
(219318, 1, 211806, 0, 0, 1, 0, 0, 56461), -- Gilded Vial
(219379, 2, 228458, 0, 0, 1, 0, 0, 56461), -- Bouldercloth Bag
(219379, 1, 60241, 0, 0, 1, 0, 0, 56461), -- Dusty Bag
(219324, 2, 228455, 0, 0, 1, 0, 0, 56461), -- Bolt of Bouldercloth
(219324, 1, 228456, 0, 0, 1, 0, 0, 56461), -- Bouldercloth
(219325, 2, 228482, 0, 0, 1, 0, 0, 56461), -- Cracked Iridescent Pearl
(219325, 1, 228481, 0, 0, 1, 0, 0, 56461), -- Tiny Fathomclam
(219327, 3, 228487, 0, 0, 1, 0, 0, 56461), -- Freshly Fallen Sticks
(219327, 2, 228485, 0, 0, 1, 0, 0, 56461), -- Carver's Spare Whittling Knife
(219327, 1, 228483, 0, 0, 1, 0, 0, 56461), -- Lovingly Carved Ramolith
(219230, 9, 222978, 0, 5887, 1, 0, 0, 56461), -- Sandstone Ramolith
(219230, 8, 221811, 0, 5887, 1, 0, 0, 56461), -- Starkstripe Hopper
(219230, 7, 221761, 0, 5887, 1, 0, 0, 56461), -- Venomwing
(219230, 6, 221494, 0, 5887, 1, 0, 0, 56461), -- Skippy
(219230, 5, 224101, 0, 5887, 1, 0, 0, 56461), -- Brown Leafbug
(219230, 4, 122457, 0, 7237, 1, 0, 0, 56461), -- Ultimate Battle-Training Stone
(219230, 3, 98715, 0, 6433, 1, 0, 0, 56461), -- Marked Flawless Battle-Stone
(219230, 2, 86143, 0, 6435, 1, 0, 0, 56461), -- Battle Pet Bandage
(219230, 1, 116429, 0, 6436, 1, 0, 0, 56461), -- Flawless Battle-Training Stone
(219100, 429, 2324, 0, 0, 1, 0, 0, 56461), -- Bleach
(219100, 428, 2325, 0, 0, 1, 0, 0, 56461), -- Black Dye
(219100, 427, 2604, 0, 0, 1, 0, 0, 56461), -- Red Dye
(219100, 426, 2605, 0, 0, 1, 0, 0, 56461), -- Green Dye
(219100, 425, 4340, 0, 0, 1, 0, 0, 56461), -- Gray Dye
(219100, 424, 4341, 0, 0, 1, 0, 0, 56461), -- Yellow Dye
(219100, 423, 4342, 0, 0, 1, 0, 0, 56461), -- Purple Dye
(219100, 422, 6260, 0, 0, 1, 0, 0, 56461), -- Blue Dye
(219100, 421, 6261, 0, 0, 1, 0, 0, 56461), -- Orange Dye
(219100, 420, 10290, 0, 0, 1, 0, 0, 56461), -- Pink Dye
(219100, 419, 228930, 0, 0, 1, 0, 0, 56461), -- Adorning Ribbon
(219100, 418, 224764, 0, 0, 1, 0, 0, 56461), -- Mosswool Thread
(219100, 417, 7005, 0, 0, 1, 0, 0, 56461), -- Skinning Knife
(219081, 405, 2324, 0, 0, 1, 0, 0, 56461), -- Bleach
(219081, 404, 2325, 0, 0, 1, 0, 0, 56461), -- Black Dye
(219081, 403, 2604, 0, 0, 1, 0, 0, 56461), -- Red Dye
(219081, 402, 2605, 0, 0, 1, 0, 0, 56461), -- Green Dye
(219081, 401, 4340, 0, 0, 1, 0, 0, 56461), -- Gray Dye
(219081, 400, 4341, 0, 0, 1, 0, 0, 56461), -- Yellow Dye
(219081, 399, 4342, 0, 0, 1, 0, 0, 56461), -- Purple Dye
(219081, 398, 6260, 0, 0, 1, 0, 0, 56461), -- Blue Dye
(219081, 397, 6261, 0, 0, 1, 0, 0, 56461), -- Orange Dye
(219081, 396, 10290, 0, 0, 1, 0, 0, 56461), -- Pink Dye
(219081, 395, 228930, 0, 0, 1, 0, 0, 56461), -- Adorning Ribbon
(219081, 394, 224764, 0, 0, 1, 0, 0, 56461), -- Mosswool Thread
(219081, 393, 7005, 0, 0, 1, 0, 0, 56461), -- Skinning Knife
(219081, 15, 212667, 0, 9343, 1, 0, 0, 56461), -- Gloom Chitin
(219081, 14, 212664, 0, 9342, 1, 0, 0, 56461), -- Stormcharged Leather
(219082, 444, 2324, 0, 0, 1, 0, 0, 56461), -- Bleach
(219082, 443, 2325, 0, 0, 1, 0, 0, 56461), -- Black Dye
(219082, 442, 2604, 0, 0, 1, 0, 0, 56461), -- Red Dye
(219082, 441, 2605, 0, 0, 1, 0, 0, 56461), -- Green Dye
(219082, 440, 4340, 0, 0, 1, 0, 0, 56461), -- Gray Dye
(219082, 439, 4341, 0, 0, 1, 0, 0, 56461), -- Yellow Dye
(219082, 438, 4342, 0, 0, 1, 0, 0, 56461), -- Purple Dye
(219082, 437, 6260, 0, 0, 1, 0, 0, 56461), -- Blue Dye
(219082, 436, 6261, 0, 0, 1, 0, 0, 56461), -- Orange Dye
(219082, 435, 10290, 0, 0, 1, 0, 0, 56461), -- Pink Dye
(219082, 434, 228930, 0, 0, 1, 0, 0, 56461), -- Adorning Ribbon
(219082, 433, 224764, 0, 0, 1, 0, 0, 56461), -- Mosswool Thread
(219082, 432, 7005, 0, 0, 1, 0, 0, 56461), -- Skinning Knife
(219082, 15, 212667, 0, 9343, 1, 0, 0, 56461), -- Gloom Chitin
(219082, 14, 212664, 0, 9342, 1, 0, 0, 56461); -- Stormcharged Leather

DELETE FROM `npc_vendor` WHERE (`entry`=219076 AND `item`=227317 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219076 AND `item`=227318 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219076 AND `item`=227310 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219076 AND `item`=227309 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219076 AND `item`=217896 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219317 AND `item`=85663 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219317 AND `item`=39489 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219317 AND `item`=39505 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219317 AND `item`=211806 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219317 AND `item`=226205 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=219317 AND `item`=226204 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(219076, 5, 227317, 0, 0, 1, 0, 0, 56461), -- Lava Cola
(219076, 4, 227318, 0, 0, 1, 0, 0, 56461), -- Quicksilver Sipper
(219076, 3, 227310, 0, 0, 1, 0, 0, 56461), -- Magmalaid
(219076, 2, 227309, 0, 0, 1, 0, 0, 56461), -- Titanshake
(219076, 1, 217896, 0, 0, 1, 0, 0, 56461), -- Cinderbrew Mead
(219317, 6, 85663, 0, 0, 1, 0, 0, 56461), -- Herbalist's Spade
(219317, 5, 39489, 0, 0, 1, 0, 0, 56461), -- Scribe's Satchel
(219317, 4, 39505, 0, 0, 1, 0, 0, 56461), -- Virtuoso Inking Set
(219317, 3, 211806, 0, 0, 1, 0, 0, 56461), -- Gilded Vial
(219317, 2, 226205, 0, 0, 1, 0, 0, 56461), -- Distilled Algari Freshwater
(219317, 1, 226204, 0, 0, 1, 0, 0, 56461); -- Fresh Parchment

DELETE FROM `npc_vendor` WHERE (`entry`=219376 AND `item`=222978 AND `ExtendedCost`=5887 AND `type`=1) OR (`entry`=219376 AND `item`=221811 AND `ExtendedCost`=5887 AND `type`=1) OR (`entry`=219376 AND `item`=221761 AND `ExtendedCost`=5887 AND `type`=1) OR (`entry`=219376 AND `item`=221494 AND `ExtendedCost`=5887 AND `type`=1) OR (`entry`=219376 AND `item`=224101 AND `ExtendedCost`=5887 AND `type`=1) OR (`entry`=219376 AND `item`=37460 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(219376, 21, 222978, 0, 5887, 1, 0, 0, 56461), -- Sandstone Ramolith
(219376, 20, 221811, 0, 5887, 1, 0, 0, 56461), -- Starkstripe Hopper
(219376, 19, 221761, 0, 5887, 1, 0, 0, 56461), -- Venomwing
(219376, 18, 221494, 0, 5887, 1, 0, 0, 56461), -- Skippy
(219376, 17, 224101, 0, 5887, 1, 0, 0, 56461), -- Brown Leafbug
(219376, 1, 37460, 0, 0, 1, 0, 0, 56461); -- Rope Pet Leash

-- Path for Oathsworn Peacekeeper
SET @MOVERGUID := @CGUID+12;
SET @ENTRY := 219014;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Peacekeeper - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2408.507, -2708.3542, 200.0747, NULL, 0),
(@PATH, 1, 2416.842, -2700.052, 200.0747, NULL, 0),
(@PATH, 2, 2424.8542, -2691.842, 200.0747, NULL, 0),
(@PATH, 3, 2441.9236, -2691.7708, 200.07454, NULL, 0),
(@PATH, 4, 2491.6892, -2691.6077, 200.07454, NULL, 0),
(@PATH, 5, 2525.0183, -2691.7673, 200.0745, NULL, 5591),
(@PATH, 6, 2491.6892, -2691.6077, 200.07454, NULL, 0),
(@PATH, 7, 2441.9236, -2691.7708, 200.07454, NULL, 0),
(@PATH, 8, 2424.8542, -2691.842, 200.0747, NULL, 0),
(@PATH, 9, 2416.842, -2700.052, 200.0747, NULL, 0),
(@PATH, 10, 2408.507, -2708.3542, 200.0747, NULL, 0),
(@PATH, 11, 2399.7065, -2716.4426, 200.0747, NULL, 3836);

UPDATE `creature` SET `position_x`=2408.507, `position_y`=-2708.3542, `position_z`=200.0747, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Oathsworn Citizen
SET @MOVERGUID := @CGUID+15;
SET @ENTRY := 219150;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Citizen - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2474.434, -2754.677, 200.07515, NULL, 0),
(@PATH, 1, 2483.3906, -2746.4097, 200.07454, NULL, 0),
(@PATH, 2, 2484.6458, -2744.0815, 200.38757, NULL, 3001),
(@PATH, 3, 2481.1528, -2738.8508, 200.07454, NULL, 0),
(@PATH, 4, 2481.1145, -2730.441, 200.07452, NULL, 0),
(@PATH, 5, 2481.0364, -2723.2395, 200.07454, NULL, 0),
(@PATH, 6, 2484.9045, -2711.1719, 200.07452, NULL, 0),
(@PATH, 7, 2491.842, -2704.4219, 200.07454, NULL, 0),
(@PATH, 8, 2500.1946, -2704.5051, 200.07454, NULL, 0),
(@PATH, 9, 2505.6736, -2703.6233, 200.07454, NULL, 0),
(@PATH, 10, 2473.1077, -2678.4792, 200.07454, NULL, 6575),
(@PATH, 11, 2455.361, -2681.4983, 200.07454, NULL, 0),
(@PATH, 12, 2447.677, -2682.1355, 200.07455, NULL, 0),
(@PATH, 13, 2441.375, -2681.8438, 200.07454, NULL, 0),
(@PATH, 14, 2432.684, -2681.184, 200.07454, NULL, 0),
(@PATH, 15, 2421.337, -2680.9236, 200.0747, NULL, 0),
(@PATH, 16, 2414.9895, -2682.8438, 200.0747, NULL, 0),
(@PATH, 17, 2408.712, -2687.3508, 200.0747, NULL, 0),
(@PATH, 18, 2401.4167, -2693.8333, 200.0747, NULL, 0),
(@PATH, 19, 2392.5261, -2706.0227, 200.0747, NULL, 0),
(@PATH, 20, 2382.1284, -2713.3196, 200.0747, NULL, 5026),
(@PATH, 21, 2385.1406, -2722.4514, 200.0747, NULL, 0),
(@PATH, 22, 2395.1807, -2732.4653, 200.0747, NULL, 0),
(@PATH, 23, 2409.9446, -2739.7744, 200.07468, NULL, 0),
(@PATH, 24, 2414.4602, -2742.1875, 200.07462, NULL, 0),
(@PATH, 25, 2422.6807, -2752.519, 200.07454, NULL, 0),
(@PATH, 26, 2429.9775, -2759.2673, 200.07687, NULL, 0),
(@PATH, 27, 2434.5105, -2760.764, 200.07559, NULL, 0),
(@PATH, 28, 2446.7014, -2760.6199, 200.07535, NULL, 0),
(@PATH, 29, 2458.467, -2761.111, 200.07698, NULL, 0),
(@PATH, 30, 2468.3315, -2758.5486, 200.07686, NULL, 0);

UPDATE `creature` SET `position_x`=2474.434, `position_y`=-2754.677, `position_z`=200.07515, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Oathsworn Citizen
SET @MOVERGUID := @CGUID+6;
SET @ENTRY := 219150;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Oathsworn Citizen - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2407.1562, -2686.4133, 200.0747, NULL, 9024),
(@PATH, 1, 2402.573, -2690.7031, 200.0747, NULL, 3751),
(@PATH, 2, 2409.2327, -2684.927, 200.0747, NULL, 0),
(@PATH, 3, 2411.2083, -2681.8108, 200.0747, NULL, 4936),
(@PATH, 4, 2408.7083, -2685.7883, 200.0747, NULL, 0);

UPDATE `creature` SET `position_x`=2407.1562, `position_y`=-2686.4133, `position_z`=200.0747, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Stabled Ramolith
SET @MOVERGUID := @CGUID+49;
SET @ENTRY := 219378;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0, NULL, 'Stabled Ramolith - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2361.4426, -2701.606, 189.99391, NULL, 0),
(@PATH, 1, 2366.1633, -2706.0557, 190.17456, NULL, 8017),
(@PATH, 2, 2358.462, -2699.5972, 189.93073, NULL, 0),
(@PATH, 3, 2353.8872, -2697.8264, 189.9511, NULL, 0),
(@PATH, 4, 2349.0383, -2697.2395, 190.11212, NULL, 0),
(@PATH, 5, 2346.3403, -2696.8716, 190.20067, NULL, 7905),
(@PATH, 6, 2352.415, -2697.4167, 189.97208, NULL, 0),
(@PATH, 7, 2357.486, -2699.3003, 189.87994, NULL, 0);

UPDATE `creature` SET `position_x`=2361.4426, `position_y`=-2701.606, `position_z`=189.99391, `orientation`=0, `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
