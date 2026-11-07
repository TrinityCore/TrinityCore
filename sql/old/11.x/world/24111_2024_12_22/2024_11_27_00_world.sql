SET @CGUID := 10004502;
SET @OGUID := 10001081;

SET @NPCTEXTID := 600041;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+48;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2657.177001953125, -2555.861083984375, 245.5923614501953125, 1.10812687873840332, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+1, 214772, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2656.03466796875, -2525.291748046875, 242.75018310546875, 2.979132413864135742, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Dornogal - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+2, 215070, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2654.953125, -2525.079833984375, 242.74993896484375, 2.778198957443237304, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Ashwhite Kestrel (Area: Dornogal - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+3, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2651.345458984375, -2545.02783203125, 240.7329559326171875, 0, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+4, 215070, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2697.16845703125, -2501.611083984375, 252.2240142822265625, 4.261437892913818359, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Ashwhite Kestrel (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+5, 215070, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2686.6025390625, -2559.5556640625, 243.3141021728515625, 4.663642406463623046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Ashwhite Kestrel (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+6, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2656.0166015625, -2540.553955078125, 244.3766021728515625, 2.652324199676513671, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+7, 215070, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2654.983642578125, -2527.032958984375, 242.749481201171875, 2.778198957443237304, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Ashwhite Kestrel (Area: Dornogal - Difficulty: 0) CreateObject2 (Auras: )
(@CGUID+8, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2685.606689453125, -2514.760498046875, 244.3982696533203125, 0, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+9, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2665.584228515625, -2559.510498046875, 245.87615966796875, 3.79269576072692871, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+10, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2656.178955078125, -2495.87841796875, 236.816680908203125, 3.9060516357421875, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject
(@CGUID+11, 214772, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2668.552001953125, -2546.704833984375, 274.354949951171875, 1.522764801979064941, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Dornogal - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+12, 214772, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2680.577392578125, -2618.84716796875, 288.353515625, 1.522764801979064941, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Dornogal - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+13, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2753.276123046875, -2590.678955078125, 223.764129638671875, 0.682878196239471435, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+14, 214772, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2783.21533203125, -2574.93408203125, 263.84320068359375, 5.657689094543457031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+15, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2782.545166015625, -2566.630126953125, 224.3134613037109375, 5.812337875366210937, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+16, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2802.919189453125, -2604.302001953125, 223.247100830078125, 3.943658828735351562, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+17, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2735.060791015625, -2618.34716796875, 221.659942626953125, 4.832509040832519531, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+18, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2808.93310546875, -2618.001708984375, 221.29156494140625, 1.662252068519592285, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+19, 214947, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2769.434814453125, -2618.529541015625, 224.9119720458984375, 4.916635513305664062, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+20, 215070, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2693.7744140625, -2675.507080078125, 314.39892578125, 1.131720900535583496, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Ashwhite Kestrel (Area: Dornogal - Difficulty: 0) CreateObject2
(@CGUID+21, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2878.380126953125, -2763.267333984375, 241.9640045166015625, 5.003903388977050781, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2
(@CGUID+22, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2854.52783203125, -2727.5556640625, 243.40496826171875, 0, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+23, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2889.8291015625, -2654.25341796875, 244.0969696044921875, 1.729729294776916503, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+24, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2874.81591796875, -2700.491455078125, 244.3238067626953125, 0, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+25, 214772, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2875.611083984375, -2733.140625, 297.451080322265625, 1.522764801979064941, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+26, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2895.87158203125, -2771.0625, 243.104217529296875, 1.051313757896423339, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2
(@CGUID+27, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2842.123291015625, -2773.017333984375, 248.36517333984375, 0.180822834372520446, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+28, 214772, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2875.642333984375, -2692.223876953125, 262.323822021484375, 5.271379947662353515, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2
(@CGUID+29, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2837.5859375, -2758.203125, 254.119659423828125, 0, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+30, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2824.059814453125, -2697.828125, 241.2568359375, 6.173586368560791015, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+31, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2885.38720703125, -2678.970458984375, 244.73480224609375, 2.761513710021972656, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2 (possible waypoints or random movement)
(@CGUID+32, 214772, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2825.118896484375, -2746.40966796875, 277.59246826171875, 5.811558723449707031, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Limestone Falcon (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2
(@CGUID+33, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2872.124267578125, -2760.40283203125, 242.953765869140625, 0, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2
(@CGUID+34, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2867.279541015625, -2739.991455078125, 242.518463134765625, 2.783788204193115234, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2
(@CGUID+35, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2940.704833984375, -2768.17529296875, 243.465301513671875, 5.60600137710571289, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2
(@CGUID+36, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2921.94091796875, -2770.029541015625, 243.65771484375, 1.986292481422424316, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2
(@CGUID+37, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2954.39501953125, -2781.3681640625, 247.79779052734375, 0, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2
(@CGUID+38, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2933.583251953125, -2696.463623046875, 243.6787872314453125, 2.019199848175048828, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2
(@CGUID+39, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2972.84716796875, -2773.064208984375, 246.454986572265625, 5.263034820556640625, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2
(@CGUID+40, 214947, 2552, 14771, 15184, '0', 0, 0, 0, 0, 2924.13623046875, -2659.420166015625, 243.183624267578125, 4.686742305755615234, 120, 2, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Eye of Topaz (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject2
(@CGUID+41, 226592, 2552, 14771, 15184, '0', 0, 0, 0, 1, 2847.21484375, -2801.283203125, 244.29193115234375, 0.900342285633087158, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Jaxi Sparkshine (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@CGUID+42, 226591, 2552, 14771, 15184, '0', 0, 0, 0, 1, 2849.25830078125, -2801.3193359375, 244.313232421875, 2.389741182327270507, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Windle Sparkshine (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@CGUID+43, 197711, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2753.786376953125, -2665.819580078125, 225.6900482177734375, 1.419044017791748046, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Lindormi (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+44, 222561, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2765.115478515625, -2667.76904296875, 225.6900482177734375, 1.642943978309631347, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Agmera (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+45, 233492, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2765.837646484375, -2640.401123046875, 224.0833282470703125, 1.540279626846313476, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Temporal Guardian (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+46, 214113, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2753.323974609375, -2658.20361328125, 225.764617919921875, 6.0282745361328125, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689), -- Time Fragment (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+47, 233492, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2750.868896484375, -2640.401123046875, 224.0833282470703125, 1.525917291641235351, 120, 0, 0, 0, NULL, NULL, NULL, NULL, 57689), -- Temporal Guardian (Area: Dornogal - Difficulty: 0) CreateObject1
(@CGUID+48, 214113, 2552, 14771, 14771, '0', 0, 0, 0, 0, 2770.06103515625, -2657.022705078125, 225.7646026611328125, 5.912850379943847656, 120, 4, 0, 1, NULL, NULL, NULL, NULL, 57689); -- Time Fragment (Area: Dornogal - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+48;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Limestone Falcon
(@CGUID+2, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Ashwhite Kestrel
(@CGUID+4, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Ashwhite Kestrel
(@CGUID+5, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Ashwhite Kestrel
(@CGUID+7, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Ashwhite Kestrel
(@CGUID+20, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 4, ''), -- Ashwhite Kestrel
(@CGUID+28, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- Limestone Falcon
(@CGUID+32, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- Limestone Falcon

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+32;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 446178, 2552, 14771, 15184, '0', 0, 0, 2968.096435546875, -2685.447509765625, 243.9940185546875, 0.767941832542419433, 0, 0, 0.374605178833007812, 0.927184462547302246, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+1, 452662, 2552, 14771, 15184, '0', 0, 0, 2844.52197265625, -2658.227783203125, 221.031341552734375, 1.230455756187438964, 0, 0, 0.577144622802734375, 0.816641986370086669, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+2, 428884, 2552, 14771, 15184, '0', 0, 0, 2944.248291015625, -2839.1181640625, 257.253387451171875, 4.712389945983886718, 0, 0, -0.70710659027099609, 0.707106947898864746, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+3, 446179, 2552, 14771, 15184, '0', 0, 0, 2968.3359375, -2682.6015625, 243.9940185546875, 5.485874176025390625, 0, 0, -0.38817977905273437, 0.92158365249633789, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+4, 452663, 2552, 14771, 15184, '0', 0, 0, 2843.744384765625, -2655.530517578125, 221.031341552734375, 5.820673465728759765, 0, 0, -0.22920036315917968, 0.973379254341125488, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+5, 428885, 2552, 14771, 15184, '0', 0, 0, 2952.905517578125, -2847.296875, 257.22735595703125, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+6, 441774, 2552, 14771, 15184, '0', 0, 0, 2865.0634765625, -2930.045166015625, 256.266387939453125, 5.576329231262207031, 0, 0, -0.3461160659790039, 0.938191711902618408, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+7, 433327, 2552, 14771, 15184, '0', 0, 0, 2982.59033203125, -2712.5087890625, 257.25836181640625, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+8, 428886, 2552, 14771, 15184, '0', 0, 0, 2935.856689453125, -2846.91845703125, 257.253326416015625, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+9, 441775, 2552, 14771, 15184, '0', 0, 0, 2948.0390625, -2913.661376953125, 322.424530029296875, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 57689), -- Stool (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+10, 428956, 2552, 14771, 15184, '0', 0, 0, 2976.62939453125, -2725.645751953125, 243.6996612548828125, 3.141592741012573242, 0, 0, -1, 0, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+11, 428957, 2552, 14771, 15184, '0', 0, 0, 2871.01123046875, -2770.772705078125, 243.5388946533203125, 3.935721635818481445, 0, 0, -0.92220020294189453, 0.386712819337844848, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+12, 452668, 2552, 14771, 15184, '0', 0, 0, 2848.235107421875, -2662.385498046875, 221.04364013671875, 0.663225173950195312, 0, 0, 0.325568199157714843, 0.945518553256988525, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+13, 428882, 2552, 14771, 15184, '0', 0, 0, 2944.428955078125, -2855.666748046875, 257.2384033203125, 1.570795774459838867, 0, 0, 0.707106590270996093, 0.707106947898864746, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+14, 429063, 2552, 14771, 15184, '0', 0, 0, 2983.4541015625, -2763.2119140625, 257.37469482421875, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+15, 452669, 2552, 14771, 15184, '0', 0, 0, 2858.3271484375, -2644.560546875, 221.011962890625, 5.480334281921386718, 0, 0, -0.39073085784912109, 0.920504987239837646, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+16, 428989, 2552, 14771, 15184, '0', 0, 0, 2845.372314453125, -2754.467041015625, 243.5467987060546875, 1.588248729705810546, 0, 0, 0.713250160217285156, 0.700909554958343505, 120, 255, 1, 57689), -- Mailbox (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+17, 428959, 2552, 14771, 15184, '0', 0, 0, 2925.615478515625, -2798.1025390625, 243.55841064453125, 1.579522013664245605, 0, 0, 0.710185050964355468, 0.704015016555786132, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+18, 433328, 2552, 14771, 15184, '0', 0, 0, 2983.487060546875, -2772.84375, 257.3936767578125, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+19, 441776, 2552, 14771, 15184, '0', 0, 0, 2864.69970703125, -2979.598876953125, 256.266387939453125, 0.689404308795928955, 0, 0, 0.337916374206542968, 0.941176116466522216, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+20, 452664, 2552, 14771, 15184, '0', 0, 0, 2862.185791015625, -2648.5078125, 220.9737396240234375, 2.391098499298095703, 0, 0, 0.930417060852050781, 0.366502493619918823, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+21, 452665, 2552, 14771, 15184, '0', 0, 0, 2861.735595703125, -2645.344970703125, 221.124603271484375, 3.988081216812133789, 0, 0, -0.91176128387451171, 0.410720497369766235, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+22, 452666, 2552, 14771, 15184, '0', 0, 0, 2859.13916015625, -2647.913818359375, 221.152801513671875, 0.759216904640197753, 0, 0, 0.370556831359863281, 0.928809821605682373, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+23, 452667, 2552, 14771, 15184, '0', 0, 0, 2851.784423828125, -2662.457275390625, 221.0487060546875, 2.356194972991943359, 0, 0, 0.923879623413085937, 0.382683247327804565, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+24, 428964, 2552, 14771, 15184, '0', 0, 0, 2936.88720703125, -2798.10595703125, 243.55841064453125, 1.579522013664245605, 0, 0, 0.710185050964355468, 0.704015016555786132, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+25, 446180, 2552, 14771, 15184, '0', 0, 0, 2838.9619140625, -2797.358154296875, 243.7215423583984375, 2.36173105239868164, 0, 0, 0.924935340881347656, 0.380124449729919433, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+26, 429064, 2552, 14771, 15184, '0', 0, 0, 2982.756103515625, -2722.520751953125, 257.234283447265625, 0, 0, 0, 0, 1, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+27, 446181, 2552, 14771, 15184, '0', 0, 0, 2835.946044921875, -2797.25390625, 243.7336578369140625, 0.802728593349456787, 0, 0, 0.390674591064453125, 0.920528829097747802, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+28, 428966, 2552, 14771, 15184, '0', 0, 0, 2944.41748046875, -2772.286376953125, 243.7103118896484375, 5.497788906097412109, 0, 0, -0.38268280029296875, 0.923879802227020263, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+29, 446182, 2552, 14771, 15184, '0', 0, 0, 2849.25830078125, -2801.3193359375, 244.313232421875, 2.389741182327270507, 0, 0, 0.93016815185546875, 0.367133766412734985, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+30, 446183, 2552, 14771, 15184, '0', 0, 0, 2847.21484375, -2801.283203125, 244.29193115234375, 0.900342285633087158, 0, 0, 0.43511962890625, 0.900372624397277832, 120, 255, 1, 57689), -- Chair (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+31, 428960, 2552, 14771, 15184, '0', 0, 0, 2864.454833984375, -2754.609375, 243.5377044677734375, 3.150327444076538085, 0, 0, -0.99999046325683593, 0.004367320332676172, 120, 255, 1, 57689), -- Bench (Area: Stoneshaper's Atrium - Difficulty: 0) CreateObject1
(@OGUID+32, 414149, 2552, 14771, 14771, '0', 0, 0, 2757.8994140625, -2666.7900390625, 225.606719970703125, 5.811313152313232421, 0, 0, -0.23375320434570312, 0.972295999526977539, 120, 255, 1, 57689); -- Portal to The Timeways (Area: Dornogal - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+32;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, 0.374605774879455566, 0.927184164524078369, 0, 0), -- Chair
(@OGUID+1, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+3, 0, 0, 0.374605774879455566, 0.927184164524078369, 0, 0), -- Chair
(@OGUID+4, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+12, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+15, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+20, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+21, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+22, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+23, 0, 0, -0.38268330693244934, 0.923879623413085937, 0, 0), -- Chair
(@OGUID+25, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+27, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+29, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+30, 0, 0, 0.923879504203796386, -0.38268348574638366, 0, 0), -- Chair
(@OGUID+32, 0, 0, 0, 1, 0, 21240); -- Portal to The Timeways

-- Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (226591 /*226591 (Windle Sparkshine)*/, 226592 /*226592 (Jaxi Sparkshine)*/);
INSERT INTO `creature_template_addon` (`entry`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(226591, 0, 0, 4, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''), -- 226591 (Windle Sparkshine)
(226592, 0, 0, 4, 0, 0, 1, 0, 0, 0, 0, 0, 0, ''); -- 226592 (Jaxi Sparkshine)

DELETE FROM `gameobject_template_addon` WHERE `entry` IN (447139 /*Chair*/, 447142 /*Chair*/, 447141 /*Chair*/, 447140 /*Chair*/, 446182 /*Chair*/, 414149 /*Portal to The Timeways*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(447139, 114, 0x0, 0, 0), -- Chair
(447142, 114, 0x0, 0, 0), -- Chair
(447141, 114, 0x0, 0, 0), -- Chair
(447140, 114, 0x0, 0, 0), -- Chair
(446182, 114, 0x0, 0, 0), -- Chair
(414149, 0, 0x0, 0, 21240); -- Portal to The Timeways

-- Template
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=226592; -- Jaxi Sparkshine
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=226591; -- Windle Sparkshine
UPDATE `creature_template` SET `faction`=35, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=233492; -- Temporal Guardian
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=214113; -- Time Fragment
UPDATE `creature_template` SET `faction`=35, `npcflag`=1, `BaseAttackTime`=2000, `unit_flags`=0x100, `unit_flags2`=0x800 WHERE `entry`=197711; -- Lindormi
UPDATE `creature_template` SET `faction`=3407, `npcflag`=128, `BaseAttackTime`=2000, `unit_flags`=0x300, `unit_flags2`=0x800 WHERE `entry`=222561; -- Agmera

DELETE FROM `gameobject_template` WHERE `entry` IN (449737 /*Crate*/, 449726 /*Mailbox*/, 449513 /*Post*/, 449510 /*Balloons*/, 449821 /*Water Trough*/, 449453 /*Crate*/, 446547 /*Mailbox*/, 414149 /*Portal to The Timeways*/);
INSERT INTO `gameobject_template` (`entry`, `type`, `displayId`, `name`, `IconName`, `castBarCaption`, `unk1`, `size`, `Data0`, `Data1`, `Data2`, `Data3`, `Data4`, `Data5`, `Data6`, `Data7`, `Data8`, `Data9`, `Data10`, `Data11`, `Data12`, `Data13`, `Data14`, `Data15`, `Data16`, `Data17`, `Data18`, `Data19`, `Data20`, `Data21`, `Data22`, `Data23`, `Data24`, `Data25`, `Data26`, `Data27`, `Data28`, `Data29`, `Data30`, `Data31`, `Data32`, `Data33`, `Data34`, `ContentTuningId`, `VerifiedBuild`) VALUES
(449737, 5, 1988, 'Crate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Crate
(449726, 19, 2128, 'Mailbox', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Mailbox
(449513, 5, 92031, 'Post', '', '', '', 0.25, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Post
(449510, 5, 96625, 'Balloons', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Balloons
(449821, 5, 10167, 'Water Trough', '', '', '', 0.75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Water Trough
(449453, 5, 31, 'Crate', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Crate
(446547, 19, 1907, 'Mailbox', '', '', '', 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 57689), -- Mailbox
(414149, 22, 76125, 'Portal to The Timeways', '', '', '', 1, 429322, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2145, 57689); -- Portal to The Timeways

-- Gossip
DELETE FROM `creature_template_gossip` WHERE (`CreatureID`=197711 AND `MenuID`=29898);
INSERT INTO `creature_template_gossip` (`CreatureID`, `MenuID`, `VerifiedBuild`) VALUES
(197711, 29898, 57689); -- Lindormi

DELETE FROM `npc_text` WHERE `ID` BETWEEN @NPCTEXTID+0 AND @NPCTEXTID+3;
INSERT INTO `npc_text` (`ID`, `Probability0`, `Probability1`, `Probability2`, `Probability3`, `Probability4`, `Probability5`, `Probability6`, `Probability7`, `BroadcastTextId0`, `BroadcastTextId1`, `BroadcastTextId2`, `BroadcastTextId3`, `BroadcastTextId4`, `BroadcastTextId5`, `BroadcastTextId6`, `BroadcastTextId7`, `VerifiedBuild`) VALUES
(@NPCTEXTID+0, 1, 0, 0, 0, 0, 0, 0, 0, 231632, 0, 0, 0, 0, 0, 0, 0, 57689), -- 197711 (Lindormi)
(@NPCTEXTID+1, 1, 0, 0, 0, 0, 0, 0, 0, 275555, 0, 0, 0, 0, 0, 0, 0, 57689), -- 197711 (Lindormi)
(@NPCTEXTID+2, 1, 0, 0, 0, 0, 0, 0, 0, 275556, 0, 0, 0, 0, 0, 0, 0, 57689), -- 197711 (Lindormi)
(@NPCTEXTID+3, 1, 0, 0, 0, 0, 0, 0, 0, 275557, 0, 0, 0, 0, 0, 0, 0, 57689); -- 197711 (Lindormi)

DELETE FROM `gossip_menu` WHERE (`MenuID`=29898 AND `TextID`=@NPCTEXTID+0) OR (`MenuID`=36956 AND `TextID`=@NPCTEXTID+1) OR (`MenuID`=36957 AND `TextID`=@NPCTEXTID+2) OR (`MenuID`=36958 AND `TextID`=@NPCTEXTID+3);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(29898, @NPCTEXTID+0, 57689), -- 197711 (Lindormi)
(36956, @NPCTEXTID+1, 57689), -- 197711 (Lindormi)
(36957, @NPCTEXTID+2, 57689), -- 197711 (Lindormi)
(36958, @NPCTEXTID+3, 57689); -- 197711 (Lindormi)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=29898 AND `OptionID` IN (19,21,20,1,22));
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(29898, 125052, 19, 0, 'Where can I find Mists of Tirna Scithe?', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(29898, 125050, 21, 0, 'Where can I find Siege of Boralus?', 0, 0, 0, 36957, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(29898, 125051, 20, 0, 'Where can I find The Necrotic Wake?', 0, 0, 0, 36956, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(29898, 125048, 1, 0, 'I seem to have misplaced my Keystone.', 0, 0, 0, 0, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689),
(29898, 125049, 22, 0, 'Where can I find Grim Batol?', 0, 0, 0, 36958, 0, NULL, 0, 0, NULL, 0, NULL, NULL, 57689);

-- Difficulty
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x30000000, `VerifiedBuild`=57689 WHERE (`Entry`=214772 AND `DifficultyID`=0); -- 214772 (Limestone Falcon) - CanSwim, Floating
UPDATE `creature_template_difficulty` SET `ContentTuningID`=356, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=226591 AND `DifficultyID`=0); -- 226591 (Windle Sparkshine) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2797, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=226592 AND `DifficultyID`=0); -- 226592 (Jaxi Sparkshine) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2145, `VerifiedBuild`=57689 WHERE (`Entry`=214113 AND `DifficultyID`=0); -- 214113 (Time Fragment) - 
UPDATE `creature_template_difficulty` SET `LevelScalingDeltaMin`=1, `LevelScalingDeltaMax`=1, `ContentTuningID`=1279, `VerifiedBuild`=57689 WHERE (`Entry`=233492 AND `DifficultyID`=0); -- 233492 (Temporal Guardian) - 
UPDATE `creature_template_difficulty` SET `ContentTuningID`=1279, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=197711 AND `DifficultyID`=0); -- 197711 (Lindormi) - CanSwim
UPDATE `creature_template_difficulty` SET `ContentTuningID`=2892, `StaticFlags1`=0x10000000, `VerifiedBuild`=57689 WHERE (`Entry`=222561 AND `DifficultyID`=0); -- 222561 (Agmera) - CanSwim

-- Model
DELETE FROM `creature_model_info` WHERE `DisplayID` IN (121319, 113259, 123225, 112143, 121139, 121140);
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(121319, 0.5, 0, 0, 57689),
(113259, 0.297494709491729736, 0, 0, 57689),
(123225, 0.347000002861022949, 1.5, 0, 57689),
(112143, 0.368032127618789672, 0.660000026226043701, 0, 57689),
(121139, 0.366928756237030029, 0, 0, 57689),
(121140, 0.403084099292755126, 0, 0, 57689);

-- Path for Limestone Falcon
SET @MOVERGUID := @CGUID+14;
SET @ENTRY := 214772;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5455, 'Limestone Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2792.7046, -2581.7876, 266.8432, NULL, 0),
(@PATH, 1, 2798.8486, -2591.751, 266.8432, NULL, 0),
(@PATH, 2, 2800.7122, -2603.3071, 266.8432, NULL, 0),
(@PATH, 3, 2798.0117, -2614.6968, 266.8432, NULL, 0),
(@PATH, 4, 2791.158, -2624.186, 266.8432, NULL, 0),
(@PATH, 5, 2781.1948, -2630.33, 266.8432, NULL, 0),
(@PATH, 6, 2769.6387, -2632.1936, 266.8432, NULL, 0),
(@PATH, 7, 2758.249, -2629.4932, 266.8432, NULL, 0),
(@PATH, 8, 2748.7598, -2622.6394, 266.8432, NULL, 0),
(@PATH, 9, 2742.6157, -2612.6763, 266.8432, NULL, 0),
(@PATH, 10, 2740.7522, -2601.12, 266.8432, NULL, 0),
(@PATH, 11, 2743.4526, -2589.7305, 266.8432, NULL, 0),
(@PATH, 12, 2750.3064, -2580.2412, 266.8432, NULL, 0),
(@PATH, 13, 2760.2695, -2574.0972, 266.8432, NULL, 0),
(@PATH, 14, 2771.8257, -2572.2334, 266.8432, NULL, 0),
(@PATH, 15, 2783.2153, -2574.934, 266.8432, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Limestone Falcon
SET @MOVERGUID := @CGUID+12;
SET @ENTRY := 214772;
SET @PATHOFFSET := 1;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5454, 'Limestone Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2681.1394, -2607.1553, 291.35352, NULL, 0),
(@PATH, 1, 2677.1843, -2596.1382, 291.35352, NULL, 0),
(@PATH, 2, 2669.3142, -2587.4734, 291.35352, NULL, 0),
(@PATH, 3, 2658.7273, -2582.48, 291.35352, NULL, 0),
(@PATH, 4, 2647.0354, -2581.918, 291.35352, NULL, 0),
(@PATH, 5, 2636.0186, -2585.873, 291.35352, NULL, 0),
(@PATH, 6, 2627.3538, -2593.743, 291.35352, NULL, 0),
(@PATH, 7, 2622.36, -2604.3298, 291.35352, NULL, 0),
(@PATH, 8, 2621.798, -2616.0217, 291.35352, NULL, 0),
(@PATH, 9, 2625.7532, -2627.0388, 291.35352, NULL, 0),
(@PATH, 10, 2633.6233, -2635.7036, 291.35352, NULL, 0),
(@PATH, 11, 2644.2102, -2640.6973, 291.35352, NULL, 0),
(@PATH, 12, 2655.902, -2641.259, 291.35352, NULL, 0),
(@PATH, 13, 2666.919, -2637.304, 291.35352, NULL, 0),
(@PATH, 14, 2675.584, -2629.434, 291.35352, NULL, 0),
(@PATH, 15, 2680.5774, -2618.8472, 291.35352, NULL, 0),
(@PATH, 16, 2681.1394, -2607.1553, 291.35352, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Limestone Falcon
SET @MOVERGUID := @CGUID+11;
SET @ENTRY := 214772;
SET @PATHOFFSET := 2;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5454, 'Limestone Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2669.114, -2535.013, 277.35495, NULL, 0),
(@PATH, 1, 2665.159, -2523.9958, 277.35495, NULL, 0),
(@PATH, 2, 2657.2888, -2515.331, 277.35495, NULL, 0),
(@PATH, 3, 2646.702, -2510.3376, 277.35495, NULL, 0),
(@PATH, 4, 2635.01, -2509.7756, 277.35495, NULL, 0),
(@PATH, 5, 2623.9932, -2513.7307, 277.35495, NULL, 0),
(@PATH, 6, 2615.3284, -2521.6006, 277.35495, NULL, 0),
(@PATH, 7, 2610.3347, -2532.1875, 277.35495, NULL, 0),
(@PATH, 8, 2609.7727, -2543.8794, 277.35495, NULL, 0),
(@PATH, 9, 2613.7278, -2554.8965, 277.35495, NULL, 0),
(@PATH, 10, 2621.598, -2563.5613, 277.35495, NULL, 0),
(@PATH, 11, 2632.1848, -2568.555, 277.35495, NULL, 0),
(@PATH, 12, 2643.8767, -2569.1167, 277.35495, NULL, 0),
(@PATH, 13, 2654.8936, -2565.1616, 277.35495, NULL, 0),
(@PATH, 14, 2663.5586, -2557.2917, 277.35495, NULL, 0),
(@PATH, 15, 2668.552, -2546.7048, 277.35495, NULL, 0),
(@PATH, 16, 2669.114, -2535.013, 277.35495, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);

-- Path for Limestone Falcon
SET @MOVERGUID := @CGUID+25;
SET @ENTRY := 214772;
SET @PATHOFFSET := 3;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 0, 0x2, 8.5454, 'Limestone Falcon - Cyclic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 2876.173, -2721.4487, 300.45108, NULL, 0),
(@PATH, 1, 2872.218, -2710.4316, 300.45108, NULL, 0),
(@PATH, 2, 2864.348, -2701.7668, 300.45108, NULL, 0),
(@PATH, 3, 2853.761, -2696.7734, 300.45108, NULL, 0),
(@PATH, 4, 2842.069, -2696.2114, 300.45108, NULL, 0),
(@PATH, 5, 2831.0522, -2700.1665, 300.45108, NULL, 0),
(@PATH, 6, 2822.3875, -2708.0364, 300.45108, NULL, 0),
(@PATH, 7, 2817.3938, -2718.6233, 300.45108, NULL, 0),
(@PATH, 8, 2816.8318, -2730.3152, 300.45108, NULL, 0),
(@PATH, 9, 2820.7869, -2741.3323, 300.45108, NULL, 0),
(@PATH, 10, 2828.657, -2749.997, 300.45108, NULL, 0),
(@PATH, 11, 2839.244, -2754.9907, 300.45108, NULL, 0),
(@PATH, 12, 2850.9358, -2755.5525, 300.45108, NULL, 0),
(@PATH, 13, 2861.9526, -2751.5974, 300.45108, NULL, 0),
(@PATH, 14, 2870.6177, -2743.7275, 300.45108, NULL, 0),
(@PATH, 15, 2875.611, -2733.1406, 300.45108, NULL, 0),
(@PATH, 16, 2876.173, -2721.4487, 300.45108, NULL, 0);

UPDATE `creature` SET `wander_distance`=0, `MovementType`=2 WHERE `guid`=@MOVERGUID;
DELETE FROM `creature_addon` WHERE `guid`=@MOVERGUID;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@MOVERGUID, @PATH, 1);
