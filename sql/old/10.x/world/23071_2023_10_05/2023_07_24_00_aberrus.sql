SET @CGUID := 9003944;
SET @OGUID := 9000373;
SET @ATID := 25;
SET @ATSPAWNID := 26;
SET @WSLID := 100040;

SET @PATH_SIEGEMASTER := (198874 * 10) << 3;
SET @PATH_SARKARETH := (202416 * 10) << 3;;
SET @PATH_WINGLORD_DEZRAN := (202610 * 10) << 3;;
SET @PATH_ZSKARN := (202637 * 10) << 3;;

-- Instance Data
DELETE FROM `access_requirement` WHERE `mapId`=2569;
INSERT INTO `access_requirement` (`mapId`, `difficulty`, `level_min`, `level_max`, `item`, `item2`, `quest_done_A`, `quest_done_H`, `completed_achievement`, `quest_failed_text`, `comment`) VALUES 
(2569, 17, 70, 0, 0, 0, 0, 0, 0, NULL, 'Aberrus the Shadowed Crucible - Looking for Raid Mode'),
(2569, 14, 70, 0, 0, 0, 0, 0, 0, NULL, 'Aberrus the Shadowed Crucible - Normal Mode'),
(2569, 15, 70, 0, 0, 0, 0, 0, 0, NULL, 'Aberrus the Shadowed Crucible - Heroic Mode'),
(2569, 16, 70, 0, 0, 0, 0, 0, 0, NULL, 'Aberrus the Shadowed Crucible - Mythic Mode');

DELETE FROM `instance_template` WHERE `map`=2569;
INSERT INTO `instance_template` (`map`, `parent`, `script`) VALUES
(2569, 0, 'instance_aberrus_the_shadowed_crucible');

DELETE FROM `world_safe_locs` WHERE `ID` BETWEEN @WSLID+0 AND @WSLID+1;
INSERT INTO `world_safe_locs` (`ID`, `MapID`, `LocX`, `LocY`, `LocZ`, `Facing`, `Comment`) VALUES
(@WSLID+0, 2569, 2212.78, 2481.39, 711.777, 0.019635128, '10.x Raid - Aberrus the Shadowed Crucible - Entrance'),
(@WSLID+1, 2454, 1817.62, 2549.31, -78.994, 3.1581035, '10.x Raid - Aberrus the Shadowed Crucible - Exit');

DELETE FROM `areatrigger` WHERE `IsServerSide`=1 AND `SpawnId` BETWEEN @ATSPAWNID+0 AND @ATSPAWNID+3;
INSERT INTO `areatrigger` (`SpawnId`, `AreaTriggerId`, `IsServerSide`, `MapId`, `PosX`, `PosY`, `PosZ`, `Orientation`, `PhaseUseFlags`, `PhaseId`, `PhaseGroup`, `Shape`, `ShapeData0`, `ShapeData1`, `ShapeData2`, `ShapeData3`, `ShapeData4`, `ShapeData5`, `ShapeData6`, `ShapeData7`, `ScriptName`, `Comment`) VALUES
(@ATSPAWNID+0, @ATID+0, 1, 2454, 1847.1129150390625, 2549.317626953125, -79.5390777587890625, 0, 1, 0, 0, 1, 1, 25, 80, 1, 25, 80, 0, 0, '', '10.1 Raid - Aberrus the Shadowed Crucible - Entrance'),
(@ATSPAWNID+1, @ATID+1, 1, 2569, 2185.072998046875, 2482.572998046875, 718.5048828125, 0, 1, 0, 0, 1, 1, 20, 30, 1, 20, 30, 0, 0, '', '10.1 Raid - Aberrus the Shadowed Crucible - Exit'),
(@ATSPAWNID+2, @ATID+2, 1, 2569, 2236.875488, 2481.375244, 711.785767, 6.278931, 1, 0, 0, 1, 20, 50, 5, 20, 50, 5, 0, 0, 'at_aberrus_sabellian_conversation_intro', 'Aberrus - Trigger Sabellian and Wrathion Conversation'),
(@ATSPAWNID+3, @ATID+3, 1, 2569, 2294.504883, 2481.418213, 711.838318, 0.000343, 1, 0, 0, 1, 10, 25, 1, 10, 25, 1, 0, 0, 'at_aberrus_sarkareth_conversation_intro', 'Aberrus - Trigger Sabellian and Sarkareth Conversation');

DELETE FROM `areatrigger_template` WHERE `IsServerSide`=1 AND `Id` BETWEEN @ATID+0 AND @ATID+3;
INSERT INTO `areatrigger_template` (`Id`, `IsServerSide`, `Type`, `Flags`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `VerifiedBuild`) VALUES
(@ATID+0, 1, 1, 0, 1, 25, 80, 1, 25, 80, 0, 0, 0),
(@ATID+1, 1, 1, 0, 1, 20, 30, 1, 20, 30, 0, 0, 0),
(@ATID+2, 1, 1, 0, 20, 50, 5, 20, 50, 5, 0, 0, 0),
(@ATID+3, 1, 1, 0, 10, 25, 1, 10, 25, 1, 0, 0, 0);

DELETE FROM `areatrigger_template_actions` WHERE `AreaTriggerId` IN (@ATID+0, @ATID+1) AND `IsServerSide`=1;
INSERT INTO `areatrigger_template_actions` (`AreaTriggerId`, `IsServerSide`, `ActionType`, `ActionParam`, `TargetType`) VALUES
(@ATID+0, 1, 2, @WSLID+0, 3),
(@ATID+1, 1, 2, @WSLID+1, 3);

-- Creature and Gameobjects Data
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+82;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `VerifiedBuild`) VALUES
(@CGUID+0, 61829, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2237.08349609375, 2498.821533203125, 743.20501708984375, 5.043346881866455078, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Bat (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+1, 205338, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2263.173583984375, 2464.359375, 711.895751953125, 0.838580965995788574, 604800, 0, 0, 14462640, 0, 0, 0, 0, 49679), -- Black Dragonflight Guard (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+2, 174650, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2256.592041015625, 2456.084228515625, 711.884033203125, 2.183900356292724609, 604800, 0, 0, 5, 0, 0, 0, 0, 49679), -- Bubbling Refuse (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+3, 205338, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2254.7900390625, 2487.923583984375, 711.8607177734375, 5.897212028503417968, 604800, 0, 0, 14462640, 0, 0, 0, 0, 49679), -- Black Dragonflight Guard (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+4, 201575, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2245.203125, 2493.19970703125, 711.88397216796875, 4.031710624694824218, 604800, 0, 0, 144626400, 3387, 0, 0, 0, 49679), -- Sabellian (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+5, 201574, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2244.9775390625, 2469.798583984375, 711.86065673828125, 2.507639884948730468, 604800, 0, 0, 108469800, 0, 0, 0, 0, 49679), -- Wrathion (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject
(@CGUID+6, 174650, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2256.5693359375, 2448.405517578125, 711.91497802734375, 5.436953544616699218, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Bubbling Refuse (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+7, 194773, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2255.05029296875, 2514.05029296875, 713.00830078125, 0.087266460061073303, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Lava Slime (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 61829, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2236.273681640625, 2479.994384765625, 733.4683837890625, 1.51956188678741455, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Bat (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+9, 205348, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2257.857666015625, 2469.83154296875, 711.8607177734375, 0.786395788192749023, 604800, 0, 0, 7231320, 0, 0, 0, 0, 49679), -- Black Dragonflight Magus (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+10, 205338, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2263.663330078125, 2497.270751953125, 711.88031005859375, 5.358007431030273437, 604800, 0, 0, 14462640, 0, 0, 0, 0, 49679), -- Black Dragonflight Guard (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+11, 205348, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2258.10595703125, 2494.57470703125, 711.8607177734375, 5.567258358001708984, 604800, 0, 0, 7231320, 0, 0, 0, 0, 49679), -- Black Dragonflight Magus (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+12, 205350, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2233.2900390625, 2459.763916015625, 711.8607177734375, 2.194372177124023437, 604800, 0, 0, 352350, 0, 0, 0, 0, 49679), -- Forgemaster Bazentus (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+13, 174650, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2257.720947265625, 2452.0458984375, 711.98187255859375, 5.903138160705566406, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Bubbling Refuse (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+14, 205338, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2254.3681640625, 2475.479248046875, 711.8682861328125, 0.525706946849822998, 604800, 0, 0, 14462640, 0, 0, 0, 0, 49679), -- Black Dragonflight Guard (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+15, 61829, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2219.249267578125, 2472.490234375, 747.50579833984375, 0.454145312309265136, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Bat (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+16, 203403, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2227.859375, 2456.70654296875, 711.8607177734375, 2.194372177124023437, 604800, 0, 0, 112919, 0, 0, 0, 0, 49679), -- Cuzolth (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+17, 174650, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2252.746826171875, 2450.5390625, 711.9306640625, 0.572480976581573486, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Bubbling Refuse (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+18, 61829, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2218.767822265625, 2483.984130859375, 738.06072998046875, 3.929567813873291015, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Bat (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+19, 61829, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2243.205810546875, 2472.1689453125, 736.69403076171875, 3.559435844421386718, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Bat (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+20, 62885, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2230.609375, 2514.8203125, 713.475341796875, 2.164208173751831054, 604800, 10, 0, 1, 0, 1, 0, 0, 49679), -- Carrion Rat (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+21, 198869, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2318.529541015625, 2484.583251953125, 708.2506103515625, 3.17020726203918457, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Devastator (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+22, 61829, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2264.753173828125, 2492.071533203125, 746.7757568359375, 0.626436293125152587, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Bat (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (possible waypoints or random movement)
(@CGUID+23, 198873, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2391.335205078125, 2490.40283203125, 708.26104736328125, 3.62545323371887207, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+24, 198869, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2316.92529296875, 2472.51904296875, 708.12860107421875, 3.17020726203918457, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Devastator (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+25, 198871, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2392.282958984375, 2471.7119140625, 708.26104736328125, 2.768368721008300781, 604800, 0, 0, 3082209, 0, 0, 0, 0, 49679), -- Sundered Scaleguard (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+26, 205736, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2422.944580078125, 2464.73779296875, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Siegemaster (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+28, 198873, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2387.744873046875, 2498.701416015625, 708.26104736328125, 3.62545323371887207, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+29, 198872, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2389.07470703125, 2505.4541015625, 708.26104736328125, 3.62545323371887207, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Manaweaver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+30, 205737, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2447.569580078125, 2467.4462890625, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Manaweaver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+31, 188663, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2333.986572265625, 2468.986572265625, 729.69317626953125, 3.143372774124145507, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Flittering Flutterwing (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: 371442 - Dragonfly Delicacy) (possible waypoints or random movement)
(@CGUID+32, 198869, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2389.880126953125, 2457.498291015625, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Devastator (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+33, 205737, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2424.458251953125, 2458.67529296875, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Manaweaver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+34, 205736, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2426.861083984375, 2472.890625, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Siegemaster (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+35, 201261, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2434.770751953125, 2481.592041015625, 708.2611083984375, 3.158304452896118164, 604800, 10, 0, 151857720, 100, 0, 0, 0, 49679), -- Kazzara, the Hellforged (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject2 (Auras: 402538 - Energize) (possible waypoints or random movement)
(@CGUID+36, 188663, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2334.77099609375, 2496.4697265625, 730.00579833984375, 5.29783487319946289, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Flittering Flutterwing (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: 371442 - Dragonfly Delicacy) (possible waypoints or random movement)
(@CGUID+37, 53697, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2216.13720703125, 2531.2109375, 711.8607177734375, 0, 604800, 0, 0, 27, 0, 0, 0, 0, 49679), -- Cinderling (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+38, 205736, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2442.132080078125, 2464.901123046875, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Siegemaster (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+39, 198869, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2315.640625, 2490.31591796875, 708.1300048828125, 3.17020726203918457, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Devastator (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+40, 205737, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2440.1806640625, 2451.163330078125, 708.26104736328125, 2.768368721008300781, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Manaweaver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+41, 198873, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2341.220458984375, 2485.100830078125, 708.30303955078125, 3.168997049331665039, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+42, 198872, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2344.64404296875, 2490.736083984375, 708.2027587890625, 3.041532278060913085, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Manaweaver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+43, 198869, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2393.803955078125, 2466.104248046875, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Devastator (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+44, 205734, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2425.272705078125, 2496, 708.2611083984375, 3.421030759811401367, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+45, 198869, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2393.95654296875, 2495.6962890625, 708.26104736328125, 3.323389530181884765, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Devastator (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+46, 198871, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2312.55029296875, 2478.4462890625, 708.3294677734375, 3.17020726203918457, 604800, 0, 0, 3082209, 0, 0, 0, 0, 49679), -- Sundered Scaleguard (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+47, 205736, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2415.553955078125, 2448.454833984375, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Siegemaster (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+48, 198873, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2341.19970703125, 2478.302001953125, 708.2803955078125, 3.647537946701049804, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+49, 198872, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2345.76904296875, 2472.913330078125, 708.1923828125, 3.333299160003662109, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Manaweaver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+50, 188663, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2333.2041015625, 2496.614013671875, 730.40863037109375, 5.340238094329833984, 604800, 10, 0, 5, 0, 1, 0, 0, 49679), -- Flittering Flutterwing (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: 371442 - Dragonfly Delicacy) (possible waypoints or random movement)
(@CGUID+51, 198873, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2388.366455078125, 2463.560791015625, 708.26104736328125, 2.768368721008300781, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+52, 205735, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2422.579833984375, 2515.16845703125, 708.26104736328125, 3.62545323371887207, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Preserver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+53, 205734, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2420.90966796875, 2508.717041015625, 708.26104736328125, 3.62545323371887207, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+54, 205737, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2417.067626953125, 2442.392333984375, 708.3046875, 2.768368721008300781, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Manaweaver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+55, 205736, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2419.470458984375, 2456.607666015625, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Siegemaster (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+56, 188663, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2218.203125, 2533.296630859375, 716.7459716796875, 3.703330039978027343, 604800, 0, 0, 5, 0, 0, 0, 0, 49679), -- Flittering Flutterwing (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: 371442 - Dragonfly Delicacy)
(@CGUID+57, 205329, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2411.142333984375, 2541.0556640625, 708.80908203125, 0, 604800, 0, 0, 3623, 0, 0, 0, 0, 49679), -- Kazzara Lava Left (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+58, 205328, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2394.463623046875, 2411.973876953125, 708.25262451171875, 0, 604800, 0, 0, 3623, 0, 0, 0, 0, 49679), -- Kazzara Lava Right (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+59, 205734, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2445.197998046875, 2498.21875, 708.2611083984375, 3.474016427993774414, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+60, 205735, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2447.529541015625, 2504.697998046875, 708.2611083984375, 3.474016427993774414, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Preserver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+61, 198874, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2395.603, 2459.497, 708.2903, 0, 604800, 0, 0, 2845116, 0, 2, 0, 0, 49679), -- Sundered Siegemaster (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+62, 205735, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2418.6494140625, 2523.767333984375, 708.87921142578125, 3.62545323371887207, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Preserver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+63, 205734, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2417.319580078125, 2517.015625, 708.26104736328125, 3.62545323371887207, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+64, 205737, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2420.991455078125, 2451, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Manaweaver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+65, 205736, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2438.65966796875, 2456.770751953125, 708.26104736328125, 2.768368721008300781, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Siegemaster (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+66, 205737, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2436.257080078125, 2442.5556640625, 708.26104736328125, 2.768368721008300781, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Manaweaver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+67, 205734, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2447.494873046875, 2489.475830078125, 708.2611083984375, 3.474016427993774414, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+68, 205735, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2450.1181640625, 2495.600830078125, 708.2611083984375, 3.474016427993774414, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Preserver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+69, 205736, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2434.7431640625, 2448.6181640625, 708.26104736328125, 2.768368721008300781, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Siegemaster (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+70, 202637, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2482.9619140625, 2474.182373046875, 708.16259765625, 3.2256622314453125, 604800, 0, 0, 71127900, 100, 0, 0, 0, 49679), -- Zskarn (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+71, 205737, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2428.382080078125, 2467.282958984375, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Manaweaver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+72, 205734, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2427.10595703125, 2487.145751953125, 708.2611083984375, 3.421030759811401367, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+73, 202610, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2482.892333984375, 2488.42529296875, 708.16259765625, 3.2256622314453125, 604800, 0, 0, 23709300, 3155, 0, 0, 0, 49679), -- Winglord Dezran (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+74, 205735, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2427.9462890625, 2502.34033203125, 708.2611083984375, 3.421030759811401367, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Preserver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+75, 202416, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 0, 2477.041748046875, 2481.015625, 708.4306640625, 3.177701950073242187, 604800, 0, 0, 118546500, 3387, 0, 0, 0, 49679), -- Scalecommander Sarkareth (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@CGUID+76, 205735, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2430.05029296875, 2493.12158203125, 708.2611083984375, 3.421030759811401367, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Preserver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+77, 205735, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2442.382080078125, 2514.947998046875, 708.2611083984375, 3.62545323371887207, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Preserver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+78, 205734, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2440.7119140625, 2508.49658203125, 708.2611083984375, 3.62545323371887207, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+79, 205737, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2443.645751953125, 2458.838623046875, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Manaweaver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+80, 205736, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2446.048583984375, 2473.053955078125, 708.2611083984375, 2.768368721008300781, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679), -- Sundered Siegemaster (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+81, 205735, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2438.451416015625, 2523.546875, 708.87921142578125, 3.62545323371887207, 604800, 0, 0, 2608023, 0, 0, 0, 0, 49679), -- Sundered Preserver (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )
(@CGUID+82, 205734, 2569, 14663, 14663, '14,15,16,17', '0', 0, 0, 1, 2437.12158203125, 2516.795166015625, 708.2611083984375, 3.62545323371887207, 604800, 0, 0, 2845116, 0, 0, 0, 0, 49679); -- Sundered Edgelord (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1 (Auras: )

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 376886, 2569, 14663, 14663, '14,15,16,17', '0', 0, 2185.072998046875, 2482.572998046875, 718.5048828125, 0, 0, 0, 0, 1, 604800, 255, 1, 49679), -- Instance Portal (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@OGUID+1, 385684, 2569, 14663, 14663, '14,15,16,17', '0', 0, 2229.776123046875, 2459.423583984375, 711.77740478515625, 1.123094439506530761, 0, 0, 0.532496452331542968, 0.846432209014892578, 604800, 255, 1, 49679), -- Anvil (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@OGUID+2, 398742, 2569, 14663, 14663, '14,15,16,17', '0', 0, 2362.6162109375, 2480.9482421875, 707.445556640625, 3.141592741012573242, 0, 0, -1, 0, 604800, 255, 0, 49679), -- Door (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@OGUID+3, 398588, 2569, 14663, 14663, '14,15,16,17', '0', 0, 2465.521240234375, 2481.5849609375, 709.08056640625, 3.141592741012573242, 0, 0, -1, 0, 604800, 255, 0, 49679), -- Invisible Door (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@OGUID+4, 397996, 2569, 14663, 14663, '14,15,16,17', '0', 0, 2468.826904296875, 2481.5849609375, 707.1500244140625, 3.141592741012573242, 0, 0, -1, 0, 604800, 255, 0, 49679), -- Gate (Area: Aberrus, the Shadowed Crucible - Difficulty: Normal) CreateObject1
(@OGUID+5, 376886, 2454, 14022, 14648, '0', '0', 0, 1842.1129150390625, 2549.317626953125, -74.5390777587890625, 0, 0, 0, 0, 1, 120, 255, 1, 50000); -- Instance Portal (Area: Aberrus Approach - Difficulty: 0) CreateObject1

DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+5;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+2, 0, 0, 1, -0.00000004371138828, 0, 0), -- Door
(@OGUID+3, 0, 0, 1, -0.00000004371138828, 0, 0); -- Invisible Door

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (397996 /*Gate*/, 398588 /*Invisible Door*/, 398742 /*Door*/, 390080 /*Door*/, 376886 /*Instance Portal*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(397996, 0, 48, 0, 0), -- Gate
(398588, 0, 48, 0, 0), -- Invisible Door
(398742, 0, 48, 0, 0), -- Door
(376886, 0, 32, 0, 0); -- Instance Portal

DELETE FROM `gameobject_template` WHERE `entry` IN (398588 /*Invisible Door*/, 397996 /*Gate*/, 398742 /*Door*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(398588, 0, 10403, 'Invisible Door', '', '', '', 1.099999547004699707, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49679), -- Invisible Door
(397996, 0, 80035, 'Gate', '', '', '', 0.999999523162841796, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49679), -- Gate
(398742, 0, 80384, 'Door', '', '', '', 0.999999523162841796, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 49679); -- Door

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+82;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 3, 0, 1, 0, 0, 0, 3834, 0, 0, ''), -- Bat
(@CGUID+1, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Black Dragonflight Guard
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Black Dragonflight Guard
(@CGUID+8, 0, 0, 0, 3, 0, 1, 0, 0, 0, 3834, 0, 0, ''), -- Bat
(@CGUID+9, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Black Dragonflight Magus
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Black Dragonflight Guard
(@CGUID+11, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 0, ''), -- Black Dragonflight Magus
(@CGUID+14, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Black Dragonflight Guard
(@CGUID+15, 0, 0, 0, 3, 0, 1, 0, 0, 0, 3834, 0, 0, ''), -- Bat
(@CGUID+18, 0, 0, 0, 3, 0, 1, 0, 0, 0, 3834, 0, 0, ''), -- Bat
(@CGUID+19, 0, 0, 0, 3, 0, 1, 0, 0, 0, 3834, 0, 0, ''), -- Bat
(@CGUID+21, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Devastator
(@CGUID+22, 0, 0, 0, 3, 0, 1, 0, 0, 0, 3834, 0, 0, ''), -- Bat
(@CGUID+23, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Edgelord
(@CGUID+24, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Devastator
(@CGUID+25, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Scaleguard
(@CGUID+26, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Siegemaster
(@CGUID+28, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Edgelord
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 4, ''), -- Sundered Manaweaver
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 4, ''), -- Sundered Manaweaver
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Devastator
(@CGUID+33, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 4, ''), -- Sundered Manaweaver
(@CGUID+34, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Siegemaster
(@CGUID+35, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, '402538'), -- Kazzara, the Hellforged - 402538 - Energize
(@CGUID+38, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Siegemaster
(@CGUID+39, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Devastator
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 4, ''), -- Sundered Manaweaver
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Edgelord
(@CGUID+42, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 4, ''), -- Sundered Manaweaver
(@CGUID+43, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Devastator
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Edgelord
(@CGUID+45, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Devastator
(@CGUID+46, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Scaleguard
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Siegemaster
(@CGUID+48, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Edgelord
(@CGUID+49, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 4, ''), -- Sundered Manaweaver
(@CGUID+51, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Edgelord
(@CGUID+52, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Preserver
(@CGUID+53, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Edgelord
(@CGUID+54, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 4, ''), -- Sundered Manaweaver
(@CGUID+55, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Siegemaster
(@CGUID+57, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Kazzara Lava Left
(@CGUID+58, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Kazzara Lava Right
(@CGUID+59, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Edgelord
(@CGUID+60, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Preserver
(@CGUID+61, @PATH_SIEGEMASTER, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Sundered Siegemaster
(@CGUID+62, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Preserver
(@CGUID+63, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Edgelord
(@CGUID+64, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 4, ''), -- Sundered Manaweaver
(@CGUID+65, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Siegemaster
(@CGUID+66, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 4, ''), -- Sundered Manaweaver
(@CGUID+67, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Edgelord
(@CGUID+68, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Preserver
(@CGUID+69, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Siegemaster
(@CGUID+70, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 3, ''), -- Zskarn
(@CGUID+71, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 4, ''), -- Sundered Manaweaver
(@CGUID+72, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Edgelord
(@CGUID+73, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Winglord Dezran
(@CGUID+74, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Preserver
(@CGUID+75, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Scalecommander Sarkareth
(@CGUID+76, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Preserver
(@CGUID+77, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Preserver
(@CGUID+78, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Edgelord
(@CGUID+79, 0, 0, 0, 0, 0, 1, 0, 425, 0, 0, 0, 4, ''), -- Sundered Manaweaver
(@CGUID+80, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Siegemaster
(@CGUID+81, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''), -- Sundered Preserver
(@CGUID+82, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 4, ''); -- Sundered Edgelord

DELETE FROM `creature_equip_template` WHERE (`ID`=1 AND `CreatureID` IN (198874,205735,205734,205737,198872,205736,198871,198873,198869,205350,205348,205338));
INSERT INTO `creature_equip_template` (`CreatureID`, `ID`, `ItemID1`, `AppearanceModID1`, `ItemVisual1`, `ItemID2`, `AppearanceModID2`, `ItemVisual2`, `ItemID3`, `AppearanceModID3`, `ItemVisual3`, `VerifiedBuild`) VALUES
(198874, 1, 192148, 0, 0, 0, 0, 0, 0, 0, 0, 49679), -- Sundered Siegemaster
(205735, 1, 191778, 0, 0, 194930, 0, 0, 0, 0, 0, 49679), -- Sundered Preserver
(205734, 1, 191418, 0, 0, 0, 0, 0, 0, 0, 0, 49679), -- Sundered Edgelord
(205737, 1, 191870, 0, 0, 0, 0, 0, 0, 0, 0, 49679), -- Sundered Manaweaver
(198872, 1, 191870, 0, 0, 0, 0, 0, 0, 0, 0, 49679), -- Sundered Manaweaver
(205736, 1, 192148, 0, 0, 0, 0, 0, 0, 0, 0, 49679), -- Sundered Siegemaster
(198871, 1, 192162, 0, 0, 192166, 0, 0, 0, 0, 0, 49679), -- Sundered Scaleguard
(198873, 1, 191418, 0, 0, 0, 0, 0, 0, 0, 0, 49679), -- Sundered Edgelord
(198869, 1, 191866, 0, 0, 0, 0, 0, 0, 0, 0, 49679), -- Sundered Devastator
(205350, 1, 189688, 0, 0, 0, 0, 0, 0, 0, 0, 49679), -- Forgemaster Bazentus
(205348, 1, 191866, 0, 0, 0, 0, 0, 0, 0, 0, 49679), -- Black Dragonflight Magus
(205338, 1, 197729, 0, 0, 197709, 0, 0, 0, 0, 0, 49679); -- Black Dragonflight Guard

DELETE FROM `creature_model_info` WHERE `DisplayID` IN (112765, 111508, 111505, 110856, 111477, 110407, 112680, 104320, 102272, 112996, 110401, 112165, 102795);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(112765, 0.864697158336639404, 3.5, 0, 49679),
(111508, 6, 13, 0, 49679),
(111505, 1.20000004768371582, 15.60000038146972656, 0, 49679),
(110856, 0.685900032520294189, 1.899999976158142089, 0, 49679),
(111477, 3.139086008071899414, 8.050000190734863281, 0, 49679),
(110407, 0.722000002861022949, 2, 0, 49679),
(104320, 1.584961533546447753, 2.099999904632568359, 0, 49679),
(102272, 2.106381893157958984, 3.60000014305114746, 0, 49679),
(112996, 1.880967140197753906, 5.634999752044677734, 0, 49679),
(110401, 0.721999943256378173, 2, 0, 49679),
(112165, 0.722000002861022949, 2, 0, 49679),
(102795, 1.584961533546447753, 2.099999904632568359, 0, 49679);

DELETE FROM `creature_template_difficulty` WHERE (`DifficultyID`=14 AND `Entry` IN (201261,202416,202610,202637,198874,205328,205329,205735,205734,205737,198872,205736,198871,198873,198869,203403,205350,205348,194773,201574,201575,174650,205338));
INSERT INTO `creature_template_difficulty` (`Entry`, `DifficultyID`, `LevelScalingDeltaMin`, `LevelScalingDeltaMax`, `ContentTuningID`, `HealthScalingExpansion`, `HealthModifier`, `ManaModifier`, `CreatureDifficultyID`, `TypeFlags`, `TypeFlags2`, `VerifiedBuild`) VALUES
(201261, 14, 3, 3, 2645, 9, 420, 1, 234281, 2097228, 67108992, 49679),
(202416, 14, 3, 3, 2645, 9, 500, 1, 231034, 2097260, 65536, 49679),
(202610, 14, 0, 0, 2645, 9, 100, 1, 231226, 2097260, 65536, 49679),
(202637, 14, 3, 3, 2645, 9, 300, 1, 231253, 2097260, 128, 49679),
(198874, 14, 1, 1, 2645, 9, 12, 1, 227286, 270532680, 0, 49679),
(205328, 14, 0, 0, 2057, 8, 0.100000001490116119, 1, 234504, 1073741824, 0, 49679),
(205329, 14, 0, 0, 2057, 8, 0.100000001490116119, 1, 234505, 1073741824, 0, 49679),
(205735, 14, 1, 1, 2645, 9, 11, 1, 234926, 2097224, 0, 49679),
(205734, 14, 1, 1, 2645, 9, 12, 1, 234925, 2097224, 0, 49679),
(205737, 14, 1, 1, 2645, 9, 11, 1, 234928, 2097224, 0, 49679),
(198872, 14, 1, 1, 2645, 9, 11, 1, 227284, 2097224, 0, 49679),
(205736, 14, 1, 1, 2645, 9, 12, 1, 234927, 2097224, 0, 49679),
(198871, 14, 1, 1, 2645, 9, 13, 1, 227283, 2097224, 0, 49679),
(198873, 14, 1, 1, 2645, 9, 12, 1, 227285, 2097224, 0, 49679),
(198869, 14, 1, 1, 2645, 9, 11, 1, 227281, 2097224, 0, 49679),
(203403, 14, 0, 0, 2627, 9, 1, 1, 232500, 0, 0, 49679),
(205350, 14, 0, 0, 2151, 9, 10, 1, 234526, 0, 32768, 49679),
(205348, 14, 2, 2, 2645, 9, 20, 1, 234524, 2097224, 0, 49679),
(194773, 14, 0, 0, 81, 9, 0.200000002980232238, 1, 223006, 0, 0, 49679),
(201574, 14, 0, 0, 2645, 9, 300, 1, 230187, 4, 0, 49679),
(201575, 14, 3, 3, 2645, 9, 400, 1, 230188, 4, 0, 49679),
(174650, 14, 0, 0, 81, 9, 0.200000002980232238, 1, 196698, 0, 0, 49679),
(205338, 14, 2, 2, 2645, 9, 40, 1, 234514, 2097224, 0, 49679);

DELETE FROM `creature_template_movement` WHERE `CreatureId`=188663;
INSERT INTO `creature_template_movement` (`CreatureId`, `Ground`, `Swim`, `Flight`, `Rooted`, `Chase`, `Random`, `InteractionPauseTimer`) VALUES
(188663, 0, 0, 1, 0, 0, 0, NULL);

DELETE FROM `creature_template_addon` WHERE `entry` IN (188663 /*188663 (Flittering Flutterwing) - Dragonfly Delicacy*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(188663, 0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, '371442'); -- 188663 (Flittering Flutterwing) - Dragonfly Delicacy

DELETE FROM `waypoint_data` WHERE `id`= @PATH_SIEGEMASTER;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH_SIEGEMASTER, 0, 2395.603, 2459.497, 708.2903, NULL, 5814, 1),
(@PATH_SIEGEMASTER, 1, 2410.109, 2471.991, 708.2902, NULL, 0, 1),
(@PATH_SIEGEMASTER, 2, 2408.983, 2491.738, 708.2902, NULL, 0, 1),
(@PATH_SIEGEMASTER, 3, 2401.788, 2503.958, 708.2902, NULL, 0, 1),
(@PATH_SIEGEMASTER, 4, 2394.375, 2501.688, 708.3055, NULL, 5655, 1),
(@PATH_SIEGEMASTER, 5, 2410.031, 2486.123, 708.2902, NULL, 0, 1),
(@PATH_SIEGEMASTER, 6, 2409.898, 2470.884, 708.2902, NULL, 0, 1),
(@PATH_SIEGEMASTER, 7, 2401.526, 2456.868, 708.2902, NULL, 0, 1),
(@PATH_SIEGEMASTER, 8, 2395.603, 2459.497, 708.2903, NULL, 5885, 1),
(@PATH_SIEGEMASTER, 9, 2410.109, 2471.991, 708.2902, NULL, 0, 1),
(@PATH_SIEGEMASTER, 10, 2408.983, 2491.738, 708.2902, NULL, 0, 1),
(@PATH_SIEGEMASTER, 11, 2401.788, 2503.958, 708.2902, NULL, 10, 1),
(@PATH_SIEGEMASTER, 12, 2394.375, 2501.688, 708.3055, NULL, 6895, 1),
(@PATH_SIEGEMASTER, 13, 2410.031, 2486.123, 708.2902, NULL, 0, 1),
(@PATH_SIEGEMASTER, 14, 2409.898, 2470.884, 708.2902, NULL, 0, 1),
(@PATH_SIEGEMASTER, 15, 2401.526, 2456.868, 708.2902, NULL, 0, 1);

DELETE FROM `waypoint_data` WHERE `id`=@PATH_SARKARETH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH_SARKARETH, 0, 2500.0615, 2482.264, 708.7047, NULL, 0, 0, 0, 100, 0),
(@PATH_SARKARETH, 1, 2511.0615, 2482.014, 701.9547, NULL, 0, 0, 0, 100, 0),
(@PATH_SARKARETH, 2, 2519.8115, 2485.014, 700.4547, NULL, 0, 0, 0, 100, 0),
(@PATH_SARKARETH, 3, 2526.8115, 2492.264, 700.4547, NULL, 0, 0, 0, 100, 0),
(@PATH_SARKARETH, 4, 2535.8115, 2515.014, 700.4547, NULL, 0, 0, 0, 100, 0),
(@PATH_SARKARETH, 5, 2540.0615, 2529.014, 700.4547, NULL, 0, 0, 0, 100, 0),
(@PATH_SARKARETH, 6, 2544.5642, 2552.007, 699.9161, NULL, 0, 0, 0, 100, 0);

DELETE FROM `waypoint_data` WHERE `id`=@PATH_WINGLORD_DEZRAN;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH_WINGLORD_DEZRAN, 0, 2494.0542, 2487.5217, 708.2893, NULL, 0, 0, 0, 100, 0),
(@PATH_WINGLORD_DEZRAN, 1, 2500.8042, 2487.5217, 708.5393, NULL, 0, 0, 0, 100, 0),
(@PATH_WINGLORD_DEZRAN, 2, 2512.8042, 2490.0217, 700.5393, NULL, 0, 0, 0, 100, 0),
(@PATH_WINGLORD_DEZRAN, 3, 2517.5542, 2493.2717, 700.2893, NULL, 0, 0, 0, 100, 0),
(@PATH_WINGLORD_DEZRAN, 4, 2520.8042, 2500.0217, 700.2893, NULL, 0, 0, 0, 100, 0),
(@PATH_WINGLORD_DEZRAN, 5, 2531.5542, 2529.7717, 700.2893, NULL, 0, 0, 0, 100, 0),
(@PATH_WINGLORD_DEZRAN, 6, 2535.716, 2551.6182, 699.9161, NULL, 0, 0, 0, 100, 0);

DELETE FROM `waypoint_data` WHERE `id`=@PATH_ZSKARN;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(@PATH_ZSKARN, 0, 2500.9102, 2474.3933, 708.5393, NULL, 0, 0, 0, 100, 0),
(@PATH_ZSKARN, 1, 2512.4102, 2473.3933, 701.0393, NULL, 0, 0, 0, 100, 0),
(@PATH_ZSKARN, 2, 2522.9102, 2476.1433, 700.2893, NULL, 0, 0, 0, 100, 0),
(@PATH_ZSKARN, 3, 2534.1602, 2487.6433, 700.2893, NULL, 0, 0, 0, 100, 0),
(@PATH_ZSKARN, 4, 2545.9102, 2511.8933, 700.2893, NULL, 0, 0, 0, 100, 0),
(@PATH_ZSKARN, 5, 2555.8586, 2552.1042, 699.9161, NULL, 0, 0, 0, 100, 0);

DELETE FROM `npc_vendor` WHERE (`entry`=205350 AND `item`=204634 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=205350 AND `item`=2901 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=205350 AND `item`=5956 AND `ExtendedCost`=0 AND `type`=1) OR (`entry`=205350 AND `item`=190452 AND `ExtendedCost`=0 AND `type`=1);
INSERT INTO `npc_vendor` (`entry`, `slot`, `item`, `maxcount`, `ExtendedCost`, `type`, `PlayerConditionID`, `IgnoreFiltering`, `VerifiedBuild`) VALUES
(205350, 4, 204634, 0, 0, 1, 0, 0, 49679), -- Rot Resistant Cauldron
(205350, 3, 2901, 0, 0, 1, 0, 0, 49679), -- Mining Pick
(205350, 2, 5956, 0, 0, 1, 0, 0, 49679), -- Blacksmith Hammer
(205350, 1, 190452, 0, 0, 1, 0, 0, 49679); -- Primal Flux

UPDATE `creature_model_info` SET `BoundingRadius`=1.930850028991699218, `CombatReach`=3.300000190734863281, `VerifiedBuild`=49679 WHERE `DisplayID`=102286;
UPDATE `creature_model_info` SET `CombatReach`=3.60000014305114746, `VerifiedBuild`=49679 WHERE `DisplayID` IN (102318, 102320, 102327, 103004, 102766, 102324, 102322);
UPDATE `creature_model_info` SET `BoundingRadius`=0.551690876483917236, `CombatReach`=0.375000029802322387, `VerifiedBuild`=49679 WHERE `DisplayID`=96635;
UPDATE `creature_model_info` SET `VerifiedBuild`=49679 WHERE `DisplayID` IN (107146, 104559, 108050, 103844, 103843, 103842, 103841, 104904);

UPDATE `creature_template` SET `faction`=16, `speed_walk`=4.800000190734863281, `speed_run`=1.714285731315612792, `BaseAttackTime`=2000, `unit_flags2`=2097152, `ScriptName`='boss_kazzara_the_hellforged' WHERE `entry`=201261; -- Kazzara, the Hellforged
UPDATE `creature_template` SET `faction`=14, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=320, `unit_flags2`=4194304 WHERE `entry`=202416; -- Scalecommander Sarkareth
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=2097152 WHERE `entry`=202637; -- Zskarn
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352, `StringId`='sundered_mob' WHERE `entry`=198874; -- Sundered Siegemaster
UPDATE `creature_template` SET `faction`=35, `speed_walk`=3.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2048, `unit_flags3`=16777216, `flags_extra`=128 WHERE `entry`=205328; -- Kazzara Lava Right
UPDATE `creature_template` SET `faction`=35, `speed_walk`=3.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=33587456, `unit_flags2`=2048, `unit_flags3`=16777216, `flags_extra`=128 WHERE `entry`=205329; -- Kazzara Lava Left
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `StringId`='sundered_mob' WHERE `entry`=205735; -- Sundered Preserver
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `StringId`='sundered_mob' WHERE `entry`=205734; -- Sundered Edgelord
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `StringId`='sundered_mob' WHERE `entry`=205737; -- Sundered Manaweaver
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=188663; -- Flittering Flutterwing
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352, `StringId`='sundered_mob' WHERE `entry`=198872; -- Sundered Manaweaver
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048, `StringId`='sundered_mob' WHERE `entry`=205736; -- Sundered Siegemaster
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352, `StringId`='sundered_mob' WHERE `entry`=198871; -- Sundered Scaleguard
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352, `StringId`='sundered_mob' WHERE `entry`=198873; -- Sundered Edgelord
UPDATE `creature_template` SET `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=4196352, `StringId`='sundered_mob' WHERE `entry`=198869; -- Sundered Devastator
UPDATE `creature_template` SET `faction`=35, `npcflag`=4294967296, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=203403; -- Cuzolth
UPDATE `creature_template` SET `faction`=3276, `npcflag`=4224, `BaseAttackTime`=2000, `unit_flags`=33600, `unit_flags2`=2048 WHERE `entry`=205350; -- Forgemaster Bazentus
UPDATE `creature_template` SET `faction`=35, `speed_walk`=1.60000002384185791, `speed_run`=1.857142806053161621, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=205348; -- Black Dragonflight Magus
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194773; -- Lava Slime
UPDATE `creature_template` SET `faction`=35, `npcflag`=3, `speed_walk`=1.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=201574; -- Wrathion
UPDATE `creature_template` SET `faction`=35, `speed_walk`=1.20000004768371582, `BaseAttackTime`=2000, `unit_flags`=33536, `unit_flags2`=2048 WHERE `entry`=201575; -- Sabellian
UPDATE `creature_template` SET `faction`=35, `speed_walk`=1.60000002384185791, `speed_run`=1.857142806053161621, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=205338; -- Black Dragonflight Guard
UPDATE `creature_template` SET `faction`=14, `BaseAttackTime`=2000, `unit_flags`=256, `unit_flags2`=4194304, `unit_flags3`=1 WHERE `entry`=202610; -- Winglord Dezran

UPDATE `gameobject_template` SET `VerifiedBuild`=50000 WHERE `entry` IN (376886, 385684);

-- Conversations
DELETE FROM `conversation_actors` WHERE (`ConversationId` IN (20800, 20970, 20985) AND `Idx` IN (0,1,2));
INSERT INTO `conversation_actors` (`ConversationId`, `ConversationActorId`, `ConversationActorGuid`, `Idx`, `CreatureId`, `CreatureDisplayInfoId`, `NoActorObject`, `ActivePlayerObject`, `VerifiedBuild`) VALUES
(20800, 89966, @CGUID+4, 0, 0, 0, 0, 0, 50000), -- Full: 0x203CD94120C4D9C000049400002977D5 Creature/0 R3894/S1172 Map: 2569 (Aberrus, the Shadowed Crucible) Entry: 201575 (Sabellian) Low: 2717653
(20800, 89965, @CGUID+5, 1, 0, 0, 0, 0, 50000), -- Full: 0x203CD94120C4D98000049400002977D4 Creature/0 R3894/S1172 Map: 2569 (Aberrus; the Shadowed Crucible) Entry: 201574 (Wrathion) Low: 2717652
(20970, 90307, @CGUID+75, 1, 0, 0, 0, 0, 50000), -- Full: 0x2042554120C5AC000069F50000666449 Creature/0 R4245/S27125 Map: 2569 (Aberrus, the Shadowed Crucible) Entry: 202416 (Scalecommander Sarkareth) Low: 6710345
(20970, 89966, @CGUID+4, 0, 0, 0, 0, 0, 50000), -- Full: 0x2042554120C4D9C00069F50000666448 Creature/0 R4245/S27125 Map: 2569 (Aberrus, the Shadowed Crucible) Entry: 201575 (Sabellian) Low: 6710344
(20985, 90307, @CGUID+75, 2, 0, 0, 0, 0, 50000), -- Full: 0x2042554120C5AC000069F50000666449 Creature/0 R4245/S27125 Map: 2569 (Aberrus, the Shadowed Crucible) Entry: 202416 (Scalecommander Sarkareth) Low: 6710345
(20985, 90376, @CGUID+73, 0, 0, 0, 0, 0, 50000), -- Full: 0x2042554120C5DC800069F50000666448 Creature/0 R4245/S27125 Map: 2569 (Aberrus, the Shadowed Crucible) Entry: 202610 (Winglord Dezran) Low: 6710344
(20985, 90395, @CGUID+70, 1, 0, 0, 0, 0, 50000); -- Full: 0x2042554120C5E3400069F50000666448 Creature/0 R4245/S27125 Map: 2569 (Aberrus, the Shadowed Crucible) Entry: 202637 (Zskarn) Low: 6710344

DELETE FROM `conversation_line_template` WHERE `Id` IN (56693, 56692, 56691, 56690, 56694, 56695, 56696, 56697, 56698, 56699, 56700, 56701, 56702, 57836, 57837, 57838, 57821);
INSERT INTO `conversation_line_template` (`Id`, `UiCameraID`, `ActorIdx`, `Flags`, `ChatType`, `VerifiedBuild`) VALUES
(56693, 0, 0, 0, 0, 50000),
(56692, 0, 0, 0, 0, 50000),
(56691, 0, 1, 0, 0, 50000),
(56690, 0, 0, 0, 0, 50000),
(56696, 0, 1, 0, 0, 50000),
(56695, 0, 1, 0, 0, 50000),
(56694, 0, 0, 0, 0, 50000),
(57821, 0, 2, 0, 0, 50000),
(56702, 0, 0, 0, 0, 50000),
(56701, 0, 2, 0, 0, 50000),
(57838, 0, 1, 0, 0, 50000),
(57837, 0, 1, 0, 0, 50000),
(57836, 0, 2, 0, 0, 50000),
(56700, 0, 1, 0, 0, 50000),
(56699, 0, 1, 0, 0, 50000),
(56698, 0, 1, 0, 0, 50000),
(56697, 0, 0, 0, 0, 50000);

DELETE FROM `conversation_template` WHERE `Id`IN (20800, 20985, 20970);
INSERT INTO `conversation_template` (`Id`, `FirstLineId`, `TextureKitId`, `ScriptName`, `VerifiedBuild`) VALUES
(20800, 56690, 0, 'conversation_aberrus_sabellian_intro', 50000),
(20970, 56694, 0, '', 50000),
(20985, 56697, 0, 'conversation_aberrus_kazzara_intro', 50000);

-- Conditions
SET @CONDREF := -4;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`IN (1,2);
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=@CONDREF-0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(13, 1, 411873, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Spell 411873 can only hit Player'),
(13, 2, 411873, 0, 0, 31, 0, 4, 0, 0, 0, 0, 0, '', 'Spell 411873 can only hit Player'),
(13, 1, 411877, 0, 0, @CONDREF-0, 0, 0, 0, 0, 0, 0, 0, '', 'Spell 411877 can only hit npcs on condition reference'),
(13, 2, 411874, 0, 0, @CONDREF-0, 0, 0, 0, 0, 0, 0, 0, '', 'Spell 411877 can only hit npcs on condition reference'),
(@CONDREF-0, 0, 0, 0, 0, 31, 0, 3, 205734, 0, 0, 0, 0, '', 'Apply condition reference on Sundered Edgelord'),
(@CONDREF-0, 0, 0, 0, 1, 31, 0, 3, 205735, 0, 0, 0, 0, '', 'Apply condition reference on Sundered Preserver'),
(@CONDREF-0, 0, 0, 0, 2, 31, 0, 3, 205736, 0, 0, 0, 0, '', 'Apply condition reference on Sundered Siegemaster'),
(@CONDREF-0, 0, 0, 0, 3, 31, 0, 3, 205737, 0, 0, 0, 0, '', 'Apply condition reference on Sundered Manaweaver'),
(@CONDREF-0, 0, 0, 0, 4, 31, 0, 3, 198869, 0, 0, 0, 0, '', 'Apply condition reference on Sundered Devastator'),
(@CONDREF-0, 0, 0, 0, 5, 31, 0, 3, 198871, 0, 0, 0, 0, '', 'Apply condition reference on Sundered Scaleguard'),
(@CONDREF-0, 0, 0, 0, 6, 31, 0, 3, 198872, 0, 0, 0, 0, '', 'Apply condition reference on Sundered Manaweaver'),
(@CONDREF-0, 0, 0, 0, 7, 31, 0, 3, 198873, 0, 0, 0, 0, '', 'Apply condition reference on Sundered Edgelord'),
(@CONDREF-0, 0, 0, 0, 8, 31, 0, 3, 198874, 0, 0, 0, 0, '', 'Apply condition reference on Sundered Siegemaster');
