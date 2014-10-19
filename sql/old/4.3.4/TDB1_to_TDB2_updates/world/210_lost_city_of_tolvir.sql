SET @OGUID := 164446;

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+7;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 206660, 755, 1, 1, -10687.06, -1309.015, 18.34057, 3.403396, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: The Warlord's Garrison)
(@OGUID+1, 206661, 755, 1, 1, -10687.06, -1309.015, 18.34058, 3.403396, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: The Warlord's Garrison)
(@OGUID+2, 207409, 755, 1, 1, -10752.43, -1310.148, 15.30941, 5.829401, 0, 0, 0, 1, 7200, 255, 1), -- -Unknown- (Area: The Warlord's Garrison)
(@OGUID+3, 205365, 755, 1, 1, -10937.4, -1400.58, 10.3038, 3.141593, 1.191104E-43, 0, 0, 2.802597E-44, 7200, 255, 1), -- -Unknown- (Area: The Warlord's Garrison)
(@OGUID+4, 207338, 755, 1, 1, -10937.4, -1400.5, 10.2844, 3.141593, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: The Warlord's Garrison)
(@OGUID+5, 207596, 755, 1, 1, -10809.85, -1351.196, 17.3134, 3.479464, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: The Warlord's Garrison)
(@OGUID+6, 207595, 755, 1, 1, -11081.09, -1296.448, 13.20066, 1.489785, 0, 0, 1, -4.371139E-08, 7200, 255, 1), -- -Unknown- (Area: Terrace of the Augurs)
(@OGUID+7, 207594, 755, 1, 1, -11061.35, -1280.109, 13.20066, 3.112825, 0, 0, 1, -4.371139E-08, 7200, 255, 1); -- -Unknown- (Area: Terrace of the Augurs)


DELETE FROM `creature_template_addon` WHERE `entry` IN (45096, 45096, 45096, 45096, 45096, 45097, 45096, 45097, 45096, 45096, 45096, 45096, 50038, 50036, 50037, 49732, 49835, 44981, 44932, 44924, 44926, 49835, 49732, 44981, 45001, 44922, 45007, 45007, 45001, 45007, 44922, 44924, 45007, 49835, 44577, 44586, 44586, 44586, 44586, 44586, 44586, 44586, 44586, 44897, 44896, 44897, 44898, 45001, 45001, 44896, 49732, 45122, 45122, 49732, 49732, 44922, 44977, 44976, 44981, 44819, 49835, 45342, 43612, 44932, 44922, 49732, 49835, 49743, 49219, 44981, 44896, 44897, 44898, 44896, 44897, 44898, 49835, 44976, 50496, 47720, 47720, 47720, 44926, 44924, 44981, 44261, 50496, 44796, 44796, 44796, 44796, 44796, 44796, 44796, 44796, 44796, 44796, 44796, 44796, 49732, 45377, 50496, 44898, 50496, 45062, 44982, 49743, 49835, 44982, 44924, 45007, 44922, 49743, 50496, 45007, 44981, 49725, 50496, 50496, 44922, 44926, 44932, 50496, 43614, 49725, 50491, 50491, 50496, 50491, 50496, 45124, 50491, 50490, 49725, 49725, 50491, 45124, 45124, 50490, 45124, 45124, 45124, 45124, 50491, 32638, 32639, 50496, 45062, 44981, 47720, 45065, 49743, 45065, 49732, 44976, 44982, 44922, 50496, 50496, 50496, 44976, 44981, 44982, 50496, 45065, 44980, 49743, 49743, 47720, 44982, 44981, 44980, 44976, 44977, 44976, 44982, 49835, 37231, 37231, 50496, 37231, 37231, 37231, 37231, 50496, 45007, 44976, 45065, 45065, 44982, 44980, 45065, 44922, 37231, 37231, 45065, 45007, 47720, 49732, 49732, 47720, 47720, 45065, 45065, 44977, 44980, 45065, 48092, 48097, 48097, 48092, 48092, 48097, 48092, 48097, 48097, 48092, 48097, 48092);
INSERT INTO `creature_template_addon` (`entry`, `mount`, `bytes1`, `bytes2`, `auras`) VALUES
(45096, 0, 0x0, 0x1, '84186'), -- Tamed Tol'vir Prowler - Cosmetic - Sleep Zzz
(45097, 0, 0x0, 0x1, ''), -- Oathsworn Tamer
(50038, 0, 0x0, 0x1, ''), -- Captain Hadan
(50036, 0, 0x0, 0x1, ''), -- Ramkahen Scout
(50037, 0, 0x0, 0x1, ''), -- Ramkahen Scout
(49732, 0, 0x0, 0x1, ''), -- Horned Lizard
(49835, 0, 0x0, 0x1, ''), -- Desert Spider
(44981, 0, 0x0, 0x1, ''), -- Oathsworn Skinner
(44932, 0, 0x0, 0x1, ''), -- Oathsworn Pathfinder
(44924, 0, 0x0, 0x1, '82671'), -- Oathsworn Myrmidon - Bladed Shield Spike
(44926, 0, 0x0, 0x1, ''), -- Oathsworn Wanderer
-- (45001, 0, 0x0, 0x1, '84062'), -- Enslaved Bandit - Emote State - Applause / Cheer
(44922, 0, 0x0, 0x1, ''), -- Oathsworn Axemaster
(45007, 0, 0x0, 0x1, ''), -- Enslaved Bandit
-- (45001, 0, 0x0, 0x1, '84070'), -- Enslaved Bandit - Emote State - Shout / Cheer
(44577, 0, 0x0, 0x1, ''), -- General Husam
(44586, 0, 0x3000000, 0x1, ''), -- Bad Intentions Target
(44897, 0, 0x0, 0x1, ''), -- Pygmy Scout
(44896, 0, 0x0, 0x1, ''), -- Pygmy Brute
-- (44897, 0, 0x0, 0x1, '46598'), -- Pygmy Scout - Ride Vehicle Hardcoded
-- (44898, 0, 0x0, 0x1, '46598'), -- Pygmy Firebreather - Ride Vehicle Hardcoded
(45001, 0, 0x0, 0x1, ''), -- Enslaved Bandit
-- (45001, 0, 0x0, 0x1, '84072'), -- Enslaved Bandit - Emote State - Exclaim / No
(45122, 0, 0x0, 0x1, ''), -- Oathsworn Captain
(44977, 0, 0x0, 0x1, ''), -- Neferset Torturer
(44976, 0, 0x0, 0x1, ''), -- Neferset Plaguebringer
(44819, 0, 0x0, 0x1, ''), -- Siamat
(45342, 0, 0x0, 0x1, '86483'), -- Storm Locale - Single Rainbow
(43612, 0, 0x0, 0x1, ''), -- High Prophet Barim
(49743, 0, 0x0, 0x1, ''), -- Dung Beetle
(49219, 0, 0x0, 0x1, ''), -- Burning Soul
(50496, 0, 0x3000000, 0x1, ''), -- Oasis Moth
(47720, 0, 0x0, 0x1, ''), -- Camel
(44261, 0, 0x3000000, 0x1, ''), -- Sharptalon Eagle
(44796, 0, 0x0, 0x1, '46598'), -- Tol'vir Land Mine - Ride Vehicle Hardcoded
(45377, 0, 0x0, 0x1, ''), -- Augh
(44898, 0, 0x0, 0x1, ''), -- Pygmy Firebreather
(45062, 0, 0x0, 0x1, ''), -- Oathsworn Scorpid Keeper
(44982, 0, 0x0, 0x1, ''), -- Neferset Darkcaster
(49725, 0, 0x0, 0x1, ''), -- Emerald Boa
(43614, 0, 0x0, 0x1, ''), -- Lockmaw
(50491, 0, 0x0, 0x1, ''), -- Mac Frog
(45124, 0, 0x0, 0x1, ''), -- Add Stalker
(50490, 0, 0x0, 0x1, ''), -- Locust
(32638, 0, 0x0, 0x1, '61424'), -- Hakmud of Argus - Traveler's Tundra Mammoth
(32639, 0, 0x0, 0x1, '61424'), -- Gnimo - Traveler's Tundra Mammoth
(45065, 0, 0x0, 0x1, ''), -- Tol'vir Merchant
(44980, 0, 0x0, 0x1, ''), -- Neferset Theurgist
(37231, 0, 0x0, 0x1, ''), -- Rope Beam Stalker
-- (45007, 0, 0x0, 0x1, '16245'), -- Enslaved Bandit - Freeze Anim
(48092, 0, 0x0, 0x1, '89698'), -- Wind Tunnel - Wind Tunnel
(48097, 0, 0x0, 0x1, ''); -- Wind Tunnel Landing Zone

SET @CGUID := 221351;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+199;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 53488, 755, 1, 1, -10702.53, -1313.526, 17.6862, 0, 7200, 0, 0), -- Summon Enabler Stalker (Area: The Warlord's Garrison)
(@CGUID+1, 45096, 755, 1, 1, -10717.9, -1277.29, 15.43603, 3.298672, 7200, 0, 0), -- Tamed Tol'vir Prowler (Area: The Warlord's Garrison)
(@CGUID+2, 45096, 755, 1, 1, -10728.8, -1285.88, 15.43603, 0.8901179, 7200, 0, 0), -- Tamed Tol'vir Prowler (Area: The Warlord's Garrison)
(@CGUID+3, 45096, 755, 1, 1, -10742.7, -1288.73, 15.43603, 5.899213, 7200, 0, 0), -- Tamed Tol'vir Prowler (Area: The Warlord's Garrison)
(@CGUID+4, 45096, 755, 1, 1, -10715.1, -1287.94, 15.43603, 2.740167, 7200, 0, 0), -- Tamed Tol'vir Prowler (Area: The Warlord's Garrison)
(@CGUID+5, 45096, 755, 1, 1, -10735.5, -1284.2, 15.43603, 4.380776, 7200, 0, 0), -- Tamed Tol'vir Prowler (Area: The Warlord's Garrison)
(@CGUID+6, 45097, 755, 1, 1, -10715.8, -1283.062, 15.3854, 3.490364, 7200, 0, 0), -- Oathsworn Tamer (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+7, 45096, 755, 1, 1, -10699.1, -1339.87, 15.43603, 2.513274, 7200, 0, 0), -- Tamed Tol'vir Prowler (Area: The Warlord's Garrison)
(@CGUID+8, 45097, 755, 1, 1, -10703.43, -1344.97, 15.4777, 3.445467, 7200, 0, 0), -- Oathsworn Tamer (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+9, 45096, 755, 1, 1, -10711.7, -1354.37, 15.43603, 3.630285, 7200, 0, 0), -- Tamed Tol'vir Prowler (Area: The Warlord's Garrison)
(@CGUID+10, 45096, 755, 1, 1, -10718.1, -1351.84, 15.43603, 5.270895, 7200, 0, 0), -- Tamed Tol'vir Prowler (Area: The Warlord's Garrison)
(@CGUID+11, 45096, 755, 1, 1, -10723.7, -1351.58, 15.43603, 2.024582, 7200, 0, 0), -- Tamed Tol'vir Prowler (Area: The Warlord's Garrison)
(@CGUID+12, 45096, 755, 1, 1, -10701, -1350.09, 15.43603, 3.630285, 7200, 0, 0), -- Tamed Tol'vir Prowler (Area: The Warlord's Garrison)
(@CGUID+13, 50038, 755, 1, 1, -10696.31, -1311.684, 17.6862, 3.403392, 7200, 0, 0), -- Captain Hadan (Area: The Warlord's Garrison)
(@CGUID+14, 50036, 755, 1, 1, -10694.88, -1305.34, 18.02543, 3.595378, 7200, 0, 0), -- Ramkahen Scout (Area: The Warlord's Garrison)
(@CGUID+15, 50037, 755, 1, 1, -10691.72, -1316.764, 18.0256, 3.473205, 7200, 0, 0), -- Ramkahen Scout (Area: The Warlord's Garrison)
(@CGUID+16, 49732, 755, 1, 1, -10723.8, -1284.534, 15.3854, 6.265067, 7200, 0, 0), -- Horned Lizard (Area: The Warlord's Garrison)
(@CGUID+17, 49835, 755, 1, 1, -10731.31, -1335.133, 15.4777, 0.1813482, 7200, 0, 0), -- Desert Spider (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+18, 44981, 755, 1, 1, -10750.8, -1368.59, 15.43603, 3.926991, 7200, 0, 0), -- Oathsworn Skinner (Area: The Warlord's Garrison)
(@CGUID+19, 44932, 755, 1, 1, -10758.1, -1369.04, 15.43603, 5.044002, 7200, 0, 0), -- Oathsworn Pathfinder (Area: The Warlord's Garrison)
(@CGUID+20, 44924, 755, 1, 1, -10753, -1378.72, 15.43603, 2.094395, 7200, 0, 0), -- Oathsworn Myrmidon (Area: The Warlord's Garrison)
(@CGUID+21, 44926, 755, 1, 1, -10784, -1298.25, 15.43603, 2.146755, 7200, 0, 0), -- Oathsworn Wanderer (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+22, 49835, 755, 1, 1, -10767.17, -1292.183, 15.40277, 3.924337, 7200, 0, 0), -- Desert Spider (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+23, 49732, 755, 1, 1, -10766.04, -1287.711, 15.39636, 1.08678, 7200, 0, 0), -- Horned Lizard (Area: The Warlord's Garrison)
(@CGUID+24, 44981, 755, 1, 1, -10783.3, -1288.84, 15.43603, 3.525565, 7200, 0, 0), -- Oathsworn Skinner (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+25, 45001, 755, 1, 1, -10731.4, -1395.14, 15.43603, 3.508112, 7200, 0, 0), -- Enslaved Bandit (Area: The Warlord's Garrison)
(@CGUID+26, 44922, 755, 1, 1, -10760.6, -1379.4, 15.43603, 0.6632251, 7200, 0, 0), -- Oathsworn Axemaster (Area: The Warlord's Garrison)
(@CGUID+27, 45007, 755, 1, 1, -10737.5, -1394.56, 15.43603, 3.682645, 7200, 0, 0), -- Enslaved Bandit (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+28, 45007, 755, 1, 1, -10788, -1291.09, 15.43603, 3.246312, 7200, 0, 0), -- Enslaved Bandit (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+29, 45001, 755, 1, 1, -10732, -1400.14, 15.43603, 2.530727, 7200, 0, 0), -- Enslaved Bandit (Area: The Warlord's Garrison)
(@CGUID+30, 45007, 755, 1, 1, -10741.7, -1396.38, 15.43603, 0, 7200, 0, 0), -- Enslaved Bandit (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+31, 44922, 755, 1, 1, -10793.8, -1285.84, 15.43603, 5.72468, 7200, 0, 0), -- Oathsworn Axemaster (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+32, 44924, 755, 1, 1, -10795.8, -1292.77, 15.43603, 0.418879, 7200, 0, 0), -- Oathsworn Myrmidon (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+33, 45007, 755, 1, 1, -10734.6, -1404.64, 15.43603, 2.094395, 7200, 0, 0), -- Enslaved Bandit (Area: The Warlord's Garrison)
(@CGUID+34, 49835, 755, 1, 1, -10738.63, -1392.072, 15.47772, 4.00379, 7200, 0, 0), -- Desert Spider (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+35, 44577, 755, 1, 1, -10858, -1364.31, 15.43603, 3.420845, 7200, 0, 0), -- General Husam (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+36, 44586, 755, 1, 1, -10881.61, -1348.891, 27.96363, 0.2792527, 7200, 0, 0), -- Bad Intentions Target (Area: The Warlord's Garrison)
(@CGUID+37, 44586, 755, 1, 1, -10869.75, -1389.601, 28.12603, 0.03490658, 7200, 0, 0), -- Bad Intentions Target (Area: The Warlord's Garrison)
(@CGUID+38, 44586, 755, 1, 1, -10884.4, -1353.424, 27.95413, 4.991642, 7200, 0, 0), -- Bad Intentions Target (Area: The Warlord's Garrison)
(@CGUID+39, 44586, 755, 1, 1, -10874.1, -1386.257, 28.57507, 1.815142, 7200, 0, 0), -- Bad Intentions Target (Area: The Warlord's Garrison)
(@CGUID+40, 44586, 755, 1, 1, -10886.31, -1345.097, 28.08513, 1.884956, 7200, 0, 0), -- Bad Intentions Target (Area: The Warlord's Garrison)
(@CGUID+41, 44586, 755, 1, 1, -10872.4, -1394.326, 28.20153, 5.078908, 7200, 0, 0), -- Bad Intentions Target (Area: The Warlord's Garrison)
(@CGUID+42, 44586, 755, 1, 1, -10889.8, -1350.47, 28.13524, 3.473205, 7200, 0, 0), -- Bad Intentions Target (Area: The Warlord's Garrison)
(@CGUID+43, 44586, 755, 1, 1, -10877.43, -1391.359, 27.96223, 3.473205, 7200, 0, 0), -- Bad Intentions Target (Area: The Warlord's Garrison)
(@CGUID+44, 44897, 755, 1, 1, -10957.5, -1485.63, 6.767189, 1.146581, 7200, 0, 0), -- Pygmy Scout (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+45, 44896, 755, 1, 1, -10952.29, -1499.962, 6.759735, 0.5934119, 7200, 0, 0), -- Pygmy Brute (Area: The Warlord's Garrison) (possible waypoints or random movement)
-- (@CGUID+688, 44897, 0, 1, 1, -0.0607, 0, 1.1799, 0, 7200, 0, 0), -- Pygmy Scout (Area: The Warlord's Garrison) - !!! on transport (NYI) !!! (possible waypoints or random movement)
-- (@CGUID+688, 44898, 0, 1, 1, -0.06073758, 0, 1.179883, 0, 7200, 0, 0), -- Pygmy Firebreather (Area: The Warlord's Garrison) - !!! on transport (NYI) !!! (possible waypoints or random movement)
(@CGUID+46, 45001, 755, 1, 1, -10742.7, -1405.46, 15.43603, 1.815142, 7200, 0, 0), -- Enslaved Bandit (Area: The Warlord's Garrison)
(@CGUID+47, 45001, 755, 1, 1, -10738.6, -1406.5, 15.43603, 1.780236, 7200, 0, 0), -- Enslaved Bandit (Area: The Warlord's Garrison)
(@CGUID+48, 44896, 755, 1, 1, -10968.13, -1496.2, 6.759732, 0.7853982, 7200, 0, 0), -- Pygmy Brute (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+49, 49732, 755, 1, 1, -10794.21, -1393.75, 15.47772, 4.371437, 7200, 0, 0), -- Horned Lizard (Area: The Warlord's Garrison)
(@CGUID+50, 45122, 755, 1, 1, -10795.36, -1406.129, 15.42857, 3.809066, 7200, 0, 0), -- Oathsworn Captain (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+51, 45122, 755, 1, 1, -10830.25, -1297.257, 15.42047, 3.379167, 7200, 0, 0), -- Oathsworn Captain (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+52, 49732, 755, 1, 1, -10867.83, -1337.295, 15.47772, 3.454659, 7200, 0, 0), -- Horned Lizard (Area: The Warlord's Garrison)
(@CGUID+53, 49732, 755, 1, 1, -10860.57, -1326.876, 15.47772, 4.679432, 7200, 0, 0), -- Horned Lizard (Area: The Warlord's Garrison)
(@CGUID+54, 44922, 755, 1, 1, -10878.8, -1330.79, 15.43603, 0.8726646, 7200, 0, 0), -- Oathsworn Axemaster (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+55, 44977, 755, 1, 1, -10869.7, -1331.66, 15.43603, 2.565634, 7200, 0, 0), -- Neferset Torturer (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+56, 44976, 755, 1, 1, -10878.9, -1322.44, 15.43603, 5.689773, 7200, 0, 0), -- Neferset Plaguebringer (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+57, 44981, 755, 1, 1, -10870.2, -1322.68, 15.43603, 4.066617, 7200, 0, 0), -- Oathsworn Skinner (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+58, 44819, 755, 1, 1, -10948.5, -1399.79, 35.55273, 2.408554, 7200, 0, 0), -- Siamat (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+59, 49835, 755, 1, 1, -10894.23, -1377.027, 15.47772, 1.580289, 7200, 0, 0), -- Desert Spider (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+60, 45342, 755, 1, 1, -10989.6, -1408.82, 35.71183, 6.003932, 7200, 0, 0), -- Storm Locale (Area: The Warlord's Garrison)
(@CGUID+61, 43612, 755, 1, 1, -11018.6, -1261.16, 13.32593, 4.817109, 7200, 0, 0), -- High Prophet Barim (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+62, 44932, 755, 1, 1, -10858.4, -1403, 15.43603, 5.61996, 7200, 0, 0), -- Oathsworn Pathfinder (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+63, 44922, 755, 1, 1, -10851.9, -1401.14, 15.43603, 4.625123, 7200, 0, 0), -- Oathsworn Axemaster (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+64, 49732, 755, 1, 1, -10942.52, -1276.307, 10.8854, 4.244499, 7200, 0, 0), -- Horned Lizard (Area: The Warlord's Garrison)
(@CGUID+65, 49835, 755, 1, 1, -10941.89, -1271.671, 10.8854, 5.161344, 7200, 0, 0), -- Desert Spider (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+66, 49743, 755, 1, 1, -10960.71, -1295.397, 10.8854, 0.7183092, 7200, 0, 0), -- Dung Beetle (Area: The Warlord's Garrison)
(@CGUID+67, 49219, 755, 1, 1, -10944.83, -1259.014, 10.8901, 0, 7200, 0, 0), -- Burning Soul (Area: The Warlord's Garrison)
(@CGUID+68, 44981, 755, 1, 1, -10846.9, -1408.22, 15.43603, 2.268928, 7200, 0, 0), -- Oathsworn Skinner (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+69, 44896, 755, 1, 1, -10978.35, -1605.314, 6.578125, 1.832596, 7200, 0, 0), -- Pygmy Brute (Area: The Warlord's Garrison) (possible waypoints or random movement)
-- (@CGUID+712, 44897, 0, 1, 1, -0.0607, 0, 1.1799, 0, 7200, 0, 0), -- Pygmy Scout (Area: The Warlord's Garrison) - !!! on transport (NYI) !!! (possible waypoints or random movement)
-- (@CGUID+712, 44898, 0, 1, 1, -0.06073758, 0, 1.179883, 0, 7200, 0, 0), -- Pygmy Firebreather (Area: The Warlord's Garrison) - !!! on transport (NYI) !!! (possible waypoints or random movement)
(@CGUID+70, 44896, 755, 1, 1, -10998.73, -1582.326, 6.593321, 6.178465, 7200, 0, 0), -- Pygmy Brute (Area: The Warlord's Garrison) (possible waypoints or random movement)
-- (@CGUID+713, 44897, 0, 1, 1, -0.0607, 0, 1.1799, 0, 7200, 0, 0), -- Pygmy Scout (Area: The Warlord's Garrison) - !!! on transport (NYI) !!! (possible waypoints or random movement)
-- (@CGUID+713, 44898, 0, 1, 1, -0.06073758, 0, 1.179883, 0, 7200, 0, 0), -- Pygmy Firebreather (Area: The Warlord's Garrison) - !!! on transport (NYI) !!! (possible waypoints or random movement)
(@CGUID+71, 49835, 755, 1, 1, -10869.31, -1408.753, 15.43948, 1.739047, 7200, 0, 0), -- Desert Spider (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+72, 44976, 755, 1, 1, -10855.1, -1410.81, 15.43603, 1.500983, 7200, 0, 0), -- Neferset Plaguebringer (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+73, 50496, 755, 1, 1, -10927.11, -1470.482, 10.42825, 0.3068974, 7200, 0, 0), -- Oasis Moth (Area: The Warlord's Garrison)
(@CGUID+74, 47720, 755, 1, 1, -11005.9, -1390.45, 10.89013, 2.932153, 7200, 0, 0), -- Camel (Area: The Warlord's Garrison)
(@CGUID+75, 47720, 755, 1, 1, -11003.1, -1388.22, 10.89013, 5.550147, 7200, 0, 0), -- Camel (Area: The Warlord's Garrison)
(@CGUID+76, 47720, 755, 1, 1, -10997.2, -1382.02, 10.89013, 4.363323, 7200, 0, 0), -- Camel (Area: The Warlord's Garrison)
(@CGUID+77, 44926, 755, 1, 1, -10906.4, -1490.86, 6.759744, 5.61996, 7200, 0, 0), -- Oathsworn Wanderer (Area: Sanctum of the South Wind) (possible waypoints or random movement)
(@CGUID+78, 44924, 755, 1, 1, -10908.6, -1498, 6.759744, 0.4537856, 7200, 0, 0), -- Oathsworn Myrmidon (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+79, 44981, 755, 1, 1, -10898.9, -1497.4, 6.759744, 2.86234, 7200, 0, 0), -- Oathsworn Skinner (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+80, 44261, 755, 1, 1, -10912.47, -1487.805, 22.50149, 0.4182364, 7200, 0, 0), -- Sharptalon Eagle (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+81, 50496, 755, 1, 1, -10877.08, -1503.305, 11.04868, 2.435273, 7200, 0, 0), -- Oasis Moth (Area: The Warlord's Garrison)
-- (@CGUID+724, 44796, 0, 1, 1, 0, 0, 0, 0, 7200, 0, 0), -- Tol'vir Land Mine (Area: The Warlord's Garrison) - !!! on transport (NYI) !!!
-- (@CGUID+724, 44796, 0, 1, 1, 0, 0, 0, 0, 7200, 0, 0), -- Tol'vir Land Mine (Area: The Warlord's Garrison) - !!! on transport (NYI) !!! (possible waypoints or random movement)
(@CGUID+82, 49732, 755, 1, 1, -10912.68, -1505.343, 6.763939, 2.234175, 7200, 0, 0), -- Horned Lizard (Area: The Warlord's Garrison)
(@CGUID+83, 45377, 755, 1, 1, -10978.3, -1587.67, 6.311274, 0.9948376, 7200, 0, 0), -- Augh (Area: The Warlord's Garrison) (possible waypoints or random movement)
(@CGUID+84, 50496, 755, 1, 1, -10979.05, -1501.246, 9.123808, 2.51614, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+85, 44898, 755, 1, 1, -10966.08, -1507.366, 10.73325, 0.6632251, 7200, 0, 0), -- Pygmy Firebreather (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+86, 50496, 755, 1, 1, -11000.46, -1503.657, 10.32466, 4.807743, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+87, 45062, 755, 1, 1, -10994.78, -1501.035, 6.759734, 4.049164, 7200, 0, 0), -- Oathsworn Scorpid Keeper (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+88, 44982, 755, 1, 1, -10996.6, -1510.486, 6.759734, 2.251475, 7200, 0, 0), -- Neferset Darkcaster (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+89, 49743, 755, 1, 1, -10991.89, -1473.916, 6.761546, 1.675602, 7200, 0, 0), -- Dung Beetle (Area: The Trapper's Enclave)
(@CGUID+90, 49835, 755, 1, 1, -10986.82, -1463.708, 6.681905, 4.184319, 7200, 0, 0), -- Desert Spider (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+91, 44982, 755, 1, 1, -11011.3, -1475.51, 6.759734, 2.321288, 7200, 0, 0), -- Neferset Darkcaster (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+92, 44924, 755, 1, 1, -11010.6, -1468.63, 6.759734, 3.577925, 7200, 0, 0), -- Oathsworn Myrmidon (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+93, 45007, 755, 1, 1, -11002.79, -1500.905, 6.759734, 5.166174, 7200, 0, 0), -- Enslaved Bandit (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+94, 44922, 755, 1, 1, -11004.98, -1509.448, 6.759734, 0.9250245, 7200, 0, 0), -- Oathsworn Axemaster (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+95, 49743, 755, 1, 1, -11010.24, -1511.41, 6.800141, 0.6684008, 7200, 0, 0), -- Dung Beetle (Area: The Trapper's Enclave)
(@CGUID+96, 50496, 755, 1, 1, -11009.64, -1459.143, 8.96263, 0.8061266, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+97, 45007, 755, 1, 1, -11023.4, -1470.65, 6.759734, 5.742133, 7200, 0, 0), -- Enslaved Bandit (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+98, 44981, 755, 1, 1, -11021.8, -1478.07, 6.759734, 1.500983, 7200, 0, 0), -- Oathsworn Skinner (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+99, 49725, 755, 1, 1, -11025.89, -1508.948, 6.760407, 1.244334, 7200, 0, 0), -- Emerald Boa (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+100, 50496, 755, 1, 1, -11022.95, -1494.951, 10.33994, 2.829646, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+101, 50496, 755, 1, 1, -11022.93, -1511.974, 9.775724, 4.512177, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+102, 44922, 755, 1, 1, -11021.5, -1463.53, 6.759734, 5.5676, 7200, 0, 0), -- Oathsworn Axemaster (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+103, 44926, 755, 1, 1, -11026.5, -1513.41, 6.759734, 3.455752, 7200, 0, 0), -- Oathsworn Wanderer (Area: The Trapper's Enclave)
(@CGUID+104, 44932, 755, 1, 1, -11039.7, -1509.69, 6.759734, 4.939282, 7200, 0, 0), -- Oathsworn Pathfinder (Area: The Trapper's Enclave)
(@CGUID+105, 50496, 755, 1, 1, -11038.79, -1510.049, 8.545758, 4.647817, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+106, 43614, 755, 1, 1, -11058.1, -1656.58, 0.8279553, 0.715585, 7200, 0, 0), -- Lockmaw (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+107, 49725, 755, 1, 1, -11048.61, -1510.841, 6.798261, 0.2137415, 7200, 0, 0), -- Emerald Boa (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+108, 50491, 755, 1, 1, -10977.26, -1589.047, 6.305853, 6.134747, 7200, 0, 0), -- Mac Frog (Area: The Trapper's Enclave)
(@CGUID+109, 50491, 755, 1, 1, -11052.17, -1522.637, 6.788048, 3.002179, 7200, 0, 0), -- Mac Frog (Area: The Trapper's Enclave)
(@CGUID+110, 50496, 755, 1, 1, -11048.68, -1519.563, 9.600751, 3.493381, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+111, 50491, 755, 1, 1, -11036.58, -1575.156, 0.5306947, 0.5621505, 7200, 0, 0), -- Mac Frog (Area: The Trapper's Enclave)
(@CGUID+112, 50496, 755, 1, 1, -11060.47, -1510.14, 8.725437, 4.112632, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+113, 45124, 755, 1, 1, -10987.2, -1660.37, 1.453323, 1.762783, 7200, 0, 0), -- Add Stalker (Area: The Trapper's Enclave)
(@CGUID+114, 50491, 755, 1, 1, -10979.18, -1653.236, 0.08044004, 1.277468, 7200, 0, 0), -- Mac Frog (Area: The Trapper's Enclave)
(@CGUID+115, 50490, 755, 1, 1, -10993.67, -1642.55, 1.179498, 0.6200623, 7200, 0, 0), -- Locust (Area: The Trapper's Enclave)
(@CGUID+116, 49725, 755, 1, 1, -10893.32, -1634.817, 10.13192, 3.915089, 7200, 0, 0), -- Emerald Boa (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+117, 49725, 755, 1, 1, -10902.25, -1637.207, 9.558862, 2.939642, 7200, 0, 0), -- Emerald Boa (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+118, 50491, 755, 1, 1, -10997.27, -1674.396, 0.1134961, 1.289814, 7200, 0, 0), -- Mac Frog (Area: Oasis of the Fallen Prophet)
(@CGUID+119, 45124, 755, 1, 1, -11065.3, -1580.95, 1.533023, 4.625123, 7200, 0, 0), -- Add Stalker (Area: Oasis of the Fallen Prophet)
(@CGUID+120, 45124, 755, 1, 1, -11084.2, -1622.91, 1.811483, 0.4014257, 7200, 0, 0), -- Add Stalker (Area: Oasis of the Fallen Prophet)
(@CGUID+121, 50490, 755, 1, 1, -11077.22, -1635.167, 0.6936857, 1.847488, 7200, 0, 0), -- Locust (Area: Oasis of the Fallen Prophet)
(@CGUID+122, 45124, 755, 1, 1, -11014.5, -1695.01, 1.206273, 2.146755, 7200, 0, 0), -- Add Stalker (Area: Oasis of the Fallen Prophet)
(@CGUID+123, 45124, 755, 1, 1, -11017.1, -1676.24, 1.643833, 2.216568, 7200, 0, 0), -- Add Stalker (Area: Oasis of the Fallen Prophet)
(@CGUID+124, 45124, 755, 1, 1, -11095.4, -1633.63, 2.356323, 5.846853, 7200, 0, 0), -- Add Stalker (Area: Oasis of the Fallen Prophet)
(@CGUID+125, 45124, 755, 1, 1, -11036.8, -1694.15, 1.594813, 0.4014257, 7200, 0, 0), -- Add Stalker (Area: Oasis of the Fallen Prophet)
(@CGUID+126, 50491, 755, 1, 1, -11015.97, -1704.195, -0.002523273, 3.344357, 7200, 0, 0), -- Mac Frog (Area: Oasis of the Fallen Prophet)
(@CGUID+127, 50496, 755, 1, 1, -11062.24, -1479.842, 9.096326, 6.128476, 7200, 0, 0), -- Oasis Moth (Area: Oasis of the Fallen Prophet)
(@CGUID+128, 45062, 755, 1, 1, -11087.6, -1493.48, 6.759734, 5.637414, 7200, 0, 0), -- Oathsworn Scorpid Keeper (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+129, 44981, 755, 1, 1, -11071.9, -1483.46, 6.759734, 5.742133, 7200, 0, 0), -- Oathsworn Skinner (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+130, 47720, 755, 1, 1, -11047.4, -1376.6, 10.89013, 3.193953, 7200, 0, 0), -- Camel (Area: The Trapper's Enclave)
(@CGUID+131, 45065, 755, 1, 1, -11034.4, -1371.74, 10.89013, 5.044002, 7200, 0, 0), -- Tol'vir Merchant (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+132, 49743, 755, 1, 1, -11031.25, -1381.927, 10.8854, 1.570796, 7200, 0, 0), -- Dung Beetle (Area: The Trapper's Enclave)
(@CGUID+133, 45065, 755, 1, 1, -11014.6, -1365.94, 10.89013, 5.044002, 7200, 0, 0), -- Tol'vir Merchant (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+134, 49732, 755, 1, 1, -11079.78, -1519.094, 6.800443, 1.914171, 7200, 0, 0), -- Horned Lizard (Area: The Trapper's Enclave)
(@CGUID+135, 44976, 755, 1, 1, -11077.84, -1400.152, 10.89456, 0.2233469, 7200, 0, 0), -- Neferset Plaguebringer (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+136, 44982, 755, 1, 1, -11070.32, -1394.033, 10.85526, 0.2755347, 7200, 0, 0), -- Neferset Darkcaster (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+137, 44922, 755, 1, 1, -11099.9, -1539.96, 6.759744, 3.769911, 7200, 0, 0), -- Oathsworn Axemaster (Area: The Trapper's Enclave)
(@CGUID+138, 50496, 755, 1, 1, -11100.64, -1504.163, 9.459798, 1.798593, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+139, 50496, 755, 1, 1, -11099.23, -1544.756, 9.832254, 5.440124, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+140, 50496, 755, 1, 1, -11109.83, -1533.434, 8.895953, 2.168112, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+141, 44976, 755, 1, 1, -11104.7, -1556.23, 6.759744, 2.792527, 7200, 0, 0), -- Neferset Plaguebringer (Area: The Trapper's Enclave)
(@CGUID+142, 44981, 755, 1, 1, -11109.1, -1541.29, 6.759744, 4.485496, 7200, 0, 0), -- Oathsworn Skinner (Area: The Trapper's Enclave)
(@CGUID+143, 44982, 755, 1, 1, -11099.3, -1547.89, 6.759744, 3.525565, 7200, 0, 0), -- Neferset Darkcaster (Area: The Trapper's Enclave)
(@CGUID+144, 50496, 755, 1, 1, -11110.73, -1541.659, 9.589666, 5.255738, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+145, 45065, 755, 1, 1, -11077.7, -1383.69, 10.89013, 5.044002, 7200, 0, 0), -- Tol'vir Merchant (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+146, 44980, 755, 1, 1, -11115.8, -1552.79, 6.759744, 0.8377581, 7200, 0, 0), -- Neferset Theurgist (Area: The Trapper's Enclave)
(@CGUID+147, 49743, 755, 1, 1, -11145.08, -1440.953, 10.8854, 3.967033, 7200, 0, 0), -- Dung Beetle (Area: The Trapper's Enclave)
(@CGUID+148, 49743, 755, 1, 1, -11096.58, -1392.912, 10.89567, 5.879227, 7200, 0, 0), -- Dung Beetle (Area: The Trapper's Enclave)
(@CGUID+149, 47720, 755, 1, 1, -11146.6, -1447.05, 10.89013, 4.764749, 7200, 0, 0), -- Camel (Area: The Trapper's Enclave)
(@CGUID+150, 44982, 755, 1, 1, -11112.1, -1398.39, 10.89123, 2.617994, 7200, 0, 0), -- Neferset Darkcaster (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+151, 44981, 755, 1, 1, -11124.2, -1404.55, 10.89013, 1.466077, 7200, 0, 0), -- Oathsworn Skinner (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+152, 44980, 755, 1, 1, -11131, -1406.69, 10.89013, 1.239184, 7200, 0, 0), -- Neferset Theurgist (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+153, 44976, 755, 1, 1, -11118.3, -1402.22, 10.89013, 1.884956, 7200, 0, 0), -- Neferset Plaguebringer (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+154, 44977, 755, 1, 1, -11100.1, -1360.74, 10.89013, 0.6457718, 7200, 0, 0), -- Neferset Torturer (Area: The Trapper's Enclave)
(@CGUID+155, 44976, 755, 1, 1, -11096.9, -1370.5, 10.89013, 6.038839, 7200, 0, 0), -- Neferset Plaguebringer (Area: The Trapper's Enclave)
(@CGUID+156, 44982, 755, 1, 1, -11096.5, -1379.91, 10.89013, 0.6981317, 7200, 0, 0), -- Neferset Darkcaster (Area: The Trapper's Enclave)
(@CGUID+157, 49835, 755, 1, 1, -11138.71, -1361.543, 10.92205, 2.897374, 7200, 0, 0), -- Desert Spider (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+158, 37231, 755, 1, 1, -11095.3, -1357.23, 11.57513, 0, 7200, 0, 0), -- Rope Beam Stalker (Area: The Trapper's Enclave)
(@CGUID+159, 37231, 755, 1, 1, -11093.6, -1356.25, 17.29753, 0, 7200, 0, 0), -- Rope Beam Stalker (Area: The Trapper's Enclave)
(@CGUID+160, 50496, 755, 1, 1, -11126.31, -1384.29, 19.47555, 2.568381, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+161, 37231, 755, 1, 1, -11087.8, -1379.9, 11.40353, 0, 7200, 0, 0), -- Rope Beam Stalker (Area: The Trapper's Enclave)
(@CGUID+162, 37231, 755, 1, 1, -11086.9, -1378.05, 17.26353, 0, 7200, 0, 0), -- Rope Beam Stalker (Area: The Trapper's Enclave)
(@CGUID+163, 37231, 755, 1, 1, -11090.6, -1369.01, 17.27573, 0, 7200, 0, 0), -- Rope Beam Stalker (Area: The Trapper's Enclave)
(@CGUID+164, 37231, 755, 1, 1, -11092.2, -1367.9, 11.12613, 0, 7200, 0, 0), -- Rope Beam Stalker (Area: The Trapper's Enclave)
(@CGUID+165, 50496, 755, 1, 1, -11120.06, -1382.238, 20.50793, 1.095119, 7200, 0, 0), -- Oasis Moth (Area: The Trapper's Enclave)
(@CGUID+166, 45007, 755, 1, 1, -11090.2, -1374.35, 13.74533, 3.543018, 7200, 0, 0), -- Enslaved Bandit (Area: The Trapper's Enclave)
(@CGUID+167, 44976, 755, 1, 1, -11158.2, -1378.69, 10.89013, 2.617994, 7200, 0, 0), -- Neferset Plaguebringer (Area: The Trapper's Enclave)
(@CGUID+168, 45065, 755, 1, 1, -11164.77, -1380.648, 10.89009, 0.3665192, 7200, 0, 0), -- Tol'vir Merchant (Area: The Trapper's Enclave)
(@CGUID+169, 45065, 755, 1, 1, -11159.8, -1392.86, 10.89013, 0.418879, 7200, 0, 0), -- Tol'vir Merchant (Area: The Trapper's Enclave)
(@CGUID+170, 44982, 755, 1, 1, -11152, -1393.03, 10.89013, 2.984513, 7200, 0, 0), -- Neferset Darkcaster (Area: The Trapper's Enclave)
(@CGUID+171, 44980, 755, 1, 1, -11156, -1385.36, 10.89013, 3.961897, 7200, 0, 0), -- Neferset Theurgist (Area: The Trapper's Enclave)
(@CGUID+172, 45065, 755, 1, 1, -11056.9, -1377.2, 10.90073, 5.044002, 7200, 0, 0), -- Tol'vir Merchant (Area: The Trapper's Enclave) (possible waypoints or random movement)
(@CGUID+173, 44922, 755, 1, 1, -11103.1, -1351.72, 10.89013, 5.88176, 7200, 0, 0), -- Oathsworn Axemaster (Area: Terrace of the Augurs)
(@CGUID+174, 37231, 755, 1, 1, -11097.3, -1347.2, 17.15963, 3.176499, 7200, 0, 0), -- Rope Beam Stalker (Area: Terrace of the Augurs)
(@CGUID+175, 37231, 755, 1, 1, -11099, -1347.01, 11.41073, 0, 7200, 0, 0), -- Rope Beam Stalker (Area: Terrace of the Augurs)
(@CGUID+176, 45065, 755, 1, 1, -11094.4, -1336.96, 10.89013, 1.937315, 7200, 0, 0), -- Tol'vir Merchant (Area: Terrace of the Augurs)
(@CGUID+177, 45007, 755, 1, 1, -11096.8, -1352.65, 13.28943, 3.595378, 7200, 0, 0), -- Enslaved Bandit (Area: Terrace of the Augurs)
(@CGUID+178, 47720, 755, 1, 1, -11046.7, -1371.46, 10.89013, 6.073746, 7200, 0, 0), -- Camel (Area: Terrace of the Augurs)
(@CGUID+179, 49732, 755, 1, 1, -11121.68, -1329.764, 10.87805, 4.396595, 7200, 0, 0), -- Horned Lizard (Area: Terrace of the Augurs)
(@CGUID+180, 49732, 755, 1, 1, -11096.25, -1321.88, 10.88428, 3.93872, 7200, 0, 0), -- Horned Lizard (Area: Terrace of the Augurs)
(@CGUID+181, 47720, 755, 1, 1, -11080.7, -1316.41, 10.89013, 1.413717, 7200, 0, 0), -- Camel (Area: Terrace of the Augurs)
(@CGUID+182, 47720, 755, 1, 1, -11085.7, -1313.39, 10.89013, 0.4537856, 7200, 0, 0), -- Camel (Area: Terrace of the Augurs)
(@CGUID+183, 45065, 755, 1, 1, -11068.1, -1329.47, 10.89013, 2.007129, 7200, 0, 0), -- Tol'vir Merchant (Area: Terrace of the Augurs)
(@CGUID+184, 45065, 755, 1, 1, -11046.1, -1322.27, 10.89013, 1.937315, 7200, 0, 0), -- Tol'vir Merchant (Area: Terrace of the Augurs)
(@CGUID+185, 44977, 755, 1, 1, -11061.41, -1318.644, 10.81301, 3.49863, 7200, 0, 0), -- Neferset Torturer (Area: Terrace of the Augurs) (possible waypoints or random movement)
(@CGUID+186, 44980, 755, 1, 1, -11070.83, -1317.864, 10.88428, 3.486137, 7200, 0, 0), -- Neferset Theurgist (Area: Terrace of the Augurs) (possible waypoints or random movement)
(@CGUID+187, 45065, 755, 1, 1, -11022.9, -1317.45, 10.89013, 1.780236, 7200, 0, 0), -- Tol'vir Merchant (Area: Terrace of the Augurs) (possible waypoints or random movement)
(@CGUID+188, 48092, 755, 1, 1, -10891.5, -1379.72, 15.43603, 5.340707, 7200, 0, 0), -- Wind Tunnel (Area: Terrace of the Augurs)
(@CGUID+189, 48097, 755, 1, 1, -10955.2, -1437.38, -148.974, 1.32645, 7200, 0, 0), -- Wind Tunnel Landing Zone (Area: Terrace of the Augurs)
(@CGUID+190, 48097, 755, 1, 1, -10911.04, -1386.198, -149.2622, 3.385939, 7200, 0, 0), -- Wind Tunnel Landing Zone (Area: Terrace of the Augurs)
(@CGUID+191, 48092, 755, 1, 1, -10964.9, -1481.17, 6.759734, 5.340707, 7200, 0, 0), -- Wind Tunnel (Area: Terrace of the Augurs)
(@CGUID+192, 48092, 755, 1, 1, -10930.58, -1302.745, 2.202041, 5.358161, 7200, 0, 0), -- Wind Tunnel (Area: Terrace of the Augurs)
(@CGUID+193, 48097, 755, 1, 1, -10910.61, -1432.009, 35.44183, 2.076942, 7200, 0, 0), -- Wind Tunnel Landing Zone (Area: Terrace of the Augurs)
(@CGUID+194, 48092, 755, 1, 1, -10998.4, -1356.15, 10.88983, 5.340707, 7200, 0, 0), -- Wind Tunnel (Area: Terrace of the Augurs)
(@CGUID+195, 48097, 755, 1, 1, -10940.86, -1350.918, 35.64969, 5.410521, 7200, 0, 0), -- Wind Tunnel Landing Zone (Area: Terrace of the Augurs)
(@CGUID+196, 48097, 755, 1, 1, -10994.91, -1417.094, -149.2738, 0.3141593, 7200, 0, 0), -- Wind Tunnel Landing Zone (Area: Terrace of the Augurs)
(@CGUID+197, 48092, 755, 1, 1, -11027.7, -1427.97, 5.693843, 5.340707, 7200, 0, 0), -- Wind Tunnel (Area: Terrace of the Augurs)
(@CGUID+198, 48097, 755, 1, 1, -10979, -1374.833, -149.0995, 5.445427, 7200, 0, 0), -- Wind Tunnel Landing Zone (Area: Terrace of the Augurs)
(@CGUID+199, 48092, 755, 1, 1, -10887.71, -1447.698, 2.248156, 4.747295, 7200, 0, 0); -- Wind Tunnel (Area: Terrace of the Augurs)


DELETE FROM `creature_equip_template` WHERE `entry` IN (50038, 50036, 50037, 44981, 44932, 44924, 44926, 44922, 45007, 44897, 44896, 44898, 45122, 44977, 44976, 43612, 45377, 45062, 44982, 44980);
INSERT INTO `creature_equip_template` (`entry`, `itemEntry1`, `itemEntry2`, `itemEntry3`) VALUES
(50038, 62798, 0, 0), -- Captain Hadan
(50036, 43967, 0, 0), -- Ramkahen Scout
(50037, 43967, 0, 0), -- Ramkahen Scout
(44981, 56231, 57021, 0), -- Oathsworn Skinner
(44932, 0, 0, 60790), -- Oathsworn Pathfinder
(44924, 57025, 56175, 0), -- Oathsworn Myrmidon
(44926, 0, 0, 60789), -- Oathsworn Wanderer
(44922, 57009, 0, 0), -- Oathsworn Axemaster
(45007, 2179, 2179, 0), -- Enslaved Bandit
(44897, 0, 0, 60764), -- Pygmy Scout
(44896, 60765, 0, 0), -- Pygmy Brute
(44898, 49423, 0, 0), -- Pygmy Firebreather
(45122, 57009, 0, 0), -- Oathsworn Captain
(44977, 57113, 57113, 0), -- Neferset Torturer
(44976, 58802, 0, 0), -- Neferset Plaguebringer
(43612, 58803, 0, 0), -- High Prophet Barim
(45377, 60957, 0, 0), -- Augh
(45062, 57008, 57037, 0), -- Oathsworn Scorpid Keeper
(44982, 58802, 0, 0), -- Neferset Darkcaster
(44980, 57036, 0, 0); -- Neferset Theurgist
