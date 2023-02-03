SET @CGUID := 1251148;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+72;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 186962, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3372.55908203125, 2924.046875, 281.760223388671875, 2.519045591354370117, 120, 0, 0, 523080, 0, 0, 0, 0, 0, 47213), -- Cascade (Area: Drake Eye's Pond - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+1, 186968, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3378.125, 2931.25, 282.691009521484375, 0, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Falling Water (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+2, 193507, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3337.5, 3050, 287.729156494140625, 2.996659517288208007, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Red Furred Bull (Area: Drake Eye's Pond - Difficulty: 0) (Auras: 391254 - Hearty) (possible waypoints or random movement)
(@CGUID+3, 193497, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3491.8037109375, 2975.03564453125, 271.352783203125, 6.029302597045898437, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+4, 186968, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3389.421630859375, 2913.707763671875, 286.903594970703125, 6.168272018432617187, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Falling Water (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+5, 193497, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3350.08935546875, 2966.580810546875, 283.9476318359375, 3.908497333526611328, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: Drake Eye's Pond - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+6, 193497, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3487.681396484375, 3022.477783203125, 271.1937255859375, 3.539489030838012695, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+7, 193503, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3313.7744140625, 2994.470458984375, 287.324798583984375, 3.449909925460815429, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Red Furred Cow (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+8, 186968, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3377.01171875, 2914.5341796875, 281.907989501953125, 5.105226993560791015, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Falling Water (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+9, 193507, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3409.728759765625, 2957.98388671875, 281.006805419921875, 1.753444790840148925, 120, 8, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Red Furred Bull (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+10, 186968, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3384.828369140625, 2937.002197265625, 283.2322998046875, 0.09686414897441864, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Falling Water (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+11, 186968, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3379.33056640625, 2907.591064453125, 282.12457275390625, 4.737774372100830078, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Falling Water (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+12, 192049, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3416.472412109375, 2939.812255859375, 278.890045166015625, 3.753438949584960937, 120, 2, 0, 5, 0, 1, 0, 0, 0, 47213), -- Swoglet (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+13, 193497, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3418.620849609375, 3035.47119140625, 280.488494873046875, 5.451517581939697265, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+14, 193507, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3414.80810546875, 3103.326904296875, 271.116180419921875, 2.762717247009277343, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Red Furred Bull (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+15, 193497, 2444, 13646, 0, '0', '0', 0, 0, 0, -2988.383056640625, 2821.664306640625, 358.69256591796875, 2.998886346817016601, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: 0 - Difficulty: 0)
(@CGUID+16, 193502, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3291.61181640625, 3017.924560546875, 294.001983642578125, 3.954701662063598632, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Red Furred Calf (Area: Drake Eye's Pond - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+17, 186968, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3310.4150390625, 2919.291748046875, 283.0059814453125, 1.345264554023742675, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Falling Water (Area: Drake Eye's Pond - Difficulty: 0)
(@CGUID+18, 186968, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3300, 2933.3330078125, 282.797760009765625, 1.327300786972045898, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Falling Water (Area: Drake Eye's Pond - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+19, 186968, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3278.803466796875, 2930.679931640625, 296.54730224609375, 2.66910409927368164, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Falling Water (Area: Drake Eye's Pond - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+20, 193507, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3263.56689453125, 3093.732177734375, 297.872314453125, 3.045173168182373046, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Red Furred Bull (Area: Drake Eye's Pond - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+21, 186968, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3293.692626953125, 2943.80126953125, 282.8580322265625, 4.657392501831054687, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Falling Water (Area: Drake Eye's Pond - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+22, 186968, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3284.188720703125, 2935.71826171875, 288.8746337890625, 1.222748994827270507, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Falling Water (Area: Drake Eye's Pond - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+23, 186968, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3275.963623046875, 2923.741455078125, 293.664947509765625, 4.071846961975097656, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Falling Water (Area: Drake Eye's Pond - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+24, 193497, 2444, 13646, 13893, '0', '0', 0, 0, 0, -3281.161865234375, 3042.67431640625, 295.672821044921875, 4.272325515747070312, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: Drake Eye's Pond - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+25, 193507, 2444, 13646, 0, '0', '0', 0, 0, 0, -3231.201171875, 2958.121337890625, 306.979827880859375, 3.042894840240478515, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Red Furred Bull (Area: 0 - Difficulty: 0) (Auras: 391254 - Hearty) (possible waypoints or random movement)
(@CGUID+26, 193502, 2444, 13646, 0, '0', '0', 0, 0, 0, -3268.4140625, 3152.89111328125, 295.2208251953125, 0.470039248466491699, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Red Furred Calf (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+27, 193507, 2444, 13646, 0, '0', '0', 0, 0, 0, -3202.001708984375, 3034.117919921875, 309.383270263671875, 2.66834259033203125, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Red Furred Bull (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+28, 193502, 2444, 13646, 0, '0', '0', 0, 0, 0, -3226.5615234375, 3162.84130859375, 304.055816650390625, 5.88873291015625, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Red Furred Calf (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+29, 193503, 2444, 13646, 0, '0', '0', 0, 0, 0, -3235.30908203125, 3172.47900390625, 300.15423583984375, 2.986716508865356445, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Red Furred Cow (Area: 0 - Difficulty: 0)
(@CGUID+30, 193503, 2444, 13646, 0, '0', '0', 0, 0, 0, -3221.94091796875, 3164.751708984375, 304.914459228515625, 5.88982248306274414, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Red Furred Cow (Area: 0 - Difficulty: 0)
(@CGUID+31, 193502, 2444, 13646, 0, '0', '0', 0, 0, 0, -3223.851318359375, 3169.372314453125, 304.276947021484375, 5.895462989807128906, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Red Furred Calf (Area: 0 - Difficulty: 0)
(@CGUID+32, 190221, 2444, 13646, 0, '0', '0', 0, 0, 0, -3258.5654296875, 3147.34619140625, 332.172882080078125, 1.647834181785583496, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Pine Flicker (Area: 0 - Difficulty: 0)
(@CGUID+33, 193509, 2444, 13646, 0, '0', '0', 0, 0, 0, -3169.621826171875, 3126.63720703125, 316.84649658203125, 2.111149549484252929, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Woodland Filcher (Area: 0 - Difficulty: 0)
(@CGUID+34, 193503, 2444, 13646, 0, '0', '0', 0, 0, 0, -3168.71533203125, 2997.248291015625, 322.721466064453125, 1.202307939529418945, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Red Furred Cow (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+35, 193502, 2444, 13646, 0, '0', '0', 0, 0, 0, -3148.564, 2844.99, 334.8633, 4.346758365631103515, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Red Furred Calf (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+36, 193511, 2444, 13646, 0, '0', '0', 0, 0, 0, -3123.94677734375, 3089.97021484375, 321.038726806640625, 1.173803091049194335, 120, 10, 0, 16796, 0, 1, 0, 0, 0, 47213), -- Woadspine (Area: 0 - Difficulty: 0)
(@CGUID+37, 192069, 2444, 13646, 0, '0', '0', 0, 0, 0, -3127.521240234375, 3009.60205078125, 326.29534912109375, 4.869223594665527343, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Vorquin Runt (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+38, 193511, 2444, 13646, 0, '0', '0', 0, 0, 0, -3160.88818359375, 2975.091796875, 323.24371337890625, 1.690186500549316406, 120, 10, 0, 16796, 0, 1, 0, 0, 0, 47213), -- Woadspine (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+39, 193497, 2444, 13646, 0, '0', '0', 0, 0, 0, -3103.592041015625, 3017.97119140625, 327.12640380859375, 3.569432258605957031, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+40, 193509, 2444, 13646, 0, '0', '0', 0, 0, 0, -3149.278076171875, 2988.14599609375, 421.5181884765625, 0.328183174133300781, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Woodland Filcher (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+41, 193509, 2444, 13646, 0, '0', '0', 0, 0, 0, -3136.3212890625, 2967.685546875, 402.413726806640625, 2.293825626373291015, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Woodland Filcher (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+42, 193509, 2444, 13646, 0, '0', '0', 0, 0, 0, -3084.536865234375, 2912.9892578125, 336.6861572265625, 2.951300621032714843, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Woodland Filcher (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+43, 193497, 2444, 13646, 0, '0', '0', 0, 0, 0, -3153.3388671875, 2922.899169921875, 325.522308349609375, 3.879445552825927734, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+44, 193511, 2444, 13646, 0, '0', '0', 0, 0, 0, -3083.158203125, 2932.35546875, 334.71661376953125, 5.608444690704345703, 120, 10, 0, 16796, 0, 1, 0, 0, 0, 47213), -- Woadspine (Area: 0 - Difficulty: 0) (Auras: 391254 - Hearty) (possible waypoints or random movement)
(@CGUID+45, 193507, 2444, 13646, 0, '0', '0', 0, 0, 0, -3207.890625, 2840.412353515625, 327.21759033203125, 3.299134016036987304, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Red Furred Bull (Area: 0 - Difficulty: 0) (Auras: 391254 - Hearty) (possible waypoints or random movement)
(@CGUID+46, 193497, 2444, 13646, 0, '0', '0', 0, 0, 0, -3245.916015625, 2904.17578125, 308.024993896484375, 6.18740081787109375, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: 0 - Difficulty: 0) (Auras: 391254 - Hearty) (possible waypoints or random movement)
(@CGUID+47, 193497, 2444, 13646, 0, '0', '0', 0, 0, 0, -3276.91162109375, 2941.439208984375, 300.492919921875, 3.397525787353515625, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+48, 193503, 2444, 13646, 0, '0', '0', 0, 0, 0, -3207.26318359375, 2836.4619140625, 327.40167236328125, 3.299072265625, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Red Furred Cow (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+49, 193497, 2444, 13646, 0, '0', '0', 0, 0, 0, -3221.33154296875, 2862.044921875, 322.595245361328125, 1.249983072280883789, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+50, 190221, 2444, 13646, 0, '0', '0', 0, 0, 0, -3222.03076171875, 2857.2314453125, 360.84259033203125, 0.445851445198059082, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Pine Flicker (Area: 0 - Difficulty: 0)
(@CGUID+51, 193511, 2444, 13646, 0, '0', '0', 0, 0, 0, -3156.29638671875, 2792.6513671875, 337.919677734375, 4.751403331756591796, 120, 10, 0, 16796, 0, 1, 0, 0, 0, 47213), -- Woadspine (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+52, 193502, 2444, 13646, 0, '0', '0', 0, 0, 0, -3053.83, 2954.135, 337.9153, 3.928618669509887695, 120, 0, 0, 41990, 0, 0, 0, 0, 0, 47213), -- Red Furred Calf (Area: 0 - Difficulty: 0)
(@CGUID+53, 193503, 2444, 13646, 0, '0', '0', 0, 0, 0, -3121.640869140625, 2770.778076171875, 339.125274658203125, 3.423512697219848632, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Red Furred Cow (Area: 0 - Difficulty: 0)
(@CGUID+54, 192049, 2444, 13646, 0, '0', '0', 0, 0, 0, -3137.230712890625, 2782.123291015625, 337.557861328125, 5.570118904113769531, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Swoglet (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+55, 193509, 2444, 13646, 0, '0', '0', 0, 0, 0, -3037.59521484375, 2831.408935546875, 349.8687744140625, 1.874179482460021972, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Woodland Filcher (Area: 0 - Difficulty: 0)
(@CGUID+56, 193497, 2444, 13646, 0, '0', '0', 0, 0, 0, -3150, 2758.3330078125, 336.92156982421875, 3.141592741012573242, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: 0 - Difficulty: 0)
(@CGUID+57, 190221, 2444, 13646, 0, '0', '0', 0, 0, 0, -3039.766357421875, 2831.180419921875, 373.154541015625, 4.888529300689697265, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Pine Flicker (Area: 0 - Difficulty: 0)
(@CGUID+58, 190221, 2444, 13646, 0, '0', '0', 0, 0, 0, -3064.702392578125, 2774.33984375, 376.420562744140625, 5.449159622192382812, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Pine Flicker (Area: 0 - Difficulty: 0)
(@CGUID+59, 193509, 2444, 13646, 0, '0', '0', 0, 0, 0, -3055.9736328125, 2733.874267578125, 357.814361572265625, 0.985118687152862548, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Woodland Filcher (Area: 0 - Difficulty: 0)
(@CGUID+60, 193511, 2444, 13646, 0, '0', '0', 0, 0, 0, -3109.15625, 2748.355224609375, 343.676422119140625, 5.380113601684570312, 120, 10, 0, 16796, 0, 1, 0, 0, 0, 47213), -- Woadspine (Area: 0 - Difficulty: 0)
(@CGUID+61, 3300, 2444, 13646, 0, '0', '0', 0, 0, 0, -3011.153076171875, 2829.43798828125, 353.092987060546875, 3.911278247833251953, 120, 10, 0, 1, 0, 1, 0, 0, 0, 47213), -- Adder (Area: 0 - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+62, 193497, 2444, 13646, 0, '0', '0', 0, 0, 0, -3092.3828125, 2709.001708984375, 354.7318115234375, 2.514942646026611328, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: 0 - Difficulty: 0)
(@CGUID+63, 193511, 2444, 13646, 0, '0', '0', 0, 0, 0, -3005.49072265625, 2759.76220703125, 363.23553466796875, 1.263251066207885742, 120, 10, 0, 16796, 0, 1, 0, 0, 0, 47213), -- Woadspine (Area: 0 - Difficulty: 0)
(@CGUID+64, 190221, 2444, 13646, 0, '0', '0', 0, 0, 0, -3108.12353515625, 2698.450439453125, 385.30755615234375, 1.383399724960327148, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Pine Flicker (Area: 0 - Difficulty: 0)
(@CGUID+65, 193509, 2444, 13646, 0, '0', '0', 0, 0, 0, -2967.766845703125, 2774.170166015625, 370.210174560546875, 2.91632080078125, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Woodland Filcher (Area: 0 - Difficulty: 0)
(@CGUID+66, 193497, 2444, 13646, 0, '0', '0', 0, 0, 0, -3133.450927734375, 2681.535888671875, 348.73211669921875, 6.103593826293945312, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: 0 - Difficulty: 0)
(@CGUID+67, 193497, 2444, 13646, 0, '0', '0', 0, 0, 0, -3079.166015625, 2663.541015625, 349.06732177734375, 3.312328100204467773, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Shortcoat Bear (Area: 0 - Difficulty: 0)
(@CGUID+68, 193494, 2444, 13646, 0, '0', '0', 0, 0, 0, -3102.247802734375, 2648.08154296875, 344.626861572265625, 1.485581159591674804, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213), -- Mud Beaver Kit (Area: 0 - Difficulty: 0)
(@CGUID+69, 193496, 2444, 13646, 0, '0', '0', 0, 0, 0, -3103.803955078125, 2644.2587890625, 347.93817138671875, 2.34719395637512207, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Mud Beaver (Area: 0 - Difficulty: 0)
(@CGUID+70, 193496, 2444, 13646, 0, '0', '0', 0, 0, 0, -3055.104248046875, 2612.0869140625, 349.909576416015625, 2.731550931930541992, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Mud Beaver (Area: 0 - Difficulty: 0)
(@CGUID+71, 193496, 2444, 13646, 0, '0', '0', 0, 0, 0, -3043.741943359375, 2612.848388671875, 349.21875, 2.827628850936889648, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Mud Beaver (Area: 0 - Difficulty: 0)
(@CGUID+72, 193494, 2444, 13646, 0, '0', '0', 0, 0, 0, -3031.0107421875, 2618.493408203125, 347.579498291015625, 4.124927520751953125, 120, 0, 0, 5, 0, 0, 0, 0, 0, 47213); -- Mud Beaver Kit (Area: 0 - Difficulty: 0)
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+72;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+69, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''), -- Mud Beaver
(@CGUID+70, 0, 0, 1, 1, 0, 0, 0, 0, 0, ''); -- Mud Beaver

-- Creature Template Addon
DELETE FROM `creature_template_addon` WHERE `entry` IN (186962);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(186962, 0, 0, 0, 1, 994, 0, 0, 0, 0, ''); -- Cascade

-- Creature Template
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=193496; -- Mud Beaver
UPDATE `creature_template` SET `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=193494; -- Mud Beaver Kit
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=190, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=186968; -- Falling Water
UPDATE `creature_template` SET `minlevel`=69, `maxlevel`=69, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048 WHERE `entry`=186962; -- Cascade

-- Waypoint for CGUID+30
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+30;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+30, @CGUID+30, 0, 0, 515, 0, 0),
(@CGUID+30, @CGUID+31, 4, 50, 515, 0, 0),
(@CGUID+30, @CGUID+28, 4, 300, 515, 0, 0);

SET @PATH := (@CGUID+30) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3221.941, 3164.752, 304.9145, NULL, 9315),
(@PATH, 1, -3237.54, 3171.276, 299.4421, NULL, 0),
(@PATH, 2, -3250.205, 3168.465, 297.0771, NULL, 0),
(@PATH, 3, -3273.017, 3157.314, 293.3007, NULL, 0),
(@PATH, 4, -3291.589, 3139.887, 289.4615, NULL, 0),
(@PATH, 5, -3311.828, 3132.185, 284.9856, NULL, 0),
(@PATH, 6, -3329.309, 3114.338, 283.46, NULL, 0),
(@PATH, 7, -3346.333, 3107.361, 281.3661, NULL, 12776),
(@PATH, 8, -3329.342, 3114.314, 283.5957, NULL, 0),
(@PATH, 9, -3311.828, 3132.185, 284.9856, NULL, 0),
(@PATH, 10, -3291.589, 3139.887, 289.4615, NULL, 0),
(@PATH, 11, -3273.017, 3157.314, 293.3007, NULL, 0),
(@PATH, 12, -3250.205, 3168.465, 297.0771, NULL, 0),
(@PATH, 13, -3237.54, 3171.276, 299.4421, NULL, 0);

UPDATE `creature` SET `position_x`= -3221.941, `position_y`= 3164.752, `position_z`= 304.9145, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+30;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+30;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+30, @PATH, 1);

-- Waypoints for CGUID+29
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+29;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+29, @CGUID+29, 0, 0, 515, 0, 0),
(@CGUID+29, @CGUID+26, 4, 0, 515, 0, 0);

SET @PATH := (@CGUID+29) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3273.257, 3154.356, 293.516, NULL, 0),
(@PATH, 1, -3255.875, 3167.584, 296.3474, NULL, 0),
(@PATH, 2, -3242.941, 3173.677, 298.6594, NULL, 0),
(@PATH, 3, -3231.033, 3171.812, 301.8438, NULL, 12678),
(@PATH, 4, -3242.941, 3173.677, 298.6594, NULL, 0),
(@PATH, 5, -3255.875, 3167.584, 296.3474, NULL, 0),
(@PATH, 6, -3273.257, 3154.356, 293.516, NULL, 0),
(@PATH, 7, -3292.941, 3138.2, 289.4376, NULL, 0),
(@PATH, 8, -3312.712, 3124.7, 285.8718, NULL, 0),
(@PATH, 9, -3330.528, 3116.392, 283.038, NULL, 0),
(@PATH, 10, -3344.62, 3120.847, 280.0471, NULL, 10069),
(@PATH, 11, -3330.528, 3116.392, 283.038, NULL, 0),
(@PATH, 12, -3312.712, 3124.7, 285.8718, NULL, 0),
(@PATH, 13, -3292.941, 3138.2, 289.4376, NULL, 0);

UPDATE `creature` SET `position_x`= -3273.257, `position_y`= 3154.356, `position_z`= 293.516, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+29;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+29;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+29, @PATH, 1);

-- Waypoints for CGUID+7
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+7;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+7, @CGUID+7, 0, 0, 515, 0, 0),
(@CGUID+7, @CGUID+16, 4, 0, 515, 0, 0);

SET @PATH := (@CGUID+7) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3260.802, 3056.167, 299.3716, NULL, 0),
(@PATH, 1, -3271.066, 3026.757, 298.5669, NULL, 0),
(@PATH, 2, -3290.816, 3001.569, 294.3964, NULL, 0),
(@PATH, 3, -3313.774, 2994.47, 287.3248, NULL, 10202),
(@PATH, 4, -3290.847, 3001.51, 294.4677, NULL, 0),
(@PATH, 5, -3271.066, 3026.757, 298.5669, NULL, 0),
(@PATH, 6, -3260.802, 3056.167, 299.3716, NULL, 0),
(@PATH, 7, -3261.559, 3084.41, 297.9975, NULL, 10190);

UPDATE `creature` SET `position_x`= -3260.802, `position_y`= 3056.167, `position_z`= 299.3716, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+7;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+7;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+7, @PATH, 1);

-- Waypoints for CGUID+45
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+45;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+45, @CGUID+45, 0, 0, 515, 0, 0),
(@CGUID+45, @CGUID+48, 4, 270, 515, 0, 0);

SET @PATH := (@CGUID+45) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3130.597, 2865.218, 334.5344, NULL, 0),
(@PATH, 1, -3152.476, 2880.941, 329.6471, NULL, 0),
(@PATH, 2, -3175.695, 2872.866, 328.4665, NULL, 0),
(@PATH, 3, -3191.878, 2850.299, 329.4904, NULL, 0),
(@PATH, 4, -3207.891, 2840.412, 327.2176, NULL, 13238),
(@PATH, 5, -3191.878, 2850.299, 329.4904, NULL, 0),
(@PATH, 6, -3175.695, 2872.866, 328.4665, NULL, 0),
(@PATH, 7, -3152.476, 2880.941, 329.6471, NULL, 0),
(@PATH, 8, -3130.597, 2865.218, 334.5344, NULL, 0),
(@PATH, 9, -3133.165, 2843.919, 336.6699, NULL, 0),
(@PATH, 10, -3130.866, 2819.775, 339.3342, NULL, 0),
(@PATH, 11, -3118.113, 2789.064, 341.9163, NULL, 0),
(@PATH, 12, -3098.924, 2784.544, 342.7412, NULL, 19652),
(@PATH, 13, -3118.113, 2789.064, 341.9163, NULL, 0);

UPDATE `creature` SET `position_x`= -3130.597, `position_y`= 2865.218, `position_z`= 334.5344, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+45;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+45;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+45, @PATH, 1);

-- Waypoints for CGUID+34
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+34;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+34, @CGUID+34, 0, 0, 515, 0, 0),
(@CGUID+34, @CGUID+35, 4, 90, 515, 0, 0);

SET @PATH := (@CGUID+34) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3148.564, 2844.99, 334.8633, NULL, 0),
(@PATH, 1, -3145.479, 2815.103, 337.6548, NULL, 0),
(@PATH, 2, -3150.939, 2791.375, 337.5459, NULL, 12224),
(@PATH, 3, -3145.479, 2815.103, 337.6548, NULL, 0),
(@PATH, 4, -3148.584, 2844.957, 334.7147, NULL, 0),
(@PATH, 5, -3157.285, 2870.507, 331.8231, NULL, 0),
(@PATH, 6, -3174.842, 2908.945, 324.9927, NULL, 0),
(@PATH, 7, -3180.681, 2942.253, 323.1447, NULL, 0),
(@PATH, 8, -3176.771, 2976.226, 321.7616, NULL, 0),
(@PATH, 9, -3168.715, 2997.248, 322.7215, NULL, 11680),
(@PATH, 10, -3176.771, 2976.226, 321.7616, NULL, 0),
(@PATH, 11, -3180.681, 2942.253, 323.1447, NULL, 0),
(@PATH, 12, -3174.842, 2908.945, 324.9927, NULL, 0),
(@PATH, 13, -3157.309, 2870.596, 331.8496, NULL, 0);

UPDATE `creature` SET `position_x`= -3148.564, `position_y`= 2844.99, `position_z`= 334.8633, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+34;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+34;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+34, @PATH, 1);

-- Waypoints for CGUID+53
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+53;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+53, @CGUID+53, 0, 0, 515, 0, 0),
(@CGUID+53, @CGUID+52, 4, 90, 515, 0, 0);

SET @PATH := (@CGUID+53) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`) VALUES
(@PATH, 0, -3053.83, 2954.135, 337.9153, NULL, 0),
(@PATH, 1, -3044.431, 2919.313, 342.0883, NULL, 0),
(@PATH, 2, -3064.269, 2884.431, 342.7607, NULL, 0),
(@PATH, 3, -3082.457, 2862.576, 339.8906, NULL, 0),
(@PATH, 4, -3089.723, 2839.701, 341.3051, NULL, 0),
(@PATH, 5, -3093.773, 2800.255, 343.5883, NULL, 0),
(@PATH, 6, -3110.278, 2774.07, 341.6331, NULL, 0),
(@PATH, 7, -3129.675, 2768.448, 337.7774, NULL, 0),
(@PATH, 8, -3134.945, 2769.635, 337.29, NULL, 11349),
(@PATH, 9, -3129.675, 2768.448, 337.7774, NULL, 0),
(@PATH, 10, -3110.278, 2774.07, 341.6331, NULL, 0),
(@PATH, 11, -3093.773, 2800.255, 343.5883, NULL, 0),
(@PATH, 12, -3089.785, 2839.574, 341.3051, NULL, 0),
(@PATH, 13, -3082.457, 2862.576, 339.8906, NULL, 0),
(@PATH, 14, -3064.269, 2884.431, 342.7607, NULL, 0),
(@PATH, 15, -3044.431, 2919.313, 342.0883, NULL, 0),
(@PATH, 16, -3053.83, 2954.135, 337.9153, NULL, 0),
(@PATH, 17, -3046.835, 2982.354, 334.9452, NULL, 0),
(@PATH, 18, -3028.762, 2995.345, 338.7017, NULL, 11348),
(@PATH, 19, -3046.835, 2982.354, 334.9452, NULL, 0);

UPDATE `creature` SET `position_x`= -3053.83, `position_y`= 2954.135, `position_z`= 337.9153, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+53;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+53;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+53, @PATH, 1);

-- Waypoints for CGUID+71
SET @PATH := (@CGUID+71) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, -3034.547, 2610.082, 350.8969, NULL, 0, 1),
(@PATH, 1, -3038.78, 2602.208, 355.6927, NULL, 0, 1),
(@PATH, 2, -3043.285, 2602.394, 356.6492, NULL, 9196, 1),
(@PATH, 3, -3038.78, 2602.208, 355.6927, NULL, 0, 1),
(@PATH, 4, -3034.547, 2610.082, 350.8969, NULL, 0, 1),
(@PATH, 5, -3052.382, 2616.239, 347.7048, NULL, 6253, 1);

UPDATE `creature` SET `position_x`= -3034.547, `position_y`= 2610.082, `position_z`= 350.8969, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+71;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+71;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+71, @PATH, 1);
