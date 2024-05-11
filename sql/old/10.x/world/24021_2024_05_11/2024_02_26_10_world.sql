SET @CGUID := 9004108;
SET @OGUID := 9003868;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+48;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `VerifiedBuild`) VALUES
(@CGUID+0, 185272, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5902.6318359375, -3004.85595703125, 200.7157135009765625, 0.052480250597000122, 120, 0, 0, 16605, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Ancient Construct (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+1, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5750.1025390625, -3040.934814453125, 211.25299072265625, 3.843105316162109375, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+2, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5873.82080078125, -2966.31103515625, 207.3056488037109375, 2.744068384170532226, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+3, 185272, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5925.92431640625, -3046.973876953125, 200.7157135009765625, 0.943276762962341308, 120, 0, 0, 16605, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Ancient Construct (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+4, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5801.91943359375, -3040.503173828125, 210.5941162109375, 2.874973773956298828, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+5, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5793.21484375, -2919.36279296875, 207.296051025390625, 1.048147439956665039, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+6, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5933.38427734375, -3015.03369140625, 200.0926666259765625, 2.594782590866088867, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+7, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5797.5205078125, -2922.2548828125, 207.5377197265625, 1.500182867050170898, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+8, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5847.798828125, -2981.6796875, 207.8623504638671875, 5.329618453979492187, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+9, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5916.8271484375, -3039.683837890625, 201.4382171630859375, 0.267679601907730102, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+10, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5788.724609375, -3028.44482421875, 211.23529052734375, 0.350099146366119384, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+11, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5807.978515625, -3083.946533203125, 212.1324920654296875, 2.161147832870483398, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+12, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5854.6787109375, -2982.9765625, 207.263092041015625, 1.614386200904846191, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+13, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5930.3349609375, -3011.33251953125, 200.3862152099609375, 0.44295552372932434, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+14, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5792.3642578125, -2915.578125, 209.25634765625, 4.705502510070800781, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+15, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5758.41455078125, -3073.49853515625, 211.4390716552734375, 3.057764768600463867, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+16, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5769.76171875, -2986.830322265625, 210.831817626953125, 4.121662139892578125, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+17, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5800.421875, -2923.7587890625, 207.30914306640625, 1.26346755027770996, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+18, 185272, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5842.42431640625, -2936.533203125, 205.2529754638671875, 0.328986376523971557, 120, 0, 0, 16605, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Ancient Construct (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+19, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5925.619140625, -3053.7421875, 201.4376983642578125, 4.55332040786743164, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+20, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5866.43212890625, -2982.71435546875, 207.2529754638671875, 1.250236749649047851, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+21, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5796.4892578125, -3031.515625, 210.7431793212890625, 1.033916473388671875, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+22, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5755.10302734375, -3026.30908203125, 210.670379638671875, 2.215724468231201171, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+23, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5772.13037109375, -3088.53466796875, 211.7568817138671875, 2.049893617630004882, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+24, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5804.22265625, -2896.564453125, 207.3623809814453125, 0.914744794368743896, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+25, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5820.77099609375, -2903.092041015625, 207.5016937255859375, 0.561812758445739746, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+26, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5731.298828125, -2991.292236328125, 213.4561004638671875, 5.460728645324707031, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+27, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5771.7041015625, -3033.330810546875, 212.0654754638671875, 5.139191627502441406, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+28, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5721.7109375, -2997.479736328125, 211.5408172607421875, 5.605190277099609375, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+29, 185272, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5962.3115234375, -2993.604248046875, 199.6699981689453125, 2.362212181091308593, 120, 0, 0, 16605, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Ancient Construct (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+30, 186853, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5955.62158203125, -3026.51220703125, 199.9217681884765625, 2.635974407196044921, 120, 0, 0, 16605, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Conjured Guardian (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+31, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5875.59326171875, -2898.97509765625, 207.252960205078125, 1.192506313323974609, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+32, 185272, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5889.2421875, -2904.270751953125, 207.186798095703125, 4.339447975158691406, 120, 0, 0, 16605, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Ancient Construct (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+33, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5944.345703125, -2938.5322265625, 201.7408599853515625, 0.729677259922027587, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+34, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5947.056640625, -2936.95556640625, 201.265411376953125, 5.587829113006591796, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+35, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5906.494140625, -2911.286376953125, 207.9876556396484375, 4.712388992309570312, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+36, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5923.650390625, -2980.5546875, 200.168609619140625, 5.308788299560546875, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+37, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5956.8046875, -2934.424072265625, 201.495452880859375, 0.178137376904487609, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+38, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5959.84033203125, -2938.955810546875, 201.57171630859375, 3.102656364440917968, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+39, 185272, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5951.87353515625, -2928.4375, 200.7156982421875, 4.687173366546630859, 120, 0, 0, 16605, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Ancient Construct (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+40, 186853, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5978.99755859375, -3020.447998046875, 198.8108978271484375, 2.635974407196044921, 120, 0, 0, 16605, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Conjured Guardian (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+41, 186853, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5982.36474609375, -2965.288330078125, 199.8657073974609375, 0.857039332389831542, 120, 0, 0, 16605, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Conjured Guardian (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+42, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5994.9853515625, -3086.94091796875, 200.2669677734375, 2.445415019989013671, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+43, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 6005.4462890625, -3036.3359375, 200.674591064453125, 1.781545877456665039, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+44, 186853, 2570, 13769, 13806, '0', 0, 0, 0, 0, 6014.35693359375, -3030.154541015625, 204.2588958740234375, 2.635974407196044921, 120, 0, 0, 16605, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Conjured Guardian (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+45, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 6012.884765625, -3021.2109375, 200.96478271484375, 3.140908002853393554, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+46, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 6022.76708984375, -3032.10546875, 200.9654083251953125, 1.208475589752197265, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262), -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1 (possible waypoints or random movement)
(@CGUID+47, 185272, 2570, 13769, 13806, '0', 0, 0, 0, 0, 6024.54150390625, -2982.920166015625, 200.7157135009765625, 3.360021352767944335, 120, 0, 0, 16605, 0, 0, NULL, NULL, NULL, NULL, 53262), -- Ancient Construct (Area: The War Creche - Difficulty: 0) CreateObject1
(@CGUID+48, 187163, 2570, 13769, 13806, '0', 0, 0, 0, 0, 5916.6689453125, -2796.9404296875, 71.5298919677734375, 4.734846115112304687, 120, 4, 0, 5, 0, 1, NULL, NULL, NULL, NULL, 53262); -- Dark Widow (Area: The War Creche - Difficulty: 0) CreateObject1
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+48;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+0, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Ancient Construct
(@CGUID+3, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Ancient Construct
(@CGUID+29, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Ancient Construct
(@CGUID+30, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Conjured Guardian
(@CGUID+32, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Ancient Construct
(@CGUID+39, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''), -- Ancient Construct
(@CGUID+40, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Conjured Guardian
(@CGUID+41, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Conjured Guardian
(@CGUID+44, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Conjured Guardian
(@CGUID+47, 0, 0, 0, 0, 0, 1, 0, 27, 0, 0, 0, 0, ''); -- Ancient Construct

-- GameObject
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+34;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`, `VerifiedBuild`) VALUES
(@OGUID+0, 377597, 2570, 13769, 13806, '0', 0, 0, 5794.10498046875, -3093.44287109375, 263.763824462890625, 2.167680978775024414, 0, 0, 0.883761405944824218, 0.467937797307968139, 120, 255, 1, 53262), -- Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+1, 377602, 2570, 13769, 13806, '0', 0, 0, 5712.94287109375, -3023.697509765625, 263.107757568359375, 6.225575447082519531, 0, 0, -0.02880096435546875, 0.999585151672363281, 120, 255, 1, 53262), -- Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+2, 377592, 2570, 13769, 13806, '0', 0, 0, 5814.96630859375, -3086.807373046875, 211.436279296875, 6.03359079360961914, 0, 0, -0.12447357177734375, 0.992222905158996582, 120, 255, 1, 53262), -- Lingering Everflame (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+3, 377595, 2570, 13769, 13806, '0', 0, 0, 5779.7666015625, -3093.101318359375, 263.763824462890625, 0.902321338653564453, 0, 0, 0.436010360717773437, 0.899941682815551757, 120, 255, 1, 53262), -- Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+4, 377591, 2570, 13769, 13806, '0', 0, 0, 5797.75927734375, -2897.719482421875, 207.07818603515625, 6.03359079360961914, 0, 0, -0.12447357177734375, 0.992222905158996582, 120, 255, 1, 53262), -- Lingering Everflame (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+5, 377600, 2570, 13769, 13806, '0', 0, 0, 5734.8740234375, -3075.489990234375, 263.107757568359375, 0.736512541770935058, 0, 0, 0.359989166259765625, 0.932956516742706298, 120, 255, 1, 53262), -- Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+6, 376276, 2570, 13769, 13806, '0', 0, 0, 5837.6103515625, -2947.94970703125, 205.095458984375, 5.176036834716796875, 0.625855445861816406, 0.329096794128417968, -0.6258554458618164, 0.329097568988800048, 120, 255, 1, 53262), -- Rune of Guardians (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+7, 378712, 2570, 13769, 13806, '0', 0, 0, 5849.30908203125, -2985.170166015625, 209.110260009765625, 1.092055439949035644, 0, 0, 0.519296646118164062, 0.854594051837921142, 120, 255, 1, 53262), -- Edict: The Earth-Warder (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+8, 376276, 2570, 13769, 13806, '0', 0, 0, 5867.7734375, -2922.677001953125, 205.095458984375, 5.176036834716796875, 0.625855445861816406, 0.329096794128417968, -0.6258554458618164, 0.329097568988800048, 120, 255, 1, 53262), -- Rune of Guardians (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+9, 375420, 2570, 13769, 13806, '0', 0, 0, 5819.92626953125, -3077.282958984375, 213.3481292724609375, 5.467829704284667968, 0, 0, -0.39647865295410156, 0.918043911457061767, 120, 255, 1, 53262), -- Debris (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+10, 381425, 2570, 13769, 13806, '0', 0, 0, 5745.3115234375, -3055.223876953125, 251.0892791748046875, 4.348520755767822265, 0, 0, -0.82337474822998046, 0.56749802827835083, 120, 255, 1, 53262), -- Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+11, 381423, 2570, 13769, 13806, '0', 0, 0, 5736.9755859375, -3034.963623046875, 252.4689483642578125, 2.337939739227294921, 0, 0, 0.920348167419433593, 0.391100019216537475, 120, 255, 1, 53262), -- Edict: Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+12, 375503, 2570, 13769, 13806, '0', 0, 0, 5795.330078125, -2892.260498046875, 215.4988861083984375, 5.240739822387695312, 0, 0, -0.4979410171508789, 0.867210924625396728, 120, 255, 1, 53262), -- Edict: Obsidian Warders (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+13, 376276, 2570, 13769, 13806, '0', 0, 0, 5817.291015625, -3022.241455078125, 210.4369659423828125, 5.176036834716796875, 0.625855445861816406, 0.329096794128417968, -0.6258554458618164, 0.329097568988800048, 120, 255, 1, 53262), -- Rune of Guardians (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+14, 381425, 2570, 13769, 13806, '0', 0, 0, 5735.02685546875, -3016.630126953125, 251.090057373046875, 3.691178083419799804, 0, 0, -0.96248149871826171, 0.271347343921661376, 120, 255, 1, 53262), -- Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+15, 375501, 2570, 13769, 13806, '0', 0, 0, 5870.2021484375, -2983.376708984375, 209.519195556640625, 2.32742166519165039, 0, 0, 0.918278694152832031, 0.395934671163558959, 120, 255, 1, 53262), -- Edict: Weyrns (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+16, 376276, 2570, 13769, 13806, '0', 0, 0, 5762.50537109375, -2995.814208984375, 210.7897186279296875, 5.176036834716796875, 0.625855445861816406, 0.329096794128417968, -0.6258554458618164, 0.329097568988800048, 120, 255, 1, 53262), -- Rune of Guardians (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+17, 376276, 2570, 13769, 13806, '0', 0, 0, 5762.56005859375, -3047.67529296875, 210.5292510986328125, 5.176036834716796875, 0.625855445861816406, 0.329096794128417968, -0.6258554458618164, 0.329097568988800048, 120, 255, 1, 53262), -- Rune of Guardians (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+18, 381425, 2570, 13769, 13806, '0', 0, 0, 5780.0615234375, -3075.114501953125, 251.089141845703125, 5.120627403259277343, 0, 0, -0.54909324645996093, 0.835761070251464843, 120, 255, 1, 53262), -- Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+19, 381423, 2570, 13769, 13806, '0', 0, 0, 5798.43505859375, -3073.194580078125, 252.5824432373046875, 4.005276203155517578, 0, 0, -0.90819644927978515, 0.418544113636016845, 120, 255, 1, 53262), -- Edict: Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+20, 381425, 2570, 13769, 13806, '0', 0, 0, 5818.900390625, -3063.569580078125, 251.0961151123046875, 5.94611215591430664, 0, 0, -0.1677398681640625, 0.985831260681152343, 120, 255, 1, 53262), -- Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+21, 381423, 2570, 13769, 13806, '0', 0, 0, 5829.7353515625, -3050.04345703125, 252.7537689208984375, 4.766773223876953125, 0, 0, -0.68762016296386718, 0.726070582866668701, 120, 255, 1, 53262), -- Edict: Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+22, 381423, 2570, 13769, 13806, '0', 0, 0, 5759.7197265625, -3066.645751953125, 252.5118255615234375, 3.336160182952880859, 0, 0, -0.99527168273925781, 0.097130239009857177, 120, 255, 1, 53262), -- Edict: Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+23, 376276, 2570, 13769, 13806, '0', 0, 0, 5886.54248046875, -2950.451416015625, 205.095458984375, 0.502843201160430908, -0.35277557373046875, 0.612820625305175781, 0.35277557373046875, 0.612821102142333984, 120, 255, 1, 53262), -- Rune of Guardians (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+24, 377897, 2570, 13769, 13806, '0', 0, 0, 5901.9482421875, -2910.326171875, 207.1034393310546875, 5.143473625183105468, 0, 0, -0.53951072692871093, 0.841978728771209716, 120, 255, 1, 53262), -- Lingering Everflame (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+25, 378702, 2570, 13769, 13806, '0', 0, 0, 5910.712890625, -2907.739501953125, 215.2241973876953125, 3.11642765998840332, 0, 0, 0.999920845031738281, 0.012582127936184406, 120, 255, 1, 53262), -- Edict: Dark Talons (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+26, 377884, 2570, 13769, 13806, '0', 0, 0, 5974.734375, -3086.33251953125, 200.7344970703125, 5.770055770874023437, 0, 0, -0.25375938415527343, 0.967267394065856933, 120, 255, 1, 53262), -- Everflame Brazier (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+27, 377885, 2570, 13769, 13806, '0', 0, 0, 6005.32421875, -3064.97021484375, 200.5421905517578125, 0.088163316249847412, 0, 0, 0.0440673828125, 0.999028563499450683, 120, 255, 1, 53262), -- Everflame Brazier (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+28, 377896, 2570, 13769, 13806, '0', 0, 0, 5962.10595703125, -3134.885498046875, 124.1091842651367187, 1.792439579963684082, 0, 0, 0.780971527099609375, 0.624566614627838134, 120, 255, 1, 53262), -- Everflame Brazier (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+29, 377898, 2570, 13769, 13806, '0', 0, 0, 5962.10595703125, -3134.885498046875, 124.1091766357421875, 1.792439579963684082, 0, 0, 0.780971527099609375, 0.624566614627838134, 120, 255, 1, 53262), -- Everflame Brazier (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+30, 378704, 2570, 13769, 13806, '0', 0, 0, 6024.26318359375, -3019.89404296875, 204.103485107421875, 3.776696443557739257, 0, 0, -0.95000267028808593, 0.312241733074188232, 120, 255, 1, 53262), -- Edict: Evoker (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+31, 377598, 2570, 13769, 13806, '0', 0, 0, 6010.4326171875, -3066.028076171875, 129.2456512451171875, 5.605981826782226562, 0, 0, -0.3321685791015625, 0.943220019340515136, 120, 255, 1, 53262), -- Forge (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+32, 377593, 2570, 13769, 13806, '0', 0, 0, 6027.41796875, -3061.28857421875, 128.776275634765625, 3.459235906600952148, 0, 0, -0.98741436004638671, 0.158154711127281188, 120, 255, 1, 53262), -- Anvil (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+33, 377889, 2570, 13769, 13806, '0', 0, 0, 6023.79541015625, -3133.31982421875, 122.4642257690429687, 0.684976041316986083, 0, 0, 0.335831642150878906, 0.941922008991241455, 120, 255, 1, 53262), -- Everflame Brazier (Area: The War Creche - Difficulty: 0) CreateObject1
(@OGUID+34, 377886, 2570, 13769, 13806, '0', 0, 0, 6106.88623046875, -3069.354736328125, 136.075347900390625, 0.14539743959903717, 0, 0, 0.072634696960449218, 0.997358620166778564, 120, 255, 1, 53262); -- Everflame Brazier (Area: The War Creche - Difficulty: 0) CreateObject1
DELETE FROM `gameobject_addon` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+34;
INSERT INTO `gameobject_addon` (`guid`, `parent_rotation0`, `parent_rotation1`, `parent_rotation2`, `parent_rotation3`, `WorldEffectID`, `AIAnimKitID`) VALUES
(@OGUID+0, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Dark Talons
(@OGUID+1, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Dark Talons
(@OGUID+2, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Lingering Everflame
(@OGUID+3, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Dark Talons
(@OGUID+4, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Lingering Everflame
(@OGUID+5, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Dark Talons
(@OGUID+24, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Lingering Everflame
(@OGUID+26, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Everflame Brazier
(@OGUID+27, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Everflame Brazier
(@OGUID+28, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Everflame Brazier
(@OGUID+29, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Everflame Brazier
(@OGUID+31, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Forge
(@OGUID+32, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Anvil
(@OGUID+33, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0), -- Everflame Brazier
(@OGUID+34, 0, 0, -0.12447428703308105, 0.992222845554351806, 0, 0); -- Everflame Brazier

-- Template
UPDATE `creature_template` SET `faction`=31, `speed_walk`=0.400000005960464477, `speed_run`=0.285714298486709594, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=187163; -- Dark Widow
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=185272; -- Ancient Construct
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags2`=2048 WHERE `entry`=186853; -- Conjured Guardian

-- Template Addon
DELETE FROM `gameobject_template_addon` WHERE `entry` IN (377886 /*Everflame Brazier*/, 377889 /*Everflame Brazier*/, 377898 /*Everflame Brazier*/, 377896 /*Everflame Brazier*/, 377885 /*Everflame Brazier*/, 377884 /*Everflame Brazier*/);
INSERT INTO `gameobject_template_addon` (`entry`, `faction`, `flags`, `WorldEffectID`, `AIAnimKitID`) VALUES
(377886, 114, 0, 0, 0), -- Everflame Brazier
(377889, 114, 0, 0, 0), -- Everflame Brazier
(377898, 114, 0, 0, 0), -- Everflame Brazier
(377896, 114, 0, 0, 0), -- Everflame Brazier
(377885, 114, 0, 0, 0), -- Everflame Brazier
(377884, 114, 0, 0, 0); -- Everflame Brazier

-- Model & Difficulty
UPDATE `creature_template_difficulty` SET `VerifiedBuild`=53262 WHERE (`DifficultyID`=0 AND `Entry` IN (187335,181312,187131,187133,187164,182696,186853,183380,187015,181712,186946,181596,181680,187163,185272,185172,55370));

DELETE FROM `creature_model_info` WHERE `DisplayID`=116786;
INSERT INTO `creature_model_info` (`DisplayID`, `BoundingRadius`, `CombatReach`, `DisplayID_Other_Gender`, `VerifiedBuild`) VALUES
(116786, 0.212528020143508911, 0.150000005960464477, 0, 53262);

UPDATE `creature_model_info` SET `VerifiedBuild`=53262 WHERE `DisplayID`=104019;
UPDATE `creature_model_info` SET `BoundingRadius`=3.186465263366699218, `CombatReach`=4, `VerifiedBuild`=53262 WHERE `DisplayID`=105960;

-- Page Text
DELETE FROM `page_text` WHERE `ID` IN (8606 /*8606*/, 8531 /*8531*/);
INSERT INTO `page_text` (`ID`, `Text`, `NextPageID`, `PlayerConditionID`, `Flags`, `VerifiedBuild`) VALUES
(8606, 'Dark Talons\n\nWhere the enemies of the Earth-Warder tread, the Dark Talons shall harrow their skies, crush their will, and topple their leaders.\n\nDeny our enemies solace in walls and borders. For every talon in our ranks, you shall strike down ten of our foes from behind.\n\nThis weyrn, currently under the authority of Scalecommander Cindrethresh, shall train to be the elite force that shall be feared by all enemies of the black dragonflight.', 0, 0, 0, 53441), -- 8606
(8531, 'Obsidian Warders\n\nThis weyrn is charged with defending the allies of the black dragonflight and protecting its strongholds.\n\nWhether it is deployed to reinforce draconic legions or guard the skies alongside dragons, this weyrn is the embodiment of the Earth-Warder\'s aegis.\n\nCurrently under the authority of Scalecommander Azurathel, the Warders shall train to be the bulwark that enemy forces will break upon.', 0, 0, 0, 53441); -- 8531

-- Path for CGUID+18
SET @ENTRY := 185272;
SET @PATHOFFSET := 0;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 0, 0, 'Ancient Construct - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 5865.528, -2935.503, 205.253, NULL, 0),
(@PATH, 1, 5887.056, -2941.627, 205.387, NULL, 0),
(@PATH, 2, 5903.747, -2952.913, 205.3282, NULL, 0),
(@PATH, 3, 5887.056, -2941.627, 205.387, NULL, 0),
(@PATH, 4, 5865.528, -2935.503, 205.253, NULL, 0),
(@PATH, 5, 5849.722, -2934.042, 205.253, NULL, 0),
(@PATH, 6, 5835.656, -2938.844, 205.253, NULL, 0),
(@PATH, 7, 5825.506, -2943.889, 205.253, NULL, 0),
(@PATH, 8, 5835.656, -2938.844, 205.253, NULL, 0),
(@PATH, 9, 5849.722, -2934.042, 205.253, NULL, 0);

UPDATE `creature` SET `position_x`= 5865.528, `position_y`= -2935.503, `position_z`= 205.253, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+18;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(@CGUID+18, @PATH, 1);
