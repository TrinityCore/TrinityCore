SET @CGUID := 396355;
SET @OGUID := 245674;

-- Creature templates
UPDATE `creature_template` SET `gossip_menu_id`=10518, `unit_flags`=768 WHERE `entry`=34480; -- Cheerful Tauren Spirit
UPDATE `creature_template` SET `gossip_menu_id`=10518, `minlevel`=60, `maxlevel`=60, `unit_flags`=768 WHERE `entry`=35252; -- Ghostly Tauren Celebrant

UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=10, `auras`='4986 33900' WHERE `entry`=35252; -- 35252 (Ghostly Tauren Celebrant) - Unseen, Shroud of Death
UPDATE `creature_template_addon` SET `bytes1`=0, `emote`=0, `auras`='4986 33900' WHERE `entry`=34480; -- 34480 (Cheerful Tauren Spirit) - Unseen, Shroud of Death

-- Scaling
DELETE FROM `creature_template_scaling` WHERE (`DifficultyID`=0 AND `Entry` IN (35252,34480));
INSERT INTO `creature_template_scaling` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `VerifiedBuild`) VALUES
(35252, 0, 0, 0, 414, 46366),
(34480, 0, 0, 0, 414, 46366);

UPDATE `creature_template_scaling` SET `VerifiedBuild`=46366 WHERE (`DifficultyID`=0 AND `Entry` IN (133271,133218,118512,96470,89713,61141,52658,52657,52655,52651,51503,51372,50483,49750,47589,36648,19176,15164,14442,14441,14440,11084,11071,11051,11047,10881,10278,10054,8722,8674,8398,8364,8363,8362,8361,8360,8359,8358,8357,8356,7089,6746,6410,5189,5054,4721,3978,3566,3095,3093,3092,3084,3083,3050,3029,3028,3027,3026,3025,3024,3023,3022,3021,3020,3019,3018,3017,3016,3015,3014,3013,3012,3011,3010,3009,3008,3007,3005,3004,3003,3002,3001,2999,2998,2997,2996,2995,2971,2960,2620));

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=46366 WHERE (`Idx`=0 AND `CreatureID` IN (2998,19176,3027,11084,3008,3020,3050,3007,11071,52657,8364,3018,3003,3022,3011,96470,8362,3019,8360,3092,3015,3017,36648,35252,5054,8358,50483,11047,2971,3566,3002,10278,49750,8359,2995,3009,2960,51503,8722,10881,3023,133271,7089,41031,8363,8674,14440,89713,8398,8356,3014,52651,6746,133218,118512,47589,3010,3016,2999,15164,3028,3093,2620,3978,8357,3029,3004,61141,51372,52658,3001,2997,3005,356,10054,3021,3024,3025,3012,3084,18379,52655,6410,2996,3083,3013,14442,34480,4721,11051,5189,8361,3026,3095,14441)) OR (`Idx`=1 AND `CreatureID` IN (19176,35252,133271,133218,51372,3084)) OR (`Idx`=3 AND `CreatureID` IN (133271,133218,51372,3084)) OR (`Idx`=2 AND `CreatureID` IN (133271,133218,51372,3084));

UPDATE `creature_model_info` SET `VerifiedBuild`=46366 WHERE `DisplayID` IN (82820, 83227, 82748, 74863, 64916, 61763, 38011, 38010, 38009, 38006, 37400, 37343, 37342, 37344, 37345, 37022, 36615, 35712, 30272, 29232, 14496, 14495, 14494, 10617, 10614, 10586, 10577, 10188, 9742, 9272, 7998, 7999, 10689, 7627, 7628, 7626, 7625, 7624, 7623, 7622, 7620, 7621, 5847, 5487, 5372, 3129, 3002, 2738, 4518, 1056, 2132, 2129, 2133, 9392, 8572, 9391, 2141, 2140, 4517, 2120, 2088, 2095, 2107, 2111, 2097, 2125, 2124, 2089, 2085, 2084, 2086, 2117, 2099, 2114, 2119, 2091, 2118, 2101, 2116, 2108, 2094, 2127, 2093, 2126, 2109, 2092, 2083, 2100, 2090, 2110, 2104, 2098, 10824, 161, 1072);
UPDATE `creature_model_info` SET `DisplayID_Other_Gender`=0, `VerifiedBuild`=46366 WHERE `DisplayID` IN (29713, 29714);

-- Quests
UPDATE `quest_details` SET `Emote1`=3, `VerifiedBuild`=46366 WHERE `ID`=14176; -- The Grateful Dead

UPDATE `quest_request_items` SET `EmoteOnComplete`=0, `EmoteOnIncomplete`=0, `VerifiedBuild`=46366 WHERE `ID`=14176; -- The Grateful Dead

UPDATE `quest_offer_reward` SET `Emote1`=4, `VerifiedBuild`=46366 WHERE `ID`=14176; -- The Grateful Dead

DELETE FROM `creature_queststarter` WHERE `id`=34480;
INSERT INTO `creature_queststarter` (`id`, `quest`, `VerifiedBuild`) VALUES
(34480, 14176, 46366);

DELETE FROM `game_event_creature_quest` WHERE `id`=34480;

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN 145013 AND 145022;
DELETE FROM `creature` WHERE `guid` IN (145040, 145041);
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 145013 AND 145022;
DELETE FROM `game_event_creature` WHERE `guid` IN (145040, 145041);

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 34382, 1, 1638, 5345, '0', 0, 0, 0, 1, -978.0225830078125, -72.6458358764648437, 19.29324531555175781, 0.401425719261169433, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Chapman (Area: Thunder Bluff - Difficulty: 0)
(@CGUID+1, 34383, 1, 1638, 5345, '0', 0, 0, 0, 1, -977.62677001953125, -74.53125, 19.17006301879882812, 0.244346097111701965, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Catrina (Area: Thunder Bluff - Difficulty: 0)
(@CGUID+2, 34480, 1, 1638, 5345, '0', 0, 0, 0, 0, -971.01739501953125, -79.1805572509765625, 18.88194465637207031, 1.064650893211364746, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Cheerful Tauren Spirit (Area: Thunder Bluff - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+3, 35252, 1, 1638, 5345, '0', 0, 0, 0, 0, -979.91143798828125, -67.2083358764648437, 20.61611747741699218, 3.996803998947143554, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Tauren Celebrant (Area: Thunder Bluff - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+4, 35252, 1, 1638, 5345, '0', 0, 0, 0, 0, -988.50177001953125, -70.1875, 22.69485855102539062, 6.17846536636352539, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Tauren Celebrant (Area: Thunder Bluff - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+5, 35252, 1, 1638, 5345, '0', 0, 0, 0, 0, -983.61798095703125, -74.5417022705078125, 20.65583419799804687, 0.366519153118133544, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Tauren Celebrant (Area: Thunder Bluff - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+6, 35252, 1, 1638, 5345, '0', 0, 0, 0, 0, -988.1961669921875, -76.1545181274414062, 22.06944465637207031, 1.832595705986022949, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Tauren Celebrant (Area: Thunder Bluff - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+7, 35252, 1, 1638, 5345, '0', 0, 0, 0, 0, -982.00347900390625, -65.5833358764648437, 21.9618072509765625, 0.453785598278045654, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Tauren Celebrant (Area: Thunder Bluff - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+8, 35252, 1, 1638, 5345, '0', 0, 0, 0, 0, -974.63897705078125, -84.0589981079101562, 20.59403419494628906, 1.274090290069580078, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Tauren Celebrant (Area: Thunder Bluff - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+9, 35252, 1, 1638, 5345, '0', 0, 0, 0, 0, -981.7080078125, -76.1371994018554687, 20.18573379516601562, 4.066617012023925781, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Tauren Celebrant (Area: Thunder Bluff - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+10, 35252, 1, 1638, 5345, '0', 0, 0, 0, 0, -986.093994140625, -79.2985992431640625, 21.44523429870605468, 1.134464025497436523, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366), -- Ghostly Tauren Celebrant (Area: Thunder Bluff - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)
(@CGUID+11, 35252, 1, 1638, 5345, '0', 0, 0, 0, 0, -984.48785400390625, -82.5694427490234375, 21.32398033142089843, 1.29154360294342041, 120, 0, 0, 18771, 0, 0, 0, 0, 0, 46366); -- Ghostly Tauren Celebrant (Area: Thunder Bluff - Difficulty: 0) (Auras: 4986 - Unseen, 33900 - Shroud of Death)

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78416 AND 78418;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78459 AND 78477;
DELETE FROM `gameobject` WHERE `guid` BETWEEN 78538 AND 78557;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78416 AND 78418;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78459 AND 78477;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 78538 AND 78557;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+42;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180338, 1, 1638, 5345, '0', 0, 0, -982.482666015625, -69.9600677490234375, 20.57870674133300781, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+1, 180338, 1, 1638, 5345, '0', 0, 0, -979.7569580078125, -79.6302108764648437, 19.90927696228027343, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+2, 180338, 1, 1638, 5345, '0', 0, 0, -981.94097900390625, -69.09375, 20.54777908325195312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+3, 180338, 1, 1638, 5345, '0', 0, 0, -983.39581298828125, -69.5920181274414062, 23.80661201477050781, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+4, 180338, 1, 1638, 5345, '0', 0, 0, -980.51043701171875, -79.8402786254882812, 20.08268547058105468, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+5, 180338, 1, 1638, 5345, '0', 0, 0, -985.27777099609375, -76.1753463745117187, 24.29875946044921875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+6, 180338, 1, 1638, 5345, '0', 0, 0, -980.63018798828125, -80.09375, 22.98438644409179687, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+7, 180338, 1, 1638, 5345, '0', 0, 0, -984.9375, -72.0868072509765625, 23.89490699768066406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+8, 180338, 1, 1638, 5345, '0', 0, 0, -984.91839599609375, -73.0590286254882812, 23.87839698791503906, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+9, 180338, 1, 1638, 5345, '0', 0, 0, -979.64410400390625, -81.0277786254882812, 22.96629905700683593, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+10, 180338, 1, 1638, 5345, '0', 0, 0, -983.6180419921875, -70.3506927490234375, 20.84995269775390625, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+11, 180338, 1, 1638, 5345, '0', 0, 0, -984.85418701171875, -76.173614501953125, 20.92022895812988281, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+12, 180338, 1, 1638, 5345, '0', 0, 0, -982.86456298828125, -68.861114501953125, 23.79463577270507812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+13, 180338, 1, 1638, 5345, '0', 0, 0, -985.47393798828125, -75.0295181274414062, 21.10662269592285156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+14, 180338, 1, 1638, 5345, '0', 0, 0, -984.98614501953125, -77.3263931274414062, 24.26637649536132812, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 01 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+15, 180339, 1, 1638, 5345, '0', 0, 0, -982.23089599609375, -68.626739501953125, 20.82021522521972656, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Candle 02 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+16, 180340, 1, 1638, 5345, '0', 0, 0, -984.31768798828125, -73.4565963745117187, 20.8533172607421875, 0.855210542678833007, 0, 0, 0.414692878723144531, 0.909961462020874023, 120, 255, 1, 46366), -- Candle 03 (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+17, 180761, 1, 1638, 5345, '0', 0, 0, -981.08697509765625, -79.5799026489257812, 21.18680000305175781, 0.942476630210876464, 0, 0, 0.453989982604980468, 0.891006767749786376, 120, 255, 1, 46366), -- Tauren Hero Portrait (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+18, 180885, 1, 1638, 5345, '0', 0, 0, -980.32989501953125, -71.845489501953125, 19.58780288696289062, 0.750490784645080566, 0, 0, 0.3665008544921875, 0.93041771650314331, 120, 255, 1, 46366), -- InnTableTiny (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+19, 182807, 1, 1638, 5345, '0', 0, 0, -980.77081298828125, -79.8229141235351562, 20.13351821899414062, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+20, 182807, 1, 1638, 5345, '0', 0, 0, -984.73785400390625, -73.1875, 20.99459648132324218, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bottle (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+21, 195063, 1, 1638, 5345, '0', 0, 0, -983.4930419921875, -72.6302108764648437, 20.66981315612792968, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+22, 195063, 1, 1638, 5345, '0', 0, 0, -984.1492919921875, -77.3333358764648437, 20.75267982482910156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+23, 195063, 1, 1638, 5345, '0', 0, 0, -982.13018798828125, -68.0763931274414062, 20.8835906982421875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+24, 195063, 1, 1638, 5345, '0', 0, 0, -980.40972900390625, -71.34375, 20.71851539611816406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+25, 195063, 1, 1638, 5345, '0', 0, 0, -980.2117919921875, -80.2552108764648437, 20.06755256652832031, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Orange Marigolds (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+26, 195066, 1, 1638, 5345, '0', 0, 0, -983.00177001953125, -70.0833358764648437, 20.78368377685546875, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+27, 195066, 1, 1638, 5345, '0', 0, 0, -984.30902099609375, -72.329864501953125, 20.99181556701660156, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+28, 195066, 1, 1638, 5345, '0', 0, 0, -984.6319580078125, -76.1215286254882812, 20.85416603088378906, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+29, 195066, 1, 1638, 5345, '0', 0, 0, -984.9132080078125, -75.1597213745117187, 20.9375, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Bread of the Dead (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+30, 195067, 1, 1638, 5345, '0', 0, 0, -983.56597900390625, -73.3246536254882812, 20.64240455627441406, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+31, 195067, 1, 1638, 5345, '0', 0, 0, -980.89202880859375, -79.2656021118164062, 20.10219955444335937, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Mixed Fruit Bowl (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+32, 195068, 1, 1638, 5345, '0', 0, 0, -983.0086669921875, -70.095489501953125, 20.78351402282714843, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+33, 195068, 1, 1638, 5345, '0', 0, 0, -984.920166015625, -75.171875, 20.93883132934570312, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+34, 195068, 1, 1638, 5345, '0', 0, 0, -984.638916015625, -76.1319427490234375, 20.85489082336425781, 0, 0, 0, 0, 1, 120, 255, 1, 46366), -- Offering Bowl (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+35, 195069, 1, 1638, 5345, '0', 0, 0, -980.36456298828125, -72.3871536254882812, 20.70847511291503906, 5.393068790435791015, 0, 0, -0.43051052093505859, 0.902585566043853759, 120, 255, 1, 46366), -- Candy Skulls (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+36, 195069, 1, 1638, 5345, '0', 0, 0, -979.8663330078125, -71.9184036254882812, 20.70171165466308593, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- Candy Skulls (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+37, 195069, 1, 1638, 5345, '0', 0, 0, -980.89410400390625, -71.7934036254882812, 20.70992469787597656, 6.12610626220703125, 0, 0, -0.07845878601074218, 0.996917366981506347, 120, 255, 1, 46366), -- Candy Skulls (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+38, 195087, 1, 1638, 5345, '0', 0, 0, -979.109375, -77.9027786254882812, 19.64342498779296875, 2.548179388046264648, 0, 0, 0.956304550170898437, 0.292372345924377441, 120, 255, 1, 46366), -- Ghostly Cooking Fire (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+39, 195090, 1, 1638, 5345, '0', 0, 0, -981.625, -66.9791641235351562, 20.97347450256347656, 3.804818391799926757, 0, 0, -0.94551849365234375, 0.325568377971649169, 120, 255, 1, 46366), -- Spirit Candle (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+40, 195090, 1, 1638, 5345, '0', 0, 0, -985.32098388671875, -76.3575973510742187, 21.06189918518066406, 3.263772249221801757, 0, 0, -0.99813461303710937, 0.061051756143569946, 120, 255, 1, 46366), -- Spirit Candle (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+41, 195307, 1, 1638, 5345, '0', 0, 0, -979.9774169921875, -71.3420181274414062, 20.71724510192871093, 3.9793548583984375, 0, 0, -0.9135446548461914, 0.406738430261611938, 120, 255, 1, 46366), -- Orange Marigolds (Area: Thunder Bluff - Difficulty: 0)
(@OGUID+42, 195307, 1, 1638, 5345, '0', 0, 0, -984.53472900390625, -75.828125, 20.86415672302246093, 3.001946926116943359, 0, 0, 0.997563362121582031, 0.069766148924827575, 120, 255, 1, 46366); -- Orange Marigolds (Area: Thunder Bluff - Difficulty: 0)

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=51 AND `guid` BETWEEN @CGUID+0 AND @CGUID+11;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(51, @CGUID+0), 
(51, @CGUID+1), 
(51, @CGUID+2), 
(51, @CGUID+3), 
(51, @CGUID+4), 
(51, @CGUID+5), 
(51, @CGUID+6), 
(51, @CGUID+7), 
(51, @CGUID+8), 
(51, @CGUID+9), 
(51, @CGUID+10),
(51, @CGUID+11);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=51 AND `guid` BETWEEN @OGUID+0 AND @OGUID+42;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(51, @OGUID+0),
(51, @OGUID+1),
(51, @OGUID+2),
(51, @OGUID+3),
(51, @OGUID+4),
(51, @OGUID+5),
(51, @OGUID+6),
(51, @OGUID+7),
(51, @OGUID+8),
(51, @OGUID+9),
(51, @OGUID+10),
(51, @OGUID+11),
(51, @OGUID+12),
(51, @OGUID+13),
(51, @OGUID+14),
(51, @OGUID+15),
(51, @OGUID+16),
(51, @OGUID+17),
(51, @OGUID+18),
(51, @OGUID+19),
(51, @OGUID+20),
(51, @OGUID+21),
(51, @OGUID+22),
(51, @OGUID+23),
(51, @OGUID+24),
(51, @OGUID+25),
(51, @OGUID+26),
(51, @OGUID+27),
(51, @OGUID+28),
(51, @OGUID+29),
(51, @OGUID+30),
(51, @OGUID+31),
(51, @OGUID+32),
(51, @OGUID+33),
(51, @OGUID+34),
(51, @OGUID+35),
(51, @OGUID+36),
(51, @OGUID+37),
(51, @OGUID+38),
(51, @OGUID+39),
(51, @OGUID+40),
(51, @OGUID+41),
(51, @OGUID+42);
