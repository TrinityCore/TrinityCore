SET @CGUID := 1250142;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+68;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2947.333251953125, 3478.25537109375, 342.744842529296875, 1.295982837677001953, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+1, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2874.13916015625, 3472.099609375, 345.269439697265625, 1.36985933780670166, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+2, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2909.53125, 3445.353515625, 343.43890380859375, 5.281287193298339843, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+3, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2758.4228515625, 3514.710205078125, 377.83514404296875, 2.682311773300170898, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+4, 194433, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2761.61279296875, 3444.04345703125, 370.824005126953125, 5.484949588775634765, 120, 6, 0, 25194, 0, 1, 0, 0, 0, 47213), -- Vorquin Foal (Area: The Azure Span - Difficulty: 0)
(@CGUID+5, 194433, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2874.4052734375, 3471.662353515625, 345.069244384765625, 5.000562191009521484, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Vorquin Foal (Area: The Azure Span - Difficulty: 0)
(@CGUID+6, 190726, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2782.260498046875, 3511.23046875, 367.2896728515625, 1.886677265167236328, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Striped Bruffalon (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+7, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2874.4111328125, 3479.976318359375, 345.515289306640625, 4.877073287963867187, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+8, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2874.145751953125, 3567.71875, 370.028106689453125, 3.909217357635498046, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+9, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2872.141357421875, 3469.83056640625, 345.319000244140625, 3.428923606872558593, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+10, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2764.77783203125, 3449.498779296875, 371.808502197265625, 5.238074302673339843, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+11, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2873.6005859375, 3470.786865234375, 345.1793212890625, 0.413975954055786132, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+12, 190726, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2864.314208984375, 3585.606689453125, 373.358428955078125, 2.359543323516845703, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Striped Bruffalon (Area: The Azure Span - Difficulty: 0) (Auras: )
(@CGUID+13, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2939.03857421875, 3441.8095703125, 341.91607666015625, 5.861489772796630859, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+14, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2783.333984375, 3483.3330078125, 366.6385498046875, 0.799552083015441894, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+15, 190765, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2821.944091796875, 3609.2431640625, 384.4437255859375, 4.788255214691162109, 120, 6, 0, 201552, 6882, 1, 0, 0, 0, 47213), -- Mysterious Apparition (Area: The Azure Span - Difficulty: 0)
(@CGUID+16, 190726, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2919.508544921875, 3474.47607421875, 341.9703369140625, 5.075846672058105468, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Striped Bruffalon (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+17, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2806.9072265625, 3619.927001953125, 385.304534912109375, 2.535986185073852539, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+18, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2836.085205078125, 3633.443603515625, 383.863525390625, 3.909217357635498046, 120, 5, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+19, 190726, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2867.843505859375, 3517.2861328125, 357.29107666015625, 2.564153194427490234, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Striped Bruffalon (Area: The Azure Span - Difficulty: 0) (Auras: ) (possible waypoints or random movement)
(@CGUID+20, 194433, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2847.33349609375, 3542.372314453125, 367.72967529296875, 0.623646855354309082, 120, 6, 0, 25194, 0, 1, 0, 0, 0, 47213), -- Vorquin Foal (Area: The Azure Span - Difficulty: 0)
(@CGUID+21, 190743, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2822.4453125, 3435.6025390625, 349.587982177734375, 4.577257156372070312, 120, 6, 0, 50388, 0, 1, 0, 0, 0, 47213), -- Frosty Flowerpine (Area: The Azure Span - Difficulty: 0)
(@CGUID+22, 192267, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2749.333740234375, 3614.46728515625, 389.577972412109375, 1.302905201911926269, 120, 6, 0, 5, 0, 1, 0, 0, 0, 47213), -- Azure Crystalspine (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+23, 190726, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2902.45849609375, 3634.115966796875, 376.452789306640625, 2.072013616561889648, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Striped Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+24, 190726, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2825.018310546875, 3665.151611328125, 386.898162841796875, 1.53562021255493164, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Striped Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+25, 193431, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2810.416015625, 3648.958984375, 381.73822021484375, 0, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 47213), -- Hungry Nibbler (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+26, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2871.689208984375, 3676.802001953125, 391.14703369140625, 3.909217357635498046, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+27, 193431, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2807.7783203125, 3649.026123046875, 381.421539306640625, 3.252562999725341796, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 47213), -- Hungry Nibbler (Area: The Azure Span - Difficulty: 0)
(@CGUID+28, 193431, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2775.126953125, 3651.2841796875, 384.87774658203125, 3.247231721878051757, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 47213), -- Hungry Nibbler (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+29, 193431, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2745.939208984375, 3646.8544921875, 384.357757568359375, 0.192280754446983337, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 47213), -- Hungry Nibbler (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+30, 193431, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2742.704833984375, 3654.128662109375, 384.295135498046875, 3.20104527473449707, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 47213), -- Hungry Nibbler (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+31, 190726, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2903.646484375, 3677.98193359375, 390.98602294921875, 3.12489628791809082, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Striped Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+32, 192069, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2788.2744140625, 3687.7607421875, 393.993560791015625, 2.442078113555908203, 120, 10, 0, 5, 0, 1, 0, 0, 0, 47213), -- Vorquin Runt (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+33, 190726, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2787.392333984375, 3723.94970703125, 396.263824462890625, 2.849738121032714843, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Striped Bruffalon (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+34, 193431, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2887.14794921875, 3613.694580078125, 372.467987060546875, 3.911745071411132812, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 47213), -- Hungry Nibbler (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying) (possible waypoints or random movement)
(@CGUID+35, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2834.674560546875, 3724.3447265625, 394.457611083984375, 4.3902435302734375, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+36, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2833.32470703125, 3725.00830078125, 395.27496337890625, 2.030792474746704101, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+37, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2901.009765625, 3705.501953125, 392.518524169921875, 0.5239945650100708, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+38, 190726, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2958.333984375, 3631.25, 379.830474853515625, 1.723742604255676269, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Striped Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+39, 193431, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2927.09521484375, 3595.44873046875, 360.51251220703125, 0.778689205646514892, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 47213), -- Hungry Nibbler (Area: The Azure Span - Difficulty: 0)
(@CGUID+40, 193431, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2925.937744140625, 3596.387939453125, 360.4761962890625, 0.953494966030120849, 120, 4, 0, 41990, 0, 1, 0, 0, 0, 47213), -- Hungry Nibbler (Area: The Azure Span - Difficulty: 0)
(@CGUID+41, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2890.378662109375, 3713.360107421875, 393.83026123046875, 0.312791883945465087, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+42, 190726, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2846.940185546875, 3728.570556640625, 393.807098388671875, 0.080144703388214111, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Striped Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+43, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2881.796142578125, 3715.07275390625, 394.30706787109375, 5.185280323028564453, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+44, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2875.995361328125, 3723.14306640625, 395.36962890625, 4.606156826019287109, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+45, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2950.73583984375, 3685.409912109375, 390.43011474609375, 5.926783561706542968, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+46, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2962.592529296875, 3669.927490234375, 387.9771728515625, 4.336236953735351562, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+47, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2863.662109375, 3726.084716796875, 394.93109130859375, 5.16730356216430664, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+48, 190726, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2971.064208984375, 3695.18212890625, 391.43023681640625, 5.726480007171630859, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Striped Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+49, 194433, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2859.598876953125, 3707.03076171875, 393.935546875, 5.345347881317138671, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Vorquin Foal (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+50, 194433, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2853.81396484375, 3708.399658203125, 394.117523193359375, 5.380113601684570312, 120, 0, 0, 25194, 0, 0, 0, 0, 0, 47213), -- Vorquin Foal (Area: The Azure Span - Difficulty: 0) (possible waypoints or random movement)
(@CGUID+51, 192069, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2957.281982421875, 3674.840087890625, 388.928497314453125, 4.556207656860351562, 120, 10, 0, 5, 0, 1, 0, 0, 0, 47213), -- Vorquin Runt (Area: The Azure Span - Difficulty: 0)
(@CGUID+52, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2829.611328125, 3753.8046875, 400.9217529296875, 5.643287181854248046, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+53, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2959.697998046875, 3738.119873046875, 396.613189697265625, 3.909217357635498046, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+54, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2955.27099609375, 3740.717529296875, 396.799835205078125, 3.909217357635498046, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+55, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2829.9033203125, 3757.413818359375, 402.24261474609375, 1.128979325294494628, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+56, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2958.84716796875, 3743.478271484375, 397.256134033203125, 3.909217357635498046, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+57, 194433, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2831.80029296875, 3726.130859375, 395.6064453125, 4.195744037628173828, 120, 6, 0, 25194, 0, 1, 0, 0, 0, 47213), -- Vorquin Foal (Area: The Azure Span - Difficulty: 0)
(@CGUID+58, 190726, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2835.313720703125, 3776.99169921875, 407.41363525390625, 3.181610584259033203, 120, 10, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Striped Bruffalon (Area: The Azure Span - Difficulty: 0)
(@CGUID+59, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2815.5361328125, 3778.362548828125, 412.01177978515625, 3.458098173141479492, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+60, 194433, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2830.565185546875, 3756.203369140625, 401.6710205078125, 1.090304970741271972, 120, 6, 0, 25194, 0, 1, 0, 0, 0, 47213), -- Vorquin Foal (Area: The Azure Span - Difficulty: 0)
(@CGUID+61, 190944, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2806.998291015625, 3784.35498046875, 416.334869384765625, 3.909217357635498046, 120, 6, 0, 83980, 0, 1, 0, 0, 0, 47213), -- Vorquin Strider (Area: The Azure Span - Difficulty: 0)
(@CGUID+62, 192069, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2826.101806640625, 3757.423583984375, 402.74664306640625, 0.701740741729736328, 120, 6, 0, 5, 0, 1, 0, 0, 0, 47213), -- Vorquin Runt (Area: The Azure Span - Difficulty: 0)
(@CGUID+63, 190743, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2704.07666015625, 3736.09326171875, 436.682281494140625, 4.1888427734375, 120, 0, 0, 50388, 0, 0, 0, 0, 0, 47213), -- Frosty Flowerpine (Area: The Azure Span - Difficulty: 0)
(@CGUID+64, 192049, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2918.329345703125, 3509.3720703125, 340.120147705078125, 2.548748731613159179, 120, 2, 0, 5, 0, 1, 0, 0, 0, 47213), -- Swoglet (Area: The Azure Span - Difficulty: 0)
(@CGUID+65, 192049, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2916.987548828125, 3489.393798828125, 340.145416259765625, 2.717226028442382812, 120, 2, 0, 5, 0, 1, 0, 0, 0, 47213), -- Swoglet (Area: The Azure Span - Difficulty: 0)
(@CGUID+66, 193422, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2952.11279296875, 3536.951416015625, 339.96588134765625, 1.086687922477722167, 120, 0, 0, 83980, 0, 0, 0, 0, 0, 47213), -- Starving Bullfrog (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying)
(@CGUID+67, 190743, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2651.939453125, 3661.282958984375, 430.062103271484375, 4.009271621704101562, 120, 4, 0, 50388, 0, 1, 0, 0, 0, 47213), -- Frosty Flowerpine (Area: The Azure Span - Difficulty: 0)
(@CGUID+68, 193422, 2444, 13646, 13646, '0', 0, 0, 0, 0, -2654.411376953125, 3648.996337890625, 420.46875, 5.7662200927734375, 120, 4, 0, 83980, 0, 1, 0, 0, 0, 47213); -- Starving Bullfrog (Area: The Azure Span - Difficulty: 0) (Auras: 383173 - Decaying)

-- Creature Template Data
DELETE FROM `creature_template_addon` WHERE `entry` IN (193431 /*193431 (Hungry Nibbler) - Decaying*/, 193422 /*193422 (Starving Bullfrog) - Decaying*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(193431, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'), -- 193431 (Hungry Nibbler) - Decaying
(193422, 0, 0, 0, 1, 0, 0, 0, 0, 0, '383173'); -- 193422 (Starving Bullfrog) - Decaying

-- Creature Template
UPDATE `creature_template` SET `faction`=188, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=193425; -- Cricket
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=2106, `speed_run`=1.285714268684387207, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=193428; -- Feral Hyena
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32832, `unit_flags2`=2048, `VehicleId`=7809 WHERE `entry`=190723; -- Gloomfur Sasquatch
UPDATE `creature_template` SET `faction`=188, `speed_run`=0.857142865657806396, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=192069; -- Vorquin Runt
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=1711, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=193431; -- Hungry Nibbler
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=16, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=190765; -- Mysterious Apparition
UPDATE `creature_template` SET `minlevel`=73, `maxlevel`=73 WHERE `entry`=142668; -- Merchant Maku
UPDATE `creature_template` SET `minlevel`=70, `maxlevel`=70, `npcflag`=2097152 WHERE `entry`=142666; -- Collector Unta
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=31, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=194433; -- Vorquin Foal
UPDATE `creature_template` SET `minlevel`=68, `maxlevel`=68, `faction`=2575, `BaseAttackTime`=2000, `unit_flags`=32768, `unit_flags2`=2048 WHERE `entry`=193422; -- Starving Bullfrog
UPDATE `creature_template` SET `faction`=188, `speed_walk`=0.400000005960464477, `speed_run`=0.285714298486709594, `BaseAttackTime`=2000, `unit_flags`=33280, `unit_flags2`=2048 WHERE `entry`=192049; -- Swoglet

-- Waypoints for CGUID+47
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+47;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+47, @CGUID+47, 0, 0, 515, 0, 0),
(@CGUID+47, @CGUID+50, 3, 320, 515, 0, 0),
(@CGUID+47, @CGUID+49, 3, 40, 515, 0, 0),
(@CGUID+47, @CGUID+44, 5, 320, 515, 0, 0);

SET @PATH := (@CGUID+47) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, -2823.995, 3751.725, 400.1057, NULL, 0, 1),
(@PATH, 1, -2845.976, 3760.843, 400.053, NULL, 0, 1),
(@PATH, 2, -2874.627, 3735.818, 397.1706, NULL, 0, 1),
(@PATH, 3, -2876.212, 3721.113, 395.0222, NULL, 0, 1),
(@PATH, 4, -2856.986, 3708.8, 394.0511, NULL, 0, 1),
(@PATH, 5, -2841.226, 3684.631, 392.3909, NULL, 0, 1),
(@PATH, 6, -2823.495, 3671.72, 388.8033, NULL, 0, 1),
(@PATH, 7, -2801.325, 3675.545, 389.8899, NULL, 0, 1),
(@PATH, 8, -2786.106, 3678.505, 393.182, NULL, 0, 1),
(@PATH, 9, -2814.224, 3725.8, 396.3261, NULL, 0, 1);

UPDATE `creature` SET `position_x`= -2823.995, `position_y`= 3751.725, `position_z`= 400.1057, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+47;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+47;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+47, @PATH, 1);

-- Waypoints for CGUID+1
DELETE FROM `creature_formations` WHERE `leaderGUID` = @CGUID+1;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES
(@CGUID+1, @CGUID+1, 0, 0, 515, 7, 20),
(@CGUID+1, @CGUID+11, 2, 90, 515, 7, 20),
(@CGUID+1, @CGUID+5, 2, 270, 515, 7, 20),
(@CGUID+1, @CGUID+20, 4, 90, 515, 7, 20);

SET @PATH := (@CGUID+1) * 10;
DELETE FROM `waypoint_data` WHERE `id`= @PATH;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`) VALUES
(@PATH, 0, -2863.423, 3518.392, 359.1091, NULL, 0, 1),
(@PATH, 1, -2864.745, 3510.142, 353.7862, NULL, 0, 1),
(@PATH, 2, -2865.961, 3499.74, 351.8744, NULL, 0, 1),
(@PATH, 3, -2870.448, 3491.551, 348.6903, NULL, 0, 1),
(@PATH, 4, -2874.817, 3483.576, 345.9015, NULL, 0, 1),
(@PATH, 5, -2879.241, 3475.501, 344.1271, NULL, 0, 1),
(@PATH, 7, -2880.814, 3472.643, 343.2171, NULL, 6869, 1),
(@PATH, 8, -2877.531, 3478.596, 344.7417, NULL, 0, 1),
(@PATH, 9, -2873.209, 3486.484, 346.6925, NULL, 0, 1),
(@PATH, 10, -2868.721, 3494.675, 349.8636, NULL, 0, 1),
(@PATH, 11, -2865.65, 3504.413, 352.4859, NULL, 0, 1),
(@PATH, 12, -2864.305, 3512.807, 355.4395, NULL, 0, 1),
(@PATH, 13, -2862.989, 3521.021, 360.6571, NULL, 0, 1),
(@PATH, 14, -2862.652, 3527.833, 363.4797, NULL, 0, 1),
(@PATH, 15, -2854.944, 3533.396, 365.6675, NULL, 0, 1),
(@PATH, 16, -2844.298, 3540.235, 366.8548, NULL, 0, 1),
(@PATH, 17, -2844.137, 3549.458, 370.2161, NULL, 0, 1),
(@PATH, 18, -2843.977, 3558.619, 372.9981, NULL, 0, 1),
(@PATH, 19, -2843.92, 3562.048, 373.9577, NULL, 0, 1),
(@PATH, 20, -2843.908, 3562.199, 373.9289, NULL, 5626, 1),
(@PATH, 21, -2844.039, 3555.362, 372.0224, NULL, 0, 1),
(@PATH, 22, -2844.2, 3546.22, 368.9179, NULL, 0, 1),
(@PATH, 23, -2850.248, 3536.781, 366.559, NULL, 0, 1),
(@PATH, 24, -2857.958, 3531.217, 365.1093, NULL, 0, 1),
(@PATH, 25, -2862.091, 3526.701, 363.1119, NULL, 0, 1);

UPDATE `creature` SET `position_x`= -2863.423, `position_y`= 3518.392, `position_z`= 359.1091, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= @CGUID+1;
DELETE FROM `creature_addon` WHERE `guid`= @CGUID+1;
INSERT INTO `creature_addon` (`guid`, `path_id`, `bytes2`) VALUES
(@CGUID+1, @PATH, 1);
