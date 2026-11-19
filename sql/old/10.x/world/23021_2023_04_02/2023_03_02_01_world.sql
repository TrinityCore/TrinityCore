SET @CGUID := 9003391;

-- Creature
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+58;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 193509, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3141.465087890625, 2605.76806640625, 366.6434326171875, 6.029794692993164062, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Woodland Filcher (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1, 193497, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3207.224609375, 2491.256103515625, 373.889862060546875, 3.469732046127319335, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Shortcoat Bear (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+2, 193509, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3190.01904296875, 2544.512451171875, 370.781463623046875, 5.976603031158447265, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Woodland Filcher (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+3, 193509, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3154.621337890625, 2476.716796875, 385.9647216796875, 4.662187576293945312, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Woodland Filcher (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+4, 194720, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3184.49609375, 2516.0830078125, 374.760833740234375, 1.364205598831176757, 120, 4, 0, 5, 0, 1, 0, 0, 0, 48069), -- Grizzlefur Cub (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+5, 193509, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3196.561279296875, 2596.87744140625, 362.147125244140625, 4.192681789398193359, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Woodland Filcher (Area: The Azure Span - Difficulty: 0) (Auras: 391254 - Hearty) (possible waypoints or random movement)
(@CGUID+6, 193497, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3096.220458984375, 2566.802001953125, 383.842498779296875, 1.951713085174560546, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Shortcoat Bear (Area: The Azure Span - Difficulty: 0)
(@CGUID+7, 190221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3177.155029296875, 2482.549072265625, 439.96923828125, 5.061579704284667968, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48069), -- Pine Flicker (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+8, 193498, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3095.4541015625, 2564.67822265625, 384.868865966796875, 1.188112854957580566, 120, 8, 0, 25194, 0, 1, 0, 0, 0, 48069), -- Juvenile Shortcoat Bear (Area: The Azure Span - Difficulty: 0)
(@CGUID+9, 193497, 2444, 13646, 13893, '0', 0, 0, 0, 0, -3377.257568359375, 2889.8466796875, 284.125640869140625, 3.202989578247070312, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48317), -- Shortcoat Bear (Area: Drake Eye's Pond - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+10, 193497, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3243.31494140625, 2565.11376953125, 360.181793212890625, 4.109749317169189453, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Shortcoat Bear (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+11, 193511, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3259.803955078125, 2657.994384765625, 346.947296142578125, 2.698893547058105468, 120, 6, 0, 16796, 0, 1, 0, 0, 0, 48069), -- Woadspine (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+12, 193497, 2444, 13646, 13893, '0', 0, 0, 0, 0, -3440.619140625, 2900.65625, 277.47259521484375, 3.805480241775512695, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48317), -- Shortcoat Bear (Area: Drake Eye's Pond - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+13, 193511, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3294.292724609375, 2667.4208984375, 339.689544677734375, 1.16526341438293457, 120, 6, 0, 16796, 0, 1, 0, 0, 0, 48069), -- Woadspine (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+14, 193497, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3279.532958984375, 2715.971435546875, 333.073272705078125, 0.782780826091766357, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Shortcoat Bear (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+15, 193498, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3279.532958984375, 2715.971435546875, 333.073272705078125, 2.490132331848144531, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 48069), -- Juvenile Shortcoat Bear (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+16, 193509, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3204.287353515625, 2727.846435546875, 461.797149658203125, 5.599758148193359375, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Woodland Filcher (Area: The Azure Span - Difficulty: 0)
(@CGUID+17, 192267, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3334.35986328125, 2690.464111328125, 330.450775146484375, 0.584559142589569091, 120, 4, 0, 5, 0, 1, 0, 0, 0, 48069), -- Azure Crystalspine (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+18, 193507, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3352.778564453125, 2751.54931640625, 321.405242919921875, 5.43351602554321289, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Red Furred Bull (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+19, 193507, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3304.895751953125, 2800.178955078125, 325.705474853515625, 6.195866584777832031, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Red Furred Bull (Area: The Azure Span - Difficulty: 0)
(@CGUID+20, 193507, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3296.901123046875, 2798.611083984375, 327.486175537109375, 2.565255165100097656, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Red Furred Bull (Area: The Azure Span - Difficulty: 0)
(@CGUID+21, 193502, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3360.275390625, 2767.575439453125, 316.8699951171875, 5.43351602554321289, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Red Furred Calf (Area: The Azure Span - Difficulty: 0) (Auras: 391254 - Hearty) (possible waypoints or random movement)
(@CGUID+22, 193503, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3355.16943359375, 2764.870361328125, 318.772491455078125, 5.43351602554321289, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Red Furred Cow (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+23, 193502, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3360.676025390625, 2760.53271484375, 317.2611083984375, 5.43351602554321289, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Red Furred Calf (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+24, 193503, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3362.92578125, 2755.596435546875, 317.787841796875, 5.43351602554321289, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Red Furred Cow (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+25, 193497, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3374.8779296875, 2712.501953125, 320.56719970703125, 3.047751426696777343, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Shortcoat Bear (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+26, 190221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3389.277587890625, 2603.8251953125, 366.759857177734375, 1.96351015567779541, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48069), -- Pine Flicker (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+27, 193507, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3471.467041015625, 2596.6806640625, 333.193603515625, 1.91470038890838623, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Red Furred Bull (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+28, 193503, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3478.05712890625, 2594.320556640625, 333.1785888671875, 5.059251785278320312, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Red Furred Cow (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+29, 198260, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3533.661376953125, 2604.7509765625, 293.337921142578125, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Misaligned Ley Crystal (Area: The Azure Span - Difficulty: 0) (Auras: 393077 - Misaligned [DNT])
(@CGUID+30, 190221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3457.617431640625, 2603.408935546875, 361.245361328125, 4.295994281768798828, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48069), -- Pine Flicker (Area: The Azure Span - Difficulty: 0)
(@CGUID+31, 193503, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3427.06787109375, 2507.338623046875, 351.760772705078125, 2.291278839111328125, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Red Furred Cow (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+32, 193502, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3425.463134765625, 2502.846923828125, 354.22247314453125, 2.291278839111328125, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Red Furred Calf (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+33, 190221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3468.522216796875, 2610.235107421875, 355.74774169921875, 1.707101821899414062, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48069), -- Pine Flicker (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+34, 193503, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3434.524658203125, 2500.30615234375, 354.255157470703125, 2.291278839111328125, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Red Furred Cow (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+35, 193502, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3430.307373046875, 2501.932373046875, 354.545196533203125, 2.291278839111328125, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 48069), -- Red Furred Calf (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+36, 193503, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3434.564208984375, 2506.783447265625, 352.47943115234375, 2.291278839111328125, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Red Furred Cow (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+37, 192265, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3400.09814453125, 2526.235595703125, 349.155029296875, 4.460101604461669921, 120, 4, 0, 5, 0, 1, 0, 0, 0, 48069), -- Azure Crystalspine (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+38, 193511, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3301.1083984375, 2547.455078125, 358.20208740234375, 5.801037311553955078, 120, 6, 0, 16796, 0, 1, 0, 0, 0, 48069), -- Woadspine (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+39, 193497, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3366.51025390625, 2841.447998046875, 305.390533447265625, 3.333540201187133789, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Shortcoat Bear (Area: The Azure Span - Difficulty: 0)
(@CGUID+40, 193509, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3301.207763671875, 2371.35107421875, 385.38775634765625, 3.153202772140502929, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Woodland Filcher (Area: The Azure Span - Difficulty: 0)
(@CGUID+41, 193509, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3429.626708984375, 2396.7275390625, 388.8052978515625, 0, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Woodland Filcher (Area: The Azure Span - Difficulty: 0)
(@CGUID+42, 193509, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3270.89501953125, 2375.21533203125, 390.109161376953125, 0.485478222370147705, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Woodland Filcher (Area: The Azure Span - Difficulty: 0)
(@CGUID+43, 193509, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3342.89990234375, 2364.084716796875, 386.423431396484375, 2.491533517837524414, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Woodland Filcher (Area: The Azure Span - Difficulty: 0)
(@CGUID+44, 190221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3324.71533203125, 2394.008056640625, 409.89825439453125, 3.610646724700927734, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48069), -- Pine Flicker (Area: The Azure Span - Difficulty: 0)
(@CGUID+45, 193511, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3274.082763671875, 2390.043701171875, 386.538970947265625, 1.696120262145996093, 120, 6, 0, 16796, 0, 1, 0, 0, 0, 48069), -- Woadspine (Area: The Azure Span - Difficulty: 0)
(@CGUID+46, 193497, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3210.613525390625, 2408.14794921875, 391.93817138671875, 1.00234997272491455, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Shortcoat Bear (Area: The Azure Span - Difficulty: 0)
(@CGUID+47, 190221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3257.098388671875, 2419.534423828125, 465.31298828125, 1.089844584465026855, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48069), -- Pine Flicker (Area: The Azure Span - Difficulty: 0)
(@CGUID+48, 190221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3297.494384765625, 2362.50537109375, 446.179901123046875, 6.1339569091796875, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48069), -- Pine Flicker (Area: The Azure Span - Difficulty: 0)
(@CGUID+49, 192968, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3287.065185546875, 2316.624267578125, 391.383514404296875, 2.808651685714721679, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 48069), -- Oozing Decay (Area: The Azure Span - Difficulty: 0)
(@CGUID+50, 192968, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3287.26123046875, 2316.69189453125, 391.359832763671875, 2.808651685714721679, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 48069), -- Oozing Decay (Area: The Azure Span - Difficulty: 0)
(@CGUID+51, 192968, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3242.24267578125, 2419.56982421875, 382.1826171875, 0.958544135093688964, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 48069), -- Oozing Decay (Area: The Azure Span - Difficulty: 0)
(@CGUID+52, 192968, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3242.60009765625, 2419.060791015625, 382.261962890625, 2.224019765853881835, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 48069), -- Oozing Decay (Area: The Azure Span - Difficulty: 0)
(@CGUID+53, 193497, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3317.92529296875, 2462.03125, 370.12274169921875, 5.238353252410888671, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 48069), -- Shortcoat Bear (Area: The Azure Span - Difficulty: 0)
(@CGUID+54, 192968, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3313.263671875, 2448.664306640625, 371.596649169921875, 4.171561717987060546, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 48069), -- Oozing Decay (Area: The Azure Span - Difficulty: 0)
(@CGUID+55, 192968, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3312.746337890625, 2448.697509765625, 371.348602294921875, 4.171561717987060546, 120, 0, 0, 28249, 0, 0, 0, 0, 0, 48069), -- Oozing Decay (Area: The Azure Span - Difficulty: 0)
(@CGUID+56, 190221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3377.388671875, 2782.68603515625, 319.876007080078125, 3.628751039505004882, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48069), -- Pine Flicker (Area: The Azure Span - Difficulty: 0)
(@CGUID+57, 193497, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3267.970458984375, 2751.9208984375, 336.005218505859375, 3.265947818756103515, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 48069), -- Shortcoat Bear (Area: The Azure Span - Difficulty: 0)
(@CGUID+58, 190221, 2444, 13646, 13646, '0', 0, 0, 0, 0, -3454.7255859375, 2796.169189453125, 314.72821044921875, 3.729835748672485351, 120, 0, 0, 5, 0, 0, 0, 0, 0, 48069); -- Pine Flicker (Area: The Azure Span - Difficulty: 0)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+58;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+19, 0, 0, 0, 0, 0, 1, 0, 567, 0, 0, 0, 0, ''), -- Red Furred Bull
(@CGUID+20, 0, 0, 0, 0, 0, 1, 0, 567, 0, 0, 0, 0, ''), -- Red Furred Bull
(@CGUID+41, 0, 0, 0, 3, 0, 1, 0, 455, 0, 0, 0, 0, ''); -- Woodland Filcher

-- Creature Template
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=193498; -- Juvenile Shortcoat Bear

-- Waypoints for CGUID+18
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+18;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+18, @CGUID+18, 0, 0, 515, 0, 0),
(@CGUID+18, @CGUID+22, 6, 300, 515, 1, 10),
(@CGUID+18, @CGUID+24, 6, 60, 515, 1, 10),
(@CGUID+18, @CGUID+23, 6, 20, 515, 1, 10),
(@CGUID+18, @CGUID+21, 6, 340, 515, 1, 10);

SET @PATH := (@CGUID+18) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3431.728, 2867.523, 281.4935, NULL, 0),
(@PATH, 1, -3419.981, 2899.703, 278.6351, NULL, 5474),
(@PATH, 2, -3431.728, 2867.523, 281.4935, NULL, 0),
(@PATH, 3, -3431.83, 2849.077, 282.5457, NULL, 0),
(@PATH, 4, -3402.982, 2829.287, 296.1257, NULL, 0),
(@PATH, 5, -3393.507, 2804.335, 305.7631, NULL, 0),
(@PATH, 6, -3367.661, 2768.48, 313.1128, NULL, 0),
(@PATH, 7, -3344.799, 2742.466, 325.5055, NULL, 0),
(@PATH, 8, -3338.543, 2711.809, 327.3452, NULL, 0),
(@PATH, 9, -3335.512, 2674.767, 330.0016, NULL, 0),
(@PATH, 10, -3314.007, 2650.757, 336.9271, NULL, 7867),
(@PATH, 11, -3335.512, 2674.767, 330.0016, NULL, 0),
(@PATH, 12, -3338.547, 2711.659, 327.283, NULL, 0),
(@PATH, 13, -3344.799, 2742.466, 325.5055, NULL, 0),
(@PATH, 14, -3367.661, 2768.48, 313.1128, NULL, 0),
(@PATH, 15, -3393.507, 2804.335, 305.7631, NULL, 0),
(@PATH, 16, -3402.903, 2829.225, 296.1129, NULL, 0),
(@PATH, 17, -3431.75, 2849.015, 282.6152, NULL, 0);

UPDATE `creature` SET `position_x`= -3431.728, `position_y`= 2867.523, `position_z`= 281.4935, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+18;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+18;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+18, @PATH, 1);

-- Waypoints for CGUID+27
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+27;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+27, @CGUID+27, 0, 0, 515, 0, 0),
(@CGUID+27, @CGUID+28, 4, 90, 515, 7, 13);

SET @PATH := (@CGUID+27) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3368.637, 2503.476, 357.2046, NULL, 8120),
(@PATH, 1, -3378.715, 2520.76, 354.722, NULL, 0),
(@PATH, 2, -3395.434, 2536.872, 348.9058, NULL, 0),
(@PATH, 3, -3405.865, 2563.971, 343.0657, NULL, 0),
(@PATH, 4, -3427.337, 2579.958, 337.147, NULL, 0),
(@PATH, 5, -3451.198, 2584.038, 335.8872, NULL, 0),
(@PATH, 6, -3468.911, 2589.598, 334.9581, NULL, 0),
(@PATH, 7, -3471.467, 2596.681, 333.1936, NULL, 12127),
(@PATH, 8, -3468.911, 2589.598, 334.9581, NULL, 0),
(@PATH, 9, -3451.198, 2584.038, 335.8872, NULL, 0),
(@PATH, 10, -3427.337, 2579.958, 337.147, NULL, 0),
(@PATH, 11, -3405.865, 2563.971, 343.0657, NULL, 0),
(@PATH, 12, -3395.434, 2536.872, 348.9058, NULL, 0),
(@PATH, 13, -3378.715, 2520.76, 354.722, NULL, 0);

UPDATE `creature` SET `position_x`= -3368.637, `position_y`= 2503.476, `position_z`= 357.2046, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+27;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+27;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+27, @PATH, 1);

-- Waypoints for CGUID+36
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+36;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+36, @CGUID+36, 0, 0, 515, 0, 0),
(@CGUID+36, @CGUID+34, 6, 300, 515, 14, 29),
(@CGUID+36, @CGUID+31, 6, 60, 515, 14, 29),
(@CGUID+36, @CGUID+32, 6, 20, 515, 14, 29),
(@CGUID+36, @CGUID+35, 6, 340, 515, 14, 29);

SET @PATH := (@CGUID+36) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3458.837, 2658.7, 320.8941, NULL, 0),
(@PATH, 1, -3467.094, 2646.333, 323.1231, NULL, 0),
(@PATH, 2, -3481.785, 2625.183, 327.2216, NULL, 0),
(@PATH, 3, -3479.976, 2605.903, 331.3741, NULL, 0),
(@PATH, 4, -3474.12, 2589.726, 334.2054, NULL, 0),
(@PATH, 5, -3468.488, 2572.898, 337.7356, NULL, 0),
(@PATH, 6, -3471.764, 2561.555, 340.4263, NULL, 0),
(@PATH, 7, -3466.884, 2541.586, 347.2043, NULL, 0),
(@PATH, 8, -3452.113, 2526.793, 350.9787, NULL, 0),
(@PATH, 9, -3424.503, 2495.325, 357.4188, NULL, 0),
(@PATH, 10, -3399.151, 2478.432, 363.8409, NULL, 0),
(@PATH, 11, -3371.424, 2463.726, 364.0047, NULL, 0),
(@PATH, 12, -3360.255, 2445.521, 371.7814, NULL, 0),
(@PATH, 13, -3358.184, 2422.88, 378.118, NULL, 0),
(@PATH, 14, -3360.905, 2397.951, 381.4866, NULL, 8263),
(@PATH, 15, -3358.17, 2422.805, 378.2343, NULL, 0),
(@PATH, 16, -3360.255, 2445.521, 371.7814, NULL, 0),
(@PATH, 17, -3371.424, 2463.726, 364.0047, NULL, 0),
(@PATH, 18, -3399.151, 2478.432, 363.8409, NULL, 0),
(@PATH, 19, -3424.503, 2495.325, 357.4188, NULL, 0),
(@PATH, 20, -3452.113, 2526.793, 350.9787, NULL, 0),
(@PATH, 21, -3466.884, 2541.586, 347.2043, NULL, 0),
(@PATH, 22, -3471.764, 2561.555, 340.4263, NULL, 0),
(@PATH, 23, -3468.488, 2572.898, 337.7356, NULL, 0),
(@PATH, 24, -3474.12, 2589.726, 334.2054, NULL, 0),
(@PATH, 25, -3479.976, 2605.903, 331.3741, NULL, 0),
(@PATH, 26, -3481.785, 2625.183, 327.2216, NULL, 0),
(@PATH, 27, -3467.094, 2646.333, 323.1231, NULL, 0),
(@PATH, 28, -3458.837, 2658.7, 320.8941, NULL, 0),
(@PATH, 29, -3459.622, 2676.675, 318.6869, NULL, 6859);

UPDATE `creature` SET `position_x`= -3458.837, `position_y`= 2658.7, `position_z`= 320.8941, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+36;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+36;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+36, @PATH, 1);

-- Waypoints for CGUID+14
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+14;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+14, @CGUID+14, 0, 0, 515, 0, 0),
(@CGUID+14, @CGUID+15, 4, 0, 515, 0, 0);

SET @PATH := (@CGUID+14) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3292.83, 2765.562, 329.8903, NULL, 0),
(@PATH, 1, -3272.51, 2770.939, 334.2202, NULL, 0),
(@PATH, 2, -3248.28, 2769.512, 335.4793, NULL, 0),
(@PATH, 3, -3230.285, 2753.267, 338.4461, NULL, 0),
(@PATH, 4, -3234.465, 2718.448, 338.7516, NULL, 0),
(@PATH, 5, -3231.943, 2703.92, 342.3979, NULL, 0),
(@PATH, 6, -3279.533, 2715.971, 333.0733, NULL, 0),
(@PATH, 7, -3279.384, 2715.222, 333.0733, NULL, 0),
(@PATH, 8, -3274.8, 2708.097, 335.8755, NULL, 0),
(@PATH, 9, -3283.481, 2708.161, 332.993, NULL, 0),
(@PATH, 10, -3279.51, 2715.779, 333.0733, NULL, 0),
(@PATH, 11, -3284.165, 2710.661, 332.6612, NULL, 0),
(@PATH, 12, -3274.773, 2712.59, 333.8369, NULL, 1941),
(@PATH, 13, -3303.483, 2745.253, 328.144, NULL, 0);

UPDATE `creature` SET `position_x`= -3292.83, `position_y`= 2765.562, `position_z`= 329.8903, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+14;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+14;
INSERT INTO `creature_addon` (`guid`, `path_id`, `SheathState`) VALUES
(@CGUID+14, @PATH, 1);
