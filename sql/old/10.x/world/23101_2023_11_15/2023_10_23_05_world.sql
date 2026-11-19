SET @CGUID := 6000773;
SET @OGUID := 6000576;

-- Creature templates
DELETE FROM `creature_template_addon` WHERE `entry` IN (109825, 109734);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(109825, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 109825 (Aria Sorrowheart)
(109734, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 109734 (Hag of the Crooked Tree)

-- Models
UPDATE `creature_template_model` SET `VerifiedBuild`=51754 WHERE (`Idx`=3 AND `CreatureID`=112453) OR (`Idx`=2 AND `CreatureID` IN (112453,168932,49690)) OR (`Idx`=1 AND `CreatureID` IN (112453,93416,168932,49690)) OR (`Idx`=0 AND `CreatureID` IN (112453,94518,111383,2110,94383,93416,168932,111384,109734,109860,109825,49690,98090));

UPDATE `creature_model_info` SET `BoundingRadius`=0.300000011920928955, `CombatReach`=1, `VerifiedBuild`=51754 WHERE `DisplayID`=100508;
UPDATE `creature_model_info` SET `VerifiedBuild`=51754 WHERE `DisplayID` IN (40021, 47755, 55461, 58128, 70772, 71147, 42265, 64050, 67969, 1160);

-- Quests
UPDATE `quest_greeting` SET `VerifiedBuild`=51754 WHERE (`ID`=109734 AND `Type`=0);

UPDATE `quest_details` SET `VerifiedBuild`=51754 WHERE `ID`=43162;

DELETE FROM `quest_request_items` WHERE `ID`=43162;
INSERT INTO `quest_request_items` (`ID`, `EmoteOnComplete`, `EmoteOnIncomplete`, `EmoteOnCompleteDelay`, `EmoteOnIncompleteDelay`, `CompletionText`, `VerifiedBuild`) VALUES
(43162, 0, 0, 0, 0, 'Steel your heart and drink deep,$b$bReturn my sister back to sleep.', 51754); -- Under the Crooked Tree

UPDATE `quest_offer_reward` SET `VerifiedBuild`=51754 WHERE `ID` IN (43162, 43259);

UPDATE `creature_queststarter` SET `VerifiedBuild`=51754 WHERE (`id`=109734 AND `quest`=43162);

UPDATE `creature_questender` SET `VerifiedBuild`=51754 WHERE (`id`=109734 AND `quest` IN (43162,43259));

-- Old creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN 651343 AND 651353;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN 651343 AND 651353;
DELETE FROM `game_event_creature` WHERE `guid` BETWEEN 651343 AND 651353;

-- Creature spawns
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 109734, 1220, 7558, 7642, '0', 0, 0, 0, 0, 2906.13720703125, 7677.853515625, 4.001736164093017578, 4.70738077163696289, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Hag of the Crooked Tree (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@CGUID+1, 109825, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2927.71435546875, 7699.83837890625, 4.174652099609375, 4.059299945831298828, 120, 0, 0, 2258380, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Aria Sorrowheart (Area: Bradensbrook - Difficulty: 0) CreateObject1 (Auras: )
(@CGUID+2, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2921.678955078125, 7713.064453125, 14.75717449188232421, 4.414573192596435546, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@CGUID+3, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2950.013916015625, 7713.34912109375, 18.54337310791015625, 3.571464061737060546, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@CGUID+4, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2934.327392578125, 7696.11572265625, 25.71790313720703125, 4.198917388916015625, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@CGUID+5, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2917.4296875, 7712.92041015625, 26.51630783081054687, 4.414573192596435546, 120, 0, 0, 112919, 0, 0, NULL, NULL, NULL, NULL, 51754), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@CGUID+6, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2944.6902, 7689.033, 27.137547, 0, 120, 0, 0, 112919, 0, 2, NULL, NULL, NULL, NULL, 51754), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@CGUID+7, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2927.2039, 7690.2583, 23.157822, 0, 120, 0, 0, 112919, 0, 2, NULL, NULL, NULL, NULL, 51754), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+8, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2918.6843, 7729.5454, 18.94083, 0, 120, 0, 0, 112919, 0, 2, NULL, NULL, NULL, NULL, 51754), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+9, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2942.7214, 7698.4077, 25.029968, 0, 120, 0, 0, 112919, 0, 2, NULL, NULL, NULL, NULL, 51754), -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+10, 109860, 1220, 7558, 7642, '0', 6944, 0, 0, 0, 2925.2622, 7739.953, 23.024887, 0, 120, 0, 0, 112919, 0, 2, NULL, NULL, NULL, NULL, 51754); -- Crooked Tree Crow (Area: Bradensbrook - Difficulty: 0) CreateObject1 (possible waypoints or random movement)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+6 AND @CGUID+10;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+6, (109860*100)+0, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 109860 (Crooked Tree Crow)
(@CGUID+7, (109860*100)+1, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 109860 (Crooked Tree Crow)
(@CGUID+8, (109860*100)+2, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 109860 (Crooked Tree Crow)
(@CGUID+9, (109860*100)+3, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 109860 (Crooked Tree Crow)
(@CGUID+10, (109860*100)+4, 0, 0, 3, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 109860 (Crooked Tree Crow)

DELETE FROM `waypoint_data` WHERE `id` BETWEEN (109860*100)+0 AND (109860*100)+4;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
((109860*100)+0, 0, 2955.2969, 7693.427, 27.137547, NULL, 0, 0),
((109860*100)+0, 1, 2959.6902, 7704.033, 27.137547, NULL, 0, 0),
((109860*100)+0, 2, 2955.2969, 7714.6396, 27.137547, NULL, 0, 0),
((109860*100)+0, 3, 2944.6902, 7719.033, 27.137547, NULL, 0, 0),
((109860*100)+0, 4, 2934.0835, 7714.6396, 27.137547, NULL, 0, 0),
((109860*100)+0, 5, 2929.6902, 7704.033, 27.137547, NULL, 0, 0),
((109860*100)+0, 6, 2934.0835, 7693.427, 27.137547, NULL, 0, 0),
((109860*100)+0, 7, 2944.6902, 7689.033, 27.137547, NULL, 0, 0),
((109860*100)+1, 0, 2927.2039, 7690.2583, 23.157822, NULL, 0, 0),
((109860*100)+1, 1, 2931.5972, 7700.8647, 23.157822, NULL, 0, 0),
((109860*100)+1, 2, 2927.2039, 7711.471, 23.157822, NULL, 0, 0),
((109860*100)+1, 3, 2916.5972, 7715.8647, 23.157822, NULL, 0, 0),
((109860*100)+1, 4, 2905.9905, 7711.471, 23.157822, NULL, 0, 0),
((109860*100)+1, 5, 2901.5972, 7700.8647, 23.157822, NULL, 0, 0),
((109860*100)+1, 6, 2905.9905, 7690.2583, 23.157822, NULL, 0, 0),
((109860*100)+1, 7, 2916.5972, 7685.8647, 23.157822, NULL, 0, 0),
((109860*100)+2, 0, 2916.2512, 7718.3257, 18.94083, NULL, 0, 0),
((109860*100)+2, 1, 2922.4644, 7708.6714, 18.94083, NULL, 0, 0),
((109860*100)+2, 2, 2933.684, 7706.239, 18.94083, NULL, 0, 0),
((109860*100)+2, 3, 2943.3381, 7712.4517, 18.94083, NULL, 0, 0),
((109860*100)+2, 4, 2945.7712, 7723.6714, 18.94083, NULL, 0, 0),
((109860*100)+2, 5, 2939.558, 7733.325, 18.94083, NULL, 0, 0),
((109860*100)+2, 6, 2928.3384, 7735.7583, 18.94083, NULL, 0, 0),
((109860*100)+2, 7, 2918.6843, 7729.5454, 18.94083, NULL, 0, 0),
((109860*100)+3, 0, 2963.9348, 7698.4077, 25.029968, NULL, 0, 0),
((109860*100)+3, 1, 2968.3281, 7709.014, 25.029968, NULL, 0, 0),
((109860*100)+3, 2, 2963.9348, 7719.6206, 25.029968, NULL, 0, 0),
((109860*100)+3, 3, 2953.3281, 7724.014, 25.029968, NULL, 0, 0),
((109860*100)+3, 4, 2942.7214, 7719.6206, 25.029968, NULL, 0, 0),
((109860*100)+3, 5, 2938.3281, 7709.014, 25.029968, NULL, 0, 0),
((109860*100)+3, 6, 2942.7214, 7698.4077, 25.029968, NULL, 0, 0),
((109860*100)+3, 7, 2953.3281, 7694.014, 25.029968, NULL, 0, 0),
((109860*100)+4, 0, 2935.869, 7735.5596, 23.024887, NULL, 0, 0),
((109860*100)+4, 1, 2940.2622, 7724.953, 23.024887, NULL, 0, 0),
((109860*100)+4, 2, 2935.869, 7714.3467, 23.024887, NULL, 0, 0),
((109860*100)+4, 3, 2925.2622, 7709.953, 23.024887, NULL, 0, 0),
((109860*100)+4, 4, 2914.6555, 7714.3467, 23.024887, NULL, 0, 0),
((109860*100)+4, 5, 2910.2622, 7724.953, 23.024887, NULL, 0, 0),
((109860*100)+4, 6, 2914.6555, 7735.5596, 23.024887, NULL, 0, 0),
((109860*100)+4, 7, 2925.2622, 7739.953, 23.024887, NULL, 0, 0);

-- Old gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN 400379 AND 400391;
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN 400379 AND 400391;
DELETE FROM `game_event_gameobject` WHERE `guid` BETWEEN 400379 AND 400391;

-- Gameobject spawns
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+12;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 180411, 1220, 7558, 7642, '0', 0, 0, 2938.84814453125, 7706.15185546875, 8.826979637145996093, 2.047860622406005859, 0, 0, 0.854158401489257812, 0.520012855529785156, 120, 255, 1, 51754), -- G_Ghost_01 (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@OGUID+1, 180411, 1220, 7558, 7642, '0', 6944, 0, 2938.838623046875, 7706.150390625, 8.841352462768554687, 2.047860622406005859, 0, 0, 0.854158401489257812, 0.520012855529785156, 120, 255, 1, 51754), -- G_Ghost_01 (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@OGUID+2, 248860, 1220, 7558, 7642, '0', 0, 0, 2896.405517578125, 7680.525390625, 4.33762979507446289, 3.673851728439331054, 0, 0, -0.96479606628417968, 0.262999176979064941, 120, 255, 1, 51754), -- Books (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@OGUID+3, 248860, 1220, 7558, 7642, '0', 0, 0, 2900.036376953125, 7678.84912109375, 4.01916360855102539, 0, 0, 0, 0, 1, 120, 255, 1, 51754), -- Books (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@OGUID+4, 251706, 1220, 7558, 7642, '0', 0, 0, 2905.947998046875, 7675.81884765625, 4.686910152435302734, 4.7073822021484375, 0, 0, -0.70887470245361328, 0.705334424972534179, 120, 255, 0, 51754), -- Crooked Tree Cauldron (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@OGUID+5, 251765, 1220, 7558, 7642, '0', 0, 0, 2896.572998046875, 7678.57568359375, 4.042050361633300781, 4.079247951507568359, 0.025952816009521484, 0.021407127380371093, -0.89148426055908203, 0.451800823211669921, 120, 255, 1, 51754), -- Crooked Tree Tent (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@OGUID+6, 251768, 1220, 7558, 7642, '0', 0, 0, 2894.333251953125, 7673.99658203125, 4.345799922943115234, 0, 0, 0, 0, 1, 120, 255, 1, 51754), -- Spooky Light Big (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@OGUID+7, 251768, 1220, 7558, 7642, '0', 0, 0, 2900.84375, 7682.70947265625, 4.939099788665771484, 0, 0, 0, 0, 1, 120, 255, 1, 51754), -- Spooky Light Big (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@OGUID+8, 251822, 1220, 7558, 7642, '0', 0, 0, 2899.237060546875, 7679.2734375, 4.079217910766601562, 4.515312671661376953, 0, 0, -0.77324104309082031, 0.634112238883972167, 120, 255, 1, 51754), -- Crooked Tree Chair (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@OGUID+9, 251823, 1220, 7558, 7642, '0', 0, 0, 2894.14501953125, 7680.35791015625, 4.618403911590576171, 4.110296249389648437, -0.0405592918395996, 0.105701446533203125, -0.87858390808105468, 0.463974654674530029, 120, 255, 1, 51754), -- Crooked Tree Bed (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@OGUID+10, 251824, 1220, 7558, 7642, '0', 0, 0, 2897.671875, 7677.541015625, 3.973532915115356445, 2.426764965057373046, 0.01990365982055664, -0.04411602020263671, 0.935296058654785156, 0.350540876388549804, 120, 255, 1, 51754), -- Crooked Tree Rug (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@OGUID+11, 251826, 1220, 7558, 7642, '0', 0, 0, 2904.35498046875, 7678.31005859375, 5.042687416076660156, 0, 0, 0, 0, 1, 120, 255, 1, 51754), -- Crooked Tree Candle (Area: Bradensbrook - Difficulty: 0) CreateObject1
(@OGUID+12, 251826, 1220, 7558, 7642, '0', 0, 0, 2907.647705078125, 7678.7666015625, 5.03698587417602539, 0, 0, 0, 0, 1, 120, 255, 1, 51754); -- Crooked Tree Candle (Area: Bradensbrook - Difficulty: 0) CreateObject1

-- Event spawns
DELETE FROM `game_event_creature` WHERE `eventEntry`=12 AND `guid` BETWEEN @CGUID+0 AND @CGUID+10;
INSERT INTO `game_event_creature` (`eventEntry`, `guid`) VALUES
(12, @CGUID+0),
(12, @CGUID+1),
(12, @CGUID+2),
(12, @CGUID+3),
(12, @CGUID+4),
(12, @CGUID+5),
(12, @CGUID+6),
(12, @CGUID+7),
(12, @CGUID+8),
(12, @CGUID+9),
(12, @CGUID+10);

DELETE FROM `game_event_gameobject` WHERE `eventEntry`=12 AND `guid` BETWEEN @OGUID+0 AND @OGUID+12;
INSERT INTO `game_event_gameobject` (`eventEntry`, `guid`) VALUES
(12, @OGUID+0),
(12, @OGUID+1),
(12, @OGUID+2),
(12, @OGUID+3),
(12, @OGUID+4),
(12, @OGUID+5),
(12, @OGUID+6),
(12, @OGUID+7),
(12, @OGUID+8),
(12, @OGUID+9),
(12, @OGUID+10),
(12, @OGUID+11),
(12, @OGUID+12);
