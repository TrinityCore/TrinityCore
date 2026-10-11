SET @CGUID := 10006075;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+50;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 222037, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2015.8819580078125, -2265.020751953125, 10.42981624603271484, 5.34156656265258789, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Opalshell Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+1, 222023, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1924.0260009765625, -2310.95654296875, -0.26113945245742797, 3.327887773513793945, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Coastal Water Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+2, 222023, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1977.8836669921875, -2280.09716796875, 0.595161616802215576, 1.463885188102722167, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Coastal Water Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+3, 222023, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1954.2552490234375, -2330.99658203125, 2.708271503448486328, 1.152749538421630859, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Coastal Water Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+4, 222023, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1879.1475830078125, -2278.661376953125, 3.486607074737548828, 5.500247001647949218, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Coastal Water Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+5, 222037, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1961.21875, -2314.3994140625, 0.724301099777221679, 2.609715938568115234, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Opalshell Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+6, 222057, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1945.279541015625, -2307.38720703125, 38.37174224853515625, 1.178097367286682128, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59207), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+7, 222037, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1902.7100830078125, -2295.1025390625, 0.28880852460861206, 5.558488845825195312, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Opalshell Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+8, 222020, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1963.3004150390625, -2283.939208984375, -2.0700531005859375, 5.159676074981689453, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Condensed Droplet (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+9, 222020, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1945.5069580078125, -2322.310791015625, 1.191968083381652832, 2.704055309295654296, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Condensed Droplet (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+10, 222020, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1877.4722900390625, -2264.11279296875, 1.364690423011779785, 0.647579848766326904, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Condensed Droplet (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+11, 222036, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1941.5, -2248.229248046875, -8.54939842224121093, 0, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Sea Slug (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+12, 222037, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2015.6285400390625, -2143.4775390625, 11.73628902435302734, 3.866451025009155273, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Opalshell Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+13, 222037, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2003.59375, -2189.421875, 1.331594347953796386, 0.001470412826165556, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Opalshell Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+14, 222023, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2006.55908203125, -2193.545166015625, 1.640867590904235839, 6.168225288391113281, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Coastal Water Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+15, 222020, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2004.9444580078125, -2141.661376953125, -2.84337234497070312, 2.151192188262939453, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Condensed Droplet (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+16, 222023, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2014.7569580078125, -2138.00341796875, 1.756831526756286621, 4.110478878021240234, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Coastal Water Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+17, 222156, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1906.2916259765625, -2192.4619140625, -7.41265010833740234, 4.968377590179443359, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Scavenging Sandsnapper (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+18, 222037, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2031.498291015625, -2163.663330078125, 1.077849984169006347, 2.580553054809570312, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Opalshell Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+19, 222036, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1949.96875, -2168.717041015625, -9.44145584106445312, 1.533325791358947753, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Sea Slug (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+20, 222057, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1958.404541015625, -2154.93408203125, 12.35186290740966796, 4.908735275268554687, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59207), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+21, 222156, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1960.439208984375, -2206.48095703125, -6.21706819534301757, 0.788177728652954101, 120, 8, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Scavenging Sandsnapper (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+22, 222037, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2014.90283203125, -2130.013916015625, 5.41991424560546875, 3.722617149353027343, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Opalshell Scuttler (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+23, 222057, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1945.279541015625, -2206.1650390625, 44.0362396240234375, 1.178097367286682128, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 59207), -- Isle Gull (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+24, 222036, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1887.1597900390625, -2155.71533203125, -11.2954282760620117, 3.196254730224609375, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59207), -- Sea Slug (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+25, 221978, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2092.255126953125, -2364.96875, 110.7621536254882812, 4.514562606811523437, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Living Earth Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+26, 221984, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2048.819580078125, -2405.880126953125, 95.39349365234375, 1.354327201843261718, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Restless Pebble (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+27, 221984, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2080.8681640625, -2330.661376953125, 113.4048843383789062, 5.379660606384277343, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Restless Pebble (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+28, 221984, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2005.9444580078125, -2438.560791015625, 81.9560394287109375, 6.238329410552978515, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Restless Pebble (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+29, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2024.9879150390625, -2439.654541015625, 85.94940185546875, 2.38911747932434082, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+30, 221984, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1963.642333984375, -2434.145751953125, 75.68251800537109375, 2.047662734985351562, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Restless Pebble (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+31, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1943.2708740234375, -2423.475830078125, 72.2848358154296875, 1.677861452102661132, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+32, 221978, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1947.25, -2418.522705078125, 69.82869720458984375, 2.836552858352661132, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Living Earth Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+33, 221984, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1947.2742919921875, -2496.935791015625, 97.35152435302734375, 4.956983089447021484, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Restless Pebble (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+34, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1892.296875, -2480.319580078125, 90.4478759765625, 0.499035269021987915, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+35, 221984, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1930.3785400390625, -2535.619873046875, 104.6844863891601562, 3.948966026306152343, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Restless Pebble (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+36, 221978, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1870.701416015625, -2496.583251953125, 89.33292388916015625, 0, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Living Earth Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+37, 221978, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1972.1129150390625, -2519.907958984375, 109.5740966796875, 5.420439720153808593, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Living Earth Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+38, 221984, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1806.1944580078125, -2451.732666015625, 90.98221588134765625, 3.78202986717224121, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Restless Pebble (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+39, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1764.954833984375, -2466.741455078125, 99.92917633056640625, 3.092667341232299804, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+40, 221984, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1804.2379150390625, -2503.8525390625, 95.83721923828125, 6.005807876586914062, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Restless Pebble (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+41, 221984, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1853.1129150390625, -2416.864501953125, 78.17681884765625, 5.640282154083251953, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Restless Pebble (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+42, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1834.1788330078125, -2419.388916015625, 85.0765228271484375, 5.788821697235107421, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+43, 221984, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1839.951416015625, -2468.60595703125, 89.589599609375, 2.87254953384399414, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Restless Pebble (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+44, 221984, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1774.8646240234375, -2477.501708984375, 95.73386383056640625, 3.229705810546875, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Restless Pebble (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+45, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 1811.6319580078125, -2381.335205078125, 82.17779541015625, 4.939843654632568359, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+46, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2105.97216796875, -2421.189208984375, 140.29345703125, 4.11810922622680664, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+47, 221978, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2125.734375, -2454.3994140625, 161.6712799072265625, 2.351592540740966796, 120, 6, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Living Earth Elemental (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+48, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2096.548583984375, -2474.0087890625, 149.141876220703125, 2.409595966339111328, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+49, 221984, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2086.59033203125, -2450.08154296875, 141.8535003662109375, 5.27541208267211914, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302), -- Restless Pebble (Area: Isle of Dorn - Difficulty: 0) CreateObject2
(@CGUID+50, 221524, 2552, 14717, 14717, '0', 0, 0, 0, 0, 2134.072998046875, -2423.3125, 161.047821044921875, 5.517031669616699218, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 59302); -- Gemwing (Area: Isle of Dorn - Difficulty: 0) CreateObject2

-- Template
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=221978; -- Living Earth Elemental
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=222023; -- Coastal Water Elemental
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=222037; -- Opalshell Scuttler
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=222020; -- Condensed Droplet
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=0x800 WHERE `entry`=221984; -- Restless Pebble

-- Difficulty
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=59207 WHERE (`Entry`=221978 AND `DifficultyID`=0); -- 221978 (Living Earth Elemental) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=59207 WHERE (`Entry`=222023 AND `DifficultyID`=0); -- 222023 (Coastal Water Elemental) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=59207 WHERE (`Entry`=222037 AND `DifficultyID`=0); -- 222037 (Opalshell Scuttler) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=81, `StaticFlags1`=0x10000000, `VerifiedBuild`=59207 WHERE (`Entry`=222020 AND `DifficultyID`=0); -- 222020 (Condensed Droplet) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=59302 WHERE (`Entry`=221984 AND `DifficultyID`=0); -- 221984 (Restless Pebble) - CanSwim

-- Path for Isle Gull
SET @MOVERGUID := @CGUID+6;
SET @ENTRY := 222057;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Isle Gull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1949.673, -2296.7805, 38.371742, NULL, 0),
(@PATH, 1, 1960.2795, -2292.3872, 38.371742, NULL, 0),
(@PATH, 2, 1970.8861, -2296.7805, 38.371742, NULL, 0),
(@PATH, 3, 1975.2795, -2307.3872, 38.371742, NULL, 0),
(@PATH, 4, 1970.8861, -2317.994, 38.371742, NULL, 0),
(@PATH, 5, 1960.2795, -2322.3872, 38.371742, NULL, 0),
(@PATH, 6, 1949.673, -2317.994, 38.371742, NULL, 0),
(@PATH, 7, 1945.2795, -2307.3872, 38.371742, NULL, 0),
(@PATH, 8, 1949.673, -2296.7805, 38.371742, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Isle Gull
SET @MOVERGUID := @CGUID+20;
SET @ENTRY := 222057;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.6714, 'Isle Gull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1960.6881, -2166.4146, 12.351863, NULL, 0),
(@PATH, 1, 1967.1913, -2176.1472, 12.351863, NULL, 0),
(@PATH, 2, 1976.9241, -2182.6504, 12.351863, NULL, 0),
(@PATH, 3, 1988.4045, -2184.934, 12.351863, NULL, 0),
(@PATH, 4, 1999.885, -2182.6504, 12.351863, NULL, 0),
(@PATH, 5, 2009.6178, -2176.1472, 12.351863, NULL, 0),
(@PATH, 6, 2016.121, -2166.4146, 12.351863, NULL, 0),
(@PATH, 7, 2018.4045, -2154.934, 12.351863, NULL, 0),
(@PATH, 8, 2016.121, -2143.4536, 12.351863, NULL, 0),
(@PATH, 9, 2009.6177, -2133.721, 12.351863, NULL, 0),
(@PATH, 10, 1999.885, -2127.2178, 12.351863, NULL, 0),
(@PATH, 11, 1988.4045, -2124.934, 12.351863, NULL, 0),
(@PATH, 12, 1976.9241, -2127.2178, 12.351863, NULL, 0),
(@PATH, 13, 1967.1913, -2133.721, 12.351863, NULL, 0),
(@PATH, 14, 1960.6881, -2143.4536, 12.351863, NULL, 0),
(@PATH, 15, 1958.4045, -2154.934, 12.351863, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Isle Gull
SET @MOVERGUID := @CGUID+23;
SET @ENTRY := 222057;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 2.8683, 'Isle Gull - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1949.673, -2195.5583, 44.03624, NULL, 0),
(@PATH, 1, 1960.2795, -2191.165, 44.03624, NULL, 0),
(@PATH, 2, 1970.8861, -2195.5583, 44.03624, NULL, 0),
(@PATH, 3, 1975.2795, -2206.165, 44.03624, NULL, 0),
(@PATH, 4, 1970.8861, -2216.7717, 44.03624, NULL, 0),
(@PATH, 5, 1960.2795, -2221.165, 44.03624, NULL, 0),
(@PATH, 6, 1949.673, -2216.7717, 44.03624, NULL, 0),
(@PATH, 7, 1945.2795, -2206.165, 44.03624, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
