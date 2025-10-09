SET @CGUID := 7003375;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+103;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2436.609375, -664.6961669921875, 41.5509490966796875, 0.40103498101234436, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+1, 131568, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2359.798583984375, -687.1492919921875, 64.7012176513671875, 2.012466907501220703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Honey-Crazed Mauler (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259688 - Honey Crazed)
(@CGUID+2, 131568, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2466.725830078125, -657.6007080078125, 39.94602203369140625, 4.514852523803710937, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Honey-Crazed Mauler (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259688 - Honey Crazed) (possible waypoints or random movement)
(@CGUID+3, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2473.48779296875, -640.46527099609375, 35.51139450073242187, 0.194685965776443481, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked) (possible waypoints or random movement)
(@CGUID+4, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2463.1650390625, -665.109375, 41.35620880126953125, 6.136178493499755859, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+5, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2472.302001953125, -691.23089599609375, 42.15011978149414062, 1.618736743927001953, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked) (possible waypoints or random movement)
(@CGUID+6, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2453.6806640625, -688.6961669921875, 41.89596176147460937, 4.387172222137451171, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+7, 131568, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2451.138916015625, -729.2569580078125, 44.7101593017578125, 0.44803282618522644, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Honey-Crazed Mauler (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259688 - Honey Crazed)
(@CGUID+8, 131568, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2458.89404296875, -693.37677001953125, 42.38252639770507812, 0.914740920066833496, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Honey-Crazed Mauler (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259688 - Honey Crazed) (possible waypoints or random movement)
(@CGUID+9, 131568, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2427.333251953125, -740.03302001953125, 51.20001602172851562, 3.987064838409423828, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Honey-Crazed Mauler (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259688 - Honey Crazed) (possible waypoints or random movement)
(@CGUID+10, 131568, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2382.86279296875, -722.22052001953125, 60.33462142944335937, 2.767612218856811523, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Honey-Crazed Mauler (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259688 - Honey Crazed)
(@CGUID+11, 131568, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2434.725830078125, -679.17706298828125, 41.5509490966796875, 5.072628974914550781, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Honey-Crazed Mauler (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259688 - Honey Crazed) (possible waypoints or random movement)
(@CGUID+12, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2455.835205078125, -709.7742919921875, 42.7528533935546875, 3.747791290283203125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+13, 131733, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2324.29345703125, -517.6649169921875, 64.80638885498046875, 2.311542749404907226, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Questionable Meat (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+14, 131568, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2391.267333984375, -634.0382080078125, 64.16138458251953125, 2.957421779632568359, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Honey-Crazed Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2 (Auras: 259688 - Honey Crazed) (possible waypoints or random movement)
(@CGUID+15, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2352.350830078125, -522, 65.17529296875, 4.964884281158447265, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+16, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2260.53125, -462.729156494140625, 68.3033447265625, 0.265017867088317871, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+17, 131733, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2246.010498046875, -477.744781494140625, 69.87970733642578125, 3.952250957489013671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Questionable Meat (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+18, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2304.9931640625, -516.80731201171875, 64.75624847412109375, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+19, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2320.90966796875, -540.53125, 65.9415283203125, 1.395571827888488769, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+20, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2338.87158203125, -449.404510498046875, 65.66576385498046875, 4.690911293029785156, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+21, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2276.026123046875, -453.963531494140625, 66.350860595703125, 2.307700634002685546, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+22, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2295.25341796875, -452.852447509765625, 64.71331787109375, 5.423097133636474609, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+23, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2306.890625, -529.93927001953125, 64.98712921142578125, 0.912642955780029296, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+24, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2221.600830078125, -458.539947509765625, 70.63338470458984375, 5.48428201675415039, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+25, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2343.223876953125, -539.06427001953125, 65.432952880859375, 2.967021465301513671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+26, 131733, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2276.40283203125, -472.9757080078125, 66.8061065673828125, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Questionable Meat (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+27, 131733, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2307.114501953125, -518.1475830078125, 64.75624847412109375, 3.049586772918701171, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Questionable Meat (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+28, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2335.6337890625, -415.376739501953125, 72.1914215087890625, 1.837741971015930175, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+29, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2342.578125, -464.50347900390625, 66.15332794189453125, 6.210620880126953125, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+30, 131733, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2345.975830078125, -457.088531494140625, 65.55804443359375, 4.168372631072998046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Questionable Meat (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+31, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2351.0087890625, -464.578125, 66.551727294921875, 5.743721485137939453, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+32, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2297.145751953125, -435.6632080078125, 65.61571502685546875, 3.322928905487060546, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+33, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2246.147705078125, -475.510406494140625, 69.87981414794921875, 5.63665771484375, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+34, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2321.154541015625, -469.5382080078125, 66.94226837158203125, 5.00610208511352539, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+35, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2312.3837890625, -449.760406494140625, 64.4022216796875, 1.536640882492065429, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+36, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2302.147705078125, -427.685760498046875, 70.78520965576171875, 3.651776552200317382, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2 (Auras: 265075 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+37, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2335.460205078125, -504.26214599609375, 65.6402435302734375, 4.810553550720214843, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2 (Auras: 265075 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+38, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2234.94091796875, -458.98089599609375, 74.3497314453125, 4.677214622497558593, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+39, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2225.8212890625, -485.842010498046875, 70.37516021728515625, 5.500027656555175781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+40, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2298.895751953125, -409.883697509765625, 65.69966888427734375, 3.451218128204345703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+41, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2319.96875, -510.567718505859375, 65.4654998779296875, 5.17159891128540039, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+42, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2290.916748046875, -428.86285400390625, 64.38941192626953125, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+43, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2298.6962890625, -500.743072509765625, 65.8303070068359375, 1.230983972549438476, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+44, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2295.37158203125, -587.123291015625, 65.3799896240234375, 2.50281381607055664, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+45, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2275.72216796875, -469.229156494140625, 66.80689239501953125, 1.365481019020080566, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+46, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2284.63720703125, -566.59722900390625, 65.21453857421875, 1.822008132934570312, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+47, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2270.5, -580.04168701171875, 65.379425048828125, 5.819437026977539062, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+48, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2331.0244140625, -526.1180419921875, 64.78047943115234375, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+49, 131733, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2197.33154296875, -513.09722900390625, 71.95404052734375, 5.15454721450805664, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Questionable Meat (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+50, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2196.373291015625, -516.50518798828125, 73.4366607666015625, 1.52588820457458496, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+51, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2161.632080078125, -593.92535400390625, 67.2903289794921875, 0.781443536281585693, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+52, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2164.338623046875, -586.00518798828125, 67.37651824951171875, 3.543483972549438476, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+53, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2223.197998046875, -487.60589599609375, 70.9422607421875, 4.967176437377929687, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+54, 131733, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2214.486083984375, -473.49652099609375, 74.27447509765625, 3.355064630508422851, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Questionable Meat (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+55, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2166.885498046875, -402.513885498046875, 64.7661895751953125, 6.178781032562255859, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+56, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2195.567626953125, -408.33160400390625, 64.27691650390625, 3.968773841857910156, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+57, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2177.819580078125, -505.211822509765625, 70.3309478759765625, 0.923447906970977783, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+58, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2172.1025390625, -417.586822509765625, 64.79625701904296875, 4.185880184173583984, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+59, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2203.859375, -407.744781494140625, 64.49395751953125, 3.167155742645263671, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2 (Auras: 265075 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+60, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2184.79345703125, -431.401031494140625, 64.2166900634765625, 4.165657997131347656, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+61, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2204.05908203125, -426.37847900390625, 62.99933624267578125, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+62, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2190.255126953125, -420.713531494140625, 64.39855194091796875, 1.359863638877868652, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+63, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2184.364501953125, -542.451416015625, 72.6708221435546875, 3.174405097961425781, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+64, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2170.272705078125, -550.41839599609375, 70.45563507080078125, 4.2905426025390625, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+65, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2165.671875, -424.255218505859375, 64.95169830322265625, 0.541957557201385498, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+66, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2218.998291015625, -469.932281494140625, 73.40203857421875, 0.147676587104797363, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+67, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2182.8212890625, -511.1788330078125, 72.94205474853515625, 5.685309410095214843, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+68, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2163.076416015625, -555.592041015625, 69.0931854248046875, 0, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2 (Auras: 265075 - Cosmetic - Sleep Zzz Breakable)
(@CGUID+69, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2206.125, -437.94097900390625, 65.0478973388671875, 3.346315622329711914, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+70, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2182.6806640625, -406.96875, 64.0907440185546875, 0.600757002830505371, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+71, 131571, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2176.717041015625, -561.170166015625, 69.5252532958984375, 3.231507778167724609, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 62876), -- Cockroach (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+72, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2187.90283203125, -548.8350830078125, 72.48148345947265625, 2.132370471954345703, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+73, 131513, 1643, 9042, 9471, '0', 0, 0, 0, 0, 2368.75, -626.46356201171875, 62.89113998413085937, 1.8408966064453125, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 62876), -- Highlands Mauler (Area: Highland Flats - Difficulty: 0) CreateObject2
(@CGUID+74, 131568, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2422.772705078125, -576.717041015625, 47.16836929321289062, 0.762224078178405761, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Honey-Crazed Mauler (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259688 - Honey Crazed)
(@CGUID+75, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2529.565185546875, -620.47222900390625, 21.47122001647949218, 3.72560739517211914, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+76, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2498.975830078125, -581.31427001953125, 30.2337799072265625, 3.528902, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+77, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2512.576416015625, -547.84027099609375, 25.78047752380371093, 0.912292182445526123, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+78, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2498.03466796875, -617.76043701171875, 28.22982597351074218, 4.222661972045898437, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+79, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2494.984375, -557.8680419921875, 27.89641380310058593, 4.805337905883789062, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+80, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2501.12841796875, -595.17706298828125, 29.67304611206054687, 1.957271695137023925, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+81, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2525.678955078125, -619.26910400390625, 21.96204566955566406, 5.819292068481445312, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+82, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2562.0859375, -518.98089599609375, 20.06060791015625, 4.48844766616821289, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+83, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2608.306396484375, -623.85418701171875, 23.4936981201171875, 5.630792617797851562, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+84, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2553.913330078125, -548.72393798828125, 20.9806976318359375, 5.831501007080078125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+85, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2582.499267578125, -554.44964599609375, 18.73620223999023437, 4.00342559814453125, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+86, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2555.04345703125, -621.67364501953125, 20.55480575561523437, 5.878123283386230468, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+87, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2569.8603515625, -617.25518798828125, 19.77095794677734375, 0.54244542121887207, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+88, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2581.66748046875, -511.305572509765625, 19.6752166748046875, 4.976086616516113281, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+89, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2556.375, -584.4774169921875, 19.50090408325195312, 4.234559059143066406, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+90, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2558.03125, -544.07293701171875, 21.64256858825683593, 2.21253371238708496, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+91, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2557.8837890625, -648.67706298828125, 21.05070877075195312, 3.04921722412109375, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+92, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2527.69189453125, -659.265625, 21.02539253234863281, 4.533564567565917968, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+93, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2567.3212890625, -671.33331298828125, 21.135711669921875, 2.970533609390258789, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+94, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2546.4931640625, -581.03125, 19.40926933288574218, 2.249845504760742187, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+95, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2580.37939453125, -592.263916015625, 19.5750732421875, 0.028731625527143478, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+96, 133529, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2520.704833984375, -626.9774169921875, 22.57008552551269531, 0.633306145668029785, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63003), -- Channeling Target (Area: Mildenhall Meadery - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+97, 133529, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2487.963623046875, -585.97393798828125, 30.64056396484375, 0.400291293859481811, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63003), -- Channeling Target (Area: Mildenhall Meadery - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+98, 133529, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2523.8681640625, -694.82464599609375, 21.02539253234863281, 0.201646462082862854, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63003), -- Channeling Target (Area: Mildenhall Meadery - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+99, 133529, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2580.8916015625, -608.6492919921875, 20.22707366943359375, 3.804104804992675781, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63003), -- Channeling Target (Area: Mildenhall Meadery - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+100, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2461.064208984375, -527.42535400390625, 28.49271202087402343, 5.457814693450927734, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+101, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2519.671875, -538.421875, 25.65643692016601562, 6.149988651275634765, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
(@CGUID+102, 131663, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2505.013916015625, -524.11114501953125, 24.51288032531738281, 5.78884124755859375, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 63003), -- Flowing Honey (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2 (Auras: 259798 - Honey Soaked)
(@CGUID+103, 133429, 1643, 9042, 9470, '0', 0, 0, 0, 0, 2538.390625, -691.85589599609375, 21.02581787109375, 3.356070756912231445, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 63003); -- Bubbling Mead (Area: Mildenhall Meadery - Difficulty: 0) CreateObject2
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+103;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+36, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '265075'), -- Highlands Mauler - 265075 - Cosmetic - Sleep Zzz Breakable
(@CGUID+37, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '265075'), -- Highlands Mauler - 265075 - Cosmetic - Sleep Zzz Breakable
(@CGUID+59, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '265075'), -- Highlands Mauler - 265075 - Cosmetic - Sleep Zzz Breakable
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '265075'); -- Highlands Mauler - 265075 - Cosmetic - Sleep Zzz Breakable

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (131513,131663,131568);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(131513, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 131513 (Highlands Mauler) - Cosmetic - Sleep Zzz Breakable
(131663, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '259798'), -- 131663 (Flowing Honey) - Honey Soaked
(131568, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, '259688'); -- 131568 (Honey-Crazed Mauler) - Honey Crazed

-- Template
UPDATE `creature_template` SET `flags_extra`=128 WHERE `entry`=133529; -- Channeling Target

-- Difficulty
DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=0 AND `Entry` IN (232117,131513));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `TypeFlags3`) VALUES
(232117, 0, 10, 0.699999988079071044, 1, 283535, 0x0, 0, 0), -- Botanist Alaenra
(131513, 0, 10, 1.299999952316284179, 1, 137377, 0x0, 0, 0); -- Highlands Mauler

UPDATE `creature_template_difficulty` SET `ContentTuningID`=188, `VerifiedBuild`=63003 WHERE (`Entry`=133429 AND `DifficultyID`=0); -- 133429 (Bubbling Mead) - CannotSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=188, `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=131513 AND `DifficultyID`=0); -- 131513 (Highlands Mauler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=188, `StaticFlags1`=0x10000000, `VerifiedBuild`=63003 WHERE (`Entry`=131568 AND `DifficultyID`=0); -- 131568 (Honey-Crazed Mauler) - CanSwim
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x20000100, `VerifiedBuild`=63003 WHERE (`Entry`=131733 AND `DifficultyID`=0); -- 131733 (Questionable Meat) - Sessile, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=188, `StaticFlags1`=0x20000000, `VerifiedBuild`=63003 WHERE (`Entry`=133529 AND `DifficultyID`=0); -- 133529 (Channeling Target) - Floating

-- Spelltarget
DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (267465));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 267465, 0, 0, 51, 0, 5, 133529, 0, '', 0, 'Potential target of the spell is TYPEID_UNIT, entry is 133529');

DELETE FROM `conditions` WHERE (`SourceTypeOrReferenceId` = 13) AND (`SourceEntry` IN (262429));
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(13, 1, 262429, 0, 0, 51, 0, 5, 133529, 0, '', 0, 'Potential target of the spell is TYPEID_UNIT, entry is 133529');

 -- Bubbling Mead smart ai
SET @ENTRY := 133429;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`, `Difficulties`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 0, 11, 262429, 0, 0, 0, 0, 0, 0, 19, 133529, 15, 0, 0, 0, 0, 0, 'Time = 1 seconds (OOC) - Self: Cast spell  262429 on Closest alive creature Channeling Target (133529) in 15 yards', '');

UPDATE `creature` SET `StringId` = 'CosmeticChannel' WHERE `guid` IN (@CGUID+76, @CGUID+87, @CGUID+75, @CGUID+103);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceEntry` = 133429 AND `SourceId` = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ConditionStringValue1`, `NegativeCondition`, `Comment`) VALUES 
(22, 1, 133429, 0, 0, 58, 1, 0, 0, 0, 'CosmeticChannel', 0, 'Object has StringID CosmeticChannel');

-- Path for Highlands Mauler
SET @MOVERGUID := @CGUID+73;
SET @ENTRY := 131513;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Highlands Mauler - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2351.4514, -576.6285, 62.063873, NULL, 0),
(@PATH, 1, 2345.5486, -558.3455, 62.289066, NULL, 0),
(@PATH, 2, 2335.019, -535.691, 64.78919, NULL, 0),
(@PATH, 3, 2316.2014, -510.9132, 64.98137, NULL, 0),
(@PATH, 4, 2308.566, -475.49652, 63.666607, NULL, 0),
(@PATH, 5, 2308.4766, -474.5, 63.93138, NULL, 0),
(@PATH, 6, 2308.2969, -472.5078, 64.11757, NULL, 0),
(@PATH, 7, 2308.1172, -470.51562, 64.31215, NULL, 0),
(@PATH, 8, 2307.4514, -463.13196, 64.25566, NULL, 8923),
(@PATH, 9, 2308.566, -475.49652, 63.666607, NULL, 0),
(@PATH, 10, 2316.2014, -510.9132, 64.98137, NULL, 0),
(@PATH, 11, 2335.019, -535.691, 64.78919, NULL, 0),
(@PATH, 12, 2345.5486, -558.3455, 62.289066, NULL, 0),
(@PATH, 13, 2351.4514, -576.6285, 62.063873, NULL, 0),
(@PATH, 14, 2361.5261, -600.3299, 63.47316, NULL, 0),
(@PATH, 15, 2369.2466, -615.29865, 62.828926, NULL, 8131),
(@PATH, 16, 2361.5261, -600.3299, 63.47316, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Highlands Mauler
SET @MOVERGUID := @CGUID+28;
SET @ENTRY := 131513;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Highlands Mauler - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2341.981, -447.6111, 65.65106, NULL, 0),
(@PATH, 1, 2327.2378, -455.50696, 64.77006, NULL, 0),
(@PATH, 2, 2305.3386, -454.94098, 63.994278, NULL, 0),
(@PATH, 3, 2274.7812, -457.71875, 66.68825, NULL, 0),
(@PATH, 4, 2255.394, -464.37674, 68.51856, NULL, 0),
(@PATH, 5, 2240.7812, -474.95834, 69.79641, NULL, 0),
(@PATH, 6, 2228.915, -471.658, 70.29925, NULL, 0),
(@PATH, 7, 2222.9114, -464.39584, 71.31144, NULL, 6634),
(@PATH, 8, 2228.915, -471.658, 70.29925, NULL, 0),
(@PATH, 9, 2240.7812, -474.95834, 69.79641, NULL, 0),
(@PATH, 10, 2255.394, -464.37674, 68.51856, NULL, 0),
(@PATH, 11, 2274.7812, -457.71875, 66.68825, NULL, 0),
(@PATH, 12, 2305.3386, -454.94098, 63.994278, NULL, 0),
(@PATH, 13, 2327.2378, -455.50696, 64.77006, NULL, 0),
(@PATH, 14, 2341.981, -447.6111, 65.65106, NULL, 0),
(@PATH, 15, 2350.052, -421.35764, 68.30169, NULL, 0),
(@PATH, 16, 2344.5486, -405.69965, 68.01502, NULL, 7861),
(@PATH, 17, 2350.052, -421.35764, 68.30169, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Honey-Crazed Mauler
SET @MOVERGUID := @CGUID+1;
SET @ENTRY := 131568;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x0, NULL, 'Honey-Crazed Mauler - Cosmetic');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2361.0295, -645.9601, 62.31235, NULL, 0),
(@PATH, 1, 2378.3125, -629.71875, 63.402237, NULL, 0),
(@PATH, 2, 2391.4045, -615.9722, 59.20391, NULL, 0),
(@PATH, 3, 2409.9827, -608.86285, 51.96145, NULL, 0),
(@PATH, 4, 2425.8455, -601.77606, 47.736206, NULL, 0),
(@PATH, 5, 2425.9792, -585.8802, 47.09549, NULL, 0),
(@PATH, 6, 2415.2205, -567.7083, 47.085037, NULL, 8377),
(@PATH, 7, 2425.9792, -585.8802, 47.09549, NULL, 0),
(@PATH, 8, 2425.8455, -601.77606, 47.736206, NULL, 0),
(@PATH, 9, 2409.9827, -608.86285, 51.96145, NULL, 0),
(@PATH, 10, 2391.4045, -615.9722, 59.20391, NULL, 0),
(@PATH, 11, 2378.3125, -629.71875, 63.402237, NULL, 0),
(@PATH, 12, 2361.0295, -645.9601, 62.31235, NULL, 0),
(@PATH, 13, 2350.823, -668.1667, 62.847862, NULL, 0),
(@PATH, 14, 2339.2812, -682.7101, 64.13643, NULL, 8817),
(@PATH, 15, 2350.823, -668.1667, 62.847862, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`, `auras`) VALUES
(@MOVERGUID, @PATH, 1, '259688');
